/**
*   @file    Spi_DSPI.h
*   @implements Spi_DSPI.h_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - DSPI LLD header file.
*   @details DSPI peripheral LLD header file.

*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : DSPI
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

#ifndef SPI_DSPI_H
#define SPI_DSPI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_DSPI_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_DSPI_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_DSPI_h_REF_3
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Spi_DSPI_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_DSPI_h_REF_5
* Violates MISRA 2004 Required Rule 8.8,
* An external object or function shall be declared in one and only one file.
*
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

#define SPI_VENDOR_ID_DSPI                    43
/*
* @violates @ref Spi_DSPI_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/

#define SPI_AR_RELEASE_MAJOR_VERSION_DSPI     4
/*
* @violates @ref Spi_DSPI_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_MINOR_VERSION_DSPI     2
/*
* @violates @ref Spi_DSPI_h_REF_4 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_DSPI  2
#define SPI_SW_MAJOR_VERSION_DSPI             1
#define SPI_SW_MINOR_VERSION_DSPI             0
#define SPI_SW_PATCH_VERSION_DSPI             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief  Map HWUnit to DSPI device structure.
*/
/*
* @violates @ref Spi_DSPI_h_REF_3 A function should be used in preference to a function-like macro.
*/

#define DSPI_HWUNIT2DSPI(HWUnit)    (&Spi_Dspi_aDeviceState[(HWUnit)])


#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief   This Macro shall set different MCU clock mode .
* @details This Macro shall set different MCU clock mode .
*
* @param[in]    ClockMode   Clock mode to be set.
*
* @pre  Pre-compile parameter SPI_DUAL_CLOCK_MODE shall be STD_ON.
*
*/
/*================================================================================================*/
/*
* @violates @ref Spi_DSPI_h_REF_3 A function should be used in preference to a function-like macro.
*/
#define DSPI_SET_CLOCK_MODE(ClockMode)  (Spi_Dspi_ClockMode = (ClockMode))

#endif /* #if (SPI_DUAL_CLOCK_MODE == STD_ON) */

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief   Internal structure keeping a set of cached channel attributes.
* @details Internal structure keeping a set of cached channel attributes
*          used by the optimized implementation of Spi_SyncTransmit() for
*          the sequences having only one job.
*/
typedef struct
{
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    /**< @brief Cached value of the CTAR register. */
    VAR(uint32, SPI_VAR) u32CTAR[2];
#else
    VAR(uint32, SPI_VAR) u32CTAR;
#endif
    /**< @brief Cached pointer to the buffer descriptor. */
    P2CONST(Spi_BufferDescriptorType, SPI_VAR, SPI_APPL_CONST) pcBufferDescriptor;
    /**< @brief Cached pointer to the channel states. */
    P2VAR(Spi_ChannelStateType, SPI_VAR, SPI_APPL_DATA) pState;
    /**< @brief Cached default transmit value. */
     VAR(Spi_DataBufferType, SPI_VAR) DefaultTransmitValue;
 #if (SPI_FORCE_DATA_TYPE == STD_ON)
    /**< @brief Channel attributes for data width. */
    VAR(uint8, SPI_VAR) u8DataWidth;
#endif
} Spi_Dspi_ChannelCacheAttrsType;

/**
* @brief    Internal structure keeping a set of cached sequences attributes.
* @details  Internal structure keeping a set of cached sequences attributes
*           used by the optimized implementation of Spi_SyncTransmit() for
*           the sequences having only one job.
*/
typedef struct
{
    /**< @brief Number of channels in sequence. */
    VAR(Spi_ChannelType, SPI_VAR) NumChannels;
    /**< @brief Cached pointer to the sequence job state. */
    P2VAR(Spi_JobStateType, SPI_VAR, SPI_APPL_DATA) pJobState;
    /**< @brief Cached pointer to the sequence DSPI state. */
    P2VAR(Spi_StatusType, SPI_VAR, SPI_APPL_DATA) pJobDspiStatus;
    /**< @brief Table of channel cached attributes. */
    P2VAR(Spi_Dspi_ChannelCacheAttrsType, SPI_VAR, SPI_APPL_DATA) pChannels;
    /**< @brief Cached value of the DSPI HW Unit memory mapped registers base address. */
    VAR(uint32, SPI_VAR) u32DspiBaseAddress;
    /**< @brief Cached value of CMD field of the SPI dataframes. */
    VAR(uint32, SPI_VAR) u32JobCMD;
    /**< @brief DSPI CTAR register address. */
    VAR(uint32, SPI_VAR) u32DspiCTARAddress;
} Spi_Dspi_SequenceCacheAttrsType;
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */

/**
* @brief This structure holds runtime configuration parameters for Spi handler.
*/
typedef struct
{
    /**< @brief Reference to the corresponding HWUnit config instance. */
    P2CONST(Spi_HWUnitConfigType, SPI_VAR, SPI_APPL_CONST) pcHWUnitConfig;
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
#if (SPI_DMA_USED == STD_ON)
    /**< @brief Internal buffer containing the command|data frame information for the last dataframe in job. */
    VAR(uint32, SPI_VAR) u32TxDmaBuffer;
    /**< @brief Internal buffer containing the command|data frame information for the last dataframe in job. */
    VAR(uint32, SPI_VAR) u32TxDmaBufferLast;
    /**< @brief Address of the default master TX DMA descriptor stored in memory. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) pu32TxDmaTcdDefault;
    /**< @brief Address of the TX DMA descriptor to be used for transfering the last job dataframe. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) pu32TxDmaTcdLast;
    /**< @brief Address of the master TX MMIO DMA descriptor. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) pu32TxDmaTcd;
    /**< @brief Address of the master RX MMIO DMA descriptor. */
    P2VAR(uint32, SPI_VAR, SPI_APPL_DATA) pu32RxDmaTcd;
    /**< @brief Cache of the e_link configuration part into the iteration field. */
    VAR(uint16, SPI_VAR) u16MinorELink;
#endif
    /**< @brief CTAR register used to define different transfer attributes for exeternal device. */
    VAR(uint32, SPI_VAR) u32ExternalDeviceCTAR;
    /**< @brief Position in ChannelIndexList to the channel in transmission. */
    P2CONST(Spi_ChannelType, SPI_VAR, SPI_APPL_CONST) pcCurrentChannelIndexPointer;
    /**< @brief Number of sent frames, which must be read back in the next ISR call. */
    VAR(Spi_NumberOfDataType, SPI_VAR) SentFrames;
    /**< @brief Reference to the current job. */
    P2CONST(Spi_JobConfigType, SPI_VAR, SPI_APPL_CONST) pcCurrentJob;
    /**< @brief Indicates if this is the last chunk of data in the job. */
    VAR(boolean, SPI_VAR) bIsEndOfJob;
#endif
    /**< @brief Pointer to the Tx buffer of the channel currently in transmission. */
     P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) pCurrentTxBuffer;
    /**< @brief Pointer to the Rx buffer of the channel currently in transmission. */
    P2VAR(Spi_DataBufferType, SPI_VAR, SPI_APPL_DATA) pCurrentRxBuffer;
     /**< @brief The frame command value to be used for the channel in transmission. */
    VAR(uint32, SPI_VAR) u32CurrentCmd;
    /**< @brief Number of channels in a pending job, not yet transmitted. */
    VAR(Spi_ChannelType, SPI_VAR) RemainingChannels;
    /**< @brief Number of frames in a pending channel, not yet transmitted. */
    VAR(Spi_NumberOfDataType, SPI_VAR) RemainingData;
    /**< @brief Memory mapped registers base address. */
    VAR(uint32, SPI_VAR) u32DspiBaseAddress;
    /**< @brief DSPI PUSHR register address. */
    VAR(uint32, SPI_VAR) u32DspiPUSHRAddress;
    /**< @brief DSPI POPR register address. */
    VAR(uint32, SPI_VAR) u32DspiPOPRAddress;
    /**< @brief DSPI Status register address. */
    VAR(uint32, SPI_VAR) u32DspiSRAddress;
    /**< @brief DSPI CTAR register address. */
    VAR(uint32, SPI_VAR) u32DspiCTARAddress;
    /**< @brief Asynchronous operating mode of the DSPI unit. */
    VAR(Spi_AsyncModeType, SPI_VAR) AsyncMode;
    /**< @brief Pointer to the Autosar HW unit SPI state. */
    P2VAR(Spi_StatusType, SPI_VAR, SPI_APPL_DATA) pStatus;
    VAR(Spi_NumberOfDataType, SPI_VAR) ReceivedData;
    /**< @brief Flag that indicates a poll request */
    VAR(uint8, SPI_VAR) u8IsPollRequest;
} Spi_Dspi_DeviceStateType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_DSPI_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/

 #include "Spi_MemMap.h"
 

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief    Pointer table to the cached information structure
* @details  Pointer table to the cached information structure, for one job sequences,
*           or NULL, for unoptimized sequences.
*/
extern P2VAR(Spi_Dspi_SequenceCacheAttrsType, AUTOMATIC, SPI_VAR) Spi_Dspi_apOneJobSeqsOptimized[SPI_MAX_SEQUENCE];
#endif

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief Holds the mode of the Dual Clock.
*/
extern VAR(Spi_DualClockModeType, AUTOMATIC) Spi_Dspi_ClockMode;
#endif

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_DSPI_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))) 
/*
* @violates @ref Spi_DSPI_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
 
/*
* @violates @ref Spi_DSPI_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief Keep the HWUnit internal fields.
*/
/*
* @violates @ref Spi_DSPI_h_REF_5 An external object or function shall be declared in one and
* only one file
*/
extern VAR(Spi_Dspi_DeviceStateType, SPI_VAR) Spi_Dspi_aDeviceState[SPI_MAX_HWUNIT];

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))    
/*
* @violates @ref Spi_DSPI_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/    
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_DSPI_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_DSPI_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
FUNC(void, SPI_CODE) Spi_Dspi_Init
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus
    );

FUNC(void, SPI_CODE) Spi_Dspi_DeInit
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    );

#if (((SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0)) && \
    (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
FUNC(void, SPI_CODE) Spi_Dspi_PrepareCacheInformation(void);
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
FUNC(Std_ReturnType, SPI_CODE) Spi_Dspi_SyncTransmit
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence
    );
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
FUNC(Std_ReturnType, SPI_CODE) Spi_Dspi_SyncTransmit_Fast
    (
        P2CONST(Spi_Dspi_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    );
#endif
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_Dspi_JobTransfer
    (
        P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_Dspi_IrqConfig
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_Dspi_IrqPoll
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_Dspi_IsrFifoRx
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev,
        VAR(uint8, AUTOMATIC) u8HWoffset
    );
#endif

#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
FUNC(void, SPI_CODE) Spi_Dspi_SlaveCancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence);
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC(void, SPI_CODE) Spi_Dspi_IsrDmaRx
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    );
#endif
#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
FUNC(void, SPI_CODE) Spi_Dspi_SetTSBMode
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob
    );

FUNC(void, SPI_CODE) Spi_Dspi_StopTSBMode
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob
    );

FUNC(void, SPI_CODE) Spi_Dspi_TSB_ASDR_DataUpdate
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob,
        P2CONST(uint32, AUTOMATIC,SPI_APPL_DATA) ASDR_Data
    );
#endif /*(SPI_TSB_MODE == STD_ON)*/
#endif /*TSB_MODE_SUPPORTED*/

#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_DSPI_h_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
*
* @violates @ref Spi_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif

#endif /* SPI_DSPI_H */

/** @} */

