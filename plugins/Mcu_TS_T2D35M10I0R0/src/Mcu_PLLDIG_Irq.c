/**
*   @file    Mcu_PLLDIG_Irq.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Power Control Unit module functions implementation.
*   @details Specific functions for PLLDIG configuration and control.
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
* @section Mcu_PLLDIG_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_PLLDIG_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_PLLDIG_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_PLLDIG_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_PLLDIG_c_REF_5
* Violates MISRA 2004 Required Rule 10.1, The value of an expression of integer type shall
* not be implicitly converted to a different underlying type. Integer to pointer conversion,
* specific to the ISR entry / exit code .
*
* @section Mcu_PLLDIG_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
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
#include "Mcal.h"
#include "Mcu_PLLDIG.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define MCU_PLLDIG_VENDOR_ID_IRQ_C                      43
/** @violates @ref Mcu_PLLDIG_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C       4
/** @violates @ref Mcu_PLLDIG_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_PLLDIG_AR_RELEASE_MINOR_VERSION_IRQ_C       2
/** @violates @ref Mcu_PLLDIG_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_PLLDIG_AR_RELEASE_REVISION_VERSION_IRQ_C    2
#define MCU_PLLDIG_SW_MAJOR_VERSION_IRQ_C               1
#define MCU_PLLDIG_SW_MINOR_VERSION_IRQ_C               0
#define MCU_PLLDIG_SW_PATCH_VERSION_IRQ_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PLLDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Mcu_PLLDIG_Irq.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and Mcu_PLLDIG header file are of the same vendor. */
#if (MCU_PLLDIG_VENDOR_ID_IRQ_C != MCU_PLLDIG_VENDOR_ID)
    #error "Mcu_PLLDIG_Irq.c and Mcu_PLLDIG.h have different Vendor IDs."
#endif
#ifdef CHECK_AUTOSAR_VERSION
  /* Check if source file and Mcu_PLLDIG header file are of the same Autosar version. */
  #if ( (MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION_IRQ_C != MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_PLLDIG_AR_RELEASE_MINOR_VERSION_IRQ_C != MCU_PLLDIG_AR_RELEASE_MINOR_VERSION) || \
        (MCU_PLLDIG_AR_RELEASE_REVISION_VERSION_IRQ_C != MCU_PLLDIG_AR_RELEASE_REVISION_VERSION) \
      )
        #error "AutoSar Version Numbers of Mcu_PLLDIG_Irq.c and Mcu_PLLDIG.h are different."
  #endif
#endif
/* Check if source file and Mcu_PLLDIG header file are of the same Software version. */
#if ( (MCU_PLLDIG_SW_MAJOR_VERSION_IRQ_C != MCU_PLLDIG_SW_MAJOR_VERSION) || \
      (MCU_PLLDIG_SW_MINOR_VERSION_IRQ_C != MCU_PLLDIG_SW_MINOR_VERSION) || \
      (MCU_PLLDIG_SW_PATCH_VERSION_IRQ_C != MCU_PLLDIG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PLLDIG_Irq.c and Mcu_PLLDIG.h are different."
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


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_PLLDIG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PLLDIG_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#if (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00)
#if (((MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) && (MCU_PLLDIG_PLL0_LOL_ISR_USED == STD_ON)) || \
     ((MCU_PLL1_UNDER_MCU_CONTROL == STD_ON) && (MCU_PLLDIG_PLL1_LOL_ISR_USED == STD_ON)) \
    )
ISR( Mcu_PllDig_Pll_LossOfLockIsr );
#endif
#endif

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
#if (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL0_EXTPD_ISR_USED == STD_ON)
ISR( Mcu_PllDig_Pll0_PowerDownCompleteIsr );
#endif /* MCU_PLLDIG_PLL0_EXTPD_ISR_USED == STD_ON */
#endif /* (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) */

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
#if (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON)
#if ( MCU_PLLDIG_PLL0_LOL_ISR_USED == STD_ON )
ISR( Mcu_PllDig_Pll0_LossOfLockIsr );
#endif /* MCU_PLLDIG_PLL0_LOL_ISR_USED == STD_ON */
#endif /* (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)) */


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
#ifdef MCU_PLL1_UNDER_MCU_CONTROL
#if (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL1_EXTPD_ISR_USED == STD_ON)
ISR( Mcu_PllDig_Pll1_PowerDownCompleteIsr );
#endif /* MCU_PLLDIG_PLL1_EXTPD_ISR_USED */
#endif /* (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL1_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) */

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
#ifdef MCU_PLL1_UNDER_MCU_CONTROL
#if (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL1_LOL_ISR_USED == STD_ON)
ISR( Mcu_PllDig_Pll1_LossOfLockIsr );
#endif /* MCU_PLLDIG_PLL1_LOL_ISR_USED */
#endif /* (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL1_UNDER_MCU_CONTROL */
#endif /* ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)) */


#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
#ifdef MCU_PLL2_UNDER_MCU_CONTROL
#if (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL2_EXTPD_ISR_USED == STD_ON)
ISR( Mcu_PllDig_Pll2_PowerDownCompleteIsr );
#endif /* MCU_PLLDIG_PLL2_EXTPD_ISR_USED == STD_ON */
#endif /* (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL2_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
#ifdef MCU_PLL2_UNDER_MCU_CONTROL
#if (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON)
#if ( MCU_PLLDIG_PLL2_LOL_ISR_USED == STD_ON )
ISR( Mcu_PllDig_Pll2_LossOfLockIsr );
#endif /* MCU_PLLDIG_PLL2_LOL_ISR_USED == STD_ON */
#endif /* (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL2_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */


#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
#ifdef MCU_PLL3_UNDER_MCU_CONTROL
#if (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL3_EXTPD_ISR_USED == STD_ON)
ISR( Mcu_PllDig_Pll3_PowerDownCompleteIsr );
#endif /* MCU_PLLDIG_PLL3_EXTPD_ISR_USED == STD_ON */
#endif /* (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL3_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
#ifdef MCU_PLL3_UNDER_MCU_CONTROL
#if (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON)
#if ( MCU_PLLDIG_PLL3_LOL_ISR_USED == STD_ON )
ISR( Mcu_PllDig_Pll3_LossOfLockIsr );
#endif /* MCU_PLLDIG_PLL3_LOL_ISR_USED == STD_ON */
#endif /* (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL3_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
#ifdef MCU_PLL4_UNDER_MCU_CONTROL
#if (MCU_PLL4_UNDER_MCU_CONTROL == STD_ON)
#if ( MCU_PLLDIG_PLL4_LOL_ISR_USED == STD_ON )
ISR( Mcu_PllDig_Pll4_LossOfLockIsr );
#endif /* MCU_PLLDIG_PLL4_LOL_ISR_USED == STD_ON */
#endif /* (MCU_PLL4_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL4_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_PLLDIG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PLLDIG_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_PLLDIG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PLLDIG_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#if (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00)
#if (((MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) && (MCU_PLLDIG_PLL0_LOL_ISR_USED == STD_ON)) || \
     ((MCU_PLL1_UNDER_MCU_CONTROL == STD_ON) && (MCU_PLLDIG_PLL1_LOL_ISR_USED == STD_ON)) \
    )
/**
* @brief        PLLDIG Pll ISR.
* @details      This ISR is generated by the PLLDIG IP when the Pll0 or PLL1 module loses lock.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll_LossOfLockIsr )
{
#if ((MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) && (MCU_PLLDIG_PLL0_LOL_ISR_USED == STD_ON))
    Mcu_PLLDIG_PLL0LossOfLockIsr();
#endif

#if ((MCU_PLL1_UNDER_MCU_CONTROL == STD_ON) && (MCU_PLLDIG_PLL1_LOL_ISR_USED == STD_ON))
    Mcu_PLLDIG_PLL1LossOfLockIsr();
#endif
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif
#endif


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
#if (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL0_EXTPD_ISR_USED == STD_ON)
/**
* @brief        PLLDIG Pll0 EXTPD ISR.
* @details      This ISR is generated by the PLLDIG Ip when External Power Down Cycle Complete.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll0_PowerDownCompleteIsr )
{
    Mcu_PLLDIG_PLL0PowerDownCompleteIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL0_EXTPD_ISR_USED == STD_ON */
#endif /* (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) */


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) \
    )
#if (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON)
#if ( MCU_PLLDIG_PLL0_LOL_ISR_USED == STD_ON )
/**
* @brief        PLLDIG Pll0 ISR.
* @details      This ISR is generated by the PLLDIG Ip when the Pll0 module loses lock.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll0_LossOfLockIsr )
{
    Mcu_PLLDIG_PLL0LossOfLockIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL0_LOL_ISR_USED == STD_ON */
#endif /* (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)) */


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
#ifdef MCU_PLL1_UNDER_MCU_CONTROL
#if (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL1_EXTPD_ISR_USED == STD_ON)
/**
* @brief        PLLDIG Pll1 EXTPD ISR.
* @details      This ISR is generated by the PLLDIG Ip when External Power Down Cycle Complete.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll1_PowerDownCompleteIsr )
{
    Mcu_PLLDIG_PLL1PowerDownCompleteIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL1_EXTPD_ISR_USED */
#endif /* (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL1_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) */


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) \
    )
#ifdef MCU_PLL1_UNDER_MCU_CONTROL
#if (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL1_LOL_ISR_USED == STD_ON)
/**
* @brief        PLLDIG Pll1 ISR.
* @details      This ISR is generated by the PLLDIG Ip when the Pll1 module loses lock.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll1_LossOfLockIsr )
{
    Mcu_PLLDIG_PLL1LossOfLockIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL1_LOL_ISR_USED */
#endif /* (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL1_UNDER_MCU_CONTROL */
#endif /* ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)) */


#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
#ifdef MCU_PLL2_UNDER_MCU_CONTROL
#if (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL2_EXTPD_ISR_USED == STD_ON)
/**
* @brief        PLLDIG Pll2 EXTPD ISR.
* @details      This ISR is generated by the PLLDIG Ip when External Power Down Cycle Complete.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll2_PowerDownCompleteIsr )
{
    Mcu_PLLDIG_PLL2PowerDownCompleteIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL2_EXTPD_ISR_USED */
#endif /* (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL2_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
#ifdef MCU_PLL2_UNDER_MCU_CONTROL
#if (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL2_LOL_ISR_USED == STD_ON)
/**
* @brief        PLLDIG Pll2 ISR.
* @details      This ISR is generated by the PLLDIG Ip when the Pll1 module loses lock.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll2_LossOfLockIsr )
{
    Mcu_PLLDIG_PLL2LossOfLockIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL2_LOL_ISR_USED */
#endif /* (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL2_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */


#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
#ifdef MCU_PLL3_UNDER_MCU_CONTROL
#if (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL3_EXTPD_ISR_USED == STD_ON)
/**
* @brief        PLLDIG Pll3 EXTPD ISR.
* @details      This ISR is generated by the PLLDIG Ip when External Power Down Cycle Complete.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll3_PowerDownCompleteIsr )
{
    Mcu_PLLDIG_PLL3PowerDownCompleteIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL3_EXTPD_ISR_USED */
#endif /* (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL3_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
#ifdef MCU_PLL3_UNDER_MCU_CONTROL
#if (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL3_LOL_ISR_USED == STD_ON)
/**
* @brief        PLLDIG Pll3 ISR.
* @details      This ISR is generated by the PLLDIG Ip when the Pll1 module loses lock.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll3_LossOfLockIsr )
{
    Mcu_PLLDIG_PLL3LossOfLockIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL3_LOL_ISR_USED */
#endif /* (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL3_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
#ifdef MCU_PLL4_UNDER_MCU_CONTROL
#if (MCU_PLL4_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL4_LOL_ISR_USED == STD_ON)
/**
* @brief        PLLDIG Pll4 ISR.
* @details      This ISR is generated by the PLLDIG Ip when the Pll1 module loses lock.
*
* @isr
*
*/
/** @violates @ref Mcu_PLLDIG_c_REF_6 The IRQ handler is used by external code */
ISR( Mcu_PllDig_Pll4_LossOfLockIsr )
{
    Mcu_PLLDIG_PLL4LossOfLockIsr();
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_PLLDIG_c_REF_5 Conversion from integer to pointer */
    EXIT_INTERRUPT();
}
#endif /* MCU_PLLDIG_PLL4_LOL_ISR_USED */
#endif /* (MCU_PLL4_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL4_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_PLLDIG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PLLDIG_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
