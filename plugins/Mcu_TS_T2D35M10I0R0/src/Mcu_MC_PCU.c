/**
*   @file    Mcu_MC_PCU.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Power Control Unit module functions implementation.
*   @details Specific functions for MC_PCU configuration and control.
*            Part of the Magic Carpet hw IP.
*            Includes also the PMU hw IP.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : MC
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
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_PCU_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_MC_PCU_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_MC_PCU_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_MC_PCU_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_MC_PCU_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*
* @section Mcu_MC_PCU_c_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_MC_PCU.h"

#ifdef MCU_ERROR_ISR_NOTIFICATION
#include "Mcu.h"
#endif

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
                                       SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define MCU_MC_PCU_VENDOR_ID_C                      43
/** @violates @ref Mcu_MC_PCU_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked ... */
#define MCU_MC_PCU_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_MC_PCU_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked ... */
#define MCU_MC_PCU_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_MC_PCU_c_REF_3 MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked ... */
#define MCU_MC_PCU_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_MC_PCU_SW_MAJOR_VERSION_C               1
#define MCU_MC_PCU_SW_MINOR_VERSION_C               0
#define MCU_MC_PCU_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if source file and Mcu_MC_PCU header file are of the same vendor. */
#if (MCU_MC_PCU_VENDOR_ID_C != MCU_MC_PCU_VENDOR_ID)
    #error "Mcu_MC_PCU.c and Mcu_MC_PCU.h have different Vendor IDs."
#endif
#ifdef CHECK_AUTOSAR_VERSION
  /* Check if source file and Mcu_MC_PCU header file are of the same Autosar version. */
  #if ( (MCU_MC_PCU_AR_RELEASE_MAJOR_VERSION_C != MCU_MC_PCU_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_MC_PCU_AR_RELEASE_MINOR_VERSION_C != MCU_MC_PCU_AR_RELEASE_MINOR_VERSION) || \
        (MCU_MC_PCU_AR_RELEASE_REVISION_VERSION_C != MCU_MC_PCU_AR_RELEASE_REVISION_VERSION) \
      )
        #error "AutoSar Version Numbers of Mcu_MC_PCU.c and Mcu_MC_PCU.h are different."
  #endif
#endif
/* Check if source file and Mcu_MC_PCU header file are of the same Software version. */
#if ( (MCU_MC_PCU_SW_MAJOR_VERSION_C != MCU_MC_PCU_SW_MAJOR_VERSION) || \
      (MCU_MC_PCU_SW_MINOR_VERSION_C != MCU_MC_PCU_SW_MINOR_VERSION) || \
      (MCU_MC_PCU_SW_PATCH_VERSION_C != MCU_MC_PCU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_PCU.c and Mcu_MC_PCU.h are different."
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_PCU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_PCU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_PCU.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_PCU_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_PCU_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_PCU.c and SilRegMacros.h are different"
    #endif
#endif

#ifdef MCU_ERROR_ISR_NOTIFICATION
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_MC_PCU_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu_MC_PCU.c and Mcu.h have different vendor ids"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_PCU_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_MC_PCU_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
        (MCU_MC_PCU_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Mcu_MC_PCU.c and Mcu.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_MC_PCU_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_MC_PCU_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_MC_PCU_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu_MC_PCU.c and Mcu.h are different"
#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_MC_PCU_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_MC_PCU_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
/**
* @brief            This function configure the Power Management Unit
* @details          The operating voltages are monitored by a set of on-chip supervisory circuits
*                   to ensure that this device works within the correct voltage range.
*                   Called by:
*                       - Mcu_Ipw_Init() from IPW.
*
* @param[in]        MC_PCU_pConfigPtr   Pointer to PMU configuration structure.
*
* @return           void
*
*/
/** @violates @ref Mcu_MC_PCU_c_REF_5 Global declaration of function */
FUNC( void, MCU_CODE) Mcu_MC_PCU_PowerInit(P2CONST( Mcu_MC_PCU_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_PCU_pConfigPtr)
{
#if (IPV_MC == IPV_MC_04_04_01_00)
    /* Configure the control register (PMC_PMCCR). */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_PMCCR_ADDR32, MC_PCU_pConfigPtr->u32Control | PMC_PMCCR_PMCCR_EN_MASK32);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_PMCCR_ADDR32,MC_PCU_pConfigPtr->u32Control );

    /* Configure the Interrupt Request Enable register (PMC_IER). */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32 ( PMC_BASEADDR, PMC_IER_ADDR32, MC_PCU_pConfigPtr->u32ResetInterruptEn | PMC_PMCCR_IE_EN_MASK32);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_IER_ADDR32,MC_PCU_pConfigPtr->u32ResetInterruptEn);

    /* Configure the Reset Event Enable register(PMC_REE_0). */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_0_ADDR32, MC_PCU_pConfigPtr->u32ResetEventEn);

    /* Configure the Reset Event Selection register(PMC_RES_0). */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_0_ADDR32, MC_PCU_pConfigPtr->u32ResetEventSel);

    /* Configure the Temperature Reset Event Enable register(PMC_REE_TD). */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_TD_ADDR32, MC_PCU_pConfigPtr->u32TempResEventEn);

    /* Configure the Temperature Reset Event Selection register(PMC_RES_TD). */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_TD_ADDR32, MC_PCU_pConfigPtr->u32TempResEventSel);

    /* Configure the Temperature Detector Configuration register(PMC_CTL_TD). */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_CTL_TD_ADDR32, MC_PCU_pConfigPtr->u32TempDetConfig);
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* Configure the control register (PMC_PMCCR). */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_PMCCR_ADDR32, MC_PCU_pConfigPtr->u32Control | PMC_PMCCR_ENABLE_MASK32);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_PMCCR_ADDR32, MC_PCU_pConfigPtr->u32Control);

    /* Temperature Sensor Event interrupt enable */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_TS_IER_ADDR32, MC_PCU_pConfigPtr->u32TemperatureInterruptControl | PMC_TS_IER_TS_EN_MASK32);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_TS_IER_ADDR32, MC_PCU_pConfigPtr->u32TemperatureInterruptControl);

    /* Analog front end voltage detectors */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_AFE_INTR_ENA_ADDR32, MC_PCU_pConfigPtr->u32AfeDetectorInterruptControl | PMC_AFE_INTR_ENA_IE_EN_MASK32);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_AFE_INTR_ENA_ADDR32, MC_PCU_pConfigPtr->u32AfeDetectorInterruptControl);

    /* reset event enable */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_TD_ADDR32, MC_PCU_pConfigPtr->u32ResetEventEnable);

    /* reset event selection */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_TD_ADDR32, MC_PCU_pConfigPtr->u32ResetEventSelection);

#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    
    /* Keep the bit IE_EN set to make following read/write is valid */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_IER_ADDR32, MC_PCU_pConfigPtr->u32ResetInterruptEn | PMC_IER_IE_EN_MASK32);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD3_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD3ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD3_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD3ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD3_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD3FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD4_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD4ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD4_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD4ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD4_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD4FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD7_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD7ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD7_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD7ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD7_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD7FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD8_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD8ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD8_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD8ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD8_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD8FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD9_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD9ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD9_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD9ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD9_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD9FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD10_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD10ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD10_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD10FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD12_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD12ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD12_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD12ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD12_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD12FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD13_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD13ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD13_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD13ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD13_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD13FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD14_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD14ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD14_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD14ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD14_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD14FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_VD15_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD15ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_VD15_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD15ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_VD15_ADDR32, (uint32)MC_PCU_pConfigPtr->u32VD15FccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_TD_ADDR32, (uint32)MC_PCU_pConfigPtr->u32TempResEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_TD_ADDR32, (uint32)MC_PCU_pConfigPtr->u32TempResEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_CTL_TD_ADDR32, (uint32)MC_PCU_pConfigPtr->u32TempDetConfig);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_FEE_TD_ADDR32, (uint32)MC_PCU_pConfigPtr->u32TempFccuEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_VSIO_ADDR32, MC_PCU_pConfigPtr->u32VoltageSupply );

#elif (IPV_MC == IPV_MC_04_06_01_00)
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_LVD_HVD_INTR_ENB_ADDR32, MC_PCU_pConfigPtr->u32ResetInterruptEn | PMC_LVD_HVD_INTR_ENB_PMC_ENABLE_MASK32);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_LVD_HVD_INTR_ENB_ADDR32, MC_PCU_pConfigPtr->u32ResetInterruptEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_ADDR32, MC_PCU_pConfigPtr->u32ResetEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_ADDR32, MC_PCU_pConfigPtr->u32ResetEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_TS_IER_ADDR32, MC_PCU_pConfigPtr->u32TempResetInterruptEn | PMC_TS_IER_TS_EN_MASK32);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_TS_IER_ADDR32, MC_PCU_pConfigPtr->u32TempResetInterruptEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_REE_TD_ADDR32, MC_PCU_pConfigPtr->u32TempResEventEn);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_RES_TD_ADDR32, MC_PCU_pConfigPtr->u32TempResEventSel);

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_CTL_TD_ADDR32, MC_PCU_pConfigPtr->u32TempDetConfig);
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */
}
#endif


#if (MCU_GET_POWER_DOMAIN_API == STD_ON)
/**
* @brief            This function returns the power status of all available power domains.
* @details          This function returns if power domain is operable or inoperable.
*                   Called by:
*                       - Mcu_IPW_GetPowerDomain_OperableState() from IPW.
*
* @return           Return value of the API.
* @retval           E_OK   Power domain is operable.
* @retval           E_NOT_OK   Power domain is inoperable.
*
*/
FUNC( Std_ReturnType, MCU_CODE ) Mcu_MC_PCU_Get_PcuState( VAR( void, AUTOMATIC))
{
    /* Result of the operation. */
    VAR( Std_ReturnType, AUTOMATIC) PcuStatus = (Std_ReturnType)E_NOT_OK;

    /* PCU_PSTAT[PD0] contains the power status for power domain. */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    if ( MC_PCU_STAT_PD0_MASK32 == (REG_READ32(MC_PCU_PSTAT_ADDR32) & MC_PCU_STAT_PD0_MASK32) )
    {
        PcuStatus = (Std_ReturnType)E_OK;
    }

    return (Std_ReturnType)PcuStatus;
}
#endif /* (MCU_GET_POWER_DOMAIN_API == STD_ON) */


#if (MCU_VOLTAGE_ERROR_ISR_USED == STD_ON)
/**
* @brief            This function handle the voltage error detection.
* @details          Assigned to INTC254 for MPC56XXL.
*                   Assigned to INTC477 for MPC57XXP.
*                   Leopard: PMUCTRL_IRQS bits are set by hardware if corresponding bits are set in
*                   the PMUCTRL_IRQE register.
*                   Panther: PMC_ESR_0 bits acivate an interrupt only if corresponding bit from
*                   PMC_IER is set.
*
* @return           void
*
* @isr
* @implements Mcu_PMU_VoltageErrorInt_Activity
*/
FUNC( void, MCU_CODE) Mcu_PMU_VoltageErrorInt( VAR( void, AUTOMATIC) )
{
#ifdef MCU_ERROR_ISR_NOTIFICATION
    /* marked as 0xFF in case an error is detected */
    VAR( uint8 , AUTOMATIC) u8errorFlag = (uint8)0x00U;
#endif

#if (IPV_MC == IPV_MC_04_04_01_00)
    VAR( uint32, AUTOMATIC) u32PmcVoltageEvent ;

    /* get the available voltage irq flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PmcVoltageEvent = REG_READ32(PMC_ESR_0_ADDR32) & (PMC_ESR_0_RWBITS_MASK32);
    /* Clear the error flags. */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_BIT_SET_LOCK32( PMC_BASEADDR, PMC_ESR_0_ADDR32, u32PmcVoltageEvent);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        if ( (uint32)0x00U != u32PmcVoltageEvent )
        {
            /* mark event */
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    VAR(uint32, AUTOMATIC) u32AfeIsrStatus;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR(uint32, AUTOMATIC) u32AfeIsrEnabled;
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32AfeIsrStatus = REG_READ32(PMC_AFE_INTR_STATUS_ADDR32) & PMC_AFE_INTR_STATUS_MASK32;

    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_AFE_INTR_STATUS_ADDR32, u32AfeIsrStatus );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* read the enable isr's */
        /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
        u32AfeIsrEnabled = REG_READ32(PMC_AFE_INTR_ENA_ADDR32) & PMC_AFE_INTR_ENA_RWBITS_MASK32;

        if((uint32)0x00000000U != u32AfeIsrStatus)
        {
            if(PMC_AFE_INTR_ENA_RWBITS_MASK32 == (PMC_AFE_INTR_ENA_RWBITS_MASK32 & u32AfeIsrEnabled))
            {
                u8errorFlag = (uint8)0xFFU;
            }
        }
    }
#endif

#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    VAR(uint32, AUTOMATIC) u32VoltageIsrStatus;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR(uint32, AUTOMATIC) u32VoltageIsrEnabled;
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD3_ADDR32) & PMC_EPR_VD3_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD3_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* read the enable isr's */
        /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
        u32VoltageIsrEnabled = REG_READ32(PMC_IER_ADDR32);
            
        /* check if there is an event to report */
        if (((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD3IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD4_ADDR32) & PMC_EPR_VD4_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD4_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD4IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD7_ADDR32) & PMC_EPR_VD7_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD7_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD7IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD8_ADDR32) & PMC_EPR_VD8_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD8_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD8IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD9_ADDR32) & PMC_EPR_VD9_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD9_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD9IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD10_ADDR32) & PMC_EPR_VD10_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD10_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD10IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD12_ADDR32) & PMC_EPR_VD12_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD12_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD12IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD13_ADDR32) & PMC_EPR_VD13_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD13_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD13IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD14_ADDR32) & PMC_EPR_VD14_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD14_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD14IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

    /* read the isr flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_EPR_VD15_ADDR32) & PMC_EPR_VD15_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_EPR_VD15_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != (PMC_IER_VD15IE_MASK32 & u32VoltageIsrEnabled)))
        {
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif

#elif (IPV_MC == IPV_MC_04_06_01_00)
    VAR( uint32, AUTOMATIC) u32VoltageIsrStatus;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32VoltageIsrEnabled;
#endif

    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32VoltageIsrStatus = REG_READ32(PMC_LVD_HVD_EVENT_STATUS_ADDR32) & \
                          PMC_LVD_HVD_EVENT_STATUS_RWBITS_MASK32;
    /* clear IRQ flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_LVD_HVD_EVENT_STATUS_ADDR32, u32VoltageIsrStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
        u32VoltageIsrEnabled = REG_READ32(PMC_LVD_HVD_INTR_ENB_ADDR32) & \
                               PMC_LVD_HVD_INTR_ENB_PMC_ENABLE_MASK32;
        
        /* check if there is an event to report */
        if(((uint32)0x00000000U != u32VoltageIsrStatus) && ((uint32)0x00000000U != u32VoltageIsrEnabled))
        {
            /* mark */
            u8errorFlag = (uint8)0xFFU;
        }
    }
#endif
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* here check if I must report or jump to callback */
        if ( (uint8)0x00U != u8errorFlag )
        {
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_VOLTAGE_ERROR);
        }
    }
#endif
}
#endif /* (MCU_VOLTAGE_ERROR_ISR_USED == STD_ON) */


#if ( MCU_TEMPERATURE_ERROR_ISR_USED == STD_ON )
/**
* @brief            This function handle the voltage error detection.
* @details          Assigned to INTC478 for MPC57XXP.
*                   Panther: PMC_ESR_0 bits acivate an interrupt only if corresponding bit from
*                   PMC_IER is set.
*
* @return           void
*
* @isr
* @implements Mcu_PMU_TemperatureErrorInt_Activity
*/
FUNC( void, MCU_CODE) Mcu_PMU_TemperatureErrorInt( VAR( void, AUTOMATIC) )
{
#if (IPV_MC == IPV_MC_04_04_01_00)
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32PmcIntEnabled ;
#endif
    VAR( uint32, AUTOMATIC) u32PmcTempEvent ;
    
    /* get the available temp irq flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PmcTempEvent = REG_READ32(PMC_ESR_TD_ADDR32) & (PMC_ESR_TD_RWBITS_MASK32);
    /* Clear the error flags. */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_BIT_SET_LOCK32( PMC_BASEADDR, PMC_ESR_TD_ADDR32, u32PmcTempEvent);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* get enabled events and mask with temp sources */
        /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
        u32PmcIntEnabled = REG_READ32(PMC_IER_ADDR32) & (PMC_IER_TEMPI_E_MASK32);
        /* at least one temp monitor is enabled */
        if(((uint32)0x00000000U != u32PmcIntEnabled) && ((uint32)0x00000000U != u32PmcTempEvent))
        {
            /* report event */
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_TEMPERATURE_MONITOR_ERROR);
        }
    }
#endif

#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    VAR(uint32, AUTOMATIC) u32TempSenseStatus;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR(uint32, AUTOMATIC) u32TempSenseEnabled;
#endif

    /* get the status flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32TempSenseStatus = REG_READ32(PMC_ESR_TD_ADDR32) & PMC_ESR_TD_MASK32;
    /* clean the enabled status flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(PMC_BASEADDR, PMC_ESR_TD_ADDR32, u32TempSenseStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
        u32TempSenseEnabled = REG_READ32(PMC_TS_IER_ADDR32) & PMC_TS_IER_RWBITS_USR_MASK32;
        /* report */
        
        if(PMC_ESR_TD_MASK32 == (PMC_ESR_TD_MASK32 & u32TempSenseStatus))
        {
            if(PMC_TS_IER_RWBITS_USR_MASK32 == (PMC_TS_IER_RWBITS_USR_MASK32 & u32TempSenseEnabled))
            {
                /* report */

                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_TEMPERATURE_MONITOR_ERROR);
            }
        }
    }
#endif

#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    VAR( uint32, AUTOMATIC) u32TempSenseStatus;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32TempSenseEnabled;
#endif

    /* get the status flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32TempSenseStatus = REG_READ32(PMC_EPR_TD_ADDR32) & PMC_EPR_TD_RWBITS_MASK32;
    /* clean the enabled status flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_EPR_TD_ADDR32, u32TempSenseStatus );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
        u32TempSenseEnabled = REG_READ32(PMC_CTL_TD_ADDR32) & PMC_CTL_TD_IE_RWBITS_MASK32;
        
        /* report */
        if(((uint32)0x00000000U  != u32TempSenseStatus) && ((uint32)0x00000000U  != u32TempSenseEnabled))
        {
            /* report */
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_TEMPERATURE_MONITOR_ERROR);
        }
    }
#endif

#elif (IPV_MC == IPV_MC_04_06_01_00)
    VAR( uint32, AUTOMATIC) u32TempSenseStatus;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32TempSenseEnabled;
#endif

    /* get the status flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32TempSenseStatus = REG_READ32(PMC_ESR_TD_ADDR32) & PMC_ESR_TD_RWBITS_MASK32;
    /* clean the enabled status flags */
    /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
    /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( PMC_BASEADDR, PMC_ESR_TD_ADDR32, u32TempSenseStatus );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_MC_PCU_c_REF_4 Required Rule 11.1, Conversion from integer to pointer */
        /** @violates @ref Mcu_MC_PCU_c_REF_6 The cast is used to access memory mapped registers.*/
        u32TempSenseEnabled = REG_READ32(PMC_TS_IER_ADDR32) & PMC_TS_IER_RWBITS_MASK32;
        /* report */
        if (((uint32)0x00000000U  != u32TempSenseStatus) && ((uint32)0x00000000U  != u32TempSenseEnabled))
        {
            /* report */
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_TEMPERATURE_MONITOR_ERROR);
        }
    }
#endif
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */
}
#endif /* ( MCU_TEMPERATURE_ERROR_ISR_USED == STD_ON ) */


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_MC_PCU_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_MC_PCU_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
