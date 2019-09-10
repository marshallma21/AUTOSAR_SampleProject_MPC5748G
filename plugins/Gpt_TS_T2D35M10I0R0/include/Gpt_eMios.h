/**
*   @file    Gpt_eMios.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
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

#ifndef GPT_EMIOS_H
#define GPT_EMIOS_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Gpt_eMios_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include file
* This violation  is not  fixed since  the inclusion  of MemMap.h  is as  per Autosar  requirement
* MEMMAP003.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref Gpt_eMios_H_REF_1 Repeated include file */
#include "Gpt_eMios_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Gpt_eMios.h
*/
#define GPT_EMIOS_VENDOR_ID                       43
#define GPT_EMIOS_AR_RELEASE_MAJOR_VERSION        4
#define GPT_EMIOS_AR_RELEASE_MINOR_VERSION        2
#define GPT_EMIOS_AR_RELEASE_REVISION_VERSION     2
#define GPT_EMIOS_SW_MAJOR_VERSION                1
#define GPT_EMIOS_SW_MINOR_VERSION                0
#define GPT_EMIOS_SW_PATCH_VERSION                0
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (GPT_EMIOS_VENDOR_ID != GPT_EMIOS_TYPES_VENDOR_ID)
    #error "Gpt_eMios.h and Gpt_eMios_Types.h have different vendor ids"
#endif
#if ((GPT_EMIOS_AR_RELEASE_MAJOR_VERSION != GPT_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_AR_RELEASE_MINOR_VERSION != GPT_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_EMIOS_AR_RELEASE_REVISION_VERSION != GPT_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios.h and Gpt_eMios_Types.h are different"
#endif
#if ((GPT_EMIOS_SW_MAJOR_VERSION != GPT_EMIOS_TYPES_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_SW_MINOR_VERSION != GPT_EMIOS_TYPES_SW_MINOR_VERSION) || \
     (GPT_EMIOS_SW_PATCH_VERSION != GPT_EMIOS_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_eMios.h and Gpt_eMios_Types.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

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
/** @violates @ref Gpt_eMios_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

FUNC(void, GPT_CODE) Gpt_eMios_Init 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(uint8, AUTOMATIC) u8Prescaler,
    VAR(boolean, AUTOMATIC) bFreezeEnable
);

#if (GPT_DEINIT_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_eMios_DeInit (VAR(uint8, AUTOMATIC) u8HwChannel);
#endif /* GPT_DEINIT_API */

FUNC(void, GPT_CODE) Gpt_eMios_StartTimer 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(uint32, AUTOMATIC) u32Value
);

FUNC(void, GPT_CODE) Gpt_eMios_StopTimer (VAR(uint8, AUTOMATIC) u8HwChannel);

FUNC(uint32, GPT_CODE) Gpt_eMios_GetTimeElapsed 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
);

FUNC(void, GPT_CODE) Gpt_eMios_EnableInterrupt (VAR(uint8, AUTOMATIC) u8HwChannel);

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
FUNC(void, GPT_CODE) Gpt_eMios_DisableInterrupt (VAR(uint8, AUTOMATIC) u8HwChannel);
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API || GPT_WAKEUP_FUNCTIONALITY_API */

#if (GPT_SET_CLOCK_MODE == STD_ON)
FUNC (void, GPT_CODE) Gpt_eMios_SetClockMode(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint8, AUTOMATIC) u8ChPrescale);
#endif /*GPT_SET_CLOCK_MODE == STD_ON*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_eMios_StartPredefTimer 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(uint8, AUTOMATIC) u8Prescaler,
    VAR(boolean, AUTOMATIC) bFreezeEnable
);

FUNC(uint32, GPT_CODE) Gpt_eMios_GetPredefTimerValue
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimerType
);

FUNC(void, GPT_CODE) Gpt_eMios_StopPredefTimer (VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref Gpt_eMios_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*Gpt_eMios_H*/

/** @} */
