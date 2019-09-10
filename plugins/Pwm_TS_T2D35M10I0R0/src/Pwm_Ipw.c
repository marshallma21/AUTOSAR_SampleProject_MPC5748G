/**
*   @file           Pwm_Ipw.c
*
*   @version        1.0.0
*
*   @brief          AUTOSAR Pwm - PWM Ipw API implementation.
*   @details        PWM IWP API implementation.
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



#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_IPW_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include'
* MemMap.h included after each section define in order to set the current memory section
*
* @section Pwm_IPW_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Pwm_IPW_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_IPW_C_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Pwm_IPW_C_REF_6
* Violates MISRA 2004 Required Rule 8.10, external  could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
*/


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
/*
* @file           Pwm_Ipw.c
*/

#include "Pwm_Ipw.h"
#include "Pwm_eMios.h"
#include "Pwm_Ipw_Notif.h"

/*===============================================================================================
*                                        SOURCE FILE VERSION INFORMATION
===============================================================================================*/
/**
* @{
* @file           Pwm_Ipw.c
*/
#define PWM_IPW_VENDOR_ID_C                     43
/** @violates @ref Pwm_IPW_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Pwm_IPW_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Pwm_IPW_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to 
*   ensure that 31 character significance and case sensitivity are supported for external identifiers. */
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
#define PWM_IPW_AR_RELEASE_REVISION_VERSION_C   2
#define PWM_IPW_SW_MAJOR_VERSION_C              1
#define PWM_IPW_SW_MINOR_VERSION_C              0
#define PWM_IPW_SW_PATCH_VERSION_C              0
/**@}*/

/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/
#if (PWM_IPW_VENDOR_ID_C != PWM_IPW_VENDOR_ID)
    #error "Pwm_Ipw.c and Pwm_Ipw.h have different vendor ids"
#endif

#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.c and Pwm_Ipw.h are different"
#endif

#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_IPW_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_IPW_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.c and Pwm_Ipw.h are different"
#endif


#if (PWM_IPW_VENDOR_ID_C != PWM_EMIOS_VENDOR_ID)
    #error "Pwm_Ipw.c and Pwm_eMios.h have different vendor ids"
#endif

#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_EMIOS_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_EMIOS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.c and Pwm_eMios.h are different"
#endif

#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_EMIOS_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_EMIOS_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_EMIOS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.c and Pwm_eMios.h are different"
#endif

#if (PWM_IPW_VENDOR_ID_C != PWM_IPW_NOTIF_VENDOR_ID)
    #error "Pwm_Ipw.c and Pwm_Ipw_Notif.h have different vendor ids"
#endif

#if ((PWM_IPW_AR_RELEASE_MAJOR_VERSION_C    != PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_MINOR_VERSION_C    != PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_AR_RELEASE_REVISION_VERSION_C != PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw.c and Pwm_Ipw_Notif.h are different"
#endif

#if ((PWM_IPW_SW_MAJOR_VERSION_C != PWM_IPW_NOTIF_SW_MAJOR_VERSION) || \
     (PWM_IPW_SW_MINOR_VERSION_C != PWM_IPW_NOTIF_SW_MINOR_VERSION) || \
     (PWM_IPW_SW_PATCH_VERSION_C != PWM_IPW_NOTIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw.c and Pwm_Ipw_Notif.h are different"
#endif

/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/
 
/*===============================================================================================
*                                       CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL VARIABLES
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/

/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
#define PWM_START_SEC_CODE
/*
* @violates @ref Pwm_IPW_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"


/*================================================================================================*/
/**
* @brief            Pwm_Ipw_Init
* @details          This function call the supported IP initialization functions.
*
* @param[in]        pIpConfig - Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_Init
(   
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (NULL_PTR != pIpConfig->peMiosIpConfig)
    {
        /* Call EMIOS IP init function */
        Pwm_eMios_Init(pIpConfig->peMiosIpConfig);
    }
}


/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief            Pwm_Ipw_DeInit
* @details          This function call the supported IP deinitialization functions.
*
* @param[in]        pIpConfig - Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_DeInit
(
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    if (NULL_PTR != pIpConfig->peMiosIpConfig)
    {
        /* Call EMIOS IP deinit function */
        Pwm_eMios_DeInit(pIpConfig->peMiosIpConfig);
    }
}
#endif /* PWM_DE_INIT_API */


/*===============================================================================================*/
#if (PWM_SET_DUTY_CYCLE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetDutyCycle
* @details          This function will call SetDutyCycle function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        u16DutyCycle    Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetDutyCycle
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16,           AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    Pwm_eMios_SetDutyCycle((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                             u16DutyCycle,
                             pIpConfig->peMiosIpConfig);
}
#endif /* PWM_SET_DUTY_CYCLE_API */


/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetPeriodAndDuty
* @details          This function will call SetPeriodAndDuty function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        nPeriod         Pwm signal period value
* @param[in]        u16DutyCycle    Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetPeriodAndDuty
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_PeriodType,   AUTOMATIC)                 nPeriod,
    VAR         (uint16,           AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    Pwm_eMios_SetPeriodAndDuty((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                 nPeriod,
                                 u16DutyCycle,
                                 pIpConfig->peMiosIpConfig);
}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetOutputToIdle
* @details          This function will call SetOutputToIdle function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           void
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetOutputToIdle
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    Pwm_eMios_SetOutputToIdle((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                    pIpConfig->peMiosIpConfig);
}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief            Pwm_Ipw_GetOutputState
* @details          This function will call GetOutputState function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
*
*/
FUNC(Pwm_OutputStateType,PWM_CODE) Pwm_Ipw_GetOutputState
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    VAR(Pwm_OutputStateType, AUTOMATIC) nRetVal = PWM_LOW;

    nRetVal = Pwm_eMios_GetOutputState((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                        pIpConfig->peMiosIpConfig);
    return nRetVal;
}
#endif /* PWM_GET_OUTPUT_STATE_API */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief            Pwm_Ipw_DisableNotification
* @details          This function will call DisableNotification function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
*
*/
FUNC(void,PWM_CODE) Pwm_Ipw_DisableNotification
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    Pwm_eMios_DisableNotification((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                    pIpConfig->peMiosIpConfig);
}


/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_EnableNotification
* @details          This function will call EnableNotification function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        eNotification   Notification type to be enabled
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
*
*/
FUNC (void, PWM_CODE) Pwm_Ipw_EnableNotification
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    Pwm_eMios_EnableNotification((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                       eNotification,
                                       pIpConfig->peMiosIpConfig);
}

#endif /* PWM_NOTIFICATION_SUPPORTED */


#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_GetChannelState
* @details          This function will call GetChannelState function for the corresponding IP of PwmChannel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @return           uint16
*/
FUNC (uint16, PWM_CODE) Pwm_Ipw_GetChannelState
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    VAR(uint16, AUTOMATIC) dutyCycle = (uint16)0x00;
    
    dutyCycle = Pwm_eMios_GetChannelState((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig);
    return dutyCycle;
}
#endif /* PWM_GET_CHANNEL_STATE */

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_ValidateNotification
* @details          This function will check validate of Edge type with polarity
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
* @retval           E_NOT_OK        Notification handler is not valid
*/

FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateNotification
(
    VAR         (Pwm_ChannelType,           AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_EdgeNotificationType,  AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    retVal = Pwm_eMios_ValidateNotification
             (
                (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                eNotification
             );
    return retVal;
}

#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_DUTY_CYCLE_API == STD_ON))
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_ValidateParamParamOffsetDuty
* @details          This function will check Offset parameter with period default and intput duty of 
*                   current channel
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        u16DutyCycle    Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @retval           uint8           the error id
*/
FUNC (uint8, PWM_CODE) Pwm_Ipw_ValidateParamParamOffsetDuty
/* @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint16        ,   AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */
    VAR(uint8, AUTOMATIC) retVal = (uint8)0U;

    retVal = Pwm_eMios_ValidateParamOffsetDuty
                (
                    (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                    u16DutyCycle,
                    pIpConfig->peMiosIpConfig
                );

    return retVal;
}
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_TRIGGER_DELAY_API == STD_ON))
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_GetCurrentPeriodValue
* @details          This function will calculate the current period value
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @retval           Pwm_PeriodType  the current period value
*/
FUNC (Pwm_PeriodType, PWM_CODE) Pwm_Ipw_GetCurrentPeriodValue
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    VAR(Pwm_PeriodType, AUTOMATIC) nPeriod;
    
    nPeriod = (Pwm_PeriodType)Pwm_eMios_GetCurrentPeriodValue
                            (
                                (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                pIpConfig->peMiosIpConfig
                            );
    return nPeriod;
}
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_ValidateTriggerMode
* @details          This function will check validate of current channel mode. The mode must be OPWMT
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
* @nRetVal          E_NOT_OK        Current channel mode is invalid
*/
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateTriggerMode
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;

    nRetVal = Pwm_eMios_ValidateTriggerMode
              (
                (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                pIpConfig->peMiosIpConfig
              );

    return nRetVal;
}
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_COUNTER_BUS_API == STD_ON))
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_ValidateCounterBus
* @details          This function will validate of counter bus
*
* @param[in]        uint32          the counter bus id
*
* @retval           Std_ReturnType  E_OK/E_NOT_OK
*/
FUNC (Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateCounterBus
(
    VAR         (uint32,           AUTOMATIC)                 u32Bus
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) retVal = (Std_ReturnType)E_OK;

    retVal = Pwm_eMios_ValidateCounterBus(u32Bus);

    return retVal;
}
#endif

#if (PWM_PARAM_CHECK == STD_ON)
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_ValidateParamOffset
* @details          This function will Offset parameter with period and duty default of all channel
*
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*
* @retval           uint8           the error id
*/
FUNC(uint8, PWM_CODE) Pwm_Ipw_ValidateParamOffset
(
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */
    VAR(uint8, AUTOMATIC) retVal = (uint8)0U;

    retVal = Pwm_eMios_ValidateParamOffset(pIpConfig->peMiosIpConfig);

    return retVal;
}
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_GetMaxPeriodValue
* @details          This function will calculate the maximum period value supported by hardware
*
* @param[in]        nChannelNumber  Pwm channel id in top configuration structure
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*/
/** @violates @ref Pwm_Ipw_C_REF_6 external  could be made static */
FUNC (uint32, PWM_CODE) Pwm_Ipw_GetMaxPeriodValue
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    VAR(uint32, AUTOMATIC) u32RetVal;
    
    u32RetVal = Pwm_eMios_GetMaxPeriodValue
                (
                    (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig, 
                    pIpConfig->peMiosIpConfig
                );
    return u32RetVal;
}

#endif /* PWM_GET_CHANNEL_STATE_API */

#ifdef PWM_SET_COUNTER_BUS_API
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_SetCounterBus
* @details          This function will change the bus of pwm channels running.
* @param[in]        ChannelNumber - pwm channel id
* @param[in]        Bus           - the eMIOS bus to change to
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetCounterBus
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (uint32,           AUTOMATIC)                 u32Bus,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    Pwm_eMios_SetCounterBus((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                              pIpConfig->peMiosIpConfig,
                              u32Bus);
}
#endif
#endif /* PWM_SET_COUNTER_BUS_API */

#ifdef PWM_SET_CHANNEL_OUTPUT_API
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_SetChannelOutput
* @details          This function is useful to set the state of the PWM pin as requested
* @param[in]        ChannelNumber - pwm channel id
* @param[in]        eState        - Active/Inactive state of the channel
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetChannelOutput
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_StateType,    AUTOMATIC)                 eState,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    Pwm_eMios_SetChannelOutput((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                              pIpConfig->peMiosIpConfig, eState);
}
#endif
#endif /* PWM_SET_CHANNEL_OUTPUT_API */

#ifdef PWM_SET_TRIGGER_DELAY_API
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Implementation specific function to change the trigger delay
* @details          This function is useful to set the trigger delay to opwmt mode. If no DET error
*                   reported then the trigger delay for  the PWM channels will be set. If development
*                   error detection for the Pwm module is enabled:
*                       - Report the error to the Development Error Tracer.
*                       - Skip the desired functionality in order to avoid any corruptions of data 
*                   or hardware registers: This means leave the function without any actions.
*
* @param[in]        nChannelNumber   - pwm channel id
* @param[in]        nTriggerDelay    - triggerdelay
*
*
*/
/*===============================================================================================*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetTriggerDelay
(
    VAR         (Pwm_ChannelType,  AUTOMATIC)                 nChannelNumber,
    VAR         (Pwm_PeriodType,   AUTOMATIC)                 nTriggerDelay,
    CONSTP2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    Pwm_eMios_SetTriggerDelay((*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
                                pIpConfig->peMiosIpConfig, nTriggerDelay);
}
#endif
#endif/*PWM_SET_TRIGGER_DELAY_API*/

#ifdef PWM_BUFFER_TRANSFER_EN_DIS_API
#if (PWM_BUFFER_TRANSFER_EN_DIS_API == STD_ON)
/*===============================================================================================*/
/**
* @brief            Implementation specific function to enable/disable the buffer transfer.
* @details          This function is useful to enable/disable the buffer transfer to synchronize
*                   multiple PWM channels.
* @param[in]        u8ModuleIndex   - eMIOS module
*                   u32ChannelMasks - channel mask set
*/
FUNC (void, PWM_CODE) Pwm_Ipw_BufferTransferEnableDisable
/** @violates @ref Pwm_IPW_C_REF_5 Identifier exceeds 31 chars. */
(
    VAR         (uint8,            AUTOMATIC)                 u8ModuleIndex,
    VAR         (uint32,           AUTOMATIC)                 u32ChannelMasks
)
{
    Pwm_eMios_BufferTransferEnableDisable(u8ModuleIndex, u32ChannelMasks);
}
#endif
#endif

/*===============================================================================================*/
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief            Pwm_Ipw_SetClockMode
* @details          This function will call SetClockMode function of all configured Hw IPs
*
* @param[in]        ePrescaler      Prescaler - prescaler type 
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*/
FUNC (void, PWM_CODE) Pwm_Ipw_SetClockMode
(
    VAR         (Pwm_PrescalerType,         AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_IpConfigType,          AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Call eMios IP function */
    Pwm_eMios_SetClockMode(ePrescaler, pIpConfig->peMiosIpConfig);
}
#endif
/*===============================================================================================*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
/**
* @brief            Pwm_Ipw_ValidateIdleState
* @details          This function will call ValidateIdleState function of all configured Hw IPs
*
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*/
FUNC(Std_ReturnType, PWM_CODE) Pwm_Ipw_ValidateIdleState
(
    P2CONST(Pwm_IpConfigType, AUTOMATIC, PWM_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */ 
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;

    nRetVal = Pwm_eMios_ValidateIdleState(pIpConfig->peMiosIpConfig);

    return nRetVal;
}

/*===============================================================================================*/
/**
* @brief            Pwm_Ipw_SetPowerState
* @details          This function will call SetPowerState function of all configured Hw IPs
*
* @param[in]        nPowerState     target power mode
* @param[in]        pIpConfig       Pointer to PWM top configuration structure
*/

FUNC(void, PWM_CODE) Pwm_Ipw_SetPowerState
(
    P2CONST     (Pwm_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) pIpConfig,
    VAR         (Pwm_PowerStateType,AUTOMATIC)                 nPowerState
)
{
    /* Call eMios IP function */
    Pwm_eMios_SetPowerState(pIpConfig->peMiosIpConfig, nPowerState);
}
#endif


#define PWM_STOP_SEC_CODE
/*
* @violates @ref Pwm_IPW_C_REF_1 Only preprocessor statements and comments before "#include"
*/
/*
* @violates @ref Pwm_IPW_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
