/**
*   @file    Lin_LINFlex_Irq.c
*   @implements Lin_LINFlex_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Lin - File used by LIN that contain the ISRs.
*   @details This file contains the ISR functions used to serve the LIN interrupts.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_LINFlex_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a 
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_LINFlex_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_LINFlex_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_LINFlex_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section Lin_LINFlex_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Lin_Irq.c
*/
#include "Lin.h"
#include "Lin_LINFlex.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_Irq.c
*/
#define LIN_IRQ_VENDOR_ID_C                    43
#define LIN_AR_RELEASE_MAJOR_VERSION_IRQ_C     4
#define LIN_AR_RELEASE_MINOR_VERSION_IRQ_C     2
/*
* @violates @ref Lin_LINFlex_Irq_c_REF_3 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_IRQ_C  2
#define LIN_SW_MAJOR_VERSION_IRQ_C             1
#define LIN_SW_MINOR_VERSION_IRQ_C             0
#define LIN_SW_PATCH_VERSION_IRQ_C             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_IRQ_VENDOR_ID_C != LIN_VENDOR_ID)
    #error "Lin_Irq.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin.h header file are of the same Autosar version */
#if (((LIN_AR_RELEASE_MAJOR_VERSION_IRQ_C   != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_IRQ_C    != LIN_AR_RELEASE_MINOR_VERSION)) || \
     (LIN_AR_RELEASE_REVISION_VERSION_IRQ_C != LIN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Lin_Irq.c and Lin.h are different"
#endif
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_IRQ_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_IRQ_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_IRQ_C != LIN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Lin_Irq.c and Lin.h are different"
#endif
/* Check if current file and Lin_Linflex header file are of the same vendor */
#if (LIN_IRQ_VENDOR_ID_C != LIN_VENDOR_ID_FLEX)
    #error "Lin_Irq.c and Lin_Linflex.h have different vendor ids"
#endif
/* Check if current file and Lin_Linflex header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_IRQ_C    != LIN_AR_RELEASE_MAJOR_VERSION_FLEX) || \
     (LIN_AR_RELEASE_MINOR_VERSION_IRQ_C    != LIN_AR_RELEASE_MINOR_VERSION_FLEX) || \
     (LIN_AR_RELEASE_REVISION_VERSION_IRQ_C != LIN_AR_RELEASE_REVISION_VERSION_FLEX))
    #error "AutoSar Version Numbers of Lin_Irq.c and Lin_Linflex.h are different"
#endif
/* Check if current file and Lin_Linflex header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_IRQ_C != LIN_SW_MAJOR_VERSION_FLEX) || \
     (LIN_SW_MINOR_VERSION_IRQ_C != LIN_SW_MINOR_VERSION_FLEX) || \
     (LIN_SW_PATCH_VERSION_IRQ_C != LIN_SW_PATCH_VERSION_FLEX))
    #error "Software Version Numbers of Lin_Irq.c and Lin_Linflex.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief          LIN controller interrupts
* @details        LIN controller interrupts
*
*/
#define LIN_START_SEC_CODE
/** 
* @violates @ref Lin_LINFlex_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#if ( LIN_UNIFIED_INTERRUPTS == STD_ON )

    #if defined(LinHWCh_0)
    ISR(Lin_Linflex_Isr_LINFlex_0);
    #endif /* defined(LinHWCh_0) */
    
    #if defined(LinHWCh_1)
    ISR(Lin_Linflex_Isr_LINFlex_1);
    #endif /* defined(LinHWCh_1) */
    
    #if defined(LinHWCh_2)
    ISR(Lin_Linflex_Isr_LINFlex_2);
    #endif /* defined(LinHWCh_2) */
    
    #if defined(LinHWCh_3)
    ISR(Lin_Linflex_Isr_LINFlex_3);
    #endif /* defined(LinHWCh_3) */
    
    #if defined(LinHWCh_4)
    ISR(Lin_Linflex_Isr_LINFlex_4);
    #endif /* defined(LinHWCh_4) */
    
    #if defined(LinHWCh_5)
    ISR(Lin_Linflex_Isr_LINFlex_5);
    #endif /* defined(LinHWCh_5) */
    
    #if defined(LinHWCh_6)
    ISR(Lin_Linflex_Isr_LINFlex_6);
    #endif /* defined(LinHWCh_6) */
    
    #if defined(LinHWCh_7)
    ISR(Lin_Linflex_Isr_LINFlex_7);
    #endif /* defined(LinHWCh_7) */
    
    #if defined(LinHWCh_8)
    ISR(Lin_Linflex_Isr_LINFlex_8);
    #endif /* defined(LinHWCh_8) */
    
    #if defined(LinHWCh_9)
    ISR(Lin_Linflex_Isr_LINFlex_9);
    #endif /* defined(LinHWCh_9) */
    
    #if defined(LinHWCh_10)
    ISR(Lin_Linflex_Isr_LINFlex_10);
    #endif /* defined(LinHWCh_10) */
    
    #if defined(LinHWCh_11)
    ISR(Lin_Linflex_Isr_LINFlex_11);
    #endif /* defined(LinHWCh_11) */
    
    #if defined(LinHWCh_12)
    ISR(Lin_Linflex_Isr_LINFlex_12);
    #endif /* defined(LinHWCh_12) */
    
    #if defined(LinHWCh_13)
    ISR(Lin_Linflex_Isr_LINFlex_13);
    #endif /* defined(LinHWCh_13) */
    
    #if defined(LinHWCh_14)
    ISR(Lin_Linflex_Isr_LINFlex_14);
    #endif /* defined(LinHWCh_14) */
    
    #if defined(LinHWCh_15)
    ISR(Lin_Linflex_Isr_LINFlex_15);
    #endif /* defined(LinHWCh_15) */
    
    #if defined(LinHWCh_16)
    ISR(Lin_Linflex_Isr_LINFlex_16);
    #endif /* defined(LinHWCh_16) */
    
    #if defined(LinHWCh_17)
    ISR(Lin_Linflex_Isr_LINFlex_17);
    #endif /* defined(LinHWCh_17) */

#else

    #if defined(LinHWCh_0)
    ISR(Lin_Linflex_IsrError_LINFlex_0);
    ISR(Lin_Linflex_IsrTx_LINFlex_0);
    ISR(Lin_Linflex_IsrRx_LINFlex_0);
    #endif /* defined(LinHWCh_0) */
    
    #if defined(LinHWCh_1)
    ISR(Lin_Linflex_IsrError_LINFlex_1);
    ISR(Lin_Linflex_IsrTx_LINFlex_1);
    ISR(Lin_Linflex_IsrRx_LINFlex_1);
    #endif /* defined(LinHWCh_1) */
    
    #if defined(LinHWCh_2)
    ISR(Lin_Linflex_IsrError_LINFlex_2);
    ISR(Lin_Linflex_IsrTx_LINFlex_2);
    ISR(Lin_Linflex_IsrRx_LINFlex_2);
    #endif /* defined(LinHWCh_2) */
    
    #if defined(LinHWCh_3)
    ISR(Lin_Linflex_IsrError_LINFlex_3);
    ISR(Lin_Linflex_IsrTx_LINFlex_3);
    ISR(Lin_Linflex_IsrRx_LINFlex_3);
    #endif /* defined(LinHWCh_3) */
    
    #if defined(LinHWCh_4)
    ISR(Lin_Linflex_IsrError_LINFlex_4);
    ISR(Lin_Linflex_IsrTx_LINFlex_4);
    ISR(Lin_Linflex_IsrRx_LINFlex_4);
    #endif /* defined(LinHWCh_4) */
    
    #if defined(LinHWCh_5)
    ISR(Lin_Linflex_IsrError_LINFlex_5);
    ISR(Lin_Linflex_IsrTx_LINFlex_5);
    ISR(Lin_Linflex_IsrRx_LINFlex_5);
    #endif /* defined(LinHWCh_5) */
    
    #if defined(LinHWCh_6)
    ISR(Lin_Linflex_IsrError_LINFlex_6);
    ISR(Lin_Linflex_IsrTx_LINFlex_6);
    ISR(Lin_Linflex_IsrRx_LINFlex_6);
    #endif /* defined(LinHWCh_6) */
    
    #if defined(LinHWCh_7)
    ISR(Lin_Linflex_IsrError_LINFlex_7);
    ISR(Lin_Linflex_IsrTx_LINFlex_7);
    ISR(Lin_Linflex_IsrRx_LINFlex_7);
    #endif /* defined(LinHWCh_7) */
    
    #if defined(LinHWCh_8)
    ISR(Lin_Linflex_IsrError_LINFlex_8);
    ISR(Lin_Linflex_IsrTx_LINFlex_8);
    ISR(Lin_Linflex_IsrRx_LINFlex_8);
    #endif /* defined(LinHWCh_8) */
    
    #if defined(LinHWCh_9)
    ISR(Lin_Linflex_IsrError_LINFlex_9);
    ISR(Lin_Linflex_IsrTx_LINFlex_9);
    ISR(Lin_Linflex_IsrRx_LINFlex_9);
    #endif /* defined(LinHWCh_9) */
    
    #if defined(LinHWCh_10)
    ISR(Lin_Linflex_IsrError_LINFlex_10);
    ISR(Lin_Linflex_IsrTx_LINFlex_10);
    ISR(Lin_Linflex_IsrRx_LINFlex_10);
    #endif /* defined(LinHWCh_10) */
    
    #if defined(LinHWCh_11)
    ISR(Lin_Linflex_IsrError_LINFlex_11);
    ISR(Lin_Linflex_IsrTx_LINFlex_11);
    ISR(Lin_Linflex_IsrRx_LINFlex_11);
    #endif /* defined(LinHWCh_11) */
    
    #if defined(LinHWCh_12)
    ISR(Lin_Linflex_IsrError_LINFlex_12);
    ISR(Lin_Linflex_IsrTx_LINFlex_12);
    ISR(Lin_Linflex_IsrRx_LINFlex_12);
    #endif /* defined(LinHWCh_12) */
    
    #if defined(LinHWCh_13)
    ISR(Lin_Linflex_IsrError_LINFlex_13);
    ISR(Lin_Linflex_IsrTx_LINFlex_13);
    ISR(Lin_Linflex_IsrRx_LINFlex_13);
    #endif /* defined(LinHWCh_13) */
    
    #if defined(LinHWCh_14)
    ISR(Lin_Linflex_IsrError_LINFlex_14);
    ISR(Lin_Linflex_IsrTx_LINFlex_14);
    ISR(Lin_Linflex_IsrRx_LINFlex_14);
    #endif /* defined(LinHWCh_14) */
    
    #if defined(LinHWCh_15)
    ISR(Lin_Linflex_IsrError_LINFlex_15);
    ISR(Lin_Linflex_IsrTx_LINFlex_15);
    ISR(Lin_Linflex_IsrRx_LINFlex_15);
    #endif /* defined(LinHWCh_15) */
    
    #if defined(LinHWCh_16)
    ISR(Lin_Linflex_IsrError_LINFlex_16);
    ISR(Lin_Linflex_IsrTx_LINFlex_16);
    ISR(Lin_Linflex_IsrRx_LINFlex_16);
    #endif /* defined(LinHWCh_16) */
    
    #if defined(LinHWCh_17)
    ISR(Lin_Linflex_IsrError_LINFlex_17);
    ISR(Lin_Linflex_IsrTx_LINFlex_17);
    ISR(Lin_Linflex_IsrRx_LINFlex_17);
    #endif /* defined(LinHWCh_17) */

#endif /* LIN_UNIFIED_INTERRUPTS == STD_ON */

#define LIN_STOP_SEC_CODE
/** 
* @violates @ref Lin_LINFlex_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define LIN_START_SEC_CODE
/** 
* @violates @ref Lin_LINFlex_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#if ( LIN_UNIFIED_INTERRUPTS == STD_ON )

    #if defined(LinHWCh_0)
    /**
    * @brief   Interrupt handle on LinFlex_0.
    * @details This function implements the ISR occurring on 
    *          LinFlex_0.
    * @note    This interrupt handlers is only present if Hardware 
    *          Channel 0 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_0)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_0);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_0);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_0) */
    
    #if defined(LinHWCh_1)
    /**
    * @brief   Interrupt handle on LinFlex_1.
    * @details This function implements the ISR occurring on
    *          LinFlex_1.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 1 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_1)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_1);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_1);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_1) */
    
    #if defined(LinHWCh_2)
    /**
    * @brief   Interrupt handle on LinFlex_2.
    * @details This function implements the ISR occurring on
    *          LinFlex_2.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 2 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_2)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_2);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_2);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_2) */
    
    #if defined(LinHWCh_3)
    /**
    * @brief   Interrupt handle on LinFlex_3.
    * @details This function implements the ISR occurring on
    *          LinFlex_3.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_3)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_3);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_3);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_3) */
    
    #if defined(LinHWCh_4)
    /**
    * @brief   Interrupt handle on LinFlex_4.
    * @details This function implements the ISR occurring on
    *          LinFlex_4.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 4 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_4)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_4);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_4);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_4) */
    
    #if defined(LinHWCh_5)
    /**
    * @brief   Interrupt handle on LinFlex_5.
    * @details This function implements the ISR occurring on
    *          LinFlex_5.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 5 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_5)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_5);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_5);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_5) */
    
    #if defined(LinHWCh_6)
    /**
    * @brief   Interrupt handle on LinFlex_2.
    * @details This function implements the ISR occurring on
    *          LinFlex_2.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 2 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_6)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_6);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_6);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_6) */
    
    #if defined(LinHWCh_7)
    /**
    * @brief   Interrupt handle on LinFlex_7.
    * @details This function implements the ISR occurring on
    *          LinFlex_7.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 7 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_7)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_7);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_7);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_7) */
    
    #if defined(LinHWCh_8)
    /**
    * @brief   Interrupt handle on LinFlex_8.
    * @details This function implements the ISR occurring on
    *          LinFlex_8.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 8 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_8)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_8);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_8);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_8) */
    
    #if defined(LinHWCh_9)
    /**
    * @brief   Interrupt handle on LinFlex_9.
    * @details This function implements the ISR occurring on
    *          LinFlex_9.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 9 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_9)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_9);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_9);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_9) */
    
    #if defined(LinHWCh_10)
    /**
    * @brief   Interrupt handle on LinFlex_10.
    * @details This function implements the ISR occurring on
    *          LinFlex_10.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 10 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_10)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_10);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_10);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_10) */
    
    #if defined(LinHWCh_11)
    /**
    * @brief   Interrupt handle on LinFlex_11.
    * @details This function implements the ISR occurring on
    *          LinFlex_11.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 11 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_11)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_11);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_11);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_11) */
    
    #if defined(LinHWCh_12)
    /**
    * @brief   Interrupt handle on LinFlex_12.
    * @details This function implements the ISR occurring on
    *          LinFlex_12.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 12 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_12)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_12);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_12);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_12) */
    
    #if defined(LinHWCh_13)
    /**
    * @brief   Interrupt handle on LinFlex_13.
    * @details This function implements the ISR occurring on
    *          LinFlex_13.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 13 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_13)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_13);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_13);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_13) */
    
    #if defined(LinHWCh_14)
    /**
    * @brief   Interrupt handle on LinFlex_14.
    * @details This function implements the ISR occurring on
    *          LinFlex_14.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 14 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_14)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_14);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_14);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_14) */
    
    #if defined(LinHWCh_15)
    /**
    * @brief   Interrupt handle on LinFlex_15.
    * @details This function implements the ISR occurring on
    *          LinFlex_15.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 15 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_15)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_15);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_15);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_15) */
    
    #if defined(LinHWCh_16)
    /**
    * @brief   Interrupt handle on LinFlex_16.
    * @details This function implements the ISR occurring on
    *          LinFlex_16.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 16 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_16)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_16);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_16);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_16) */
    
    #if defined(LinHWCh_17)
    /**
    * @brief   Interrupt handle on LinFlex_17.
    * @details This function implements the ISR occurring on
    *          LinFlex_17.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 17 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_Isr_LINFlex_17)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_17);
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_17);    
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_17) */
    
#else

    #if defined(LinHWCh_0)
    /**
    * @brief   Error interrupt on LinFlex_0.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_0.
    * @note    This interrupt handlers is only present if Hardware 
    *          Channel 0 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_0)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_0);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_0.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_0.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 0 is used and DMA is not used.
    *
    * @isr
    *
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_0)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_0);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_0.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_0.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 0 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_0)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_0);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_0) */
    
    #if defined(LinHWCh_1)
    /**
    * @brief   Error interrupt on LinFlex_1.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_1.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 1 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_1)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_1);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_1.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_1.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 1 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_1)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_1);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_1.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_1.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 1 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_1)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_1);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_1) */
    
    #if defined(LinHWCh_2)
    /**
    * @brief   Error interrupt on LinFlex_2.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_2.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 2 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_2)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_2);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_2.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_2.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 2 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_2)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_2);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_2.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_2.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 2 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_2)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_2);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_2) */
    
    #if defined(LinHWCh_3)
    /**
    * @brief   Error interrupt on LinFlex_3.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_3.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_3)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_3);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_3.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_3.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_3)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_3);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_3.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_3.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_3)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_3);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_3) */
    
    #if defined(LinHWCh_4)
    /**
    * @brief   Error interrupt on LinFlex_4.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_4.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 4 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_4)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_4);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_4.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_4.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 4 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_4)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_4);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_4.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_4.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 4 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_4)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_4);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_4) */
    
    #if defined(LinHWCh_5)
    /**
    * @brief   Error interrupt on LinFlex_5.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_5.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 5 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_5)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_5);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_5.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_5.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 5 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_5)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_5);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_5.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_5.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 5 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_5)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_5);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_5) */
    
    #if defined(LinHWCh_6)
    /**
    * @brief   Error interrupt on LinFlex_6.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_6.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 6 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_6)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_6);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_6.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_6.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 6 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_6)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_6);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_6.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_6.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 6 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_6)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_6);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_6) */
    
    #if defined(LinHWCh_7)
    /**
    * @brief   Error interrupt on LinFlex_7.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_7.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 7 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_7)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_7);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_7.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_7.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 7 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_7)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_7);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_7.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_7.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 7 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_7)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_7);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_7) */
    
    #if defined(LinHWCh_8)
    /**
    * @brief   Error interrupt on LinFlex_8.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_8.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 8 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_8)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_8);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_8.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_8.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 8 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_8)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_8);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_8.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_8.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 8 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_8)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_8);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_8) */
    
    #if defined(LinHWCh_9)
    /**
    * @brief   Error interrupt on LinFlex_9.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_9.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 9 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_9)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_9);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_9.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_9.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 9 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_9)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_9);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_9.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_9.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 9 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_9)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_9);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_9) */
    
    #if defined(LinHWCh_10)
    /**
    * @brief   Error interrupt on LinFlex_10.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_10.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 10 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_10)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_10);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_10.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_10.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 10 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_10)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_10);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_10.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_10.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 10 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_10)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_10);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_10) */
    
    #if defined(LinHWCh_11)
    /**
    * @brief   Error interrupt on LinFlex_11.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_11.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 11 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_11)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_11);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_11.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_11.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 11 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_11)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_11);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_11.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_11.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 11 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_11)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_11);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_11) */
    
    #if defined(LinHWCh_12)
    /**
    * @brief   Error interrupt on LinFlex_12.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_12.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 12 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_12)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_12);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_12.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_12.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 12 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_12)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_12);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_12.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_12.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 12 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_12)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_12);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_12) */
    
    #if defined(LinHWCh_13)
    /**
    * @brief   Error interrupt on LinFlex_13.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_13.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 13 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_13)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_13);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_13.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_13.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 13 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_13)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_13);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_13.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_13.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 13 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_13)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_13);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_13) */
    
    #if defined(LinHWCh_14)
    /**
    * @brief   Error interrupt on LinFlex_14.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_14.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_14)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_14);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_14.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_14.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_14)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_14);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_14.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_14.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 3 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_14)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_14);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_14) */
    
    #if defined(LinHWCh_15)
    /**
    * @brief   Error interrupt on LinFlex_15.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_15.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 4 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_15)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_15);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_15.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_15.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 4 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_15)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_15);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_15.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_15.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 4 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_15)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_15);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_15) */
    
    #if defined(LinHWCh_16)
    /**
    * @brief   Error interrupt on LinFlex_16.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_16.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 5 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_16)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_16);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_16.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_16.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 5 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_16)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_16);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_16.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_16.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 5 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_16)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_16);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_16) */
    
    #if defined(LinHWCh_17)
    /**
    * @brief   Error interrupt on LinFlex_17.
    * @details This function implements the ISR occurring on error on
    *          LinFlex_17.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 17 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrError_LINFlex_17)
    {
        Lin_Linflex_ErrorInterruptHandler(LinHWCh_17);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Rx interrupt on LinFlex_17.
    * @details This function implements the ISR occurring on reception on
    *          LinFlex_17.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 17 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrRx_LINFlex_17)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_17);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    
    /**
    * @brief   Tx interrupt on LinFlex_17.
    * @details This function implements the ISR occurring on transmission
    *          on LinFlex_17.
    * @note    This interrupt handlers is only present if Hardware
    *          Channel 17 is used and DMA is not used.
    *
    * @isr
    *
    */
    /**
    * @violates @ref Lin_LINFlex_Irq_c_REF_6 All declarations and definitions of objects or
    * functions at file scope shall have internal linkage unless external linkage is required.
    */
    ISR(Lin_Linflex_IsrTx_LINFlex_17)
    {
        Lin_Linflex_TxRxInterruptHandler(LinHWCh_17);
        /**
        * @violates @ref Lin_LINFlex_Irq_c_REF_4 cast from unsigned int to pointer
        */
        EXIT_INTERRUPT();
    }
    #endif /* defined(LinHWCh_17) */

#endif /* LIN_UNIFIED_INTERRUPTS == STD_ON */

#define LIN_STOP_SEC_CODE
/** 
* @violates @ref Lin_LINFlex_Irq_c_REF_1 #include statements in a file should only be preceded
*        by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_Irq_c_REF_2 Precautions shall be taken in order to prevent the contents
*        of a header file being included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif

/*! @} */
