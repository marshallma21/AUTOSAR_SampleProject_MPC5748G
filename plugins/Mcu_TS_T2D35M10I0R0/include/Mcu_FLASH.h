/**
*   @file    Mcu_FLASH.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Function prototypes.
*   @details Interface available for IPW layer only.
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


#ifndef MCU_FLASH_H
#define MCU_FLASH_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_FLASH_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_FLASH_h_REF_2
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Mcu_FLASH_h_REF_3
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
#include "Mcu_FLASH_Types.h"
#include "Mcu_EnvCfg.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_FLASH_VENDOR_ID                        43
#define MCU_FLASH_AR_RELEASE_MAJOR_VERSION         4
#define MCU_FLASH_AR_RELEASE_MINOR_VERSION         2
#define MCU_FLASH_AR_RELEASE_REVISION_VERSION      2
#define MCU_FLASH_SW_MAJOR_VERSION                 1
#define MCU_FLASH_SW_MINOR_VERSION                 0
#define MCU_FLASH_SW_PATCH_VERSION                 0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_FLASH_VENDOR_ID != MCU_FLASH_TYPES_VENDOR_ID)
    #error "Mcu_FLASH.h and Mcu_FLASH_Types.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_FLASH_AR_RELEASE_MAJOR_VERSION != MCU_FLASH_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FLASH_AR_RELEASE_MINOR_VERSION != MCU_FLASH_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FLASH_AR_RELEASE_REVISION_VERSION != MCU_FLASH_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FLASH.h and Mcu_FLASH_Types.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_FLASH_SW_MAJOR_VERSION != MCU_FLASH_TYPES_SW_MAJOR_VERSION) || \
     (MCU_FLASH_SW_MINOR_VERSION != MCU_FLASH_TYPES_SW_MINOR_VERSION) || \
     (MCU_FLASH_SW_PATCH_VERSION != MCU_FLASH_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FLASH.h and Mcu_FLASH_Types.h are different"
#endif

/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_FLASH_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_FLASH.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_FLASH_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FLASH_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FLASH_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FLASH.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_FLASH_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_FLASH_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_FLASH_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FLASH.h and Mcu_EnvCfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_FLASH_h_REF_1 Repeated include files
*/
#include "Mcu_MemMap.h"

#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_FLASH_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_FLASH_Init(FLASH_pConfigPtr) \
do\
{ \
      Mcal_Trusted_Call(Mcu_FLASH_Init,(FLASH_pConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_FLASH_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_FLASH_Init( FLASH_pConfigPtr) \
do\
{ \
        Mcu_FLASH_Init(FLASH_pConfigPtr); \
}\
while(0)
#endif
#endif

/** @violates @ref Mcu_FLASH_h_REF_2 these object are used trough the entire MCU code*/
extern P2FUNC (void, MCU_CODE, Mcu_FLASH_Init) (P2CONST( Mcu_FLASH_ConfigType, AUTOMATIC, MCU_APPL_DATA) FLASH_pConfigPtr);
#endif /* (MCU_DISABLE_FLASH_CONFIG == STD_OFF) */

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_FLASH_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_FLASH_SetWS(FLASH_pClockConfigPtr) \
do\
{ \
        Mcal_Trusted_Call(Mcu_FLASH_SetWS,(FLASH_pClockConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_FLASH_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_FLASH_SetWS( FLASH_pClockConfigPtr) \
do\
{ \
        Mcu_FLASH_SetWS(FLASH_pClockConfigPtr); \
}\
while(0)
#endif
#endif

/** @violates @ref Mcu_FLASH_h_REF_2 these object are used trough the entire MCU code*/
extern P2FUNC (void, MCU_CODE, Mcu_FLASH_SetWS) (P2CONST( Mcu_FLASH_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) FLASH_pClockConfigPtr);
#endif /* (MCU_DISABLE_FLASH_CONFIG == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_FLASH_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* MCU_FLASH_H */

/** @} */

