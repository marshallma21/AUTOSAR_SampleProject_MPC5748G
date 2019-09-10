/**
*   @file    Reg_eSys_eMios.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eDMA
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_EMIOS_H_1
* Violates MISRA 2004 Required Rule 19.15, :  Repeated include file MemMap.h  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation
* since all header files are protected against multiple inclusions
*
* @section REG_ESYS_EMIOS_H_2
* Violates MISRA 2004 Advisory Rule 19.7, : Use of function like macro. This
* violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section REG_ESYS_EMIOS_H_3
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
* @section REG_ESYS_EMIOS_H_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section REG_ESYS_EMIOS_H_5
* Violates MISRA 2004 Required Rule 8.12, When an array is declared with external linkage, its size 
* shall be stated explicitly or defined implicitly by initialisation.
*
* @section REG_ESYS_EMIOS_H_6
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
*/

#ifndef REG_ESYS_EMIOS_H
#define REG_ESYS_EMIOS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/** @violates @ref REG_ESYS_EMIOS_H_1 Repeated include file MemMap.h */
#include "Reg_eSys.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Reg_eSys_eMios.h
* @brief   Header file version information
*/
#define REG_ESYS_EMIOS_VENDOR_ID                          43
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION           4
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION           2
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define REG_ESYS_EMIOS_AR_RELEASE_REVISION_VERSION        2
#define REG_ESYS_EMIOS_SW_MAJOR_VERSION                   1
#define REG_ESYS_EMIOS_SW_MINOR_VERSION                   0
#define REG_ESYS_EMIOS_SW_PATCH_VERSION                   0
/** @} */

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
        (REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Reg_eSys_eMios.h and Reg_eSys.h are different"
#endif
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define MCL_START_SEC_CONST_32
/** @violates @ref REG_ESYS_EMIOS_H_1 Repeated include file MemMap.h */

#include "Mcl_MemMap.h"

/**
* @brief EMIOS base address array declaration
*/

/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
@violates @ref REG_ESYS_EMIOS_H_5 Array size shall be stated explicitly
@violates @ref REG_ESYS_EMIOS_H_6 the define cannot be moved inside the block scope...
*/
extern CONST(uint32, MCL_CONST) EMIOS_BASE_ADDR32[];
#define MCL_STOP_SEC_CONST_32
/** @violates @ref REG_ESYS_EMIOS_H_1 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* This is applicable for the following lines of code */
/**
* @{
* @brief EMIOS Module Registers - global registers, mIdx : emios module index 0 for emiosA, 1 for
*        emiosB
*/

/* MCR: module configuration register */
/**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_MCR_ADDR32(mIdx)             (EMIOS_BASE_ADDR32[(mIdx)] + (uint32)0x0000UL)

/* GFR: global flag register */
/**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_GFR_ADDR32(mIdx)             (EMIOS_BASE_ADDR32[(mIdx)] + (uint32)0x0004UL)

/* OUDR: output update disable register */
/**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_OUDR_ADDR32(mIdx)                   (EMIOS_BASE_ADDR32[(mIdx)] + (uint32)0x0008UL)

#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
        /* UCDIS: enable/disable channel - not available on all EMIOS IP versions */
        /**
        * @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
         @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
        */
        #define EMIOS_UCDIS_ADDR32(mIdx)           (EMIOS_BASE_ADDR32[(mIdx)] + (uint32)0x000CUL)
    #endif
#endif
/**@}*/

/**
* @brief EMIOS Module Registers - offset address
*/
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_CADR_OFFSET_U32                                       ((uint32)(0x00UL))
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_CBDR_OFFSET_U32                                       ((uint32)(0x04UL))
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_CCNTR_OFFSET_U32                                      ((uint32)(0x08UL))
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_CCR_OFFSET_U32                                        ((uint32)(0x0CUL))
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_CSR_OFFSET_U32                                        ((uint32)(0x10UL))
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_ALTA_OFFSET_U32                                       ((uint32)(0x14UL))
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_MCR_OFFSET_U32                                        ((uint32)(0x0000UL))
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_OUDR_OFFSET_U32                                       ((uint32)(0x0008UL))
/** @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro */
#define EMIOS_UCDIS_OFFSET_U32                                      ((uint32)(0x000CUL))

/**
* @{
* @brief EMIOS Module Registers - Unified Channel specific registers, mIdx : emios module index 0
*        for
* emiosA, 1 for emiosB, chIdx : unified channel index
*/

/* EMIOS_BASE_ADDR32es[ module_ID ] + 0x20(uc block offset) + channel offset + register offset */
/**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_CADR_ADDR32(mIdx, chIdx)    (EMIOS_BASE_ADDR32[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x00UL)

/**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_CBDR_ADDR32(mIdx, chIdx)    (EMIOS_BASE_ADDR32[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x04UL)

/**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_CCNTR_ADDR32(mIdx, chIdx)   (EMIOS_BASE_ADDR32[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x08UL)

/**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_CCR_ADDR32(mIdx, chIdx)     (EMIOS_BASE_ADDR32[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x0CUL)

/**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_CSR_ADDR32(mIdx, chIdx)     (EMIOS_BASE_ADDR32[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x10UL)

 /**
* @violates @ref REG_ESYS_EMIOS_H_2 Use of function like macro
* @violates @ref REG_ESYS_EMIOS_H_3 This is not a standard library macro,
*/
#define EMIOS_ALTA_ADDR32(mIdx, chIdx)    (EMIOS_BASE_ADDR32[(mIdx)] + 0x20UL + \
                                    (uint32)((uint32)(chIdx)<<(5UL)) + 0x14UL)
/**@}*/


/* MASK and SHIFT values for each register field */
/**
* @{
* @brief MCR - Module Configuration Register - bitfield mask and shift defines.
*/
#define MCR_DOZEEN_MASK_U32     ((uint32)(BIT31))
#define MCR_DOZEEN_SHIFT        ((uint32)(31U))

#define MCR_MDIS_MASK_U32       ((uint32)(BIT30))
#define MCR_MDIS_SHIFT          ((uint32)(30U))

#define MCR_FRZ_MASK_U32        ((uint32)(BIT29))
#define MCR_FRZ_SHIFT           ((uint32)(29U))

#define MCR_GTBE_MASK_U32       ((uint32)(BIT28))
#define MCR_GTBE_SHIFT          ((uint32)(28U))

#define MCR_ETB_MASK_U32        ((uint32)(BIT27))
#define MCR_ETB_SHIFT           ((uint32)(27U))

#define MCR_GPREN_MASK_U32      ((uint32)(BIT26))
#define MCR_GPREN_SHIFT         ((uint32)(26U))

#define MCR_SRV_MASK_U32        ((uint32)(BIT19|BIT18|BIT17|BIT16))
#define MCR_SRV_SHIFT           ((uint32)(16U))

#define MCR_GPRE_MASK_U32       ((uint32)(BIT15|BIT14|BIT13|BIT12|BIT11|BIT10|BIT9|BIT8))
#define MCR_GPRE_SHIFT          ((uint32)(8U))
/**@}*/

/**
* @{
* @brief GFR - Global Flag Register - bitfield mask and shift defines.
*/
/* Mask and shift defines are not needed - read only register */
/**@}*/

/**
* @{
* @brief OUDR - Output Update Disable Register
*/
/* Mask and shift defines are not needed */
/**@}*/

/**
* @{
* @brief CADR[n] - unified channel N register A
*/
/* mask and shift defines are not needed */
/**@}*/

/**
* @{
* @brief CBDR[n] - unified channel N register B
*/
/* Mask and shift defines are not needed */
/**@}*/

/**
* @{
* @brief CCNTR[n] - unified channel N counter register
*/
/* Mask and shift defines are not needed */
/**@}*/

/**
* @{
* @brief CCR[n] - unified channel N control register
*/
#define CCR_FREN_MASK_U32           ((uint32)(BIT31))
#define CCR_FREN_SHIFT              ((uint32)(31U))

#define CCR_ODIS_MASK_U32           ((uint32)(BIT30))
#define CCR_ODIS_SHIFT              ((uint32)(30U))

#define CCR_ODISL_MASK_U32          ((uint32)(BIT29|BIT28))
#define CCR_ODISL_SHIFT             ((uint32)(28U))

#define CCR_UCPRE_MASK_U32          ((uint32)(BIT27|BIT26))
#define CCR_UCPRE_SHIFT             ((uint32)(26U))

#define CCR_UCPREN_MASK_U32         ((uint32)(BIT25))
#define CCR_UCPREN_SHIFT            ((uint32)(25U))

#define CCR_DMA_MASK_U32            ((uint32)(BIT24))
#define CCR_DMA_SHIFT               ((uint32)(24U))

#define CCR_IF_MASK_U32             ((uint32)(BIT22|BIT21|BIT20|BIT19))
#define CCR_IF_SHIFT                ((uint32)(19U))

#define CCR_FCK_MASK_U32            ((uint32)(BIT18))
#define CCR_FCK_SHIFT               ((uint32)(18U))

#define CCR_FEN_MASK_U32            ((uint32)(BIT17))
#define CCR_FEN_SHIFT               ((uint32)(17U))

#define CCR_FORCMA_MASK_U32         ((uint32)(BIT13))
#define CCR_FORCMA_SHIFT            ((uint32)(13U))

#define CCR_FORCMB_MASK_U32         ((uint32)(BIT12))
#define CCR_FORCMB_SHIFT            ((uint32)(12U))

#define CCR_BSL_MASK_U32            ((uint32)(BIT10|BIT9))
#define CCR_BSL_SHIFT               ((uint32)(9U))

#define CCR_EDSEL_MASK_U32          ((uint32)(BIT8))
#define CCR_EDSEL_SHIFT             ((uint32)(8U))

#define CCR_EDPOL_MASK_U32          ((uint32)(BIT7))
#define CCR_EDPOL_SHIFT             ((uint32)(7U))

/* EDGE select mask - part of MODE field */
#define CCR_MODE_EDGE_SELECT_MASK_U32               ((uint32)(BIT1))
#define CCR_MODE_EDGE_SELECT_SHIFT                  ((uint32)(1U))

/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_DAOC_MODE_EDGE_SELECT_MASK_U32          ((uint32)(BIT0))
#define CCR_MCB_MODE_U32                            ((uint32)(BIT4|BIT6))
#define CCR_MC_MODE_U32                             ((uint32)(BIT4))

#define CCR_MODE_MASK_U32                           ((uint32)(BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0))
#define CCR_MODE_SHIFT                              ((uint32)(0U))
/**@}*/

/**
* @{
* @brief CSR[n] - unified channel N status register
*/
#define CSR_OVR_MASK_U32                            ((uint32)(BIT31))
#define CSR_OVR_SHIFT                               ((uint32)(31U))

#define CSR_OVFL_MASK_U32                           ((uint32)(BIT15))
#define CSR_OVFL_SHIFT                              ((uint32)(15U))

#define CSR_UCIN_MASK_U32                           ((uint32)(BIT2))
#define CSR_UCIN_SHIFT                              ((uint32)(2U))

#define CSR_UCOUT_MASK_U32                          ((uint32)(BIT1))
#define CSR_UCOUT_SHIFT                             ((uint32)(1U))

#define CSR_FLAG_MASK_U32                           ((uint32)(BIT0))
#define CSR_FLAG_SHIFT                              ((uint32)(0U))
/**@}*/

/**
* @{
* @brief ALTA[n] - unified channel N alternate A register
*/
/* Mask and shift defines are not needed */
/**@}*/

/** Bitfield defines. */

/**
* @{
* @brief MCR - bitfield defines.
*/
#define MCR_DOZEEN_ENABLE_U32      ((uint32)(0U))
#define MCR_DOZEEN_DISABLE_U32     ((uint32)(1U))

#define MCR_MDIS_CLK_ON_U32        ((uint32)(0U))
#define MCR_MDIS_LOW_POWER_U32     ((uint32)(1U))

#define MCR_FRZ_DISABLE_U32        ((uint32)(0U))
#define MCR_FRZ_ENABLE_U32         ((uint32)(1U))

#define MCR_GTBE_DISABLE_U32       ((uint32)(0U))
#define MCR_GTBE_ENABLE_U32        ((uint32)(1U))

#define MCR_ETB_UC_U32             ((uint32)(0U))
#define MCR_ETB_STAC_U32           ((uint32)(1U))

#define MCR_GPREN_DISABLE_U32      ((uint32)(0U))
#define MCR_GPREN_ENABLE_U32       ((uint32)(1U))

#define MCR_SRV_ETPUTA_TCR1_U32    ((uint32)(0U))
#define MCR_SRV_ETPUTB_TCR1_U32    ((uint32)(1U))
#define MCR_SRV_ETPUTA_TCR2_U32    ((uint32)(2U))
#define MCR_SRV_ETPUTB_TCR2_U32    ((uint32)(3U))
/**@}*/

/**
* @{
* @brief GFR - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/**
* @{
* @brief OUDR - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/**
* @{
* @brief CADR[n] - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/**
* @{
* @brief CBDR[n] - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/**
* @{
* @brief CCNTR[n] - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/**
* @{
* @brief CCR[n] - bitfield defines.
*/
#define CCR_FREN_DISABLE_U32     ((uint32)(0U))
#define CCR_FREN_ENABLE_U32      ((uint32)(1U))

#define CCR_ODIS_DISABLE_U32     ((uint32)(0U))
#define CCR_ODIS_ENABLE_U32      ((uint32)(1U))

#define CCR_ODISSL_IN_0_U32      ((uint32)(0U))
#define CCR_ODISSL_IN_1_U32      ((uint32)(1U))
#define CCR_ODISSL_IN_2_U32      ((uint32)(2U))
#define CCR_ODISSL_IN_3_U32      ((uint32)(3U))

#define CCR_UCPRE_DIV_1_U32      ((uint32)(0U))
#define CCR_UCPRE_DIV_2_U32      ((uint32)(1U))
#define CCR_UCPRE_DIV_3_U32      ((uint32)(2U))
#define CCR_UCPRE_DIV_4_U32      ((uint32)(3U))

#define CCR_UCPREN_DISABLE_U32   ((uint32)(0U))
#define CCR_UCPREN_ENABLE_U32    ((uint32)(1U))

#define CCR_DMA_ASSIGN_INT_U32   ((uint32)(0U))
#define CCR_DMA_ASSIGN_DMA_U32   ((uint32)(1U))

#define CCR_IF_BYPASSED_U32      ((uint32)(0U))
#define CCR_IF_2_PERIODS_U32     ((uint32)(1U))
#define CCR_IF_4_PERIODS_U32     ((uint32)(2U))
#define CCR_IF_8_PERIODS_U32     ((uint32)(4U))
#define CCR_IF_16_PERIODS_U32    ((uint32)(8U))

#define CCR_FCK_PRESCALED_U32    ((uint32)(0U))
#define CCR_FCK_MAIN_U32         ((uint32)(1U))

#define CCR_FEN_DISABLE_U32      ((uint32)(0U))
#define CCR_FEN_ENABLE_U32       ((uint32)(1U))

#define CCR_FORCMA_DISABLE_U32   ((uint32)(0U))
#define CCR_FORCMA_ENABLE_U32    ((uint32)(1U))

#define CCR_FORCMB_DISABLE_U32   ((uint32)(0U))
#define CCR_FORCMB_ENABLE_U32    ((uint32)(1U))

#define CCR_BSL_BUS_A_U32        ((uint32)(0U))
#define CCR_BSL_BUS_DIVERSE_U32  ((uint32)(1U))
#define CCR_BSL_BUS_F_U32        ((uint32)(2U))
#define CCR_BSL_INT_COUNTER_U32  ((uint32)(3U))

#define CCR_EDSEL_0_U32          ((uint32)(0U))
#define CCR_EDSEL_1_U32          ((uint32)(1U))

#define CCR_EDPOL_0_U32          ((uint32)(0U))
#define CCR_EDPOL_1_U32          ((uint32)(1U))

/* Unified channel mode field */
#define CCR_MODE_GPI_U32         ((uint32)(0x00))
#define CCR_MODE_GPO_U32         ((uint32)(0x01))
#define CCR_MODE_SAIC_U32        ((uint32)(0x02))
#define CCR_MODE_SAOC_U32        ((uint32)(0x03))
#define CCR_MODE_IPWM_U32        ((uint32)(0x04))
#define CCR_MODE_IPM_U32         ((uint32)(0x05))
#define CCR_MODE_DAOC_U32        ((uint32)(0x06))
#define CCR_MODE_DAOC_BOTH_U32   ((uint32)(0x07))

#define CCR_MODE_PEA_CONT_U32    ((uint32)(0x08))
#define CCR_MODE_PEA_SINGLE_U32  ((uint32)(0x09))
#define CCR_MODE_PEC_CONT_U32    ((uint32)(0x0A))
#define CCR_MODE_PEC_SINGLE_U32  ((uint32)(0x0B))

#define CCR_MODE_QDEC_COUNT_U32  ((uint32)(0x0C))
#define CCR_MODE_QDEC_PHASE_U32  ((uint32)(0x0D))

#define CCR_MODE_WPTA_U32        ((uint32)(0x0E))

/* CCR_MODE_ 0x0F reserved */
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MC_UP_CLEAR_START_INT_CLOCK_U32             ((uint32)(0x10))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MC_UP_CLEAR_START_EXT_CLOCK_U32             ((uint32)(0x11))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MC_UP_CLEAR_END_INT_CLOCK_U32               ((uint32)(0x12))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MC_UP_CLEAR_END_EXT_CLOCK_U32               ((uint32)(0x13))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MC_UP_DOWN_FLAG_A_INT_CLOCK_U32             ((uint32)(0x14))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MC_UP_DOWN_FLAG_A_EXT_CLOCK_U32             ((uint32)(0x15))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MC_CHANGE_DIR_INT_CLOCK_U32                 ((uint32)(0x16))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MC_CHANGE_DIR_EXT_CLK_U32                   ((uint32)(0x17))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWFM_FLAG_B_IMMEDIATE_U32                  ((uint32)(0x18))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWFM_FLAG_B_NEXT_PERIOD_U32                ((uint32)(0x19))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWFM_FLAG_A_FLAG_B_IMMEDIATE_U32           ((uint32)(0x1A))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWFM_FLAG_A_FLAG_B_NEXT_PERIOD_U32         ((uint32)(0x1B))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWMC_FLAG_TRAILING_TRAILING_DEAD_TIME_U32  ((uint32)(0x1C))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWMC_FLAG_TRAILING_LEADING_DEAD_TIME_U32   ((uint32)(0x1D))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWMC_FLAG_BOTH_TRAILING_DEAD_TIME_U32      ((uint32)(0x1E))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWMC_FLAG_BOTH_LEADING_DEAD_TIME_U32       ((uint32)(0x1F))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWM_FLAG_B_IMMEDIATE_U32                   ((uint32)(0x20))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWM_FLAG_B_NEXT_PERIOD                 ((uint32)(0x21))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWM_FLAG_A_FLAG_B_IMMEDIATE_U32            ((uint32)(0x22))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWM_FLAG_A_FLAG_B_NEXT_PERIOD_U32          ((uint32)(0x23))
#define CCR_EDPOL_N_MODE_MASK_U32                            ((uint32)(0xFFU))
#define CCR_EDPOL_N_MODE_SET_U32                             ((uint32)(0xA6U))
#define CCR_EDPOL_N_MODE_CLEAR_U32                           ((uint32)(0x26U))
/* CCR_MODE_ 0x24, 0x25 reserved */
/* Output Pulse Width Modulation with Trigger - not available on all EMIOS IP versions */
#define CCR_MODE_OPWMT_U32                                   ((uint32)(0x26))
/* CCR_MODE_ 0x27 ... 0x4F reserved */
#define CCR_MODE_MCB_INT_CLOCK_U32                           ((uint32)(0x50))
#define CCR_MODE_MCB_EXT_CLOCK_U32                           ((uint32)(0x51))
/* CCR_MODE_ 0x52, 0x53 reserved */
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MCB_FLAG_A_INT_CLOCK_U32                    ((uint32)(0x54))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MCB_FLAG_A_EXT_CLOCK_U32                    ((uint32)(0x55))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MCB_FLAG_A_CYCLE_INT_CLOCK_U32              ((uint32)(0x56))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_MCB_FLAG_A_CYCLE_EXT_CLOCK_U32              ((uint32)(0x57))
#define CCR_MODE_OPWFMB_FLAG_B_U32                           ((uint32)(0x58))
/* CCR_MODE_ 0x59 reserved */
#define CCR_MODE_OPWFMB_FLAG_AB_U32                          ((uint32)(0x5A))
/* CCR_MODE_ 0x5B reserved */
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWMCB_FLAG_TRAILING_TRAILING_DEAD_TIME_U32        ((uint32)(0x5C))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWMCB_FLAG_TRAILING_LEADING_DEAD_TIME_U32         ((uint32)(0x5D))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWMCB_FLAG_BOTH_TRAILING_DEAD_TIME_U32            ((uint32)(0x5E))
/** @violates @ref REG_ESYS_EMIOS_H_4 This is required as per autosar Requirement */
#define CCR_MODE_OPWMCB_FLAG_BOTH_LEADING_DEAD_TIME_U32             ((uint32)(0x5F))
#define CCR_MODE_OPWMB_FLAG_B_U32                                   ((uint32)(0x60))
/* CCR_MODE_ 0x61 reserved */
#define CCR_MODE_OPWMB_FLAG_AB_U32                                  ((uint32)(0x62))
/* CCR_MODE_ 0x63 0x3F reserved */
/**@}*/

/**
* @{
* @brief CSR[n] - bitfield defines.
*/
/* only w1c bits */
#define CSR_OVR_BIT_U32           ((uint32)(BIT31))
#define CSR_OVFL_BIT_U32          ((uint32)(BIT15))
#define CSR_FLAG_BIT_U32          ((uint32)(BIT0))
/**@}*/

/**
* @{
* @brief ALTA[n] - bitfield defines.
*/
/* bitfields for this register are not needed */
/**@}*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_EMIOS_H */
/** @} */

