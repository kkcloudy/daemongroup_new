/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-PDU-Contents"
 * 	found in "RANAP-PDU-Contents.asn"
 */

#ifndef	_RAB_SetupOrModifyItemFirst_H_
#define	_RAB_SetupOrModifyItemFirst_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RAB-ID.h"
#include "NAS-SynchronisationIndicator.h"
#include "Service-Handover.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RAB_Parameters;
struct UserPlaneInformation;
struct TransportLayerInformation;
/* auto changed by perl script */
/*struct ;*/

/* RAB-SetupOrModifyItemFirst */
typedef struct RAB_SetupOrModifyItemFirst {
	RAB_ID_t	 rAB_ID;
/* auto changed by perl script */
	NAS_SynchronisationIndicator_t	*nAS_SynchronisationIndicator;	/* OPTIONAL */
/* auto changed by perl script */
	struct RAB_Parameters	*rAB_Parameters;	/* OPTIONAL */
/* auto changed by perl script */
	struct UserPlaneInformation	*userPlaneInformation;	/* OPTIONAL */
/* auto changed by perl script */
	struct TransportLayerInformation	*transportLayerInformation;	/* OPTIONAL */
/* auto changed by perl script */
	Service_Handover_t	*service_Handover;	/* OPTIONAL */
/* auto changed by perl script */
	struct 	 ProtocolExtensionContainer_209P0 *iE_Extensions ;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RAB_SetupOrModifyItemFirst_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RAB_SetupOrModifyItemFirst;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RAB-Parameters.h"
#include "UserPlaneInformation.h"
#include "TransportLayerInformation.h"
#include "ProtocolExtensionContainer.h"

#endif	/* _RAB_SetupOrModifyItemFirst_H_ */
#include <asn_internal.h>
