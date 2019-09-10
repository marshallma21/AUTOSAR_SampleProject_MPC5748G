/**
*   @file    Mcu_MC_ME.h
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


#ifndef Mcu_MC_ME_H
#define Mcu_MC_ME_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_ME_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_MC_ME_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
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
#include "Mcu_MC_ME_Types.h"
#include "Mcu_EnvCfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_MC_ME_VENDOR_ID                    43
/** @violates @ref Mcu_MC_ME_H_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_AR_RELEASE_MAJOR_VERSION     4
/** @violates @ref Mcu_MC_ME_H_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_AR_RELEASE_MINOR_VERSION     2
/** @violates @ref Mcu_MC_ME_H_REF_2 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_AR_RELEASE_REVISION_VERSION  2
#define MCU_MC_ME_SW_MAJOR_VERSION             1
#define MCU_MC_ME_SW_MINOR_VERSION             0
#define MCU_MC_ME_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_MC_ME_Types header file are from the same vendor */
#if (MCU_MC_ME_VENDOR_ID != MCU_MC_ME_TYPES_VENDOR_ID)
    #error "Mcu_MC_ME.h and Mcu_MC_ME_Types.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_ME_Types header file are of the same Autosar version */
#if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION != MCU_MC_ME_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_MINOR_VERSION != MCU_MC_ME_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_REVISION_VERSION != MCU_MC_ME_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME.h and Mcu_MC_ME_Types.h are different"
#endif
/* Check if source file and Mcu_MC_ME_Types header file are of the same Software version */
#if ((MCU_MC_ME_SW_MAJOR_VERSION != MCU_MC_ME_TYPES_SW_MAJOR_VERSION) || \
     (MCU_MC_ME_SW_MINOR_VERSION != MCU_MC_ME_TYPES_SW_MINOR_VERSION) || \
     (MCU_MC_ME_SW_PATCH_VERSION != MCU_MC_ME_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_ME.h and Mcu_MC_ME_Types.h are different"
#endif

/* Check if source file and Mcu_EnvCfg header file are from the same vendor */
#if (MCU_MC_ME_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_MC_ME.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_MC_ME_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_MC_ME_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_MC_ME_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_ME.h and Mcu_EnvCfg.h are different"
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
* @violates @ref Mcu_MC_ME_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
    FUNC( void, MCU_CODE) Mcu_MC_ME_SetUserAccessAllowed(void);
#endif
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_10) ||\
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_06_00_00_10) ||\
     (IPV_MC == IPV_MC_04_04_01_00)\
    )
FUNC( void, MCU_CODE) Mcu_MC_ME_InitCCTL(P2CONST( Mcu_MC_ME_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_ME_pConfigPtr);
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||
           (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||
           (IPV_MC == IPV_MC_04_04_01_00)) */

FUNC( void, MCU_CODE) Mcu_MC_ME_ModesPeriphInit(P2CONST( Mcu_MC_ME_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_ME_pConfigPtr);

#if (MCU_INIT_CLOCK == STD_ON)
FUNC( void, MCU_CODE) Mcu_MC_ME_BlindEnabledClockUpdate(VAR( uint32, AUTOMATIC ) u32EnabledClocks);

FUNC( void, MCU_CODE) Mcu_MC_ME_EnabledClkUpdate( VAR( uint32, AUTOMATIC ) u32EnabledClocks);

FUNC( void, MCU_CODE) Mcu_MC_ME_SystemClkUpdate( VAR( uint32, AUTOMATIC ) u32SystemClk);

#if (IPV_MC == IPV_MC_06_00_00_10)
FUNC(void, MCU_CODE) Mcu_MC_ME_SecondarySystemClkUpdate(VAR(uint32, AUTOMATIC) u32SecSysClkValue, VAR(uint32, AUTOMATIC) u32SecSysClkMask);
#endif

#endif /* (MCU_INIT_CLOCK == STD_ON) */

FUNC( void, MCU_CODE) Mcu_MC_ME_ApplyMode( VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode);

FUNC( void, MCU_CODE) Mcu_MC_ME_ModeConfig(P2CONST( Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pModeConfigPtr);

#if ((MCU_GET_PERIPH_STATE_API == STD_ON) || (defined MCU_GET_INTERNAL_STATE))
FUNC( Std_ReturnType, MCU_CODE) Mcu_MC_ME_GetPeripheralState(VAR( Mcu_PeripheralIdType, AUTOMATIC) Mcu_ePeriphId);
#endif /* ((MCU_GET_PERIPH_STATE_API == STD_ON) || (defined MCU_GET_INTERNAL_STATE)) */

#if (MCU_POWERMODE_STATE_API == STD_ON)
FUNC( Mcu_PowerModeStateType, MCU_CODE) Mcu_MC_ME_GetPowerModeState( VAR( void, AUTOMATIC));
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_06_00_00_10))
#if((MCU_SAFE_MODE_ISR_USED == STD_ON ) || \
    (MCU_INVALID_MODE_ISR_USED == STD_ON ) || \
    (MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) || \
    (MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON) || \
    (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON) \
   )
FUNC( void, MCU_CODE) Mcu_MC_ME_Int( VAR( void, AUTOMATIC) );
#endif
#else  /* for all other platforms */

#if (MCU_SAFE_MODE_ISR_USED == STD_ON)
FUNC( void, MCU_CODE) Mcu_MC_ME_SafeMode_Int( VAR( void, AUTOMATIC));
#endif /* (MCU_SAFE_MODE_ISR_USED == STD_ON) */

#if (MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON)
FUNC( void, MCU_CODE) Mcu_MC_ME_TransitionComplete_Int( VAR( void, AUTOMATIC));
#endif /* (MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON) */

#if (MCU_INVALID_MODE_ISR_USED == STD_ON)
FUNC( void, MCU_CODE) Mcu_MC_ME_InvalidMode_Int( VAR( void, AUTOMATIC));
#endif /* (MCU_INVALID_MODE_ISR_USED == STD_ON) */

#if ((MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) || \
     (MCU_INVALID_CLK_CONFIGURATION_ISR_USED == STD_ON) || \
     (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON))
FUNC( void, MCU_CODE) Mcu_MC_ME_InvalidModeConfig_Int( VAR( void, AUTOMATIC));
#endif /* ((MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) ||
           (MCU_INVALID_CLK_CONFIGURATION_ISR_USED == STD_ON) ||
           (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON)) */
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

FUNC( uint32, MCU_CODE) Mcu_MC_ME_GetCurrentModeClockSettings( VAR( void, AUTOMATIC));

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_MC_ME_H_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* Mcu_MC_ME_H */

/** @} */
