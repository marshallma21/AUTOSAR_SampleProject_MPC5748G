/**
*   @file    Mcu_MC_RGM.h
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


#ifndef MCU_MC_RGM_H
#define MCU_MC_RGM_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_RGM_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_MC_RGM_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
**
* @section Mcu_MC_RGM_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Mcu_MC_RGM_h_REF_4
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to braced initialiser,
* a constant, a parenthesised expression, a type qualifier, a storage class specifier, or
* a do-while-zero construct
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
#include "Mcu_MC_RGM_Types.h"
#include "Mcu_EnvCfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_MC_RGM_VENDOR_ID                        43
/** @violates @ref Mcu_MC_RGM_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION         4
/** @violates @ref Mcu_MC_RGM_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_RGM_AR_RELEASE_MINOR_VERSION         2
/** @violates @ref Mcu_MC_RGM_h_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_RGM_AR_RELEASE_REVISION_VERSION      2
#define MCU_MC_RGM_SW_MAJOR_VERSION                 1
#define MCU_MC_RGM_SW_MINOR_VERSION                 0
#define MCU_MC_RGM_SW_PATCH_VERSION                 0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_MC_RGM_Types header file are from the same vendor */
#if (MCU_MC_RGM_VENDOR_ID != MCU_MC_RGM_TYPES_VENDOR_ID)
    #error "Mcu_MC_RGM.h and Mcu_MC_RGM_Types.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_RGM_Types header file are of the same Autosar version */
#if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION != MCU_MC_RGM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION != MCU_MC_RGM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_REVISION_VERSION != MCU_MC_RGM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_RGM.h and Mcu_MC_RGM_Types.h are different"
#endif
/* Check if source file and Mcu_MC_RGM_Types header file are of the same Software version */
#if ((MCU_MC_RGM_SW_MAJOR_VERSION != MCU_MC_RGM_TYPES_SW_MAJOR_VERSION) || \
     (MCU_MC_RGM_SW_MINOR_VERSION != MCU_MC_RGM_TYPES_SW_MINOR_VERSION) || \
     (MCU_MC_RGM_SW_PATCH_VERSION != MCU_MC_RGM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_RGM.h and Mcu_MC_RGM_Types.h are different"
#endif

/* Check if source file and Mcu_EnvCfg header file are from the same vendor */
#if (MCU_MC_RGM_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_MC_RGM.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_RGM.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_MC_RGM_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_MC_RGM_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_MC_RGM_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_RGM.h and Mcu_EnvCfg.h are different"
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
* @violates @ref Mcu_MC_RGM_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_MC_RGM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_MC_RGM_ResetInit(MC_RGM_pConfigPtr) \
do\
{ \
        Mcal_Trusted_Call(Mcu_MC_RGM_ResetInit,(MC_RGM_pConfigPtr)); \
}\
while(0)
#else
/** @violates @ref Mcu_MC_RGM_h_REF_3 Function-like macro defined.*/
#define  Call_Mcu_MC_RGM_ResetInit(MC_RGM_pConfigPtr) \
do\
{ \
        Mcu_MC_RGM_ResetInit(MC_RGM_pConfigPtr); \
}\
while(0)
#endif
#endif


#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_MC_RGM_h_REF_3 Function-like macro defined.*/
/** @violates @ref Mcu_MC_RGM_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {}.*/
#define  Call_Mcu_MC_RGM_GetResetReason() \
        Mcal_Trusted_Call_Return((uint32)Mcu_MC_RGM_GetResetReason,())
#else
/** @violates @ref Mcu_MC_RGM_h_REF_3 Function-like macro defined.*/
/** @violates @ref Mcu_MC_RGM_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {}.*/
#define  Call_Mcu_MC_RGM_GetResetReason() \
        Mcu_MC_RGM_GetResetReason()
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/** @violates @ref Mcu_MC_RGM_h_REF_3 Function-like macro defined.*/
/** @violates @ref Mcu_MC_RGM_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {}.*/
#define  Call_Mcu_MC_RGM_GetResetRawValue() \
        Mcal_Trusted_Call_Return(Mcu_MC_RGM_GetResetRawValue,())
#else
/** @violates @ref Mcu_MC_RGM_h_REF_3 Function-like macro defined.*/
/** @violates @ref Mcu_MC_RGM_h_REF_4 MISRA 2004 Required Rule 19.4, This is not a macro, it can not be included in () or {}.*/
#define  Call_Mcu_MC_RGM_GetResetRawValue() \
        Mcu_MC_RGM_GetResetRawValue()
#endif
#endif

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
    FUNC( void, MCU_CODE) Mcu_MC_RGM_SetUserAccessAllowed(void);
#endif
#endif

FUNC(void, MCU_CODE) Mcu_MC_RGM_ResetInit(P2CONST( Mcu_MC_RGM_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_RGM_pConfigPtr);

FUNC( Mcu_ResetType, MCU_CODE) Mcu_MC_RGM_GetResetReason( VAR( void, AUTOMATIC));

FUNC( Mcu_RawResetType, MCU_CODE) Mcu_MC_RGM_GetResetRawValue( VAR( void, AUTOMATIC));

#if (MCU_PERFORM_RESET_API == STD_ON)
FUNC(void, MCU_CODE) Mcu_MC_RGM_PerformReset(P2CONST( Mcu_MC_RGM_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_RGM_pConfigPtr);
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */

#if (MCU_RESET_ALTERNATE_ISR_USED == STD_ON)
FUNC( void, MCU_CODE) Mcu_MC_RGM_ResetAltInt( VAR( void, AUTOMATIC));
#endif /* (MCU_RESET_ALTERNATE_ISR_USED == STD_ON) */

#if (MCU_RGM_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
FUNC( void, MCU_CODE ) Mcu_MC_RGM_ClearClockMonitoringIrqFlags(VAR( void, AUTOMATIC));
#endif /* (MCU_RGM_CLEAR_CLOCK_IRQ_FLAG == STD_ON) */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_MC_RGM_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* MCU_MC_RGM_H */

/** @} */
