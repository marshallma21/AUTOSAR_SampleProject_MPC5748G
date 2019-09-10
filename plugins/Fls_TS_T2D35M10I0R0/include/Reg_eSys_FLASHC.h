/**
*   @file    Reg_eSys_FLASHC.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Fls - Defines used to access the Flash registers.
*   @details This file contains defines used to access the Flash registers.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : IPV_FLASHV2
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

#ifndef REG_ESYS_FLASHC_H
#define REG_ESYS_FLASHC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_FLASHC_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Reg_eSys_FLASHC_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/**
* @violates @ref Reg_eSys_FLASHC_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ESYS_FLASHC_VENDOR_ID                           43
/* @violates @ref Reg_eSys_FLASHC_H_REF_2 Identifier exceeds 31 characters */
#define ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION            4
/* @violates @ref Reg_eSys_FLASHC_H_REF_2 Identifier exceeds 31 characters */
#define ESYS_FLASHC_AR_RELEASE_MINOR_VERSION            2
/* @violates @ref Reg_eSys_FLASHC_H_REF_2 Identifier exceeds 31 characters */
#define ESYS_FLASHC_AR_RELEASE_REVISION_VERSION         2
#define ESYS_FLASHC_SW_MAJOR_VERSION                    1
#define ESYS_FLASHC_SW_MINOR_VERSION                    0
#define ESYS_FLASHC_SW_PATCH_VERSION                    0

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (ESYS_FLASHC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_FLASHC.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define IPV_FLASHV2_C55FG_4096          (0x01000305UL)    /* for XPC564xM platform */
#define IPV_FLASHV2_C55FM_2560          (0x25608600UL)    /* for MPC5744P platform */
#define IPV_FLASHV2_C55FM_4096          (0x40965519UL)    /* for MPC5775N platform */
#define IPV_FLASHV2_C55FM_8192          (0x01000802UL)    /* for MPC5777M platform */
#define IPV_FLASHV2_C55FM_4272          (0x42565538UL)    /* for MPC574XR platform */
#define IPV_FLASHV2_C55FM_6144          (0x62725539UL)    /* for MPC574XG platform */
#define IPV_FLASHV2_C55FM_8480          (0x84803202UL)    /* for MPC5777C platform */
#define IPV_FLASHV2_C55FM_4096K         (0x40965546UL)    /* for MPC5775K platform */
#define IPV_FLASHV2_C55FM_2048          (0x20485546UL)    /* for S32R274 platform */  



#define FLASH_BASEADDR      (FMCR_BASEADDR)  /** @brief Flash register base address  */
#define FLASH_MCR_OFFSET    ((uint32)0x00UL) /** @brief Module Configuration Register (MCR) address offset  */

/* memory array control/configuration registers */
#define FLASH_MCR_ADDR32    ((uint32)(FLASH_BASEADDR + (uint32)0x00UL)) /**< @brief Module Configuration Register (MCR) */
#define FLASH_MCRA_ADDR32   ((uint32)(FLASH_BASEADDR + (uint32)0x04UL)) /**< @brief Alternate Module Configuration Register (MCRA) */
#define FLASH_MCRE_ADDR32   ((uint32)(FLASH_BASEADDR + (uint32)0x08UL)) /**< @brief Extended Module Configuration Register (MCRE) */
#define FLASH_LOCK0_ADDR32  ((uint32)(FLASH_BASEADDR + (uint32)0x10UL)) /**< @brief Lock 0 Register - Test, Low/Middle Block address space (LOCK0) */ 
#define FLASH_LOCK1_ADDR32  ((uint32)(FLASH_BASEADDR + (uint32)0x14UL)) /**< @brief Lock 1 Register - High Block address space (LOCK1) */
#define FLASH_LOCK2_ADDR32  ((uint32)(FLASH_BASEADDR + (uint32)0x18UL)) /**< @brief Lock 2 Register - 256 KByte Block address space (LOCK2) */
#define FLASH_LOCK3_ADDR32  ((uint32)(FLASH_BASEADDR + (uint32)0x1CUL)) /**< @brief Lock 3 Register - 256 KByte Block address space (LOCK3) */
#define FLASH_LOCK0A_ADDR32 ((uint32)(FLASH_BASEADDR + (uint32)0x20UL)) /**< @brief Alternate Lock 0 Register - Test, Low/Middle Block address space (LOCK0A) */
#define FLASH_LOCK1A_ADDR32 ((uint32)(FLASH_BASEADDR + (uint32)0x24UL)) /**< @brief Alternate Lock 1 Register - High Block address space (LOCK1A) */
#define FLASH_SEL0_ADDR32   ((uint32)(FLASH_BASEADDR + (uint32)0x38UL)) /**< @brief Select 0 Register - Low/Middle Block address space (SEL0) */
#define FLASH_SEL1_ADDR32   ((uint32)(FLASH_BASEADDR + (uint32)0x3CUL)) /**< @brief Select 1 Register - High Block address space (SEL1) */  
#define FLASH_SEL2_ADDR32   ((uint32)(FLASH_BASEADDR + (uint32)0x40UL)) /**< @brief Select 2 Register - 256 KByte Block address space (SEL2) */
#define FLASH_SEL3_ADDR32   ((uint32)(FLASH_BASEADDR + (uint32)0x44UL)) /**< @brief Select 3 Register - 256 KByte Block address space (SEL3) */
#define FLASH_ADR_ADDR32    ((uint32)(FLASH_BASEADDR + (uint32)0x50UL)) /**< @brief Address Register (ADR) */
#define FLASH_UT0_ADDR32    ((uint32)(FLASH_BASEADDR + (uint32)0x54UL)) /**< @brief User Test 0 register (UT0) */



/* PFC (Platform Flash Controller) control/configuration registers */
#define FLASH_PFCR1 0x0000U /**< @brief Platform Flash Configuration Register 1 (PFCR1) */
#define FLASH_PFCR2 0x0001U /**< @brief Platform Flash Configuration Register 2 (PFCR2) */
#define FLASH_PFCR3 0x0002U /**< @brief Platform Flash Configuration Register 3 (PFCR3) */
#define FLASH_PFAPR 0x0003U /**< @brief Platform Flash Access Protection Register (PFAPR) */

/* MCR register bits */
#define FLASH_MCR_RVE_U32   0x80000000U  /**< @brief RVE:   Read Voltage Error (Read/Clear) */
#define FLASH_MCR_RRE_U32   0x40000000U  /**< @brief RRE:   Read Reference Error (Read/Clear) */
#define FLASH_MCR_EER_U32   0x00008000U  /**< @brief EER:   Ecc event ERror (Read/Clear) */
#define FLASH_MCR_RWE_U32   0x00004000U  /**< @brief RWE:   Read-while-Write event Error (Read/Clear) */
#define FLASH_MCR_SBC_U32   0x00002000U  /**< @brief SBC:   Single Bit Correction (Read/Clear) */
#define FLASH_MCR_PEAS_U32  0x00000800U  /**< @brief PEAS:  Program/Erase Access Space (Read Only) */
#define FLASH_MCR_DONE_U32  0x00000400U  /**< @brief DONE:  modify operation DONE (Read Only) */
#define FLASH_MCR_PEG_U32   0x00000200U  /**< @brief PEG:   Program/Erase Good (Read Only) */
#define FLASH_MCR_PECIE_U32 0x00000100U  /**< @brief PECIE: Program/Erase Complete Interrupt Enable (Read Only) */
#define FLASH_MCR_FERS_U32  0x00000080U  /**< @brief FERS:  Factory Erase (Read Only) */
#define FLASH_MCR_PGM_U32   0x00000010U  /**< @brief PGM:   ProGraM (Read/Write) */
#define FLASH_MCR_PSUS_U32  0x00000008U  /**< @brief PSUS:  Program SUSpend (Read/Write) */
#define FLASH_MCR_ERS_U32   0x00000004U  /**< @brief ERS:   ERaSe (Read/Write) */
#define FLASH_MCR_ESUS_U32  0x00000002U  /**< @brief ESUS:  Erase SUSpend (Read/Write) */
#define FLASH_MCR_EHV_U32   0x00000001U  /**< @brief EHV:   Enable High Voltage (Read/Write) */

/* MCR register bits - masks for W1C operations */
#define FLASH_MCR_RVE_W1C   (FLASH_MCR_RVE_U32)
#define FLASH_MCR_RRE_W1C   (FLASH_MCR_RRE_U32)
#define FLASH_MCR_EER_W1C   (FLASH_MCR_EER_U32)
#define FLASH_MCR_RWE_W1C   (FLASH_MCR_RWE_U32)
#define FLASH_MCR_SBC_W1C   (FLASH_MCR_SBC_U32)

/* LOCK0 - Low/Middle Block Lock register bits */
#define FLASH_LML_TSLK_U32  0x80000000U  /**< @brief TSLK: Test/Shadow address space block LocK (Read/Write) */
#define FLASH_LML_LLK29_U32 0x20000000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK28_U32 0x10000000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK27_U32 0x08000000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK26_U32 0x04000000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK25_U32 0x02000000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK24_U32 0x01000000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK23_U32 0x00800000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK22_U32 0x00400000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK21_U32 0x00200000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK20_U32 0x00100000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK19_U32 0x00080000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK18_U32 0x00040000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK17_U32 0x00020000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_LLK16_U32 0x00010000U  /**< @brief LLK29-0: Low address space block LocK 29-0 (Read/Write) */
#define FLASH_LML_MLK15_U32 0x00008000U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK14_U32 0x00004000U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK13_U32 0x00002000U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK12_U32 0x00001000U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK11_U32 0x00000800U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK10_U32 0x00000400U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK9_U32  0x00000200U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK8_U32  0x00000100U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK7_U32  0x00000080U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK6_U32  0x00000040U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK5_U32  0x00000020U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK4_U32  0x00000010U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK3_U32  0x00000008U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK2_U32  0x00000004U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK1_U32  0x00000002U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */
#define FLASH_LML_MLK0_U32  0x00000001U  /**< @brief MLK29-0: Mid address space block LocK 29-0(Read/Write) */

/* LOCK1 - High Block Lock register bits */
#define FLASH_HBL_HLK15_U32 0x00008000U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK14_U32 0x00004000U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK13_U32 0x00002000U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK12_U32 0x00001000U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK11_U32 0x00000800U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK10_U32 0x00000400U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK9_U32  0x00000200U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK8_U32  0x00000100U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK7_U32  0x00000080U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK6_U32  0x00000040U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK5_U32  0x00000020U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK4_U32  0x00000010U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK3_U32  0x00000008U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK2_U32  0x00000004U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK1_U32  0x00000002U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */
#define FLASH_HBL_HLK0_U32  0x00000001U  /**< @brief HLK15-0: High address space block LocK 15-0 (Read/Write) */

/* LOCK2 - Large Block Lock register bits */
#define FLASH_LGBL_LGLK31_U32 0x80000000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK30_U32 0x40000000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK29_U32 0x20000000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK28_U32 0x10000000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK27_U32 0x08000000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK26_U32 0x04000000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK25_U32 0x02000000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK24_U32 0x01000000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK23_U32 0x00800000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK22_U32 0x00400000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK21_U32 0x00200000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK20_U32 0x00100000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK19_U32 0x00080000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK18_U32 0x00040000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK17_U32 0x00020000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK16_U32 0x00010000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK15_U32 0x00008000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK14_U32 0x00004000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK13_U32 0x00002000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK12_U32 0x00001000U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK11_U32 0x00000800U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK10_U32 0x00000400U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK9_U32  0x00000200U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK8_U32  0x00000100U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK7_U32  0x00000080U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK6_U32  0x00000040U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK5_U32  0x00000020U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK4_U32  0x00000010U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK3_U32  0x00000008U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK2_U32  0x00000004U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK1_U32  0x00000002U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */
#define FLASH_LGBL_LGLK0_U32  0x00000001U  /**< @brief HLK31-0: Large address space block LocK 31-0 (Read/Write) */

/* SEL0 - Low/Middle Block Select register bits */
#define FLASH_LMS_TSSL_U32    0x80000000U  /**< @brief TSLK: Test/Shadow address space block SeLect (Read/Write) */
#define FLASH_LMS_LSL29_U32   0x20000000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL28_U32   0x10000000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL27_U32   0x08000000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL26_U32   0x04000000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL25_U32   0x02000000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL24_U32   0x01000000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL23_U32   0x00800000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL22_U32   0x00400000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL21_U32   0x00200000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL20_U32   0x00100000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL19_U32   0x00080000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL18_U32   0x00040000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL17_U32   0x00020000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_LSL16_U32   0x00010000U  /**< @brief LSL29-0: Low address space block SeLect 29-0 (Read/Write) */
#define FLASH_LMS_MSL15_U32   0x00008000U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL14_U32   0x00004000U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL13_U32   0x00002000U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL12_U32   0x00001000U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL11_U32   0x00000800U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL10_U32   0x00000400U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL9_U32    0x00000200U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL8_U32    0x00000100U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL7_U32    0x00000080U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL6_U32    0x00000040U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL5_U32    0x00000020U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL4_U32    0x00000010U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL3_U32    0x00000008U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL2_U32    0x00000004U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL1_U32    0x00000002U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */
#define FLASH_LMS_MSL0_U32    0x00000001U  /**< @brief MSL29-0: Mid address space block SeLect 29-0(Read/Write) */

/* SEL1 - High Block Select register bits */
#define FLASH_HBS_HSL15_U32   0x00008000U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL14_U32   0x00004000U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL13_U32   0x00002000U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL12_U32   0x00001000U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL11_U32   0x00000800U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL10_U32   0x00000400U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL9_U32    0x00000200U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL8_U32    0x00000100U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL7_U32    0x00000080U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL6_U32    0x00000040U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL5_U32    0x00000020U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL4_U32    0x00000010U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL3_U32    0x00000008U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL2_U32    0x00000004U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL1_U32    0x00000002U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */
#define FLASH_HBS_HSL0_U32    0x00000001U  /**< @brief MSL15-0: High address space block SeLect 15-0(Read/Write) */

/* SEL2 - Large Block Select register bits */
#define FLASH_LGBS_LGSL31_U32 0x80000000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL30_U32 0x40000000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL29_U32 0x20000000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL28_U32 0x10000000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL27_U32 0x08000000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL26_U32 0x04000000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL25_U32 0x02000000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL24_U32 0x01000000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL23_U32 0x00800000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL22_U32 0x00400000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL21_U32 0x00200000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL20_U32 0x00100000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL19_U32 0x00080000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL18_U32 0x00040000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL17_U32 0x00020000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL16_U32 0x00010000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL15_U32 0x00008000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL14_U32 0x00004000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL13_U32 0x00002000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL12_U32 0x00001000U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL11_U32 0x00000800U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL10_U32 0x00000400U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL9_U32  0x00000200U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL8_U32  0x00000100U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL7_U32  0x00000080U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL6_U32  0x00000040U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL5_U32  0x00000020U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL4_U32  0x00000010U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL3_U32  0x00000008U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL2_U32  0x00000004U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL1_U32  0x00000002U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */
#define FLASH_LGBS_LGSL0_U32  0x00000001U  /**< @brief LGSL31-0: Large address space block SeLect 31-0 (Read/Write) */

/* UT0 register bits */
#define FLASH_UT0_AIE_U32     0x00000002U  /**< @brief AIE: Array Integrity Enable (Read/Write) */

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_FLASHC_H*/

/** @} */
