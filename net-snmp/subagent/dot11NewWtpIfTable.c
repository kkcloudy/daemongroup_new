/*
 * Note: this file originally auto-generated by mib2c using
 *  : mib2c.iterate.conf,v 5.14.2.2 2005/05/09 08:13:01 dts12 Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "dot11NewWtpIfTable.h"
#include "wcpss/asd/asd.h"
#include "wcpss/wid/WID.h"
#include "dbus/wcpss/dcli_wid_wtp.h"
#include "dbus/wcpss/dcli_wid_wlan.h"
#include "ws_dcli_wlans.h"
#include "ws_sysinfo.h"
#include "ws_init_dbus.h"
#include "autelanWtpGroup.h"
#include "ws_dbus_list_interface.h"


#define NEWWTPIFTABEL "1.3.10"


    /* Typical data structure for a row entry */
struct dot11NewWtpIfTable_entry {
    /* Index values */
	dbus_parameter parameter;
	long globalNewIfwtpID;
	long NewIfwtpID;
	long NewIfIndex;
	char *NewWtpModel;
//	 char *wtpModel;
	
    /* Column values */
	
	
	long NewwtpMTU;
	u_long NewwtpIfSpeed;
	unsigned char NewwtpIfPhyAddr[6];
	char *NewwtpIfIntro;
	char *NewwtpIfName;
	long NewwtpIfType;
	long NewwtpIfAdminStatus;
	long NewwtpIfOperStatus;
	long NewwtpIfLastChange;

    /* Illustrate using a simple linked list */
    int   valid;
    struct dot11WtpIfTable_entry *next;
};

void dot11NewWtpIfTable_load();
void dot11NewWtpIfTable_removeEntry( struct dot11NewWtpIfTable_entry *entry );

/** Initializes the dot11WtpIfTable module */
void
init_dot11NewWtpIfTable(void)
{
  /* here we initialize all the tables we're planning on supporting */
    initialize_table_dot11NewWtpIfTable();
}

/** Initialize the dot11WtpIfTable table by defining its contents and how it's structured */
void
initialize_table_dot11NewWtpIfTable(void)
{
    static oid dot11NewWtpIfTable_oid[128] = {0};
    size_t dot11NewWtpIfTable_oid_len   = 0;
	mad_dev_oid(dot11NewWtpIfTable_oid,NEWWTPIFTABEL,&dot11NewWtpIfTable_oid_len,enterprise_pvivate_oid);
    netsnmp_handler_registration    *reg;
    netsnmp_iterator_info           *iinfo;
    netsnmp_table_registration_info *table_info;

    reg = netsnmp_create_handler_registration(
              "dot11NewWtpIfTable",     dot11NewWtpIfTable_handler,
              dot11NewWtpIfTable_oid, dot11NewWtpIfTable_oid_len,
              HANDLER_CAN_RWRITE
              );

    table_info = SNMP_MALLOC_TYPEDEF( netsnmp_table_registration_info );
    netsnmp_table_helper_add_indexes(table_info,
                           ASN_INTEGER,  /* index: globalNewIfwtpID */
                           ASN_INTEGER,  /* index: wtpIfIndex */
                           0);
    table_info->min_column = NEWWTPIFTABLE_MIN_COLUMN;
    table_info->max_column = NEWWTPIFTABLE_MAX_COLUMN;
    
    iinfo = SNMP_MALLOC_TYPEDEF( netsnmp_iterator_info );
    iinfo->get_first_data_point = dot11NewWtpIfTable_get_first_data_point;
    iinfo->get_next_data_point  = dot11NewWtpIfTable_get_next_data_point;
    iinfo->table_reginfo        = table_info;
    
    netsnmp_register_table_iterator( reg, iinfo );
	netsnmp_inject_handler(reg,netsnmp_get_cache_handler(DOT1DTPFDBTABLE_CACHE_TIMEOUT,dot11NewWtpIfTable_load, dot11NewWtpIfTable_removeEntry,
							dot11NewWtpIfTable_oid, dot11NewWtpIfTable_oid_len));

    /* Initialise the contents of the table here */
}



struct dot11NewWtpIfTable_entry  *dot11NewWtpIfTable_head;

/* create a new row in the (unsorted) table */
struct dot11NewWtpIfTable_entry *
dot11NewWtpIfTable_createEntry(
				dbus_parameter parameter,
				long globalNewIfwtpID,
				long NewIfwtpID,
				long  NewIfIndex,
				char *NewWtpModel,
				long NewwtpMTU,
				u_long NewwtpIfSpeed,
				unsigned char NewwtpIfPhyAddr[6],
				char *NewwtpIfIntro,
				char *NewwtpIfName,
				long NewwtpIfType,
				long NewwtpIfAdminStatus,
				long NewwtpIfOperStatus,
				long NewwtpIfLastChange
			    ) 

{
    struct dot11NewWtpIfTable_entry *entry;

    entry = SNMP_MALLOC_TYPEDEF(struct dot11NewWtpIfTable_entry);
    if (!entry)
        return NULL;
    memcpy(&(entry->parameter), &parameter, sizeof(dbus_parameter));
    entry->globalNewIfwtpID = globalNewIfwtpID;
    entry->NewIfwtpID = NewIfwtpID;	
    entry->NewIfIndex = NewIfIndex;
	entry->NewWtpModel    =strdup(NewWtpModel);
	entry->NewwtpMTU = NewwtpMTU;
  	entry->NewwtpIfSpeed = NewwtpIfSpeed;
	memcpy(entry->NewwtpIfPhyAddr,NewwtpIfPhyAddr,6);
	entry->NewwtpIfIntro = strdup(NewwtpIfIntro);
	entry->NewwtpIfName = strdup(NewwtpIfName);
	entry->NewwtpIfType = NewwtpIfType;
	entry->NewwtpIfAdminStatus = NewwtpIfAdminStatus;
	entry->NewwtpIfOperStatus = NewwtpIfOperStatus;
	entry->NewwtpIfLastChange = NewwtpIfLastChange;
	entry->valid = 1;
       entry->next = dot11NewWtpIfTable_head;
      dot11NewWtpIfTable_head = entry;
      return entry;
}

/* remove a row from the table */
void
dot11NewWtpIfTable_removeEntry( struct dot11NewWtpIfTable_entry *entry ) {
    struct dot11NewWtpIfTable_entry *ptr, *prev;

    if (!entry)
        return;    /* Nothing to remove */

    for ( ptr  = dot11NewWtpIfTable_head, prev = NULL;
          ptr != NULL;
          prev = ptr, ptr = ptr->next ) {
        if ( ptr == entry )
            break;
    }
    if ( !ptr )
        return;    /* Can't find it */

    if ( prev == NULL )
        dot11NewWtpIfTable_head = ptr->next;
    else
        prev->next = ptr->next;
	
	FREE_OBJECT(entry->NewWtpModel);
	FREE_OBJECT(entry->NewwtpIfIntro);
	FREE_OBJECT(entry->NewwtpIfName);
    SNMP_FREE( entry );   /* XXX - release any other internal resources */
}

void dot11NewWtpIfTable_load()
{
	snmp_log(LOG_DEBUG, "enter dot11NewWtpIfTable_load\n");

	struct dot11NewWtpIfTable_entry *temp = NULL;

	while( dot11NewWtpIfTable_head )
	{
		temp=dot11NewWtpIfTable_head->next;
		dot11NewWtpIfTable_removeEntry(dot11NewWtpIfTable_head);
		dot11NewWtpIfTable_head=temp;
	}  

    
    char eth[4][5] = {"eth0","eth1","eth2","eth3"};
	char wtp_mac[20] = { 0 };
	char wtp_model[50] = { 0 };
	
    snmpd_dbus_message *messageHead = NULL, *messageNode = NULL;
    snmp_log(LOG_DEBUG, "enter list_connection_call_dbus_method:show_wtp_list_by_mac_cmd_func\n");
    messageHead = list_connection_call_dbus_method(show_wtp_list_by_mac_cmd_func, SHOW_ALL_WTP_TABLE_METHOD);
    snmp_log(LOG_DEBUG, "exit list_connection_call_dbus_method:show_wtp_list_by_mac_cmd_func,messageHead=%p\n", messageHead);
	
	if(messageHead)
	{
	    for(messageNode = messageHead; NULL != messageNode; messageNode = messageNode->next)
        {
		    DCLI_WTP_API_GROUP_ONE *head = messageNode->message;
		    void *connection = NULL;
			if(SNMPD_DBUS_ERROR == get_slot_dbus_connection(messageNode->parameter.slot_id, &connection, SNMPD_INSTANCE_MASTER_V3))
			    continue;
			    
		    if((head)&&(head->WTP_INFO)&&(head->WTP_INFO->WTP_LIST))
    		{
    		
    		    WID_WTP *q = NULL;
    		    int i = 0, j = 0, ret = 0;
    		
				for(i = 0,q = head->WTP_INFO->WTP_LIST; (i < head->WTP_INFO->list_len)&&(NULL != q); i++,q=q->next)
				{
					memset(wtp_mac,0,20);
					if(q->WTPMAC)
					{
						memcpy(wtp_mac,q->WTPMAC,sizeof(wtp_mac)-1);
					}
					
					memset(wtp_model,0,20);
					if(q->WTPModel)
					{
						strncpy(wtp_model,q->WTPModel,sizeof(wtp_model)-1);
					}
                    unsigned long globalNewIfwtpID = local_to_global_ID(messageNode->parameter,
                                                                        q->WTPID,
                                                                        WIRELESS_MAX_NUM);
                    
					ret = 0;
					DCLI_WTP_API_GROUP_TWO *WTPINFO = NULL;
					ret=show_ap_if_info_func(messageNode->parameter, connection,q->WTPID,&WTPINFO);
					if(ret == 1 && WTPINFO)
					{
						if(WTPINFO->WTP[0])
						{
							for(j = 0; j < WTPINFO->WTP[0]->apifinfo.eth_num; j++)
							{
								unsigned int IfStatus = 0;
								unsigned int wtpIfIndex = j +1;
								unsigned int wtpIfSpeed = WTPINFO->WTP[0]->apifinfo.eth[j].eth_rate;
								time_t online_time = 0, now = 0;
								
								if(1 == WTPINFO->WTP[0]->apifinfo.eth[j].state) 					
									IfStatus=1;
							
								time(&now);
								online_time = 100 * (now - (WTPINFO->WTP[0]->apifinfo.eth[j].state_time));	
								dot11NewWtpIfTable_createEntry(messageNode->parameter,
																globalNewIfwtpID,
																q->WTPID,
																wtpIfIndex,
																wtp_model,
																0,
																wtpIfSpeed,
																wtp_mac,
																"",
																"",
																6,
																IfStatus,
																IfStatus,
																online_time);
									  
							}	
						}
					    free_show_ap_if_info(WTPINFO);
				    } 			  
					FREE_OBJECT(q->WTPMAC);
                }
            }
        }
        free_dbus_message_list(&messageHead, Free_wtp_list_by_mac_head);
    }

    snmp_log(LOG_DEBUG, "exit dot11NewWtpIfTable_load\n");
}



/* Example iterator hook routines - using 'get_next' to do most of the work */
netsnmp_variable_list *
dot11NewWtpIfTable_get_first_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{

	if(dot11NewWtpIfTable_head==NULL)
		return NULL;
	*my_loop_context = dot11NewWtpIfTable_head;
	*my_data_context = dot11NewWtpIfTable_head;
	return dot11NewWtpIfTable_get_next_data_point(my_loop_context, my_data_context,
	put_index_data,  mydata );
}

netsnmp_variable_list *
dot11NewWtpIfTable_get_next_data_point(void **my_loop_context,
                          void **my_data_context,
                          netsnmp_variable_list *put_index_data,
                          netsnmp_iterator_info *mydata)
{
    struct dot11NewWtpIfTable_entry *entry = (struct dot11NewWtpIfTable_entry *)*my_loop_context;
    netsnmp_variable_list *idx = put_index_data;

    if ( entry ) {
        snmp_set_var_value( idx,(u_char *)&entry->globalNewIfwtpID, sizeof(entry->globalNewIfwtpID) );
        idx = idx->next_variable;

	snmp_set_var_value( idx,(u_char*)&entry->NewIfIndex, sizeof(long) );
        idx = idx->next_variable;

	*my_data_context = (void *)entry;
        *my_loop_context = (void *)entry->next;
    } else {
        return NULL;
    }
	return put_index_data;
}


/** handles requests for the dot11WtpIfTable table */
int
dot11NewWtpIfTable_handler(
    netsnmp_mib_handler               *handler,
    netsnmp_handler_registration      *reginfo,
    netsnmp_agent_request_info        *reqinfo,
    netsnmp_request_info              *requests) {

    netsnmp_request_info       *request;
    netsnmp_table_request_info *table_info;
    struct dot11NewWtpIfTable_entry          *table_entry;

    switch (reqinfo->mode) {
        /*
         * Read-support (also covers GetNext requests)
         */
    case MODE_GET:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11NewWtpIfTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);


		if( !table_entry ){
        		netsnmp_set_request_error(reqinfo,request,SNMP_NOSUCHINSTANCE);
				continue;
	    	}      
		
            switch (table_info->colnum) {

		   case COLUMN_NEWIFWTPID:
          {
		  snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                                          (u_char*)&table_entry->globalNewIfwtpID,
                                          sizeof(long));
	      }

		        
			break;
			
	      case COLUMN_NEWWTPIFINDEX:
          {
		  snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                                          (u_char*)&table_entry->NewIfIndex,
                                          sizeof(long));
	      }

		        
			break;
            case COLUMN_NEWWTPMTU:
			{
                void *connection = NULL;
                if(SNMPD_DBUS_ERROR == get_slot_dbus_connection(table_entry->parameter.slot_id, &connection, SNMPD_INSTANCE_MASTER_V3))
                    break;
                        
				int ret = 0;		
				int wtpMTU = 0;
				DCLI_AC_API_GROUP_FOUR *codeinfo = NULL;
				wid_code_infomation *model_head = NULL;
				
				ret=show_ap_model_code_func(table_entry->parameter, connection, table_entry->NewWtpModel,&codeinfo);
				if(ret == 1)
				{
					if(codeinfo != NULL)
					model_head = codeinfo->code_info;
					if(model_head != NULL)
					{
						wtpMTU = model_head->ap_if_mtu;
					}
				}
				else if (SNMPD_CONNECTION_ERROR == ret) {
    			    close_slot_dbus_connection(table_entry->parameter.slot_id);
    			}
    			
    			snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                             		 (u_char*)&wtpMTU,
                             		 sizeof(long));
			   if(ret == 1)
				{
					Free_ap_model_code(codeinfo);
				}
				            	
           	}
                break;
            case COLUMN_NEWWTPIFSPEED:
			{			
				snmp_set_var_typed_value( request->requestvb, ASN_GAUGE,
							  (u_char*)&table_entry->NewwtpIfSpeed,
							  sizeof(table_entry->NewwtpIfSpeed)); 	
	
            }                
                break;
            case COLUMN_NEWWTPIFPHYADDR:
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          (u_char*)table_entry->NewwtpIfPhyAddr,
                                          6);
                break;
            case COLUMN_NEWWTPIFINTRO:
			{   
				
				char logo[50] = { 0 };
				memset(logo,0,50);
				get_logo(logo);	
				delete_enter(logo);
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          (u_char*)logo,
                                          strlen(logo));
            }
                break;
			 case COLUMN_NEWWTPIFNAME:
			{   
				char eth[4][5] = {"eth0","eth1","eth2","eth3"};
                snmp_set_var_typed_value( request->requestvb, ASN_OCTET_STR,
                                          (u_char*)eth[table_entry->NewIfIndex-1],
                                          strlen(eth[table_entry->NewIfIndex-1]));  
           	}

                break;
		 case COLUMN_NEWWTPIFTYPE:
				   
                snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                                          (u_char*)&table_entry->NewwtpIfType,
                                          sizeof(table_entry->NewwtpIfType));
                break;
		 case COLUMN_NEWWTPIFADMINSTATUS:
		 {      
                snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                                          (u_char*)&table_entry->NewwtpIfAdminStatus,
                                          sizeof(table_entry->NewwtpIfAdminStatus));
		}
                break;
		 case COLUMN_NEWWTPIFOPERSTATUS:
		 {      

                snmp_set_var_typed_value( request->requestvb, ASN_INTEGER,
                                          (u_char*)&table_entry->NewwtpIfOperStatus,
                                          sizeof(table_entry->NewwtpIfOperStatus));
		}
                break;
		 case COLUMN_NEWWTPIFLASTCHANGE:
		 {      
                snmp_set_var_typed_value( request->requestvb, ASN_TIMETICKS,
                                          (u_char*)&table_entry->NewwtpIfLastChange,
                                          sizeof(table_entry->NewwtpIfLastChange));
		 }
                break;				
            }
        }
        break;

        /*
         * Write-support
         */
    case MODE_SET_RESERVE1:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11WtpIfTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {

			case COLUMN_NEWIFWTPID:
		    if ( request->requestvb->type != ASN_INTEGER ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
			 break;

	        case COLUMN_NEWWTPIFINDEX:
		    if ( request->requestvb->type != ASN_INTEGER ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
			 break;

            case COLUMN_NEWWTPMTU:
                if ( request->requestvb->type != ASN_INTEGER ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
                /* Also may need to check size/value */
                break;
            case COLUMN_NEWWTPIFSPEED:
                if ( request->requestvb->type != ASN_GAUGE ) {
                    netsnmp_set_request_error( reqinfo, request,
                                               SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
                /* Also may need to check size/value */
                break;
			case COLUMN_NEWWTPIFADMINSTATUS:
                if ( request->requestvb->type != ASN_INTEGER ) {
                    netsnmp_set_request_error( reqinfo, request,
												SNMP_ERR_WRONGTYPE );
                    return SNMP_ERR_NOERROR;
                }
                /* Also may need to check size/value */
                break;
            default:
                netsnmp_set_request_error( reqinfo, request,
                                           SNMP_ERR_NOTWRITABLE );
                return SNMP_ERR_NOERROR;
            }
        }
        break;

    case MODE_SET_RESERVE2:
        break;

    case MODE_SET_FREE:
        break;

    case MODE_SET_ACTION:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11WtpIfTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);

		if( !table_entry ){
        		netsnmp_set_request_error(reqinfo,request,SNMP_NOSUCHINSTANCE);
				continue;
	    	}   
		
            switch (table_info->colnum) {
		  case COLUMN_NEWIFWTPID:
			  break;

          case COLUMN_NEWWTPIFINDEX:
		   //   table_entry->old_wtpIfIndex = table_entry->wtpIfIndex;
			  break;
		
            case COLUMN_NEWWTPMTU:
                /* Need to save old 'table_entry->wtpMTU' value.
                   May need to use 'memcpy' */
            //    table_entry->old_wtpMTU = table_entry->wtpMTU;
              //  table_entry->wtpMTU     = request->requestvb->val.YYY;
                break;
            case COLUMN_NEWWTPIFSPEED:
			{
                /* Need to save old 'table_entry->wtpIfSpeed' value.
                   May need to use 'memcpy' */
               // table_entry->old_wtpIfSpeed = table_entry->wtpIfSpeed;
                void *connection = NULL;
                if(SNMPD_DBUS_ERROR == get_instance_dbus_connection(table_entry->parameter, &connection, SNMPD_INSTANCE_MASTER_V3))
                {
					netsnmp_set_request_error(reqinfo,request,SNMP_ERR_WRONGTYPE);
                    break;
                }
                
                int ret = 0;
				char if_index[10] = { 0 };
				memset(if_index,0,10);
				char if_rate[10] = { 0 };
				memset(if_rate,0,10);

				if((*request->requestvb->val.integer == 10)||(*request->requestvb->val.integer == 100)||(*request->requestvb->val.integer == 1000))
				{
					memset(if_index,0,10);
					snprintf(if_index,sizeof(if_index)-1,"%d",table_entry->NewIfIndex-1);
					
					memset(if_rate,0,10);
					snprintf(if_rate,sizeof(if_rate)-1,"%d",*request->requestvb->val.integer);
					
					ret = set_ap_if_rate_cmd(table_entry->parameter, connection,table_entry->NewIfwtpID,if_index,if_rate);
					if(ret == 1)
					{
						table_entry->NewwtpIfSpeed = *request->requestvb->val.integer;
					}	
					else
					{
            	        if(SNMPD_CONNECTION_ERROR == ret) {
                            close_slot_dbus_connection(table_entry->parameter.slot_id);
            	        }
						netsnmp_set_request_error(reqinfo,request,SNMP_ERR_WRONGTYPE);
					}
				}
				else
				{						
					netsnmp_set_request_error(reqinfo,request,SNMP_ERR_WRONGTYPE);
				}				
            }
                break;
			 case COLUMN_NEWWTPIFNAME:
			 	break;
			case COLUMN_NEWWTPIFADMINSTATUS:
				{
                    void *connection = NULL;
                    if(SNMPD_DBUS_ERROR == get_instance_dbus_connection(table_entry->parameter, &connection, SNMPD_INSTANCE_MASTER_V3))
                    {
    					netsnmp_set_request_error(reqinfo,request,SNMP_ERR_WRONGTYPE);
                        break;
                    }
                    
					int ret = 0;
					char id[5] = { 0 };
					char state[10] = { 0 };

					memset(state,0,10);
					if(*request->requestvb->val.integer==1)
						strncpy(state,"uplink",sizeof(state)-1);
					else
						strncpy(state,"downlink",sizeof(state)-1);

					memset(id,0,5);
					snprintf(id,sizeof(id)-1,"%d",table_entry->NewIfIndex-1);
					
					ret=set_ap_if_updown_func(table_entry->parameter, connection, table_entry->NewIfwtpID,"eth",id,state);
					if(ret==1)
					{
						table_entry->NewwtpIfAdminStatus = *request->requestvb->val.integer;
					}
					else
					{	
					    if(SNMPD_CONNECTION_ERROR == ret) {
                            close_slot_dbus_connection(table_entry->parameter.slot_id);
            	        }					
						netsnmp_set_request_error(reqinfo,request,SNMP_ERR_WRONGTYPE);
					}					
				}
				break;
            }
        }
        break;

    case MODE_SET_UNDO:
        for (request=requests; request; request=request->next) {
            table_entry = (struct dot11WtpIfTable_entry *)
                              netsnmp_extract_iterator_context(request);
            table_info  =     netsnmp_extract_table_info(      request);
    
            switch (table_info->colnum) {

			case COLUMN_NEWIFWTPID:
		// table_entry->wtpIfIndex  = table_entry->old_wtpIfIndex;
			
	        case COLUMN_NEWWTPIFINDEX:
		// table_entry->wtpIfIndex  = table_entry->old_wtpIfIndex;
                break;	
            case COLUMN_NEWWTPMTU:
                /* Need to restore old 'table_entry->wtpMTU' value.
                   May need to use 'memcpy' */
           //     table_entry->wtpMTU = table_entry->old_wtpMTU;
                break;
            case COLUMN_NEWWTPIFSPEED:
                /* Need to restore old 'table_entry->wtpIfSpeed' value.
                   May need to use 'memcpy' */
           //     table_entry->wtpIfSpeed = table_entry->old_wtpIfSpeed;
                break;
			case COLUMN_NEWWTPIFADMINSTATUS:
				/* Need to restore old 'table_entry->wtpIfAdminStatus' value.May need to use 'memcpy' */
			//	table_entry->wtpIfAdminStatus = table_entry->old_wtpIfAdminStatus;
        		break;
            }
        }
        break;

    case MODE_SET_COMMIT:
        break;
    }
    return SNMP_ERR_NOERROR;
}
