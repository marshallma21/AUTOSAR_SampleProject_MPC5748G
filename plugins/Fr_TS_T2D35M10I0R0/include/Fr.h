/**
*   @file       Fr.h
*   @implements Fr.h_Artifact
*
*   @version 1.0.0
*
*   @brief   AUTOSAR Fr - Module interface file.
*   @details Contains all types and function prototypes required by FlexRay driver.
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
#ifndef FR_H
#define FR_H

#ifdef __cplusplus
extern "C"{
#endif
/***************************************************************************************************
* MISRA violations
***************************************************************************************************/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section FR_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, #include "Fr_MemMap.h" is not preceded only by
* preprocessor directives and appears not only in the beginning of file because it otherwise
* would not work.
*
* @section FR_H_REF_2
* Violates MISRA 2004 Required Rule 8.7, Declaration required here.
*
* @section FR_H_REF_3
* Violates MISRA 2004 Required Rule 8.12, This is not violation size of array is defined by 
* initialization.
*
* @section FR_H_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler - linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* Identifier is specified by ASR standard.
*
* @section FR_H_REF_5
* Violates MISRA 2004 Required Rule 5.1, Identifier is specified by the FSL coding rule standard.
*
* @section FR_H_REF_6
* Violates MISRA 2004 Advisory Rule 19.1, Inclusion of "MemMap.h" is required here because of
* its functionality.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fr_GeneralTypes.h"
#include "Fr_Cfg.h"
#include "Std_Types.h"
#include "Soc_Ips.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_MODULE_ID                        81
#define FR_VENDOR_ID                        43
#define FR_AR_RELEASE_MAJOR_VERSION         4
#define FR_AR_RELEASE_MINOR_VERSION         2
#define FR_AR_RELEASE_REVISION_VERSION      2
#define FR_SW_MAJOR_VERSION                 1
#define FR_SW_MINOR_VERSION                 0
#define FR_SW_PATCH_VERSION                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr_Cfg.h header file are of the same vendor */
#if(FR_VENDOR_ID != FR_VENDOR_ID_CFG)
    #error "Fr.h and Fr_Cfg.h have different Vendor IDs"
#endif
/* Check if current file and Fr_Cfg.h header file are of the same Autosar version */
#if((FR_AR_RELEASE_MAJOR_VERSION    != FR_AR_RELEASE_MAJOR_VERSION_CFG) || \
    (FR_AR_RELEASE_MINOR_VERSION    != FR_AR_RELEASE_MINOR_VERSION_CFG) || \
    (FR_AR_RELEASE_REVISION_VERSION != FR_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Fr.h and Fr_Cfg.h are different"
#endif
/* Check if current file and Fr_Cfg.h header file are of the same software version */
#if((FR_SW_MAJOR_VERSION != FR_SW_MAJOR_VERSION_CFG) || \
    (FR_SW_MINOR_VERSION != FR_SW_MINOR_VERSION_CFG) || \
    (FR_SW_PATCH_VERSION != FR_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Fr.h and Fr_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h header file are of the same Autosar version */
    #if((FR_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FR_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Fr.h and Std_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Error reported when parameter timer index exceeds number of available timers
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_TIMER_IDX_U8                     ((uint8)0x01U)
/**
* @brief Error reported when invalid pointer in parameter list
* @implements Fr_DetErrorIds_define
* */
#define FR_E_PARAM_POINTER                        ((uint8)0x02U)
/**
* @brief Error reported when parameter offset exceeds bounds  
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_OFFSET_U8                        ((uint8)0x03U)
/**
* @brief Error reported when invalid controller index
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_CTRL_IDX_U8                      ((uint8)0x04U)
/**
* @brief Error reported when invalid channel index
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_CHNL_IDX_U8                      ((uint8)0x05U)
/**
* @brief Error reported when parameter cycle exceeds 63
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_CYCLE_U8                         ((uint8)0x06U)
/**
* @brief Error reported when Fr module was not initialized
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INIT_FAILED                          ((uint8)0x08U)
/**
* @brief Error reported when Fr CC is not in the expected POC state
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_POCSTATE_U8                      ((uint8)0x09U)
/**
* @brief Error reported when Payload length parameter has an invalid value
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_LENGTH_U8                        ((uint8)0x0AU)
/**
* @brief Error reported when invalid LPdu index
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_LPDU_IDX_U8                      ((uint8)0x0BU)
/**
* @brief Error reported when invalid FlexRay header CRC
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_HEADERCRC_U8                     ((uint8)0x0CU)
/**
* @brief Error reported when invalid value passed as parameter Fr_ConfigParamIdx.
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_CONFIG_IDX_U8                    ((uint8)0x0DU)
/**
* @brief Error reported when invalid framelist size value.
* @implements Fr_DetErrorIds_define
* */
#define FR_E_INV_FRAMELIST_SIZE                   ((uint8)0x0EU)
#define FR_E_DEFAULT                              ((uint8)0x0FU)

/* Service ID for DET reporting */
#define FR_SID_INIT_U8                            ((uint8)0x1CU)
#define FR_SID_CONTROLLERINIT_U8                  ((uint8)0x00U)
#define FR_SID_STARTCOMMUNICATION_U8              ((uint8)0x03U)
#define FR_SID_HALTCOMMUNICATION_U8               ((uint8)0x04U)
#define FR_SID_ABORTCOMMUNICATION_U8              ((uint8)0x05U)
#define FR_SID_SENDWUP_U8                         ((uint8)0x06U)
#define FR_SID_SETWAKEUPCHANNEL_U8                ((uint8)0x07U)
#define FR_SID_GETPOCSTATUS_U8                    ((uint8)0x0AU)
#define FR_SID_TRANSMITTXLPDU_U8                  ((uint8)0x0BU)
#define FR_SID_RECEIVERXLPDU_U8                   ((uint8)0x0CU)
#define FR_SID_CHECKTXLPDUSTATUS_U8               ((uint8)0x0DU)
#define FR_SID_GETGLOBALTIME_U8                   ((uint8)0x10U)
#define FR_SID_SETABSTIMER_U8                     ((uint8)0x11U)
#define FR_SID_CANCELABSTIMER_U8                  ((uint8)0x13U)
#define FR_SID_ENABLEABSTIMERIRQ_U8               ((uint8)0x15U)
#define FR_SID_ACKABSTIMERIRQ_U8                  ((uint8)0x17U)
#define FR_SID_DISABLEABSTIMERIRQ_U8              ((uint8)0x19U)
#define FR_SID_GETVERSIONINFO_U8                  ((uint8)0x1BU)
#define FR_SID_PREPARELPDU_U8                     ((uint8)0x1FU)
#define FR_SID_GETABSTIMERIRQSTATUS_U8            ((uint8)0x20U)
#define FR_SID_GETNMVECTOR_U8                     ((uint8)0x22U)
#define FR_SID_ALLOWCOLDSTART_U8                  ((uint8)0x23U)
#define FR_SID_ALLSLOTS_U8                        ((uint8)0x24U)
#define FR_SID_RECONFIGLPDU_U8                    ((uint8)0x25U)
#define FR_SID_DISABLELPDU_U8                     ((uint8)0x26U)
#define FR_SID_GETNUMOFSTARTUPFRAMES_U8           ((uint8)0x27U)
#define FR_SID_GETCHANNELSTATUS_U8                ((uint8)0x28U)
#define FR_SID_GETCLOCKCORRECTION_U8              ((uint8)0x29U)
#define FR_SID_GETSYNCFRAMELIST_U8                ((uint8)0x2AU)
#define FR_SID_GETWAKEUPRXSTATUS_U8               ((uint8)0x2BU)
#define FR_SID_CANCELTXLPDU_U8                    ((uint8)0x2DU)
#define FR_SID_READCCCONFIG_U8                    ((uint8)0x2EU)
#if(FR_DEINIT_API == STD_ON)
#define FR_SID_DEINIT_U8                          ((uint8)0x2FU)
#endif

#ifdef ERR_IPV_FLEXRAY_0002
#if(ERR_IPV_FLEXRAY_0002 == STD_ON)
/* Halt command macro */
#define FR_POCR_CMD_HALT_U16                      ((uint16)0x0007U)
#else
    #error : the define ERR_IPV_FLEXRAY_0002 must not be STD_OFF
#endif
#endif /* ERR_IPV_FLEXRAY_0002 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/***************************************************************************************************
* @enum Fr_CCClockSourceType
***************************************************************************************************/
typedef enum
{
    FR_CLK_SRC_CRYSTAL_OSCILLATOR = 0U,  /* Selects on-chip crystal oscillator. */
    FR_CLK_SRC_PLL                       /* Selects System PLL clock. */
} Fr_CCClockSourceType;

/***************************************************************************************************
* @enum Fr_BufferType
*  @brief This type is used to specify type of the message buffer.
***************************************************************************************************/
typedef enum
{
    FR_FIFOA_BUFFER = 0U,  /* Receive FIFO A */
    FR_FIFOB_BUFFER,       /* Receive FIFO B */
    FR_TRANSMIT_BUFFER,    /* Individual transmit message buffer */
    FR_RECEIVE_BUFFER      /* individual receive message buffer */
} Fr_BufferType;

/***************************************************************************************************
* @enum Fr_CCFifoRangeFilterModeType
*  @brief  Type definition for the Fr_FIFO_range_filter_mode field of the
*   Fr_FIFO_range_filter_config_type structure.
***************************************************************************************************/
typedef enum
{
    FR_ACCEPTANCE = 0U,  /* Filter is set to accept selected IDs */
    FR_REJECTION         /* Filter is set to reject selected IDs */
} Fr_CCFifoRangeFilterModeType;

/***************************************************************************************************
* @enum Fr_CCFifoChannelType
*  @brief Type channel definition for Receive FIFO storage
***************************************************************************************************/
typedef enum
{
    FR_RECEIVE_FIFOA = 0U,  /* Receive FIFO A */
    FR_RECEIVE_FIFOB        /* Receive FIFO B */
} Fr_CCFifoChannelType;


/***************************************************************************************************
* @enum Fr_SoftwareStatesType
*  @brief Type of software states.
***************************************************************************************************/
typedef enum
{
    FR_UNINIT = 0U,  /* Flexray un-init */
    FR_INIT          /* Flexray init */
#if(FR_DEINIT_API == STD_ON)
    ,FR_DEINIT_FALSE  /* De-init false */
#endif
} Fr_SoftwareStatesType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/***************************************************************************************************
* @typedef Fr_ConfigType
*  @brief   Basic configuration type. Pointer to this type is passed to the Fr_Init() function.
*  @implements Fr_ConfigType_typedef
***************************************************************************************************/
typedef void Fr_ConfigType;
#ifdef SUPPORT_IP_V9
#ifdef FR_ACCESS_ERROR_NOTIFICATION_EN
/**
* @brief          Type for pointer to function.
* @details        Type for pointer to function. Used for user handlers from plugin.
*
*/
typedef void (*Fr_PCallBackType)( void);
#endif /* FR_ACCESS_ERROR_NOTIFICATION_EN */
#endif /* SUPPORT_IP_V9 */
/***************************************************************************************************
* @struct Fr_CCHardwareConfigType
*  @details The structure of the type Fr_CCHardwareConfigType contains the FlexRay module specific
*   parameters. The instance of the Fr_CCHardwareConfigType structure is used by the
*   Fr_ControllerInit() function.
***************************************************************************************************/
typedef struct
{
    /* Base address of the FlexRay module */
    CONST(uint32, FR_CONST)CCBaseAddress;
    /* Base address of the FlexRay memory */
    CONSTP2CONST(uint8, FR_CONST, FR_APPL_CONST)CCFlexRayMemoryBaseAddress;
    /* Channel to which the node is connected */
    CONST(Fr_ChannelType, FR_CONST)Channels;
    /* Enabling of single channel mode (FALSE - dual channel mode) */
    CONST(boolean, FR_CONST)SingleChannelModeEnabled;
    /* Protocol Engine Clock Source select */
    CONST(Fr_CCClockSourceType, FR_CONST)ClockSource;
    /* Channel Bit Rate selection */
    CONST(uint8, FR_CONST)Bitrate;
    /* Timeout value in the MCR reg. */
    CONST(uint8, FR_CONST)Timeout;
    /* Offset for sync frame tables */
    CONST(uint16, FR_CONST)SyncFrameTableOffset;
#ifdef SUPPORT_IP_V9
    #ifdef FR_ACCESS_ERROR_NOTIFICATION_EN
    CONST(Fr_PCallBackType, CAN_CONST) Fr_AccessErrorNotification;
    #endif /* FR_ACCESS_ERROR_NOTIFICATION_EN */
#endif /* SUPPORT_IP_V9 */
    /* Second absolute timer enable/disable */
    CONST(boolean, FR_CONST)EnableSecondaryAbsTimer;
} Fr_CCHardwareConfigType;

/***************************************************************************************************
* @struct Fr_CCLpduInfoType
*  @brief Each individual MB is configured through this structure
*  @details The instance of the type Fr_CCLpduInfoType is an array of configuration structures.
*   Each item in this array describes one LPdu and its connection to a buffer
***************************************************************************************************/
typedef struct
{
    /* Buffer type */
    CONST(Fr_BufferType, FR_CONST)BufferType;
    /* Reference to buffer configuration structure */
    CONSTP2CONST(void, FR_CONST, FR_APPL_CONST)BufferConfigPtr;
    /* Individual Message Buffer Number */
    CONST(uint8, FR_CONST)MessageBufferNumber;
    /* Buffer should be used for the initialization? */
    CONST(boolean, FR_CONST)FirstInitialization;
    /* Buffer is Reconfigurable */
    CONST(boolean, FR_CONST)Reconfigurable;
} Fr_CCLpduInfoType;

/***************************************************************************************************
* @struct Fr_CCBufferAddressType
*  @details Array of this type contains the 32-bit or 64-bit addresses (FlexRay memory base plus data area
*   offset) of message buffers data areas. These values are used for message buffer
*   transmission/reception operation.
*  @par
*   The address of this array of the type Fr_CCBufferAddressType should be passed into the
*   relevant BufferOffsetTable parameter of the configuration structure of the type
*   Fr_CCBufferConfigSetType.
*  @par
*   Data field offset is used to determine the start address of the corresponding message buffer
*   data field in the FlexRay memory according to equation:
*  @par
*   DataAddr [Fr_CCBufferAddressType] = DataOffset16 [Fr_CCBufferOffset16Type] +
*   CCFlexRayMemoryBaseAddress[Fr_CCHardwareConfigType]
*  @par
*   The instance of the Fr_CCBufferAddressType structure is used by the
*   Fr_TransmitTxLPdu() and Fr_ReceiveRxLPdu() functions.
***************************************************************************************************/
typedef struct
{
    CONSTP2CONST(uint8, FR_CONST, FR_APPL_CONST)MbDataAddrPtr;  /* Address pointer of the message buffer data field */
} Fr_CCBufferAddressType;

/***************************************************************************************************
* @struct Fr_CCBufferOffset16Type
*  @details Array of this type contains 16-bit offset values for message buffer data areas.
*   These values are used only for message buffer initialization. During transmission/reception
*   operation with message buffer, the similar array of type Fr_CCBufferAddressType is used.
*  @par
*   The address of this array of the type Fr_CCBufferOffset16Type should be passed into the
*   relevant BufferInitOffsetTable parameter of the configuration structure of the type
*   Fr_CCBufferConfigSetType.
*   Data field offset is used to determine the start address of the corresponding message buffer
*   data field in the FlexRay memory.
*  @par
*   The instance of the Fr_CCBufferOffset16Type structure is used by the Fr_ControllerInit() and
*   Fr_PrepareLPdu() functions.
***************************************************************************************************/
typedef struct
{
    CONST(uint16, FR_CONST)DataOffset16;  /* Offset value of the message buffer data field */
}Fr_CCBufferOffset16Type;

/***************************************************************************************************
* @struct Fr_CCBufferConfigSetType
*  @details The instance of the Fr_CCBufferConfigSetType structure is used by the
*   Fr_ControllerInit(), Fr_TransmitTxLPdu(), Fr_PrepareLPdu(), Fr_ReceiveRxLPdu() and
*   Fr_CheckTxLPduStatus() functions to access the message buffers configuration.
***************************************************************************************************/
typedef struct
{
    /* Reference to configuration information of one message buffer configuration set */
    CONSTP2CONST(Fr_CCLpduInfoType, FR_CONST, FR_APPL_CONST)LPduInfoPtr;
    /* Initial MB offsets 32-bit */
    CONSTP2CONST(Fr_CCBufferAddressType, FR_CONST, FR_APPL_CONST)BufferAddressTable;
    /* Initial MB offsets 16-bit */
    CONSTP2CONST(Fr_CCBufferOffset16Type, FR_CONST, FR_APPL_CONST)BufferOffsetTable;
    /* The number of items in the configuration structure of the type Fr_CCLpduInfoType - i.e. the
    the number of virtual resources */
    CONST(uint16, FR_CONST)BuffersConfiguredCount;
    /* Data size - segment 1 */
    CONST(uint8, FR_CONST)MessageBufferSegment1DataSize;
    /* Data size - segment 2 */
    CONST(uint8, FR_CONST)MessageBufferSegment2DataSize;
    /* Last MB in segment 1 (Number of MB in Segment1 - 1) */
    CONST(uint8, FR_CONST)LastMBSEG1;
    /* Last individual MB;(Number of MB in Segment1 + Number of MB in Segment2 - 1) */
    CONST(uint8, FR_CONST)LastMBUTIL;
     /* Ch A, seg 1 - the initial index of the MB header field */
    CONST(uint8, FR_CONST)RSBIR_A1BufferIndexInit;
    /* Ch B, seg 1 - the initial index of the MB header field */
    CONST(uint8, FR_CONST)RSBIR_B1BufferIndexInit;
    /* Ch A, seg 2 - the initial index of the MB header field */
    CONST(uint8, FR_CONST)RSBIR_A2BufferIndexInit;
    /* Ch B, seg 2 - the initial index of the MB header field */
    CONST(uint8, FR_CONST)RSBIR_B2BufferIndexInit;
} Fr_CCBufferConfigSetType;

/***************************************************************************************************
* @struct Fr_CCLowLevelConfigSetType
*  @details The structure of the type Fr_CCLowLevelConfigSetType contains the FlexRay protocol
*   specific parameters. The configuration information corresponds with the contents of the FlexRay
*   module Protocol Configuration Registers (registers PCR0 to PCR30), the FlexRay Protocol
*   Specification, the AUTOSAR FlexRay Driver and the FlexRay Interface specifications. The FlexRay
*   Driver uses these values for Protocol Configuration Registers initialization and for internal
*   operations.
***************************************************************************************************/
typedef struct
{
    CONST(uint32, FR_CONST)RegPCR0_1;    /* Protocol Configuration Registers  0, 1 values */
    CONST(uint32, FR_CONST)RegPCR2_3;    /* Protocol Configuration Registers  2, 3 values */
    CONST(uint32, FR_CONST)RegPCR4_5;    /* Protocol Configuration Registers  4, 5 values */
    CONST(uint32, FR_CONST)RegPCR6_7;    /* Protocol Configuration Registers  6, 7 values */
    CONST(uint32, FR_CONST)RegPCR8_9;    /* Protocol Configuration Registers  8, 9 values */
    CONST(uint32, FR_CONST)RegPCR10_11;  /* Protocol Configuration Registers 10,11 values */
    CONST(uint32, FR_CONST)RegPCR12_13;  /* Protocol Configuration Registers 12,13 values */
    CONST(uint32, FR_CONST)RegPCR14_15;  /* Protocol Configuration Registers 14,15 values */
    CONST(uint32, FR_CONST)RegPCR16_17;  /* Protocol Configuration Registers 16,17 values */
    CONST(uint32, FR_CONST)RegPCR18_19;  /* Protocol Configuration Registers 18,19 values */
    CONST(uint32, FR_CONST)RegPCR20_21;  /* Protocol Configuration Registers 20,21 values */
    CONST(uint32, FR_CONST)RegPCR22_23;  /* Protocol Configuration Registers 22,23 values */
    CONST(uint32, FR_CONST)RegPCR24_25;  /* Protocol Configuration Registers 24,25 values */
    CONST(uint32, FR_CONST)RegPCR26_27;  /* Protocol Configuration Registers 26,27 values */
    CONST(uint32, FR_CONST)RegPCR28_29;  /* Protocol Configuration Registers 28,29 values */
    CONST(uint16, FR_CONST)RegPCR30;     /* Protocol Configuration Register 30 value */
    /* FlexRay parameter gNumberoftaticslots */
    CONST(uint16, FR_CONST)gNumberOfStaticSlots;
    /* FlexRay parameter gNetworkManagementVectorLength */
    CONST(uint8, FR_CONST)gNetworkManagementVectorLength;
    /* pPayloadLengthDynMax */
    CONST(uint8, FR_CONST)pPayloadLengthDynMax;
    /* gPayloadLengthStatic */
    CONST(uint8, FR_CONST)gPayloadLengthStatic;
} Fr_CCLowLevelConfigSetType;

/***************************************************************************************************
* @struct Fr_ConfigurationType
*  @details The structure of the type Fr_ConfigurationType is a top level descriptor containing
*   possible configurations of one FlexRay driver and one multiple configuration. The structure of
*   this type is passed via void pointer to the function Fr_Init().
***************************************************************************************************/
typedef struct
{
    /* Enable/Disable reporting of DEM messages */
    CONST(uint32, FR_CONST)state;
    /* ID of DEM message */
    CONST(uint32, FR_CONST)id;
} Fr_DemErrorType;
/***************************************************************************************************
* @struct Fr_ConfigurationType
*  @details The structure of the type Fr_ConfigurationType is a top level descriptor containing
*   possible configurations of one FlexRay driver and one multiple configuration. The structure of
*   this type is passed via void pointer to the function Fr_Init().
***************************************************************************************************/
typedef struct
{
    /* Reference to array of the Hardware Configuration structures */
    CONSTP2CONST(Fr_CCHardwareConfigType, FR_CONST, FR_APPL_CONST)CCHardwareConfigPtr;
    /* Reference to array of Buffer Configuration structures */
    CONSTP2CONST(Fr_CCBufferConfigSetType, FR_CONST, FR_APPL_CONST)BufferConfigSetPtr;
    /* Reference to array of Low Level Configuration structures */
    CONSTP2CONST(Fr_CCLowLevelConfigSetType, FR_CONST, FR_APPL_CONST)LowLevelConfigSetPtr;
    /* Reference to array of FlexRay Protocol Configuration parameters */
    CONSTP2CONST(uint32, FR_CONST, FR_APPL_CONST)CCReadBackConfigSetPtr;
    /* Referece to FrDemCtrlTestResult */
    CONSTP2CONST(Fr_DemErrorType, FR_CONST, FR_APPL_CONST)FrDemCtrlTestResultPtr;
} Fr_ConfigurationType;

/***************************************************************************************************
* @struct  Fr_CCTxBufferConfigType
*  @details The configuration information for each individual transmit message buffer is stored in a
*   separate instance of the type Fr_CCTxBufferConfigType. The address of each separate
*   structure of the type Fr_CCTxBufferConfigType should be passed into the relevant
*   @c BufferConfigPtr parameter of the configuration structure of the type Fr_CCLpduInfoType.
*  @par
*   The instance of the Fr_CCTxBufferConfigType structure is used by the Fr_ControllerInit(),
*   Fr_TransmitTxLPdu(), Fr_PrepareLPdu(), and Fr_CheckTxLPduStatus().
***************************************************************************************************/
typedef struct
{
    /* Transmit frame ID */
    CONST(uint16, FR_CONST)TxFrameID;
    /* Header CRC */
    CONST(uint16, FR_CONST)HeaderCRC;
    /* Payload length [in Words] */
    CONST(uint8, FR_CONST)TxPayloadLength;
    /* Transmission mode */
    CONST(boolean, FR_CONST)TxChannelAEnable;
    /* Transmit channel B enable */
    CONST(boolean, FR_CONST)TxChannelBEnable;
    /* Payload preamble */
    CONST(boolean, FR_CONST)PayloadPreamble;
     /* Transmit cycle counter filter enable */
    CONST(boolean, FR_CONST)TxCycleCounterFilterEnable;
    /* Transmit cycle counter filter value */
    CONST(uint8, FR_CONST)TxCycleCounterFilterValue;
    /* Transmit cycle counter filter mask */
    CONST(uint8, FR_CONST)TxCycleCounterFilterMask;
    /* Value of the FrIfAllowDynamicLSduLength parameter */
    CONST(boolean, FR_CONST)AllowDynamicLength;
    /* DemEventId */
    CONST(uint16, FR_CONST)DemFTSlotStatus;
    /* DemFTSlotSTatusRefExist exist */
    CONST(boolean, FR_CONST)DemFTSlotSTatusRefExist;
} Fr_CCTxBufferConfigType;

/***************************************************************************************************
* @struct Fr_CCRxBufferConfigType
*  @details The configuration information for each individual receive message buffer is stored in a
*   separate instance of the type Fr_CCRxBufferConfigType.
*  @par
*   The address of each separate structure of the type Fr_CCRxBufferConfigType should be
*   passed into the relevant BufferConfigPtr parameter of the configuration structure of the type
*   Fr_CCLpduInfoType.
*  @par
*   The instance of the Fr_CCRxBufferConfigType structure is used by the
*   Fr_ControllerInit(), Fr_ReceiveRxLPdu() and Fr_PrepareLPdu() functions.
*  @note  The receive shadow buffers have to be configured together with the receive message buffers
*   for correct FlexRay module operation in an instance of the Fr_CCBufferConfigSetType type.
***************************************************************************************************/
typedef struct
{
    /* Receive frame ID */
    CONST(uint16, FR_CONST)RxFrameID;
    /* Maximum payload length [in Words] - only for checking */
    CONST(uint8, FR_CONST)RxPayloadLength;
    /* Receive channel A enable */
    CONST(boolean, FR_CONST)RxChannelAEnable;
    /* Receive channel B enable */
    CONST(boolean, FR_CONST)RxChannelBEnable;
    /* Receive cycle counter filter enable */
    CONST(boolean, FR_CONST)RxCycleCounterFilterEnable;
    /* Receive cycle counter filter value */
    CONST(uint8, FR_CONST)RxCycleCounterFilterValue;
    /* Receive cycle counter filter mask */
    CONST(uint8, FR_CONST)RxCycleCounterFilterMask;
    /* DemEventId */
    CONST(uint16, FR_CONST)DemFTSlotStatus;
    /* DemFTSlotSTatusRefExist exist */
    CONST(boolean, FR_CONST)DemFTSlotSTatusRefExist;
} Fr_CCRxBufferConfigType;

/***************************************************************************************************
* @struct Fr_CCFifoRangeFiltersType
*  @details Up to four range filters for each FIFO can be configured. Each filter can be configured
*   either as acceptance or rejection selecting whether FlexRay frames within selected range are
*   received (accepted) into FIFO or not.
***************************************************************************************************/
typedef struct
{
    /* TRUE - Range Filter is enabled */
    CONST(boolean, FR_CONST)RangeFilterEnable;
    /* Acceptance or Rejection mode */
    CONST(Fr_CCFifoRangeFilterModeType, FR_CONST)RangeFilterMode;
     /* SID0 - Slot ID - Lower interval boundary */
    CONST(uint16, FR_CONST)RangeFilterLowerInterval;
    /* SID1 - Slot ID - Upper interval boundary */
    CONST(uint16, FR_CONST)RangeFilterUpperInterval;
} Fr_CCFifoRangeFiltersType;

/***************************************************************************************************
* @struct Fr_CCFifoConfigType
*  @details The configuration information for each FIFO storage is stored in a separate instance of
*   the type Fr_CCFifoConfigType. The address of each separate structure of the type
*   Fr_CCFifoConfigType should be passed into the relevant BufferConfigPtr parameter of the
*   configuration structure of the type Fr_CCLpduInfoType.
***************************************************************************************************/
typedef struct
{
    /* Selects the receive FIFO (FIFO A, FIFO B). */
    CONST(Fr_CCFifoChannelType, FR_CONST)FIFOChannel;
    /* Configures the index of the first FIFO message buffer.*/
    CONST(uint16, FR_CONST)FIFOStartIndex;
    /* Configures the FIFO depth. */
    CONST(uint8, FR_CONST)FIFODepth;
    /* Configures the FIFO entry size [in Words]. */
    CONST(uint8, FR_CONST)FIFOEntrySize;
    /* Message ID filter mask value */
    CONST(uint16, FR_CONST)MessageIDFilterMask;
    /* Message ID filter match value */
    CONST(uint16, FR_CONST)MessageIDFilterMatch;
    /* Contains range filters configuration. */
    CONST(Fr_CCFifoRangeFiltersType, FR_CONST)FIFORangeFiltersConfig[4];
} Fr_CCFifoConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define FR_START_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref FR_H_REF_1 */
#include "Fr_MemMap.h"

#if (FR_VARIANT_PRECOMPILE == STD_OFF)
/* @violates @ref FR_H_REF_3 */
FR_CONF_PB
#endif /* (FR_VARIANT_PRECOMPILE) */

#define FR_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/* @violates @ref FR_H_REF_1 */
#include "Fr_MemMap.h"

/* @violates @ref FR_H_REF_5 */
/* @violates @ref FR_H_REF_4 */
#define FR_START_SEC_VAR_NO_INIT_UNSPECIFIED
/* Covers FR112 */
/* @violates @ref FR_H_REF_1 */
#include "Fr_MemMap.h"

/* Pointer to configuration structure */
extern P2CONST(Fr_ConfigurationType, FR_VAR, FR_APPL_CONST) Fr_pCfgPtr;

/* @violates @ref FR_H_REF_5 */
#define FR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/* Covers FR112 */
/* @violates @ref FR_H_REF_1 */
#include "Fr_MemMap.h"

/* @violates @ref FR_H_REF_5 */
/* @violates @ref FR_H_REF_4 */
#define FR_START_SEC_VAR_INIT_UNSPECIFIED
/* Covers FR112 */
/* @violates @ref FR_H_REF_1 */
#include "Fr_MemMap.h"


#define FR_STOP_SEC_VAR_INIT_UNSPECIFIED
/* Covers FR112 */
/* @violates @ref FR_H_REF_1 */
#include "Fr_MemMap.h"

#define FR_START_SEC_VAR_INIT_16
/* @violates @ref FR_H_REF_1 */
/* @violates @ref FR_H_REF_6 */
#include "Fr_MemMap.h"

#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
    /* Only if FR_PREPARE_LPDU_SUPPORT is enabled: */
    /* Array is used for storage of information which virtual message buffer is currently configured
    for the physical message buffer each array element represents one physical MB and stored value
    corresponds with configured virtual MB index.
    Example: VirtualResourceAllocation[15] means that MB with index 15 (MBCCSR15,MBIDX15...) is
    configured for virtual MB with index 26 */
extern VAR(uint16, FR_VAR) Fr_VirtualResourceAllocation[FR_NUM_CTRL_SUPPORTED][FR_NUMBER_MB];
#endif  /* FR_PREPARE_LPDU_SUPPORT */

#define FR_STOP_SEC_VAR_INIT_16
/* Covers FR112 */
/* @violates @ref FR_H_REF_1 */
/* @violates @ref FR_H_REF_6 */
#include "Fr_MemMap.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define FR_START_SEC_CODE
/* @violates @ref FR_H_REF_1 */
#include "Fr_MemMap.h"

extern FUNC(void, FR_CODE) Fr_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC,FR_APPL_DATA) VersioninfoPtr);
/* Initialization */
extern FUNC(void, FR_CODE) Fr_Init(P2CONST(Fr_ConfigType, AUTOMATIC, FR_APPL_CONST) Fr_ConfigPtr);
extern FUNC(Std_ReturnType, FR_CODE) Fr_ControllerInit(VAR(uint8, AUTOMATIC) Fr_CtrlIdx);
/* Runtime configuration */
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetWakeupChannel(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(Fr_ChannelType, AUTOMATIC) Fr_ChnlIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_CancelTxLPdu(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx);
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, FR_CODE) Fr_PrepareLPdu(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx);
#endif
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReconfigLPdu(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx, VAR(uint16, AUTOMATIC) Fr_FrameId,
                                                     VAR(Fr_ChannelType, AUTOMATIC) Fr_ChnlIdx, VAR(uint8, AUTOMATIC) Fr_CycleRepetition,
                                                     VAR(uint8, AUTOMATIC) Fr_CycleOffset, VAR(uint8, AUTOMATIC) Fr_PayloadLength, VAR(uint16, AUTOMATIC) Fr_HeaderCRC
                                                    );
#endif
#if(FR_DISABLE_LPDU_SUPPORT == STD_ON)
extern FUNC(Std_ReturnType, FR_CODE) Fr_DisableLPdu(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx);
#endif
/* Transmit, receive */
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReceiveRxLPdu(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx,P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LSduPtr,
                                                      P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_LPduStatusPtr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_LSduLengthPtr
                                                     );
extern FUNC(Std_ReturnType, FR_CODE) Fr_TransmitTxLPdu(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx, P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) Fr_LSduPtr, VAR(uint8, AUTOMATIC) Fr_LSduLength);
extern FUNC(Std_ReturnType, FR_CODE) Fr_SendWUP(VAR(uint8, AUTOMATIC) Fr_CtrlIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetNmVector(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NmVectorPtr);
/* POC control */
extern FUNC(Std_ReturnType, FR_CODE) Fr_AbortCommunication(VAR(uint8, AUTOMATIC) Fr_CtrlIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_AllowColdstart(VAR(uint8, AUTOMATIC) Fr_CtrlIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_HaltCommunication(VAR(uint8, AUTOMATIC) Fr_CtrlIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_StartCommunication(VAR(uint8, AUTOMATIC) Fr_CtrlIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_AllSlots(VAR(uint8, AUTOMATIC) Fr_CtrlIdx);
/* CC status */
extern FUNC(Std_ReturnType, FR_CODE) Fr_CheckTxLPduStatus(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint16, AUTOMATIC) Fr_LPduIdx,P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) Fr_TxLPduStatusPtr);
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetPOCStatus(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, P2VAR(Fr_POCStatusType,AUTOMATIC, FR_APPL_DATA) Fr_POCStatusPtr);
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetSyncFrameList(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint8, AUTOMATIC) Fr_ListSize, 
                                                         P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAEvenListPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBEvenListPtr,
                                                         P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAOddListPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBOddListPtr
                                                        );
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetChannelStatus(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelAStatusPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_ChannelBStatusPtr);
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetWakeupRxStatus(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_WakeupRxStatusPtr);
/* Timers */
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetGlobalTime(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_CyclePtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) Fr_MacroTickPtr);
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetClockCorrection(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) Fr_RateCorrectionPtr, P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) Fr_OffsetCorrectionPtr);
extern FUNC(Std_ReturnType, FR_CODE) Fr_SetAbsoluteTimer(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx, VAR(uint8, AUTOMATIC) Fr_Cycle, VAR(uint16, AUTOMATIC) Fr_Offset);
extern FUNC(Std_ReturnType, FR_CODE) Fr_CancelAbsoluteTimer(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx);
/* Interrupt mode support */
extern FUNC(Std_ReturnType, FR_CODE) Fr_EnableAbsoluteTimerIRQ(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_AckAbsoluteTimerIRQ(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_DisableAbsoluteTimerIRQ(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx);
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetAbsoluteTimerIRQStatus(VAR(uint8, AUTOMATIC) Fr_CtrlIdx,VAR(uint8, AUTOMATIC) Fr_AbsTimerIdx, P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) Fr_IRQStatusPtr);
extern FUNC(Std_ReturnType, FR_CODE) Fr_ReadCCConfig(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, VAR(uint8, AUTOMATIC) Fr_ConfigParamIdx, P2VAR(uint32, AUTOMATIC, FR_APPL_DATA) Fr_ConfigParamValuePtr);
extern FUNC(Std_ReturnType, FR_CODE) Fr_GetNumOfStartupFrames(VAR(uint8, AUTOMATIC) Fr_CtrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) Fr_NumOfStartupFramesPtr);
#if(FR_DEINIT_API == STD_ON)
/* DeInitialization */
extern FUNC(void, FR_CODE) Fr_DeInit(void);
#endif

#define FR_STOP_SEC_CODE
/* @violates @ref FR_H_REF_1 */
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FR_H */
/* End of file */
