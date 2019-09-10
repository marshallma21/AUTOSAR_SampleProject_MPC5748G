[!NOCODE!][!//
/**
  @file    Fr_SpecChecks.m
  @version 1.0.0

  @brief   AUTOSAR Fr - plugin check.
  @details FlexRay Protocol specification checks.
  
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
[!IF "not(var:defined('FR_FRSPECCHECKS_M'))"!][!//
[!/* This macro checks whether the configuration is according to the FlexRay specification 2.1A */!][!//
[!/* Errors reported here use different numbering schema than the rest of errors */!][!//
[!MACRO "SpecChecks", "FrIfCluster" = "", "FrController" = ""!][!//
  [!/* Check the length of gdNit with respect to other parts of the cycle */!][!//
  [!VAR "MacDynamicSegmentLength" = "number(node:ref($FrIfCluster)/FrIfGdMinislot) * number(node:ref($FrIfCluster)/FrIfGNumberOfMinislots)"!][!//
  [!VAR "MacStaticSegmentLength" = "number(node:ref($FrIfCluster)/FrIfGdStaticSlot) * number(node:ref($FrIfCluster)/FrIfGNumberOfStaticSlots)"!][!//
  [!VAR "MacComputedNitLength" = "number(node:ref($FrIfCluster)/FrIfGMacroPerCycle) - number(node:ref($FrIfCluster)/FrIfGdSymbolWindow) - $MacDynamicSegmentLength - $MacStaticSegmentLength"!]
  [!IF "$MacComputedNitLength != number(node:ref($FrIfCluster)/FrIfGdNit)"!]
    [!ERROR!]Error 800: The length of gdNit must be equal to gMacroPerCycle - gdSymbolWindow - (gNumberOfStaticSlots * gdStaticSlot) - (gNumberOfMinislots * gdMinislot) = [!"num:i($MacComputedNitLength)"!].[!ENDERROR!][!//
  [!ENDIF!]
[!ENDMACRO!]
[!ENDIF!][!//
[!ENDNOCODE!][!//
