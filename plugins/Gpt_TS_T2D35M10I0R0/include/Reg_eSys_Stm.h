/**
*   @file    Reg_eSys_Stm.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - STM driver header file.
*   @details STM main register description.
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

#ifndef REG_ESYS_STM_H
#define REG_ESYS_STM_H

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
* @section REG_ESYS_STM_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section REG_ESYS_STM_H_REF_2
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
#include "Reg_eSys.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief Parameters that shall be published within the Gpt driver header file and also in the
*       module's description file
* @{
*/
#define REG_ESYS_STM_VENDOR_ID                       43
#define REG_ESYS_STM_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_STM_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_STM_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_STM_SW_MAJOR_VERSION                1
#define REG_ESYS_STM_SW_MINOR_VERSION                0
#define REG_ESYS_STM_SW_PATCH_VERSION                0
/** @} */
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Reg_eSys.h file are of the same Autosar version */
    #if ((REG_ESYS_STM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_STM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_Stm.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/
#if (GPT_STM_USED == STD_ON)

#define GPT_START_SEC_CONST_32
/** @violates @ref REG_ESYS_STM_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @brief Maximum possible number of STM modules
*/
#define STM_MODULE_NUM_MAX_U8          (3U)

/**
* @brief STM base address array declaration
*/
extern CONST(uint32, GPT_CONST) STM_BASE_ADDR32[STM_MODULE_NUM_MAX_U8];

#define GPT_STOP_SEC_CONST_32
/** @violates @ref REG_ESYS_STM_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/** @violates @ref REG_ESYS_STM_H_REF_1 Use of function like macro */
#define STM_MODULE_INDEX_U32(ch)      (((ch) & (uint32)STM_MOD_MASK_U8) >> STM_MOD_SHIFT)

/** @violates @ref REG_ESYS_STM_H_REF_1 Use of function like macro */
#define STM_CHANNEL_INDEX_U32(ch)     (((ch) & (uint32)STM_CH_MASK_U8)  >> STM_CH_SHIFT)

/**
* @{
* @brief System Timer Module (STM) Registers address
*/
/** @violates @ref REG_ESYS_STM_H_REF_1 Use of function like macro */
#define STM_CR_ADDR32(ch)      (STM_BASE_ADDR32[STM_MODULE_INDEX_U32(ch)])
/** @violates @ref REG_ESYS_STM_H_REF_1 Use of function like macro */
#define STM_CNT_ADDR32(ch)      (STM_BASE_ADDR32[STM_MODULE_INDEX_U32(ch)]+(uint32)0x4UL)
/** @violates @ref REG_ESYS_STM_H_REF_1 Use of function like macro */
#define STM_CCR_ADDR32(ch)      (STM_BASE_ADDR32[STM_MODULE_INDEX_U32(ch)] + ((uint32)(STM_CHANNEL_INDEX_U32(ch))<<4) + (uint32)0x10UL)
/** @violates @ref REG_ESYS_STM_H_REF_1 Use of function like macro */
#define STM_CIR_ADDR32(ch)      (STM_BASE_ADDR32[STM_MODULE_INDEX_U32(ch)] + ((uint32)(STM_CHANNEL_INDEX_U32(ch))<<4) + (uint32)0x14UL)
/** @violates @ref REG_ESYS_STM_H_REF_1 Use of function like macro */
#define STM_CMP_ADDR32(ch)      (STM_BASE_ADDR32[STM_MODULE_INDEX_U32(ch)] + ((uint32)(STM_CHANNEL_INDEX_U32(ch))<<4) + (uint32)0x18UL)
/** @} */

/**
* @brief Defines for System Timer Module (STM) Registers
*/
#define STM_CR_FRZ_DISABLE_U32   ((uint32)0UL)
#define STM_CR_FRZ_ENABLE_U32    ((uint32)1UL)
#define STM_CR_TEN_DISABLE_U32   ((uint32)0UL)
#define STM_CR_TEN_ENABLE_U32    ((uint32)1UL)
#define STM_CCR_CEN_DISABLE_U32  ((uint32)0UL)
#define STM_CCR_CEN_ENABLE_U32   ((uint32)1UL)
#define STM_CIR_CIF_SET_U32      ((uint32)1UL)


#define STM_CR_TEN_MASK_U32      ((uint32)(BIT0))
#define STM_CR_TEN_SHIFT         ((uint32)(0U))

#define STM_CR_FRZ_MASK_U32      ((uint32)(BIT1))
#define STM_CR_FRZ_SHIFT         ((uint32)(1U))

#define STM_CR_CPS_MASK_U32      ((uint32)(BIT15|BIT14|BIT13|BIT12|BIT11|BIT10|BIT9|BIT8))
#define STM_CR_CPS_SHIFT         ((uint32)(8U))

#define STM_CR_CSL_MASK_U32      ((uint32)(BIT4))
#define STM_CR_CSL_SHIFT         ((uint32)(4U))

#define STM_CCR_CEN_MASK_U32     ((uint32)(BIT0))
#define STM_CCR_CEN_SHIFT        ((uint32)(0U))

#define STM_CIR_CIF_MASK_U32     ((uint32)(BIT0))
#define STM_CIR_CIF_SHIFT        ((uint32)(0U))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/
#endif /*(GPT_STM_USED == STD_ON)*/

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_STM_H*/

/** @} */
