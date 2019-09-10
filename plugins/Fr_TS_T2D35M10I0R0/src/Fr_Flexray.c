/**
*   @file    Fr_Flexray.c
*   @implements Fr_FlexRay.c_Artifact
*
*   @version 1.0.0
*
*   @brief   AUTOSAR Fr - FlexRay IP module LLD file.
*   @details Provides functions for FlexRay module register access.
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
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section FR_FLEXRAY_C_REF_1
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer because of memory
* mapped registers addressing.
*
* @section FR_FLEXRAY_C_REF_2
* Violates MISRA 2004 Advisory Rule 11.4, A cast between pointers to two different objects is
* done because of the speed optimization of the memory access and required 32-bit access to two
* adjacent 16-bit registers.
*
* @section FR_FLEXRAY_C_REF_3
* Violates MISRA 2004 Required Rule 19.15, Inclusion of "Fr_MemMap.h" is required here because of
* its functionality.
*
* @section FR_FLEXRAY_C_REF_4
* Violates MISRA 2004 Required Rule 17.4, No better way how to access HW memory area and some
* configuration structures.
*
* @section FR_FLEXRAY_C_REF_6
* Violates MISRA 2004 Advisory Rule 19.1,  #include "Fr_MemMap.h" is not preceded only by preprocessor
* directives and appears not only in the beginning of file because it otherwise would not work.
*
* @section FR_FLEXRAY_C_REF_7
* Violates MISRA 2004 Required Rule 13.6, This violation is due to performance reasons to ensure
* fast data copying process.
*
* @section FR_FLEXRAY_C_REF_8
* Violates MISRA 2004 Required Rule 5.1, Identifier is specified by ASR or configuration.
*
* @section FR_FLEXRAY_C_REF_10
* Violates MISRA 2004 Required Rule 1.4, The compiler - linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* Identifier is specified by ASR standard.
*
* @section FR_FLEXRAY_C_REF_11
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an 
* integral type.
*
* @section FR_FLEXRAY_C_REF_12
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed between a pointer to object type and
* a different pointer to object type.
*
* @section FR_FLEXRAY_C_REF_13
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any constorvolatile
* qualification from the type addressed by a pointer.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Fr_Flexray.h"
#include "Fr_IPW.h"
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DEM_H
  #include "Dem.h"
#endif
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_FLEXRAY_MODULE_ID_C                        81
#define FR_FLEXRAY_VENDOR_ID_C                        43
/* @violates @ref FR_FLEXRAY_C_REF_8 */
/* @violates @ref FR_FLEXRAY_C_REF_10 */
#define FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION_C         4
/* @violates @ref FR_FLEXRAY_C_REF_8 */
/* @violates @ref FR_FLEXRAY_C_REF_10 */
#define FR_FLEXRAY_AR_RELEASE_MINOR_VERSION_C         2
/* @violates @ref FR_FLEXRAY_C_REF_8 */
/* @violates @ref FR_FLEXRAY_C_REF_10 */
#define FR_FLEXRAY_AR_RELEASE_REVISION_VERSION_C      2
#define FR_FLEXRAY_SW_MAJOR_VERSION_C                 1
#define FR_FLEXRAY_SW_MINOR_VERSION_C                 0
#define FR_FLEXRAY_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_Flexray.h header file are of the same vendor */
#if(FR_FLEXRAY_VENDOR_ID_C != FR_FLEXRAY_VENDOR_ID)
   #error "Fr_Flexray.c and Fr_Flexray.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Flexray.h header file are of the same Autosar version */
#if((FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION_C    != FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION) || \
    (FR_FLEXRAY_AR_RELEASE_MINOR_VERSION_C    != FR_FLEXRAY_AR_RELEASE_MINOR_VERSION) || \
    (FR_FLEXRAY_AR_RELEASE_REVISION_VERSION_C != FR_FLEXRAY_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_Flexray.c and Fr_Flexray.h are different"
#endif
/* Check if current file and Fr_Flexray.h header file are of the same software version */
#if((FR_FLEXRAY_SW_MAJOR_VERSION_C != FR_FLEXRAY_SW_MAJOR_VERSION) || \
    (FR_FLEXRAY_SW_MINOR_VERSION_C != FR_FLEXRAY_SW_MINOR_VERSION) || \
    (FR_FLEXRAY_SW_PATCH_VERSION_C != FR_FLEXRAY_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_Flexray.c and Fr_Flexray.h are different"
#endif

/* Check if current file and Fr_IPW.h header file are of the same vendor */
#if(FR_FLEXRAY_VENDOR_ID_C != FR_IPW_VENDOR_ID)
    #error "Fr_Flexray.c and Fr_IPW.h have different Vendor IDs"
#endif
/* Check if current file and Fr_IPW.h header file are of the same Autosar version */
#if((FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION_C    != FR_IPW_AR_RELEASE_MAJOR_VERSION) || \
    (FR_FLEXRAY_AR_RELEASE_MINOR_VERSION_C    != FR_IPW_AR_RELEASE_MINOR_VERSION) || \
    (FR_FLEXRAY_AR_RELEASE_REVISION_VERSION_C != FR_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_Flexray.c and Fr_IPW.h are different"
#endif
/* Check if current file and Fr_IPW.h header file are of the same software version */
#if((FR_FLEXRAY_SW_MAJOR_VERSION_C != FR_IPW_SW_MAJOR_VERSION) || \
    (FR_FLEXRAY_SW_MINOR_VERSION_C != FR_IPW_SW_MINOR_VERSION) || \
    (FR_FLEXRAY_SW_PATCH_VERSION_C != FR_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_Flexray.c and Fr_IPW.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if current file and Dem.h header file are of the same Autosar version */
        #if((FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
            (FR_FLEXRAY_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Fr_Flexray.c and Dem.h are different"
        #endif
    #endif /* FR_DISABLE_DEM_REPORT_ERROR_STATUS */
    
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if((FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (FR_FLEXRAY_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr_Flexray.c and Mcal.h are different"
    #endif

#endif /* CHECK_AUTOSAR_VERSION */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if(FR_RXSTRINGENTCHECK == STD_OFF)
    #define FLEXRAY_STRINGENT_MASK_AB 0x8080U
    #define FLEXRAY_STRINGENT_MASK_A  0x0080U
    #define FLEXRAY_STRINGENT_MASK_B  0x8000U 
#else
    #define FLEXRAY_STRINGENT_MASK_AB 0x8E8EU
    #define FLEXRAY_STRINGENT_MASK_A  0x008EU
    #define FLEXRAY_STRINGENT_MASK_B  0x8E00U
#endif


#define FR_START_SEC_CODE
/* Covers FR112 */
/* @violates @ref FR_FLEXRAY_C_REF_3 */
/* @violates @ref FR_FLEXRAY_C_REF_6 */
#include "Fr_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_TxBufferCfg(VAR(uint8, AUTOMATIC) ctrlIdx, P2CONST(Fr_CCLpduInfoType, AUTOMATIC, FR_APPL_CONST) TxLPduInfoPtr);
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_RxBufferCfg(VAR(uint8, AUTOMATIC) ctrlIdx, P2CONST(Fr_CCLpduInfoType, AUTOMATIC, FR_APPL_CONST) LPduInfoPointer);
static FUNC(void, FR_CODE) Fr_Flexray_ConfigureFifo(VAR(uint8, AUTOMATIC) ctrlIdx, P2CONST(Fr_CCFifoConfigType, AUTOMATIC, FR_APPL_CONST) CCFIFOConfigPtr);
static FUNC(void, FR_CODE) Fr_Flexray_GetProtocolState(VAR(uint16, AUTOMATIC) regValuePSR0, P2VAR(Fr_POCStateType, AUTOMATIC, FR_APPL_DATA) protStatePtr);
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetWakeupState(VAR(uint16, AUTOMATIC) regValuePSR0, P2VAR(Fr_WakeupStatusType, AUTOMATIC, FR_APPL_DATA) wakeupStatusPtr);
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetStartupState(VAR(uint16, AUTOMATIC) regValuePSR0, P2VAR(Fr_StartupStateType, AUTOMATIC, FR_APPL_DATA) startupStatePtr);
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetSlotMode(VAR(uint16, AUTOMATIC) regValuePSR0, P2VAR(Fr_SlotModeType, AUTOMATIC, FR_APPL_DATA) slotModePtr);
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetErrorMode(VAR(uint16, AUTOMATIC) regValuePSR0, P2VAR(Fr_ErrorModeType, AUTOMATIC, FR_APPL_DATA) errorModePtr);
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_WaitForCmdProcess(VAR(uint8, AUTOMATIC) ctrlIdx);
#if(FR_DEINIT_API == STD_ON)
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GoDefaultConfig(VAR(uint8, AUTOMATIC) u8CtrlIdx);
#endif
static FUNC(uint16, FR_CODE) Fr_Flexray_CalcHeaderCRC(CONST(uint16, AUTOMATIC) FrameId, CONST(uint16, AUTOMATIC) PayloadLen);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static FUNC(void, FR_CODE) Fr_Flexray_DemReport(P2CONST(Fr_CCRxBufferConfigType, AUTOMATIC, FR_APPL_CONST) prxCfgPtr_12, VAR(Dem_EventStatusType, AUTOMATIC) u16StatusReport );
#endif
static FUNC(void, FR_CODE) Fr_Flexray_ReadMB (
                                                VAR(uint8, AUTOMATIC) ctrlIdx,
                                                P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
                                                VAR(uint8, AUTOMATIC) u8tmpPayloadLen_12,
                                                VAR(uint8, AUTOMATIC) u8tmpMBIdx_12
                                             );
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_PrepareTxBuffer(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx, VAR(uint8, AUTOMATIC) u8tmpMBNum_31);
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_PrepareRxBuffer(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx, VAR(uint8, AUTOMATIC) u8tmpMBNum_31);
#endif
static INLINE FUNC(void, FR_CODE) Fr_Flexray_WriteRegister(VAR(uint8, AUTOMATIC) ctrlIdx, CONST(uint16, AUTOMATIC) regOffset, CONST(uint16, AUTOMATIC) regValue);
static INLINE FUNC(void, FR_CODE) Fr_Flexray_WriteRegister32(VAR(uint8, AUTOMATIC) ctrlIdx, CONST(uint16, AUTOMATIC) regOffset, CONST(uint32, AUTOMATIC) regValue);
static INLINE FUNC(uint16, FR_CODE) Fr_Flexray_ReadRegister(VAR(uint8, AUTOMATIC) ctrlIdx, CONST(uint16, AUTOMATIC) regOffset);
static INLINE FUNC(uint32, FR_CODE) Fr_Flexray_ReadRegister32(VAR(uint8, AUTOMATIC) ctrlIdx, CONST(uint16, AUTOMATIC) regOffset);
static INLINE FUNC(P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA), FR_CODE) Fr_Flexray_GetData16Pointer(CONST(uint32, AUTOMATIC) data16Address);
static INLINE FUNC(P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA), FR_CODE) Fr_Flexray_GetData32Pointer(CONST(uint32, AUTOMATIC) data32Address);
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/***************************************************************************************************
* @function_name    Fr_Flexray_DemReport
*
* @brief            FrIP function in order to report DEM error.
* @description      Report DEM error.
* @param[in]        prxCfgPtr_12  - Store the reference to Rx MB configuration 
* @param[in]        u16StatusReport - The status of DEM event.
***************************************************************************************************/
static FUNC(void, FR_CODE) Fr_Flexray_DemReport
(
    P2CONST(Fr_CCRxBufferConfigType, AUTOMATIC, FR_APPL_CONST) prxCfgPtr_12,
    VAR(Dem_EventStatusType, AUTOMATIC) u16StatusReport
)
{
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_LPDU_SLOTSTATUS;

    if(prxCfgPtr_12->DemFTSlotSTatusRefExist)
    {
        FR_E_LPDU_SLOTSTATUS = prxCfgPtr_12->DemFTSlotStatus;
        Dem_ReportErrorStatus(FR_E_LPDU_SLOTSTATUS, u16StatusReport);
    }
}
#endif
/***************************************************************************************************
* @function_name    Fr_Flexray_ReadMB
*
* @brief            FrIP function in order to read the contents into massage buffer.
* @description      Copy receive payload data
* @param[in]        ctrlIdx  - Controller index
* @param[in]        lsduPtr - Sdu pointer
* @param[in]        u8tmpPayloadLen_12 - Lenght of sdu
* @param[in]        u8tmpMBIdx_12 - MB index.
***************************************************************************************************/
static FUNC(void, FR_CODE) Fr_Flexray_ReadMB 
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
    VAR(uint8, AUTOMATIC) u8tmpPayloadLen_12,
    VAR(uint8, AUTOMATIC) u8tmpMBIdx_12
)
{
    VAR(uint8, AUTOMATIC) u8fr_p_12;  /* Temporary counter used for copying */
    VAR(uint8, AUTOMATIC) u8fr_o_12;  /* Temporary counter used for copying */
    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    VAR(uint32, AUTOMATIC) u32tmpdata;  /* Temporary variable for data */
    VAR(uint16, AUTOMATIC) u16tmpdata;  /* Temporary variable for data */
    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
    /* Pointer to data field in FR memory space in 32-bit format */
    P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA) pdataPtr32_12;
    /* Pointer to data field in FR memory space in 16-bit format */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pdataPtr16_12;

    /* Load MB Data pointer */
    /* Driver execution time optimization - data offset is not loaded 
    from structure of type Fr_CCLpduInfoType, */
    /* but from structure of type Fr_CCBufferOffsetType */
    /* Load MB Data pointer for 32-bit access */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    pdataPtr32_12 = Fr_Flexray_GetData32Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_12].MbDataAddrPtr);
    
    /* Data copying process - optimized for the speed */
    /* 32-bit copying process */
    /* Example: PayloadLength = 10 Bytes [0..7] */
    /* For data[B]<=4n, where n=PayloadLength/4 */
    for(u8fr_p_12 = 0U; u8fr_p_12 < (u8tmpPayloadLen_12 >> 1U); u8fr_p_12++)
    {
        /* Fr_CtrlIdx: Memory: Data Field */
        /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
        #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u32tmpdata = pdataPtr32_12[u8fr_p_12];
        u32tmpdata = (uint32)(((u32tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32) | ((u32tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32));
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_2 */
        ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_12] = u32tmpdata;
        #else
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_2 */
        /* @violates @ref FR_FLEXRAY_C_REF_6 */
        ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_12] = pdataPtr32_12[u8fr_p_12];
        #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
    }
    /* Example: first 8 Bytes are copied [0..7], u8fr_p_12 = 1+1 */
    /* Convert 32-bit counter of last copied byte to 16-bit counter */
    u8fr_o_12 = (VAR(uint8, AUTOMATIC))((u8fr_p_12 * 2U) & 0xFFU);
    
    /* 16-bit copying process */
    /* Copy the following two bytes only if((PayloadLength % 4) > 1) */
    /* @violates @ref FR_FLEXRAY_C_REF_6 */
    for(u8fr_p_12 = u8fr_o_12; u8fr_p_12 < u8tmpPayloadLen_12; u8fr_p_12++)
    {   
        /* Load MB Data pointer for 16-bit access */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_1 */
        /* @violates @ref FR_FLEXRAY_C_REF_11 */
        pdataPtr16_12 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_12].MbDataAddrPtr);
        /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
        #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16tmpdata = pdataPtr16_12[u8fr_p_12];
        u16tmpdata = (uint16)(((uint16)(u16tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16) | ((uint16)(u16tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16));
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_2 */
        ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_12] = u16tmpdata;
        #else
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_2 */
        ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_12] = pdataPtr16_12[u8fr_p_12];
        #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
    }   /* Example: next 2 Bytes are copied [8..9], u8fr_p_12 = 4+1 */
}
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Flexray_PrepareTxBuffer
*
* @brief            Fr function for the Fr_Flexray_PrepareLPdu function.
* @description      Prepare transmission buffer.
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be prepared.
* @param[in]        u8tmpMBNum_31 - Temporary variable for the MB index.
***************************************************************************************************/ 
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_PrepareTxBuffer
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx,
    VAR(uint8, AUTOMATIC) u8tmpMBNum_31
)
{
    VAR(uint16, AUTOMATIC) u16mbIdx_31;      /* The value of the MBIDX register */
    VAR(uint16, AUTOMATIC) u16mbRegOffset_31;   /* Temporary offset address of MB registers */
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_31 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16tmpVal1_31;    /* Temporary variable for register access */
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_31;
    /* Pointer to one instance of Fr_CCTxBufferConfigType */
    P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST) ptxCfgPtr_31;
    
    /* Temporary offset address of MB configuration registers */
    u16mbRegOffset_31 = (((VAR(uint16, AUTOMATIC))u8tmpMBNum_31) * 4U);
    /* Get the index from MBIDXn */
    u16mbIdx_31 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBIDXR0_ADDR16 + u16mbRegOffset_31);
    /* Store the reference to transmit buffer configuration */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    ptxCfgPtr_31 = (P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].BufferConfigPtr);
    
    /* MBIDXn must not be written because it could be changed by
    Rx shadow buffer index swap */
    u16mbIdx_31 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBIDXR0_ADDR16 + u16mbRegOffset_31);
    /* Check whether the index value is in expected range */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    if(u16mbIdx_31 <= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B2BufferIndexInit)
    {
        /* Disable appropriate MB */
        if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) & FLEXRAY_MBCCSR_EDS_U16))
        {
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31, FLEXRAY_MBCCSR_EDT_U16);
        }
        /* Check if buffer has been successfully disabled */
        if(FLEXRAY_MBCCSR_EDS_U16 != (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) & FLEXRAY_MBCCSR_EDS_U16))
        {
            /* Appropriate message buffer is disabled and can be reconfigured */
    
            /* Fr_CtrlIdx: FR_MBCCSRn: MTD */
            u16tmpVal1_31 = FLEXRAY_MBCCSR_MTD_U16;     /* Configure MB as Transmit */
            u16tmpVal1_31 |= FLEXRAY_MBCCSR_MBIF_U16;   /* Clear any pending interrupts */
            
            /* Store configuration into the FR_MBCCSRn register */
            /* Fr_CtrlIdx: FR_MBCCSRn */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31, u16tmpVal1_31);
            
            /* Configure FR_MBCCFRn register */
            u16tmpVal1_31 = 0U;      /* Clear variable */
            
            if(ptxCfgPtr_31->TxChannelAEnable)
            {
                u16tmpVal1_31 |= FLEXRAY_MBCCFR_CHA_U16;    /* Channel assignment - ch. A */
            }
            if(ptxCfgPtr_31->TxChannelBEnable)
            {
                u16tmpVal1_31 |= FLEXRAY_MBCCFR_CHB_U16;    /* Channel assignment - ch. B */
            }
            /* Assign Message Buffer in the dynamic segment to one channel only. 
            This is also as per the specification as it does'nt allow to assign a message buffer
            to both the channels in a dynamic segment. */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            if(((ptxCfgPtr_31->TxFrameID) > (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gNumberOfStaticSlots) && \
               (((VAR(boolean, AUTOMATIC))TRUE == (ptxCfgPtr_31->TxChannelAEnable)) && ((VAR(boolean, AUTOMATIC))TRUE == (ptxCfgPtr_31->TxChannelBEnable))) \
              )
            {
                u16tmpVal1_31 = FLEXRAY_MBCCFR_CHA_U16;
            }
            
            /* Cycle counter filter settings */
            /* Should the cycle counter filter be enabled? */
            if(ptxCfgPtr_31->TxCycleCounterFilterEnable)
            {
                /* Cycle counter filter value */
                u16tmpVal1_31 |= (VAR(uint16, AUTOMATIC))(ptxCfgPtr_31->TxCycleCounterFilterValue) & FLEXRAY_MBCCFR_CCFVAL_MASK_U16;
                /* Cycle counter filter mask */
                u16tmpVal1_31 |= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))(ptxCfgPtr_31->TxCycleCounterFilterMask) << 6U) & FLEXRAY_MBCCFR_CCFMSK_MASK_U16;
                /* Cycle counter filter enabled */
                u16tmpVal1_31 |= FLEXRAY_MBCCFR_CCFE_U16;
            }
            /* Store configuration into FR_MBCCFRn register */
            /* Fr_CtrlIdx: FR_MBCCFRn */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCFR0_ADDR16 + u16mbRegOffset_31, u16tmpVal1_31);
            
            /* Configure FR_MBFIDRn register */
            /* Fr_CtrlIdx: FR_MBFIDRn */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBFIDR0_ADDR16 + u16mbRegOffset_31, (VAR(uint16, AUTOMATIC))(ptxCfgPtr_31->TxFrameID & FLEXRAY_MBFIDR_FID_MASK_U16));
            
            /* Configure data field offset */
            /* According to a FlexRay Memory Layout described in FlexRay module documentation */
            
            /* Calculate the message buffer header */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            /* @violates @ref FR_FLEXRAY_C_REF_1 */
            /* @violates @ref FR_FLEXRAY_C_REF_11 */
            pheaderMBPtr_31 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u16mbIdx_31 * FLEXRAY_HEADER_SIZE);
            
            /* Configure Frame Header registers */
            /* Fr_CtrlIdx: Memory: FrameHeader: FID */
            u16tmpVal1_31 = (VAR(uint16, AUTOMATIC))(ptxCfgPtr_31->TxFrameID & 0x07FFU);    /* Frame ID */
            /* Fr_CtrlIdx: Memory: FrameHeader: PPI */
            /* Is the payload preamble indicator configured? */
            if(ptxCfgPtr_31->PayloadPreamble)
            {
                u16tmpVal1_31 |= FLEXRAY_FRAMEHEADER0_PPI_U16;  /* Configure Payload preamble indicator */
            }
            /* Fr_CtrlIdx: Memory: FrameHeader0 */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            pheaderMBPtr_31[0U] = u16tmpVal1_31;  /* Store the first word of Frame Header Section */
            
            u16tmpVal1_31 = 0U;            /* Clear temporary variable */
            /* Check if MB is configured for dynamic segment */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            if((ptxCfgPtr_31->TxFrameID) > (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gNumberOfStaticSlots)
            {
                /* Use configured payload length in dynamic segment */
                u16tmpVal1_31 |= ((VAR(uint16, AUTOMATIC))(ptxCfgPtr_31->TxPayloadLength) & 0x7FU);
            }
            else
            {
                /* Use gPayloadLengthStatic for all frames in static segment */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                u16tmpVal1_31 |= ((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gPayloadLengthStatic) & 0x7FU);
            }
            
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            pheaderMBPtr_31[1U] = u16tmpVal1_31;   /* Store the second word of Frame Header Section */
            
            /* Fr_CtrlIdx: Memory: FrameHeader2 */
            u16tmpVal1_31 = 0U;            /* Clear temporary variable */
            u16tmpVal1_31 |= (ptxCfgPtr_31->HeaderCRC & 0x07FFU);       /* Header CRC */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            pheaderMBPtr_31[2U] = u16tmpVal1_31;   /* Store the third word of Frame Header Section */
            
            /* Enable message buffer */
            SchM_Enter_Fr_FR_EXCLUSIVE_AREA_07();
            u16tmpVal1_31 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) | FLEXRAY_MBCCSR_EDT_U16);
            
            /* Enable the MB in the FR_MBCCSRn register */
            /* Fr_CtrlIdx: FR_MBCCSRn */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31, u16tmpVal1_31);
            SchM_Exit_Fr_FR_EXCLUSIVE_AREA_07();
            /* Check if buffer has been successfully enabled */
            if(FLEXRAY_MBCCSR_EDS_U16 == ((Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) & FLEXRAY_MBCCSR_EDS_U16)))
            {
                /* Yes */
                retVal_31 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
        }
    }
    return retVal_31;
}
/***************************************************************************************************
* @function_name    Fr_Flexray_PrepareRxBuffer
*
* @brief            Fr function for the Fr_Flexray_PrepareLPdu function.
* @description      Prepare transmission buffer.
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be prepared.
* @param[in]        u8tmpMBNum_31 - Temporary variable for the MB index.
***************************************************************************************************/ 
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_PrepareRxBuffer
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx,
    VAR(uint8, AUTOMATIC) u8tmpMBNum_31
)
{
    VAR(uint16, AUTOMATIC) u16mbIdx_31;      /* The value of the MBIDX register */
    VAR(uint16, AUTOMATIC) u16mbRegOffset_31;   /* Temporary offset address of MB registers */
    VAR(uint16, AUTOMATIC) u16tmpVal1_31;    /* Temporary variable for register access */
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_31;
    /* Pointer to one instance of Fr_CCRxBufferConfigType */
    P2CONST(Fr_CCRxBufferConfigType, AUTOMATIC, FR_APPL_CONST) prxCfgPtr_31;
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_31 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

    /* prxCfgPtr_31 points to configuration referenced by Fr_BufConfSetIdx */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    prxCfgPtr_31 = (P2CONST(Fr_CCRxBufferConfigType, AUTOMATIC, FR_APPL_CONST))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].BufferConfigPtr);
    /* Temporary offset address of MB configuration registers */
    u16mbRegOffset_31 = (((VAR(uint16, AUTOMATIC))u8tmpMBNum_31) * 4U);
    /* Get the index from MBIDXn */
    u16mbIdx_31 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBIDXR0_ADDR16 + u16mbRegOffset_31);
    /* Check whether the index value is in expected range */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    if(u16mbIdx_31 <= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B2BufferIndexInit)
    {
        /* Disable appropriate MB */
        if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) & FLEXRAY_MBCCSR_EDS_U16))
        {
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31, FLEXRAY_MBCCSR_EDT_U16);
        }
        /* Check if buffer has been successfully disabled */
        if(FLEXRAY_MBCCSR_EDS_U16 != (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) & FLEXRAY_MBCCSR_EDS_U16))
        {
            /* Yes */
            /* Appropriate message buffer is disabled and can be configured */
            /* Fr_CtrlIdx: FR_MBCCSRn */
            u16tmpVal1_31 = 0U;      /* Clear variable */
            /* Store configuration into the FR_MBCCSRn register */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31, u16tmpVal1_31);
            
            /* Configure FR_MBCCFRn register */
            u16tmpVal1_31 = 0U;      /* Clear variable */
            if(prxCfgPtr_31->RxChannelAEnable)
            {
                u16tmpVal1_31 |= FLEXRAY_MBCCFR_CHA_U16;    /* Channel assignment - ch. A */
            }
            if(prxCfgPtr_31->RxChannelBEnable)
            {
                u16tmpVal1_31 |= FLEXRAY_MBCCFR_CHB_U16;    /* Channel assignment - ch. B */
            }
            /* Cycle counter filter settings */
            /* Should the cycle counter filter be enabled? */
            if(prxCfgPtr_31->RxCycleCounterFilterEnable)
            {
                /* Cycle counter filter value */
                u16tmpVal1_31 |= (VAR(uint16, AUTOMATIC))(prxCfgPtr_31->RxCycleCounterFilterValue) & FLEXRAY_MBCCFR_CCFVAL_MASK_U16;
                /* Cycle counter filter mask */
                u16tmpVal1_31 |= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))(prxCfgPtr_31->RxCycleCounterFilterMask) << 6U) & FLEXRAY_MBCCFR_CCFMSK_MASK_U16;
                /* Cycle counter filter enabled */
                u16tmpVal1_31 |= FLEXRAY_MBCCFR_CCFE_U16;
            }
            
            /* Store configuration into FR_MBCCFRn register */
            /* Fr_CtrlIdx: FR_MBCCFRn */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCFR0_ADDR16 + u16mbRegOffset_31, u16tmpVal1_31);
            
            /* Configure FR_MBFIDRn register */
            /* Fr_CtrlIdx: FR_MBFIDRn */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBFIDR0_ADDR16 + u16mbRegOffset_31, (VAR(uint16, AUTOMATIC))(prxCfgPtr_31->RxFrameID & FLEXRAY_MBFIDR_FID_MASK_U16));
            
            /* Calculate the message buffer header */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            /* @violates @ref FR_FLEXRAY_C_REF_1 */
            /* @violates @ref FR_FLEXRAY_C_REF_11 */
            pheaderMBPtr_31 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u16mbIdx_31 * FLEXRAY_HEADER_SIZE);
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            pheaderMBPtr_31[FLEXRAY_HEADER_SIZE - 1U] = 0x00U;
            
            /* Enable message buffer */
            SchM_Enter_Fr_FR_EXCLUSIVE_AREA_07();
            u16tmpVal1_31 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) | FLEXRAY_MBCCSR_EDT_U16);
            /* Enable the MB in the FR_MBCCSRn register */
            /* Fr_CtrlIdx: FR_MBCCSRn */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31, u16tmpVal1_31);
            if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) & FLEXRAY_MBCCSR_EDS_U16))
            {
                /* Yes */
                /* Clear Buffer Interrupt Flag which is set after MB enabling */
                /* Select only necessary bits */
                u16tmpVal1_31 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31) & FLEXRAY_MBCCSR0_CONFIG_MASK_U16);
                u16tmpVal1_31 |= FLEXRAY_MBCCSR_MBIF_U16;      /* Set MBIF flag - clear Rx MB interrupt flag */
                /* Fr_CtrlIdx: FR_MBCCSR */
                /* Clear Transmit Buffer Interrupt Flag */
                Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_31, u16tmpVal1_31);
                
                retVal_31 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            SchM_Exit_Fr_FR_EXCLUSIVE_AREA_07();
        }
    }
    return retVal_31;
}
#endif /* FR_PREPARE_LPDU_SUPPORT == STD_ON */
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef IPV_FLEXRAY
#ifdef FR_ACCESS_ERROR_NOTIFICATION_EN
/***************************************************************************************************
* @function_name    Fr_Flexray_ReadValueRegister
*
* @description      Read value of register
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        RegisterAdress - Register Adress
* @return           :uint16 - Register value
***************************************************************************************************/
FUNC(uint16, FR_CODE) Fr_Flexray_ReadValueRegister
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) RegisterAdress
)
{
    return Fr_Flexray_ReadRegister(ctrlIdx,RegisterAdress);
}
/***************************************************************************************************
* @function_name    Fr_Flexray_WriteValueRegister
*
* @description      Write value of register
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        RegisterAdress - Register Adress
* @param[in]        RegisterValue - Register value
* @return           void
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_WriteValueRegister
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) RegisterAdress,
    VAR(uint16, AUTOMATIC) RegisterValue
)
{
    Fr_Flexray_WriteRegister(ctrlIdx,RegisterAdress,RegisterValue);
}
#endif /* FR_ACCESS_ERROR_NOTIFICATION_EN */
#endif /* IPV_FLEXRAY */
/***************************************************************************************************
* @function_name    Fr_Flexray_CCInit
*
* @brief            FrIP function for FlexRay CC configuration
* @description      Writes values from configuration file into the Module Configuration Register
* @param[in]        ctrlIdx - Index of FlexRay CC  
* @return           none
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_CCInit
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_28 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16regVal_28 = 0U;  /* Temporary variable for register access */
    
#ifndef IPV_FLEXRAY
    /* Check if FR CC is enabled */
    if(FLEXRAY_MCR_MEN_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MCR_ADDR16) & FLEXRAY_MCR_MEN_U16))
    {/* MEN bit is set, FR CC is enabled */
    #ifdef ERR_IPV_FLEXRAY_0002
        #if(ERR_IPV_FLEXRAY_0002 == STD_ON)
        /* Move FR CC to HALT state */                                  
        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(ctrlIdx, FLEXRAY_POCR_CMD_HALT_U16))
        #else
            #error : the define ERR_IPV_FLEXRAY_0002 must not be STD_OFF
        #endif
    #else
        /* Move FR CC to FREEZE state */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(ctrlIdx, FLEXRAY_POCR_CMD_FREEZE_U16))
    #endif /* ERR_IPV_FLEXRAY_0002 */
        {   /* Move FR CC to DEFAULT CONFIG state */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(ctrlIdx, FLEXRAY_POCR_CMD_DEFAULTCONFIG_U16))
            {   /* Wait for DEFAULT CONFIG POC state or timeout expiration */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForPOCState(ctrlIdx, FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16))
                {
                    /* Clear MEN bit in FLEXRAY_MCR_ADDR16 register, disable FR CC */
                    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MCR_ADDR16, 0U);
                }
            }
        }
    }
    
    /* Check if FR CC is disabled */
    if(0U == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MCR_ADDR16) & FLEXRAY_MCR_MEN_U16))
    {
        /* MEN bit is cleared, is possible to change configuration */
#endif /* IPV_FLEXRAY */
        /* Configuration of the device operation mode */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        if ((VAR(boolean, AUTOMATIC))TRUE == (Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->SingleChannelModeEnabled)
        {
            u16regVal_28 |= FLEXRAY_MCR_SCM_U16;            /* Single chip mode */
        }
        
        /* FlexRay channel configuration, see FR module documentation for detailed description */
        /* of the single and dual channel mode */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        switch((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->Channels)
        {
            case FR_CHANNEL_A:
                /* Dual mode - port A enabled, single mode - port A enabled */
                u16regVal_28 |= FLEXRAY_MCR_CHA_U16;
            break;
            case FR_CHANNEL_B:
                 /* Dual mode - port B enabled, single mode - port A enabled,
                internal channel A behaves as channel B */
                u16regVal_28 |= FLEXRAY_MCR_CHB_U16;
        #ifdef ERR_IPV_FLEXRAY_0005
            #if(ERR_IPV_FLEXRAY_0005 == STD_ON)
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                if ((VAR(boolean, AUTOMATIC))TRUE != (Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->SingleChannelModeEnabled)
                {
                     u16regVal_28 |= FLEXRAY_MCR_CHA_U16;
                }
            #else
                #error : the define ERR_IPV_FLEXRAY_0005 must not be STD_OFF
            #endif
        #endif
            break;
            case FR_CHANNEL_AB:
                /* Dual mode - both ports enabled, single mode - no ports enabled */
                u16regVal_28 |=(VAR(uint16,AUTOMATIC)) (FLEXRAY_MCR_CHA_U16 | FLEXRAY_MCR_CHB_U16);
            break;
            default:
            break;
        }
        
        /* FlexRay Protocol Engine clock selection */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        switch((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->ClockSource)
        {
            case FR_CLK_SRC_PLL:
                /* Use on-chip PLL bus clock as PE clock source */
                u16regVal_28 |= FLEXRAY_MCR_CLKSEL_U16;
            break;
            case FR_CLK_SRC_CRYSTAL_OSCILLATOR:
                /* Use on-chip crystal oscillator as PE clock source */
                u16regVal_28 &= ~FLEXRAY_MCR_CLKSEL_U16;
            break;
            default:
            break;
        }

        /* FlexRay Channel Bit Rate selection */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16regVal_28 |= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->Bitrate) << 1U) & FLEXRAY_MCR_BITRATE_MASK_U16;
        
        /* Write to MCR reg. before enabling the FR module */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MCR_ADDR16, u16regVal_28);

        /* Store the value of the timeout bit field in the SYMATOR register */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_SYMATOR_ADDR16, (VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->Timeout));

        /* Initialize the FlexRay Memory Start address */
        /* @violates @ref FR_FLEXRAY_C_REF_1 */
        /* @violates @ref FR_FLEXRAY_C_REF_11 */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_SYMBADHR_ADDR16, (VAR(uint16, AUTOMATIC))(((uint32)((*((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr)).CCFlexRayMemoryBaseAddress)) >> 16U));
        /* @violates @ref FR_FLEXRAY_C_REF_1 */
        /* @violates @ref FR_FLEXRAY_C_REF_11 */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_SYMBADLR_ADDR16, (VAR(uint16, AUTOMATIC))(((uint32)((*((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr)).CCFlexRayMemoryBaseAddress)) & FLEXRAY_SYMBADLR_SMBA_MASK_U16));
        
        /* Set FlexRay Module Enable Bit */
        u16regVal_28 |= FLEXRAY_MCR_MEN_U16;
        
        /* Configure FLEXRAY_MCR_ADDR16 register */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MCR_ADDR16, u16regVal_28);
        
        returnValue_28 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
#ifndef IPV_FLEXRAY
    }
#endif /* IPV_FLEXRAY */
    
    return returnValue_28;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_ClusterNodeParamCfg
*
* @brief            FrIP function for cluster and node parameters configuration
* @description      Writes values from configuration file into the FlexRay CC 
*                   Protocol Configuration Registers
* @param[in]        ctrlIdx - Index of FlexRay CC  
* @param[out]       none
* @return           none
*
* @implements       Fr_Flexray_ClusterNodeParamCfg_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_ClusterNodeParamCfg
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR0_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR0_1);     /* PCR0_1   regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR2_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR2_3);     /* PCR2_3   regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR4_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR4_5);     /* PCR4_5   regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR6_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR6_7);     /* PCR6_7   regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR8_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR8_9);     /* PCR8_9   regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR10_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR10_11);  /* PCR10_11 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR12_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR12_13);  /* PCR12_13 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR14_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR14_15);  /* PCR14_15 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR16_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR16_17);  /* PCR16_17 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR18_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR18_19);  /* PCR18_19 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR20_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR20_21);  /* PCR20_21 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR22_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR22_23);  /* PCR22_23 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR24_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR24_25);  /* PCR24_25 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR26_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR26_27);  /* PCR26_27 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister32(ctrlIdx, FLEXRAY_PCR28_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR28_29);  /* PCR28_29 regs. config */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PCR30_ADDR16, (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR30);       /* PCR30    reg.  config */
    
    /* Configure FLEXRAY_NMVLR_ADDR16 register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_NMVLR_ADDR16, (uint16)(Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gNetworkManagementVectorLength);
    /* Configure FLEXRAY_SFTOR_ADDR16 register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_SFTOR_ADDR16, (Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->SyncFrameTableOffset);
    /* Configure FLEXRAY_SFTCCSR_ADDR16 to set sync frame table to continuous mode */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_SFTCCSR_ADDR16, FLEXRAY_SFTCCSR_SIDEN_U16);
    
}

/***************************************************************************************************
* @function_name    Fr_Flexray_ClearDisableIRQs
*
* @brief            FrIP function which clears all interrupt flags and disables all interrupts.
* @details          Function clears all MBIF flags and clears GIFER, PIFR0, PIFR1, PIER0 and PIER1
*                   registers.
* @param[in]        ctrlIdx - Index of FlexRay CC          
* @return           ::Std_ReturnType
*                       - E_OK      All interrupt flags were cleared and all interrupts were
*                                   disabled
*                       - E_NOT_OK  Some interrupt flag was not clear or some interrupt was not
*                                   disabled
*
* @implements      Fr_Flexray_ClearDisableIrqs_Activity 
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_ClearDisableIRQs
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_155 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);  
    VAR(uint16, AUTOMATIC) u16regVal_155;    /* Temporary variable for register access */
    VAR(uint16, AUTOMATIC) u16timeout_155;  /* Temp variable for never-ending while loop protection */
    VAR(boolean, AUTOMATIC) bEnd_155 = (VAR(boolean, AUTOMATIC))FALSE;  /* wait cycle finish or not */
    VAR(boolean, AUTOMATIC) bEnd2_155 = (VAR(boolean, AUTOMATIC))FALSE; /* wait cycle finish or not */
    VAR(uint16, AUTOMATIC) u16tmpVal_155;

    /* Clear MBIF flags and disable MB interrupts(MBIE), loop over all message buffers */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_00();
    for(u16tmpVal_155 = 0U; u16tmpVal_155 < FR_NUMBER_MB; u16tmpVal_155++)
    {
        u16regVal_155 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + (u16tmpVal_155 * 4U));
        /* Clear CMT and MBIE */
        u16regVal_155 &= ~(FLEXRAY_MBCCSR_CMT_U16 | FLEXRAY_MBCCSR_MBIE_U16);
        u16regVal_155 |= FLEXRAY_MBCCSR_MBIF_U16; /* Clear MBIF */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + (u16tmpVal_155 * 4U), u16regVal_155);
    }

    u16timeout_155 = 0U;
    /* Clear FIFO FNEBIF&FNEAIF flags - loop until FNEBIF&FNEAIF are not set, or timeout expired */
    while(((VAR(boolean, AUTOMATIC))FALSE == bEnd_155) && ((VAR(boolean, AUTOMATIC))FALSE == bEnd2_155))
    {
        u16regVal_155 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16);     
        /* Check FNEAIF and FNEBIF */
        if((FLEXRAY_GIFER_FNEAIF_U16 == (u16regVal_155 & FLEXRAY_GIFER_FNEAIF_U16)) || (FLEXRAY_GIFER_FNEBIF_U16 == (u16regVal_155 & FLEXRAY_GIFER_FNEBIF_U16)))
        {
            /* Clear FNEAIF and FNEBIF */
            u16regVal_155 |= (FLEXRAY_GIFER_FNEAIF_U16 | FLEXRAY_GIFER_FNEBIF_U16);
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16, u16regVal_155);
        }
        else
        {/* FIFO interrupts are not set */
            bEnd_155 = (VAR(boolean, AUTOMATIC))TRUE;
        }
        
        if(u16timeout_155 > 255U)
        {/* timeout has expired */
            bEnd2_155 = (VAR(boolean, AUTOMATIC))TRUE;
        }
        u16timeout_155++;
    }
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_00();
    
    /* Verify timeout occured */
    if((VAR(boolean, AUTOMATIC))FALSE == bEnd2_155)
    {
        /* Clear all interrupt flags */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16,(VAR(uint16,AUTOMATIC))(FLEXRAY_GIFER_WUPIF_U16 | ((VAR(uint16, AUTOMATIC))(FLEXRAY_GIFER_FNEBIF_U16 | FLEXRAY_GIFER_FNEAIF_U16))));
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIFR0_ADDR16, 0xFFFFU);
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIFR1_ADDR16, 0xFFFFU);
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_CHIERFR_ADDR16, 0xFFFFU);
        
        /* Disable all FlexRay interrupts */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16, 0U);
        /* Check that interupts were disabled and no interrupt is pending */
        if(0U == Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16))
        {
            /* Disable interrupts */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIER0_ADDR16, 0U);
            /* Check that interupts were disabled */
            if(0U == Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PIER0_ADDR16))
            {
                /* Disable interrupts */
                Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIER1_ADDR16, 0U);
                /* Check that interupts were disabled */
                if(0U == Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PIER1_ADDR16))
                {
                    /* All interrupts were disabled */
                    returnValue_155 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                }
            }
        }
    }
    return returnValue_155;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_RxBufferCfg
*
* @brief            FrIP function for receive message buffer configuration
* @details          This function will configure selected message buffer as a receive
*                   message buffer
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        LPduInfoPointer Pointer to the structure with information for message buffer
*                   configuration.
* @return           ::Std_ReturnType
*                       - E_OK      Message buffer was successfully configured
*                       - E_NOT_OK  Error occured within message buffer enabling/disabling
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_RxBufferCfg
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2CONST(Fr_CCLpduInfoType, AUTOMATIC, FR_APPL_CONST) LPduInfoPointer
)
{
    /* rxCfgPtr_104 points to configuration referenced by Fr_BufConfSetIdx */
    P2CONST(Fr_CCRxBufferConfigType, AUTOMATIC, FR_APPL_CONST) prxCfgPtr_104 = (P2CONST(Fr_CCRxBufferConfigType, AUTOMATIC, FR_APPL_CONST))(LPduInfoPointer->BufferConfigPtr);
    /* Offset from FR base address to the MB registers */
    VAR(volatile uint16, AUTOMATIC) u16mbRegOffset_104 = (((VAR(uint16, AUTOMATIC))LPduInfoPointer->MessageBufferNumber) * 4U);
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_104;
    /* Temporary variable for register access */
    VAR(uint16, AUTOMATIC) u16regVal_104;
    /* Temporary return value to signal succes or failure of this function */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_104 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);

    /* Disable appropriate MB */
    if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_104) & FLEXRAY_MBCCSR_EDS_U16))
    {
        /* Disable it */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_104, FLEXRAY_MBCCSR_EDT_U16);
    }
    /* Check if buffer has been successfully disabled */
    if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_104) & FLEXRAY_MBCCSR_EDS_U16))
    {
        returnValue_104 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK); /* Signal error */
    }
    else
    {
        /* Appropriate message buffer is disabled and can be configured */
        /***************************** Configure FR_MBCCSRn register ********************************/
        u16regVal_104 = 0U;          /* Clear variable */
        /* Store configuration into the FR_MBCCSRn register */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_104, u16regVal_104);

        /******************************** Configure FR_MBCCFRn register *****************************/
        u16regVal_104 = 0U;                          /* Clear variable */
        if(prxCfgPtr_104->RxChannelAEnable)
        {
            u16regVal_104 |= FLEXRAY_MBCCFR_CHA_U16;      /* Channel assignment - ch. A */
        }
        if(prxCfgPtr_104->RxChannelBEnable)
        {
            u16regVal_104 |= FLEXRAY_MBCCFR_CHB_U16;      /* Channel assignment - ch. B */
        }
        /* Cycle counter filter settings */
        /* Should the cycle counter filter be enabled? */
        if(prxCfgPtr_104->RxCycleCounterFilterEnable)
        {
            /* Cycle counter filter value */
            u16regVal_104 |= (VAR(uint16, AUTOMATIC))(prxCfgPtr_104->RxCycleCounterFilterValue) & FLEXRAY_MBCCFR_CCFVAL_MASK_U16;
            /* Cycle counter filter mask */
            u16regVal_104 |= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))(prxCfgPtr_104->RxCycleCounterFilterMask) << 6U) & FLEXRAY_MBCCFR_CCFMSK_MASK_U16;
            /* Cycle counter filter enabled */
            u16regVal_104 |= FLEXRAY_MBCCFR_CCFE_U16;
        }

        /* Store configuration into FR_MBCCFRn register */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCFR0_ADDR16 + u16mbRegOffset_104, u16regVal_104);

        /**************************** Configure FR_MBIDXRn register *********************************/
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBFIDR0_ADDR16 + u16mbRegOffset_104, prxCfgPtr_104->RxFrameID);

        /********************************* Configure FR memory ***********************************/
        /* According to a FlexRay Memory Layout described in FlexRay module documentation */

        /* Calculate the message buffer header:
           FR_memory_base_address + (Configuring_MB_number * MB_header_length) */    
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_1 */
        /* @violates @ref FR_FLEXRAY_C_REF_11 */
        pheaderMBPtr_104 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (LPduInfoPointer->MessageBufferNumber * FLEXRAY_HEADER_SIZE);
        /* Configure Frame Header registers */
        /* Fr_CtrlIdx: Memory: FrameHeader3 */
        u16regVal_104 = 0U;            /* Clear temporary variable */
        /* Data offset load from structure of type BufferOffsetTable */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16regVal_104 |= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferOffsetTable[LPduInfoPointer->MessageBufferNumber].DataOffset16;
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
        /* Store Data Field Offset to Frame header register */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_104[3U] = u16regVal_104;
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else
        /* Store Data Field Offset into the FR_MBDORx register */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBDOR0_ADDR16 + (LPduInfoPointer->MessageBufferNumber), u16regVal_104);
#endif /* IPV_FLEXRAY */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_104[FLEXRAY_HEADER_SIZE - 1U] = 0x00U;   /* Clear slot status */

        /******************************** Configure FR_MBIDXRn register *****************************/
        /* Message Buffer Index Registers initialization */
        /* Fr_CtrlIdx: FR_MBIDXRn */
        u16regVal_104 = LPduInfoPointer->MessageBufferNumber;
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBIDXR0_ADDR16 + u16mbRegOffset_104, u16regVal_104);
        
        /* MB for LPdu wich is Reconfigurable stays disabled */
        if((VAR(boolean, AUTOMATIC))FALSE == (LPduInfoPointer->Reconfigurable))
        {
            /* Enable message buffer */
            SchM_Enter_Fr_FR_EXCLUSIVE_AREA_10();
            u16regVal_104 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_104) | FLEXRAY_MBCCSR_EDT_U16);
            /* Enable the MB in the FR_MBCCSRn register */
            /* Fr_CtrlIdx: FR_MBCCSRn */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_104, u16regVal_104);
            SchM_Exit_Fr_FR_EXCLUSIVE_AREA_10();
            /* Check if buffer is again enabled */
            if(FLEXRAY_MBCCSR_EDS_U16 != (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_104) & FLEXRAY_MBCCSR_EDS_U16))
            {/* No */
                returnValue_104 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK); /* Signal error */
            }
        }
    }
    return returnValue_104;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_TxBufferCfg
*
* @brief            FrIP function for transmit message buffer configuration
* @details          This function will configure selected message buffer as a transmit
*                   message buffer
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        LPduInfoPointer Pointer to the structure with information for configuring MB
* @return           ::Std_ReturnType
*                       - E_OK      Message buffer was successfully configured
*                       - E_NOT_OK  Error occured within message buffer enabling/disabling
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_TxBufferCfg
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2CONST(Fr_CCLpduInfoType, AUTOMATIC, FR_APPL_CONST) TxLPduInfoPtr
)
{
    /* Temporary variable for register access */
    VAR(uint16, AUTOMATIC) u16regVal_105;
    /* Offset from FR base address to the MB registers */
    VAR(volatile uint16, AUTOMATIC) u16mbRegOffset_105 = (((VAR(uint16, AUTOMATIC))TxLPduInfoPtr->MessageBufferNumber) * 4U);
    /* Pointer to the structure which contains all configuration data for transmit buffer */
    P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST) ptxCfgPtr_105;
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_105;
    /* Temporary variable to signal success or failure */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_105 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);

    /* Get pointer to the transmit message buffer structure*/
    ptxCfgPtr_105 = (P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST))(TxLPduInfoPtr->BufferConfigPtr);
    /* Disable appropriate MB if enabled */
    if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_105) & FLEXRAY_MBCCSR_EDS_U16))
    {
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_105, FLEXRAY_MBCCSR_EDT_U16);
    }
    /* Check if the buffer has been disabled */
    if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_105) & FLEXRAY_MBCCSR_EDS_U16))
    {
        /* No, buffer has not been disabled -> signal failure */
        returnValue_105 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    else
    {
        /* Appropriate message buffer is disabled and can be configured */
        /************************** Configure FR_MBCCSRn register ***********************************/
        u16regVal_105 = FLEXRAY_MBCCSR_MTD_U16;    /* Set FR_MBCCSRn: MTD -> Configure MB as Transmit */

        /* Store configuration into the FR_MBCCSRn register*/
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_105, u16regVal_105);
        /************************** Configure FR_MBCCFRn register ***********************************/
        u16regVal_105 = 0U;      /* Clear default register value */
        
        /* Transmit on channel A enabled? */
        if(ptxCfgPtr_105->TxChannelAEnable)
        {
            u16regVal_105 |= FLEXRAY_MBCCFR_CHA_U16;    /* Channel assignment - ch. A */
        }
        /* Transmit on channel B enabled? */
        if(ptxCfgPtr_105->TxChannelBEnable)
        {
            u16regVal_105 |= FLEXRAY_MBCCFR_CHB_U16;    /* Channel assignment - ch. B */
        }  
        /* errata e6858715 fix 
        Assign Message Buffer in the dynamic segment to one channel only. 
        This is also as per the specification as it does'nt allow to assign a message buffer to 
        both the channels in a dynamic segment. */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        if((ptxCfgPtr_105->TxFrameID) > (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gNumberOfStaticSlots)
        {
            if(((VAR(boolean, AUTOMATIC))TRUE == (ptxCfgPtr_105->TxChannelAEnable)) && ((VAR(boolean, AUTOMATIC))TRUE == (ptxCfgPtr_105->TxChannelBEnable)))
            {
                u16regVal_105 = FLEXRAY_MBCCFR_CHA_U16;
            }
        }
        
        /* Cycle counter filter settings */
        /* Should the cycle counter filter be enabled? */
        if(ptxCfgPtr_105->TxCycleCounterFilterEnable)
        {
            /* Store cycle counter filter value */
            u16regVal_105 |= (VAR(uint16, AUTOMATIC))(ptxCfgPtr_105->TxCycleCounterFilterValue) & FLEXRAY_MBCCFR_CCFVAL_MASK_U16;
            /* Store cycle counter filter mask */
            u16regVal_105 |= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))(ptxCfgPtr_105->TxCycleCounterFilterMask) << 6U) & FLEXRAY_MBCCFR_CCFMSK_MASK_U16;
            /* Enable cycle counter filter for this message buffer*/
            u16regVal_105 |= FLEXRAY_MBCCFR_CCFE_U16;
        }
        /* Store configuration into FR_MBCCFRn register */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCFR0_ADDR16 + u16mbRegOffset_105, u16regVal_105);
        /******************************* Configure FR_MBFIDRn register ******************************/
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBFIDR0_ADDR16 + u16mbRegOffset_105, (VAR(uint16, AUTOMATIC))(ptxCfgPtr_105->TxFrameID & FLEXRAY_MBFIDR_FID_MASK_U16));
        /********************************* Configure FR memory ***********************************/
        /* Configure data field offset according to Memory Layout described in FR module doc. */
        /* Calculate the message buffer header */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_1 */
        /* @violates @ref FR_FLEXRAY_C_REF_11 */
        pheaderMBPtr_105 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (TxLPduInfoPtr->MessageBufferNumber * FLEXRAY_HEADER_SIZE);
        /* Configure Message Buffer Header Registers */
        /* Configure frame header */

        /* Store frame ID (FrameHeader: FID) */
        u16regVal_105 = (VAR(uint16, AUTOMATIC))(ptxCfgPtr_105->TxFrameID & 0x07FFU);
        /* Fr_CtrlIdx: Memory: FrameHeader: PPI */
        /* Is the payload preamble indicator configured? */
        if(ptxCfgPtr_105->PayloadPreamble)
        {
            u16regVal_105 |= FLEXRAY_FRAMEHEADER0_PPI_U16;  /* Configure Payload preamble indicator */
        }
        /* Frame header 0-1 byte */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_105[0U] = u16regVal_105;       /* Store the first word of Frame Header Section */

        /* Frame header 2-3 byte - payload length */
        u16regVal_105 = 0U;                    /* Clear temporary variable */
        /* Check if MB is configured for dynamic segment */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        if((ptxCfgPtr_105->TxFrameID) > (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gNumberOfStaticSlots)
        {
            /* Use configured payload length in dynamic segment */
            u16regVal_105 |= ((VAR(uint16, AUTOMATIC))(ptxCfgPtr_105->TxPayloadLength) & 0x7FU);
        }
        else
        {
            /* Use gPayloadLengthStatic for all frames in static segment */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            u16regVal_105 |= ((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gPayloadLengthStatic) & 0x7FU);
        }

        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_105[1U] = u16regVal_105;       /* Store the second word of Frame Header Section */

        /* Frame header 4-5 byte */
        u16regVal_105 = 0U;                    /* Clear temporary variable */
        u16regVal_105 |= (ptxCfgPtr_105->HeaderCRC & 0x07FFU);          /* Header CRC */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_105[2U] = u16regVal_105;        /* Store the third word of Frame Header Section */

        /* Configure data field offset */
        /* Data field offset 0-1 byte */
        u16regVal_105 = 0U;                    /* Clear temporary variable */
        /* Data offset is loaded from the structure of type BufferOffsetTable */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16regVal_105 |= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferOffsetTable[TxLPduInfoPtr->MessageBufferNumber].DataOffset16;
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
        /* Store Data Field Offset to Frame header register */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_105[3U] = u16regVal_105;
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else
        /* Store Data Field Offset into the FR_MBDORx register FRIPI V10*/
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBDOR0_ADDR16 + (TxLPduInfoPtr->MessageBufferNumber), u16regVal_105);
#endif /* IPV_FLEXRAY */

        /****************************** Configure FR_MBIDXRn register *******************************/
        /* Message Buffer Index Registers initialization */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBIDXR0_ADDR16 + u16mbRegOffset_105, (uint16)(TxLPduInfoPtr->MessageBufferNumber));
        /* MB for LPdu wich is Reconfigurable stays disabled */
        if((VAR(boolean, AUTOMATIC))FALSE == (TxLPduInfoPtr->Reconfigurable))
        {
            /* Enable message buffer */
            /* Trigger only EDT bit in FR_MBIDXRn register */
            SchM_Enter_Fr_FR_EXCLUSIVE_AREA_11();
            u16regVal_105 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_105) | FLEXRAY_MBCCSR_EDT_U16);
            /* Enable the MB in the FR_MBCCSRn register by writing the new value */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_105, u16regVal_105);
            SchM_Exit_Fr_FR_EXCLUSIVE_AREA_11();
            /* Check if buffer has been successfully reenabled */
            if(FLEXRAY_MBCCSR_EDS_U16 != (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_105) & FLEXRAY_MBCCSR_EDS_U16))
            {
                /* No, signal the failure */
                returnValue_105 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            }
        }
    }
    return returnValue_105;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_ConfigureFifo
*
* @brief            FrIP function for receive FIFO configuration
* @details          This function will configure receive FIFO
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        CCFIFOConfigPtr Pointer to the structure with information for configuring MB
* @return           none
***************************************************************************************************/
static FUNC(void, FR_CODE) Fr_Flexray_ConfigureFifo
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2CONST(Fr_CCFifoConfigType, AUTOMATIC, FR_APPL_CONST) CCFIFOConfigPtr
)
{
    /* Temporary variable for register access */
    VAR(uint16, AUTOMATIC) u16regVal_103 = 0U;
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
    /* Temporary variable for register access */
    VAR(uint16, AUTOMATIC) u16tmpVal_103;
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_VAR_NOINIT) pheaderMBPtr_103;
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#endif /* IPV_FLEXRAY */

    if(FR_RECEIVE_FIFOB == CCFIFOConfigPtr->FIFOChannel) /* Determine which FIFO is configured */
    {
        /* Set SEL bit in FLEXRAY_RFWMSR_ADDR16 reg. to configure FIFO for channel B*/
        u16regVal_103 |= FLEXRAY_RFWMSR_SEL_U16;
    }

    /* Set SEL bit in FLEXRAY_RFWMSR_ADDR16 register */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFWMSR_ADDR16, u16regVal_103);

    /* Configure Receive FIFO Start Data Offset */
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
    for (u16tmpVal_103 = CCFIFOConfigPtr->FIFOStartIndex; u16tmpVal_103 < (CCFIFOConfigPtr->FIFOStartIndex + CCFIFOConfigPtr->FIFODepth); u16tmpVal_103++)
    {
        /* Calculate the message buffer header */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_103 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u16tmpVal_103 * FLEXRAY_HEADER_SIZE);
        /* Data offset load from structure of type BufferOffsetTable (from configuration)*/
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16regVal_103 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferOffsetTable[u16tmpVal_103].DataOffset16;

        /* Store Data Field Offset to Frame header register */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_103[3U] = u16regVal_103;
    }
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else

    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFSDOR_ADDR16, (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferOffsetTable[CCFIFOConfigPtr->FIFOStartIndex].DataOffset16);
#endif /* IPV_FLEXRAY */

    /******************************** Configure FLEXRAY_RFSIR_ADDR16 register ****************************/
    /* Configure start of the receive FIFO (SIDX in the FLEXRAY_RFSIR_ADDR16 register */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFSIR_ADDR16, (VAR(uint16, AUTOMATIC))(CCFIFOConfigPtr->FIFOStartIndex & FLEXRAY_RFSIR_SIDX_MASK_U16));

    /******************************** Configure FLEXRAY_RFDSR_ADDR16 register ****************************/
    /* Configure FIFO Depth and Size reg. */
    u16regVal_103 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))(CCFIFOConfigPtr->FIFOEntrySize) & FLEXRAY_RFDSR_ENTRY_SIZE_MASK_U16); /*in [Words]*/
    u16regVal_103 |= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))(CCFIFOConfigPtr->FIFODepth) << 8U) & FLEXRAY_RFDSR_FIFO_DEPTH_MASK_U16;

    /* Store collected settings (FIFO_DEPTH and ENTRY_SIZE) into FLEXRAY_RFDSR_ADDR16 register */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFDSR_ADDR16, u16regVal_103); /* Store FIFO size and depth */

    /********************************* Set values for Filters ************************************/
    /* Configure FIFO Message ID Acceptance Filter Value - no message ID filter is configured */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFMIDAFVR_ADDR16, (VAR(uint16, AUTOMATIC))(CCFIFOConfigPtr->MessageIDFilterMatch)); /* Acceptance filter value */
    /* Configure FIFO Message ID Acceptance Filter Mask - no message ID filter is configured */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFMIDAFMR_ADDR16, (VAR(uint16, AUTOMATIC))(CCFIFOConfigPtr->MessageIDFilterMask)); /* Acceptance filter mask */
    /* Configure FIFO Frame ID Rejection Filter Value - to receive all frames */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFFIDRFVR_ADDR16, 0U); /* Rejection filter value */
    /* Configure FIFO Frame ID Rejection Filter Mask - to receive all frames */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFFIDRFMR_ADDR16, 0x07FFU); /* Rejection filter mask */

    /* Configure Range Filters */
    /* Range filter 0 enabled? */
    if(CCFIFOConfigPtr->FIFORangeFiltersConfig[0U].RangeFilterEnable)
    {
        u16regVal_103 = FLEXRAY_RFRFCFR_SEL_F0_U16;     /* Set filter Selector - filter 0 */
        /* To prevent Compiler_Warning: Building register value using bit field macro(s).
           Compiler_Affected: CodeWarrior
        */
        #if(FLEXRAY_RFRFCFR_IBD_LOWINT_U16 != 0U)
        u16regVal_103  |= FLEXRAY_RFRFCFR_IBD_LOWINT_U16;   /* Set lower interval boundary selection */
        #endif
        /* Set Lower Interval Boundary Slot ID */
        u16regVal_103 |= (CCFIFOConfigPtr->FIFORangeFiltersConfig[0U].RangeFilterLowerInterval & FLEXRAY_RFRFCFR_SID_MASK_U16);
        /* Store settings for lower interval boundary */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCFR_ADDR16, u16regVal_103); 

        u16regVal_103 = FLEXRAY_RFRFCFR_SEL_F0_U16;         /* Set filter Selector - filter 0 */
        u16regVal_103 |= FLEXRAY_RFRFCFR_IBD_UPPINT_U16;    /* Set upper interval boundary selection */
        /* Set Upper Interval Boundary Slot ID */
        u16regVal_103 |= (CCFIFOConfigPtr->FIFORangeFiltersConfig[0U].RangeFilterUpperInterval & FLEXRAY_RFRFCFR_SID_MASK_U16);
        /* Store settings for upper interval boundary */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCFR_ADDR16, u16regVal_103); 
    }

    /* Range filter 1 enabled? */
    if(CCFIFOConfigPtr->FIFORangeFiltersConfig[1U].RangeFilterEnable)
    {
        u16regVal_103 = FLEXRAY_RFRFCFR_SEL_F1_U16;     /* Set filter Selector - filter 1 */
        /* To prevent Compiler_Warning: Building register value using bit field macro(s).
           Compiler_Affected: CodeWarrior
        */
        #if(FLEXRAY_RFRFCFR_IBD_LOWINT_U16 != 0U)
        u16regVal_103  |= FLEXRAY_RFRFCFR_IBD_LOWINT_U16;   /* Set lower interval boundary selection */
        #endif
        /* Set Lower Interval Boundary Slot ID */
        u16regVal_103 |= (CCFIFOConfigPtr->FIFORangeFiltersConfig[1U].RangeFilterLowerInterval & FLEXRAY_RFRFCFR_SID_MASK_U16);
        /* Store settings for lower interval boundary */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCFR_ADDR16, u16regVal_103);

        u16regVal_103 = FLEXRAY_RFRFCFR_SEL_F1_U16;         /* Set filter Selector - filter 1 */
        u16regVal_103 |= FLEXRAY_RFRFCFR_IBD_UPPINT_U16;    /* Set upper interval boundary selection */
        /* Set Upper Interval Boundary Slot ID */
        u16regVal_103 |= (CCFIFOConfigPtr->FIFORangeFiltersConfig[1U].RangeFilterUpperInterval & FLEXRAY_RFRFCFR_SID_MASK_U16);
        /* Store settings for upper interval boundary */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCFR_ADDR16, u16regVal_103); 
    }

    /* Range filter 2 enabled? */
    if(CCFIFOConfigPtr->FIFORangeFiltersConfig[2U].RangeFilterEnable)
    {
        u16regVal_103 = FLEXRAY_RFRFCFR_SEL_F2_U16;         /* Set filter Selector - filter 2 */
        /* To prevent Compiler_Warning: Building register value using bit field macro(s).
           Compiler_Affected: CodeWarrior
        */
        #if(FLEXRAY_RFRFCFR_IBD_LOWINT_U16 != 0U)
        u16regVal_103  |= FLEXRAY_RFRFCFR_IBD_LOWINT_U16;   /* Set lower interval boundary selection */
        #endif
        /* Set Lower Interval Boundary Slot ID */
        u16regVal_103 |= (CCFIFOConfigPtr->FIFORangeFiltersConfig[2U].RangeFilterLowerInterval & FLEXRAY_RFRFCFR_SID_MASK_U16);
        /* Store settings for lower interval boundary */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCFR_ADDR16, u16regVal_103); 

        u16regVal_103 = FLEXRAY_RFRFCFR_SEL_F2_U16;         /* Set filter Selector - filter 2 */
        u16regVal_103 |= FLEXRAY_RFRFCFR_IBD_UPPINT_U16;    /* Set upper interval boundary selection */
        /* Set Upper Interval Boundary Slot ID */
        u16regVal_103 |= (CCFIFOConfigPtr->FIFORangeFiltersConfig[2U].RangeFilterUpperInterval & FLEXRAY_RFRFCFR_SID_MASK_U16);
        /* Store settings for upper interval boundary */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCFR_ADDR16, u16regVal_103); 
    }

    /* Range filter 3 */
    /* Range filter 3 enabled? */
    if(CCFIFOConfigPtr->FIFORangeFiltersConfig[3U].RangeFilterEnable)
    {
        u16regVal_103 = FLEXRAY_RFRFCFR_SEL_F3_U16;         /* Set filter Selector - filter 3 */
        /* To prevent Compiler_Warning: Building register value using bit field macro(s).
           Compiler_Affected: CodeWarrior
        */
        #if(FLEXRAY_RFRFCFR_IBD_LOWINT_U16 != 0U)
        u16regVal_103  |= FLEXRAY_RFRFCFR_IBD_LOWINT_U16;   /* Set lower interval boundary selection */
        #endif
        /* Set Lower Interval Boundary Slot ID */
        u16regVal_103 |= (CCFIFOConfigPtr->FIFORangeFiltersConfig[3U].RangeFilterLowerInterval & FLEXRAY_RFRFCFR_SID_MASK_U16);
        /* Store settings for lower interval boundary */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCFR_ADDR16, u16regVal_103);

        u16regVal_103 = FLEXRAY_RFRFCFR_SEL_F3_U16;         /* Set filter Selector - filter 3 */
        u16regVal_103 |= FLEXRAY_RFRFCFR_IBD_UPPINT_U16;    /* Set upper interval boundary selection */
        /* Set Upper Interval Boundary Slot ID */
        u16regVal_103 |= (CCFIFOConfigPtr->FIFORangeFiltersConfig[3U].RangeFilterUpperInterval & FLEXRAY_RFRFCFR_SID_MASK_U16);
        /* Store settings for upper interval boundary */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCFR_ADDR16, u16regVal_103);
    }

    /* Configure the FIFO Range Filter Control reg. */
    u16regVal_103 = 0U;            /* Clear temporary variable */
    /* Range filter 0 enabled? */
    if(CCFIFOConfigPtr->FIFORangeFiltersConfig[0U].RangeFilterEnable)
    {
        u16regVal_103 |= FLEXRAY_RFRFCTR_F0EN_U16;             /* Enable Range Filter 0 */
    }
    /* Range filter 1 enabled? */
    if(CCFIFOConfigPtr->FIFORangeFiltersConfig[1U].RangeFilterEnable)
    {
        u16regVal_103 |= FLEXRAY_RFRFCTR_F1EN_U16;             /* Enable Range Filter 1 */
    }
    /* Range filter 2 enabled? */
    if(CCFIFOConfigPtr->FIFORangeFiltersConfig[2U].RangeFilterEnable)
    {
        u16regVal_103 |= FLEXRAY_RFRFCTR_F2EN_U16;             /* Enable Range Filter 2 */
    }
    /* Range filter 3 enabled? */
    if(CCFIFOConfigPtr->FIFORangeFiltersConfig[3U].RangeFilterEnable)
    {
        u16regVal_103 |= FLEXRAY_RFRFCTR_F3EN_U16;             /* Enable Range Filter 3  */
    }
    /* Filter 0 as rejection? */
    if(FR_REJECTION == CCFIFOConfigPtr->FIFORangeFiltersConfig[0U].RangeFilterMode)
    {
        u16regVal_103 |= FLEXRAY_RFRFCTR_F0MD_U16;             /* Range filter 0 as rejection filter */
    }
    /* Filter 1 as rejection? */
    if(FR_REJECTION == CCFIFOConfigPtr->FIFORangeFiltersConfig[1U].RangeFilterMode)
    {
        u16regVal_103 |= FLEXRAY_RFRFCTR_F1MD_U16;             /* Range filter 1 as rejection filter */
    }
    /* Filter 2 as rejection? */
    if(FR_REJECTION == CCFIFOConfigPtr->FIFORangeFiltersConfig[2U].RangeFilterMode)
    {
        u16regVal_103 |= FLEXRAY_RFRFCTR_F2MD_U16;             /* Range filter 2 as rejection filter */
    }
    /* Filter 3 as rejection? */
    if(FR_REJECTION == CCFIFOConfigPtr->FIFORangeFiltersConfig[3U].RangeFilterMode)
    {
        u16regVal_103 |= FLEXRAY_RFRFCTR_F3MD_U16;             /* Range filter 3 as rejection filter */
    }
    /* Write configuration settings to the FIFO Range Filter Control reg. */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RFRFCTR_ADDR16, u16regVal_103);

}

/***************************************************************************************************
* @function_name    Fr_Flexray_BuffersInit
*
* @brief            FrIP function for message buffers configuration
* @details          This function configures the transmit, receive message buffers, shadow buffers 
*                   and FIFO arrays
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to errors
*
* @implements       Fr_Flexray_BuffersInit_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_BuffersInit
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
    /* Pointer to buffer header in the FR memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_VAR_NOINIT) pheaderMBPtr_107;
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#endif /* IPV_FLEXRAY */
    /* Pointer to used buffer configuration structure */
    P2CONST(Fr_CCLpduInfoType, AUTOMATIC, FR_APPL_CONST) plpduInfoPtr_107;
    VAR(uint16, AUTOMATIC) u16itemIdx_107;    /* The index of configured item */
    VAR(uint16, AUTOMATIC) u16regVal_107;    /* Temporary variable for register access */
    /* Temporary variable to signal success or failure */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_107 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    VAR(boolean, AUTOMATIC) bconfigureFifoA_107 = (VAR(boolean, AUTOMATIC))TRUE;
    VAR(boolean, AUTOMATIC) bconfigureFifoB_107 = (VAR(boolean, AUTOMATIC))TRUE;  
    VAR(uint16, AUTOMATIC) u16regVal_0; /* Temporary variable for register value */
    
    /* Configure FR_MBSEG2DS, MBSEG1DS */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_0 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->MessageBufferSegment1DataSize) & FLEXRAY_MBDSR_MBSEG1DS_MASK_U16);
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_0 |= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->MessageBufferSegment2DataSize) << 8U) & FLEXRAY_MBDSR_MBSEG2DS_MASK_U16;
    /* Configure FLEXRAY_MBDSR_ADDR16 register */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBDSR_ADDR16, u16regVal_0);
    /* Configure FLEXRAY_MBSSUTR_ADDR16 register: LAST_MB_SEG1, LAST_MB_UTIL */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_0 = (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LastMBUTIL) & FLEXRAY_MBSSUTR_LAST_MB_UTIL_MASK_U16);
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_0 |= (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LastMBSEG1) << 8U) & FLEXRAY_MBSSUTR_LAST_MB_SEG1_MASK_U16;
    /* Configure FLEXRAY_MBSSUTR_ADDR16 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBSSUTR_ADDR16, u16regVal_0);
    
    /* plpduInfoPtr_107 points to buffer configuration set referenced by Fr_BufConfSetIdx */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    plpduInfoPtr_107 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr;

    /* Receive shadow buffers configuration */

    /* Configuration of receive shadow buffer for channel A and segment 1 */
    /* Configure RSBIR reg: RSBIR: SEL, RSBIDX */
    /* Store buffer index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_107 = (VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_A1BufferIndexInit);  
    /* To prevent Compiler_Warning: Building register value using bit field macro(s).
       Compiler_Affected: CodeWarrior
    */
    #if(FLEXRAY_RSBIR_SEL_RSBIR_A1_U16 != 0U)
    u16regVal_107 |= FLEXRAY_RSBIR_SEL_RSBIR_A1_U16;     /* Selector field - ch A, seg 1 */
    #endif
    /* Store settings for shadow buffer, ch A, seg 1 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RSBIR_ADDR16, u16regVal_107);

    /* Configure Data Field offset in the FR Memory */
    u16regVal_107 = 0U;            /* Clear temporary variable */
    /* Data offset load from structure of type BufferOffsetTable */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_107 |= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferOffsetTable[(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_A1BufferIndexInit].DataOffset16;
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
    /* Calculate the message buffer header */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    pheaderMBPtr_107 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + ((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_A1BufferIndexInit * FLEXRAY_HEADER_SIZE);
    /* Store Data Field Offset to Frame header register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    pheaderMBPtr_107[3U] = u16regVal_107;
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else
    /* Store Data Field Offset into the FR_MBDOR0x register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBDOR0_ADDR16 + ((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_A1BufferIndexInit), u16regVal_107);
#endif /* IPV_FLEXRAY */
 
    /* Configuration of receive shadow buffer for channel A and segment 2 */
    /* Configure RSBIR reg: RSBIR: SEL, RSBIDX */
    /* Store buffer index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_107 = (VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_A2BufferIndexInit);
    u16regVal_107 |= FLEXRAY_RSBIR_SEL_RSBIR_A2_U16;     /* Selector field - ch A, seg 2 */
    /* Store settings for shadow buffer, ch A, seg 2 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RSBIR_ADDR16, u16regVal_107);

    /* Configure Data Field offset in the FR Memory */
    u16regVal_107 = 0U;            /* Clear temporary variable */
    /* Data offset load from structure of type BufferOffsetTable */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_107 |= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferOffsetTable[(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_A2BufferIndexInit].DataOffset16;
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
    /* Calculate the message buffer header */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    pheaderMBPtr_107 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + ((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_A2BufferIndexInit * FLEXRAY_HEADER_SIZE);
    /* Store Data Field Offset to Frame header register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    pheaderMBPtr_107[3U] = u16regVal_107;
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else
    /* Store Data Field Offset into the FR_MBDOR0x register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBDOR0_ADDR16 + ((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_A2BufferIndexInit), u16regVal_107);
#endif /* IPV_FLEXRAY */

    /* Configuration of receive shadow buffer for channel B and segment 1 */
    /* Configure RSBIR reg: RSBIR: SEL, RSBIDX */
    /* Store buffer index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_107 = (VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B1BufferIndexInit);
    u16regVal_107 |= FLEXRAY_RSBIR_SEL_RSBIR_B1_U16;     /* Selector field - ch B, seg 1 */
    /* Store settings for shadow buffer, ch B, seg 1 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RSBIR_ADDR16, u16regVal_107);

    /* Configure Data Field offset in the FR Memory */
    u16regVal_107 = 0U;            /* Clear temporary variable */
    /* Data offset load from structure of type BufferOffsetTable */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_107 |= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferOffsetTable[(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B1BufferIndexInit].DataOffset16;
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
    /* Calculate the message buffer header */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    pheaderMBPtr_107 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + ((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B1BufferIndexInit * FLEXRAY_HEADER_SIZE);
    /* Store Data Field Offset to Frame header register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    pheaderMBPtr_107[3U] = u16regVal_107;
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else
    /* Store Data Field Offset into the FR_MBDOR0x register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBDOR0_ADDR16 + ((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B1BufferIndexInit), u16regVal_107);
#endif /* IPV_FLEXRAY */

    /* Configuration of receive shadow buffer for channel B and segment 2 */
    /* Configure RSBIR reg: RSBIR: SEL, RSBIDX */
    /* Store buffer index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_107 = (VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B2BufferIndexInit);
    u16regVal_107 |= FLEXRAY_RSBIR_SEL_RSBIR_B2_U16;     /* Selector field - ch B, seg 2 */
    /* Store settings for shadow buffer, ch B, seg 2 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_RSBIR_ADDR16, u16regVal_107);

    /* Configure Data Field offset in the FR Memory */
    u16regVal_107 = 0U;            /* Clear temporary variable */
    /* Data offset load from structure of type BufferOffsetTable */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u16regVal_107 |= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferOffsetTable[(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B2BufferIndexInit].DataOffset16;
#ifdef IPV_FLEXRAY
    #if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
    /* Calculate the message buffer header */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    pheaderMBPtr_107 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + ((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B2BufferIndexInit * FLEXRAY_HEADER_SIZE);
    /* Store Data Field Offset to Frame header register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    pheaderMBPtr_107[3U] = u16regVal_107;
    #endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else
    /* Store Data Field Offset into the FR_MBDOR0x register */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBDOR0_ADDR16 + ((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B2BufferIndexInit), u16regVal_107);
#endif /* IPV_FLEXRAY */
  
    /* Configuration of all buffers referenced in set Fr_BufConfSetIdx */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    for(u16itemIdx_107 = 0U; u16itemIdx_107 < (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BuffersConfiguredCount; u16itemIdx_107++)
    {
        /* Configure only the item with the parameter FirstInitialization set to
          (VAR(boolean, FR_VAR))TRUE */
        /* Remainder configuration item can be used during a reconfiguration */
        if((VAR(boolean, AUTOMATIC))TRUE == plpduInfoPtr_107->FirstInitialization)
        {
            switch(plpduInfoPtr_107->BufferType)
            {

                /* Transmit MB configuration */
                case FR_TRANSMIT_BUFFER:
                    returnValue_107 = Fr_Flexray_TxBufferCfg(ctrlIdx, plpduInfoPtr_107);
                    #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
                        /* [SWS_Fr_00440],[SWS_Fr_00441]: Only if FR_PREPARE_LPDU_SUPPORT is enabled: */
                        /* Store information which virtual resource is currently configured
                        for given physical resource (individual MB) */
                        Fr_VirtualResourceAllocation[ctrlIdx][plpduInfoPtr_107->MessageBufferNumber] = u16itemIdx_107;
                    #endif /* FR_PREPARE_LPDU_SUPPORT */
                break;

                /* Receive MB configuration */
                case FR_RECEIVE_BUFFER:
                    returnValue_107 = Fr_Flexray_RxBufferCfg(ctrlIdx, plpduInfoPtr_107);
                    #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
                    /* [SWS_Fr_00440],[SWS_Fr_00441]: Only if FR_PREPARE_LPDU_SUPPORT is enabled: */
                    /* Store information which virtual resource is currently configured
                       for given physical resource (individual MB) */
                        Fr_VirtualResourceAllocation[ctrlIdx][plpduInfoPtr_107->MessageBufferNumber] = u16itemIdx_107;
                    #endif /* FR_PREPARE_LPDU_SUPPORT */
                break;

                /* Receive FIFO storage configuration */
                case FR_FIFOA_BUFFER:
                    /* Only if the fifo is not already configured */
                    if((VAR(boolean, AUTOMATIC))TRUE == bconfigureFifoA_107)
                    {
                        Fr_Flexray_ConfigureFifo(ctrlIdx, (P2CONST(Fr_CCFifoConfigType, AUTOMATIC, FR_APPL_CONST))(plpduInfoPtr_107->BufferConfigPtr));
                        bconfigureFifoA_107 = (VAR(boolean, AUTOMATIC))FALSE; 
                    }
                break;
                case FR_FIFOB_BUFFER:
                    /* Only if the fifo is not already configured */
                    if((VAR(boolean, AUTOMATIC))TRUE == bconfigureFifoB_107)
                    {
                        Fr_Flexray_ConfigureFifo(ctrlIdx, (P2CONST(Fr_CCFifoConfigType, AUTOMATIC, FR_APPL_CONST))(plpduInfoPtr_107->BufferConfigPtr));
                        bconfigureFifoB_107 = (VAR(boolean, AUTOMATIC))FALSE; 
                    }
                break;
            default:
                break;
            }
        }
        /* Increment the plpduInfoPtr_107 - move to next resource configuration */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        plpduInfoPtr_107++;
        /* Check if the buffer configuration has been successful */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == returnValue_107)
        {
            /* NO */
            break; /* There is a failure, break the configuration */
        }
    }
    return returnValue_107;    /* API call finished successfully */
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetPOCStatus
*
* @brief            FrIP function for quering the controller POC status
* @description      Provides information about the current protocol status directly from the 
*                   FLEXRAY_PSR0_ADDR16 and FLEXRAY_PSR1_ADDR16 registers.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[out]       pocStatusPtr - Address of the variable where the Protocol status is stored to
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware errors
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetPOCStatus
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) pocStatusPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); 
    VAR(uint32, AUTOMATIC) u32pocStatus;    /* Stores information from both FLEXRAY_PSR0_ADDR16/1 registers */

    /* Read both PSR0 & PSR1 registers at the same time */
    u32pocStatus = Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PSR0_ADDR16);

    /* The state of the PSR0 register (the PROSTATE field) is not updated if the FREEZE occurred */
    if(FLEXRAY_PSR1_FRZ_U16 == ((VAR(uint16,AUTOMATIC))(u32pocStatus) & FLEXRAY_PSR1_FRZ_U16))
    {
        /* Store the POC status to location referenced by given pointer */
        pocStatusPtr->State = FR_POCSTATE_HALT;
        pocStatusPtr->Freeze = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        /* Determine the POC state */
        Fr_Flexray_GetProtocolState((VAR(uint16,AUTOMATIC))(u32pocStatus >> 16U), &pocStatusPtr->State);
        pocStatusPtr->Freeze = (VAR(boolean, AUTOMATIC))FALSE;
    }
    /* Determine the startup state*/
    if (pocStatusPtr->State == FR_POCSTATE_STARTUP)
    {
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Flexray_GetStartupState((VAR(uint16,AUTOMATIC))(u32pocStatus >> 16U), &pocStatusPtr->StartupState))
        {
            retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
        }
    }
    else
    {
        /* Return FR_STARTUP_UNDEFINED in case of startup routine is not in progress */
        pocStatusPtr->StartupState = FR_STARTUP_UNDEFINED;
    }
    
    
    /* Determine the Wakeup status */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Flexray_GetWakeupState((VAR(uint16,AUTOMATIC))(u32pocStatus >> 16U), &pocStatusPtr->WakeupStatus))
    {
        retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    
    /* Determine the Slot Mode */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Flexray_GetSlotMode((VAR(uint16,AUTOMATIC))(u32pocStatus >> 16U), &pocStatusPtr->SlotMode))
    {
        retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    
    /* Determine the Error Mode */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Flexray_GetErrorMode((VAR(uint16,AUTOMATIC))(u32pocStatus >> 16U), &pocStatusPtr->ErrorMode))
    {
        retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    
    if(FLEXRAY_PSR1_HHR_U16 == ((VAR(uint16,AUTOMATIC))(u32pocStatus) & FLEXRAY_PSR1_HHR_U16))
    {
        /* Store the Halt request status to location referenced by given pointer */
        pocStatusPtr->CHIHaltRequest = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        /* Store the Halt request status to location referenced by given pointer */
        pocStatusPtr->CHIHaltRequest = (VAR(boolean, AUTOMATIC))FALSE;
    }
    
    if(FLEXRAY_PSR1_CPN_U16 == ((VAR(uint16,AUTOMATIC))(u32pocStatus) & FLEXRAY_PSR1_CPN_U16))
    {
        /* Store the ColdStart Noise status to location referenced by given pointer */
        pocStatusPtr->ColdstartNoise = (VAR(boolean, AUTOMATIC))TRUE;
    }
    else
    {
        /* Store the ColdStart Noise status to location referenced by given pointer */
        pocStatusPtr->ColdstartNoise = (VAR(boolean, AUTOMATIC))FALSE;
    }
    
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetProtocolState
*
* @brief            FrIP function for quering the state of the protocol
* @description      The FlexRay controller Protocol State is determined here.
* @param[in]        regValuePSR0 - Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       protStatePtr - Address the Protocol State is stored to.
* @return           none
***************************************************************************************************/
static FUNC(void, FR_CODE) Fr_Flexray_GetProtocolState
(
    VAR(uint16, AUTOMATIC) regValuePSR0,
    P2VAR(Fr_POCStateType, AUTOMATIC, FR_APPL_DATA) protStatePtr
)
{
    /* Determine the POC status */
    switch(regValuePSR0 & FLEXRAY_PSR0_PROTSTATE_MASK_U16)
    {
        case FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16:
            /* Store the POC status to location referenced by given pointer */
            *protStatePtr = FR_POCSTATE_DEFAULT_CONFIG;
            break;

        case FLEXRAY_PSR0_PROTSTATE_CONFIG_U16:
            /* Store the POC status to location referenced by given pointer */
            *protStatePtr = FR_POCSTATE_CONFIG;
            break;

        case FLEXRAY_PSR0_PROTSTATE_WAKEUP_U16:
            /* Store the POC status to location referenced by given pointer */
            *protStatePtr = FR_POCSTATE_WAKEUP;
            break;

        case FLEXRAY_PSR0_PROTSTATE_READY_U16:
            /* Store the POC status to location referenced by given pointer */
            *protStatePtr = FR_POCSTATE_READY;
            break;

        case FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16:
            /* Store the POC status to location referenced by given pointer */
            *protStatePtr = FR_POCSTATE_NORMAL_PASSIVE;
            break;

        case FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16:
            /* Store the POC status to location referenced by given pointer */
            *protStatePtr = FR_POCSTATE_NORMAL_ACTIVE;
            break;

        case FLEXRAY_PSR0_PROTSTATE_HALT_U16:
            /* Store the POC status to location referenced by given pointer */
            *protStatePtr = FR_POCSTATE_HALT;
            break;

        case FLEXRAY_PSR0_PROTSTATE_STARTUP_U16:
            /* Store the POC status to location referenced by given pointer */
            *protStatePtr = FR_POCSTATE_STARTUP;
            break;

        default:
            /* Reserved values cannot occur */
            break;
    }
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetWakeupState
*
* @brief            FrIP function for the Fr_GetPOCStatus API
* @description      The FlexRay controller wakeup state is determined here.
* @param[in]        regValuePSR0 - Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       wakeupStatusPtr - Address the Wakeup status is stored to.
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetWakeupState
(
    VAR(uint16, AUTOMATIC) regValuePSR0,
    P2VAR(Fr_WakeupStatusType, AUTOMATIC, FR_APPL_DATA) wakeupStatusPtr
)
{
    /* Initialize variable */
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    
    /* Determine the wakeup status */
    switch(regValuePSR0 & FLEXRAY_PSR0_WUP_MASK_U16)
    {
        case FLEXRAY_PSR0_WUP_RH_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_RECEIVED_HEADER;
            break;

        case FLEXRAY_PSR0_WUP_RW_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_RECEIVED_WUP;
            break;

        case FLEXRAY_PSR0_WUP_HC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_COLLISION_HEADER;
            break;

        case FLEXRAY_PSR0_WUP_WC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_COLLISION_WUP;
            break;

        case FLEXRAY_PSR0_WUP_UC_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_COLLISION_UNKNOWN;
            break;

        case FLEXRAY_PSR0_WUP_T_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_TRANSMITTED;
            break;

        case FLEXRAY_PSR0_WUP_UD_U16:
            /* Store the wakeup status to location referenced by given pointer */
            *wakeupStatusPtr = FR_WAKEUP_UNDEFINED;
            break;

        default:
            /* Reserved value cannot occur */
            *wakeupStatusPtr = FR_WAKEUP_UNDEFINED;
            retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            break;
    }
    
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetStartupState
*
* @brief            FrIP function for the Fr_GetPOCStatus API
* @description      The FlexRay controller startup state is determined here.
* @param[in]        regValuePSR0 - Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       startupStatePtr - Address the Startup state is stored to.
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetStartupState
(
    VAR(uint16, AUTOMATIC) regValuePSR0,
    P2VAR(Fr_StartupStateType, AUTOMATIC, FR_APPL_DATA) startupStatePtr
)
{
    /* Initialize variable */
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    
    /* Determine the startup status */
    switch(regValuePSR0 & FLEXRAY_PSR0_STARTUP_MASK_U16)
    {
        case FLEXRAY_PSR0_STARTUP_CCR_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_COLDSTART_COLLISION_RESOLUTION;
            break;

        case FLEXRAY_PSR0_STARTUP_CL_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_COLDSTART_LISTEN;
            break;

        case FLEXRAY_PSR0_STARTUP_ICOC_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_INTEGRATION_CONSISTENCY_CHECK;
            break;

        case FLEXRAY_PSR0_STARTUP_IL_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_INTEGRATION_LISTEN;
            break;

        case FLEXRAY_PSR0_STARTUP_IS_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_INITIALIZE_SCHEDULE;
            break;

        case FLEXRAY_PSR0_STARTUP_CCC_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_COLDSTART_CONSISTENCY_CHECK;
            break;

        case FLEXRAY_PSR0_STARTUP_ICLC_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_INTEGRATION_COLDSTART_CHECK;
            break;

        case FLEXRAY_PSR0_STARTUP_CG_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_COLDSTART_GAP;
            break;

        case FLEXRAY_PSR0_STARTUP_CJ_U16:
            /* Store the startup status to location referenced by given pointer */
            *startupStatePtr = FR_STARTUP_COLDSTART_JOIN;
            break;

        default:
            /* Reserved values cannot occur but this also solves them */
            *startupStatePtr = FR_STARTUP_UNDEFINED;
            retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            break;
    }
    
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetSlotMode
*
* @brief            FrIP function for the Fr_GetPOCStatus API
* @description      The FlexRay controller slot mode is determined here.
* @param[in]        regValuePSR0 - Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       slotModePtr -  Address the Slot mode is stored to. 
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetSlotMode
(
    VAR(uint16, AUTOMATIC) regValuePSR0,
    P2VAR(Fr_SlotModeType, AUTOMATIC, FR_APPL_DATA) slotModePtr
)
{
    /* Initialize variable */
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);

    /* Determine the slot mode */
    switch(regValuePSR0 & FLEXRAY_PSR0_SLOTMODE_MASK_U16)
    {
        case FLEXRAY_PSR0_SLOTMODE_SINGLE_U16:
            /* Store the slot mode to location referenced by given pointer */
            *slotModePtr = FR_SLOTMODE_SINGLE;
            break;

        case FLEXRAY_PSR0_SLOTMODE_ALL_PENDING_U16:
            /* Store the slot mode to location referenced by given pointer */
            *slotModePtr = FR_SLOTMODE_ALL_PENDING;
            break;

        case FLEXRAY_PSR0_SLOTMODE_ALL_U16:
            /* Store the slot mode to location referenced by given pointer */
            *slotModePtr = FR_SLOTMODE_ALL;
            break;

        default:
            /* Reserved value cannot occur */
            *slotModePtr = FR_SLOTMODE_SINGLE;
            retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            break;
    }
    
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetPOCState
* @brief            FrIP function for quering the controller POC status
* @description      Read the FlexRay controller Protocol Status Register 1.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[out]       pocState - Address of the variable wher the Protocol status is stored to
* @return           none
***************************************************************************************************/
FUNC(uint16, FR_CODE) Fr_Flexray_GetPOCState
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    VAR(uint32, AUTOMATIC) u32pocStatus;
    VAR(uint16, AUTOMATIC) u16pocState;

    /* Read both PSR0 & PSR1 registers at the same time */
    u32pocStatus = Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PSR0_ADDR16);
    /* Get status of FRZ bit */
    u16pocState = (VAR(uint16,AUTOMATIC))(u32pocStatus);
    /* Check FRZ bit is set? */
    /* The state of the PSR0 register (PROSTATE field) is not updated if FREEZE occurred */
    if ((u16pocState & FLEXRAY_PSR1_FRZ_U16) == FLEXRAY_PSR1_FRZ_U16)
    { /* Yes, FRZ bit is set*/
        /* When FRZ bit is set signal the POC: Halt State */
        u16pocState = FLEXRAY_PSR0_PROTSTATE_HALT_U16;
    }
    else
    { /* No, FRZ bit is not set */
        u16pocState = (VAR(uint16,AUTOMATIC))((VAR(uint16,AUTOMATIC))(u32pocStatus >> 16U) & FLEXRAY_PSR0_PROTSTATE_MASK_U16);
    }
    /* return POC state */
    return u16pocState;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_EnterPOCConfigState 
*
* @brief            FrIP function for entering the POC:Config state
* @details          This API call determines in which POC state of the FlexRay protocol and
*                   performs following sequences:
*                   - if the state of the protocol is POC:Halt, the function sends
*                     the DEFAULT_CONFIG command and later on the CONFIG command
*                   - if the state of the protocol is POC:Default Config or POC:Ready,
*                     the function sends the the CONFIG command
*                   If the transition is not successful this API call returns E_NOT_OK.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Error occurred during transition into POC:Config
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_EnterPOCConfigState
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_109 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);   
    /* Temporary variable for never-ending while loop protection */
    VAR(uint16, AUTOMATIC) u16timeout_109 = 0U;
    VAR(uint16, AUTOMATIC) u16pocState_109;          /* Current POC state */
    /* Indicates if wait cycle should finish or not */
    VAR(boolean, AUTOMATIC) bEnd_109 = (VAR(boolean, AUTOMATIC))FALSE;

    /* Perform the following sequence only if the POCState is not POC:Default_Config or POC:Ready */
    u16pocState_109 = Fr_Flexray_GetPOCState(ctrlIdx);
    
    /* Check FRZ bit is set or POC State is not Ready */
    if(FLEXRAY_PSR0_PROTSTATE_READY_U16 != u16pocState_109)
    {
        if(FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16 != u16pocState_109)
        {/* CC is not in POC:Default Config ot POC:Ready state */
            retVal_109 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK); /* set default value*/
        #ifdef ERR_IPV_FLEXRAY_0002
            #if(ERR_IPV_FLEXRAY_0002 == STD_ON)
            /* Try to invoke HALT command */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(ctrlIdx, FLEXRAY_POCR_CMD_HALT_U16))
            #else
                #error : the define ERR_IPV_FLEXRAY_0002 must not be STD_OFF
            #endif
        #else
            /* Try to invoke FREEZE command */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(ctrlIdx, FLEXRAY_POCR_CMD_FREEZE_U16))
        #endif /* ERR_IPV_FLEXRAY_0002 */
            {/* FREEZE invoking was successfull */             
                if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForPOCState(ctrlIdx, FLEXRAY_PSR0_PROTSTATE_HALT_U16))
                {/* Now the CC should be in POC:halt state */
                    
                    /* go to the POC:Default_Config state */
                    /* Wait till Default Config state is reached or timeout expired */
                    while((VAR(boolean, AUTOMATIC))FALSE == bEnd_109)
                    {
                        /* Wait till Protocol Command Write is not busy */
                        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForCmdProcess(ctrlIdx))
                        {
                            /* Immediately transition to the POC:Default_Config */
                            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_POCR_ADDR16,((VAR(uint16, AUTOMATIC))(FLEXRAY_POCR_CMD_DEFAULTCONFIG_U16 | FLEXRAY_POCR_WME_U16)));
                        }

                        /* check state */
                        u16pocState_109 = Fr_Flexray_GetPOCState(ctrlIdx);
                        if(FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16 == u16pocState_109)
                        {/* Desired state is reached */
                             bEnd_109 = (VAR(boolean, AUTOMATIC))TRUE;
                        }

                        /* check timeout */
                        if(u16timeout_109 >= FR_IPW_MAX_WAITCYCLES_U8)
                        {/* timeout has expired */
                             bEnd_109 = (VAR(boolean, AUTOMATIC))TRUE;
                        }

                        u16timeout_109++;  /* Increment timeout counter */
                    }

                    if(u16timeout_109 < FR_IPW_MAX_WAITCYCLES_U8)
                    {/* Desired POC state was reached on time*/
                        retVal_109 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                    }
                }
            }
        }
    }
    
    /* Check if no error occurred */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == retVal_109)
    {
        /* Now the CC should be in POC:Default_Config or POC:Ready => send the CONFIG command */
        /* Wait till Protocol Command Write is not busy */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) != Fr_Flexray_WaitForCmdProcess(ctrlIdx))
        {
            /* Immediately transition to the POC:Config */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_POCR_ADDR16, ((VAR(uint16, AUTOMATIC))(FLEXRAY_POCR_CMD_CONFIG_U16 | FLEXRAY_POCR_WME_U16)));
            /* Wait till FlexRay CC is not in POC:Config */
            retVal_109 = Fr_Flexray_WaitForPOCState(ctrlIdx, FLEXRAY_PSR0_PROTSTATE_CONFIG_U16);
        }
        else
        {
            retVal_109 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
        }
    }

    return retVal_109;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_LeavePOCConfigState 
*
* @brief            FrIP function for leaving the POC:Config state - entering POC:Ready state
* @details          This API call transmit the CC into POC:Ready state. It is assumed that
*                   CC is in the POC:Config state.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @return           ::Std_ReturnType:
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Error occurred during transition into POC:Ready
*
* @implements       Fr_Flexray_LeavePOCConfigState_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_LeavePOCConfigState
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_110 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

    /* Wait till Protocol Command Write is not busy */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForCmdProcess(ctrlIdx))
    {
        /* Send the command CONFIG COMPLETE */
        /* Immediately transition to POC:Ready state */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_POCR_ADDR16, ((VAR(uint16, AUTOMATIC))(FLEXRAY_POCR_CMDCONFIGCOMPLETE_U16 | FLEXRAY_POCR_WME_U16)));
        /* Wait till Protocol Command Write is not busy */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForCmdProcess(ctrlIdx))
        {
            /* Wait if POC:Ready state is reached */
            retVal_110 = Fr_Flexray_WaitForPOCState(ctrlIdx, FLEXRAY_PSR0_PROTSTATE_READY_U16);
        }
    }

    return retVal_110;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_InvokeCHICommand
*
* @brief            FrIP function for invoking POCCMD commands
* details           Invokes required CHI command
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        chiCommand - required CHI command
* @return           ::Std_ReturnType:
*                       - E_OK      CHI command was accepted by PE
*                       - E_NOT_OK  CHI command was not accepted by PE due to BSY flag
*
* @implements       Fr_Flexray_InvokeCHICommand_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_InvokeCHICommand
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) chiCommand
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_110 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);

    /* Wait till Protocol Command Write is not busy */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForCmdProcess(ctrlIdx))
    {
        /* Send the command CONFIG COMPLETE */
        /* Immediately transition to POC:Ready state */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_POCR_ADDR16, ((VAR(uint16, AUTOMATIC))(chiCommand | FLEXRAY_POCR_WME_U16)));
        retVal_110 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    }

    return retVal_110;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_AckAbsTimerIRQ
*
* @brief            FrIP function for the Fr_AckAbsoluteTimerIRQ API            
* @details          Ack the FlexRay CC absolute timer 
* @param[in]        ctrlIdx - Index of FlexRay CC           
* @param[in]        timerIdx Index of absolute timer within the context of the FlexRay CC
* @return           none
*
* @implements       Fr_Flexray_AckAbsTimerIRQ_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_AckAbsTimerIRQ
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    /* Determine for which timer should be cleared the interrupt flag */
    if(0U == timerIdx)
    {   /* Timer 1 */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIFR0_ADDR16, FLEXRAY_PIFR0_TI1_IF_U16); /* Clear flag */
    }
    else
    {   /* Timer 2 */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIFR0_ADDR16, FLEXRAY_PIFR0_TI2_IF_U16); /* Clear flag */
    }
}

/***************************************************************************************************
* @function_name    Fr_Flexray_CancelAbsTimer
*
* @brief            FrIP function for the Fr_CancelAbsoluteTimer API            
* @details          Cancel the FlexRay CC absolute timer 
* @param[in]        ctrlIdx - Index of FlexRay CC          
* @param[in]        timerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           none
*
* @implements       Fr_Flexray_CancelAbsTimer_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_CancelAbsTimer
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    VAR(uint16, AUTOMATIC) u16tmpVal_019;
    
    /* Stop timer */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_01();
    u16tmpVal_019 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16) & FLEXRAY_TICCR_CONFIG_MASK_U16);
    /* Determine which timer should be stoped */
    if(0U == timerIdx)
    {   /* Timer 1 should be stoped */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16, (VAR(uint16, AUTOMATIC))(u16tmpVal_019 | FLEXRAY_TICCR_T1SP_U16));

    }
    else
    {   /* Timer 2 should be stoped */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16, (VAR(uint16, AUTOMATIC))(u16tmpVal_019 | FLEXRAY_TICCR_T2SP_U16));
    }
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_01();
}

/***************************************************************************************************
* @function_name    Fr_Flexray_DisableAbsTimerIRQ
*
* @brief            FrIP function for the Fr_DisableAbsoluteTimerIRQ API          
* @details          Disable the FlexRay CC absolute timer
* @param[in]        ctrlIdx - Index of FlexRay CC  
* @param[in]        timerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           none
*
* @implements       Fr_Flexray_DisableAbsTimerIRQ_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_DisableAbsTimerIRQ
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    VAR(uint16, AUTOMATIC) u16tmpVal_025;
    
    /* Determine for which timer should be disabled the interrupt line */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_02();
    u16tmpVal_025 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PIER0_ADDR16);   /* Load the PIER0 reg. */
    if(0U == timerIdx)
    {   /* Timer 1 should be disabled */
        u16tmpVal_025 &= ~FLEXRAY_PIER0_TI1_IE_U16;  /* Clear control flag */
    }
    else
    {   /* Timer 2 should be disabled */
        u16tmpVal_025 &= ~FLEXRAY_PIER0_TI2_IE_U16;  /* Clear control flag */
    }
    
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIER0_ADDR16, u16tmpVal_025);           /* Store new settings */
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_02();
}

/***************************************************************************************************
* @function_name    Fr_Flexray_EnableAbsTimerIRQ
*
* @brief            FrIP function for the Fr_EnableAbsoluteTimerIRQ          
* @details          Enable the FlexRay CC absolute timer
* @param[in]        ctrlIdx - Index of FlexRay CC         
* @param[in]        timerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           none
*
* @implements       Fr_Flexray_EnableAbsTimerIRQ_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_EnableAbsTimerIRQ
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    VAR(uint16, AUTOMATIC) u16tmpVal_021;
    
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_04();
    u16tmpVal_021 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PIER0_ADDR16);     /* Load the PIER0 reg. */
    /* Determine for which timer should be enabled the interrupt */
    if(0U == timerIdx)
    {   /* Timer 1 */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIER0_ADDR16, (VAR(uint16, AUTOMATIC))(u16tmpVal_021 | FLEXRAY_PIER0_TI1_IE_U16));     /* Set control flag */

    }
    else
    {   /* Timer 2 */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PIER0_ADDR16, (VAR(uint16, AUTOMATIC))(u16tmpVal_021 | FLEXRAY_PIER0_TI2_IE_U16));     /* Set control flag */
    }
    
    /* Load FLEXRAY_GIFER_ADDR16 reg. */
    u16tmpVal_021 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16) & FLEXRAY_GIFER_CTRL_FLAGS_MASK_U16);
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16, (VAR(uint16, AUTOMATIC))(u16tmpVal_021 |  FLEXRAY_GIFER_PRIE_U16));          /* Set control flag */
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_04();
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetAbsTimerIRQStatus
*
* @brief            FrIP function for the Fr_GetAbsoluteTimerIRQStatus                      
* @details          Check whether absolute timer inerrupt flag is pending
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        timerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           ::boolean
*                     - TRUE - Interrupt is pending
*                     - FALSE - Interrupt is not pending
*
* @implements       Fr_Flexray_GetAbsTimerIRQStatus_Activity
***************************************************************************************************/
FUNC(boolean, FR_CODE) Fr_Flexray_GetAbsTimerIRQStatus 
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
        VAR(uint16, AUTOMATIC) u16tmpVal_032;
        VAR(boolean, AUTOMATIC) bstatusIRQ_032 = (VAR(boolean, AUTOMATIC))FALSE;

        u16tmpVal_032 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PIFR0_ADDR16);   /* Load the PIFR0 reg. */
        /* Determine for which timer should be checked the interrupt flag */
        if(0U == timerIdx)
        {   /* Timer 1 */
            if(0U != (u16tmpVal_032 & FLEXRAY_PIFR0_TI1_IF_U16))
            {   /* Interrupt flag has been set */
                bstatusIRQ_032 = (VAR(boolean, AUTOMATIC))TRUE;
            }
        }
        else
        {   /* Timer 2 */
            if(0U != (u16tmpVal_032 & FLEXRAY_PIFR0_TI2_IF_U16))
            {   /* Interrupt flag has been set */
                bstatusIRQ_032 = (VAR(boolean, AUTOMATIC))TRUE;
            }
        }
        return bstatusIRQ_032;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_SetAbsTimer
*
* @brief            FrIP function for the Fr_SetAbsoluteTimer API          
* @details          Store information about absolute timer into the FlexRay CC registers
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        timeridx - Index of FlexRay timer
* @param[in]        cycle - Cycle the timer shall elapse in
* @param[in]        offset - Offset within cycle Fr_Cycle in units of macrotick the timer shall
*                            elapse at
* @return           none
*
* @implements       Fr_Flexray_SetAbsTimer_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_SetAbsTimer
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx,
    VAR(uint8, AUTOMATIC) cycle,
    VAR(uint16, AUTOMATIC) offset
)
{
    VAR(uint16, AUTOMATIC) u16startBit_017; /* Variable for storing the start bit */
    VAR(uint16, AUTOMATIC) u16stopBit_017;  /* Variable for storing the stop bit */
    VAR(uint16, AUTOMATIC) u16cysrReg_017;  /* Variable for storing FR_TIxCYSR reg address */
    VAR(uint16, AUTOMATIC) u16mtorReg_017;  /* Variable for storing FR_TIxMTOR reg address */
    
    /* Determine which timer should be configured */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_03();
    if(0U == timerIdx)
    {   /* Timer 1 should be configured - store values for timer 1*/
        u16stopBit_017 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16) | FLEXRAY_TICCR_T1SP_U16);
        u16startBit_017 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16) | FLEXRAY_TICCR_T1TR_U16);
        u16cysrReg_017 = FLEXRAY_TI1CYSR_ADDR16;
        u16mtorReg_017 = FLEXRAY_TI1MTOR_ADDR16;
    }
    else
    {   /* Timer 2 should be configured - store values for timer 2 */
        u16stopBit_017 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16) | FLEXRAY_TICCR_T2SP_U16);
        u16startBit_017 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16) | FLEXRAY_TICCR_T2TR_U16);
        u16cysrReg_017 = FLEXRAY_TI2CR0_ADDR16;
        u16mtorReg_017 = FLEXRAY_TI2CR1_ADDR16;
    }

    /* Configure absolute timer */
    /* stop the timer */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16, u16stopBit_017);
    /* store cycle value */
    Fr_Flexray_WriteRegister(ctrlIdx, u16cysrReg_017, (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))(((VAR(uint16, AUTOMATIC))cycle) << 8U) | FLEXRAY_TI1CYSR_T1_CYC_MSK_U16));
    /* store the macrotick */
    Fr_Flexray_WriteRegister(ctrlIdx, u16mtorReg_017, offset);

    /* start the timer */
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16, u16startBit_017);
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_03();
}

/***************************************************************************************************
* @function_name    Fr_Flexray_SetWakeupChannel
*
* @brief            FrIP function for the Fr_SetWakeupChannel API        
* @details          Store information about wakeup channel into FlexRay CC registers
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        chnlIdx - Index of FlexRay channel
* @return           ::Std_ReturnType:
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Error occurred during set wakeup channel
*
* @implements       Fr_Flexray_SetWakeupChannel_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_SetWakeupChannel
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(Fr_ChannelType, AUTOMATIC) chnlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_07 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16tmpVal_07;
    
    /* Invoke CHI command CONFIG */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(ctrlIdx, FLEXRAY_POCR_CMD_CONFIG_U16))
    {
        /* Wait till FlexRay CC is not in POC:Config */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForPOCState(ctrlIdx, FLEXRAY_PSR0_PROTSTATE_CONFIG_U16))
        {    
          
            /* The CC should be in POC:config */
            /* Load the PCR10 */
            u16tmpVal_07 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PCR10_ADDR16);
            
            /* Determine the channel */
            if(FR_CHANNEL_A == chnlIdx)
            {   /* Channel A should be used for wakeup sending */
                /* Channel A - clear the bit in register */
                 u16tmpVal_07 &= ~FLEXRAY_PCR10_WUP_CH_U16;
            }
            else
            {   /* Channel B should be used for wakeup sending */
                /* Fr_CtrlIdx: PCR10: wakeup_channel */
                u16tmpVal_07 |= FLEXRAY_PCR10_WUP_CH_U16;       /* Channel B - set the bit */
            }
            
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PCR10_ADDR16, u16tmpVal_07);  /* Store new settings */
            
            /* Invoke CHI command CONFIG COMPLETE */
            /* Immediately transition to POC:ready state */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(ctrlIdx, FLEXRAY_POCR_CMDCONFIGCOMPLETE_U16))
            {
                /* Wait till FlexRay CC is not in POC:Ready */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForPOCState(ctrlIdx, FLEXRAY_PSR0_PROTSTATE_READY_U16))
                {
                    retVal_07 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                }
            }
        }
    }
    
    return retVal_07;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetGlobalTime
*
* @brief            FrIP function for the Fr_GetGlobalTime API           
* @details          Query current cycle and macrotick from FlexRay CC registers
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[out]       cyclePtr - Address where current cycle is stored to
* @param[out]       macrotickPtr - Address where current macrotick is stored to 
* @return           none
*
* @implements       Fr_Flexray_GetGlobalTime_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetGlobalTime
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) cyclePtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) macroTickPtr
)
{
    /* Temporary value used for coherent 32bit read of two registers */
    VAR(uint32, AUTOMATIC) u32tmpVal_016;
    VAR(Std_ReturnType, AUTOMATIC) retVal_155 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    
    /* Read both MTCTR and CYCTR */
    u32tmpVal_016 = Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_MTCTR_ADDR16);
    
    /* Lower part contains CYCTR - cycle count */
    *cyclePtr = (VAR(uint8, AUTOMATIC))(u32tmpVal_016);
    /* Upper part contains MTCTR - macrotick */
    *macroTickPtr = (VAR(uint16, AUTOMATIC))(u32tmpVal_016 >> 16U);
    
    /* Check whether the read value does not exceed configured one */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    if(((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR10_11 >> 16U) & 0x3fffU) <= *macroTickPtr)
    {
        /* Register read issue - use saturated value */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        *macroTickPtr = (VAR(uint16, AUTOMATIC))(((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR10_11 >> 16U) & 0x3fffU) - 1U);
        /* Report error */
        retVal_155 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    
    return retVal_155;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetErrorMode
*
* @brief            FrIP function for the Fr_GetPOCStatus API
* @description      The FlexRay controller error mode is determined here.
* @param[in]        regValuePSR0 - Value of the FLEXRAY_PSR0_ADDR16 register.
* @param[out]       errorModePtr - Address the Error mode is stored to.
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to hardware error
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetErrorMode
(
    VAR(uint16, AUTOMATIC) regValuePSR0,
    P2VAR(Fr_ErrorModeType, AUTOMATIC, FR_APPL_DATA) errorModePtr
)
{
    /* Initialize variable */
    VAR(Std_ReturnType, AUTOMATIC) retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    
    /* Determine the error mode */
    switch(regValuePSR0 & FLEXRAY_PSR0_ERRMODE_MASK_U16)
    {
        case FLEXRAY_PSR0_ERRMODE_ACTIVE_U16:
            /* Store the Error mode to location referenced by given pointer */
            *errorModePtr = FR_ERRORMODE_ACTIVE;
            break;

        case FLEXRAY_PSR0_ERRMODE_PASSIVE_U16:
            /* Store the Error mode to location referenced by given pointer */
            *errorModePtr = FR_ERRORMODE_PASSIVE;
            break;

        case FLEXRAY_PSR0_ERRMODE_COMM_HALT_U16:
            /* Store the Error mode to location referenced by given pointer */
            *errorModePtr = FR_ERRORMODE_COMM_HALT;
            break;

        default:
            /* Reserved value cannot occur */
            *errorModePtr = FR_ERRORMODE_ACTIVE;
            retVal = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            break;
    }
    return retVal;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_WaitForCmdProcess
*
* @internal
* @brief            FrIP function for waiting until CC process current command or timeout expires
* @details          This API call wait until CHI process previous command or timeout expired.
*                   In case timeout expire report DEM error.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Waiting loop timeout reached before CHI processed previous
*                                   command.
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_WaitForCmdProcess
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_101 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16timeout_101 = 0U;   /* Temporary variable for never-ending while loop protection */
    VAR(boolean, AUTOMATIC) bEnd_101 = (VAR(boolean, AUTOMATIC))FALSE;    /* indicates if wait cycle should finish or not */
    
    /* Wait for processed command or timeout expiration */
    while((VAR(boolean, AUTOMATIC))FALSE == bEnd_101)
    {
        if(u16timeout_101 >= FR_IPW_MAX_WAITCYCLES_U8)
        {/* timout expired */
            bEnd_101 = (VAR(boolean, AUTOMATIC))TRUE;
        }
        if(FLEXRAY_POCR_BSY_U16 != (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_POCR_ADDR16) & FLEXRAY_POCR_BSY_U16))
        {/* BSY flag is not set, command was processed */
            bEnd_101 = (VAR(boolean, AUTOMATIC))TRUE;
        }
        u16timeout_101++;        /* Increment temporary counter */
    }

    if(u16timeout_101 < FR_IPW_MAX_WAITCYCLES_U8)
    {/* TempCycle did not reach the maximum value */
        retVal_101 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    }
    else
    {
        /* TempCycle reached the maximum value - detected error while accessing the CC */
    }
    return retVal_101;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_WaitForPOCState
*
* @internal
* @brief            Wait for selected POC state
* @details             This API call wait until CC process current command or timeout expired.
*                   In case timeout expire report DET error.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        pocState indicates which POC state should be reached
*                       - #FR_POCSTATE_DEFAULT_CONFIG POC:Default Config state
*                       - #FR_POCSTATE_CONFIG POC:Config state
*                       - #FR_POCSTATE_WAKEUP POC:Wakeup state
*                       - #FR_POCSTATE_READY POC:Ready state
*                       - #FR_POCSTATE_NORMAL_PASSIVE POC:Normal Passive state
*                       - #FR_POCSTATE_NORMAL_ACTIVE POC:Normal Active state
*                       - #FR_POCSTATE_HALT POC:Halt state
*                       - #FR_POCSTATE_STARTUP POC:Startup state
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_WaitForPOCState
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    CONST(uint16, AUTOMATIC) pocState
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_102 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    VAR(uint16, AUTOMATIC) u16timeout_102 = 0U;    /* Variable for timeout measurement */
    VAR(boolean, AUTOMATIC) bEnd_102 = (VAR(boolean, AUTOMATIC))FALSE;    /* indicates if wait cycle should finish or not */
    VAR(uint16, AUTOMATIC) u16pocState_102;    /* Current POC state */

    /* Wait for the selected POC state or timeout expiration */
    while((VAR(boolean, AUTOMATIC))FALSE == bEnd_102)
    {
        u16pocState_102 = Fr_Flexray_GetPOCState(ctrlIdx);
        if(u16pocState_102 == pocState)
        {/* desired POC state is reached - end wait cycle */
            bEnd_102 = (VAR(boolean, AUTOMATIC))TRUE;
        }

        if(u16timeout_102 >= FR_IPW_MAX_WAITCYCLES_U8)
        {/* timeous expired - end wait cycle */
            bEnd_102 = (VAR(boolean, AUTOMATIC))TRUE;
        }

        ++u16timeout_102;
    }

    if(u16timeout_102 >= FR_IPW_MAX_WAITCYCLES_U8)
    {/* TempCycle reached the maximum value - detected error while accessing the CC */
        /* If this API function detects errors while accessing any CC, it return E_NOT_OK and
        higher layer should call DEM function and return DEM: FR_E_ACCESS */
        retVal_102 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);    /* Indicate error */
    }

    return retVal_102;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_ReadRegister
*
* @brief            FrIP function for reading the value from the FlexRay CC register
* @description      Function reads value from the FlexRay module register depending on the register 
*                   offset value
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        regOffset - Offset to FlexRay CC register area
* @return           16bit register data
***************************************************************************************************/
static INLINE FUNC(uint16, FR_CODE) Fr_Flexray_ReadRegister
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    CONST(uint16, AUTOMATIC) regOffset
)
{
    VAR(uint16, AUTOMATIC) u16regValue;
    
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    u16regValue = *((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCBaseAddress) + (regOffset));
    return u16regValue;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_ReadRegister32
*
* @brief            FrIP function for reading the value from the FlexRay CC register
* @description      Function reads value from the FlexRay module register depending on the register 
*                   offset value
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        regOffset - Offset to FlexRay CC register area  
* @description      Function reads value from the 32bit FlexRay module register
* @return           32bit register data
***************************************************************************************************/
static INLINE FUNC(uint32, FR_CODE) Fr_Flexray_ReadRegister32
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    CONST(uint16, AUTOMATIC) regOffset
)
{
    VAR(uint32, AUTOMATIC) u32regValue;
    
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    u32regValue = *((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCBaseAddress) + (regOffset / 2U));
    /* Check the cpu byte order before reading the value from 32-bit register */
#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    u32regValue = (uint32)(((u32regValue << FLEXRAY_REGISTER_OFFSET_U8) & FLEXRAY_REGISTER_MASK_HIGH_U32) | (uint32)((u32regValue >> FLEXRAY_REGISTER_OFFSET_U8) & FLEXRAY_REGISTER_MASK_LOW_U32));
#endif /* CPU_BYTE_ORDER == LOW_BYTE_FIRST */
    return u32regValue;
}


/***************************************************************************************************
* @function_name    Fr_Flexray_WriteRegister
*
* @brief            FrIP function for writing into the FlexRay CC register
* @description      Function writes given value into the FlexRay module register depending on the 
*                   register offset value
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        regOffset - Offset to FlexRay CC register area 
* @param[in]        regValue - Value to be written into FlexRay CC register 
* @return           none
***************************************************************************************************/
static INLINE FUNC(void, FR_CODE) Fr_Flexray_WriteRegister
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    CONST(uint16, AUTOMATIC) regOffset,
    CONST(uint16, AUTOMATIC) regValue
)
{
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    *(((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCBaseAddress)) + regOffset) = regValue;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_WriteRegister32
*
* @brief            FrIP function for writing into the FlexRay CC register
* @description      Function writes given value into the FlexRay module register depending on the 
*                   register offset value
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        regOffset - Offset to FlexRay CC register area 
* @param[in]        regValue - Value to be written into FlexRay CC register 
* @return           none
***************************************************************************************************/
static INLINE FUNC(void, FR_CODE) Fr_Flexray_WriteRegister32
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    CONST(uint16, AUTOMATIC) regOffset,
    CONST(uint32, AUTOMATIC) regValue
)
{
    /* Check the cpu byte order before writing the value to 32-bit register */
#if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    VAR(uint32, AUTOMATIC) u32regValue_temp;

    u32regValue_temp = (uint32)((regValue << FLEXRAY_REGISTER_OFFSET_U8) & FLEXRAY_REGISTER_MASK_HIGH_U32) | (uint32)((regValue >> FLEXRAY_REGISTER_OFFSET_U8) & FLEXRAY_REGISTER_MASK_LOW_U32);    
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    *(((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCBaseAddress)) + (regOffset / 2U)) = u32regValue_temp;
#else /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    *(((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCBaseAddress)) + (regOffset / 2U)) = regValue;
#endif /* CPU_BYTE_ORDER == LOW_BYTE_FIRST */ 
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetData16Pointer
*
* @brief            FrIP function which returns pointer to 16bit data in the FlexRay memory
* @description      Function returns pointer to 16bit data in the FlexRay memory
* @param[in]        data16Address - Address in FlexRay memory  
* @return           16bit data pointer
***************************************************************************************************/
static INLINE FUNC(P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA), FR_CODE) Fr_Flexray_GetData16Pointer
(
    CONST(uint32, AUTOMATIC) data16Address
)
{
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    return (P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA)) (data16Address);
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetData32Pointer
*
* @brief            FrIP function which returns pointer to 32bit data in the FlexRay memory
* @description      Function returns pointer to 32bit data in the FlexRay memory
* @param[in]        data32Address - Address in FlexRay memory 
* @return           32bit data pointer
***************************************************************************************************/
static INLINE FUNC(P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA), FR_CODE) Fr_Flexray_GetData32Pointer
(
    CONST(uint32, AUTOMATIC) data32Address
)
{
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    return (P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA)) (data32Address);
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetNmVector
*
* @brief            FrIP function for the Fr_GetNmVector API
* @description      Read the network management vector of the last communication cycle
*                   and write it to the output parameter Fr_NmVectorPtr. The number of bytes
*                   written to the output parameter is constant and known at configuration time
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       nmVectorPtr - Address of the variable the NmVector is stored to
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements        Fr_Flexray_GetNmVector_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetNmVector
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) nmVectorPtr,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) hwErr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_34 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    /* Indicates if wait cycle should finish or not */
    VAR(boolean, AUTOMATIC) bEnd_34 = (VAR(boolean, AUTOMATIC))FALSE;
    /* 8bit pointer to FlexRay register space */
    P2VAR(volatile uint8, AUTOMATIC, FR_APPL_DATA) pccRegPtr8_34;
    VAR(uint8, AUTOMATIC) u8fr_p_34;       /* Temporary counter used for copying */
    VAR(uint16, AUTOMATIC) u16nmvLen_34;    /* Temporary variable for NMV length */
    /* Variable for data consistent check */
    VAR(boolean, AUTOMATIC) bdataCons_34;
    VAR(uint8, AUTOMATIC) u8readCnt_34 = 0U;    /* Data read count */
    
    /* pccRegPtr8_34 points to base address of the CC referenced by Fr_CtrlIdx (8bit format) */
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    pccRegPtr8_34 = (P2VAR(volatile uint8, AUTOMATIC, FR_APPL_DATA))((Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCBaseAddress);
    /* Load the length of NMV in Bytes */
    u16nmvLen_34 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_NMVLR_ADDR16) & FLEXRAY_NMVLR_MASK_U16);
    
    /* Check validity of the register value */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    if(u16nmvLen_34 != (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gNetworkManagementVectorLength)
    {
        /* Indicate HW error */
        *hwErr = (VAR(boolean, AUTOMATIC))TRUE;
        /* Use valid value */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16nmvLen_34 = (VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gNetworkManagementVectorLength);
    }
    else
    {
        *hwErr = (VAR(boolean, AUTOMATIC))FALSE;
    }
    
    /* Read data while they are not consistent and valid (FR265) or
    maximum count of read cycles was performed (never-ending loop protection) */
    while((VAR(boolean, AUTOMATIC))FALSE == bEnd_34)
    {
        /* assume that data are consistent. If not so, this value will be updated */
        bdataCons_34 = (VAR(boolean, AUTOMATIC))TRUE;
        
        /* Copy all network management vector items */
        for(u8fr_p_34 = 0U; u8fr_p_34 < u16nmvLen_34; u8fr_p_34++)
        {
            #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
            if((u8fr_p_34 & (uint8)0x01) == (uint8)0x00)
            {
                /* Check if data are consistent or need to be updated */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                if(nmVectorPtr[u8fr_p_34] != pccRegPtr8_34[FLEXRAY_NMVR0_8BIT + u8fr_p_34 + (uint8)0x01])
                {
                    /* Copy vector value into memory location given by reference*/
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    nmVectorPtr[u8fr_p_34] = pccRegPtr8_34[FLEXRAY_NMVR0_8BIT + u8fr_p_34 + (uint8)0x01];
                    /* Indicate data inconsitency => another check is required */
                    bdataCons_34 = (VAR(boolean, AUTOMATIC))FALSE;
                }
            }
            else
            {                     
                /* Check if data are consistent or need to be updated */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */            
                if(nmVectorPtr[u8fr_p_34] != pccRegPtr8_34[(FLEXRAY_NMVR0_8BIT + u8fr_p_34) - (uint8)1])
                {
                    /* Copy vector value into memory location given by reference*/
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    nmVectorPtr[u8fr_p_34] = pccRegPtr8_34[(FLEXRAY_NMVR0_8BIT + u8fr_p_34) - (uint8)1];
                    /* Indicate data inconsitency => another check is required */
                    bdataCons_34 = (VAR(boolean, AUTOMATIC))FALSE;
                }
            }
            #else
            /* Check if data are consistent or need to be updated */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            if(nmVectorPtr[u8fr_p_34] != pccRegPtr8_34[FLEXRAY_NMVR0_8BIT + u8fr_p_34])
            {
                /* Copy vector value into memory location given by reference*/
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                nmVectorPtr[u8fr_p_34] = pccRegPtr8_34[FLEXRAY_NMVR0_8BIT + u8fr_p_34];
                /* Indicate data inconsitency => another check is required */
                bdataCons_34 = (VAR(boolean, AUTOMATIC))FALSE;
            }
            #endif
        }
        /* Another read is done */
        u8readCnt_34++;

        if(bdataCons_34)
        {/* Data is consistent */
            bEnd_34 = (VAR(boolean, AUTOMATIC))TRUE;
            retVal_34 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); /* API call was successful */
        }
        if(u8readCnt_34 > FR_IPW_MAX_NMVREAD_U8)
        {/* Timeout has expired */
            bEnd_34 = (VAR(boolean, AUTOMATIC))TRUE;
        } 
    }
    
    /* In the case of hw error update the return value */
    if((VAR(boolean, AUTOMATIC))TRUE == *hwErr)
    {
        retVal_34 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK); 
    }
    
    return retVal_34;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetChannelStatus
*
* @brief            FrIP function for the Fr_GetChannelStatus API
* @description      Reads the aggregated channel status, NIT status and symbol window status from 
*                   FLEXRAY_PSR2_ADDR16, and FLEXRAY_PSR3_ADDR16 registers
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       channelAStatusPtr - Address of the variable the channel A status is stored to
* @param[out]       channelAStatusPtr - Address of the variable the channel A status is stored to
* @return           none
*
* @implements       Fr_Flexray_GetChannelStatus_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_GetChannelStatus
( 
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAStatusPtr, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBStatusPtr
)
{
    VAR(uint16, AUTOMATIC) u16tmpRegVal_40; /* Temporary variable for register access */
    
    /* Read PSR2 register */
    u16tmpRegVal_40 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PSR2_ADDR16);
    
    *channelBStatusPtr = (VAR(uint16, AUTOMATIC))((u16tmpRegVal_40 & FLEXRAY_PSR2_CHB_MASK_U16) >> 2U);
    *channelAStatusPtr = (VAR(uint16, AUTOMATIC))((u16tmpRegVal_40 & FLEXRAY_PSR2_CHA_MASK_U16) << 4U);
    
    /* Read PSR3 register */
    u16tmpRegVal_40 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PSR3_ADDR16);
    
    *channelBStatusPtr |= ((u16tmpRegVal_40 & FLEXRAY_PSR3_CHB_MASK_U16) >> 8U);
    *channelAStatusPtr |= (u16tmpRegVal_40 & FLEXRAY_PSR3_CHA_MASK_U16);
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetClockCorrection
*
* @brief            FrIP function for the Fr_GetChannelStatus API
* @description      Read rate and offset correction values from FR_RTCORVR and FR_OFCORVR registers
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       rateCorrectionPtr - Address of the variable the rate correction value is 
*                                       stored to
* @param[out]       offsetCorrectionPtr - Address of the variable the offset correction value is 
*                                         stored to
*
* @implements       Fr_Flexray_GetClockCorrection_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetClockCorrection
( 
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) rateCorrectionPtr, 
    P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) offsetCorrectionPtr
)
{
    VAR(uint32, AUTOMATIC) u32RateOffsetCorrMax_156;
    VAR(sint16, AUTOMATIC) s16tmpVal_156;
    VAR(uint32, AUTOMATIC) u32tmpVal_156;
    VAR(Std_ReturnType, AUTOMATIC) retVal_156 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
  
    /* Get pRateCorrectionOut maximum magnitude from configuration */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u32RateOffsetCorrMax_156 = (VAR(uint32, AUTOMATIC))((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR14_15 >> 21U) & 0x000007FFU;
    /* Read signed extended rate correction value */
    *rateCorrectionPtr = (VAR(sint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_RTCORVR_ADDR16));
    /* Prepare absolute value */
    s16tmpVal_156 = *rateCorrectionPtr;
    if(s16tmpVal_156 < 0)
    {
        s16tmpVal_156 = (VAR(sint16, AUTOMATIC))(-(s16tmpVal_156));
    }
    /* Check range */
    if(s16tmpVal_156 > (VAR(sint16, AUTOMATIC))(u32RateOffsetCorrMax_156))
    {
        /* Not-In-Range, use saturated value */
        *rateCorrectionPtr = (VAR(sint16, AUTOMATIC))(u32RateOffsetCorrMax_156);
        /* Indicate error */
        retVal_156 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    
    /* Get pOffsetCorrectionOut maximum magnitude from configuration */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u32RateOffsetCorrMax_156 = (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR8_9 & 0x00003FFFU;
    /* Read offset correction value */
    u32tmpVal_156 = (VAR(uint32, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_OFCORVR_ADDR16));
    /* Extend the read value to 32-bit signed int and prepare absolute value */
    s16tmpVal_156 = (VAR(sint16, AUTOMATIC))(u32tmpVal_156);
    if(s16tmpVal_156 < 0)
    {
        u32tmpVal_156 |= 0xffff0000U;
        s16tmpVal_156 = (VAR(sint16, AUTOMATIC))(-(s16tmpVal_156));
    }
    /* Check range */
    if(s16tmpVal_156 > (VAR(sint16, AUTOMATIC))(u32RateOffsetCorrMax_156))
    {
        /* Not-In-Range, use saturated value */
        *offsetCorrectionPtr = (VAR(sint32, AUTOMATIC))(u32RateOffsetCorrMax_156);
        /* Indicate error */
        retVal_156 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    else
    {
        /* Store the output value */
        *offsetCorrectionPtr = (sint32)(u32tmpVal_156);
    }
    
    return retVal_156;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetSyncFrameList
*
* @brief            FrIP function for the Fr_GetSyncFrameList API
* @description      Reads syncFrame List ID table from FlexRay memory
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       channelAEvenListPtr - Address of the variable the channel A even list is 
*                                         stored to
* @param[out]       channelBEvenListPtr - Address of the variable the channel B even list is 
*                                         stored to
* @param[out]       channelAOddListPtr - Address of the variable the channel A odd list is 
*                                        stored to
* @param[out]       channelBOddListPtr - Address of the variable the channel B odd list is 
*                                        stored to  
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements        Fr_Flexray_GetSyncFrameList_Activity    
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetSyncFrameList
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) listSize, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAOddListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBOddListPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal_42 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint8, AUTOMATIC) i_42;          /* Temporary variable for copying process access */
    VAR(uint16, AUTOMATIC) u16tmpSyncFrameCnt_42;   /* Temporary variable for Sync Frame Counter */
    VAR(uint8, AUTOMATIC) u8tmpListSizeChAEven_42; /* Temporary variable for listSize chA even */
    VAR(uint8, AUTOMATIC) u8tmpListSizeChBEven_42; /* Temporary variable for listSize chB even */
    VAR(uint8, AUTOMATIC) u8tmpListSizeChAOdd_42;  /* Temporary variable for listSize chA odd */
    VAR(uint8, AUTOMATIC) u8tmpListSizeChBOdd_42;  /* Temporary variable for listSize chB odd */
    VAR(uint8, AUTOMATIC) u8tmpListSizeMax_42;     /* Temporary variable for max listSize */
    
    if(15U >= listSize)
    {
        u8tmpListSizeMax_42 = listSize;
    }
    else
    {/* Maximum 15 syncframes shall be supported */
        u8tmpListSizeMax_42 = 15U;
    }
    /* Check if both EVAL OVAL bits are set */
    if((FLEXRAY_SFTCCSR_EVAL_U16 | FLEXRAY_SFTCCSR_OVAL_U16) == ((Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_SFTCCSR_ADDR16)) & (FLEXRAY_SFTCCSR_EVAL_U16 | FLEXRAY_SFTCCSR_OVAL_U16)))
    {
        /* Lock even/odd cycle tables */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_SFTCCSR_ADDR16, (FLEXRAY_SFTCCSR_OLKT_U16 | FLEXRAY_SFTCCSR_ELKT_U16));

        /* Check Even/Odd Cycle Table Lock Status */
        if((FLEXRAY_SFTCCSR_ELKS_U16 | FLEXRAY_SFTCCSR_OLKS_U16) == ((Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_SFTCCSR_ADDR16)) & (FLEXRAY_SFTCCSR_ELKS_U16 | FLEXRAY_SFTCCSR_OLKS_U16 | FLEXRAY_SFTCCSR_SIDEN_U16)))
        {
            /* Read Sync Frame Counter for all subset of sync table */
            u16tmpSyncFrameCnt_42 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_SFCNTR_ADDR16);
            /* Prepare list size for channel A Even Sync Frames */
            u8tmpListSizeChAEven_42 = (VAR(uint8, AUTOMATIC))((u16tmpSyncFrameCnt_42 & 0x0F00U) >> 8U);
            /* Prepare list size for channel B Even Sync Frames */
            u8tmpListSizeChBEven_42 = (VAR(uint8, AUTOMATIC))((u16tmpSyncFrameCnt_42 & 0xF000U) >> 12U);
            /* Prepare list size for channel A Odd Sync Frames */
            u8tmpListSizeChAOdd_42 = (VAR(uint8, AUTOMATIC))(u16tmpSyncFrameCnt_42 & 0x000FU);
            /* Prepare list size for channel B Odd Sync Frames */
            u8tmpListSizeChBOdd_42 = (VAR(uint8, AUTOMATIC))((u16tmpSyncFrameCnt_42 & 0x00F0U) >> 4U); 
            
            for(i_42 = 0U; i_42 < u8tmpListSizeMax_42; i_42++)
            {
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                channelAEvenListPtr[i_42] = 0U;
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                channelBEvenListPtr[i_42] = 0U;
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                channelAOddListPtr[i_42] = 0U;
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                channelBOddListPtr[i_42] = 0U;
                if(i_42 < u8tmpListSizeChAEven_42)
                {/* Copy channel A Even Sync Frame ID Table */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    channelAEvenListPtr[i_42] = *(Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress + (Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->SyncFrameTableOffset) + i_42);
                }
                if(i_42 < u8tmpListSizeChBEven_42)
                {/* Copy channel B Even Sync Frame ID Table */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    channelBEvenListPtr[i_42] = *(Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress + (Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->SyncFrameTableOffset + 0x001EU) + i_42);
                }     
                if(i_42 < u8tmpListSizeChAOdd_42)
                {/* Copy channel A Odd Sync Frame ID Table */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    channelAOddListPtr[i_42] = *(Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress + (Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->SyncFrameTableOffset + 0x003CU) + i_42);
                }   
                if(i_42 < u8tmpListSizeChBOdd_42)
                {/* Copy channel B Odd Sync Frame ID Table */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    channelBOddListPtr[i_42] = *(Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress + (Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->SyncFrameTableOffset + 0x005AU) + i_42);
                } 
            }
            
            /* Unlock even/odd cycle table and enable generation*/
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_SFTCCSR_ADDR16, (FLEXRAY_SFTCCSR_ELKT_U16 | FLEXRAY_SFTCCSR_OLKT_U16 | FLEXRAY_SFTCCSR_SIDEN_U16));
            
            /* Check Even Cycle Table Lock Status */
            if(FLEXRAY_SFTCCSR_ELKS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_SFTCCSR_ADDR16) & FLEXRAY_SFTCCSR_ELKS_U16))
            {
                /* Tables were not unlocked */
            }
            /* Check Odd Cycle Table Lock Status */
            else if(FLEXRAY_SFTCCSR_OLKS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_SFTCCSR_ADDR16) & FLEXRAY_SFTCCSR_OLKS_U16))
            {   
                /* Tables were not unlocked */
            }
            else
            {   
                /* Tables were unlocked successfully*/ 
                retVal_42 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
        }
        else
        {   
            /* Tables were not locked return E_NOT_OK */
        }
    }
    else
    {
        /* EVAL OVAL bits are not set, table is not valid return E_NOT_OK  */
    }
    
    return retVal_42;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_GetWakeupRxStatus
*
* @brief            FrIP function for the Fr_GetWakeupRxStatus API
* @description      Reads the Wakeup Symbol Received on channel A and channel B bits from the 
*                   FLEXRAY_PSR3_ADDR16 register
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       wakeupRxStatusPtr - Address of a variable where the wakeup Rx status is stored to
* @return           none
*
* @implements        Fr_Flexray_GetWakeupRxStatus_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetWakeupRxStatus
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) wakeupRxStatusPtr
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal_43 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16tmpRegVal_43; /* Temporary variable for register access */
    
    /* Read PSR3 register */
    u16tmpRegVal_43 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PSR3_ADDR16);
    
    /* Store wakeup symbol received on channel A */
    *wakeupRxStatusPtr = (VAR(uint8, AUTOMATIC))((u16tmpRegVal_43 & FLEXRAY_PSR3_WUA_U16) >> 5U);
    
    /* Store wakeup symbol recieved on channel B */
    *wakeupRxStatusPtr |= (VAR(uint8, AUTOMATIC))((u16tmpRegVal_43 & FLEXRAY_PSR3_WUB_U16) >> 12U);
    
    /* Clear both WUA and WUB flags */
    if(0U != (u16tmpRegVal_43 & (FLEXRAY_PSR3_WUB_U16 | FLEXRAY_PSR3_WUA_U16)))
    {
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_PSR3_ADDR16, FLEXRAY_PSR3_WUB_U16 | FLEXRAY_PSR3_WUA_U16);
    }
    if (0U == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PSR3_ADDR16) & (FLEXRAY_PSR3_WUB_U16 | FLEXRAY_PSR3_WUA_U16)))
    {
        retVal_43 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); /* Flags were cleared */
    }
    
    return retVal_43;
} 

/***************************************************************************************************
* @function_name    Fr_Flexray_ReadbackCCConfig
*
* @brief            FrIP function for the Fr_ControllerInit API
* @description      Read back and compare cluster and configuration values to reference values 
*                   held in the configuration.
* @param[in]        ctrlIdx - Index of FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      Configuration is OK
*                       - E_NOT_OK  Error in configuration was found
*
* @implements        Fr_Flexray_ReadbackCCConfig_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_ReadbackCCConfig
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR0_1 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR0_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR2_3 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR2_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR4_5 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR4_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);    
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR6_7 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR6_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR8_9 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR8_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR10_11 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR10_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR12_13 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR12_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR14_15 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR14_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR16_17 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR16_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR18_19 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR18_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR20_21 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR20_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR22_23 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR22_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR24_25 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR24_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR26_27 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR26_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR28_29 != Fr_Flexray_ReadRegister32(ctrlIdx, FLEXRAY_PCR28_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    else if((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->RegPCR30 != Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_PCR30_ADDR16))
    {
        retVal_00 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    else
    {
        /* PCR registers check finished without error */
    }
    
    return retVal_00;
} 

/***************************************************************************************************
* @function_name    Fr_Flexray_TransmitTxLPdu
*
* @brief            FrIP function for the Fr_TransmitTxLPdu API
* @description      Copy data and activate it for transmission
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be transmitted 
* @param[in]        lsduPtr - Address of data to be transmitted
* @param[in]        lsduLength - Payload length of data to be transmitted
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_Flexray_TransmitTxLPdu_Activity 
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_TransmitTxLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lpduIdx,
    P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) lsduPtr, 
    VAR(uint8, AUTOMATIC) lsduLength
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_11 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    /*  Temporary offset address of message buffer registers */
    VAR(uint16, AUTOMATIC) u16mbRegOffset_11;
    /* Current MB index which is configured for given lpduIdx */
    VAR(uint8, AUTOMATIC) u8tmpBuffIdx_11;
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_11;
    /* Pointer to data field in FR memory in 16-bit format */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pdataMBPtr16_11;
    /* Pointer to data field in FR memory in 8bit format */
    P2VAR(volatile uint8, AUTOMATIC, FR_APPL_DATA) pdataMBPtr8_11;
    /* Pointer to data field in FR memory space in 32-bit format */
    P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA) pdataMBPtr32_11;
    VAR(uint16, AUTOMATIC) u16regValue_11;    /* Temporary variable for register access */
    VAR(uint8, AUTOMATIC) u8fr_p_11;    /* Temporary counter used for copying */
    #ifdef FR_UNUSED_BIT_VALUE_U8
    VAR(uint8, AUTOMATIC) u8fr_o_11;    /* Temporary counter used for copying */
    #endif
    /* Pointer to one instance of Fr_CCTxBufferConfigType */
    P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST) ptxCfgPtr_11;
    VAR(uint8, AUTOMATIC) u8tmpLen_11;  /* Temp. data payload length rounded to words (9B->5Words) */
    #ifdef FR_UNUSED_BIT_VALUE_U8
    VAR(uint8, AUTOMATIC) u8tmpPayloadLen_11;  /* Temp. value of data payload length in static seg. */
    #endif /* FR_UNUSED_BIT_VALUE_U8 */
    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    VAR(uint8, AUTOMATIC) u8tmpdata;         /* Temporary variable for data */
    VAR(uint16, AUTOMATIC) u16tmpdata;
    VAR(uint32, AUTOMATIC) u32tmpdata;
    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
    
    /* Store the reference to transmit buffer configuration */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    ptxCfgPtr_11 = (P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lpduIdx].BufferConfigPtr);
    
    /* Store configured MB index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u8tmpBuffIdx_11 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lpduIdx].MessageBufferNumber;

    u16mbRegOffset_11 = (((VAR(uint16, AUTOMATIC))u8tmpBuffIdx_11) * 4U);
    
    /* It is necessary to read the MB index from FR_MBIDXR register since it could be changed during MB reconfiguration:
       TX->(RX->index swapped with RXShadow)->TX */
    /* Load current MB index - the original value of u8tmpBuffIdx_11 is replaced by the index of message buffer header field */
    u8tmpBuffIdx_11 = (VAR(uint8, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBIDXR0_ADDR16 + u16mbRegOffset_11));
                                                                                 
    /* Check whether the read value not greather than the last utilized MB index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    if(u8tmpBuffIdx_11 <= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B2BufferIndexInit)
    {
        /* Read FR_MBCCSR register value */
        u16regValue_11 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_11);
        /* Message buffer configured for Tx ? */
        if(FLEXRAY_MBCCSR_MTD_U16 == (u16regValue_11 & FLEXRAY_MBCCSR_MTD_U16))
        {
            /* Lock MB -> write 1 to LCKT bit and 0 to the EDT bit in FR_MBCCSR register for current MB
              (write access to all other bits is ignored) */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_11, FLEXRAY_MBCCSR_LCKT_U16);
            
            /* Read the MB again for checking if the MB is locked, */
            /* otherwise the MB is busy or there is an error -> report error */
            /* Is the MB locked? */
            if(FLEXRAY_MBCCSR_LCKS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_11) & FLEXRAY_MBCCSR_LCKS_U16))
            {   /* MB is locked */
                /* Calculate the message buffer header */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                /* @violates @ref FR_FLEXRAY_C_REF_1 */
                /* @violates @ref FR_FLEXRAY_C_REF_11 */
                pheaderMBPtr_11 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u8tmpBuffIdx_11 * FLEXRAY_HEADER_SIZE);
                
                /* Driver execution time optimization - data offset is not loaded from structure of type 
                   Fr_CCLpduInfoType, but from structure of type Fr_CCBufferOffsetType */
                /* Load MB Data pointer for 32-bit access */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                /* @violates @ref FR_FLEXRAY_C_REF_1 */
                /* @violates @ref FR_FLEXRAY_C_REF_11 */
                pdataMBPtr32_11 = Fr_Flexray_GetData32Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpBuffIdx_11].MbDataAddrPtr);
                /* Data copying process - optimized for the speed */
                /* Copies lsduLength bytes from address lsduPtr into the FlexRay CCs transmission 
                   resource */
                /* 32-bit copying process */
                /* Example: lsduLength = 35 Bytes [0..34], FR_UNUSED_BIT_VALUE_U8 is not defined */
                /* For  data[B] <= 4n  ,where n = PayloadLength / 4 */
                for(u8fr_p_11 = 0U; u8fr_p_11 < (lsduLength >> 2U); u8fr_p_11++)
                {
                    /* Fr_CtrlIdx: Memory: Data Field */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    pdataMBPtr32_11[u8fr_p_11] = ((P2CONST(volatile uint32, AUTOMATIC, FR_APPL_CONST))lsduPtr)[u8fr_p_11];
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u32tmpdata = pdataMBPtr32_11[u8fr_p_11];
                    u32tmpdata = (uint32)(((uint32)(u32tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32) | ((uint32)(u32tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    pdataMBPtr32_11[u8fr_p_11] = u32tmpdata;
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */ 
                }
                /* Example: first 32 Bytes are copied [0..31], u8fr_p_11 = 7+1 */
                /* Convert 32-bit counter of last copied byte to 16-bit counter */
                u8fr_p_11 = (VAR(uint8, AUTOMATIC))((u8fr_p_11 * 2U) & 0xFFU);
                /* 16-bit copying process */
                if(u8fr_p_11 < (lsduLength >> 1U))
                {/* Copy the following two bytes only if((PayloadLength % 4) > 1)*/
                    /* Load MB Data pointer for 16-bit access */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    /* @violates @ref FR_FLEXRAY_C_REF_12 */
                    pdataMBPtr16_11 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpBuffIdx_11].MbDataAddrPtr);
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    pdataMBPtr16_11[u8fr_p_11] = ((P2CONST(volatile uint16, AUTOMATIC, FR_APPL_CONST))lsduPtr)[u8fr_p_11];
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u16tmpdata = pdataMBPtr16_11[u8fr_p_11];
                    u16tmpdata = (uint16)(((uint16)(u16tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16) | ((uint16)(u16tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    pdataMBPtr16_11[u8fr_p_11] = u16tmpdata;
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                    u8fr_p_11++;
                }
            
                /* Example: next 2 Bytes are copied [32..33], u8fr_p_11 = 16+1 */
                /* 8bit copying process  - convert 16-bit counter of last copied byte to
                   8bit counter */   
                u8fr_p_11 = (VAR(uint8, AUTOMATIC))((u8fr_p_11 * 2U) & 0xFFU);
                /* Copy the last byte only if((PayloadLength % 2) != 0) */
                if(u8fr_p_11 < (lsduLength))
                {
                    /* Load MB Data pointer for 8bit access */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    /* @violates @ref FR_FLEXRAY_C_REF_12 */
                    /* @violates @ref FR_FLEXRAY_C_REF_13 */
                    pdataMBPtr8_11 = (P2VAR(volatile uint8, AUTOMATIC, FR_APPL_DATA))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpBuffIdx_11].MbDataAddrPtr);
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    pdataMBPtr8_11[u8fr_p_11] = ((P2CONST(volatile uint8, AUTOMATIC, FR_APPL_CONST))lsduPtr)[u8fr_p_11];
            
                    /* Increment counter */
                    u8fr_p_11++;
                    /* Set the remaining bits only if FR_UNUSED_BIT_VALUE_U8
                    (i.e. FrUnusedBitValue) parameter is defined */
                    #ifdef FR_UNUSED_BIT_VALUE_U8
                    /* Set the remaining bits in CCs transmission buffer to the configured
                       value given by parameter FrUnusedBitValue */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    pdataMBPtr8_11[u8fr_p_11] = FR_UNUSED_BIT_VALUE_U8;
                    #endif /* FR_UNUSED_BIT_VALUE_U8 */
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u8tmpdata = pdataMBPtr8_11[u8fr_p_11];
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    pdataMBPtr8_11[u8fr_p_11] = pdataMBPtr8_11[u8fr_p_11 - (uint8)1];
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    pdataMBPtr8_11[u8fr_p_11 - (uint8)1] = u8tmpdata;
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                    u8fr_p_11++;
                }
                /* Example: Last Byte is copied [34], u8fr_p_11 = 34+1 */
                /* if FR_UNUSED_BIT_VALUE_U8 is defined, last byte is set to this value [34..35], 
                   u8fr_p_11 = 34+1+1 */
            
                /* Only for MB configured for static segment */
                /* Set the remaining bits only if FR_UNUSED_BIT_VALUE_U8
                  (i.e. FrUnusedBitValue) parameter is defined */
                #ifdef FR_UNUSED_BIT_VALUE_U8
                /* Check whether the MB is configured for static segment
                   of communication cycle */
                /* @violates @ref FR_FLEXRAY_C_REF_7 */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                if(ptxCfgPtr_11->TxFrameID < ((Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gNumberOfStaticSlots + 1U))
                {
                    /* Data update process - optimized for the speed */
                    /* Load the payload length value for static slots */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u8tmpPayloadLen_11 = (Fr_pCfgPtr + ctrlIdx)->LowLevelConfigSetPtr->gPayloadLengthStatic;
                    /* Convert 8bit counter of last updated byte to 16-bit counter */
                    u8fr_p_11 = u8fr_p_11 >> 1U;
                    /* Check whether another update process is required - if whole buffer is not already 
                       updated */
                    if(u8fr_p_11 < u8tmpPayloadLen_11)
                    {
                        /* Load MB Data pointer for 16-bit access */
                        /* @violates @ref FR_FLEXRAY_C_REF_4 */
                        /* @violates @ref FR_FLEXRAY_C_REF_1 */
                        /* @violates @ref FR_FLEXRAY_C_REF_11 */
                        pdataMBPtr16_11 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpBuffIdx_11].MbDataAddrPtr);
            
                        /* Rounding to 16-bit before 32-bit process */
                        /* Example: gPayloadLengthStatic = 46 Bytes [0..45], 
                                    function got 37 Bytes [0..36], data + last byte with 
                                    FR_UNUSED_BIT_VALUE_U8 already copied [0..37], u8fr_p_11 = 38 */
            
                        /* Check if rounding is required before 32-bit process 
                           - Is the last updated word odd? */
                        if(0U != (u8fr_p_11 % 2U))
                        {
                            /* Yes, the last updated word is odd - rounding is required before
                               32-bit process */
                            /* Set one word to the configured value given by parameter
                               FrUnusedBitValue */
                            /* Fr_CtrlIdx: Memory: Data Field */
                            /* @violates @ref FR_FLEXRAY_C_REF_4 */
                            pdataMBPtr16_11[u8fr_p_11] = FR_UNUSED_BIT_VALUE_U16;
                            u8fr_p_11++;                 /* Increment counter to next word */
                        }
                        /* Example: one 16-bit value is updated with
                        FR_UNUSED_BIT_VALUE_U8 [0..39], u8fr_p_11 = 20 */
            
                        /* 32-bit update process - convert 16-bit counter of last updated byte
                           to 32-bit counter */
                        u8fr_o_11 = u8fr_p_11 >> 1U;
                        /* Update all remaining 32-bit units */
                        for(u8fr_p_11 = u8fr_o_11; u8fr_p_11 < (u8tmpPayloadLen_11 >> 1U); u8fr_p_11++)
                        {
                            /* Set all remaining 32-bit units to the configured value given by
                               parameter FrUnusedBitValue */
                            /* Fr_CtrlIdx: Memory: Data Field */
                            /* @violates @ref FR_FLEXRAY_C_REF_4 */
                            pdataMBPtr32_11[u8fr_p_11] = FR_UNUSED_BIT_VALUE_U32;
                        }
                        /* Example: all remaining 32-bit units are updated with
                           FR_UNUSED_BIT_VALUE_U8 [0..43], u8fr_p_11 = 10+1 */
                        /* Convert 32-bit counter of last copied byte to 16-bit counter */
                        u8fr_o_11 = (VAR(uint8, AUTOMATIC))((u8fr_p_11 * 2U) & 0xFFU);
            
                        /* Update the remaining 16-bit unit if(gPayloadLengthStatic % 2) */
                        for(u8fr_p_11 = u8fr_o_11; u8fr_p_11 < u8tmpPayloadLen_11; u8fr_p_11++)
                        {
                            /* Set one word to the configured value given by parameter
                               FrUnusedBitValue */
                            /* Fr_CtrlIdx: Memory: Data Field */
                            /* @violates @ref FR_FLEXRAY_C_REF_4 */
                            pdataMBPtr16_11[u8fr_p_11] = FR_UNUSED_BIT_VALUE_U16;
                        }
                        /* Example: the last remaining 16-bit unit is updated with
                           FR_UNUSED_BIT_VALUE_U8 [0..45], u8fr_p_11 = 22+1 */
                    }
                }
                #endif /* FR_UNUSED_BIT_VALUE_U8 */
                /* Data length (lsduLength) check is performed earlier if
                   FR_DEV_ERROR_DETECT is set */
                /* Check if FrIfAllowDynamicLSduLength parameter is configured for
                   relevant frame */
                if(ptxCfgPtr_11->AllowDynamicLength)
                {
                    /* FrIfAllowDynamicLSduLength shall be reconfigured to the length given
                       by the lsduLength parameter*/
                    u8tmpLen_11 = lsduLength >> 1U;   /* Convert to Words */
                    if(0U != (lsduLength % 2U))     /* Check if PayloadLength is odd value */
                    {
                    /* Convert to Words and round up, for example 9B -> 5W */
                        u8tmpLen_11 += 1U;
                    }
            
                    /* The MB is configured for dynamic segment - the payload d length can be changed */
                    /* Is the configured payload data length different than required 
                       (by function parameter) */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    if((pheaderMBPtr_11[1U] & FLEXRAY_FRAMEHEADER1_PLDLENMASK_U16) != u8tmpLen_11)
                    {   /* Yes, payload data length value is different */
                        /* Payload data length parameter and CRC have to be changed */
                        /* @violates @ref FR_FLEXRAY_C_REF_4 */
                        pheaderMBPtr_11[1U] = u8tmpLen_11;
                        /* Calculate new header_crc
                           - it is not calculation of configuration data */
                        /* @violates @ref FR_FLEXRAY_C_REF_4 */
                        pheaderMBPtr_11[2U] = Fr_Flexray_CalcHeaderCRC(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBFIDR0_ADDR16 + u16mbRegOffset_11), (VAR(uint16, AUTOMATIC))u8tmpLen_11);
                    }
                }
                /* Set MB to commit */
                /* Clear Transmit Buffer Interrupt Flag */
                /* Load FR_MBCCSRn register and select only necessary bits */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_05();
                u16regValue_11 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_11) & FLEXRAY_MBCCSR0_CONFIG_MASK_U16);
                u16regValue_11 |= (VAR(uint16, AUTOMATIC))(FLEXRAY_MBCCSR_CMT_U16 | FLEXRAY_MBCCSR_MBIF_U16);
                Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_11, u16regValue_11);
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_05();
            
                /* Attempt to unlock MB */
                /* If the application writes 1 to LCKT bit and 0 to the EDT bit, the write
                   access to all other bits is ignored */
                Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_11, FLEXRAY_MBCCSR_LCKT_U16);
                
                retVal_11 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);        /* API call was successful */
            
            }
            else  /* MB is not locked */
            {
                retVal_11 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            }
        }
        else
        {
            /* HW error MB is not configured for Tx -> return E_NOT_OK */
        }
    }
    return retVal_11; 
}

/***************************************************************************************************
* @function_name    Fr_Flexray_CalcHeaderCRC
*
* @brief            Header CRC calculating
* @details          This function calculates value of the header CRC field
*                   It calculates the CRC only for the frames which are not
*                   startup and sync frames
* @note             Not intended for the startup and sync frames CRC calculation
* @param[in]        FrameId Frame ID
* @param[in]        PayloadLen Data payload length
* @return           ::uint16 - Calculated CRC Value
***************************************************************************************************/
static FUNC(uint16, FR_CODE) Fr_Flexray_CalcHeaderCRC
(
  CONST(uint16, AUTOMATIC) FrameId,
  CONST(uint16, AUTOMATIC) PayloadLen
)
{
    VAR(uint16, AUTOMATIC) u16crc_106;
    VAR(uint16, AUTOMATIC) u16nextBit_106;
    VAR(uint16, AUTOMATIC) u16crcu16nextBit_106;
    VAR(sint16, AUTOMATIC) s16fr_i_106;

    /* Calculate crc over sync bit */
    /* Calculate crc over startup bit */
    u16crc_106 = 0x68U;
    /* Calculate crc over frameID field in a network order */
    for(s16fr_i_106 = 10; s16fr_i_106 >= 0; s16fr_i_106--)
    {
        u16nextBit_106 = (VAR(uint16, AUTOMATIC))((FrameId >> (VAR(uint8, AUTOMATIC))s16fr_i_106) & 0x0001U);
        u16crcu16nextBit_106 = (VAR(uint16, AUTOMATIC))(u16nextBit_106 ^ ((u16crc_106 >> 10U) & 0x0001U));
        u16crc_106 = (VAR(uint16, AUTOMATIC))(u16crc_106 << 1U);
        if(0U != u16crcu16nextBit_106)
        {
            u16crc_106 ^= 0x0385U;
        }
    }
    /* Calculate crc over payloadLength field in a network order */
    for(s16fr_i_106 = 6; s16fr_i_106 >= 0; s16fr_i_106--)
    {
        u16nextBit_106 = (VAR(uint16, AUTOMATIC))((PayloadLen >> (VAR(uint8, AUTOMATIC))s16fr_i_106) & 0x0001U);
        u16crcu16nextBit_106 = (VAR(uint16, AUTOMATIC))(u16nextBit_106 ^ ((u16crc_106 >> 10U) & 0x0001U));
        u16crc_106 = (VAR(uint16, AUTOMATIC))(u16crc_106 << 1U);
        if(0U != u16crcu16nextBit_106)
        {
            u16crc_106 ^= 0x0385U;
        }
    }
    
    return  (VAR(uint16, AUTOMATIC))(u16crc_106 & 0x7FFU);
}

/***************************************************************************************************
* @function_name    Fr_Flexray_ReceiveRxLPdu
*
* @brief            FrIP function for the Fr_ReceiveRxLPdu API
* @description      Copy receive payload data
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be transmitted 
* @param[out]       lsduPtr - Address of field that data is copied to
* @param[out]       lpduStatusPtr - Address of the variable the status is stored to
* @param[out]       lsduLengthPtr - Address of the variable the payload is stored to
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the controller
*
* @implements       Fr_Flexray_ReceiveRxLPdu_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_ReceiveRxLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lpduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_12 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16tmpVal_12;  /* Temporary variable for register access */
    /* The current MB index which is configured for given Fr_LPduIdx */
    VAR(uint8, AUTOMATIC) u8tmpMBIdx_12;
    /* Temporary offset address of message buffer registers */
    VAR(uint16, AUTOMATIC) u16mbRegOffset_12;
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_12;
    /* Pointer to one instance of Fr_CCRxBufferConfigType */
    P2CONST(Fr_CCRxBufferConfigType, AUTOMATIC, FR_APPL_CONST) prxCfgPtr_12;
    VAR(uint8, AUTOMATIC) u8tmpPayloadLen_12;  /* Temporary data payload length in Words */
    #if(FR_RXSTRINGENTLENGTHCHECK == STD_ON)
    VAR(boolean, AUTOMATIC) bStatusVal = (VAR(boolean, AUTOMATIC))TRUE;
    #endif /* FR_RX_STRINGENT_LENGTH_CHECK == STD_ON */
    
    /* Store the current MB index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u8tmpMBIdx_12 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lpduIdx].MessageBufferNumber;
    /* Temporary offset address of MB configuration registers */
    u16mbRegOffset_12 = (((VAR(uint16, AUTOMATIC))u8tmpMBIdx_12) * 4U);
    /* Store the reference to Rx MB configuration */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    prxCfgPtr_12 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lpduIdx].BufferConfigPtr;
    /* Load current MB index - the original value of u8tmpMBIdx_12 is replaced by the index of mess. buffer header field */
    u8tmpMBIdx_12 = (VAR(uint8, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBIDXR0_ADDR16 + u16mbRegOffset_12));
    
    /* Check whether the read value not greather than the last utilized MB index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    if(u8tmpMBIdx_12 <= (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->RSBIR_B2BufferIndexInit)
    {
      /* Read FR_MBCCSR register value */
      u16tmpVal_12 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_12);
      /* Message buffer configured for Rx ? */
      if(FLEXRAY_MBCCSR_MTD_U16 != (u16tmpVal_12 & FLEXRAY_MBCCSR_MTD_U16))
      {
          /*  The function Fr_ReceiveRxLPdu shall ensure that the function returns
              FR_RECEIVED only once per received frame.
              - done by usage of MBIF together with DUP flag and clearing it */
        if(((VAR(uint8, AUTOMATIC))(FLEXRAY_MBCCSR_DUP_U16 | FLEXRAY_MBCCSR_MBIF_U16))
              == (u16tmpVal_12 & ((VAR(uint16, AUTOMATIC)) (FLEXRAY_MBCCSR_DUP_U16 | FLEXRAY_MBCCSR_MBIF_U16)))
          )
        {   /* Yes, Valid non-null frame received and was not read yet*/
            /* Lock Rx MB */
            /* If the application writes 1 to LCKT bit and 0 to the EDT bit, the write access 
               to all other bits is ignored */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_12, FLEXRAY_MBCCSR_LCKT_U16);
        
            /* Read the MB again to check if the MB is locked, */
            /* otherwise the MB is busy or there was an error -> report FR_E_ACCESS */
            u16tmpVal_12 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_12);
            if(FLEXRAY_MBCCSR_LCKS_U16 == (u16tmpVal_12 & FLEXRAY_MBCCSR_LCKS_U16))
            {   /* MB is locked */
                /* Calculate the message buffer header */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                /* @violates @ref FR_FLEXRAY_C_REF_1 */
                /* @violates @ref FR_FLEXRAY_C_REF_11 */
                pheaderMBPtr_12 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u8tmpMBIdx_12 * FLEXRAY_HEADER_SIZE);
                                                             
                /* Load data length from Frame header reg. [Words] */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                u8tmpPayloadLen_12 = (VAR(uint8, AUTOMATIC))(pheaderMBPtr_12[1U] & FLEXRAY_FRAMEHEADER1_PLDLENMASK_U16);
                
                /* Payload data length is also limited by Rx MB configuration */
                if(u8tmpPayloadLen_12 != prxCfgPtr_12->RxPayloadLength)
                {   /* received payload length does not match configured payload length */
                    /* Copy only limited length of data */
                #if(FR_RXSTRINGENTLENGTHCHECK == STD_OFF)
                    /* Copy only limited length of data */
                    if(u8tmpPayloadLen_12 > prxCfgPtr_12->RxPayloadLength)
                    { 
                        u8tmpPayloadLen_12 = prxCfgPtr_12->RxPayloadLength;
                    }
                #else /* FR_RX_STRINGENT_LENGTH_CHECK == STD_ON */
                    /* Data are not accepted */
                    /* Store the reception status */
                    *lpduStatusPtr = FR_NOT_RECEIVED;
                    /* Store the number of copied bytes */
                    *lsduLengthPtr = 0U;
                    bStatusVal = (VAR(boolean, AUTOMATIC))FALSE;
                #endif /* FR_RX_STRINGENT_LENGTH_CHECK */
                }/* received payload length exactly matches configured payload length */
                
                #if(FR_RXSTRINGENTLENGTHCHECK == STD_ON)
                if ((VAR(boolean, AUTOMATIC))TRUE == bStatusVal)
                {
                #endif /* FR_RX_STRINGENT_LENGTH_CHECK */
                    /* Read the FR_MBCCFRn register */
                    u16tmpVal_12 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCFR0_ADDR16 + u16mbRegOffset_12);
                
                    /* MB is assigned to channels AB */
                    if((FLEXRAY_MBCCFR_CHA_U16 | FLEXRAY_MBCCFR_CHB_U16) == (u16tmpVal_12 & (FLEXRAY_MBCCFR_CHA_U16 | FLEXRAY_MBCCFR_CHB_U16)))
                    {
                        /* Check Slot Status information */
                        /* @violates @ref FR_FLEXRAY_C_REF_4 */
                        if(0x8080U == (pheaderMBPtr_12[STATUS_SLOT] & FLEXRAY_STRINGENT_MASK_AB))
                        { 
                            /* Stringent check pass */
                            Fr_Flexray_ReadMB (ctrlIdx, lsduPtr, u8tmpPayloadLen_12, u8tmpMBIdx_12);
                            /* Store the reception status */
                            *lpduStatusPtr = FR_RECEIVED;
                            /* Store the number of copied bytes */
                            *lsduLengthPtr = (VAR(uint8, AUTOMATIC))(u8tmpPayloadLen_12 << 1U);
                            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                              Fr_Flexray_DemReport (prxCfgPtr_12, DEM_EVENT_STATUS_PASSED);
                            #endif
                        }
                        else /* Stringent check did not pass */
                        {
                            /* Store the reception status */
                            *lpduStatusPtr = FR_NOT_RECEIVED;
                            /* Store the number of copied bytes */
                            *lsduLengthPtr = 0U;
                            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                              Fr_Flexray_DemReport (prxCfgPtr_12, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                    }
                    /* MB is assigned to channel A */ 
                    else if(FLEXRAY_MBCCFR_CHA_U16 == (u16tmpVal_12 & FLEXRAY_MBCCFR_CHA_U16))
                    {
                        
                        /* Check Slot Status information */
                        /* @violates @ref FR_FLEXRAY_C_REF_4 */
                        if(0x0080U == (pheaderMBPtr_12[STATUS_SLOT] & FLEXRAY_STRINGENT_MASK_A))
                        { 
                            /* Stringent check pass */
                            Fr_Flexray_ReadMB (ctrlIdx, lsduPtr, u8tmpPayloadLen_12, u8tmpMBIdx_12);
                            /* Store the reception status */
                            *lpduStatusPtr = FR_RECEIVED;
                            /* Store the number of copied bytes */
                            *lsduLengthPtr = (VAR(uint8, AUTOMATIC))(u8tmpPayloadLen_12 << 1U);
                            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                              Fr_Flexray_DemReport (prxCfgPtr_12, DEM_EVENT_STATUS_PASSED);
                            #endif
                        }
                        else /* Stringent check did not pass */
                        {
                            /* Store the reception status */
                            *lpduStatusPtr = FR_NOT_RECEIVED;
                            /* Store the number of copied bytes */
                            *lsduLengthPtr = 0U;        
                            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                              Fr_Flexray_DemReport (prxCfgPtr_12, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }  
                    }
                    else /* MB is assigned to channel B */ 
                    {
                        /* Check Slot Status information */
                        /* @violates @ref FR_FLEXRAY_C_REF_4 */
                        if(0x8000U == (pheaderMBPtr_12[STATUS_SLOT] & FLEXRAY_STRINGENT_MASK_B))
                        { 
                            /* Stringent check passed */
                            Fr_Flexray_ReadMB (ctrlIdx, lsduPtr, u8tmpPayloadLen_12, u8tmpMBIdx_12);
                            /* Store the reception status */
                            *lpduStatusPtr = FR_RECEIVED;
                            /* Store the number of copied bytes */
                            *lsduLengthPtr = (VAR(uint8, AUTOMATIC))(u8tmpPayloadLen_12 << 1U);
                            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                              Fr_Flexray_DemReport (prxCfgPtr_12, DEM_EVENT_STATUS_PASSED);
                            #endif
                        }
                        else /* Stringent check did not pass */
                        {
                            /* Store the reception status */
                            *lpduStatusPtr = FR_NOT_RECEIVED;
                            /* Store the number of copied bytes */
                            *lsduLengthPtr = 0U;
                            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                              Fr_Flexray_DemReport (prxCfgPtr_12, DEM_EVENT_STATUS_FAILED);
                            #endif
                        }
                    }
                #if(FR_RXSTRINGENTLENGTHCHECK == STD_ON)
                }
                #endif /* FR_RX_STRINGENT_LENGTH_CHECK */
                /*  The function Fr_ReceiveRxLPdu shall ensure that the function returns
                    FR_RECEIVED only once per received frame.
                    - done by usage of MBIF together with DUP flag and clearing it */
                    
                /* Clear Message Buffer Interrupt Flag */
                /* Fr_CtrlIdx: FR_MBCCSR : MBIF */
                /* Load FR_MBCCSRn register and select only necessary bits */
                SchM_Enter_Fr_FR_EXCLUSIVE_AREA_06();
                u16tmpVal_12 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_12) & FLEXRAY_MBCCSR0_CONFIG_MASK_U16);
                u16tmpVal_12 |= FLEXRAY_MBCCSR_MBIF_U16;    /*Clear flag*/
                Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_12, u16tmpVal_12);
                SchM_Exit_Fr_FR_EXCLUSIVE_AREA_06();
        
                /* Attempt to unlock MB */
                /* If the application writes 1 to LCKT bit and 0 to the EDT bit,
                   the write access to all other bits is ignored */
                /* Unlock MB */
                Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_12, FLEXRAY_MBCCSR_LCKT_U16);
                
                retVal_12 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); /* API call was successful*/
            }
        }
        else    /* MBIF == 0 of DUP == 0 (data already read or no valid frame received) */
        {
            /* Store the length "0" into lsduLengthPtr */
            *lsduLengthPtr = 0U;
            /* [SWS_Fr_00236]: Store the reception status */
            *lpduStatusPtr = FR_NOT_RECEIVED;
            retVal_12 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            /* Clear Message Buffer Interrupt Flag */
            /* Fr_CtrlIdx: FR_MBCCSR : MBIF */
            /* Load FR_MBCCSRn register and select only necessary bits */
            SchM_Enter_Fr_FR_EXCLUSIVE_AREA_06();
            u16tmpVal_12 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_12) & FLEXRAY_MBCCSR0_CONFIG_MASK_U16);
            u16tmpVal_12 |= FLEXRAY_MBCCSR_MBIF_U16;    /* Clear flag */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_12, u16tmpVal_12);
            SchM_Exit_Fr_FR_EXCLUSIVE_AREA_06();
        }
      }
    }
    
    return retVal_12;
}

/***************************************************************************************************
* @function_name    Fr_Flexray_ReceiveFifoA
*
* @brief            FrIP function for the Fr_ReceiveRxLPdu API
* @description      Copy FifoA data
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be transmitted 
* @param[out]       lsduPtr - Address of field that data is copied to
* @param[out]       lpduStatusPtr - Address of the variable the status is stored to
* @param[out]       lsduLengthPtr - Address of the variable the payload is stored to
* @return           none
*
* @implements       Fr_Flexray_ReceiveFifoA_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_ReceiveFifoA
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lpduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
)
{
    VAR(uint16, AUTOMATIC) u16tmpVal_FifoA;  /* Temporary variable for register access */
    VAR(uint8, AUTOMATIC) u8fr_p_FifoA;  /* Temporary counter used for copying */
    VAR(uint8, AUTOMATIC) u8fr_o_FifoA;  /* Temporary counter used for copying */
    /* The current MB index which is configured for given Fr_LPduIdx */
    VAR(uint8, AUTOMATIC) u8tmpMBIdx_FifoA;
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_FifoA;
    /* Pointer to data field in FR memory space in 16-bit format */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pdataPtr16_FifoA;
    /* Pointer to data field in FR memory space in 32-bit format */
    P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA) pdataPtr32_FifoA;
    VAR(uint8, AUTOMATIC) u8tmpPayloadLen_FifoA;  /* Temporary data payload length in Words */
    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    VAR(uint32, AUTOMATIC) u32tmpdata;  /* Temporary variable for data */
    VAR(uint16, AUTOMATIC) u16tmpdata;  /* Temporary variable for data */
    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)*/
    
    /* Check whether the FIFO A is empty or not */
    if(FLEXRAY_GIFER_FNEAIF_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16) & FLEXRAY_GIFER_FNEAIF_U16))
    {   /* FIFO A is not empty */
        /* Load Read index - MB header index of the next available
           FIFO A buffer that can be read */
        u8tmpMBIdx_FifoA = (VAR(uint8, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_RFARIR_ADDR16));
 
        /* Calculate the message buffer header */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_1 */
        /* @violates @ref FR_FLEXRAY_C_REF_11 */
        pheaderMBPtr_FifoA = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u8tmpMBIdx_FifoA * FLEXRAY_HEADER_SIZE);

        /* [SWS_Fr_00239]: Load data length from Frame header reg. [Words] */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u8tmpPayloadLen_FifoA = (VAR(uint8, AUTOMATIC))(pheaderMBPtr_FifoA[1U] & FLEXRAY_FRAMEHEADER1_PLDLENMASK_U16);
        /* Load configured payload length into u16tmpVal_FifoA */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16tmpVal_FifoA = (((P2CONST(Fr_CCFifoConfigType, AUTOMATIC, FR_APPL_CONST))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lpduIdx].BufferConfigPtr))->FIFOEntrySize);
        /* Payload data length is also limited by Rx MB configuration */
        if(u8tmpPayloadLen_FifoA != u16tmpVal_FifoA)
        {   /* received payload length does not match configured payload length */
             
            #if(FR_RXSTRINGENTLENGTHCHECK == STD_OFF) 
            /* Copy only limited length of data */
            if(u8tmpPayloadLen_FifoA > u16tmpVal_FifoA)
            {
                u8tmpPayloadLen_FifoA = (VAR(uint8, AUTOMATIC))u16tmpVal_FifoA;
            }
            /* Stringent check */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            if(0x0080U == (pheaderMBPtr_FifoA[STATUS_SLOT] & FLEXRAY_STRINGENT_MASK_A))
            {
                /* Load MB Data pointer */
                /* Driver execution time optimization - data offset is not loaded from structure of type Fr_CCLpduInfoType,
                   but from structure of type Fr_CCBufferOffsetType */
                /* Load MB Data pointer for 32-bit access */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                /* @violates @ref FR_FLEXRAY_C_REF_1 */
                /* @violates @ref FR_FLEXRAY_C_REF_11 */
                pdataPtr32_FifoA = Fr_Flexray_GetData32Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_FifoA].MbDataAddrPtr);
 
                /* Data copying process - optimized for the speed */
                /* 32-bit copying process */
                /* Example: PayloadLength = 10 Bytes [0..7] */
                /* For data[B]<=4n, where n=PayloadLength/4 */
                for(u8fr_p_FifoA = 0U; u8fr_p_FifoA < (u8tmpPayloadLen_FifoA >> 1U); u8fr_p_FifoA++)
                {
                    /* Fr_CtrlIdx: Memory: Data Field */
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u32tmpdata = pdataPtr32_FifoA[u8fr_p_FifoA];
                    u32tmpdata = (uint32)(((u32tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32) | ((u32tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoA] = u32tmpdata;
                    #else
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoA] = pdataPtr32_FifoA[u8fr_p_FifoA];
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                }
                /* Example: first 8 Bytes are copied [0..7], u8fr_p_FifoA = 1+1 */
                /* Convert 32-bit counter of last copied byte to 16-bit counter */
                u8fr_o_FifoA = (VAR(uint8, AUTOMATIC))((u8fr_p_FifoA * 2U) & 0xFFU);
                /* 16-bit copying process */
                /* Copy the following two bytes only if((PayloadLength % 4) > 1) */
                for(u8fr_p_FifoA = u8fr_o_FifoA; u8fr_p_FifoA < u8tmpPayloadLen_FifoA; u8fr_p_FifoA++)
                {
                    /* Load MB Data pointer for 16-bit access */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    pdataPtr16_FifoA = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_FifoA].MbDataAddrPtr);
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u16tmpdata = pdataPtr16_FifoA[u8fr_p_FifoA];
                    u16tmpdata = (uint16)(((uint16)(u16tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16) | ((uint16)(u16tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoA] = u16tmpdata;
                    #else
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoA] = pdataPtr16_FifoA[u8fr_p_FifoA];
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                }   /* Example: next 2 Bytes are copied [8..9], u8fr_p_FifoA = 4+1 */
                /* Store the number of copied bytes */
                *lsduLengthPtr = (VAR(uint8, AUTOMATIC))(u8tmpPayloadLen_FifoA << 1U);
                /* [SWS_Fr_00236]: Store the reception status */
                *lpduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE;
            }
            else /* Stringent check did not pass */
            {
                /* Store the number of copied bytes */
                *lsduLengthPtr = 0U;
                /* Store the reception status */
                *lpduStatusPtr = FR_NOT_RECEIVED;
            }
            
            #else /* FR_RX_STRINGENT_LENGTH_CHECK == STD_ON */
            /* Store the number of copied bytes */
            *lsduLengthPtr = 0U;                    
            /* Store the reception status */
            *lpduStatusPtr = FR_NOT_RECEIVED;
            #endif /* FR_RX_STRINGENT_LENGTH_CHECK */                 
        } /* received payload length does not match configured payload length */
        else /* received payload length exactly matches configured payload length */
        {      
            /* Stringent check */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            if(0x0080U == (pheaderMBPtr_FifoA[STATUS_SLOT] & FLEXRAY_STRINGENT_MASK_A))
            { /* Stringent check passed */
                /* Load MB Data pointer */
                /* Driver execution time optimization - data offset is not loaded from structure of type Fr_CCLpduInfoType,
                   but from structure of type Fr_CCBufferOffsetType */
                /* Load MB Data pointer for 32-bit access */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                /* @violates @ref FR_FLEXRAY_C_REF_1 */
                /* @violates @ref FR_FLEXRAY_C_REF_11 */
                pdataPtr32_FifoA = Fr_Flexray_GetData32Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_FifoA].MbDataAddrPtr);
 
                /* Data copying process - optimized for the speed */
                /* 32-bit copying process */
                /* Example: PayloadLength = 10 Bytes [0..7] */
                /* For data[B]<=4n, where n=PayloadLength/4 */
                for(u8fr_p_FifoA = 0U; u8fr_p_FifoA < (u8tmpPayloadLen_FifoA >> 1U); u8fr_p_FifoA++)
                {
                    /* Fr_CtrlIdx: Memory: Data Field */
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u32tmpdata = pdataPtr32_FifoA[u8fr_p_FifoA];
                    u32tmpdata = (uint32)(((u32tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32) | ((u32tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoA] = u32tmpdata;
                    #else
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoA] = pdataPtr32_FifoA[u8fr_p_FifoA];
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                }
                /* Example: first 8 Bytes are copied [0..7], u8fr_p_FifoA = 1+1 */
                /* Convert 32-bit counter of last copied byte to 16-bit counter */
                u8fr_o_FifoA = (VAR(uint8, AUTOMATIC))((u8fr_p_FifoA * 2U) & 0xFFU);
                /* 16-bit copying process */
                /* Copy the following two bytes only if((PayloadLength % 4) > 1) */
                for(u8fr_p_FifoA = u8fr_o_FifoA; u8fr_p_FifoA < u8tmpPayloadLen_FifoA; u8fr_p_FifoA++)
                {
                    /* Load MB Data pointer for 16-bit access */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    pdataPtr16_FifoA = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_FifoA].MbDataAddrPtr);
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u16tmpdata = pdataPtr16_FifoA[u8fr_p_FifoA];
                    u16tmpdata = (uint16)(((uint16)(u16tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16) | ((uint16)(u16tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoA] = u16tmpdata;
                    #else
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoA] = pdataPtr16_FifoA[u8fr_p_FifoA];
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                }   /* Example: next 2 Bytes are copied [8..9], u8fr_p_FifoA = 4+1 */
                /* Store the number of copied bytes */
                *lsduLengthPtr = (VAR(uint8, AUTOMATIC))(u8tmpPayloadLen_FifoA << 1U);
                /* [SWS_Fr_00236]: Store the reception status */
                *lpduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE;
            }
            else /* stringent check did not pass */
            {
                /* Store the number of copied bytes */
                *lsduLengthPtr = 0U;
                /* Store the reception status */
                *lpduStatusPtr = FR_NOT_RECEIVED;
            }
        } 
        /* Clear FIFO A not empty flag */
        /* Fr_CtrlIdx: GIFER: FNEAIF */
        /* Load GIFER register and select only necessary bits */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_13();
        u16tmpVal_FifoA = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16) & (VAR(uint16, AUTOMATIC))(~FLEXRAY_GIFER_INT_FLAGS_MASK_U16));
        u16tmpVal_FifoA |= FLEXRAY_GIFER_FNEAIF_U16;
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16, u16tmpVal_FifoA);  /* Clear the flag */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_13();
    }
    else
    {   /* FIFO A is empty */
        /* Store the length "0" into lsduLengthPtr */
        *lsduLengthPtr = 0U;
        /* [SWS_Fr_00236]: Store the reception status */
        *lpduStatusPtr = FR_NOT_RECEIVED;
    }
}

/***************************************************************************************************
* @function_name    Fr_Flexray_ReceiveFifoB
*
* @brief            FrIP function for the Fr_ReceiveRxLPdu API
* @description      Copy FifoB data
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be transmitted 
* @param[out]       lsduPtr - Address of field that data is copied to
* @param[out]       lpduStatusPtr - Address of the variable the status is stored to
* @param[out]       lsduLengthPtr - Address of the variable the payload is stored to
* @return           none
*
* @implements       Fr_Flexray_ReceiveFifoB_Activity
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Flexray_ReceiveFifoB
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lpduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
)
{
    VAR(uint16, AUTOMATIC) u16tmpVal_FifoB;  /* Temporary variable for register access */
    VAR(uint8, AUTOMATIC) u8fr_p_FifoB;  /* Temporary counter used for copying */
    VAR(uint8, AUTOMATIC) u8fr_o_FifoB;  /* Temporary counter used for copying */
    /* The current MB index which is configured for given Fr_LPduIdx */
    VAR(uint8, AUTOMATIC) u8tmpMBIdx_FifoB;
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_FifoB;
    /* Pointer to data field in FR memory space in 16-bit format */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pdataPtr16_FifoB;
    /* Pointer to data field in FR memory space in 32-bit format */
    P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA) pdataPtr32_FifoB;
    /* Pointer to one instance of Fr_CCRxBufferConfigType */
    VAR(uint8, AUTOMATIC) u8tmpPayloadLen_FifoB;  /* Temporary data payload length in Words */
    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
    VAR(uint32, AUTOMATIC) u32tmpdata;  /* Temporary variable for data */
    VAR(uint16, AUTOMATIC) u16tmpdata;  /* Temporary variable for data */
    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)*/
        
    /* Check whether the FIFO B is empty or not */
    if(FLEXRAY_GIFER_FNEBIF_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16) & FLEXRAY_GIFER_FNEBIF_U16))
    {   /* FIFO B is not empty */
        /* Load Read index - MB header index of the next available
           FIFO B buffer that can be read */
        u8tmpMBIdx_FifoB = (VAR(uint8, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_RFBRIR_ADDR16));

        /* Calculate the message buffer header */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_1 */
        /* @violates @ref FR_FLEXRAY_C_REF_11 */
        pheaderMBPtr_FifoB = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u8tmpMBIdx_FifoB * FLEXRAY_HEADER_SIZE);
        /* [FR239]: Load data length from Frame header reg. [Words] */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u8tmpPayloadLen_FifoB = (VAR(uint8, AUTOMATIC))(pheaderMBPtr_FifoB[1U] & FLEXRAY_FRAMEHEADER1_PLDLENMASK_U16);
        /* Payload data length is also limited by Rx MB configuration */
        /* Load configured payload length into u16tmpVal_FifoB */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16tmpVal_FifoB = (((P2CONST(Fr_CCFifoConfigType, AUTOMATIC, FR_APPL_CONST))((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lpduIdx].BufferConfigPtr))->FIFOEntrySize);
        /* Payload data length is also limited by Rx MB configuration */
        if(u8tmpPayloadLen_FifoB != u16tmpVal_FifoB)
        {   /* received payload length does not match configured payload length */
            
            #if(FR_RXSTRINGENTLENGTHCHECK == STD_OFF) 
            /* Copy only limited length of data */
            if(u8tmpPayloadLen_FifoB > u16tmpVal_FifoB)
            {
                u8tmpPayloadLen_FifoB = (VAR(uint8, AUTOMATIC))u16tmpVal_FifoB;
            }
            /* Stringent check */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            if(0x8000U == (pheaderMBPtr_FifoB[STATUS_SLOT] & FLEXRAY_STRINGENT_MASK_B))
            { /* stringent check passed */
                /* Load MB Data pointer */
                /* Driver execution time optimization - data offset is not loaded from structure of type Fr_CCLpduInfoType,
                   but from structure of type Fr_CCBufferOffsetType */
                /* Load MB Data pointer for 32-bit access */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                /* @violates @ref FR_FLEXRAY_C_REF_1 */
                /* @violates @ref FR_FLEXRAY_C_REF_11 */
                pdataPtr32_FifoB = Fr_Flexray_GetData32Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_FifoB].MbDataAddrPtr);
 
                /* Data copying process - optimized for the speed */
                /* 32-bit copying process */
                /* Example: PayloadLength = 10 Bytes [0..7] */
                /* For data[B]<=4n,where n=PayloadLength/4 */
                for(u8fr_p_FifoB = 0U; u8fr_p_FifoB < (u8tmpPayloadLen_FifoB >> 1U); u8fr_p_FifoB++)
                {
                    /* Fr_CtrlIdx: Memory: Data Field */
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u32tmpdata = pdataPtr32_FifoB[u8fr_p_FifoB];
                    u32tmpdata = (uint32)(((u32tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32) | ((u32tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoB] = u32tmpdata;
                    #else
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoB] = pdataPtr32_FifoB[u8fr_p_FifoB];
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                }
                /* Example: first 8 Bytes are copied [0..7], u8fr_p_FifoB = 1+1 */
 
                /* Convert 32-bit counter of last copied byte to 16-bit counter */
                u8fr_o_FifoB = (VAR(uint8, AUTOMATIC))((u8fr_p_FifoB * 2U) & 0xFFU);
 
                /* 16-bit copying process */
                /* Copy the following two bytes only if((PayloadLength % 4) > 1) */
                for(u8fr_p_FifoB = u8fr_o_FifoB; u8fr_p_FifoB < u8tmpPayloadLen_FifoB; u8fr_p_FifoB++)
                {
                    /* Load MB Data pointer for 16-bit access */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    pdataPtr16_FifoB = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_FifoB].MbDataAddrPtr);
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u16tmpdata = pdataPtr16_FifoB[u8fr_p_FifoB];
                    u16tmpdata = (uint16)(((uint16)(u16tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16) | ((uint16)(u16tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoB] = u16tmpdata;
                    #else
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoB] = pdataPtr16_FifoB[u8fr_p_FifoB];
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                }   /* Example: next 2 Bytes are copied [8..9], u8fr_p_FifoB = 4+1 */
 
                /* Store the number of copied bytes */  
                *lsduLengthPtr = (VAR(uint8, AUTOMATIC))(u8tmpPayloadLen_FifoB << 1U);
                /* [SWS_Fr_00236]: Store the reception status */
                *lpduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE;   
            }
            else /* stringent check did not pass */
            {
                /* Store the number of copied bytes */
                *lsduLengthPtr = 0U;
                /* Store the reception status */  
                *lpduStatusPtr = FR_NOT_RECEIVED;
            }                     
            #else /* FR_RX_STRINGENT_LENGTH_CHECK == STD_ON */
            /* Store the number of copied bytes */
            *lsduLengthPtr = 0U;
            /* Store the reception status */  
            *lpduStatusPtr = FR_NOT_RECEIVED;
            #endif /* FR_RX_STRINGENT_LENGTH_CHECK */  
        }
        else /* received payload length exactly matches configured payload length */
        {
            /* Stringent check */
            /* @violates @ref FR_FLEXRAY_C_REF_4 */
            if(0x8000U == (pheaderMBPtr_FifoB[STATUS_SLOT] & FLEXRAY_STRINGENT_MASK_B))
            { /* stringent check passed */
            
                /* Load MB Data pointer */
                /* Driver execution time optimization - data offset is not loaded from structure of type Fr_CCLpduInfoType,
                   but from structure of type Fr_CCBufferOffsetType */
                /* Load MB Data pointer for 32-bit access */
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                /* @violates @ref FR_FLEXRAY_C_REF_1 */
                /* @violates @ref FR_FLEXRAY_C_REF_11 */
                pdataPtr32_FifoB = Fr_Flexray_GetData32Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_FifoB].MbDataAddrPtr);
 
                /* Data copying process - optimized for the speed */
                /* 32-bit copying process */
                /* Example: PayloadLength = 10 Bytes [0..7] */
                /* For data[B]<=4n,where n=PayloadLength/4 */
                for(u8fr_p_FifoB = 0U; u8fr_p_FifoB < (u8tmpPayloadLen_FifoB >> 1U); u8fr_p_FifoB++)
                {
                    /* Fr_CtrlIdx: Memory: Data Field */
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u32tmpdata = pdataPtr32_FifoB[u8fr_p_FifoB];
                    u32tmpdata = (uint32)(((u32tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32) | ((u32tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoB] = u32tmpdata;
                    #else
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint32, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoB] = pdataPtr32_FifoB[u8fr_p_FifoB];
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                }
                /* Example: first 8 Bytes are copied [0..7], u8fr_p_FifoB = 1+1 */
 
                /* Convert 32-bit counter of last copied byte to 16-bit counter */
                u8fr_o_FifoB =  (VAR(uint8, AUTOMATIC))((u8fr_p_FifoB * 2U) & 0xFFU);
 
                /* 16-bit copying process */
                /* Copy the following two bytes only if((PayloadLength % 4) > 1) */
                for(u8fr_p_FifoB = u8fr_o_FifoB; u8fr_p_FifoB < u8tmpPayloadLen_FifoB; u8fr_p_FifoB++)
                {
                    /* Load MB Data pointer for 16-bit access */
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_1 */
                    /* @violates @ref FR_FLEXRAY_C_REF_11 */
                    pdataPtr16_FifoB = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->BufferAddressTable[u8tmpMBIdx_FifoB].MbDataAddrPtr);
                    /* If for each 2-byte block of message buffer data field, payload data byte which has higher index is located in lower address, reverse the payload data byte order */
                    #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST)
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u16tmpdata = pdataPtr16_FifoB[u8fr_p_FifoB];
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    u16tmpdata = (uint16)(((uint16)(u16tmpdata << FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16) | ((uint16)(u16tmpdata >> FLEXRAY_PAYLOAD_BYTE_OFFSET_U32) & FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16));
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoB] = u16tmpdata;
                    #else
                    /* @violates @ref FR_FLEXRAY_C_REF_4 */
                    /* @violates @ref FR_FLEXRAY_C_REF_2 */
                    ((P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA))lsduPtr)[u8fr_p_FifoB] = pdataPtr16_FifoB[u8fr_p_FifoB];
                    #endif /* #if(CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
                }   /* Example: next 2 Bytes are copied [8..9], u8fr_p_FifoB = 4+1 */
 
                /* Store the number of copied bytes */  
                *lsduLengthPtr = (VAR(uint8, AUTOMATIC))(u8tmpPayloadLen_FifoB << 1U);
                /* [SWS_Fr_00236]: Store the reception status */
                *lpduStatusPtr = FR_RECEIVED_MORE_DATA_AVAILABLE;
            }
            else /* stringent check did not pass */
            {
                /* Store the number of copied bytes */  
                *lsduLengthPtr = 0U;
                /* Store the reception status */
                *lpduStatusPtr = FR_NOT_RECEIVED;
            }     
        }
        /* Clear FIFO B not empty flag */
        /* Fr_CtrlIdx: GIFER: FNEBIF */
        /* Load GIFER register and select only necessary bits */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_12();
        u16tmpVal_FifoB = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16) & (VAR(uint16, AUTOMATIC))(~FLEXRAY_GIFER_INT_FLAGS_MASK_U16));
        u16tmpVal_FifoB |= FLEXRAY_GIFER_FNEBIF_U16;
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16, u16tmpVal_FifoB);  /* Clear the flag */
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_12();
    }
    else
    {   /* FIFO B is empty */
        /* Store the length "0" into lsduLengthPtr */
        *lsduLengthPtr = 0U;
        /* [SWS_Fr_00236]: Store the reception status */
        *lpduStatusPtr = FR_NOT_RECEIVED;
    }
}

/***************************************************************************************************
* @function_name    Fr_Flexray_CheckTxLPduStatus
*
* @brief            FrIP function for the Fr_CheckTxLPduStatus API
* @description      Check whether LPdu was transmitted or not
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be canceled
* @param[out]       txLPduStatusPtr - Address of the variable where the status information is 
*                                     stored to
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
*
* @implements       Fr_Flexray_CheckTxLPduStatus_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_CheckTxLPduStatus
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx,
    P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) txLPduStatusPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_13 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    /* The current MB index which is configured for given Fr_LPduIdx */
    VAR(uint8, AUTOMATIC) u8mbIdx_13;
    VAR(uint16, AUTOMATIC) u16mbRegOffset_13;  /* Temporary offset address of MB registers */
    VAR(uint16, AUTOMATIC) u16tmpRegVal_13;
    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to one instance of Fr_CCTxBufferConfigType */
    P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST) ptxCfgPtr_13;
    /* Pointer to buffer header in the FlexRay memory space */
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_13;
    /* Variable to hold DEM ID information*/
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_LPDU_SLOTSTATUS;
    #endif
    
    /* Store the configured MB index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u8mbIdx_13 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].MessageBufferNumber;
    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to one instance of Fr_CCReceiveBufferConfigType */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    ptxCfgPtr_13 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].BufferConfigPtr;
    /* Calculate the message buffer header */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    /* @violates @ref FR_FLEXRAY_C_REF_1 */
    /* @violates @ref FR_FLEXRAY_C_REF_11 */
    pheaderMBPtr_13 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u8mbIdx_13 * FLEXRAY_HEADER_SIZE);
    #endif

    /* Temporary offset address of MB configuration registers */
    u16mbRegOffset_13 = (((VAR(uint16, AUTOMATIC))u8mbIdx_13) * 4U);
    /* Read FR_MBCCSR register value */
    u16tmpRegVal_13 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_13);
     /* Message buffer configured for Tx ? */
    if(FLEXRAY_MBCCSR_MTD_U16 == (u16tmpRegVal_13 & FLEXRAY_MBCCSR_MTD_U16))
    {
        /* Is the CMT bit set? */
        if(FLEXRAY_MBCCSR_CMT_U16 != (u16tmpRegVal_13 & FLEXRAY_MBCCSR_CMT_U16))
        {/* No transmission request is pending */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if(ptxCfgPtr_13->DemFTSlotSTatusRefExist)
            {
                /* @violates @ref FR_FLEXRAY_C_REF_4 */
                if(0U == (pheaderMBPtr_13[3] & 0x0101U))
                {
                    FR_E_LPDU_SLOTSTATUS = ptxCfgPtr_13->DemFTSlotStatus;
                    Dem_ReportErrorStatus(FR_E_LPDU_SLOTSTATUS, DEM_EVENT_STATUS_PASSED);
                }
                else
                {
                    FR_E_LPDU_SLOTSTATUS = ptxCfgPtr_13->DemFTSlotStatus;
                    Dem_ReportErrorStatus(FR_E_LPDU_SLOTSTATUS, DEM_EVENT_STATUS_FAILED);
                }
            }
            #endif /* FR_DISABLE_DEM_REPORT_ERROR_STATUS */
            *txLPduStatusPtr = FR_TRANSMITTED;
        }
        else
        {/* Transmission request is still pending */
            *txLPduStatusPtr = FR_NOT_TRANSMITTED;
        }
        retVal_13 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);    /* API call was successful */
    }
    else
    {
        /* HW error MB is not configured for Tx -> return E_NOT_OK */
    }
    return retVal_13;
}

#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Flexray_PrepareLPdu
*
* @brief            FrIP function for the Fr_PrepareLPdu API
* @description      Check LPdu status
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be prepared
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
*
* @implements        Fr_Flexray_PrepareLPdu_Activity
***************************************************************************************************/ 
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_PrepareLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_31 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint8, AUTOMATIC) u8tmpMBNum_31;  /* Temporary variable for the MB index */
    
    /* Store the initial MB index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u8tmpMBNum_31 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].MessageBufferNumber;
    /* [FR249]: Determine the type of buffer */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    switch((Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].BufferType)
    {
    /* Transmit MB configuration */
    case FR_TRANSMIT_BUFFER:
        retVal_31 = Fr_Flexray_PrepareTxBuffer(ctrlIdx, lPduIdx, u8tmpMBNum_31);
        break;

    /* Receive MB configuration */
    case FR_RECEIVE_BUFFER:
        retVal_31 = Fr_Flexray_PrepareRxBuffer(ctrlIdx, lPduIdx, u8tmpMBNum_31);
        break;
        
    case FR_FIFOA_BUFFER: /* Intentional fall-through */
    
    case FR_FIFOB_BUFFER: /* Intentional fall-through */
    
    default:
        break;
    }
    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == retVal_31) /* Continue only on success */
    {
        /* [SWS_Fr_00440],[SWS_Fr_00441]: Only if FR_PREPARE_LPDU_SUPPORT is enabled: */
        /* Store information which LPdu is currently configured for given physical
           resource (individual MB) */
        Fr_VirtualResourceAllocation[ctrlIdx][u8tmpMBNum_31] = lPduIdx;
    }   /* E_OK == retVal_31 */
    
    return retVal_31;
}  
#endif /* FR_PREPARE_LPDU_SUPPORT == STD_ON */

/***************************************************************************************************
* @function_name    Fr_Flexray_CancelTxLPdu
*
* @brief            FrIP function for the Fr_CancelTxLPdu API
* @description      Cancel required LPdu and provide information about it
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lPduIdx - Index of LPdu to be canceled
* @param[out]       pendingStatusPtr - Information whether the LPdu was canceled or not
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
*
* @implements       Fr_Flexray_CancelTxLPdu_Activity                   
***************************************************************************************************/ 
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_CancelTxLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) pendingStatusPtr
) 
{
     /* Set initial return value */
     VAR(Std_ReturnType, AUTOMATIC) retVal_45 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
     VAR(uint8, AUTOMATIC) u8tmpMBIdx_45;
     VAR(uint16, AUTOMATIC) u16mbRegOffset_45;
     VAR(uint16, AUTOMATIC) u16tmpRegVal_45;
     
    /* Store the current MB index */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u8tmpMBIdx_45 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].MessageBufferNumber;

    /* Temporary offset address of MB configuration registers */
    u16mbRegOffset_45 = (((VAR(uint16, AUTOMATIC))u8tmpMBIdx_45) * 4U);
    
    /* Read FR_MBCCSR register value */
    SchM_Enter_Fr_FR_EXCLUSIVE_AREA_09();
    u16tmpRegVal_45 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_45);
    /* Message buffer configured for Tx ? */
    if(FLEXRAY_MBCCSR_MTD_U16 == (u16tmpRegVal_45 & FLEXRAY_MBCCSR_MTD_U16))
    {
        /* Message buffer data ready for transmission ? */
        if(FLEXRAY_MBCCSR_CMT_U16 == (u16tmpRegVal_45 & FLEXRAY_MBCCSR_CMT_U16))
        {   /* Yes - Data are ready for transmission */
            *pendingStatusPtr = (VAR(boolean, AUTOMATIC))(TRUE);
            /* Lock MB -> write 1 to LCKT bit and 0 to the EDT bit in FR_MBCCSR register for current MB
              (write access to all other bits is ignored) */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_45, FLEXRAY_MBCCSR_LCKT_U16); 
            /* Select only necessary bits from MBCCSRx register */
            u16tmpRegVal_45 &= FLEXRAY_MBCCSR0_CONFIG_MASK_U16;
            /* Clear CMT bit */
            u16tmpRegVal_45 &= ~FLEXRAY_MBCCSR_CMT_U16;
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_45, u16tmpRegVal_45);
            /* Unlock MB -> write 1 to LCKT bit and 0 to the EDT bit in FR_MBCCSR register for current MB
              (write access to all other bits is ignored) */
            Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_45, FLEXRAY_MBCCSR_LCKT_U16);
            
            /* Is the MB Unlocked and CMT cleared? */
            u16tmpRegVal_45 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_45);
            if((FLEXRAY_MBCCSR_LCKS_U16 != (u16tmpRegVal_45 & FLEXRAY_MBCCSR_LCKS_U16)) && (FLEXRAY_MBCCSR_CMT_U16 != (u16tmpRegVal_45 & FLEXRAY_MBCCSR_CMT_U16)))
            { /* Yes */ 
                retVal_45 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            else
            {
               /* This is HW error return E_NOT_OK and pendingStatusPtr TRUE */
            }
        }
        else 
        {
             /* Data is not ready for transmission return E_OK pendingStatusPtr FALSE */
             retVal_45 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
        }
    }
    else
    {
        /* HW error MB is not configured for Tx -> return E_NOT_OK */
    }
    SchM_Exit_Fr_FR_EXCLUSIVE_AREA_09();
    
    return retVal_45;
}
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON) 
/***************************************************************************************************
* @function_name    Fr_Flexray_ReconfigLPdu
*
* @brief            FrIP function for the Fr_ReconfigLPdu API
* @description      Reconfigures required LPdu
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be reconfigured
* @param[in]        frameId - Frame ID for reconfiguration
* @param[in]        cycleRepetition - Repetition value for cycle filter mechanism
* @param[in]        cycleOffste - Offste value for cycle filter mechanism
* @param[in]        payloadLength - payload for data to be reconfigured
* @param[in]        headerCRC - hedaer CRC value  
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
*
* @implements       Fr_Flexray_ReconfigLPdu_Activity
***************************************************************************************************/ 
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_ReconfigLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx,
    VAR(uint16, AUTOMATIC) frameId,
    VAR(Fr_ChannelType, AUTOMATIC) chnlIdx,
    VAR(uint8, AUTOMATIC) cycleRepetition,
    VAR(uint8, AUTOMATIC) cycleOffset,
    VAR(uint8, AUTOMATIC) payloadLength,
    VAR(uint16, AUTOMATIC) headerCRC
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_37 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint8, AUTOMATIC) u8tmpMBIdx_37;
    VAR(uint16, AUTOMATIC) u16mbRegOffset_37;
    VAR(uint16, AUTOMATIC) u16tmpRegVal_37;
    P2VAR(volatile uint16, AUTOMATIC, FR_APPL_DATA) pheaderMBPtr_37;
    
    /* Get current MB Idx */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u8tmpMBIdx_37 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].MessageBufferNumber;
    /* Offset from FR base address to the MB registers */
    u16mbRegOffset_37 = (((VAR(uint16, AUTOMATIC))u8tmpMBIdx_37) * 4U);
        
    if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_37) & FLEXRAY_MBCCSR_EDS_U16))
    {
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_37, FLEXRAY_MBCCSR_EDT_U16);
    }
    /* Check if buffer has been successfully disabled */
    if(FLEXRAY_MBCCSR_EDS_U16 != (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_37) & FLEXRAY_MBCCSR_EDS_U16))
    { /* Yes */ 
        /* Read FR_MBCCFRx register */
        SchM_Enter_Fr_FR_EXCLUSIVE_AREA_08();
        u16tmpRegVal_37 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCFR0_ADDR16 + u16mbRegOffset_37);
        
        u16tmpRegVal_37 &= 0x8000U;    /* Clear all configured bits */  

        if(FR_CHANNEL_AB == chnlIdx)
        {
            /* For static segment configure both channels */
            u16tmpRegVal_37 |= (FLEXRAY_MBCCFR_CHA_U16 | FLEXRAY_MBCCFR_CHB_U16);
        }
        else if(FR_CHANNEL_A == chnlIdx)
        {
            u16tmpRegVal_37 |= FLEXRAY_MBCCFR_CHA_U16;
            /* Clear CHB bit */
            u16tmpRegVal_37 &= ~FLEXRAY_MBCCFR_CHB_U16;
        }
        else
        {
            u16tmpRegVal_37 |= FLEXRAY_MBCCFR_CHB_U16;
            /* Clear CHA bit */
            u16tmpRegVal_37 &= ~FLEXRAY_MBCCFR_CHA_U16;
        }
        
        u16tmpRegVal_37 |= (VAR(uint16, AUTOMATIC))
                                     ((((VAR(uint16,AUTOMATIC))cycleRepetition & 0x3FU) - 1U) << 6U);
        
        u16tmpRegVal_37 |= (VAR(uint16, AUTOMATIC))(cycleOffset) & 0x003FU; 
        
        u16tmpRegVal_37 |= FLEXRAY_MBCCFR_CCFE_U16; /* Enable Cycle counter filtering */

        /* Reconfigure MBCCFRx register */
        Fr_Flexray_WriteRegister(ctrlIdx, (FLEXRAY_MBCCFR0_ADDR16 + u16mbRegOffset_37), u16tmpRegVal_37);
        SchM_Exit_Fr_FR_EXCLUSIVE_AREA_08();
        
        /* Reconfigure MBFIDRx register */
        Fr_Flexray_WriteRegister(ctrlIdx, (FLEXRAY_MBFIDR0_ADDR16 + u16mbRegOffset_37), (VAR(uint16, AUTOMATIC))(frameId & FLEXRAY_MBFIDR_FID_MASK_U16));
        
        /* Calculate the message buffer header:
           FR_memory_base_address + (Configuring_MB_number * MB_header_length) */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        /* @violates @ref FR_FLEXRAY_C_REF_1 */
        /* @violates @ref FR_FLEXRAY_C_REF_11 */
        pheaderMBPtr_37 = Fr_Flexray_GetData16Pointer((uint32)(Fr_pCfgPtr + ctrlIdx)->CCHardwareConfigPtr->CCFlexRayMemoryBaseAddress) + (u8tmpMBIdx_37 * FLEXRAY_HEADER_SIZE);
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        u16tmpRegVal_37 = (VAR(uint16, AUTOMATIC))(pheaderMBPtr_37[0] & 0xF800U);
        u16tmpRegVal_37 |= (frameId & 0x07FFU);
        /* Configure Frame ID */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_37[0U] = u16tmpRegVal_37;
        /* Configure Payload Length */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_37[1U] = (VAR(uint16, AUTOMATIC))(((((VAR(uint16, AUTOMATIC))payloadLength + 1U) & 0xFEU) >> 1) & FLEXRAY_FRAMEHEADER1_PLDLENMASK_U16);
        /* Configure Header CRC */
        /* @violates @ref FR_FLEXRAY_C_REF_4 */
        pheaderMBPtr_37[2U] = (VAR(uint16, AUTOMATIC))(headerCRC & 0x07FFU);
        
        /* Enable MB */
        Fr_Flexray_WriteRegister(ctrlIdx, (VAR(uint16, AUTOMATIC))(FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_37), FLEXRAY_MBCCSR_EDT_U16);
        /* Check MB is enabled*/
        if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_37) & FLEXRAY_MBCCSR_EDS_U16))
        {   /*Yes*/
            retVal_37 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
        } 
    }
    else /* Message buffer was not disabled */
    {   /* No */
        /* Buffer was not disabled return E_NOT_OK */
    }
    return retVal_37;
}
#endif /* FR_RECONFIG_LPDU_SUPPORT */

#if(FR_DISABLE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Flexray_DisableLPdu
*
* @brief            FrIP function for the Fr_Flexray_DisableLPdu
* @description      Disables required Message Buffer
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lPduIdx - Index of LPdu to be reconfigured
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
*
* @implements       Fr_Flexray_DisableLPdu_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_DisableLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_38 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint8, AUTOMATIC) u8tmpMBIdx_38;
    VAR(uint16, AUTOMATIC) u16mbRegOffset_38;
    
    /* Get current MB Idx */
    /* @violates @ref FR_FLEXRAY_C_REF_4 */
    u8tmpMBIdx_38 = (Fr_pCfgPtr + ctrlIdx)->BufferConfigSetPtr->LPduInfoPtr[lPduIdx].MessageBufferNumber;
    /* Offset from FR base address to the MB registers */
    u16mbRegOffset_38 = (((VAR(uint16, AUTOMATIC))u8tmpMBIdx_38) * 4U);
        
    if(FLEXRAY_MBCCSR_EDS_U16 == (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_38) & FLEXRAY_MBCCSR_EDS_U16))
    {
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_38, FLEXRAY_MBCCSR_EDT_U16);
    }
    /* Check if buffer has been successfully disabled */
    if(FLEXRAY_MBCCSR_EDS_U16 != (Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MBCCSR0_ADDR16 + u16mbRegOffset_38) & FLEXRAY_MBCCSR_EDS_U16))
    {   /* Yes */
        retVal_38 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    }
    else
    {   /* No */
        /* Buffer was not disabled return E_NOT_OK */
    } 
    return retVal_38;  
}
#endif /* FR_DISABLE_LPDU_SUPPORT */

/***************************************************************************************************
* @function_name    Fr_Flexray_GetNumOfStartFrames
*
* @brief            FrIP function for the Fr_GetNumOfStartupFrames
* @description      Reads number of startup frames
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        configParamIdx - Index of LPdu to be reconfigured
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
*
* @implements        Fr_FlexRay_GetNumOfStartFrames_Activity
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE)Fr_Flexray_GetNumOfStartFrames
(
    VAR(uint8, AUTOMATIC) ctrlIdx, 
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) numOfStartupFramesPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_039 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    
    (void)ctrlIdx; /* Index is not used since no register is being read */
    /* FlexRay 2.1 Rev A compliant hardware does not suppport accumulating the number of 
       startupframes. The driver shall always assume 2 startup frames available */
    *numOfStartupFramesPtr = 2U;
    
    return retVal_039; 
}

/***************************************************************************************************
* @function_name    Fr_Flexray_DisableTimers
*
* @brief            IP function for disabling timer interrupts
* @description      Disables timers
* @param[in]        ctrlIdx - Index of FlexRay CC
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE)Fr_Flexray_DisableTimers
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_TICCR_ADDR16, (VAR(uint16, AUTOMATIC))(FLEXRAY_TICCR_T2SP_U16 | FLEXRAY_TICCR_T1SP_U16));
}

/***************************************************************************************************
* @function_name    Fr_Flexray_CheckCCAccess
*
* @brief            IP function for checking access to the CC
* @description      Checks access to the CC
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        Fr_CC_enabled - Indicates whether CC module should be enabled or not
* @param[in]        regMVR - Value of the MVR
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_CheckCCAccess
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    CONST(boolean, AUTOMATIC) Fr_CC_enabled,
    CONST(uint16, AUTOMATIC) regMVR
)
{
    VAR(uint16, AUTOMATIC) u16regVal_154;    /* Temporary variable for register access */
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_154 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);

    /* Check if MVR register is correct */
    if (regMVR != Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MVR_ADDR16))
    {/* MVR register is wrong, report error */
        retVal_154 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }

    if (Fr_CC_enabled)
    {
        if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == retVal_154)
        {
            /* Check if FlexRay module is enabled */
            u16regVal_154 = Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_MCR_ADDR16);
            if ((u16regVal_154 & FLEXRAY_MCR_MEN_U16) != FLEXRAY_MCR_MEN_U16)
            {/* FlexRay module is not enabled, report error */
                retVal_154 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            }
        }
    }

    return retVal_154;
}
#ifdef SUPPORT_IP_V9
#ifdef FR_ACCESS_ERROR_NOTIFICATION_EN
/***************************************************************************************************
* @function_name    Fr_Flexray_EnableErrorIRQs
*
* @brief            IP function for enable access error interrupt to the CC
* @description      enable access error interrupt to the CC
* @param[in]        ctrlIdx - Index of FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_EnableErrorIRQs
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    VAR(uint16, AUTOMATIC) u16tmpVal_022;
    VAR(Std_ReturnType, AUTOMATIC) retVal_157 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    
    /* Load value of GIFER register */
    u16tmpVal_022 = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16) & FLEXRAY_GIFER_CTRL_FLAGS_MASK_U16);
    /* Check previous value of CHIE bit */
    if (FLEXRAY_GIFER_CHIE_U16 != (VAR(uint16, AUTOMATIC))(u16tmpVal_022 & FLEXRAY_GIFER_CHIE_U16))
    {
        /* The CHIE bit not yet set */
        /* Set CHIE bit */
        Fr_Flexray_WriteRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16, (VAR(uint16, AUTOMATIC))(u16tmpVal_022 | FLEXRAY_GIFER_CHIE_U16));
        /* Check again the CHIE bit value */
        if (FLEXRAY_GIFER_CHIE_U16 == (VAR(uint16, AUTOMATIC))((VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(ctrlIdx, FLEXRAY_GIFER_ADDR16) & FLEXRAY_GIFER_CTRL_FLAGS_MASK_U16) & FLEXRAY_GIFER_CHIE_U16))
        {
            retVal_157 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
        }
    }
    else
    {
        retVal_157 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    }
    
    return retVal_157;
}
#endif /* FR_ACCESS_ERROR_NOTIFICATION_EN */
#endif /* SUPPORT_IP_V9 */
#if(FR_DEINIT_API == STD_ON)
/*************************************************************************************************
* @function_name    Fr_Flexray_GoDefaultConfig
*
* @brief            IP function for FlexRay Deinitializationn
* @description      Put POC to Default config state form
* @param[in]        u8CtrlIdx - Index of FlexRay CC
* @return           none
**************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GoDefaultConfig
(
    VAR(uint8, AUTOMATIC) u8CtrlIdx
)
{
    VAR(Std_ReturnType, AUTOMATIC) retVal_159 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    
    /* Transition back to POC:halt (Required to access POC:default config) */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(u8CtrlIdx, FLEXRAY_POCR_CMD_FREEZE_U16))
    {
        /* Transition back to POC:default config (Required to clear MEN bit) */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_InvokeCHICommand(u8CtrlIdx, FLEXRAY_POCR_CMD_DEFAULTCONFIG_U16))
        {
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_WaitForPOCState(u8CtrlIdx, FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16))
            {
                retVal_159 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
        }
    }
    return retVal_159;
}
/*************************************************************************************************
* @function_name    Fr_Flexray_DeInit
*
* @brief            IP function for FlexRay Deinitializationn
* @description      
* @param[in]        u8CtrlIdx - Index of FlexRay CC
* @return           none
**************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_DeInit
(
    VAR(uint8, AUTOMATIC) u8CtrlIdx
)
{

    VAR(uint8, AUTOMATIC) u8loop;
    VAR(uint16, AUTOMATIC) u16tmp_MaxMB;
    VAR(uint16, AUTOMATIC) u16tmp_RegRead;
    VAR(uint8, AUTOMATIC) u8tmp_TimeOut;
    VAR(Std_ReturnType, AUTOMATIC) retVal_160 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(boolean, AUTOMATIC) Fr_bBufferError = (VAR(boolean, AUTOMATIC))FALSE;

    /* Now in state POC:config, can clear most registers */
    for(u8loop = 0U; u8loop < FLEXRAY_NUMBER_PCR_U8; u8loop++)
    {
        /* Clear all FLEXRAY_PCRn registers */
        Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_PCR0_ADDR16 + (u8loop)), FLEXRAY_RESET_VAL_U16);
    }
    /* Clear all other registers that can be cleared */
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_STBSCR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_MBDSR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_PEDRDR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_PIER0_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_PIER1_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SFTOR_ADDR16 , FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SFTOR_ADDR16 , FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SFIDAFVR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SFIDAFMR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_NMVLR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_TICCR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SFTCCSR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_TI1CYSR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_TI1MTOR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_TI2CR0_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_TI2CR1_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SSSR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SSCCR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_MTSACFR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_MTSBCFR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RSBIR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFWMSR_ADDR16 , FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFSIR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFDSR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFMIDAFVR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFMIDAFMR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFFIDRFVR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFFIDRFMR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFRFCFR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFRFCTR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFSDOR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFPTR_ADDR16, FLEXRAY_RESET_VAL_U16);
    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFFLPCR_ADDR16, FLEXRAY_RESET_VAL_U16);

    /* Wait for FLEXRAY_EERICR.BSY is cleared */
    u8tmp_TimeOut = 0U;
    do
    {
        u16tmp_RegRead = (VAR(uint16, AUTOMATIC))(Fr_Flexray_ReadRegister(u8CtrlIdx, FLEXRAY_EERICR_ADDR16));
        u8tmp_TimeOut++;
    }while(((u16tmp_RegRead & FLEXRAY_EERICR_BSY_U16) == FLEXRAY_EERICR_BSY_U16) && (u8tmp_TimeOut < FR_IPW_MAX_WAITCYCLES_U8));
    if(((u16tmp_RegRead & FLEXRAY_EERICR_BSY_U16) == 0U) && (u8tmp_TimeOut < FR_IPW_MAX_WAITCYCLES_U8))
    {
        Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_EERICR_ADDR16, FLEXRAY_RESET_VAL_U16);
        Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_EEIAR_ADDR16, FLEXRAY_RESET_VAL_U16);
        Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_EEIDR_ADDR16, FLEXRAY_RESET_VAL_U16);
        Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_EEICR_ADDR16, FLEXRAY_RESET_VAL_U16);
        Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_MBSSUTR_ADDR16, FLEXRAY_MBSSUTR_RESET_VAL_U16);
        
        /* Read back FLEXRAY_MBSSUTR to get the maximum number of Message Buffers. */
        u16tmp_MaxMB = (VAR(uint16, AUTOMATIC))((Fr_Flexray_ReadRegister(u8CtrlIdx, FLEXRAY_MBSSUTR_ADDR16)) & ((VAR(uint16, AUTOMATIC))0x7FU));
        /* Loop to clear all Message Buffers */
        for (u8loop = 0U; u8loop <= u16tmp_MaxMB; u8loop++)
        {
            /* If Message Buffer is Enabled, Disable it */
            if (((Fr_Flexray_ReadRegister(u8CtrlIdx, (FLEXRAY_MBCCSR0_ADDR16 + ((uint16)u8loop * 4U)))) & FLEXRAY_MBCCSR_EDS_U16) == FLEXRAY_MBCCSR_EDS_U16)
            {
                /* Write to EDT bit must be done separately */
                Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBCCSR0_ADDR16 + ((uint16)u8loop * 4U)) , FLEXRAY_MBCCSR_EDT_U16);
            }
            /* Check again the EDS bit in order to make sure that this buffer is disabled */
            if ((Fr_Flexray_ReadRegister(u8CtrlIdx, (FLEXRAY_MBCCSR0_ADDR16 + ((uint16)u8loop * 4U))) & FLEXRAY_MBCCSR_EDS_U16) != FLEXRAY_MBCCSR_EDS_U16)
            {
                Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBCCSR0_ADDR16 + ((uint16)u8loop * 4U)), FLEXRAY_RESET_VAL_1_U16);
                Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBCCFR0_ADDR16 + ((uint16)u8loop * 4U)), FLEXRAY_RESET_VAL_U16);
                Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBFIDR0_ADDR16 + ((uint16)u8loop * 4U)), FLEXRAY_RESET_VAL_U16);
                Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBIDXR0_ADDR16 + ((uint16)u8loop * 4U)), FLEXRAY_RESET_VAL_U16);
                /* Clear FLEXRAY_MBDORn registers */
                Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBDOR0_ADDR16 + (uint16)u8loop), FLEXRAY_RESET_VAL_U16);
            }
            else
            {
                Fr_bBufferError = (VAR(boolean, AUTOMATIC))TRUE;
                break; /* This buffer can not disabled */
            }
        }
        /* Check if has less one buffer can not disabled */
        if ((VAR(boolean, AUTOMATIC))FALSE == Fr_bBufferError)
        {
            /* do not have any buffer can not disabled, run to next step*/
            /* Additional 4 extra FLEXRAY_MBDORn registers to clear */
            Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBDOR0_ADDR16 + (u8loop)), FLEXRAY_RESET_VAL_U16);
            u8loop++;
            Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBDOR0_ADDR16 + (u8loop)), FLEXRAY_RESET_VAL_U16);
            u8loop++;
            Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBDOR0_ADDR16 + (u8loop)), FLEXRAY_RESET_VAL_U16);
            u8loop++;
            Fr_Flexray_WriteRegister(u8CtrlIdx, (FLEXRAY_MBDOR0_ADDR16 + (u8loop)), FLEXRAY_RESET_VAL_U16);
            
            /* Clear interrupt flags */
            Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_GIFER_ADDR16, FLEXRAY_GIFER_RESET_VAL_U16);
            Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_PIFR0_ADDR16, FLEXRAY_PIFR0_RESET_VAL_U16);
            Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_PIFR1_ADDR16, FLEXRAY_PIFR1_RESET_VAL_U16);
            Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_PSR1_ADDR16, FLEXRAY_PSR1_RESET_VAL_U16);
            Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_PSR3_ADDR16, FLEXRAY_PSR3_RESET_VAL_U16);
            Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_EEIFER_ADDR16, FLEXRAY_EEIFER_RESET_VAL_U16);
            Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_CHIERFR_ADDR16, FLEXRAY_CHIERFR_RESET_VAL_U16);
            
            /* Go to default config in order to clear MEM bit */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_GoDefaultConfig(u8CtrlIdx))
            {
                /* Now in POC:default config, can clear MEN flag */
                /* Clear MEN bit to disable FR Module */
                Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_MCR_ADDR16, FLEXRAY_RESET_VAL_U16);
                
                /* Check if MEN bit has been successfully cleared */
                if((((Fr_Flexray_ReadRegister(u8CtrlIdx, FLEXRAY_MCR_ADDR16)) & FLEXRAY_MCR_MEN_U16) == 0U))
                {
                    /* Reset registers that can only be written in disabled mode */
                    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_MCR_ADDR16, FLEXRAY_RESET_VAL_U16);
                    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SYMATOR_ADDR16, FLEXRAY_SYMATOR_RESET_VAL_U16);
                    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SYMBADHR_ADDR16, FLEXRAY_RESET_VAL_U16);
                    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_SYMBADLR_ADDR16, FLEXRAY_RESET_VAL_U16);
                    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFSYMBADHR_ADDR16, FLEXRAY_RESET_VAL_U16);
                    Fr_Flexray_WriteRegister(u8CtrlIdx, FLEXRAY_RFSYMBADLR_ADDR16, FLEXRAY_RESET_VAL_U16);
                    retVal_160 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                }
            }
        }
    }
    
    return retVal_160;
}  
#endif /* FR_DEINIT_API */
#define FR_STOP_SEC_CODE
/* Covers FR112 */
/* @violates @ref FR_FLEXRAY_C_REF_3 */
/* @violates @ref FR_FLEXRAY_C_REF_6 */
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
