/**
*   @file    Adc_Adcdig_Irq.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - ADCDig Interrupt source file.
*   @details  Autosar Adc Interrupt source file.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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
all groups are without interrupt groups. All AdcInterrupt were not enabled.
---------------------------   ----------    ------------  ------------------------------------------
Nguyen Huy Cuong (B53917)     10/02/2017    MCAL-15093    [ADC] Resolve the compiler warnings
---------------------------   ----------    ------------  ------------------------------------------
'==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Adcdig_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Adcdig_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* There are different kinds of execution code sections.
*
* @section Adc_Adcdig_Irq_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and 
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section Adc_Adcdig_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section Adc_Adcdig_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*
* @section Adc_Adcdig_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 1.2, place reliance on undefined or unspecified behaviour
* This is used for the code complexity.
*
* @section Adc_Adcdig_Irq_c_REF_7
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Adcdig_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*
* @section Adc_Adcdig_Irq_c_REF_9
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware offset of the controller. The address calculated as an
* unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_Adcdig_Irq_c_REF_10
* Violates MISRA 2004 Required Rule 8.7,
* Objects shall be defined at block scope 
* if they are only accessed from within a single function.
*
* @section Adc_Adcdig_Irq_c_REF_11
* Violates MISRA 2004 Required Rule 10.1, cast from integer type to different type or a wider integer type
* This is used for the Speed optimization of the memory access.
*
* @section Adc_Adcdig_Irq_c_REF_12
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation occurs because of the interaction with MCL module / ISR symbols
* need to be exported .
*
* @section Adc_Adcdig_Irq_c_REF_13
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* This violation cannot be removed due to the interaction with MCL module.
*
* @section Adc_Adcdig_Irq_c_REF_14
* Violates MISRA 2004 Advisory Rule 11.4, cast from pointer to pointer. This is used for the Speed
* optimization of the memory access.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external Units
* 3) internal and external interfaces from this Unit
==================================================================================================*/
#include "Adc_Ipw.h"
#define USER_MODE_REG_PROT_ENABLED                (ADC_USER_MODE_REG_PROT_ENABLED)
#include "SilRegMacros.h"
#include "Adc_Adcdig_Irq.h"
#include "Mcal.h"
#include "SchM_Adc.h"
#ifdef ADC_DMA_SUPPORTED
  #include "CDD_Mcl.h"
#endif

#if (ADC_BCTU_AVAILABLE == STD_ON)
  #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON)
    #include "Adc_Reg_eSys_Bctu.h"
  #endif
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_ADCDIG_AR_VENDOR_ID_IRQ_C                 43
/**
* @violates @ref Adc_Adcdig_Irq_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_ADCDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C     4
/**
* @violates @ref Adc_Adcdig_Irq_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_ADCDIG_AR_RELEASE_MINOR_VERSION_IRQ_C     2
/**
* @violates @ref Adc_Adcdig_Irq_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_ADCDIG_AR_RELEASE_REVISION_VERSION_IRQ_C  2
#define ADC_ADCDIG_SW_MAJOR_VERSION_IRQ_C             1
#define ADC_ADCDIG_SW_MINOR_VERSION_IRQ_C             0
#define ADC_ADCDIG_SW_PATCH_VERSION_IRQ_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC IPW header file are from the same vendor */
#if (ADC_ADCDIG_AR_VENDOR_ID_IRQ_C != ADC_VENDOR_ID_IPW_H)
    #error "Adc_Adcdig_Irq.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if source file and ADC IPW header file are of the same Autosar version */
#if ((ADC_ADCDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (ADC_ADCDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (ADC_ADCDIG_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
    #error "AutoSar Version Numbers of Adc_Adcdig_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if source file and ADC IPW header file are of the same Software version */
#if ((ADC_ADCDIG_SW_MAJOR_VERSION_IRQ_C != ADC_SW_MAJOR_VERSION_IPW_H) || \
     (ADC_ADCDIG_SW_MINOR_VERSION_IRQ_C != ADC_SW_MINOR_VERSION_IPW_H) || \
     (ADC_ADCDIG_SW_PATCH_VERSION_IRQ_C != ADC_SW_PATCH_VERSION_IPW_H) \
    )
    #error "Software Version Numbers of Adc_Adcdig_Irq.c and Adc_Ipw.h are different"
#endif

#if (ADC_BCTU_AVAILABLE == STD_ON)
    #if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON)
        /* Check if source file and Adc_Reg_eSys_Bctu.h file are from the same vendor */
        #if (ADC_ADCDIG_AR_VENDOR_ID_IRQ_C != BCTU_REG_VENDOR_ID)
            #error "Adc_Adcdig_Irq.c and Adc_Reg_eSys_Bctu.h have different vendor ids"
        #endif
        
        /* Check if source file and Adc_Reg_eSys_Bctu.h file are of the same Autosar version */
        #if ((ADC_ADCDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != BCTU_REG_AR_RELEASE_MAJOR_VERSION) || \
            (ADC_ADCDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != BCTU_REG_AR_RELEASE_MINOR_VERSION) || \
            (ADC_ADCDIG_AR_RELEASE_REVISION_VERSION_IRQ_C != BCTU_REG_AR_RELEASE_REVISION_VERSION) \
            )
            #error "AutoSar Version Numbers of Adc_Adcdig_Irq.c and Adc_Reg_eSys_Bctu.h are different"
        #endif
        
        /* Check if source file and Adc_Reg_eSys_Bctu.h file are of the same Software version */
        #if ((ADC_ADCDIG_SW_MAJOR_VERSION_IRQ_C != BCTU_REG_SW_MAJOR_VERSION) || \
            (ADC_ADCDIG_SW_MINOR_VERSION_IRQ_C != BCTU_REG_SW_MINOR_VERSION) || \
            (ADC_ADCDIG_SW_PATCH_VERSION_IRQ_C != BCTU_REG_SW_PATCH_VERSION) \
            )
            #error "Software Version Numbers of Adc_Adcdig_Irq.c and Adc_Reg_eSys_Bctu.h are different"
        #endif
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((ADC_ADCDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_ADCDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adcdig_Irq.c and Mcal.h are different"
 #endif
 /* Check if source file and SilREgMacros header file are of the same AutoSar version */
 #if ((ADC_ADCDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_ADCDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adcdig_Irq.c and SilRegMacros.h are different"
 #endif

 #ifdef ADC_DMA_SUPPORTED
  /* Check if source file and DMA header file are of the same Autosar version */
  #if ((ADC_ADCDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
       (ADC_ADCDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != MCL_AR_RELEASE_MINOR_VERSION)  \
      )
      #error "AutoSar Version Numbers of Adc_Adcdig_Irq.c and CDD_Mcl.h are different"
  #endif
  /* Check if source file and Mcl_Types.h are of the same Autosar version */
  #if ((ADC_ADCDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCL_TYPES_AR_RELEASE_MAJOR_VERSION) || \
       (ADC_ADCDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != MCL_TYPES_AR_RELEASE_MINOR_VERSION)  \
      )
      #error "AutoSar Version Numbers of Adc_Adcdig_Irq.c and Mcl_Types.h are different"
  #endif
 #endif
#endif

/* Check if source file and Adc_Adcdig_Irq.h file are from the same vendor */
#if (ADC_ADCDIG_AR_VENDOR_ID_IRQ_C != ADC_VENDOR_ID_ADCDIG_IRQ)
    #error "Adc_Adcdig_Irq.c and Adc_Adcdig_Irq.h have different vendor ids"
#endif

/* Check if source file and Adc_Adcdig_Irq.h file are of the same Autosar version */
#if ((ADC_ADCDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_IRQ) || \
    (ADC_ADCDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_IRQ) || \
    (ADC_ADCDIG_AR_RELEASE_REVISION_VERSION_IRQ_C != ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_IRQ) \
    )
    #error "AutoSar Version Numbers of Adc_Adcdig_Irq.c and Adc_Adcdig_Irq.h are different"
#endif

/* Check if source file and Adc_Adcdig_Irq.h file are of the same Software version */
#if ((ADC_ADCDIG_SW_MAJOR_VERSION_IRQ_C != ADC_SW_MAJOR_VERSION_ADCDIG_IRQ) || \
    (ADC_ADCDIG_SW_MINOR_VERSION_IRQ_C != ADC_SW_MINOR_VERSION_ADCDIG_IRQ) || \
    (ADC_ADCDIG_SW_PATCH_VERSION_IRQ_C != ADC_SW_PATCH_VERSION_ADCDIG_IRQ) \
    )
    #error "Software Version Numbers of Adc_Adcdig_Irq.c and Adc_Adcdig_Irq.h are different"
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#if ((ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON) || (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING))
    #define ADC_DMA_SERQ_REG_ADDR32  ((uint32)0xFC0A0018UL)
#endif
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#ifdef ADC_DMA_SUPPORTED
#if ((ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON) || ((ADC_HW_TRIGGER_API == STD_ON) && (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)))
#define ADC_START_SEC_CONST_8
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/** @violates @ref Adc_Adcdig_Irq_c_REF_10 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
static CONST(uint8, ADC_CONST) Adc_Adcdig_aDmaChannels[] =
{
#if (ADC_MAX_HW_UNITS >= 1U)
    ADC_UNIT_0_ASSOCIATED_DMA_HW_CHANNEL
#endif
#if (ADC_MAX_HW_UNITS >= 2U)
    , ADC_UNIT_1_ASSOCIATED_DMA_HW_CHANNEL
#endif
#if (ADC_MAX_HW_UNITS >= 3U)
    , ADC_UNIT_2_ASSOCIATED_DMA_HW_CHANNEL
#endif
#if (ADC_MAX_HW_UNITS >= 4U)
    , ADC_UNIT_3_ASSOCIATED_DMA_HW_CHANNEL
#endif
};
#define ADC_STOP_SEC_CONST_8
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
#endif /* ((ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_ON) || ((ADC_HW_TRIGGER_API == STD_ON) && (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING))) */
#endif /* ADC_DMA_SUPPORTED */
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

#ifdef ADC_DMA_SUPPORTED
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/**
 * @brief The array to store the TCD configuration for each channel segment
 * @violates @ref Adc_Adcdig_Irq_c_REF_13  External object declared more than once
 */
extern VAR(Mcl_DmaTcdAttributesType, ADC_VAR) Adc_Adcdig_aDmaTcdConfig[ADC_MAX_HW_UNITS_CFG][ADC_MAX_CHANNEL_SEGMENTS_U8];

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

/**
* @violates @ref Adc_Adcdig_Irq_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
 * @brief          Internal buffer used by DMA to transfer blocks with gaps.
 * @violates @ref Adc_Adcdig_Irq_c_REF_8 internal linkage or external linkage
 * @violates @ref Adc_Adcdig_Irq_c_REF_13  External object declared more than once
 */
extern VAR(Adc_ValueGroupType,ADC_VAR) Adc_Adcdig_aDmaInternalResultBuffer[ADC_MAX_HW_UNITS_CFG];
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/**
 * @brief Declare the memory to store DMA TCD configuration for scatter gather node
 */
ALIGNED_VARS_START(ADC_CODE, ADCDIG_TCD_REG_SIZE_U8)
/** @violates @ref Adc_Adcdig_Irq_c_REF_13  External object declared more than once*/
extern VAR_ALIGN(VAR(Mcl_DmaTcdType, ADC_VAR) Adc_Adcdig_aDmaTcdConfigMem[ADC_MAX_HW_UNITS_CFG][ADC_MAX_CHANNEL_SEGMENTS_U8][ADCDIG_DMA_NUM_TCD_U8], ADCDIG_TCD_REG_SIZE_U8)
ALIGNED_VARS_STOP()

/**
* @violates @ref Adc_Adcdig_Irq_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
#endif /* ADC_DMA_SUPPORTED */

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/**
* @brief          Used to point the configuration structure.
*/
/** @violates @ref Adc_Adcdig_Irq_c_REF_13  External object declared more than once*/
extern P2CONST(Adc_ConfigType, ADC_VAR, ADC_APPL_CONST) Adc_pCfgPtr;

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/** @violates @ref Adc_Adcdig_Irq_c_REF_13  External object declared more than once*/
extern VAR(Adc_GroupStatusType, ADC_VAR) Adc_aGroupStatus[ADC_MAX_GROUPS];
/** @violates @ref Adc_Adcdig_Irq_c_REF_13  External object declared more than once*/
extern VAR(Adc_UnitStatusType , ADC_VAR) Adc_aUnitStatus[ADC_MAX_HW_UNITS];

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
/**
* @brief          This array is used to handle the MHT groups in
*                 an efficient manner through the driver code.
*/
/** @violates @ref Adc_Adcdig_Irq_c_REF_13  External object declared more than once*/
extern VAR(Adc_GroupType, ADC_VAR) Adc_Adcdig_aMhtChannelGroup[ADC_MAX_HW_UNITS_CFG][ADC_MAX_GROUPS_PER_HW_UNIT];
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#if ((ADC_BCTU_AVAILABLE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON))
#define ADC_START_SEC_VAR_INIT_BOOLEAN
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/** @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.*/
extern VAR(boolean, ADC_VAR) Adc_Adcdig_abAlreadyCleared[ADC_MAX_GROUPS];

#define ADC_STOP_SEC_VAR_INIT_BOOLEAN
/**
 * @violates @ref Adc_Adcdig_Irq_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON) */
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/** @violates @ref Adc_Adcdig_Irq_c_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) \
    )
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_EndGroupConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_EndSoftwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(boolean, AUTOMATIC) bInjectedFlag
);
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_CallExtraNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#ifdef ADC_WDG_SUPPORTED
#if ((defined(ADC_UNIT_0_WDG_ISR_USED)) || (defined(ADC_UNIT_1_WDG_ISR_USED)) || \
     (defined(ADC_UNIT_2_WDG_ISR_USED)) || (defined(ADC_UNIT_3_WDG_ISR_USED)) || \
     ((defined(ADC_WDG_GROUP_SHARED_ISR)) && ((defined(ADC_UNIT_0_ISR_USED)) || \
      (defined(ADC_UNIT_1_ISR_USED)) || (defined(ADC_UNIT_2_ISR_USED)) || \
      (defined(ADC_UNIT_3_ISR_USED)))) \
     )
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_WdgThresholdHandler
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_EndWdgInterrupt
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /*  defined(ADC_UNIT_0_WDG_ISR_USED)) || ....  */
#endif /* ADC_WDG_SUPPORTED */

#ifdef ADC_DMA_SUPPORTED
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_DmaEndNormalConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
);

#if(ADC_HW_TRIGGER_API == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_DmaEndHardwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_DmaEndGroupConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* ADC_DMA_SUPPORTED */

/*==================================================================================================
*                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) \
    )
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_CallExtraNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (Adc_pCfgPtr->pGroups[Group].ExtraNotification != NULL_PTR)
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_pCfgPtr->pGroups[Group].ExtraNotification();
    }
}
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
#endif /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) || \
     (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) \
    )
/**
* @brief @implements Adc_ADCDig_RecordResult_Activity */
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_RecordResult
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples
)
{
    VAR(Adc_ChannelIndexType, AUTOMATIC) Ch = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex = 0U;
    VAR(uint32, AUTOMATIC) u32CdrValue;
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
    VAR(Std_ReturnType, AUTOMATIC) ReturnValue = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32CdrMask = ADCDIG_CDR_DATA_MASK_U32;
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
    P2CONST(Adc_Adcdig_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr = Adc_pCfgPtr->pAdc;
    VAR(Adc_ChannelType, AUTOMATIC) Shift = 0U;
#endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */
#if ((ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) || (ADC_ENABLE_LIMIT_CHECK == STD_ON))
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
#endif /* ((ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) || (ADC_ENABLE_LIMIT_CHECK == STD_ON)) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /* Flag to set if ADC results are in the range selected */
    VAR(boolean,AUTOMATIC) bFlag = (boolean)TRUE;
    VAR(uint16, AUTOMATIC) u16CdrValueTemp;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;

    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pResult = Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + Adc_aGroupStatus[Group].ResultIndex;
#if ((ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) || (ADC_ENABLE_LIMIT_CHECK == STD_ON))
    /* Get the index of hardware Unit*/
    HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
#endif /* ((ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) || (ADC_ENABLE_LIMIT_CHECK == STD_ON)) */
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Shift = (16U - (pConfigPtr[HwIndex].Res));
    u32CdrMask = (uint32)(ADCDIG_CDR_DATA_MASK_U32 << Shift);
#endif
#if (ADC_SETCHANNEL_API == STD_ON)
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
#endif
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    for (Ch = 0U; Ch < ChannelCount; Ch++)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ChIndex = Adc_aRuntimeGroupChannel[Group].pChannel[Ch];
#else
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ChIndex = Adc_pCfgPtr->pGroups[Group].pAssignment[Ch];
#endif        
        /**
        * @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
        * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
        */
        u32CdrValue = REG_READ32(ADCDIG_CH_DATA_REG_ADDR32(Unit, (uint32)Adc_pCfgPtr->pChannels[Unit][ChIndex].ChId));

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if ((boolean)TRUE == Adc_ChannelsLimitCheckingCfg[HwIndex][ChIndex].bChannelLimitCheck)
        {
    #if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
            u16CdrValueTemp = (uint16)((u32CdrValue & ADCDIG_SHIFT_MASK_U32) >> Shift);
    #else
            u16CdrValueTemp = (uint16)(u32CdrValue & ADCDIG_CDR_DATA_MASK_U32);
    #endif /* ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT */
            bFlag = (boolean)Adc_CheckConversionValuesInRange(u16CdrValueTemp, Unit, ChIndex);
            if ((boolean)TRUE == bFlag)
            {
                /**
                * @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                */
                *(pResult+(Ch*(GroupSamples))) = (uint16)(u32CdrValue & u32CdrMask);
            }
            else
            {
                Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;
                /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
                return (Std_ReturnType)E_NOT_OK;
            }
        }
        else /* In case of bChannelLimitCheck = FALSE) */
        {
            /**
            * @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            */
            *(pResult+(Ch*(GroupSamples)))=(uint16)(u32CdrValue & u32CdrMask);
        }
#else
        /**
        * @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
        * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
        */
        *(pResult+(Ch*(GroupSamples))) = (uint16)(u32CdrValue & u32CdrMask);
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
    }
    return ReturnValue;
}
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) || \
     (defined(ADC_DMA_SUPPORTED)) || (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) \
    )
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
LOCAL_INLINE FUNC(boolean, ADC_CODE) Adc_Adcdig_CheckNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(boolean, AUTOMATIC) bCallNotification = (boolean) FALSE;

    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((ADC_NOTIFICATION_ENABLED == Adc_aGroupStatus[Group].eNotification) && \
        (NULL_PTR != Adc_pCfgPtr->pGroups[Group].Notification)
       )
    {
        bCallNotification = (boolean) TRUE;
    }
    return bCallNotification;
}
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) || \
     (defined(ADC_DMA_SUPPORTED)) \
     )

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_UpdateQueue
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
#if (ADC_ENABLE_QUEUING == STD_ON)
    Adc_RemoveFromQueue(Unit, 0U);
#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
    if (Adc_aUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
    {
        Adc_Adcdig_StartNormalConversion((Adc_HwUnitType)Unit);
    }
#endif
#else
    /* no element will be present in the queue */
    Adc_aUnitStatus[Unit].SwNormalQueueIndex= (Adc_QueueIndexType)0;
#endif /* ADC_ENABLE_QUEUING == STD_ON */
}
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) || \
     (defined(ADC_DMA_SUPPORTED)) \
     )
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_ClearValidBit
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChTemp;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndexTemp;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;

#if (ADC_SETCHANNEL_API == STD_ON)
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
#endif 
    
    /* Clear VALID bit from ADC result registers for all channels assigned to the group when
    conversion is aborted */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    for (ChTemp = 0U; ChTemp < ChannelCount; ChTemp++)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ChIndexTemp = Adc_aRuntimeGroupChannel[Group].pChannel[ChTemp];
#else
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ChIndexTemp = Adc_pCfgPtr->pGroups[Group].pAssignment[ChTemp];
#endif 
        /**
        * @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer
        * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
        */
        REG_READ32(ADCDIG_CH_DATA_REG_ADDR32(Unit, (uint32)Adc_pCfgPtr->pChannels[Unit][ChIndexTemp].ChId));
    }
}
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) \
    )
/**
* @brief @implements Adc_ADCDig_UpdateGroupState_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_UpdateGroupState
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples,
    VAR(boolean, AUTOMATIC) bInjectedFlag
)
{
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(boolean, AUTOMATIC)  bCallNotification = (boolean)FALSE;
#endif
    VAR(volatile uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
    VAR(uint32, AUTOMATIC) u32MsrStatus;

    /* At least once the group was converted */
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;

    if(ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
    }

    if (GroupSamples <= Adc_aGroupStatus[Group].ResultIndex)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((ADC_STREAM_BUFFER_LINEAR == Adc_pCfgPtr->pGroups[Group].eBufferMode) && \
           (ADC_ACCESS_MODE_STREAMING == Adc_pCfgPtr->pGroups[Group].eAccessMode)
          )
        {
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            u32MsrStatus = REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit)) & ADCDIG_NORMAL_CONV_STATUS_U32;
            /* the following code stop the conversion and abort the current group conversion,
                is important to abort the current, otherwise, another interrupt occurs after the stop */
            while(ADCDIG_NORMAL_CONV_ONGOING_U32 == u32MsrStatus)
            {
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_CONV_MASK_U32 | ADCDIG_ABORT_CHAIN_U32, ADCDIG_ABORT_CHAIN_U32);
                /* If the ongoing conversion is not aborted, report the production error */
                if (u32Timeout > 0UL)
                {
                    u32Timeout--;             
                }
                else
                {
                    /* Exit critical region */
                    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
                    return;
                }
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                u32MsrStatus = REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit)) & ADCDIG_NORMAL_CONV_STATUS_U32;
            }

            Adc_Adcdig_ClearValidBit(Unit, Group);

            /* Disable Interrupt Mask */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32);
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);

            Adc_Adcdig_UpdateQueue(Unit);

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
            bCallNotification = Adc_Adcdig_CheckNotification(Group);

            /* Exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();

            if ((boolean)TRUE == bCallNotification)
            {
                /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                Adc_pCfgPtr->pGroups[Group].Notification();
            }
#else
            /* Exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

            /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
        Adc_aGroupStatus[Group].ResultIndex = 0U;
    }

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    bCallNotification = Adc_Adcdig_CheckNotification(Group);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */

    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (ADC_CONV_MODE_ONESHOT == Adc_pCfgPtr->pGroups[Group].eMode)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;

        if((boolean)FALSE == bInjectedFlag)
        {
            /* Disable Interrupt Mask*/
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32);
            Adc_Adcdig_UpdateQueue(Unit);
        }
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)         
        else
        {
            /* Disable Interrupt*/
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_EN_U32);
            /* No element will be present in the sw inj queue */
            Adc_aUnitStatus[Unit].SwInjectedQueueIndex = 0U;
        }
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */        
    }

#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)   
    if((boolean)TRUE == bInjectedFlag)
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32);
    }
    else
 #endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */      
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
    }

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    if ((boolean)TRUE == bCallNotification)
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_pCfgPtr->pGroups[Group].Notification();
    }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
}
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) \
    )
/**
* @brief          This function handles the normal conversion ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_ADCDig_EndNormalConv_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_EndSoftwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(boolean, AUTOMATIC) bInjectedFlag
)
{
    VAR(Adc_GroupType, AUTOMATIC) Group = 0U;
    /* Streaming num samples should be at least 1U */
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples = 1U;
    VAR(Std_ReturnType, AUTOMATIC) Test = (Std_ReturnType) E_OK;
#if (ADC_SETCHANNEL_API == STD_ON)
    VAR(Adc_NCMRType, AUTOMATIC) CMRMask;
    VAR(uint32, AUTOMATIC) u32MsrStatus;
    VAR(volatile uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
#endif
    
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)      
    if ((boolean)TRUE == bInjectedFlag)
    {
        Group = Adc_aUnitStatus[Unit].SwInjectedQueue[0];
    }
    else
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */     
    {
        Group = Adc_aUnitStatus[Unit].SwNormalQueue[0];
    }
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    GroupSamples = Adc_pCfgPtr->pGroups[Group].NumSamples;
    Test = Adc_Adcdig_RecordResult(Unit, Group, GroupSamples);
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
    Adc_Adcdig_CallExtraNotification(Group);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
    
    /* Enter critical region */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_14();
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)      
    if ((boolean)TRUE == bInjectedFlag)
    {
#ifdef ADC_DMA_SUPPORTED
    #if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
        if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
        {
            if (Adc_aUnitStatus[Unit].SwNormalQueueIndex > (Adc_QueueIndexType)0U)
            {
                /* Restart normal conversion */
                Adc_Adcdig_StartNormalConversion((Adc_HwUnitType)Unit);
            }
        }
    #endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */
#endif /* ADC_DMA_SUPPORTED */
        if ((Std_ReturnType)E_NOT_OK == Test)
        {
            Adc_aGroupStatus[Group].ResultIndex = 0U;

            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
            /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
    }
    else
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */    
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        if ((boolean)TRUE == Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated) 
        {
            do
            {
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_CONV_MASK_U32 | ADCDIG_ABORT_CHAIN_U32, ADCDIG_ABORT_CHAIN_U32);
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
                if (u32Timeout > 0UL)
                {
                    u32Timeout--;        
                }
            }
            while(ADCDIG_NORMAL_CONV_ONGOING_U32 == u32MsrStatus);
            /** @violates @ref Adc_Adcdig_Irq_c_REF_6 It is needed for calculation value of go back space for source address.*/
            Adc_GetCMR_Register(Unit, Group, &CMRMask);
            Adc_Adcdig_SetNcmrRegisters(Unit, CMRMask.Adc_u32NCMR0, CMRMask.Adc_u32NCMR1, CMRMask.Adc_u32NCMR2);
            Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean) FALSE;
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_START_CONV_EN_U32);
        }
#endif
        if ((Std_ReturnType)E_NOT_OK == Test)
        {
            /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if (ADC_CONV_MODE_ONESHOT == Adc_pCfgPtr->pGroups[Group].eMode)
            {
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32);
            }
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
            Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)TRUE;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
            /* Exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_14();
            /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)FALSE;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

        /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
        Adc_aGroupStatus[Group].ResultIndex++;
    }
    Adc_Adcdig_UpdateGroupState(Unit, Group, GroupSamples, bInjectedFlag);
}

#if (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          This function handles the injected conversion ending.
* @details        When a HW injected conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_ADCDig_EndInjectedConv_Activity
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
FUNC(void, ADC_CODE) Adc_Adcdig_EndHardwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(boolean, AUTOMATIC) bInjectedFlag
)
{
    VAR(Adc_GroupType, AUTOMATIC) Group = 0U;
    /* Streaming num samples should be at least 1U */
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples = 1U;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(boolean, AUTOMATIC)  bCallNotification = (boolean) FALSE;
#endif
    VAR(Std_ReturnType, AUTOMATIC)  Test = (Std_ReturnType) E_OK;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = NULL_PTR;
#if (ADC_SETCHANNEL_API == STD_ON)
    VAR(Adc_NCMRType, AUTOMATIC) CMRMask;
#if ((ADC_BCTU_AVAILABLE == STD_ON)||(ADC_CTUV2_AVAILABLE == STD_ON))
    VAR(Adc_ChannelType, AUTOMATIC) ListChannelSorted[ADC_MAXIMUM_HW_CHANNELS] = {0U};
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;
#endif
#endif
    
    if((boolean)TRUE == bInjectedFlag)
    {
        Group = (Adc_aUnitStatus[Unit].HwInjectedQueue[0]);
    }
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    else
    {
        Group = (Adc_aUnitStatus[Unit].HwNormalQueue[0]);
    }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */

    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
    
    GroupSamples = pGroupPtr->NumSamples;
    Test = Adc_Adcdig_RecordResult(Unit, Group, GroupSamples);
#if (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON)
    Adc_Adcdig_CallExtraNotification(Group);
#endif /* (ADC_ENABLE_INITIAL_NOTIFICATION == STD_ON) */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_15();

    if ((Std_ReturnType)E_NOT_OK == Test)
    {
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();
        /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
        return;
    }

#if (ADC_SETCHANNEL_API == STD_ON)
    if ((boolean)TRUE == Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated) 
    {
#if (ADC_BCTU_AVAILABLE == STD_ON)
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if(pGroupPtr->pHwResource[0] < (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
        {
            /* Disable global trigger for all trigger input */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(BCTU_MCR_ADDR32, BCTU_GTRG_EN_U32);

            /* Remove list element and trigger source */
            Adc_BctuUpdateListAddress(pGroupPtr);
            
            ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
            
            for(ChIndex = (Adc_ChannelType)0; ChIndex < ChannelCount; ChIndex++)
            {
                /** @violates @ref Adc_Adcdig_Irq_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic */
                ListChannelSorted[ChIndex] = Adc_pCfgPtr->pChannels[Unit][Adc_aRuntimeGroupChannel[Group].pChannel[ChIndex]].ChId;
            }
            
            /* Sort list channels */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_6 It is needed to sort the channel list.*/
            Adc_BctuSortListChannels(ListChannelSorted, ChannelCount);
            
            /* Update new list element */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_6 It is needed to update the list of elements.*/
            Adc_BctuUpdateCurrentListElement(Group, ListChannelSorted, ChannelCount);
        }
        else
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
        {
            /** @violates @ref Adc_Adcdig_Irq_c_REF_6 It is needed for calculation value of go back space for source address.*/
            Adc_GetCMR_Register(Unit, Group, &CMRMask);  
            if((boolean)TRUE == bInjectedFlag)
            {   
                Adc_Adcdig_SetJcmrRegisters(Unit, CMRMask.Adc_u32NCMR0, CMRMask.Adc_u32NCMR1, CMRMask.Adc_u32NCMR2);
            }
        #if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
            else
            {
                Adc_Adcdig_SetNcmrRegisters(Unit, CMRMask.Adc_u32NCMR0, CMRMask.Adc_u32NCMR1, CMRMask.Adc_u32NCMR2);
            }
        #endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
          
        }
        Adc_aRuntimeGroupChannel[Group].bRuntimeUpdated = (boolean) FALSE;
    }
#endif

#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
    Adc_aGroupStatus[Group].ResultIndex++;
    /* At least once the group was converted */
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;
    if (ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
    }

    /* If all samples completed, wrap to 0 */
    if (Adc_aGroupStatus[Group].ResultIndex >= GroupSamples)
    {
        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
        if((ADC_STREAM_BUFFER_LINEAR == pGroupPtr->eBufferMode) && (ADC_ACCESS_MODE_STREAMING == pGroupPtr->eAccessMode))
        {
            /* Stop Conversion */
            if((boolean)TRUE == bInjectedFlag)
            {
#if ((ADC_BCTU_AVAILABLE == STD_ON)||(ADC_CTUV2_AVAILABLE == STD_ON))
                /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                if(pGroupPtr->pHwResource[0] < (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
                {
#if (ADC_BCTU_AVAILABLE == STD_ON)
                    if((boolean)FALSE == Adc_Adcdig_abAlreadyCleared[Group])
                    {
                        Adc_Adcdig_abAlreadyCleared[Group] = (boolean)TRUE;
                        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                        Adc_Bctu_DisableCtuTrigger(pGroupPtr, pGroupPtr->pHwResource[0], (boolean)TRUE);
                    }
#elif (ADC_CTUV2_AVAILABLE == STD_ON)
                    /* TODO: Implementation for CTU2 */
#endif /* ADC_BCTU_AVAILABLE == STD_ON */
                }
                else
#endif /* ((ADC_BCTU_AVAILABLE == STD_ON)||(ADC_CTUV2_AVAILABLE == STD_ON)) */
                {
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_INJ_EXT_TRIGGER_EN_U32);
                    /* Disable Interrupt Mask*/
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                    REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_MASK_U32);
                }
                Adc_aUnitStatus[Unit].HwInjectedQueueIndex = (Adc_QueueIndexType)0;
            }
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
            else
            {
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_EXT_TRIGGER_EN_U32);
                /* Disable Interrupt Mask*/
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32);
                Adc_aUnitStatus[Unit].HwNormalQueueIndex = (Adc_QueueIndexType)0;
            }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
            bCallNotification = Adc_Adcdig_CheckNotification(Group);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
            /* Exit critical region */
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
            if ((boolean) TRUE == bCallNotification)
            {
                pGroupPtr->Notification();
            }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
        Adc_aGroupStatus[Group].ResultIndex = 0U;
    }
#else 
    Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    bCallNotification = Adc_Adcdig_CheckNotification(Group);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_15();
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    if ((boolean) TRUE == bCallNotification)
    {
        pGroupPtr->Notification();
    }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
}
#endif /* ADC_HW_TRIGGER_API == STD_ON */
#endif /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#ifdef ADC_DMA_SUPPORTED
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_LimitCheckValueInRange
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
    VAR(Std_ReturnType, AUTOMATIC) ReadGroupRet = (Std_ReturnType)E_OK;
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResult = NULL_PTR;
    VAR(Adc_ValueGroupType, AUTOMATIC) ResultValue;
    VAR(Adc_ValueGroupType, AUTOMATIC) ResultTemp;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
    P2CONST(Adc_Adcdig_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr = Adc_pCfgPtr->pAdc;
#endif /* ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT */

#if (ADC_SETCHANNEL_API == STD_ON)
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChIndex = Adc_aRuntimeGroupChannel[Group].pChannel[0];
#else
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChIndex = Adc_pCfgPtr->pGroups[Group].pAssignment[0];
#endif 
    /* Get the index of hardware Unit*/
    HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if ((boolean)TRUE == Adc_ChannelsLimitCheckingCfg[HwIndex][ChIndex].bChannelLimitCheck)
    {
        /* Get the result from internal buffer */
        ResultValue = Adc_Adcdig_aDmaInternalResultBuffer[HwIndex];
        
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ResultTemp = (ResultValue >> (16U - pConfigPtr[HwIndex].Res));
#else
        ResultTemp = ResultValue;
#endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */

        if((boolean)FALSE == Adc_CheckConversionValuesInRange(ResultTemp, Unit, ChIndex))
        {
            Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)TRUE;
            ReadGroupRet = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Adc_aGroupStatus[Group].bLimitCheckFailed = (boolean)FALSE;
            /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pResult = Adc_pCfgPtr->pGroups[Group].pResultsBufferPtr[Group] + Adc_aGroupStatus[Group].ResultIndex;
            *pResult = ResultValue;
        }
    }
    return ReadGroupRet;
}
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_DmaCheckNotification
(
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(boolean, AUTOMATIC)  bCallNotification = (boolean) FALSE;
#endif

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    bCallNotification = Adc_Adcdig_CheckNotification(Group);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    if ((boolean) TRUE == bCallNotification)
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_pCfgPtr->pGroups[Group].Notification();
    }
#else
    (void)Group;
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
}
#endif

#if defined(ADC_DMA_SUPPORTED) || defined(__DOXYGEN__)
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_UpdateNextDestinationAddress
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) Index;
    VAR(uint32, AUTOMATIC) u32DesOff = 0UL;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) pTcdAddress = NULL_PTR;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroups = NULL_PTR;
    
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    pTcdAddress = (Mcl_DmaTcdType*)Mcl_DmaGetChannelTcdAddress(DmaChannel);
    if(Adc_aUnitStatus[Unit].NumSegment > 1U)
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 only Array indexing shall be allowed */
        pGroups = &(Adc_pCfgPtr->pGroups[Group]);
        /* Get the index of hardware Unit*/
        HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
        if(Adc_aGroupStatus[Group].ResultIndex < pGroups->NumSamples)
        {
            u32DesOff = (uint32)Adc_aGroupStatus[Group].ResultIndex << 1U;
        }
        for(Index = 0U; Index < Adc_aUnitStatus[Unit].NumSegment; Index++)
        {
            /* Re-Configure the destination address for TCD configuration memory to the next sample */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_14 cast from pointer to pointer */
            REG_WRITE32(&(Adc_Adcdig_aDmaTcdConfigMem[HwIndex][Index][4]), (Adc_Adcdig_aDmaTcdConfig[HwIndex][Index].u32daddr + u32DesOff));
        }
        Mcl_DmaConfigScatterGatherTcd(pTcdAddress, Adc_Adcdig_aDmaTcdConfig[HwIndex], Adc_Adcdig_aDmaTcdConfigMem[HwIndex][1]);
    }
#if (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF)
    Mcl_DmaTcdSetDaddr(pTcdAddress, (Adc_Adcdig_aDmaTcdConfig[HwIndex][0].u32daddr + u32DesOff)); 
#else
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE8(ADC_DMA_SERQ_REG_ADDR32, Adc_Adcdig_aDmaChannels[Unit]);
#endif /* (ADC_OPTIMIZE_ONESHOT_HW_TRIGGER == STD_OFF) */
}
/**
* @brief          This function handles the normal conversion via DMA ending.
* @details        When a normal (not injected) conversion ends, and the end of
*                 conversion DMA ISR is called, this function takes care about
*                 the driver and the module state transitions.
*
* @param[in]      Unit        the current HW Unit.
* @param[in]      Group       the handled group.
*
* @return         void
*
* @api
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_DmaEndNormalConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(volatile uint32, AUTOMATIC) u32Timeout;
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel;
    VAR(uint32, AUTOMATIC) u32MsrStatus;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr;
    
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;
    /* Get the DMA channel that is configured for this hardware unit */
    DmaChannel = (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit];
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
    
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if((Std_ReturnType)E_NOT_OK == Adc_Adcdig_LimitCheckValueInRange(Unit, Group))
    {
        if (ADC_CONV_MODE_ONESHOT == pGroupPtr->eMode)
        {
            Adc_Adcdig_ClearDmarRegisters(Unit);
            Adc_Adcdig_ClearValidBit(Unit, Group);
            /* Disable DMA interrupt */
            Mcl_DmaDisableHwRequest(DmaChannel);
        }
        else
        {
            /* Re-enable the DMA */
            Mcl_DmaEnableHwRequest(DmaChannel);
        }
        /* Exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
        /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
        return;
    }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    /* If continuous conversion */
    if(ADC_CONV_MODE_CONTINUOUS == pGroupPtr->eMode)
    {
        /* At least once the group was converted */
        if(ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
        {
            Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
        }
        /* Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed */
        Adc_aGroupStatus[Group].ResultIndex++;
        /* If all samples completed, wrap to 0 */
        if(Adc_aGroupStatus[Group].ResultIndex >= pGroupPtr->NumSamples)
        {
            Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;

            if(ADC_ACCESS_MODE_STREAMING == pGroupPtr->eAccessMode)
            {
                if(ADC_STREAM_BUFFER_LINEAR == pGroupPtr->eBufferMode)
                {
                    Adc_Adcdig_ClearDmarRegisters(Unit);
                    Adc_Adcdig_ClearValidBit(Unit, Group);
                    /* Disable DMA hardware request */
                    Mcl_DmaDisableHwRequest(DmaChannel);
                    /* The following code stop the conversion and abort the current group conversion,
                       is important to abort the current, otherwise, another interrupt occurs after the stop */
                    u32Timeout = ADC_TIMEOUT_COUNTER;
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                    u32MsrStatus = REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit)) & ADCDIG_NORMAL_CONV_STATUS_U32;
                    while(ADCDIG_NORMAL_CONV_ONGOING_U32 == u32MsrStatus)
                    {
                        /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                        /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                        REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_CONV_MASK_U32 | ADCDIG_ABORT_CHAIN_U32, ADCDIG_ABORT_CHAIN_U32);
                        /* If the ongoing conversion is not aborted, report the production error */
                        if (u32Timeout > 0UL)
                        {
                            u32Timeout--;                       
                        }
                        else
                        {
                            /* Exit critical region */
                            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
                            /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
                            return;
                        }
                        /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
                        /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                        u32MsrStatus = REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit)) & ADCDIG_NORMAL_CONV_STATUS_U32;
                    }
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                    REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_NORM_CONV_CLEAN_U32|ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
                    /* Update the internal queue */
                    Adc_Adcdig_UpdateQueue(Unit);
                    /* Call notification function if available */
                    Adc_Adcdig_DmaCheckNotification(Group);
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
                    return;
                }
                else
                {
                    /* Reset the destinition address for the first sample */
                    Adc_Adcdig_UpdateNextDestinationAddress(Unit, Group, DmaChannel);
                }
            }
            else
            {
                if(Adc_aUnitStatus[Unit].NumSegment > 1U) /* If NumSegment = 1, The reset destinition address will be load automatically */
                {
                    Adc_Adcdig_UpdateNextDestinationAddress(Unit, Group, DmaChannel);
                }
            }
            Adc_aGroupStatus[Group].ResultIndex = 0U;
        }
        else
        {
            if(Adc_aUnitStatus[Unit].NumSegment > 1U) /* If NumSegment = 1, The next destinition address will be load automatically */
            {
                /* Re-Configure the destinition address for the next sample */
                Adc_Adcdig_UpdateNextDestinationAddress(Unit, Group, DmaChannel);
            }
        }
        /* Call the call-back function if enabled */
        Adc_Adcdig_DmaCheckNotification(Group);
        Mcl_DmaEnableHwRequest(DmaChannel);
    }
    else
    {
        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
        
        Adc_Adcdig_ClearDmarRegisters(Unit);
        /* Disable DMA interrupt */
        Mcl_DmaDisableHwRequest(DmaChannel);
        /* Update the internal queue */
        Adc_Adcdig_UpdateQueue(Unit);
        /* Call the call-back function if enabled */
        Adc_Adcdig_DmaCheckNotification(Group);
    }
}
#endif /* defined(ADC_DMA_SUPPORTED) || defined(__DOXYGEN__) */

#ifdef ADC_DMA_SUPPORTED
#if(ADC_HW_TRIGGER_API == STD_ON)
/**
 * @brief   This function handles the Injected conversion via DMA ending.
 * @details When a Injected conversion ends, and the end of
 *          conversion DMA ISR is called, this function takes care about
 *          the driver and the module state.
 *
 * @param[in]   Unit        the current HW Unit.
 * @param[in]   Group       the handled group.
 *
 * @api
 */
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_DmaEndHardwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr;
    
    Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;
    /* Get the DMA channel that is configured for this hardware unit */
    DmaChannel = (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit];
    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
    
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    if((Std_ReturnType)E_NOT_OK == Adc_Adcdig_LimitCheckValueInRange(Unit, Group))
    {
        Mcl_DmaEnableHwRequest(DmaChannel);
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_13();
        /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
        return;
    }
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

    if(ADC_ACCESS_MODE_STREAMING == pGroupPtr->eAccessMode)
    {
        Adc_aGroupStatus[Group].ResultIndex++;
        /* at least once the group was converted */
        if (ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
        {
            Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
        }
        if(Adc_aGroupStatus[Group].ResultIndex >= pGroupPtr->NumSamples)
        {
            Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
            
            if (ADC_STREAM_BUFFER_LINEAR == pGroupPtr->eBufferMode)
            {
                Adc_Adcdig_ClearDmarRegisters(Unit);
                Adc_Adcdig_ClearValidBit(Unit, Group);
                Mcl_DmaDisableHwRequest(DmaChannel);
                /* The following code stop the conversion and abort the current group conversion,
                   is important to abort the current, otherwise, another interrupt occurs after the stop */
                if((Adc_GroupConvType)ADC_CONV_TYPE_INJECTED == pGroupPtr->eType)
                {
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_INJ_EXT_TRIGGER_EN_U32);
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                    REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_INJ_CONV_CLEAN_U32|ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32);    
                    /* Reset the internal queue */
                    Adc_aUnitStatus[Unit].HwInjectedQueueIndex = 0U;
                }
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
                else
                {
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_EXT_TRIGGER_EN_U32);
                     /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                     /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                    REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_NORM_CONV_CLEAN_U32|ADCDIG_ISR_END_CHAIN_NORM_CONV_CLEAN_U32);
                    /* Reset the internal queue */
                    Adc_aUnitStatus[Unit].HwNormalQueueIndex = 0U;
                }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */

                /* Call notification function if available */
                Adc_Adcdig_DmaCheckNotification(Group);
                /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
                return;
            }
            else
            {
                /* Reseting the destinition address for the first sample */
                Adc_Adcdig_UpdateNextDestinationAddress(Unit, Group, DmaChannel);
                Adc_aGroupStatus[Group].ResultIndex = 0U;
            }
        }
        else
        {
            if(Adc_aUnitStatus[Unit].NumSegment > 1U) /* If NumSegment = 1, The next destinition address will be load automatically */
            {
                /* Re-Configure the destinition address for the next sample */
                Adc_Adcdig_UpdateNextDestinationAddress(Unit, Group, DmaChannel);
            }
        }
    }
    else
    {
        Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
        if(Adc_aUnitStatus[Unit].NumSegment > 1U) /* If NumSegment = 1, The reset destinition address will be load automatically */
        {
            Adc_Adcdig_UpdateNextDestinationAddress(Unit, Group, DmaChannel);
        }
    }
    /* Call notification function if available */
    Adc_Adcdig_DmaCheckNotification(Group);
    /* Enable DMA hardware request */
    Mcl_DmaEnableHwRequest(DmaChannel);
}
#endif /* (ADC_HW_TRIGGER_API == STD_ON) || defined(__DOXYGEN__) */
#endif /* defined(ADC_DMA_SUPPORTED) || defined(__DOXYGEN__) */

#if ((defined(ADC_UNIT_0_WDG_ISR_USED)) || (defined(ADC_UNIT_1_WDG_ISR_USED)) || \
     (defined(ADC_UNIT_2_WDG_ISR_USED)) || (defined(ADC_UNIT_3_WDG_ISR_USED)) || \
     ((defined(ADC_WDG_GROUP_SHARED_ISR)) && \
      ((defined(ADC_UNIT_0_ISR_USED)) || \
       (defined(ADC_UNIT_1_ISR_USED)) || (defined(ADC_UNIT_2_ISR_USED)) || \
       (defined(ADC_UNIT_3_ISR_USED)) \
      ) \
     ) \
    )
#if defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function handles the watchdog interrupt.
* @details        This function handles the watchdog interrupt (clears the
*                 current channel interrupt, and calls the callback function
*                 (if defined).
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_ADCDig_EndWDGInterrupt_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_EndWdgInterrupt
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint32, AUTOMATIC) u32AworReg[3];
    VAR(uint32, AUTOMATIC) u32AworMasks[3] = {0UL, 0UL, 0UL};
    VAR(Adc_ChannelType, AUTOMATIC) Ch = 0U;
    VAR(uint8, AUTOMATIC) u8Index;
    VAR(uint32, AUTOMATIC) u32Mask;

    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32AworReg[0] = REG_READ32(ADCDIG_AWORR0_REG_ADDR32(Unit));

#if (ADC_AWORR1_AVAILABLE == STD_ON)
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32AworReg[1] = REG_READ32(ADCDIG_AWORR1_REG_ADDR32(Unit));
#endif /* (ADC_AWORR1_AVAILABLE == STD_ON) */

#if (ADC_AWORR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_AworrPresent[Unit][ADC_AWORR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32AworReg[2] = REG_READ32(ADCDIG_AWORR2_REG_ADDR32(Unit));
    }
#endif /* (ADC_AWORR2_AVAILABLE == STD_ON) */

    for (Ch = 0U; Ch < Adc_pCfgPtr->Misc.aAdc_Channels[Unit]; Ch++)
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (ADC_UNUSED_THRESHOLD_U8 != Adc_pCfgPtr->pChannels[Unit][Ch].u8ThReg)
        {
            /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            u8Index = Adc_pCfgPtr->pChannels[Unit][Ch].u8RegIndex;
            /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            u32Mask = Adc_pCfgPtr->pChannels[Unit][Ch].u32Mask;
            /* Check if watchdog triggered for current channel */
            if((uint32)u32Mask == (u32AworReg[u8Index] & (uint32)u32Mask))
            {
                /* Add channel mask to clear the register */
                u32AworMasks[u8Index] |= u32Mask;
                /* Call notification (if available) */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                if (Adc_pCfgPtr->pChannels[Unit][Ch].WdogNotification != NULL_PTR)
                {
                    /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                    Adc_pCfgPtr->pChannels[Unit][Ch].WdogNotification();
                }
            }
        }
    }

    /* Acknowledge all processed channels */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_AWORR0_REG_ADDR32(Unit), u32AworMasks[0]);

#if (ADC_AWORR1_AVAILABLE == STD_ON)
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_AWORR1_REG_ADDR32(Unit), u32AworMasks[1]);
#endif /* (ADC_AWORR1_AVAILABLE == STD_ON) */

#if (ADC_AWORR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_AworrPresent[Unit][ADC_AWORR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_AWORR2_REG_ADDR32(Unit), u32AworMasks[2]);
    }
#endif /* (ADC_AWORR2_AVAILABLE == STD_ON) */
}
#endif /* defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */
#endif /* defined(ADC_UNIT_0_WDG_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) \
    )
/**
* @brief          This function implements the ISR for the conversion.
* @details        The function implements the ISR for the given hardware Unit.
*                 It's used on both ADC Hardware Units.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_ADCDig_EndGroupConversion_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_EndGroupConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    VAR(volatile uint32, AUTOMATIC) u32IsrValue = (uint32)REG_READ32(ADCDIG_ISR_REG_ADDR32(Unit));
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    VAR(volatile uint32, AUTOMATIC) u32ImrValue = (uint32)REG_READ32(ADCDIG_IMR_REG_ADDR32(Unit));
    VAR(boolean, AUTOMATIC) bIsrSpurious = (boolean)TRUE;
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)    
    VAR(Adc_QueueIndexType, AUTOMATIC) SwInjectedQueueIndex;
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
    VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIndex;
#if (ADC_HW_TRIGGER_API == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) HwInjectedQueueIndex;
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) HwNormalQueueIndex;
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
#endif /* ADC_HW_TRIGGER_API == STD_ON */

    if(NULL_PTR != Adc_pCfgPtr)
    {
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)
        SwInjectedQueueIndex = Adc_aUnitStatus[Unit].SwInjectedQueueIndex;
        if ((ADCDIG_ISR_END_CHAIN_INJ_CONV_U32 == (u32IsrValue & ADCDIG_ISR_END_CHAIN_INJ_CONV_U32)) && \
            (SwInjectedQueueIndex > (Adc_QueueIndexType)0) \
           )
        {
            if (ADCDIG_ISR_END_CHAIN_INJ_CONV_MASK_U32 == (u32ImrValue & ADCDIG_ISR_END_CHAIN_INJ_CONV_MASK_U32))
            {
                Adc_Adcdig_EndSoftwareConv(Unit, (boolean)TRUE);
                /* To get again the right ISR status */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32);
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                u32IsrValue = REG_READ32(ADCDIG_ISR_REG_ADDR32(Unit));
            }
            else
            {
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32);
            }
            bIsrSpurious = (boolean)FALSE;
        }
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
        SwNormalQueueIndex = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
        if((ADCDIG_ISR_END_CHAIN_NORM_CONV_U32 == (u32IsrValue & ADCDIG_ISR_END_CHAIN_NORM_CONV_U32)) && \
           (SwNormalQueueIndex > (Adc_QueueIndexType)0) \
          )
        {
            if (ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32 == (u32ImrValue & ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32))
            {
                Adc_Adcdig_EndSoftwareConv(Unit, (boolean)FALSE);
            }
            else
            {
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
            }
            bIsrSpurious = (boolean)FALSE;
        }

#if (ADC_HW_TRIGGER_API == STD_ON)
        HwInjectedQueueIndex = Adc_aUnitStatus[Unit].HwInjectedQueueIndex;
        if ((ADCDIG_ISR_END_CHAIN_INJ_CONV_U32 == (u32IsrValue & ADCDIG_ISR_END_CHAIN_INJ_CONV_U32)) && \
            (HwInjectedQueueIndex > (Adc_QueueIndexType)0) \
           )
        {
            if (ADCDIG_ISR_END_CHAIN_INJ_CONV_MASK_U32 == (u32ImrValue & ADCDIG_ISR_END_CHAIN_INJ_CONV_MASK_U32))
            {
                Adc_Adcdig_EndHardwareConv(Unit, (boolean)TRUE);
            }
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32 | \
                                                     ADCDIG_ISR_END_CHANNEL_INJ_CONV_CLEAN_U32 \
                       );
            bIsrSpurious = (boolean)FALSE;
        }
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        HwNormalQueueIndex = Adc_aUnitStatus[Unit].HwNormalQueueIndex;
        if ((ADCDIG_ISR_END_CHAIN_NORM_CONV_U32 == (u32IsrValue & ADCDIG_ISR_END_CHAIN_NORM_CONV_U32)) && \
            (HwNormalQueueIndex > (Adc_QueueIndexType)0) \
           )
        {
            if (ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32 == (u32ImrValue & ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32))
            {
                Adc_Adcdig_EndHardwareConv(Unit, (boolean)FALSE);
            }
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32 | ADCDIG_ISR_END_CHANNEL_NORM_CONV_U32);
            bIsrSpurious = (boolean)FALSE;
        }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
#endif /* ADC_HW_TRIGGER_API == STD_ON */
    }
    if ((boolean)TRUE == bIsrSpurious)
    {
        /* Clear Interrupt status flags */
        /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), u32IsrValue);
    }
}
#endif  /* (defined(ADC_UNIT_0_ISR_USED) || ... */

#if ((defined(ADC_UNIT_0_WDG_ISR_USED)) || (defined(ADC_UNIT_1_WDG_ISR_USED)) || \
     (defined(ADC_UNIT_2_WDG_ISR_USED)) || (defined(ADC_UNIT_3_WDG_ISR_USED)) || \
     ((defined(ADC_WDG_GROUP_SHARED_ISR)) && ((defined(ADC_UNIT_0_ISR_USED)) || \
      (defined(ADC_UNIT_1_ISR_USED)) || (defined(ADC_UNIT_2_ISR_USED)) || \
      (defined(ADC_UNIT_3_ISR_USED)))) \
    )
#if defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function implements the ISR processing function for the
*                 Wdg interrupts.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements    Adc_ADCDig_WDGThresholdHandler_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_WdgThresholdHandler
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint32, AUTOMATIC) u32ActiveInterrupts = 0UL;
    VAR(uint32, AUTOMATIC) u32WtimrValue = 0UL;

    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32ActiveInterrupts = REG_READ32(ADCDIG_WTISR_REG_ADDR32(Unit));

    /* Read Watchdog Threshold Interrupt Mask Register */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32WtimrValue = REG_READ32(ADCDIG_WTIMR_REG_ADDR32(Unit));

    if(NULL_PTR != Adc_pCfgPtr)
    {
        if ((u32WtimrValue > 0UL) && (u32ActiveInterrupts > 0UL))
        {
            Adc_Adcdig_EndWdgInterrupt(Unit);
        }
    }

    /* Acknowledge all WDG irqs */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_WTISR_REG_ADDR32(Unit), u32ActiveInterrupts);
}
#endif /* defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */
#endif /* defined(ADC_UNIT_0_WDG_ISR_USED) || ... */

#if defined( ADC_DMA_SUPPORTED) || defined(__DOXYGEN__)
/**
* @brief          This function handles the ISR processing function for the
*                 DMA conversions.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_Adcdig_DmaEndGroupConversion_Activity
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_DmaEndGroupConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Adc_GroupType, AUTOMATIC) Group = 0U;
    /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    VAR(volatile uint32, AUTOMATIC) u32IsrValue = (uint32)REG_READ32(ADCDIG_ISR_REG_ADDR32(Unit));
    VAR(Adc_QueueIndexType, AUTOMATIC) SwNormalQueueIndex;
#if(ADC_HW_TRIGGER_API == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) HwInjectedQueueIndex;
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    VAR(Adc_QueueIndexType, AUTOMATIC) HwNormalQueueIndex;
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
    VAR(uint32, AUTOMATIC) u32IsrEndChain;
#if (ADC_BCTU_AVAILABLE == STD_ON)
    VAR(uint32, AUTOMATIC) u32IsrEndChannelCtu;
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) pTcdAddress = NULL_PTR;
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel;
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */


    if(NULL_PTR != Adc_pCfgPtr)
    {
        SwNormalQueueIndex = Adc_aUnitStatus[Unit].SwNormalQueueIndex;
#if(ADC_HW_TRIGGER_API == STD_ON)
        HwInjectedQueueIndex = Adc_aUnitStatus[Unit].HwInjectedQueueIndex;
  #if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        HwNormalQueueIndex = Adc_aUnitStatus[Unit].HwNormalQueueIndex;
  #endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
        u32IsrEndChain = u32IsrValue & ADCDIG_ISR_END_CHAIN_INJ_CONV_U32;
  #if (ADC_BCTU_AVAILABLE == STD_ON)
        u32IsrEndChannelCtu = u32IsrValue & ADCDIG_ISR_END_CHANNEL_CTU_CONV_U32;
  #endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
        if ((ADCDIG_ISR_END_CHAIN_NORM_CONV_U32 == (u32IsrValue & ADCDIG_ISR_END_CHAIN_NORM_CONV_U32)) && (SwNormalQueueIndex > 0U))
        {
            Group = Adc_aUnitStatus[Unit].SwNormalQueue[0];
            /* Enter critical region */
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13();
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_NORM_CONV_CLEAN_U32|ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
            Adc_Adcdig_DmaEndNormalConv(Unit, Group); 
        }
#if(ADC_HW_TRIGGER_API == STD_ON)
  #if (ADC_BCTU_AVAILABLE == STD_ON)
        else if(((ADCDIG_ISR_END_CHAIN_INJ_CONV_U32 == u32IsrEndChain) || (ADCDIG_ISR_END_CHANNEL_CTU_CONV_U32 == u32IsrEndChannelCtu)) && (HwInjectedQueueIndex > 0U))
  #else
        else if ((ADCDIG_ISR_END_CHAIN_INJ_CONV_U32 == u32IsrEndChain) && (HwInjectedQueueIndex > 0U))
  #endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
        {
            Group = Adc_aUnitStatus[Unit].HwInjectedQueue[0];

#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
            /** @violates @ref Adc_Adcdig_Irq_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic */
            if ((boolean) TRUE == Adc_pCfgPtr->pGroups[Group].bAdcDoubleBuffering)
            {
                DmaChannel = Adc_Adcdig_aDmaChannels[Unit];
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                pTcdAddress = (Mcl_DmaTcdType*)Mcl_DmaGetChannelTcdAddress(DmaChannel);
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13();
                /** @violates @ref Adc_Adcdig_Irq_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic */
                if(Adc_pCfgPtr->pGroups[Group].NumSamples == Mcl_DmaTcdGetIterCount(pTcdAddress))
                {
                    Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
                }
                else
                {
                    Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
                }
                Adc_Adcdig_DmaCheckNotification(Group);
            }
            else
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
            {
                /* Enter critical region */
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13();     
#if (ADC_BCTU_AVAILABLE == STD_ON)
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_CTU_CONV_CLEAN_U32|ADCDIG_ISR_END_CHANNEL_INJ_CONV_CLEAN_U32|ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32);
#else
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_INJ_CONV_CLEAN_U32|ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32);
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
                Adc_Adcdig_DmaEndHardwareConv(Unit, Group);
            }
        }
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
        else if ((ADCDIG_ISR_END_CHAIN_NORM_CONV_U32 == (u32IsrValue & ADCDIG_ISR_END_CHAIN_NORM_CONV_U32)) && (HwNormalQueueIndex > 0U))
        {
    #if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
            if ((boolean) TRUE == Adc_pCfgPtr->pGroups[Group].bAdcDoubleBuffering)
            {
                DmaChannel = Adc_Adcdig_aDmaChannels[Unit];
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                pTcdAddress = (Mcl_DmaTcdType*)Mcl_DmaGetChannelTcdAddress(DmaChannel);
                if(Adc_pCfgPtr->pGroups[Group].NumSamples == Mcl_DmaTcdGetIterCount(pTcdAddress))
                {
                    Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;
                }
                else
                {
                    Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
                }
                Adc_Adcdig_DmaCheckNotification(Group);
            }
            else
    #endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
            {
                Group = Adc_aUnitStatus[Unit].HwNormalQueue[0];
                /* Enter critical region */
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_13();
                /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_NORM_CONV_CLEAN_U32|ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
                Adc_Adcdig_DmaEndHardwareConv(Unit, Group);
            }
        }
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */
        else
        {
            /** @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), u32IsrValue);
        }
    }
}
#endif /* defined( ADC_DMA_SUPPORTED) || defined(__DOXYGEN__) */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
/**
* @brief          This function handles the end of a CTU conversion in the case
*                 of multiple hardware trigger.
* @details        When a CTU conversion ends, and the end of
*                 conversion ISR is called, this function takes care about the
*                 driver and the module state transitions.
*
* @param[in]      Unit        the current HW Unit.
*
* @return         void
*
* @api
* @implements     Adc_Adcdig_EndMultipleCtuConv_Activity
*/
FUNC(void, ADC_CODE) Adc_Adcdig_EndMultipleCtuConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32TrgSrc
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(Adc_GroupType, AUTOMATIC) Group = 0U;
    VAR(Std_ReturnType, AUTOMATIC) Test = (Std_ReturnType)E_NOT_OK;
    VAR(Adc_GroupType, AUTOMATIC) GrpIndex = 0U;
    /* Streaming num samples should be at least 1U */
    VAR(Adc_StreamNumSampleType, AUTOMATIC) GroupSamples = 1U;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = NULL_PTR;
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    VAR(boolean, AUTOMATIC) bCallNotification = (boolean) FALSE;
#endif

    if(NULL_PTR != Adc_pCfgPtr)
    {
        /* Get the index of hardware Unit*/
        HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
        /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        for(GrpIndex = 0U; GrpIndex < Adc_pCfgPtr->Misc.aAdc_HwQueueMaxDepth[Unit]; GrpIndex++)
        {
            Group = Adc_Adcdig_aMhtChannelGroup[HwIndex][GrpIndex];
            /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);

            /* check if the current channel is triggered or not... */
            /** @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if(u32TrgSrc == (uint32)pGroupPtr->pHwResource[0])
            {
                break;
            }
        }

        GroupSamples = pGroupPtr->NumSamples;
        /* enter critical region */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_17();

        Test = Adc_Adcdig_RecordResult(Unit, Group, GroupSamples);

        if((Std_ReturnType)E_NOT_OK == Test)
        {
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17();
            /** @violates @ref Adc_Adcdig_Irq_c_REF_4 Return statement before end of function. */
            return;
        }
        /*Increment ResultIndex with modulo 'NumSamples' to remember that another sample is completed*/
        Adc_aGroupStatus[Group].ResultIndex++;
        /* At least once the group was converted */
        Adc_aGroupStatus[Group].eAlreadyConverted = ADC_ALREADY_CONVERTED;

        if (ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
        {
            Adc_aGroupStatus[Group].eConversion = ADC_COMPLETED;
        }
        /* If all samples completed, wrap to 0 */
        if (Adc_aGroupStatus[Group].ResultIndex >= GroupSamples)
        {
            Adc_aGroupStatus[Group].eConversion = ADC_STREAM_COMPLETED;

            if((ADC_STREAM_BUFFER_LINEAR == pGroupPtr->eBufferMode) && \
               (ADC_ACCESS_MODE_STREAMING == pGroupPtr->eAccessMode)
              )
            {
                /* Stop Conversion */
                /**
                 * @violates @ref Adc_Adcdig_Irq_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                 * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer
                 * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type. 
                */
                Adc_Bctu_DisableInputTrigger(pGroupPtr->pHwResource[0]);

                Adc_aUnitStatus[Unit].HwInjectedQueueIndex--;
            }
            Adc_aGroupStatus[Group].ResultIndex = 0U;
        }
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        bCallNotification = Adc_Adcdig_CheckNotification(Group);
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
        /* Exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_17();
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        if ((boolean) TRUE == bCallNotification)
        {
            /* Call the notification function */
            pGroupPtr->Notification();
        }
#endif /* ADC_GRP_NOTIF_CAPABILITY == STD_ON */
    }
}
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

#ifdef ADC_UNIT_0_ISR_USED
/*==================================================================================================
                                          ADC HW UNIT 0
==================================================================================================*/
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware Unit 0.
* @details        The function implements the ISR for the ADC Hardware Unit 0.
*
* @return         void
*
* @isr
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
ISR(Adc_Adcdig_EndGroupConvUnit0)
{
#ifdef ADC_WDG_GROUP_SHARED_ISR
#ifdef ADC_WDG_SUPPORTED
    Adc_Adcdig_WdgThresholdHandler((Adc_HwUnitType)ADC_UNIT_0);
#endif
#endif /* ADC_WDG_GROUP_SHARED_ISR */
    Adc_Adcdig_EndGroupConversion((Adc_HwUnitType)ADC_UNIT_0);
    /**
    * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_Irq_c_REF_11 cast from int to a different type
    * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_0_ISR_USED */

#ifndef ADC_WDG_GROUP_SHARED_ISR
#if defined( ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
#ifdef ADC_UNIT_0_WDG_ISR_USED
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware Unit 0.
* @details        The function implements the ISR for the ADC Hardware Unit 0.
*
* @return         void
*
* @isr
*
* @note           This ISR is only defined if the ADC_WDG_SUPPORTED
*                 is enabled.
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
ISR(Adc_Adcdig_WatchDogThresholdUnit0)
{
    Adc_Adcdig_WdgThresholdHandler((Adc_HwUnitType)ADC_UNIT_0);
    /**
    * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_Irq_c_REF_11 cast from int to a different type
    * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_0_WDG_ISR_USED */
#endif /* defined( ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */
#endif /* ADC_WDG_GROUP_SHARED_ISR */

#if defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_0)
/**
* @brief          This function handles internal ADC updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the ADC Hardware Unit 0.
*
* @return         void
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
FUNC(void, ADC_CODE) Adc_Adcdig_DmaTransferComplete0()
{
    Adc_Adcdig_DmaEndGroupConversion((Adc_HwUnitType)ADC_UNIT_0);
}
#endif

#ifdef ADC_UNIT_1_ISR_USED
/*==================================================================================================
                                          ADC HW UNIT 1
==================================================================================================*/
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware Unit 1
* @details        The function implements the ISR for the ADC Hardware Unit 1.
*
* @return         void
*
* @isr
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
ISR(Adc_Adcdig_EndGroupConvUnit1)
{
#ifdef ADC_WDG_GROUP_SHARED_ISR
#ifdef ADC_WDG_SUPPORTED
    Adc_Adcdig_WdgThresholdHandler((Adc_HwUnitType)ADC_UNIT_1);
#endif
#endif /* ADC_WDG_GROUP_SHARED_ISR */
    Adc_Adcdig_EndGroupConversion((Adc_HwUnitType)ADC_UNIT_1);
    /**
    * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_Irq_c_REF_11 cast from int to a different type
    * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_1_ISR_USED */

#ifndef ADC_WDG_GROUP_SHARED_ISR
#if defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
#ifdef ADC_UNIT_1_WDG_ISR_USED
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware Unit 1.
* @details        The function implements the ISR for the ADC Hardware Unit 1.
*
* @return         void
*
* @isr
*
* @note           This ISR is only defined if the ADC_WDG_SUPPORTED
*                 is enabled.
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
* @violates @ref Adc_Adcdig_Irq_c_REF_7 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
ISR(Adc_Adcdig_WatchDogThresholdUnit1)
{
    Adc_Adcdig_WdgThresholdHandler((Adc_HwUnitType)ADC_UNIT_1);
    /**
    * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_Irq_c_REF_11 cast from int to a different type
    * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_1_WDG_ISR_USED */
#endif /* defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */
#endif /* ADC_WDG_GROUP_SHARED_ISR */

#if defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_1)
/**
* @brief          This function handles internal ADC updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the ADC Hardware Unit 1.
*
* @return         void
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
FUNC(void, ADC_CODE) Adc_Adcdig_DmaTransferComplete1()
{
    Adc_Adcdig_DmaEndGroupConversion((Adc_HwUnitType)ADC_UNIT_1);
}
#endif

#ifdef ADC_UNIT_2_ISR_USED
/*==================================================================================================
                                          ADC HW UNIT 2
==================================================================================================*/
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware Unit 2
* @details        The function implements the ISR for the ADC Hardware Unit 2.
*
* @return         void
*
* @isr
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
ISR(Adc_Adcdig_EndGroupConvUnit2)
{
#ifdef ADC_WDG_GROUP_SHARED_ISR
#ifdef ADC_WDG_SUPPORTED
    Adc_Adcdig_WdgThresholdHandler((Adc_HwUnitType)ADC_UNIT_2);
#endif
#endif /* ADC_WDG_GROUP_SHARED_ISR */
    Adc_Adcdig_EndGroupConversion((Adc_HwUnitType)ADC_UNIT_2);
    /**
    * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_Irq_c_REF_11 cast from int to a different type
    * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_2_ISR_USED  */

#ifndef ADC_WDG_GROUP_SHARED_ISR
#if defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
#ifdef ADC_UNIT_2_WDG_ISR_USED
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware Unit 2.
* @details        The function implements the ISR for the ADC Hardware Unit 2.
*
* @return         void
*
* @isr
*
* @note           This ISR is only defined if the ADC_WDG_SUPPORTED
*                 is enabled.
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
ISR(Adc_Adcdig_WatchDogThresholdUnit2)
{
    Adc_Adcdig_WdgThresholdHandler((Adc_HwUnitType)ADC_UNIT_2);
    /**
    * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_Irq_c_REF_11 cast from int to a different type
    * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_2_WDG_ISR_USED */
#endif /* defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */
#endif /* ADC_WDG_GROUP_SHARED_ISR */

#if defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_2)
/**
* @brief          This function handles internal ADC updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the ADC Hardware Unit 2.
*
* @return         void
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
FUNC(void, ADC_CODE) Adc_Adcdig_DmaTransferComplete2()
{
    Adc_Adcdig_DmaEndGroupConversion((Adc_HwUnitType)ADC_UNIT_2);
}
#endif


#ifdef ADC_UNIT_3_ISR_USED
/*==================================================================================================
                                          ADC HW UNIT 3
==================================================================================================*/
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware Unit 3
* @details        The function implements the ISR for the ADC Hardware Unit 3.
*
* @return         void
*
* @isr
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
ISR(Adc_Adcdig_EndGroupConvUnit3)
{
#ifdef ADC_WDG_GROUP_SHARED_ISR
#ifdef ADC_WDG_SUPPORTED
    Adc_Adcdig_WdgThresholdHandler((Adc_HwUnitType)ADC_UNIT_3);
#endif
#endif /* ADC_WDG_GROUP_SHARED_ISR */
    Adc_Adcdig_EndGroupConversion((Adc_HwUnitType)ADC_UNIT_3);
    /**
    * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_Irq_c_REF_11 cast from int to a different type
    * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif /*  ADC_UNIT_3_ISR_USED */

#ifndef ADC_WDG_GROUP_SHARED_ISR
#if defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__)
#ifdef ADC_UNIT_3_WDG_ISR_USED
/**
* @brief          This function implements the ISR for the conversion done of
*                 the ADC Hardware Unit 3.
* @details        The function implements the ISR for the ADC Hardware Unit 3.
*
* @return         void
*
* @isr
*
* @note           This ISR is only defined if the ADC_WDG_SUPPORTED
*                 is enabled.
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
ISR(Adc_Adcdig_WatchDogThresholdUnit3)
{
    Adc_Adcdig_WdgThresholdHandler((Adc_HwUnitType)ADC_UNIT_3);
    /**
    * @violates @ref Adc_Adcdig_Irq_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_Irq_c_REF_11 cast from int to a different type
    * @violates @ref Adc_Adcdig_Irq_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    EXIT_INTERRUPT();
}
#endif /* ADC_UNIT_3_WDG_ISR_USED */
#endif /* defined(ADC_WDG_SUPPORTED) || defined(__DOXYGEN__) */
#endif /* ADC_WDG_GROUP_SHARED_ISR */

#if defined(ADC_DMA_SUPPORTED) && defined(ADC_UNIT_3)
/**
* @brief          This function handles internal ADC updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the ADC Hardware Unit 3.
*
* @return         void
* @violates @ref Adc_Adcdig_Irq_c_REF_12 internal linkage vs external linkage.
*/
FUNC(void, ADC_CODE) Adc_Adcdig_DmaTransferComplete3()
{
    Adc_Adcdig_DmaEndGroupConversion((Adc_HwUnitType)ADC_UNIT_3);
}
#endif

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_Adcdig_Irq_c_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Adcdig_Irq_c_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif


/** @} */
