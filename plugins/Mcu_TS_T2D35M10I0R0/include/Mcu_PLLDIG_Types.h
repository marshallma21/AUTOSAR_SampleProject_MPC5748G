/**
*   @file    Mcu_PLLDIG_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from PLLDIG.
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


#ifndef MCU_PLLDIG_TYPES_H
#define MCU_PLLDIG_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_PLLDIG_Types_h_REF_1
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
#include "Reg_eSys_PLLDIG.h"
#include "Soc_Ips.h"
#include "Mcu_PLLDIG_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_PLLDIG_TYPES_VENDOR_ID                       43
#define MCU_PLLDIG_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCU_PLLDIG_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCU_PLLDIG_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCU_PLLDIG_TYPES_SW_MAJOR_VERSION                1
#define MCU_PLLDIG_TYPES_SW_MINOR_VERSION                0
#define MCU_PLLDIG_TYPES_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_PLLDIG_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_PLLDIG_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_PLLDIG_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PLLDIG_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PLLDIG_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PLLDIG_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_PLLDIG_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_PLLDIG_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_PLLDIG_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PLLDIG_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_PLLDIG_TYPES_VENDOR_ID != REG_ESYS_PLLDIG_VENDOR_ID)
    #error "Mcu_PLLDIG_Types.h and Reg_eSys_PLLDIG.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_PLLDIG_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_PLLDIG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PLLDIG_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_PLLDIG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PLLDIG_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_PLLDIG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PLLDIG_Types.h and Reg_eSys_PLLDIG.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_PLLDIG_TYPES_SW_MAJOR_VERSION != REG_ESYS_PLLDIG_SW_MAJOR_VERSION) || \
     (MCU_PLLDIG_TYPES_SW_MINOR_VERSION != REG_ESYS_PLLDIG_SW_MINOR_VERSION) || \
     (MCU_PLLDIG_TYPES_SW_PATCH_VERSION != REG_ESYS_PLLDIG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PLLDIG_Types.h and Reg_eSys_PLLDIG.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PLLDIG_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PLLDIG_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PLLDIG_Types.h and Soc_Ips.h are different"
    #endif
#endif

/* Check if source file and Mcu_PLLDIG_IPVersion header file are from the same vendor */
#if (MCU_PLLDIG_TYPES_VENDOR_ID != MCU_PLLDIG_IPVERSION_VENDOR_ID)
    #error "Mcu_PLLDIG_Types.h and Mcu_PLLDIG_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_PLLDIG_IPVersion header file are of the same Autosar version */
#if ((MCU_PLLDIG_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_PLLDIG_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PLLDIG_TYPES_AR_RELEASE_MINOR_VERSION != MCU_PLLDIG_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PLLDIG_TYPES_AR_RELEASE_REVISION_VERSION != MCU_PLLDIG_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PLLDIG_Types.h and Mcu_PLLDIG_IPVersion.h are different"
#endif
/* Check if source file and Mcu_PLLDIG_IPVersion header file are of the same Software version */
#if ((MCU_PLLDIG_TYPES_SW_MAJOR_VERSION != MCU_PLLDIG_IPVERSION_SW_MAJOR_VERSION) || \
     (MCU_PLLDIG_TYPES_SW_MINOR_VERSION != MCU_PLLDIG_IPVERSION_SW_MINOR_VERSION) || \
     (MCU_PLLDIG_TYPES_SW_PATCH_VERSION != MCU_PLLDIG_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PLLDIG_Types.h and Mcu_PLLDIG_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**************************************************************/
/*                 PLLDIG_PLL0CAL3                            */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0CAL3_U32(value)              ((uint32)(( (value)&PLLDIG_PLL0CAL3_RWBITS_MASK32 ) | PLLDIG_PLL0CAL3_RESBITS_MASK32))

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0CAL3_MDFEN_U32(value)        ((uint32)(( (value) << PLLDIG_PLL0CAL3_MDFEN_SHIFT32 ) & PLLDIG_PLL0CAL3_MDFEN_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL0CR                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0CR_U32(value)                ((uint32)(((value)&PLLDIG_PLL0CR_RWBITS_MASK32)|PLLDIG_PLL0CR_RESBITS_MASK32))

#define MCU_PLLDIG_PLL0CR_LOLIE_ENA_U32             (PLLDIG_PLL0CR_LOLIE_MASK32)
#define MCU_PLLDIG_PLL0CR_LOLIE_DIS_U32             ((uint32)0x00000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13))
    #define MCU_PLLDIG_PLL0CR_LOLRE_ENA_U32         (PLLDIG_PLL0CR_LOLRE_MASK32)
    #define MCU_PLLDIG_PLL0CR_LOLRE_DIS_U32         ((uint32)0x00000000U)
#endif

    
#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
    #define MCU_PLLDIG_PLL0CR_EXPDIE_ENA_U32        (PLLDIG_PLL0CR_EXPDIE_MASK32)
    #define MCU_PLLDIG_PLL0CR_EXPDIE_DIS_U32        ((uint32)0x00000000U)
#endif

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)
    #define MCU_PLLDIG_PLL0CR_LOCIE_ENA_U32         (PLLDIG_PLL0CR_LOCIE_MASK32)
    #define MCU_PLLDIG_PLL0CR_LOCIE_DIS_U32         ((uint32)0x00000000U)
#endif

/**************************************************************/
/*                 PLLDIG_PLL0SR                              */
/**************************************************************/
#define MCU_PLLDIG_PLL0SR_LOLF_U32                  (PLLDIG_PLL0SR_LOLF_MASK32)
#define MCU_PLLDIG_PLL0SR_LOCK_U32                  (PLLDIG_PLL0SR_LOCK_MASK32)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
    #define MCU_PLLDIG_PLL0SR_EXTPDF_U32            (PLLDIG_PLL0SR_EXTPDF_MASK32)
#endif

/**************************************************************/
/*                 PLLDIG_PLL0DV                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0DV_U32(value)                ((uint32)(((value)&PLLDIG_PLL0DV_RWBITS_MASK32)|PLLDIG_PLL0DV_RESBITS_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0DV_RFDPHI1_U32(value)        ((uint32)(( (value) << PLLDIG_PLL0DV_RFDPHI1_SHIFT32 ) & PLLDIG_PLL0DV_RFDPHI1_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0DV_RFDPHI_U32(value)         ((uint32)(( (value) << PLLDIG_PLL0DV_RFDPHI_SHIFT32 ) & PLLDIG_PLL0DV_RFDPHI_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0DV_PREDIV_U32(value)         ((uint32)(( (value) << PLLDIG_PLL0DV_PREDIV_SHIFT32 ) & PLLDIG_PLL0DV_PREDIV_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0DV_MFD_U32(value)            ((uint32)( (value) & PLLDIG_PLL0DV_MFD_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL0FM                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0FM_U32(value)                ((uint32)(((value) & PLLDIG_PLL0FM_RWBITS_MASK32) | PLLDIG_PLL0FM_RESBITS_MASK32))

#define MCU_PLLDIG_PLL0FM_SSCGBYP_DIS_U32           (0x00000000U)
#define MCU_PLLDIG_PLL0FM_SSCGBYP_ENA_U32           (PLLDIG_PLL0FM_SSCGBYP_MASK32)

#define MCU_PLLDIG_PLL0FM_MODSEL_CENTERED_U32       (0x00000000U)
#define MCU_PLLDIG_PLL0FM_MODSEL_BELOW_U32          (PLLDIG_PLL0FM_MODSEL_MASK32)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0FM_MODPRD_U32(value)         ((uint32)(((value) << PLLDIG_PLL0FM_MODPRD_SHIFT32 ) & PLLDIG_PLL0FM_MODPRD_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0FM_INCSTP_U32(value)         ((uint32)(((value) << PLLDIG_PLL0FM_INCSTP_SHIFT32 ) & PLLDIG_PLL0FM_INCSTP_MASK32))

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL0FM_STEPSIZE_U32(value)         ((uint32)(((value) << PLLDIG_PLL0FM_STEPSIZE_SHIFT32 ) & PLLDIG_PLL0FM_STEPSIZE_MASK32))
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL0FM_STEPNO_U32(value)         ((uint32)(((value) << PLLDIG_PLL0FM_STEPNO_SHIFT32 ) & PLLDIG_PLL0FM_STEPNO_MASK32))
#endif
/**************************************************************/
/*                 PLLDIG_PLL0FD                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0FD_U32(value)                ((uint32)(((value) & PLLDIG_PLL0FD_RWBITS_MASK32 ) | PLLDIG_PLL0FD_RESBITS_MASK32 ))

#define MCU_PLLDIG_PLL0FD_SMDEN_DIS_U32             (PLLDIG_PLL0FD_SMDEN_MASK32)
#define MCU_PLLDIG_PLL0FD_SMDEN_ENA_U32             (0x00000000U)

#define MCU_PLLDIG_PLL0FD_SDM2_DIS_U32              (0x00000000U)
#define MCU_PLLDIG_PLL0FD_SDM2_ENA_U32              (PLLDIG_PLL0FD_SDM2_MASK32)

#define MCU_PLLDIG_PLL0FD_SDM3_DIS_U32              (0x00000000U)
#define MCU_PLLDIG_PLL0FD_SDM3_ENA_U32              (PLLDIG_PLL0FD_SDM3_MASK32)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0FD_DTHDIS_U32(value)         ((uint32)(((value) << PLLDIG_PLL0FD_DTHDIS_SHIFT32 ) & PLLDIG_PLL0FD_DTHDIS_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL0FD_MFN_U32(value)            ((uint32)(((value) << PLLDIG_PLL0FD_MFN_SHIFT32 ) & PLLDIG_PLL0FD_MFN_MASK32))


/**************************************************************/
/*                 PLLDIG_PLL0CAL1                            */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define MCU_PLLDIG_PLL0CAL1_BYPASS_DIS_U32             (0x00000000U)
    #define MCU_PLLDIG_PLL0CAL1_BYPASS_EN_U32              (PLLDIG_PLL0CAL1_BYPCAL_MASK32)
#endif

/**************************************************************/
/*                 PLLDIG_PLL1CAL3                            */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1CAL3_U32(value)              ((uint32)(((value) & PLLDIG_PLL1CAL3_RWBITS_MASK32 ) | PLLDIG_PLL1CAL3_RESBITS_MASK32))

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1CAL3_MDFEN_U32(value)        ((uint32)(((value) << PLLDIG_PLL1CAL3_MDFEN_SHIFT32 ) & PLLDIG_PLL1CAL3_MDFEN_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL1CR                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1CR_U32(value)                ((uint32)(((value) & PLLDIG_PLL1CR_RWBITS_MASK32)|PLLDIG_PLL1CR_RESBITS_MASK32))

#define MCU_PLLDIG_PLL1CR_LOLIE_ENA_U32             (PLLDIG_PLL1CR_LOLIE_MASK32)
#define MCU_PLLDIG_PLL1CR_LOLIE_DIS_U32             ((uint32)0x00000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13))
    #define MCU_PLLDIG_PLL1CR_LOLRE_ENA_U32         (PLLDIG_PLL1CR_LOLRE_MASK32)
    #define MCU_PLLDIG_PLL1CR_LOLRE_DIS_U32         ((uint32)0x00000000U)
#endif

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)
    #define MCU_PLLDIG_PLL1CR_LOCIE_ENA_U32         (PLLDIG_PLL1CR_LOCIE_MASK32)
    #define MCU_PLLDIG_PLL1CR_LOCIE_DIS_U32         ((uint32)0x00000000U)
#endif

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
    #define MCU_PLLDIG_PLL1CR_EXPDIE_ENA_U32        (PLLDIG_PLL1CR_EXPDIE_MASK32)
    #define MCU_PLLDIG_PLL1CR_EXPDIE_DIS_U32        ((uint32)0x00000000U)
#endif

/**************************************************************/
/*                 PLLDIG_PLL1SR                              */
/**************************************************************/
#define MCU_PLLDIG_PLL1SR_LOLF_U32                  (PLLDIG_PLL1SR_LOLF_MASK32)
#define MCU_PLLDIG_PLL1SR_LOCK_U32                  (PLLDIG_PLL1SR_LOCK_MASK32)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
    #define MCU_PLLDIG_PLL1SR_EXTPDF_U32            (PLLDIG_PLL1SR_EXTPDF_MASK32)
#endif

/**************************************************************/
/*                 PLLDIG_PLL1DV                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1DV_U32(value)                ((uint32)(((value) & PLLDIG_PLL1DV_RWBITS_MASK32 ) | PLLDIG_PLL1DV_RESBITS_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1DV_RFDPHI_U32(value)         ((uint32)(((value) << PLLDIG_PLL1DV_RFDPHI_SHIFT32 ) & PLLDIG_PLL1DV_RFDPHI_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1DV_MFD_U32(value)            ((uint32)((value) & PLLDIG_PLL1DV_MFD_MASK32))

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL1DV_RFDPHI1_U32(value)        ((uint32)(((value) << PLLDIG_PLL1DV_RFDPHI1_SHIFT32 ) & PLLDIG_PLL1DV_RFDPHI1_MASK32))
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL1DV_PREDIV_U32(value)         ((uint32)(((value) << PLLDIG_PLL1DV_PREDIV_SHIFT32 ) & PLLDIG_PLL1DV_PREDIV_MASK32))
#endif


/**************************************************************/
/*                 PLLDIG_PLL1FM                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FM_U32(value)                ((uint32)(((value)&PLLDIG_PLL1FM_RWBITS_MASK32)|PLLDIG_PLL1FM_RESBITS_MASK32))

#define MCU_PLLDIG_PLL1FM_SSCGBYP_DIS_U32           (0x00000000U)
#define MCU_PLLDIG_PLL1FM_SSCGBYP_ENA_U32           (PLLDIG_PLL1FM_SSCGBYP_MASK32)

#define MCU_PLLDIG_PLL1FM_MODSEL_CENTERED_U32       (0x00000000U)
#define MCU_PLLDIG_PLL1FM_MODSEL_BELOW_U32          (PLLDIG_PLL1FM_MODSEL_MASK32)

#define MCU_PLLDIG_PLL1FM_MODEN_ENA_U32             (PLLDIG_PLL1FM_MODEN_MASK32)
#define MCU_PLLDIG_PLL1FM_MODEN_DIS_U32             ((uint32)0x00000000U)

#define MCU_PLLDIG_PLL1FM_MODSEL_ENA_U32            (PLLDIG_PLL1FM_MODSEL_MASK32)
#define MCU_PLLDIG_PLL1FM_MODSEL_DIS_U32            ((uint32)0x00000000U)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FM_MODPRD_U32(value)         ((uint32)(((value) << PLLDIG_PLL1FM_MODPRD_SHIFT32 ) & PLLDIG_PLL1FM_MODPRD_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FM_INCSTP_U32(value)         ((uint32)(((value) << PLLDIG_PLL1FM_INCSTP_SHIFT32 ) & PLLDIG_PLL1FM_INCSTP_MASK32))

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL1FM_STEPSIZE_U32(value)         ((uint32)(((value) << PLLDIG_PLL1FM_STEPSIZE_SHIFT32 ) & PLLDIG_PLL1FM_STEPSIZE_MASK32))
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL1FM_STEPNO_U32(value)         ((uint32)(((value) << PLLDIG_PLL1FM_STEPNO_SHIFT32 ) & PLLDIG_PLL1FM_STEPNO_MASK32))
#endif

/**************************************************************/
/*                 PLLDIG_PLL1FD                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FD_U32(value)                ((uint32)(((value) & PLLDIG_PLL1FD_RWBITS_MASK32 ) | PLLDIG_PLL1FD_RESBITS_MASK32 ))

#define MCU_PLLDIG_PLL1FD_FDEN_ENA_U32              (PLLDIG_PLL1FD_FDEN_MASK32)
#define MCU_PLLDIG_PLL1FD_FDEN_DIS_U32              ((uint32)0x00000000U)

#define MCU_PLLDIG_PLL1FD_SMDEN_DIS_U32             (PLLDIG_PLL1FD_SMDEN_MASK32)
#define MCU_PLLDIG_PLL1FD_SMDEN_ENA_U32             (0x00000000U)

#define MCU_PLLDIG_PLL1FD_SDM2_DIS_U32              (0x00000000U)
#define MCU_PLLDIG_PLL1FD_SDM2_ENA_U32              (PLLDIG_PLL1FD_SDM2_MASK32)

#define MCU_PLLDIG_PLL1FD_SDM3_DIS_U32              (0x00000000U)
#define MCU_PLLDIG_PLL1FD_SDM3_ENA_U32              (PLLDIG_PLL1FD_SDM3_MASK32)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FD_DTHDIS_U32(value)         ((uint32)(((value) << PLLDIG_PLL1FD_DTHDIS_SHIFT32 ) & PLLDIG_PLL1FD_DTHDIS_MASK32))

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FD_DTHDIS1_U32(value)         ((uint32)(((value) << PLLDIG_PLL1FD_DTHDIS1_SHIFT32 ) & PLLDIG_PLL1FD_DTHDIS1_MASK32))

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FD_DTHDIS0_U32(value)         ((uint32)(((value) << PLLDIG_PLL1FD_DTHDIS0_SHIFT32 ) & PLLDIG_PLL1FD_DTHDIS0_MASK32))

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FD_FRCDIV_U32(value)         ((uint32)((value)&PLLDIG_PLL1FD_FRCDIV_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL1FD_MFN_U32(value)            ((uint32)(((value) << PLLDIG_PLL1FD_MFN_SHIFT32 ) & PLLDIG_PLL1FD_MFN_MASK32))



/**************************************************************/
/*                 PLLDIG_PLL2CAL3                            */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2CAL3_U32(value)              ((uint32)(((value) & PLLDIG_PLL2CAL3_RWBITS_MASK32 ) | PLLDIG_PLL2CAL3_RESBITS_MASK32))

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2CAL3_MDFEN_U32(value)        ((uint32)(((value) << PLLDIG_PLL2CAL3_MDFEN_SHIFT32 ) & PLLDIG_PLL2CAL3_MDFEN_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL2CR                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2CR_U32(value)                ((uint32)(((value) & PLLDIG_PLL2CR_RWBITS_MASK32)|PLLDIG_PLL2CR_RESBITS_MASK32))

#define MCU_PLLDIG_PLL2CR_LOLIE_ENA_U32             (PLLDIG_PLL2CR_LOLIE_MASK32)
#define MCU_PLLDIG_PLL2CR_LOLIE_DIS_U32             ((uint32)0x00000000U)

#define MCU_PLLDIG_PLL2CR_EXPDIE_ENA_U32            (PLLDIG_PLL2CR_EXPDIE_MASK32)
#define MCU_PLLDIG_PLL2CR_EXPDIE_DIS_U32            ((uint32)0x00000000U)

/**************************************************************/
/*                 PLLDIG_PLL2SR                              */
/**************************************************************/
#define MCU_PLLDIG_PLL2SR_LOLF_U32                  (PLLDIG_PLL2SR_LOLF_MASK32)
#define MCU_PLLDIG_PLL2SR_LOCK_U32                  (PLLDIG_PLL2SR_LOCK_MASK32)

#define MCU_PLLDIG_PLL2SR_EXTPDF_U32                (PLLDIG_PLL2SR_EXTPDF_MASK32)

/**************************************************************/
/*                 PLLDIG_PLL2DV                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2DV_U32(value)                ((uint32)(((value) & PLLDIG_PLL2DV_RWBITS_MASK32 ) | PLLDIG_PLL2DV_RESBITS_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2DV_RFDPHI1_U32(value)        ((uint32)(((value) << PLLDIG_PLL2DV_RFDPHI1_SHIFT32 ) & PLLDIG_PLL2DV_RFDPHI1_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2DV_RFDPHI_U32(value)         ((uint32)(((value) << PLLDIG_PLL2DV_RFDPHI_SHIFT32 ) & PLLDIG_PLL2DV_RFDPHI_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2DV_PREDIV_U32(value)         ((uint32)(((value) << PLLDIG_PLL2DV_PREDIV_SHIFT32 ) & PLLDIG_PLL2DV_PREDIV_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2DV_MFD_U32(value)            ((uint32)((value) & PLLDIG_PLL2DV_MFD_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL2FM                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2FM_U32(value)                ((uint32)(((value) & PLLDIG_PLL2FM_RWBITS_MASK32 ) |PLLDIG_PLL2FM_RESBITS_MASK32))

#define MCU_PLLDIG_PLL2FM_SSCGBYP_DIS_U32           (0x00000000U)
#define MCU_PLLDIG_PLL2FM_SSCGBYP_ENA_U32           (PLLDIG_PLL2FM_SSCGBYP_MASK32)

#define MCU_PLLDIG_PLL2FM_MODSEL_CENTERED_U32       (0x00000000U)
#define MCU_PLLDIG_PLL2FM_MODSEL_BELOW_U32          (PLLDIG_PLL2FM_MODSEL_MASK32)

#define MCU_PLLDIG_PLL2FM_MODEN_ENA_U32             (PLLDIG_PLL2FM_MODEN_MASK32)
#define MCU_PLLDIG_PLL2FM_MODEN_DIS_U32             ((uint32)0x00000000U)

#define MCU_PLLDIG_PLL2FM_MODSEL_ENA_U32            (PLLDIG_PLL2FM_MODSEL_MASK32)
#define MCU_PLLDIG_PLL2FM_MODSEL_DIS_U32            ((uint32)0x00000000U)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2FM_MODPRD_U32(value)         ((uint32)(((value) << PLLDIG_PLL2FM_MODPRD_SHIFT32 ) & PLLDIG_PLL2FM_MODPRD_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2FM_INCSTP_U32(value)         ((uint32)(((value) << PLLDIG_PLL2FM_INCSTP_SHIFT32 ) & PLLDIG_PLL2FM_INCSTP_MASK32))

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL2FM_STEPSIZE_U32(value)         ((uint32)(((value) << PLLDIG_PLL2FM_STEPSIZE_SHIFT32 ) & PLLDIG_PLL2FM_STEPSIZE_MASK32))
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL2FM_STEPNO_U32(value)         ((uint32)(((value) << PLLDIG_PLL2FM_STEPNO_SHIFT32 ) & PLLDIG_PLL2FM_STEPNO_MASK32))
#endif

/**************************************************************/
/*                 PLLDIG_PLL2FD                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2FD_U32(value)                ((uint32)(((value) & PLLDIG_PLL2FD_RWBITS_MASK32 ) | PLLDIG_PLL2FD_RESBITS_MASK32 ))

#define MCU_PLLDIG_PLL2FD_FDEN_ENA_U32              (PLLDIG_PLL2FD_FDEN_MASK32)
#define MCU_PLLDIG_PLL2FD_FDEN_DIS_U32              ((uint32)0x00000000U)

#define MCU_PLLDIG_PLL2FD_SMDEN_DIS_U32             (PLLDIG_PLL2FD_SMDEN_MASK32)
#define MCU_PLLDIG_PLL2FD_SMDEN_ENA_U32             (0x00000000U)

#define MCU_PLLDIG_PLL2FD_SDM2_DIS_U32              (0x00000000U)
#define MCU_PLLDIG_PLL2FD_SDM2_ENA_U32              (PLLDIG_PLL2FD_SDM2_MASK32)

#define MCU_PLLDIG_PLL2FD_SDM3_DIS_U32              (0x00000000U)
#define MCU_PLLDIG_PLL2FD_SDM3_ENA_U32              (PLLDIG_PLL2FD_SDM3_MASK32)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2FD_DTHDIS_U32(value)         ((uint32)(((value) << PLLDIG_PLL2FD_DTHDIS_SHIFT32 ) & PLLDIG_PLL2FD_DTHDIS_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2FD_FRCDIV_U32(value)         ((uint32)((value)&PLLDIG_PLL2FD_FRCDIV_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL2FD_MFN_U32(value)            ((uint32)(((value) << PLLDIG_PLL2FD_MFN_SHIFT32 ) & PLLDIG_PLL2FD_MFN_MASK32))



/**************************************************************/
/*                 PLLDIG_PLL3CAL3                            */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3CAL3_U32(value)              ((uint32)(((value) & PLLDIG_PLL3CAL3_RWBITS_MASK32 ) | PLLDIG_PLL3CAL3_RESBITS_MASK32))

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3CAL3_MDFEN_U32(value)        ((uint32)(((value) << PLLDIG_PLL3CAL3_MDFEN_SHIFT32 ) & PLLDIG_PLL3CAL3_MDFEN_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL3CR                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3CR_U32(value)                ((uint32)(((value) & PLLDIG_PLL3CR_RWBITS_MASK32)|PLLDIG_PLL3CR_RESBITS_MASK32))

#define MCU_PLLDIG_PLL3CR_LOLIE_ENA_U32             (PLLDIG_PLL3CR_LOLIE_MASK32)
#define MCU_PLLDIG_PLL3CR_LOLIE_DIS_U32             ((uint32)0x00000000U)

#define MCU_PLLDIG_PLL3CR_EXPDIE_ENA_U32            (PLLDIG_PLL3CR_EXPDIE_MASK32)
#define MCU_PLLDIG_PLL3CR_EXPDIE_DIS_U32            ((uint32)0x00000000U)

/**************************************************************/
/*                 PLLDIG_PLL3SR                              */
/**************************************************************/
#define MCU_PLLDIG_PLL3SR_LOLF_U32                  (PLLDIG_PLL3SR_LOLF_MASK32)
#define MCU_PLLDIG_PLL3SR_LOCK_U32                  (PLLDIG_PLL3SR_LOCK_MASK32)

#define MCU_PLLDIG_PLL3SR_EXTPDF_U32                (PLLDIG_PLL3SR_EXTPDF_MASK32)

/**************************************************************/
/*                 PLLDIG_PLL3DV                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3DV_U32(value)                ((uint32)(((value) & PLLDIG_PLL3DV_RWBITS_MASK32 ) | PLLDIG_PLL3DV_RESBITS_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3DV_RFDPHI1_U32(value)        ((uint32)(((value) << PLLDIG_PLL3DV_RFDPHI1_SHIFT32 ) & PLLDIG_PLL3DV_RFDPHI1_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3DV_RFDPHI_U32(value)         ((uint32)(((value) << PLLDIG_PLL3DV_RFDPHI_SHIFT32 ) & PLLDIG_PLL3DV_RFDPHI_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3DV_PREDIV_U32(value)         ((uint32)(((value) << PLLDIG_PLL3DV_PREDIV_SHIFT32 ) & PLLDIG_PLL3DV_PREDIV_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3DV_MFD_U32(value)            ((uint32)((value) & PLLDIG_PLL3DV_MFD_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL3FM                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3FM_U32(value)                ((uint32)(((value) & PLLDIG_PLL3FM_RWBITS_MASK32 ) |PLLDIG_PLL3FM_RESBITS_MASK32))

#define MCU_PLLDIG_PLL3FM_SSCGBYP_DIS_U32           (0x00000000U)
#define MCU_PLLDIG_PLL3FM_SSCGBYP_ENA_U32           (PLLDIG_PLL3FM_SSCGBYP_MASK32)

#define MCU_PLLDIG_PLL3FM_MODSEL_CENTERED_U32       (0x00000000U)
#define MCU_PLLDIG_PLL3FM_MODSEL_BELOW_U32          (PLLDIG_PLL3FM_MODSEL_MASK32)

#define MCU_PLLDIG_PLL3FM_MODEN_ENA_U32             (PLLDIG_PLL3FM_MODEN_MASK32)
#define MCU_PLLDIG_PLL3FM_MODEN_DIS_U32             ((uint32)0x00000000U)

#define MCU_PLLDIG_PLL3FM_MODSEL_ENA_U32            (PLLDIG_PLL3FM_MODSEL_MASK32)
#define MCU_PLLDIG_PLL3FM_MODSEL_DIS_U32            ((uint32)0x00000000U)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3FM_MODPRD_U32(value)         ((uint32)(((value) << PLLDIG_PLL3FM_MODPRD_SHIFT32 ) & PLLDIG_PLL3FM_MODPRD_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3FM_INCSTP_U32(value)         ((uint32)(((value) << PLLDIG_PLL3FM_INCSTP_SHIFT32 ) & PLLDIG_PLL3FM_INCSTP_MASK32))

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL3FM_STEPSIZE_U32(value)         ((uint32)(((value) << PLLDIG_PLL3FM_STEPSIZE_SHIFT32 ) & PLLDIG_PLL3FM_STEPSIZE_MASK32))
    /** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define MCU_PLLDIG_PLL3FM_STEPNO_U32(value)         ((uint32)(((value) << PLLDIG_PLL3FM_STEPNO_SHIFT32 ) & PLLDIG_PLL3FM_STEPNO_MASK32))
#endif

/**************************************************************/
/*                 PLLDIG_PLL3FD                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3FD_U32(value)                ((uint32)(((value) & PLLDIG_PLL3FD_RWBITS_MASK32 ) | PLLDIG_PLL3FD_RESBITS_MASK32 ))

#define MCU_PLLDIG_PLL3FD_FDEN_ENA_U32              (PLLDIG_PLL3FD_FDEN_MASK32)
#define MCU_PLLDIG_PLL3FD_FDEN_DIS_U32              ((uint32)0x00000000U)

#define MCU_PLLDIG_PLL3FD_SMDEN_DIS_U32             (PLLDIG_PLL3FD_SMDEN_MASK32)
#define MCU_PLLDIG_PLL3FD_SMDEN_ENA_U32             (0x00000000U)

#define MCU_PLLDIG_PLL3FD_SDM2_DIS_U32              (0x00000000U)
#define MCU_PLLDIG_PLL3FD_SDM2_ENA_U32              (PLLDIG_PLL3FD_SDM2_MASK32)

#define MCU_PLLDIG_PLL3FD_SDM3_DIS_U32              (0x00000000U)
#define MCU_PLLDIG_PLL3FD_SDM3_ENA_U32              (PLLDIG_PLL3FD_SDM3_MASK32)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3FD_DTHDIS_U32(value)         ((uint32)(((value) << PLLDIG_PLL3FD_DTHDIS_SHIFT32 ) & PLLDIG_PLL3FD_DTHDIS_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3FD_FRCDIV_U32(value)         ((uint32)((value)&PLLDIG_PLL3FD_FRCDIV_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL3FD_MFN_U32(value)            ((uint32)(((value) << PLLDIG_PLL3FD_MFN_SHIFT32 ) & PLLDIG_PLL3FD_MFN_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL4CR                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL4CR_U32(value)                ((uint32)(((value) & PLLDIG_PLL4CR_RWBITS_MASK32)|PLLDIG_PLL4CR_RESBITS_MASK32))

#define MCU_PLLDIG_PLL4CR_LOLIE_ENA_U32             (PLLDIG_PLL4CR_LOLIE_MASK32)
#define MCU_PLLDIG_PLL4CR_LOLIE_DIS_U32             ((uint32)0x00000000U)

/**************************************************************/
/*                 PLLDIG_PLL4SR                              */
/**************************************************************/
#define MCU_PLLDIG_PLL4SR_LOLF_U32                  (PLLDIG_PLL4SR_LOLF_MASK32)
#define MCU_PLLDIG_PLL4SR_LOCK_U32                  (PLLDIG_PLL4SR_LOCK_MASK32)

/**************************************************************/
/*                 PLLDIG_PLL4DV                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL4DV_U32(value)                ((uint32)(((value) & PLLDIG_PLL4DV_RWBITS_MASK32 ) | PLLDIG_PLL4DV_RESBITS_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL4DV_RFDPHI1_U32(value)        ((uint32)(((value) << PLLDIG_PLL4DV_RFDPHI1_SHIFT32 ) & PLLDIG_PLL4DV_RFDPHI1_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL4DV_RFDPHI_U32(value)         ((uint32)(((value) << PLLDIG_PLL4DV_RFDPHI_SHIFT32 ) & PLLDIG_PLL4DV_RFDPHI_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL4DV_PREDIV_U32(value)         ((uint32)(((value) << PLLDIG_PLL4DV_PREDIV_SHIFT32 ) & PLLDIG_PLL4DV_PREDIV_MASK32))
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL4DV_MFD_U32(value)            ((uint32)((value) & PLLDIG_PLL4DV_MFD_MASK32))

/**************************************************************/
/*                 PLLDIG_PLL4FD                              */
/**************************************************************/
/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL4FD_U32(value)                ((uint32)(((value) & PLLDIG_PLL4FD_RWBITS_MASK32 ) | PLLDIG_PLL4FD_RESBITS_MASK32 ))

#define MCU_PLLDIG_PLL4FD_SMDEN_DIS_U32             (PLLDIG_PLL4FD_SMDEN_MASK32)
#define MCU_PLLDIG_PLL4FD_SMDEN_ENA_U32             (0x00000000U)

/** @violates @ref Mcu_PLLDIG_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define MCU_PLLDIG_PLL4FD_MFN_U32(value)            ((uint32)(((value) << PLLDIG_PLL4FD_MFN_SHIFT32 ) & PLLDIG_PLL4FD_MFN_MASK32))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum
{
    MCU_PLLDIG_PLL_LOCKED = 0x33U,   /**< @brief PLL is locked. */
    MCU_PLLDIG_PLL_UNLOCKED = 0xCCU,   /**< @brief PLL is unlocked. */
    MCU_PLLDIG_PLL_STATUS_UNDEFINED = 0x5AU   /**< @brief PLL Status is unknown. */

} Mcu_PLLDIG_PllStatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            PLLDIG addr and value pair.
* @details          this structure is used to represent a pair of addr and data to be written to
*                   hardware
*/
typedef struct
{
   VAR( uint32, MCU_VAR) u32RegisterAddr; /**< @brief  register address, added by hand in the code template */
   VAR( uint32, MCU_VAR) u32RegisterData; /**< @brief  generated value, as it's already defined */

} Mcu_PLLDIG_RegisterConfigType;

/**
* @brief            PLLDIG IP configuration.
* @details          This structure contains information PLL
*/
typedef struct
{
    /**< @brief number of PLL registers under MCU control */
    VAR (uint8, MCU_VAR)  u8NoOfPllDigRegsUnderMcuControl;
    /**< @brief PLL configuration registers */
    CONST( Mcu_PLLDIG_RegisterConfigType, MCU_CONST) (*apPllDigConfig)[];
    
} Mcu_PLLDIG_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_PLLDIG_TYPES_H */

/** @} */
