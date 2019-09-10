/**
*   @file    Gpt_Rtc.c
*   @implements     Gpt_Rtc.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - Source file of the RTC driver.
*   @details RTC driver interface.
*
*   @addtogroup GPT_MODULE
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
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GPT_RTC_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation  is not  fixed since  the inclusion  of MemMap.h  is as  per Autosar  requirement
* MEMMAP003.
*
* @section GPT_RTC_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_RTC_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_RTC_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section GPT_RTC_C_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_RTC_C_REF_7
* Violates MISRA 2004 Advisory Rule 12.1, Use of mixed mode arithmetic
* This violation is due to the macro CAN_BIT_ASSIGN and no explicit cast operation used for the parameters passed
* to the macro. The care is taken for the parameters sent as inputs to the macro and hence unintended truncation of values
* would not result.
*
* @section GPT_RTC_C_REF_8
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function. These objects are used in various parts of the code
*
* @section GPT_RTC_C_REF_9
* Violates MISRA 2004 Required Rule 8.1, Functions shall have prototype declarations and the
* prototype shall be visible at both the function definition and call.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*/
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Gpt_Rtc.c
*/
#include "Std_Types.h"
#include "Gpt_Rtc.h"
#include "Reg_eSys_Rtc.h"
#include "Gpt_Ipw_Irq.h"
#include "SchM_Gpt.h"

#define USER_MODE_REG_PROT_ENABLED (GPT_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Gpt_Rtc.c
*/
#define GPT_RTC_VENDOR_ID_C                    43
#define GPT_RTC_AR_RELEASE_MAJOR_VERSION_C     4
#define GPT_RTC_AR_RELEASE_MINOR_VERSION_C     2
#define GPT_RTC_AR_RELEASE_REVISION_VERSION_C  2
#define GPT_RTC_SW_MAJOR_VERSION_C             1
#define GPT_RTC_SW_MINOR_VERSION_C             0
#define GPT_RTC_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_RTC_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_RTC_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_Rtc.c and Std_Types.h are different"
    #endif
#endif
#if (GPT_RTC_VENDOR_ID_C != GPT_RTC_VENDOR_ID)
#error "Gpt_Rtc.c and Gpt_Rtc.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_RTC_AR_RELEASE_MAJOR_VERSION_C != GPT_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_MINOR_VERSION_C != GPT_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_REVISION_VERSION_C != GPT_RTC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc.c and Gpt_Rtc.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_RTC_SW_MAJOR_VERSION_C != GPT_RTC_SW_MAJOR_VERSION) || \
     (GPT_RTC_SW_MINOR_VERSION_C != GPT_RTC_SW_MINOR_VERSION) || \
     (GPT_RTC_SW_PATCH_VERSION_C != GPT_RTC_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Rtc.c and Gpt_Rtc.h are different"
#endif


#if (GPT_RTC_VENDOR_ID_C != REG_ESYS_RTC_VENDOR_ID)
#error "Gpt_Rtc.c and Reg_eSys_Rtc.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_RTC_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_RTC_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_RTC_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc.c and Reg_eSys_Rtc.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_RTC_SW_MAJOR_VERSION_C != REG_ESYS_SW_MAJOR_VERSION) || \
     (GPT_RTC_SW_MINOR_VERSION_C != REG_ESYS_SW_MINOR_VERSION) || \
     (GPT_RTC_SW_PATCH_VERSION_C != REG_ESYS_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_Rtc.c and Reg_eSys_Rtc.h are different"
#endif

/* Check if source file and GPT header file are of the same vendor */
#if (GPT_IPW_IRQ_VENDOR_ID != GPT_RTC_VENDOR_ID_C)
    #error "Gpt_Rtc.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
/* Check if source file and GPT header file are of the same Autosar version */
#if ((GPT_RTC_AR_RELEASE_MAJOR_VERSION_C  != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_MINOR_VERSION_C  != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc.c  and  Gpt_Irq_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_RTC_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_RTC_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_RTC_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Rtc.c and Gpt_Irq_Irq.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same vendor */
#if (GPT_RTC_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Gpt_Rtc.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((GPT_RTC_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (GPT_RTC_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_Rtc.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((GPT_RTC_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
     (GPT_RTC_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
     (GPT_RTC_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_Rtc.c and SilRegMacros.h are different"
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef IPV_RTC
#define RTC_OVERFLOW_PAD_U32         ((uint32)1U)
    
#endif
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
#define GPT_START_SEC_VAR_INIT_32
/** @violates @ref GPT_RTC_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_RTC_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @brief          Global array variable used to store the runtime target time value.
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
VAR(uint32, GPT_VAR) Gpt_Rtc_u32TargetValue = 0U;

/**
* @brief          Global array variable used to store the counter value when interrupt occurs.
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/** @violates @ref GPT_RTC_C_REF_8 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
VAR(uint32, GPT_VAR) Gpt_Rtc_u32CounterValueInterrupt = 0U;

 #define GPT_STOP_SEC_VAR_INIT_32
/** @violates @ref GPT_RTC_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_RTC_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
/* @violates @ref GPT_RTC_C_REF_2 MISRA 2004 Advisory Rule 19.15,Repeated include MemMap.h */
/* @violates @ref GPT_RTC_C_REF_1 MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
#include "Gpt_MemMap.h"

#ifdef GPT_RTC_0_CH_0_ISR_USED
ISR(Gpt_RTC_0_Ch_0_ISR);
#endif

#if (GPT_RTC_USED == STD_ON)
static FUNC (void, GPT_CODE) Gpt_Rtc_ProcessInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif

/* @violates @ref GPT_RTC_H_REF_5 Violates MISRA 2004 Required Rule 19.11 All macro identifiers in preprocessor directives shall be defined */
/* @violates @ref GPT_RTC_H_REF_4 Violates MISRA 2004 Required Rule 10.1 shall not be implicitly converted */
#if (IPV_RTC == IPV_RTC_00_03_00_03)
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
#if (GPT_ENABLE_USER_MODE_SUPPORT == STD_ON)
FUNC(void, GPT_CODE) Gpt_Rtc_DisableSupervisorBit(void);
#endif /* (GPT_ENABLE_USER_MODE_SUPPORT == STD_ON) */
#endif /* GPT_ENABLE_USER_MODE_SUPPORT */
#endif

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (GPT_RTC_USED == STD_ON)
/**
* @brief   RTC_Gpt_ProcessInterrupt.
* @details Non-AutoSar support function used by interrupt service routines to call notification 
*          functions if provided and enabled
*    
* @param[in]     hwChannel      hardware channel index
* @implements Gpt_Rtc_ProcessInterrupt_Activity
*/
static FUNC(void, GPT_CODE) Gpt_Rtc_ProcessInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint32,AUTOMATIC) u32Temp2;

    /* u32Temp1 = RTC_READ_API_INTERRUPT(); */
    
    /* Check the status flag register and interrupt enable register */
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    u32Temp1 = REG_BIT_GET32(RTC_STATUS_ADDR32, RTC_STATUS_APIF_MASK_U32);
    
    /* u32Temp2 = RTC_READ_API_INT_ENABLE(); */
    
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    u32Temp2 = REG_BIT_GET32(RTC_CTRL_ADDR32, RTC_CTLR_APIIE_MASK_U32);
    
    /* Get counter value for elapse */
    /* Gpt_Rtc_u32CounterValueInterrupt = Gpt_Rtc_u32TargetValue + RTC_API_GET_COUNTER(); */

#if (IPV_RTC == IPV_RTC_00_03_00_03)
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 MISRA 2004 Required Rule 11.3,Cast from unsigned long to pointer. */
    /** @violates @ref GPT_RTC_C_REF_7 MISRA 2004 Required Rule 12.1,Use of mixed mode arithmetic. */
    Gpt_Rtc_u32CounterValueInterrupt = Gpt_Rtc_u32TargetValue + REG_READ32(RTC_CNT_ADDR32) & RTC_APIVAL_MASK_U32;
#else
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 MISRA 2004 Required Rule 11.3,Cast from unsigned long to pointer. */
    /** @violates @ref GPT_RTC_C_REF_7 MISRA 2004 Required Rule 12.1,Use of mixed mode arithmetic. */
    Gpt_Rtc_u32CounterValueInterrupt = Gpt_Rtc_u32TargetValue + REG_READ32(RTC_WKEUP_CNT_ADDR32) & RTC_APIVAL_MASK_U32;
#endif
    
    if((RTC_STATUS_APIF_MASK_U32 == u32Temp1) && (RTC_CTLR_APIIE_MASK_U32 == u32Temp2))
    {
        /* Call GPT upper layer handler */
        Gpt_Ipw_ProcessCommonInterrupt(u8HwChannel,(uint8)GPT_RTC_MODULE);
    }

    /*Clear interrupt flag*/
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_STATUS_ADDR32, RTC_STATUS_APIF_MASK_U32);
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (IPV_RTC == IPV_RTC_00_03_00_03)
    
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
#if (GPT_ENABLE_USER_MODE_SUPPORT == STD_ON)
/**
* @brief        Enables RTC registers writing in User Mode by configuring RTCSUPV
* @details      resets the SUPV bit (RTC Supervisor Bit.) bit of the RTC IP to allow acces to registers in User Mode
*
* @param[in]    none
*
* @return       none
*
* @pre          Should be executed in supervisor mode
* @post         none
*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Rtc_DisableSupervisorBit(void)
/** @violates @ref GPT_RTC_C_REF_9 Violates MISRA 2004 Required Rule 8.1 Functions shall have prototype declarations and the */
{
    /* Allow User mode access to RTC */
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(RTC_SUPV_ADDR32, RTC_SUPV_MASK_U32);
}
#endif /* (GPT_ENABLE_USER_MODE_SUPPORT == STD_ON) */
#endif /* GPT_ENABLE_USER_MODE_SUPPORT */
#endif

/*================================================================================================*/
/**
* @brief          Gpt driver initialization function for the Rtc module.
* @details        This function:
*                       - resets the Rtc control register
*                       - clears the Rtc interrupt flags
*                       - sets the clock source for Rtc  (selection in tresos)
*                       - sets the prescaler value (selection in tresos)
*                       - configures the freeze mode (enabled/disabled)
*                       - enables API Interrupt (RTCC - APIIE) - the RTCC - APIEN (API function) is
*                         not enabled here, but enabled when starting the RTC timer channel, after
*                         setting the timeout value (in RTCC - APIVAL)
*                       - enables the RTC counter
*
* @param[in]     freezeEnable     indicates if the Freeze mode is enabled
* @param[in]     channelClkSrc    clock source for the RTC channel
* @param[in]     channelPrescale   Prescaler value for the RTC channel
*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (void, GPT_CODE) Gpt_Rtc_Init
(
    VAR(Rtc_Gpt_ChannelClkSrcType,  AUTOMATIC) channelClkSrc,
    VAR(uint8,                      AUTOMATIC) u8ChannelPrescale,
    VAR(boolean,                    AUTOMATIC) bFreezeEnable
)
{

#if (IPV_RTC == IPV_RTC_00_03_00_03)
    
#ifdef GPT_ENABLE_USER_MODE_SUPPORT
#if (GPT_ENABLE_USER_MODE_SUPPORT == STD_ON)
    /* Clear the supervisor only access bit from RTCSUPV */
    Mcal_Trusted_Call(Gpt_Rtc_DisableSupervisorBit,());
#endif /* (GPT_ENABLE_USER_MODE_SUPPORT == STD_ON) */
#endif /* GPT_ENABLE_USER_MODE_SUPPORT */

    /* Reset RTC control register */
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_RMW32(RTC_CTRL_ADDR32, (uint32)0xDFFFFFFFUL, (uint32)0x0UL);

    /* Clear interrupt request */
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_STATUS_ADDR32, RTC_STATUS_ALL_INT_MASK_U32);
    
    /* Configure clock select */
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_RMW32(RTC_CTRL_ADDR32, RTC_CTLR_CLKSEL_MASK_U32, (uint32)(((uint32)channelClkSrc)<<RTC_CLKSEL_OFFSET));
#else
    /* Reset RTC control register */
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_CTRL_ADDR32, (uint32)0x0UL);

    /* Clear interrupt request */
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_STATUS_ADDR32, BIT15|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2);
    
    /* Configure clock select */
    /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_RMW32(RTC_CTRL_ADDR32, RTC_CTLR_SCLKSEL_MASK_U32, (uint32)(((uint32)channelClkSrc)<<RTC_CTLR_SCLKSEL_SHIFT));
#endif
    
#if (IPV_RTC != IPV_RTC_00_03_00_03)
    if(RTC_GPT_CLKSRC_XOSC == channelClkSrc)
    {
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_CLEAR32(RTC_CTRL_ADDR32, RTC_CTLR_CLKSEL_MASK_U32);
    }
    else
    {
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_SET32(RTC_CTRL_ADDR32, RTC_CTLR_CLKSEL_MASK_U32);
    }
#endif

    /* RTC_CONFIGURE_PRESCALER(u8ChannelPrescale); */
#if (IPV_RTC != IPV_RTC_00_03_00_03)
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_RMW32(RTC_CTRL_ADDR32, RTC_CTLR_PREDIV_MASK_U32, (uint32)(((uint32)u8ChannelPrescale) << RTC_CTLR_PREDIV_SHIFT));
#else
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_RMW32(RTC_CTRL_ADDR32, (RTC_CTLR_DIV32EN_MASK_U32 | RTC_CTLR_DIV512EN_MASK_U32), (uint32)(((uint32)u8ChannelPrescale) << RTC_DIV_OFFSET));
#endif
    
    if ((boolean)TRUE == bFreezeEnable)
    {
        /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        /* RTC_FREEZE_ENABLE(); */
        REG_BIT_SET32(RTC_CTRL_ADDR32, RTC_CTLR_FRZEN_MASK_U32);
    }

    Gpt_Rtc_u32TargetValue = 0U;
}

#if (GPT_DEINIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief         Gpt driver de-initialization function for Rtc module.
* @details       This function:
*                       - resets the Rtc control register
*                       - clears the Rtc interrupt flags
*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (void, GPT_CODE) Gpt_Rtc_DeInit()
{
    Gpt_Rtc_u32TargetValue = 0U;

#if (IPV_RTC == IPV_RTC_00_03_00_03)
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_RMW32(RTC_CTRL_ADDR32, (uint32)0xDFFFFFFFUL, (uint32)0x0UL);

    /* Clear all interrupts */
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_STATUS_ADDR32, RTC_STATUS_ALL_INT_MASK_U32);
#else
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_CTRL_ADDR32, (uint32)0x0UL);

    /* Clear all interrupts */
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_STATUS_ADDR32, BIT15|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2);
#endif
    
}
#endif

/*================================================================================================*/
/**
* @brief          A brief text description (one line).
* @details        A detailed text description of the code object being described, it can span more
*                 lines and contain formatting tags (both Doxygen and HTML). Optional tag.
*
* @brief          Gpt driver function for starting the Rtc timer channel.
* @details        This function:
*                       - disables the API functionality
*                       - sets the timeout value (in RTCC - APIVAL)
*                       - enables API functionality (RTCC - APIEN).
*                       - reads the RTC counter register and stores the value of the channel start time
*                       - if in one shot mode, enables API Interrupt, in order to stop the channel in the ISR
*
* @param[in]      value            channel timeout value
* @param[in]      channelMode      One Shot or Continous
*
* @param[in,out]  startTimeValuePtr pointer to the start time value
*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (void, GPT_CODE) Gpt_Rtc_StartTimer
(
    VAR(uint32,     AUTOMATIC) u32Value
)
{
    Gpt_Rtc_u32TargetValue = u32Value;
    
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_09();
    {
        /* Disable Interrupt */
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_CLEAR32(RTC_CTRL_ADDR32, RTC_CTLR_APIEN_MASK_U32);

#if (IPV_RTC == IPV_RTC_00_03_00_03)
        /* Disable Counter */
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_CLEAR32(RTC_CTRL_ADDR32, RTC_CTLR_CNTEN_MASK_U32);
#else
        /* Disable Counter */
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_CLEAR32(RTC_CTRL_ADDR32, RTC_CTLR_RTCEN_MASK_U32);
#endif

        /* Configure channel compare register */
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_WRITE32(RTC_APIVAL_ADDR32, (u32Value));
    
        /* Enable Interrupt */
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        /* RTC_API_ENABLE(); */
        REG_BIT_SET32(RTC_CTRL_ADDR32, RTC_CTLR_APIEN_MASK_U32);
    
#if (IPV_RTC == IPV_RTC_00_03_00_03)
        /* Restart API counter */
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_SET32(RTC_CTRL_ADDR32, RTC_CTLR_CNTEN_MASK_U32);
#else
        /* Restart API counter */
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_SET32(RTC_CTRL_ADDR32, RTC_CTLR_RTCEN_MASK_U32);
#endif
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_09();
}

/*================================================================================================*/
/**
* @brief          Gpt driver function for stopping the Rtc timer channel.
* @details        This function:
*                           - disables the API functionality
*                           - clears the API interrupt flag
* @param[out]    returnValuePtr   current time value on stop
*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (void, GPT_CODE) Gpt_Rtc_StopTimer(void)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_10();
    {
        /* Stop API counter */
        /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_CLEAR32(RTC_CTRL_ADDR32, RTC_CTLR_APIEN_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_10();
    /* Clear interrupt flag */
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_STATUS_ADDR32, RTC_STATUS_APIF_MASK_U32);
}

/*================================================================================================*/
/**
* @brief          A brief text description (one line).
* @details        A detailed text description of the code object being described, it can span more
*                 lines and contain formatting tags (both Doxygen and HTML). Optional tag.
*
* @brief           Gpt driver function for getting the current time value for an Rtc timer channel.
* @details        This function:
*                        - reads timeOut value (RTCC - APIVAL)
*                        - reads the RTC counter register
*                        - depending on above it calculates and returns the current time
*
* @param[in]      startTimeValue   RTC start timer value
* @param[out]    returnValuePtr   current time value
*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC (uint32, GPT_CODE) Gpt_Rtc_GetTimeElapsed
(
    P2VAR(boolean,      AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
    P2VAR(uint32,       AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
)
{
    VAR(uint32, AUTOMATIC) u32ReturnValue = 0U;
    VAR(uint32, AUTOMATIC) u32CounterValue;
    VAR(uint32, AUTOMATIC) u32TempValue;
    VAR(uint32, AUTOMATIC) u32CompareValue;

    /* Read counter register */
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    *pu32TargetValue = Gpt_Rtc_u32TargetValue;
    
#if (IPV_RTC == IPV_RTC_00_03_00_03)
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    u32CounterValue = REG_READ32(RTC_CNT_ADDR32) & RTC_APIVAL_MASK_U32;

    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    u32CompareValue = REG_READ32(RTC_APIVAL_ADDR32);
#else
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    u32CounterValue = REG_READ32(RTC_WKEUP_CNT_ADDR32) & RTC_APIVAL_MASK_U32;

    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    u32CompareValue = RTC_APIVAL_MASK_U32 & REG_READ32(RTC_APIVAL_ADDR32);
#endif
    
    /* Calculate the elapsed time */
    if (u32CounterValue >= u32CompareValue)
    {
        u32TempValue = Gpt_Rtc_u32CounterValueInterrupt - u32CounterValue;
    }
    else
    {
        u32TempValue = u32CompareValue - u32CounterValue;
    }
    
    if (u32TempValue > *pu32TargetValue)
    {
        u32ReturnValue = *pu32TargetValue;
    }
    else
    {
         u32ReturnValue = *pu32TargetValue - u32TempValue;
    }

    /*Check interrupt status flag*/
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    if (REG_BIT_GET32(RTC_STATUS_ADDR32, RTC_STATUS_APIF_MASK_U32))
    {
        /* Channel counter was rollover */
        *pbReturnChannelRollover = (boolean)TRUE;
    }
    else     
    {
        /* Channel counter was not rollover */
        *pbReturnChannelRollover = (boolean)FALSE;
    }
    return u32ReturnValue;
}
#if (GPT_SET_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function changes the RTC prescaler value.
* @details    This function sets the RTC prescaler based on the input mode.
*
* @param[in]  u8chPrescale     prescaler value
*
* @pre     On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
*

*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Rtc_SetClockMode(VAR(uint8, AUTOMATIC) u8chPrescale)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_11();
    {
#if (IPV_RTC != IPV_RTC_00_03_00_03)
        /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_RMW32(RTC_CTRL_ADDR32, RTC_CTLR_PREDIV_MASK_U32, (uint32)(((uint32)u8chPrescale) << RTC_CTLR_PREDIV_SHIFT));
#else
        /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_RMW32(RTC_CTRL_ADDR32, (RTC_CTLR_DIV32EN_MASK_U32 | RTC_CTLR_DIV512EN_MASK_U32), (uint32)(((uint32)u8chPrescale)<<RTC_DIV_OFFSET));
#endif
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_11();
}
#endif

/**
*
* @brief           Gpt driver function for Enable Interrupt for RTC channel
* @details        This function:
*                        - Enable Interrupt for RTC channel
*
* @param[in]      No required

*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/

FUNC(void, GPT_CODE) Gpt_Rtc_EnableInterrupt(void)
{
    /* Clear interrupt flag */
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_STATUS_ADDR32, RTC_STATUS_APIF_MASK_U32);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_12();
    {
        /* Enable API interrupt and start RTC counter */
        /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_SET32(RTC_CTRL_ADDR32, RTC_CTLR_APIIE_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_12();
}

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
*
* @brief           Gpt driver function for Disable Interrupt for RTC channel
* @details        This function:
*                        - Disable Interrupt for RTC channel
*
* @param[in]      No required

*
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
FUNC(void, GPT_CODE) Gpt_Rtc_DisableInterrupt(void)
{
    /* Clear interrupt flag */
    /* @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
    /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
    REG_WRITE32(RTC_STATUS_ADDR32, RTC_STATUS_APIF_MASK_U32);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_13();
    {
        /* Disable Interrupt */
        /** @violates @ref GPT_RTC_C_REF_3 MISRA 2004 Required Rule 11.1,Cast from unsigned long to pointer */
        /** @violates @ref GPT_RTC_C_REF_6 Cast from unsigned long to pointer. */
        REG_BIT_CLEAR32(RTC_CTRL_ADDR32, RTC_CTLR_APIIE_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_13();
}
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API || GPT_WAKEUP_FUNCTIONALITY_API */

#ifdef GPT_RTC_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief          Interrupt handler for RTC channel
* @details        Interrupt Service Routine corresponding to Gpt_RTC_Ch_0 hw channel.
*
*
* @isr
* @violates @ref GPT_RTC_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_RTC_0_Ch_0_ISR)
{
    Gpt_Rtc_ProcessInterrupt((uint8)RTC_0_CH_0);
    /* @violates @ref GPT_RTC_IRQ_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer */
    /* @violates @ref GPT_RTC_IRQ_C_REF_4 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif

#define GPT_STOP_SEC_CODE
/* @violates @ref GPT_RTC_C_REF_1 MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include" */
/* @violates @ref GPT_RTC_C_REF_2 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
