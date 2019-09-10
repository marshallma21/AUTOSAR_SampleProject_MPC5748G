/**
*   @file    Adc_Bctu.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - low level driver header file.
*   @details BCTU low level driver API.
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

#ifndef ADC_BCTU_H
#define ADC_BCTU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Bctu_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* There are different kinds of execution code sections.
*
* @section Adc_Bctu_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
* @section Adc_Bctu_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_Bctu.h
*/
#define BCTU_VENDOR_ID                       43
#define BCTU_MODULE_ID                       123
#define BCTU_AR_RELEASE_MAJOR_VERSION        4
#define BCTU_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref Adc_Bctu_h_REF_2 Identifier exceeds 31 characters */
#define BCTU_AR_RELEASE_REVISION_VERSION     2
#define BCTU_SW_MAJOR_VERSION                1
#define BCTU_SW_MINOR_VERSION                0
#define BCTU_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if Std_Types.h file and CTUV2 header file are of the same Autosar version */
 #if ((BCTU_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (BCTU_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Bctu.h and Std_Types.h are different"
 #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
 * @brief          Mask value for each Adc unit.
 *
 */
#define ADC_UNIT_0_MASK_U32     (0x01UL)
#define ADC_UNIT_1_MASK_U32     (0x02UL)
#define ADC_UNIT_2_MASK_U32     (0x04UL)
#define ADC_UNIT_3_MASK_U32     (0x08UL)

/**
 * @brief          Start BCTU software trigger.
 *
 * @violates @ref Adc_Bctu_h_REF_3 MISRA-C:2004 Rule 19.7: Function-like macro defined
 */
#define Adc_Bctu_StartSoftwareTrigger(Trigger) \
        (REG_BIT_SET32(BCTU_SFTRGR_ADDR32(((uint32)(Trigger) >> 0x05)), 1UL << ((Trigger) & 0x1FUL)))
/**
 * @brief      Clear TRIGEN bit to disable hardware trigger
 *
 * @violates @ref Adc_Bctu_h_REF_3 MISRA-C:2004 Rule 19.7: Function-like macro defined
 */
#define Adc_Bctu_DisableInputTrigger(Trigger) \
        (REG_BIT_CLEAR32(BCTU_TRGCFG_ADDR32((uint32)(Trigger)), BCTU_INPUT_TRIG_EN_U32))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * @brief         This type defines the notification function pointer definition - BCTU
 *
 */
typedef void (*Adc_BctuNotifyType)(void);

/**
 * @brief         This type defines results buffer for conversion data
 *
 */
typedef uint16 Adc_Bctu_DataType;

/**
 * @brief         This type defines configuration for member of the list
 *
 */
typedef uint16 Adc_Bctu_ListChannelType;

/**
 * @brief         Configuration structure for input trigger.
 *
 */
typedef struct
{
    CONST(uint8, ADC_CONST) u8BctuTrCfgId;                      /**< @brief BCTU Trigger configuration number */
    CONST(uint8, ADC_CONST) u8AdcHwSelected;                    /**< @brief BCTU ADC HW selection */
    CONST(uint8, ADC_CONST) u8BctuLoop;                         /**< @brief BCTU Loop bit */
    CONST(uint8, ADC_CONST) u8BctuTrs;                          /**< @brief BCTU trigger resolution */
    CONST(uint8, ADC_CONST) u8BctuLADDR;                        /**< @brief BCTU channel value or addr of the first LIST position */
    CONST(Adc_BctuNotifyType, ADC_CONST) BctuNotification;      /**< @brief Bctu notification function pointer */
    P2P2VAR(Adc_Bctu_DataType, ADC_VAR, ADC_APPL_DATA) pResultsBufferPtr; /**< @brief pointer to user result buffer array */
    P2CONST(Adc_Bctu_ListChannelType, ADC_VAR, ADC_APPL_CONST) pAdcChannelTriggered; /**< @brief pointer to list channel array */
    CONST(uint8, ADC_CONST) u8NumListElement;                   /**< @brief Number of element in the LIST */
    CONST(uint8, ADC_CONST) u8NumHwCfg;                         /**< @brief Number of Adc unit configured */
} Adc_Bctu_TriggerConfigType;

/**
 * @brief         Main configuration structure for BCTU.
 *
 */
typedef struct
{
    P2CONST(Adc_Bctu_TriggerConfigType, ADC_VAR, ADC_APPL_CONST) pTriggerConfig;   /**< @brief Pointer to trigger configure array */
    CONST(uint8, ADC_CONST) u8NumInputTrigger;                                /**< @brief Number of input trigger */
    CONST(uint8, ADC_CONST) au8AdcUnitActive[ADC_MAX_HW_UNITS];               /**< @brief Adc unit is ON/OFF */
    CONST(uint8, ADC_CONST) au8DmaChanel[ADC_MAX_HW_UNITS];                   /**< @brief Dma channel assigned for Adc unit */
} Adc_Bctu_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/** @violates @ref Adc_Bctu_h_REF_1 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Bctu_Init
(
    P2CONST(Adc_Bctu_ConfigType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr
);
FUNC(void, ADC_CODE) Adc_Bctu_DeInit(void);
FUNC(void, ADC_CODE) Adc_Bctu_StartCtu(void);
FUNC(void, ADC_CODE) Adc_Bctu_StopCtu(void);

#if (ADC_SET_MODE_API==STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_Bctu_SetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) eSetMode
);
#endif /* (ADC_SET_MODE_API == STD_ON) */
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

#if ((ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
FUNC(void, ADC_CODE) Adc_Bctu_EnableCtuTrigger
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource,
    VAR(boolean, AUTOMATIC) bAutosarApi,
    VAR(boolean, AUTOMATIC) bFirstTrigger
);
FUNC(void, ADC_CODE) Adc_Bctu_DisableCtuTrigger
(
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource,
    VAR(boolean, AUTOMATIC) bLastTrigger
);
FUNC(void, ADC_CODE) Adc_BctuUpdateListAddress
(
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr
);
FUNC(void, ADC_CODE) Adc_BctuSortListChannels
(
    P2VAR(Adc_ChannelType, AUTOMATIC, ADC_APPL_CONST) pListChannelSorted,
    VAR(Adc_ChannelIndexType, AUTOMATIC) ListSize
);
FUNC(void, ADC_CODE) Adc_BctuUpdateListElement
(
    VAR(uint16, AUTOMATIC) u16ListIndex,
    VAR(uint32, AUTOMATIC) u32Value
);
#if (ADC_SETCHANNEL_API == STD_ON)
FUNC(void, ADC_CODE) Adc_BctuUpdateCurrentListElement
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_ChannelType, AUTOMATIC, ADC_APPL_CONST) pListChannelSorted,
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount
);
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
#endif /*(ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) */

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_Bctu_h_REF_1 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_BCTU_H */

/** @} */
