/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $
 *
 * $Id:$
 *
 * @file dot11CreateQosTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11CREATEQOSTABLE_DATA_GET_H
#define DOT11CREATEQOSTABLE_DATA_GET_H

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
 *** Table dot11CreateQosTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-QoS-MIB::dot11CreateQosTable is subid 1 of dot11QoSCreate.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.3.3.1, length: 12
*/
    /*
     * indexes
     */

    int QoSName_get( dot11CreateQosTable_rowreq_ctx *rowreq_ctx, char **QoSName_val_ptr_ptr, size_t *QoSName_val_ptr_len_ptr );
    int QoSRowStatus_get( dot11CreateQosTable_rowreq_ctx *rowreq_ctx, u_long * QoSRowStatus_val_ptr );


int dot11CreateQosTable_indexes_set_tbl_idx(dot11CreateQosTable_mib_index *tbl_idx, long QosID_val);
int dot11CreateQosTable_indexes_set(dot11CreateQosTable_rowreq_ctx *rowreq_ctx, long QosID_val);




#ifdef __cplusplus
}
#endif

#endif /* DOT11CREATEQOSTABLE_DATA_GET_H */
/** @} */
