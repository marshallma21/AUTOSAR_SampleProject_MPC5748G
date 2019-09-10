/**
*   @file    Wdg_Swt_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Wdg - Wdg_SWT Types.
*   @details Contains the Wdg_Swt Types that are exported
*
*   @addtogroup Wdg
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

#ifndef WDG_SWT_TYPES_H
#define WDG_SWT_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Wdg_Swt_Types_h_REF_1
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
/** @violates @ref Wdg_Swt_Types_h_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the contents
*                  of a header file being included twice */
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Swt_Types.h
*/
#define WDG_SWT_TYPES_VENDOR_ID                    43
#define WDG_SWT_TYPES_MODULE_ID                    102
#define WDG_SWT_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define WDG_SWT_TYPES_AR_RELEASE_MINOR_VERSION     2
#define WDG_SWT_TYPES_AR_RELEASE_REVISION_VERSION  2
#define WDG_SWT_TYPES_SW_MAJOR_VERSION             1
#define WDG_SWT_TYPES_SW_MINOR_VERSION             0
#define WDG_SWT_TYPES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Std_Types header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_SWT_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_SWT_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Reg_eSys_Types.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Wdg_Swt_ConfigType.
* @details        Contains the information related to the hardware setup for SWT

*/
typedef struct
{
    uint32              Swt_u32Config;       /**< @brief SWT configuration */
    uint32              Swt_u32Timeout;      /**< @brief SWT timeout */
    uint32              Swt_u32Window;      /**< @brief SWT window */
    uint32              Swt_u32InitialKey;   /**< @brief SWT initial key value */
    uint32              Wdg_u32InternalTimerClock; /**< @brief SWT internal clock frequency */
}Wdg_Swt_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/



/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /*WDG_SWT_TYPES_H*/

/** @} */
