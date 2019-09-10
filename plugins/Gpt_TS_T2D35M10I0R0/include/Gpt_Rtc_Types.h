/**
*   @file    Gpt_Rtc_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - Source file of the RTC driver.
*   @details RTC driver interface.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios_Stm_Pit
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef GPT_RTC_TYPES_H
#define GPT_RTC_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Gpt_Rtc_Types_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Gpt_Rtc_Types_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Gpt_Rtc_Types_3
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Cfg.h"
#include "Gpt_EnvCfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_RTC_TYPES_VENDOR_ID                       43
/* @violates @ref Gpt_Rtc_Types_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_TYPES_AR_RELEASE_MAJOR_VERSION        4
/*
* @violates @ref Gpt_Rtc_Types_2 The compiler/linker shall be checked to ensure 31 
* character  significance and case sensitivity are supported for external identifiers
*/
/* @violates @ref Gpt_Rtc_Types_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_TYPES_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Gpt_Rtc_Types_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_TYPES_AR_RELEASE_REVISION_VERSION     2
/* @violates @ref Gpt_Rtc_Types_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_TYPES_SW_MAJOR_VERSION                1
/* @violates @ref Gpt_Rtc_Types_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_TYPES_SW_MINOR_VERSION                0
/* @violates @ref Gpt_Rtc_Types_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_TYPES_SW_PATCH_VERSION                0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* API SERVICE IDs */
/**
* @brief API service ID for RTC_Gpt_ProcessInterrupt function
* @details Parameters used when raising a CER error/exception
*/
#define GPT_RTC_INTERRUPT_ID          ((uint8)0x06U)
/**
* @brief RTC Channels defines
*/
#define    RTC_0_CH_0                 ((uint8)0x00U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @{
* @brief This enumerated type allows the selection of clock sources for RTC.
*/
typedef enum
{
    RTC_GPT_CLKSRC_XOSC = 0,
    RTC_GPT_CLKSRC_FIRC,
    RTC_GPT_CLKSRC_SIRC,
    RTC_GPT_CLKSRC_SXOSC
} Rtc_Gpt_ChannelClkSrcType;
/**@}*/
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
/*
* @violates @ref Gpt_Rtc_Types_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Gpt_MemMap.h"

/* Check if header file and MemMap.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_RTC_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_MEMMAP_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_RTC_TYPES_AR_RELEASE_MINOR_VERSION != GPT_MEMMAP_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Rtc_Gpt_Types.h and MemMap.h are different"
    #endif
#endif

#define GPT_STOP_SEC_CODE
/*
* @violates @ref Gpt_Rtc_Types_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_RTC_TYPES_H*/

/**@}*/
