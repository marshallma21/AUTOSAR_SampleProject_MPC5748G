/**
*   @file    Fr_IPW.c
*   @implements Fr_IPW.c_Artifact
*
*   @version 1.0.0
*
*   @brief   AUTOSAR Fr - FlexRay module IPW file.
*   @details Provides functions for FlexRay IP module access.
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
* @section FR_IPW_C_REF_1
* Violates MISRA 2004 Required Rule 19.15, #include "Fr_MemMap.h" is not preceded only by
* preprocessor directives and appears not only in the beginning of file because it otherwise
* would not work.
*
* @section FR_IPW_C_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, Inclusion of "Fr_MemMap.h" is required here because of
* its functionality.
*
* @section FR_IPW_C_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifier specified by ASR.
*
* @section FR_IPW_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler - linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* Identifier is specified by ASR standard.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Fr_IPW.h"
#include "Fr_Flexray.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_IPW_MODULE_ID_C                        81
#define FR_IPW_VENDOR_ID_C                        43
/* @violates @ref FR_IPW_C_REF_3 */
/* @violates @ref FR_IPW_C_REF_4 */
#define FR_IPW_AR_RELEASE_MAJOR_VERSION_C         4
/* @violates @ref FR_IPW_C_REF_3 */
/* @violates @ref FR_IPW_C_REF_4 */
#define FR_IPW_AR_RELEASE_MINOR_VERSION_C         2
/* @violates @ref FR_IPW_C_REF_3 */
/* @violates @ref FR_IPW_C_REF_4 */
#define FR_IPW_AR_RELEASE_REVISION_VERSION_C      2
#define FR_IPW_SW_MAJOR_VERSION_C                 1
#define FR_IPW_SW_MINOR_VERSION_C                 0
#define FR_IPW_SW_PATCH_VERSION_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_IPW.h header file are of the same vendor */
#if(FR_IPW_VENDOR_ID_C != FR_IPW_VENDOR_ID)
    #error "Fr_IPW.c and Fr_IPW.h have different Vendor IDs"
#endif
/* Check if current file and Fr_IPW.h header file are of the same Autosar version */
#if((FR_IPW_AR_RELEASE_MAJOR_VERSION_C    != FR_IPW_AR_RELEASE_MAJOR_VERSION) || \
    (FR_IPW_AR_RELEASE_MINOR_VERSION_C    != FR_IPW_AR_RELEASE_MINOR_VERSION) || \
    (FR_IPW_AR_RELEASE_REVISION_VERSION_C != FR_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_IPW.c and Fr_IPW.h are different"
#endif
/* Check if current file and Fr_IPW.h header file are of the same software version */
#if((FR_IPW_SW_MAJOR_VERSION_C != FR_IPW_SW_MAJOR_VERSION) || \
    (FR_IPW_SW_MINOR_VERSION_C != FR_IPW_SW_MINOR_VERSION) || \
    (FR_IPW_SW_PATCH_VERSION_C != FR_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_IPW.c and Fr_IPW.h are different"
#endif

/* Check if current file and Fr_Flexray.h header file are of the same vendor */
#if(FR_IPW_VENDOR_ID_C != FR_FLEXRAY_VENDOR_ID)
    #error "Fr_IPW.c and Fr_Flexray.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Flexray.h header file are of the same Autosar version */
#if((FR_IPW_AR_RELEASE_MAJOR_VERSION_C    != FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION) || \
    (FR_IPW_AR_RELEASE_MINOR_VERSION_C    != FR_FLEXRAY_AR_RELEASE_MINOR_VERSION ) || \
    (FR_IPW_AR_RELEASE_REVISION_VERSION_C != FR_FLEXRAY_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_IPW.c and Fr_Flexray.h are different"
#endif
/* Check if current file and Fr_Flexray.h header file are of the same software version */
#if((FR_IPW_SW_MAJOR_VERSION_C != FR_FLEXRAY_SW_MAJOR_VERSION) || \
    (FR_IPW_SW_MINOR_VERSION_C != FR_FLEXRAY_SW_MINOR_VERSION) || \
    (FR_IPW_SW_PATCH_VERSION_C != FR_FLEXRAY_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_IPW.c and Fr_Flexray.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if((FR_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (FR_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr_IPW.c and Mcal.h are different"
    #endif
#endif /* CHECK_AUTOSAR_VERSION */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* @violates @ref FR_IPW_C_REF_3 */
#define FR_START_SEC_VAR_INIT_BOOLEAN
/* @violates @ref FR_IPW_C_REF_1 */
#include "Fr_MemMap.h"
/* The permission for enabling FR module */
VAR(boolean, FR_VAR) Fr_bModuleEnablePermission = (VAR(boolean, FR_VAR))TRUE;
#define FR_STOP_SEC_VAR_INIT_BOOLEAN
/* @violates @ref FR_IPW_C_REF_1 */
/* @violates @ref FR_IPW_C_REF_2 */
#include "Fr_MemMap.h"

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FR_START_SEC_CODE
/* Covers FR112 */
/* @violates @ref FR_IPW_C_REF_1 */
/* @violates @ref FR_IPW_C_REF_2 */
#include "Fr_MemMap.h"


/***************************************************************************************************
* @function_name    Fr_Ipw_CCInit
*
* @brief            LLD function for FlexRay CC configuration
* @description      Writes values from configuration file into the Module Configuration Register
* @param[in]        ctrlIdx - Index of FlexRay CC  
* @return           ::Std_ReturnType
*                       - E_OK      FR CC was successfully reinitialized
*                       - E_NOT_OK  not possible to move FR CC to default config state
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_CCInit
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_6 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Flexray_CCInit(ctrlIdx))
    {
        /* Enable permission for enabling FR Module */
        Fr_bModuleEnablePermission = (VAR(boolean, FR_VAR))TRUE;
        retVal_6 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    }
    else
    {
        #if (FR_IPW_CC_ONCE_ENABLEONLYMODE == STD_ON)
        /* Only one correct initialization of FR CC is allowed */
            /* Disable permission for enabling FR Module */
            Fr_bModuleEnablePermission = (VAR(boolean, FR_VAR))FALSE;
        
        #else
        /* Initialization of FR CC is permanently allowed */
            /* Enable permission for enabling FR Module */
            Fr_bModuleEnablePermission = (VAR(boolean, FR_VAR))TRUE;
        #endif
    }
    
    return retVal_6;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_CheckCCAccess
*
* @brief            LLD function for checking access to the CC
* @details          Function checks whether the FlexRay CC is accessible or not
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        Fr_CC_enabled Indicates whether CC module should be enabled or not
* @return           ::Std_ReturnType
*                       - E_OK      CC is accessible
*                       - E_NOT_OK  CC is not accessible
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_CheckCCAccess
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    CONST(boolean, AUTOMATIC) Fr_CC_enabled
)
{
    /* Check Module Version Register for S32R274 0xA568 */
    return  Fr_Flexray_CheckCCAccess (ctrlIdx, Fr_CC_enabled, 0xA568U);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_ClusterNodeParamCfg
*
* @brief            LLD function for cluster and node parameters configuration
* @description      Writes values from configuration file into the FlexRay CC 
*                   Protocol Configuration Registers
* @param[in]        ctrlIdx - Index of FlexRay CC  
* @param[out]       none
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_ClusterNodeParamCfg
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    Fr_Flexray_ClusterNodeParamCfg(ctrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_ClearDisableIRQs
*
* @brief            LLD function which clears all interrupt flags and disables all interrupts.
* @details          Function clears all MBIF flags and clears GIFER, PIFR0, PIFR1, PIER0 and PIER1
*                   registers.
* @param[in]        ctrlIdx - Index of FlexRay CC          
* @return           ::Std_ReturnType
*                       - E_OK      All interrupt flags were cleared and all interrupts were
*                                   disabled
*                       - E_NOT_OK  Some interrupt flag was not clear or some interrupt was not
*                                   disabled
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_ClearDisableIRQs
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    return Fr_Flexray_ClearDisableIRQs(ctrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_LeavePOCConfigState
*
* @brief            LLD function for leaving the POC:Config state - entering POC:Ready state
* @details          This API call transmit the CC into POC:Ready state. It is assumed that
*                   CC is in the POC:Config state.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @return           ::Std_ReturnType:
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Error occurred during transition into POC:Ready
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_LeavePOCConfigState
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    return Fr_Flexray_LeavePOCConfigState(ctrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_DisableTimers
*
* @brief            LLD function which disables timers.
* @details          Function clears all T1SP and T2SP bits in the TICCR register.
* @param[in]        ctrlIdx - Index of FlexRay CC          
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_DisableTimers
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    Fr_Flexray_DisableTimers(ctrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetPOCState
*
* @brief            LLD function for quering the controller POC status
* @description      Read the FlexRay controller Protocol Status Register 1.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[out]       pocStatus - Address of the variable wher the Protocol status is stored to
* @return           uint16
***************************************************************************************************/
FUNC(uint16, FR_CODE) Fr_Ipw_GetPOCState
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    /* Return current state of the protocol */
    return Fr_Flexray_GetPOCState(ctrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetPOCStatus
*
* @brief            LLD function for quering the controller POC status
* @description      Read the FlexRay controller Protocol Status Register 1.
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[out]       pocStatusPtr - Address of the variable wher the Protocol status is stored to
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Reserved value was read
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetPOCStatus
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) pocStatusPtr
)
{
    return Fr_Flexray_GetPOCStatus(ctrlIdx, pocStatusPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_InvokeCHIcommand
*
* @brief            LLD function for invoking POCCMD commands
* details           Invokes required CHI command
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        chiCommand - required CHI command
* @return           ::Std_ReturnType:
*                       - E_OK      CHI command was accepted by PE
*                       - E_NOT_OK  CHI command was not accepted by PE due to BSY flag
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_InvokeCHICommand
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) chiCommand
)
{
    return Fr_Flexray_InvokeCHICommand(ctrlIdx, chiCommand);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_BuffersInit
*
* @brief            LLD function for message buffers configuration
* @details          This function configures the transmit, receive message buffers, shadow buffers 
*                   and FIFO arrays
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully
*                       - E_NOT_OK  Function call aborted due to errors
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_BuffersInit
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    return Fr_Flexray_BuffersInit(ctrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_EnterPOCConfigState 
*
* @brief            LLD function for entering the POC:Config state
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
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_EnterPOCConfigState 
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    return Fr_Flexray_EnterPOCConfigState(ctrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_AckAbsTimerIRQ
*
* @brief            LLD function for the Fr_AckAbsoluteTimerIRQ API            
* @details          Ack the FlexRay CC absolute timer 
* @param[in]        ctrlIdx - Index of FlexRay CC           
* @param[in]        timerIdx Index of absolute timer within the context of the FlexRay CC
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_AckAbsoluteTimerIRQ
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    Fr_Flexray_AckAbsTimerIRQ(ctrlIdx, timerIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_CancelAbsoluteTimer
*
* @brief            LLD function for the Fr_CancelAbsoluteTimer API            
* @details          Cancel the FlexRay CC absolute timer 
* @param[in]        ctrlIdx - Index of FlexRay CC          
* @param[in]        timerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_CancelAbsoluteTimer
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    Fr_Flexray_CancelAbsTimer(ctrlIdx, timerIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_DisableAbsoluteTimerIRQ
*
* @brief            LLD function for the Fr_DisableAbsoluteTimerIRQ API          
* @details          Disable the FlexRay CC absolute timer
* @param[in]        ctrlIdx - Index of FlexRay CC  
* @param[in]        timerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_DisableAbsoluteTimerIRQ
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    Fr_Flexray_DisableAbsTimerIRQ(ctrlIdx, timerIdx);    
}

/***************************************************************************************************
* @function_name    Fr_Ipw_EnableAbsoluteTimerIRQ
*
* @brief            LLD function for the Fr_EnableAbsoluteTimerIRQ          
* @details          Enable the FlexRay CC absolute timer
* @param[in]        ctrlIdx - Index of FlexRay CC         
* @param[in]        timerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_EnableAbsoluteTimerIRQ
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    Fr_Flexray_EnableAbsTimerIRQ(ctrlIdx, timerIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetAbsoluteTimerIRQStatus 
*
* @brief            LLD function for the Fr_GetAbsoluteTimerIRQStatus                      
* @details          Check whether absolute timer inerrupt flag is pending
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        timerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           ::boolean
*                     - TRUE - Interrupt is pending
*                     - FALSE - Interrupt is not pending
***************************************************************************************************/
FUNC(boolean, FR_CODE) Fr_Ipw_GetAbsoluteTimerIRQStatus
/* @violates @ref FR_IPW_C_REF_3 */
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx
)
{
    return Fr_Flexray_GetAbsTimerIRQStatus(ctrlIdx, timerIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_SetAbsoluteTimer
*
* @brief            LLD function for the Fr_SetAbsoluteTimer API          
* @details          Store information about absolute timer into the FlexRay CC registers
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        timeridx - Index of FlexRay timer
* @param[in]        cycle - Cycle the timer shall elapse in
* @param[in]        offset - Offset within cycle Fr_Cycle in units of macrotick the timer shall
*                            elapse at
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_SetAbsoluteTimer
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) timerIdx,
    VAR(uint8, AUTOMATIC) cycle,
    VAR(uint16, AUTOMATIC) offset
)
{
    Fr_Flexray_SetAbsTimer(ctrlIdx, timerIdx, cycle, offset);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_SetWakeupChannel
*
* @brief            LLD function for the Fr_SetWakeupChannel API        
* @details          Store information about wakeup channel into FlexRay CC registers
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[in]        chnlIdx - Index of FlexRay channel
* @return           ::Std_ReturnType:
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  Error occurred during set wakeup channel
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_SetWakeupChannel
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(Fr_ChannelType, AUTOMATIC) chnlIdx
)
{   /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) retVal_7 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    
    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Flexray_SetWakeupChannel(ctrlIdx, chnlIdx))
    {
        retVal_7 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    }
    return retVal_7;
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetGlobalTime
*
* @brief            LLD function for the Fr_GetGlobalTime API           
* @details          Query current cycle and macrotick from FlexRay CC registers
* @param[in]        ctrlIdx - Index of FlexRay CC 
* @param[out]       cyclePtr - Address where current cycle is stored to
* @param[out]       macrotickPtr - Address where current macrotick is stored to 
* @return           none
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetGlobalTime
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) cyclePtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) macroTickPtr
)
{
    return Fr_Flexray_GetGlobalTime(ctrlIdx, cyclePtr, macroTickPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetNmVector
*
* @brief            LLD function for the Fr_GetNmVector API
* @description      Read the network management vector of the last communication cycle
*                   and write it to the output parameter Fr_NmVectorPtr. The number of bytes
*                   written to the output parameter is constant and known at configuration time
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       nmVectorPtr - Address of the variable the NmVector is stored to
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetNmVector
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) nmVectorPtr,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) hwErr
)
{
    return Fr_Flexray_GetNmVector(ctrlIdx, nmVectorPtr, hwErr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetChannelStatus
*
* @brief            LLD function for the Fr_GetChannelStatus API
* @description      Reads the aggregated channel status, NIT status and symbol window status from 
*                   FLEXRAY_PSR2, and FLEXRAY_PSR3 registers
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       channelAStatusPtr - Address of the variable the channel A status is stored to
* @param[out]       channelAStatusPtr - Address of the variable the channel A status is stored to
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_GetChannelStatus
( 
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAStatusPtr, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBStatusPtr
)
{
    Fr_Flexray_GetChannelStatus(ctrlIdx, channelAStatusPtr, channelBStatusPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetClockCorrection
*
* @brief            LLD function for the Fr_GetChannelStatus API
* @description      Read rate and offset correction values from FR_RTCORVR and FR_OFCORVR registers
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       rateCorrectionPtr - Address of the variable the rate correction value is 
*                                       stored to
* @param[out]       offsetCorrectionPtr - Address of the variable the offset correction value is 
*                                         stored to
* @return           none
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetClockCorrection
( 
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) rateCorrectionPtr, 
    P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) offsetCorrectionPtr
)
{
    return Fr_Flexray_GetClockCorrection(ctrlIdx, rateCorrectionPtr, offsetCorrectionPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetSyncFrameList
*
* @brief            LLD function for the Fr_GetSyncFrameList API
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
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetSyncFrameList
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint8, AUTOMATIC) listSize, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAOddListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBOddListPtr
)
{

    return Fr_Flexray_GetSyncFrameList(ctrlIdx, listSize, channelAEvenListPtr, channelBEvenListPtr, channelAOddListPtr, channelBOddListPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_GetChannelStatus
*
* @brief            LLD function for the Fr_GetWakeupRxStatus API
* @description      Reads the Wakeup Symbol Received on channel A and channel B bits from the 
*                   FLEXRAY_PSR3 register
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[out]       wakeupRxStatusPtr - Address of a variable where the wakeup Rx status is stored to
* @return           none
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_GetWakeupRxStatus
( 
    VAR(uint8, AUTOMATIC) ctrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) wakeupRxStatusPtr 
)
{
    return Fr_Flexray_GetWakeupRxStatus(ctrlIdx, wakeupRxStatusPtr);
} 

/***************************************************************************************************
* @function_name    Fr_Ipw_ReadbackCCConfig
*
* @brief            LLD function for the Fr_ControllerInit API
* @description      Read back and compare cluster and configuration values to reference values 
*                   held in the configuration.
* @param[in]        ctrlIdx - Index of FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      Configuration is OK
*                       - E_NOT_OK  Error in configuration was found
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_ReadbackCCConfig
(
    VAR(uint8, AUTOMATIC) ctrlIdx
)
{
    return Fr_Flexray_ReadbackCCConfig(ctrlIdx);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_TransmitTxLPdu
*
* @brief            LLD function for the Fr_TransmitTxLPdu API
* @description      Copy data and activate it for transmission
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be transmitted 
* @param[in]        lsduPtr - Address of data to be transmitted
* @param[in]        lsduLength - Payload length of data to be transmitted
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_TransmitTxLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lpduIdx,
    P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) lsduPtr,
    VAR(uint8, AUTOMATIC) lsduLength
)
{
    return Fr_Flexray_TransmitTxLPdu(ctrlIdx, lpduIdx, lsduPtr, lsduLength);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_ReceiveRxLPdu
*
* @brief            LLD function for the Fr_receiveRxLPdu API
* @description      Copy receive payload data
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be transmitted 
* @param[out]       lsduPtr - Address of field that data is copied to
* @param[out]       lpduStatusPtr - Address of the variable the status is stored to
* @param[out]       lsduLengthPtr - Address of the variable the payload is stored to
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the controller
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_ReceiveRxLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lpduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr 
)
{
    return Fr_Flexray_ReceiveRxLPdu(ctrlIdx, lpduIdx, lsduPtr, lpduStatusPtr, lsduLengthPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_ReceiveFifoA
*
* @brief            LLD function for the Fr_receiveRxLPdu API
* @description      Copy FifoA data
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be transmitted 
* @param[out]       lsduPtr - Address of field that data is copied to
* @param[out]       lpduStatusPtr - Address of the variable the status is stored to
* @param[out]       lsduLengthPtr - Address of the variable the payload is stored to
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_ReceiveFifoA
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lpduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
)
{
    Fr_Flexray_ReceiveFifoA(ctrlIdx, lpduIdx, lsduPtr, lpduStatusPtr, lsduLengthPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_ReceiveFifoB
*
* @brief            LLD function for the Fr_receiveRxLPdu API
* @description      Copy FifoB data
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be transmitted 
* @param[out]       lsduPtr - Address of field that data is copied to
* @param[out]       lpduStatusPtr - Address of the variable the status is stored to
* @param[out]       lsduLengthPtr - Address of the variable the payload is stored to
* @return           none
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Ipw_ReceiveFifoB
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lpduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
)
{
    Fr_Flexray_ReceiveFifoB(ctrlIdx, lpduIdx, lsduPtr, lpduStatusPtr, lsduLengthPtr);
}

/***************************************************************************************************
* @function_name    Fr_Ipw_CheckTxLPduStatus
*
* @brief            LLD function for the Fr_CheckTxLPduStatus API
* @description      Check whether LPdu was transmitted or not
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be canceled
* @param[out]       txLPduStatusPtr - Address of the variable where the status information is 
*                                     stored to
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_CheckTxLPduStatus
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx,
    P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) txLPduStatusPtr
)
{
    return Fr_Flexray_CheckTxLPduStatus(ctrlIdx, lPduIdx, txLPduStatusPtr);
}

#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Ipw_PrepareLPdu
*
* @brief            LLD function for the Fr_PrepareLPdu API
* @description      Check LPdu status
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be prepared
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_PrepareLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx
)
{
    return Fr_Flexray_PrepareLPdu(ctrlIdx, lPduIdx);
}
#endif /* FR_PREPARE_LPDU_SUPPORT == STD_ON */

/***************************************************************************************************
* @function_name    Fr_Ipw_CancelTxLPdu
*
* @brief            LLD function for the Fr_CancelTxLPdu API
* @description      Cancel required LPdu and provide information about it
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lpduIdx - Index of LPdu to be canceled
* @param[out]       pendingStatus - Information whether the LPdu was canceled or not
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/ 
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_CancelTxLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) pendingStatus
) 
{
    return Fr_Flexray_CancelTxLPdu(ctrlIdx, lPduIdx, pendingStatus);
}

#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Ipw_ReconfigLPdu
*
* @brief            LLD function for the Fr_ReconfigLPdu API
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
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_ReconfigLPdu
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
    return Fr_Flexray_ReconfigLPdu(ctrlIdx, lPduIdx, frameId, chnlIdx, cycleRepetition, cycleOffset, payloadLength, headerCRC);
}
#endif /* FR_RECONFIG_LPDU_SUPPORT == STD_ON */

#if(FR_DISABLE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_Ipw_DisableLPdu
*
* @brief            LLD function for the Fr_DisableLPdu
* @description      Disables required Message Buffer
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        lPduIdx - Index of LPdu to be reconfigured
* @return           ::Std_ReturnType
*                       - E_OK      Function call finished successfully:
*                       - E_NOT_OK  Function call aborted due to no access to the FlexRay CC
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_DisableLPdu
(
    VAR(uint8, AUTOMATIC) ctrlIdx,
    VAR(uint16, AUTOMATIC) lPduIdx
)
{
    return Fr_Flexray_DisableLPdu(ctrlIdx, lPduIdx);
}
#endif /* FR_DISABLE_LPDU_SUPPORT == STD_ON */

/***************************************************************************************************
* @function_name    Fr_Ipw_GetNumOfStartupFrames
*
* @brief            LLD function for the Fr_GetNumOfStartupFrames
* @description      Reconfigures required LPdu
* @param[in]        ctrlIdx - Index of FlexRay CC
* @param[in]        configParamIdx - Index of LPdu to be reconfigured
* @return           ::uint32 - Parameter value
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE)Fr_Ipw_GetNumOfStartupFrames
( 
    VAR(uint8, AUTOMATIC) ctrlIdx, 
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) numOfStartupFramesPtr
)
{
    return Fr_Flexray_GetNumOfStartFrames(ctrlIdx, numOfStartupFramesPtr);
}
#if(FR_DEINIT_API == STD_ON)
/*************************************************************************************************
* @function_name    Fr_Ipw_WaitForPOCState
*
* @brief            LLD function for FlexRay Deinitializationn
* @description      Wait POC available into state.
* @param[in]        u8ctrlIdx - Index of FlexRay CC
* @return           none
**************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_WaitForPOCState
(
    VAR(uint8, AUTOMATIC) u8ctrlIdx,
    CONST(uint16, AUTOMATIC) u16pocState
)
{
    /* return Fr_Flexray_WaitForPOCState(u8ctrlIdx); */
    return Fr_Flexray_WaitForPOCState(u8ctrlIdx, u16pocState);
}
/**************************************************************************************************
* @function_name    Fr_IPW_DeInit
*
* @brief            LLD function for FlexRay Deinitialization
* @description     
* @param[in]        u8ctrlIdx - Index of FlexRay CC  
* @return           none
**************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_Ipw_DeInit
(
    VAR(uint8, AUTOMATIC) u8ctrlIdx
)
{
    return Fr_Flexray_DeInit(u8ctrlIdx);
}
#endif /* FR_DEINIT_API */

#define FR_STOP_SEC_CODE
/* Covers FR112 */
/* @violates @ref FR_IPW_C_REF_1 */
/* @violates @ref FR_IPW_C_REF_2 */
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
