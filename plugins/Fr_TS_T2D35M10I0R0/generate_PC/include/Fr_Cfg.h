/**
*   @file       Fr_Cfg.h
*   @implements Fr_Cfg.h_Artifact
*
*   @version 1.0.0
*
*   @brief   AUTOSAR Fr - driver configuration header file.
*   @details Configuration settings generated by user settings.
*
*   @addtogroup [MODULE_SECTION]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : FLEXRAY
*   Dependencies         : 
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef FR_CFG_H
#define FR_CFG_H

#include "Mcal.h"
#include "Soc_Ips.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************************************
* MISRA violations
***************************************************************************************************/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifier is specified by ASR 
* or configuration.
*
* @section FR_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 19.4, Unable to expand to a parenthesis expression.
*
* @section FR_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier is specified by ASR or configuration.
*
* @section FR_CFG_H_REF_3
* Violates MISRA 2004 Required Rule 19.15, #include "Fr_MemMap.h" is not preceded only by
* preprocessor directives and appears not only in the beginning of file because it otherwise
* would not work.
* 
* @section FR_CFG_H_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, Inclusion of "Fr_MemMap.h" is required here because of
* its functionality.

*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_MODULE_ID_CFG                        81
#define FR_VENDOR_ID_CFG                        43
#define FR_AR_RELEASE_MAJOR_VERSION_CFG         4
#define FR_AR_RELEASE_MINOR_VERSION_CFG         2
#define FR_AR_RELEASE_REVISION_VERSION_CFG      2
#define FR_SW_MAJOR_VERSION_CFG                 1
#define FR_SW_MINOR_VERSION_CFG                 0
#define FR_SW_PATCH_VERSION_CFG                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if((FR_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (FR_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr_Cfg.h and Mcal.h are different"
    #endif
#endif /* CHECK_AUTOSAR_VERSION */


[!AUTOSPACING!][!//
[!WS "0"!][!INCLUDE "Fr_VersionCheck.m"!][!//
[!WS "0"!][!INCLUDE "Fr_DeviceMacros.m"!][!//
[!//
[!//
[!//
[!//
[!/*-------------------------------------------------------------------------*/!][!//
[!/* Main generation script                                                  */!][!//
[!/*-------------------------------------------------------------------------*/!][!//
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
[!WS "0"!]/* On/Off PreCompile swtiches */
[!IF "((IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size()<=1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantLinkTime')"!][!//
  [!WS "0"!]#define FR_VARIANT_PRECOMPILE                 (STD_ON)[!CR!]
[!ELSE!][!//
  [!WS "0"!]#define FR_VARIANT_PRECOMPILE                 (STD_OFF)[!CR!]
[!ENDIF!][!//
[!SELECT "FrGeneral"!][!//
  [!IF "'true' = text:tolower(node:value(FrDevErrorDetect))"!][!//
    [!WS "0"!]#define FR_DEV_ERROR_DETECT                   (STD_ON)
  [!ELSE!][!//
    [!WS "0"!]#define FR_DEV_ERROR_DETECT                   (STD_OFF)
  [!ENDIF!][!//
  [!IF "'true' = text:tolower(node:value(FrVersionInfoApi))"!][!//
    [!WS "0"!]#define FR_VERSION_INFO_API                   (STD_ON)
  [!ELSE!][!//
    [!WS "0"!]#define FR_VERSION_INFO_API                   (STD_OFF)
  [!ENDIF!][!//
  [!IF "'true' = text:tolower(node:value(FrRxStringentCheck))"!][!//
    [!WS "0"!]#define FR_RXSTRINGENTCHECK                   (STD_ON)
  [!ELSE!][!//
    [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
    [!WS "0"!]#define FR_RXSTRINGENTCHECK                   (STD_OFF)
  [!ENDIF!][!//
  [!IF "'true' = text:tolower(node:value(FrRxStringentLengthCheck))"!][!//
    [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
    [!WS "0"!]#define FR_RXSTRINGENTLENGTHCHECK             (STD_ON)
  [!ELSE!][!//
    [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
    [!WS "0"!]#define FR_RXSTRINGENTLENGTHCHECK             (STD_OFF)
  [!ENDIF!][!//
  /* @violates @ref FR_CFG_H_REF_1 */
  [!IF "'true' = text:tolower(node:value(FrPrepareLPduSupport))"!][!//
    [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
    [!WS "0"!]#define FR_PREPARE_LPDU_SUPPORT               (STD_ON)
  [!ELSE!][!//
    [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
    [!WS "0"!]#define FR_PREPARE_LPDU_SUPPORT               (STD_OFF)
  [!ENDIF!][!//
  [!IF "'true' = text:tolower(node:value(FrDisableLPduSupport))"!][!//
    [!WS "0"!]#define FR_DISABLE_LPDU_SUPPORT               (STD_ON)
  [!ELSE!][!//
    [!WS "0"!]#define FR_DISABLE_LPDU_SUPPORT               (STD_OFF)
  [!ENDIF!][!//
  [!IF "'true' = text:tolower(node:value(FrReconfigLPduSupport))"!][!//
    [!WS "0"!]#define FR_RECONFIG_LPDU_SUPPORT              (STD_ON)
  [!ELSE!][!//
    [!WS "0"!]#define FR_RECONFIG_LPDU_SUPPORT              (STD_OFF)
  [!ENDIF!][!//
  [!IF "VendorSpecific/FrDisableDemReportErrorStatus = 'true'"!][!//
    [!WS "0"!]#define FR_DISABLE_DEM_REPORT_ERROR_STATUS    (STD_ON)
  [!ELSE!][!//
    [!WS "0"!]#define FR_DISABLE_DEM_REPORT_ERROR_STATUS    (STD_OFF)
  [!ENDIF!][!//
  [!IF "'true' = text:tolower(node:exists(VendorSpecific/FrUnusedBitValue))"!][!//
    [!WS "0"!]/* FR_UNUSED_BIT_VALUE_U8 definition */
    [!IF "0 = number(VendorSpecific/FrUnusedBitValue)"!][!//
      [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 8bit format */
      [!WS "0"!]#define FR_UNUSED_BIT_VALUE_U8       ((uint8)0x00U)
      [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 16bit format */
      [!WS "0"!]#define FR_UNUSED_BIT_VALUE_U16    ((uint16)0x0000U)
      [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 32bit format */
      [!WS "0"!]#define FR_UNUSED_BIT_VALUE_U32    ((uint32)0x00000000U)
    [!ELSE!][!//
      [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 8bit format */
      [!WS "0"!]#define FR_UNUSED_BIT_VALUE_U8       ((uint8)0xFFU)
      [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 16bit format */
      [!WS "0"!]#define FR_UNUSED_BIT_VALUE_U16    ((uint16)0xFFFFU)
      [!WS "0"!]/* Copy of FrUnusedBitValue parameter from Fr General\VendorSpecific container in 32bit format */
      [!WS "0"!]#define FR_UNUSED_BIT_VALUE_U32    ((uint32)0xFFFFFFFFU)
    [!ENDIF!][!//
  [!ENDIF!][!//  
  [!CR!][!//
  [!WS "0"!]/* Constants */
  [!WS "0"!]#define FR_INSTANCE_ID_U8 ((uint8)[!"FrIndex"!]U)
  [!WS "0"!]/* Maximum number of communication controllers that the driver supports */
  [!IF "num:i(FrNumCtrlSupported) < num:i($AvailableControllers)"!][!//
    [!WS "0"!]#define FR_NUM_CTRL_SUPPORTED [!"num:i(FrNumCtrlSupported)"!]U
  [!ELSE!][!//
    [!WS "0"!]#define FR_NUM_CTRL_SUPPORTED [!"num:i($AvailableControllers)"!]U
  [!ENDIF!][!//
  [!WS "0"!]/* Maximum number of available message buffers */
  [!WS "0"!]#define FR_NUMBER_MB [!"num:i($AvailableBuffers)"!]U
  [!WS "0"!]/* Maxmimum number of test iterations during controller initialization */
  [!WS "0"!]#define FR_CTRL_TEST_COUNT [!"num:i(FrCtrlTestCount)"!]U
[!ENDSELECT!][!//
[!CR!][!//

[!NOCODE!][!//Macro to generate the configuration define
    [!MACRO "FrExportDriverConfiguration"!]
    [!NOCODE!][!//
    [!VAR "configName" = "as:name(FrMultipleConfiguration)"!][!//
    [!IF "((IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
        [!CODE!][!//
            [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
            [!WS "0"!]#define FR_CONF_PB \
        [!ENDCODE!][!//
        [!IF "var:defined('postBuildVariant')"!][!//
            [!VAR "variantIndex"="0"!][!//
            [!VAR "variantNumber"="variant:size()"!][!//
            [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
            [!//
                [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
                [!CODE!][!WS4!]extern CONST(Fr_ConfigurationType, FR_CONST) ([!"$configName"!]_[!"."!][]);[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
            [!ENDLOOP!][!//
        [!ELSE!][!//
            [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
            [!CODE!][!WS4!]extern CONST(Fr_ConfigurationType, FR_CONST) ([!"$configName"!][]);[!CR!][!ENDCODE!]
        [!ENDIF!][!//
    [!ELSE!]
        [!CODE!]
            [!WS "0"!]/* @violates @ref FR_CFG_H_REF_1 */
            [!WS "0"!]#define FR_CONF_PC[!WS5!]extern CONST(Fr_ConfigurationType, FR_CONST) ([!"$configName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] [[!"num:i($AvailableControllers +1)"!]]);
            [!WS "0"!]#define Fr_PBCfgVariantPredefined[!WS5!](&[!"$configName"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] [0])
        [!ENDCODE!]
    [!ENDIF!] 
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
[!ENDNOCODE!]

    [!LOOP "node:order(FrMultipleConfiguration,'node:name(.)')"!][!//Sort the multiple configurations by their name at first
    [!LOOP "node:order(FrController/*,'FrCtrlIdx','node:name(.)')"!][!//Sort the controllers by their name at first
        [!WS "0"!]/* Symbolic name for FrController and FrAbsoluteTimer */
        [!IF "(string-length(node:name(.)) + 20.0) > 31.0"!][!//Max 31 characters is required by misra rule 1.4, 20.0 is size of "FrConf_FrController_"
        [!WS "0"!]/* @violates @ref FR_CFG_H_REF_2 */
        [!ENDIF!][!//
        [!WS "0"!]#define FrConf_FrController_[!"node:name(.)"!][!WS "1"!] [!"node:value(FrCtrlIdx)"!]
        [!LOOP "node:order(FrAbsoluteTimer/*,'FrAbsTimerIdx','node:name(.)')"!][!//Sort the timers by their name at first
        [!IF "(string-length(node:name(.)) + 23.0) > 31.0"!][!//Max 31 characters is required by misra rule 1.4, 23.0 is size of "FrConf_FrAbsoluteTimer_"
        [!WS "0"!]/* @violates @ref FR_CFG_H_REF_2 */
        [!ENDIF!][!//
        [!WS "0"!]#define FrConf_FrAbsoluteTimer_[!"node:name(.)"!][!WS "1"!] [!"node:value(FrAbsTimerIdx)"!]
        [!ENDLOOP!]
    [!ENDLOOP!]
    [!ENDLOOP!][!//
    [!CR!][!//
[!//
[!//

    [!WS"0"!][!/* Extern declarations for configuration structures */!]
    [!WS"0"!][!CALL "FrExportDriverConfiguration"!]

[!IF "$SupportIpv9 = 'true'"!]
[!WS "0"!]#define SUPPORT_IP_V9
[!SELECT "FrGeneral/VendorSpecific"!][!//
[!WS "0"!]/* Macro for init error notification */
[!IF "node:exists(FrErrorInitiNotification) and (normalize-space(FrErrorInitiNotification) != 'NULL_PTR')"!]
[!WS "0"!]#define FR_INIT_ERROR_NOTIFICATION [!WS "10"!][!"normalize-space(FrErrorInitiNotification)"!]
/* @violates @ref FR_CFG_H_REF_1 */
[!WS "0"!]#define FR_INIT_ERROR_NOTIFICATION_EN [!WS "10"!](STD_ON)
[!ELSE!]
[!WS "0"!]#define FR_INIT_ERROR_NOTIFICATION(void)
/* @violates @ref FR_CFG_H_REF_1 */
[!WS "0"!]#define FR_INIT_ERROR_NOTIFICATION_EN [!WS "10"!](STD_OFF)
[!ENDIF!]
[!IF "FrAccessErrorNotificationEnable = 'true'"!][!//
[!WS "0"!]/* Macro for access error notification */
[!WS "0"!]#define FR_ACCESS_ERROR_NOTIFICATION_EN
[!ENDIF!]
[!ENDSELECT!][!//
[!WS "0"!]#define FR_DEINIT_API                         (STD_OFF)
[!ELSE!]
[!WS "0"!]#define FR_DEINIT_API                         (STD_ON)
[!ENDIF!]


#ifdef __cplusplus
}
#endif

#endif /* FR_CFG_H */

/** @} */