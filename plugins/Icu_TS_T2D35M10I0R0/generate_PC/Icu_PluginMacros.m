[!NOCODE!][!//
/**
  @file    Icu_PluginMacros.m
  @version 1.0.0

  @brief   AUTOSAR Icu - plugin check.
  @details Version checks.

  Project AUTOSAR 4.2 MCAL
  Patform PA
  Peripheral eMIOS SIUL2 WKPU
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
[!// MACRO for creating the mapping between hardware channels and logical channels
[!MACRO "ICU_VARIABLES"!]
[!NOCODE!]
    [!VAR "ICU_CHANNELS"   = "num:i(160)"!]
    [!VAR "OutNumIcuChannels" = "num:i(count(IcuChannel/*))"!]
    [!VAR "OutNumIcuChannelsUsingeMios" = "0"!]
    [!VAR "OutNumIcuChannelsUsingSiul2"  = "0"!]
    [!VAR "OutNumIcuChannelsUsingWkpu"  = "0"!]

    [!LOOP "IcuChannel/*"!][!/*
        [!//Update variables storing number of Icu channels using either eMios, Siul2 or Wkpu IP
        */!][!IF "contains(IcuHwIP,'EMIOS')"!][!/*
            */!][!VAR "OutNumIcuChannelsUsingeMios" = "$OutNumIcuChannelsUsingeMios + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'SIUL2')"!][!/*
            */!][!VAR "OutNumIcuChannelsUsingSiul2" = "$OutNumIcuChannelsUsingSiul2 + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'WKPU')"!][!/*
            */!][!VAR "OutNumIcuChannelsUsingWkpu" = "$OutNumIcuChannelsUsingWkpu + 1"!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDLOOP!]

    [!VAR "EMIOS_1_CHANNELS_START_INDEX"   = "num:i(32)"!]
    [!VAR "EMIOS_2_CHANNELS_START_INDEX"   = "num:i(64)"!]
    [!VAR "IRQ_CHANNELS_START_INDEX"   = "num:i(96)"!]
    [!VAR "WKPU_CHANNELS_START_INDEX"   = "num:i(128)"!]
    [!VAR "ICU_CHANNELS"   = "num:i(160)"!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!// MACRO for creating Siul2 global configuration paramters
[!MACRO "ICU_SIUL2_GLOBAL_CONFIGURATION"!][!/*
    */!][!VAR "MacSiul2ChannelsExists"="0"!][!/*
    */!][!LOOP "IcuChannel/*"!][!/*
    */!][!IF "contains(IcuHwIP,'SIUL2')"!][!/*
        */!][!VAR "MacSiul2ChannelsExists"="1"!][!/*
    */!][!ENDIF!][!/*
    */!][!ENDLOOP!][!/*
        */!][!IF "$MacSiul2ChannelsExists != 0 "!][!/*
    */!][!IF "node:exists(IcuSiul2/IcuSiul2_0/IcuEXT_ISR_InterruptFilterClockPrescaler)"!][!/*
        */!][!IF "node:exists(IcuSiul2/IcuSiul2_0/IcuEXT_ISR_AlternateInterruptFilterClockPrescaler)"!](Icu_Siul2_GlobalConfigurationType)(((Icu_Siul2_GlobalConfigurationType)[!"node:value(IcuSiul2/IcuSiul2_0/IcuEXT_ISR_AlternateInterruptFilterClockPrescaler)"!]U << ICU_SIUL2_INT_ALTERNATE_FILTER_CLOCK_PRESCALER_GC_SHIFT) |[!/*
            */!](Icu_Siul2_GlobalConfigurationType)[!"node:value(IcuSiul2/IcuSiul2_0/IcuEXT_ISR_InterruptFilterClockPrescaler)"!]U),[!/*
        */!][!ELSE!](Icu_Siul2_GlobalConfigurationType)[!"node:value(IcuSiul2/IcuSiul2_0/IcuEXT_ISR_InterruptFilterClockPrescaler)"!]U,[!/*
        */!][!ENDIF!][!/*
    */!][!ELSE!](Icu_Siul2_GlobalConfigurationType)0U,[!/*
    */!][!ENDIF!][!/*
    */!][!ELSE!](Icu_Siul2_GlobalConfigurationType)0U,[!/*
    */!][!ENDIF!][!/*
*/!][!ENDMACRO!]

[!// MACRO for get prescaler for Master Bus
[!MACRO "GetMasterPrescaler", "parameMiosBus", "parameMiosChannel"!]
[!NOCODE!]
    [!IF "($parameMiosBus = 'EMIOS_BUS_A')"!]
        [!VAR "eMiosMaster" = "23"!]
    [!ELSEIF "($parameMiosBus = 'EMIOS_BUS_F')"!]
        [!VAR "eMiosMaster" = "22"!]
    [!ELSEIF "($parameMiosBus = 'EMIOS_BUS_DIVERSE')"!]
        [!IF "($parameMiosChannel < 8)"!][!//
            [!VAR "eMiosMaster" = "0"!]
        [!ELSEIF "($parameMiosChannel < 16)"!]
            [!VAR "eMiosMaster" = "8"!]
        [!ELSEIF "($parameMiosChannel < 24)"!]
            [!VAR "eMiosMaster" = "16"!]
        [!ELSE!]
            [!VAR "eMiosMaster" = "24"!]
        [!ENDIF!]
    [!ENDIF!]
    [!VAR "MacIsRightMasterBus" = "'false'"!]
    [!VAR "NumIcueMiosMasterBus" = "num:i(count(node:ref(IcueMiosChannelRef)/../../IcueMiosMasterBus/*))"!]
    [!IF "num:i($NumIcueMiosMasterBus)>0"!]
        [!LOOP "node:ref(IcueMiosChannelRef)/../../IcueMiosMasterBus/*"!]
            [!VAR "MastereMiosIdx" = "substring-after(eMiosMasterBus,'CH_')"!]
            [!IF "(num:i($eMiosMaster) = $MastereMiosIdx)"!]
                [!VAR "PrescalerVal" = "node:value(MasterBusPrescaler)"!]
                [!VAR "MacIsRightMasterBus" = "'true'"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$MacIsRightMasterBus = 'false'"!]
            [!ERROR!] Selecting eMios Master Bus channel correspond to [!"$parameMiosBus"!] is wrong[!ENDERROR!]
        [!ENDIF!]
    [!ELSE!]
        [!ERROR!] eMios Master Bus channel configuration correspond to [!"$parameMiosBus"!] not exist[!ENDERROR!]
    [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!// MACRO for get prescaler alternate for Master Bus
[!MACRO "GetMasterPrescaler_Alternate", "parameMiosBus", "parameMiosChannel"!]
[!NOCODE!]
    [!IF "($parameMiosBus = 'EMIOS_BUS_A')"!][!//
        [!VAR "eMiosMaster" = "23"!]
    [!ELSEIF "($parameMiosBus = 'EMIOS_BUS_F')"!][!//
        [!VAR "eMiosMaster" = "22"!]
    [!ELSEIF "($parameMiosBus = 'EMIOS_BUS_DIVERSE')"!][!//
        [!IF "($parameMiosChannel < 8)"!][!//
            [!VAR "eMiosMaster" = "0"!]
        [!ELSEIF "($parameMiosChannel < 16)"!][!//
            [!VAR "eMiosMaster" = "8"!]
        [!ELSEIF "($parameMiosChannel < 24)"!][!//
            [!VAR "eMiosMaster" = "16"!]
        [!ELSE!]
            [!VAR "eMiosMaster" = "24"!]
        [!ENDIF!][!//
    [!ENDIF!][!//
    [!VAR "MacIsRightMasterBus" = "'false'"!]
    [!VAR "NumIcueMiosMasterBus" = "num:i(count(node:ref(IcueMiosChannelRef)/../../IcueMiosMasterBus/*))"!]
    [!IF "num:i($NumIcueMiosMasterBus)>0"!]
        [!LOOP "node:ref(IcueMiosChannelRef)/../../IcueMiosMasterBus/*"!]
            [!VAR "MastereMiosIdx" = "substring-after(eMiosMasterBus,'CH_')"!]
            [!IF "(num:i($eMiosMaster) = $MastereMiosIdx)"!]
                [!VAR "PrescalerVal_Alternate" = "node:value(MasterBusPrescaler_Alternate)"!]
                [!VAR "MacIsRightMasterBus" = "'true'"!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!IF "$MacIsRightMasterBus = 'false'"!]
            [!ERROR!] Selecting eMios Master Bus channel correspond to  [!"$parameMiosBus"!] is wrong[!ENDERROR!]
        [!ENDIF!]
    [!ELSE!]
        [!ERROR!] eMios Master Bus channel configuration correspond to [!"$parameMiosBus"!] not exist[!ENDERROR!]
    [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!// MACRO for creating the mapping between hardware channels and logical channels
[!MACRO "ICU_GENERATE_HW_MAPPING","VARIANT", "MISRA_REF"!]
[!SELECT "IcuConfigSet"!]
/*
 * @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
CONST(Icu_ChannelType,ICU_CONST) Icu_InitHWMap_[!"$VARIANT"!][ICU_MAX_HW_CHANNELS] = {[!CR!][!/*
   */!][!FOR "Idx" = "0" TO "$ICU_CHANNELS - 1"!][!/*
        */!][!VAR "Found" = "'false'"!][!/*
        */!][!LOOP "./IcuChannel/*"!][!/*
            */!][!IF "contains(IcuHwIP,'EMIOS')"!][!/*
                */!][!IF "(node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule)) = 'EMIOS_0'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcueMiosChannelRef)/IcueMiosChannel),'CH_')"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule)) = 'EMIOS_1'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcueMiosChannelRef)/IcueMiosChannel),'CH_')+$EMIOS_1_CHANNELS_START_INDEX"!][!/*
                */!][!ELSEIF "(node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule)) = 'EMIOS_2'"!][!/*
                    */!][!VAR "ch" = "substring-after((node:ref(IcueMiosChannelRef)/IcueMiosChannel),'CH_')+$EMIOS_2_CHANNELS_START_INDEX"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "contains(IcuHwIP,'SIUL2')"!][!/*
                */!][!VAR "ch" = "substring-after((node:ref(IcuSiul2ChannelRef)/IcuSiul2Channel),'IRQ_CH_')+$IRQ_CHANNELS_START_INDEX"!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "contains(IcuHwIP,'WKPU')"!][!/*
                */!][!VAR "ch" = "substring-after((node:ref(IcuWkpuChannelRef)/IcuWkpuChannel),'WKPU_CH_')+$WKPU_CHANNELS_START_INDEX"!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "num:i($ch)=$Idx"!][!/*
                */!]  [!"node:name(.)"!][!/*
                */!][!VAR "Found" = "'true'"!][!/*
            */!][!ENDIF!][!/*
            */!][!ENDLOOP!][!/*
            */!][!IF "$Found='false'"!][!/*
          */!]  NoIcuChannel[!/*
           */!][!ENDIF!][!/*

        */!][!IF "$Idx < $ICU_CHANNELS - 1"!],[!ELSE!] [!ENDIF!][!/*

        */!][!IF "$Idx < $EMIOS_1_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to EMIOS_0_CH_[!"$Idx"!] */[!CR!][!/*
        */!][!ELSEIF "$Idx < $EMIOS_2_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to EMIOS_1_CH_[!"num:i($Idx - $EMIOS_1_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$Idx < $IRQ_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to EMIOS_2_CH_[!"num:i($Idx - $EMIOS_2_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$Idx < $WKPU_CHANNELS_START_INDEX"!][!/*
            */!] /* maps to IRQ_CH_[!"num:i($Idx - $IRQ_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ELSEIF "$Idx < $ICU_CHANNELS"!][!/*
            */!] /* maps to WKPU_CH_[!"num:i($Idx - $WKPU_CHANNELS_START_INDEX)"!] */[!CR!][!/*
        */!][!ENDIF!][!/*
    */!][!ENDFOR!][!/*
    */!]};
[!ENDSELECT!]
[!ENDMACRO!]

[!// MACRO for generating the notification function prototype
[!MACRO "ICU_GENERATE_NOTIFICATION_FUNCTIONS_PROTOTYPE", "MISRA_REF"="'Icu_PBCfg_c_5'"!]
[!NOCODE!]
    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "Found" = "'false'"!]
    [!SELECT "IcuConfigSet"!]
     [!LOOP "./IcuChannel/*"!]
        [!VAR "a" = "IcuMeasurementMode"!]
        [!IF "(contains($a,'ICU_MODE_TIMESTAMP') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL_PTR') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL'))"!]
            [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
            [!VAR "MacInnerLoopCounter" = "0"!]
            [!VAR "MacMatchcounter" = "0"!]
            [!VAR "MacNotification" = "IcuTimestampMeasurement/IcuTimestampNotification"!]
            [!LOOP "../../../*/IcuChannel/*"!] [!//All notifications from all configurations
                [!VAR "a" = "IcuMeasurementMode"!]
                [!IF "(contains($a,'ICU_MODE_TIMESTAMP') and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL_PTR')and (IcuTimestampMeasurement/IcuTimestampNotification != 'NULL'))"!]
                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                        [!IF "($MacNotification = IcuTimestampMeasurement/IcuTimestampNotification)"!]
                             [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$MacMatchcounter = 1"!]
                  [!IF "$Found = 'false'"!]
                      [!VAR "Found" = "'true'"!]
                      [!CODE!]
/**
 *   @brief External Notifications for Timestamp
 */[!/*
                       */!][!CR!][!ENDCODE!]
                 [!ENDIF!]
                 [!CODE!]
/**
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.8 Maybe used in multiple configuration variants
 */
extern FUNC (void, ICU_CODE) [!"IcuTimestampMeasurement/IcuTimestampNotification"!](void);[!CR!]
                [!ENDCODE!][!//
            [!ENDIF!]
        [!ENDIF!]
     [!ENDLOOP!]
    [!ENDSELECT!]

    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "Found" = "'false'"!]
    [!SELECT "IcuConfigSet"!]
     [!LOOP "./IcuChannel/*"!]
        [!VAR "a" = "IcuMeasurementMode"!]
        [!IF "(contains($a,'ICU_MODE_SIGNAL_EDGE_DETECT') and (IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR'))"!]
            [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
            [!VAR "MacInnerLoopCounter" = "0"!]
            [!VAR "MacMatchcounter" = "0"!]
            [!VAR "MacNotification" = "IcuSignalEdgeDetection/IcuSignalNotification"!]
            [!LOOP "../../../*/IcuChannel/*"!] [!//All notifications from all configurations
                [!VAR "a" = "IcuMeasurementMode"!]
                [!IF "(contains($a,'ICU_MODE_SIGNAL_EDGE_DETECT') and (IcuSignalEdgeDetection/IcuSignalNotification != 'NULL_PTR'))"!]
                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                        [!IF "($MacNotification = IcuSignalEdgeDetection/IcuSignalNotification)"!]
                             [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$MacMatchcounter = 1"!]
                [!IF "$Found = 'false'"!]
                    [!VAR "Found" = "'true'"!]
                     [!CODE!][!//
[!CR!]/**
 *   @brief External Notifications for Edge Detection
 */[!/*
          */!][!CR!][!ENDCODE!]
                [!ENDIF!]
                [!CODE!]
/**
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.8 Maybe used in multiple configuration variants
 */
extern FUNC (void, ICU_CODE) [!"IcuSignalEdgeDetection/IcuSignalNotification"!](void);[!CR!]
                [!ENDCODE!][!//
            [!ENDIF!]
        [!ENDIF!]
     [!ENDLOOP!]
    [!ENDSELECT!]

    [!VAR "MacOuterLoopCounter" = "0"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "Found" = "'false'"!]
    [!SELECT "IcuConfigSet"!]
     [!LOOP "./IcuChannel/*"!]
        [!IF "node:exists(IcuOverflowNotification)"!]
         [!IF "(IcuOverflowNotification != 'NULL_PTR') and (IcuOverflowNotification != 'NULL')"!]
            [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
            [!VAR "MacInnerLoopCounter" = "0"!]
            [!VAR "MacMatchcounter" = "0"!]
            [!VAR "MacNotification" = "IcuOverflowNotification"!]
            [!LOOP "../../../*/IcuChannel/*"!] [!//All notifications from all configurations
         [!IF "node:exists(IcuOverflowNotification)"!]
                [!IF "(IcuOverflowNotification != 'NULL_PTR')and (IcuOverflowNotification != 'NULL')"!]
                    [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                    [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                        [!IF "($MacNotification = IcuOverflowNotification)"!]
                            [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
         [!ENDIF!]
            [!ENDLOOP!]
            [!IF "$MacMatchcounter = 1"!]
                  [!IF "$Found = 'false'"!]
                      [!VAR "Found" = "'true'"!]
                      [!CODE!]
/**
 *   @brief  Overflow notification handlers
 */[!/*
                          */!][!CR!][!ENDCODE!]
                   [!ENDIF!]
                   [!CODE!]
/**
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.8 Maybe used in multiple configuration variants
 */
extern FUNC (void, ICU_CODE) [!"IcuOverflowNotification"!](void);[!CR!]
                  [!ENDCODE!][!//
                [!ENDIF!]
            [!ENDIF!]
          [!ENDIF!]
     [!ENDLOOP!]
    [!ENDSELECT!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!// MACRO for creating the configuration pointer(s)
[!MACRO "ICU_GENERATE_CONFIGURATION","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'"!]
[!SELECT "IcuConfigSet"!][!//
[!VAR "count" = "count(IcuChannel/*)"!][!//
[!VAR "Idx" = "1"!][!//
[!VAR "MacLoopVar"="0"!][!//
/*
 *  @brief    [!"$VARIANT"!] Default Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_ChannelConfigType, ICU_CONST) Icu_InitChannel_[!"$VARIANT"!][[!"num:i(count(IcuChannel/*))"!]]=
 {
 [!FOR "x" = "0" TO "num:i(count(IcuChannel/*))"!][!/*
  */!][!LOOP "IcuChannel/*"!][!/*
    */!][!VAR "Loop"="num:i($MacLoopVar)"!][!/*
    */!][!IF "IcuChannelId = $Loop"!][!/*
    */!][!WS "8"!]/* [!"node:name(.)"!] */
        {[!CR!][!/*
        */!][!WS "12"!]([!IF "IcuWakeupCapability"!]((Icu_ParamType)ICU_WAKEUP_CAPABLE << ICU_WAKEUP_SHIFT) | \[!CR!][!WS "12"!][!ENDIF!][!/*
        */!](Icu_ParamType)((Icu_ParamType)[!"IcuDefaultStartEdge"!] << ICU_EDGE_PARAM_SHIFT)),[!CR!][!/*

        */!][!IF "contains(IcuHwIP,'EMIOS')"!][!/*
                */!][!IF "not(contains(ecu:list(concat('Icu.ChannelType.',(concat((concat(node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule),'_')),node:value(node:ref(IcueMiosChannelRef)/IcueMiosChannel))))),node:value(IcuMeasurementMode)))"!][!/*
                    */!][!ERROR!] [!"node:name(.)"!] from channel [!"node:name(../.)"!] does not support [!"node:value(IcuMeasurementMode)"!] mode [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'SIUL2')"!][!/*
                */!][!IF "not(contains(ecu:list(concat('Icu.ChannelType.',node:value(node:ref(IcuSiul2ChannelRef)/IcuSiul2Channel))),node:value(IcuMeasurementMode)))"!][!/*
                    */!][!ERROR!] [!"node:name(.)"!] from channel [!"node:name(../.)"!] does not support [!"node:value(IcuMeasurementMode)"!] mode [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'WKPU')"!][!/*
                */!][!IF "not(contains(ecu:list(concat('Icu.ChannelType.',node:value(node:ref(IcuWkpuChannelRef)/IcuWkpuChannel))),node:value(IcuMeasurementMode)))"!][!/*
                    */!][!ERROR!] [!"node:name(.)"!] from channel [!"node:name(../.)"!] does not support [!"node:value(IcuMeasurementMode)"!] mode [!ENDERROR!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
            */!][!WS "12"!](Icu_MeasurementModeType)[!"IcuMeasurementMode"!],[!CR!][!/*

            */!][!WS "12"!](Icu_MeasurementSubModeType)[!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'"!]0U[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!"IcuTimestampMeasurement/IcuTimestampMeasurementProperty"!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!"IcuSignalMeasurement/IcuSignalMeasurementProperty"!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_EDGE_COUNTER'"!][!"IcuDefaultStartEdge"!][!ENDIF!],[!CR!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!WS "12"!]NULL_PTR[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_EDGE_COUNTER'"!][!WS "12"!]NULL_PTR[!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_TIMESTAMP'"!][!/*
                */!][!IF "IcuTimestampMeasurement/IcuTimestampNotification!='NULL_PTR'"!][!/*
                    */!][!WS "12"!]&[!"IcuTimestampMeasurement/IcuTimestampNotification"!][!/*
                */!][!ELSE!][!/*
                    */!][!WS "12"!]NULL_PTR[!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
            */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_EDGE_DETECT'"!][!/*
                */!][!IF "IcuSignalEdgeDetection/IcuSignalNotification!='NULL_PTR'"!][!/*
                    */!][!WS "12"!]&[!"IcuSignalEdgeDetection/IcuSignalNotification"!][!/*
                */!][!ELSE!][!/*
                    */!][!WS "12"!]NULL_PTR[!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!],
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
[!/*     */!](Mcl_ChannelType)[!IF "((IcuMeasurementMode = 'ICU_MODE_TIMESTAMP') or (IcuMeasurementMode = 'ICU_MODE_SIGNAL_MEASUREMENT')) and IcuDMAChannelEnable = 'true'"!][!/*
              */!][!WS "12"!][!"node:value(node:ref(IcuDMAChannelRef)/MclDMAChannelId)"!],[!/* MCL DMA logical Channel
              */!][!IF "node:exists(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif)"!] [!/* Validation for Notification function
                 */!][!IF "(node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) = 'NULL_PTR') or (node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) = 'NULL')"!][!/*
                        */!][!ERROR!] Notification need to be configured for DMA Channels that are linked to Icu Channels. The name of the notification shall be <IcuChannelName>_DmaNotification e.g [!"node:name(.)"!]_DmaNotification[!ENDERROR!][!/*
                */!][!ELSEIF "node:value(node:ref(IcuDMAChannelRef)/MclDmaTransferCompletionNotif) != concat(node:name(.),'_DmaNotification')"!][!/*
                      */!][!ERROR!] Notification name must be [!"node:name(.)"!]_DmaNotification[!ENDERROR!][!/*
                  */!][!ENDIF!][!/*
                */!][!ELSE!][!/*
                  */!][!ERROR!] Notification need to be configured for DMA Channels that are linked to Icu Channels [!ENDERROR!][!/*
              */!][!ENDIF!]
                [!IF "node:ref(IcuDMAChannelRef)/DmaSource0 != 'NOT_USED'"!][!/* Validation for DMA source*/!]
                    [!IF "(text:split(node:value(node:ref(IcuDMAChannelRef)/DmaSource0),'_')[2] != text:split(node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule), '_')[2])"!]
                        [!ERROR!] Dma Source need to be configured - For [!"node:ref(IcuDMAChannelRef)"!] set DMA Channel Enable[!ENDERROR!]
                    [!ELSE!]
                        [!VAR "HwEmios" = "text:split(node:value(node:ref(IcueMiosChannelRef)/IcueMiosChannel), '_')[2]"!]
                        [!VAR "DmaSource" = "substring-after(text:split(node:value(node:ref(IcuDMAChannelRef)/DmaSource0),'_')[3], 'ch')"!]
                        [!IF "num:i($HwEmios) = 0"!]
                             [!IF "$DmaSource != 'A'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 1"!]
                             [!IF "$DmaSource != 'B'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 9"!]
                             [!IF "$DmaSource != 'C'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 10"!]
                             [!IF "$DmaSource != 'D'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 17"!]
                             [!IF "$DmaSource != 'E'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 18"!]
                             [!IF "$DmaSource != 'F'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 25"!]
                             [!IF "$DmaSource != 'G'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 26"!]
                             [!IF "$DmaSource != 'F'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ELSEIF "node:ref(IcuDMAChannelRef)/DmaSource1 != 'NOT_USED'"!]
                    [!IF "(text:split(node:value(node:ref(IcuDMAChannelRef)/DmaSource1),'_')[2] != text:split(node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule), '_')[2])"!]
                        [!ERROR!] Dma Source need to be configured - For [!"node:ref(IcuDMAChannelRef)"!] set DMA Channel Enable[!ENDERROR!]
                    [!ELSE!]
                        [!VAR "HwEmios" = "text:split(node:value(node:ref(IcueMiosChannelRef)/IcueMiosChannel), '_')[2]"!]
                        [!VAR "DmaSource" = "substring-after(text:split(node:value(node:ref(IcuDMAChannelRef)/DmaSource1),'_')[3], 'ch')"!]
                        [!IF "num:i($HwEmios) = 0"!]
                             [!IF "$DmaSource != 'A'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 1"!]
                             [!IF "$DmaSource != 'B'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 9"!]
                             [!IF "$DmaSource != 'C'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 10"!]
                             [!IF "$DmaSource != 'D'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 17"!]
                             [!IF "$DmaSource != 'E'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 18"!]
                             [!IF "$DmaSource != 'F'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 25"!]
                             [!IF "$DmaSource != 'G'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                        [!IF "num:i($HwEmios) = 26"!]
                             [!IF "$DmaSource != 'F'"!]
                                [!ERROR!] Dma Source need to be configured Corectly with source [!"$DmaSource"!] in DMAMUX[!ENDERROR!]
                             [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ELSE!][!WS "12"!]NoMclDmaChannel,[!/*
      */!][!ENDIF!]
#endif
#if (ICU_OVERFLOW_NOTIFICATION_API == STD_ON)
[!/*   */!][!IF "node:exists(IcuOverflowNotification)"!][!/*
            */!][!WS "12"!][!IF "IcuOverflowNotification!= 'NULL_PTR'"!]&[!ENDIF!][!"IcuOverflowNotification"!][!/*
        */!][!ELSE!][!/*
            */!][!WS "12"!]NULL_PTR[!/*
        */!][!ENDIF!],
#endif  /* ICU_OVERFLOW_NOTIFICATION_API */
#if (ICU_REPORT_WAKEUP_SOURCE == STD_ON)
            (Icu_WakeupValueType)[!/*
            */!][!IF "IcuWakeupCapability"!][!/*
                */!]((uint32)((uint32)1U<<[!"as:ref(IcuWakeup/IcuChannelWakeupInfo)/EcuMWakeupSourceId"!]))[!/*
            */!][!ELSE!][!/*
                */!]0U[!/*
            */!][!ENDIF!][!CR!]
#endif /* (ICU_REPORT_WAKEUP_SOURCE == STD_ON) */
        }[!IF "$Idx!=$count"!],[!CR!][!ENDIF!][!/*
        */!][!VAR "Idx" = "$Idx + 1"!][!/*
        */!][!ENDIF!][!/*
  */!][!ENDLOOP!][!/*
*/!][!VAR "MacLoopVar"="$MacLoopVar + 1"!][!/*
*/!][!ENDFOR!][!CR!]
 };

[!ENDSELECT!]
[!ENDMACRO!]

[!// MACRO for creating the eMios configuration pointer(s)
[!MACRO "ICU_GENERATE_IP_CONFIGURATION","VARIANT"="'PB'", "MISRA_REF"="'Icu_PBCfg_c_3'", "MISRA_REF_1"="'Icu_PBCfg_c_4'"!]
[!SELECT "IcuConfigSet"!][!//
[!CALL "ICU_VARIABLES"!][!//
[!IF "num:i($OutNumIcuChannelsUsingeMios)>0"!]
/*
 *  @brief    [!"$VARIANT"!] Default EMIOS Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 *  @violates @ref [!"$MISRA_REF_1"!] violates Misra 1.4 Identifier clash
 */
 CONST(Icu_eMios_ChannelConfigType, ICU_CONST) Icu_eMios_ChannelConfig_[!"$VARIANT"!][[!"num:i($OutNumIcuChannelsUsingeMios)"!]] =
 {
    [!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!][!/*
                */!][!IF "contains(IcuHwIP,'EMIOS')"!]
    /** @brief [!"node:name(.)"!] */
    {
        /** @brief eMios HW Module and Channel used by the Icu channel */[!CR!][!/*
        */!][!VAR "eMiosMod" = "node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule)"!][!/*
        */!][!VAR "eMiosChannal" = "node:value(node:ref(IcueMiosChannelRef)/IcueMiosChannel)"!][!/*
        */!][!WS "8"!]ICU_[!"$eMiosMod"!]_[!"$eMiosChannal"!],
        /** @brief eMios channel configuration parameters */[!CR!][!/*
        */!][!WS "8"!]([!IF "node:ref(IcueMiosChannelRef)/IcuEmiosFreeze"!](Icu_eMios_ControlType)((Icu_eMios_ControlType)(EMIOS_FREEZE_ENABLE << ICU_EMIOS_FREEZE_PARAM_SHIFT)) | \[!CR!][!WS "8"!][!ENDIF!][!/*
        */!][!IF "(contains(node:ref(IcueMiosChannelRef)/IcuEmiosBusSelect,'EMIOS_BUS_INTERNAL_COUNTER'))"!][!/*
            */!](Icu_eMios_ControlType)((Icu_eMios_ControlType)[!"node:value(node:ref(IcueMiosChannelRef)/IcuEmiosPrescaler)"!] << ICU_EMIOS_PRESCALER_PARAM_SHIFT)[!/*
            */!][!IF "../../../IcuNonAUTOSAR/IcuEnableDualClockMode"!][!/*
                */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)[!"node:value(node:ref(IcueMiosChannelRef)/IcuEmiosPrescaler_Alternate)"!] << ICU_EMIOS_PRESC_ALT_PARAM_SHIFT)[!/*
            */!][!ENDIF!][!/*
        */!][!ELSE!][!/*
            */!][!VAR "BusSelect"="node:ref(IcueMiosChannelRef)/IcuEmiosBusSelect"!][!/*
            */!][!VAR "eMiosChannel"="substring-after(node:ref(IcueMiosChannelRef)/IcueMiosChannel,'CH_')"!][!/*
            */!][!CALL "GetMasterPrescaler", "parameMiosBus" = "$BusSelect", "parameMiosChannel" = "$eMiosChannel"!][!/*
            */!][!WS "8"!](Icu_eMios_ControlType)((Icu_eMios_ControlType)[!"$PrescalerVal"!] << ICU_EMIOS_PRESCALER_PARAM_SHIFT)[!/*
            */!][!IF "../../../IcuNonAUTOSAR/IcuEnableDualClockMode"!][!/*
                */!][!CALL "GetMasterPrescaler_Alternate", "parameMiosBus" = "$BusSelect", "parameMiosChannel" = "$eMiosChannel"!][!/*
                */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType) [!"$PrescalerVal_Alternate"!]<< ICU_EMIOS_PRESC_ALT_PARAM_SHIFT)[!/*
            */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)[!"node:value(node:ref(IcueMiosChannelRef)/IcuEmiosDigitalFilter)"!] << ICU_EMIOS_DIG_FILTER_PARAM_SHIFT)[!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)[!"node:value(node:ref(IcueMiosChannelRef)/IcuEmiosBusSelect)"!] << ICU_EMIOS_BUS_SELECT_PARAM_SHIFT)[!/*

        */!][!IF "IcuMeasurementMode='ICU_MODE_SIGNAL_MEASUREMENT'"!][!/*
        */!][!IF "IcuDMAChannelEnable='true'"!][!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)EMIOS_UC_SAIC_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT)[!/*
        */!][!ELSE!][!/*
        */!][!IF "IcuSignalMeasurement/IcuSignalMeasurementProperty='ICU_HIGH_TIME' or IcuSignalMeasurement/IcuSignalMeasurementProperty='ICU_LOW_TIME' or IcuSignalMeasurement/IcuSignalMeasurementProperty='ICU_ACTIVE_TIME'"!][!/*
        */!][!IF "contains(ecu:list(concat('Icu.ChannelType.',(concat((concat(node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule),'_')),node:value(node:ref(IcueMiosChannelRef)/IcueMiosChannel))))),'IPWM')"!][!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)EMIOS_UC_IPWM_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT)[!/*
        */!][!ELSE!][!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)EMIOS_UC_SAIC_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT)[!/*
        */!][!ENDIF!][!/*
        */!][!ELSEIF "(IcuSignalMeasurement/IcuSignalMeasurementProperty ='ICU_DUTY_CYCLE') and ((node:value(node:ref(IcueMiosChannelRef)/IcuUserModeForDutycycle)) = 'IPWM')"!][!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)EMIOS_UC_IPWM_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT)[!/*
        */!][!ELSEIF "(IcuSignalMeasurement/IcuSignalMeasurementProperty ='ICU_DUTY_CYCLE') and ((node:value(node:ref(IcueMiosChannelRef)/IcuUserModeForDutycycle)) = 'SAIC')"!][!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)EMIOS_UC_SAIC_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT)[!/*
        */!][!ELSE!][!/*
        */!][!IF "contains(ecu:list(concat('Icu.ChannelType.',(concat((concat(node:value(node:ref(IcueMiosChannelRef)/../../IcueMiosModule),'_')),node:value(node:ref(IcueMiosChannelRef)/IcueMiosChannel))))), 'IPM')"!][!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)EMIOS_UC_IPM_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT)[!/*
        */!][!ELSE!][!/*
        */!][!CR!][!WS "8"!] | (Icu_eMios_ControlType)((Icu_eMios_ControlType)EMIOS_UC_SAIC_MODE << ICU_EMIOS_UC_MODE_PARAM_SHIFT)[!/*
        */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*
        */!][!ENDIF!][!/*
        */!][!ENDIF!]),[!/*
        */!][!CR!][!WS "8"!](uint8)[!"IcuDefaultStartEdge"!],[!/*
        */!][!IF "(IcuSignalMeasurement/IcuSignalMeasurementProperty = 'ICU_DUTY_CYCLE') and (node:ref(IcueMiosChannelRef)/IcuSignalMeasureWithoutInterrupt = 'true')"!][!/*
        */!][!ERROR!] IcuSignalMeasureWithoutInterrupt do not support for ICU_DUTY_CYCLE [!ENDERROR!][!/*
        */!][!ENDIF!][!/*
        */!][!CR!][!WS "8"!][!IF "node:ref(IcueMiosChannelRef)/IcuSignalMeasureWithoutInterrupt = 'true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannelsUsingeMios))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
 };
/*
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_eMios_IpConfigType, ICU_CONST) Icu_eMiosIcu_IpConfig_[!"$VARIANT"!] =
 {
    /** @brief Number of eMios channels in the Icu configuration */
    (uint8)[!"num:i($OutNumIcuChannelsUsingeMios)"!],
    /** @brief Pointer to the array of eMios enabled Icu channel configurations */
    &Icu_eMios_ChannelConfig_[!"$VARIANT"!]
 };

[!ELSE!]
    /** @brief No eMios channels configured */
[!ENDIF!]

[!IF "num:i($OutNumIcuChannelsUsingSiul2)>0"!]
/*
 *  @brief    [!"$VARIANT"!] Default SIUL2 Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
CONST(Icu_Siul2_ChannelConfigType, ICU_CONST) Icu_Siul2_ChannelConfig_[!"$VARIANT"!][[!"num:i($OutNumIcuChannelsUsingSiul2)"!]] =
{
    [!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!][!/*
                */!][!IF "contains(IcuHwIP,'SIUL2')"!][!/*
    */!][!WS "4"!]/** @brief [!"node:name(.)"!] */
    {
        /** @brief Siul2 HW Module and Channel used by the Icu channel */[!CR!][!/*
        */!][!WS "8"!]ICU_[!"node:value(node:ref(IcuSiul2ChannelRef)/IcuSiul2Channel)"!],
        /** @brief Siul2 channel configuration parameters */[!CR!][!/*
        */!][!IF "node:ref(IcuSiul2ChannelRef)/Icu_EXT_ISR_IFERDigitalFilter = 'true'"!][!/*
        */!][!WS "8"!]((Icu_Siul2_ControlType)ICU_SIUL2_INT_FILTER_ENABLE_PARAM_MASK[!/*
        */!][!CR!][!WS "8"!] | (Icu_Siul2_ControlType)((Icu_Siul2_ControlType)[!"node:value(node:ref(IcuSiul2ChannelRef)/Icu_EXT_ISR_IFMCDigitalFilter)"!]U << ICU_SIUL2_INT_FILTER_COUNTER_PARAM_SHIFT)),[!/*
        */!][!ELSE!][!WS "8"!](Icu_Siul2_ControlType)0U,[!/*
        */!][!ENDIF!][!/*
        */!][!CR!][!WS "8"!](uint8)[!"IcuDefaultStartEdge"!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannelsUsingSiul2))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
};
/*
 *  @brief    [!"$VARIANT"!] Default SIUL2 Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
CONST(Icu_Siul2_IpConfigType, ICU_CONST) Icu_Siul2Icu_IpConfig_[!"$VARIANT"!] =
{
    /** @brief Number of Siul2 channels in the Icu configuration */
    (uint8)[!"num:i($OutNumIcuChannelsUsingSiul2)"!],
    /** @brief The Siul2 global configuration paramters */
    [!CALL "ICU_SIUL2_GLOBAL_CONFIGURATION"!]
    /** @brief Pointer to the array of Siul2 enabled Icu channel configurations */
    &Icu_Siul2_ChannelConfig_[!"$VARIANT"!]
};
[!ELSE!]
    /** @brief No Siul2 channels configured */
[!ENDIF!]

[!IF "num:i($OutNumIcuChannelsUsingWkpu)>0"!]
/*
 *  @brief    [!"$VARIANT"!] Default WKPU Configuration
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_Wkpu_ChannelConfigType, ICU_CONST) Icu_Wkpu_ChannelConfig_[!"$VARIANT"!][[!"num:i($OutNumIcuChannelsUsingWkpu)"!]] =
 {
    [!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!][!/*
                */!][!IF "contains(IcuHwIP,'WKPU')"!][!/*
    */!][!WS "4"!]/** @brief [!"node:name(.)"!] */
    {
        /** @brief Wkpu HW Module and Channel used by the Icu channel */[!CR!][!/*
        */!][!WS "8"!]ICU_[!"node:value(node:ref(IcuWkpuChannelRef)/IcuWkpuChannel)"!],
        /** @brief Wkpu Default Start Edge */[!CR!][!/*
        */!][!WS "8"!](uint8)[!"IcuDefaultStartEdge"!],
        /** @brief Siul2 channel configuration parameters */[!CR!][!/*
        */!][!WS "8"!](Icu_Wkpu_ControlType)0U[!/*
        */!][!IF "node:ref(IcuWkpuChannelRef)/IcuWKPU_ISR_WIPUER"!][!/*
            */!][!CR!][!WS "8"!] | (Icu_Wkpu_ControlType)((Icu_Wkpu_ControlType)ICU_WKPU_PULLUP_ENABLE << ICU_WKPU_PULLUP_ENABLE_PARAM_SHIFT)[!CR!][!/*
        */!][!ENDIF!][!/*
        */!][!IF "node:ref(IcuWkpuChannelRef)/Icu_EXT_ISR_WIFERDigitalFilter"!][!/*
            */!][!CR!][!WS "8"!] | (Icu_Wkpu_ControlType)((Icu_Wkpu_ControlType)ICU_WKPU_INT_FILTER_ENABLE << ICU_WKPU_INT_FILTER_ENABLE_PARAM_SHIFT)[!CR!][!/*
        */!][!ENDIF!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannelsUsingWkpu))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!][!/*
                */!][!ENDIF!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
 };
/*
 *  @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_Wkpu_IpConfigType, ICU_CONST) Icu_WkpuIcu_IpConfig_[!"$VARIANT"!] =
 {
    /** @brief Number of Wkpu channels in the Icu configuration */
    (uint8)[!"num:i($OutNumIcuChannelsUsingWkpu)"!],
    /** @brief Pointer to the array of Wkpu enabled Icu channel configurations */
    &Icu_Wkpu_ChannelConfig_[!"$VARIANT"!]
 };
[!ELSE!]
    /** @brief No Wkpu channels configured */
[!ENDIF!]

/*
 * @brief   Icu channels IP related configuration array
 * @violates @ref [!"$MISRA_REF"!] violates Misra 8.10 external ... could be made static
 */
 CONST(Icu_IpChannelConfigType, ICU_CONST) Icu_IpChannelConfig_[!"$VARIANT"!][[!"num:i(count(IcuChannel/*))"!]] =
 {
    [!VAR "CurIcuChannelUsingeMios" = "0"!][!/*
    */!][!VAR "CurIcuChannelUsingSiul2"  = "0"!][!/*
    */!][!VAR "CurIcuChannelUsingWkpu"  = "0"!][!/*
    */!][!VAR "comma" = "1"!][!/*
    */!][!FOR "varCounter" = "0" TO "$OutNumIcuChannels"!][!/*
        */!][!LOOP "IcuChannel/*"!][!/*
            */!][!IF "IcuChannelId = $varCounter"!]
    /** @brief [!"@name"!] */
    {[!/*
        */!][!IF "contains(IcuHwIP,'EMIOS')"!]
        /** @brief IP type of this channel */
        ICU_EMIOS_CHANNEL,
        /** @brief Index in the configuration table of the eMios channels */
        (uint8)[!"num:i($CurIcuChannelUsingeMios)"!],[!/*
        */!][!VAR "CurIcuChannelUsingeMios" = "$CurIcuChannelUsingeMios + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'SIUL2')"!]
        /** @brief IP type of this channel */
        ICU_SIUL2_CHANNEL,
        /** @brief Index in the configuration table of the Siul2 channels */
        (uint8)[!"num:i($CurIcuChannelUsingSiul2)"!],[!/*
        */!][!VAR "CurIcuChannelUsingSiul2" = "$CurIcuChannelUsingSiul2 + 1"!][!/*
        */!][!ELSEIF "contains(IcuHwIP,'WKPU')"!]
        /** @brief IP type of this channel */
        ICU_WKPU_CHANNEL,
        /** @brief Index in the configuration table of the Ukpu channels */
        (uint8)[!"num:i($CurIcuChannelUsingWkpu)"!],[!/*
        */!][!VAR "CurIcuChannelUsingWkpu" = "$CurIcuChannelUsingWkpu + 1"!][!/*
        */!][!ENDIF!]
    }[!IF "(num:i($comma))<(num:i($OutNumIcuChannels))"!],[!ENDIF!][!VAR "comma"="$comma + 1"!][!CR!][!/*
            */!][!ENDIF!][!/*
        */!][!ENDLOOP!][!/*
    */!][!ENDFOR!]
 };
[!ENDSELECT!]
[!ENDMACRO!]

[!ENDNOCODE!]