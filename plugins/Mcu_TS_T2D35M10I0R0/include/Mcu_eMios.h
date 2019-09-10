/**
*   @file    Mcu_eMios.h
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

/**
*
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_eMios_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Precautions shall be taken in order to prevent the contents of a
* header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
* 
*/
#ifndef MCU_EMIOS_H
#define MCU_EMIOS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcu_eMios_Types.h"
#include "Mcu_EnvCfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_EMIOS_H_VENDOR_ID                       43
#define MCU_EMIOS_H_AR_RELEASE_MAJOR_VERSION        4
#define MCU_EMIOS_H_AR_RELEASE_MINOR_VERSION        2
#define MCU_EMIOS_H_AR_RELEASE_REVISION_VERSION     2
#define MCU_EMIOS_H_SW_MAJOR_VERSION                1
#define MCU_EMIOS_H_SW_MINOR_VERSION                0
#define MCU_EMIOS_H_SW_PATCH_VERSION                0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Std_Types header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_EMIOS_H_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_EMIOS_H_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_eMios.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Mcu_eMios_Types file are of the same vendor */
#if (MCU_EMIOS_H_VENDOR_ID != MCU_EMIOS_TYPES_VENDOR_ID)
    #error "Mcu_eMios.h and Mcu_eMios_Types.h have different vendor ids"
#endif
/* Check if source file and Mcu_eMios_Types header file are of the same Autosar version */
 #if ((MCU_EMIOS_H_AR_RELEASE_MAJOR_VERSION != MCU_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
      (MCU_EMIOS_H_AR_RELEASE_MINOR_VERSION != MCU_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION) || \
      (MCU_EMIOS_H_AR_RELEASE_REVISION_VERSION != MCU_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION) \
     )
    #error "AutoSar Version Numbers of Mcu_eMios.h and Mcu_eMios_Types.h are different"
#endif
/* Check if source file and Mcu_eMios_Types header file are of the same software version */
#if ((MCU_EMIOS_H_SW_MAJOR_VERSION != MCU_EMIOS_TYPES_SW_MAJOR_VERSION) || \
     (MCU_EMIOS_H_SW_MINOR_VERSION != MCU_EMIOS_TYPES_SW_MINOR_VERSION) || \
     (MCU_EMIOS_H_SW_PATCH_VERSION != MCU_EMIOS_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_eMios.h and Mcu_eMios_Types.h are different"
#endif

/* Check if source file and Mcu_EnvCfg header file are from the same vendor */
#if (MCU_EMIOS_H_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_eMios.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_EMIOS_H_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_EMIOS_H_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_EMIOS_H_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_eMios.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_EMIOS_H_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_EMIOS_H_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_EMIOS_H_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_eMios.h and Mcu_EnvCfg.h are different"
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
/* @violates @ref Mcu_eMios_H_REF_1 Repeated include file */
#include "Mcu_MemMap.h"

#if (MCU_EMIOS_SUPPORT == STD_ON)
FUNC (void, MCU_CODE) Mcu_eMios_Init(VAR (uint8, AUTOMATIC) u8Module, P2CONST(Mcu_eMios_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr);
#endif

#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_eMios_ConfigureGpren(VAR (uint8, AUTOMATIC) u8Module, VAR (uint8, AUTOMATIC) u8Value);
#endif

#define MCU_STOP_SEC_CODE
/* @violates @ref Mcu_eMios_H_REF_1 Repeated include file */
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif   /* MCU_EMIOS_H */
/** @} */
