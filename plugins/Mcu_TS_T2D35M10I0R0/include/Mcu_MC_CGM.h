/**
*   @file    Mcu_MC_CGM.h
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


#ifndef MCU_MC_CGM_H
#define MCU_MC_CGM_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_CGM_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_MC_CGM_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, : The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
*
* @section Mcu_MC_CGM_h_REF_3
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
#include "Mcu_MC_CGM_Types.h"
#include "Mcu_EnvCfg.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_MC_CGM_VENDOR_ID                        43
/** @violates @ref Mcu_MC_CGM_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION         4
/** @violates @ref Mcu_MC_CGM_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_AR_RELEASE_MINOR_VERSION         2
/** @violates @ref Mcu_MC_CGM_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_CGM_AR_RELEASE_REVISION_VERSION      2
#define MCU_MC_CGM_SW_MAJOR_VERSION                 1
#define MCU_MC_CGM_SW_MINOR_VERSION                 0
#define MCU_MC_CGM_SW_PATCH_VERSION                 0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_MC_CGM_Types header file are from the same vendor */
#if (MCU_MC_CGM_VENDOR_ID != MCU_MC_CGM_TYPES_VENDOR_ID)
    #error "Mcu_MC_CGM.h and Mcu_MC_CGM_Types.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_CGM_Types header file are of the same Autosar version */
#if ((MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION != MCU_MC_CGM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_CGM_AR_RELEASE_MINOR_VERSION != MCU_MC_CGM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_CGM_AR_RELEASE_REVISION_VERSION != MCU_MC_CGM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_CGM.h and Mcu_MC_CGM_Types.h are different"
#endif
/* Check if source file and Mcu_MC_CGM_Types header file are of the same Software version */
#if ((MCU_MC_CGM_SW_MAJOR_VERSION != MCU_MC_CGM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_MC_CGM_SW_MINOR_VERSION != MCU_MC_CGM_TYPES_SW_MINOR_VERSION) || \
     (MCU_MC_CGM_SW_PATCH_VERSION != MCU_MC_CGM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_CGM.h and Mcu_MC_CGM_Types.h are different"
#endif

/* Check if source file and Mcu_EnvCfg header file are from the same vendor */
#if (MCU_MC_CGM_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_MC_CGM.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_CGM_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_CGM_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_CGM.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_MC_CGM_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_MC_CGM_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_MC_CGM_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_CGM.h and Mcu_EnvCfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
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
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_MC_CGM_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


#if (MCU_INIT_CLOCK == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_MC_CGM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_MC_CGM_SystemClockConfig(MC_CGM_pClockConfigPtr) \
do\
{ \
        Mcal_Trusted_Call(Mcu_MC_CGM_SystemClockConfig,(MC_CGM_pClockConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_MC_CGM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_MC_CGM_SystemClockConfig(MC_CGM_pClockConfigPtr) \
do\
{ \
        Mcu_MC_CGM_SystemClockConfig(MC_CGM_pClockConfigPtr); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_MC_CGM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_MC_CGM_AuxClockConfig(MC_CGM_pClockConfigPtr) \
do\
{ \
        Mcal_Trusted_Call(Mcu_MC_CGM_AuxClockConfig,(MC_CGM_pClockConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_MC_CGM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_MC_CGM_AuxClockConfig(MC_CGM_pClockConfigPtr) \
do\
{ \
        Mcu_MC_CGM_AuxClockConfig(MC_CGM_pClockConfigPtr); \
}\
while(0)
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
    FUNC( void, MCU_CODE) Mcu_MC_CGM_SetUserAccessAllowed(void);
#endif
#endif
    FUNC( void, MCU_CODE) Mcu_MC_CGM_ProgClockSwitchConfig(P2CONST( Mcu_MC_CGM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) MC_CGM_pClockConfigPtr);
    FUNC( void, MCU_CODE) Mcu_MC_CGM_SystemClockConfig(P2CONST( Mcu_MC_CGM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) MC_CGM_pClockConfigPtr);
    FUNC( void, MCU_CODE) Mcu_MC_CGM_AuxClockConfig(P2CONST( Mcu_MC_CGM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) MC_CGM_pClockConfigPtr);

#if (IPV_MC == IPV_MC_06_00_00_10)
    FUNC( void, MCU_CODE) Mcu_SRC_ConfigPllClockSources(VAR( Mcu_SRC_ConfigType, MCU_VAR) SRC_ClockConfig);
#endif

#if (IPV_MC == IPV_MC_04_06_05_00)
    FUNC( void, MCU_CODE) Mcu_MC_CGM_PeriphClkPrepareForSwitch(VAR( uint32, AUTOMATIC ) u32McuMaxClockMode);
#endif /* (IPV_MC == IPV_MC_04_06_05_00) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifdef MCU_GET_INTERNAL_STATE
#if (IPV_MC == IPV_MC_04_06_01_00)
    FUNC(Std_ReturnType, MCU_CODE) Mcu_MC_CGM_GetEmiosClockState(VAR( void, AUTOMATIC));
#endif /* (IPV_MC == IPV_MC_04_06_01_00) */
#endif /* MCU_GET_INTERNAL_STATE */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_MC_CGM_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include
file
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_MC_CGM_H */

/** @} */
