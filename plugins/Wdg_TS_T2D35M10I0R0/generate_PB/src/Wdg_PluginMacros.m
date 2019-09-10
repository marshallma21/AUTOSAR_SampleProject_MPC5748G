[!NOCODE!][!//
/**
  @file    Wdg_PluginMacros.m
  @version 1.0.0

  @brief   AUTOSAR Wdg - plugin check.
  @details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Patform PA
  Peripheral Swt
  Dependencies none
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.0
  BuildVersion MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217

  (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
  All Rights Reserved.
*/
/*==================================================================================================
==================================================================================================*/

[!// Constant that defines the maximum number of Wdg instances
[!VAR "WdgMaxNumberOfInstances"="3"!]

[!// MACRO for defining which instances will be used
[!MACRO "WdgInstanceMacro","SwtInstance"!]
[!NOCODE!]
[!VAR "MacWdgFoundInstance"="0"!]
[!LOOP "WdgSettingsConfig/*"!]
       [!IF "node:value(./WdgInstance) = $SwtInstance"!]
       [!VAR "MacWdgFoundInstance"="1"!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]
/**
  * @brief  This constant specifies if the instance of the WDG is selected or not
  */
[!IF "$MacWdgFoundInstance = 1 "!][!/*
    */!]#define WDG_INSTANCE[!"substring-after($SwtInstance,'SWT')"!] (STD_ON)
[!ELSE!][!/*
    */!]#define WDG_INSTANCE[!"substring-after($SwtInstance,'SWT')"!] (STD_OFF)
[!ENDIF!]
[!ENDMACRO!]

[!// MACRO for checking that the Gpt callback has been set
[!MACRO "WdgCheckCbkNotification","SwtInstance"!]
[!NOCODE!]
[!LOOP "WdgSettingsConfig/*"!]
    [!IF "./WdgInstance = $SwtInstance"!]
        [!IF "node:exists(node:ref(./WdgExternalTriggerCounterRef)/GptNotification)"!]
            [!IF "node:ref(./WdgExternalTriggerCounterRef)/GptNotification != concat('Wdg_Cbk_GptNotification',substring-after($SwtInstance,'SWT'))"!]
                [!ERROR!] The notification handler for [!"$SwtInstance"!] must be Wdg_Cbk_GptNotification[!"substring-after($SwtInstance,'SWT')"!][!ENDERROR!]
            [!ENDIF!]
        [!ELSE!]
            [!ERROR!] The channel notification for [!"$SwtInstance"!] must be set up and the notification handler must be Wdg_Cbk_GptNotification[!"substring-after($SwtInstance,'SWT')"!][!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDNOCODE!]

[!ENDMACRO!]

[!// MACRO for defining mode configuration
[!MACRO "WdgModeConfig","WdgMode"!]
(uint32)(SWT_ALL_MAP_DISABLE_U32[!/* 
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgMasterAccessProtectionforMaster0'))"!] | SWT_MAP0_ENABLE_U32[!ENDIF!][!/* 
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgMasterAccessProtectionforMaster1'))"!] | SWT_MAP1_ENABLE_U32[!ENDIF!][!/* 
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgMasterAccessProtectionforMaster2'))"!] | SWT_MAP2_ENABLE_U32[!ENDIF!][!/* 
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgMasterAccessProtectionforMaster3'))"!] | SWT_MAP3_ENABLE_U32[!ENDIF!][!/* 
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgMasterAccessProtectionforMaster4'))"!] | SWT_MAP4_ENABLE_U32[!ENDIF!][!/* 
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgMasterAccessProtectionforMaster5'))"!] | SWT_MAP5_ENABLE_U32[!ENDIF!][!/* 
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgMasterAccessProtectionforMaster6'))"!] | SWT_MAP6_ENABLE_U32[!ENDIF!][!/* 
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgMasterAccessProtectionforMaster7'))"!] | SWT_MAP7_ENABLE_U32[!ENDIF!][!/*
            */!] | SWT_WDG_ENABLED_U32 | [!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgWindowMode'))"!]SWT_TRIGGER_MODE_WINDOW_U32 | [!ELSE!]SWT_TRIGGER_MODE_REGULAR_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgSoftLockConfiguration'))"!]SWT_WDG_SOFT_LOCK_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgHardLockConfiguration'))"!]SWT_WDG_HARD_LOCK_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgKeyedService'))"!]SWT_KEYED_SERVICE_U32 | [!ELSE!]SWT_FIXED_SERVICE_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgRunsInStopMode'))"!]SWT_WDG_RUN_IN_HALT_U32 | [!ELSE!]SWT_WDG_STOP_IN_HALT_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgRunsInDebugMode'))"!]SWT_WDG_RUN_IN_DEBUG_U32 | [!ELSE!]SWT_WDG_STOP_IN_DEBUG_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgOperationMode')) = 'Interrupt'"!]SWT_INTERRUPT_TOGGLE_U32 | [!ELSE!]SWT_RESET_ON_TIMEOUT_U32 | [!ENDIF!][!/*
            */!][!IF "node:value(concat(concat('./',$WdgMode),'/WdgResetOnInvalidAccess')) = 'BusError'"!]SWT_INVALID_ACCESS_GEN_BUS_ERROR_U32 [!ELSE!]SWT_INVALID_ACCESS_GEN_SYSTEM_RESET_U32 [!ENDIF!][!/*
             */!] ), /* WDG Control and configuration */
        (uint32)[!"num:inttohex(num:i(node:value(concat(concat('./',$WdgMode),'/WdgTimeoutPeriod')) * node:value(concat(concat('./',$WdgMode),'/WdgClockValue')) * 1000),8)"!],  /* Time-out config */
        (uint32)[!IF "node:value(concat(concat('./',$WdgMode),'/WdgWindowMode'))"!][!/*
                  */!][!"num:inttohex(num:i(node:value(concat(concat('./',$WdgMode),'/WdgWindowPeriod'))* node:value(concat(concat('./',$WdgMode),'/WdgClockValue')) * 1000),8)"!][!/*
            */!][!ELSE!][!"num:inttohex(num:i(node:value(concat(concat('./',$WdgMode),'/WdgTimeoutPeriod'))*0.4 * node:value(concat(concat('./',$WdgMode),'/WdgClockValue')) * 1000),8)"!][!ENDIF!],  /* Window config */
        (uint32)[!IF "node:value(concat(concat('./',$WdgMode),'/WdgKeyedService'))"!][!/*
            */!][!"num:inttohex(num:i(node:value(concat(concat('./',$WdgMode),'/WdgServiceKeyValue'))),8)"!][!ELSE!][!"num:inttohex(0,8)"!][!ENDIF!],  /*Initial service key value*/
        (uint32)[!"node:value(concat(concat('./',$WdgMode),'/WdgClockValue'))"!] /*Wdg Internal clock value*/    
[!ENDMACRO!]

[!// MACRO for defining configuration sets
[!MACRO "WdgConfigSet","WdgSwtInstance", "WdgMisraRef", "WdgConfigType"!]
[!NOCODE!]
[!ENDNOCODE!]

/** 
 * @violates @ref [!"$WdgMisraRef"!] MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 * functions at file scope shall have internal linkage unless external linkage is required.
 */
CONST(Wdg_Swt_ConfigType, WDG_CONST) Wdg_Swt_OffModeSettings_[!"substring-after($WdgSwtInstance,'SWT')"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
        (uint32)(SWT_MAP_ENABLE_8BITS_U32 | SWT_WDG_DISABLED_U32 | SWT_WDG_SOFT_LOCK_U32),
        (uint32)0x00000100, /*Timeout config*/
        (uint32)0x00000000,  /* Window config */
        (uint32)0x00000000, /* Initial key value*/
        (uint32)128       /* Internal clock frequency*/
};

[!LOOP "WdgSettingsConfig/*"!][!//

[!IF "node:value(./WdgInstance) = $WdgSwtInstance"!][!//

 /** @violates @ref [!"$WdgMisraRef"!] MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
  *   functions at file scope shall have internal linkage unless external linkage is required. 
  */
CONST(Wdg_Swt_ConfigType, WDG_CONST) Wdg_Swt_SlowModeSettings_[!"@index"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    [!CALL "WdgModeConfig","WdgMode" = "'WdgSettingsSlow'"!]
};


/** @violates @ref [!"$WdgMisraRef"!] MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. 
 */
CONST(Wdg_Swt_ConfigType, WDG_CONST) Wdg_Swt_FastModeSettings_[!"@index"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]=
{
    [!CALL "WdgModeConfig","WdgMode" = "'WdgSettingsFast'"!]
};

[!VAR "MacWdgNotificationValue"="node:value(concat('./../../WdgGeneral/',concat('WdgCallbackNotification', substring-after($WdgSwtInstance,'SWT'))))"!]
/**
* @brief  This constant contains the configuration set for the postbuild time
*/
/** @violates @ref [!"$WdgMisraRef"!] MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
 *   functions at file scope shall have internal linkage unless external linkage is required. */

CONST(Wdg_ConfigType, WDG_CONST)[!"@name"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
        [!"node:value(./WdgDefaultMode)"!],
        WDG_IPW_INSTANCE[!"substring-after($WdgSwtInstance,'SWT')"!],
        (Gpt_ChannelType)GptConf_GptChannelConfiguration_[!"text:split(./WdgExternalTriggerCounterRef ,'/')[5]"!],
        (uint32)[!"num:i(node:value(node:ref(./WdgExternalTriggerCounterRef)/GptChannelTickFrequency)div 1000)"!],
        { &Wdg_Swt_OffModeSettings_[!"substring-after($WdgSwtInstance,'SWT')"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], &Wdg_Swt_SlowModeSettings_[!"@index"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], &Wdg_Swt_FastModeSettings_[!"@index"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]},
        [!IF "normalize-space($MacWdgNotificationValue) = 'NULL' or normalize-space($MacWdgNotificationValue) = 'NULL_PTR'"!]NULL_PTR[!ELSE!]&[!"$MacWdgNotificationValue"!][!ENDIF!] /* WdgCallbackNotification */
};
[!ENDIF!]
[!ENDLOOP!]
[!ENDMACRO!]

[!// MACRO for defining wich isrs are used configuration
[!MACRO "WdgNotificationMacro","WdgSwtInstance"!]
[!IF "(normalize-space(node:value(concat('WdgGeneral/',concat('WdgCallbackNotification', substring-after($WdgSwtInstance,'SWT'))))) !='NULL_PTR') and (normalize-space(node:value(concat('WdgGeneral/',concat('WdgCallbackNotification', substring-after($WdgSwtInstance,'SWT'))))) !='NULL')"!]
/**
 *   @brief External Notifications for Wdg Interrupt
 */[!CR!]
extern FUNC (void, WDG_CODE) [!"node:value(concat('WdgGeneral/',concat('WdgCallbackNotification', substring-after($WdgSwtInstance,'SWT'))))"!](void);
[!ENDIF!]
[!ENDMACRO!]

[!// MACRO for defining wich isrs are used configuration
[!MACRO "WdgIsr","WdgSwtInstance"!]
[!LOOP "WdgSettingsConfig/*"!][!//
[!IF "./WdgInstance = $WdgSwtInstance and node:value(./WdgInterruptContentEnable) = 'true'"!]

/**
* @brief  This variable will indicate if the ISR[!"substring-after($WdgSwtInstance,'SWT')"!] is used
*/
#define  WDG_ISR[!"substring-after($WdgSwtInstance,'SWT')"!]_USED
[!BREAK!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDMACRO!]

[!MACRO "WdgExportDriverConfiguration"!]
[!NOCODE!][!//
[!CODE!][!//
/** 
 * @violates @ref Wdg_Cfg_h_REF_2 MISRA 2004 Required Rule 19.4 C macros shall only expand to...
 */
#define WDG_CONF_PB \
[!ENDCODE!][!//
[!VAR "num_confg" = "num:i(count(WdgSettingsConfig/*))"!][!//
[!VAR "num_confgIndex"="0"!][!//
[!LOOP "WdgSettingsConfig/*"!][!//
[!VAR "num_confgIndex" = "$num_confgIndex + 1"!][!//
[!VAR "configName" = "@name"!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Wdg_ConfigType, WDG_CONST) [!"$configName"!]_[!"."!];[!IF "($variantIndex < $variantNumber) or ($num_confgIndex < $num_confg)"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Wdg_ConfigType, WDG_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!]

[!ENDNOCODE!]
