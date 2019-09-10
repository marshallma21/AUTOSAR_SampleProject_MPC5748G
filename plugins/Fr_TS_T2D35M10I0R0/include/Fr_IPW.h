/**
*   @file    Fr_IPW.h
*   @implements Fr_IPW.h_Artifact
*
*   @version 1.0.0
*
*   @brief   AUTOSAR Fr - FlexRay LLD Module interface file..
*   @details Contains all types and function prototypes required by FlexRay LLD driver.
*
*   @addtogroup [MODULE_SECTION]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : FLEXRAY
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
#ifndef FR_IPW_H
#define FR_IPW_H

#ifdef __cplusplus
extern "C"{
#endif

/***************************************************************************************************
* MISRA violations
***************************************************************************************************/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section FR_IPW_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, #include "Fr_MemMap.h" is not preceded only by
* preprocessor directives and appears not only in the beginning of file because it otherwise
* would not work.
*
* @section FR_IPW_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier specified by ASR.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#ifndef FR_H
#include "Fr.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_IPW_MODULE_ID                        81
#define FR_IPW_VENDOR_ID                        43
#define FR_IPW_AR_RELEASE_MAJOR_VERSION         4
#define FR_IPW_AR_RELEASE_MINOR_VERSION         2
/* @violates @ref FR_IPW_H_REF_2 */
#define FR_IPW_AR_RELEASE_REVISION_VERSION      2
#define FR_IPW_SW_MAJOR_VERSION                 1
#define FR_IPW_SW_MINOR_VERSION                 0
#define FR_IPW_SW_PATCH_VERSION                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr.h header file are of the same vendor */
#if(FR_IPW_VENDOR_ID != FR_VENDOR_ID)
    #error "Fr_IPW.h and Fr.h have different Vendor IDs"
#endif
/* Check if current file and Fr.h header file are of the same Autosar version */
#if((FR_IPW_AR_RELEASE_MAJOR_VERSION    != FR_AR_RELEASE_MAJOR_VERSION) || \
    (FR_IPW_AR_RELEASE_MINOR_VERSION    != FR_AR_RELEASE_MINOR_VERSION) || \
    (FR_IPW_AR_RELEASE_REVISION_VERSION != FR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_IPW.h and Fr.h are different"
#endif
/* Check if current file and Fr.h header file are of the same software version */
#if((FR_IPW_SW_MAJOR_VERSION != FR_SW_MAJOR_VERSION) || \
    (FR_IPW_SW_MINOR_VERSION != FR_SW_MINOR_VERSION) || \
    (FR_IPW_SW_PATCH_VERSION != FR_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_IPW.h and Fr.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Never-ending while loop protection */
/* FR_IPW_MAX_WAITCYCLES constant is used to correctly handle the situation when the driver */
/* waits till the PE accepts a command (for example the protocol control command). */
/* In such a case, the driver will be waiting in the loop (maximum FR_IPW_MAX_WAITCYCLES */
/* iterations) until a proper value appears in the required register. */
#define FR_IPW_MAX_WAITCYCLES_U8                    ((uint8)100U)

/* This value is used for never-ending NMV reading protection */
#define FR_IPW_MAX_NMVREAD_U8                       ((uint8)5U)

/* This value is used to enable/disable FR Controler disabled mode */
/* STD_ON means that hardware allows to enable FR CC (set MEN bit) only once */
/* STD_OFF means that hardware allows to re-enable FR CC (set and clear MEN bit) more than once */
#define FR_IPW_CC_ONCE_ENABLEONLYMODE (STD_OFF)

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_START_SEC_CODE
/* @violates @ref FR_IPW_H_REF_1 */
#include "Fr_MemMap.h"

FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_CCInit(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(void, FR_CODE) Fr_Ipw_DisableTimers(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_CheckCCAccess(VAR(uint8, AUTOMATIC) ctrlIdx, CONST(boolean, AUTOMATIC) Fr_CC_enabled);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_EnterPOCConfigState(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(void, FR_CODE) Fr_Ipw_ClusterNodeParamCfg(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_BuffersInit(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_ClearDisableIRQs(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_LeavePOCConfigState(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_InvokeCHICommand(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) chiCommand);
FUNC(void, FR_CODE) Fr_Ipw_AckAbsoluteTimerIRQ(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(void, FR_CODE) Fr_Ipw_CancelAbsoluteTimer(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(void, FR_CODE) Fr_Ipw_DisableAbsoluteTimerIRQ(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
/* @violates @ref FR_IPW_H_REF_2 */
FUNC(boolean, FR_CODE) Fr_Ipw_GetAbsoluteTimerIRQStatus(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(void, FR_CODE) Fr_Ipw_SetAbsoluteTimer(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx, VAR(uint8, AUTOMATIC) cycle, VAR(uint16, AUTOMATIC) offset);
FUNC(void, FR_CODE) Fr_Ipw_EnableAbsoluteTimerIRQ(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_SetWakeupChannel(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(Fr_ChannelType, AUTOMATIC) chnlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetGlobalTime(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) cyclePtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) macroTickPtr);
FUNC(uint16, FR_CODE) Fr_Ipw_GetPOCState(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetPOCStatus(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) pocStatusPtr);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetNmVector(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) nmVectorPtr, P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) hwErr);
FUNC(void, FR_CODE) Fr_Ipw_GetChannelStatus(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAStatusPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBStatusPtr);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetClockCorrection(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) rateCorrectionPtr, P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) offsetCorrectionPtr);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetSyncFrameList(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) listSize,
                                                      P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAEvenListPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBEvenListPtr,
                                                      P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAOddListPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBOddListPtr
                                                     );
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetWakeupRxStatus(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) wakeupRxStatusPtr); 
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_ReadbackCCConfig(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_TransmitTxLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lpduIdx, P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) lsduPtr, VAR(uint8, AUTOMATIC) lsduLength);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_ReceiveRxLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lpduIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
                                                   P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
                                                  );
FUNC(void, FR_CODE) Fr_Ipw_ReceiveFifoA(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lpduIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
                                                   P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
                                                  );
FUNC(void, FR_CODE) Fr_Ipw_ReceiveFifoB(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lpduIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
                                                   P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
                                                  );
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_CheckTxLPduStatus(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx, P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) txLPduStatusPtr);
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_PrepareLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx);
#endif
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_ReconfigLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx, VAR(uint16, AUTOMATIC) frameId, VAR(Fr_ChannelType, AUTOMATIC) chnlIdx,
                                                  VAR(uint8, AUTOMATIC) cycleRepetition, VAR(uint8, AUTOMATIC) cycleOffset, VAR(uint8, AUTOMATIC) payloadLength, VAR(uint16, AUTOMATIC) headerCRC
                                                 );
#endif
#if(FR_DISABLE_LPDU_SUPPORT == STD_ON)
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_DisableLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx);
#endif
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_CancelTxLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx, P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) pendingStatus);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetNumOfStartupFrames(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) numOfStartupFramesPtr);
#if(FR_DEINIT_API == STD_ON)
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_WaitForPOCState(VAR(uint8, AUTOMATIC) u8ctrlIdx, CONST(uint16, AUTOMATIC) u16pocState);
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_DeInit(VAR(uint8, AUTOMATIC) u8ctrlIdx);
#endif
#define FR_STOP_SEC_CODE
/* @violates @ref FR_IPW_H_REF_1 */
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FR_IPW_H */
/* End of file */
