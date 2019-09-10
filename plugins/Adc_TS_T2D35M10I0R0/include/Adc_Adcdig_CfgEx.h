/**
*   @file    Adc_Adcdig_CfgEx.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - ADCDig configuration header file.
*   @details Adcdig Configuration extern low level driver API.
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

#ifndef ADC_ADCDIG_CFGEX_H
#define ADC_ADCDIG_CFGEX_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Adcdig_CfgEx_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*
* @section Adc_Adcdig_CfgEx_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Adc_Types.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_ADCDIG_CFGEX                        43
#define ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_CFGEX         4
#define ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_CFGEX         2
/** @violates @ref Adc_Adcdig_CfgEx_h_REF_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_CFGEX      2
#define ADC_SW_MAJOR_VERSION_ADCDIG_CFGEX                 1
#define ADC_SW_MINOR_VERSION_ADCDIG_CFGEX                 0
#define ADC_SW_PATCH_VERSION_ADCDIG_CFGEX                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_CFGEX != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_CFGEX != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adcdig_CfgEx.h and Mcal.h are different"
 #endif 
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID_ADCDIG_CFGEX != ADC_VENDOR_ID_TYPES)
#error "Adc_Adcdig_CfgEx.h and Adc_Types.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_CFGEX != ADC_AR_RELEASE_MAJOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_CFGEX != ADC_AR_RELEASE_MINOR_VERSION_TYPES) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_CFGEX != ADC_AR_RELEASE_REVISION_VERSION_TYPES) \
    )
#error "AutoSar Version Numbers of Adc_Adcdig_CfgEx.h and Adc_Types.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_ADCDIG_CFGEX != ADC_SW_MAJOR_VERSION_TYPES) || \
     (ADC_SW_MINOR_VERSION_ADCDIG_CFGEX != ADC_SW_MINOR_VERSION_TYPES) || \
     (ADC_SW_PATCH_VERSION_ADCDIG_CFGEX != ADC_SW_PATCH_VERSION_TYPES) \
    )
#error "Software Version Numbers of Adc_Adcdig_CfgEx.h and Adc_Types.h are different"
#endif

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
#ifdef ADC_WDG_SUPPORTED
/**
* @brief          Structure for watchdog threshold control configuration.
*
*/
typedef struct
{
    CONST(uint8, ADC_CONST) u8Register; /**< @brief Threshold register configured */
    CONST(uint32, ADC_CONST) u32ThValues; /**< @brief Threshold value */
} Adc_Adcdig_ThresholdConfigurationType;
#endif /* ADC_WDG_SUPPORTED */

/**
* @brief          Structure for channel configuration.
*
*/
typedef struct
{
    CONST(Adc_ChannelType, ADC_CONST) ChId; /**< @brief Channel Id */
#ifdef ADC_WDG_SUPPORTED
    CONST(uint8, ADC_CONST) u8ThReg; /**< @brief Threshold register configured */
    CONST(Adc_WdgNotifyType , ADC_CONST) WdogNotification; /**< @brief Wdg notification function pointer */
    CONST(uint8, ADC_CONST) u8RegIndex;         /**< @brief Channel descriptions for the WDG interrupts */
    CONST(uint32, ADC_CONST) u32Mask;         /**< @brief Channel descriptions Mask for the WDG interrupts */
#endif /* ADC_WDG_SUPPORTED */
    CONST(uint8, ADC_CONST) u8EnablePresampling; /**< @brief status to indicate the presampling state */
} Adc_Adcdig_ChannelConfigurationType;

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__)
typedef struct
{

    CONST(boolean, ADC_CONST) bChannelLimitCheck; /**< @brief Channel limit checking feature */
    CONST(Adc_ChannelRangeSelectType, ADC_CONST) eChannelRange; /**< @brief  Range conversion */
    CONST(Adc_ValueGroupType, ADC_CONST) ChannelHighLimit; /**< @brief High limit channel conversion value */
    CONST(Adc_ValueGroupType, ADC_CONST) ChannelLowLimit; /**< @brief Low limit channel conversion value */
} Adc_Adcdig_ChannelLimitCheckingType;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) || defined(__DOXYGEN__) */

/**
* @brief          Structure for Adc hardware unit configuration.
*
*/
typedef struct
{
    /**< @brief Adc hardware unit id */
    CONST(Adc_HwUnitType, ADC_CONST) AdcHardwareUnitId;
    /**< @brief Main configuration of control registers */
    CONST(uint32, ADC_CONST) u32AdcMainConfig;
    /**< @brief Prescaler of normal mode */
    CONST(uint32, ADC_CONST) u32AdcPrescale;
    /**< @brief Power down delay */
    CONST(uint8, ADC_CONST) u8AdcPwrDownDelay;
#if (ADC_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Prescaler of alternate mode */
    CONST(uint32, ADC_CONST) u32AdcAltPrescale;
    /**< @brief Power down delay for low power system frequency */
    CONST(uint8, ADC_CONST) u8AdcAltPwrDownDelay;
#endif
#if (ADC_DSDR_AVAILABLE == STD_ON)
    /** @brief Mux delay value */
    CONST(uint16, ADC_CONST) u16AdcMuxDelay;
#endif /* (ADC_DSDR_AVAILABLE == STD_ON) */
    /**< @brief presampling control register - preval0 field
       Internal voltage selection for presampling, targeting internal precision channels. */
    CONST(uint8, ADC_CONST) u8PreVal0;
    /**< @brief presampling control register - preval1 field
       Internal voltage selection for Presampling, targeting the temperature sensor channel */
    CONST(uint8, ADC_CONST) u8PreVal1;
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
    /**< @brief presampling control register - preval2 field */
    CONST(uint8, ADC_CONST) u8PreVal2;
#endif
    /**< @brief presampling control register - preconv field */
    CONST(uint8, ADC_CONST) u8PreConv;
    /**< @brief Conversion time CTR0 */
    CONST(Adc_ConversionTimeType, ADC_CONST) ConvTimeNormal;
    CONST(Adc_ConversionTimeType, ADC_CONST) ConvTimeAlternate;
#if (ADC_CTR1_AVAILABLE == STD_ON)
    /**< @brief Conversion time CTR1 */
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTimeNormal1;
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTimeAlternate1;
#endif
#if (ADC_CTR2_AVAILABLE == STD_ON)
    /**< @brief Conversion time CTR2 */
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTimeNormal2;
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTimeAlternate2;
#endif
    /**< @brief Resolution of the ADC hardware */
    CONST(Adc_ResolutionType, ADC_CONST) Res;
#ifdef ADC_WDG_SUPPORTED
    /**< @brief Maximum of Threshold registers configured. */
    CONST(uint8, ADC_CONST) ConfiguredThCount;
    /**< @brief Pointer to Threshold registers configuration. */
    P2CONST(Adc_Adcdig_ThresholdConfigurationType, ADC_VAR, ADC_APPL_CONST) pThConfigured;
#endif /* ADC_WDG_SUPPORTED */
} Adc_Adcdig_HwUnitConfigurationType;

/**
* @brief          Structure for group configuration.
*
*/
typedef struct
{
    CONST(Adc_HwUnitType, ADC_CONST) HwUnit;                                /**< @brief Hw unit to which the group belongs to */
    CONST(Adc_GroupAccessModeType , ADC_CONST) eAccessMode;                 /**< @brief   Access Mode */
    CONST(Adc_GroupConvModeType , ADC_CONST) eMode;                         /**< @brief Conversion Mode (OneShot/Continuous) */
    CONST(Adc_GroupConvType , ADC_CONST) eType;                             /**< @brief Conversion type (Normal/Injected) */
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || defined(__DOXYGEN__)
    CONST(Adc_GroupPriorityType , ADC_CONST) Priority;                      /**< @brief Priority of group */
#endif /* (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE) || defined(__DOXYGEN__) */
    CONST(Adc_GroupReplacementType , ADC_CONST) eReplecementMode;           /**< @brief Replacement Mode */
    CONST(Adc_TriggerSourceType , ADC_CONST) eTriggerSource;                /**< @brief Hw/Sw trigger */
#if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__)
    #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || defined(__DOXYGEN__)
    CONST(Adc_MhtGroupType, ADC_CONST) IsMHTGroup;                          /**< @brief Inidicate the group type (Regular or MHT) */
    #endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || defined(__DOXYGEN__) */
    CONST(Adc_HwTriggerSignalType , ADC_CONST) eTriggerEdge;                /**< @brief Hardware trigger edge */
    P2CONST(Adc_HwTriggerTimerType, ADC_VAR, ADC_APPL_CONST) pHwResource;   /**< @brief Resource of the selected hw trigger */
    #if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || defined(__DOXYGEN__)
    CONST(Adc_HwTriggerTimerType, ADC_CONST) AssignedTriggerCount;          /**< @brief Number of trigger source assigned to the group */
    #endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || defined(__DOXYGEN__) */
#endif /* #if (STD_ON==ADC_HW_TRIGGER_API) || defined(__DOXYGEN__) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY) || defined(__DOXYGEN__)
    CONST(Adc_NotifyType , ADC_CONST) Notification;                         /**< @brief Pointer to notification function */
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) || defined(__DOXYGEN__) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
    CONST(Adc_NotifyType , ADC_CONST) ExtraNotification;                    /**< @brief Pointer to extra notification function */
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
    CONST(uint32, ADC_CONST) u32PrecisionChannel;                           /**< @brief ANP0_31, Precision configured channels */
#if (ADC_EXTENDED_CH_AVAILABLE == STD_ON)
    CONST(uint32, ADC_CONST) u32ExtendedChannel;                            /**< @brief ANS0_31 medium accuracy extended configured channels */
#endif
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
    CONST(uint32, ADC_CONST) u32ExternalChannel;                            /**< @brief ANX0_31 External configured channels */
#endif
    CONST(uint32, ADC_CONST) u32PrecisionPsr;                               /**< @brief Presampling for Precision channels */
#if (ADC_EXTENDED_CH_AVAILABLE == STD_ON)
    CONST(uint32, ADC_CONST) u32ExtendedPsr;                                /**< @brief Presampling for Extended channels */
#endif
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
    CONST(uint32, ADC_CONST) u32ExternalPsr;                                /**< @brief Presampling for External channels */
#endif
    CONST(uint32, ADC_CONST) u32Wer0;                                       /**< @brief Wer0 for precision channels */
#if (ADC_EXTENDED_CH_AVAILABLE == STD_ON)
    CONST(uint32, ADC_CONST) u32Wer1;                                       /**< @brief Wer1 for Extended(medi.accuracy channels) */
#endif
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
    CONST(uint32, ADC_CONST) u32Wer2;                                       /**< @brief Wer2 for External channels */
#endif
    P2P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA) pResultsBufferPtr; /**< @brief pointer to user result buffer array */
    CONST(Adc_StreamBufferModeType , ADC_CONST) eBufferMode;                /**< @brief Buffer Mode */
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API==STD_ON) || defined(__DOXYGEN__)
    CONST(Adc_GroupType, ADC_CONST) EnableChDisableChGroupIndex;            /**< @brief Group's index if it has the support to enable/disable channel */
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) || defined(__DOXYGEN__) */
    CONST(Adc_StreamNumSampleType , ADC_CONST) NumSamples;                  /**< @brief  Number of samples */
    P2CONST(Adc_GroupDefType , ADC_VAR, ADC_APPL_CONST) pAssignment;        /**< @brief Assigned channels to group */
    CONST(Adc_ChannelIndexType , ADC_CONST) AssignedChannelCount;           /**< @brief Number of channels */
    
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTime;                     /**< @brief Conversion time */
    #if (ADC_CTR1_AVAILABLE == STD_ON)
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTime1;                    /**< @brief Conversion time CTR1 */
    #endif
    #if (ADC_CTR2_AVAILABLE == STD_ON)
    CONST(Adc_ConversionTimeType , ADC_CONST) ConvTime2;                    /**< @brief Conversion time CTR2 */
    #endif
    
    #if (ADC_DUAL_CLOCK_MODE == STD_ON)
    CONST(Adc_ConversionTimeType , ADC_CONST) AltConvTime;                  /**< @brief Alternate Conversion time */
    #if (ADC_CTR1_AVAILABLE == STD_ON)
    CONST(Adc_ConversionTimeType , ADC_CONST) AltConvTime1;                 /**< @brief Alternate conversion time CTR1 */
    #endif
    #if (ADC_CTR2_AVAILABLE == STD_ON)
    CONST(Adc_ConversionTimeType , ADC_CONST) AltConvTime2;                 /**< @brief Alternate Conversion time CTR2 */
    #endif
    #endif /* if (ADC_DUAL_CLOCK_MODE == STD_ON) */
#endif /* if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)*/

    CONST(Adc_ChannelType , ADC_CONST) LastCh;                              /**< @brief Last channel configured */
    CONST(Adc_ChannelType , ADC_CONST) FirstCh;                             /**< @brief First channel configured */
    CONST(uint8 , ADC_CONST) u8AdcWithoutInterrupt;                         /**< @brief Enables or Disables the ADC and DMA interrupts */
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
    CONST(boolean , ADC_CONST) bAdcDoubleBuffering;                         /**< @brief Enables or Disables the ADC double buffering feature */
#endif
} Adc_GroupConfigurationType;

/**
* @brief          Miscellaneous configuration structure.
*
*/
typedef struct
{
    CONST(uint8 , ADC_CONST) u8Adc_DmaInterruptSoftware[ADC_MAX_HW_UNITS];                                /**< @brief DMA or Interrupt driven */
    CONST(Adc_HwUnitType , ADC_CONST) Adc_MaxHwCfg;                                     /**< @brief Number of the maximum hw units */
    CONST(Adc_GroupType , ADC_CONST) aAdc_Groups[ADC_MAX_HW_UNITS];                     /**< @brief   Number of groups configured for each unit */
    CONST(Adc_ChannelType , ADC_CONST) aAdc_Channels[ADC_MAX_HW_UNITS];                 /**< @brief Number of channels of the hw unit x */
    CONST(uint8 , ADC_CONST) au8Adc_DmaChannel[ADC_MAX_HW_UNITS];                       /**< @brief If dma driven then indicates the dma channel number for HW UNITS */
    CONST(uint8 , ADC_CONST) au8Adc_HwUnit[ADC_MAX_HW_UNITS];                           /**< @brief If unit x is active STD_ON/STD_OFF */
    CONST(Adc_QueueIndexType , ADC_CONST) aAdc_HwQueueMaxDepth[ADC_MAX_HW_UNITS];       /**< @brief Maximum depth of the hw queue for each unit */
    CONST(Adc_HwUnitType, ADC_CONST) aHwLogicalId[ADC_MAX_HW_UNITS];                   /**< Hardware index in the structure */
} Adc_Adcdig_MultiConfigType;

/**
* @brief          Miscellaneous configuration structure.
*
*/
typedef struct
{
    CONST(uint8 , ADC_CONST) au8Adc_CeocfrPresent[ADC_MAX_HW_UNITS][ADC_CEOCFR_REGS];   /**< @brief CEOCFR registers working for each unit */
    CONST(uint8 , ADC_CONST) au8Adc_DmarPresent[ADC_MAX_HW_UNITS][ADC_DMAR_REGS];       /**< @brief DMAR registers working for each unit */
    CONST(uint8 , ADC_CONST) au8Adc_PsrPresent[ADC_MAX_HW_UNITS][ADC_PSR_REGS];         /**< @brief PSR registers working for each unit */
    CONST(uint8 , ADC_CONST) au8Adc_CtrPresent[ADC_MAX_HW_UNITS][ADC_CTR_REGS];         /**< @brief CTR registers working for each unit */
    CONST(uint8 , ADC_CONST) au8Adc_NcmrPresent[ADC_MAX_HW_UNITS][ADC_NCMR_REGS];       /**< @brief NCMR registers working for each unit */
    CONST(uint8 , ADC_CONST) au8Adc_JcmrPresent[ADC_MAX_HW_UNITS][ADC_JCMR_REGS];       /**< @brief JCMR registers working for each unit */
#if (ADC_DSDR_AVAILABLE == STD_ON)
    CONST(uint8 , ADC_CONST) au8Adc_DsdrPresent[ADC_MAX_HW_UNITS];                      /**< @brief DSDR registers working for each unit */
#endif /* ADC_DSDR_AVAILABLE == STD_ON */
    CONST(uint8 , ADC_CONST) au8Adc_CwselrPresent[ADC_MAX_HW_UNITS][ADC_CWSELR_REGS];   /**< @brief CWSELR registers working for each unit */
    CONST(uint8 , ADC_CONST) au8Adc_CwenrPresent[ADC_MAX_HW_UNITS][ADC_CWENR_REGS];     /**< @brief CWENR registers working for each unit */
    CONST(uint8 , ADC_CONST) au8Adc_AworrPresent[ADC_MAX_HW_UNITS][ADC_AWORR_REGS];     /**< @brief AWORR registers working for each unit */
    CONST(uint8 , ADC_CONST) au8Adc_ThrhlrPresent[ADC_MAX_HW_UNITS][ADC_THRHLR_REGS];   /**< @brief THRHLR registers working for each unit */
} Adc_Adcdig_RegisterAvailabilityType;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_Adcdig_CfgEx_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#if (ADC_SETCHANNEL_API == STD_ON)
extern VAR(Adc_RuntimeGroupChannelType, ADC_VAR) Adc_aRuntimeGroupChannel[ADC_MAX_GROUPS];
#endif

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_Adcdig_CfgEx_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* ADC_ADCDIG_CFGEX_H */

/** @} */
