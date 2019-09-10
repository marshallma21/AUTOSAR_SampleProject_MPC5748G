[!CODE!][!//
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

[!NOCODE!][!//
[!INCLUDE "Port_VersionCheck_Src_PB.m"!][!//
[!/* Include package file in order to get valid Pins */!][!//
[!IF "((ecu:get('PortCalypsoFamily'))='3')"!][!//
    [!INCLUDE "Calypso_Resource_3M.m"!][!//
[!ELSE!][!//
    [!INCLUDE "Calypso_Resource_6M.m"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//

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
[!NOCODE!][!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetAltConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetAltConf"!][!//
[!NOCODE!][!//
[!/* Alternative Mode 0 is the GPIO */!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "OutPinAltConf"="0"!]
[!ELSE!][!//
    [!VAR "MacPinMode"="concat(./PortPinMode,'_PORT',number(./PortPinPcr))"!][!//
    [!VAR "OutPinAltConf"="number(substring-after(substring-before((substring-after($PinMap,$MacPinMode)),':'),';'))"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetMSCR                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the selected pin */!][!//
[!MACRO "GetMSCR"!][!//
[!NOCODE!][!//
[!VAR "MacPinMSCR"="num:i(0)"!][!//
[!/* Get the Alternative Mode configuration and fill the PCR */!][!//
[!CALL "GetAltConf"!][!//
[!/* Check if pin is in analog mode */!][!//
[!IF "($OutPinAltConf = 10)"!][!//
    [!/* Pin is in analog mode. Set APC  */!][!//
    [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,22))"!][!//
[!ELSE!]
    [!IF "($OutPinAltConf >= 17)"!][!//
        [!/* Pin is input/output */!][!//
        [!/* Set first output params: SSS field in MSCR, OBE and Safe Mode */!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl($OutPinAltConf - 16,0))"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,25))"!][!//
        [!IF "./PortPinSafeMode"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,23))"!][!//
        [!ENDIF!][!//
        [!/* Set then input params: IBE */!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,19))"!][!//
    [!ELSEIF "($OutPinAltConf >= 8)"!][!//
        [!/* Check if pin is in output only mode */!][!//
        [!IF "($OutPinAltConf = 8)"!]
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,25))"!][!//
            [!IF "./PortPinSafeMode"!][!//
                [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,23))"!][!//
            [!ENDIF!][!//
        [!ELSE!]
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,19))"!][!//
        [!ENDIF!]
    [!ELSEIF "($OutPinAltConf > 0)"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl($OutPinAltConf,0))"!][!//
        [!IF "num:i(./PortPinPcr)=32 or num:i(./PortPinPcr)=121"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,19))"!][!//
        [!ENDIF!]
        [!IF "./PortPinSafeMode"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,23))"!][!//
        [!ENDIF!][!//
    [!ELSE!][!//
        [!/* Pin is GPIO */!][!//
        [!/* Check if the pin is configured as input or output */!][!//
        [!IF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,25))"!][!//
            [!/* Check if safe mode control is enabled */!][!//
            [!IF "./PortPinSafeMode"!][!//
                [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,23))"!][!//
            [!ENDIF!][!//
        [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_INOUT')"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,25))"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,19))"!][!//
            [!/* Check if safe mode control is enabled */!][!//
            [!IF "./PortPinSafeMode"!][!//
                [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,23))"!][!//
            [!ENDIF!][!//
        [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
            [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,19))"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//

    [!/* Check if open drain output is enabled. ODE has EDITABLE = true for all pins except ADC ones. But here, we are dealing with a non ADC pad */!][!//
    [!IF "./PortPinOde"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,24))"!][!//
    [!ENDIF!][!//

    [!/* Check what type of output slew rate is set */!][!// 
    [!IF "text:match(./PortPinSlewRate,'HalfDriveWithSlewRate')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,28))"!][!//
    [!ELSEIF "text:match(./PortPinSlewRate,'FullDriveWithSlewRate')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,28))"!][!//
    [!ELSEIF "text:match(./PortPinSlewRate,'HalfDriveWithoutSlewRate')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(2,28))"!][!//
    [!ELSEIF "text:match(./PortPinSlewRate,'FullDriveWithoutSlewRate')"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(3,28))"!][!//
    [!ENDIF!][!//

    [!/* Check if open hysteresis is enabled. PortPinHysteresisControl has EDITABLE = true for all pins except ADC ones. But here, we are dealing with a non ADC pad */!][!//
    [!IF "./PortPinHysteresisControl"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,18))"!][!//
    [!ELSE!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(0,18))"!][!//
    [!ENDIF!][!//

    [!/* Check if weak pull up/down is enabled. Wpe has EDITABLE = true for all pins except ADC ones. But here, we are dealing with a non ADC pad */!][!//
    [!IF "./PortPinWpe"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,16))"!][!//
    [!ENDIF!][!//

    [!/* Check whether weak pull-up or weak pull-down is selected. Wps has EDITABLE = true for all pins except ADC ones. But here, we are dealing with a non ADC pad */!][!//
    [!IF "./PortPinWps"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,17))"!][!//
    [!ENDIF!][!//

    [!/* Check if read status is enabled. PortPinWithReadBack has EDITABLE = true for all pins except ADC ones. But here, we are dealing with a non ADC pad */!][!//
    [!IF "./PortPinWithReadBack"!][!//
        [!VAR "MacPinMSCR"="bit:or($MacPinMSCR,bit:shl(1,19))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"num:inttohex($MacPinMSCR,8)"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetUnusedMSCR                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Fill the MSCR register for the unused pins */!][!//
[!MACRO "GetUnusedMSCR"!][!//
[!NOCODE!][!//
[!VAR "MacConfigREG"="num:i(0)"!][!//
[!/* Get the Alternative Mode configuration and fill the Config Register */!][!//
[!CALL "GetAltConf"!][!//
[!/* Check if the pin is configured as input or output */!][!//
[!IF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,25))"!][!//
[!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,19))"!][!//
[!ENDIF!][!//

[!/* Check if open drain output is enabled */!][!//
[!IF "./PortPinOde"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,24))"!][!//
[!ENDIF!][!//

[!/* Check if weak pull up/down is enabled */!][!//
[!IF "./PortPinWpe"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,16))"!][!//
[!ENDIF!][!//

[!/* Check whether weak pull-up or weak pull-down is selected */!][!//
[!IF "./PortPinWps"!][!//
    [!VAR "MacConfigREG"="bit:or($MacConfigREG,bit:shl(1,17))"!][!//
[!ENDIF!][!//

[!ENDNOCODE!][!//
[!"num:inttohex($MacConfigREG,8)"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDO                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the output status for selected pin */!][!//
[!MACRO "GetPDO"!][!//
[!NOCODE!][!//
[!IF "not((contains(node:fallback(./PortPinMode,'ADC'),'ADC') and (not(contains(node:fallback(./PortPinMode,'MA'),'MA')))) or (contains(node:fallback(./PortPinMode,'CMP'),'CMP') and (not(contains(node:fallback(./PortPinMode,'_O'),'_O')))))"!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_LOW')"!][!//
        [!VAR "MacPinPDO"="num:i(0)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_HIGH')"!][!//
        [!VAR "MacPinPDO"="num:i(1)"!][!//
    [!ENDIF!][!//
    [!IF "text:match(./PortPinLevelValue,'PORT_PIN_LEVEL_NOTCHANGED')"!][!//
        [!VAR "MacPinPDO"="num:i(2)"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacPinPDO"="num:i(2)"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDO"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                            MACRO GetPDDir                                   */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the direction to be set for selected pin */!][!//
[!MACRO "GetPDDir"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'ADC')"!][!//
    [!VAR "MacPinPDDir"="num:i(0)"!][!//
[!ELSE!][!//
    [!/* Test to 'PORT_PIN_INOUT' should be done first, as 'PORT_PIN_INOUT' string contains 'PORT_PIN_IN' string */!][!//
    [!IF "text:match(./PortPinDirection,'PORT_PIN_INOUT')"!][!//
        [!VAR "MacPinPDDir"="num:i(2)"!][!//
    [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_IN')"!][!//
        [!VAR "MacPinPDDir"="num:i(0)"!][!//
    [!ELSEIF "text:match(./PortPinDirection,'PORT_PIN_OUT')"!][!//
        [!VAR "MacPinPDDir"="num:i(1)"!][!//
    [!ELSE!]
        [!/*do nothing*/!]
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacPinPDDir"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetGPIO                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Set the initial GPIO Mode for selected pin */!][!//
[!MACRO "GetGPIO"!][!//
[!NOCODE!][!//
[!IF "text:match(./PortPinMode,'GPIO')"!][!//
    [!VAR "MacGPIOMode"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "MacGPIOMode"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacGPIOMode"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetDirConf                                 */!][!//
[!/*****************************************************************************/!][!//
[!/* Get the Alternative Mode configuration for selected pin */!][!//
[!MACRO "GetDirConf"!][!//
[!NOCODE!][!//
[!IF "(./PortPinMode = 'GPIO')"!][!//
    [!IF "./PortPinDirectionChangeable"!][!//
        [!VAR "MacDirection"= "string('(boolean)TRUE')"!][!//
    [!ELSE!][!//
        [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
    [!ENDIF!][!//
[!ELSE!][!//
    [!VAR "MacDirection"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacDirection"!][!//
[!ENDMACRO!][!//
[!/*****************************************************************************/!][!//
[!//
[!//
[!/*****************************************************************************/!][!//
[!/*                          MACRO GetModeChang                               */!][!//
[!/*****************************************************************************/!][!//
[!MACRO "GetModeChang"!][!//
[!NOCODE!][!//
[!IF "./PortPinModeChangeable"!][!//
    [!VAR "MacModeChang"= "string('(boolean)TRUE')"!][!//
[!ELSE!][!//
    [!VAR "MacModeChang"= "string('(boolean)FALSE')"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!"$MacModeChang"!][!//
[!ENDMACRO!][!//
[!ENDNOCODE!][!//
[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
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
static CONST(uint16, PORT_CONST) Port_au16NoUnUsedPadsArrayDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_UNUSED_PADS_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "ecu:get('PortMaxPinNumber')"!][!//
    [!VAR "PinUsed"="0"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!IF "$PinUsed=0"!][!//
            [!IF "num:i(./PortPinPcr)=$x"!][!//
                [!VAR "PinUsed"="$PinUsed + 1"!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$PinUsed=0"!][!//
        [!IF "contains(concat(',',string(ecu:get('PortUnimplementedPAD')),','),concat(',',$x,','))"!][!//
            [!VAR "PinUsed"="$PinUsed + 1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!IF "$PinUsed=0"!][!//
        [!IF "$counter=0"!][!//
[!CODE!][!//
    (uint16)[!"$x"!][!//
[!ENDCODE!][!//
        [!ELSE!][!//
[!CODE!][!//
,
    (uint16)[!"$x"!][!//
[!ENDCODE!][!//
        [!ENDIF!][!//
        [!VAR "counter"= "$counter+1"!][!//
    [!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!]
};

#define PORT_STOP_SEC_CONFIG_DATA_16

/* @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before '#include' */
/* @violates @ref PORT_PBCFG_REF_2 Repeated include file MemMap.h */
#include "Port_MemMap.h"

#endif /* (PORT_MAX_UNUSED_PADS_U16 != 0) */
[!ENDSELECT!][!//


#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED

/* @violates @ref PORT_PBCFG_REF_1 only preprocessor statements and comments before '#include' */
/* @violates @ref PORT_PBCFG_REF_2 Repeated include file MemMap.h */
#include "Port_MemMap.h"

[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
 * @brief Default Configuration for Pins not initialized
 */
static CONST(Port_Siul2_UnUsedPinConfigType, PORT_CONST) Port_UnUsedPin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /**
    * @note: Configuration of Default pin
    */
    [!LOOP "NotUsedPortPin"!][!/*
        */!](uint32)[!CALL "GetUnusedMSCR"!], (uint8)[!CALL "GetPDO"!]
    [!ENDLOOP!]
};
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "count"= "1"!][!//
[!VAR "Maxcount"= "num:i(count(PortContainer/*/PortPin/*))-1"!][!//
[!VAR "LoopVar"="1"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief Pin default configuration data for configPB
*/
static CONST(Port_Siul2_PinConfigType, PORT_CONST) Port_aPinConfigDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_MAX_CONFIGURED_PADS_U16]=
{
[!NOCODE!]
[!FOR "x" = "0" TO "num:i(count(PortContainer/*/PortPin/*))"!][!//
    [!LOOP "PortContainer/*/PortPin/*"!][!//
        [!VAR "Loop"="num:i($LoopVar)"!][!//
        [!IF "PortPinId = $Loop"!][!//
            [!IF "$Maxcount>=$count"!][!//
[!CODE!][!//
    {(Port_InternalPinIdType)[!"./PortPinPcr"!], (uint32)[!CALL "GetMSCR"!], (uint8)[!CALL "GetPDO"!], (uint8)[!CALL "GetPDDir"!], [!CALL "GetGPIO"!], [!CALL "GetDirConf"!], [!CALL "GetModeChang"!]},
[!ENDCODE!][!//
            [!ELSE!][!//
[!CODE!][!//
    {(Port_InternalPinIdType)[!"./PortPinPcr"!], (uint32)[!CALL "GetMSCR"!], (uint8)[!CALL "GetPDO"!], (uint8)[!CALL "GetPDDir"!], [!CALL "GetGPIO"!], [!CALL "GetDirConf"!], [!CALL "GetModeChang"!]}
[!ENDCODE!][!//
            [!ENDIF!][!//
            [!VAR "count"= "$count+1"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
};
[!ENDSELECT!][!//

[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief Pad selection default configuration for configPB
* @violates @ref PORT_PBCFG_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers.
*/
static CONST(Port_Siul2_PadSelConfigType, PORT_CONST) Port_aPadSelConfigDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PORT_NMBR_INMUX_REGS_U16]=
{
[!NOCODE!]
[!VAR "cINMUX0"="0"!][!//
[!VAR "cINMUX1"="0"!][!//
[!VAR "cINMUX2"="0"!][!//
[!VAR "cINMUX3"="0"!][!//
[!VAR "cINMUX4"="0"!][!//
[!VAR "cINMUX5"="0"!][!//
[!VAR "cINMUX6"="0"!][!//
[!VAR "cINMUX7"="0"!][!//
[!VAR "cINMUX8"="0"!][!//
[!VAR "cINMUX9"="0"!][!//
[!VAR "cINMUX10"="0"!][!//
[!VAR "cINMUX11"="0"!][!//
[!VAR "cINMUX12"="0"!][!//
[!VAR "cINMUX13"="0"!][!//
[!VAR "cINMUX14"="0"!][!//
[!VAR "cINMUX15"="0"!][!//
[!VAR "cINMUX16"="0"!][!//
[!VAR "cINMUX17"="0"!][!//
[!VAR "cINMUX18"="0"!][!//
[!VAR "cINMUX19"="0"!][!//
[!VAR "cINMUX20"="0"!][!//
[!VAR "cINMUX21"="0"!][!//
[!VAR "cINMUX22"="0"!][!//
[!VAR "cINMUX23"="0"!][!//
[!VAR "cINMUX24"="0"!][!//
[!VAR "cINMUX25"="0"!][!//
[!VAR "cINMUX26"="0"!][!//
[!VAR "cINMUX27"="0"!][!//
[!VAR "cINMUX28"="0"!][!//
[!VAR "cINMUX29"="0"!][!//
[!VAR "cINMUX30"="0"!][!//
[!VAR "cINMUX31"="0"!][!//
[!VAR "cINMUX32"="0"!][!//
[!VAR "cINMUX33"="0"!][!//
[!VAR "cINMUX34"="0"!][!//
[!VAR "cINMUX35"="0"!][!//
[!VAR "cINMUX36"="0"!][!//
[!VAR "cINMUX37"="0"!][!//
[!VAR "cINMUX38"="0"!][!//
[!VAR "cINMUX39"="0"!][!//
[!VAR "cINMUX40"="0"!][!//
[!VAR "cINMUX41"="0"!][!//
[!VAR "cINMUX42"="0"!][!//
[!VAR "cINMUX43"="0"!][!//
[!VAR "cINMUX44"="0"!][!//
[!VAR "cINMUX45"="0"!][!//
[!VAR "cINMUX46"="0"!][!//
[!VAR "cINMUX47"="0"!][!//
[!VAR "cINMUX48"="0"!][!//
[!VAR "cINMUX49"="0"!][!//
[!VAR "cINMUX50"="0"!][!//
[!VAR "cINMUX51"="0"!][!//
[!VAR "cINMUX52"="0"!][!//
[!VAR "cINMUX53"="0"!][!//
[!VAR "cINMUX54"="0"!][!//
[!VAR "cINMUX55"="0"!][!//
[!VAR "cINMUX56"="0"!][!//
[!VAR "cINMUX57"="0"!][!//
[!VAR "cINMUX58"="0"!][!//
[!VAR "cINMUX59"="0"!][!//
[!VAR "cINMUX60"="0"!][!//
[!VAR "cINMUX61"="0"!][!//
[!VAR "cINMUX62"="0"!][!//
[!VAR "cINMUX63"="0"!][!//
[!VAR "cINMUX64"="0"!][!//
[!VAR "cINMUX65"="0"!][!//
[!VAR "cINMUX66"="0"!][!//
[!VAR "cINMUX67"="0"!][!//
[!VAR "cINMUX68"="0"!][!//
[!VAR "cINMUX69"="0"!][!//
[!VAR "cINMUX70"="0"!][!//
[!VAR "cINMUX71"="0"!][!//
[!VAR "cINMUX72"="0"!][!//
[!VAR "cINMUX73"="0"!][!//
[!VAR "cINMUX74"="0"!][!//
[!VAR "cINMUX75"="0"!][!//
[!VAR "cINMUX76"="0"!][!//
[!VAR "cINMUX77"="0"!][!//
[!VAR "cINMUX78"="0"!][!//
[!VAR "cINMUX79"="0"!][!//
[!VAR "cINMUX80"="0"!][!//
[!VAR "cINMUX81"="0"!][!//
[!VAR "cINMUX82"="0"!][!//
[!VAR "cINMUX83"="0"!][!//
[!VAR "cINMUX84"="0"!][!//
[!VAR "cINMUX85"="0"!][!//
[!VAR "cINMUX86"="0"!][!//
[!VAR "cINMUX87"="0"!][!//
[!VAR "cINMUX88"="0"!][!//
[!VAR "cINMUX89"="0"!][!//
[!VAR "cINMUX90"="0"!][!//
[!VAR "cINMUX91"="0"!][!//
[!VAR "cINMUX92"="0"!][!//
[!VAR "cINMUX93"="0"!][!//
[!VAR "cINMUX94"="0"!][!//
[!VAR "cINMUX95"="0"!][!//
[!VAR "cINMUX96"="0"!][!//
[!VAR "cINMUX97"="0"!][!//
[!VAR "cINMUX98"="0"!][!//
[!VAR "cINMUX99"="0"!][!//
[!VAR "cINMUX100"="0"!][!//
[!VAR "cINMUX101"="0"!][!//
[!VAR "cINMUX102"="0"!][!//
[!VAR "cINMUX103"="0"!][!//
[!VAR "cINMUX104"="0"!][!//
[!VAR "cINMUX105"="0"!][!//
[!VAR "cINMUX106"="0"!][!//
[!VAR "cINMUX107"="0"!][!//
[!VAR "cINMUX108"="0"!][!//
[!VAR "cINMUX109"="0"!][!//
[!VAR "cINMUX110"="0"!][!//
[!VAR "cINMUX111"="0"!][!//
[!VAR "cINMUX112"="0"!][!//
[!VAR "cINMUX113"="0"!][!//
[!VAR "cINMUX114"="0"!][!//
[!VAR "cINMUX115"="0"!][!//
[!VAR "cINMUX116"="0"!][!//
[!VAR "cINMUX117"="0"!][!//
[!VAR "cINMUX118"="0"!][!//
[!VAR "cINMUX119"="0"!][!//
[!VAR "cINMUX120"="0"!][!//
[!VAR "cINMUX121"="0"!][!//
[!VAR "cINMUX122"="0"!][!//
[!VAR "cINMUX123"="0"!][!//
[!VAR "cINMUX124"="0"!][!//
[!VAR "cINMUX125"="0"!][!//
[!VAR "cINMUX126"="0"!][!//
[!VAR "cINMUX127"="0"!][!//
[!VAR "cINMUX128"="0"!][!//
[!VAR "cINMUX129"="0"!][!//
[!VAR "cINMUX130"="0"!][!//
[!VAR "cINMUX131"="0"!][!//
[!VAR "cINMUX132"="0"!][!//
[!VAR "cINMUX133"="0"!][!//
[!VAR "cINMUX134"="0"!][!//
[!VAR "cINMUX135"="0"!][!//
[!VAR "cINMUX136"="0"!][!//
[!VAR "cINMUX137"="0"!][!//
[!VAR "cINMUX138"="0"!][!//
[!VAR "cINMUX139"="0"!][!//
[!VAR "cINMUX140"="0"!][!//
[!VAR "cINMUX141"="0"!][!//
[!VAR "cINMUX142"="0"!][!//
[!VAR "cINMUX143"="0"!][!//
[!VAR "cINMUX144"="0"!][!//
[!VAR "cINMUX145"="0"!][!//
[!VAR "cINMUX146"="0"!][!//
[!VAR "cINMUX147"="0"!][!//
[!VAR "cINMUX148"="0"!][!//
[!VAR "cINMUX149"="0"!][!//
[!VAR "cINMUX150"="0"!][!//
[!VAR "cINMUX151"="0"!][!//
[!VAR "cINMUX152"="0"!][!//
[!VAR "cINMUX153"="0"!][!//
[!VAR "cINMUX154"="0"!][!//
[!VAR "cINMUX155"="0"!][!//
[!VAR "cINMUX156"="0"!][!//
[!VAR "cINMUX157"="0"!][!//
[!VAR "cINMUX158"="0"!][!//
[!VAR "cINMUX159"="0"!][!//
[!VAR "cINMUX160"="0"!][!//
[!VAR "cINMUX161"="0"!][!//
[!VAR "cINMUX162"="0"!][!//
[!VAR "cINMUX163"="0"!][!//
[!VAR "cINMUX164"="0"!][!//
[!VAR "cINMUX165"="0"!][!//
[!VAR "cINMUX166"="0"!][!//
[!VAR "cINMUX167"="0"!][!//
[!VAR "cINMUX168"="0"!][!//
[!VAR "cINMUX169"="0"!][!//
[!VAR "cINMUX170"="0"!][!//
[!VAR "cINMUX171"="0"!][!//
[!VAR "cINMUX172"="0"!][!//
[!VAR "cINMUX173"="0"!][!//
[!VAR "cINMUX174"="0"!][!//
[!VAR "cINMUX175"="0"!][!//
[!VAR "cINMUX176"="0"!][!//
[!VAR "cINMUX177"="0"!][!//
[!VAR "cINMUX178"="0"!][!//
[!VAR "cINMUX179"="0"!][!//
[!VAR "cINMUX180"="0"!][!//
[!VAR "cINMUX181"="0"!][!//
[!VAR "cINMUX182"="0"!][!//
[!VAR "cINMUX183"="0"!][!//
[!VAR "cINMUX184"="0"!][!//
[!VAR "cINMUX185"="0"!][!//
[!VAR "cINMUX186"="0"!][!//
[!VAR "cINMUX187"="0"!][!//
[!VAR "cINMUX188"="0"!][!//
[!VAR "cINMUX189"="0"!][!//
[!VAR "cINMUX190"="0"!][!//
[!VAR "cINMUX191"="0"!][!//
[!VAR "cINMUX192"="0"!][!//
[!VAR "cINMUX193"="0"!][!//
[!VAR "cINMUX194"="0"!][!//
[!VAR "cINMUX195"="0"!][!//
[!VAR "cINMUX196"="0"!][!//
[!VAR "cINMUX197"="0"!][!//
[!VAR "cINMUX198"="0"!][!//
[!VAR "cINMUX199"="0"!][!//
[!VAR "cINMUX200"="0"!][!//
[!VAR "cINMUX201"="0"!][!//
[!VAR "cINMUX202"="0"!][!//
[!VAR "cINMUX203"="0"!][!//
[!VAR "cINMUX204"="0"!][!//
[!VAR "cINMUX205"="0"!][!//
[!VAR "cINMUX206"="0"!][!//
[!VAR "cINMUX207"="0"!][!//
[!VAR "cINMUX208"="0"!][!//
[!VAR "cINMUX209"="0"!][!//
[!VAR "cINMUX210"="0"!][!//
[!VAR "cINMUX211"="0"!][!//
[!VAR "cINMUX212"="0"!][!//
[!VAR "cINMUX213"="0"!][!//
[!VAR "cINMUX214"="0"!][!//
[!VAR "cINMUX215"="0"!][!//
[!VAR "cINMUX216"="0"!][!//
[!VAR "cINMUX217"="0"!][!//
[!VAR "cINMUX218"="0"!][!//
[!VAR "cINMUX219"="0"!][!//
[!VAR "cINMUX220"="0"!][!//
[!VAR "cINMUX221"="0"!][!//
[!VAR "cINMUX222"="0"!][!//
[!VAR "cINMUX223"="0"!][!//
[!VAR "cINMUX224"="0"!][!//
[!VAR "cINMUX225"="0"!][!//
[!VAR "cINMUX226"="0"!][!//
[!VAR "cINMUX227"="0"!][!//
[!VAR "cINMUX228"="0"!][!//
[!VAR "cINMUX229"="0"!][!//
[!VAR "cINMUX230"="0"!][!//
[!VAR "cINMUX231"="0"!][!//
[!VAR "cINMUX232"="0"!][!//
[!VAR "cINMUX233"="0"!][!//
[!VAR "cINMUX234"="0"!][!//
[!VAR "cINMUX235"="0"!][!//
[!VAR "cINMUX236"="0"!][!//
[!VAR "cINMUX237"="0"!][!//
[!VAR "cINMUX238"="0"!][!//
[!VAR "cINMUX239"="0"!][!//
[!VAR "cINMUX240"="0"!][!//
[!VAR "cINMUX241"="0"!][!//
[!VAR "cINMUX242"="0"!][!//
[!VAR "cINMUX243"="0"!][!//
[!VAR "cINMUX244"="0"!][!//
[!VAR "cINMUX245"="0"!][!//
[!VAR "cINMUX246"="0"!][!//
[!VAR "cINMUX247"="0"!][!//
[!VAR "cINMUX248"="0"!][!//
[!VAR "cINMUX249"="0"!][!//
[!VAR "cINMUX250"="0"!][!//
[!VAR "cINMUX251"="0"!][!//
[!VAR "cINMUX252"="0"!][!//
[!VAR "cINMUX253"="0"!][!//
[!VAR "cINMUX254"="0"!][!//
[!VAR "cINMUX255"="0"!][!//
[!VAR "cINMUX256"="0"!][!//
[!VAR "cINMUX257"="0"!][!//
[!VAR "cINMUX258"="0"!][!//
[!VAR "cINMUX259"="0"!][!//
[!VAR "cINMUX260"="0"!][!//
[!VAR "cINMUX261"="0"!][!//
[!VAR "cINMUX262"="0"!][!//
[!VAR "cINMUX263"="0"!][!//
[!VAR "cINMUX264"="0"!][!//
[!VAR "cINMUX265"="0"!][!//
[!VAR "cINMUX266"="0"!][!//
[!VAR "cINMUX267"="0"!][!//
[!VAR "cINMUX268"="0"!][!//
[!VAR "cINMUX269"="0"!][!//
[!VAR "cINMUX270"="0"!][!//
[!VAR "cINMUX271"="0"!][!//
[!VAR "cINMUX272"="0"!][!//
[!VAR "cINMUX273"="0"!][!//
[!VAR "cINMUX274"="0"!][!//
[!VAR "cINMUX275"="0"!][!//
[!VAR "cINMUX276"="0"!][!//
[!VAR "cINMUX277"="0"!][!//
[!VAR "cINMUX278"="0"!][!//
[!VAR "cINMUX279"="0"!][!//
[!VAR "cINMUX280"="0"!][!//
[!VAR "cINMUX281"="0"!][!//
[!VAR "cINMUX282"="0"!][!//
[!VAR "cINMUX283"="0"!][!//
[!VAR "cINMUX284"="0"!][!//
[!VAR "cINMUX285"="0"!][!//
[!VAR "cINMUX286"="0"!][!//
[!VAR "cINMUX287"="0"!][!//
[!VAR "cINMUX288"="0"!][!//
[!VAR "cINMUX289"="0"!][!//
[!VAR "cINMUX290"="0"!][!//
[!VAR "cINMUX291"="0"!][!//
[!VAR "cINMUX292"="0"!][!//
[!VAR "cINMUX293"="0"!][!//
[!VAR "cINMUX294"="0"!][!//
[!VAR "cINMUX295"="0"!][!//
[!VAR "cINMUX296"="0"!][!//
[!VAR "cINMUX297"="0"!][!//
[!VAR "cINMUX298"="0"!][!//
[!VAR "cINMUX299"="0"!][!//
[!VAR "cINMUX300"="0"!][!//
[!VAR "cINMUX301"="0"!][!//
[!VAR "cINMUX302"="0"!][!//
[!VAR "cINMUX303"="0"!][!//
[!VAR "cINMUX304"="0"!][!//
[!VAR "cINMUX305"="0"!][!//
[!VAR "cINMUX306"="0"!][!//
[!VAR "cINMUX307"="0"!][!//
[!VAR "cINMUX308"="0"!][!//
[!VAR "cINMUX309"="0"!][!//
[!VAR "cINMUX310"="0"!][!//
[!VAR "cINMUX311"="0"!][!//
[!VAR "cINMUX312"="0"!][!//
[!VAR "cINMUX313"="0"!][!//
[!VAR "cINMUX314"="0"!][!//
[!VAR "cINMUX315"="0"!][!//
[!VAR "cINMUX316"="0"!][!//
[!VAR "cINMUX317"="0"!][!//
[!VAR "cINMUX318"="0"!][!//
[!VAR "cINMUX319"="0"!][!//
[!VAR "cINMUX320"="0"!][!//
[!VAR "cINMUX321"="0"!][!//
[!VAR "cINMUX322"="0"!][!//
[!VAR "cINMUX323"="0"!][!//
[!VAR "cINMUX324"="0"!][!//
[!VAR "cINMUX325"="0"!][!//
[!VAR "cINMUX326"="0"!][!//
[!VAR "cINMUX327"="0"!][!//
[!VAR "cINMUX328"="0"!][!//
[!VAR "cINMUX329"="0"!][!//
[!VAR "cINMUX330"="0"!][!//
[!VAR "cINMUX331"="0"!][!//
[!VAR "cINMUX332"="0"!][!//
[!VAR "cINMUX333"="0"!][!//
[!VAR "cINMUX334"="0"!][!//
[!VAR "cINMUX335"="0"!][!//
[!VAR "cINMUX336"="0"!][!//
[!VAR "cINMUX337"="0"!][!//
[!VAR "cINMUX338"="0"!][!//
[!VAR "cINMUX339"="0"!][!//
[!VAR "cINMUX340"="0"!][!//
[!VAR "cINMUX341"="0"!][!//
[!VAR "cINMUX342"="0"!][!//
[!VAR "cINMUX343"="0"!][!//
[!VAR "cINMUX344"="0"!][!//
[!VAR "cINMUX345"="0"!][!//
[!VAR "cINMUX346"="0"!][!//
[!VAR "cINMUX347"="0"!][!//
[!VAR "cINMUX348"="0"!][!//
[!VAR "cINMUX349"="0"!][!//
[!VAR "cINMUX350"="0"!][!//
[!VAR "cINMUX351"="0"!][!//
[!VAR "cINMUX352"="0"!][!//
[!VAR "cINMUX353"="0"!][!//
[!VAR "cINMUX354"="0"!][!//
[!VAR "cINMUX355"="0"!][!//
[!VAR "cINMUX356"="0"!][!//
[!VAR "cINMUX357"="0"!][!//
[!VAR "cINMUX358"="0"!][!//
[!VAR "cINMUX359"="0"!][!//
[!VAR "cINMUX360"="0"!][!//
[!VAR "cINMUX361"="0"!][!//
[!VAR "cINMUX362"="0"!][!//
[!VAR "cINMUX363"="0"!][!//
[!VAR "cINMUX364"="0"!][!//
[!VAR "cINMUX365"="0"!][!//
[!VAR "cINMUX366"="0"!][!//
[!VAR "cINMUX367"="0"!][!//
[!VAR "cINMUX368"="0"!][!//
[!VAR "cINMUX369"="0"!][!//
[!VAR "cINMUX370"="0"!][!//
[!VAR "cINMUX371"="0"!][!//
[!VAR "cINMUX372"="0"!][!//
[!VAR "cINMUX373"="0"!][!//
[!VAR "cINMUX374"="0"!][!//
[!VAR "cINMUX375"="0"!][!//
[!VAR "cINMUX376"="0"!][!//
[!VAR "cINMUX377"="0"!][!//
[!VAR "cINMUX378"="0"!][!//
[!VAR "cINMUX379"="0"!][!//
[!VAR "cINMUX380"="0"!][!//
[!VAR "cINMUX381"="0"!][!//
[!VAR "cINMUX382"="0"!][!//
[!VAR "cINMUX383"="0"!][!//
[!VAR "cINMUX384"="0"!][!//
[!VAR "cINMUX385"="0"!][!//
[!VAR "cINMUX386"="0"!][!//
[!VAR "cINMUX387"="0"!][!//
[!VAR "cINMUX388"="0"!][!//
[!VAR "cINMUX389"="0"!][!//
[!VAR "cINMUX390"="0"!][!//
[!VAR "cINMUX391"="0"!][!//
[!VAR "cINMUX392"="0"!][!//
[!VAR "cINMUX393"="0"!][!//
[!VAR "cINMUX394"="0"!][!//
[!VAR "cINMUX395"="0"!][!//
[!VAR "cINMUX396"="0"!][!//
[!VAR "cINMUX397"="0"!][!//
[!VAR "cINMUX398"="0"!][!//
[!VAR "cINMUX399"="0"!][!//
[!VAR "cINMUX400"="0"!][!//
[!VAR "cINMUX401"="0"!][!//
[!VAR "cINMUX402"="0"!][!//
[!VAR "cINMUX403"="0"!][!//
[!VAR "cINMUX404"="0"!][!//
[!VAR "cINMUX405"="0"!][!//
[!VAR "cINMUX406"="0"!][!//
[!VAR "cINMUX407"="0"!][!//
[!VAR "cINMUX408"="0"!][!//
[!VAR "cINMUX409"="0"!][!//
[!VAR "cINMUX410"="0"!][!//
[!VAR "cINMUX411"="0"!][!//
[!VAR "cINMUX412"="0"!][!//
[!VAR "cINMUX413"="0"!][!//
[!VAR "cINMUX414"="0"!][!//
[!VAR "cINMUX415"="0"!][!//
[!VAR "cINMUX416"="0"!][!//
[!VAR "cINMUX417"="0"!][!//
[!VAR "cINMUX418"="0"!][!//
[!VAR "cINMUX419"="0"!][!//
[!VAR "cINMUX420"="0"!][!//
[!VAR "cINMUX421"="0"!][!//
[!VAR "cINMUX422"="0"!][!//
[!VAR "cINMUX423"="0"!][!//
[!VAR "cINMUX424"="0"!][!//
[!VAR "cINMUX425"="0"!][!//
[!VAR "cINMUX426"="0"!][!//
[!VAR "cINMUX427"="0"!][!//
[!VAR "cINMUX428"="0"!][!//
[!VAR "cINMUX429"="0"!][!//
[!VAR "cINMUX430"="0"!][!//
[!VAR "cINMUX431"="0"!][!//
[!VAR "cINMUX432"="0"!][!//
[!VAR "cINMUX433"="0"!][!//
[!VAR "cINMUX434"="0"!][!//
[!VAR "cINMUX435"="0"!][!//
[!VAR "cINMUX436"="0"!][!//
[!VAR "cINMUX437"="0"!][!//
[!VAR "cINMUX438"="0"!][!//
[!VAR "cINMUX439"="0"!][!//
[!VAR "cINMUX440"="0"!][!//
[!VAR "cINMUX441"="0"!][!//
[!VAR "cINMUX442"="0"!][!//
[!VAR "cINMUX443"="0"!][!//
[!VAR "cINMUX444"="0"!][!//
[!VAR "cINMUX445"="0"!][!//
[!VAR "cINMUX446"="0"!][!//
[!VAR "cINMUX447"="0"!][!//
[!VAR "cINMUX448"="0"!][!//
[!VAR "cINMUX449"="0"!][!//
[!VAR "cINMUX450"="0"!][!//
[!VAR "cINMUX451"="0"!][!//
[!VAR "cINMUX452"="0"!][!//
[!VAR "cINMUX453"="0"!][!//
[!VAR "cINMUX454"="0"!][!//
[!VAR "cINMUX455"="0"!][!//
[!VAR "cINMUX456"="0"!][!//
[!VAR "cINMUX457"="0"!][!//
[!VAR "cINMUX458"="0"!][!//
[!VAR "cINMUX459"="0"!][!//
[!VAR "cINMUX460"="0"!][!//
[!VAR "cINMUX461"="0"!][!//
[!VAR "cINMUX462"="0"!][!//
[!VAR "cINMUX463"="0"!][!//
[!VAR "cINMUX464"="0"!][!//
[!VAR "cINMUX465"="0"!][!//
[!VAR "cINMUX466"="0"!][!//
[!VAR "cINMUX467"="0"!][!//
[!VAR "cINMUX468"="0"!][!//
[!VAR "cINMUX469"="0"!][!//
[!VAR "cINMUX470"="0"!][!//
[!VAR "cINMUX471"="0"!][!//
[!VAR "cINMUX472"="0"!][!//
[!VAR "cINMUX473"="0"!][!//
[!VAR "cINMUX474"="0"!][!//
[!VAR "cINMUX475"="0"!][!//
[!VAR "cINMUX476"="0"!][!//
[!VAR "cINMUX477"="0"!][!//
[!VAR "cINMUX478"="0"!][!//
[!VAR "cINMUX479"="0"!][!//
[!VAR "cINMUX480"="0"!][!//
[!VAR "cINMUX481"="0"!][!//
[!VAR "cINMUX482"="0"!][!//
[!VAR "cINMUX483"="0"!][!//
[!VAR "cINMUX484"="0"!][!//
[!VAR "cINMUX485"="0"!][!//
[!VAR "cINMUX486"="0"!][!//
[!VAR "cINMUX487"="0"!][!//
[!VAR "cINMUX488"="0"!][!//
[!VAR "cINMUX489"="0"!][!//
[!VAR "cINMUX490"="0"!][!//
[!VAR "cINMUX491"="0"!][!//
[!VAR "cINMUX492"="0"!][!//
[!VAR "cINMUX493"="0"!][!//
[!VAR "cINMUX494"="0"!][!//
[!VAR "cINMUX495"="0"!][!//
[!VAR "cINMUX496"="0"!][!//
[!VAR "cINMUX497"="0"!][!//
[!VAR "cINMUX498"="0"!][!//
[!VAR "cINMUX499"="0"!][!//
[!VAR "cINMUX500"="0"!][!//
[!VAR "cINMUX501"="0"!][!//
[!VAR "cINMUX502"="0"!][!//
[!VAR "cINMUX503"="0"!][!//
[!VAR "cINMUX504"="0"!][!//
[!VAR "cINMUX505"="0"!][!//
[!VAR "cINMUX506"="0"!][!//
[!VAR "cINMUX507"="0"!][!//
[!VAR "cINMUX508"="0"!][!//
[!VAR "cINMUX509"="0"!][!//
[!VAR "mode_pin"="0"!][!//
[!LOOP "PortContainer/*"!][!//
[!LOOP "PortPin/*"!][!//
[!VAR "mode_pin"="concat(./PortPinMode,'_PORT',number(./PortPinPcr))"!][!//
[!/* INMUX 0*/!]
[!IF "contains($INMUX0, $mode_pin)"!][!//
  [!VAR "cINMUX0"="number(substring-after(substring-before((substring-after($INMUX0,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 1*/!]
[!IF "contains($INMUX1, $mode_pin)"!][!//
  [!VAR "cINMUX1"="number(substring-after(substring-before((substring-after($INMUX1,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 2*/!]
[!IF "contains($INMUX2, $mode_pin)"!][!//
  [!VAR "cINMUX2"="number(substring-after(substring-before((substring-after($INMUX2,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 3*/!]
[!IF "contains($INMUX3, $mode_pin)"!][!//
  [!VAR "cINMUX3"="number(substring-after(substring-before((substring-after($INMUX3,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 4*/!]
[!IF "contains($INMUX4, $mode_pin)"!][!//
  [!VAR "cINMUX4"="number(substring-after(substring-before((substring-after($INMUX4,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 5*/!]
[!IF "contains($INMUX5, $mode_pin)"!][!//
  [!VAR "cINMUX5"="number(substring-after(substring-before((substring-after($INMUX5,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 6*/!]
[!IF "contains($INMUX6, $mode_pin)"!][!//
  [!VAR "cINMUX6"="number(substring-after(substring-before((substring-after($INMUX6,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 7*/!]
[!IF "contains($INMUX7, $mode_pin)"!][!//
  [!VAR "cINMUX7"="number(substring-after(substring-before((substring-after($INMUX7,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 8*/!]
[!IF "contains($INMUX8, $mode_pin)"!][!//
  [!VAR "cINMUX8"="number(substring-after(substring-before((substring-after($INMUX8,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 9*/!]
[!IF "contains($INMUX9, $mode_pin)"!][!//
  [!VAR "cINMUX9"="number(substring-after(substring-before((substring-after($INMUX9,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 10*/!]
[!IF "contains($INMUX10, $mode_pin)"!][!//
  [!VAR "cINMUX10"="number(substring-after(substring-before((substring-after($INMUX10,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 11*/!]
[!IF "contains($INMUX11, $mode_pin)"!][!//
  [!VAR "cINMUX11"="number(substring-after(substring-before((substring-after($INMUX11,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 12*/!]
[!IF "contains($INMUX12, $mode_pin)"!][!//
  [!VAR "cINMUX12"="number(substring-after(substring-before((substring-after($INMUX12,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 13*/!]
[!IF "contains($INMUX13, $mode_pin)"!][!//
  [!VAR "cINMUX13"="number(substring-after(substring-before((substring-after($INMUX13,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 14*/!]
[!IF "contains($INMUX14, $mode_pin)"!][!//
  [!VAR "cINMUX14"="number(substring-after(substring-before((substring-after($INMUX14,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 15*/!]
[!IF "contains($INMUX15, $mode_pin)"!][!//
  [!VAR "cINMUX15"="number(substring-after(substring-before((substring-after($INMUX15,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 16*/!]
[!IF "contains($INMUX16, $mode_pin)"!][!//
  [!VAR "cINMUX16"="number(substring-after(substring-before((substring-after($INMUX16,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 17*/!]
[!IF "contains($INMUX17, $mode_pin)"!][!//
  [!VAR "cINMUX17"="number(substring-after(substring-before((substring-after($INMUX17,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 18*/!]
[!IF "contains($INMUX18, $mode_pin)"!][!//
  [!VAR "cINMUX18"="number(substring-after(substring-before((substring-after($INMUX18,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 19*/!]
[!IF "contains($INMUX19, $mode_pin)"!][!//
  [!VAR "cINMUX19"="number(substring-after(substring-before((substring-after($INMUX19,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 20*/!]
[!IF "contains($INMUX20, $mode_pin)"!][!//
  [!VAR "cINMUX20"="number(substring-after(substring-before((substring-after($INMUX20,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 21*/!]
[!IF "contains($INMUX21, $mode_pin)"!][!//
  [!VAR "cINMUX21"="number(substring-after(substring-before((substring-after($INMUX21,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 22*/!]
[!IF "contains($INMUX22, $mode_pin)"!][!//
  [!VAR "cINMUX22"="number(substring-after(substring-before((substring-after($INMUX22,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 23*/!]
[!IF "contains($INMUX23, $mode_pin)"!][!//
  [!VAR "cINMUX23"="number(substring-after(substring-before((substring-after($INMUX23,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 24*/!]
[!IF "contains($INMUX24, $mode_pin)"!][!//
  [!VAR "cINMUX24"="number(substring-after(substring-before((substring-after($INMUX24,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 25*/!]
[!IF "contains($INMUX25, $mode_pin)"!][!//
  [!VAR "cINMUX25"="number(substring-after(substring-before((substring-after($INMUX25,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 26*/!]
[!IF "contains($INMUX26, $mode_pin)"!][!//
  [!VAR "cINMUX26"="number(substring-after(substring-before((substring-after($INMUX26,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 27*/!]
[!IF "contains($INMUX27, $mode_pin)"!][!//
  [!VAR "cINMUX27"="number(substring-after(substring-before((substring-after($INMUX27,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 28*/!]
[!IF "contains($INMUX28, $mode_pin)"!][!//
  [!VAR "cINMUX28"="number(substring-after(substring-before((substring-after($INMUX28,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 29*/!]
[!IF "contains($INMUX29, $mode_pin)"!][!//
  [!VAR "cINMUX29"="number(substring-after(substring-before((substring-after($INMUX29,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 30*/!]
[!IF "contains($INMUX30, $mode_pin)"!][!//
  [!VAR "cINMUX30"="number(substring-after(substring-before((substring-after($INMUX30,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 31*/!]
[!IF "contains($INMUX31, $mode_pin)"!][!//
  [!VAR "cINMUX31"="number(substring-after(substring-before((substring-after($INMUX31,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 32*/!]
[!IF "contains($INMUX32, $mode_pin)"!][!//
  [!VAR "cINMUX32"="number(substring-after(substring-before((substring-after($INMUX32,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 33*/!]
[!IF "contains($INMUX33, $mode_pin)"!][!//
  [!VAR "cINMUX33"="number(substring-after(substring-before((substring-after($INMUX33,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 34*/!]
[!IF "contains($INMUX34, $mode_pin)"!][!//
  [!VAR "cINMUX34"="number(substring-after(substring-before((substring-after($INMUX34,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 35*/!]
[!IF "contains($INMUX35, $mode_pin)"!][!//
  [!VAR "cINMUX35"="number(substring-after(substring-before((substring-after($INMUX35,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 36*/!]
[!IF "contains($INMUX36, $mode_pin)"!][!//
  [!VAR "cINMUX36"="number(substring-after(substring-before((substring-after($INMUX36,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 37*/!]
[!IF "contains($INMUX37, $mode_pin)"!][!//
  [!VAR "cINMUX37"="number(substring-after(substring-before((substring-after($INMUX37,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 38*/!]
[!IF "contains($INMUX38, $mode_pin)"!][!//
  [!VAR "cINMUX38"="number(substring-after(substring-before((substring-after($INMUX38,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 39*/!]
[!IF "contains($INMUX39, $mode_pin)"!][!//
  [!VAR "cINMUX39"="number(substring-after(substring-before((substring-after($INMUX39,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 40*/!]
[!IF "contains($INMUX40, $mode_pin)"!][!//
  [!VAR "cINMUX40"="number(substring-after(substring-before((substring-after($INMUX40,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 41*/!]
[!IF "contains($INMUX41, $mode_pin)"!][!//
  [!VAR "cINMUX41"="number(substring-after(substring-before((substring-after($INMUX41,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 42*/!]
[!IF "contains($INMUX42, $mode_pin)"!][!//
  [!VAR "cINMUX42"="number(substring-after(substring-before((substring-after($INMUX42,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 43*/!]
[!IF "contains($INMUX43, $mode_pin)"!][!//
  [!VAR "cINMUX43"="number(substring-after(substring-before((substring-after($INMUX43,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 44*/!]
[!IF "contains($INMUX44, $mode_pin)"!][!//
  [!VAR "cINMUX44"="number(substring-after(substring-before((substring-after($INMUX44,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 45*/!]
[!IF "contains($INMUX45, $mode_pin)"!][!//
  [!VAR "cINMUX45"="number(substring-after(substring-before((substring-after($INMUX45,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 46*/!]
[!IF "contains($INMUX46, $mode_pin)"!][!//
  [!VAR "cINMUX46"="number(substring-after(substring-before((substring-after($INMUX46,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 47*/!]
[!IF "contains($INMUX47, $mode_pin)"!][!//
  [!VAR "cINMUX47"="number(substring-after(substring-before((substring-after($INMUX47,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 48*/!]
[!IF "contains($INMUX48, $mode_pin)"!][!//
  [!VAR "cINMUX48"="number(substring-after(substring-before((substring-after($INMUX48,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 49*/!]
[!IF "contains($INMUX49, $mode_pin)"!][!//
  [!VAR "cINMUX49"="number(substring-after(substring-before((substring-after($INMUX49,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 50*/!]
[!IF "contains($INMUX50, $mode_pin)"!][!//
  [!VAR "cINMUX50"="number(substring-after(substring-before((substring-after($INMUX50,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 51*/!]
[!IF "contains($INMUX51, $mode_pin)"!][!//
  [!VAR "cINMUX51"="number(substring-after(substring-before((substring-after($INMUX51,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 52*/!]
[!IF "contains($INMUX52, $mode_pin)"!][!//
  [!VAR "cINMUX52"="number(substring-after(substring-before((substring-after($INMUX52,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 53*/!]
[!IF "contains($INMUX53, $mode_pin)"!][!//
  [!VAR "cINMUX53"="number(substring-after(substring-before((substring-after($INMUX53,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 54*/!]
[!IF "contains($INMUX54, $mode_pin)"!][!//
  [!VAR "cINMUX54"="number(substring-after(substring-before((substring-after($INMUX54,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 55*/!]
[!IF "contains($INMUX55, $mode_pin)"!][!//
  [!VAR "cINMUX55"="number(substring-after(substring-before((substring-after($INMUX55,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 56*/!]
[!IF "contains($INMUX56, $mode_pin)"!][!//
  [!VAR "cINMUX56"="number(substring-after(substring-before((substring-after($INMUX56,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 57*/!]
[!IF "contains($INMUX57, $mode_pin)"!][!//
  [!VAR "cINMUX57"="number(substring-after(substring-before((substring-after($INMUX57,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 58*/!]
[!IF "contains($INMUX58, $mode_pin)"!][!//
  [!VAR "cINMUX58"="number(substring-after(substring-before((substring-after($INMUX58,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 59*/!]
[!IF "contains($INMUX59, $mode_pin)"!][!//
  [!VAR "cINMUX59"="number(substring-after(substring-before((substring-after($INMUX59,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 60*/!]
[!IF "contains($INMUX60, $mode_pin)"!][!//
  [!VAR "cINMUX60"="number(substring-after(substring-before((substring-after($INMUX60,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 61*/!]
[!IF "contains($INMUX61, $mode_pin)"!][!//
  [!VAR "cINMUX61"="number(substring-after(substring-before((substring-after($INMUX61,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 62*/!]
[!IF "contains($INMUX62, $mode_pin)"!][!//
  [!VAR "cINMUX62"="number(substring-after(substring-before((substring-after($INMUX62,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 63*/!]
[!IF "contains($INMUX63, $mode_pin)"!][!//
  [!VAR "cINMUX63"="number(substring-after(substring-before((substring-after($INMUX63,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 64*/!]
[!IF "contains($INMUX64, $mode_pin)"!][!//
  [!VAR "cINMUX64"="number(substring-after(substring-before((substring-after($INMUX64,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 65*/!]
[!IF "contains($INMUX65, $mode_pin)"!][!//
  [!VAR "cINMUX65"="number(substring-after(substring-before((substring-after($INMUX65,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 66*/!]
[!IF "contains($INMUX66, $mode_pin)"!][!//
  [!VAR "cINMUX66"="number(substring-after(substring-before((substring-after($INMUX66,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 67*/!]
[!IF "contains($INMUX67, $mode_pin)"!][!//
  [!VAR "cINMUX67"="number(substring-after(substring-before((substring-after($INMUX67,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 68*/!]
[!IF "contains($INMUX68, $mode_pin)"!][!//
  [!VAR "cINMUX68"="number(substring-after(substring-before((substring-after($INMUX68,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 69*/!]
[!IF "contains($INMUX69, $mode_pin)"!][!//
  [!VAR "cINMUX69"="number(substring-after(substring-before((substring-after($INMUX69,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 70*/!]
[!IF "contains($INMUX70, $mode_pin)"!][!//
  [!VAR "cINMUX70"="number(substring-after(substring-before((substring-after($INMUX70,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 71*/!]
[!IF "contains($INMUX71, $mode_pin)"!][!//
  [!VAR "cINMUX71"="number(substring-after(substring-before((substring-after($INMUX71,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 72*/!]
[!IF "contains($INMUX72, $mode_pin)"!][!//
  [!VAR "cINMUX72"="number(substring-after(substring-before((substring-after($INMUX72,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 73*/!]
[!IF "contains($INMUX73, $mode_pin)"!][!//
  [!VAR "cINMUX73"="number(substring-after(substring-before((substring-after($INMUX73,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 74*/!]
[!IF "contains($INMUX74, $mode_pin)"!][!//
  [!VAR "cINMUX74"="number(substring-after(substring-before((substring-after($INMUX74,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 75*/!]
[!IF "contains($INMUX75, $mode_pin)"!][!//
  [!VAR "cINMUX75"="number(substring-after(substring-before((substring-after($INMUX75,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 76*/!]
[!IF "contains($INMUX76, $mode_pin)"!][!//
  [!VAR "cINMUX76"="number(substring-after(substring-before((substring-after($INMUX76,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 77*/!]
[!IF "contains($INMUX77, $mode_pin)"!][!//
  [!VAR "cINMUX77"="number(substring-after(substring-before((substring-after($INMUX77,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 78*/!]
[!IF "contains($INMUX78, $mode_pin)"!][!//
  [!VAR "cINMUX78"="number(substring-after(substring-before((substring-after($INMUX78,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 79*/!]
[!IF "contains($INMUX79, $mode_pin)"!][!//
  [!VAR "cINMUX79"="number(substring-after(substring-before((substring-after($INMUX79,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 80*/!]
[!IF "contains($INMUX80, $mode_pin)"!][!//
  [!VAR "cINMUX80"="number(substring-after(substring-before((substring-after($INMUX80,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 81*/!]
[!IF "contains($INMUX81, $mode_pin)"!][!//
  [!VAR "cINMUX81"="number(substring-after(substring-before((substring-after($INMUX81,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 82*/!]
[!IF "contains($INMUX82, $mode_pin)"!][!//
  [!VAR "cINMUX82"="number(substring-after(substring-before((substring-after($INMUX82,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 83*/!]
[!IF "contains($INMUX83, $mode_pin)"!][!//
  [!VAR "cINMUX83"="number(substring-after(substring-before((substring-after($INMUX83,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 84*/!]
[!IF "contains($INMUX84, $mode_pin)"!][!//
  [!VAR "cINMUX84"="number(substring-after(substring-before((substring-after($INMUX84,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 85*/!]
[!IF "contains($INMUX85, $mode_pin)"!][!//
  [!VAR "cINMUX85"="number(substring-after(substring-before((substring-after($INMUX85,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 86*/!]
[!IF "contains($INMUX86, $mode_pin)"!][!//
  [!VAR "cINMUX86"="number(substring-after(substring-before((substring-after($INMUX86,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 87*/!]
[!IF "contains($INMUX87, $mode_pin)"!][!//
  [!VAR "cINMUX87"="number(substring-after(substring-before((substring-after($INMUX87,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 88*/!]
[!IF "contains($INMUX88, $mode_pin)"!][!//
  [!VAR "cINMUX88"="number(substring-after(substring-before((substring-after($INMUX88,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 89*/!]
[!IF "contains($INMUX89, $mode_pin)"!][!//
  [!VAR "cINMUX89"="number(substring-after(substring-before((substring-after($INMUX89,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 90*/!]
[!IF "contains($INMUX90, $mode_pin)"!][!//
  [!VAR "cINMUX90"="number(substring-after(substring-before((substring-after($INMUX90,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 91*/!]
[!IF "contains($INMUX91, $mode_pin)"!][!//
  [!VAR "cINMUX91"="number(substring-after(substring-before((substring-after($INMUX91,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 92*/!]
[!IF "contains($INMUX92, $mode_pin)"!][!//
  [!VAR "cINMUX92"="number(substring-after(substring-before((substring-after($INMUX92,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 93*/!]
[!IF "contains($INMUX93, $mode_pin)"!][!//
  [!VAR "cINMUX93"="number(substring-after(substring-before((substring-after($INMUX93,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 94*/!]
[!IF "contains($INMUX94, $mode_pin)"!][!//
  [!VAR "cINMUX94"="number(substring-after(substring-before((substring-after($INMUX94,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 95*/!]
[!IF "contains($INMUX95, $mode_pin)"!][!//
  [!VAR "cINMUX95"="number(substring-after(substring-before((substring-after($INMUX95,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 96*/!]
[!IF "contains($INMUX96, $mode_pin)"!][!//
  [!VAR "cINMUX96"="number(substring-after(substring-before((substring-after($INMUX96,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 97*/!]
[!IF "contains($INMUX97, $mode_pin)"!][!//
  [!VAR "cINMUX97"="number(substring-after(substring-before((substring-after($INMUX97,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 98*/!]
[!IF "contains($INMUX98, $mode_pin)"!][!//
  [!VAR "cINMUX98"="number(substring-after(substring-before((substring-after($INMUX98,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 99*/!]
[!IF "contains($INMUX99, $mode_pin)"!][!//
  [!VAR "cINMUX99"="number(substring-after(substring-before((substring-after($INMUX99,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 100*/!]
[!IF "contains($INMUX100, $mode_pin)"!][!//
  [!VAR "cINMUX100"="number(substring-after(substring-before((substring-after($INMUX100,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 101*/!]
[!IF "contains($INMUX101, $mode_pin)"!][!//
  [!VAR "cINMUX101"="number(substring-after(substring-before((substring-after($INMUX101,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 102*/!]
[!IF "contains($INMUX102, $mode_pin)"!][!//
  [!VAR "cINMUX102"="number(substring-after(substring-before((substring-after($INMUX102,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 103*/!]
[!IF "contains($INMUX103, $mode_pin)"!][!//
  [!VAR "cINMUX103"="number(substring-after(substring-before((substring-after($INMUX103,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 104*/!]
[!IF "contains($INMUX104, $mode_pin)"!][!//
  [!VAR "cINMUX104"="number(substring-after(substring-before((substring-after($INMUX104,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 105*/!]
[!IF "contains($INMUX105, $mode_pin)"!][!//
  [!VAR "cINMUX105"="number(substring-after(substring-before((substring-after($INMUX105,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 106*/!]
[!IF "contains($INMUX106, $mode_pin)"!][!//
  [!VAR "cINMUX106"="number(substring-after(substring-before((substring-after($INMUX106,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 107*/!]
[!IF "contains($INMUX107, $mode_pin)"!][!//
  [!VAR "cINMUX107"="number(substring-after(substring-before((substring-after($INMUX107,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 108*/!]
[!IF "contains($INMUX108, $mode_pin)"!][!//
  [!VAR "cINMUX108"="number(substring-after(substring-before((substring-after($INMUX108,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 109*/!]
[!IF "contains($INMUX109, $mode_pin)"!][!//
  [!VAR "cINMUX109"="number(substring-after(substring-before((substring-after($INMUX109,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 110*/!]
[!IF "contains($INMUX110, $mode_pin)"!][!//
  [!VAR "cINMUX110"="number(substring-after(substring-before((substring-after($INMUX110,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 111*/!]
[!IF "contains($INMUX111, $mode_pin)"!][!//
  [!VAR "cINMUX111"="number(substring-after(substring-before((substring-after($INMUX111,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 112*/!]
[!IF "contains($INMUX112, $mode_pin)"!][!//
  [!VAR "cINMUX112"="number(substring-after(substring-before((substring-after($INMUX112,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 113*/!]
[!IF "contains($INMUX113, $mode_pin)"!][!//
  [!VAR "cINMUX113"="number(substring-after(substring-before((substring-after($INMUX113,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 114*/!]
[!IF "contains($INMUX114, $mode_pin)"!][!//
  [!VAR "cINMUX114"="number(substring-after(substring-before((substring-after($INMUX114,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 115*/!]
[!IF "contains($INMUX115, $mode_pin)"!][!//
  [!VAR "cINMUX115"="number(substring-after(substring-before((substring-after($INMUX115,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 116*/!]
[!IF "contains($INMUX116, $mode_pin)"!][!//
  [!VAR "cINMUX116"="number(substring-after(substring-before((substring-after($INMUX116,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 117*/!]
[!IF "contains($INMUX117, $mode_pin)"!][!//
  [!VAR "cINMUX117"="number(substring-after(substring-before((substring-after($INMUX117,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 118*/!]
[!IF "contains($INMUX118, $mode_pin)"!][!//
  [!VAR "cINMUX118"="number(substring-after(substring-before((substring-after($INMUX118,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 119*/!]
[!IF "contains($INMUX119, $mode_pin)"!][!//
  [!VAR "cINMUX119"="number(substring-after(substring-before((substring-after($INMUX119,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 120*/!]
[!IF "contains($INMUX120, $mode_pin)"!][!//
  [!VAR "cINMUX120"="number(substring-after(substring-before((substring-after($INMUX120,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 121*/!]
[!IF "contains($INMUX121, $mode_pin)"!][!//
  [!VAR "cINMUX121"="number(substring-after(substring-before((substring-after($INMUX121,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 122*/!]
[!IF "contains($INMUX122, $mode_pin)"!][!//
  [!VAR "cINMUX122"="number(substring-after(substring-before((substring-after($INMUX122,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 123*/!]
[!IF "contains($INMUX123, $mode_pin)"!][!//
  [!VAR "cINMUX123"="number(substring-after(substring-before((substring-after($INMUX123,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 124*/!]
[!IF "contains($INMUX124, $mode_pin)"!][!//
  [!VAR "cINMUX124"="number(substring-after(substring-before((substring-after($INMUX124,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 125*/!]
[!IF "contains($INMUX125, $mode_pin)"!][!//
  [!VAR "cINMUX125"="number(substring-after(substring-before((substring-after($INMUX125,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 126*/!]
[!IF "contains($INMUX126, $mode_pin)"!][!//
  [!VAR "cINMUX126"="number(substring-after(substring-before((substring-after($INMUX126,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 127*/!]
[!IF "contains($INMUX127, $mode_pin)"!][!//
  [!VAR "cINMUX127"="number(substring-after(substring-before((substring-after($INMUX127,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 128*/!]
[!IF "contains($INMUX128, $mode_pin)"!][!//
  [!VAR "cINMUX128"="number(substring-after(substring-before((substring-after($INMUX128,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 129*/!]
[!IF "contains($INMUX129, $mode_pin)"!][!//
  [!VAR "cINMUX129"="number(substring-after(substring-before((substring-after($INMUX129,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 130*/!]
[!IF "contains($INMUX130, $mode_pin)"!][!//
  [!VAR "cINMUX130"="number(substring-after(substring-before((substring-after($INMUX130,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 131*/!]
[!IF "contains($INMUX131, $mode_pin)"!][!//
  [!VAR "cINMUX131"="number(substring-after(substring-before((substring-after($INMUX131,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 132*/!]
[!IF "contains($INMUX132, $mode_pin)"!][!//
  [!VAR "cINMUX132"="number(substring-after(substring-before((substring-after($INMUX132,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 133*/!]
[!IF "contains($INMUX133, $mode_pin)"!][!//
  [!VAR "cINMUX133"="number(substring-after(substring-before((substring-after($INMUX133,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 134*/!]
[!IF "contains($INMUX134, $mode_pin)"!][!//
  [!VAR "cINMUX134"="number(substring-after(substring-before((substring-after($INMUX134,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 135*/!]
[!IF "contains($INMUX135, $mode_pin)"!][!//
  [!VAR "cINMUX135"="number(substring-after(substring-before((substring-after($INMUX135,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 136*/!]
[!IF "contains($INMUX136, $mode_pin)"!][!//
  [!VAR "cINMUX136"="number(substring-after(substring-before((substring-after($INMUX136,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 137*/!]
[!IF "contains($INMUX137, $mode_pin)"!][!//
  [!VAR "cINMUX137"="number(substring-after(substring-before((substring-after($INMUX137,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 138*/!]
[!IF "contains($INMUX138, $mode_pin)"!][!//
  [!VAR "cINMUX138"="number(substring-after(substring-before((substring-after($INMUX138,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 139*/!]
[!IF "contains($INMUX139, $mode_pin)"!][!//
  [!VAR "cINMUX139"="number(substring-after(substring-before((substring-after($INMUX139,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 140*/!]
[!IF "contains($INMUX140, $mode_pin)"!][!//
  [!VAR "cINMUX140"="number(substring-after(substring-before((substring-after($INMUX140,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 141*/!]
[!IF "contains($INMUX141, $mode_pin)"!][!//
  [!VAR "cINMUX141"="number(substring-after(substring-before((substring-after($INMUX141,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 142*/!]
[!IF "contains($INMUX142, $mode_pin)"!][!//
  [!VAR "cINMUX142"="number(substring-after(substring-before((substring-after($INMUX142,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 143*/!]
[!IF "contains($INMUX143, $mode_pin)"!][!//
  [!VAR "cINMUX143"="number(substring-after(substring-before((substring-after($INMUX143,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 144*/!]
[!IF "contains($INMUX144, $mode_pin)"!][!//
  [!VAR "cINMUX144"="number(substring-after(substring-before((substring-after($INMUX144,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 145*/!]
[!IF "contains($INMUX145, $mode_pin)"!][!//
  [!VAR "cINMUX145"="number(substring-after(substring-before((substring-after($INMUX145,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 146*/!]
[!IF "contains($INMUX146, $mode_pin)"!][!//
  [!VAR "cINMUX146"="number(substring-after(substring-before((substring-after($INMUX146,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 147*/!]
[!IF "contains($INMUX147, $mode_pin)"!][!//
  [!VAR "cINMUX147"="number(substring-after(substring-before((substring-after($INMUX147,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 148*/!]
[!IF "contains($INMUX148, $mode_pin)"!][!//
  [!VAR "cINMUX148"="number(substring-after(substring-before((substring-after($INMUX148,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 149*/!]
[!IF "contains($INMUX149, $mode_pin)"!][!//
  [!VAR "cINMUX149"="number(substring-after(substring-before((substring-after($INMUX149,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 150*/!]
[!IF "contains($INMUX150, $mode_pin)"!][!//
  [!VAR "cINMUX150"="number(substring-after(substring-before((substring-after($INMUX150,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 151*/!]
[!IF "contains($INMUX151, $mode_pin)"!][!//
  [!VAR "cINMUX151"="number(substring-after(substring-before((substring-after($INMUX151,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 152*/!]
[!IF "contains($INMUX152, $mode_pin)"!][!//
  [!VAR "cINMUX152"="number(substring-after(substring-before((substring-after($INMUX152,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 153*/!]
[!IF "contains($INMUX153, $mode_pin)"!][!//
  [!VAR "cINMUX153"="number(substring-after(substring-before((substring-after($INMUX153,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 154*/!]
[!IF "contains($INMUX154, $mode_pin)"!][!//
  [!VAR "cINMUX154"="number(substring-after(substring-before((substring-after($INMUX154,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 155*/!]
[!IF "contains($INMUX155, $mode_pin)"!][!//
  [!VAR "cINMUX155"="number(substring-after(substring-before((substring-after($INMUX155,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 156*/!]
[!IF "contains($INMUX156, $mode_pin)"!][!//
  [!VAR "cINMUX156"="number(substring-after(substring-before((substring-after($INMUX156,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 157*/!]
[!IF "contains($INMUX157, $mode_pin)"!][!//
  [!VAR "cINMUX157"="number(substring-after(substring-before((substring-after($INMUX157,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 158*/!]
[!IF "contains($INMUX158, $mode_pin)"!][!//
  [!VAR "cINMUX158"="number(substring-after(substring-before((substring-after($INMUX158,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 159*/!]
[!IF "contains($INMUX159, $mode_pin)"!][!//
  [!VAR "cINMUX159"="number(substring-after(substring-before((substring-after($INMUX159,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 160*/!]
[!IF "contains($INMUX160, $mode_pin)"!][!//
  [!VAR "cINMUX160"="number(substring-after(substring-before((substring-after($INMUX160,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 161*/!]
[!IF "contains($INMUX161, $mode_pin)"!][!//
  [!VAR "cINMUX161"="number(substring-after(substring-before((substring-after($INMUX161,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 162*/!]
[!IF "contains($INMUX162, $mode_pin)"!][!//
  [!VAR "cINMUX162"="number(substring-after(substring-before((substring-after($INMUX162,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 163*/!]
[!IF "contains($INMUX163, $mode_pin)"!][!//
  [!VAR "cINMUX163"="number(substring-after(substring-before((substring-after($INMUX163,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 164*/!]
[!IF "contains($INMUX164, $mode_pin)"!][!//
  [!VAR "cINMUX164"="number(substring-after(substring-before((substring-after($INMUX164,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 165*/!]
[!IF "contains($INMUX165, $mode_pin)"!][!//
  [!VAR "cINMUX165"="number(substring-after(substring-before((substring-after($INMUX165,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 166*/!]
[!IF "contains($INMUX166, $mode_pin)"!][!//
  [!VAR "cINMUX166"="number(substring-after(substring-before((substring-after($INMUX166,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 167*/!]
[!IF "contains($INMUX167, $mode_pin)"!][!//
  [!VAR "cINMUX167"="number(substring-after(substring-before((substring-after($INMUX167,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 168*/!]
[!IF "contains($INMUX168, $mode_pin)"!][!//
  [!VAR "cINMUX168"="number(substring-after(substring-before((substring-after($INMUX168,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 169*/!]
[!IF "contains($INMUX169, $mode_pin)"!][!//
  [!VAR "cINMUX169"="number(substring-after(substring-before((substring-after($INMUX169,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 170*/!]
[!IF "contains($INMUX170, $mode_pin)"!][!//
  [!VAR "cINMUX170"="number(substring-after(substring-before((substring-after($INMUX170,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 171*/!]
[!IF "contains($INMUX171, $mode_pin)"!][!//
  [!VAR "cINMUX171"="number(substring-after(substring-before((substring-after($INMUX171,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 172*/!]
[!IF "contains($INMUX172, $mode_pin)"!][!//
  [!VAR "cINMUX172"="number(substring-after(substring-before((substring-after($INMUX172,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 173*/!]
[!IF "contains($INMUX173, $mode_pin)"!][!//
  [!VAR "cINMUX173"="number(substring-after(substring-before((substring-after($INMUX173,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 174*/!]
[!IF "contains($INMUX174, $mode_pin)"!][!//
  [!VAR "cINMUX174"="number(substring-after(substring-before((substring-after($INMUX174,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 175*/!]
[!IF "contains($INMUX175, $mode_pin)"!][!//
  [!VAR "cINMUX175"="number(substring-after(substring-before((substring-after($INMUX175,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 176*/!]
[!IF "contains($INMUX176, $mode_pin)"!][!//
  [!VAR "cINMUX176"="number(substring-after(substring-before((substring-after($INMUX176,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 177*/!]
[!IF "contains($INMUX177, $mode_pin)"!][!//
  [!VAR "cINMUX177"="number(substring-after(substring-before((substring-after($INMUX177,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 178*/!]
[!IF "contains($INMUX178, $mode_pin)"!][!//
  [!VAR "cINMUX178"="number(substring-after(substring-before((substring-after($INMUX178,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 179*/!]
[!IF "contains($INMUX179, $mode_pin)"!][!//
  [!VAR "cINMUX179"="number(substring-after(substring-before((substring-after($INMUX179,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 180*/!]
[!IF "contains($INMUX180, $mode_pin)"!][!//
  [!VAR "cINMUX180"="number(substring-after(substring-before((substring-after($INMUX180,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 181*/!]
[!IF "contains($INMUX181, $mode_pin)"!][!//
  [!VAR "cINMUX181"="number(substring-after(substring-before((substring-after($INMUX181,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 182*/!]
[!IF "contains($INMUX182, $mode_pin)"!][!//
  [!VAR "cINMUX182"="number(substring-after(substring-before((substring-after($INMUX182,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 183*/!]
[!IF "contains($INMUX183, $mode_pin)"!][!//
  [!VAR "cINMUX183"="number(substring-after(substring-before((substring-after($INMUX183,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 184*/!]
[!IF "contains($INMUX184, $mode_pin)"!][!//
  [!VAR "cINMUX184"="number(substring-after(substring-before((substring-after($INMUX184,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 185*/!]
[!IF "contains($INMUX185, $mode_pin)"!][!//
  [!VAR "cINMUX185"="number(substring-after(substring-before((substring-after($INMUX185,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 186*/!]
[!IF "contains($INMUX186, $mode_pin)"!][!//
  [!VAR "cINMUX186"="number(substring-after(substring-before((substring-after($INMUX186,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 187*/!]
[!IF "contains($INMUX187, $mode_pin)"!][!//
  [!VAR "cINMUX187"="number(substring-after(substring-before((substring-after($INMUX187,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 188*/!]
[!IF "contains($INMUX188, $mode_pin)"!][!//
  [!VAR "cINMUX188"="number(substring-after(substring-before((substring-after($INMUX188,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 189*/!]
[!IF "contains($INMUX189, $mode_pin)"!][!//
  [!VAR "cINMUX189"="number(substring-after(substring-before((substring-after($INMUX189,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 190*/!]
[!IF "contains($INMUX190, $mode_pin)"!][!//
  [!VAR "cINMUX190"="number(substring-after(substring-before((substring-after($INMUX190,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 191*/!]
[!IF "contains($INMUX191, $mode_pin)"!][!//
  [!VAR "cINMUX191"="number(substring-after(substring-before((substring-after($INMUX191,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 192*/!]
[!IF "contains($INMUX192, $mode_pin)"!][!//
  [!VAR "cINMUX192"="number(substring-after(substring-before((substring-after($INMUX192,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 193*/!]
[!IF "contains($INMUX193, $mode_pin)"!][!//
  [!VAR "cINMUX193"="number(substring-after(substring-before((substring-after($INMUX193,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 194*/!]
[!IF "contains($INMUX194, $mode_pin)"!][!//
  [!VAR "cINMUX194"="number(substring-after(substring-before((substring-after($INMUX194,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 195*/!]
[!IF "contains($INMUX195, $mode_pin)"!][!//
  [!VAR "cINMUX195"="number(substring-after(substring-before((substring-after($INMUX195,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 196*/!]
[!IF "contains($INMUX196, $mode_pin)"!][!//
  [!VAR "cINMUX196"="number(substring-after(substring-before((substring-after($INMUX196,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 197*/!]
[!IF "contains($INMUX197, $mode_pin)"!][!//
  [!VAR "cINMUX197"="number(substring-after(substring-before((substring-after($INMUX197,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 198*/!]
[!IF "contains($INMUX198, $mode_pin)"!][!//
  [!VAR "cINMUX198"="number(substring-after(substring-before((substring-after($INMUX198,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 199*/!]
[!IF "contains($INMUX199, $mode_pin)"!][!//
  [!VAR "cINMUX199"="number(substring-after(substring-before((substring-after($INMUX199,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 200*/!]
[!IF "contains($INMUX200, $mode_pin)"!][!//
  [!VAR "cINMUX200"="number(substring-after(substring-before((substring-after($INMUX200,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 201*/!]
[!IF "contains($INMUX201, $mode_pin)"!][!//
  [!VAR "cINMUX201"="number(substring-after(substring-before((substring-after($INMUX201,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 202*/!]
[!IF "contains($INMUX202, $mode_pin)"!][!//
  [!VAR "cINMUX202"="number(substring-after(substring-before((substring-after($INMUX202,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 203*/!]
[!IF "contains($INMUX203, $mode_pin)"!][!//
  [!VAR "cINMUX203"="number(substring-after(substring-before((substring-after($INMUX203,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 204*/!]
[!IF "contains($INMUX204, $mode_pin)"!][!//
  [!VAR "cINMUX204"="number(substring-after(substring-before((substring-after($INMUX204,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 205*/!]
[!IF "contains($INMUX205, $mode_pin)"!][!//
  [!VAR "cINMUX205"="number(substring-after(substring-before((substring-after($INMUX205,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 206*/!]
[!IF "contains($INMUX206, $mode_pin)"!][!//
  [!VAR "cINMUX206"="number(substring-after(substring-before((substring-after($INMUX206,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 207*/!]
[!IF "contains($INMUX207, $mode_pin)"!][!//
  [!VAR "cINMUX207"="number(substring-after(substring-before((substring-after($INMUX207,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 208*/!]
[!IF "contains($INMUX208, $mode_pin)"!][!//
  [!VAR "cINMUX208"="number(substring-after(substring-before((substring-after($INMUX208,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 209*/!]
[!IF "contains($INMUX209, $mode_pin)"!][!//
  [!VAR "cINMUX209"="number(substring-after(substring-before((substring-after($INMUX209,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 210*/!]
[!IF "contains($INMUX210, $mode_pin)"!][!//
  [!VAR "cINMUX210"="number(substring-after(substring-before((substring-after($INMUX210,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 211*/!]
[!IF "contains($INMUX211, $mode_pin)"!][!//
  [!VAR "cINMUX211"="number(substring-after(substring-before((substring-after($INMUX211,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 212*/!]
[!IF "contains($INMUX212, $mode_pin)"!][!//
  [!VAR "cINMUX212"="number(substring-after(substring-before((substring-after($INMUX212,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 213*/!]
[!IF "contains($INMUX213, $mode_pin)"!][!//
  [!VAR "cINMUX213"="number(substring-after(substring-before((substring-after($INMUX213,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 214*/!]
[!IF "contains($INMUX214, $mode_pin)"!][!//
  [!VAR "cINMUX214"="number(substring-after(substring-before((substring-after($INMUX214,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 215*/!]
[!IF "contains($INMUX215, $mode_pin)"!][!//
  [!VAR "cINMUX215"="number(substring-after(substring-before((substring-after($INMUX215,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 216*/!]
[!IF "contains($INMUX216, $mode_pin)"!][!//
  [!VAR "cINMUX216"="number(substring-after(substring-before((substring-after($INMUX216,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 217*/!]
[!IF "contains($INMUX217, $mode_pin)"!][!//
  [!VAR "cINMUX217"="number(substring-after(substring-before((substring-after($INMUX217,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 218*/!]
[!IF "contains($INMUX218, $mode_pin)"!][!//
  [!VAR "cINMUX218"="number(substring-after(substring-before((substring-after($INMUX218,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 219*/!]
[!IF "contains($INMUX219, $mode_pin)"!][!//
  [!VAR "cINMUX219"="number(substring-after(substring-before((substring-after($INMUX219,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 220*/!]
[!IF "contains($INMUX220, $mode_pin)"!][!//
  [!VAR "cINMUX220"="number(substring-after(substring-before((substring-after($INMUX220,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 221*/!]
[!IF "contains($INMUX221, $mode_pin)"!][!//
  [!VAR "cINMUX221"="number(substring-after(substring-before((substring-after($INMUX221,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 222*/!]
[!IF "contains($INMUX222, $mode_pin)"!][!//
  [!VAR "cINMUX222"="number(substring-after(substring-before((substring-after($INMUX222,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 223*/!]
[!IF "contains($INMUX223, $mode_pin)"!][!//
  [!VAR "cINMUX223"="number(substring-after(substring-before((substring-after($INMUX223,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 224*/!]
[!IF "contains($INMUX224, $mode_pin)"!][!//
  [!VAR "cINMUX224"="number(substring-after(substring-before((substring-after($INMUX224,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 225*/!]
[!IF "contains($INMUX225, $mode_pin)"!][!//
  [!VAR "cINMUX225"="number(substring-after(substring-before((substring-after($INMUX225,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 226*/!]
[!IF "contains($INMUX226, $mode_pin)"!][!//
  [!VAR "cINMUX226"="number(substring-after(substring-before((substring-after($INMUX226,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 227*/!]
[!IF "contains($INMUX227, $mode_pin)"!][!//
  [!VAR "cINMUX227"="number(substring-after(substring-before((substring-after($INMUX227,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 228*/!]
[!IF "contains($INMUX228, $mode_pin)"!][!//
  [!VAR "cINMUX228"="number(substring-after(substring-before((substring-after($INMUX228,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 229*/!]
[!IF "contains($INMUX229, $mode_pin)"!][!//
  [!VAR "cINMUX229"="number(substring-after(substring-before((substring-after($INMUX229,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 230*/!]
[!IF "contains($INMUX230, $mode_pin)"!][!//
  [!VAR "cINMUX230"="number(substring-after(substring-before((substring-after($INMUX230,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 231*/!]
[!IF "contains($INMUX231, $mode_pin)"!][!//
  [!VAR "cINMUX231"="number(substring-after(substring-before((substring-after($INMUX231,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 232*/!]
[!IF "contains($INMUX232, $mode_pin)"!][!//
  [!VAR "cINMUX232"="number(substring-after(substring-before((substring-after($INMUX232,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 233*/!]
[!IF "contains($INMUX233, $mode_pin)"!][!//
  [!VAR "cINMUX233"="number(substring-after(substring-before((substring-after($INMUX233,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 234*/!]
[!IF "contains($INMUX234, $mode_pin)"!][!//
  [!VAR "cINMUX234"="number(substring-after(substring-before((substring-after($INMUX234,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 235*/!]
[!IF "contains($INMUX235, $mode_pin)"!][!//
  [!VAR "cINMUX235"="number(substring-after(substring-before((substring-after($INMUX235,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 236*/!]
[!IF "contains($INMUX236, $mode_pin)"!][!//
  [!VAR "cINMUX236"="number(substring-after(substring-before((substring-after($INMUX236,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 237*/!]
[!IF "contains($INMUX237, $mode_pin)"!][!//
  [!VAR "cINMUX237"="number(substring-after(substring-before((substring-after($INMUX237,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 238*/!]
[!IF "contains($INMUX238, $mode_pin)"!][!//
  [!VAR "cINMUX238"="number(substring-after(substring-before((substring-after($INMUX238,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 239*/!]
[!IF "contains($INMUX239, $mode_pin)"!][!//
  [!VAR "cINMUX239"="number(substring-after(substring-before((substring-after($INMUX239,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 240*/!]
[!IF "contains($INMUX240, $mode_pin)"!][!//
  [!VAR "cINMUX240"="number(substring-after(substring-before((substring-after($INMUX240,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 241*/!]
[!IF "contains($INMUX241, $mode_pin)"!][!//
  [!VAR "cINMUX241"="number(substring-after(substring-before((substring-after($INMUX241,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 242*/!]
[!IF "contains($INMUX242, $mode_pin)"!][!//
  [!VAR "cINMUX242"="number(substring-after(substring-before((substring-after($INMUX242,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 243*/!]
[!IF "contains($INMUX243, $mode_pin)"!][!//
  [!VAR "cINMUX243"="number(substring-after(substring-before((substring-after($INMUX243,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 244*/!]
[!IF "contains($INMUX244, $mode_pin)"!][!//
  [!VAR "cINMUX244"="number(substring-after(substring-before((substring-after($INMUX244,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 245*/!]
[!IF "contains($INMUX245, $mode_pin)"!][!//
  [!VAR "cINMUX245"="number(substring-after(substring-before((substring-after($INMUX245,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 246*/!]
[!IF "contains($INMUX246, $mode_pin)"!][!//
  [!VAR "cINMUX246"="number(substring-after(substring-before((substring-after($INMUX246,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 247*/!]
[!IF "contains($INMUX247, $mode_pin)"!][!//
  [!VAR "cINMUX247"="number(substring-after(substring-before((substring-after($INMUX247,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 248*/!]
[!IF "contains($INMUX248, $mode_pin)"!][!//
  [!VAR "cINMUX248"="number(substring-after(substring-before((substring-after($INMUX248,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 249*/!]
[!IF "contains($INMUX249, $mode_pin)"!][!//
  [!VAR "cINMUX249"="number(substring-after(substring-before((substring-after($INMUX249,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 250*/!]
[!IF "contains($INMUX250, $mode_pin)"!][!//
  [!VAR "cINMUX250"="number(substring-after(substring-before((substring-after($INMUX250,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 251*/!]
[!IF "contains($INMUX251, $mode_pin)"!][!//
  [!VAR "cINMUX251"="number(substring-after(substring-before((substring-after($INMUX251,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 252*/!]
[!IF "contains($INMUX252, $mode_pin)"!][!//
  [!VAR "cINMUX252"="number(substring-after(substring-before((substring-after($INMUX252,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 253*/!]
[!IF "contains($INMUX253, $mode_pin)"!][!//
  [!VAR "cINMUX253"="number(substring-after(substring-before((substring-after($INMUX253,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 254*/!]
[!IF "contains($INMUX254, $mode_pin)"!][!//
  [!VAR "cINMUX254"="number(substring-after(substring-before((substring-after($INMUX254,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 255*/!]
[!IF "contains($INMUX255, $mode_pin)"!][!//
  [!VAR "cINMUX255"="number(substring-after(substring-before((substring-after($INMUX255,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 256*/!]
[!IF "contains($INMUX256, $mode_pin)"!][!//
  [!VAR "cINMUX256"="number(substring-after(substring-before((substring-after($INMUX256,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 257*/!]
[!IF "contains($INMUX257, $mode_pin)"!][!//
  [!VAR "cINMUX257"="number(substring-after(substring-before((substring-after($INMUX257,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 258*/!]
[!IF "contains($INMUX258, $mode_pin)"!][!//
  [!VAR "cINMUX258"="number(substring-after(substring-before((substring-after($INMUX258,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 259*/!]
[!IF "contains($INMUX259, $mode_pin)"!][!//
  [!VAR "cINMUX259"="number(substring-after(substring-before((substring-after($INMUX259,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 260*/!]
[!IF "contains($INMUX260, $mode_pin)"!][!//
  [!VAR "cINMUX260"="number(substring-after(substring-before((substring-after($INMUX260,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 261*/!]
[!IF "contains($INMUX261, $mode_pin)"!][!//
  [!VAR "cINMUX261"="number(substring-after(substring-before((substring-after($INMUX261,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 262*/!]
[!IF "contains($INMUX262, $mode_pin)"!][!//
  [!VAR "cINMUX262"="number(substring-after(substring-before((substring-after($INMUX262,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 263*/!]
[!IF "contains($INMUX263, $mode_pin)"!][!//
  [!VAR "cINMUX263"="number(substring-after(substring-before((substring-after($INMUX263,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 264*/!]
[!IF "contains($INMUX264, $mode_pin)"!][!//
  [!VAR "cINMUX264"="number(substring-after(substring-before((substring-after($INMUX264,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 265*/!]
[!IF "contains($INMUX265, $mode_pin)"!][!//
  [!VAR "cINMUX265"="number(substring-after(substring-before((substring-after($INMUX265,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 266*/!]
[!IF "contains($INMUX266, $mode_pin)"!][!//
  [!VAR "cINMUX266"="number(substring-after(substring-before((substring-after($INMUX266,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 267*/!]
[!IF "contains($INMUX267, $mode_pin)"!][!//
  [!VAR "cINMUX267"="number(substring-after(substring-before((substring-after($INMUX267,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 268*/!]
[!IF "contains($INMUX268, $mode_pin)"!][!//
  [!VAR "cINMUX268"="number(substring-after(substring-before((substring-after($INMUX268,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 269*/!]
[!IF "contains($INMUX269, $mode_pin)"!][!//
  [!VAR "cINMUX269"="number(substring-after(substring-before((substring-after($INMUX269,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 270*/!]
[!IF "contains($INMUX270, $mode_pin)"!][!//
  [!VAR "cINMUX270"="number(substring-after(substring-before((substring-after($INMUX270,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 271*/!]
[!IF "contains($INMUX271, $mode_pin)"!][!//
  [!VAR "cINMUX271"="number(substring-after(substring-before((substring-after($INMUX271,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 272*/!]
[!IF "contains($INMUX272, $mode_pin)"!][!//
  [!VAR "cINMUX272"="number(substring-after(substring-before((substring-after($INMUX272,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 273*/!]
[!IF "contains($INMUX273, $mode_pin)"!][!//
  [!VAR "cINMUX273"="number(substring-after(substring-before((substring-after($INMUX273,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 274*/!]
[!IF "contains($INMUX274, $mode_pin)"!][!//
  [!VAR "cINMUX274"="number(substring-after(substring-before((substring-after($INMUX274,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 275*/!]
[!IF "contains($INMUX275, $mode_pin)"!][!//
  [!VAR "cINMUX275"="number(substring-after(substring-before((substring-after($INMUX275,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 276*/!]
[!IF "contains($INMUX276, $mode_pin)"!][!//
  [!VAR "cINMUX276"="number(substring-after(substring-before((substring-after($INMUX276,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 277*/!]
[!IF "contains($INMUX277, $mode_pin)"!][!//
  [!VAR "cINMUX277"="number(substring-after(substring-before((substring-after($INMUX277,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 278*/!]
[!IF "contains($INMUX278, $mode_pin)"!][!//
  [!VAR "cINMUX278"="number(substring-after(substring-before((substring-after($INMUX278,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 279*/!]
[!IF "contains($INMUX279, $mode_pin)"!][!//
  [!VAR "cINMUX279"="number(substring-after(substring-before((substring-after($INMUX279,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 280*/!]
[!IF "contains($INMUX280, $mode_pin)"!][!//
  [!VAR "cINMUX280"="number(substring-after(substring-before((substring-after($INMUX280,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 281*/!]
[!IF "contains($INMUX281, $mode_pin)"!][!//
  [!VAR "cINMUX281"="number(substring-after(substring-before((substring-after($INMUX281,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 282*/!]
[!IF "contains($INMUX282, $mode_pin)"!][!//
  [!VAR "cINMUX282"="number(substring-after(substring-before((substring-after($INMUX282,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 283*/!]
[!IF "contains($INMUX283, $mode_pin)"!][!//
  [!VAR "cINMUX283"="number(substring-after(substring-before((substring-after($INMUX283,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 284*/!]
[!IF "contains($INMUX284, $mode_pin)"!][!//
  [!VAR "cINMUX284"="number(substring-after(substring-before((substring-after($INMUX284,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 285*/!]
[!IF "contains($INMUX285, $mode_pin)"!][!//
  [!VAR "cINMUX285"="number(substring-after(substring-before((substring-after($INMUX285,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 286*/!]
[!IF "contains($INMUX286, $mode_pin)"!][!//
  [!VAR "cINMUX286"="number(substring-after(substring-before((substring-after($INMUX286,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 287*/!]
[!IF "contains($INMUX287, $mode_pin)"!][!//
  [!VAR "cINMUX287"="number(substring-after(substring-before((substring-after($INMUX287,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 288*/!]
[!IF "contains($INMUX288, $mode_pin)"!][!//
  [!VAR "cINMUX288"="number(substring-after(substring-before((substring-after($INMUX288,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 289*/!]
[!IF "contains($INMUX289, $mode_pin)"!][!//
  [!VAR "cINMUX289"="number(substring-after(substring-before((substring-after($INMUX289,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 290*/!]
[!IF "contains($INMUX290, $mode_pin)"!][!//
  [!VAR "cINMUX290"="number(substring-after(substring-before((substring-after($INMUX290,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 291*/!]
[!IF "contains($INMUX291, $mode_pin)"!][!//
  [!VAR "cINMUX291"="number(substring-after(substring-before((substring-after($INMUX291,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 292*/!]
[!IF "contains($INMUX292, $mode_pin)"!][!//
  [!VAR "cINMUX292"="number(substring-after(substring-before((substring-after($INMUX292,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 293*/!]
[!IF "contains($INMUX293, $mode_pin)"!][!//
  [!VAR "cINMUX293"="number(substring-after(substring-before((substring-after($INMUX293,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 294*/!]
[!IF "contains($INMUX294, $mode_pin)"!][!//
  [!VAR "cINMUX294"="number(substring-after(substring-before((substring-after($INMUX294,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 295*/!]
[!IF "contains($INMUX295, $mode_pin)"!][!//
  [!VAR "cINMUX295"="number(substring-after(substring-before((substring-after($INMUX295,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 296*/!]
[!IF "contains($INMUX296, $mode_pin)"!][!//
  [!VAR "cINMUX296"="number(substring-after(substring-before((substring-after($INMUX296,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 297*/!]
[!IF "contains($INMUX297, $mode_pin)"!][!//
  [!VAR "cINMUX297"="number(substring-after(substring-before((substring-after($INMUX297,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 298*/!]
[!IF "contains($INMUX298, $mode_pin)"!][!//
  [!VAR "cINMUX298"="number(substring-after(substring-before((substring-after($INMUX298,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 299*/!]
[!IF "contains($INMUX299, $mode_pin)"!][!//
  [!VAR "cINMUX299"="number(substring-after(substring-before((substring-after($INMUX299,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 300*/!]
[!IF "contains($INMUX300, $mode_pin)"!][!//
  [!VAR "cINMUX300"="number(substring-after(substring-before((substring-after($INMUX300,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 301*/!]
[!IF "contains($INMUX301, $mode_pin)"!][!//
  [!VAR "cINMUX301"="number(substring-after(substring-before((substring-after($INMUX301,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 302*/!]
[!IF "contains($INMUX302, $mode_pin)"!][!//
  [!VAR "cINMUX302"="number(substring-after(substring-before((substring-after($INMUX302,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 303*/!]
[!IF "contains($INMUX303, $mode_pin)"!][!//
  [!VAR "cINMUX303"="number(substring-after(substring-before((substring-after($INMUX303,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 304*/!]
[!IF "contains($INMUX304, $mode_pin)"!][!//
  [!VAR "cINMUX304"="number(substring-after(substring-before((substring-after($INMUX304,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 305*/!]
[!IF "contains($INMUX305, $mode_pin)"!][!//
  [!VAR "cINMUX305"="number(substring-after(substring-before((substring-after($INMUX305,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 306*/!]
[!IF "contains($INMUX306, $mode_pin)"!][!//
  [!VAR "cINMUX306"="number(substring-after(substring-before((substring-after($INMUX306,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 307*/!]
[!IF "contains($INMUX307, $mode_pin)"!][!//
  [!VAR "cINMUX307"="number(substring-after(substring-before((substring-after($INMUX307,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 308*/!]
[!IF "contains($INMUX308, $mode_pin)"!][!//
  [!VAR "cINMUX308"="number(substring-after(substring-before((substring-after($INMUX308,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 309*/!]
[!IF "contains($INMUX309, $mode_pin)"!][!//
  [!VAR "cINMUX309"="number(substring-after(substring-before((substring-after($INMUX309,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 310*/!]
[!IF "contains($INMUX310, $mode_pin)"!][!//
  [!VAR "cINMUX310"="number(substring-after(substring-before((substring-after($INMUX310,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 311*/!]
[!IF "contains($INMUX311, $mode_pin)"!][!//
  [!VAR "cINMUX311"="number(substring-after(substring-before((substring-after($INMUX311,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 312*/!]
[!IF "contains($INMUX312, $mode_pin)"!][!//
  [!VAR "cINMUX312"="number(substring-after(substring-before((substring-after($INMUX312,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 313*/!]
[!IF "contains($INMUX313, $mode_pin)"!][!//
  [!VAR "cINMUX313"="number(substring-after(substring-before((substring-after($INMUX313,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 314*/!]
[!IF "contains($INMUX314, $mode_pin)"!][!//
  [!VAR "cINMUX314"="number(substring-after(substring-before((substring-after($INMUX314,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 315*/!]
[!IF "contains($INMUX315, $mode_pin)"!][!//
  [!VAR "cINMUX315"="number(substring-after(substring-before((substring-after($INMUX315,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 316*/!]
[!IF "contains($INMUX316, $mode_pin)"!][!//
  [!VAR "cINMUX316"="number(substring-after(substring-before((substring-after($INMUX316,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 317*/!]
[!IF "contains($INMUX317, $mode_pin)"!][!//
  [!VAR "cINMUX317"="number(substring-after(substring-before((substring-after($INMUX317,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 318*/!]
[!IF "contains($INMUX318, $mode_pin)"!][!//
  [!VAR "cINMUX318"="number(substring-after(substring-before((substring-after($INMUX318,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 319*/!]
[!IF "contains($INMUX319, $mode_pin)"!][!//
  [!VAR "cINMUX319"="number(substring-after(substring-before((substring-after($INMUX319,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 320*/!]
[!IF "contains($INMUX320, $mode_pin)"!][!//
  [!VAR "cINMUX320"="number(substring-after(substring-before((substring-after($INMUX320,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 321*/!]
[!IF "contains($INMUX321, $mode_pin)"!][!//
  [!VAR "cINMUX321"="number(substring-after(substring-before((substring-after($INMUX321,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 322*/!]
[!IF "contains($INMUX322, $mode_pin)"!][!//
  [!VAR "cINMUX322"="number(substring-after(substring-before((substring-after($INMUX322,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 323*/!]
[!IF "contains($INMUX323, $mode_pin)"!][!//
  [!VAR "cINMUX323"="number(substring-after(substring-before((substring-after($INMUX323,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 324*/!]
[!IF "contains($INMUX324, $mode_pin)"!][!//
  [!VAR "cINMUX324"="number(substring-after(substring-before((substring-after($INMUX324,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 325*/!]
[!IF "contains($INMUX325, $mode_pin)"!][!//
  [!VAR "cINMUX325"="number(substring-after(substring-before((substring-after($INMUX325,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 326*/!]
[!IF "contains($INMUX326, $mode_pin)"!][!//
  [!VAR "cINMUX326"="number(substring-after(substring-before((substring-after($INMUX326,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 327*/!]
[!IF "contains($INMUX327, $mode_pin)"!][!//
  [!VAR "cINMUX327"="number(substring-after(substring-before((substring-after($INMUX327,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 328*/!]
[!IF "contains($INMUX328, $mode_pin)"!][!//
  [!VAR "cINMUX328"="number(substring-after(substring-before((substring-after($INMUX328,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 329*/!]
[!IF "contains($INMUX329, $mode_pin)"!][!//
  [!VAR "cINMUX329"="number(substring-after(substring-before((substring-after($INMUX329,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 330*/!]
[!IF "contains($INMUX330, $mode_pin)"!][!//
  [!VAR "cINMUX330"="number(substring-after(substring-before((substring-after($INMUX330,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 331*/!]
[!IF "contains($INMUX331, $mode_pin)"!][!//
  [!VAR "cINMUX331"="number(substring-after(substring-before((substring-after($INMUX331,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 332*/!]
[!IF "contains($INMUX332, $mode_pin)"!][!//
  [!VAR "cINMUX332"="number(substring-after(substring-before((substring-after($INMUX332,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 333*/!]
[!IF "contains($INMUX333, $mode_pin)"!][!//
  [!VAR "cINMUX333"="number(substring-after(substring-before((substring-after($INMUX333,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 334*/!]
[!IF "contains($INMUX334, $mode_pin)"!][!//
  [!VAR "cINMUX334"="number(substring-after(substring-before((substring-after($INMUX334,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 335*/!]
[!IF "contains($INMUX335, $mode_pin)"!][!//
  [!VAR "cINMUX335"="number(substring-after(substring-before((substring-after($INMUX335,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 336*/!]
[!IF "contains($INMUX336, $mode_pin)"!][!//
  [!VAR "cINMUX336"="number(substring-after(substring-before((substring-after($INMUX336,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 337*/!]
[!IF "contains($INMUX337, $mode_pin)"!][!//
  [!VAR "cINMUX337"="number(substring-after(substring-before((substring-after($INMUX337,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 338*/!]
[!IF "contains($INMUX338, $mode_pin)"!][!//
  [!VAR "cINMUX338"="number(substring-after(substring-before((substring-after($INMUX338,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 339*/!]
[!IF "contains($INMUX339, $mode_pin)"!][!//
  [!VAR "cINMUX339"="number(substring-after(substring-before((substring-after($INMUX339,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 340*/!]
[!IF "contains($INMUX340, $mode_pin)"!][!//
  [!VAR "cINMUX340"="number(substring-after(substring-before((substring-after($INMUX340,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 341*/!]
[!IF "contains($INMUX341, $mode_pin)"!][!//
  [!VAR "cINMUX341"="number(substring-after(substring-before((substring-after($INMUX341,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 342*/!]
[!IF "contains($INMUX342, $mode_pin)"!][!//
  [!VAR "cINMUX342"="number(substring-after(substring-before((substring-after($INMUX342,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 343*/!]
[!IF "contains($INMUX343, $mode_pin)"!][!//
  [!VAR "cINMUX343"="number(substring-after(substring-before((substring-after($INMUX343,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 344*/!]
[!IF "contains($INMUX344, $mode_pin)"!][!//
  [!VAR "cINMUX344"="number(substring-after(substring-before((substring-after($INMUX344,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 345*/!]
[!IF "contains($INMUX345, $mode_pin)"!][!//
  [!VAR "cINMUX345"="number(substring-after(substring-before((substring-after($INMUX345,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 346*/!]
[!IF "contains($INMUX346, $mode_pin)"!][!//
  [!VAR "cINMUX346"="number(substring-after(substring-before((substring-after($INMUX346,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 347*/!]
[!IF "contains($INMUX347, $mode_pin)"!][!//
  [!VAR "cINMUX347"="number(substring-after(substring-before((substring-after($INMUX347,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 348*/!]
[!IF "contains($INMUX348, $mode_pin)"!][!//
  [!VAR "cINMUX348"="number(substring-after(substring-before((substring-after($INMUX348,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 349*/!]
[!IF "contains($INMUX349, $mode_pin)"!][!//
  [!VAR "cINMUX349"="number(substring-after(substring-before((substring-after($INMUX349,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 350*/!]
[!IF "contains($INMUX350, $mode_pin)"!][!//
  [!VAR "cINMUX350"="number(substring-after(substring-before((substring-after($INMUX350,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 351*/!]
[!IF "contains($INMUX351, $mode_pin)"!][!//
  [!VAR "cINMUX351"="number(substring-after(substring-before((substring-after($INMUX351,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 352*/!]
[!IF "contains($INMUX352, $mode_pin)"!][!//
  [!VAR "cINMUX352"="number(substring-after(substring-before((substring-after($INMUX352,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 353*/!]
[!IF "contains($INMUX353, $mode_pin)"!][!//
  [!VAR "cINMUX353"="number(substring-after(substring-before((substring-after($INMUX353,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 354*/!]
[!IF "contains($INMUX354, $mode_pin)"!][!//
  [!VAR "cINMUX354"="number(substring-after(substring-before((substring-after($INMUX354,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 355*/!]
[!IF "contains($INMUX355, $mode_pin)"!][!//
  [!VAR "cINMUX355"="number(substring-after(substring-before((substring-after($INMUX355,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 356*/!]
[!IF "contains($INMUX356, $mode_pin)"!][!//
  [!VAR "cINMUX356"="number(substring-after(substring-before((substring-after($INMUX356,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 357*/!]
[!IF "contains($INMUX357, $mode_pin)"!][!//
  [!VAR "cINMUX357"="number(substring-after(substring-before((substring-after($INMUX357,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 358*/!]
[!IF "contains($INMUX358, $mode_pin)"!][!//
  [!VAR "cINMUX358"="number(substring-after(substring-before((substring-after($INMUX358,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 359*/!]
[!IF "contains($INMUX359, $mode_pin)"!][!//
  [!VAR "cINMUX359"="number(substring-after(substring-before((substring-after($INMUX359,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 360*/!]
[!IF "contains($INMUX360, $mode_pin)"!][!//
  [!VAR "cINMUX360"="number(substring-after(substring-before((substring-after($INMUX360,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 361*/!]
[!IF "contains($INMUX361, $mode_pin)"!][!//
  [!VAR "cINMUX361"="number(substring-after(substring-before((substring-after($INMUX361,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 362*/!]
[!IF "contains($INMUX362, $mode_pin)"!][!//
  [!VAR "cINMUX362"="number(substring-after(substring-before((substring-after($INMUX362,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 363*/!]
[!IF "contains($INMUX363, $mode_pin)"!][!//
  [!VAR "cINMUX363"="number(substring-after(substring-before((substring-after($INMUX363,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 364*/!]
[!IF "contains($INMUX364, $mode_pin)"!][!//
  [!VAR "cINMUX364"="number(substring-after(substring-before((substring-after($INMUX364,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 365*/!]
[!IF "contains($INMUX365, $mode_pin)"!][!//
  [!VAR "cINMUX365"="number(substring-after(substring-before((substring-after($INMUX365,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 366*/!]
[!IF "contains($INMUX366, $mode_pin)"!][!//
  [!VAR "cINMUX366"="number(substring-after(substring-before((substring-after($INMUX366,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 367*/!]
[!IF "contains($INMUX367, $mode_pin)"!][!//
  [!VAR "cINMUX367"="number(substring-after(substring-before((substring-after($INMUX367,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 368*/!]
[!IF "contains($INMUX368, $mode_pin)"!][!//
  [!VAR "cINMUX368"="number(substring-after(substring-before((substring-after($INMUX368,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 369*/!]
[!IF "contains($INMUX369, $mode_pin)"!][!//
  [!VAR "cINMUX369"="number(substring-after(substring-before((substring-after($INMUX369,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 370*/!]
[!IF "contains($INMUX370, $mode_pin)"!][!//
  [!VAR "cINMUX370"="number(substring-after(substring-before((substring-after($INMUX370,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 371*/!]
[!IF "contains($INMUX371, $mode_pin)"!][!//
  [!VAR "cINMUX371"="number(substring-after(substring-before((substring-after($INMUX371,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 372*/!]
[!IF "contains($INMUX372, $mode_pin)"!][!//
  [!VAR "cINMUX372"="number(substring-after(substring-before((substring-after($INMUX372,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 373*/!]
[!IF "contains($INMUX373, $mode_pin)"!][!//
  [!VAR "cINMUX373"="number(substring-after(substring-before((substring-after($INMUX373,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 374*/!]
[!IF "contains($INMUX374, $mode_pin)"!][!//
  [!VAR "cINMUX374"="number(substring-after(substring-before((substring-after($INMUX374,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 375*/!]
[!IF "contains($INMUX375, $mode_pin)"!][!//
  [!VAR "cINMUX375"="number(substring-after(substring-before((substring-after($INMUX375,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 376*/!]
[!IF "contains($INMUX376, $mode_pin)"!][!//
  [!VAR "cINMUX376"="number(substring-after(substring-before((substring-after($INMUX376,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 377*/!]
[!IF "contains($INMUX377, $mode_pin)"!][!//
  [!VAR "cINMUX377"="number(substring-after(substring-before((substring-after($INMUX377,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 378*/!]
[!IF "contains($INMUX378, $mode_pin)"!][!//
  [!VAR "cINMUX378"="number(substring-after(substring-before((substring-after($INMUX378,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 379*/!]
[!IF "contains($INMUX379, $mode_pin)"!][!//
  [!VAR "cINMUX379"="number(substring-after(substring-before((substring-after($INMUX379,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 380*/!]
[!IF "contains($INMUX380, $mode_pin)"!][!//
  [!VAR "cINMUX380"="number(substring-after(substring-before((substring-after($INMUX380,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 381*/!]
[!IF "contains($INMUX381, $mode_pin)"!][!//
  [!VAR "cINMUX381"="number(substring-after(substring-before((substring-after($INMUX381,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 382*/!]
[!IF "contains($INMUX382, $mode_pin)"!][!//
  [!VAR "cINMUX382"="number(substring-after(substring-before((substring-after($INMUX382,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 383*/!]
[!IF "contains($INMUX383, $mode_pin)"!][!//
  [!VAR "cINMUX383"="number(substring-after(substring-before((substring-after($INMUX383,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 384*/!]
[!IF "contains($INMUX384, $mode_pin)"!][!//
  [!VAR "cINMUX384"="number(substring-after(substring-before((substring-after($INMUX384,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 385*/!]
[!IF "contains($INMUX385, $mode_pin)"!][!//
  [!VAR "cINMUX385"="number(substring-after(substring-before((substring-after($INMUX385,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 386*/!]
[!IF "contains($INMUX386, $mode_pin)"!][!//
  [!VAR "cINMUX386"="number(substring-after(substring-before((substring-after($INMUX386,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 387*/!]
[!IF "contains($INMUX387, $mode_pin)"!][!//
  [!VAR "cINMUX387"="number(substring-after(substring-before((substring-after($INMUX387,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 388*/!]
[!IF "contains($INMUX388, $mode_pin)"!][!//
  [!VAR "cINMUX388"="number(substring-after(substring-before((substring-after($INMUX388,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 389*/!]
[!IF "contains($INMUX389, $mode_pin)"!][!//
  [!VAR "cINMUX389"="number(substring-after(substring-before((substring-after($INMUX389,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 390*/!]
[!IF "contains($INMUX390, $mode_pin)"!][!//
  [!VAR "cINMUX390"="number(substring-after(substring-before((substring-after($INMUX390,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 391*/!]
[!IF "contains($INMUX391, $mode_pin)"!][!//
  [!VAR "cINMUX391"="number(substring-after(substring-before((substring-after($INMUX391,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 392*/!]
[!IF "contains($INMUX392, $mode_pin)"!][!//
  [!VAR "cINMUX392"="number(substring-after(substring-before((substring-after($INMUX392,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 393*/!]
[!IF "contains($INMUX393, $mode_pin)"!][!//
  [!VAR "cINMUX393"="number(substring-after(substring-before((substring-after($INMUX393,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 394*/!]
[!IF "contains($INMUX394, $mode_pin)"!][!//
  [!VAR "cINMUX394"="number(substring-after(substring-before((substring-after($INMUX394,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 395*/!]
[!IF "contains($INMUX395, $mode_pin)"!][!//
  [!VAR "cINMUX395"="number(substring-after(substring-before((substring-after($INMUX395,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 396*/!]
[!IF "contains($INMUX396, $mode_pin)"!][!//
  [!VAR "cINMUX396"="number(substring-after(substring-before((substring-after($INMUX396,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 397*/!]
[!IF "contains($INMUX397, $mode_pin)"!][!//
  [!VAR "cINMUX397"="number(substring-after(substring-before((substring-after($INMUX397,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 398*/!]
[!IF "contains($INMUX398, $mode_pin)"!][!//
  [!VAR "cINMUX398"="number(substring-after(substring-before((substring-after($INMUX398,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 399*/!]
[!IF "contains($INMUX399, $mode_pin)"!][!//
  [!VAR "cINMUX399"="number(substring-after(substring-before((substring-after($INMUX399,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 400*/!]
[!IF "contains($INMUX400, $mode_pin)"!][!//
  [!VAR "cINMUX400"="number(substring-after(substring-before((substring-after($INMUX400,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 401*/!]
[!IF "contains($INMUX401, $mode_pin)"!][!//
  [!VAR "cINMUX401"="number(substring-after(substring-before((substring-after($INMUX401,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 402*/!]
[!IF "contains($INMUX402, $mode_pin)"!][!//
  [!VAR "cINMUX402"="number(substring-after(substring-before((substring-after($INMUX402,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 403*/!]
[!IF "contains($INMUX403, $mode_pin)"!][!//
  [!VAR "cINMUX403"="number(substring-after(substring-before((substring-after($INMUX403,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 404*/!]
[!IF "contains($INMUX404, $mode_pin)"!][!//
  [!VAR "cINMUX404"="number(substring-after(substring-before((substring-after($INMUX404,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 405*/!]
[!IF "contains($INMUX405, $mode_pin)"!][!//
  [!VAR "cINMUX405"="number(substring-after(substring-before((substring-after($INMUX405,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 406*/!]
[!IF "contains($INMUX406, $mode_pin)"!][!//
  [!VAR "cINMUX406"="number(substring-after(substring-before((substring-after($INMUX406,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 407*/!]
[!IF "contains($INMUX407, $mode_pin)"!][!//
  [!VAR "cINMUX407"="number(substring-after(substring-before((substring-after($INMUX407,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 408*/!]
[!IF "contains($INMUX408, $mode_pin)"!][!//
  [!VAR "cINMUX408"="number(substring-after(substring-before((substring-after($INMUX408,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 409*/!]
[!IF "contains($INMUX409, $mode_pin)"!][!//
  [!VAR "cINMUX409"="number(substring-after(substring-before((substring-after($INMUX409,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 410*/!]
[!IF "contains($INMUX410, $mode_pin)"!][!//
  [!VAR "cINMUX410"="number(substring-after(substring-before((substring-after($INMUX410,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 411*/!]
[!IF "contains($INMUX411, $mode_pin)"!][!//
  [!VAR "cINMUX411"="number(substring-after(substring-before((substring-after($INMUX411,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 412*/!]
[!IF "contains($INMUX412, $mode_pin)"!][!//
  [!VAR "cINMUX412"="number(substring-after(substring-before((substring-after($INMUX412,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 413*/!]
[!IF "contains($INMUX413, $mode_pin)"!][!//
  [!VAR "cINMUX413"="number(substring-after(substring-before((substring-after($INMUX413,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 414*/!]
[!IF "contains($INMUX414, $mode_pin)"!][!//
  [!VAR "cINMUX414"="number(substring-after(substring-before((substring-after($INMUX414,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 415*/!]
[!IF "contains($INMUX415, $mode_pin)"!][!//
  [!VAR "cINMUX415"="number(substring-after(substring-before((substring-after($INMUX415,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 416*/!]
[!IF "contains($INMUX416, $mode_pin)"!][!//
  [!VAR "cINMUX416"="number(substring-after(substring-before((substring-after($INMUX416,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 417*/!]
[!IF "contains($INMUX417, $mode_pin)"!][!//
  [!VAR "cINMUX417"="number(substring-after(substring-before((substring-after($INMUX417,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 418*/!]
[!IF "contains($INMUX418, $mode_pin)"!][!//
  [!VAR "cINMUX418"="number(substring-after(substring-before((substring-after($INMUX418,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 419*/!]
[!IF "contains($INMUX419, $mode_pin)"!][!//
  [!VAR "cINMUX419"="number(substring-after(substring-before((substring-after($INMUX419,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 420*/!]
[!IF "contains($INMUX420, $mode_pin)"!][!//
  [!VAR "cINMUX420"="number(substring-after(substring-before((substring-after($INMUX420,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 421*/!]
[!IF "contains($INMUX421, $mode_pin)"!][!//
  [!VAR "cINMUX421"="number(substring-after(substring-before((substring-after($INMUX421,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 422*/!]
[!IF "contains($INMUX422, $mode_pin)"!][!//
  [!VAR "cINMUX422"="number(substring-after(substring-before((substring-after($INMUX422,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 423*/!]
[!IF "contains($INMUX423, $mode_pin)"!][!//
  [!VAR "cINMUX423"="number(substring-after(substring-before((substring-after($INMUX423,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 424*/!]
[!IF "contains($INMUX424, $mode_pin)"!][!//
  [!VAR "cINMUX424"="number(substring-after(substring-before((substring-after($INMUX424,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 425*/!]
[!IF "contains($INMUX425, $mode_pin)"!][!//
  [!VAR "cINMUX425"="number(substring-after(substring-before((substring-after($INMUX425,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 426*/!]
[!IF "contains($INMUX426, $mode_pin)"!][!//
  [!VAR "cINMUX426"="number(substring-after(substring-before((substring-after($INMUX426,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 427*/!]
[!IF "contains($INMUX427, $mode_pin)"!][!//
  [!VAR "cINMUX427"="number(substring-after(substring-before((substring-after($INMUX427,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 428*/!]
[!IF "contains($INMUX428, $mode_pin)"!][!//
  [!VAR "cINMUX428"="number(substring-after(substring-before((substring-after($INMUX428,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 429*/!]
[!IF "contains($INMUX429, $mode_pin)"!][!//
  [!VAR "cINMUX429"="number(substring-after(substring-before((substring-after($INMUX429,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 430*/!]
[!IF "contains($INMUX430, $mode_pin)"!][!//
  [!VAR "cINMUX430"="number(substring-after(substring-before((substring-after($INMUX430,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 431*/!]
[!IF "contains($INMUX431, $mode_pin)"!][!//
  [!VAR "cINMUX431"="number(substring-after(substring-before((substring-after($INMUX431,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 432*/!]
[!IF "contains($INMUX432, $mode_pin)"!][!//
  [!VAR "cINMUX432"="number(substring-after(substring-before((substring-after($INMUX432,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 433*/!]
[!IF "contains($INMUX433, $mode_pin)"!][!//
  [!VAR "cINMUX433"="number(substring-after(substring-before((substring-after($INMUX433,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 434*/!]
[!IF "contains($INMUX434, $mode_pin)"!][!//
  [!VAR "cINMUX434"="number(substring-after(substring-before((substring-after($INMUX434,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 435*/!]
[!IF "contains($INMUX435, $mode_pin)"!][!//
  [!VAR "cINMUX435"="number(substring-after(substring-before((substring-after($INMUX435,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 436*/!]
[!IF "contains($INMUX436, $mode_pin)"!][!//
  [!VAR "cINMUX436"="number(substring-after(substring-before((substring-after($INMUX436,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 437*/!]
[!IF "contains($INMUX437, $mode_pin)"!][!//
  [!VAR "cINMUX437"="number(substring-after(substring-before((substring-after($INMUX437,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 438*/!]
[!IF "contains($INMUX438, $mode_pin)"!][!//
  [!VAR "cINMUX438"="number(substring-after(substring-before((substring-after($INMUX438,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 439*/!]
[!IF "contains($INMUX439, $mode_pin)"!][!//
  [!VAR "cINMUX439"="number(substring-after(substring-before((substring-after($INMUX439,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 440*/!]
[!IF "contains($INMUX440, $mode_pin)"!][!//
  [!VAR "cINMUX440"="number(substring-after(substring-before((substring-after($INMUX440,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 441*/!]
[!IF "contains($INMUX441, $mode_pin)"!][!//
  [!VAR "cINMUX441"="number(substring-after(substring-before((substring-after($INMUX441,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 442*/!]
[!IF "contains($INMUX442, $mode_pin)"!][!//
  [!VAR "cINMUX442"="number(substring-after(substring-before((substring-after($INMUX442,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 443*/!]
[!IF "contains($INMUX443, $mode_pin)"!][!//
  [!VAR "cINMUX443"="number(substring-after(substring-before((substring-after($INMUX443,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 444*/!]
[!IF "contains($INMUX444, $mode_pin)"!][!//
  [!VAR "cINMUX444"="number(substring-after(substring-before((substring-after($INMUX444,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 445*/!]
[!IF "contains($INMUX445, $mode_pin)"!][!//
  [!VAR "cINMUX445"="number(substring-after(substring-before((substring-after($INMUX445,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 446*/!]
[!IF "contains($INMUX446, $mode_pin)"!][!//
  [!VAR "cINMUX446"="number(substring-after(substring-before((substring-after($INMUX446,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 447*/!]
[!IF "contains($INMUX447, $mode_pin)"!][!//
  [!VAR "cINMUX447"="number(substring-after(substring-before((substring-after($INMUX447,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 448*/!]
[!IF "contains($INMUX448, $mode_pin)"!][!//
  [!VAR "cINMUX448"="number(substring-after(substring-before((substring-after($INMUX448,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 449*/!]
[!IF "contains($INMUX449, $mode_pin)"!][!//
  [!VAR "cINMUX449"="number(substring-after(substring-before((substring-after($INMUX449,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 450*/!]
[!IF "contains($INMUX450, $mode_pin)"!][!//
  [!VAR "cINMUX450"="number(substring-after(substring-before((substring-after($INMUX450,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 451*/!]
[!IF "contains($INMUX451, $mode_pin)"!][!//
  [!VAR "cINMUX451"="number(substring-after(substring-before((substring-after($INMUX451,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 452*/!]
[!IF "contains($INMUX452, $mode_pin)"!][!//
  [!VAR "cINMUX452"="number(substring-after(substring-before((substring-after($INMUX452,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 453*/!]
[!IF "contains($INMUX453, $mode_pin)"!][!//
  [!VAR "cINMUX453"="number(substring-after(substring-before((substring-after($INMUX453,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 454*/!]
[!IF "contains($INMUX454, $mode_pin)"!][!//
  [!VAR "cINMUX454"="number(substring-after(substring-before((substring-after($INMUX454,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 455*/!]
[!IF "contains($INMUX455, $mode_pin)"!][!//
  [!VAR "cINMUX455"="number(substring-after(substring-before((substring-after($INMUX455,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 456*/!]
[!IF "contains($INMUX456, $mode_pin)"!][!//
  [!VAR "cINMUX456"="number(substring-after(substring-before((substring-after($INMUX456,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 457*/!]
[!IF "contains($INMUX457, $mode_pin)"!][!//
  [!VAR "cINMUX457"="number(substring-after(substring-before((substring-after($INMUX457,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 458*/!]
[!IF "contains($INMUX458, $mode_pin)"!][!//
  [!VAR "cINMUX458"="number(substring-after(substring-before((substring-after($INMUX458,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 459*/!]
[!IF "contains($INMUX459, $mode_pin)"!][!//
  [!VAR "cINMUX459"="number(substring-after(substring-before((substring-after($INMUX459,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 460*/!]
[!IF "contains($INMUX460, $mode_pin)"!][!//
  [!VAR "cINMUX460"="number(substring-after(substring-before((substring-after($INMUX460,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 461*/!]
[!IF "contains($INMUX461, $mode_pin)"!][!//
  [!VAR "cINMUX461"="number(substring-after(substring-before((substring-after($INMUX461,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 462*/!]
[!IF "contains($INMUX462, $mode_pin)"!][!//
  [!VAR "cINMUX462"="number(substring-after(substring-before((substring-after($INMUX462,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 463*/!]
[!IF "contains($INMUX463, $mode_pin)"!][!//
  [!VAR "cINMUX463"="number(substring-after(substring-before((substring-after($INMUX463,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 464*/!]
[!IF "contains($INMUX464, $mode_pin)"!][!//
  [!VAR "cINMUX464"="number(substring-after(substring-before((substring-after($INMUX464,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 465*/!]
[!IF "contains($INMUX465, $mode_pin)"!][!//
  [!VAR "cINMUX465"="number(substring-after(substring-before((substring-after($INMUX465,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 466*/!]
[!IF "contains($INMUX466, $mode_pin)"!][!//
  [!VAR "cINMUX466"="number(substring-after(substring-before((substring-after($INMUX466,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 467*/!]
[!IF "contains($INMUX467, $mode_pin)"!][!//
  [!VAR "cINMUX467"="number(substring-after(substring-before((substring-after($INMUX467,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 468*/!]
[!IF "contains($INMUX468, $mode_pin)"!][!//
  [!VAR "cINMUX468"="number(substring-after(substring-before((substring-after($INMUX468,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 469*/!]
[!IF "contains($INMUX469, $mode_pin)"!][!//
  [!VAR "cINMUX469"="number(substring-after(substring-before((substring-after($INMUX469,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 470*/!]
[!IF "contains($INMUX470, $mode_pin)"!][!//
  [!VAR "cINMUX470"="number(substring-after(substring-before((substring-after($INMUX470,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 471*/!]
[!IF "contains($INMUX471, $mode_pin)"!][!//
  [!VAR "cINMUX471"="number(substring-after(substring-before((substring-after($INMUX471,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 472*/!]
[!IF "contains($INMUX472, $mode_pin)"!][!//
  [!VAR "cINMUX472"="number(substring-after(substring-before((substring-after($INMUX472,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 473*/!]
[!IF "contains($INMUX473, $mode_pin)"!][!//
  [!VAR "cINMUX473"="number(substring-after(substring-before((substring-after($INMUX473,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 474*/!]
[!IF "contains($INMUX474, $mode_pin)"!][!//
  [!VAR "cINMUX474"="number(substring-after(substring-before((substring-after($INMUX474,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 475*/!]
[!IF "contains($INMUX475, $mode_pin)"!][!//
  [!VAR "cINMUX475"="number(substring-after(substring-before((substring-after($INMUX475,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 476*/!]
[!IF "contains($INMUX476, $mode_pin)"!][!//
  [!VAR "cINMUX476"="number(substring-after(substring-before((substring-after($INMUX476,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 477*/!]
[!IF "contains($INMUX477, $mode_pin)"!][!//
  [!VAR "cINMUX477"="number(substring-after(substring-before((substring-after($INMUX477,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 478*/!]
[!IF "contains($INMUX478, $mode_pin)"!][!//
  [!VAR "cINMUX478"="number(substring-after(substring-before((substring-after($INMUX478,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 479*/!]
[!IF "contains($INMUX479, $mode_pin)"!][!//
  [!VAR "cINMUX479"="number(substring-after(substring-before((substring-after($INMUX479,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 480*/!]
[!IF "contains($INMUX480, $mode_pin)"!][!//
  [!VAR "cINMUX480"="number(substring-after(substring-before((substring-after($INMUX480,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 481*/!]
[!IF "contains($INMUX481, $mode_pin)"!][!//
  [!VAR "cINMUX481"="number(substring-after(substring-before((substring-after($INMUX481,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 482*/!]
[!IF "contains($INMUX482, $mode_pin)"!][!//
  [!VAR "cINMUX482"="number(substring-after(substring-before((substring-after($INMUX482,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 483*/!]
[!IF "contains($INMUX483, $mode_pin)"!][!//
  [!VAR "cINMUX483"="number(substring-after(substring-before((substring-after($INMUX483,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 484*/!]
[!IF "contains($INMUX484, $mode_pin)"!][!//
  [!VAR "cINMUX484"="number(substring-after(substring-before((substring-after($INMUX484,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 485*/!]
[!IF "contains($INMUX485, $mode_pin)"!][!//
  [!VAR "cINMUX485"="number(substring-after(substring-before((substring-after($INMUX485,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 486*/!]
[!IF "contains($INMUX486, $mode_pin)"!][!//
  [!VAR "cINMUX486"="number(substring-after(substring-before((substring-after($INMUX486,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 487*/!]
[!IF "contains($INMUX487, $mode_pin)"!][!//
  [!VAR "cINMUX487"="number(substring-after(substring-before((substring-after($INMUX487,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 488*/!]
[!IF "contains($INMUX488, $mode_pin)"!][!//
  [!VAR "cINMUX488"="number(substring-after(substring-before((substring-after($INMUX488,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 489*/!]
[!IF "contains($INMUX489, $mode_pin)"!][!//
  [!VAR "cINMUX489"="number(substring-after(substring-before((substring-after($INMUX489,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 490*/!]
[!IF "contains($INMUX490, $mode_pin)"!][!//
  [!VAR "cINMUX490"="number(substring-after(substring-before((substring-after($INMUX490,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 491*/!]
[!IF "contains($INMUX491, $mode_pin)"!][!//
  [!VAR "cINMUX491"="number(substring-after(substring-before((substring-after($INMUX491,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 492*/!]
[!IF "contains($INMUX492, $mode_pin)"!][!//
  [!VAR "cINMUX492"="number(substring-after(substring-before((substring-after($INMUX492,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 493*/!]
[!IF "contains($INMUX493, $mode_pin)"!][!//
  [!VAR "cINMUX493"="number(substring-after(substring-before((substring-after($INMUX493,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 494*/!]
[!IF "contains($INMUX494, $mode_pin)"!][!//
  [!VAR "cINMUX494"="number(substring-after(substring-before((substring-after($INMUX494,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 495*/!]
[!IF "contains($INMUX495, $mode_pin)"!][!//
  [!VAR "cINMUX495"="number(substring-after(substring-before((substring-after($INMUX495,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 496*/!]
[!IF "contains($INMUX496, $mode_pin)"!][!//
  [!VAR "cINMUX496"="number(substring-after(substring-before((substring-after($INMUX496,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 497*/!]
[!IF "contains($INMUX497, $mode_pin)"!][!//
  [!VAR "cINMUX497"="number(substring-after(substring-before((substring-after($INMUX497,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 498*/!]
[!IF "contains($INMUX498, $mode_pin)"!][!//
  [!VAR "cINMUX498"="number(substring-after(substring-before((substring-after($INMUX498,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 499*/!]
[!IF "contains($INMUX499, $mode_pin)"!][!//
  [!VAR "cINMUX499"="number(substring-after(substring-before((substring-after($INMUX499,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 500*/!]
[!IF "contains($INMUX500, $mode_pin)"!][!//
  [!VAR "cINMUX500"="number(substring-after(substring-before((substring-after($INMUX500,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 501*/!]
[!IF "contains($INMUX501, $mode_pin)"!][!//
  [!VAR "cINMUX501"="number(substring-after(substring-before((substring-after($INMUX501,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 502*/!]
[!IF "contains($INMUX502, $mode_pin)"!][!//
  [!VAR "cINMUX502"="number(substring-after(substring-before((substring-after($INMUX502,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 503*/!]
[!IF "contains($INMUX503, $mode_pin)"!][!//
  [!VAR "cINMUX503"="number(substring-after(substring-before((substring-after($INMUX503,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 504*/!]
[!IF "contains($INMUX504, $mode_pin)"!][!//
  [!VAR "cINMUX504"="number(substring-after(substring-before((substring-after($INMUX504,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 505*/!]
[!IF "contains($INMUX505, $mode_pin)"!][!//
  [!VAR "cINMUX505"="number(substring-after(substring-before((substring-after($INMUX505,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 506*/!]
[!IF "contains($INMUX506, $mode_pin)"!][!//
  [!VAR "cINMUX506"="number(substring-after(substring-before((substring-after($INMUX506,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 507*/!]
[!IF "contains($INMUX507, $mode_pin)"!][!//
  [!VAR "cINMUX507"="number(substring-after(substring-before((substring-after($INMUX507,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 508*/!]
[!IF "contains($INMUX508, $mode_pin)"!][!//
  [!VAR "cINMUX508"="number(substring-after(substring-before((substring-after($INMUX508,$mode_pin)),':'),';'))"!][!//
[!ENDIF!][!//
[!/* INMUX 509*/!]
[!IF "((ecu:get('PortCalypsoFamily')) ='3')"!]
    [!IF "contains($INMUX509, $mode_pin)"!][!//
        [!VAR "cINMUX509"="number(substring-after(substring-before((substring-after($INMUX509,$mode_pin)),':'),';'))"!][!//
    [!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
    (uint32)[!"num:inttohex($cINMUX0, 8)"!],
    (uint32)[!"num:inttohex($cINMUX1, 8)"!],
    (uint32)[!"num:inttohex($cINMUX2, 8)"!],
    (uint32)[!"num:inttohex($cINMUX3, 8)"!],
    (uint32)[!"num:inttohex($cINMUX4, 8)"!],
    (uint32)[!"num:inttohex($cINMUX5, 8)"!],
    (uint32)[!"num:inttohex($cINMUX6, 8)"!],
    (uint32)[!"num:inttohex($cINMUX7, 8)"!],
    (uint32)[!"num:inttohex($cINMUX8, 8)"!],
    (uint32)[!"num:inttohex($cINMUX9, 8)"!],
    (uint32)[!"num:inttohex($cINMUX10, 8)"!],
    (uint32)[!"num:inttohex($cINMUX11, 8)"!],
    (uint32)[!"num:inttohex($cINMUX12, 8)"!],
    (uint32)[!"num:inttohex($cINMUX13, 8)"!],
    (uint32)[!"num:inttohex($cINMUX14, 8)"!],
    (uint32)[!"num:inttohex($cINMUX15, 8)"!],
    (uint32)[!"num:inttohex($cINMUX16, 8)"!],
    (uint32)[!"num:inttohex($cINMUX17, 8)"!],
    (uint32)[!"num:inttohex($cINMUX18, 8)"!],
    (uint32)[!"num:inttohex($cINMUX19, 8)"!],
    (uint32)[!"num:inttohex($cINMUX20, 8)"!],
    (uint32)[!"num:inttohex($cINMUX21, 8)"!],
    (uint32)[!"num:inttohex($cINMUX22, 8)"!],
    (uint32)[!"num:inttohex($cINMUX23, 8)"!],
    (uint32)[!"num:inttohex($cINMUX24, 8)"!],
    (uint32)[!"num:inttohex($cINMUX25, 8)"!],
    (uint32)[!"num:inttohex($cINMUX26, 8)"!],
    (uint32)[!"num:inttohex($cINMUX27, 8)"!],
    (uint32)[!"num:inttohex($cINMUX28, 8)"!],
    (uint32)[!"num:inttohex($cINMUX29, 8)"!],
    (uint32)[!"num:inttohex($cINMUX30, 8)"!],
    (uint32)[!"num:inttohex($cINMUX31, 8)"!],
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)[!"num:inttohex($cINMUX36, 8)"!],
    (uint32)[!"num:inttohex($cINMUX37, 8)"!],
    (uint32)[!"num:inttohex($cINMUX38, 8)"!],
    (uint32)[!"num:inttohex($cINMUX39, 8)"!],
    (uint32)[!"num:inttohex($cINMUX40, 8)"!],
    (uint32)[!"num:inttohex($cINMUX41, 8)"!],
    (uint32)[!"num:inttohex($cINMUX42, 8)"!],
    (uint32)[!"num:inttohex($cINMUX43, 8)"!],
    (uint32)[!"num:inttohex($cINMUX44, 8)"!],
    (uint32)[!"num:inttohex($cINMUX45, 8)"!],
    (uint32)[!"num:inttohex($cINMUX46, 8)"!],
    (uint32)[!"num:inttohex($cINMUX47, 8)"!],
    (uint32)[!"num:inttohex($cINMUX48, 8)"!],
    (uint32)[!"num:inttohex($cINMUX49, 8)"!],
    (uint32)[!"num:inttohex($cINMUX50, 8)"!],
    (uint32)[!"num:inttohex($cINMUX51, 8)"!],
    (uint32)[!"num:inttohex($cINMUX52, 8)"!],
    (uint32)[!"num:inttohex($cINMUX53, 8)"!],
    (uint32)[!"num:inttohex($cINMUX54, 8)"!],
    (uint32)[!"num:inttohex($cINMUX55, 8)"!],
    (uint32)[!"num:inttohex($cINMUX56, 8)"!],
    (uint32)[!"num:inttohex($cINMUX57, 8)"!],
    (uint32)[!"num:inttohex($cINMUX58, 8)"!],
    (uint32)[!"num:inttohex($cINMUX59, 8)"!],
    (uint32)[!"num:inttohex($cINMUX60, 8)"!],
    (uint32)[!"num:inttohex($cINMUX61, 8)"!],
    (uint32)[!"num:inttohex($cINMUX62, 8)"!],
    (uint32)[!"num:inttohex($cINMUX63, 8)"!],
    (uint32)[!"num:inttohex($cINMUX64, 8)"!],
    (uint32)[!"num:inttohex($cINMUX65, 8)"!],
    (uint32)[!"num:inttohex($cINMUX66, 8)"!],
    (uint32)[!"num:inttohex($cINMUX67, 8)"!],
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX72, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX73, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX74, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX75, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX76, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX77, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX78, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX79, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX80, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX81, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX82, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX83, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX84, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX85, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX86, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX87, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX88, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX89, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX90, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX91, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX92, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX93, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX94, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX95, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX96, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX97, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX98, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX99, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX100, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX101, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX102, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX103, 8)"!],[!ENDIF!]
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
    (uint32)[!"num:inttohex($cINMUX144, 8)"!],
    (uint32)[!"num:inttohex($cINMUX145, 8)"!],
    (uint32)[!"num:inttohex($cINMUX146, 8)"!],
    (uint32)[!"num:inttohex($cINMUX147, 8)"!],
    (uint32)[!"num:inttohex($cINMUX148, 8)"!],
    (uint32)[!"num:inttohex($cINMUX149, 8)"!],
    (uint32)[!"num:inttohex($cINMUX150, 8)"!],
    (uint32)[!"num:inttohex($cINMUX151, 8)"!],
    (uint32)[!"num:inttohex($cINMUX152, 8)"!],
    (uint32)[!"num:inttohex($cINMUX153, 8)"!],
    (uint32)[!"num:inttohex($cINMUX154, 8)"!],
    (uint32)[!"num:inttohex($cINMUX155, 8)"!],
    (uint32)[!"num:inttohex($cINMUX156, 8)"!],
    (uint32)[!"num:inttohex($cINMUX157, 8)"!],
    (uint32)[!"num:inttohex($cINMUX158, 8)"!],
    (uint32)[!"num:inttohex($cINMUX159, 8)"!],
    (uint32)[!"num:inttohex($cINMUX160, 8)"!],
    (uint32)[!"num:inttohex($cINMUX161, 8)"!],
    (uint32)[!"num:inttohex($cINMUX162, 8)"!],
    (uint32)[!"num:inttohex($cINMUX163, 8)"!],
    (uint32)[!"num:inttohex($cINMUX164, 8)"!],
    (uint32)[!"num:inttohex($cINMUX165, 8)"!],
    (uint32)[!"num:inttohex($cINMUX166, 8)"!],
    (uint32)[!"num:inttohex($cINMUX167, 8)"!],
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX168, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX169, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX170, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX171, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX172, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX173, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX174, 8)"!],[!ENDIF!]
    (uint32)[!"num:inttohex($cINMUX175, 8)"!],
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
    (uint32)[!"num:inttohex($cINMUX188, 8)"!],
    (uint32)[!"num:inttohex($cINMUX189, 8)"!],
    (uint32)[!"num:inttohex($cINMUX190, 8)"!],
    (uint32)[!"num:inttohex($cINMUX191, 8)"!],
    (uint32)[!"num:inttohex($cINMUX192, 8)"!],
    (uint32)[!"num:inttohex($cINMUX193, 8)"!],
    (uint32)[!"num:inttohex($cINMUX194, 8)"!],
    (uint32)[!"num:inttohex($cINMUX195, 8)"!],
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)[!"num:inttohex($cINMUX200, 8)"!],
    (uint32)[!"num:inttohex($cINMUX201, 8)"!],
    (uint32)[!"num:inttohex($cINMUX202, 8)"!],
    (uint32)[!"num:inttohex($cINMUX203, 8)"!],
    (uint32)[!"num:inttohex($cINMUX204, 8)"!],
    (uint32)[!"num:inttohex($cINMUX205, 8)"!],
    (uint32)[!"num:inttohex($cINMUX206, 8)"!],
    (uint32)[!"num:inttohex($cINMUX207, 8)"!],
    (uint32)[!"num:inttohex($cINMUX208, 8)"!],
    (uint32)[!"num:inttohex($cINMUX209, 8)"!],
    (uint32)[!"num:inttohex($cINMUX210, 8)"!],
    (uint32)[!"num:inttohex($cINMUX211, 8)"!],
    (uint32)[!"num:inttohex($cINMUX212, 8)"!],
    (uint32)[!"num:inttohex($cINMUX213, 8)"!],
    (uint32)[!"num:inttohex($cINMUX214, 8)"!],
    (uint32)[!"num:inttohex($cINMUX215, 8)"!],
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX216, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX217, 8)"!],[!ENDIF!]
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)[!"num:inttohex($cINMUX224, 8)"!],
    (uint32)[!"num:inttohex($cINMUX225, 8)"!],
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX232, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX233, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX234, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX235, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX236, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX237, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX238, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX239, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX240, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX241, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX242, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX243, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX244, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX245, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX246, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX247, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX248, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX249, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX250, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX251, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX252, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX253, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX254, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX255, 8)"!],[!ENDIF!]
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)[!"num:inttohex($cINMUX265, 8)"!],
    (uint32)[!"num:inttohex($cINMUX266, 8)"!],
    (uint32)[!"num:inttohex($cINMUX267, 8)"!],
    (uint32)[!"num:inttohex($cINMUX268, 8)"!],
    (uint32)[!"num:inttohex($cINMUX269, 8)"!],
    (uint32)[!"num:inttohex($cINMUX270, 8)"!],
    (uint32)[!"num:inttohex($cINMUX271, 8)"!],
    (uint32)[!"num:inttohex($cINMUX272, 8)"!],
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
    (uint32)[!"num:inttohex($cINMUX288, 8)"!],
    (uint32)[!"num:inttohex($cINMUX289, 8)"!],
    (uint32)[!"num:inttohex($cINMUX290, 8)"!],
    (uint32)[!"num:inttohex($cINMUX291, 8)"!],
    (uint32)[!"num:inttohex($cINMUX292, 8)"!],
    (uint32)[!"num:inttohex($cINMUX293, 8)"!],
    (uint32)[!"num:inttohex($cINMUX294, 8)"!],
    (uint32)[!"num:inttohex($cINMUX295, 8)"!],
    (uint32)[!"num:inttohex($cINMUX296, 8)"!],
    (uint32)[!"num:inttohex($cINMUX297, 8)"!],
    (uint32)[!"num:inttohex($cINMUX298, 8)"!],
    (uint32)[!"num:inttohex($cINMUX299, 8)"!],
    (uint32)[!"num:inttohex($cINMUX300, 8)"!],
    (uint32)[!"num:inttohex($cINMUX301, 8)"!],
    (uint32)[!"num:inttohex($cINMUX302, 8)"!],
    (uint32)[!"num:inttohex($cINMUX303, 8)"!],
    (uint32)[!"num:inttohex($cINMUX304, 8)"!],
    (uint32)[!"num:inttohex($cINMUX305, 8)"!],
    (uint32)[!"num:inttohex($cINMUX306, 8)"!],
    (uint32)[!"num:inttohex($cINMUX307, 8)"!],
    (uint32)[!"num:inttohex($cINMUX308, 8)"!],
    (uint32)[!"num:inttohex($cINMUX309, 8)"!],
    (uint32)[!"num:inttohex($cINMUX310, 8)"!],
    (uint32)[!"num:inttohex($cINMUX311, 8)"!],
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX312, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX313, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX314, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX315, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX316, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX317, 8)"!],[!ENDIF!]
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
    (uint32)[!"num:inttohex($cINMUX329, 8)"!],
    (uint32)[!"num:inttohex($cINMUX330, 8)"!],
    (uint32)[!"num:inttohex($cINMUX331, 8)"!],
    (uint32)0xFFFFFFFFU,
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX333, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX334, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX335, 8)"!],[!ENDIF!]
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
    (uint32)[!"num:inttohex($cINMUX448, 8)"!],
    (uint32)[!"num:inttohex($cINMUX449, 8)"!],
    (uint32)[!"num:inttohex($cINMUX450, 8)"!],
    (uint32)[!"num:inttohex($cINMUX451, 8)"!],
    (uint32)[!"num:inttohex($cINMUX452, 8)"!],
    (uint32)[!"num:inttohex($cINMUX453, 8)"!],
    (uint32)[!"num:inttohex($cINMUX454, 8)"!],
    (uint32)[!"num:inttohex($cINMUX455, 8)"!],
    (uint32)[!"num:inttohex($cINMUX456, 8)"!],
    (uint32)[!"num:inttohex($cINMUX457, 8)"!],
    (uint32)[!"num:inttohex($cINMUX458, 8)"!],
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX459, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX460, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX461, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX462, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX463, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX464, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX465, 8)"!],[!ENDIF!]
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX468, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX469, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX470, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX471, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX472, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX473, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX474, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX475, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX476, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX477, 8)"!],[!ENDIF!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!](uint32)0xFFFFFFFFU,[!ELSE!](uint32)[!"num:inttohex($cINMUX478, 8)"!],[!ENDIF!]
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)[!"num:inttohex($cINMUX488, 8)"!],
    (uint32)[!"num:inttohex($cINMUX489, 8)"!],
    (uint32)[!"num:inttohex($cINMUX490, 8)"!],
    (uint32)[!"num:inttohex($cINMUX491, 8)"!],
    (uint32)[!"num:inttohex($cINMUX492, 8)"!],
    (uint32)[!"num:inttohex($cINMUX493, 8)"!],
    (uint32)[!"num:inttohex($cINMUX494, 8)"!],
    (uint32)[!"num:inttohex($cINMUX495, 8)"!],
    (uint32)[!"num:inttohex($cINMUX496, 8)"!],
    (uint32)[!"num:inttohex($cINMUX497, 8)"!],
    (uint32)[!"num:inttohex($cINMUX498, 8)"!],
    (uint32)0xFFFFFFFFU,
    (uint32)0xFFFFFFFFU,
    (uint32)[!"num:inttohex($cINMUX501, 8)"!],
    (uint32)[!"num:inttohex($cINMUX502, 8)"!],
    (uint32)[!"num:inttohex($cINMUX503, 8)"!],
    (uint32)[!"num:inttohex($cINMUX504, 8)"!],
    (uint32)[!"num:inttohex($cINMUX505, 8)"!],
    (uint32)[!"num:inttohex($cINMUX506, 8)"!],
    (uint32)[!"num:inttohex($cINMUX507, 8)"!],
    (uint32)[!"num:inttohex($cINMUX508, 8)"!]
    [!IF "((ecu:get('PortCalypsoFamily')) ='3')"!],(uint32)[!"num:inttohex($cINMUX509, 8)"!][!ENDIF!]
};
[!ENDSELECT!][!//

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

[!/*****************************************************************************/!][!//
[!SELECT "PortConfigSet"!][!//
[!VAR "counter"="0"!][!//
/**
* @brief This table contains all the Configured Port Pin parameters and the
*        number of Port Pins configured by the tool for the post-build mode
* @violates @ref PORT_PBCFG_REF_4 Violates MISRA 2004 Required Rule 8.10
*/
[!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
CONST(Port_ConfigType, PORT_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ELSE!]
CONST(Port_ConfigType, PORT_CONST) Port_PBCfgVariantPredefined =
[!ENDIF!]
{
    PORT_MAX_CONFIGURED_PADS_U16,
    PORT_MAX_UNUSED_PADS_U16,
#if (PORT_MAX_UNUSED_PADS_U16 != 0U)
    Port_au16NoUnUsedPadsArrayDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#else
    NULL_PTR,
#endif
    &Port_UnUsedPin[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Port_aPinConfigDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    Port_aPadSelConfigDefault[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDSELECT!][!//

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
[!ENDCODE!][!//
