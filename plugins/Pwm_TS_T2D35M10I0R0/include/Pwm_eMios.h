/**
*   @file    Pwm_eMIOS.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Pwm - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios
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
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_eMIOS_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, :  Repeated include files,  Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
*@section Pwm_eMIOS_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
*/
#ifndef PWM_EMIOS_H
#define PWM_EMIOS_H

#ifdef __cplusplus
extern "C"{
#endif

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @violates @ref Pwm_eMIOS_H_REF_1 Repeated include files
*/
#include "Std_Types.h"



/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

/**
* @{
*/
#define PWM_EMIOS_VENDOR_ID                           43
#define PWM_EMIOS_MODULE_ID                           121
/** @violates @ref Pwm_eMIOS_H_REF_2 This is required as per autosar Requirement */
#define PWM_EMIOS_AR_RELEASE_MAJOR_VERSION            4
/** @violates @ref Pwm_eMIOS_H_REF_2 This is required as per autosar Requirement */
#define PWM_EMIOS_AR_RELEASE_MINOR_VERSION            2
/** @violates @ref Pwm_eMIOS_H_REF_2 This is required as per autosar Requirement */
#define PWM_EMIOS_AR_RELEASE_REVISION_VERSION         2
/** @violates @ref Pwm_eMIOS_H_REF_2 This is required as per autosar Requirement */
#define PWM_EMIOS_SW_MAJOR_VERSION                    1
/** @violates @ref Pwm_eMIOS_H_REF_2 This is required as per autosar Requirement */
#define PWM_EMIOS_SW_MINOR_VERSION                    0
/** @violates @ref Pwm_eMIOS_H_REF_2 This is required as per autosar Requirement */
#define PWM_EMIOS_SW_PATCH_VERSION                    0
/** @} */

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if source file and Std_Types.h are of the same Autosar version */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

#if ((PWM_EMIOS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMIOS.h and Std_Types.h are different"
#endif

#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */


/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/


/*===============================================================================================
                                             ENUMS
===============================================================================================*/


/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/


/*===============================================================================================
                                     FUNCTION PROTOTYPES
===============================================================================================*/
#define PWM_START_SEC_CODE

/*
* @violates @ref Pwm_eMIOS_H_REF_1 Repeated include files
*/
#include "Pwm_MemMap.h"

/*===============================================================================================*/
FUNC(void, PWM_CODE) Pwm_eMios_Init
(
    P2CONST(Pwm_eMios_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);

/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_DeInit
(
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif /* PWM_DE_INIT_API */


/*===============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_COUNTER_BUS_API == STD_ON))
FUNC(void, PWM_CODE) Pwm_eMios_SetDutyCycle
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    VAR(uint16,                          AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif /* PWM_SET_DUTY_CYCLE_API */


/*===============================================================================================*/

#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_SetPeriodAndDuty
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    VAR(Pwm_PeriodType,                  AUTOMATIC)                 nPeriod,
    VAR(uint16,                          AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*===============================================================================================*/
#if ( PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_SetOutputToIdle
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_eMios_GetOutputState
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif /* PWM_GET_OUTPUT_STATE_API */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_EnableNotification
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    VAR(Pwm_EdgeNotificationType,        AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);

/*===============================================================================================*/
FUNC(void, PWM_CODE) Pwm_eMios_DisableNotification
(
    VAR         (uint8,                  AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);

/*===============================================================================================*/
#if (PWM_PARAM_CHECK == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_eMios_ValidateNotification
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (Pwm_EdgeNotificationType,AUTOMATIC)                 eNotification
);
#endif /* PWM_PARAM_CHECK */

#endif /* PWM_NOTIFICATION_SUPPORTED */

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_COUNTER_BUS_API == STD_ON))
/*===============================================================================================*/
FUNC(Std_ReturnType, PWM_CODE) Pwm_eMios_ValidateCounterBus
(
    VAR         (uint32,                  AUTOMATIC)                 u32Bus
);
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_TRIGGER_DELAY_API == STD_ON))
/*===============================================================================================*/
FUNC(Pwm_PeriodType, PWM_CODE) Pwm_eMios_GetCurrentPeriodValue
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);

FUNC(Std_ReturnType, PWM_CODE) Pwm_eMios_ValidateTriggerMode
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
/*===============================================================================================*/
FUNC(Pwm_PeriodType, PWM_CODE) Pwm_eMios_GetMaxPeriodValue
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_DUTY_CYCLE_API == STD_ON))
/*===============================================================================================*/
FUNC(uint8, PWM_CODE) Pwm_eMios_ValidateParamOffsetDuty
/* @violates @ref Pwm_eMIOS_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (uint16,                  AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif

#if (PWM_PARAM_CHECK == STD_ON)
/*===============================================================================================*/
FUNC(uint8, PWM_CODE) Pwm_eMios_ValidateParamOffset
(
    P2CONST(Pwm_eMios_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif


/*===============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_SetCounterBus
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig,
    VAR(uint32,                          AUTOMATIC)                 u32Bus
);
#endif /* PWM_SET_COUNTER_BUS_API */


/*===============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_SetChannelOutput
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig,
    VAR(Pwm_StateType,                   AUTOMATIC)                 eState
);
#endif /* PWM_SET_CHANNEL_OUTPUT_API */


/*===============================================================================================*/
#if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) || (PWM_FEATURE_DAOC == STD_ON))
FUNC(void, PWM_CODE) Pwm_eMios_ProcessCommonInterrupt
/* @violates @ref Pwm_eMIOS_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR(Pwm_ChannelType,                 AUTOMATIC)                 u8HwChannel
);
#endif

/*===============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_SetTriggerDelay
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig,
    VAR(Pwm_PeriodType,                  AUTOMATIC)                 nTriggerDelay
);

#endif

/*===============================================================================================*/
#if (PWM_BUFFER_TRANSFER_EN_DIS_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_BufferTransferEnableDisable
/* @violates @ref Pwm_eMIOS_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR(uint8,                           AUTOMATIC)                 u8ModuleIndex,
    VAR(uint32,                          AUTOMATIC)                 u32ChannelMask
);
#endif

/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
FUNC(uint16, PWM_CODE)  Pwm_eMios_GetChannelState
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig
);
#endif    /*PWM_GET_CHANNEL_STATE_API*/

#if (PWM_SET_CLOCK_MODE_API == STD_ON)
FUNC(void, PWM_CODE) Pwm_eMios_SetClockMode
(
    VAR         (Pwm_PrescalerType,      AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);
#endif
/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_eMios_ValidateIdleState
(
    P2CONST(Pwm_eMios_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
);

FUNC(void, PWM_CODE) Pwm_eMios_SetPowerState
(
    P2CONST     (Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig,
    VAR         (Pwm_PowerStateType,     AUTOMATIC)                 ePowerState
);
#endif


#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_eMIOS_H_REF_1 Repeated include files
*/
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif


#endif   /* EMIOS_PWM_LLD_H */

/** @} */

