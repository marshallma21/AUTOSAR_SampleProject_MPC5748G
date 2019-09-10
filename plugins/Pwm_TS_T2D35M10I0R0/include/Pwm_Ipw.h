/**
*   @file           Pwm_Ipw.h
*
*   @version        1.0.0
*
*   @brief          AUTOSAR Pwm - Pwm Ipw API.
*   @details        Pwm Ipw API.
*
*   @addtogroup     PWM_MODULE
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

#ifndef PWM_IPW_H
#define PWM_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_IPW_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_IPW_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/

/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @violates @ref Pwm_IPW_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_Ipw_Types.h"
#include "Pwm_Cfg.h"

/*===============================================================================================
*                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_Ipw.h
*/
#define PWM_IPW_VENDOR_ID                         43
#define PWM_IPW_MODULE_ID                         121
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_REVISION_VERSION       2
#define PWM_IPW_SW_MAJOR_VERSION                  1
#define PWM_IPW_SW_MINOR_VERSION                  0
#define PWM_IPW_SW_PATCH_VERSION                  0
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if header file and Pwm_Ipw_Types header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Pwm_Ipw.h and Pwm_Ipw_Types.h have different vendor ids"
#endif
/* Check if header file and Pwm_Ipw_Types header file are of the same Autosar version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION    != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.h and Pwm_Ipw_Types.h are different"
#endif
/* Check if header file and Pwm_Ipw_Types header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.h and Pwm_Ipw_Types.h are different"
#endif

/* Check if header file and Pwm_Cfg header file are of the same vendor */
#if (PWM_IPW_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Pwm_Ipw.h and Pwm_Cfg.h have different vendor ids"
#endif
/* Check if header file and Pwm_Cfg header file are of the same Autosar version */
#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.h and Pwm_Cfg.h are different"
#endif
/* Check if header file and Pwm_Cfg header file are of the same software version */
#if ((PWM_IPW_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.h and Pwm_Cfg.h are different"
#endif

/*===============================================================================================
*                                           CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       DEFINES AND MACROS
===============================================================================================*/

/*===============================================================================================
*                                             ENUMS
===============================================================================================*/

/*===============================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/

/*===============================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/

/*===============================================================================================
*                                     FUNCTION PROTOTYPES
===============================================================================================*/
/*
* @violates Pwm_IPW_H_REF_2 Only preprocessor statements and comments before "#include"
*/

#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_IPW_H_REF_1 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

FUNC (void, PWM_CODE) Pwm_Ipw_Init
(   
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);


#if (PWM_DE_INIT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_DeInit
(
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_DE_INIT_API */


#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetDutyCycle
(
    VAR         (Pwm_ChannelType,       AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,                AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_SET_DUTY_CYCLE_API */


#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetPeriodAndDuty
(
    VAR         (Pwm_ChannelType,       AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_PeriodType,        AUTOMATIC)                 nPeriod,
    VAR         (uint16,                AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)

FUNC (void, PWM_CODE) Pwm_Ipw_SetOutputToIdle
(
    VAR         (Pwm_ChannelType,       AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);

#endif /* PWM_SET_OUTPUT_TO_IDLE_API */

#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
FUNC(Pwm_OutputStateType,PWM_CODE) Pwm_Ipw_GetOutputState
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_GET_OUTPUT_STATE_API */

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)

FUNC (void, PWM_CODE) Pwm_Ipw_DisableNotification
(
    VAR         (Pwm_ChannelType,       AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) pIpConfig
);

    

FUNC (void, PWM_CODE) Pwm_Ipw_EnableNotification
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
    
#endif /* PWM_NOTIFICATION_SUPPORTED */

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
FUNC (uint16, PWM_CODE) Pwm_Ipw_GetChannelState
(
    VAR         (Pwm_ChannelType,   AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif /* PWM_GET_CHANNEL_STATE_API */

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_DUTY_CYCLE_API == STD_ON))
FUNC (uint8, PWM_CODE) Pwm_Ipw_ValidateParamParamOffsetDuty
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16        ,   AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateNotification
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
FUNC (uint32, PWM_CODE) Pwm_Ipw_GetMaxPeriodValue
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_TRIGGER_DELAY_API == STD_ON))
FUNC (Pwm_PeriodType, PWM_CODE) Pwm_Ipw_GetCurrentPeriodValue
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateTriggerMode
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_COUNTER_BUS_API == STD_ON))
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateCounterBus
(
    VAR         (uint32,           AUTOMATIC)                 u32Bus
);
#endif

#if (PWM_PARAM_CHECK == STD_ON)
FUNC(uint8, PWM_CODE) Pwm_Ipw_ValidateParamOffset
(
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif



#ifdef PWM_SET_COUNTER_BUS_API
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetCounterBus
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint32,           AUTOMATIC)                 u32Bus,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif
#endif /* PWM_SET_COUNTER_BUS_API */

/*===============================================================================================*/
#ifdef PWM_SET_CHANNEL_OUTPUT_API
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetChannelOutput
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_StateType,    AUTOMATIC)                 eState,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif
#endif /* PWM_SET_CHANNEL_OUTPUT_API */

#ifdef PWM_SET_TRIGGER_DELAY_API
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetTriggerDelay
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_PeriodType,   AUTOMATIC)                 nTriggerDelay,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif
#endif/*PWM_SET_TRIGGER_DELAY_API*/

#ifdef PWM_BUFFER_TRANSFER_EN_DIS_API
#if (PWM_BUFFER_TRANSFER_EN_DIS_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_BufferTransferEnableDisable
/* @violates @ref Pwm_IPW_H_REF_2 Identifier exceeds 31 chars. */
(
    VAR         (uint8,            AUTOMATIC)                 u8ModuleIndex,
    VAR         (uint32,           AUTOMATIC)                 u32ChannelMasks
);
#endif
#endif

#if (PWM_SET_CLOCK_MODE_API == STD_ON)
FUNC (void, PWM_CODE) Pwm_Ipw_SetClockMode
(
    VAR         (Pwm_PrescalerType,AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);
#endif

#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateIdleState
(
    P2CONST     (Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
);

FUNC(void, PWM_CODE) Pwm_Ipw_SetPowerState
(
    P2CONST     (Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pIpConfig,
    VAR         (Pwm_PowerStateType,AUTOMATIC)                 nPowerState
);
#endif
/* @violates Pwm_IPW_H_REF_2 Only preprocessor statements and comments before "#include" */
#define PWM_STOP_SEC_CODE
/* @violates @ref Pwm_IPW_H_REF_1 precautions to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* PWM_IPW_H */

/** @} */
