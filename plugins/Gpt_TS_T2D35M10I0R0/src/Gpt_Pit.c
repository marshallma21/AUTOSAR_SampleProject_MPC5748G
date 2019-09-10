/**
*   @file    Gpt_Pit.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - PIT driver source file.
*   @details Detailed file description (can be multiple lines).
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
* @section GPT_PIT_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section GPT_PIT_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section GPT_PIT_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section GPT_PIT_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_PIT_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section GPT_PIT_C_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, Cast from unsigned long to pointer.
* This violation is due to the pointer arithematic used to write/ read
* the data to/from the registers.
*
* @section GPT_PIT_C_REF_7
* Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'. 
* This violation is because of complex statement
*
* @section GPT_PIT_C_REF_8
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section GPT_PIT_C_REF_9
* Violates MISRA 2004 Required Rule 9.2, Braces shall be used to indicate and match the structure in the 
* non-zero initialisation of arrays and structures. At here, we tend to initialized for whole structure, however, 
* when configure only 1 controller is configured, tool reported as non-zero initialisation. 
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Ipw_Irq.h"
#include "Gpt_Pit.h"
#include "Reg_eSys_Pit.h"
#include "SchM_Gpt.h"

#define USER_MODE_REG_PROT_ENABLED (GPT_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_PIT_VENDOR_ID_C                    43
/** @violates @ref GPT_PIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_PIT_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref GPT_PIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_PIT_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref GPT_PIT_C_REF_4 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_PIT_AR_RELEASE_REVISION_VERSION_C  2
#define GPT_PIT_SW_MAJOR_VERSION_C             1
#define GPT_PIT_SW_MINOR_VERSION_C             0
#define GPT_PIT_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_PIT_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_PIT_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Gpt_Pit.c and Std_Types.h are different"
    #endif
#endif

#if ( GPT_PIT_VENDOR_ID_C!= GPT_IPW_IRQ_VENDOR_ID)
    #error "Gpt_Pit.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Pit.c and Gpt_Ipw_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_PIT_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_PIT_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_PIT_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Pit.c and Gpt_Ipw_Irq.h are different"
#endif

#if (GPT_PIT_VENDOR_ID_C!= GPT_PIT_VENDOR_ID)
    #error "Gpt_Pit.c and Gpt_Pit.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_AR_RELEASE_MAJOR_VERSION_C != GPT_PIT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_MINOR_VERSION_C != GPT_PIT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_REVISION_VERSION_C != GPT_PIT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Pit.c and Gpt_Pit.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_PIT_SW_MAJOR_VERSION_C != GPT_PIT_SW_MAJOR_VERSION) || \
     (GPT_PIT_SW_MINOR_VERSION_C != GPT_PIT_SW_MINOR_VERSION) || \
     (GPT_PIT_SW_PATCH_VERSION_C != GPT_PIT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Pit.c and Gpt_Pit.h are different"
#endif

#if ( GPT_PIT_VENDOR_ID_C!= REG_ESYS_PIT_VENDOR_ID)
    #error "Gpt_Pit.c and Reg_eSys_Pit.h have different vendor ids"
#endif
/* Check if source file and Gpt header file are of the same Autosar version */
#if ((GPT_PIT_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_PIT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_PIT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_PIT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Pit.c and Reg_eSys_Pit.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_PIT_SW_MAJOR_VERSION_C != REG_ESYS_PIT_SW_MAJOR_VERSION) || \
     (GPT_PIT_SW_MINOR_VERSION_C != REG_ESYS_PIT_SW_MINOR_VERSION) || \
     (GPT_PIT_SW_PATCH_VERSION_C != REG_ESYS_PIT_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Pit.c and Reg_eSys_Pit.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same vendor */
#if (GPT_PIT_VENDOR_ID_C != SILREGMACROS_VENDOR_ID)
    #error "Gpt_Pit.c and SilRegMacros.h have different vendor ids"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#if ((GPT_PIT_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
     (GPT_PIT_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Pit.c and SilRegMacros.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same software version */
#if ((GPT_PIT_SW_MAJOR_VERSION_C != SILREGMACROS_SW_MAJOR_VERSION) || \
     (GPT_PIT_SW_MINOR_VERSION_C != SILREGMACROS_SW_MINOR_VERSION) || \
     (GPT_PIT_SW_PATCH_VERSION_C != SILREGMACROS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Pit.c and SilRegMacros.h are different"
#endif


/*==================================================================================================
*                         LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#if (GPT_PIT_USED == STD_ON)

/**
* @brief Number of timers for each PIT module
*/

#define GPT_START_SEC_CONST_32
/** @violates @ref GPT_PIT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_PIT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"
/**
* @brief base address array for PIT
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/

CONST(uint32, GPT_CONST) PIT_BASE_ADDR32[PIT_MODULE_NUM_MAX_U8] = 
{
#ifdef PIT_0_BASEADDR
    PIT_0_BASEADDR
#elif defined(PIT_1_BASEADDR)
    (uint32)(0x00000000UL)
#endif
#ifdef PIT_1_BASEADDR
    ,PIT_1_BASEADDR
#endif
/** @violates @ref GPT_PIT_C_REF_9 MISRA rule 9.2 Braces shall be used to indicate and match the structure */
};

#define GPT_STOP_SEC_CONST_32
/** @violates @ref GPT_PIT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_PIT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

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

#define GPT_START_SEC_CODE
/** @violates @ref GPT_PIT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_PIT_C_REF_2 Repeated include file MemMap.h */

#include "Gpt_MemMap.h"

#if (GPT_PIT_MODULE_SINGLE_INTERRUPT == STD_ON)
#ifdef GPT_PIT_0_ISR_USED
ISR(Gpt_PIT_0_ISR);
#endif
#ifdef GPT_PIT_1_ISR_USED
ISR(Gpt_PIT_1_ISR);
#endif
#else

#ifdef GPT_PIT_0_CH_RTI_ISR_USED
ISR(Gpt_PIT_0_TIMER_RTI_ISR);
#endif

#ifdef GPT_PIT_0_CH_0_ISR_USED
ISR(Gpt_PIT_0_TIMER_0_ISR);
#endif

#ifdef GPT_PIT_0_CH_1_ISR_USED
ISR(Gpt_PIT_0_TIMER_1_ISR);
#endif

#ifdef GPT_PIT_0_CH_2_ISR_USED
ISR(Gpt_PIT_0_TIMER_2_ISR);
#endif

#ifdef GPT_PIT_0_CH_3_ISR_USED
ISR(Gpt_PIT_0_TIMER_3_ISR);
#endif

#ifdef GPT_PIT_0_CH_4_ISR_USED
ISR(Gpt_PIT_0_TIMER_4_ISR);
#endif

#ifdef GPT_PIT_0_CH_5_ISR_USED
ISR(Gpt_PIT_0_TIMER_5_ISR);
#endif

#ifdef GPT_PIT_0_CH_6_ISR_USED
ISR(Gpt_PIT_0_TIMER_6_ISR);
#endif

#ifdef GPT_PIT_0_CH_7_ISR_USED
ISR(Gpt_PIT_0_TIMER_7_ISR);
#endif

#ifdef GPT_PIT_0_CH_8_ISR_USED
ISR(Gpt_PIT_0_TIMER_8_ISR);
#endif

#ifdef GPT_PIT_0_CH_9_ISR_USED
ISR(Gpt_PIT_0_TIMER_9_ISR);
#endif

#ifdef GPT_PIT_0_CH_10_ISR_USED
ISR(Gpt_PIT_0_TIMER_10_ISR);
#endif

#ifdef GPT_PIT_0_CH_11_ISR_USED
ISR(Gpt_PIT_0_TIMER_11_ISR);
#endif

#ifdef GPT_PIT_0_CH_12_ISR_USED
ISR(Gpt_PIT_0_TIMER_12_ISR);
#endif

#ifdef GPT_PIT_0_CH_13_ISR_USED
ISR(Gpt_PIT_0_TIMER_13_ISR);
#endif

#ifdef GPT_PIT_0_CH_14_ISR_USED
ISR(Gpt_PIT_0_TIMER_14_ISR);
#endif

#ifdef GPT_PIT_0_CH_15_ISR_USED
ISR(Gpt_PIT_0_TIMER_15_ISR);
#endif

#ifdef GPT_PIT_1_CH_RTI_ISR_USED
ISR(Gpt_PIT_1_TIMER_RTI_ISR);
#endif

#ifdef GPT_PIT_1_CH_0_ISR_USED
ISR(Gpt_PIT_1_TIMER_0_ISR);
#endif

#ifdef GPT_PIT_1_CH_1_ISR_USED
ISR(Gpt_PIT_1_TIMER_1_ISR);
#endif

#ifdef GPT_PIT_1_CH_2_ISR_USED
ISR(Gpt_PIT_1_TIMER_2_ISR);
#endif

#ifdef GPT_PIT_1_CH_3_ISR_USED
ISR(Gpt_PIT_1_TIMER_3_ISR);
#endif

#ifdef GPT_PIT_1_CH_4_ISR_USED
ISR(Gpt_PIT_1_TIMER_4_ISR);
#endif

#ifdef GPT_PIT_1_CH_5_ISR_USED
ISR(Gpt_PIT_1_TIMER_5_ISR);
#endif

#ifdef GPT_PIT_1_CH_6_ISR_USED
ISR(Gpt_PIT_1_TIMER_6_ISR);
#endif

#ifdef GPT_PIT_1_CH_7_ISR_USED
ISR(Gpt_PIT_1_TIMER_7_ISR);
#endif

#ifdef GPT_PIT_1_CH_8_ISR_USED
ISR(Gpt_PIT_1_TIMER_8_ISR);
#endif

#ifdef GPT_PIT_1_CH_9_ISR_USED
ISR(Gpt_PIT_1_TIMER_9_ISR);
#endif

#ifdef GPT_PIT_1_CH_10_ISR_USED
ISR(Gpt_PIT_1_TIMER_10_ISR);
#endif

#ifdef GPT_PIT_1_CH_11_ISR_USED
ISR(Gpt_PIT_1_TIMER_11_ISR);
#endif

#ifdef GPT_PIT_1_CH_12_ISR_USED
ISR(Gpt_PIT_1_TIMER_12_ISR);
#endif

#ifdef GPT_PIT_1_CH_13_ISR_USED
ISR(Gpt_PIT_1_TIMER_13_ISR);
#endif

#ifdef GPT_PIT_1_CH_14_ISR_USED
ISR(Gpt_PIT_1_TIMER_14_ISR);
#endif

#ifdef GPT_PIT_1_CH_15_ISR_USED
ISR(Gpt_PIT_1_TIMER_15_ISR);
#endif

#endif /*GPT_PIT_MODULE_SINGLE_INTERRUPT == STD_ON*/

#if ((defined GPT_PIT_0_ISR_USED      ) ||(defined GPT_PIT_1_ISR_USED      )||(defined GPT_PIT_0_CH_RTI_ISR_USED)||(defined GPT_PIT_1_CH_RTI_ISR_USED)|| \
     (defined GPT_PIT_0_CH_0_ISR_USED ) ||(defined GPT_PIT_0_CH_1_ISR_USED )||(defined GPT_PIT_0_CH_2_ISR_USED  )||(defined GPT_PIT_0_CH_3_ISR_USED  )|| \
     (defined GPT_PIT_0_CH_4_ISR_USED ) ||(defined GPT_PIT_0_CH_5_ISR_USED )||(defined GPT_PIT_0_CH_6_ISR_USED  )||(defined GPT_PIT_0_CH_7_ISR_USED  )|| \
     (defined GPT_PIT_0_CH_8_ISR_USED ) ||(defined GPT_PIT_0_CH_9_ISR_USED )||(defined GPT_PIT_0_CH_10_ISR_USED )||(defined GPT_PIT_0_CH_11_ISR_USED )|| \
     (defined GPT_PIT_0_CH_12_ISR_USED) ||(defined GPT_PIT_0_CH_13_ISR_USED)||(defined GPT_PIT_0_CH_14_ISR_USED )||(defined GPT_PIT_0_CH_15_ISR_USED )|| \
     (defined GPT_PIT_1_CH_0_ISR_USED ) ||(defined GPT_PIT_1_CH_1_ISR_USED )||(defined GPT_PIT_1_CH_2_ISR_USED  )||(defined GPT_PIT_1_CH_3_ISR_USED  )|| \
     (defined GPT_PIT_1_CH_4_ISR_USED ) ||(defined GPT_PIT_1_CH_5_ISR_USED )||(defined GPT_PIT_1_CH_6_ISR_USED  )||(defined GPT_PIT_1_CH_7_ISR_USED  )|| \
     (defined GPT_PIT_1_CH_8_ISR_USED ) ||(defined GPT_PIT_1_CH_9_ISR_USED )||(defined GPT_PIT_1_CH_10_ISR_USED )||(defined GPT_PIT_1_CH_11_ISR_USED )|| \
     (defined GPT_PIT_1_CH_12_ISR_USED) ||(defined GPT_PIT_1_CH_13_ISR_USED)||(defined GPT_PIT_1_CH_14_ISR_USED )||(defined GPT_PIT_1_CH_15_ISR_USED )   \
    )
static FUNC (void, GPT_CODE) Gpt_Pit_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/

#if ((defined GPT_PIT_0_ISR_USED      ) ||(defined GPT_PIT_1_ISR_USED      )||(defined GPT_PIT_0_CH_RTI_ISR_USED)||(defined GPT_PIT_1_CH_RTI_ISR_USED)|| \
     (defined GPT_PIT_0_CH_0_ISR_USED ) ||(defined GPT_PIT_0_CH_1_ISR_USED )||(defined GPT_PIT_0_CH_2_ISR_USED  )||(defined GPT_PIT_0_CH_3_ISR_USED  )|| \
     (defined GPT_PIT_0_CH_4_ISR_USED ) ||(defined GPT_PIT_0_CH_5_ISR_USED )||(defined GPT_PIT_0_CH_6_ISR_USED  )||(defined GPT_PIT_0_CH_7_ISR_USED  )|| \
     (defined GPT_PIT_0_CH_8_ISR_USED ) ||(defined GPT_PIT_0_CH_9_ISR_USED )||(defined GPT_PIT_0_CH_10_ISR_USED )||(defined GPT_PIT_0_CH_11_ISR_USED )|| \
     (defined GPT_PIT_0_CH_12_ISR_USED) ||(defined GPT_PIT_0_CH_13_ISR_USED)||(defined GPT_PIT_0_CH_14_ISR_USED )||(defined GPT_PIT_0_CH_15_ISR_USED )|| \
     (defined GPT_PIT_1_CH_0_ISR_USED ) ||(defined GPT_PIT_1_CH_1_ISR_USED )||(defined GPT_PIT_1_CH_2_ISR_USED  )||(defined GPT_PIT_1_CH_3_ISR_USED  )|| \
     (defined GPT_PIT_1_CH_4_ISR_USED ) ||(defined GPT_PIT_1_CH_5_ISR_USED )||(defined GPT_PIT_1_CH_6_ISR_USED  )||(defined GPT_PIT_1_CH_7_ISR_USED  )|| \
     (defined GPT_PIT_1_CH_8_ISR_USED ) ||(defined GPT_PIT_1_CH_9_ISR_USED )||(defined GPT_PIT_1_CH_10_ISR_USED )||(defined GPT_PIT_1_CH_11_ISR_USED )|| \
     (defined GPT_PIT_1_CH_12_ISR_USED) ||(defined GPT_PIT_1_CH_13_ISR_USED)||(defined GPT_PIT_1_CH_14_ISR_USED )||(defined GPT_PIT_1_CH_15_ISR_USED )   \
    )
/**
* @brief   Driver routine to process all the interrupts of PIT.
* @details Support function used by interrupt service routines to implement PIT specific operations
*          and call the GPT upper layer handler to implement non-hardware specific operations.
*
* @param[in]     u8ModuleIdx      hardware module index
* @param[in]     u8ChannelIdx     hardware channel index
*
* @implements   Gpt_Pit_ProcessCommonInterrupt_Activity
*/
static FUNC(void, GPT_CODE) Gpt_Pit_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint32,AUTOMATIC) u32Temp2;
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    /*Checks for spurious interrupts*/
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    u32Temp1 = REG_BIT_GET32(PIT_TFLG_ADDR32(u8ModuleIdx,u8ChannelIdx),PIT_TFLG_TIF_MASK_U32);
    
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    u32Temp2 = REG_BIT_GET32(PIT_TCTRL_LOCKABLE_ADDR32(u8ModuleIdx,u8ChannelIdx),PIT_TCTRL_TIE_MASK_U32);

    if ((PIT_TFLG_TIF_ON_U32 == u32Temp1) && (((uint32)PIT_TCTRL_TIE_ON_U32 << PIT_TCTRL_TIE_SHIFT) == u32Temp2))
    {
        /* Call GPT upper layer handler */
        Gpt_Ipw_ProcessCommonInterrupt(u8HwChannel, (uint8)GPT_PIT_MODULE);
    }

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_04();
    {
        /*Clear interrupt flag*/
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET32(PIT_TFLG_ADDR32(u8ModuleIdx,u8ChannelIdx), PIT_TFLG_TIF_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_04();
}
#endif
/*==================================================================================================
*                                      GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Gpt driver initialization function for Pit module.
* @details This function is called separately for each PIT hw channel corresponding to the configured
*          timer channels, and:
*          - enables the PIT module
*          - configures the freeze mode (enabled or disabled)
*          - disables the IRQ correpsonding to the PIT channel
*          - clears the (pending) interrupt flag corresponding to Pit channel
*          - disables the PIT timer channel
*          - clears the Load Value register correponding to the Pit channel.
*
*
* @param[in]     u8HwChannel        Pit hw channel ID
* @param[in]     bFreezeEnable     indicates if the Freeze mode is enabled
*
*
*/
FUNC(void, GPT_CODE) Gpt_Pit_Init(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(boolean, AUTOMATIC) bFreezeEnable)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8HwChannel);
    
#ifdef ERR_IPV_PIT_0002
  #if (ERR_IPV_PIT_0002 == STD_ON)
    /* Insert a minimum delay of two bus clocks to guarantee the write is not ignored */
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_RMW_LOCK32(PIT_BASE_ADDR32[u8ModuleIdx], PIT_MCR_LOCKABLE_ADDR32(u8ModuleIdx), (uint32)0UL, (uint32)0UL);
  #endif
#endif /*ERR_IPV_PIT_0002*/

    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    if((uint32)0 == (uint32)PIT_CHANNEL_INDEX_U32((uint32)u8ChannelIdx))
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx],PIT_MCR_LOCKABLE_ADDR32((uint32)u8ModuleIdx), PIT_MCR_MDIS_RTI_MASK_U32);
    }
    else
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_MCR_LOCKABLE_ADDR32((uint32)u8ModuleIdx), PIT_MCR_MDIS_MASK_U32);
    }

    /* Stop Channel to Configure Channel */
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TEN_MASK_U32);

    /* Disable interrupts*/
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TIE_MASK_U32);

    /* Clear pending interrupts */
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_BIT_SET32(PIT_TFLG_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx), PIT_TFLG_TIF_MASK_U32);

    /* Set Compare Value to 0 */
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_WRITE_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_LDVAL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), 0xFFFFFFFFU);

    if ((boolean)TRUE == bFreezeEnable)
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_MCR_LOCKABLE_ADDR32((uint32)u8ModuleIdx), PIT_MCR_FRZ_MASK_U32);
    }
    else
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_MCR_LOCKABLE_ADDR32((uint32)u8ModuleIdx), PIT_MCR_FRZ_MASK_U32);
    }
    
    return;
}

/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   Gpt driver de-initialization function for Pit module.
* @details This function is called separately for each PIT hw channel corresponding to the configured
*          timer channels, and:
*          - disables the PIT channel
*          - disables the freeze mode
*          - disables IRQ corresponding to Pit channel
*          - clears the (pending) interrupt flag corresponding to Pit channel
*
* @param[in]     u8HwChannel        Pit hw channel ID
*
*
*
*/
FUNC(void, GPT_CODE) Gpt_Pit_DeInit(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    /* Enable hardware module clock. This shall be be executed before any other setup is made */
    if((uint32)0 == (uint32)PIT_CHANNEL_INDEX_U32((uint32)u8ChannelIdx))
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_MCR_LOCKABLE_ADDR32((uint32)u8ModuleIdx), PIT_MCR_MDIS_RTI_MASK_U32);
    }
    else
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_MCR_LOCKABLE_ADDR32((uint32)u8ModuleIdx), PIT_MCR_MDIS_MASK_U32);
    }

    /* Reset Status and Control Register */
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TEN_MASK_U32);
    
    /* Disable channel interrupts*/
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TIE_MASK_U32);
    
    /* Clear Load Value Register */
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_WRITE_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_LDVAL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), 0UL);
    
    /* Clear Interrupt Flag */
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_BIT_SET32(PIT_TFLG_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), PIT_TFLG_TIF_MASK_U32);

    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_MCR_LOCKABLE_ADDR32((uint32)u8ModuleIdx), PIT_MCR_FRZ_MASK_U32);
    
    return;
}
#endif

/*================================================================================================*/
/**
* @brief   Gpt driver function for starting the Pit timer channel.
* @details This function:
*          - clears the (pending) interrupt flag corresponding to Pit channel
*          - disables the PIT timer channel
*          - sets the timeout value into the PIT timer channel register
*          - enables the PIT timer channel
*          - enables the IRQ corresponding to the PIT timer channel,if channel configured in One Shot mode.
*
* @param[in]     u8HwChannel        Pit hw channel ID
* @param[in]     u32Value          channel timeout value
* @param[in]     eChannelMode      One Shot or Continous
*
*
*/
FUNC(void, GPT_CODE) Gpt_Pit_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint32, AUTOMATIC) u32Value)
{
#ifdef GPT_PIT_RTI_USED
#if (GPT_PIT_RTI_USED == STD_ON)
    VAR(volatile uint32, AUTOMATIC) u32Timeout;
#endif
#endif
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_05();
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx],PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TEN_MASK_U32);
        
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_WRITE_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_LDVAL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), u32Value);
        
#ifdef GPT_PIT_RTI_USED
#if (GPT_PIT_RTI_USED == STD_ON)
    if (((uint8)PIT_0_CH_RTI == u8HwChannel) || ((uint8)PIT_1_CH_RTI == u8HwChannel))
    {
        u32Timeout = (uint32)GPT_TIMEOUT_COUNTER;

        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 MISRA 2004 Rule 11.3, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_7 MISRA 2004 Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'*/
        
        while ((u32Value != REG_READ32(PIT_LDVAL_LOCKABLE_ADDR32(u8ModuleIdx,u8ChannelIdx))) && (u32Timeout > 0UL))
        {
            u32Timeout--;
        }
        if (0UL == u32Timeout)
        {
        #if (GPT_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if((uint32)STD_ON == Gpt_E_TimeoutCfg.state)
            {
                /* Report production error and return from function. */
                Dem_ReportErrorStatus((Dem_EventIdType)Gpt_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            }
        #endif /* (GPT_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
        
            /** @violates @ref GPT_PIT_C_REF_8 MISRA 2004 Rule 14.7, Return statement before end of function */
            return;
        }
    }
#endif
#endif

        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET_LOCK32(PIT_BASE_ADDR32[((uint32)u8ModuleIdx)],PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TEN_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_05();
    
    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Pit timer channel.
* @details This function disables the PIT channel
*
* @param[in]     u8HwChannel        Pit hw channel ID
*
*
*/
FUNC(void, GPT_CODE) Gpt_Pit_StopTimer(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8HwChannel);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_06();
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx],PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TEN_MASK_U32);
        
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET32(PIT_TFLG_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx), PIT_TFLG_TIF_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_06();
    
    return;
}

/*================================================================================================*/

/**
* @brief   Gpt driver function for getting the time elapsed for an Pit timer channel.
* @details This function:
*          - reads the PIT channel load register
*          - reads the PIT counter register
*          - depending on above it calculates and returns the elapsed time
*          - reads and return the interrupt status flag value
*          - reads and return the current target time value
*
* @param[in]     u8HwChannel                Pit hw channel ID
* @param[out]    pbReturnChannelRollover    Interrupt status flag value
* @param[out]    pu32TargetValue            current target time value
*
* @return        Elapsed time since the last roll-over or start time.
*
*/
FUNC(uint32, GPT_CODE) Gpt_Pit_GetTimeElapsed(VAR(uint8, AUTOMATIC) u8HwChannel,
                                              P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
                                              P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
                                             )
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    VAR(uint32, AUTOMATIC)  u32ReturnValue;
    VAR(uint32, AUTOMATIC)  u32Flag;
    
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    *pu32TargetValue = REG_READ32(PIT_LDVAL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx));
    
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    u32ReturnValue = *pu32TargetValue - REG_READ32(PIT_CVAL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx));
    
    /*Check interrupt status flag*/
    /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
    u32Flag = (uint32)REG_BIT_GET32(PIT_TFLG_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), PIT_TFLG_TIF_MASK_U32);
    
    if (u32Flag != 0U)
    {
        /* Channel counter was roll-over */
        *pbReturnChannelRollover = (boolean)TRUE;
    }
    else
    {
        /* Channel counter was not roll-over */
        *pbReturnChannelRollover = (boolean)FALSE;
    }
    
    return u32ReturnValue;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for enabling the Pit timer channel IRQ.
* @details This function enables the IRQ corresponding to the Pit timer channel
*
* @param[in]     u8HwChannel        Pit hw channel ID
*
*
*/
FUNC(void, GPT_CODE) Gpt_Pit_EnableInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_07();
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET32(PIT_TFLG_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx), PIT_TFLG_TIF_MASK_U32);
        
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TIE_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_07();
    
    return;
}

/*================================================================================================*/
#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/**
* @brief   Gpt driver function for disabling the Pit timer channel IRQ.
* @details This function disables the IRQ corresponding to the Pit timer channel
*
* @param[in]     u8HwChannel        Pit hw channel ID
*
*
*/
FUNC(void, GPT_CODE) Gpt_Pit_DisableInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8HwChannel);
    VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8HwChannel);
    
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_08();
    {
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_CLEAR_LOCK32(PIT_BASE_ADDR32[(uint32)u8ModuleIdx], PIT_TCTRL_LOCKABLE_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx), (uint32)PIT_TCTRL_TIE_MASK_U32);
        
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        REG_BIT_SET32(PIT_TFLG_ADDR32((uint32)u8ModuleIdx,(uint32)u8ChannelIdx), PIT_TFLG_TIF_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_08();
}
#endif

#if (GPT_PIT_MODULE_SINGLE_INTERRUPT == STD_ON)
#ifdef GPT_PIT_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT_0 channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0 hw module.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_ISR)
{
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint8, AUTOMATIC) u8Channel;

    for (u8Channel = PIT_0_CH_0; u8Channel < ((uint8)PIT_0_CH_0 + (uint8)GPT_PIT_0_NUM_CHANNEL_U8); u8Channel++)
    {
        VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8Channel);
        VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8Channel);
        
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        u32Temp1 = REG_BIT_GET32(PIT_TFLG_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx),PIT_TFLG_TIF_MASK_U32);

        if (PIT_TFLG_TIF_ON_U32 == u32Temp1)
        {
            Gpt_Pit_ProcessCommonInterrupt(u8Channel);
        }
    }
    EXIT_INTERRUPT();
}
#endif
#ifdef GPT_PIT_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT_1 channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1 hw module.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_ISR)
{
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint8, AUTOMATIC) u8Channel;

    for (u8Channel = PIT_1_CH_0; u8Channel < ((uint8)PIT_1_CH_0 + (uint8)GPT_PIT_1_NUM_CHANNEL_U8); u8Channel++)
    {
        VAR(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)PIT_MODULE_INDEX_U32(u8Channel);
        VAR(uint8, AUTOMATIC) u8ChannelIdx = (uint8)PIT_CHANNEL_INDEX_U32(u8Channel);
        
        /** @violates @ref GPT_PIT_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_PIT_C_REF_6 Cast from unsigned long to pointer */
        u32Temp1 = REG_BIT_GET32(PIT_TFLG_ADDR32((uint32)u8ModuleIdx, (uint32)u8ChannelIdx),PIT_TFLG_TIF_MASK_U32);

        if (PIT_TFLG_TIF_ON_U32 == u32Temp1)
        {
            Gpt_Pit_ProcessCommonInterrupt(u8Channel);
        }
    }
    EXIT_INTERRUPT();
}
#endif
#else

#ifdef GPT_PIT_0_CH_RTI_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_RTI hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_RTI_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_RTI);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_0 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_0_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_0);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_1 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_1_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_1);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_2 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_2_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_2);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_3 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_3_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_3);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_4_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_4 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_4_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_4);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_5_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_5 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_5_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_5);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_6_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_6 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_6_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_6);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_7_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_7 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_7_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_7);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_8_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_8 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_8_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_8);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_9_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_9 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_9_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_9);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_10_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_10 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_10_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_10);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_11_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_11 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_11_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_11);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_12_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_12 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_12_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_12);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_13_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_13 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_13_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_13);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_14_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_14 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_14_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_14);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_0_CH_15_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_0_TIMER_15 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_0_TIMER_15_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_0_CH_15);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_RTI_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_RTI hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_RTI_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_RTI);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_0 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_0_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_0);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_1 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_1_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_1);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_2 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_2_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_2);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_3 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_3_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_3);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_4_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_4 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_4_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_4);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_5_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_5 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_5_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_5);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_6_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_6 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_6_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_6);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_7_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_7 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_7_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_7);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_8_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_8 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_8_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_8);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_9_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_9 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_9_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_9);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_10_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_10 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_10_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_10);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_11_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_11 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_11_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_11);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_12_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_12 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_12_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_12);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_13_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_13 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_13_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_13);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_14_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_14 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_14_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_14);

    EXIT_INTERRUPT();

}
#endif

#ifdef GPT_PIT_1_CH_15_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for PIT channels.
* @details Interrupt Service Routine corresponding to Gpt_PIT_1_TIMER_15 hw channel.
*
* @isr
* @violates @ref GPT_PIT_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_PIT_1_TIMER_15_ISR)
{
    Gpt_Pit_ProcessCommonInterrupt((uint8)PIT_1_CH_15);

    EXIT_INTERRUPT();

}
#endif

#endif /*GPT_PIT_MODULE_SINGLE_INTERRUPT == STD_ON*/

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_PIT_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_PIT_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif/*GPT_PIT_USED == STD_ON*/

#ifdef __cplusplus
}
#endif

/** @} */