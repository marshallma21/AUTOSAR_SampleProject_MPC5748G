/**
* @file    Port_PBcfg.c
* @implements Port_PBcfg.c_Artifact
*
* @version 1.0.0
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver postbuild configuration.
*
* @addtogroup  Port
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : SIUL2
*   Dependencies         : none
*
*   Autosar Version      : 4.2.2
*   Autosar Revision     : ASR_REL_4_2_REV_0002
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217
*
*   (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
*   All Rights Reserved.
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_PBCFG_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before #include'. 
* Port_MemMap.h.h is included after each section define in order to set the current memory section as defined by AUTOSAR.
*
* @section PORT_PBCFG_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of Port_MemMap.h.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_PBCFG_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers. 
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_PBCFG_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or 
* functions at file scope shall have internal linkage unless external linkage is required. 
* This warning appears when defining functions or objects that will be used by the upper layers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port.h"


/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*
*/
#define PORT_VENDOR_ID_PBCFG_C                       43
/*
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C        4
/*
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
#define PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C        2

/** @violates @ref PORT_PBCFG_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*   ensure that 31 character significance and case sensitivity are supported for external
*   identifiers.
*/
#define PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C     2
#define PORT_SW_MAJOR_VERSION_PBCFG_C                1
#define PORT_SW_MINOR_VERSION_PBCFG_C                0
#define PORT_SW_PATCH_VERSION_PBCFG_C                0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_PBcfg.c and Port.h are of the same vendor */
#if (PORT_VENDOR_ID_PBCFG_C != PORT_VENDOR_ID)
    #error "Port_PBcfg.c and Port.h have different vendor ids"
#endif
/* Check if Port_PBcfg.c and Port.h are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MAJOR_VERSION) || \
     (PORT_AR_RELEASE_MINOR_VERSION_PBCFG_C    != PORT_AR_RELEASE_MINOR_VERSION) || \
     (PORT_AR_RELEASE_REVISION_VERSION_PBCFG_C != PORT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Port_PBcfg.c and Port.h are different"
#endif

/* Check if Port_PBcfg.c and Port.h are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_PBCFG_C != PORT_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_PBCFG_C != PORT_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_PBCFG_C != PORT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Port_PBcfg.c and Port.h are different"
#endif

/*=================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL MACROS
=================================================================================================*/


/*=================================================================================================
*                                      LOCAL CONSTANTS
=================================================================================================*/
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)

#define PORT_START_SEC_CONFIG_DATA_16

/* @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before '#include' */
/* @violates @ref PORT_PBCFG_REF_2 Repeated include file MemMap.h */
#include "Port_MemMap.h"

/**
* @brief NoDefaultPadsArray is an array containing Unimplemented pads and User pads
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
static CONST(uint16, PORT_CONST) Port_au16NoUnUsedPadsArrayDefault[PORT_MAX_UNUSED_PADS_U16]=
{
    (uint16)0,
    (uint16)1,
    (uint16)2,
    (uint16)4,
    (uint16)5,
    (uint16)6,
    (uint16)8,
    (uint16)9,
    (uint16)11,
    (uint16)12,
    (uint16)13,
    (uint16)14,
    (uint16)15,
    (uint16)16,
    (uint16)17,
    (uint16)18,
    (uint16)19,
    (uint16)20,
    (uint16)21,
    (uint16)22,
    (uint16)23,
    (uint16)24,
    (uint16)25,
    (uint16)26,
    (uint16)27,
    (uint16)28,
    (uint16)29,
    (uint16)30,
    (uint16)31,
    (uint16)34,
    (uint16)35,
    (uint16)36,
    (uint16)37,
    (uint16)38,
    (uint16)39,
    (uint16)40,
    (uint16)41,
    (uint16)42,
    (uint16)43,
    (uint16)44,
    (uint16)45,
    (uint16)46,
    (uint16)47,
    (uint16)48,
    (uint16)49,
    (uint16)50,
    (uint16)51,
    (uint16)52,
    (uint16)53,
    (uint16)54,
    (uint16)55,
    (uint16)56,
    (uint16)57,
    (uint16)58,
    (uint16)59,
    (uint16)60,
    (uint16)61,
    (uint16)62,
    (uint16)63,
    (uint16)64,
    (uint16)65,
    (uint16)66,
    (uint16)67,
    (uint16)68,
    (uint16)69,
    (uint16)70,
    (uint16)71,
    (uint16)72,
    (uint16)73,
    (uint16)74,
    (uint16)75,
    (uint16)77,
    (uint16)78,
    (uint16)79,
    (uint16)80,
    (uint16)81,
    (uint16)82,
    (uint16)83,
    (uint16)84,
    (uint16)85,
    (uint16)86,
    (uint16)87,
    (uint16)88,
    (uint16)89,
    (uint16)90,
    (uint16)91,
    (uint16)92,
    (uint16)93,
    (uint16)94,
    (uint16)95,
    (uint16)96,
    (uint16)97,
    (uint16)98,
    (uint16)99,
    (uint16)100,
    (uint16)101,
    (uint16)102,
    (uint16)103,
    (uint16)104,
    (uint16)105,
    (uint16)106,
    (uint16)107,
    (uint16)108,
    (uint16)109,
    (uint16)110,
    (uint16)111,
    (uint16)112,
    (uint16)113,
    (uint16)114,
    (uint16)115,
    (uint16)116,
    (uint16)117,
    (uint16)118,
    (uint16)119,
    (uint16)120,
    (uint16)123,
    (uint16)124,
    (uint16)125,
    (uint16)126,
    (uint16)127,
    (uint16)128,
    (uint16)129,
    (uint16)130,
    (uint16)131,
    (uint16)132,
    (uint16)133,
    (uint16)134,
    (uint16)135,
    (uint16)136,
    (uint16)137,
    (uint16)138,
    (uint16)139,
    (uint16)140,
    (uint16)141,
    (uint16)142,
    (uint16)143,
    (uint16)144,
    (uint16)145,
    (uint16)146,
    (uint16)147,
    (uint16)148,
    (uint16)149,
    (uint16)150,
    (uint16)151,
    (uint16)152,
    (uint16)153,
    (uint16)154,
    (uint16)155,
    (uint16)156,
    (uint16)157,
    (uint16)158,
    (uint16)159,
    (uint16)160,
    (uint16)161,
    (uint16)162,
    (uint16)163,
    (uint16)164,
    (uint16)165,
    (uint16)166,
    (uint16)167,
    (uint16)168,
    (uint16)169,
    (uint16)170,
    (uint16)171,
    (uint16)172,
    (uint16)173,
    (uint16)174,
    (uint16)175,
    (uint16)176,
    (uint16)177,
    (uint16)178,
    (uint16)179,
    (uint16)180,
    (uint16)181,
    (uint16)182,
    (uint16)183,
    (uint16)184,
    (uint16)185,
    (uint16)186,
    (uint16)187,
    (uint16)188,
    (uint16)189,
    (uint16)190,
    (uint16)191,
    (uint16)192,
    (uint16)193,
    (uint16)194,
    (uint16)195,
    (uint16)196,
    (uint16)197,
    (uint16)198,
    (uint16)199,
    (uint16)200,
    (uint16)201,
    (uint16)202,
    (uint16)203,
    (uint16)204,
    (uint16)205,
    (uint16)206,
    (uint16)207,
    (uint16)208,
    (uint16)209,
    (uint16)210,
    (uint16)211,
    (uint16)212,
    (uint16)213,
    (uint16)214,
    (uint16)215,
    (uint16)216,
    (uint16)217,
    (uint16)218,
    (uint16)219,
    (uint16)220,
    (uint16)221,
    (uint16)222,
    (uint16)223,
    (uint16)224,
    (uint16)225,
    (uint16)226,
    (uint16)227,
    (uint16)228,
    (uint16)229,
    (uint16)230,
    (uint16)231,
    (uint16)232,
    (uint16)233,
    (uint16)234,
    (uint16)235,
    (uint16)236,
    (uint16)237,
    (uint16)238,
    (uint16)239,
    (uint16)240,
    (uint16)241,
    (uint16)242,
    (uint16)243,
    (uint16)244,
    (uint16)245,
    (uint16)246,
    (uint16)247,
    (uint16)248,
    (uint16)249,
    (uint16)250,
    (uint16)251,
    (uint16)252,
    (uint16)253,
    (uint16)254,
    (uint16)255,
    (uint16)256,
    (uint16)257,
    (uint16)258,
    (uint16)259,
    (uint16)260,
    (uint16)261,
    (uint16)262,
    (uint16)263
};

#define PORT_STOP_SEC_CONFIG_DATA_16

/* @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before '#include' */
/* @violates @ref PORT_PBCFG_REF_2 Repeated include file MemMap.h */
#include "Port_MemMap.h"

#endif /* (PORT_MAX_UNUSED_PADS_U16 != 0) */


#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED

/* @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before '#include' */
/* @violates @ref PORT_PBCFG_REF_2 Repeated include file MemMap.h */
#include "Port_MemMap.h"

/**
 * @brief Default Configuration for Pins not initialized
 */
static CONST(Port_Siul2_UnUsedPinConfigType, PORT_CONST) Port_UnUsedPin =
{
    /**
    * @note: Configuration of Default pin
    */
    (uint32)0x00080000, (uint8)0
    
};

/**
* @brief Pin default configuration data for configPB
*/
static CONST(Port_Siul2_PinConfigType, PORT_CONST) Port_aPinConfigDefault[PORT_MAX_CONFIGURED_PADS_U16]=
{
    {(Port_InternalPinIdType)10, (uint32)0x02000000, (uint8)0, (uint8)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)7, (uint32)0x02000000, (uint8)0, (uint8)1, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)76, (uint32)0x00080000, (uint8)0, (uint8)0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)3, (uint32)0x00080000, (uint8)0, (uint8)0, (boolean)TRUE, (boolean)TRUE, (boolean)TRUE},
    {(Port_InternalPinIdType)121, (uint32)0x00080001, (uint8)0, (uint8)0, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)32, (uint32)0x00080001, (uint8)0, (uint8)0, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)33, (uint32)0x00000001, (uint8)0, (uint8)1, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE},
    {(Port_InternalPinIdType)122, (uint32)0x02080001, (uint8)0, (uint8)0, (boolean)FALSE, (boolean)FALSE, (boolean)TRUE}
};

/**
* @brief Pad selection default configuration for configPB
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
static CONST(Port_Siul2_PadSelConfigType, PORT_CONST) Port_aPadSelConfigDefault[PORT_NMBR_INMUX_REGS_U16]=
{
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000,
    (uint32)0x00000000
    
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_PBCFG_REF_2 Repeated include file MemMap.h
*/
#include "Port_MemMap.h"

/*=================================================================================================
*                                      LOCAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                      GLOBAL CONSTANTS
=================================================================================================*/
#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_PBCFG_REF_2 Repeated include file MemMap.h
*/
#include "Port_MemMap.h"

/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
* @violates @ref PORT_PBCFG_REF_4 Violates MISRA 2004 Required Rule 8.10
*/

CONST(Port_ConfigType, PORT_CONST) PortConfigSet =

{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)
    Port_au16NoUnUsedPadsArrayDefault,
#else
    NULL_PTR,
#endif
    &Port_UnUsedPin,
    Port_aPinConfigDefault,
    Port_aPadSelConfigDefault
};

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before '#include'
* @violates @ref PORT_PBCFG_REF_2 Repeated include file MemMap.h
*/
#include "Port_MemMap.h"

/*=================================================================================================
*                                      GLOBAL VARIABLES
=================================================================================================*/


/*=================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
=================================================================================================*/


/*=================================================================================================
*                                       LOCAL FUNCTIONS
=================================================================================================*/


/*=================================================================================================
*                                       GLOBAL FUNCTIONS
=================================================================================================*/

#ifdef __cplusplus
}
#endif
/** @} */

/* End of File */
