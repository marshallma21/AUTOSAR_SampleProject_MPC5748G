[!NOCODE!][!//
/**
  @file    Fr_DeviceMacros.m
  @version 1.0.0

  @brief   AUTOSAR Fr - plugin check.
  @details Fr driver device specific defines
  
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
[!WS "0"!][!/* Multiple inclusion protection */!][!//
[!IF "not(var:defined('FR_DEVICEMACROS_M'))"!][!//
  [!/* Size of the header area of the message buffer in the memory in bytes: */!][!//
  [!VAR "MBHeaderLength" = "8"!][!//
  [!/* Number of available FlexRay Controllers on the device: */!][!//
  [!VAR "AvailableControllers" = "1"!][!//
  [!/* Number of available message buffers on the device: */!][!//
  [!VAR "AvailableBuffers" = "128"!][!//
  [!/* Add support IpV version 9: */!][!//
  [!VAR "SupportIpv9" = "'false'"!][!//
[!ENDIF!][!//
[!ENDNOCODE!][!//