/**
*   @file    Adc_Adcdig.h
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

#ifndef ADC_ADCDIG_H
#define ADC_ADCDIG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Adcdig_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_Adcdig_h_REF_4
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
#include "Adc_Reg_eSys_Adcdig.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_ADCDIG                      43
/**
* @violates @ref Adc_Adcdig_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG       4
/**
* @violates @ref Adc_Adcdig_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MINOR_VERSION_ADCDIG       2
/**
* @violates @ref Adc_Adcdig_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_ADCDIG    2
#define ADC_SW_MAJOR_VERSION_ADCDIG               1
#define ADC_SW_MINOR_VERSION_ADCDIG               0
#define ADC_SW_PATCH_VERSION_ADCDIG               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Reg_eSys_ADCDig header file are of the same vendor */
#if (ADC_VENDOR_ID_ADCDIG != ADC_VENDOR_ID_REG)
    #error "Adc_Adcdig.h and Adc_Reg_eSys_Adcdig.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_ADCDig header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG != ADC_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG != ADC_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADCDIG != ADC_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_Adcdig.h and Adc_Reg_eSys_Adcdig.h are different"
#endif

/* Check if source file and ADC Reg_eSys_ADCDig header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_ADCDIG != ADC_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_ADCDIG != ADC_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_ADCDIG != ADC_SW_PATCH_VERSION_REG) \
    )
#error "Software Version Numbers of Adc_Adcdig.h and Adc_Reg_eSys_Adcdig.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define ADCDIG_DMA_NUM_TCD_U8             (8U)
#define ADCDIG_TCD_REG_SIZE_U8            (32U)
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
/** @violates @ref Adc_Adcdig_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

FUNC(void, ADC_CODE) Adc_Adcdig_Init
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
);

#if (ADC_DEINIT_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Adcdig_DeInit(void);
#endif /* (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Adcdig_StartInjectedConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

FUNC(void, ADC_CODE) Adc_Adcdig_StartNormalConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_StopCurrentConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bStartApi
);
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_HW_TRIGGER_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Adcdig_EnableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
FUNC(void, ADC_CODE) Adc_Adcdig_DisableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Adcdig_EnableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);

FUNC(void, ADC_CODE) Adc_Adcdig_DisableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);

FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_HwResultReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pDataPtr
);
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */

#if (ADC_READ_GROUP_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_ReadGroup
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pDataPtr,
    P2VAR(boolean, AUTOMATIC, ADC_APPL_DATA) pFlag
);
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if (ADC_SET_MODE_API == STD_ON)
FUNC (Std_ReturnType, ADC_CODE) Adc_Adcdig_SetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) eSetMode
);
#endif /* (ADC_SET_MODE_API == STD_ON) */

#if (ADC_CALIBRATION == STD_ON)
FUNC(void, ADC_CODE) Adc_Adcdig_Calibrate
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    P2VAR(Adc_CalibrationStatusType , AUTOMATIC, ADC_APPL_DATA) pStatus
);
#endif /* ADC_CALIBRATION == STD_ON */

#if (ADC_SELF_TEST == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_SelfTest
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* ADC_SELF_TEST == STD_ON */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_ConfigureThreshold
(
    VAR(Adc_GroupType, AUTOMATIC) GroupId,
    VAR(Adc_ValueGroupType, AUTOMATIC) LowValue,
    VAR(Adc_ValueGroupType, AUTOMATIC) HighValue
);
#endif /* (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_SetClockMode
(
    VAR(Adc_DualClockModeType, AUTOMATIC) eClockMode
);
#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
FUNC(void, ADC_CODE) Adc_Adcdig_EnableCtuControlMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

FUNC(void, ADC_CODE) Adc_Adcdig_DisableCtuControlMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

#if (defined(ADC_DMA_SUPPORTED) || (ADC_DEINIT_API == STD_ON))
FUNC(void, ADC_CODE) Adc_Adcdig_ClearDmarRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* (defined(ADC_DMA_SUPPORTED) || (ADC_DEINIT_API == STD_ON)) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_SetPowerState
(
    VAR(Adc_PowerStateType, AUTOMATIC) Adc_ePowerState
);
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#if ( (ADC_DEINIT_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_SETCHANNEL_API == STD_ON) || \
      ((ADC_HW_TRIGGER_API == STD_ON) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) )
FUNC(void, ADC_CODE) Adc_Adcdig_SetNcmrRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32Precision,
    VAR(uint32, AUTOMATIC) u32Extended,
    VAR(uint32, AUTOMATIC) u32External
);
#endif

FUNC(void, ADC_CODE) Adc_Adcdig_SetJcmrRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32Precision,
    VAR(uint32, AUTOMATIC) u32Extended,
    VAR(uint32, AUTOMATIC) u32External
);

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_Adcdig_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* ADC_ADCDIG_H */

/** @} */
