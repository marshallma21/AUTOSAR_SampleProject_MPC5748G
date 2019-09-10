/**
*   @file    eMios_Common.c
*   @implements    eMios_Common.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eDMA
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
* @section eMios_Common_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include" MemMap.h included after each section define in order to set the current memory section
*
* @section eMios_Common_c_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section eMios_Common_c_3
* Violates MISRA 2004 Required Rule 11.1, Conversion shall not be performed between a pointer to a function
* and any type other than an integral type
*
* @section eMios_Common_c_4
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* The long names are maintained for better readability.
*
* @section eMios_Common_c_5
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
*@section eMios_Common_c_6
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section eMios_Common_c_7
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic. This violation is due to the use of pointer arithematic, to access the channel
* parameters, the indexing of the pointer is taken care and hence the unintended memory location
* will not be accessed.
*
* @section eMios_Common_c_8
* Violates MISRA 2004 Required Rule 12.4, side effects on right hand of logical operator: '||'
* This violation  is not fixed since  the functions execution is not mandatory, both left hand and
* right hand side of logical operator && are checking some status values
*/


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           eMios_Common.c
*/
#include "modules.h"
#if ((USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON) || (USE_PWM_MODULE==STD_ON))
/** @violates @ref eMios_Common_c_2 Precautions shall be taken in order to prevent...*/
#include "Std_Types.h"
#include "eMios_Common_Types.h"
#include "eMios_Common.h"

#if (USE_GPT_MODULE==STD_ON)
#include "Gpt_eMios_Irq.h"
#endif

#if (USE_ICU_MODULE==STD_ON)
#include "Icu_Cfg.h"
#include "Icu_eMios_Irq.h"
#endif

#if (USE_PWM_MODULE==STD_ON)
#include "Pwm_Ipw_Types.h"
#include "Pwm_eMios.h"
#endif

#include "SchM_Mcl.h"
#define USER_MODE_REG_PROT_ENABLED (STD_OFF)
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           eMios_Common.c
* @brief          Source file version information
*/
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
#define EMIOS_COMMON_VENDOR_ID_C                      43
/** @violates @ref eMios_Common_c_5 This is not a standard library macro
 **@violates @ref eMios_Common_c_6 This is required as per autosar Requirement */
#define EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref eMios_Common_c_5 This is not a standard library macro
*   @violates @ref eMios_Common_c_6 This is required as per autosar Requirement */
#define EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref eMios_Common_c_5 This is not a standard library macro
*   @violates @ref eMios_Common_c_6 This is required as per autosar Requirement */
#define EMIOS_COMMON_AR_RELEASE_REVISION_VERSION_C    2
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
#define EMIOS_COMMON_SW_MAJOR_VERSION_C               1
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
#define EMIOS_COMMON_SW_MINOR_VERSION_C               0
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
#define EMIOS_COMMON_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C != MODULES_AR_RELEASE_MAJOR_VERSION_H) || \
        (EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C != MODULES_AR_RELEASE_MINOR_VERSION_H))
        #error "AutoSar Version Numbers of eMios_Common.c and modules.h are different"
    #endif
    #if ((EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of eMios_Common.c and Std_Types.h are different"
    #endif
#endif

#if (EMIOS_COMMON_VENDOR_ID_C != EMIOS_COMMON_TYPES_VENDOR_ID)
    #error "eMios_Common.c and eMios_Common_Types.h have different vendor ids"
#endif
#if ((EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C != EMIOS_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C !=  \
                                              EMIOS_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_REVISION_VERSION_C !=  \
                                              EMIOS_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMios_Common.c and eMios_Common_Types.h are different"
#endif
#if ((EMIOS_COMMON_SW_MAJOR_VERSION_C != EMIOS_COMMON_TYPES_SW_MAJOR_VERSION)  || \
        (EMIOS_COMMON_SW_MINOR_VERSION_C != EMIOS_COMMON_TYPES_SW_MINOR_VERSION)  || \
        (EMIOS_COMMON_SW_PATCH_VERSION_C != EMIOS_COMMON_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMios_Common.c and eMios_Common_Types.h are different"
#endif

#if (EMIOS_COMMON_VENDOR_ID_C != REG_ESYS_EMIOS_VENDOR_ID)
    #error "eMios_Common.c and Reg_eSys_eMios.h have different vendor ids"
#endif
#if ((EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C != REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C != REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_EMIOS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMios_Common.c and Reg_eSys_eMios.h are different"
#endif
#if ((EMIOS_COMMON_SW_MAJOR_VERSION_C != REG_ESYS_EMIOS_SW_MAJOR_VERSION)  || \
        (EMIOS_COMMON_SW_MINOR_VERSION_C != REG_ESYS_EMIOS_SW_MINOR_VERSION)  || \
        (EMIOS_COMMON_SW_PATCH_VERSION_C != REG_ESYS_EMIOS_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMios_Common.c and Reg_eSys_eMios.h are different"
#endif

#if (USE_GPT_MODULE==STD_ON)
#if (EMIOS_COMMON_VENDOR_ID_C != GPT_EMIOS_IRQ_VENDOR_ID)
    #error "eMios_Common.c and Gpt_eMios_Irq.h have different vendor ids"
#endif
#if ((EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C != GPT_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C != GPT_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_REVISION_VERSION_C != GPT_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMios_Common.c and Gpt_eMios_Irq.h are different"
#endif
#if ((EMIOS_COMMON_SW_MAJOR_VERSION_C != GPT_EMIOS_IRQ_SW_MAJOR_VERSION)  || \
        (EMIOS_COMMON_SW_MINOR_VERSION_C != GPT_EMIOS_IRQ_SW_MINOR_VERSION)  || \
        (EMIOS_COMMON_SW_PATCH_VERSION_C != GPT_EMIOS_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMios_Common.c and Gpt_eMios_Irq.h are different"
#endif
#endif

#if (USE_PWM_MODULE==STD_ON)
#if (EMIOS_COMMON_VENDOR_ID_C != PWM_EMIOS_VENDOR_ID)
    #error "eMios_Common.c and Pwm_eMios.h have different vendor ids"
#endif
#if ((EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C != PWM_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C != PWM_EMIOS_AR_RELEASE_MINOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_REVISION_VERSION_C != PWM_EMIOS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMios_Common.c and Pwm_eMios.h are different"
#endif
#if ((EMIOS_COMMON_SW_MAJOR_VERSION_C != PWM_EMIOS_SW_MAJOR_VERSION)  || \
        (EMIOS_COMMON_SW_MINOR_VERSION_C != PWM_EMIOS_SW_MINOR_VERSION)  || \
        (EMIOS_COMMON_SW_PATCH_VERSION_C != PWM_EMIOS_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMios_Common.c and Pwm_eMios.h are different"
#endif
#endif

#if (USE_ICU_MODULE==STD_ON)
#if (EMIOS_COMMON_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "eMios_Common.c and Icu_Cfg.h have different vendor ids"
#endif
#if ((EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
        (EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
        (EMIOS_COMMON_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of eMios_Common.c and Icu_Cfg.h are different"
#endif
#if ((EMIOS_COMMON_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG)  || \
        (EMIOS_COMMON_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG)  || \
        (EMIOS_COMMON_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of eMios_Common.c and Icu_Cfg.h are different"
#endif
#if (EMIOS_COMMON_VENDOR_ID_C != ICU_EMIOS_IRQ_VENDOR_ID)
    #error "eMios_Common.c and Icu_eMios_Irq.h have different vendor ids"
#endif
#if ((EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION_C != ICU_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_MINOR_VERSION_C != ICU_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION) || \
        (EMIOS_COMMON_AR_RELEASE_REVISION_VERSION_C != ICU_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of eMios_Common.c and Icu_eMios.h are different"
#endif
#if ((EMIOS_COMMON_SW_MAJOR_VERSION_C != ICU_EMIOS_IRQ_SW_MAJOR_VERSION)  || \
        (EMIOS_COMMON_SW_MINOR_VERSION_C != ICU_EMIOS_IRQ_SW_MINOR_VERSION)  || \
        (EMIOS_COMMON_SW_PATCH_VERSION_C != ICU_EMIOS_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of eMios_Common.c and Icu_eMios_Irq.h are different"
#endif
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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

#define MCL_START_SEC_CONST_32
/**@violates @ref eMios_Common_c_1 only preprocessor statements and comments before "#include"
 **@violates @ref eMios_Common_c_2 Precautions shall be taken in order to prevent...*/
#include "Mcl_MemMap.h"

/**
* @brief EMIOS base address array
*/
CONST(uint32, MCL_CONST) EMIOS_BASE_ADDR32[] = 
{
#ifdef  EMIOS0_BASEADDR
    /** @brief check if first emios is available on the platform */
    EMIOS0_BASEADDR,
#endif

#ifdef  EMIOS1_BASEADDR
    /** @brief check if second emios is available on the platform */
    EMIOS1_BASEADDR,
#endif

#ifdef  EMIOS2_BASEADDR
    /** @brief check if third emios is available on the platform */
    EMIOS2_BASEADDR,
#endif

#ifdef  EMIOS3_BASEADDR
    /** @brief check if for fourth emios is available on the platform */
    EMIOS3_BASEADDR,
#endif
};

#define MCL_STOP_SEC_CONST_32
/**@violates @ref eMios_Common_c_1 only preprocessor statements and comments before "#include"
 **@violates @ref eMios_Common_c_2 Precautions shall be taken in order to prevent...*/
#include "Mcl_MemMap.h"


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                   GLOBAL FUNCTIONS PROTOTYPES
==================================================================================================*/
#define MCL_START_SEC_CODE
/**@violates @ref eMios_Common_c_1 only preprocessor statements and comments before "#include"
 **@violates @ref eMios_Common_c_2 Precautions shall be taken in order to prevent...*/
#include "Mcl_MemMap.h"

/*
* @brief EMIOS_0 common ISR declarations
*/
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_0_CH_1_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_2_CH_3_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_4_CH_5_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_6_CH_7_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_8_CH_9_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_10_CH_11_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_12_CH_13_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_14_CH_15_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_16_CH_17_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_18_CH_19_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_20_CH_21_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_22_CH_23_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_24_CH_25_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_26_CH_27_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_28_CH_29_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_30_CH_31_ISR);

/*
* @brief EMIOS_1 common ISR declarations
*/
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_0_CH_1_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_2_CH_3_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_4_CH_5_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_6_CH_7_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_8_CH_9_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_10_CH_11_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_12_CH_13_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_14_CH_15_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_16_CH_17_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_18_CH_19_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_20_CH_21_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_22_CH_23_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_24_CH_25_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_26_CH_27_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_28_CH_29_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_30_CH_31_ISR);

/*
* @brief EMIOS_2 common ISR declarations
*/
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_0_CH_1_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_2_CH_3_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_4_CH_5_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_6_CH_7_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_8_CH_9_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_10_CH_11_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_12_CH_13_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_14_CH_15_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_16_CH_17_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_18_CH_19_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_20_CH_21_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_22_CH_23_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_24_CH_25_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_26_CH_27_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_28_CH_29_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_30_CH_31_ISR);

/*
* @brief EMIOS_0 independent ISR declarations
*/
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_0_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_1_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_2_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_3_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_4_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_5_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_6_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_7_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_8_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_9_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_10_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_11_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_12_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_13_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_14_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_15_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_16_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_17_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_18_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_19_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_20_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_21_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_22_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_23_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_24_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_25_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_26_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_27_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_28_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_29_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_30_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_0_CH_31_ISR);

/*
* @brief EMIOS_1 independent ISR declarations
*/
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_0_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_1_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_2_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_3_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_4_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_5_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_6_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_7_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_8_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_9_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_10_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_11_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_12_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_13_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_14_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_15_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_16_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_17_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_18_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_19_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_20_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_21_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_22_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_23_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_24_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_25_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_26_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_27_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_28_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_29_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_30_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_1_CH_31_ISR);

/*
* @brief EMIOS_2 independent ISR declarations
*/
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_0_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_1_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_2_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_3_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_4_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_5_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_6_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_7_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_8_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_9_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_10_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_11_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_12_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_13_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_14_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_15_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_16_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_17_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_18_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_19_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_20_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_21_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_22_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_23_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_24_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_25_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_26_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_27_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_28_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_29_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_30_ISR);
/** @violates @ref eMios_Common_c_5 This is not a standard library macro */
ISR(EMIOS_2_CH_31_ISR);

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef EMIOS_UCDIS_AVAILABLE
#if (EMIOS_UCDIS_AVAILABLE == STD_ON)
/** 
* @brief   eMios start channel function. 
* @details This function is called separately for each EMIOS hw channel in order to start/enable it.
*
* @param[in]     u8HwChannel        Emios hw channel ID
*
*/
FUNC (void, MCL_CODE) eMios_StartChannel(VAR(uint8, AUTOMATIC) u8HwChannel)
{   
    CONST(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(u8HwChannel));
    CONST(uint8, AUTOMATIC) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(u8HwChannel));
    
    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_00();
    /* enable timer channel */ 
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/  
    REG_BIT_CLEAR32(EMIOS_UCDIS_ADDR32(u8ModuleIdx), (uint32)(BIT0 << u8ChannelIdx));   
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_00();

    return;
}

/** 
* @brief   eMios stop channel function. 
* @details This function is called separately for each EMIOS hw channel in order to stop/disable it.
*
* @param[in]     u8HwChannel        Emios hw channel ID
*
*/
FUNC (void, MCL_CODE) eMios_StopChannel(VAR(uint8, AUTOMATIC) u8HwChannel)
{   
    
    CONST(uint8, AUTOMATIC) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(u8HwChannel));
    CONST(uint8, AUTOMATIC) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(u8HwChannel));

    SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_01();
    /* disable timer channel */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    REG_BIT_SET32(EMIOS_UCDIS_ADDR32(u8ModuleIdx), (uint32)(BIT0 << u8ChannelIdx));
    
    SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_01();
    
    return;
}
#endif  /* EMIOS_UCDIS_AVAILABLE */
#endif

#ifdef EMIOS_COMMON_ISR_HANDLER
#if  (EMIOS_COMMON_ISR_HANDLER == STD_ON)
/*==================================================================================================*/
/*                    COMMON EMIOS CHANNELS INTERRUPT SERVICE ROUTINES DEFINITION                   */
/*==================================================================================================*/
/*********************************** EMIOS 0 common interrupts START ******************************/
/**
* @brief EMIOS module:0 channels:0,1 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_0
*/
#if  ((defined GPT_EMIOS_0_CH_0_ISR_USED) && (defined PWM_EMIOS_0_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_0"
#endif

#if  ((defined PWM_EMIOS_0_CH_0_ISR_USED) && (defined ICU_EMIOS_0_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_0"
#endif

#if  ((defined ICU_EMIOS_0_CH_0_ISR_USED) && (defined GPT_EMIOS_0_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_0"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_1
*/
#if  ((defined GPT_EMIOS_0_CH_1_ISR_USED) && (defined PWM_EMIOS_0_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if  ((defined PWM_EMIOS_0_CH_1_ISR_USED) && (defined ICU_EMIOS_0_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if  ((defined ICU_EMIOS_0_CH_1_ISR_USED) && (defined GPT_EMIOS_0_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if ( (defined GPT_EMIOS_0_CH_0_ISR_USED) || (defined GPT_EMIOS_0_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_0_ISR_USED) || (defined PWM_EMIOS_0_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_0_ISR_USED) || (defined ICU_EMIOS_0_CH_1_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 0 and 1 for eMios_0 module
* @details   Process the interrupt of eMios channels 0 and 1
* @note   This will be defined only if eMios channels 0 or 1 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_0_CH_0_CH_1_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_0_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_0_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_0_ISR_USED) )

    /* Check if match event occured on EMIOS_0 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 0)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_0 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 0)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
           ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_0_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_0);
            #endif

            #if(defined PWM_EMIOS_0_CH_0_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_0);
            #endif

            #if(defined ICU_EMIOS_0_CH_0_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_0);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 0),REG_READ32(EMIOS_CSR_ADDR32(0, 0)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_1_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_1_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_1_ISR_USED) )

    /* Check if match event occured on EMIOS_1 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer */
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 1)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_1 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 1)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_1_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_1);
            #endif

            #if(defined PWM_EMIOS_0_CH_1_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_1);
            #endif

            #if(defined ICU_EMIOS_0_CH_1_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_1);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 1),REG_READ32(EMIOS_CSR_ADDR32(0, 1)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/**
* @brief EMIOS module:0 channels:2,3 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_2
*/
#if  ((defined GPT_EMIOS_0_CH_2_ISR_USED) && (defined PWM_EMIOS_0_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_2"
#endif

#if  ((defined PWM_EMIOS_0_CH_2_ISR_USED) && (defined ICU_EMIOS_0_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_2"
#endif

#if  ((defined ICU_EMIOS_0_CH_2_ISR_USED) && (defined GPT_EMIOS_0_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_2"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_3
*/
#if  ((defined GPT_EMIOS_0_CH_3_ISR_USED) && (defined PWM_EMIOS_0_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if  ((defined PWM_EMIOS_0_CH_3_ISR_USED) && (defined ICU_EMIOS_0_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if  ((defined ICU_EMIOS_0_CH_3_ISR_USED) && (defined GPT_EMIOS_0_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if ( (defined GPT_EMIOS_0_CH_2_ISR_USED) || (defined GPT_EMIOS_0_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_2_ISR_USED) || (defined PWM_EMIOS_0_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_2_ISR_USED) || (defined ICU_EMIOS_0_CH_3_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 2 and 3 for eMios_0 module
* @details   Process the interrupt of eMios channels 2 and 3
*
* @note   This will be defined only if eMios channels 2 or 3 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_0_CH_2_CH_3_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_2_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_2_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_2_ISR_USED) )

    /* Check if match event occured on EMIOS_2 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer */
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 2)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_2 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 2)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_2_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_2);
            #endif

            #if(defined PWM_EMIOS_0_CH_2_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_2);
            #endif

            #if(defined ICU_EMIOS_0_CH_2_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_2);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 2),REG_READ32(EMIOS_CSR_ADDR32(0, 2)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_3_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_3_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_3_ISR_USED) )

    /* Check if match event occured on EMIOS_3 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer */
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 3)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_3 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 3)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_3_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_3);
            #endif

            #if(defined PWM_EMIOS_0_CH_3_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_3);
            #endif

            #if(defined ICU_EMIOS_0_CH_3_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_3);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 3),REG_READ32(EMIOS_CSR_ADDR32(0, 3)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer
     ** @violates @ref eMios_Common_c_4, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:4,5 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_4
*/
#if  ((defined GPT_EMIOS_0_CH_4_ISR_USED) && (defined PWM_EMIOS_0_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_4"
#endif

#if  ((defined PWM_EMIOS_0_CH_4_ISR_USED) && (defined ICU_EMIOS_0_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_4"
#endif

#if  ((defined ICU_EMIOS_0_CH_4_ISR_USED) && (defined GPT_EMIOS_0_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_4"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_5
*/
#if  ((defined GPT_EMIOS_0_CH_5_ISR_USED) && (defined PWM_EMIOS_0_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if  ((defined PWM_EMIOS_0_CH_5_ISR_USED) && (defined ICU_EMIOS_0_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if  ((defined ICU_EMIOS_0_CH_5_ISR_USED) && (defined GPT_EMIOS_0_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if ( (defined GPT_EMIOS_0_CH_4_ISR_USED) || (defined GPT_EMIOS_0_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_4_ISR_USED) || (defined PWM_EMIOS_0_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_4_ISR_USED) || (defined ICU_EMIOS_0_CH_5_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 4 and 5 for eMios_0 module
* @details   Process the interrupt of eMios channels 4 and 5
*
* @note   This will be defined only if eMios channels 4 or 5 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_4_CH_5_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_4_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_4_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_4_ISR_USED) )

    /* Check if match event occured on EMIOS_4 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 4)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_4 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 4)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_4_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_4);
            #endif

            #if(defined PWM_EMIOS_0_CH_4_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_4);
            #endif

            #if(defined ICU_EMIOS_0_CH_4_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_4);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 4),REG_READ32(EMIOS_CSR_ADDR32(0, 4)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_5_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_5_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_5_ISR_USED) )

    /* Check if match event occured on EMIOS_5 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 5)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_5 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 5)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_5_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_5);
            #endif

            #if(defined PWM_EMIOS_0_CH_5_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_5);
            #endif

            #if(defined ICU_EMIOS_0_CH_5_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_5);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 5),REG_READ32(EMIOS_CSR_ADDR32(0, 5)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:6,7 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_6
*/
#if  ((defined GPT_EMIOS_0_CH_6_ISR_USED) && (defined PWM_EMIOS_0_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_6"
#endif

#if  ((defined PWM_EMIOS_0_CH_6_ISR_USED) && (defined ICU_EMIOS_0_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_6"
#endif

#if  ((defined ICU_EMIOS_0_CH_6_ISR_USED) && (defined GPT_EMIOS_0_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_6"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_7
*/
#if  ((defined GPT_EMIOS_0_CH_7_ISR_USED) && (defined PWM_EMIOS_0_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if  ((defined PWM_EMIOS_0_CH_7_ISR_USED) && (defined ICU_EMIOS_0_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if  ((defined ICU_EMIOS_0_CH_7_ISR_USED) && (defined GPT_EMIOS_0_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if ( (defined GPT_EMIOS_0_CH_6_ISR_USED) || (defined GPT_EMIOS_0_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_6_ISR_USED) || (defined PWM_EMIOS_0_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_6_ISR_USED) || (defined ICU_EMIOS_0_CH_7_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 6 and 7 for eMios_0 module
* @details   Process the interrupt of eMios channels 6 and 7
*
* @note   This will be defined only if eMios channels 6 or 7 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_6_CH_7_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_6_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_6_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_6_ISR_USED) )

    /* Check if match event occured on EMIOS_6 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 6)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_6 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 6)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
                #if(defined GPT_EMIOS_0_CH_6_ISR_USED)
                        Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_6);
                #endif

                #if(defined PWM_EMIOS_0_CH_6_ISR_USED)
                        Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_6);
                #endif

                #if(defined ICU_EMIOS_0_CH_6_ISR_USED)
                        Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_6);
                #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 6),REG_READ32(EMIOS_CSR_ADDR32(0, 6)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_7_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_7_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_7_ISR_USED) )

    /* Check if match event occured on EMIOS_7 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 7)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_7 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 7)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_7_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_7);
            #endif

            #if(defined PWM_EMIOS_0_CH_7_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_7);
            #endif

            #if(defined ICU_EMIOS_0_CH_7_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_7);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 7),REG_READ32(EMIOS_CSR_ADDR32(0, 7)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:8,9 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_8
*/
#if  ((defined GPT_EMIOS_0_CH_8_ISR_USED) && (defined PWM_EMIOS_0_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_8"
#endif

#if  ((defined PWM_EMIOS_0_CH_8_ISR_USED) && (defined ICU_EMIOS_0_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_8"
#endif

#if  ((defined ICU_EMIOS_0_CH_8_ISR_USED) && (defined GPT_EMIOS_0_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_8"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_9
*/
#if  ((defined GPT_EMIOS_0_CH_9_ISR_USED) && (defined PWM_EMIOS_0_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if  ((defined PWM_EMIOS_0_CH_9_ISR_USED) && (defined ICU_EMIOS_0_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if  ((defined ICU_EMIOS_0_CH_9_ISR_USED) && (defined GPT_EMIOS_0_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if ( (defined GPT_EMIOS_0_CH_8_ISR_USED) || (defined GPT_EMIOS_0_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_8_ISR_USED) || (defined PWM_EMIOS_0_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_8_ISR_USED) || (defined ICU_EMIOS_0_CH_9_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 8 and 9 for eMios_0 module
* @details   Process the interrupt of eMios channels 8 and 9
* @note   This will be defined only if eMios channels 8 or 9 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_0_CH_8_CH_9_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_8_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_8_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_8_ISR_USED) )

    /* Check if match event occured on EMIOS_8 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 8)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_8 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 8)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_8_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_8);
            #endif

            #if(defined PWM_EMIOS_0_CH_8_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_8);
            #endif

            #if(defined ICU_EMIOS_0_CH_8_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_8);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 8),REG_READ32(EMIOS_CSR_ADDR32(0, 8)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_9_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_9_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_9_ISR_USED) )

    /* Check if match event occured on EMIOS_9 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 9)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_9 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 9)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_9_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_9);
            #endif

            #if(defined PWM_EMIOS_0_CH_9_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_9);
            #endif

            #if(defined ICU_EMIOS_0_CH_9_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_9);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 9),REG_READ32(EMIOS_CSR_ADDR32(0, 9)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer
     **@violates @ref eMios_Common_c_4 Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:10,11 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_10
*/
#if  ((defined GPT_EMIOS_0_CH_10_ISR_USED) && (defined PWM_EMIOS_0_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_10"
#endif

#if  ((defined PWM_EMIOS_0_CH_10_ISR_USED) && (defined ICU_EMIOS_0_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_10"
#endif

#if  ((defined ICU_EMIOS_0_CH_10_ISR_USED) && (defined GPT_EMIOS_0_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_10"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_11
*/
#if  ((defined GPT_EMIOS_0_CH_11_ISR_USED) && (defined PWM_EMIOS_0_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if  ((defined PWM_EMIOS_0_CH_11_ISR_USED) && (defined ICU_EMIOS_0_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if  ((defined ICU_EMIOS_0_CH_11_ISR_USED) && (defined GPT_EMIOS_0_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if ( (defined GPT_EMIOS_0_CH_10_ISR_USED) || (defined GPT_EMIOS_0_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_10_ISR_USED) || (defined PWM_EMIOS_0_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_10_ISR_USED) || (defined ICU_EMIOS_0_CH_11_ISR_USED) )

/*================================================================================================*/
/**
* @brief    Interrupt handler for eMios channels : 10 and 11 for eMios_0 module
* @details  Process the interrupt of eMios channels 10 and 11
*
*@note      This will be defined only if eMios channels 10 or 11 are configured in GPT, ICU or
*           PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
/*================================================================================================*/
ISR(EMIOS_0_CH_10_CH_11_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_10_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_10_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_10_ISR_USED) )

    /* Check if match event occured on EMIOS_10 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 10)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_10 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 10)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_10_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_10);
            #endif

            #if(defined PWM_EMIOS_0_CH_10_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_10);
            #endif

            #if(defined ICU_EMIOS_0_CH_10_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_10);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 10),REG_READ32(EMIOS_CSR_ADDR32(0, 10)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_11_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_11_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_11_ISR_USED) )

    /* Check if match event occured on EMIOS_11 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 11)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_11 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 11)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_11_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_11);
            #endif

            #if(defined PWM_EMIOS_0_CH_11_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_11);
            #endif

            #if(defined ICU_EMIOS_0_CH_11_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_11);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 11),REG_READ32(EMIOS_CSR_ADDR32(0, 11)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:12,13 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_12
*/
#if  ((defined GPT_EMIOS_0_CH_12_ISR_USED) && (defined PWM_EMIOS_0_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_12"
#endif

#if  ((defined PWM_EMIOS_0_CH_12_ISR_USED) && (defined ICU_EMIOS_0_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_12"
#endif

#if  ((defined ICU_EMIOS_0_CH_12_ISR_USED) && (defined GPT_EMIOS_0_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_12"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_13
*/
#if  ((defined GPT_EMIOS_0_CH_13_ISR_USED) && (defined PWM_EMIOS_0_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if  ((defined PWM_EMIOS_0_CH_13_ISR_USED) && (defined ICU_EMIOS_0_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if  ((defined ICU_EMIOS_0_CH_13_ISR_USED) && (defined GPT_EMIOS_0_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if ( (defined GPT_EMIOS_0_CH_12_ISR_USED) || (defined GPT_EMIOS_0_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_12_ISR_USED) || (defined PWM_EMIOS_0_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_12_ISR_USED) || (defined ICU_EMIOS_0_CH_13_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 12 and 13 for eMios_0 module
* @details   Process the interrupt of eMios channels 12 and 13
*
* @note     This will be defined only if eMios channels 12 or 13 are configured in GPT, ICU or PWM
*           mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_12_CH_13_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_12_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_12_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_12_ISR_USED) )

    /* Check if match event occured on EMIOS_12 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 12)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_12 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 12)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_12_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_12);
            #endif

            #if(defined PWM_EMIOS_0_CH_12_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_12);
            #endif

            #if(defined ICU_EMIOS_0_CH_12_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_12);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 12),REG_READ32(EMIOS_CSR_ADDR32(0, 12)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_13_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_13_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_13_ISR_USED) )

    /* Check if match event occured on EMIOS_13 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 13)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_13 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 13)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_13_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_13);
            #endif

            #if(defined PWM_EMIOS_0_CH_13_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_13);
            #endif

            #if(defined ICU_EMIOS_0_CH_13_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_13);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 13),REG_READ32(EMIOS_CSR_ADDR32(0, 13)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:14,15 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_14
*/
#if  ((defined GPT_EMIOS_0_CH_14_ISR_USED) && (defined PWM_EMIOS_0_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_14"
#endif

#if  ((defined PWM_EMIOS_0_CH_14_ISR_USED) && (defined ICU_EMIOS_0_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_14"
#endif

#if  ((defined ICU_EMIOS_0_CH_14_ISR_USED) && (defined GPT_EMIOS_0_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_14"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_15
*/
#if  ((defined GPT_EMIOS_0_CH_15_ISR_USED) && (defined PWM_EMIOS_0_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if  ((defined PWM_EMIOS_0_CH_15_ISR_USED) && (defined ICU_EMIOS_0_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if  ((defined ICU_EMIOS_0_CH_15_ISR_USED) && (defined GPT_EMIOS_0_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if ( (defined GPT_EMIOS_0_CH_14_ISR_USED) || (defined GPT_EMIOS_0_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_14_ISR_USED) || (defined PWM_EMIOS_0_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_14_ISR_USED) || (defined ICU_EMIOS_0_CH_15_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 14 and 15 for eMios_0 module
* @details   Process the interrupt of eMios channels 14 and 15
*
* @note     This will be defined only if eMios channels 14 or 15 are configured in GPT, ICU or PWM
*           mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_14_CH_15_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_14_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_14_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_14_ISR_USED) )

    /* Check if match event occured on EMIOS_14 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 14)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_14 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 14)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_14_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_14);
            #endif

            #if(defined PWM_EMIOS_0_CH_14_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_14);
            #endif

            #if(defined ICU_EMIOS_0_CH_14_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_14);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 14),REG_READ32(EMIOS_CSR_ADDR32(0, 14)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_15_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_15_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_15_ISR_USED) )

    /* Check if match event occured on EMIOS_15 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 15)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_15 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 15)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_15_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_15);
            #endif

            #if(defined PWM_EMIOS_0_CH_15_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_15);
            #endif

            #if(defined ICU_EMIOS_0_CH_15_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_15);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 15),REG_READ32(EMIOS_CSR_ADDR32(0, 15)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:16,17 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_16
*/
#if  ((defined GPT_EMIOS_0_CH_16_ISR_USED) && (defined PWM_EMIOS_0_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_16"
#endif

#if  ((defined PWM_EMIOS_0_CH_16_ISR_USED) && (defined ICU_EMIOS_0_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_16"
#endif

#if  ((defined ICU_EMIOS_0_CH_16_ISR_USED) && (defined GPT_EMIOS_0_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_16"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_17
*/
#if  ((defined GPT_EMIOS_0_CH_17_ISR_USED) && (defined PWM_EMIOS_0_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if  ((defined PWM_EMIOS_0_CH_17_ISR_USED) && (defined ICU_EMIOS_0_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if  ((defined ICU_EMIOS_0_CH_17_ISR_USED) && (defined GPT_EMIOS_0_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if ( (defined GPT_EMIOS_0_CH_16_ISR_USED) || (defined GPT_EMIOS_0_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_16_ISR_USED) || (defined PWM_EMIOS_0_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_16_ISR_USED) || (defined ICU_EMIOS_0_CH_17_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 16 and 17 for eMios_0 module
* @details   Process the interrupt of eMios channels 16 and 17

* @note     This will be defined only if eMios channels 16 or 17 are configured in GPT, ICU or PWM
*           mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_16_CH_17_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_16_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_16_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_16_ISR_USED) )

    /* Check if match event occured on EMIOS_16 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 16)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_16 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 16)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_16_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_16);
            #endif

            #if(defined PWM_EMIOS_0_CH_16_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_16);
            #endif

            #if(defined ICU_EMIOS_0_CH_16_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_16);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 16),REG_READ32(EMIOS_CSR_ADDR32(0, 16)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_17_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_17_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_17_ISR_USED) )

    /* Check if match event occured on EMIOS_17 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 17)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_17 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 17)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
        ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_17_ISR_USED)
                    Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_17);
            #endif

            #if(defined PWM_EMIOS_0_CH_17_ISR_USED)
                    Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_17);
            #endif

            #if(defined ICU_EMIOS_0_CH_17_ISR_USED)
                    Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_17);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 17),REG_READ32(EMIOS_CSR_ADDR32(0, 17)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:18,19 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_18
*/
#if  ((defined GPT_EMIOS_0_CH_18_ISR_USED) && (defined PWM_EMIOS_0_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_18"
#endif

#if  ((defined PWM_EMIOS_0_CH_18_ISR_USED) && (defined ICU_EMIOS_0_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_18"
#endif

#if  ((defined ICU_EMIOS_0_CH_18_ISR_USED) && (defined GPT_EMIOS_0_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_18"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_19
*/
#if  ((defined GPT_EMIOS_0_CH_19_ISR_USED) && (defined PWM_EMIOS_0_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if  ((defined PWM_EMIOS_0_CH_19_ISR_USED) && (defined ICU_EMIOS_0_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if  ((defined ICU_EMIOS_0_CH_19_ISR_USED) && (defined GPT_EMIOS_0_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if ( (defined GPT_EMIOS_0_CH_18_ISR_USED) || (defined GPT_EMIOS_0_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_18_ISR_USED) || (defined PWM_EMIOS_0_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_18_ISR_USED) || (defined ICU_EMIOS_0_CH_19_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 18 and 19 for eMios_0 module
* @details   Process the interrupt of eMios channels 18 and 19
*
* @note   This will be defined only if eMios channels 18 or 19 are configured in GPT, ICU or PWM
*            mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_18_CH_19_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_18_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_18_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_18_ISR_USED) )

    /* Check if match event occured on EMIOS_18 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 18)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_18 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 18)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_18_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_18);
            #endif

            #if(defined PWM_EMIOS_0_CH_18_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_18);
            #endif

            #if(defined ICU_EMIOS_0_CH_18_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_18);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 18),REG_READ32(EMIOS_CSR_ADDR32(0, 18)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_19_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_19_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_19_ISR_USED) )

    /* Check if match event occured on EMIOS_19 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 19)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_19 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 19)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_19_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_19);
            #endif

            #if(defined PWM_EMIOS_0_CH_19_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_19);
            #endif

            #if(defined ICU_EMIOS_0_CH_19_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_19);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 19),REG_READ32(EMIOS_CSR_ADDR32(0, 19)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:20,21 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_20
*/
#if  ((defined GPT_EMIOS_0_CH_20_ISR_USED) && (defined PWM_EMIOS_0_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_20"
#endif

#if  ((defined PWM_EMIOS_0_CH_20_ISR_USED) && (defined ICU_EMIOS_0_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_20"
#endif

#if  ((defined ICU_EMIOS_0_CH_20_ISR_USED) && (defined GPT_EMIOS_0_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_20"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_21
*/
#if  ((defined GPT_EMIOS_0_CH_21_ISR_USED) && (defined PWM_EMIOS_0_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if  ((defined PWM_EMIOS_0_CH_21_ISR_USED) && (defined ICU_EMIOS_0_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if  ((defined ICU_EMIOS_0_CH_21_ISR_USED) && (defined GPT_EMIOS_0_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if ( (defined GPT_EMIOS_0_CH_20_ISR_USED) || (defined GPT_EMIOS_0_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_20_ISR_USED) || (defined PWM_EMIOS_0_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_20_ISR_USED) || (defined ICU_EMIOS_0_CH_21_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 20 and 21 for eMios_0 module
* @details   Process the interrupt of eMios channels 20 and 21
*
* @note   This will be defined only if eMios channels 20 or 21 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_20_CH_21_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_20_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_20_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_20_ISR_USED) )

    /* Check if match event occured on EMIOS_20 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 20)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_20 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 20)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_20_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_20);
            #endif

            #if(defined PWM_EMIOS_0_CH_20_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_20);
            #endif

            #if(defined ICU_EMIOS_0_CH_20_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_20);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 20),REG_READ32(EMIOS_CSR_ADDR32(0, 20)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_21_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_21_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_21_ISR_USED) )

    /* Check if match event occured on EMIOS_21 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 21)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_21 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 21)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_21_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_21);
            #endif

            #if(defined PWM_EMIOS_0_CH_21_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_21);
            #endif

            #if(defined ICU_EMIOS_0_CH_21_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_21);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 21),REG_READ32(EMIOS_CSR_ADDR32(0, 21)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:22,23 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_22
*/
#if  ((defined GPT_EMIOS_0_CH_22_ISR_USED) && (defined PWM_EMIOS_0_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_22"
#endif

#if  ((defined PWM_EMIOS_0_CH_22_ISR_USED) && (defined ICU_EMIOS_0_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_22"
#endif

#if  ((defined ICU_EMIOS_0_CH_22_ISR_USED) && (defined GPT_EMIOS_0_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_22"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_23
*/
#if  ((defined GPT_EMIOS_0_CH_23_ISR_USED) && (defined PWM_EMIOS_0_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if  ((defined PWM_EMIOS_0_CH_23_ISR_USED) && (defined ICU_EMIOS_0_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if  ((defined ICU_EMIOS_0_CH_23_ISR_USED) && (defined GPT_EMIOS_0_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if ( (defined GPT_EMIOS_0_CH_22_ISR_USED) || (defined GPT_EMIOS_0_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_22_ISR_USED) || (defined PWM_EMIOS_0_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_22_ISR_USED) || (defined ICU_EMIOS_0_CH_23_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 22 and 23 for eMios_0 module
* @details   Process the interrupt of eMios channels 22 and 23
*
* @note   This will be defined only if eMios channels 22 or 23 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_0_CH_22_CH_23_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_22_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_22_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_22_ISR_USED) )

    /* Check if match event occured on EMIOS_22 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 22)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_22 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 22)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_22_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_22);
            #endif
    
            #if(defined PWM_EMIOS_0_CH_22_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_22);
            #endif
    
            #if(defined ICU_EMIOS_0_CH_22_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_22);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 22),REG_READ32(EMIOS_CSR_ADDR32(0, 22)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_23_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_23_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_23_ISR_USED) )

    /* Check if match event occured on EMIOS_23 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 23)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_23 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 23)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_23_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_23);
            #endif

            #if(defined PWM_EMIOS_0_CH_23_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_23);
            #endif

            #if(defined ICU_EMIOS_0_CH_23_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_23);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 23),REG_READ32(EMIOS_CSR_ADDR32(0, 23)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:24,25 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_24
*/
#if  ((defined GPT_EMIOS_0_CH_24_ISR_USED) && (defined PWM_EMIOS_0_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_24"
#endif

#if  ((defined PWM_EMIOS_0_CH_24_ISR_USED) && (defined ICU_EMIOS_0_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_24"
#endif

#if  ((defined ICU_EMIOS_0_CH_24_ISR_USED) && (defined GPT_EMIOS_0_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_24"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_25
*/
#if  ((defined GPT_EMIOS_0_CH_25_ISR_USED) && (defined PWM_EMIOS_0_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if  ((defined PWM_EMIOS_0_CH_25_ISR_USED) && (defined ICU_EMIOS_0_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if  ((defined ICU_EMIOS_0_CH_25_ISR_USED) && (defined GPT_EMIOS_0_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if ( (defined GPT_EMIOS_0_CH_24_ISR_USED) || (defined GPT_EMIOS_0_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_24_ISR_USED) || (defined PWM_EMIOS_0_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_24_ISR_USED) || (defined ICU_EMIOS_0_CH_25_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 24 and 25 for eMios_0 module
* @details   Process the interrupt of eMios channels 24 and 25
*
* @note   This will be defined only if eMios channels 24 or 25 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_0_CH_24_CH_25_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_24_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_24_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_24_ISR_USED) )

    /* Check if match event occured on EMIOS_24 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 24)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_24 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 24)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_24_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_24);
            #endif

            #if(defined PWM_EMIOS_0_CH_24_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_24);
            #endif

            #if(defined ICU_EMIOS_0_CH_24_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_24);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 24),REG_READ32(EMIOS_CSR_ADDR32(0, 24)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_25_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_25_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_25_ISR_USED) )

    /* Check if match event occured on EMIOS_25 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 25)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_25 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 25)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_25_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_25);
            #endif

            #if(defined PWM_EMIOS_0_CH_25_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_25);
            #endif

            #if(defined ICU_EMIOS_0_CH_25_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_25);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 25),REG_READ32(EMIOS_CSR_ADDR32(0, 25)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:26,27 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_26
*/
#if  ((defined GPT_EMIOS_0_CH_26_ISR_USED) && (defined PWM_EMIOS_0_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_26"
#endif

#if  ((defined PWM_EMIOS_0_CH_26_ISR_USED) && (defined ICU_EMIOS_0_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_26"
#endif

#if  ((defined ICU_EMIOS_0_CH_26_ISR_USED) && (defined GPT_EMIOS_0_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_26"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_27
*/
#if  ((defined GPT_EMIOS_0_CH_27_ISR_USED) && (defined PWM_EMIOS_0_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if  ((defined PWM_EMIOS_0_CH_27_ISR_USED) && (defined ICU_EMIOS_0_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if  ((defined ICU_EMIOS_0_CH_27_ISR_USED) && (defined GPT_EMIOS_0_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if ( (defined GPT_EMIOS_0_CH_26_ISR_USED) || (defined GPT_EMIOS_0_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_26_ISR_USED) || (defined PWM_EMIOS_0_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_26_ISR_USED) || (defined ICU_EMIOS_0_CH_27_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 26 and 27 for eMios_0 module
* @details   Process the interrupt of eMios channels 26 and 27
*
* @note   This will be defined only if eMios channels 26 or 27 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_0_CH_26_CH_27_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_26_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_26_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_26_ISR_USED) )

    /* Check if match event occured on EMIOS_26 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 26)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_26 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 26)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_26_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_26);
            #endif

            #if(defined PWM_EMIOS_0_CH_26_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_26);
            #endif

            #if(defined ICU_EMIOS_0_CH_26_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_26);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 26),REG_READ32(EMIOS_CSR_ADDR32(0, 26)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_27_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_27_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_27_ISR_USED) )

    /* Check if match event occured on EMIOS_27 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 27)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_27 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 27)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_27_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_27);
            #endif

            #if(defined PWM_EMIOS_0_CH_27_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_27);
            #endif

            #if(defined ICU_EMIOS_0_CH_27_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_27);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 27),REG_READ32(EMIOS_CSR_ADDR32(0, 27)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:28,29 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_28
*/
#if  ((defined GPT_EMIOS_0_CH_28_ISR_USED) && (defined PWM_EMIOS_0_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_28"
#endif

#if  ((defined PWM_EMIOS_0_CH_28_ISR_USED) && (defined ICU_EMIOS_0_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_28"
#endif

#if  ((defined ICU_EMIOS_0_CH_28_ISR_USED) && (defined GPT_EMIOS_0_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_28"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_29
*/
#if  ((defined GPT_EMIOS_0_CH_29_ISR_USED) && (defined PWM_EMIOS_0_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if  ((defined PWM_EMIOS_0_CH_29_ISR_USED) && (defined ICU_EMIOS_0_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if  ((defined ICU_EMIOS_0_CH_29_ISR_USED) && (defined GPT_EMIOS_0_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if ( (defined GPT_EMIOS_0_CH_28_ISR_USED) || (defined GPT_EMIOS_0_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_28_ISR_USED) || (defined PWM_EMIOS_0_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_28_ISR_USED) || (defined ICU_EMIOS_0_CH_29_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 28 and 29 for eMios_0 module
* @details   Process the interrupt of eMios channels 28 and 29
*
* @note   This will be defined only if eMios channels 28 or 29 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_0_CH_28_CH_29_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_28_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_28_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_28_ISR_USED) )

    /* Check if match event occured on EMIOS_28 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 28)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_28 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 28)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_28_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_28);
            #endif

            #if(defined PWM_EMIOS_0_CH_28_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_28);
            #endif

            #if(defined ICU_EMIOS_0_CH_28_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_28);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 28),REG_READ32(EMIOS_CSR_ADDR32(0, 28)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_29_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_29_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_29_ISR_USED) )

    /* Check if match event occured on EMIOS_29 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 29)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_29 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 29)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_29_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_29);
            #endif

            #if(defined PWM_EMIOS_0_CH_29_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_29);
            #endif

            #if(defined ICU_EMIOS_0_CH_29_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_29);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 29),REG_READ32(EMIOS_CSR_ADDR32(0, 29)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channels:30,31 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_30
*/
#if  ((defined GPT_EMIOS_0_CH_30_ISR_USED) && (defined PWM_EMIOS_0_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_30"
#endif

#if  ((defined PWM_EMIOS_0_CH_30_ISR_USED) && (defined ICU_EMIOS_0_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_30"
#endif

#if  ((defined ICU_EMIOS_0_CH_30_ISR_USED) && (defined GPT_EMIOS_0_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_30"
#endif


/*
* @brief resource conflict check for EMIOS_0_CH_31
*/
#if  ((defined GPT_EMIOS_0_CH_31_ISR_USED) && (defined PWM_EMIOS_0_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if  ((defined PWM_EMIOS_0_CH_31_ISR_USED) && (defined ICU_EMIOS_0_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if  ((defined ICU_EMIOS_0_CH_31_ISR_USED) && (defined GPT_EMIOS_0_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if ( (defined GPT_EMIOS_0_CH_30_ISR_USED) || (defined GPT_EMIOS_0_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_30_ISR_USED) || (defined PWM_EMIOS_0_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_30_ISR_USED) || (defined ICU_EMIOS_0_CH_31_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 30 and 31 for eMios_0 module
* @details   Process the interrupt of eMios channels 30 and 31
*
* @note   This will be defined only if eMios channels 30 or 31 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_30_CH_31_ISR)
{
     #if ( (defined GPT_EMIOS_0_CH_30_ISR_USED) || \
           (defined PWM_EMIOS_0_CH_30_ISR_USED) || \
           (defined ICU_EMIOS_0_CH_30_ISR_USED) )

    /* Check if match event occured on EMIOS_30 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 30)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_30 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 30)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_30_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_30);
            #endif

            #if(defined PWM_EMIOS_0_CH_30_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_30);
            #endif

            #if(defined ICU_EMIOS_0_CH_30_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_30);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 30),REG_READ32(EMIOS_CSR_ADDR32(0, 30)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_0_CH_31_ISR_USED) || \
          (defined PWM_EMIOS_0_CH_31_ISR_USED) || \
          (defined ICU_EMIOS_0_CH_31_ISR_USED) )

    /* Check if match event occured on EMIOS_31 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(0, 31)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_31 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(0, 31)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_0_CH_31_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_31);
            #endif

            #if(defined PWM_EMIOS_0_CH_31_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_31);
            #endif

            #if(defined ICU_EMIOS_0_CH_31_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_31);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(0, 31),REG_READ32(EMIOS_CSR_ADDR32(0, 31)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif



/*********************************** EMIOS 0 common interrupts END ********************************/



/*********************************** EMIOS 1 common interrupts START ******************************/


/*
* @brief EMIOS module:1 channels:0,1 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_0
*/
#if  ((defined GPT_EMIOS_1_CH_0_ISR_USED) && (defined PWM_EMIOS_1_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_0"
#endif

#if  ((defined PWM_EMIOS_1_CH_0_ISR_USED) && (defined ICU_EMIOS_1_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_0"
#endif

#if  ((defined ICU_EMIOS_1_CH_0_ISR_USED) && (defined GPT_EMIOS_1_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_0"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_1
*/
#if  ((defined GPT_EMIOS_1_CH_1_ISR_USED) && (defined PWM_EMIOS_1_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if  ((defined PWM_EMIOS_1_CH_1_ISR_USED) && (defined ICU_EMIOS_1_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if  ((defined ICU_EMIOS_1_CH_1_ISR_USED) && (defined GPT_EMIOS_1_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if ( (defined GPT_EMIOS_1_CH_0_ISR_USED) || (defined GPT_EMIOS_1_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_0_ISR_USED) || (defined PWM_EMIOS_1_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_0_ISR_USED) || (defined ICU_EMIOS_1_CH_1_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 0 and 1 for eMios_1 module
* @details   Process the interrupt of eMios channels 0 and 1
*
* @note   This will be defined only if eMios channels 0 or 1 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_0_CH_1_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_0_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_0_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_0_ISR_USED) )

    /* Check if match event occured on EMIOS_0 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 0)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_0 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 0)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_0_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_0);
            #endif

            #if(defined PWM_EMIOS_1_CH_0_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_0);
            #endif

            #if(defined ICU_EMIOS_1_CH_0_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_0);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 0),REG_READ32(EMIOS_CSR_ADDR32(1, 0)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_1_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_1_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_1_ISR_USED) )

    /* Check if match event occured on EMIOS_1 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 1)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_1 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 1)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_1_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_1);
            #endif

            #if(defined PWM_EMIOS_1_CH_1_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_1);
            #endif

            #if(defined ICU_EMIOS_1_CH_1_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_1);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 1),REG_READ32(EMIOS_CSR_ADDR32(1, 1)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:2,3 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_2
*/
#if  ((defined GPT_EMIOS_1_CH_2_ISR_USED) && (defined PWM_EMIOS_1_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_2"
#endif

#if  ((defined PWM_EMIOS_1_CH_2_ISR_USED) && (defined ICU_EMIOS_1_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_2"
#endif

#if  ((defined ICU_EMIOS_1_CH_2_ISR_USED) && (defined GPT_EMIOS_1_CH_2_ISR_USED))
#error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_2"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_3
*/
#if  ((defined GPT_EMIOS_1_CH_3_ISR_USED) && (defined PWM_EMIOS_1_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if  ((defined PWM_EMIOS_1_CH_3_ISR_USED) && (defined ICU_EMIOS_1_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if  ((defined ICU_EMIOS_1_CH_3_ISR_USED) && (defined GPT_EMIOS_1_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if ( (defined GPT_EMIOS_1_CH_2_ISR_USED) || (defined GPT_EMIOS_1_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_2_ISR_USED) || (defined PWM_EMIOS_1_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_2_ISR_USED) || (defined ICU_EMIOS_1_CH_3_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 2 and 3 for eMios_1 module
* @details   Process the interrupt of eMios channels 2 and 3
*
* @note   This will be defined only if eMios channels 2 or 3 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_1_CH_2_CH_3_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_2_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_2_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_2_ISR_USED) )

    /* Check if match event occured on EMIOS_2 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 2)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_2 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 2)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_2_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_2);
            #endif

            #if(defined PWM_EMIOS_1_CH_2_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_2);
            #endif

            #if(defined ICU_EMIOS_1_CH_2_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_2);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 2),REG_READ32(EMIOS_CSR_ADDR32(1, 2)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_3_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_3_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_3_ISR_USED) )

    /* Check if match event occured on EMIOS_3 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 3)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_3 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 3)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_3_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_3);
            #endif

            #if(defined PWM_EMIOS_1_CH_3_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_3);
            #endif

            #if(defined ICU_EMIOS_1_CH_3_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_3);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 3),REG_READ32(EMIOS_CSR_ADDR32(1, 3)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:4,5 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_4
*/
#if  ((defined GPT_EMIOS_1_CH_4_ISR_USED) && (defined PWM_EMIOS_1_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_4"
#endif

#if  ((defined PWM_EMIOS_1_CH_4_ISR_USED) && (defined ICU_EMIOS_1_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_4"
#endif

#if  ((defined ICU_EMIOS_1_CH_4_ISR_USED) && (defined GPT_EMIOS_1_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_4"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_5
*/
#if  ((defined GPT_EMIOS_1_CH_5_ISR_USED) && (defined PWM_EMIOS_1_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if  ((defined PWM_EMIOS_1_CH_5_ISR_USED) && (defined ICU_EMIOS_1_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if  ((defined ICU_EMIOS_1_CH_5_ISR_USED) && (defined GPT_EMIOS_1_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if ( (defined GPT_EMIOS_1_CH_4_ISR_USED) || (defined GPT_EMIOS_1_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_4_ISR_USED) || (defined PWM_EMIOS_1_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_4_ISR_USED) || (defined ICU_EMIOS_1_CH_5_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 4 and 5 for eMios_1 module
* @details   Process the interrupt of eMios channels 4 and 5
* @note   This will be defined only if eMios channels 4 or 5 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro
*/
ISR(EMIOS_1_CH_4_CH_5_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_4_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_4_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_4_ISR_USED) )

    /* Check if match event occured on EMIOS_4 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 4)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_4 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 4)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_4_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_4);
            #endif

            #if(defined PWM_EMIOS_1_CH_4_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_4);
            #endif

            #if(defined ICU_EMIOS_1_CH_4_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_4);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 4),REG_READ32(EMIOS_CSR_ADDR32(1, 4)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_5_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_5_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_5_ISR_USED) )

    /* Check if match event occured on EMIOS_5 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 5)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_5 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 5)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_5_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_5);
            #endif

            #if(defined PWM_EMIOS_1_CH_5_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_5);
            #endif

            #if(defined ICU_EMIOS_1_CH_5_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_5);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 5),REG_READ32(EMIOS_CSR_ADDR32(1, 5)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:6,7 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_6
*/
#if  ((defined GPT_EMIOS_1_CH_6_ISR_USED) && (defined PWM_EMIOS_1_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_6"
#endif

#if  ((defined PWM_EMIOS_1_CH_6_ISR_USED) && (defined ICU_EMIOS_1_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_6"
#endif

#if  ((defined ICU_EMIOS_1_CH_6_ISR_USED) && (defined GPT_EMIOS_1_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_6"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_7
*/
#if  ((defined GPT_EMIOS_1_CH_7_ISR_USED) && (defined PWM_EMIOS_1_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if  ((defined PWM_EMIOS_1_CH_7_ISR_USED) && (defined ICU_EMIOS_1_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if  ((defined ICU_EMIOS_1_CH_7_ISR_USED) && (defined GPT_EMIOS_1_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if ( (defined GPT_EMIOS_1_CH_6_ISR_USED) || (defined GPT_EMIOS_1_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_6_ISR_USED) || (defined PWM_EMIOS_1_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_6_ISR_USED) || (defined ICU_EMIOS_1_CH_7_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 6 and 7 for eMios_1 module
* @details   Process the interrupt of eMios channels 6 and 7
*
* @note   This will be defined only if eMios channels 6 or 7 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_6_CH_7_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_6_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_6_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_6_ISR_USED) )

    /* Check if match event occured on EMIOS_6 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 6)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_6 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 6)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_6_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_6);
            #endif

            #if(defined PWM_EMIOS_1_CH_6_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_6);
            #endif

            #if(defined ICU_EMIOS_1_CH_6_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_6);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 6),REG_READ32(EMIOS_CSR_ADDR32(1, 6)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_7_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_7_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_7_ISR_USED) )

    /* Check if match event occured on EMIOS_7 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 7)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_7 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 7)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_7_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_7);
            #endif

            #if(defined PWM_EMIOS_1_CH_7_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_7);
            #endif

            #if(defined ICU_EMIOS_1_CH_7_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_7);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 7),REG_READ32(EMIOS_CSR_ADDR32(1, 7)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:8,9 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_8
*/
#if  ((defined GPT_EMIOS_1_CH_8_ISR_USED) && (defined PWM_EMIOS_1_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_8"
#endif

#if  ((defined PWM_EMIOS_1_CH_8_ISR_USED) && (defined ICU_EMIOS_1_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_8"
#endif

#if  ((defined ICU_EMIOS_1_CH_8_ISR_USED) && (defined GPT_EMIOS_1_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_8"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_9
*/
#if  ((defined GPT_EMIOS_1_CH_9_ISR_USED) && (defined PWM_EMIOS_1_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if  ((defined PWM_EMIOS_1_CH_9_ISR_USED) && (defined ICU_EMIOS_1_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if  ((defined ICU_EMIOS_1_CH_9_ISR_USED) && (defined GPT_EMIOS_1_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if ( (defined GPT_EMIOS_1_CH_8_ISR_USED) || (defined GPT_EMIOS_1_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_8_ISR_USED) || (defined PWM_EMIOS_1_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_8_ISR_USED) || (defined ICU_EMIOS_1_CH_9_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 8 and 9 for eMios_1 module
* @details   Process the interrupt of eMios channels 8 and 9
*
* @note   This will be defined only if eMios channels 8 or 9 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_8_CH_9_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_8_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_8_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_8_ISR_USED) )

    /* Check if match event occured on EMIOS_8 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 8)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_8 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 8)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_8_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_8);
            #endif

            #if(defined PWM_EMIOS_1_CH_8_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_8);
            #endif

            #if(defined ICU_EMIOS_1_CH_8_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_8);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 8),REG_READ32(EMIOS_CSR_ADDR32(1, 8)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_9_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_9_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_9_ISR_USED) )

    /* Check if match event occured on EMIOS_9 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 9)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_9 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 9)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_9_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_9);
            #endif

            #if(defined PWM_EMIOS_1_CH_9_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_9);
            #endif

            #if(defined ICU_EMIOS_1_CH_9_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_9);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 9),REG_READ32(EMIOS_CSR_ADDR32(1, 9)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:10,11 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_10
*/
#if  ((defined GPT_EMIOS_1_CH_10_ISR_USED) && (defined PWM_EMIOS_1_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_10"
#endif

#if  ((defined PWM_EMIOS_1_CH_10_ISR_USED) && (defined ICU_EMIOS_1_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_10"
#endif

#if  ((defined ICU_EMIOS_1_CH_10_ISR_USED) && (defined GPT_EMIOS_1_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_10"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_11
*/
#if  ((defined GPT_EMIOS_1_CH_11_ISR_USED) && (defined PWM_EMIOS_1_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if  ((defined PWM_EMIOS_1_CH_11_ISR_USED) && (defined ICU_EMIOS_1_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if  ((defined ICU_EMIOS_1_CH_11_ISR_USED) && (defined GPT_EMIOS_1_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if ( (defined GPT_EMIOS_1_CH_10_ISR_USED) || (defined GPT_EMIOS_1_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_10_ISR_USED) || (defined PWM_EMIOS_1_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_10_ISR_USED) || (defined ICU_EMIOS_1_CH_11_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 10 and 11 for eMios_1 module
* @details   Process the interrupt of eMios channels 10 and 11
*
* @note     This will be defined only if eMios channels 10 or 11 are configured in GPT, ICU or PWM
*           mode
*/
/*
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_10_CH_11_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_10_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_10_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_10_ISR_USED) )

    /* Check if match event occured on EMIOS_10 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 10)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_10 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 10)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_10_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_10);
            #endif

            #if(defined PWM_EMIOS_1_CH_10_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_10);
            #endif

            #if(defined ICU_EMIOS_1_CH_10_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_10);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 10),REG_READ32(EMIOS_CSR_ADDR32(1, 10)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_11_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_11_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_11_ISR_USED) )

    /* Check if match event occured on EMIOS_11 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 11)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_11 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 11)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_11_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_11);
            #endif

            #if(defined PWM_EMIOS_1_CH_11_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_11);
            #endif

            #if(defined ICU_EMIOS_1_CH_11_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_11);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 11),REG_READ32(EMIOS_CSR_ADDR32(1, 11)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:12,13 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_12
*/
#if  ((defined GPT_EMIOS_1_CH_12_ISR_USED) && (defined PWM_EMIOS_1_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_12"
#endif

#if  ((defined PWM_EMIOS_1_CH_12_ISR_USED) && (defined ICU_EMIOS_1_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_12"
#endif

#if  ((defined ICU_EMIOS_1_CH_12_ISR_USED) && (defined GPT_EMIOS_1_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_12"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_13
*/
#if  ((defined GPT_EMIOS_1_CH_13_ISR_USED) && (defined PWM_EMIOS_1_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if  ((defined PWM_EMIOS_1_CH_13_ISR_USED) && (defined ICU_EMIOS_1_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if  ((defined ICU_EMIOS_1_CH_13_ISR_USED) && (defined GPT_EMIOS_1_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if ( (defined GPT_EMIOS_1_CH_12_ISR_USED) || (defined GPT_EMIOS_1_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_12_ISR_USED) || (defined PWM_EMIOS_1_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_12_ISR_USED) || (defined ICU_EMIOS_1_CH_13_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 12 and 13 for eMios_1 module
* @details   Process the interrupt of eMios channels 12 and 13
*
* @note   This will be defined only if eMios channels 12 or 13 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_12_CH_13_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_12_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_12_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_12_ISR_USED) )

    /* Check if match event occured on EMIOS_12 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 12)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_12 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 12)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_12_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_12);
            #endif

            #if(defined PWM_EMIOS_1_CH_12_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_12);
            #endif

            #if(defined ICU_EMIOS_1_CH_12_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_12);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 12),REG_READ32(EMIOS_CSR_ADDR32(1, 12)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_13_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_13_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_13_ISR_USED) )

    /* Check if match event occured on EMIOS_13 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 13)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_13 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 13)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_13_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_13);
            #endif

            #if(defined PWM_EMIOS_1_CH_13_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_13);
            #endif

            #if(defined ICU_EMIOS_1_CH_13_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_13);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 13),REG_READ32(EMIOS_CSR_ADDR32(1, 13)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:14,15 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_14
*/
#if  ((defined GPT_EMIOS_1_CH_14_ISR_USED) && (defined PWM_EMIOS_1_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_14"
#endif

#if  ((defined PWM_EMIOS_1_CH_14_ISR_USED) && (defined ICU_EMIOS_1_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_14"
#endif

#if  ((defined ICU_EMIOS_1_CH_14_ISR_USED) && (defined GPT_EMIOS_1_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_14"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_15
*/
#if  ((defined GPT_EMIOS_1_CH_15_ISR_USED) && (defined PWM_EMIOS_1_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if  ((defined PWM_EMIOS_1_CH_15_ISR_USED) && (defined ICU_EMIOS_1_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if  ((defined ICU_EMIOS_1_CH_15_ISR_USED) && (defined GPT_EMIOS_1_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if ( (defined GPT_EMIOS_1_CH_14_ISR_USED) || (defined GPT_EMIOS_1_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_14_ISR_USED) || (defined PWM_EMIOS_1_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_14_ISR_USED) || (defined ICU_EMIOS_1_CH_15_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 14 and 15 for eMios_1 module
* @details   Process the interrupt of eMios channels 14 and 15
*
* @note   This will be defined only if eMios channels 14 or 15 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_14_CH_15_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_14_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_14_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_14_ISR_USED) )

    /* Check if match event occured on EMIOS_14 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 14)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_14 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 14)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_14_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_14);
            #endif

            #if(defined PWM_EMIOS_1_CH_14_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_14);
            #endif

            #if(defined ICU_EMIOS_1_CH_14_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_14);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 14),REG_READ32(EMIOS_CSR_ADDR32(1, 14)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_15_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_15_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_15_ISR_USED) )

    /* Check if match event occured on EMIOS_15 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 15)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_15 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 15)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_15_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_15);
            #endif

            #if(defined PWM_EMIOS_1_CH_15_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_15);
            #endif

            #if(defined ICU_EMIOS_1_CH_15_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_15);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 15),REG_READ32(EMIOS_CSR_ADDR32(1, 15)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:16,17 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_16
*/
#if  ((defined GPT_EMIOS_1_CH_16_ISR_USED) && (defined PWM_EMIOS_1_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_16"
#endif

#if  ((defined PWM_EMIOS_1_CH_16_ISR_USED) && (defined ICU_EMIOS_1_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_16"
#endif

#if  ((defined ICU_EMIOS_1_CH_16_ISR_USED) && (defined GPT_EMIOS_1_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_16"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_17
*/
#if  ((defined GPT_EMIOS_1_CH_17_ISR_USED) && (defined PWM_EMIOS_1_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if  ((defined PWM_EMIOS_1_CH_17_ISR_USED) && (defined ICU_EMIOS_1_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if  ((defined ICU_EMIOS_1_CH_17_ISR_USED) && (defined GPT_EMIOS_1_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if ( (defined GPT_EMIOS_1_CH_16_ISR_USED) || (defined GPT_EMIOS_1_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_16_ISR_USED) || (defined PWM_EMIOS_1_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_16_ISR_USED) || (defined ICU_EMIOS_1_CH_17_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 16 and 17 for eMios_1 module
* @details   Process the interrupt of eMios channels 16 and 17
*
* @note   This will be defined only if eMios channels 16 or 17 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_16_CH_17_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_16_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_16_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_16_ISR_USED) )

    /* Check if match event occured on EMIOS_16 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 16)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_16 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 16)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_16_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_16);
            #endif

            #if(defined PWM_EMIOS_1_CH_16_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_16);
            #endif

            #if(defined ICU_EMIOS_1_CH_16_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_16);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 16),REG_READ32(EMIOS_CSR_ADDR32(1, 16)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_17_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_17_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_17_ISR_USED) )

    /* Check if match event occured on EMIOS_17 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 17)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_17 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 17)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_17_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_17);
            #endif

            #if(defined PWM_EMIOS_1_CH_17_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_17);
            #endif

            #if(defined ICU_EMIOS_1_CH_17_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_17);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 17),REG_READ32(EMIOS_CSR_ADDR32(1, 17)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer
     **@violates @ref eMios_Common_c_4 Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:18,19 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_18
*/
#if  ((defined GPT_EMIOS_1_CH_18_ISR_USED) && (defined PWM_EMIOS_1_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_18"
#endif

#if  ((defined PWM_EMIOS_1_CH_18_ISR_USED) && (defined ICU_EMIOS_1_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_18"
#endif

#if  ((defined ICU_EMIOS_1_CH_18_ISR_USED) && (defined GPT_EMIOS_1_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_18"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_19
*/
#if  ((defined GPT_EMIOS_1_CH_19_ISR_USED) && (defined PWM_EMIOS_1_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if  ((defined PWM_EMIOS_1_CH_19_ISR_USED) && (defined ICU_EMIOS_1_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if  ((defined ICU_EMIOS_1_CH_19_ISR_USED) && (defined GPT_EMIOS_1_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if ( (defined GPT_EMIOS_1_CH_18_ISR_USED) || (defined GPT_EMIOS_1_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_18_ISR_USED) || (defined PWM_EMIOS_1_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_18_ISR_USED) || (defined ICU_EMIOS_1_CH_19_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 18 and 19 for eMios_1 module
* @details   Process the interrupt of eMios channels 18 and 19
*
* @note   This will be defined only if eMios channels 18 or 19 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_18_CH_19_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_18_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_18_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_18_ISR_USED) )

    /* Check if match event occured on EMIOS_18 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 18)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_18 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 18)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_18_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_18);
            #endif

            #if(defined PWM_EMIOS_1_CH_18_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_18);
            #endif

            #if(defined ICU_EMIOS_1_CH_18_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_18);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 18),REG_READ32(EMIOS_CSR_ADDR32(1, 18)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_19_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_19_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_19_ISR_USED) )

    /* Check if match event occured on EMIOS_19 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 19)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_19 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 19)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_19_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_19);
            #endif

            #if(defined PWM_EMIOS_1_CH_19_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_19);
            #endif

            #if(defined ICU_EMIOS_1_CH_19_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_19);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 19),REG_READ32(EMIOS_CSR_ADDR32(1, 19)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:20,21 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_20
*/
#if  ((defined GPT_EMIOS_1_CH_20_ISR_USED) && (defined PWM_EMIOS_1_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_20"
#endif

#if  ((defined PWM_EMIOS_1_CH_20_ISR_USED) && (defined ICU_EMIOS_1_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_20"
#endif

#if  ((defined ICU_EMIOS_1_CH_20_ISR_USED) && (defined GPT_EMIOS_1_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_20"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_21
*/
#if  ((defined GPT_EMIOS_1_CH_21_ISR_USED) && (defined PWM_EMIOS_1_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if  ((defined PWM_EMIOS_1_CH_21_ISR_USED) && (defined ICU_EMIOS_1_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if  ((defined ICU_EMIOS_1_CH_21_ISR_USED) && (defined GPT_EMIOS_1_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if ( (defined GPT_EMIOS_1_CH_20_ISR_USED) || (defined GPT_EMIOS_1_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_20_ISR_USED) || (defined PWM_EMIOS_1_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_20_ISR_USED) || (defined ICU_EMIOS_1_CH_21_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 20 and 21 for eMios_1 module
* @details   Process the interrupt of eMios channels 20 and 21
*
* @note   This will be defined only if eMios channels 20 or 21 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_20_CH_21_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_20_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_20_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_20_ISR_USED) )

    /* Check if match event occured on EMIOS_20 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 20)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_20 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 20)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_20_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_20);
            #endif

            #if(defined PWM_EMIOS_1_CH_20_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_20);
            #endif

            #if(defined ICU_EMIOS_1_CH_20_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_20);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 20),REG_READ32(EMIOS_CSR_ADDR32(1, 20)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_21_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_21_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_21_ISR_USED) )

    /* Check if match event occured on EMIOS_21 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 21)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_21 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 21)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_21_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_21);
            #endif

            #if(defined PWM_EMIOS_1_CH_21_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_21);
            #endif

            #if(defined ICU_EMIOS_1_CH_21_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_21);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 21),REG_READ32(EMIOS_CSR_ADDR32(1, 21)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:22,23 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_22
*/
#if  ((defined GPT_EMIOS_1_CH_22_ISR_USED) && (defined PWM_EMIOS_1_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_22"
#endif

#if  ((defined PWM_EMIOS_1_CH_22_ISR_USED) && (defined ICU_EMIOS_1_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_22"
#endif

#if  ((defined ICU_EMIOS_1_CH_22_ISR_USED) && (defined GPT_EMIOS_1_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_22"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_23
*/
#if  ((defined GPT_EMIOS_1_CH_23_ISR_USED) && (defined PWM_EMIOS_1_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if  ((defined PWM_EMIOS_1_CH_23_ISR_USED) && (defined ICU_EMIOS_1_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if  ((defined ICU_EMIOS_1_CH_23_ISR_USED) && (defined GPT_EMIOS_1_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if ( (defined GPT_EMIOS_1_CH_22_ISR_USED) || (defined GPT_EMIOS_1_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_22_ISR_USED) || (defined PWM_EMIOS_1_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_22_ISR_USED) || (defined ICU_EMIOS_1_CH_23_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 22 and 23 for eMios_1 module
* @details   Process the interrupt of eMios channels 22 and 23
*
* @note   This will be defined only if eMios channels 22 or 23 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_22_CH_23_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_22_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_22_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_22_ISR_USED) )

    /* Check if match event occured on EMIOS_22 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 22)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_22 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 22)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_22_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_22);
            #endif

            #if(defined PWM_EMIOS_1_CH_22_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_22);
            #endif

            #if(defined ICU_EMIOS_1_CH_22_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_22);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 22),REG_READ32(EMIOS_CSR_ADDR32(1, 22)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_23_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_23_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_23_ISR_USED) )

    /* Check if match event occured on EMIOS_23 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 23)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_23 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 23)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_23_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_23);
            #endif

            #if(defined PWM_EMIOS_1_CH_23_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_23);
            #endif

            #if(defined ICU_EMIOS_1_CH_23_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_23);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 23),REG_READ32(EMIOS_CSR_ADDR32(1, 23)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:24,25 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_24
*/
#if  ((defined GPT_EMIOS_1_CH_24_ISR_USED) && (defined PWM_EMIOS_1_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_24"
#endif

#if  ((defined PWM_EMIOS_1_CH_24_ISR_USED) && (defined ICU_EMIOS_1_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_24"
#endif

#if  ((defined ICU_EMIOS_1_CH_24_ISR_USED) && (defined GPT_EMIOS_1_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_24"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_25
*/
#if  ((defined GPT_EMIOS_1_CH_25_ISR_USED) && (defined PWM_EMIOS_1_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if  ((defined PWM_EMIOS_1_CH_25_ISR_USED) && (defined ICU_EMIOS_1_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if  ((defined ICU_EMIOS_1_CH_25_ISR_USED) && (defined GPT_EMIOS_1_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if ( (defined GPT_EMIOS_1_CH_24_ISR_USED) || (defined GPT_EMIOS_1_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_24_ISR_USED) || (defined PWM_EMIOS_1_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_24_ISR_USED) || (defined ICU_EMIOS_1_CH_25_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 24 and 25 for eMios_1 module
* @details   Process the interrupt of eMios channels 24 and 25
*
* @note   This will be defined only if eMios channels 24 or 25 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_24_CH_25_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_24_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_24_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_24_ISR_USED) )

    /* Check if match event occured on EMIOS_24 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 24)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_24 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 24)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_24_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_24);
            #endif

            #if(defined PWM_EMIOS_1_CH_24_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_24);
            #endif

            #if(defined ICU_EMIOS_1_CH_24_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_24);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 24),REG_READ32(EMIOS_CSR_ADDR32(1, 24)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_25_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_25_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_25_ISR_USED) )

    /* Check if match event occured on EMIOS_25 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 25)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_25 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 25)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_25_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_25);
            #endif

            #if(defined PWM_EMIOS_1_CH_25_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_25);
            #endif

            #if(defined ICU_EMIOS_1_CH_25_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_25);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 25),REG_READ32(EMIOS_CSR_ADDR32(1, 25)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:26,27 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_26
*/
#if  ((defined GPT_EMIOS_1_CH_26_ISR_USED) && (defined PWM_EMIOS_1_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_26"
#endif

#if  ((defined PWM_EMIOS_1_CH_26_ISR_USED) && (defined ICU_EMIOS_1_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_26"
#endif

#if  ((defined ICU_EMIOS_1_CH_26_ISR_USED) && (defined GPT_EMIOS_1_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_26"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_27
*/
#if  ((defined GPT_EMIOS_1_CH_27_ISR_USED) && (defined PWM_EMIOS_1_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if  ((defined PWM_EMIOS_1_CH_27_ISR_USED) && (defined ICU_EMIOS_1_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if  ((defined ICU_EMIOS_1_CH_27_ISR_USED) && (defined GPT_EMIOS_1_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if ( (defined GPT_EMIOS_1_CH_26_ISR_USED) || (defined GPT_EMIOS_1_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_26_ISR_USED) || (defined PWM_EMIOS_1_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_26_ISR_USED) || (defined ICU_EMIOS_1_CH_27_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 26 and 27 for eMios_1 module
* @details   Process the interrupt of eMios channels 26 and 27
*
* @note   This will be defined only if eMios channels 26 or 27 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_26_CH_27_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_26_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_26_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_26_ISR_USED) )

    /* Check if match event occured on EMIOS_26 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 26)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_26 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 26)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_26_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_26);
            #endif

            #if(defined PWM_EMIOS_1_CH_26_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_26);
            #endif

            #if(defined ICU_EMIOS_1_CH_26_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_26);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 26),REG_READ32(EMIOS_CSR_ADDR32(1, 26)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_27_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_27_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_27_ISR_USED) )

    /* Check if match event occured on EMIOS_27 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 27)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_27 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 27)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_27_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_27);
            #endif

            #if(defined PWM_EMIOS_1_CH_27_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_27);
            #endif

            #if(defined ICU_EMIOS_1_CH_27_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_27);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 27),REG_READ32(EMIOS_CSR_ADDR32(1, 27)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:28,29 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_28
*/
#if  ((defined GPT_EMIOS_1_CH_28_ISR_USED) && (defined PWM_EMIOS_1_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_28"
#endif

#if  ((defined PWM_EMIOS_1_CH_28_ISR_USED) && (defined ICU_EMIOS_1_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_28"
#endif

#if  ((defined ICU_EMIOS_1_CH_28_ISR_USED) && (defined GPT_EMIOS_1_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_28"
#endif


/*
* @brief resource conflict check for EMIOS_1_CH_29
*/
#if  ((defined GPT_EMIOS_1_CH_29_ISR_USED) && (defined PWM_EMIOS_1_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if  ((defined PWM_EMIOS_1_CH_29_ISR_USED) && (defined ICU_EMIOS_1_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if  ((defined ICU_EMIOS_1_CH_29_ISR_USED) && (defined GPT_EMIOS_1_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if ( (defined GPT_EMIOS_1_CH_28_ISR_USED) || (defined GPT_EMIOS_1_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_28_ISR_USED) || (defined PWM_EMIOS_1_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_28_ISR_USED) || (defined ICU_EMIOS_1_CH_29_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 28 and 29 for eMios_1 module
* @details   Process the interrupt of eMios channels 28 and 29
*
* @note   This will be defined only if eMios channels 28 or 29 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_28_CH_29_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_28_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_28_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_28_ISR_USED) )

    /* Check if match event occured on EMIOS_28 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 28)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_28 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 28)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_28_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_28);
            #endif

            #if(defined PWM_EMIOS_1_CH_28_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_28);
            #endif

            #if(defined ICU_EMIOS_1_CH_28_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_28);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 28),REG_READ32(EMIOS_CSR_ADDR32(1, 28)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_29_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_29_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_29_ISR_USED) )

    /* Check if match event occured on EMIOS_29 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 29)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_29 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 29)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_29_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_29);
            #endif

            #if(defined PWM_EMIOS_1_CH_29_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_29);
            #endif

            #if(defined ICU_EMIOS_1_CH_29_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_29);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 29),REG_READ32(EMIOS_CSR_ADDR32(1, 29)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channels:30,31 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_1_CH_30
*/
#if  ((defined GPT_EMIOS_1_CH_30_ISR_USED) && (defined PWM_EMIOS_1_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

#if  ((defined PWM_EMIOS_1_CH_30_ISR_USED) && (defined ICU_EMIOS_1_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

#if  ((defined ICU_EMIOS_1_CH_30_ISR_USED) && (defined GPT_EMIOS_1_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

/*
* @brief resource conflict check for EMIOS_1_CH_31
*/
#if  ((defined GPT_EMIOS_1_CH_31_ISR_USED) && (defined PWM_EMIOS_1_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if  ((defined PWM_EMIOS_1_CH_31_ISR_USED) && (defined ICU_EMIOS_1_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if  ((defined ICU_EMIOS_1_CH_31_ISR_USED) && (defined GPT_EMIOS_1_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if ( (defined GPT_EMIOS_1_CH_30_ISR_USED) || (defined GPT_EMIOS_1_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_30_ISR_USED) || (defined PWM_EMIOS_1_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_30_ISR_USED) || (defined ICU_EMIOS_1_CH_31_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 30 and 31 for eMios_1 module
* @details   Process the interrupt of eMios channels 30 and 31
*
* @note   This will be defined only if eMios channels 30 or 31 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_30_CH_31_ISR)
{
     #if ( (defined GPT_EMIOS_1_CH_30_ISR_USED) || \
           (defined PWM_EMIOS_1_CH_30_ISR_USED) || \
           (defined ICU_EMIOS_1_CH_30_ISR_USED) )

    /* Check if match event occured on EMIOS_30 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 30)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_30 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 30)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_30_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_30);
            #endif

            #if(defined PWM_EMIOS_1_CH_30_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_30);
            #endif

            #if(defined ICU_EMIOS_1_CH_30_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_30);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 30),REG_READ32(EMIOS_CSR_ADDR32(1, 30)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_1_CH_31_ISR_USED) || \
          (defined PWM_EMIOS_1_CH_31_ISR_USED) || \
          (defined ICU_EMIOS_1_CH_31_ISR_USED) )

    /* Check if match event occured on EMIOS_31 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(1, 31)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_31 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(1, 31)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_1_CH_31_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_31);
            #endif

            #if(defined PWM_EMIOS_1_CH_31_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_31);
            #endif

            #if(defined ICU_EMIOS_1_CH_31_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_31);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(1, 31),REG_READ32(EMIOS_CSR_ADDR32(1, 31)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif



/*********************************** EMIOS 1 common interrupts END ********************************/


/********************************** EMIOS 2 common interrupts START ********************************/
/*
* @brief EMIOS module:2 channels:0,1 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_0
*/
#if  ((defined GPT_EMIOS_2_CH_0_ISR_USED) && (defined PWM_EMIOS_2_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_0"
#endif

#if  ((defined PWM_EMIOS_2_CH_0_ISR_USED) && (defined ICU_EMIOS_2_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_0"
#endif

#if  ((defined ICU_EMIOS_2_CH_0_ISR_USED) && (defined GPT_EMIOS_2_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_0"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_1
*/
#if  ((defined GPT_EMIOS_2_CH_1_ISR_USED) && (defined PWM_EMIOS_2_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if  ((defined PWM_EMIOS_2_CH_1_ISR_USED) && (defined ICU_EMIOS_2_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if  ((defined ICU_EMIOS_2_CH_1_ISR_USED) && (defined GPT_EMIOS_2_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if ( (defined GPT_EMIOS_2_CH_0_ISR_USED) || (defined GPT_EMIOS_2_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_0_ISR_USED) || (defined PWM_EMIOS_2_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_0_ISR_USED) || (defined ICU_EMIOS_2_CH_1_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 0 and 1 for eMios_2 module
* @details   Process the interrupt of eMios channels 0 and 1
* @note   This will be defined only if eMios channels 0 or 1 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_0_CH_1_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_0_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_0_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_0_ISR_USED) )

    /* Check if match event occured on EMIOS_2 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 0)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_2 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 0)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_0_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_0);
            #endif

            #if(defined PWM_EMIOS_2_CH_0_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_0);
            #endif

            #if(defined ICU_EMIOS_2_CH_0_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_0);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 0),REG_READ32(EMIOS_CSR_ADDR32(2, 0)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_1_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_1_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_1_ISR_USED) )

    /* Check if match event occured on EMIOS_1 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 1)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_1 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 1)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_1_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_1);
            #endif

            #if(defined PWM_EMIOS_2_CH_1_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_1);
            #endif

            #if(defined ICU_EMIOS_2_CH_1_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_1);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 1),REG_READ32(EMIOS_CSR_ADDR32(2, 1)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:2,3 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_2
*/
#if  ((defined GPT_EMIOS_2_CH_2_ISR_USED) && (defined PWM_EMIOS_2_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_2"
#endif

#if  ((defined PWM_EMIOS_2_CH_2_ISR_USED) && (defined ICU_EMIOS_2_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_2"
#endif

#if  ((defined ICU_EMIOS_2_CH_2_ISR_USED) && (defined GPT_EMIOS_2_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_2"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_3
*/
#if  ((defined GPT_EMIOS_2_CH_3_ISR_USED) && (defined PWM_EMIOS_2_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if  ((defined PWM_EMIOS_2_CH_3_ISR_USED) && (defined ICU_EMIOS_2_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if  ((defined ICU_EMIOS_2_CH_3_ISR_USED) && (defined GPT_EMIOS_2_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if ( (defined GPT_EMIOS_2_CH_2_ISR_USED) || (defined GPT_EMIOS_2_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_2_ISR_USED) || (defined PWM_EMIOS_2_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_2_ISR_USED) || (defined ICU_EMIOS_2_CH_3_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 2 and 3 for eMios_2 module
* @details   Process the interrupt of eMios channels 2 and 3
*
* @note   This will be defined only if eMios channels 2 or 3 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_2_CH_3_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_2_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_2_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_2_ISR_USED) )

    /* Check if match event occured on EMIOS_2 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 2)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_2 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 2)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_2_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_2);
            #endif

            #if(defined PWM_EMIOS_2_CH_2_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_2);
            #endif

            #if(defined ICU_EMIOS_2_CH_2_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_2);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 2),REG_READ32(EMIOS_CSR_ADDR32(2, 2)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_3_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_3_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_3_ISR_USED) )

    /* Check if match event occured on EMIOS_3 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 3)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_3 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 3)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_3_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_3);
            #endif

            #if(defined PWM_EMIOS_2_CH_3_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_3);
            #endif

            #if(defined ICU_EMIOS_2_CH_3_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_3);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 3),REG_READ32(EMIOS_CSR_ADDR32(2, 3)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
  /* @violates @ref eMios_Common_c_4 Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:4,5 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_4
*/
#if  ((defined GPT_EMIOS_2_CH_4_ISR_USED) && (defined PWM_EMIOS_2_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_4"
#endif

#if  ((defined PWM_EMIOS_2_CH_4_ISR_USED) && (defined ICU_EMIOS_2_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_4"
#endif

#if  ((defined ICU_EMIOS_2_CH_4_ISR_USED) && (defined GPT_EMIOS_2_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_4"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_5
*/
#if  ((defined GPT_EMIOS_2_CH_5_ISR_USED) && (defined PWM_EMIOS_2_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if  ((defined PWM_EMIOS_2_CH_5_ISR_USED) && (defined ICU_EMIOS_2_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if  ((defined ICU_EMIOS_2_CH_5_ISR_USED) && (defined GPT_EMIOS_2_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if ( (defined GPT_EMIOS_2_CH_4_ISR_USED) || (defined GPT_EMIOS_2_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_4_ISR_USED) || (defined PWM_EMIOS_2_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_4_ISR_USED) || (defined ICU_EMIOS_2_CH_5_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 4 and 5 for eMios_2 module
* @details   Process the interrupt of eMios channels 4 and 5
*
* @note   This will be defined only if eMios channels 4 or 5 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_4_CH_5_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_4_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_4_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_4_ISR_USED) )

    /* Check if match event occured on EMIOS_4 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 4)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_4 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 4)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_4_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_4);
            #endif

            #if(defined PWM_EMIOS_2_CH_4_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_4);
            #endif

            #if(defined ICU_EMIOS_2_CH_4_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_4);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 4),REG_READ32(EMIOS_CSR_ADDR32(2, 4)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_5_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_5_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_5_ISR_USED) )

    /* Check if match event occured on EMIOS_5 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 5)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_5 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 5)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_5_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_5);
            #endif

            #if(defined PWM_EMIOS_2_CH_5_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_5);
            #endif

            #if(defined ICU_EMIOS_2_CH_5_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_5);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 5),REG_READ32(EMIOS_CSR_ADDR32(2, 5)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:6,7 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_6
*/
#if  ((defined GPT_EMIOS_2_CH_6_ISR_USED) && (defined PWM_EMIOS_2_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_6"
#endif

#if  ((defined PWM_EMIOS_2_CH_6_ISR_USED) && (defined ICU_EMIOS_2_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_6"
#endif

#if  ((defined ICU_EMIOS_2_CH_6_ISR_USED) && (defined GPT_EMIOS_2_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_6"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_7
*/
#if  ((defined GPT_EMIOS_2_CH_7_ISR_USED) && (defined PWM_EMIOS_2_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if  ((defined PWM_EMIOS_2_CH_7_ISR_USED) && (defined ICU_EMIOS_2_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if  ((defined ICU_EMIOS_2_CH_7_ISR_USED) && (defined GPT_EMIOS_2_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if ( (defined GPT_EMIOS_2_CH_6_ISR_USED) || (defined GPT_EMIOS_2_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_6_ISR_USED) || (defined PWM_EMIOS_2_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_6_ISR_USED) || (defined ICU_EMIOS_2_CH_7_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 6 and 7 for eMios_2 module
* @details   Process the interrupt of eMios channels 6 and 7
*
* @note   This will be defined only if eMios channels 6 or 7 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_6_CH_7_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_6_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_6_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_6_ISR_USED) )

    /* Check if match event occured on EMIOS_6 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 6)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_6 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 6)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_6_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_6);
            #endif

            #if(defined PWM_EMIOS_2_CH_6_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_6);
            #endif

            #if(defined ICU_EMIOS_2_CH_6_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_6);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 6),REG_READ32(EMIOS_CSR_ADDR32(2, 6)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_7_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_7_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_7_ISR_USED) )

    /* Check if match event occured on EMIOS_7 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 7)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_7 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 7)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_7_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_7);
            #endif

            #if(defined PWM_EMIOS_2_CH_7_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_7);
            #endif

            #if(defined ICU_EMIOS_2_CH_7_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_7);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 7),REG_READ32(EMIOS_CSR_ADDR32(2, 7)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:8,9 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_8
*/
#if  ((defined GPT_EMIOS_2_CH_8_ISR_USED) && (defined PWM_EMIOS_2_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_8"
#endif

#if  ((defined PWM_EMIOS_2_CH_8_ISR_USED) && (defined ICU_EMIOS_2_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_8"
#endif

#if  ((defined ICU_EMIOS_2_CH_8_ISR_USED) && (defined GPT_EMIOS_2_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_8"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_9
*/
#if  ((defined GPT_EMIOS_2_CH_9_ISR_USED) && (defined PWM_EMIOS_2_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if  ((defined PWM_EMIOS_2_CH_9_ISR_USED) && (defined ICU_EMIOS_2_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if  ((defined ICU_EMIOS_2_CH_9_ISR_USED) && (defined GPT_EMIOS_2_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if ( (defined GPT_EMIOS_2_CH_8_ISR_USED) || (defined GPT_EMIOS_2_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_8_ISR_USED) || (defined PWM_EMIOS_2_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_8_ISR_USED) || (defined ICU_EMIOS_2_CH_9_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 8 and 9 for eMios_2 module
* @details   Process the interrupt of eMios channels 8 and 9
* @note   This will be defined only if eMios channels 8 or 9 are configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_8_CH_9_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_8_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_8_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_8_ISR_USED) )

    /* Check if match event occured on EMIOS_8 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 8)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_8 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 8)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_8_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_8);
            #endif

            #if(defined PWM_EMIOS_2_CH_8_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_8);
            #endif

            #if(defined ICU_EMIOS_2_CH_8_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_8);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 8),REG_READ32(EMIOS_CSR_ADDR32(2, 8)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_9_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_9_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_9_ISR_USED) )

    /* Check if match event occured on EMIOS_9 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 9)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_9 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 9)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_9_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_9);
            #endif

            #if(defined PWM_EMIOS_2_CH_9_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_9);
            #endif

            #if(defined ICU_EMIOS_2_CH_9_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_9);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 9),REG_READ32(EMIOS_CSR_ADDR32(2, 9)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer
     **@violates @ref eMios_Common_c_4 Implicit conversion changes signedness */
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:10,11 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_10
*/
#if  ((defined GPT_EMIOS_2_CH_10_ISR_USED) && (defined PWM_EMIOS_2_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_10"
#endif

#if  ((defined PWM_EMIOS_2_CH_10_ISR_USED) && (defined ICU_EMIOS_2_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_10"
#endif

#if  ((defined ICU_EMIOS_2_CH_10_ISR_USED) && (defined GPT_EMIOS_2_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_10"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_11
*/
#if  ((defined GPT_EMIOS_2_CH_11_ISR_USED) && (defined PWM_EMIOS_2_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if  ((defined PWM_EMIOS_2_CH_11_ISR_USED) && (defined ICU_EMIOS_2_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if  ((defined ICU_EMIOS_2_CH_11_ISR_USED) && (defined GPT_EMIOS_2_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if ( (defined GPT_EMIOS_2_CH_10_ISR_USED) || (defined GPT_EMIOS_2_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_10_ISR_USED) || (defined PWM_EMIOS_2_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_10_ISR_USED) || (defined ICU_EMIOS_2_CH_11_ISR_USED) )

/*================================================================================================*/
/**
* @brief    Interrupt handler for eMios channels : 10 and 11 for eMios_2 module
* @details  Process the interrupt of eMios channels 10 and 11
*
*@note      This will be defined only if eMios channels 10 or 11 are configured in GPT, ICU or
*           PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_10_CH_11_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_10_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_10_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_10_ISR_USED) )

    /* Check if match event occured on EMIOS_10 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 10)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_10 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 10)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_10_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_10);
            #endif

            #if(defined PWM_EMIOS_2_CH_10_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_10);
            #endif

            #if(defined ICU_EMIOS_2_CH_10_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_10);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 10),REG_READ32(EMIOS_CSR_ADDR32(2, 10)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_11_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_11_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_11_ISR_USED) )

    /* Check if match event occured on EMIOS_11 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 11)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_11 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 11)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_11_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_11);
            #endif

            #if(defined PWM_EMIOS_2_CH_11_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_11);
            #endif

            #if(defined ICU_EMIOS_2_CH_11_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_11);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 11),REG_READ32(EMIOS_CSR_ADDR32(2, 11)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:12,13 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_12
*/
#if  ((defined GPT_EMIOS_2_CH_12_ISR_USED) && (defined PWM_EMIOS_2_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_12"
#endif

#if  ((defined PWM_EMIOS_2_CH_12_ISR_USED) && (defined ICU_EMIOS_2_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_12"
#endif

#if  ((defined ICU_EMIOS_2_CH_12_ISR_USED) && (defined GPT_EMIOS_2_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_12"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_13
*/
#if  ((defined GPT_EMIOS_2_CH_13_ISR_USED) && (defined PWM_EMIOS_2_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if  ((defined PWM_EMIOS_2_CH_13_ISR_USED) && (defined ICU_EMIOS_2_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if  ((defined ICU_EMIOS_2_CH_13_ISR_USED) && (defined GPT_EMIOS_2_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if ( (defined GPT_EMIOS_2_CH_12_ISR_USED) || (defined GPT_EMIOS_2_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_12_ISR_USED) || (defined PWM_EMIOS_2_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_12_ISR_USED) || (defined ICU_EMIOS_2_CH_13_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 12 and 13 for eMios_2 module
* @details   Process the interrupt of eMios channels 12 and 13
*
* @note     This will be defined only if eMios channels 12 or 13 are configured in GPT, ICU or PWM
*           mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_12_CH_13_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_12_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_12_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_12_ISR_USED) )

    /* Check if match event occured on EMIOS_12 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 12)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_12 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 12)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_12_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_12);
            #endif

            #if(defined PWM_EMIOS_2_CH_12_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_12);
            #endif

            #if(defined ICU_EMIOS_2_CH_12_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_12);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 12),REG_READ32(EMIOS_CSR_ADDR32(2, 12)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_13_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_13_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_13_ISR_USED) )

    /* Check if match event occured on EMIOS_13 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 13)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_13 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 13)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_13_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_13);
            #endif

            #if(defined PWM_EMIOS_2_CH_13_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_13);
            #endif

            #if(defined ICU_EMIOS_2_CH_13_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_13);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 13),REG_READ32(EMIOS_CSR_ADDR32(2, 13)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:14,15 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_14
*/
#if  ((defined GPT_EMIOS_2_CH_14_ISR_USED) && (defined PWM_EMIOS_2_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_14"
#endif

#if  ((defined PWM_EMIOS_2_CH_14_ISR_USED) && (defined ICU_EMIOS_2_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_14"
#endif

#if  ((defined ICU_EMIOS_2_CH_14_ISR_USED) && (defined GPT_EMIOS_2_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_14"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_15
*/
#if  ((defined GPT_EMIOS_2_CH_15_ISR_USED) && (defined PWM_EMIOS_2_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if  ((defined PWM_EMIOS_2_CH_15_ISR_USED) && (defined ICU_EMIOS_2_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if  ((defined ICU_EMIOS_2_CH_15_ISR_USED) && (defined GPT_EMIOS_2_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if ( (defined GPT_EMIOS_2_CH_14_ISR_USED) || (defined GPT_EMIOS_2_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_14_ISR_USED) || (defined PWM_EMIOS_2_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_14_ISR_USED) || (defined ICU_EMIOS_2_CH_15_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 14 and 15 for eMios_2 module
* @details   Process the interrupt of eMios channels 14 and 15
*
* @note     This will be defined only if eMios channels 14 or 15 are configured in GPT, ICU or PWM
*           mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_14_CH_15_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_14_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_14_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_14_ISR_USED) )

    /* Check if match event occured on EMIOS_14 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 14)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_14 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 14)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_14_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_14);
            #endif

            #if(defined PWM_EMIOS_2_CH_14_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_14);
            #endif

            #if(defined ICU_EMIOS_2_CH_14_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_14);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 14),REG_READ32(EMIOS_CSR_ADDR32(2, 14)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_15_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_15_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_15_ISR_USED) )

    /* Check if match event occured on EMIOS_15 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 15)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_15 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 15)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_15_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_15);
            #endif

            #if(defined PWM_EMIOS_2_CH_15_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_15);
            #endif

            #if(defined ICU_EMIOS_2_CH_15_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_15);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 15),REG_READ32(EMIOS_CSR_ADDR32(2, 15)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:16,17 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_16
*/
#if  ((defined GPT_EMIOS_2_CH_16_ISR_USED) && (defined PWM_EMIOS_2_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_16"
#endif

#if  ((defined PWM_EMIOS_2_CH_16_ISR_USED) && (defined ICU_EMIOS_2_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_16"
#endif

#if  ((defined ICU_EMIOS_2_CH_16_ISR_USED) && (defined GPT_EMIOS_2_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_16"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_17
*/
#if  ((defined GPT_EMIOS_2_CH_17_ISR_USED) && (defined PWM_EMIOS_2_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if  ((defined PWM_EMIOS_2_CH_17_ISR_USED) && (defined ICU_EMIOS_2_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if  ((defined ICU_EMIOS_2_CH_17_ISR_USED) && (defined GPT_EMIOS_2_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if ( (defined GPT_EMIOS_2_CH_16_ISR_USED) || (defined GPT_EMIOS_2_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_16_ISR_USED) || (defined PWM_EMIOS_2_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_16_ISR_USED) || (defined ICU_EMIOS_2_CH_17_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 16 and 17 for eMios_2 module
* @details   Process the interrupt of eMios channels 16 and 17

* @note     This will be defined only if eMios channels 16 or 17 are configured in GPT, ICU or PWM
*           mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_16_CH_17_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_16_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_16_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_16_ISR_USED) )

    /* Check if match event occured on EMIOS_16 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 16)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_16 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 16)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_16_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_16);
            #endif

            #if(defined PWM_EMIOS_2_CH_16_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_16);
            #endif

            #if(defined ICU_EMIOS_2_CH_16_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_16);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 16),REG_READ32(EMIOS_CSR_ADDR32(2, 16)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_17_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_17_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_17_ISR_USED) )

    /* Check if match event occured on EMIOS_17 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 17)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_17 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 17)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_17_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_17);
            #endif

            #if(defined PWM_EMIOS_2_CH_17_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_17);
            #endif

            #if(defined ICU_EMIOS_2_CH_17_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_17);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 17),REG_READ32(EMIOS_CSR_ADDR32(2, 17)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:18,19 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_18
*/
#if  ((defined GPT_EMIOS_2_CH_18_ISR_USED) && (defined PWM_EMIOS_2_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_18"
#endif

#if  ((defined PWM_EMIOS_2_CH_18_ISR_USED) && (defined ICU_EMIOS_2_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_18"
#endif

#if  ((defined ICU_EMIOS_2_CH_18_ISR_USED) && (defined GPT_EMIOS_2_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_18"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_19
*/
#if  ((defined GPT_EMIOS_2_CH_19_ISR_USED) && (defined PWM_EMIOS_2_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if  ((defined PWM_EMIOS_2_CH_19_ISR_USED) && (defined ICU_EMIOS_2_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if  ((defined ICU_EMIOS_2_CH_19_ISR_USED) && (defined GPT_EMIOS_2_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if ( (defined GPT_EMIOS_2_CH_18_ISR_USED) || (defined GPT_EMIOS_2_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_18_ISR_USED) || (defined PWM_EMIOS_2_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_18_ISR_USED) || (defined ICU_EMIOS_2_CH_19_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 18 and 19 for eMios_2 module
* @details   Process the interrupt of eMios channels 18 and 19
*
* @note   This will be defined only if eMios channels 18 or 19 are configured in GPT, ICU or PWM
*            mode
*/
/*
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_18_CH_19_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_18_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_18_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_18_ISR_USED) )

    /* Check if match event occured on EMIOS_18 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 18)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_18 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 18)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_18_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_18);
            #endif

            #if(defined PWM_EMIOS_2_CH_18_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_18);
            #endif

            #if(defined ICU_EMIOS_2_CH_18_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_18);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 18),REG_READ32(EMIOS_CSR_ADDR32(2, 18)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_19_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_19_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_19_ISR_USED) )

    /* Check if match event occured on EMIOS_19 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 19)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_19 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 19)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_19_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_19);
            #endif

            #if(defined PWM_EMIOS_2_CH_19_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_19);
            #endif

            #if(defined ICU_EMIOS_2_CH_19_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_19);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 19),REG_READ32(EMIOS_CSR_ADDR32(2, 19)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:20,21 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_20
*/
#if  ((defined GPT_EMIOS_2_CH_20_ISR_USED) && (defined PWM_EMIOS_2_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_20"
#endif

#if  ((defined PWM_EMIOS_2_CH_20_ISR_USED) && (defined ICU_EMIOS_2_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_20"
#endif

#if  ((defined ICU_EMIOS_2_CH_20_ISR_USED) && (defined GPT_EMIOS_2_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_20"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_21
*/
#if  ((defined GPT_EMIOS_2_CH_21_ISR_USED) && (defined PWM_EMIOS_2_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if  ((defined PWM_EMIOS_2_CH_21_ISR_USED) && (defined ICU_EMIOS_2_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if  ((defined ICU_EMIOS_2_CH_21_ISR_USED) && (defined GPT_EMIOS_2_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if ( (defined GPT_EMIOS_2_CH_20_ISR_USED) || (defined GPT_EMIOS_2_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_20_ISR_USED) || (defined PWM_EMIOS_2_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_20_ISR_USED) || (defined ICU_EMIOS_2_CH_21_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 20 and 21 for eMios_2 module
* @details   Process the interrupt of eMios channels 20 and 21
*
* @note   This will be defined only if eMios channels 20 or 21 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_20_CH_21_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_20_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_20_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_20_ISR_USED) )

    /* Check if match event occured on EMIOS_20 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 20)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_20 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 20)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_20_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_20);
            #endif

            #if(defined PWM_EMIOS_2_CH_20_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_20);
            #endif

            #if(defined ICU_EMIOS_2_CH_20_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_20);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 20),REG_READ32(EMIOS_CSR_ADDR32(2, 20)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_21_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_21_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_21_ISR_USED) )

    /* Check if match event occured on EMIOS_21 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 21)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_21 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 21)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_21_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_21);
            #endif

            #if(defined PWM_EMIOS_2_CH_21_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_21);
            #endif

            #if(defined ICU_EMIOS_2_CH_21_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_21);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 21),REG_READ32(EMIOS_CSR_ADDR32(2, 21)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:22,23 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_22
*/
#if  ((defined GPT_EMIOS_2_CH_22_ISR_USED) && (defined PWM_EMIOS_2_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_22"
#endif

#if  ((defined PWM_EMIOS_2_CH_22_ISR_USED) && (defined ICU_EMIOS_2_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_22"
#endif

#if  ((defined ICU_EMIOS_2_CH_22_ISR_USED) && (defined GPT_EMIOS_2_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_22"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_23
*/
#if  ((defined GPT_EMIOS_2_CH_23_ISR_USED) && (defined PWM_EMIOS_2_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if  ((defined PWM_EMIOS_2_CH_23_ISR_USED) && (defined ICU_EMIOS_2_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if  ((defined ICU_EMIOS_2_CH_23_ISR_USED) && (defined GPT_EMIOS_2_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if ( (defined GPT_EMIOS_2_CH_22_ISR_USED) || (defined GPT_EMIOS_2_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_22_ISR_USED) || (defined PWM_EMIOS_2_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_22_ISR_USED) || (defined ICU_EMIOS_2_CH_23_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 22 and 23 for eMios_2 module
* @details   Process the interrupt of eMios channels 22 and 23
*
* @note   This will be defined only if eMios channels 22 or 23 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_22_CH_23_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_22_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_22_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_22_ISR_USED) )

    /* Check if match event occured on EMIOS_22 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 22)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_22 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 22)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_22_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_22);
            #endif

            #if(defined PWM_EMIOS_2_CH_22_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_22);
            #endif

            #if(defined ICU_EMIOS_2_CH_22_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_22);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 22),REG_READ32(EMIOS_CSR_ADDR32(2, 22)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_23_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_23_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_23_ISR_USED) )

    /* Check if match event occured on EMIOS_23 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 23)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_23 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 23)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_23_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_23);
            #endif

            #if(defined PWM_EMIOS_2_CH_23_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_23);
            #endif

            #if(defined ICU_EMIOS_2_CH_23_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_23);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 23),REG_READ32(EMIOS_CSR_ADDR32(2, 23)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:24,25 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_24
*/
#if  ((defined GPT_EMIOS_2_CH_24_ISR_USED) && (defined PWM_EMIOS_2_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_24"
#endif

#if  ((defined PWM_EMIOS_2_CH_24_ISR_USED) && (defined ICU_EMIOS_2_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_24"
#endif

#if  ((defined ICU_EMIOS_2_CH_24_ISR_USED) && (defined GPT_EMIOS_2_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_24"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_25
*/
#if  ((defined GPT_EMIOS_2_CH_25_ISR_USED) && (defined PWM_EMIOS_2_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if  ((defined PWM_EMIOS_2_CH_25_ISR_USED) && (defined ICU_EMIOS_2_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if  ((defined ICU_EMIOS_2_CH_25_ISR_USED) && (defined GPT_EMIOS_2_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if ( (defined GPT_EMIOS_2_CH_24_ISR_USED) || (defined GPT_EMIOS_2_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_24_ISR_USED) || (defined PWM_EMIOS_2_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_24_ISR_USED) || (defined ICU_EMIOS_2_CH_25_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 24 and 25 for eMios_2 module
* @details   Process the interrupt of eMios channels 24 and 25
*
* @note   This will be defined only if eMios channels 24 or 25 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_24_CH_25_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_24_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_24_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_24_ISR_USED) )

    /* Check if match event occured on EMIOS_24 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 24)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_24 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 24)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_24_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_24);
            #endif

            #if(defined PWM_EMIOS_2_CH_24_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_24);
            #endif

            #if(defined ICU_EMIOS_2_CH_24_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_24);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 24),REG_READ32(EMIOS_CSR_ADDR32(2, 24)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_25_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_25_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_25_ISR_USED) )

    /* Check if match event occured on EMIOS_25 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 25)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_25 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 25)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_25_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_25);
            #endif

            #if(defined PWM_EMIOS_2_CH_25_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_25);
            #endif

            #if(defined ICU_EMIOS_2_CH_25_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_25);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 25),REG_READ32(EMIOS_CSR_ADDR32(2, 25)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:26,27 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_26
*/
#if  ((defined GPT_EMIOS_2_CH_26_ISR_USED) && (defined PWM_EMIOS_2_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_26"
#endif

#if  ((defined PWM_EMIOS_2_CH_26_ISR_USED) && (defined ICU_EMIOS_2_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_26"
#endif

#if  ((defined ICU_EMIOS_2_CH_26_ISR_USED) && (defined GPT_EMIOS_2_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_26"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_27
*/
#if  ((defined GPT_EMIOS_2_CH_27_ISR_USED) && (defined PWM_EMIOS_2_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if  ((defined PWM_EMIOS_2_CH_27_ISR_USED) && (defined ICU_EMIOS_2_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if  ((defined ICU_EMIOS_2_CH_27_ISR_USED) && (defined GPT_EMIOS_2_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if ( (defined GPT_EMIOS_2_CH_26_ISR_USED) || (defined GPT_EMIOS_2_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_26_ISR_USED) || (defined PWM_EMIOS_2_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_26_ISR_USED) || (defined ICU_EMIOS_2_CH_27_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 26 and 27 for eMios_2 module
* @details   Process the interrupt of eMios channels 26 and 27
*
* @note   This will be defined only if eMios channels 26 or 27 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_26_CH_27_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_26_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_26_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_26_ISR_USED) )

    /* Check if match event occured on EMIOS_26 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 26)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_26 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 26)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_26_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_26);
            #endif

            #if(defined PWM_EMIOS_2_CH_26_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_26);
            #endif

            #if(defined ICU_EMIOS_2_CH_26_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_26);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 26),REG_READ32(EMIOS_CSR_ADDR32(2, 26)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_27_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_27_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_27_ISR_USED) )

    /* Check if match event occured on EMIOS_27 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 27)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_27 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 27)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_27_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_27);
            #endif

            #if(defined PWM_EMIOS_2_CH_27_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_27);
            #endif

            #if(defined ICU_EMIOS_2_CH_27_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_27);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 27),REG_READ32(EMIOS_CSR_ADDR32(2, 27)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:28,29 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_28
*/
#if  ((defined GPT_EMIOS_2_CH_28_ISR_USED) && (defined PWM_EMIOS_2_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_28"
#endif

#if  ((defined PWM_EMIOS_2_CH_28_ISR_USED) && (defined ICU_EMIOS_2_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_28"
#endif

#if  ((defined ICU_EMIOS_2_CH_28_ISR_USED) && (defined GPT_EMIOS_2_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_28"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_29
*/
#if  ((defined GPT_EMIOS_2_CH_29_ISR_USED) && (defined PWM_EMIOS_2_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if  ((defined PWM_EMIOS_2_CH_29_ISR_USED) && (defined ICU_EMIOS_2_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if  ((defined ICU_EMIOS_2_CH_29_ISR_USED) && (defined GPT_EMIOS_2_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if ( (defined GPT_EMIOS_2_CH_28_ISR_USED) || (defined GPT_EMIOS_2_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_28_ISR_USED) || (defined PWM_EMIOS_2_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_28_ISR_USED) || (defined ICU_EMIOS_2_CH_29_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 28 and 29 for eMios_2 module
* @details   Process the interrupt of eMios channels 28 and 29
*
* @note   This will be defined only if eMios channels 28 or 29 are configured in GPT, ICU or PWM
*         mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_28_CH_29_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_28_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_28_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_28_ISR_USED) )

    /* Check if match event occured on EMIOS_28 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 28)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_28 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 28)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_28_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_28);
            #endif

            #if(defined PWM_EMIOS_2_CH_28_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_28);
            #endif

            #if(defined ICU_EMIOS_2_CH_28_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_28);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 28),REG_READ32(EMIOS_CSR_ADDR32(2, 28)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_29_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_29_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_29_ISR_USED) )

    /* Check if match event occured on EMIOS_29 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 29)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_29 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 29)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_29_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_29);
            #endif

            #if(defined PWM_EMIOS_2_CH_29_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_29);
            #endif

            #if(defined ICU_EMIOS_2_CH_29_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_29);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 29),REG_READ32(EMIOS_CSR_ADDR32(2, 29)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channels:30,31 common interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_30
*/
#if  ((defined GPT_EMIOS_2_CH_30_ISR_USED) && (defined PWM_EMIOS_2_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_30"
#endif

#if  ((defined PWM_EMIOS_2_CH_30_ISR_USED) && (defined ICU_EMIOS_2_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_30"
#endif

#if  ((defined ICU_EMIOS_2_CH_30_ISR_USED) && (defined GPT_EMIOS_2_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_30"
#endif


/*
* @brief resource conflict check for EMIOS_2_CH_31
*/
#if  ((defined GPT_EMIOS_2_CH_31_ISR_USED) && (defined PWM_EMIOS_2_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if  ((defined PWM_EMIOS_2_CH_31_ISR_USED) && (defined ICU_EMIOS_2_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if  ((defined ICU_EMIOS_2_CH_31_ISR_USED) && (defined GPT_EMIOS_2_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if ( (defined GPT_EMIOS_2_CH_30_ISR_USED) || (defined GPT_EMIOS_2_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_30_ISR_USED) || (defined PWM_EMIOS_2_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_30_ISR_USED) || (defined ICU_EMIOS_2_CH_31_ISR_USED) )

/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channels : 30 and 31 for eMios_2 module
* @details   Process the interrupt of eMios channels 30 and 31
*
* @note   This will be defined only if eMios channels 30 or 31 are configured in GPT, ICU or PWM
*         mode
*/
/*
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_30_CH_31_ISR)
{
     #if ( (defined GPT_EMIOS_2_CH_30_ISR_USED) || \
           (defined PWM_EMIOS_2_CH_30_ISR_USED) || \
           (defined ICU_EMIOS_2_CH_30_ISR_USED) )

    /* Check if match event occured on EMIOS_30 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 30)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_30 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 30)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_30_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_30);
            #endif

            #if(defined PWM_EMIOS_2_CH_30_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_30);
            #endif

            #if(defined ICU_EMIOS_2_CH_30_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_30);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 30),REG_READ32(EMIOS_CSR_ADDR32(2, 30)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    #if ( (defined GPT_EMIOS_2_CH_31_ISR_USED) || \
          (defined PWM_EMIOS_2_CH_31_ISR_USED) || \
          (defined ICU_EMIOS_2_CH_31_ISR_USED) )

    /* Check if match event occured on EMIOS_31 */
    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    if ( ( REG_READ32(EMIOS_CSR_ADDR32(2, 31)) & CSR_FLAG_MASK_U32) != 0U )
    {
        /* Check that a match event generates an interrupt and interrupts are enabled for EMIOS_31 */
        /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
        if ( (REG_READ32(EMIOS_CCR_ADDR32(2, 31)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
            ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT )))
        {
            #if(defined GPT_EMIOS_2_CH_31_ISR_USED)
                Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_31);
            #endif

            #if(defined PWM_EMIOS_2_CH_31_ISR_USED)
                Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_31);
            #endif

            #if(defined ICU_EMIOS_2_CH_31_ISR_USED)
                Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_31);
            #endif
        }
        else
        {
            REG_WRITE32(EMIOS_CSR_ADDR32(2, 31),REG_READ32(EMIOS_CSR_ADDR32(2, 31)) & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32));
        }
    }
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif

/*********************************** EMIOS 2 common interrupts END ********************************/

#else  /* EMIOS_COMMON_ISR_HANDLER == STD_OFF */
/*================================================================================================*/
/*                     CHANNEL INDEPENDENT EMIOS INTERRUPT SERVICE ROUTINES DEFINITION            */
/*================================================================================================*/
/*********************************** EMIOS 0 independent interrupts START *************************/
/*
* @brief EMIOS module:0 channel:0 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_0
*/
#if  ((defined GPT_EMIOS_0_CH_0_ISR_USED) && (defined PWM_EMIOS_0_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_0"
#endif

#if  ((defined PWM_EMIOS_0_CH_0_ISR_USED) && (defined ICU_EMIOS_0_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_0"
#endif

#if  ((defined ICU_EMIOS_0_CH_0_ISR_USED) && (defined GPT_EMIOS_0_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_0"
#endif


#if ( (defined GPT_EMIOS_0_CH_0_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_0_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_0_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 0 for eMios_0 module
* @details   Process the interrupt of eMios channel 0
*
* @note   This will be defined only if eMios channel 0 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_0_ISR)
{

    #if(defined GPT_EMIOS_0_CH_0_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_0);
    #endif

    #if(defined PWM_EMIOS_0_CH_0_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_0);
    #endif

    #if(defined ICU_EMIOS_0_CH_0_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_0);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:1 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_1
*/
#if  ((defined GPT_EMIOS_0_CH_1_ISR_USED) && (defined PWM_EMIOS_0_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if  ((defined PWM_EMIOS_0_CH_1_ISR_USED) && (defined ICU_EMIOS_0_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_1"
#endif

#if  ((defined ICU_EMIOS_0_CH_1_ISR_USED) && (defined GPT_EMIOS_0_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_1"
#endif


#if ( (defined GPT_EMIOS_0_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_1_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 1 for eMios_0 module
* @details   Process the interrupt of eMios channel 1
*
* @note   This will be defined only if eMios channel 1 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_1_ISR)
{

    #if(defined GPT_EMIOS_0_CH_1_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_1);
    #endif

    #if(defined PWM_EMIOS_0_CH_1_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_1);
    #endif

    #if(defined ICU_EMIOS_0_CH_1_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_1);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:2 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_2
*/
#if  ((defined GPT_EMIOS_0_CH_2_ISR_USED) && (defined PWM_EMIOS_0_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_2"
#endif

#if  ((defined PWM_EMIOS_0_CH_2_ISR_USED) && (defined ICU_EMIOS_0_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_2"
#endif

#if  ((defined ICU_EMIOS_0_CH_2_ISR_USED) && (defined GPT_EMIOS_0_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_2"
#endif


#if ( (defined GPT_EMIOS_0_CH_2_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_2_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_2_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 2 for eMios_0 module
* @details   Process the interrupt of eMios channel 2
*
* @note   This will be defined only if eMios channel 2 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_2_ISR)
{

    #if(defined GPT_EMIOS_0_CH_2_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_2);
    #endif

    #if(defined PWM_EMIOS_0_CH_2_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_2);
    #endif

    #if(defined ICU_EMIOS_0_CH_2_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_2);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:3 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_3
*/
#if  ((defined GPT_EMIOS_0_CH_3_ISR_USED) && (defined PWM_EMIOS_0_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if  ((defined PWM_EMIOS_0_CH_3_ISR_USED) && (defined ICU_EMIOS_0_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_3"
#endif

#if  ((defined ICU_EMIOS_0_CH_3_ISR_USED) && (defined GPT_EMIOS_0_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_3"
#endif


#if ( (defined GPT_EMIOS_0_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_3_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 3 for eMios_0 module
* @details   Process the interrupt of eMios channel 3
*
* @note   This will be defined only if eMios channel 3 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_3_ISR)
{

    #if(defined GPT_EMIOS_0_CH_3_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_3);
    #endif

    #if(defined PWM_EMIOS_0_CH_3_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_3);
    #endif

    #if(defined ICU_EMIOS_0_CH_3_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_3);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:4 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_4
*/
#if  ((defined GPT_EMIOS_0_CH_4_ISR_USED) && (defined PWM_EMIOS_0_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_4"
#endif

#if  ((defined PWM_EMIOS_0_CH_4_ISR_USED) && (defined ICU_EMIOS_0_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_4"
#endif

#if  ((defined ICU_EMIOS_0_CH_4_ISR_USED) && (defined GPT_EMIOS_0_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_4"
#endif


#if ( (defined GPT_EMIOS_0_CH_4_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_4_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_4_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 4 for eMios_0 module
* @details   Process the interrupt of eMios channel 4
*
* @note   This will be defined only if eMios channel 4 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_4_ISR)
{

    #if(defined GPT_EMIOS_0_CH_4_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_4);
    #endif

    #if(defined PWM_EMIOS_0_CH_4_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_4);
    #endif

    #if(defined ICU_EMIOS_0_CH_4_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_4);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:5 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_5
*/
#if  ((defined GPT_EMIOS_0_CH_5_ISR_USED) && (defined PWM_EMIOS_0_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if  ((defined PWM_EMIOS_0_CH_5_ISR_USED) && (defined ICU_EMIOS_0_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_5"
#endif

#if  ((defined ICU_EMIOS_0_CH_5_ISR_USED) && (defined GPT_EMIOS_0_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_5"
#endif


#if ( (defined GPT_EMIOS_0_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_5_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 5 for eMios_0 module
* @details   Process the interrupt of eMios channel 5
*
* @note   This will be defined only if eMios channel 5 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_5_ISR)
{

    #if(defined GPT_EMIOS_0_CH_5_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_5);
    #endif

    #if(defined PWM_EMIOS_0_CH_5_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_5);
    #endif

    #if(defined ICU_EMIOS_0_CH_5_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_5);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:6 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_6
*/
#if  ((defined GPT_EMIOS_0_CH_6_ISR_USED) && (defined PWM_EMIOS_0_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_6"
#endif

#if  ((defined PWM_EMIOS_0_CH_6_ISR_USED) && (defined ICU_EMIOS_0_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_6"
#endif

#if  ((defined ICU_EMIOS_0_CH_6_ISR_USED) && (defined GPT_EMIOS_0_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_6"
#endif


#if ( (defined GPT_EMIOS_0_CH_6_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_6_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_6_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 6 for eMios_0 module
* @details   Process the interrupt of eMios channel 6
*
* @note   This will be defined only if eMios channel 6 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_6_ISR)
{

    #if(defined GPT_EMIOS_0_CH_6_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_6);
    #endif

    #if(defined PWM_EMIOS_0_CH_6_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_6);
    #endif

    #if(defined ICU_EMIOS_0_CH_6_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_6);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:7 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_0_CH_7
*/
#if  ((defined GPT_EMIOS_0_CH_7_ISR_USED) && (defined PWM_EMIOS_0_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if  ((defined PWM_EMIOS_0_CH_7_ISR_USED) && (defined ICU_EMIOS_0_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_7"
#endif

#if  ((defined ICU_EMIOS_0_CH_7_ISR_USED) && (defined GPT_EMIOS_0_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_7"
#endif


#if ( (defined GPT_EMIOS_0_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_7_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 7 for eMios_0 module
* @details   Process the interrupt of eMios channel 7
*
* @note   This will be defined only if eMios channel 7 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_7_ISR)
{

    #if(defined GPT_EMIOS_0_CH_7_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_7);
    #endif

    #if(defined PWM_EMIOS_0_CH_7_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_7);
    #endif

    #if(defined ICU_EMIOS_0_CH_7_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_7);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:8 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_8
*/

#if  ((defined GPT_EMIOS_0_CH_8_ISR_USED) && (defined PWM_EMIOS_0_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_8"
#endif

#if  ((defined PWM_EMIOS_0_CH_8_ISR_USED) && (defined ICU_EMIOS_0_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_8"
#endif

#if  ((defined ICU_EMIOS_0_CH_8_ISR_USED) && (defined GPT_EMIOS_0_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_8"
#endif


#if ( (defined GPT_EMIOS_0_CH_8_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_8_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_8_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 8 for eMios_0 module
* @details   Process the interrupt of eMios channel 8
*
* @note   This will be defined only if eMios channel 8 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_8_ISR)
{

    #if(defined GPT_EMIOS_0_CH_8_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_8);
    #endif

    #if(defined PWM_EMIOS_0_CH_8_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_8);
    #endif

    #if(defined ICU_EMIOS_0_CH_8_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_8);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:9 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_9
*/
#if  ((defined GPT_EMIOS_0_CH_9_ISR_USED) && (defined PWM_EMIOS_0_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if  ((defined PWM_EMIOS_0_CH_9_ISR_USED) && (defined ICU_EMIOS_0_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_9"
#endif

#if  ((defined ICU_EMIOS_0_CH_9_ISR_USED) && (defined GPT_EMIOS_0_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_9"
#endif


#if ( (defined GPT_EMIOS_0_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_9_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 9 for eMios_0 module
* @details   Process the interrupt of eMios channel 9
*
* @note   This will be defined only if eMios channel 9 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_9_ISR)
{

    #if(defined GPT_EMIOS_0_CH_9_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_9);
    #endif

    #if(defined PWM_EMIOS_0_CH_9_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_9);
    #endif

    #if(defined ICU_EMIOS_0_CH_9_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_9);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:10 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_10
*/
#if  ((defined GPT_EMIOS_0_CH_10_ISR_USED) && (defined PWM_EMIOS_0_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_10"
#endif

#if  ((defined PWM_EMIOS_0_CH_10_ISR_USED) && (defined ICU_EMIOS_0_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_10"
#endif

#if  ((defined ICU_EMIOS_0_CH_10_ISR_USED) && (defined GPT_EMIOS_0_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_10"
#endif


#if ( (defined GPT_EMIOS_0_CH_10_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_10_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_10_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 10 for eMios_0 module
* @details   Process the interrupt of eMios channel 10
*
* @note   This will be defined only if eMios channel 10 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_10_ISR)
{

    #if(defined GPT_EMIOS_0_CH_10_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_10);
    #endif

    #if(defined PWM_EMIOS_0_CH_10_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_10);
    #endif

    #if(defined ICU_EMIOS_0_CH_10_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_10);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:11 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_11
*/
#if  ((defined GPT_EMIOS_0_CH_11_ISR_USED) && (defined PWM_EMIOS_0_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if  ((defined PWM_EMIOS_0_CH_11_ISR_USED) && (defined ICU_EMIOS_0_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_11"
#endif

#if  ((defined ICU_EMIOS_0_CH_11_ISR_USED) && (defined GPT_EMIOS_0_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_11"
#endif


#if ( (defined GPT_EMIOS_0_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_11_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 11 for eMios_0 module
* @details   Process the interrupt of eMios channel 11
*
* @note   This will be defined only if eMios channel 11 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_11_ISR)
{

    #if(defined GPT_EMIOS_0_CH_11_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_11);
    #endif

    #if(defined PWM_EMIOS_0_CH_11_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_11);
    #endif

    #if(defined ICU_EMIOS_0_CH_11_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_11);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:12 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_12
*/
#if  ((defined GPT_EMIOS_0_CH_12_ISR_USED) && (defined PWM_EMIOS_0_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_12"
#endif

#if  ((defined PWM_EMIOS_0_CH_12_ISR_USED) && (defined ICU_EMIOS_0_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_12"
#endif

#if  ((defined ICU_EMIOS_0_CH_12_ISR_USED) && (defined GPT_EMIOS_0_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_12"
#endif


#if ( (defined GPT_EMIOS_0_CH_12_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_12_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_12_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 12 for eMios_0 module
* @details   Process the interrupt of eMios channel 12
*
* @note   This will be defined only if eMios channel 12 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_12_ISR)
{

    #if(defined GPT_EMIOS_0_CH_12_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_12);
    #endif

    #if(defined PWM_EMIOS_0_CH_12_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_12);
    #endif

    #if(defined ICU_EMIOS_0_CH_12_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_12);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:13 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_13
*/
#if  ((defined GPT_EMIOS_0_CH_13_ISR_USED) && (defined PWM_EMIOS_0_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if  ((defined PWM_EMIOS_0_CH_13_ISR_USED) && (defined ICU_EMIOS_0_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_13"
#endif

#if  ((defined ICU_EMIOS_0_CH_13_ISR_USED) && (defined GPT_EMIOS_0_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_13"
#endif


#if ( (defined GPT_EMIOS_0_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_13_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 13 for eMios_0 module
* @details   Process the interrupt of eMios channel 13
*
* @note   This will be defined only if eMios channel 13 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_13_ISR)
{

    #if(defined GPT_EMIOS_0_CH_13_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_13);
    #endif

    #if(defined PWM_EMIOS_0_CH_13_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_13);
    #endif

    #if(defined ICU_EMIOS_0_CH_13_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_13);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:14 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_14
*/
#if  ((defined GPT_EMIOS_0_CH_14_ISR_USED) && (defined PWM_EMIOS_0_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_14"
#endif

#if  ((defined PWM_EMIOS_0_CH_14_ISR_USED) && (defined ICU_EMIOS_0_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_14"
#endif

#if  ((defined ICU_EMIOS_0_CH_14_ISR_USED) && (defined GPT_EMIOS_0_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_14"
#endif


#if ( (defined GPT_EMIOS_0_CH_14_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_14_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_14_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 14 for eMios_0 module
* @details   Process the interrupt of eMios channel 14
*
* @note   This will be defined only if eMios channel 14 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_14_ISR)
{

    #if(defined GPT_EMIOS_0_CH_14_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_14);
    #endif

    #if(defined PWM_EMIOS_0_CH_14_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_14);
    #endif

    #if(defined ICU_EMIOS_0_CH_14_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_14);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:15 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_15
*/
#if  ((defined GPT_EMIOS_0_CH_15_ISR_USED) && (defined PWM_EMIOS_0_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if  ((defined PWM_EMIOS_0_CH_15_ISR_USED) && (defined ICU_EMIOS_0_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_15"
#endif

#if  ((defined ICU_EMIOS_0_CH_15_ISR_USED) && (defined GPT_EMIOS_0_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_15"
#endif


#if ( (defined GPT_EMIOS_0_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_15_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 15 for eMios_0 module
* @details   Process the interrupt of eMios channel 15
*
* @note   This will be defined only if eMios channel 15 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_15_ISR)
{

    #if(defined GPT_EMIOS_0_CH_15_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_15);
    #endif

    #if(defined PWM_EMIOS_0_CH_15_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_15);
    #endif

    #if(defined ICU_EMIOS_0_CH_15_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_15);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:16 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_16
*/
#if  ((defined GPT_EMIOS_0_CH_16_ISR_USED) && (defined PWM_EMIOS_0_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_16"
#endif

#if  ((defined PWM_EMIOS_0_CH_16_ISR_USED) && (defined ICU_EMIOS_0_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_16"
#endif

#if  ((defined ICU_EMIOS_0_CH_16_ISR_USED) && (defined GPT_EMIOS_0_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_16"
#endif


#if ( (defined GPT_EMIOS_0_CH_16_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_16_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_16_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 16 for eMios_0 module
* @details   Process the interrupt of eMios channel 16
*
* @note   This will be defined only if eMios channel 16 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_16_ISR)
{

    #if(defined GPT_EMIOS_0_CH_16_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_16);
    #endif

    #if(defined PWM_EMIOS_0_CH_16_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_16);
    #endif

    #if(defined ICU_EMIOS_0_CH_16_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_16);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:17 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_17
*/
#if  ((defined GPT_EMIOS_0_CH_17_ISR_USED) && (defined PWM_EMIOS_0_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if  ((defined PWM_EMIOS_0_CH_17_ISR_USED) && (defined ICU_EMIOS_0_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_17"
#endif

#if  ((defined ICU_EMIOS_0_CH_17_ISR_USED) && (defined GPT_EMIOS_0_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_17"
#endif


#if ( (defined GPT_EMIOS_0_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_17_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 17 for eMios_0 module
* @details   Process the interrupt of eMios channel 17
*
* @note   This will be defined only if eMios channel 17 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_17_ISR)
{

    #if(defined GPT_EMIOS_0_CH_17_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_17);
    #endif

    #if(defined PWM_EMIOS_0_CH_17_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_17);
    #endif

    #if(defined ICU_EMIOS_0_CH_17_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_17);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:18 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_18
*/
#if  ((defined GPT_EMIOS_0_CH_18_ISR_USED) && (defined PWM_EMIOS_0_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_18"
#endif

#if  ((defined PWM_EMIOS_0_CH_18_ISR_USED) && (defined ICU_EMIOS_0_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_18"
#endif

#if  ((defined ICU_EMIOS_0_CH_18_ISR_USED) && (defined GPT_EMIOS_0_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_18"
#endif


#if ( (defined GPT_EMIOS_0_CH_18_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_18_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_18_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 18 for eMios_0 module
* @details   Process the interrupt of eMios channel 18
*
* @note   This will be defined only if eMios channel 18 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_18_ISR)
{

    #if(defined GPT_EMIOS_0_CH_18_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_18);
    #endif

    #if(defined PWM_EMIOS_0_CH_18_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_18);
    #endif

    #if(defined ICU_EMIOS_0_CH_18_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_18);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:19 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_19
*/
#if  ((defined GPT_EMIOS_0_CH_19_ISR_USED) && (defined PWM_EMIOS_0_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if  ((defined PWM_EMIOS_0_CH_19_ISR_USED) && (defined ICU_EMIOS_0_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_19"
#endif

#if  ((defined ICU_EMIOS_0_CH_19_ISR_USED) && (defined GPT_EMIOS_0_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_19"
#endif


#if ( (defined GPT_EMIOS_0_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_19_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 19 for eMios_0 module
* @details   Process the interrupt of eMios channel 19
*
* @note   This will be defined only if eMios channel 19 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_19_ISR)
{

    #if(defined GPT_EMIOS_0_CH_19_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_19);
    #endif

    #if(defined PWM_EMIOS_0_CH_19_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_19);
    #endif

    #if(defined ICU_EMIOS_0_CH_19_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_19);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:20 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_20
*/
#if  ((defined GPT_EMIOS_0_CH_20_ISR_USED) && (defined PWM_EMIOS_0_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_20"
#endif

#if  ((defined PWM_EMIOS_0_CH_20_ISR_USED) && (defined ICU_EMIOS_0_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_20"
#endif

#if  ((defined ICU_EMIOS_0_CH_20_ISR_USED) && (defined GPT_EMIOS_0_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_20"
#endif


#if ( (defined GPT_EMIOS_0_CH_20_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_20_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_20_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 20 for eMios_0 module
* @details   Process the interrupt of eMios channel 20
*
* @note   This will be defined only if eMios channel 20 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_20_ISR)
{

    #if(defined GPT_EMIOS_0_CH_20_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_20);
    #endif

    #if(defined PWM_EMIOS_0_CH_20_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_20);
    #endif

    #if(defined ICU_EMIOS_0_CH_20_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_20);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:21 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_21
*/
#if  ((defined GPT_EMIOS_0_CH_21_ISR_USED) && (defined PWM_EMIOS_0_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if  ((defined PWM_EMIOS_0_CH_21_ISR_USED) && (defined ICU_EMIOS_0_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_21"
#endif

#if  ((defined ICU_EMIOS_0_CH_21_ISR_USED) && (defined GPT_EMIOS_0_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_21"
#endif


#if ( (defined GPT_EMIOS_0_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_21_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 21 for eMios_0 module
* @details   Process the interrupt of eMios channel 21
*
* @note   This will be defined only if eMios channel 21 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_21_ISR)
{

    #if(defined GPT_EMIOS_0_CH_21_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_21);
    #endif

    #if(defined PWM_EMIOS_0_CH_21_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_21);
    #endif

    #if(defined ICU_EMIOS_0_CH_21_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_21);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:22 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_22
*/
#if  ((defined GPT_EMIOS_0_CH_22_ISR_USED) && (defined PWM_EMIOS_0_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_22"
#endif

#if  ((defined PWM_EMIOS_0_CH_22_ISR_USED) && (defined ICU_EMIOS_0_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_22"
#endif

#if  ((defined ICU_EMIOS_0_CH_22_ISR_USED) && (defined GPT_EMIOS_0_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_22"
#endif


#if ( (defined GPT_EMIOS_0_CH_22_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_22_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_22_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 22 for eMios_0 module
* @details   Process the interrupt of eMios channel 22
*
* @note   This will be defined only if eMios channel 22 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_22_ISR)
{

    #if(defined GPT_EMIOS_0_CH_22_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_22);
    #endif

    #if(defined PWM_EMIOS_0_CH_22_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_22);
    #endif

    #if(defined ICU_EMIOS_0_CH_22_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_22);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:23 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_23
*/
#if  ((defined GPT_EMIOS_0_CH_23_ISR_USED) && (defined PWM_EMIOS_0_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if  ((defined PWM_EMIOS_0_CH_23_ISR_USED) && (defined ICU_EMIOS_0_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_23"
#endif

#if  ((defined ICU_EMIOS_0_CH_23_ISR_USED) && (defined GPT_EMIOS_0_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_23"
#endif


#if ( (defined GPT_EMIOS_0_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_23_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 23 for eMios_0 module
* @details   Process the interrupt of eMios channel 23
*
* @note   This will be defined only if eMios channel 23 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_23_ISR)
{

    #if(defined GPT_EMIOS_0_CH_23_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_23);
    #endif

    #if(defined PWM_EMIOS_0_CH_23_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_23);
    #endif

    #if(defined ICU_EMIOS_0_CH_23_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_23);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:24 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_24
*/
#if  ((defined GPT_EMIOS_0_CH_24_ISR_USED) && (defined PWM_EMIOS_0_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_24"
#endif

#if  ((defined PWM_EMIOS_0_CH_24_ISR_USED) && (defined ICU_EMIOS_0_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_24"
#endif

#if  ((defined ICU_EMIOS_0_CH_24_ISR_USED) && (defined GPT_EMIOS_0_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_24"
#endif


#if ( (defined GPT_EMIOS_0_CH_24_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_24_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_24_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 24 for eMios_0 module
* @details   Process the interrupt of eMios channel 24
*
* @note   This will be defined only if eMios channel 24 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_24_ISR)
{

    #if(defined GPT_EMIOS_0_CH_24_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_24);
    #endif

    #if(defined PWM_EMIOS_0_CH_24_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_24);
    #endif

    #if(defined ICU_EMIOS_0_CH_24_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_24);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:25 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_25
*/
#if  ((defined GPT_EMIOS_0_CH_25_ISR_USED) && (defined PWM_EMIOS_0_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if  ((defined PWM_EMIOS_0_CH_25_ISR_USED) && (defined ICU_EMIOS_0_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_25"
#endif

#if  ((defined ICU_EMIOS_0_CH_25_ISR_USED) && (defined GPT_EMIOS_0_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_25"
#endif


#if ( (defined GPT_EMIOS_0_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_25_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 25 for eMios_0 module
* @details   Process the interrupt of eMios channel 25
*
* @note   This will be defined only if eMios channel 25 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_25_ISR)
{

    #if(defined GPT_EMIOS_0_CH_25_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_25);
    #endif

    #if(defined PWM_EMIOS_0_CH_25_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_25);
    #endif

    #if(defined ICU_EMIOS_0_CH_25_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_25);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:26 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_26
*/
#if  ((defined GPT_EMIOS_0_CH_26_ISR_USED) && (defined PWM_EMIOS_0_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_26"
#endif

#if  ((defined PWM_EMIOS_0_CH_26_ISR_USED) && (defined ICU_EMIOS_0_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_26"
#endif

#if  ((defined ICU_EMIOS_0_CH_26_ISR_USED) && (defined GPT_EMIOS_0_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_26"
#endif


#if ( (defined GPT_EMIOS_0_CH_26_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_26_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_26_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 26 for eMios_0 module
* @details   Process the interrupt of eMios channel 26
*
* @note   This will be defined only if eMios channel 26 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_26_ISR)
{

    #if(defined GPT_EMIOS_0_CH_26_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_26);
    #endif

    #if(defined PWM_EMIOS_0_CH_26_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_26);
    #endif

    #if(defined ICU_EMIOS_0_CH_26_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_26);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:27 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_27
*/
#if  ((defined GPT_EMIOS_0_CH_27_ISR_USED) && (defined PWM_EMIOS_0_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if  ((defined PWM_EMIOS_0_CH_27_ISR_USED) && (defined ICU_EMIOS_0_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_27"
#endif

#if  ((defined ICU_EMIOS_0_CH_27_ISR_USED) && (defined GPT_EMIOS_0_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_27"
#endif


#if ( (defined GPT_EMIOS_0_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_27_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 27 for eMios_0 module
* @details   Process the interrupt of eMios channel 27
*
* @note   This will be defined only if eMios channel 27 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_27_ISR)
{

    #if(defined GPT_EMIOS_0_CH_27_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_27);
    #endif

    #if(defined PWM_EMIOS_0_CH_27_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_27);
    #endif

    #if(defined ICU_EMIOS_0_CH_27_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_27);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:28 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_28
*/
#if  ((defined GPT_EMIOS_0_CH_28_ISR_USED) && (defined PWM_EMIOS_0_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_28"
#endif

#if  ((defined PWM_EMIOS_0_CH_28_ISR_USED) && (defined ICU_EMIOS_0_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_28"
#endif

#if  ((defined ICU_EMIOS_0_CH_28_ISR_USED) && (defined GPT_EMIOS_0_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_28"
#endif


#if ( (defined GPT_EMIOS_0_CH_28_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_28_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_28_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 28 for eMios_0 module
* @details   Process the interrupt of eMios channel 28
*
* @note   This will be defined only if eMios channel 28 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_28_ISR)
{

    #if(defined GPT_EMIOS_0_CH_28_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_28);
    #endif

    #if(defined PWM_EMIOS_0_CH_28_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_28);
    #endif

    #if(defined ICU_EMIOS_0_CH_28_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_28);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:29 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_29
*/
#if  ((defined GPT_EMIOS_0_CH_29_ISR_USED) && (defined PWM_EMIOS_0_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if  ((defined PWM_EMIOS_0_CH_29_ISR_USED) && (defined ICU_EMIOS_0_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_29"
#endif

#if  ((defined ICU_EMIOS_0_CH_29_ISR_USED) && (defined GPT_EMIOS_0_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_29"
#endif


#if ( (defined GPT_EMIOS_0_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_29_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 29 for eMios_0 module
* @details   Process the interrupt of eMios channel 29
*
* @note   This will be defined only if eMios channel 29 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_29_ISR)
{

    #if(defined GPT_EMIOS_0_CH_29_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_29);
    #endif

    #if(defined PWM_EMIOS_0_CH_29_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_29);
    #endif

    #if(defined ICU_EMIOS_0_CH_29_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_29);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:30 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_30
*/
#if  ((defined GPT_EMIOS_0_CH_30_ISR_USED) && (defined PWM_EMIOS_0_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_30"
#endif

#if  ((defined PWM_EMIOS_0_CH_30_ISR_USED) && (defined ICU_EMIOS_0_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_30"
#endif

#if  ((defined ICU_EMIOS_0_CH_30_ISR_USED) && (defined GPT_EMIOS_0_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_30"
#endif


#if ( (defined GPT_EMIOS_0_CH_30_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_30_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_30_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 30 for eMios_0 module
* @details   Process the interrupt of eMios channel 30
*
* @note   This will be defined only if eMios channel 30 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_30_ISR)
{

    #if(defined GPT_EMIOS_0_CH_30_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_30);
    #endif

    #if(defined PWM_EMIOS_0_CH_30_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_30);
    #endif

    #if(defined ICU_EMIOS_0_CH_30_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_30);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:0 channel:31 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_0_CH_31
*/
#if  ((defined GPT_EMIOS_0_CH_31_ISR_USED) && (defined PWM_EMIOS_0_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if  ((defined PWM_EMIOS_0_CH_31_ISR_USED) && (defined ICU_EMIOS_0_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_0_31"
#endif

#if  ((defined ICU_EMIOS_0_CH_31_ISR_USED) && (defined GPT_EMIOS_0_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_0_31"
#endif


#if ( (defined GPT_EMIOS_0_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_0_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_0_CH_31_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 31 for eMios_0 module
* @details   Process the interrupt of eMios channel 31
*
* @note   This will be defined only if eMios channel 31 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_0_CH_31_ISR)
{

    #if(defined GPT_EMIOS_0_CH_31_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_0_CH_31);
    #endif

    #if(defined PWM_EMIOS_0_CH_31_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_0_CH_31);
    #endif

    #if(defined ICU_EMIOS_0_CH_31_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_0_CH_31);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif



/*********************************** EMIOS 0 independent interrupts END ***************************/



/*********************************** EMIOS 1 independent interrupts START *************************/


/*
* @brief EMIOS module:1 channel:0 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_0
*/
#if  ((defined GPT_EMIOS_1_CH_0_ISR_USED) && (defined PWM_EMIOS_1_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_0"
#endif

#if  ((defined PWM_EMIOS_1_CH_0_ISR_USED) && (defined ICU_EMIOS_1_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_0"
#endif

#if  ((defined ICU_EMIOS_1_CH_0_ISR_USED) && (defined GPT_EMIOS_1_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_0"
#endif


#if ( (defined GPT_EMIOS_1_CH_0_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_0_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_0_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 0 for eMios_1 module
* @details   Process the interrupt of eMios channel 0
*
* @note   This will be defined only if eMios channel 0 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_0_ISR)
{

    #if(defined GPT_EMIOS_1_CH_0_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_0);
    #endif

    #if(defined PWM_EMIOS_1_CH_0_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_0);
    #endif

    #if(defined ICU_EMIOS_1_CH_0_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_0);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:1 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_1
*/
#if  ((defined GPT_EMIOS_1_CH_1_ISR_USED) && (defined PWM_EMIOS_1_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if  ((defined PWM_EMIOS_1_CH_1_ISR_USED) && (defined ICU_EMIOS_1_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_1"
#endif

#if  ((defined ICU_EMIOS_1_CH_1_ISR_USED) && (defined GPT_EMIOS_1_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_1"
#endif


#if ( (defined GPT_EMIOS_1_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_1_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 1 for eMios_1 module
* @details   Process the interrupt of eMios channel 1
*
* @note   This will be defined only if eMios channel 1 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_1_ISR)
{

    #if(defined GPT_EMIOS_1_CH_1_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_1);
    #endif

    #if(defined PWM_EMIOS_1_CH_1_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_1);
    #endif

    #if(defined ICU_EMIOS_1_CH_1_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_1);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:2 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_2
*/
#if  ((defined GPT_EMIOS_1_CH_2_ISR_USED) && (defined PWM_EMIOS_1_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_2"
#endif

#if  ((defined PWM_EMIOS_1_CH_2_ISR_USED) && (defined ICU_EMIOS_1_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_2"
#endif

#if  ((defined ICU_EMIOS_1_CH_2_ISR_USED) && (defined GPT_EMIOS_1_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_2"
#endif


#if ( (defined GPT_EMIOS_1_CH_2_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_2_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_2_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 2 for eMios_1 module
* @details   Process the interrupt of eMios channel 2
*
* @note   This will be defined only if eMios channel 2 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_2_ISR)
{

    #if(defined GPT_EMIOS_1_CH_2_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_2);
    #endif

    #if(defined PWM_EMIOS_1_CH_2_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_2);
    #endif

    #if(defined ICU_EMIOS_1_CH_2_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_2);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:3 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_3
*/
#if  ((defined GPT_EMIOS_1_CH_3_ISR_USED) && (defined PWM_EMIOS_1_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if  ((defined PWM_EMIOS_1_CH_3_ISR_USED) && (defined ICU_EMIOS_1_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_3"
#endif

#if  ((defined ICU_EMIOS_1_CH_3_ISR_USED) && (defined GPT_EMIOS_1_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_3"
#endif


#if ( (defined GPT_EMIOS_1_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_3_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 3 for eMios_1 module
* @details   Process the interrupt of eMios channel 3
*
* @note   This will be defined only if eMios channel 3 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_3_ISR)
{

    #if(defined GPT_EMIOS_1_CH_3_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_3);
    #endif

    #if(defined PWM_EMIOS_1_CH_3_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_3);
    #endif

    #if(defined ICU_EMIOS_1_CH_3_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_3);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:4 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_4
*/
#if  ((defined GPT_EMIOS_1_CH_4_ISR_USED) && (defined PWM_EMIOS_1_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_4"
#endif

#if  ((defined PWM_EMIOS_1_CH_4_ISR_USED) && (defined ICU_EMIOS_1_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_4"
#endif

#if  ((defined ICU_EMIOS_1_CH_4_ISR_USED) && (defined GPT_EMIOS_1_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_4"
#endif


#if ( (defined GPT_EMIOS_1_CH_4_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_4_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_4_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 4 for eMios_1 module
* @details   Process the interrupt of eMios channel 4
*
* @note   This will be defined only if eMios channel 4 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
/*

*/
ISR(EMIOS_1_CH_4_ISR)
{

    #if(defined GPT_EMIOS_1_CH_4_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_4);
    #endif

    #if(defined PWM_EMIOS_1_CH_4_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_4);
    #endif

    #if(defined ICU_EMIOS_1_CH_4_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_4);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:5 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_5
*/
#if  ((defined GPT_EMIOS_1_CH_5_ISR_USED) && (defined PWM_EMIOS_1_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if  ((defined PWM_EMIOS_1_CH_5_ISR_USED) && (defined ICU_EMIOS_1_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_5"
#endif

#if  ((defined ICU_EMIOS_1_CH_5_ISR_USED) && (defined GPT_EMIOS_1_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_5"
#endif


#if ( (defined GPT_EMIOS_1_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_5_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 5 for eMios_1 module
* @details   Process the interrupt of eMios channel 5
*
* @note   This will be defined only if eMios channel 5 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_5_ISR)
{

    #if(defined GPT_EMIOS_1_CH_5_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_5);
    #endif

    #if(defined PWM_EMIOS_1_CH_5_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_5);
    #endif

    #if(defined ICU_EMIOS_1_CH_5_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_5);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:6 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_6
*/
#if  ((defined GPT_EMIOS_1_CH_6_ISR_USED) && (defined PWM_EMIOS_1_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_6"
#endif

#if  ((defined PWM_EMIOS_1_CH_6_ISR_USED) && (defined ICU_EMIOS_1_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_6"
#endif

#if  ((defined ICU_EMIOS_1_CH_6_ISR_USED) && (defined GPT_EMIOS_1_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_6"
#endif


#if ( (defined GPT_EMIOS_1_CH_6_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_6_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_6_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 6 for eMios_1 module
* @details   Process the interrupt of eMios channel 6
*
* @note   This will be defined only if eMios channel 6 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_6_ISR)
{

    #if(defined GPT_EMIOS_1_CH_6_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_6);
    #endif

    #if(defined PWM_EMIOS_1_CH_6_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_6);
    #endif

    #if(defined ICU_EMIOS_1_CH_6_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_6);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:7 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_7
*/
#if  ((defined GPT_EMIOS_1_CH_7_ISR_USED) && (defined PWM_EMIOS_1_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if  ((defined PWM_EMIOS_1_CH_7_ISR_USED) && (defined ICU_EMIOS_1_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_7"
#endif

#if  ((defined ICU_EMIOS_1_CH_7_ISR_USED) && (defined GPT_EMIOS_1_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_7"
#endif


#if ( (defined GPT_EMIOS_1_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_7_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 7 for eMios_1 module
* @details   Process the interrupt of eMios channel 7
*
* @note   This will be defined only if eMios channel 7 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_7_ISR)
{

    #if(defined GPT_EMIOS_1_CH_7_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_7);
    #endif

    #if(defined PWM_EMIOS_1_CH_7_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_7);
    #endif

    #if(defined ICU_EMIOS_1_CH_7_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_7);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:8 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_8
*/
#if  ((defined GPT_EMIOS_1_CH_8_ISR_USED) && (defined PWM_EMIOS_1_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_8"
#endif

#if  ((defined PWM_EMIOS_1_CH_8_ISR_USED) && (defined ICU_EMIOS_1_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_8"
#endif

#if  ((defined ICU_EMIOS_1_CH_8_ISR_USED) && (defined GPT_EMIOS_1_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_8"
#endif


#if ( (defined GPT_EMIOS_1_CH_8_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_8_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_8_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 8 for eMios_1 module
* @details   Process the interrupt of eMios channel 8
*
* @note   This will be defined only if eMios channel 8 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_8_ISR)
{

    #if(defined GPT_EMIOS_1_CH_8_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_8);
    #endif

    #if(defined PWM_EMIOS_1_CH_8_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_8);
    #endif

    #if(defined ICU_EMIOS_1_CH_8_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_8);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:9 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_9
*/
#if  ((defined GPT_EMIOS_1_CH_9_ISR_USED) && (defined PWM_EMIOS_1_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if  ((defined PWM_EMIOS_1_CH_9_ISR_USED) && (defined ICU_EMIOS_1_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_9"
#endif

#if  ((defined ICU_EMIOS_1_CH_9_ISR_USED) && (defined GPT_EMIOS_1_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_9"
#endif


#if ( (defined GPT_EMIOS_1_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_9_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 9 for eMios_1 module
* @details   Process the interrupt of eMios channel 9
*
* @note   This will be defined only if eMios channel 9 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_9_ISR)
{

    #if(defined GPT_EMIOS_1_CH_9_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_9);
    #endif

    #if(defined PWM_EMIOS_1_CH_9_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_9);
    #endif

    #if(defined ICU_EMIOS_1_CH_9_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_9);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:10 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_10
*/
#if  ((defined GPT_EMIOS_1_CH_10_ISR_USED) && (defined PWM_EMIOS_1_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_10"
#endif

#if  ((defined PWM_EMIOS_1_CH_10_ISR_USED) && (defined ICU_EMIOS_1_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_10"
#endif

#if  ((defined ICU_EMIOS_1_CH_10_ISR_USED) && (defined GPT_EMIOS_1_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_10"
#endif


#if ( (defined GPT_EMIOS_1_CH_10_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_10_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_10_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 10 for eMios_1 module
* @details   Process the interrupt of eMios channel 10
*
* @note      This will be defined only if eMios channel 10 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_10_ISR)
{

    #if(defined GPT_EMIOS_1_CH_10_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_10);
    #endif

    #if(defined PWM_EMIOS_1_CH_10_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_10);
    #endif

    #if(defined ICU_EMIOS_1_CH_10_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_10);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:11 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_11
*/
#if  ((defined GPT_EMIOS_1_CH_11_ISR_USED) && (defined PWM_EMIOS_1_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if  ((defined PWM_EMIOS_1_CH_11_ISR_USED) && (defined ICU_EMIOS_1_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_11"
#endif

#if  ((defined ICU_EMIOS_1_CH_11_ISR_USED) && (defined GPT_EMIOS_1_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_11"
#endif


#if ( (defined GPT_EMIOS_1_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_11_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 11 for eMios_1 module
* @details   Process the interrupt of eMios channel 11
*
* @note   This will be defined only if eMios channel 11 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_11_ISR)
{

    #if(defined GPT_EMIOS_1_CH_11_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_11);
    #endif

    #if(defined PWM_EMIOS_1_CH_11_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_11);
    #endif

    #if(defined ICU_EMIOS_1_CH_11_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_11);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:12 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_12
*/
#if  ((defined GPT_EMIOS_1_CH_12_ISR_USED) && (defined PWM_EMIOS_1_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_12"
#endif

#if  ((defined PWM_EMIOS_1_CH_12_ISR_USED) && (defined ICU_EMIOS_1_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_12"
#endif

#if  ((defined ICU_EMIOS_1_CH_12_ISR_USED) && (defined GPT_EMIOS_1_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_12"
#endif


#if ( (defined GPT_EMIOS_1_CH_12_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_12_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_12_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 12 for eMios_1 module
* @details   Process the interrupt of eMios channel 12
*
* @note   This will be defined only if eMios channel 12 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_12_ISR)
{

    #if(defined GPT_EMIOS_1_CH_12_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_12);
    #endif

    #if(defined PWM_EMIOS_1_CH_12_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_12);
    #endif

    #if(defined ICU_EMIOS_1_CH_12_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_12);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:13 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_13
*/
#if  ((defined GPT_EMIOS_1_CH_13_ISR_USED) && (defined PWM_EMIOS_1_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if  ((defined PWM_EMIOS_1_CH_13_ISR_USED) && (defined ICU_EMIOS_1_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_13"
#endif

#if  ((defined ICU_EMIOS_1_CH_13_ISR_USED) && (defined GPT_EMIOS_1_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_13"
#endif


#if ( (defined GPT_EMIOS_1_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_13_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 13 for eMios_1 module
* @details   Process the interrupt of eMios channel 13
*
* @note   This will be defined only if eMios channel 13 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_13_ISR)
{

    #if(defined GPT_EMIOS_1_CH_13_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_13);
    #endif

    #if(defined PWM_EMIOS_1_CH_13_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_13);
    #endif

    #if(defined ICU_EMIOS_1_CH_13_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_13);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:14 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_14
*/
#if  ((defined GPT_EMIOS_1_CH_14_ISR_USED) && (defined PWM_EMIOS_1_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_14"
#endif

#if  ((defined PWM_EMIOS_1_CH_14_ISR_USED) && (defined ICU_EMIOS_1_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_14"
#endif

#if  ((defined ICU_EMIOS_1_CH_14_ISR_USED) && (defined GPT_EMIOS_1_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_14"
#endif


#if ( (defined GPT_EMIOS_1_CH_14_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_14_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_14_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 14 for eMios_1 module
* @details   Process the interrupt of eMios channel 14
*
* @note   This will be defined only if eMios channel 14 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_14_ISR)
{

    #if(defined GPT_EMIOS_1_CH_14_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_14);
    #endif

    #if(defined PWM_EMIOS_1_CH_14_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_14);
    #endif

    #if(defined ICU_EMIOS_1_CH_14_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_14);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:15 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_15
*/
#if  ((defined GPT_EMIOS_1_CH_15_ISR_USED) && (defined PWM_EMIOS_1_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if  ((defined PWM_EMIOS_1_CH_15_ISR_USED) && (defined ICU_EMIOS_1_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_15"
#endif

#if  ((defined ICU_EMIOS_1_CH_15_ISR_USED) && (defined GPT_EMIOS_1_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_15"
#endif


#if ( (defined GPT_EMIOS_1_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_15_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 15 for eMios_1 module
* @details   Process the interrupt of eMios channel 15
*
* @note   This will be defined only if eMios channel 15 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_15_ISR)
{

    #if(defined GPT_EMIOS_1_CH_15_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_15);
    #endif

    #if(defined PWM_EMIOS_1_CH_15_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_15);
    #endif

    #if(defined ICU_EMIOS_1_CH_15_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_15);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:16 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_16
*/
#if  ((defined GPT_EMIOS_1_CH_16_ISR_USED) && (defined PWM_EMIOS_1_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_16"
#endif

#if  ((defined PWM_EMIOS_1_CH_16_ISR_USED) && (defined ICU_EMIOS_1_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_16"
#endif

#if  ((defined ICU_EMIOS_1_CH_16_ISR_USED) && (defined GPT_EMIOS_1_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_16"
#endif


#if ( (defined GPT_EMIOS_1_CH_16_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_16_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_16_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 16 for eMios_1 module
* @details   Process the interrupt of eMios channel 16
*
* @note   This will be defined only if eMios channel 16 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_16_ISR)
{

    #if(defined GPT_EMIOS_1_CH_16_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_16);
    #endif

    #if(defined PWM_EMIOS_1_CH_16_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_16);
    #endif

    #if(defined ICU_EMIOS_1_CH_16_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_16);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:17 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_17
*/
#if  ((defined GPT_EMIOS_1_CH_17_ISR_USED) && (defined PWM_EMIOS_1_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if  ((defined PWM_EMIOS_1_CH_17_ISR_USED) && (defined ICU_EMIOS_1_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_17"
#endif

#if  ((defined ICU_EMIOS_1_CH_17_ISR_USED) && (defined GPT_EMIOS_1_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_17"
#endif


#if ( (defined GPT_EMIOS_1_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_17_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 17 for eMios_1 module
* @details   Process the interrupt of eMios channel 17
*
* @note   This will be defined only if eMios channel 17 is configured in GPT, ICU or PWM mode
*/
/*
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_17_ISR)
{

    #if(defined GPT_EMIOS_1_CH_17_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_17);
    #endif

    #if(defined PWM_EMIOS_1_CH_17_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_17);
    #endif

    #if(defined ICU_EMIOS_1_CH_17_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_17);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:18 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_18
*/
#if  ((defined GPT_EMIOS_1_CH_18_ISR_USED) && (defined PWM_EMIOS_1_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_18"
#endif

#if  ((defined PWM_EMIOS_1_CH_18_ISR_USED) && (defined ICU_EMIOS_1_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_18"
#endif

#if  ((defined ICU_EMIOS_1_CH_18_ISR_USED) && (defined GPT_EMIOS_1_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_18"
#endif


#if ( (defined GPT_EMIOS_1_CH_18_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_18_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_18_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 18 for eMios_1 module
* @details   Process the interrupt of eMios channel 18
*
* @note   This will be defined only if eMios channel 18 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_18_ISR)
{

    #if(defined GPT_EMIOS_1_CH_18_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_18);
    #endif

    #if(defined PWM_EMIOS_1_CH_18_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_18);
    #endif

    #if(defined ICU_EMIOS_1_CH_18_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_18);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:19 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_19
*/
#if  ((defined GPT_EMIOS_1_CH_19_ISR_USED) && (defined PWM_EMIOS_1_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if  ((defined PWM_EMIOS_1_CH_19_ISR_USED) && (defined ICU_EMIOS_1_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_19"
#endif

#if  ((defined ICU_EMIOS_1_CH_19_ISR_USED) && (defined GPT_EMIOS_1_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_19"
#endif


#if ( (defined GPT_EMIOS_1_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_19_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 19 for eMios_1 module
* @details   Process the interrupt of eMios channel 19
*
* @note   This will be defined only if eMios channel 19 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_19_ISR)
{

    #if(defined GPT_EMIOS_1_CH_19_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_19);
    #endif

    #if(defined PWM_EMIOS_1_CH_19_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_19);
    #endif

    #if(defined ICU_EMIOS_1_CH_19_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_19);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:20 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_20
*/
#if  ((defined GPT_EMIOS_1_CH_20_ISR_USED) && (defined PWM_EMIOS_1_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_20"
#endif

#if  ((defined PWM_EMIOS_1_CH_20_ISR_USED) && (defined ICU_EMIOS_1_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_20"
#endif

#if  ((defined ICU_EMIOS_1_CH_20_ISR_USED) && (defined GPT_EMIOS_1_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_20"
#endif


#if ( (defined GPT_EMIOS_1_CH_20_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_20_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_20_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 20 for eMios_1 module
* @details   Process the interrupt of eMios channel 20
*
* @note   This will be defined only if eMios channel 20 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_20_ISR)
{

    #if(defined GPT_EMIOS_1_CH_20_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_20);
    #endif

    #if(defined PWM_EMIOS_1_CH_20_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_20);
    #endif

    #if(defined ICU_EMIOS_1_CH_20_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_20);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:21 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_21
*/
#if  ((defined GPT_EMIOS_1_CH_21_ISR_USED) && (defined PWM_EMIOS_1_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if  ((defined PWM_EMIOS_1_CH_21_ISR_USED) && (defined ICU_EMIOS_1_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_21"
#endif

#if  ((defined ICU_EMIOS_1_CH_21_ISR_USED) && (defined GPT_EMIOS_1_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_21"
#endif


#if ( (defined GPT_EMIOS_1_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_21_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 21 for eMios_1 module
* @details   Process the interrupt of eMios channel 21
*
* @note   This will be defined only if eMios channel 21 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_21_ISR)
{

    #if(defined GPT_EMIOS_1_CH_21_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_21);
    #endif

    #if(defined PWM_EMIOS_1_CH_21_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_21);
    #endif

    #if(defined ICU_EMIOS_1_CH_21_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_21);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/**
    @brief EMIOS module:1 channel:22 independent interrupt handler
*/

/**
    @brief resource conflict check for EMIOS_1_CH_22
*/
#if  ((defined GPT_EMIOS_1_CH_22_ISR_USED) && (defined PWM_EMIOS_1_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_22"
#endif

#if  ((defined PWM_EMIOS_1_CH_22_ISR_USED) && (defined ICU_EMIOS_1_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_22"
#endif

#if  ((defined ICU_EMIOS_1_CH_22_ISR_USED) && (defined GPT_EMIOS_1_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_22"
#endif


#if ( (defined GPT_EMIOS_1_CH_22_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_22_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_22_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 22 for eMios_1 module
* @details   Process the interrupt of eMios channel 22
*
* @note   This will be defined only if eMios channel 22 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_22_ISR)
{

    #if(defined GPT_EMIOS_1_CH_22_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_22);
    #endif

    #if(defined PWM_EMIOS_1_CH_22_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_22);
    #endif

    #if(defined ICU_EMIOS_1_CH_22_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_22);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:23 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_23
*/
#if  ((defined GPT_EMIOS_1_CH_23_ISR_USED) && (defined PWM_EMIOS_1_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if  ((defined PWM_EMIOS_1_CH_23_ISR_USED) && (defined ICU_EMIOS_1_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_23"
#endif

#if  ((defined ICU_EMIOS_1_CH_23_ISR_USED) && (defined GPT_EMIOS_1_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_23"
#endif


#if ( (defined GPT_EMIOS_1_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_23_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 23 for eMios_1 module
* @details   Process the interrupt of eMios channel 23
*
* @note   This will be defined only if eMios channel 23 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_23_ISR)
{

    #if(defined GPT_EMIOS_1_CH_23_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_23);
    #endif

    #if(defined PWM_EMIOS_1_CH_23_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_23);
    #endif

    #if(defined ICU_EMIOS_1_CH_23_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_23);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:24 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_24
*/
#if  ((defined GPT_EMIOS_1_CH_24_ISR_USED) && (defined PWM_EMIOS_1_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_24"
#endif

#if  ((defined PWM_EMIOS_1_CH_24_ISR_USED) && (defined ICU_EMIOS_1_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_24"
#endif

#if  ((defined ICU_EMIOS_1_CH_24_ISR_USED) && (defined GPT_EMIOS_1_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_24"
#endif


#if ( (defined GPT_EMIOS_1_CH_24_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_24_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_24_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 24 for eMios_1 module
* @details   Process the interrupt of eMios channel 24
*
* @note   This will be defined only if eMios channel 24 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_24_ISR)
{

    #if(defined GPT_EMIOS_1_CH_24_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_24);
    #endif

    #if(defined PWM_EMIOS_1_CH_24_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_24);
    #endif

    #if(defined ICU_EMIOS_1_CH_24_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_24);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:25 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_25
*/
#if  ((defined GPT_EMIOS_1_CH_25_ISR_USED) && (defined PWM_EMIOS_1_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if  ((defined PWM_EMIOS_1_CH_25_ISR_USED) && (defined ICU_EMIOS_1_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_25"
#endif

#if  ((defined ICU_EMIOS_1_CH_25_ISR_USED) && (defined GPT_EMIOS_1_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_25"
#endif


#if ( (defined GPT_EMIOS_1_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_25_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 25 for eMios_1 module
* @details   Process the interrupt of eMios channel 25
*
* @note   This will be defined only if eMios channel 25 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_25_ISR)
{

    #if(defined GPT_EMIOS_1_CH_25_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_25);
    #endif

    #if(defined PWM_EMIOS_1_CH_25_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_25);
    #endif

    #if(defined ICU_EMIOS_1_CH_25_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_25);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:26 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_26
*/
#if  ((defined GPT_EMIOS_1_CH_26_ISR_USED) && (defined PWM_EMIOS_1_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_26"
#endif

#if  ((defined PWM_EMIOS_1_CH_26_ISR_USED) && (defined ICU_EMIOS_1_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_26"
#endif

#if  ((defined ICU_EMIOS_1_CH_26_ISR_USED) && (defined GPT_EMIOS_1_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_26"
#endif


#if ( (defined GPT_EMIOS_1_CH_26_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_26_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_26_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 26 for eMios_1 module
* @details   Process the interrupt of eMios channel 26
*
* @note   This will be defined only if eMios channel 26 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_26_ISR)
{

    #if(defined GPT_EMIOS_1_CH_26_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_26);
    #endif

    #if(defined PWM_EMIOS_1_CH_26_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_26);
    #endif

    #if(defined ICU_EMIOS_1_CH_26_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_26);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:27 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_27
*/
#if  ((defined GPT_EMIOS_1_CH_27_ISR_USED) && (defined PWM_EMIOS_1_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if  ((defined PWM_EMIOS_1_CH_27_ISR_USED) && (defined ICU_EMIOS_1_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_27"
#endif

#if  ((defined ICU_EMIOS_1_CH_27_ISR_USED) && (defined GPT_EMIOS_1_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_27"
#endif


#if ( (defined GPT_EMIOS_1_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_27_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 27 for eMios_1 module
* @details   Process the interrupt of eMios channel 27
*
* @note   This will be defined only if eMios channel 27 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_27_ISR)
{

    #if(defined GPT_EMIOS_1_CH_27_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_27);
    #endif

    #if(defined PWM_EMIOS_1_CH_27_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_27);
    #endif

    #if(defined ICU_EMIOS_1_CH_27_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_27);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:28 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_28
*/
#if  ((defined GPT_EMIOS_1_CH_28_ISR_USED) && (defined PWM_EMIOS_1_CH_28_ISR_USED))
#error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_28"
#endif

#if  ((defined PWM_EMIOS_1_CH_28_ISR_USED) && (defined ICU_EMIOS_1_CH_28_ISR_USED))
#error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_28"
#endif

#if  ((defined ICU_EMIOS_1_CH_28_ISR_USED) && (defined GPT_EMIOS_1_CH_28_ISR_USED))
#error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_28"
#endif


#if ( (defined GPT_EMIOS_1_CH_28_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_28_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_28_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 28 for eMios_1 module
* @details   Process the interrupt of eMios channel 28
*
* @note   This will be defined only if eMios channel 28 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_28_ISR)
{

    #if(defined GPT_EMIOS_1_CH_28_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_28);
    #endif

    #if(defined PWM_EMIOS_1_CH_28_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_28);
    #endif

    #if(defined ICU_EMIOS_1_CH_28_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_28);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:29 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_29
*/
#if  ((defined GPT_EMIOS_1_CH_29_ISR_USED) && (defined PWM_EMIOS_1_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if  ((defined PWM_EMIOS_1_CH_29_ISR_USED) && (defined ICU_EMIOS_1_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_29"
#endif

#if  ((defined ICU_EMIOS_1_CH_29_ISR_USED) && (defined GPT_EMIOS_1_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_29"
#endif


#if ( (defined GPT_EMIOS_1_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_29_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 29 for eMios_1 module
* @details   Process the interrupt of eMios channel 29
*
* @note   This will be defined only if eMios channel 29 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_29_ISR)
{

    #if(defined GPT_EMIOS_1_CH_29_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_29);
    #endif

    #if(defined PWM_EMIOS_1_CH_29_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_29);
    #endif

    #if(defined ICU_EMIOS_1_CH_29_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_29);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:30 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_30
*/
#if  ((defined GPT_EMIOS_1_CH_30_ISR_USED) && (defined PWM_EMIOS_1_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

#if  ((defined PWM_EMIOS_1_CH_30_ISR_USED) && (defined ICU_EMIOS_1_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_30"
#endif

#if  ((defined ICU_EMIOS_1_CH_30_ISR_USED) && (defined GPT_EMIOS_1_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_30"
#endif


#if ( (defined GPT_EMIOS_1_CH_30_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_30_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_30_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 30 for eMios_1 module
* @details   Process the interrupt of eMios channel 30
*
* @note   This will be defined only if eMios channel 30 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_30_ISR)
{

    #if(defined GPT_EMIOS_1_CH_30_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_30);
    #endif

    #if(defined PWM_EMIOS_1_CH_30_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_30);
    #endif

    #if(defined ICU_EMIOS_1_CH_30_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_30);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:1 channel:31 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_1_CH_31
*/
#if  ((defined GPT_EMIOS_1_CH_31_ISR_USED) && (defined PWM_EMIOS_1_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if  ((defined PWM_EMIOS_1_CH_31_ISR_USED) && (defined ICU_EMIOS_1_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_1_31"
#endif

#if  ((defined ICU_EMIOS_1_CH_31_ISR_USED) && (defined GPT_EMIOS_1_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_1_31"
#endif


#if ( (defined GPT_EMIOS_1_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_1_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_1_CH_31_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 31 for eMios_1 module
* @details   Process the interrupt of eMios channel 31
*
* @note   This will be defined only if eMios channel 31 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_1_CH_31_ISR)
{

    #if(defined GPT_EMIOS_1_CH_31_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_1_CH_31);
    #endif

    #if(defined PWM_EMIOS_1_CH_31_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_1_CH_31);
    #endif

    #if(defined ICU_EMIOS_1_CH_31_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_1_CH_31);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif



/*********************************** EMIOS 1 independent interrupts END ***************************/

/********************************** EMIOS 2 independent interrupts START **************************/

/*
* @brief EMIOS module:2 channel:0 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_0
*/
#if  ((defined GPT_EMIOS_2_CH_0_ISR_USED) && (defined PWM_EMIOS_2_CH_0_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_0"
#endif

#if  ((defined PWM_EMIOS_2_CH_0_ISR_USED) && (defined ICU_EMIOS_2_CH_0_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_0"
#endif

#if  ((defined ICU_EMIOS_2_CH_0_ISR_USED) && (defined GPT_EMIOS_2_CH_0_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_0"
#endif


#if ( (defined GPT_EMIOS_2_CH_0_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_0_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_0_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 0 for eMios_2 module
* @details   Process the interrupt of eMios channel 0
*
* @note   This will be defined only if eMios channel 0 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_0_ISR)
{

    #if(defined GPT_EMIOS_2_CH_0_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_0);
    #endif

    #if(defined PWM_EMIOS_2_CH_0_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_0);
    #endif

    #if(defined ICU_EMIOS_2_CH_0_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_0);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:1 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_1
*/
#if  ((defined GPT_EMIOS_2_CH_1_ISR_USED) && (defined PWM_EMIOS_2_CH_1_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if  ((defined PWM_EMIOS_2_CH_1_ISR_USED) && (defined ICU_EMIOS_2_CH_1_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_1"
#endif

#if  ((defined ICU_EMIOS_2_CH_1_ISR_USED) && (defined GPT_EMIOS_2_CH_1_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_1"
#endif


#if ( (defined GPT_EMIOS_2_CH_1_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_1_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_1_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 1 for eMios_2 module
* @details   Process the interrupt of eMios channel 1
*
* @note   This will be defined only if eMios channel 1 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_1_ISR)
{

    #if(defined GPT_EMIOS_2_CH_1_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_1);
    #endif

    #if(defined PWM_EMIOS_2_CH_1_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_1);
    #endif

    #if(defined ICU_EMIOS_2_CH_1_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_1);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:2 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_2
*/
#if  ((defined GPT_EMIOS_2_CH_2_ISR_USED) && (defined PWM_EMIOS_2_CH_2_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_2"
#endif

#if  ((defined PWM_EMIOS_2_CH_2_ISR_USED) && (defined ICU_EMIOS_2_CH_2_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_2"
#endif

#if  ((defined ICU_EMIOS_2_CH_2_ISR_USED) && (defined GPT_EMIOS_2_CH_2_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_2"
#endif


#if ( (defined GPT_EMIOS_2_CH_2_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_2_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_2_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 2 for eMios_2 module
* @details   Process the interrupt of eMios channel 2
*
* @note   This will be defined only if eMios channel 2 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_2_ISR)
{

    #if(defined GPT_EMIOS_2_CH_2_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_2);
    #endif

    #if(defined PWM_EMIOS_2_CH_2_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_2);
    #endif

    #if(defined ICU_EMIOS_2_CH_2_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_2);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:3 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_3
*/
#if  ((defined GPT_EMIOS_2_CH_3_ISR_USED) && (defined PWM_EMIOS_2_CH_3_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if  ((defined PWM_EMIOS_2_CH_3_ISR_USED) && (defined ICU_EMIOS_2_CH_3_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_3"
#endif

#if  ((defined ICU_EMIOS_2_CH_3_ISR_USED) && (defined GPT_EMIOS_2_CH_3_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_3"
#endif


#if ( (defined GPT_EMIOS_2_CH_3_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_3_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_3_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 3 for eMios_2 module
* @details   Process the interrupt of eMios channel 3
*
* @note   This will be defined only if eMios channel 3 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_3_ISR)
{

    #if(defined GPT_EMIOS_2_CH_3_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_3);
    #endif

    #if(defined PWM_EMIOS_2_CH_3_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_3);
    #endif

    #if(defined ICU_EMIOS_2_CH_3_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_3);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:4 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_4
*/
#if  ((defined GPT_EMIOS_2_CH_4_ISR_USED) && (defined PWM_EMIOS_2_CH_4_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_4"
#endif

#if  ((defined PWM_EMIOS_2_CH_4_ISR_USED) && (defined ICU_EMIOS_2_CH_4_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_4"
#endif

#if  ((defined ICU_EMIOS_2_CH_4_ISR_USED) && (defined GPT_EMIOS_2_CH_4_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_4"
#endif


#if ( (defined GPT_EMIOS_2_CH_4_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_4_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_4_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 4 for eMios_2 module
* @details   Process the interrupt of eMios channel 4
*
* @note   This will be defined only if eMios channel 4 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_4_ISR)
{

    #if(defined GPT_EMIOS_2_CH_4_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_4);
    #endif

    #if(defined PWM_EMIOS_2_CH_4_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_4);
    #endif

    #if(defined ICU_EMIOS_2_CH_4_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_4);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:5 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_5
*/
#if  ((defined GPT_EMIOS_2_CH_5_ISR_USED) && (defined PWM_EMIOS_2_CH_5_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if  ((defined PWM_EMIOS_2_CH_5_ISR_USED) && (defined ICU_EMIOS_2_CH_5_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_5"
#endif

#if  ((defined ICU_EMIOS_2_CH_5_ISR_USED) && (defined GPT_EMIOS_2_CH_5_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_5"
#endif


#if ( (defined GPT_EMIOS_2_CH_5_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_5_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_5_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 5 for eMios_2 module
* @details   Process the interrupt of eMios channel 5
*
* @note   This will be defined only if eMios channel 5 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_5_ISR)
{

    #if(defined GPT_EMIOS_2_CH_5_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_5);
    #endif

    #if(defined PWM_EMIOS_2_CH_5_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_5);
    #endif

    #if(defined ICU_EMIOS_2_CH_5_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_5);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:6 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_6
*/
#if  ((defined GPT_EMIOS_2_CH_6_ISR_USED) && (defined PWM_EMIOS_2_CH_6_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_6"
#endif

#if  ((defined PWM_EMIOS_2_CH_6_ISR_USED) && (defined ICU_EMIOS_2_CH_6_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_6"
#endif

#if  ((defined ICU_EMIOS_2_CH_6_ISR_USED) && (defined GPT_EMIOS_2_CH_6_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_6"
#endif


#if ( (defined GPT_EMIOS_2_CH_6_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_6_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_6_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 6 for eMios_2 module
* @details   Process the interrupt of eMios channel 6
*
* @note   This will be defined only if eMios channel 6 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_6_ISR)
{

    #if(defined GPT_EMIOS_2_CH_6_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_6);
    #endif

    #if(defined PWM_EMIOS_2_CH_6_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_6);
    #endif

    #if(defined ICU_EMIOS_2_CH_6_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_6);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:7 independent interrupt handler
*/

/*
* @brief resource conflict check for EMIOS_2_CH_7
*/
#if  ((defined GPT_EMIOS_2_CH_7_ISR_USED) && (defined PWM_EMIOS_2_CH_7_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if  ((defined PWM_EMIOS_2_CH_7_ISR_USED) && (defined ICU_EMIOS_2_CH_7_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_7"
#endif

#if  ((defined ICU_EMIOS_2_CH_7_ISR_USED) && (defined GPT_EMIOS_2_CH_7_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_7"
#endif


#if ( (defined GPT_EMIOS_2_CH_7_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_7_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_7_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 7 for eMios_2 module
* @details   Process the interrupt of eMios channel 7
*
* @note   This will be defined only if eMios channel 7 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_7_ISR)
{

    #if(defined GPT_EMIOS_2_CH_7_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_7);
    #endif

    #if(defined PWM_EMIOS_2_CH_7_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_7);
    #endif

    #if(defined ICU_EMIOS_2_CH_7_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_7);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:8 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_8
*/

#if  ((defined GPT_EMIOS_2_CH_8_ISR_USED) && (defined PWM_EMIOS_2_CH_8_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_8"
#endif

#if  ((defined PWM_EMIOS_2_CH_8_ISR_USED) && (defined ICU_EMIOS_2_CH_8_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_8"
#endif

#if  ((defined ICU_EMIOS_2_CH_8_ISR_USED) && (defined GPT_EMIOS_2_CH_8_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_8"
#endif


#if ( (defined GPT_EMIOS_2_CH_8_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_8_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_8_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 8 for eMios_2 module
* @details   Process the interrupt of eMios channel 8
*
* @note   This will be defined only if eMios channel 8 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_8_ISR)
{

    #if(defined GPT_EMIOS_2_CH_8_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_8);
    #endif

    #if(defined PWM_EMIOS_2_CH_8_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_8);
    #endif

    #if(defined ICU_EMIOS_2_CH_8_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_8);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:9 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_9
*/
#if  ((defined GPT_EMIOS_2_CH_9_ISR_USED) && (defined PWM_EMIOS_2_CH_9_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if  ((defined PWM_EMIOS_2_CH_9_ISR_USED) && (defined ICU_EMIOS_2_CH_9_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_9"
#endif

#if  ((defined ICU_EMIOS_2_CH_9_ISR_USED) && (defined GPT_EMIOS_2_CH_9_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_9"
#endif


#if ( (defined GPT_EMIOS_2_CH_9_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_9_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_9_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 9 for eMios_2 module
* @details   Process the interrupt of eMios channel 9
*
* @note   This will be defined only if eMios channel 9 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_9_ISR)
{

    #if(defined GPT_EMIOS_2_CH_9_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_9);
    #endif

    #if(defined PWM_EMIOS_2_CH_9_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_9);
    #endif

    #if(defined ICU_EMIOS_2_CH_9_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_9);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:10 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_10
*/
#if  ((defined GPT_EMIOS_2_CH_10_ISR_USED) && (defined PWM_EMIOS_2_CH_10_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_10"
#endif

#if  ((defined PWM_EMIOS_2_CH_10_ISR_USED) && (defined ICU_EMIOS_2_CH_10_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_10"
#endif

#if  ((defined ICU_EMIOS_2_CH_10_ISR_USED) && (defined GPT_EMIOS_2_CH_10_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_10"
#endif


#if ( (defined GPT_EMIOS_2_CH_10_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_10_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_10_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 10 for eMios_2 module
* @details   Process the interrupt of eMios channel 10
*
* @note   This will be defined only if eMios channel 10 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_10_ISR)
{

    #if(defined GPT_EMIOS_2_CH_10_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_10);
    #endif

    #if(defined PWM_EMIOS_2_CH_10_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_10);
    #endif

    #if(defined ICU_EMIOS_2_CH_10_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_10);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:11 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_11
*/
#if  ((defined GPT_EMIOS_2_CH_11_ISR_USED) && (defined PWM_EMIOS_2_CH_11_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if  ((defined PWM_EMIOS_2_CH_11_ISR_USED) && (defined ICU_EMIOS_2_CH_11_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_11"
#endif

#if  ((defined ICU_EMIOS_2_CH_11_ISR_USED) && (defined GPT_EMIOS_2_CH_11_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_11"
#endif


#if ( (defined GPT_EMIOS_2_CH_11_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_11_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_11_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 11 for eMios_2 module
* @details   Process the interrupt of eMios channel 11
*
* @note   This will be defined only if eMios channel 11 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_11_ISR)
{

    #if(defined GPT_EMIOS_2_CH_11_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_11);
    #endif

    #if(defined PWM_EMIOS_2_CH_11_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_11);
    #endif

    #if(defined ICU_EMIOS_2_CH_11_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_11);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:12 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_12
*/
#if  ((defined GPT_EMIOS_2_CH_12_ISR_USED) && (defined PWM_EMIOS_2_CH_12_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_12"
#endif

#if  ((defined PWM_EMIOS_2_CH_12_ISR_USED) && (defined ICU_EMIOS_2_CH_12_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_12"
#endif

#if  ((defined ICU_EMIOS_2_CH_12_ISR_USED) && (defined GPT_EMIOS_2_CH_12_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_12"
#endif


#if ( (defined GPT_EMIOS_2_CH_12_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_12_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_12_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 12 for eMios_2 module
* @details   Process the interrupt of eMios channel 12
*
* @note   This will be defined only if eMios channel 12 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_12_ISR)
{

    #if(defined GPT_EMIOS_2_CH_12_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_12);
    #endif

    #if(defined PWM_EMIOS_2_CH_12_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_12);
    #endif

    #if(defined ICU_EMIOS_2_CH_12_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_12);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:13 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_13
*/
#if  ((defined GPT_EMIOS_2_CH_13_ISR_USED) && (defined PWM_EMIOS_2_CH_13_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if  ((defined PWM_EMIOS_2_CH_13_ISR_USED) && (defined ICU_EMIOS_2_CH_13_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_13"
#endif

#if  ((defined ICU_EMIOS_2_CH_13_ISR_USED) && (defined GPT_EMIOS_2_CH_13_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_13"
#endif


#if ( (defined GPT_EMIOS_2_CH_13_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_13_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_13_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 13 for eMios_2 module
* @details   Process the interrupt of eMios channel 13
*
* @note   This will be defined only if eMios channel 13 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_13_ISR)
{

    #if(defined GPT_EMIOS_2_CH_13_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_13);
    #endif

    #if(defined PWM_EMIOS_2_CH_13_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_13);
    #endif

    #if(defined ICU_EMIOS_2_CH_13_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_13);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:14 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_14
*/
#if  ((defined GPT_EMIOS_2_CH_14_ISR_USED) && (defined PWM_EMIOS_2_CH_14_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_14"
#endif

#if  ((defined PWM_EMIOS_2_CH_14_ISR_USED) && (defined ICU_EMIOS_2_CH_14_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_14"
#endif

#if  ((defined ICU_EMIOS_2_CH_14_ISR_USED) && (defined GPT_EMIOS_2_CH_14_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_14"
#endif


#if ( (defined GPT_EMIOS_2_CH_14_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_14_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_14_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 14 for eMios_2 module
* @details   Process the interrupt of eMios channel 14
*
* @note   This will be defined only if eMios channel 14 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_14_ISR)
{

    #if(defined GPT_EMIOS_2_CH_14_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_14);
    #endif

    #if(defined PWM_EMIOS_2_CH_14_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_14);
    #endif

    #if(defined ICU_EMIOS_2_CH_14_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_14);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:15 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_15
*/
#if  ((defined GPT_EMIOS_2_CH_15_ISR_USED) && (defined PWM_EMIOS_2_CH_15_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if  ((defined PWM_EMIOS_2_CH_15_ISR_USED) && (defined ICU_EMIOS_2_CH_15_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_15"
#endif

#if  ((defined ICU_EMIOS_2_CH_15_ISR_USED) && (defined GPT_EMIOS_2_CH_15_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_15"
#endif


#if ( (defined GPT_EMIOS_2_CH_15_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_15_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_15_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 15 for eMios_2 module
* @details   Process the interrupt of eMios channel 15
*
* @note   This will be defined only if eMios channel 15 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_15_ISR)
{

    #if(defined GPT_EMIOS_2_CH_15_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_15);
    #endif

    #if(defined PWM_EMIOS_2_CH_15_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_15);
    #endif

    #if(defined ICU_EMIOS_2_CH_15_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_15);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:16 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_16
*/
#if  ((defined GPT_EMIOS_2_CH_16_ISR_USED) && (defined PWM_EMIOS_2_CH_16_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_16"
#endif

#if  ((defined PWM_EMIOS_2_CH_16_ISR_USED) && (defined ICU_EMIOS_2_CH_16_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_16"
#endif

#if  ((defined ICU_EMIOS_2_CH_16_ISR_USED) && (defined GPT_EMIOS_2_CH_16_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_16"
#endif


#if ( (defined GPT_EMIOS_2_CH_16_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_16_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_16_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 16 for eMios_2 module
* @details   Process the interrupt of eMios channel 16
*
* @note   This will be defined only if eMios channel 16 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_16_ISR)
{

    #if(defined GPT_EMIOS_2_CH_16_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_16);
    #endif

    #if(defined PWM_EMIOS_2_CH_16_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_16);
    #endif

    #if(defined ICU_EMIOS_2_CH_16_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_16);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:17 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_17
*/
#if  ((defined GPT_EMIOS_2_CH_17_ISR_USED) && (defined PWM_EMIOS_2_CH_17_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if  ((defined PWM_EMIOS_2_CH_17_ISR_USED) && (defined ICU_EMIOS_2_CH_17_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_17"
#endif

#if  ((defined ICU_EMIOS_2_CH_17_ISR_USED) && (defined GPT_EMIOS_2_CH_17_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_17"
#endif


#if ( (defined GPT_EMIOS_2_CH_17_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_17_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_17_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 17 for eMios_2 module
* @details   Process the interrupt of eMios channel 17
*
* @note   This will be defined only if eMios channel 17 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_17_ISR)
{

    #if(defined GPT_EMIOS_2_CH_17_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_17);
    #endif

    #if(defined PWM_EMIOS_2_CH_17_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_17);
    #endif

    #if(defined ICU_EMIOS_2_CH_17_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_17);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:18 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_18
*/
#if  ((defined GPT_EMIOS_2_CH_18_ISR_USED) && (defined PWM_EMIOS_2_CH_18_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_18"
#endif

#if  ((defined PWM_EMIOS_2_CH_18_ISR_USED) && (defined ICU_EMIOS_2_CH_18_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_18"
#endif

#if  ((defined ICU_EMIOS_2_CH_18_ISR_USED) && (defined GPT_EMIOS_2_CH_18_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_18"
#endif


#if ( (defined GPT_EMIOS_2_CH_18_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_18_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_18_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 18 for eMios_2 module
* @details   Process the interrupt of eMios channel 18
*
* @note   This will be defined only if eMios channel 18 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_18_ISR)
{

    #if(defined GPT_EMIOS_2_CH_18_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_18);
    #endif

    #if(defined PWM_EMIOS_2_CH_18_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_18);
    #endif

    #if(defined ICU_EMIOS_2_CH_18_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_18);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:19 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_19
*/
#if  ((defined GPT_EMIOS_2_CH_19_ISR_USED) && (defined PWM_EMIOS_2_CH_19_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if  ((defined PWM_EMIOS_2_CH_19_ISR_USED) && (defined ICU_EMIOS_2_CH_19_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_19"
#endif

#if  ((defined ICU_EMIOS_2_CH_19_ISR_USED) && (defined GPT_EMIOS_2_CH_19_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_19"
#endif


#if ( (defined GPT_EMIOS_2_CH_19_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_19_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_19_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 19 for eMios_2 module
* @details   Process the interrupt of eMios channel 19
*
* @note   This will be defined only if eMios channel 19 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_19_ISR)
{

    #if(defined GPT_EMIOS_2_CH_19_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_19);
    #endif

    #if(defined PWM_EMIOS_2_CH_19_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_19);
    #endif

    #if(defined ICU_EMIOS_2_CH_19_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_19);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:20 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_20
*/
#if  ((defined GPT_EMIOS_2_CH_20_ISR_USED) && (defined PWM_EMIOS_2_CH_20_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_20"
#endif

#if  ((defined PWM_EMIOS_2_CH_20_ISR_USED) && (defined ICU_EMIOS_2_CH_20_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_20"
#endif

#if  ((defined ICU_EMIOS_2_CH_20_ISR_USED) && (defined GPT_EMIOS_2_CH_20_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_20"
#endif


#if ( (defined GPT_EMIOS_2_CH_20_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_20_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_20_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 20 for eMios_2 module
* @details   Process the interrupt of eMios channel 20
*
* @note   This will be defined only if eMios channel 20 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_20_ISR)
{

    #if(defined GPT_EMIOS_2_CH_20_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_20);
    #endif

    #if(defined PWM_EMIOS_2_CH_20_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_20);
    #endif

    #if(defined ICU_EMIOS_2_CH_20_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_20);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:21 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_21
*/
#if  ((defined GPT_EMIOS_2_CH_21_ISR_USED) && (defined PWM_EMIOS_2_CH_21_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if  ((defined PWM_EMIOS_2_CH_21_ISR_USED) && (defined ICU_EMIOS_2_CH_21_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_21"
#endif

#if  ((defined ICU_EMIOS_2_CH_21_ISR_USED) && (defined GPT_EMIOS_2_CH_21_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_21"
#endif


#if ( (defined GPT_EMIOS_2_CH_21_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_21_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_21_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 21 for eMios_2 module
* @details   Process the interrupt of eMios channel 21
*
* @note   This will be defined only if eMios channel 21 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_21_ISR)
{

    #if(defined GPT_EMIOS_2_CH_21_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_21);
    #endif

    #if(defined PWM_EMIOS_2_CH_21_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_21);
    #endif

    #if(defined ICU_EMIOS_2_CH_21_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_21);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:22 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_22
*/
#if  ((defined GPT_EMIOS_2_CH_22_ISR_USED) && (defined PWM_EMIOS_2_CH_22_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_22"
#endif

#if  ((defined PWM_EMIOS_2_CH_22_ISR_USED) && (defined ICU_EMIOS_2_CH_22_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_22"
#endif

#if  ((defined ICU_EMIOS_2_CH_22_ISR_USED) && (defined GPT_EMIOS_2_CH_22_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_22"
#endif


#if ( (defined GPT_EMIOS_2_CH_22_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_22_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_22_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 22 for eMios_2 module
* @details   Process the interrupt of eMios channel 22
*
* @note   This will be defined only if eMios channel 22 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_22_ISR)
{

    #if(defined GPT_EMIOS_2_CH_22_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_22);
    #endif

    #if(defined PWM_EMIOS_2_CH_22_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_22);
    #endif

    #if(defined ICU_EMIOS_2_CH_22_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_22);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:23 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_23
*/
#if  ((defined GPT_EMIOS_2_CH_23_ISR_USED) && (defined PWM_EMIOS_2_CH_23_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if  ((defined PWM_EMIOS_2_CH_23_ISR_USED) && (defined ICU_EMIOS_2_CH_23_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_23"
#endif

#if  ((defined ICU_EMIOS_2_CH_23_ISR_USED) && (defined GPT_EMIOS_2_CH_23_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_23"
#endif


#if ( (defined GPT_EMIOS_2_CH_23_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_23_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_23_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 23 for eMios_2 module
* @details   Process the interrupt of eMios channel 23
*
* @note   This will be defined only if eMios channel 23 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_23_ISR)
{

    #if(defined GPT_EMIOS_2_CH_23_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_23);
    #endif

    #if(defined PWM_EMIOS_2_CH_23_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_23);
    #endif

    #if(defined ICU_EMIOS_2_CH_23_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_23);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:24 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_24
*/
#if  ((defined GPT_EMIOS_2_CH_24_ISR_USED) && (defined PWM_EMIOS_2_CH_24_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_24"
#endif

#if  ((defined PWM_EMIOS_2_CH_24_ISR_USED) && (defined ICU_EMIOS_2_CH_24_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_24"
#endif

#if  ((defined ICU_EMIOS_2_CH_24_ISR_USED) && (defined GPT_EMIOS_2_CH_24_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_24"
#endif


#if ( (defined GPT_EMIOS_2_CH_24_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_24_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_24_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 24 for eMios_2 module
* @details   Process the interrupt of eMios channel 24
*
* @note   This will be defined only if eMios channel 24 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_24_ISR)
{

    #if(defined GPT_EMIOS_2_CH_24_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_24);
    #endif

    #if(defined PWM_EMIOS_2_CH_24_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_24);
    #endif

    #if(defined ICU_EMIOS_2_CH_24_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_24);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:25 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_25
*/
#if  ((defined GPT_EMIOS_2_CH_25_ISR_USED) && (defined PWM_EMIOS_2_CH_25_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if  ((defined PWM_EMIOS_2_CH_25_ISR_USED) && (defined ICU_EMIOS_2_CH_25_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_25"
#endif

#if  ((defined ICU_EMIOS_2_CH_25_ISR_USED) && (defined GPT_EMIOS_2_CH_25_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_25"
#endif


#if ( (defined GPT_EMIOS_2_CH_25_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_25_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_25_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 25 for eMios_2 module
* @details   Process the interrupt of eMios channel 25
*
* @note   This will be defined only if eMios channel 25 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_25_ISR)
{

    #if(defined GPT_EMIOS_2_CH_25_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_25);
    #endif

    #if(defined PWM_EMIOS_2_CH_25_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_25);
    #endif

    #if(defined ICU_EMIOS_2_CH_25_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_25);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:26 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_26
*/
#if  ((defined GPT_EMIOS_2_CH_26_ISR_USED) && (defined PWM_EMIOS_2_CH_26_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_26"
#endif

#if  ((defined PWM_EMIOS_2_CH_26_ISR_USED) && (defined ICU_EMIOS_2_CH_26_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_26"
#endif

#if  ((defined ICU_EMIOS_2_CH_26_ISR_USED) && (defined GPT_EMIOS_2_CH_26_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_26"
#endif


#if ( (defined GPT_EMIOS_2_CH_26_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_26_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_26_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 26 for eMios_2 module
* @details   Process the interrupt of eMios channel 26
*
* @note   This will be defined only if eMios channel 26 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_26_ISR)
{

    #if(defined GPT_EMIOS_2_CH_26_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_26);
    #endif

    #if(defined PWM_EMIOS_2_CH_26_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_26);
    #endif

    #if(defined ICU_EMIOS_2_CH_26_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_26);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:27 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_27
*/
#if  ((defined GPT_EMIOS_2_CH_27_ISR_USED) && (defined PWM_EMIOS_2_CH_27_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if  ((defined PWM_EMIOS_2_CH_27_ISR_USED) && (defined ICU_EMIOS_2_CH_27_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_27"
#endif

#if  ((defined ICU_EMIOS_2_CH_27_ISR_USED) && (defined GPT_EMIOS_2_CH_27_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_27"
#endif


#if ( (defined GPT_EMIOS_2_CH_27_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_27_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_27_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 27 for eMios_2 module
* @details   Process the interrupt of eMios channel 27
*
* @note   This will be defined only if eMios channel 27 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_27_ISR)
{

    #if(defined GPT_EMIOS_2_CH_27_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_27);
    #endif

    #if(defined PWM_EMIOS_2_CH_27_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_27);
    #endif

    #if(defined ICU_EMIOS_2_CH_27_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_27);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:28 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_28
*/
#if  ((defined GPT_EMIOS_2_CH_28_ISR_USED) && (defined PWM_EMIOS_2_CH_28_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_28"
#endif

#if  ((defined PWM_EMIOS_2_CH_28_ISR_USED) && (defined ICU_EMIOS_2_CH_28_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_28"
#endif

#if  ((defined ICU_EMIOS_2_CH_28_ISR_USED) && (defined GPT_EMIOS_2_CH_28_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_28"
#endif


#if ( (defined GPT_EMIOS_2_CH_28_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_28_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_28_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 28 for eMios_2 module
* @details   Process the interrupt of eMios channel 28
*
* @note   This will be defined only if eMios channel 28 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_28_ISR)
{

    #if(defined GPT_EMIOS_2_CH_28_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_28);
    #endif

    #if(defined PWM_EMIOS_2_CH_28_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_28);
    #endif

    #if(defined ICU_EMIOS_2_CH_28_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_28);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:29 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_29
*/
#if  ((defined GPT_EMIOS_2_CH_29_ISR_USED) && (defined PWM_EMIOS_2_CH_29_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if  ((defined PWM_EMIOS_2_CH_29_ISR_USED) && (defined ICU_EMIOS_2_CH_29_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_29"
#endif

#if  ((defined ICU_EMIOS_2_CH_29_ISR_USED) && (defined GPT_EMIOS_2_CH_29_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_29"
#endif


#if ( (defined GPT_EMIOS_2_CH_29_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_29_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_29_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 29 for eMios_2 module
* @details   Process the interrupt of eMios channel 29
*
* @note   This will be defined only if eMios channel 29 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_29_ISR)
{

    #if(defined GPT_EMIOS_2_CH_29_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_29);
    #endif

    #if(defined PWM_EMIOS_2_CH_29_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_29);
    #endif

    #if(defined ICU_EMIOS_2_CH_29_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_29);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:30 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_30
*/
#if  ((defined GPT_EMIOS_2_CH_30_ISR_USED) && (defined PWM_EMIOS_2_CH_30_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_30"
#endif

#if  ((defined PWM_EMIOS_2_CH_30_ISR_USED) && (defined ICU_EMIOS_2_CH_30_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_30"
#endif

#if  ((defined ICU_EMIOS_2_CH_30_ISR_USED) && (defined GPT_EMIOS_2_CH_30_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_30"
#endif


#if ( (defined GPT_EMIOS_2_CH_30_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_30_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_30_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 30 for eMios_2 module
* @details   Process the interrupt of eMios channel 30
*
* @note   This will be defined only if eMios channel 30 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_30_ISR)
{

    #if(defined GPT_EMIOS_2_CH_30_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_30);
    #endif

    #if(defined PWM_EMIOS_2_CH_30_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_30);
    #endif

    #if(defined ICU_EMIOS_2_CH_30_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_30);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif


/*
* @brief EMIOS module:2 channel:31 independent interrupt handler
*/

/**
* @brief resource conflict check for EMIOS_2_CH_31
*/
#if  ((defined GPT_EMIOS_2_CH_31_ISR_USED) && (defined PWM_EMIOS_2_CH_31_ISR_USED))
    #error "GPT and PWM resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if  ((defined PWM_EMIOS_2_CH_31_ISR_USED) && (defined ICU_EMIOS_2_CH_31_ISR_USED))
    #error "PWM and ICU resource conflict for EMIOS unified channel EMIOS_2_31"
#endif

#if  ((defined ICU_EMIOS_2_CH_31_ISR_USED) && (defined GPT_EMIOS_2_CH_31_ISR_USED))
    #error "ICU and GPT resource conflict for EMIOS unified channel EMIOS_2_31"
#endif


#if ( (defined GPT_EMIOS_2_CH_31_ISR_USED) || \
      (defined PWM_EMIOS_2_CH_31_ISR_USED) || \
      (defined ICU_EMIOS_2_CH_31_ISR_USED) )
/*================================================================================================*/
/**
* @brief     Interrupt handler for eMios channel : 31 for eMios_2 module
* @details   Process the interrupt of eMios channel 31
*
* @note   This will be defined only if eMios channel 31 is configured in GPT, ICU or PWM mode
* @violates @ref eMios_Common_c_5 This is not a standard library macro,
*/
ISR(EMIOS_2_CH_31_ISR)
{

    #if(defined GPT_EMIOS_2_CH_31_ISR_USED)
         Gpt_eMios_ProcessCommonInterrupt(EMIOS_2_CH_31);
    #endif

    #if(defined PWM_EMIOS_2_CH_31_ISR_USED)
         Pwm_eMios_ProcessCommonInterrupt(EMIOS_2_CH_31);
    #endif

    #if(defined ICU_EMIOS_2_CH_31_ISR_USED)
         Icu_eMios_ProcessCommonInterrupt(EMIOS_2_CH_31);
    #endif

    /** @violates @ref eMios_Common_c_3 Cast from unsigned long to pointer*/
    EXIT_INTERRUPT();
}
#endif

/*********************************** EMIOS 2 independent interrupts END ***************************/

#endif  /* EMIOS_COMMON_ISR_HANDLER == STD_ON */
#else
#error "Unknown EMIOS interrupt handler type, EMIOS_COMMON_ISR_HANDLER is undefined";
#endif /* #ifdef EMIOS_COMMON_ISR_HANDLER */


#define MCL_STOP_SEC_CODE
/**@violates @ref eMios_Common_c_1 only preprocessor statements and comments before "#include"
 **@violates @ref eMios_Common_c_2 Precautions shall be taken in order to prevent...*/

#include "Mcl_MemMap.h"


#ifdef __cplusplus
}
#endif/*(USE_GPT_MODULE==STD_ON) || (USE_ICU_MODULE==STD_ON) || (USE_PWM_MODULE==STD_ON))*/
#endif
/** @} */
