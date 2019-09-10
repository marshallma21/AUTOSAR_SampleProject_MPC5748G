/**
*   @file    Gpt_Rtc.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios_Stm_Pit
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

#ifndef GPT_RTC_H
#define GPT_RTC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_RTC_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section GPT_RTC_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_RTC_H_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*@section GPT_RTC_H_REF_4
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer
* type shall not be implicitly converted to a different underlying type.
*
* @section GPT_RTC_H_REF_5
* Violates MISRA 2004 Required Rule 19.11, All macro identifiers in preprocessor directives shall be defined
* before use, except in #ifdef and #ifndef preprocessor directives and the defined() operator.
* This violation is due to configuration defines, defined in a different file. Those defines are always present.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Rtc_Types.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_RTC_VENDOR_ID                       43
/* @violates @ref GPT_RTC_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref GPT_RTC_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref GPT_RTC_H_REF_3 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
#define GPT_RTC_AR_RELEASE_REVISION_VERSION     2
#define GPT_RTC_SW_MAJOR_VERSION                1
#define GPT_RTC_SW_MINOR_VERSION                0
#define GPT_RTC_SW_PATCH_VERSION                0

/*==================================================================================================
*                                    FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h file are of the same Autosar version */

#if (GPT_RTC_VENDOR_ID != GPT_RTC_TYPES_VENDOR_ID)
    #error "Gpt_Rtc.h and Gpt_Rtc_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_RTC_AR_RELEASE_MAJOR_VERSION != GPT_RTC_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_MINOR_VERSION != GPT_RTC_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_REVISION_VERSION != GPT_RTC_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc.h and Gpt_Rtc_Types.h are different"
#endif
/* Check if header file and Gpt header file are of the same software version */
#if ((GPT_RTC_SW_MAJOR_VERSION != GPT_RTC_TYPES_SW_MAJOR_VERSION) || \
     (GPT_RTC_SW_MINOR_VERSION != GPT_RTC_TYPES_SW_MINOR_VERSION) || \
     (GPT_RTC_SW_PATCH_VERSION != GPT_RTC_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Rtc.h and Gpt_Rtc_Types.h are different"
#endif

#if ( GPT_RTC_VENDOR_ID!= GPT_VENDOR_ID_CFG)
    #error "Gpt_Rtc.h and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_RTC_AR_RELEASE_MAJOR_VERSION != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_RTC_AR_RELEASE_MINOR_VERSION != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_RTC_AR_RELEASE_REVISION_VERSION != GPT_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Gpt_Rtc.h and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_RTC_SW_MAJOR_VERSION != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_RTC_SW_MINOR_VERSION != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_RTC_SW_PATCH_VERSION != GPT_SW_PATCH_VERSION_CFG) )
    #error "Software Version Numbers of Gpt_Rtc.h and Gpt_Cfg.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if (GPT_DEV_ERROR_DETECT == STD_ON)

/**
* @brief  RTC specific macro for checking the timeout value.
* @details        A detailed text description of the code object being described, it can span more
*
* @param[in]      value      Timeout vaule.
*
* @return         Boolean
* @retval         TRUE - Time out value is valid
* @retval         FALSE - Time out value is Invalid
*
*/
/* @violates @ref GPT_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.7,  Use of function like macro */
#define RTC_INVALID_TIMEOUT_VALUE(value)    ((value) > RTC_API_RTCC_APIVAL_MAX_VALUE_U32)
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define GPT_START_SEC_VAR_NO_INIT_32
/** @violates @ref GPT_RTC_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#if (GPT_RTC_USED == STD_ON) 
/**
* @brief          Global array variable used to store the runtime target time value.
*/
extern VAR(uint32, GPT_VAR) Gpt_Rtc_u32TargetValue;
#endif
#define GPT_STOP_SEC_VAR_NO_INIT_32
/** @violates @ref GPT_RTC_H_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_RTC_H_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

FUNC (void, GPT_CODE) Gpt_Rtc_Init
(
    VAR(Rtc_Gpt_ChannelClkSrcType,  AUTOMATIC) channelClkSrc,
    VAR(uint8,                      AUTOMATIC) u8ChannelPrescale,
    VAR(boolean,                    AUTOMATIC) bFreezeEnable
);

#if (GPT_DEINIT_API == STD_ON)
FUNC (void, GPT_CODE) Gpt_Rtc_DeInit(void);
#endif

FUNC (void, GPT_CODE) Gpt_Rtc_StartTimer
(   
    VAR(uint32,                     AUTOMATIC) u32Value
);

FUNC (void, GPT_CODE) Gpt_Rtc_StopTimer(void);

FUNC (uint32, GPT_CODE) Gpt_Rtc_GetTimeElapsed
(
    P2VAR(boolean,      AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
    P2VAR(uint32,       AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
);
#if (GPT_SET_CLOCK_MODE == STD_ON)
FUNC (void, GPT_CODE) Gpt_Rtc_SetClockMode
(
    VAR(uint8, AUTOMATIC) u8chPrescale
);
#endif
FUNC(void, GPT_CODE) Gpt_Rtc_EnableInterrupt(void);

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
FUNC(void, GPT_CODE) Gpt_Rtc_DisableInterrupt(void);
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API || GPT_WAKEUP_FUNCTIONALITY_API */

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_RTC_H_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*GPT_RTC_H*/

/** @} */
