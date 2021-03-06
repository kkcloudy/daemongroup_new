/* 
 * Quagga Work Queue Support.
 *
 * Copyright (C) 2005 Sun Microsystems, Inc.
 *
 * This file is part of GNU Zebra.
 *
 * Quagga is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * Quagga is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Quagga; see the file COPYING.  If not, write to the Free
 * Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.  
 */

#include <lib/zebra.h>
#include "thread.h"
#include "memory.h"
#include "workqueue.h"
#include "linklist.h"
#include "command.h"
#include "log.h"
#include "prefix.h"
#include "table.h"


/* master list of work_queues */
static struct list work_queues;

#define WORK_QUEUE_MIN_GRANULARITY 1

static struct work_queue_item *
work_queue_item_new (struct work_queue *wq)
{
  struct work_queue_item *item;
#if 0
  assert (wq);
#else
	if(!wq)
		return NULL;
#endif
  item = XCALLOC (MTYPE_WORK_QUEUE_ITEM, 
                  sizeof (struct work_queue_item));
  
  return item;
}

static void
work_queue_item_free (struct work_queue_item *item)
{
  XFREE (MTYPE_WORK_QUEUE_ITEM, item);
  return;
}

/* create new work queue */
struct work_queue *
work_queue_new (struct thread_master *m, const char *queue_name)
{
  struct work_queue *new;
  
  new = XCALLOC (MTYPE_WORK_QUEUE, sizeof (struct work_queue));

  if (new == NULL)
    return new;
  
  new->name = XSTRDUP (MTYPE_WORK_QUEUE_NAME, queue_name);
  new->master = m;
  
  if ( (new->items = list_new ()) == NULL)
    {
      XFREE (MTYPE_WORK_QUEUE_NAME, new->name);
      XFREE (MTYPE_WORK_QUEUE, new);
      
      return NULL;
    }
  
  
  if ( (new->pre_items = list_new ()) == NULL)
    {
      list_free(new->items);
      XFREE (MTYPE_WORK_QUEUE_NAME, new->name);
      XFREE (MTYPE_WORK_QUEUE, new);
      
      return NULL;
    }
  
  new->pre_items->del = (void (*)(void *)) work_queue_item_free; 
  listnode_add (&work_queues, new);
  
  new->cycles.granularity = WORK_QUEUE_MIN_GRANULARITY;

  /* Default values, can be overriden by caller */
  new->spec.hold = WORK_QUEUE_DEFAULT_HOLD;
    
  return new;
}

void
work_queue_free (struct work_queue *wq)
{
  /* list_delete frees items via callback */
  list_delete (wq->items);
  list_delete (wq->pre_items);
  listnode_delete (&work_queues, wq);
  
  XFREE (MTYPE_WORK_QUEUE_NAME, wq->name);
  XFREE (MTYPE_WORK_QUEUE, wq);
  return;
}

static inline int
work_queue_schedule (struct work_queue *wq, unsigned int delay)
{
  /* if appropriate, schedule work queue thread */
  if ( (wq->flags == WQ_UNPLUGGED) 
       && (wq->thread == NULL)
       && ((listcount (wq->pre_items) > 0)||(listcount (wq->items) > 0)) )
    {
      wq->thread = thread_add_background (wq->master, work_queue_run, 
                                          wq, delay);
      return 1;
    }
  else
    return 0;
}
  
void
work_queue_add (struct work_queue *wq, void *data)
{
  struct work_queue_item *item;

#if 0  
  assert (wq);
#else
  if(!wq)
  	return;
#endif

  if (!(item = work_queue_item_new (wq)))
    {
      zlog_err ("%s: unable to get new queue item", __func__);
      return;
    }
  item->data = data;
  listnode_add (wq->items, item);
  work_queue_schedule (wq, wq->spec.hold);
  return;
}
  
void
work_queue_pre_add (struct work_queue *wq, void *data)
{
  struct work_queue_item *item;

#if 0  
  assert (wq);
#else
  if(!wq)
  	return;
#endif

  if (!(item = work_queue_item_new (wq)))
    {
      zlog_err ("%s: unable to get new queue item", __func__);
      return;
    }
  item->data = data;
  listnode_add (wq->pre_items, item);
  work_queue_schedule (wq, wq->spec.hold);
  return;
}


static void
work_queue_item_remove (struct work_queue *wq, struct listnode *ln)
{
  struct work_queue_item *item = listgetdata (ln);

#if 0
  assert (item && item->data);
#else
  if(!item || !item->data)
  	return;
#endif
  /* call private data deletion callback if needed */  
  if (wq->spec.del_item_data)
    wq->spec.del_item_data (wq, item->data);

  list_delete_node (wq->items, ln);
  work_queue_item_free (item);
  
  return;
}

static void
work_queue_pre_item_remove (struct work_queue *wq, struct listnode *ln)
{
  struct work_queue_item *item = listgetdata (ln);

#if 0
  assert (item && item->data);
#else
  if(!item || !item->data)
  	return;
#endif
  /* call private data deletion callback if needed */  
  if (wq->spec.del_item_data)
    wq->spec.del_item_data (wq, item->data);

  list_delete_node (wq->pre_items, ln);
  work_queue_item_free (item);
  
  return;
}

static void
work_queue_item_requeue (struct work_queue *wq, struct listnode *ln)
{
  LISTNODE_DETACH (wq->items, ln);
  LISTNODE_ATTACH (wq->items, ln); /* attach to end of list */
}
static void
work_queue_pre_item_requeue (struct work_queue *wq, struct listnode *ln)
{
  LISTNODE_DETACH (wq->pre_items, ln);
  LISTNODE_ATTACH (wq->pre_items, ln); /* attach to end of list */
}

DEFUN(show_work_queues,
      show_work_queues_cmd,
      "show work-queues",
      SHOW_STR
      "Work Queue information\n")
{
  struct listnode *node;
  struct work_queue *wq;
  
  vty_out (vty, 
           "%c %8s %5s %8s %21s%s",
           ' ', "List","(ms) ","Q. Runs","Cycle Counts   ",
           VTY_NEWLINE);
  vty_out (vty,
           "%c %8s %5s %8s %7s %6s %6s %s%s",
           'P',
           "Items",
           "Hold",
           "Total",
           "Best","Gran.","Avg.", 
           "Name", 
           VTY_NEWLINE);
 
  for (ALL_LIST_ELEMENTS_RO ((&work_queues), node, wq))
    {
      vty_out (vty,"%c %8d %5d %8ld %7d %6d %6u %s%s",
               (wq->flags == WQ_PLUGGED ? 'P' : ' '),
               listcount (wq->items),
               wq->spec.hold,
               wq->runs,
               wq->cycles.best, wq->cycles.granularity,
                 (wq->runs) ? 
                   (unsigned int) (wq->cycles.total / wq->runs) : 0,
               wq->name,
               VTY_NEWLINE);
    }
    
  return CMD_SUCCESS;
}

/* 'plug' a queue: Stop it from being scheduled,
 * ie: prevent the queue from draining.
 */
void
work_queue_plug (struct work_queue *wq)
{
  if (wq->thread)
    thread_cancel (wq->thread);
  
  wq->thread = NULL;
  
  wq->flags = WQ_PLUGGED;
}

/* unplug queue, schedule it again, if appropriate
 * Ie: Allow the queue to be drained again
 */
void
work_queue_unplug (struct work_queue *wq)
{
  wq->flags = WQ_UNPLUGGED;

  /* if thread isnt already waiting, add one */
  work_queue_schedule (wq, wq->spec.hold);
}

/* timer thread to process a work queue
 * will reschedule itself if required,
 * otherwise work_queue_item_add 
 */
int
work_queue_run (struct thread *thread)
{
  struct work_queue *wq;
  struct work_queue_item *item;
  wq_item_status ret;
  unsigned int cycles = 0;
  struct listnode *node, *nnode;
  char yielded = 0;

  wq = THREAD_ARG (thread);

  if(!wq || !(wq->pre_items||wq->items))
  {
		zlog(NULL, LOG_CRIT, "line %u, function %s",
			 __LINE__,(__func__ ? __func__ : "?"));
		zlog_backtrace(LOG_CRIT);

		return 1;
  }

  wq->thread = NULL;
  /* calculate cycle granularity:
   * list iteration == 1 cycle
   * granularity == # cycles between checks whether we should yield.
   *
   * granularity should be > 0, and can increase slowly after each run to
   * provide some hysteris, but not past cycles.best or 2*cycles.
   *
   * Best: starts low, can only increase
   *
   * Granularity: starts at WORK_QUEUE_MIN_GRANULARITY, can be decreased 
   *              if we run to end of time slot, can increase otherwise 
   *              by a small factor.
   *
   * We could use just the average and save some work, however we want to be
   * able to adjust quickly to CPU pressure. Average wont shift much if
   * daemon has been running a long time.
   */
   if (wq->cycles.granularity == 0)
     wq->cycles.granularity = WORK_QUEUE_MIN_GRANULARITY;

   if(NULL != wq->pre_items)
   {
	   for (ALL_LIST_ELEMENTS (wq->pre_items, node, nnode, item))
	   {
		   assert (item && item->data);
		   
		   /* dont run items which are past their allowed retries */
		   if (item->ran > wq->spec.max_retries)
			 {
				 //  zlog_debug("rn %p discard this time.",item->data);
				   /* run error handler, if any */
			   if (wq->spec.errorfunc)
				 wq->spec.errorfunc (wq, item->data);
			   work_queue_pre_item_remove (wq, node);
			   continue;				   
			 }
	   
		   /* run and take care of items that want to be retried immediately */
		   do
			 {
			   ret = wq->spec.workfunc (wq, item->data);
			   item->ran++;
			 }
		   while ((ret == WQ_RETRY_NOW) 
				  && (item->ran < wq->spec.max_retries));
	   
		   switch (ret)
			 {
			 case WQ_QUEUE_BLOCKED:
			   {
				 /* decrement item->ran again, cause this isn't an item
				  * specific error, and fall through to WQ_RETRY_LATER
				  */
				 item->ran--;
			   }
			 case WQ_RETRY_LATER:
		   {
			 goto stats;
		   }
			 case WQ_REQUEUE:
		   {
			 work_queue_pre_item_requeue (wq, node);
			 break;
		   }
			 case WQ_RETRY_NOW:
			   /* a RETRY_NOW that gets here has exceeded max_tries, same as ERROR */
			 case WQ_ERROR:
		   {
			 if (wq->spec.errorfunc)
			   wq->spec.errorfunc (wq, item);
		   }
		   /* fall through here is deliberate */
			 case WQ_SUCCESS:
			 default:
		   {
			 work_queue_pre_item_remove (wq, node);
			 break;
		   }
			 }
	   
		   /* completed cycle */
		   cycles++;
	   
		   /* test if we should yield */
		   if ( !(cycles % wq->cycles.granularity) 
			   && thread_should_yield (thread))
			 {
			   yielded = 1;
			   goto stats;
			 }
		 }

   }

  if(NULL != wq->items)
  {
	  for (ALL_LIST_ELEMENTS (wq->items, node, nnode, item))
	  {
		assert (item && item->data);
		
		/* dont run items which are past their allowed retries */
		if (item->ran > wq->spec.max_retries)
		  {
		  //  zlog_debug("rn %p discard this time.",item->data);
			/* run error handler, if any */
		if (wq->spec.errorfunc)
		  wq->spec.errorfunc (wq, item->data);
		work_queue_item_remove (wq, node);
		continue;
		  }
	  
		/* run and take care of items that want to be retried immediately */
		do
		  {
			ret = wq->spec.workfunc (wq, item->data);
			item->ran++;
		  }
		while ((ret == WQ_RETRY_NOW) 
			   && (item->ran < wq->spec.max_retries));
	  
		switch (ret)
		  {
		  case WQ_QUEUE_BLOCKED:
			{
			  /* decrement item->ran again, cause this isn't an item
			   * specific error, and fall through to WQ_RETRY_LATER
			   */
			  item->ran--;
			}
		  case WQ_RETRY_LATER:
		{
		  goto stats;
		}
		  case WQ_REQUEUE:
		{
		  work_queue_item_requeue (wq, node);
		  break;
		}
		  case WQ_RETRY_NOW:
			/* a RETRY_NOW that gets here has exceeded max_tries, same as ERROR */
		  case WQ_ERROR:
		{
		  if (wq->spec.errorfunc)
			wq->spec.errorfunc (wq, item);
		}
		/* fall through here is deliberate */
		  case WQ_SUCCESS:
		  default:
		{
		  work_queue_item_remove (wq, node);
		  break;
		}
		  }
	  
		/* completed cycle */
		cycles++;
	  
		/* test if we should yield */
		if ( !(cycles % wq->cycles.granularity) 
			&& thread_should_yield (thread))
		  {
			yielded = 1;
			goto stats;
		  }
	  }


  }

stats:

#define WQ_HYSTERIS_FACTOR 2

  /* we yielded, check whether granularity should be reduced */
  if (yielded && (cycles < wq->cycles.granularity))
    {
      wq->cycles.granularity = ((cycles > 0) ? cycles 
                                             : WORK_QUEUE_MIN_GRANULARITY);
    }
  
  if (cycles >= (wq->cycles.granularity))
    {
      if (cycles > wq->cycles.best)
        wq->cycles.best = cycles;
      
      /* along with yielded check, provides hysteris for granularity */
      if (cycles > (wq->cycles.granularity * WQ_HYSTERIS_FACTOR * 2))
        wq->cycles.granularity *= WQ_HYSTERIS_FACTOR; /* quick ramp-up */
      else if (cycles > (wq->cycles.granularity * WQ_HYSTERIS_FACTOR))
        wq->cycles.granularity += WQ_HYSTERIS_FACTOR;
    }
#undef WQ_HYSTERIS_FACTOR
  
  wq->runs++;
  wq->cycles.total += cycles;

#if 0
  printf ("%s: cycles %d, new: best %d, worst %d\n",
            __func__, cycles, wq->cycles.best, wq->cycles.granularity);
#endif
  
if((wq->items && listcount (wq->items) > 0 ) || (wq->pre_items && listcount (wq->pre_items)>0))
{
	  work_queue_schedule (wq, 0);
}
else if (wq->spec.completion_func)
	wq->spec.completion_func (wq);
  return 0;
}
int
extern_work_queue_schedule (struct work_queue *wq, unsigned int delay)
{
	return work_queue_schedule (wq, delay);

}
struct work_queue_item *
extern_work_queue_item_new (struct work_queue *wq)
{
	return work_queue_item_new(wq);
}

