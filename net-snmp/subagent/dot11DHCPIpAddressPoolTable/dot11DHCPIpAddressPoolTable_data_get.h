/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18.2.1 $ of : mfd-data-get.m2c,v $
 *
 * $Id:$
 *
 * @file dot11DHCPIpAddressPoolTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11DHCPIPADDRESSPOOLTABLE_DATA_GET_H
#define DOT11DHCPIPADDRESSPOOLTABLE_DATA_GET_H

#ifdef __cplusplus
extern "C" {
#endif

/* *********************************************************************
 * GET function declarations
 */

/* *********************************************************************
 * GET Table declarations
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11DHCPIpAddressPoolTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11DHCPIpAddressPoolTable is subid 4 of dot11Service.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.4, length: 12
*/
    /*
     * indexes
     */
    int AddPoolIndex_map(long *mib_AddPoolIndex_val_ptr, long raw_AddPoolIndex_val);

    int IPAddpoolStartAdd_map(u_long *mib_IPAddpoolStartAdd_val_ptr, u_long raw_IPAddpoolStartAdd_val);
    int IPAddpoolStartAdd_get( dot11DHCPIpAddressPoolTable_rowreq_ctx *rowreq_ctx, u_long * IPAddpoolStartAdd_val_ptr );
    int IPAddpoolEndAdd_map(u_long *mib_IPAddpoolEndAdd_val_ptr, u_long raw_IPAddpoolEndAdd_val);
    int IPAddpoolEndAdd_get( dot11DHCPIpAddressPoolTable_rowreq_ctx *rowreq_ctx, u_long * IPAddpoolEndAdd_val_ptr );
    int GatewayAddress_map(u_long *mib_GatewayAddress_val_ptr, u_long raw_GatewayAddress_val);
    int GatewayAddress_get( dot11DHCPIpAddressPoolTable_rowreq_ctx *rowreq_ctx, u_long * GatewayAddress_val_ptr );
    int IPAddLeasePeriod_map(long *mib_IPAddLeasePeriod_val_ptr, long raw_IPAddLeasePeriod_val);
    int IPAddLeasePeriod_get( dot11DHCPIpAddressPoolTable_rowreq_ctx *rowreq_ctx, long * IPAddLeasePeriod_val_ptr );


int dot11DHCPIpAddressPoolTable_indexes_set_tbl_idx(dot11DHCPIpAddressPoolTable_mib_index *tbl_idx, long AddPoolIndex_val);
int dot11DHCPIpAddressPoolTable_indexes_set(dot11DHCPIpAddressPoolTable_rowreq_ctx *rowreq_ctx, long AddPoolIndex_val);




#ifdef __cplusplus
}
#endif

#endif /* DOT11DHCPIPADDRESSPOOLTABLE_DATA_GET_H */
/** @} */
