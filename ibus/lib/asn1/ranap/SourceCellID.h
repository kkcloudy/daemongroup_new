/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_SourceCellID_H_
#define	_SourceCellID_H_


#include <asn_application.h>

/* Including external dependencies */
#include "SourceUTRANCellID.h"
#include "CGI.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SourceCellID_PR {
	SourceCellID_PR_NOTHING,	/* No components present */
	SourceCellID_PR_sourceUTRANCellID,
	SourceCellID_PR_sourceGERANCellID,
	/* Extensions may appear below */
	
} SourceCellID_PR;

/* SourceCellID */
typedef struct SourceCellID {
	SourceCellID_PR present;
	union SourceCellID_u {
		SourceUTRANCellID_t	 sourceUTRANCellID;
		CGI_t	 sourceGERANCellID;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SourceCellID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SourceCellID;

#ifdef __cplusplus
}
#endif

#endif	/* _SourceCellID_H_ */
#include <asn_internal.h>
