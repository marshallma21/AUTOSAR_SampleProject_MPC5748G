/**
*   @file    Wdg_Swt.h
*   @version 1.0.0
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) Registers
*   @details Contains information about the SWT's registers
*
*   @addtogroup  Wdg
*   @{
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

#ifndef WDG_SWT_H
#define WDG_SWT_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Swt_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
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
/** @violates @ref Wdg_Swt_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                  of a header file being included twice */
#include "Wdg_Swt_Types.h"
#include "Wdg_Cfg.h"
/**
* @file           Wdg_Swt.h   
*/


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Swt.h    
*/
#define WDG_SWT_VENDOR_ID                       43
#define WDG_SWT_MODULE_ID                       102
#define WDG_SWT_AR_RELEASE_MAJOR_VERSION        4
#define WDG_SWT_AR_RELEASE_MINOR_VERSION        2
#define WDG_SWT_AR_RELEASE_REVISION_VERSION     2
#define WDG_SWT_SW_MAJOR_VERSION                1
#define WDG_SWT_SW_MINOR_VERSION                0
#define WDG_SWT_SW_PATCH_VERSION                0

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Wdg_Swt_Types.h header file are of the same vendor */
#if (WDG_SWT_VENDOR_ID != WDG_SWT_TYPES_VENDOR_ID)
    #error "Wdg_Swt.h and Wdg_Swt_Types.h have different vendor ids"
#endif

/* Check if source file and Wdg_Swt_Types.h header file are of the same Autosar version */
#if ((WDG_SWT_AR_RELEASE_MAJOR_VERSION    != WDG_SWT_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_MINOR_VERSION    != WDG_SWT_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_REVISION_VERSION != WDG_SWT_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt.h and Wdg_Swt_Types.h are different"
#endif

/* Check if source file and Wdg_Swt_Types.h header file are of the same Software version */
#if ((WDG_SWT_SW_MAJOR_VERSION != WDG_SWT_TYPES_SW_MAJOR_VERSION) || \
     (WDG_SWT_SW_MINOR_VERSION != WDG_SWT_TYPES_SW_MINOR_VERSION) || \
     (WDG_SWT_SW_PATCH_VERSION != WDG_SWT_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt.h and Wdg_Swt_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"


/*This function initializes the hardware of WDG module. */
FUNC(uint32, WDG_CODE) Wdg_Swt_Init(P2CONST(Wdg_Swt_ConfigType, AUTOMATIC, WDG_APPL_CONST) Swt_pConfigPtr,
                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                   );

/* Switches the watchdog into the mode Mode. */
FUNC(Std_ReturnType, WDG_CODE) Wdg_Swt_SetMode(P2CONST(Wdg_Swt_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
                                               CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                              );


/*  This function triggers the watchdog hardware. */
FUNC(void, WDG_CODE) Wdg_Swt_Trigger(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);

/* The function checks the hardware settings for the parameter.*/
FUNC(Std_ReturnType, WDG_CODE)
     Wdg_Swt_CheckHwSettings(P2CONST(Wdg_Swt_ConfigType, AUTOMATIC, WDG_APPL_CONST) Swt_pConfigPtr,
                             CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                            );


#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* WDG_SWT_H */

/** @} */
