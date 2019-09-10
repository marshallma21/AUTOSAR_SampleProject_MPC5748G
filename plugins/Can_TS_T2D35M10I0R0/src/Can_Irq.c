/**
*   @file    Can_Irq.c
*   @implements Can_Irq.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Can - module interface
*   @details Interrupt routines for Can driver.
*
*   @addtogroup CAN_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : FLEXCAN
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
* @section Can_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, #include preceded by non preproc directives.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Can_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h
* There are different kinds of execution code sections.
*
* @section Can_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, Identifier clash
* This violation is due to the requirement that request to have a file version check.
*
* @section Can_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used
* This violation is due to the structure of the types used.
*
* @section Can_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* This macro compute the address of any register by using the hardware ofsset of the controller. The address calculated as an unsigned int
* is passed to  a macro for initializing the pointer with that address. (ex: see REG_WRITE32 macro).
*
* @section Can_Irq_c_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and an integral type.
*
* @section Can_Irq_c_REF_9
* Violates MISRA 2004 Advisory Rule 12.1, Use of mixed mode arithmetic
* This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed
* to the macro. The care is taken for the parameters sent as inputs to the macro and hence unintended truncation of values
* would not result.
*
* @section Can_Irq_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*/

/*
(CAN035) The module Can_Irq.c contains the implementation of interrupt frames.The implementation of the interrupt service routine shall be in Can.c
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Can_Irq.c
*/
#include "Can.h"
#include "Can_IPW.h"
#include "CanIf_Cbk.h"
#include "Mcal.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/* The integration of incompatible files shall be avoided. */
/* @violates @ref Can_Irq_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_VENDOR_ID_IRQ_C                      43
#define CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
#define CAN_AR_RELEASE_MINOR_VERSION_IRQ_C       2
/* @violates @ref Can_Irq_c_REF_3 Violates MISRA 2004 Rule 1.4, Identifier clash */
#define CAN_AR_RELEASE_REVISION_VERSION_IRQ_C    2
#define CAN_SW_MAJOR_VERSION_IRQ_C               1
#define CAN_SW_MINOR_VERSION_IRQ_C               0
#define CAN_SW_PATCH_VERSION_IRQ_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CAN header file are of the same vendor */
#if (CAN_VENDOR_ID_IRQ_C != CAN_VENDOR_ID)
    #error "Can_Irq.c and Can.h have different vendor ids"
#endif
/* Check if current file and CAN header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C    != CAN_AR_RELEASE_MAJOR_VERSION) || \
     (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C    != CAN_AR_RELEASE_MINOR_VERSION) || \
     (CAN_AR_RELEASE_REVISION_VERSION_IRQ_C != CAN_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Can_Irq.c and Can.h are different"
#endif
/* Check if current file and CAN header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_IRQ_C != CAN_SW_MAJOR_VERSION) || \
     (CAN_SW_MINOR_VERSION_IRQ_C != CAN_SW_MINOR_VERSION) || \
     (CAN_SW_PATCH_VERSION_IRQ_C != CAN_SW_PATCH_VERSION))
    #error "Software Version Numbers of Can_Irq.c and Can.h are different"
#endif


/* Check if current file and CAN_IPW header file are of the same vendor */
#if (CAN_VENDOR_ID_IRQ_C != CAN_IPW_VENDOR_ID_H)
    #error "Can_Irq.c and Can_IPW.h have different vendor ids"
#endif
/* Check if current file and CAN_IPW header file are of the same Autosar version */
#if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C    != CAN_IPW_AR_RELEASE_MAJOR_VERSION_H) || \
     (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C    != CAN_IPW_AR_RELEASE_MINOR_VERSION_H) || \
     (CAN_AR_RELEASE_REVISION_VERSION_IRQ_C != CAN_IPW_AR_RELEASE_REVISION_VERSION_H))
    #error "AutoSar Version Numbers of Can_Irq.c and Can_IPW.h are different"
#endif
/* Check if current file and CAN_IPW header file are of the same Software version */
#if ((CAN_SW_MAJOR_VERSION_IRQ_C != CAN_IPW_SW_MAJOR_VERSION_H) || \
     (CAN_SW_MINOR_VERSION_IRQ_C != CAN_IPW_SW_MINOR_VERSION_H) || \
     (CAN_SW_PATCH_VERSION_IRQ_C != CAN_IPW_SW_PATCH_VERSION_H))
    #error "Software Version Numbers of Can_Irq.c and Can_IPW.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if (CAN_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C != DET_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_Irq.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and CANIF_CBK header file are of the same version */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  #ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((CAN_AR_RELEASE_MAJOR_VERSION_IRQ_C != CANIF_CBK_AR_RELEASE_MAJOR_VERSION) || \
         (CAN_AR_RELEASE_MINOR_VERSION_IRQ_C != CANIF_CBK_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Can_Irq.c and CanIf_Cbk.h are different"
    #endif
  #endif
#endif

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


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/*
   (CAN033) The Can module shall implement the interrupt service routines for all CAN Hardware Unit
   interrupts that are needed. The Can module shall disable all unused interrupts in the CAN controller.
   The Can module shall reset the interrupt flag at the end of the ISR (if not done automatically by
   hardware). The Can module shall not set the configuration (i.e. priority) of the vector table entry.
*/
/**
* @brief          CAN controller A interrupts
* @details        CAN controller A interrupts
*
*
*/
/* CAN controller A interrupts */
#ifdef CAN_FCA_INDEX
    #if (CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON)
        ISR(Can_IsrFCA_ERR);
    #endif
    #if (CAN_A_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCA_BO);
    #endif /* (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_PUBLIC_ICOM_SUPPORT==STD_ON)
        ISR(Can_IsrFCA_PN);
    #endif/* (CAN_PUBLIC_ICOM_SUPPORT==STD_OFF) */
    
    #if ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCA_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCA_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCA_FrameAv);
                    ISR(Can_IsrFCA_Overf);
                    ISR(Can_IsrFCA_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCA_MB_00_03);
                    ISR(Can_IsrFCA_MB_04_07);
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCA_MB_08_11);
                    ISR(Can_IsrFCA_MB_12_15);
                    ISR(Can_IsrFCA_MB_16_31);
                    ISR(Can_IsrFCA_MB_32_63);
                    ISR(Can_IsrFCA_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCA_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCA_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCA_FrameAv);
                    ISR(Can_IsrFCA_Overf);
                    ISR(Can_IsrFCA_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCA_MB_00_03);
                    ISR(Can_IsrFCA_MB_04_07);
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCA_MB_08_11);
                    ISR(Can_IsrFCA_MB_12_15);
                    ISR(Can_IsrFCA_MB_16_31);
                    ISR(Can_IsrFCA_MB_32_63);
                    ISR(Can_IsrFCA_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCA_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_A_FIFO_EN == STD_OFF)
                   ISR(Can_IsrFCA_MB_00_03);
                   ISR(Can_IsrFCA_MB_04_07);
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                   ISR(Can_IsrFCA_MB_08_11);
                   ISR(Can_IsrFCA_MB_12_15);
                   ISR(Can_IsrFCA_MB_16_31);
                   ISR(Can_IsrFCA_MB_32_63);
                   ISR(Can_IsrFCA_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCA_INDEX */

/**
* @brief          CAN controller B interrupts
* @details        CAN controller B interrupts
*
*
*/
/* CAN controller B interrupts */
#ifdef CAN_FCB_INDEX
  #if (CAN_B_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCB_ERR);
  #endif
    #if (CAN_B_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCB_BO);
    #endif /* (CAN_B_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCB_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCB_FrameAv);
                    ISR(Can_IsrFCB_Overf);
                    ISR(Can_IsrFCB_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_00_03);
                    ISR(Can_IsrFCB_MB_04_07);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_08_11);
                    ISR(Can_IsrFCB_MB_12_15);
                    ISR(Can_IsrFCB_MB_16_31);
                    ISR(Can_IsrFCB_MB_32_63);
                    ISR(Can_IsrFCB_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_OFF) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCB_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCB_FrameAv);
                    ISR(Can_IsrFCB_Overf);
                    ISR(Can_IsrFCB_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_00_03);
                    ISR(Can_IsrFCB_MB_04_07);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_08_11);
                    ISR(Can_IsrFCB_MB_12_15);
                    ISR(Can_IsrFCB_MB_16_31);
                    ISR(Can_IsrFCB_MB_32_63);
                    ISR(Can_IsrFCB_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCB_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_OFF)
                    ISR(Can_IsrFCB_MB_00_03);
                    ISR(Can_IsrFCB_MB_04_07);
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCB_MB_08_11);
                    ISR(Can_IsrFCB_MB_12_15);
                    ISR(Can_IsrFCB_MB_16_31);
                    ISR(Can_IsrFCB_MB_32_63);
                    ISR(Can_IsrFCB_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCB_INDEX */

/**
* @brief          CAN controller C interrupts
* @details        CAN controller C interrupts
**/
/* CAN controller C interrupts */
#ifdef CAN_FCC_INDEX
  #if (CAN_C_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCC_ERR);
  #endif
    #if (CAN_C_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCC_BO);
    #endif /* (CAN_C_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCC_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCC_FrameAv);
                    ISR(Can_IsrFCC_Overf);
                    ISR(Can_IsrFCC_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_00_03);
                    ISR(Can_IsrFCC_MB_04_07);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_08_11);
                    ISR(Can_IsrFCC_MB_12_15);
                    ISR(Can_IsrFCC_MB_16_31);
                    ISR(Can_IsrFCC_MB_32_63);
                    ISR(Can_IsrFCC_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_OFF) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCC_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCC_FrameAv);
                    ISR(Can_IsrFCC_Overf);
                    ISR(Can_IsrFCC_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_00_03);
                    ISR(Can_IsrFCC_MB_04_07);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_08_11);
                    ISR(Can_IsrFCC_MB_12_15);
                    ISR(Can_IsrFCC_MB_16_31);
                    ISR(Can_IsrFCC_MB_32_63);
                    ISR(Can_IsrFCC_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCC_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_OFF)
                    ISR(Can_IsrFCC_MB_00_03);
                    ISR(Can_IsrFCC_MB_04_07);
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCC_MB_08_11);
                    ISR(Can_IsrFCC_MB_12_15);
                    ISR(Can_IsrFCC_MB_16_31);
                    ISR(Can_IsrFCC_MB_32_63);
                    ISR(Can_IsrFCC_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCC_INDEX */

/**
* @brief          CAN controller D interrupts
* @details        CAN controller D interrupts
*
*
*/
/* CAN controller D interrupts */
#ifdef CAN_FCD_INDEX
  #if (CAN_D_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCD_ERR);
  #endif
    #if (CAN_D_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCD_BO);
    #endif /* (CAN_D_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCD_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_D_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCD_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCD_FrameAv);
                    ISR(Can_IsrFCD_Overf);
                    ISR(Can_IsrFCD_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCD_MB_00_03);
                    ISR(Can_IsrFCD_MB_04_07);
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCD_MB_08_11);
                    ISR(Can_IsrFCD_MB_12_15);
                    ISR(Can_IsrFCD_MB_16_31);
                    ISR(Can_IsrFCD_MB_32_63);
                    ISR(Can_IsrFCD_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_D_TXINT_SUPPORTED == STD_OFF) && (CAN_D_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCD_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_D_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCD_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCD_FrameAv);
                    ISR(Can_IsrFCD_Overf);
                    ISR(Can_IsrFCD_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCD_MB_00_03);
                    ISR(Can_IsrFCD_MB_04_07);
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCD_MB_08_11);
                    ISR(Can_IsrFCD_MB_12_15);
                    ISR(Can_IsrFCD_MB_16_31);
                    ISR(Can_IsrFCD_MB_32_63);
                    ISR(Can_IsrFCD_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCD_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_D_FIFO_EN == STD_OFF)
                   ISR(Can_IsrFCD_MB_00_03);
                   ISR(Can_IsrFCD_MB_04_07);
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                   ISR(Can_IsrFCD_MB_08_11);
                   ISR(Can_IsrFCD_MB_12_15);
                   ISR(Can_IsrFCD_MB_16_31);
                   ISR(Can_IsrFCD_MB_32_63);
                   ISR(Can_IsrFCD_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCD_INDEX */

/**
* @brief          CAN controller E interrupts
* @details        CAN controller E interrupts
*
*
*/
/* CAN controller E interrupts */
#ifdef CAN_FCE_INDEX
  #if (CAN_E_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCE_ERR);
  #endif
    #if (CAN_E_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCE_BO);
    #endif /* (CAN_E_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCE_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_E_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCE_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCE_FrameAv);
                    ISR(Can_IsrFCE_Overf);
                    ISR(Can_IsrFCE_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCE_MB_00_03);
                    ISR(Can_IsrFCE_MB_04_07);
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCE_MB_08_11);
                    ISR(Can_IsrFCE_MB_12_15);
                    ISR(Can_IsrFCE_MB_16_31);
                    ISR(Can_IsrFCE_MB_32_63);  
                    ISR(Can_IsrFCE_MB_64_95);    
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_E_TXINT_SUPPORTED == STD_OFF) && (CAN_E_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCE_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_E_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCE_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCE_FrameAv);
                    ISR(Can_IsrFCE_Overf);
                    ISR(Can_IsrFCE_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_E_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCE_MB_00_03);
                    ISR(Can_IsrFCE_MB_04_07);
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCE_MB_08_11);
                    ISR(Can_IsrFCE_MB_12_15);
                    ISR(Can_IsrFCE_MB_16_31);
                    ISR(Can_IsrFCE_MB_32_63);
                    ISR(Can_IsrFCE_MB_64_95);    
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCE_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_E_FIFO_EN == STD_OFF)
                   ISR(Can_IsrFCE_MB_00_03);
                   ISR(Can_IsrFCE_MB_04_07);
            #endif /* (CAN_E_FIFO_EN == STD_OFF) */
                   ISR(Can_IsrFCE_MB_08_11);
                   ISR(Can_IsrFCE_MB_12_15);
                   ISR(Can_IsrFCE_MB_16_31);
                   ISR(Can_IsrFCE_MB_32_63);
                   ISR(Can_IsrFCE_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCE_INDEX */


/**
* @brief          CAN controller F interrupts
* @details        CAN controller F interrupts
*
*
*/
/* CAN controller F interrupts */
#ifdef CAN_FCF_INDEX
  #if (CAN_F_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCF_ERR);
  #endif
    #if (CAN_F_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCF_BO);
    #endif /* (CAN_F_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCF_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_F_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCF_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCF_FrameAv);
                    ISR(Can_IsrFCF_Overf);
                    ISR(Can_IsrFCF_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_F_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCF_MB_00_03);
                    ISR(Can_IsrFCF_MB_04_07);
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCF_MB_08_11);
                    ISR(Can_IsrFCF_MB_12_15);
                    ISR(Can_IsrFCF_MB_16_31);
                    ISR(Can_IsrFCF_MB_32_63);
                    ISR(Can_IsrFCF_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_F_TXINT_SUPPORTED == STD_OFF) && (CAN_F_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCF_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_F_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCF_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCF_FrameAv);
                    ISR(Can_IsrFCF_Overf);
                    ISR(Can_IsrFCF_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_F_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCF_MB_00_03);
                    ISR(Can_IsrFCF_MB_04_07);
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCF_MB_08_11);
                    ISR(Can_IsrFCF_MB_12_15);
                    ISR(Can_IsrFCF_MB_16_31);
                    ISR(Can_IsrFCF_MB_32_63);
                    ISR(Can_IsrFCF_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCF_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_F_FIFO_EN == STD_OFF)
                   ISR(Can_IsrFCF_MB_00_03);
                   ISR(Can_IsrFCF_MB_04_07);
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */
                   ISR(Can_IsrFCF_MB_08_11);
                   ISR(Can_IsrFCF_MB_12_15);
                   ISR(Can_IsrFCF_MB_16_31);
                   ISR(Can_IsrFCF_MB_32_63);
                   ISR(Can_IsrFCF_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCF_INDEX */


/**
* @brief          CAN controller G interrupts
* @details        CAN controller G interrupts
*
*
*/
/* CAN controller G interrupts */
#ifdef CAN_FCG_INDEX
  #if (CAN_G_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCG_ERR);
  #endif
    #if (CAN_G_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCG_BO);
    #endif /* (CAN_G_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_G_TXINT_SUPPORTED == STD_ON) && (CAN_G_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCG_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_G_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCG_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCG_FrameAv);
                    ISR(Can_IsrFCG_Overf);
                    ISR(Can_IsrFCG_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_G_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCG_MB_00_03);
                    ISR(Can_IsrFCG_MB_04_07);
            #endif /* (CAN_G_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCG_MB_08_11);
                    ISR(Can_IsrFCG_MB_12_15);
                    ISR(Can_IsrFCG_MB_16_31);
                    ISR(Can_IsrFCG_MB_32_63);
                    ISR(Can_IsrFCG_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_G_TXINT_SUPPORTED == STD_OFF) && (CAN_G_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCG_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_G_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCG_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCG_FrameAv);
                    ISR(Can_IsrFCG_Overf);
                    ISR(Can_IsrFCG_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_G_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCG_MB_00_03);
                    ISR(Can_IsrFCG_MB_04_07);
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCG_MB_08_11);
                    ISR(Can_IsrFCG_MB_12_15);
                    ISR(Can_IsrFCG_MB_16_31);
                    ISR(Can_IsrFCG_MB_32_63);
                    ISR(Can_IsrFCG_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_G_TXINT_SUPPORTED == STD_ON) && (CAN_G_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCG_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_G_FIFO_EN == STD_OFF)
                   ISR(Can_IsrFCG_MB_00_03);
                   ISR(Can_IsrFCG_MB_04_07);
            #endif /* (CAN_G_FIFO_EN == STD_OFF) */
                   ISR(Can_IsrFCG_MB_08_11);
                   ISR(Can_IsrFCG_MB_12_15);
                   ISR(Can_IsrFCG_MB_16_31);
                   ISR(Can_IsrFCG_MB_32_63);
                   ISR(Can_IsrFCG_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_G_TXINT_SUPPORTED == STD_ON) && (CAN_G_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCG_INDEX */

/**
* @brief          CAN controller H interrupts
* @details        CAN controller H interrupts
*
*
*/
/* CAN controller G interrupts */
#ifdef CAN_FCH_INDEX
  #if (CAN_H_ERROR_NOTIFICATION_ENABLE == STD_ON)
    ISR(Can_IsrFCH_ERR);
  #endif
    #if (CAN_H_BUSOFFINT_SUPPORTED == STD_ON)
        ISR(Can_IsrFCH_BO);
    #endif /* (CAN_H_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_H_TXINT_SUPPORTED == STD_ON) && (CAN_H_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCH_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_H_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCH_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCH_FrameAv);
                    ISR(Can_IsrFCH_Overf);
                    ISR(Can_IsrFCH_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_H_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCH_MB_00_03);
                    ISR(Can_IsrFCH_MB_04_07);
            #endif /* (CAN_H_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCH_MB_08_11);
                    ISR(Can_IsrFCH_MB_12_15);
                    ISR(Can_IsrFCH_MB_16_31);
                    ISR(Can_IsrFCH_MB_32_63);
                    ISR(Can_IsrFCH_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_H_TXINT_SUPPORTED == STD_OFF) && (CAN_H_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCH_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_H_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    ISR(Can_IsrFCH_RxFifoEvents);
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    ISR(Can_IsrFCH_FrameAv);
                    ISR(Can_IsrFCH_Overf);
                    ISR(Can_IsrFCH_Warn);
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_H_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCH_MB_00_03);
                    ISR(Can_IsrFCH_MB_04_07);
            #endif /* (CAN_H_FIFO_EN == STD_OFF) */
                    ISR(Can_IsrFCH_MB_08_11);
                    ISR(Can_IsrFCH_MB_12_15);
                    ISR(Can_IsrFCH_MB_16_31);
                    ISR(Can_IsrFCH_MB_32_63);
                    ISR(Can_IsrFCH_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */

    #elif ((CAN_H_TXINT_SUPPORTED == STD_ON) && (CAN_H_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            ISR(Can_IsrFCH_UNI);
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_H_FIFO_EN == STD_OFF)
                   ISR(Can_IsrFCH_MB_00_03);
                   ISR(Can_IsrFCH_MB_04_07);
            #endif /* (CAN_H_FIFO_EN == STD_OFF) */
                   ISR(Can_IsrFCH_MB_08_11);
                   ISR(Can_IsrFCH_MB_12_15);
                   ISR(Can_IsrFCH_MB_16_31);
                   ISR(Can_IsrFCH_MB_32_63);
                   ISR(Can_IsrFCH_MB_64_95);
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */
    #endif /* ((CAN_H_TXINT_SUPPORTED == STD_ON) && (CAN_H_RXINT_SUPPORTED == STD_OFF)) */
#endif /* CAN_FCH_INDEX */





#define CAN_START_SEC_CODE
/* @violates @ref Can_Irq_c_REF_1 MISRA 2004 Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Irq_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN A
==================================================================================================*/
#ifdef CAN_FCA_INDEX
  #if (CAN_A_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    CAN_ERRISR(A)
  #endif
    #if (CAN_A_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        CAN_BOISR(A)
    #endif /* (CAN_A_BUSOFFINT_SUPPORTED == STD_ON) */

    #if (CAN_PUBLIC_ICOM_SUPPORT==STD_ON)
        /* External Wake-up by PNET */
        CAN_WKPPNISR(A)
    #endif/* (CAN_PUBLIC_ICOM_SUPPORT==STD_OFF) */
    #if ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(A)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(A)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(A)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(A)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                /* Message Buffer 00_03 */
                /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_00_03, 0U, 3U)
                /* Message Buffer 04_07 */
                /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_04_07, 4U, 7U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                /* Message Buffer 08_11 */
                /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_08_11, 8U,11U)
                /* Message Buffer 12_15 */
                /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_12_15,12U,15U)
                /* Message Buffer 16_31 */
                /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_16_31,16U,31U)
                /* Message Buffer 32_39 */
                /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_32_63,32U,63U)
                /* Message Buffer 64_95 */
                /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_OFF) && (CAN_A_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIRXISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_A_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        CAN_RXFIFO_EVENTS(A)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        CAN_MB_FRAV(A)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        CAN_MB_RXOVER(A)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        CAN_MB_RXWARN(A)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_A_FIFO_EN == STD_OFF) */
                    /* Message Buffer 00_03 */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(A, MB_00_03, 0U, 3U)
                    /* Message Buffer 04_07 */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(A, MB_04_07, 4U, 7U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */
                    /* Message Buffer 08_11 */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(A, MB_08_11, 8U,11U)
                    /* Message Buffer 12_15 */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(A, MB_12_15,12U,15U)
                    /* Message Buffer 16_31 */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(A, MB_16_31,16U,31U)
                    /* Message Buffer 32_39 */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(A, MB_32_63,32U,63U)
                    /* Message Buffer 64_95 */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNITXISRS(A)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_A_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(A, MB_00_03, 0U, 3U)
                   
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(A, MB_04_07, 4U, 7U)
            #endif /* (CAN_A_FIFO_EN == STD_OFF) */
            
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(A, MB_08_11, 8U,11U)
                   
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(A, MB_12_15,12U,15U)
                   
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(A, MB_16_31,16U,31U)
                   
                   /* Message Buffer 32_39 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(A, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(A, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_A_TXINT_SUPPORTED == STD_ON) && (CAN_A_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCA_INDEX */


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN B
==================================================================================================*/
#ifdef CAN_FCB_INDEX
  #if (CAN_B_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Required Rule 11.3, A cast should not be performed */
        CAN_ERRISR(B)
  #endif
    #if (CAN_B_BUSOFFINT_SUPPORTED == STD_ON)
    /* Bus Off */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        CAN_BOISR(B)
    #endif /* (CAN_B_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Required Rule 11.3, A cast should not be performed */
                        CAN_RXFIFO_EVENTS(B)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        CAN_MB_FRAV(B)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        CAN_MB_RXOVER(B)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        CAN_MB_RXWARN(B)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_04_07, 4U, 7U)
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_16_31,16U,31U)
                   /* Message Buffer 32_39 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_OFF) && (CAN_B_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIRXISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_B_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(B)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(B)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(B)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(B)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(B, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(B, MB_04_07, 4U, 7U)                
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(B, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(B, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(B, MB_16_31,16U,31U)
                   /* Message Buffer 32_39 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(B, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNITXISRS(B)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_B_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(B, MB_00_03, 0U, 3U)
                   
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(B, MB_04_07, 4U, 7U)
            #endif /* (CAN_B_FIFO_EN == STD_OFF) */
            
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(B, MB_08_11, 8U,11U)
                   
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(B, MB_12_15,12U,15U)
                   
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(B, MB_16_31,16U,31U)
                   
                   /* Message Buffer 32_39 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(B, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(B, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_B_TXINT_SUPPORTED == STD_ON) && (CAN_B_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCB_INDEX */


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN C
==================================================================================================*/
#ifdef CAN_FCC_INDEX
  #if (CAN_C_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        CAN_ERRISR(C)
  #endif
    #if (CAN_C_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
            CAN_BOISR(C)
    #endif /* (CAN_C_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(C)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(C)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(C)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(C)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_04_07, 4U, 7U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_16_31,16U,31U)
                   /* Message Buffer 32_39 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_OFF) && (CAN_C_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIRXISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_C_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(C)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(C)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(C)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(C)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_C_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(C, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(C, MB_04_07, 4U, 7U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(C, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(C, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(C, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(C, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
                /* All MBs */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                CAN_MB_UNITXISRS(C)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_C_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(C, MB_00_03, 0U, 3U)
                   
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(C, MB_04_07, 4U, 7U)
            #endif /* (CAN_C_FIFO_EN == STD_OFF) */
            
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(C, MB_08_11, 8U,11U)
                   
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(C, MB_12_15,12U,15U)
                   
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(C, MB_16_31,16U,31U)
                   
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(C, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(C, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_C_TXINT_SUPPORTED == STD_ON) && (CAN_C_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCC_INDEX */

/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN D
==================================================================================================*/
#ifdef CAN_FCD_INDEX
  #if (CAN_D_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        CAN_ERRISR(D)
  #endif
    #if (CAN_D_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
            CAN_BOISR(D)
    #endif /* (CAN_D_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIISRS(D)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_D_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(D)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(D)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(D)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(D)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_16_31,16U,31U)
                   /* Message Buffer 32_39 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_D_TXINT_SUPPORTED == STD_OFF) && (CAN_D_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIRXISRS(D)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_D_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(D)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(D)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(D)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(D)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(D, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(D, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(D, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(D, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(D, MB_16_31,16U,31U)
                   /* Message Buffer 32_39 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(D, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_64_95,64U,95U)
    #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNITXISRS(D)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_D_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(D, MB_00_03, 0U, 3U)
                   
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(D, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
            
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(D, MB_08_11, 8U,11U)
                   
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(D, MB_12_15,12U,15U)
                   
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(D, MB_16_31,16U,31U)
                   
                   /* Message Buffer 32_39 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(D, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(D, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_D_TXINT_SUPPORTED == STD_ON) && (CAN_D_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCD_INDEX */


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN E
==================================================================================================*/
#ifdef CAN_FCE_INDEX
  #if (CAN_E_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        CAN_ERRISR(E)
  #endif
    #if (CAN_E_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
            CAN_BOISR(E)
    #endif /* (CAN_E_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIISRS(E)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_E_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(E)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(E)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(E)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(E)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(E, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(E, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(E, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(E, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(E, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(E, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(E, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_E_TXINT_SUPPORTED == STD_OFF) && (CAN_E_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
                /* All MBs */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                CAN_MB_UNIRXISRS(E)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_E_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(E)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                        /* Rx Fifo Frame Available Interrupt */
                        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                            CAN_MB_FRAV(E)
                        /* RX Fifo Overflow Interrupt*/
                        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                            CAN_MB_RXOVER(E)
                        /* Rx Fifo Warning Interrupt */
                        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                            CAN_MB_RXWARN(E)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_E_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                            CAN_MB_RXISRS(E, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                            CAN_MB_RXISRS(E, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                            CAN_MB_RXISRS(E, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                            CAN_MB_RXISRS(E, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                            CAN_MB_RXISRS(E, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                            CAN_MB_RXISRS(E, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                            CAN_MB_ISRS(E, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNITXISRS(E)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_E_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(E, MB_00_03, 0U, 3U)
                   
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(E, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
            
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(E, MB_08_11, 8U,11U)
                   
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(E, MB_12_15,12U,15U)
                   
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(E, MB_16_31,16U,31U)
                   
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(E, MB_32_63,32U,63U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_E_TXINT_SUPPORTED == STD_ON) && (CAN_E_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCE_INDEX */


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN F
==================================================================================================*/
#ifdef CAN_FCF_INDEX
  #if (CAN_F_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        CAN_ERRISR(F)
  #endif
    #if (CAN_F_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
            CAN_BOISR(F)
    #endif /* (CAN_F_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
                /* All MBs */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                CAN_MB_UNIISRS(F)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_F_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(F)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(F)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(F)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(F)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_F_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_F_TXINT_SUPPORTED == STD_OFF) && (CAN_F_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
                /* All MBs */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                CAN_MB_UNIRXISRS(F)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_F_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(F)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(F)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(F)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(F)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_F_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(F, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(F, MB_04_07, 4U, 7U)
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(F, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(F, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(F, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(F, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
                /* All MBs */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                CAN_MB_UNITXISRS(F)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_F_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(F, MB_00_03, 0U, 3U)
                   
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(F, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
            
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(F, MB_08_11, 8U,11U)
                   
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(F, MB_12_15,12U,15U)
                   
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(F, MB_16_31,16U,31U)
                   
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(F, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(F, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCF_INDEX */



/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN G
==================================================================================================*/
#ifdef CAN_FCG_INDEX
  #if (CAN_G_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        CAN_ERRISR(G)
  #endif
    #if (CAN_G_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
            CAN_BOISR(G)
    #endif /* (CAN_G_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_G_TXINT_SUPPORTED == STD_ON) && (CAN_G_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
                /* All MBs */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                CAN_MB_UNIISRS(G)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_G_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(G)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(G)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(G)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(G)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_G_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_G_TXINT_SUPPORTED == STD_OFF) && (CAN_G_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
                /* All MBs */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                CAN_MB_UNIRXISRS(G)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_G_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(G)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(G)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(G)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(G)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_G_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(G, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(G, MB_04_07, 4U, 7U)
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(G, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(G, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(G, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(G, MB_32_63,32U,63U)
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_G_TXINT_SUPPORTED == STD_ON) && (CAN_G_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNITXISRS(G)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_G_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(G, MB_00_03, 0U, 3U)
                   
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(G, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
            
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(G, MB_08_11, 8U,11U)
                   
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(G, MB_12_15,12U,15U)
                   
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(G, MB_16_31,16U,31U)
                   
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(G, MB_32_63,32U,63U)
                   
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(G, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCF_INDEX */


/*==================================================================================================
    INTERRUPT SERVICE ROUTINES FOR FLEXCAN H
==================================================================================================*/
#ifdef CAN_FCH_INDEX
  #if (CAN_H_ERROR_NOTIFICATION_ENABLE == STD_ON)
    /* Error */
    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
        CAN_ERRISR(H)
  #endif
    #if (CAN_H_BUSOFFINT_SUPPORTED == STD_ON)
        /* Bus Off */
        /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
        /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
        /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
        /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
            CAN_BOISR(H)
    #endif /* (CAN_G_BUSOFFINT_SUPPORTED == STD_ON) */

    #if ((CAN_H_TXINT_SUPPORTED == STD_ON) && (CAN_H_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
                /* All MBs */
                /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                CAN_MB_UNIISRS(H)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_H_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(H)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(H)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(H)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(H)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_H_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_32_63,32U,63U)

                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_H_TXINT_SUPPORTED == STD_OFF) && (CAN_H_RXINT_SUPPORTED == STD_ON))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNIRXISRS(H)
        #else /* (CAN_ISROPTCODESIZE == STD_ON) */
            #if (CAN_H_FIFO_EN == STD_ON)
                #if (CAN_RXFIFO_EVENT_UNIFIED == STD_ON)
                    /* All events of Rx fifo */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_RXFIFO_EVENTS(H)
                #else /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
                    /* Rx Fifo Frame Available Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_FRAV(H)
                    /* RX Fifo Overflow Interrupt*/
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXOVER(H)
                    /* Rx Fifo Warning Interrupt */
                    /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                    /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                    /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                    /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                        CAN_MB_RXWARN(H)
                #endif /* (CAN_RXFIFO_EVENT_UNIFIED == STD_OFF) */
            #else /* (CAN_H_FIFO_EN == STD_OFF) */
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(H, MB_00_03, 0U, 3U)
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(H, MB_04_07, 4U, 7U)
            #endif /* (CAN_F_FIFO_EN == STD_OFF) */
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(H, MB_08_11, 8U,11U)
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(H, MB_12_15,12U,15U)
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(H, MB_16_31,16U,31U)
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_RXISRS(H, MB_32_63,32U,63U)

                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_ON) */

    #elif ((CAN_H_TXINT_SUPPORTED == STD_ON) && (CAN_H_RXINT_SUPPORTED == STD_OFF))
        #if (CAN_ISROPTCODESIZE == STD_ON)
            /* All MBs */
            /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
            CAN_MB_UNITXISRS(H)
        #else /* (CAN_ISROPTCODESIZE == STD_OFF) */
            #if (CAN_H_FIFO_EN == STD_OFF)
                   /* Message Buffer 00_03 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(H, MB_00_03, 0U, 3U)
                   
                   /* Message Buffer 04_07 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(H, MB_04_07, 4U, 7U)
            #endif /* (CAN_D_FIFO_EN == STD_OFF) */
            
                   /* Message Buffer 08_11 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(H, MB_08_11, 8U,11U)
                   
                   /* Message Buffer 12_15 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(H, MB_12_15,12U,15U)
                   
                   /* Message Buffer 16_31 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(H, MB_16_31,16U,31U)
                   
                   /* Message Buffer 32_63 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_TXISRS(H, MB_32_63,32U,63U)
                   
                   /* Message Buffer 64_95 */
                   /* @violates @ref Can_Irq_c_REF_5  Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer. */
                   /* @violates @ref Can_Irq_c_REF_6 Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed */
                   /* @violates @ref Can_Irq_c_REF_4 Violates MISRA 2004 Required Rule 17.4, pointer arithmetic other than array indexing used */
                   /* @violates @ref Can_Irq_c_REF_10 Violates MISRA 2004 Required Rule 8.10, external ... could be made static */
                   /* @violates @ref Can_Irq_c_REF_9 Violates MISRA 2004 Rule 12.1, due to the macro CAN_BIT_ASSIGN */
                        CAN_MB_ISRS(H, MB_64_95,64U,95U)
        #endif /* (CAN_ISROPTCODESIZE == STD_OFF) */
    #endif /* ((CAN_F_TXINT_SUPPORTED == STD_ON) && (CAN_F_RXINT_SUPPORTED == STD_ON)) */
#endif /* CAN_FCF_INDEX */

#define CAN_STOP_SEC_CODE
/* @violates @ref Can_Irq_c_REF_1 MISRA 2004 Rule 19.1, #include preceded by non preproc directives. */
/* @violates @ref Can_Irq_c_REF_2 MISRA 2004 Rule 19.15, Repeated include file MemMap.h  */
#include "Can_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
