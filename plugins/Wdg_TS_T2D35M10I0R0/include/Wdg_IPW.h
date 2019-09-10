/**
* @file    Wdg_IPW.h
* @version 1.0.0
* @brief   AUTOSAR Wdg - IP Wrapper for Wdg
* @details Contains the platform specific implementation for WDG
*
* @addtogroup  Wdg
* @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : Swt
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

#ifndef WDG_IPW_H
#define WDG_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_IPW_h_REF_1
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*          Middle layer between AUTOSAR and hardware needs a way to map HLD
*          functions to LLD functions.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*/



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Wdg_Swt.h"
/**
* @file          Wdg_IPW.h  
*/


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file          Wdg_IPW.h    
*/
#define WDG_IPW_VENDOR_ID                    43
#define WDG_IPW_AR_RELEASE_MAJOR_VERSION     4
#define WDG_IPW_AR_RELEASE_MINOR_VERSION     2
#define WDG_IPW_AR_RELEASE_REVISION_VERSION  2
#define WDG_IPW_SW_MAJOR_VERSION             1
#define WDG_IPW_SW_MINOR_VERSION             0
#define WDG_IPW_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Swt header file are of the same vendor */
#if (WDG_IPW_VENDOR_ID != WDG_SWT_VENDOR_ID)
    #error "Wdg_IPW.h and Wdg_Swt.h have different vendor ids"
#endif
/* Check if current file and Wdg_Swt header file are of the same Autosar version */
#if ((WDG_IPW_AR_RELEASE_MAJOR_VERSION    != WDG_SWT_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_MINOR_VERSION    != WDG_SWT_AR_RELEASE_MINOR_VERSION) || \
     (WDG_IPW_AR_RELEASE_REVISION_VERSION != WDG_SWT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Wdg_IPW.h and Wdg_Swt.h are different"
#endif
/* Check if current file and SWT header file are of the same Software version */
#if ((WDG_IPW_SW_MAJOR_VERSION != WDG_SWT_SW_MAJOR_VERSION) || \
     (WDG_IPW_SW_MINOR_VERSION != WDG_SWT_SW_MINOR_VERSION) || \
     (WDG_IPW_SW_PATCH_VERSION != WDG_SWT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Wdg_IPW.h and Wdg_Swt.h are different"
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between SWT initialization function and high level initialization function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_Init(Wdg_IPW_ConfigPtr, Wdg_Instance) (Wdg_Swt_Init((Wdg_IPW_ConfigPtr), (Wdg_Instance)))
#endif

#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between SWT initialization function and high level set mode function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_SetMode(Wdg_IPW_ConfigPtr, Wdg_Instance) (Wdg_Swt_Init((Wdg_IPW_ConfigPtr), (Wdg_Instance)))
#endif

#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between SWT trigger function and high level trigger function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_Trigger(Wdg_Instance) (Wdg_Swt_Trigger(Wdg_Instance))
#endif


#if (WDG_INTERNAL_MODULE == WDG_TYPE)
/**
* @brief Mapping macro between SWT check hw settings and high level check hw settings function
*
* @violates @ref Wdg_IPW_h_REF_1  MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
 #define Wdg_IPW_CheckHwSettings(Wdg_IPW_ConfigPtr, Wdg_Instance) (Wdg_Swt_CheckHwSettings((Wdg_IPW_ConfigPtr), (Wdg_Instance)))
#endif

/*==================================================================================================
*                                            ENUMS
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

#endif /*WDG_IPW_H*/
/** @} */
