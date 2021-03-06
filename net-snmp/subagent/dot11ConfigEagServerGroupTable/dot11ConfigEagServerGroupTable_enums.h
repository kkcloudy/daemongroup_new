/*
 * Note: this file originally auto-generated by mib2c using
 *  : generic-table-enums.m2c,v 1.3 2004/05/18 17:44:32 rstory Exp $
 *
 * $Id:$
 */
#ifndef DOT11CONFIGEAGSERVERGROUPTABLE_ENUMS_H
#define DOT11CONFIGEAGSERVERGROUPTABLE_ENUMS_H

#ifdef __cplusplus
extern "C" {
#endif

 /*
 * NOTES on enums
 * ==============
 *
 * Value Mapping
 * -------------
 * If the values for your data type don't exactly match the
 * possible values defined by the mib, you should map them
 * below. For example, a boolean flag (1/0) is usually represented
 * as a TruthValue in a MIB, which maps to the values (1/2).
 *
 */
/*************************************************************************
 *************************************************************************
 *
 * enum definitions for table dot11ConfigEagServerGroupTable
 *
 *************************************************************************
 *************************************************************************/

/*************************************************************
 * constants for enums for the MIB node
 * EagEnable (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef EAGENABLE_ENUMS
#define EAGENABLE_ENUMS

#define EAGENABLE_TRUE  1 
#define EAGENABLE_FALSE  2 


#endif /* EAGENABLE_ENUMS */

    /*
     * TODO:140:o: Define interal representation of EagEnable enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_EAGENABLE_TRUE  1 
#define INTERNAL_EAGENABLE_FALSE  2 

/*************************************************************
 * constants for enums for the MIB node
 * IdleTimeFunction (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef IDLETIMEFUNCTION_ENUMS
#define IDLETIMEFUNCTION_ENUMS

#define IDLETIMEFUNCTION_TRUE  1 
#define IDLETIMEFUNCTION_FALSE  2 


#endif /* IDLETIMEFUNCTION_ENUMS */

    /*
     * TODO:140:o: Define interal representation of IdleTimeFunction enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_IDLETIMEFUNCTION_TRUE  1 
#define INTERNAL_IDLETIMEFUNCTION_FALSE  2 

/*************************************************************
 * constants for enums for the MIB node
 * DebugLog (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef DEBUGLOG_ENUMS
#define DEBUGLOG_ENUMS

#define DEBUGLOG_TRUE  1 
#define DEBUGLOG_FALSE  2 


#endif /* DEBUGLOG_ENUMS */

    /*
     * TODO:140:o: Define interal representation of DebugLog enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_DEBUGLOG_TRUE  1 
#define INTERNAL_DEBUGLOG_FALSE  2 

/*************************************************************
 * constants for enums for the MIB node
 * JustAllowWirelessUserLogin (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef JUSTALLOWWIRELESSUSERLOGIN_ENUMS
#define JUSTALLOWWIRELESSUSERLOGIN_ENUMS

#define JUSTALLOWWIRELESSUSERLOGIN_TRUE  1 
#define JUSTALLOWWIRELESSUSERLOGIN_FALSE  2 


#endif /* JUSTALLOWWIRELESSUSERLOGIN_ENUMS */

    /*
     * TODO:140:o: Define interal representation of JustAllowWirelessUserLogin enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_JUSTALLOWWIRELESSUSERLOGIN_TRUE  1 
#define INTERNAL_JUSTALLOWWIRELESSUSERLOGIN_FALSE  2 

/*************************************************************
 * constants for enums for the MIB node
 * AutoCreateUserSession (INTEGER / ASN_INTEGER)
 *
 * since a Textual Convention may be referenced more than once in a
 * MIB, protect againt redefinitions of the enum values.
 */
#ifndef AUTOCREATEUSERSESSION_ENUMS
#define AUTOCREATEUSERSESSION_ENUMS

#define AUTOCREATEUSERSESSION_TRUE  1 
#define AUTOCREATEUSERSESSION_FALSE  2 


#endif /* AUTOCREATEUSERSESSION_ENUMS */

    /*
     * TODO:140:o: Define interal representation of AutoCreateUserSession enums.
     * (used for value mapping; see notes at top of file)
     */
#define INTERNAL_AUTOCREATEUSERSESSION_TRUE  1 
#define INTERNAL_AUTOCREATEUSERSESSION_FALSE  2 



#ifdef __cplusplus
}
#endif

#endif /* DOT11CONFIGEAGSERVERGROUPTABLE_ENUMS_H */
