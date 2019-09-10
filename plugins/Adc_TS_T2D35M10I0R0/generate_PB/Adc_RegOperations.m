[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ADC_REGOPERATIONS_M'))"!]
[!VAR "ADC_REGOPERATIONS_M"="'true'"!]
[!NOCODE!][!//

/**
*   @file    Adc_RegOperations.m
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - version check macro.
*   @details Version checks.
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

[!ENDNOCODE!][!//
[!AUTOSPACING!]

[!MACRO "HWRESOURCE" , "SOURCE"!][!//
  [!NOCODE!]            
      [!IF "contains($SOURCE,'BCTU_EMIOS0')"!]
          [!CODE!][!"num:i(substring-after($SOURCE, 'BCTU_EMIOS0_'))"!][!ENDCODE!]
      [!ELSEIF "contains($SOURCE,'BCTU_EMIOS1')"!]
          [!CODE!][!"num:i(substring-after($SOURCE, 'BCTU_EMIOS1_')) + 32"!][!ENDCODE!]
      [!ELSEIF "contains($SOURCE,'BCTU_EMIOS2')"!]
          [!CODE!][!"num:i(substring-after($SOURCE, 'BCTU_EMIOS2_')) + 64"!][!ENDCODE!]
      [!ELSEIF "contains($SOURCE,'BCTU_PIT_3')"!] 
          [!CODE!][!"23"!][!ENDCODE!]
      [!ELSEIF "contains($SOURCE,'BCTU_PIT_7')"!] 
          [!CODE!][!"55"!][!ENDCODE!]
      [!ELSEIF "contains($SOURCE,'BCTU_PIT_8')"!] 
          [!CODE!][!"87"!][!ENDCODE!]
      [!ELSEIF "contains($SOURCE,'PIT_2')"!] 
          [!CODE!][!"101"!][!ENDCODE!]
      [!ELSEIF "contains($SOURCE,'PIT_6')"!] 
          [!CODE!][!"102"!][!ENDCODE!]
      [!ENDIF!]
  [!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "Adc_Group_Define"!][!//
/**
* @brief          Total number of groups in Config.
*
*/
#define ADC_GROUPS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]           [!"num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*))"!]
[!ENDMACRO!]
    
[!MACRO "Adc_Notification_Config"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "node:exists(AdcNotification) and (AdcNotification != 'NULL_PTR')"!][!//
/**
* @brief         ADC Notification functions.
* @details       ADC Nofification functions defined inside the Plugin.
*
*/
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!][!//
[!IF "(../../../../../AdcGeneral/AdcGrpNotifCapability = 'true') and (node:exists(AdcNotification))"!][!//
[!IF "node:exists(AdcNotification) and (AdcNotification != 'NULL_PTR')"!][!//
[!IF "text:uniq(../../../../../../AdcConfigSet/AdcHwUnit/*/AdcGroup/*[AdcGroupId <= $x]/AdcNotification, ./AdcNotification)"!][!//
extern void [!"AdcNotification"!](void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!IF "node:exists(AdcExtraNotification) and (AdcExtraNotification != 'NULL_PTR')"!][!//
[!IF "text:uniq(../../../../../../AdcConfigSet/AdcHwUnit/*/AdcGroup/*[AdcGroupId <= $x]/AdcExtraNotification, AdcExtraNotification)"!]
extern void [!"AdcExtraNotification"!](void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_WdgNotification_Config"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcChannel/*"!][!//
[!IF "AdcEnableThresholds = 'true'"!][!//
[!IF "AdcWdogNotification != 'NULL_PTR'"!][!//
/**
* @brief          Adc Watchdog notification functions.
* @details        Adc Watchdog notification functions defined inside the Plugin.
*
*/
[!BREAK!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcChannel/*"!][!//
[!IF "AdcEnableThresholds = 'true'"!][!//
[!IF "AdcWdogNotification != 'NULL_PTR'"!]
/**< @brief for Channel - [!"AdcLogicalChannelId"!] */
extern void [!"AdcWdogNotification"!](void);
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Group_Assignments"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
/**
* @brief          Group Assignments on ADC Hardware unit [!"$Unit"!][!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!][!ENDIF!].
*
*/
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!][!//
[!IF "../../AdcHwUnitId = concat('ADC',string($Unit))"!][!//
static CONST(Adc_ChannelType, ADC_CONST) Adc_Group[!"AdcGroupId"!]_Assignment_[!"$Unit"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!/*    
                                         */!][ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_GROUP_[!"AdcGroupId"!]_CHANNELS] =
{
[!VAR "MAX_COUNT" = "count(AdcGroupDefinition/*)-1"!][!//
[!VAR "CRT_COUNT" = "0"!][!//
[!LOOP "AdcGroupDefinition/*"!][!//
[!VAR "CurrAdcChannel" = "."!][!//
[!VAR "CurrAdcChannel1" = "substring-after(substring-after(substring-after(substring-after(substring-after($CurrAdcChannel,'/'),'/'),'/'),'/'),'/')"!][!//
[!VAR "INDEX" = "0"!][!//
[!LOOP "../../../../AdcChannel/*"!][!//
[!IF "@name = $CurrAdcChannel1"!][!//
    [!"AdcLogicalChannelId"!]U[!IF "$CRT_COUNT < $MAX_COUNT"!],[!ELSE!][!ENDIF!]
[!ENDIF!][!//
[!VAR "INDEX" = "$INDEX + 1"!][!//
[!ENDLOOP!][!//
[!VAR "CRT_COUNT" = "$CRT_COUNT + 1"!][!//
[!ENDLOOP!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_ResultBuffer_Config", "Type"!][!//
/**
* @brief          Adc Result Buffer RAM initializations.
* @details        Array for all ADC group result ram buffers.
*/
[!VAR "MAX_NUM"="count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)"!][!//
[!VAR "CRT_NUM"="1"!][!//
static P2VAR(Adc_ValueGroupType, ADC_VAR, ADC_APPL_DATA) Adc_ResultsBufferPtr[] =
{
[!FOR "x" = "1" TO "$MAX_NUM"!][!//
    NULL_PTR[!IF "$CRT_NUM<$MAX_NUM"!],[!ELSE!][!ENDIF!]
[!VAR "CRT_NUM"="$CRT_NUM+1"!][!//
[!ENDFOR!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_Channel_Pointer_Config", "Type"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
/**
* @brief          Definition of channels's pointer structure [!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!] [!ENDIF!] Configuration.
*
*/
static P2CONST(Adc_Adcdig_ChannelConfigurationType, ADC_VAR, ADC_APPL_CONST) Adc_ChannelsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcHwUnitId = concat('ADC',string($Unit))"!][!//
[!VAR "UnitExits"="$UnitExits+1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 0"!][!//
    NULL_PTR[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ELSE!][!//
    Adc_ChannelsCfg_[!"$Unit"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDFOR!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_Channel_LimitChecking_Pointer_Config"!][!//
[!VAR "maxUnit"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of channels' limit checking pointer structure.
*
*/
P2CONST(Adc_Adcdig_ChannelLimitCheckingType, ADC_VAR, ADC_APPL_CONST) Adc_ChannelsLimitCheckingCfg[]=
{
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcLogicalUnitId = $Unit"!][!//
    Adc_ChannelsLimitCheckingCfg_[!"$Unit"!][!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//
};
#endif
[!ENDMACRO!][!//

[!MACRO "Adc_WdgThreshold_Config"!][!//
[!NOCODE!][!//
/** 
* @brief           Lookup for WDG functionality activation.
*/
[!VAR "WDG_FUNCTIONALITY_FOUND" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcChannel/*"!][!//
[!IF "AdcEnableThresholds = 'true'"!][!//
[!VAR "WDG_FUNCTIONALITY_FOUND" = "1"!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!IF "$WDG_FUNCTIONALITY_FOUND = 1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!VAR "WdgEnabled" = "0"!][!//
[!LOOP "AdcChannel/*"!][!//
[!IF "AdcEnableThresholds = 'true'"!][!//
[!VAR "WdgEnabled" = "1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "num:i($WdgEnabled) = '1'"!][!//
/**
* @brief          Definition of watchdog threshold control for [!"AdcHwUnitId"!] in configuration variant [!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].
*
*/
static CONST(Adc_Adcdig_ThresholdConfigurationType, ADC_CONST) Adc_ThresholdCfg_[!"AdcHwUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!VAR "Count" = "1"!][!//
[!LOOP "AdcThresholdControl/*"!][!//
    {
        /**< @brief Threshold register */
        [!"AdcThresholdControlRegister"!]_U8,
        /**< @brief Threshold value */
        ADCDIG_LOW_TH_VALUE_U32([!"AdcLowThreshold"!])|ADCDIG_HIGH_TH_VALUE_U32((uint32)[!"AdcHighThreshold"!])
    }[!IF "$Count < count(../*)"!],[!ENDIF!]
[!VAR "Count" = "$Count + 1"!][!//
[!ENDLOOP!][!//
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
        
/**
* @brief          Definition of ADC Hw units for Configuration variant [!IF "var:defined('postBuildVariant')"!] [!"$postBuildVariant"!][!ENDIF!].
*/
static CONST(Adc_Adcdig_HwUnitConfigurationType, ADC_CONST) Adc_HwUnitCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!VAR "MAX_COUNT"="count(AdcConfigSet/AdcHwUnit/*) - 1"!][!//
[!VAR "CRT_COUNT"="0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!CODE!][!//
    /**< @brief Hardware Unit [!"AdcHwUnitId"!] */
    {
        /**< @brief Hardware unit id*/
        (Adc_HwUnitType)[!"substring-after(string(AdcHwUnitId),'ADC')"!],
        /**< @brief Main configuration for control register */
        ([!IF "AdcAutoClockOff = 'true'"!]ADCDIG_AUTO_CLKOFF_EN_U32[!ELSE!]ADCDIG_AUTO_CLKOFF_DIS_U32[!ENDIF!] | ADCDIG_OVERWRITE_EN_U32 | [!IF "../../../AdcGeneral/AdcResultAlignment = 'ADC_ALIGN_RIGHT'"!]ADCDIG_WRITE_RIGHT_ALIGNED_U32[!ELSE!]ADCDIG_WRITE_LEFT_ALIGNED_U32[!ENDIF!]),
        /**< @brief Prescaler of normal mode */
[!IF "node:exists(AdcPrescale)"!][!//
        (ADCDIG_CLOCK_PRESCALER_DIV[!"num:i(AdcPrescale)"!]_U32),
[!ELSE!][!//
        (ADCDIG_CLOCK_PRESCALER_DIV1_U32),
[!ENDIF!][!//
        /**< @brief Power down delay */
        (ADCDIG_POWERDOWN_EXIT_DELAY_VALUE_U8([!"num:i(AdcPowerDownDelay)"!])),
[!IF "(../../../NonAutosar/AdcEnableDualClockMode)"!][!//
        /**< @brief Prescaler of alternate mode */
        (ADCDIG_CLOCK_PRESCALER_DIV[!"num:i(AdcAltPrescale)"!]_U32),
        /**< @brief Alternate Power down exit delay when ADC runs on low power system frequency */
        (ADCDIG_POWERDOWN_EXIT_DELAY_VALUE_U8([!"num:i(AdcAltPowerDownDelay)"!])),
[!ENDIF!][!//
        /**< @brief Mux delay value */
        (ADCDIG_MUX_DELAY_VALUE_U8((uint8)[!"num:i(AdcMuxDelay)"!])),
[!IF "AdcPresamplingInternalSignal0 = 'VSS_HV' "!][!//
        /**< @brief VSS_HV */
        (uint8)0x0,
[!ELSEIF "AdcPresamplingInternalSignal0 = 'VDD_HV' "!][!//
        /**< @brief VDD_HV */
        (uint8)0x1,
[!ELSEIF "AdcPresamplingInternalSignal0 = 'VREFL' "!][!//
        /**< @brief VREFL */
        (uint8)0x2,
[!ELSE!][!//
        /**< @brief VDD_HV_REF_ADC1 */
        (uint8)0x3,
[!ENDIF!][!//
[!IF "AdcPresamplingInternalSignal1 = 'VSS_HV' "!][!//
        /**< @brief VSS_HV */
        (uint8)0x0,
[!ELSEIF "AdcPresamplingInternalSignal1 = 'VDD_HV' "!][!//
        /**< @brief VDD_HV */
        (uint8)0x1,
[!ELSEIF "AdcPresamplingInternalSignal1 = 'VREFL' "!][!//
        /**< @brief VREFL */
        (uint8)0x2,
[!ELSE!][!//
        /**< @brief VDD_HV_REF_ADC1 */
        (uint8)0x3,
[!ENDIF!][!//
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
[!IF "AdcPresamplingInternalSignal2 = 'VSS_HV' "!][!//
        /**< @brief VSS_HV */
        (uint8)0x0,
[!ELSEIF "AdcPresamplingInternalSignal2 = 'VDD_HV' "!][!//
        /**< @brief VDD_HV */
        (uint8)0x1,
[!ELSEIF "AdcPresamplingInternalSignal2 = 'VREFL' "!][!//
        /**< @brief VREFL */
        (uint8)0x2,
[!ELSE!][!//
        /**< @brief VDD_HV_REF_ADC1 */
        (uint8)0x3,
[!ENDIF!][!//
#endif
[!IF "AdcBypassSampling = 'true'"!][!//
        /**< @brief Bypass the sampling phase */
        (uint8)0x1,
[!ELSE!][!//
        /**< @brief do not bypass the sampling phase */
        (uint8)0x0,
[!ENDIF!][!//
[!IF "((../../../NonAutosar/AdcEnableDualClockMode = 'true') or (../../../NonAutosar/AdcConvTimeOnce = 'true')) and (node:exists(AdcNormalConvTimings))"!][!//
        /**< @brief Normal Conversion time - CTR0 */
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcNormalConvTimings/AdcSamplingDurationNormal)"!])),
[!ELSE!][!//
        (Adc_ConversionTimeType)0x8,
[!ENDIF!][!//
[!IF "(../../../NonAutosar/AdcEnableDualClockMode = 'true') and (node:exists(AdcAlternateConvTimings))"!][!//
        /**< @brief Alternate Conversion time - CTR0 */
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcAlternateConvTimings/AdcSamplingDurationAlt)"!])),
[!ELSE!][!//
        (Adc_ConversionTimeType)0x8,
[!ENDIF!][!//
[!IF "((../../../NonAutosar/AdcEnableDualClockMode = 'true') or (../../../NonAutosar/AdcConvTimeOnce = 'true')) and (node:exists(AdcNormalConvTimings))"!][!//
        /**< @brief Normal Conversion time - CTR1 */
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcNormalConvTimings/AdcSamplingDurationNormal1)"!])),
[!ELSE!][!//
        (Adc_ConversionTimeType)0x8,
[!ENDIF!][!//
[!IF "(../../../NonAutosar/AdcEnableDualClockMode = 'true') and (node:exists(AdcAlternateConvTimings))"!][!// 
        /**< @brief Alternate Conversion time - CTR1 */
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcAlternateConvTimings/AdcSamplingDurationAlt1)"!])),
[!ELSE!][!//
        (Adc_ConversionTimeType)0x8,
[!ENDIF!][!//
#if (ADC_CTR2_AVAILABLE == STD_ON)
[!IF "((../../../NonAutosar/AdcEnableDualClockMode = 'true') or (../../../NonAutosar/AdcConvTimeOnce = 'true')) and (node:exists(AdcNormalConvTimings))"!][!//
        /**< @brief Normal Conversion time - CTR2 */
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcNormalConvTimings/AdcSamplingDurationNormal2)"!])),
[!ELSE!][!//
        (Adc_ConversionTimeType)0x8,
[!ENDIF!][!//
[!IF "(../../../NonAutosar/AdcEnableDualClockMode = 'true') and (node:exists(AdcAlternateConvTimings))"!][!//
        /**< @brief Alternate Conversion time - CTR2 */
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcAlternateConvTimings/AdcSamplingDurationAlt2)"!])),
[!ELSE!][!//
        (Adc_ConversionTimeType)0x8,
[!ENDIF!][!//
#endif /* ADC_CTR2_AVAILABLE == STD_ON */
        /**< @brief Adc bit resolution. */
        (Adc_ResolutionType)ADC_BITS_RESOLUTION_[!IF "AdcHwUnitId = 'ADC0'"!]10[!ELSE!]12[!ENDIF!]_U8
[!IF "../../../NonAutosar/AdcEnableWatchdogFunctionality  = 'true'"!],
[!VAR "WdgEnabled" = "0"!][!//
[!LOOP "AdcChannel/*"!][!//
[!IF "AdcEnableThresholds = 'true'"!][!//
[!VAR "WdgEnabled" = "1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "num:i($WdgEnabled) = '1'"!][!//
        /**< @brief Maximum of Threshold registers configured. */
        (uint8)[!"num:i(count(AdcThresholdControl/*))"!]U,
        /**< @brief Threshold registers configuration. */
        Adc_ThresholdCfg_[!"AdcHwUnitId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!ELSE!][!//
        /**< @brief Maximum of Threshold registers configured. */
        0U,
        /**< @brief Threshold registers configuration. */
        NULL_PTR
[!ENDIF!][!//
[!ENDIF!]
    }[!IF "$CRT_COUNT<$MAX_COUNT"!],[!ELSE!][!ENDIF!]
[!VAR "CRT_COUNT"="$CRT_COUNT+1"!][!//
[!ENDCODE!][!//
[!ENDLOOP!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_Channel_Config"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
[!VAR "LoopVar"="0"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcHwUnitId = concat('ADC',string($Unit))"!][!//
[!VAR "UnitExits"="$UnitExits+1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 1"!][!//
[!VAR "LoopVar"="0"!][!//
/**
* @brief          Definition of channels on ADC Hardware unit for configuration variant [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
* @details        Array of conversion command messages
*/
static CONST(Adc_Adcdig_ChannelConfigurationType, ADC_CONST) Adc_ChannelsCfg_[!"$Unit"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!VAR "numChannel" = "num:i(count(AdcConfigSet/AdcHwUnit/*[AdcHwUnitId=concat('ADC',string($Unit))]/AdcChannel/*)-1)"!][!//
[!FOR "x" = "0" TO "$numChannel"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*[AdcHwUnitId=concat('ADC',string($Unit))]/AdcChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "../../AdcHwUnitId = concat('ADC',string($Unit))"!][!//
[!IF "AdcLogicalChannelId = $Loop"!][!//
    /**< @brief Hardware Unit [!"../../AdcHwUnitId"!]  --  [!"AdcChannelId"!] */
    {
[!NOCODE!][!//
    [!VAR "ChannelId"="num:i(substring-after(AdcChannelId,'AN_'))"!]
[!ENDNOCODE!][!//    
        /**< @brief Adc physical channel */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8([!"$ChannelId"!])),
#ifdef ADC_WDG_SUPPORTED
[!IF "AdcEnableThresholds = 'true' and node:exists(AdcThresholdRegister)"!][!//
        /**< @brief Threshold register configured */
        [!"node:ref(AdcThresholdRegister)/AdcThresholdControlRegister"!]_U8,
[!ELSE!][!//
        /**< @brief Threshold register configured */
        ADC_UNUSED_THRESHOLD_U8,
[!ENDIF!][!//
[!IF "AdcEnableThresholds = 'true'"!][!//
[!IF "AdcWdogNotification != 'NULL_PTR'"!][!//
        /**< @brief Channel WDOG Notification function pointer */
        &[!"AdcWdogNotification"!],
[!ELSE!][!//
        /**< @brief No WDOG notification */
        NULL_PTR,
[!ENDIF!][!//
[!ELSE!][!//
        /**< @brief No WDOG notification */
        NULL_PTR,
[!ENDIF!][!//
        /**< @brief Channel descriptions for the WDG interrupts */
        (uint8)[!"num:i($ChannelId div 32)"!],
        /**< @brief Channel descriptions Mask for the WDG interrupts */
        (uint32)[!"num:inttohex(bit:shl(1, num:i($ChannelId mod 32)), 8)"!]U,
#endif /* ADC_WDG_SUPPORTED */
[!IF "AdcEnablePresampling ='true' "!][!//
        /**< @brief presampling enabled */
        (uint8)0x1
[!ELSE!][!//
        /**< @brief presampling disabled */
        (uint8)0x0
[!ENDIF!][!//
    }[!IF "$x < $numChannel"!],[!ELSE!][!ENDIF!]
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
};
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Channel_LimitChecking_Config"!][!//
[!VAR "maxUnit"="num:i(count(AdcConfigSet/AdcHwUnit/*)-1)"!][!//
[!VAR "LoopVar"="0"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
[!IF "AdcLogicalUnitId = $Unit"!][!//
[!VAR "UnitExits"="$UnitExits+1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 1"!][!//
[!VAR "LoopVar"="0"!][!//
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Definition of channels limit checking on ADC logical unit [!"$Unit"!].
*/
static CONST(Adc_Adcdig_ChannelLimitCheckingType, ADC_CONST) Adc_ChannelsLimitCheckingCfg_[!"$Unit"!][] =
{
[!VAR "numChannel" = "num:i(count(AdcConfigSet/AdcHwUnit/*[AdcLogicalUnitId=$Unit]/AdcChannel/*)-1)"!][!//
[!FOR "x" = "0" TO "$numChannel"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*[AdcLogicalUnitId=$Unit]/AdcChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "AdcLogicalChannelId = $Loop"!][!//
    /**< @brief ADC logical Id [!"$Unit"!]  --  Channel logical Id [!"AdcLogicalChannelId"!] */
    {
[!IF "node:exists(AdcChannelLimitCheck) and AdcChannelLimitCheck ='true'"!][!//
        /**< @brief limit check enabled */
        (boolean)TRUE,
        /**< @brief range for limit check */
[!IF "node:exists(AdcChannelRangeSelect)"!][!//
        (Adc_ChannelRangeSelectType)[!"AdcChannelRangeSelect"!],
[!ELSE!][!//
        (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
[!ENDIF!][!//
        /**< @brief high limit value */
[!IF "node:exists(AdcChannelHighLimit)"!][!//
        (Adc_ValueGroupType)[!"num:i(AdcChannelHighLimit)"!],
[!ELSE!][!//
        (Adc_ValueGroupType)0,
[!ENDIF!][!//
        /**< @brief low limit value */
[!IF "node:exists(AdcChannelLowLimit)"!][!//
        (Adc_ValueGroupType)[!"num:i(AdcChannelLowLimit)"!]
[!ELSE!][!//
        (Adc_ValueGroupType)0,
[!ENDIF!][!//
[!ELSE!][!//
        /**< @brief limit check disabled */
        (boolean)FALSE,
        /**< @brief range for limit check */
        (Adc_ChannelRangeSelectType)ADC_RANGE_ALWAYS,
        /**< @brief high limit value */
        (Adc_ValueGroupType)0,
        /**< @brief low limit value */
        (Adc_ValueGroupType)0
[!ENDIF!][!//
    }[!IF "$x < $numChannel"!],[!ELSE!][!ENDIF!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
};
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_HwTriggerSource_Config"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW'"!][!//
[!VAR "HWNUM" ="num:i(count(AdcHwTrig/*))"!][!//
/**
* @brief          Hardware trigger sources configured for group [!"AdcGroupId"!] - for configuration variant [!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
* 
*/
static CONST(Adc_HwTriggerTimerType, ADC_CONST) Adc_GroupTriggerSource[!"AdcGroupId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!VAR "INTINDEX" = "0"!][!//
[!LOOP "AdcHwTrig/*"!][!//
[!NOCODE!][!//
[!VAR "HwTrgSrc" = "AdcHwTrigSrc"!]
[!VAR "HWRES"!][!CALL "HWRESOURCE" , "SOURCE" = "$HwTrgSrc"!][!ENDVAR!]
[!ENDNOCODE!][!//
    (Adc_HwTriggerTimerType)[!"num:i(number($HWRES))"!]U[!IF "$INTINDEX < ($HWNUM - 1)"!],[!ENDIF!]
[!VAR "INTINDEX"="$INTINDEX + 1"!][!//
[!ENDLOOP!][!//
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Group_Config"!][!//
[!NOCODE!][!//
/**
* @brief          Definition of Precise PSR.
*/
[!VAR "AdcPrecisePsr"="0"!][!//
[!VAR "AdcExtdPsr" = "0"!][!//
[!VAR "AdcExternalPsr" = "0"!][!//
[!VAR "CurrAdcChannel" = "0"!][!//
[!VAR "CurrAdcChannel1" = "0"!][!//
[!VAR "AdcTemp_Ch" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!LOOP "AdcGroupDefinition/*"!][!//
[!VAR "CurrAdcChannel" = "."!][!//
[!VAR "CurrAdcChannel1" = "substring-after(substring-after(substring-after(substring-after(substring-after($CurrAdcChannel,'/'),'/'),'/'),'/'),'/')"!]
[!LOOP "../../../../AdcChannel/*"!][!//
[!IF "$CurrAdcChannel1 = @name"!][!//
[!IF "contains(AdcChannelId,'AN_')"!][!//
[!VAR "AdcTemp_Ch" = "substring-after(AdcChannelId,'AN_')"!][!//
[!IF "$AdcTemp_Ch < 32"!]
[!VAR "AdcTemp_Ch" = "bit:shl(1,$AdcTemp_Ch)"!][!//
[!IF "AdcEnablePresampling"!][!//
[!VAR "AdcPrecisePsr" = "bit:or($AdcPrecisePsr,$AdcTemp_Ch)"!][!//
[!ENDIF!][!//
[!ELSEIF "$AdcTemp_Ch < 64"!][!//
[!VAR "AdcTemp_Ch" = "bit:shl(1,($AdcTemp_Ch) - 32)"!][!//
[!IF "AdcEnablePresampling"!]
[!VAR "AdcExtdPsr" = "bit:or($AdcExtdPsr,$AdcTemp_Ch)"!][!//
[!ENDIF!][!//
[!ELSEIF "$AdcTemp_Ch < 96"!][!//
[!VAR "AdcTemp_Ch" = "bit:shl(1,($AdcTemp_Ch) - 64)"!][!//
[!IF "AdcEnablePresampling"!][!//
[!VAR "AdcExternalPsr" = "bit:or($AdcExternalPsr,$AdcTemp_Ch)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "EnableCHDisableCHIndex" ="0"!][!//
/**
* @brief          Definition of all ADC groups for configuration varaint [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
static CONST(Adc_GroupConfigurationType, ADC_CONST) Adc_GroupsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!VAR "numGroup" = "num:i(count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1)"!][!//
[!FOR "x" = "0" TO "num:i($numGroup)"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "AdcGroupId = $Loop"!][!//
[!NOCODE!][!//
[!VAR "AdcTemp_Ch" = "0"!]
[!VAR "AdcPrecise_Ch" = "0"!]
[!VAR "AdcExtd_Ch" = "0"!]
[!VAR "AdcExternal_Ch" = "0"!]
[!VAR "AdcPrecise_Psr" = "0"!]
[!VAR "AdcExtd_Psr" = "0"!]
[!VAR "AdcExternal_Psr" = "0"!]
[!VAR "AdcWer0" = "0"!]
[!VAR "AdcWer1" = "0"!]
[!VAR "AdcWer2" = "0"!]
[!VAR "FirstDmaCh" = "0"!]
[!VAR "LastDmaCh" = "0"!]
[!VAR "MaxAdcChVal" = "0"!]
[!VAR "MinAdcChVal" = "255"!]

[!LOOP "AdcGroupDefinition/*"!]
    [!VAR "CurrAdcChannel" = "."!]
    [!VAR "CurrAdcChannel1" = "substring-after(substring-after(substring-after(substring-after(substring-after($CurrAdcChannel,'/'),'/'),'/'),'/'),'/')"!]
[!LOOP "../../../../AdcChannel/*"!]
[!IF "$CurrAdcChannel1 = @name"!]

[!IF "contains(AdcChannelId,'AN_')"!][!//
[!VAR "AdcTemp_Ch" = "substring-after(AdcChannelId,'AN_')"!][!//

[!IF "$AdcTemp_Ch > $MaxAdcChVal"!]
[!VAR "MaxAdcChVal" = "$AdcTemp_Ch"!]
[!ENDIF!]
[!IF "$AdcTemp_Ch < $MinAdcChVal"!]
[!VAR "MinAdcChVal" = "$AdcTemp_Ch"!]
[!ENDIF!]

[!IF "$AdcTemp_Ch < 32"!]
[!VAR "AdcTemp_Ch" = "bit:shl(1,$AdcTemp_Ch)"!]
[!VAR "AdcPrecise_Ch" = "bit:or($AdcPrecise_Ch,$AdcTemp_Ch)"!]
[!IF "AdcEnablePresampling"!]
[!VAR "AdcPrecise_Psr" = "bit:or($AdcPrecise_Psr,$AdcTemp_Ch)"!]
[!ENDIF!]
[!IF "AdcEnableThresholds"!]
[!VAR "AdcWer0" = "bit:or($AdcWer0,$AdcTemp_Ch)"!]
[!ENDIF!]

[!ELSEIF "$AdcTemp_Ch < 64"!]
[!VAR "AdcTemp_Ch" = "bit:shl(1,($AdcTemp_Ch) - 32)"!]
[!VAR "AdcExtd_Ch" = "bit:or($AdcExtd_Ch,$AdcTemp_Ch)"!]
[!IF "AdcEnablePresampling"!]
[!VAR "AdcExtd_Psr" = "bit:or($AdcExtd_Psr,$AdcTemp_Ch)"!]
[!ENDIF!]
[!IF "AdcEnableThresholds"!]
[!VAR "AdcWer1" = "bit:or($AdcWer1,$AdcTemp_Ch)"!]
[!ENDIF!]

[!ELSEIF "$AdcTemp_Ch < 96"!]
[!VAR "AdcTemp_Ch" = "bit:shl(1,($AdcTemp_Ch) - 64)"!]
[!VAR "AdcExternal_Ch" = "bit:or($AdcExternal_Ch,$AdcTemp_Ch)"!]
[!IF "AdcEnablePresampling"!]
[!VAR "AdcExternal_Psr" = "bit:or($AdcExternal_Psr,$AdcTemp_Ch)"!]
[!ENDIF!]
[!IF "AdcEnableThresholds"!]
[!VAR "AdcWer2" = "bit:or($AdcWer2,$AdcTemp_Ch)"!]
[!ENDIF!]

[!ENDIF!]
[!ENDIF!]
[!ENDIF!]
[!ENDLOOP!]
[!ENDLOOP!]

[!VAR "FirstDmaCh" = "$MinAdcChVal"!]
[!VAR "LastDmaCh" = "$MaxAdcChVal"!]
[!ENDNOCODE!][!//
    /**< @brief Group[!"AdcGroupId"!] -- Hardware Unit [!"../../AdcHwUnitId"!] */
    {
        /**< @brief Hardware unit configured */
        (Adc_HwUnitType)[!"substring-after(string(../../AdcHwUnitId),'ADC')"!],
        /**< @brief Access mode */
        [!"AdcGroupAccessMode"!],
        /**< @brief Conversion mode */
        [!"AdcGroupConversionMode"!],
        /**< @brief Conversion type */
        [!"AdcGroupConversionType"!],
#if (ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE)
        /**< @brief Priority configured */
        [!IF "(../../../../../AdcGeneral/AdcPriorityImplementation != 'ADC_PRIORITY_NONE') and (node:exists(AdcGroupPriority))"!]ADC_GROUP_PRIORITY([!"AdcGroupPriority"!]),[!ELSE!]ADC_GROUP_PRIORITY(0U),[!ENDIF!]
#endif /* ADC_PRIORITY_IMPLEMENTATION != ADC_PRIORITY_NONE */
        /**< @brief Replacement mode */
        ADC_GROUP_REPL_ABORT_RESTART,
        /**< @brief Trigger source configured */
        [!"AdcGroupTriggSrc"!],
#if (STD_ON==ADC_HW_TRIGGER_API)
#if (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS)
[!IF "AdcMultipleHardwareTriggerGroup"!][!//
        /**< @brief This is an MHT group */
        (Adc_MhtGroupType)ADC_MHT_GROUP_TYPE,
[!ELSE!][!//
        /**< @brief This a Regular Group */
        (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE,
[!ENDIF!][!//
#endif /* (STD_ON == ADC_MULTIPLE_HARDWARE_TRIGGERS) */
        /**< @brief Hardware trigger signal */
        [!IF "(../../../../../AdcGeneral/AdcHwTriggerApi = 'true') and (AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW') and (node:exists(AdcHwTrigSignal))"!][!"AdcHwTrigSignal"!],[!ELSE!]ADC_HW_TRIG_BOTH_EDGES,[!ENDIF!]
        /**< @brief Hardware resource for the group*/
        [!IF "(../../../../../AdcGeneral/AdcHwTriggerApi = 'true') and (AdcGroupTriggSrc = 'ADC_TRIGG_SRC_HW')"!]Adc_GroupTriggerSource[!"AdcGroupId"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!][!"num:i(0)"!]U,[!ENDIF!]
[!IF "(../../../../../NonAutosar/AdcEnableCtuTrigNonAutosarApi = 'true')"!][!//
        /**< @brief Number of trigger source assigned to the group */
        (Adc_HwTriggerTimerType)[!"num:i(count(AdcHwTrig/*))"!],
[!ENDIF!][!//
#endif /* (STD_ON==ADC_HW_TRIGGER_API) */
#if (STD_ON==ADC_GRP_NOTIF_CAPABILITY)
        /**< @brief Notification function */
[!IF "(../../../../../AdcGeneral/AdcGrpNotifCapability = 'true') and (node:exists(AdcNotification))"!][!//
        [!IF "AdcNotification != 'NULL_PTR'"!]&[!"AdcNotification"!],[!ELSE!][!"AdcNotification"!],[!ENDIF!]
[!ELSE!][!//
        NULL_PTR,
[!ENDIF!][!//
#endif /* (STD_ON==ADC_GRP_NOTIF_CAPABILITY) */
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
        /**< @brief Extra notification function */
[!IF "(../../../../../NonAutosar/AdcEnableInitialNotification = 'true')"!][!//
        [!IF "AdcExtraNotification != 'NULL_PTR'"!]&[!"AdcExtraNotification"!],[!ELSE!][!"AdcExtraNotification"!],[!ENDIF!]
[!ELSE!]
        NULL_PTR,
[!ENDIF!][!//
#endif /*(ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)*/
        /**< @brief Precision configured channels */
        (uint32)[!"num:inttohex($AdcPrecise_Ch)"!]U,
#if (ADC_EXTENDED_CH_AVAILABLE == STD_ON)
        /**< @brief Extended configured channels */
        (uint32)[!"num:inttohex($AdcExtd_Ch)"!]U,
#endif
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
        /**< @brief External configured channels */
        (uint32)[!"num:inttohex($AdcExternal_Ch)"!]U,
#endif
[!IF "(../../../../../NonAutosar/AdcPreSamplingOnce)"!][!//
        /**< @brief Presampling for Precision channels */
        (uint32)[!"num:inttohex($AdcPrecisePsr)"!]U,
#if (ADC_EXTENDED_CH_AVAILABLE == STD_ON)
        /**< @brief Presampling for Extended channels */
        (uint32)[!"num:inttohex($AdcExtdPsr)"!]U,
#endif
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
        /**< @brief Presampling for External channels */
        (uint32)[!"num:inttohex($AdcExternalPsr)"!]U,
#endif
[!ELSE!][!//
        /**< @brief Presampling for Precision channels */
        (uint32)[!"num:inttohex($AdcPrecise_Psr)"!]U,
#if (ADC_EXTENDED_CH_AVAILABLE == STD_ON)
        /**< @brief Presampling for Extended channels */
        (uint32)[!"num:inttohex($AdcExtd_Psr)"!]U,
#endif
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
        /**< @brief Presampling for External channels */
        (uint32)[!"num:inttohex($AdcExternal_Psr)"!]U,
#endif
[!ENDIF!][!//
        /**< @brief Wer0 for precision channels */
        (uint32)[!"num:inttohex($AdcWer0)"!]U,
#if (ADC_EXTENDED_CH_AVAILABLE == STD_ON)
        /**< @brief Wer1 for extended(medi.accuracy channels) */
        (uint32)[!"num:inttohex($AdcWer1)"!]U,
#endif
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
        /**< @brief Wer2 for external channels */
        (uint32)[!"num:inttohex($AdcWer2)"!]U,
#endif
        /**< @brief ADC Group Result Buffers RAM array */
        Adc_ResultsBufferPtr,
        /**< @brief Group Streaming Buffer Mode */
        [!"AdcStreamingBufferMode"!],
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /**< @brief Index of the group with AdcEnableChDisableChGroup enabled */
        (Adc_GroupType)[!IF "node:fallback(AdcEnableChDisableChGroup,'false') = 'true'"!][!"num:i($EnableCHDisableCHIndex)"!][!VAR "EnableCHDisableCHIndex" = "$EnableCHDisableCHIndex + 1"!][!ELSE!]ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX[!ENDIF!],
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
        /**< @brief Number of streaming samples */
        (Adc_StreamNumSampleType)ADC_STREAMING_NUM_SAMPLES([!"AdcStreamingNumSamples"!]),
        /**< @brief Channels assigned to the group*/
        Adc_Group[!"AdcGroupId"!]_Assignment_[!"num:i(substring-after(../../AdcHwUnitId, 'ADC'))"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        /**< @brief Number of channels in the group*/
        (Adc_ChannelIndexType)ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_GROUP_[!"AdcGroupId"!]_CHANNELS,   
[!IF "(../../../../../NonAutosar/AdcConvTimeOnce = 'false')"!][!//
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcGroupConversionConfiguration/AdcSamplingDuration)"!])),
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcGroupConversionConfiguration/AdcSamplingDuration1)"!])),
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcGroupConversionConfiguration/AdcSamplingDuration2)"!])),
[!IF "(../../../../../NonAutosar/AdcEnableDualClockMode = 'true')"!][!//
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcAlternateGroupConvTimings/AdcAltGroupSamplingDuration)"!])),
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcAlternateGroupConvTimings/AdcAltGroupSamplingDuration1)"!])),
        (Adc_ConversionTimeType)(ADCDIG_INPSAMP_VALUE_U32([!"num:i(AdcAlternateGroupConvTimings/AdcAltGroupSamplingDuration2)"!])),
[!ENDIF!][!//
[!ENDIF!][!//
        /**< @brief Last Channel configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8([!"num:i($LastDmaCh)"!])),
        /**< @brief First Channel Configured */
        (Adc_ChannelType)(ADC_ID_CHANNEL_U8([!"num:i($FirstDmaCh)"!])),
        /**< @brief Enables or Disables the ADC and DMA interrupts */
        (uint8)[!IF "AdcWithoutInterrupts"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
        ,
        /**< @brief Enables or Disables the ADC double buffering feature */
        (boolean)[!IF "AdcEnableDoubleBuffering"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!]
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
    }[!IF "$LoopVar < $numGroup"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_ETimeout_Config"!][!//
/** @violates @ref Adc_Cfg_c_REF_5 MISRA-C:2004 Rule 8.10: External linkage.*/
CONST(Mcal_DemErrorType, ADC_CONST) Adc_E_TimeoutCfg = 
{
[!IF "node:exists(AdcDemEventParameterRefs/ADC_E_TIMEOUT)"!][!//
    (uint32)STD_ON,
[!ELSE!][!//
    (uint32)STD_OFF,
[!ENDIF!][!//
[!IF "node:exists(AdcDemEventParameterRefs/ADC_E_TIMEOUT)"!][!//
    (uint16)DemConf_DemEventParameter_[!"node:ref(AdcDemEventParameterRefs/ADC_E_TIMEOUT)/@name"!]
[!ELSE!][!//
    (uint16)0U
[!ENDIF!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_Structure_Config"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
[!VAR "LoopVar"="0"!][!//
/**
* @brief          ADC driver Configuration structure [!IF "var:defined('postBuildVariant')"!][!"$postBuildVariant"!][!ENDIF!].
*/
/** @violates @ref Adc_PBcfg_c_REF_5 MISRA-C:2004 Rule 8.10: External linkage.*/
[!IF "(IMPLEMENTATION_CONFIG_VARIANT !='VariantPostBuild' and (variant:size()<=1))"!][!//
CONST(Adc_ConfigType, ADC_CONST) Adc_PBCfgVariantPredefined =
[!ELSE!][!//
CONST(Adc_ConfigType, ADC_CONST) [!"as:name(AdcConfigSet)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ENDIF!][!//
{
    /**< @brief pointer to Hw unit configurations */
    Adc_HwUnitCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /**< @brief pointer to group configurations */
    Adc_GroupsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /**< @brief pointer to channel configurations */
    Adc_ChannelsCfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /**< @brief total number of groups */
    (Adc_GroupType)ADC_GROUPS[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /**< @brief Miscellaneous configuration parameters. - Adc_Adcdig_MultiConfigType */
    {
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
            [!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId = concat('ADC',$Unit)"!][!"AdcConfigSet/AdcHwUnit/*/AdcHwUnitId[.=concat('ADC',$Unit)]/../AdcTransferType"!][!ELSE!]ADC_INTERRUPT[!ENDIF!][!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!]
        },
        /**< @brief number of the maximum hardware units in the current configuration */
        [!"num:i(count(AdcConfigSet/AdcHwUnit/*))"!]U,
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
            /**< @brief number of groups of the hw unit [!"$Unit"!] */
            (Adc_GroupType)[!"num:i(count(AdcConfigSet/AdcHwUnit/*/AdcHwUnitId[.=concat('ADC',$Unit)]/../AdcGroup/*))"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!][!//
        },
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
            /**< @brief number of channels of the ADC Hardware unit [!"$Unit"!] */
            (Adc_ChannelType)[!"num:i(count(AdcConfigSet/AdcHwUnit/*/AdcHwUnitId[.=concat('ADC',$Unit)]/../AdcChannel/*))"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!][!//
        },
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!NOCODE!][!//
[!VAR "DmaChannelId"="255"!]
[!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId = concat('ADC',$Unit)"!]
    [!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId[.=concat('ADC',$Unit)]/../AdcTransferType = 'ADC_DMA'"!]
        [!LOOP "node:refs('ASPathDataOfSchema:/TS_T2D35M10I0R0/Mcl')/MclConfigSet/*[1]/DMAChannel/*[MclDMAChannelEnable = 'true']"!]
            [!VAR "temp"="node:value(string(concat('DmaSource',string(num:i(num:i(substring-after(DmaHwChannel,'eDMA_')) div 16)))))"!][!//
            [!IF "$temp = concat('ADC_',$Unit)"!]
              [!VAR "DmaChannelId"="num:i(MclDMAChannelId)"!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//
            /** The DMA channel number for ADC [!"$Unit"!] */
            (uint8)[!"num:i($DmaChannelId)"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!][!//
        },
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
            /**< @brief ADC_UNIT_[!"$Unit"!] - ON/OFF */
            [!IF "AdcConfigSet/AdcHwUnit/*/AdcHwUnitId = concat('ADC',$Unit)"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!][!//
        },
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!NOCODE!][!//
[!VAR "mhtGroups_hw" = "0"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "../../AdcHwUnitId = concat('ADC',$Unit)"!][!//
[!IF "AdcMultipleHardwareTriggerGroup = 'true'"!][!//
[!VAR "mhtGroups_hw" = "$mhtGroups_hw + 1"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief number of MHT groups of the ADC Hardware unit [!"$Unit"!] */
            (uint8)[!"num:i($mhtGroups_hw)"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!]
        },
        {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!NOCODE!][!//
    [!VAR "LogicalUnit"="255"!][!//
    [!LOOP "AdcConfigSet/AdcHwUnit/*"!][!//
        [!IF "AdcHwUnitId = concat('ADC',string($Unit))"!][!//
            [!VAR "LogicalUnit" = "num:i(AdcLogicalUnitId)"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!CODE!][!//
            [!"num:i($LogicalUnit)"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDCODE!][!//
[!ENDFOR!][!//
        }
    }
[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
    ,
    /** @brief BCTU configuration */
    &Adc_BctuConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
[!ENDIF!][!//
};
[!ENDMACRO!][!//

[!MACRO "Adc_Registers_availability"!][!//

[!VAR "LoopVar"="0"!][!//
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
/**
* @brief          ADC Registers available for each unit .
*/
/** @violates @ref Adc_Cfg_c_REF_5 MISRA-C:2004 Rule 8.10: External linkage.*/
CONST(Adc_Adcdig_RegisterAvailabilityType, ADC_CONST) Adc_RegistersAvailable =
{
    /**< @brief ADC Registers available for each Unit. - Adc_Adcdig_RegisterAvailabilityType */
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_CEOCFR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfCEOCFReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_CEOCFR_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "CEOCFR_REG" = "concat('ADC_CEOCFR',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcCeocfrRegisters'))"!][!//
[!IF "$CEOCFR_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$CEOCFR_REG"!] available on unit ADC[!"$x"!] */
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_CEOCFR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_DMAR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfDMAReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_DMAR_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "DMAR_REG" = "concat('ADC_DMAR',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcDmarRegisters'))"!][!//
[!IF "$DMAR_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$DMAR_REG"!] available on unit ADC[!"$x"!] */
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_DMAR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_PSR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfPSReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_PSR_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "PSR_REG" = "concat('ADC_PSR',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcPsrRegisters'))"!][!//
[!IF "$PSR_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$PSR_REG"!] available on unit ADC[!"$x"!] */ 
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_PSR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_CTR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfCTReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_CTR_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "CRT_REG" = "concat('ADC_CTR',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcCtrRegisters'))"!][!//
[!IF "$CRT_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$CRT_REG"!] available on unit ADC[!"$x"!] */  
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_CTR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_NCMR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfNCMReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_NCMR_REGS -1"!][!//
[!NOCODE!][!//
   [!VAR "NCMR_REG" = "concat('ADC_NCMR',$y)"!][!//
   [!VAR "FOUND_REG" = "0"!][!//
   [!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcNcmrRegisters'))"!][!//
     [!IF "$NCMR_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
   [!ENDLOOP!][!//
  [!ENDNOCODE!][!//
            /**< @brief [!"$NCMR_REG"!] available on unit ADC[!"$x"!] */  
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_NCMR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_JCMR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfJCMReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_JCMR_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "JCMR_REG" = "concat('ADC_JCMR',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcJcmrRegisters'))"!][!//
[!IF "$JCMR_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$JCMR_REG"!] available on unit ADC[!"$x"!] */ 
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_JCMR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
[!NOCODE!][!//
[!VAR "DSDR_Found" = "0"!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
[!IF "ecu:get(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcDsdrRegPresent')) = 'TRUE'"!][!//
[!VAR "DSDR_Found" = "1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!ENDNOCODE!][!//
[!IF "$DSDR_Found = 1"!][!//
    {
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
[!NOCODE!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!IF "ecu:get(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcDsdrRegPresent')) = 'TRUE'"!][!//
[!VAR "FOUND_REG" = "1"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
            /**< @brief DSDR register available on unit ADC[!"$x"!] */ 
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
[!ENDIF!][!//
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_CWSEL_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfCWSELReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_CWSEL_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "CWSEL_REG" = "concat('ADC_CWSEL',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcCwselRegisters'))"!][!//
[!IF "$CWSEL_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$CWSEL_REG"!] available on unit ADC[!"$x"!] */ 
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_CWSEL_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_CWENR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfCWENReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_CWENR_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "CWENR_REG" = "concat('ADC_CWENR',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcCwenrRegisters'))"!][!//
[!IF "$CWENR_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$CWENR_REG"!] available on unit ADC[!"$x"!] */ 
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_CWENR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_AWORR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfAWORReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_AWORR_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "AWORR_REG" = "concat('ADC_AWORR',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcAworrRegisters'))"!][!//
[!IF "$AWORR_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$AWORR_REG"!] available on unit ADC[!"$x"!] */ 
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_AWORR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!NOCODE!][!//
[!VAR "NO_HW_UNITS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit')"!][!//
[!VAR "NO_THRHLR_REGS"="ecu:get('Adc.AdcConfigSet.AdcHwUnit.AdcNumberOfTHRHLReg')"!][!//
[!ENDNOCODE!][!//
[!FOR "x" = "0" TO "$NO_HW_UNITS -1"!][!//
        {
[!FOR "y" = "0" TO "$NO_THRHLR_REGS -1"!][!//
[!NOCODE!][!//
[!VAR "THRHLR_REG" = "concat('ADC_THRHLR',$y)"!][!//
[!VAR "FOUND_REG" = "0"!][!//
[!LOOP "ecu:list(concat(concat('Adc.AdcConfigSet.AdcHwUnit',string($x)),'.AdcThrhlrRegisters'))"!][!//
[!IF "$THRHLR_REG = node:current()"!][!VAR "FOUND_REG" = "1"!][!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
            /**< @brief [!"$THRHLR_REG"!] available on unit ADC[!"$x"!] */ 
            [!IF "$FOUND_REG = 1"!](uint8)STD_ON[!ELSE!](uint8)STD_OFF[!ENDIF!][!IF "$y < $NO_THRHLR_REGS -1"!], [!ENDIF!]
[!ENDFOR!][!//
        }[!IF "$x < $NO_HW_UNITS -1"!], [!ENDIF!]
[!ENDFOR!][!//
    }
};
[!ENDMACRO!]

[!MACRO "AdcExportDriverConfiguration"!]
[!NOCODE!][!//
[!VAR "configName" = "as:name(AdcConfigSet)"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!LOOP "variant:all()"!][!//
[!CODE!][!//
/** @violates @ref Adc_cfg_h_REF_3 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern CONST(Adc_ConfigType, ADC_CONST) [!"$configName"!]_[!"."!];
[!ENDCODE!][!//
    [!ENDLOOP!][!//
[!ELSE!][!//
[!CODE!][!//
/** @violates @ref Adc_cfg_h_REF_3 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern CONST(Adc_ConfigType, ADC_CONST) [!"$configName"!];
[!ENDCODE!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!ENDIF!]
