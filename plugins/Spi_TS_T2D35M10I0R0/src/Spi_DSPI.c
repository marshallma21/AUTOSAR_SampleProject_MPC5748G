/**
*   @file    Spi_DSPI.c
*   @implements Spi_DSPI.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - DSPI low-level driver implementations.
*   @details DSPI low-level driver implementations.
*
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

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, Names of new objects shall be checked in order to
* not cause confusion with standard object names.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_DSPI_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_DSPI_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_DSPI_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type.
*
* @section Spi_DSPI_c_REF_4
* Violates MISRA 2004 Advisory Rule 11.4,
* A cast should not be performed between a pointer to object type and a different pointer to object type.
* Casts between (uint8*) and (uint32*) are used for optimizing the memory accesses.
*
* @section Spi_DSPI_c_REF_5
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope shall have
* internal linkage unless external linkage is required.
* Structure shall be public as it is used by Reg_eSys_DSPI.h which may be sed outside DSPI module.
*
* @section Spi_DSPI_c_REF_6
* Violates MISRA 2004 Required Rule 17.4,
* Array indexing shall be the only allowed form of pointer arithmetic.
* Gain in generated code speed
*
* @section Spi_DSPI_c_REF_8
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity are
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_DSPI_c_REF_11
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope if they are only accessed from within a single function.
* The variables are defined globally for performance reasons.
*
* @section Spi_DSPI_c_REF_12
* Violates MISRA 2004 Advisory Rule 11.3,
* A cast should not be performed between a pointer type and an integral type.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Spi.h"
#include "Spi_DSPI.h"
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/*
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Dem.h"
#endif

#include "Reg_eSys_DSPI.h"
#if (SPI_DMA_USED == STD_ON)
#include "CDD_Mcl.h"
#endif

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_VENDOR_ID_DSPI_C                    43
/*
* @violates @ref Spi_DSPI_c_REF_8 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers.
*/

#define SPI_AR_RELEASE_MAJOR_VERSION_DSPI_C         4
/*
* @violates @ref Spi_DSPI_c_REF_8 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_MINOR_VERSION_DSPI_C         2
/*
* @violates @ref Spi_DSPI_c_REF_8 The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_DSPI_C      2
#define SPI_SW_MAJOR_VERSION_DSPI_C                 1
#define SPI_SW_MINOR_VERSION_DSPI_C                 0
#define SPI_SW_PATCH_VERSION_DSPI_C                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi.h are of the same vendor */
#if (SPI_VENDOR_ID_DSPI_C != SPI_VENDOR_ID)
    #error "Spi.h and Spi_DSPI.c have different vendor ids"
#endif
/* Check if Spi_DSPI.c file and Spi.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_DSPI_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_DSPI_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_DSPI_C != SPI_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Spi_Dspi.c and Spi.h are different"
#endif
#if ((SPI_SW_MAJOR_VERSION_DSPI_C  != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_DSPI_C  != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_DSPI_C  != SPI_SW_PATCH_VERSION))
#error "Software Version Numbers of Spi_Dspi.c and Spi.h are different"
#endif

/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_VENDOR_ID_DSPI_C != SPI_VENDOR_ID_DSPI)
    #error "Spi_DSPI.c and Spi_DSPI.h have different vendor ids"
#endif
/* Check if Spi_DSPI.c file and Spi_DSPI.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_DSPI_C    != SPI_AR_RELEASE_MAJOR_VERSION_DSPI) || \
     (SPI_AR_RELEASE_MINOR_VERSION_DSPI_C    != SPI_AR_RELEASE_MINOR_VERSION_DSPI) || \
     (SPI_AR_RELEASE_REVISION_VERSION_DSPI_C != SPI_AR_RELEASE_REVISION_VERSION_DSPI))
#error "AutoSar Version Numbers of Spi_Dspi.c and Spi_DSPI.h are different"
#endif
#if ((SPI_SW_MAJOR_VERSION_DSPI_C  != SPI_SW_MAJOR_VERSION_DSPI) || \
     (SPI_SW_MINOR_VERSION_DSPI_C  != SPI_SW_MINOR_VERSION_DSPI) || \
     (SPI_SW_PATCH_VERSION_DSPI_C  != SPI_SW_PATCH_VERSION_DSPI))
#error "Software Version Numbers of Spi_Dspi.c and Spi_Dspi.h are different"
#endif

/* Check if this header file and Reg_eSys_DSPI.h are of the same vendor */
#if (SPI_VENDOR_ID_DSPI_C != SPI_VENDOR_ID_REGFLEX)
    #error "Spi_DSPI.c and Reg_eSys_DSPI.h have different vendor ids"
#endif
/* Check if Spi_DSPI.c file and Reg_eSys_DSPI.h file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_DSPI_C    != SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_MINOR_VERSION_DSPI_C    != SPI_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (SPI_AR_RELEASE_REVISION_VERSION_DSPI_C != SPI_AR_RELEASE_REVISION_VERSION_REGFLEX))
#error "AutoSar Version Numbers of Spi_Dspi.c and Reg_eSys_DSPI.h are different"
#endif
#if ((SPI_SW_MAJOR_VERSION_DSPI_C  != SPI_SW_MAJOR_VERSION_REGFLEX) || \
     (SPI_SW_MINOR_VERSION_DSPI_C  != SPI_SW_MINOR_VERSION_REGFLEX) || \
     (SPI_SW_PATCH_VERSION_DSPI_C  != SPI_SW_PATCH_VERSION_REGFLEX))
#error "Software Version Numbers of Spi_Dspi.c and Reg_eSys_DSPI.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_DSPI_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_AR_RELEASE_MINOR_VERSION_DSPI_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_Dspi.c and Mcal.h are different"
    #endif

#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_DSPI_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_AR_RELEASE_MINOR_VERSION_DSPI_C  != DEM_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_Dspi.c and Dem.h are different"
    #endif
#endif

#if (SPI_DMA_USED == STD_ON)
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_DSPI_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
        (SPI_AR_RELEASE_MINOR_VERSION_DSPI_C  != MCL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_Dspi.c and CDD_Mcl.h are different"
    #endif
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define DSPI_DMA_MAX_LINKED_ITER_CNT  (0x1FFu)

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
/**
* @brief Pool of cached information for sequences having only one job.
*/
static VAR(Spi_Dspi_SequenceCacheAttrsType, SPI_VAR)
/*
* @violates @ref Spi_DSPI_c_REF_11 the variables are defined globally for
* performance reasons.
*/
    Spi_Dspi_aSeqsAttributes[SPI_OPTIMIZED_SEQ_BUFFER_SIZE];

/**
* @brief Pool of cached information for sequences having only one job.
*/
static VAR(Spi_Dspi_ChannelCacheAttrsType, SPI_VAR)
/*
* @violates @ref Spi_DSPI_c_REF_11 the variables are defined globally for
* performance reasons.
*/
    Spi_Dspi_aChannelsAttributes[SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE];
#endif /* (SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))

/**
* @brief DMA TCD descriptors for scatter / gather DMA transmissions
* @note  This buffers must be alligned at 32bytes.
* @note  lint tool detection failed due to macro usage.
*        Conform with MISRA 2004 Required Rules 8.10 (local variable must be
*        defined as static)
*/
ALIGNED_VARS_START(ex_var, 32)
/*
* @violates @ref Spi_DSPI_c_REF_11 the variables are defined globally for
* performance reasons.
*/
VAR_ALIGN(static VAR(uint8, SPI_VAR) Spi_Dspi_au8DmaTcdTxArray[SPI_MAX_HWUNIT][32], 32)
/*
* @violates @ref Spi_DSPI_c_REF_11 the variables are defined globally for
* performance reasons.
*/
VAR_ALIGN(static VAR(uint8, SPI_VAR) Spi_Dspi_au8DmaTcdTxLastArray[SPI_MAX_HWUNIT][32], 32)
ALIGNED_VARS_STOP()

/**
* @brief DMA TCD descriptor global variable (used to avoid MISRA 1.2 rule error).
*/
/*
* @violates @ref Spi_DSPI_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(Mcl_DmaTcdAttributesType, AUTOMATIC) Spi_Dspi_DmaCfgDesc;

#endif  /* SPI_DMA_USED == STD_ON */



#define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_32
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief DSPI base address array.
*/
/*
* @violates @ref Spi_DSPI_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
CONST(uint32, SPI_CONST) Spi_Dspi_au32BaseAddrs[13] =
{
    #ifdef  DSPI0_BASEADDR
        DSPI0_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI1_BASEADDR
        DSPI1_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI2_BASEADDR
        DSPI2_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI3_BASEADDR
        DSPI3_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI4_BASEADDR
        DSPI4_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI5_BASEADDR
        DSPI5_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI6_BASEADDR
        DSPI6_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI7_BASEADDR
        DSPI7_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI8_BASEADDR
        DSPI8_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI9_BASEADDR
        DSPI9_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI10_BASEADDR
        DSPI10_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI11_BASEADDR
        DSPI11_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif
    #ifdef  DSPI12_BASEADDR
        DSPI12_BASEADDR
    #else
        ((uint32)0x00000000UL)
    #endif

};

#define SPI_STOP_SEC_CONST_32
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
                                    GLOBAL VARIABLES
==================================================================================================*/
#define SPI_START_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*
* @violates @ref Spi_DSPI_c_REF_11 the variables are defined globally for
* performance reasons.
*/
static VAR(volatile uint32, SPI_VAR) Spi_Dspi_u32ReadDiscard;

#define SPI_STOP_SEC_VAR_NO_INIT_32
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#define SPI_START_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief       Holds the mode of the Dual Clock.
* @details       This structure is used to store runtime internal state parameters
*              for the DSPI IP peripheral.
*
*/
VAR(Spi_DualClockModeType, SPI_VAR) Spi_Dspi_ClockMode = SPI_NORMAL;
#endif

#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief         Pointer table to the cached information structure, for one job
*             sequences, or NULL, for unoptimized sequences.
* @details    Internal structure keeping a set of cached sequences attributes
*               used by the optimized implementation of Spi_SyncTransmit() for the
*              sequences having only one job.
*
*/
/*
* @violates @ref Spi_DSPI_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
P2VAR(Spi_Dspi_SequenceCacheAttrsType, SPI_VAR, SPI_APPL_DATA) Spi_Dspi_apOneJobSeqsOptimized[SPI_MAX_SEQUENCE]={NULL_PTR};
#endif

#define SPI_STOP_SEC_VAR_INIT_UNSPECIFIED
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))) 
/*
* @violates @ref Spi_DSPI_c_REF_8 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_START_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */
 
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/**
* @brief Keep the HWUnit internal fields.
*
*/
/*
* @violates @ref Spi_DSPI_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
VAR(Spi_Dspi_DeviceStateType, SPI_VAR) Spi_Dspi_aDeviceState[SPI_MAX_HWUNIT];

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))    
/*
* @violates @ref Spi_DSPI_c_REF_8 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/    
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
#else
    #define SPI_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_InitDma
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_DmaIrqConfig
    (
        P2CONST(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) pcDspiDev,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_ChannelTransferFifoInit
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev,
        VAR(Spi_ChannelType, AUTOMATIC) Channel
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_JobTransferFifoDrain
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    );
#endif

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_JobTransferFifoFill
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_ChannelTransferDmaInit
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev,
        VAR(Spi_ChannelType, AUTOMATIC) Channel
    );
#endif

#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_JobTransferDmaContinue
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    );
#endif

#ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
#if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
static FUNC(void, SPI_CODE) Spi_Dspi_TransferDmaContinue
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    );
#endif
#endif
#endif

#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_Dspi_SyncTransmitChannel
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev,
        VAR(Spi_ChannelType, AUTOMATIC) Channel
    );
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Initialize DMA related fields for a DSPI unit.
* @details Initialize DMA TCD descriptors static fields.
*
* @param[in]     HWUnit      Specifies which DSPI peripheral is used.
* @param[in]     pDspiDev     LLD instance of the given DSPI peripheral.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_InitDma
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    )
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;

    /* initialize cache values */
    pDspiDev->pu32TxDmaTcdDefault =
    /*
    * @violates @ref Spi_DSPI_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))Spi_Dspi_au8DmaTcdTxArray[HWUnit];

    pDspiDev->pu32TxDmaTcdLast =
    /*
    * @violates @ref Spi_DSPI_c_REF_4 A cast should not be performed between a pointer
    *       to object type and a different pointer to object type.
    */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))Spi_Dspi_au8DmaTcdTxLastArray[HWUnit];
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    */
    /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    pcHWUnitConfig = pDspiDev->pcHWUnitConfig;
    pDspiDev->pu32TxDmaTcd =
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        /*
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))Mcl_DmaGetChannelTcdAddress(pcHWUnitConfig->u8TxDmaChannel);
    pDspiDev->pu32RxDmaTcd =
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        */
        /*
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        (P2VAR(uint32, AUTOMATIC, SPI_APPL_DATA))Mcl_DmaGetChannelTcdAddress(pcHWUnitConfig->u8RxDmaChannel);

    /* store DMA Minor ELink configuration for future usage */
    pDspiDev->u16MinorELink = (uint16)pcHWUnitConfig->u8TxDmaChannelAux;

    /* configure TX Channel 1 to write data frames (16bits) to u32TxDmaBuffer */
    Spi_Dspi_DmaCfgDesc.u32saddr = (uint32) 0u; /* will be updated later */
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    Spi_Dspi_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_1BYTE; /* 1bytes src transfer size */
    Spi_Dspi_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_1BYTE; /* 1bytes dest transfer size */
    Spi_Dspi_DmaCfgDesc.u32num_bytes = 1u;          /* bytes to transfer */
    Spi_Dspi_DmaCfgDesc.u32soff  = DMA_OFFSET_8_BITS;  /* src offset */
        #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Spi_Dspi_DmaCfgDesc.u32daddr = (uint32)(&pDspiDev->u32TxDmaBuffer); /* dest address */
        #else
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Spi_Dspi_DmaCfgDesc.u32daddr = (uint32)(&pDspiDev->u32TxDmaBuffer)+3u; /* dest address */
        #endif
    #else
    Spi_Dspi_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_2BYTES;
    Spi_Dspi_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_2BYTES;
    Spi_Dspi_DmaCfgDesc.u32soff  = DMA_OFFSET_16_BITS;
    Spi_Dspi_DmaCfgDesc.u32num_bytes = 2u;          /* bytes to transfer */
        #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Spi_Dspi_DmaCfgDesc.u32daddr = (uint32)(&pDspiDev->u32TxDmaBuffer); /* dest address */
        #else
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    */
    /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Spi_Dspi_DmaCfgDesc.u32daddr = (uint32)(&pDspiDev->u32TxDmaBuffer)+2u; /* dest address */
        #endif
    #endif
    Spi_Dspi_DmaCfgDesc.u32doff  = 0u;  /* no dest offset */
    Spi_Dspi_DmaCfgDesc.u32smod  = 0u;  /* no source address modulo */
    Spi_Dspi_DmaCfgDesc.u32dmod  = 0u;  /* no dest address modulo   */
    Spi_Dspi_DmaCfgDesc.u32iter  = 1u;  /* iteration count          */

    Mcl_DmaConfigScatterGatherLinkedTcd(pDspiDev->pu32TxDmaTcd, &Spi_Dspi_DmaCfgDesc, pDspiDev->pu32TxDmaTcdDefault, pcHWUnitConfig->u8TxDmaChannelAux);
    Mcl_DmaTcdSetLinkAndIterCount(pDspiDev->pu32TxDmaTcd, (Mcl_ChannelType)pcHWUnitConfig->u8TxDmaChannelAux, (uint16)0u);
    Mcl_DmaTcdSetFlags(pDspiDev->pu32TxDmaTcd, (uint8)(DMA_TCD_MAJOR_E_LINK_U32 | DMA_TCD_E_SG_U32));    
 
    /* duplicate in memory TX Channel 1 TCD, for final restore */
    Mcl_DmaConfigScatterGatherLinkedTcd(pDspiDev->pu32TxDmaTcdDefault, &Spi_Dspi_DmaCfgDesc, pDspiDev->pu32TxDmaTcdDefault, pcHWUnitConfig->u8TxDmaChannelAux);
    Mcl_DmaTcdSetLinkAndIterCount(pDspiDev->pu32TxDmaTcdDefault, (Mcl_ChannelType)pcHWUnitConfig->u8TxDmaChannelAux, (uint16)0u);
    Mcl_DmaTcdSetFlags(pDspiDev->pu32TxDmaTcdDefault, (uint8)(DMA_TCD_MAJOR_E_LINK_U32 | DMA_TCD_E_SG_U32) );     
 
    /* configure TX Channel 2 to write u32TxDmaBuffer (32bits) to DSPI PUSHR */
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    /*
     * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
     * a pointer to a function and any type other than an integral type.
     */
    /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Spi_Dspi_DmaCfgDesc.u32saddr = (uint32) (&pDspiDev->u32TxDmaBuffer); /* src address read */
    Spi_Dspi_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_4BYTES; /* 4bytes src transfer size */
    Spi_Dspi_DmaCfgDesc.u32soff  = 0u;               /* no src offset */
    Spi_Dspi_DmaCfgDesc.u32smod  = 0u;  /* no source address modulo */
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    Spi_Dspi_DmaCfgDesc.u32daddr = (uint32)(pDspiDev->u32DspiPUSHRAddress);/* dest address */ 
    Spi_Dspi_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_4BYTES; /* 4bytes dest transfer size */
    Spi_Dspi_DmaCfgDesc.u32doff  = 0u;     /* no dest offset */
    Spi_Dspi_DmaCfgDesc.u32dmod  = 0u;     /* no dest address modulo   */
    Spi_Dspi_DmaCfgDesc.u32num_bytes = 4u; /* bytes to transfer */
    Spi_Dspi_DmaCfgDesc.u32iter  = 1u;     /* iteration count          */
    /*
     * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
     * a pointer to a function and any type other than an integral type.
     */
     /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaConfigTcd((Mcl_DmaTcdType *)Mcl_DmaGetChannelTcdAddress(pcHWUnitConfig->u8TxDmaChannelAux), &Spi_Dspi_DmaCfgDesc);  
    /*
     * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
     * a pointer to a function and any type other than an integral type.
     */
     /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaTcdSetFlags((Mcl_DmaTcdType *)Mcl_DmaGetChannelTcdAddress(pcHWUnitConfig->u8TxDmaChannelAux), (uint8)DMA_TCD_DISABLE_REQ_U32 );       
    
    /* setup scatter/gather TCD */
    /* S/G to the original DMA TCD => reload the initial values */
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    /*
     * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
     * a pointer to a function and any type other than an integral type.
     */
    /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Spi_Dspi_DmaCfgDesc.u32saddr = (uint32) (&pDspiDev->u32TxDmaBufferLast); /* src address read */
    Spi_Dspi_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_4BYTES; /* 4bytes src transfer size */
    Spi_Dspi_DmaCfgDesc.u32soff  = 0u;               /* no src offset */
    Spi_Dspi_DmaCfgDesc.u32smod  = 0u;  /* no source address modulo */
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    /*
     * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
     * a pointer to a function and any type other than an integral type.
     */
     /*
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Spi_Dspi_DmaCfgDesc.u32daddr = (uint32)(&pDspiDev->u32TxDmaBuffer); /* dest address */ 
    Spi_Dspi_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_4BYTES; /* 4bytes dest transfer size */
    Spi_Dspi_DmaCfgDesc.u32doff  = 0u;     /* no dest offset */
    Spi_Dspi_DmaCfgDesc.u32dmod  = 0u;     /* no dest address modulo   */
    Spi_Dspi_DmaCfgDesc.u32num_bytes = 4u; /* bytes to transfer */
    Spi_Dspi_DmaCfgDesc.u32iter  = 1u;     /* iteration count          */
    Mcl_DmaConfigScatterGatherLinkedTcd(pDspiDev->pu32TxDmaTcdLast, &Spi_Dspi_DmaCfgDesc, pDspiDev->pu32TxDmaTcdDefault, pcHWUnitConfig->u8TxDmaChannelAux);
    Mcl_DmaTcdSetFlags(pDspiDev->pu32TxDmaTcdLast,  (uint8) (DMA_TCD_MAJOR_E_LINK_U32 | DMA_TCD_DISABLE_REQ_U32 | DMA_TCD_E_SG_U32 ));    
    
    /* setup RX DMA channel */
    /* configure TX Channel 1 to write data frames (16bits) to u32TxDmaBuffer */
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    Spi_Dspi_DmaCfgDesc.u32saddr = (uint32)(pDspiDev->u32DspiPOPRAddress); /* data only read */
        #else
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    Spi_Dspi_DmaCfgDesc.u32saddr = (uint32)(pDspiDev->u32DspiPOPRAddress)+3u; /* data only read */
        #endif
    Spi_Dspi_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_1BYTE; /* 1bytes src transfer size */
    Spi_Dspi_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_1BYTE; /* 1bytes dest transfer size */
    Spi_Dspi_DmaCfgDesc.u32doff  = DMA_OFFSET_8_BITS;  /* no dest offset */
    Spi_Dspi_DmaCfgDesc.u32num_bytes = 1u;          /* bytes to transfer */
    #else
        #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    Spi_Dspi_DmaCfgDesc.u32saddr = (uint32)(pDspiDev->u32DspiPOPRAddress); /* data only read */
        #else
    /* Compiler_Warning: It is intended for the address of the element to be stored
                          in another non pointer element*/
    Spi_Dspi_DmaCfgDesc.u32saddr = (uint32)(pDspiDev->u32DspiPOPRAddress)+2u; /* data only read */
        #endif
    Spi_Dspi_DmaCfgDesc.u32ssize = (uint32)DMA_SIZE_2BYTES;
    Spi_Dspi_DmaCfgDesc.u32dsize = (uint32)DMA_SIZE_2BYTES;
    Spi_Dspi_DmaCfgDesc.u32doff  = DMA_OFFSET_16_BITS; /* no dest offset */
    Spi_Dspi_DmaCfgDesc.u32num_bytes = 2u;          /* bytes to transfer */
    #endif
    Spi_Dspi_DmaCfgDesc.u32soff  = 0u;  /* src offset */
    Spi_Dspi_DmaCfgDesc.u32daddr = 0u;  /* dest address => will be updated later */

    Spi_Dspi_DmaCfgDesc.u32smod  = 0u;  /* no source address modulo */
    Spi_Dspi_DmaCfgDesc.u32dmod  = 0u;  /* no dest address modulo   */
    Spi_Dspi_DmaCfgDesc.u32iter  = 0u;  /* beg maj iter cnt => will be updated later */

    /* !!!! Not able to set the e-link */
    Mcl_DmaConfigTcd(pDspiDev->pu32RxDmaTcd, &Spi_Dspi_DmaCfgDesc);
    Mcl_DmaTcdSetFlags(pDspiDev->pu32RxDmaTcd,  (uint8)DMA_TCD_DISABLE_REQ_U32);  

}
#endif /* (SPI_DMA_USED == STD_ON) */

/*================================================================================================*/
/**
* @brief   Configures DMA interrupts for the Rx channel.
* @details Activate RX channel interrupt in interrupt mode or disable then
*          in polling mode.
*
* @param[in]     pcDspiDev     LLD instance of the given DSPI peripheral.
* @param[in]     AsyncMode   Operation mode (SPI_INTERRUPT_MODE | SPI_POLLING_MODE).
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_DmaIrqConfig
    (
        P2CONST(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_CONST) pcDspiDev,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    )
{
    /* start RX before TX! */
    if (SPI_INTERRUPT_MODE == AsyncMode)
    {
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIntMaj(pcDspiDev->pu32RxDmaTcd);
    }
    else
    {
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdClearIntMaj(pcDspiDev->pu32RxDmaTcd);
    }
}
#endif /* (SPI_DMA_USED == STD_ON) */

/*================================================================================================*/
/**
* @brief   This function initializes channel related informations in DSPI HW Unit structure.
* @details The function must be called before starting the async transfer of a
*          channel
*
*     Configuration characteristics:
*     - TxDma1 fills the Data part (16bits) of a TxBuffer (32 bits), with the
*       command field set by this function
*     - TxDma1 is daisy chained with TxDma2 which transfers the TxBuffer content
*       to the DSPI PUSHR register.
*     - At the end of TxDma1 transmission, one of the following may happen:
*         -> a dedicated descriptor is loaded through scatter/gather into the
*            channel TCD, in order to transfer the last dataframe which will
*            deassert the CS signal (for end of job channels - see picture below)
*         -> the default Tx descriptor is reloaded through scatter/gather into
*            the channel TCD, in order to facilitate the next transmission
*            configuration; transmission session not started for this descriptor
*            (for not end of job channels, or for channels having the size of 1.)
*         -> the scatter/gather link is disabled, and the DMA transmission ends,
*            conserving the actual Spi Tx/Rx Buffer pointers (for long channels,
*            which need to be transferred in many datachunck of
*            DSPI_DMA_MAX_LINKED_ITER_CNT)
*
* 1) DMA configuration for the transmission of the last channel in job
*    - for this situation, the last frame will be sent using a distinct DMA
*      descriptor, as it should manage the CS deassertion into the command field.
*
*     SpiTxBuffer
*          |
*          V
*     ,---------,     DMA.E_LINK
*     | TX DMA1 |.......................
*     |         |>-------,             :
*     '---------'        |             :
*      :DMA.S_G          |16bits       :
*      :                 |             :
*      : u32TxDmaBufferLast |             :
*      :     |           |             :
*      V     V           |             :
*     ,---------,        |  DMA.E_LINK V
*     | TX DMA  |.......................
*     |  Last   |>--,    |             :
*     '---------'   |    |             :
*                   |    |             :
*             32bits|    V             :
*                   V /----\           :
*                /---------\           V
*   u32TxDmaBuffer: |Cmd |Data|      ,---------,
*                \---------/      | TX DMA2 |
*                     '---------->|         |---->DSPI.PUSHR
*                         32bits  '---------'
*                                                             ,---------,
*                                                 DSPI.POPR-->| RX DMA  |
*                                                             |         |
*                                                             '---------'
*                                                                  |
*                                                                  V
*                                                             SpiRxBuffer
*
* 2) DMA configuration for the transmission of a not final job channel, or
*    for channels having only one dataframe.
*    - all transmission is managed through the DMA TX descriptor in place;
*      reload only the default DMA descriptor
*
*     SpiTxBuffer
*          |
*          V
*     ,---------,     DMA.E_LINK
*     | TX DMA1 |.......................
*     |         |>-------,             :
*     '---------'        |             :
*          :DMA.S_G      |16bits       :
*          :             |             :
*          :             |             :
*          :             |             :
*          V             |             :
*     ,---------,        |             :
*     | TX DMA  |        |             :
*     | Default |        |             :
*     '---------'        |             :
*                        |             :
*                        |             :
*                        V             :
*                     /----\           V
*   u32TxDmaBuffer: |Cmd |Data|      ,---------,
*                \---------/      | TX DMA2 |
*                     '---------->|         |---->DSPI.PUSHR
*                         32bits  '---------'
*                                                             ,---------,
*                                                 DSPI.POPR-->| RX DMA  |
*                                                             |         |
*                                                             '---------'
*                                                                  |
*                                                                  V
*                                                             SpiRxBuffer
*
* 3) DMA configuration for the transmission of long jobs
*    - same picture as (2) but without any scatter/gather chaining;
*    - then the transmission is finished, the Tx channel descriptor
*      will conserve the Rx/Tx Spi buffer pointers
*
* As the Tx / Rx channel descriptors are already preset with some values, this
* function updates only:
* - Tx descriptor: - source address (Spi Tx Buffer)
*                  - DMA major iteration count (derived from channel size)
*                  - scattered/gathered DMA descriptor address
*                    (TxDmaLast or TxDmaDefault)
*                  - flags (S/G & DREQ activation)
* - Rx descriptor: - destination address (Spi Rx Buffer)
*                  - DMA major iteration count (channel size)
*
* @param[in]     pDspiDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmited.
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_ChannelTransferDmaInit
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev,
        VAR(Spi_ChannelType, AUTOMATIC) Channel
    )
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
        pcDspiChannelAttributesConfig;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig =
        &(*Spi_pcSpiConfigPtr->pcChannelConfig)[Channel];
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) pChannelState =
        pcChannelConfig->pChannelState;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pBufferRX;
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pBufferTX;
     VAR(Spi_NumberOfDataType, AUTOMATIC) FramesCount;
    VAR(uint8, AUTOMATIC) u8CsClearNeeded = (uint8)FALSE;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) pTxTcdAddr = pDspiDev->pu32TxDmaTcd;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) pRxTcdAddr = pDspiDev->pu32RxDmaTcd;
    VAR(uint8, AUTOMATIC) u8SgaFlag = (uint8)DMA_TCD_E_SG_U32;
    
    /* Set the CTAR parameters for this channel */
    pcDspiChannelAttributesConfig = &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)[Channel];
    /* set CTAR register */
    /*
    * @remarks The call is blocking till the HWUnit exits the running state.
    */
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(pDspiDev->u32DspiCTARAddress,(pDspiDev->u32ExternalDeviceCTAR |pcDspiChannelAttributesConfig->u32CMD));

    FramesCount = pChannelState->Length;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
    {
        FramesCount /= 2u;
    }
    else
    {
        /* Do nothing */
    }
#endif
#ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
#if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
    /* Store the number of frames will be sent in high speed mode */
    pDspiDev->SentFrames = FramesCount;
    pDspiDev->ReceivedData = 0u;
#endif
#endif
    /* identify the TX/RX buffers and update them into the DMA TCDs */
    if (0u != (pChannelState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8)))
    {
        /* update source address into the DMA TCD */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSaddr(pTxTcdAddr, (uint32)(&pcChannelConfig->DefaultTransmitValue));

        /* overwrite the default src next offset */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSoff(pTxTcdAddr, (sint16)0u /* no src offset */);
        pDspiDev->u32TxDmaBufferLast = ((pDspiDev->u32CurrentCmd & ~DSPI_CONT_MASK_U32) | pcChannelConfig->DefaultTransmitValue);
    #ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
    #if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
        /* Backup the TX address for future */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        pDspiDev->pCurrentTxBuffer = (Spi_DataType*)(pcChannelConfig->DefaultTransmitValue);
    #endif
    #endif
    }
    else
    {
        pBufferTX = pcChannelConfig->pcBufferDescriptor->pBufferTX;
        
    #ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
    #if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
        /* Backup the TX address for future */
        pDspiDev->pCurrentTxBuffer = pcChannelConfig->pcBufferDescriptor->pBufferTX;
    #endif
    #endif 
        /* configure TX Channel 1 to write data frames (8 or 16bits - depending on Spy_DataType) to
           u32TxDmaBuffer */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSaddr(pTxTcdAddr, (uint32)pBufferTX);

        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
        {
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            /* 2 bytes src offset */
            Mcl_DmaTcdSetSoff(pTxTcdAddr, (sint16)2u);
            Mcl_DmaTcdSetSModuloAndSize(pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(pTxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetDaddr(pTxTcdAddr, (uint32)(&pDspiDev->u32TxDmaBuffer));
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetDaddr(pTxTcdAddr, (uint32)(&pDspiDev->u32TxDmaBuffer)+2u);
            #endif
            /* 2 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else
        {
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* 1 bytes src offset */
            Mcl_DmaTcdSetSoff(pTxTcdAddr, (sint16)1u);
            Mcl_DmaTcdSetSModuloAndSize(pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            Mcl_DmaTcdSetDModuloAndSize(pTxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);

            /* dest address */
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetDaddr(pTxTcdAddr, (uint32)(&pDspiDev->u32TxDmaBuffer));
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetDaddr(pTxTcdAddr, (uint32)(&pDspiDev->u32TxDmaBuffer)+3u);
            #endif

            /* 1 bytes to transfer */
            Mcl_DmaTcdSetMinorLoop(pTxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }
        #endif
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth )
        {
            pDspiDev->u32TxDmaBufferLast = 
                ((pDspiDev->u32CurrentCmd & ~DSPI_CONT_MASK_U32) |
                #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
                /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                ((uint32)(pBufferTX[pChannelState->Length -1u])<<8u) |
                /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                  (uint32)pBufferTX[pChannelState->Length - 2u] 
                );
                #else
                /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                ((uint32)(pBufferTX[pChannelState->Length -2u])<<8u) |
                /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                  (uint32)pBufferTX[pChannelState->Length - 1u] 
                );
                #endif
        }
        else
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pDspiDev->u32TxDmaBufferLast = ((pDspiDev->u32CurrentCmd & ~DSPI_CONT_MASK_U32) | pBufferTX[FramesCount-1u]);
        }
        #else
        /*
        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pDspiDev->u32TxDmaBufferLast = ((pDspiDev->u32CurrentCmd & ~DSPI_CONT_MASK_U32) | pBufferTX[FramesCount-1u]);
        #endif
    }

    /* prepare the command in the intermediate buffer */
    pDspiDev->u32TxDmaBuffer = pDspiDev->u32CurrentCmd;

    /* get the number of frames to be sent through DMA */
    if ( DSPI_DMA_MAX_LINKED_ITER_CNT < FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        pDspiDev->RemainingData = FramesCount - DSPI_DMA_MAX_LINKED_ITER_CNT;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
        {
            pDspiDev->RemainingData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        FramesCount = DSPI_DMA_MAX_LINKED_ITER_CNT;

        /* S/G linking must be disabled in this case;
        The actual TCD must be in place till the last DMA chunk will
        be finished */
        u8SgaFlag = 0u;
        /* reset dest address adjustment */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSga(pTxTcdAddr, 0u);
    }
    else
    {
        pDspiDev->RemainingData = 0u;

        /* identify if CS clearing will be needed at the channel end */
        if (0u == pDspiDev->RemainingChannels)
        {
            if (1u == FramesCount)
            {   /* clear the CS assertion directly into the next TX frame */
                pDspiDev->u32TxDmaBuffer &= ~DSPI_CONT_MASK_U32;
            }
            else
            {   /* the last dataframe must be sent in a distinct TCD */
                u8CsClearNeeded = (uint8)TRUE;
            }
        }
    }

    /* Configure RX DMA descriptor */
    /* Rx buffer will be NULL if discarding read values */
    pBufferRX = pcChannelConfig->pcBufferDescriptor->pBufferRX;
    
    #ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
    #if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
        /* Backup the RX address for future */
        pDspiDev->pCurrentRxBuffer = pcChannelConfig->pcBufferDescriptor->pBufferRX;
    #endif
    #endif  
    
    if (NULL_PTR == pBufferRX)
    {
        /* dest address - discard read */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */

        Mcl_DmaTcdSetDaddr(pRxTcdAddr, (uint32) &Spi_Dspi_u32ReadDiscard);

        /* update RX transfer size; no offset for destination address */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIterCount(pRxTcdAddr, (uint16)(FramesCount));
        Mcl_DmaTcdSetDoff(pRxTcdAddr, (sint16)0u);
    }
    else
    {
        /* dest address - RX buffer */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetDaddr(pRxTcdAddr, (uint32)pBufferRX);
        /* update RX transfer size; 2bytes offset for destination address */
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
        {
            /* update RX transfer size; 2bytes offset for destination address */
            /*
             * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
             * a pointer to a function and any type other than an integral type.
             * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
             */
            Mcl_DmaTcdSetIterCount(pRxTcdAddr, (uint16)(FramesCount));
            Mcl_DmaTcdSetDoff(pRxTcdAddr, (sint16)2u);
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(pRxTcdAddr, (uint32)(pDspiDev->u32DspiPOPRAddress));
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(pRxTcdAddr, (uint32)(pDspiDev->u32DspiPOPRAddress)+2u);
            #endif
            /* overwrite the default src next offset */
            /* 2 bytes src transfer size, 2 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            Mcl_DmaTcdSetDModuloAndSize(pRxTcdAddr, (uint8)0x00u, DMA_SIZE_2BYTES);
            /* 2 bytes to transfer */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x02u));
        }
        else
        {
            /* update RX transfer size; 1bytes offset for destination address */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetIterCount(pRxTcdAddr, (uint16)(FramesCount));
            Mcl_DmaTcdSetDoff(pRxTcdAddr, (sint16)1u);
            #if (CPU_BYTE_ORDER==LOW_BYTE_FIRST)
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(pRxTcdAddr, (uint32)(pDspiDev->u32DspiPOPRAddress));
            #else
            /* Compiler_Warning: It is intended for the address of the element to be passed
                                  to the function as an unsigned integer*/
            Mcl_DmaTcdSetSaddr(pRxTcdAddr, (uint32)(pDspiDev->u32DspiPOPRAddress)+3u);
            #endif
            /* overwrite the default src next offset */
            /* 1 bytes src transfer size, 1 bytes dest transfer size */
            /* no src offset */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetSoff(pRxTcdAddr, (sint16)0u);
            Mcl_DmaTcdSetSModuloAndSize(pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE );
            Mcl_DmaTcdSetDModuloAndSize(pRxTcdAddr, (uint8)0x00u, DMA_SIZE_1BYTE);
            /* 1 bytes to transfer */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetMinorLoop(pRxTcdAddr, (boolean)FALSE, (boolean)FALSE, (sint32)0u, (uint32)(0x01u));
        }
        #else
          /* update RX transfer size; 2bytes offset for destination address */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIterCount(pRxTcdAddr, (uint16)(FramesCount));
        Mcl_DmaTcdSetDoff(pRxTcdAddr, (sint16)2u);
        #endif
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetIterCount(pRxTcdAddr, (uint16)(FramesCount));        
    }

    /* configure or not scatter/gather related informations */
    if (u8CsClearNeeded)
    {
        /* if Cs clearing is needed, last dataframe will be transmitted using
        a distinct TCD.
        */

        /* update transfer size */
        FramesCount = (uint16)(FramesCount-1u);
        
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetLinkAndIterCount(pTxTcdAddr, (Mcl_ChannelType)pDspiDev->u16MinorELink, (uint16)(FramesCount)); 


        /* flags are set by default to DMA_TCD_MAJOR_E_LINK_U32 | DMA_TCD_SGA */
        /* update S/G address with the address of the CS clearing TCD */
        /* Compiler_Warning: It is intended for the address of the element to be passed
                              to the function as an unsigned integer*/
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
         Mcl_DmaTcdSetSga(pTxTcdAddr, (uint32)pDspiDev->pu32TxDmaTcdLast);
    }
    else
    {
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetLinkAndIterCount(pTxTcdAddr, (Mcl_ChannelType)pDspiDev->u16MinorELink, (uint16)(FramesCount)); 

        /* S/G address set by default to reload the default TX1 TCD */
        /* setup flags */
        /* reset DONE flag (quicker than LLM_Wr_DMA_CDNE()) */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetFlags(pTxTcdAddr, (uint8)0u);
        Mcl_DmaTcdSetFlags(pTxTcdAddr,
            (uint8)(DMA_TCD_DONE_U32 | DMA_TCD_MAJOR_E_LINK_U32 | DMA_TCD_DISABLE_REQ_U32 | u8SgaFlag));
    }

    /* start RX before TX! */
    pcHWUnitConfig = pDspiDev->pcHWUnitConfig;
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(pcHWUnitConfig->u8RxDmaChannel);

    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(pcHWUnitConfig->u8TxDmaChannel);

}
#endif /* SPI_DMA_USED == STD_ON */

/*================================================================================================*/
/**
* @brief   Restart the DMA transmission, refreshing the size.
* @details Source and destination addresses are already set into the active TCDs.
*
* @param[in]     pDspiDev      Specifies which DSPI module is used
*
* @pre The function can be called only if Spi_Dspi_JobTransferDmaStart() was
*      previously called to initialize the DMA configuration.
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_JobTransferDmaContinue
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    )
{
    VAR(Spi_NumberOfDataType, AUTOMATIC) FramesCount;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
      pcDspiChannelAttributesConfig = &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)[*(pDspiDev->pcCurrentChannelIndexPointer)];
#endif
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) pTxTcdAddr = pDspiDev->pu32TxDmaTcd;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) pRxTcdAddr = pDspiDev->pu32RxDmaTcd;
    
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
    {
        FramesCount = pDspiDev->RemainingData / 2u;
    }
    else
    {
        FramesCount = pDspiDev->RemainingData;
    }
    #else
    FramesCount = pDspiDev->RemainingData;
    #endif

    /* get the number of frames to be sent through DMA */
    if ( DSPI_DMA_MAX_LINKED_ITER_CNT < FramesCount)
    {
        /* DMA iteration count is on 9 bits, if e_link field is used */
        pDspiDev->RemainingData = FramesCount - DSPI_DMA_MAX_LINKED_ITER_CNT;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
        {
            pDspiDev->RemainingData *= 2u;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        FramesCount = DSPI_DMA_MAX_LINKED_ITER_CNT;

        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update RX transfer size */
        Mcl_DmaTcdSetIterCount(pRxTcdAddr, (uint16)(FramesCount)); 
    }
    else
    {
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update RX transfer size */
        Mcl_DmaTcdSetIterCount(pRxTcdAddr, (uint16)(FramesCount)); 

        pDspiDev->RemainingData = 0u;

        /* identify if CS clearing will be needed at the channel end */
        if ( 0u == pDspiDev->RemainingChannels )
        {
            if (1u == FramesCount)
            {   
                /* clear the CS assertion directly into the next TX frame */
                pDspiDev->u32TxDmaBuffer &= ~DSPI_CONT_MASK_U32;
                /* set S/G address to reload the default TX1 descriptor, at the end*/
                /* Compiler_Warning: It is intended for the address of the element to be passed
                                      to the function as an unsigned integer*/
                /*
                * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                Mcl_DmaTcdSetSga(pTxTcdAddr, (uint32)pDspiDev->pu32TxDmaTcdDefault);
                /* reset DONE flag */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */                
                Mcl_DmaTcdSetFlags(pTxTcdAddr, (uint8)0u);
                /* enable scatter/gather link and conserve the E_LINK setting;
                - DMA REQ must be disabled at the end of the current
                transfer, in order to stop the transfer before the reload of
                the default TCD
                */
                Mcl_DmaTcdSetFlags(pTxTcdAddr, (uint8)(DMA_TCD_MAJOR_E_LINK_U32 | DMA_TCD_E_SG_U32 | DMA_TCD_DISABLE_REQ_U32));
            }
            else
            {   /* last dataframe will be transmited using a distinct TCD. */
                /* Compiler_Warning: It is intended for the address of the element to be passed
                                      to the function as an unsigned integer*/
                /*
                * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                 Mcl_DmaTcdSetSga(pTxTcdAddr, (uint32)pDspiDev->pu32TxDmaTcdLast);
                
                /* reset DONE flag (quicker than LLM_Wr_DMA_CDNE()) */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                Mcl_DmaTcdSetFlags(pTxTcdAddr, (uint8)0u);
                  /* enable scatter/gather link and conserve the E_LINK setting;
                - DMA REQ must not be disabled at the end of the current
                transfer, in order to allow the execution of the linked SG
                */
                 Mcl_DmaTcdSetFlags(pTxTcdAddr, (uint8)(DMA_TCD_MAJOR_E_LINK_U32 | DMA_TCD_E_SG_U32));
                FramesCount--;
            }
        }
        else
        {
            /* Do nothing */
        }
    }

    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaTcdSetLinkAndIterCount(pTxTcdAddr, (Mcl_ChannelType)pDspiDev->u16MinorELink, (uint16)(FramesCount)); 

    /* start RX before TX! */
    pcHWUnitConfig = pDspiDev->pcHWUnitConfig;
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(pcHWUnitConfig->u8RxDmaChannel);
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    Mcl_DmaEnableHwRequest(pcHWUnitConfig->u8TxDmaChannel);
}
#endif

/*================================================================================================*/
/**
* @brief   This function initializes channel related informations in DSPI HW Unit structure.
* @details The function must be called before starting the async transfer of a
*          channel.
*
* @param[in]     pDspiDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmitted.
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_ChannelTransferFifoInit
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev,
        VAR(Spi_ChannelType, AUTOMATIC) Channel
    )
{
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) 
        pcDspiChannelAttributesConfig;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig;
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) pChannelState;

    pcChannelConfig = &(*Spi_pcSpiConfigPtr->pcChannelConfig)[Channel];
    pChannelState = pcChannelConfig->pChannelState;
    pDspiDev->RemainingData = pChannelState->Length;
    pDspiDev->ReceivedData = pChannelState->Length;

    /* identify the TX/RX buffers */
    if (0u != (pChannelState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8)))
    {
        pDspiDev->pCurrentTxBuffer = NULL_PTR;

        /* integrate default transmit value in the command */
        pDspiDev->u32CurrentCmd = (pDspiDev->u32CurrentCmd & DSPI_TX_CMD_MASK_U32) | pcChannelConfig->DefaultTransmitValue;
    }
    else
    {
        pDspiDev->pCurrentTxBuffer = pcChannelConfig->pcBufferDescriptor->pBufferTX;

        /* remove default transmit value from the command, if previously set */
        pDspiDev->u32CurrentCmd &= DSPI_TX_CMD_MASK_U32;
    }

    /* Rx buffer will be NULL if discarding read values */
    pDspiDev->pCurrentRxBuffer = pcChannelConfig->pcBufferDescriptor->pBufferRX;

    /* Set the CTAR parameters for this channel */
    pcDspiChannelAttributesConfig = &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)[Channel];

    /*
    * @note False detection of MISRA 2004 Rule 11.4 violation.
    *       (cast from pointer to pointer)
    */
    /* set CTAR register */
    /**
    * @note The call is blocking till the HWUnit exits the running state.
    */
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(pDspiDev->u32DspiCTARAddress,(pDspiDev->u32ExternalDeviceCTAR | pcDspiChannelAttributesConfig->u32CMD));

#if (SPI_SLAVE_SUPPORT == STD_ON)
    if(SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        /*
         * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
         *     type and an integral type.
         * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
         */
        REG_BIT_SET32(DSPI_RSER_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset), DSPI_RSER_RFDF_RE_MASK_U32);
    }
    else
    {
        /* Do nothing */
    }
#endif
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function fills the DSPI FIFO.
* @details This function fills DSPI FIFO Transmit buffer with the
*          predefined data assigned or transmit the default
*          buffer values in case of the lack of transmit
*          data buffer.
*
* @param[in]     pDspiDev     Specifies which DSPI module is used
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_JobTransferFifoFill
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    )
{
    VAR(uint32, AUTOMATIC) u32Cmd;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pBufferTX;
     VAR(Spi_NumberOfDataType, AUTOMATIC) nFramesCount;
    VAR(Spi_NumberOfDataType, AUTOMATIC) nRemainingData;
    VAR(uint8, AUTOMATIC) u8EndOfJob = (uint8)FALSE; /* end of job */
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
        pcDspiChannelAttributesConfig = &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)[*(pDspiDev->pcCurrentChannelIndexPointer)];
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pu16BufferFullTX;
#endif
    /* Get physical device handler */
    VAR(uint32, AUTOMATIC) u32DspiPUSHRAddress = pDspiDev->u32DspiPUSHRAddress;

    /* Get Channel Attributes */
    u32Cmd = pDspiDev->u32CurrentCmd;    

#if (SPI_SLAVE_SUPPORT == STD_ON)
    /* calculate the number of frames to be sent and the 'end of job' state */
    nFramesCount = pDspiDev->RemainingData;
    
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
        {
            nFramesCount/=2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
    
    if(SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        if(nFramesCount > SPI_FIFO_SIZE)
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            nFramesCount = (Spi_NumberOfDataType)((uint32)SPI_FIFO_SIZE - DSPI_SR_TXCTR_VAL_U32(REG_READ32(DSPI_SR_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset))));
        }
        else
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            if(nFramesCount > (SPI_FIFO_SIZE - DSPI_SR_TXCTR_VAL_U32(REG_READ32(DSPI_SR_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset)))))
            {
               /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                nFramesCount = (Spi_NumberOfDataType)((uint32)SPI_FIFO_SIZE - DSPI_SR_TXCTR_VAL_U32(REG_READ32(DSPI_SR_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset))));
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else
    {
#endif
        nFramesCount = 1u;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
            if(SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
            {
                /* The number of remaining data must be even */
                nRemainingData = 2u;
            }
            else
            {
                nRemainingData = 1u;
            }
        #else
            nRemainingData = 1u;
        #endif
    
        if((0u == (uint32)(pDspiDev->RemainingChannels)) && (nRemainingData == pDspiDev->RemainingData))
        {
            u8EndOfJob = (uint8)TRUE;
        }
        else
        {
            u8EndOfJob = (uint8)FALSE;
        }
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif

    pBufferTX = pDspiDev->pCurrentTxBuffer;
    pDspiDev->RemainingData -= nFramesCount;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    if(SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
    {
        pDspiDev->RemainingData -= nFramesCount;
    }
    else
    {
        /* Do nothing */
    }
    #endif
    pDspiDev->SentFrames = nFramesCount;

    if (NULL_PTR != pBufferTX)
    {
        /* set the new TX buffer pointer */
        /*
        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pDspiDev->pCurrentTxBuffer += nFramesCount;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pDspiDev->pCurrentTxBuffer += nFramesCount;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        /* write the information from the buffer */
        while (nFramesCount > 0u)
        {
            nFramesCount--;

            if (0u == nFramesCount)
            {
                /* Force the CS disabling if last data unit
                for the last channel of the Job */
                if (u8EndOfJob)
                {
                    /* signal the end of job for the current DSPI Unit */
                    pDspiDev->bIsEndOfJob = (boolean)TRUE;
                    u32Cmd = u32Cmd & ~DSPI_CONT_MASK_U32; /* clear the continuous CS assertion */
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }

            #if (SPI_FORCE_DATA_TYPE == STD_ON)
            if( SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
            {
                /*
                * @violates @ref Spi_DSPI_c_REF_4 A cast should not be performed between a
                * pointer to object type and a different pointer to object type.
                */
                pu16BufferFullTX = (uint16 *) pBufferTX;
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(u32DspiPUSHRAddress, (u32Cmd | *pu16BufferFullTX));
                /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                pBufferTX++;
            }
            else
            {
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(u32DspiPUSHRAddress, (u32Cmd | *pBufferTX));
            }
            #else
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(u32DspiPUSHRAddress, (u32Cmd | *pBufferTX));
            #endif
            /*
            * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pBufferTX++;
        }
    }
    else
    {   /* write the default value */
        while (nFramesCount > 0u)
        {
            nFramesCount--;

            if (0u == nFramesCount)
            {
                /* Force the CS disabling if last data unit
                for the last channel of the Job */
                if (u8EndOfJob)
                {
                    /* signal the end of job for the current DSPI Unit */
                    pDspiDev->bIsEndOfJob = (boolean)TRUE;
                    u32Cmd = u32Cmd & ~DSPI_CONT_MASK_U32; /* clear the continuous CS assertion */
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(u32DspiPUSHRAddress, u32Cmd);
        }
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function drains the DSPI FIFO.
* @details This function retrieves the received data from DSPI FIFO.
*
* @param[in]     pDspiDev     Specifies which DSPI module is used.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
LOCAL_INLINE FUNC(void, SPI_CODE) Spi_Dspi_JobTransferFifoDrain
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    )
{
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pBufferRx;
     VAR(Spi_NumberOfDataType, AUTOMATIC) nFramesCount = 0U;
    VAR(uint32, AUTOMATIC) u32DspiPOPRAddress = pDspiDev->u32DspiPOPRAddress;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
        pcDspiChannelAttributesConfig = &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)[*(pDspiDev->pcCurrentChannelIndexPointer)];
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pu16BufferFullRX;
    #endif
    #if (SPI_SLAVE_SUPPORT == STD_ON)
    VAR(Spi_NumberOfDataType, AUTOMATIC) DiscardFramesCount = 0U;
    #endif
    VAR(Spi_NumberOfDataType, AUTOMATIC) TempFramesCount = 0U;
    
    if( SPI_MASTER == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode )
    {
        /* Master mode */
        nFramesCount = pDspiDev->SentFrames;
    }
    else
    {
        /* Slave mode */
        #if (SPI_SLAVE_SUPPORT == STD_ON)
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        nFramesCount = (Spi_NumberOfDataType)DSPI_SR_RXCTR_VAL_U32(REG_READ32(DSPI_SR_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset)));

        /* Check if the received data fits into the remaining buffer space */
        if( pDspiDev->ReceivedData < nFramesCount )
        {
            /* Too much data, buffer overflow detected */

            /* Set the number of frames to be discarded */
            DiscardFramesCount = nFramesCount - pDspiDev->ReceivedData;
            /* Set the number of frames received to the remaining length of the buffer */
            nFramesCount = pDspiDev->ReceivedData;
            /* Set the remaining length of the buffer to 0 */
            pDspiDev->ReceivedData = 0u;
            
        }
        else
        {
            /* No overflow detected, continue normal flow */
            pDspiDev->ReceivedData -= nFramesCount;
            /* Set no frames to discard */
            DiscardFramesCount = 0u;
        }
        #endif
    }

    pBufferRx = pDspiDev->pCurrentRxBuffer;

    if (NULL_PTR != pBufferRx)
    {
        /* set the new RX buffer pointer */
        /*
        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pDspiDev->pCurrentRxBuffer += nFramesCount;
        #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if(SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pDspiDev->pCurrentRxBuffer += nFramesCount;
        }
        else
        {
            /* Do nothing */
        }
        #endif
        /* Save nFramesCount to TempFramesCount for compare by do{}while */
        TempFramesCount = nFramesCount;
        /* read the deserialized information */
        do
        {
        #if (SPI_SLAVE_SUPPORT == STD_ON)
            if(0u != nFramesCount)
            {
        #endif
            #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if(SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_4 A cast should not be performed between a
                    * pointer to object type and a different pointer to object type.
                    */
                    pu16BufferFullRX = (uint16 *) pBufferRx;
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    *pu16BufferFullRX = (uint16)REG_READ32(u32DspiPOPRAddress);
                    /*
                    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pBufferRx += 2u;
                }
                else
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                     *pBufferRx = (Spi_DataBufferType)REG_READ32(u32DspiPOPRAddress);
                     /*
                    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pBufferRx++;
                }
            #else
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                 *pBufferRx = (Spi_DataBufferType)REG_READ32(u32DspiPOPRAddress);
                 /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                pBufferRx++;
                #endif
                nFramesCount--;
        #if (SPI_SLAVE_SUPPORT == STD_ON)
            }
        #endif
        } while ((0u < nFramesCount) && (nFramesCount < TempFramesCount));  /* TX_FIFO_SIZE =4 */
        /* update current RX buffer pointer */
        pDspiDev->pCurrentRxBuffer = pBufferRx;

#if (SPI_SLAVE_SUPPORT == STD_ON)
        if( SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
        {
            /* Check if there are any frames to discard */
            if(0u != DiscardFramesCount)
            {
                /* Save DiscardFramesCount to TempFramesCount for use compare by do{}while */
                TempFramesCount = DiscardFramesCount;
                /* Discard all the surplus frames */
                do
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    Spi_Dspi_u32ReadDiscard = REG_READ32(u32DspiPOPRAddress);
                    DiscardFramesCount--;
                }
                while((DiscardFramesCount>0u) && (DiscardFramesCount<TempFramesCount));
            }
            else
            {
                /* Do nothing */
            }

            if((Spi_NumberOfDataType)0u == pDspiDev->ReceivedData)
            {
                pDspiDev->bIsEndOfJob = (boolean)1;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
#endif
    }
    else
    {
        /* Save nFramesCount to TempFramesCount for use compare by do{}while */
        TempFramesCount = nFramesCount;
        /* discard the information read */
        do
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Spi_Dspi_u32ReadDiscard = REG_READ32(u32DspiPOPRAddress);
            nFramesCount--;
        } while ((0u < nFramesCount) && (nFramesCount < TempFramesCount));
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
#if ((SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON))
/*================================================================================================*/
/**
* @brief   Low-level initialize function.
* @details Computes sequence / job configuration parameters like
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          This cached values will be used in sync transmissions in
*          order to optimize the time.
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall not be LEVEL1.
* @pre  Pre-compile parameter SPI_OPTIMIZE_ONE_JOB_SEQUENCES shall be STD_ON.
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Dspi_PrepareCacheInformation(void)
{
    VAR(Spi_ChannelType, AUTOMATIC) Channel;
    VAR(Spi_ChannelType, AUTOMATIC) ChannelId;
    VAR(Spi_JobType, AUTOMATIC) Job;
    VAR(uint32, AUTOMATIC) u32Sequence;
    P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev;
    P2VAR(Spi_Dspi_ChannelCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) pChannelAttrs;
    P2VAR(Spi_Dspi_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) pSeqAttrs;
    P2CONST(Spi_Ipw_DeviceAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) pcDeviceAttributesConfig;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequenceConfig;
    VAR(uint32, AUTOMATIC) u32SelectedCTAR;
    /* index to the first free entry in 'Spi_Dspi_aSeqsAttributes' table. */
    VAR(Spi_SequenceType, AUTOMATIC) SeqsAttrCurrentIndex = 0u;
    /* index to the first free entry in 'Spi_Dspi_aChannelsAttributes' table. */
    VAR(Spi_ChannelType, AUTOMATIC) ChannelsAttrCurrentIndex = 0u;

    /* reset all sequences as not optimized */
    for (u32Sequence = 0u; u32Sequence <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Sequence); u32Sequence++)
    {
        Spi_Dspi_apOneJobSeqsOptimized[u32Sequence] = NULL_PTR;
    }

    for (u32Sequence = 0u; u32Sequence <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Sequence); u32Sequence++)
    {
        pcSequenceConfig = &(*Spi_pcSpiConfigPtr->pcSequenceConfig)[u32Sequence];
        /* only one job sequences can be optimized */
        if (1u == pcSequenceConfig->NumJobs)
        {
            Job = (*pcSequenceConfig->pcJobIndexList)[0];
            pcJobConfig = &(*Spi_pcSpiConfigPtr->pcJobConfig)[Job];
            pDspiDev = &Spi_Dspi_aDeviceState[pcJobConfig->HWUnit];
            /* Generate CTAR selection */
            u32SelectedCTAR = DSPI_GENERATE_CTAR_U32((uint32)pDspiDev->pcHWUnitConfig->u8NrOfCTAR);

            /* check if enough place in the cached data channel pool */
            if (pcJobConfig->NumChannels <= (SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE-ChannelsAttrCurrentIndex))
            {
                /* get the first empty entry in the sequence pool and
                link it to the sequence */
                pSeqAttrs = &Spi_Dspi_aSeqsAttributes[SeqsAttrCurrentIndex];
                Spi_Dspi_apOneJobSeqsOptimized[u32Sequence] = pSeqAttrs;

                /* retrieve the device configuration for the sequence */
                pcDeviceAttributesConfig =
                    &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig)
                        [(*Spi_pcSpiConfigPtr->pcJobConfig)[Job].ExternalDevice];

                /* prepare sequence cache information */
                pSeqAttrs->NumChannels = pcJobConfig->NumChannels;
                pSeqAttrs->pJobState = &Spi_aSpiJobState[Job];
                pSeqAttrs->u32DspiBaseAddress = Spi_Dspi_aDeviceState[pcJobConfig->HWUnit].u32DspiBaseAddress;
                pSeqAttrs->pJobDspiStatus = Spi_Dspi_aDeviceState[pcJobConfig->HWUnit].pStatus;
                pSeqAttrs->u32JobCMD = pcDeviceAttributesConfig->u32CMD | u32SelectedCTAR;
                pSeqAttrs->u32DspiCTARAddress = pDspiDev->u32DspiCTARAddress;

                /* set the link to the first cached channel entry */
                pSeqAttrs->pChannels = &Spi_Dspi_aChannelsAttributes[ChannelsAttrCurrentIndex];

                /* prepare channel cache information */
                for (Channel = 0u; Channel < pcJobConfig->NumChannels; Channel++)
                {
                    ChannelId = (*pcJobConfig->pcChannelIndexList)[Channel];
                    pcChannelConfig = &(*Spi_pcSpiConfigPtr->pcChannelConfig)[ChannelId];
                    /*
                    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pChannelAttrs = &pSeqAttrs->pChannels[Channel];
                    pChannelAttrs->DefaultTransmitValue = pcChannelConfig->DefaultTransmitValue;
                    pChannelAttrs->pState = pcChannelConfig->pChannelState;
                    pChannelAttrs->pcBufferDescriptor = pcChannelConfig->pcBufferDescriptor;
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
                    pChannelAttrs->u32CTAR[0] =
                        (*Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig)
                            [pcJobConfig->ExternalDevice].u32CTAR[0]
                        |
                        (*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)
                            [ChannelId].u32CMD;
                    pChannelAttrs->u32CTAR[1] =
                        (*Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig)
                            [pcJobConfig->ExternalDevice].u32CTAR[1]
                        |
                        (*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)
                            [ChannelId].u32CMD;
#else
                    pChannelAttrs->u32CTAR =
                        (*Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig)
                            [pcJobConfig->ExternalDevice].u32CTAR
                        |
                        (*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)
                            [ChannelId].u32CMD;
#endif
#if (SPI_FORCE_DATA_TYPE == STD_ON)
                    pChannelAttrs->u8DataWidth =
                        (*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)
                            [ChannelId].u8DataWidth;
#endif
                } /* for (channels) */

                /* set the pool indexes to the new empty entries */
                SeqsAttrCurrentIndex++;
                ChannelsAttrCurrentIndex += pcJobConfig->NumChannels;

                /* end the loop if caches are full */
                if(
                    (SeqsAttrCurrentIndex >= SPI_OPTIMIZED_SEQ_BUFFER_SIZE)||
                    (ChannelsAttrCurrentIndex >= SPI_OPTIMIZED_CHANNEL_BUFFER_SIZE)
                  )
                {
                    break; /* end the loop */
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    } /* for (sequences) */
}
#endif /* (SPI_LEVEL_DELIVERED != LEVEL1) && (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */

/*================================================================================================*/
/**
* @brief   Low-level initialize function.
* @details Initialize the specific Spi unit with all configuration
*          parameters like Baud Rate, CS, Clock polarity, etc.
*          Also this function initializes all structure parameters
*          from the specific DSPI unit.
*
* @param[in]      HWUnit      Specifies which DSPI peripheral is used
* @param[in]      AsyncMode   operation mode
*                             (SPI_INTERRUPT_MODE | SPI_POLLING_MODE)
* @param[in]      pStatus     pointer to the Autosar SPI HWUnit State
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Dspi_Init
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        P2VAR(Spi_StatusType, AUTOMATIC, SPI_APPL_DATA) pStatus
    )
{
    P2CONST(Spi_Ipw_DeviceAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
        pcDspiDeviceAttributesConfig;
    P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev;
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;
    VAR(uint32, AUTOMATIC) u32Job;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
    VAR(uint32, AUTOMATIC) u32MCR1;
    VAR(uint8, AUTOMATIC) u8HWoffset;

#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    /* Clock mode */
    Spi_Dspi_ClockMode = SPI_NORMAL;
#endif
    /* Get physical device instances and link them */
    pDspiDev = &Spi_Dspi_aDeviceState[HWUnit];
    pcHWUnitConfig = &(*Spi_pcSpiConfigPtr->pcHWUnitConfig)[HWUnit];
    pDspiDev->pcHWUnitConfig = pcHWUnitConfig;
    pDspiDev->pStatus = pStatus;

    /* Reset poll flag */
    pDspiDev->u8IsPollRequest = 0u;

    /* Peripheral Registers */
    u8HWoffset = pcHWUnitConfig->u8Offset;
    
    /* cache frequently used DSPI addresses in order to have a quicker access */
    pDspiDev->u32DspiBaseAddress = DSPI_GET_BASE_ADDRESS_U32(u8HWoffset);
    pDspiDev->u32DspiPUSHRAddress = DSPI_PUSHR_ADDR32(u8HWoffset);
    pDspiDev->u32DspiPOPRAddress = DSPI_POPR_ADDR32(u8HWoffset);
    pDspiDev->u32DspiSRAddress = DSPI_SR_ADDR32(u8HWoffset);

#if (SPI_SLAVE_SUPPORT == STD_ON)

    if (SPI_SLAVE == (Spi_ModeType)pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        pDspiDev->u32DspiCTARAddress = DSPI_CTAR0_ADDR32(u8HWoffset);

        /* Determine chip select inactive states for each PCS */
        u32MCR1 = (DSPI_MCR_PCSIS_ALL_U32);   /* high by default */
    }
    else
    {
#endif
        pDspiDev->u32DspiCTARAddress = DSPI_CTAR_ADDR32(u8HWoffset, (uint32)pcHWUnitConfig->u8NrOfCTAR);

         /* Determine chip select inactive states for each PCS */
        u32MCR1 = (DSPI_MCR_MSTR_U32 | DSPI_MCR_PCSIS_ALL_U32);   /* high by default */
                
#if (SPI_SLAVE_SUPPORT == STD_ON)
    }
#endif
    for (u32Job = 0u; u32Job <= (uint32)(Spi_pcSpiConfigPtr->Spi_Max_Job); u32Job++)
    {
        pcJobConfig = &(*Spi_pcSpiConfigPtr->pcJobConfig)[u32Job];
        if (pcJobConfig->HWUnit == HWUnit)
        {
            /* External device attributes */
            pcDspiDeviceAttributesConfig = &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig)[pcJobConfig->ExternalDevice];
            u32MCR1 = (uint32)(u32MCR1 & (~pcDspiDeviceAttributesConfig->u32MCR));
        }
        else
        {
            /* Do nothing */
        }
    }

    /* SPI works as a Master and CS configured with inactive
    state as appropriate */
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_MCR_ADDR32(u8HWoffset), (u32MCR1 & DSPI_MCR_RESERVED_MASK_U32));

#if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) )
#if (SPI_DMA_USED == STD_ON)
    if (pcHWUnitConfig->u16UseDma)
    {
        REG_WRITE32(DSPI_RSER_ADDR32(u8HWoffset),
                        (DSPI_RSER_TFFF_RE_MASK_U32|DSPI_RSER_TFFF_DIRS_MASK_U32|DSPI_RSER_RFDF_RE_MASK_U32|DSPI_RSER_RFDF_DIRS_MASK_U32
                        ) & DSPI_RSER_RESERVED_MASK_U32
                   /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                   );
        /* initialize DMA TCDs */
        Spi_Dspi_InitDma(HWUnit, pDspiDev);
    }
    else
    {
        /* Do nothing */
    }
#endif /* (SPI_DMA_USED == STD_ON) */
#endif
}

/*================================================================================================*/
/**
* @brief   IRQ configure functions.
* @details Activate/deactivate TCF interrupts for async HWUnit according to
*          the driver operation mode (polling or interrupt).
*
* @param[in]     HWUnit      Specifies which DSPI peripheral is used
* @param[in]     AsyncMode   Specifies the operation mode
*                             (SPI_INTERRUPT_MODE | SPI_POLLING_MODE)
*
*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/*================================================================================================*/
/*
* @violates @ref Spi_DSPI_c_REF_5 All declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required.
*/
FUNC(void, SPI_CODE) Spi_Dspi_IrqConfig
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit,
        VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode
    )
{
    P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev =
        &Spi_Dspi_aDeviceState[HWUnit];
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig =
        pDspiDev->pcHWUnitConfig;
    VAR(uint8, AUTOMATIC) u8HWoffset = pcHWUnitConfig->u8Offset;

    /* set the async mode for the HWUnit */
    pDspiDev->AsyncMode = AsyncMode;

    /* activate/deactivate TCF interrupts for Async HWUnits */
    if (SPI_PHYUNIT_ASYNC_U32 == pcHWUnitConfig->u32IsSync)
    {
#if (SPI_DMA_USED == STD_ON)
        if (pcHWUnitConfig->u16UseDma)
        {
            Spi_Dspi_DmaIrqConfig(pDspiDev, AsyncMode);
        }
        else
        {
            /* Do nothing */
        }
#endif /* SPI_DMA_USED == STD_ON */

        if (SPI_INTERRUPT_MODE == AsyncMode)
        {
        #if (SPI_DMA_USED == STD_ON)
            if (pcHWUnitConfig->u16UseDma)
            {
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_CLEAR32(DSPI_RSER_ADDR32(u8HWoffset), DSPI_RSER_TCF_RE_MASK_U32);
            } 
            else
            {
            #if (SPI_SLAVE_SUPPORT == STD_ON)
                if (SPI_SLAVE == (Spi_ModeType)pcHWUnitConfig->u8SpiPhyUnitMode)
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    REG_BIT_CLEAR32(DSPI_RSER_ADDR32(u8HWoffset), DSPI_RSER_TCF_RE_MASK_U32);
                }
                else
                {
            #endif
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    REG_BIT_SET32(DSPI_RSER_ADDR32(u8HWoffset), DSPI_RSER_TCF_RE_MASK_U32);
            #if (SPI_SLAVE_SUPPORT == STD_ON)
                }
            #endif
            }
        #else
            #if (SPI_SLAVE_SUPPORT == STD_ON)
                if (SPI_SLAVE == (Spi_ModeType)pcHWUnitConfig->u8SpiPhyUnitMode)
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    REG_BIT_CLEAR32(DSPI_RSER_ADDR32(u8HWoffset), DSPI_RSER_TCF_RE_MASK_U32);
                }
                else
                {
            #endif
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    REG_BIT_SET32(DSPI_RSER_ADDR32(u8HWoffset), DSPI_RSER_TCF_RE_MASK_U32);
            #if (SPI_SLAVE_SUPPORT == STD_ON)
                }
            #endif
        #endif /* SPI_DMA_USED == STD_ON */
        }
        else
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_CLEAR32(DSPI_RSER_ADDR32(u8HWoffset), DSPI_RSER_TCF_RE_MASK_U32);
        }
    }
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2) ) */

/*================================================================================================*/
/**
* @brief   IRQ polling functions.
* @details Configures DMA unit to detect received data via
*          interrupt or by polling a bit in the RSER register.
*
* @param[in]     HWUnit     Specifies which DSPI peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_Dspi_IrqPoll
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    )
{
    P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev;
#if (SPI_DMA_USED == STD_ON)
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;
#endif

    pDspiDev = DSPI_HWUNIT2DSPI(HWUnit);

    if ((SPI_POLLING_MODE == pDspiDev->AsyncMode) &&
        (SPI_PHYUNIT_ASYNC_U32 == pDspiDev->pcHWUnitConfig->u32IsSync)
       )
    {
#if (SPI_DMA_USED == STD_ON)
        pcHWUnitConfig = pDspiDev->pcHWUnitConfig;
#endif
        /* Set pool request flag */
        pDspiDev->u8IsPollRequest = 1u;

#if (SPI_DMA_USED == STD_ON)
        if (pcHWUnitConfig->u16UseDma)
        {
            /* Get status from TCD[7] register */
            /* Emulate IRQ */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            *
            */
            if (0u != Mcl_DmaIsTransferCompleted(pcHWUnitConfig->u8RxDmaChannel))
            {
                /*
                * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                Mcl_DmaTcdClearDone(pcHWUnitConfig->u8RxDmaChannel) ;
                Spi_Dspi_IsrDmaRx(pDspiDev);
            }
            else
            {
                /* Do nothing */
            }
        }
        else
#endif /* (SPI_DMA_USED == STD_ON) */
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            if (0u != (REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_TCF_W1C))
            {
                /* Emulate IRQ in PIO_FIFO mode */
                Spi_Dspi_IsrFifoRx(pDspiDev, pDspiDev->pcHWUnitConfig->u8Offset);
            }
            else
            {
                /* Do nothing */
            }
        }
    }
    else
    {
        /* Do nothing */
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function performs the de-initialization of a specific peripheral unit.
* @details This function de-initializes all configured values
*          in the MCR register and CTAR registers.
*
* @param[in]     HWUnit      Specifies which DSPI peripheral is used
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Dspi_DeInit
    (
        VAR(Spi_HWUnitType, AUTOMATIC) HWUnit
    )
{
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_CONST) pcHWUnitConfig;
    VAR(uint8, AUTOMATIC) u8HWoffset;
    VAR(uint8, AUTOMATIC) u8NrOfCTAR;
    VAR(uint32, AUTOMATIC) u32RxCtrVal;
    VAR(uint32, AUTOMATIC) u32SRVal;

    /* Get physical device handler */
    pcHWUnitConfig = &(*Spi_pcSpiConfigPtr->pcHWUnitConfig)[HWUnit];

    /* Pointer to peripheral registers */
    u8HWoffset = pcHWUnitConfig->u8Offset;
    
    /* Pointer to the number of CTAR registers available for the HW unit */
    u8NrOfCTAR = pcHWUnitConfig->u8NrOfCTAR;
    
    /* Reset the DSPI Regs and Read until the RXCTR becomes zero*/    
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    u32RxCtrVal = DSPI_SR_RXCTR_VAL_U32(REG_READ32(DSPI_SR_ADDR32(u8HWoffset)));
    while(u32RxCtrVal)
    {
        /*
        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_READ32(DSPI_POPR_ADDR32(u8HWoffset));
        u32RxCtrVal--;
    }
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    u32SRVal = REG_READ32(DSPI_SR_ADDR32(u8HWoffset));
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */   
    REG_WRITE32(DSPI_SR_ADDR32(u8HWoffset), (u32SRVal & DSPI_SR_RESERVED_MASK_U32));
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_MCR_ADDR32(u8HWoffset), (DSPI_MCR_RESET_U32 & DSPI_MCR_RESERVED_MASK_U32));
    
    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_RSER_ADDR32(u8HWoffset), (DSPI_RSER_RESET_MASK_U32 & DSPI_RSER_RESERVED_MASK_U32));
    
    while( (uint8)0 < u8NrOfCTAR  )
    {
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(DSPI_CTAR_ADDR32(u8HWoffset, (uint32)u8NrOfCTAR), DSPI_CTAR_RESET_U32);
        u8NrOfCTAR--;
    }

    /*
    * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
    * a pointer to a function and any type other than an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_TCR_ADDR32(u8HWoffset), (DSPI_TCR_RESET_U32 & DSPI_TCR_RESERVED_MASK_U32));
}

/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
/**
* @brief   This function is called by TCF ISRs for the DSPI units working in PIO_FIFO mode.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the DSPI
*          peripherals.
*
* @param[in]     pDspiDev     Specifies which DSPI peripheral is used
*
* @implements Spi_Dspi_IsrFifoRx_Activity
*/
FUNC(void, SPI_CODE) Spi_Dspi_IsrFifoRx
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev,
        VAR(uint8, AUTOMATIC) u8HWoffset
    )
{
    VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode = pDspiDev->AsyncMode;
    VAR(uint32, AUTOMATIC) u32IsrStatus = 0u;
#if ((SPI_DMA_USED == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
    VAR(uint32, AUTOMATIC) u32TFUF_Flag = 0u;
#endif
    
    /* Check if the driver has been initialized */
    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        if (SPI_POLLING_MODE != AsyncMode)
        {
            if((uint8)SPI_MASTER == pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
            {
                /*Not in pooling mode: read status register and interrupts enabled register */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                u32IsrStatus = REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_TCF_W1C;
                /*
                * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                u32IsrStatus &= REG_READ32(DSPI_RSER_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset)) & DSPI_RSER_TCF_RE_MASK_U32;
            }
            else
            {
    #if (SPI_SLAVE_SUPPORT == STD_ON)

                /*Not in pooling mode: read status register and interrupts enabled register */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                u32IsrStatus = REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_RFDF_W1C;
                /*
                * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
                * a pointer to a function and any type other than an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                u32IsrStatus &= REG_READ32(DSPI_RSER_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset)) & DSPI_SR_RFDF_W1C;
    #endif
            }
        }
        else
        {
            /* Operation mode is SPI_POLLING_MODE: set u32IsrStatus to poll request flag */
            u32IsrStatus = pDspiDev->u8IsPollRequest;
            /* Clear poll request flag */
            pDspiDev->u8IsPollRequest = 0u;
        }

        /* check if any enabled isr had been triggered */
        if (0u != u32IsrStatus)
        {
            #if (SPI_DMA_USED == STD_ON)
            if (0u != pDspiDev->pcHWUnitConfig->u16UseDma)
            {
                #if (SPI_SLAVE_SUPPORT == STD_ON)
                if(SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
                {
                    /* 
                    * In case of Slave using DMA to transfer, It will enable interrupt request of RFDF flag and 
                    * Slave will discard the received data if Master send extra frames 
                    */
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    Spi_Dspi_u32ReadDiscard = REG_READ32(pDspiDev->u32DspiPOPRAddress);
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    REG_WRITE32(pDspiDev->u32DspiSRAddress, DSPI_SR_RFDF_W1C & DSPI_SR_RESERVED_MASK_U32);
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    u32TFUF_Flag = REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_TFUF_W1C;
                    if(u32TFUF_Flag!=0u)
                    {
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                        *     type and an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                        REG_WRITE32(pDspiDev->u32DspiSRAddress, DSPI_SR_TFUF_W1C & DSPI_SR_RESERVED_MASK_U32);
                    }
                    else
                    {
                        /* Do nothing */
                    }
                }
                else
                {
                    /* Do nothing */
                }
                #endif  /* (SPI_SLAVE_SUPPORT == STD_ON) */
            }
            else
            #endif  /* (SPI_DMA_USED == STD_ON) */
            {
                /* clear TCF Flag, in order to unlock next TX transmission */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(pDspiDev->u32DspiSRAddress, DSPI_SR_TCF_W1C);

                /* Copy data from DSPI FIFOD to channels */
                Spi_Dspi_JobTransferFifoDrain(pDspiDev);

            #if (SPI_SLAVE_SUPPORT == STD_ON)
                if( SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    REG_WRITE32(pDspiDev->u32DspiSRAddress, DSPI_SR_RFDF_W1C & DSPI_SR_RESERVED_MASK_U32);
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    u32IsrStatus = REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_TFUF_W1C;
                    if(u32IsrStatus!=0u)
                    {
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                        *     type and an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                        REG_WRITE32(pDspiDev->u32DspiSRAddress, DSPI_SR_TFUF_W1C & DSPI_SR_RESERVED_MASK_U32);
                    }
                    else
                    {
                         /* Do nothing */
                    }
                }
                else
                {
                    /* Do nothing */
                }
            #endif
                if ((boolean)FALSE == pDspiDev->bIsEndOfJob)
                {
                    /* check for the channel switch */
                    if ( 0u == pDspiDev->RemainingData )
                    {
                        /* reached the end of channel => move to the next channel */
                        /* Increase Channel indexes */
                        pDspiDev->RemainingChannels--;
                        /*
                        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        pDspiDev->pcCurrentChannelIndexPointer++;
                 
                        if(SPI_MASTER == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode )
                        {
                            /* prepare next channel transmission */
                            Spi_Dspi_ChannelTransferFifoInit(pDspiDev, *(pDspiDev->pcCurrentChannelIndexPointer));
                        }
                        else
                        {
                            /* Do nothing */
                        }
                    }
                    else
                    {
                        /* Do nothing */
                    }

                    /* perform the next chunk transmission */
                    Spi_Dspi_JobTransferFifoFill(pDspiDev);
                }
                else
                {
                    if(SPI_JOB_OK != pDspiDev->pcCurrentJob->pJobState->Result)
                    {
                        /* finish job transfer */
                        Spi_JobTransferFinished(pDspiDev->pcCurrentJob);
                    }
                    else
                    {
                        /* Do nothing */
                    }                
                }
            }
        }
        else
        {
            /* Driver has been initialized and received an unconfigured interrupt, clear status flags */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(pDspiDev->u32DspiSRAddress, DSPI_SR_INT_MASK_U32 & DSPI_SR_RESERVED_MASK_U32);
        }
    }
    else
    {
        /* Driver has not been initialized, clear status flags and Reset the DSPI Regs*/
            /* Need to make sure that SPI unit in Stop mode */    
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET32(DSPI_MCR_ADDR32(u8HWoffset), DSPI_MCR_HALT_U32);
            /* Flush the TX and RX FIFOs */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET32(DSPI_MCR_ADDR32(u8HWoffset), (DSPI_MCR_CLR_TXF_U32 | DSPI_MCR_CLR_RXF_U32));
            /* Clear Status register */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(DSPI_SR_ADDR32(u8HWoffset), DSPI_SR_INT_MASK_U32 & DSPI_SR_RESERVED_MASK_U32);
            /* Clear HALT bit for next transmission */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_CLEAR32(DSPI_MCR_ADDR32(u8HWoffset), DSPI_MCR_HALT_U32);
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
/**
* @brief   This function is called by DMA ISR for Rx DMA channels.
* @details Non-AutoSar support function used by interrupt service
*          routine. The function is used as a pseudo ISR for all the DSPI
*          peripherals
*
* @param[in]     pDspiDev     Specifies which DSPI peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*       and SPI_DMA_USED must be STD_ON
*
*/
/*================================================================================================*/
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
FUNC(void, SPI_CODE) Spi_Dspi_IsrDmaRx
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    )
{
    VAR(Spi_AsyncModeType, AUTOMATIC) AsyncMode = pDspiDev->AsyncMode;
    VAR(uint8, AUTOMATIC) u8IsrStatus  = (uint8)FALSE;
#ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
#if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)    
    P2CONST(Spi_Ipw_DeviceAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) pcDeviceAttributesConfig;
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequenceConfig = (pDspiDev->pcCurrentJob)->pJobState->pAsyncCrtSequenceState->pcSequence;
    VAR(boolean, AUTOMATIC) bExAcceptance = (boolean)FALSE;
#endif
#endif

    if (NULL_PTR != Spi_pcSpiConfigPtr)
    {
        if (SPI_POLLING_MODE == AsyncMode)
        {
            /* Operation mode is SPI_POLLING_MODE: set u8IsrStatus to poll request flag*/
            u8IsrStatus = (uint8)pDspiDev->u8IsPollRequest;
            /* Clear poll request flag */
            pDspiDev->u8IsPollRequest = (uint8)FALSE;
        }
        else
        {
            /* Operation mode is SPI_INTERRUPT_MODE: set u8IsrStatus to enabled*/
            u8IsrStatus = (uint8)TRUE;
        }

        /* Check if a poll request was made or if the operation mode is SPI_INTERRUPT_MODE */
        if (0u != u8IsrStatus)
        {

            if ( 0u != pDspiDev->RemainingData )
            {
                /* Channel not finished => update RX/TX pointers */
                Spi_Dspi_JobTransferDmaContinue(pDspiDev);
            }
            else
            {
                /* reached the end of channel => move to the next channel */
                if (0u != pDspiDev->RemainingChannels)
                {
                    /* Increase Channel indexes */
                    pDspiDev->RemainingChannels--;
                    /*
                    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pDspiDev->pcCurrentChannelIndexPointer++;

                    /* prepare next channel transmission */
                    Spi_Dspi_ChannelTransferDmaInit(pDspiDev,*(pDspiDev->pcCurrentChannelIndexPointer));
                }
                else
                {
                #ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
                    #if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
                        /* retrieve the device configuration for the sequence */
                        pcDeviceAttributesConfig =
                            &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig)
                                [pDspiDev->pcCurrentJob->ExternalDevice];
                        if((uint8)STD_ON == pcDeviceAttributesConfig->u8SlaveHighSpeed)
                        {
                            /* Increase the number of received frames */
                            pDspiDev->ReceivedData++;
                            /* Call back function */
                            if (NULL_PTR != pcSequenceConfig->pfHPEndNotification)
                            {
                                pcSequenceConfig->pfHPEndNotification(pDspiDev->ReceivedData);
                            }
                            else
                            {
                                /* Do nothing */
                            }
                            /* Accept for extra frame case */
                            bExAcceptance = (boolean)TRUE;
                            /* Continuing transmission on Slave device */
                            Spi_Dspi_TransferDmaContinue(pDspiDev);
                        }
                        else
                        {
                            /* Prevent the extra frame from Master device */
                            bExAcceptance = (boolean)FALSE;
                    #endif
                #endif
                            /* finish job transfer */
                            Spi_JobTransferFinished(pDspiDev->pcCurrentJob);
                #ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
                    #if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
                        }
                     #endif
                #endif
                #if (SPI_SLAVE_SUPPORT == STD_ON)
                  if((SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
                    #ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
                    #if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
                        && ((boolean)FALSE == bExAcceptance)
                    #endif
                    #endif
                    )
                    {
                        /* 
                        * Enable interrupt request for RFDF flag to discard receive data when Master send extra frames
                        * after Slave is finished job transfer 
                        */
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                        *     type and an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                        REG_WRITE32(pDspiDev->u32DspiSRAddress, DSPI_SR_RFDF_W1C & DSPI_SR_RESERVED_MASK_U32);
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                        *     type and an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                        REG_BIT_CLEAR32(DSPI_RSER_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset), DSPI_RSER_RFDF_DIRS_MASK_U32);
                    }
                    else
                    {
                        /* Do nothing */
                    }
                #endif  /* (SPI_SLAVE_SUPPORT == STD_ON) */
                }
            }
        }
        else
        {
            /* Driver is initialized but there was no poll request*/
            /* Do nothing */
        }
    }
    else
    {
        /* Driver is not initialized, do nothing */
    }
}
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) ||
        (SPI_LEVEL_DELIVERED == LEVEL2))) */

/*================================================================================================*/
/**
* @brief   This function sets the Job's attributes and send all the data through the SPI bus.
* @details This function is in charge to setup the Job attribute,
*          and to send all data though the SPI Bus.
*
* @param[in]     pcJobConfig    Specifies the Job for which we will set the
*                            register values
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
FUNC(void, SPI_CODE) Spi_Dspi_JobTransfer
    (
        P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig
    )
{
    P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev =
        &Spi_Dspi_aDeviceState[pcJobConfig->HWUnit];
    P2CONST(Spi_ChannelType, AUTOMATIC, SPI_APPL_CONST) pcChannelList =
            (*pcJobConfig->pcChannelIndexList);
    VAR(uint32, AUTOMATIC) u32SelectedCTAR;
    #if (SPI_DMA_USED == STD_ON)
        #if (SPI_SLAVE_SUPPORT == STD_ON)
            VAR(uint8, AUTOMATIC) u8HWoffset = pDspiDev->pcHWUnitConfig->u8Offset;
        #endif
    #endif
    #if (SPI_SLAVE_SUPPORT == STD_ON)
        VAR(uint32, AUTOMATIC) u32SRval;
        VAR(uint32, AUTOMATIC) u32Timeout=SPI_TIMEOUT_COUNTER;
    #endif
    
    #if (SPI_SLAVE_SUPPORT == STD_ON)
    if(SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        /* 
        * Maybe exist a frame data is not shift to RX FIFO when Master send extra frames with low baudrate, 
        * Slave need discard extra frame before preparing for a new job 
        */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        u32SRval = REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_TFUF_W1C;
        if(u32SRval!=0u)
        {
            /* 
            * Slave will wait until TFUF flag is cleared before prepare next Job of new sequence,
            * It will clear TFUF flag by Spi_Dspi_IsrFifoRx() function 
            */
            do
            {
                u32Timeout--;
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                u32SRval = REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_TFUF_W1C;
            }while((u32SRval!=0u) && (u32Timeout>0u));
            if(u32Timeout == 0u)
            {
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(pDspiDev->u32DspiSRAddress, DSPI_SR_TFUF_W1C & DSPI_SR_RESERVED_MASK_U32);
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
    } 
    else
    {
         /* Do nothing */
    }
    #endif  /* (SPI_SLAVE_SUPPORT == STD_ON) */
    
    /* start job notification to assert the non-cs pin,
     when non-cs pin is used as chipselect*/
    if (NULL_PTR != pcJobConfig->pfStartNotification)
    {
        pcJobConfig->pfStartNotification();
    }
    else
    {
        /* Do nothing */
    }
    
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    pDspiDev->u32ExternalDeviceCTAR = pcJobConfig->ExternalDeviceAttrs.u32CTAR[Spi_Dspi_ClockMode];
#else
    pDspiDev->u32ExternalDeviceCTAR = pcJobConfig->ExternalDeviceAttrs.u32CTAR;
#endif

    /* Generate CTAR selection */
    u32SelectedCTAR = DSPI_GENERATE_CTAR_U32((uint32)pDspiDev->pcHWUnitConfig->u8NrOfCTAR);

    /* setup job specific ctar and cmd */
    pDspiDev->u32CurrentCmd = (pcJobConfig->ExternalDeviceAttrs.u32CMD | u32SelectedCTAR);

    /* initialize starting channel index */
    pDspiDev->pcCurrentChannelIndexPointer = pcChannelList;
    pDspiDev->RemainingChannels = pcJobConfig->NumChannels - (Spi_ChannelType) 1u;

    /* memorize the current job */
    pDspiDev->pcCurrentJob = pcJobConfig;

#if (SPI_DMA_USED == STD_ON)
    #if (SPI_SLAVE_SUPPORT == STD_ON)
        if(SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            u32SRval = REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_RFDF_W1C;
            if(0u != u32SRval)
            {
                /* Need to change the state of SPI unit to Stop mode */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_SET32(DSPI_MCR_ADDR32(u8HWoffset), DSPI_MCR_HALT_U32); 
                /* Discard all frames in FIFO */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_SET32(DSPI_MCR_ADDR32(u8HWoffset), (DSPI_MCR_CLR_RXF_U32 | DSPI_MCR_CLR_TXF_U32)); 
                /* Clear Status register */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(DSPI_SR_ADDR32(u8HWoffset), DSPI_SR_INT_MASK_U32 & DSPI_SR_RESERVED_MASK_U32);
                /* Clear HALT bit for continuing transmission */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_BIT_CLEAR32(DSPI_MCR_ADDR32(u8HWoffset), DSPI_MCR_HALT_U32);
            }
        }
        else
        {
            /* Do nothing */
        }   
    #endif
    if (0u != pDspiDev->pcHWUnitConfig->u16UseDma)
    {
        #if (SPI_SLAVE_SUPPORT == STD_ON)
        if(SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
        {
            /* Enable DMA request of RFDF flag */
            /*
             * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
             *     type and an integral type.
             * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
             */
            REG_BIT_SET32(DSPI_RSER_ADDR32(pDspiDev->pcHWUnitConfig->u8Offset), DSPI_RSER_RFDF_DIRS_MASK_U32);
        }
        else
        {
            /* Do nothing */
        }
        #endif 
        /* initialize the transfer parameters for the first channel */
        Spi_Dspi_ChannelTransferDmaInit(pDspiDev, *pcChannelList);
    }
    else
#endif /* (SPI_DMA_USED == STD_ON) */
    {
        pDspiDev->bIsEndOfJob = (boolean)FALSE;

        /* initialize the transfer parameters for the first channel */
        Spi_Dspi_ChannelTransferFifoInit(pDspiDev, *pcChannelList);
        Spi_Dspi_JobTransferFifoFill(pDspiDev);
    }
}
#endif /* ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)) */

/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
#if (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON)
/**
* @brief   This function starts the synchronous transmission for optimized sequences having only one job.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*          Same behavior as Spi_SyncTransmit(), but the initialization time and
*          data preparation time are optimized.
*
* @param[in]     pcSequence     Keep the cached information for "one job sequence"
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
* @pre  Pre-compile parameter SPI_OPTIMIZE_ONE_JOB_SEQUENCES shall be STD_ON
*
* @implements Spi_Dspi_SyncTransmit_Fast_Activity
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_Dspi_SyncTransmit_Fast
    (
        P2CONST(Spi_Dspi_SequenceCacheAttrsType, AUTOMATIC, SPI_APPL_CONST) pcSequence
    )
{
    P2VAR(Spi_Dspi_ChannelCacheAttrsType, AUTOMATIC, SPI_APPL_DATA) pChannel;    
    VAR(Spi_ChannelType, AUTOMATIC) ChannelsCount;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pBufferTX;
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pBufferRX;
     P2VAR(Spi_JobStateType, AUTOMATIC, SPI_APPL_DATA) pJobState = pcSequence->pJobState;
    VAR(uint32, AUTOMATIC) u32Timeout = SPI_TIMEOUT_COUNTER;
    VAR(uint32, AUTOMATIC) u32TempXferData;
    VAR(Std_ReturnType, AUTOMATIC) Status;
    VAR(uint32, AUTOMATIC) u32DspiBaseAddress;
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthTX;
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthRX;
    VAR(uint32, AUTOMATIC) u32nEmptyPlaces;
    VAR(uint32, AUTOMATIC) u32StatusReset = 0u;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pu16BufferFullTX;
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pu16BufferFullRX;
#endif

    /* retrieve the DSPI offset */
    u32DspiBaseAddress = pcSequence->u32DspiBaseAddress;

    /* set the CMD part of the word to be transmitted */
    u32TempXferData = pcSequence->u32JobCMD;

    /* Set the job status as pending and mark HW Unit as busy */
    pJobState->Result = SPI_JOB_PENDING;
    *(pcSequence->pJobDspiStatus) = SPI_BUSY;
    /* iterate on all channels in job */
    pChannel = pcSequence->pChannels;
    ChannelsCount = pcSequence->NumChannels;
    while ((Spi_ChannelType)0 < ChannelsCount)
    {
        ChannelsCount--;

        /* set CTAR register */
        /**
        * @note The call is blocking till the HWUnit exits
        *       the running state.
        */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(pcSequence->u32DspiCTARAddress, pChannel->u32CTAR[Spi_Dspi_ClockMode]);
#else
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(pcSequence->u32DspiCTARAddress, pChannel->u32CTAR);
#endif

        /* retrieve RX/TX buffers and the transmitted/received lengths */
        if (pChannel->pState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
        {
            pBufferTX = NULL_PTR;
        }
        else
        {
            pBufferTX = pChannel->pcBufferDescriptor->pBufferTX;
        }
        pBufferRX = pChannel->pcBufferDescriptor->pBufferRX;

        LengthTX = pChannel->pState->Length;
    #if (SPI_FORCE_DATA_TYPE == STD_ON)
        if (SPI_DATA_WIDTH_16 == pChannel->u8DataWidth)
        {
            LengthTX /= 2u;
        }
        else
        {
            /* Do nothing */
        }
    #endif
        LengthRX = LengthTX;

        u32Timeout = SPI_TIMEOUT_COUNTER;
        u32nEmptyPlaces = SPI_FIFO_SIZE;

        /* while there is still something to read or to write */
        /* a kind of: while ((LengthTX > 0) || (LengthRX > 0)) */
        while (0u < (LengthTX | LengthRX))
        {
            /* --------- Transmit ---------- */
            /* there is something to write and Transmit FIFO not full */
            if ((0u < LengthTX) && (0u < u32nEmptyPlaces))
            {
                LengthTX--;
                u32nEmptyPlaces--;

                /* reset the timeout */
                u32Timeout = SPI_TIMEOUT_COUNTER;

                /* prepare the data to be transmitted */
                if (NULL_PTR == pBufferTX)
                {
                    /* Get default data if TX buffer is NULL_PTR */
                    u32TempXferData =(u32TempXferData & DSPI_TX_CMD_MASK_U32) | 
                                      pChannel->DefaultTransmitValue;
                }
                else
                {
                    /* Read transmit data */
                    #if (SPI_FORCE_DATA_TYPE == STD_ON)
                    if (SPI_DATA_WIDTH_16 == pChannel->u8DataWidth)
                    {
                        /*
                        * @violates @ref Spi_DSPI_c_REF_4 A cast should not be performed between a 
                        *       pointer to object type and a different pointer to object type.
                        */
                        pu16BufferFullTX = (uint16 *) pBufferTX;
                        u32TempXferData =(u32TempXferData & DSPI_TX_CMD_MASK_U32) | (*pu16BufferFullTX);
                        /*
                        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        pBufferTX++;
                    }
                    else
                    {
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a 
                        *     pointer type and an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                        u32TempXferData = (u32TempXferData & DSPI_TX_CMD_MASK_U32) | (*pBufferTX);
                    }
                    #else
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a 
                    *     pointer type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    u32TempXferData = (u32TempXferData & DSPI_TX_CMD_MASK_U32) | (*pBufferTX);
                    #endif
                    /*
                    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pBufferTX++;
                }

                /* For the last frame, clear the continuous CS assertion */
                /* a kind of: if ((0u == LengthTX) && (0u == ChannelsCount) )*/
                if (0u == (LengthTX | ChannelsCount))
                {
                    u32TempXferData = u32TempXferData & ~DSPI_CONT_MASK_U32;
                }
                else
                {
                    /* Do nothing */
                }

                /* Transmit the data */
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(DSPI_BASEADDR2PUSHR_ADDR32(u32DspiBaseAddress), u32TempXferData);

                /* Transmit FIFO Fill Flag must be reset */
                u32StatusReset |= DSPI_SR_TFFF_W1C;
            }

            /* --------- Receive ---------- */
            /* there is still something to read and Receive FIFO has data */
            if (0u < LengthRX )
            {
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                if (0u != ((REG_READ32(DSPI_BASEADDR2SR_ADDR32(u32DspiBaseAddress))) & DSPI_SR_RFDF_W1C))
                {
                    LengthRX--;
                    u32nEmptyPlaces++;

                    /* reset the timeout */
                    u32Timeout = SPI_TIMEOUT_COUNTER;

                    /* Read Data from RX FIFO */
                    if (NULL_PTR == pBufferRX)
                    {
                        /* discard data if RX buffer is NULL_PTR */
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not
                        * be performed between
                        * a pointer to a function and any type other than an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                        Spi_Dspi_u32ReadDiscard = REG_READ32(DSPI_BASEADDR2POPR_ADDR32(u32DspiBaseAddress));
                    }
                    else
                    {
                        #if (SPI_FORCE_DATA_TYPE == STD_ON)
                        if (SPI_DATA_WIDTH_16 == pChannel->u8DataWidth)
                        {
                            /*
                            * @violates @ref Spi_DSPI_c_REF_4 A cast should not be
                            * performed between a pointer
                            *       to object type and a different pointer to object type.
                            */
                            pu16BufferFullRX = (uint16 *) pBufferRX;
                           /*
                            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall
                            * not be performed between
                            * a pointer to a function and any type other than an
                            * integral type.
                            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                            */
                            *pu16BufferFullRX = (uint16)REG_READ32(DSPI_BASEADDR2POPR_ADDR32(u32DspiBaseAddress));
                            /*
                            * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            pBufferRX += 2u;
                        }
                        else
                        {
                            /*
                            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall
                            * not be performed between
                            * a pointer to a function and any type other than an
                            * integral type.
                            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                            */
                             *pBufferRX = (Spi_DataBufferType)REG_READ32(DSPI_BASEADDR2POPR_ADDR32(u32DspiBaseAddress));
                             /*
                            * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                            *       the only allowed form of pointer arithmetic.
                            */
                            pBufferRX++;
                        }
                        #else
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be
                        * performed between a pointer type and an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                         *pBufferRX = (Spi_DataBufferType)REG_READ32(DSPI_BASEADDR2POPR_ADDR32(u32DspiBaseAddress));
                         /*
                        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        pBufferRX++;
                        #endif
                    }

                    /* Receive FIFO Drain Flag must be reset */
                    u32StatusReset |= DSPI_SR_RFDF_W1C;
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }

            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(DSPI_BASEADDR2SR_ADDR32(u32DspiBaseAddress), u32StatusReset);

            u32Timeout--;
            /* end the loop if timeout expired */
            if (0u == u32Timeout)
            {
                /* force the end of the outer loop too */
                ChannelsCount = 0U;
                break;
            }
            else
            {
                /* Do nothing */
            }
        } /* while ((LengthTX > 0) || (LengthRX > 0)) */
        /*
        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pChannel++;
    } /* while (ChannelsCount) */

    /* release the HW Unit */
    *(pcSequence->pJobDspiStatus) = SPI_IDLE;

    if (0u < u32Timeout)
    {
        /* Job is done set the status as OK */
        pJobState->Result = SPI_JOB_OK;
        Status = (Std_ReturnType)E_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            /* Do nothing */
        }
#endif 
    }
    else
    {
        /* u32Timeout expired => transmission failed */
        /* set the Job status as FAILED */
        pJobState->Result = SPI_JOB_FAILED;
        Status = (Std_ReturnType)E_NOT_OK;
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            /* Do nothing */
        }
#endif
    }
    
    return Status;
}
#endif /* (SPI_OPTIMIZE_ONE_JOB_SEQUENCES == STD_ON) */
#endif /* ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function performs the synchronous transmission for a channel.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     pDspiDev     Specifies device involved in transmission
* @param[in]     Channel     ID of the channel to be transmited.
*
* @return Std_ReturnType
* @retval E_OK            Transmission data has been completed
* @retval E_NOT_OK        Transmission data has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
*/
LOCAL_INLINE FUNC(Std_ReturnType, SPI_CODE) Spi_Dspi_SyncTransmitChannel
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev,
        VAR(Spi_ChannelType, AUTOMATIC) Channel
    )
{
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthTX = pDspiDev->RemainingData;
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthRX;
     P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pBufferTX = pDspiDev->pCurrentTxBuffer;
    P2VAR(Spi_DataBufferType, AUTOMATIC, SPI_APPL_DATA) pBufferRX = pDspiDev->pCurrentRxBuffer;
     VAR(uint32, AUTOMATIC) u32TempXferData = pDspiDev->u32CurrentCmd;
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) pcDspiChannelAttributesConfig =
        &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)[Channel];
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pu16BufferFullTX;
    P2VAR(uint16, AUTOMATIC, SPI_APPL_DATA) pu16BufferFullRX;
#endif
    VAR(uint32, AUTOMATIC) u32StatusReset = 0u;
    VAR(uint32, AUTOMATIC) u32nEmptyPlaces = SPI_FIFO_SIZE;
    VAR(uint32, AUTOMATIC) u32Timeout = SPI_TIMEOUT_COUNTER;
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig = 
        &(*Spi_pcSpiConfigPtr->pcChannelConfig)[Channel];
    VAR(uint32, AUTOMATIC) u32DspiPUSHRAddress = pDspiDev->u32DspiPUSHRAddress;
    VAR(uint32, AUTOMATIC) u32DspiPOPRAddress = pDspiDev->u32DspiPOPRAddress;
    
    LengthRX = LengthTX;
    /* while there is still something to read or to write */
    /* a kind of: while ((LengthTX > 0) || (LengthRX > 0)) */
    while (0u < (LengthTX | LengthRX))
    {
        /* --------- Transmit ---------- */
        /* there is something to write and Transmit FIFO not full */
        if ((LengthTX > 0u) && (u32nEmptyPlaces > 0u))
        {
            LengthTX--;
            u32nEmptyPlaces--;
            /* reset the timeout */
            u32Timeout = SPI_TIMEOUT_COUNTER;
            /* prepare the data to be transmitted */
            if (NULL_PTR == pBufferTX)
            {
                /* Get default data if TX buffer is NULL_PTR */
                u32TempXferData =
                    (u32TempXferData & DSPI_TX_CMD_MASK_U32) |
                    pcChannelConfig->DefaultTransmitValue;
            }
            else
            {
                /* Read transmit data */
                #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_4 A cast should not be performed
                    * between a pointer to object type and a different pointer to object
                    * type.
                    */
                    pu16BufferFullTX = (uint16 *) pBufferTX;
                    u32TempXferData =
                        (u32TempXferData & DSPI_TX_CMD_MASK_U32) | (*pu16BufferFullTX);
                }
                else
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed
                    *  between a pointer type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    u32TempXferData =
                        (u32TempXferData & DSPI_TX_CMD_MASK_U32) | (*pBufferTX);
                }
                #else
                /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed
                * between a pointer type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
                 u32TempXferData = (u32TempXferData & DSPI_TX_CMD_MASK_U32) | (*pBufferTX);
                #endif
                /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                pBufferTX++;
                #if (SPI_FORCE_DATA_TYPE == STD_ON)
                if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
                {
                    /*
                    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pBufferTX++;
                }
                else
                {
                    /* Do nothing */
                }
                #endif
            }
            /* For the last frame, clear the continous CS assertion */
            /* a kind of: ((0u == LengthTX) && (0u == RemainingChannels))*/
            /* if (0u == (LengthTX | RemainingChannels)) */
            if (0u == (LengthTX | pDspiDev->RemainingChannels))
            {
                /* clear the continuous CS assertion */
                u32TempXferData = u32TempXferData & ~DSPI_CONT_MASK_U32;
            }
            else
            {
                /* Do nothing */
            }
            /* Transmit the data */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(u32DspiPUSHRAddress, u32TempXferData);
            
            /* Transmit FIFO Fill Flag must be reset */
            u32StatusReset |= DSPI_SR_TFFF_W1C;
        }

        /* --------- Receive ---------- */
        /* there is still something to read and Receive FIFO has data */
        if (0u < LengthRX)
        {
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            if (0u != ((REG_READ32(pDspiDev->u32DspiSRAddress)) &DSPI_SR_RFDF_W1C))
            {
                LengthRX--;
                u32nEmptyPlaces++;
                /* reset the timeout */
                u32Timeout = SPI_TIMEOUT_COUNTER;
                /* Read Data from RX FIFO */
                if (NULL_PTR == pBufferRX)
                {
                    /* discard data if RX buffer is NULL_PTR */
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                    Spi_Dspi_u32ReadDiscard = REG_READ32(u32DspiPOPRAddress);
                }
                else
                {
                    #if (SPI_FORCE_DATA_TYPE == STD_ON)
                    if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
                    {
                        /*
                        * @violates @ref Spi_DSPI_c_REF_4 A cast should not be
                        * performed between a pointer
                        *       to object type and a different pointer to object type.
                        */
                        pu16BufferFullRX = (uint16 *) pBufferRX;
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                        *     type and an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                        *pu16BufferFullRX = (uint16)REG_READ32(u32DspiPOPRAddress);
                        /*
                        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        pBufferRX += 2u;
                    }
                    else
                    {
                        /*
                        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                        *     type and an integral type.
                        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                        */
                          *pBufferRX = (Spi_DataBufferType)REG_READ32(u32DspiPOPRAddress);
                         /*
                        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                        *       the only allowed form of pointer arithmetic.
                        */
                        pBufferRX++;
                    }
                    #else
                    /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                      *pBufferRX = (Spi_DataBufferType)REG_READ32(u32DspiPOPRAddress);
                     /*
                    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                    *       the only allowed form of pointer arithmetic.
                    */
                    pBufferRX++;
                    #endif
                }
                /* Receive FIFO Drain Flag must be reset */
                u32StatusReset |= DSPI_SR_RFDF_W1C;
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* Do nothing */
        }
        /*
        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(pDspiDev->u32DspiSRAddress, u32StatusReset);

        u32Timeout--;
        /* end the loop if timeout expired */
        if (0u == u32Timeout)
        {
            /* force the end of the outer loop too */
            pDspiDev->RemainingChannels = 0U;
            Status = (Std_ReturnType)E_NOT_OK;
            break;
        }
        else
        {
            /* Do nothing */
        }
    } /* while ((LengthTX > 0) || (LengthRX > 0)) */
    return Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */
/*================================================================================================*/
#if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) )
/**
* @brief   This function performs the synchronous transmission for a sequence.
* @details This function is pre compile time selectable by the
*          configuration parameter: SPI_LEVEL_DELIVERED. This function is only
*          relevant for LEVEL 0 and LEVEL 2.
*
* @param[in]     Sequence      Specifies the sequence for which we will have
*                              the synchronous transmission
*
* @return Std_ReturnType
* @retval E_OK            Transmission command has been completed
* @retval E_NOT_OK        Transmission command has not been accepted
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL0 or LEVEL2
*
* @implements Spi_Dspi_SyncTransmit_Activity
*/
FUNC(Std_ReturnType, SPI_CODE) Spi_Dspi_SyncTransmit
    (
        VAR(Spi_SequenceType, AUTOMATIC) Sequence
    )
{
    P2CONST(Spi_SequenceConfigType, AUTOMATIC, SPI_APPL_CONST) pcSequenceConfig;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pcChannelConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
    P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev;
    P2CONST(Spi_Ipw_ChannelAttributesConfigType, AUTOMATIC, SPI_APPL_CONST)
        pcDspiChannelAttributesConfig;
    VAR(Spi_JobType, AUTOMATIC) JobsCount;
    VAR(Spi_JobType, AUTOMATIC) Job;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) pcJobIndexList;
    P2CONST(Spi_ChannelType, AUTOMATIC, SPI_APPL_CONST) pcChannelIndexList;
    VAR(Std_ReturnType, AUTOMATIC) Status = (Std_ReturnType)E_OK;
    VAR(Std_ReturnType, AUTOMATIC) TransmitChannelStatus = (Std_ReturnType)E_NOT_OK;
    P2VAR(Spi_JobStateType, AUTOMATIC, SPI_APPL_DATA) pJobState;
    P2VAR(Spi_ChannelStateType, AUTOMATIC, SPI_APPL_DATA) pChannelState;
    VAR(Spi_ChannelType, AUTOMATIC) Channel;
    VAR(Spi_NumberOfDataType, AUTOMATIC) LengthTX;
    VAR(uint32, AUTOMATIC) u32Ctar;
    VAR(uint32, AUTOMATIC) u32SelectedCTAR;

    /* Get sequence configuration */
    pcSequenceConfig = &(*Spi_pcSpiConfigPtr->pcSequenceConfig)[Sequence];
    /* Get the number of jobs in the sequence */
    JobsCount = pcSequenceConfig->NumJobs;

    pcJobIndexList = (*pcSequenceConfig->pcJobIndexList);
    while (0u < JobsCount)
    {
        /* Get the job id */
        Job = *pcJobIndexList;
        /* Set the job status as pending */
        pJobState = &Spi_aSpiJobState[Job];
        pJobState->Result = SPI_JOB_PENDING;
        pcJobConfig = &(*Spi_pcSpiConfigPtr->pcJobConfig)[Job];
        
        /* start job notification to assert the non-cs pin,
            when non-cs pin is used as chipselect*/
        if (NULL_PTR != pcJobConfig->pfStartNotification)
        {
            pcJobConfig->pfStartNotification();
        }
        else
        {
            /* Do nothing */
        }
        
        pDspiDev = &Spi_Dspi_aDeviceState[pcJobConfig->HWUnit];
        /* Generate CTAR selection */
        u32SelectedCTAR = DSPI_GENERATE_CTAR_U32((uint32)pDspiDev->pcHWUnitConfig->u8NrOfCTAR);

        /* mark HW unit as busy */
        *(pDspiDev->pStatus) = SPI_BUSY;

        /* retrieve the CTAR setting for the corresponding external device */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
        u32Ctar = pcJobConfig->ExternalDeviceAttrs.u32CTAR[Spi_Dspi_ClockMode];
#else
        u32Ctar = pcJobConfig->ExternalDeviceAttrs.u32CTAR;
#endif

        /* set the CMD part of the word to be transmitted */
        pDspiDev->u32CurrentCmd = (pcJobConfig->ExternalDeviceAttrs.u32CMD | u32SelectedCTAR);

        /* iterate on all channels in job */
        pDspiDev->RemainingChannels = pcJobConfig->NumChannels;
        pcChannelIndexList = (*pcJobConfig->pcChannelIndexList);
        while((Spi_ChannelType)0u < pDspiDev->RemainingChannels)
        {
            pDspiDev->RemainingChannels--;

            /* Get the channel ID & configuration */
            Channel = *pcChannelIndexList;
            pcChannelConfig = &(*Spi_pcSpiConfigPtr->pcChannelConfig)[Channel];
            pChannelState = pcChannelConfig->pChannelState;
            /* Get Channel Attributes */
            pcDspiChannelAttributesConfig = &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcChannelAttributesConfig)[Channel];
            /* set CTAR register */
            /**
            * @note The call is blocking till the HWUnit exits
            *       the running state.
            */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(pDspiDev->u32DspiCTARAddress,(u32Ctar | pcDspiChannelAttributesConfig->u32CMD));

            /* retrieve RX/TX buffers and the transmitted/received lengths */
            if (pChannelState->u8Flags & ((uint8)SPI_CHANNEL_FLAG_TX_DEFAULT_U8))
            {
                pDspiDev->pCurrentTxBuffer = NULL_PTR;
            }
            else
            {
                pDspiDev->pCurrentTxBuffer = pcChannelConfig->pcBufferDescriptor->pBufferTX;
            }
            pDspiDev->pCurrentRxBuffer = pcChannelConfig->pcBufferDescriptor->pBufferRX;

            LengthTX = pChannelState->Length;
            #if (SPI_FORCE_DATA_TYPE == STD_ON)
            /*
            * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            if (1u == pcDspiChannelAttributesConfig->u8DataWidth)
            {
                /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                if (SPI_DATA_WIDTH_16 == pcDspiChannelAttributesConfig->u8DataWidth)
                {
                    LengthTX /= 2u;
                }
                else
                {
                    /* Do nothing */
                }
            }
            else
            {
                /* Do nothing */
            }
            #endif
            /* Update RemainingData for new channel */
            pDspiDev->RemainingData = LengthTX;
            
            /* synchronous transmission for a channel */
            TransmitChannelStatus = Spi_Dspi_SyncTransmitChannel(pDspiDev, Channel);
            
            /*
            * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
            *       the only allowed form of pointer arithmetic.
            */
            pcChannelIndexList++;
        } /* while (RemainingChannels) */

        /* release the HW unit */
        *(pDspiDev->pStatus) = SPI_IDLE;

        if ((Std_ReturnType)E_OK == TransmitChannelStatus)
        {
            /* Job is done set the status as OK */
            pJobState->Result = SPI_JOB_OK;
            /* Perform job EndNotification (if there is one) */
            if (NULL_PTR != pcJobConfig->pfEndNotification)
            {
                pcJobConfig->pfEndNotification();
            }
            else
            {
                /* Do nothing */
            }
        }
        else
        {
            /* transmission failed */
            /* set the remaining job status (including the current one) as FAILED */
            do
            {
                /* Set the job status as FAILED */
                Spi_aSpiJobState[*pcJobIndexList].Result = SPI_JOB_FAILED;
                /* Update pointer position for pcJobConfig */
                pcJobConfig = &(*Spi_pcSpiConfigPtr->pcJobConfig)[*pcJobIndexList];
                /* Perform job EndNotification (if there is one) */
                if (NULL_PTR != pcJobConfig->pfEndNotification)
                {
                    pcJobConfig->pfEndNotification();
                }
                else
                {
                    /* Do nothing */
                }
                /*
                * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
                *       the only allowed form of pointer arithmetic.
                */
                pcJobIndexList++;
                JobsCount--;
            } while (0u < JobsCount);
            JobsCount = 1u;  /* needed to end correctly the outer loop */
            Status = (Std_ReturnType)E_NOT_OK;
        }
        /* iterate to next job in sequence */
        /*
        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        pcJobIndexList++;
        JobsCount--;
    } /* while (JobsCount > 0u) */

    if ((Std_ReturnType)E_OK != Status)
    {
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_FAILED);
        }
        else
        {
            /* Do nothing */
        }
#endif
    }
    else
    {
#if (SPI_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)        
        /* Call Dem_ReportErrorStatus. */
        if ((uint32)STD_ON == Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Spi_pcSpiConfigPtr->Spi_E_Hardware_ErrorCfg.id, DEM_EVENT_STATUS_PASSED);
        }
        else
        {
            /* Do nothing */
        }
#endif 
    }
    return Status;
}
#endif /* #if ( (SPI_LEVEL_DELIVERED == LEVEL2) || (SPI_LEVEL_DELIVERED == LEVEL0) ) */

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief   Low-level timed serial bus mode setting function.
* @details Initialize all the Spi units with CSI configuration.
*          Also configure the master configuration register for
*          parameters like DSPI configuration, continuous clock enable,
*          master mode selection etc.
*
* @param[in]  Spi_JobType  Job to be configured in TSB mode.
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Dspi_SetTSBMode
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob
    )
{
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
    VAR(uint8, AUTOMATIC) u8HWoffset;
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
    P2CONST(Spi_TSBConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobTSBConfig;
    VAR(uint32, AUTOMATIC) u32SpiNormalJob;
    VAR(uint32, AUTOMATIC) u32MCR;
    VAR(uint32, AUTOMATIC) u32DSICR;
    VAR(uint32, AUTOMATIC) u32DSICR1;
    VAR(uint32, AUTOMATIC) u32CTAR;
#ifdef ITSB_MODE_SUPPORTED
#if (SPI_ITSB_MODE == STD_ON)
#if (ITSB_TIMESLOT_MODE == STD_ON)
    VAR(uint32, AUTOMATIC) u32TSL;
    VAR(uint32, AUTOMATIC) u32TS_CONF;
#endif /*(ITSB_TIMESLOT_MODE == STD_ON)*/
#endif /*(SPI_ITSB_MODE == STD_ON)*/    
#endif /* ITSB_MODE_SUPPORTED */

    /*
    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    pcJobTSBConfig = &Spi_pcSpiConfigPtr->pcJobTSBConfig[TSBJob];

    u32SpiNormalJob = pcJobTSBConfig->Spi_TSB_Job;
    pcJobConfig = &(*Spi_pcSpiConfigPtr->pcJobConfig)[u32SpiNormalJob];


    /* Logical Spi HWUnit */
    HWUnit = pcJobConfig->HWUnit;
    pcHWUnitConfig = &(*Spi_pcSpiConfigPtr->pcHWUnitConfig)[HWUnit];
    /* Peripheral Registers */
    u8HWoffset = pcHWUnitConfig->u8Offset;
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    u32MCR = REG_READ32(DSPI_MCR_ADDR32(u8HWoffset));
    /*2) configuration of DSPI_MCR_ADDR32*/
    /* Master mode selection*/
    /* Determine chip select inactive states for each PCS */  /* high by default */
    /* CSI configuration of the DSPI*/
    /* Enable Transmit FIFO*/
    /* Disable Receive FIFO.*/
    /* Continuous SCK Enable*/
    /* HALT = 1; stop transfers*/
    u32MCR = (u32MCR & DSPI_MCR_PCSIS_ALL_U32) | DSPI_MCR_MSTR_U32 | DSPI_MCR_DCONF_CSI_U32
             | DSPI_MCR_RX_FIFO_U32 | DSPI_MCR_CONT_SCKE_U32 | DSPI_MCR_HALT_U32;

    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_MCR_ADDR32(u8HWoffset), (u32MCR & DSPI_MCR_RESERVED_MASK_U32));
    /*2) configuration of DSPI_DSICR*/
    /*Timed Serial Bus Configuration enabled*/
    /*ctar3 selection*/

    /*3)Set DSPI_DSICR attributes Transmit Data Source(TXSS), Change in data transfer(CID),
        DSI peripheral Chip Select(DPCSx)*/
    u32DSICR = pcJobTSBConfig->ExternalDeviceTSBAttrs.u32DSICR;
#ifdef ITSB_MODE_SUPPORTED
#if (SPI_ITSB_MODE == STD_ON)
    if( (boolean)TRUE == pcJobTSBConfig->ExternalDeviceTSBAttrs.bIsITSBmode )
    {
        REG_WRITE32(DSPI_DSICR_ADDR32(u8HWoffset), \
                     ((u32DSICR|DSPI_DSICR_ITSBC_U32|DSPI_DSICR_DSICTAS_CTAR3_U32) & DSPI_DSICR_RESERVED_MASK_U32)
                   /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                   );
    }
    else
    {
#endif /*(SPI_ITSB_MODE == STD_ON)*/
        REG_WRITE32(DSPI_DSICR_ADDR32(u8HWoffset), \
                     ((u32DSICR|DSPI_DSICR_TSBC_U32|DSPI_DSICR_DSICTAS_CTAR3_U32) & DSPI_DSICR_RESERVED_MASK_U32)
                   /*
                    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                    *     type and an integral type.
                    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                    */
                   );
#if (SPI_ITSB_MODE == STD_ON)
    }
#endif /*(SPI_ITSB_MODE == STD_ON)*/
#else
    REG_WRITE32(DSPI_DSICR_ADDR32(u8HWoffset), \
                 ((u32DSICR|DSPI_DSICR_TSBC_U32|DSPI_DSICR_DSICTAS_CTAR3_U32) & DSPI_DSICR_RESERVED_MASK_U32)
               /*
                * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
                *     type and an integral type.
                * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
                */
               );
#endif /* ITSB_MODE_SUPPORTED */
    /*4)Set DSPI_DSICR1 attributes Timed Serial Bus Operation Count(TSBCNT),
        Peripheral chip select for the second part of the frame with dual receiver */
    u32DSICR1 = pcJobTSBConfig->ExternalDeviceTSBAttrs.u32DSICR1;
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_DSICR1_ADDR32(u8HWoffset), ((u32DSICR1) & DSPI_DSICR1_RESERVED_MASK_U32));

    /*5)Set ctar3 attributes*/

    /*Update the ctar3 based on clock mode selected*/
    #if (SPI_DUAL_CLOCK_MODE == STD_ON)
    u32CTAR = pcJobTSBConfig->ExternalDeviceTSBAttrs.u32CTAR[Spi_Dspi_ClockMode];
    #else
    u32CTAR = pcJobTSBConfig->ExternalDeviceTSBAttrs.u32CTAR;
    #endif
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_CTAR3_ADDR32(u8HWoffset), u32CTAR);
    /*LSB first, when operating in TSB configuration, this bit
    should be set to be compliant to MSC specification*/
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_BIT_SET32(DSPI_CTAR3_ADDR32(u8HWoffset), DSPI_CTAR_LSBFE_MASK_U32);
#ifdef ITSB_MODE_SUPPORTED    
#if (SPI_ITSB_MODE == STD_ON)
#if (ITSB_TIMESLOT_MODE == STD_ON)
    /* Update Time Slot Register */
    u32TSL = pcJobTSBConfig->ExternalDeviceTSBAttrs.u32TSL;
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_TSL_ADDR32(u8HWoffset), u32TSL);
    /* Update Time Slot Configuration */
    u32TS_CONF = pcJobTSBConfig->ExternalDeviceTSBAttrs.u32TS_CONF;
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_TS_CONF_ADDR32(u8HWoffset), u32TS_CONF);
#endif
#else
    {
        /* Do nothing */
    }
#endif /* (SPI_ITSB_MODE == STD_ON) */
#endif /* ITSB_MODE_SUPPORTED */
    /*6) Start transfer*/
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_BIT_CLEAR32(DSPI_MCR_ADDR32(u8HWoffset), DSPI_MCR_HALT_U32);
}
/*================================================================================================*/
/**
* @brief   Low-level timed serial bus mode de-initialisation function.
* @details DSPI hardware is de-initialised to master and SPI mode
*
* @param[in]     Spi_JobType Job configured in TSB mode
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Dspi_StopTSBMode
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob
    )
{
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
    P2CONST(Spi_TSBConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobTSBConfig;
    VAR(uint32, AUTOMATIC) u32SpiNormalJob;

    /*
    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    pcJobTSBConfig = &Spi_pcSpiConfigPtr->pcJobTSBConfig[TSBJob];

    u32SpiNormalJob = pcJobTSBConfig->Spi_TSB_Job;
    pcJobConfig = &(*Spi_pcSpiConfigPtr->pcJobConfig)[u32SpiNormalJob];

    /* Logical Spi HWUnit */
    HWUnit = pcJobConfig->HWUnit;

    /* De- initialize the DSPI driver */
    Spi_Dspi_DeInit(HWUnit);

    /* Reset configuration pointer */
    Spi_pcSpiConfigPtr = NULL_PTR;
}
/*================================================================================================*/
/**
* @brief   Low-level ASDR write register while in  timed serial bus mode
* @details Low-level ASDR write register while in  timed serial bus mode
*
* @param[in]     Spi_JobType Job configured in TSB mode
*
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Dspi_TSB_ASDR_DataUpdate
    (
        VAR(Spi_JobType, AUTOMATIC) TSBJob,
        P2CONST(uint32, AUTOMATIC,SPI_APPL_CONST) ASDR_Data
    )
{
    VAR(Spi_HWUnitType, AUTOMATIC) HWUnit;
    VAR(uint8, AUTOMATIC) u8HWoffset;
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
    P2CONST(Spi_TSBConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobTSBConfig;
    VAR(uint32, AUTOMATIC) u32SpiNormalJob;
    VAR(uint32, AUTOMATIC) u32DSICR1;

    /*
    * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
    *       the only allowed form of pointer arithmetic.
    */
    pcJobTSBConfig = &Spi_pcSpiConfigPtr->pcJobTSBConfig[TSBJob];

    u32SpiNormalJob = pcJobTSBConfig->Spi_TSB_Job;
    pcJobConfig = &(*Spi_pcSpiConfigPtr->pcJobConfig)[u32SpiNormalJob];

    /* Logical Spi HWUnit */
    HWUnit = pcJobConfig->HWUnit;
    pcHWUnitConfig = &(*Spi_pcSpiConfigPtr->pcHWUnitConfig)[HWUnit];
    /* Peripheral Registers */
    u8HWoffset = pcHWUnitConfig->u8Offset;    
    /* Check DSI 64-bit Mode in DSPI_DSICR1 register*/
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    u32DSICR1 = REG_READ32(DSPI_DSICR1_ADDR32(u8HWoffset));
    /*Update data on ASDR register*/
    if( 0u != ( u32DSICR1 & DSPI_DSICR1_DSI64E_MASK_U32 ))
    {
        /* Update ASDR1 before ASDR0 */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /*
        * @violates @ref Spi_DSPI_c_REF_6 Array indexing shall be
        *       the only allowed form of pointer arithmetic.
        */
        REG_WRITE32(DSPI_ASDR1_ADDR32(u8HWoffset), *(ASDR_Data + 1));
    }
    /*
    * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
    *     type and an integral type.
    * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(DSPI_ASDR_ADDR32(u8HWoffset), *ASDR_Data);  
}
#endif /*(SPI_TSB_MODE == STD_ON)*/
#endif /*TSB_MODE_SUPPORTED*/

#ifdef SPI_SLAVE_HIGH_SPEED_SUPPORT
#if(SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON)
#if ((SPI_DMA_USED == STD_ON) && \
    ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2)))
/*================================================================================================*/
/**
* @brief   This function is called by DMA notification for each DSPI peripheral on Slave mode with High Speed.
* @details Non-AutoSar support function used by interrupt service
*          routine. 
*
* @param[in]     pDspiDev     Specifies which DSPI peripheral is used
*
* @pre  Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2
*       and SPI_DMA_USED must be STD_ON
*
*/
/*================================================================================================*/
static FUNC(void, SPI_CODE) Spi_Dspi_TransferDmaContinue
    (
        P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev
    )
{
    P2CONST(Spi_Ipw_DeviceAttributesConfigType, AUTOMATIC, SPI_APPL_CONST) pcDeviceAttributesConfig;
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) pTxTcdAddr = pDspiDev->pu32TxDmaTcd;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, SPI_APPL_DATA) pRxTcdAddr = pDspiDev->pu32RxDmaTcd;
    VAR(Spi_NumberOfDataType, AUTOMATIC) TransferSize = pDspiDev->SentFrames;
    P2CONST(Spi_ChannelConfigType, AUTOMATIC, SPI_APPL_CONST) pChannelConfig =
        &(*Spi_pcSpiConfigPtr->pcChannelConfig)[*(pDspiDev->pcCurrentChannelIndexPointer)];
    
    /* retrieve the device configuration for the sequence */
    pcDeviceAttributesConfig =
        &(*Spi_pcSpiConfigPtr->pcAttributesConfig->pcDeviceAttributesConfig)
            [pDspiDev->pcCurrentJob->ExternalDevice];   
    
    if((uint8)STD_ON == pcDeviceAttributesConfig->u8SlaveHighSpeed)
    {
        /* Update receive address again */
        if(pDspiDev->ReceivedData == pChannelConfig->FrameCnt)
        {
            pDspiDev->ReceivedData = 0u;
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaTcdSetDaddr(pRxTcdAddr,(uint32)(pDspiDev->pCurrentRxBuffer));
        }
        else
        {
            /* Do nothing */
        }
        /* Update transfer address again */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaTcdSetSaddr(pTxTcdAddr, (uint32)(pDspiDev->pCurrentTxBuffer));
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update TX transfer size */
        Mcl_DmaTcdSetIterCount(pTxTcdAddr, (uint16)(TransferSize));
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        /* update RX transfer size */
        Mcl_DmaTcdSetIterCount(pRxTcdAddr, (uint16)(TransferSize));
        /* start RX before TX! */
        pcHWUnitConfig = pDspiDev->pcHWUnitConfig;
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaEnableHwRequest(pcHWUnitConfig->u8RxDmaChannel);
        /*
        * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
        * a pointer to a function and any type other than an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        Mcl_DmaEnableHwRequest(pcHWUnitConfig->u8TxDmaChannel);        
    }
    else
    {
        /* Do nothing */
    }
}
#endif /* ((SPI_DMA_USED == STD_ON) && ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))) */
#endif /* SPI_SLAVE_HIGH_SPEED_SUPPORT == STD_ON */
#endif /* SPI_SLAVE_HIGH_SPEED_SUPPORT */

#if ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON))
/*================================================================================================*/
/**
* @brief   This function is used to request the cancelation of the given sequence for Slave and stop sequence immediately.
* @details This function is used to request the cancelation of the given sequence for Slave and stop sequence immediately.
*          - Sync or Async:       Asynchronous
*
* @param[in]      Sequence            Sequence ID
*
* @pre  parameters: (SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON)
*                             
*/
/*================================================================================================*/
FUNC(void, SPI_CODE) Spi_Dspi_SlaveCancel(VAR(Spi_SequenceType, AUTOMATIC) Sequence)
{
    P2CONST(Spi_JobConfigType, AUTOMATIC, SPI_APPL_CONST) pcJobConfig;
    VAR(Spi_JobType, AUTOMATIC) Job;
    P2VAR(Spi_Dspi_DeviceStateType, AUTOMATIC, SPI_APPL_DATA) pDspiDev;
    P2VAR(Spi_SequenceStateType, AUTOMATIC, SPI_APPL_DATA) pSequenceState;
    P2CONST(Spi_JobType, AUTOMATIC, SPI_APPL_CONST) pcJob;
    VAR(uint32, AUTOMATIC) u32SRval;
    VAR(uint8, AUTOMATIC) u8HWoffset;
    VAR(uint32, AUTOMATIC) u32Timeout = SPI_TIMEOUT_COUNTER;
#if (SPI_DMA_USED == STD_ON)
    P2CONST(Spi_HWUnitConfigType, AUTOMATIC, SPI_APPL_CONST) pcHWUnitConfig;
#endif
    
    /* Set sequence state to Cancel */
    Spi_aSpiSequenceState[Sequence].Result = SPI_SEQ_CANCELLED;
    
    pSequenceState = &Spi_aSpiSequenceState[Sequence];
    pcJob = pSequenceState->pcCurrentJobIndexPointer;
    Job = *pcJob;
    pcJobConfig = &(*Spi_pcSpiConfigPtr->pcJobConfig)[Job];
    pDspiDev = &Spi_Dspi_aDeviceState[pcJobConfig->HWUnit];
    if(SPI_SLAVE == (Spi_ModeType)pDspiDev->pcHWUnitConfig->u8SpiPhyUnitMode)
    {
        /* Stop DMA transfer */
    #if (SPI_DMA_USED == STD_ON)
        if (0u != pDspiDev->pcHWUnitConfig->u16UseDma)
        {
            /* Disable TX before RX */
            pcHWUnitConfig = pDspiDev->pcHWUnitConfig;
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaDisableHwRequest(pcHWUnitConfig->u8TxDmaChannel);
            /*
            * @violates @ref Spi_DSPI_c_REF_3 Conversions shall not be performed between
            * a pointer to a function and any type other than an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            Mcl_DmaDisableHwRequest(pcHWUnitConfig->u8RxDmaChannel);
        }
        else
        {
            /* Do nothing */
        }
    #endif
        u8HWoffset = pDspiDev->pcHWUnitConfig->u8Offset;
        /* Need to change the state of SPI unit to Stop mode */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_BIT_SET32(DSPI_MCR_ADDR32(u8HWoffset), DSPI_MCR_HALT_U32); 
        /* Wait untill the module is STOPPED. This way no data is in Shift Register */
        do
        {
            u32Timeout--;
            /* end the loop if timeout expired */
            if (0u == u32Timeout)
            {
                /* force the end of the outer loop too */
                break;
            }
            else
            {
                /* Do nothing */
            }
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            u32SRval = REG_READ32(pDspiDev->u32DspiSRAddress) & DSPI_SR_TXRXS_W1C;
        }while(0u != u32SRval);
        
        /* Clear TX FIFO and RX FIFO */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        u32SRval = REG_READ32(pDspiDev->u32DspiSRAddress) & (DSPI_SR_TXCTR_MASK_U32 | DSPI_SR_RXCTR_MASK_U32);
        if(0u != u32SRval)
        {
            /* Discard all frames in FIFO */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_BIT_SET32(DSPI_MCR_ADDR32(u8HWoffset), (DSPI_MCR_CLR_RXF_U32 | DSPI_MCR_CLR_TXF_U32)); 
            /* Clear Status register */
            /*
            * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
            *     type and an integral type.
            * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
            */
            REG_WRITE32(DSPI_SR_ADDR32(u8HWoffset), DSPI_SR_INT_MASK_U32 & DSPI_SR_RESERVED_MASK_U32);
        }
        else
        {
            /* Do nothing */
        }
        /* Clear HALT bit for continuing transmission */
        /*
        * @violates @ref Spi_DSPI_c_REF_3 A cast should not be performed between a pointer
        *     type and an integral type.
        * @violates @ref Spi_DSPI_c_REF_12 A cast should not be performed between a pointer type and an integral type.
        */
        REG_BIT_CLEAR32(DSPI_MCR_ADDR32(u8HWoffset), DSPI_MCR_HALT_U32);
        
        Spi_JobTransferFinished(pcJobConfig);
    }
    else
    {
        /* Do nothing */
    }
}
#endif  /* ((SPI_CANCEL_API == STD_ON) && (SPI_SLAVE_SUPPORT == STD_ON)) */
/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_DSPI_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_DSPI_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif

/** @} */
