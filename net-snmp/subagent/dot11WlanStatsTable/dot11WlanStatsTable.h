/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.32.2.3 $ of : mfd-top.m2c,v $
 *
 * $Id:$
 */
#ifndef DOT11WLANSTATSTABLE_H
#define DOT11WLANSTATSTABLE_H

#ifdef __cplusplus
extern "C" {
#endif


/** @defgroup misc misc: Miscelaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>

/* other required module components */
    /* *INDENT-OFF*  */
config_require(DOT11-AC-MIB/dot11WlanStatsTable/dot11WlanStatsTable_interface);
config_require(DOT11-AC-MIB/dot11WlanStatsTable/dot11WlanStatsTable_data_access);
config_require(DOT11-AC-MIB/dot11WlanStatsTable/dot11WlanStatsTable_data_get);
config_require(DOT11-AC-MIB/dot11WlanStatsTable/dot11WlanStatsTable_data_set);
    /* *INDENT-ON*  */

/* OID and column number definitions for  */
#include "dot11WlanStatsTable_oids.h"

/* enum definions */
#include "dot11WlanStatsTable_enums.h"
#include "ws_dbus_list_interface.h"

/* *********************************************************************
 * function declarations
 */
void init_dot11WlanStatsTable(void);

/* *********************************************************************
 * Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11WlanStatsTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11WlanStatsTable is subid 4 of dot11wlanConfig.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.13.4, length: 12
*/
/* *********************************************************************
 * When you register your mib, you get to provide a generic
 * pointer that will be passed back to you for most of the
 * functions calls.
 *
 * TODO:100:r: Review all context structures
 */
    /*
     * TODO:101:o: |-> Review dot11WlanStatsTable registration context.
     */
typedef netsnmp_data_list * dot11WlanStatsTable_registration_ptr;

/**********************************************************************/
/*
 * TODO:110:r: |-> Review dot11WlanStatsTable data context structure.
 * This structure is used to represent the data for dot11WlanStatsTable.
 */
/*
 * This structure contains storage for all the columns defined in the
 * dot11WlanStatsTable.
 */
typedef struct dot11WlanStatsTable_data_s {
    
        /*
         * wlanAssocedStaNum(1)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   wlanAssocedStaNum;
    
        /*
         * wlanAssocReqTimes(2)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   wlanAssocReqTimes;
    
        /*
         * wlanAssocRespTimes(3)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   wlanAssocRespTimes;
    
        /*
         * wlanAssocSuccessTimes(4)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   wlanAssocSuccessTimes;
    
        /*
         * wlanAssocFailTimes(5)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   wlanAssocFailTimes;
    
        /*
         * wlanUnassocNormallyTimes(6)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   wlanUnassocNormallyTimes;
    
        /*
         * wlanUnassocAnomalyTimes(7)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h
         */
   u_long   wlanUnassocAnomalyTimes;
    
} dot11WlanStatsTable_data;


/*
 * TODO:120:r: |-> Review dot11WlanStatsTable mib index.
 * This structure is used to represent the index for dot11WlanStatsTable.
 */
typedef struct dot11WlanStatsTable_mib_index_s {

        /*
         * wlanID(1)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/r/d/h
         */
   long   wlanID;


} dot11WlanStatsTable_mib_index;

    /*
     * TODO:121:r: |   |-> Review dot11WlanStatsTable max index length.
     * If you KNOW that your indexes will never exceed a certain
     * length, update this macro to that length.
*/
#define MAX_dot11WlanStatsTable_IDX_LEN     1


/* *********************************************************************
 * TODO:130:o: |-> Review dot11WlanStatsTable Row request (rowreq) context.
 * When your functions are called, you will be passed a
 * dot11WlanStatsTable_rowreq_ctx pointer.
 */
typedef struct dot11WlanStatsTable_rowreq_ctx_s {

    /** this must be first for container compare to work */
    netsnmp_index        oid_idx;
    oid                  oid_tmp[MAX_dot11WlanStatsTable_IDX_LEN];
    
    dot11WlanStatsTable_mib_index        tbl_idx;
    
    dot11WlanStatsTable_data              data;

    /*
     * flags per row. Currently, the first (lower) 8 bits are reserved
     * for the user. See mfd.h for other flags.
     */
    u_int                       rowreq_flags;

    /*
     * implementor's context pointer (provided during registration)
     */
    dot11WlanStatsTable_registration_ptr dot11WlanStatsTable_reg;

    /*
     * TODO:131:o: |   |-> Add useful data to dot11WlanStatsTable rowreq context.
     */
    
    /*
     * storage for future expansion
     */
    netsnmp_data_list             *dot11WlanStatsTable_data_list;

} dot11WlanStatsTable_rowreq_ctx;

typedef struct dot11WlanStatsTable_ref_rowreq_ctx_s {
    dot11WlanStatsTable_rowreq_ctx *rowreq_ctx;
} dot11WlanStatsTable_ref_rowreq_ctx;

/* *********************************************************************
 * function prototypes
 */
    int dot11WlanStatsTable_pre_request(dot11WlanStatsTable_registration_ptr user_context);
    int dot11WlanStatsTable_post_request(dot11WlanStatsTable_registration_ptr user_context);


extern oid dot11WlanStatsTable_oid[];
extern int dot11WlanStatsTable_oid_size;


#include "dot11WlanStatsTable_interface.h"
#include "dot11WlanStatsTable_data_access.h"
#include "dot11WlanStatsTable_data_get.h"
#include "dot11WlanStatsTable_data_set.h"

/*
 * DUMMY markers, ignore
 *
 * TODO:099:x: *************************************************************
 * TODO:199:x: *************************************************************
 * TODO:299:x: *************************************************************
 * TODO:399:x: *************************************************************
 * TODO:499:x: *************************************************************
 */

#ifdef __cplusplus
}
#endif

#endif /* DOT11WLANSTATSTABLE_H */
