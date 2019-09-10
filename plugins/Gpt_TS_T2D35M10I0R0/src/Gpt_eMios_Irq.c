/**
*   @file           Gpt_eMios_Irq.c
*   @implements     Gpt_eMios_Irq.c_Artifact
*   @version        1.0.0
*
*   @brief          AUTOSAR Gpt - eMios interrupt handler driver source file.
*   @details        eMios interrupt handling routines.
*
*   @addtogroup     GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios_Stm_Pit
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
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
    
#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Gpt_eMios_Irq_C_REF_1
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between 
* a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
* registers or other hardware specific features.
*
* @section Gpt_eMios_Irq_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Gpt_eMios_Irq_C_REF_3
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
* 
* @section Gpt_eMios_Irq_C_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Gpt_eMios_Irq_C_REF_5
* Violates MISRA 2004 Advisory Rule 11.3, Conversions shall not be performed between 
* a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
* registers or other hardware specific features.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not 
* rely on the significance of more than 31 characters.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_eMios_Irq.h"
#include "Gpt_Ipw_Irq.h"
#include "Reg_eSys_eMios.h"

#define USER_MODE_REG_PROT_ENABLED  (GPT_USER_MODE_SOFT_LOCKING)
/*
* @violates @ref Gpt_eMios_Irq_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "SilRegMacros.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_EMIOS_IRQ_VENDOR_ID_C                       43
#define GPT_EMIOS_IRQ_MODULE_ID_C                       100

#define GPT_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION_C        4
#define GPT_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION_C        2
#define GPT_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION_C     2
#define GPT_EMIOS_IRQ_SW_MAJOR_VERSION_C                1
#define GPT_EMIOS_IRQ_SW_MINOR_VERSION_C                0
#define GPT_EMIOS_IRQ_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/* Check if current file and Gpt_eMios_Irq.h header file are of the same vendor */
#if (GPT_EMIOS_IRQ_VENDOR_ID_C != GPT_EMIOS_IRQ_VENDOR_ID)
    #error "Gpt_eMios_Irq.c and Gpt_eMios_Irq.h have different vendor ids"
#endif

/* Check if source file and Gpt_eMios_Irq.h are of the same Autosar version */
#if ((GPT_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION_C    != GPT_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION_C    != GPT_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios_Irq.c and Gpt_eMios_Irq.h are different"
#endif


/* Check if source file and Gpt_eMios_Irq.h are of the same software version */
#if ((GPT_EMIOS_IRQ_SW_MAJOR_VERSION_C != GPT_EMIOS_IRQ_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_IRQ_SW_MINOR_VERSION_C != GPT_EMIOS_IRQ_SW_MINOR_VERSION) || \
     (GPT_EMIOS_IRQ_SW_PATCH_VERSION_C != GPT_EMIOS_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_eMios_Irq.c and Gpt_eMios_Irq.h are different"
#endif


/* Check if current file and Reg_eSys_eMios.h file are of the same vendor */
#if (GPT_EMIOS_IRQ_VENDOR_ID_C != REG_ESYS_EMIOS_VENDOR_ID)
    #error "Gpt_eMios_Irq.c and Reg_eSys_eMios.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_eMios.h file are of the same Autosar version */
#if ((GPT_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION)|| \
     (GPT_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_EMIOS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios_Irq.c and Reg_eSys_eMios.h are different"
#endif

/* Check if source file and Reg_eSys_eMios.h file are of the same software version */
#if ((GPT_EMIOS_IRQ_SW_MAJOR_VERSION_C != REG_ESYS_EMIOS_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_IRQ_SW_MINOR_VERSION_C != REG_ESYS_EMIOS_SW_MINOR_VERSION)|| \
     (GPT_EMIOS_IRQ_SW_PATCH_VERSION_C != REG_ESYS_EMIOS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_eMios_Irq.c and Reg_eSys_eMios.h are different"
#endif


/* Check if source file and SilRegMacros.h are of the same vendor */
#if (GPT_EMIOS_IRQ_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Gpt_eMios_Irq.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((GPT_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (GPT_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios_Irq.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((GPT_EMIOS_IRQ_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_IRQ_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
     (GPT_EMIOS_IRQ_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_eMios_Irq.c and SilRegMacros.h are different"
#endif


#if (GPT_EMIOS_IRQ_VENDOR_ID_C != GPT_IPW_IRQ_VENDOR_ID)
    #error "Gpt_eMios_Irq.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios_Irq.c and Gpt_Ipw_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_EMIOS_IRQ_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_IRQ_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_EMIOS_IRQ_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_eMios_Irq.c and Gpt_Ipw_Irq.h are different"
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
#define GPT_START_SEC_CODE
/*
* @violates @ref Gpt_eMios_Irq_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Gpt_MemMap.h"


#if (GPT_EMIOS_USED == STD_ON)
/**
* @brief   Driver routine to process all the interrupts of eMios.
* @details Non-AutoSar support function used by interrupt service routines to call notification
*          functions if provided and enabled
*
* @param[in]     u8HwChannel      hardware channel index
* @implements  Gpt_eMios_ProcessCommonInterrupt_Activity
*/
/** @violates @ref Gpt_eMios_Irq_C_REF_3 Violates MISRA 2004 Required Rule 8.10, Declarations 
and definitions of Objects or Functions at File scope */
FUNC(void, GPT_CODE) Gpt_eMios_ProcessCommonInterrupt (VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint32,AUTOMATIC) u32Temp2;

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /** @violates @ref Gpt_eMios_Irq_C_REF_1 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_Irq_C_REF_5 Cast from unsigned long to pointer */
    u32Temp1 = REG_READ32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx));
    /** @violates @ref Gpt_eMios_Irq_C_REF_1 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_Irq_C_REF_5 Cast from unsigned long to pointer */
    u32Temp2 = REG_READ32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx));

    /* Check for spurious interrupts */
    if ((((uint32)CSR_FLAG_MASK_U32 & u32Temp1) == (uint32)CSR_FLAG_MASK_U32)
       && (((uint32)CCR_FEN_MASK_U32 & u32Temp2) == (uint32)CCR_FEN_MASK_U32))
    {
        /* Call GPT upper layer handler */
        Gpt_Ipw_ProcessCommonInterrupt(u8HwChannel,(uint8)GPT_EMIOS_MODULE);
    }

    /* Clear interrupt flag */
    /** @violates @ref Gpt_eMios_Irq_C_REF_1 Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_Irq_C_REF_5 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);
}
#endif /*GPT_EMIOS_USED == STD_ON*/


#define GPT_STOP_SEC_CODE
/*
* @violates @ref Gpt_eMios_Irq_C_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
/*
* @violates @ref Gpt_eMios_Irq_C_REF_4 #include statements in a file should
* only be preceded by other preprocessor directives or comments.
*/
#include "Gpt_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
