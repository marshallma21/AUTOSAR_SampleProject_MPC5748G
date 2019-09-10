[!NOCODE!][!//
/**
  @file    CDD_Mcl_Cfg_h_checks.m
  @version 1.0.0

  @brief   AUTOSAR Mcl - version check macro.
  @details Version checks.
  
  Project AUTOSAR 4.2 MCAL
  Patform PA
  Peripheral eDMA
  Dependencies none
  
  ARVersion 4.2.2
  ARRevision ASR_REL_4_2_REV_0002
  ARConfVariant
  SWVersion 1.0.0
  BuildVersion MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217

  c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
  All Rights Reserved.
*/
/*==================================================================================================

[!VAR "MclSwMajorVersionTemplate"="1"!][!//     
[!VAR "MclSwMinorVersionTemplate"="0"!][!//     

[!ENDNOCODE!][!//
[!SELECT "CommonPublishedInformation"!][!//
    [!IF "not(num:i(SwMajorVersion) = num:i($MclSwMajorVersionTemplate))"!]
        [!ERROR!]
            "The software major number of the Basic Software Module Description file (Mcl.epd version [!"SwMajorVersion"!]) and the Code template file (CDD_Mcl_Cfg.h version [!"num:i($MclSwMajorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!]
    [!IF "not(num:i(SwMinorVersion) = num:i($MclSwMinorVersionTemplate))"!]
        [!ERROR!]
            "The software minor number of the Basic Software Module Description file (Mcl.epd version [!"SwMinorVersion"!]) and the Code template file (CDD_Mcl_Cfg.h version [!"num:i($MclSwMinorVersionTemplate)"!]) are different"
        [!ENDERROR!]
    [!ENDIF!]
[!ENDSELECT!][!//
[!NOCODE!][!//

[!ENDNOCODE!][!//
