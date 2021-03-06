/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $
 *
 * $Id:$
 *
 * @file dot11PermitSSIDTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11PERMITSSIDTABLE_DATA_GET_H
#define DOT11PERMITSSIDTABLE_DATA_GET_H

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
 *** Table dot11PermitSSIDTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11PermitSSIDTable is subid 10 of dot11AcGroup.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.10, length: 11
*/
    /*
     * indexes
     */

    int permitSSID_get( dot11PermitSSIDTable_rowreq_ctx *rowreq_ctx, char **permitSSID_val_ptr_ptr, size_t *permitSSID_val_ptr_len_ptr );
    int permitSSIDRowStatus_get( dot11PermitSSIDTable_rowreq_ctx *rowreq_ctx, u_long * permitSSIDRowStatus_val_ptr );


int dot11PermitSSIDTable_indexes_set_tbl_idx(dot11PermitSSIDTable_mib_index *tbl_idx, long permitSSIDID_val);
int dot11PermitSSIDTable_indexes_set(dot11PermitSSIDTable_rowreq_ctx *rowreq_ctx, long permitSSIDID_val);




#ifdef __cplusplus
}
#endif

#endif /* DOT11PERMITSSIDTABLE_DATA_GET_H */
/** @} */
