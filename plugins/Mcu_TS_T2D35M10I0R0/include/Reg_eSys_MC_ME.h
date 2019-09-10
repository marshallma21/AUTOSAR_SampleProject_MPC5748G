/**
*   @file    Reg_eSys_MC_ME.h
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


#ifndef REG_ESYS_MC_ME_H
#define REG_ESYS_MC_ME_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_MC_ME_H_REF_1
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

#define REG_ESYS_MC_ME_VENDOR_ID                        43
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_ME_AR_RELEASE_MAJOR_VERSION         4
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_ME_AR_RELEASE_MINOR_VERSION         2
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_ME_AR_RELEASE_REVISION_VERSION      2
#define REG_ESYS_MC_ME_SW_MAJOR_VERSION                 1
#define REG_ESYS_MC_ME_SW_MINOR_VERSION                 0
#define REG_ESYS_MC_ME_SW_PATCH_VERSION                 0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_MC_ME_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_MC_ME_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_MC_ME.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_MC_IPVersion header file are from the same vendor */
#if (REG_ESYS_MC_ME_VENDOR_ID != MCU_MC_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_MC_ME.h and Mcu_MC_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_MC_ME_AR_RELEASE_MAJOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_MC_ME_AR_RELEASE_MINOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_MC_ME_AR_RELEASE_REVISION_VERSION != MCU_MC_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_MC_ME.h and Mcu_MC_IPVersion.h are different"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Software version */
#if ((REG_ESYS_MC_ME_SW_MAJOR_VERSION != MCU_MC_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_MC_ME_SW_MINOR_VERSION != MCU_MC_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_MC_ME_SW_PATCH_VERSION != MCU_MC_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_MC_ME.h and Mcu_MC_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* ME: Global Status Register Address. */
#define MC_ME_GS_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0000U))
/* ME: Mode Control Register Address. */
#define MC_ME_MCTL_ADDR32                  ((uint32)(MC_ME_BASEADDR + (uint32)0x0004U))
/* ME: Mode Enable Register Address. */
#define MC_ME_ME_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0008U))
/* ME: Interrupt Status Register Address. */
#define MC_ME_IS_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x000CU))
/* ME: Interrupt Mask Register Address. */
#define MC_ME_IM_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0010U))
/* ME: Invalid Mode Transition Status Register Address. */
#define MC_ME_IMTS_ADDR32                   ((uint32)(MC_ME_BASEADDR + (uint32)0x0014U))
/* ME: Debug Mode Transition Status Register Address. */
#define MC_ME_DMTS_ADDR32                   ((uint32)(MC_ME_BASEADDR + (uint32)0x0018U))

/* ME: RESET Mode Configuration Register Address. */
#define MC_ME_RESET_MC_ADDR32               ((uint32)(MC_ME_BASEADDR + (uint32)0x0020U))
/* ME: TEST Mode Configuration Register Address. */
#define MC_ME_TEST_MC_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0024U))
/* ME: SAFE Mode Configuration Register Address. */
#define MC_ME_SAFE_MC_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0028U))
/* ME: DRUN Mode Configuration Register Address. */
#define MC_ME_DRUN_MC_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x002CU))
/* ME: RUN0 Mode Configuration Registers Address. */
#define MC_ME_RUN0_MC_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0030U))
/* ME: RUN1 Mode Configuration Registers Address. */
#define MC_ME_RUN1_MC_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0034U))
/* ME: RUN2 Mode Configuration Registers Address. */
#define MC_ME_RUN2_MC_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0038U))
/* ME: RUN3 Mode Configuration Registers Address. */
#define MC_ME_RUN3_MC_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x003CU))
/* ME: HALT0 Mode Configuration Register Address. */
#define MC_ME_HALT0_MC_ADDR32               ((uint32)(MC_ME_BASEADDR + (uint32)0x0040U))
/* ME: STOP0 Mode Configuration Register Address. */
#define MC_ME_STOP0_MC_ADDR32               ((uint32)(MC_ME_BASEADDR + (uint32)0x0048U))

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
/* ME: STANDBY0 Mode Configuration Register Address. */
#define MC_ME_STBY0_MC_ADDR32               ((uint32)(MC_ME_BASEADDR + (uint32)0x0054U))
#endif

/* ME: Peripheral Status Register 0 Address. */
#define MC_ME_PS0_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0060U))
/* ME: Peripheral Status Register 1 Address. */
#define MC_ME_PS1_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0064U))
/* ME: Peripheral Status Register 2 Address. */
#define MC_ME_PS2_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0068U))
/* ME: Peripheral Status Register 3 Address. */
#define MC_ME_PS3_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x006CU))
/* ME: Peripheral Status Register 4 Address. */
#define MC_ME_PS4_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0070U))
/* ME: Peripheral Status Register 5 Address. */
#define MC_ME_PS5_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0074U))
/* ME: Peripheral Status Register 6 Address. */
#define MC_ME_PS6_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0078U))
/* ME: Peripheral Status Register 7 Address. */
#define MC_ME_PS7_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x007CU))

/* ME: Run Peripheral Configuration 0 Register Address. */
#define MC_ME_RUN_PC0_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0080U))
/* ME: Run Peripheral Configuration 1 Register Address. */
#define MC_ME_RUN_PC1_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0084U))
/* ME: Run Peripheral Configuration 2 Register Address. */
#define MC_ME_RUN_PC2_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0088U))
/* ME: Run Peripheral Configuration 3 Register Address. */
#define MC_ME_RUN_PC3_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x008CU))
/* ME: Run Peripheral Configuration 4 Register Address. */
#define MC_ME_RUN_PC4_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0090U))
/* ME: Run Peripheral Configuration 5 Register Address. */
#define MC_ME_RUN_PC5_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0094U))
/* ME: Run Peripheral Configuration 6 Register Address. */
#define MC_ME_RUN_PC6_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x0098U))
/* ME: Run Peripheral Configuration 7 Register Address. */
#define MC_ME_RUN_PC7_ADDR32                ((uint32)(MC_ME_BASEADDR + (uint32)0x009CU))

/* ME: Low-Power Peripheral Configuration 0 Register Address. */
#define MC_ME_LP_PC0_ADDR32                 ((uint32)(MC_ME_BASEADDR + (uint32)0x00A0U))
/* ME: Low-Power Peripheral Configuration 1 Register Address. */
#define MC_ME_LP_PC1_ADDR32                 ((uint32)(MC_ME_BASEADDR + (uint32)0x00A4U))
/* ME: Low-Power Peripheral Configuration 2 Register Address. */
#define MC_ME_LP_PC2_ADDR32                 ((uint32)(MC_ME_BASEADDR + (uint32)0x00A8U))
/* ME: Low-Power Peripheral Configuration 3 Register Address. */
#define MC_ME_LP_PC3_ADDR32                 ((uint32)(MC_ME_BASEADDR + (uint32)0x00ACU))
/* ME: Low-Power Peripheral Configuration 4 Register Address. */
#define MC_ME_LP_PC4_ADDR32                 ((uint32)(MC_ME_BASEADDR + (uint32)0x00B0U))
/* ME: Low-Power Peripheral Configuration 5 Register Address. */
#define MC_ME_LP_PC5_ADDR32                 ((uint32)(MC_ME_BASEADDR + (uint32)0x00B4U))
/* ME: Low-Power Peripheral Configuration 6 Register Address. */
#define MC_ME_LP_PC6_ADDR32                 ((uint32)(MC_ME_BASEADDR + (uint32)0x00B8U))
/* ME: Low-Power Peripheral Configuration 7 Register Address. */
#define MC_ME_LP_PC7_ADDR32                 ((uint32)(MC_ME_BASEADDR + (uint32)0x00BCU))

#if (IPV_MC == IPV_MC_05_00_00_10)
    /* MCV5 */
    #define MC_ME_PCTL3_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C0U))
    #define MC_ME_PCTL2_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C1U))
    #define MC_ME_PCTL1_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C2U))

    #define MC_ME_PCTL7_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C4U))
    #define MC_ME_PCTL6_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C5U))
    #define MC_ME_PCTL5_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C6U))
    #define MC_ME_PCTL4_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C7U))

    #define MC_ME_PCTL11_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00C8U))
    #define MC_ME_PCTL10_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00C9U))
    #define MC_ME_PCTL9_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00CAU))

    #define MC_ME_PCTL15_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00CCU))
    #define MC_ME_PCTL14_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00CDU))
    #define MC_ME_PCTL13_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00CEU))
    #define MC_ME_PCTL12_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00CFU))

    #define MC_ME_PCTL19_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D0U))
    #define MC_ME_PCTL18_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D1U))
    #define MC_ME_PCTL17_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D2U))
    #define MC_ME_PCTL16_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D3U))

    #define MC_ME_PCTL23_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D4U))
    #define MC_ME_PCTL22_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D5U))
    #define MC_ME_PCTL21_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D6U))
    #define MC_ME_PCTL20_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D7U))

    #define MC_ME_PCTL27_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D8U))
    #define MC_ME_PCTL26_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D9U))
    #define MC_ME_PCTL25_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DAU))
    #define MC_ME_PCTL24_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DBU))

    #define MC_ME_PCTL30_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DDU))
    #define MC_ME_PCTL29_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DEU))
    #define MC_ME_PCTL28_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DFU))

    #define MC_ME_PCTL35_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E0U))
    #define MC_ME_PCTL34_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E1U))

    #define MC_ME_PCTL36_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E7U))

    #define MC_ME_PCTL60_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00FFU))

    #define MC_ME_PCTL84_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0117U))

    #define MC_ME_PCTL88_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x011BU))

    #define MC_ME_PCTL129_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0142U))
    #define MC_ME_PCTL128_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0143U))

    #define MC_ME_PCTL132_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0147U))

    #define MC_ME_PCTL136_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x014BU))

    #define MC_ME_PCTL152_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x015BU))

    #define MC_ME_PCTL168_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x016BU))

    #define MC_ME_PCTL172_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x016FU))

    #define MC_ME_PCTL176_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0173U))

    #define MC_ME_PCTL180_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0177U))

    #define MC_ME_PCTL184_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017BU))

    #define MC_ME_PCTL188_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017FU))

    #define MC_ME_PCTL193_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0182U))
    
    #define MC_ME_PCTL192_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0183U))

    #define MC_ME_PCTL196_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0187U))

    #define MC_ME_PCTL200_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018BU))

    #define MC_ME_PCTL204_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018FU))
    
#elif (IPV_MC == IPV_MC_06_00_00_10)

    #define MC_ME_PCTL39_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E4U))
    #define MC_ME_PCTL40_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00EBU))
    
    #define MC_ME_PCTL48_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F3U))
    #define MC_ME_PCTL49_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F2U))
    #define MC_ME_PCTL50_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F1U))
    
    #define MC_ME_PCTL52_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F7U))
    #define MC_ME_PCTL54_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F5U))
    
    #define MC_ME_PCTL58_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F9U))
    #define MC_ME_PCTL77_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x010EU))
    #define MC_ME_PCTL79_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x010CU))

    #define MC_ME_PCTL81_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0112U))
    #define MC_ME_PCTL83_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0110U))
    #define MC_ME_PCTL85_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0116U))
    #define MC_ME_PCTL87_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0114U))
    
    #define MC_ME_PCTL89_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x011AU))
    #define MC_ME_PCTL91_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0118U))
    #define MC_ME_PCTL93_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x011EU))

    #define MC_ME_PCTL100_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0127U))
    #define MC_ME_PCTL104_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x012BU))
    
    #define MC_ME_PCTL116_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0137U))
    #define MC_ME_PCTL120_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x013BU))
    #define MC_ME_PCTL160_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0163U))
    #define MC_ME_PCTL161_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0162U))
    #define MC_ME_PCTL162_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0161U))
    #define MC_ME_PCTL166_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0165U))
    #define MC_ME_PCTL170_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0169U))
    #define MC_ME_PCTL182_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0175U))
    
    #define MC_ME_PCTL184_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017BU))
    #define MC_ME_PCTL186_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0179U))
    #define MC_ME_PCTL188_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017FU))
    
    #define MC_ME_PCTL190_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017DU))
    #define MC_ME_PCTL192_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0183U))
    #define MC_ME_PCTL194_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0181U))
    
    #define MC_ME_PCTL204_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018FU))
    #define MC_ME_PCTL206_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018DU))
    #define MC_ME_PCTL208_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0193U))
    
    #define MC_ME_PCTL212_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0197U))
    #define MC_ME_PCTL216_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x019BU))
    #define MC_ME_PCTL220_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x019FU))
    #define MC_ME_PCTL236_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01AFU))

#else
    /* MCV4 */
    #define MC_ME_PCTL0_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C0U))
    #define MC_ME_PCTL1_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C1U))
    #define MC_ME_PCTL2_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C2U))
    #define MC_ME_PCTL3_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C3U))
    #define MC_ME_PCTL4_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C4U))
    #define MC_ME_PCTL5_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C5U))
    #define MC_ME_PCTL6_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C6U))
    #define MC_ME_PCTL7_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C7U))
    /* LFAST_0 Peripheral Control Register */
    #define MC_ME_PCTL9_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00C9U))
    #define MC_ME_PCTL10_ADDR32                      ((uint32)(MC_ME_BASEADDR + (uint32)0x00CAU))

    #define MC_ME_PCTL11_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00CBU))
    #define MC_ME_PCTL12_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00CCU))
    #define MC_ME_PCTL15_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00CFU))
    #define MC_ME_PCTL20_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D4U))
    #define MC_ME_PCTL21_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D5U))
    #define MC_ME_PCTL22_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D6U))
    #define MC_ME_PCTL23_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D7U))
    #define MC_ME_PCTL24_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D8U))
    #define MC_ME_PCTL25_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00D9U))

    #define MC_ME_PCTL28_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DCU))
    #define MC_ME_PCTL29_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DDU))

    #define MC_ME_PCTL30_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DEU))
    #define MC_ME_PCTL31_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00DFU))
    #define MC_ME_PCTL32_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E0U))
    #define MC_ME_PCTL33_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E1U))
    /* ATX Peripheral Control Register (MC_ME_PCTL34) */
    #define MC_ME_PCTL34_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E2U))
    /* DMAMUX_0 Peripheral Control Register (MC_ME_PCTL36) */
    #define MC_ME_PCTL36_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E4U))
    /* CRC_0 Peripheral Control Register (MC_ME_PCTL38) */
    #define MC_ME_PCTL38_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E6U))
    
    #define MC_ME_PCTL40_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E8U))
    #define MC_ME_PCTL41_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00E9U))
    #define MC_ME_PCTL42_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00EAU))
    #define MC_ME_PCTL43_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00EBU))

    #define MC_ME_PCTL45_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00EDU))
    #define MC_ME_PCTL49_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F1U))

    #define MC_ME_PCTL50_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F2U))
    #define MC_ME_PCTL51_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F3U))
    #define MC_ME_PCTL52_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F4U))
    #define MC_ME_PCTL53_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F5U))
    #define MC_ME_PCTL54_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F6U))

    #define MC_ME_PCTL55_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F7U))
    #define MC_ME_PCTL56_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F8U))
    #define MC_ME_PCTL57_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00F9U))
    #define MC_ME_PCTL58_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00FAU))
    #define MC_ME_PCTL59_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00FBU))
    #define MC_ME_PCTL60_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00FCU))

    #define MC_ME_PCTL61_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00FDU))
    #define MC_ME_PCTL62_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00FEU))
    #define MC_ME_PCTL63_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x00FFU))
    #define MC_ME_PCTL64_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0100U))
    #define MC_ME_PCTL65_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0101U))
    #define MC_ME_PCTL66_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0102U))

    #define MC_ME_PCTL67_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0103U))
    #define MC_ME_PCTL68_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0104U))
    #define MC_ME_PCTL69_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0105U))
    #define MC_ME_PCTL70_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0106U))
    #define MC_ME_PCTL71_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0107U))
    #define MC_ME_PCTL72_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0108U))
    #define MC_ME_PCTL73_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0109U))
    #define MC_ME_PCTL74_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x010AU))
    #define MC_ME_PCTL75_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x010BU))
    #define MC_ME_PCTL76_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x010CU))

    #define MC_ME_PCTL77_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x010DU))
    /* CAN_1 Peripheral Control Register (MC_ME_PCTL78) */
    #define MC_ME_PCTL78_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x010EU))
    /* CAN_0 Peripheral Control Register (MC_ME_PCTL79) */
    #define MC_ME_PCTL79_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x010FU))
    #define MC_ME_PCTL81_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0111U))
    #define MC_ME_PCTL82_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0112U))
    #define MC_ME_PCTL83_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0113U))
    #define MC_ME_PCTL84_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0114U))
    #define MC_ME_PCTL85_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0115U))
    
    #define MC_ME_PCTL87_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0117U))
    
    #define MC_ME_PCTL89_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0119U))    
    #define MC_ME_PCTL90_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x011AU))

    #define MC_ME_PCTL91_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x011BU))
    #define MC_ME_PCTL92_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x011CU))
    #define MC_ME_PCTL93_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x011DU))
    #define MC_ME_PCTL96_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0120U))
    #define MC_ME_PCTL97_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0121U))

    #define MC_ME_PCTL98_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0122U))

    #define MC_ME_PCTL99_ADDR32                     ((uint32)(MC_ME_BASEADDR + (uint32)0x0123U))
    #define MC_ME_PCTL100_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0124U))
    #define MC_ME_PCTL101_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0125U))
    #define MC_ME_PCTL102_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0126U))
    /* SENT_0 Peripheral Control Register (MC_ME_PCTL104) */
    #define MC_ME_PCTL104_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0128U))
    #define MC_ME_PCTL105_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0129U))
    /* FLEXRAY Peripheral Control Register (MC_ME_PCTL107) */
    #define MC_ME_PCTL107_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x012BU))
    #define MC_ME_PCTL111_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x012FU))
    #define MC_ME_PCTL112_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0130U))
    
    #define MC_ME_PCTL116_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0134U))
    #define MC_ME_PCTL120_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0138U))
    
    #define MC_ME_PCTL123_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x013BU))
    /* ADC_3 Peripheral Control Register (MC_ME_PCTL124) */
    #define MC_ME_PCTL124_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x013CU))
    /* ADC_1 Peripheral Control Register (MC_ME_PCTL126) */
    #define MC_ME_PCTL126_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x013EU))
    #define MC_ME_PCTL127_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x013FU))
    #define MC_ME_PCTL128_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0140U))
    /* ETIMER_1 Peripheral Control Register (MC_ME_PCTL137) */
    #define MC_ME_PCTL137_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0149U))
    /* CTU_1 Peripheral Control Register (MC_ME_PCTL141) */
    #define MC_ME_PCTL141_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x014DU))
    #define MC_ME_PCTL143_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x014FU))
    /* PWM_1 Peripheral Control Register (MC_ME_PCTL144) */
    #define MC_ME_PCTL144_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0150U))
    /* DMAMUX_1 Peripheral Control Register (MC_ME_PCTL146) */
    #define MC_ME_PCTL146_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0152U))
    #define MC_ME_PCTL148_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0154U))
    #define MC_ME_PCTL149_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0155U))
    
    #define MC_ME_PCTL152_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0158U))
    #define MC_ME_PCTL154_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x015AU))
    #define MC_ME_PCTL158_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x015EU))
    
    #define MC_ME_PCTL161_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0161U))
    #define MC_ME_PCTL162_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0162U))
    #define MC_ME_PCTL166_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0166U))
    
    #define MC_ME_PCTL170_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x016AU))
    #define MC_ME_PCTL177_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0171U))
    #define MC_ME_PCTL179_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0173U))
    #define MC_ME_PCTL180_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0174U))
    #define MC_ME_PCTL181_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0175U))
    #define MC_ME_PCTL182_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0176U))
    #define MC_ME_PCTL183_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0177U))
    #define MC_ME_PCTL184_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0178U))
    #define MC_ME_PCTL185_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0179U))
    #define MC_ME_PCTL186_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017AU))
    #define MC_ME_PCTL187_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017BU))
    #define MC_ME_PCTL188_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017CU))
    #define MC_ME_PCTL189_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017DU))
    #define MC_ME_PCTL190_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017EU))
    #define MC_ME_PCTL191_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x017FU))
    #define MC_ME_PCTL192_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0180U))
    #define MC_ME_PCTL193_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0181U))
    #define MC_ME_PCTL194_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0182U))
    
    #define MC_ME_PCTL196_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0184U))
    #define MC_ME_PCTL197_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0185U))
    #define MC_ME_PCTL198_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0186U))
    
    #define MC_ME_PCTL200_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0188U))
    
    #define MC_ME_PCTL202_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018AU))
    #define MC_ME_PCTL203_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018BU))
    /* LINFlex_0 Peripheral Control Register (MC_ME_PCTL204) */
    #define MC_ME_PCTL204_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018CU))
    #define MC_ME_PCTL205_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018DU))
    #define MC_ME_PCTL206_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018EU))
    #define MC_ME_PCTL207_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x018FU))
    /* DSPI_3 Peripheral Control Register (MC_ME_PCTL208) */
    #define MC_ME_PCTL208_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0190U))
    /* DSPI_2 Peripheral Control Register (MC_ME_PCTL209) */
    #define MC_ME_PCTL209_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0191U))
    #define MC_ME_PCTL210_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0192U))
    #define MC_ME_PCTL213_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0195U))
    /* SENT_1 Peripheral Control Register (MC_ME_PCTL214) */
    #define MC_ME_PCTL214_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0196U))
    
    #define MC_ME_PCTL216_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x0198U))
    
    #define MC_ME_PCTL219_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x019BU))
    #define MC_ME_PCTL220_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x019CU))
    #define MC_ME_PCTL225_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01A1U))
    #define MC_ME_PCTL226_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01A2U))
    #define MC_ME_PCTL227_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01A3U))
    #define MC_ME_PCTL229_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01A5U))
    #define MC_ME_PCTL230_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01A6U))
    #define MC_ME_PCTL232_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01A8U))
    /* ADC_2 Peripheral Control Register (MC_ME_PCTL235) */
    #define MC_ME_PCTL235_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01ABU))
    /* ADC_0 Peripheral Control Register (MC_ME_PCTL237) */
    #define MC_ME_PCTL237_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01ADU))
    #define MC_ME_PCTL238_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01AEU))
    /* SWG_0 Peripheral Control Register (MC_ME_PCTL239) */
    #define MC_ME_PCTL239_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01AFU))
    /* ETIMER_2 Peripheral Control Register (MC_ME_PCTL245) */
    #define MC_ME_PCTL245_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01B5U))
    #define MC_ME_PCTL246_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01B6U))
    /* ETIMER_0 Peripheral Control Register (MC_ME_PCTL247) */
    #define MC_ME_PCTL247_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01B7U))
    #define MC_ME_PCTL248_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01B8U))
    #define MC_ME_PCTL249_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01B9U))
    #define MC_ME_PCTL250_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01BAU))
    /* CTU_0 Peripheral Control Register (MC_ME_PCTL251) */
    #define MC_ME_PCTL251_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01BBU))
    #define MC_ME_PCTL252_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01BCU))
    #define MC_ME_PCTL253_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01BDU))
    #define MC_ME_PCTL254_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01BEU))
    /* PWM_0 Peripheral Control Register (MC_ME_PCTL255) */
    #define MC_ME_PCTL255_ADDR32                    ((uint32)(MC_ME_BASEADDR + (uint32)0x01BFU))
#endif

/************************************/
/* Core Control Register (ME_CCTLn) */
/************************************/

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_CCTL0_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01C6U))
    #define MC_ME_CCTL1_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01C4U))
#else
    #define MC_ME_CCTL0_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01C4U))
    #define MC_ME_CCTL1_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01C6U))
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_CCTL2_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01CAU))
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_CCTL2_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01CAU))
#else
    #define MC_ME_CCTL2_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01C8U))
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_CCTL3_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01C8U))
    #define MC_ME_CCTL4_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01CEU))
#else
    #define MC_ME_CCTL3_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01CAU))
    #define MC_ME_CCTL4_ADDR32                          ((uint32)(MC_ME_BASEADDR + (uint32)0x01CCU))
#endif

/**************************************/
/* Core Address Register (ME_CADDRn)  */
/**************************************/
#define MC_ME_CADDR0_ADDR32                         ((uint32)(MC_ME_BASEADDR + (uint32)0x01E0U))
#define MC_ME_CADDR1_ADDR32                         ((uint32)(MC_ME_BASEADDR + (uint32)0x01E4U))
#define MC_ME_CADDR2_ADDR32                         ((uint32)(MC_ME_BASEADDR + (uint32)0x01E8U))
#define MC_ME_CADDR3_ADDR32                         ((uint32)(MC_ME_BASEADDR + (uint32)0x01ECU))
#define MC_ME_CADDR4_ADDR32                         ((uint32)(MC_ME_BASEADDR + (uint32)0x01F0U))

#define MC_ME_TEST_SEC_CC_I_ADDR32                  ((uint32)(MC_ME_BASEADDR + (uint32)0x00000240U))
#define MC_ME_DRUN_SEC_CC_I_ADDR32                  ((uint32)(MC_ME_BASEADDR + (uint32)0x00000260U))
#define MC_ME_RUN0_SEC_CC_I_ADDR32                  ((uint32)(MC_ME_BASEADDR + (uint32)0x00000270U))
#define MC_ME_RUN1_SEC_CC_I_ADDR32                  ((uint32)(MC_ME_BASEADDR + (uint32)0x00000280U))
#define MC_ME_RUN2_SEC_CC_I_ADDR32                  ((uint32)(MC_ME_BASEADDR + (uint32)0x00000290U))
#define MC_ME_RUN3_SEC_CC_I_ADDR32                  ((uint32)(MC_ME_BASEADDR + (uint32)0x000002A0U))

/*************************************/
/*  GPR SLEEP Register (GPR_SLEEP)   */
/*************************************/
#if ((IPV_MC == IPV_MC_05_00_00_07))

#ifdef MCU_ERR009139_IPV_MC_05000007
#if (MCU_ERR009139_IPV_MC_05000007 == STD_ON)
/* ME:  GPR SLEEP Register Address. */
#define MC_ME_GPR_SLEEP_ADDR32              ((uint32)0xFFF94014U)
#endif  /* MCU_ERR009139_IPV_MC_05000007 */
#endif  /* (MCU_ERR009139_IPV_MC_05000007 == STD_ON) */

#endif

/*************************************/
/* Global Status Register (MC_ME_GS) */
/*************************************/
/* bit masks */
#define MC_ME_GS_S_CURRENT_MODE_MASK32              ((uint32)0xF0000000U)
#define MC_ME_GS_S_MTRANS_MASK32                    ((uint32)0x08000000U)
#define MC_ME_GS_S_SYSCLK_MASK32                    ((uint32)0x0000000FU)
#define MC_ME_GS_S_PDO_MASK32                       ((uint32)0x00800000U)
#define MC_ME_GS_S_MVR_MASK32                       ((uint32)0x00100000U)
#define MC_ME_GS_S_FLA_MASK32                       ((uint32)0x00030000U)
/* clock sources status */
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_GS_S_SDPLL_MASK32                 ((uint32)0x00000100U)
#endif /* IPV_MC_04_03_00_00 */

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_GS_S_PLL1_MASK32                  ((uint32)0x00000080U)
    #define MC_ME_GS_S_PLL0_MASK32                  ((uint32)0x00000040U)
    #define MC_ME_GS_S_XOSC_MASK32                  ((uint32)0x00000020U)
    #define MC_ME_GS_S_IRCOSC_MASK32                ((uint32)0x00000010U)
#endif /* ((IPV_MC == IPV_MC_04_04_01_00)  ... */

#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_GS_S_PLL3_MASK32                  ((uint32)0x00000800U)
    #define MC_ME_GS_S_PLL2_MASK32                  ((uint32)0x00000400U)
    #define MC_ME_GS_S_PLL1_MASK32                  ((uint32)0x00000200U)
    #define MC_ME_GS_S_PLL0_MASK32                  ((uint32)0x00000100U)
    #define MC_ME_GS_S_SXOSC_MASK32                 ((uint32)0x00000080U)
    #define MC_ME_GS_S_SIRC_MASK32                  ((uint32)0x00000040U)
    #define MC_ME_GS_S_FXOSC_MASK32                 ((uint32)0x00000020U)
    #define MC_ME_GS_S_FIRC_MASK32                  ((uint32)0x00000010U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_GS_S_SXOSC_MASK32                 ((uint32)0x00000100U)
    #define MC_ME_GS_S_SIRC_MASK32                  ((uint32)0x00000080U)
    #define MC_ME_GS_S_PLL0_MASK32                  ((uint32)0x00000040U)
    #define MC_ME_GS_S_FXOSC_MASK32                 ((uint32)0x00000020U)
    #define MC_ME_GS_S_FIRC_MASK32                  ((uint32)0x00000010U)
#endif /* (IPV_MC == IPV_MC_05_00_00_07) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_GS_S_VIDEOPLL_MASK32                  ((uint32)0x00000400U)
    #define MC_ME_GS_S_DDRPLLDFS123_MASK32              ((uint32)0x00000200U)
    /** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_ME_GS_S_ENETPLLDFS1234_MASK32            ((uint32)0x00000100U)
    #define MC_ME_GS_S_PERIPHPLL_MASK32                 ((uint32)0x00000080U)
    #define MC_ME_GS_S_ARMPLLDFS123_MASK32              ((uint32)0x00000040U)
    #define MC_ME_GS_S_XOSC_MASK32                      ((uint32)0x00000020U)
    #define MC_ME_GS_S_FIRC_MASK32                      ((uint32)0x00000010U)
#endif

/* working values for sys clock */
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_GS_S_SYSCLK_SDPLL_U32             ((uint32)0x00000003U)
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_GS_S_SYSCLK_PLL1_U32              ((uint32)0x00000004U)
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_GS_S_SYSCLK_PLL0_U32              ((uint32)0x00000002U)
    #define MC_ME_GS_S_SYSCLK_XOSC_U32              ((uint32)0x00000001U)
    #define MC_ME_GS_S_SYSCLK_IRCOSC_U32            ((uint32)0x00000000U)
#endif /* IPV_MC == IPV_MC_04_03_00_00 */
#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_GS_S_SYSCLK_DISABLED              ((uint32)0x0000000FU)
    #define MC_ME_GS_S_SYSCLK_PLL1                  ((uint32)0x00000005U)
    #define MC_ME_GS_S_SYSCLK_PLL0                  ((uint32)0x00000004U)
    #define MC_ME_GS_S_SYSCLK_FXOSC                 ((uint32)0x00000001U)
    #define MC_ME_GS_S_SYSCLK_FIRC                  ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_GS_S_SYSCLK_DISABLED              ((uint32)0x0000000FU)
    #define MC_ME_GS_S_SYSCLK_PLL0                  ((uint32)0x00000002U)
    #define MC_ME_GS_S_SYSCLK_FXOSC                 ((uint32)0x00000001U)
    #define MC_ME_GS_S_SYSCLK_FIRC                  ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_07) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_GS_S_SYSCLK_DISABLED                  ((uint32)0x0000000FU)
    /** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_ME_GS_S_SYSCLK_ARM_PLL_DFS_1_U32         ((uint32)0x00000002U)
    #define MC_ME_GS_S_SYSCLK_XOSC_U32                  ((uint32)0x00000001U)
    #define MC_ME_GS_S_SYSCLK_FIRC_U32                  ((uint32)0x00000000U)
#endif
/****************************************/
/* Power control for each run mode, common masks ((MC_ME_n_MC) */
/****************************************/
/* masks */
#define MC_ME_MODE_MC_PWRLVL_MASK32                 ((uint32)0x70000000U)
#define MC_ME_MODE_MC_PWRLVL_SHIFT32                ((uint32)28U)
#define MC_ME_MODE_MC_PDO_MASK32                    ((uint32)0x00800000U)
#define MC_ME_MODE_MC_MVRON_MASK32                  ((uint32)0x00100000U)
#define MC_ME_MODE_MC_FLAON_MASK32                  ((uint32)0x00030000U)

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_MODE_MC_SDPLLON_MASK32            ((uint32)0x00000100U)
#endif /* IPV_MC_04_03_00_00 */

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_MODE_MC_PLL1ON_MASK32             ((uint32)0x00000080U)
    #define MC_ME_MODE_MC_PLL0ON_MASK32             ((uint32)0x00000040U)
    #define MC_ME_MODE_MC_XOSCON_MASK32             ((uint32)0x00000020U)
    #define MC_ME_MODE_MC_IRCOSCON_MASK32           ((uint32)0x00000010U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_MODE_MC_PLL3ON_MASK32             ((uint32)0x00000800U)
    #define MC_ME_MODE_MC_PLL2ON_MASK32             ((uint32)0x00000400U)
    #define MC_ME_MODE_MC_PLL1ON_MASK32             ((uint32)0x00000200U)
    #define MC_ME_MODE_MC_PLL0ON_MASK32             ((uint32)0x00000100U)
    #define MC_ME_MODE_MC_SXOSCON_MASK32            ((uint32)0x00000080U)
    #define MC_ME_MODE_MC_SIRCON_MASK32             ((uint32)0x00000040U)
    #define MC_ME_MODE_MC_FXOSCON_MASK32            ((uint32)0x00000020U)
    #define MC_ME_MODE_MC_FIRCON_MASK32             ((uint32)0x00000010U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_MODE_MC_SXOSCON_MASK32            ((uint32)0x00000100U)
    #define MC_ME_MODE_MC_SIRCON_MASK32             ((uint32)0x00000080U)
    #define MC_ME_MODE_MC_PLL0ON_MASK32             ((uint32)0x00000040U)
    #define MC_ME_MODE_MC_FXOSCON_MASK32            ((uint32)0x00000020U)
    #define MC_ME_MODE_MC_FIRCON_MASK32             ((uint32)0x00000010U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_MODE_MC_VIDEOPLLON_MASK32         ((uint32)0x00000400U)
    /** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_ME_MODE_MC_DDRPLLDFS123ON_MASK32     ((uint32)0x00000200U)
    /** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_ME_MODE_MC_ENETPLLDFS1234ON_MASK32   ((uint32)0x00000100U)
    /** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_ME_MODE_MC_PERIPHPLLON_MASK32        ((uint32)0x00000080U)
    /** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_ME_MODE_MC_ARMPLLDFS123ON_MASK32     ((uint32)0x00000040U)
    #define MC_ME_MODE_MC_XOSCON_MASK32             ((uint32)0x00000020U)
    #define MC_ME_MODE_MC_FIRCON_MASK32             ((uint32)0x00000010U)
#endif /* (IPV_MC == IPV_MC_05_00_00_07) */

#define MC_ME_MODE_MC_SYSCLK_MASK32                 ((uint32)0x0000000FU)

/* working values */
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_MODE_MC_SYSCLK_SDPLL_U32          ((uint32)0x00000003U)
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_MODE_MC_SYSCLK_PLL1_U32           ((uint32)0x00000004U)
    #define MC_ME_MODE_MC_SYSCLK_PLL0_U32           ((uint32)0x00000002U)
    #define MC_ME_MODE_MC_SYSCLK_XOSC_U32           ((uint32)0x00000001U)
    #define MC_ME_MODE_MC_SYSCLK_IRCOSC_U32         ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_MODE_MC_SYSCLK_PLL1_U32           ((uint32)0x00000005U)
    #define MC_ME_MODE_MC_SYSCLK_PLL0_U32           ((uint32)0x00000004U)
    #define MC_ME_MODE_MC_SYSCLK_FXOSC_U32          ((uint32)0x00000001U)
    #define MC_ME_MODE_MC_SYSCLK_FIRC_U32           ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_MODE_MC_SYSCLK_PLL0_U32           ((uint32)0x00000002U)
    #define MC_ME_MODE_MC_SYSCLK_FXOSC_U32          ((uint32)0x00000001U)
    #define MC_ME_MODE_MC_SYSCLK_FIRC_U32           ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_ME_MODE_MC_SYSCLK_ARM_PLL_DFS1_U32   ((uint32)0x00000002U)
    #define MC_ME_MODE_MC_SYSCLK_XOSC_U32           ((uint32)0x00000001U)
    #define MC_ME_MODE_MC_SYSCLK_FIRC_U32           ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */
/* number of bytes used by the MC_ME_*_MC registers */
#define MC_ME_MODE_MC_REG_OFFSET_U32                ((uint32)0x0000004U)


/********************************************************/
/*  ME_IS[IMTC]: Mode transition complete interrupt.    */
/********************************************************/
/*
   This bit is set whenever the mode transition process completes (S_MTRANS transits from 1 to 0).
   This mode transition interrupt bit will not be set while entering low-power modes HALT0,
   or STOP0. */
#define MC_ME_IS_I_MTC_MASK32               ((uint32)0x00000001U)
/* ME_IS[ISAFE]: SAFE mode interrupt.
   This bit is set whenever the device enters SAFE mode on hardware requests generated in the
   system. */
#define MC_ME_IS_I_SAFE_MASK32              ((uint32)0x00000002U)
/* ME_IS[IMODE]: Invalid mode interrupt.
   This bit is set whenever an invalid mode transition is requested. */
#define MC_ME_IS_I_IMODE_MASK32             ((uint32)0x00000004U)
/* ME_IS[ICONF]: Invalid mode configuration interrupt.
   This bit is set whenever a write operation to ME_<mode>_MC registers with invalid mode
   configuration is attempted. */
#define MC_ME_IS_I_ICONF_MASK32             ((uint32)0x00000008U)
/* ME_IS[I_ICONF_CU]: Invalid mode configuration interrupt (Clock Usage).
   This bit is set during a mode transition if a clock which is required to be on by an enabled
   peripheral is configured to be turned off. */
#define MC_ME_IS_I_ICONF_CU_MASK32          ((uint32)0x00000010U)
/* ME_IS[I_ICONF_CC]: Invalid mode configuration interrupt (core configuration).
   This bit is set if a write access to one of the ME_CCTLn registers is attempted while a mode
   transition is in progress. */
#define MC_ME_IS_I_ICONF_CC_MASK32          ((uint32)0x00000020U)

/* ME_IS[I_ICONF_SCC]: Invalid Mode Configuration Interrupt (Secondary Clock Configuration).
   This bit is set if the source for any of the secondary sysclks have been configured to be turned off in the target mode. 
   This bit gets set when the MCTL register is written to with an invalid configuration and the mode transition 
   request is ignored */
#define MC_ME_IS_I_ICONF_SCC_MASK32          ((uint32)0x00000040U)

/* mask to clear all enabled ISR's */
#define MC_ME_IS_I_CLEAR_MASK32             ((uint32)0x0000003FU)
/* mix all conf. ints into 1 */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
#define MC_ME_IS_I_CONF_ALL_MASK32          ( MC_ME_IS_I_ICONF_MASK32 | \
                                              MC_ME_IS_I_ICONF_CU_MASK32 | \
                                              MC_ME_IS_I_ICONF_CC_MASK32 \
                                            )
#elif ((IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_05_00_00_10))
    #define MC_ME_IS_I_CONF_ALL_MASK32          ( MC_ME_IS_I_ICONF_MASK32 | MC_ME_IS_I_ICONF_CC_MASK32 )
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_IS_I_CONF_ALL_MASK32          ( MC_ME_IS_I_ICONF_SCC_MASK32 | MC_ME_IS_I_ICONF_MASK32 | \
                                                  MC_ME_IS_I_ICONF_CU_MASK32 | MC_ME_IS_I_ICONF_MASK32 | \
                                                  MC_ME_IS_I_IMODE_MASK32 \
                                                )
#endif

/********************************************************/
/*            Interrupt Mask Register (MC_ME_IM)        */
/********************************************************/
#define MC_ME_IM_M_MTC_MASK32               ((uint32)0x00000001U)
#define MC_ME_IM_M_SAFE_MASK32              ((uint32)0x00000002U)
#define MC_ME_IM_M_IMODE_MASK32             ((uint32)0x00000004U)
#define MC_ME_IM_M_ICONF_MASK32             ((uint32)0x00000008U)
#define MC_ME_IM_M_ICONF_CU_MASK32          ((uint32)0x00000010U)
#define MC_ME_IM_M_ICONF_CC_MASK32          ((uint32)0x00000020U)
#define MC_ME_IM_M_ICONF_SCC_MASK32         ((uint32)0x00000040U)

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
#define MC_ME_IM_M_ICONF_ALL_MASK32         ( MC_ME_IM_M_ICONF_MASK32 | \
                                              MC_ME_IM_M_ICONF_CU_MASK32 | \
                                              MC_ME_IM_M_ICONF_CC_MASK32 \
                                            )
#elif ((IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_05_00_00_10))
    #define MC_ME_IM_M_ICONF_ALL_MASK32         ( MC_ME_IM_M_ICONF_MASK32 | MC_ME_IM_M_ICONF_CC_MASK32 )
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_IM_M_ICONF_ALL_MASK32         ( MC_ME_IM_M_ICONF_SCC_MASK32 | MC_ME_IM_M_ICONF_CC_MASK32 | \
                                                  MC_ME_IM_M_ICONF_CU_MASK32 | MC_ME_IM_M_ICONF_MASK32 | \
                                                  MC_ME_IM_M_IMODE_MASK32 \
                                                )
#endif
/********************************************************/
/* Invalid Mode Transition Status Register (MC_ME_IMTS) */
/********************************************************/
#if (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_IMTS_MASK32                   ((uint32)0x0000001EU)
#else
    #define MC_ME_IMTS_MASK32                   ((uint32)0x0000003FU)
#endif

/* ME_IMTS[SEA] field: SAFE Event Active status.
  This bit is set whenever the device is in SAFE mode, SAFE event bit is pending and a new mode
  requested other than RESET/SAFE modes. */
#define MC_ME_IMTS_S_SEA_MASK32             ((uint32)0x00000001U)
/* ME_IMTS[NMA] field: Non-existing Mode Access status.
   This bit is set whenever the target mode requested is one of those non existing modes determined
   by ME_ME register. */
#define MC_ME_IMTS_S_NMA_MASK32             ((uint32)0x00000002U)
/* ME_IMTS[DMA] field: Disabled Mode Access status.
  This bit is set whenever the target mode requested is one of those disabled modes determined by
  ME_ME register. */
#define MC_ME_IMTS_S_DMA_MASK32             ((uint32)0x00000004U)
/* ME_IMTS[MRI] field: Mode Request Illegal status.
  This bit is set whenever the target mode requested is not a valid mode with respect to current
  mode. */
#define MC_ME_IMTS_S_MRI_MASK32             ((uint32)0x00000008U)
/* ME_IMTS[MTI] field: Mode Transition Illegal status.
   This bit is set whenever a new mode is requested while some other mode transition process is
   active (S_MTRANS is '1'). */
#define MC_ME_IMTS_S_MTI_MASK32             ((uint32)0x00000010U)
/* Mode Request Ignored Status */
#define MC_ME_IMTS_S_MRIG_MASK32            ((uint32)0x00000020U)

#define MC_ME_IMTS_S_CLEAR_MASK32           ((uint32)0x0000003FU)


/********************************************************/
/*                      ME_ME: ME_RESET_MC              */
/********************************************************/
/* ME_ME: ME_RESET_MC register - Mask for the writable allowed bits. */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_10) || \
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_06_00_00_10) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_ME_RESET_MC_WRBITS_MASK32            ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_ME_RESET_MC_RESBITS_MASK32           ((uint32)0x00130010U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_RESET_MC_RESBITS_MASK32           ((uint32)0x00130050U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_RESET_MC_RESBITS_MASK32           ((uint32)0x00130090U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_RESET_MC_RESBITS_MASK32           ((uint32)0x00100010U)
#endif


/********************************************************/
/*                      ME_ME: ME_TEST_MC               */
/********************************************************/
/* ME_ME: ME_TEST_MC register - Mask for the writable allowed bits. */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_ME_TEST_MC_WRBITS_MASK32             ((uint32)0x708300FFU)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_TEST_MC_WRBITS_MASK32             ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_TEST_MC_WRBITS_MASK32             ((uint32)0x708007EFU)
#endif
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_TEST_MC_RESBITS_MASK32            ((uint32)0x00100010U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_04_01_00) \
      )
    #define MC_ME_TEST_MC_RESBITS_MASK32            ((uint32)0x00100000U)
#else
    #define MC_ME_TEST_MC_RESBITS_MASK32            ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */


/********************************************************/
/*                      ME_ME: ME_SAFE_MC               */
/********************************************************/
/* ME_ME: ME_SAFE_MC register - Mask for the writable allowed bits. */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_03_00_00) \
    )
    #define MC_ME_SAFE_MC_WRBITS_MASK32             ((uint32)0x00800000U)
#elif ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_10) || \
       (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_04_06_05_00) \
      )
    #define MC_ME_SAFE_MC_WRBITS_MASK32             ((uint32)0x70800000U)
#endif
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_10) || \
     (IPV_MC == IPV_MC_05_00_00_07) \
    )
    #define MC_ME_SAFE_MC_RESBITS_MASK32            ((uint32)0x00130010U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_ME_SAFE_MC_RESBITS_MASK32            ((uint32)0x00000000U)
#endif 


/********************************************************/
/*                  ME_ME: ME_DRUN_MC                   */
/********************************************************/
/* ME_ME: ME_DRUN_MC register - Mask for the writable allowed bits. */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_ME_DRUN_MC_WRBITS_MASK32             ((uint32)0x700300EFU)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_DRUN_MC_WRBITS_MASK32             ((uint32)0x700301EFU)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_DRUN_MC_WRBITS_MASK32             ((uint32)0x70030FEFU)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_DRUN_MC_WRBITS_MASK32             ((uint32)0x700301EFU)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_DRUN_MC_WRBITS_MASK32             ((uint32)0x700007EFU)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_DRUN_MC_RESBITS_MASK32                ((uint32)0x00000000U)
#else
    #define MC_ME_DRUN_MC_RESBITS_MASK32                ((uint32)0x00100010U)
#endif
/********************************************************/
/*                  ME_ME: ME_RUN0_3_MC                 */
/********************************************************/
/* ME_ME: ME_RUN0_3_MC register - Mask for the writable allowed bits. */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_ME_RUN0_3_MC_WRBITS_MASK32           ((uint32)0x700300EFU)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) || \
       (IPV_MC == IPV_MC_05_00_00_07) \
      )
    #define MC_ME_RUN0_3_MC_WRBITS_MASK32           ((uint32)0x700301EFU)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_RUN0_3_MC_WRBITS_MASK32           ((uint32)0x70030FEFU)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_RUN0_3_MC_WRBITS_MASK32           ((uint32)0x700007EFU)
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) || \
     (IPV_MC == IPV_MC_05_00_00_10) \
    )
    #define MC_ME_RUN0_3_MC_RESBITS_MASK32          ((uint32)0x00100010U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_RUN0_3_MC_RESBITS_MASK32          ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_RUN0_3_MC_RESBITS_MASK32          ((uint32)0x00100010U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */


/********************************************************/
/*                  ME_ME: ME_HALT0_MC                  */
/********************************************************/
/* ME_ME: ME_HALT0_MC register - Mask for the writable allowed bits. */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_ME_HALT0_MC_WRBITS_MASK32            ((uint32)0x000300EFU)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_HALT0_MC_WRBITS_MASK32            ((uint32)0x000301EFU)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_HALT0_MC_RESBITS_MASK32           ((uint32)0x00100010U)
#else
    #define MC_ME_HALT0_MC_RESBITS_MASK32           ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */


/********************************************************/
/*              ME_ME: ME_STOP0_MC                      */
/********************************************************/
/* ME_ME: ME_STOP0_MC register - Mask for the writable allowed bits. */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_STOP0_MC_WRBITS_MASK32            ((uint32)0x00830020U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_STOP0_MC_WRBITS_MASK32            ((uint32)0x008300FFU)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_ME_STOP0_MC_WRBITS_MASK32            ((uint32)0x0083002FU)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_STOP0_MC_WRBITS_MASK32            ((uint32)0x009301BFU)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_ME_STOP0_MC_RESBITS_MASK32           ((uint32)0x00100010U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_STOP0_MC_RESBITS_MASK32           ((uint32)0x00100000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_STOP0_MC_RESBITS_MASK32           ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */


/********************************************************/
/*              ME_ME: ME_STANDBY0_MC                   */
/********************************************************/
#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_STBY0_MC_WRBITS_MASK32                ((uint32)0x000000F0U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_STBY0_MC_WRBITS_MASK32                ((uint32)0x000001B0U)
#endif

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
    #define MC_ME_STBY0_MC_RESBITS_MASK32               ((uint32)0x0081000FU)
#endif


/********************************************************/
/*              ME_ME: ME_MCTL[KEY]                     */
/********************************************************/
/* ME_MCTL[KEY] field: Control key - These bits enable write access to this register. */
#define MC_ME_MCTL_DIRECT_KEY_U32                   ((uint32)0x00005AF0U)
/* ME_MCTL[KEY] field: Read access will always return inverted key. */
#define MC_ME_MCTL_INVERTED_KEY_U32                 ((uint32)0x0000A50FU)


#define MC_ME_PS_OFFSET_U32                         ((uint32)0x00000004U)


/********************************************************/
/*  Mode Enable Register (ME_ME) masks and defines      */
/********************************************************/
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_ME_WRBITS_MASK32                  ((uint32)0x000005E2U)
    #define MC_ME_ME_RESBITS_MASK32                 ((uint32)0x0000801DU)
#elif ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
    #define MC_ME_ME_WRBITS_MASK32                  ((uint32)0x000024E0U)
    #define MC_ME_ME_RESBITS_MASK32                 ((uint32)0x0000801DU)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_ME_WRBITS_MASK32                  ((uint32)0x000000E2U)
    #define MC_ME_ME_RESBITS_MASK32                 ((uint32)0x00000000U)
#endif

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
    #define MC_ME_ME_STBY0_MASK32                   ((uint32)0x00002000U)
#endif 

#define MC_ME_ME_STOP0_MASK32                       ((uint32)0x00000400U)
#define MC_ME_ME_HALT0_MASK32                       ((uint32)0x00000100U)
#define MC_ME_ME_RUN3_MASK32                        ((uint32)0x00000080U)
#define MC_ME_ME_RUN2_MASK32                        ((uint32)0x00000040U)
#define MC_ME_ME_RUN1_MASK32                        ((uint32)0x00000020U)
#define MC_ME_ME_TEST_MASK32                        ((uint32)0x00000002U)


/********************************************************/
/* Interrupt Mask Register (ME_IM) mask and defines     */
/********************************************************/
#define MC_ME_IM_WRBITS_MASK32                      ((uint32)0x0000003FU)
#define MC_ME_IM_RESBITS_MASK32                     ((uint32)0x00000000U)

#define MC_ME_IM_ICONF_SCC_MASK32                   ((uint32)0x00000040U)
#define MC_ME_IM_ICONF_CC_MASK32                    ((uint32)0x00000020U)
#define MC_ME_IM_ICONF_CU_MASK32                    ((uint32)0x00000010U)
#define MC_ME_IM_ICONF_MASK32                       ((uint32)0x00000008U)
#define MC_ME_IM_IMODE_MASK32                       ((uint32)0x00000004U)
#define MC_ME_IM_SAFE_MASK32                        ((uint32)0x00000002U)
#define MC_ME_IM_MTC_MASK32                         ((uint32)0x00000001U)


/********************************************************/
/*          Core Control Register (ME_CCTLn)            */
/********************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_CCTL_RWBITS_MASK16                ((uint16)0x00FEU)
#elif ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
    #define MC_ME_CCTL_RWBITS_MASK16                ((uint16)0x00FCU)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_CCTL_RWBITS_MASK16                ((uint16)0x00FAU)
#endif

#define MC_ME_CCTL_RESBITS_MASK16                   ((uint16)0x0000U)
#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
#define MC_ME_CCTL_STBY_MASK16                      ((uint16)0x2000U)
#endif
#define MC_ME_CCTL_RUN3_MASK16                      ((uint16)0x0080U)
#define MC_ME_CCTL_RUN2_MASK16                      ((uint16)0x0040U)
#define MC_ME_CCTL_RUN1_MASK16                      ((uint16)0x0020U)
#define MC_ME_CCTL_RUN0_MASK16                      ((uint16)0x0010U)
#define MC_ME_CCTL_DRUN_MASK16                      ((uint16)0x0008U)
#define MC_ME_CCTL_SAFE_MASK16                      ((uint16)0x0004U)
#define MC_ME_CCTL_TEST_MASK16                      ((uint16)0x0002U)

#define MC_ME_CCTL_UNUSED_MASK16                    ((uint16)0xFFFFU)

/********************************************************/
/*      Core Control Register (ME_CADDRn)               */
/********************************************************/
#define MC_ME_CADDR_RWBITS_MASK32                   ((uint32)0xFFFFFFFDU)
#define MC_ME_CADDR_RESBITS_MASK32                  ((uint32)0x00000000U)

#define MC_ME_CADDR_ADDR_MASK32                     ((uint32)0xFFFFFFFCU)
#define MC_ME_CADDR_RMC_MASK32                      ((uint32)0x00000001U)

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_CADDR_ADDR_EN_MASK32              ((uint32)0x00000001U)
#endif

/*****************************************************************************/
/*  <MODE> Secondary Clock Configuration Register (MC_ME_<MODE>_SEC_CC_I)   */
/****************************************************************************/
#define MC_ME_MODE_SEC_CC_I_PWRLVL3_MASK32                 ((uint32)0x70000000U)
#define MC_ME_MODE_SEC_CC_I_PWRLVL3_SHIFT32                ((uint32)28U)

#define MC_ME_MODE_SEC_CC_I_PWRLVL2_MASK32                 ((uint32)0x07000000U)
#define MC_ME_MODE_SEC_CC_I_PWRLVL2_SHIFT32                ((uint32)24U)

#define MC_ME_MODE_SEC_CC_I_PWRLVL1_MASK32                 ((uint32)0x00700000U)
#define MC_ME_MODE_SEC_CC_I_PWRLVL1_SHIFT32                ((uint32)20U)

#define MC_ME_MODE_SEC_CC_I_SYSCLK3_MASK32                 ((uint32)0x0000F000U)
#define MC_ME_MODE_SEC_CC_I_SYSCLK3_SHIFT32                ((uint32)12U)

#define MC_ME_MODE_SEC_CC_I_SYSCLK2_MASK32                 ((uint32)0x00000F00U)
#define MC_ME_MODE_SEC_CC_I_SYSCLK2_SHIFT32                ((uint32)8U)

#define MC_ME_MODE_SEC_CC_I_SYSCLK1_MASK32                 ((uint32)0x000000F0U)
#define MC_ME_MODE_SEC_CC_I_SYSCLK1_SHIFT32                ((uint32)4U)

/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK3_ARM_PLL_DFS3_U32    ((uint32)0x00002000U)
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK3_XOSC_U32            ((uint32)0x00001000U)
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK3_FIRC_U32            ((uint32)0x00000000U)
    
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK2_ARM_PLL_DFS2_U32    ((uint32)0x00000200U)
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK2_XOSC_U32            ((uint32)0x00000100U)
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK2_FIRC_U32            ((uint32)0x00000000U)

/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK1_ARM_PLL_U32         ((uint32)0x00000020U)
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK1_XOSC_U32            ((uint32)0x00000010U)
/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_SYSCLK1_FIRC_U32            ((uint32)0x00000000U)

/** @violates @ref REG_ESYS_MC_ME_H_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_MODE_SEC_CC_I_ALL_SYSCLKS_MASK32          (MC_ME_MODE_SEC_CC_I_SYSCLK3_MASK32 | \
                                                         MC_ME_MODE_SEC_CC_I_SYSCLK2_MASK32 | \
                                                         MC_ME_MODE_SEC_CC_I_SYSCLK1_MASK32 \
                                                        )

#ifdef MCU_ERR009139_IPV_MC_05000007
#if (MCU_ERR009139_IPV_MC_05000007 == STD_ON)
/*****************************************************************************/
/*  GPR SLEEP Register (GPR_SLEEP)   */
/****************************************************************************/
#define MC_ME_GPR_SLEEP_RWBITS_MASK32                   ((uint32)0x00000043U)
#define MC_ME_GPR_SLEEP_RESBITS_MASK32                  ((uint32)0x00000000U)

#define MC_ME_GPR_SLEEP_ENABLE_U32                      ((uint32)0x00000043U)

#define MC_ME_GPR_SLEEP_DEFAULT_U32                     ((uint32)0x00000000U)

#endif  /* MCU_ERR009139_IPV_MC_05000007 */
#endif  /* (MCU_ERR009139_IPV_MC_05000007 == STD_ON) */

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

#endif /* REG_ESYS_MC_ME_H */

/** @} */
