[!AUTOSPACING!]
[!CODE!]
/**
*   @file       Pwm_PBcfg.c
*   @implements Pwm_PBcfg.c_Artifact
*   @version    1.0.0
*
*   @brief      AUTOSAR Pwm - Pwm post-build configuration file.
*   @details    Post-build configuration structure instances.
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios
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

[!NOCODE!][!//
[!INCLUDE "Pwm_VersionCheck_Src_PB.m"!][!//
[!ENDNOCODE!][!//

[!NOCODE!]

/* Variable storing number of Emios Modules available on the current platform */
[!VAR "numeMiosModules" = "ecu:get('Pwm.Num_eMios_Hw_Modules')"!]

[!MACRO "GenerateeMiosMasterbusPeriodInTicks", "MotorFreq"!]
    [!NOCODE!]
        
        [!VAR "MasterPrescalerVal" = "substring-after(MasterBusPrescaler,'PwmPrescalerDiv')"!]
        [!VAR "MasterPeriod"="MasterBusPeriodDefault"!][!//

        [!VAR "MasterPeriodMax"="16777215"!][!//

        [!IF "MasterBusPeriodInTicks"!][!//
            [!VAR "OutMasterPeriodTicks"="$MasterPeriod"!][!//
        [!ELSE!][!//
            [!VAR "OutMasterPeriodTicks"="$MasterPeriod * ($MotorFreq div $MasterPrescalerVal)"!][!//
        [!ENDIF!][!//
        [!IF "num:i($OutMasterPeriodTicks) < 1"!][!//
            [!ERROR!][!//
The configured period/ticks for master bus [!"PwmeMiosMasterBus"!] on [!"../../PwmeMiosModule"!] in channel config set [!"name(../../../../.)"!] is smaller than 1 tick: [!"$OutMasterPeriodTicks"!]
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm Channel clock tree settings.
            [!ENDERROR!][!//
        [!ENDIF!][!//
        [!IF "num:i($OutMasterPeriodTicks) > $MasterPeriodMax"!][!//
            [!ERROR!][!//
The configured period/ticks for master bus [!"PwmeMiosMasterBus"!] on [!"../../PwmeMiosModule"!] in channel config set [!"name(../../../../.)"!] is larger than [!"$MasterPeriodMax"!] ticks: [!"$MasterPeriod"!]
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm Channel clock tree settings.
            [!ENDERROR!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "GetDaocModulo", "parameMiosBus", "parameMiosChannel", "paramClockRef"!]
    [!NOCODE!]
    [!IF "($parameMiosBus = 'PWM_BUS_A_U32')"!][!//
        [!VAR "eMiosMaster" = "23"!]
    [!ELSEIF "($parameMiosBus = 'PWM_BUS_F_U32')"!][!//
        [!VAR "eMiosMaster" = "22"!]
    [!ELSEIF "($parameMiosBus = 'PWM_BUS_DIVERSE_U32')"!][!//
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
    [!LOOP "node:ref(PwmeMiosChannel)/../../PwmeMiosMasterBus/*"!]
        [!VAR "MastereMiosIdx" = "substring-after(PwmeMiosMasterBus,'Channel_')"!]
        [!IF "(num:i($eMiosMaster) = $MastereMiosIdx)"!][!//
            [!CALL "GenerateeMiosMasterbusPeriodInTicks", "MotorFreq" = "$paramClockRef"!]
            [!VAR "PwmDaocModulo"="$OutMasterPeriodTicks"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "GetMasterMode", "parameMiosBus", "parameMiosChannel"!]
    [!NOCODE!]
    [!IF "($parameMiosBus = 'PWM_BUS_A_U32')"!][!//
        [!VAR "eMiosMaster" = "23"!]
    [!ELSEIF "($parameMiosBus = 'PWM_BUS_F_U32')"!][!//
        [!VAR "eMiosMaster" = "22"!]
    [!ELSEIF "($parameMiosBus = 'PWM_BUS_DIVERSE_U32')"!][!//
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
    [!IF "($parameMiosBus = 'PWM_BUS_INTERNAL_COUNTER_U32')"!][!//
        [!VAR "MasterBusMode" = "(num:i(0))"!]
    [!ELSE!]
        [!LOOP "node:ref(PwmeMiosChannel)/../../PwmeMiosMasterBus/*"!]
            [!VAR "MastereMiosIdx" = "substring-after(PwmeMiosMasterBus,'Channel_')"!]
            [!IF "(num:i($eMiosMaster) = $MastereMiosIdx)"!][!//
                [!VAR "MasterBusMode" = "MasterModeSelect"!]
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDIF!][!//
    [!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "GetMasterPeriod", "parameMiosBus", "parameMiosChannel", "paramClockRef"!]
    [!NOCODE!]
    [!IF "($parameMiosBus = 'PWM_BUS_A_U32')"!][!//
        [!VAR "eMiosMaster" = "23"!]
    [!ELSEIF "($parameMiosBus = 'PWM_BUS_F_U32')"!][!//
        [!VAR "eMiosMaster" = "22"!]
    [!ELSEIF "($parameMiosBus = 'PWM_BUS_DIVERSE_U32')"!][!//
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
    [!LOOP "node:ref(PwmeMiosChannel)/../../PwmeMiosMasterBus/*"!]
        [!VAR "MastereMiosIdx" = "substring-after(PwmeMiosMasterBus,'Channel_')"!]
        [!IF "(num:i($eMiosMaster) = $MastereMiosIdx)"!][!//
            [!VAR "PrescalerVal" = "substring-after(MasterBusPrescaler,'PwmPrescalerDiv')"!]
            [!CALL "GenerateeMiosMasterbusPeriodInTicks", "MotorFreq" = "$paramClockRef"!]
            [!VAR "OutPeriod"="$OutMasterPeriodTicks"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "GetMasterPeriod_Alternate", "parameMiosBus", "parameMiosChannel"!]
    [!NOCODE!]
    [!VAR "eMiosMaster" = "30"!]
    [!IF "($parameMiosBus = 'PWM_BUS_A_U32')"!][!//
        [!VAR "eMiosMaster" = "23"!]
    [!ELSEIF "($parameMiosBus = 'PWM_BUS_F_U32')"!][!//
        [!VAR "eMiosMaster" = "22"!]
    [!ELSEIF "($parameMiosBus = 'PWM_BUS_DIVERSE_U32')"!][!//
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
    [!LOOP "node:ref(PwmeMiosChannel)/../../PwmeMiosMasterBus/*"!]
        [!VAR "MastereMiosIdx" = "substring-after(PwmeMiosMasterBus,'Channel_')"!]
        [!IF "(num:i($eMiosMaster) = $MastereMiosIdx)"!][!//
            [!VAR "PrescalerVal_Alternate" = "substring-after(MasterBusPrescaler_Alternate,'PwmPrescalerDiv')"!]
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!ENDNOCODE!]
[!ENDMACRO!]

/* Macro used to validate the period of DAOC channel with master bus */
[!MACRO "ValidatePwmDaocModulo"!]
    [!NOCODE!]
    [!LOOP "PwmChannel/*"!]
        [!IF "(contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC'))"!][!//
            [!IF "((contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_A')) or (contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_F')) or (contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_DIVERSE')))"!][!//
                [!VAR "McuClockRefValue"="node:ref(PwmMcuClockReferencePoint)/McuClockReferencePointFrequency"!][!//
                [!CALL "GenerateeMiosChannelPeriodInTicks", "MotorFreq" = "$McuClockRefValue"!]
                [!VAR "DefaultPeriod" = "$OutPeriodTicks"!]
                [!VAR "MaceMiosBus" = "node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect"!]
                [!VAR "parameMiosChannel" = "substring-after(node:ref(PwmeMiosChannel)/PwmeMiosChannel,'Channel_')"!]
                [!VAR "eMiosChannelId" = "PwmChannelId"!]
                [!VAR "PwmChannelName" = "node:name(.)"!]
        
                [!IF "($MaceMiosBus = 'PWM_BUS_A_U32')"!][!//
                    [!VAR "eMiosMaster" = "23"!]
                [!ELSEIF "($MaceMiosBus = 'PWM_BUS_F_U32')"!][!//
                    [!VAR "eMiosMaster" = "22"!]
                [!ELSEIF "($MaceMiosBus = 'PWM_BUS_DIVERSE_U32')"!][!//
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
        
                [!LOOP "node:ref(PwmeMiosChannel)/../../PwmeMiosMasterBus/*"!]
                    [!VAR "MastereMiosIdx" = "substring-after(PwmeMiosMasterBus,'Channel_')"!]
                    [!IF "(num:i($MastereMiosIdx) = $eMiosMaster)"!][!//
                        [!CALL "GenerateeMiosMasterbusPeriodInTicks", "MotorFreq" = "$McuClockRefValue"!]
                        [!VAR "MasterPeriod" = "$OutMasterPeriodTicks"!]
                            [!IF "(num:i($DefaultPeriod)) > (num:i($MasterPeriod))"!][!//
                                [!ERROR!]For PwmeMiosChannel_[!"$eMiosChannelId"!] of logical channel [!"$PwmChannelName"!] use DAOC mode with external bus, but default period is more than the period of master bus[!ENDERROR!][!//
                            [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDLOOP!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!ENDNOCODE!]
[!ENDMACRO!]

/* Macro used to validate the Emios configured Pwm mode and bus selection */
[!MACRO "ValidatePwmBusSelection"!]
    [!NOCODE!]
    [!FOR "mIdx" = "0" TO "num:i($numeMiosModules - 1)"!]
        [!LOOP "PwmChannel/*"!]
            [!VAR "MatchBus_A_Config" = "0"!][!VAR "MatchBus_B_Config" = "0"!][!VAR "MatchBus_C_Config" = "0"!][!VAR "MatchBus_D_Config" = "0"!][!VAR "MatchBus_E_Config" = "0"!][!VAR "MatchBus_F_Config" = "0"!]
            [!VAR "PwmChannelName" = "node:name(.)"!]
            [!LOOP "node:ref(PwmeMiosChannel)/../../PwmeMiosMasterBus/*"!]
                [!VAR "MastereMiosChannel" = "substring-after(PwmeMiosMasterBus,'Channel_')"!]
                [!IF "($MastereMiosChannel = 23)"!][!//
                    [!IF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_A_Config" = "3"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_A_Config" = "4"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_A_Config" = "1"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_A_Config" = "2"!][!//
                    [!ENDIF!][!//
                [!ELSEIF "($MastereMiosChannel = 0)"!][!//
                    [!IF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_B_Config" = "3"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_B_Config" = "4"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_B_Config" = "1"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_B_Config" = "2"!][!//
                    [!ENDIF!][!//
                [!ELSEIF "($MastereMiosChannel = 8)"!][!//
                    [!IF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_C_Config" = "3"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_C_Config" = "4"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_C_Config" = "1"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_C_Config" = "2"!][!//
                    [!ENDIF!][!//
                [!ELSEIF "($MastereMiosChannel = 16)"!][!//
                    [!IF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_D_Config" = "3"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_D_Config" = "4"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_D_Config" = "1"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_D_Config" = "2"!][!//
                    [!ENDIF!][!//
                [!ELSEIF "($MastereMiosChannel = 24)"!][!//
                    [!IF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_E_Config" = "3"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_E_Config" = "4"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_E_Config" = "1"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_E_Config" = "2"!][!//
                    [!ENDIF!][!//
                [!ELSEIF "($MastereMiosChannel = 22)"!][!//
                    [!IF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_F_Config" = "3"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_F_Config" = "4"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_F_Config" = "1"!][!//
                    [!ELSEIF "contains(MasterModeSelect, 'MASTER_MODE_UP_BUFFERED_COUNTER_U32')"!][!//
                        [!VAR "MatchBus_F_Config" = "2"!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//

            [!VAR "MaceMiosModule"  = "substring-after(node:ref(PwmeMiosChannel)/../../PwmeMiosModule,'eMios_')"!]
            [!VAR "MaceMiosChannel" = "substring-after(node:ref(PwmeMiosChannel)/PwmeMiosChannel,'Channel_')"!]
            [!IF "(num:i($MaceMiosModule) = $mIdx)"!][!//
                [!IF "contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_A_U32')"!][!//
                    [!IF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_TRAIL_DEADTIME')))"!][!//
                        [!IF "($MatchBus_A_Config = 2) or ($MatchBus_A_Config = 3) or ($MatchBus_A_Config = 4)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 23 should be configured to MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                        [!ELSEIF "($MatchBus_A_Config = 0)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS A, but EMIOS channel 23 has not been configured[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_TRAIL_DEADTIME')))"!][!//
                        [!IF "($MatchBus_A_Config = 2) or ($MatchBus_A_Config = 1) or ($MatchBus_A_Config = 4)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 23 should be configured to MASTER_MODE_UP_DOWN_COUNTER_U32[!ENDERROR!][!//
                        [!ELSEIF "($MatchBus_A_Config = 0)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS A, but EMIOS channel 23 has not been configured[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMB')))"!][!//
                        [!IF "($MatchBus_A_Config = 1) or ($MatchBus_A_Config = 3) or ($MatchBus_A_Config = 4)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , thus EMIOS channel 23 should be configured to MASTER_MODE_UP_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                        [!ELSEIF "($MatchBus_A_Config = 0)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS A, but EMIOS channel 23 has not been configured[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWM')))"!][!//
                        [!IF "($MatchBus_A_Config = 1) or ($MatchBus_A_Config = 3) or ($MatchBus_A_Config = 2)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , but EMIOS channel 23 has been configured to MASTER_MODE_UP_COUNTER_U32[!ENDERROR!][!//
                        [!ELSEIF "($MatchBus_A_Config = 0)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS A, but EMIOS channel 23 has not been configured[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ELSEIF "contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_F_U32')"!][!//
                    [!IF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_TRAIL_DEADTIME')))"!][!//
                        [!IF "($MatchBus_F_Config = 2) or ($MatchBus_F_Config = 3) or ($MatchBus_F_Config = 4)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 22 should be configured to MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                        [!ELSEIF "($MatchBus_F_Config = 0)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS F, but EMIOS channel 22 has not been configured[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_TRAIL_DEADTIME')))"!][!//
                        [!IF "($MatchBus_F_Config = 2) or ($MatchBus_F_Config = 1) or ($MatchBus_F_Config = 4)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 22 should be configured to MASTER_MODE_UP_DOWN_COUNTER_U32[!ENDERROR!][!//
                        [!ELSEIF "($MatchBus_F_Config = 0)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS F, but EMIOS channel 22 has not been configured[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMB')))"!][!//
                        [!IF "($MatchBus_F_Config = 1) or ($MatchBus_F_Config = 3) or ($MatchBus_F_Config = 4)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 22 should be configured to MASTER_MODE_UP_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                        [!ELSEIF "($MatchBus_F_Config = 0)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS F, but EMIOS channel 22 has not been configured[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWM')))"!][!//
                        [!IF "($MatchBus_F_Config = 1) or ($MatchBus_F_Config = 3) or ($MatchBus_F_Config = 2)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 22 should be configured to MASTER_MODE_UP_COUNTER_U32[!ENDERROR!][!//
                        [!ELSEIF "($MatchBus_F_Config = 0)"!][!//
                            [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS F, but EMIOS channel 22 has not been configured[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ELSEIF "contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_DIVERSE_U32')"!][!//
                    [!IF "($MaceMiosChannel < 8)"!][!//
                        [!IF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_TRAIL_DEADTIME')))"!][!//
                            [!IF "($MatchBus_B_Config = 2) or ($MatchBus_B_Config = 3) or ($MatchBus_B_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 0 should be configured to MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_B_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS B, but EMIOS channel 0 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_TRAIL_DEADTIME')))"!][!//
                            [!IF "($MatchBus_B_Config = 2) or ($MatchBus_B_Config = 1) or ($MatchBus_B_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 0 should be configured to MASTER_MODE_UP_DOWN_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_B_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS B, but EMIOS channel 0 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMB')))"!][!//
                            [!IF "($MatchBus_B_Config = 1) or ($MatchBus_B_Config = 3) or ($MatchBus_B_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 0 should be configured to MASTER_MODE_UP_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_B_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS B, but EMIOS channel 0 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWM')))"!][!//
                            [!IF "($MatchBus_B_Config = 1) or ($MatchBus_B_Config = 3) or ($MatchBus_B_Config = 2)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 0 should be configured to MASTER_MODE_UP_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_B_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS B, but EMIOS channel 0 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ELSEIF "($MaceMiosChannel < 16)"!][!//
                        [!IF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_TRAIL_DEADTIME')))"!][!//
                            [!IF "($MatchBus_C_Config = 2) or ($MatchBus_C_Config = 3) or ($MatchBus_C_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 8 should be configured to MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_C_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS C, but EMIOS channel 8 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_TRAIL_DEADTIME')))"!][!//
                            [!IF "($MatchBus_C_Config = 2) or ($MatchBus_C_Config = 1) or ($MatchBus_C_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 8 should be configured to MASTER_MODE_UP_DOWN_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_C_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS C, but EMIOS channel 8 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMB')))"!][!//
                            [!IF "($MatchBus_C_Config = 1) or ($MatchBus_C_Config = 3) or ($MatchBus_C_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 8 should be configured to MASTER_MODE_UP_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_C_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS C, but EMIOS channel 8 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWM')))"!][!//
                            [!IF "($MatchBus_C_Config = 1) or ($MatchBus_C_Config = 3) or ($MatchBus_C_Config = 2)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 8 should be configured to MASTER_MODE_UP_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_C_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS C, but EMIOS channel 8 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ELSEIF "($MaceMiosChannel < 24)"!][!//
                        [!IF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_TRAIL_DEADTIME')))"!][!//
                            [!IF "($MatchBus_D_Config = 2) or ($MatchBus_D_Config = 3) or ($MatchBus_D_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 16 should be configured to MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_D_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS D, but EMIOS channel 16 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_TRAIL_DEADTIME')))"!][!//
                            [!IF "($MatchBus_D_Config = 2) or ($MatchBus_D_Config = 1) or ($MatchBus_D_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 16 should be configured to MASTER_MODE_UP_DOWN_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_D_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS D, but EMIOS channel 16 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMB')))"!][!//
                            [!IF "($MatchBus_D_Config = 1) or ($MatchBus_D_Config = 3) or ($MatchBus_D_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 16 should be configured to MASTER_MODE_UP_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_D_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS D, but EMIOS channel 16 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWM')))"!][!//
                            [!IF "($MatchBus_D_Config = 1) or ($MatchBus_D_Config = 3) or ($MatchBus_D_Config = 2)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 16 should be configured to MASTER_MODE_UP_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_D_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS D, but EMIOS channel 16 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ELSE!][!//
                        [!IF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB_TRAIL_DEADTIME')))"!][!//
                            [!IF "($MatchBus_E_Config = 2) or ($MatchBus_E_Config = 3) or ($MatchBus_E_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 24 should be configured to MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_E_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS E, but EMIOS channel 24 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC_TRAIL_DEADTIME')))"!][!//
                            [!IF "($MatchBus_E_Config = 2) or ($MatchBus_E_Config = 1) or ($MatchBus_E_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 24 should be configured to MASTER_MODE_UP_DOWN_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_E_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS E, but EMIOS channel 24 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMB')))"!][!//
                            [!IF "($MatchBus_E_Config = 1) or ($MatchBus_E_Config = 3) or ($MatchBus_E_Config = 4)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 24 should be configured to MASTER_MODE_UP_BUFFERED_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_E_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS E, but EMIOS channel 24 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ELSEIF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWM')))"!][!//
                            [!IF "($MatchBus_E_Config = 1) or ($MatchBus_E_Config = 3) or ($MatchBus_E_Config = 2)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] mode , so EMIOS channel 24 should be configured to MASTER_MODE_UP_COUNTER_U32[!ENDERROR!][!//
                            [!ELSEIF "($MatchBus_E_Config = 0)"!][!//
                                [!ERROR!]Logical channel [!"$PwmChannelName"!] use BUS E, but EMIOS channel 24 has not been configured[!ENDERROR!][!//
                            [!ENDIF!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDFOR!]
    [!ENDNOCODE!]
[!ENDMACRO!]

/* Macro used to validate the offset of channel that using PWM_FIXED_PERIOD class */
[!MACRO "ValidateOffsetPwmFixedPeriod"!]
    [!NOCODE!]
    [!LOOP "PwmChannel/*"!]
        [!IF "node:exists('PwmChannelClass')"!]
            [!IF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMB')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWM')))"!][!//
                [!IF "not((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC')))"!][!//
                    [!VAR "PwmChannelName" = "node:name(.)"!]
                    [!VAR "ChannelClass" = "PwmChannelClass"!][!//
                    [!IF "($ChannelClass = 'PWM_FIXED_PERIOD')"!][!//
                        [!VAR "Offset" = "node:ref(PwmeMiosChannel)/PwmOffset"!]
                        [!IF "($Offset != 0)"!][!//
                            [!ERROR!]For PwmChannel_[!"$PwmChannelName"!] use PWM_FIXED_PERIOD class, so the offset phase shift must be equal 0[!ENDERROR!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//    
    [!ENDLOOP!][!//
    [!ENDNOCODE!]
[!ENDMACRO!]

/* Macro used to count and validate the Emios configured Pwm channels */
[!MACRO "ValidatePwmConfiguration"!]
  [!NOCODE!]
  [!VAR "OutNumPwmChannels" = "num:i(count(PwmChannel/*))"!]
  [!VAR "MacOuterLoopCounter" = "0"!]
  [!LOOP "PwmChannel/*"!]
    [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
    /* Check if there are no eMios hw channels referenced multiple times by same logic channels */
    [!IF "contains(PwmHwIP,'eMios')"!]
      [!VAR "MacInnerLoopCounter" = "0"!]
      [!VAR "MacMatchcounter" = "0"!]
      [!VAR "MacOutereMiosChannelPath" = "node:path(node:ref(./PwmeMiosChannel))"!]
      [!LOOP "../../../*[@index]/PwmChannel/*"!]
        [!IF "contains(PwmHwIP,'eMios')"!]
          [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
          [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
              [!VAR "MacInnereMiosChannelPath" = "node:path(node:ref(./PwmeMiosChannel))"!]
              [!IF "($MacInnereMiosChannelPath = $MacOutereMiosChannelPath)"!]
                [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
              [!ENDIF!]
          [!ENDIF!]
        [!ENDIF!]
      [!ENDLOOP!]
      [!IF "$MacMatchcounter > 1"!]
        [!ERROR!] 
          "eMios channel [!"$MacInnereMiosChannelPath"!] is referenced by more than one logic Pwm channel." 
        [!ENDERROR!] 
      [!ENDIF!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!ENDNOCODE!]
[!ENDMACRO!]


/* Macro used to generate the value of the default period attribute of a Pwm channel using
either the Emios IP. The unit measure requested by Autosar for the 
Default Period attribute is 'second'. The plugin allows the user to introduce it either in
seconds or, if plugin field PwmPeriodInTicks is checked, directly in ticks. In both cases, the value
is converted to ticks, beucase this is the format used internally by the driver */
[!MACRO "GenerateeMiosChannelPeriodInTicks", "MotorFreq"!]
    [!NOCODE!]
        [!IF "(contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_INTERNAL_COUNTER_U32') or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC')))"!]
            [!VAR "PrescalerVal" = "substring-after(node:ref(PwmeMiosChannel)/PwmPrescaler,'PwmPrescalerDiv')"!]
            [!VAR "Period"="PwmPeriodDefault"!][!//
        [!VAR "PeriodMax"="65534"!][!//

        [!IF "PwmPeriodInTicks"!][!//
            [!VAR "OutPeriodTicks"="$Period"!][!//
        [!ELSE!][!//
            [!VAR "OutPeriodTicks"="$Period * ($MotorFreq div $PrescalerVal)"!][!//
        [!ENDIF!][!//
        [!IF "num:i($OutPeriodTicks) < 1"!][!//
            [!ERROR!][!//
The configured period/ticks for channel: [!"@name"!]  is smaller than 1 tick: [!"$OutPeriodTicks"!]
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm Channel clock tree settings.
            [!ENDERROR!][!//
        [!ENDIF!][!//
        [!IF "num:i($OutPeriodTicks) > $PeriodMax"!][!//
            [!ERROR!][!//
The configured period/ticks for channel: [!"@name"!]  is larger than [!"$PeriodMax"!] ticks: [!"$OutPeriodTicks"!]
The plugin performs the conversion from Period to ticks if requested.
To solve this problem change the configured Period/ticks or change the Pwm Channel clock tree settings.
                [!ENDERROR!][!//
            [!ENDIF!]
        [!ELSE!][!//
            [!VAR "BusSelect"="node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect"!][!//
            [!VAR "eMiosChannel"="substring-after(node:ref(PwmeMiosChannel)/PwmeMiosChannel,'Channel_')"!][!//
            [!CALL "GetMasterPeriod", "parameMiosBus" = "$BusSelect", "parameMiosChannel" = "$eMiosChannel","paramClockRef" = "$MotorFreq"!]
            [!VAR "OutPeriodTicks"="$OutPeriod"!]
        [!ENDIF!]
    [!ENDNOCODE!]
[!ENDMACRO!]


/* Macro used to generate the correspondence (translation) table between all EMIOS available 
channels and the indexes of channels in the array of Pwm channels configured to use EMIOS */
[!MACRO "GenerateeMiosHwToLogicMap", "parameMiosModule"!]
[!NOCODE!]
    [!VAR "OutVarHwToLogicArray" = "''"!]
[!CODE!]
      /*---------------------EMIOS_[!"num:i($parameMiosModule)"!]---------------------------*/
[!ENDCODE!]
    [!FOR "MacCurModChannel" = "0" TO "31"!]
    /* Limit max number of configured channels to 255 */
    [!VAR "MacVarChTranslationIndex" = "255"!] 
    /* Loop through all Pwm channels configured to use EMIOS IP */
    [!LOOP "PwmChannel/*"!]
        [!IF "contains(PwmHwIP,'eMios')"!]
            /* Get indexes of EMIOS Module and Channel of current looped Pwm channel */
            [!VAR "MaceMiosModule"  = "substring-after(node:ref(PwmeMiosChannel)/../../PwmeMiosModule,'eMios_')"!]
            [!VAR "MaceMiosChannel" = "substring-after(node:ref(PwmeMiosChannel)/PwmeMiosChannel,'Channel_')"!]
            /* Check the match with the module id received as parameter */
            [!IF "num:i($MaceMiosModule) = num:i($parameMiosModule)"!]
                /* Check the match with the channel loop var */
                [!IF "num:i($MaceMiosChannel) = $MacCurModChannel"!]
                    /* Keep the index of the channel in the array of configured Pwm channels */
                    [!VAR "MacVarChTranslationIndex" = "PwmChannelId"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDIF!]
    [!ENDLOOP!]

    /* If no configured Pwm channel is using the current EMIOS channel in module  */
[!CODE!][!//
        (Pwm_ChannelType)[!"num:i($MacVarChTranslationIndex)"!][!//
[!ENDCODE!][!//    
    [!IF "($MacCurModChannel < 31) or ($parameMiosModule < 2)"!]
[!CODE!],[!//
[!ENDCODE!][!//
    [!ENDIF!]
    [!IF "$MacVarChTranslationIndex < 255"!]
[!CODE!][!//
        /* EMIOS_[!"num:i($parameMiosModule)"!]_[!"num:i($MacCurModChannel)"!] */
[!ENDCODE!][!//
    [!ELSE!][!//
[!CODE!][!//
        /* EMIOS_[!"num:i($parameMiosModule)"!]_[!"num:i($MacCurModChannel)"!] UnUsed */
[!ENDCODE!][!//
    [!ENDIF!]
    [!ENDFOR!]
[!ENDNOCODE!]
[!ENDMACRO!]
/* Macro used to validate each channels from an eMios module must have the same PwmMcuClockReferencePoint setting  */
[!MACRO "ValidateMcuClockRef"!]
    [!NOCODE!]
        [!VAR "eMios_0_Clk" = "0"!][!VAR "eMios_1_Clk" = "0"!][!VAR "eMios_2_Clk" = "0"!]
        [!LOOP "PwmChannel/*"!]
            [!VAR "eMiosModule" = "node:ref(PwmeMiosChannel)/../../PwmeMiosModule"!]
            [!IF "$eMiosModule = 'eMios_0'"!]
                [!IF "($eMios_0_Clk != 0) and ($eMios_0_Clk != PwmMcuClockReferencePoint) "!][!//
                [!ERROR!][!//
PwmMcuClockReferencePoint is not uniformity in eMios module 0.
Each channels from an eMios module must have the same PwmMcuClockReferencePoint setting
                [!ENDERROR!][!//
                [!ELSEIF "$eMios_0_Clk = 0"!][!//
                    [!VAR "eMios_0_Clk" = "PwmMcuClockReferencePoint"!]
                [!ENDIF!][!//
            [!ENDIF!]
            [!IF "$eMiosModule = 'eMios_1'"!]
                [!IF "($eMios_1_Clk != 0) and ($eMios_1_Clk != PwmMcuClockReferencePoint) "!][!//
                [!ERROR!][!//
PwmMcuClockReferencePoint is not uniformity in eMios module 1.
Each channels from an eMios module must have the same PwmMcuClockReferencePoint setting
                [!ENDERROR!][!//
                [!ELSEIF "$eMios_1_Clk = 0"!][!//
                    [!VAR "eMios_1_Clk" = "PwmMcuClockReferencePoint"!]
                [!ENDIF!][!//
            [!ENDIF!]
            [!IF "$eMiosModule = 'eMios_2'"!]
                [!IF "($eMios_2_Clk != 0) and ($eMios_2_Clk != PwmMcuClockReferencePoint) "!][!//
                [!ERROR!][!//
PwmMcuClockReferencePoint is not uniformity in eMios module 2.
Each channels from an eMios module must have the same PwmMcuClockReferencePoint setting
                [!ENDERROR!][!//
                [!ELSEIF "$eMios_2_Clk = 0"!][!//
                    [!VAR "eMios_2_Clk" = "PwmMcuClockReferencePoint"!]
                [!ENDIF!][!//
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDNOCODE!]
[!ENDMACRO!]

[!ENDNOCODE!]

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_PBcfg_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section Pwm_PBcfg_C_REF_2
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
* 
* @section Pwm_PBcfg_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of Pwm_Memmap.h
* is as  per Autosar  requirement Pwm_Memmap003.
* 
* @section Pwm_PBcfg_C_REF_4
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.*
*
* @section Pwm_PBcfg_C_REF_5
* Violates MISRA 2004 Required Rule 16.9, A function identifier shall only be used with either 
* preceing &, or with a paranhesised parameter list which may be empty.
*
* @section Pwm_PBcfg_C_REF_6
* Violates MISRA 2004 Required Rule 12.8, The right-hand operand of a shift operator shall lie 
* between zero and one less than the width in bits of the underlying type of the left-hand operand.
*
* @section Pwm_PBcfg_C_REF_7
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one and only one file 
* This is not a violation since this extern object is used one time.
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Pwm.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           Pwm_PBcfg.c
*/

#define PWM_PB_CFG_VENDOR_ID_C                      43
#define PWM_PB_CFG_MODULE_ID_C                      121
/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_PB_CFG_AR_RELEASE_MAJOR_VERSION_C       4
/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_PB_CFG_AR_RELEASE_MINOR_VERSION_C       2
/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_PB_CFG_AR_RELEASE_REVISION_VERSION_C    2

#define PWM_PB_CFG_SW_MAJOR_VERSION_C               1
#define PWM_PB_CFG_SW_MINOR_VERSION_C               0
#define PWM_PB_CFG_SW_PATCH_VERSION_C               0
/**@}*/

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#if (PWM_PB_CFG_VENDOR_ID_C != PWM_VENDOR_ID)
    #error "Pwm_PBcfg.c and Pwm.h have different vendor ids"
#endif

#if ((PWM_PB_CFG_AR_RELEASE_MAJOR_VERSION_C != PWM_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_PB_CFG_AR_RELEASE_MINOR_VERSION_C != PWM_AR_RELEASE_MINOR_VERSION) || \
        (PWM_PB_CFG_AR_RELEASE_REVISION_VERSION_C != PWM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_PBcfg.c and Pwm.h are different"
#endif

#if ((PWM_PB_CFG_SW_MAJOR_VERSION_C != PWM_SW_MAJOR_VERSION) || \
        (PWM_PB_CFG_SW_MINOR_VERSION_C != PWM_SW_MINOR_VERSION)  || \
        (PWM_PB_CFG_SW_PATCH_VERSION_C != PWM_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_PBcfg.c and Pwm.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define PWM_START_SEC_CODE
/** @violates @ref Pwm_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
/*
* @violates @ref Pwm_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Pwm_MemMap.h"

[!NOCODE!]
[!INCLUDE "Pwm_NotifyCheck_Src.m"!]

[!IF "PwmGeneral/PwmNotificationSupported"!][!// only generate the ISR macros if notifications are supported
[!CALL "GeneratePwmNotifications"!]
[!ENDIF!]
[!ENDNOCODE!]

  
#define PWM_STOP_SEC_CODE
/** @violates @ref Pwm_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
/*
* @violates @ref Pwm_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Pwm_MemMap.h"
/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Pwm_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
/*
* @violates @ref Pwm_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Pwm_Memmap.h"


[!SELECT "PwmChannelConfigSet"!]
[!NOCODE!]
/* Validate Pwm configuration */
[!CALL "ValidateOffsetPwmFixedPeriod"!]
[!CALL "ValidatePwmConfiguration"!]
[!CALL "ValidatePwmBusSelection"!]
[!CALL "ValidatePwmDaocModulo"!]
[!CALL "ValidateMcuClockRef"!]
[!ENDNOCODE!]

/** 
* @brief Number of configured Pwm channels 
*/
#define PWM_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]            [!"num:i(count(PwmChannel/*))"!]

/** 
* @brief Number of configured EMIOS channels
*/
#define PWM_EMIOS_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]     [!"num:i($OutNumPwmChannels)"!]


[!NOCODE!]/***************************** Configuration for Emios ********************/[!ENDNOCODE!]
/* @brief Configurations for Pwm channels using EMIOS */
static CONST(Pwm_eMios_ChannelConfigType, PWM_CONST) Pwm_eMios_ChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PWM_EMIOS_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
{
  [!VAR "comma" = "1"!]
  [!FOR "varCounter" = "0" TO "$OutNumPwmChannels"!]
      [!LOOP "PwmChannel/*"!]
        [!IF "PwmChannelId = $varCounter"!]
            [!IF "contains(PwmHwIP,'eMios')"!]
    /* @brief [!"node:name(.)"!] */
    {
        [!VAR "EmiosMod"     = "substring-after(node:ref(PwmeMiosChannel)/../../PwmeMiosModule,'eMios_')"!]
        [!VAR "EmiosChannel" = "substring-after(node:ref(PwmeMiosChannel)/PwmeMiosChannel,'Channel_')"!]
        /** @brief Pwm channel polarity */
        [!"PwmPolarity"!],
        /** @brief Pwm channel idle state */
        [!"PwmIdleState"!],
        /** @brief Default duty cycle value */
        (uint16)[!"num:inttohex(PwmDutycycleDefault,4)"!]U,
        [!VAR "McuClockRefValue"="node:ref(PwmMcuClockReferencePoint)/McuClockReferencePointFrequency"!][!//
        [!CALL "GenerateeMiosChannelPeriodInTicks", "MotorFreq" = "$McuClockRefValue"!]
        /** @brief Default period value */
        (Pwm_PeriodType)[!"num:i($OutPeriodTicks)"!]U,
        /** @brief EMIOS HW Module and Channel used by the Pwm channel */
        PWM_EMIOS_M[!"$EmiosMod"!]_C[!"$EmiosChannel"!],
        /* @brief EMIOS channel configuration parameters */
        [!IF "(contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_INTERNAL_COUNTER_U32'))"!]
            [!VAR "PrescalerVal" = "substring-after(node:ref(PwmeMiosChannel)/PwmPrescaler,'PwmPrescalerDiv')"!]
            [!IF "../../../PwmGeneral/PwmEnableDualClockMode"!]
                [!VAR "PrescalerVal_Alternate" = "substring-after(node:ref(PwmeMiosChannel)/PwmPrescaler_Alternate,'PwmPrescalerDiv')"!]
            [!ENDIF!][!//
        [!ELSE!][!//
            [!VAR "BusSelect"="node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect"!][!//
            [!VAR "eMiosChannel"="substring-after(node:ref(PwmeMiosChannel)/PwmeMiosChannel,'Channel_')"!][!//
            [!CALL "GetMasterPeriod", "parameMiosBus" = "$BusSelect", "parameMiosChannel" = "$eMiosChannel", "paramClockRef" = "$McuClockRefValue"!]
            [!IF "../../../PwmGeneral/PwmEnableDualClockMode"!]
                [!CALL "GetMasterPeriod_Alternate", "parameMiosBus" = "$BusSelect", "parameMiosChannel" = "$eMiosChannel"!]
            [!ENDIF!][!//
        [!ENDIF!][!//
        /* @violates @ref Pwm_PBcfg_C_REF_6 The right-hand operand of a shift operator shall. */
        (Pwm_eMios_ControlType)([!"node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect"!] | [!"node:ref(PwmeMiosChannel)/PwmModeSelect"!] [!//
              [!IF "node:ref(PwmeMiosChannel)/PwmFreezeEnable"!] | PWM_FREEZE_ENABLE_U32[!ENDIF!] [!//
                  [!IF "../../../PwmGeneral/PwmEnableDualClockMode"!][!//
                  [!IF "num:i($PrescalerVal_Alternate) = 1"!] | (PWM_PRES_1_U32 >> 0x3U)[!//
                  [!ELSEIF "num:i($PrescalerVal_Alternate) = 2"!] | (PWM_PRES_2_U32 >> 0x3U)[!//
                  [!ELSEIF "num:i($PrescalerVal_Alternate) = 3"!] | (PWM_PRES_3_U32 >> 0x3U)[!//
                  [!ELSEIF "num:i($PrescalerVal_Alternate) = 4"!] | (PWM_PRES_4_U32 >> 0x3U)[!//
                  [!ELSE!] | 0UL /* prescaler not used */[!//
                  [!ENDIF!][!//
              [!ENDIF!][!//
                  [!IF "num:i($PrescalerVal) = 1"!] | (PWM_PRES_1_U32)[!//
                  [!ELSEIF "num:i($PrescalerVal) = 2"!] | (PWM_PRES_2_U32)[!//
                  [!ELSEIF "num:i($PrescalerVal) = 3"!] | (PWM_PRES_3_U32)[!//
                  [!ELSEIF "num:i($PrescalerVal) = 4"!] | (PWM_PRES_4_U32)[!//
                  [!ELSE!] | 0UL /* prescaler not used */[!//
                  [!ENDIF!] ),
        [!IF "((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMB')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMT')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWM')))"!][!//
          [!IF "not((contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMCB')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'OPWMC')))"!][!//
            [!IF "((contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_A_U32')) or (contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_F_U32')) or (contains(node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect,'PWM_BUS_DIVERSE_U32')))"!][!//
        (Pwm_PeriodType)[!"node:ref(PwmeMiosChannel)/PwmOffset"!],/* leading edge of the PWM output pulse in OPWMB, OPWMT modes */
            [!ENDIF!][!//
          [!ELSE!][!// 
        (Pwm_PeriodType)0,/* leading edge of the PWM output pulse in OPWMB, OPWMT modes */
          [!ENDIF!]
        [!ELSE!][!//
        (Pwm_PeriodType)0,/* leading edge of the PWM output pulse in OPWMB, OPWMT modes */
        [!ENDIF!][!//
        [!VAR "BusSelect"="node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect"!][!//
        [!VAR "eMiosChannel"="substring-after(node:ref(PwmeMiosChannel)/PwmeMiosChannel,'Channel_')"!][!//
        [!CALL "GetMasterMode", "parameMiosBus" = "$BusSelect", "parameMiosChannel" = "$eMiosChannel"!]
        (uint8)[!"$MasterBusMode"!],
        #if (PWM_FEATURE_DAOC == STD_ON)
        [!IF "(contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'DAOC'))"!]
        [!VAR "BusSelect"="node:ref(PwmeMiosChannel)/EmiosUnifiedChannelBusSelect"!][!//
        [!VAR "eMiosChannel"="substring-after(node:ref(PwmeMiosChannel)/PwmeMiosChannel,'Channel_')"!][!//
        [!CALL "GetDaocModulo", "parameMiosBus" = "$BusSelect", "parameMiosChannel" = "$eMiosChannel", "paramClockRef" = "$McuClockRefValue"!]
        (Pwm_PeriodType)[!"num:i($PwmDaocModulo)"!]U,
        [!ELSE!][!//
        (Pwm_PeriodType)0,/* only use for DAOC mode */
        [!ENDIF!][!//
        #endif
        #if (PWM_FEATURE_OPWMT == STD_ON)
        [!IF "(contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'PWM_MODE_OPWMT'))"!]
        (Pwm_PeriodType)[!"node:ref(PwmeMiosChannel)/PwmTriggerDelay"!],/* delay for generating the trigger event in OPWMT mode */
        [!ELSE!][!//
        (Pwm_PeriodType)0,/* delay for generating the trigger event in OPWMT mode */
        [!ENDIF!][!//
        #endif
        #if (PWM_FEATURE_OPWMCB == STD_ON)
        [!IF "(contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'PWM_MODE_OPWMCB_LEAD_DEADTIME')) or (contains(node:ref(PwmeMiosChannel)/PwmModeSelect,'PWM_MODE_OPWMCB_TRAIL_DEADTIME'))"!][!//
        (uint16)[!"node:ref(PwmeMiosChannel)/Pwm_Deadtime"!],[!//
        [!ELSE!][!//
        (uint16)0,[!//
        [!ENDIF!]/*deadtime parameter */
        #endif
        (boolean)[!IF "node:ref(PwmeMiosChannel)/OffsetDelayAdjust"!]TRUE[!ELSE!]FALSE[!ENDIF!] /* Pwm_Offset and Pwm_TriggerDelay adjusted during runtime */
    }[!IF "(num:i($comma))<(num:i($OutNumPwmChannels))"!],[!ENDIF!][!CR!][!VAR "comma"="$comma + 1"!]
            [!ENDIF!]
          [!ENDIF!]
      [!ENDLOOP!]
    [!ENDFOR!]
};

/**
@brief EMIOS IP configuration
*/
/* @violates @ref Pwm_PBcfg_C_REF_2 external ... could be made static */
static CONST(Pwm_eMios_IpConfigType, PWM_CONST) Pwm_eMios_IpConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /** @brief Number of EMIOS channels in the Pwm configuration */
    (uint8)[!"num:i($OutNumPwmChannels)"!],
    /** @brief Pointer to the array of EMIOS enabled Pwm channel configurations */
    &Pwm_eMios_ChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};


/* @brief Array of configured Pwm channels */
static CONST(Pwm_ChannelConfigType, PWM_CONST) Pwm_Channels_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PWM_EMIOS_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
{
    [!VAR "comma" = "1"!]
  [!FOR "varCounter" = "0" TO "$OutNumPwmChannels"!]
    [!LOOP "PwmChannel/*"!]
       [!IF "PwmChannelId = $varCounter"!]
    /* @brief [!"@name"!] */
    {
        /* @brief Channel class: Variable/Fixed/Fixed_Shifted period */
    [!IF "node:exists('PwmChannelClass')"!]
        [!"PwmChannelClass"!],
    [!ELSE!]
        PWM_FIXED_PERIOD,
    [!ENDIF!]
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /** @brief Pwm notification function */
    [!IF "node:exists('PwmNotification')"!]
      [!IF "(PwmNotification = '') or (PwmNotification = 'NULL_PTR') or (PwmNotification = 'NULL')"!]
        NULL_PTR
     [!ELSE!]
        /* @violates @ref Pwm_PBcfg_C_REF_5 Callback definition */
        [!"PwmNotification"!],
      [!ENDIF!]
    [!ELSE!]
        NULL_PTR,
    [!ENDIF!]
#endif
    }[!IF "(num:i($comma))<(num:i($OutNumPwmChannels))"!],[!ENDIF!][!VAR "comma"="$comma + 1"!][!CR!]
      [!ENDIF!]
    [!ENDLOOP!]
  [!ENDFOR!]
};

/**
@brief   Pwm channels IP related configuration array
*/
static CONST(Pwm_IpChannelConfigType, PWM_CONST) Pwm_IpChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][PWM_EMIOS_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] = 
{
  [!VAR "curPwmChannelUsingeMios" = "0"!]
  [!VAR "comma" = "1"!]
  [!FOR "varCounter" = "0" TO "$OutNumPwmChannels"!]
    [!LOOP "PwmChannel/*"!]
      [!IF "PwmChannelId = $varCounter"!]
    /** @brief [!"@name"!] */
    {
    [!IF "contains(PwmHwIP,'eMios')"!]
        /* @brief Index in the configuration table of the EMIOS channels */
        (uint8)[!"num:i($curPwmChannelUsingeMios)"!],
        [!VAR "curPwmChannelUsingeMios" = "$curPwmChannelUsingeMios + 1"!]
    [!ENDIF!]
    }[!IF "(num:i($comma))<(num:i($OutNumPwmChannels))"!],[!ENDIF!][!VAR "comma"="$comma + 1"!][!CR!]    
      [!ENDIF!]
    [!ENDLOOP!]
  [!ENDFOR!]
};
[!ENDSELECT!]
/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
/**
@brief   Pwm high level configuration structure
*/
[!SELECT "PwmChannelConfigSet"!]
/*
* @violates @ref Pwm_PBcfg_C_REF_2 external ... could be made static
*/
[!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!]
CONST(Pwm_ConfigType, Pwm_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
[!ELSE!]
CONST(Pwm_ConfigType, Pwm_CONST) Pwm_PBCfgVariantPredefined =
[!ENDIF!]
{
    /** @brief Number of configured Pwm channels */
    (Pwm_ChannelType)PWM_CONF_CHANNELS_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /** @brief Pointer to array of Pwm channels */
    &Pwm_Channels_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    /** @brief IP specific configuration */
    {
        /* @brief Pointer to the structure containing EMIOS configuration */
        &Pwm_eMios_IpConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        /* @brief Pointer to Array containing channe IP related information */
        &Pwm_IpChannelConfig_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] [!CR!]
    }
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    ,
    /** @brief Hw to logic channel map. Array containing a number of elements
    equal to total number of available channels on EMIOS IPV */
    {
[!FOR "idx" = "0" TO "$numeMiosModules - 1"!]
        [!CALL "GenerateeMiosHwToLogicMap", "parameMiosModule" = "$idx"!]
[!ENDFOR!]
    }
#endif /* (PWM_NOTIFICATION_SUPPORTED == STD_ON) */  
};
[!ENDSELECT!]

/* @violates @ref Pwm_PBcfg_C_REF_4 Identifier exceeds 31 chars. */
#define PWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Pwm_PBcfg_C_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the 
*   contents of a header file being included twice.*/
/*
* @violates @ref Pwm_PBcfg_C_REF_3 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Pwm_Memmap.h"


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */

[!ENDCODE!]
