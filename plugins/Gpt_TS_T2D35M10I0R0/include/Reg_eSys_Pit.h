/**
*   @file    Reg_eSys_Pit.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - PIT driver header file.
*   @details PIT module register description.
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

#ifndef REG_ESYS_PIT_H
#define REG_ESYS_PIT_H

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
* @section REG_ESYS_PIT_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macro defined for register operations.
* Function like macro are used to reduce code complexity.
*
* @section REG_ESYS_PIT_H_REF_2
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
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_Pit.h
*/
#define REG_ESYS_PIT_VENDOR_ID                       43
#define REG_ESYS_PIT_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_PIT_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_PIT_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_PIT_SW_MAJOR_VERSION                1
#define REG_ESYS_PIT_SW_MINOR_VERSION                0
#define REG_ESYS_PIT_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Reg_eSys.h file are of the same Autosar version */
    #if ((REG_ESYS_PIT_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_PIT_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_Pit.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#if (GPT_PIT_USED == STD_ON)

#define GPT_START_SEC_CONST_32
/** @violates @ref REG_ESYS_PIT_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @brief Maximum possible number of PIT modules
*/
#define PIT_MODULE_NUM_MAX_U8          (2U)

/**
* @brief PIT base address array declaration
*/
extern CONST(uint32, GPT_CONST) PIT_BASE_ADDR32[PIT_MODULE_NUM_MAX_U8];

#define GPT_STOP_SEC_CONST_32
/** @violates @ref REG_ESYS_PIT_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @violates @ref REG_ESYS_PIT_H_REF_1 Use of function like macro */
#define PIT_MODULE_INDEX_U32(ch)      (((ch) & PIT_MOD_MASK_U8) >> PIT_MOD_SHIFT)

/** @violates @ref REG_ESYS_PIT_H_REF_1 Use of function like macro */
#define PIT_CHANNEL_INDEX_U32(ch)     (((ch) & PIT_CH_MASK_U8)  >> PIT_CH_SHIFT)

/* PIT Registers */

/**
* @brief PIT Module Control Registers (PITMCR)  Register address
*/
/** @violates @ref REG_ESYS_PIT_H_REF_1 Use of function like macro */
#define PIT_MCR_LOCKABLE_ADDR32(u8ModuleIdx)    (PIT_BASE_ADDR32[(u8ModuleIdx)])

/**
* @brief Timer Load Value Register (LDVAL)  Register address
*/
/** @violates @ref REG_ESYS_PIT_H_REF_1 Use of function like macro */
#define PIT_LDVAL_LOCKABLE_ADDR32(u8ModuleIdx,u8ChannelIdx)    (PIT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(4UL)) + (uint32)0x00F0UL))

/**
* @brief Current Timer Value Register (CVAL)  Register address
*/
/** @violates @ref REG_ESYS_PIT_H_REF_1 Use of function like macro */
#define PIT_CVAL_LOCKABLE_ADDR32(u8ModuleIdx,u8ChannelIdx)     (PIT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(4UL)) + (uint32)0x00F4UL))

/**
* @brief Timer Control Register (TCTRL)  Register address
*/
/** @violates @ref REG_ESYS_PIT_H_REF_1 Use of function like macro */
#define PIT_TCTRL_LOCKABLE_ADDR32(u8ModuleIdx,u8ChannelIdx)    (PIT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(4UL)) + (uint32)0x00F8UL))


/**
* @brief Timer Flag Register (TFLG)  Register address
*/
/** @violates @ref REG_ESYS_PIT_H_REF_1 Use of function like macro */
#define PIT_TFLG_ADDR32(u8ModuleIdx,u8ChannelIdx)              (PIT_BASE_ADDR32[(u8ModuleIdx)] + ((uint32)((uint32)(u8ChannelIdx)<<(4UL)) + (uint32)0x00FCUL))



/**
* @brief PIT registers - bitfield mask and shift defines.
*/
#define PIT_TFLG_TIF_MASK_U32                              ((uint32)(BIT0))

#define PIT_TCTRL_TIE_MASK_U32                             ((uint32)(BIT1))
#define PIT_TCTRL_TIE_SHIFT                                ((uint32)1UL)
#define PIT_TCTRL_TEN_MASK_U32                             ((uint32)(BIT0))

#define PIT_MCR_MDIS_RTI_MASK_U32                          ((uint32)(BIT2))
#define PIT_MCR_MDIS_MASK_U32                              ((uint32)(BIT1))
#define PIT_MCR_MDIS_SHIFT                                 ((uint32)1UL)
#define PIT_MCR_FRZ_MASK_U32                               ((uint32)(BIT0))


/**
* @brief PIT registers - bitfield defines.
*/
#define PIT_TFLG_TIF_ON_U32                             ((uint32)1UL)
#define PIT_TFLG_TIF_OFF_U32                            ((uint32)0UL)

#define PIT_TCTRL_TIE_ON_U32                            ((uint32)1UL)
#define PIT_TCTRL_TIE_OFF_U32                           ((uint32)0UL)
#define PIT_TCTRL_TEN_ON_U32                            ((uint32)1UL)
#define PIT_TCTRL_TEN_OFF_U32                           ((uint32)0UL)

#define PIT_MCR_MDIS_ON_U32                             ((uint32)1UL)
#define PIT_MCR_MDIS_OFF_U32                            ((uint32)0UL)
#define PIT_MCR_FRZ_ON_U32                              ((uint32)1UL)
#define PIT_MCR_FRZ_OFF_U32                             ((uint32)0UL)


/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* (GPT_PIT_USED == STD_ON) */

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_PIT_H*/

/** @} */
