/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $
 *
 * $Id:$
 *
 * @file dot11AcPhyPortTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11ACPHYPORTTABLE_DATA_GET_H
#define DOT11ACPHYPORTTABLE_DATA_GET_H

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
 *** Table dot11AcPhyPortTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11AcPhyPortTable is subid 6 of dot11AcInterface.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.4.6, length: 12
*/
    /*
     * indexes
     */

    int PhyPortDescr_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, char **PhyPortDescr_val_ptr_ptr, size_t *PhyPortDescr_val_ptr_len_ptr );
    int PhyPortType_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long * PhyPortType_val_ptr );
    int PhyPortMTU_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, long * PhyPortMTU_val_ptr );
    int PhyPortSpeed_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long * PhyPortSpeed_val_ptr );
    int PhyPortPhysAddress_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, char **PhyPortPhysAddress_val_ptr_ptr, size_t *PhyPortPhysAddress_val_ptr_len_ptr );
    int PhyPortAdminStatus_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long * PhyPortAdminStatus_val_ptr );
    int PhyPortOperStatus_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long * PhyPortOperStatus_val_ptr );
    int PhyPortLastChange_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, u_long * PhyPortLastChange_val_ptr );
    int PhyPortUpDwnTimes_get( dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, long * PhyPortUpDwnTimes_val_ptr );


int dot11AcPhyPortTable_indexes_set_tbl_idx(dot11AcPhyPortTable_mib_index *tbl_idx, long PhyPortIndex_val);
int dot11AcPhyPortTable_indexes_set(dot11AcPhyPortTable_rowreq_ctx *rowreq_ctx, long PhyPortIndex_val);




#ifdef __cplusplus
}
#endif

#endif /* DOT11ACPHYPORTTABLE_DATA_GET_H */
/** @} */
