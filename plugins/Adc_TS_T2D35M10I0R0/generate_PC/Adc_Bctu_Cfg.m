[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('ADC_BCTU_CFG_M'))"!]
[!VAR "ADC_BCTU_CFG_M"="'true'"!]

[!NOCODE!][!//
/**
*   @file    Adc_Bctu_Cfg.m
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

[!MACRO "Adc_Bctu_Data_Buffer"!][!//
[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
/**
* @brief    The data buffers for BCTU.
* @details  Declarations of the BCTU destination buffers.
*/
[!VAR "maxUnit"="num:i(ecu:get('Adc.AdcConfigSet.AdcHwUnit'))-1"!][!//
[!LOOP "AdcConfigSet/BCTUHwUnit/*[1]/BCTU_InputTrigger/*"!][!//
[!VAR "numselected" = "0"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!LOOP "AdcChannelTriggered/*"!][!//
[!IF "ADCHWUNIT = concat('ADC',string($Unit))"!][!//
[!VAR "numselected" = "$numselected + 1"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!]

[!IF "./BCTUUserBuffer != 'NULL_PTR'"!][!//
[!IF "./BCTUMode = 'LIST_MODE'"!][!//
[!VAR "temp" = "count(./AdcChannelTriggered/*) div ($numselected)"!][!//
static VAR(Adc_Bctu_DataType, ADC_VAR) DataBuffer_[!"num:i(@index)"!][[!"num:i($numselected)"!]][[!"num:i($temp)"!]];
[!ELSE!][!//
static VAR(Adc_Bctu_DataType, ADC_VAR) DataBuffer_[!"num:i(@index)"!][[!"num:i($numselected)"!]][1];
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//


[!MACRO "Adc_Bctu_User_Buffer", "Type"!][!//
[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
/**
* @brief    The user buffers for BCTU.
* @details  Declarations of the BCTU destination buffers.
*/
[!LOOP "AdcConfigSet/BCTUHwUnit/*[1]/BCTU_InputTrigger/*"!][!//
[!IF "./BCTUUserBuffer != 'NULL_PTR'"!][!//
[!IF "$Type = 'EXTERN'"!]extern P2VAR(Adc_Bctu_DataType, ADC_VAR, ADC_APPL_DATA) [!"./BCTUUserBuffer"!][ADC_MAX_HW_UNITS];
[!ELSE!][!//
P2VAR(Adc_Bctu_DataType, ADC_VAR, ADC_APPL_DATA) [!"./BCTUUserBuffer"!][ADC_MAX_HW_UNITS] =
{
[!VAR "index_num" = "0"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcChannelTriggered/*"!][!//
[!IF "ADCHWUNIT = concat('ADC',string($Unit))"!][!//
[!VAR "UnitExits"="$UnitExits+1"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 1"!][!//
    &DataBuffer_[!"num:i(@index)"!][[!"num:i($index_num)"!]][0][!IF "$Unit < $maxUnit"!],[!ENDIF!]
[!VAR "index_num" = "$index_num + 1"!][!//
[!ELSE!][!//
    NULL_PTR[!IF "$Unit < $maxUnit"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDFOR!][!//
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Bctu_List_Trigger_Mode"!][!//
[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
/**
* @brief    The LIST element for LIST trigger mode.
* @details  Declarations LIST element for LIST trigger mode.
*/
[!LOOP "AdcConfigSet/BCTUHwUnit/*[1]/BCTU_InputTrigger/*"!][!//
[!IF "./BCTUMode = 'LIST_MODE'"!][!//
[!NOCODE!][!//
[!FOR "Index1" = "1" TO "num:i(count(AdcChannelTriggered/*)) - 1"!]
    [!FOR "Index2" = "$Index1 + 1" TO "num:i(count(AdcChannelTriggered/*))"!]
        [!IF "(AdcChannelTriggered/*[num:i($Index1)]/AdcChannel = AdcChannelTriggered/*[num:i($Index2)]/AdcChannel) and (AdcChannelTriggered/*[num:i($Index1)]/ADCHWUNIT = AdcChannelTriggered/*[num:i($Index2)]/ADCHWUNIT)"!]
            [!ERROR!]Duplicate physical channel.[!ENDERROR!]
        [!ENDIF!]
    [!ENDFOR!]
[!ENDFOR!]
[!ENDNOCODE!][!//
static CONST(Adc_Bctu_ListChannelType, ADC_CONST) Bctu_Cfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]ListInputTrigger[!"num:i(@index)"!][] =
{
[!VAR "loopvar" = "0"!][!//
[!LOOP "./AdcChannelTriggered/*"!][!//
[!VAR "loopvar"="$loopvar + 1"!][!//
[!NOCODE!][!//
    [!VAR "Channel"="num:i(substring-after(./AdcChannel, 'AN_'))"!]
    [!IF "./COMMAND = 'LAST'"!][!VAR "Last" = "bit:shl(1,15)"!][!ELSE!][!VAR "Last" = "0"!][!ENDIF!]
[!ENDNOCODE!][!//
    (uint16)[!"num:inttohex(bit:or($Channel,$Last),4)"!]U[!IF "$loopvar < (count(../../AdcChannelTriggered/*))"!],[!ELSE!][!ENDIF!]
[!ENDLOOP!][!//
};
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Bctu_Trigger_Configuration"!][!//
[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
/**
* @brief          Configuration for BCTU input trigger for [!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].
* @details        Configuration structure for BCTU input trigger for [!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!].
*
* 
*/
[!VAR "loopvar"="0"!][!//
static CONST(Adc_Bctu_TriggerConfigType, ADC_CONST) Adc_BctuTriggerConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][] =
{
[!LOOP "AdcConfigSet/BCTUHwUnit/*[1]/BCTU_InputTrigger/*"!][!//
[!VAR "loopvar"="$loopvar + 1"!][!//
    {
[!VAR "TriggerSource"!][!CALL "HWRESOURCE" , "SOURCE" = "./BCTUInputTriggerID"!][!ENDVAR!][!//
        (uint8)[!"num:i($TriggerSource)"!],
[!VAR "hwselected" = "0"!][!//
[!VAR "NumHwCfg" = "0"!][!//
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcChannelTriggered/*"!][!//
[!IF "ADCHWUNIT = concat('ADC',string($Unit))"!][!//
[!VAR "UnitExits"="$UnitExits+1"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 1"!][!//
[!VAR "hwselected" = "bit:or($hwselected,(bit:shl(1,$Unit)))"!][!//
[!VAR "NumHwCfg" = "$NumHwCfg + 1"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
        (uint8)[!"num:i($hwselected)"!],
        (uint8)[!IF "./BCTUTriggerLoop"!]1[!ELSE!]0[!ENDIF!],
        (uint8)[!IF "./BCTUMode = 'LIST_MODE'"!]1[!ELSE!]0[!ENDIF!],
[!IF "./BCTUMode = 'SINGLE_MODE'"!][!//
        (uint8)[!"substring-after(./AdcChannelTriggered/*[1]/AdcChannel, 'AN_')"!],
[!ELSE!][!//
[!NOCODE!][!//
  [!VAR "CurrentPos" = "@index"!]
  [!VAR "LaddrValue" = "0"!]
  [!FOR "Index" = "1" TO "num:i($CurrentPos)"!]
    [!IF "../*[num:i($Index)]/BCTUMode = 'LIST_MODE'"!]
      [!VAR "LaddrValue" = "$LaddrValue + count(../*[num:i($Index)]/AdcChannelTriggered/*)"!]  
    [!ENDIF!]
  [!ENDFOR!]
[!ENDNOCODE!][!//
        (uint8)[!"num:i($LaddrValue)"!],
[!ENDIF!][!//
        [!IF "./BCTUUserCallback != 'NULL_PTR'"!]&[!"./BCTUUserCallback"!][!ELSE!]NULL_PTR[!ENDIF!],
        [!"./BCTUUserBuffer"!],
[!IF "./BCTUMode = 'LIST_MODE'"!][!//
        Bctu_Cfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]ListInputTrigger[!"num:i(@index)"!],
        (uint8)[!"num:i(count(AdcChannelTriggered/*))"!],
[!ELSE!][!//
        NULL_PTR,
        (uint8)1,
[!ENDIF!][!//
        (uint8)[!"num:i($NumHwCfg)"!]
    }[!IF "$loopvar < (count(../../BCTU_InputTrigger/*))"!],[!ELSE!][!ENDIF!]
[!ENDLOOP!][!//
};
[!ENDIF!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Bctu_Main_Configuration"!][!//
[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
/**
* @brief          Configuration for BCTU hardware unit [!IF "var:defined('postBuildVariant')"!]for [!"$postBuildVariant"!][!ENDIF!].
* @details        Main configuration structure for BCTU hardware unit [!IF "var:defined('postBuildVariant')"!]for [!"$postBuildVariant"!][!ENDIF!]..
*
* 
*/
static CONST(Adc_Bctu_ConfigType, ADC_CONST) Adc_BctuConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    Adc_BctuTriggerConfig[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    (uint8)[!"num:i(count(AdcConfigSet/BCTUHwUnit/*[1]/BCTU_InputTrigger/*))"!]U,
    {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcConfigSet/BCTUHwUnit/*[1]/BCTU_InputTrigger/*/AdcChannelTriggered/*"!][!//
[!IF "ADCHWUNIT = concat('ADC',string(num:i($Unit)))"!][!//
[!VAR "UnitExits"="$UnitExits+1"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
        (uint8)[!IF "$UnitExits = 1"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDFOR!][!//
    },
    {
[!FOR "Unit" = "0" TO "num:i($maxUnit)"!][!//
[!VAR "mcl_Id"="0"!][!//
[!VAR "foundDma"="0"!][!//
[!VAR "UnitExits" = "0"!][!//
[!LOOP "AdcConfigSet/BCTUHwUnit/*[1]/BCTU_InputTrigger/*/AdcChannelTriggered/*"!][!//
[!IF "ADCHWUNIT = concat('ADC',string(num:i($Unit)))"!][!//
[!VAR "UnitExits"="$UnitExits+1"!][!//
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "AdcConfigSet/BCTUHwUnit/*[1]/BCTUDMAChannelEnable"!][!//
[!LOOP "node:refs('ASPathDataOfSchema:/TS_T2D35M10I0R0/Mcl')/MclConfigSet/*[1]/DMAChannel/*"!][!//
[!IF "$UnitExits = 1"!][!//
[!VAR "temp"="node:value(string(concat('DmaSource',string(num:i(num:i(substring-after(DmaHwChannel,'eDMA_')) div 16)))))"!][!//
[!IF "$temp = concat('BCTU_',string(num:i($Unit)))"!][!//
[!VAR "foundDma"="1"!][!//
[!VAR "mcl_Id"="string(MclDMAChannelId)"!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$UnitExits = 1"!][!//
[!IF "$foundDma = 0"!][!//
[!ERROR "No DMA channels enabled and configured in the MCL Plugin for transfer conversion results for BCTU_ADC. Enable them into MCL Plugin."!][!//
[!ENDIF!][!//
[!ENDIF!][!//
        (uint8)[!"num:i($mcl_Id)"!]U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]     /** Dma channel for ADC_[!"$Unit"!] */
[!ELSE!][!//
        (uint8)255U[!IF "$Unit < num:i($maxUnit)"!],[!ENDIF!]
[!ENDIF!][!//
[!ENDFOR!][!//
    }
};
[!ENDIF!][!//
[!ENDMACRO!][!//

[!MACRO "Adc_Bctu_Callback_Configuration"!][!//
[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
/**
* @brief    The external user callback function.
* @details  Declarations of the input trigger callback function.
*/
[!LOOP "AdcConfigSet/BCTUHwUnit/*[1]/BCTU_InputTrigger/*/BCTUUserCallback"!][!//
[!IF ". != 'NULL_PTR'"!][!//
void [!"."!](void);
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDMACRO!][!//

[!ENDIF!]