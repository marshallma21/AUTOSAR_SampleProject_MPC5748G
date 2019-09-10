/**
*   @file    Mcu_MC_CGM_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from MC_CGM.
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


#ifndef MCU_MC_CGM_TYPES_H
#define MCU_MC_CGM_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_CGM_Types_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_MC_CGM_Types_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Mcu_MC_CGM_Types_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
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
#include "Soc_Ips.h"
#include "Reg_eSys_MC_CGM.h"
#include "Mcu_MC_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_MC_CGM_TYPES_VENDOR_ID                        43
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_TYPES_AR_RELEASE_MAJOR_VERSION         4
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_TYPES_AR_RELEASE_MINOR_VERSION         2
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_TYPES_AR_RELEASE_REVISION_VERSION      2
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_TYPES_SW_MAJOR_VERSION                 1
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_TYPES_SW_MINOR_VERSION                 0
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_TYPES_SW_PATCH_VERSION                 0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_MC_CGM_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_MC_CGM_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_MC_CGM_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_CGM_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_CGM_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_CGM_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_MC_CGM_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_MC_CGM_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_MC_CGM_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_CGM_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Reg_eSys_MC_CGM header file are from the same vendor */
#if (MCU_MC_CGM_TYPES_VENDOR_ID != REG_ESYS_MC_CGM_VENDOR_ID)
    #error "Mcu_MC_CGM_Types.h and Reg_eSys_MC_CGM.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_MC_CGM header file are of the same Autosar version */
#if ((MCU_MC_CGM_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_MC_CGM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_CGM_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_MC_CGM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_CGM_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_MC_CGM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_CGM_Types.h and Reg_eSys_MC_CGM.h are different"
#endif
/* Check if source file and Reg_eSys_MC_CGM header file are of the same Software version */
#if ((MCU_MC_CGM_TYPES_SW_MAJOR_VERSION != REG_ESYS_MC_CGM_SW_MAJOR_VERSION) || \
     (MCU_MC_CGM_TYPES_SW_MINOR_VERSION != REG_ESYS_MC_CGM_SW_MINOR_VERSION) || \
     (MCU_MC_CGM_TYPES_SW_PATCH_VERSION != REG_ESYS_MC_CGM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_CGM_Types.h and Reg_eSys_MC_CGM.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_CGM_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_CGM_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_CGM_Types.h and Soc_Ips.h are different"
    #endif
#endif

/* Check if source file and Mcu_MC_IPVersion header file are from the same vendor */
#if (MCU_MC_CGM_TYPES_VENDOR_ID != MCU_MC_IPVERSION_VENDOR_ID)
    #error "Mcu_MC_CGM_Types.h and Mcu_MC_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Autosar version */
#if ((MCU_MC_CGM_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_CGM_TYPES_AR_RELEASE_MINOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_CGM_TYPES_AR_RELEASE_REVISION_VERSION != MCU_MC_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_CGM_Types.h and Mcu_MC_IPVersion.h are different"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Software version */
#if ((MCU_MC_CGM_TYPES_SW_MAJOR_VERSION != MCU_MC_IPVERSION_SW_MAJOR_VERSION) || \
     (MCU_MC_CGM_TYPES_SW_MINOR_VERSION != MCU_MC_IPVERSION_SW_MINOR_VERSION) || \
     (MCU_MC_CGM_TYPES_SW_PATCH_VERSION != MCU_MC_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_CGM_Types.h and Mcu_MC_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/******************************************************************/
/************************    MC_CGM_PCS    ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_PCS_SDUR_U8(time)                ((time))
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_PCS_DIVC_U32(value)              ((uint32)(((value) & MC_CGM_PCS_DIVC_RWBITS_MASK32 ) | MC_CGM_PCS_DIVC_RESBITS_MASK32 ))
/* Configuration for CGM_PCS_DIVCn[INIT] field register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_PCS_DIVC_INIT_U32(value)         ((uint32)( (uint32)((value) << (uint32)16U) & MC_CGM_PCS_DIVC_INIT_U32_MASK32 ))
/* Configuration for CGM_PCS_DIVCn[rate] field register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_PCS_DIVC_RATE_U32(value)         ((uint32)((value) & MC_CGM_PCS_DIVC_RATE_U32_MASK32))
/* Configuration for CGM_PCS_DIVSn[DIVS] field register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_PCS_DIVS_U32(value)              ((uint32)( ((value) & MC_CGM_PCS_DIVS_RWBITS_MASK32 ) | MC_CGM_PCS_DIVS_RESBITS_MASK32 ))
/* Configuration for CGM_PCS_DIVEn[DIVE] field register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_PCS_DIVE_U32(value)              ((uint32)( ((value) & MC_CGM_PCS_DIVE_RWBITS_MASK32 ) | MC_CGM_PCS_DIVE_RESBITS_MASK32 ))

/***********************************************************/
/********************    MC_CGM_UPD     ********************/
/***********************************************************/

/***********************************************************/
/****************    MC_CGM_SC_DIV_RC     ******************/
/***********************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_SC_DIV_RC_U32(value)                     ((uint32)( ((value) & MC_CGM_SC_DIV_RC_RWBITS_MASK32 ) | MC_CGM_SC_DIV_RC_RESBITS_MASK32 ))

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_SC_DIV_RC_SYS_DIV_RATIO_CHNG_EN_U32  (MC_CGM_SC_DIV_RC_SYS_DIV_RATIO_CHNG_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_SC_DIV_RC_SYS_DIV_RATIO_CHNG_DIS_U32 ((uint32)0x00000000U)



/***********************************************************/
/****************   MC_CGM_DIV_UPD_TYPE   ******************/
/***********************************************************/

#if ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_05_00_00_10) || \
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_DIV_UPD_TYPE_U32(value)                  ((uint32)( ((value) & MC_CGM_DIV_UPD_TYPE_RWBITS_MASK32 ) | MC_CGM_DIV_UPD_TYPE_RESBITS_MASK32 ))
    
#elif (IPV_MC == IPV_MC_06_00_00_10)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_DIV_UPD_TYPE_U32(value)                  ((uint32)( ((value) & MC_CGM_0_DIV_UPD_TYPE_RWBITS_MASK32 ) | MC_CGM_0_DIV_UPD_TYPE_RESBITS_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_1_DIV_UPD_TYPE_U32(value)                  ((uint32)( ((value) & MC_CGM_1_DIV_UPD_TYPE_RWBITS_MASK32 ) | MC_CGM_1_DIV_UPD_TYPE_RESBITS_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_DIV_UPD_TYPE_U32(value)                  ((uint32)( ((value) & MC_CGM_2_DIV_UPD_TYPE_RWBITS_MASK32 ) | MC_CGM_2_DIV_UPD_TYPE_RESBITS_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_3_DIV_UPD_TYPE_U32(value)                  ((uint32)( ((value) & MC_CGM_3_DIV_UPD_TYPE_RWBITS_MASK32 ) | MC_CGM_3_DIV_UPD_TYPE_RESBITS_MASK32 ))
    
#endif /* ... */

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_SYS_UPD_TYPE_EN_U32      (MC_CGM_DIV_UPD_TYPE_SYS_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_SYS_UPD_TYPE_DIS_U32     ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX15_UPD_TYPE_EN_U32    (MC_CGM_DIV_UPD_TYPE_AUX15_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX15_UPD_TYPE_DIS_U32   ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX14_UPD_TYPE_EN_U32    (MC_CGM_DIV_UPD_TYPE_AUX14_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX14_UPD_TYPE_DIS_U32   ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX13_UPD_TYPE_EN_U32    (MC_CGM_DIV_UPD_TYPE_AUX13_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX13_UPD_TYPE_DIS_U32   ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX12_UPD_TYPE_EN_U32    (MC_CGM_DIV_UPD_TYPE_AUX12_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX12_UPD_TYPE_DIS_U32   ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX11_UPD_TYPE_EN_U32    (MC_CGM_DIV_UPD_TYPE_AUX11_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX11_UPD_TYPE_DIS_U32   ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX10_UPD_TYPE_EN_U32    (MC_CGM_DIV_UPD_TYPE_AUX10_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX10_UPD_TYPE_DIS_U32   ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX9_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX9_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX9_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX8_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX8_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX8_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX7_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX7_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX7_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX6_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX6_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX6_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX5_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX5_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX5_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX4_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX4_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX4_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX3_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX3_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX3_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX2_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX2_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX2_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX1_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX1_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX1_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX0_UPD_TYPE_EN_U32     (MC_CGM_DIV_UPD_TYPE_AUX0_UPD_TYPE_U32_MASK32)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_DIV_UPD_TYPE_AUX0_UPD_TYPE_DIS_U32    ((uint32)0x00000000U)


/***********************************************************/
/****************   MC_CGM_DIV_UPD_TRIG   ******************/
/***********************************************************/
#if ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_05_00_00_10) || \
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_06_00_00_10) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_DIV_UPD_TRIG_U32(value)          \
        ((uint32)(((value) & MC_CGM_DIV_UPD_TRIG_RWBITS_MASK32 ) | MC_CGM_DIV_UPD_TRIG_RESBITS_MASK32))
#endif

/******************************************************************/
/************************    CGM_SC_DC0    ************************/
/******************************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_07) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC0_DIVISOR_U32(value)    \
        ((uint32)(( (uint32)(( (value) - (uint32)1U ) << (uint32)16U ) & MC_CGM_SC_DC0_DIV_RWBITS_MASK32 ) | MC_CGM_SC_DC0_DIV_RESBITS_MASK32 ))
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || ... */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_07))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC1_DIVISOR_U32(value)    \
        ((uint32)(( (uint32)(( (value) - (uint32)1U ) << (uint32)16U ) & MC_CGM_SC_DC1_DIV_RWBITS_MASK32 ) | MC_CGM_SC_DC1_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC2_DIVISOR_U32(value)    \
        ((uint32)(( (uint32)(( (value) - (uint32)1U ) << (uint32)16U ) & MC_CGM_SC_DC2_DIV_RWBITS_MASK32 ) | MC_CGM_SC_DC2_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC3_DIVISOR_U32(value)    \
        ((uint32)(( (uint32)(( (value) - (uint32)1U ) << (uint32)16U ) & MC_CGM_SC_DC3_DIV_RWBITS_MASK32 ) | MC_CGM_SC_DC3_DIV_RESBITS_MASK32 ))
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_07) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC4_DIVISOR_U32(value)    \
        ((uint32)(( (uint32)(( (value) - (uint32)1U ) << (uint32)16U ) & MC_CGM_SC_DC4_DIV_RWBITS_MASK32 ) | MC_CGM_SC_DC4_DIV_RESBITS_MASK32 ))
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_05_00)) */

#if ((IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_07))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC5_DIVISOR_U32(value)    \
        ((uint32)(( (uint32)(( (value) - (uint32)1U ) << (uint32)16U ) & MC_CGM_SC_DC5_DIV_RWBITS_MASK32 ) | MC_CGM_SC_DC5_DIV_RESBITS_MASK32 ))
#endif

#if ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_10))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SC_DC0_U32(value)                ((uint32)( ((value) & MC_CGM_SC_DC0_RWBITS_MASK32 ) | MC_CGM_SC_DC0_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC0_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_SC_DC0_DIV_U32_MASK32))
    #define MC_CGM_SC_DC0_EN_U32                    (MC_CGM_SC_DC0_DE_U32_MASK32)
    #define MC_CGM_SC_DC0_DIS_U32                   ((uint32)0x00000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SC_DC1_U32(value)                ((uint32)( ((value) & MC_CGM_SC_DC1_RWBITS_MASK32 ) | MC_CGM_SC_DC1_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC1_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_SC_DC1_DIV_U32_MASK32))
    #define MC_CGM_SC_DC1_EN_U32                    (MC_CGM_SC_DC1_DE_U32_MASK32)
    #define MC_CGM_SC_DC1_DIS_U32                   ((uint32)0x00000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SC_DC2_U32(value)                ((uint32)( ((value) & MC_CGM_SC_DC2_RWBITS_MASK32 ) | MC_CGM_SC_DC2_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC2_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_SC_DC2_DIV_U32_MASK32))
    #define MC_CGM_SC_DC2_EN_U32                    (MC_CGM_SC_DC2_DE_U32_MASK32)
    #define MC_CGM_SC_DC2_DIS_U32                   ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_04_06_01_00) */

#if (IPV_MC == IPV_MC_05_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SC_DC3_U32(value)                ((uint32)( ((value) & MC_CGM_SC_DC3_RWBITS_MASK32 ) | MC_CGM_SC_DC3_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC3_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_SC_DC3_DIV_U32_MASK32))
    #define MC_CGM_SC_DC3_EN_U32                    (MC_CGM_SC_DC3_DE_U32_MASK32)
    #define MC_CGM_SC_DC3_DIS_U32                   ((uint32)0x00000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SC_DC4_U32(value)                ((uint32)( ((value) & MC_CGM_SC_DC4_RWBITS_MASK32 ) | MC_CGM_SC_DC4_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC4_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_SC_DC4_DIV_U32_MASK32))
    #define MC_CGM_SC_DC4_EN_U32                    (MC_CGM_SC_DC4_DE_U32_MASK32)
    #define MC_CGM_SC_DC4_DIS_U32                   ((uint32)0x00000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SC_DC5_U32(value)                ((uint32)( ((value) & MC_CGM_SC_DC5_RWBITS_MASK32 ) | MC_CGM_SC_DC5_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC5_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_SC_DC5_DIV_U32_MASK32))
    #define MC_CGM_SC_DC5_EN_U32                    (MC_CGM_SC_DC5_DE_U32_MASK32)
    #define MC_CGM_SC_DC5_DIS_U32                   ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_05_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SC_DC6_U32(value)                ((uint32)( ((value) & MC_CGM_SC_DC6_DIV_RWBITS_MASK32 ) | MC_CGM_SC_DC6_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_SYSCLK_DC6_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_SC_DC6_DIV_U32_MASK32))
    #define MC_CGM_SC_DC6_EN_U32                    (MC_CGM_SC_DC6_DE_U32_MASK32)
    #define MC_CGM_SC_DC6_DIS_U32                   ((uint32)0x00000000U)
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_SC_DC0_U32(value)                ((uint32)( ((value) & MC_CGM_0_SC_DC0_DIV_RWBITS_MASK32 ) | MC_CGM_0_SC_DC0_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_SYSCLK_DC0_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_0_SC_DC0_DIV_U32_MASK32))
    #define MC_CGM_0_SC_DC0_EN_U32                    (MC_CGM_0_SC_DC0_DE_U32_MASK32)
    #define MC_CGM_0_SC_DC0_DIS_U32                   ((uint32)0x00000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_SC_DC1_U32(value)                ((uint32)( ((value) & MC_CGM_0_SC_DC1_DIV_RWBITS_MASK32 ) | MC_CGM_0_SC_DC1_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_SYSCLK_DC1_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_0_SC_DC1_DIV_U32_MASK32))
    #define MC_CGM_0_SC_DC1_EN_U32                    (MC_CGM_0_SC_DC1_DE_U32_MASK32)
    #define MC_CGM_0_SC_DC1_DIS_U32                   ((uint32)0x00000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_SC_DC2_U32(value)                ((uint32)( ((value) & MC_CGM_0_SC_DC2_DIV_RWBITS_MASK32 ) | MC_CGM_0_SC_DC2_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_SYSCLK_DC2_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_0_SC_DC2_DIV_U32_MASK32))
    #define MC_CGM_0_SC_DC2_EN_U32                    (MC_CGM_0_SC_DC2_DE_U32_MASK32)
    #define MC_CGM_0_SC_DC2_DIS_U32                   ((uint32)0x00000000U)
    
        /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_1_SC_DC0_U32(value)                ((uint32)( ((value) & MC_CGM_1_SC_DC0_DIV_RWBITS_MASK32 ) | MC_CGM_1_SC_DC0_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_1_SYSCLK_DC0_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_1_SC_DC0_DIV_U32_MASK32))
    #define MC_CGM_1_SC_DC0_EN_U32                    (MC_CGM_1_SC_DC0_DE_U32_MASK32)
    #define MC_CGM_1_SC_DC0_DIS_U32                   ((uint32)0x00000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_1_SC_DC1_U32(value)                ((uint32)( ((value) & MC_CGM_1_SC_DC1_DIV_RWBITS_MASK32 ) | MC_CGM_1_SC_DC1_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_1_SYSCLK_DC1_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_1_SC_DC1_DIV_U32_MASK32))
    #define MC_CGM_1_SC_DC1_EN_U32                    (MC_CGM_1_SC_DC1_DE_U32_MASK32)
    #define MC_CGM_1_SC_DC1_DIS_U32                   ((uint32)0x00000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_1_SC_DC2_U32(value)                ((uint32)( ((value) & MC_CGM_1_SC_DC2_DIV_RWBITS_MASK32 ) | MC_CGM_1_SC_DC2_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_1_SYSCLK_DC2_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_1_SC_DC2_DIV_U32_MASK32))
    #define MC_CGM_1_SC_DC2_EN_U32                    (MC_CGM_1_SC_DC2_DE_U32_MASK32)
    #define MC_CGM_1_SC_DC2_DIS_U32                   ((uint32)0x00000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_SC_DC0_U32(value)                ((uint32)( ((value) & MC_CGM_2_SC_DC0_DIV_RWBITS_MASK32 ) | MC_CGM_2_SC_DC0_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_SYSCLK_DC0_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_2_SC_DC0_DIV_U32_MASK32))
    #define MC_CGM_2_SC_DC0_EN_U32                    (MC_CGM_2_SC_DC0_DE_U32_MASK32)
    #define MC_CGM_2_SC_DC0_DIS_U32                   ((uint32)0x00000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_3_SC_DC0_U32(value)                ((uint32)( ((value) & MC_CGM_3_SC_DC0_DIV_RWBITS_MASK32 ) | MC_CGM_3_SC_DC0_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_3_SYSCLK_DC0_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_3_SC_DC0_DIV_U32_MASK32))
    #define MC_CGM_3_SC_DC0_EN_U32                    (MC_CGM_3_SC_DC0_DE_U32_MASK32)
    #define MC_CGM_3_SC_DC0_DIS_U32                   ((uint32)0x00000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_3_SC_DC1_U32(value)                ((uint32)( ((value) & MC_CGM_3_SC_DC1_DIV_RWBITS_MASK32 ) | MC_CGM_3_SC_DC1_DIV_RESBITS_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_3_SYSCLK_DC1_DIVISOR_U32(value)    ((uint32)((uint32)(((value) - (uint32)1U) << (uint32)16U) & MC_CGM_3_SC_DC1_DIV_U32_MASK32))
    #define MC_CGM_3_SC_DC1_EN_U32                    (MC_CGM_3_SC_DC1_DE_U32_MASK32)
    #define MC_CGM_3_SC_DC1_DIS_U32                   ((uint32)0x00000000U)
#endif

/******************************************************************/
/************************   CGM_CLKOUT1    ************************/
/******************************************************************/
/* Configuration for CGM_CLKOUT1_SC register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_CLKOUT1_U32(value)               ((uint32)( ((value) & MC_CGM_CLKOUT1_SC_SELCTL_MASK32 ) | MC_CGM_CLKOUT1_SC_RESBITS_MASK32 ))

#define MC_CGM_CLKOUT1_SOURCE_FXOSC_U32         ((uint32)0x00000000U)
#define MC_CGM_CLKOUT1_SOURCE_FIRC_U32          ((uint32)0x01000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_CLKOUT1_SOURCE_SXOSC_UNDIV_U32   ((uint32)0x02000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_CLKOUT1_SOURCE_SIRC_UNDIV_U32    ((uint32)0x03000000U)
#define MC_CGM_CLKOUT1_SOURCE_RTC_U32           ((uint32)0x04000000U)
#define MC_CGM_CLKOUT1_SOURCE_LPU_U32           ((uint32)0x05000000U)
#define MC_CGM_CLKOUT1_SOURCE_Z2_U32            ((uint32)0x06000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_CLKOUT1_SOURCE_FXOSC_ANALOG_U32  ((uint32)0x07000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_CLKOUT1_SOURCE_FXOSC_UNDIV_U32   ((uint32)0x08000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_CLKOUT1_SOURCE_FIRC_UNDIV_U32    ((uint32)0x09000000U)
#define MC_CGM_CLKOUT1_SOURCE_SXOSC_U32         ((uint32)0x0A000000U)
#define MC_CGM_CLKOUT1_SOURCE_SIRC_U32          ((uint32)0x0B000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_CLKOUT1_SOURCE_CAN0_CHI_U32      ((uint32)0x0C000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_CLKOUT1_SOURCE_CAN0_PE_U32       ((uint32)0x0D000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
#define MC_CGM_CLKOUT1_SOURCE_PLL0_PHI0_U32     ((uint32)0x0E000000U)

/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_CLKOUT1_DC_U32(value)          ((uint32)((value) & ( MC_CGM_CLKOUT1_DC_DE_MASK32 | MC_CGM_CLKOUT1_DC_DIV_MASK32 )))
#define MC_CGM_CLKOUT1_DC_EN_U32              (MC_CGM_CLKOUT1_DC_DE_MASK32)
#define MC_CGM_CLKOUT1_DC_DIS_U32             ((uint32)0x00000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_CLKOUT1_DIV_U32(div)           ((uint32)( ((div) - (uint32)1U) << (uint32)16U))

/******************************************************************/
/************************    CGM_AC0_SC[SELCTL] *******************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK0_U32(value)               ((uint32)( ((value) & MC_CGM_AC0_SC_SELCTL_MASK32 ) | MC_CGM_AC0_SC_RESBITS_MASK32 ))
#define MC_CGM_AUXCLK0_SOURCE_IRC_U32           ((uint32)0x00000000U)
#define MC_CGM_AUXCLK0_SOURCE_XTAL_U32          ((uint32)0x01000000U)
#define MC_CGM_AUXCLK0_SOURCE_PLL0_U32          ((uint32)0x02000000U)
#define MC_CGM_AUXCLK0_SOURCE_SDPLL_U32         ((uint32)0x03000000U)
#define MC_CGM_AUXCLK0_SOURCE_PLL1_U32          ((uint32)0x04000000U)
#define MC_CGM_AUXCLK0_SOURCE_FIRC_U32          ((uint32)0x00000000U)
#define MC_CGM_AUXCLK0_SOURCE_FXOSC_U32         ((uint32)0x01000000U)

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK0_U32(value)               ((uint32) ((value) & MC_CGM_0_AC0_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK0_SOURCE_FIRC_U32           ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK0_SOURCE_XOSC_U32           ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK0_SOURCE_DDR_PLL_DFS1_U32   ((uint32)0x05000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AUXCLK0_U32(value)               ((uint32) ((value) & MC_CGM_0_AC2_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK0_SOURCE_FIRC_U32               ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK0_SOURCE_XOSC_U32               ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK0_SOURCE_PERIPH_PLL_DIV5_U32    ((uint32)0x03000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK0_SOURCE_EXTERNAL_PAD_U32       ((uint32)0x07000000U)
#endif
/******************************************************************/
/************************    CGM_AC0_DC0   ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AC0_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC0_DC0_DE_MASK32 | MC_CGM_AC0_DC0_DIV_MASK32 )))
#define MC_CGM_AUXCLK0_DIV0_EN_U32              (MC_CGM_AC0_DC0_DE_MASK32)
#define MC_CGM_AUXCLK0_DIV0_DIS_U32             ((uint32)0x00000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK0_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC0_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC0_DC0_DE_MASK32 | MC_CGM_0_AC0_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK0_DIV0_EN_U32              (MC_CGM_0_AC0_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK0_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK0_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AC0_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_2_AC0_DC0_DE_MASK32 | MC_CGM_2_AC0_DC0_DIV_MASK32 )))
    #define MC_CGM_2_AUXCLK0_DIV0_EN_U32              (MC_CGM_2_AC0_DC0_DE_MASK32)
    #define MC_CGM_2_AUXCLK0_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AUXCLK0_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif
/******************************************************************/
/************************    CGM_AC0_DC1   ************************/
/******************************************************************/
/* Configuration for CGM_AC0_DC1 register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AC0_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC0_DC1_DE_MASK32 | MC_CGM_AC0_DC1_DIV_MASK32 )))
#define MC_CGM_AUXCLK0_DIV1_EN_U32              (MC_CGM_AC0_DC1_DE_MASK32)
#define MC_CGM_AUXCLK0_DIV1_DIS_U32             ((uint32)0x00000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK0_DIV1_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))

/******************************************************************/
/************************    CGM_AC0_DC2   ************************/
/******************************************************************/
/* Configuration for CGM_AC0_DC2 register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AC0_DC2_U32(value)               ((uint32)((value) & ( MC_CGM_AC0_DC2_DE_MASK32 | MC_CGM_AC0_DC2_DIV_MASK32 )))
#define MC_CGM_AUXCLK0_DIV2_EN_U32              (MC_CGM_AC0_DC2_DE_MASK32)
#define MC_CGM_AUXCLK0_DIV2_DIS_U32             ((uint32)0x00000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK0_DIV2_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))

/******************************************************************/
/************************    CGM_AC0_DC3   ************************/
/******************************************************************/
/* Configuration for CGM_AC0_DC3 register. */
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC0_DC3_U32(value)               ((uint32)((value) & ( MC_CGM_AC0_DC3_DE_MASK32 | MC_CGM_AC0_DC3_DIV_MASK32 | MC_CGM_AC0_DC3_DIV_FMT_MASK32)))
    #define MC_CGM_AUXCLK0_DIV3_EN_U32              (MC_CGM_AC0_DC3_DE_MASK32)
    #define MC_CGM_AUXCLK0_DIV3_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK0_DIV3_U32(div, fmt)       ((uint32)((((div) - (uint32)1U) << (uint32)16U) | (fmt)))
#endif

/******************************************************************/
/************************    CGM_AC0_DC4   ************************/
/******************************************************************/
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00))
    /* Configuration for CGM_AC0_DC4 register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC0_DC4_U32(value)               ((uint32)((value) & ( MC_CGM_AC0_DC4_DE_MASK32 | MC_CGM_AC0_DC4_DIV_MASK32 )))
    #define MC_CGM_AUXCLK0_DIV4_EN_U32              (MC_CGM_AC0_DC4_DE_MASK32)
    #define MC_CGM_AUXCLK0_DIV4_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK0_DIV4_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif




/******************************************************************/
/************************    CGM_AC1       ************************/
/******************************************************************/
/* Configuration for CGM_AC1_SC register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK1_U32(value)               ((uint32)( ((value) & MC_CGM_AC1_SC_SELCTL_MASK32 ) | MC_CGM_AC1_SC_RESBITS_MASK32 ))
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_CGM_AUXCLK1_SOURCE_IRC_U32           ((uint32)0x00000000U)
#endif
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_CGM_AUXCLK1_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK1_SOURCE_PLL0_U32          ((uint32)0x02000000U)
#endif
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AUXCLK1_SOURCE_SDPLL_U32         ((uint32)0x03000000U)
    #define MC_CGM_AUXCLK1_SOURCE_PLL1_U32          ((uint32)0x04000000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define MC_CGM_AUXCLK1_SOURCE_DRCLK_U32         ((uint32)0x05000000U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_CGM_AUXCLK1_SOURCE_SIPI_CLK_U32      ((uint32)0x07000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK1_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK1_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK1_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK1_SOURCE_PLL1_U32          ((uint32)0x05000000U)
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK1_U32(value)               ((uint32) ((value) & MC_CGM_0_AC1_SC_SELCTL_MASK32))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK1_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK1_SOURCE_XOSC_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK1_SOURCE_DDR_PLL_DFS2_U32  ((uint32)0x05000000U)
#endif

/* Configuration for CGM_AC1_DC0 register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AC1_DC0_U32(value)                   ((uint32)((value) & ( MC_CGM_AC1_DC0_DE_MASK32 | MC_CGM_AC1_DC0_DIV_MASK32 )))
#define MC_CGM_AUXCLK1_DIV0_EN_U32                  (MC_CGM_AC1_DC0_DE_MASK32)
#define MC_CGM_AUXCLK1_DIV0_DIS_U32                 ((uint32)0x00000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK1_DIV0_U32(div)                ((uint32)( ((div) - (uint32)1U) << (uint32)16U))

/* Configuration for CGM_AC1_DC1 register. */
#if (IPV_MC == IPV_MC_04_04_01_00)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC1_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC1_DC1_DE_MASK32 | MC_CGM_AC1_DC1_DIV_MASK32 )))
    #define MC_CGM_AUXCLK1_DIV1_EN_U32              (MC_CGM_AC1_DC1_DE_MASK32)
    #define MC_CGM_AUXCLK1_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK1_DIV1_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif /* (IPV_MC != IPV_MC_04_06_01_00) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC1_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC1_DC0_DE_MASK32 | MC_CGM_0_AC1_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK1_DIV0_EN_U32              (MC_CGM_0_AC1_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK1_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK1_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif
/******************************************************************/
/************************    CGM_AC2       ************************/
/******************************************************************/
/* Configuration for CGM_AC2_SC register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK2_U32(value)                   ((uint32)( ( (value) & MC_CGM_AC2_SC_SELCTL_MASK32 ) | MC_CGM_AC2_SC_RESBITS_MASK32 ))
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
    (IPV_MC == IPV_MC_04_06_05_00) )
    #define MC_CGM_AUXCLK2_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK2_SOURCE_PLL0_U32          ((uint32)0x02000000U)
#endif
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AUXCLK2_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK2_SOURCE_SDPLL_U32         ((uint32)0x03000000U)
    #define MC_CGM_AUXCLK2_SOURCE_PLL1_U32          ((uint32)0x04000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */
#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK2_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK2_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK2_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK2_SOURCE_PLL1_U32          ((uint32)0x05000000U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_CGM_AUXCLK2_SOURCE_F40_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK2_SOURCE_EXTAL_U32        ((uint32)0x01000000U)
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK2_U32(value)                   ((uint32)((value) & MC_CGM_0_AC2_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK2_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK2_SOURCE_XOSC_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK2_SOURCE_DDR_PLL_DFS3_U32  ((uint32)0x05000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AUXCLK2_U32(value)                   ((uint32)((value) & MC_CGM_2_AC2_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK2_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK2_SOURCE_XOSC_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK2_SOURCE_ENET_PLL_U32      ((uint32)0x04000000U)
#endif

/* Configuration for CGM_AC2_DC0 register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AC2_DC0_U32(value)                   ((uint32)((value) & ( MC_CGM_AC2_DC0_DE_MASK32 | MC_CGM_AC2_DC0_DIV_MASK32 )))
#define MC_CGM_AUXCLK2_DIV0_EN_U32                  (MC_CGM_AC2_DC0_DE_MASK32)
#define MC_CGM_AUXCLK2_DIV0_DIS_U32                 ((uint32)0x00000000U)
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK2_DIV0_U32(div)                ((uint32)( ((div) - (uint32)1U) << (uint32)16U))

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_05_00_00_10))
    /* Configuration for CGM_AC2_DC0 register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC2_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC2_DC1_DE_MASK32 | MC_CGM_AC2_DC1_DIV_MASK32 )))
    #define MC_CGM_AUXCLK2_DIV1_EN_U32              (MC_CGM_AC2_DC1_DE_MASK32)
    #define MC_CGM_AUXCLK2_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK2_DIV1_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC2_DC0_U32(value)                   ((uint32)((value) & ( MC_CGM_0_AC2_DC0_DE_MASK32 | MC_CGM_0_AC2_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK2_DIV0_EN_U32                  (MC_CGM_0_AC2_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK2_DIV0_DIS_U32                 ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK2_DIV0_U32(div)                ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AC2_DC0_U32(value)                   ((uint32)((value) & ( MC_CGM_2_AC2_DC0_DE_MASK32 | MC_CGM_2_AC2_DC0_DIV_MASK32 )))
    #define MC_CGM_2_AUXCLK2_DIV0_EN_U32                  (MC_CGM_2_AC2_DC0_DE_MASK32)
    #define MC_CGM_2_AUXCLK2_DIV0_DIS_U32                 ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AUXCLK2_DIV0_U32(div)                ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif

/******************************************************************/
/************************    CGM_AC3_SC    ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK3_U32(value)                   ((uint32)( ((value) & MC_CGM_AC3_SC_SELCTL_MASK32 ) | MC_CGM_AC3_SC_RESBITS_MASK32 ))
#define MC_CGM_AUXCLK3_SOURCE_IRC_U32               ((uint32)0x00000000U)
#define MC_CGM_AUXCLK3_SOURCE_XTAL_U32              ((uint32)0x01000000U)
#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK3_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK3_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK3_SOURCE_SIRC_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK3_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK3_SOURCE_PLL1_U32          ((uint32)0x05000000U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_CGM_AUXCLK3_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK3_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
#endif


#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK3_U32(value)                   ((uint32) ((value) & MC_CGM_0_AC3_SC_SELCTL_MASK32 ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK3_SOURCE_FIRC_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK3_SOURCE_XOSC_U32                ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK3_SOURCE_SYS6_CLK_U32            ((uint32)0x08000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK3_SOURCE_PERIPH_PLL_DIV3_U32     ((uint32)0x03000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AUXCLK3_U32(value)                   ((uint32) ((value) & MC_CGM_2_AC3_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK3_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK3_SOURCE_XOSC_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK3_SOURCE_EXTERNAL_PAD_U32  ((uint32)0x07000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK3_SOURCE_SYS6_CLK_U32      ((uint32)0x08000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK3_SOURCE_PERI_CLK_U32      ((uint32)0x0A000000U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC3_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC3_DC0_DE_MASK32 | MC_CGM_AC3_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK3_DIV0_EN_U32              (MC_CGM_AC3_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK3_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK3_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC3_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC3_DC0_DE_MASK32 | MC_CGM_0_AC3_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK3_DIV0_EN_U32              (MC_CGM_0_AC3_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK3_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK3_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AC3_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_2_AC3_DC0_DE_MASK32 | MC_CGM_2_AC3_DC0_DIV_MASK32 )))
    #define MC_CGM_2_AUXCLK3_DIV0_EN_U32              (MC_CGM_2_AC3_DC0_DE_MASK32)
    #define MC_CGM_2_AUXCLK3_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AUXCLK3_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif

/******************************************************************/
/************************    CGM_AC4_SC    ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK4_U32(value)                   ((uint32)( ((value) & MC_CGM_AC4_SC_SELCTL_MASK32 ) | MC_CGM_AC4_SC_RESBITS_MASK32 ))
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define MC_CGM_AUXCLK4_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK4_SOURCE_PLL0_U32          ((uint32)0x03000000U)
#elif (IPV_MC == IPV_MC_04_03_00_00)
    #define MC_CGM_AUXCLK4_SOURCE_XTAL_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK4_SOURCE_PLL0_U32          ((uint32)0x01000000U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_CGM_AUXCLK4_SOURCE_PLL0_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK4_SOURCE_XTAL_U32          ((uint32)0x01000000U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_CGM_AUXCLK4_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK4_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK4_SOURCE_PLL0_U32          ((uint32)0x03000000U)
#elif (IPV_MC == IPV_MC_04_04_01_00)
    #define MC_CGM_AUXCLK4_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK4_SOURCE_PLL0_PHI1_U32     ((uint32)0x03000000U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK4_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK4_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK4_SOURCE_SIRC_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK4_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK4_SOURCE_PLL1_U32          ((uint32)0x05000000U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_CGM_AUXCLK4_SOURCE_F40_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK4_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK4_U32(value)                   ((uint32) ((value) & MC_CGM_0_AC4_SC_SELCTL_MASK32 ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK4_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK4_SOURCE_XOSC_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK4_SOURCE_EXTERNAL_PAD_U32  ((uint32)0x07000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK4_SOURCE_SYS6_CLK_U32      ((uint32)0x08000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK4_SOURCE_PERI_CLK_U32      ((uint32)0x0A000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AUXCLK4_U32(value)                   ((uint32) ((value) & MC_CGM_2_AC4_SC_SELCTL_MASK32 ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK4_SOURCE_FIRC_U32           ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK4_SOURCE_XOSC_U32           ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK4_SOURCE_ARM_PLL_DFS1_U32   ((uint32)0x02000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK4_SOURCE_ENET_PLL_U32       ((uint32)0x04000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK4_SOURCE_DDR_PLL_DFS2_U32   ((uint32)0x05000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_2_AUXCLK4_SOURCE_VIDEO_PLL_DIV2_U32 ((uint32)0x09000000U)
    
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC4_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC4_DC0_DE_MASK32 | MC_CGM_AC4_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK4_DIV0_EN_U32              (MC_CGM_AC4_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK4_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK4_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC4_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC4_DC0_DE_MASK32 | MC_CGM_0_AC4_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK4_DIV0_EN_U32              (MC_CGM_0_AC4_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK4_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK4_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AC4_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_2_AC4_DC0_DE_MASK32 | MC_CGM_2_AC4_DC0_DIV_MASK32 )))
    #define MC_CGM_2_AUXCLK4_DIV0_EN_U32              (MC_CGM_2_AC4_DC0_DE_MASK32)
    #define MC_CGM_2_AUXCLK4_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_2_AUXCLK4_DIV0_U32(div)            ((uint32)( ((div) - (uint32)1U) << (uint32)16U))
#endif

/******************************************************************/
/************************    CGM_AC5_SC    ************************/
/******************************************************************/
/* Configuration for CGM_AC5_SC[SELCTL] field register. */
#if (IPV_MC == IPV_MC_04_04_01_00)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_U32(value)               ((uint32)( ((value) & MC_CGM_AC5_SC_SELCTL_MASK32 ) | MC_CGM_AC5_SC_RESBITS_MASK32 ))
    #define MC_CGM_AUXCLK5_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK5_SOURCE_PLL0_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK5_SOURCE_DIGRF_U32         ((uint32)0x05000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC5_DC0_DE_MASK32 | MC_CGM_AC5_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK5_DIV0_EN_U32              (MC_CGM_AC5_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK5_DIV0_DIS_U32             ((uint32)0x00000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

#elif (IPV_MC == IPV_MC_04_06_01_00)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_U32(value)               ((uint32)( ((value) & MC_CGM_AC5_SC_SELCTL_MASK32 ) | MC_CGM_AC5_SC_RESBITS_MASK32 ))
    #define MC_CGM_AUXCLK5_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK5_SOURCE_PLL0_U32          ((uint32)0x02000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC5_DC0_DE_MASK32 | MC_CGM_AC5_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK5_DIV0_EN_U32              (MC_CGM_AC5_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK5_DIV0_DIS_U32             ((uint32)0x00000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC5_DC1_DE_MASK32 | MC_CGM_AC5_DC1_DIV_MASK32 )))
    #define MC_CGM_AUXCLK5_DIV1_EN_U32              (MC_CGM_AC5_DC1_DE_MASK32)
    #define MC_CGM_AUXCLK5_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

#elif (( IPV_MC == IPV_MC_04_00_15_15 ) || (IPV_MC == IPV_MC_04_01_00_00))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC5_DC0_DE_MASK32 | MC_CGM_AC5_DC0_DIV_MASK32 | MC_CGM_AC5_DC0_DIV_FMT_MASK32)))

    #define MC_CGM_AUXCLK5_DIV0_EN_U32              (MC_CGM_AC5_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK5_DIV0_DIS_U32             ((uint32)0x00000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_DIV0_U32(div, fmt)       ((uint32)((((div) - (uint32)1U) << (uint32)16U) | (fmt)))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC5_DC1_DE_MASK32 | MC_CGM_AC5_DC1_DIV_MASK32 )))
    #define MC_CGM_AUXCLK5_DIV1_EN_U32              (MC_CGM_AC5_DC1_DE_MASK32)
    #define MC_CGM_AUXCLK5_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_DC2_U32(value)               ((uint32)((value) & ( MC_CGM_AC5_DC2_DE_MASK32 | MC_CGM_AC5_DC2_DIV_MASK32 )))
    #define MC_CGM_AUXCLK5_DIV2_EN_U32              (MC_CGM_AC5_DC2_DE_MASK32)
    #define MC_CGM_AUXCLK5_DIV2_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_DIV2_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_U32(value)               ((uint32)( ((value) & MC_CGM_AC5_SC_SELCTL_MASK32 ) | MC_CGM_AC5_SC_RESBITS_MASK32 ))
    #define MC_CGM_AUXCLK5_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK5_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK5_SOURCE_SIRC_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK5_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK5_SOURCE_PLL1_U32          ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK5_SOURCE_PLL2_U32          ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK5_SOURCE_PLL3_U32          ((uint32)0x07000000U)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC5_DC0_DE_MASK32 | MC_CGM_AC5_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK5_DIV0_EN_U32              (MC_CGM_AC5_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK5_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC5_DC1_DE_MASK32 | MC_CGM_AC5_DC1_DIV_MASK32 )))
    #define MC_CGM_AUXCLK5_DIV1_EN_U32              (MC_CGM_AC5_DC1_DE_MASK32)
    #define MC_CGM_AUXCLK5_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK5_U32(value)               ((uint32)( ((value) & MC_CGM_AC5_SC_SELCTL_MASK32 ) | MC_CGM_AC5_SC_RESBITS_MASK32 ))
    #define MC_CGM_AUXCLK5_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK5_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    
#elif (IPV_MC == IPV_MC_06_00_00_10)

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK5_U32(value)                     ((uint32)((value) & MC_CGM_0_AC5_SC_SELCTL_MASK32 ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK5_SOURCE_FIRC_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK5_SOURCE_XOSC_U32                ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK5_SOURCE_PERIPH_PLL_DIV5_U32     ((uint32)0x03000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC5_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC5_DC0_DE_MASK32 | MC_CGM_0_AC5_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK5_DIV0_EN_U32              (MC_CGM_0_AC5_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK5_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK5_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC5_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC5_DC1_DE_MASK32 | MC_CGM_0_AC5_DC1_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK5_DIV1_EN_U32              (MC_CGM_0_AC5_DC1_DE_MASK32)
    #define MC_CGM_0_AUXCLK5_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK5_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
    
#endif /* (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC0_U32(value)              ((uint32)((value) & ( MC_CGM_AC5_CDC0_DE_MASK32 | MC_CGM_AC5_CDC0_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC0_EN_U32                  (MC_CGM_AC5_CDC0_DE_MASK32)
    #define MC_CGM_AC5_CDC0_DIS_U32                 ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC0_DIV_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC1_U32(value)              ((uint32)((value) & ( MC_CGM_AC5_CDC1_DE_MASK32 | MC_CGM_AC5_CDC1_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC1_EN_U32                  (MC_CGM_AC5_CDC1_DE_MASK32)
    #define MC_CGM_AC5_CDC1_DIS_U32                 ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC1_DIV_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC2_U32(value)              ((uint32)((value) & ( MC_CGM_AC5_CDC2_DE_MASK32 | MC_CGM_AC5_CDC2_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC2_EN_U32                  (MC_CGM_AC5_CDC2_DE_MASK32)
    #define MC_CGM_AC5_CDC2_DIS_U32                 ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC2_DIV_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC10_U32(value)             ((uint32)((value) & ( MC_CGM_AC5_CDC10_DE_MASK32 | MC_CGM_AC5_CDC10_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC10_EN_U32                 (MC_CGM_AC5_CDC10_DE_MASK32)
    #define MC_CGM_AC5_CDC10_DIS_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC10_DIV_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC11_U32(value)             ((uint32)((value) & ( MC_CGM_AC5_CDC11_DE_MASK32 | MC_CGM_AC5_CDC11_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC11_EN_U32                 (MC_CGM_AC5_CDC11_DE_MASK32)
    #define MC_CGM_AC5_CDC11_DIS_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC11_DIV_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC12_U32(value)             ((uint32)((value) & ( MC_CGM_AC5_CDC12_DE_MASK32 | MC_CGM_AC5_CDC12_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC12_EN_U32                 (MC_CGM_AC5_CDC12_DE_MASK32)
    #define MC_CGM_AC5_CDC12_DIS_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC12_DIV_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC13_U32(value)             ((uint32)((value) & ( MC_CGM_AC5_CDC13_DE_MASK32 | MC_CGM_AC5_CDC13_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC13_EN_U32                 (MC_CGM_AC5_CDC13_DE_MASK32)
    #define MC_CGM_AC5_CDC13_DIS_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC13_DIV_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC20_U32(value)             ((uint32)((value) & ( MC_CGM_AC5_CDC20_DE_MASK32 | MC_CGM_AC5_CDC20_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC20_EN_U32                 (MC_CGM_AC5_CDC20_DE_MASK32)
    #define MC_CGM_AC5_CDC20_DIS_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC20_DIV_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC21_U32(value)             ((uint32)((value) & ( MC_CGM_AC5_CDC21_DE_MASK32 | MC_CGM_AC5_CDC21_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC21_EN_U32                 (MC_CGM_AC5_CDC21_DE_MASK32)
    #define MC_CGM_AC5_CDC21_DIS_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC21_DIV_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC22_U32(value)             ((uint32)((value) & ( MC_CGM_AC5_CDC22_DE_MASK32 | MC_CGM_AC5_CDC22_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC22_EN_U32                 (MC_CGM_AC5_CDC22_DE_MASK32)
    #define MC_CGM_AC5_CDC22_DIS_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC22_DIV_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC23_U32(value)             ((uint32)((value) & ( MC_CGM_AC5_CDC23_DE_MASK32 | MC_CGM_AC5_CDC23_DIV_MASK32 )))
    #define MC_CGM_AC5_CDC23_EN_U32                 (MC_CGM_AC5_CDC23_DE_MASK32)
    #define MC_CGM_AC5_CDC23_DIS_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC5_CDC23_DIV_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

#endif /* (IPV_MC == IPV_MC_04_00_15_15) */


/******************************************************************/
/************************    CGM_AC6_SC    ************************/
/******************************************************************/
/* Configuration for CGM_AC6_SC[SELCTL] field register. */
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK6_U32(value)               ((uint32)( ((value) & MC_CGM_AC6_SC_SELCTL_MASK32 ) | MC_CGM_AC6_SC_RESBITS_MASK32 ))

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00))
    #define MC_CGM_AUXCLK6_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK6_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK6_SOURCE_PLL0_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK6_SOURCE_PLL1_U32          ((uint32)0x04000000U)

    /* Configuration for CGM_AC6_DC0[DE] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC6_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC6_DC0_DE_MASK32 | MC_CGM_AC6_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK6_DIV0_EN_U32              (MC_CGM_AC6_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK6_DIV0_DIS_U32             ((uint32)0x00000000U)
    /* Configuration for CGM_AC6_DC0[DIV] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK6_DIV0_U32(div)            ((uint32)(((div) - (uint32)1U) << (uint32)16U))
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK6_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK6_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK6_SOURCE_SIRC_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK6_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK6_SOURCE_PLL1_U32          ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK6_SOURCE_PLL2_U32          ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK6_SOURCE_PLL3_U32          ((uint32)0x07000000U)

    /* Configuration for CGM_AC6_DC0[DE] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC6_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC6_DC0_DE_MASK32 | MC_CGM_AC6_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK6_DIV0_EN_U32              (MC_CGM_AC6_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK6_DIV0_DIS_U32             ((uint32)0x00000000U)
    /* Configuration for CGM_AC6_DC0[DIV] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK6_DIV0_U32(div)            ((uint32)(((div) - (uint32)1U) << (uint32)16U))

    /* Configuration for CGM_AC6_DC1[DE] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC6_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC6_DC1_DE_MASK32 | MC_CGM_AC6_DC1_DIV_MASK32 )))
    #define MC_CGM_AUXCLK6_DIV1_EN_U32              (MC_CGM_AC6_DC1_DE_MASK32)
    #define MC_CGM_AUXCLK6_DIV1_DIS_U32             ((uint32)0x00000000U)
    /* Configuration for CGM_AC6_DC0[DIV] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK6_DIV1_U32(div)            ((uint32)(((div) - (uint32)1U) << (uint32)16U))
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_CGM_AUXCLK6_SOURCE_FXOSC_U32         ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK6_SOURCE_FIRC_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK6_SOURCE_PLL0_PHI0_U32     ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK6_SOURCE_S160_U32          ((uint32)0x03000000U)
    #define MC_CGM_AUXCLK6_SOURCE_RTC_U32           ((uint32)0x04000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK6_SOURCE_PLL0_PHI1_U32     ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK6_SOURCE_SXOSC_U32         ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK6_SOURCE_SIRC_U32          ((uint32)0x07000000U)
    #define MC_CGM_AUXCLK6_SOURCE_Z4A_U32           ((uint32)0x08000000U)
    #define MC_CGM_AUXCLK6_SOURCE_Z4B_U32           ((uint32)0x09000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK6_SOURCE_HSM_CORE_CLK_U32  ((uint32)0x0A000000U)
    #define MC_CGM_AUXCLK6_SOURCE_S40_U32           ((uint32)0x0C000000U)
    #define MC_CGM_AUXCLK6_SOURCE_F40_U32           ((uint32)0x0D000000U)
    #define MC_CGM_AUXCLK6_SOURCE_F80_U32           ((uint32)0x0E000000U)
    #define MC_CGM_AUXCLK6_SOURCE_FS80_U32          ((uint32)0x0F000000U)

    /* Configuration for CGM_AC6_DC0[DE] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC6_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC6_DC0_DE_MASK32 | MC_CGM_AC6_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK6_DIV0_EN_U32              (MC_CGM_AC6_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK6_DIV0_DIS_U32             ((uint32)0x00000000U)
    /* Configuration for CGM_AC6_DC0[DIV] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK6_DIV0_U32(div)            ((uint32)(((div) - (uint32)1U) << (uint32)16U))
    
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* Configuration for CGM_AC6_SC[SELCTL] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK6_U32(value)               ((uint32) ((value) & MC_CGM_0_AC6_SC_SELCTL_MASK32 ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK6_SOURCE_FIRC_U32                ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK6_SOURCE_XOSC_U32                ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK6_SOURCE_PERIPH_PLL_DIV5_U32     ((uint32)0x03000000U)

    /* Configuration for CGM_AC6_DC0[DE] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC6_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC6_DC0_DE_MASK32 | MC_CGM_0_AC6_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK6_DIV0_EN_U32              (MC_CGM_0_AC6_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK6_DIV0_DIS_U32             ((uint32)0x00000000U)
    /* Configuration for CGM_AC6_DC0[DIV] field register. */
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK6_DIV0_U32(div)            ((uint32)(((div) - (uint32)1U) << (uint32)16U))
    
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */


/******************************************************************/
/************************    CGM_AC7_SC    ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK7_U32(value)                   ((uint32)( ((value) & MC_CGM_AC7_SC_SELCTL_MASK32 ) | MC_CGM_AC7_SC_RESBITS_MASK32 ))
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_CGM_AUXCLK7_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK7_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK7_SOURCE_PLL0_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK7_SOURCE_PLL1_U32          ((uint32)0x04000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK7_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK7_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK7_SOURCE_SIRC_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK7_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK7_SOURCE_PLL1_U32          ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK7_SOURCE_PLL2_U32          ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK7_SOURCE_PLL3_U32          ((uint32)0x07000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK7_U32(value)                   ((uint32)((value) & MC_CGM_0_AC7_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK7_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK7_SOURCE_XOSC_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK7_SOURCE_ENET_PLL_U32      ((uint32)0x04000000U)
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AUXCLK7_SOURCE_SDPLL_U32         ((uint32)0x03000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_05_00) || \
     (IPV_MC == IPV_MC_05_00_00_10) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC7_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC7_DC0_DE_MASK32 | MC_CGM_AC7_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK7_DIV0_EN_U32              (MC_CGM_AC7_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK7_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK7_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif
#if (IPV_MC == IPV_MC_05_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC7_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC7_DC0_DE_MASK32 | MC_CGM_AC7_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK7_DIV0_EN_U32              (MC_CGM_AC7_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK7_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK7_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC7_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC7_DC1_DE_MASK32 | MC_CGM_AC7_DC1_DIV_MASK32 )))
    #define MC_CGM_AUXCLK7_DIV1_EN_U32              (MC_CGM_AC7_DC1_DE_MASK32)
    #define MC_CGM_AUXCLK7_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK7_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC7_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC7_DC1_DE_MASK32 | MC_CGM_0_AC7_DC1_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK7_DIV1_EN_U32              (MC_CGM_0_AC7_DC1_DE_MASK32)
    #define MC_CGM_0_AUXCLK7_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK7_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

/******************************************************************/
/************************    CGM_AC8_SC    ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK8_U32(value)                   ((uint32)( ((value) & MC_CGM_AC8_SC_SELCTL_MASK32 ) | MC_CGM_AC8_SC_RESBITS_MASK32 ))

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_CGM_AUXCLK8_SOURCE_IRC_U32           ((uint32)0x00000000U)
#endif
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) \
    )
    #define MC_CGM_AUXCLK8_SOURCE_XTAL_U32          ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK8_SOURCE_PLL0_U32          ((uint32)0x02000000U)
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AUXCLK8_SOURCE_SDPLL_U32         ((uint32)0x03000000U)
    #define MC_CGM_AUXCLK8_SOURCE_PLL1_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK8_SOURCE_LFAST_U32         ((uint32)0x05000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK8_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK8_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK8_SOURCE_SIRC_U32          ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK8_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK8_SOURCE_PLL1_U32          ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK8_SOURCE_PLL2_U32          ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK8_SOURCE_PLL3_U32          ((uint32)0x07000000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_CGM_AUXCLK8_SOURCE_F40_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK8_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK8_U32(value)                   ((uint32) ((value) & MC_CGM_0_AC8_SC_SELCTL_MASK32))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK8_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK8_SOURCE_XOSC_U32          ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK8_SOURCE_DDR_PLL_U32       ((uint32)0x05000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC8_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC8_DC0_DE_MASK32 | MC_CGM_0_AC8_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK8_DIV0_EN_U32              (MC_CGM_0_AC8_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK8_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK8_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC8_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC8_DC1_DE_MASK32 | MC_CGM_0_AC8_DC1_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK8_DIV1_EN_U32              (MC_CGM_0_AC8_DC1_DE_MASK32)
    #define MC_CGM_0_AUXCLK8_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK8_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_10) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC8_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC8_DC0_DE_MASK32 | MC_CGM_AC8_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK8_DIV0_EN_U32              (MC_CGM_AC8_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK8_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK8_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

/******************************************************************/
/************************    CGM_AC9_SC    ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK9_U32(value)                   ((uint32)( ((value) & MC_CGM_AC9_SC_SELCTL_MASK32 ) | MC_CGM_AC9_SC_RESBITS_MASK32 ))
#if (IPV_MC == IPV_MC_04_03_00_00)
    #define MC_CGM_AUXCLK9_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK9_SOURCE_XTAL_U32          ((uint32)0x00000004U)
    #define MC_CGM_AUXCLK9_SOURCE_PLL0_U32          ((uint32)0x00000008U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_AFE160_U32        ((uint32)0x0000000CU)
    #define MC_CGM_AUXCLK9_SOURCE_PLL1_U32          ((uint32)0x00000010U)
    #define MC_CGM_AUXCLK9_SOURCE_NAP_U32           ((uint32)0x00000014U)
    #define MC_CGM_AUXCLK9_SOURCE_CTE_U32           ((uint32)0x00000020U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_PLL0_FBCLK_U32    ((uint32)0x00000024U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_AFE320_U32        ((uint32)0x00000028U)
    #define MC_CGM_AUXCLK9_SOURCE_AFE80_U32         ((uint32)0x0000002CU)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_RAMDAC_U32        ((uint32)0x00000034U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_CGM_AUXCLK9_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK9_SOURCE_XTAL_U32          ((uint32)0x00000004U)
    #define MC_CGM_AUXCLK9_SOURCE_PLL0_U32          ((uint32)0x00000008U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_AFE160_U32        ((uint32)0x0000000CU)
    #define MC_CGM_AUXCLK9_SOURCE_PLL1_U32          ((uint32)0x00000010U)
    #define MC_CGM_AUXCLK9_SOURCE_NAP_U32           ((uint32)0x00000014U)
    #define MC_CGM_AUXCLK9_SOURCE_OSC40_U32         ((uint32)0x00000018U)
    #define MC_CGM_AUXCLK9_SOURCE_PTI_U32           ((uint32)0x0000001CU)
    #define MC_CGM_AUXCLK9_SOURCE_CTE_U32           ((uint32)0x00000020U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_PLL0_FBCLK_U32    ((uint32)0x00000024U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_AFE320_U32        ((uint32)0x00000028U)
    #define MC_CGM_AUXCLK9_SOURCE_AFE80_U32         ((uint32)0x0000002CU)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_RAMDAC_U32        ((uint32)0x00000030U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_SINK_SEL_1_U32    ((uint32)0x00000034U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_SINK_SEL_2_U32    ((uint32)0x00000038U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK9_SOURCE_SINK_SEL_3_U32    ((uint32)0x0000003CU)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00))
    #define MC_CGM_AUXCLK9_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK9_SOURCE_XTAL_U32          ((uint32)0x01000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK9_SOURCE_FIRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK9_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK9_SOURCE_PLL0_U32          ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK9_SOURCE_PLL1_U32          ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK9_SOURCE_PLL2_U32          ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK9_SOURCE_PLL3_U32          ((uint32)0x07000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_CGM_AUXCLK9_SOURCE_FS80_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK9_SOURCE_FXOSC_U32         ((uint32)0x01000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK9_U32(value)                   ((uint32) ((value) & MC_CGM_0_AC9_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK9_SOURCE_FIRC_U32               ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK9_SOURCE_XOSC_U32               ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK9_SOURCE_VIDEO_PLL_DIV2_U32     ((uint32)0x06000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_10) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC9_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC9_DC0_DE_MASK32 | MC_CGM_AC9_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK9_DIV0_EN_U32              (MC_CGM_AC9_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK9_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK9_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC9_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC9_DC0_DE_MASK32 | MC_CGM_0_AC9_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK9_DIV0_EN_U32              (MC_CGM_0_AC9_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK9_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK9_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC9_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC9_DC1_DE_MASK32 | MC_CGM_0_AC9_DC1_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK9_DIV1_EN_U32              (MC_CGM_0_AC9_DC1_DE_MASK32)
    #define MC_CGM_0_AUXCLK9_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK9_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif
/******************************************************************/
/************************    CGM_AC10_SC   ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK10_U32(value)              ((uint32)( ((value) & MC_CGM_AC10_SC_SELCTL_MASK32 ) | MC_CGM_AC10_SC_RESBITS_MASK32 ))
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_04_01_00) \
    )
    #define MC_CGM_AUXCLK10_SOURCE_IRC_U32          ((uint32)0x00000000U)
#endif
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_04_01_00))
    #define MC_CGM_AUXCLK10_SOURCE_XTAL_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK10_SOURCE_PLL0_U32         ((uint32)0x02000000U)
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK10_SOURCE_SDPLL_U32        ((uint32)0x03000000U)
#elif (IPV_MC == IPV_MC_04_04_01_00)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK10_SOURCE_PLL0_PHI1_U32    ((uint32)0x03000000U)
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_04_01_00))
    #define MC_CGM_AUXCLK10_SOURCE_PLL1_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK10_SOURCE_RMII_U32         ((uint32)0x05000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */
#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK10_SOURCE_FIRC_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK10_SOURCE_FXOSC_U32        ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK10_SOURCE_PLL0_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK10_SOURCE_PLL1_U32         ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK10_SOURCE_PLL2_U32         ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK10_SOURCE_PLL3_U32         ((uint32)0x07000000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK10_U32(value)              ((uint32) ((value) & MC_CGM_0_AC10_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK10_SOURCE_FIRC_U32           ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK10_SOURCE_XOSC_U32           ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK10_SOURCE_ARM_PLL_U32        ((uint32)0x02000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK10_SOURCE_PERIPH_PLL_U32     ((uint32)0x03000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK10_SOURCE_ENET_PLL_U32       ((uint32)0x04000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK10_SOURCE_DDR_PLL_U32        ((uint32)0x05000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK10_SOURCE_VIDEO_PLL_U32      ((uint32)0x06000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC10_DC0_U32(value)              ((uint32)((value) & ( MC_CGM_0_AC10_DC0_DE_MASK32 | MC_CGM_0_AC10_DC0_DIV_MASK32 | MC_CGM_0_AC10_DC0_DIV_FMT_MASK32)))
    #define MC_CGM_0_AUXCLK10_DIV0_EN_U32             (MC_CGM_0_AC10_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK10_DIV0_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK10_DIV0_U32(div,fmt)       ((uint32)((((div) - (uint32)1U) << (uint32)16U) | (fmt)))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC10_DC1_U32(value)              ((uint32)((value) & ( MC_CGM_0_AC10_DC1_DE_MASK32 | MC_CGM_0_AC10_DC1_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK10_DIV1_EN_U32             (MC_CGM_0_AC10_DC1_DE_MASK32)
    #define MC_CGM_0_AUXCLK10_DIV1_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK10_DIV1_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_10) ||\
     (IPV_MC == IPV_MC_04_04_01_00) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC10_DC0_U32(value)              ((uint32)((value) & ( MC_CGM_AC10_DC0_DE_MASK32 | MC_CGM_AC10_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK10_DIV0_EN_U32             (MC_CGM_AC10_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK10_DIV0_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK10_DIV0_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif


/******************************************************************/
/************************    CGM_AC11_SC   ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK11_U32(value)                  ((uint32)( ((value) & MC_CGM_AC11_SC_SELCTL_MASK32 ) | MC_CGM_AC11_SC_RESBITS_MASK32 ))

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_04_01_00) \
    )
    #define MC_CGM_AUXCLK11_SOURCE_IRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK11_SOURCE_XTAL_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK11_SOURCE_PLL0_U32         ((uint32)0x02000000U)
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK11_SOURCE_SDPLL_U32        ((uint32)0x03000000U)
#elif (IPV_MC == IPV_MC_04_04_01_00)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK11_SOURCE_PLL0_PHI1_U32    ((uint32)0x03000000U)
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_04_04_01_00))
    #define MC_CGM_AUXCLK11_SOURCE_PLL1_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK11_SOURCE_RMII_U32         ((uint32)0x05000000U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK11_SOURCE_FIRC_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK11_SOURCE_FXOSC_U32        ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK11_SOURCE_PLL0_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK11_SOURCE_PLL1_U32         ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK11_SOURCE_PLL2_U32         ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK11_SOURCE_PLL3_U32         ((uint32)0x07000000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK11_U32(value)                  ((uint32) ((value) & MC_CGM_0_AC11_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK11_SOURCE_FIRC_32KHZ_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK11_SOURCE_XOSC_32KHZ_U32         ((uint32)0x01000000U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC11_DC0_U32(value)              ((uint32)((value) & ( MC_CGM_0_AC11_DC0_DE_MASK32 | MC_CGM_0_AC11_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK11_DIV0_EN_U32             (MC_CGM_0_AC11_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK11_DIV0_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK11_DIV0_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_04_01_00) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC11_DC0_U32(value)              ((uint32)((value) & ( MC_CGM_AC11_DC0_DE_MASK32 | MC_CGM_AC11_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK11_DIV0_EN_U32             (MC_CGM_AC11_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK11_DIV0_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK11_DIV0_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif


/******************************************************************/
/************************    CGM_AC12_SC   ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK12_U32(value)                  ((uint32)( ((value) & MC_CGM_AC12_SC_SELCTL_MASK32 ) | MC_CGM_AC12_SC_RESBITS_MASK32 ))

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AUXCLK12_SOURCE_IRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK12_SOURCE_XTAL_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK12_SOURCE_PLL0_U32         ((uint32)0x02000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK12_SOURCE_SDPLL_U32        ((uint32)0x03000000U)
    #define MC_CGM_AUXCLK12_SOURCE_PLL1_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK12_SOURCE_MC_U32           ((uint32)0x05000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK12_SOURCE_PBRIDGE_U32      ((uint32)0x06000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK12_SOURCE_FIRC_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK12_SOURCE_FXOSC_U32        ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK12_SOURCE_SIRC_U32         ((uint32)0x02000000U)
    #define MC_CGM_AUXCLK12_SOURCE_PLL0_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK12_SOURCE_PLL1_U32         ((uint32)0x05000000U)
    #define MC_CGM_AUXCLK12_SOURCE_PLL2_U32         ((uint32)0x06000000U)
    #define MC_CGM_AUXCLK12_SOURCE_PLL3_U32         ((uint32)0x07000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK12_SOURCE_SYSCLK_U32       ((uint32)0x08000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK12_U32(value)                  ((uint32) ((value) & MC_CGM_0_AC12_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK12_SOURCE_FIRC_U32           ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK12_SOURCE_XOSC_U32           ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK12_SOURCE_ENET_PLL_DFS1_U32  ((uint32)0x04000000U)
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC12_DC0_U32(value)              ((uint32)((value) & ( MC_CGM_AC12_DC0_DE_MASK32 | MC_CGM_AC12_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK12_DIV0_EN_U32             (MC_CGM_AC12_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK12_DIV0_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK12_DIV0_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC12_DC0_U32(value)              ((uint32)((value) & ( MC_CGM_0_AC12_DC0_DE_MASK32 | MC_CGM_0_AC12_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK12_DIV0_EN_U32             (MC_CGM_0_AC12_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK12_DIV0_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK12_DIV0_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif


/******************************************************************/
/************************    CGM_AC13_SC   ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK13_U32(value)                  ((uint32)( ((value) & MC_CGM_AC13_SC_SELCTL_MASK32 ) | MC_CGM_AC13_SC_RESBITS_MASK32 ))

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_CGM_AUXCLK13_SOURCE_IRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK13_SOURCE_XTAL_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK13_SOURCE_PLL0_U32         ((uint32)0x02000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK13_SOURCE_SDPLL_U32        ((uint32)0x03000000U)
    #define MC_CGM_AUXCLK13_SOURCE_PLL1_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK13_SOURCE_MC_U32           ((uint32)0x05000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK13_SOURCE_PBRIDGE_U32      ((uint32)0x06000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK13_SOURCE_FIRC_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK13_SOURCE_FXOSC_U32        ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK13_SOURCE_SIRC_U32         ((uint32)0x02000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK13_SOURCE_SXOSC_U32        ((uint32)0x03000000U)
    #define MC_CGM_AUXCLK13_SOURCE_RTC_U32          ((uint32)0x09000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK13_U32(value)                  ((uint32) ((value) & MC_CGM_0_AC13_SC_SELCTL_MASK32 ))

    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK13_SOURCE_FIRC_U32           ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK13_SOURCE_XOSC_U32           ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK13_SOURCE_ENET_PLL_DFS2_U32  ((uint32)0x04000000U)
    
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC13_DC0_U32(value)              ((uint32)((value) & ( MC_CGM_AC13_DC0_DE_MASK32 | MC_CGM_AC13_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK13_DIV0_EN_U32             (MC_CGM_AC13_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK13_DIV0_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK13_DIV0_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC13_DC0_U32(value)              ((uint32)((value) & ( MC_CGM_0_AC13_DC0_DE_MASK32 | MC_CGM_0_AC13_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK13_DIV0_EN_U32             (MC_CGM_0_AC13_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK13_DIV0_DIS_U32            ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK13_DIV0_U32(div)           ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif


/******************************************************************/
/************************    CGM_AC14_SC   ************************/
/******************************************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK14_U32(value)               ((uint32)(((value) & MC_CGM_AC14_SC_SELCTL_MASK32 ) | MC_CGM_AC14_SC_RESBITS_MASK32 ))
#endif
#if (IPV_MC == IPV_MC_04_03_00_00)
    #define MC_CGM_AUXCLK14_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK14_SOURCE_XTAL_U32          ((uint32)0x00000040U)
    #define MC_CGM_AUXCLK14_SOURCE_PLL0_U32          ((uint32)0x00000080U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_AFE160_U32        ((uint32)0x000000C0U)
    #define MC_CGM_AUXCLK14_SOURCE_PLL1_U32          ((uint32)0x00000100U)
    #define MC_CGM_AUXCLK14_SOURCE_NAP_U32           ((uint32)0x00000140U)
    #define MC_CGM_AUXCLK14_SOURCE_CTE_U32           ((uint32)0x00000200U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_PLL0_FBCLK_U32    ((uint32)0x00000240U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_AFE320_U32        ((uint32)0x00000280U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_AFE80_U32         ((uint32)0x000002C0U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_RAMDAC_U32        ((uint32)0x00000340U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_CGM_AUXCLK14_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK14_SOURCE_XTAL_U32          ((uint32)0x00000040U)
    #define MC_CGM_AUXCLK14_SOURCE_PLL0_U32          ((uint32)0x00000080U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_AFE160_U32        ((uint32)0x000000C0U)
    #define MC_CGM_AUXCLK14_SOURCE_PLL1_U32          ((uint32)0x00000100U)
    #define MC_CGM_AUXCLK14_SOURCE_NAP_U32           ((uint32)0x00000140U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_OSC40_U32         ((uint32)0x00000180U)
    #define MC_CGM_AUXCLK14_SOURCE_PTI_U32           ((uint32)0x000001C0U)
    #define MC_CGM_AUXCLK14_SOURCE_CTE_U32           ((uint32)0x00000200U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_PLL0_FBCLK_U32    ((uint32)0x00000240U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_AFE320_U32        ((uint32)0x00000280U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_AFE80_U32         ((uint32)0x000002C0U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_RAMDAC_U32        ((uint32)0x00000300U)
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_SINK_SEL_1_U32    ((uint32)0x00000340U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_SINK_SEL_2_U32    ((uint32)0x00000380U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_SINK_SEL_3_U32    ((uint32)0x000003C0U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK14_SOURCE_FIRC_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK14_SOURCE_FXOSC_U32        ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK14_SOURCE_PLL0_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK14_SOURCE_PLL1_U32         ((uint32)0x05000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK14_U32(value)               ((uint32)((value) & MC_CGM_0_AC14_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK14_SOURCE_FIRC_U32           ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK14_SOURCE_XOSC_U32           ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK14_SOURCE_ENET_PLL_DFS3_U32  ((uint32)0x04000000U)

#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) \
    )
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC14_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC14_DC0_DE_MASK32 | MC_CGM_AC14_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK14_DIV0_EN_U32              (MC_CGM_AC14_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK14_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK14_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC14_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC14_DC0_DE_MASK32 | MC_CGM_0_AC14_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK14_DIV0_EN_U32              (MC_CGM_0_AC14_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK14_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK14_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif


#if (IPV_MC == IPV_MC_04_06_05_00)
    #define MCB_CGM_SINK_SEL_3_SYS_CLK_U32                     ((uint32)0x00000000U)
    #define MCB_CGM_SINK_SEL_3_CORE1_CLK_U32                   ((uint32)0x00100000U)
    #define MCB_CGM_SINK_SEL_3_CORE2_CLK_U32                   ((uint32)0x00200000U)
    #define MCB_CGM_SINK_SEL_3_PBRIDGE_0_CLK_U32               ((uint32)0x00300000U)
    #define MCB_CGM_SINK_SEL_3_DMA_CLK_U32                     ((uint32)0x00400000U)
    #define MCB_CGM_SINK_SEL_3_CORE0_CLK_U32                   ((uint32)0x00500000U)
    #define MCB_CGM_SINK_SEL_3_PBRIDGE_1_CLK_U32               ((uint32)0x00800000U)
    #define MCB_CGM_SINK_SEL_3_CORE_0_TCK_CLK_U32              ((uint32)0x00B00000U)
    #define MCB_CGM_SINK_SEL_3_CORE_2_TCK_CLK_U32              ((uint32)0x00C00000U)
    #define MCB_CGM_SINK_SEL_3_FLASH_CLK_U32                   ((uint32)0x00D00000U)
    #define MCB_CGM_SINK_SEL_3_ENABLE_SIGNAL_TO_FLASH_U32      ((uint32)0x00F00000U)

    #define MCB_CGM_SINK_SEL_2_ADC_CLK_U32                     ((uint32)0x00000000U)
    #define MCB_CGM_SINK_SEL_2_CAN_CLK_U32                     ((uint32)0x00030000U)
    #define MCB_CGM_SINK_SEL_2_SPT_CLK_U32                     ((uint32)0x00040000U)
    #define MCB_CGM_SINK_SEL_2_LFAST_CLK_U32                   ((uint32)0x00050000U)
    #define MCB_CGM_SINK_SEL_2_ENET_CLK_U32                    ((uint32)0x00060000U)
    #define MCB_CGM_SINK_SEL_2_ENET_TIME_CLK_U32               ((uint32)0x00070000U)
    #define MCB_CGM_SINK_SEL_2_SPI_CLK_U32                     ((uint32)0x00080000U)
    #define MCB_CGM_SINK_SEL_2_LIN_CLK_U32                     ((uint32)0x00090000U)
    #define MCB_CGM_SINK_SEL_2_CORE_0_NEX_CLK_U32              ((uint32)0x000A0000U)
    #define MCB_CGM_SINK_SEL_2_CORE_0_SLV_CLK_U32              ((uint32)0x000B0000U)
    #define MCB_CGM_SINK_SEL_2_CORE_1_NEX_CLK_U32              ((uint32)0x000C0000U)
    #define MCB_CGM_SINK_SEL_2_CORE_1_SLV_CLK_U32              ((uint32)0x000D0000U)
    #define MCB_CGM_SINK_SEL_2_CORE_2_NEX_CLK_U32              ((uint32)0x000E0000U)
    #define MCB_CGM_SINK_SEL_2_CORE_2_SLV_CLK_U32              ((uint32)0x000F0000U)
    
    #define MCB_CGM_SINK_SEL_1_AC0_CLK_U32                     ((uint32)0x00000000U)
    #define MCB_CGM_SINK_SEL_1_AC1_CLK_U32                     ((uint32)0x00001000U)
    #define MCB_CGM_SINK_SEL_1_AC2_CLK_U32                     ((uint32)0x00002000U)
    #define MCB_CGM_SINK_SEL_1_AC3_CLK_U32                     ((uint32)0x00003000U)
    #define MCB_CGM_SINK_SEL_1_AC4_CLK_U32                     ((uint32)0x00004000U)
    #define MCB_CGM_SINK_SEL_1_AC7_CLK_U32                     ((uint32)0x00007000U)
    #define MCB_CGM_SINK_SEL_1_AC8_CLK_U32                     ((uint32)0x00008000U)
    #define MCB_CGM_SINK_SEL_1_AC10_CLK_U32                    ((uint32)0x0000A000U)
    #define MCB_CGM_SINK_SEL_1_AC11_CLK_U32                    ((uint32)0x0000B000U)
    #define MCB_CGM_SINK_SEL_1_AC12_CLK_U32                    ((uint32)0x0000C000U)
    #define MCB_CGM_SINK_SEL_1_AC13_CLK_U32                    ((uint32)0x0000D000U)
    #define MCB_CGM_SINK_SEL_1_SYS_CLK_U32                     ((uint32)0x0000F000U)
#endif

/******************************************************************/
/************************    CGM_AC15_SC   ************************/
/******************************************************************/
/** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_CGM_AUXCLK15_U32(value)                  ((uint32)(((value) & MC_CGM_AC15_SC_SELCTL_MASK32 ) | MC_CGM_AC15_SC_RESBITS_MASK32 ))

#if (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_CGM_AUXCLK15_SOURCE_IRC_U32          ((uint32)0x00000000U)
    #define MC_CGM_AUXCLK15_SOURCE_XTAL_U32         ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK15_SOURCE_PLL0_U32         ((uint32)0x02000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK15_SOURCE_SDPLL_U32        ((uint32)0x03000000U)
    #define MC_CGM_AUXCLK15_SOURCE_PLL1_U32         ((uint32)0x04000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_CGM_AUXCLK15_SOURCE_FIRC_U32         ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_AUXCLK15_SOURCE_FXOSC_U32        ((uint32)0x01000000U)
    #define MC_CGM_AUXCLK15_SOURCE_PLL0_U32         ((uint32)0x04000000U)
    #define MC_CGM_AUXCLK15_SOURCE_PLL1_U32         ((uint32)0x05000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK15_U32(value)                  ((uint32)((value) & MC_CGM_0_AC15_SC_SELCTL_MASK32 ))
    
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK15_SOURCE_FIRC_U32           ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK15_SOURCE_XOSC_U32           ((uint32)0x01000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit. */
    #define MC_CGM_0_AUXCLK15_SOURCE_ENET_PLL_DFS4_U32  ((uint32)0x04000000U)

#endif

#if ((IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_10))
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC15_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_AC15_DC0_DE_MASK32 | MC_CGM_AC15_DC0_DIV_MASK32 )))
    #define MC_CGM_AUXCLK15_DIV0_EN_U32              (MC_CGM_AC15_DC0_DE_MASK32)
    #define MC_CGM_AUXCLK15_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK15_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif
#if (IPV_MC == IPV_MC_05_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AC15_DC1_U32(value)               ((uint32)((value) & ( MC_CGM_AC15_DC1_DE_MASK32 | MC_CGM_AC15_DC1_DIV_MASK32 )))
    #define MC_CGM_AUXCLK15_DIV1_EN_U32              (MC_CGM_AC15_DC1_DE_MASK32)
    #define MC_CGM_AUXCLK15_DIV1_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_AUXCLK15_DIV1_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AC15_DC0_U32(value)               ((uint32)((value) & ( MC_CGM_0_AC15_DC0_DE_MASK32 | MC_CGM_0_AC15_DC0_DIV_MASK32 )))
    #define MC_CGM_0_AUXCLK15_DIV0_EN_U32              (MC_CGM_0_AC15_DC0_DE_MASK32)
    #define MC_CGM_0_AUXCLK15_DIV0_DIS_U32             ((uint32)0x00000000U)
    /** @violates @ref Mcu_MC_CGM_Types_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MC_CGM_0_AUXCLK15_DIV0_U32(div)            ((uint32)(( (div) - (uint32)1U ) << (uint32)16U ))
#endif

#ifdef  ERR_IPV_MC_0043
#if (STD_ON == ERR_IPV_MC_0043)
    #define MCU_MC_CGM_SYSTEM_CLOCK_TIMEOUT         ((uint16)0x0003U)
#endif
#endif

/******************************************************************/
/************************    clock drop    ************************/
/******************************************************************/
#if (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_CGM_DROPCLK_SOURCE_IRC_U32           ((uint32)0x00000000U)
    #define MC_CGM_DROPCLK_SOURCE_XTAL_U32          ((uint32)0x01000000U)
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define SRC_GPR1_VIDEO_PLL_SOURCE_FIRC_U32            ((uint32)0x00000000U)
    #define SRC_GPR1_VIDEO_PLL_SOURCE_XOSC_U32            (SRC_GPR1_VIDEO_PLL_SOURCE_SELECT_MASK32)
    
    #define SRC_GPR1_PERIPH_PLL_SOURCE_FIRC_U32           ((uint32)0x00000000U)
    #define SRC_GPR1_PERIPH_PLL_SOURCE_XOSC_U32           (SRC_GPR1_PERIPH_PLL_SOURCE_SELECT_MASK32)
                                                          
    #define SRC_GPR1_DDR_PLL_SOURCE_FIRC_U32              ((uint32)0x00000000U)
    #define SRC_GPR1_DDR_PLL_SOURCE_XOSC_U32              (SRC_GPR1_DDR_PLL_SOURCE_SELECT_MASK32)
                                                          
    #define SRC_GPR1_ENET_PLL_SOURCE_FIRC_U32             ((uint32)0x00000000U)
    #define SRC_GPR1_ENET_PLL_SOURCE_XOSC_U32             (SRC_GPR1_ENET_PLL_SOURCE_SELECT_MASK32)
                                                          
    #define SRC_GPR1_ARM_PLL_SOURCE_FIRC_U32              ((uint32)0x00000000U)
    #define SRC_GPR1_ARM_PLL_SOURCE_XOSC_U32              (SRC_GPR1_ARM_PLL_SOURCE_SELECT_MASK32)
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCU_INIT_CLOCK == STD_ON)


/**
* @brief       MC_CGM addr and value pair.
* @details     this structure is used to represent a pair of addr and data to be written to hardware
*/
typedef struct
{
   VAR( uint32, MCU_VAR) u32RegisterAddr; /* register addr, added by hand in the code template */
   VAR( uint32, MCU_VAR) u32RegisterData; /* generated value, as it\92s already defined */

} Mcu_MC_CGM_RegisterConfigType;


#if (IPV_MC == IPV_MC_06_00_00_10)
/**
* @brief       SRC mask and value pair.
* @details     this structure is used to represent a pair of mask and data to be written to hardware
*/
typedef struct
{
   VAR( uint32, MCU_VAR) u32RegisterMask; /* register addr, added by hand in the code template */
   VAR( uint32, MCU_VAR) u32RegisterData; /* generated value, as it\92s already defined */

} Mcu_SRC_ConfigType;
#endif

/**
* @brief   MC_CGM IP configuration.
* @details This structure contains information for IRCOSC, XOSC, PLL, Output Clocks, CMUs
*          The definitions for each Clock setting within the structure Mcu_ConfigType shall contain:
*          - MCU specific properties as, e.g., clock safety features and special clock distribution
*            settings
*          - PLL settings /start lock options
*          - Internal oscillator setting
*/
typedef struct
{
    /**< @brief These clock sources must be powered on for the current clock setting . */
    VAR (uint32, MCU_VAR) u32EnabledClkSources;
    
#if (IPV_MC == IPV_MC_06_00_00_10)
    /* the SDUR values will be generated in the prog clock switch pointer array */ 
#else
    /**< @brief Configuration for Progressive Clock Switching (CGM_PCS_SDUR[SDUR]). */
    VAR (uint8, MCU_VAR)  u8ProgClkSwitch;
#endif

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_06_01_00)  || \
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_06_00_00_10) \
    )
    /* This is used as a mask to set the divider update mask and to triger a divider update after
    register update */
    /* This is set from the plugin by adding bits for each aux clock under MCU control */
    VAR (uint32, MCU_VAR) u32AuxDividerUpdateTriggerMask;
#endif
    /**< @brief number of prog. sw. registers unde mcu control */
    VAR (uint8, MCU_VAR)  u8NoOfProgSwitchUnderMcuControl;
    /* prog clock switch */
    CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) (*apPcsClockConfig)[];
    /**< @brief number of sys clock regs unde mcu control */
    VAR (uint8, MCU_VAR)  u8NoOfSysClockUnderMcuControl;
    /* system clock config */
    CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) (*apSystemClockConfig)[];
#if (IPV_MC == IPV_MC_06_00_00_10)
    /**< @brief secondary sys clock mask */
    VAR (uint32, MCU_VAR)  u32SecondarySysClockWriteMask;
    /**< @brief number of secondary sys clock regs unde mcu control */
    VAR (uint8, MCU_VAR)  u8NoOfSecondarySysClockUnderMcuControl;
    /* secondary system clock config */
    CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) (*apSecondarySystemClockConfig)[];
#endif
    /**< @brief number of aux clock regs under mcu control */
    VAR (uint8, MCU_VAR)  u8NoAuxClockUnderMcuControl;
    /* auxiliary clock dividers */
    CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) (*apAuxClockConfig)[];

} Mcu_MC_CGM_ClockConfigType;


#endif /* (MCU_INIT_CLOCK == STD_ON) */


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_MC_CGM_TYPES_H */

/** @} */
