/**
*   @file    Mcu_IPW_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from IPW.
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


#ifndef MCU_IPW_TYPES_H
#define MCU_IPW_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_IPW_Types_h_REF_1
* Violates MISRA 2004 Required Rule 20.2, The names of standard macros, objects and
* functions shall not be reused
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_MC_CGM_Types.h"
#include "Mcu_FIRC_Types.h"
#include "Mcu_FXOSC_Types.h"
#include "Mcu_MC_ME_Types.h"
#include "Mcu_MC_RGM_Types.h"
#include "Mcu_MC_PCU_Types.h"
#include "Mcu_PMCDIG_Types.h"
#include "Mcu_CMU_Types.h"
#include "Mcu_SIRC_Types.h"
#include "Mcu_STCU_Types.h"
#include "Mcu_SXOSC_Types.h"
#if (MCU_SRAMC_SUPPORT == STD_ON)
  #include "Mcu_PRAM_Types.h"
#endif /* (MCU_SRAMC_SUPPORT == STD_ON) */
#include "Mcu_FLASH_Types.h"
#include "Mcu_PLLDIG_Types.h"
#include "Mcu_SSCM_Types.h"
#include "Mcu_SIUL2_Types.h"
#if (MCU_EMIOS_SUPPORT == STD_ON)
#include "Mcu_eMios_Types.h"
#endif
#if (MCU_LPU_SUPPORT == STD_ON)
#include "Mcu_LPU_Types.h"
#endif
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcu_IPW_Types.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define MCU_IPW_TYPES_VENDOR_ID                       43
#define MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCU_IPW_TYPES_SW_MAJOR_VERSION                1
#define MCU_IPW_TYPES_SW_MINOR_VERSION                0
#define MCU_IPW_TYPES_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/

/* Check if current file and Mcu_MC_CGM_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_MC_CGM_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_MC_CGM_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_MC_CGM_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_MC_CGM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_MC_CGM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_MC_CGM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_MC_CGM_Types.h are different"
#endif

/* Check if current file and Mcu_MC_CGM_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_MC_CGM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_MC_CGM_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_MC_CGM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_MC_CGM_Types.h are different"
#endif

/* Check if current file and Mcu_FIRC_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_FIRC_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_FIRC_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_FIRC_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_FIRC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_FIRC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_FIRC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_FIRC_Types.h are different"
#endif

/* Check if current file and Mcu_FIRC_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_FIRC_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_FIRC_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_FIRC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_FIRC_Types.h are different"
#endif

/* Check if current file and Mcu_FXOSC_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_FXOSC_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_FXOSC_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_FXOSC_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_FXOSC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_FXOSC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_FXOSC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_FXOSC_Types.h are different"
#endif

/* Check if current file and Mcu_FXOSC_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_FXOSC_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_FXOSC_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_FXOSC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_FXOSC_Types.h are different"
#endif

/* Check if current file and Mcu_MC_ME_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_MC_ME_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_MC_ME_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_MC_ME_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_MC_ME_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_MC_ME_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_MC_ME_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_MC_ME_Types.h are different"
#endif

/* Check if current file and Mcu_MC_ME_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_MC_ME_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_MC_ME_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_MC_ME_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_MC_ME_Types.h are different"
#endif

/* Check if current file and Mcu_MC_RGM_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_MC_RGM_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_MC_RGM_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_MC_RGM_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_MC_RGM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_MC_RGM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_MC_RGM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_MC_RGM_Types.h are different"
#endif

/* Check if current file and Mcu_MC_RGM_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_MC_RGM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_MC_RGM_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_MC_RGM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_MC_RGM_Types.h are different"
#endif

/* Check if current file and Mcu_MC_PCU_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_MC_PCU_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_MC_PCU_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_MC_PCU_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_MC_PCU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_MC_PCU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_MC_PCU_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_MC_PCU_Types.h are different"
#endif

/* Check if current file and Mcu_MC_PCU_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_MC_PCU_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_MC_PCU_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_MC_PCU_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_MC_PCU_Types.h are different"
#endif

/* Check if current file and Mcu_PMCDIG_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_PMCDIG_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_PMCDIG_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_PMCDIG_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_PMCDIG_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_PMCDIG_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_PMCDIG_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_PMCDIG_Types.h are different"
#endif

/* Check if current file and Mcu_PMCDIG_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_PMCDIG_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_PMCDIG_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_PMCDIG_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_PMCDIG_Types.h are different"
#endif

/* Check if current file and Mcu_CMU_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_CMU_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_CMU_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_CMU_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_CMU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_CMU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CMU_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_CMU_Types.h are different"
#endif

/* Check if current file and Mcu_CMU_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_CMU_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_CMU_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_CMU_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_CMU_Types.h are different"
#endif

/* Check if current file and Mcu_SIRC_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_SIRC_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_SIRC_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_SIRC_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_SIRC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_SIRC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_SIRC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_SIRC_Types.h are different"
#endif

/* Check if current file and Mcu_SIRC_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_SIRC_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_SIRC_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_SIRC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_SIRC_Types.h are different"
#endif

/* Check if current file and Mcu_STCU_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_STCU_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_STCU_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_STCU_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_STCU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_STCU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_STCU_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_STCU_Types.h are different"
#endif

/* Check if current file and Mcu_STCU_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_STCU_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_STCU_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_STCU_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_STCU_Types.h are different"
#endif

/* Check if current file and Mcu_SXOSC_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_SXOSC_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_SXOSC_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_SXOSC_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_SXOSC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_SXOSC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_SXOSC_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_SXOSC_Types.h are different"
#endif

/* Check if current file and Mcu_SXOSC_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_SXOSC_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_SXOSC_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_SXOSC_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_SXOSC_Types.h are different"
#endif

#if (MCU_SRAMC_SUPPORT == STD_ON)
/* Check if current file and Mcu_PRAM_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_PRAM_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_PRAM_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_PRAM_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_PRAM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_PRAM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_PRAM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_PRAM_Types.h are different"
#endif

/* Check if current file and Mcu_PRAM_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_PRAM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_PRAM_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_PRAM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_PRAM_Types.h are different"
#endif
#endif

/* Check if current file and Mcu_FLASH_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_FLASH_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_FLASH_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_FLASH_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_FLASH_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_FLASH_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_FLASH_Types.h are different"
#endif

/* Check if current file and Mcu_FLASH_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_FLASH_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_FLASH_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_FLASH_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_FLASH_Types.h are different"
#endif

/* Check if current file and Mcu_PLLDIG_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_PLLDIG_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_PLLDIG_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_PLLDIG_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_PLLDIG_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_PLLDIG_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_PLLDIG_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_PLLDIG_Types.h are different"
#endif

/* Check if current file and Mcu_PLLDIG_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_PLLDIG_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_PLLDIG_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_PLLDIG_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_PLLDIG_Types.h are different"
#endif

/* Check if current file and Mcu_SSCM_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_SSCM_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_SSCM_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_SSCM_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_SSCM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_SSCM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_SSCM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_SSCM_Types.h are different"
#endif

/* Check if current file and Mcu_SSCM_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_SSCM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_SSCM_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_SSCM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_SSCM_Types.h are different"
#endif

/* Check if current file and Mcu_SIUL2_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_SIUL2_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_SIUL2_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_SIUL2_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_SIUL2_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_SIUL2_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_SIUL2_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_SIUL2_Types.h are different"
#endif

/* Check if current file and Mcu_SIUL2_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_SIUL2_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_SIUL2_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_SIUL2_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_SIUL2_Types.h are different"
#endif

#if (MCU_EMIOS_SUPPORT == STD_ON)
/* Check if current file and Mcu_eMios_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_EMIOS_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_eMios_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_eMios_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_eMios_Types.h are different"
#endif

/* Check if current file and Mcu_eMios_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_EMIOS_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_EMIOS_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_EMIOS_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_eMios_Types.h are different"
#endif
#endif

#if (MCU_LPU_SUPPORT == STD_ON)
/* Check if current file and Mcu_LPU_Types header file are of the same vendor */
#if (MCU_IPW_TYPES_VENDOR_ID != MCU_LPU_TYPES_VENDOR_ID)
    #error "Mcu_IPW_Types.h and Mcu_LPU_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_LPU_Types header file are of the same Autosar version */
#if ((MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCU_LPU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCU_LPU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCU_LPU_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW_Types.h and Mcu_LPU_Types.h are different"
#endif

/* Check if current file and Mcu_LPU_Types header file are of the same Software version */
#if ((MCU_IPW_TYPES_SW_MAJOR_VERSION != MCU_LPU_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_TYPES_SW_MINOR_VERSION != MCU_LPU_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_TYPES_SW_PATCH_VERSION != MCU_LPU_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW_Types.h and Mcu_LPU_Types.h are different"
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Define macro for clock under Mcu control */
#define MCU_IPW_FIRC_UNDER_MCU_CONTROL          ((uint8)0x01U)
#define MCU_IPW_FIRC_NOT_UNDER_MCU_CONTROL      ((uint8)0x00U)

#define MCU_IPW_SIRC_UNDER_MCU_CONTROL          ((uint8)0x02U)
#define MCU_IPW_SIRC_NOT_UNDER_MCU_CONTROL      ((uint8)0x00U)

#define MCU_IPW_SXOSC_UNDER_MCU_CONTROL          ((uint8)0x04U)
#define MCU_IPW_SXOSC_NOT_UNDER_MCU_CONTROL      ((uint8)0x00U)

#define MCU_IPW_FXOSC_UNDER_MCU_CONTROL          ((uint8)0x08U)
#define MCU_IPW_FXOSC_NOT_UNDER_MCU_CONTROL      ((uint8)0x00U)

#define MCU_IPW_PLL0_UNDER_MCU_CONTROL           ((uint8)0x10U)
#define MCU_IPW_PLL0_NOT_UNDER_MCU_CONTROL       ((uint8)0x00U)


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief        Mcu_ClockNotificationType
* @details      Clock failure notification.
*               Enable/disable clock failure interrupt generated by the MCU.
*/
typedef enum
{
    MCU_CLK_NOTIF_DIS = 0x5AU,   /**< @brief Disable clock notification. */ 
    MCU_CLK_NOTIF_EN = 0xA5U  /**< @brief Enable clock notification. */ 

} Mcu_ClockNotificationType;
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief            Mcu driver configuration structure.
* @details          Configuration for Mode Entry Module (MC_ME) module:
*                       - ME_RUN_PC0...7 registers
*                       - ME_LP_PC0...7 registers
*                       - ME_PCTLx registers
*                   Configuration for MC_RGM module.
*                   Configuration for FLASH controller.
*                   Used by "Mcu_ConfigType" structure.
*
*/
typedef struct
{
    /**< @brief Configuration for MC_ME (Mode Entry Module) hardware IP. */
    P2CONST( Mcu_MC_ME_ConfigType, MCU_VAR, MCU_APPL_CONST) MC_ME_pConfig;
    /**< @brief Configuration for MC_RGM (Reset Generation Module) hardware IP. */
    P2CONST( Mcu_MC_RGM_ConfigType, MCU_VAR, MCU_APPL_CONST) MC_RGM_pConfig;
    /**< @brief Configuration for FLASH (Flash Memory) hardware IP. */
    P2CONST( Mcu_FLASH_ConfigType, MCU_VAR, MCU_APPL_CONST) FLASH_pConfig;
    /**< @brief Configuration for PMCIDG hardware IP. */
    P2CONST( Mcu_PMCDIG_ConfigType, MCU_VAR, MCU_APPL_CONST) MC_PMCDIG_pConfig ;
} Mcu_HwIPsConfigType;


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            Definition of a Clock configuration.
* @details          This configuration is transmitted as parameter to Mcu_Ipw_InitClock() API.
*                   Used by "Mcu_ConfigType" structure.
*
* @note             The structure Mcu_ConfigType shall provide a configurable (enable/ disable)
*                   clock failure notification if the MCU provides an interrupt for such detection.
*
*/
typedef struct
{
    /**< @brief The ID for Clock configuration. */
    VAR( Mcu_ClockType, MCU_VAR) Mcu_ClkConfigId;
    /**< @brief Clock error notification enable configuration. */
    VAR( Mcu_ClockNotificationType, MCU_VAR) Mcu_ClkNotification;
    /**< @brief System Clock for current Clock configuration.
    * This affect the Mode settings from MC_ME IP. */
    VAR( uint32, MCU_VAR ) Mcu_u32SystemClkSource;
    /**< @brief MC_CGM IP Clock settings. */
    P2CONST( Mcu_MC_CGM_ClockConfigType, MCU_VAR, MCU_APPL_CONST) MC_CGM_pClockConfig;
    /**< @brief PLLDIG IP Clock settings. */
    P2CONST( Mcu_PLLDIG_ConfigType, MCU_VAR, MCU_APPL_CONST) MC_PLLDIG_pClockConfig;
#if (MCU_EMIOS_SUPPORT == STD_ON)
    /**< @brief EMIOS Clock settings. */
    /** @violates @ref Mcu_IPW_Types_h_REF_1 This is not a standard library macro. */
    P2CONST( Mcu_eMios_ConfigType, MCU_VAR, MCU_APPL_CONST) EMIOS_pClockConfig;
#endif
    /**< @brief CMU IP Clock settings. */
    P2CONST( Mcu_CMU_ConfigType, MCU_VAR, MCU_APPL_CONST) Mcu_CMU_pClockConfig;
    /**< @brief FIRC IP Clock settings. */
    P2CONST( Mcu_FIRC_ConfigType, MCU_VAR, MCU_APPL_CONST) FIRC_pClockConfig;
    /**< @brief SIRC IP Clock settings. */
    P2CONST( Mcu_SIRC_ConfigType, MCU_VAR, MCU_APPL_CONST) SIRC_pClockConfig;
    /**< @brief FXOSC IP Clock settings. */
    P2CONST( Mcu_FXOSC_ConfigType, MCU_VAR, MCU_APPL_CONST) FXOSC_pClockConfig;
    /**< @brief SXOSC IP Clock settings. */
    P2CONST( Mcu_SXOSC_ConfigType, MCU_VAR, MCU_APPL_CONST) SXOSC_pClockConfig;
#if (MCU_SRAMC_SUPPORT == STD_ON)
    /**< @brief SRAMC IP Clock settings. */
    P2CONST( Mcu_PRAM_ClockConfigType, MCU_VAR, MCU_APPL_CONST) SRAMC_pClockConfig;
#endif /* (MCU_SRAMC_SUPPORT == STD_ON) */
    /**< @brief FLASH IP Clock settings. */
    P2CONST( Mcu_FLASH_ClockConfigType, MCU_VAR, MCU_APPL_CONST) FLASH_pClockConfig;
    /**< @brief Clock sources and PLLs under mcu control. */
    VAR( uint8, MCU_VAR) u8ClockSourcesControl;
} Mcu_ClockConfigType;
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

#endif /* MCU_IPW_TYPES_H */


/** @} */
