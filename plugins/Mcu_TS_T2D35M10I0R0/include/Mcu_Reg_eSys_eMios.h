/**
*   @file    Mcu_Reg_eSys_eMios.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Macros for memory access.
*   @details Macros/Defines used for registry and memory read/write.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : MC
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

#ifndef MCU_REG_ESYS_EMIOS_H
#define MCU_REG_ESYS_EMIOS_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_Reg_eSys_eMios_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Mcu_Reg_eSys_eMios_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
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
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_REG_ESYS_EMIOS_VENDOR_ID                       43
#define MCU_REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_1 The compiler/linker shall be checked. */
#define MCU_REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION        2
#define MCU_REG_ESYS_EMIOS_AR_RELEASE_REVISION_VERSION     2
#define MCU_REG_ESYS_EMIOS_SW_MAJOR_VERSION                1
#define MCU_REG_ESYS_EMIOS_SW_MINOR_VERSION                0
#define MCU_REG_ESYS_EMIOS_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCU_REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_Reg_eSys_eMios.h and Reg_eSys.h are different"
#endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_RWBITS_MASK32             ((uint32)0x7C0FFF00U)
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_RESBITS_MASK32            ((uint32)0x00000000U)

/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_MDIS_MASK32               ((uint32)0x40000000U)
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_FRZ_MASK32                ((uint32)0x20000000U)
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_GTBE_MASK32               ((uint32)0x10000000U)
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_ETB_MASK32                ((uint32)0x08000000U)
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_GPREN_MASK32              ((uint32)0x04000000U)
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_SRV_MASK32                ((uint32)0x000F0000U)
/** @violates @ref Mcu_Reg_eSys_eMios_h_REF_2 This is not a standard library macro. */
#define EMIOS_MCR_GPRE_MASK32               ((uint32)0x0000FF00U)

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

#endif /* MCU_REG_ESYS_EMIOS_H */
/** @} */

