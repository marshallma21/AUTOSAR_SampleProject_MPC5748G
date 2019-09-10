/**
*   @file Icu_Reg_eSys_Siul2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Icu - SIUL low level driver register defines.
*   @details The description of the registers of the SIUL module.
*
*   @addtogroup Siul
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS SIUL2 WKPU
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


#ifndef ICU_REG_ESYS_SIUL2_H
#define ICU_REG_ESYS_SIUL2_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Reg_eSys_SIUL2_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
* @section Icu_Reg_eSys_SIUL2_h_REF_2
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to IP functions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Icu_Reg_eSys_SIUL2_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent
*           the contents of a header file being included twice
*/
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ICU_REGESYS_SIUL2_VENDOR_ID                    43
#define ICU_REGESYS_SIUL2_AR_RELEASE_MAJOR_VERSION     4
#define ICU_REGESYS_SIUL2_AR_RELEASE_MINOR_VERSION     2
#define ICU_REGESYS_SIUL2_AR_RELEASE_REVISION_VERSION  2
#define ICU_REGESYS_SIUL2_SW_MAJOR_VERSION             1
#define ICU_REGESYS_SIUL2_SW_MINOR_VERSION             0
#define ICU_REGESYS_SIUL2_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#if (ICU_REGESYS_SIUL2_VENDOR_ID != REG_ESYS_VENDOR_ID)
    #error "Icu_Reg_eSys_Siul2.h and Reg_eSys.h have different vendor IDs"
#endif
    /* Check if header file and Icu_Reg_eSys_SIUL2 header file are of the same Autosar version */
#if ((ICU_REGESYS_SIUL2_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_REGESYS_SIUL2_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) || \
     (ICU_REGESYS_SIUL2_AR_RELEASE_REVISION_VERSION != REG_ESYS_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Reg_eSys_Siul2.h and Reg_eSys.h are different"
#endif
/* Check if header file and Icu_Reg_eSys_SIUL2 header file are of the same software version */
#if ((ICU_REGESYS_SIUL2_SW_MAJOR_VERSION != REG_ESYS_SW_MAJOR_VERSION) || \
     (ICU_REGESYS_SIUL2_SW_MINOR_VERSION != REG_ESYS_SW_MINOR_VERSION) || \
     (ICU_REGESYS_SIUL2_SW_PATCH_VERSION != REG_ESYS_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Reg_eSys_Siul2.h and Reg_eSys.h are different"
#endif

/*==================================================================================================
*                               DEFINES AND MACROS
==================================================================================================*/

/* @brief Interrupt Status Flag Register address, bits and masks */
#define ICU_SIUL2_DISR0_ADDR32                          (SIUL2_BASEADDR + 0x10UL)
#define ICU_SIUL2_DISR0_EIF                             (0xFFFFFFFFUL)

/* @brief DMA/Interrupt Request Enable Register address, bits and masks */
#define ICU_SIUL2_DIRER0_LOCKABLE_ADDR32                (SIUL2_BASEADDR + 0x18UL)
#define ICU_SIUL2_DIRER0_EIRE                           (0xFFFFFFFFUL)

/* @brief DMA/Interrupt Request Select Register address, bits and masks */
#define ICU_SIUL2_DIRSR0_LOCKABLE_ADDR32                (SIUL2_BASEADDR + 0x20UL)
#define ICU_SIUL2_DIRSR0_DIRSR                          (0xFFFFFFFFUL)

/* @brief Interrupt Rising Edge Event Register address, bits and masks */
#define ICU_SIUL2_IREER0_LOCKABLE_ADDR32                (SIUL2_BASEADDR + 0x28UL)
#define ICU_SIUL2_IREER0_IREE                           (0xFFFFFFFFUL)

/* @brief Interrupt Falling Edge Event Register address, bits and masks */
#define ICU_SIUL2_IFEER0_LOCKABLE_ADDR32                (SIUL2_BASEADDR + 0x30UL)
#define ICU_SIUL2_IFEER0_IFEE                           (0xFFFFFFFFUL)

/* @brief Interrupt Filter Enable Register address, bits and masks */
#define ICU_SIUL2_IFER0_LOCKABLE_ADDR32                 (SIUL2_BASEADDR + 0x38UL)
#define ICU_SIUL2_IFER0_IFE                             (0xFFFFFFFFUL)


/**
* @brief Interrupt Filter Maximum Counter Register address
* @violates @ref Icu_Reg_eSys_SIUL2_h_REF_2 Function-like macro defined
*/
#define ICU_SIUL2_IFMCR_LOCKABLE_ADDR32(IFMC_OFFSET)   (SIUL2_BASEADDR + (IFMC_OFFSET) + 0x40UL)

/* @brief Interrupt Filter Maximum Counter mask */
#define ICU_SIUL2_IFMCR_MAXCNT                          (0x0000000FUL)


/*
* @brief Interrupt Filter Clock Prescaler Register
*/
#define ICU_SIUL2_IFCPR_LOCKABLE_ADDR32                 (SIUL2_BASEADDR + 0xC0UL)

/* @brief Interrupt Filter Clock Prescaler Register masks and shift counts */
#define ICU_SIUL2_IFCPR_IFCP                            (0x0000000FUL)
#define ICU_SIUL2_IFCPR_SHIFT                           (0U)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/


/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif
/* ICU_REG_ESYS_SIUL2_H */
#endif
/** @} */
