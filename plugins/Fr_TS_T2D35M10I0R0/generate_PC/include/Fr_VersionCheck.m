[!NOCODE!][!//
/**
  @file    Fr_VersionCheck.m
  @version 1.0.0

  @brief   AUTOSAR Fr - plugin check.
  @details Fr plugin generation templates version checks
  
  Project AUTOSAR 4.2 MCAL
  Patform PA
  Peripheral FLEXRAY
  Dependencies 
  
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
[!WS "0"!][!/* *** multiple inclusion protection *** */!][!//
[!IF "not(var:defined('FR_VERSIONCHECKMACROS_M'))"!][!//
  [!VAR "FR_VERSIONCHECKMACROS_M"="'true'"!][!//
  [!VAR "FR_AR_MAJOR_VERSION_TEMPLATE"="4"!][!//
  [!VAR "FR_AR_MINOR_VERSION_TEMPLATE"="2"!][!//
  [!VAR "FR_AR_PATCH_VERSION_TEMPLATE"="2"!][!//
  [!VAR "FR_SW_MAJOR_VERSION_TEMPLATE"="1"!][!//
  [!VAR "FR_SW_MINOR_VERSION_TEMPLATE"="0"!][!//
  [!VAR "FR_SW_PATCH_VERSION_TEMPLATE"="0"!][!//
  [!VAR "FR_VENDOR_ID_TEMPLATE"="43"!][!//
  [!VAR "FR_MODULE_ID_TEMPLATE"="81"!][!//
  [!SELECT "CommonPublishedInformation"!][!//
  [!IF "num:i(ArReleaseMajorVersion) != num:i($FR_AR_MAJOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
      [!WS "0"!]Error TBD: AUTOSAR major version number of the Basic Software Module Description file ([!"ArReleaseMajorVersion"!]) and the Code Template files ([!"num:i($FR_AR_MAJOR_VERSION_TEMPLATE)"!]) are different.
    [!ENDERROR!]
  [!ENDIF!][!//
  [!IF "num:i(ArReleaseMinorVersion) != num:i($FR_AR_MINOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
      [!WS "0"!]Error TBD: AUTOSAR minor version number of the Basic Software Module Description file ([!"ArReleaseMajorVersion"!]) and  Code Template files ([!"num:i($FR_AR_MINOR_VERSION_TEMPLATE)"!]) are different.
    [!ENDERROR!]
  [!ENDIF!][!//
  [!IF "num:i(ArReleaseRevisionVersion) != num:i($FR_AR_PATCH_VERSION_TEMPLATE)"!]
    [!ERROR!]
      [!WS "0"!]Error TBD: AUTOSAR release revision version numbers of the Basic Software Module Description file ([!"ArReleaseRevisionVersion"!]) and the Code Template files version ([!"num:i($FR_AR_PATCH_VERSION_TEMPLATE)"!]) are different.
    [!ENDERROR!]
  [!ENDIF!][!//
  [!IF "num:i(SwMajorVersion) != num:i($FR_SW_MAJOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
       [!WS "0"!]Error TBD: The software major number of the Basic Software Module Description file ([!"SwMajorVersion"!]) and the Code Template files (FR_cfg.h version [!"num:i($FR_SW_MAJOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
  [!ENDIF!][!//
  [!IF "num:i(SwMinorVersion) != num:i($FR_SW_MINOR_VERSION_TEMPLATE)"!]
    [!ERROR!]
      [!WS "0"!]Error TBD: The software minor number of the Basic Software Module Description file ([!"SwMinorVersion"!]) and the Code Template files (FR_cfg.h version [!"num:i($FR_SW_MINOR_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
  [!ENDIF!][!//
  [!IF "num:i(SwPatchVersion) != num:i($FR_SW_PATCH_VERSION_TEMPLATE)"!]
    [!ERROR!]
      [!WS "0"!]Error TBD:  The software patch number of the Basic Software Module Description file ([!"SwPatchVersion"!]) and the Code Template files (FR_cfg.h version [!"num:i($FR_SW_PATCH_VERSION_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
  [!ENDIF!][!//
  [!IF "num:i(VendorId) != num:i($FR_VENDOR_ID_TEMPLATE)"!]
    [!ERROR!]
      [!WS "0"!]Error TBD: The vendor ID of the Basic Software Module Description file ([!"VendorId"!]) and the Code Template files (FR_cfg.h vendor ID [!"num:i($FR_VENDOR_ID_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
  [!ENDIF!][!//
  [!IF "num:i(ModuleId) != num:i($FR_MODULE_ID_TEMPLATE)"!]
    [!ERROR!]
      [!WS "0"!]Error TBD: The module ID of the Basic Software Module Description file ([!"ModuleId"!]) and the Code Template files ([!"num:i($FR_MODULE_ID_TEMPLATE)"!]) are different ****
    [!ENDERROR!]
  [!ENDIF!][!//
  [!ENDSELECT!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//
