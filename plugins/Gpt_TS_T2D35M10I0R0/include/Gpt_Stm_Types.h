/**
*   @file    Gpt_Stm_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - STM driver header file.
*   @details STM defines which need to be exported to external application
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

#ifndef GPT_STM_TYPES_H
#define GPT_STM_TYPES_H

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
* @section GPT_STM_TYPES_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref GPT_STM_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_Cfg.h"
/** @violates @ref GPT_STM_TYPES_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_EnvCfg.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Stm_Types.h
* @{
*/
#define GPT_STM_TYPES_VENDOR_ID                       43
#define GPT_STM_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define GPT_STM_TYPES_AR_RELEASE_MINOR_VERSION        2
#define GPT_STM_TYPES_AR_RELEASE_REVISION_VERSION     2
#define GPT_STM_TYPES_SW_MAJOR_VERSION                1
#define GPT_STM_TYPES_SW_MINOR_VERSION                0
#define GPT_STM_TYPES_SW_PATCH_VERSION                0
/** @} */

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_STM_TYPES_VENDOR_ID != GPT_VENDOR_ID_CFG)
    #error "Gpt_Stm_Types.h and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_STM_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_STM_TYPES_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_STM_TYPES_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Gpt_Stm_Types.h and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_STM_TYPES_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_STM_TYPES_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_STM_TYPES_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG) \
    )
    #error "Software Version Numbers of Gpt_Stm_Types.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_STM_TYPES_VENDOR_ID!= GPT_ENVCFG_VENDOR_ID)
    #error "Gpt_Stm_Types.h and Gpt_EnvCfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_STM_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_TYPES_AR_RELEASE_MINOR_VERSION != GPT_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_TYPES_AR_RELEASE_REVISION_VERSION != GPT_ENVCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Stm_Types.h and Gpt_EnvCfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_STM_TYPES_SW_MAJOR_VERSION != GPT_ENVCFG_SW_MAJOR_VERSION) || \
     (GPT_STM_TYPES_SW_MINOR_VERSION != GPT_ENVCFG_SW_MINOR_VERSION) || \
     (GPT_STM_TYPES_SW_PATCH_VERSION != GPT_ENVCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Stm_Types.h and Gpt_EnvCfg.h are different"
#endif
/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief          STM channels defines
* @details        There are defines used for the STM channel encoding -> channel_id
*
* @note           A STM module generally has only 4 channels so by using this method
*                 there will be gaps of 12 channels between different STM modules because
*                 [              6 bit  | 2 bit               ]
*                 [ module id: 63 ... 0 | channel id: 3 ... 0 ]
*/
#define STM_MOD_MASK_U8             ((uint8)0xFC)
#define STM_MOD_SHIFT               ((uint8)2U)
#define STM_CH_MASK_U8              ((uint8)0x03)
#define STM_CH_SHIFT                ((uint8)0U)
/** @} */


/**
* @{
* @brief STM Channels defines
*/
#define STM_0_CH_0                  ((uint8)0)
#define STM_0_CH_1                  ((uint8)1)
#define STM_0_CH_2                  ((uint8)2)
#define STM_0_CH_3                  ((uint8)3)

#define STM_1_CH_0                  ((uint8)(1U<<STM_MOD_SHIFT) + (uint8)0)
#define STM_1_CH_1                  ((uint8)(1U<<STM_MOD_SHIFT) + (uint8)1)
#define STM_1_CH_2                  ((uint8)(1U<<STM_MOD_SHIFT) + (uint8)2)
#define STM_1_CH_3                  ((uint8)(1U<<STM_MOD_SHIFT) + (uint8)3)

#define STM_2_CH_0                  ((uint8)(2U<<STM_MOD_SHIFT) + (uint8)0)
#define STM_2_CH_1                  ((uint8)(2U<<STM_MOD_SHIFT) + (uint8)1)
#define STM_2_CH_2                  ((uint8)(2U<<STM_MOD_SHIFT) + (uint8)2)
#define STM_2_CH_3                  ((uint8)(2U<<STM_MOD_SHIFT) + (uint8)3)
/** @} */

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*GPT_STM_TYPES_H*/

/** @} */
