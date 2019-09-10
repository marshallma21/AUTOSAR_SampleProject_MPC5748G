/**
*   @file    Mcu_PMCDIG_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from PMCDIG.
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


#ifndef MCU_PMCDIG_TYPES_H
#define MCU_PMCDIG_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section MCU_PMCDIG_TYPES_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section MCU_PMCDIG_TYPES_h_REF_2
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
#include "Mcu_Cfg.h"
#include "Reg_eSys_PMCDIG.h"
#include "Soc_Ips.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_PMCDIG_TYPES_VENDOR_ID                     43
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_PMCDIG_TYPES_AR_RELEASE_MAJOR_VERSION      4
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_PMCDIG_TYPES_AR_RELEASE_MINOR_VERSION      2
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_PMCDIG_TYPES_AR_RELEASE_REVISION_VERSION   2
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_PMCDIG_TYPES_SW_MAJOR_VERSION              1
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_PMCDIG_TYPES_SW_MINOR_VERSION              0
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_PMCDIG_TYPES_SW_PATCH_VERSION              0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_PMCDIG_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_PMCDIG_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_PMCDIG_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PMCDIG_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PMCDIG_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PMCDIG_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_PMCDIG_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_PMCDIG_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_PMCDIG_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PMCDIG_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Reg_eSys_PMCDIG header file are from the same vendor */
#if (MCU_PMCDIG_TYPES_VENDOR_ID != REG_ESYS_PMCDIG_VENDOR_ID)
    #error "Mcu_PMCDIG_Types.h and Reg_eSys_PMCDIG.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_PMCDIG header file are of the same Autosar version */
#if ((MCU_PMCDIG_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_PMCDIG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PMCDIG_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_PMCDIG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PMCDIG_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_PMCDIG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PMCDIG_Types.h and Reg_eSys_PMCDIG.h are different"
#endif
/* Check if source file and Reg_eSys_PMCDIG header file are of the same Software version */
#if ((MCU_PMCDIG_TYPES_SW_MAJOR_VERSION != REG_ESYS_PMCDIG_SW_MAJOR_VERSION) || \
     (MCU_PMCDIG_TYPES_SW_MINOR_VERSION != REG_ESYS_PMCDIG_SW_MINOR_VERSION) || \
     (MCU_PMCDIG_TYPES_SW_PATCH_VERSION != REG_ESYS_PMCDIG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PMCDIG_Types.h and Reg_eSys_PMCDIG.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PMCDIG_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PMCDIG_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PMCDIG_Types.h and Soc_Ips.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/***********************************************************/
/*                        PMCDIG_RDCR                      */
/***********************************************************/
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define PMCDIG_RDCR_VALUE_U32(value)            ((uint32)(( (value) & PMCDIG_RDCR_RWBITS_MASK32 ) | PMCDIG_RDCR_RESBITS_MASK32))

/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_MEM_SLEEP_ENABLE_U32        ( PMCDIG_RDCR_MEM_SLEEP_EN_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_MEM_SLEEP_DISABLE_U32       ((uint32)0x00000000U)

#define PMCDIG_RDCR_PAD_KEEP_ENABLE_U32        ( PMCDIG_RDCR_PAD_KEEP_EN_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_PAD_KEEP_DISABLE_U32       ((uint32)0x00000000U)

#define PMCDIG_RDCR_RD24_RET_ENABLE_U32         ( PMCDIG_RDCR_RD24_RET_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_RD24_RET_DISABLE_U32        ((uint32)0x00000000U)

#define PMCDIG_RDCR_RD64_RET_ENABLE_U32         ( PMCDIG_RDCR_RD64_RET_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_RD64_RET_DISABLE_U32        ((uint32)0x00000000U)

/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_RD128_RET_ENABLE_U32         ( PMCDIG_RDCR_RD128_RET_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_RD128_RET_DISABLE_U32        ((uint32)0x00000000U)

/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_RD256_RET_ENABLE_U32         ( PMCDIG_RDCR_RD256_RET_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_RDCR_RD256_RET_DISABLE_U32        ((uint32)0x00000000U)

/***********************************************************/
/*                        PMCDIG_MCR                       */
/***********************************************************/
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define PMCDIG_MCR_VALUE_U32(value)             ((uint32)(( (value) & PMCDIG_MCR_RWBITS_MASK32 ) | PMCDIG_MCR_RESBITS_MASK32 ))

/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_SIG_TO_ADC_FLIP_ENABLE_U32   ( PMCDIG_MCR_SIG_TO_ADC_FLIP_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_SIG_TO_ADC_FLIP_DISABLE_U32  ((uint32)0x00000000U)

/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_SIG_TO_ADC_EN_ENABLE_U32     ( PMCDIG_MCR_SIG_TO_ADC_EN_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_SIG_TO_ADC_EN_DISABLE_U32    ((uint32)0x00000000U)

#define PMCDIG_MCR_ISO_ACK2_ENABLE_U32          ( PMCDIG_MCR_ISO_ACK2_MASK32 )
#define PMCDIG_MCR_ISO_ACK2_DISABLE_U32         ((uint32)0x00000000U)

#define PMCDIG_MCR_ISO_ACK1_ENABLE_U32          ( PMCDIG_MCR_ISO_ACK1_MASK32 )
#define PMCDIG_MCR_ISO_ACK1_DISABLE_U32         ((uint32)0x00000000U)

#define PMCDIG_MCR_ISO_ACK0_ENABLE_U32          ( PMCDIG_MCR_ISO_ACK0_MASK32 )
#define PMCDIG_MCR_ISO_ACK0_DISABLE_U32         ((uint32)0x00000000U)

/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_FLASH_LP_FAST_EXIT_DIS_U32   ( PMCDIG_MCR_FLASH_LP_FAST_EXIT_DIS_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_FLASH_LP_FAST_EXIT_ENA_U32   ((uint32)0x00000000U)

/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_LVD_PD2_COLD_REE_ENA_U32     ( PMCDIG_MCR_LVD_PD2_COLD_REE_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_LVD_PD2_COLD_REE_DIS_U32     ((uint32)0x00000000U)

#define PMCDIG_MCR_HVD_REE_ENABLE_U32           ( PMCDIG_MCR_HVD_REE_MASK32 )
#define PMCDIG_MCR_HVD_REE_DISABLE_U32          ((uint32)0x00000000U)

/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_LVD_IO_HI_REE_ENABLE_U32     ( PMCDIG_MCR_LVD_IO_HI_REE_MASK32 )
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define PMCDIG_MCR_LVD_IO_HI_REE_DISABLE_U32    ((uint32)0x00000000U)

#if (IPV_PMC == IPV_PMCDIG_00_01_08_04)
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMCDIG_SIG_TO_ADC_SEL_VDDE_B_U32               ((uint32)0x00060000U)
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMCDIG_SIG_TO_ADC_SEL_VDDE_SDR_U32             ((uint32)0x00080000U)
    #define PMCDIG_SIG_TO_ADC_SEL_VDD_A_U32                ((uint32)0x000A0000U)
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMCDIG_SIG_TO_ADC_SEL_VDD_LV_PD0_U32           ((uint32)0x000C0000U)
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMCDIG_SIG_TO_ADC_SEL_VDD_LV_PD1_U32           ((uint32)0x000E0000U)
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMCDIG_SIG_TO_ADC_SEL_VDD_LV_PD2_U32           ((uint32)0x00100000U)
/** @violates @ref MCU_PMCDIG_TYPES_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define PMCDIG_SIG_TO_ADC_SEL_VDD_VSS_PMC_U32          ((uint32)0x00120000U)
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Configuration of PMCDIG hw IP
* @details          This data configuration is set at module initialization phase.
*/
typedef struct
{
    /* RAM Domain Configuration Register */
    VAR( uint32, MCU_VAR) u32PmcdigRDCR;
    /* MISC Control Register */
    VAR( uint32, MCU_VAR) u32PmcdigMCR;
} Mcu_PMCDIG_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_PMCDIG_TYPES_H */

/** @} */
