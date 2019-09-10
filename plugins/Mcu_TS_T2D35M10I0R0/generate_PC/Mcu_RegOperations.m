[!NOCODE!]
/**
    @file    Mcu_RegOperations.m
    @version 1.0.0

    @brief   AUTOSAR Mcu - Register operations.
    @details Register operations.

    Project AUTOSAR 4.2 MCAL
    Platform PA
    Peripheral MC
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

[!MACRO "CheckDuplicates"!]
[!NOCODE!]
        [!VAR "ConfigIndexA" = "@name"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
            [!VAR "clockSettingMain" = "@name"!]
                [!VAR "ConfigIndexB" = "@name"!]
                [!IF "$ConfigIndexA!=$ConfigIndexB"!]
                    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
                        [!VAR "clockSettingSlave" = "@name"!]
                        [!IF "$clockSettingMain=$clockSettingSlave"!]
                            [!ERROR!]
    [!"$ConfigIndexA"!] contains McuClockSettingConfig [!"$clockSettingMain"!] which is duplicated in [!"$ConfigIndexB"!]
                            [!ENDERROR!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ENDIF!]
        [!ENDLOOP!]

        [!VAR "ConfigIndexA" = "@name"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
            [!VAR "modeSettingMain" = "@name"!]
                [!VAR "ConfigIndexB" = "@name"!]
                [!IF "$ConfigIndexA!=$ConfigIndexB"!]
                    [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
                        [!VAR "modeSettingSlave" = "@name"!]
                        [!IF "$modeSettingMain=$modeSettingSlave"!]
                            [!ERROR!]
    [!"$ConfigIndexA"!] contains McuModeSettingConf [!"$modeSettingMain"!] which is duplicated in [!"$ConfigIndexB"!]
                            [!ENDERROR!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ENDIF!]
        [!ENDLOOP!]

        [!VAR "ConfigIndexA" = "@name"!]
        [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
            [!VAR "ramSettingMain" = "@name"!]
                [!VAR "ConfigIndexB" = "@name"!]
                [!IF "$ConfigIndexA!=$ConfigIndexB"!]
                    [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
                        [!VAR "ramSettingSlave" = "@name"!]
                        [!IF "$ramSettingMain=$ramSettingSlave"!]
                            [!ERROR!]
    [!"$ConfigIndexA"!] contains McuRamSectorSettingConf [!"$ramSettingMain"!] which is duplicated in [!"$ConfigIndexB"!]
                            [!ENDERROR!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                [!ENDIF!]
        [!ENDLOOP!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Mcu_Dem_Config"!][!// 
[!NOCODE!]
    [!VAR "McuDemEventParameter"!]MCU_E_TIMEOUT_FAILURE,MCU_E_INVALIDMODE_CONFIG,MCU_E_SSCM_CER_FAILURE[!ENDVAR!]
    [!VAR "DemErrorCount" = "num:i(count(text:split($McuDemEventParameter, ',')))"!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief        DEM error reporting configuration
* @details      Set the state and id for Mcal_DemErrorType.
*/
/** @violates @ref Mcu_Cfg_c_REF_7 MISRA 2004 Required Rule 8.10, external linkage ... */
CONST( Mcu_DemConfigType, MCU_CONST) Mcu_Dem_Config = 
{
[!ENDCODE!]
    [!FOR "Index" = "1" TO "num:i($DemErrorCount)"!]
        [!VAR "ErrorName" = "normalize-space(text:split($McuDemEventParameter, ',')[num:i($Index)])"!]
        [!IF "node:exists(McuModuleConfiguration/McuDemEventParameterRefs)"!]
            [!VAR "DemRefNode" = "concat('McuModuleConfiguration/McuDemEventParameterRefs/',$ErrorName)"!]
            [!IF "node:exists($DemRefNode)"!]
                [!IF "node:refvalid($DemRefNode)"!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_ON, DemConf_DemEventParameter_[!"node:ref(node:value($DemRefNode))/@name"!]}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
                [!ELSE!]
                     [!ERROR "Invalid reference for $ErrorName"!]
                [!ENDIF!]
            [!ELSE!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_OFF, 0U}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
            [!ENDIF!]
        [!ELSE!]
[!CODE!]
    /* DEM error reporting [!"$ErrorName"!] */
    {(uint32)STD_OFF, 0U}[!IF "$Index < $DemErrorCount"!],[!ENDIF!]
[!ENDCODE!]
        [!ENDIF!]
    [!ENDFOR!]
[!CODE!]
};
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!]

[!MACRO "McuCheckPeripheralReferences"!][!//
[!NOCODE!]
        [!VAR "Current_ConfigSet"="McuModuleConfiguration"!]
        [!LOOP "McuModuleConfiguration/McuPeripheral/*"!]
            [!VAR "PeripheralName"="@name"!]            
            [!IF "node:exists(./McuPerRunConfig)"!]
                [!IF "contains(./McuPerRunConfig,$Current_ConfigSet)"!]
                [!ELSE!]
                    [!ERROR!]
                        WRONG Reference is selected for McuPerRunConfig in [!"$Current_ConfigSet"!]/McuPeripheral/[!"$PeripheralName"!].
                        Mcu Peripheral Run mode(in the container McuRunConfig) configured in [!"$Current_ConfigSet"!] should be referenced.
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]
            [!IF "node:exists(./McuPerLowPwrConfig)"!]
                [!IF "contains(./McuPerLowPwrConfig,$Current_ConfigSet)"!]
                [!ELSE!]
                    [!ERROR!]
                        WRONG Reference is selected for McuPerRunConfig in [!"$Current_ConfigSet"!]/McuPeripheral/[!"$PeripheralName"!]. 
                        Mcu Peripheral Low power mode(in the container McuLowPowerConfig) configured in [!"$Current_ConfigSet"!] should be referenced.
                    [!ENDERROR!]
                [!ENDIF!]
            [!ENDIF!]            
        [!ENDLOOP!][!//McuPeripheral/*
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "McuLinkerSymbols","Type"!][!//
[!NOCODE!][!//
[!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
    [!IF "McuRamSectionSizeLinkerSym != ''"!]
        [!VAR "Externs_SL" = "concat('extern  VAR(uint32, MCU_VAR) ',McuRamSectionSizeLinkerSym,'[];')"!]
        [!CODE!][!//
/**
* @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_6 MISRA 2004 Required Rule 20.2, The names of standard macros, objects and functions shall not be reused
* @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_8 MISRA 2004 Required Rule 8.12, The array shall be stated explicitly or defined implicitly by initialisation
* @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_9 MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*/
[!"$Externs_SL"!]
        [!ENDCODE!][!//
    [!ENDIF!]
    [!IF "McuRamSectionBaseAddrLinkerSym != ''"!]
        [!VAR "Externs_BAL" = "concat('extern  VAR(uint8, MCU_VAR) ',McuRamSectionBaseAddrLinkerSym,'[];')"!]
        [!CODE!][!//
/**
* @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_6 MISRA 2004 Required Rule 20.2, The names of standard macros, objects and functions shall not be reused
* @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_8 MISRA 2004 Required Rule 8.12, The array shall be stated explicitly or defined implicitly by initialisation
* @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_9 MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*/
[!"$Externs_BAL"!]
        [!ENDCODE!][!//
    [!ENDIF!]
[!ENDLOOP!][!//McuRamSectorSettingConf/*
[!ENDNOCODE!][!//
[!ENDMACRO!][!//

[!MACRO "Mcu_Ram_Config","Type"!][!//
[!NOCODE!]

[!IF "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))>0"!]
    [!VAR "var"= "1"!]
    [!VAR "RamSector"= "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))-1"!]
[!CODE!]
/**
* @brief        Definition of RAM sections within the configuration structure.
* @details      Blocks of memory are initialized with a default data.
*               Configuration set by calling Mcu_InitClock() API.
*
*/
static CONST(Mcu_RamConfigType, MCU_CONST) Mcu_aRamConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))"!]] =
{
[!ENDCODE!]
        [!LOOP "McuModuleConfiguration/McuRamSectorSettingConf/*"!]
            [!VAR "PCindex" = "@index"!]
            [!CALL "MCheckRamSection"!]
[!CODE!]
    {
        /* The ID for Ram Sector configuration. */
        (uint8)[!"num:i(McuRamSectorId)"!]U,

        /* RAM section base address: Start of Mcu_RamConfig[[!"@index"!]]. */
        /** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_4 MISRA 2004 Required Rule 11.1, conversion from pointer to integer */
        /** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_5 MISRA 2004 Advisory Rule 11.4, cast between pointer and object */
        /** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_10 MISRA 2004 Required Rule 11.3, the cast is used to access a linker symbol */
        [!IF "McuRamSectionBaseAddrLinkerSym = ''"!](uint8 (*)[1U])[!"num:inttohex(McuRamSectionBaseAddress,8)"!]U[!ELSE!](uint8 (*)[1U])[!"McuRamSectionBaseAddrLinkerSym"!][!ENDIF!],

        /* RAM section size: Section base address (must be aligned to 4 bytes). */
        /** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_4 MISRA 2004 Required Rule 11.1, conversion from pointer to integer */
        /** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_10 MISRA 2004 Required Rule 11.3, the cast is used to access a linker symbol */
        [!IF "McuRamSectionSizeLinkerSym = ''"!](uint32)[!"num:inttohex(McuRamSectionSize,8)"!]U,[!ELSE!](uint32)[!"McuRamSectionSizeLinkerSym"!],[!ENDIF!]

        /* RAM default value: Section size in bytes (must be multiple of 4). */
        (uint8)[!"num:inttohex(McuRamDefaultValue,2)"!]U
    }[!IF "$PCindex < $RamSector"!],[!ENDIF!] /* End of Mcu_Ram_Config[!"$Type"!][[!"@index"!]]. */
                [!ENDCODE!]
            [!VAR "var"= "$var+1"!]
        [!ENDLOOP!][!//McuRamSectorSettingConf/*
        [!CODE!]
};
[!ENDCODE!]
        [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!//


[!MACRO "Mcu_Mode_Config","Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))>0"!]
        [!VAR "Mode"= "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))-1"!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
[!CODE!]
#if (MCU_CONFIGURE_CADDRN == STD_ON)
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_MC_ME_CoreAddressConfigType, MCU_CONST) Mcu_aModeCoreAdressConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_MC_ME_NUMBER_OF_CORES] = 
{
    [!IF "../../../McuCoreControlConfiguration/McuCADDRnControl = 'true'"!]
    /* Core Control Register (ME_CADDR1) */
    {
        MC_ME_CADDR1_ADDR32,
        [!IF "McuCoreConfiguration/McuCoreCaddr1ResetEnable = 'true'"!][!IF "McuCoreConfiguration/McuCoreZ4ADefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_MASK32 | [!ENDIF!][!ENDIF!]MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
            [!IF "McuCoreConfiguration/McuCoreCaddr1ResetEnable = 'true'"!][!IF "McuCoreConfiguration/McuCoreZ4ADefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_U32([!"num:inttohex(McuCoreConfiguration/McuCoreCaddr1BootAddr,8)"!]U) |[!ENDIF!][!ENDIF!]
            [!IF "McuCoreConfiguration/McuCoreCaddr1ResetEnable='true'"!]MC_ME_CADDR_RESET_ENABLE_U32[!ELSE!]MC_ME_CADDR_RESET_DISABLE_U32[!ENDIF!]
        )
    },
    [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3)"!]
    /* Core Control Register (ME_CADDR2) */
    {
        MC_ME_CADDR2_ADDR32,
         [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3) and (McuCoreConfiguration/McuCoreCaddr2ResetEnable = 'true')"!][!IF "McuCoreConfiguration/McuCoreZ4BDefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_MASK32 | [!ENDIF!][!ENDIF!]MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
            [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3) and (McuCoreConfiguration/McuCoreCaddr2ResetEnable = 'true')"!][!IF "McuCoreConfiguration/McuCoreZ4BDefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_U32([!"num:inttohex(McuCoreConfiguration/McuCoreCaddr2BootAddr,8)"!]U) |[!ENDIF!][!ENDIF!]
            [!IF "McuCoreConfiguration/McuCoreCaddr2ResetEnable='true'"!]MC_ME_CADDR_RESET_ENABLE_U32[!ELSE!]MC_ME_CADDR_RESET_DISABLE_U32[!ENDIF!]
        )
    },
    [!ENDIF!]
    /* Core Control Register (ME_CADDR3) */
    {
        MC_ME_CADDR3_ADDR32,
         [!IF "McuCoreConfiguration/McuCoreCaddr3ResetEnable = 'true'"!][!IF "McuCoreConfiguration/McuCoreZ2DefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_MASK32 | [!ENDIF!][!ENDIF!]MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
             [!IF "McuCoreConfiguration/McuCoreCaddr3ResetEnable = 'true'"!][!IF "McuCoreConfiguration/McuCoreZ2DefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_U32([!"num:inttohex(McuCoreConfiguration/McuCoreCaddr3BootAddr,8)"!]U) |[!ENDIF!][!ENDIF!]
            [!IF "McuCoreConfiguration/McuCoreCaddr3ResetEnable='true'"!]MC_ME_CADDR_RESET_ENABLE_U32[!ELSE!]MC_ME_CADDR_RESET_DISABLE_U32[!ENDIF!]
        )
    }
    [!ELSE!]
    /* Core Control Register (ME_CADDR1) */
    {
        MC_ME_CADDR1_ADDR32,
        0x00000000U,
        0x00000000U
    },
    [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3)"!]
    /* Core Control Register (ME_CADDR2) */
    {
        MC_ME_CADDR2_ADDR32,
        0x00000000U,
        0x00000000U
    },
    [!ENDIF!]
    /* Core Control Register (ME_CADDR3) */
    {
        MC_ME_CADDR3_ADDR32,
        0x00000000U,
        0x00000000U
    }
    [!ENDIF!]
};
#endif /* MCU_CONFIGURE_CADDRN == STD_ON */
[!ENDCODE!]
        [!ENDLOOP!]


[!CODE!]
/**
* @brief        Definition of MCU mode sections in the configuration structure.
* @details      Specifies the system behaviour during the selected target mode.
*               Configuration set by calling Mcu_SetMode() API.
*/
static CONST( Mcu_ModeConfigType, MCU_CONST) Mcu_aModeConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]] = 
{    
[!ENDCODE!]
    [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
        [!VAR "PCindex" = "@index"!]
[!CODE!]
    /* Start of Mcu_ModeConfig[[!"@index"!]] - [!"McuPowerMode"!] */
    {
        /* The ID for Power Mode configuration. */
        (uint8)[!"num:i( num:i(McuMode) - 1 )"!]U,

        /* The selected magic target mode. Configure the ME_MCTL[TARGET_MODE] register filed. */
        [!IF "McuPowerMode='RUN3'"!](MCU_RUN3_MODE),[!ELSEIF "McuPowerMode='RUN2'"!](MCU_RUN2_MODE),[!ELSEIF "McuPowerMode='RUN1'"!](MCU_RUN1_MODE),[!ELSEIF "McuPowerMode='RUN0'"!](MCU_RUN0_MODE),[!ELSEIF "McuPowerMode='DRUN'"!](MCU_DRUN_MODE),[!ELSEIF "McuPowerMode='STOP0'"!](MCU_STOP0_MODE),[!ELSEIF "McuPowerMode='STANDBY0'"!](MCU_STBY0_MODE),[!ELSEIF "McuPowerMode='LPU_RUN'"!](MCU_STBY0_MODE),[!ELSEIF "McuPowerMode='SAFE'"!](MCU_SAFE_MODE),[!ELSEIF "McuPowerMode='RESET'"!](MCU_RESET_MODE),[!ELSEIF "McuPowerMode='RESET_DEST'"!](MCU_DEST_RESET_MODE),[!ENDIF!]

        /* Specifies the system behaviour for this configured state. */
        (
            /* Configure the MC_<mode>_MC[PDO] register field. */               
            [!IF "McuOutputPowerDownControl='true'"!](MC_ME_OUT_POWER_CONTROL_EN_U32) |[!ELSE!](MC_ME_OUT_POWER_CONTROL_DIS_U32) |[!ENDIF!]

            /* Configure the MC_<mode>_MC[MVRON] register field. */
            [!IF "McuPowerMode='STANDBY0'"!](MC_ME_MAIN_VOLTAGE_REG_DIS_U32) |[!ELSEIF "McuPowerMode='STOP0'"!][!IF "McuMainVoltageRegulatorControl='true'"!](MC_ME_MAIN_VOLTAGE_REG_EN_U32) |[!ELSE!](MC_ME_MAIN_VOLTAGE_REG_DIS_U32) |[!ENDIF!][!ELSE!](MC_ME_MAIN_VOLTAGE_REG_EN_U32) |[!ENDIF!]

            /* Configure the MC_<mode>_MC[CFLAON] register field. */
            [!IF "McuFlashPowerControl='NormalMode'"!](MC_ME_CODE_FLASH_NORMAL_POWER_U32) |[!ELSEIF "McuFlashPowerControl='LowPower'"!](MC_ME_CODE_FLASH_LOW_POWER_U32) |[!ELSEIF "McuFlashPowerControl='PowerDown'"!](MC_ME_CODE_FLASH_POWER_DOWN_U32) | [!ENDIF!]

            /* Configure the MC_<mode>_MC[PLL0ON] register field. */
            [!IF "McuPll0Control='true'"!](MC_ME_PLL0_EN_U32) | [!ELSE!](MC_ME_PLL0_DIS_U32) | [!ENDIF!]

            /* Configure the MC_<mode>_MC[SXOSCON] register field. */
            [!IF "McuSXOscControl='true'"!](MC_ME_SXOSC_EN_U32) | [!ELSE!](MC_ME_SXOSC_DIS_U32) | [!ENDIF!]

            /* Configure the MC_<mode>_MC[SIRCON] register field. */
            [!IF "McuSIrcOscControl='true'"!](MC_ME_SIRC_EN_U32) | [!ELSE!](MC_ME_SIRC_DIS_U32) | [!ENDIF!]

            /* Configure the MC_<mode>_MC[FXOSCON] register field. */
            [!IF "McuFXoscControl='true'"!](MC_ME_FXOSC_EN_U32) | [!ELSE!](MC_ME_FXOSC_DIS_U32) | [!ENDIF!]
            
            /* Configure the MC_<mode>_MC[FIRCON] register field. */
            [!IF "(McuPowerMode = 'STOP0' or McuPowerMode ='STANDBY0' or McuPowerMode = 'LPU_RUN')"!][!IF "McuFircControl='true'"!](MC_ME_FIRC_EN_U32) | [!ELSE!](MC_ME_FIRC_DIS_U32) | [!ENDIF!][!ELSE!](MC_ME_FIRC_EN_U32) | [!ENDIF!]

            /* Configure the MC_<mode>_MC[SYSCLK] register field. */
            [!IF "McuSystemClockSwitch='FIRC'"!](MC_ME_SYSCLK_FIRC_U32)[!ELSEIF "McuSystemClockSwitch='FXOSC'"!](MC_ME_SYSCLK_FXOSC_U32)[!ELSEIF "McuSystemClockSwitch='PLL0_PHI0'"!](MC_ME_SYSCLK_PLL0_U32)[!ELSE!](MC_ME_SYSCLK_DISABLED_U32)[!ENDIF!] |
            
            /* configure the MC_<mode>_MC[PWRLVL] register field. */
            MC_ME_POWER_LEVEL_U32( (uint32)[!"num:i(McuPowerLevelControl)"!]U )
        )
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
        /* Fast transition supported (from Low Power to Run mode). */
        ,[!IF "McuFastTransition='true'"!](boolean)TRUE[!ELSE!](boolean)FALSE[!ENDIF!]

        /* Specifies the system behaviour for this RUN state that will be after wakeup (exit from low power mode - STOP0/HALT0). */
        ,[!IF "McuFastTransition='true'"!]
        (
            /* Configure the MC_<mode>_MC[PDO] register field. */
            [!IF "McuModeSettingConfAfterWkp/McuOutputPowerDownControl='true'"!](MC_ME_OUT_POWER_CONTROL_EN_U32) |[!ELSE!](MC_ME_OUT_POWER_CONTROL_DIS_U32) |[!ENDIF!]

            /* Configure the MC_<mode>_MC[MVRON] register field. */
            (MC_ME_MAIN_VOLTAGE_REG_EN_U32) |

            /* Configure the MC_<mode>_MC[CFLAON] register field. */
            [!IF "McuModeSettingConfAfterWkp/McuFlashPowerControl='NormalMode'"!](MC_ME_CODE_FLASH_NORMAL_POWER_U32) |[!ELSEIF "McuModeSettingConfAfterWkp/McuFlashPowerControl='LowPower'"!]MC_ME_CODE_FLASH_LOW_POWER_U32 |[!ELSEIF "McuModeSettingConfAfterWkp/McuFlashPowerControl='PowerDown'"!](MC_ME_CODE_FLASH_POWER_DOWN_U32) |[!ENDIF!]

            /* Configure the MC_<mode>_MC[PLL0ON] register field. */
            [!IF "McuModeSettingConfAfterWkp/McuPll0Control='true'"!](MC_ME_PLL0_EN_U32) | [!ELSE!](MC_ME_PLL0_DIS_U32) | [!ENDIF!]

            /* Configure the MC_<mode>_MC[SXOSCON] register field. */
            [!IF "McuModeSettingConfAfterWkp/McuSXOscControl='true'"!](MC_ME_SXOSC_EN_U32) | [!ELSE!](MC_ME_SXOSC_DIS_U32) | [!ENDIF!]

            /* Configure the MC_<mode>_MC[SIRCON] register field. */
            [!IF "McuModeSettingConfAfterWkp/McuSIrcOscControl='true'"!](MC_ME_SIRC_EN_U32) | [!ELSE!](MC_ME_SIRC_DIS_U32) | [!ENDIF!]

            /* Configure the MC_<mode>_MC[FXOSCON] register field. */
            [!IF "McuModeSettingConfAfterWkp/McuFXoscControl='true'"!](MC_ME_FXOSC_EN_U32) | [!ELSE!](MC_ME_FXOSC_DIS_U32) | [!ENDIF!]
            
            /* Configure the MC_<mode>_MC[RCON] register field. */
            [!IF "McuModeSettingConfAfterWkp/McuFircControl='true'"!](MC_ME_FIRC_EN_U32) | [!ELSE!](MC_ME_FIRC_DIS_U32) | [!ENDIF!]
            
            /* Configure the MC_<mode>_MC[SYSCLK] register field. */
            [!IF "McuModeSettingConfAfterWkp/McuSystemClockSwitch='FIRC'"!](MC_ME_SYSCLK_FIRC_U32)[!ELSEIF "McuModeSettingConfAfterWkp/McuSystemClockSwitch='FXOSC'"!](MC_ME_SYSCLK_FXOSC_U32)[!ELSEIF "McuModeSettingConfAfterWkp/McuSystemClockSwitch='PLL0_PHI0'"!](MC_ME_SYSCLK_PLL0_U32)[!ENDIF!] |
            
             /* configure the MC_<mode>_MC[PWRLVL] register field. */
            MC_ME_POWER_LEVEL_U32( (uint32)[!"num:i(McuModeSettingConfAfterWkp/McuPowerLevelControl)"!]U )
        )[!ELSE!](MC_ME_FAST_MODE_CONFIG_DEFAULT_U32)[!ENDIF!]
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
#if ( MCU_CONFIGURE_CADDRN == STD_ON)
        /* configuration of CADDRs */
        ,MCU_MC_ME_NUMBER_OF_CORES
        ,&Mcu_aModeCoreAdressConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
#endif /* MCU_CONFIGURE_CADDRN == STD_ON */

#ifdef MCU_ERR009139_IPV_MC_05000007
#if (MCU_ERR009139_IPV_MC_05000007 == STD_ON)
        /* Configure the GPR_SLEEP register. */
        ,[!IF "McuPowerMode='STANDBY0'"!]MC_ME_GPR_SLEEP_VALUE_U32([!IF "../../McuPowerControl/McuPmcRamDomain_Config/McuPmcRdCr_Rd256Ret='true'"!]MC_ME_GPR_SLEEP_ENABLE_U32[!ELSE!]MC_ME_GPR_SLEEP_DEFAULT_U32[!ENDIF!])[!ELSE!](MC_ME_GPR_SLEEP_DEFAULT_U32)[!ENDIF!]
#endif  /* MCU_ERR009139_IPV_MC_05000007 */
#endif  /* (MCU_ERR009139_IPV_MC_05000007 == STD_ON) */
    }[!IF "$PCindex < $Mode"!],[!ENDIF!]
    /* end of Mcu_aModeConfig[!"$Type"!][!"num:i($ConfigIndex)"!][[!"@index"!]]. */
[!ENDCODE!]
        [!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]
    [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!//



[!MACRO "Mcu_LowPowerMode_Config", "Type"!][!// 
[!IF "count(McuModuleConfiguration/McuModeSettingConf/*/McuPowerMode[. = 'LPU_RUN']) >= 1"!]
[!NOCODE!]
    [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))>0"!]
        [!VAR "Mode"= "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))-1"!]
[!CODE!]
/**
* @brief        Definition of MCU low power mode sections in the configuration structure.
* @details      Specifies the system behaviour during the selected target low power mode.
*               Configuration set by calling Mcu_SetMode() API.
*/
static CONST( Mcu_LPU_LowPowerModeConfigType, MCU_CONST) Mcu_aLowPowerModeConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]] = 
{    
[!ENDCODE!]
        [!LOOP "McuModuleConfiguration/McuModeSettingConf/*"!]
            [!VAR "PCindex" = "@index"!]
[!CODE!]
    [!IF "McuPowerMode='LPU_RUN'"!][!//
    /* Start of Mcu_aLowPowerModeConfig[[!"@index"!]] - [!IF "McuPowerMode='LPU_RUN'"!][!"McuPowerMode"!][!ELSE!]unused[!ENDIF!] */ 
    {
        /* The ID for Low Power Mode configuration. */
        (uint8)[!"num:i( num:i(McuMode) - 1 )"!]U,

        /* The selected LPU target mode. Configure the LPU_MCTL[TARGET_MODE] register filed. */
        MCU_[!"McuPowerMode"!]_MODE,
        
        /* Specifies the system behaviour for this configured state. */
        (
            /* Configure the LPU_<mode>_CF[CAN0_CONT] register field. */               
            [!IF "McuLpuConfiguration/McuCAN0ContinuousOperation='true'"!](LPU_RUN_CF_CAN0_SUPPORTED_U32) |[!ELSE!](LPU_RUN_CF_CAN0_NOT_SUPPORTED_U32) |[!ENDIF!]

            /* Configure the LPU_<mode>_CF[DIRECT_DRUN] register field. */
            [!IF "McuLpuConfiguration/McuDirectDrun='true'"!](LPU_RUN_CF_EXIT_TO_DRUN_U32) |[!ELSE!](LPU_RUN_CF_EXIT_TO_LPU_RUN_U32) |[!ENDIF!]

            /* Configure the LPU_<mode>_CF[SYS_CLK_SEL] register field. */
            [!IF "McuLpuConfiguration/McuSystemClockSelect='true'"!][!IF "McuLpuConfiguration/McuFXoscControl='true'"!](LPU_RUN_CF_SYS_CLK_SEL_FXOSC_U32) |[!ELSE!](LPU_RUN_CF_SYS_CLK_SEL_FIRC_U32) |[!ENDIF!][!ELSE!](LPU_RUN_CF_SYS_CLK_SEL_FIRC_U32) |[!ENDIF!]

            /* Configure the LPU_<mode>_CF[LPU_SLEEP] register field. */
            [!IF "McuLpuConfiguration/McuLpuSleep='true'"!](LPU_RUN_CF_CORE_SLEEP_U32) |[!ELSE!](LPU_RUN_CF_NO_CORE_SLEEP_U32) |[!ENDIF!]
            
            /* Configure the LPU_<mode>_CF[FIRCON] register field. */
            [!IF "McuLpuConfiguration/McuFircControl='true'"!]([!"McuPowerMode"!]_CF_FIRC_ON_U32) |[!ELSE!](LPU_RUN_CF_FIRC_OFF_U32) |[!ENDIF!]
            
            /* Configure the LPU_<mode>_CF[SXOSCON] register field. */
            [!IF "McuLpuConfiguration/McuSXOscControl='true'"!](LPU_RUN_CF_SXOSC_ON_U32) |[!ELSE!]([!"McuPowerMode"!]_CF_SXOSC_OFF_U32) |[!ENDIF!]

            /* Configure the LPU_<mode>_CF[SIRCON] register field. */
            [!IF "McuLpuConfiguration/McuSIrcOscControl='true'"!](LPU_RUN_CF_SIRC_ON_U32) |[!ELSE!]([!"McuPowerMode"!]_CF_SIRC_OFF_U32) |[!ENDIF!]

            /* Configure the LPU_<mode>_CF[FXOSCON] register field. */
            [!IF "McuLpuConfiguration/McuFXoscControl='true'"!](LPU_RUN_CF_FXOSC_ON_U32)[!ELSE!]([!"McuPowerMode"!]_CF_FXOSC_OFF_U32)[!ENDIF!]
        ),

        (
            /* Configure the LPU_ICR[LPU_MRIG_E] register field. */
            [!IF "McuLpuConfiguration/McuLpuMRIGInterruptEnable='true'"!](LPU_ICR_MRIG_INT_EN_U32) |[!ELSE!](LPU_ICR_MRIG_INT_DIS_U32) |[!ENDIF!]

            /* Configure the LPU_ICR[LPU_NEM_E] register field. */
            [!IF "McuLpuConfiguration/McuLpuNEMInterruptEnable='true'"!](LPU_ICR_NEM_INT_EN_U32)[!ELSE!](LPU_ICR_NEM_INT_DIS_U32)[!ENDIF!]
        ),
        
        (
            /* Configure the LPU_MDIS[eMIOS_2] register field. */
            [!IF "num:i(count(ecu:list('MCU.eMIOS.List')))=3"!][!IF "McuLpuConfiguration/McuDisableEmios2='true'"!](LPU_MDIS_EMIOS_2_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_EMIOS_2_CLK_EN_U32) |[!ENDIF!][!ELSE!](LPU_MDIS_EMIOS_2_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[eMIOS_0] register field. */
            [!IF "num:i(count(ecu:list('MCU.eMIOS.List')))=2"!][!IF "McuLpuConfiguration/McuDisableEmios0='true'"!](LPU_MDIS_EMIOS_0_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_EMIOS_0_CLK_EN_U32) |[!ENDIF!][!ELSE!](LPU_MDIS_EMIOS_0_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[CMP_2] register field. */
            [!IF "McuLpuConfiguration/McuDisableCmp2='true'"!](LPU_MDIS_CMP_2_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_CMP_2_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[CMP_1] register field. */
            [!IF "McuLpuConfiguration/McuDisableCmp1='true'"!](LPU_MDIS_CMP_1_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_CMP_1_CLK_EN_U32) |[!ENDIF!]
            
            /* Configure the LPU_MDIS[CMP_0] register field. */
            [!IF "McuLpuConfiguration/McuDisableCmp0='true'"!](LPU_MDIS_CMP_0_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_CMP_0_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[MEMU_1] register field. */
            [!IF "McuLpuConfiguration/McuDisableMemu1='true'"!](LPU_MDIS_MEMU_1_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_MEMU_1_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[BCTU] register field. */
            [!IF "McuLpuConfiguration/McuDisableBctu='true'"!](LPU_MDIS_BCTU_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_BCTU_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[CAN0] register field. */
            [!IF "McuLpuConfiguration/McuDisableCan0='true'"!](LPU_MDIS_CAN0_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_CAN0_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[LIN_0] register field. */
            [!IF "McuLpuConfiguration/McuDisableLin0='true'"!](LPU_MDIS_LIN_0_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_LIN_0_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[SPI_0] register field. */
            [!IF "McuLpuConfiguration/McuDisableSpi0='true'"!](LPU_MDIS_SPI_0_CLK_DIS_U32) |[!ELSE!](LPU_MDIS_SPI_0_CLK_EN_U32) |[!ENDIF!]

            /* Configure the LPU_MDIS[ADC_0] register field. */
            [!IF "McuLpuConfiguration/McuDisableAdc0='true'"!](LPU_MDIS_ADC_0_CLK_DIS_U32)[!ELSE!](LPU_MDIS_ADC_0_CLK_EN_U32)[!ENDIF!]
        )
        
    }[!IF "$PCindex < $Mode"!],[!ENDIF!]/* end of Mcu_aLowPowerModeConfig[!"$Type"!][!"num:i($ConfigIndex)"!][[!"@index"!]]. */
    [!ELSE!][!//
    {(uint8)[!"num:i( num:i(McuMode) - 1 )"!]U, MCU_LPU_DRUN_MODE, (uint32)0U, (uint32)0U, (uint32)0U}[!IF "$PCindex < $Mode"!],[!ENDIF!]/* end of Mcu_aLowPowerModeConfig[!"$Type"!][!"num:i($ConfigIndex)"!][[!"@index"!]]. */
    [!ENDIF!][!//
[!ENDCODE!]
        [!ENDLOOP!]
[!CODE!]
};
[!ENDCODE!]
     [!ENDIF!]
[!ENDNOCODE!]
[!ENDIF!]
[!ENDMACRO!][!// 


[!MACRO "FLASH_Clock_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
/**
* @brief        Timing configuration for FLASH hw IP.
* @details      Set the Pipeline/Write/Read wait states for FLASH controller.
*               Configuration set by calling Mcu_InitClock API.
*/
#if (MCU_INIT_CLOCK == STD_ON)
static CONST( Mcu_FLASH_ClockConfigType, MCU_CONST) FLASH_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    /* Flash Controller timing settings. 
       PFCR1 configuration register: Address Pipelining Control & Read Wait State Control. */
    ( 
        MCU_FLASH_ADDR_PIPELINE_WS_U32((uint32)[!"num:i(McuFlash/McuFlashAddrPipelineControl)"!]) |
        MCU_FLASH_READ_WS_U32((uint32)[!"num:i(McuFlash/McuFlashReadWaitStateControl)"!])
    )
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "MC_CGM_PcsClock_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) MC_CGM_aPcsClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_CGM_NUMBER_OF_PCS_REGS] = 
{
    [!LOOP "McuProgClkSwitch/McuPcsConfig/*"!]
    {
        MC_CGM_PCS_DIVC[!"num:i(substring-after(McuPCS_Name,'PCS_'))"!]_ADDR32,
        MC_CGM_PCS_DIVC_U32
        (
            MC_CGM_PCS_DIVC_INIT_U32((uint32)[!"num:inttohex(num:i(McuPCS_DivInit),8)"!]U) |
            MC_CGM_PCS_DIVC_RATE_U32((uint32)[!"num:inttohex(num:i(McuPCS_DivRate),8)"!]U)
        )
    },
    {
        MC_CGM_PCS_DIVS[!"num:i(substring-after(McuPCS_Name,'PCS_'))"!]_ADDR32,
        MC_CGM_PCS_DIVS_U32((uint32)[!"num:inttohex(num:i(McuPCS_DivStart),8)"!]U)
    },
    {
        MC_CGM_PCS_DIVE[!"num:i(substring-after(McuPCS_Name,'PCS_'))"!]_ADDR32,
        MC_CGM_PCS_DIVE_U32((uint32)[!"num:inttohex(num:i(McuPCS_DivEnd),8)"!]U)
    },
    [!ENDLOOP!]
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "MC_CGM_SystemClock_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
        [!IF "McuClksysClockMcuControl='true'"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
        [!IF "McuClksysClockMcuControl='true'"!]
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) MC_CGM_aSystemClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_CGM_NUMBER_OF_SYSTEM_CLOCK_REGS] = 
{
    /* System Clock Divider 0 Configuration. */
    {
        MC_CGM_SC_DC0_ADDR32,
        MC_CGM_SYSCLK_DC0_DIVISOR_U32((uint32)[!"num:i(McuSystemClkDiv_Divider0)"!]U)
    },
    /* System Clock Divider 1 Configuration. */
    {
        MC_CGM_SC_DC1_ADDR32,
        MC_CGM_SYSCLK_DC1_DIVISOR_U32((uint32)[!"num:i(McuSystemClkDiv_Divider1)"!]U)
    },
    /* System Clock Divider 2 Configuration. */
    {
        MC_CGM_SC_DC2_ADDR32,
        MC_CGM_SYSCLK_DC2_DIVISOR_U32((uint32)[!"num:i(McuSystemClkDiv_Divider2)"!]U)
    },
    /* System Clock Divider 5 Configuration. */
    {
        MC_CGM_SC_DC5_ADDR32,
        MC_CGM_SYSCLK_DC5_DIVISOR_U32((uint32)[!"num:i(McuSystemClkDiv_Divider5)"!]U)
    }
};
    [!ENDIF!]
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
            [!ENDIF!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 



[!MACRO "MC_CGM_AuxClock_Config", "Type"!][!// 
[!NOCODE!]
        [!VAR "ConfigIndex" = "0"!]
        [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
            [!VAR "TheNumberOfAuxElements"="0"!]
            [!LOOP "*"!]
                [!IF "contains(@name,'McuAuxClock')='true'"!]
                    [!VAR "usedByMcu" = "concat('../',@name,'/','McuAuxClockUnderMcuControl')"!]
                    [!IF "(@name != 'McuAuxClock4') or (@name = 'McuAuxClock4' and (ecu:get('MCU.AuxClock4.Used') = 'true'))"!]
                        [!IF "node:value($usedByMcu)='true'"!]
                            [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 1"!]
                            [!IF " (ecu:get('MCU.ERR010609.EXIST') = 'true') and (@name = 'McuAuxClock6')"!][!//
                                [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 2"!]
                            [!ENDIF!]
                            [!LOOP "*"!]
                                [!IF "contains(@name,'_Divisor')"!]
                                    [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 1"!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "McuCLKOUT1/McuCLKOUT1UnderMcuControl='true'"!][!//   
                [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 2"!]
                [!IF " (ecu:get('MCU.ERR010609.EXIST') = 'true')"!][!//
                    [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 2"!]
                [!ENDIF!]
            [!ENDIF!]

[!IF "$TheNumberOfAuxElements != 0"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) MC_CGM_aAuxClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i($TheNumberOfAuxElements)"!]] = 
{
[!ENDCODE!][!//
[!CODE!][!//
    [!IF "McuCLKOUT1/McuCLKOUT1UnderMcuControl='true'"!][!//
        [!IF " (ecu:get('MCU.ERR010609.EXIST') = 'true')"!][!//
    /* Disable divider of CLKOUT1 */
    {
        MC_CGM_CLKOUT1_DC_ADDR32,
        MC_CGM_CLKOUT1_DC_U32
        (
            MC_CGM_CLKOUT1_DC_DIS_U32
        )
    },

    /* Select FIRC as source clock of CLKOUT1. */  
    {
        MC_CGM_CLKOUT1_SC_ADDR32,
        MC_CGM_CLKOUT1_U32(MC_CGM_CLKOUT1_SOURCE_FIRC_U32)
    },
        [!ENDIF!][!//

    /* CLKOUT1 Source Selection. */  
    {
        MC_CGM_CLKOUT1_SC_ADDR32,
        MC_CGM_CLKOUT1_U32([!IF "McuCLKOUT1/McuCLKOUT1_Source='FIRC'"!]MC_CGM_CLKOUT1_SOURCE_FIRC_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='FXOSC'"!]MC_CGM_CLKOUT1_SOURCE_FXOSC_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='SIRC'"!]MC_CGM_CLKOUT1_SOURCE_SIRC_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='SXOSC'"!]MC_CGM_CLKOUT1_SOURCE_SXOSC_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='PLL0_PHI0'"!]MC_CGM_CLKOUT1_SOURCE_PLL0_PHI0_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='SXOSC_Undiv'"!]MC_CGM_CLKOUT1_SOURCE_SXOSC_UNDIV_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='SIRC_Undiv'"!]MC_CGM_CLKOUT1_SOURCE_SIRC_UNDIV_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='LPU'"!]MC_CGM_CLKOUT1_SOURCE_LPU_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='RTC'"!]MC_CGM_CLKOUT1_SOURCE_RTC_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='Z2'"!]MC_CGM_CLKOUT1_SOURCE_Z2_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='FXOSC_ANALOG'"!]MC_CGM_CLKOUT1_SOURCE_FXOSC_ANALOG_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='FXOSC_Undiv'"!]MC_CGM_CLKOUT1_SOURCE_FXOSC_UNDIV_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='FIRC_Undiv'"!]MC_CGM_CLKOUT1_SOURCE_FIRC_UNDIV_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='CAN0_CHI'"!]MC_CGM_CLKOUT1_SOURCE_CAN0_CHI_U32[!ELSEIF "McuCLKOUT1/McuCLKOUT1_Source='CAN0_PE'"!]MC_CGM_CLKOUT1_SOURCE_CAN0_PE_U32[!ENDIF!])
    },
    
    /* CLKOUT1_DC Configuration. */  
    {
        MC_CGM_CLKOUT1_DC_ADDR32,
        MC_CGM_CLKOUT1_DC_U32
        ([!//
            [!IF "node:value(McuCLKOUT1/McuCLKOUT1Div_En)"!]
            MC_CGM_CLKOUT1_DC_EN_U32[!ELSE!]
            MC_CGM_CLKOUT1_DC_DIS_U32[!ENDIF!] |
            MC_CGM_CLKOUT1_DIV_U32((uint32)[!"node:value(McuCLKOUT1/McuCLKOUT1_Divisor)"!]U)
        )
    },
    [!ENDIF!][!//
[!ENDCODE!][!//
[!VAR "TheFirstAuxClock" = "1"!][!//
[!LOOP "*"!][!//
    [!IF "contains(@name, 'McuAuxClock') and ((@name != 'McuAuxClock4') or (@name = 'McuAuxClock4' and (ecu:get('MCU.AuxClock4.Used') = 'true')))"!][!//
        [!VAR "AuxClockNumber" = "substring-after(@name,'McuAuxClock')"!][!//
        [!IF "McuAuxClockUnderMcuControl='true'"!][!//
[!CODE!]
    [!IF "$TheFirstAuxClock = 1"!][!VAR "TheFirstAuxClock" = "0"!][!ELSE!],[!ENDIF!]
        [!IF " (ecu:get('MCU.ERR010609.EXIST') = 'true') and (@name = 'McuAuxClock6')"!][!//
    /* Disable Auxiliary Clock6 Divider0 */
    {
        MC_CGM_AC6_DC0_ADDR32,
        MC_CGM_AC6_DC0_U32
        (                        
            MC_CGM_AUXCLK6_DIV0_DIS_U32
        )
    },
    
    /* Select FIRC as source clock of Auxiliary Clock6. */
    {
        MC_CGM_AC6_SC_ADDR32,
        MC_CGM_AUXCLK6_U32(MC_CGM_AUXCLK6_SOURCE_FIRC_U32)
    },
        [!ENDIF!][!//

    /* Auxiliary Clock[!"$AuxClockNumber"!] Source Selection. */
    {
        MC_CGM_AC[!"$AuxClockNumber"!]_SC_ADDR32,
        MC_CGM_AUXCLK[!"$AuxClockNumber"!]_U32([!IF "McuAuxClk_Source='FIRC'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_FIRC_U32[!ELSEIF "McuAuxClk_Source='FXOSC'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_FXOSC_U32[!ELSEIF "McuAuxClk_Source='SIRC'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_SIRC_U32[!ELSEIF "McuAuxClk_Source='SXOSC'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_SXOSC_U32[!ELSEIF "McuAuxClk_Source='PLL0_PHI0'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_PLL0_PHI0_U32[!ELSEIF "McuAuxClk_Source='PLL0_PHI1'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_PLL0_PHI1_U32[!ELSEIF "McuAuxClk_Source='SXOSC_Undiv'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_SXOSC_UNDIV_U32[!ELSEIF "McuAuxClk_Source='SIRC_Undiv'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_SIRC_UNDIV_U32[!ELSEIF "McuAuxClk_Source='LPU'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_LPU_U32[!ELSEIF "McuAuxClk_Source='RTC'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_RTC_U32[!ELSEIF "McuAuxClk_Source='Z2'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_Z2_U32[!ELSEIF "McuAuxClk_Source='FXOSC_ANALOG'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_FXOSC_ANALOG_U32[!ELSEIF "McuAuxClk_Source='FXOSC_Undiv'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_FXOSC_UNDIV_U32[!ELSEIF "McuAuxClk_Source='FIRC_Undiv'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_FIRC_UNDIV_U32[!ELSEIF "McuAuxClk_Source='CAN0_CHI'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_CAN0_CHI_U32[!ELSEIF "McuAuxClk_Source='CAN0_PE'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_CAN0_PE_U32[!ELSEIF "McuAuxClk_Source='EXTAL'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_EXTAL_U32[!ELSEIF "McuAuxClk_Source='F40'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_F40_U32[!ELSEIF "McuAuxClk_Source='S160'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_S160_U32[!ELSEIF "McuAuxClk_Source='Z4a'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_Z4A_U32[!ELSEIF "McuAuxClk_Source='Z4b'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_Z4B_U32[!ELSEIF "McuAuxClk_Source='HSM_CORE_CLK'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_HSM_CORE_CLK_U32[!ELSEIF "McuAuxClk_Source='S40'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_S40_U32[!ELSEIF "McuAuxClk_Source='F80'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_F80_U32[!ELSEIF "McuAuxClk_Source='FS80'"!]MC_CGM_AUXCLK[!"$AuxClockNumber"!]_SOURCE_FS80_U32[!ENDIF!])
    }
[!ENDCODE!]
            [!VAR "NumberOfDividers"="0"!][!//
            [!LOOP "*"!][!//
            [!IF "contains(@name, 'McuAuxClkDiv')"!][!//
                [!IF "num:i(substring-after(@name, 'McuAuxClkDiv')) >= num:i($NumberOfDividers)"!][!// 
                    [!VAR "NumberOfDividers"="num:i(substring-after(@name, 'McuAuxClkDiv')) + 1"!][!//
                [!ENDIF!][!//
            [!ENDIF!][!//
            [!ENDLOOP!][!//
            [!IF "$NumberOfDividers != 0"!][!//
                [!FOR "CurrentAuxClkDiv" = "0" TO "$NumberOfDividers - 1"!][!//
[!CODE!]
    ,
    {
        MC_CGM_AC[!"$AuxClockNumber"!]_DC[!"$CurrentAuxClkDiv"!]_ADDR32,
        /* Auxiliary Clock[!"$AuxClockNumber"!] Divider[!"$CurrentAuxClkDiv"!] Configuration. */
        MC_CGM_AC[!"$AuxClockNumber"!]_DC[!"$CurrentAuxClkDiv"!]_U32
        ([!//
            [!IF "node:exists(concat('McuAuxClkDiv',$CurrentAuxClkDiv,'_En'))"!][!//
            [!IF "node:value(concat('McuAuxClkDiv',$CurrentAuxClkDiv,'_En'))"!]
            MC_CGM_AUXCLK[!"$AuxClockNumber"!]_DIV[!"$CurrentAuxClkDiv"!]_EN_U32[!ELSE!]
            MC_CGM_AUXCLK[!"$AuxClockNumber"!]_DIV[!"$CurrentAuxClkDiv"!]_DIS_U32[!ENDIF!] | [!//
            [!ENDIF!]
            MC_CGM_AUXCLK[!"$AuxClockNumber"!]_DIV[!"$CurrentAuxClkDiv"!]_U32((uint32)[!"node:value(concat('McuAuxClkDiv',$CurrentAuxClkDiv,'_Divisor'))"!]U)
        )
    }
[!ENDCODE!]
                [!ENDFOR!][!//
            [!ENDIF!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!CODE!]  
};

#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
[!ENDIF!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "MC_CGM_Clock_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
            [!VAR "TheNumberOfAuxElements"="0"!]
            [!LOOP "*"!]
                [!IF "contains(@name,'McuAuxClock')='true'"!]
                    [!VAR "usedByMcu" = "concat('../',@name,'/','McuAuxClockUnderMcuControl')"!]
                    [!IF "(@name != 'McuAuxClock4') or (@name = 'McuAuxClock4' and (ecu:get('MCU.AuxClock4.Used') = 'true'))"!]
                        [!IF "node:value($usedByMcu)='true'"!]
                            [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 1"!]
                            [!IF " (ecu:get('MCU.ERR010609.EXIST') = 'true') and (@name = 'McuAuxClock6')"!][!//
                                [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 2"!]
                            [!ENDIF!]
                            [!LOOP "*"!]
                                [!IF "contains(@name,'_Divisor')"!]
                                    [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 1"!]
                                [!ENDIF!]
                            [!ENDLOOP!]
                        [!ENDIF!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!]
            [!IF "McuCLKOUT1/McuCLKOUT1UnderMcuControl='true'"!][!//   
                [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 2"!]
                [!IF " (ecu:get('MCU.ERR010609.EXIST') = 'true')"!][!//
                    [!VAR "TheNumberOfAuxElements" = "$TheNumberOfAuxElements + 2"!]
                [!ENDIF!]
            [!ENDIF!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            MC_CGM IP clock configuration.
* @details          This structure contains information for IRCOSC, XOSC, PLL, Output Clocks, CMUs
*
*/
static CONST( Mcu_MC_CGM_ClockConfigType, MCU_CONST) MC_CGM_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    /* These clock sources must be powered on for the current clock setting */
    (
        [!IF "McuClkSetFXOSC_En='true'"!]MC_ME_FXOSC_EN_U32[!ELSE!]MC_ME_FXOSC_DIS_U32[!ENDIF!] |
        [!IF "McuClkSetSXOSC_En='true'"!]MC_ME_SXOSC_EN_U32[!ELSE!]MC_ME_SXOSC_DIS_U32[!ENDIF!] |
        [!IF "McuClkSetFIRCOSC_En='true'"!]MC_ME_FIRC_EN_U32[!ELSE!]MC_ME_FIRC_DIS_U32[!ENDIF!] |
        [!IF "McuClkSetSIRCOSC_En='true'"!]MC_ME_SIRC_EN_U32[!ELSE!]MC_ME_SIRC_DIS_U32[!ENDIF!] |
        [!IF "McuClkSetPLL0_En='true'"!]MC_ME_PLL0_EN_U32[!ELSE!]MC_ME_PLL0_DIS_U32[!ENDIF!]
    ),
    
    /* Progressive Clock Switching (CGM_PCS_SDUR[SDUR]) */
    MC_CGM_PCS_SDUR_U8([!"num:inttohex(num:i(McuProgClkSwitch/McuProgresSwitchDuration),2)"!]U),
    
    /* This is used as a mask to set the divider update mask and to triger a divider update after register update */
    MC_CGM_DIV_UPD_TYPE_U32(
        [!IF "McuAuxClock6/McuAuxClockUnderMcuControl='true'"!]MC_CGM_DIV_UPD_TYPE_AUX6_UPD_TYPE_EN_U32[!ELSE!]MC_CGM_DIV_UPD_TYPE_AUX6_UPD_TYPE_DIS_U32[!ENDIF!]
    ),
    
    /* number of pcs registers unde mcu control */
    MCU_CGM_NUMBER_OF_PCS_REGS,
    /* pcs registers */
     &MC_CGM_aPcsClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    
    /* number of sys clock regs unde mcu control */
    [!IF "McuClksysClockMcuControl='true'"!]MCU_CGM_NUMBER_OF_SYSTEM_CLOCK_REGS[!ELSE!](uint8)0x00U[!ENDIF!],
    /* system clock configuration */
    [!IF "McuClksysClockMcuControl='true'"!]&MC_CGM_aSystemClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!](NULL_PTR)[!ENDIF!],
    
    /* number of configurable aux clock regs */
    ((uint8)[!"num:i($TheNumberOfAuxElements)"!]U),
    /* auxiliary clock dividers */
    [!IF "num:i($TheNumberOfAuxElements)>0"!]&MC_CGM_aAuxClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ELSE!](NULL_PTR)[!ENDIF!]
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "Mcu_SIRC_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
[!IF "McuSIRC/McuSIRCUnderMcuControl"!]
#if (MCU_INIT_CLOCK == STD_ON)            
/**
* @brief            SIRC clock configuration.
* @details          This structure contains information for SIRC 128Khz oscillator.
*
*/
static CONST( Mcu_SIRC_ConfigType, MCU_CONST) Mcu_SIRC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    /* Control register */
    SIRC_CTL_VALUE_U32( SIRC_CTL_SIRCDIV_VALUE_U32( (uint32)[!"num:i(num:i(McuSIRC/McuSIRC_Div)-1)"!]U ) )
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
[!ENDIF!]
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "Mcu_FIRC_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
[!IF "McuFIRC/McuFIRCUnderMcuControl"!]
#if (MCU_INIT_CLOCK == STD_ON)            
/**
* @brief            FIRC clock configuration.
* @details          This structure contains information for FIRC 16Mhz oscillator.
*
*/
static CONST( Mcu_FIRC_ConfigType, MCU_CONST) Mcu_FIRC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    /* Control register */
    FIRC_CTL_VALUE_U32( FIRC_CTL_FIRCDIV_VALUE_U32( (uint32)[!"num:i(num:i(McuFIRC/McuFIRC_Div)-1)"!]U ) )
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
[!ENDIF!]
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "Mcu_SXOSC_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
            
[!IF "McuSXOSC/McuSXOSCUnderMcuControl"!]
#if (MCU_INIT_CLOCK == STD_ON)            
/**
* @brief            SXOSC clock configuration.
* @details          This structure contains information for SXOSC 32.767Khz oscillator.
*
*/
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SXOSC_ConfigType, MCU_CONST) Mcu_SXOSC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    /* Control register */
    SXOSC_CTL_VALUE_U32(
        [!IF "McuSXOSC/McuSXOSC_OSCBYP"!]SXOSC_CTL_OSCBYP_OUTPUT_USED_U32[!ELSE!]SXOSC_CTL_OSCBYP_OUTPUT_NOT_USED_U32[!ENDIF!] |
        [!IF "McuSXOSC/McuSXOSC_ALC"!]SXOSC_CTL_ALC_ENABLE_U32[!ELSE!]SXOSC_CTL_ALC_DISABLE_U32[!ENDIF!] |
        SXOSC_CTL_EOCV_VALUE_U32( (uint32)[!"McuSXOSC/McuSXOSC_EOCV"!]U ) |
        [!IF "McuSXOSC/McuSXOSC_M_OSC"!]SXOSC_CTL_M_OSC_ENABLE_U32[!ELSE!]SXOSC_CTL_M_OSC_DISABLE_U32[!ENDIF!] |
        SXOSC_CTL_OSCDIV_VALUE_U32( (uint32)[!"num:i(num:i(McuSXOSC/McuSXOSC_Div)-1)"!]U )
    )
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
[!ENDIF!]
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 

[!MACRO "Mcu_FXOSC_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
[!IF "McuFXOSC/McuFXOSCUnderMcuControl"!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            FXOSC clock configuration.
* @details          This structure contains information for FXOSC.
*
*/
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_FXOSC_ConfigType, MCU_CONST) Mcu_FXOSC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    /* Control register */
    FXOSC_CTL_VALUE_U32(
        [!IF "McuFXOSC/McuFXOSC_OSCBYP"!]FXOSC_CTL_OSCBYP_OUTPUT_USED_U32[!ELSE!]FXOSC_CTL_OSCBYP_OUTPUT_NOT_USED_U32[!ENDIF!] |
        [!IF "McuFXOSC/McuFXOSC_OSCM"!]FXOSC_CTL_MODE_LCP_U32[!ELSE!]FXOSC_CTL_MODE_FSP_U32[!ENDIF!] |
        FXOSC_CTL_EOCV_VALUE_U32( (uint32)[!"McuFXOSC/McuFXOSC_EOCV"!]U ) |
        [!IF "McuFXOSC/McuFXOSC_M_OSC"!]FXOSC_CTL_M_OSC_ENABLE_U32[!ELSE!]FXOSC_CTL_M_OSC_DISABLE_U32[!ENDIF!] |
        FXOSC_CTL_OSCDIV_VALUE_U32( (uint32)[!"num:i(num:i(McuFXOSC/McuFXOSC_Div)-1)"!]U )
    )
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
[!ENDIF!]
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 



[!MACRO "Mcu_PLL_REG_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
        [!VAR "NumberOfPLLsUnderMcuControl"="0"!]
        [!LOOP "*"!]
            [!IF "contains(@name,'McuPll_')='true'"!]
                [!VAR "usedByMcu" = "concat('../',@name,'/','McuPLLUnderMcuControl')"!]
                [!IF "node:value($usedByMcu)='true'"!]
                    [!VAR "NumberOfPLLsUnderMcuControl" = "$NumberOfPLLsUnderMcuControl + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!VAR "TheFirstPLL" = "1"!]    
[!CODE!]    
[!IF "$NumberOfPLLsUnderMcuControl != 0"!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            PLLDIG Registers configuration.
* @details          This structure contains configuration for PLLDIG Registers.
*
*/
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_PLLDIG_RegisterConfigType, MCU_CONST) Mcu_PLLDIG_aRegistersConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!IF "ecu:get('MCU.EXPDIE.EXIST') = 'true'"!][!"num:i(6 * $NumberOfPLLsUnderMcuControl)"!][!ELSE!][!"num:i(5 * $NumberOfPLLsUnderMcuControl)"!][!ENDIF!]U] = 
{
    [!IF "McuPll_0/McuPLLUnderMcuControl = 'true'"!]
    [!IF "$TheFirstPLL=0.0"!],[!ENDIF!][!VAR "TheFirstPLL" = "0"!]
    /* PLL0 configuration */
    {
        PLLDIG_PLL0CAL3_ADDR32,
        MCU_PLLDIG_PLL0CAL3_U32( MCU_PLLDIG_PLL0CAL3_MDFEN_U32( (uint32)[!"num:i(McuPll_0/McuPll_Configuration/McuPllCal3Mfden)"!]U ) )
    },
    [!IF "ecu:get('MCU.EXPDIE.EXIST') = 'true'"!][!//
    {
        PLLDIG_PLL0CAL1_ADDR32,
        [!IF "McuPll_0/McuPll_Configuration/McuPllCalBypcal"!]MCU_PLLDIG_PLL0CAL1_BYPASS_EN_U32[!ELSE!]MCU_PLLDIG_PLL0CAL1_BYPASS_DIS_U32[!ENDIF!]
    },
    [!ENDIF!][!//
    {
        PLLDIG_PLL0CR_ADDR32,
        (
[!IF "ecu:get('MCU.EXPDIE.EXIST') = 'true'"!][!//
            [!IF "McuPll_0/McuPll_Configuration/McuExternalPowerDownCycleInt"!]MCU_PLLDIG_PLL0CR_EXPDIE_ENA_U32[!ELSE!]MCU_PLLDIG_PLL0CR_EXPDIE_DIS_U32[!ENDIF!] |
[!ENDIF!][!//
            [!IF "McuPll_0/McuPll_Configuration/McuPllCrLolie"!]MCU_PLLDIG_PLL0CR_LOLIE_ENA_U32[!ELSE!]MCU_PLLDIG_PLL0CR_LOLIE_DIS_U32[!ENDIF!] |
            [!IF "McuPll_0/McuPll_Configuration/McuPllCrLolre"!]MCU_PLLDIG_PLL0CR_LOLRE_ENA_U32[!ELSE!]MCU_PLLDIG_PLL0CR_LOLRE_DIS_U32[!ENDIF!]
        )
    },
    {
        PLLDIG_PLL0DV_ADDR32,
        MCU_PLLDIG_PLL0DV_U32(
            MCU_PLLDIG_PLL0DV_RFDPHI1_U32( (uint32)[!"num:i(McuPll_0/McuPll_Configuration/McuPllDvRfdphi1)"!]U ) | 
            MCU_PLLDIG_PLL0DV_RFDPHI_U32( (uint32)[!"num:i(McuPll_0/McuPll_Configuration/McuPllDvRfdphi)"!]U ) |
            MCU_PLLDIG_PLL0DV_PREDIV_U32( (uint32)[!"num:i(McuPll_0/McuPll_Configuration/McuPllDvPrediv)"!]U ) |
            MCU_PLLDIG_PLL0DV_MFD_U32( (uint32)[!"num:i(McuPll_0/McuPll_Configuration/McuPllDvMfd)"!]U )
        )
    },
    {
        PLLDIG_PLL0FM_ADDR32,
        MCU_PLLDIG_PLL0FM_U32(
            [!IF "McuPll_0/McuPll_Configuration/McuPllFmSscgbyp"!]MCU_PLLDIG_PLL0FM_SSCGBYP_ENA_U32[!ELSE!]MCU_PLLDIG_PLL0FM_SSCGBYP_DIS_U32[!ENDIF!] |
            MCU_PLLDIG_PLL0FM_MODPRD_U32( (uint32)[!"num:i(McuPll_0/McuPll_Configuration/McuPllFmStepsize)"!]U ) |
            MCU_PLLDIG_PLL0FM_INCSTP_U32( (uint32)[!"num:i(McuPll_0/McuPll_Configuration/McuPllFmStepno)"!]U )
        )
    },
    {
        PLLDIG_PLL0FD_ADDR32,
        MCU_PLLDIG_PLL0FD_U32(
            [!IF "McuPll_0/McuPll_Configuration/McuPllFdSmden"!]MCU_PLLDIG_PLL0FD_SMDEN_DIS_U32[!ELSE!]MCU_PLLDIG_PLL0FD_SMDEN_ENA_U32[!ENDIF!] |
            [!IF "McuPll_0/McuPll_Configuration/McuPllFdSdm2"!]MCU_PLLDIG_PLL0FD_SDM2_ENA_U32[!ELSE!]MCU_PLLDIG_PLL0FD_SDM2_DIS_U32[!ENDIF!] |
            [!IF "McuPll_0/McuPll_Configuration/McuPllFdSdm3"!]MCU_PLLDIG_PLL0FD_SDM3_ENA_U32[!ELSE!]MCU_PLLDIG_PLL0FD_SDM3_DIS_U32[!ENDIF!] |
            MCU_PLLDIG_PLL0FD_DTHDIS_U32( [!IF "McuPll_0McuPll_Configuration//McuPllFdDthDis"!]((uint32)1U )[!ELSE!](uint32)0U )[!ENDIF!] |
            MCU_PLLDIG_PLL0FD_MFN_U32( (uint32)[!"num:i(McuPll_0/McuPll_Configuration/McuPllFdMfn)"!]U )
        )
    }
    [!ENDIF!]
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
[!ENDIF!]
[!ENDCODE!]
        [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 

[!MACRO "Mcu_PLLDIG_Config","Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
        [!VAR "NumberOfPLLsUnderMcuControl"="0"!]
        [!LOOP "*"!]
            [!IF "contains(@name,'McuPll_')='true'"!]
                [!VAR "usedByMcu" = "concat('../',@name,'/','McuPLLUnderMcuControl')"!]
                [!IF "node:value($usedByMcu)='true'"!]
                    [!VAR "NumberOfPLLsUnderMcuControl" = "$NumberOfPLLsUnderMcuControl + 1"!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            PLLDIG clock configuration.
* @details          This structure contains information for PLLDIG PLL0 and FMPLL1.
*
*/
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_PLLDIG_ConfigType, MCU_CONST) Mcu_PLLDIG_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* number of pll regs under mcu control */
     ((uint8)[!IF "ecu:get('MCU.EXPDIE.EXIST') = 'true'"!][!"num:i(6 * $NumberOfPLLsUnderMcuControl)"!][!ELSE!][!"num:i(5 * $NumberOfPLLsUnderMcuControl)"!][!ENDIF!]U),
    [!IF "$NumberOfPLLsUnderMcuControl != 0"!]
    &Mcu_PLLDIG_aRegistersConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
    [!ELSE!]
    (NULL_PTR)
    [!ENDIF!]
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "EMIOS_Module_Config","Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_EMIOS_SUPPORT == STD_ON)
/**
* @brief            eMios Module Configuration.
* @details          This structure contains information for eMios0 and eMios1.
*
*/
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_6 MISRA 2004 Required Rule 20.2, The names of standard macros, objects and functions shall not be reused */
static CONST(Mcu_eMios_ConfigType, MCU_CONST) EMIOS_ModuleConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    {
        /* eMios0 configuration */
        EMIOS_MCR_U32
        (
            [!IF "McuEMIOS/McuEMIOS_0/McuMdisBit"!]EMIOS_MCR_MDIS_ENA_U32[!ELSE!]EMIOS_MCR_MDIS_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_0/McuFreezeBit"!]EMIOS_MCR_FRZ_ENA_U32[!ELSE!]EMIOS_MCR_FRZ_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_0/McuGlobalTimeBaseEnable"!]EMIOS_MCR_GTBE_ENA_U32[!ELSE!]EMIOS_MCR_GTBE_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_0/McuExternalTimeBase"!]EMIOS_MCR_ETB_ENA_U32[!ELSE!]EMIOS_MCR_ETB_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_0/McuGlobalPrescalerEnable"!]EMIOS_MCR_GPREN_ENA_U32[!ELSE!]EMIOS_MCR_GPREN_DIS_U32[!ENDIF!] |
            EMIOS_MCR_GPRE_U32((uint32)[!"num:i(McuEMIOS/McuEMIOS_0/McuGlobalPrescaler)"!]U)
        ),
        /* eMios1 configuration */
        EMIOS_MCR_U32
        (
            [!IF "McuEMIOS/McuEMIOS_1/McuMdisBit"!]EMIOS_MCR_MDIS_ENA_U32[!ELSE!]EMIOS_MCR_MDIS_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_1/McuFreezeBit"!]EMIOS_MCR_FRZ_ENA_U32[!ELSE!]EMIOS_MCR_FRZ_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_1/McuGlobalTimeBaseEnable"!]EMIOS_MCR_GTBE_ENA_U32[!ELSE!]EMIOS_MCR_GTBE_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_1/McuExternalTimeBase"!]EMIOS_MCR_ETB_ENA_U32[!ELSE!]EMIOS_MCR_ETB_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_1/McuGlobalPrescalerEnable"!]EMIOS_MCR_GPREN_ENA_U32[!ELSE!]EMIOS_MCR_GPREN_DIS_U32[!ENDIF!] |
            EMIOS_MCR_GPRE_U32((uint32)[!"num:i(McuEMIOS/McuEMIOS_1/McuGlobalPrescaler)"!]U)
        )[!IF "num:i(count(ecu:list('MCU.eMIOS.List')))=3"!],
        /* eMios2 configuration */
        EMIOS_MCR_U32
        (
            [!IF "McuEMIOS/McuEMIOS_2/McuMdisBit"!]EMIOS_MCR_MDIS_ENA_U32[!ELSE!]EMIOS_MCR_MDIS_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_2/McuFreezeBit"!]EMIOS_MCR_FRZ_ENA_U32[!ELSE!]EMIOS_MCR_FRZ_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_2/McuGlobalTimeBaseEnable"!]EMIOS_MCR_GTBE_ENA_U32[!ELSE!]EMIOS_MCR_GTBE_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_2/McuExternalTimeBase"!]EMIOS_MCR_ETB_ENA_U32[!ELSE!]EMIOS_MCR_ETB_DIS_U32[!ENDIF!] |
            [!IF "McuEMIOS/McuEMIOS_2/McuGlobalPrescalerEnable"!]EMIOS_MCR_GPREN_ENA_U32[!ELSE!]EMIOS_MCR_GPREN_DIS_U32[!ENDIF!] |
            EMIOS_MCR_GPRE_U32((uint32)[!"num:i(McuEMIOS/McuEMIOS_2/McuGlobalPrescaler)"!]U)
        )[!ENDIF!]
    }
};
#endif /* (MCU_EMIOS_SUPPORT == STD_ON) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!//

[!MACRO "MC_CMU_Config", "Type"!][!// 
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            CMU configuration.
* @details          This structure contains information for CMU[n]. 
*                   The number of CMU's is defined in the resource files, 
*
*/
static CONST( Mcu_CMU_ConfigType, MCU_CONST) Mcu_CMU_Config[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    {
[!ENDCODE!]
            [!VAR "cmuCfgMax"="ecu:get('MCU.CMU.UNITS')"!]
            [!VAR "cmuCfgMax" = "$cmuCfgMax - 1 "!]
            [!FOR "cmuCfgIndex" = "0" TO "$cmuCfgMax" STEP "1"!]
                [!VAR "enable" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuClkMonitorEn')"!]
                [!VAR "cmuTmp" ="concat('McuClkMonitor_',$cmuCfgIndex)"!]
                [!IF "node:exists($enable)"!]
                    [!VAR "div" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuRCDivisorFactor')"!]
[!CODE!]
        /* [!"$cmuTmp"!] config */
        CMU_CSR_U32
        (
            [!IF "node:value($enable)"!]CMU_CSR_CMU_ENA_U32 |[!ELSE!]CMU_CSR_CMU_DIS_U32 |[!ENDIF!]
            [!IF "node:value($enable)"!][!IF "node:value($div) = 'DIV_1'"!]CMU_CSR_RCDIV_1_U32[!ELSEIF "node:value($div) = 'DIV_2'"!]CMU_CSR_RCDIV_2_U32[!ELSEIF "node:value($div) = 'DIV_4'"!]CMU_CSR_RCDIV_4_U32[!ELSEIF "node:value($div) = 'DIV_8'"!]CMU_CSR_RCDIV_8_U32[!ENDIF!][!ELSE!]CMU_CSR_RCDIV_1_U32[!ENDIF!]
        )[!IF "$cmuCfgIndex < $cmuCfgMax"!],[!ENDIF!]
[!ENDCODE!]
                [!ENDIF!]
            [!ENDFOR!]
[!CODE!]
    },
    {
[!ENDCODE!]
            [!VAR "cmuCfgMax"="ecu:get('MCU.CMU.UNITS')"!]
            [!VAR "cmuCfgMax" = "$cmuCfgMax - 1 "!]
            [!FOR "cmuCfgIndex" = "0" TO "$cmuCfgMax" STEP "1"!]
                [!VAR "hf" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuHighFrequencyRef')"!]
                [!VAR "enable" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuClkMonitorEn')"!]
                [!VAR "cmuTmp" ="concat('McuClkMonitor_',$cmuCfgIndex)"!]
                [!IF "node:exists($enable)"!]
[!CODE!]
        /* [!"$cmuTmp"!] hfRefr */
        CMU_HFREFR_VALUE_U32
        (
            (uint32)[!IF "node:value($enable)"!][!"num:i(node:value($hf))"!][!ELSE!]0[!ENDIF!]U
        )[!IF "$cmuCfgIndex < $cmuCfgMax"!],[!ENDIF!]
[!ENDCODE!]
                [!ENDIF!]
            [!ENDFOR!]
[!CODE!]
    },
    {
[!ENDCODE!]
            [!VAR "cmuCfgMax"="ecu:get('MCU.CMU.UNITS')"!]
            [!VAR "cmuCfgMax" = "$cmuCfgMax - 1 "!]
            [!FOR "cmuCfgIndex" = "0" TO "$cmuCfgMax" STEP "1"!]
                [!VAR "lf" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuLowFrequencyRef')"!]
                [!VAR "enable" ="concat('McuClkMonitor_',$cmuCfgIndex,'/McuClkMonitorEn')"!]
                [!VAR "cmuTmp" ="concat('McuClkMonitor_',$cmuCfgIndex)"!]
                [!IF "node:exists($enable)"!]
[!CODE!]
        /* [!"$cmuTmp"!] lfRefr */
        CMU_LFREFR_VALUE_U32
        (
            (uint32)[!IF "node:value($enable)"!][!"num:i(node:value($lf))"!][!ELSE!]0[!ENDIF!]U
        )[!IF "$cmuCfgIndex < $cmuCfgMax"!],[!ENDIF!]
[!ENDCODE!]
                [!ENDIF!]
            [!ENDFOR!]
[!CODE!]
    }
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "PRAM_Clock_Config", "Type"!][!//
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
    [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief        Timing configuration for SRAMC hw IP.
* @details      Set the Read wait states for RAM.
*               Configuration set by calling Mcu_InitClock API.
*/
static CONST( Mcu_PRAM_ClockConfigType, MCU_CONST) SRAMC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] = 
{
    /* PRCR1 configuration register. */
    PRAMC_PRCR1_VALUE_U32(
        PRAMC_PRCR1_PRI_VALUE_U32((uint32)[!"num:i(McuRam/McuRamPRAMC_0_PRCR1/McuPRI)"!]U)|
        [!IF "McuRam/McuRamPRAMC_0_PRCR1/McuP1BODIS = 'true'"!]PRAMC_PRCR1_P1_BO_DIS_U32[!ELSE!]PRAMC_PRCR1_P1_BO_ENA_U32[!ENDIF!]|
        [!IF "McuRam/McuRamPRAMC_0_PRCR1/McuP0BODIS = 'true'"!]PRAMC_PRCR1_P0_BO_DIS_U32[!ELSE!]PRAMC_PRCR1_P0_BO_ENA_U32[!ENDIF!]|
        [!IF "McuRam/McuRamPRAMC_0_PRCR1/McuFT_DIS = '1'"!]PRAMC_PRCR1_FT_DIS_U32[!ELSE!]PRAMC_PRCR1_FT_ENA_U32[!ENDIF!]
    ),
    PRAMC_PRCR1_VALUE_U32(
        [!IF "McuRam/McuRamPRAMC_1_PRCR1/McuP0BODIS = 'true'"!]PRAMC_PRCR1_P0_BO_DIS_U32[!ELSE!]PRAMC_PRCR1_P0_BO_ENA_U32[!ENDIF!]|
        [!IF "McuRam/McuRamPRAMC_1_PRCR1/McuFT_DIS = '1'"!]PRAMC_PRCR1_FT_DIS_U32[!ELSE!]PRAMC_PRCR1_FT_ENA_U32[!ENDIF!]
    )[!IF "ecu:get('MCU.MultiplePRAM')"!],
    PRAMC_PRCR1_VALUE_U32(
        [!IF "McuRam/McuRamPRAMC_2_PRCR1/McuP0BODIS = 'true'"!]PRAMC_PRCR1_P0_BO_DIS_U32[!ELSE!]PRAMC_PRCR1_P0_BO_ENA_U32[!ENDIF!]|
        [!IF "McuRam/McuRamPRAMC_2_PRCR1/McuFT_DIS = '1'"!]PRAMC_PRCR1_FT_DIS_U32[!ELSE!]PRAMC_PRCR1_FT_ENA_U32[!ENDIF!]
    )[!ENDIF!]
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
    [!ENDLOOP!][!//McuClockSettingConfig/*
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "Mcu_Clock_Config", "Type"!][!//
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief          Initialization clock data.
* @details        Static configuration realized by calling Mcu_InitClock() API.
*
*/
static CONST( Mcu_ClockConfigType, MCU_CONST) Mcu_aClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][[!"num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]] =  
{
[!ENDCODE!]
        [!IF "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))>0"!]
            [!VAR "ClockConfigs"= "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))-1"!]
            [!LOOP "McuModuleConfiguration/McuClockSettingConfig/*"!]
                [!CODE!]
    /* Start of Mcu_ClockConfig[[!"@index"!]]. */
    {
[!ENDCODE!]
                [!VAR "PCindex" = "@index"!]
[!CODE!]
        /* ID Clock Configuration. */
        (uint8)[!"num:i( num:i(McuClockSettingId)-1 )"!]U,

        /* Globally enable/disable SCM, loss of clock and loss of lock notification. */
        ([!IF "num:i(count(*/McuClkMonitorEn[.='true'])) >= 1"!]MCU_CLK_NOTIF_EN[!ELSE!]MCU_CLK_NOTIF_DIS[!ENDIF!]),
        
        /* System Clock Selection. 
           This affect the Mode settings from MC_ME IP. */
        (
[!ENDCODE!]
        [!IF "McuSystemClockSwitch='FIRC'"!]
            [!CODE!]MC_ME_SYSCLK_FIRC_U32 | MC_ME_FIRC_EN_U32[!ENDCODE!]
        [!ELSEIF "McuSystemClockSwitch='FXOSC'"!]
            [!CODE!]MC_ME_SYSCLK_FXOSC_U32 | MC_ME_FXOSC_EN_U32[!ENDCODE!]
        [!ELSEIF "McuSystemClockSwitch='PLL0_PHI0'"!]
            [!CODE!]MC_ME_SYSCLK_PLL0_U32 | MC_ME_PLL0_EN_U32 [!ENDCODE!]
        [!ENDIF!]
[!CODE!]
        ),

        /* MC_CGM IP Clock settings. */
        &MC_CGM_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        
        /* PLLDIG IP Clock settings. */
        &Mcu_PLLDIG_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
                
#if (MCU_EMIOS_SUPPORT == STD_ON)
        /* eMios Module settings. */
        &EMIOS_ModuleConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#endif
        /* CMU IP Clock settings. */
        &Mcu_CMU_Config[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        
        /* FIRC IP Clock settings. */
        [!IF "McuFIRC/McuFIRCUnderMcuControl"!]
        &Mcu_FIRC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        [!ELSE!]
        (NULL_PTR),
        [!ENDIF!]
        
        /* SIRC IP Clock settings. */
        [!IF "McuSIRC/McuSIRCUnderMcuControl"!]
        &Mcu_SIRC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        [!ELSE!]
        (NULL_PTR),
        [!ENDIF!]
        
        /* FXOSC IP Clock settings. */
        [!IF "McuFXOSC/McuFXOSCUnderMcuControl"!]
        &Mcu_FXOSC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        [!ELSE!]
        (NULL_PTR),
        [!ENDIF!]
        
        /* SXOSC IP Clock settings. */
        [!IF "McuSXOSC/McuSXOSCUnderMcuControl"!]
        &Mcu_SXOSC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        [!ELSE!]
        (NULL_PTR),
        [!ENDIF!]
        
#if (MCU_SRAMC_SUPPORT == STD_ON)
        /* SRAMC IP Clock settings. */
         &SRAMC_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
#endif /* (MCU_SRAMC_SUPPORT == STD_ON) */

        /* FLASH IP Clock settings. */
        &FLASH_ClockConfig[!"$Type"!][!"num:i($ConfigIndex)"!]_[!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
        
        ([!IF "McuFIRC/McuFIRCUnderMcuControl"!] MCU_IPW_FIRC_UNDER_MCU_CONTROL | [!ELSE!] MCU_IPW_FIRC_NOT_UNDER_MCU_CONTROL | [!ENDIF!]
        [!IF "McuSIRC/McuSIRCUnderMcuControl"!] MCU_IPW_SIRC_UNDER_MCU_CONTROL | [!ELSE!] MCU_IPW_SIRC_NOT_UNDER_MCU_CONTROL | [!ENDIF!]
        [!IF "McuSXOSC/McuSXOSCUnderMcuControl"!] MCU_IPW_SXOSC_UNDER_MCU_CONTROL | [!ELSE!] MCU_IPW_SXOSC_NOT_UNDER_MCU_CONTROL | [!ENDIF!]
        [!IF "McuFXOSC/McuFXOSCUnderMcuControl"!] MCU_IPW_FXOSC_UNDER_MCU_CONTROL | [!ELSE!] MCU_IPW_FXOSC_NOT_UNDER_MCU_CONTROL  | [!ENDIF!]
        [!IF "McuPll_0/McuPLLUnderMcuControl"!] MCU_IPW_PLL0_UNDER_MCU_CONTROL [!ELSE!] MCU_IPW_PLL0_NOT_UNDER_MCU_CONTROL [!ENDIF!])
        
    }[!IF "$PCindex < $ClockConfigs"!],[!ENDIF!]         /* end of Mcu_ClockConfig[[!"@index"!]] */
[!ENDCODE!]
            [!ENDLOOP!][!//McuClockSettingConfig/*
[!CODE!]
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */
[!ENDCODE!]
        [!ENDIF!]
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "MC_RGM_Config", "Type"!][!//
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief          Initialization data for MC_RGM hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_MC_RGM_ConfigType, MCU_CONST) MC_RGM_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
#if (MCU_PERFORM_RESET_API == STD_ON)
    /* MC_ResetType: Functional vs Destructive. */
    ([!IF "McuModuleConfiguration/McuResetConfig/McuResetType = 'FunctionalReset'"!]MCU_FUNC_RESET[!ELSE!]MCU_DEST_RESET[!ENDIF!]),
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */
    /* destructive reset config */
    /* MCRGM_Dest_ResetOpt: RGM_DERD Register Configuration. */
    (uint32)0x00U, /* unused */
    /* MCRGM_Dest_SafeIsrOpt: RGM_DEAR Register Configuration. */
    (uint32)0x00U, /* unused */
    /* MCRGM_Dest_ExtPinReset: RGM_DBRE Register Configuration. */
    MC_RGM_DBRE_U32( (uint32)0x00U ),
    
    /* functional reset config */
    /* Func_ResetOpt: FERD Register Configuration. */
    MC_RGM_FERD_U32
    (
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_LVD_LV_PD2_COLD_ResetSource/McuDisableReset='false'"!]MC_RGM_LVD_LV_PD2_COLD_EVENT_RESET_U32[!ELSE!]MC_RGM_LVD_LV_PD2_COLD_EVENT_SAFE_INT_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_HVD_LV_COLD_ResetSource/McuDisableReset='false'"!]MC_RGM_HVD_LV_COLD_EVENT_RESET_U32[!ELSE!]MC_RGM_HVD_LV_COLD_EVENT_SAFE_INT_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_LVD_IO_A_HI_ResetSource/McuDisableReset='false'"!]MC_RGM_LVD_IO_A_HI_EVENT_RESET_U32[!ELSE!]MC_RGM_LVD_IO_A_HI_EVENT_SAFE_INT_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_Z2_DBG_ResetSource/McuDisableReset='false'"!]MC_RGM_Z2_DBG_EVENT_RESET_U32[!ELSE!]MC_RGM_Z2_DBG_EVENT_SAFE_INT_U32[!ENDIF!]) |
        [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3)"!]([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_Z4B_DBG_ResetSource/McuDisableReset='false'"!]MC_RGM_Z4B_DBG_EVENT_RESET_U32[!ELSE!]MC_RGM_Z4B_DBG_EVENT_SAFE_INT_U32[!ENDIF!]) |[!ENDIF!]
        ([!IF "McuModuleConfiguration.McuResetConfig/Mcu_D_Z4A_DBG_ResetSource/McuDisableReset='false'"!]MC_RGM_Z4A_DBG_EVENT_RESET_U32[!ELSE!]MC_RGM_Z4A_DBG_EVENT_SAFE_INT_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration.McuResetConfig/Mcu_D_CMU_OLR_ResetSource/McuDisableReset='false'"!]MC_RGM_CMU_OLR_EVENT_RESET_U32[!ELSE!]MC_RGM_CMU_OLR_EVENT_SAFE_INT_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration.McuResetConfig/Mcu_D_JTAG_FUNC_ResetSource/McuDisableReset='false'"!]MC_RGM_JTAG_FUNC_EVENT_RESET_U32[!ELSE!]MC_RGM_JTAG_FUNC_EVENT_SAFE_INT_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration.McuResetConfig/Mcu_D_NMI_WKPU_ResetSource/McuDisableReset='false'"!]MC_RGM_NMI_WKPU_EVENT_RESET_U32[!ELSE!]MC_RGM_NMI_WKPU_EVENT_SAFE_INT_U32[!ENDIF!])
        
    ),
    /* MCRGM_Func_SafeIsrOpt: RGM_FEAR Register Configuration. */
    MC_RGM_FEAR_U32
    (
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_LVD_LV_PD2_COLD_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_LVW_PD2_COLD_EVENT_SAFE_U32[!ELSE!]MC_RGM_LVW_PD2_COLD_EVENT_ISR_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_HVD_LV_COLD_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_HVD_LV_COLD_EVENT_SAFE_U32[!ELSE!]MC_RGM_HVD_LV_COLD_EVENT_ISR_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_LVD_IO_A_HI_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_LVD_IO_A_HI_EVENT_SAFE_U32[!ELSE!]MC_RGM_LVD_IO_A_HI_EVENT_ISR_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_Z2_DBG_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_Z2_DBG_EVENT_SAFE_U32[!ELSE!]MC_RGM_Z2_DBG_EVENT_ISR_U32[!ENDIF!]) |
        [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3)"!]([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_Z4B_DBG_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_Z4B_DBG_EVENT_SAFE_U32[!ELSE!]MC_RGM_Z4B_DBG_EVENT_ISR_U32[!ENDIF!]) |[!ENDIF!]
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_Z4A_DBG_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_Z4A_DBG_EVENT_SAFE_U32[!ELSE!]MC_RGM_Z4A_DBG_EVENT_ISR_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_CMU_OLR_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_CMU_OLR_EVENT_SAFE_U32[!ELSE!]MC_RGM_CMU_OLR_EVENT_ISR_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_JTAG_FUNC_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_JTAG_FUNC_EVENT_SAFE_U32[!ELSE!]MC_RGM_JTAG_FUNC_EVENT_ISR_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_NMI_WKPU_ResetSource/McuEnableInterruptSafe='false'"!]MC_RGM_NMI_WKPU_EVENT_SAFE_U32[!ELSE!]MC_RGM_NMI_WKPU_EVENT_ISR_U32[!ENDIF!])
    ),
    /* MCRGM_Func_ExtPinReset: RGM_FBRE Register Configuration. */
    MC_RGM_FBRE_U32( 
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_LVD_LV_PD2_COLD_ResetSource/McuResetPin='false'"!]MC_RGM_LVD_LV_PD2_COLD_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_LVD_LV_PD2_COLD_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_BE_Z2_DBG_ResetSource/McuResetPin='false'"!]MC_RGM_Z2_DBG_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_Z2_DBG_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3)"!]([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_BE_Z4B_DBG_ResetSource/McuResetPin='false'"!]MC_RGM_Z4B_DBG_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_Z4B_DBG_ASSERT_ESR0_EN_U32[!ENDIF!]) |[!ENDIF!]
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_BE_Z4A_DBG_ResetSource/McuResetPin='false'"!]MC_RGM_Z4A_DBG_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_Z4A_DBG_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_BE_FCCU_SHORT_ResetSource/McuResetPin='false'"!]MC_RGM_FCCU_SHORT_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_FCCU_SHORT_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_BE_FCCU_LONG_ResetSource/McuResetPin='false'"!]MC_RGM_FCCU_LONG_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_FCCU_LONG_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_CMU_OLR_ResetSource/McuResetPin='false'"!]MC_RGM_CMU_OLR_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_CMU_OLR_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_JTAG_FUNC_ResetSource/McuResetPin='false'"!]MC_RGM_JTAG_FUNC_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_JTAG_FUNC_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_NMI_WKPU_ResetSource/McuResetPin='false'"!]MC_RGM_NMI_WKPU_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_NMI_WKPU_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_SS_SOFT_FUNC_ResetSource/McuResetPin='false'"!]MC_RGM_SOFT_FUNC_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_SOFT_FUNC_ASSERT_ESR0_EN_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_BE_HSM_FUNC_ResetSource/McuResetPin='false'"!]MC_RGM_HSM_FUNC_ASSERT_ESR0_DIS_U32[!ELSE!]MC_RGM_HSM_FUNC_ASSERT_ESR0_EN_U32[!ENDIF!])
    ),
    /* MCRGM_Func_Phase1or3Opt: RGM_FESS Register Configuration. */
    MC_RGM_FESS_U32
    (
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_LVD_LV_PD2_COLD_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_LVD_LV_PD2_COLD_PHASE1_U32[!ELSE!]MC_RGM_LVD_LV_PD2_COLD_PHASE3_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_HVD_LV_COLD_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_HVD_LV_COLD_PHASE1_U32[!ELSE!]MC_RGM_HVD_LV_COLD_PHASE3_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_LVD_IO_A_HI_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_LVD_IO_A_HI_PHASE1_U32[!ELSE!]MC_RGM_LVD_IO_A_HI_PHASE3_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_BE_Z2_DBG_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_Z2_DBG_PHASE1_U32[!ELSE!]MC_RGM_Z2_DBG_PHASE3_U32[!ENDIF!]) |
        [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3)"!]([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_BE_Z4B_DBG_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_Z4B_DBG_PHASE1_U32[!ELSE!]MC_RGM_Z4B_DBG_PHASE3_U32[!ENDIF!]) |[!ENDIF!]
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_BE_Z4A_DBG_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_Z4A_DBG_PHASE1_U32[!ELSE!]MC_RGM_Z4A_DBG_PHASE3_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_CMU_OLR_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_CMU_OLR_PHASE1_U32[!ELSE!]MC_RGM_CMU_OLR_PHASE3_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_JTAG_FUNC_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_JTAG_FUNC_RESET_PHASE1_U32[!ELSE!]MC_RGM_JTAG_FUNC_RESET_PHASE3_U32[!ENDIF!]) |
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_D_NMI_WKPU_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_NMI_WKPU_PHASE1_U32[!ELSE!]MC_RGM_NMI_WKPU_PHASE3_U32[!ENDIF!]) | 
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_SS_SOFT_FUNC_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_SOFT_FUNC_RESET_PHASE1_U32[!ELSE!]MC_RGM_SOFT_FUNC_RESET_PHASE3_U32[!ENDIF!]) |      
        ([!IF "McuModuleConfiguration/McuResetConfig/Mcu_SS_EXR_ResetSource/McuResetPhase='PHASE_1'"!]MC_RGM_EXR_RESET_PHASE1_U32[!ELSE!]MC_RGM_EXR_RESET_PHASE3_U32[!ENDIF!])
               
    ),

    /* MCRGM_Threshold_Reset: RGM_FRET Register Configuration. */
    MC_RGM_FRET_U8((uint8)[!"num:i(McuModuleConfiguration/McuResetConfig/McuFunctResetEscThreshold)"!]U),
    
    /* Destructive Reset Escalation Threshold Register */
    MC_RGM_DRET_U8((uint8)[!"num:i(McuModuleConfiguration/McuResetConfig/McuDestResetEscThreshold)"!]U)
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!// 



[!MACRO "MC_ME_Config", "Type"!][!//
[!NOCODE!]
    [!VAR "totalNumberOfRegs" = "count(McuModuleConfiguration/McuPeripheral/*)"!]
        [!VAR "ConfigIndex" = "0"!]
    [!SELECT "McuModuleConfiguration"!][!//
[!CODE!]
static CONST( Mcu_MC_ME_CoreAddressConfigType, MCU_CONST) MC_ME_aCaddrConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_MC_ME_NUMBER_OF_CORES] = 
{
    /* Core Control Register (ME_CADDR1) */
    {
        MC_ME_CADDR1_ADDR32,
        [!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuUseDefaultBootAddrEnable = 'false'"!][!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuUseDefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_MASK32 | [!ENDIF!][!ENDIF!]MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
             [!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuUseDefaultBootAddrEnable = 'false'"!][!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuUseDefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_U32([!"num:inttohex(McuCoreConfiguration/McuCoreZ4AConfiguration/McuBootAddress,8)"!]U) |[!ENDIF!][!ENDIF!]
            [!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE_U32[!ELSE!]MC_ME_CADDR_RESET_DISABLE_U32[!ENDIF!]
        )
    },
    [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3)"!]
    /* Core Control Register (ME_CADDR2) */
    {
        MC_ME_CADDR2_ADDR32,
         [!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuUseDefaultBootAddrEnable = 'false'"!][!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuUseDefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_MASK32 | [!ENDIF!][!ENDIF!]MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
            [!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuUseDefaultBootAddrEnable = 'false'"!][!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuUseDefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_U32([!"num:inttohex(McuCoreConfiguration/McuCoreZ4BConfiguration/McuBootAddress,8)"!]U) |[!ENDIF!][!ENDIF!]
            [!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE_U32[!ELSE!]MC_ME_CADDR_RESET_DISABLE_U32[!ENDIF!]
        )
    },
    [!ENDIF!]
    /* Core Control Register (ME_CADDR3) */
    {
        MC_ME_CADDR3_ADDR32,
        [!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuUseDefaultBootAddrEnable = 'false'"!][!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuUseDefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_MASK32 | [!ENDIF!][!ENDIF!]MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
            [!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuUseDefaultBootAddrEnable = 'false'"!][!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuUseDefaultBootAddrEnable = 'false'"!]MC_ME_CADDR_ADDR_U32([!"num:inttohex(McuCoreConfiguration/McuCoreZ2Configuration/McuBootAddress,8)"!]U) |[!ENDIF!][!ENDIF!]
            [!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuCoreReset='true'"!]MC_ME_CADDR_RESET_ENABLE_U32[!ELSE!]MC_ME_CADDR_RESET_DISABLE_U32[!ENDIF!]
        )
    }
};
[!ENDCODE!]

[!CODE!]
static CONST( Mcu_MC_ME_CoreConfigType, MCU_CONST) MC_ME_aCctlConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_MC_ME_NUMBER_OF_CORES] = 
{
    /* Core Control Register (ME_CCTL1) */
    {
        MC_ME_CCTL1_ADDR32,
        MC_ME_CCTL_ENABLE_U16
        ( 
            ([!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuCCTL1Run3='true'"!]MC_ME_CCTL_RUN3_ON_U16[!ELSE!]MC_ME_CCTL_RUN3_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuCCTL1Run2='true'"!]MC_ME_CCTL_RUN2_ON_U16[!ELSE!]MC_ME_CCTL_RUN2_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuCCTL1Run1='true'"!]MC_ME_CCTL_RUN1_ON_U16[!ELSE!]MC_ME_CCTL_RUN1_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuCCTL1Run0='true'"!]MC_ME_CCTL_RUN0_ON_U16[!ELSE!]MC_ME_CCTL_RUN0_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuCCTL1Drun='true'"!]MC_ME_CCTL_DRUN_ON_U16[!ELSE!]MC_ME_CCTL_DRUN_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4AConfiguration/McuCCTL1Safe='true'"!]MC_ME_CCTL_SAFE_ON_U16[!ELSE!]MC_ME_CCTL_SAFE_OFF_U16[!ENDIF!])
        )
    },
    [!IF "(num:i(ecu:get('MCU.CORE.COUNT')) = 3)"!]
    /* Core Control Register (ME_CCTL2) */
    {
        MC_ME_CCTL2_ADDR32,
        MC_ME_CCTL_ENABLE_U16
        ( 
            ([!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuCCTL2Run3='true'"!]MC_ME_CCTL_RUN3_ON_U16[!ELSE!]MC_ME_CCTL_RUN3_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuCCTL2Run2='true'"!]MC_ME_CCTL_RUN2_ON_U16[!ELSE!]MC_ME_CCTL_RUN2_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuCCTL2Run1='true'"!]MC_ME_CCTL_RUN1_ON_U16[!ELSE!]MC_ME_CCTL_RUN1_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuCCTL2Run0='true'"!]MC_ME_CCTL_RUN0_ON_U16[!ELSE!]MC_ME_CCTL_RUN0_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuCCTL2Drun='true'"!]MC_ME_CCTL_DRUN_ON_U16[!ELSE!]MC_ME_CCTL_DRUN_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ4BConfiguration/McuCCTL2Safe='true'"!]MC_ME_CCTL_SAFE_ON_U16[!ELSE!]MC_ME_CCTL_SAFE_OFF_U16[!ENDIF!])
        )
    },
    [!ENDIF!]
    /* Core Control Register (ME_CCTL3) */
    {
        MC_ME_CCTL3_ADDR32,
        MC_ME_CCTL_ENABLE_U16
        ( 
            ([!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuCCTL3Run3='true'"!]MC_ME_CCTL_RUN3_ON_U16[!ELSE!]MC_ME_CCTL_RUN3_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuCCTL3Run2='true'"!]MC_ME_CCTL_RUN2_ON_U16[!ELSE!]MC_ME_CCTL_RUN2_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuCCTL3Run1='true'"!]MC_ME_CCTL_RUN1_ON_U16[!ELSE!]MC_ME_CCTL_RUN1_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuCCTL3Run0='true'"!]MC_ME_CCTL_RUN0_ON_U16[!ELSE!]MC_ME_CCTL_RUN0_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuCCTL3Drun='true'"!]MC_ME_CCTL_DRUN_ON_U16[!ELSE!]MC_ME_CCTL_DRUN_OFF_U16[!ENDIF!]) |
            ([!IF "McuCoreConfiguration/McuCoreZ2Configuration/McuCCTL3Safe='true'"!]MC_ME_CCTL_SAFE_ON_U16[!ELSE!]MC_ME_CCTL_SAFE_OFF_U16[!ENDIF!])
        )
    }
};
[!ENDCODE!]
    [!ENDSELECT!][!//
[!CODE!]
static CONST( Mcu_MC_ME_RegisterConfigType, MCU_CONST) MC_ME_aPCTLConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][MCU_MC_ME_NUMBER_OF_PCTL_REGS] = 
{
[!ENDCODE!]
        [!VAR "actualNumberOfRegs" = "0"!]
        [!LOOP "McuModuleConfiguration/McuPeripheral/*"!][!//
            [!VAR "n" = "0"!]
            [!VAR "m" = "0"!]
            [!VAR "PerName"="./McuPerName"!]
            [!VAR "TempMcuPerRunConfig1" = "McuPerRunConfig"!][!//
            [!LOOP "../../McuRunConfig/*"!][!//
                [!VAR "TempMcuPerRunConfig"="@name"!][!//
                [!IF "contains($TempMcuPerRunConfig1,$TempMcuPerRunConfig)"!][!//
                   [!VAR "n" = "@index"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//McuRunConfig/*
            [!VAR "TempMcuPerLowPwrConfig1" = "McuPerLowPwrConfig"!][!//
            [!LOOP "../../McuLowPowerConfig/*"!][!//
                [!VAR "TempMcuPerLowPwrConfig"="@name"!][!//
                [!IF "contains($TempMcuPerLowPwrConfig1,$TempMcuPerLowPwrConfig)"!][!//
                    [!VAR "m" = "@index"!][!//
                [!ENDIF!][!//
            [!ENDLOOP!][!//McuLowPowerConfig/*
[!CODE!]
    /* [!"$PerName"!] */
    {
        [!"concat('MC_ME_', substring-before($PerName,'_'),'_ADDR32')"!],
        MC_ME_PCTLn_U8([!IF "McuPerDBGConfig"!]MC_ME_PCTL_DBG_FRZ_EN_U8, [!ELSE!]MC_ME_PCTL_DBG_FRZ_DIS_U8, [!ENDIF!][!"concat('MC_ME_CFG_RUN_PC',num:i($n),'_U8')"!], [!"concat('MC_ME_CFG_LP_PC',num:i($m),'_U8')"!])
    }[!IF "num:i($actualNumberOfRegs)<num:i($totalNumberOfRegs - 1)"!],[!ENDIF!][!VAR "actualNumberOfRegs" = "$actualNumberOfRegs + 1"!]
[!ENDCODE!]
        [!ENDLOOP!]
[!CODE!]
};
/**
* @brief            Configuration of MC_ME hw IP.
* @details          This data configuration is set at module initialization phase.
*
*/
static CONST( Mcu_MC_ME_ConfigType, MCU_CONST) MC_ME_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    [!ENDCODE!]
    [!LOOP "McuModuleConfiguration/McuRunConfig/*"!]
        [!VAR "PCindex" = "@index"!]
        [!VAR "PCname"  = "@name"!]
        [!CODE!]
    /* ME_RUN_PC[!"$PCindex"!]: Run Config Mode[!"$PCindex"!] : [!"$PCname"!]. */
    (
        ([!IF "McuModeRun3='true'"!]MC_ME_RUN3_CLK_ACTIVE_U32[!ELSE!]MC_ME_RUN3_CLK_GATED_U32[!ENDIF!]) |
        ([!IF "McuModeRun2='true'"!]MC_ME_RUN2_CLK_ACTIVE_U32[!ELSE!]MC_ME_RUN2_CLK_GATED_U32[!ENDIF!]) |
        ([!IF "McuModeRun1='true'"!]MC_ME_RUN1_CLK_ACTIVE_U32[!ELSE!]MC_ME_RUN1_CLK_GATED_U32[!ENDIF!]) |
        ([!IF "McuModeRun0='true'"!]MC_ME_RUN0_CLK_ACTIVE_U32[!ELSE!]MC_ME_RUN0_CLK_GATED_U32[!ENDIF!]) |
        ([!IF "McuModeDRun='true'"!]MC_ME_DRUN_CLK_ACTIVE_U32[!ELSE!]MC_ME_DRUN_CLK_GATED_U32[!ENDIF!]) |
        ([!IF "McuModeSafe='true'"!]MC_ME_SAFE_CLK_ACTIVE_U32[!ELSE!]MC_ME_SAFE_CLK_GATED_U32[!ENDIF!]) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        [!ENDCODE!] 
    [!ENDLOOP!][!//McuRunConfig/*

    [!LOOP "McuModuleConfiguration/McuLowPowerConfig/*"!]
        [!VAR "PCindex" = "@index"!]
        [!CODE!]
    /* ME_LP_PC[!"$PCindex"!]: Low Power Mode [!"$PCindex"!]. */
    (
        ([!IF "McuStop0='true'"!]MC_ME_STOP0_CLK_ACTIVE_U32[!ELSE!]MC_ME_STOP0_CLK_GATED_U32[!ENDIF!]) |
        ([!IF "McuStandby0='true'"!]MC_ME_STBY0_CLK_ACTIVE_U32[!ELSE!]MC_ME_STBY0_CLK_GATED_U32[!ENDIF!])
    ),
[!ENDCODE!]
    [!ENDLOOP!][!//McuLowPowerConfig/*
[!CODE!]
    MCU_MC_ME_NUMBER_OF_PCTL_REGS,
    &MC_ME_aPCTLConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
[!ENDCODE!]
[!CODE!]
    /* Modes Enabled according to ME_ME details. RUN0/DRUN/SAFE/RESET/RESET_DEST are always ON. Configuration of ME_ME register. */
    MC_ME_ME_ENABLE
    (
        [!IF "McuModuleConfiguration/McuEnableMode/McuModeStop0"!]MC_ME_STOP0_MODE_EN_U32[!ELSE!]MC_ME_STOP0_MODE_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuEnableMode/McuModeStandBy0"!]MC_ME_STBY0_MODE_EN_U32[!ELSE!]MC_ME_STBY0_MODE_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuEnableMode/McuModeRun3"!]MC_ME_RUN3_MODE_EN_U32[!ELSE!]MC_ME_RUN3_MODE_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuEnableMode/McuModeRun2"!]MC_ME_RUN2_MODE_EN_U32[!ELSE!]MC_ME_RUN2_MODE_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuEnableMode/McuModeRun1"!]MC_ME_RUN1_MODE_EN_U32[!ELSE!]MC_ME_RUN1_MODE_DIS_U32[!ENDIF!] |
        MC_ME_TEST_MODE_DIS_U32
    ),

    /* Enable Mode Transition Interrupts: Configure the ME_IM Register. */
    MC_ME_INT_ENABLE
    (
        [!IF "McuModuleConfiguration/McuInterruptTransition/McuTransitionComplete='true'"!]MC_ME_TRANSITION_MODE_INT_EN_U32[!ELSE!]MC_ME_TRANSITION_MODE_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuInterruptTransition/McuSafeMode='true'"!]MC_ME_SAFE_MODE_INT_EN_U32[!ELSE!]MC_ME_SAFE_MODE_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuInterruptTransition/McuInvalidMode='true'"!]MC_ME_INVALID_MODE_INT_EN_U32[!ELSE!]MC_ME_INVALID_MODE_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuInterruptTransition/McuInvalidConfiguration='true'"!]MC_ME_INVALID_MODE_CFG_INT_EN_U32[!ELSE!]MC_ME_INVALID_MODE_CFG_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuInterruptTransition/McuInvalidClockConfiguration='true'"!]MC_ME_INVALID_MODE_CLK_INT_EN_U32[!ELSE!]MC_ME_INVALID_MODE_CLK_INT_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuInterruptTransition/McuInvalidCoreConfiguration='true'"!]MC_ME_INVALID_MODE_CPU_INT_EN_U32[!ELSE!]MC_ME_INVALID_MODE_CPU_INT_DIS_U32[!ENDIF!]
    ),
[!ENDCODE!]

[!CODE!]
    /* configuration of CADDRs */
    MCU_MC_ME_NUMBER_OF_CORES,
    &MC_ME_aCaddrConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    
    /* configuration of CCTLs */
    MCU_MC_ME_NUMBER_OF_CORES,
    &MC_ME_aCctlConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "FLASH_Config", "Type"!][!//
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief            Platform FLASH hw IP configuration.
* @details          Configure prefetch mechanism, buffers, access protection.
*                   Configuration set by calling Mcu_Init API.
*/
static CONST( Mcu_FLASH_ConfigType, MCU_CONST) FLASH_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Platform Flash Configuration Register 1 (PFCR1). */
    MCU_FLASH_PFCR1_U32
    (
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master15Prefetch='true'"!]MCU_FLASH_P0_MASTER15_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER15_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master14Prefetch='true'"!]MCU_FLASH_P0_MASTER14_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER14_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master13Prefetch='true'"!]MCU_FLASH_P0_MASTER13_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER13_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master12Prefetch='true'"!]MCU_FLASH_P0_MASTER12_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER12_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master11Prefetch='true'"!]MCU_FLASH_P0_MASTER11_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER11_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master10Prefetch='true'"!]MCU_FLASH_P0_MASTER10_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER10_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master9Prefetch='true'"!]MCU_FLASH_P0_MASTER9_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER9_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master8Prefetch='true'"!]MCU_FLASH_P0_MASTER8_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER8_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master7Prefetch='true'"!]MCU_FLASH_P0_MASTER7_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER7_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master6Prefetch='true'"!]MCU_FLASH_P0_MASTER6_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER6_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master5Prefetch='true'"!]MCU_FLASH_P0_MASTER5_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER5_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master4Prefetch='true'"!]MCU_FLASH_P0_MASTER4_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER4_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master3Prefetch='true'"!]MCU_FLASH_P0_MASTER3_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER3_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master2Prefetch='true'"!]MCU_FLASH_P0_MASTER2_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER2_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master1Prefetch='true'"!]MCU_FLASH_P0_MASTER1_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER1_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0Master0Prefetch='true'"!]MCU_FLASH_P0_MASTER0_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_MASTER0_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0DataPrefetch='true'"!]MCU_FLASH_P0_DATA_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_DATA_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0InstructionPrefetch='true'"!]MCU_FLASH_P0_INSTR_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P0_INSTR_PREFETCH_DIS_U32[!ENDIF!] |
        MCU_FLASH_P0_PFLIM_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuPort0PrefetchLimit)"!]U ) |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort0ReadBufferEnable='true'"!]MCU_FLASH_P0_BUFFER_EN_U32[!ELSE!]MCU_FLASH_P0_BUFFER_DIS_U32[!ENDIF!]
    ),
    
    /* Platform Flash Configuration Register 2 (PFCR2). */
    MCU_FLASH_PFCR2_U32
    (
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master15Prefetch='true'"!]MCU_FLASH_P1_MASTER15_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER15_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master14Prefetch='true'"!]MCU_FLASH_P1_MASTER14_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER14_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master13Prefetch='true'"!]MCU_FLASH_P1_MASTER13_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER13_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master12Prefetch='true'"!]MCU_FLASH_P1_MASTER12_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER12_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master11Prefetch='true'"!]MCU_FLASH_P1_MASTER11_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER11_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master10Prefetch='true'"!]MCU_FLASH_P1_MASTER10_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER10_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master9Prefetch='true'"!]MCU_FLASH_P1_MASTER9_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER9_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master8Prefetch='true'"!]MCU_FLASH_P1_MASTER8_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER8_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master7Prefetch='true'"!]MCU_FLASH_P1_MASTER7_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER7_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master6Prefetch='true'"!]MCU_FLASH_P1_MASTER6_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER6_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master5Prefetch='true'"!]MCU_FLASH_P1_MASTER5_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER5_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master4Prefetch='true'"!]MCU_FLASH_P1_MASTER4_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER4_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master3Prefetch='true'"!]MCU_FLASH_P1_MASTER3_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER3_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master2Prefetch='true'"!]MCU_FLASH_P1_MASTER2_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER2_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master1Prefetch='true'"!]MCU_FLASH_P1_MASTER1_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER1_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1Master0Prefetch='true'"!]MCU_FLASH_P1_MASTER0_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_MASTER0_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1DataPrefetch='true'"!]MCU_FLASH_P1_DATA_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_DATA_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1InstructionPrefetch='true'"!]MCU_FLASH_P1_INSTR_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P1_INSTR_PREFETCH_DIS_U32[!ENDIF!] |
        MCU_FLASH_P1_PFLIM_U32((uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuPort1PrefetchLimit)"!]U) |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1ReadBufferEnable='true'"!]MCU_FLASH_P1_BUFFER_EN_U32[!ELSE!]MCU_FLASH_P1_BUFFER_DIS_U32[!ENDIF!]
    ),
    
    /* Platform Flash Configuration Register 3 (PFCR3). */
    MCU_FLASH_PFCR3_U32(
        MCU_FLASH_P0_WCFG_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuPort0PageBufferConfiguration)"!]U ) |
        MCU_FLASH_P1_WCFG_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuPort1PageBufferConfiguration)"!]U ) |
        MCU_FLASH_P2_WCFG_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuPort2PageBufferConfiguration)"!]U ) |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuBAFDisable='true'"!]MCU_FLASH_BAF_DIS_U32[!ELSE!]MCU_FLASH_BAF_EN_U32[!ENDIF!] |
        MCU_FLASH_ARBM_WCFG_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuFlashArbitrationMode)"!]U )
    ),
    /* Platform Flash Configuration Register 3 (PFCR3). */
    MCU_FLASH_PFCR4_U32(
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master15Prefetch='true'"!]MCU_FLASH_P2_MASTER15_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER15_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master14Prefetch='true'"!]MCU_FLASH_P2_MASTER14_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER14_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master13Prefetch='true'"!]MCU_FLASH_P2_MASTER13_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER13_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master12Prefetch='true'"!]MCU_FLASH_P2_MASTER12_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER12_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master11Prefetch='true'"!]MCU_FLASH_P2_MASTER11_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER11_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master10Prefetch='true'"!]MCU_FLASH_P2_MASTER10_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER10_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master9Prefetch='true'"!]MCU_FLASH_P2_MASTER9_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER9_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master8Prefetch='true'"!]MCU_FLASH_P2_MASTER8_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER8_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master7Prefetch='true'"!]MCU_FLASH_P2_MASTER7_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER7_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master6Prefetch='true'"!]MCU_FLASH_P2_MASTER6_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER6_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master5Prefetch='true'"!]MCU_FLASH_P2_MASTER5_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER5_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master4Prefetch='true'"!]MCU_FLASH_P2_MASTER4_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER4_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master3Prefetch='true'"!]MCU_FLASH_P2_MASTER3_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER3_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master2Prefetch='true'"!]MCU_FLASH_P2_MASTER2_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER2_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master1Prefetch='true'"!]MCU_FLASH_P2_MASTER1_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER1_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2Master0Prefetch='true'"!]MCU_FLASH_P2_MASTER0_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_MASTER0_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1DataPrefetch='true'"!]MCU_FLASH_P2_DATA_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_DATA_PREFETCH_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort1InstructionPrefetch='true'"!]MCU_FLASH_P2_INSTR_PREFETCH_EN_U32[!ELSE!]MCU_FLASH_P2_INSTR_PREFETCH_DIS_U32[!ENDIF!] |
        MCU_FLASH_P2_PFLIM_U32((uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuPort2PrefetchLimit)"!]U) |
        [!IF "McuModuleConfiguration/McuPlatformFlashConfig/McuPort2ReadBufferEnable='true'"!]MCU_FLASH_P2_BUFFER_EN_U32[!ELSE!]MCU_FLASH_P2_BUFFER_DIS_U32[!ENDIF!]
    ),
    
    /* Platform Flash Access Protection Register (PFAPR). */
    MCU_FLASH_PFAPR_U32
    (
        MCU_FLASH_M0AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster0AccessProt)"!]U ) |
        MCU_FLASH_M1AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster1AccessProt)"!]U ) |
        MCU_FLASH_M2AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster2AccessProt)"!]U ) |
        MCU_FLASH_M3AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster3AccessProt)"!]U ) |
        MCU_FLASH_M4AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster4AccessProt)"!]U ) |
        MCU_FLASH_M5AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster5AccessProt)"!]U ) |
        MCU_FLASH_M6AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster6AccessProt)"!]U ) |
        MCU_FLASH_M7AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster7AccessProt)"!]U ) |
        MCU_FLASH_M8AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster8AccessProt)"!]U ) |
        MCU_FLASH_M9AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster9AccessProt)"!]U ) |
        MCU_FLASH_M10AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster10AccessProt)"!]U ) |
        MCU_FLASH_M11AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster11AccessProt)"!]U ) |
        MCU_FLASH_M12AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster12AccessProt)"!]U ) |
        MCU_FLASH_M13AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster13AccessProt)"!]U ) |
        MCU_FLASH_M14AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster14AccessProt)"!]U ) |
        MCU_FLASH_M15AP_U32( (uint32)[!"num:i(McuModuleConfiguration/McuPlatformFlashConfig/McuMaster15AccessProt)"!]U )
    )
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "PMCDIG_Config", "Type"!][!//
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief          Initialization data for PMCDIG hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_PMCDIG_ConfigType, MCU_CONST) PMCDIG_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* RAM Domain Configuration Register */
    PMCDIG_RDCR_VALUE_U32(
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcRamDomain_Config/McuPmcRdCr_MemSleep='true'"!]PMCDIG_RDCR_MEM_SLEEP_ENABLE_U32[!ELSE!]PMCDIG_RDCR_MEM_SLEEP_DISABLE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcRamDomain_Config/McuPmcRdCr_PadKeep='true'"!]PMCDIG_RDCR_PAD_KEEP_ENABLE_U32[!ELSE!]PMCDIG_RDCR_PAD_KEEP_DISABLE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcRamDomain_Config/McuPmcRdCr_Rd64Ret='true'"!]PMCDIG_RDCR_RD64_RET_ENABLE_U32[!ELSE!]PMCDIG_RDCR_RD64_RET_DISABLE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcRamDomain_Config/McuPmcRdCr_Rd128Ret='true'"!]PMCDIG_RDCR_RD128_RET_ENABLE_U32[!ELSE!]PMCDIG_RDCR_RD128_RET_DISABLE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcRamDomain_Config/McuPmcRdCr_Rd256Ret='true'"!]PMCDIG_RDCR_RD256_RET_ENABLE_U32[!ELSE!]PMCDIG_RDCR_RD256_RET_DISABLE_U32[!ENDIF!]
    ),
    /* MISC Control Register */
    PMCDIG_MCR_VALUE_U32(
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcMisc_Config/McuPmcMcr_FlashLpFastExistDis='true'"!]PMCDIG_MCR_FLASH_LP_FAST_EXIT_DIS_U32[!ELSE!]PMCDIG_MCR_FLASH_LP_FAST_EXIT_ENA_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcMisc_Config/McuPmcMcr_LvdPd2ColdRee='true'"!]PMCDIG_MCR_LVD_PD2_COLD_REE_ENA_U32[!ELSE!]PMCDIG_MCR_LVD_PD2_COLD_REE_DIS_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcMisc_Config/McuPmcMcr_HvdRee='true'"!]PMCDIG_MCR_HVD_REE_ENABLE_U32[!ELSE!]PMCDIG_RDCR_MEM_SLEEP_DISABLE_U32[!ENDIF!] |
        [!IF "McuModuleConfiguration/McuPowerControl/McuPmcMisc_Config/McuPmcMcr_LvdIoHiRee='true'"!]PMCDIG_MCR_LVD_IO_HI_REE_ENABLE_U32[!ELSE!]PMCDIG_MCR_LVD_IO_HI_REE_DISABLE_U32[!ENDIF!]
    )
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "Mcu_HwIPs_Config", "Type"!][!//
[!NOCODE!]
    [!VAR "ConfigIndex" = "0"!]
[!CODE!]
/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_HwIPsConfigType, MCU_CONST) Mcu_HwIPsConfig[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
{
    /* Configuration for MC_ME (Mode Entry Module) hardware IP. */
    &MC_ME_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for MC_RGM (Reset Generation Module) hardware IP. */
    &MC_RGM_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],

    /* Configuration for FLASH (Flash Memory) hardware IP. */
    &FLASH_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    
    /* Configuration for PMCDIG (Power Management Controller) hardware IP. */
    &PMCDIG_Config[!"$Type"!][!"num:i($ConfigIndex)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!// 


[!MACRO "Mcu_Config", "Type"!][!//
[!NOCODE!]
[!CODE!]
/**
* @brief          Initialization data for the MCU driver.
* @details        A pointer to such a structure is provided to the MCU initialization routines for configuration.
*
*/
/** @violates @ref Mcu_[!IF "$Type = 'PC'"!]Cfg[!ELSE!]PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!]_c_REF_7 MISRA 2004 Required Rule 8.10, external linkage ... */
CONST(Mcu_ConfigType, MCU_CONST) [!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile') and (variant:size() <= 1)"!]Mcu_PBCfgVariantPredefined[!ELSE!][!"as:name(McuModuleConfiguration)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!] =
{
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to DEM error reporting configurations. */
    &Mcu_Dem_Config,
#endif

    /* Number of RAM Sections configurations. */
    (Mcu_RamSectionType)[!"num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))"!]U,

    /* Number of Power Modes configurations. */
    (Mcu_ModeType)[!"num:i(count(McuModuleConfiguration/McuModeSettingConf/*))"!]U,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Number of Clock Setting configurations. */
    (Mcu_ClockType)[!"num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))"!]U,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
    /* Pointer to RAM Section configurations. */
    [!IF "num:i(count(McuModuleConfiguration/McuRamSectorSettingConf/*))>0"!]&Mcu_aRamConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!](NULL_PTR),[!ENDIF!]
#endif

    /* Pointer to Power Mode configurations. */
    [!IF "num:i(count(McuModuleConfiguration/McuModeSettingConf/*))>0"!]&Mcu_aModeConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!](NULL_PTR),[!ENDIF!]

#if (MCU_LPU_SUPPORT == STD_ON)
    /* Pointer to Low Power Mode configurations. */
    [!IF "count(McuModuleConfiguration/McuModeSettingConf/*/McuPowerMode[. = 'LPU_RUN']) >= 1"!]&Mcu_aLowPowerModeConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!](NULL_PTR),[!ENDIF!]
#endif
    
#if (MCU_INIT_CLOCK == STD_ON)
    /* Pointer to Clock configurations. */
    [!IF "num:i(count(McuModuleConfiguration/McuClockSettingConfig/*))>0"!]&Mcu_aClockConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],[!ELSE!](NULL_PTR),[!ENDIF!]
#endif /* (MCU_INIT_CLOCK == STD_ON) */

    /* Pointer to Low Level Mcu driver configuration. */
    &Mcu_HwIPsConfig[!"$Type"!][!"num:i(@index)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]
};
[!ENDCODE!]
[!ENDNOCODE!]
[!ENDMACRO!][!// 

[!ENDNOCODE!]
