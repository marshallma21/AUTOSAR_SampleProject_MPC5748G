/**
*   @file    Mcu_FLASH_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from FLASH.
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


#ifndef MCU_FLASH_TYPES_H
#define MCU_FLASH_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_FLASH_Types_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_FLASH_Types_h_REF_2
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
#include "Mcu_Reg_eSys_FLASHC.h"
#include "Soc_Ips.h"
#include "Mcu_FLASH_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_FLASH_TYPES_VENDOR_ID                    43
#define MCU_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MCU_FLASH_TYPES_AR_RELEASE_MINOR_VERSION     2
#define MCU_FLASH_TYPES_AR_RELEASE_REVISION_VERSION  2
#define MCU_FLASH_TYPES_SW_MAJOR_VERSION             1
#define MCU_FLASH_TYPES_SW_MINOR_VERSION             0
#define MCU_FLASH_TYPES_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_FLASH_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_FLASH_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FLASH_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FLASH_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FLASH_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_FLASH_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_FLASH_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_FLASH_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FLASH_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_FLASH_TYPES_VENDOR_ID != REG_ESYS_FLASHC_VENDOR_ID)
    #error "Mcu_FLASH_Types.h and Mcu_Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FLASH_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FLASH_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FLASH_Types.h and Mcu_Reg_eSys_FLASHC.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_FLASH_TYPES_SW_MAJOR_VERSION != REG_ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (MCU_FLASH_TYPES_SW_MINOR_VERSION != REG_ESYS_FLASHC_SW_MINOR_VERSION) || \
     (MCU_FLASH_TYPES_SW_PATCH_VERSION != REG_ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FLASH_Types.h and Mcu_Reg_eSys_FLASHC.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_FLASH_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_FLASH_Types.h and Soc_Ips.h are different"
    #endif
#endif

/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_FLASH_TYPES_VENDOR_ID != MCU_FLASH_IPVERSION_VENDOR_ID)
    #error "Mcu_FLASH_Types.h and Mcu_FLASH_IPVersion.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_FLASH_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FLASH_TYPES_AR_RELEASE_MINOR_VERSION != MCU_FLASH_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FLASH_TYPES_AR_RELEASE_REVISION_VERSION != MCU_FLASH_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FLASH_Types.h and Mcu_FLASH_IPVersion.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_FLASH_TYPES_SW_MAJOR_VERSION != MCU_FLASH_IPVERSION_SW_MAJOR_VERSION) || \
     (MCU_FLASH_TYPES_SW_MINOR_VERSION != MCU_FLASH_IPVERSION_SW_MINOR_VERSION) || \
     (MCU_FLASH_TYPES_SW_PATCH_VERSION != MCU_FLASH_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FLASH_Types.h and Mcu_FLASH_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* defines for PFLASH_PFCR1 */
#if ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_25_60_86_00) || \
     (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || \
     (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || \
     (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || \
     (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
    )
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 Function-like macro defined.*/
    #define MCU_FLASH_PFCR1_U32(value)                      ((uint32)(((value) & FLASHC_PFCR1_RWBITS_MASK32) | FLASHC_PFCR1_RESBITS_MASK32))
    /* PFCR1[P0_MxPFE] configuration filed. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER15_PREFETCH_EN_U32           (FLASHC_PFCR1_P0_M15PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER15_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER14_PREFETCH_EN_U32           (FLASHC_PFCR1_P0_M14PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER14_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER13_PREFETCH_EN_U32           (FLASHC_PFCR1_P0_M13PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER13_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER12_PREFETCH_EN_U32           (FLASHC_PFCR1_P0_M12PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER12_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER11_PREFETCH_EN_U32           (FLASHC_PFCR1_P0_M11PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER11_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER10_PREFETCH_EN_U32           (FLASHC_PFCR1_P0_M10PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER10_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER9_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M9PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER9_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER8_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M8PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER8_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER7_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M7PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER7_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER6_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M6PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER6_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER5_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M5PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER5_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER4_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M4PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER4_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER3_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M3PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER3_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER2_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M2PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER2_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER1_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M1PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER1_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER0_PREFETCH_EN_U32            (FLASHC_PFCR1_P0_M0PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_MASTER0_PREFETCH_DIS_U32           (0x00000000U)

#ifdef ERR_IPV_FLASH_0015
#if (STD_ON == ERR_IPV_FLASH_0015)
    #define MCU_FLASH_ADDR_PIPELINE_WS_DIS_U32              (0x00000004U)
#endif /* (STD_ON == ERR_IPV_FLASH_0015) */
#endif /* ERR_IPV_FLASH_0015 */

    /* PFCR1[APC]: Possible values. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 Function-like macro defined.*/
    #define MCU_FLASH_ADDR_PIPELINE_WS_U32(ws)              ((uint32)((uint32)((uint32)(ws) << (uint32)13U) & FLASHC_PFCR1_APC_MASK32))

    /* PFCR1[RWSC]: Possible values. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_READ_WS_U32(ws)                       ((uint32)((uint32)((uint32)(ws) << (uint32)8U) & FLASHC_PFCR1_RWSC_MASK32 ))

    /* PFCR1[P0_DPFEN] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_DATA_PREFETCH_EN_U32               (FLASHC_PFCR1_P0_DPFEN_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_DATA_PREFETCH_DIS_U32              (0x00000000U)

    /* PFCR1[P0_IFPFEN] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_INSTR_PREFETCH_EN_U32              (FLASHC_PFCR1_P0_IFPFEN_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P0_INSTR_PREFETCH_DIS_U32             (0x00000000U)

    /* PFCR1[P0_PFLIM] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_P0_PFLIM_U32(value)                   ((uint32)((uint32)((value) << (uint32)1U) & FLASHC_PFCR1_P0_PFLIM_MASK32 ))

    /* PFCR1[P0_BFEN] configuration field. */
    #define MCU_FLASH_P0_BUFFER_EN_U32                      (FLASHC_PFCR1_P0_BFEN_MASK32)
    #define MCU_FLASH_P0_BUFFER_DIS_U32                     (0x00000000U)

#endif


/* defines for PFLASH_PFCR2 */
#if ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || \
     (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || \
     (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || \
     (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
    )
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_PFCR2_U32(value)                      ((uint32)(((value) & FLASHC_PFCR2_RWBITS_MASK32 ) | FLASHC_PFCR2_RESBITS_MASK32 ))

    /* PFCR2[P1_MxPFE] configuration filed. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER15_PREFETCH_EN_U32           (FLASHC_PFCR2_P1_M15PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER15_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER14_PREFETCH_EN_U32           (FLASHC_PFCR2_P1_M14PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER14_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER13_PREFETCH_EN_U32           (FLASHC_PFCR2_P1_M13PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER13_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER12_PREFETCH_EN_U32           (FLASHC_PFCR2_P1_M12PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER12_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER11_PREFETCH_EN_U32           (FLASHC_PFCR2_P1_M11PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER11_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER10_PREFETCH_EN_U32           (FLASHC_PFCR2_P1_M10PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER10_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER9_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M9PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER9_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER8_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M8PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER8_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER7_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M7PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER7_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER6_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M6PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER6_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER5_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M5PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER5_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER4_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M4PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER4_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER3_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M3PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER3_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER2_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M2PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER2_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER1_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M1PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER1_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER0_PREFETCH_EN_U32            (FLASHC_PFCR2_P1_M0PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_MASTER0_PREFETCH_DIS_U32           (0x00000000U)

    /* PFCR2[P1_DPFEN] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_DATA_PREFETCH_EN_U32               (FLASHC_PFCR2_P1_DPFEN_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_DATA_PREFETCH_DIS_U32              (0x00000000U)

    /* PFCR2[P1_IFPFEN] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_INSTR_PREFETCH_EN_U32              (FLASHC_PFCR2_P1_IFPFEN_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P1_INSTR_PREFETCH_DIS_U32             (0x00000000U)

    /* PFCR2[P1_PFLIM] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_P1_PFLIM_U32(value)                   ((uint32)((uint32)((value) << (uint32)1U) & FLASHC_PFCR2_P1_PFLIM_MASK32 ))

    /* PFCR2[P1_BFEN] configuration field. */
    #define MCU_FLASH_P1_BUFFER_EN_U32                      (FLASHC_PFCR2_P1_BFEN_MASK32)
    #define MCU_FLASH_P1_BUFFER_DIS_U32                     (0x00000000U)

#endif

/* defines for PFLASH_PFCR3 */
#if ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_25_60_86_00) || \
     (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || \
     (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || \
     (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || \
     (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
    )

    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_PFCR3_U32(value)                      ((uint32)(((value) & FLASHC_PFCR3_RWBITS_MASK32 ) | FLASHC_PFCR3_RESBITS_MASK32 ))

    /* PFCR3[P0_WCFG] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_P0_WCFG_U32(value)                    ((uint32)((uint32)((value) << (uint32)30) & FLASHC_PFCR3_P0_WCFG_MASK32 ))

    /* PFCR3[P1_WCFG] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_P1_WCFG_U32(value)                    ((uint32)((uint32)((value) << (uint32)28) & FLASHC_PFCR3_P1_WCFG_MASK32 ))
#endif 

#if ((IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46))
    /* PFCR3[P2_WCFG] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_P2_WCFG_U32(value)                    ((uint32)((uint32)((value) << (uint32)26) & FLASHC_PFCR3_P2_WCFG_MASK32 ))

    /* PFCR3[ARBM] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_ARBM_WCFG_U32(value)                  ((uint32)((uint32)((value) << (uint32)12) & FLASHC_PFCR3_ARBM_MASK32 ))
#elif ((IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || \
       (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || \
       (IPV_FLASHV2 == IPV_FLASH_40_96_55_19) \
      )
    /* PFCR3[ARBM] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_ARBM_WCFG_U32(value)                  ((uint32)((uint32)((value) << (uint32)14) & FLASHC_PFCR3_ARBM_MASK32 ))
#endif

#if ((IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) || (IPV_FLASHV2 == IPV_FLASH_84_80_32_02))
    /* PFCR3[BFEN_LK] configuration field. */
    #define MCU_FLASH_BFEN_LOCK_U32                               (FLASHC_PFCR3_BFEN_LK_MASK32)
    #define MCU_FLASH_BFEN_UNLOCK_U32                             (0x00000000U)
#endif

#if ((IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || \
     (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) \
    )
    /* PFCR3[BDRM] configuration field. */
    #define MCU_FLASH_BDRM_EN_U32                               (FLASHC_PFCR3_BDRM_MASK32)
    #define MCU_FLASH_BDRM_DIS_U32                              (0x00000000U)
#endif 

#if ((IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || \
     (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || \
     (IPV_FLASHV2 == IPV_FLASH_40_96_55_19) \
    )
    /* PFCR3[BAF_DIS] configuration field. */
    #define MCU_FLASH_BAF_DIS_U32                               (FLASHC_PFCR3_BAF_DIS_MASK32)
    #define MCU_FLASH_BAF_EN_U32                                0x00000000U    
#endif

#if ((IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_84_80_32_02))
    #define MCU_FLASH_DERR_SUP_EN_U32                           (FLASHC_PFCR3_DERR_SUP_MASK32)
    #define MCU_FLASH_DERR_SUP_DIS_U32                          (0x00000000U)
#endif /* (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) */

#if ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_25_60_86_00) || \
     (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || \
     (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || \
     (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || \
     (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
    )

    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_PFAPR_U32(value)                      ((uint32)(((value) & FLASHC_PFAPR_RWBITS_MASK32 ) | FLASHC_PFAPR_RESBITS_MASK32 ))

    /* PFAPR[M0AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M0AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)30U) & FLASHC_PFAPR_M0AP_MASK32))

    /* PFAPR[M1AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M1AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)28U) & FLASHC_PFAPR_M1AP_MASK32))

    /* PFAPR[M2AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M2AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)26U) & FLASHC_PFAPR_M2AP_MASK32))

    /* PFAPR[M3AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M3AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)24U) & FLASHC_PFAPR_M3AP_MASK32))

    /* PFAPR[M4AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M4AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)22U) & FLASHC_PFAPR_M4AP_MASK32))

    /* PFAPR[M5AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M5AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)20U) & FLASHC_PFAPR_M5AP_MASK32))

    /* PFAPR[M6AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M6AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)18U) & FLASHC_PFAPR_M6AP_MASK32))

    /* PFAPR[M7AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M7AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)16U) & FLASHC_PFAPR_M7AP_MASK32))

    /* PFAPR[M8AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M8AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)14U) & FLASHC_PFAPR_M8AP_MASK32))

    /* PFAPR[M9AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M9AP_U32(value)                       ((uint32)((uint32)((value) << (uint32)12U) & FLASHC_PFAPR_M9AP_MASK32))

    /* PFAPR[M10AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M10AP_U32(value)                      ((uint32)((uint32)((value) << (uint32)10U) & FLASHC_PFAPR_M10AP_MASK32))

    /* PFAPR[M11AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M11AP_U32(value)                      ((uint32)((uint32)((value) << (uint32)8U) & FLASHC_PFAPR_M11AP_MASK32))

    /* PFAPR[M12AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M12AP_U32(value)                      ((uint32)((uint32)((value) << (uint32)6U) & FLASHC_PFAPR_M12AP_MASK32))

    /* PFAPR[M13AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
    #define MCU_FLASH_M13AP_U32(value)                      ((uint32)((uint32)((value) << (uint32)4U) & FLASHC_PFAPR_M13AP_MASK32))

    /* PFAPR[M14AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 Function-like macro defined.*/
    #define MCU_FLASH_M14AP_U32(value)                      ((uint32)((uint32)((value) << (uint32)2U) & FLASHC_PFAPR_M14AP_MASK32))

    /* PFAPR[M15AP] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 Function-like macro defined.*/
    #define MCU_FLASH_M15AP_U32(value)                      ((uint32)((uint32)((value) << (uint32)0U) & FLASHC_PFAPR_M15AP_MASK32))
#endif 

#if ((IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46))

    /** @violates @ref Mcu_FLASH_Types_h_REF_2 Function-like macro defined.*/
    #define MCU_FLASH_PFCR4_U32(value)                      ((uint32)(((value) & FLASHC_PFCR4_RWBITS_MASK32) | FLASHC_PFCR4_RESBITS_MASK32))

    /* PFCR4[P2_MxPFE] configuration filed. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER15_PREFETCH_EN_U32           (FLASHC_PFCR4_P2_M15PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER15_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER14_PREFETCH_EN_U32           (FLASHC_PFCR4_P2_M14PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER14_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER13_PREFETCH_EN_U32           (FLASHC_PFCR4_P2_M13PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER13_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER12_PREFETCH_EN_U32           (FLASHC_PFCR4_P2_M12PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER12_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER11_PREFETCH_EN_U32           (FLASHC_PFCR4_P2_M11PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER11_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER10_PREFETCH_EN_U32           (FLASHC_PFCR4_P2_M10PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER10_PREFETCH_DIS_U32          (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER9_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M9PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER9_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER8_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M8PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER8_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER7_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M7PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER7_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER6_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M6PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER6_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER5_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M5PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER5_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER4_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M4PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER4_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER3_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M3PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER3_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER2_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M2PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER2_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER1_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M1PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER1_PREFETCH_DIS_U32           (0x00000000U)

    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER0_PREFETCH_EN_U32            (FLASHC_PFCR4_P2_M0PFE_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_MASTER0_PREFETCH_DIS_U32           (0x00000000U)

    /* PFCR4[P2_DPFEN] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_DATA_PREFETCH_EN_U32               (FLASHC_PFCR4_P2_DPFEN_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_DATA_PREFETCH_DIS_U32              (0x00000000U)

    /* PFCR4[P2_IFPFEN] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_INSTR_PREFETCH_EN_U32              (FLASHC_PFCR4_P2_IFPFEN_MASK32)
    /** @violates @ref Mcu_FLASH_Types_h_REF_1 Defines longer than 31 characters.*/
    #define MCU_FLASH_P2_INSTR_PREFETCH_DIS_U32             (0x00000000U)

    /* PFCR4[P2_PFLIM] configuration field. */
    /** @violates @ref Mcu_FLASH_Types_h_REF_2 Function-like macro defined.*/
    #define MCU_FLASH_P2_PFLIM_U32(value)                   ((uint32)((uint32)((value) << (uint32)1U) & FLASHC_PFCR4_P2_PFLIM_MASK32))

    /* PFCR4[P2_BFEN] configuration field. */
    #define MCU_FLASH_P2_BUFFER_EN_U32                      (FLASHC_PFCR4_P2_BFEN_MASK32)
    #define MCU_FLASH_P2_BUFFER_DIS_U32                     (0x00000000U)
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            Timing configuration for FLASH hw IP.
* @details          Set the Pipeline/Write/Read wait states for FLASH controller.
*                   Configuration set by calling Mcu_InitClock API.
*/
typedef struct
{
    VAR( uint32, MCU_VAR) u32FlashWS;   /**< @brief Flash wait-state configuration. */

} Mcu_FLASH_ClockConfigType;
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/**
* @brief            Platform FLASH hw IP configuration.
* @details          Configure prefetch mechanism, buffers, access protection.
*                   Configuration set by calling Mcu_Init API.
*/
typedef struct
{
#if (IPV_FLASHV2 == IPV_FLASH_00_00_05_01)
    /**< @brief Platform Flash Configuration Register (without wait-states configuration). */
    VAR( uint32, MCU_VAR) u32FlashConfig;
#elif ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || \
       (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || \
       (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || \
       (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
      )
    /**< @brief Platform Flash Configuration Register (without wait-states configuration) PFCR1. */
    VAR( uint32, MCU_VAR) u32FlashConfig1;
    /**< @brief Platform Flash Configuration Register PFCR2. */
    VAR( uint32, MCU_VAR) u32FlashConfig2;
    /**< @brief Platform Flash Configuration Register PFCR3. */
    VAR( uint32, MCU_VAR) u32FlashConfig3;
#elif (IPV_FLASHV2 ==  IPV_FLASH_25_60_86_00)
    /**< @brief Platform Flash Configuration Register (without wait-states configuration) PFCR1. */
    VAR( uint32, MCU_VAR) u32FlashConfig1;
    /**< @brief Platform Flash Configuration Register PFCR3. */
    VAR( uint32, MCU_VAR) u32FlashConfig3;
#endif /* (IPV_FLASHV2 == IPV_FLASH_40_96_55_19) */
#if ((IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46))
    /**< @brief Platform Flash Configuration Register PFCR4. */
    VAR( uint32, MCU_VAR) u32FlashConfig4;
#endif
    /**< @brief Platform Flash Access Protection Register. */
    VAR( uint32, MCU_VAR) u32FlashAccess;

} Mcu_FLASH_ConfigType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_FLASH_TYPES_H */

/** @} */
