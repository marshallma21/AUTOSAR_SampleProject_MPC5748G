[!NOCODE!][!//
/**   
  @file    Spi_RegOperations.m
  @version 1.0.0

  @brief   AUTOSAR Spi - File used by the C generation templates.
  @details This file contains macros used by the C generation templates.
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : DSPI
*   Dependencies         : 
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
[!//============================FILE VERSION CHECKS=====================================================
[!MACRO "Spi_FileVersionCheck"!]
[!CODE!][!//
/* Check if current file and SPI header file are of the same vendor */
#if (SPI_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID)
    #error "Spi_PBCfg.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_PBCfg.c and Spi.h are different"
#endif

/* Check if current file and Reg_eSys_DSPI.h file are of the same vendor */
#if (SPI_VENDOR_ID_PBCFG_C != SPI_VENDOR_ID_REGFLEX)
    #error "Spi_PBCfg.c and Reg_eSys_DSPI.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_DSPI.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != SPI_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_REVISION_VERSION_PBCFG_C != SPI_AR_RELEASE_REVISION_VERSION_REGFLEX))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Reg_eSys_DSPI.h are different"
#endif
/* Check if current file and Reg_eSys_DSPI.h file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_PBCFG_C != SPI_SW_MAJOR_VERSION_REGFLEX) || \
     (SPI_SW_MINOR_VERSION_PBCFG_C != SPI_SW_MINOR_VERSION_REGFLEX) || \
     (SPI_SW_PATCH_VERSION_PBCFG_C != SPI_SW_PATCH_VERSION_REGFLEX))
    #error "Software Version Numbers of Spi_PBCfg.c and Reg_eSys_DSPI.h are different"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/* Check if current file and Dem.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_PBCFG_C    != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_PBCfg.c and Dem.h are different"
#endif
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
#endif
[!ENDCODE!][!//
[!ENDMACRO!][!//
[!//====================================================================================================
[!//
[!//===================Check Dual Clock Support============================================
[!MACRO "Spi_CheckDualClockSupport"!]
[!VAR "DualClockSupport"= "'false'"!]
[!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!IF "(node:exists(SpiPhyUnitAlternateClockRef))"!][!//
[!VAR "DualClockSupport"= "'true'"!]
[!ENDIF!][!//
[!ENDLOOP!][!//

[!VAR "DualClockEnabled" = "'false'"!][!//
[!ENDMACRO!][!//
[!//======================================================================================
[!//
[!//===================Check configuration of sequences for Slave=========================
[!MACRO "Spi_CheckSequenceConfigForSlave"!]
[!VAR "Spislavesupported" = "0"!][!//
[!VAR "Spislavesupported1" = "0"!][!//
[!LOOP "SpiDriver/SpiSequence/*"!]
    [!LOOP "SpiJobAssignment/*"!]
    [!SELECT "node:ref(node:current())"!] [!//
        [!SELECT "node:ref(SpiDeviceAssignment)"!] [!//
        [!IF "SpiSlaveMode = 'true'"!] [!//
            [!VAR "Spislavesupported" = "1"!][!//
            [!VAR "Spislavesupported1" = "1"!][!//
        [!ENDIF!] [!//
        [!ENDSELECT!] [!//
    [!IF "$Spislavesupported1=1"!] [!//
        [!IF "(count(SpiChannelList/*))!=1"!]
        [!ERROR "Channel error(In slave mode only one channel needs to be configured)"!]
        [!ENDIF!]
    [!ENDIF!]

    [!ENDSELECT!] [!//
    [!ENDLOOP!] [!//

    [!IF "$Spislavesupported1=1"!] [!//
        [!IF "count(SpiJobAssignment/*)!=1"!]
        [!ERROR "Job error(In slave mode only one Job needs to be configured)"!]
        [!ENDIF!]
    [!ENDIF!]
[!VAR "Spislavesupported1" = "0"!][!//
[!ENDLOOP!] [!//
[!ENDMACRO!][!//
[!//======================================================================================= 
[!//
[!//=======================Check configuration of External Devices========================= 
[!MACRO "Spi_CheckExternalDeviceConfig"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!LOOP "SpiDriver/SpiSequence/*"!]
    [!LOOP "SpiJobAssignment/*"!]
    [!SELECT "node:ref(node:current())"!] [!//
        [!SELECT "node:ref(SpiDeviceAssignment)"!] [!//
        [!IF "SpiSlaveMode = 'true'"!] [!//
            [!VAR "varSpiSlaveunit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
            [!IF "node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiSlaveunit,']/SpiPhyUnitMode')) != 'SPI_SLAVE' "!][!//
            [!ERROR!]As the device [!"@name"!] selected to slave mode, hardware unit mapped to this Device has to be in slave mode.[!ENDERROR!][!//
            [!ENDIF!] [!//
        [!ENDIF!] [!//
        [!IF "SpiSlaveMode = 'false'"!] [!//
            [!VAR "varSpiSlaveunit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
            [!IF "node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiSlaveunit,']/SpiPhyUnitMode')) != 'SPI_MASTER' "!][!//
            [!ERROR!]As the device [!"@name"!] is not selected to slave mode, hardware unit mapped to this Device has to be in Master mode.[!ENDERROR!][!//
            [!ENDIF!] [!//
        [!ENDIF!] [!//
        [!ENDSELECT!] [!//
    [!ENDSELECT!] [!//
    [!ENDLOOP!] [!//
[!ENDLOOP!] [!//
[!ENDMACRO!][!//
[!//=======================================================================================
[!//
[!//=======================================================================================
[!MACRO "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalAbsoluteTimeError" = "1000000"!]
  [!VAR "OptimalRelativeTimeError" = "0"!]
  [!VAR "OptimalTime" = "0"!]
  [!VAR "OptimalPrescaler" = "0"!]
  [!VAR "OptimalScaler" = "0"!]
  [!// if $DesiredTime=0, initialized values are OK; no further calculations needed
  [!IF "$DesiredTime > 0.0"!]
    [!FOR "Prescaler_Count" = "0" TO "3"!]
      [!VAR "Prescaler" = "$Prescaler_Count*2 + 1"!]
      [!VAR "Scaler" = "2"!]
      [!FOR "Scaler_Count" = "0" TO "15"!]
      [!IF "(TSBModeEnable = 'true')"!]
      [!VAR "CalculatedTime" = "(((bit:shl($Prescaler,4))|($Scaler))+ 1) div $BusClock"!]
      [!ELSE!]
        [!VAR "CalculatedTime" = "$Prescaler * 1000 * $Scaler div $BusClock"!]
      [!ENDIF!]
        [!VAR "RelativeTimeError" = "($CalculatedTime div $DesiredTime) - 1 "!]
        [!VAR "AbsoluteTimeError" = "$RelativeTimeError"!]
        [!IF "$AbsoluteTimeError < 0"!][!VAR "AbsoluteTimeError" = "$AbsoluteTimeError * (-1)"!][!ENDIF!]
        [!IF "$AbsoluteTimeError < $OptimalAbsoluteTimeError"!]
          [!VAR "OptimalAbsoluteTimeError" = "$AbsoluteTimeError"!]
          [!VAR "OptimalRelativeTimeError" = "$RelativeTimeError"!]
          [!VAR "OptimalTime" = "$CalculatedTime"!]
          [!VAR "OptimalPrescaler" = "$Prescaler"!]
          [!VAR "OptimalScaler" = "$Scaler"!]
        [!ENDIF!]
        [!VAR "Scaler" = "$Scaler*2"!]
      [!ENDFOR!]
    [!ENDFOR!]
  [!ENDIF!][!//"$DesiredTime > 0.0"
[!ENDMACRO!][!//
[!//===================================================================================================
[!//
[!//===================================================================================================
[!MACRO "DetermineOptimalBaudrateSettings"!]
  [!VAR "OptimalAbsoluteBaudrateError" = "1000000"!]
  [!VAR "OptimalRelativeBaudrateError" = "0"!]
  [!VAR "OptimalBaudrate" = "0"!]
  [!VAR "OptimalDouble" = "0"!]
  [!VAR "OptimalPrescaler" = "0"!]
  [!VAR "OptimalScaler" = "0"!]
  [!FOR "Double" = "0" TO "1"!]
    [!FOR "Prescaler_Count" = "0" TO "3"!]
      [!VAR "Prescaler" = "$Prescaler_Count*2 + 1"!]
      [!IF "$Prescaler = 1"!][!VAR "Prescaler" = "2"!][!ENDIF!]
      [!VAR "Scaler" = "2"!]
      [!FOR "Scaler_Count" = "0" TO "15"!]
        [!VAR "CalculatedBaudrate" = "1000000 * $BusClock * (1+ $Double) div ($Prescaler * $Scaler)"!]
        [!// DesiredBaudrate is always positive
        [!VAR "RelativeBaudrateError" = "($CalculatedBaudrate div $DesiredBaudrate) - 1 "!]
        [!VAR "AbsoluteBaudrateError" = "$RelativeBaudrateError"!]
        [!IF "$AbsoluteBaudrateError < 0"!][!VAR "AbsoluteBaudrateError" = "$AbsoluteBaudrateError * (-1)"!][!ENDIF!]
        [!IF "$AbsoluteBaudrateError < $OptimalAbsoluteBaudrateError"!]
          [!VAR "OptimalAbsoluteBaudrateError" = "$AbsoluteBaudrateError"!]
          [!VAR "OptimalRelativeBaudrateError" = "$RelativeBaudrateError"!]
          [!VAR "OptimalBaudrate" = "$CalculatedBaudrate"!]
          [!VAR "OptimalDouble" = "$Double"!]
          [!VAR "OptimalPrescaler" = "$Prescaler"!]
          [!VAR "OptimalScaler" = "$Scaler"!]
        [!ENDIF!]
        [!IF "$Scaler = 4"!]
          [!VAR "Scaler" = "6"!]
        [!ELSEIF "$Scaler = 6"!]
          [!VAR "Scaler" = "8"!]
        [!ELSE!]
          [!VAR "Scaler" = "$Scaler*2"!]
        [!ENDIF!]
      [!ENDFOR!]
    [!ENDFOR!]
  [!ENDFOR!]
[!ENDMACRO!][!//
[!//===================================================================================================
[!//
[!//===================================================================================================
[!MACRO "GenerateExternalDeviceInfo"!]
[!NOCODE!][!//
  [!//
  [!VAR "BusClock" = "$BusClockNormal"!][!//
  [!VAR "DesiredTime" = "num:i(SpiTimeCs2Clk * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPCSCLK" = "$OptimalPrescaler"!]
  [!VAR "OptimalSCSCLK" = "$OptimalScaler"!]
  [!VAR "OptimalTimeCs2Clk" = "$OptimalTime"!]
  [!VAR "OptimalTimeCs2ClkError" = "$OptimalRelativeTimeError"!]
  [!//
  [!VAR "DesiredTime" = "num:i(SpiTimeClk2Cs * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPASC" = "$OptimalPrescaler"!]
  [!VAR "OptimalSASC" = "$OptimalScaler"!]
  [!VAR "OptimalTimeClk2Cs" = "$OptimalTime"!]
  [!VAR "OptimalTimeClk2CsError" = "$OptimalRelativeTimeError"!]
  [!//
  [!VAR "DesiredTime" = "num:i(SpiTimeCs2Cs * 1000000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPDT" = "$OptimalPrescaler"!]
  [!VAR "OptimalSDT" = "$OptimalScaler"!]
  [!VAR "OptimalTimeCs2Cs" = "$OptimalTime"!]
  [!VAR "OptimalTimeCs2CsError" = "$OptimalRelativeTimeError"!]
  [!//
  [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
  [!CALL "DetermineOptimalBaudrateSettings"!]
  [!VAR "OptimalPBR" = "$OptimalPrescaler"!]
  [!VAR "OptimalSBR" = "$OptimalScaler"!]
  [!VAR "OptimalDBR" = "$OptimalDouble"!]
  [!VAR "OptimalBaudrateNormal" = "$OptimalBaudrate"!]
  [!VAR "OptimalRelativeBaudrateErrorNormal" = "$OptimalRelativeBaudrateError"!]
  [!//
  [!IF "$DualClockEnabled = 'true'"!][!//
    [!VAR "BusClock" = "$BusClockAlternate"!][!//
    [!VAR "DesiredTime" = "num:i(SpiTimeCs2Clk * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPCSCLKAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSCSCLKAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeCs2ClkAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeCs2ClkErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
    [!VAR "DesiredTime" = "num:i(SpiTimeClk2Cs * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPASCAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSASCAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeClk2CsAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeClk2CsErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
    [!VAR "DesiredTime" = "num:i(SpiTimeCs2Cs * 1000000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPDTAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSDTAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeCs2CsAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeCs2CsErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
    [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
    [!CALL "DetermineOptimalBaudrateSettings"!]
    [!VAR "OptimalPBRAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSBRAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalDBRAlternate" = "$OptimalDouble"!]
    [!VAR "OptimalBaudrateAlternate" = "$OptimalBaudrate"!]
    [!VAR "OptimalRelativeBaudrateErrorAlternate" = "$OptimalRelativeBaudrateError"!]
  [!ENDIF!][!// "$DualClockEnabled = 'true'"
  [!//  
[!ENDNOCODE!][!//
[!IF "$DualClockSupport = 'true'"!][!//
          {
            /* Normal Mode */
[!ENDIF!][!//
            (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
                [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    DSPI_CTAR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    DSPI_CTAR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */
            DSPI_CTAR_PCSCLK_[!"num:i($OptimalPCSCLK)"!]_U32 | DSPI_CTAR_SCSCLK_[!"num:i($OptimalSCSCLK)"!]_U32 | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Clk)"!], Error=[!"round(10000*$OptimalTimeCs2ClkError) div 100"!]% */
            DSPI_CTAR_PASC_[!"num:i($OptimalPASC)"!]_U32 | DSPI_CTAR_SASC_[!"num:i($OptimalSASC)"!]_U32 | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2Cs)"!], Error=[!"round(10000*$OptimalTimeClk2CsError) div 100"!]% */
            DSPI_CTAR_PDT_[!"num:i($OptimalPDT)"!]_U32 | DSPI_CTAR_SDT_[!"num:i($OptimalSDT)"!]_U32 | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Cs)"!], Error=[!"round(10000*$OptimalTimeCs2CsError) div 100"!]% */
            DSPI_CTAR_PBR_[!"num:i($OptimalPBR)"!]_U32 | DSPI_CTAR_SBR_[!"num:i($OptimalSBR)"!]_U32 | DSPI_CTAR_DBR_[!"num:i($OptimalDBR)"!]_U32), /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateNormal)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorNormal) div 100"!]% */
[!IF "$DualClockSupport = 'true'"!][!//
[!IF "$DualClockEnabled = 'true'"!][!//
            /* Alternate Mode */
            (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
            [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    DSPI_CTAR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    DSPI_CTAR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */
            DSPI_CTAR_PCSCLK_[!"num:i($OptimalPCSCLKAlternate)"!]_U32 | DSPI_CTAR_SCSCLK_[!"num:i($OptimalSCSCLKAlternate)"!]_U32 | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2ClkAlternate)"!], Error=[!"round(10000*$OptimalTimeCs2ClkErrorAlternate) div 100"!]% */
            DSPI_CTAR_PASC_[!"num:i($OptimalPASCAlternate)"!]_U32 | DSPI_CTAR_SASC_[!"num:i($OptimalSASCAlternate)"!]_U32 | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2CsAlternate)"!], Error=[!"round(10000*$OptimalTimeClk2CsErrorAlternate) div 100"!]% */
            DSPI_CTAR_PDT_[!"num:i($OptimalPDTAlternate)"!]_U32 | DSPI_CTAR_SDT_[!"num:i($OptimalSDTAlternate)"!]_U32 | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2CsAlternate)"!], Error=[!"round(10000*$OptimalTimeCs2CsErrorAlternate) div 100"!]% */
            DSPI_CTAR_PBR_[!"num:i($OptimalPBRAlternate)"!]_U32 | DSPI_CTAR_SBR_[!"num:i($OptimalSBRAlternate)"!]_U32 | DSPI_CTAR_DBR_[!"num:i($OptimalDBRAlternate)"!]_U32 ) /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateAlternate)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorAlternate) div 100"!]% */
[!ELSE!][!//
            /*SpiHwUnit is not enable Alternate Mode, Set CTAR is the same configuration as Normal Mode to use*/
            /* Normal Mode */
            (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
                [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    DSPI_CTAR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    DSPI_CTAR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */
            DSPI_CTAR_PCSCLK_[!"num:i($OptimalPCSCLK)"!]_U32 | DSPI_CTAR_SCSCLK_[!"num:i($OptimalSCSCLK)"!]_U32 | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Clk)"!], Error=[!"round(10000*$OptimalTimeCs2ClkError) div 100"!]% */
            DSPI_CTAR_PASC_[!"num:i($OptimalPASC)"!]_U32 | DSPI_CTAR_SASC_[!"num:i($OptimalSASC)"!]_U32 | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeClk2Cs)"!], Error=[!"round(10000*$OptimalTimeClk2CsError) div 100"!]% */
            DSPI_CTAR_PDT_[!"num:i($OptimalPDT)"!]_U32 | DSPI_CTAR_SDT_[!"num:i($OptimalSDT)"!]_U32 | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000000)"!]ns, Is=[!"num:i($OptimalTimeCs2Cs)"!], Error=[!"round(10000*$OptimalTimeCs2CsError) div 100"!]% */
            DSPI_CTAR_PBR_[!"num:i($OptimalPBR)"!]_U32 | DSPI_CTAR_SBR_[!"num:i($OptimalSBR)"!]_U32 | DSPI_CTAR_DBR_[!"num:i($OptimalDBR)"!]_U32), /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateNormal)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorNormal) div 100"!]% */
[!ENDIF!][!//
          },   
[!ENDIF!][!//
[!IF "SpiEnableCs = 'true'"!]
    [!IF "SpiCsSelection = 'CS_VIA_PERIPHERAL_ENGINE'"!][!//
            (uint32)(DSPI_CMD_[!"SpiCsIdentifier"!]_U32 | /* Chip Select Pin Via Peripheral Engine*/     
    [!IF "SpiCsContinous = 'FALSE'"!][!WS "12"!]    DSPI_CMD_CONTINOUS_FALSE_U32),/* Continuous chip select */
    [!ELSEIF "SpiCsContinous = 'TRUE'"!][!WS "12"!]    DSPI_CMD_CONTINOUS_TRUE_U32),/* Continuous chip select */
    [!ELSE!][!ERROR "Illegal value for SpiCsContinous"!][!//
    [!ENDIF!][!//
    [!ELSEIF "SpiCsSelection = 'CS_VIA_GPIO'"!][!//
            0x00000000u,/* Chip Select Via GPIO */
    [!ENDIF!][!//
[!ELSE!][!WS "8"!]0x00000000u,
[!ENDIF!]
            [!IF "SpiCsPolarity = 'HIGH'"!][!//
        [!WS "8"!]    DSPI_[!"SpiCsIdentifier"!]_IDLEHIGH_U32[!//
[!ELSE!][!WS "8"!](uint32)0u[!//
[!ENDIF!][!WS "2"!]/* Chip select polarity */
[!ENDMACRO!][!//
[!//===================================================================================================
[!//
[!//===================================================================================================
[!MACRO "GenerateSlaveDeviceInfo"!]
    [!IF "$DualClockSupport = 'true'"!][!//
          {
          /* Normal Mode */
        [!ENDIF!][!//
                    (uint32)(([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
            [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
            [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
            [!ENDIF!] | /* Clock Polarity (Idle State) */
                            [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    DSPI_CTAR_CPHA_LEADING_U32[!//
            [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    DSPI_CTAR_CPHA_TRAILING_U32[!//
            [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
            [!ENDIF!] | (uint32)0u ) & DSPI_CTAR_SLAVE_RESERVED_MASK_U32),
        [!IF "$DualClockSupport = 'true'"!][!//
    [!IF "$DualClockEnabled = 'true'"!][!//
                    /* Alternate Mode */
                    (uint32)(([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
            [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
            [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
            [!ENDIF!] | /* Clock Polarity (Idle State) */
                            [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    DSPI_CTAR_CPHA_LEADING_U32[!//
            [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    DSPI_CTAR_CPHA_TRAILING_U32[!//
            [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
            [!ENDIF!] | (uint32)0u ) & DSPI_CTAR_SLAVE_RESERVED_MASK_U32)
[!ELSE!][!//
            /*SpiHwUnit is not enable Alternate Mode, Set CTAR is the same configuration as Normal Mode to use*/
            /* Normal Mode */
            (uint32)(([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
            [!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
            [!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
            [!ENDIF!] | /* Clock Polarity (Idle State) */
                            [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    DSPI_CTAR_CPHA_LEADING_U32[!//
            [!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    DSPI_CTAR_CPHA_TRAILING_U32[!//
            [!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
            [!ENDIF!] | (uint32)0u ) & DSPI_CTAR_SLAVE_RESERVED_MASK_U32)
[!ENDIF!][!//
         },
        [!ENDIF!][!//
            (uint32)[!WS "8"!]0x00000000u,
            [!IF "SpiCsPolarity = 'HIGH'"!][!//
                [!WS "8"!]    DSPI_[!"SpiCsIdentifier"!]_IDLEHIGH_U32[!//
            [!ELSE!][!//
            [!WS "8"!]  (uint32)0u[!//
            [!ENDIF!][!WS "2"!]/* Chip select polarity */
    [!ENDMACRO!][!//
[!//===================================================================================================
[!//
[!//===================================================================================================
[!MACRO "GenerateTSBExternalDeviceInfo"!]
[!NOCODE!][!//
  [!//
  [!VAR "BusClock" = "$BusClockNormal"!][!//
  [!VAR "DesiredTime" = "num:i(SpiTimeCs2Clk * 1000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPCSCLK" = "$OptimalPrescaler"!]
  [!VAR "OptimalSCSCLK" = "$OptimalScaler"!]
  [!VAR "OptimalTimeCs2Clk" = "$OptimalTime"!]
  [!VAR "OptimalTimeCs2ClkError" = "$OptimalRelativeTimeError"!]
  [!//
  [!VAR "DesiredTime" = "num:i(SpiTimeClk2Cs * 1000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPASC" = "$OptimalPrescaler"!]
  [!VAR "OptimalSASC" = "$OptimalScaler"!]
  [!VAR "OptimalTimeClk2Cs" = "$OptimalTime"!]
  [!VAR "OptimalTimeClk2CsError" = "$OptimalRelativeTimeError"!]
  [!//
  [!VAR "DesiredTime" = "num:i(SpiTimeCs2Cs * 1000000)"!]
  [!CALL "DetermineOptimalTimeSettings"!]
  [!VAR "OptimalPDT" = "$OptimalPrescaler"!]
  [!VAR "OptimalSDT" = "$OptimalScaler"!]
  [!VAR "OptimalTimeCs2Cs" = "$OptimalTime"!]
  [!VAR "OptimalTimeCs2CsError" = "$OptimalRelativeTimeError"!]
  [!//
  [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
  [!CALL "DetermineOptimalBaudrateSettings"!]
  [!VAR "OptimalPBR" = "$OptimalPrescaler"!]
  [!VAR "OptimalSBR" = "$OptimalScaler"!]
  [!VAR "OptimalDBR" = "$OptimalDouble"!]
  [!VAR "OptimalBaudrateNormal" = "$OptimalBaudrate"!]
  [!VAR "OptimalRelativeBaudrateErrorNormal" = "$OptimalRelativeBaudrateError"!]
  [!//
  [!IF "$DualClockEnabled = 'true'"!][!//
    [!VAR "BusClock" = "$BusClockAlternate"!][!//
    [!VAR "DesiredTime" = "num:i(SpiTimeCs2Clk * 1000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPCSCLKAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSCSCLKAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeCs2ClkAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeCs2ClkErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
    [!VAR "DesiredTime" = "num:i(SpiTimeClk2Cs * 1000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPASCAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSASCAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeClk2CsAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeClk2CsErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
    [!VAR "DesiredTime" = "num:i(SpiTimeCs2Cs * 1000000)"!]
    [!CALL "DetermineOptimalTimeSettings"!]
    [!VAR "OptimalPDTAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSDTAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalTimeCs2CsAlternate" = "$OptimalTime"!]
    [!VAR "OptimalTimeCs2CsErrorAlternate" = "$OptimalRelativeTimeError"!]
    [!//
    [!VAR "DesiredBaudrate" = "SpiBaudrate"!]
    [!CALL "DetermineOptimalBaudrateSettings"!]
    [!VAR "OptimalPBRAlternate" = "$OptimalPrescaler"!]
    [!VAR "OptimalSBRAlternate" = "$OptimalScaler"!]
    [!VAR "OptimalDBRAlternate" = "$OptimalDouble"!]
    [!VAR "OptimalBaudrateAlternate" = "$OptimalBaudrate"!]
    [!VAR "OptimalRelativeBaudrateErrorAlternate" = "$OptimalRelativeBaudrateError"!]
  [!ENDIF!][!// "$DualClockEnabled = 'true'"
  [!//
[!ENDNOCODE!][!//
[!IF "$DualClockSupport = 'true'"!][!//
          {
            /* Normal Mode */
[!ENDIF!][!//
        (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
        [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]DSPI_CTAR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]DSPI_CTAR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */
        DSPI_CTAR_PCSCLK_[!"num:i($OptimalPCSCLK)"!]_U32 | DSPI_CTAR_SCSCLK_[!"num:i($OptimalSCSCLK)"!]_U32 | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000)"!], Is=[!"num:i($OptimalTimeCs2Clk)"!], Error=[!"round(10000*$OptimalTimeCs2ClkError) div 100"!]% */
        DSPI_CTAR_PASC_[!"num:i($OptimalPASC)"!]_U32 | DSPI_CTAR_SASC_[!"num:i($OptimalSASC)"!]_U32 | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000)"!], Is=[!"num:i($OptimalTimeClk2Cs)"!], Error=[!"round(10000*$OptimalTimeClk2CsError) div 100"!]% */
        DSPI_CTAR_PDT_[!"num:i($OptimalPDT)"!]_U32 | DSPI_CTAR_SDT_[!"num:i($OptimalSDT)"!]_U32 | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000)"!], Is=[!"num:i($OptimalTimeCs2Cs)"!], Error=[!"round(10000*$OptimalTimeCs2CsError) div 100"!]% */
        DSPI_CTAR_PBR_[!"num:i($OptimalPBR)"!]_U32 | DSPI_CTAR_SBR_[!"num:i($OptimalSBR)"!]_U32 | DSPI_CTAR_DBR_[!"num:i($OptimalDBR)"!]_U32 |
        [!IF "$Dualreceiver = 0"!]DSPI_DUALRECEIVER_DISABLED_U32[!ELSE!][!//
        DSPI_CMD_WIDTH_[!"$Dualreceiver"!]_U32[!ENDIF!])[!IF "$DualClockSupport = 'true'"!],[!ENDIF!] /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrate)"!], Error=[!"round(10000*$OptimalRelativeBaudrateError) div 100"!]% */
[!IF "$DualClockSupport = 'true'"!][!//
[!IF "$DualClockEnabled = 'true'"!][!//
            /* Alternate Mode */
            (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
            [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]    DSPI_CTAR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]    DSPI_CTAR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */
            DSPI_CTAR_PCSCLK_[!"num:i($OptimalPCSCLKAlternate)"!]_U32 | DSPI_CTAR_SCSCLK_[!"num:i($OptimalSCSCLKAlternate)"!]_U32 | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000)"!], Is=[!"num:i($OptimalTimeCs2ClkAlternate)"!], Error=[!"round(10000*$OptimalTimeCs2ClkErrorAlternate) div 100"!]% */
            DSPI_CTAR_PASC_[!"num:i($OptimalPASCAlternate)"!]_U32 | DSPI_CTAR_SASC_[!"num:i($OptimalSASCAlternate)"!]_U32 | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000)"!], Is=[!"num:i($OptimalTimeClk2CsAlternate)"!], Error=[!"round(10000*$OptimalTimeClk2CsErrorAlternate) div 100"!]% */
            DSPI_CTAR_PDT_[!"num:i($OptimalPDTAlternate)"!]_U32 | DSPI_CTAR_SDT_[!"num:i($OptimalSDTAlternate)"!]_U32 | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000)"!], Is=[!"num:i($OptimalTimeCs2CsAlternate)"!], Error=[!"round(10000*$OptimalTimeCs2CsErrorAlternate) div 100"!]% */
            DSPI_CTAR_PBR_[!"num:i($OptimalPBRAlternate)"!]_U32 | DSPI_CTAR_SBR_[!"num:i($OptimalSBRAlternate)"!]_U32 | DSPI_CTAR_DBR_[!"num:i($OptimalDBRAlternate)"!]_U32 |
            [!IF "$Dualreceiver = 0"!]DSPI_DUALRECEIVER_DISABLED_U32[!ELSE!][!//
            DSPI_CMD_WIDTH_[!"$Dualreceiver"!]_U32[!ENDIF!]) /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrateAlternate)"!], Error=[!"round(10000*$OptimalRelativeBaudrateErrorAlternate) div 100"!]% */
    [!ELSE!]
            /*SpiHwUnit is not enable Alternate Mode, Set CTAR is the same configuration as Normal Mode to use*/
            /* Normal Mode */
            (uint32)([!IF "SpiShiftClockIdleLevel = 'LOW'"!]DSPI_CTAR_CPOL_LOW_U32[!//
[!ELSEIF "SpiShiftClockIdleLevel = 'HIGH'"!]DSPI_CTAR_CPOL_HIGH_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiShiftClockIdleLevel"!][!//
[!ENDIF!] | /* Clock Polarity (Idle State) */
        [!IF "SpiDataShiftEdge = 'LEADING'"!][!WS "8"!]DSPI_CTAR_CPHA_LEADING_U32[!//
[!ELSEIF "SpiDataShiftEdge = 'TRAILING'"!][!WS "8"!]DSPI_CTAR_CPHA_TRAILING_U32[!//
[!ELSE!][!ERROR "Illegal value for SpiDataShiftEdge"!][!//
[!ENDIF!] | /* Clock Phase */
        DSPI_CTAR_PCSCLK_[!"num:i($OptimalPCSCLK)"!]_U32 | DSPI_CTAR_SCSCLK_[!"num:i($OptimalSCSCLK)"!]_U32 | /* TimeCs2Clk: Should=[!"num:i(SpiTimeCs2Clk * 1000000)"!], Is=[!"num:i($OptimalTimeCs2Clk)"!], Error=[!"round(10000*$OptimalTimeCs2ClkError) div 100"!]% */
        DSPI_CTAR_PASC_[!"num:i($OptimalPASC)"!]_U32 | DSPI_CTAR_SASC_[!"num:i($OptimalSASC)"!]_U32 | /* TimeClk2Cs: Should=[!"num:i(SpiTimeClk2Cs * 1000000)"!], Is=[!"num:i($OptimalTimeClk2Cs)"!], Error=[!"round(10000*$OptimalTimeClk2CsError) div 100"!]% */
        DSPI_CTAR_PDT_[!"num:i($OptimalPDT)"!]_U32 | DSPI_CTAR_SDT_[!"num:i($OptimalSDT)"!]_U32 | /* TimeCs2Cs: Should=[!"num:i(SpiTimeCs2Cs * 1000000)"!], Is=[!"num:i($OptimalTimeCs2Cs)"!], Error=[!"round(10000*$OptimalTimeCs2CsError) div 100"!]% */
        DSPI_CTAR_PBR_[!"num:i($OptimalPBR)"!]_U32 | DSPI_CTAR_SBR_[!"num:i($OptimalSBR)"!]_U32 | DSPI_CTAR_DBR_[!"num:i($OptimalDBR)"!]_U32 |
        [!IF "$Dualreceiver = 0"!]DSPI_DUALRECEIVER_DISABLED_U32[!ELSE!][!//
        DSPI_CMD_WIDTH_[!"$Dualreceiver"!]_U32[!ENDIF!]) /* Baudrate: Should=[!"SpiBaudrate"!], Is=[!"num:i($OptimalBaudrate)"!], Error=[!"round(10000*$OptimalRelativeBaudrateError) div 100"!]% */
    [!ENDIF!]
          }
[!ENDIF!][!//
[!ENDMACRO!][!//
[!//===================================================================================================
[!//
[!MACRO "GenerateTSLValue"!]
[!NOCODE!][!//
[!VAR "TS3Val" = "bit:shl(TS3_LEN,24)"!]
[!VAR "TS2Val" = "bit:shl(TS2_LEN,16)"!]
[!VAR "TS1Val" = "bit:shl(TS1_LEN,8)"!]
[!VAR "TS0Val" = "TS0_LEN"!]
[!VAR "TSL1Val" = "bit:or($TS3Val,$TS2Val)"!]
[!VAR "TSL2Val" = "bit:or($TS1Val,$TS0Val)"!]
[!VAR "TSLVal" = "bit:or($TSL1Val,$TSL2Val)"!]
[!ENDNOCODE!][!//
                (uint32)[!"num:inttohex($TSLVal,8)"!]u,
[!ENDMACRO!]
[!//
[!//=================Check repeat of Job, Seq, External device==========================================
[!MACRO "Spi_CheckRepeatOfJobSeqExternalDevice"!]
[!NOCODE!][!//
[!//Check repeat of SpiJobs
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "Matchcounter" = "0"!]
    [!VAR "Name" = "node:name(.)"!]
    [!LOOP "../*"!]
    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
      [!IF "($Name = node:name(.))"!]
          [!VAR "Matchcounter" = "$Matchcounter + 1"!]
       [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$Matchcounter = 1"!]
    [!ELSE!][!//
        [!ERROR!]SpiJob Symbolic name "[!"@name"!]" for the two or more SpiJobs is repeated.[!ENDERROR!]
    [!ENDIF!][!//
[!ENDLOOP!][!//

[!//Check repeat of SpiSequences
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!LOOP "SpiDriver/SpiSequence/*"!][!//
[!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "Matchcounter" = "0"!]
    [!VAR "Name" = "node:name(.)"!]
    [!LOOP "../*"!]
    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
      [!IF "($Name = node:name(.))"!]
          [!VAR "Matchcounter" = "$Matchcounter + 1"!]
       [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$Matchcounter = 1"!]
    [!ELSE!][!//
        [!ERROR!]SpiSequences Symbolic name "[!"@name"!]" for the two or more SpiSequences is repeated.[!ENDERROR!]
    [!ENDIF!][!//
[!ENDLOOP!][!//

[!//Check repeat of SpiExternalDevices
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
[!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!]
    [!VAR "InnerLoopCounter" = "0"!]
    [!VAR "Matchcounter" = "0"!]
    [!VAR "Name" = "node:name(.)"!]
    [!LOOP "../*"!]
    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!]
    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!]
      [!IF "($Name = node:name(.))"!]
          [!VAR "Matchcounter" = "$Matchcounter + 1"!]
       [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$Matchcounter = 1"!]
    [!ELSE!][!//
        [!ERROR!]SpiExternalDevice Symbolic name "[!"@name"!]" for the two or more SpiExternalDevices is repeated.[!ENDERROR!]
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!]
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//=========Check repeat of SpiPhyTxDmaChannel, SpiPhyTxDmaChannelAux, SpiPhyRxDmaChannel============
[!MACRO "Spi_CheckRepeatOfDmaChannels"!]
[!NOCODE!][!//
[!IF "ecu:get('SpiDMAPresent') = 'TRUE'"!]
    [!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
        [!VAR "Unit_Name"="@name"!]
        [!IF "(SpiPhyUnitAsyncMethod = 'DMA')"!]
            [!VAR "Spi_PhyTxDmaChannel1"="SpiPhyTxDmaChannel"!]
            [!VAR "Spi_PhyTxDmaChannel2"="SpiPhyTxDmaChannelAux"!]
            [!VAR "Spi_PhyRxDmaChannel"="SpiPhyRxDmaChannel"!]

            [!IF "($Spi_PhyTxDmaChannel1 = $Spi_PhyTxDmaChannel2)"!]
                [!ERROR!]
                        SpiPhyTxDmaChannel ([!"$Spi_PhyTxDmaChannel1"!]) and SpiPhyTxDmaChannelAux ([!"$Spi_PhyTxDmaChannel2"!]) values in [!"@name"!] are repeated. Please select different values for SpiPhyTxDmaChannel and SpiPhyTxDmaChannelAux.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "($Spi_PhyTxDmaChannel1 = $Spi_PhyRxDmaChannel)"!]
                [!ERROR!]
                        SpiPhyTxDmaChannel ([!"$Spi_PhyTxDmaChannel1"!]) and SpiPhyRxDmaChannel ([!"$Spi_PhyRxDmaChannel"!]) values in [!"@name"!] are repeated. Please select different values for SpiPhyTxDmaChannel and SpiPhyRxDmaChannel.
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "($Spi_PhyTxDmaChannel2 = $Spi_PhyRxDmaChannel)"!]
                [!ERROR!]
                        SpiPhyTxDmaChannelAux ([!"$Spi_PhyTxDmaChannel2"!]) and SpiPhyRxDmaChannel ([!"$Spi_PhyRxDmaChannel"!]) values in [!"@name"!] are repeated. Please select different values for SpiPhyTxDmaChannelAux and SpiPhyRxDmaChannel.
                [!ENDERROR!]
            [!ENDIF!]

            [!LOOP "../../SpiPhyUnit/*"!]
                [!IF "(SpiPhyUnitAsyncMethod = 'DMA')"!]
                    [!IF "($Spi_PhyTxDmaChannel1 = SpiPhyTxDmaChannelAux)"!]
                        [!ERROR!]
                            SpiPhyTxDmaChannel ([!"$Spi_PhyTxDmaChannel1"!]) in [!"$Unit_Name"!] container and SpiPhyTxDmaChannelAux ([!"SpiPhyTxDmaChannelAux"!]) in [!"@name"!] are repeated. Please select different values for SpiPhyTxDmaChannel and SpiPhyTxDmaChannelAux.
                        [!ENDERROR!]
                    [!ENDIF!]
                    [!IF "($Spi_PhyTxDmaChannel1 = SpiPhyRxDmaChannel)"!]
                        [!ERROR!]
                            SpiPhyTxDmaChannel ([!"$Spi_PhyTxDmaChannel1"!]) in [!"$Unit_Name"!] container and SpiPhyRxDmaChannel ([!"SpiPhyRxDmaChannel"!]) in [!"@name"!] are repeated. Please select different values for SpiPhyTxDmaChannel and SpiPhyRxDmaChannel.
                        [!ENDERROR!]
                    [!ENDIF!]
                    [!IF "($Spi_PhyTxDmaChannel2 = SpiPhyRxDmaChannel)"!]
                        [!ERROR!]
                            SpiPhyTxDmaChannelAux ([!"$Spi_PhyTxDmaChannel2"!]) in [!"$Unit_Name"!] container and SpiPhyRxDmaChannel ([!"SpiPhyRxDmaChannel"!]) in [!"@name"!] are repeated. Please select different values for SpiPhyTxDmaChannelAux and SpiPhyRxDmaChannel.
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDLOOP!][!//
        [!ENDIF!]
    [!ENDLOOP!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//============Check the number of sequences, Jobs, Channels =======================================
[!MACRO "Spi_CheckNumberOfSequenceJobChannel"!]
[!NOCODE!][!//
[!// Calculate the maximum number of elements (sequences, jobs, channels) in configuration.
[!VAR "SpiMaxSequencesCount" = "0"!][!//
[!VAR "SpiMaxJobsCount" = "0"!][!//
[!VAR "SpiMaxChannelsCount" = "0"!][!//
[!VAR "SpiMaxOneJobSequences" = "0"!][!//
[!VAR "SpiMaxOneJobSeqChannels" = "0"!][!//
[!VAR "SpiMaxSequencesAllowed" = "256"!][!//
[!VAR "SpiMaxJobsAllowed" = "65536"!][!//
[!VAR "SpiMaxChannelsAllowed" = "256"!][!//

[!VAR "TmpCounter" = "num:i(count(SpiDriver/SpiSequence/*))"!]
[!IF "$SpiMaxSequencesCount < $TmpCounter"!]
    [!VAR "SpiMaxSequencesCount" = "$TmpCounter"!]
[!ENDIF!]
[!VAR "TmpCounter" = "num:i(count(SpiDriver/SpiJob/*))"!]
[!IF "$SpiMaxJobsCount < $TmpCounter"!]
    [!VAR "SpiMaxJobsCount" = "$TmpCounter"!]
[!ENDIF!]
[!VAR "TmpCounter" = "num:i(count(SpiDriver/SpiChannel/*))"!]
[!IF "$SpiMaxChannelsCount < $TmpCounter"!]
    [!VAR "SpiMaxChannelsCount" = "$TmpCounter"!]
[!ENDIF!]
[!VAR "TmpCounter" = "num:i(count(SpiDriver/SpiSequence/*[count(SpiJobAssignment/*) = 1]))"!]
[!IF "$SpiMaxOneJobSequences < $TmpCounter"!]
    [!VAR "SpiMaxOneJobSequences" = "$TmpCounter"!]
[!ENDIF!]
[!VAR "TmpCounter" = "num:i(count(node:refs(SpiDriver/SpiSequence/*[count(SpiJobAssignment/*) = 1]/SpiJobAssignment/*)/SpiChannelList/*/SpiChannelAssignment))"!]
[!IF "$SpiMaxOneJobSeqChannels < $TmpCounter"!]
    [!VAR "SpiMaxOneJobSeqChannels" = "$TmpCounter"!]
[!ENDIF!]
    
[!IF "(node:value(SpiNonAUTOSAR/SpiAllowBigSizeCollections) = 'false')"!]
    [!IF "$SpiMaxSequencesCount > $SpiMaxSequencesAllowed"!]
        [!ERROR!]
            The number of sequences defined exceeds the maximum number allowed ([!"num:i($SpiMaxSequencesAllowed)"!]).
        [!ENDERROR!]
    [!ENDIF!]
    [!IF "$SpiMaxChannelsCount > $SpiMaxChannelsAllowed"!]
        [!ERROR!]
            The number of channels defined exceeds the maximum number allowed ([!"num:i($SpiMaxChannelsAllowed)"!]).
        [!ENDERROR!]
    [!ENDIF!]
    [!IF "$SpiMaxJobsCount > $SpiMaxJobsAllowed"!]
        [!ERROR!]
            The number of jobs defined exceeds the maximum number allowed ([!"num:i($SpiMaxJobsAllowed)"!]).
        [!ENDERROR!]
    [!ENDIF!]
[!ENDIF!]
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//================= List Of Notification Functions =================================================
[!MACRO "Spi_ListOfNotificationFunctions"!]
/* Job start Notifications */
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!VAR "WhiteSpaceInstartJobNotification"="normalize-space(SpiJobStartNotification)"!][!//
[!IF "(string-length($WhiteSpaceInstartJobNotification)>0) and (SpiJobStartNotification!='NULL_PTR') and (SpiJobStartNotification!='NULL')"!][!//
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void [!"SpiJobStartNotification"!](void); /* start job Notification for Job '[!"name(.)"!]' */
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//

/* Job End Notifications */
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!VAR "WhiteSpaceInJobEndNotification"="normalize-space(SpiJobEndNotification)"!][!//
[!IF "(string-length($WhiteSpaceInJobEndNotification)>0) and (SpiJobEndNotification!='NULL_PTR') and (SpiJobEndNotification!='NULL')"!][!//
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void [!"SpiJobEndNotification"!](void); /* End Notification for Job '[!"name(.)"!]' */
[!ENDIF!][!//
[!ENDLOOP!][!//
[!//
/* Sequence End Notifications */
[!NOCODE!]
[!LOOP "SpiDriver/SpiSequence/*"!][!//
[!VAR "WhiteSpaceInSeqEndNotification"="normalize-space(SpiSeqEndNotification)"!][!//
[!IF "(string-length($WhiteSpaceInSeqEndNotification)>0)  and (SpiSeqEndNotification!='NULL_PTR') and (SpiSeqEndNotification!='NULL')"!][!//
[!CODE!]
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 An external object or function shall be declared in one and only one file.
*/
extern void [!"SpiSeqEndNotification"!](void); /* End Notification for Sequence '[!"name(.)"!]' */
[!ENDCODE!]
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================================================================================================
[!MACRO "Spi_CheckChannelAttributes"!]
[!NOCODE!][!//
[!VAR "OuterLoopCounter" = "$OuterLoopCounter + 1"!][!//
    [!VAR "InnerLoopCounter" = "0"!][!//
    [!VAR "Matchcounter" = "0"!][!//
    [!VAR "TempChannel_FirstSpiChannelId" = "0"!][!//
    [!VAR "TempChannel_FirstSpiChannelType" = "SpiChannelType"!][!//
    [!VAR "TempChannel_FirstSpiDataWidth" = "SpiDataWidth"!][!//
    [!VAR "TempChannel_FirstSpiDefaultData" = "SpiDefaultData"!][!//
    [!VAR "TempChannel_FirstSpiEbMaxLength" = "SpiEbMaxLength"!][!//
    [!VAR "TempChannel_FirstSpiIbNBuffers" = "SpiChannelType"!][!//
    [!VAR "TempChannel_FirstSpiTransferStart" = "SpiTransferStart"!][!//
    [!VAR "Name" = "node:name(.)"!][!//
    [!LOOP "../*"!][!//
    [!VAR "InnerLoopCounter" = "$InnerLoopCounter + 1"!][!//
    [!IF "$OuterLoopCounter >= $InnerLoopCounter"!][!//
      [!IF "($Name = node:name(.))"!][!//
         [!VAR "Matchcounter" = "$Matchcounter + 1"!][!//
         [!IF "$Matchcounter = 1"!][!//
         [!VAR "TempChannel_FirstSpiChannelId" = "SpiChannelId"!][!//
         [!VAR "TempChannel_FirstSpiChannelType" = "SpiChannelType"!][!//
         [!VAR "TempChannel_FirstSpiDataWidth" = "SpiDataWidth"!][!//
         [!VAR "TempChannel_FirstSpiDefaultData" = "SpiDefaultData"!][!//
         [!VAR "TempChannel_FirstSpiEbMaxLength" = "SpiEbMaxLength"!][!//
         [!VAR "TempChannel_FirstSpiIbNBuffers" = "SpiIbNBuffers"!][!//
         [!VAR "TempChannel_FirstSpiTransferStart" = "SpiTransferStart"!][!//
         [!ENDIF!][!//
         [!IF "($Matchcounter > 1) and (SpiChannelType = 'IB')"!][!//
         [!IF "($TempChannel_FirstSpiChannelId != SpiChannelId) or ($TempChannel_FirstSpiChannelType != SpiChannelType) or
         ($TempChannel_FirstSpiDataWidth != SpiDataWidth) or ($TempChannel_FirstSpiDefaultData != SpiDefaultData) or
         ($TempChannel_FirstSpiIbNBuffers != SpiIbNBuffers) or($TempChannel_FirstSpiTransferStart != SpiTransferStart) "!][!//
         [!ERROR!]If the same symbolic channel name [!"node:name(.)"!] is used for more than one channel, all channel attributes shall be identical.[!ENDERROR!]
         [!ENDIF!][!//
         [!ENDIF!][!//
         [!IF "($Matchcounter > 1) and (SpiChannelType = 'EB')"!][!//
         [!IF "($TempChannel_FirstSpiChannelId != SpiChannelId) or ($TempChannel_FirstSpiChannelType != SpiChannelType) or
         ($TempChannel_FirstSpiDataWidth != SpiDataWidth) or ($TempChannel_FirstSpiDefaultData != SpiDefaultData) or
         ($TempChannel_FirstSpiEbMaxLength != SpiEbMaxLength) or ($TempChannel_FirstSpiTransferStart != SpiTransferStart) "!][!//
         [!ERROR!]If the same symbolic channel name [!"node:name(.)"!] is used for more than one channel, all channel attributes shall be identical.[!ENDERROR!]
         [!ENDIF!][!//
         [!ENDIF!][!//
      [!ENDIF!][!//
    [!ENDIF!][!//
    [!ENDLOOP!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//===================Buffers Descriptors for EB Channels and Allocate Buffers for IB Channels=======
[!MACRO "Spi_BuffersDescriptorForEBchannel"!]
[!NOCODE!][!//
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!ENDNOCODE!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!CALL "Spi_CheckChannelAttributes"!][!//
[!IF "$Matchcounter = 1"!]
[!IF "SpiChannelType = 'EB'"!][!//
[!IF "num:i(SpiDataWidth) > 8"!][!//
VAR_ALIGN(static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PB[!"name(.)"!], 2)
[!ELSE!][!//
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PB[!"name(.)"!];
[!ENDIF!][!//

/* Allocate Buffers for IB Channels (if any) */

[!ELSEIF "SpiChannelType = 'IB'"!][!//
[!IF "num:i(SpiDataWidth) > 8"!][!//
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PB[!"name(.)"!][[!"SpiIbNBuffers"!]], 2)
VAR_ALIGN(static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PB[!"name(.)"!][[!"SpiIbNBuffers"!]], 2)
[!ELSE!][!//
static VAR(Spi_DataBufferType, SPI_VAR) BufferTX_PB[!"name(.)"!][[!"SpiIbNBuffers"!]];
static VAR(Spi_DataBufferType, SPI_VAR) BufferRX_PB[!"name(.)"!][[!"SpiIbNBuffers"!]];
[!ENDIF!][!//
[!ELSE!][!//
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//=================Buffers Descriptors for IB Channels==============================================
[!MACRO "Spi_BuffersDescriptorForIBchannel"!]
/*  Buffers Descriptors for IB Channels (if any) */
[!NOCODE!][!//
[!VAR "OuterLoopCounter" = "0"!][!//
[!VAR "InnerLoopCounter" = "0"!][!//
[!ENDNOCODE!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!CALL "Spi_CheckChannelAttributes"!][!//
[!IF "$Matchcounter = 1"!][!//
[!IF "SpiChannelType = 'IB'"!][!//
static VAR(Spi_BufferDescriptorType, SPI_VAR) Buffer_PB[!"name(.)"!] =
{
    BufferTX_PB[!"name(.)"!],
    BufferRX_PB[!"name(.)"!]
};
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================================================================================================
[!// POSTBUILD FLASH from here onward! */
[!//=================Channel Configuration============================================================
[!MACRO "Spi_ChannelConfiguration"!]
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiChannel/*)"!][!//
/* SpiChannelConfig_PB[!"@index"!] Channel Configuration of [!"name(.)"!]*/
static CONST(Spi_ChannelConfigType, SPI_CONST) SpiChannelConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiChannel/*))"!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiChannelId = $Loop"!][!//
    {
        /* [!"name(.)"!]*/
        [!"SpiChannelType"!],
        (Spi_DataBufferType)[!"SpiDefaultData"!]U,
[!IF "SpiChannelType = 'IB'"!][!//
        [!"SpiIbNBuffers"!]U,
[!ENDIF!][!//
[!IF "SpiChannelType = 'EB'"!][!//
        [!"SpiEbMaxLength"!]U,
[!ENDIF!][!//
        &Buffer_PB[!"name(.)"!],
        &Spi_aSpiChannelState[[!"SpiChannelId"!]]
    }[!IF "$idx!=$count"!],[!ENDIF!]
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================Channel Assignment of Jobs =====================================================
[!MACRO "Spi_ChannelAssignmentOfJobs"!]
/* Channel to Job Assignment */
[!/* Retrieves all Channel assignments */!]
[!LOOP "SpiDriver/SpiJob/*"!][!//
static CONST(Spi_ChannelType, SPI_CONST) [!"name(.)"!]_ChannelAssignment_PB[[!"num:i(count(SpiChannelList/*))"!]] = {[!//
[!LOOP "SpiChannelList/*"!][!//
[!IF "@index > 0"!],[!ENDIF!][!//
SpiConf_SpiChannel_[!"name(node:ref(SpiChannelAssignment))"!][!//
[!ENDLOOP!]};
[!ENDLOOP!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//========Configuration of Jobs=====================================================================
[!MACRO "Spi_JobConfiguration"!]
[!VAR "spiPath" = "node:path(.)"!][!//
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiJob/*)"!][!//
/* SpiJobConfig_PB[!"@index"!] Job Configuration of [!"name(.)"!]*/
static CONST(Spi_JobConfigType, SPI_CONST) SpiJobConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiJob/*))"!][!//
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiJobId = $Loop"!][!//
    {
[!VAR "WhiteSpaceInJobEndNotification1"="normalize-space(SpiJobEndNotification)"!]
[!VAR "WhiteSpaceInstartJobNotification1"="normalize-space(SpiJobStartNotification)"!]
        /* [!"name(.)"!] */
        (Spi_ChannelType)[!"num:i(count(SpiChannelList/*))"!]u,
        &[!"name(.)"!]_ChannelAssignment_PB, /* List of Channels */
[!IF "(string-length($WhiteSpaceInJobEndNotification1)>0) and (SpiJobEndNotification!='NULL_PTR') and (SpiJobEndNotification!='NULL')"!][!//
        &[!"SpiJobEndNotification"!][!//
[!ELSE!][!//
        NULL_PTR[!//
[!ENDIF!], /* End Notification */
[!IF "(string-length($WhiteSpaceInstartJobNotification1)>0) and (SpiJobStartNotification!='NULL_PTR') and (SpiJobStartNotification!='NULL')"!][!//
        &[!"SpiJobStartNotification"!][!//
[!ELSE!][!//
        NULL_PTR[!//
[!ENDIF!], /* Start Notification */
        (sint8)[!"SpiJobPriority"!], /* Priority */
        &Spi_aSpiJobState[[!"SpiJobId"!]], /* JobState instance */
        [!"node:value(node:ref(SpiDeviceAssignment)/SpiHwUnit)"!], /* HWUnit index */
[!VAR "varSpiHwUnit"="string(substring-after(node:value(node:ref(SpiDeviceAssignment)/SpiHwUnit),'CSIB')+1)"!][!//
        [!"node:value(concat($spiPath,'/SpiGeneral/SpiPhyUnit/*[',$varSpiHwUnit,']/SpiPhyUnitMapping'))"!]_OFFSET, /* DSPI device HW unit offset */
        /* External Device Settings */
        [!SELECT "node:ref(SpiDeviceAssignment)"!]
        [!WS "8"!]SPI_[!"name(.)"!], /* External Device */
        {
        [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitClockRef)"!][!//
        [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
        [!ENDSELECT!][!//
        [!VAR "BusClockNormal" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!IF "(node:exists(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef))"!][!//
        [!VAR "DualClockEnabled" = "'true'"!][!//
        [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef)"!][!//
        [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
        [!ENDSELECT!][!//
        [!VAR "BusClockAlternate" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!ELSE!][!//
        [!VAR "DualClockEnabled" = "'false'"!][!//
        [!ENDIF!][!//
        [!IF "SpiSlaveMode = 'false'"!]
        [!CALL "GenerateExternalDeviceInfo"!]
        [!ELSE!]
        [!CALL "GenerateSlaveDeviceInfo"!]
        [!ENDIF!][!//
        }
        [!ENDSELECT!]
    }[!IF "$idx!=$count"!],[!ENDIF!]
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//============Job Assignment of Sequences ==========================================================
[!MACRO "Spi_JobAssignmentOfSequences"!]
/* Job to Sequence Assignment */
[!LOOP "SpiDriver/SpiSequence/*"!][!//
static CONST(Spi_JobType, SPI_CONST) [!"name(.)"!]_JobAssignment_PB[[!"num:i(count(SpiJobAssignment/*))"!]] = {[!//
[!LOOP "SpiJobAssignment/*"!][!//
[!/* Check if reference node has the name "Job". We need to avoid the name "Job" */!][!//
[!/* driver shall run into problems if a name "Job" is founded */!][!//
[!IF "name(node:ref(.)) = 'Job'"!][!//
Job_default[!//
[!ELSE!][!//
[!IF "@index > 0"!],[!ENDIF!][!//
SpiConf_SpiJob_[!"name(node:ref(.))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
};
[!ENDLOOP!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==============Configuration of Sequences =========================================================
[!MACRO "Spi_SequenceConfiguration"!]
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiSequence/*)"!][!//
/* SpiSequenceConfig_PB[!"@index"!] Sequence Configuration of [!"name(.)"!]*/
static CONST(Spi_SequenceConfigType, SPI_CONST) SpiSequenceConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiSequence/*))"!][!//
[!LOOP "SpiDriver/SpiSequence/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiSequenceId = $Loop"!][!//
    {  /* [!"name(.)"!] */
[!VAR "WhiteSpaceInSeqEndNotification1"="normalize-space(SpiSeqEndNotification)"!]
        (Spi_JobType)[!"num:i(count(SpiJobAssignment/*))"!]u,
        &[!"name(.)"!]_JobAssignment_PB, /* List of Jobs */
[!IF "(string-length($WhiteSpaceInSeqEndNotification1)>0) and (SpiSeqEndNotification!='NULL_PTR') and (SpiSeqEndNotification!='NULL')"!][!//
        &[!"SpiSeqEndNotification"!][!//
[!ELSE!][!//
        NULL_PTR[!//
[!ENDIF!], /* End Notification */
        [!WS "8"!][!IF "SpiInterruptibleSequence"!](uint8)TRUE[!ELSE!](uint8)FALSE[!ENDIF!] /* Interruptible */
    }[!IF "$idx!=$count"!],[!ENDIF!]
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//===================Attribute Configuration of Channels ===========================================
[!MACRO "Spi_AttributeConfigurationOfChannels"!]
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiChannel/*)"!][!//
[!CODE!][!//
/* DspiChannelAttributesConfig_PB[!"@index"!] Channel Attribute Configuration of [!"name(.)"!]*/
static CONST(Spi_Ipw_ChannelAttributesConfigType, SPI_CONST) DspiChannelAttributesConfig_PB[!"@index"!][[!"num:i($count)"!]] =
{
[!ENDCODE!][!//
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiChannel/*))"!][!//
[!LOOP "SpiDriver/SpiChannel/*"!][!//
[!VAR "Loop"="num:i($LoopVar)"!][!//
[!IF "SpiChannelId = $Loop"!][!//
[!CODE!][!//
[!IF "num:i(SpiDataWidth) > 8"!][!//
    {(uint32)(DSPI_CMD_[!"SpiTransferStart"!]_U32 | DSPI_CMD_WIDTH_[!"SpiDataWidth"!]_U32),SPI_DATA_WIDTH_16}[!//
[!ELSE!][!//
    {(uint32)(DSPI_CMD_[!"SpiTransferStart"!]_U32 | DSPI_CMD_WIDTH_[!"SpiDataWidth"!]_U32),SPI_DATA_WIDTH_8}[!//
[!ENDIF!][!//
[!IF "$idx!=$count"!],[!ENDIF!][!//
[!ENDCODE!][!//
[!VAR "idx" = "$idx + 1"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!CR!][!ENDFOR!][!//
[!CODE!][!//
};
[!ENDCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================Attribute Configuration of External Devices ====================================
[!MACRO "Spi_AttributeConfigurationOfExternalDevices"!]
[!VAR "var"= "1"!][!VAR "deviceattribute"= "num:i(count(SpiDriver/SpiExternalDevice/*))-1"!][!//
/* DspiDeviceAttributesConfig_PB[!"@index"!] Device Attribute Configuration of [!"name(.)"!]*/
static CONST(Spi_Ipw_DeviceAttributesConfigType, SPI_CONST) DspiDeviceAttributesConfig_PB[!"@index"!][[!"num:i(count(SpiDriver/SpiExternalDevice/*))"!]] =
{
[!AUTOSPACING!][!LOOP "SpiDriver/SpiExternalDevice/*"!][!//
    {  /* [!"name(.)"!] */
        [!VAR "varSpiHwUnit"="string(substring-after(node:value(SpiHwUnit),'CSIB')+1)"!][!//
        [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitClockRef)"!][!//
        [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
        [!ENDSELECT!][!//
        [!VAR "BusClockNormal" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!IF "(node:exists(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef))"!][!//
        [!VAR "DualClockEnabled" = "'true'"!][!//
        [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef)"!][!//
        [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
        [!ENDSELECT!][!//
        [!VAR "BusClockAlternate" = "string($SpiPeriphFrequency div 1000000)"!][!//
        [!ELSE!]
        [!VAR "DualClockEnabled" = "'false'"!][!//
        [!ENDIF!][!//
        [!IF "SpiSlaveMode = 'false'"!]
        [!CALL "GenerateExternalDeviceInfo"!]
        [!ELSE!]
        [!CALL "GenerateSlaveDeviceInfo"!]
        [!ENDIF!]
    }[!IF "$deviceattribute>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
[!CR!][!ENDLOOP!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//=================Link to Attribute Configuration of Channels and Devices =========================
[!MACRO "Spi_LinkToAttributeConfiguration"!]
/* SpiAttributesConfig_PB[!"@index"!] Attribute Configuration of [!"@name"!] */
static CONST(Spi_AttributesConfigType, SPI_CONST) SpiAttributesConfig_PB[!"@index"!] = {
    &DspiChannelAttributesConfig_PB[!"@index"!],
    &DspiDeviceAttributesConfig_PB[!"@index"!]
};
[!ENDMACRO!][!//
[!//=================================================================================================
[!//
[!//=============Array of DSPI Unit configurations===================================================
[!MACRO "Spi_HWUnitConfiguration"!]
/* Array of DSPI Unit configurations */
static CONST(Spi_HWUnitConfigType, SPI_CONST) HWUnitConfig_PB[SPI_MAX_HWUNIT] =
{
[!VAR "var"= "1"!][!VAR "numdevices"= "num:i(count(SpiGeneral/SpiPhyUnit/*))-1"!][!//
[!AUTOSPACING!][!LOOP "SpiGeneral/SpiPhyUnit/*"!][!//
[!VAR "unit"="./SpiPhyUnitMapping"!][!//
[!FOR "x"="1" TO "ecu:get('SpiNumberOfUnits')"!][!//
[!IF "ecu:list('Spi.SpiGeneral.SpiPhyUnit.SpiPhyUnitMapping')[num:i($x)] = $unit"!][!//
[!VAR "unit_index" = "$x"!][!//
[!ENDIF!][!//
[!ENDFOR!][!//
[!VAR "unit_NrCTAR"="(ecu:list('Spi.SpiGeneral.SpiPhyUnit.NrCTAR'))[num:i($unit_index)]"!]
    { [!"SpiPhyUnitMapping"!]_OFFSET[!//
, (uint8)[!"$unit_NrCTAR"!]u[!//
[!IF "SpiPhyUnitMode = 'SPI_SLAVE'"!][!//
, (uint8)SPI_SLAVE [!//
[!ELSE!][!//
, (uint8)SPI_MASTER [!//
[!ENDIF!][!//
[!IF "SpiPhyUnitSync = 'true'"!][!//
, SPI_PHYUNIT_SYNC_U32[!//
[!IF "ecu:get('SpiDMAPresent') = 'TRUE' and ../../SpiGlobalDmaEnable = 'true' and ../../SpiLevelDelivered >0"!][!//
, (uint16)FALSE
, 0u
, 0u
, 0u
[!ENDIF!][!//
[!ELSE!][!//
, SPI_PHYUNIT_ASYNC_U32[!//
[!IF "ecu:get('SpiDMAPresent') = 'TRUE' and ../../SpiGlobalDmaEnable = 'true' and ../../SpiLevelDelivered >0"!][!//
[!IF "SpiPhyUnitAsyncMethod = 'DMA'"!][!//
, (uint16)TRUE
, [!"node:value(node:ref(SpiPhyTxDmaChannel)/MclDMAChannelId)"!]u
, [!"node:value(node:ref(SpiPhyTxDmaChannelAux)/MclDMAChannelId)"!]u
, [!"node:value(node:ref(SpiPhyRxDmaChannel)/MclDMAChannelId)"!]u
[!ELSE!][!//
, (uint16)FALSE
, 0u
, 0u
, 0u
[!ENDIF!][!//
[!ENDIF!][!//
[!ENDIF!][!//
 }[!IF "$numdevices>=$var"!],[!ENDIF!][!VAR "var"= "$var+1"!][!//
[!CR!][!ENDLOOP!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//==================Spi Configuration===============================================================
[!MACRO "Spi_ConfigurationInfo"!]
    [!NOCODE!]
    [!VAR "SpiDemErrorEnable" = "'false'"!]
    [!IF "SpiNonAUTOSAR/SpiDisableDemReportErrorStatus ='false'"!][!//
        [!IF "node:exists(SpiDemEventParameterRefs)"!]
            [!VAR "SpiDemErrorEnable" = "'true'"!]
        [!ENDIF!]
    [!ENDIF!]
    [!ENDNOCODE!]
/*
* @violates @ref Spi_PBcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 All declarations and definitions of objects or functions 
* at file scope shall have internal linkage unless external linkage is required.
*/
/* [!"@name"!] Configuration */
CONST(Spi_ConfigType, SPI_CONST) [!//
[!IF "(IMPLEMENTATION_CONFIG_VARIANT = 'VariantPreCompile' or IMPLEMENTATION_CONFIG_VARIANT='VariantLinkTime') and (variant:size() <= 1)"!]Spi_PBCfgVariantPredefined[!//
[!ELSE!][!"as:name(SpiDriver)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!][!ENDIF!] =
{
    [!"num:i(count(SpiDriver/SpiExternalDevice/*))"!]u,
    [!"num:i(num:i(count(SpiDriver/SpiChannel/*)) - 1)"!]u,
    [!"num:i(num:i(count(SpiDriver/SpiJob/*)) - 1)"!]u,
    [!"num:i(num:i(count(SpiDriver/SpiSequence/*)) - 1)"!]u,
    &SpiChannelConfig_PB[!"@index"!],
    &SpiJobConfig_PB[!"@index"!],
    &SpiSequenceConfig_PB[!"@index"!],
    &SpiAttributesConfig_PB[!"@index"!],
    &HWUnitConfig_PB
    /**
    * @brief   DEM error parameters
    */
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
[!IF "$SpiDemErrorEnable"!][!//
[!IF "node:exists(SpiDemEventParameterRefs/SPI_E_HARDWARE_ERROR)"!][!//
[!IF "node:exists(node:ref(SpiDemEventParameterRefs/SPI_E_HARDWARE_ERROR))"!][!//
    ,{ (uint32)STD_ON, (uint32)DemConf_DemEventParameter_[!"node:name(node:ref(SpiDemEventParameterRefs/SPI_E_HARDWARE_ERROR))"!]} /* SPI_E_HARDWARE_ERROR parameters*/ [!//
[!ELSE!][!//
    [!ERROR "Invalid reference for SPI_E_HARDWARE_ERROR"!][!//
[!ENDIF!][!//
[!ELSE!][!//
    ,{ (uint32)STD_OFF, (uint32)0U} /* SPI_E_HARDWARE_ERROR parameters*/[!//
[!ENDIF!][!// 
[!ELSE!][!//
    ,{ (uint32)STD_OFF, (uint32)0U}/* SPI_E_HARDWARE_ERROR parameters*/ [!//
[!ENDIF!][!CR!][!// 
#endif /* SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */  
[!IF "(node:value(SpiNonAUTOSAR/SpiTSBModeSupport) = 'true')"!][!//
#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
    ,Spi_aSpiJobTSBConfig
#endif
#endif
[!ENDIF!][!//
};
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//=================== Export Driver Configuration ===============================================================================
[!MACRO "Spi_ExportDriverConfiguration"!][!//
[!NOCODE!][!//
[!VAR "configName" = "as:name(SpiDriver)"!][!//
[!CODE!][!//
#define SPI_CONF_PB \
[!ENDCODE!][!//
[!IF "var:defined('postBuildVariant')"!][!//
    [!VAR "variantIndex"="0"!][!//
    [!VAR "variantNumber"="variant:size()"!][!//
    [!LOOP "variant:all()"!][!VAR "variantIndex"="$variantIndex + 1"!][!//
    [!//
        [!CODE!][!WS4!]extern CONST(Spi_ConfigType, SPI_CONST) [!"$configName"!]_[!"."!];[!IF "$variantIndex < $variantNumber"!]\[!ENDIF!][!CR!][!ENDCODE!]
    [!ENDLOOP!][!//
[!ELSE!][!//
    [!CODE!][!WS4!]extern CONST(Spi_ConfigType, SPI_CONST) [!"$configName"!];[!CR!][!ENDCODE!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!//
[!//=============== Configuration of TSBJobs =========================================================
[!MACRO "Spi_TSBJobConfiguration"!]
[!IF "(node:value(SpiNonAUTOSAR/SpiTSBModeSupport) = 'true')"!][!//
[!VAR "idx" = "1"!][!//
[!VAR "LoopVar"="0"!][!//
[!VAR "count" = "count(SpiDriver/SpiJob/*)"!][!//
[!VAR "TSBJobCount"="0"!][!//
[!LOOP "SpiDriver/SpiJob/*"!][!//
[!IF "TSBModeEnable = 'true'"!][!//
   [!VAR "TSBJobCount" = "$TSBJobCount +1"!] [!ENDIF!][!//
[!ENDLOOP!][!//
[!IF "$TSBJobCount=0"!]
  [!ERROR!] Atlease one TSBJob should be configured as SpiTSBModeSupport is enabled [!ENDERROR!]
[!ENDIF!]
/* SpiJobConfig_PB[!"@index"!] Job Configuration of [!"name(.)"!]*/
static CONST(Spi_TSBConfigType, SPI_CONST) Spi_aSpiJobTSBConfig[[!"num:i($TSBJobCount)"!]] =
{
[!VAR "Dualreceiver" = "0"!][!//
[!FOR "x" = "0" TO "num:i(count(SpiDriver/SpiJob/*))"!][!//
[!LOOP "SpiDriver/SpiJob/*"!][!//
    [!IF "TSBModeEnable = 'true'"!][!//
        [!VAR "Loop"="num:i($LoopVar)"!][!//
        [!IF "SpiJobId = $Loop"!]
        {
            (Spi_JobType)([!"SpiJobId"!]),  /*Normal Job Id*/
            {
                /*DSICR attributes*/
                (uint32)(DSPI_DSICR_CS_[!"DsiCsIdentifier"!]_U32
                [!IF "TransmitDataSource = 'DSISerializationRegister'"!]| DSPI_DSICR_TXSS_CLEAR_U32[!//
                [!ELSEIF "TransmitDataSource = 'DSIAltSerRegister'"!]| DSPI_DSICR_TXSS_SET_U32[!//
                [!ENDIF!]
                [!IF "ChangeInDataTransfer = 'true'"!]| DSPI_DSICR_CID_SET_U32
                [!ELSEIF "ChangeInDataTransfer = 'false'"!]| DSPI_DSICR_CID_CLEAR_U32
                [!ENDIF!] ),
                /*DSICR1 attributes*/
                (uint32)([!IF "DualReceiverSupport = 'true'"!]DSPI_DSICR1_CS_[!"SecondaryDsiCsIdentifier"!]_U32[!//
                [!ELSE!]DSPI_DUALRECEIVER_DISABLED_U32[!//
                [!ENDIF!]
                | DSPI_DSICR1_TSBCNT_[!"TSBFrameSize"!]_U32[!IF "TSBFrameSize > 31"!] | DSPI_DSICR1_DSI64E_MASK_U32[!ELSE!][!ENDIF!]
                ),
                [!NOCODE!]
                ([!IF "DualReceiverSupport = 'true'"!]
                [!VAR "Dualreceiver" = "SecondaryFrameSize"!][!//
                [!ELSE!]
                [!VAR "Dualreceiver" = "0"!][!//
                [!ENDIF!])
                [!ENDNOCODE!]
                /*CTAR2 attributes*/ /* External Device Settings */
                [!VAR "varSpiHwUnit"="string(substring-after(node:value(node:ref(SpiDeviceAssignment)/SpiHwUnit),'CSIB')+1)"!][!//
                [!SELECT "node:ref(SpiDeviceAssignment)"!][!//
                [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitClockRef)"!][!//
                [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
                [!ENDSELECT!][!//
                [!VAR "BusClockNormal" = "string($SpiPeriphFrequency div 1000000)"!][!//
                [!IF "(node:exists(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef))"!][!//
                [!VAR "DualClockEnabled" = "'true'"!][!//
                [!SELECT "node:ref(../../../SpiGeneral/SpiPhyUnit/*[number($varSpiHwUnit)]/SpiPhyUnitAlternateClockRef)"!][!//
                [!VAR "SpiPeriphFrequency" = "McuClockReferencePointFrequency"!][!//
                [!ENDSELECT!][!//
                [!VAR "BusClockAlternate" = "string($SpiPeriphFrequency div 1000000)"!][!//
                [!ELSE!][!//
                [!VAR "DualClockEnabled" = "'false'"!][!//
                [!ENDIF!][!//
                [!CALL "GenerateTSBExternalDeviceInfo"!][!//
                [!ENDSELECT!][!//
                [!IF "(node:value(../../../SpiNonAUTOSAR/SpiITSBModeSupport) = 'true' ) and (ecu:get('SpiITSBSupport')='TRUE')"!][!//
                [!IF "ITSBModeEnable = 'true'"!]
                ,
                /*ITSB mode enable*/
                (boolean)TRUE,[!//
                [!IF "ecu:get('SpiITSBTimeSlotSupport') = 'TRUE'"!]
                /*TSL attributes*/
                [!CALL "GenerateTSLValue"!][!//
                /*TS_CONF attributes*/
                (uint32)(DSPI_TS_CONF_TS3_[!"TS3_CONF"!]_U32 | DSPI_TS_CONF_TS2_[!"TS2_CONF"!]_U32 | DSPI_TS_CONF_TS1_[!"TS1_CONF"!]_U32 | DSPI_TS_CONF_TS0_[!"TS0_CONF"!]_U32)
                [!ENDIF!][!//
                [!ELSE!][!CR!]
                ,
                (boolean)FALSE,
                [!IF "ecu:get('SpiITSBTimeSlotSupport') = 'TRUE'"!]
                /*TSL attributes*/
                (uint32)0U,
                (uint32)0U       
                [!ENDIF!][!//
                [!ENDIF!][!//
                [!ENDIF!]
            }
        }[!IF "$idx!=$TSBJobCount"!],[!CR!][!ELSE!][!ENDIF!]
        [!VAR "idx" = "$idx + 1"!][!//
        [!ENDIF!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//
[!VAR "LoopVar"="$LoopVar + 1"!][!//
[!ENDFOR!][!//
[!CR!]};
[!ENDIF!][!//
[!ENDMACRO!][!//
[!//==================================================================================================
[!ENDNOCODE!][!//

