/**
*   @file    Gpt_eMios.c
*   @implements    Gpt_eMios.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - Brief file description (one line).
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
* @section Gpt_eMios_C_REF_1
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
*
* @section Gpt_eMios_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file. This violation is not fixed
* since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Gpt_eMios_C_REF_3
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Gpt_eMios_C_REF_4
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
* @section Gpt_eMios_C_REF_5
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section Gpt_eMios_C_REF_6
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external
* identifiers.
*
* @section Gpt_eMios_C_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, Cast from unsigned long to pointer.
* The cast is used to address memory mapped registers or other hw resources.
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
#include "Gpt_eMios.h"
#include "eMios_Common.h"
#include "SchM_Gpt.h"

#define USER_MODE_REG_PROT_ENABLED (GPT_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_EMIOS_VENDOR_ID_C                       43
/** @violates @ref Gpt_eMios_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
/** @violates @ref Gpt_eMios_C_REF_6 This is required as per autosar Requirement */
#define GPT_EMIOS_AR_RELEASE_MAJOR_VERSION_C        4
/** @violates @ref Gpt_eMios_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
/** @violates @ref Gpt_eMios_C_REF_6 This is required as per autosar Requirement */
#define GPT_EMIOS_AR_RELEASE_MINOR_VERSION_C        2
/** @violates @ref Gpt_eMios_C_REF_4 Violates MISRA 2004 Required Rule 5.1, The long identifiers are maintained for better readability. */
/** @violates @ref Gpt_eMios_C_REF_6 This is required as per autosar Requirement */
#define GPT_EMIOS_AR_RELEASE_REVISION_VERSION_C     2
#define GPT_EMIOS_SW_MAJOR_VERSION_C                1
#define GPT_EMIOS_SW_MINOR_VERSION_C                0
#define GPT_EMIOS_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if header file and Std_Types.h file are of the same Autosar version */
    #if ((GPT_EMIOS_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_EMIOS_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_eMios.c and Std_Types.h are different"
    #endif
#endif

#if (GPT_EMIOS_VENDOR_ID_C != GPT_IPW_IRQ_VENDOR_ID)
    #error "Gpt_eMios.c and Gpt_Ipw_Irq.h have different vendor ids"
#endif
#if ((GPT_EMIOS_AR_RELEASE_MAJOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_AR_RELEASE_MINOR_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (GPT_EMIOS_AR_RELEASE_REVISION_VERSION_C != GPT_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios.c and Gpt_Ipw_Irq.h are different"
#endif
#if ((GPT_EMIOS_SW_MAJOR_VERSION_C != GPT_IPW_IRQ_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_SW_MINOR_VERSION_C != GPT_IPW_IRQ_SW_MINOR_VERSION) || \
     (GPT_EMIOS_SW_PATCH_VERSION_C != GPT_IPW_IRQ_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_eMios.c and Gpt_Ipw_Irq.h are different"
#endif

#if (GPT_EMIOS_VENDOR_ID_C != GPT_EMIOS_VENDOR_ID)
    #error "Gpt_eMios.c and Gpt_eMios.h have different vendor ids"
#endif
#if ((GPT_EMIOS_AR_RELEASE_MAJOR_VERSION_C != GPT_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_EMIOS_AR_RELEASE_MINOR_VERSION_C != GPT_EMIOS_AR_RELEASE_MINOR_VERSION) || \
     (GPT_EMIOS_AR_RELEASE_REVISION_VERSION_C != GPT_EMIOS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios.c and Gpt_eMios.h are different"
#endif
#if ((GPT_EMIOS_SW_MAJOR_VERSION_C != GPT_EMIOS_SW_MAJOR_VERSION) || \
     (GPT_EMIOS_SW_MINOR_VERSION_C != GPT_EMIOS_SW_MINOR_VERSION) || \
     (GPT_EMIOS_SW_PATCH_VERSION_C != GPT_EMIOS_SW_PATCH_VERSION) )
    #error "Software Version Numbers of Gpt_eMios.c and Gpt_eMios.h are different"
#endif

/* Check if source file and eMios_Common.h are of the same vendor */
#if (GPT_EMIOS_VENDOR_ID_C != EMIOS_COMMON_VENDOR_ID )
    #error "Gpt_eMios.c and eMios_Common.h have different vendor ids"
#endif

/* Check if source file and eMios_Common.h are of the same Autosar version */
#if ((GPT_EMIOS_AR_RELEASE_MAJOR_VERSION_C != EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION) || \
        (GPT_EMIOS_AR_RELEASE_MINOR_VERSION_C != EMIOS_COMMON_AR_RELEASE_MINOR_VERSION) || \
        (GPT_EMIOS_AR_RELEASE_REVISION_VERSION_C != EMIOS_COMMON_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Gpt_eMios.c and eMios_Common.h are different"
#endif

/* Check if source file and eMios_Common.h are of the same software version */
#if ((GPT_EMIOS_SW_MAJOR_VERSION_C != EMIOS_COMMON_SW_MAJOR_VERSION) || \
        (GPT_EMIOS_SW_MINOR_VERSION_C != EMIOS_COMMON_SW_MINOR_VERSION)  || \
        (GPT_EMIOS_SW_PATCH_VERSION_C != EMIOS_COMMON_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_eMios.c and eMios_Common.h are different"
#endif

/* Check if source file and SilRegMacros.h are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((GPT_EMIOS_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (GPT_EMIOS_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Gpt_eMios.c and SilRegMacros.h are different"
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
#define GPT_START_SEC_CODE
/** @violates @ref Gpt_eMios_C_REF_2 Repeated include file */
#include "Gpt_MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/**
* @brief   Gpt driver initialization function for Emios module.
* @details This function is called separately for each EMIOS hw channel corresponding to the configured
*          timer channels, and:
*         - disables the interrupt corresponding to Emios channel
*         - puts the Emios channel into GPIO mode
*         - sets the prescaler value
*         - enables/disables the Freeze Mode
*         - clears the (pending) interrupt flag corresponding to Emios channel
*         - resets the UC A register.
*
* @param[in]     bFreezeEnable    indicates if the Freeze mode is enabled
* @param[in]     u8Prescaler      prescaler value for the corresponding Emios channel
* @param[in]     u8HwChannel      Emios hw channel ID
*
* @return        void
*
*/
/** @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC(void, GPT_CODE) Gpt_eMios_Init (VAR(uint8, AUTOMATIC) u8HwChannel,
                                     VAR(uint8, AUTOMATIC) u8Prescaler,
                                     VAR(boolean, AUTOMATIC) bFreezeEnable
                                    )
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */
    VAR(uint32,AUTOMATIC) u32Temp;

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /* Only write UCDIS register if it_s available */
#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
    /* Enable eMIOS Channel */
    eMios_StartChannel(u8HwChannel);
    #endif
#endif  /* EMIOS_UCDIS_AVAILABLE */

    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx),CCR_FEN_MASK_U32);

    /* Stop Channel to Configure Channel */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), (CCR_MODE_MASK_U32|CCR_EDSEL_MASK_U32), (CCR_MODE_GPI_U32|CCR_EDSEL_MASK_U32));

    /* Save current emios channel param value in local variable */
    if ((boolean)TRUE == bFreezeEnable)
    {
        u32Temp = (((uint32)u8Prescaler<<CCR_UCPRE_SHIFT) | CCR_FREN_MASK_U32 | CCR_BSL_MASK_U32);
    }
    else
    {
        u32Temp = (((uint32)u8Prescaler<<CCR_UCPRE_SHIFT) | CCR_BSL_MASK_U32);
    }

    /* Initialize prescale value, channel filter, freeze enable, and bus select and disable the prescaler */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_RMW32 \
    ( \
        EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), \
        (CCR_FREN_MASK_U32|CCR_UCPRE_MASK_U32|CCR_UCPREN_MASK_U32|CCR_IF_MASK_U32|CCR_FCK_MASK_U32|CCR_BSL_MASK_U32), \
        ((u32Temp)&(CCR_FREN_MASK_U32|CCR_UCPRE_MASK_U32|CCR_UCPREN_MASK_U32|CCR_IF_MASK_U32|CCR_FCK_MASK_U32|CCR_BSL_MASK_U32)) \
     );

    /* Clear pending interrupts */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);

    /* Set Compare Value to 1 (writing 0 may lead to unpredictable result ) */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CADR_ADDR32(u8ModuleIdx, u8ChannelIdx), 1U);
}

#if (GPT_DEINIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief   Gpt driver de-initialization function for Emios module.
* @details This function is called separately for each EMIOS hw channel corresponding to the configured
*          timer channels, and:
*          - resets the Emios channel control register
*          - resets the UC A register.
*          - clears the (pending) interrupt flag corresponding to Emios channel
*
* @param[in]     u8HwChannel        Emios hw channel ID
*
*/
/** @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC(void, GPT_CODE) Gpt_eMios_DeInit (VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /* Reset Timer control register */
    /* Internal Counter is also cleared when entering GPIO Mode */
    /* This is applicable for the following lines of code */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), 0U);

    /* Set Compare Value to 1 (writing 0 may lead to unpredictable result ) */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CADR_ADDR32(u8ModuleIdx, u8ChannelIdx), 1U);

    /* Clear Interrupt Flag */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);

    /* Only write UCDIS register if it_s available */
#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
    /* Disable eMIOS Channel */
    eMios_StopChannel(u8HwChannel);
    #endif
#endif  /* EMIOS_UCDIS_AVAILABLE */
}
#endif /* GPT_DEINIT_API */


/*==================================================================================================*/
/**
* @brief   Gpt driver function for starting the Emios timer channel.
* @details This function:
*          - puts the Emios channel into GPIO mode
*          - enables the channel prescaler
*          - programs the UC A register with the value passed as input parameter
*          - sets the Emios channel mode to Modulus Counter Buffered (Up counter)
*          - enables the IRQ for the Emios channel, if channel configured in One Shot mode.
*
* @param[in]     u8HwChannel        Emios hw channel ID
* @param[in]     u32Value           channel timeout value
*
*/
/** @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC(void, GPT_CODE) Gpt_eMios_StartTimer (VAR(uint8, AUTOMATIC) u8HwChannel,
                                           VAR(uint32, AUTOMATIC) u32Value
                                          )
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */
#ifdef ERR_IPV_EMIOS_0001
#if STD_ON == ERR_IPV_EMIOS_0001
    VAR(uint32, AUTOMATIC) u32EnableInterrupt;  /**< @brief assigned FLAG Enable bit */
#endif
#endif
    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    
        
    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_14();
    {
#ifdef ERR_IPV_EMIOS_0001
#if STD_ON == ERR_IPV_EMIOS_0001
        /* Get FLAG interrupt enable bit */
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        u32EnableInterrupt = REG_BIT_GET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32);

        /* Disable Interrupt */
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32);
#endif
#endif
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), (CCR_MODE_MASK_U32|CCR_EDSEL_MASK_U32), (CCR_MODE_GPI_U32|CCR_EDSEL_MASK_U32));
        
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_UCPREN_MASK_U32);
   
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_WRITE32(EMIOS_CADR_ADDR32(u8ModuleIdx, u8ChannelIdx), u32Value);

        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_MODE_MASK_U32, CCR_MODE_MCB_INT_CLOCK_U32);
    
#ifdef ERR_IPV_EMIOS_0001
#if STD_ON == ERR_IPV_EMIOS_0001
        /* Clear Interrupt Flag */
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);
    
        /* Restore FLAG interrupt enable bit*/
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32, u32EnableInterrupt);
#endif
#endif
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_14();
}

/*==================================================================================================*/
/**
* @brief   Gpt driver function for stopping the Emios timer channel.
* @details This function puts the Emios channel into GPIO mode
*
* @param[in]     u8HwChannel        Emios hw channel ID
*
*/
/** @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC(void, GPT_CODE) Gpt_eMios_StopTimer (VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_15();
    {
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), (CCR_MODE_MASK_U32|CCR_EDSEL_MASK_U32), (CCR_MODE_GPI_U32|CCR_EDSEL_MASK_U32));
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_15();
    
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);
}

/*==================================================================================================*/
/**
* @brief   Gpt driver function for getting the time elapsed for an Emios timer channel.
* @details This function is called for reading the Emios channel counter register.
*
* @param[in]     u8HwChannel        Emios hw channel ID
* @param[out]    pbReturnChannelRollover    interrupt status flag value of the timer channel
* @param[out]    pu32TargetValue            current target time value
*
*/
/** @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC(uint32, GPT_CODE) Gpt_eMios_GetTimeElapsed (VAR(uint8, AUTOMATIC) u8HwChannel,
                                                 P2VAR(boolean, AUTOMATIC, GPT_APPL_DATA) pbReturnChannelRollover,
                                                 P2VAR(uint32, AUTOMATIC, GPT_APPL_DATA) pu32TargetValue
                                                )
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */
    VAR(uint32,AUTOMATIC) u32ReturnValue;

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /* Read the current target time before to read the elapsed time. */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    *pu32TargetValue = REG_READ32(EMIOS_CADR_ADDR32(u8ModuleIdx, u8ChannelIdx));

    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    u32ReturnValue = REG_READ32(EMIOS_CCNTR_ADDR32(u8ModuleIdx, u8ChannelIdx));

    /* Check for interrupt status flag */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    if (REG_READ32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx)) & (uint32)CSR_FLAG_MASK_U32)
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


/*==================================================================================================*/
/**
* @brief   Gpt driver function for enabling the Emios timer channel notifification/IRQ.
* @details This function:
*          - clears the (pending) interrupt flag corresponding to Emios channel
*          - enables the IRQ corresponding to the Emios channel
*
* @param[in]     u8HwChannel        Emios hw channel ID
*
*/
/** @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC(void, GPT_CODE) Gpt_eMios_EnableInterrupt (VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /* Clear interrupt flag */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_16();
    {
        /* Enable timer interrupt if it_s not already enabled */
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_16();
}

#if ((GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) || (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON))
/*==================================================================================================*/
/**
* @brief   Gpt driver function for disabling the Emios timer channel notifification/IRQ.
* @details This function disables the IRQ corresponding to the Emios channel
*
* @param[in]     u8HwChannel        Emios hw channel ID
*
*/
/** @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and definitions of Objects or Functions at File scope */
FUNC(void, GPT_CODE) Gpt_eMios_DisableInterrupt (VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    SchM_Enter_Gpt_GPT_EXCLUSIVE_AREA_17();
    {
        /* Disable timer interrupt */
        /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
        /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32);
    }
    SchM_Exit_Gpt_GPT_EXCLUSIVE_AREA_17();
    
    /* Clear interrupt flag */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);
}
#endif /* GPT_ENABLE_DISABLE_NOTIFICATION_API || GPT_WAKEUP_FUNCTIONALITY_API */

#if (GPT_SET_CLOCK_MODE == STD_ON)
/*==================================================================================================*/
/**
* @brief      The function changes the EMIOS channel prescaler value.
* @details    This function sets the EMIOS channel prescaler based on the input mode.
*
* @param[in]  u8ChPrescale     prescaler value for the corresponding Emios channel
* @param[in]  u8HwChannel      Emios hw channel ID
* @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and 
* definitions of Objects or Functions at File scope 
*/
FUNC (void, GPT_CODE) Gpt_eMios_SetClockMode(VAR(uint8, AUTOMATIC) u8HwChannel,
                                             VAR(uint8, AUTOMATIC) u8ChPrescale
                                            )
{
    VAR(uint32, AUTOMATIC) u32TempParam;
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /* Save current emios channel param value in local variable */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    u32TempParam = REG_READ32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx));
    u32TempParam &= ~((uint32)CCR_UCPRE_MASK_U32);
    u32TempParam |= ((((uint32)u8ChPrescale) << CCR_UCPRE_SHIFT) & (uint32)CCR_UCPRE_MASK_U32);

    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), u32TempParam);
}
#endif /* GPT_SET_CLOCK_MODE == STD_ON */

/*==================================================================================================*/
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/*==================================================================================================*/
/**
* @brief      The function start predef timer channel.
* @details    This function sets the EMIOS channel based on the input mode.
*
* @param[in]  u8ChPrescale     prescaler value for the corresponding Emios channel
* @param[in]  u8HwChannel      Emios hw channel ID
* @param[in]  bFreezeEnable    Freeze value for the corresponding Emios channel
* @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and 
* definitions of Objects or Functions at File scope 
*/
FUNC(void, GPT_CODE) Gpt_eMios_StartPredefTimer 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(uint8, AUTOMATIC) u8Prescaler,
    VAR(boolean, AUTOMATIC) bFreezeEnable
)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */
    VAR(uint32,AUTOMATIC) u32Temp;

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /* Only write UCDIS register if it_s available */
#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
    /* Enable eMIOS Channel */
    eMios_StartChannel(u8HwChannel);
    #endif
#endif  /* EMIOS_UCDIS_AVAILABLE */

    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx),CCR_FEN_MASK_U32);

    /* Stop Channel to Configure Channel */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), (CCR_MODE_MASK_U32|CCR_EDSEL_MASK_U32), (CCR_MODE_GPI_U32|CCR_EDSEL_MASK_U32));
    
    /* Clear counter*/
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CCNTR_ADDR32(u8ModuleIdx, u8ChannelIdx), 0U);
    
    /* Save current emios channel param value in local variable */
    if ((boolean)TRUE == bFreezeEnable)
    {
        u32Temp = (((uint32)u8Prescaler<<CCR_UCPRE_SHIFT) | CCR_FREN_MASK_U32 | CCR_BSL_MASK_U32);
    }
    else
    {
        u32Temp = (((uint32)u8Prescaler<<CCR_UCPRE_SHIFT) | CCR_BSL_MASK_U32);
    }

    /* Initialize prescale value, channel filter, freeze enable, and bus select and disable the prescaler */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_RMW32 \
    ( \
        EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), \
        (CCR_FREN_MASK_U32|CCR_UCPRE_MASK_U32|CCR_UCPREN_MASK_U32|CCR_IF_MASK_U32|CCR_FCK_MASK_U32|CCR_BSL_MASK_U32), \
        ((u32Temp)&(CCR_FREN_MASK_U32|CCR_UCPRE_MASK_U32|CCR_UCPREN_MASK_U32|CCR_IF_MASK_U32|CCR_FCK_MASK_U32|CCR_BSL_MASK_U32)) \
     );

    /* Clear pending interrupts */
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 MISRA 2004 Advisory Rule 11.3 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);
    
     /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 MISRA 2004 Advisory Rule 11.3 Cast from unsigned long to pointer */
    REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_UCPREN_MASK_U32);

    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 MISRA 2004 Advisory Rule 11.3 Cast from unsigned long to pointer */
    REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_MODE_MASK_U32, CCR_MODE_SAOC_U32);
}
/*==================================================================================================*/
/**
* @brief      The function get time elapsed of predef timer channel.
* @details    This function get time elapsed of the EMIOS channel.
*
* @param[in]  ePredefTimerType Types of predef timer
* @param[in]  u8HwChannel      Emios hw channel ID
* @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and 
* definitions of Objects or Functions at File scope 
*/
FUNC(uint32, GPT_CODE) Gpt_eMios_GetPredefTimerValue 
(
    VAR(uint8, AUTOMATIC) u8HwChannel,
    VAR(Gpt_PredefTimerType, AUTOMATIC) ePredefTimerType
)
{
    VAR(uint32, AUTOMATIC) u32CounterValue;
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    u32CounterValue = REG_READ32(EMIOS_CCNTR_ADDR32(u8ModuleIdx, u8ChannelIdx));
    
    switch(ePredefTimerType)
    {
        case GPT_PREDEF_TIMER_1US_16BIT:
            u32CounterValue = (0x0000FFFFU & u32CounterValue);
            break;
        case GPT_PREDEF_TIMER_1US_24BIT:
            u32CounterValue = (0x00FFFFFFU & u32CounterValue);
            break;
        default:
            /* 32bit timer */
            break;
    }   
  
    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    return u32CounterValue;
}
/*==================================================================================================*/
/**
* @brief      The function stop the predef timer channel.
* @details    This function stop the EMIOS channel.
*
* @param[in]  u8HwChannel      Emios hw channel ID
* @violates @ref Gpt_eMios_C_REF_5 Violates MISRA 2004 Required Rule 8.10, Declarations and 
* definitions of Objects or Functions at File scope 
*/
FUNC(void, GPT_CODE) Gpt_eMios_StopPredefTimer (VAR(uint8, AUTOMATIC) u8HwChannel)
{
    VAR(uint8, AUTOMATIC) u8ModuleIdx;   /**< @brief assigned eMios HW module  index */
    VAR(uint8, AUTOMATIC) u8ChannelIdx;  /**< @brief assigned eMios HW channel index */

    u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), (CCR_MODE_MASK_U32|CCR_EDSEL_MASK_U32), (CCR_MODE_GPI_U32|CCR_EDSEL_MASK_U32));

    /** @violates @ref Gpt_eMios_C_REF_1 Cast from unsigned long to pointer */
    /** @violates @ref Gpt_eMios_C_REF_7 Cast from unsigned long to pointer */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);
}
#endif
#define GPT_STOP_SEC_CODE
/** @violates @ref Gpt_eMios_C_REF_2 Repeated include file */
/** @violates @ref Gpt_eMios_C_REF_3 Declaration before #include */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
