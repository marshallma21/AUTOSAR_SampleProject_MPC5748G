/**
*   @file    Can_PBcfg.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Can - module interface
*   @details Configuration Structures for PostBuild.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : FLEXCAN
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

#ifdef __cplusplus
extern "C"{
#endif

/**
*
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and 
* external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Can_PBcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,#include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_PBcfg_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Can_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*
*/

/*
   (CAN078) The code file structure shall not be defined within this specification completely.
            At this point it shall be pointed out that the code-file structure shall include the following file named: Can_PBcfg.c.
            This file shall contain all post-build time configurable parameters.
   (CAN221) VariantPB: (Mix of precompile and Post Build multiple selectable configurable configurations.
*/
/**
* @file           Can_PBcfg.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Can.h"
#include "Can_IPW.h"

[!AUTOSPACING!]
[!NOCODE!]
/*
 Example 1 of valid configuration:
   Source Clock = 8MHz, Bit Rate = 1Mb/sec,
   CanControllerTimeQuanta  = 125ns
      -> Presclaer = 1, CanBit = 8Tq (these ale calculated in background)
   CanControllerPropSeg  = 3, CanControllerSeg1 = 0, CanControllerSeg2 = 1, CanControllerSyncJumpWidth = 0.

 Example 2 of valid configuration:
   Source Clock = 8MHz, Bit Rate = 125Kb/sec,
   CanControllerTimeQuanta  = 1000ns,
      -> Presclaer = 8, CanBit = 8Tq (these ale calculated in background)
   CanControllerPropSeg  = 0, CanControllerSeg1 = 2, CanControllerSeg2 = 2, CanControllerSyncJumpWidth = 2.
*/
[!ENDNOCODE!][!//
[!//
[!NOCODE!][!//
[!INCLUDE "Can_VersionCheck_Src_PB.m"!][!//
[!ENDNOCODE!][!//
[!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/*
* @file           Can_PBcfg.c
*/
#define CAN_VENDOR_ID_PBCFG_C                   43
#define CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
#define CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C     2
/* @violates @ref Can_PBcfg_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C  2
#define CAN_SW_MAJOR_VERSION_PBCFG_C             1
#define CAN_SW_MINOR_VERSION_PBCFG_C             0
#define CAN_SW_PATCH_VERSION_PBCFG_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Can configuration header file are of the same vendor */
#if (CAN_VENDOR_ID_PBCFG_C != CAN_VENDOR_ID)
#error "Can.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_AR_RELEASE_REVISION_VERSION))
  #error "AutoSar Version Numbers of Can_PBcfg.c and Can.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_SW_PATCH_VERSION))
       #error "Software Version Numbers of Can_PBcfg.c and Can.h are different"
#endif

/* Check if current file and Can_IPW configuration header file are of the same vendor */
#if (CAN_VENDOR_ID_PBCFG_C  != CAN_IPW_VENDOR_ID_H)
#error "Can.h and Can_Cfg.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
  #error "AutoSar Version Numbers of Can_PBcfg.c and Can_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_IPW_SW_PATCH_VERSION_H))
       #error "Software Version Numbers of Can_PBcfg.c and Can_IPW.h are different"
#endif

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#define CAN_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"

/**
@brief    Prototype of User Notifications
*/
[!NOCODE!][!INCLUDE "Can_NotifyCheck_Src_PB.m"!][!ENDNOCODE!][!//
[!NOCODE!][!INCLUDE "Can_SourceClock.m"!][!ENDNOCODE!][!//
[!NOCODE!][!CALL "CanRxFifoWarningNotification_PB"!][!ENDNOCODE!][!//
[!NOCODE!][!CALL "CanRxFifoOverflowNotification_PB"!][!ENDNOCODE!][!//
[!NOCODE!][!CALL "CanErrorControllerNotification_PB"!][!ENDNOCODE!][!//

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

[!NOCODE!]
[!VAR "LoopVar"="0"!]
[!SELECT "CanConfigSet"!]
    [!VAR "HOHCount" = "num:i(count(CanHardwareObject/*))"!]
    [!VAR "additionalHTH" = "0"!]
    [!IF "(../CanGeneral/CanMultiplexedTransmission = 'true')"!]
        [!LOOP "CanHardwareObject/*"!]
            [!IF "(CanObjectType = 'TRANSMIT') and (node:value(CanHwObjectCount) > 1 )"!]
                [!VAR "additionalHTH" = "$additionalHTH + node:value(CanHwObjectCount) - 1 "!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
[!ENDSELECT!]
[!VAR "MaxConfiguredMBs" = "num:i($additionalHTH + $HOHCount)"!]
[!IF "$MaxConfiguredMBs > num:i(ecu:get('Can.CanConfigSet.CanMB'))"!]
    [!ERROR!] Maximum configured MBs exceed [!"ecu:get('Can.CanConfigSet.CanMB')"!] space [!ENDERROR!]
[!ENDIF!]
[!ENDNOCODE!]

#define CAN_MAXMBCOUNT_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]  [!WS!][!"$MaxConfiguredMBs"!]U[!CR!]

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
[!/* This section is for global variables, local to this file */!][!//
[!VAR "Tsyncsegment" = "1"!][!/* Sync_seg has 1 Tq length */!][!//
[!NOCODE!][!//
[!/*
    Sync-seg = is the segment that is used to synchronise the nodes on the bus. A bit edge (if there is a data change) is expected during this segment.
    Prop-Seg = is a period of time that is used to compensate for physical delay times within the network.
    Phase-seg1 = is a buffer segment that may be lengthened during resynchronisation to compensate for oscillator drift and positive phase differences between the oscillators of the transmitting and receiving node(s).
    Phase-seg2 = is a buffer segment that may be shortened during resynchronisation (described below) to compensate for negative phase errors and oscillator drift.

    The Sample point is always at the end of Phase-seg1 and is the time at which the bus level is read and interpreted as the value of the current bit.
    Whether transmitting or receiving, all nodes on a single CAN bus must have the same nominal bit time. Bit time is programmable at each node on a CAN Bus and is a function
        of the period of the oscillator local to each node, the value that is user-programmed into a Baud Rate Prescaler (BRP) register in the controller at each node, and the programmed number of time quanta per bit.
    When any node receives a data frame or a remote frame, it is necessary for the receiver to synchronise with the transmitter.
        1. The first is hard synchronisation and occurs at Start-of-Frame (SOF).
        2. For subsequent bits in any received frame, if a bit edge does not occur in the Sync-seg segment of bit time, resynchronisation is automatically invoked and will shorten or lengthen the current bit time depending
            on where the edge occurs. The maximum amount by which the bit time is lengthened or shortened is determined by a user-programmable number of time quanta known as the Synchronisation Jump Width (SJW).
*/!]
[!ENDNOCODE!][!//
[!VAR "LoopVar"="0"!][!//
[!SELECT "CanConfigSet"!][!//
    [!VAR "TableIdCount" = "0"!][!//
    [!LOOP "CanController/*"!][!//
        [!IF "CanControllerRxFifoEnable = 'true'"!][!//
            [!VAR "TableIdCount" = "$TableIdCount+num:i(substring-after(./CanRxFifo/CanRxFifoFiltersNumber,'FILTERS_NUMBER_'))"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!IF "$TableIdCount != 0"!][!//
        [!WS "0"!]#if (CAN_RXFIFO_ENABLE == STD_ON)
        [!WS "0"!]/**
        [!WS "0"!]* @brief        Can_RxFiFoTableIdConfigType
        [!WS "0"!]* @details      Identifier FormatA:
        [!WS "0"!]*                   - StandardID: bits [29:19]
        [!WS "0"!]*                   - ExtendedID: bits [29:1]
        [!WS "0"!]*               Identifier FormatB:
        [!WS "0"!]*                   - StandardID: bits [29:19] & [13:3]
        [!WS "0"!]*                   - ExtendedID: bits [29:16] & [13:0] (only 14 MSB)
        [!WS "0"!]*               Identifier FormatC:
        [!WS "0"!]*                   - StandardID: bits [31::24] & [23:16] & [15:8] & [7:0] (only 8 MSB)
        [!WS "0"!]*                   - ExtendedID: bits [31::24] & [23:16] & [15:8] & [7:0] (only 8 MSB)
        [!WS "0"!]*
        [!WS "0"!]*/
        [!WS "0"!]static CONST(Can_RxFiFoTableIdConfigType, CAN_CONST) RxFifoTableID_PBConfig0[CAN_MAXTABLEID_0] =
        [!WS "0"!]{
        [!VAR "TableIdCountLocal" = "0"!][!//
        [!LOOP "CanController/*"!][!//
            [!VAR "ControllerCanHwChannel" = "CanHwChannel"!][!//
            [!IF "CanControllerRxFifoEnable = 'true'"!][!//
            [!VAR "tableidvalue" = "0"!][!//
                [!LOOP "CanRxFifo/CanRxFifoTable/*"!][!//
                    [!VAR "TableIdCountLocal" = "$TableIdCountLocal+1"!][!//
                    [!IF "../../CanControllerIDAcceptanceMode = 'D'"!][!//
                        [!VAR "tableidvalue" = "0"!][!//
                    [!ELSE!][!//
                        [!VAR "tableidvalue" = "num:i(CanIDValue0)"!][!//
                    [!ENDIF!][!//
                    [!VAR "tablefiltermaskvalue" = "num:i(CanMBFilterMaskValue)"!][!//
                    [!IF "../../CanControllerIDAcceptanceMode = 'C'"!][!//
                        [!VAR "tableidvalue0" = "bit:shl($tableidvalue,24)"!][!//
                        [!VAR "tableidvalue1" = "bit:shl(num:i(CanIDValue1),16)"!][!//
                        [!VAR "tableidvalue2" = "bit:shl(num:i(CanIDValue2),8)"!][!//
                        [!VAR "tableidvalue3" = "bit:shl(num:i(CanIDValue3),0)"!][!//
                        [!VAR "tableidvalue" = "bit:or($tableidvalue0,$tableidvalue1)"!][!//
                        [!VAR "tableidvalue" = "bit:or($tableidvalue,$tableidvalue2)"!][!//
                        [!VAR "tableidvalue" = "bit:or($tableidvalue,$tableidvalue3)"!][!//
                    [!ELSEIF "CanTableIDType = 'Standard'"!][!//
                        [!IF "../../CanControllerIDAcceptanceMode = 'A'"!][!//
                            [!VAR "tableidvalue" = "bit:shl($tableidvalue,19)"!][!//
                            [!VAR "tablefiltermaskvalue" = "bit:shl($tablefiltermaskvalue,19)"!][!//
                            [!VAR "tablefiltermaskvalue" = "bit:or($tablefiltermaskvalue,num:hextoint('0xc0000000'))"!][!//
                        [!ENDIF!][!//
                        [!IF "../../CanControllerIDAcceptanceMode = 'B'"!][!//
                            [!VAR "tableidvalue0" = "bit:shl($tableidvalue,19)"!][!//
                            [!VAR "tableidvalue1" = "bit:shl(num:i(CanIDValue1),3)"!][!//
                            [!VAR "tableidvalue" = "bit:or($tableidvalue0,$tableidvalue1)"!][!//
                            [!VAR "tablefiltermaskvalue0" = "bit:and($tablefiltermaskvalue,num:hextoint('0x3ff800'))"!][!//
                            [!VAR "tablefiltermaskvalue1" = "bit:and($tablefiltermaskvalue,num:hextoint('0x7ff'))"!][!//
                            [!VAR "tablefiltermaskvalue0" = "bit:shl($tablefiltermaskvalue0,8)"!][!//
                            [!VAR "tablefiltermaskvalue1" = "bit:shl($tablefiltermaskvalue1,3)"!][!//
                            [!VAR "tablefiltermaskvalue" = "bit:or($tablefiltermaskvalue0,$tablefiltermaskvalue1)"!][!//
                            [!VAR "tablefiltermaskvalue" = "bit:or($tablefiltermaskvalue,num:hextoint('0xc000c000'))"!][!//
                        [!ENDIF!][!//
                    [!ELSE!][!//
                        [!IF "../../CanControllerIDAcceptanceMode = 'A'"!][!//
                            [!VAR "tableidvalue" = "bit:shl($tableidvalue,1)"!][!//
                            [!VAR "tableidvalue" = "bit:bitset($tableidvalue,30)"!][!//
                            [!VAR "tablefiltermaskvalue" = "bit:shl($tablefiltermaskvalue,1)"!][!//
                            [!VAR "tablefiltermaskvalue" = "bit:or($tablefiltermaskvalue,num:hextoint('0xc0000000'))"!][!//
                        [!ENDIF!][!//
                        [!IF "../../CanControllerIDAcceptanceMode = 'B'"!][!//
                            [!VAR "tableidvalue0" = "bit:shl($tableidvalue,16)"!][!//
                            [!VAR "tableidvalue" = "bit:or($tableidvalue0,num:i(CanIDValue1))"!][!//
                            [!VAR "tableidvalue" = "bit:bitset($tableidvalue,30)"!][!//
                            [!VAR "tableidvalue" = "bit:bitset($tableidvalue,14)"!][!//
                            [!VAR "tablefiltermaskvalue0" = "bit:and($tablefiltermaskvalue,num:hextoint('0xfffc000'))"!][!//
                            [!VAR "tablefiltermaskvalue1" = "bit:and($tablefiltermaskvalue,num:hextoint('0x3fff'))"!][!//
                            [!VAR "tablefiltermaskvalue0" = "bit:shl($tablefiltermaskvalue0,2)"!][!//
                            [!VAR "tablefiltermaskvalue" = "bit:or($tablefiltermaskvalue0,$tablefiltermaskvalue1)"!][!//
                            [!VAR "tablefiltermaskvalue" = "bit:or($tablefiltermaskvalue,num:hextoint('0xc000c000'))"!][!//
                        [!ENDIF!][!//
                    [!ENDIF!][!//
                    [!WS "4"!]{
                    [!WS "4"!]    (uint32)[!"num:inttohex($tableidvalue,8)"!]U, /* [!"@name"!] of [!IF "../../CanControllerIDAcceptanceMode != 'C'"!]type [!"(CanTableIDType)"!] and[!ENDIF!] format[!"../../CanControllerIDAcceptanceMode"!] for [!"$ControllerCanHwChannel"!] */
                    [!WS "4"!]    (uint32)[!"num:inttohex($tablefiltermaskvalue,8)"!]U  /* Filter Mask (correspond to RXIMR register) */
                    [!WS "4"!]}[!IF "$TableIdCount != $TableIdCountLocal"!],[!ENDIF!][!CR!]
                [!ENDLOOP!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        [!WS "0"!]};
        [!WS "0"!]#endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
    [!ENDIF!][!//
    [!VAR "LoopVar"="0"!][!//
[!ENDSELECT!][!//

/*==================================================================================================*/
/**
* @brief          Filter Masks
* @details        Filter Masks
*
*/
/*==================================================================================================*/
[!SELECT "CanConfigSet"!]
    [!VAR "CSET_NR" = "num:i(0)"!]
    [!WS "0"!]static CONST(Can_IdType, CAN_CONST) Can_FilterMasks[!"$CSET_NR"!]_PB[CAN_MAXFILTERCOUNT_[!"$CSET_NR"!]] =
    [!WS "0"!]{
    [!VAR "filtermaskcount" = "0"!]
    [!VAR "MASK_COUNT"="num:i(count(CanHardwareObject/*/CanHwFilter/CanHwFilterMask))"!]
    [!VAR "END_COMMA"="0"!]
    [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!] 
       [!SELECT "CanHwFilter"!]
           [!VAR "END_COMMA"="$END_COMMA + 1"!]
           [!WS "4"!](Can_IdType)[!"num:inttohex(CanHwFilterMask)"!]U[!//
           [!IF "$END_COMMA < $MASK_COUNT"!],[!ELSE!][!WS "1"!][!ENDIF!] /* FilterMasks0[[!"num:i($filtermaskcount)"!]], "[!"@name"!]" */
           [!VAR "filtermaskcount" = "$filtermaskcount + 1"!]
      [!ENDSELECT!]
    [!ENDLOOP!]
    [!WS "0"!]};
[!ENDSELECT!]

[!NOCODE!]
[!/*==================================================================================================*/!]
[!VAR "ARBITRATION_LENGTH" = "8"!]
[!VAR "CAN_REGION_LENGTH" = "512"!]
[!VAR "MBOffsetAddr" = "0"!]

[!VAR "Can_NextMBBlockAddr" = "'0x0080 0x0080 0x0080 0x0080 0x0080 0x0080 0x0080 0x0080#0x0280 0x0280 0x0280 0x0280 0x0280 0x0280 0x0280 0x0280#0x0480 0x0480 0x0480 0x0480 0x0480 0x0480 0x0480 0x0480'"!]
[!MACRO "GetMBOffsetAddr_separate", "Controller" = "0", "RamBlock" = "0", "PayloadLength" = "8"!]
    [!VAR "strBlockBefore" = "substring($Can_NextMBBlockAddr, 1, num:i($RamBlock * 7 * 8))"!]
    [!VAR "strBlockAfter"  = "substring($Can_NextMBBlockAddr, num:i(($RamBlock+1) * 7 * 8))"!]
    [!VAR "targetBlockAddr" = "text:split($Can_NextMBBlockAddr, '#')[position()-1 = $RamBlock]"!]
    [!VAR "strBefore" = "substring($targetBlockAddr, 1, num:i($Controller * 7))"!]
    [!VAR "strAfter"  = "substring($targetBlockAddr, num:i(($Controller+1) * 7))"!]
    [!VAR "MBOffsetAddr" = "text:split($targetBlockAddr)[position()-1 = $Controller]"!]
    [!VAR "BlockMaxAddr" = "num:i((num:hextoint('0x80') + (($RamBlock + 1) * $CAN_REGION_LENGTH ) - 1))"!]
    [!VAR "avaiableRegionRemain" = "$CAN_REGION_LENGTH - num:i(num:mod((num:hextoint($MBOffsetAddr) - num:hextoint('0x80')), $CAN_REGION_LENGTH))"!]
    [!IF "($avaiableRegionRemain < num:i($ARBITRATION_LENGTH + $PayloadLength)) or (num:hextoint($MBOffsetAddr) > $BlockMaxAddr)"!]
        [!ERROR!] 
            Exceed MBs configured for Ram Block [!"num:i($RamBlock)"!] of Can Controller [!"num:i($Controller)"!] with Play load length = [!"num:i($PayloadLength)"!].
        [!ENDERROR!]
    [!ENDIF!]
    [!VAR "targetAddr" = "num:hextoint($MBOffsetAddr)"!]
    [!VAR "targetAddr" = "num:inttohex(num:i($targetAddr + $ARBITRATION_LENGTH + $PayloadLength), 4)"!]
    [!VAR "targetBlockAddr" = "concat($strBefore, $targetAddr, $strAfter)"!]
    [!VAR "Can_NextMBBlockAddr" = "concat($strBlockBefore, $targetBlockAddr, $strBlockAfter)"!]
[!ENDMACRO!]

[!VAR "Can_NextMBAddr" = "'0x0080 0x0080 0x0080 0x0080 0x0080 0x0080 0x0080 0x0080'"!]
[!MACRO "GetMBOffsetAddr_normal","Controller" = "0", "PayloadLength" = "8"!]
    [!VAR "strBefore" = "substring($Can_NextMBAddr, 1, num:i($Controller * 7))"!]
    [!VAR "strAfter"  = "substring($Can_NextMBAddr, num:i(($Controller+1) * 7))"!]
    [!VAR "MBOffsetAddr" = "text:split($Can_NextMBAddr)[position()-1 = $Controller]"!]
    [!VAR "targetAddr" = "num:hextoint($MBOffsetAddr)"!]
    [!VAR "targetAddr" = "num:i($targetAddr + $ARBITRATION_LENGTH + $PayloadLength)"!]
    [!IF "($MBOffsetAddr > num:hextoint('0x680')) or (($targetAddr - 1) > num:hextoint('0x680'))"!]
        [!ERROR!] 
            Exceed MBs with Play load length = [!"num:i($PayloadLength)"!] configured for Can Controller [!"num:i($Controller)"!] .
        [!ENDERROR!]
    [!ENDIF!]
    [!VAR "avaiableRegionRemain" = "$CAN_REGION_LENGTH - num:i(num:mod(($targetAddr - num:hextoint('0x80')), $CAN_REGION_LENGTH))"!]
    [!IF "$avaiableRegionRemain < num:i($ARBITRATION_LENGTH + $PayloadLength)"!]
        [!VAR "targetAddr" = "$targetAddr + $avaiableRegionRemain"!]
    [!ENDIF!]
    [!VAR "targetAddr" = "num:inttohex($targetAddr,4)"!]
    [!VAR "Can_NextMBAddr" = "concat($strBefore, $targetAddr, $strAfter)"!]
[!ENDMACRO!]

[!/*==================================================================================================*/!]
[!SELECT "CanConfigSet"!]
    [!VAR "Can_MBsPerBlockTable" = "''"!]
    [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!]
        [!IF "CanControllerId > 0"!]
            [!VAR "Can_MBsPerBlockTable" = "concat($Can_MBsPerBlockTable, '#')"!]
        [!ENDIF!]
        [!IF "(ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON') and (node:exists('CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig'))"!]
            [!IF "../../../CanGeneral/CanSpecifiedRAMBlockSize"!]
                [!FOR "i" = "0" TO "2"!]
                    [!VAR "MBsPerBlock" = "'32'"!]
                    [!LOOP "node:order(CanRAMBlock/*, 'CanRAMBlockName')"!]
                        [!IF "CanRAMBlockName = concat('CAN_RAM_BLOCK_', num:i($i))"!]
                            [!VAR "payload" = "text:split(CanRAMBlockSizeValue, '_')[position() - 1 = 1]"!]
                            [!VAR "MBsPerBlock" = "num:i(num:i('512') div num:i($ARBITRATION_LENGTH + $payload))"!]
                        [!ENDIF!]
                    [!ENDLOOP!]
                    [!VAR "Can_MBsPerBlockTable" = "concat($Can_MBsPerBlockTable, $MBsPerBlock)"!]
                    [!IF "$i < 2"!]
                        [!VAR "Can_MBsPerBlockTable" = "concat($Can_MBsPerBlockTable, ' ')"!]
                    [!ENDIF!]
                [!ENDFOR!]
            [!ELSE!]
                [!VAR "payload" = "text:split(../../../CanGeneral/MBDSR,'_')[position() - 1 = 1]"!]
                [!VAR "MBsPerBlock" = "num:i(num:i('512') div num:i($ARBITRATION_LENGTH + $payload))"!]
                [!VAR "Can_MBsPerBlockTable" = "concat($Can_MBsPerBlockTable, $MBsPerBlock, ' ', $MBsPerBlock, ' ', $MBsPerBlock)"!]
            [!ENDIF!]
        [!ELSE!]
            [!VAR "Can_MBsPerBlockTable" = "concat($Can_MBsPerBlockTable, '32 32 32')"!]
        [!ENDIF!]
    [!ENDLOOP!]
[!ENDSELECT!]

[!/*==================================================================================================*/!]

[!VAR "MBIndex" = "0"!]
[!VAR "Can_BlockStartAddrTable" = "'0x0080 0x0280 0x0480'"!]
[!MACRO "GetMBIndex_FD", "Controller" = "0", "MBAddr" = "'0x0080'", "PayloadLength" = "8"!]
    [!VAR "Can_BlockMBsTable" = "text:split($Can_MBsPerBlockTable, '#')[position() - 1 = $Controller]"!]
    [!VAR "blockNumber" = "num:i((num:hextoint($MBAddr) - num:hextoint('0x80')) div num:i('512'))"!]
    [!VAR "startMBIdxOfRegion" = "'0'"!]
    [!FOR "i" = "1" TO "$blockNumber"!]
        [!VAR "MBsPerBlock" = "text:split($Can_BlockMBsTable, ' ')[position() - 1 = num:i($i - 1)]"!]
        [!VAR "startMBIdxOfRegion" = "num:i($startMBIdxOfRegion + $MBsPerBlock)"!]
    [!ENDFOR!]
    [!VAR "BlockStartAddr" = "text:split($Can_BlockStartAddrTable, ' ')[position() - 1 = num:i($blockNumber)]"!]
    [!VAR "MBIndexOffset" = "num:i((num:hextoint($MBAddr) - num:hextoint($BlockStartAddr)) div num:i($ARBITRATION_LENGTH + $PayloadLength))"!]
    [!VAR "MBIndex" = "num:i($startMBIdxOfRegion + $MBIndexOffset)"!]
[!ENDMACRO!]
[!/*==================================================================================================*/!]

[!VAR "Can_MaxMBCountTable" = "'0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00'"!]
[!MACRO "Update_EndMBIndex", "Controller" = "0", "can_MBIndex" = "0"!]
    [!VAR "strBefore" = "substring($Can_MaxMBCountTable, 1, num:i($Controller * 5))"!]
    [!VAR "strAfter"  = "substring($Can_MaxMBCountTable, num:i(($Controller+1) * 5))"!]
    [!VAR "targetIndex" = "text:split($Can_MaxMBCountTable, ' ')[position() - 1 = $Controller]"!]
    [!VAR "targetIndex" = "num:hextoint($targetIndex)"!]
    [!IF "$targetIndex < num:i($can_MBIndex + 1) "!]
        [!VAR "targetIndex" = "num:i($can_MBIndex + 1)"!]
    [!ENDIF!]
    [!VAR "targetIndex" = "num:inttohex($targetIndex, 2)"!]
    [!VAR "Can_MaxMBCountTable" = "concat($strBefore, $targetIndex, $strAfter)"!]
[!ENDMACRO!]
[!/*==================================================================================================*/!]
[!ENDNOCODE!]
/*==================================================================================================*/
/**
* @brief          Information about message buffers
* @details        (CAN100)Several TX hardware objects with unique HTHs may be configured. The CanIf module provides the HTH as parameter of the TX request. See Figure 7-2 for a possible configuration.
*
*/
/*==================================================================================================*/
[!SELECT "CanConfigSet"!]
    [!VAR "CSET_NR" = "num:i(0)"!] 
    [!WS "0"!]static CONST(Can_MBConfigObjectType, CAN_CONST) MessageBufferConfigs[!"$CSET_NR"!]_PB[CAN_MAXMBCOUNT_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]] =
    [!WS "0"!]{
    [!VAR "CanControllerIdValue"="0"!]
    [!VAR "ObjectID"="0"!]
    [!VAR "END_COMMA"="0"!]
    [!VAR "MASK_COUNT"="num:i(count(CanHardwareObject/*))"!]
    [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
        [!VAR "END_COMMA"="$END_COMMA + 1"!]
        [!IF "(../../../CanGeneral/CanMultiplexedTransmission = 'true') and (CanObjectType = 'TRANSMIT') and (node:value(CanHwObjectCount) >= 1 )"!]
            [!VAR "objectid"="0"!]
            [!FOR "objectid" = "0" TO "num:i(node:value(CanHwObjectCount) - 1 )"!]         
                [!WS "4"!]/* [!"@name"!] Message Buffer of Can Controller ID = [!SELECT "node:ref(CanControllerRef)"!][!"num:i(CanControllerId)"!]U[!ENDSELECT!] */
                [!WS "4"!]{
                [!INDENT "8"!]
                [!IF "CanObjectType = 'RECEIVE'"!]
                    [!IF "CanHandleType = 'BASIC'"!]
                        [!IF "node:exists(CanHwFilter/CanHwFilterMask)"!]
                           (Can_HwHandleType)[!"num:inttohex(CanObjectId)"!]U, /* uIdMaskIndex */
                        [!ENDIF!] 
                    [!ELSE!]
                        (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
                    [!ENDIF!]
                [!ELSE!]
                    (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
                [!ENDIF!]
                [!SELECT "node:ref(CanControllerRef)"!]
                    (uint8)[!"num:i(CanControllerId)"!]U, /* ControllerId  - based on the order from CanController list */
                [!ENDSELECT!]
                (CanIdType)CAN_[!"CanIdType"!], /* ID type: EXTENDED, STANDARD, MIXED */
                (Can_ObjType)CAN_[!"CanObjectType"!], /* Receive/Transmit MB configuration */
                [!IF "node:exists(CanHwFilter/CanHwFilterCode)"!]
                    (Can_IdType)[!"num:inttohex(CanHwFilter/CanHwFilterCode)"!]U, /* MessageId */
                [!ELSE!]
                    (Can_IdType)0x0U, /* MessageId */
                [!ENDIF!]
                (uint8)[!"num:inttohex(CanMBPrio)"!]U, /* Local priority bits used for arbitration */
                (Can_HwHandleType)[!"num:inttohex(CanObjectId)"!]U, /* Hardware Object ID */
                [!IF "ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON'"!]
                #if (CAN_FD_MODE_ENABLE == STD_ON)
                    [!IF " (node:exists(CanFdPaddingValue)) and (node:exists(../../../CanConfigSet/CanController/*/CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig)) and (node:fallback(CanObjectType,'TRANSMIT') = 'TRANSMIT')"!]
                        (uint8)[!"num:inttohex(CanFdPaddingValue)"!], /**< @brief Padding value for MB > 8 bytes */
                    [!ELSE!]
                        (uint8)0U,
                    [!ENDIF!]
                #endif
                [!ENDIF!]
                /* Read/Write period reference used when polling mode is selected for the controller */
                [!IF "node:refexists(CanMainFunctionRWPeriodRef)"!]
                    [!SELECT "node:ref(CanMainFunctionRWPeriodRef)"!]
                        (uint8)[!"@index"!]U,    /* HOH reference is from [!"node:name(.)"!] */
                    [!ENDSELECT!]
                [!ELSE!]
                    (uint8)0U,   /* HOH configured for interrupt mode, reference not used */
                [!ENDIF!][!//
                [!// Determine Address and payload length of MB
                [!SELECT "node:ref(CanControllerRef)"!]
                    [!VAR "controllerID" = "num:i(CanControllerId)"!]
                [!ENDSELECT!]
                [!IF "(ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON') and (node:exists(concat('../../CanController/', text:split(CanControllerRef, '/')[position()-1 = 4],'/CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig')))"!]
                    [!IF "(../../../CanGeneral/CanSpecifiedRAMBlockSize = 'true')"!]
                        [!SELECT "node:ref(CanRAMBlockRef)"!]
                            [!VAR "dataLength" = "substring-before(substring-after(CanRAMBlockSizeValue,'_'),'_')"!]
                            [!VAR "blockNumber" = "substring-after(CanRAMBlockName, 'CAN_RAM_BLOCK_')"!]
                        [!ENDSELECT!]
                        [!CALL "GetMBOffsetAddr_separate", "Controller" = "$controllerID", "RamBlock" = "$blockNumber", "PayloadLength" = "$dataLength"!][!//
                        /* Ram block [!"$blockNumber"!] - Payload [!"$dataLength"!]*/
                        (uint16)[!"$MBOffsetAddr"!]U,       /* Address of Message Buffer  */
                        (uint8)[!"num:i($dataLength)"!]U,    /* Payload lenth of Message Buffer */
                        [!CALL "GetMBIndex_FD", "MBAddr" = "$MBOffsetAddr", "PayloadLength" = "$dataLength"!]
                        (uint8)[!"$MBIndex"!]U    /* The index of MB in message buffer memory */
                    [!ELSE!]
                        [!// Calculate address based on MBDSR
                        [!VAR "dataLength" = "substring-before(substring-after(../../../CanGeneral/MBDSR,'_'),'_')"!]
                        [!CALL "GetMBOffsetAddr_normal", "Controller" = "$controllerID", "PayloadLength" = "$dataLength"!]
                        (uint16)[!"$MBOffsetAddr"!]U,       /* Address of Message Buffer  */
                        (uint8)[!"num:i($dataLength)"!]U,    /* Payload lenth of Message Buffer */
                        [!CALL "GetMBIndex_FD", "MBAddr" = "$MBOffsetAddr", "PayloadLength" = "$dataLength"!]
                        (uint8)[!"$MBIndex"!]U    /* The index of MB in message buffer memory */
                    [!ENDIF!]
                [!ELSE!]
                    [!// Calculate address for default case 8Bytes
                    [!CALL "GetMBOffsetAddr_normal", "Controller" = "$controllerID", "PayloadLength" = "8"!]
                    (uint16)[!"$MBOffsetAddr"!]U,       /* Address of Message Buffer  */
                    (uint8)8U,    /* Payload lenth of Message Buffer */
                    [!VAR "MBIndex" = "num:i((num:hextoint($MBOffsetAddr) - num:hextoint('0x80')) div (num:i($ARBITRATION_LENGTH + 8)))"!]
                    (uint8)[!"$MBIndex"!]U    /* The index of MB in message buffer memory */
                    [!IF "$MBIndex = 0"!]
                        [!SELECT "node:ref(CanControllerRef)"!]
                            [!IF "CanControllerRxFifoEnable = 'true'"!]
                                [!VAR "RxfifoMBsNumber" = "num:i((num:i(substring-after(./CanRxFifo/CanRxFifoFiltersNumber,'FILTERS_NUMBER_')) div 4) + 6)"!]
                                [!FOR "i" = "1" TO "num:i($RxfifoMBsNumber - 1)"!] [!// Loop MBs for Rxfifo (if Rxfifo is enabled)
                                    [!CALL "GetMBOffsetAddr_normal", "Controller" = "$controllerID", "PayloadLength" = "8"!]
                                [!ENDFOR!]
                                [!VAR "MBIndex" =  "num:i($RxfifoMBsNumber - 1)"!] [!// Update the number of MBs occupied by RxFIFO
                            [!ENDIF!]
                        [!ENDSELECT!]
                    [!ENDIF!]
                [!ENDIF!]
                [!CALL "Update_EndMBIndex", "Controller" = "$controllerID", "can_MBIndex" = "$MBIndex"!]
                [!IF "(node:exists(CanTriggerTransmitEnable)) and (node:value(CanTriggerTransmitEnable) ='true')"!]
                    #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
                    /* The parameter is used to detect the MB which run with trigger transmit feature */
                    ,(uint8)TRUE
                    #endif
                [!ELSE!]
                    #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
                    /* The parameter is used to detect the MB which run with trigger transmit feature */
                    ,(uint8)FALSE
                    #endif
                [!ENDIF!]
                [!ENDINDENT!]
                [!WS "4"!]}[!IF "$objectid < num:i(node:value(CanHwObjectCount) - 1 )"!],[!CR!][!ENDIF!][!CR!]
            [!ENDFOR!]
        [!ELSE!]
            [!WS "4"!]/* [!"@name"!] Message Buffer of Can Controller ID = [!SELECT "node:ref(CanControllerRef)"!][!"num:i(CanControllerId)"!]U[!ENDSELECT!] */
            [!WS "4"!]{
            [!INDENT "8"!]
            [!IF "CanObjectType = 'RECEIVE'"!]
                [!IF "CanHandleType = 'BASIC'"!]
                    [!IF "node:exists(CanHwFilter/CanHwFilterMask)"!]
                        (Can_HwHandleType)[!"num:inttohex(CanObjectId)"!]U, /* uIdMaskIndex */
                    [!ENDIF!] 
                [!ELSE!]
                    (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
                [!ENDIF!]
            [!ELSE!]
                (Can_HwHandleType)CAN_MAXMASKCOUNT, /* uIdMaskIndex */
            [!ENDIF!]
            [!SELECT "node:ref(CanControllerRef)"!]
                (uint8)[!"num:i(CanControllerId)"!]U, /* ControllerId  - based on the order from CanController list */
            [!ENDSELECT!]
            (CanIdType)CAN_[!"CanIdType"!], /* ID type: EXTENDED, STANDARD, MIXED */
            (Can_ObjType)CAN_[!"CanObjectType"!], /* Receive/Transmit MB configuration */
            [!IF "node:exists(CanHwFilter/CanHwFilterCode)"!]
                (Can_IdType)[!"num:inttohex(CanHwFilter/CanHwFilterCode)"!]U, /* MessageId */
            [!ELSE!]
                (Can_IdType)0x0U, /* MessageId */
            [!ENDIF!]
            (uint8)[!"num:inttohex(CanMBPrio)"!]U, /* Local priority bits used for arbitration */
            (Can_HwHandleType)[!"num:inttohex(CanObjectId)"!]U, /* Hardware Object ID */
            [!IF "ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON'"!]
            #if (CAN_FD_MODE_ENABLE == STD_ON)
                [!IF " (node:exists(CanFdPaddingValue)) and (node:exists(../../../CanConfigSet/CanController/*/CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig)) and (node:fallback(CanObjectType,'TRANSMIT') = 'TRANSMIT')"!]
                    (uint8)[!"num:inttohex(CanFdPaddingValue)"!], /**< @brief Padding value for MB > 8 bytes */
                [!ELSE!]
                    (uint8)0U,
                [!ENDIF!]
            #endif
            [!ENDIF!]
            /* Read/Write period reference used when polling mode is selected for the controller */
            [!IF "node:refexists(CanMainFunctionRWPeriodRef)"!]
                [!SELECT "node:ref(CanMainFunctionRWPeriodRef)"!]
                    (uint8)[!"@index"!]U, /* HOH reference is from [!"node:name(.)"!] */
                [!ENDSELECT!]
            [!ELSE!]
                (uint8)0U, /* HOH configured for interrupt mode, reference not used */
            [!ENDIF!][!//
            [!// Determine Address and payload length of MB
            [!SELECT "node:ref(CanControllerRef)"!]
                [!VAR "controllerID" = "num:i(CanControllerId)"!]
            [!ENDSELECT!]
            [!IF "(ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON') and (node:exists(concat('../../CanController/', text:split(CanControllerRef, '/')[position()-1 = 4],'/CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig')))"!]
                [!IF "(../../../CanGeneral/CanSpecifiedRAMBlockSize = 'true')"!]
                    [!SELECT "node:ref(CanRAMBlockRef)"!]
                        [!VAR "dataLength" = "substring-before(substring-after(CanRAMBlockSizeValue,'_'),'_')"!]
                        [!VAR "blockNumber" = "substring-after(CanRAMBlockName, 'CAN_RAM_BLOCK_')"!]
                    [!ENDSELECT!]
                    [!CALL "GetMBOffsetAddr_separate", "Controller" = "$controllerID", "RamBlock" = "$blockNumber", "PayloadLength" = "$dataLength"!][!//
                    /* Ram block [!"$blockNumber"!] - Payload [!"$dataLength"!]*/
                    (uint16)[!"$MBOffsetAddr"!]U,       /* Address of Message Buffer  */
                    (uint8)[!"num:i($dataLength)"!]U,    /* Payload lenth of Message Buffer */
                    [!CALL "GetMBIndex_FD", "MBAddr" = "$MBOffsetAddr", "PayloadLength" = "$dataLength"!]
                    (uint8)[!"$MBIndex"!]U    /* The index of MB in message buffer memory */
                [!ELSE!]
                    [!// Calculate address based on MBDSR
                    [!VAR "dataLength" = "substring-before(substring-after(../../../CanGeneral/MBDSR,'_'),'_')"!]
                    [!CALL "GetMBOffsetAddr_normal", "Controller" = "$controllerID", "PayloadLength" = "$dataLength"!]
                    (uint16)[!"$MBOffsetAddr"!]U,       /* Address of Message Buffer  */
                    (uint8)[!"num:i($dataLength)"!]U,    /* Payload lenth of Message Buffer */
                    [!CALL "GetMBIndex_FD", "MBAddr" = "$MBOffsetAddr", "PayloadLength" = "$dataLength"!]
                    (uint8)[!"$MBIndex"!]U    /* The index of MB in message buffer memory */
                [!ENDIF!]
            [!ELSE!]
                [!// Calculate address for default case 8Bytes
                [!CALL "GetMBOffsetAddr_normal", "Controller" = "$controllerID", "PayloadLength" = "8"!]
                (uint16)[!"$MBOffsetAddr"!]U,       /* Address of Message Buffer  */
                (uint8)8U,    /* Payload lenth of Message Buffer */
                [!VAR "MBIndex" = "num:i((num:hextoint($MBOffsetAddr) - num:hextoint('0x80')) div (num:i($ARBITRATION_LENGTH + 8)))"!]
                (uint8)[!"$MBIndex"!]U    /* The index of MB in message buffer memory */
                [!IF "$MBIndex = 0"!]
                    [!SELECT "node:ref(CanControllerRef)"!]
                        [!IF "CanControllerRxFifoEnable = 'true'"!]
                            [!VAR "RxfifoMBsNumber" = "num:i((num:i(substring-after(./CanRxFifo/CanRxFifoFiltersNumber,'FILTERS_NUMBER_')) div 4) + 6)"!]
                            [!FOR "i" = "1" TO "num:i($RxfifoMBsNumber - 1)"!] [!// Loop MBs for Rxfifo (if Rxfifo is enabled)
                                [!CALL "GetMBOffsetAddr_normal", "Controller" = "$controllerID", "PayloadLength" = "8"!]
                            [!ENDFOR!]
                            [!VAR "MBIndex" =  "num:i($RxfifoMBsNumber - 1)"!] [!// Update the number of MBs occupied by RxFIFO
                        [!ENDIF!]
                    [!ENDSELECT!]
                [!ENDIF!]
            [!ENDIF!]
            [!CALL "Update_EndMBIndex", "Controller" = "$controllerID", "can_MBIndex" = "$MBIndex"!]
            [!IF "(node:exists(CanTriggerTransmitEnable)) and (node:value(CanTriggerTransmitEnable) ='true')"!]
                #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
                /* The parameter is used to detect the MB which run with trigger transmit feature */
                ,(boolean)TRUE
                #endif
            [!ELSE!]
                #if (CAN_TRIGGER_TRANSMIT_EN == STD_ON)
                /* The parameter is used to detect the MB which run with trigger transmit feature */
                ,(boolean)FALSE
                #endif
            [!ENDIF!]
            [!ENDINDENT!]
            [!WS "4"!]}[!//
        [!ENDIF!][!//
        [!IF "$END_COMMA < $MASK_COUNT"!][!//
            [!WS "0"!],
        [!ENDIF!]
        [!CR!]
    [!ENDLOOP!]
    [!WS "0"!]};
[!ENDSELECT!]

/*==================================================================================================*/
/**
* @brief          Configuration of FlexCan controller
* @details        Configuration of FlexCan controller
*
*/
[!VAR "LoopVar"="0"!]
[!SELECT "CanConfigSet"!]
    [!VAR "CSET_NR" = "num:i(0)"!]
    [!LOOP "CanController/*"!]
        [!VAR "MASK_COUNT2"="num:i(count(CanControllerBaudrateConfig/*))"!]
        [!VAR "END_COMMA2"="0"!]
        [!WS "0"!]/* Compiler_Warning: this warning due to behavior of compiler depend on configs. */
        [!WS "0"!]static CONST(Can_ControllerBaudrateConfigType, CAN_CONST) ControllerBaudrateCfgSet[!"$CSET_NR"!]_PB_[!"CanControllerId"!][CAN_CFGSET[!"num:i($CSET_NR)"!]_MAX_BAUDRATE_FC_[!"substring-after(CanHwChannel,'FlexCAN_')"!]_[!"@index"!]] =
        [!WS "0"!]{
        [!LOOP "CanControllerBaudrateConfig/*"!]
            [!NOCODE!]
            [!VAR "END_COMMA2"="$END_COMMA2 + 1"!]
            [!/*
            Sync-seg = is the segment that is used to synchronise the nodes on the bus. A bit edge (if there is a data change) is expected during this segment.
            Prop-Seg = is a period of time that is used to compensate for physical delay times within the network.
            Phase-seg1 = is a buffer segment that may be lengthened during resynchronisation to compensate for oscillator drift and positive phase differences between the oscillators of the transmitting and receiving node(s).
            Phase-seg2 = is a buffer segment that may be shortened during resynchronisation (described below) to compensate for negative phase errors and oscillator drift.

            The Sample point is always at the end of Phase-seg1 and is the time at which the bus level is read and interpreted as the value of the current bit.
            Whether transmitting or receiving, all nodes on a single CAN bus must have the same nominal bit time. Bit time is programmable at each node on a CAN Bus and is a function
                of the period of the oscillator local to each node, the value that is user-programmed into a Baud Rate Prescaler (BRP) register in the controller at each node, and the programmed number of time quanta per bit.

            When any node receives a data frame or a remote frame, it is necessary for the receiver to synchronise with the transmitter.
                1. The first is hard synchronisation and occurs at Start-of-Frame (SOF).
                2. For subsequent bits in any received frame, if a bit edge does not occur in the Sync-seg segment of bit time, resynchronisation is automatically invoked and will shorten or lengthen the current bit time depending
                    on where the edge occurs. The maximum amount by which the bit time is lengthened or shortened is determined by a user-programmable number of time quanta known as the Synchronisation Jump Width (SJW).
            */!]
            [!/* Make the selection of source clock: from MCU or from CAN bus. */!]
            [!VAR "OutCanClockFrequencyFromMcu" = "0"!]
            [!IF "../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]
                [!VAR "OutCanClockFrequencyFromMcu_Alternate" = "0"!]
            [!ENDIF!]
            [!CALL "CanClockFrequency_M"!]
            [!VAR "CANClockFrequency" = "$OutCanClockFrequencyFromMcu"!][!/* Get the clock from MCU */!]
            [!IF "../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]
                [!VAR "CANClockFrequency_Alternate" = "$OutCanClockFrequencyFromMcu_Alternate"!][!/* Get the clock from MCU */!]
            [!ENDIF!]
            [!/* Calculate the prescaler */!]
            [!VAR "Prescaler" = "num:i(CanControllerPrescaller)"!][!/* Calculate Prescaler value. */!]
            [!VAR "CanControllerTimeQuanta" = "$Prescaler div ($CANClockFrequency)"!]
            [!IF "((ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON') and (../../CanClockFromBus = 'true')) or (ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_OFF')"!]
                [!IF "../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]
                    [!VAR "Prescaler_Alternate" = "num:i(CanControllerPrescaller_Alt)"!][!/* Calculate Prescaler value. */!]
                    [!VAR "CanControllerTimeQuanta_Alternate" = "$Prescaler_Alternate div ($CANClockFrequency_Alternate)"!]
                [!ENDIF!]
            [!ENDIF!]
            [!/* Calculate the Number of Tq/Can bit for the current baud rate and clock selection. */!]
            [!VAR "CANTimeQuanta" = "num:i(round((1 div (num:i(CanControllerBaudRate) * 1000)) div $CanControllerTimeQuanta))"!]
            [!IF "($CANTimeQuanta < 8) or ($CANTimeQuanta > 25)"!]
                [!ERROR!]
                    For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!], the desired CAN bus Nominal Bit Time (NBT) should be an integer number of Time Quanta (CAN system clock periods) from 8 to 25.
                    Current No of CanTimeQuantas = [!"num:i($CANTimeQuanta)"!] --->>> OUT of RANGE [8-25]
                    No of CanTimeQuantas = (1 / CanControllerBaudRate) / CanControllerTimeQuanta; where CanControllerTimeQuanta = (Prescaler / CANClockFrequency).
                [!ENDERROR!]
            [!ENDIF!]
            [!IF "((ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON') and (../../CanClockFromBus = 'true')) or (ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_OFF')"!]
                [!IF "../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]
                    [!VAR "CANTimeQuanta_Alternate" = "num:i(round((1 div (num:i(CanControllerBaudRate) * 1000)) div $CanControllerTimeQuanta_Alternate))"!]
                    [!IF "($CANTimeQuanta_Alternate < 8) or ($CANTimeQuanta_Alternate > 25)"!]
                        [!ERROR!]
                            For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!], the desired CAN bus Nominal Bit Time (NBT) should be an integer number of Time Quanta (CAN system clock periods) from 8 to 25.
                            Current No of CanTimeQuantas = [!"num:i($CANTimeQuanta_Alternate)"!] --->>> OUT of RANGE [8-25]
                            No of CanTimeQuantas = (1 / CanControllerBaudRate) / CanControllerTimeQuanta_Alternate; where CanControllerTimeQuanta_Alternate = (Prescaler_Alternate / CANClockFrequency_Alternate).
                        [!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
            [!IF "CanAdvancedSetting = 'false'"!]
                [!IF "CanControllerCheckCanStandard"!]
                  [!IF "ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON'"!]
                    [!/* Check the CAN FD bit time compliance  - get the values from Tresos interface and check to see that the number of time quantas introduced by user it is correct.*/!]
                    [!/* Formula used fot checking the total number of time quantas is: NoTqFD= fcanclk/((desired_baudrate[Hz])*(FD_prescaller +1 ))*/!]
                    [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!] 
                        [!SELECT "node:ref(../../CanCpuClockRef)"!]
                            [!VAR "OutCanClockFrequencyFromMcuFd" = "McuClockReferencePointFrequency"!]
                        [!ENDSELECT!]
                        [!VAR "CANTimeQuantaFd" = "num:i($OutCanClockFrequencyFromMcuFd div(num:i(num:i(CanControllerFdBaudrateConfig/CanControllerFdBaudRate) * (num:i((CanControllerFdBaudrateConfig/CanControllerFDPrescaller)-1) + 1)*1000)))"!]                    
                        [!VAR "FdTimeSegment1" = "num:i(num:i(CanControllerFdBaudrateConfig/CanControllerPropSeg) + num:i(CanControllerFdBaudrateConfig/CanControllerSeg1))"!]
                        [!VAR "FdTimeSegment2" = "num:i(num:i(CanControllerFdBaudrateConfig/CanControllerSeg2))"!]
                        [!VAR "FdTsyncsegment" = "1"!]
                        [!VAR "UserNoTimeQuantasFd"= "num:i($FdTsyncsegment + num:i(CanControllerFdBaudrateConfig/CanControllerPropSeg) + num:i(CanControllerFdBaudrateConfig/CanControllerSeg1) + num:i(CanControllerFdBaudrateConfig/CanControllerSeg2))"!]
                        [!IF "($CANTimeQuantaFd) != ($UserNoTimeQuantasFd)"!]     
                            [!ERROR!]
                                Time quanta value calculated based on CPU frequency and user prescaler should be [!"$CANTimeQuantaFd "!].
                                The value of FdTimeSegment1 + FdTimeSegment2 + FdTsyncsegment -> [!"$FdTimeSegment1"!] + [!"$FdTimeSegment2"!] + [!"$FdTsyncsegment"!]= [!"$UserNoTimeQuantasFd"!]
                            [!ENDERROR!]  
                        [!ENDIF!]
                        [!IF "($CANTimeQuantaFd<5) or ($CANTimeQuantaFd>48) "!]
                            [!ERROR!]
                                Time quanta out of range. Modify the prescaller to obtain a valid Time Quanta
                            [!ENDERROR!]
                        [!ENDIF!]
                        [!IF "($FdTimeSegment1<0) or ($FdTimeSegment1>255) "!]
                            [!ERROR!]
                                FdTimeSegment1 should have values between 0 and 255
                            [!ENDERROR!]
                        [!ENDIF!]
                        [!IF "($FdTimeSegment2<0) or ($FdTimeSegment2>255) "!]
                            [!ERROR!]
                                FdTimeSegment2 should have values between 0 and 255
                            [!ENDERROR!]
                        [!ENDIF!]
                    [!ENDIF!]
                  [!ENDIF!]
                  [!IF "ecu:get('Can.CanConfigSet.CBTSupport')='STD_ON'"!] 
                    [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!] 
                        [!/* Check the CAN CBT bit time compliance  - get the values from Tresos interface and check to see that the number of time quantas introduced by user it is correct.*/!]
                        [!/* Formula used fot checking the total number of time quantas is: NoTqCBT= fcanclk/((desired_baudrate[Hz])*(FD_prescaller +2 ))*/!]
                        [!SELECT "node:ref(../../CanCpuClockRef)"!]
                            [!VAR "OutCanClockFrequencyFromMcuCbt" = "McuClockReferencePointFrequency"!]
                        [!ENDSELECT!]
                        [!VAR "CANTimeQuantaCbt" = "num:i($OutCanClockFrequencyFromMcuCbt div(num:i(num:i(CanControllerCBT/CanControllerCbtBaudRate) * (num:i((CanControllerCBT/CanControllerCbtPrescaller)-1) + 1)*1000)))"!]
                        [!VAR "CbtTimeSegment1" = "num:i(num:i(CanControllerCBT/CanControllerCbtPropSeg) + num:i(CanControllerCBT/CanControllerCbtSeg1))"!]
                        [!VAR "CbtTimeSegment2" = "num:i(num:i(CanControllerCBT/CanControllerCbtSeg2))"!]
                        [!VAR "CbtTsyncsegment" = "1"!]
                        [!VAR "UserNoTimeQuantasCbt"= "num:i($CbtTsyncsegment + num:i(CanControllerCBT/CanControllerCbtPropSeg) + num:i(CanControllerCBT/CanControllerCbtSeg1) + num:i(CanControllerCBT/CanControllerCbtSeg2))"!]
                        [!IF "($CANTimeQuantaCbt) != ($UserNoTimeQuantasCbt)"!]     
                            [!ERROR!]
                               Time quanta value calculated based on CPU frequency and user prescaler should be [!"$CANTimeQuantaCbt "!].
                               The value of CbtTimeSegment1 + CbtTimeSegment2 + CbtTsyncsegment -> [!"$CbtTimeSegment1"!] + [!"$CbtTimeSegment2"!] + [!"$CbtTsyncsegment"!]= [!"$UserNoTimeQuantasCbt"!]
                            [!ENDERROR!]  
                        [!ENDIF!]
                        [!IF "($CANTimeQuantaCbt<8) or ($CANTimeQuantaCbt>129) "!]
                            [!ERROR!]
                               Time quanta out of range. Modify the prescaller to obtain a valid Time Quanta
                            [!ENDERROR!]
                        [!ENDIF!]
                        
                        [!IF "($CbtTimeSegment1<4) or ($CbtTimeSegment1>96) "!]
                            [!ERROR!]
                               CbtTimeSegment1 should have values between 4 and 96
                            [!ENDERROR!]
                        [!ENDIF!]
                        [!IF "($CbtTimeSegment2<2) or ($CbtTimeSegment2>32) "!]
                            [!ERROR!]
                               CbtTimeSegment2 should have values between 2 and 32
                            [!ENDERROR!]
                        [!ENDIF!]
                        [!IF "ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON'"!]
                            [!IF "(node:exists(CanControllerFdBaudrateConfig) = 'true') and ((node:value(CanControllerFdBaudrateConfig/CanControllerTxBitRateSwitch)) = 'true')"!]
                                [!IF "$UserNoTimeQuantasCbt != $UserNoTimeQuantasFd"!]
                                    [!WARNING!]
                                        The No of Time Quantas for CAN_CBT ([!"num:i($UserNoTimeQuantasCbt)"!]) is different by No of Time Quantas configurated for CAN_FD ([!"num:i($UserNoTimeQuantasFd)"!]).
                                        This situation can occur a quantization error of up to one time quantum of the arbitration phase, which may be present as a phase error.
                                    [!ENDWARNING!]
                                [!ENDIF!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!IF "ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON'"!]
                            [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!] 
                                [!WARNING!]
                                    When the CAN FD feature is enabled, always use the CAN_CBT register for the CAN bit timing to have same No. of time quanta for both control phase and data phase.
                                [!ENDWARNING!]
                            [!ENDIF!]
                        [!ENDIF!]
                    [!ENDIF!] 
                  [!ENDIF!]
                    [!/* Check the CAN bit time compliance  - get the values from Tresos interface and check.*/!]
                    [!VAR "NoTimeQuantas"= "num:i($Tsyncsegment + num:i(CanControllerPropSeg) + num:i(CanControllerSeg1) + num:i(CanControllerSeg2))"!]
                    [!VAR "TimeSegment1" = "num:i(num:i(CanControllerPropSeg) + num:i(CanControllerSeg1))"!]
                    [!VAR "TimeSegment2" = "num:i(num:i(CanControllerSeg2))"!]
                    [!IF "($TimeSegment1 < 4) or ($TimeSegment1 > 16)"!]
                        [!ERROR!]For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!], TimeSegment1 [= CanControllerPropSeg + CanControllerSeg1] should be between [4 .. 16], current value is [!"num:i($TimeSegment1)"!][!ENDERROR!]
                    [!ENDIF!]
                    [!IF "($NoTimeQuantas < 8) or ($NoTimeQuantas > 25)"!]
                        [!ERROR!]
                        For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                        No of CanTimeQuantas should be between [8 .. 25], current value is [!"num:i($NoTimeQuantas)"!].
                        BitTimeQuanta = SyncSeg + PropSeg + PSEG1 + PSEG2 .
                        SyncSeg = 1. PropSeg = [!"num:i(CanControllerPropSeg)"!]. PSEG1 = [!"num:i(CanControllerSeg1)"!]. PSEG2 = [!"num:i(CanControllerSeg2)"!].[!ENDERROR!]
                    [!ENDIF!]             
                [!ENDIF!]
            [!ELSE!]
                [!/* Initiates the derivation of the CAN bit timing values from the CanControllerBaudRate parameter. */!]
                [!VAR "BusPropogationDelay" ="5 div 1000000000"!][!/* Hard coded to 5ns/m. */!]
                [!VAR "PhysicalDelayOfBus"="CanBusLength * $BusPropogationDelay"!]
                [!/* Tprop_seg=TpropAB + TpropBA = 2 * (Tbus + Trx + Ttx). Ussually Trx=Ttx. */!]
                [!VAR "Tpropogationsegment"="2*($PhysicalDelayOfBus + 2 * (CanPropDelayTranceiver div 1000000000))"!]
                [!VAR "PropogationSegment"="1+round($Tpropogationsegment div $CanControllerTimeQuanta )"!]
                [!IF "($PropogationSegment >= 1) and ($PropogationSegment <= 8)"!]
                    [!VAR "PhaseSegments" = "($CANTimeQuanta - $PropogationSegment - $Tsyncsegment)"!]
                    [!IF "$PhaseSegments >= 2"!]
                        [!VAR "Modulo" = "$PhaseSegments mod 2"!]
                        [!IF "$Modulo = 0"!]
                            [!VAR "PhaseSegment1" = "num:i($PhaseSegments div 2)"!]
                            [!VAR "PhaseSegment2" = "num:i($PhaseSegment1)"!]
                        [!ELSE!]
                            [!VAR "PhaseSegment1" = "num:i(($PhaseSegments - 1) div 2)"!]
                            [!VAR "PhaseSegment2" = "num:i($PhaseSegment1 + 1)"!]
                        [!ENDIF!]
                        [!IF "($PhaseSegment1 < 1) or ($PhaseSegment1 > 8)"!]
                            [!ERROR!]
                            For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                            PropSegment1 is out of range [1:8]. Current value is [!"num:i($PhaseSegment1)"!].
                            The bit length has [!"num:i($CANTimeQuanta)"!] Time Quantas.
                            Propagation Segment based bus length and tranceiver delay has [!"num:i($PropogationSegment)"!] Time Quantas.
                            Need to increase PropogationSegment or to decrease the number of Time Quantas per bit.
                            [!ENDERROR!]
                        [!ENDIF!]
                        [!IF "($PhaseSegment2 < 2) or ($PhaseSegment2 > 8)"!]
                            [!ERROR!]
                            For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                            PropSegment2 is out of range [2:8]. Current value is [!"num:i($PhaseSegment2)"!]
                            The bit length has [!"num:i($CANTimeQuanta)"!] Time Quantas.
                            Propagation Segment based bus length and tranceiver delay has [!"num:i($PropogationSegment)"!] Time Quantas.
                            Need to increase PropogationSegment or to decrease the number of Time Quantas per bit.
                            [!ENDERROR!]
                        [!ENDIF!]
                        [!IF "$PhaseSegment1 < 5"!]
                            [!VAR "RJW" = "num:i($PhaseSegment1)"!]
                        [!ELSE!]
                            [!VAR "RJW" = "4"!]
                        [!ENDIF!]
                    [!ELSE!]
                        [!ERROR!] For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!], (Phase Segment1+Phase Segment2) must be >= 8. Increase no of CANTimeQuanta ([!"num:i($CANTimeQuanta)"!]) per bit or decrease PropSegment ([!"num:i($PropogationSegment)"!])(based CanBusLength and CanPropDelayTranceiver).[!ENDERROR!]
                    [!ENDIF!]
                [!ELSE!]
                    [!ERROR!]
                    For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                    Propagation Segment is out of range [1:8].
                    Delay A_to_B >= node output delay(A) + bus line delay(A+B) + node input delay(B)
                    Prop_Seg >= Delay A_to_B + Delay B_to_A
                    Prop_Seg >= 2 * [max(node output delay+ bus line delay + node input delay)]

                    The formulas used:
                    BusPropogationDelay =5 div 1000000000 /* Hard coded to 5ns/m. */
                    PhysicalDelayOfBus = CanBusLength * BusPropogationDelay
                    Tpropogationsegment = 2*(PhysicalDelayOfBus + 2 * (CanPropDelayTranceiver div 1000000000))
                    PropogationSegment = 1+round(Tpropogationsegment div CanControllerTimeQuanta )
                    [!ENDERROR!]
                [!ENDIF!]
                [!VAR "NoTimeQuantas"= "num:i($Tsyncsegment + $PropogationSegment + $PhaseSegment1 + $PhaseSegment2)"!]
            [!ENDIF!]
            [!IF "CanControllerCheckCanStandard"!]
                [!/* Minimum ratio between the peripheral clock frequency and Can Bit rate Check */!]
                [!VAR "maxmb" = "0"!]
                [!VAR "x" = "num:i(../../CanControllerId)"!]
                [!LOOP "../../../../CanHardwareObject/*"!]
                    [!SELECT "node:ref(CanControllerRef)"!]
                        [!IF "num:i(CanControllerId) = num:i($x)"!]
                            [!VAR "maxmb" = "$maxmb+1"!]
                        [!ENDIF!]
                    [!ENDSELECT!]
                [!ENDLOOP!]
                [!IF "num:i($maxmb) <= 16"!]
                    [!IF "($NoTimeQuantas * $Prescaler < 8)"!]
                        [!ERROR!]
                        For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                        When CanMessageBufferCount is <=16, Prescaler is [!"num:i($Prescaler)"!], No of CanTimeQuantas is [!"num:i($NoTimeQuantas)"!],
                        Minimum Ratio should be 8, current value is [!"num:i($NoTimeQuantas * $Prescaler)"!].
                        Increase Prescaler or NoTimeQuantas values.[!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
                [!IF "(num:i($maxmb) > 16) and (num:i($maxmb) <= 32)"!]
                    [!IF "($NoTimeQuantas * $Prescaler < 8)"!]
                        [!ERROR!]
                        For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                        When CanMessageBufferCount is >16 and <=32, Prescaler is [!"num:i($Prescaler)"!], No of CanTimeQuantas is [!"num:i($NoTimeQuantas)"!],
                        Minimum Ratio should be 8, current value is [!"num:i($NoTimeQuantas * $Prescaler)"!].
                        Increase Prescaler or NoTimeQuantas values.[!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
                [!IF "(num:i($maxmb) > 32) and (num:i($maxmb) <= 64)"!]
                    [!IF "($NoTimeQuantas * $Prescaler < 16)"!]
                        [!ERROR!]
                        For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                        When CanMessageBufferCount is >32 and <=64, Prescaler is [!"num:i($Prescaler)"!], No of CanTimeQuantas is [!"num:i($NoTimeQuantas)"!],
                        Minimum Ratio should be 16, current value is [!"num:i($NoTimeQuantas * $Prescaler)"!].
                        Increase Prescaler or NoTimeQuantas values.[!ENDERROR!]
                    [!ENDIF!]
                [!ENDIF!]
                [!IF "num:i($CANTimeQuanta) != num:i($NoTimeQuantas)"!]
                    [!WARNING!]
                        For [!"node:name(.)"!] of CanController [!"../../CanHwChannel"!],
                        The No of CanTimeQuantas set by you ([!"$NoTimeQuantas"!]) is different by No of CanTimeQuantas calculated from clock settings ([!"num:i($CANTimeQuanta)"!]).
                        NoTimeQuantas = SyncSeg + PropSeg + PSEG1  + PSEG2  (from user settings).
                        NoCANTimeQuantas = (1 / CanControllerBaudRate) / CanControllerTimeQuanta;
                    [!ENDWARNING!]
                [!ENDIF!]
            [!ENDIF!]
            [!ENDNOCODE!]
            [!WS "4"!]/*
            [!WS "4"!]=================================================
            [!WS "4"!]Clock Size = [!"$CANClockFrequency"!] Hz [!IF "((ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON') and (../../CanClockFromBus = 'true')) or (ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_OFF')"!] - Clock from MCU. [!ELSE!] - Clock from external OSC.[!ENDIF!][!CR!]
            [!WS "4"!][!IF "((ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON') and (../../CanClockFromBus = 'true')) or (ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_OFF')"!][!IF "node:exists(./../../../../../CanGeneral/CanEnableDualClockMode)"!][!IF "./../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]Clock Size Alternate = [!"$CANClockFrequency_Alternate"!] Hz [!IF "../../CanClockFromBus"!] - Clock from MCU. [!ELSE!] - Clock from external OSC.[!ENDIF!] [!ENDIF!][!ENDIF!][!ENDIF!][!CR!]
            [!WS "4"!]Clock Prescaler = [!"$Prescaler"!] (1..256)
            [!WS "4"!][!IF "((ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON') and (../../CanClockFromBus = 'true')) or (ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_OFF')"!][!IF "node:exists(./../../../../../CanGeneral/CanEnableDualClockMode)"!][!IF "./../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]Clock Prescaler_Alternate = [!"$Prescaler_Alternate"!] (1..256)[!ENDIF!][!ENDIF!][!ENDIF!][!CR!]
            [!WS "4"!]CanBitRate = [!"CanControllerBaudRate"!] Kbps (1bps..1Mbps)
            [!WS "4"!]Number CANTimeQuantas per bit = [!"$CANTimeQuanta"!] (8..25)
            [!WS "4"!][!IF "((ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON') and (../../CanClockFromBus = 'true')) or (ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_OFF')"!][!IF "node:exists(./../../../../../CanGeneral/CanEnableDualClockMode)"!][!IF "./../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]Number CANTimeQuantas_Alternate per bit = [!"$CANTimeQuanta_Alternate"!] (8..25)[!ENDIF!][!ENDIF!][!ENDIF!][!CR!]
            [!WS "4"!]CTRL Register Fields:
            [!WS "4"!]PSEG1 = [!IF "CanAdvancedSetting"!][!"$PhaseSegment1"!][!ELSE!][!"CanControllerSeg1"!][!ENDIF!] (0..7)
            [!WS "4"!]PSEG2 = [!IF "CanAdvancedSetting"!][!"$PhaseSegment2"!][!ELSE!][!"CanControllerSeg2"!][!ENDIF!] (1..7)
            [!WS "4"!]PROPSEG = [!IF "CanAdvancedSetting"!][!"num:i($PropogationSegment)"!][!ELSE!][!"num:i(CanControllerPropSeg)"!][!ENDIF!] (0..7)
            [!WS "4"!]RJW = [!IF "CanAdvancedSetting"!][!"$RJW"!][!ELSE!][!"CanControllerSyncJumpWidth"!][!ENDIF!] (0..3)
            [!WS "4"!]=================================================
            [!WS "4"!]*/
            [!IF "../../CanControllerActivation = 'true'"!]
                [!WS "4"!]/* Configuration for CanController ID[!"../../CanControllerId"!] == [!"../../CanHwChannel"!] */
                [!WS "4"!]{
                [!WS "8"!]/* ===== Control Register - CTRL ===== */
                [!WS "8"!](uint32)( ((uint32)[!"num:i(num:i($Prescaler) - 1)"!] << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |    /* CTRL[PRESDIV] - Clock Prescaler */
                [!IF "CanAdvancedSetting = 'false'"!]
                    [!WS "18"!]((uint32)[!"num:i(num:i(CanControllerSyncJumpWidth)-1)"!] << FLEXCAN_CTRL_RJW_SHIFT_U8) |     /* CTRL[RJW] - Resynchronization Jump Width */
                [!ELSE!]
                    [!WS "18"!]((uint32)[!"num:i(num:i($RJW)-1)"!] << FLEXCAN_CTRL_RJW_SHIFT_U8) |      /* CTRL[RJW] - Resynchronization Jump Width */
                [!ENDIF!] 
                [!IF "CanAdvancedSetting = 'false'"!]
                    [!WS "18"!]((uint32)[!"num:i(num:i(CanControllerSeg1)-1)"!] << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |      /* CTRL[PSEG1] - Segment 1 */
                [!ELSE!]
                    [!WS "18"!]((uint32)[!"num:i(num:i($PhaseSegment1)-1)"!] << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |     /* CTRL[PSEG1] - Segment 1 */
                [!ENDIF!] 
                [!IF "CanAdvancedSetting = 'false'"!]
                    [!WS "18"!]((uint32)[!"num:i(num:i(CanControllerSeg2)-1)"!] << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |    /* CTRL[PSEG2] - Segment 2 */
                [!ELSE!]
                    [!WS "18"!]((uint32)[!"num:i(num:i($PhaseSegment2)-1)"!] << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |   /* CTRL[PSEG2] - Segment 2 */
                [!ENDIF!] 
                [!IF "ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON'"!]
                    [!IF "../../CanClockFromBus = 'true'"!]
                        [!WS "18"!]((uint32)1 << FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                    [!ELSE!]
                        [!WS "18"!]((uint32)0 << FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                    [!ENDIF!] 
                [!ENDIF!] 
                [!IF "CanAdvancedSetting = 'false'"!]
                    [!WS "18"!][!"num:i(num:i(CanControllerPropSeg)-1)"!]U   /* CTRL[PROPSEG] - Propagation segment */
                [!ELSE!]
                    [!WS "18"!][!"num:i(num:i($PropogationSegment)-1)"!]U    /* CTRL[PROPSEG] - Propagation segment */
                [!ENDIF!]
                [!WS "16"!]),
                [!WS "8"!](uint8)[!"num:i(CanTxArbitrationStartDelay)"!]U, /* CTRL2[TASD] Tx Arbitration Start Delay */
                [!WS "0"!]#if (CAN_DUAL_CLOCK_MODE == STD_ON)
                [!IF "((ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON') and (../../CanClockFromBus = 'true')) or (ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_OFF')"!]
                    [!IF "../../../../../CanGeneral/CanEnableDualClockMode = 'true'"!]
                        [!WS "8"!]/* ===== Control Register Alternate - CTRL ===== */
                        [!WS "8"!](uint32)( ((uint32)[!"num:i(num:i($Prescaler_Alternate) - 1)"!] << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |     /* CTRL[PRESDIV] - Clock Prescaler */
                        [!IF "CanAdvancedSetting = 'false'"!]
                            [!WS "18"!]((uint32)[!"num:i(num:i(CanControllerSyncJumpWidth)-1)"!]  << FLEXCAN_CTRL_RJW_SHIFT_U8) |   
                        [!ELSE!]
                            [!WS "18"!]((uint32)[!"num:i(num:i($RJW)-1)"!]  << FLEXCAN_CTRL_RJW_SHIFT_U8) | 
                        [!ENDIF!]
                        [!IF "CanAdvancedSetting = 'false'"!]
                            [!WS "18"!]((uint32)[!"num:i(num:i(CanControllerSeg1)-1)"!] << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |    /* CTRL[PSEG1] - Segment 1 */
                        [!ELSE!]
                            [!WS "18"!]((uint32)[!"num:i(num:i($PhaseSegment1)-1)"!] << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |    /* CTRL[PSEG1] - Segment 1 */
                        [!ENDIF!]
                        [!IF "CanAdvancedSetting = 'false'"!]
                            [!WS "18"!]((uint32)[!"num:i(num:i(CanControllerSeg2)-1)"!] << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |      /* CTRL[PSEG2] - Segment 2 */
                        [!ELSE!]
                            [!WS "18"!]((uint32)[!"num:i(num:i($PhaseSegment2)-1)"!] << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |     /* CTRL[PSEG2] - Segment 2 */
                        [!ENDIF!]
                        [!IF "ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON'"!]
                            [!IF "../../CanClockFromBus = 'true'"!]
                                [!WS "18"!]((uint32)1 << FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                            [!ELSE!]
                                [!WS "18"!]((uint32)0 << FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |
                            [!ENDIF!] 
                        [!ENDIF!] 
                        [!IF "CanAdvancedSetting = 'false'"!]
                            [!WS "18"!][!"num:i(num:i(CanControllerPropSeg)-1)"!]U   /* CTRL[PROPSEG] - Propagation segment */
                        [!ELSE!]
                            [!WS "18"!][!"num:i(num:i($PropogationSegment)-1)"!]U    /* CTRL[PROPSEG] - Propagation segment */
                        [!ENDIF!]
                        [!WS "16"!]),
                    [!ELSE!]
                        [!WS "8"!]0U,
                    [!ENDIF!]
                [!ELSE!]
                    [!WS "8"!]0U,
                [!ENDIF!]
                [!IF "(./../../../../../CanGeneral/CanEnableDualClockMode = 'true') and ((ecu:get('Can.CanConfig.CtrlClksrcAvailable')='STD_ON') and (../../CanClockFromBus = 'false'))"!]
                    [!WARNING!]When dual clock feature is enabled (CanEnableDualClockMode), the clock from MCU should be selected (CanClockFromBus).[!ENDWARNING!]
                [!ENDIF!]
                [!WS "0"!]#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
                [!WS "8"!](uint16)[!"CanControllerBaudRate"!],   /* [!"CanControllerBaudRate"!]kbps baud rate */
                [!IF "ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON'"!]
                [!WS "0"!]#if (CAN_FD_MODE_ENABLE == STD_ON)
                [!WS "8"!]{
                [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)1U << FLEXCAN_FD_OFFSET_U8), /*CAN FD Activated*/
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U << FLEXCAN_FD_OFFSET_U8), /*CAN FD Deactivated*/
                [!ENDIF!]
                [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!]
                    [!WS "12"!](uint32)[!"CanControllerFdBaudrateConfig/CanControllerFdBaudRate"!]U,   /* [!"CanControllerBaudRate"!]kbps baud rate */
                [!ELSE!]
                    [!WS "12"!](uint32)0U,
                [!ENDIF!]
                [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i((CanControllerFdBaudrateConfig/CanControllerFDPrescaller)-1)"!]U << FLEXCAN_FD_PRESDIV_OFFSET_U8) |   /* CAN FD propagation segment */
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_PRESDIV_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"CanControllerFdBaudrateConfig/CanControllerPropSeg"!]U << FLEXCAN_FD_PROPSEG_OFFSET_U8) |   /* CAN FD propagation segment */
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_PROPSEG_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i((CanControllerFdBaudrateConfig/CanControllerSeg1)-1)"!]U << FLEXCAN_FD_PSEG1_OFFSET_U8) |   /* time segment 1 */
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<< FLEXCAN_FD_PSEG1_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i((CanControllerFdBaudrateConfig/CanControllerSeg2)-1)"!]U<<FLEXCAN_FD_PSEG2_OFFSET_U8) |   /*Time segment 2  */
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_PSEG2_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i((CanControllerFdBaudrateConfig/CanControllerSyncJumpWidth - 1))"!]U<<FLEXCAN_FD_SJW_OFFSET_U8), /*Sync jump width*/
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_SJW_OFFSET_U8), /*Sync jump width*/
                [!ENDIF!]
                [!IF "(node:exists(CanControllerFdBaudrateConfig)) = 'true'"!]
                    [!WS "12"!](uint32)[!"CanControllerFdBaudrateConfig/CanControllerTrcvDelayCompensationOffset"!]U, /*TRCV DELAY*/
                [!ELSE!]
                    [!WS "12"!](uint32)0U, /*TRCV DELAY*/
                [!ENDIF!]
                [!IF "(node:exists(CanControllerFdBaudrateConfig) = 'true') and ((node:value(CanControllerFdBaudrateConfig/CanControllerTxBitRateSwitch)) = 'true')"!]
                    [!WS "12"!](uint32)((uint32)1U<<FLEXCAN_FD_BRS_OFFSET_U8) /*true -> the node exists, BRS activated*/
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_BRS_OFFSET_U8) /*false -> the node dos not exist, BRS deactivated*/
                [!ENDIF!]
                [!WS "0"!]#if ( (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON) || (CAN_CONTROLLER_FD_PREXCEN == STD_ON) || (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON) )
                [!WS "12"!],(uint32)(
                [!IF "(node:exists(CanControllerFdBaudrateConfig))"!]
                    [!WS "0"!]#if (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON)
                    [!IF "(node:value(CanControllerFdBaudrateConfig/CanControllerFdIsoCANFD) = 'true')"!]
                        [!WS "23"!](uint32)((uint32)1U<<FLEXCAN_FD_CTRL2_STFCNTEN_SHIFT_U32)
                    [!ELSE!]
                        [!WS "23"!](uint32)((uint32)0U<<FLEXCAN_FD_CTRL2_STFCNTEN_SHIFT_U32)
                    [!ENDIF!]
                    [!WS "0"!]#else
                        [!WS "23"!](uint32)((uint32)0U<<FLEXCAN_FD_CTRL2_STFCNTEN_SHIFT_U32)
                    [!WS "0"!]#endif /* (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON) */
                    [!WS "0"!]#if (CAN_CONTROLLER_FD_PREXCEN == STD_ON)
                    [!IF "(node:value(CanControllerFdBaudrateConfig/CanControllerFdPrExcEn) = 'true')"!]
                        [!WS "23"!]| (uint32)((uint32)1U<<FLEXCAN_FD_CTRL2_PREXCEN_SHIFT_U32)
                    [!ELSE!]
                        [!WS "23"!]| (uint32)((uint32)0U<<FLEXCAN_FD_CTRL2_PREXCEN_SHIFT_U32)
                    [!ENDIF!]
                    [!WS "0"!]#endif /* (CAN_CONTROLLER_FD_PREXCEN == STD_ON) */
                    [!WS "0"!]#if (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON)
                    [!IF "(node:value(CanControllerFdBaudrateConfig/CanControllerFdEdgeFilterDis) = 'true')"!]
                        [!WS "23"!]| (uint32)((uint32)1U<<FLEXCAN_FD_CTRL2_EDFLTDIS_SHIFT_U32)
                    [!ELSE!]
                        [!WS "23"!]| (uint32)((uint32)0U<<FLEXCAN_FD_CTRL2_EDFLTDIS_SHIFT_U32)
                    [!ENDIF!]
                    [!WS "0"!]#endif /* (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON) */
                [!ELSE!]
                    [!WS "23"!]0U
                [!ENDIF!]
                [!WS "21"!])
                [!WS "0"!]#endif /* ( (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON) || (CAN_CONTROLLER_FD_PREXCEN == STD_ON) || (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON)) */
                [!WS "8"!]},
                [!WS "0"!]#endif /* (CAN_FD_MODE_ENABLE == STD_ON) */
                [!ENDIF!]
                [!WS "0"!]#if (CAN_CBT_ENABLE == STD_ON)
                [!WS "8"!]{
                [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)1U<<FLEXCAN_CBT_OFFSET_U8),
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_CBT_OFFSET_U8),
                [!ENDIF!]
                [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!]
                    [!WS "12"!](uint32)[!"CanControllerCBT/CanControllerCbtBaudRate"!]U,   /* [!"CanControllerCBT/CanControllerCbtBaudRate"!] kbps baud rate */
                [!ELSE!]
                    [!WS "12"!](uint32)0U,
                [!ENDIF!]  
                [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i((CanControllerCBT/CanControllerCbtPrescaller)-1)"!]U << FLEXCAN_FD_PRESDIV_CBT_OFFSET_U8) |   /* CAN FD propagation segment */
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_PRESDIV_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)1U<<FLEXCAN_CBT_OFFSET_U8) |
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_CBT_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i(CanControllerCBT/CanControllerCbtPropSeg - 1)"!]U << FLEXCAN_CBT_PROPSEG_OFFSET_U8) |   /* CAN FD propagation segment */
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_PROPSEG_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i(CanControllerCBT/CanControllerCbtSeg1 - 1)"!]U << FLEXCAN_CBT_PSEG1_OFFSET_U8) |   /* time segment 1 */
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<< FLEXCAN_FD_PSEG1_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i(CanControllerCBT/CanControllerCbtSeg2 - 1)"!]U<<FLEXCAN_CBT_PSEG2_OFFSET_U8) |   /*Time segment 2  */
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_PSEG2_OFFSET_U8) |
                [!ENDIF!]
                [!IF "(node:value(CanControllerCBT/CanControllerCbtEnable)) = 'true'"!]
                    [!WS "12"!](uint32)((uint32)[!"num:i((CanControllerCBT/CanControllerSyncJumpWidthCbt - 1))"!]U<<FLEXCAN_CBT_SJW_OFFSET_U8) /*Sync jump width*/
                [!ELSE!]
                    [!WS "12"!](uint32)((uint32)0U<<FLEXCAN_FD_SJW_OFFSET_U8) /*Sync jump width*/
                [!ENDIF!]
                [!WS "8"!]},
                [!WS "0"!]#endif /* (CAN_CBT_ENABLE == STD_ON) */
                [!WS "0"!]#if (CAN_SET_BAUDRATE_API == STD_ON)
                [!WS "8"!](uint16)[!"CanControllerBaudRateConfigID"!]
                [!WS "0"!]#endif
                [!WS "4"!]}
                [!IF "$END_COMMA2 < $MASK_COUNT2"!]
                    [!WS "0"!],
                [!ENDIF!]
                [!CR!]
            [!ELSE!]
                [!WS "8"!]{
                [!WS "12"!]/* [!"../../CanHwChannel"!] ControlRegister Default Configuration: 125 Kbps BaudRate with Oscillator clock 8MHz as Clock source and TimeQuantum of 1000ns. */
                [!WS "12"!]/* ===== Control Register - CTRL ===== */
                [!WS "12"!](uint32)( ((uint32)7 << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |     /* CTRL[PRESDIV] - Clock Prescaler */
                [!WS "22"!]((uint32)2 << FLEXCAN_CTRL_RJW_SHIFT_U8) |         /* CTRL[RJW] - Resynchronization Jump Width */
                [!WS "22"!]((uint32)2 << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |       /* CTRL[PSEG1] - Segment 1 */
                [!WS "22"!]((uint32)2 << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |       /* CTRL[PSEG2] - Segment 2 */
                [!WS "22"!]((uint32)0 << FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |      /* CTRL[CLK_SRC] - Clock source */
                [!WS "22"!](uint32)0                                          /* CTRL[PROPSEG] - Propagation segment */
                [!WS "20"!]) ,
                [!WS "8"!](uint8)12U, /* CTRL2[TASD] Tx Arbitration Start Delay */
                [!WS "0"!]#if (CAN_DUAL_CLOCK_MODE == STD_ON)
                [!WS "8"!]/* ===== Control Register Alternate - CTRL ===== */
                [!WS "8"!](uint32)( ((uint32)7 << FLEXCAN_CTRL_PRESDIV_SHIFT_U8) |    /* CTRL[PRESDIV] - Clock Prescaler */
                [!WS "18"!]((uint32)2 << FLEXCAN_CTRL_RJW_SHIFT_U8 ) |       /* CTRL[RJW] - Resynchronization Jump Width */
                [!WS "18"!]((uint32)2 << FLEXCAN_CTRL_PSEG1_SHIFT_U8) |      /* CTRL[PSEG1] - Segment 1 */
                [!WS "18"!]((uint32)2 << FLEXCAN_CTRL_PSEG2_SHIFT_U8) |      /* CTRL[PSEG2] - Segment 2 */
                [!WS "18"!]((uint32)0 << FLEXCAN_CTRL_CLKSRC_SHIFT_U8) |     /* CTRL[CLK_SRC] - Clock source */
                [!WS "18"!](uint32)0                                         /* CTRL[PROPSEG] - Propagation segment */
                [!WS "16"!]) ,
                [!WS "0"!]#endif /* CAN_DUAL_CLOCK_MODE == STD_ON */
                [!WS "8"!](uint16)125U    /* 125kbps baud rate */
                [!WS "0"!]#if (CAN_FD_MODE_ENABLE == STD_ON)
                [!WS "8"!],{
                [!WS "12"!]    0U, 0U, 0U, 0U, 0U
                [!WS "8"!]#if ( (CAN_CONTROLLER_FD_ISO_CANFD == STD_ON) || (CAN_CONTROLLER_FD_PREXCEN == STD_ON) || (CAN_CONTROLLER_FD_EDFLTDIS == STD_ON))
                [!WS "12"!]    ,0U
                [!WS "8"!]#endif
                [!WS "8"!]}
                [!WS "0"!]#endif
                [!WS "0"!]#if (CAN_CBT_ENABLE == STD_ON)
                [!WS "8"!],{
                [!WS "12"!]    0U, 0U, 0U
                [!WS "8"!]}
                [!WS "0"!]#endif
                [!WS "0"!]#if (CAN_SET_BAUDRATE_API == STD_ON)
                [!WS "8"!],(uint16)0U    /*Can Controller BaudRate ConfigID */
                [!WS "0"!]#endif
                [!WS "4"!]}
                [!IF "$END_COMMA2 < $MASK_COUNT2"!]
                    [!WS "0"!],
                [!ENDIF!]
                [!CR!]
            [!ENDIF!]
        [!ENDLOOP!]
        [!WS "0"!]};
    [!ENDLOOP!]
[!ENDSELECT!]

/*==================================================================================================*/
/**
* @brief          Description of individual FlexCan controllers on chip
* @details        Description of individual FlexCan controllers on chip
*
*/

[!VAR "LoopVar"="0"!]
[!SELECT "CanConfigSet"!]
    [!VAR "CSET_NR" = "num:i(0)"!]
    [!VAR "MaxConfiguredMBs" = "../CanGeneral/CanMaxMessageBuffers"!][!// The number of MBs are configured from the CanMaxMessageBuffers node
    [!WS "0"!]static CONST(Can_ControlerDescriptorType, CAN_CONST) ControlerDescriptors[!"$CSET_NR"!]_PB[CAN_MAXCONTROLLERCOUNT_[!"$CSET_NR"!]] =
    [!WS "0"!]{
    [!VAR "MASK_COUNT4"="num:i(count(CanController/*))"!]
    [!VAR "END_COMMA4"="0"!]
    [!VAR "tableidcount" = "0"!]
    [!LOOP "node:order(CanController/*,'node:value(CanControllerId)')"!]
        [!WS "4"!]/* ControlerDescriptor of CanController_[!"node:value(CanControllerId)"!]*/
        [!WS "4"!]{
                    [!INDENT "8"!]
                    [!IF "CanControllerActivation = 'true'"!]
                        /* No. of Message Buffers for current controller - u8MaxMBCount */
                        [!VAR "CtrlID" = "CanControllerId"!]
                        [!VAR "maxmbcount" = "text:split($Can_MaxMBCountTable, ' ')[position() - 1 = $CtrlID]"!]
                        [!VAR "maxmbcount" = "num:hextoint($maxmbcount)"!]
                        (uint8)[!"$maxmbcount"!]U, /* No. of Message Buffers for current controller - u8MaxMBCount */
                        [!IF "$maxmbcount>ecu:get('Can.CanConfigSet.CanMB')"!]
                            [!ERROR!]Maximum MBs + RxFifo (if enabled) exceed [!"ecu:get('Can.CanConfigSet.CanMB')"!] space.[!ENDERROR!]
                        [!ENDIF!]
                        [!IF "$MaxConfiguredMBs < $maxmbcount"!]
                            [!ERROR!] 
                                CanMaxMessageBuffers = [!"$MaxConfiguredMBs"!] < The number of MBs of Can Controller [!"num:i(CanControllerId)"!] = [!"num:i($maxmbcount)"!].
                                Value of CanMaxMessageBuffers must be great or equal than the number of MBs are configured for Can Controller. 
                            [!ENDERROR!]
                        [!ENDIF!]

                        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
                        [!VAR "maxbrcount" = "num:i(count(CanControllerBaudrateConfig/*))"!]
                        (uint8)[!"num:i($maxbrcount)"!]U,
                        [!IF "contains(node:path(node:ref(CanControllerDefaultBaudrate)),node:path(CanControllerBaudrateConfig))"!]
                        [!ELSE!]
                            [!ERROR!]
                                Please select CanControllerDefaultBaudrate from the "[!"substring-after(node:path(CanControllerBaudrateConfig),'ELEMENTS/')"!]" container.
                            [!ENDERROR!]
                        [!ENDIF!]
                        /* Default BaudRate configured for current controller - u8DefaultBaudRateIndex */
                        [!VAR "defaultbaudrateref" = "node:path(node:ref(CanControllerDefaultBaudrate))"!]
                        [!VAR "defaultbaudrateindex" = "0"!]
                        [!LOOP "CanControllerBaudrateConfig/*"!]
                            [!IF "$defaultbaudrateref = node:path(.)"!]
                                (uint8)[!"num:i($defaultbaudrateindex)"!]U,
                                [!BREAK!]
                            [!ENDIF!]
                            [!VAR "defaultbaudrateindex" = "$defaultbaudrateindex + 1"!]
                        [!ENDLOOP!]
                         /* pControllerBaudrateConfigsPtr - pControllerBaudrateConfigsPtr*/
                         ControllerBaudrateCfgSet[!"$CSET_NR"!]_PB_[!"CanControllerId"!],
                        #if (CAN_RXFIFO_ENABLE == STD_ON)
                        /*Rx Fifo Global mask value - u32RxFifoGlobalMask*/
                        (uint32)[!IF "CanControllerRxFifoEnable = 'true'"!][!"num:inttohex(num:i(./CanRxFifo/CanRxFifoGlobalMaskValue))"!]U,[!ELSE!]0U,[!ENDIF!]
                        /* Number of MBs used by Rx Fifo - u8RxFiFoUsedMb */
                        (uint8)[!IF "CanControllerRxFifoEnable = 'true'"!][!"num:i((num:i(substring-after(./CanRxFifo/CanRxFifoFiltersNumber,'FILTERS_NUMBER_')) div 4) + 6)"!]U,[!ELSE!]0U,[!ENDIF!]
                        /* Pointer to RxFifo Overflow notification function. - Can_RxFifoOverflowNotification */
                        [!IF "(CanControllerRxFifoEnable = 'true') and (normalize-space(CanRxFifoOverflowNotification) != 'NULL_PTR')"!]&[!"normalize-space(CanRxFifoOverflowNotification)"!],[!ELSE!]NULL_PTR,[!ENDIF!]
                        /* Pointer to RxFifo Warning notification function. - Can_RxFifoWarningNotification */
                        [!IF "(CanControllerRxFifoEnable = 'true') and (normalize-space(CanRxFifoWarningNotification) != 'NULL_PTR')"!]&[!"normalize-space(CanRxFifoWarningNotification)"!],[!ELSE!]NULL_PTR,[!ENDIF!][!CR!]
                        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                        #if (CAN_FD_MODE_ENABLE == STD_ON)
                            /* Message Buffer Data Size for three RAM regions */
                            (uint32)(
                                        [!INDENT "18"!]
                                        [!IF "(ecu:get('Can.CanConfigSet.CanFdEnable')='STD_ON') and (node:exists(CanControllerBaudrateConfig/*/CanControllerFdBaudrateConfig))"!]
                                            /* Exist FD */
                                            [!IF "../../../CanGeneral/CanSpecifiedRAMBlockSize"!]
                                                /* CanSpecifiedRAMBlockSize */
                                                [!VAR "MASK_COUNT5" = "num:i(count(CanRAMBlock/*))"!]
                                                [!VAR "END_COMMA5"="0"!]
                                                [!LOOP "CanRAMBlock/*"!]
                                                    [!VAR "MBDSRx_OFFSET_U8" = "concat('FLEXCAN_MBDSR', substring-after(CanRAMBlockName, 'CAN_RAM_BLOCK_'), '_OFFSET_U8')"!]
                                                    [!VAR "payload" = "CanRAMBlockSizeValue"!]
                                                    ((uint32)[!"$payload"!]_U32 << (uint32)[!"$MBDSRx_OFFSET_U8"!])[!//
                                                        [!VAR "END_COMMA5"="$END_COMMA5 + 1"!][!//
                                                        [!IF "$END_COMMA5 < $MASK_COUNT5"!] | [!ENDIF!][!CR!]
                                                [!ENDLOOP!]
                                            [!ELSE!]
                                                /* Don't CanSpecifiedRAMBlockSize */
                                                [!VAR "payload" = "../../../CanGeneral/MBDSR"!]
                                                ((uint32)[!"$payload"!]_U32 << (uint32)FLEXCAN_MBDSR0_OFFSET_U8) | 
                                                ((uint32)[!"$payload"!]_U32 << (uint32)FLEXCAN_MBDSR1_OFFSET_U8) |
                                                ((uint32)[!"$payload"!]_U32 << (uint32)FLEXCAN_MBDSR2_OFFSET_U8)
                                            [!ENDIF!]
                                        [!ELSE!]
                                            0U
                                        [!ENDIF!]
                                        [!ENDINDENT!]
                             [!WS "8"!]),
                        #endif
                        /* ===== Controller Options ===== -  u32Options*/
                        (uint32)(
                                    [!INDENT "20"!]
                                    [!IF "CanSoftwareBusOffRecovery = 'true' "!]
                                        CAN_CONTROLLERCONFIG_BUSOFFSWREC_U32 |/* Software BusOff Recovery */
                                    [!ENDIF!]
                                    [!IF "CanControllerRxFifoEnable = 'true' "!]
                                        CAN_CONTROLLERCONFIG_RXFIFO_U32 | /* RX Fifo Enabled */
                                    [!ELSE!] 
                                        /* RX Fifo Disabled */ 
                                    [!ENDIF!]
                                    [!IF "CanLocalPriorityEn = 'true' "!]
                                        CAN_CONTROLLERCONFIG_LPRIO_EN_U32 |  /* Local Priority Feature */
                                    [!ENDIF!]
                                    [!IF "(CanErrorControllerNotifEn = 'true') and (normalize-space(CanErrorControllerNotification) != 'NULL_PTR')"!]
                                        CAN_CONTROLLERCONFIG_ERR_EN_U32 | /* Error Notification enabled */
                                    [!ELSE!] 
                                        /* Error Notification disable */ 
                                    [!ENDIF!]
                                    [!IF "CanControllerRxFifoEnable = 'true'"!]
                                        #if (CAN_RXFIFO_ENABLE == STD_ON)
                                            [!IF "(normalize-space(CanRxFifoOverflowNotification) != 'NULL_PTR')"!]
                                                CAN_CONTROLLERCONFIG_OVER_EN_U32 | /* Rx Fifo Overflow handling enabled */
                                            [!ELSE!] 
                                                /* Rx Fifo Overflow handling disabled */ 
                                            [!ENDIF!]
                                            [!IF "(normalize-space(CanRxFifoWarningNotification) != 'NULL_PTR')"!]
                                                CAN_CONTROLLERCONFIG_WARN_EN_U32 | /* Rx Fifo Warning handling enabled */
                                            [!ELSE!] 
                                                /* Rx Fifo Warning handling disabled */ 
                                            [!ENDIF!]
                                            [!IF "CanRxFifo/CanControllerIDAcceptanceMode = 'A'"!]
                                                CAN_CONTROLLERCONFIG_IDAM_A_U32 | /* ID Acceptance Mode A */
                                            [!ELSEIF "CanRxFifo/CanControllerIDAcceptanceMode = 'B'"!]
                                                CAN_CONTROLLERCONFIG_IDAM_B_U32 | /* ID Acceptance Mode B */
                                            [!ELSEIF "CanRxFifo/CanControllerIDAcceptanceMode = 'C'"!]
                                                CAN_CONTROLLERCONFIG_IDAM_C_U32 | /* ID Acceptance Mode C */
                                            [!ELSEIF "CanRxFifo/CanControllerIDAcceptanceMode = 'D'"!]
                                                CAN_CONTROLLERCONFIG_IDAM_D_U32 | /* ID Acceptance Mode D: All frames rejected */
                                            [!ENDIF!]
                                        #endif
                                    [!ENDIF!]
                                    [!IF "CanBccSupport = 'true'"!]
                                        #if (CAN_BCC_SUPPORT_ENABLE == STD_ON)
                                            CAN_CONTROLLERCONFIG_BCC_EN_U32 |
                                        #endif /* (CAN_BCC_SUPPORT_ENABLE == STD_ON) */
                                    [!ENDIF!]
                                    0U
                                    [!ENDINDENT!]
                                )
                    [!ELSE!]
                        /* No. of Message Buffers for current controller - u8MaxMBCount */
                        (uint8)0U,
                        /* No. of BaudRate configured for current controller - u8MaxBaudRateCount */
                        (uint8)0U,
                        /* Default BaudRate configured for current controller */
                        (uint8)0U,
                        /* pControllerBaudrateConfigsPtr */
                        ControllerBaudrateCfgSet[!"$CSET_NR"!]_PB_[!"CanControllerId"!],

                        #if (CAN_RXFIFO_ENABLE == STD_ON)
                        /*Rx Fifo Global mask value*/
                        (uint32)0U,
                        /* Number of MBs used by Rx Fifo */
                        (uint8)0U,
                        /* Pointer to RxFifo Overflow notification function. */
                        NULL_PTR,
                        /* Pointer to RxFifo Warning notification function. */
                        NULL_PTR,
                        #endif /* (CAN_RXFIFO_ENABLE == STD_ON) */
                        #if (CAN_FD_MODE_ENABLE == STD_ON)
                            /* Message Buffer Data Size for three RAM regions */
                            (uint32)0U,
                        #endif
                        /* ===== Controller Options ===== */
                        (uint32)(0U)
                    [!ENDIF!]
                   [!ENDINDENT!]
        [!WS "4"!]}[!//
        [!VAR "END_COMMA4"="$END_COMMA4 + 1"!][!//
        [!IF "$END_COMMA4 < $MASK_COUNT4"!][!//
            [!WS "0"!], /* ControlerDescriptors CanController_[!"node:value(CanControllerId)"!] end */
        [!ENDIF!]
        [!CR!]
    [!ENDLOOP!]
    [!WS "0"!]};
[!ENDSELECT!]

/*==================================================================================================*/
/**
* @brief          Top level structure containing all Can driver configurations
* @details        Top level structure containing all Can driver configurations
*
*/
[!VAR "LoopVar"="0"!] 
[!SELECT "CanConfigSet"!]
    [!VAR "CSET_NR" = "num:i(0)"!]
    [!WS "0"!]/* @violates @ref Can_PBcfg_c_REF_4 Violates MISRA 2004 Required Rule 8.10*/
    [!NOCODE!][!//
    [!IF "((../IMPLEMENTATION_CONFIG_VARIANT != 'VariantPostBuild') and (variant:size()>1)) or (../IMPLEMENTATION_CONFIG_VARIANT = 'VariantPostBuild')"!][!//
    [!CODE!][!WS "0"!]CONST(Can_ConfigType, CAN_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =[!ENDCODE!][!//
    [!ELSE!]
    [!CODE!][!WS "0"!]CONST(Can_ConfigType, CAN_CONST) Can_PBCfgVariantPredefined =[!ENDCODE!][!//
    [!ENDIF!][!//
    [!ENDNOCODE!]
    [!WS "0"!]{
    [!WS "4"!]Can_FilterMasks[!"$CSET_NR"!]_PB, /*  - pFilterMasks */
    [!WS "4"!]/* MessageBufferConfigContainer - MBConfigContainer */
    [!WS "4"!]{
    [!WS "8"!]MessageBufferConfigs[!"$CSET_NR"!]_PB, /* pMessageBufferConfigsPtr */
    [!WS "8"!](Can_HwHandleType)CAN_MAXMBCOUNT_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!], /* uMessageBufferConfigCount */
    [!WS "4"!]},
    [!WS "4"!]
    [!WS "4"!]ControlerDescriptors[!"$CSET_NR"!]_PB, /* FlexCAN controller description - ControlerDescriptors*/
    [!WS "0"!]#if (CAN_RXFIFO_ENABLE == STD_ON)
    [!WS "4"!]/* Can_RxFiFoTableIdConfigType - pRxFiFoTableIdConfig */
    [!VAR "rxfifoenable" = "0"!]
    [!LOOP "CanController/*"!][!/* If at least one controller has RxFifo enabled, rxfifoenable var is set. */!]
        [!IF "CanControllerRxFifoEnable = 'true'"!]
            [!VAR "rxfifoenable" = "1"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$rxfifoenable = 1"!]
        [!WS "4"!]RxFifoTableID_PBConfig[!"$CSET_NR"!],
    [!ELSE!]
        [!WS "4"!]NULL_PTR, /* Rx fifo disabled */
    [!ENDIF!]
    [!WS "0"!]#endif  /* (CAN_RXFIFO_ENABLE == STD_ON) */
    [!WS "4"!]/* The index of the first HTH configured */
    [!VAR "Can_First_HTH_Index" = "0"!]
    [!VAR "Can_Check_ExistHTH" = "0"!]
    [!LOOP "node:order(CanHardwareObject/*,'node:value(CanObjectId)')"!]
        [!IF "CanObjectType = 'TRANSMIT'"!]
            [!IF "$Can_Check_ExistHTH = 0"!]
                [!VAR "Can_First_HTH_Index" = "CanObjectId"!]
            [!ENDIF!]
            [!VAR "Can_Check_ExistHTH" = "1"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!IF "$Can_Check_ExistHTH = 0"!][!/* Unless it has any HTH, Can_First_HTH_Index will be equal Max MB count  */!]
        [!WS "4"!](Can_HwHandleType)CAN_MAXMBCOUNT_PB[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!],
    [!ELSE!]
        [!WS "4"!](Can_HwHandleType)[!"num:i($Can_First_HTH_Index)"!]U,
    [!ENDIF!]
    [!WS "4"!]/*Controller ID mapping - u8ControllerIdMapping*/
    [!WS "4"!]{ [!//
    [!VAR "Can_hardware_ob_id" = "0"!][!VAR "END_COMMA"="0"!][!//
    [!VAR "MASK_COUNT"="0"!][!//
    [!LOOP "CanHardwareObject/*"!][!//
        [!IF "$MASK_COUNT < CanObjectId"!][!//
            [!VAR "MASK_COUNT" = "CanObjectId"!][!//
        [!ENDIF!][!//
    [!ENDLOOP!][!//
    [!VAR "MASK_COUNT" = "$MASK_COUNT + 1"!][!//
    [!FOR "objectid" = "0" TO "num:i(count(CanHardwareObject/*) - 1)"!][!//
        [!LOOP "CanHardwareObject/*"!][!//
            [!IF "CanObjectId = $objectid"!][!//
                [!VAR "END_COMMA"="$END_COMMA + 1"!][!//
                [!SELECT "node:ref(CanControllerRef)"!][!//
                    [!WS "0"!][!"num:i(CanControllerId)"!]U[!//
                [!ENDSELECT!][!//
                [!IF "$END_COMMA < $MASK_COUNT"!][!//
                    [!WS "0"!], [!//
                [!ENDIF!][!//
                [!BREAK!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//
    [!ENDFOR!][!//
    [!WS "0"!]},
    [!WS "4"!]/*Can Object Type mapping - eObjectTypeMapping*/
    [!WS "4"!]{
    [!VAR "Can_hardware_ob_id" = "0"!]
    [!VAR "END_COMMA"="0"!]
    [!VAR "MASK_COUNT"="0"!]
    [!LOOP "CanHardwareObject/*"!]
        [!IF "$MASK_COUNT < CanObjectId"!]
            [!VAR "MASK_COUNT" = "CanObjectId"!]
        [!ENDIF!]
    [!ENDLOOP!]
    [!VAR "MASK_COUNT" = "$MASK_COUNT + 1"!]
    [!FOR "objectid" = "0" TO "num:i(count(CanHardwareObject/*) - 1)"!]
        [!LOOP "CanHardwareObject/*"!]
            [!IF "CanObjectId = $objectid"!]
                [!VAR "END_COMMA"="$END_COMMA + 1"!]
                [!WS "8"!](Can_ObjType)CAN_[!"CanObjectType"!][!//
                [!IF "$END_COMMA < $MASK_COUNT"!] ,[!//
                [!ENDIF!]
                [!CR!]
                [!BREAK!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDFOR!]
    [!WS "4"!]}
    [!WS "0"!]};
[!ENDSELECT!]
 
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define CAN_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref Can_PBcfg_c_REF_1 MISRA 2004  Rule 19.1, #include preceded by non preproc directives.*/
/* @violates @ref Can_PBcfg_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
