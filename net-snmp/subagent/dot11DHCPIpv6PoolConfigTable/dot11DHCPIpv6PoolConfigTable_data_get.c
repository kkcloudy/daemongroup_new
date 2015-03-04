/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $ 
 *
 * $Id:$
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "dot11DHCPIpv6PoolConfigTable.h"


/** @defgroup data_get data_get: Routines to get data
 *
 * TODO:230:M: Implement dot11DHCPIpv6PoolConfigTable get routines.
 * TODO:240:M: Implement dot11DHCPIpv6PoolConfigTable mapping routines (if any).
 *
 * These routine are used to get the value for individual objects. The
 * row context is passed, along with a pointer to the memory where the
 * value should be copied.
 *
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table dot11DHCPIpv6PoolConfigTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigTable is subid 7 of dot11Service.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7, length: 12
*/

/* ---------------------------------------------------------------------
 * TODO:200:r: Implement dot11DHCPIpv6PoolConfigTable data context functions.
 */


/**
 * set mib index(es)
 *
 * @param tbl_idx mib index structure
 * @param Ipv6DHCPID_val
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This convenience function is useful for setting all the MIB index
 *  components with a single function call. It is assume that the C values
 *  have already been mapped from their native/rawformat to the MIB format.
 */
int
dot11DHCPIpv6PoolConfigTable_indexes_set_tbl_idx(dot11DHCPIpv6PoolConfigTable_mib_index *tbl_idx, long Ipv6DHCPID_val)
{
    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:dot11DHCPIpv6PoolConfigTable_indexes_set_tbl_idx","called\n"));

    /* Ipv6DHCPID(1)/INTEGER/ASN_INTEGER/long(long)//l/A/W/e/r/d/h */
    tbl_idx->Ipv6DHCPID = Ipv6DHCPID_val;
    

    return MFD_SUCCESS;
} /* dot11DHCPIpv6PoolConfigTable_indexes_set_tbl_idx */

/**
 * @internal
 * set row context indexes
 *
 * @param reqreq_ctx the row context that needs updated indexes
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This function sets the mib indexs, then updates the oid indexs
 *  from the mib index.
 */
int
dot11DHCPIpv6PoolConfigTable_indexes_set(dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, long Ipv6DHCPID_val)
{
    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:dot11DHCPIpv6PoolConfigTable_indexes_set","called\n"));

    if(MFD_SUCCESS != dot11DHCPIpv6PoolConfigTable_indexes_set_tbl_idx(&rowreq_ctx->tbl_idx
                                   , Ipv6DHCPID_val
           ))
        return MFD_ERROR;

    /*
     * convert mib index to oid index
     */
    rowreq_ctx->oid_idx.len = sizeof(rowreq_ctx->oid_tmp) / sizeof(oid);
    if(0 != dot11DHCPIpv6PoolConfigTable_index_to_oid(&rowreq_ctx->oid_idx,
                                    &rowreq_ctx->tbl_idx)) {
        return MFD_ERROR;
    }

    return MFD_SUCCESS;
} /* dot11DHCPIpv6PoolConfigTable_indexes_set */


/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.Ipv6DHCPPoolName
 * Ipv6DHCPPoolName is subid 2 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.2
 * Description:
DHCP IPV6 pool name.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   1
 *   hint: 255a
 *
 * Ranges:  0 - 255;
 *
 * Its syntax is DisplayString (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 255)
 */
/**
 * Extract the current value of the Ipv6DHCPPoolName data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param Ipv6DHCPPoolName_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param Ipv6DHCPPoolName_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by Ipv6DHCPPoolName.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*Ipv6DHCPPoolName_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update Ipv6DHCPPoolName_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
Ipv6DHCPPoolName_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, char **Ipv6DHCPPoolName_val_ptr_ptr, size_t *Ipv6DHCPPoolName_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != Ipv6DHCPPoolName_val_ptr_ptr) && (NULL != *Ipv6DHCPPoolName_val_ptr_ptr));
   netsnmp_assert( NULL != Ipv6DHCPPoolName_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:Ipv6DHCPPoolName_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the Ipv6DHCPPoolName data.
 * copy (* Ipv6DHCPPoolName_val_ptr_ptr ) data and (* Ipv6DHCPPoolName_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for Ipv6DHCPPoolName data
     */
    if ((NULL == (* Ipv6DHCPPoolName_val_ptr_ptr )) ||
        ((* Ipv6DHCPPoolName_val_ptr_len_ptr ) <
         (rowreq_ctx->data.Ipv6DHCPPoolName_len* sizeof(rowreq_ctx->data.Ipv6DHCPPoolName[0])))) {
        /*
         * allocate space for Ipv6DHCPPoolName data
         */
        (* Ipv6DHCPPoolName_val_ptr_ptr ) = malloc(rowreq_ctx->data.Ipv6DHCPPoolName_len* sizeof(rowreq_ctx->data.Ipv6DHCPPoolName[0]));
        if(NULL == (* Ipv6DHCPPoolName_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* Ipv6DHCPPoolName_val_ptr_len_ptr ) = rowreq_ctx->data.Ipv6DHCPPoolName_len* sizeof(rowreq_ctx->data.Ipv6DHCPPoolName[0]);
    memcpy( (* Ipv6DHCPPoolName_val_ptr_ptr ), rowreq_ctx->data.Ipv6DHCPPoolName, rowreq_ctx->data.Ipv6DHCPPoolName_len* sizeof(rowreq_ctx->data.Ipv6DHCPPoolName[0]) );

    return MFD_SUCCESS;
} /* Ipv6DHCPPoolName_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.IPv6PoolStartAddr
 * IPv6PoolStartAddr is subid 3 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.3
 * Description:
IPV6 Address pool starting address.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   1
 *   hint: 2x:
 *
 * Ranges:  16;
 *
 * Its syntax is InetAddressIPv6 (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 16)
 */
/**
 * Extract the current value of the IPv6PoolStartAddr data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param IPv6PoolStartAddr_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param IPv6PoolStartAddr_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by IPv6PoolStartAddr.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*IPv6PoolStartAddr_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update IPv6PoolStartAddr_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
IPv6PoolStartAddr_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, char **IPv6PoolStartAddr_val_ptr_ptr, size_t *IPv6PoolStartAddr_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != IPv6PoolStartAddr_val_ptr_ptr) && (NULL != *IPv6PoolStartAddr_val_ptr_ptr));
   netsnmp_assert( NULL != IPv6PoolStartAddr_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:IPv6PoolStartAddr_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the IPv6PoolStartAddr data.
 * copy (* IPv6PoolStartAddr_val_ptr_ptr ) data and (* IPv6PoolStartAddr_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for IPv6PoolStartAddr data
     */
    if ((NULL == (* IPv6PoolStartAddr_val_ptr_ptr )) ||
        ((* IPv6PoolStartAddr_val_ptr_len_ptr ) <
         (rowreq_ctx->data.IPv6PoolStartAddr_len* sizeof(rowreq_ctx->data.IPv6PoolStartAddr[0])))) {
        /*
         * allocate space for IPv6PoolStartAddr data
         */
        (* IPv6PoolStartAddr_val_ptr_ptr ) = malloc(rowreq_ctx->data.IPv6PoolStartAddr_len* sizeof(rowreq_ctx->data.IPv6PoolStartAddr[0]));
        if(NULL == (* IPv6PoolStartAddr_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* IPv6PoolStartAddr_val_ptr_len_ptr ) = rowreq_ctx->data.IPv6PoolStartAddr_len* sizeof(rowreq_ctx->data.IPv6PoolStartAddr[0]);
    memcpy( (* IPv6PoolStartAddr_val_ptr_ptr ), rowreq_ctx->data.IPv6PoolStartAddr, rowreq_ctx->data.IPv6PoolStartAddr_len* sizeof(rowreq_ctx->data.IPv6PoolStartAddr[0]) );

    return MFD_SUCCESS;
} /* IPv6PoolStartAddr_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.IPv6PoolStopAddr
 * IPv6PoolStopAddr is subid 4 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.4
 * Description:
IPV6 Address pool ending address.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   1
 *   hint: 2x:
 *
 * Ranges:  16;
 *
 * Its syntax is InetAddressIPv6 (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 16)
 */
/**
 * Extract the current value of the IPv6PoolStopAddr data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param IPv6PoolStopAddr_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param IPv6PoolStopAddr_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by IPv6PoolStopAddr.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*IPv6PoolStopAddr_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update IPv6PoolStopAddr_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
IPv6PoolStopAddr_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, char **IPv6PoolStopAddr_val_ptr_ptr, size_t *IPv6PoolStopAddr_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != IPv6PoolStopAddr_val_ptr_ptr) && (NULL != *IPv6PoolStopAddr_val_ptr_ptr));
   netsnmp_assert( NULL != IPv6PoolStopAddr_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:IPv6PoolStopAddr_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the IPv6PoolStopAddr data.
 * copy (* IPv6PoolStopAddr_val_ptr_ptr ) data and (* IPv6PoolStopAddr_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for IPv6PoolStopAddr data
     */
    if ((NULL == (* IPv6PoolStopAddr_val_ptr_ptr )) ||
        ((* IPv6PoolStopAddr_val_ptr_len_ptr ) <
         (rowreq_ctx->data.IPv6PoolStopAddr_len* sizeof(rowreq_ctx->data.IPv6PoolStopAddr[0])))) {
        /*
         * allocate space for IPv6PoolStopAddr data
         */
        (* IPv6PoolStopAddr_val_ptr_ptr ) = malloc(rowreq_ctx->data.IPv6PoolStopAddr_len* sizeof(rowreq_ctx->data.IPv6PoolStopAddr[0]));
        if(NULL == (* IPv6PoolStopAddr_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* IPv6PoolStopAddr_val_ptr_len_ptr ) = rowreq_ctx->data.IPv6PoolStopAddr_len* sizeof(rowreq_ctx->data.IPv6PoolStopAddr[0]);
    memcpy( (* IPv6PoolStopAddr_val_ptr_ptr ), rowreq_ctx->data.IPv6PoolStopAddr, rowreq_ctx->data.IPv6PoolStopAddr_len* sizeof(rowreq_ctx->data.IPv6PoolStopAddr[0]) );

    return MFD_SUCCESS;
} /* IPv6PoolStopAddr_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.IPv6NetPrefixLen
 * IPv6NetPrefixLen is subid 5 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.5
 * Description:
Prefix length.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   0
 *   settable   1
 *
 * Ranges:  1 - 128;
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * Extract the current value of the IPv6NetPrefixLen data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param IPv6NetPrefixLen_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
IPv6NetPrefixLen_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, long * IPv6NetPrefixLen_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != IPv6NetPrefixLen_val_ptr );


    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:IPv6NetPrefixLen_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the IPv6NetPrefixLen data.
 * copy (* IPv6NetPrefixLen_val_ptr ) from rowreq_ctx->data
 */
    (* IPv6NetPrefixLen_val_ptr ) = rowreq_ctx->data.IPv6NetPrefixLen;

    return MFD_SUCCESS;
} /* IPv6NetPrefixLen_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.FirDNSServerIPv6Address
 * FirDNSServerIPv6Address is subid 6 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.6
 * Description:
IP Address first DNS IP Address.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   1
 *   hint: 2x:
 *
 * Ranges:  16;
 *
 * Its syntax is InetAddressIPv6 (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 16)
 */
/**
 * Extract the current value of the FirDNSServerIPv6Address data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param FirDNSServerIPv6Address_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param FirDNSServerIPv6Address_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by FirDNSServerIPv6Address.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*FirDNSServerIPv6Address_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update FirDNSServerIPv6Address_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
FirDNSServerIPv6Address_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, char **FirDNSServerIPv6Address_val_ptr_ptr, size_t *FirDNSServerIPv6Address_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != FirDNSServerIPv6Address_val_ptr_ptr) && (NULL != *FirDNSServerIPv6Address_val_ptr_ptr));
   netsnmp_assert( NULL != FirDNSServerIPv6Address_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:FirDNSServerIPv6Address_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the FirDNSServerIPv6Address data.
 * copy (* FirDNSServerIPv6Address_val_ptr_ptr ) data and (* FirDNSServerIPv6Address_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for FirDNSServerIPv6Address data
     */
    if ((NULL == (* FirDNSServerIPv6Address_val_ptr_ptr )) ||
        ((* FirDNSServerIPv6Address_val_ptr_len_ptr ) <
         (rowreq_ctx->data.FirDNSServerIPv6Address_len* sizeof(rowreq_ctx->data.FirDNSServerIPv6Address[0])))) {
        /*
         * allocate space for FirDNSServerIPv6Address data
         */
        (* FirDNSServerIPv6Address_val_ptr_ptr ) = malloc(rowreq_ctx->data.FirDNSServerIPv6Address_len* sizeof(rowreq_ctx->data.FirDNSServerIPv6Address[0]));
        if(NULL == (* FirDNSServerIPv6Address_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* FirDNSServerIPv6Address_val_ptr_len_ptr ) = rowreq_ctx->data.FirDNSServerIPv6Address_len* sizeof(rowreq_ctx->data.FirDNSServerIPv6Address[0]);
    memcpy( (* FirDNSServerIPv6Address_val_ptr_ptr ), rowreq_ctx->data.FirDNSServerIPv6Address, rowreq_ctx->data.FirDNSServerIPv6Address_len* sizeof(rowreq_ctx->data.FirDNSServerIPv6Address[0]) );

    return MFD_SUCCESS;
} /* FirDNSServerIPv6Address_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.SeconDNSServerIPv6Address
 * SeconDNSServerIPv6Address is subid 7 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.7
 * Description:
IP Address second DNS IP Address.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   1
 *   hint: 2x:
 *
 * Ranges:  16;
 *
 * Its syntax is InetAddressIPv6 (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 16)
 */
/**
 * Extract the current value of the SeconDNSServerIPv6Address data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param SeconDNSServerIPv6Address_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param SeconDNSServerIPv6Address_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by SeconDNSServerIPv6Address.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*SeconDNSServerIPv6Address_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update SeconDNSServerIPv6Address_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
SeconDNSServerIPv6Address_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, char **SeconDNSServerIPv6Address_val_ptr_ptr, size_t *SeconDNSServerIPv6Address_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != SeconDNSServerIPv6Address_val_ptr_ptr) && (NULL != *SeconDNSServerIPv6Address_val_ptr_ptr));
   netsnmp_assert( NULL != SeconDNSServerIPv6Address_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:SeconDNSServerIPv6Address_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the SeconDNSServerIPv6Address data.
 * copy (* SeconDNSServerIPv6Address_val_ptr_ptr ) data and (* SeconDNSServerIPv6Address_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for SeconDNSServerIPv6Address data
     */
    if ((NULL == (* SeconDNSServerIPv6Address_val_ptr_ptr )) ||
        ((* SeconDNSServerIPv6Address_val_ptr_len_ptr ) <
         (rowreq_ctx->data.SeconDNSServerIPv6Address_len* sizeof(rowreq_ctx->data.SeconDNSServerIPv6Address[0])))) {
        /*
         * allocate space for SeconDNSServerIPv6Address data
         */
        (* SeconDNSServerIPv6Address_val_ptr_ptr ) = malloc(rowreq_ctx->data.SeconDNSServerIPv6Address_len* sizeof(rowreq_ctx->data.SeconDNSServerIPv6Address[0]));
        if(NULL == (* SeconDNSServerIPv6Address_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* SeconDNSServerIPv6Address_val_ptr_len_ptr ) = rowreq_ctx->data.SeconDNSServerIPv6Address_len* sizeof(rowreq_ctx->data.SeconDNSServerIPv6Address[0]);
    memcpy( (* SeconDNSServerIPv6Address_val_ptr_ptr ), rowreq_ctx->data.SeconDNSServerIPv6Address, rowreq_ctx->data.SeconDNSServerIPv6Address_len* sizeof(rowreq_ctx->data.SeconDNSServerIPv6Address[0]) );

    return MFD_SUCCESS;
} /* SeconDNSServerIPv6Address_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.Ipv6LeasePeriod
 * Ipv6LeasePeriod is subid 8 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.8
 * Description:
IPv6 Address Lease Periods.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 *
 * Its syntax is TICKS (based on perltype TICKS)
 * The net-snmp type is ASN_TIMETICKS. The C type decl is u_long (u_long)
 */
/**
 * Extract the current value of the Ipv6LeasePeriod data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param Ipv6LeasePeriod_val_ptr
 *        Pointer to storage for a u_long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
Ipv6LeasePeriod_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, u_long * Ipv6LeasePeriod_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != Ipv6LeasePeriod_val_ptr );


    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:Ipv6LeasePeriod_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the Ipv6LeasePeriod data.
 * copy (* Ipv6LeasePeriod_val_ptr ) from rowreq_ctx->data
 */
    (* Ipv6LeasePeriod_val_ptr ) = rowreq_ctx->data.Ipv6LeasePeriod;

    return MFD_SUCCESS;
} /* Ipv6LeasePeriod_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.Ipv6DHCPRowStatus
 * Ipv6DHCPRowStatus is subid 9 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is Create.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.9
 * Description:
This variable is used to create, modify, and/or delete a row
			        	 in this table.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   1
 *
 * Enum range: 3/8. Values:  active(1), notInService(2), notReady(3), createAndGo(4), createAndWait(5), destroy(6)
 *
 * Its syntax is RowStatus (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * Extract the current value of the Ipv6DHCPRowStatus data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param Ipv6DHCPRowStatus_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
Ipv6DHCPRowStatus_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, u_long * Ipv6DHCPRowStatus_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != Ipv6DHCPRowStatus_val_ptr );

    (* Ipv6DHCPRowStatus_val_ptr ) = rowreq_ctx->data.Ipv6DHCPRowStatus;

    return MFD_SUCCESS;
} /* Ipv6DHCPRowStatus_get */

/*---------------------------------------------------------------------
 * DOT11-AC-MIB::dot11DHCPIpv6PoolConfigEntry.SysIPv6GWAddr
 * SysIPv6GWAddr is subid 10 of dot11DHCPIpv6PoolConfigEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.31656.6.1.2.6.7.1.10
 * Description:
AP IPV6 Gateway address.
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 1      hashint   1
 *   settable   0
 *   hint: 2x:
 *
 * Ranges:  50;
 *
 * Its syntax is InetAddressIPv6 (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.  (Max 50)
 */
/**
 * Extract the current value of the SysIPv6GWAddr data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param SysIPv6GWAddr_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param SysIPv6GWAddr_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by SysIPv6GWAddr.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*SysIPv6GWAddr_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update SysIPv6GWAddr_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
SysIPv6GWAddr_get( dot11DHCPIpv6PoolConfigTable_rowreq_ctx *rowreq_ctx, char **SysIPv6GWAddr_val_ptr_ptr, size_t *SysIPv6GWAddr_val_ptr_len_ptr )
{
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != SysIPv6GWAddr_val_ptr_ptr) && (NULL != *SysIPv6GWAddr_val_ptr_ptr));
   netsnmp_assert( NULL != SysIPv6GWAddr_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:dot11DHCPIpv6PoolConfigTable:SysIPv6GWAddr_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

/*
 * TODO:231:o: |-> Extract the current value of the SysIPv6GWAddr data.
 * copy (* SysIPv6GWAddr_val_ptr_ptr ) data and (* SysIPv6GWAddr_val_ptr_len_ptr ) from rowreq_ctx->data
 */
    /*
     * make sure there is enough space for SysIPv6GWAddr data
     */
    if ((NULL == (* SysIPv6GWAddr_val_ptr_ptr )) ||
        ((* SysIPv6GWAddr_val_ptr_len_ptr ) <
         (rowreq_ctx->data.SysIPv6GWAddr_len* sizeof(rowreq_ctx->data.SysIPv6GWAddr[0])))) {
        /*
         * allocate space for SysIPv6GWAddr data
         */
        (* SysIPv6GWAddr_val_ptr_ptr ) = malloc(rowreq_ctx->data.SysIPv6GWAddr_len* sizeof(rowreq_ctx->data.SysIPv6GWAddr[0]));
        if(NULL == (* SysIPv6GWAddr_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* SysIPv6GWAddr_val_ptr_len_ptr ) = rowreq_ctx->data.SysIPv6GWAddr_len* sizeof(rowreq_ctx->data.SysIPv6GWAddr[0]);
    memcpy( (* SysIPv6GWAddr_val_ptr_ptr ), rowreq_ctx->data.SysIPv6GWAddr, rowreq_ctx->data.SysIPv6GWAddr_len* sizeof(rowreq_ctx->data.SysIPv6GWAddr[0]) );

    return MFD_SUCCESS;
} /* SysIPv6GWAddr_get */



/** @} */
