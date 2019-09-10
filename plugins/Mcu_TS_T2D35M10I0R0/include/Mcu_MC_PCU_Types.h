/**
*   @file    Mcu_MC_PCU_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from MC_PCU.
*   @details Public data types exported outside of the Mcu driver.
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


#ifndef MCU_MC_PCU_TYPES_H
#define MCU_MC_PCU_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_PCU_Types_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Mcu_MC_PCU_Types_h_REF_2
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
#include "Reg_eSys_MC_PCU.h"
#include "Soc_Ips.h"
#include "Mcu_MC_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_MC_PCU_TYPES_VENDOR_ID                        43
/** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_PCU_TYPES_AR_RELEASE_MAJOR_VERSION         4
/** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_PCU_TYPES_AR_RELEASE_MINOR_VERSION         2
/** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_PCU_TYPES_AR_RELEASE_REVISION_VERSION      2
/** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_PCU_TYPES_SW_MAJOR_VERSION                 1
/** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_PCU_TYPES_SW_MINOR_VERSION                 0
/** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_PCU_TYPES_SW_PATCH_VERSION                 0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Reg_eSys_MC_PCU header file are from the same vendor */
#if (MCU_MC_PCU_TYPES_VENDOR_ID != REG_ESYS_MC_PCU_VENDOR_ID)
    #error "Mcu_MC_PCU_Types.h and Reg_eSys_MC_PCU.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_MC_PCU header file are of the same Autosar version */
#if ((MCU_MC_PCU_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_MC_PCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_PCU_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_MC_PCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_PCU_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_MC_PCU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcu_MC_PCU_Types.h and Reg_eSys_MC_PCU.h are different"
#endif
/* Check if source file and Reg_eSys_MC_PCU header file are of the same Software version */
#if ((MCU_MC_PCU_TYPES_SW_MAJOR_VERSION != REG_ESYS_MC_PCU_SW_MAJOR_VERSION) || \
     (MCU_MC_PCU_TYPES_SW_MINOR_VERSION != REG_ESYS_MC_PCU_SW_MINOR_VERSION) || \
     (MCU_MC_PCU_TYPES_SW_PATCH_VERSION != REG_ESYS_MC_PCU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_PCU_Types.h and Reg_eSys_MC_PCU.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_PCU_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_PCU_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_MC_PCU_Types.h and Soc_Ips.h are different"
    #endif
#endif

/* Check if source file and Mcu_MC_IPVersion header file are from the same vendor */
#if (MCU_MC_PCU_TYPES_VENDOR_ID != MCU_MC_IPVERSION_VENDOR_ID)
    #error "Mcu_MC_PCU_Types.h and Mcu_MC_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Autosar version */
#if ((MCU_MC_PCU_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_PCU_TYPES_AR_RELEASE_MINOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_PCU_TYPES_AR_RELEASE_REVISION_VERSION != MCU_MC_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_PCU_Types.h and Mcu_MC_IPVersion.h are different"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Software version */
#if ((MCU_MC_PCU_TYPES_SW_MAJOR_VERSION != MCU_MC_IPVERSION_SW_MAJOR_VERSION) || \
     (MCU_MC_PCU_TYPES_SW_MINOR_VERSION != MCU_MC_IPVERSION_SW_MINOR_VERSION) || \
     (MCU_MC_PCU_TYPES_SW_PATCH_VERSION != MCU_MC_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_PCU_Types.h and Mcu_MC_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/********** PMU Registers Configuration **********/
#if (IPV_MC == IPV_MC_04_04_01_00)
    /****************************************************/
    /***              PMC_PMCCR                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_PMCCR_CONFIG_U32(value)                 ( ((value) & PMC_PMCCR_RWBITS_MASK32 ) | PMC_PMCCR_RESBITS_MASK32 )

    #define PMC_PMCCR_INT_AUX_REG_BYPASS_U32            (PMC_PMCCR_INT_AUX_REG_BYPASS_MASK32)
    #define PMC_PMCCR_INT_AUX_REG_ACTIVE_U32            ((uint32)0x00000000U)
    #define PMC_PMCCR_INT_REG_BYPASS_U32                (PMC_PMCCR_INT_REG_BYPASS_MASK32)
    #define PMC_PMCCR_INT_REG_ACTIVE_U32                ((uint32)0x00000000U)


    /****************************************************/
    /***              PMC_IER                         ***/
    /****************************************************/
/** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_IER_CONFIG_U32(value)                   ( ((value) & PMC_IER_RWBITS_MASK32 ) | PMC_IER_RESBITS_MASK32 )

    #define PMC_IER_TS1_3IE_ENA_U32                     (PMC_IER_TS1_3IE_MASK32)
    #define PMC_IER_TS1_3IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_TS1_2IE_ENA_U32                     (PMC_IER_TS1_2IE_MASK32)
    #define PMC_IER_TS1_2IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_TS1_0IE_ENA_U32                     (PMC_IER_TS1_0IE_MASK32)
    #define PMC_IER_TS1_0IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_TS0_3IE_ENA_U32                     (PMC_IER_TS0_3IE_MASK32)
    #define PMC_IER_TS0_3IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_TS0_2IE_ENA_U32                     (PMC_IER_TS0_2IE_MASK32)
    #define PMC_IER_TS0_2IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_TS0_0IE_ENA_U32                     (PMC_IER_TS0_0IE_MASK32)
    #define PMC_IER_TS0_0IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD6IE_O_ENA_U32                     (PMC_IER_VD6IE_O_MASK32)
    #define PMC_IER_VD6IE_O_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD6IE_ADC_ENA_U32                   (PMC_IER_VD6IE_ADC_MASK32)
    #define PMC_IER_VD6IE_ADC_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_IER_VD6IE_IM_ENA_U32                    (PMC_IER_VD6IE_IM_MASK32)
    #define PMC_IER_VD6IE_IM_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD6IE_F_ENA_U32                     (PMC_IER_VD6IE_F_MASK32)
    #define PMC_IER_VD6IE_F_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD6IE_C_ENA_U32                     (PMC_IER_VD6IE_C_MASK32)
    #define PMC_IER_VD6IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD4IE_C_ENA_U32                     (PMC_IER_VD4IE_C_MASK32)
    #define PMC_IER_VD4IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD3IE_H_ENA_U32                     (PMC_IER_VD3IE_H_MASK32)
    #define PMC_IER_VD3IE_H_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD3IE_C_ENA_U32                     (PMC_IER_VD3IE_C_MASK32)
    #define PMC_IER_VD3IE_C_DIS_U32                     ((uint32)0x00000000U)


    /****************************************************/
    /***              PMC_REE_0                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_0_CONFIG_U32(value)                 ( ((value) & PMC_REE_0_RWBITS_MASK32 ) | PMC_REE_0_RESBITS_MASK32 )

    #define PMC_REE_0_VD6RE_O_ENA_U32                   (PMC_REE_0_VD6RE_O_MASK32)
    #define PMC_REE_0_VD6RE_O_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_0_VD6RE_ADC_ENA_U32                 (PMC_REE_0_VD6RE_ADC_MASK32)
    #define PMC_REE_0_VD6RE_ADC_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_REE_0_VD6RE_IM_ENA_U32                  (PMC_REE_0_VD6RE_IM_MASK32)
    #define PMC_REE_0_VD6RE_IM_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_0_VD6RE_F_ENA_U32                   (PMC_REE_0_VD6RE_F_MASK32)
    #define PMC_REE_0_VD6RE_F_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_0_VD6RE_C_ENA_U32                   (PMC_REE_0_VD6RE_C_MASK32)
    #define PMC_REE_0_VD6RE_C_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_0_VD4RE_C_ENA_U32                   (PMC_REE_0_VD4RE_C_MASK32)
    #define PMC_REE_0_VD4RE_C_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_0_VD3RE_H_ENA_U32                   (PMC_REE_0_VD3RE_H_MASK32)
    #define PMC_REE_0_VD3RE_H_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_0_VD3RE_C_ENA_U32                   (PMC_REE_0_VD3RE_C_MASK32)
    #define PMC_REE_0_VD3RE_C_DIS_U32                   ((uint32)0x00000000U)


    /****************************************************/
    /***              PMC_RES_0                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_0_CONFIG_U32(value)                 ( ((value) & PMC_RES_0_RWBITS_MASK32 ) | PMC_RES_0_RESBITS_MASK32 )

    #define PMC_RES_0_VD6RE_O_ENA_U32                   (PMC_RES_0_VD6RE_O_MASK32)
    #define PMC_RES_0_VD6RE_O_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_0_VD6RE_ADC_ENA_U32                 (PMC_RES_0_VD6RE_ADC_MASK32)
    #define PMC_RES_0_VD6RE_ADC_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_RES_0_VD6RE_IM_ENA_U32                  (PMC_RES_0_VD6RE_IM_MASK32)
    #define PMC_RES_0_VD6RE_IM_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_0_VD6RE_F_ENA_U32                   (PMC_RES_0_VD6RE_F_MASK32)
    #define PMC_RES_0_VD6RE_F_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_0_VD6RE_C_ENA_U32                   (PMC_RES_0_VD6RE_C_MASK32)
    #define PMC_RES_0_VD6RE_C_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_0_VD4RE_C_ENA_U32                   (PMC_RES_0_VD4RE_C_MASK32)
    #define PMC_RES_0_VD4RE_C_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_0_VD3RE_H_ENA_U32                   (PMC_RES_0_VD3RE_H_MASK32)
    #define PMC_RES_0_VD3RE_H_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_0_VD3RE_C_ENA_U32                   (PMC_RES_0_VD3RE_C_MASK32)
    #define PMC_RES_0_VD3RE_C_DIS_U32                   ((uint32)0x00000000U)


    /****************************************************/
    /***              PMC_REE_TD                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_TD_CONFIG_U32(value)                ( ((value) & PMC_REE_TD_RWBITS_MASK32 ) | PMC_REE_TD_RESBITS_MASK32 )

    #define PMC_REE_TD_TEMP1_3_ENA_U32                  (PMC_REE_TD_TEMP1_3_MASK32)
    #define PMC_REE_TD_TEMP1_3_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP1_2_ENA_U32                  (PMC_REE_TD_TEMP1_2_MASK32)
    #define PMC_REE_TD_TEMP1_2_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP1_0_ENA_U32                  (PMC_REE_TD_TEMP1_0_MASK32)
    #define PMC_REE_TD_TEMP1_0_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP0_3_ENA_U32                  (PMC_REE_TD_TEMP0_3_MASK32)
    #define PMC_REE_TD_TEMP0_3_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP0_2_ENA_U32                  (PMC_REE_TD_TEMP0_2_MASK32)
    #define PMC_REE_TD_TEMP0_2_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP0_0_ENA_U32                  (PMC_REE_TD_TEMP0_0_MASK32)
    #define PMC_REE_TD_TEMP0_0_DIS_U32                  ((uint32)0x00000000U)


    /****************************************************/
    /***              PMC_RES_TD                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_TD_CONFIG_U32(value)                ( ((value) & PMC_RES_TD_RWBITS_MASK32 ) | PMC_RES_TD_RESBITS_MASK32 )

    #define PMC_RES_TD_TEMP1_3_ENA_U32                  (PMC_REE_TD_TEMP1_3_MASK32)
    #define PMC_RES_TD_TEMP1_3_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP1_2_ENA_U32                  (PMC_REE_TD_TEMP1_2_MASK32)
    #define PMC_RES_TD_TEMP1_2_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP1_0_ENA_U32                  (PMC_REE_TD_TEMP1_0_MASK32)
    #define PMC_RES_TD_TEMP1_0_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP0_3_ENA_U32                  (PMC_REE_TD_TEMP0_3_MASK32)
    #define PMC_RES_TD_TEMP0_3_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP0_2_ENA_U32                  (PMC_REE_TD_TEMP0_2_MASK32)
    #define PMC_RES_TD_TEMP0_2_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP0_0_ENA_U32                  (PMC_REE_TD_TEMP0_0_MASK32)
    #define PMC_RES_TD_TEMP0_0_DIS_U32                  ((uint32)0x00000000U)


    /****************************************************/
    /***              PMC_CTL_TD                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_CONFIG_U32(value)                ( ((value) & PMC_CTL_TD_RWBITS_MASK32 ) | PMC_CTL_TD_RESBITS_MASK32 )
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_TS1_TRIM_ADJ_U32(value)          ((uint32)(((value) << (uint32)10U) & PMC_CTL_TD_TS1_TRIM_ADJ_MASK32))
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_TS0_TRIM_ADJ_U32(value)          ((uint32)(((value) << (uint32)2U ) & PMC_CTL_TD_TS0_TRIM_ADJ_MASK32))

    #define PMC_CTL_TD_TS1_DOUT_ENA_U32                 (PMC_CTL_TD_TS1_DOUT_EN_MASK32)
    #define PMC_CTL_TD_TS1_DOUT_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS1_AOUT_ENA_U32                 (PMC_CTL_TD_TS1_AOUT_EN_MASK32)
    #define PMC_CTL_TD_TS1_AOUT_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS0_DOUT_ENA_U32                 (PMC_CTL_TD_TS0_DOUT_EN_MASK32)
    #define PMC_CTL_TD_TS0_DOUT_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS0_AOUT_ENA_U32                 (PMC_CTL_TD_TS0_AOUT_EN_MASK32)
    #define PMC_CTL_TD_TS0_AOUT_DIS_U32                 ((uint32)0x00000000U)

#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))

    /************************************/
    /*********** PMC_PMCCR  *************/
    /************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_PMCCR_CONFIG_U32(value)                ( ((value) & PMC_PMCCR_RWBITS_USR_MASK32 ) | PMC_PMCCR_RESBITS_MASK32 )
    /* Internal/External regulator Selection */
    #define PMC_PMCCR_INT_EXT_MODE_EN_U32               (PMC_PMCCR_INT_EXT_MODE_MASK32)
    #define PMC_PMCCR_INT_EXT_MODE_DIS_U32              ((uint32)0x00000000U)
    
    /* This bit controls the enable/disable on the LVD MIPI supply. */
    #define PMC_PMCCR_LVD_MIPI_ENABLE_EN_U32             (PMC_PMCCR_LVD_MIPI_ENABLE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_MIPI_ENABLE_DIS_U32            ((uint32)0x00000000U)
    /* This bit controls the enable/disable on the LVD PMC supply. */
    #define PMC_PMCCR_LVD_PMC_ENABLE_EN_U32             (PMC_PMCCR_LVD_PMC_ENABLE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_PMC_ENABLE_DIS_U32            ((uint32)0x00000000U)
    /*This bit controls the enable/disable on the LVD IO supply. */
    #define PMC_PMCCR_LVD_IO_ENABLE_EN_U32              (PMC_PMCCR_LVD_IO_ENABLE_MASK32)
    #define PMC_PMCCR_LVD_IO_ENABLE_DIS_U32             ((uint32)0x00000000U)
    /* This bit controls the enable/disable on the LVD FLASH supply. */
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_FLASH_ENABLE_EN_U32           (PMC_PMCCR_LVD_FLASH_ENABLE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_FLASH_ENABLE_DIS_U32          ((uint32)0x00000000U)
    /* This bit controls the enable/disable on the HVD ADC supply. */
    #define PMC_PMCCR_HVD_ADC_ENABLE_EN_U32             (PMC_PMCCR_HVD_ADC_ENABLE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_HVD_ADC_ENABLE_DIS_U32            ((uint32)0x00000000U)
    /* This bit controls the enable/disable on the LVD ADC supply. */
    #define PMC_PMCCR_LVD_ADC_ENABLE_EN_U32             (PMC_PMCCR_LVD_ADC_ENABLE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_ADC_ENABLE_DIS_U32            ((uint32)0x00000000U)
    /* This bit controls the enable/disable on the HVD Core supply. */
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_HVD_CORE_INT_ENABLE_EN_U32        (PMC_PMCCR_HVD_CORE_INT_ENABLE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_HVD_CORE_INT_ENABLE_DIS_U32       ((uint32)0x00000000U)
    /* LVD Core and LVD_PLL Enable Disbale control bit. */
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_CORE_INT_ENABLE_EN_U32        (PMC_PMCCR_LVD_CORE_INT_ENABLE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_PMCCR_LVD_CORE_INT_ENABLE_DIS_U32       ((uint32)0x00000000U)

    /************************************/
    /*********** PMC_TS_IER *************/
    /************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_TS_IER_CONFIG_U32(value)                ( ((value) & PMC_TS_IER_RWBITS_USR_MASK32 ) | PMC_TS_IER_RESBITS_MASK32 )
    /* Temperature Sensor 1 input 3 Interrupt Enable. */
    #define PMC_TS_IER_TS1_3IE_EN_U32                   (PMC_TS_IER_TS1_3IE_MASK32)
    #define PMC_TS_IER_TS1_3IE_DIS_U32                  ((uint32)0x00000000U)
    /* Temperature Sensor 1 input 2 Interrupt Enable. */
    #define PMC_TS_IER_TS1_2IE_EN_U32                   (PMC_TS_IER_TS1_2IE_MASK32)
    #define PMC_TS_IER_TS1_2IE_DIS_U32                  ((uint32)0x00000000U)
    /* Temperature Sensor 1 input 0 Interrupt Enable. */
    #define PMC_TS_IER_TS1_0IE_EN_U32                   (PMC_TS_IER_TS1_0IE_MASK32)
    #define PMC_TS_IER_TS1_0IE_DIS_U32                  ((uint32)0x00000000U)
    /* Temperature Sensor 0 input 3 Interrupt Enable. */
    #define PMC_TS_IER_TS0_3IE_EN_U32                   (PMC_TS_IER_TS0_3IE_MASK32)
    #define PMC_TS_IER_TS0_3IE_DIS_U32                  ((uint32)0x00000000U)
    /* Temperature Sensor 0 input 2 Interrupt Enable. */
    #define PMC_TS_IER_TS0_2IE_EN_U32                   (PMC_TS_IER_TS0_2IE_MASK32)
    #define PMC_TS_IER_TS0_2IE_DIS_U32                  ((uint32)0x00000000U)
    /* Temperature Sensor 0 input 0 Interrupt Enable. */
    #define PMC_TS_IER_TS0_0IE_EN_U32                   (PMC_TS_IER_TS0_0IE_MASK32)
    #define PMC_TS_IER_TS0_0IE_DIS_U32                  ((uint32)0x00000000U)


    /************************************/
    /******* PMC_AFE_INTR_ENA        ****/
    /************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_AFE_INTR_ENA_CONFIG_U32(value)          ( ((value) & PMC_AFE_INTR_ENA_RWBITS_USR_MASK32 ) | PMC_AFE_INTR_ENA_RESBITS_MASK32 )
    /* AFE-9 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG9_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG9_MASK32)
    #define PMC_AFE_INT_EN_VREG9_DIS_U32                ((uint32)0x00000000)
    /* AFE-8 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG8_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG8_MASK32)
    #define PMC_AFE_INT_EN_VREG8_DIS_U32                ((uint32)0x00000000)
    /* AFE-7 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG7_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG7_MASK32)
    #define PMC_AFE_INT_EN_VREG7_DIS_U32                ((uint32)0x00000000)
    /* AFE-6 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG6_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG6_MASK32)
    #define PMC_AFE_INT_EN_VREG6_DIS_U32                ((uint32)0x00000000)
    /* AFE-5 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG5_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG5_MASK32)
    #define PMC_AFE_INT_EN_VREG5_DIS_U32                ((uint32)0x00000000)
    /* AFE-4 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG4_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG4_MASK32)
    #define PMC_AFE_INT_EN_VREG4_DIS_U32                ((uint32)0x00000000)
    /* AFE-3 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG3_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG3_MASK32)
    #define PMC_AFE_INT_EN_VREG3_DIS_U32                ((uint32)0x00000000)
    /* AFE-2 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG2_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG2_MASK32)
    #define PMC_AFE_INT_EN_VREG2_DIS_U32                ((uint32)0x00000000)
    /* AFE-1 Interrupt Enable/Disable Control */
    #define PMC_AFE_INT_EN_VREG1_EN_U32                 (PMC_AFE_INTR_ENA_AFE_INT_EN_VREG1_MASK32)
    #define PMC_AFE_INT_EN_VREG1_DIS_U32                ((uint32)0x00000000)

    /************************************/
    /************ PMC_REE_TD *************/
    /************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_TD_CONFIG_U32(value)                ( ((value) & PMC_REE_TD_RWBITS_MASK32 ) | PMC_REE_TD_RESBITS_MASK32 )
    
    #define PMC_REE_TEMP1_3_ENA_U32                   (PMC_REE_TD_TEMP1_3_MASK32)
    #define PMC_REE_TEMP1_2_ENA_U32                   (PMC_REE_TD_TEMP1_2_MASK32)
    #define PMC_REE_TEMP1_0_ENA_U32                   (PMC_REE_TD_TEMP1_0_MASK32)
    #define PMC_REE_TEMP0_3_ENA_U32                   (PMC_REE_TD_TEMP0_3_MASK32)
    #define PMC_REE_TEMP0_2_ENA_U32                   (PMC_REE_TD_TEMP0_2_MASK32)
    #define PMC_REE_TEMP0_0_ENA_U32                   (PMC_REE_TD_TEMP0_0_MASK32)
    
    #define PMC_REE_TEMP1_3_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TEMP1_2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TEMP1_0_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TEMP0_3_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TEMP0_2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TEMP0_0_DIS_U32                   ((uint32)0x00000000U)


    /************************************/
    /************ PMC_RES_TD *************/
    /************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_TD_CONFIG_U32(value)                 ( ((value) & PMC_RES_TD_RWBITS_MASK32 ) | PMC_RES_TD_RESBITS_MASK32 )

    #define PMC_RES_TEMP1_3_ENA_U32                   (PMC_RES_TD_TEMP1_3_MASK32)
    #define PMC_RES_TEMP1_2_ENA_U32                   (PMC_RES_TD_TEMP1_2_MASK32)
    #define PMC_RES_TEMP1_0_ENA_U32                   (PMC_RES_TD_TEMP1_0_MASK32)
    #define PMC_RES_TEMP0_3_ENA_U32                   (PMC_RES_TD_TEMP0_3_MASK32)
    #define PMC_RES_TEMP0_2_ENA_U32                   (PMC_RES_TD_TEMP0_2_MASK32)
    #define PMC_RES_TEMP0_0_ENA_U32                   (PMC_RES_TD_TEMP0_0_MASK32)
    
    
    #define PMC_RES_TEMP1_3_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TEMP1_2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TEMP1_0_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TEMP0_3_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TEMP0_2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TEMP0_0_DIS_U32                   ((uint32)0x00000000U)

#elif ( IPV_MC == IPV_MC_04_00_15_15 )
    /****************************************************/
    /***               (IE_P)                         ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_IER_CONFIG_U32(value)                   ( ((value) & PMC_IER_RWBITS_MASK32 ) | PMC_IER_RESBITS_MASK32 )
    #define PMC_IER_IE_EN_MASK32                        ((uint32)0x80000000U)
    #define PMC_IER_VD15IE_A_ENA_U32                    (PMC_IER_VD15IE_A_MASK32)
    #define PMC_IER_VD15IE_C_ENA_U32                    (PMC_IER_VD15IE_C_MASK32)
    #define PMC_IER_VD14IE_A_ENA_U32                    (PMC_IER_VD14IE_A_MASK32)
    #define PMC_IER_VD14IE_IM_ENA_U32                   (PMC_IER_VD14IE_IM_MASK32)
    #define PMC_IER_VD13IE_IM_ENA_U32                   (PMC_IER_VD13IE_IM_MASK32)
    #define PMC_IER_VD12IE_F_ENA_U32                    (PMC_IER_VD12IE_F_MASK32)
    #define PMC_IER_VD10IE_A_ENA_U32                    (PMC_IER_VD10IE_A_MASK32)
    #define PMC_IER_VD10IE_F_ENA_U32                    (PMC_IER_VD10IE_F_MASK32)
    #define PMC_IER_VD9IE_O_ENA_U32                     (PMC_IER_VD9IE_O_MASK32)
    #define PMC_IER_VD9IE_IF2_ENA_U32                   (PMC_IER_VD9IE_IF2_MASK32)
    #define PMC_IER_VD9IE_IF_ENA_U32                    (PMC_IER_VD9IE_IF_MASK32)
    #define PMC_IER_VD9IE_IJ_ENA_U32                    (PMC_IER_VD9IE_IJ_MASK32)
    #define PMC_IER_VD9IE_IM_ENA_U32                    (PMC_IER_VD9IE_IM_MASK32)
    #define PMC_IER_VD9IE_F_ENA_U32                     (PMC_IER_VD9IE_F_MASK32)
    #define PMC_IER_VD9IE_EBI_ENA_U32                   (PMC_IER_VD9IE_EBI_MASK32)
    #define PMC_IER_VD9IE_C_ENA_U32                     (PMC_IER_VD9IE_C_MASK32)
    #define PMC_IER_VD8IE_C_ENA_U32                     (PMC_IER_VD8IE_C_MASK32)
    #define PMC_IER_VD7IE_C_ENA_U32                     (PMC_IER_VD7IE_C_MASK32)
    #define PMC_IER_VD4IE_C_ENA_U32                     (PMC_IER_VD4IE_C_MASK32)
    #define PMC_IER_VD3IE_P_ENA_U32                     (PMC_IER_VD3IE_P_MASK32)
    #define PMC_IER_VD3IE_F_ENA_U32                     (PMC_IER_VD3IE_F_MASK32)
    #define PMC_IER_VD3IE_C_ENA_U32                     (PMC_IER_VD3IE_C_MASK32)
    #define PMC_IER_VD15IE_A_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD15IE_C_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD14IE_A_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD14IE_IM_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_IER_VD13IE_IM_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_IER_VD12IE_F_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD10IE_A_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD10IE_F_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_O_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_IF2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_IF_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_IJ_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_IM_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_F_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_EBI_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD8IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD7IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD4IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD3IE_P_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD3IE_F_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD3IE_C_DIS_U32                     ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD3)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD3_CONFIG_U32(value)               ( ((value) & PMC_REE_VD3_RWBITS_MASK32 ) | PMC_REE_VD3_RESBITS_MASK32 )
    #define PMC_REE_VD3_LVD3_P_ENA_U32                  (PMC_REE_VD3_LVD3_P_MASK32)
    #define PMC_REE_VD3_LVD3_F_ENA_U32                  (PMC_REE_VD3_LVD3_F_MASK32)
    #define PMC_REE_VD3_LVD3_C_ENA_U32                  (PMC_REE_VD3_LVD3_C_MASK32)
    #define PMC_REE_VD3_LVD3_P_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD3_LVD3_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD3_LVD3_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD3)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD3_CONFIG_U32(value)               ( ((value) & PMC_RES_VD3_RWBITS_MASK32 ) | PMC_RES_VD3_RESBITS_MASK32 )
    #define PMC_RES_VD3_LVD3_P_ENA_U32                  (PMC_RES_VD3_LVD3_P_MASK32)
    #define PMC_RES_VD3_LVD3_F_ENA_U32                  (PMC_RES_VD3_LVD3_F_MASK32)
    #define PMC_RES_VD3_LVD3_C_ENA_U32                  (PMC_RES_VD3_LVD3_C_MASK32)
    #define PMC_RES_VD3_LVD3_P_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_VD3_LVD3_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_VD3_LVD3_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD3)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD3_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD3_RWBITS_MASK32 ) | PMC_FEE_VD3_RESBITS_MASK32 )
    #define PMC_FEE_VD3_FEE3_P_ENA_U32                  (PMC_FEE_VD3_FEE3_P_MASK32)
    #define PMC_FEE_VD3_FEE3_F_ENA_U32                  (PMC_FEE_VD3_FEE3_F_MASK32)
    #define PMC_FEE_VD3_FEE3_C_ENA_U32                  (PMC_FEE_VD3_FEE3_C_MASK32)
    #define PMC_FEE_VD3_FEE3_P_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD3_FEE3_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD3_FEE3_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD4)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD4_CONFIG_U32(value)               ( ((value) & PMC_REE_VD4_RWBITS_MASK32 ) | PMC_REE_VD4_RESBITS_MASK32 )
    #define PMC_REE_VD4_LVD4_C_ENA_U32                  (PMC_REE_VD4_LVD4_C_MASK32)
    #define PMC_REE_VD4_LVD4_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD4)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD4_CONFIG_U32(value)               ( ((value) & PMC_RES_VD4_RWBITS_MASK32 ) | PMC_RES_VD4_RESBITS_MASK32 )
    #define PMC_RES_VD4_LVD4_C_ENA_U32                  (PMC_RES_VD4_LVD4_C_MASK32)
    #define PMC_RES_VD4_LVD4_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD4)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD4_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD4_RWBITS_MASK32 ) | PMC_FEE_VD4_RESBITS_MASK32 )
    #define PMC_FEE_VD4_FEE4_C_ENA_U32                  (PMC_FEE_VD4_FEE4_C_MASK32)
    #define PMC_FEE_VD4_FEE4_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD7)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD7_CONFIG_U32(value)               ( ((value) & PMC_REE_VD7_RWBITS_MASK32 ) | PMC_REE_VD7_RESBITS_MASK32 )
    #define PMC_REE_VD7_HVD7_C_ENA_U32                  (PMC_REE_VD7_HVD7_C_MASK32)
    #define PMC_REE_VD7_HVD7_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD7)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD7_CONFIG_U32(value)               ( ((value) & PMC_RES_VD7_RWBITS_MASK32 ) | PMC_RES_VD7_RESBITS_MASK32 )
    #define PMC_RES_VD7_HVD7_C_ENA_U32                  (PMC_RES_VD7_HVD7_C_MASK32)
    #define PMC_RES_VD7_HVD7_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD7)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD7_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD7_RWBITS_MASK32 ) | PMC_FEE_VD7_RESBITS_MASK32 )
    #define PMC_FEE_VD7_FEE7_C_ENA_U32                  (PMC_FEE_VD7_FEE7_C_MASK32)
    #define PMC_FEE_VD7_FEE7_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD8)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD8_CONFIG_U32(value)               ( ((value) & PMC_REE_VD8_RWBITS_MASK32 ) | PMC_REE_VD8_RESBITS_MASK32 )
    #define PMC_REE_VD8_HVD8_F_ENA_U32                  (PMC_REE_VD8_HVD8_F_MASK32)
    #define PMC_REE_VD8_HVD8_C_ENA_U32                  (PMC_REE_VD8_HVD8_C_MASK32)
    #define PMC_REE_VD8_HVD8_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD8_HVD8_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD8)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD8_CONFIG_U32(value)               ( ((value) & PMC_RES_VD8_RWBITS_MASK32 ) | PMC_RES_VD8_RESBITS_MASK32 )
    #define PMC_RES_VD8_HVD8_F_ENA_U32                  (PMC_RES_VD8_HVD8_F_MASK32)
    #define PMC_RES_VD8_HVD8_C_ENA_U32                  (PMC_RES_VD8_HVD8_C_MASK32)
    #define PMC_RES_VD8_HVD8_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_VD8_HVD8_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD8)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD8_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD8_RWBITS_MASK32 ) | PMC_FEE_VD8_RESBITS_MASK32 )
    #define PMC_FEE_VD8_FEE8_F_ENA_U32                  (PMC_FEE_VD8_FEE8_F_MASK32)
    #define PMC_FEE_VD8_FEE8_C_ENA_U32                  (PMC_FEE_VD8_FEE8_C_MASK32)
    #define PMC_FEE_VD8_FEE8_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD8_FEE8_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD9)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD9_CONFIG_U32(value)               ( ((value) & PMC_REE_VD9_RWBITS_MASK32 ) | PMC_REE_VD9_RESBITS_MASK32 )
    #define PMC_REE_VD9_LVD9_O_ENA_U32                  (PMC_REE_VD9_LVD9_O_MASK32)
    #define PMC_REE_VD9_LVD9_IF2_ENA_U32                (PMC_REE_VD9_LVD9_IF2_MASK32)
    #define PMC_REE_VD9_LVD9_IF_ENA_U32                 (PMC_REE_VD9_LVD9_IF_MASK32)
    #define PMC_REE_VD9_LVD9_IJ_ENA_U32                 (PMC_REE_VD9_LVD9_IJ_MASK32)
    #define PMC_REE_VD9_LVD9_IM_ENA_U32                 (PMC_REE_VD9_LVD9_IM_MASK32)
    #define PMC_REE_VD9_LVD9_F_ENA_U32                  (PMC_REE_VD9_LVD9_F_MASK32)
    #define PMC_REE_VD9_LVD9_EBI_ENA_U32                (PMC_REE_VD9_LVD9_EBI_MASK32)
    #define PMC_REE_VD9_LVD9_C_ENA_U32                  (PMC_REE_VD9_LVD9_C_MASK32)
    #define PMC_REE_VD9_LVD9_O_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_IF2_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_IF_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_IJ_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_IM_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_EBI_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD9)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD9_CONFIG_U32(value)               ( ((value) & PMC_RES_VD9_RWBITS_MASK32 ) | PMC_RES_VD9_RESBITS_MASK32 )
    #define PMC_RES_VD9_LVD9_IF2_ENA_U32                (PMC_RES_VD9_LVD9_IF2_MASK32)
    #define PMC_RES_VD9_LVD9_IF_ENA_U32                 (PMC_RES_VD9_LVD9_IF_MASK32)
    #define PMC_RES_VD9_LVD9_EBI_ENA_U32                (PMC_RES_VD9_LVD9_EBI_MASK32)
    #define PMC_RES_VD9_LVD9_IF2_DIS_U32                ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_IF_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_EBI_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD9)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD9_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD9_RWBITS_MASK32 ) | PMC_FEE_VD9_RESBITS_MASK32 )
    #define PMC_FEE_VD9_FEE9_O_ENA_U32                  (PMC_FEE_VD9_FEE9_O_MASK32)
    #define PMC_FEE_VD9_FEE9_IF2_ENA_U32                (PMC_FEE_VD9_FEE9_IF2_MASK32)
    #define PMC_FEE_VD9_FEE9_IF_ENA_U32                 (PMC_FEE_VD9_FEE9_IF_MASK32)
    #define PMC_FEE_VD9_FEE9_IJ_ENA_U32                 (PMC_FEE_VD9_FEE9_IJ_MASK32)
    #define PMC_FEE_VD9_FEE9_IM_ENA_U32                 (PMC_FEE_VD9_FEE9_IM_MASK32)
    #define PMC_FEE_VD9_FEE9_F_ENA_U32                  (PMC_FEE_VD9_FEE9_F_MASK32)
    #define PMC_FEE_VD9_FEE9_EBI_ENA_U32                (PMC_FEE_VD9_FEE9_EBI_MASK32)
    #define PMC_FEE_VD9_FEE9_C_ENA_U32                  (PMC_FEE_VD9_FEE9_C_MASK32)
    #define PMC_FEE_VD9_FEE9_O_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_IF2_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_IF_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_IJ_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_IM_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_EBI_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD10)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD10_CONFIG_U32(value)              ( ((value) & PMC_REE_VD10_RWBITS_MASK32 ) | PMC_REE_VD10_RESBITS_MASK32 )
    #define PMC_REE_VD10_LVD10_A_ENA_U32                (PMC_REE_VD10_LVD10_A_MASK32)
    #define PMC_REE_VD10_LVD10_F_ENA_U32                (PMC_REE_VD10_LVD10_F_MASK32)
    #define PMC_REE_VD10_LVD10_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD10_LVD10_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD10)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD10_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD10_RWBITS_MASK32 ) | PMC_FEE_VD10_RESBITS_MASK32 )
    #define PMC_FEE_VD10_FEE10_A_ENA_U32                (PMC_FEE_VD10_FEE10_A_MASK32)
    #define PMC_FEE_VD10_FEE10_F_ENA_U32                (PMC_FEE_VD10_FEE10_F_MASK32)
    #define PMC_FEE_VD10_FEE10_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD10_FEE10_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD12)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD12_CONFIG_U32(value)              ( ((value) & PMC_REE_VD12_RWBITS_MASK32 ) | PMC_REE_VD12_RESBITS_MASK32 )
    #define PMC_REE_VD12_HVD12_F_ENA_U32                (PMC_REE_VD12_HVD12_F_MASK32)
    #define PMC_REE_VD12_HVD12_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD12)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD12_CONFIG_U32(value)              ( ((value) & PMC_RES_VD12_RWBITS_MASK32 ) | PMC_RES_VD12_RESBITS_MASK32 )
    #define PMC_RES_VD12_HVD12_F_ENA_U32                (PMC_RES_VD12_HVD12_F_MASK32)
    #define PMC_RES_VD12_HVD12_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD12)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD12_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD12_RWBITS_MASK32 ) | PMC_FEE_VD12_RESBITS_MASK32 )
    #define PMC_FEE_VD12_FEE12_F_ENA_U32                (PMC_FEE_VD12_FEE12_F_MASK32)
    #define PMC_FEE_VD12_FEE12_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD13)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD13_CONFIG_U32(value)              ( ((value) & PMC_REE_VD13_RWBITS_MASK32 ) | PMC_REE_VD13_RESBITS_MASK32 )
    #define PMC_REE_VD13_LVD13_IM_ENA_U32               (PMC_REE_VD13_LVD13_IM_MASK32)
    #define PMC_REE_VD13_LVD13_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD13)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD13_CONFIG_U32(value)              ( ((value) & PMC_RES_VD13_RWBITS_MASK32 ) | PMC_RES_VD13_RESBITS_MASK32 )
    #define PMC_RES_VD13_LVD13_IM_ENA_U32               (PMC_RES_VD13_LVD13_IM_MASK32)
    #define PMC_RES_VD13_LVD13_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD13)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD13_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD13_RWBITS_MASK32 ) | PMC_FEE_VD13_RESBITS_MASK32 )
    #define PMC_FEE_VD13_FEE13_IM_ENA_U32               (PMC_FEE_VD13_FEE13_IM_MASK32)
    #define PMC_FEE_VD13_FEE13_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD14)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD14_CONFIG_U32(value)              ( ((value) & PMC_REE_VD14_RWBITS_MASK32 ) | PMC_REE_VD14_RESBITS_MASK32 )
    #define PMC_REE_VD14_LVD14_A_ENA_U32                (PMC_REE_VD14_LVD14_A_MASK32)
    #define PMC_REE_VD14_LVD14_IM_ENA_U32               (PMC_REE_VD14_LVD14_IM_MASK32)
    #define PMC_REE_VD14_LVD14_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD14_LVD14_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD14)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD14_CONFIG_U32(value)              ( ((value) & PMC_RES_VD14_RWBITS_MASK32 ) | PMC_RES_VD14_RESBITS_MASK32 )
    #define PMC_RES_VD14_LVD14_A_ENA_U32                (PMC_RES_VD14_LVD14_A_MASK32)
    #define PMC_RES_VD14_LVD14_IM_ENA_U32               (PMC_RES_VD14_LVD14_IM_MASK32)
    #define PMC_RES_VD14_LVD14_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_RES_VD14_LVD14_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD14)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD14_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD14_RWBITS_MASK32 ) | PMC_FEE_VD14_RESBITS_MASK32 )
    #define PMC_FEE_VD14_FEE14_A_ENA_U32                (PMC_FEE_VD14_FEE14_A_MASK32)
    #define PMC_FEE_VD14_FEE14_IM_ENA_U32               (PMC_FEE_VD14_FEE14_IM_MASK32)
    #define PMC_FEE_VD14_FEE14_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD14_FEE14_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD15)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD15_CONFIG_U32(value)              ( ((value) & PMC_REE_VD15_RWBITS_MASK32 ) | PMC_REE_VD15_RESBITS_MASK32 )
    #define PMC_REE_VD15_HVD15_A_ENA_U32                (PMC_REE_VD15_HVD15_A_MASK32)
    #define PMC_REE_VD15_HVD15_C_ENA_U32                (PMC_REE_VD15_HVD15_C_MASK32)
    #define PMC_REE_VD15_HVD15_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD15_HVD15_C_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD15)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD15_CONFIG_U32(value)              ( ((value) & PMC_RES_VD15_RWBITS_MASK32 ) | PMC_RES_VD15_RESBITS_MASK32 )
    #define PMC_RES_VD15_HVD15_A_ENA_U32                (PMC_RES_VD15_HVD15_A_MASK32)
    #define PMC_RES_VD15_HVD15_C_ENA_U32                (PMC_RES_VD15_HVD15_C_MASK32)
    #define PMC_RES_VD15_HVD15_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_RES_VD15_HVD15_C_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD15)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD15_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD15_RWBITS_MASK32 ) | PMC_FEE_VD15_RESBITS_MASK32 )
    #define PMC_FEE_VD15_FEE15_A_ENA_U32                (PMC_FEE_VD15_FEE15_A_MASK32)
    #define PMC_FEE_VD15_FEE15_C_ENA_U32                (PMC_FEE_VD15_FEE15_C_MASK32)
    #define PMC_FEE_VD15_FEE15_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD15_FEE15_C_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (VSIO)                         ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_VSIO_CONFIG_U32(value)                  ( ((value) & PMC_VSIO_RWBITS_MASK32 ) | PMC_VSIO_RESBITS_MASK32 )
    #define PMC_VSIO_VSIO_IF2_EN_U32                    ((uint32)0x00000800U)
    #define PMC_VSIO_VSIO_IF_EN_U32                     ((uint32)0x00000400U)
    #define PMC_VSIO_VSIO_IJ_EN_U32                     ((uint32)0x00000200U)
    #define PMC_VSIO_VSIO_IM_EN_U32                     ((uint32)0x00000100U)
    #define PMC_VSIO_VSIO_IF2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IF_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IJ_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IM_DIS_U32                    ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_TD)                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_TD_CONFIG_U32(value)                ( ((value) & PMC_REE_TD_RWBITS_MASK32 ) | PMC_REE_TD_RESBITS_MASK32 )
    #define PMC_REE_TD_TEMP_3_ENA_U32                   (PMC_REE_TD_TEMP_3_MASK32)
    #define PMC_REE_TD_TEMP_2_ENA_U32                   (PMC_REE_TD_TEMP_2_MASK32)
    #define PMC_REE_TD_TEMP_0_ENA_U32                   (PMC_REE_TD_TEMP_0_MASK32)
    #define PMC_REE_TD_TEMP_3_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP_2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP_0_DIS_U32                   ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_TD)                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_TD_CONFIG_U32(value)                ( ((value) & PMC_RES_TD_RWBITS_MASK32 ) | PMC_RES_TD_RESBITS_MASK32 )
    #define PMC_RES_TD_TEMP_3_ENA_U32                   (PMC_RES_TD_TEMP_3_MASK32)
    #define PMC_RES_TD_TEMP_2_ENA_U32                   (PMC_RES_TD_TEMP_2_MASK32)
    #define PMC_RES_TD_TEMP_0_ENA_U32                   (PMC_RES_TD_TEMP_0_MASK32)
    #define PMC_RES_TD_TEMP_3_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP_2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP_0_DIS_U32                   ((uint32)0x00000000U)

    /****************************************************/
    /***               (CTL_TD)                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_CONFIG_U32(value)                ( ((value) & PMC_CTL_TD_RWBITS_MASK32 ) | PMC_CTL_TD_RESBITS_MASK32 )
    #define PMC_CTL_TD_TS3IE_ENA_U32                    (PMC_CTL_TD_TS3IE_MASK32)
    #define PMC_CTL_TD_TS2IE_ENA_U32                    (PMC_CTL_TD_TS2IE_MASK32)
    #define PMC_CTL_TD_TS0IE_ENA_U32                    (PMC_CTL_TD_TS0IE_MASK32)
    #define PMC_CTL_TD_DOUT_ENA_U32                     (PMC_CTL_TD_DOUT_MASK32)
    #define PMC_CTL_TD_AOUT_ENA_U32                     (PMC_CTL_TD_AOUT_MASK32)
    #define PMC_CTL_TD_TS3IE_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS2IE_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS0IE_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_CTL_TD_DOUT_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_CTL_TD_AOUT_DIS_U32                     ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_TRIM_ADJ_OVER_U32(value)         ((uint32)( (uint32)((value) << (uint32)8U) & PMC_CTL_TD_TRIM_ADJ_OVER_MASK32 ))
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_TRIM_ADJ_UNDER_U32(value)        ((uint32)( (uint32)((value) << (uint32)2U) & PMC_CTL_TD_TRIM_ADJ_UNDER_MASK32 ))

    /****************************************************/
    /***               (FEE_TD)                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_TD_CONFIG_U32(value)                ( ((value) & PMC_FEE_TD_RWBITS_MASK32 ) | PMC_FEE_TD_RESBITS_MASK32 )
    #define PMC_FEE_TD_FEE_TS3_ENA_U32                  (PMC_FEE_TD_FEE_TS3_MASK32)
    #define PMC_FEE_TD_FEE_TS2_ENA_U32                  (PMC_FEE_TD_FEE_TS2_MASK32)
    #define PMC_FEE_TD_FEE_TS0_ENA_U32                  (PMC_FEE_TD_FEE_TS0_MASK32)
    #define PMC_FEE_TD_FEE_TS3_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_TD_FEE_TS2_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_TD_FEE_TS0_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (VSIO)                         ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_VSIO_CONFIG_U32(value)                  ( ((value) & PMC_VSIO_RWBITS_MASK32 ) | PMC_VSIO_RESBITS_MASK32 )
    #define PMC_VSIO_VSIO_IF2_ENA_U32                   (PMC_VSIO_VSIO_IF2_MASK32)
    #define PMC_VSIO_VSIO_IF_ENA_U32                    (PMC_VSIO_VSIO_IF_MASK32)
    #define PMC_VSIO_VSIO_IJ_ENA_U32                    (PMC_VSIO_VSIO_IJ_MASK32)
    #define PMC_VSIO_VSIO_IM_ENA_U32                    (PMC_VSIO_VSIO_IM_MASK32)
    #define PMC_VSIO_VSIO_IF2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IF_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IJ_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IM_DIS_U32                    ((uint32)0x00000000U)

#elif ( IPV_MC == IPV_MC_04_01_00_00 )
    /****************************************************/
    /***               (IE_P)                         ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_IER_CONFIG_U32(value)                   ( ((value) & PMC_IER_RWBITS_MASK32 ) | PMC_IER_RESBITS_MASK32 )
    #define PMC_IER_IE_EN_MASK32                        ((uint32)0x80000000U)
    #define PMC_IER_VD15IE_A_ENA_U32                    (PMC_IER_VD15IE_A_MASK32)
    #define PMC_IER_VD15IE_C_ENA_U32                    (PMC_IER_VD15IE_C_MASK32)
    #define PMC_IER_VD14IE_A_ENA_U32                    (PMC_IER_VD14IE_A_MASK32)
    #define PMC_IER_VD14IE_IM_ENA_U32                   (PMC_IER_VD14IE_IM_MASK32)
    #define PMC_IER_VD13IE_IM_ENA_U32                   (PMC_IER_VD13IE_IM_MASK32)
    #define PMC_IER_VD12IE_F_ENA_U32                    (PMC_IER_VD12IE_F_MASK32)
    #define PMC_IER_VD10IE_A_ENA_U32                    (PMC_IER_VD10IE_A_MASK32)
    #define PMC_IER_VD10IE_F_ENA_U32                    (PMC_IER_VD10IE_F_MASK32)
    #define PMC_IER_VD9IE_O_ENA_U32                     (PMC_IER_VD9IE_O_MASK32)
    #define PMC_IER_VD9IE_IF_ENA_U32                    (PMC_IER_VD9IE_IF_MASK32)
    #define PMC_IER_VD9IE_IJ_ENA_U32                    (PMC_IER_VD9IE_IJ_MASK32)
    #define PMC_IER_VD9IE_IM_ENA_U32                    (PMC_IER_VD9IE_IM_MASK32)
    #define PMC_IER_VD9IE_F_ENA_U32                     (PMC_IER_VD9IE_F_MASK32)
    #define PMC_IER_VD9IE_C_ENA_U32                     (PMC_IER_VD9IE_C_MASK32)
    #define PMC_IER_VD8IE_F_ENA_U32                     (PMC_IER_VD8IE_F_MASK32)
    #define PMC_IER_VD8IE_C_ENA_U32                     (PMC_IER_VD8IE_C_MASK32)
    #define PMC_IER_VD7IE_C_ENA_U32                     (PMC_IER_VD7IE_C_MASK32)
    #define PMC_IER_VD4IE_C_ENA_U32                     (PMC_IER_VD4IE_C_MASK32)
    #define PMC_IER_VD3IE_P_ENA_U32                     (PMC_IER_VD3IE_P_MASK32)
    #define PMC_IER_VD3IE_F_ENA_U32                     (PMC_IER_VD3IE_F_MASK32)
    #define PMC_IER_VD3IE_C_ENA_U32                     (PMC_IER_VD3IE_C_MASK32)
    #define PMC_IER_VD15IE_A_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD15IE_C_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD14IE_A_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD14IE_IM_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_IER_VD13IE_IM_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_IER_VD12IE_F_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD10IE_A_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD10IE_F_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_O_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_IF_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_IJ_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_IM_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_F_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD9IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD8IE_F_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD8IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD7IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD4IE_C_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD3IE_P_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD3IE_F_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_VD3IE_C_DIS_U32                     ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD3)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD3_CONFIG_U32(value)               ( ((value) & PMC_REE_VD3_RWBITS_MASK32 ) | PMC_REE_VD3_RESBITS_MASK32 )
    #define PMC_REE_VD3_LVD3_P_ENA_U32                  (PMC_REE_VD3_LVD3_P_MASK32)
    #define PMC_REE_VD3_LVD3_F_ENA_U32                  (PMC_REE_VD3_LVD3_F_MASK32)
    #define PMC_REE_VD3_LVD3_C_ENA_U32                  (PMC_REE_VD3_LVD3_C_MASK32)
    #define PMC_REE_VD3_LVD3_P_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD3_LVD3_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD3_LVD3_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD3)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD3_CONFIG_U32(value)               ( ((value) & PMC_RES_VD3_RWBITS_MASK32 ) | PMC_RES_VD3_RESBITS_MASK32 )
    #define PMC_RES_VD3_LVD3_P_ENA_U32                  (PMC_RES_VD3_LVD3_P_MASK32)
    #define PMC_RES_VD3_LVD3_F_ENA_U32                  (PMC_RES_VD3_LVD3_F_MASK32)
    #define PMC_RES_VD3_LVD3_C_ENA_U32                  (PMC_RES_VD3_LVD3_C_MASK32)
    #define PMC_RES_VD3_LVD3_P_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_VD3_LVD3_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_VD3_LVD3_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD3)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD3_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD3_RWBITS_MASK32 ) | PMC_FEE_VD3_RESBITS_MASK32 )
    #define PMC_FEE_VD3_FEE3_P_ENA_U32                  (PMC_FEE_VD3_FEE3_P_MASK32)
    #define PMC_FEE_VD3_FEE3_F_ENA_U32                  (PMC_FEE_VD3_FEE3_F_MASK32)
    #define PMC_FEE_VD3_FEE3_C_ENA_U32                  (PMC_FEE_VD3_FEE3_C_MASK32)
    #define PMC_FEE_VD3_FEE3_P_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD3_FEE3_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD3_FEE3_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD4)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD4_CONFIG_U32(value)               ( ((value) & PMC_REE_VD4_RWBITS_MASK32 ) | PMC_REE_VD4_RESBITS_MASK32 )
    #define PMC_REE_VD4_LVD4_C_ENA_U32                  (PMC_REE_VD4_LVD4_C_MASK32)
    #define PMC_REE_VD4_LVD4_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD4)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD4_CONFIG_U32(value)               ( ((value) & PMC_RES_VD4_RWBITS_MASK32 ) | PMC_RES_VD4_RESBITS_MASK32 )
    #define PMC_RES_VD4_LVD4_C_ENA_U32                  (PMC_RES_VD4_LVD4_C_MASK32)
    #define PMC_RES_VD4_LVD4_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD4)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD4_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD4_RWBITS_MASK32 ) | PMC_FEE_VD4_RESBITS_MASK32 )
    #define PMC_FEE_VD4_FEE4_C_ENA_U32                  (PMC_FEE_VD4_FEE4_C_MASK32)
    #define PMC_FEE_VD4_FEE4_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD7)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD7_CONFIG_U32(value)               ( ((value) & PMC_REE_VD7_RWBITS_MASK32 ) | PMC_REE_VD7_RESBITS_MASK32 )
    #define PMC_REE_VD7_HVD7_C_ENA_U32                  (PMC_REE_VD7_HVD7_C_MASK32)
    #define PMC_REE_VD7_HVD7_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD7)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD7_CONFIG_U32(value)               ( ((value) & PMC_RES_VD7_RWBITS_MASK32 ) | PMC_RES_VD7_RESBITS_MASK32 )
    #define PMC_RES_VD7_HVD7_C_ENA_U32                  (PMC_RES_VD7_HVD7_C_MASK32)
    #define PMC_RES_VD7_HVD7_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD7)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD7_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD7_RWBITS_MASK32 ) | PMC_FEE_VD7_RESBITS_MASK32 )
    #define PMC_FEE_VD7_FEE7_C_ENA_U32                  (PMC_FEE_VD7_FEE7_C_MASK32)
    #define PMC_FEE_VD7_FEE7_C_DIS_U32                  ((uint32)0x00000000U)


    /****************************************************/
    /***               (REE_VD8)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD8_CONFIG_U32(value)               ( ((value) & PMC_REE_VD8_RWBITS_MASK32 ) | PMC_REE_VD8_RESBITS_MASK32 )
    #define PMC_REE_VD8_HVD8_F_ENA_U32                  (PMC_REE_VD8_HVD8_F_MASK32)
    #define PMC_REE_VD8_HVD8_C_ENA_U32                  (PMC_REE_VD8_HVD8_C_MASK32)
    #define PMC_REE_VD8_HVD8_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD8_HVD8_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD8)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD8_CONFIG_U32(value)               ( ((value) & PMC_RES_VD8_RWBITS_MASK32 ) | PMC_RES_VD8_RESBITS_MASK32 )
    #define PMC_RES_VD8_HVD8_F_ENA_U32                  (PMC_RES_VD8_HVD8_F_MASK32)
    #define PMC_RES_VD8_HVD8_C_ENA_U32                  (PMC_RES_VD8_HVD8_C_MASK32)
    #define PMC_RES_VD8_HVD8_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_VD8_HVD8_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD8)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD8_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD8_RWBITS_MASK32 ) | PMC_FEE_VD8_RESBITS_MASK32 )

    #define PMC_FEE_VD8_FEE8_F_ENA_U32                  (PMC_FEE_VD8_FEE8_F_MASK32)
    #define PMC_FEE_VD8_FEE8_C_ENA_U32                  (PMC_FEE_VD8_FEE8_C_MASK32)
    #define PMC_FEE_VD8_FEE8_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD8_FEE8_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD9)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD9_CONFIG_U32(value)               ( ((value) & PMC_REE_VD9_RWBITS_MASK32 ) | PMC_REE_VD9_RESBITS_MASK32 )
    #define PMC_REE_VD9_LVD9_O_ENA_U32                  (PMC_REE_VD9_LVD9_O_MASK32)
    #define PMC_REE_VD9_LVD9_IF_ENA_U32                 (PMC_REE_VD9_LVD9_IF_MASK32)
    #define PMC_REE_VD9_LVD9_IJ_ENA_U32                 (PMC_REE_VD9_LVD9_IJ_MASK32)
    #define PMC_REE_VD9_LVD9_IM_ENA_U32                 (PMC_REE_VD9_LVD9_IM_MASK32)
    #define PMC_REE_VD9_LVD9_F_ENA_U32                  (PMC_REE_VD9_LVD9_F_MASK32)
    #define PMC_REE_VD9_LVD9_C_ENA_U32                  (PMC_REE_VD9_LVD9_C_MASK32)
    #define PMC_REE_VD9_LVD9_O_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_IF_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_IJ_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_IM_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_REE_VD9_LVD9_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD9)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD9_CONFIG_U32(value)               ( ((value) & PMC_RES_VD9_RWBITS_MASK32 ) | PMC_RES_VD9_RESBITS_MASK32 )
    #define PMC_RES_VD9_LVD9_O_ENA_U32                  (PMC_RES_VD9_LVD9_O_MASK32)
    #define PMC_RES_VD9_LVD9_IF_ENA_U32                 (PMC_RES_VD9_LVD9_IF_MASK32)
    #define PMC_RES_VD9_LVD9_IJ_ENA_U32                 (PMC_RES_VD9_LVD9_IJ_MASK32)
    #define PMC_RES_VD9_LVD9_IM_ENA_U32                 (PMC_RES_VD9_LVD9_IM_MASK32)
    #define PMC_RES_VD9_LVD9_F_ENA_U32                  (PMC_RES_VD9_LVD9_F_MASK32)
    #define PMC_RES_VD9_LVD9_C_ENA_U32                  (PMC_RES_VD9_LVD9_C_MASK32)
    #define PMC_RES_VD9_LVD9_O_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_IF_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_IJ_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_IM_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_RES_VD9_LVD9_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD9)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD9_CONFIG_U32(value)               ( ((value) & PMC_FEE_VD9_RWBITS_MASK32 ) | PMC_FEE_VD9_RESBITS_MASK32 )
    #define PMC_FEE_VD9_FEE9_O_ENA_U32                  (PMC_FEE_VD9_FEE9_O_MASK32)
    #define PMC_FEE_VD9_FEE9_IF_ENA_U32                 (PMC_FEE_VD9_FEE9_IF_MASK32)
    #define PMC_FEE_VD9_FEE9_IJ_ENA_U32                 (PMC_FEE_VD9_FEE9_IJ_MASK32)
    #define PMC_FEE_VD9_FEE9_IM_ENA_U32                 (PMC_FEE_VD9_FEE9_IM_MASK32)
    #define PMC_FEE_VD9_FEE9_F_ENA_U32                  (PMC_FEE_VD9_FEE9_F_MASK32)
    #define PMC_FEE_VD9_FEE9_C_ENA_U32                  (PMC_FEE_VD9_FEE9_C_MASK32)
    #define PMC_FEE_VD9_FEE9_O_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_IF_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_IJ_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_IM_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_F_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_VD9_FEE9_C_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD10)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD10_CONFIG_U32(value)              ( ((value) & PMC_REE_VD10_RWBITS_MASK32 ) | PMC_REE_VD10_RESBITS_MASK32 )
    #define PMC_REE_VD10_LVD10_A_ENA_U32                (PMC_REE_VD10_LVD10_A_MASK32)
    #define PMC_REE_VD10_LVD10_F_ENA_U32                (PMC_REE_VD10_LVD10_F_MASK32)
    #define PMC_REE_VD10_LVD10_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD10_LVD10_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD10)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD10_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD10_RWBITS_MASK32 ) | PMC_FEE_VD10_RESBITS_MASK32 )
    #define PMC_FEE_VD10_FEE10_A_ENA_U32                (PMC_FEE_VD10_FEE10_A_MASK32)
    #define PMC_FEE_VD10_FEE10_F_ENA_U32                (PMC_FEE_VD10_FEE10_F_MASK32)
    #define PMC_FEE_VD10_FEE10_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD10_FEE10_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD12)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD12_CONFIG_U32(value)              ( ((value) & PMC_REE_VD12_RWBITS_MASK32 ) | PMC_REE_VD12_RESBITS_MASK32 )
    #define PMC_REE_VD12_HVD12_F_ENA_U32                (PMC_REE_VD12_HVD12_F_MASK32)
    #define PMC_REE_VD12_HVD12_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD12)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD12_CONFIG_U32(value)              ( ((value) & PMC_RES_VD12_RWBITS_MASK32 ) | PMC_RES_VD12_RESBITS_MASK32 )
    #define PMC_RES_VD12_HVD12_F_ENA_U32                (PMC_RES_VD12_HVD12_F_MASK32)
    #define PMC_RES_VD12_HVD12_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD12)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD12_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD12_RWBITS_MASK32 ) | PMC_FEE_VD12_RESBITS_MASK32 )
    #define PMC_FEE_VD12_FEE12_F_ENA_U32                (PMC_FEE_VD12_FEE12_F_MASK32)
    #define PMC_FEE_VD12_FEE12_F_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD13)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD13_CONFIG_U32(value)              ( ((value) & PMC_REE_VD13_RWBITS_MASK32 ) | PMC_REE_VD13_RESBITS_MASK32 )
    #define PMC_REE_VD13_LVD13_A_ENA_U32                (PMC_REE_VD13_LVD13_A_MASK32)
    #define PMC_REE_VD13_LVD13_IM_ENA_U32               (PMC_REE_VD13_LVD13_IM_MASK32)
    #define PMC_REE_VD13_LVD13_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD13_LVD13_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD13)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD13_CONFIG_U32(value)              ( ((value) & PMC_RES_VD13_RWBITS_MASK32 ) | PMC_RES_VD13_RESBITS_MASK32 )
    #define PMC_RES_VD13_LVD13_A_ENA_U32                (PMC_RES_VD13_LVD13_A_MASK32)
    #define PMC_RES_VD13_LVD13_IM_ENA_U32               (PMC_REE_VD13_LVD13_IM_MASK32)
    #define PMC_RES_VD13_LVD13_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_RES_VD13_LVD13_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD13)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD13_CONFIG_U32(value)              (((value) & PMC_FEE_VD13_RWBITS_MASK32 ) | PMC_FEE_VD13_RESBITS_MASK32)
    #define PMC_FEE_VD13_FEE13_A_ENA_U32                (PMC_FEE_VD13_FEE13_A_MASK32)
    #define PMC_FEE_VD13_FEE13_IM_ENA_U32               (PMC_FEE_VD13_FEE13_IM_MASK32)
    #define PMC_FEE_VD13_FEE13_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD13_FEE13_IM_DIS_U32               ((uint32)0x00000000U)


    /****************************************************/
    /***               (REE_VD14)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD14_CONFIG_U32(value)              ( ((value) & PMC_REE_VD14_RWBITS_MASK32 ) | PMC_REE_VD14_RESBITS_MASK32 )
    #define PMC_REE_VD14_LVD14_A_ENA_U32                (PMC_REE_VD14_LVD14_A_MASK32)
    #define PMC_REE_VD14_LVD14_IM_ENA_U32               (PMC_REE_VD14_LVD14_IM_MASK32)
    #define PMC_REE_VD14_LVD14_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD14_LVD14_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD14)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD14_CONFIG_U32(value)              ( ((value) & PMC_RES_VD14_RWBITS_MASK32 ) | PMC_RES_VD14_RESBITS_MASK32 )
    #define PMC_RES_VD14_LVD14_A_ENA_U32                (PMC_RES_VD14_LVD14_A_MASK32)
    #define PMC_RES_VD14_LVD14_IM_ENA_U32               (PMC_RES_VD14_LVD14_IM_MASK32)
    #define PMC_RES_VD14_LVD14_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_RES_VD14_LVD14_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD14)                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD14_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD14_RWBITS_MASK32 ) | PMC_FEE_VD14_RESBITS_MASK32 )
    #define PMC_FEE_VD14_FEE14_A_ENA_U32                (PMC_FEE_VD14_FEE14_A_MASK32)
    #define PMC_FEE_VD14_FEE14_IM_ENA_U32               (PMC_FEE_VD14_FEE14_IM_MASK32)
    #define PMC_FEE_VD14_FEE14_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD14_FEE14_IM_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_VD15)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_VD15_CONFIG_U32(value)              ( ((value) & PMC_REE_VD15_RWBITS_MASK32 ) | PMC_REE_VD15_RESBITS_MASK32 )
    #define PMC_REE_VD15_HVD15_A_ENA_U32                (PMC_REE_VD15_HVD15_A_MASK32)
    #define PMC_REE_VD15_HVD15_C_ENA_U32                (PMC_REE_VD15_HVD15_C_MASK32)
    #define PMC_REE_VD15_HVD15_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_REE_VD15_HVD15_C_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_VD15)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_VD15_CONFIG_U32(value)              ( ((value) & PMC_RES_VD15_RWBITS_MASK32 ) | PMC_RES_VD15_RESBITS_MASK32 )
    #define PMC_RES_VD15_HVD15_A_ENA_U32                (PMC_RES_VD15_HVD15_A_MASK32)
    #define PMC_RES_VD15_HVD15_C_ENA_U32                (PMC_RES_VD15_HVD15_C_MASK32)
    #define PMC_RES_VD15_HVD15_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_RES_VD15_HVD15_C_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (FEE_VD15)                     ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_VD15_CONFIG_U32(value)              ( ((value) & PMC_FEE_VD15_RWBITS_MASK32 ) | PMC_FEE_VD15_RESBITS_MASK32 )
    #define PMC_FEE_VD15_FEE15_A_ENA_U32                (PMC_FEE_VD15_FEE15_A_MASK32)
    #define PMC_FEE_VD15_FEE15_C_ENA_U32                (PMC_FEE_VD15_FEE15_C_MASK32)
    #define PMC_FEE_VD15_FEE15_A_DIS_U32                ((uint32)0x00000000U)
    #define PMC_FEE_VD15_FEE15_C_DIS_U32                ((uint32)0x00000000U)

    /****************************************************/
    /***               (REE_TD)                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_TD_CONFIG_U32(value)                ( ((value) & PMC_REE_TD_RWBITS_MASK32 ) | PMC_REE_TD_RESBITS_MASK32 )
    #define PMC_REE_TD_TEMP_3_ENA_U32                   (PMC_REE_TD_TEMP_3_MASK32)
    #define PMC_REE_TD_TEMP_2_ENA_U32                   (PMC_REE_TD_TEMP_2_MASK32)
    #define PMC_REE_TD_TEMP_0_ENA_U32                   (PMC_REE_TD_TEMP_0_MASK32)
    #define PMC_REE_TD_TEMP_3_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP_2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_TD_TEMP_0_DIS_U32                   ((uint32)0x00000000U)

    /****************************************************/
    /***               (RES_TD)                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_TD_CONFIG_U32(value)                ( ((value) & PMC_RES_TD_RWBITS_MASK32 ) | PMC_RES_TD_RESBITS_MASK32 )
    #define PMC_RES_TD_TEMP_3_ENA_U32                   (PMC_RES_TD_TEMP_3_MASK32)
    #define PMC_RES_TD_TEMP_2_ENA_U32                   (PMC_RES_TD_TEMP_2_MASK32)
    #define PMC_RES_TD_TEMP_0_ENA_U32                   (PMC_RES_TD_TEMP_0_MASK32)
    #define PMC_RES_TD_TEMP_3_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP_2_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_TD_TEMP_0_DIS_U32                   ((uint32)0x00000000U)

    /****************************************************/
    /***               (CTL_TD)                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_CONFIG_U32(value)                ( ((value) & PMC_CTL_TD_RWBITS_MASK32 ) | PMC_CTL_TD_RESBITS_MASK32 )
    #define PMC_CTL_TD_TS3IE_ENA_U32                    (PMC_CTL_TD_TS3IE_MASK32)
    #define PMC_CTL_TD_TS2IE_ENA_U32                    (PMC_CTL_TD_TS2IE_MASK32)
    #define PMC_CTL_TD_TS0IE_ENA_U32                    (PMC_CTL_TD_TS0IE_MASK32)
    #define PMC_CTL_TD_DOUT_ENA_U32                     (PMC_CTL_TD_DOUT_MASK32)
    #define PMC_CTL_TD_AOUT_ENA_U32                     (PMC_CTL_TD_AOUT_MASK32)
    #define PMC_CTL_TD_TS3IE_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS2IE_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS0IE_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_CTL_TD_DOUT_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_CTL_TD_AOUT_DIS_U32                     ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_TRIM_ADJ_OVER_U32(value)         ((uint32)( (uint32)((value) << (uint32)8U) & PMC_CTL_TD_TRIM_ADJ_OVER_MASK32 ))
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_TRIM_ADJ_UNDER_U32(value)        ((uint32)( (uint32)((value) << (uint32)2U) & PMC_CTL_TD_TRIM_ADJ_UNDER_MASK32 ))

    /****************************************************/
    /***               (FEE_TD)                       ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_FEE_TD_CONFIG_U32(value)                ( ((value) & PMC_FEE_TD_RWBITS_MASK32 ) | PMC_FEE_TD_RESBITS_MASK32 )
    #define PMC_FEE_TD_FEE_TS3_ENA_U32                  (PMC_FEE_TD_FEE_TS3_MASK32)
    #define PMC_FEE_TD_FEE_TS2_ENA_U32                  (PMC_FEE_TD_FEE_TS2_MASK32)
    #define PMC_FEE_TD_FEE_TS0_ENA_U32                  (PMC_FEE_TD_FEE_TS0_MASK32)
    #define PMC_FEE_TD_FEE_TS3_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_TD_FEE_TS2_DIS_U32                  ((uint32)0x00000000U)
    #define PMC_FEE_TD_FEE_TS0_DIS_U32                  ((uint32)0x00000000U)

    /****************************************************/
    /***               (VSIO)                         ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_VSIO_CONFIG_U32(value)                  ( ((value) & PMC_VSIO_RWBITS_MASK32 ) | PMC_VSIO_RESBITS_MASK32 )
    #define PMC_VSIO_VSIO_IF_ENA_U32                    (PMC_VSIO_VSIO_IF_MASK32)
    #define PMC_VSIO_VSIO_IJ_ENA_U32                    (PMC_VSIO_VSIO_IJ_MASK32)
    #define PMC_VSIO_VSIO_IM_ENA_U32                    (PMC_VSIO_VSIO_IM_MASK32)
    #define PMC_VSIO_VSIO_IF_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IJ_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_VSIO_VSIO_IM_DIS_U32                    ((uint32)0x00000000U)

#elif (IPV_MC == IPV_MC_04_06_01_00)
    /****************************************************/
    /***              PMC_TS_IER                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_TS_IER_CONFIG_U32(value)                ( ((value) & PMC_TS_IER_RWBITS_MASK32 ) | PMC_TS_IER_RESBITS_MASK32 )

    #define PMC_IER_TS_EN_ENA_U32                       (PMC_TS_IER_TS_EN_MASK32)
    #define PMC_IER_TS1_2IE_ENA_U32                     (PMC_TS_IER_TS1_2IE_MASK32)
    #define PMC_IER_TS1_0IE_ENA_U32                     (PMC_TS_IER_TS1_0IE_MASK32)
    #define PMC_IER_TS0_2IE_ENA_U32                     (PMC_TS_IER_TS0_2IE_MASK32)
    #define PMC_IER_TS0_0IE_ENA_U32                     (PMC_TS_IER_TS0_0IE_MASK32)
    #define PMC_IER_TS_EN_DIS_U32                       ((uint32)0x00000000U)
    #define PMC_IER_TS1_2IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_TS1_0IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_TS0_2IE_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_IER_TS0_0IE_DIS_U32                     ((uint32)0x00000000U)

    /****************************************************/
    /***              PMC_REE_TD                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_TD_CONFIG_U32(value)                ( ((value) & PMC_REE_TD_RWBITS_MASK32 ) | PMC_REE_TD_RESBITS_MASK32 )

    #define PMC_REE_TEMP1_2_ENA_U32                     (PMC_REE_TD_TEMP1_2_MASK32)
    #define PMC_REE_TEMP1_0_ENA_U32                     (PMC_REE_TD_TEMP1_0_MASK32)
    #define PMC_REE_TEMP0_2_ENA_U32                     (PMC_REE_TD_TEMP0_2_MASK32)
    #define PMC_REE_TEMP0_0_ENA_U32                     (PMC_REE_TD_TEMP0_0_MASK32)
    #define PMC_REE_TEMP1_2_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_REE_TEMP1_0_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_REE_TEMP0_2_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_REE_TEMP0_0_DIS_U32                     ((uint32)0x00000000U)

    /****************************************************/
    /***              PMC_RES_TD                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_TD_CONFIG_U32(value)                ( ((value) & PMC_RES_TD_RWBITS_MASK32 ) | PMC_RES_TD_RESBITS_MASK32 )

    #define PMC_RES_TEMP1_2_ENA_U32                     (PMC_RES_TD_TEMP1_2_MASK32)
    #define PMC_RES_TEMP1_0_ENA_U32                     (PMC_RES_TD_TEMP1_0_MASK32)
    #define PMC_RES_TEMP0_2_ENA_U32                     (PMC_RES_TD_TEMP0_2_MASK32)
    #define PMC_RES_TEMP0_0_ENA_U32                     (PMC_RES_TD_TEMP0_0_MASK32)
    #define PMC_RES_TEMP1_2_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_RES_TEMP1_0_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_RES_TEMP0_2_DIS_U32                     ((uint32)0x00000000U)
    #define PMC_RES_TEMP0_0_DIS_U32                     ((uint32)0x00000000U)

    /****************************************************/
    /***              PMC_CTL_TD                      ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_CTL_TD_CONFIG_U32(value)                ( ((value) & PMC_CTL_TD_RWBITS_MASK32 ) | PMC_CTL_TD_RESBITS_MASK32 )

    #define PMC_CTL_TD_TS1_DOUT_ENA_U32                 (PMC_CTL_TD_TS1_DOUT_EN_MASK32)
    #define PMC_CTL_TD_TS0_DOUT_ENA_U32                 (PMC_CTL_TD_TS0_DOUT_EN_MASK32)
    #define PMC_CTL_TD_TS1_DOUT_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS1_AOUT_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS0_DOUT_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_CTL_TD_TS0_AOUT_DIS_U32                 ((uint32)0x00000000U)


    /****************************************************/
    /***            PMC_LVD_HVD_INTR_ENB              ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_LVD_HVD_INTR_ENB_CONFIG_U32(value)      ( ((value) & PMC_LVD_HVD_INTR_ENB_RWBITS_MASK32 ) | PMC_LVD_HVD_INTR_ENB_RESBITS_MASK32 )

    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_PMC_ENA_U32            (PMC_LVD_HVD_INTR_ENB_PMC_ENABLE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_PMC_ENA_U32        (PMC_LVD_HVD_INTR_ENB_LVD_PMC_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_SAR_ADC_ENA_U32    (PMC_LVD_HVD_INTR_ENB_LVD_SAR_ADC_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_IO_ENA_U32         (PMC_LVD_HVD_INTR_ENB_LVD_IO_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_FLASH_ENA_U32      (PMC_LVD_HVD_INTR_ENB_HVD_FLASH_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_FLASH_ENA_U32      (PMC_LVD_HVD_INTR_ENB_LVD_FLASH_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_HV_ENA_U32         (PMC_LVD_HVD_INTR_ENB_HVD_HV_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_CORE_ENA_U32       (PMC_LVD_HVD_INTR_ENB_HVD_CORE_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_CORE_HOT_ENA_U32   (PMC_LVD_HVD_INTR_ENB_LVD_CORE_HOT_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_CORE_COLD_ENA_U32  (PMC_LVD_HVD_INTR_ENB_LVD_CORE_COLD_MASK32)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_PMC_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_PMC_DIS_U32        ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_SAR_ADC_DIS_U32    ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_IO_DIS_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_FLASH_DIS_U32      ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_FLASH_DIS_U32      ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_HV_DIS_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_HVD_CORE_DIS_U32       ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_CORE_HOT_DIS_U32   ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMC_LVD_HVD_INTR_ENB_LVD_CORE_COLD_DIS_U32  ((uint32)0x00000000U)

    /****************************************************/
    /***                      PMC_REE                 ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_REE_CONFIG_U32(value)                   ( ((value) & PMC_REE_RWBITS_MASK32 ) | PMC_REE_RESBITS_MASK32 )

    #define PMC_REE_LVD_SAR_ADC_ENA_U32                 (PMC_REE_LVD_SAR_ADC_MASK32)
    #define PMC_REE_HVD_FLASH_ENA_U32                   (PMC_REE_HVD_FLASH_MASK32)
    #define PMC_REE_HVD_HV_ENA_U32                      (PMC_REE_HVD_HV_MASK32)
    #define PMC_REE_HVD_CORE_ENA_U32                    (PMC_REE_HVD_CORE_MASK32)
    #define PMC_REE_LVD_CORE_COLD_ENA_U32               (PMC_REE_LVD_CORE_COLD_MASK32)
    #define PMC_REE_LVD_SAR_ADC_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_REE_HVD_FLASH_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_REE_HVD_HV_DIS_U32                      ((uint32)0x00000000U)
    #define PMC_REE_HVD_CORE_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_REE_LVD_CORE_COLD_DIS_U32               ((uint32)0x00000000U)

    /****************************************************/
    /***                      PMC_RES                 ***/
    /****************************************************/
    /** @violates @ref Mcu_MC_PCU_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define PMC_RES_CONFIG_U32(value)                   ( ((value) & PMC_RES_RWBITS_MASK32 ) | PMC_RES_RESBITS_MASK32 )

    #define PMC_RES_LVD_SAR_ADC_ENA_U32                 (PMC_RES_LVD_SAR_ADC_MASK32)
    #define PMC_RES_HVD_FLASH_ENA_U32                   (PMC_RES_HVD_FLASH_MASK32)
    #define PMC_RES_HVD_HV_ENA_U32                      (PMC_RES_HVD_HV_MASK32)
    #define PMC_RES_HVD_CORE_ENA_U32                    (PMC_RES_HVD_CORE_MASK32)
    #define PMC_RES_LVD_CORE_HOT_ENA_U32                (PMC_RES_LVD_CORE_HOT_MASK32)
    #define PMC_RES_LVD_CORE_COLD_ENA_U32               (PMC_RES_LVD_CORE_COLD_MASK32)
    #define PMC_RES_LVD_SAR_ADC_DIS_U32                 ((uint32)0x00000000U)
    #define PMC_RES_HVD_FLASH_DIS_U32                   ((uint32)0x00000000U)
    #define PMC_RES_HVD_HV_DIS_U32                      ((uint32)0x00000000U)
    #define PMC_RES_HVD_CORE_DIS_U32                    ((uint32)0x00000000U)
    #define PMC_RES_LVD_CORE_HOT_DIS_U32                ((uint32)0x00000000U)
    #define PMC_RES_LVD_CORE_COLD_DIS_U32               ((uint32)0x00000000U)

#endif /* (IPV_MC == IPV_MC_04_04_01_00) */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )

/**
* @brief            Configuration for PMU.
* @details          The power control unit (MC_PCU) acts as a bridge for mapping the PMU peripheral
 *                  to the MC_PCU address space.
*/
typedef struct
{
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00))
    VAR( uint32, MCU_VAR) u32Control;                /**< @brief Low/high voltage detection enable register. PMCCR register. */
#endif /* ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00)) */

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00))
    VAR( uint32, MCU_VAR) u32ResetInterruptEn;      /**< @brief Reset event interrupt enable register. PMC_IER register. */
#endif /* ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
           (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00)) */

#if (IPV_MC == IPV_MC_04_06_01_00)
    VAR( uint32, MCU_VAR) u32TempResetInterruptEn;  /**< @brief Temperature Sensor Interrupt Enable Register. PMC_TS_IER register. */
#endif /* (IPV_MC == IPV_MC_04_06_01_00) */

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_06_01_00))
    VAR( uint32, MCU_VAR) u32ResetEventEn;          /**< @brief Reset event enable register. PMC_REE_0 register. */
    VAR( uint32, MCU_VAR) u32ResetEventSel;         /**< @brief Reset event selection register. PMC_RES_0 register. */
    VAR( uint32, MCU_VAR) u32TempResEventEn;        /**< @brief Temperature reset event enable register. PMC_REE_TD register. */
    VAR( uint32, MCU_VAR) u32TempResEventSel;       /**< @brief Temperature reset event selection register. PMC_RES_TD register. */
    VAR( uint32, MCU_VAR) u32TempDetConfig;         /**< @brief Temperature detector configuration register. PMC_CTL_TD register. */
#endif /* ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_06_01_00)) */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    VAR( uint32, MCU_VAR) u32TemperatureInterruptControl;
    VAR( uint32, MCU_VAR) u32AfeDetectorInterruptControl;
    VAR( uint32, MCU_VAR) u32ResetEventEnable;
    VAR( uint32, MCU_VAR) u32ResetEventSelection;
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if (( IPV_MC == IPV_MC_04_00_15_15 ) || (IPV_MC == IPV_MC_04_01_00_00))
    VAR( uint32, MCU_VAR) u32VD3ResetEventEn;        /**< @brief Reset Event Enable Register (REE_VD3). */
    VAR( uint32, MCU_VAR) u32VD4ResetEventEn;        /**< @brief Reset Event Enable Register (REE_VD4). */
    VAR( uint32, MCU_VAR) u32VD7ResetEventEn;        /**< @brief Reset Event Enable Register (REE_VD7). */
    VAR( uint32, MCU_VAR) u32VD8ResetEventEn;        /**< @brief Reset Event Enable Register (REE_VD8). */
    VAR( uint32, MCU_VAR) u32VD9ResetEventEn;        /**< @brief Reset Event Enable Register (REE_VD9). */
    VAR( uint32, MCU_VAR) u32VD10ResetEventEn;       /**< @brief Reset Event Enable Register (REE_VD10). */
    VAR( uint32, MCU_VAR) u32VD12ResetEventEn;       /**< @brief Reset Event Enable Register (REE_VD12). */
    VAR( uint32, MCU_VAR) u32VD13ResetEventEn;       /**< @brief Reset Event Enable Register (REE_VD13). */
    VAR( uint32, MCU_VAR) u32VD14ResetEventEn;       /**< @brief Reset Event Enable Register (REE_VD14). */
    VAR( uint32, MCU_VAR) u32VD15ResetEventEn;       /**< @brief Reset Event Enable Register (REE_VD15). */
    VAR( uint32, MCU_VAR) u32VD3ResetEventSel;       /**< @brief Reset Event Select Register (RES_VD3). */
    VAR( uint32, MCU_VAR) u32VD4ResetEventSel;       /**< @brief Reset Event Select Register (RES_VD4). */
    VAR( uint32, MCU_VAR) u32VD7ResetEventSel;       /**< @brief Reset Event Select Register (RES_VD7). */
    VAR( uint32, MCU_VAR) u32VD8ResetEventSel;       /**< @brief Reset Event Select Register (RES_VD8). */
    VAR( uint32, MCU_VAR) u32VD9ResetEventSel;       /**< @brief Reset Event Select Register (RES_VD9). */
    VAR( uint32, MCU_VAR) u32VD12ResetEventSel;      /**< @brief Reset Event Select Register (RES_VD12). */
    VAR( uint32, MCU_VAR) u32VD13ResetEventSel;      /**< @brief Reset Event Select Register (RES_VD13). */
    VAR( uint32, MCU_VAR) u32VD14ResetEventSel;      /**< @brief Reset Event Select Register (RES_VD14). */
    VAR( uint32, MCU_VAR) u32VD15ResetEventSel;      /**< @brief Reset Event Select Register (RES_VD15). */
    VAR( uint32, MCU_VAR) u32VD3FccuEventEn;         /**< @brief Reset Event Enable Register (REE_VD3). */
    VAR( uint32, MCU_VAR) u32VD4FccuEventEn;         /**< @brief Reset Event Enable Register (REE_VD4). */
    VAR( uint32, MCU_VAR) u32VD7FccuEventEn;         /**< @brief Reset Event Enable Register (REE_VD7). */
    VAR( uint32, MCU_VAR) u32VD8FccuEventEn;         /**< @brief Reset Event Enable Register (REE_VD8). */
    VAR( uint32, MCU_VAR) u32VD9FccuEventEn;         /**< @brief Reset Event Enable Register (REE_VD9). */
    VAR( uint32, MCU_VAR) u32VD10FccuEventEn;        /**< @brief Reset Event Enable Register (REE_VD10). */
    VAR( uint32, MCU_VAR) u32VD12FccuEventEn;        /**< @brief Reset Event Enable Register (REE_VD12). */
    VAR( uint32, MCU_VAR) u32VD13FccuEventEn;        /**< @brief Reset Event Enable Register (REE_VD13). */
    VAR( uint32, MCU_VAR) u32VD14FccuEventEn;        /**< @brief Reset Event Enable Register (REE_VD14). */
    VAR( uint32, MCU_VAR) u32VD15FccuEventEn;        /**< @brief Reset Event Enable Register (REE_VD15). */
    VAR( uint32, MCU_VAR) u32VoltageSupply;          /**< @brief Voltage Supply for I/O Segments Register (VSIO). */
    VAR( uint32, MCU_VAR) u32TempResEventEn;         /**< @brief Reset Event Enable Register (REE_TD). */
    VAR( uint32, MCU_VAR) u32TempResEventSel;        /**< @brief Reset Event Select Register (RES_TD). */
    VAR( uint32, MCU_VAR) u32TempDetConfig;          /**< @brief Temperature Sensor Configuration Register (CTL_TD). */
    VAR( uint32, MCU_VAR) u32TempFccuEventEn;        /**< @brief Temperature Sensor Configuration Register (CTL_TD). */
#endif /* (( IPV_MC == IPV_MC_04_00_15_15 ) || (IPV_MC == IPV_MC_04_01_00_00)) */

} Mcu_MC_PCU_ConfigType;
#endif

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_MC_PCU_TYPES_H */

/** @} */
