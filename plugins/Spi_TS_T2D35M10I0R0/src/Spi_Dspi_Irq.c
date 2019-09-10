/**
*   @file    Spi_Dspi_Irq.c
*   @implements     Spi_Dspi_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Post-Build(PB) configuration file.
*   @details Generated Post-Build(PB) configuration file.
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
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Spi_Dspi_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1,
* #include statements in a file should only be preceded by other preprocessor directives or comments.
* AUTOSAR imposes the specification of the sections in which certain parts of the driver must be placed.
*
* @section Spi_Dspi_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Spi_Dspi_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character signifiance and case sensitivity are 
* supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Spi_Dspi_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function
* and any type other than an integral type.
* This violation can not be avoided because it appears when addressing memory mapped registers
* or other hardware specific features.
*
* @section Spi_Dspi_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall
* have internal linkage unless external linkage is required.
* State variables may be used by LLD layer.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Spi.h"
#include "Spi_DSPI.h"
/*
* @violates @ref Spi_Dspi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
#include "Mcal.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/*
* @violates @ref Spi_Dspi_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/

#define SPI_MODULE_ID_IRQ_C                      83
#define SPI_VENDOR_ID_IRQ_C                      43
#define SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define SPI_AR_RELEASE_MINOR_VERSION_IRQ_C       2
/*
* @violates @ref Spi_Dspi_Irq_c_REF_4 The compiler/linker shall be checked to ensure that 31 character 
* signifiance and case sensitivity are supported for external identifiers.
*/

#define SPI_AR_RELEASE_REVISION_VERSION_IRQ_C    2
#define SPI_SW_MAJOR_VERSION_IRQ_C               1
#define SPI_SW_MINOR_VERSION_IRQ_C               0
#define SPI_SW_PATCH_VERSION_IRQ_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if this header file and Spi.h are of the same vendor */
#if (SPI_VENDOR_ID_IRQ_C != SPI_VENDOR_ID)
    #error "Spi_Dspi_Irq.c and Spi.h have different vendor ids"
#endif
/* Check if current file and SPI header file are of the same Autosar version */
#if ((SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (SPI_AR_RELEASE_MINOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MINOR_VERSION) || \
     (SPI_AR_RELEASE_REVISION_VERSION_IRQ_C != SPI_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Spi_Dspi_Irq.c and Spi.h are different"
#endif
/* Check if current file and SPI header file are of the same Software version */
#if ((SPI_SW_MAJOR_VERSION_IRQ_C != SPI_SW_MAJOR_VERSION) || \
     (SPI_SW_MINOR_VERSION_IRQ_C != SPI_SW_MINOR_VERSION) || \
     (SPI_SW_PATCH_VERSION_IRQ_C != SPI_SW_PATCH_VERSION))
    #error "Software Version Numbers of Spi_Dspi_Irq.c and Spi_DSPI.h are different"
#endif

/* Check if this header file and Spi_Cfg.h are of the same vendor */
#if (SPI_VENDOR_ID_IRQ_C != SPI_VENDOR_ID_DSPI)
    #error "Spi_Dspi_Irq.c and Spi_DSPI.h have different vendor ids"
#endif

#if (( SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MAJOR_VERSION_DSPI) || \
     ( SPI_AR_RELEASE_MINOR_VERSION_IRQ_C    != SPI_AR_RELEASE_MINOR_VERSION_DSPI) || \
     ( SPI_AR_RELEASE_REVISION_VERSION_IRQ_C != SPI_AR_RELEASE_REVISION_VERSION_DSPI))
#error "AutoSar Version Numbers of Spi_DSPI.h and Spi_Dspi_Irq.c are different"
#endif

#if (( SPI_SW_MAJOR_VERSION_IRQ_C != SPI_SW_MAJOR_VERSION_DSPI) || \
     ( SPI_SW_MINOR_VERSION_IRQ_C != SPI_SW_MINOR_VERSION_DSPI) || \
     ( SPI_SW_PATCH_VERSION_IRQ_C != SPI_SW_PATCH_VERSION_DSPI))
#error "Software Version Numbers of Spi_Dspi_Irq.c and Spi_DSPI.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcal header file are of the same Autosar version */
    #if ((SPI_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (SPI_AR_RELEASE_MINOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Spi_Dspi_Irq.c and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                  LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#define SPI_START_SEC_CODE
/*
* @violates @ref Spi_Dspi_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/

    /* Notifications */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    #if (SPI_DMA_USED == STD_ON)
        #ifdef DSPI_0_ENABLED
            #if (DSPI_0_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_0(void);
            #endif
        #endif

        #ifdef DSPI_1_ENABLED
            #if (DSPI_1_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_1(void);
            #endif
        #endif

        #ifdef DSPI_2_ENABLED
            #if (DSPI_2_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_2(void);
            #endif
        #endif

        #ifdef DSPI_3_ENABLED
            #if (DSPI_3_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_3(void);
            #endif
        #endif

        #ifdef DSPI_4_ENABLED
            #if (DSPI_4_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_4(void);
            #endif
        #endif
        
        #ifdef DSPI_5_ENABLED
            #if (DSPI_5_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_5(void);
            #endif
        #endif
        
        #ifdef DSPI_6_ENABLED
            #if (DSPI_6_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_6(void);
            #endif
        #endif
        
        #ifdef DSPI_7_ENABLED
            #if (DSPI_7_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_7(void);
            #endif
        #endif
        
        #ifdef DSPI_8_ENABLED
            #if (DSPI_8_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_8(void);
            #endif
        #endif
        
        #ifdef DSPI_9_ENABLED
            #if (DSPI_9_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_9(void);
            #endif
        #endif
        
        #ifdef DSPI_10_ENABLED
            #if (DSPI_10_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_10(void);
            #endif
        #endif
        
        #ifdef DSPI_11_ENABLED
            #if (DSPI_11_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_11(void);
            #endif
        #endif
        
        #ifdef DSPI_12_ENABLED
            #if (DSPI_12_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_12(void);
            #endif
        #endif

        #ifdef SPI_0_ENABLED
            #if (SPI_0_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_0(void);
            #endif
        #endif

        #ifdef SPI_1_ENABLED
            #if (SPI_1_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_1(void);
            #endif
        #endif

        #ifdef SPI_2_ENABLED
            #if (SPI_2_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_2(void);
            #endif
        #endif

        #ifdef SPI_3_ENABLED
            #if (SPI_3_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_3(void);
            #endif
        #endif

        #ifdef SPI_4_ENABLED
            #if (SPI_4_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_4(void);
            #endif
        #endif
        
        #ifdef SPI_5_ENABLED
            #if (SPI_5_ENABLED == STD_ON)
    FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_5(void);
            #endif
        #endif
    #endif
#endif


    /* Interrupt service routines */

#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    #ifdef DSPI_0_ENABLED
        #if (DSPI_0_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_0);
        #endif
    #endif

    #ifdef DSPI_1_ENABLED
        #if (DSPI_1_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_1);
        #endif
    #endif

    #ifdef DSPI_2_ENABLED
        #if (DSPI_2_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_2);
        #endif
    #endif

    #ifdef DSPI_3_ENABLED
        #if (DSPI_3_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_3);
        #endif
    #endif

    #ifdef DSPI_4_ENABLED
        #if (DSPI_4_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_4);
        #endif
    #endif
    
    #ifdef DSPI_5_ENABLED
        #if (DSPI_5_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_5);
        #endif
    #endif
    
    #ifdef DSPI_6_ENABLED
        #if (DSPI_6_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_6);
        #endif
    #endif
    
    #ifdef DSPI_7_ENABLED
        #if (DSPI_7_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_7);
        #endif
    #endif
    
    #ifdef DSPI_8_ENABLED
        #if (DSPI_8_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_8);
        #endif
    #endif
    
    #ifdef DSPI_9_ENABLED
        #if (DSPI_9_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_9);
        #endif
    #endif
    
    #ifdef DSPI_10_ENABLED
        #if (DSPI_10_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_10);
        #endif
    #endif
    
    #ifdef DSPI_11_ENABLED
        #if (DSPI_11_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_11);
        #endif
    #endif
    
    #ifdef DSPI_12_ENABLED
        #if (DSPI_12_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_DSPI_12);
        #endif
    #endif
    
    #ifdef SPI_0_ENABLED
        #if (SPI_0_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_SPI_0);
        #endif
    #endif

    #ifdef SPI_1_ENABLED
        #if (SPI_1_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_SPI_1);
        #endif
    #endif

    #ifdef SPI_2_ENABLED
        #if (SPI_2_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_SPI_2);
        #endif
    #endif

    #ifdef SPI_3_ENABLED
        #if (SPI_3_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_SPI_3);
        #endif
    #endif

    #ifdef SPI_4_ENABLED
        #if (SPI_4_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_SPI_4);
        #endif
    #endif
    
    #ifdef SPI_5_ENABLED
        #if (SPI_5_ENABLED == STD_ON)
    ISR(Spi_Dspi_IsrTCF_SPI_5);
        #endif
    #endif
#endif

/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 0. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 0
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_0_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
#if ((SPI_LEVEL_DELIVERED == LEVEL1) || (SPI_LEVEL_DELIVERED == LEVEL2))
    #if (SPI_DMA_USED == STD_ON)
        #ifdef DSPI_0_ENABLED
            #if (DSPI_0_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_0(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_0_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx notification for the DSPI 1. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 1
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_1_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
        #ifdef DSPI_1_ENABLED
            #if (DSPI_1_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_1(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_1_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/**
* @brief   This function is the DMA Rx notification for the DSPI 2. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 2
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_2_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
        #ifdef DSPI_2_ENABLED
            #if (DSPI_2_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_2(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_2_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 3. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 3
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_3_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_3_ENABLED
            #if (DSPI_3_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_3(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_3_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 4. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 4
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_4_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_4_ENABLED
            #if (DSPI_4_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_4(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_4_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 5. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 5
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_5_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_5_ENABLED
            #if (DSPI_5_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_5(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_5_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 6. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 6
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_6_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_6_ENABLED
            #if (DSPI_6_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_6(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_6_HWUNIT));
}
            #endif
        #endif  
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 7. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 7
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_7_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_7_ENABLED
            #if (DSPI_7_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_7(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_7_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 8. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 8
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_8_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_8_ENABLED
            #if (DSPI_8_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_8(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_8_HWUNIT));
}
            #endif
        #endif 
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 9. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 9
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_9_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_9_ENABLED
            #if (DSPI_9_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_9(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_9_HWUNIT));
}
            #endif
        #endif  
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 10. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 10
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_10_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_10_ENABLED
            #if (DSPI_10_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_10(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_10_HWUNIT));
}
            #endif
        #endif 
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 11. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 11
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_11_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_11_ENABLED
            #if (DSPI_11_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_11(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_11_HWUNIT));
}
            #endif
        #endif 
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the DSPI 12. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for DSPI 12
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_12_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef DSPI_12_ENABLED
            #if (DSPI_12_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_DSPI_12(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(DSPI_12_HWUNIT));
}
            #endif
        #endif        
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the SPI 0. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for SPI 0
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_0_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef SPI_0_ENABLED
            #if (SPI_0_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_0(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(SPI_0_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the SPI 1. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for SPI 1
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_1_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef SPI_1_ENABLED
            #if (SPI_1_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_1(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(SPI_1_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the SPI 2. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for SPI 2
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_2_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef SPI_2_ENABLED
            #if (SPI_2_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_2(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(SPI_2_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the SPI 3. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for SPI 3
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_3_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef SPI_3_ENABLED
            #if (SPI_3_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_3(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(SPI_3_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the SPI 4. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for SPI 4
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_4_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef SPI_4_ENABLED
            #if (SPI_4_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_4(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(SPI_4_HWUNIT));
}
            #endif
        #endif
/*================================================================================================*/
/** 
* @brief   This function is the DMA Rx notification for the SPI 5. 
* @details Non-AutoSar support function used by MCL interrupt service routine
            for the DMA Rx for SPI 5
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_5_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
        #ifdef SPI_5_ENABLED
            #if (SPI_5_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC (void, SPI_CODE) Spi_Dspi_IsrRxDma_SPI_5(void)
{
    Spi_Dspi_IsrDmaRx(DSPI_HWUNIT2DSPI(SPI_5_HWUNIT));
}
            #endif
        #endif
    #endif /* End SPI_DMA_USED */

/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 0.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 0
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_0_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef DSPI_0_ENABLED
        #if (DSPI_0_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_0)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_0_HWUNIT), DSPI_0_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 1.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 1
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_1_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef DSPI_1_ENABLED
        #if (DSPI_1_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_1)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_1_HWUNIT), DSPI_1_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the DSPI 2.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 2.
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_2_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef DSPI_2_ENABLED
        #if (DSPI_2_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_2)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_2_HWUNIT), DSPI_2_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 3. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 3.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_3_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_3_ENABLED
        #if (DSPI_3_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_3)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_3_HWUNIT), DSPI_3_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 4. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 4.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_4_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_4_ENABLED
        #if (DSPI_4_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_4)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_4_HWUNIT), DSPI_4_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 5. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 5.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_5_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_5_ENABLED
        #if (DSPI_5_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_5)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_5_HWUNIT), DSPI_5_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 6. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 6.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_6_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_6_ENABLED
        #if (DSPI_6_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_6)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_6_HWUNIT), DSPI_6_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 7. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 7.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_7_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_7_ENABLED
        #if (DSPI_7_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_7)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_7_HWUNIT), DSPI_7_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 8. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 8.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_8_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_8_ENABLED
        #if (DSPI_8_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_8)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_8_HWUNIT), DSPI_8_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 9. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 9.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_9_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_9_ENABLED
        #if (DSPI_9_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_9)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_9_HWUNIT), DSPI_9_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 10. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 10.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_10_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_10_ENABLED
        #if (DSPI_10_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_10)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_10_HWUNIT), DSPI_10_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 11. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 11.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_11_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_11_ENABLED
        #if (DSPI_11_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_11)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_11_HWUNIT), DSPI_11_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/** 
* @brief   This function is the end-of-queue Rx ISR for the DSPI 12. 
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for DSPI 12.
*     
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter DSPI_12_ENABLED shall be STD_ON.
* 
*/
/*================================================================================================*/
    #ifdef DSPI_12_ENABLED
        #if (DSPI_12_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_DSPI_12)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(DSPI_12_HWUNIT), DSPI_12_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the SPI 0.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for SPI 0
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_0_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef SPI_0_ENABLED
        #if (SPI_0_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_SPI_0)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(SPI_0_HWUNIT), SPI_0_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the SPI 1.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for SPI 1
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_1_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef SPI_1_ENABLED
        #if (SPI_1_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_SPI_1)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(SPI_1_HWUNIT), SPI_1_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the SPI 2.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for SPI 2
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_2_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef SPI_2_ENABLED
        #if (SPI_2_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_SPI_2)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(SPI_2_HWUNIT), SPI_2_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the SPI 3.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for SPI 3
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_3_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef SPI_3_ENABLED
        #if (SPI_3_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_SPI_3)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(SPI_3_HWUNIT), SPI_3_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the SPI 4.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for SPI 4
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_4_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef SPI_4_ENABLED
        #if (SPI_4_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_SPI_4)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(SPI_4_HWUNIT), SPI_4_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
/*================================================================================================*/
/**
* @brief   This function is the end-of-queue Rx ISR for the SPI 5.
* @details Non-AutoSar support function used by interrupt service
*          routine of the end-of-queue Rx for SPI 5
*
* @pre Pre-compile parameter SPI_LEVEL_DELIVERED shall be LEVEL1 or LEVEL2.
* @pre Pre-compile parameter SPI_5_ENABLED shall be STD_ON.
*
*/
/*================================================================================================*/
    #ifdef SPI_5_ENABLED
        #if (SPI_5_ENABLED == STD_ON)
/*
* @violates @ref Spi_Dspi_Irq_c_REF_8 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*/        
ISR(Spi_Dspi_IsrTCF_SPI_5)
{
    Spi_Dspi_IsrFifoRx(DSPI_HWUNIT2DSPI(SPI_5_HWUNIT), SPI_5_OFFSET);
    /*
    * @violates @ref Spi_Dspi_Irq_c_REF_5 Conversions shall not be performed between a pointer to a function
    *       and any type other than an integral type.
    */
    EXIT_INTERRUPT();
}
        #endif
    #endif
#endif /* End SPI_LEVEL_DELIVERED */
/*================================================================================================*/
#define SPI_STOP_SEC_CODE
/*
* @violates @ref Spi_Dspi_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Spi_Dspi_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Spi_MemMap.h"
 
#ifdef __cplusplus
}
#endif

/** @} */



