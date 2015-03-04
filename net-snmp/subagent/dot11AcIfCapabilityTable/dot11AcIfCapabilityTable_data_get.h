/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.18.2.1 $ of : mfd-data-get.m2c,v $
 *
 * $Id:$
 *
 * @file dot11AcIfCapabilityTable_data_get.h
 *
 * @addtogroup get
 *
 * Prototypes for get functions
 *
 * @{
 */
#ifndef DOT11ACIFCAPABILITYTABLE_DATA_GET_H
#define DOT11ACIFCAPABILITYTABLE_DATA_GET_H

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
 *** Table dot11AcIfCapabilityTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * dot11AcIfCapabilityTable is subid 3 of dot11AcInterface.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.4.3, length: 12
*/
    /*
     * indexes
     */
    int ifIndex_map(long *mib_ifIndex_val_ptr, long raw_ifIndex_val);

    int acIfInUcastPkts_map(unsigned long long *mib_acIfInUcastPkts_val_ptr, unsigned long long raw_acIfInUcastPkts_val);
    int acIfInUcastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acIfInUcastPkts_val_ptr );
    int acIfInNUcastPkts_map(unsigned long long *mib_acIfInNUcastPkts_val_ptr, unsigned long long raw_acIfInNUcastPkts_val);
    int acIfInNUcastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acIfInNUcastPkts_val_ptr );
    int acIfInOctets_map(unsigned long long *mib_acIfInOctets_val_ptr, unsigned long long raw_acIfInOctets_val);
    int acIfInOctets_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acIfInOctets_val_ptr );
    int acIfInDiscardPkts_map(u_long *mib_acIfInDiscardPkts_val_ptr, u_long raw_acIfInDiscardPkts_val);
    int acIfInDiscardPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acIfInDiscardPkts_val_ptr );
    int acIfInErrors_map(u_long *mib_acIfInErrors_val_ptr, u_long raw_acIfInErrors_val);
    int acIfInErrors_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acIfInErrors_val_ptr );
    int acIfOutUcastPkts_map(unsigned long long *mib_acIfOutUcastPkts_val_ptr, unsigned long long raw_acIfOutUcastPkts_val);
    int acIfOutUcastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acIfOutUcastPkts_val_ptr );
    int acIfOutNUcastPkts_map(unsigned long long *mib_acIfOutNUcastPkts_val_ptr, unsigned long long raw_acIfOutNUcastPkts_val);
    int acIfOutNUcastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acIfOutNUcastPkts_val_ptr );
    int acIfOutOctets_map(unsigned long long *mib_acIfOutOctets_val_ptr, unsigned long long raw_acIfOutOctets_val);
    int acIfOutOctets_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acIfOutOctets_val_ptr );
    int acIfOutDiscardPkts_map(u_long *mib_acIfOutDiscardPkts_val_ptr, u_long raw_acIfOutDiscardPkts_val);
    int acIfOutDiscardPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acIfOutDiscardPkts_val_ptr );
    int acIfOutErrors_map(u_long *mib_acIfOutErrors_val_ptr, u_long raw_acIfOutErrors_val);
    int acIfOutErrors_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acIfOutErrors_val_ptr );
    int acIfUpDwnTimes_map(u_long *mib_acIfUpDwnTimes_val_ptr, u_long raw_acIfUpDwnTimes_val);
    int acIfUpDwnTimes_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acIfUpDwnTimes_val_ptr );
    int acIfInMulticastPkts_map(u_long *mib_acIfInMulticastPkts_val_ptr, u_long raw_acIfInMulticastPkts_val);
    int acIfInMulticastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acIfInMulticastPkts_val_ptr );
    int acIfOutMulticastPkts_map(u_long *mib_acIfOutMulticastPkts_val_ptr, u_long raw_acIfOutMulticastPkts_val);
    int acIfOutMulticastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acIfOutMulticastPkts_val_ptr );
    int acUplinkRate_map(unsigned long long *mib_acUplinkRate_val_ptr, unsigned long long raw_acUplinkRate_val);
    int acUplinkRate_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acUplinkRate_val_ptr );
    int acDownlinkRate_map(unsigned long long *mib_acDownlinkRate_val_ptr, unsigned long long raw_acDownlinkRate_val);
    int acDownlinkRate_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acDownlinkRate_val_ptr );
    int acBandwidthUsage_map(u_long *mib_acBandwidthUsage_val_ptr, u_long raw_acBandwidthUsage_val);
    int acBandwidthUsage_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acBandwidthUsage_val_ptr );
    int acDropUsage_map(u_long *mib_acDropUsage_val_ptr, u_long raw_acDropUsage_val);
    int acDropUsage_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acDropUsage_val_ptr );
    int acIfOutBroadcastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acIfOutBroadcastPkts_val_ptr );
    int acUplinkKbyteRate_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acUplinkKbyteRate_val_ptr );
    int acDownlinkKbyteRate_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, u_long * acDownlinkKbyteRate_val_ptr );
	int acipv6IfInReceivesPkts_map(unsigned long long *mib_acipv6IfInReceivesPkts_val_ptr, unsigned long long raw_acipv6IfInReceivesPkts_val);
    int acipv6IfInReceivesPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInReceivesPkts_val_ptr );
	int acipv6IfInHdrErrorsPkts_map(unsigned long long *mib_acipv6IfInHdrErrorsPkts_val_ptr, unsigned long long raw_acipv6IfInHdrErrorsPkts_val);
    int acipv6IfInHdrErrorsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInHdrErrorsPkts_val_ptr );
	int acipv6IfInTooBigErrorsPkts_map(unsigned long long *mib_acipv6IfInTooBigErrorsPkts_val_ptr, unsigned long long raw_acipv6IfInTooBigErrorsPkts_val);
    int acipv6IfInTooBigErrorsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInTooBigErrorsPkts_val_ptr );
	int acipv6IfInNoRoutesPkts_map(unsigned long long *mib_acipv6IfInNoRoutesPkts_val_ptr, unsigned long long raw_acipv6IfInNoRoutesPkts_val);
    int acipv6IfInNoRoutesPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInNoRoutesPkts_val_ptr );
	int acipv6IfInAddrErrorsPkts_map(unsigned long long *mib_acipv6IfInAddrErrorsPkts_val_ptr, unsigned long long raw_acipv6IfInAddrErrorsPkts_val);
    int acipv6IfInAddrErrorsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInAddrErrorsPkts_val_ptr );
	int acipv6IfInUnknownProtosPkts_map(unsigned long long *mib_acipv6IfInUnknownProtosPkts_val_ptr, unsigned long long raw_acipv6IfInUnknownProtosPkts_val);
    int acipv6IfInUnknownProtosPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInUnknownProtosPkts_val_ptr );
	int acipv6IfInTruncatedPkts_map(unsigned long long *mib_acipv6IfInTruncatedPkts_val_ptr, unsigned long long raw_acipv6IfInTruncatedPkts_val);
    int acipv6IfInTruncatedPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInTruncatedPkts_val_ptr );
	int acipv6IfInDiscardsPkts_map(unsigned long long *mib_acipv6IfInDiscardsPkts_val_ptr, unsigned long long raw_acipv6IfInDiscardsPkts_val);
    int acipv6IfInDiscardsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInDiscardsPkts_val_ptr );
	int acipv6IfInDeliversPkts_map(unsigned long long *mib_acipv6IfInDeliversPkts_val_ptr, unsigned long long raw_acipv6IfInDeliversPkts_val);
    int acipv6IfInDeliversPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInDeliversPkts_val_ptr );
	int acipv6IfOutForwDatagramsPkts_map(unsigned long long *mib_acipv6IfOutForwDatagramsPkts_val_ptr, unsigned long long raw_acipv6IfOutForwDatagramsPkts_val);
    int acipv6IfOutForwDatagramsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfOutForwDatagramsPkts_val_ptr );
	int acipv6IfOutRequestsPkts_map(unsigned long long *mib_acipv6IfOutRequestsPkts_val_ptr, unsigned long long raw_acipv6IfOutRequestsPkts_val);
    int acipv6IfOutRequestsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfOutRequestsPkts_val_ptr );
	int acipv6IfOutDiscardsPkts_map(unsigned long long *mib_acipv6IfOutDiscardsPkts_val_ptr, unsigned long long raw_acipv6IfOutDiscardsPkts_val);
    int acipv6IfOutDiscardsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfOutDiscardsPkts_val_ptr );
	int acipv6IfOutFragOKsPkts_map(unsigned long long *mib_acipv6IfOutFragOKsPkts_val_ptr, unsigned long long raw_acipv6IfOutFragOKsPkts_val);
    int acipv6IfOutFragOKsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfOutFragOKsPkts_val_ptr );
	int acipv6IfOutFragFailsPkts_map(unsigned long long *mib_acipv6IfOutFragFailsPkts_val_ptr, unsigned long long raw_acipv6IfOutFragFailsPkts_val);
    int acipv6IfOutFragFailsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfOutFragFailsPkts_val_ptr );
	int acipv6IfOutFragCreatesPkts_map(unsigned long long *mib_acipv6IfOutFragCreatesPkts_val_ptr, unsigned long long raw_acipv6IfOutFragCreatesPkts_val);
    int acipv6IfOutFragCreatesPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfOutFragCreatesPkts_val_ptr );
	int acipv6IfReasmReqdsPkts_map(unsigned long long *mib_acipv6IfReasmReqdsPkts_val_ptr, unsigned long long raw_acipv6IfReasmReqdsPkts_val);
    int acipv6IfReasmReqdsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfReasmReqdsPkts_val_ptr );
	int acipv6IfReasmOKsPkts_map(unsigned long long *mib_acipv6IfReasmOKsPkts_val_ptr, unsigned long long raw_acipv6IfReasmOKsPkts_val);
    int acipv6IfReasmOKsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfReasmOKsPkts_val_ptr );
	int acipv6IfReasmFailsPkts_map(unsigned long long *mib_acipv6IfReasmFailsPkts_val_ptr, unsigned long long raw_acipv6IfReasmFailsPkts_val);
    int acipv6IfReasmFailsPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfReasmFailsPkts_val_ptr );
	int acipv6IfInMcastPkts_map(unsigned long long *mib_acipv6IfInMcastPkts_val_ptr, unsigned long long raw_acipv6IfInMcastPkts_val);
    int acipv6IfInMcastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfInMcastPkts_val_ptr );
	int acipv6IfOutMcastPkts_map(unsigned long long *mib_acipv6IfOutMcastPkts_val_ptr, unsigned long long raw_acipv6IfOutMcastPkts_val);
    int acipv6IfOutMcastPkts_get( dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, unsigned long long * acipv6IfOutMcastPkts_val_ptr );


int dot11AcIfCapabilityTable_indexes_set_tbl_idx(dot11AcIfCapabilityTable_mib_index *tbl_idx, long ifIndex_val);
int dot11AcIfCapabilityTable_indexes_set(dot11AcIfCapabilityTable_rowreq_ctx *rowreq_ctx, long ifIndex_val);




#ifdef __cplusplus
}
#endif

#endif /* DOT11ACIFCAPABILITYTABLE_DATA_GET_H */
/** @} */
