/**
*   @file    Gpt_eMios_Types.h
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
#ifndef GPT_EMIOS_TYPES_H
#define GPT_EMIOS_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Gpt_eMios_Types_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Gpt_eMios_Types_H_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, 
* objects and functions shall not be reused
*
* @section [global]
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
/** @violates @ref Gpt_eMios_Types_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "eMios_Common_Types.h"
/** @violates @ref Gpt_eMios_Types_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_Cfg.h"
/** @violates @ref Gpt_eMios_Types_H_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "Gpt_EnvCfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Gpt_eMios_Types.h
* @brief          Source file version information
*
*/
#define GPT_EMIOS_TYPES_VENDOR_ID                         43
#define GPT_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define GPT_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION          2
#define GPT_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION       2
#define GPT_EMIOS_TYPES_SW_MAJOR_VERSION                  1
#define GPT_EMIOS_TYPES_SW_MINOR_VERSION                  0
#define GPT_EMIOS_TYPES_SW_PATCH_VERSION                  0
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION != EMIOS_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION != EMIOS_COMMON_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_eMios_Types.h and eMios_Common_Types.h are different"
    #endif
#endif

#if ( GPT_EMIOS_TYPES_VENDOR_ID != GPT_VENDOR_ID_CFG)
    #error "Gpt_eMios_Types.h and Gpt_Cfg.h have different vendor ids"
#endif
#if ((GPT_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Gpt_eMios_Types.h and Gpt_Cfg.h are different"
#endif
#if ((GPT_EMIOS_TYPES_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_EMIOS_TYPES_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_EMIOS_TYPES_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG) )
    #error "Software Version Numbers of Gpt_eMios_Types.h and Gpt_Cfg.h are different"
#endif

#if ( GPT_EMIOS_TYPES_VENDOR_ID!= GPT_ENVCFG_VENDOR_ID)
    #error "Gpt_eMios_Types.h and Gpt_EnvCfg.h have different vendor ids"
#endif
#if ((GPT_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION != GPT_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION != GPT_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     (GPT_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION != GPT_ENVCFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios_Types.h and Gpt_EnvCfg.h are different"
#endif
#if ((GPT_EMIOS_TYPES_SW_MAJOR_VERSION != GPT_ENVCFG_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_TYPES_SW_MINOR_VERSION != GPT_ENVCFG_SW_MINOR_VERSION) || \
     (GPT_EMIOS_TYPES_SW_PATCH_VERSION != GPT_ENVCFG_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_eMios_Types.h and Gpt_EnvCfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief EMIOS unified channel prescaller control
* @note Hardware Dependent Definition - DO NOT CHANGE
* @violates @ref Gpt_eMios_Types_H_REF_2 This is not a standard library macro, 
*/
#define GPT_EMIOS_PRESCALER_DIVIDE_1            ((uint32)0U)

/** @violates @ref Gpt_eMios_Types_H_REF_2 This is not a standard library macro */
#define GPT_EMIOS_PRESCALER_DIVIDE_2            ((uint32)1U)

/** @violates @ref Gpt_eMios_Types_H_REF_2 This is not a standard library macro */
#define GPT_EMIOS_PRESCALER_DIVIDE_3            ((uint32)2U)

/** @violates @ref Gpt_eMios_Types_H_REF_2 This is not a standard library macro */
#define GPT_EMIOS_PRESCALER_DIVIDE_4            ((uint32)3U)

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

#ifdef __cplusplus
}
#endif

#endif /*Gpt_eMios_Types_H*/

/** @} */
