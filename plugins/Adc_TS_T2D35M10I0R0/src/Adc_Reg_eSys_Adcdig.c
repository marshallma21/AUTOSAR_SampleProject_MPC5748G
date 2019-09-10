/**
*   @file    Adc_Reg_eSys_Adcdig.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - module register and macro definitions.
*   @details Adc module registers, and macro definitions used to manipulate the module registers.
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
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Reg_eSys_Adcdig_c_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31 character significance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
* 
* @section Adc_Reg_eSys_Adcdig_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Adc_Reg_eSys_Adcdig_c_REF_3
* Violates MISRA 2004 Advisory Rule 19.1,
* '#include' statements in a file should only be preceded by othe preprocessor directives or comments
*
* @section Adc_Reg_eSys_Adcdig_c_REF_4
* Violates MISRA 2004 Required Rule 8.10,
* All declarations and definitions of objects or functions at file scope 
* shall have internal linkage unless external linkage is required.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Reg_eSys.h"
#include "Adc_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_REG_C                      43
/**
* @violates @ref Adc_Reg_eSys_Adcdig_c_REF_1 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MAJOR_VERSION_REG_C       4
/**
* @violates @ref Adc_Reg_eSys_Adcdig_c_REF_1 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MINOR_VERSION_REG_C       2
/**
* @violates @ref Adc_Reg_eSys_Adcdig_c_REF_1 The compiler/linker shall be checked to ensure that 31 character
* significance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_REG_C    2
#define ADC_SW_MAJOR_VERSION_REG_C               1
#define ADC_SW_MINOR_VERSION_REG_C               0
#define ADC_SW_PATCH_VERSION_REG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if source file and Reg_eSys.h file are of the same Autosar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_REG_C != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_REG_C != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Reg_eSys_Adcdig.c and Reg_eSys.h are different"
 #endif
 /* Check if source file and Std_Types header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_REG_C != STD_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_REG_C != STD_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Reg_eSys_Adcdig.c and Std_Types.h are different"
 #endif
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID_REG_C != ADC_VENDOR_ID_CFG)
#error "Adc_Reg_eSys_Adcdig.c and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_REG_C != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_REG_C != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_REG_C != ADC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Adc_Reg_eSys_Adcdig.c and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_REG_C != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION_REG_C != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION_REG_C != ADC_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Adc_Reg_eSys_Adcdig.c and Adc_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define ADC_START_SEC_CONST_32
/** @violates @ref Adc_Reg_eSys_Adcdig_c_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

/**
* @brief base address array for ADCDig
*/
CONST(uint32, ADC_CONST) ADCDIG_BASE_ADDR32[ADC_MAX_HW_UNITS] =
{
#ifdef ADC0_BASEADDR
    ADC0_BASEADDR
#endif
#ifdef ADC1_BASEADDR
    ,ADC1_BASEADDR
#endif
#ifdef ADC2_BASEADDR
    ,ADC2_BASEADDR
#endif
#ifdef ADC3_BASEADDR
    ,ADC3_BASEADDR
#endif
};

/**
* @brief offset from ADC unit base address for registers ADC_THRHLRn 
*/
/** * @violates @ref Adc_Reg_eSys_Adcdig_c_REF_4 internal linkage vs external linkage. */
CONST(uint32, ADC_CONST) ADCDIG_THR_REG_OFFSETS_U32[16] =
{
    0x0060UL, 
    0x0064UL,
    0x0068UL,
    0x006CUL,
    0x0280UL,
    0x0284UL,
    0x0288UL,
    0x028CUL,
    0x0290UL,
    0x0294UL,
    0x0298UL,
    0x029CUL,
    0x02A0UL,
    0x02A4UL,
    0x02A8UL,
    0x02ACUL 
};
    
#define ADC_STOP_SEC_CONST_32
/** @violates @ref Adc_Reg_eSys_Adcdig_c_REF_2 Repeated include file MemMap.h */
/** @violates @ref Adc_Reg_eSys_Adcdig_c_REF_3 Only preprocessor statements and comments before "#include" */
#include "Adc_MemMap.h"
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
