/**
*   @file    Adc_Adcdig_Irq.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - ADCDig IP header file.
*   @details ADCDig low level driver API.
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

#ifndef ADC_ADCDIG_IRQ_H
#define ADC_ADCDIG_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
*
* @section Adc_Adcdig_Irq_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Adcdig_Irq_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_Adcdig_Irq_h_REF_3
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* This violation cannot be removed due to the interaction with MCL module.
*
* @section Adc_Adcdig_Irq_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_ADCDIG_IRQ                      43
/**
* @violates @ref Adc_Adcdig_Irq_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_IRQ       4

/**
* @violates @ref Adc_Adcdig_Irq_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_IRQ       2
/**
* @violates @ref Adc_Adcdig_Irq_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_IRQ    2
#define ADC_SW_MAJOR_VERSION_ADCDIG_IRQ               1
#define ADC_SW_MINOR_VERSION_ADCDIG_IRQ               0
#define ADC_SW_PATCH_VERSION_ADCDIG_IRQ               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
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
#define ADC_START_SEC_CODE
/**
 * @violates @ref Adc_Adcdig_Irq_h_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_h_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#ifdef ADC_MULTIPLE_HARDWARE_TRIGGERS
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
FUNC(void, ADC_CODE) Adc_Adcdig_EndMultipleCtuConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32TrgSrc
/** @violates @ref Adc_Adcdig_Irq_h_REF_3 Function declaration */
);
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */
#endif

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) \
    )
#if (ADC_HW_TRIGGER_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Adcdig_EndHardwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(boolean, AUTOMATIC) bInjectedFlag
/** @violates @ref Adc_Adcdig_Irq_h_REF_3 Function declaration */
);
#endif /* ADC_HW_TRIGGER_API == STD_ON */
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#ifdef ADC_UNIT_0_ISR_USED
ISR(Adc_Adcdig_EndGroupConvUnit0);
#endif /* ADC_UNIT_0_ISR_USED */
#ifdef ADC_UNIT_1_ISR_USED
ISR(Adc_Adcdig_EndGroupConvUnit1);
#endif /* ADC_UNIT_1_ISR_USED */
#ifdef ADC_UNIT_2_ISR_USED
ISR(Adc_Adcdig_EndGroupConvUnit2);
#endif /* ADC_UNIT_2_ISR_USED */
#ifdef ADC_UNIT_3_ISR_USED
ISR(Adc_Adcdig_EndGroupConvUnit3);
#endif /* ADC_UNIT_3_ISR_USED */

#ifdef ADC_WDG_SUPPORTED
  #ifndef ADC_WDG_GROUP_SHARED_ISR
    #ifdef ADC_UNIT_0_WDG_ISR_USED
/**
* @violates @ref Adc_Adcdig_Irq_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
ISR(Adc_Adcdig_WatchDogThresholdUnit0);
    #endif /* ADC_UNIT_0_WDG_ISR_USED */
    #ifdef ADC_UNIT_1_WDG_ISR_USED
/**
* @violates @ref Adc_Adcdig_Irq_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
ISR(Adc_Adcdig_WatchDogThresholdUnit1);
    #endif /* ADC_UNIT_1_WDG_ISR_USED */
    #ifdef ADC_UNIT_2_WDG_ISR_USED
/**
* @violates @ref Adc_Adcdig_Irq_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
ISR(Adc_Adcdig_WatchDogThresholdUnit2);
    #endif /* ADC_UNIT_2_WDG_ISR_USED */
    #ifdef ADC_UNIT_3_WDG_ISR_USED
/**
* @violates @ref Adc_Adcdig_Irq_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
ISR(Adc_Adcdig_WatchDogThresholdUnit3);
    #endif /* ADC_UNIT_3_WDG_ISR_USED */
  #endif  /* ADC_WDG_GROUP_SHARED_ISR */
#endif /* ADC_WDG_SUPPORTED */

#ifdef ADC_DMA_SUPPORTED
#ifdef  ADC_UNIT_0
/** @violates @ref Adc_Adcdig_Irq_h_REF_3 Function declaration */
FUNC(void, ADC_CODE) Adc_Adcdig_DmaTransferComplete0(void);
#endif
#ifdef  ADC_UNIT_1
/** @violates @ref Adc_Adcdig_Irq_h_REF_3 Function declaration */
FUNC(void, ADC_CODE) Adc_Adcdig_DmaTransferComplete1(void);
#endif
#ifdef  ADC_UNIT_2
/** @violates @ref Adc_Adcdig_Irq_h_REF_3 Function declaration */
FUNC(void, ADC_CODE) Adc_Adcdig_DmaTransferComplete2(void);
#endif
#ifdef  ADC_UNIT_3
/** @violates @ref Adc_Adcdig_Irq_h_REF_3 Function declaration */
FUNC(void, ADC_CODE) Adc_Adcdig_DmaTransferComplete3(void);
#endif
#endif /* ADC_DMA_SUPPORTED */

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_Adcdig_Irq_h_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Adcdig_Irq_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
#ifdef __cplusplus
}
#endif

#endif /* ADC_ADCDIG_IRQ_H */

/** @} */
