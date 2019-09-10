/**
*   @file    Reg_eSys_MC_CGM.h
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


#ifndef REG_ESYS_MC_CGM_H
#define REG_ESYS_MC_CGM_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_MC_CGM_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "Mcu_MC_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_MC_CGM_VENDOR_ID                       43
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_CGM_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_CGM_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_CGM_AR_RELEASE_REVISION_VERSION     2
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_CGM_SW_MAJOR_VERSION                1
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_CGM_SW_MINOR_VERSION                0
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_CGM_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_MC_CGM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_MC_CGM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_MC_CGM.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_MC_IPVersion header file are from the same vendor */
#if (REG_ESYS_MC_CGM_VENDOR_ID != MCU_MC_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_MC_CGM.h and Mcu_MC_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_MC_CGM_AR_RELEASE_MAJOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_MC_CGM_AR_RELEASE_MINOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_MC_CGM_AR_RELEASE_REVISION_VERSION != MCU_MC_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_MC_CGM.h and Mcu_MC_IPVersion.h are different"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Software version */
#if ((REG_ESYS_MC_CGM_SW_MAJOR_VERSION != MCU_MC_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_MC_CGM_SW_MINOR_VERSION != MCU_MC_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_MC_CGM_SW_PATCH_VERSION != MCU_MC_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_MC_CGM.h and Mcu_MC_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/********** MC_CGM Registers **********/

/***********************************************************/
/*          progresive clock switching                     */
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* PCS Switch Duration Register (MC_CGM_PCS_SDUR) */
    #define MC_CGM_PCS_SDUR_ADDR8           ((uint32)(MC_CGM_BASEADDR + (uint32)0x0700U))
    /* PCS Divider Change Register 1 Address. */
    #define MC_CGM_PCS_DIVC1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0704U))

    /* PCS Divider End Register 1 Address. */
    #define MC_CGM_PCS_DIVE1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0708U))
    /* PCS Divider Start Register 1 Address. */
    #define MC_CGM_PCS_DIVS1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x070CU))

    /* PCS Divider Change Register 2 Address. */
    #define MC_CGM_PCS_DIVC2_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0710U))

    /* PCS Divider End Register 2 Address. */
    #define MC_CGM_PCS_DIVE2_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0714U))
    /* PCS Divider Start Register 2 Address. */
    #define MC_CGM_PCS_DIVS2_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0718U))

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00 ))
    /* PCS Divider Change Register 3 Address. */
    #define MC_CGM_PCS_DIVC3_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x071CU))

    /* PCS Divider End Register 3 Address. */
    #define MC_CGM_PCS_DIVE3_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0720U))
    /* PCS Divider Start Register 3 Address. */
    #define MC_CGM_PCS_DIVS3_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0724U))

#endif /* (IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00 ) */

    /* PCS Divider Change Register 4 Address. */
    #define MC_CGM_PCS_DIVC4_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0728U))

    /* PCS Divider End Register 4 Address. */
    #define MC_CGM_PCS_DIVE4_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x072CU))
    /* PCS Divider Start Register 4 Address. */
    #define MC_CGM_PCS_DIVS4_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0730U))

#elif (IPV_MC == IPV_MC_05_00_00_10)

    /* PCS Switch Duration Register (MC_CGM_PCS_SDUR) */
    #define MC_CGM_PCS_SDUR_ADDR8           ((uint32)(MC_CGM_BASEADDR + (uint32)0x0703U))

    /* PCS Divider Change Register 1 (MC_CGM_PCS_DIVC1) */
    #define MC_CGM_PCS_DIVC1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0704U))
    /* PCS Divider End Register 1 (MC_CGM_PCS_DIVE1) */
    #define MC_CGM_PCS_DIVE1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0708U))
    /* PCS Divider Start Register 1 (MC_CGM_PCS_DIVS1) */
    #define MC_CGM_PCS_DIVS1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x070CU))

    /* PCS Divider Change Register 4 (MC_CGM_PCS_DIVC4) */
    #define MC_CGM_PCS_DIVC4_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0728U))
    /* PCS Divider End Register 4 (MC_CGM_PCS_DIVE4) */
    #define MC_CGM_PCS_DIVE4_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x072CU))
    /* PCS Divider Start Register 4 (MC_CGM_PCS_DIVS4) */
    #define MC_CGM_PCS_DIVS4_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0730U))

    /* PCS Divider Change Register 5 (MC_CGM_PCS_DIVC5) */
    #define MC_CGM_PCS_DIVC5_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0734U))
    /* PCS Divider End Register 5 (MC_CGM_PCS_DIVE5) */
    #define MC_CGM_PCS_DIVE5_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0738U))
    /* PCS Divider Start Register 5 (MC_CGM_PCS_DIVS5) */
    #define MC_CGM_PCS_DIVS5_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x073CU))

 #elif (IPV_MC == IPV_MC_05_00_00_07)

     /* PCS Switch Duration Register (MC_CGM_PCS_SDUR) */
    #define MC_CGM_PCS_SDUR_ADDR8           ((uint32)(MC_CGM_BASEADDR + (uint32)0x0700U))
    /* PCS Divider Change Register 1 Address. */
    #define MC_CGM_PCS_DIVC1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0704U))
    /* PCS Divider End Register 1 Address. */
    #define MC_CGM_PCS_DIVE1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0708U))
    /* PCS Divider Start Register 1 Address. */
    #define MC_CGM_PCS_DIVS1_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x070CU))
    /* PCS Divider Change Register 2 Address. */
    #define MC_CGM_PCS_DIVC2_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0710U))
    /* PCS Divider End Register 2 Address. */
    #define MC_CGM_PCS_DIVE2_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0714U))
    /* PCS Divider Start Register 2 Address. */
    #define MC_CGM_PCS_DIVS2_ADDR32         ((uint32)(MC_CGM_BASEADDR + (uint32)0x0718U))

#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* PCS Switch Duration Register (MC_CGM_PCS_SDUR) */
    #define MC_CGM_0_PCS_SDUR_ADDR8           ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0700U))
    /* PCS Divider Change Register 1 Address. */
    #define MC_CGM_0_PCS_DIVC1_ADDR32         ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0704U))
    /* PCS Divider End Register 1 Address. */
    #define MC_CGM_0_PCS_DIVE1_ADDR32         ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0708U))
    /* PCS Divider Start Register 1 Address. */
    #define MC_CGM_0_PCS_DIVS1_ADDR32         ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x070CU))
    /* PCS Divider Change Register 2 Address. */
    #define MC_CGM_0_PCS_DIVC2_ADDR32         ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0710U))
    /* PCS Divider End Register 2 Address. */
    #define MC_CGM_0_PCS_DIVE2_ADDR32         ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0714U))
    /* PCS Divider Start Register 2 Address. */
    #define MC_CGM_0_PCS_DIVS2_ADDR32         ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0718U))
    
    /* PCS Switch Duration Register (MC_CGM_PCS_SDUR) */
    #define MC_CGM_1_PCS_SDUR_ADDR8           ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x0700U))
    /* PCS Divider Change Register 1 Address. */
    #define MC_CGM_1_PCS_DIVC1_ADDR32         ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x0704U))
    /* PCS Divider End Register 1 Address. */
    #define MC_CGM_1_PCS_DIVE1_ADDR32         ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x0708U))
    /* PCS Divider Start Register 1 Address. */
    #define MC_CGM_1_PCS_DIVS1_ADDR32         ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x070CU))
    /* PCS Divider Change Register 2 Address. */
    #define MC_CGM_1_PCS_DIVC2_ADDR32         ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x0710U))
    /* PCS Divider End Register 2 Address. */
    #define MC_CGM_1_PCS_DIVE2_ADDR32         ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x0714U))
    /* PCS Divider Start Register 2 Address. */
    #define MC_CGM_1_PCS_DIVS2_ADDR32         ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x0718U))

    /* PCS Switch Duration Register (MC_CGM_PCS_SDUR) */
    #define MC_CGM_2_PCS_SDUR_ADDR8           ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0700U))
    /* PCS Divider Change Register 1 Address. */
    #define MC_CGM_2_PCS_DIVC1_ADDR32         ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0704U))
    /* PCS Divider End Register 1 Address. */
    #define MC_CGM_2_PCS_DIVE1_ADDR32         ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0708U))
    /* PCS Divider Start Register 1 Address. */
    #define MC_CGM_2_PCS_DIVS1_ADDR32         ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x070CU))
    /* PCS Divider Change Register 2 Address. */
    #define MC_CGM_2_PCS_DIVC2_ADDR32         ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0710U))
    /* PCS Divider End Register 2 Address. */
    #define MC_CGM_2_PCS_DIVE2_ADDR32         ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0714U))
    /* PCS Divider Start Register 2 Address. */
    #define MC_CGM_2_PCS_DIVS2_ADDR32         ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0718U))
    
    /* PCS Switch Duration Register (MC_CGM_PCS_SDUR) */
    #define MC_CGM_3_PCS_SDUR_ADDR8           ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x0700U))
    /* PCS Divider Change Register 1 Address. */
    #define MC_CGM_3_PCS_DIVC1_ADDR32         ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x0704U))
    /* PCS Divider End Register 1 Address. */
    #define MC_CGM_3_PCS_DIVE1_ADDR32         ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x0708U))
    /* PCS Divider Start Register 1 Address. */
    #define MC_CGM_3_PCS_DIVS1_ADDR32         ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x070CU))
    /* PCS Divider Change Register 2 Address. */
    #define MC_CGM_3_PCS_DIVC2_ADDR32         ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x0710U))
    /* PCS Divider End Register 2 Address. */
    #define MC_CGM_3_PCS_DIVE2_ADDR32         ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x0714U))
    /* PCS Divider Start Register 2 Address. */
    #define MC_CGM_3_PCS_DIVS2_ADDR32         ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x0718U))
#endif


/***********************************************************/
/********************    MC_CGM_UPD     ********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_05_00_00_10) ||\
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_04_06_05_00) \
    )

    /* System Clock Divider Ratio Change Register (MC_CGM_SC_DIV_RC) */
    #define MC_CGM_SC_DIV_RC_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x07D0U))
    /* Divider Update Type (MC_CGM_DIV_UPD_TYPE) */
    #define MC_CGM_DIV_UPD_TYPE_ADDR32              ((uint32)(MC_CGM_BASEADDR + (uint32)0x07D4U))
    /* Divider Update Trigger (MC_CGM_DIV_UPD_TRIG) */
    #define MC_CGM_DIV_UPD_TRIG_ADDR32              ((uint32)(MC_CGM_BASEADDR + (uint32)0x07D8U))
    /* Divider Update Status (MC_CGM_DIV_UPD_STAT) */
    #define MC_CGM_DIV_UPD_STAT_ADDR32              ((uint32)(MC_CGM_BASEADDR + (uint32)0x07DCU))

#endif /* ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_00_15_15) ||
           (IPV_MC == IPV_MC_04_01_00_00)) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* System Clock Divider Ratio Change Register (MC_CGM_SC_DIV_RC) */
    #define MC_CGM_0_SC_DIV_RC_ADDR32                 ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x07D0U))
    /* Divider Update Type (MC_CGM_DIV_UPD_TYPE) */
    #define MC_CGM_0_DIV_UPD_TYPE_ADDR32              ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x07D4U))
    /* Divider Update Trigger (MC_CGM_DIV_UPD_TRIG) */
    #define MC_CGM_0_DIV_UPD_TRIG_ADDR32              ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x07D8U))
    /* Divider Update Status (MC_CGM_DIV_UPD_STAT) */
    #define MC_CGM_0_DIV_UPD_STAT_ADDR32              ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x07DCU))
    
    /* System Clock Divider Ratio Change Register (MC_CGM_SC_DIV_RC) */
    #define MC_CGM_1_SC_DIV_RC_ADDR32                 ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x07D0U))
    /* Divider Update Type (MC_CGM_DIV_UPD_TYPE) */
    #define MC_CGM_1_DIV_UPD_TYPE_ADDR32              ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x07D4U))
    /* Divider Update Trigger (MC_CGM_DIV_UPD_TRIG) */
    #define MC_CGM_1_DIV_UPD_TRIG_ADDR32              ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x07D8U))
    /* Divider Update Status (MC_CGM_DIV_UPD_STAT) */
    #define MC_CGM_1_DIV_UPD_STAT_ADDR32              ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x07DCU))
    
    /* System Clock Divider Ratio Change Register (MC_CGM_SC_DIV_RC) */
    #define MC_CGM_2_SC_DIV_RC_ADDR32                 ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x07D0U))
    /* Divider Update Type (MC_CGM_DIV_UPD_TYPE) */
    #define MC_CGM_2_DIV_UPD_TYPE_ADDR32              ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x07D4U))
    /* Divider Update Trigger (MC_CGM_DIV_UPD_TRIG) */
    #define MC_CGM_2_DIV_UPD_TRIG_ADDR32              ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x07D8U))
    /* Divider Update Status (MC_CGM_DIV_UPD_STAT) */
    #define MC_CGM_2_DIV_UPD_STAT_ADDR32              ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x07DCU))
    
    /* System Clock Divider Ratio Change Register (MC_CGM_SC_DIV_RC) */
    #define MC_CGM_3_SC_DIV_RC_ADDR32                 ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x07D0U))
    /* Divider Update Type (MC_CGM_DIV_UPD_TYPE) */
    #define MC_CGM_3_DIV_UPD_TYPE_ADDR32              ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x07D4U))
    /* Divider Update Trigger (MC_CGM_DIV_UPD_TRIG) */
    #define MC_CGM_3_DIV_UPD_TRIG_ADDR32              ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x07D8U))
    /* Divider Update Status (MC_CGM_DIV_UPD_STAT) */
    #define MC_CGM_3_DIV_UPD_STAT_ADDR32              ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x07DCU))
#endif

/***********************************************************/
/**********************    CGM_SC     **********************/
/***********************************************************/
/* CGM: System Clock Select Status Register Address. */
#define MC_CGM_SC_SS_ADDR32                     ((uint32)(MC_CGM_BASEADDR + (uint32)0x07E4U))

/* CGM: System Clock Divider 0 Configuration Registers Address. */
#define MC_CGM_SC_DC0_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x07E8U))
/* CGM: System Clock Divider 1 Configuration Registers Address. */
#define MC_CGM_SC_DC1_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x07ECU))
/* CGM: System Clock Divider 2 Configuration Registers Address. */
#define MC_CGM_SC_DC2_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x07F0U))
/* CGM: System Clock Divider 3 Configuration Registers Address. */
#define MC_CGM_SC_DC3_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x07F4U))
/* CGM: System Clock Divider 4 Configuration Registers Address. */
#define MC_CGM_SC_DC4_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x07F8U))
/* CGM: System Clock Divider 5 Configuration Register Address. */
#define MC_CGM_SC_DC5_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x07FCU))

#if (IPV_MC == IPV_MC_05_00_00_07)
    /* CGM: System Clock Divider 6 Configuration Register Address. */
    #define MC_CGM_SC_DC6_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0200U))
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_SC_DC6_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0400U))
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: System Clock Select Status Register Address. */
    #define MC_CGM_0_SC_SS_ADDR32                     ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x07E4U))
    /* CGM: System Clock Divider 0 Configuration Registers Address. */
    #define MC_CGM_0_SC_DC0_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x07E8U))
    /* CGM: System Clock Divider 1 Configuration Registers Address. */
    #define MC_CGM_0_SC_DC1_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x07ECU))
    /* CGM: System Clock Divider 2 Configuration Registers Address. */
    #define MC_CGM_0_SC_DC2_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x07F0U))
    
    /* CGM: System Clock Select Status Register Address. */
    #define MC_CGM_1_SC_SS_ADDR32                     ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x07E4U))
    /* CGM: System Clock Divider 0 Configuration Registers Address. */
    #define MC_CGM_1_SC_DC0_ADDR32                    ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x07E8U))
    /* CGM: System Clock Divider 1 Configuration Registers Address. */
    #define MC_CGM_1_SC_DC1_ADDR32                    ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x07ECU))
    /* CGM: System Clock Divider 2 Configuration Registers Address. */
    #define MC_CGM_1_SC_DC2_ADDR32                    ((uint32)(MC_CGM_1_BASEADDR + (uint32)0x07F0U))
    
    /* CGM: System Clock Select Status Register Address. */
    #define MC_CGM_2_SC_SS_ADDR32                     ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x07E4U))
    /* CGM: System Clock Divider 0 Configuration Registers Address. */
    #define MC_CGM_2_SC_DC0_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x07E8U))
    
    /* CGM: System Clock Select Status Register Address. */
    #define MC_CGM_3_SC_SS_ADDR32                     ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x07E4U))
    /* CGM: System Clock Divider 0 Configuration Registers Address. */
    #define MC_CGM_3_SC_DC0_ADDR32                    ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x07E8U))
    /* CGM: System Clock Divider 1 Configuration Registers Address. */
    #define MC_CGM_3_SC_DC1_ADDR32                    ((uint32)(MC_CGM_3_BASEADDR + (uint32)0x07ECU))
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define SRC_GPR1_ADDR32                           ((uint32)(SRC_BASEADDR + (uint32)0x0100U))
#endif


/***********************************************************/
/**********************  CGM_CLKOUT1  **********************/
/***********************************************************/
/* CGM: Clkout 1 Select Register Address */
#define MC_CGM_CLKOUT1_SC_ADDR32               ((uint32)(MC_CGM_BASEADDR + (uint32)0x0180U))

/* CLKOUT1_DC Configuration Register Address */
#define MC_CGM_CLKOUT1_DC_ADDR32               ((uint32)(MC_CGM_BASEADDR + (uint32)0x0188U))

/***********************************************************/
/**********************    CGM_AC0    **********************/
/***********************************************************/
#define MC_CGM_AC0_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0800U))

/* CGM: Auxiliary Clock 0 Select Status Register Address. */
#define MC_CGM_AC0_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0804U))

/* CGM: Auxiliary Clock 0 Divider Configuration Register 0 Address. */
#define MC_CGM_AC0_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0808U))
/* CGM: Auxiliary Clock 0 Divider Configuration Register 1 Address. */
#define MC_CGM_AC0_DC1_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x080CU))
/* CGM: Auxiliary Clock 0 Divider Configuration Register 2 Address. */
#define MC_CGM_AC0_DC2_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0810U))
/* CGM: Auxiliary Clock 0 Divider Configuration Register 3 Address. */
#define MC_CGM_AC0_DC3_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0814U))
/* CGM: Auxiliary Clock 0 Divider Configuration Register 4 Address. */
#define MC_CGM_AC0_DC4_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0818U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 0 Select Control Register Address. */
    #define MC_CGM_0_AC0_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0800U))
    /* CGM: Auxiliary Clock 0 Select Status Register Address. */
    #define MC_CGM_0_AC0_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0804U))
    /* CGM: Auxiliary Clock 0 Divider Configuration Register 0 Address. */
    #define MC_CGM_0_AC0_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0808U))
    
    /* CGM: Auxiliary Clock 0 Select Control Register Address. */
    #define MC_CGM_2_AC0_SC_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0800U))
    /* CGM: Auxiliary Clock 0 Select Status Register Address. */
    #define MC_CGM_2_AC0_SS_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0804U))
    /* CGM: Auxiliary Clock 0 Divider Configuration Register 0 Address. */
    #define MC_CGM_2_AC0_DC0_ADDR32                   ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0808U))
#endif

/***********************************************************/
/**********************    CGM_AC1    **********************/
/***********************************************************/

/* CGM: Auxiliary Clock 1 Select Control Register Address. */
#define MC_CGM_AC1_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0820U))

/* CGM: Auxiliary Clock 1 Select Status Register Address. */
#define MC_CGM_AC1_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0824U))

/* CGM: Auxiliary Clock 1 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC1_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0828U))
/* CGM: Auxiliary Clock 1 Divider1 Configuration Register 1 Address. */
#define MC_CGM_AC1_DC1_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x082CU))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 2 Select Control Register Address. */
    #define MC_CGM_0_AC1_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0820U))
    /* CGM: Auxiliary Clock 2 Select Status Register Address. */
    #define MC_CGM_0_AC1_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0824U))
    /* CGM: Auxiliary Clock 2 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC1_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0828U))
#endif
/***********************************************************/
/**********************    CGM_AC2    **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 2 Select Control Register Address. */
#define MC_CGM_AC2_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0840U))

/* CGM: Auxiliary Clock 2 Select Status Register Address. */
#define MC_CGM_AC2_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0844U))

/* CGM: Auxiliary Clock 2 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC2_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0848U))
/* CGM: Auxiliary Clock 2 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC2_DC1_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x084CU))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 2 Select Control Register Address. */
    #define MC_CGM_0_AC2_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0840U))
    /* CGM: Auxiliary Clock 2 Select Status Register Address. */
    #define MC_CGM_0_AC2_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0844U))
    /* CGM: Auxiliary Clock 2 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC2_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0848U))
    
    /* CGM: Auxiliary Clock 2 Select Control Register Address. */
    #define MC_CGM_2_AC2_SC_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0840U))
    /* CGM: Auxiliary Clock 2 Select Status Register Address. */
    #define MC_CGM_2_AC2_SS_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0844U))
    /* CGM: Auxiliary Clock 2 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_2_AC2_DC0_ADDR32                   ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0848U))
#endif

/***********************************************************/
/**********************    CGM_AC3    **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 3 Select Control Register Address. */
#define MC_CGM_AC3_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0860U))

/* CGM: Auxiliary Clock 3 Select Status Register Address. */
#define MC_CGM_AC3_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0864U))

/* CGM: Auxiliary Clock 3 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC3_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0868U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 3 Select Control Register Address. */
    #define MC_CGM_0_AC3_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0860U))
    /* CGM: Auxiliary Clock 3 Select Status Register Address. */
    #define MC_CGM_0_AC3_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0864U))
    /* CGM: Auxiliary Clock 3 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC3_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0868U))
    
    /* CGM: Auxiliary Clock 3 Select Control Register Address. */
    #define MC_CGM_2_AC3_SC_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0860U))
    /* CGM: Auxiliary Clock 3 Select Status Register Address. */
    #define MC_CGM_2_AC3_SS_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0864U))
    /* CGM: Auxiliary Clock 3 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_2_AC3_DC0_ADDR32                   ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0868U))
#endif

/***********************************************************/
/**********************    CGM_AC4    **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 4 Select Control Register Address. */
#define MC_CGM_AC4_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0880U))

/* CGM: Auxiliary Clock 4 Select Status Register Address. */
#define MC_CGM_AC4_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0884U))

/* CGM: Auxiliary Clock 4 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC4_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0888U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 4 Select Control Register Address. */
    #define MC_CGM_0_AC4_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0880U))
    /* CGM: Auxiliary Clock 4 Select Status Register Address. */
    #define MC_CGM_0_AC4_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0884U))
    /* CGM: Auxiliary Clock 4 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC4_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0888U))
    
    /* CGM: Auxiliary Clock 4 Select Control Register Address. */
    #define MC_CGM_2_AC4_SC_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0880U))
    /* CGM: Auxiliary Clock 4 Select Status Register Address. */
    #define MC_CGM_2_AC4_SS_ADDR32                    ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0884U))
    /* CGM: Auxiliary Clock 4 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_2_AC4_DC0_ADDR32                   ((uint32)(MC_CGM_2_BASEADDR + (uint32)0x0888U))
#endif

/***********************************************************/
/**********************    CGM_AC5    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) \
    )
    /* CGM: Auxiliary Clock 5 Select Control Register Address. */
    #define MC_CGM_AC5_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x08A0U))

    /* CGM: Auxiliary Clock 5 Select Status Register Address. */
    #define MC_CGM_AC5_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x08A4U))

    /* CGM: Auxiliary Clock 5 Divider0 Configuration Register Address. */
    #define MC_CGM_AC5_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x08A8U))
    /* CGM: Auxiliary Clock 5 Divider1 Configuration Register Address. */
    #define MC_CGM_AC5_DC1_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x08ACU))
    /* CGM: Auxiliary Clock 5 Divider0 Configuration Register Address. */
    #define MC_CGM_AC5_DC2_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x08B0U))

    /* Auxiliary Clock 5 Cascaded Divider 0 Configuration Register (MC_CGM_AC5_CDC0) */
    #define MC_CGM_AC5_CDC0_ADDR32                  ((uint32)(MC_CGM_BASEADDR + (uint32)0x0680U))
    /* Auxiliary Clock 5 Cascaded Divider 1 Configuration Register (MC_CGM_AC5_CDC1) */
    #define MC_CGM_AC5_CDC1_ADDR32                  ((uint32)(MC_CGM_BASEADDR + (uint32)0x0684U))
    /* Auxiliary Clock 5 Cascaded Divider 2 Configuration Register (MC_CGM_AC5_CDC2) */
    #define MC_CGM_AC5_CDC2_ADDR32                  ((uint32)(MC_CGM_BASEADDR + (uint32)0x0688U))
    /* Auxiliary Clock 5 Cascaded Divider 10 Configuration Register (MC_CGM_AC5_CDC10) */
    #define MC_CGM_AC5_CDC10_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x0690U))
    /* Auxiliary Clock 5 Cascaded Divider 11 Configuration Register (MC_CGM_AC5_CDC11) */
    #define MC_CGM_AC5_CDC11_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x0694U))
    /* Auxiliary Clock 5 Cascaded Divider 12 Configuration Register (MC_CGM_AC5_CDC12) */
    #define MC_CGM_AC5_CDC12_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x0698U))
    /* Auxiliary Clock 5 Cascaded Divider 13 Configuration Register (MC_CGM_AC5_CDC13) */
    #define MC_CGM_AC5_CDC13_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x069CU))
    /* Auxiliary Clock 5 Cascaded Divider 20 Configuration Register (MC_CGM_AC5_CDC20) */
    #define MC_CGM_AC5_CDC20_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x06A0U))
    /* Auxiliary Clock 5 Cascaded Divider 21 Configuration Register (MC_CGM_AC5_CDC21) */
    #define MC_CGM_AC5_CDC21_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x06A4U))
    /* Auxiliary Clock 5 Cascaded Divider 22 Configuration Register (MC_CGM_AC5_CDC22) */
    #define MC_CGM_AC5_CDC22_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x06A8U))
    /* Auxiliary Clock 5 Cascaded Divider 23 Configuration Register (MC_CGM_AC5_CDC23) */
    #define MC_CGM_AC5_CDC23_ADDR32                 ((uint32)(MC_CGM_BASEADDR + (uint32)0x06ACU))

#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* CGM: Auxiliary Clock 5 Select Control Register Address. */
    #define MC_CGM_AC5_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x01C0U))
    /* CGM: Auxiliary Clock 5 Select Status Register Address. */
    #define MC_CGM_AC5_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x01C4U))
#endif


#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 5 Select Control Register Address. */
    #define MC_CGM_0_AC5_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08A0U))
    /* CGM: Auxiliary Clock 5 Select Status Register Address. */
    #define MC_CGM_0_AC5_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08A4U))
    /* CGM: Auxiliary Clock 5 Divider0 Configuration Register Address. */
    #define MC_CGM_0_AC5_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08A8U))
    /* CGM: Auxiliary Clock 5 Divider1 Configuration Register Address. */
    #define MC_CGM_0_AC5_DC1_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08ACU))
#endif

/***********************************************************/
/**********************    CGM_AC6    **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 6 Select Control Register Address. */
#define MC_CGM_AC6_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x08C0U))

/* CGM: Auxiliary Clock 6 Select Status Register Address. */
#define MC_CGM_AC6_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x08C4U))

/* CGM: Auxiliary Clock 6 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC6_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x08C8U))
/* CGM: Auxiliary Clock 6 Divider0 Configuration Register 1 Address. */
#define MC_CGM_AC6_DC1_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x08CCU))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 6 Select Control Register Address. */
    #define MC_CGM_0_AC6_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08C0U))
    /* CGM: Auxiliary Clock 6 Select Status Register Address. */
    #define MC_CGM_0_AC6_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08C4U))
    /* CGM: Auxiliary Clock 6 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC6_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08C8U))
#endif

/***********************************************************/
/**********************    CGM_AC7    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) \
    )

    /* CGM: Auxiliary Clock 7 Select Control Register Address. */
    #define MC_CGM_AC7_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x08E0U))

    /* CGM: Auxiliary Clock 7 Select Status Register Address. */
    #define MC_CGM_AC7_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x08E4U))

    /* CGM: Auxiliary Clock 7 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_AC7_DC0_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x08E8U))
    /* CGM: Auxiliary Clock 7 Divider0 Configuration Register 1 Address. */
    #define MC_CGM_AC7_DC1_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x08ECU))

#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 7 Select Control Register Address. */
    #define MC_CGM_0_AC7_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08E0U))
    /* CGM: Auxiliary Clock 7 Select Status Register Address. */
    #define MC_CGM_0_AC7_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08E4U))
    /* CGM: Auxiliary Clock 7 Divider0 Configuration Register 1 Address. */
    #define MC_CGM_0_AC7_DC1_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x08ECU))
#endif

/***********************************************************/
/**********************    CGM_AC8    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) \
    )

    /* CGM: Auxiliary Clock 8 Select Control Register Address. */
    #define MC_CGM_AC8_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0900U))

    /* CGM: Auxiliary Clock 8 Select Status Register Address. */
    #define MC_CGM_AC8_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0904U))

    /* CGM: Auxiliary Clock 8 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_AC8_DC0_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0908U))

#elif (IPV_MC == IPV_MC_05_00_00_07)

    /* CGM: Auxiliary Clock 8 Select Control Register Address. */
    #define MC_CGM_AC8_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0280U))

    /* CGM: Auxiliary Clock 8 Select Status Register Address. */
    #define MC_CGM_AC8_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0284U))

#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 8 Select Control Register Address. */
    #define MC_CGM_0_AC8_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0900U))
    /* CGM: Auxiliary Clock 8 Select Status Register Address. */
    #define MC_CGM_0_AC8_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0904U))
    /* CGM: Auxiliary Clock 8 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC8_DC0_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0908U))
    /* CGM: Auxiliary Clock 8 Divider1 Configuration Register 1 Address. */
    #define MC_CGM_0_AC8_DC1_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x090CU))
#endif
/***********************************************************/
/**********************    CGM_AC9    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) \
    )

    /* CGM: Auxiliary Clock 9 Select Control Register Address. */
    /* For IPV_MC_04_06_05_00 this address is intentionally wrong,
    just to differentiate AC9 from AC14 */
    #define MC_CGM_AC9_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0920U))

    /* CGM: Auxiliary Clock 9 Select Status Register Address. */
    #define MC_CGM_AC9_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0924U))

    /* CGM: Auxiliary Clock 9 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_AC9_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0928U))

#elif (IPV_MC == IPV_MC_05_00_00_07)

    /* CGM: Auxiliary Clock 9 Select Control Register Address. */
    #define MC_CGM_AC9_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x02C0U))

    /* CGM: Auxiliary Clock 9 Select Status Register Address. */
    #define MC_CGM_AC9_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x02C4U))

#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 9 Select Control Register Address. */
    #define MC_CGM_0_AC9_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0920U))
    /* CGM: Auxiliary Clock 9 Select Status Register Address. */
    #define MC_CGM_0_AC9_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0924U))
    /* CGM: Auxiliary Clock 9 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC9_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0928U))
    /* CGM: Auxiliary Clock 9 Divider1 Configuration Register 1 Address. */
    #define MC_CGM_0_AC9_DC1_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x092CU))
#endif

/***********************************************************/
/**********************    CGM_AC10   **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 10 Select Control Register Address. */
#define MC_CGM_AC10_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0940U))

/* CGM: Auxiliary Clock 10 Select Status Register Address. */
#define MC_CGM_AC10_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0944U))

/* CGM: Auxiliary Clock 10 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC10_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x0948U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 10 Select Control Register Address. */
    #define MC_CGM_0_AC10_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0940U))
    /* CGM: Auxiliary Clock 10 Select Status Register Address. */
    #define MC_CGM_0_AC10_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0944U))
    /* CGM: Auxiliary Clock 10 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC10_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0948U))
    /* CGM: Auxiliary Clock 10 Divider1 Configuration Register 0 Address. */
    #define MC_CGM_0_AC10_DC1_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x094CU))
#endif

/***********************************************************/
/**********************    CGM_AC11   **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 11 Select Control Register Address. */
#define MC_CGM_AC11_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0960U))

/* CGM: Auxiliary Clock 11 Select Status Register Address. */
#define MC_CGM_AC11_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0964U))

/* CGM: Auxiliary Clock 11 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC11_DC0_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0968U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 11 Select Control Register Address. */
    #define MC_CGM_0_AC11_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0960U))
    /* CGM: Auxiliary Clock 11 Select Status Register Address. */
    #define MC_CGM_0_AC11_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0964U))
    /* CGM: Auxiliary Clock 11 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC11_DC0_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0968U))
#endif

/***********************************************************/
/**********************    CGM_AC12   **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 12 Select Control Register Address. */
#define MC_CGM_AC12_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0980U))

/* CGM: Auxiliary Clock 12 Select Status Register Address. */
#define MC_CGM_AC12_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0984U))

/* CGM: Auxiliary Clock 12 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC12_DC0_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x0988U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 12 Select Control Register Address. */
    #define MC_CGM_0_AC12_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0980U))
    /* CGM: Auxiliary Clock 12 Select Status Register Address. */
    #define MC_CGM_0_AC12_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0984U))
    /* CGM: Auxiliary Clock 12 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC12_DC0_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x0988U))
#endif

/***********************************************************/
/**********************    CGM_AC13   **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 13 Select Control Register Address. */
#define MC_CGM_AC13_SC_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x09A0U))

/* CGM: Auxiliary Clock 13 Select Status Register Address. */
#define MC_CGM_AC13_SS_ADDR32                    ((uint32)(MC_CGM_BASEADDR + (uint32)0x09A4U))

/* CGM: Auxiliary Clock 13 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC13_DC0_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x09A8U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 13 Select Control Register Address. */
    #define MC_CGM_0_AC13_SC_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x09A0U))
    /* CGM: Auxiliary Clock 13 Select Status Register Address. */
    #define MC_CGM_0_AC13_SS_ADDR32                    ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x09A4U))
    /* CGM: Auxiliary Clock 13 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC13_DC0_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x09A8U))
#endif

/***********************************************************/
/**********************    CGM_AC14   **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 14 Select Control Register Address. */
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_CGM_AC14_SC_ADDR32               ((uint32)((uint32)0xFFC10028U))
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AC14_SC_ADDR32               ((uint32)(MC_CGM_BASEADDR + (uint32)0x09C0U))
#endif
/* CGM: Auxiliary Clock 14 Select Status Register Address. */
#define MC_CGM_AC14_SS_ADDR32                   ((uint32)(MC_CGM_BASEADDR + (uint32)0x09C4U))

/* CGM: Auxiliary Clock 14 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC14_DC0_ADDR32                  ((uint32)(MC_CGM_BASEADDR + (uint32)0x09C8U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 14 Select Control Register Address. */
    #define MC_CGM_0_AC14_SC_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x09C0U))
    /* CGM: Auxiliary Clock 14 Select Status Register Address. */
    #define MC_CGM_0_AC14_SS_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x09C4U))
    /* CGM: Auxiliary Clock 14 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC14_DC0_ADDR32                  ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x09C8U))
#endif

/***********************************************************/
/**********************    CGM_AC15   **********************/
/***********************************************************/
/* CGM: Auxiliary Clock 15 Select Control Register Address. */
#define MC_CGM_AC15_SC_ADDR32                   ((uint32)(MC_CGM_BASEADDR +(uint32)0x09E0U))

/* CGM: Auxiliary Clock 15 Select Status Register Address. */
#define MC_CGM_AC15_SS_ADDR32                   ((uint32)(MC_CGM_BASEADDR +(uint32)0x09E4U))

/* CGM: Auxiliary Clock 15 Divider0 Configuration Register 0 Address. */
#define MC_CGM_AC15_DC0_ADDR32                  ((uint32)(MC_CGM_BASEADDR + (uint32)0x09E8U))
/* CGM: Auxiliary Clock 15 Divider0 Configuration Register 1 Address. */
#define MC_CGM_AC15_DC1_ADDR32                  ((uint32)(MC_CGM_BASEADDR + (uint32)0x09ECU))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM: Auxiliary Clock 15 Select Control Register Address. */
    #define MC_CGM_0_AC15_SC_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR +(uint32)0x09E0U))
    /* CGM: Auxiliary Clock 15 Select Status Register Address. */
    #define MC_CGM_0_AC15_SS_ADDR32                   ((uint32)(MC_CGM_0_BASEADDR +(uint32)0x09E4U))
    /* CGM: Auxiliary Clock 15 Divider0 Configuration Register 0 Address. */
    #define MC_CGM_0_AC15_DC0_ADDR32                  ((uint32)(MC_CGM_0_BASEADDR + (uint32)0x09E8U))
#endif

/***************** MC_CGM Registers Masks ******************/
/***********************************************************/
/**********************    CGM_PCS    **********************/
/***********************************************************/
#define MC_CGM_PCS_DIVC_RWBITS_MASK32               ((uint32)0xFFFF00FFU)
#define MC_CGM_PCS_DIVC_RESBITS_MASK32              ((uint32)0x00000000U)
#define MC_CGM_PCS_DIVS_RWBITS_MASK32               ((uint32)0x000FFFFFU)
#define MC_CGM_PCS_DIVS_RESBITS_MASK32              ((uint32)0x00000000U)
#define MC_CGM_PCS_DIVE_RWBITS_MASK32               ((uint32)0x000FFFFFU)
#define MC_CGM_PCS_DIVE_RESBITS_MASK32              ((uint32)0x00000000U)

/* MC_CGM_PCS_DIVCn[INIT] field mask. */
#define MC_CGM_PCS_DIVC_INIT_U32_MASK32             ((uint32)0xFFFF0000U)

/* MC_CGM_PCS_DIVCn[RATE] field mask. */
#define MC_CGM_PCS_DIVC_RATE_U32_MASK32             ((uint32)0x000000FFU)

/* MC_CGM_DIVSn[DIVS] field mask. */
#define MC_CGM_PCS_DIVS_U32_RATE_MASK32             ((uint32)0x000FFFFFU)

/* MC_CGM_DIVEn[DIVE] field mask. */
#define MC_CGM_PCS_DIVE_U32_RATE_MASK32             ((uint32)0x000FFFFFU)


/***********************************************************/
/********************    MC_CGM_UPD     ********************/
/***********************************************************/

/* System Clock Divider Ratio Change Register (MC_CGM_SC_DIV_RC) */
#define MC_CGM_SC_DIV_RC_RWBITS_MASK32                  ((uint32)0x00000001U)
#define MC_CGM_SC_DIV_RC_RESBITS_MASK32                 ((uint32)0x00000000U)

/* MC_CGM_SC_DIV_RC[SYS_DIV_RATIO_CHNG] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_SC_DIV_RC_SYS_DIV_RATIO_CHNG_U32_MASK32  ((uint32)0x00000001U)


#if (IPV_MC == IPV_MC_04_06_01_00)
    /* Divider Update Type (MC_CGM_DIV_UPD_TYPE) */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_TYPE_RWBITS_MASK32               ((uint32)0x80000767U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_TYPE_RESBITS_MASK32              ((uint32)0x00000000U)

#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* Divider Update Type (MC_CGM_DIV_UPD_TYPE) */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_TYPE_RWBITS_MASK32               ((uint32)0x80000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_TYPE_RESBITS_MASK32              ((uint32)0x00000000U)

#elif (IPV_MC == IPV_MC_05_00_00_10)

    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_TYPE_RWBITS_MASK32               ((uint32)0x8000FFFFU)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_TYPE_RESBITS_MASK32              ((uint32)0x00000000U)

#elif (IPV_MC == IPV_MC_05_00_00_07)

    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_TYPE_RWBITS_MASK32               ((uint32)0x80000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_TYPE_RESBITS_MASK32              ((uint32)0x00000000U)

#elif (IPV_MC == IPV_MC_06_00_00_10)

    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_0_DIV_UPD_TYPE_RWBITS_MASK32               ((uint32)0x80000300U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_0_DIV_UPD_TYPE_RESBITS_MASK32              ((uint32)0x00000000U)
    
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_1_DIV_UPD_TYPE_RWBITS_MASK32               ((uint32)0x80000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_1_DIV_UPD_TYPE_RESBITS_MASK32              ((uint32)0x00000000U)
    
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_2_DIV_UPD_TYPE_RWBITS_MASK32               ((uint32)0x80000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_2_DIV_UPD_TYPE_RESBITS_MASK32              ((uint32)0x00000000U)
    
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_3_DIV_UPD_TYPE_RWBITS_MASK32               ((uint32)0x80000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_3_DIV_UPD_TYPE_RESBITS_MASK32              ((uint32)0x00000000U)
    
#endif

/* MC_CGM_DIV_UPD_TYPE[SYS_UPD_TYPE] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_SYS_UPD_TYPE_U32_MASK32     ((uint32)0x80000000U)

/* MC_CGM_DIV_UPD_TYPE[AUX15 .. 0_UPD_TYPE] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX15_UPD_TYPE_U32_MASK32   ((uint32)0x00008000U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX14_UPD_TYPE_U32_MASK32   ((uint32)0x00004000U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX13_UPD_TYPE_U32_MASK32   ((uint32)0x00002000U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX12_UPD_TYPE_U32_MASK32   ((uint32)0x00001000U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX11_UPD_TYPE_U32_MASK32   ((uint32)0x00000800U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX10_UPD_TYPE_U32_MASK32   ((uint32)0x00000400U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX9_UPD_TYPE_U32_MASK32    ((uint32)0x00000200U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX8_UPD_TYPE_U32_MASK32    ((uint32)0x00000100U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX7_UPD_TYPE_U32_MASK32    ((uint32)0x00000080U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX6_UPD_TYPE_U32_MASK32    ((uint32)0x00000040U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX5_UPD_TYPE_U32_MASK32    ((uint32)0x00000020U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX4_UPD_TYPE_U32_MASK32    ((uint32)0x00000010U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX3_UPD_TYPE_U32_MASK32    ((uint32)0x00000008U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX2_UPD_TYPE_U32_MASK32    ((uint32)0x00000004U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX1_UPD_TYPE_U32_MASK32    ((uint32)0x00000002U)
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_TYPE_AUX0_UPD_TYPE_U32_MASK32    ((uint32)0x00000001U)


/* Divider Update Trigger (MC_CGM_DIV_UPD_TRIG) */
#define MC_CGM_DIV_UPD_TRIG_RWBITS_MASK32               ((uint32)0xFFFFFFFFU)
#define MC_CGM_DIV_UPD_TRIG_RESBITS_MASK32              ((uint32)0x00000000U)

#if (IPV_MC == IPV_MC_04_06_01_00)
    /* Divider Update Status (MC_CGM_DIV_UPD_STAT) */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_STAT_RWBITS_MASK32               ((uint32)0x80000767U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_STAT_RESBITS_MASK32              ((uint32)0x00000000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* Divider Update Status (MC_CGM_DIV_UPD_STAT) */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_STAT_RWBITS_MASK32               ((uint32)0x80000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_STAT_RESBITS_MASK32              ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)

    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_STAT_RWBITS_MASK32               ((uint32)0x8000FFFFU)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_STAT_RESBITS_MASK32              ((uint32)0x00000000U)

#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* Divider Update Status (MC_CGM_DIV_UPD_STAT) */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_STAT_RWBITS_MASK32               ((uint32)0x80000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_DIV_UPD_STAT_RESBITS_MASK32              ((uint32)0x00000000U)

#endif

/* MC_CGM_DIV_UPD_STAT[SYS_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_SYS_UPD_TYPE_U32_MASK32     ((uint32)0x80000000U)
/* MC_CGM_DIV_UPD_STAT[AUX10_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_AUX10_UPD_TYPE_U32_MASK32   ((uint32)0x00000400U)
/* MC_CGM_DIV_UPD_STAT[AUX9_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_AUX9_UPD_TYPE_U32_MASK32    ((uint32)0x00000200U)
/* MC_CGM_DIV_UPD_STAT[AUX8_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_AUX8_UPD_TYPE_U32_MASK32    ((uint32)0x00000100U)
/* MC_CGM_DIV_UPD_STAT[AUX6_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_AUX6_UPD_TYPE_U32_MASK32    ((uint32)0x00000040U)
/* MC_CGM_DIV_UPD_STAT[AUX5_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_AUX5_UPD_TYPE_U32_MASK32    ((uint32)0x00000020U)
/* MC_CGM_DIV_UPD_STAT[AUX2_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_AUX2_UPD_TYPE_U32_MASK32    ((uint32)0x00000004U)
/* MC_CGM_DIV_UPD_STAT[AUX1_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_AUX1_UPD_TYPE_U32_MASK32    ((uint32)0x00000002U)
/* MC_CGM_DIV_UPD_STAT[AUX0_UPD_STAT] field mask. */
/** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_CGM_DIV_UPD_STAT_AUX0_UPD_TYPE_U32_MASK32    ((uint32)0x00000001U)


/***********************************************************/
/**********************    CGM_SC     **********************/
/***********************************************************/
/* CGM_SC_SS[SELSTAT] bits mask. */
#define MC_CGM_SC_SS_SELSTAT_MASK32                 ((uint32)0x0F000000U)
/* CGM_SC_SS[SWTRG] bits mask. */
#define MC_CGM_SC_SS_SWTRG_MASK32                   ((uint32)0x000E0000U)
/* CGM_SC_SS[SWIP] bits mask. */
#define MC_CGM_SC_SS_SWIP_MASK32                    ((uint32)0x00010000U)


#if (IPV_MC == IPV_MC_04_04_01_00)
    /* CGM_SC_DC0[DE] bit mask. */
    #define MC_CGM_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x000F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC1[DIV] bits mask. */
    #define MC_CGM_SC_DC1_DIV_RWBITS_MASK32         ((uint32)0x001F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC1_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC2[DIV] bits mask. */
    #define MC_CGM_SC_DC2_DIV_RWBITS_MASK32         ((uint32)0x000F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC2_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC3[DIV] bits mask. */
    #define MC_CGM_SC_DC3_DIV_RWBITS_MASK32         ((uint32)0x000F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC3_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC4[DIV] bits mask. */
    #define MC_CGM_SC_DC4_DIV_RWBITS_MASK32         ((uint32)0x000F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC4_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
#elif (IPV_MC == IPV_MC_04_00_15_15)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC1[DIV] bits mask. */
    #define MC_CGM_SC_DC1_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC1_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC2[DIV] bits mask. */
    #define MC_CGM_SC_DC2_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC2_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC3[DIV] bits mask. */
    #define MC_CGM_SC_DC3_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC3_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC4[DIV] bits mask. */
    #define MC_CGM_SC_DC4_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC4_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
#elif (IPV_MC == IPV_MC_04_01_00_00)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC1[DIV] bits mask. */
    #define MC_CGM_SC_DC1_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC1_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
    /* CGM_SC_DC2[DIV] bits mask. */
    #define MC_CGM_SC_DC2_DIV_RWBITS_MASK32         ((uint32)0x003F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC2_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* MC_CGM_SC_DC0 bits mask. */
    #define MC_CGM_SC_DC0_RWBITS_MASK32             ((uint32)0x803F0000U)
    #define MC_CGM_SC_DC0_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_SC_DC0_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_SC_DC0_DIV_U32_MASK32            ((uint32)0x003F0000U)

    /* MC_CGM_SC_DC1 bits mask. */
    #define MC_CGM_SC_DC1_RWBITS_MASK32             ((uint32)0x803F0000U)
    #define MC_CGM_SC_DC1_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC1[DE] bits mask. */
    #define MC_CGM_SC_DC1_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC1[DIV] bits mask. */
    #define MC_CGM_SC_DC1_DIV_U32_MASK32            ((uint32)0x003F0000U)

    /* MC_CGM_SC_DC2 bits mask. */
    #define MC_CGM_SC_DC2_RWBITS_MASK32             ((uint32)0x803F0000U)
    #define MC_CGM_SC_DC2_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC2[DE] bits mask. */
    #define MC_CGM_SC_DC2_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC2[DIV] bits mask. */
    #define MC_CGM_SC_DC2_DIV_U32_MASK32            ((uint32)0x003F0000U)

#elif (IPV_MC == IPV_MC_05_00_00_10)

    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_SC_DC0_RWBITS_MASK32             ((uint32)0x800F0000U)
    #define MC_CGM_SC_DC0_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_SC_DC0_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_SC_DC0_DIV_U32_MASK32            ((uint32)0x000F0000U)

    /* CGM_SC_DC1[DIV] bits mask. */
    #define MC_CGM_SC_DC1_RWBITS_MASK32             ((uint32)0x80030000U)
    #define MC_CGM_SC_DC1_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC1[DE] bits mask. */
    #define MC_CGM_SC_DC1_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC1[DIV] bits mask. */
    #define MC_CGM_SC_DC1_DIV_U32_MASK32            ((uint32)0x00030000U)

    /* CGM_SC_DC2[DIV] bits mask. */
    #define MC_CGM_SC_DC2_RWBITS_MASK32             ((uint32)0x80070000U)
    #define MC_CGM_SC_DC2_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC2[DE] bits mask. */
    #define MC_CGM_SC_DC2_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC2[DIV] bits mask. */
    #define MC_CGM_SC_DC2_DIV_U32_MASK32            ((uint32)0x00070000U)

    /* CGM_SC_DC3[DIV] bits mask. */
    #define MC_CGM_SC_DC3_RWBITS_MASK32             ((uint32)0x800F0000U)
    #define MC_CGM_SC_DC3_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC3[DE] bits mask. */
    #define MC_CGM_SC_DC3_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC3[DIV] bits mask. */
    #define MC_CGM_SC_DC3_DIV_U32_MASK32            ((uint32)0x000F0000U)

    /* CGM_SC_DC4[DIV] bits mask. */
    #define MC_CGM_SC_DC4_RWBITS_MASK32             ((uint32)0x801F0000U)
    #define MC_CGM_SC_DC4_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC4[DE] bits mask. */
    #define MC_CGM_SC_DC4_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC4[DIV] bits mask. */
    #define MC_CGM_SC_DC4_DIV_U32_MASK32            ((uint32)0x001F0000U)

    /* CGM_SC_DC5[DIV] bits mask. */
    #define MC_CGM_SC_DC5_RWBITS_MASK32             ((uint32)0x800F0000U)
    #define MC_CGM_SC_DC5_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_SC_DC5[DE] bits mask. */
    #define MC_CGM_SC_DC5_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC5[DIV] bits mask. */
    #define MC_CGM_SC_DC5_DIV_U32_MASK32            ((uint32)0x000F0000U)

    /* CGM_SC_DC6[DIV] bits mask. */
    #define MC_CGM_SC_DC6_DIV_RWBITS_MASK32         ((uint32)0x80030000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC6_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC6[DE] bits mask. */
    #define MC_CGM_SC_DC6_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC6[DIV] bits mask. */
    #define MC_CGM_SC_DC6_DIV_U32_MASK32            ((uint32)0x00030000U)

#elif (IPV_MC == IPV_MC_05_00_00_07)

    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x00070000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x80000000U)

    /* CGM_SC_DC1[DIV] bits mask. */
    #define MC_CGM_SC_DC1_DIV_RWBITS_MASK32         ((uint32)0x00070000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC1_DIV_RESBITS_MASK32        ((uint32)0x80000000U)

    /* CGM_SC_DC2[DIV] bits mask. */
    #define MC_CGM_SC_DC2_DIV_RWBITS_MASK32         ((uint32)0x000F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC2_DIV_RESBITS_MASK32        ((uint32)0x80000000U)

    /* CGM_SC_DC3[DIV] bits mask. */
    #define MC_CGM_SC_DC3_DIV_RWBITS_MASK32         ((uint32)0x00000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC3_DIV_RESBITS_MASK32        ((uint32)0x80030000U)

    /* CGM_SC_DC4[DIV] bits mask. */
    #define MC_CGM_SC_DC4_DIV_RWBITS_MASK32         ((uint32)0x00000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC4_DIV_RESBITS_MASK32        ((uint32)0x80010000U)

    /* CGM_SC_DC5[DIV] bits mask. */
    #define MC_CGM_SC_DC5_DIV_RWBITS_MASK32         ((uint32)0x001F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC5_DIV_RESBITS_MASK32        ((uint32)0x80000000U)

    /* CGM_SC_DC6[DIV] bits mask. */
    #define MC_CGM_SC_DC6_DIV_RWBITS_MASK32         ((uint32)0x00000000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC6_DIV_RESBITS_MASK32        ((uint32)0x00000000U)

    /* CGM_SC_DC6[DE] bits mask. */
    #define MC_CGM_SC_DC6_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC6[DIV] bits mask. */
    #define MC_CGM_SC_DC6_DIV_U32_MASK32            ((uint32)0x00070000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#if (IPV_MC == IPV_MC_04_06_05_00)
    /* CGM_SC_DC5[DIV] bits mask. */
    #define MC_CGM_SC_DC5_DIV_RWBITS_MASK32         ((uint32)0x001F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_SC_DC5_DIV_RESBITS_MASK32        ((uint32)0x80000000U)
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_SC_DC0[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_0_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x80030000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_0_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_0_SC_DC0_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_0_SC_DC0_DIV_U32_MASK32            ((uint32)0x00030000U)
    
    /* CGM_SC_DC1[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_0_SC_DC1_DIV_RWBITS_MASK32         ((uint32)0x80030000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_0_SC_DC1_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_0_SC_DC1_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_0_SC_DC1_DIV_U32_MASK32            ((uint32)0x00030000U)
    
    /* CGM_SC_DC2[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_0_SC_DC2_DIV_RWBITS_MASK32         ((uint32)0x80070000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_0_SC_DC2_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_0_SC_DC2_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_0_SC_DC2_DIV_U32_MASK32            ((uint32)0x00070000U)
    
    /* CGM_SC_DC0[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_1_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x80030000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_1_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_1_SC_DC0_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_1_SC_DC0_DIV_U32_MASK32            ((uint32)0x00030000U)
    
    /* CGM_SC_DC1[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_1_SC_DC1_DIV_RWBITS_MASK32         ((uint32)0x80030000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_1_SC_DC1_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_1_SC_DC1_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_1_SC_DC1_DIV_U32_MASK32            ((uint32)0x00030000U)
    
    /* CGM_SC_DC2[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_1_SC_DC2_DIV_RWBITS_MASK32         ((uint32)0x800F0000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_1_SC_DC2_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_1_SC_DC2_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_1_SC_DC2_DIV_U32_MASK32            ((uint32)0x000F0000U)
       
    /* CGM_SC_DC0[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_2_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x80030000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_2_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_2_SC_DC0_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_2_SC_DC0_DIV_U32_MASK32            ((uint32)0x00030000U)

    /* CGM_SC_DC0[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_3_SC_DC0_DIV_RWBITS_MASK32         ((uint32)0x80030000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_3_SC_DC0_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_3_SC_DC0_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_3_SC_DC0_DIV_U32_MASK32            ((uint32)0x00030000U)
      
    /* CGM_SC_DC1[DIV] bits mask. */
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_3_SC_DC1_DIV_RWBITS_MASK32         ((uint32)0x80030000U)
    /** @violates @ref REG_ESYS_MC_CGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_CGM_3_SC_DC1_DIV_RESBITS_MASK32        ((uint32)0x00000000U)
    /* CGM_SC_DC0[DE] bits mask. */
    #define MC_CGM_3_SC_DC1_DE_U32_MASK32             ((uint32)0x80000000U)
    /* CGM_SC_DC0[DIV] bits mask. */
    #define MC_CGM_3_SC_DC1_DIV_U32_MASK32            ((uint32)0x00030000U)
#endif

/***********************************************************/
/**********************  CGM_CLKOUT1  **********************/
/***********************************************************/
/* CGM_CLKOUT1_SC[SELCTL] bits mask. */
#define MC_CGM_CLKOUT1_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
#define MC_CGM_CLKOUT1_SC_RESBITS_MASK32            ((uint32)0x00000000U)

/* MC_CGM_CLKOUT1_DC[DE] bit mask. */
#define MC_CGM_CLKOUT1_DC_DE_MASK32             ((uint32)0x80000000U)
/* MC_CGM_CLKOUT1_DC[DIV] bit mask. */
#define MC_CGM_CLKOUT1_DC_DIV_MASK32            ((uint32)0x07FF0000U)

/***********************************************************/
/**********************    CGM_AC0    **********************/
/***********************************************************/
#if (IPV_MC == IPV_MC_04_04_01_00)

    /* CGM_AC0_SC[SELCTL] bits mask. */
    #define MC_CGM_AC0_SC_SELCTL_MASK32             ((uint32)0x03000000U)
    
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))

    /* CGM_AC0_SC[SELCTL] bits mask. */
    #define MC_CGM_AC0_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
      
    /* CGM_AC0_SC[SELCTL] bits mask. */
    #define MC_CGM_AC0_SC_SELCTL_MASK32             ((uint32)0x0F000000U)

#elif (IPV_MC == IPV_MC_05_00_00_10)

    /* CGM_AC0_SC[SELCTL] bits mask. */
    #define MC_CGM_AC0_SC_SELCTL_MASK32             ((uint32)0x01000000U)

#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC0_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC0_SC_SELCTL_MASK32             ((uint32)0x07000000U)   
    
    /* CGM_AC0_SC[SELCTL] bits mask. */
    #define MC_CGM_2_AC0_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#define MC_CGM_AC0_SC_RESBITS_MASK32                ((uint32)0x00000000U)

#if (IPV_MC == IPV_MC_04_04_01_00)
    #define MC_CGM_AC0_SS_SELSTAT_MASK32            ((uint32)0x03000000U)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AC0_SS_SELSTAT_MASK32            ((uint32)0x07000000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
    #define MC_CGM_AC0_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AC0_SS_SELSTAT_MASK32            ((uint32)0x01000000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

/* CGM_AC0_DC0 bit mask. */
#define MC_CGM_AC0_DC0_DE_MASK32                    ((uint32)0x80000000U)
#define MC_CGM_AC0_DC0_DIV_MASK32                   ((uint32)0x000F0000U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    /* CGM_AC0_DC1 bit mask. */
    #define MC_CGM_AC0_DC1_DE_MASK32                    ((uint32)0x80000000U)
    #define MC_CGM_AC0_DC1_DIV_MASK32                   ((uint32)0x007F0000U)

    /* CGM_AC0_DC2 bit mask. */
    #define MC_CGM_AC0_DC2_DE_MASK32                    ((uint32)0x80000000U)
    #define MC_CGM_AC0_DC2_DIV_MASK32                   ((uint32)0x007F0000U)
#else
    /* CGM_AC0_DC1 bit mask. */
    #define MC_CGM_AC0_DC1_DE_MASK32                    ((uint32)0x80000000U)
    #define MC_CGM_AC0_DC1_DIV_MASK32                   ((uint32)0x001F0000U)

    /* CGM_AC0_DC2 bit mask. */
    #define MC_CGM_AC0_DC2_DE_MASK32                    ((uint32)0x80000000U)
    #define MC_CGM_AC0_DC2_DIV_MASK32                   ((uint32)0x001F0000U)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

/* CGM_AC0_DC3 bit mask. */
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))

    #define MC_CGM_AC0_DC3_DE_MASK32                    ((uint32)0x80000000U)
    #define MC_CGM_AC0_DC3_DIV_MASK32                   ((uint32)0x01FF0000U)
    #define MC_CGM_AC0_DC3_DIV_FMT_MASK32               ((uint32)0x00000003U)

#elif (IPV_MC == IPV_MC_04_06_01_00)

    #define MC_CGM_AC0_DC3_DE_MASK32                    ((uint32)0x80000000U)
    #define MC_CGM_AC0_DC3_DIV_MASK32                   ((uint32)0x1FFF0000U)
    #define MC_CGM_AC0_DC3_DIV_FMT_MASK32               ((uint32)0x00000003U)

#endif

/* CGM_AC0_DC4 bit mask. */
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_CGM_AC0_DC4_DE_MASK32                    ((uint32)0x80000000U)
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define MC_CGM_AC0_DC4_DIV_MASK32                   ((uint32)0x000F0000U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_CGM_AC0_DC4_DIV_MASK32                   ((uint32)0x003F0000U)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

#if (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC0_DC1 bit mask. */
    #define MC_CGM_0_AC0_DC0_DE_MASK32                    ((uint32)0x80000000U)
    #define MC_CGM_0_AC0_DC0_DIV_MASK32                   ((uint32)0x00030000U)
    
    /* CGM_AC0_DC1 bit mask. */
    #define MC_CGM_2_AC0_DC0_DE_MASK32                    ((uint32)0x80000000U)
    #define MC_CGM_2_AC0_DC0_DIV_MASK32                   ((uint32)0x000F0000U)

#endif

/***********************************************************/
/**********************    CGM_AC1    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* CGM_AC1_SC[SELCTL] bits mask. */
    #define MC_CGM_AC1_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC1_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC1_SS[SELCTL] bits mask. */
    #define MC_CGM_AC1_SS_SELCTL_MASK32             ((uint32)0x07000000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
    /* CGM_AC1_SC[SELCTL] bits mask. */
    #define MC_CGM_AC1_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC1_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC1_SS[SELCTL] bits mask. */
    #define MC_CGM_AC1_SS_SELCTL_MASK32             ((uint32)0x0F000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC1_SC[SELCTL] bits mask. */
    #define MC_CGM_AC1_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC1_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC1_SS[SELCTL] bits mask. */
    #define MC_CGM_AC1_SS_SELCTL_MASK32             ((uint32)0x07000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* CGM_AC1_SS[SELCTL] bits mask. */
    #define MC_CGM_AC1_SS_SELCTL_MASK32             ((uint32)0x03000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM_AC1_SS[SELCTL] bits mask. */
    #define MC_CGM_0_AC1_SC_SELCTL_MASK32             ((uint32)0x07000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if ((IPV_MC == IPV_MC_04_00_15_15)|| (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    /* CGM_AC1_DC0 bit mask. */
    #define MC_CGM_AC1_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC1_DC0_DIV_MASK32               ((uint32)0x007F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AC1_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC1_DC0_DIV_MASK32               ((uint32)0x1FFF0000U)
#else
    /* CGM_AC1_DC0 bit mask. */
    #define MC_CGM_AC1_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC1_DC0_DIV_MASK32               ((uint32)0x001F0000U)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

/* CGM_AC1_DC1 bit mask. */
#if (IPV_MC == IPV_MC_04_04_01_00)
    #define MC_CGM_AC1_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC1_DC1_DIV_MASK32               ((uint32)0x003F0000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM_AC1_DC0 bit mask. */
    #define MC_CGM_0_AC1_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC1_DC0_DIV_MASK32               ((uint32)0x00030000U)
#endif

/***********************************************************/
/**********************    CGM_AC2    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* CGM_AC2_SC[SELCTL] bits mask. */
    #define MC_CGM_AC2_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC2_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC2_SS[SELCTL] bits mask. */
    #define MC_CGM_AC2_SS_SELCTL_MASK32             ((uint32)0x07000000U)

#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* CGM_AC2_SC[SELCTL] bits mask. */
    #define MC_CGM_AC2_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC2_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC2_SS[SELCTL] bits mask. */
    #define MC_CGM_AC2_SS_SELCTL_MASK32             ((uint32)0x0F000000U)

#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC2_SC[SELCTL] bits mask. */
    #define MC_CGM_AC2_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC2_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC2_SS[SELCTL] bits mask. */
    #define MC_CGM_AC2_SS_SELCTL_MASK32             ((uint32)0x07000000U)

#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* CGM_AC2_SC[SELCTL] bits mask. */
    #define MC_CGM_AC2_SC_SELCTL_MASK32             ((uint32)0x01000000U)
    #define MC_CGM_AC2_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC2_SS[SELCTL] bits mask. */
    #define MC_CGM_AC2_SS_SELCTL_MASK32             ((uint32)0x01000000U)

#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM_AC2_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC2_SC_SELCTL_MASK32             ((uint32)0x07000000U)

    /* CGM_AC2_SC[SELCTL] bits mask. */
    #define MC_CGM_2_AC2_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

/* CGM_AC2_DC0 bit mask. */
#define MC_CGM_AC2_DC0_DE_MASK32                    ((uint32)0x80000000U)

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_05_00_00_10))
    #define MC_CGM_AC2_DC0_DIV_MASK32               ((uint32)0x000F0000U)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AC2_DC0_DIV_MASK32               ((uint32)0x007F0000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
    #define MC_CGM_AC2_DC0_DIV_MASK32               ((uint32)0x003F0000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

/* CGM_AC2_DC1 bit mask. */
#define MC_CGM_AC2_DC1_DE_MASK32                ((uint32)0x80000000U)
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define MC_CGM_AC2_DC1_DIV_MASK32               ((uint32)0x003F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AC2_DC1_DIV_MASK32               ((uint32)0x000F0000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#if (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC2_DC0 bit mask. */
    #define MC_CGM_0_AC2_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC2_DC0_DIV_MASK32               ((uint32)0x00030000U)
    
    /* CGM_AC2_DC0 bit mask. */
    #define MC_CGM_2_AC2_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_2_AC2_DC0_DIV_MASK32               ((uint32)0x000F0000U)
    
#endif

/***********************************************************/
/**********************    CGM_AC3    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    /* CGM_AC3_SC[SELCTL] bits mask. */
    #define MC_CGM_AC3_SC_SELCTL_MASK32                 ((uint32)0x0F000000U)
    #define MC_CGM_AC3_SC_RESBITS_MASK32                ((uint32)0x00000000U)
    /* CGM_AC3_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC3_SS_SELSTAT_MASK32                ((uint32)0x0F000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC3_SC[SELCTL] bits mask. */
    #define MC_CGM_AC3_SC_SELCTL_MASK32                 ((uint32)0x07000000U)
    #define MC_CGM_AC3_SC_RESBITS_MASK32                ((uint32)0x00000000U)
    /* CGM_AC3_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC3_SS_SELSTAT_MASK32                ((uint32)0x07000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM_AC3_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC3_SC_SELCTL_MASK32                 ((uint32)0x0F000000U)
        
    /* CGM_AC3_SC[SELCTL] bits mask. */
    #define MC_CGM_2_AC3_SC_SELCTL_MASK32                 ((uint32)0x0F000000U)
#else
    /* CGM_AC3_SC[SELCTL] bits mask. */
    #define MC_CGM_AC3_SC_SELCTL_MASK32                 ((uint32)0x01000000U)
    #define MC_CGM_AC3_SC_RESBITS_MASK32                ((uint32)0x00000000U)
    /* CGM_AC3_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC3_SS_SELSTAT_MASK32                ((uint32)0x01000000U)
#endif 

/* CGM_AC3_DC1 bit mask. */
#define MC_CGM_AC3_DC0_DE_MASK32                ((uint32)0x80000000U)
#define MC_CGM_AC3_DC0_DIV_MASK32               ((uint32)0x000F0000U)

#if (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC3_DC0 bit mask. */
    #define MC_CGM_0_AC3_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC3_DC0_DIV_MASK32               ((uint32)0x00030000U)
    
    /* CGM_AC3_DC0 bit mask. */
    #define MC_CGM_2_AC3_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_2_AC3_DC0_DIV_MASK32               ((uint32)0x000F0000U)
    
#endif

/***********************************************************/
/**********************    CGM_AC4    **********************/
/***********************************************************/
#if (IPV_MC == IPV_MC_04_04_01_00)
    /* CGM_AC4_SC[SELCTL] bits mask. */
    #define MC_CGM_AC4_SC_SELCTL_MASK32             ((uint32)0x03000000U)
    /* CGM_AC4_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC4_SS_SELSTAT_MASK32            ((uint32)0x03000000U)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) || \
       (IPV_MC == IPV_MC_05_00_00_07) \
      )
    /* CGM_AC4_SC[SELCTL] bits mask. */
    #define MC_CGM_AC4_SC_SELCTL_MASK32             ((uint32)0x01000000U)
    /* CGM_AC4_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC4_SS_SELSTAT_MASK32            ((uint32)0x01000000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
    /* CGM_AC4_SC[SELCTL] bits mask. */
    #define MC_CGM_AC4_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    /* CGM_AC4_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC4_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC4_SC[SELCTL] bits mask. */
    #define MC_CGM_AC4_SC_SELCTL_MASK32                 ((uint32)0x07000000U)
    /* CGM_AC4_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC4_SS_SELSTAT_MASK32                ((uint32)0x07000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM_AC4_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC4_SC_SELCTL_MASK32                 ((uint32)0x0F000000U)
    /* CGM_AC4_SC[SELCTL] bits mask. */
    #define MC_CGM_2_AC4_SC_SELCTL_MASK32                 ((uint32)0x0F000000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#define MC_CGM_AC4_SC_RESBITS_MASK32                ((uint32)0x00000000U)


/* CGM_AC4_DC1 bit mask. */
#define MC_CGM_AC4_DC0_DE_MASK32                ((uint32)0x80000000U)
#define MC_CGM_AC4_DC0_DIV_MASK32               ((uint32)0x000F0000U)

#if (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC4_DC0 bit mask. */
    #define MC_CGM_0_AC4_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC4_DC0_DIV_MASK32               ((uint32)0x000F0000U)

    /* CGM_AC4_DC0 bit mask. */
    #define MC_CGM_2_AC4_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_2_AC4_DC0_DIV_MASK32               ((uint32)0x000F0000U)
#endif

/***********************************************************/
/**********************    CGM_AC5    **********************/
/***********************************************************/
#if (IPV_MC == IPV_MC_04_04_01_00)
    /* CGM_AC5_SC[SELCTL] bits mask. */
    #define MC_CGM_AC5_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC5_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC5_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC5_SS_SELSTAT_MASK32            ((uint32)0x07000000U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* CGM_AC5_SC[SELCTL] bits mask. */
    #define MC_CGM_AC5_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC5_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC5_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC5_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC5_SC[SELCTL] bits mask. */
    #define MC_CGM_AC5_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC5_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC5_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC5_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* CGM_AC5_SC[SELCTL] bits mask. */
    #define MC_CGM_AC5_SC_SELCTL_MASK32             ((uint32)0x01000000U)
    #define MC_CGM_AC5_SC_RESBITS_MASK32            ((uint32)0x00000000U)
    /* CGM_AC5_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC5_SS_SELSTAT_MASK32            ((uint32)0x01000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* CGM_AC5_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC5_SC_SELCTL_MASK32             ((uint32)0x03000000U)
#endif

/* CGM_AC5_DC0 bit mask. */
#define MC_CGM_AC5_DC0_DE_MASK32                    ((uint32)0x80000000U)

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_05_00_00_10))
    #define MC_CGM_AC5_DC0_DIV_MASK32               ((uint32)0x001F0000U)
#elif (IPV_MC == IPV_MC_04_03_00_00)
    #define MC_CGM_AC5_DC0_DIV_MASK32               ((uint32)0x000F0000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define MC_CGM_AC5_DC0_DIV_MASK32               ((uint32)0x1FFF0000U)
    #define MC_CGM_AC5_DC0_DIV_FMT_MASK32           ((uint32)0x00000003U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_CGM_AC5_DC0_DIV_MASK32               ((uint32)0x003F0000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* CGM_AC5_DC1 bit mask. */
    #define MC_CGM_AC5_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC5_DC1_DIV_MASK32               ((uint32)0x00FF0000U)
    /* CGM_AC5_DC2 bit mask. */
    #define MC_CGM_AC5_DC2_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC5_DC2_DIV_MASK32               ((uint32)0x03FF0000U)

#elif ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_10))
    /* CGM_AC5_DC1 bit mask. */
    #define MC_CGM_AC5_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC5_DC1_DIV_MASK32               ((uint32)0x003F0000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* MC_CGM_AC5_CDC0 bit mask. */
    #define MC_CGM_AC5_CDC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC0_DIV_MASK32              ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC1 bit mask. */
    #define MC_CGM_AC5_CDC1_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC1_DIV_MASK32              ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC2 bit mask. */
    #define MC_CGM_AC5_CDC2_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC2_DIV_MASK32              ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC10 bit mask. */
    #define MC_CGM_AC5_CDC10_DE_MASK32              ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC10_DIV_MASK32             ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC11 bit mask. */
    #define MC_CGM_AC5_CDC11_DE_MASK32              ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC11_DIV_MASK32             ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC12 bit mask. */
    #define MC_CGM_AC5_CDC12_DE_MASK32              ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC12_DIV_MASK32             ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC13 bit mask. */
    #define MC_CGM_AC5_CDC13_DE_MASK32              ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC13_DIV_MASK32             ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC20 bit mask. */
    #define MC_CGM_AC5_CDC20_DE_MASK32              ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC20_DIV_MASK32             ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC21 bit mask. */
    #define MC_CGM_AC5_CDC21_DE_MASK32              ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC21_DIV_MASK32             ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC22 bit mask. */
    #define MC_CGM_AC5_CDC22_DE_MASK32              ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC22_DIV_MASK32             ((uint32)0x03FF0000U)
    /* MC_CGM_AC5_CDC23 bit mask. */
    #define MC_CGM_AC5_CDC23_DE_MASK32              ((uint32)0x80000000U)
    #define MC_CGM_AC5_CDC23_DIV_MASK32             ((uint32)0x03FF0000U)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

#if (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC5_DC0 bit mask. */
    #define MC_CGM_0_AC5_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC5_DC0_DIV_MASK32               ((uint32)0x00030000U)
    /* CGM_AC5_DC1 bit mask. */
    #define MC_CGM_0_AC5_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC5_DC1_DIV_MASK32               ((uint32)0x00030000U)
    
#endif

/***********************************************************/
/**********************    CGM_AC6    **********************/
/***********************************************************/
#if (IPV_MC == IPV_MC_04_04_01_00)
    /* CGM_AC6_SC[SELCTL] bits mask. */
    #define MC_CGM_AC6_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC6_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC6_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC6_SS_SELSTAT_MASK32            ((uint32)0x07000000U)

    /* CGM_AC6_DC0 bit mask. */
    #define MC_CGM_AC6_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC6_DC0_DIV_MASK32               ((uint32)0x007F0000U)

#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* CGM_AC6_SC[SELCTL] bits mask. */
    #define MC_CGM_AC6_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC6_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC6_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC6_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)

    /* CGM_AC6_DC0 bit mask. */
    #define MC_CGM_AC6_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC6_DC0_DIV_MASK32               ((uint32)0x01FF0000U)

#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* CGM_AC6_SC[SELCTL] bits mask. */
    #define MC_CGM_AC6_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC6_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC6_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC6_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)

    /* CGM_AC6_DC0 bit mask. */
    #define MC_CGM_AC6_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC6_DC0_DIV_MASK32               ((uint32)0x003F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC6_SC[SELCTL] bits mask. */
    #define MC_CGM_AC6_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC6_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC6_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC6_SS_SELSTAT_MASK32            ((uint32)0x07000000U)

    /* CGM_AC6_DC0 bit mask. */
    #define MC_CGM_AC6_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC6_DC0_DIV_MASK32               ((uint32)0x000F0000U)

    /* CGM_AC6_DC1 bit mask. */
    #define MC_CGM_AC6_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC6_DC1_DIV_MASK32               ((uint32)0x000F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* CGM_AC6_SC[SELCTL] bits mask. */
    #define MC_CGM_AC6_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC6_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC6_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC6_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)

    /* CGM_AC6_DC0 bit mask. */
    #define MC_CGM_AC6_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC6_DC0_DIV_MASK32               ((uint32)0x001F0000U)
    #define MC_CGM_AC6_DC0_RESBITS_MASK32           ((uint32)0x80000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC6_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC6_SC_SELCTL_MASK32             ((uint32)0x03000000U)
    
    /* CGM_AC6_DC0 bit mask. */
    #define MC_CGM_0_AC6_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC6_DC0_DIV_MASK32               ((uint32)0x00030000U)
    
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */



/***********************************************************/
/**********************    CGM_AC7    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* CGM_AC7_SC[SELCTL] bits mask. */
    #define MC_CGM_AC7_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC7_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC7_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC7_SS_SELSTAT_MASK32            ((uint32)0x07000000U)

    /* CGM_AC7_DC0 bit mask. */
    #define MC_CGM_AC7_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC7_DC0_DIV_MASK32               ((uint32)0x000F0000U)

#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* CGM_AC7_SC[SELCTL] bits mask. */
    #define MC_CGM_AC7_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC7_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC7_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC7_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)

    /* CGM_AC7_DC0 bit mask. */
    #define MC_CGM_AC7_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC7_DC0_DIV_MASK32               ((uint32)0x01FF0000U)

#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC7_SC[SELCTL] bits mask. */
    #define MC_CGM_AC7_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC7_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC7_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC7_SS_SELSTAT_MASK32            ((uint32)0x07000000U)

    /* CGM_AC7_DC0 bit mask. */
    #define MC_CGM_AC7_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC7_DC0_DIV_MASK32               ((uint32)0x000F0000U)
    /* CGM_AC7_DC1 bit mask. */
    #define MC_CGM_AC7_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC7_DC1_DIV_MASK32               ((uint32)0x000F0000U)

#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC7_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC7_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    
    /* CGM_AC7_DC1 bit mask. */
    #define MC_CGM_0_AC7_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC7_DC1_DIV_MASK32               ((uint32)0x001F0000U)
    
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */


/***********************************************************/
/**********************    CGM_AC8    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* CGM_AC8_SC[SELCTL] bits mask. */
    #define MC_CGM_AC8_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC8_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC8_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC8_SS_SELSTAT_MASK32            ((uint32)0x07000000U)

    /* CGM_AC8_DC0 bit mask. */
    #define MC_CGM_AC8_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC8_DC0_DIV_MASK32               ((uint32)0x001F0000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
    /* CGM_AC8_SC[SELCTL] bits mask. */
    #define MC_CGM_AC8_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC8_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC8_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC8_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)

    /* CGM_AC8_DC0 bit mask. */
    #define MC_CGM_AC8_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC8_DC0_DIV_MASK32               ((uint32)0x003F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC8_SC[SELCTL] bits mask. */
    #define MC_CGM_AC8_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC8_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC8_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC8_SS_SELSTAT_MASK32            ((uint32)0x07000000U)

    /* CGM_AC8_DC0 bit mask. */
    #define MC_CGM_AC8_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC8_DC0_DIV_MASK32               ((uint32)0x000F0000U)

#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* CGM_AC8_SC[SELCTL] bits mask. */
    #define MC_CGM_AC8_SC_SELCTL_MASK32             ((uint32)0x01000000U)
    #define MC_CGM_AC8_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC8_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC8_SS_SELSTAT_MASK32            ((uint32)0x01000000U)

#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC8_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC8_SC_SELCTL_MASK32             ((uint32)0x07000000U)

    /* CGM_AC8_DC0 bit mask. */
    #define MC_CGM_0_AC8_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC8_DC0_DIV_MASK32               ((uint32)0x00030000U)
    
    /* CGM_AC8_DC1 bit mask. */
    #define MC_CGM_0_AC8_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC8_DC1_DIV_MASK32               ((uint32)0x000F0000U)
    
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */


/***********************************************************/
/**********************    CGM_AC9    **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* CGM_AC9_SC[SELCTL] bits mask. */
    #define MC_CGM_AC9_SC_SELCTL_MASK32             ((uint32)0x0000003CU)
    #define MC_CGM_AC9_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC9_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC9_SS_SELSTAT_MASK32            ((uint32)0x03000000U)

    /* CGM_AC9_DC0 bit mask. */
    #define MC_CGM_AC9_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC9_DC0_DIV_MASK32               ((uint32)0x007F0000U)
#elif ( 0 ) /* (IPV_MC == IPV_MC_04_06_05_00) but it does not work */
    /* CGM_AC9_SC[SELCTL] bits mask. */
    #define MC_CGM_AC9_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC9_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC9_DC0 bit mask. */
    #define MC_CGM_AC9_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC9_DC0_DIV_MASK32               ((uint32)0x007F0000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
    /* CGM_AC9_SC[SELCTL] bits mask. */
    #define MC_CGM_AC9_SC_SELCTL_MASK32             ((uint32)0x0F000000U)
    #define MC_CGM_AC9_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC9_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC9_SS_SELSTAT_MASK32            ((uint32)0x0F000000U)

    /* CGM_AC9_DC0 bit mask. */
    #define MC_CGM_AC9_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC9_DC0_DIV_MASK32               ((uint32)0x003F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC9_SC[SELCTL] bits mask. */
    #define MC_CGM_AC9_SC_SELCTL_MASK32             ((uint32)0x07000000U)
    #define MC_CGM_AC9_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC9_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC9_SS_SELSTAT_MASK32            ((uint32)0x07000000U)

    /* CGM_AC9_DC0 bit mask. */
    #define MC_CGM_AC9_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_AC9_DC0_DIV_MASK32               ((uint32)0x000F0000U)

#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* CGM_AC9_SC[SELCTL] bits mask. */
    #define MC_CGM_AC9_SC_SELCTL_MASK32             ((uint32)0x01000000U)
    #define MC_CGM_AC9_SC_RESBITS_MASK32            ((uint32)0x00000000U)

    /* CGM_AC9_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC9_SS_SELSTAT_MASK32            ((uint32)0x01000000U)

#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC9_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC9_SC_SELCTL_MASK32             ((uint32)0x07000000U)

    /* CGM_AC9_DC0 bit mask. */
    #define MC_CGM_0_AC9_DC0_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC9_DC0_DIV_MASK32               ((uint32)0x00070000U)
    
    /* CGM_AC9_DC1 bit mask. */
    #define MC_CGM_0_AC9_DC1_DE_MASK32                ((uint32)0x80000000U)
    #define MC_CGM_0_AC9_DC1_DIV_MASK32               ((uint32)0x00070000U)
    
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */


/***********************************************************/
/**********************    CGM_AC10   **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_04_01_00) \
    )
    /* CGM_AC10_SC[SELCTL] bits mask. */
    #define MC_CGM_AC10_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    #define MC_CGM_AC10_SC_RESBITS_MASK32           ((uint32)0x00000000U)

    /* CGM_AC10_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC10_SS_SELSTAT_MASK32           ((uint32)0x07000000U)

    /* CGM_AC10_DC0 bit mask. */
    #define MC_CGM_AC10_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_AC10_DC0_DIV_MASK32              ((uint32)0x000F0000U)

#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
    /* CGM_AC10_SC[SELCTL] bits mask. */
    #define MC_CGM_AC10_SC_SELCTL_MASK32            ((uint32)0x0F000000U)
    #define MC_CGM_AC10_SC_RESBITS_MASK32           ((uint32)0x00000000U)

    /* CGM_AC10_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC10_SS_SELSTAT_MASK32           ((uint32)0x0F000000U)

    /* CGM_AC10_DC0 bit mask. */
    #define MC_CGM_AC10_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_AC10_DC0_DIV_MASK32              ((uint32)0x000F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC10_SC[SELCTL] bits mask. */
    #define MC_CGM_AC10_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    #define MC_CGM_AC10_SC_RESBITS_MASK32           ((uint32)0x00000000U)

    /* CGM_AC10_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC10_SS_SELSTAT_MASK32           ((uint32)0x07000000U)

    /* CGM_AC10_DC0 bit mask. */
    #define MC_CGM_AC10_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_AC10_DC0_DIV_MASK32              ((uint32)0x000F0000U)
    
#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC10_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC10_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    
    /* CGM_AC10_DC0 bit mask. */
    #define MC_CGM_0_AC10_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_0_AC10_DC0_DIV_MASK32              ((uint32)0x000F0000U)
    #define MC_CGM_0_AC10_DC0_DIV_FMT_MASK32          ((uint32)0x00000003U)
    
    /* CGM_AC10_DC1 bit mask. */
    #define MC_CGM_0_AC10_DC1_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_0_AC10_DC1_DIV_MASK32              ((uint32)0x000F0000U)
    
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */


/***********************************************************/
/**********************    CGM_AC11   **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_04_01_00) \
    )
    /* CGM_AC11_SC[SELCTL] bits mask. */
    #define MC_CGM_AC11_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    #define MC_CGM_AC11_SC_RESBITS_MASK32           ((uint32)0x00000000U)

    /* CGM_AC11_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC11_SS_SELSTAT_MASK32           ((uint32)0x07000000U)

    /* CGM_AC11_DC0 bit mask. */
    #define MC_CGM_AC11_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_AC11_DC0_DIV_MASK32              ((uint32)0x000F0000U)
    
#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC11_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC11_SC_SELCTL_MASK32            ((uint32)0x01000000U)
    
    /* CGM_AC11_DC0 bit mask. */
    #define MC_CGM_0_AC11_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_0_AC11_DC0_DIV_MASK32              ((uint32)0x00030000U)
    
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */


/***********************************************************/
/**********************    CGM_AC12   **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* CGM_AC12_SC[SELCTL] bits mask. */
    #define MC_CGM_AC12_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    #define MC_CGM_AC12_SC_RESBITS_MASK32           ((uint32)0x00000000U)

    /* CGM_AC12_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC12_SS_SELSTAT_MASK32           ((uint32)0x07000000U)

#elif (IPV_MC == IPV_MC_05_00_00_10)

    /* CGM_AC12_SC[SELCTL] bits mask. */
    #define MC_CGM_AC12_SC_SELCTL_MASK32            ((uint32)0x0F000000U)
    #define MC_CGM_AC12_SC_RESBITS_MASK32           ((uint32)0x00000000U)

    /* CGM_AC12_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC12_SS_SELSTAT_MASK32           ((uint32)0x0F000000U)

#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC12_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC12_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    
    /* CGM_AC12_DC0 bit mask. */
    #define MC_CGM_0_AC12_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_0_AC12_DC0_DIV_MASK32              ((uint32)0x00030000U)

#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

/* CGM_AC12_DC0 bit mask. */
#define MC_CGM_AC12_DC0_DE_MASK32               ((uint32)0x80000000U)

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_05_00_00_10))
    #define MC_CGM_AC12_DC0_DIV_MASK32              ((uint32)0x000F0000U)
#endif
#if (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_CGM_AC12_DC0_DIV_MASK32              ((uint32)0x007F0000U)
#endif


/***********************************************************/
/**********************    CGM_AC13   **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* CGM_AC13_SC[SELCTL] bits mask. */
    #define MC_CGM_AC13_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    #define MC_CGM_AC13_SC_RESBITS_MASK32           ((uint32)0x00000000U)

    /* CGM_AC13_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC13_SS_SELSTAT_MASK32           ((uint32)0x07000000U)


#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* CGM_AC13_SC[SELCTL] bits mask. */
    #define MC_CGM_AC13_SC_SELCTL_MASK32            ((uint32)0x0F000000U)
    #define MC_CGM_AC13_SC_RESBITS_MASK32           ((uint32)0x00000000U)

    /* CGM_AC13_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC13_SS_SELSTAT_MASK32           ((uint32)0x0F000000U)
    
#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC13_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC13_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    
    /* CGM_AC13_DC0 bit mask. */
    #define MC_CGM_0_AC13_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_0_AC13_DC0_DIV_MASK32              ((uint32)0x00030000U)
    
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

/* CGM_AC13_DC0 bit mask. */
#define MC_CGM_AC13_DC0_DE_MASK32               ((uint32)0x80000000U)

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_05_00_00_10))
    #define MC_CGM_AC13_DC0_DIV_MASK32              ((uint32)0x000F0000U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_CGM_AC13_DC0_DIV_MASK32              ((uint32)0x007F0000U)
#endif


/***********************************************************/
/**********************    CGM_AC14   **********************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))

    /* CGM_AC14_SC[SELCTL] bits mask. */
    #define MC_CGM_AC14_SC_SELCTL_MASK32            ((uint32)0x000003C0U)
    #define MC_CGM_AC14_SC_RESBITS_MASK32           ((uint32)0x00000000U)
    /* CGM_AC14_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC14_SS_SELSTAT_MASK32           ((uint32)0x03000000U)
    
#elif (IPV_MC == IPV_MC_05_00_00_10)

    #define MC_CGM_AC14_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    #define MC_CGM_AC14_SC_RESBITS_MASK32           ((uint32)0x00000000U)
    /* CGM_AC14_SS[SELSTAT] bit mask. */
    #define MC_CGM_AC14_SS_SELSTAT_MASK32           ((uint32)0x07000000U)
    
#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC14_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC14_SC_SELCTL_MASK32            ((uint32)0x07000000U)

    /* CGM_AC14_DC0 bit mask. */
    #define MC_CGM_0_AC14_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_0_AC14_DC0_DIV_MASK32              ((uint32)0x000F0000U)
    
#endif

/* CGM_AC14_DC0 bit mask. */
#define MC_CGM_AC14_DC0_DE_MASK32               ((uint32)0x80000000U)

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AC14_DC0_DIV_MASK32              ((uint32)0x007F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AC14_DC0_DIV_MASK32              ((uint32)0x000F0000U)
#endif

#if (IPV_MC == IPV_MC_04_06_05_00)
    #define MCB_CGM_SINK_SEL_MASK32                   ((uint32)0x00FFF000U)
#endif

/***********************************************************/
/**********************    CGM_AC15   **********************/
/***********************************************************/
#if (IPV_MC == IPV_MC_04_06_05_00)

    /* CGM_AC15_SC[SELCTL] bits mask. */
    #define MC_CGM_AC15_SC_SELCTL_MASK32            ((uint32)0x0F000000U)
    #define MC_CGM_AC15_SC_RESBITS_MASK32           ((uint32)0x00000000U)
    
#elif (IPV_MC == IPV_MC_05_00_00_10)

    /* CGM_AC15_SC[SELCTL] bits mask. */
    #define MC_CGM_AC15_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    #define MC_CGM_AC15_SC_RESBITS_MASK32           ((uint32)0x00000000U)
    
#elif (IPV_MC == IPV_MC_06_00_00_10)

    /* CGM_AC15_SC[SELCTL] bits mask. */
    #define MC_CGM_0_AC15_SC_SELCTL_MASK32            ((uint32)0x07000000U)
    
    /* CGM_AC15_DC0 bit mask. */
    #define MC_CGM_0_AC15_DC0_DE_MASK32               ((uint32)0x80000000U)
    #define MC_CGM_0_AC15_DC0_DIV_MASK32              ((uint32)0x000F0000U)
    
#endif

/* CGM_AC15_DC0 bit mask. */
#define MC_CGM_AC15_DC0_DE_MASK32               ((uint32)0x80000000U)

#if (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_CGM_AC15_DC0_DIV_MASK32              ((uint32)0x007F0000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AC15_DC0_DIV_MASK32              ((uint32)0x000F0000U)
#endif

/* CGM_AC15_DC1 bit mask. */
#define MC_CGM_AC15_DC1_DE_MASK32               ((uint32)0x80000000U)
#define MC_CGM_AC15_DC1_DIV_MASK32              ((uint32)0x000F0000U)

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define SRC_GPR1_VIDEO_PLL_SOURCE_SELECT_MASK32         ((uint32)0x80000000U)
    #define SRC_GPR1_PERIPH_PLL_SOURCE_SELECT_MASK32        ((uint32)0x40000000U)
    #define SRC_GPR1_DDR_PLL_SOURCE_SELECT_MASK32           ((uint32)0x20000000U)
    #define SRC_GPR1_ENET_PLL_SOURCE_SELECT_MASK32          ((uint32)0x10000000U)
    #define SRC_GPR1_ARM_PLL_SOURCE_SELECT_MASK32           ((uint32)0x08000000U)
#endif

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

#endif /* REG_ESYS_MC_CGM_H */

/** @} */
