/*
 * Generated by asn1c-0.9.23 (http://lionet.info/asn1c)
 * From ASN.1 module "RANAP-IEs"
 * 	found in "RANAP-IEs.asn"
 */

#ifndef	_EncryptionKey_H_
#define	_EncryptionKey_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* EncryptionKey */
typedef BIT_STRING_t	 EncryptionKey_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_EncryptionKey;
asn_struct_free_f EncryptionKey_free;
asn_struct_print_f EncryptionKey_print;
asn_constr_check_f EncryptionKey_constraint;
ber_type_decoder_f EncryptionKey_decode_ber;
der_type_encoder_f EncryptionKey_encode_der;
xer_type_decoder_f EncryptionKey_decode_xer;
xer_type_encoder_f EncryptionKey_encode_xer;
per_type_decoder_f EncryptionKey_decode_uper;
per_type_encoder_f EncryptionKey_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _EncryptionKey_H_ */
#include <asn_internal.h>
