/**
*   @file       Fr.c
*   @implements Fr.c_Artifact
*    
*   @version 1.0.0
*
*   @brief   AUTOSAR Fr - FlexRay driver code.
*   @details ASR4.0 FlexRay driver API.
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
* @section FR_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, #include "Fr_MemMap.h" is not preceded only by
* preprocessor directives and appears not only in the beginning of file because it otherwise
* would not work.
*
* @section FR_C_REF_3
* Violates MISRA 2004 Required Rule 17.4, No better way how to access HW memory area and some
* configuration structures.
*
* @section FR_C_REF_5
* Violates MISRA 2004 Advisory Rule 19.1, Inclusion of "Fr_MemMap.h" is required here because of
* its functionality.
*
* @section FR_C_REF_6
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable. Behaviour of this
* operation is expected.
*
* @section FR_C_REF_7
* Violates MISRA 2004 Required Rule 8.10, API functions and some configuration structure pointers
* requires external linkage.
*
* @section FR_C_REF_8
* Violates MISRA 2004 Required Rule 5.1, Identifier specified by ASR.
*
* @section FR_C_REF_10
* Violates MISRA 2004 Required Rule 1.4, The compiler - linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* Identifier is specified by ASR standard.
*
* @section FR_C_REF_11
* Violates MISRA 2004 Required Rule 8.7, Declaration required here.
*
*/
/* DOC 1 - Target platform and used compiler does not require special
           alignment for char, short, int, long type variables which allows
           typecasts between pointer to them and makes MISRA rule 11.4 permissible
           because no problems with data alignment will arise. */


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Fr.h"  /* Include FlexRay driver header file */
#include "Fr_IPW.h"
#include "Fr_Flexray.h"
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/* Covers FR071 */
#ifndef DEM_H
  #include "Dem.h" /* Include DEM header file */
#endif
#endif /* FR_DISABLE_DEM_REPORT_ERROR_STATUS */
#if(FR_DEV_ERROR_DETECT == STD_ON)
/* Covers FR118 */
    #include "Det.h"
#endif /* FR_DEV_ERROR_DETECT */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_VENDOR_ID_C                      43
#define FR_AR_RELEASE_MAJOR_VERSION_C       4
#define FR_AR_RELEASE_MINOR_VERSION_C       2
/* @violates @ref FR_C_REF_8 */
/* @violates @ref FR_C_REF_10 */
#define FR_AR_RELEASE_REVISION_VERSION_C    2
#define FR_SW_MAJOR_VERSION_C               1
#define FR_SW_MINOR_VERSION_C               0
#define FR_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr.h header file are of the same vendor */
#if(FR_VENDOR_ID_C != FR_VENDOR_ID)
    #error "Fr.c and Fr.h have different Vendor IDs"
#endif
/* Check if current file and Fr.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION_C != FR_AR_RELEASE_MAJOR_VERSION) || \
    (FR_AR_RELEASE_MINOR_VERSION_C != FR_AR_RELEASE_MINOR_VERSION) || \
    (FR_AR_RELEASE_REVISION_VERSION_C != FR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr.c and Fr.h are different"
#endif
/* Check if current file and Fr.h header file are of the same Software version */
#if((FR_SW_MAJOR_VERSION_C != FR_SW_MAJOR_VERSION) || \
    (FR_SW_MINOR_VERSION_C != FR_SW_MINOR_VERSION) || \
    (FR_SW_PATCH_VERSION_C != FR_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr.c and Fr.h are different"
#endif

/* Check if current file and Fr_IPW.h header file are of the same vendor */
#if(FR_VENDOR_ID_C != FR_IPW_VENDOR_ID)
    #error "Fr.c and Fr_IPW.h have different Vendor IDs"
#endif
/* Check if current file and Fr_IPW.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION_C    != FR_IPW_AR_RELEASE_MAJOR_VERSION) || \
    (FR_AR_RELEASE_MINOR_VERSION_C    != FR_IPW_AR_RELEASE_MINOR_VERSION) || \
    (FR_AR_RELEASE_REVISION_VERSION_C != FR_IPW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr.c and Fr_IPW.h are different"
#endif
/* Check if current file and Fr_IPW.h header file are of the same Software version */
#if((FR_SW_MAJOR_VERSION_C != FR_IPW_SW_MAJOR_VERSION) || \
    (FR_SW_MINOR_VERSION_C != FR_IPW_SW_MINOR_VERSION) || \
    (FR_SW_PATCH_VERSION_C != FR_IPW_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr.c and Fr_IPW.h are different"
#endif

/* Check if current file and Fr_Flexray.h header file are of the same vendor */
#if(FR_VENDOR_ID_C!= FR_FLEXRAY_VENDOR_ID)
    #error "Fr.c and Fr_Flexray.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Flexray.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION_C    != FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION) || \
    (FR_AR_RELEASE_MINOR_VERSION_C    != FR_FLEXRAY_AR_RELEASE_MINOR_VERSION) || \
    (FR_AR_RELEASE_REVISION_VERSION_C != FR_FLEXRAY_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr.c and Fr_Flexray.h are different"
#endif
/* Check if current file and Fr_Flexray.h header file are of the same Software version */
#if((FR_SW_MAJOR_VERSION_C != FR_FLEXRAY_SW_MAJOR_VERSION) || \
    (FR_SW_MINOR_VERSION_C != FR_FLEXRAY_SW_MINOR_VERSION) || \
    (FR_SW_PATCH_VERSION_C != FR_FLEXRAY_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr.c and Fr_Flexray.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* Check if current file and Dem.h header file are of the same Autosar version */
        #if((FR_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
            (FR_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Fr.c and Dem.h are different"
        #endif
    #endif /* FR_DISABLE_DEM_REPORT_ERROR_STATUS */

    #if(FR_DEV_ERROR_DETECT == STD_ON)
        /* Check if current file and Det.h header file are of the same Autosar version */
        #if((FR_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
            (FR_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Fr.c and Det.h are different"
        #endif
    #endif  /* FR_DEV_ERROR_DETECT */

    /* Check if current file and Mcal.h header file are of the same Autosar version */
    #if((FR_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (FR_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr.c and Mcal.h are different"
    #endif

#endif /* CHECK_AUTOSAR_VERSION */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#if(FR_DEV_ERROR_DETECT == STD_ON)
/* Only if FR_DEV_ERROR_DETECT is enabled: */

#define FR_START_SEC_VAR_NO_INIT_8
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"
/* Variable used to store nuber of configured controllers*/
VAR(static uint8, FR_VAR) Fr_u8CtrlNumber; 
/* Arrays used for storage information how many absolute timers have been
   configured in a certain CC (0 - no timer configured) */
VAR(static uint8, FR_VAR) Fr_au8AbsoluteTimersNum[FR_NUM_CTRL_SUPPORTED];
#define FR_STOP_SEC_VAR_NO_INIT_8
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

#endif /* FR_DEV_ERROR_DETECT */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
/* @violates @ref FR_C_REF_8 */
/* @violates @ref FR_C_REF_10 */
#define FR_START_SEC_VAR_INIT_UNSPECIFIED
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

/* Pointer to configuration structure */
P2CONST(Fr_ConfigurationType, FR_VAR, FR_APPL_CONST) Fr_pCfgPtr = NULL_PTR;

#if(FR_DEV_ERROR_DETECT == STD_ON)
/* Driver states variable */
/* @violates @ref FR_C_REF_7 */
VAR(Fr_SoftwareStatesType, FR_VAR) Fr_eDriverStates = FR_UNINIT;
#endif

/* @violates @ref FR_C_REF_8 */
#define FR_STOP_SEC_VAR_INIT_UNSPECIFIED
/* Covers FR112 */
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

#define FR_START_SEC_VAR_INIT_16
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
    /* Only if FR_PREPARE_LPDU_SUPPORT is enabled: */
    /* Array is used for storage of information which virtual message buffer is currently configured
    for the physical message buffer each array element represents one physical MB and stored value
    corresponds with configured virtual MB index.
    Example: VirtualResourceAllocation[15] means that MB with index 15 (MBCCSR15,MBIDX15...) is
    configured for virtual MB with index 26 */
VAR(uint16, FR_VAR) Fr_VirtualResourceAllocation[FR_NUM_CTRL_SUPPORTED][FR_NUMBER_MB] = {{0U}};
#endif  /* FR_PREPARE_LPDU_SUPPORT */

#define FR_STOP_SEC_VAR_INIT_16
/* Covers FR112 */
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

/* @violates @ref FR_C_REF_8 */
#define FR_START_SEC_VAR_INIT_BOOLEAN
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"
/* The permission for enabling FR module */
extern VAR(boolean, FR_VAR) Fr_bModuleEnablePermission;

/* The Flexray controller state */
/* @violates @ref FR_C_REF_7 */
VAR(boolean, FR_VAR) Fr_bCCActive[FR_NUM_CTRL_SUPPORTED] = {(VAR(boolean, AUTOMATIC))FALSE};
#define FR_STOP_SEC_VAR_INIT_BOOLEAN
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

#define FR_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

#if (FR_VARIANT_PRECOMPILE == STD_ON)
/* @violates @ref FR_C_REF_11 */
FR_CONF_PC
#endif /* (FR_VARIANT_PRECOMPILE) */

#define FR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON) 

#if(FR_DEV_ERROR_DETECT == STD_ON)
static FUNC(Std_ReturnType, FR_CODE) Fr_ReconfigLPduDetReport
                                                            (
                                                                VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
                                                                VAR(uint16, AUTOMATIC) Fr_LPduIdx,
                                                                VAR(uint16, AUTOMATIC) Fr_FrameId,
                                                                VAR(Fr_ChannelType, AUTOMATIC) Fr_ChnlIdx,
                                                                VAR(uint8, AUTOMATIC) Fr_CycleRepetition,
                                                                VAR(uint8, AUTOMATIC) Fr_CycleOffset,
                                                                VAR(uint8, AUTOMATIC) Fr_PayloadLength,
                                                                VAR(uint16, AUTOMATIC) Fr_HeaderCRC
                                                            );
#endif/* FR_DEV_ERROR_DETECT */

#endif /* FR_RECONFIG_LPDU_SUPPORT */

#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
static FUNC(void, FR_CODE) Fr_Dem_ReportErrorStatus(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(Dem_EventStatusType, AUTOMATIC) u16StatusMask);
#endif

#if(FR_DEV_ERROR_DETECT == STD_ON)
static FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInitDetReport (VAR(uint8, AUTOMATIC) Fr_CtrlIdx);
#endif
#ifdef SUPPORT_IP_V9
#if (STD_ON == FR_INIT_ERROR_NOTIFICATION_EN)
extern void FR_INIT_ERROR_NOTIFICATION(void);
#endif /* FR_INIT_ERROR_NOTIFICATION_EN */
#endif /* SUPPORT_IP_V9 */
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON) 

#if(FR_DEV_ERROR_DETECT == STD_ON)
/* Only if FR_DEV_ERROR_DETECT is enabled: */
/***************************************************************************************************
* @function_name    Fr_ReconfigLPduDetReport
*
* @brief            Check and report error of parametters. 
* @details          Check error when error detection is enabled. 
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_FrameId FlexRay Frame ID the FrIf_LPdu shall be configured to
* @param[in]        Fr_ChnlIdx FlexRay Channel the FrIf_LPdu shall be configured to
* @param[in]        Fr_CycleRepetition Cycle Repetition part of the cycle filter mechanism 
*                                      FrIf_LPdu shall be configured to.
* @param[in]        Fr_CycleOffset Cycle Offset part of the cycle filter mechanism FrIf_LPdu shall 
*                                  be configured to.
* @param[in]        Fr_PayloadLength Payloadlength in units of bytes the FrIf_LPduIdx shall be 
*                                    configured to.
* @param[in]        Fr_HeaderCRC Header CRC the FrIf_LPdu shall be configured to.
* @return           :Std_ReturnType
*                       - E_OK      Don not have any error.
*                       - E_NOT_OK  Have least one error.
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_ReconfigLPduDetReport
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint16, AUTOMATIC) Fr_LPduIdx,
    VAR(uint16, AUTOMATIC) Fr_FrameId,
    VAR(Fr_ChannelType, AUTOMATIC) Fr_ChnlIdx,
    VAR(uint8, AUTOMATIC) Fr_CycleRepetition,
    VAR(uint8, AUTOMATIC) Fr_CycleOffset,
    VAR(uint8, AUTOMATIC) Fr_PayloadLength,
    VAR(uint16, AUTOMATIC) Fr_HeaderCRC
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_37 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_RECONFIGLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_CTRL_IDX_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if(Fr_LPduIdx > (((Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->BuffersConfiguredCount) - 1U))
    {
        /* Fr_LPduIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_LPDU_IDX_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if(((VAR(boolean, AUTOMATIC))TRUE == (Fr_pCfgPtr + Fr_CtrlIdx)->CCHardwareConfigPtr->SingleChannelModeEnabled) && ((Fr_pCfgPtr + Fr_CtrlIdx)->CCHardwareConfigPtr->Channels != Fr_ChnlIdx))
    {
        /* Fr_ChnlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_CHNL_IDX_U8);
    }
    else if((Fr_CycleRepetition != 1U) && (Fr_CycleRepetition != 2U)  && (Fr_CycleRepetition != 4U)
                                       && (Fr_CycleRepetition != 8U)  && (Fr_CycleRepetition != 16U)
                                       && (Fr_CycleRepetition != 32U) && (Fr_CycleRepetition != 64U)
           )
    {
        /* Fr_CycleRepetition has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_CYCLE_U8);
    }
    else if(Fr_CycleOffset > (Fr_CycleRepetition - 1U))
    {
        /* Fr_CycleOffset has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_CYCLE_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if((Fr_FrameId <= (Fr_pCfgPtr + Fr_CtrlIdx)->LowLevelConfigSetPtr->gNumberOfStaticSlots) && (Fr_PayloadLength != (((Fr_pCfgPtr + Fr_CtrlIdx)->LowLevelConfigSetPtr->gPayloadLengthStatic )* 2U)))
    {    
        /* Fr_PayloadLength has an invalid value for static segment */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_LENGTH_U8);
    }
    else if(Fr_HeaderCRC > 2047U)
    {
        /* Fr_HeaderCRC has an invalid value for static segment */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECONFIGLPDU_U8, FR_E_INV_HEADERCRC_U8);
        
    }
    else
    {
        returnValue_37 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    }
    return returnValue_37;
}
#endif
#endif /* FR_RECONFIG_LPDU_SUPPORT */

#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/***************************************************************************************************
* @function_name    Fr_Dem_ReportErrorStatus
*
* @brief            Check and report Det error status.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
*                   u16StatusMask Status macro of DEM report.
***************************************************************************************************/
static FUNC(void, FR_CODE) Fr_Dem_ReportErrorStatus(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(Dem_EventStatusType, AUTOMATIC) u16StatusMask)
{
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;

    /* @violates @ref FR_C_REF_3 */
    if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
    {
        /* The Fr_BuffersInit() function detected error while accessing the CC */
        /* @violates @ref FR_C_REF_3 */
        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, u16StatusMask);
    }
}
#endif

#if(FR_DEV_ERROR_DETECT == STD_ON)
/* Only if FR_DEV_ERROR_DETECT is enabled: */
/***************************************************************************************************
* @function_name    Fr_ControllerInitDetReport
*
* @brief            Check and report Det error status.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           :Std_ReturnType
*                       - E_OK      API API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
***************************************************************************************************/
static FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInitDetReport (VAR(uint8, AUTOMATIC) Fr_CtrlIdx)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_CONTROLLERINIT_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
        returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);    /* API call aborted due to errors */
    }
    if((Fr_CtrlIdx >= Fr_u8CtrlNumber) && ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == returnValue_0))  /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_CONTROLLERINIT_U8, FR_E_INV_CTRL_IDX_U8);

        returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);    /* API call aborted due to errors */
    }
    return returnValue_0;
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define FR_START_SEC_CODE
/* Covers FR112 */
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

#if(FR_VERSION_INFO_API == STD_ON)
/***************************************************************************************************
* @function_name    Fr_GetVersionInfo
*
* @brief            Software module version query
* @details          [SWS_Fr_00341]: The function Fr_GetVersionInfo shall return the version information
*                   of this module
* @param[out]       VersioninfoPtr Std_VersionInfoType type pointer where to store version numbers
* @return           none
*
* @implements       Fr_GetVersionInfo_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, FR_APPL_DATA) VersioninfoPtr
)
{
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(NULL_PTR == VersioninfoPtr)
    {
        /* If VersioninfoPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_GETVERSIONINFO_U8,
                                                                                  FR_E_PARAM_POINTER);
    }
    else /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        VersioninfoPtr->moduleID = (VAR(uint16, AUTOMATIC))FR_MODULE_ID;
        VersioninfoPtr->vendorID = (VAR(uint16, AUTOMATIC))FR_VENDOR_ID;
        VersioninfoPtr->sw_major_version = (VAR(uint8, AUTOMATIC))FR_SW_MAJOR_VERSION;
        VersioninfoPtr->sw_minor_version = (VAR(uint8, AUTOMATIC))FR_SW_MINOR_VERSION;
        VersioninfoPtr->sw_patch_version = (VAR(uint8, AUTOMATIC))FR_SW_PATCH_VERSION;
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */

    return;         /* Exit from function */
}
#endif /* FR_VERSION_INFO_API == STD_ON */

/*************************************************************************************************/


/***************************************************************************************************
* @function_name    Fr_Init
*
* @brief            Controller initialization function
* @details          [SWS_Fr_00137]: The function Fr_Init shall internally store the configuration address 
*                   to enable subsequent API calls to access the configuration.
* @param[in]        Fr_ConfigPtr Pointer to the Controller configuration
* @return           none
*
* @implements       Fr_Init_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(void, FR_CODE) Fr_Init
(
    /* Compiler_Warning: Fr_ConfigPtr is used only in Post Build variant
       Compiler_Affected: CodeWarrior
       Warning: variable/argument Fr_ConfigPtr is not used in function
    */
    P2CONST(Fr_ConfigType, AUTOMATIC, FR_APPL_CONST) Fr_ConfigPtr
)
{
#if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Check state of Fr_eDriverStates */
    if (FR_UNINIT == Fr_eDriverStates)
    {
#endif /* FR_DEV_ERROR_DETECT */
    #if(FR_DEV_ERROR_DETECT == STD_ON)
        #if(FR_VARIANT_PRECOMPILE == STD_OFF)
        if(NULL_PTR == Fr_ConfigPtr)
        #else
        if(NULL_PTR != Fr_ConfigPtr)
        #endif /* FR_VARIANT_PRECOMPILE */
        {
            /* Only if FR_DEV_ERROR_DETECT is enabled: */
            /* If Fr_ConfigPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
            /* to the DET and the API function shall return. */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_INIT_U8, FR_E_PARAM_POINTER);
        }
        else
        {
    #endif /* FR_DEV_ERROR_DETECT */

    #if(FR_VARIANT_PRECOMPILE == STD_OFF)
            /* Internally store the configuration data address to enable subsequent API calls to access
            configuration data */
            Fr_pCfgPtr = (P2CONST(Fr_ConfigurationType, AUTOMATIC, FR_APPL_CONST))(Fr_ConfigPtr);
    #else /* Variant Pre-Compile */
            Fr_pCfgPtr = Fr_PBCfgVariantPredefined;
    #endif /* FR_VARIANT_PRECOMPILE */

    #if(FR_DEV_ERROR_DETECT == STD_ON)
            /* Find number of configured controllers */
            Fr_u8CtrlNumber = 0U;
            /* @violates @ref FR_C_REF_3 */
            while((NULL_PTR != (Fr_pCfgPtr + Fr_u8CtrlNumber)->CCHardwareConfigPtr) && (Fr_u8CtrlNumber < FR_NUM_CTRL_SUPPORTED))
            {
                /* Store timers availability information */
                /* Check whether the timer 2 can be configured as an absolute timer */
                /* @violates @ref FR_C_REF_3 */
                if((VAR(boolean, AUTOMATIC))TRUE == (Fr_pCfgPtr + Fr_u8CtrlNumber)->CCHardwareConfigPtr->EnableSecondaryAbsTimer)
                {
                    /* Timer 2 can be configured as an absolute timer -> Fr_AbsTimerIdx = 1 */
                    Fr_au8AbsoluteTimersNum[Fr_u8CtrlNumber] = 2U;    /* Two absolute timers are configured */
                    /* Check whether at least the timer 1 can be configured as an absolute timer */
                }
                else
                {
                    /* Timer 1 can be configured as an absolute timer -> Fr_AbsTimerIdx = 0 */
                    Fr_au8AbsoluteTimersNum[Fr_u8CtrlNumber] = 1U;    /* One absolute timer is configured */
                }
                Fr_u8CtrlNumber++; /* Increase number of controllers */
            }
            /* Successful initialization done
            - store for other API functions to check for proper module initialization */
            Fr_eDriverStates = FR_INIT;
        }
    #endif /* FR_DEV_ERROR_DETECT */
#if(FR_DEV_ERROR_DETECT == STD_ON)
  #ifdef SUPPORT_IP_V9
    }
    else
    {
    #if (STD_ON == FR_INIT_ERROR_NOTIFICATION_EN)
        /* Initialization error report */
        FR_INIT_ERROR_NOTIFICATION();
    #endif /* FR_INIT_ERROR_NOTIFICATION_EN */
    }
  #endif /* SUPPORT_IP_V9 */
  #if(FR_DEINIT_API == STD_ON)
    }
    else
    {
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_INIT_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
  #endif /* FR_DEINIT_API */
#endif /* FR_DEV_ERROR_DETECT */
}
/***************************************************************************************************
* @function_name    Fr_ControllerInit
*
* @brief            CC configuration
* @details          [SWS_Fr_00148]: Switch CC into POC:Config, configures all FlexRay
*                   cluster and node configuration parameters, configures all
*                   transmit or receive resources and switch CC into POC:Ready
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           :Std_ReturnType
*                       - E_OK      API API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_ControllerInit_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInit
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
    #if(FR_CTRL_TEST_COUNT > 0U)
    VAR(uint8, AUTOMATIC) u8i_0;
    #endif

#if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    returnValue_0 = Fr_ControllerInitDetReport(Fr_CtrlIdx);
    if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == returnValue_0)
    {
#endif /* FR_DEV_ERROR_DETECT */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(FALSE)))
        {/* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                Fr_Dem_ReportErrorStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
            #endif
            returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
        }
        else
        {
            /* This controller is activated */
            Fr_bCCActive[Fr_CtrlIdx] = (VAR(boolean, AUTOMATIC))TRUE;
            /* Initilize FlexRay CC */
            if((VAR(boolean, FR_VAR))TRUE == Fr_bModuleEnablePermission)
            {
                /* Ban permission for FR module enable */
                Fr_bModuleEnablePermission = (VAR(boolean, FR_VAR))FALSE;
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CCInit(Fr_CtrlIdx))
                {
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_Dem_ReportErrorStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
    
                    returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);    /* API call aborted due to errors */
                }
            }
            
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == returnValue_0)
            {
                /* Switch controller into POC:Config state */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_EnterPOCConfigState(Fr_CtrlIdx))
                {
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_Dem_ReportErrorStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
        
                    returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);    /* API call aborted due to errors */
                }
            }
            
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == returnValue_0)
            {
                /* Configure all FlexRay cluster and node configuration parameters */
                Fr_Ipw_ClusterNodeParamCfg(Fr_CtrlIdx);
        
                /* Configure all transmit/receive resources */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_BuffersInit(Fr_CtrlIdx))
                {
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_Dem_ReportErrorStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
        
                    returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                }
            }
            
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == returnValue_0)
            {
                /* Disable all timers - already done by transition to POC:Halt */
                Fr_Ipw_DisableTimers(Fr_CtrlIdx);
        
                /* Switch controller into POC:Ready */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_LeavePOCConfigState(Fr_CtrlIdx))
                {
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        Fr_Dem_ReportErrorStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                    #endif
        
                    returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                }
            }
        
            #if(FR_CTRL_TEST_COUNT > 0U)
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == returnValue_0)
            {
                /* CC Configuration Test */
                for(u8i_0 = 0U; u8i_0 < FR_CTRL_TEST_COUNT; u8i_0++)
                {
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_ReadbackCCConfig(Fr_CtrlIdx))
                    {    
                        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            Fr_Dem_ReportErrorStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_FAILED);
                        #endif
                        returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                        break;
                    }
                }
            }
            #endif
            
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == returnValue_0)
            {
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    Fr_Dem_ReportErrorStatus(Fr_CtrlIdx, DEM_EVENT_STATUS_PASSED);
                #endif
            
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_ClearDisableIRQs(Fr_CtrlIdx))
                {
                    returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                }
            #ifdef SUPPORT_IP_V9
                #ifdef FR_ACCESS_ERROR_NOTIFICATION_EN
                else
                {
                    /* Init access error intrrupt */
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_EnableErrorIRQs(Fr_CtrlIdx))
                    {
                        returnValue_0 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                    }
                }
                #endif /* FR_ACCESS_ERROR_NOTIFICATION_EN */
            #endif /* SUPPORT_IP_V9 */
            }
        }
#if(FR_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* FR_DEV_ERROR_DETECT */
    return returnValue_0;
}

/***************************************************************************************************
* @function_name    Fr_StartCommunication
*
* @brief            Starts the communication
* @details          [SWS_Fr_00177]: Invoke the CC CHI command RUN, which initiates the startup
*                   procedure within the FlexRay CC
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_StartCommunication_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_StartCommunication
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_3 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
        
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    VAR(uint16, AUTOMATIC) u16tmpPOCState_3;
    
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        /* Determine the POC state */
        u16tmpPOCState_3 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
        /* Check whether the CC is in the POC:ready */
        if(FLEXRAY_PSR0_PROTSTATE_READY_U16 != u16tmpPOCState_3)
        {   /* The CC is not in the POC:ready */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_STARTCOMMUNICATION_U8, FR_E_INV_POCSTATE_U8);
        }
    #else  /* FR_DEV_ERROR_DETECT == STD_OFF */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
    #endif /* FR_DEV_ERROR_DETECT */         
        /* No error yet -> execute the following code */
        else
        {   /* The CC is in the POC:ready */
            /* Invoke CHI command RUN */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_CtrlIdx, FLEXRAY_POCR_CMD_RUN_U16))
            {
                /* API call was successful */
                returnValue_3 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); 
            }
            else
            {
                /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */

    return returnValue_3;        /* Return the state of function execution */
} /* End of Fr_StartCommunication */

/***************************************************************************************************
* @function_name    Fr_AllowColdstart
*
* @brief            Invokes the CC CHI command ALLOW_COLDSTART
* @details          [SWS_Fr_00182]: Invokes the CC CHI command ALLOW_COLDSTART
*
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
*
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
*
* @implements       Fr_AllowColdstart_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_AllowColdstart
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_35 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    VAR(uint16, AUTOMATIC) u16tmpPOCState_35;
    
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLOWCOLDSTART_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);  /* Report error */
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLOWCOLDSTART_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        /* Determine the POC state */ 
        u16tmpPOCState_35 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);        
        /* Check whether the CC is not in POC:default config, POC:config or POC:halt */
        if((FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16 == u16tmpPOCState_35) || (FLEXRAY_PSR0_PROTSTATE_CONFIG_U16 == u16tmpPOCState_35) || (FLEXRAY_PSR0_PROTSTATE_HALT_U16 == u16tmpPOCState_35))
        {
            /* The CC is in POC:default config or POC:config or POC:halt */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLOWCOLDSTART_U8, FR_E_INV_POCSTATE_U8);
        }
    #else   /* FR_DEV_ERROR_DETECT == STD_OFF */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
    #endif  /* FR_DEV_ERROR_DETECT */    
        else  /* CC is in required state */
        {
            /* Invoke CHI command ALLOW_COLDSTART and wait till Protocol Command Write is not busy*/
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_CtrlIdx, FLEXRAY_POCR_CMDALLOWCOLDSTART_U16))
            {
                /* API call was successful */
                returnValue_35 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); 
            }
            else
            {
                /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
    
    return returnValue_35;        /* Return the state of function execution */
} /* End of Fr_AllowColdStart */

/***************************************************************************************************
* @function_name    Fr_AllSlots
*
* @brief            Invokes the CC CHI command ALL_SLOTS
* @details          [SWS_Fr_00518]: Invoke the CC CHI command ALL_SLOTS, which requests a switch from 
*                   key slot only mode to all slots transmission mode at the beginning of the next 
*                   communication cycle.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
*
* @implements       Fr_AllSlots_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_AllSlots
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_36 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    VAR(uint16, AUTOMATIC) u16tmpPOCState_36;
    
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLSLOTS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLSLOTS_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }    
    else
    {
        /* Determine the POC state */
        u16tmpPOCState_36 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
        /* The state of the PSR0 register (PROSTATE field) is not updated if FREEZE occurred */
        /* Check whether the CC is synchronous to cluster */
        if((FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16 != u16tmpPOCState_36) && (FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16 != u16tmpPOCState_36))
        {
            /* The CC is in POC:default config or POC:config or POC:halt */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ALLSLOTS_U8, FR_E_INV_POCSTATE_U8);
        }
    #else  /* FR_DEV_ERROR_DETECT == STD_OFF */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
    #endif  /* FR_DEV_ERROR_DETECT */
        /* No error yet -> execute the following code */
        else
        {
            /* Invoke CHI command ALL_SLOTS */ 
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_CtrlIdx, FLEXRAY_POCR_CMD_ALL_SLOTS_U16))
            {             
                /* API call was successful */
                returnValue_36 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            else
            {
                /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
    
    return returnValue_36;        /* Return the state of function execution */
} /* End of Fr_AllSlots */

/***************************************************************************************************
* @function_name    Fr_HaltCommunication
*
* @brief            This API call stops communication.
* @details          [SWS_Fr_00187]: Invokes the CC CHI command HALT, which requests to halt the
*                   communication at the end of the current FlexRay communication cycle
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call in bad POC state or failure in access to the controller
*
* @implements       Fr_HaltCommunication_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_HaltCommunication
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_4 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    VAR(uint16, AUTOMATIC) u16tmpPOCState_4;
    
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_HALTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_HALTCOMMUNICATION_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        /* Determine the POC state */ 
        u16tmpPOCState_4 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
        
        /* Check whether the CC is synchronous to cluster */
        if((FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16 != u16tmpPOCState_4) && (FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16 != u16tmpPOCState_4))
        {/* The CC is not synchronized to the FlexRay global time */
                /* If CC is not synchronized to the FlexRay global time,
                FR_E_INV_POCSTATE_U8 shall be reported */
                /* to the DET and the API function shall return. */
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_HALTCOMMUNICATION_U8, FR_E_INV_POCSTATE_U8);
        }
    #else /* FR_DEV_ERROR_DETECT == STD_OFF */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
    #endif /* FR_DEV_ERROR_DETECT */
        /* No error yet -> execute the following code */
        else
        {/* The CC is synchronized to the FlexRay global time */
            /* Invoke CHI command HALT */                                  
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_CtrlIdx, FLEXRAY_POCR_CMD_HALT_U16))
            {
                /* API call was successful */
                returnValue_4 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);     
            }
            else
            {
                /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */

    return returnValue_4;        /* Return the state of function execution */
} /* End of Fr_HaltCommunication */

/***************************************************************************************************
* @function_name    Fr_AbortCommunication
*
* @brief            Abort the communication
* @details          [SWS_Fr_00191]: Invoke the CHI command FREEZE, which immediately
*                   aborts the communication and force the CC to the POC:Halt
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_AbortCommunication_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_AbortCommunication
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_5 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ABORTCOMMUNICATION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ABORTCOMMUNICATION_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else    /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
        #ifdef ERR_IPV_FLEXRAY_0002
            #if(ERR_IPV_FLEXRAY_0002 == STD_ON)
            /* Invoke CHI command HATL */                                  
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_CtrlIdx, FR_POCR_CMD_HALT_U16))
            #else
                #error : the define ERR_IPV_FLEXRAY_0002 must not be STD_OFF
            #endif
        #else
            /* Invoke CHI command FREEZE */                                  
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_CtrlIdx, FLEXRAY_POCR_CMD_FREEZE_U16))
        #endif /* ERR_IPV_FLEXRAY_0002 */
            {
                /* API call was successful */
                returnValue_5 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            else
            {
                /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
     
    return returnValue_5;        /* Return the state of function execution */
} /* End of Fr_AbortCommunication */

/***************************************************************************************************
* @function_name    Fr_SendWUP
*
* @brief            Initiates transition to POC:Wakeup
* @details          [SWS_Fr_00196]: Invoke the CC CHI command WAKEUP, which initiates the Wakeup Symbol
*                   transmission procedure on the configured FlexRay channel
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_SendWUP_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_SendWUP
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_6 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    VAR(uint16, AUTOMATIC) u16tmpPOCState_6;
    
    if(FR_INIT != Fr_eDriverStates)  /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SENDWUP_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SENDWUP_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {            
        /* Determine the POC state */
        u16tmpPOCState_6 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
        /* The state of the PSR0 register (PROSTATE field) is not updated if FREEZE occurred */
        /* Check whether the CC is in POC:ready */
        if(FLEXRAY_PSR0_PROTSTATE_READY_U16 != u16tmpPOCState_6)
        {   /* The CC is not in POC:ready */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SENDWUP_U8, FR_E_INV_POCSTATE_U8);
        }
    #else /* FR_DEV_ERROR_DETECT == STD_OFF */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
    #endif /* FR_DEV_ERROR_DETECT */
        /* No error yet -> execute the following code */
        else
        {
            /* Invoke CHI command WAKEUP */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_CtrlIdx, FLEXRAY_POCR_CMD_WAKEUP_U16))
            {
                /* API call was successful */
                returnValue_6 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            else
            {
                /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_6;        /* Return the state of function execution */
} /* End of Fr_SendWUP */

/***************************************************************************************************
* @function_name    Fr_SetWakeupChannel
*
* @brief            Selects which channel sends WUPs
* @details          [SWS_Fr_00202]: Change the CCs POCState to POC:Config by invoking the CHI command
*                   CONFIG, configure the wakeup channel according to parameter Fr_ChnlIdx and
*                   change the CCs POCState to POC:Ready again by invoking the CHI command
*                   CONFIG_COMPLETE
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_ChnlIdx Index of FlexRay channel within the context of the FlexRay CC
*                   Fr_CtrlIdx
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_SetWakeupChannel_Activity 
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_SetWakeupChannel
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(Fr_ChannelType, AUTOMATIC) Fr_ChnlIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_7 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    VAR(uint16, AUTOMATIC) u16tmpPOCState_7;
    
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        /* Report the error */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if((FR_CHANNEL_A != Fr_ChnlIdx) && (FR_CHANNEL_B != Fr_ChnlIdx))
    {
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, FR_E_INV_CHNL_IDX_U8);
    }
    else if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        
        /* Determine the POC state */
        u16tmpPOCState_7 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
        /* Check whether the CC is in POC:ready */
        if(FLEXRAY_PSR0_PROTSTATE_READY_U16 != u16tmpPOCState_7)
        {   /* The CC is not in POC:ready */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETWAKEUPCHANNEL_U8, FR_E_INV_POCSTATE_U8);
        }
    #else /* FR_DEV_ERROR_DETECT == STD_OFF */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
    #endif /* FR_DEV_ERROR_DETECT */    
        /* No error yet -> execute the following code */
        else
        {
            /* Call LLD function to set the Wakeup channel */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_SetWakeupChannel(Fr_CtrlIdx, Fr_ChnlIdx))
            {
                returnValue_7 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            else
            {
                /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
                /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }                   /* End of No error section */
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_7;        /* Return the state of function execution */
} /* End of Fr_SetWakeupChannel */

/***************************************************************************************************
* @function_name    Fr_GetPOCStatus
*
* @brief            Query for the controller status
* @details          Query the CCs actual POC status by reading the CHI variable vPOC
*                   and write the result to parameter Fr_POCStatusPtr.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_POCStatusPtr Address the output value is stored to
* @return           :Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetPOCStatus_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetPOCStatus
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) Fr_POCStatusPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_10 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETPOCSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber)              /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETPOCSTATUS_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(NULL_PTR == Fr_POCStatusPtr)
    {
        /* If Fr_SyncStatePtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETPOCSTATUS_U8, FR_E_PARAM_POINTER);
    }
    else /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
            returnValue_10 = Fr_Ipw_GetPOCStatus(Fr_CtrlIdx, Fr_POCStatusPtr);
            
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* HW issue detected, Report error */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == returnValue_10)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
            }
            #endif
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */

    return returnValue_10;        /* Return the state of function execution */
} /* End of Fr_GetPOCStatus */

/***************************************************************************************************
* @function_name    Fr_GetGlobalTime
*
* @brief            Function gets FlexRay cluster global time
* @details          [SWS_Fr_00256]: Read the current global FlexRay time and writes it to
*                   the output parameters Fr_cyclePtr and Fr_MacrotickPtr
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_CyclePtr Address where the current FlexRay communication cycle value
*                   shall be stored
* @param[out]       Fr_MacroTickPtr Address where the current macrotick value shall be stored
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetGlobalTime_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_CyclePtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_MacroTickPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_16 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16tmpPOCState_16;
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(NULL_PTR == Fr_CyclePtr)
    {
        /* If Fr_CyclePtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, FR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == Fr_MacroTickPtr)
    {
        /* If Fr_MacroTickPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETGLOBALTIME_U8, FR_E_PARAM_POINTER);
    }
    else  /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {

            /* Determine the POC state */   
            u16tmpPOCState_16 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
            /* The state of the PSR0 register (PROSTATE field) is not updated if FREEZE occurred */
            /* Check whether the CC is synchronous to cluster */
            if((FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16 == u16tmpPOCState_16) || (FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16 == u16tmpPOCState_16))
            {/* The CC is synchronized to the FlexRay global time */
                /* Call LLD function to get Cycle and Macrotick */
                returnValue_16 = Fr_Ipw_GetGlobalTime(Fr_CtrlIdx, Fr_CyclePtr, Fr_MacroTickPtr);
                
                /* HW issue detected, Report error */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == returnValue_16)
                    {
                        /* @violates @ref FR_C_REF_3 */
                        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                    }
                }
                #endif
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */

    return returnValue_16;        /* Return the state of function execution */
} /* End of Fr_GetGlobalTime */

/***************************************************************************************************
* @function_name    Fr_SetAbsoluteTimer
*
* @brief            Sets the absolute FlexRay timer
* @details          [SWS_Fr_00273]: Program the absolute FlexRay timer Fr_AbsTimerIdx according to the
*                   parameters Fr_Cycle and Fr_Offset
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx Index of absolute timer within the context of the FlexRay CC
* @param[in]        Fr_Cycle Absolute cycle the timer shall elapse in
* @param[in]        Fr_Offset Offset within cycle Fr_Cycle in units of macrotick the timer shall
*                   elapse at
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_SetAbsoluteTimer_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_SetAbsoluteTimer
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx,
    VAR(uint8, AUTOMATIC) Fr_Cycle,
    VAR(uint16, AUTOMATIC) Fr_Offset
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_17 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    VAR(uint16, AUTOMATIC) u16tmpPOCState_17;
    
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber)       /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) /* Check the Fr_AbsTimerIdx value */
    {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, FR_E_INV_TIMER_IDX_U8);
    }
    else if(Fr_Cycle > 63U) /* Check the Fr_Cycle value, max. cycle no. 63 */
    {   /* An attempt to configure timer for invalid cycle number, Fr_Cycle has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, FR_E_INV_CYCLE_U8);
    }
    /* Compare Fr_Offset value with maximum gMacroPerCycle from configuration, 
       the absolute timer shall elapsed at */
    /* @violates @ref FR_C_REF_3 */
    else if(Fr_Offset >= (((VAR(uint16, AUTOMATIC))((Fr_pCfgPtr + Fr_CtrlIdx)->LowLevelConfigSetPtr->RegPCR10_11 >> 16U)) & 0x3FFFU))
    {   /* An attempt to configure timer for invalid macrotick offset number,
          Fr_Offset has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, FR_E_INV_OFFSET_U8);
    }
    else if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        /* Determine the POC state */ 
        u16tmpPOCState_17 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
        /* Check whether the CC is synchronous to cluster */
        if((FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16 != u16tmpPOCState_17) && (FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16 != u16tmpPOCState_17))
        {   /* The CC is not synchronized to the cluster */
            (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_SETABSTIMER_U8, FR_E_INV_POCSTATE_U8);
        }
    #else /* FR_DEV_ERROR_DETECT == STD_OFF */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
    #endif /* FR_DEV_ERROR_DETECT */
        /* No error yet -> execute the following code */
        else          
        {   /* The CC is synchronized to the cluster */
            /* Call LLD function to set the Absolute Timer */
            Fr_Ipw_SetAbsoluteTimer(Fr_CtrlIdx, Fr_AbsTimerIdx, Fr_Cycle, Fr_Offset);
            /* API call was successful */
            returnValue_17 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);    
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT == STD_ON */
    
    return returnValue_17;    /* Return the state of function execution */       
}/* End of Fr_SetAbsoluteTimer */

/***************************************************************************************************
* @function_name    Fr_CancelAbsoluteTimer
*
* @brief            Stops an absolute timer
* @details          [SWS_Fr_00287]: Stop the absolute timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx Index of absolute timer within the context of the FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_CancelAbsoluteTimer_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_CancelAbsoluteTimer
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_19 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELABSTIMER_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC,Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELABSTIMER_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) /* Check the Fr_AbsTimerIdx value */
    {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELABSTIMER_U8, FR_E_INV_TIMER_IDX_U8);
    }
    else    /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {   /* Call LLD function to cancel the Absolute Timer */
        Fr_Ipw_CancelAbsoluteTimer(Fr_CtrlIdx, Fr_AbsTimerIdx);
        returnValue_19 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);    /* API call was successful */
    } /* CC access check */
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_19;    /* Return the state of function execution */
}/* End of Fr_CancelAbsoluteTimer */

/***************************************************************************************************
* @function_name    Fr_EnableAbsoluteTimerIRQ
*
* @brief            Enables absolute timer interrupts
* @details          [SWS_Fr_00298]: Enable the interrupt line related to timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx      Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx  Index of absolute timer within the context of the FlexRay C
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_EnableAbsoluteTimerIRQ_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_EnableAbsoluteTimerIRQ
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    
    VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_21 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)      /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ENABLEABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber)                 /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ENABLEABSTIMERIRQ_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx]))/* Check the Fr_AbsTimerIdx value */
    {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ENABLEABSTIMERIRQ_U8, FR_E_INV_TIMER_IDX_U8);
    }
    else    /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        /* Call LLD function to enable the Absolute Timer */
        Fr_Ipw_EnableAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_AbsTimerIdx);
        returnValue_21 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);    /* API call was successful */
    }  /* CC access check */
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_21;    /* Return the state of function execution */
}/* End of Fr_EnableAbsoluteTimerIRQ */

/***************************************************************************************************
* @function_name    Fr_AckAbsoluteTimerIRQ
*
* @brief            Clears absolute timer interrupt flag
* @details          [SWS_Fr_00309]: Reset the interrupt condition of absolute timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx Index of absolute timer within the context of the FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_AckAbsoluteTimerIRQ_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_AckAbsoluteTimerIRQ
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_23 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ACKABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ACKABSTIMERIRQ_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) /* Check the Fr_AbsTimerIdx value */
    {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_ACKABSTIMERIRQ_U8, FR_E_INV_TIMER_IDX_U8);
    }
    else  /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        /* Call LLD function to ack the Absolute Timer */
        Fr_Ipw_AckAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_AbsTimerIdx);
        
        returnValue_23 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);   /* API call was successful */
    } /* CC access check */
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_23;        /* Return the state of function execution */
}/* End of Fr_AckAbsoluteTimerIRQ */

/***************************************************************************************************
* @function_name    Fr_DisableAbsoluteTimerIRQ
*
* @brief            Disables absolute timer interrupt generation
* @details          [SWS_Fr_00320]: Disable the interrupt line related to absolute timer Fr_AbsTimerIdx
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx - Index of absolute timer within the context of the FlexRay CC
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_DisableAbsoluteTimerIRQ_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_DisableAbsoluteTimerIRQ
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_25 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLEABSTIMERIRQ_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLEABSTIMERIRQ_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) /* Check the Fr_AbsTimerIdx value */
    {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLEABSTIMERIRQ_U8, FR_E_INV_TIMER_IDX_U8);
    }
    else    /* No error yet -> execute the following code */
    { 
    #endif /* FR_DEV_ERROR_DETECT */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        /* Call LLD function to disable the Absolute Timer */
        Fr_Ipw_DisableAbsoluteTimerIRQ(Fr_CtrlIdx, Fr_AbsTimerIdx);
        
        returnValue_25 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); /* API call was successful */
    } /* CC access check */
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */

    return returnValue_25;        /* Return the state of function execution */
} /* End of Fr_DisableAbsoluteTimerIRQ */

/***************************************************************************************************
* @function_name    Fr_GetAbsoluteTimerIRQStatus
*
* @brief            Checks if the absolute timer flag is set
* @details          [SWS_Fr_00332]: Check whether the interrupt of absolute timer Fr_AbsTimerIdx
*                   is pending.
*                   Writes (VAR(boolean, AUTOMATIC))TRUE to output parameter Fr_IRQStatusPtr in case
*                   the interrupt is pending, (VAR(boolean, AUTOMATIC))FALSE otherwise
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_AbsTimerIdx - Index of absolute timer within the context of the FlexRay CC
* @param[out]       Fr_IRQStatusPtr - Address the output value is stored to
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetAbsoluteTimerIRQStatus_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetAbsoluteTimerIRQStatus
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx,
    P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) Fr_IRQStatusPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_32 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(!(Fr_AbsTimerIdx < Fr_au8AbsoluteTimersNum[Fr_CtrlIdx])) /* Check the Fr_AbsTimerIdx value */
    {   /* An attempt to configure an invalid timer, Fr_AbsTimerIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, FR_E_INV_TIMER_IDX_U8);
    }
    else if(NULL_PTR == Fr_IRQStatusPtr)
    {
        /* If Fr_IRQStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETABSTIMERIRQSTATUS_U8, FR_E_PARAM_POINTER);
    }
    else    /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
    {
        /* CC is not accessible, report error */
        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        /* @violates @ref FR_C_REF_3 */
        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
        {
            /* @violates @ref FR_C_REF_3 */
            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
        }
        #endif
    }
    else
    {
        /* Call LLD function to get Asolute Timer IRQ status */
        *Fr_IRQStatusPtr = Fr_Ipw_GetAbsoluteTimerIRQStatus(Fr_CtrlIdx, Fr_AbsTimerIdx);
         
        returnValue_32 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK); /* API call was successful */

    } /* CC access check */
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_32;        /* Return the state of function execution */
} /* End of Fr_GetAbsoluteTimerIRQStatus */

/***************************************************************************************************
* @function_name    Fr_GetNmVector
*
* @brief            Read network management vector
* @details          [SWS_Fr_00262]: Read the network management vector of the last communication cycle
*                   and write it to the output parameter Fr_NmVectorPtr. The number of bytes
*                   written to the output parameter is constant and known at configuration time
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver
* @param[out]       Fr_NmVectorPtr - Address where the NmVector of the last communication cycle
*                   shall be stored
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetNmVector_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetNmVector
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NmVectorPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_34 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16tmpPOCState_34;
    VAR(boolean, AUTOMATIC) bhwErr;
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)    /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNMVECTOR_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber)   /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNMVECTOR_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(NULL_PTR == Fr_NmVectorPtr)
    {
        /* If Fr_NmVectorPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNMVECTOR_U8, FR_E_PARAM_POINTER);
    }
    else /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
            u16tmpPOCState_34 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
            /* Check whether the CC is synchronous to cluster */
            if((FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16 == u16tmpPOCState_34) || (FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16 == u16tmpPOCState_34))
            {/* The CC is in POC:Normal Active or POC:Normal Passive */
                /* Read Network Management Vector */ 
                /* @violates @ref FR_C_REF_6 */
                returnValue_34 = Fr_Ipw_GetNmVector(Fr_CtrlIdx, Fr_NmVectorPtr, &bhwErr);
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    if((VAR(boolean, AUTOMATIC))TRUE == bhwErr)
                    {
                        /* @violates @ref FR_C_REF_3 */
                        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                    }
                }
                #endif
            }
            else
            {
                /* The CC is not synchronous to the cluster */
                /* Set error return value */
                returnValue_34 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);    
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_34;        /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_GetChannelStatus
*
* @brief            Read channel status
* @details          [SWS_Fr_00558]: Read the aggregated channel status, NIT status, symbol window status 
*                   and write it to the output parameter Fr_ChannelAStatusPtr, Fr_ChannelBStatusPtr.
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver 
* @param[out]       Fr_ChannelAStatusPtr - Address where the bitcoded channel A status information
*                                          shall be stored.
*                   Fr_ChannelBStatusPtr - Address where the bitcoded channel B status information 
*                                          shall be stored.
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetChannelStatus_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetChannelStatus
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAStatusPtr, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBStatusPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_40 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16tmpPOCState_40;
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)    /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber)   /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(NULL_PTR == Fr_ChannelAStatusPtr)
    {
        /* If Fr_ChannelAStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, FR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == Fr_ChannelBStatusPtr)
    {
        /* If Fr_ChannelBStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCHANNELSTATUS_U8, FR_E_PARAM_POINTER);
    }
    else            /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
            
            u16tmpPOCState_40 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
            /* Check whether the CC is synchronous to cluster */
            if((FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16 == u16tmpPOCState_40) || (FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16 == u16tmpPOCState_40))
            {
                /* Read aggregated channel status, NIT staus and symbol window status */
                Fr_Ipw_GetChannelStatus(Fr_CtrlIdx, Fr_ChannelAStatusPtr, Fr_ChannelBStatusPtr);
                returnValue_40 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            else
            {
                returnValue_40 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_40; /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_GetClockCorrection
*
* @brief            Gets clock correction values
* @details          [SWS_Fr_00566]: Read the rate correction value (vInterimRateCorrection11) and write 
*                   it as signed integer to the output parameter Fr_RateCorrectionPtr. Read the 
*                   offset correction value (vInterimOffsetCorrection12) and write it as signed 
*                   integer to the output parameter Fr_OffsetCorrectionPtr
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver 
* @param[out]       Fr_RateCorrectionPtr - Address where the current rate correction value shall 
*                                          be stored.
*                   Fr_OffsetCorrectionPtr - Address where the current offset correction value 
*                                            shall be stored.
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetClockCorrection_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetClockCorrection
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx, 
    P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) Fr_RateCorrectionPtr, 
    P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) Fr_OffsetCorrectionPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_41 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)    /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber)   /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(NULL_PTR == Fr_RateCorrectionPtr)
    {
        /* If Fr_ChannelAStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, FR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == Fr_OffsetCorrectionPtr)
    {
        /* If Fr_ChannelBStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETCLOCKCORRECTION_U8, FR_E_PARAM_POINTER);
    }
    else            /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
    
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
            /* Read clock correction values */
            returnValue_41 = Fr_Ipw_GetClockCorrection(Fr_CtrlIdx, Fr_RateCorrectionPtr, Fr_OffsetCorrectionPtr);
            
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == returnValue_41)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
            }
            #endif
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_41; /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_GetSyncFrameList
*
* @brief            Gets clock correction values
* @details          [SWS_Fr_00575]: Read the list of syncframes received in the last even communication 
*                   cycle on channel A and write it as array to the memory location 
*                   Fr_ChannelAEvenListPtr. 
*                   Read the list of syncframes received in the last even communication cycle on 
*                   channel B and write it as array to the memory location Fr_ChannelBEvenListPtr. 
*                   Read the list of syncframes received in the last odd communication cycle on 
*                   channel A and write it as array to the memory location Fr_ChannelAOddListPtr. 
*                   Read the list of syncframes received in the last odd communication cycle on 
*                   channel B and write it as array to the memory location Fr_ChannelBOddListPtr.
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver.
*                   Fr_ListSize - Size of the arrays passed via parameters: 
*                                Fr_ChannelAEvenListPtr, Fr_ChannelBEvenListPtr,
*                                Fr_ChannelAOddListPtr Fr_ChannelBOddListPtr. 
* @param[out]       Fr_ChannelAEvenListPtr - Address the list of syncframes on channel A within the
*                                            even communication cycle is written to.
*                   Fr_ChannelBEvenListPtr - Address the list of syncframes on channel B within the 
*                                            even communication cycle is written to.
*                   Fr_ChannelAOddListPtr - Address the list of syncframes on channel A within the 
*                                            odd communication cycle is written to.
*                   Fr_ChannelBOddListPtr - Address the list of syncframes on channel B within the 
*                                           odd communication cycle is written to.
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors or Fr_ListSize=0
*
* @implements       Fr_GetSyncFrameList_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetSyncFrameList
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint8, AUTOMATIC) Fr_ListSize, 
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBEvenListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAOddListPtr,
    P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBOddListPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_42 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)    /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber)   /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(Fr_ListSize > 15U)
    {   /* Fr_ListSize is larger than 15, FR_E_INV_FRAMELIST_SIZE shall be reported */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_INV_FRAMELIST_SIZE);
    }
    else if(NULL_PTR == Fr_ChannelAEvenListPtr)
    {
        /* If Fr_ChannelAEvenListPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == Fr_ChannelBEvenListPtr)
    {
        /* If Fr_ChannelBEvenListPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_PARAM_POINTER);
    } 
    else if(NULL_PTR == Fr_ChannelAOddListPtr)
    {
        /* If Fr_ChannelAOddListPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_PARAM_POINTER);
    }
    else if(NULL_PTR == Fr_ChannelBOddListPtr)
    {
        /* If Fr_ChannelBOddListPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETSYNCFRAMELIST_U8, FR_E_PARAM_POINTER);
    }
    else            /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
            /* Check Fr_ListSize parameter is higher than 0 */
            if(Fr_ListSize > 0U)
            {
                /* Get list of Sync frames */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_GetSyncFrameList(Fr_CtrlIdx, Fr_ListSize, Fr_ChannelAEvenListPtr, Fr_ChannelBEvenListPtr, Fr_ChannelAOddListPtr, Fr_ChannelBOddListPtr))
                {
                    returnValue_42 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                }
                else
                {
                    /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    /* @violates @ref FR_C_REF_3 */
                    if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                    {
                        /* @violates @ref FR_C_REF_3 */
                        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                    }
                    #endif
                    /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                }
            }
            else
            {
                /* do nothing */
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_42; /* Return the state of function execution */            
}

/***************************************************************************************************
* @function_name    Fr_GetWakeupRxStatus
*
* @brief            Gets clock correction values
* @details          [SWS_Fr_00588]: Read the wakeup pattern received indicators for channel A and channel 
*                   B and write it to the output parameter Fr_WakeupRxStatusPtr.
* @param[in]        Fr_CtrlIdx - Index of FlexRay CC within the context of the FlexRay Driver.
* 
* @param[out]       Fr_WakeupRxStatusPtr - Address where bitcoded wakeup reception status shall be 
*                                          stored.                        
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetWakeupRxStatus_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetWakeupRxStatus
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx, 
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_WakeupRxStatusPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_43 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)    /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETWAKEUPRXSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber)   /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETWAKEUPRXSTATUS_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(NULL_PTR == Fr_WakeupRxStatusPtr)
    {
        /* If Fr_ChannelAStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETWAKEUPRXSTATUS_U8, FR_E_PARAM_POINTER);
    }
    else            /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))TRUE))
        {
            /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_GetWakeupRxStatus(Fr_CtrlIdx, Fr_WakeupRxStatusPtr))
            {
                returnValue_43 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
            else
            {/* Hardware error flags were not cleared */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_43;
}

/***************************************************************************************************
* @function_name    Fr_TransmitTxLPdu
*
* @brief            Update selected message buffer with new data
* @details          [SWS_Fr_00224]: Figures out the physical resource mapped to the transmission
*                   of the FlexRay frame identified by Fr_LPduIdx, copies Fr_LSduLength
*                   bytes from address Fr_LSduPtr into the FlexRay  CCs transmission resource
*                   and activate it for transmission
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx The index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_LSduPtr Pointer to a buffer where the assembled LSdu to be transmitted
*                   within this LPdu is stored at
* @param[in]        Fr_LSduLength Determines the length of the data (in Bytes) to be transmitted
* @return           ::Std_ReturnType
*                       - E_OK      API call has been successful
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_TransmitTxLPdu_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint16, AUTOMATIC) Fr_LPduIdx,
    P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_LSduPtr,
    VAR(uint8, AUTOMATIC) Fr_LSduLength
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_11 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Pointer to one instance of Fr_CCTxBufferConfigType */
    P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST) ptxCfgDetPtr_11;
    
    VAR(boolean, AUTOMATIC) berrorOccured_11 = (VAR(boolean, AUTOMATIC))FALSE;
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED); /* Report error */
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, FR_E_INV_CTRL_IDX_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if(Fr_LPduIdx > (((Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->BuffersConfiguredCount) - 1U))
    {
        /* Fr_LPduIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, FR_E_INV_LPDU_IDX_U8);
    }
    else if(Fr_LSduPtr == NULL_PTR)
    {
        /* If Fr_LSduPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_TRANSMITTXLPDU_U8, FR_E_PARAM_POINTER);
    }
    else    /* 1st phase; No error yet -> execute the following code */
    {
        /* Store the reference to transmit buffer configuration */
        /* @violates @ref FR_C_REF_3 */
        ptxCfgDetPtr_11 = (P2CONST(Fr_CCTxBufferConfigType, AUTOMATIC, FR_APPL_CONST))((Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].BufferConfigPtr);
        
        /* Check whether the Fr_LSduLength has valid value; transformation from Bytes to Words
           has to be done */
        /* Check whether the MB is configured for dynamic/static segment of communication cycle and
           check whether the required data payload length is not greater than maximal data length
           in dynamic/static segment */
        /* @violates @ref FR_C_REF_3 */
        if(ptxCfgDetPtr_11->TxFrameID > (Fr_pCfgPtr + Fr_CtrlIdx)->LowLevelConfigSetPtr->gNumberOfStaticSlots)
        {/* Buffer configured for the dynamic segment */
            /* @violates @ref FR_C_REF_3 */
            if(Fr_LSduLength > (((Fr_pCfgPtr + Fr_CtrlIdx)->LowLevelConfigSetPtr->pPayloadLengthDynMax) * 2U))
            {
                /* Fr_LSduLength has an invalid value */
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, FR_E_INV_LENGTH_U8);
                /* indicate error */
                berrorOccured_11 = (VAR(boolean, AUTOMATIC))TRUE;
            }
        }
        else
        {/* Static segment */
            /* @violates @ref FR_C_REF_3 */
            if(Fr_LSduLength > (((Fr_pCfgPtr + Fr_CtrlIdx)->LowLevelConfigSetPtr->gPayloadLengthStatic) * 2U))
            {
                /* Fr_LSduLength has an invalid value */
                (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_TRANSMITTXLPDU_U8, FR_E_INV_LENGTH_U8);
                /* indicate error */
                berrorOccured_11 = (VAR(boolean, AUTOMATIC))TRUE;
            }
        }
        
        if(!((VAR(boolean, FR_VAR))TRUE == berrorOccured_11))    /* Check if some error occured */
        {    /* 2nd phase; No error yet -> execute the following code */
    #endif  /* FR_DEV_ERROR_DETECT == STD_ON */
            /* @violates @ref FR_C_REF_3 */
            if(FR_TRANSMIT_BUFFER == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].BufferType)
            {
                #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
                /* [SWS_Fr_00440]: Only if FR_PREPARE_LPDU_SUPPORT is enabled: */
                /* Check whether a transmit buffer is correctly configured to match the properties
                   of virtual one */
                /* @violates @ref FR_C_REF_3 */
                if(Fr_VirtualResourceAllocation[Fr_CtrlIdx][(Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].MessageBufferNumber] == Fr_LPduIdx)
                {      /* Yes, transmit buffer is correctly configured -> execute the following code */
                #endif /* FR_PREPARE_LPDU_SUPPORT */
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
                    {   /* CC is not accessible, report error */
                        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        /* @violates @ref FR_C_REF_3 */
                        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                        {
                            /* @violates @ref FR_C_REF_3 */
                            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                    else
                    {
                        /* Temporary offset address of MB configuration registers */
                        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_TransmitTxLPdu(Fr_CtrlIdx, Fr_LPduIdx, Fr_LSduPtr, Fr_LSduLength))
                        {
                            returnValue_11 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                        }
                        else
                        {
                            /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON -> return E_NOT_OK */
                            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                            /* @violates @ref FR_C_REF_3 */
                            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                            {
                                /* @violates @ref FR_C_REF_3 */
                                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                            }
                            #endif
                        }
                    } /* Fr_check_CC_access */
                /* [SWS_Fr_00440]: Only if FR_PREPARE_LPDU_SUPPORT is enabled: */
                #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
                }
                else    
                {
                    /* No, Tx buffer is not correctly configured -> abort the function execution */ 
                }
                #endif /* FR_PREPARE_LPDU_SUPPORT */
            }
            else
            {
                /* LPdu is not configured for Tx -> abort the function execution and return E_NOT_OK  */
            }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
        }                    /* End of 1st phase */
    }                        /* End of 2nd phase */
    #endif /* FR_DEV_ERROR_DETECT == STD_ON */
    
    return returnValue_11;        /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_ReceiveRxLPdu
*
* @brief            Receives data
* @details          [SWS_Fr_00233]:  This function figures out the physical resource mapped to the
*                   reception of the FlexRay frame identified by Fr_LPduIdx, figures out whether
*                   a new FlexRay frame has been received. If a new frame has been received,
*                   copies the received payload data to address Fr_LSduPtr, stores the number of
*                   bytes and the status #FR_RECEIVED. If a new frame has been received, FIFO code
*                   is enabled and Fr_LPduIdx is associated with FIFO A or FIFO B storage, the
*                   received payload data are copied to address Fr_LSduPtr, the number of bytes is
*                   stored and the status #FR_RECEIVED is returned. If no new frame has been
*                   received, the function doesnt copy any payload data to Fr_LSduPtr, writes 0 to
*                   parameter Fr_LSduLengthPtr and stores the status #FR_NOT_RECEIVED.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @param[out]       Fr_LSduPtr Pointer to a buffer where the LSdu
* @param[out]       Fr_LPduStatusPtr Pointer to the memory location where the status of the LPdu
*                   shall be stored
* @param[out]       Fr_LSduLengthPtr Pointer to the memory location where the length of the LSdu
*                   (in bytes) shall be stored
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_ReceiveRxLPdu_Activity
*
* @violates @ref FR_C_REF_7 
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint16, AUTOMATIC) Fr_LPduIdx,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LSduPtr,
    P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr,
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LSduLengthPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_12 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECEIVERXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECEIVERXLPDU_U8, FR_E_INV_CTRL_IDX_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if(Fr_LPduIdx > ((Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->BuffersConfiguredCount -1U))
    {
        /* Fr_LPduIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_RECEIVERXLPDU_U8, FR_E_INV_LPDU_IDX_U8);
    }
    else if(Fr_LSduPtr == NULL_PTR)
    {
        /* If Fr_LSduPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECEIVERXLPDU_U8, FR_E_PARAM_POINTER);
    }
    else if(Fr_LPduStatusPtr == NULL_PTR)
    {
        /* If Fr_LPduStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_RECEIVERXLPDU_U8, FR_E_PARAM_POINTER);
    }
    else if(Fr_LSduLengthPtr == NULL_PTR)
    {
        /* If Fr_LSduLengthPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_RECEIVERXLPDU_U8, FR_E_PARAM_POINTER);
    }
    else                                    /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        /* @violates @ref FR_C_REF_3 */
        if(FR_RECEIVE_BUFFER == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].BufferType)
        {
            #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            /* Check whether buffer is correctly configured to match the properties of
               virtual one */
            /* @violates @ref FR_C_REF_3 */
            if(Fr_VirtualResourceAllocation[Fr_CtrlIdx][(Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].MessageBufferNumber] == Fr_LPduIdx)
            {       /* Yes, receive buffer is currently configured -> execute the following code */
            #endif /* FR_PREPARE_LPDU_SUPPORT */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
                {   /* CC is not accessible, report error */
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    /* @violates @ref FR_C_REF_3 */
                    if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                    {
                        /* @violates @ref FR_C_REF_3 */
                        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                    }
                    #endif
                }
                else
                {
                    /* Copy received data */
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_ReceiveRxLPdu(Fr_CtrlIdx, Fr_LPduIdx, Fr_LSduPtr, Fr_LPduStatusPtr, Fr_LSduLengthPtr))
                    {
                        returnValue_12 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                    }
                    else
                    {
                        /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                        /* @violates @ref FR_C_REF_3 */
                        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                        {
                            /* @violates @ref FR_C_REF_3 */
                            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                } /* Check CC access */
            #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            /* [SWS_Fr_00441]: Only if FR_PREPARE_LPDU_SUPPORT is enabled: */
            }
            else
            {
                /* No, Rx buffer is currently not configured -> abort the function execution and return E_NOT_OK */
            }
            #endif /* FR_PREPARE_LPDU_SUPPORT */
        } 
        /* Check if FIFO A or FIFO B is used */
        /* @violates @ref FR_C_REF_3 */
        else if(FR_FIFOA_BUFFER == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].BufferType)
        {   /* FIFO A is used */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
            {   /* CC is not accessible, report error */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
            }
            else
            {
                /* Copy received data */
                Fr_Ipw_ReceiveFifoA(Fr_CtrlIdx, Fr_LPduIdx, Fr_LSduPtr, Fr_LPduStatusPtr, Fr_LSduLengthPtr);
                
                returnValue_12 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
        }
        /* @violates @ref FR_C_REF_3 */
        else if(FR_FIFOB_BUFFER == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].BufferType) 
        {   /* FIFO B is used */
            if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
            {   /* CC is not accessible, report error */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
            }
            else
            {
                /* Copy received data */
                Fr_Ipw_ReceiveFifoB(Fr_CtrlIdx, Fr_LPduIdx, Fr_LSduPtr, Fr_LPduStatusPtr, Fr_LSduLengthPtr);
                
                returnValue_12 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            }
        }
        else
        {
            /* Tx Buffer was detected -> abort function and return E_NOT_OK */
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_12;        /* Return the state of function execution */
}

/***************************************************************************************************
* @function_name    Fr_CheckTxLPduStatus
*
* @brief            Checks if data have been transmitted.
* @details          [SWS_Fr_00244]: Figures out the physical resource mapped to the transmission
*                   of the FlexRay frame identified by Fr_LPduIdx and check whether
*                   the transmission resource is still pending for transmission or not
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @param[out]       Fr_TxLPduStatusPtr Pointer used to store the transmit status of the LSdu
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_CheckTxLPduStatus_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_CheckTxLPduStatus
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint16, AUTOMATIC) Fr_LPduIdx,
    P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_13 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED); /* Report error */
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, FR_E_INV_CTRL_IDX_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if(Fr_LPduIdx > (((Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->BuffersConfiguredCount) - 1U))
    {
        /* Fr_LPduIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, FR_E_INV_LPDU_IDX_U8);
    }
    else if(NULL_PTR == Fr_TxLPduStatusPtr)
    {
        /* If Fr_TxLPduStatusPtr equals NULL_PTR, FR_E_PARAM_POINTER shall be reported */
        /* to the DET and the API function shall return. */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CHECKTXLPDUSTATUS_U8, FR_E_PARAM_POINTER);
    }
    else                                    /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        /* @violates @ref FR_C_REF_3 */
        if(FR_TRANSMIT_BUFFER == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].BufferType)
        {   /* Transmit MB is configured for given LPdu */
            #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            /* Check whether a transmit resource is correctly configured to match the properties of
               Fr_LPduIdx */
            /* @violates @ref FR_C_REF_3 */
            if(Fr_VirtualResourceAllocation[Fr_CtrlIdx][(Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].MessageBufferNumber] == Fr_LPduIdx)
            {/* Yes, transmit resource is correctly configured -> execute the following code */
            #endif /* FR_PREPARE_LPDU_SUPPORT */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))TRUE))
                {
                    /* CC is not accessible, report error */
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    /* @violates @ref FR_C_REF_3 */
                    if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                    {
                        /* @violates @ref FR_C_REF_3 */
                        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                    }
                   #endif
                }
                else
                {
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_CheckTxLPduStatus(Fr_CtrlIdx, Fr_LPduIdx, Fr_TxLPduStatusPtr))
                    {
                        returnValue_13 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                    }
                    else
                    {   /* Data was not transmitted */
                        /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON return E_NOT_OK */
                        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                        /* @violates @ref FR_C_REF_3 */
                        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                        {
                            /* @violates @ref FR_C_REF_3 */
                            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                } /* CC access check */
            #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            }
            else
            {
                /* No, Tx buffer is not correctly configured -> abort the function execution */
            }
            #endif /* FR_PREPARE_LPDU_SUPPORT */
        }
        else
        {
            /* LPdu is not configured for Tx -> abort the function execution and return E_NOT_OK  */
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_13;        /* Return the state of function execution */
}

#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_PrepareLPdu
*
* @brief            Reconfigures physical resource
* @details          [SWS_Fr_00249]: Figures out the physical resource mapped to the processing
*                   of the FlexRay frame identified by Fr_LPduIdx and configure the physical
*                   resource appropriate for LPduIdx operation if required by Fr configuration
* @warning          Only receive buffers and single transmit buffers reconfiguration is supported
*                   (not FIFO)
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_PrepareLPdu_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_PrepareLPdu
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint16, AUTOMATIC) Fr_LPduIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_31 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
 
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_PREPARELPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED); /* Report error */
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_PREPARELPDU_U8, FR_E_INV_CTRL_IDX_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if(Fr_LPduIdx > (((Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->BuffersConfiguredCount) - 1U))
    {
        /* Fr_LPduIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_PREPARELPDU_U8, FR_E_INV_LPDU_IDX_U8);
    }
    else                                    /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        /* Check  whether LPdu is not dynamically reconfigurable, only LPdus which are not 
            dynamically reconfigurable can use reconfiguration feature */
        /* @violates @ref FR_C_REF_3 */
        if((VAR(boolean, AUTOMATIC))FALSE == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].Reconfigurable)
        {
            if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
            {   /* CC is not accessible, report error */
                #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
                #endif
            }
            else
            {
                if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_PrepareLPdu(Fr_CtrlIdx, Fr_LPduIdx))
                {
                    returnValue_31 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                }
                else
                {
                    /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    /* @violates @ref FR_C_REF_3 */
                    if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                    {
                        /* @violates @ref FR_C_REF_3 */
                        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                    }
                    #endif
                    /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                }
            } /* Fr_check_CC_access */
        }
        else
        {
            returnValue_31 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */

    return returnValue_31;        /* Return the state of function execution */
}
#endif /* FR_PREPARE_LPDU_SUPPORT == STD_ON */

/***************************************************************************************************
* @function_name    Fr_CancelTxLPdu
*
* @brief            Reconfigures physical resource
* @details          [SWS_Fr_00611]: Figure out the physical resource (e.g., a buffer) mapped to the 
*                   transmission of the FlexRay frame identified by Fr_LPduIdx.
*                   If the physical resource figured out is actively pending for transmission, 
*                   then the transmit request of this particular resource shall be terminated and 
*                   E_OK returned. If no transmission is pending E_NOT_OK shall be returned, 
*                   indicating that no such cancelation took place.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_CancelTxLPdu_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_CancelTxLPdu
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint16, AUTOMATIC) Fr_LPduIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_45 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(boolean, AUTOMATIC) bpendingStatus_45 = (VAR(boolean, AUTOMATIC))(FALSE);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_CANCELTXLPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELTXLPDU_U8, FR_E_INV_CTRL_IDX_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if(Fr_LPduIdx > (((Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->BuffersConfiguredCount) - 1U))
    {
        /* Fr_LPduIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_CANCELTXLPDU_U8, FR_E_INV_LPDU_IDX_U8);
    }
    else    /* No error yet -> execute the following code */
    {
    #endif /* FR_DEV_ERROR_DETECT */
        /* Check whether a Tx MB is configured for given LPdu */
        /* @violates @ref FR_C_REF_3 */
        if(FR_TRANSMIT_BUFFER == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].BufferType)
        {   /* Transmit MB is configured for given LPdu */
            #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            /* Check whether buffer is correctly configured to match the properties of
               virtual one */
            /* @violates @ref FR_C_REF_3 */
            if(Fr_VirtualResourceAllocation[Fr_CtrlIdx][(Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].MessageBufferNumber] == Fr_LPduIdx)
            {       /* Yes, transmit buffer is currently configured -> execute the following code */
            #endif /* FR_PREPARE_LPDU_SUPPORT */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
                {   /* CC is not accessible, report error */
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    /* @violates @ref FR_C_REF_3 */
                    if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                    {
                        /* @violates @ref FR_C_REF_3 */
                        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                    }
                    #endif
                }
                else
                {   
                    /* @violates @ref FR_C_REF_6 */
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_CancelTxLPdu(Fr_CtrlIdx, Fr_LPduIdx, &bpendingStatus_45))
                    {
                        /* Transmit request was terminated*/
                        if((VAR(boolean, AUTOMATIC))(TRUE) == bpendingStatus_45)
                        { /*Yes*/
                            returnValue_45 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                        }
                        else
                        {
                            /* Transmit request was not terminated -> return E_NOT_OK */
                        }
                    }
                    else
                    {
                        /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                        /* @violates @ref FR_C_REF_3 */
                        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                        {
                            /* @violates @ref FR_C_REF_3 */
                            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                } /* Fr_check_CC_access */
            #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            }
            else
            {
                 /* No, Tx buffer is not correctly configured -> abort the function execution and return E_NOT_OK */
            }
            #endif /* FR_PREPARE_LPDU_SUPPORT */
        }
        else
        {
             /* LPdu is not configured for Tx -> abort the function execution and return E_NOT_OK  */
        } 
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_45;        /* Return the state of function execution */
}
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
/***************************************************************************************************
* @function_name    Fr_ReconfigLPdu
*
* @brief            Reconfigures physical resource
* @details          [SWS_Fr_00525]: Figure out the physical resource (e.g., a buffer) mapped to the 
*                   processing of the FlexRay frame as identified by Fr_LPduIdx. Configure the 
*                   physical resource (a buffer) according to the parameters given at the API. 
*                   The Lpdu direction is statically associated with the Lpdu and cannot be 
*                   changed by this service.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame
* @param[in]        Fr_FrameId FlexRay Frame ID the FrIf_LPdu shall be configured to
* @param[in]        Fr_ChnlIdx FlexRay Channel the FrIf_LPdu shall be configured to
* @param[in]        Fr_CycleRepetition Cycle Repetition part of the cycle filter mechanism 
*                                      FrIf_LPdu shall be configured to.
* @param[in]        Fr_CycleOffset Cycle Offset part of the cycle filter mechanism FrIf_LPdu shall 
*                                  be configured to.
* @param[in]        Fr_PayloadLength Payloadlength in units of bytes the FrIf_LPduIdx shall be 
*                                    configured to.
* @param[in]        Fr_HeaderCRC Header CRC the FrIf_LPdu shall be configured to.
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_ReconfigLPdu_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_ReconfigLPdu
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint16, AUTOMATIC) Fr_LPduIdx,
    VAR(uint16, AUTOMATIC) Fr_FrameId,
    VAR(Fr_ChannelType, AUTOMATIC) Fr_ChnlIdx,
    VAR(uint8, AUTOMATIC) Fr_CycleRepetition,
    VAR(uint8, AUTOMATIC) Fr_CycleOffset,
    VAR(uint8, AUTOMATIC) Fr_PayloadLength,
    VAR(uint16, AUTOMATIC) Fr_HeaderCRC
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_37 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    
#if(FR_DEV_ERROR_DETECT == STD_ON)
    returnValue_37 = Fr_ReconfigLPduDetReport(Fr_CtrlIdx, Fr_LPduIdx, Fr_FrameId, Fr_ChnlIdx, Fr_CycleRepetition, Fr_CycleOffset, Fr_PayloadLength, Fr_HeaderCRC);
    if ((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == returnValue_37) 
    {
        returnValue_37 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#endif /* FR_DEV_ERROR_DETECT */
        /* Check  whether LPdu is dynamically reconfigurable, only dynamically reconfigurable
        LPdus can be reconfigured */
        /* @violates @ref FR_C_REF_3 */
        if((VAR(boolean, AUTOMATIC))TRUE == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].Reconfigurable)
        {
            /* Check whether buffer is correctly configured to match the properties of virtual one */
        #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            /* @violates @ref FR_C_REF_3 */
            if(Fr_VirtualResourceAllocation[Fr_CtrlIdx][(Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].MessageBufferNumber] == Fr_LPduIdx)
            {
        #endif /* FR_PREPARE_LPDU_SUPPORT */
                /* Check whether target Fr_FrameId is inside static segment */
                /* @violates @ref FR_C_REF_3 */
                if(Fr_FrameId <= (Fr_pCfgPtr + Fr_CtrlIdx)->LowLevelConfigSetPtr->gNumberOfStaticSlots)
                {
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
                    {   
                        /* CC is not accessible, report error */
                        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        /* @violates @ref FR_C_REF_3 */
                        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                        {
                            /* @violates @ref FR_C_REF_3 */
                            Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                    }
                    else
                    {
                        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_ReconfigLPdu(Fr_CtrlIdx, Fr_LPduIdx, Fr_FrameId, Fr_ChnlIdx, Fr_CycleRepetition, Fr_CycleOffset, Fr_PayloadLength, Fr_HeaderCRC))
                        {
                            returnValue_37 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);   
                        }
                        else
                        {
                            /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                            /* @violates @ref FR_C_REF_3 */
                            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                            {
                                /* @violates @ref FR_C_REF_3 */
                                Dem_ReportErrorStatus((VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id, DEM_EVENT_STATUS_FAILED);
                            }
                            #endif
                            /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                        }
                    } /* Fr_check_CC_access */
                }
        #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            }
        #endif /* FR_PREPARE_LPDU_SUPPORT */
        }
#if(FR_DEV_ERROR_DETECT == STD_ON)
    }
#endif /* FR_DEV_ERROR_DETECT */
    return returnValue_37;
}
#endif /* FR_RECONFIG_LPDU_SUPPORT */

#if(FR_DISABLE_LPDU_SUPPORT == STD_ON) 
/***************************************************************************************************
* @function_name    Fr_DisableLPdu
*
* @brief            Reconfigures physical resource
* @details          [SWS_Fr_00540]: Figure out the physical resource (e.g., a buffer) mapped to the 
*                   processing of the FlexRay frame identified by Fr_LPduIdx. Configure the 
*                   physical resource (a buffer) in a way that it does not take part in the 
*                   transmission or reception process.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_LPduIdx This index is used to uniquely identify a FlexRay frame 
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_DisableLPdu_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_DisableLPdu
( 
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx, 
    VAR(uint16, AUTOMATIC) Fr_LPduIdx
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_38 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLELPDU_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED); 
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLELPDU_U8, FR_E_INV_CTRL_IDX_U8);
    }
    /* @violates @ref FR_C_REF_3 */
    else if(Fr_LPduIdx > ((Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->BuffersConfiguredCount - 1U))
    {
        /* Fr_LPduIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_DISABLELPDU_U8, FR_E_INV_LPDU_IDX_U8);
    }
    else 
    {
    #endif /* FR_DEV_ERROR_DETECT */
        /* Check  whether LPdu is dynamically reconfigurable, only dynamically reconfigurable
           LPdus can be disabled by this service */
        /* @violates @ref FR_C_REF_3 */
        if((VAR(boolean, AUTOMATIC))TRUE == (Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].Reconfigurable)
        {
            #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            /* Check whether buffer is correctly configured to match the properties of
               virtual one */
            /* @violates @ref FR_C_REF_3 */
            if(Fr_VirtualResourceAllocation[Fr_CtrlIdx][(Fr_pCfgPtr + Fr_CtrlIdx)->BufferConfigSetPtr->LPduInfoPtr[Fr_LPduIdx].MessageBufferNumber] == Fr_LPduIdx)
            {
            #endif /* FR_PREPARE_LPDU_SUPPORT */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
                {   /* CC is not accessible, report error */
                    #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                    /* @violates @ref FR_C_REF_3 */
                    if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                    {
                        /* @violates @ref FR_C_REF_3 */
                        FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                        Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                    }
                    #endif
                }
                else
                {
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_DisableLPdu(Fr_CtrlIdx, Fr_LPduIdx))
                    {
                        returnValue_38 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                    }
                    else
                    {
                        /* Call Dem for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
                        #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                        /* @violates @ref FR_C_REF_3 */
                        if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
                        {
                            /* @violates @ref FR_C_REF_3 */
                            FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                            Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                        }
                        #endif
                        /* Do nothing for FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_ON */
                    }
                }
            #if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
            }
            else
            {
                /* No, buffer is not correctly configured -> abort the function execution and return E_NOT_OK */
            }
            #endif /* FR_PREPARE_LPDU_SUPPORT */
        }
        else
        {
             /* No, LPdu is not dynamically reconfigurable -> return E_NOT_OK */
        }
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_38;
}
#endif /* FR_DISABLE_LPDU_SUPPORT */

/***************************************************************************************************
* @function_name    Fr_ReadCCConfig
*
* @brief            Reconfigures physical resource
* @details          Read the value of the configuration parameter requested by Fr_ConfigParamIdx 
*                   from the configuration and write it to output parameter *Fr_ConfigParamValuePtr.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_ConfigParamIdx Index that identifies the configuration parameter 
*                                          to read. See macros FR_CIDX_<config_parameter_name>.
* @param[out]       Fr_ConfigParamValuePtr Address the output value is stored to.
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_ReadCCConfig_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_ReadCCConfig
(
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx,
    VAR(uint8, AUTOMATIC) Fr_ConfigParamIdx,
    P2VAR(uint32, AUTOMATIC, FR_APPL_DATA) Fr_ConfigParamValuePtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_46 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(Fr_ConfigParamValuePtr == NULL_PTR)
    {
        /* Fr_ConfigParamValuePtr has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, FR_E_PARAM_POINTER);
    }
    else /* No error yet -> execute the following code */ 
    {
    #endif /* FR_DEV_ERROR_DETECT */
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_ReadbackCCConfig(Fr_CtrlIdx))
        {   /* CC contains error in the configuration */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {  
            returnValue_46 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
            
            switch(Fr_ConfigParamIdx)
            {
                case FR_CIDX_GDCYCLE:
                case FR_CIDX_PMICROPERCYCLE:
                case FR_CIDX_PDLISTENTIMEOUT:
                    /* @violates @ref FR_C_REF_3 */
                    *Fr_ConfigParamValuePtr = (Fr_pCfgPtr + Fr_CtrlIdx)->CCReadBackConfigSetPtr[Fr_ConfigParamIdx];
                    break;    /* 32bit values */
                case FR_CIDX_GMACROPERCYCLE:
                case FR_CIDX_GDMACROTICK:
                case FR_CIDX_GNUMBEROFMINISLOTS:
                case FR_CIDX_GNUMBEROFSTATICSLOTS:
                case FR_CIDX_GDNIT:
                case FR_CIDX_GDSTATICSLOT:
                case FR_CIDX_GDWAKEUPRXWINDOW:
                case FR_CIDX_PKEYSLOTID:
                case FR_CIDX_PLATESTTX:
                case FR_CIDX_POFFSETCORRECTIONOUT:
                case FR_CIDX_POFFSETCORRECTIONSTART:
                case FR_CIDX_PRATECORRECTIONOUT:
                case FR_CIDX_PSECONDKEYSLOTID:
                case FR_CIDX_PDACCEPTEDSTARTUPRANGE:
                case FR_CIDX_GCOLDSTARTATTEMPTS:
                case FR_CIDX_GCYCLECOUNTMAX: 
                case FR_CIDX_GLISTENNOISE:
                case FR_CIDX_GMAXWITHOUTCLOCKCORRECTFATAL:
                case FR_CIDX_GMAXWITHOUTCLOCKCORRECTPASSIVE:
                case FR_CIDX_GNETWORKMANAGEMENTVECTORLENGTH:
                case FR_CIDX_GPAYLOADLENGTHSTATIC:
                case FR_CIDX_GSYNCFRAMEIDCOUNTMAX:
                case FR_CIDX_GDACTIONPOINTOFFSET:
                case FR_CIDX_GDBIT:
                case FR_CIDX_GDCASRXLOWMAX:
                case FR_CIDX_GDDYNAMICSLOTIDLEPHASE:
                case FR_CIDX_GDMINISLOTACTIONPOINTOFFSET:
                case FR_CIDX_GDMINISLOT:
                case FR_CIDX_GDSAMPLECLOCKPERIOD:
                case FR_CIDX_GDSYMBOLWINDOW:
                case FR_CIDX_GDSYMBOLWINDOWACTIONPOINTOFFSET:
                case FR_CIDX_GDTSSTRANSMITTER:
                case FR_CIDX_GDWAKEUPRXIDLE:
                case FR_CIDX_GDWAKEUPRXLOW:
                case FR_CIDX_GDWAKEUPTXACTIVE:
                case FR_CIDX_GDWAKEUPTXIDLE:
                case FR_CIDX_PALLOWPASSIVETOACTIVE:
                case FR_CIDX_PCHANNELS:
                case FR_CIDX_PCLUSTERDRIFTDAMPING:
                case FR_CIDX_PDECODINGCORRECTION:
                case FR_CIDX_PDELAYCOMPENSATIONA:
                case FR_CIDX_PDELAYCOMPENSATIONB:
                case FR_CIDX_PMACROINITIALOFFSETA:
                case FR_CIDX_PMACROINITIALOFFSETB:
                case FR_CIDX_PMICROINITIALOFFSETA:
                case FR_CIDX_PMICROINITIALOFFSETB:
                case FR_CIDX_PPAYLOADLENGTHDYNMAX:
                case FR_CIDX_PSAMPLESPERMICROTICK:
                case FR_CIDX_PWAKEUPCHANNEL:
                case FR_CIDX_PWAKEUPPATTERN:
                case FR_CIDX_PDMICROTICK:
                case FR_CIDX_GDIGNOREAFTERTX:
                case FR_CIDX_PALLOWHALTDUETOCLOCK:
                case FR_CIDX_PEXTERNALSYNC:
                case FR_CIDX_PFALLBACKINTERNAL:
                case FR_CIDX_PKEYSLOTONLYENABLED:
                case FR_CIDX_PKEYSLOTUSEDFORSTARTUP:
                case FR_CIDX_PKEYSLOTUSEDFORSYNC:
                case FR_CIDX_PNMVECTOREARLYUPDATE:
                case FR_CIDX_PTWOKEYSLOTMODE:
                    /* @violates @ref FR_C_REF_3 */                
                    *Fr_ConfigParamValuePtr=( (Fr_pCfgPtr + Fr_CtrlIdx)->CCReadBackConfigSetPtr[(Fr_ConfigParamIdx + 3U) / 2U] >> (16U * (Fr_ConfigParamIdx % 2U)) ) & 0x0000FFFFU;
                    break; /* 16 bit values */
                default:
                    returnValue_46 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
                    /* Fr_ConfigParamIdx has an invalid value */
                    #if(FR_DEV_ERROR_DETECT == STD_ON)
                    (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_READCCCONFIG_U8, FR_E_INV_CONFIG_IDX_U8);
                    #endif
                break;
            }
        }
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */

    return returnValue_46;
}

/***************************************************************************************************
* @function_name    Fr_GetNumOfStartupFrames
*
* @brief            Gets the current number of startup frames seen on the cluster.
* @details          [SWS_Fr_00549]: Read the number of aligned startup frame pairs received or transmitted 
*                   during the previous double cycle, aggregated across both channels and write it 
*                   to the output parameter Fr_NumOfStartupFramesPtr.
* @param[in]        Fr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @param[in]        Fr_NumOfStartupFramesPtr Address where the number of startup frames seen 
*                                            within the last even or odd cycle pair shall be stored.
* @param[out]       Fr_ConfigParamValuePtr Address the output value is stored to.
* @return           ::Std_ReturnType
*                       - E_OK      API call finished successfully
*                       - E_NOT_OK  API call aborted due to errors
*
* @implements       Fr_GetNumOfStartupFrames_Activity
*
* @violates @ref FR_C_REF_7
***************************************************************************************************/
FUNC(Std_ReturnType, FR_CODE) Fr_GetNumOfStartupFrames
( 
    VAR(uint8, AUTOMATIC) Fr_CtrlIdx, 
    P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NumOfStartupFramesPtr
)
{
    /* Set initial return value */
    VAR(Std_ReturnType, AUTOMATIC) returnValue_39 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
    VAR(uint16, AUTOMATIC) u16tmpPOCState_39;
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif
    
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    /* Only if FR_DEV_ERROR_DETECT is enabled: */
    if(FR_INIT != Fr_eDriverStates)   /* Check the initialization status */
    {   /* The Fr was not initialized successfully prior to this API function call */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNUMOFSTARTUPFRAMES_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
    else if(Fr_CtrlIdx >= Fr_u8CtrlNumber) /* Check the Fr_CtrlIdx value */
    {   /* An attempt to configure unsupported CC, Fr_CtrlIdx has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNUMOFSTARTUPFRAMES_U8, FR_E_INV_CTRL_IDX_U8);
    }
    else if(Fr_NumOfStartupFramesPtr == NULL_PTR)
    {
        /* Fr_ConfigParamValuePtr has an invalid value */
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8, FR_SID_GETNUMOFSTARTUPFRAMES_U8, FR_E_PARAM_POINTER);
    }
    else /* No error yet -> execute the following code */ 
    {
    #endif /* FR_DEV_ERROR_DETECT */
    
        if((VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK) == Fr_Ipw_CheckCCAccess(Fr_CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
        {   /* CC is not accessible, report error */
            #if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            /* @violates @ref FR_C_REF_3 */
            if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->state)
            {
                /* @violates @ref FR_C_REF_3 */
                FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_CtrlIdx)->FrDemCtrlTestResultPtr->id;
                Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
            }
            #endif
        }
        else
        {
            
            /* Determine the POC state */ 
            u16tmpPOCState_39 = Fr_Ipw_GetPOCState(Fr_CtrlIdx);
           
            /* Check whether the CC is synchronous to cluster */
            if((FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16 == u16tmpPOCState_39) || (FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16 == u16tmpPOCState_39))
            {   /* The CC is synchronized to the cluster */
                /* Call LLD function to get number of startup frames */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_GetNumOfStartupFrames(Fr_CtrlIdx, Fr_NumOfStartupFramesPtr))
                {
                    /* API call was successful */
                    returnValue_39 = (VAR(Std_ReturnType, AUTOMATIC))(E_OK);
                }
            }
            else
            {   /* The CC is not synchronized to the cluster */
                returnValue_39 = (VAR(Std_ReturnType, AUTOMATIC))(E_NOT_OK);
            }
        } 
        
    #if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    #endif /* FR_DEV_ERROR_DETECT */
    
    return returnValue_39;
}
#if(FR_DEINIT_API == STD_ON)
/**************************************************************************************************
* @function_name    Fr_DeInit
*
* @brief            Deinitialize and reset Flexray registers
* @details          De-initialize Flexray Module
* @param[in]        FFr_CtrlIdx Index of FlexRay CC within the context of the FlexRay Driver
* @return           none
*
* @implements       Fr_DeInit_Activity
*
*
* @violates @ref FR_C_REF_7
**************************************************************************************************/
FUNC(void, FR_CODE) Fr_DeInit(void)
{
    VAR(uint8, AUTOMATIC) Fr_u8CtrlIdx;
    VAR(boolean, AUTOMATIC) Fr_bDeInitSuccessful = (VAR(boolean, AUTOMATIC))FALSE;
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Dem_EventIdType, AUTOMATIC) FR_E_CTRL_TESTRESULT;
#endif

#if(FR_DEV_ERROR_DETECT == STD_ON)
    if((FR_INIT == Fr_eDriverStates) || (FR_DEINIT_FALSE == Fr_eDriverStates))   /* Check the initialization status */
    {
#endif /* FR_DEV_ERROR_DETECT */
        /* Loop all controller in configuration */
        for(Fr_u8CtrlIdx = 0U; Fr_u8CtrlIdx < FR_NUM_CTRL_SUPPORTED; Fr_u8CtrlIdx++)
        {
            /* Check Controller state */
            if ((VAR(boolean, AUTOMATIC))TRUE == Fr_bCCActive[Fr_u8CtrlIdx])
            {
                /* Check Controller access */
                if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_CheckCCAccess(Fr_u8CtrlIdx, (VAR(boolean, AUTOMATIC))(TRUE)))
                {
                    /* Go to FREEZE mode */
                    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_u8CtrlIdx, FLEXRAY_POCR_CMD_FREEZE_U16))
                    {
                        /* Go to DEFAULT_CONFIG mode */
                        if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_InvokeCHICommand(Fr_u8CtrlIdx, FLEXRAY_POCR_CMD_DEFAULTCONFIG_U16))
                        {
                            /* wait for the controller into DEFAULT_CONFIG mode exactly*/
                            if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_WaitForPOCState(Fr_u8CtrlIdx, FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16))
                            {
                                /* Go to CONFIG mode */
                                if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_EnterPOCConfigState(Fr_u8CtrlIdx))
                                {
                                    /* Call Fr_DeInit function */
                                    if((VAR(Std_ReturnType, AUTOMATIC))(E_OK) == Fr_Ipw_DeInit(Fr_u8CtrlIdx))
                                    {
                                        /* Execute De-init function successfully without any error. */
                                        Fr_bDeInitSuccessful = (VAR(boolean, AUTOMATIC))TRUE;
                                        /* This controller is de-activated */
                                        Fr_bCCActive[Fr_u8CtrlIdx] = (VAR(boolean, AUTOMATIC))FALSE;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                /* This Fr controller is not yet enbale, all register still in reset value, do not need to de-initilaze  */
                Fr_bDeInitSuccessful = (VAR(boolean, AUTOMATIC))TRUE;
            }
            if ((VAR(boolean, AUTOMATIC))FALSE == Fr_bDeInitSuccessful)
            {
                /* if have any error during execute Fr_DeInit function and enable the DEM report, driver will report DEM error */
#if(FR_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                /* @violates @ref FR_C_REF_3 */
                if((VAR(uint32, AUTOMATIC))STD_ON == (Fr_pCfgPtr + Fr_u8CtrlIdx)->FrDemCtrlTestResultPtr->state)
                {
                    /*Report DEM error*/
                    /* @violates @ref FR_C_REF_3 */
                    FR_E_CTRL_TESTRESULT = (VAR(Dem_EventIdType, AUTOMATIC))(Fr_pCfgPtr + Fr_u8CtrlIdx)->FrDemCtrlTestResultPtr->id;
                    Dem_ReportErrorStatus(FR_E_CTRL_TESTRESULT, DEM_EVENT_STATUS_FAILED);
                }
#endif
#if(FR_DEV_ERROR_DETECT == STD_ON)
                Fr_eDriverStates = FR_DEINIT_FALSE;
#endif
                break;
            }
#if(FR_DEV_ERROR_DETECT == STD_ON)
            else
            {
                Fr_eDriverStates = FR_UNINIT;
            }
#endif
        }
#if(FR_DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        (void)Det_ReportError((VAR(uint16, AUTOMATIC))FR_MODULE_ID, FR_INSTANCE_ID_U8,FR_SID_DEINIT_U8, (VAR(uint8, AUTOMATIC))FR_E_INIT_FAILED);
    }
#endif
}
#endif /* FR_DEINIT_API */
#define FR_STOP_SEC_CODE
/* Covers FR112 */
/* @violates @ref FR_C_REF_2 */
/* @violates @ref FR_C_REF_5 */
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
