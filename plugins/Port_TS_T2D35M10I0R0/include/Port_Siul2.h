/**
* @file    Port_Siul2.h
* @version 1.0.0
*
* @brief   AUTOSAR Port - SIUL low level IP driver interface.
* @details API of the SIUL2 low level IP driver.
*
* @addtogroup Siul2
* @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : SIUL2
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef PORT_SIUL2_H
#define PORT_SIUL2_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_SIUL_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file, 
* Precautions shall be taken in order to prevent the contents of a header file being included twice. 
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_SIUL_H_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars
* for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "modules.h"

#include "Port_Cfg.h"

#include "Port_Siul2_Types.h"

/*=================================================================================================
*                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/
/*
 * @brief Parameters that shall be published within the driver header file and also in the
 *        module's description file
 */
#define PORT_SIUL2_VENDOR_ID_H                     43
/* @violates @ref PORT_SIUL_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_H      4
/* @violates @ref PORT_SIUL_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIUL2_AR_RELEASE_MINOR_VERSION_H      2
/* @violates @ref PORT_SIUL_H_REF_2 Violates MISRA 2004 Required Rule 1.4 */
#define PORT_SIUL2_AR_RELEASE_REVISION_VERSION_H   2
#define PORT_SIUL2_SW_MAJOR_VERSION_H              1
#define PORT_SIUL2_SW_MINOR_VERSION_H              0
#define PORT_SIUL2_SW_PATCH_VERSION_H              0


#if (STD_ON == USE_PORT_MODULE)
/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if the files Port_Siul2.h and Port_Cfg.h are of the same vendor */
#if (PORT_SIUL2_VENDOR_ID_H != PORT_VENDOR_ID_CFG_H)
    #error "Port_Siul2.h and Port_Cfg.h have different vendor ids"
#endif
/* Check if the files Port_Siul2.h and Port_Cfg.h are of the same Autosar version */
#if ((PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_H    != PORT_AR_RELEASE_MAJOR_VERSION_CFG_H) || \
     (PORT_SIUL2_AR_RELEASE_MINOR_VERSION_H    != PORT_AR_RELEASE_MINOR_VERSION_CFG_H) || \
     (PORT_SIUL2_AR_RELEASE_REVISION_VERSION_H != PORT_AR_RELEASE_REVISION_VERSION_CFG_H) \
    )
  #error "AutoSar Version Numbers of Port_Siul2.h and Port_Cfg.h are different"
#endif
/* Check if the files Port_Siul2.h and Port_Cfg.h are of the same software version */
#if ((PORT_SIUL2_SW_MAJOR_VERSION_H != PORT_SW_MAJOR_VERSION_CFG_H) || \
     (PORT_SIUL2_SW_MINOR_VERSION_H != PORT_SW_MINOR_VERSION_CFG_H) || \
     (PORT_SIUL2_SW_PATCH_VERSION_H != PORT_SW_PATCH_VERSION_CFG_H)    \
    )
  #error "Software Version Numbers of Port_Siul2.h and Port_Cfg.h are different"
#endif

/* Check if the files Port_Siul2.h and Port_Siul2_Types.h are of the same vendor */
#if (PORT_SIUL2_VENDOR_ID_H != PORT_SIUL2_VENDOR_ID_TYPES_H)
    #error "Port_Siul2.h and Port_Siul2_Types.h have different vendor ids"
#endif
/* Check if the files Port_Siul2.h and Port_Siul2_Types.h are of the same Autosar version */
#if ((PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_H    != PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_TYPES_H) || \
     (PORT_SIUL2_AR_RELEASE_MINOR_VERSION_H    != PORT_SIUL2_AR_RELEASE_MINOR_VERSION_TYPES_H) || \
     (PORT_SIUL2_AR_RELEASE_REVISION_VERSION_H != PORT_SIUL2_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
   #error "AutoSar Version Numbers of Port_Siul2.h and Port_PORT_SIUL2_Types.h are different"
#endif
/* Check if the files Port_Siul2.h and Port_Siul2_Types.h are of the same software version */
#if ((PORT_SIUL2_SW_MAJOR_VERSION_H != PORT_SIUL2_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_SIUL2_SW_MINOR_VERSION_H != PORT_SIUL2_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_SIUL2_SW_PATCH_VERSION_H != PORT_SIUL2_SW_PATCH_VERSION_TYPES_H)    \
    )
  #error "Software Version Numbers of Port_Siul2.h and Port_Siul2_Types.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if the files Port_Siul2.h and modules.h are of the same version */
   #if ((PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_H != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
        (PORT_SIUL2_AR_RELEASE_MINOR_VERSION_H != MODULES_AR_RELEASE_MINOR_VERSION_H)    \
       )
       #error "AutoSar Version Numbers of Port_Siul2.h and modules.h are different"
   #endif
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

/*
* @brief Parameter value used in the Port_Siul2_SetPinMode function to signalize the validation of
*        the input muxes is needed
*/
#define SIUL2_INPUT_ACTIVE_U32             ((uint32)0xFFFFFFFFUL)
#define SIUL2_OUTPUT_ACTIVE_U32            ((uint32)0xFFFFFFFEUL)
/*
* @brief Initializing value for the unused IMCR registers in order to avoid writting in not valid
*        memory areas
*/
#define SIUL2_INMUX_UNUSED_PATTERN_U32     ((uint32)0xFFFFFFFFUL)

/*=================================================================================================
*                               DEFINES AND MACROS
=================================================================================================*/


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                               STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                     FUNCTION PROTOTYPES
=================================================================================================*/

/* @brief Allocate defined section for PORT code. */
#define PORT_START_SEC_CODE
/*
* @violates @ref PORT_SIUL_H_REF_1 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "Port_MemMap.h"

#ifdef PORT_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT)
    
/* @brief    Sets the User Access Allowed bit in SIUL2 IP. */
FUNC( void, PORT_CODE) Port_Siul2_SetUserAccessAllowed(void);

#endif /* (STD_ON == PORT_ENABLE_USER_MODE_SUPPORT) */
#endif /* PORT_ENABLE_USER_MODE_SUPPORT */

/* @brief    Initializes the SIUL IP Driver. */
FUNC (void, PORT_CODE) Port_Siul2_Init
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);

#if (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API)
/*
* @brief     Sets the port pin direction
*/
FUNC (Std_ReturnType, PORT_CODE) Port_Siul2_SetPinDirection
(
    VAR    (Port_PinType,          AUTOMATIC                 ) PinIndex,
    VAR    (Port_PinDirectionType, AUTOMATIC                 ) eDirection,
    P2CONST(Port_ConfigType,       AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);
#endif /* (STD_ON == PORT_SET_PIN_DIRECTION_API) || (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief    Sets the port pin mode.
*/
FUNC (void, PORT_CODE) Port_Siul2_SetPinMode
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PinCfgRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) PinCfgRegValue,
    VAR(uint16,                 AUTOMATIC) u16InMuxRegIndex,
    VAR(Port_RegValueType,      AUTOMATIC) InMuxRegValue
);
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */

#if (STD_ON == PORT_SET_PIN_MODE_API)
/**
* @brief    Sets or resets the direction changeability for pads in GPIO mode.
*/
FUNC (void, PORT_CODE) Port_Siul2_SetGpioDirChangeability
(
    VAR(Port_InternalPinIdType, AUTOMATIC) PadID,
    VAR(boolean,                AUTOMATIC) bStatus
);

#if (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL)
/**
* @brief    Sets the desired output value for the pad  switched in GPIO mode.
*/
FUNC (void, PORT_CODE) Port_Siul2_SetGpioPadOutput
(
    VAR    (Port_PinType,    AUTOMATIC                 ) PinIndex,
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);
#endif /* (STD_OFF == PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL) */
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */


/**
* @brief   Refreshes port direction.
*/
FUNC (void, PORT_CODE) Port_Siul2_RefreshPortDirection
(
    P2CONST(Port_ConfigType, AUTOMATIC, PORT_APPL_CONST) pConfigPtr
);

#define PORT_STOP_SEC_CODE
/*
* @violates @ref PORT_SIUL_H_REF_1 Violates MISRA 2004 Advisory Rule 19.15, Repeated include
* file MemMap.h
*/
#include "Port_MemMap.h"
/* USE_PORT_MODULE */
#endif


#ifdef __cplusplus
}
#endif
/* PORT_SIUL2_H */
#endif
/** @} */
