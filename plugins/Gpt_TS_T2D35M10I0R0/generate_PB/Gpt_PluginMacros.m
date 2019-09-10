[!AUTOSPACING!]
[!NOCODE!]

/**
*   @file    Gpt_PluginMacros.m
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - Macros used to generate code template for GPT driver.
*   @details Macros used to generate code template for GPT driver.
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


[!/* Avoid multiple inclusion */!]
[!IF "not(var:defined('GPT_BUILD_CHANNEL_MAP_M'))"!]
[!VAR "GPT_BUILD_CHANNEL_MAP_M"="'true'"!]

[!//This macros is used to calculate the number of emios channel Ids and numer of emios hw modules.
[!MACRO "CalculateModulesNumber","ModuleType"!]
        [!IF "$ModuleType = 'EMIOS'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_eMios_Hw_Modules'))"!]
            [!VAR "MacHwModulOffsetValue"="1"!][!// This value will be hardcode for each platform independently
            [!VAR "MacMaxChannels"="32"!][!// The max number of channels per module
        [!ELSEIF "$ModuleType = 'PIT'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Pit_Hw_Modules'))"!]
            [!VAR "MacHwModulOffsetValue"="num:i(ecu:list('Gpt.Num_eMios_Hw_Modules'))+num:i(1)"!][!// This value will be hardcode for each platform independently
            [!VAR "MacMaxChannels"="32"!][!// The max number of channels per module
        [!ELSEIF "$ModuleType = 'STM'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Stm_Hw_Modules'))"!]
            [!VAR "MacHwModulOffsetValue"="num:i(ecu:list('Gpt.Num_eMios_Hw_Modules'))+num:i(ecu:list('Gpt.Num_Pit_Hw_Modules'))+num:i(1)"!][!// This value will be hardcode for each platform independently
            [!VAR "MacMaxChannels"="4"!][!// The max number of channels per module
        [!ELSEIF "$ModuleType = 'RTC'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Rtc_Hw_Modules'))"!]
            [!VAR "MacHwModulOffsetValue"="num:i(ecu:list('Gpt.Num_eMios_Hw_Modules'))+num:i(ecu:list('Gpt.Num_Pit_Hw_Modules'))+num:i(ecu:list('Gpt.Num_Stm_Hw_Modules'))+num:i(1)"!][!// This value will be hardcode for each platform independently
            [!VAR "MacMaxChannels"="1"!][!// The max number of channels per module
        [!ENDIF!][!//

        [!FOR "MacModuleId" = "0" TO "$MacMaxModules - 1"!]
            [!VAR "NumberChannels"="num:i(ecu:list('Gpt.Num_Channels_Per_Module'))[num:i($MacHwModulOffsetValue + $MacModuleId)]"!]
            [!IF "num:i(count(text:grep(ecu:list('Gpt.GptChannelConfigSet.GptChannelConfiguration.GptHwChannel'),concat($ModuleType,'_',$MacModuleId,'.*')))) != num:i($NumberChannels)"!]
            [!ERROR!][!//
                [!"$Name"!][!"concat(' - ',$ModuleType,'_',num:i($MacModuleId),'- number of channels is conflicted!')"!][!//
            [!ENDERROR!][!//
            [!ENDIF!]
            [!CODE!]
/* The number of channels in [!"$ModuleType"!]_[!"$MacModuleId"!] */
#define GPT_[!"$ModuleType"!]_[!"$MacModuleId"!]_NUM_CHANNEL_U8   ([!"$NumberChannels"!]U)
            [!ENDCODE!][!//                
        [!ENDFOR!]

        [!CODE!]
/* The maximum number of channels in [!"$ModuleType"!] */
#define GPT_[!"$ModuleType"!]_CHAN_NUM_U8         ([!"num:i($MacMaxModules * $MacMaxChannels)"!]U)

/* The number of modules in [!"$ModuleType"!] */
#define GPT_[!"$ModuleType"!]_MODULES_NUM_U8      ([!"num:i($MacMaxModules)"!]U)
        [!ENDCODE!][!//
[!ENDMACRO!]


[!//This macros is used to build the hardware to logic map table
[!MACRO "BuildChannelMap" , "ModuleType","LastModule"!]
        [!IF "$ModuleType = 'STM'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Stm_Hw_Modules'))"!]
            [!VAR "MacMaxChannelId"="num:i(4)"!][!//number of channels included into a module     
        [!ELSEIF "$ModuleType = 'PIT'"!]
            [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Pit_Hw_Modules'))"!]
            [!VAR "MacMaxChannelId"="num:i(32)"!][!//number of channels included into a module     
        [!ELSEIF "$ModuleType = 'EMIOS'"!]
           [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_eMios_Hw_Modules'))"!]
           [!VAR "MacMaxChannelId"="num:i(32)"!][!//number of channels included into a module     
        [!ELSEIF "$ModuleType = 'RTC'"!]    
           [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Rtc_Hw_Modules'))"!]
           [!VAR "MacMaxChannelId"="num:i(1)"!][!//number of channels included into a module     
        [!ENDIF!][!//

    [!//Hardware to logic channel mapping
    [!FOR "MacModuleId" = "0" TO "num:i($MacMaxModules)-1"!][!//
        [!FOR "MacChannelId" = "0" TO "num:i($MacMaxChannelId)-1"!][!//
            [!VAR "MacChannelUsed"="0"!][!//
            [!FOR "MacLogicChannel" = "0" TO "num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!][!//
                [!SELECT "GptChannelConfigSet/GptChannelConfiguration/*/GptChannelId[.=$MacLogicChannel]/.."!][!//
                [!IF "$ModuleType = 'PIT'"!]
                    [!IF "num:i($MacChannelId) = 0"!]
                        [!IF "GptHwChannel = concat($ModuleType,'_',num:i($MacModuleId),'_CH_RTI')"!][!//
                            [!CODE!]
        GptConf_GptChannelConfiguration_[!"node:name(.)"!][!ENDCODE!][!//
                            [!VAR "MacChannelUsed"="1"!][!//
                        [!ENDIF!][!//
                    [!ELSE!]
                        [!IF "GptHwChannel = concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId)-1)"!][!//
                            [!CODE!]
        GptConf_GptChannelConfiguration_[!"node:name(.)"!][!ENDCODE!][!//
                            [!VAR "MacChannelUsed"="1"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ELSE!]
                    [!IF "GptHwChannel = concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!][!//
                        [!CODE!]
        GptConf_GptChannelConfiguration_[!"node:name(.)"!][!ENDCODE!][!//
                        [!VAR "MacChannelUsed"="1"!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
                [!ENDSELECT!][!//
            [!ENDFOR!][!//

            
            [!IF "$MacChannelUsed=0"!][!//
                [!CODE!]
        GPT_CHN_NOT_USED[!ENDCODE!][!//
            [!ENDIF!][!//

            [!IF "$MacModuleId=(num:i($MacMaxModules -1)) and $MacChannelId=(num:i($MacMaxChannelId -1)) and $LastModule = 'TRUE'"!]
            [!//Empty code here
            [!ELSE!]
                [!CODE!],[!ENDCODE!][!//
            [!ENDIF!][!//

            [!IF "$ModuleType = 'STM'"!]
                [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!]*/[!ENDCODE!][!//
            
            [!ELSEIF "$ModuleType = 'RTC'"!]
                [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!]*/[!ENDCODE!][!//
            
            [!ELSEIF "$ModuleType = 'PIT'"!]
                [!IF "$MacModuleId=0"!][!//PIT_0
                    [!IF "$MacChannelId>15"!][!//
                        [!CODE!] /*Index not used */[!ENDCODE!][!//
                    [!ELSEIF "$MacChannelId>0"!]
                        [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId)-1)"!]*/[!ENDCODE!][!//
                    [!ELSEIF "$MacChannelId=0"!]
                        [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_RTI')"!]*/[!ENDCODE!][!//    
                    [!ENDIF!][!//
                [!ELSE!][!//PIT_1,2
                    [!IF "$MacChannelId>2"!][!//
                        [!CODE!] /*Index not used */[!ENDCODE!][!//
                    [!ELSEIF "$MacChannelId>0"!]
                        [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId)-1)"!]*/[!ENDCODE!][!//
                    [!ELSEIF "$MacChannelId=0"!]
                        [!CODE!] /*Index not used */[!ENDCODE!][!//
                    [!ENDIF!][!//                
                [!ENDIF!][!//

            [!ELSEIF "$ModuleType = 'EMIOS'"!]
                    [!CODE!] /*mapping of [!"concat($ModuleType,'_',num:i($MacModuleId),'_CH_',num:i($MacChannelId))"!]*/[!ENDCODE!][!//
            [!ENDIF!][!//
        [!ENDFOR!][!//
    [!ENDFOR!][!//  
[!ENDMACRO!]

[!//This macros is used to check parameters
[!MACRO "CheckParameter" , "ModuleType", "param"!]
    [!IF "$ModuleType = 'STM'"!]
        [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Stm_Hw_Modules'))"!]
    [!ELSEIF "$ModuleType = 'PIT'"!]
        [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Pit_Hw_Modules'))"!]
    [!ELSEIF "$ModuleType = 'EMIOS'"!]
        [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_eMios_Hw_Modules'))"!]
    [!ELSEIF "$ModuleType = 'RTC'"!]    
        [!VAR "MacMaxModules"="num:i(ecu:list('Gpt.Num_Rtc_Hw_Modules'))"!]
    [!ENDIF!][!//
        
     [!VAR "MacErrorFlag" = "string('Invalid')"!][!//
    
    [!FOR "idx" = "0" TO "num:i($MacMaxModules)"!][!//
        [!VAR "MacErrorFlag" = "string('Invalid')"!][!//
        [!FOR "x" = "0" TO "num:i(count(GptChannelConfiguration/*))"!][!//
        [!SELECT "GptChannelConfiguration/*/GptChannelId[.=$x]/.."!][!//
            [!IF "contains(GptHwChannel, concat($ModuleType, '_', $idx)) and node:exists($param)"!][!//
                [!IF "($MacErrorFlag = string('Invalid'))"!][!//
                    [!VAR "MacErrorFlag" = "string(node:value($param))"!][!//
                [!ELSE!][!//
                    [!IF "($MacErrorFlag = string(node:value($param)))"!][!//
                    [!ELSE!][!//
                        [!ERROR!][!//
                        [!"concat('For the ',$ModuleType, '_', $idx,' module all the channels must have the same value for the ', $param, ' parameter, because this module has one general clock prescaler for all its counter channels.')"!][//
                        [!ENDERROR!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//  
            [!ENDIF!][!//  
        [!ENDSELECT!][!//
        [!ENDFOR!]
    [!ENDFOR!]
[!ENDMACRO!]

[!//This macros is used to build the configuration structure for a config set.
[!MACRO "BuildConfigSet"!]
    

    [!SELECT "GptChannelConfigSet"!]
    [!CALL "CheckParameter","ModuleType"="string('STM')", "param"="string('GptChannelTickFrequency')"!][!//
    [!CALL "CheckParameter","ModuleType"="string('STM')", "param"="string('GptChannelClkSrcRef')"!][!//
    [!CALL "CheckParameter","ModuleType"="string('STM')", "param"="string('GptStmChannelClkSrc')"!][!//
    [!IF "node:value(../GptNonAUTOSAR/GptEnableDualClockMode)"!][!//
        [!CALL "CheckParameter","ModuleType"="string('STM')", "param"="string('GptChannelPrescalerAlternate')"!][!//
    [!ENDIF!]
    
    [!ENDSELECT!]

    [!FOR "x" = "0" TO "num:i(count(GptChannelConfigSet/GptChannelConfiguration/*))"!][!//
    [!SELECT "GptChannelConfigSet/GptChannelConfiguration/*/GptChannelId[.=$x]/.."!][!//

[!CODE!][!//
    {   /*[!"node:name(.)"!] configuration data*/
        [!IF "GptEnableWakeup"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!], /* Wakeup capability */
        [!IF "node:exists(GptNotification)"!][!IF "(GptNotification != '') and (GptNotification != 'NULL_PTR') and (GptNotification != 'NULL')"!]&[!"GptNotification"!][!ELSE!]NULL_PTR[!ENDIF!][!ELSE!]NULL_PTR[!ENDIF!], /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
         (EcuM_WakeupSourceType)[!IF "node:exists(GptWakeupConfiguration)"!]((uint32)((uint32)1<<[!"as:ref(GptWakeupConfiguration/GptWakeupSourceRef)/EcuMWakeupSourceId"!]))[!ELSE!]0U[!ENDIF!], /* Wakeup information */
#endif
        (Gpt_ValueType)([!"num:i(GptChannelTickValueMax)"!]U), /* Maximum ticks value*/
        (Gpt_ChannelModeType)([!"GptChannelMode"!]), /* Timer mode:continous/one-shot */
        {
            (uint8)([!"GptHwChannel"!]), /* GPT physical channel no. */
            (uint8)(GPT_[!"substring-before(GptHwChannel, '_')"!]_MODULE), /* hardware module ID */
            [!IF "GptFreezeEnable"!](boolean)TRUE[!ELSE!](boolean)(FALSE)[!ENDIF!], /* Freeze Enable */
[!ENDCODE!]
    [!VAR "MacRtcChannelFreq" = "num:i( contains(node:fallback(GptHwChannel,'RTC'),'RTC') = true()) * [!//
                                            ([!//
                                                ([!//
                                                    (num:i(node:fallback(GptRtcChannelClkSrc,'RTC_GPT_CLKSRC_XOSC') = 'RTC_GPT_CLKSRC_XOSC')) *[!//
                                                    noderef:value(concat(noderef:ref(noderef:value(concat(noderef:ref(node:fallback(GptChannelClkSrcRef, .)), '/GptClockReference'))), '/McuClockReferencePointFrequency'))[!//
                                                ) +[!//
                                                ([!//
                                                    (num:i(node:fallback(GptRtcChannelClkSrc,'RTC_GPT_CLKSRC_XOSC') = 'RTC_GPT_CLKSRC_FIRC')) *[!//
                                                    num:i(16000000)[!//
                                                ) +[!//
                                            ([!//
                                                (num:i(node:fallback(GptRtcChannelClkSrc,'RTC_GPT_CLKSRC_XOSC') = 'RTC_GPT_CLKSRC_SIRC')) *[!//
                                                 num:i(128000)[!//
                                            )[!//
                                            +[!//
                                            ([!//
                                                (num:i(node:fallback(GptRtcChannelClkSrc,'RTC_GPT_CLKSRC_XOSC') = 'RTC_GPT_CLKSRC_SXOSC')) *[!//
                                                num:i(32000)[!//
                                            ))div[!//
                                            num:i([!//
                                                (num:i(contains((node:fallback(GptChannelPrescaler,1)),1)) * num:i(1)) +[!//
                                                (num:i(contains((node:fallback(GptChannelPrescaler,1)),2)) * num:i(32)) +[!//
                                                (num:i(contains((node:fallback(GptChannelPrescaler,1)),3)) * num:i(512)) + [!//
                                                (num:i(contains((node:fallback(GptChannelPrescaler,1)),4)) * num:i(16384)) +[!//
                                                (num:i( contains(node:fallback(GptHwChannel,'PIT'),'PIT') = true())) + [!//
                                                (num:i( contains(node:fallback(GptHwChannel,'STM'),'STM') = true())) +[!//
                                                (num:i( contains(node:fallback(GptHwChannel,'EMIOS'),'EMIOS') = true()))[!//
                                            )"!][!//
    
    [!VAR "MacChannelFreq" = "num:i( contains(GptHwChannel,'PIT'))* noderef:value(concat(noderef:ref(noderef:value(concat(noderef:ref(GptChannelClkSrcRef), '/GptClockReference'))), '/McuClockReferencePointFrequency')) + [!//
                              num:i(contains(GptHwChannel,'STM')) *(noderef:value(concat(noderef:ref(noderef:value(concat(noderef:ref(GptChannelClkSrcRef), '/GptClockReference'))), '/McuClockReferencePointFrequency')) div (num:i(not(contains(node:fallback(GptHwChannel,'STM'),'STM'))) + GptChannelPrescaler)) + [!//
                              num:i(contains(GptHwChannel,'EMIOS')) *(noderef:value(concat(noderef:ref(noderef:value(concat(noderef:ref(GptChannelClkSrcRef), '/GptClockReference'))), '/McuClockReferencePointFrequency')) div (num:i(not(contains(node:fallback(GptHwChannel,'EMIOS'),'EMIOS'))) + GptChannelPrescaler))"!][!// 

    [!VAR "MacChannelFreq" = "$MacRtcChannelFreq + $MacChannelFreq"!]
    [!IF "num:f(GptChannelTickFrequency)!=num:f($MacChannelFreq)"!]
        [!ERROR!]
                The value configured for GptChannelTickFrequency parameter is not compliant with MCU clock tree settings.
                To solve this problem change the configured channel ticks frequency from "[!"num:f(GptChannelTickFrequency)"!]" to "[!"num:f($MacChannelFreq)"!]".
        [!ENDERROR!]
    [!ENDIF!][!//


    [!IF "contains(GptHwChannel, 'STM')"!][!//
[!CODE!][!//
            (Gpt_PrescalerType)([!"num:i(number(GptChannelPrescaler)-1)"!]U), /* STM Clock divider */[!ENDCODE!]
    [!ELSE!][!//
        [!IF "contains(GptHwChannel, 'PIT')"!][!//
[!CODE!][!//
            (uint8)0U, /* PIT Clock divider - Unused */[!ENDCODE!]
        [!ELSEIF "contains(GptHwChannel, 'RTC')"!][!//
            [!CODE!][!//
            (Gpt_PrescalerType)([!"num:i(number(GptChannelPrescaler) -1)"!]U), /* RTC Clock divider */[!ENDCODE!]
        [!ELSE!][!//
[!CODE!][!//
            (Gpt_PrescalerType)([!"num:i(number(GptChannelPrescaler)-1)"!]U), /* EMIOS Clock divider */[!ENDCODE!]
        [!ENDIF!][!//
    [!ENDIF!][!//

    
[!CODE!][!//    
[!IF "contains(GptHwChannel, 'RTC')"!][!//
    [!IF "GptRtcChannelClkSrc = 'RTC_GPT_CLKSRC_XOSC'"!]
        (uint8)3U, /* RTC uses XOSC Clock*/[!//
    [!ELSEIF "GptRtcChannelClkSrc = 'RTC_GPT_CLKSRC_FIRC'"!]
        (uint8)2U, /* RTC uses FIRC 16Mhz Clock*/[!//
    [!ELSEIF "GptRtcChannelClkSrc = 'RTC_GPT_CLKSRC_SIRC'"!]
        (uint8)1U, /* RTC uses SIRC 32Khz Clock*/[!//
    [!ELSE!]
        (uint8)0U, /* RTC uses SXOSC 128Khz Clock*/[!//
    [!ENDIF!]
[!ELSE!][!//
            (uint8)0U, /* RTC clock source - Unused */
[!ENDIF!][!//
[!ENDCODE!][!//

[!CODE!][!//
#if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
[!IF "contains(GptHwChannel, 'STM')"!][!//
[!IF "GptStmChannelClkSrc = 'GPT_STM_SYSTEMCLOCK'"!][!//
            (Gpt_PrescalerType)0U, /* STM clock source - System clock is selected */
[!ELSEIF "GptStmChannelClkSrc = 'GPT_STM_FXOSCCLOCK'"!][!//
            (Gpt_PrescalerType)1U, /* STM clock source - FXOSC clock is selected */
[!ENDIF!][!//
[!ELSE!][!//
            (Gpt_PrescalerType)0U, /* STM clock source - Unused*/
[!ENDIF!][!//
#endif
[!ENDCODE!][!//

[!CODE!][!//
[!IF "../../../GptNonAUTOSAR/GptEnableDualClockMode"!][!//
#if GPT_SET_CLOCK_MODE==STD_ON
[!IF "contains(GptHwChannel, 'STM')"!][!//
[!CODE!][!//
            (Gpt_PrescalerType)([!"num:i(number(GptChannelPrescalerAlternate)-1)"!]U), /* STM Clock divider */[!ENDCODE!]
[!ELSEIF "contains(GptHwChannel, 'PIT')"!][!//
[!CODE!][!//
            (uint8)(0U) /* PIT Clock divider - Unused */[!ENDCODE!]
[!ELSEIF "contains(GptHwChannel, 'RTC')"!][!//
[!CODE!][!//
            (Gpt_PrescalerType)([!"num:i(number(GptChannelPrescalerAlternate)-1)"!]U), /* STM Clock divider */[!ENDCODE!]
[!ELSE!][!//
[!CODE!][!//
            (Gpt_PrescalerType)([!"num:i(number(GptChannelPrescalerAlternate)-1)"!]U), /* EMIOS Clock divider */[!ENDCODE!]
[!ENDIF!][!//
#endif
[!ENDIF!][!//
        }
    }[!ENDCODE!][!CR!][!//
[!ENDSELECT!][!//

[!CODE!][!//
[!IF "$x < num:i(count(GptChannelConfigSet/GptChannelConfiguration/*)) - 1"!],[!ENDIF!]
[!ENDCODE!]
[!ENDFOR!][!//
[!ENDMACRO!]

[!MACRO "PredefTimerStmConsistencyCheck"!]
[!VAR "MacCurrentModule" ="substring-before(GptHwChannel,'_CH_')"!]
[!VAR "MacGptChannelClkSrcRef" = "GptChannelClkSrcRef"!]
[!VAR "MacGptChannelPrescaler" = "GptChannelPrescaler"!]
[!VAR "MacGptStmChannelClkSrc" = "GptStmChannelClkSrc"!]
[!VAR "MacGptFreezeEnable" = "GptFreezeEnable"!]
[!LOOP "../*"!]
    [!IF "substring-before(GptHwChannel,'_CH_') = $MacCurrentModule"!]
        [!IF "GptChannelClkSrcRef != $MacGptChannelClkSrcRef"!]
            [!ERROR!]
                GptChannelClkSrcRef of predeftimer [!"$MacCurrentModule"!] is not consistency with other predeftimer channel
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptChannelPrescaler != $MacGptChannelPrescaler"!]
            [!ERROR!]
                GptChannelPrescaler of predeftimer [!"$MacCurrentModule"!] is not consistency with other predeftimer channel
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptStmChannelClkSrc != $MacGptStmChannelClkSrc"!]
            [!ERROR!]
                GptStmChannelClkSrc of predeftimer [!"$MacCurrentModule"!] is not consistency with other predeftimer channel
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptFreezeEnable != $MacGptFreezeEnable"!]
            [!ERROR!]
                GptFreezeEnable of predeftimer [!"$MacCurrentModule"!] is not consistency with other predeftimer channel
            [!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!LOOP "../../GptChannelConfigSet/GptChannelConfiguration/*"!]
    [!IF "substring-before(GptHwChannel,'_CH_') = $MacCurrentModule"!]
        [!IF "GptChannelClkSrcRef != $MacGptChannelClkSrcRef"!]
            [!ERROR!]
                GptChannelClkSrcRef of predeftimer [!"$MacCurrentModule"!] is not consistency with Gpt channel [!"GptChannelId"!]
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptChannelPrescaler != $MacGptChannelPrescaler"!]
            [!ERROR!]
                GptChannelPrescaler of predeftimer [!"$MacCurrentModule"!] is not consistency with Gpt channel [!"GptChannelId"!]
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptStmChannelClkSrc != $MacGptStmChannelClkSrc"!]
            [!ERROR!]
                GptStmChannelClkSrc of predeftimer [!"$MacCurrentModule"!] is not consistency with Gpt channel [!"GptChannelId"!]
            [!ENDERROR!]
        [!ENDIF!]
        [!IF "GptFreezeEnable != $MacGptFreezeEnable"!]
            [!ERROR!]
                GptFreezeEnable of predeftimer [!"$MacCurrentModule"!] is not consistency with Gpt channel [!"GptChannelId"!]
            [!ENDERROR!]
        [!ENDIF!]
    [!ENDIF!]
[!ENDLOOP!]
[!ENDMACRO!]

[!//This macros is used to build the Predef timer configuration structure.
[!MACRO "BuildHwchannelPredefTimer","predefType"!]
[!NOCODE!]

[!VAR "path_temp" = "'GptPredefTimer_1us_16Bit'"!]

[!IF "$predefType = 'PREDEF_TIMER_1US_16BIT'"!]
    [!VAR "path_temp" = "'GptPredefTimer_1us_16Bit'"!]
[!ELSEIF "$predefType = 'PREDEF_TIMER_1US_24BIT'"!][!//
    [!VAR "path_temp" = "'GptPredefTimer_1us_24Bit'"!]
[!ELSEIF "$predefType = 'PREDEF_TIMER_1US_32BIT'"!][!//
    [!VAR "path_temp" = "'GptPredefTimer_1us_32Bit'"!]
[!ELSE!]
    [!VAR "path_temp" = "'GptPredefTimer_100us_32Bit'"!]
[!ENDIF!]

[!VAR "path_predef" = "concat('GptPredefTimerConfiguration/',$path_temp)"!]
[!SELECT "node:ref($path_predef)"!][!//
[!IF "contains(GptHwChannel,'STM')"!][!//
    [!CALL "PredefTimerStmConsistencyCheck"!]
[!ENDIF!][!//
[!CODE!][!//
    (uint8)([!"GptHwChannel"!]), /* GPT physical channel no. */
    (uint8)(GPT_[!"substring-before(GptHwChannel, '_')"!]_MODULE), /* hardware module ID */
[!IF "GptFreezeEnable"!][!//
    (boolean)TRUE, /* Freeze Enable */
[!ELSE!][!//
    (boolean)(FALSE), /* Freeze Disnable */
[!ENDIF!][!//
[!IF "contains(GptHwChannel, 'STM')"!][!//
    (Gpt_PrescalerType)([!"num:i(number(GptChannelPrescaler)-1)"!]U), /* STM Clock divider */
[!ELSE!][!//
    (Gpt_PrescalerType)([!"num:i(number(GptChannelPrescaler)-1)"!]U), /* EMIOS Clock divider */
[!ENDIF!][!//
#if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
[!IF "contains(GptHwChannel, 'STM')"!][!//
[!IF "GptStmChannelClkSrc = 'GPT_STM_SYSTEMCLOCK'"!][!//
    (Gpt_PrescalerType)0U, /* STM clock source - System clock is selected */
[!ELSEIF "GptStmChannelClkSrc = 'GPT_STM_FXOSCCLOCK'"!][!//
    (Gpt_PrescalerType)1U, /* STM clock source - FXOSC clock is selected */
[!ENDIF!][!//
[!ELSE!][!//
    (Gpt_PrescalerType)0U, /* STM clock source - Unused*/
[!ENDIF!][!//
#endif
[!ENDCODE!][!//
[!ENDSELECT!][!//
[!ENDNOCODE!]
[!ENDMACRO!]

[!ENDIF!] /* Avoid multiple inclusion ENDIF */
[!ENDNOCODE!]