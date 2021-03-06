/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18 $ of : mfd-data-set.m2c,v $
 *
 * $Id:$
 *
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "wcpss/asd/asd.h"
#include "wcpss/wid/WID.h"
#include "dbus/wcpss/dcli_wid_wtp.h"
#include "dbus/wcpss/dcli_wid_wlan.h"
#include "ws_dcli_wlans.h"
#include "ws_sysinfo.h"
#include "ws_init_dbus.h"
#include "autelanWtpGroup.h"
/* include our parent header */
#include "dot11WtpIfTable.h"


/** @defgroup data_set data_set: Routines to set data
 *
 * These routines are used to set the value for individual objects. The
 * row context is passed, along with the new value.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11WtpIfTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11WtpIfTable is subid 1 of wtpInterface.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.1.3.1, length: 12
*/
    /*
     * NOTE: if you update this chart, please update the versions in
     *       local/mib2c-conf.d/parent-set.m2i
     *       agent/mibgroup/helpers/baby_steps.c
     * while you're at it.
     */
    /*
     ***********************************************************************
     * Baby Steps Flow Chart (2004.06.05)                                  *
     *                                                                     *
     * +--------------+    +================+    U = unconditional path    *
     * |optional state|    ||required state||    S = path for success      *
     * +--------------+    +================+    E = path for error        *
     ***********************************************************************
     *
     *                        +--------------+
     *                        |     pre      |
     *                        |   request    |
     *                        +--------------+
     *                               | U
     *                        +==============+
     *       +----------------||  object    ||
     *       |              E ||  lookup    ||
     *       |                +==============+
     *       |                       | S
     *       |                +==============+
     *       |              E ||   check    ||
     *       |<---------------||   values   ||
     *       |                +==============+
     *       |                       | S
     *       |                +==============+
     *       |       +<-------||   undo     ||
     *       |       |      E ||   setup    ||
     *       |       |        +==============+
     *       |       |               | S
     *       |       |        +==============+
     *       |       |        ||    set     ||-------------------------->+
     *       |       |        ||   value    || E                         |
     *       |       |        +==============+                           |
     *       |       |               | S                                 |
     *       |       |        +--------------+                           |
     *       |       |        |    check     |-------------------------->|
     *       |       |        |  consistency | E                         |
     *       |       |        +--------------+                           |
     *       |       |               | S                                 |
     *       |       |        +==============+         +==============+  |
     *       |       |        ||   commit   ||-------->||     undo   ||  |
     *       |       |        ||            || E       ||    commit  ||  |
     *       |       |        +==============+         +==============+  |
     *       |       |               | S                     U |<--------+
     *       |       |        +--------------+         +==============+
     *       |       |        | irreversible |         ||    undo    ||
     *       |       |        |    commit    |         ||     set    ||
     *       |       |        +--------------+         +==============+
     *       |       |               | U                     U |
     *       |       +-------------->|<------------------------+
     *       |                +==============+
     *       |                ||   undo     ||
     *       |                ||  cleanup   ||
     *       |                +==============+
     *       +---------------------->| U
     *                        +--------------+
     *                        |    post      |
     *                        |   request    |
     *                        +--------------+
     *
     */

/**
 * Setup up context with information needed to undo a set request.
 *
 * This function will be called before the individual node undo setup
 * functions are called. If you need to do any undo setup that is not
 * related to a specific column, you can do it here.
 *
 * Note that an individual node's undo_setup function will only be called
 * if that node is being set to a new value.
 *
 * If there is any setup specific to a particular column (e.g. allocating
 * memory for a string), you should do that setup in the node's undo_setup
 * function, so it won't be done unless it is necessary.
 *
 * @param rowreq_ctx
 *        Pointer to the table context (dot11WtpIfTable_rowreq_ctx)
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error. set will fail.
 */
int
dot11WtpIfTable_undo_setup( dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{
    int rc = MFD_SUCCESS;

    DEBUGMSGTL(("verbose:dot11WtpIfTable:dot11WtpIfTable_undo_setup","called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert( NULL != rowreq_ctx );

    /*
     * TODO:451:M: |-> Setup dot11WtpIfTable undo.
     * set up dot11WtpIfTable undo information, in preparation for a set.
     */

    return rc;
} /* dot11WtpIfTable_undo_setup */

/**
 * Cleanup up context undo information.
 *
 * This function will be called after set/commit processing. If you
 * allocated any resources in undo_setup, this is the place to release
 * those resources.
 *
 * This function is called regardless of the success or failure of the set
 * request. If you need to perform different steps for cleanup depending
 * on success or failure, you can add a flag to the rowreq_ctx.
 *
 * @param rowreq_ctx
 *        Pointer to the table context (dot11WtpIfTable_rowreq_ctx)
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error
 */
int
dot11WtpIfTable_undo_cleanup( dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{
    int rc = MFD_SUCCESS;

    DEBUGMSGTL(("verbose:dot11WtpIfTable:dot11WtpIfTable_undo_cleanup","called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert( NULL != rowreq_ctx );

    /*
     * TODO:452:M: |-> Cleanup dot11WtpIfTable undo.
     */

    return rc;
} /* dot11WtpIfTable_undo_cleanup */

/**
 * commit new values.
 *
 * At this point, you should have done everything you can to ensure that
 * this commit will not fail.
 *
 * Should you need different behavior depending on which columns were
 * set, rowreq_ctx->column_set_flags will indicate which writeable columns were
 * set. The definitions for the FLAG_* bits can be found in
 * dot11WtpIfTable_oids.h.
 * A new row will have the MFD_ROW_CREATED bit set in rowreq_flags.
 *
 * @param dot11WtpIfTable_rowreq_ctx
 *        Pointer to the users context.
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error
 */
int
dot11WtpIfTable_commit( dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{
    int rc = MFD_SUCCESS;
    int             save_flags;

    DEBUGMSGTL(("verbose:dot11WtpIfTable:dot11WtpIfTable_commit","called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert( NULL != rowreq_ctx );

    /*
     * save flags, then clear until we actually do something
     */
    save_flags = rowreq_ctx->column_set_flags;
    rowreq_ctx->column_set_flags = 0;

    /*
     * commit dot11WtpIfTable data
     * 1) check the column's flag in save_flags to see if it was set.
     * 2) clear the flag when you handle that column
     * 3) set the column's flag in column_set_flags if it needs undo
     *    processing in case of a failure.
     */
    if (save_flags & FLAG_WTPIFSPEED) {
       save_flags &= ~FLAG_WTPIFSPEED; /* clear wtpIfSpeed */
       /*
        * TODO:482:o: |-> commit column wtpIfSpeed.
        */
       //rc = -1;
       if(-1 == rc) {
           snmp_log(LOG_ERR,"dot11WtpIfTable column wtpIfSpeed commit failed\n");
       }
       else {
            /*
             * set flag, in case we need to undo wtpIfSpeed
             */
            rowreq_ctx->column_set_flags |= FLAG_WTPIFSPEED;
       }
    }

    if (save_flags & FLAG_WTPIFADMINSTATUS) {
       save_flags &= ~FLAG_WTPIFADMINSTATUS; /* clear wtpIfAdminStatus */
       /*
        * TODO:482:o: |-> commit column wtpIfAdminStatus.
        */
       //rc = -1;
       if(-1 == rc) {
           snmp_log(LOG_ERR,"dot11WtpIfTable column wtpIfAdminStatus commit failed\n");
       }
       else {
            /*
             * set flag, in case we need to undo wtpIfAdminStatus
             */
            rowreq_ctx->column_set_flags |= FLAG_WTPIFADMINSTATUS;
       }
    }

    if (save_flags) {
       snmp_log(LOG_ERR, "unhandled columns (0x%x) in commit\n", save_flags);
       return MFD_ERROR;
    }

    return rc;
} /* dot11WtpIfTable_commit */

/**
 * undo commit new values.
 *
 * Should you need different behavior depending on which columns were
 * set, rowreq_ctx->column_set_flags will indicate which writeable columns were
 * set. The definitions for the FLAG_* bits can be found in
 * dot11WtpIfTable_oids.h.
 * A new row will have the MFD_ROW_CREATED bit set in rowreq_flags.
 *
 * @param dot11WtpIfTable_rowreq_ctx
 *        Pointer to the users context.
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error
 */
int
dot11WtpIfTable_undo_commit( dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{
    int rc = MFD_SUCCESS;

    DEBUGMSGTL(("verbose:dot11WtpIfTable:dot11WtpIfTable_undo_commit","called\n"));

    /** we should have a non-NULL pointer */
    netsnmp_assert( NULL != rowreq_ctx );

    /*
     * TODO:485:M: |-> Undo dot11WtpIfTable commit.
     * check the column's flag in rowreq_ctx->column_set_flags to see
     * if it was set during commit, then undo it.
     *
     * eg: if (rowreq_ctx->column_set_flags & FLAG_) {}
     */

    return rc;
} /* dot11WtpIfTable_undo_commit */

/*
 * TODO:420:r: Implement dot11WtpIfTable index validation.
 */
/*---------------------------------------------------------------------
 * DOT11-WTP-MIB::dot11WtpInfoEntry.wtpMacAddr
 * wtpMacAddr is subid 1 of dot11WtpInfoEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.31656.6.1.1.1.1.1.1
 * Description:
AP mac.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is Dot11BaseWtpIdTC (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max )
 */
/*
 * TODO:440:M: Implement dot11WtpIfTable node value checks.
 * TODO:450:M: Implement dot11WtpIfTable undo functions.
 * TODO:460:M: Implement dot11WtpIfTable set functions.
 * TODO:480:M: Implement dot11WtpIfTable commit functions.
 */
/*---------------------------------------------------------------------
 * DOT11-WTP-MIB::dot11WtpIfEntry.wtpIfSpeed
 * wtpIfSpeed is subid 3 of dot11WtpIfEntry.
 * Its status is Current, and its access level is ReadWrite.
 * OID: .1.3.6.1.4.1.31656.6.1.1.3.1.1.3
 * Description:
AP physical interface speed,include 10M and 100M. The input must be 10 or 100,otherwise you can't set it successfully.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 *
 * Its syntax is GAUGE (based on perltype GAUGE)
 * The net-snmp type is ASN_GAUGE. The C type decl is u_long (u_long)
 */
/**
 * Check that the proposed new value is potentially valid.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param wtpIfSpeed_val
 *        A u_long containing the new value.
 *
 * @retval MFD_SUCCESS        : incoming value is legal
 * @retval MFD_NOT_VALID_NOW  : incoming value is not valid now
 * @retval MFD_NOT_VALID_EVER : incoming value is never valid
 *
 * This is the place to check for requirements that are not
 * expressed in the mib syntax (for example, a requirement that
 * is detailed in the description for an object).
 *
 * You should check that the requested change between the undo value and the
 * new value is legal (ie, the transistion from one value to another
 * is legal).
 *      
 *@note
 * This check is only to determine if the new value
 * is \b potentially valid. This is the first check of many, and
 * is one of the simplest ones.
 * 
 *@note
 * this is not the place to do any checks for values
 * which depend on some other value in the mib. Those
 * types of checks should be done in the
 * dot11WtpIfTable_check_dependencies() function.
 *
 * The following checks have already been done for you:
 *    The syntax is ASN_GAUGE
 *
 * If there a no other checks you need to do, simply return MFD_SUCCESS.
 *
 */
int
wtpIfSpeed_check_value( dot11WtpIfTable_rowreq_ctx *rowreq_ctx, u_long wtpIfSpeed_val)
{
    DEBUGMSGTL(("verbose:dot11WtpIfTable:wtpIfSpeed_check_value","called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:441:o: |-> Check for valid wtpIfSpeed value.
     */

    return MFD_SUCCESS; /* wtpIfSpeed value not illegal */
} /* wtpIfSpeed_check_value */

/**
 * Save old value information
 *
 * @param rowreq_ctx
 *        Pointer to the table context (dot11WtpIfTable_rowreq_ctx)
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error. set will fail.
 *
 * This function will be called after the table level undo setup function
 * dot11WtpIfTable_undo_setup has been called.
 *
 *@note
 * this function will only be called if a new value is set for this column.
 *
 * If there is any setup specific to a particular column (e.g. allocating
 * memory for a string), you should do that setup in this function, so it
 * won't be done unless it is necessary.
 */
int
wtpIfSpeed_undo_setup( dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:dot11WtpIfTable:wtpIfSpeed_undo_setup","called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:455:o: |-> Setup wtpIfSpeed undo.
     */
    /*
     * copy wtpIfSpeed data
     * set rowreq_ctx->undo->wtpIfSpeed from rowreq_ctx->data.wtpIfSpeed
     */
    rowreq_ctx->undo->wtpIfSpeed = rowreq_ctx->data.wtpIfSpeed;


    return MFD_SUCCESS;
} /* wtpIfSpeed_undo_setup */

/**
 * Set the new value.
 *
 * @param rowreq_ctx
 *        Pointer to the users context. You should know how to
 *        manipulate the value from this object.
 * @param wtpIfSpeed_val
 *        A u_long containing the new value.
 */
int
wtpIfSpeed_set( dot11WtpIfTable_rowreq_ctx *rowreq_ctx, u_long wtpIfSpeed_val )
{

    DEBUGMSGTL(("verbose:dot11WtpIfTable:wtpIfSpeed_set","called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:245:o: |-> Implement wtpIfSpeed reverse mapping.
 * If the values for your data type don't exactly match the
 * possible values defined by the mib, you should map them here.
 */
    /*
     * TODO:461:M: |-> Set wtpIfSpeed value.
     * set wtpIfSpeed value in rowreq_ctx->data
     */
    void *connection = NULL;
    if(SNMPD_DBUS_ERROR == get_instance_dbus_connection(rowreq_ctx->data.parameter, &connection, SNMPD_INSTANCE_MASTER_V3))
        return MFD_ERROR;
        
	int ret = 0;
	char if_index[10] = { 0 };
	memset(if_index,0,10);
	char if_rate[10] = { 0 };
	memset(if_rate,0,10);
	int rc = MFD_ERROR;

	if((wtpIfSpeed_val == 10)||(wtpIfSpeed_val == 100)||(wtpIfSpeed_val == 1000))
	{
		memset(if_index,0,10);
		snprintf(if_index,sizeof(if_index)-1,"%d",(rowreq_ctx->data.wtpIfIndex - 1));

		memset(if_rate,0,10);
		snprintf(if_rate,sizeof(if_rate)-1,"%d",wtpIfSpeed_val);

		ret = set_ap_if_rate_cmd(rowreq_ctx->data.parameter, connection,rowreq_ctx->data.wtpCurrID,if_index,if_rate);
		if(ret == 1)
		{
    		rowreq_ctx->data.wtpIfSpeed = wtpIfSpeed_val;
			rc = MFD_SUCCESS;
		}	
		else
		{	
		    if(SNMPD_CONNECTION_ERROR == ret) {
                close_slot_dbus_connection(rowreq_ctx->data.parameter.slot_id);
	        }
			rc = MFD_ERROR;
		}
	}
	else
	{						
		rc = MFD_ERROR;
	}				

    return rc;
} /* wtpIfSpeed_set */

/**
 * undo the previous set.
 *
 * @param rowreq_ctx
 *        Pointer to the users context.
 */
int
wtpIfSpeed_undo( dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{

    DEBUGMSGTL(("verbose:dot11WtpIfTable:wtpIfSpeed_undo","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:456:o: |-> Clean up wtpIfSpeed undo.
     */
    /*
     * copy wtpIfSpeed data
     * set rowreq_ctx->data.wtpIfSpeed from rowreq_ctx->undo->wtpIfSpeed
     */
    rowreq_ctx->data.wtpIfSpeed = rowreq_ctx->undo->wtpIfSpeed;

    
    return MFD_SUCCESS;
} /* wtpIfSpeed_undo */

/*---------------------------------------------------------------------
 * DOT11-WTP-MIB::dot11WtpIfEntry.wtpIfAdminStatus
 * wtpIfAdminStatus is subid 8 of dot11WtpIfEntry.
 * Its status is Current, and its access level is ReadWrite.
 * OID: .1.3.6.1.4.1.31656.6.1.1.3.1.1.8
 * Description:
AP physical  interface type status(up or down).
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 * Enum range: 1/8. Values:  down(0), up(1)
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * Check that the proposed new value is potentially valid.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param wtpIfAdminStatus_val
 *        A long containing the new value.
 *
 * @retval MFD_SUCCESS        : incoming value is legal
 * @retval MFD_NOT_VALID_NOW  : incoming value is not valid now
 * @retval MFD_NOT_VALID_EVER : incoming value is never valid
 *
 * This is the place to check for requirements that are not
 * expressed in the mib syntax (for example, a requirement that
 * is detailed in the description for an object).
 *
 * You should check that the requested change between the undo value and the
 * new value is legal (ie, the transistion from one value to another
 * is legal).
 *      
 *@note
 * This check is only to determine if the new value
 * is \b potentially valid. This is the first check of many, and
 * is one of the simplest ones.
 * 
 *@note
 * this is not the place to do any checks for values
 * which depend on some other value in the mib. Those
 * types of checks should be done in the
 * dot11WtpIfTable_check_dependencies() function.
 *
 * The following checks have already been done for you:
 *    The syntax is ASN_INTEGER
 *    The value is one of  down(0), up(1)
 *
 * If there a no other checks you need to do, simply return MFD_SUCCESS.
 *
 */
int
wtpIfAdminStatus_check_value( dot11WtpIfTable_rowreq_ctx *rowreq_ctx, u_long wtpIfAdminStatus_val)
{
    DEBUGMSGTL(("verbose:dot11WtpIfTable:wtpIfAdminStatus_check_value","called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:441:o: |-> Check for valid wtpIfAdminStatus value.
     */

    return MFD_SUCCESS; /* wtpIfAdminStatus value not illegal */
} /* wtpIfAdminStatus_check_value */

/**
 * Save old value information
 *
 * @param rowreq_ctx
 *        Pointer to the table context (dot11WtpIfTable_rowreq_ctx)
 *
 * @retval MFD_SUCCESS : success
 * @retval MFD_ERROR   : error. set will fail.
 *
 * This function will be called after the table level undo setup function
 * dot11WtpIfTable_undo_setup has been called.
 *
 *@note
 * this function will only be called if a new value is set for this column.
 *
 * If there is any setup specific to a particular column (e.g. allocating
 * memory for a string), you should do that setup in this function, so it
 * won't be done unless it is necessary.
 */
int
wtpIfAdminStatus_undo_setup( dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{
    DEBUGMSGTL(("verbose:dot11WtpIfTable:wtpIfAdminStatus_undo_setup","called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:455:o: |-> Setup wtpIfAdminStatus undo.
     */
    /*
     * copy wtpIfAdminStatus data
     * set rowreq_ctx->undo->wtpIfAdminStatus from rowreq_ctx->data.wtpIfAdminStatus
     */
    rowreq_ctx->undo->wtpIfAdminStatus = rowreq_ctx->data.wtpIfAdminStatus;


    return MFD_SUCCESS;
} /* wtpIfAdminStatus_undo_setup */

/**
 * Set the new value.
 *
 * @param rowreq_ctx
 *        Pointer to the users context. You should know how to
 *        manipulate the value from this object.
 * @param wtpIfAdminStatus_val
 *        A long containing the new value.
 */
int
wtpIfAdminStatus_set( dot11WtpIfTable_rowreq_ctx *rowreq_ctx, u_long wtpIfAdminStatus_val )
{

    DEBUGMSGTL(("verbose:dot11WtpIfTable:wtpIfAdminStatus_set","called\n"));

    /** should never get a NULL pointer */
    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:245:o: |-> Implement wtpIfAdminStatus reverse mapping.
 * If the values for your data type don't exactly match the
 * possible values defined by the mib, you should map them here.
 */
    /*
    ***************************************************
    ***             START EXAMPLE CODE              ***
    ***---------------------------------------------***/
    switch(wtpIfAdminStatus_val) {
        case WTPIFADMINSTATUS_DOWN:
             wtpIfAdminStatus_val = INTERNAL_WTPIFADMINSTATUS_DOWN;
             break;

        case WTPIFADMINSTATUS_UP:
             wtpIfAdminStatus_val = INTERNAL_WTPIFADMINSTATUS_UP;
             break;

             default:
                 snmp_log(LOG_ERR, "couldn't reverse map value %ld for wtpIfAdminStatus\n", wtpIfAdminStatus_val );
                 return SNMP_ERR_GENERR;
    }
    /*
    ***---------------------------------------------***
    ***              END  EXAMPLE CODE              ***
    ***************************************************/

    /*
     * TODO:461:M: |-> Set wtpIfAdminStatus value.
     * set wtpIfAdminStatus value in rowreq_ctx->data
     */
    void *connection = NULL;
    if(SNMPD_DBUS_ERROR == get_instance_dbus_connection(rowreq_ctx->data.parameter, &connection, SNMPD_INSTANCE_MASTER_V3))
        return MFD_ERROR;
        
	int ret = 0;
	char id[5] = { 0 };
	char state[10] = { 0 };
	int rc = MFD_ERROR;

	memset(state,0,10);
	if (wtpIfAdminStatus_val == 1)
	{
		strncpy(state,"uplink",sizeof(state)-1);
	}
	else
	{
		strncpy(state,"downlink",sizeof(state)-1);
	}

	memset(id,0,5);
	snprintf(id,sizeof(id)-1,"%d",(rowreq_ctx->data.wtpIfIndex - 1));

	ret=set_ap_if_updown_func(rowreq_ctx->data.parameter, connection,rowreq_ctx->data.wtpCurrID,"eth",id,state);
	if(ret==1)
	{
    	rowreq_ctx->data.wtpIfAdminStatus = wtpIfAdminStatus_val;
		rc = MFD_SUCCESS;
	}
	else
	{	
	    if(SNMPD_CONNECTION_ERROR == ret) {
            close_slot_dbus_connection(rowreq_ctx->data.parameter.slot_id);
	    }					
		rc = MFD_ERROR;
	}

    return rc;
} /* wtpIfAdminStatus_set */

/**
 * undo the previous set.
 *
 * @param rowreq_ctx
 *        Pointer to the users context.
 */
int
wtpIfAdminStatus_undo( dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{

    DEBUGMSGTL(("verbose:dot11WtpIfTable:wtpIfAdminStatus_undo","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:456:o: |-> Clean up wtpIfAdminStatus undo.
     */
    /*
     * copy wtpIfAdminStatus data
     * set rowreq_ctx->data.wtpIfAdminStatus from rowreq_ctx->undo->wtpIfAdminStatus
     */
    rowreq_ctx->data.wtpIfAdminStatus = rowreq_ctx->undo->wtpIfAdminStatus;

    
    return MFD_SUCCESS;
} /* wtpIfAdminStatus_undo */

/**
 * check dependencies
 *
 * This is useful for for tables which have dependencies between columns
 * (or rows, or tables). For example, two columns allocating a percentage
 * of something add up 100%.
 *
 * Should you need different behavior depending on which columns were
 * set, rowreq_ctx->column_set_flags will indicate which writeable columns were
 * set. The definitions for the FLAG_* bits can be found in
 * dot11WtpIfTable_oids.h.
 * A new row will have the MFD_ROW_CREATED bit set in rowreq_flags.
 *
 * @retval MFD_SUCCESS all the changes to the row are legal
 * @retval MFD_ERROR   one or more changes are not legal
 *
 * (see README-table-dot11WtpIfTable if you don't have dependencies)
 */
int
dot11WtpIfTable_check_dependencies(dot11WtpIfTable_rowreq_ctx *rowreq_ctx)
{
    int rc = MFD_SUCCESS;
    
    DEBUGMSGTL(("internal:dot11WtpIfTable:dot11WtpIfTable_check_dependencies","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:470:o: Check dot11WtpIfTable row dependencies.
     * check that all new value are legal and consistent with each other
     */
    return rc;
} /* dot11WtpIfTable_check_dependencies */

/** @} */
