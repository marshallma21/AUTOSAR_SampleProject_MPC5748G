/**
*   @file    Gpt_Stm.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - STM driver header file.
*   @details STM driver interface.
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

#ifndef GPT_STM_H
#define GPT_STM_H

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
*
* @section GPT_STM_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Stm_Types.h"
#include "Mcal.h"
/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Stm.h
* @{
*/
#define GPT_STM_VENDOR_ID                       43
#define GPT_STM_AR_RELEASE_MAJOR_VERSION        4
#define GPT_STM_AR_RELEASE_MINOR_VERSION        2
#define GPT_STM_AR_RELEASE_REVISION_VERSION     2
#define GPT_STM_SW_MAJOR_VERSION                1
#define GPT_STM_SW_MINOR_VERSION                0
#define GPT_STM_SW_PATCH_VERSION                0
/** @} */

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (GPT_STM_VENDOR_ID != GPT_STM_TYPES_VENDOR_ID)
    #error "Gpt_Stm.h and Gpt_Stm_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_AR_RELEASE_MAJOR_VERSION != GPT_STM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_AR_RELEASE_MINOR_VERSION != GPT_STM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_AR_RELEASE_REVISION_VERSION != GPT_STM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Stm.h and Gpt_Stm_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_SW_MAJOR_VERSION != GPT_STM_TYPES_SW_MAJOR_VERSION) || \
     (GPT_STM_SW_MINOR_VERSION != GPT_STM_TYPES_SW_MINOR_VERSION) || \
     (GPT_STM_SW_PATCH_VERSION != GPT_STM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Stm.h and Gpt_Stm_Types.h are different"
#endif

/* Check if source file and Mcal header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_STM_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_STM_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Gpt_Stm.h and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
#if (GPT_STM_USED == STD_ON)
/**
* @brief Number of timers for each STM module
*/
#define GPT_STM_MODULE_CHAN_NUM_U8 (4U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define GPT_START_SEC_VAR_NO_INIT_32
/** @violates @ref GPT_STM_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @brief          Global array variable used to store the runtime target time value.
*/
extern VAR(uint32, GPT_VAR) Gpt_Stm_u32TargetValue[GPT_STM_MODULES_NUM_U8][GPT_STM_MODULE_CHAN_NUM_U8];

#define GPT_STOP_SEC_VAR_NO_INIT_32
/** @violates @ref GPT_STM_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
/** @violates @ref GPT_STM_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


FUNC (void, GPT_CODE) Gpt_Stm_Init
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(uint8, AUTOMATIC) u8Prescaler,
#if defined(GPT_STM_ENABLECLOCKSWITCH)
  #if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
    VAR(uint8, AUTOMATIC) u8ClockSource,
  #endif
#endif
    VAR(boolean, AUTOMATIC) bFreezeEnable
);

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_Stm_DeInit(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

FUNC (void, GPT_CODE) Gpt_Stm_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint32, AUTOMATIC) u32Value);

FUNC (void, GPT_CODE) Gpt_Stm_StopTimer(VAR(uint8, AUTOMATIC) u8HwChannel);

FUNC (uint32, GPT_CODE) Gpt_Stm_GetTimeElapsed
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
);
#if (GPT_SET_CLOCK_MODE == STD_ON)
FUNC (void, GPT_CODE) Gpt_Stm_SetClockMode
(
    VAR(uint8, AUTOMATIC) u8hwChannel,
    VAR(uint8, AUTOMATIC) u8chPrescale
);
#endif
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
FUNC(void, GPT_CODE) Gpt_Stm_StartPredefTimer 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(uint8, AUTOMATIC) u8Prescaler,
#if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
    VAR(uint8, AUTOMATIC) u8ClockSource,
#endif
    VAR(boolean, AUTOMATIC) bFreezeEnable    
);
FUNC(uint32, GPT_CODE) Gpt_Stm_GetPredefTimerValue (VAR(uint8, AUTOMATIC) u8HwChannel, VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimerType);
FUNC(void, GPT_CODE) Gpt_Stm_StopPredefTimer (VAR(uint8, AUTOMATIC) u8HwChannel);

#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_STM_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif  /* (GPT_STM_USED == STD_ON)*/
#ifdef __cplusplus
}
#endif

#endif /*GPT_STM_H*/

/** @} */
