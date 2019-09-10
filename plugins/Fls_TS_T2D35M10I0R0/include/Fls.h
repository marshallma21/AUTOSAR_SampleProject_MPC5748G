/**
*   @file    Fls.h
*   @implements Fls.h_Artifact 
*   @version 1.0.0
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Include all external API declarations and definitions of all pre-compile parameters.
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

#ifndef FLS_H
#define FLS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Fls_Cfg.h"
#include "Fls_Api.h"
#include "Fls_Version.h"
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Mcal.h header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fls.h and Mcal.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Fls_Cfg.h header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION != FLS_AR_RELEASE_MAJOR_VERSION_CFG) || \
         (FLS_AR_RELEASE_MINOR_VERSION != FLS_AR_RELEASE_MINOR_VERSION_CFG))
        #error "AutoSar Version Numbers of Fls.h and Fls_Cfg.h are different"
    #endif
#endif
/* Check if header file and Fls_Cfg.h header file are of the same vendor */
#if (FLS_VENDOR_ID != FLS_VENDOR_ID_CFG)
    #error "Fls.h and Fls_Cfg.h have different vendor ids"
#endif
/* Check if header file and Fls_Cfg.h header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION != FLS_SW_MAJOR_VERSION_CFG) || \
     (FLS_SW_MINOR_VERSION != FLS_SW_MINOR_VERSION_CFG) || \
     (FLS_SW_PATCH_VERSION != FLS_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Fls.h and Fls_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Fls_Api.h header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION != FLS_API_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION != FLS_API_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fls.h and Fls_Api.h are different"
    #endif
#endif
/* Check if header file and Fls_Api.h header file are of the same vendor */
#if (FLS_VENDOR_ID != FLS_API_VENDOR_ID)
    #error "Fls.h and Fls_Api.h have different vendor ids"
#endif
/* Check if header file and Fls_Api.h header file are of the same software version */
#if ((FLS_SW_MAJOR_VERSION != FLS_API_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION != FLS_API_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION != FLS_API_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fls.h and Fls_Api.h are different"
#endif

#ifdef __cplusplus
}
#endif

#endif /* FLS_H */

/** @} */

