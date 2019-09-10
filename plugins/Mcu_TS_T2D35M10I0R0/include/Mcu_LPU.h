/**
*   @file    Mcu_LPU.h
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


#ifndef MCU_LPU_H
#define MCU_LPU_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_LPU_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
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
#include "Mcu_LPU_Types.h"
#include "Mcu_EnvCfg.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_LPU_VENDOR_ID                    43
#define MCU_LPU_AR_RELEASE_MAJOR_VERSION     4
#define MCU_LPU_AR_RELEASE_MINOR_VERSION     2
#define MCU_LPU_AR_RELEASE_REVISION_VERSION  2
#define MCU_LPU_SW_MAJOR_VERSION             1
#define MCU_LPU_SW_MINOR_VERSION             0
#define MCU_LPU_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_LPU_Types header file are from the same vendor */
#if (MCU_LPU_VENDOR_ID != MCU_LPU_TYPES_VENDOR_ID)
    #error "Mcu_LPU.h and Mcu_LPU_Types.h have different vendor ids"
#endif
/* Check if source file and Mcu_LPU_Types header file are of the same Autosar version */
#if ((MCU_LPU_AR_RELEASE_MAJOR_VERSION != MCU_LPU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_LPU_AR_RELEASE_MINOR_VERSION != MCU_LPU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCU_LPU_AR_RELEASE_REVISION_VERSION != MCU_LPU_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_LPU.h and Mcu_LPU_Types.h are different"
#endif
/* Check if source file and Mcu_LPU_Types header file are of the same Software version */
#if ((MCU_LPU_SW_MAJOR_VERSION != MCU_LPU_TYPES_SW_MAJOR_VERSION) || \
     (MCU_LPU_SW_MINOR_VERSION != MCU_LPU_TYPES_SW_MINOR_VERSION) || \
     (MCU_LPU_SW_PATCH_VERSION != MCU_LPU_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_LPU.h and Mcu_LPU_Types.h are different"
#endif

/* Check if source file and Mcu_EnvCfg header file are from the same vendor */
#if (MCU_LPU_VENDOR_ID != MCU_SCFG_VENDOR_ID)
    #error "Mcu_LPU.h and Mcu_EnvCfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Autosar version */
#if ((MCU_LPU_AR_RELEASE_MAJOR_VERSION != MCU_SCFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_LPU_AR_RELEASE_MINOR_VERSION != MCU_SCFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_LPU_AR_RELEASE_REVISION_VERSION != MCU_SCFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_LPU.h and Mcu_EnvCfg.h are different"
#endif
/* Check if source file and Mcu_EnvCfg header file are of the same Software version */
#if ((MCU_LPU_SW_MAJOR_VERSION != MCU_SCFG_SW_MAJOR_VERSION) || \
     (MCU_LPU_SW_MINOR_VERSION != MCU_SCFG_SW_MINOR_VERSION) || \
     (MCU_LPU_SW_PATCH_VERSION != MCU_SCFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_LPU.h and Mcu_EnvCfg.h are different"
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
* @violates @ref Mcu_LPU_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_LPU_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "Mcu_MemMap.h"

#if (MCU_LPU_SUPPORT == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
    FUNC( void, MCU_CODE) Mcu_LPU_SetUserAccessAllowed(void);
#endif
#endif

FUNC( void, MCU_CODE) Mcu_LPU_LowPowerModeConfig(P2CONST(Mcu_LPU_LowPowerModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pLowPowerModeConfigPtr );

#if (MCU_LPU_INVALID_MODE_ISR_USED == STD_ON)
FUNC( void, MCU_CODE) Mcu_LPU_InvalidModeIsr( VAR( void, AUTOMATIC));
#endif /* (MCU_LPU_INVALID_MODE_ISR_USED == STD_ON) */

#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_LPU_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_LPU_h_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include' MemMap.h
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /* MCU_LPU_H */

/** @} */
