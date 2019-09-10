/**
*   @file           Pwm_Ipw_Types.h
*
*   @version        1.0.0
*
*   @brief          AUTOSAR Pwm - PWM driver Ipw header file.
*   @details        Ipw defines, types used by PWM driver.
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



#ifndef PWM_IPW_TYPES_H
#define PWM_IPW_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_IPW_Types_H_REF_1
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*/
/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pwm_Types.h"
#include "Pwm_eMios_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm_Ipw_Types.h
*/
#define PWM_IPW_TYPES_VENDOR_ID                         43
#define PWM_IPW_TYPES_MODULE_ID                         121
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION          4
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION          2
/* @violates @ref Pwm_IPW_Types_H_REF_1 Identifier exceeds 31 chars. */
#define PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION       2
#define PWM_IPW_TYPES_SW_MAJOR_VERSION                  1
#define PWM_IPW_TYPES_SW_MINOR_VERSION                  0
#define PWM_IPW_TYPES_SW_PATCH_VERSION                  0
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if included Pwm_Ftm_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_Types.h have different vendor ids"
#endif

/* Check if included Pwm_Ftm_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw_Types.h and Pwm_Types.h are different"
#endif

/* Check if included Pwm_Ftm_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw_Types.h and Pwm_Types.h are different"
#endif

/* Check if included Pwm_FlexPwm_Types.h header file has same vendor */
#if (PWM_IPW_TYPES_VENDOR_ID != PWM_EMIOS_TYPES_VENDOR_ID)
    #error "Pwm_Ipw_Types.h and Pwm_eMios_Types.h have different vendor ids"
#endif

/* Check if included Pwm_FlexPwm_Types.h header file has same AUTOSAR version */
#if ((PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    !=  PWM_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION    !=  PWM_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION !=  PWM_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Ipw_Types.h and Pwm_eMios_Types.h are different"
#endif

/* Check if included Pwm_FlexPwm_Types.h header file has same software version */
#if ((PWM_IPW_TYPES_SW_MAJOR_VERSION !=  PWM_EMIOS_TYPES_SW_MAJOR_VERSION) || \
     (PWM_IPW_TYPES_SW_MINOR_VERSION !=  PWM_EMIOS_TYPES_SW_MINOR_VERSION) || \
     (PWM_IPW_TYPES_SW_PATCH_VERSION !=  PWM_EMIOS_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_Ipw_Types.h and Pwm_eMios_Types.h are different"
#endif

/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       PLATFORM SPECIFIC DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/** @brief Symbolic name for EMIOS channels */
#define PWM_EMIOS_CHANNEL             ((Pwm_ChannelIpType)0)

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief    Defines state of PWM channel
* @details  PWM_ACTIVE - The PWM pin will be in the same state of configured polarity
*           PWM_INACTIVE - The PWM pin will be in the opposite state of configured polarity
* 
*/
typedef enum
{
    PWM_ACTIVE = 0,
    PWM_INACTIVE
} Pwm_StateType;
#endif

/**
* @brief      IP type used to implement a Pwm channel
*/

typedef uint8 Pwm_ChannelIpType;

typedef struct 
{
    /** @brief Index in the IP specific configuration table */
    CONST(uint8, PWM_CONST) u8IdxChannelConfig;
} Pwm_IpChannelConfigType;

/**
* @brief   IP specific configuration structure
* 
*/
typedef struct
{
    /* @brief pointer to the configured channels for EMIOS */
    CONSTP2CONST(Pwm_eMios_IpConfigType, PWM_CONST, PWM_APPL_CONST) peMiosIpConfig;
    /* @brief Pointer to Array containing IP type and index in the IP configuration table for each Pwm channel */
    CONST(Pwm_IpChannelConfigType,  PWM_CONST)  (*pIpChannelsConfig)[];
} Pwm_IpConfigType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
      

#ifdef __cplusplus
}
#endif

#endif    /* PWM_IPW_TYPES_H */

/** @} */

