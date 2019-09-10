/**
*   @file    Lin_LINFlex.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Lin - Low level driver header file.
*   @details This file includes the function prototypes defined in the LIN low level driver for LinFlex.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : LINFlex
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

#ifndef LIN_LINFLEX_H
#define LIN_LINFLEX_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_LINFlex_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_LINFlex_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.

* @section Lin_LINFlex_h_REF_3
* Violates MISRA 2004 Required Rule 8.8, Precautions shall be taken
* in order to prevent external objects or functions to be declared
* in more than one file.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Lin_LINFlex.h
*/
#define LIN_VENDOR_ID_FLEX                    43
#define LIN_AR_RELEASE_MAJOR_VERSION_FLEX     4
#define LIN_AR_RELEASE_MINOR_VERSION_FLEX     2
/*
* @violates @ref Lin_LINFlex_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_FLEX  2
#define LIN_SW_MAJOR_VERSION_FLEX             1
#define LIN_SW_MINOR_VERSION_FLEX             0
#define LIN_SW_PATCH_VERSION_FLEX             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief        Sleep command ID 0x3C.
*
*/
#define LINFLEX_SLEEP_COMMAND_ID_U32    ((uint32)0x0000003C) /**< @brief Sleep
                                                          command ID 0x3C.*/

/**
* @brief        Sleep command length frame.
*
*/
#define LINFLEX_DATA_LENGTH_8_U32       ((uint32)7U)         /**< @brief Sleep
                                                          command length.*/

/**
* @brief        Sleep command frame: 0xFF data.
*
*/
#define LINFLEX_DATA_255_U32            ((uint32)255U)          /**< @brief 0xFF
                                                          data.*/

/**
* @brief        Sleep command frame: 0x00 data.
*
*/
#define LINFLEX_DATA_0_U32              ((uint32)0U)          /**< @brief 0x00
                                                          data.*/

/**
* @brief        Catastrophic Errors Recovery (CER) Codes returned by the LIN driver.
*
* @details      Unexpected frame status CER code.
*
*/
#define LINFLEX_CER_UNEXPECTED_FRAME_STATUS_INTERRUPT_U8 ((uint8)0x01U)
                                               /**< @brief Unexpected
                                                    frame status.*/

/**
* @brief        Catastrophic Errors Recovery (CER) Codes returned by the LIN driver.
*
* @details      Unexpected frame error status CER code.
*
*/
#define LINFLEX_CER_UNEXPECTED_FRAME_ERROR_STATUS_INTERRUPT_U8 ((uint8)0x02U)
                                               /**< @brief Unexpected
                                                    frame error
                                                    status.*/
/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief          API LINFLEX LLD functions service IDs.
* @details        Service IDs of the LINFLEX LLD API.
*/
typedef enum
{
    LINFLEX_LLD_COPYDATA_ID        = (uint8)0x03U, /**< @brief
                                  LINFLEX_LLD_CopyData() ID.*/
    LINFLEX_LLD_HWGETSTATUS_ID     = (uint8)0x04U, /**< @brief
                                  LINFLEX_LLD_HardwareGetStatus() ID.*/
    LINFLEX_LLD_WAKEUP_ID          = (uint8)0x05U, /**< @brief
                                  LINFLEX_LLD_WakeUp() ID.*/
    LINFLEX_LLD_GOTOSLEEPINT_ID    = (uint8)0x06U, /**< @brief
                                  LINFLEX_LLD_GoToSleepInternal() ID.*/
    LINFLEX_LLD_GOTOSLEEP_ID       = (uint8)0x07U, /**< @brief
                                  LINFLEX_LLD_GoToSleep() ID.*/
    LINFLEX_LLD_SENDRESPONSE_ID    = (uint8)0x08U, /**< @brief
                                  LINFLEX_LLD_SendResponse()ID.*/
    LINFLEX_LLD_SENDHEADER_ID      = (uint8)0x09U, /**< @brief
                                  LINFLEX_LLD_SendHeader() ID.*/
    LINFLEX_LLD_DEINITCHANNEL_ID   = (uint8)0x0AU, /**< @brief
                                  LINFLEX_LLD_DeInitChannel() ID.*/
    LINFLEX_LLD_INITCHANNEL_ID     = (uint8)0x0BU, /**< @brief
                                  LINFLEX_LLD_InitChannel() ID.*/
    LINFLEX_LLD_CHECKWAKEUP_ID     = (uint8)0x0CU, /**< @brief
                                  LINFlex_LLD_CheckWakeup() ID.*/
    LINFLEX_LLD_IRQHANDLER_ID      = (uint8)0x0DU  /**< @brief
                                  LINFLEX_LLD_InterruptHandler() ID.*/
} Lin_Linflex_ApiFunctionIdsType;

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

#define LIN_START_SEC_VAR_NO_INIT_8
/**
* @violates @ref Lin_LINFlex_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @violates @ref Lin_LINFlex_h_REF_3 Precautions shall be taken in order to prevent variables being
*        declared as external in more than one file.
*/
extern volatile VAR(uint8,LIN_VAR)Lin_au8LinChStatus[LIN_HW_MAX_MODULES];

/**
* @violates @ref Lin_LINFlex_h_REF_3 Precautions shall be taken in order to prevent variables being
*        declared as external in more than one file.
*/
extern volatile VAR(uint8,LIN_VAR)Lin_au8LinChFrameStatus[LIN_HW_MAX_MODULES];

/**
* @violates @ref Lin_LINFlex_h_REF_3 Precautions shall be taken in order to prevent variables being
*        declared as external in more than one file.
*/
extern VAR(uint8, LIN_VAR)Lin_au8TransmitHeaderCommand[LIN_HW_MAX_MODULES];

/**
* @violates @ref Lin_LINFlex_h_REF_3 Precautions shall be taken in order to prevent variables being
*        declared as external in more than one file.
*/
extern volatile VAR(uint8,LIN_VAR)Lin_au8LinChFrameErrorStatus[LIN_HW_MAX_MODULES];

/**
* @violates @ref Lin_LINFlex_h_REF_3 Precautions shall be taken in order to prevent variables being
*        declared as external in more than one file.
*/
extern VAR(sint8,LIN_VAR)Lin_as8ChannelHardwareMap[LIN_HW_MAX_AVAILABLE_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT_8
/**
* @violates @ref Lin_LINFlex_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 #define LIN_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Lin_LINFlex_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
extern P2CONST(Lin_ConfigType,LIN_VAR,LIN_APPL_CONST) Lin_pcConfigPtr;
#define LIN_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Lin_LINFlex_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 #define LIN_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Lin_LINFlex_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @violates @ref Lin_LINFlex_h_REF_3 Precautions shall be taken in order to prevent variables being
*        declared as external in more than one file.
*/
extern P2CONST(Lin_ChannelConfigType,LIN_VAR,LIN_APPL_CONST)Lin_pChannelConfigPtr[LIN_HW_MAX_MODULES];


#define LIN_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Lin_LINFlex_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_LINFlex_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
FUNC (void, LIN_CODE) Lin_Linflex_TxRxInterruptHandler(CONST(uint8, AUTOMATIC) u8Channel);
FUNC (void, LIN_CODE) Lin_Linflex_ErrorInterruptHandler(CONST(uint8, AUTOMATIC) u8Channel);

/*****************************************************************************
**                          Non-AUTOSAR LIN Low Level Driver API's          **
*****************************************************************************/
FUNC (Std_ReturnType, LIN_CODE) Lin_Linflex_CheckWakeup(CONST(uint8, AUTOMATIC) u8Channel);
FUNC (void, LIN_CODE) Lin_Linflex_InitChannel(CONST(uint8, AUTOMATIC) u8Channel);
FUNC (Std_ReturnType, LIN_CODE) Lin_Linflex_SendHeader(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr);
FUNC (void, LIN_CODE) Lin_Linflex_SendResponse(CONST(uint8, AUTOMATIC) u8Channel, P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr);
FUNC (Std_ReturnType, LIN_CODE) Lin_Linflex_GoToSleep(CONST(uint8, AUTOMATIC) u8Channel);
FUNC (Std_ReturnType, LIN_CODE) Lin_Linflex_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Channel);
FUNC (void, LIN_CODE) Lin_Linflex_WakeUp(CONST(uint8, AUTOMATIC) u8Channel);

 FUNC (void, LIN_CODE) Lin_Linflex_WakeupInternal(CONST(uint8, AUTOMATIC) u8Channel);
 
FUNC (Lin_StatusType, LIN_CODE) Lin_Linflex_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Channel, P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr);

#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_LINFlex_h_REF_1 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif

#endif /* LIN_LINFLEX_H */

/** @} */
