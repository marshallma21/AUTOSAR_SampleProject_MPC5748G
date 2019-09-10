/**
*   @file    Gpt_Pit.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - PIT driver header file.
*   @details PIT driver interface.
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

#ifndef GPT_PIT_H
#define GPT_PIT_H

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
* @section GPT_PIT_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Pit_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Pit.h
*/
#define GPT_PIT_VENDOR_ID                       43
#define GPT_PIT_MODULE_ID                       100
#define GPT_PIT_AR_RELEASE_MAJOR_VERSION        4
#define GPT_PIT_AR_RELEASE_MINOR_VERSION        2
#define GPT_PIT_AR_RELEASE_REVISION_VERSION     2
#define GPT_PIT_SW_MAJOR_VERSION                1
#define GPT_PIT_SW_MINOR_VERSION                0
#define GPT_PIT_SW_PATCH_VERSION                0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_PIT_VENDOR_ID!= GPT_PIT_TYPES_VENDOR_ID)
    #error "Gpt_Pit.h and Gpt_Pit_Types.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_AR_RELEASE_MAJOR_VERSION != GPT_PIT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_MINOR_VERSION != GPT_PIT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_REVISION_VERSION != GPT_PIT_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Pit.h and Gpt_Pit_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_PIT_SW_MAJOR_VERSION != GPT_PIT_TYPES_SW_MAJOR_VERSION) || \
     (GPT_PIT_SW_MINOR_VERSION != GPT_PIT_TYPES_SW_MINOR_VERSION) || \
     (GPT_PIT_SW_PATCH_VERSION != GPT_PIT_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Pit.h and Gpt_Pit_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#if (GPT_PIT_USED == STD_ON)

#define GPT_START_SEC_CODE
/** @violates @ref GPT_PIT_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"


FUNC (void, GPT_CODE) Gpt_Pit_Init(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(boolean, AUTOMATIC) bFreezeEnable);

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_Pit_DeInit(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

FUNC (void, GPT_CODE) Gpt_Pit_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint32, AUTOMATIC) u32Value);

FUNC (void, GPT_CODE) Gpt_Pit_StopTimer(VAR(uint8, AUTOMATIC) u8HwChannel);

FUNC (uint32, GPT_CODE) Gpt_Pit_GetTimeElapsed
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
);

FUNC (void, GPT_CODE) Gpt_Pit_EnableInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
FUNC (void, GPT_CODE) Gpt_Pit_DisableInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_PIT_H_REF_1 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif /* (GPT_PIT_USED == STD_ON) */

#ifdef __cplusplus
}
#endif

#endif /*GPT_PIT_H*/

/** @} */
