/**
*   @file    Gpt_Stm.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - STM driver source file.
*   @details Containes the interface functions of the STM driver.
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
* @section GPT_STM_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include'. This is an Autosar requirement about
* the memory management.
*
* @section GPT_STM_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. All header files are
* protected against multiple inclusions.
*
* @section GPT_STM_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_STM_C_REF_4
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* The long names are maintained for better readability..
*
* @section GPT_STM_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required.
*
* @section GPT_STM_C_REF_6
* Violates MISRA 2004 Required Rule 8.1, Functions shall have prototype declarations and the
* prototype shall be visible at both the function definition and call.
*
* @section GPT_STM_C_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section GPT_STM_C_REF_8
* Violates MISRA 2004 Required Rule 9.2, Braces shall be used to indicate and match the structure in the 
* non-zero initialisation of arrays and structures. At here, we tend to initialized for whole structure, however, 
* when configure only 1 controller is configured, tool reported as non-zero initialisation. 
*
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Gpt_Ipw_Irq.h"
#include "Gpt_Stm.h"
#include "Reg_eSys_Stm.h"
#include "SchM_Gpt.h"

#define USER_MODE_REG_PROT_ENABLED (GPT_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define GPT_STM_VENDOR_ID_C                    43
/** @violates @ref GPT_STM_C_REF_4 MISRA 2004 Rule 1.4, Identifier clash */
#define GPT_STM_AR_RELEASE_MAJOR_VERSION_C     4
/** @violates @ref GPT_STM_C_REF_4 MISRA 2004 Rule 1.4, Identifier clash */
#define GPT_STM_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref GPT_STM_C_REF_4 MISRA 2004 Rule 1.4, Identifier clash */
#define GPT_STM_AR_RELEASE_REVISION_VERSION_C  2
#define GPT_STM_SW_MAJOR_VERSION_C             1
#define GPT_STM_SW_MINOR_VERSION_C             0
#define GPT_STM_SW_PATCH_VERSION_C             0
/** @} */
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_STM_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_STM_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Gpt_Stm.c and Std_Types.h are different"
    #endif

    /* Check if source file and SilRegMacros.h are of the same Autosar version */
    #if ((GPT_STM_AR_RELEASE_MAJOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_STM_AR_RELEASE_MINOR_VERSION_C    != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
         (GPT_STM_AR_RELEASE_REVISION_VERSION_C != SILREGMACROS_AR_RELEASE_REVISION_VERSION) \
        )
        #error "AutoSar Version Numbers of Gpt_Stm.c and SilRegMacros.h are different"
    #endif
#endif

#if (GPT_STM_VENDOR_ID_C != GPT_IPW_IRQ_VENDOR_ID)
    #error "Gpt_Stm.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Stm.c and Gpt_Ipw_Irq.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_STM_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_STM_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Stm.c and Gpt_Ipw_Irq.h are different"
#endif

#if (GPT_STM_VENDOR_ID_C != GPT_STM_VENDOR_ID)
    #error "Gpt_Stm.c and Gpt_Stm.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_AR_RELEASE_MAJOR_VERSION_C != GPT_STM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_AR_RELEASE_MINOR_VERSION_C != GPT_STM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_AR_RELEASE_REVISION_VERSION_C != GPT_STM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Stm.c and Gpt_Stm.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_SW_MAJOR_VERSION_C != GPT_STM_SW_MAJOR_VERSION) || \
     (GPT_STM_SW_MINOR_VERSION_C != GPT_STM_SW_MINOR_VERSION) || \
     (GPT_STM_SW_PATCH_VERSION_C != GPT_STM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Stm.c and Gpt_Stm.h are different"
#endif

#if (GPT_STM_VENDOR_ID_C != GPT_STM_TYPES_VENDOR_ID)
    #error "Gpt_Stm.c and Gpt_Stm_Types.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_AR_RELEASE_MAJOR_VERSION_C != GPT_STM_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_AR_RELEASE_MINOR_VERSION_C != GPT_STM_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_AR_RELEASE_REVISION_VERSION_C != GPT_STM_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Stm.c and Gpt_Stm_Types.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_SW_MAJOR_VERSION_C != GPT_STM_TYPES_SW_MAJOR_VERSION) || \
     (GPT_STM_SW_MINOR_VERSION_C != GPT_STM_TYPES_SW_MINOR_VERSION) || \
     (GPT_STM_SW_PATCH_VERSION_C != GPT_STM_TYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Stm.c and Gpt_Stm_Types.h are different"
#endif

#if (GPT_STM_VENDOR_ID_C != REG_ESYS_STM_VENDOR_ID)
    #error "Gpt_Stm.c and Reg_eSys_Stm.h have different vendor ids"
#endif
/* Check if header file and Gpt header file are of the same Autosar version */
#if ((GPT_STM_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_STM_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_STM_AR_RELEASE_MINOR_VERSION) || \
     (GPT_STM_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_STM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_Stm.c and Reg_eSys_Stm.h are different"
#endif
/* Check if source file and GPT header file are of the same Software version */
#if ((GPT_STM_SW_MAJOR_VERSION_C != REG_ESYS_STM_SW_MAJOR_VERSION) || \
     (GPT_STM_SW_MINOR_VERSION_C != REG_ESYS_STM_SW_MINOR_VERSION) || \
     (GPT_STM_SW_PATCH_VERSION_C != REG_ESYS_STM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Gpt_Stm.c and Reg_eSys_Stm.h are different"
#endif



/*==================================================================================================
*                                          LOCAL DEFINIES
==================================================================================================*/

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

#if (GPT_STM_USED == STD_ON)

/**
* @brief Number of counter cycles missed due to overflow
*/
#define STM_OVERFLOW_PAD_U32         ((uint32)1U)

/**
* @brief Highest possible value for STM channels
*/
#define STM_CNT_MAX_VALUE_U32        ((uint32)0xFFFFFFFFuL)

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

#define GPT_START_SEC_CONST_32
/** @violates @ref GPT_STM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_STM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @brief base address array for STM
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
CONST(uint32, GPT_CONST) STM_BASE_ADDR32[STM_MODULE_NUM_MAX_U8] =
{
#ifdef STM_0_BASEADDR
     STM_0_BASEADDR
#elif (defined(STM_1_BASEADDR) || defined(STM_2_BASEADDR))
    (uint32)(0x00000000UL)
#endif
#ifdef STM_1_BASEADDR
    ,STM_1_BASEADDR
#elif (defined(STM_2_BASEADDR))
    ,(uint32)(0x00000000UL)
#endif
#ifdef STM_2_BASEADDR
    ,STM_2_BASEADDR
#endif
};

#define GPT_STOP_SEC_CONST_32
/** @violates @ref GPT_STM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_STM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

#define GPT_START_SEC_VAR_INIT_32
/** @violates @ref GPT_STM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_STM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @brief          Global array variable used to store the runtime target time value.
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/** @violates @ref GPT_STM_C_REF_8 MISRA 2004 Rule 9.2, Braces shall be used to indicate and match the structure*/
VAR(uint32, GPT_VAR) Gpt_Stm_u32TargetValue[GPT_STM_MODULES_NUM_U8][GPT_STM_MODULE_CHAN_NUM_U8] = {{(uint32)0,(uint32)0}};

 #define GPT_STOP_SEC_VAR_INIT_32
/** @violates @ref GPT_STM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_STM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_STM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_STM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#if (GPT_STM_MODULE_SINGLE_INTERRUPT == STD_ON)

#ifdef GPT_STM_0_ISR_USED
ISR(Gpt_STM_0_ISR);
#endif

#ifdef GPT_STM_1_ISR_USED
ISR(Gpt_STM_1_ISR);
#endif

#ifdef GPT_STM_2_ISR_USED
ISR(Gpt_STM_2_ISR);
#endif

#else

#ifdef GPT_STM_0_CH_0_ISR_USED
ISR(Gpt_STM_0_Ch_0_ISR);
#endif

#if((defined GPT_STM_0_CH_1_ISR_USED) || (defined GPT_STM_ISR_1_SHARED))
ISR(Gpt_STM_0_Ch_1_ISR);
#endif

#ifdef GPT_STM_0_CH_2_ISR_USED
ISR(Gpt_STM_0_Ch_2_ISR);
#endif

#ifdef GPT_STM_0_CH_3_ISR_USED
ISR(Gpt_STM_0_Ch_3_ISR);
#endif
#ifdef GPT_STM_1_CH_0_ISR_USED
ISR(Gpt_STM_1_Ch_0_ISR);
#endif

#ifdef GPT_STM_1_CH_1_ISR_USED
ISR(Gpt_STM_1_Ch_1_ISR);
#endif

#ifdef GPT_STM_1_CH_2_ISR_USED
ISR(Gpt_STM_1_Ch_2_ISR);
#endif

#ifdef GPT_STM_1_CH_3_ISR_USED
ISR(Gpt_STM_1_Ch_3_ISR);
#endif
#ifdef GPT_STM_2_CH_0_ISR_USED
ISR(Gpt_STM_2_Ch_0_ISR);
#endif

#ifdef GPT_STM_2_CH_1_ISR_USED
ISR(Gpt_STM_2_Ch_1_ISR);
#endif

#ifdef GPT_STM_2_CH_2_ISR_USED
ISR(Gpt_STM_2_Ch_2_ISR);
#endif

#ifdef GPT_STM_2_CH_3_ISR_USED
ISR(Gpt_STM_2_Ch_3_ISR);
#endif

#endif /*GPT_STM_MODULE_SINGLE_INTERRUPT == STD_ON*/
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((defined GPT_STM_0_ISR_USED      ) ||(defined GPT_STM_1_ISR_USED      )||(defined GPT_STM_2_ISR_USED       )||(defined GPT_STM_ISR_1_SHARED     )|| \
     (defined GPT_STM_0_CH_0_ISR_USED ) ||(defined GPT_STM_0_CH_1_ISR_USED )||(defined GPT_STM_0_CH_2_ISR_USED  )||(defined GPT_STM_0_CH_3_ISR_USED  )|| \
     (defined GPT_STM_1_CH_0_ISR_USED ) ||(defined GPT_STM_1_CH_1_ISR_USED )||(defined GPT_STM_1_CH_2_ISR_USED  )||(defined GPT_STM_1_CH_3_ISR_USED  )|| \
     (defined GPT_STM_2_CH_0_ISR_USED ) ||(defined GPT_STM_2_CH_1_ISR_USED )||(defined GPT_STM_2_CH_2_ISR_USED  )||(defined GPT_STM_2_CH_3_ISR_USED  )   \
    )
/**
* @brief   Driver routine to process all the interrupts of STM.
* @details Support function used by interrupt service routines to implement STM specific operations
*          and call the GPT upper layer handler to implement non-hardware specific operations.
*
* @param[in]     u8HwChannel      hardware channel index
*
* @implements   Gpt_Stm_ProcessCommonInterrupt_Activity
* @violates @ref GPT_STM_C_REF_6 Functions shall have prototype declarations and
* the prototype shall be visible at both the function definition and call
*/

static FUNC(void, GPT_CODE) Gpt_Stm_ProcessCommonInterrupt(VAR(uint8, AUTOMATIC) u8HwChannel)\
{
    VAR(uint32, AUTOMATIC) u32OldCompare;
    VAR(uint32, AUTOMATIC) u32TargetTime;
    VAR(uint32,AUTOMATIC) u32Temp1;
    VAR(uint32,AUTOMATIC) u32Temp2;

    /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    u32Temp1 = REG_BIT_GET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32);
    /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    u32Temp2 = REG_BIT_GET32(STM_CCR_ADDR32((uint32)u8HwChannel), STM_CCR_CEN_MASK_U32);

    /*Check if interrupt status flag is set and if channel is enabled*/
    if((STM_CIR_CIF_SET_U32 == u32Temp1) && (STM_CCR_CEN_ENABLE_U32 == u32Temp2))
    {
        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        u32OldCompare = REG_READ32(STM_CMP_ADDR32((uint32)u8HwChannel));

        /*read the current target time value*/
        u32TargetTime = Gpt_Stm_u32TargetValue[STM_MODULE_INDEX_U32((uint32)u8HwChannel)][STM_CHANNEL_INDEX_U32((uint32)u8HwChannel)];

        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_WRITE32((STM_CMP_ADDR32((uint32)u8HwChannel)), ((uint32)(u32OldCompare + u32TargetTime)));

        /* Call GPT upper layer handler */
        Gpt_Ipw_ProcessCommonInterrupt(u8HwChannel,(uint8)GPT_STM_MODULE);

    }/*Check spurious interrupt*/
    
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_00();
    {
        /*Clear interrupt status flag*/
        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_BIT_SET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_00();
}
#endif

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief   Gpt driver initialization function for Stm module.
* @details This function is called separately for each STM hw channel corresponding to the configured
*          timer channels, and:
*          - sets the prescaler value
*          - configures the freeze mode (enabled/disabled)
*          - enables the STM counter
*          - disables the STM channel
*          - clears the (pending) interrupt flag corresponding to Stm channel
*          - clears the compare register correponding to the Stm channel.
*
* @param[in]     u8HwChannel            Stm hw channel ID
* @param[in]     u8Prescaler            STM prescaler value
* @param[in]     bFreezeEnable          indicates if the Freeze mode is enabled
*
*/
FUNC(void, GPT_CODE) Gpt_Stm_Init
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(uint8, AUTOMATIC) u8Prescaler,
#if defined(GPT_STM_ENABLECLOCKSWITCH)
  #if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
    VAR(uint8, AUTOMATIC) u8ClockSource,
  #endif
#endif
    VAR(boolean, AUTOMATIC) bFreezeEnable
)
{
    /* Timer Counter is enabled */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_SET32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_TEN_MASK_U32);

    /* STM channel disabled */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(STM_CCR_ADDR32((uint32)u8HwChannel), STM_CCR_CEN_MASK_U32);

    /* Clear interrupt request */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_SET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32);

    /* Set Compare Value to 0 */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_WRITE32(STM_CMP_ADDR32((uint32)u8HwChannel), (uint32)0U);
    
    /* Select Clock Source */
#if defined(GPT_STM_ENABLECLOCKSWITCH)
  #if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_RMW32(STM_CR_ADDR32(u8HwChannel), STM_CR_CSL_MASK_U32, (uint32)u8ClockSource << STM_CR_CSL_SHIFT);
  #endif
#endif

    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_RMW32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_CPS_MASK_U32, ((uint32)u8Prescaler << STM_CR_CPS_SHIFT));
    
    if ((boolean)TRUE == bFreezeEnable)
    {
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_BIT_SET32(STM_CR_ADDR32((uint32)u8HwChannel),STM_CR_FRZ_MASK_U32);
    }
    else
    {
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_BIT_CLEAR32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_FRZ_MASK_U32);
    }

    Gpt_Stm_u32TargetValue[STM_MODULE_INDEX_U32((uint32)u8HwChannel)][STM_CHANNEL_INDEX_U32((uint32)u8HwChannel)] = 0U;

    return;
}
/*================================================================================================*/
#if (GPT_DEINIT_API == STD_ON)
/**
* @brief   Gpt driver de-initialization function for Stm module.
* @details This function is called separately for each STM hw channel corresponding to the configured
*          timer channels, and:
*          - disables the STM counter
*          - resets the prescaler bits in the control register
*          - disables the STM channel
*          - clears the (pending) interrupt flag corresponding to Stm channel
*          - clears the compare register correponding to the Stm channel.
*
* @param[in]     u8HwChannel        Stm hw channel ID
*
* @pre     On/Off by the configuration parameter: GPT_DEINIT_API
*
*/
FUNC(void, GPT_CODE) Gpt_Stm_DeInit(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    /* Timer Counter is disabled */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_TEN_MASK_U32);
    
    /* Disable channel configured */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(STM_CCR_ADDR32((uint32)u8HwChannel), STM_CCR_CEN_MASK_U32);
    
    /* Clear Interrupt Flag */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_SET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32);
    
    /* Set Compare Value to 0 */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_WRITE32(STM_CMP_ADDR32((uint32)u8HwChannel), (uint32)0U);
    
    /* Reset Prescaler */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_RMW32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_CPS_MASK_U32, (uint32)0UL);

    Gpt_Stm_u32TargetValue[STM_MODULE_INDEX_U32((uint32)u8HwChannel)][STM_CHANNEL_INDEX_U32((uint32)u8HwChannel)] = 0U;

    return;
}
#endif

/*================================================================================================*/
/**
* @brief   Gpt driver function for starting the Stm timer channel.
* @details This function:
*          - reads the current counter register value and sets the compare register to the sum of
*            counter register value plus the timeout value
*          - enables the STM channel
*
* @param[in]     u8HwChannel        Stm hw channel ID
* @param[in]     u32Value          channel timeout value
*
*/
FUNC(void, GPT_CODE) Gpt_Stm_StartTimer(VAR(uint8, AUTOMATIC) u8HwChannel, VAR(uint32, AUTOMATIC) u32Value)
{
    VAR(uint32, AUTOMATIC) u32CounterValue;

    SuspendAllInterrupts();
    
    /* Configure channel compare register */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    u32CounterValue = REG_READ32(STM_CNT_ADDR32((uint32)u8HwChannel));
    
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_WRITE32(STM_CMP_ADDR32((uint32)u8HwChannel), ((uint32)(u32CounterValue + u32Value)));

    ResumeAllInterrupts();
    
    /*Store the target time value as a memory copy*/
    Gpt_Stm_u32TargetValue[STM_MODULE_INDEX_U32((uint32)u8HwChannel)][STM_CHANNEL_INDEX_U32((uint32)u8HwChannel)] = u32Value;

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_01();
    {
        /* Enable hardware channel */
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_BIT_SET32(STM_CCR_ADDR32((uint32)u8HwChannel), STM_CCR_CEN_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_01();
    /* For STM, there is no need to enable the corresponding timer channel IRQ, as there is no HW
       support for enabling/disabling the STM IRQ */

    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Stm timer channel.
* @details This function:
*          - disables the STM channel
*          - clears the (pending) interrupt flag corresponding to Stm channel
*
* @param[in]     u8HwChannel        Stm hw channel ID
*
*/
FUNC(void, GPT_CODE) Gpt_Stm_StopTimer(VAR(uint8, AUTOMATIC) u8HwChannel)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_02();
    {
        /* Disable hardware channel */
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_BIT_CLEAR32(STM_CCR_ADDR32((uint32)u8HwChannel), STM_CCR_CEN_MASK_U32);

        /* Clear interrupt status flag */
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_BIT_SET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_02();

    return;
}

/*================================================================================================*/
/**
* @brief   Gpt driver function for getting the time elapsed for an Stm timer channel.
* @details This function:
*          - reads the STM channel compare register
*          - reads the STM counter register
*          - depending on above and on channel timeout value it calculates and returns the elapsed
*            time
*
* @param[in]     u8HwChannel                Stm hw channel ID
* @param[out]    pbReturnChannelRollover    Interrupt status flag representing the timer rollover
* @param[out]    pu32TargetValue            current target time value
*
*/
FUNC(uint32, GPT_CODE) Gpt_Stm_GetTimeElapsed
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
    P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
)
{
    VAR(uint32, AUTOMATIC) u32ReturnValue;
    VAR(uint32, AUTOMATIC) u32CompareValue;
    VAR(uint32, AUTOMATIC) u32CounterValue;
    VAR(uint32, AUTOMATIC) u32TempValue;

    *pu32TargetValue = Gpt_Stm_u32TargetValue[STM_MODULE_INDEX_U32((uint32)u8HwChannel)][STM_CHANNEL_INDEX_U32((uint32)u8HwChannel)];

    /* Read compare and counter registers */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    u32CounterValue = REG_READ32(STM_CNT_ADDR32((uint32)u8HwChannel));
    
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    u32CompareValue = REG_READ32(STM_CMP_ADDR32((uint32)u8HwChannel));

    /* Calculate the elapsed time */
    if (u32CounterValue >= u32CompareValue)
    {
        u32TempValue = ((STM_CNT_MAX_VALUE_U32 - u32CounterValue) + u32CompareValue) + STM_OVERFLOW_PAD_U32;
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
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    if (STM_CIR_CIF_SET_U32 == REG_BIT_GET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32))
    {
        /* Channel counter was rollover */
        *pbReturnChannelRollover = (boolean)TRUE;
    }
    else
    {
        /* Channel counter was not rollover */
        *pbReturnChannelRollover = (boolean)FALSE;
    }
    return(u32ReturnValue);
}


#if (GPT_SET_CLOCK_MODE == STD_ON)
/*================================================================================================*/
/**
* @brief      The function changes the STM prescaler value.
* @details    This function sets the STM prescaler based on the input mode.
*
* @param[in]  u8hwChannel      hardware channel
* @param[in]  u8chPrescale     prescaler value
*
* @pre     On/Off by the configuration parameter: GPT_DUAL_CLOCK_MODE
*
*/
FUNC(void, GPT_CODE) Gpt_Stm_SetClockMode(VAR(uint8, AUTOMATIC) u8hwChannel, VAR(uint8, AUTOMATIC) u8chPrescale)
{
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_03();
    {
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_RMW32(STM_CR_ADDR32(u8hwChannel), STM_CR_CPS_MASK_U32, ((uint32)u8chPrescale << STM_CR_CPS_SHIFT));
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_03();
}
#endif
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/*================================================================================================*/
/**
* @brief      The function start the STM channel.
* @details    This function start the STM channel the input mode.
*
* @param[in]  u8hwChannel      hardware channel
* @param[in]  u8Prescaler      prescaler value
* @param[in]  bFreezeEnable    Freeze value
* @param[in]  u8ClockSource    clock source
*
*/
FUNC(void, GPT_CODE) Gpt_Stm_StartPredefTimer 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(uint8, AUTOMATIC) u8Prescaler,
#if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
    VAR(uint8, AUTOMATIC) u8ClockSource,
#endif
    VAR(boolean, AUTOMATIC) bFreezeEnable    
)
{
    /* STM channel disabled */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(STM_CCR_ADDR32((uint32)u8HwChannel), STM_CCR_CEN_MASK_U32);

    /* Clear interrupt request */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_SET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32);

    /* Set Compare Value to 0 */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_WRITE32(STM_CMP_ADDR32((uint32)u8HwChannel), (uint32)0U);
    
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    if(((uint32)STM_CR_TEN_MASK_U32) != (REG_READ32(STM_CR_ADDR32(u8HwChannel)) & STM_CR_TEN_MASK_U32))
    {
        /* clear counter */
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_WRITE32(STM_CNT_ADDR32((uint32)u8HwChannel),(uint32)0UL);

        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_RMW32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_CPS_MASK_U32, ((uint32)u8Prescaler << STM_CR_CPS_SHIFT));
        
        if ((boolean)TRUE == bFreezeEnable)
        {
            /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
            /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
            REG_BIT_SET32(STM_CR_ADDR32((uint32)u8HwChannel),STM_CR_FRZ_MASK_U32);
        }
        else
        {
            /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
            /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
            REG_BIT_CLEAR32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_FRZ_MASK_U32);
        }
        
         /* Timer Counter is enabled */
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
        REG_BIT_SET32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_TEN_MASK_U32);
    }
}
/*================================================================================================*/
/**
* @brief      The function get time elapsed of the STM channel.
* @details    This function get time elapsed of the STM channel.
*
* @param[in]  u8hwChannel      hardware channel
* @param[in]  ePredefTimerType  Types of predef timer
*
*/
FUNC(uint32, GPT_CODE) Gpt_Stm_GetPredefTimerValue 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimerType
)
{
    VAR(uint32, AUTOMATIC) u32ReturnValue;
    
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    u32ReturnValue = REG_READ32(STM_CNT_ADDR32((uint32)u8HwChannel));
    
    switch(ePredefTimerType)
    {
        case GPT_PREDEF_TIMER_1US_16BIT:
            u32ReturnValue = (0x0000FFFFU & u32ReturnValue);
        break;
        case GPT_PREDEF_TIMER_1US_24BIT:
            u32ReturnValue = (0x00FFFFFFU & u32ReturnValue);
        break;
        case GPT_PREDEF_TIMER_1US_32BIT:
        case GPT_PREDEF_TIMER_100US_32BIT:
        break;
        default:
            /* 32bit timer */
        break;
    } 
    
    return  u32ReturnValue;
}
/*================================================================================================*/
/**
* @brief      The function stop the STM channel.
* @details    This function stop the STM channel.
*
* @param[in]  u8hwChannel      hardware channel
*
*/
FUNC(void, GPT_CODE) Gpt_Stm_StopPredefTimer (VAR(uint8, AUTOMATIC) u8HwChannel)
{
    /* Timer Counter is disabled */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_TEN_MASK_U32);

    /* Disable channel configured */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_CLEAR32(STM_CCR_ADDR32((uint32)u8HwChannel), STM_CCR_CEN_MASK_U32);

    /* Clear Interrupt Flag */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_BIT_SET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32);

    /* Set Compare Value to 0 */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_WRITE32(STM_CMP_ADDR32((uint32)u8HwChannel), (uint32)0U);
    
    /* clear counter */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_WRITE32(STM_CNT_ADDR32((uint32)u8HwChannel), (uint32)0UL);
    
    /* Reset Prescaler */
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref GPT_STM_C_REF_7 Cast from unsigned long to pointer. */
    REG_RMW32(STM_CR_ADDR32((uint32)u8HwChannel), STM_CR_CPS_MASK_U32, (uint32)0UL);
    
}

#endif

#if (GPT_STM_MODULE_SINGLE_INTERRUPT == STD_ON)
#ifdef GPT_STM_0_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common Gpt_STM_0 module.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_0_ISR)
{
    VAR(uint32,AUTOMATIC) u32Temp;
    VAR(uint8, AUTOMATIC) u8ChannelIdx;
    VAR(uint8, AUTOMATIC) u8ModuleIdx = 0U;

    for (u8ChannelIdx = 0U; u8ChannelIdx < (uint8)GPT_STM_0_NUM_CHANNEL_U8; u8ChannelIdx++)
    {
        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        u32Temp = REG_BIT_GET32(STM_CIR_ADDR32((uint32)((uint32)(((uint32)u8ModuleIdx<<STM_MOD_SHIFT)) + u8ChannelIdx)), STM_CIR_CIF_MASK_U32);

        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        if (STM_CIR_CIF_SET_U32 == u32Temp)
        {
            Gpt_Stm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<STM_MOD_SHIFT) + u8ChannelIdx));
        }
    }
    EXIT_INTERRUPT();
}
#endif

#ifdef GPT_STM_1_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common Gpt_STM_1 module.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_1_ISR)
{
    VAR(uint32,AUTOMATIC) u32Temp;
    VAR(uint8, AUTOMATIC) u8ChannelIdx;
    VAR(uint8, AUTOMATIC) u8ModuleIdx = 1U;

    for (u8ChannelIdx = 0U; u8ChannelIdx < (uint8)GPT_STM_1_NUM_CHANNEL_U8; u8ChannelIdx++)
    {
        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        u32Temp = REG_BIT_GET32(STM_CIR_ADDR32((uint32)((uint32)((uint32)(u8ModuleIdx)<<STM_MOD_SHIFT) + u8ChannelIdx)), STM_CIR_CIF_MASK_U32);

        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        if (STM_CIR_CIF_SET_U32 == u32Temp)
        {
            Gpt_Stm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<STM_MOD_SHIFT) + u8ChannelIdx));
        }
    }
    EXIT_INTERRUPT();
}
#endif

#ifdef GPT_STM_2_ISR_USED
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to common Gpt_STM_2 module.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_2_ISR)
{
    VAR(uint32,AUTOMATIC) u32Temp;
    VAR(uint8, AUTOMATIC) u8ChannelIdx;
    VAR(uint8, AUTOMATIC) u8ModuleIdx = 2U;

    for (u8ChannelIdx = 0U; u8ChannelIdx < (uint8)GPT_STM_2_NUM_CHANNEL_U8; u8ChannelIdx++)
    {
        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        u32Temp = REG_BIT_GET32(STM_CIR_ADDR32((uint8)((uint8)(u8ModuleIdx<<STM_MOD_SHIFT) + u8ChannelIdx)), STM_CIR_CIF_MASK_U32);

        /** @violates @ref GPT_STM_C_REF_3 MISRA 2004 Rule 11.1, Cast from unsigned long to pointer*/
        if (STM_CIR_CIF_SET_U32 == u32Temp)
        {
            Gpt_Stm_ProcessCommonInterrupt((uint8)((uint8)(u8ModuleIdx<<STM_MOD_SHIFT) + u8ChannelIdx));
        }
    }
    EXIT_INTERRUPT();
}
#endif

#else

#ifdef GPT_STM_0_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_0_Ch_0 hw channel.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_0_Ch_0_ISR)
{

    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_0_CH_0);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_0_CH_0_ISR_USED */

#if((defined GPT_STM_0_CH_1_ISR_USED) || (defined GPT_STM_ISR_1_SHARED))
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_0_Ch_1 hw channel (or for shared ISR).
*
* @isr
*
* @note    On some platforms there is only one interrupt line shared for channels 1, 2 and 3.
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_0_Ch_1_ISR)
{
#ifndef GPT_STM_ISR_1_SHARED
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_0_CH_1);
#else
    VAR(uint8,  AUTOMATIC) u8HwChannel = 0U;
    VAR(uint32, AUTOMATIC) u32Temp1 = 0U;

    for(u8HwChannel = STM_0_CH_1; u8HwChannel <= STM_0_CH_3; u8HwChannel++)
    {
        /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
        u32Temp1 = REG_BIT_GET32(STM_CIR_ADDR32((uint32)u8HwChannel), STM_CIR_CIF_MASK_U32);
        if (STM_CIR_CIF_SET_U32 == u32Temp1)
        {
            Gpt_Stm_ProcessCommonInterrupt((uint8)u8HwChannel);
        }
    }
#endif
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_0_CH_1_ISR_USED */

#ifndef GPT_STM_ISR_1_SHARED
#ifdef GPT_STM_0_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_0_Ch_2 hw channel.
*
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_0_Ch_2_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_0_CH_2);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_0_CH_2_ISR_USED */

#ifdef GPT_STM_0_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_0_Ch_3 hw channel.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_0_Ch_3_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_0_CH_3);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_0_CH_3_ISR_USED */
#endif /* GPT_STM_ISR_1_SHARED */

#ifdef GPT_STM_1_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_1_Ch_0 hw channel.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_1_Ch_0_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_1_CH_0);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_1_CH_0_ISR_USED */

#ifdef GPT_STM_1_CH_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_1_Ch_1 hw channel (or for shared ISR).
*
* @isr
*
* @note    On some platforms there is only one interrupt line shared for channels 1, 2 and 3.
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_1_Ch_1_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_1_CH_1);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_1_CH_1_ISR_USED */

#ifdef GPT_STM_1_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_1_Ch_2 hw channel.
*
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_1_Ch_2_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_1_CH_2);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_1_CH_2_ISR_USED */

#ifdef GPT_STM_1_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_1_Ch_3 hw channel.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_1_Ch_3_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_1_CH_3);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_1_CH_3_ISR_USED */

#ifdef GPT_STM_2_CH_0_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_2_Ch_0 hw channel.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_2_Ch_0_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_2_CH_0);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_2_CH_0_ISR_USED */

#ifdef GPT_STM_2_CH_1_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_2_Ch_1 hw channel (or for shared ISR).
*
* @isr
*
* @note    On some platforms there is only one interrupt line shared for channels 1, 2 and 3.
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_2_Ch_1_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_2_CH_1);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_2_CH_1_ISR_USED */

#ifdef GPT_STM_2_CH_2_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_2_Ch_2 hw channel.
*
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_2_Ch_2_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_2_CH_2);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_2_CH_2_ISR_USED */

#ifdef GPT_STM_2_CH_3_ISR_USED
/*================================================================================================*/
/**
* @brief   Interrupt handler for STM channels.
* @details Interrupt Service Routine corresponding to Gpt_STM_2_Ch_3 hw channel.
*
* @isr
* @violates @ref GPT_STM_C_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Gpt_STM_2_Ch_3_ISR)
{
    Gpt_Stm_ProcessCommonInterrupt((uint8)STM_2_CH_3);
    /** @violates @ref GPT_STM_C_REF_3 Cast from unsigned long to pointer. */
    EXIT_INTERRUPT();
}
#endif /* GPT_STM_2_CH_3_ISR_USED */

#endif /*GPT_STM_MODULE_SINGLE_INTERRUPT == STD_ON*/

#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_STM_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_STM_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#endif /*GPT_STM_USED == STD_ON */

#ifdef __cplusplus
}
#endif

/** @} */