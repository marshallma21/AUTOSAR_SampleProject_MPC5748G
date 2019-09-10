/**
*   @file    Adc_Ipw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - Separation header layer of high-low level drivers.
*   @details Header interface between common and low level driver.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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

#ifndef ADC_IPW_H
#define ADC_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Ipw_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro. 
* Function like macros are used to reduce code complexity.
*
* @section Adc_Ipw_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Adc_Ipw_h_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
* 
* @section Adc_Ipw_h_REF_4
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* These objects are used in several files in the code.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc_Types.h"
#include "Adc_Adcdig.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_IPW_H                       43
#define ADC_AR_RELEASE_MAJOR_VERSION_IPW_H        4
#define ADC_AR_RELEASE_MINOR_VERSION_IPW_H        2
/** @violates @ref Adc_Ipw_h_REF_3 MISRA-C:2004 Rule 1.4: 31 character significance */
#define ADC_AR_RELEASE_REVISION_VERSION_IPW_H     2
#define ADC_SW_MAJOR_VERSION_IPW_H                1
#define ADC_SW_MINOR_VERSION_IPW_H                0
#define ADC_SW_PATCH_VERSION_IPW_H                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and Adc_Types header file are of the same vendor */
#if (ADC_VENDOR_ID_IPW_H != ADC_VENDOR_ID_TYPES)
    #error "Adc_Ipw.c and Adc_Types.h have different vendor ids"
#endif

/* Check if source file and Adc_Types header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_IPW_H != ADC_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_MINOR_VERSION_IPW_H != ADC_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_REVISION_VERSION_IPW_H != ADC_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
#error "AutoSar Version Numbers of Adc_Ipw.h and Adc_Types.h are different"
#endif

/* Check if source file and ADC Adc_Types header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_IPW_H != ADC_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SW_MINOR_VERSION_IPW_H != ADC_SW_MINOR_VERSION_TYPES) || \
     (ADC_SW_PATCH_VERSION_IPW_H != ADC_SW_PATCH_VERSION_TYPES) \
    )
#error "Software Version Numbers of Adc_Ipw.h and Adc_Types.h are different"
#endif
/* Check if source file and Adc_ADCDig header file are of the same vendor */
#if (ADC_VENDOR_ID_IPW_H != ADC_VENDOR_ID_ADCDIG)
    #error "Adc_Ipw.c and Adc_Adcdig.h have different vendor ids"
#endif

/* Check if source file and Adc_ADCDig header file are of the same Autosar version */
    #if ((ADC_AR_RELEASE_MAJOR_VERSION_IPW_H != ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG) || \
         (ADC_AR_RELEASE_MINOR_VERSION_IPW_H != ADC_AR_RELEASE_MINOR_VERSION_ADCDIG) || \
         (ADC_AR_RELEASE_REVISION_VERSION_IPW_H != ADC_AR_RELEASE_REVISION_VERSION_ADCDIG) \
        )
    #error "AutoSar Version Numbers of Adc_Ipw.h and Adc_Adcdig.h are different"
#endif

/* Check if source file and ADC Adc_ADCDig header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_IPW_H != ADC_SW_MAJOR_VERSION_ADCDIG) || \
     (ADC_SW_MINOR_VERSION_IPW_H != ADC_SW_MINOR_VERSION_ADCDIG) || \
     (ADC_SW_PATCH_VERSION_IPW_H != ADC_SW_PATCH_VERSION_ADCDIG) \
    )
#error "Software Version Numbers of Adc_Ipw.h and Adc_Adcdig.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Functions mapping.
* @details        Middle layer versus Low layer functions mapping
*
*/
#define Adc_Ipw_Init                                        (Adc_Adcdig_Init)

#if (ADC_DEINIT_API == STD_ON)
    #define Adc_Ipw_DeInit                                    (Adc_Adcdig_DeInit)
#endif /* ADC_DEINIT_API == STD_ON */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    #define Adc_Ipw_StartInjectedConversion                   (Adc_Adcdig_StartInjectedConversion)
    #define Adc_Ipw_StartNormalConversion                     (Adc_Adcdig_StartNormalConversion)
    #define Adc_Ipw_StopCurrentConversion                     (Adc_Adcdig_StopCurrentConversion)      
#endif /* ADC_ENABLE_START_STOP_GROUP_API == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
    #define Adc_Ipw_EnableHardwareTrigger                     (Adc_Adcdig_EnableHardwareTrigger)
    #define Adc_Ipw_DisableHardwareTrigger                    (Adc_Adcdig_DisableHardwareTrigger)
#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
    #define Adc_Ipw_EnableCtuTrigger                          (Adc_Adcdig_EnableCtuTrigger)
    #define Adc_Ipw_DisableCtuTrigger                         (Adc_Adcdig_DisableCtuTrigger)
    #define Adc_Ipw_HwResultReadGroup                         (Adc_Adcdig_HwResultReadGroup)
#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_READ_GROUP_API == STD_ON)
    #define Adc_Ipw_ReadGroup                                 (Adc_Adcdig_ReadGroup)
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if (ADC_SET_MODE_API == STD_ON)
    #define Adc_Ipw_SetMode                                   (Adc_Adcdig_SetMode)
#endif /* ADC_SET_MODE_API == STD_ON */

#if (ADC_CALIBRATION == STD_ON)
    #define Adc_Ipw_Calibrate                                 (Adc_Adcdig_Calibrate)
#endif /* ADC_CALIBRATION == STD_ON */

#if (ADC_SELF_TEST == STD_ON)
    #define Adc_Ipw_SelfTest                                  (Adc_Adcdig_SelfTest)
#endif /* ADC_SELF_TEST == STD_ON */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
    #define Adc_Ipw_ConfigureThreshold                        (Adc_Adcdig_ConfigureThreshold)
#endif /* ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    #define Adc_Ipw_SetClockMode      (Adc_Adcdig_SetClockMode)
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
  #define Adc_Ipw_SetPowerState                               (Adc_Adcdig_SetPowerState)
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
    #define Adc_Ipw_EnableCtuControlMode                      (Adc_Adcdig_EnableCtuControlMode)
    #define Adc_Ipw_DisableCtuControlMode                     (Adc_Adcdig_DisableCtuControlMode)
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_Ipw_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief          Unit status structure
* @details        Structure for the unit status.
*
* @violates @ref Adc_Ipw_h_REF_4  External object declared more than once
*/
extern VAR(Adc_NCMRType, ADC_VAR) Adc_aNCMRxMask[ADC_NO_OF_ENABLE_CH_DISABLE_CH_GROUPS];
#endif /* ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON */

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_Ipw_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
#define ADC_START_SEC_VAR_NO_INIT_8
/** @violates @ref Adc_Ipw_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
 
/** @violates @ref Adc_Ipw_h_REF_4  External object declared more than once*/
extern VAR(uint8, ADC_VAR) Adc_au8BctuGroupTriggersActive[ADC_MAX_HW_UNITS][ADC_MAX_HADRWARE_TRIGGERS];

#define ADC_STOP_SEC_VAR_NO_INIT_8
/** @violates @ref Adc_Ipw_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
#endif /* ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON */ 

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/** @violates @ref Adc_Ipw_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
FUNC(boolean, ADC_CODE) Adc_CheckConversionValuesInRange
(
    VAR(Adc_ValueGroupType, AUTOMATIC) Value,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_ChannelType, AUTOMATIC) Index
);
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

#if (ADC_ENABLE_QUEUING == STD_ON)
FUNC(void, ADC_CODE) Adc_RemoveFromQueue
(
    CONST(Adc_HwUnitType, AUTOMATIC) Unit,
    CONST(Adc_QueueIndexType, AUTOMATIC) CurQueueIndex
);
#endif /* (ADC_ENABLE_QUEUING == STD_ON) */

FUNC(void, ADC_CODE) Adc_GetCMR_Register
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_NCMRType , AUTOMATIC, ADC_APPL_DATA) pCMRMask
);

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_Ipw_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_IPW_H */

/** @} */
