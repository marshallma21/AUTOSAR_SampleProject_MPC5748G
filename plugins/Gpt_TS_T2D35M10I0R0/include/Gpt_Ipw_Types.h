/**
*   @file    Gpt_Ipw_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - Gpt driver header file.
*   @details GPT driver header file, containing variables, functions prototypes, data types and/or
*            defines and macros that:
*            - are Autosar independent.
*            - are platform dependent.
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

#ifndef GPT_IPW_TYPES_H
#define GPT_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Stm_Types.h"
#include "Gpt_Pit_Types.h"
#include "Gpt_eMios_Types.h"
#include "Gpt_Rtc_Types.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_IPW_TYPES_VENDOR_ID                      43
#define GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION       2
#define GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION    2
#define GPT_IPW_TYPES_SW_MAJOR_VERSION               1
#define GPT_IPW_TYPES_SW_MINOR_VERSION               0
#define GPT_IPW_TYPES_SW_PATCH_VERSION               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_IPW_TYPES_VENDOR_ID != GPT_STM_TYPES_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Gpt_Stm_Types.h have different vendor ids"
#endif
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_STM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_STM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_STM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_Stm_Types.h are different"
#endif
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_STM_TYPES_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_STM_TYPES_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_STM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_Stm_Types.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != GPT_PIT_TYPES_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Gpt_Pit_Types.h have different vendor ids"
#endif
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_PIT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_PIT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_PIT_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_Pit_Types.h are different"
#endif
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_PIT_TYPES_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_PIT_TYPES_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_PIT_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_Pit_Types.h are different"
#endif

#if (GPT_IPW_TYPES_VENDOR_ID != GPT_EMIOS_TYPES_VENDOR_ID)
    #error "Gpt_Ipw_Types.h and Gpt_eMios_Types.h have different vendor ids"
#endif
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_eMios_Types.h are different"
#endif
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_EMIOS_TYPES_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_EMIOS_TYPES_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_EMIOS_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_eMios_Types.h are different"
#endif


#if (GPT_IPW_TYPES_VENDOR_ID != GPT_RTC_TYPES_VENDOR_ID)
    #error "Gpt_IPW_Types.h and Gpt_Rtc_Types.h have different vendor ids"
#endif
#if ((GPT_IPW_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_RTC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_MINOR_VERSION != GPT_RTC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_IPW_TYPES_AR_RELEASE_REVISION_VERSION != GPT_RTC_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Ipw_Types.h and Gpt_Rtc_Types.h are different"
#endif
#if ((GPT_IPW_TYPES_SW_MAJOR_VERSION != GPT_RTC_TYPES_SW_MAJOR_VERSION) || \
     (GPT_IPW_TYPES_SW_MINOR_VERSION != GPT_RTC_TYPES_SW_MINOR_VERSION) || \
     (GPT_IPW_TYPES_SW_PATCH_VERSION != GPT_RTC_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Ipw_Types.h and Gpt_Rtc_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief Gpt prescaler data type
*/
typedef uint8 Gpt_PrescalerType;

/**
* @brief Low level configuration for channel specific parameters
*/
typedef struct
{
    VAR(uint8, GPT_VAR) Gpt_u8HwChannel;                /**<@brief GPT hw channel ID */
    VAR(uint8, GPT_VAR) Gpt_u8HwModule;                 /**<@brief GPT hw module used */
    VAR(boolean, GPT_VAR) Gpt_bFreezeEnable;            /**<@brief Channel freeze enable */
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uPrescaler;     /**<@brief Channel prescaler value*/
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uRtcClockSource;     /**<@brief Rtc channel clock source*/
#if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uStmClockSource;/*<@brief STM Clock source selection */
#endif
#if (GPT_SET_CLOCK_MODE == STD_ON)
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uPrescaler_Alternate;    /**<@brief Channel prescaler value Alternate*/
#endif /* GPT_DUAL_CLOCK_MODE */
} Gpt_HwChannelConfigType;

/**
* @brief Low level configuration for channel specific parameters
*/
typedef struct
{
    VAR(uint8, GPT_VAR) Gpt_u8HwChannel;                    /**<@brief GPT hw channel ID */
    VAR(uint8, GPT_VAR) Gpt_u8HwModule;                     /**<@brief GPT hw module used */
    VAR(boolean, GPT_VAR) Gpt_bFreezeEnable;                /**<@brief Channel freeze enable */
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uPrescaler;         /**<@brief Channel prescaler value*/
#if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
    VAR(Gpt_PrescalerType, GPT_VAR) Gpt_uStmClockSource;    /**<@brief STM Clock source selection */
#endif
} Gpt_HwPredefChannelConfigType;

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*GPT_IPW_TYPES_H*/

/** @} */
