/**
*   @file    Dio_Siul2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Dio SIUL2 low level SIUL2 header.
*   @details This file is the SIUL2 DIO low level driver header.
*
*   @addtogroup DIO_SIUL2
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : SIUL2
*   Dependencies         : none
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef DIO_SIUL2_H
#define DIO_SIUL2_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_Siul2_h_REF_1
*     Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
*     order to prevent the contents of a header file being included twice. This violation is not fixed 
*     since the inclusion of MemMap.h is required by Autosar.
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

/*=================================================================================================
*                               SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_SIUL2_VENDOR_ID                     43
#define DIO_SIUL2_AR_RELEASE_MAJOR_VERSION      4
#define DIO_SIUL2_AR_RELEASE_MINOR_VERSION      2
#define DIO_SIUL2_AR_RELEASE_REVISION_VERSION   2
#define DIO_SIUL2_SW_MAJOR_VERSION              1
#define DIO_SIUL2_SW_MINOR_VERSION              0
#define DIO_SIUL2_SW_PATCH_VERSION              0

/*=================================================================================================
                                      FILE VERSION CHECKS
=================================================================================================*/


/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/

#define DIO_PORTID_SHIFT_U8                     ((uint8)0x4U)
#define DIO_CHANNELGRP_OFFSET_PINS_U32          ((uint32)0x0000FFFFUL)
#define DIO_CHANNELGRP_MASK_PINS_U32            ((uint32)0x16UL)

/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/


/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#define DIO_START_SEC_CODE
/* @violates @ref Dio_Siul2_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Dio_MemMap.h"


/**
* @brief   Read the channel level
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_Siul2_ReadChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);

/**
* @brief   Write the level to the channel
*/
FUNC(void, DIO_CODE) Dio_Siul2_WriteChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId,
    CONST(Dio_LevelType,   AUTOMATIC) Level
);

#if (STD_ON == DIO_FLIP_CHANNEL_API)
/**
* @brief   Flip the level of the channel
*/
FUNC(Dio_LevelType, DIO_CODE) Dio_Siul2_FlipChannel
(
    CONST(Dio_ChannelType, AUTOMATIC) ChannelId
);
#endif /* (STD_ON == DIO_FLIP_CHANNEL_API) */

/**
* @brief   Read the port level
*/
FUNC(Dio_PortLevelType, DIO_CODE) Dio_Siul2_ReadPort
(
    CONST(Dio_PortType, AUTOMATIC) PortId
);

/**
* @brief   Write the port level
*/
FUNC(void, DIO_CODE) Dio_Siul2_WritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level
);

/**
* @brief   Read the level of the channels group
*/
FUNC(Dio_PortLevelType, DIO_CODE) Dio_Siul2_ReadChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupIdPtr
);

/**
* @brief   Write the level of the channels group
*/
FUNC(void, DIO_CODE) Dio_Siul2_WriteChannelGroup
(
    P2CONST(Dio_ChannelGroupType, AUTOMATIC, DIO_APPL_CONST) pChannelGroupIdPtr,
    CONST  (Dio_PortLevelType,    AUTOMATIC)                 Level
);

#if (STD_ON == DIO_MASKEDWRITEPORT_API)
/**
@brief   DIO Mask write port using mask
*/
FUNC(void, DIO_CODE) Dio_Siul2_MaskedWritePort
(
    CONST(Dio_PortType,      AUTOMATIC) PortId,
    CONST(Dio_PortLevelType, AUTOMATIC) Level,
    CONST(Dio_PortLevelType, AUTOMATIC) Mask
);
#endif /* (STD_ON == DIO_MASKEDWRITEPORT_API) */

#define DIO_STOP_SEC_CODE
/** @violates @ref Dio_Siul2_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file */
#include "Dio_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* DIO_SIUL2_H */
/** @} */
