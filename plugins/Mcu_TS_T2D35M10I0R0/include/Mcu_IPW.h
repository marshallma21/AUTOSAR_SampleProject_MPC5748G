/**
*   @file    Mcu_IPW.h
*   @implements Mcu_IPW.h_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Midle layer interface for Higher layer.
*   @details File contains function prototypes used by HLD only.
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


#ifndef MCU_IPW_H
#define MCU_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_IPW_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
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
#include "Mcu_IPW_Types.h"
#include "Mcu_EnvCfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_VENDOR_ID                       43
#define MCU_IPW_AR_RELEASE_MAJOR_VERSION        4
#define MCU_IPW_AR_RELEASE_MINOR_VERSION        2
#define MCU_IPW_AR_RELEASE_REVISION_VERSION     2
#define MCU_IPW_SW_MAJOR_VERSION                1
#define MCU_IPW_SW_MINOR_VERSION                0
#define MCU_IPW_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/

/* Check if current file and Mcu_IPW_Types header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID != MCU_IPW_TYPES_VENDOR_ID)
    #error "Mcu_IPW.h and Mcu_IPW_Types.h have different vendor ids"
#endif

/* Check if current file and Mcu_IPW_Types header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION    != MCU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION    != MCU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION != MCU_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.h and Mcu_IPW_Types.h are different"
#endif

/* Check if current file and Mcu_IPW_Types header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION != MCU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION != MCU_IPW_TYPES_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION != MCU_IPW_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.h and Mcu_IPW_Types.h are different"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_IPW.h and Mcu_EnvCfg.h have different vendor ids"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION    != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION    != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.h and Mcu_EnvCfg.h are different"
#endif

/* Check if current file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.h and Mcu_EnvCfg.h are different"
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
/** @violates @ref Mcu_IPW_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"


FUNC( void, MCU_CODE) Mcu_Ipw_Init(P2CONST(Mcu_HwIPsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pHwIPsConfigPtr);

#if (MCU_INIT_CLOCK == STD_ON)
FUNC( void, MCU_CODE) Mcu_Ipw_InitClock(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

FUNC( void, MCU_CODE) Mcu_Ipw_SetMode(P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pModeConfigPtr);

#if (MCU_LPU_SUPPORT == STD_ON)
FUNC( void, MCU_CODE) Mcu_IPW_LpuSetMode(P2CONST(Mcu_LPU_LowPowerModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pLowPowerModeConfigPtr);
#endif

#if (MCU_INIT_CLOCK == STD_ON)
    #if (MCU_NO_PLL == STD_OFF)
FUNC( void, MCU_CODE) Mcu_Ipw_DistributePllClock(VAR(void, AUTOMATIC));
    #endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
FUNC( Mcu_PllStatusType, MCU_CODE) Mcu_Ipw_GetPllStatus(VAR(void, AUTOMATIC));
#endif /* (MCU_NO_PLL == STD_OFF) */

#if MCU_PERFORM_RESET_API == STD_ON
FUNC( void, MCU_CODE) Mcu_Ipw_PerformReset(P2CONST(Mcu_HwIPsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pHwIPsConfigPtr);
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */

FUNC( Mcu_ResetType, MCU_CODE) Mcu_Ipw_GetResetReason(VAR(void, AUTOMATIC));

FUNC( Mcu_RawResetType, MCU_CODE) Mcu_Ipw_GetResetRawValue(VAR(void, AUTOMATIC));


#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC ( Mcu_RamStateType, MCU_CODE) Mcu_Ipw_GetRamState(VAR(void, AUTOMATIC));
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */

#if (MCU_GET_PERIPH_STATE_API == STD_ON)
FUNC( Std_ReturnType, MCU_CODE) Mcu_Ipw_GetPeripheralState(VAR(Mcu_PeripheralIdType, AUTOMATIC) Mcu_PeriphId);
#endif /* (MCU_GET_PERIPH_STATE_API == STD_ON) */

#if (MCU_GET_SYSTEM_STATE_API == STD_ON)
FUNC( uint32, MCU_CODE) Mcu_Ipw_GetSystemState(VAR(void, AUTOMATIC));
#endif /* (MCU_GET_SYSTEM_STATE_API == STD_ON) */

#if (MCU_POWERMODE_STATE_API == STD_ON)
FUNC( Mcu_PowerModeStateType, MCU_CODE) Mcu_Ipw_GetPowerModeState(VAR( void, AUTOMATIC));
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */

#if (MCU_GET_POWER_DOMAIN_API == STD_ON)
FUNC( Std_ReturnType, MCU_CODE) Mcu_Ipw_GetPowerDomainState(VAR(void, AUTOMATIC));
#endif /* (MCU_GET_POWER_DOMAIN_API == STD_ON) */

#if (MCU_GET_MEM_CONFIG_API == STD_ON)
FUNC( Mcu_SSCM_MemConfigType, MCU_CODE ) Mcu_Ipw_SscmGetMemConfig(VAR(void, AUTOMATIC) );
#endif /* (MCU_GET_MEM_CONFIG_API == STD_ON) */

#if (MCU_SSCM_GET_STATUS_API == STD_ON)
FUNC( Mcu_SSCM_StatusType, MCU_CODE ) Mcu_Ipw_SscmGetStatus(VAR(void, AUTOMATIC) );
#endif /* (MCU_SSCM_GET_STATUS_API == STD_ON) */

#ifdef MCU_SSCM_GET_UOPS_API
#if (MCU_SSCM_GET_UOPS_API == STD_ON)
FUNC( Mcu_SSCM_UopsType, MCU_CODE ) Mcu_Ipw_SscmGetUops(VAR(void, AUTOMATIC) );
#endif /* (MCU_SSCM_GET_UOPS_API == STD_ON) */
#endif /* MCU_SSCM_GET_UOPS_API */

#if (MCU_GET_MIDR_API == STD_ON)
FUNC( void, MCU_CODE) Mcu_Ipw_GetMidrStructure(P2VAR(Mcu_MidrReturnType, AUTOMATIC, MCU_APPL_DATA) pMidr);
#endif /*(MCU_GET_MIDR_API == STD_ON)*/

#if ((MCU_EMIOS_SUPPORT == STD_ON) || (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON))
#if (MCU_CHECK_EMIOS_STATUS == STD_ON)
FUNC( Std_ReturnType, MCU_CODE) Mcu_IPW_CheckEmiosStatus(VAR (uint8, AUTOMATIC) u8Module);
#endif /* (MCU_CHECK_EMIOS_STATUS == STD_ON) */
#endif /* ((MCU_EMIOS_SUPPORT == STD_ON) || (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)) */

#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_IPW_EmiosConfigureGpren(VAR (uint8, AUTOMATIC) u8Module, VAR (uint8, AUTOMATIC) u8Value);
#endif /* (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) */

#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_Ipw_DisableCmu(VAR (uint8, AUTOMATIC) u8IndexCmu);
#endif
#endif

#define MCU_STOP_SEC_CODE
/** @violates @ref Mcu_IPW_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCU_IPW_H */

/** @} */
