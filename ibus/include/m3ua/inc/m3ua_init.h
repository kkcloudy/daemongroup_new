/****************************************************************************
** Description:
*****************************************************************************
** Copyright(C) 2009 Shabd Communications Pvt. Ltd. http://www.shabdcom.org
*****************************************************************************
** Contact:
** vkgupta@shabdcom.org
*****************************************************************************
** License :
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*****************************************************************************/

#ifndef __M3UA_INIT_H__
#define __M3UA_INIT_H__

#include <m3ua_defines.h>
#include <m3ua_types.h>
#include <m3ua_api.h>
#include <m3ua_config.h>
#include <m3ua_errno.h>
#include <m3uaTimerMgr.h>
#include <m3uaTraceMgr.h>

m3_s32 m3uaInitASP(void);
m3_s32 m3uaInitTimer(void);
m3_s32 m3uaInitSGP(void);
m3_s32 m3uaInitAS(void);
m3_s32 m3uaInitRASP(void);
m3_s32 m3uaInitRSGP(void);
m3_s32 m3uaInitRAS(void);
m3_s32 m3uaInitSG(void);
m3_s32 m3uaInitConn(void);
m3_s32 m3uaInitNwApp(void);
m3_s32 m3uaInitUsr(void);

#endif

