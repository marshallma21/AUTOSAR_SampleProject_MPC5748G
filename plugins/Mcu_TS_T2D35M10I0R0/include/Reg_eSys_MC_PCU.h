/**
*   @file    Reg_eSys_MC_PCU.h
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


#ifndef REG_ESYS_MC_PCU_H
#define REG_ESYS_MC_PCU_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_MC_PCU_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, : The compiler/linker shall be checked to ensure that 31
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
#include "Mcu_Cfg.h"
#include "Reg_eSys.h"
#include "Mcu_MC_IPVersion.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_MC_PCU_VENDOR_ID                       43
/** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_PCU_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_PCU_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_PCU_AR_RELEASE_REVISION_VERSION     2
/** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_PCU_SW_MAJOR_VERSION                1
/** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_PCU_SW_MINOR_VERSION                0
/** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_PCU_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (REG_ESYS_MC_PCU_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Reg_eSys_MC_PCU.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((REG_ESYS_MC_PCU_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_MC_PCU_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_MC_PCU_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Reg_eSys_MC_PCU.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((REG_ESYS_MC_PCU_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (REG_ESYS_MC_PCU_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (REG_ESYS_MC_PCU_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_MC_PCU.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Mcu_MC_IPVersion header file are from the same vendor */
#if (REG_ESYS_MC_PCU_VENDOR_ID != MCU_MC_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_MC_PCU.h and Mcu_MC_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_MC_PCU_AR_RELEASE_MAJOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_MC_PCU_AR_RELEASE_MINOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_MC_PCU_AR_RELEASE_REVISION_VERSION != MCU_MC_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_MC_PCU.h and Mcu_MC_IPVersion.h are different"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Software version */
#if ((REG_ESYS_MC_PCU_SW_MAJOR_VERSION != MCU_MC_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_MC_PCU_SW_MINOR_VERSION != MCU_MC_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_MC_PCU_SW_PATCH_VERSION != MCU_MC_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_MC_PCU.h and Mcu_MC_IPVersion.h are different"
#endif

/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_MC_PCU_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_MC_PCU_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_MC_PCU.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/********** MC_PCU Registers **********/

/* PCU: Power Domain Status Register Address. */
#define MC_PCU_PSTAT_ADDR32                     ((uint32)( PCU_BASEADDR + (uint32)0x0040U))

/* PCU_STAT[PD0] bit mask. */
#define MC_PCU_STAT_PD0_MASK32                  ((uint32)0x00000001U)


/********** PMU Registers **********/

#if (IPV_MC == IPV_MC_04_04_01_00)
    /* PMC - Status Register. */
    #define PMC_PMCSR_ADDR32                    ((uint32)(PMC_BASEADDR + (uint32)0x0000U))
    /* PMC - Regulator Voltage Status Register. */
    #define PMC_RSSR_ADDR32                     ((uint32)(PMC_BASEADDR + (uint32)0x0004U))
    /* PMC - Control Register. */
    #define PMC_PMCCR_ADDR32                    ((uint32)(PMC_BASEADDR + (uint32)0x0008U))
    /* PMC - Interrupt Enable Register. */
    #define PMC_IER_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x0010U))
    /* PMC - Event Status Register 0. */
    #define PMC_ESR_0_ADDR32                    ((uint32)(PMC_BASEADDR + (uint32)0x0020U))
    /* PMC - Reset Event Enable Register 0. */
    #define PMC_REE_0_ADDR32                    ((uint32)(PMC_BASEADDR + (uint32)0x0030U))
    /* PMC - Reset Event Selection Register 0. */
    #define PMC_RES_0_ADDR32                    ((uint32)(PMC_BASEADDR + (uint32)0x0040U))
    /* PMC - FCCU Fault Injection Register. */
    #define PMC_FIR_ADDR32                      ((uint32)(PMC_BASEADDR + (uint32)0x0070U))
    /* PMC - LVD Sense Select Register. */
    #define PMC_LVD_SS_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x00F0U))
    /* PMC - Temperature Event Status Register. */
    #define PMC_ESR_TD_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x0100U))
    /* PMC - Temperature Reset Event Enable Register. */
    #define PMC_REE_TD_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x0104U))
    /* PMC - Temperature Reset Event Selection Register. */
    #define PMC_RES_TD_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x0108U))
    /* PMC - Temperature Detector Configuration Register. */
    #define PMC_CTL_TD_ADDR32                   ((uint32)(PMC_BASEADDR + (uint32)0x010CU))
    /* PMC - LVD Self Test Time Window Register. */
    #define PMC_STTW_ADDR32                     ((uint32)(PMC_BASEADDR + (uint32)0x013CU))
    /* PMC - Voltage Detect User Mode Test Register. */
    #define PMC_VD_UTST_ADDR32                  ((uint32)(PMC_BASEADDR + (uint32)0x0140U))


    /****************************************************/
    /***              PMC_PMCCR                       ***/
    /****************************************************/
    #define PMC_PMCCR_RWBITS_MASK32                     ((uint32)0x80000003U)
    #define PMC_PMCCR_RESBITS_MASK32                    ((uint32)0x00000000U)

    #define PMC_PMCCR_PMCCR_EN_MASK32                   ((uint32)0x80000000U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_INT_AUX_REG_BYPASS_MASK32         ((uint32)0x00000002U)
    #define PMC_PMCCR_INT_REG_BYPASS_MASK32             ((uint32)0x00000001U)


    /****************************************************/
    /***              PMC_IER                         ***/
    /****************************************************/
    #define PMC_IER_RWBITS_MASK32                       ((uint32)0xBF007C98U)
    #define PMC_IER_RESBITS_MASK32                      ((uint32)0x00000000U)

    #define PMC_PMCCR_IE_EN_MASK32                      ((uint32)0x80000000U)
    #define PMC_IER_TS1_3IE_MASK32                      ((uint32)0x20000000U)
    #define PMC_IER_TS1_2IE_MASK32                      ((uint32)0x10000000U)
    #define PMC_IER_TS1_0IE_MASK32                      ((uint32)0x08000000U)
    #define PMC_IER_TS0_3IE_MASK32                      ((uint32)0x04000000U)
    #define PMC_IER_TS0_2IE_MASK32                      ((uint32)0x02000000U)
    #define PMC_IER_TS0_0IE_MASK32                      ((uint32)0x01000000U)
    #define PMC_IER_VD6IE_O_MASK32                      ((uint32)0x00004000U)
    #define PMC_IER_VD6IE_ADC_MASK32                    ((uint32)0x00002000U)
    #define PMC_IER_VD6IE_IM_MASK32                     ((uint32)0x00001000U)
    #define PMC_IER_VD6IE_F_MASK32                      ((uint32)0x00000800U)
    #define PMC_IER_VD6IE_C_MASK32                      ((uint32)0x00000400U)
    #define PMC_IER_VD4IE_C_MASK32                      ((uint32)0x00000080U)
    #define PMC_IER_VD3IE_H_MASK32                      ((uint32)0x00000010U)
    #define PMC_IER_VD3IE_C_MASK32                      ((uint32)0x00000008U)

    /* all temp sens bits */
    #define PMC_IER_TEMPI_E_MASK32                      ((uint32)0x3F000000U)
    /* all vsense bits */
    #define PMC_IER_VOLTI_E_MASK32                      ((uint32)0x00007C98U)


    /****************************************************/
    /***              PMC_ESR_0                       ***/
    /****************************************************/
    #define PMC_ESR_0_RWBITS_MASK32                     ((uint32)0x002A7D9BU)
    #define PMC_ESR_0_VD0_C_MASK32                      ((uint32)0x00200000U)
    #define PMC_ESR_0_VD15_C_MASK32                     ((uint32)0x00080000U)
    #define PMC_ESR_0_VD12_C_MASK32                     ((uint32)0x00020000U)
    #define PMC_ESR_0_VD6_O_MASK32                      ((uint32)0x00004000U)
    #define PMC_ESR_0_VD6_ADC_MASK32                    ((uint32)0x00002000U)
    #define PMC_ESR_0_VD6_IM_MASK32                     ((uint32)0x00001000U)
    #define PMC_ESR_0_VD6_F_MASK32                      ((uint32)0x00000800U)
    #define PMC_ESR_0_VD6_C_MASK32                      ((uint32)0x00000400U)
    #define PMC_ESR_0_VD5_C_MASK32                      ((uint32)0x00000100U)
    #define PMC_ESR_0_VD4_C_MASK32                      ((uint32)0x00000080U)
    #define PMC_ESR_0_VD3_H_MASK32                      ((uint32)0x00000010U)
    #define PMC_ESR_0_VD3_C_MASK32                      ((uint32)0x00000008U)
    #define PMC_ESR_0_VD2_C_MASK32                      ((uint32)0x00000002U)
    #define PMC_ESR_0_VD1_C_MASK32                      ((uint32)0x00000001U)


    /****************************************************/
    /***              PMC_REE_0                       ***/
    /****************************************************/
    #define PMC_REE_0_RWBITS_MASK32                     ((uint32)0x00007C98U)
    #define PMC_REE_0_RESBITS_MASK32                    ((uint32)0x00000000U)

    #define PMC_REE_0_VD6RE_O_MASK32                    ((uint32)0x00004000U)
    #define PMC_REE_0_VD6RE_ADC_MASK32                  ((uint32)0x00002000U)
    #define PMC_REE_0_VD6RE_IM_MASK32                   ((uint32)0x00001000U)
    #define PMC_REE_0_VD6RE_F_MASK32                    ((uint32)0x00000800U)
    #define PMC_REE_0_VD6RE_C_MASK32                    ((uint32)0x00000400U)
    #define PMC_REE_0_VD4RE_C_MASK32                    ((uint32)0x00000080U)
    #define PMC_REE_0_VD3RE_H_MASK32                    ((uint32)0x00000010U)
    #define PMC_REE_0_VD3RE_C_MASK32                    ((uint32)0x00000008U)


    /****************************************************/
    /***              PMC_RES_0                       ***/
    /****************************************************/
    #define PMC_RES_0_RWBITS_MASK32                     ((uint32)0x00007C98U)
    #define PMC_RES_0_RESBITS_MASK32                    ((uint32)0x00000000U)

    #define PMC_RES_0_VD6RE_O_MASK32                    ((uint32)0x00004000U)
    #define PMC_RES_0_VD6RE_ADC_MASK32                  ((uint32)0x00002000U)
    #define PMC_RES_0_VD6RE_IM_MASK32                   ((uint32)0x00001000U)
    #define PMC_RES_0_VD6RE_F_MASK32                    ((uint32)0x00000800U)
    #define PMC_RES_0_VD6RE_C_MASK32                    ((uint32)0x00000400U)
    #define PMC_RES_0_VD4RE_C_MASK32                    ((uint32)0x00000080U)
    #define PMC_RES_0_VD3RE_H_MASK32                    ((uint32)0x00000010U)
    #define PMC_RES_0_VD3RE_C_MASK32                    ((uint32)0x00000008U)


    /****************************************************/
    /***              PMC_ESR_TD                      ***/
    /****************************************************/
    #define PMC_ESR_TD_RWBITS_MASK32                    ((uint32)0x00000D0DU)



    /****************************************************/
    /***              PMC_REE_TD                      ***/
    /****************************************************/
    #define PMC_REE_TD_RWBITS_MASK32                    ((uint32)0x00000D0DU)
    #define PMC_REE_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_REE_TD_TEMP1_3_MASK32                   ((uint32)0x00000800U)
    #define PMC_REE_TD_TEMP1_2_MASK32                   ((uint32)0x00000400U)
    #define PMC_REE_TD_TEMP1_0_MASK32                   ((uint32)0x00000100U)
    #define PMC_REE_TD_TEMP0_3_MASK32                   ((uint32)0x00000008U)
    #define PMC_REE_TD_TEMP0_2_MASK32                   ((uint32)0x00000004U)
    #define PMC_REE_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)


    /****************************************************/
    /***              PMC_RES_TD                      ***/
    /****************************************************/
    #define PMC_RES_TD_RWBITS_MASK32                    ((uint32)0x00000D0DU)
    #define PMC_RES_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_RES_TD_TEMP1_3_MASK32                   ((uint32)0x00000800U)
    #define PMC_RES_TD_TEMP1_2_MASK32                   ((uint32)0x00000400U)
    #define PMC_RES_TD_TEMP1_0_MASK32                   ((uint32)0x00000100U)
    #define PMC_RES_TD_TEMP0_3_MASK32                   ((uint32)0x00000008U)
    #define PMC_RES_TD_TEMP0_2_MASK32                   ((uint32)0x00000004U)
    #define PMC_RES_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)


    /****************************************************/
    /***              PMC_CTL_TD                      ***/
    /****************************************************/
    #define PMC_CTL_TD_RWBITS_MASK32                    ((uint32)0x00007F7FU)
    #define PMC_CTL_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_CTL_TD_TS1_TRIM_ADJ_MASK32              ((uint32)0x00007C00U)
    #define PMC_CTL_TD_TS1_DOUT_EN_MASK32               ((uint32)0x00000200U)
    #define PMC_CTL_TD_TS1_AOUT_EN_MASK32               ((uint32)0x00000100U)
    #define PMC_CTL_TD_TS0_TRIM_ADJ_MASK32              ((uint32)0x0000007CU)
    #define PMC_CTL_TD_TS0_DOUT_EN_MASK32               ((uint32)0x00000002U)
    #define PMC_CTL_TD_TS0_AOUT_EN_MASK32               ((uint32)0x00000001U)


    /****************************************************/
    /***              PMC_FIR                         ***/
    /****************************************************/

    #define PMC_FIR_STEST_FAULT_MASK32                  ((uint32)0x00000008U)
    #define PMC_FIR_TSNS_FAULT_MASK32                   ((uint32)0x00000004U)
    #define PMC_FIR_HVD_FAULT_MASK32                    ((uint32)0x00000002U)
    #define PMC_FIR_LVD_FAULT_MASK32                    ((uint32)0x00000001U)


#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    
    /* Analog front end Interrupt Enable Register (PMC_AFE_INTR_ENA) */
    #define PMC_AFE_INTR_ENA_ADDR32                     ((uint32)(PMC_BASEADDR + (uint32)0x0078U))
    /* Interrupt Enable Register (PMC_AFE_INTR_STATUS) */
    #define PMC_AFE_INTR_STATUS_ADDR32                  ((uint32)(PMC_BASEADDR + (uint32)0x0080U))
    /* PMC Control Register (PMC_PMCCR) */
    #define PMC_PMCCR_ADDR32                            ((uint32)(PMC_BASEADDR + (uint32)0x0094U))
    /* Temperature Sensor Interrupt Enable Register (PMC_TS_IER) */
    #define PMC_TS_IER_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0098U))
    /* Temperature Sensor Event Status Registers (TS_ESR) */
    #define PMC_ESR_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x009CU))
    /* Reset Event Enable 0 (PMC_REE_TD) */
    #define PMC_REE_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00A0U))
    /* Reset Event Selection 0 (PMC_RES_TD) */
    #define PMC_RES_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00A4U))
    /* Fault Injection Register (PMC_TS_FIR) */
    #define PMC_TS_FIR_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00B4U))
    
    /* bit defines and masks */
    /************************************/
    /******** PMC_PMCCR_ADDR32 **********/
    /************************************/
    /* actual available bits */
    #define PMC_PMCCR_RWBITS_MASK32                     ((uint32)0xC00001DFU)
    /* user available bits */
    #define PMC_PMCCR_RWBITS_USR_MASK32                 ((uint32)0x400001DFU)
    /* bits that must be 1 */
    #define PMC_PMCCR_RESBITS_MASK32                    ((uint32)0x00000020U)
    /* PMC Enable Control */
    #define PMC_PMCCR_ENABLE_MASK32                     ((uint32)0x80000000U)
    /* Internal/External regulator Selection */
    #define PMC_PMCCR_INT_EXT_MODE_MASK32               ((uint32)0x40000000U)
    /* This bit controls the enable/disable on the LVD MIPI supply. */
    #define PMC_PMCCR_LVD_MIPI_ENABLE_MASK32             ((uint32)0x00000100U)
    /* This bit controls the enable/disable on the LVD PMC supply. */
    #define PMC_PMCCR_LVD_PMC_ENABLE_MASK32             ((uint32)0x00000080U)
    /*This bit controls the enable/disable on the LVD IO supply. */
    #define PMC_PMCCR_LVD_IO_ENABLE_MASK32              ((uint32)0x00000040U)
    /* This bit controls the enable/disable on the LVD FLASH supply. */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_FLASH_ENABLE_MASK32           ((uint32)0x00000010U)
    /* This bit controls the enable/disable on the HVD ADC supply. */
    #define PMC_PMCCR_HVD_ADC_ENABLE_MASK32             ((uint32)0x00000008U)
    /* This bit controls the enable/disable on the LVD ADC supply. */
    #define PMC_PMCCR_LVD_ADC_ENABLE_MASK32             ((uint32)0x00000004U)
    /* This bit controls the enable/disable on the HVD Core supply. */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_HVD_CORE_INT_ENABLE_MASK32        ((uint32)0x00000002U)
    /* LVD Core and LVD_PLL Enable Disbale control bit. */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_CORE_INT_ENABLE_MASK32        ((uint32)0x00000001U)

    /************************************/
    /******** PMC_TS_IER_ADDR32 *********/
    /************************************/
    #define PMC_TS_IER_RWBITS_MASK32                    ((uint32)0x8000003FU)
    #define PMC_TS_IER_RWBITS_USR_MASK32                ((uint32)0x0000003FU)
    #define PMC_TS_IER_RESBITS_MASK32                   ((uint32)0x80000000U)
    /* Temperature Sensor interrupts Enable */
    #define PMC_TS_IER_TS_EN_MASK32                     ((uint32)0x80000000U)
    /* Temperature Sensor 1 input 3 Interrupt Enable. */
    #define PMC_TS_IER_TS1_3IE_MASK32                   ((uint32)0x00000020U)
    /* Temperature Sensor 1 input 2 Interrupt Enable. */
    #define PMC_TS_IER_TS1_2IE_MASK32                   ((uint32)0x00000010U)
    /* Temperature Sensor 1 input 0 Interrupt Enable. */
    #define PMC_TS_IER_TS1_0IE_MASK32                   ((uint32)0x00000008U)
    /* Temperature Sensor 0 input 3 Interrupt Enable. */
    #define PMC_TS_IER_TS0_3IE_MASK32                   ((uint32)0x00000004U)
    /* Temperature Sensor 0 input 2 Interrupt Enable. */
    #define PMC_TS_IER_TS0_2IE_MASK32                   ((uint32)0x00000002U)
    /* Temperature Sensor 0 input 0 Interrupt Enable. */
    #define PMC_TS_IER_TS0_0IE_MASK32                   ((uint32)0x00000001U)

    /************************************/
    /******* PMC_AFE_INTR_ENA_ADDR32 ****/
    /************************************/
    
    /* Interrupt Enable. */
    #define PMC_AFE_INTR_ENA_IE_EN_MASK32               ((uint32)0x80000000U)
    #define PMC_AFE_INTR_ENA_RESBITS_MASK32             ((uint32)0x00000000U)
    
#if (MCU_MIPI_PRESENT == STD_ON)
    #define PMC_AFE_INTR_ENA_RWBITS_MASK32              ((uint32)0x800000FFU)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_RWBITS_USR_MASK32          ((uint32)0x000000FEU)
#else
    #define PMC_AFE_INTR_ENA_RWBITS_MASK32              ((uint32)0x8000017EU)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_RWBITS_USR_MASK32          ((uint32)0x0000017EU)
#endif

    /* AFE-9 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG9_MASK32    ((uint32)0x00000100U)
    /* AFE-8 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG8_MASK32    ((uint32)0x00000080U)
    /* AFE-7 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG7_MASK32    ((uint32)0x00000040U)
    /* AFE-6 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG6_MASK32    ((uint32)0x00000020U)
    /* AFE-5 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG5_MASK32    ((uint32)0x00000010U)
    /* AFE-4 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG4_MASK32    ((uint32)0x00000008U)
    /* AFE-3 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG3_MASK32    ((uint32)0x00000004U)
    /* AFE-2 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG2_MASK32    ((uint32)0x00000002U)
    /* AFE-1 Interrupt Enable/Disable Control */
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_AFE_INTR_ENA_AFE_INT_EN_VREG1_MASK32    ((uint32)0x00000001U)
    
    /************************************/
    /***** PMC_AFE_INTR_STATUS_ADDR32 ***/
    /************************************/
    #define PMC_AFE_INTR_STATUS_MASK32                  ((uint32)0x000001FFU)

    /************************************/
    /********* PMC_REE_TD_ADDR32 *********/
    /************************************/
    #define PMC_REE_TD_RWBITS_MASK32                    ((uint32)0x0000003FU)
    #define PMC_REE_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    
    #define PMC_REE_TD_TEMP1_3_MASK32                   ((uint32)0x00000020U)
    #define PMC_REE_TD_TEMP1_2_MASK32                   ((uint32)0x00000010U)
    #define PMC_REE_TD_TEMP1_0_MASK32                   ((uint32)0x00000008U)
    #define PMC_REE_TD_TEMP0_3_MASK32                   ((uint32)0x00000004U)
    #define PMC_REE_TD_TEMP0_2_MASK32                   ((uint32)0x00000002U)
    #define PMC_REE_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***              PMC_RES_TD                      ***/
    /****************************************************/
    #define PMC_RES_TD_RWBITS_MASK32                    ((uint32)0x0000003FU)
    #define PMC_RES_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_RES_TD_TEMP1_3_MASK32                   ((uint32)0x00000020U)
    #define PMC_RES_TD_TEMP1_2_MASK32                   ((uint32)0x00000010U)
    #define PMC_RES_TD_TEMP1_0_MASK32                   ((uint32)0x00000008U)
    #define PMC_RES_TD_TEMP0_3_MASK32                   ((uint32)0x00000004U)
    #define PMC_RES_TD_TEMP0_2_MASK32                   ((uint32)0x00000002U)
    #define PMC_RES_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)

    /************************************/
    /******** PMC_TS_FIR_ADDR32 **********/
    /************************************/
    /* actual available bits */
    #define  PMC_TS_FIR_TSNS_FAULT_MASK32               ((uint32)0x00000001U)

    /************************************/
    /********* PMC_ESR_TD_ADDR32 ********/
    /************************************/
    #define PMC_ESR_TD_MASK32                           ((uint32)0x0000003FU)

#elif ( IPV_MC == IPV_MC_04_00_15_15 )
    /* Supply Gauge Status Register (GR_S) */
    #define PMC_GR_S_ADDR32                             ((uint32)(PMC_BASEADDR + (uint32)0x0000U))
    /* Pending Gauge Status Register (GR_P) */
    #define PMC_GR_P_ADDR32                             ((uint32)(PMC_BASEADDR + (uint32)0x0004U))
    /* Interrupt Enable Pending Register (IE_P) */
    #define PMC_IER_ADDR32                              ((uint32)(PMC_BASEADDR + (uint32)0x0008U))
    /* LVD280 Event Pending register VD3 (EPR_VD3) */
    #define PMC_EPR_VD3_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0030U))
    /* Reset Event Enable VD3 (REE_VD3) */
    #define PMC_REE_VD3_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0034U))
    /* Reset Event Selection VD3 (RES_VD3) */
    #define PMC_RES_VD3_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0038U))
    /* FCCU Event Enable VD3 (FEE_VD3) */
    #define PMC_FEE_VD3_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x003CU))
    /* LVD280 Event Pending register VD4 (EPR_VD4) */
    #define PMC_EPR_VD4_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0040U))
    /* Reset Event Enable VD3 (REE_VD4) */
    #define PMC_REE_VD4_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0044U))
    /* Reset Event Selection VD3 (RES_VD4) */
    #define PMC_RES_VD4_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0048U))
    /* FCCU Event Enable VD3 (FEE_VD4) */
    #define PMC_FEE_VD4_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x004CU))
    /* LVD280 Event Pending register VD7 (EPR_VD7) */
    #define PMC_EPR_VD7_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0070U))
    /* Reset Event Enable VD3 (REE_VD7) */
    #define PMC_REE_VD7_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0074U))
    /* Reset Event Selection VD3 (RES_VD7) */
    #define PMC_RES_VD7_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0078U))
    /* FCCU Event Enable VD3 (FEE_VD7) */
    #define PMC_FEE_VD7_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x007CU))
    /* LVD280 Event Pending register VD8 (EPR_VD8) */
    #define PMC_EPR_VD8_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0080U))
    /* Reset Event Enable VD3 (REE_VD8) */
    #define PMC_REE_VD8_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0084U))
    /* Reset Event Selection VD3 (RES_VD8) */
    #define PMC_RES_VD8_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0088U))
    /* FCCU Event Enable VD3 (FEE_VD8) */
    #define PMC_FEE_VD8_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x008CU))
    /* LVD280 Event Pending register VD9 (EPR_VD9) */
    #define PMC_EPR_VD9_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0090U))
    /* Reset Event Enable VD9 (REE_VD9) */
    #define PMC_REE_VD9_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0094U))
    /* Reset Event Selection VD9 (RES_VD9) */
    #define PMC_RES_VD9_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0098U))
    /* FCCU Event Enable VD3 (FEE_VD9) */
    #define PMC_FEE_VD9_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x009CU))
    /* LVD280 Event Pending register VD10 (EPR_VD10) */
    #define PMC_EPR_VD10_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00A0U))
    /* Reset Event Enable VD10 (REE_VD10) */
    #define PMC_REE_VD10_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00A4U))
    /* FCCU Event Enable VD10 (FEE_VD10) */
    #define PMC_FEE_VD10_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00ACU))
    /* LVD280 Event Pending register VD12 (EPR_VD12) */
    #define PMC_EPR_VD12_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00C0U))
    /* Reset Event Enable VD12 (REE_VD12) */
    #define PMC_REE_VD12_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00C4U))
    /* Reset Event Selection VD12 (RES_VD12) */
    #define PMC_RES_VD12_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00C8U))
    /* FCCU Event Enable VD12 (FEE_VD12) */
    #define PMC_FEE_VD12_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00CCU))
    /* LVD280 Event Pending register VD13 (EPR_VD13) */
    #define PMC_EPR_VD13_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00D0U))
    /* Reset Event Enable VD13 (REE_VD13) */
    #define PMC_REE_VD13_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00D4U))
    /* Reset Event Selection VD13 (RES_VD13) */
    #define PMC_RES_VD13_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00D8U))
    /* FCCU Event Enable VD13 (FEE_VD13) */
    #define PMC_FEE_VD13_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00DCU))
    /* LVD280 Event Pending register VD14 (EPR_VD14) */
    #define PMC_EPR_VD14_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00E0U))
    /* Reset Event Enable VD14 (REE_VD14) */
    #define PMC_REE_VD14_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00E4U))
    /* Reset Event Selection VD14 (RES_VD14) */
    #define PMC_RES_VD14_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00E8U))
    /* FCCU Event Enable VD14 (FEE_VD14) */
    #define PMC_FEE_VD14_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00ECU))
    /* LVD280 Event Pending register VD15 (EPR_VD15) */
    #define PMC_EPR_VD15_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00F0U))
    /* Reset Event Enable VD15 (REE_VD15) */
    #define PMC_REE_VD15_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00F4U))
    /* Reset Event Selection VD15 (RES_VD15) */
    #define PMC_RES_VD15_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00F8U))
    /* FCCU Event Enable VD15 (FEE_VD15) */
    #define PMC_FEE_VD15_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00FCU))
    /* Voltage Supply for I/O Segments Register (VSIO) */
    #define PMC_VSIO_ADDR32                             ((uint32)(PMC_BASEADDR + (uint32)0x0104U))
    /* Temperature Event Pending register (EPR_TD) */
    #define PMC_EPR_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0300U))
    /* Temperature Reset Event Enable register (REE_TD) */
    #define PMC_REE_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0304U))
    /* Temperature Reset Event Selection register (RES_TD) */
    #define PMC_RES_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0308U))
    /* Temperature detector configuration register (CTL_TD) */
    #define PMC_CTL_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x030CU))
    /* Temperature FCCU Event Enable register (FEE_TD) */
    #define PMC_FEE_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0318U))


    /****************************************************/
    /***               (GR_S)                         ***/
    /****************************************************/
    #define PMC_GR_S_RWBITS_MASK32                      ((uint32)0x00000000U)
    #define PMC_GR_S_RESBITS_MASK32                     ((uint32)0x00000000U)
    #define PMC_GR_S_VD15_MASK32                        ((uint32)0x00008000U)
    #define PMC_GR_S_VD14_MASK32                        ((uint32)0x00004000U)
    #define PMC_GR_S_VD13_MASK32                        ((uint32)0x00002000U)
    #define PMC_GR_S_VD12_MASK32                        ((uint32)0x00001000U)
    #define PMC_GR_S_VD10_MASK32                        ((uint32)0x00000400U)
    #define PMC_GR_S_VD9_MASK32                         ((uint32)0x00000200U)
    #define PMC_GR_S_VD8_MASK32                         ((uint32)0x00000100U)
    #define PMC_GR_S_VD7_MASK32                         ((uint32)0x00000080U)
    #define PMC_GR_S_VD4_MASK32                         ((uint32)0x00000010U)
    #define PMC_GR_S_VD3_MASK32                         ((uint32)0x00000008U)

    /****************************************************/
    /***               (GR_P)                         ***/
    /****************************************************/
    #define PMC_GR_P_RWBITS_MASK32                      ((uint32)0x00000000U)
    #define PMC_GR_P_RESBITS_MASK32                     ((uint32)0x00000000U)
    #define PMC_GR_P_VD15_A_MASK32                      ((uint32)0x02000000U)
    #define PMC_GR_P_VD15_C_MASK32                      ((uint32)0x01000000U)
    #define PMC_GR_P_VD14_A_MASK32                      ((uint32)0x00400000U)
    #define PMC_GR_P_VD14_IM_MASK32                     ((uint32)0x00200000U)
    #define PMC_GR_P_VD13_IM_MASK32                     ((uint32)0x00040000U)
    #define PMC_GR_P_VD12_F_MASK32                      ((uint32)0x00020000U)
    #define PMC_GR_P_VD10_A_MASK32                      ((uint32)0x00010000U)
    #define PMC_GR_P_VD10_F_MASK32                      ((uint32)0x00008000U)
    #define PMC_GR_P_VD9_O_MASK32                       ((uint32)0x00004000U)
    #define PMC_GR_P_VD9_IF2_MASK32                     ((uint32)0x00002000U)
    #define PMC_GR_P_VD9_IF_MASK32                      ((uint32)0x00001000U)
    #define PMC_GR_P_VD9_IJ_MASK32                      ((uint32)0x00000800U)
    #define PMC_GR_P_VD9_IM_MASK32                      ((uint32)0x00000400U)
    #define PMC_GR_P_VD9_F_MASK32                       ((uint32)0x00000200U)
    #define PMC_GR_P_VD9_EBI_MASK32                     ((uint32)0x00000100U)
    #define PMC_GR_P_VD9_C_MASK32                       ((uint32)0x00000080U)
    #define PMC_GR_P_VD8_C_MASK32                       ((uint32)0x00000040U)
    #define PMC_GR_P_VD8_F_MASK32                       ((uint32)0x00000020U)
    #define PMC_GR_P_VD7_C_MASK32                       ((uint32)0x00000010U)
    #define PMC_GR_P_VD4_C_MASK32                       ((uint32)0x00000008U)
    #define PMC_GR_P_VD3_P_MASK32                       ((uint32)0x00000004U)
    #define PMC_GR_P_VD3_F_MASK32                       ((uint32)0x00000002U)
    #define PMC_GR_P_VD3_C_MASK32                       ((uint32)0x00000001U)

    /****************************************************/
    /***               (IE_P)                         ***/
    /****************************************************/
    #define PMC_IER_RWBITS_MASK32                       ((uint32)0x8367FFFFU)
    #define PMC_IER_RESBITS_MASK32                      ((uint32)0x00000000U)
    #define PMC_IER_IE_EN_MASK32                        ((uint32)0x80000000U)
    #define PMC_IER_VD15IE_A_MASK32                     ((uint32)0x02000000U)
    #define PMC_IER_VD15IE_C_MASK32                     ((uint32)0x01000000U)
    #define PMC_IER_VD14IE_A_MASK32                     ((uint32)0x00400000U)
    #define PMC_IER_VD14IE_IM_MASK32                    ((uint32)0x00200000U)
    #define PMC_IER_VD13IE_IM_MASK32                    ((uint32)0x00040000U)
    #define PMC_IER_VD12IE_F_MASK32                     ((uint32)0x00020000U)
    #define PMC_IER_VD10IE_A_MASK32                     ((uint32)0x00010000U)
    #define PMC_IER_VD10IE_F_MASK32                     ((uint32)0x00008000U)
    #define PMC_IER_VD9IE_O_MASK32                      ((uint32)0x00004000U)
    #define PMC_IER_VD9IE_IF2_MASK32                    ((uint32)0x00002000U)
    #define PMC_IER_VD9IE_IF_MASK32                     ((uint32)0x00001000U)
    #define PMC_IER_VD9IE_IJ_MASK32                     ((uint32)0x00000800U)
    #define PMC_IER_VD9IE_IM_MASK32                     ((uint32)0x00000400U)
    #define PMC_IER_VD9IE_F_MASK32                      ((uint32)0x00000200U)
    #define PMC_IER_VD9IE_EBI_MASK32                    ((uint32)0x00000100U)
    #define PMC_IER_VD9IE_C_MASK32                      ((uint32)0x00000080U)
    #define PMC_IER_VD8IE_F_MASK32                      ((uint32)0x00000040U)
    #define PMC_IER_VD8IE_C_MASK32                      ((uint32)0x00000020U)
    #define PMC_IER_VD7IE_C_MASK32                      ((uint32)0x00000010U)
    #define PMC_IER_VD4IE_C_MASK32                      ((uint32)0x00000008U)
    #define PMC_IER_VD3IE_P_MASK32                      ((uint32)0x00000004U)
    #define PMC_IER_VD3IE_F_MASK32                      ((uint32)0x00000002U)
    #define PMC_IER_VD3IE_C_MASK32                      ((uint32)0x00000001U)

    #define PMC_IER_VD3IE_MASK32                        ((uint32)0x00000007U)
    #define PMC_IER_VD4IE_MASK32                        ((uint32)0x00000008U)
    #define PMC_IER_VD7IE_MASK32                        ((uint32)0x00000010U)
    #define PMC_IER_VD8IE_MASK32                        ((uint32)0x00000060U)
    #define PMC_IER_VD9IE_MASK32                        ((uint32)0x00007F80U)
    #define PMC_IER_VD10IE_MASK32                       ((uint32)0x00018000U)
    #define PMC_IER_VD12IE_MASK32                       ((uint32)0x00020000U)
    #define PMC_IER_VD13IE_MASK32                       ((uint32)0x00040000U)
    #define PMC_IER_VD14IE_MASK32                       ((uint32)0x00600000U)
    #define PMC_IER_VD15IE_MASK32                       ((uint32)0x03000000U)

    /****************************************************/
    /***               (EPR_VD3)                      ***/
    /****************************************************/
    #define PMC_EPR_VD3_RWBITS_MASK32                   ((uint32)0x000000C1U)
    #define PMC_EPR_VD3_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD3_LVD3_P_MASK32                   ((uint32)0x00000080U)
    #define PMC_EPR_VD3_LVD3_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_EPR_VD3_LVD3_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD3)                      ***/
    /****************************************************/
    #define PMC_REE_VD3_RWBITS_MASK32                   ((uint32)0x000000C1U)
    #define PMC_REE_VD3_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD3_LVD3_P_MASK32                   ((uint32)0x00000080U)
    #define PMC_REE_VD3_LVD3_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_REE_VD3_LVD3_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD3)                      ***/
    /****************************************************/
    #define PMC_RES_VD3_RWBITS_MASK32                   ((uint32)0x000000C1U)
    #define PMC_RES_VD3_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD3_LVD3_P_MASK32                   ((uint32)0x00000080U)
    #define PMC_RES_VD3_LVD3_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_RES_VD3_LVD3_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD3)                      ***/
    /****************************************************/
    #define PMC_FEE_VD3_RWBITS_MASK32                   ((uint32)0x000000C1U)
    #define PMC_FEE_VD3_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD3_FEE3_P_MASK32                   ((uint32)0x00000080U)
    #define PMC_FEE_VD3_FEE3_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_FEE_VD3_FEE3_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD4)                      ***/
    /****************************************************/
    #define PMC_EPR_VD4_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_EPR_VD4_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD4_LVD4_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD4)                      ***/
    /****************************************************/
    #define PMC_REE_VD4_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_REE_VD4_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD4_LVD4_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD4)                      ***/
    /****************************************************/
    #define PMC_RES_VD4_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_RES_VD4_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD4_LVD4_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD4)                      ***/
    /****************************************************/
    #define PMC_FEE_VD4_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_FEE_VD4_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD4_FEE4_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD7)                      ***/
    /****************************************************/
    #define PMC_EPR_VD7_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_EPR_VD7_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD7_HVD7_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD7)                      ***/
    /****************************************************/
    #define PMC_REE_VD7_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_REE_VD7_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD7_HVD7_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD7)                      ***/
    /****************************************************/
    #define PMC_RES_VD7_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_RES_VD7_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD7_HVD7_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD7)                      ***/
    /****************************************************/
    #define PMC_FEE_VD7_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_FEE_VD7_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD7_FEE7_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD8)                      ***/
    /****************************************************/
    #define PMC_EPR_VD8_RWBITS_MASK32                   ((uint32)0x00000041U)
    #define PMC_EPR_VD8_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD8_HVD8_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_EPR_VD8_HVD8_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD8)                      ***/
    /****************************************************/
    #define PMC_REE_VD8_RWBITS_MASK32                   ((uint32)0x00000041U)
    #define PMC_REE_VD8_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD8_HVD8_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_REE_VD8_HVD8_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD8)                      ***/
    /****************************************************/
    #define PMC_RES_VD8_RWBITS_MASK32                   ((uint32)0x00000041U)
    #define PMC_RES_VD8_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD8_HVD8_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_RES_VD8_HVD8_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD8)                      ***/
    /****************************************************/
    #define PMC_FEE_VD8_RWBITS_MASK32                   ((uint32)0x00000041U)
    #define PMC_FEE_VD8_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD8_FEE8_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_FEE_VD8_FEE8_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD9)                      ***/
    /****************************************************/
    #define PMC_EPR_VD9_RWBITS_MASK32                   ((uint32)0x00004F49U)
    #define PMC_EPR_VD9_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD9_LVD9_O_MASK32                   ((uint32)0x00004000U)
    #define PMC_EPR_VD9_LVD9_IF2_MASK32                 ((uint32)0x00000800U)
    #define PMC_EPR_VD9_LVD9_IF_MASK32                  ((uint32)0x00000400U)
    #define PMC_EPR_VD9_LVD9_IJ_MASK32                  ((uint32)0x00000200U)
    #define PMC_EPR_VD9_LVD9_IM_MASK32                  ((uint32)0x00000100U)
    #define PMC_EPR_VD9_LVD9_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_EPR_VD9_LVD9_EBI_MASK32                 ((uint32)0x00000008U)
    #define PMC_EPR_VD9_LVD9_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD9)                      ***/
    /****************************************************/
    #define PMC_REE_VD9_RWBITS_MASK32                   ((uint32)0x00004F49U)
    #define PMC_REE_VD9_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_O_MASK32                   ((uint32)0x00004000U)
    #define PMC_REE_VD9_LVD9_IF2_MASK32                 ((uint32)0x00000800U)
    #define PMC_REE_VD9_LVD9_IF_MASK32                  ((uint32)0x00000400U)
    #define PMC_REE_VD9_LVD9_IJ_MASK32                  ((uint32)0x00000200U)
    #define PMC_REE_VD9_LVD9_IM_MASK32                  ((uint32)0x00000100U)
    #define PMC_REE_VD9_LVD9_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_REE_VD9_LVD9_EBI_MASK32                 ((uint32)0x00000008U)
    #define PMC_REE_VD9_LVD9_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD9)                      ***/
    /****************************************************/
    #define PMC_RES_VD9_RWBITS_MASK32                   ((uint32)0x00000C08U)
    #define PMC_RES_VD9_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_IF2_MASK32                 ((uint32)0x00000800U)
    #define PMC_RES_VD9_LVD9_IF_MASK32                  ((uint32)0x00000400U)
    #define PMC_RES_VD9_LVD9_EBI_MASK32                 ((uint32)0x00000008U)

    /****************************************************/
    /***               (FEE_VD9)                      ***/
    /****************************************************/
    #define PMC_FEE_VD9_RWBITS_MASK32                   ((uint32)0x00004F49U)
    #define PMC_FEE_VD9_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_O_MASK32                   ((uint32)0x00004000U)
    #define PMC_FEE_VD9_FEE9_IF2_MASK32                 ((uint32)0x00000800U)
    #define PMC_FEE_VD9_FEE9_IF_MASK32                  ((uint32)0x00000400U)
    #define PMC_FEE_VD9_FEE9_IJ_MASK32                  ((uint32)0x00000200U)
    #define PMC_FEE_VD9_FEE9_IM_MASK32                  ((uint32)0x00000100U)
    #define PMC_FEE_VD9_FEE9_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_FEE_VD9_FEE9_EBI_MASK32                 ((uint32)0x00000008U)
    #define PMC_FEE_VD9_FEE9_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD10)                     ***/
    /****************************************************/
    #define PMC_EPR_VD10_RWBITS_MASK32                  ((uint32)0x00008040U)
    #define PMC_EPR_VD10_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD10_LVD10_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_EPR_VD10_LVD10_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (REE_VD10)                      ***/
    /****************************************************/
    #define PMC_REE_VD10_RWBITS_MASK32                  ((uint32)0x00008040U)
    #define PMC_REE_VD10_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD10_LVD10_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_REE_VD10_LVD10_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (FEE_VD10)                     ***/
    /****************************************************/
    #define PMC_FEE_VD10_RWBITS_MASK32                  ((uint32)0x00008040U)
    #define PMC_FEE_VD10_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD10_FEE10_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_FEE_VD10_FEE10_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (EPR_VD12)                      ***/
    /****************************************************/
    #define PMC_EPR_VD12_RWBITS_MASK32                  ((uint32)0x00000040U)
    #define PMC_EPR_VD12_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD12_HVD12_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (REE_VD12)                     ***/
    /****************************************************/
    #define PMC_REE_VD12_RWBITS_MASK32                  ((uint32)0x00000040U)
    #define PMC_REE_VD12_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD12_HVD12_F_MASK32                 ((uint32)0x00000040U)


    /****************************************************/
    /***               (RES_VD12)                     ***/
    /****************************************************/
    #define PMC_RES_VD12_RWBITS_MASK32                  ((uint32)0x00000040U)
    #define PMC_RES_VD12_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_RES_VD12_HVD12_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (FEE_VD12)                     ***/
    /****************************************************/
    #define PMC_FEE_VD12_RWBITS_MASK32                  ((uint32)0x00000040U)
    #define PMC_FEE_VD12_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD12_FEE12_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (EPR_VD13)                     ***/
    /****************************************************/
    #define PMC_EPR_VD13_RWBITS_MASK32                  ((uint32)0x00000100U)
    #define PMC_EPR_VD13_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD13_LVD13_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (REE_VD13)                     ***/
    /****************************************************/
    #define PMC_REE_VD13_RWBITS_MASK32                  ((uint32)0x00000100U)
    #define PMC_REE_VD13_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD13_LVD13_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (RES_VD13)                     ***/
    /****************************************************/
    #define PMC_RES_VD13_RWBITS_MASK32                  ((uint32)0x00000100U)
    #define PMC_RES_VD13_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_RES_VD13_LVD13_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (FEE_VD13)                     ***/
    /****************************************************/
    #define PMC_FEE_VD13_RWBITS_MASK32                  ((uint32)0x00000100U)
    #define PMC_FEE_VD13_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD13_FEE13_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (EPR_VD14)                     ***/
    /****************************************************/
    #define PMC_EPR_VD14_RWBITS_MASK32                  ((uint32)0x00008100U)
    #define PMC_EPR_VD14_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD14_LVD14_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_EPR_VD14_LVD14_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (REE_VD14)                     ***/
    /****************************************************/
    #define PMC_REE_VD14_RWBITS_MASK32                  ((uint32)0x00008100U)
    #define PMC_REE_VD14_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD14_LVD14_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_REE_VD14_LVD14_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (RES_VD14)                     ***/
    /****************************************************/
    #define PMC_RES_VD14_RWBITS_MASK32                  ((uint32)0x00008100U)
    #define PMC_RES_VD14_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_RES_VD14_LVD14_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_RES_VD14_LVD14_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (FEE_VD14)                     ***/
    /****************************************************/
    #define PMC_FEE_VD14_RWBITS_MASK32                  ((uint32)0x00008100U)
    #define PMC_FEE_VD14_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD14_FEE14_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_FEE_VD14_FEE14_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (EPR_VD15)                      ***/
    /****************************************************/
    #define PMC_EPR_VD15_RWBITS_MASK32                  ((uint32)0x00008001U)
    #define PMC_EPR_VD15_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD15_HVD15_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_EPR_VD15_HVD15_C_MASK32                 ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD15)                     ***/
    /****************************************************/
    #define PMC_REE_VD15_RWBITS_MASK32                  ((uint32)0x00008001U)
    #define PMC_REE_VD15_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD15_HVD15_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_REE_VD15_HVD15_C_MASK32                 ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD15)                     ***/
    /****************************************************/
    #define PMC_RES_VD15_RWBITS_MASK32                  ((uint32)0x00008001U)
    #define PMC_RES_VD15_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_RES_VD15_HVD15_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_RES_VD15_HVD15_C_MASK32                 ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD15)                     ***/
    /****************************************************/
    #define PMC_FEE_VD15_RWBITS_MASK32                  ((uint32)0x00008001U)
    #define PMC_FEE_VD15_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD15_FEE15_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_FEE_VD15_FEE15_C_MASK32                 ((uint32)0x00000001U)

    /****************************************************/
    /***               (VSIO)                         ***/
    /****************************************************/
    #define PMC_VSIO_RWBITS_MASK32                      ((uint32)0x00000F00U)
    #define PMC_VSIO_RESBITS_MASK32                     ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IF2_MASK32                    ((uint32)0x00000800U)
    #define PMC_VSIO_VSIO_IF_MASK32                     ((uint32)0x00000400U)
    #define PMC_VSIO_VSIO_IJ_MASK32                     ((uint32)0x00000200U)
    #define PMC_VSIO_VSIO_IM_MASK32                     ((uint32)0x00000100U)

    /****************************************************/
    /***               (EPR_TD)                       ***/
    /****************************************************/
    #define PMC_EPR_TD_RWBITS_MASK32                    ((uint32)0x0000000DU)
    #define PMC_EPR_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_EPR_TD_TEMP_3_MASK32                    ((uint32)0x00000008U)
    #define PMC_EPR_TD_TEMP_2_MASK32                    ((uint32)0x00000004U)
    #define PMC_EPR_TD_TEMP_0_MASK32                    ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_TD)                       ***/
    /****************************************************/
    #define PMC_REE_TD_RWBITS_MASK32                    ((uint32)0x0000000DU)
    #define PMC_REE_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP_3_MASK32                    ((uint32)0x00000008U)
    #define PMC_REE_TD_TEMP_2_MASK32                    ((uint32)0x00000004U)
    #define PMC_REE_TD_TEMP_0_MASK32                    ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_TD)                       ***/
    /****************************************************/
    #define PMC_RES_TD_RWBITS_MASK32                    ((uint32)0x000000DU)
    #define PMC_RES_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP_3_MASK32                    ((uint32)0x00000008U)
    #define PMC_RES_TD_TEMP_2_MASK32                    ((uint32)0x00000004U)
    #define PMC_RES_TD_TEMP_0_MASK32                    ((uint32)0x00000001U)

    /****************************************************/
    /***               (CTL_TD)                       ***/
    /****************************************************/
    #define PMC_CTL_TD_RWBITS_MASK32                    ((uint32)0x0000EF3FU)
    #define PMC_CTL_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_CTL_TD_IE_RWBITS_MASK32                 ((uint32)0x0000E000U)
    #define PMC_CTL_TD_TS3IE_MASK32                     ((uint32)0x00008000U)
    #define PMC_CTL_TD_TS2IE_MASK32                     ((uint32)0x00004000U)
    #define PMC_CTL_TD_TS0IE_MASK32                     ((uint32)0x00002000U)
    #define PMC_CTL_TD_DOUT_MASK32                      ((uint32)0x00000002U)
    #define PMC_CTL_TD_AOUT_MASK32                      ((uint32)0x00000001U)
    #define PMC_CTL_TD_TRIM_ADJ_OVER_MASK32             ((uint32)0x00000F00U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_CTL_TD_TRIM_ADJ_UNDER_MASK32            ((uint32)0x0000003CU)

    /****************************************************/
    /***               (FEE_TD)                       ***/
    /****************************************************/
    #define PMC_FEE_TD_RWBITS_MASK32                    ((uint32)0x0000000DU)
    #define PMC_FEE_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_FEE_TD_FEE_TS3_MASK32                   ((uint32)0x00000008U)
    #define PMC_FEE_TD_FEE_TS2_MASK32                   ((uint32)0x00000004U)
    #define PMC_FEE_TD_FEE_TS0_MASK32                   ((uint32)0x00000001U)

#elif (IPV_MC == IPV_MC_04_01_00_00)
    /* Supply Gauge Status Register (GR_S) */
    #define PMC_GR_S_ADDR32                             ((uint32)(PMC_BASEADDR + (uint32)0x0000U))
    /* Pending Gauge Status Register (GR_P) */
    #define PMC_GR_P_ADDR32                             ((uint32)(PMC_BASEADDR + (uint32)0x0004U))
    /* Interrupt Enable Pending Register (IE_P) */
    #define PMC_IER_ADDR32                              ((uint32)(PMC_BASEADDR + (uint32)0x0008U))
    /* LVD280 Event Pending register VD3 (EPR_VD3) */
    #define PMC_EPR_VD3_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0030U))
    /* Reset Event Enable VD3 (REE_VD3) */
    #define PMC_REE_VD3_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0034U))
    /* Reset Event Selection VD3 (RES_VD3) */
    #define PMC_RES_VD3_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0038U))
    /* FCCU Event Enable VD3 (FEE_VD3) */
    #define PMC_FEE_VD3_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x003CU))
    /* LVD280 Event Pending register VD4 (EPR_VD4) */
    #define PMC_EPR_VD4_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0040U))
    /* Reset Event Enable VD3 (REE_VD4) */
    #define PMC_REE_VD4_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0044U))
    /* Reset Event Selection VD3 (RES_VD4) */
    #define PMC_RES_VD4_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0048U))
    /* FCCU Event Enable VD3 (FEE_VD4) */
    #define PMC_FEE_VD4_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x004CU))
    /* LVD280 Event Pending register VD7 (EPR_VD7) */
    #define PMC_EPR_VD7_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0070U))
    /* Reset Event Enable VD3 (REE_VD7) */
    #define PMC_REE_VD7_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0074U))
    /* Reset Event Selection VD3 (RES_VD7) */
    #define PMC_RES_VD7_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0078U))
    /* FCCU Event Enable VD3 (FEE_VD7) */
    #define PMC_FEE_VD7_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x007CU))
    /* LVD280 Event Pending register VD8 (EPR_VD8) */
    #define PMC_EPR_VD8_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0080U))
    /* Reset Event Enable VD3 (REE_VD8) */
    #define PMC_REE_VD8_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0084U))
    /* Reset Event Selection VD3 (RES_VD8) */
    #define PMC_RES_VD8_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0088U))
    /* FCCU Event Enable VD3 (FEE_VD8) */
    #define PMC_FEE_VD8_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x008CU))
    /* LVD280 Event Pending register VD9 (EPR_VD9) */
    #define PMC_EPR_VD9_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0090U))
    /* Reset Event Enable VD9 (REE_VD9) */
    #define PMC_REE_VD9_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0094U))
    /* Reset Event Selection VD9 (RES_VD9) */
    #define PMC_RES_VD9_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x0098U))
    /* FCCU Event Enable VD3 (FEE_VD9) */
    #define PMC_FEE_VD9_ADDR32                          ((uint32)(PMC_BASEADDR + (uint32)0x009CU))
    /* LVD280 Event Pending register VD10 (EPR_VD10) */
    #define PMC_EPR_VD10_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00A0U))
    /* Reset Event Enable VD10 (REE_VD10) */
    #define PMC_REE_VD10_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00A4U))
    /* FCCU Event Enable VD10 (FEE_VD10) */
    #define PMC_FEE_VD10_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00ACU))
    /* LVD280 Event Pending register VD12 (EPR_VD12) */
    #define PMC_EPR_VD12_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00C0U))
    /* Reset Event Enable VD12 (REE_VD12) */
    #define PMC_REE_VD12_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00C4U))
    /* Reset Event Selection VD12 (RES_VD12) */
    #define PMC_RES_VD12_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00C8U))
    /* FCCU Event Enable VD12 (FEE_VD12) */
    #define PMC_FEE_VD12_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00CCU))
    /* LVD280 Event Pending register VD13 (EPR_VD13) */
    #define PMC_EPR_VD13_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00D0U))
    /* Reset Event Enable VD13 (REE_VD13) */
    #define PMC_REE_VD13_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00D4U))
    /* Reset Event Selection VD13 (RES_VD13) */
    #define PMC_RES_VD13_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00D8U))
    /* FCCU Event Enable VD13 (FEE_VD13) */
    #define PMC_FEE_VD13_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00DCU))
    /* LVD280 Event Pending register VD14 (EPR_VD14) */
    #define PMC_EPR_VD14_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00E0U))
    /* Reset Event Enable VD14 (REE_VD14) */
    #define PMC_REE_VD14_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00E4U))
    /* Reset Event Selection VD14 (RES_VD14) */
    #define PMC_RES_VD14_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00E8U))
    /* FCCU Event Enable VD14 (FEE_VD14) */
    #define PMC_FEE_VD14_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00ECU))
    /* LVD280 Event Pending register VD15 (EPR_VD15) */
    #define PMC_EPR_VD15_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00F0U))
    /* Reset Event Enable VD15 (REE_VD15) */
    #define PMC_REE_VD15_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00F4U))
    /* Reset Event Selection VD15 (RES_VD15) */
    #define PMC_RES_VD15_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00F8U))
    /* FCCU Event Enable VD15 (FEE_VD15) */
    #define PMC_FEE_VD15_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00FCU))
    /* Voltage Supply for I/O Segments Register (VSIO) */
    #define PMC_VSIO_ADDR32                             ((uint32)(PMC_BASEADDR + (uint32)0x0104U))
    /* Temperature Event Pending register (EPR_TD) */
    #define PMC_EPR_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0300U))
    /* Temperature Reset Event Enable register (REE_TD) */
    #define PMC_REE_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0304U))
    /* Temperature Reset Event Selection register (RES_TD) */
    #define PMC_RES_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0308U))
    /* Temperature detector configuration register (CTL_TD) */
    #define PMC_CTL_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x030CU))
    /* Temperature FCCU Event Enable register (FEE_TD) */
    #define PMC_FEE_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x0318U))


    /****************************************************/
    /***               (GR_S)                         ***/
    /****************************************************/
    #define PMC_GR_S_RWBITS_MASK32                      ((uint32)0x00000000U)
    #define PMC_GR_S_RESBITS_MASK32                     ((uint32)0x00000000U)
    #define PMC_GR_S_VD15_MASK32                        ((uint32)0x00008000U)
    #define PMC_GR_S_VD14_MASK32                        ((uint32)0x00004000U)
    #define PMC_GR_S_VD13_MASK32                        ((uint32)0x00002000U)
    #define PMC_GR_S_VD12_MASK32                        ((uint32)0x00001000U)
    #define PMC_GR_S_VD10_MASK32                        ((uint32)0x00000400U)
    #define PMC_GR_S_VD9_MASK32                         ((uint32)0x00000200U)
    #define PMC_GR_S_VD8_MASK32                         ((uint32)0x00000100U)
    #define PMC_GR_S_VD7_MASK32                         ((uint32)0x00000080U)
    #define PMC_GR_S_VD4_MASK32                         ((uint32)0x00000010U)
    #define PMC_GR_S_VD3_MASK32                         ((uint32)0x00000008U)

    /****************************************************/
    /***               (GR_P)                         ***/
    /****************************************************/
    #define PMC_GR_P_RWBITS_MASK32                      ((uint32)0x00000000U)
    #define PMC_GR_P_RESBITS_MASK32                     ((uint32)0x00000000U)
    #define PMC_GR_P_VD15_A_MASK32                      ((uint32)0x02000000U)
    #define PMC_GR_P_VD15_C_MASK32                      ((uint32)0x01000000U)
    #define PMC_GR_P_VD14_A_MASK32                      ((uint32)0x00400000U)
    #define PMC_GR_P_VD14_IM_MASK32                     ((uint32)0x00200000U)
    #define PMC_GR_P_VD13_IM_MASK32                     ((uint32)0x00040000U)
    #define PMC_GR_P_VD12_F_MASK32                      ((uint32)0x00020000U)
    #define PMC_GR_P_VD10_A_MASK32                      ((uint32)0x00010000U)
    #define PMC_GR_P_VD10_F_MASK32                      ((uint32)0x00008000U)
    #define PMC_GR_P_VD9_O_MASK32                       ((uint32)0x00004000U)
    #define PMC_GR_P_VD9_IF_MASK32                      ((uint32)0x00001000U)
    #define PMC_GR_P_VD9_IJ_MASK32                      ((uint32)0x00000800U)
    #define PMC_GR_P_VD9_IM_MASK32                      ((uint32)0x00000400U)
    #define PMC_GR_P_VD9_F_MASK32                       ((uint32)0x00000200U)
    #define PMC_GR_P_VD9_C_MASK32                       ((uint32)0x00000080U)
    #define PMC_GR_P_VD8_C_MASK32                       ((uint32)0x00000040U)
    #define PMC_GR_P_VD8_F_MASK32                       ((uint32)0x00000020U)
    #define PMC_GR_P_VD7_C_MASK32                       ((uint32)0x00000010U)
    #define PMC_GR_P_VD4_C_MASK32                       ((uint32)0x00000008U)
    #define PMC_GR_P_VD3_P_MASK32                       ((uint32)0x00000004U)
    #define PMC_GR_P_VD3_F_MASK32                       ((uint32)0x00000002U)
    #define PMC_GR_P_VD3_C_MASK32                       ((uint32)0x00000001U)

    /****************************************************/
    /***               (IE_P)                         ***/
    /****************************************************/
    #define PMC_IER_RWBITS_MASK32                       ((uint32)0x8367DEFFU)
    #define PMC_IER_RESBITS_MASK32                      ((uint32)0x00000000U)
    #define PMC_IER_IE_EN_MASK32                        ((uint32)0x80000000U)
    #define PMC_IER_VD15IE_A_MASK32                     ((uint32)0x02000000U)
    #define PMC_IER_VD15IE_C_MASK32                     ((uint32)0x01000000U)
    #define PMC_IER_VD14IE_A_MASK32                     ((uint32)0x00400000U)
    #define PMC_IER_VD14IE_IM_MASK32                    ((uint32)0x00200000U)
    #define PMC_IER_VD13IE_IM_MASK32                    ((uint32)0x00040000U)
    #define PMC_IER_VD12IE_F_MASK32                     ((uint32)0x00020000U)
    #define PMC_IER_VD10IE_A_MASK32                     ((uint32)0x00010000U)
    #define PMC_IER_VD10IE_F_MASK32                     ((uint32)0x00008000U)
    #define PMC_IER_VD9IE_O_MASK32                      ((uint32)0x00004000U)
    #define PMC_IER_VD9IE_IF_MASK32                     ((uint32)0x00001000U)
    #define PMC_IER_VD9IE_IJ_MASK32                     ((uint32)0x00000800U)
    #define PMC_IER_VD9IE_IM_MASK32                     ((uint32)0x00000400U)
    #define PMC_IER_VD9IE_F_MASK32                      ((uint32)0x00000200U)
    #define PMC_IER_VD9IE_C_MASK32                      ((uint32)0x00000080U)
    #define PMC_IER_VD8IE_C_MASK32                      ((uint32)0x00000040U)
    #define PMC_IER_VD8IE_F_MASK32                      ((uint32)0x00000020U)
    #define PMC_IER_VD7IE_C_MASK32                      ((uint32)0x00000010U)
    #define PMC_IER_VD4IE_C_MASK32                      ((uint32)0x00000008U)
    #define PMC_IER_VD3IE_P_MASK32                      ((uint32)0x00000004U)
    #define PMC_IER_VD3IE_F_MASK32                      ((uint32)0x00000002U)
    #define PMC_IER_VD3IE_C_MASK32                      ((uint32)0x00000001U)

    #define PMC_IER_VD3IE_MASK32                        ((uint32)0x00000007U)
    #define PMC_IER_VD4IE_MASK32                        ((uint32)0x00000008U)
    #define PMC_IER_VD7IE_MASK32                        ((uint32)0x00000010U)
    #define PMC_IER_VD8IE_MASK32                        ((uint32)0x00000060U)
    #define PMC_IER_VD9IE_MASK32                        ((uint32)0x00005E80U)
    #define PMC_IER_VD10IE_MASK32                       ((uint32)0x00018000U)
    #define PMC_IER_VD12IE_MASK32                       ((uint32)0x00020000U)
    #define PMC_IER_VD13IE_MASK32                       ((uint32)0x00040000U)
    #define PMC_IER_VD14IE_MASK32                       ((uint32)0x00600000U)
    #define PMC_IER_VD15IE_MASK32                       ((uint32)0x03000000U)

    /****************************************************/
    /***               (EPR_VD3)                      ***/
    /****************************************************/
    #define PMC_EPR_VD3_RWBITS_MASK32                   ((uint32)0x000000C1U)
    #define PMC_EPR_VD3_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD3_LVD3_P_MASK32                   ((uint32)0x00000080U)
    #define PMC_EPR_VD3_LVD3_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_EPR_VD3_LVD3_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD3)                      ***/
    /****************************************************/
    #define PMC_REE_VD3_RWBITS_MASK32                   ((uint32)0x000000C1U)
    #define PMC_REE_VD3_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD3_LVD3_P_MASK32                   ((uint32)0x00000080U)
    #define PMC_REE_VD3_LVD3_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_REE_VD3_LVD3_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD3)                      ***/
    /****************************************************/
    #define PMC_RES_VD3_RWBITS_MASK32                   ((uint32)0x000000C1U)
    #define PMC_RES_VD3_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD3_LVD3_P_MASK32                   ((uint32)0x00000080U)
    #define PMC_RES_VD3_LVD3_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_RES_VD3_LVD3_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD3)                      ***/
    /****************************************************/
    #define PMC_FEE_VD3_RWBITS_MASK32                   ((uint32)0x000000C1U)
    #define PMC_FEE_VD3_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD3_FEE3_P_MASK32                   ((uint32)0x00000080U)
    #define PMC_FEE_VD3_FEE3_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_FEE_VD3_FEE3_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD4)                      ***/
    /****************************************************/
    #define PMC_EPR_VD4_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_EPR_VD4_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD4_LVD4_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD4)                      ***/
    /****************************************************/
    #define PMC_REE_VD4_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_REE_VD4_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD4_LVD4_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD4)                      ***/
    /****************************************************/
    #define PMC_RES_VD4_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_RES_VD4_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD4_LVD4_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD4)                      ***/
    /****************************************************/
    #define PMC_FEE_VD4_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_FEE_VD4_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD4_FEE4_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD7)                      ***/
    /****************************************************/
    #define PMC_EPR_VD7_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_EPR_VD7_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD7_HVD7_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD7)                      ***/
    /****************************************************/
    #define PMC_REE_VD7_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_REE_VD7_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD7_HVD7_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD7)                      ***/
    /****************************************************/
    #define PMC_RES_VD7_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_RES_VD7_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD7_HVD7_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD7)                      ***/
    /****************************************************/
    #define PMC_FEE_VD7_RWBITS_MASK32                   ((uint32)0x00000001U)
    #define PMC_FEE_VD7_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD7_FEE7_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD8)                      ***/
    /****************************************************/
    #define PMC_EPR_VD8_RWBITS_MASK32                   ((uint32)0x00000041U)
    #define PMC_EPR_VD8_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD8_HVD8_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_EPR_VD8_HVD8_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD8)                      ***/
    /****************************************************/
    #define PMC_REE_VD8_RWBITS_MASK32                   ((uint32)0x00000041U)
    #define PMC_REE_VD8_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD8_HVD8_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_REE_VD8_HVD8_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD8)                      ***/
    /****************************************************/
    #define PMC_RES_VD8_RWBITS_MASK32                   ((uint32)0x00000041U)
    #define PMC_RES_VD8_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD8_HVD8_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_RES_VD8_HVD8_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD8)                      ***/
    /****************************************************/
    #define PMC_FEE_VD8_RWBITS_MASK32                   ((uint32)0x00000041U)
    #define PMC_FEE_VD8_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD8_FEE8_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_FEE_VD8_FEE8_C_MASK32                   ((uint32)0x00000001U)


    /****************************************************/
    /***               (EPR_VD9)                      ***/
    /****************************************************/
    #define PMC_EPR_VD9_RWBITS_MASK32                   ((uint32)0x00004741U)
    #define PMC_EPR_VD9_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_EPR_VD9_LVD9_O_MASK32                   ((uint32)0x00004000U)
    #define PMC_EPR_VD9_LVD9_IF_MASK32                  ((uint32)0x00000400U)
    #define PMC_EPR_VD9_LVD9_IJ_MASK32                  ((uint32)0x00000200U)
    #define PMC_EPR_VD9_LVD9_IM_MASK32                  ((uint32)0x00000100U)
    #define PMC_EPR_VD9_LVD9_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_EPR_VD9_LVD9_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD9)                      ***/
    /****************************************************/
    #define PMC_REE_VD9_RWBITS_MASK32                   ((uint32)0x00004741U)
    #define PMC_REE_VD9_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_O_MASK32                   ((uint32)0x00004000U)
    #define PMC_REE_VD9_LVD9_IF_MASK32                  ((uint32)0x00000400U)
    #define PMC_REE_VD9_LVD9_IJ_MASK32                  ((uint32)0x00000200U)
    #define PMC_REE_VD9_LVD9_IM_MASK32                  ((uint32)0x00000100U)
    #define PMC_REE_VD9_LVD9_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_REE_VD9_LVD9_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD9)                      ***/
    /****************************************************/
    #define PMC_RES_VD9_RWBITS_MASK32                   ((uint32)0x00000400U)
    #define PMC_RES_VD9_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_IF_MASK32                  ((uint32)0x00000400U)

    /****************************************************/
    /***               (FEE_VD9)                      ***/
    /****************************************************/
    #define PMC_FEE_VD9_RWBITS_MASK32                   ((uint32)0x00004741U)
    #define PMC_FEE_VD9_RESBITS_MASK32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_O_MASK32                   ((uint32)0x00004000U)
    #define PMC_FEE_VD9_FEE9_IF_MASK32                  ((uint32)0x00000400U)
    #define PMC_FEE_VD9_FEE9_IJ_MASK32                  ((uint32)0x00000200U)
    #define PMC_FEE_VD9_FEE9_IM_MASK32                  ((uint32)0x00000100U)
    #define PMC_FEE_VD9_FEE9_F_MASK32                   ((uint32)0x00000040U)
    #define PMC_FEE_VD9_FEE9_C_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***               (EPR_VD10)                     ***/
    /****************************************************/
    #define PMC_EPR_VD10_RWBITS_MASK32                  ((uint32)0x00008040U)
    #define PMC_EPR_VD10_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD10_LVD10_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_EPR_VD10_LVD10_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (REE_VD10)                      ***/
    /****************************************************/
    #define PMC_REE_VD10_RWBITS_MASK32                  ((uint32)0x00008040U)
    #define PMC_REE_VD10_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD10_LVD10_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_REE_VD10_LVD10_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (FEE_VD10)                     ***/
    /****************************************************/
    #define PMC_FEE_VD10_RWBITS_MASK32                  ((uint32)0x00008040U)
    #define PMC_FEE_VD10_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD10_FEE10_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_FEE_VD10_FEE10_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (EPR_VD12)                      ***/
    /****************************************************/
    #define PMC_EPR_VD12_RWBITS_MASK32                  ((uint32)0x00000040U)
    #define PMC_EPR_VD12_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD12_HVD12_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (REE_VD12)                     ***/
    /****************************************************/
    #define PMC_REE_VD12_RWBITS_MASK32                  ((uint32)0x00000040U)
    #define PMC_REE_VD12_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD12_HVD12_F_MASK32                 ((uint32)0x00000040U)


    /****************************************************/
    /***               (RES_VD12)                     ***/
    /****************************************************/
    #define PMC_RES_VD12_RWBITS_MASK32                  ((uint32)0x00000040U)
    #define PMC_RES_VD12_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_RES_VD12_HVD12_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (FEE_VD12)                     ***/
    /****************************************************/
    #define PMC_FEE_VD12_RWBITS_MASK32                  ((uint32)0x00000040U)
    #define PMC_FEE_VD12_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD12_FEE12_F_MASK32                 ((uint32)0x00000040U)

    /****************************************************/
    /***               (EPR_VD13)                     ***/
    /****************************************************/
    #define PMC_EPR_VD13_RWBITS_MASK32                  ((uint32)0x00000100U)
    #define PMC_EPR_VD13_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD13_LVD13_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (REE_VD13)                     ***/
    /****************************************************/
    #define PMC_REE_VD13_RWBITS_MASK32                  ((uint32)0x00000100U)
    #define PMC_REE_VD13_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD13_LVD13_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (RES_VD13)                     ***/
    /****************************************************/
    #define PMC_RES_VD13_RWBITS_MASK32                  ((uint32)0x00000100U)
    #define PMC_RES_VD13_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_RES_VD13_LVD13_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (FEE_VD13)                     ***/
    /****************************************************/
    #define PMC_FEE_VD13_RWBITS_MASK32                  ((uint32)0x00000100U)
    #define PMC_FEE_VD13_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD13_FEE13_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (EPR_VD14)                     ***/
    /****************************************************/
    #define PMC_EPR_VD14_RWBITS_MASK32                  ((uint32)0x00008100U)
    #define PMC_EPR_VD14_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD14_LVD14_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_EPR_VD14_LVD14_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (REE_VD14)                     ***/
    /****************************************************/
    #define PMC_REE_VD14_RWBITS_MASK32                  ((uint32)0x00008100U)
    #define PMC_REE_VD14_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD14_LVD14_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_REE_VD14_LVD14_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (RES_VD14)                     ***/
    /****************************************************/
    #define PMC_RES_VD14_RWBITS_MASK32                  ((uint32)0x00008100U)
    #define PMC_RES_VD14_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_RES_VD14_LVD14_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_RES_VD14_LVD14_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (FEE_VD14)                     ***/
    /****************************************************/
    #define PMC_FEE_VD14_RWBITS_MASK32                  ((uint32)0x00008100U)
    #define PMC_FEE_VD14_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD14_FEE14_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_FEE_VD14_FEE14_IM_MASK32                ((uint32)0x00000100U)

    /****************************************************/
    /***               (EPR_VD15)                      ***/
    /****************************************************/
    #define PMC_EPR_VD15_RWBITS_MASK32                  ((uint32)0x00008001U)
    #define PMC_EPR_VD15_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_EPR_VD15_HVD15_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_EPR_VD15_HVD15_C_MASK32                 ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_VD15)                     ***/
    /****************************************************/
    #define PMC_REE_VD15_RWBITS_MASK32                  ((uint32)0x00008001U)
    #define PMC_REE_VD15_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_REE_VD15_HVD15_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_REE_VD15_HVD15_C_MASK32                 ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_VD15)                     ***/
    /****************************************************/
    #define PMC_RES_VD15_RWBITS_MASK32                  ((uint32)0x00008001U)
    #define PMC_RES_VD15_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_RES_VD15_HVD15_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_RES_VD15_HVD15_C_MASK32                 ((uint32)0x00000001U)

    /****************************************************/
    /***               (FEE_VD15)                     ***/
    /****************************************************/
    #define PMC_FEE_VD15_RWBITS_MASK32                  ((uint32)0x00008001U)
    #define PMC_FEE_VD15_RESBITS_MASK32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD15_FEE15_A_MASK32                 ((uint32)0x00008000U)
    #define PMC_FEE_VD15_FEE15_C_MASK32                 ((uint32)0x00000001U)

    /****************************************************/
    /***               (VSIO)                         ***/
    /****************************************************/
    #define PMC_VSIO_RWBITS_MASK32                      ((uint32)0x00000700U)
    #define PMC_VSIO_RESBITS_MASK32                     ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IF_MASK32                     ((uint32)0x00000400U)
    #define PMC_VSIO_VSIO_IJ_MASK32                     ((uint32)0x00000200U)
    #define PMC_VSIO_VSIO_IM_MASK32                     ((uint32)0x00000100U)



    /****************************************************/
    /***               (EPR_TD)                       ***/
    /****************************************************/
    #define PMC_EPR_TD_RWBITS_MASK32                    ((uint32)0x0000000DU)
    #define PMC_EPR_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_EPR_TD_TEMP_3_MASK32                    ((uint32)0x00000008U)
    #define PMC_EPR_TD_TEMP_2_MASK32                    ((uint32)0x00000004U)
    #define PMC_EPR_TD_TEMP_0_MASK32                    ((uint32)0x00000001U)

    /****************************************************/
    /***               (REE_TD)                       ***/
    /****************************************************/
    #define PMC_REE_TD_RWBITS_MASK32                    ((uint32)0x0000000DU)
    #define PMC_REE_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP_3_MASK32                    ((uint32)0x00000008U)
    #define PMC_REE_TD_TEMP_2_MASK32                    ((uint32)0x00000004U)
    #define PMC_REE_TD_TEMP_0_MASK32                    ((uint32)0x00000001U)

    /****************************************************/
    /***               (RES_TD)                       ***/
    /****************************************************/
    #define PMC_RES_TD_RWBITS_MASK32                    ((uint32)0x0000000DU)
    #define PMC_RES_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP_3_MASK32                    ((uint32)0x00000008U)
    #define PMC_RES_TD_TEMP_2_MASK32                    ((uint32)0x00000004U)
    #define PMC_RES_TD_TEMP_0_MASK32                    ((uint32)0x00000001U)

    /****************************************************/
    /***               (CTL_TD)                       ***/
    /****************************************************/
    #define PMC_CTL_TD_RWBITS_MASK32                    ((uint32)0x0000EF3FU)
    #define PMC_CTL_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_CTL_TD_IE_RWBITS_MASK32                 ((uint32)0x0000E000U)
    #define PMC_CTL_TD_TS3IE_MASK32                     ((uint32)0x00008000U)
    #define PMC_CTL_TD_TS2IE_MASK32                     ((uint32)0x00004000U)
    #define PMC_CTL_TD_TS0IE_MASK32                     ((uint32)0x00002000U)
    #define PMC_CTL_TD_DOUT_MASK32                      ((uint32)0x00000002U)
    #define PMC_CTL_TD_AOUT_MASK32                      ((uint32)0x00000001U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_CTL_TD_TRIM_ADJ_OVER_MASK32             ((uint32)0x00000F00U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_CTL_TD_TRIM_ADJ_UNDER_MASK32            ((uint32)0x0000003CU)

    /****************************************************/
    /***               (FEE_TD)                       ***/
    /****************************************************/
    #define PMC_FEE_TD_RWBITS_MASK32                    ((uint32)0x0000000DU)
    #define PMC_FEE_TD_RESBITS_MASK32                   ((uint32)0x00000000U)
    #define PMC_FEE_TD_FEE_TS3_MASK32                   ((uint32)0x00000008U)
    #define PMC_FEE_TD_FEE_TS2_MASK32                   ((uint32)0x00000004U)
    #define PMC_FEE_TD_FEE_TS0_MASK32                   ((uint32)0x00000001U)

#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* PMC - Temperature Sensor Interrupt Enable Register (PMC_TS_IER). */
    #define PMC_TS_IER_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00A4U))
    /* PMC - Temperature Event Status register (PMC_ESR_TD) */
    #define PMC_ESR_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00A8U))
    /* PMC - Temperature Reset Event Enable register (PMC_REE_TD). */
    #define PMC_REE_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00ACU))
    /* PMC - Temperature Reset Event Selection register (PMC_RES_TD). */
    #define PMC_RES_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00B0U))
    /* PMC - Temperature detector configuration register (PMC_CTL_TD). */
    #define PMC_CTL_TD_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00B4U))
    /* PMC - Temperature Fault Injection Register (PMC_TS_FIR). */
    #define PMC_TS_FIR_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00C0U))
    /* PMC - Temp Sensor Test Control Register (PMC_TS_TMC). */
    #define PMC_TS_TMC_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00C4U))
    /* PMC - LVD Self Test Time Window Register (PMC_LVD_STTW). */
    #define PMC_LVD_STTW_ADDR32                         ((uint32)(PMC_BASEADDR + (uint32)0x00CCU))
    /* PMC - Voltage Detect User Mode Test Register (PMC_SELF_TEST_UM_VD_REG). */
    #define PMC_SELF_TEST_UM_VD_REG_ADDR32              ((uint32)(PMC_BASEADDR + (uint32)0x00D0U))
    /* PMC - FCCU Fault Injection Register (PMC_FIR) */
    #define PMC_FIR_ADDR32                              ((uint32)(PMC_BASEADDR + (uint32)0x00D4U))
    /* PMC - LVD HVD Interrupt Enable Control Register (PMC_LVD_HVD_INTR_ENB) */
    #define PMC_LVD_HVD_INTR_ENB_ADDR32                 ((uint32)(PMC_BASEADDR + (uint32)0x00D8U))
    /* PMC - LVD HVD Event Status Register (PMC_LVD_HVD_EVENT_STATUS). */
    #define PMC_LVD_HVD_EVENT_STATUS_ADDR32             ((uint32)(PMC_BASEADDR + (uint32)0x00DCU))
    /* PMC - Reset Enable Control Register (PMC_REE). */
    #define PMC_REE_ADDR32                              ((uint32)(PMC_BASEADDR + (uint32)0x00E0U))
    /* PMC - Reset Type ( Destructive / Functional) Selection Register (PMC_RES). */
    #define PMC_RES_ADDR32                              ((uint32)(PMC_BASEADDR + (uint32)0x00E4U))
    /* PMC - ADC Channel Select Register (PMC_ADC_CS). */
    #define PMC_ADC_CS_ADDR32                           ((uint32)(PMC_BASEADDR + (uint32)0x00E8U))


    /****************************************************/
    /***              PMC_TS_IER                      ***/
    /****************************************************/
    #define PMC_TS_IER_RWBITS_MASK32                    ((uint32)0x8000001BU)
    #define PMC_TS_IER_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_TS_IER_TS_EN_MASK32                     ((uint32)0x80000000U)
    #define PMC_TS_IER_TS1_2IE_MASK32                   ((uint32)0x00000010U)
    #define PMC_TS_IER_TS1_0IE_MASK32                   ((uint32)0x00000008U)
    #define PMC_TS_IER_TS0_2IE_MASK32                   ((uint32)0x00000002U)
    #define PMC_TS_IER_TS0_0IE_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***              PMC_ESR_TD                      ***/
    /****************************************************/
    #define PMC_ESR_TD_RWBITS_MASK32                    ((uint32)0x0000001BU)
    #define PMC_ESR_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_ESR_TD_TEMP1_2_MASK32                   ((uint32)0x00000010U)
    #define PMC_ESR_TD_TEMP1_0_MASK32                   ((uint32)0x00000008U)
    #define PMC_ESR_TD_TEMP0_2_MASK32                   ((uint32)0x00000002U)
    #define PMC_ESR_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***              PMC_REE_TD                      ***/
    /****************************************************/
    #define PMC_REE_TD_RWBITS_MASK32                    ((uint32)0x0000001BU)
    #define PMC_REE_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_REE_TD_TEMP1_2_MASK32                   ((uint32)0x00000010U)
    #define PMC_REE_TD_TEMP1_0_MASK32                   ((uint32)0x00000008U)
    #define PMC_REE_TD_TEMP0_2_MASK32                   ((uint32)0x00000002U)
    #define PMC_REE_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***              PMC_RES_TD                      ***/
    /****************************************************/
    #define PMC_RES_TD_RWBITS_MASK32                    ((uint32)0x0000001BU)
    #define PMC_RES_TD_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_RES_TD_TEMP1_2_MASK32                   ((uint32)0x00000010U)
    #define PMC_RES_TD_TEMP1_0_MASK32                   ((uint32)0x00000008U)
    #define PMC_RES_TD_TEMP0_2_MASK32                   ((uint32)0x00000002U)
    #define PMC_RES_TD_TEMP0_0_MASK32                   ((uint32)0x00000001U)

    /****************************************************/
    /***              PMC_CTL_TD                      ***/
    /****************************************************/
    #define PMC_CTL_TD_RWBITS_MASK32                    ((uint32)0x00000202U)
    #define PMC_CTL_TD_RESBITS_MASK32                   ((uint32)0x00000101U)

    #define PMC_CTL_TD_TS1_DOUT_EN_MASK32               ((uint32)0x00000200U)
    #define PMC_CTL_TD_TS0_DOUT_EN_MASK32               ((uint32)0x00000002U)

    /****************************************************/
    /***              PMC_TS_FIR                      ***/
    /****************************************************/
    #define PMC_TS_FIR_RWBITS_MASK32                    ((uint32)0x00000001U)

    /****************************************************/
    /***              PMC_TS_TMC                      ***/
    /****************************************************/
    #define PMC_TS_TMC_RWBITS_MASK32                    ((uint32)0x00000088U)
    #define PMC_TS_TMC_RESBITS_MASK32                   ((uint32)0x00000000U)

    #define PMC_TS_TMC_TS1_SELTSH_MASK32                ((uint32)0x00000080U)
    #define PMC_TS_TMC_TS0_SELTSH_MASK32                ((uint32)0x00000008U)

    /****************************************************/
    /***              PMC_LVD_STTW                    ***/
    /****************************************************/
    #define PMC_LVD_STTW_RWBITS_MASK32                  ((uint32)0x00000FFFU)
    #define PMC_LVD_STTW_RESBITS_MASK32                 ((uint32)0x00000000U)

    /****************************************************/
    /***         PMC_SELF_TEST_UM_VD_REG              ***/
    /****************************************************/
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_SELF_TEST_UM_VD_REG_RWBITS_MASK32       ((uint32)0x000200FFU)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_SELF_TEST_UM_VD_REG_RESBITS_MASK32      ((uint32)0x00000000U)

    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_SELF_TEST_UM_VD_REG_ST_RESULT_MASK32    ((uint32)0x00020000U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_SELF_TEST_UM_VD_REG_ST_DONE_MASK32      ((uint32)0x00010000U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_SELF_TEST_UM_VD_REG_ST_MODE_MASK32      ((uint32)0x000000C0U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_SELF_TEST_UM_VD_REG_VD_ST_CTRL_MASK32   ((uint32)0x0000003FU)

    /****************************************************/
    /***              PMC_FIR                         ***/
    /****************************************************/
    #define PMC_FIR_RWBITS_MASK32                       ((uint32)0x0000000BU)
    #define PMC_FIR_RESBITS_MASK32                      ((uint32)0x00000000U)

    #define PMC_FIR_STEST_FAULT_MASK32                  ((uint32)0x00000008U)
    #define PMC_FIR_HVD_FAULT_MASK32                    ((uint32)0x00000002U)
    #define PMC_FIR_LVD_FAULT_MASK32                    ((uint32)0x00000001U)

    /****************************************************/
    /***            PMC_LVD_HVD_INTR_ENB              ***/
    /****************************************************/
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_RWBITS_MASK32          ((uint32)0x8000447FU)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_RESBITS_MASK32         ((uint32)0x00000000U)

    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_PMC_ENABLE_MASK32      ((uint32)0x80000000U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_PMC_MASK32         ((uint32)0x00004000U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_SAR_ADC_MASK32     ((uint32)0x00000400U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_IO_MASK32          ((uint32)0x00000040U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_FLASH_MASK32       ((uint32)0x00000020U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_FLASH_MASK32       ((uint32)0x00000010U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_HV_MASK32          ((uint32)0x00000008U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_CORE_MASK32        ((uint32)0x00000004U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_CORE_HOT_MASK32    ((uint32)0x00000002U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_CORE_COLD_MASK32   ((uint32)0x00000001U)

    /****************************************************/
    /***          PMC_LVD_HVD_EVENT_STATUS            ***/
    /****************************************************/
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_STATUS_RWBITS_MASK32      ((uint32)0x0001447FU)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_STATUS_RESBITS_MASK32     ((uint32)0x00000000U)

    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_LVD_BUDDY_MASK32          ((uint32)0x00010000U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_LVD_PMC_MASK32            ((uint32)0x00004000U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_LVD_SAR_ADC_MASK32        ((uint32)0x00000400U)
    #define PMC_LVD_HVD_EVENT_LVD_IO_MASK32             ((uint32)0x00000040U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_HVD_FLASH_MASK32          ((uint32)0x00000020U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_LVD_FLASH_MASK32          ((uint32)0x00000010U)
    #define PMC_LVD_HVD_EVENT_HVD_HV_MASK32             ((uint32)0x00000008U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_HVD_CORE_MASK32           ((uint32)0x00000004U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_LVD_CORE_HOT_MASK32       ((uint32)0x00000002U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_EVENT_LVD_CORE_COLD_MASK32      ((uint32)0x00000001U)

    /****************************************************/
    /***                      PMC_REE                 ***/
    /****************************************************/
    #define PMC_REE_RWBITS_MASK32                       ((uint32)0x0000042DU)
    #define PMC_REE_RESBITS_MASK32                      ((uint32)0x00004052U)

    #define PMC_REE_LVD_SAR_ADC_MASK32                  ((uint32)0x00000400U)
    #define PMC_REE_HVD_FLASH_MASK32                    ((uint32)0x00000020U)
    #define PMC_REE_HVD_HV_MASK32                       ((uint32)0x00000008U)
    #define PMC_REE_HVD_CORE_MASK32                     ((uint32)0x00000004U)
    #define PMC_REE_LVD_CORE_COLD_MASK32                ((uint32)0x00000001U)

    /****************************************************/
    /***                      PMC_RES                 ***/
    /****************************************************/
    #define PMC_RES_RWBITS_MASK32                       ((uint32)0x0000042DU)
    #define PMC_RES_RESBITS_MASK32                      ((uint32)0x00000000U)

    #define PMC_RES_LVD_SAR_ADC_MASK32                  ((uint32)0x00000400U)
    #define PMC_RES_HVD_FLASH_MASK32                    ((uint32)0x00000020U)
    #define PMC_RES_HVD_HV_MASK32                       ((uint32)0x00000008U)
    #define PMC_RES_HVD_CORE_MASK32                     ((uint32)0x00000004U)
    #define PMC_RES_LVD_CORE_HOT_MASK32                 ((uint32)0x00000002U)
    #define PMC_RES_LVD_CORE_COLD_MASK32                ((uint32)0x00000001U)

    /****************************************************/
    /***                   PMC_ADC_CS                 ***/
    /****************************************************/
    #define PMC_ADC_CS_RWBITS_MASK32                    ((uint32)0x0000033FU)
    #define PMC_ADC_CS_RESBITS_MASK32                   ((uint32)0x00000000U)

    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_ADC_CS_STND_BY_RAM_BO_CLR_MASK32        ((uint32)0x00000200U)
    /** @violates @ref Reg_eSys_MC_PCU_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_ADC_CS_STND_BY_RAM_BR_DETCT_MASK32      ((uint32)0x00000100U)
    #define PMC_ADC_CS_ADC_CHSE_MASK32                  ((uint32)0x0000003FU)

#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

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

#endif /* REG_ESYS_MC_PCU_H */

/** @} */
