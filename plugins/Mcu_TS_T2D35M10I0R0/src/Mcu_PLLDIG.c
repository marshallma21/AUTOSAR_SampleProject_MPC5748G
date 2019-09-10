/**
*   @file    Mcu_PLLDIG.c
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
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*
* @section Mcu_PLLDIG_c_REF_6
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
#include "Mcu_PLLDIG.h"

#ifdef MCU_ERROR_ISR_NOTIFICATION
#include "Mcu.h"
#endif /* MCU_ERROR_ISR_NOTIFICATION */

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define MCU_PLLDIG_VENDOR_ID_C                      43
/** @violates @ref Mcu_PLLDIG_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_PLLDIG_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_PLLDIG_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_PLLDIG_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_PLLDIG_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_PLLDIG_SW_MAJOR_VERSION_C               1
#define MCU_PLLDIG_SW_MINOR_VERSION_C               0
#define MCU_PLLDIG_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if source file and Mcu_PLLDIG header file are of the same vendor. */
#if (MCU_PLLDIG_VENDOR_ID_C != MCU_PLLDIG_VENDOR_ID)
    #error "Mcu_PLLDIG.c and Mcu_PLLDIG.h have different Vendor IDs."
#endif
#ifdef CHECK_AUTOSAR_VERSION
  /* Check if source file and Mcu_PLLDIG header file are of the same Autosar version. */
  #if( (MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION_C != MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_PLLDIG_AR_RELEASE_MINOR_VERSION_C != MCU_PLLDIG_AR_RELEASE_MINOR_VERSION) || \
        (MCU_PLLDIG_AR_RELEASE_REVISION_VERSION_C != MCU_PLLDIG_AR_RELEASE_REVISION_VERSION) \
     )
        #error "AutoSar Version Numbers of Mcu_PLLDIG.c and Mcu_PLLDIG.h are different."
  #endif
#endif
/* Check if source file and Mcu_PLLDIG header file are of the same Software version. */
#if ( (MCU_PLLDIG_SW_MAJOR_VERSION_C != MCU_PLLDIG_SW_MAJOR_VERSION) || \
      (MCU_PLLDIG_SW_MINOR_VERSION_C != MCU_PLLDIG_SW_MINOR_VERSION) || \
      (MCU_PLLDIG_SW_PATCH_VERSION_C != MCU_PLLDIG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PLLDIG.c and Mcu_PLLDIG.h are different."
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PLLDIG_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PLLDIG.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PLLDIG_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PLLDIG.c and SilRegMacros.h are different"
    #endif
#endif

#ifdef MCU_ERROR_ISR_NOTIFICATION
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_PLLDIG_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu_PLLDIG.c and Mcu.h have different vendor ids"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_PLLDIG_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
        (MCU_PLLDIG_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Mcu_PLLDIG.c and Mcu.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_PLLDIG_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_PLLDIG_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_PLLDIG_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu_PLLDIG.c and Mcu.h are different"
#endif
#endif /* MCU_ERROR_ISR_NOTIFICATION */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || \
     (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) \
    )
#ifdef MCU_PLL1_UNDER_MCU_CONTROL
#if ((MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) || (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON))
    #define MCU_PLL_UNDER_MCU_CONTROL_AGGREGATOR
#endif
#else
#if (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON)
    #define MCU_PLL_UNDER_MCU_CONTROL_AGGREGATOR
#endif
#endif
#endif
#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
#ifndef MCU_PLL_UNDER_MCU_CONTROL_AGGREGATOR
#ifdef MCU_PLL2_UNDER_MCU_CONTROL
#if ((MCU_PLL2_UNDER_MCU_CONTROL == STD_ON) || (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON))
    #define MCU_PLL_UNDER_MCU_CONTROL_AGGREGATOR
#endif
#endif
#endif
#endif
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
#ifndef MCU_PLL_UNDER_MCU_CONTROL_AGGREGATOR
#ifdef MCU_PLL3_UNDER_MCU_CONTROL
#if ((MCU_PLL3_UNDER_MCU_CONTROL == STD_ON) || (MCU_PLL4_UNDER_MCU_CONTROL == STD_ON))
    #define MCU_PLL_UNDER_MCU_CONTROL_AGGREGATOR
#endif
#endif
#endif
#endif

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
* @violates @ref Mcu_PLLDIG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PLLDIG_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            Configure for PLL.
* @details          This routine configure for PLLDIG registers.
*
* @param[in]        PLLDIG_pConfigPtr   Pointer to clock configuration structure
*                   (member of 'Mcu_ClockConfigType' struct).
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_PLLDIG_PllConfig(P2CONST( Mcu_PLLDIG_ConfigType, AUTOMATIC, MCU_APPL_CONST) PLLDIG_pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Counter;

    /* assume that MC_ME already powered down the PLL */
    /* not my job to check on that */
    /* write the new pll values */
    for ( u32Counter = (uint32)0x00U; u32Counter < (uint32)(PLLDIG_pConfigPtr->u8NoOfPllDigRegsUnderMcuControl); u32Counter++)
    {
        /* for all pairs write them to hardware */
        /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32 \
        ( \
            (*PLLDIG_pConfigPtr->apPllDigConfig)[u32Counter].u32RegisterAddr, \
            (*PLLDIG_pConfigPtr->apPllDigConfig)[u32Counter].u32RegisterData \
        );
    }

}
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            Get PLL Status.
* @details          This routine returns the status of PLL.
*
* @param[in]        void.
*
* @return           void
*
*/
FUNC( Mcu_PLLDIG_PllStatusType, MCU_CODE)Mcu_PLLDIG_GetPLLStatus( VAR( void, AUTOMATIC))
{
    VAR( Mcu_PLLDIG_PllStatusType, AUTOMATIC) ePllDigStatus = (Mcu_PLLDIG_PllStatusType)MCU_PLLDIG_PLL_STATUS_UNDEFINED;
#ifdef MCU_PLL_UNDER_MCU_CONTROL_AGGREGATOR
    VAR(uint32, AUTOMATIC) u32PllCr;
    VAR(uint32, AUTOMATIC) u32PllSr;
    VAR(uint32, AUTOMATIC) u32PllLockedCount = (uint32)0U;
    VAR(uint32, AUTOMATIC) u32PllUnlockedCount = (uint32)0U;
#endif

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || \
     (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) \
    )
#if (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON)
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllCr = REG_READ32( PLLDIG_PLL0CR_ADDR32 ) & PLLDIG_PLL0CR_CLKCFG_MASK32;
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllSr = REG_READ32( PLLDIG_PLL0SR_ADDR32 ) & MCU_PLLDIG_PLL0SR_LOCK_U32;
    /* if the PLL is powered on check for it's lock */
    if (PLLDIG_PLL0CR_CLKCFG_BO_U32 != u32PllCr)
    {
        if (MCU_PLLDIG_PLL0SR_LOCK_U32 == u32PllSr)
        {
            u32PllLockedCount++;
        }
        else
        {
            u32PllUnlockedCount++;
        }
    }
#endif

#ifdef MCU_PLL1_UNDER_MCU_CONTROL
#if (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON)
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllCr = REG_READ32( PLLDIG_PLL1CR_ADDR32 ) & PLLDIG_PLL1CR_CLKCFG_MASK32 ;
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllSr = REG_READ32( PLLDIG_PLL1SR_ADDR32 ) & MCU_PLLDIG_PLL1SR_LOCK_U32 ;
    /* same checks for PLL1 */
    if (PLLDIG_PLL1CR_CLKCFG_BO_U32 != u32PllCr)
    {
        if (MCU_PLLDIG_PLL1SR_LOCK_U32 == u32PllSr)
        {
            u32PllLockedCount++;
        }
        else
        {
            u32PllUnlockedCount++;
        }
    }
#endif /* (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL1_UNDER_MCU_CONTROL */
#endif

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
#ifdef MCU_PLL2_UNDER_MCU_CONTROL
#if (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON)
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllCr = REG_READ32( PLLDIG_PLL2CR_ADDR32 ) & PLLDIG_PLL2CR_CLKCFG_MASK32 ;
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllSr = REG_READ32( PLLDIG_PLL2SR_ADDR32 ) & MCU_PLLDIG_PLL2SR_LOCK_U32 ;
    if (PLLDIG_PLL2CR_CLKCFG_BO_U32 != u32PllCr)
    {
        if (MCU_PLLDIG_PLL2SR_LOCK_U32 == u32PllSr)
        {
            u32PllLockedCount++;
        }
        else
        {
            u32PllUnlockedCount++;
        }
    }
#endif /* (MCU_PLL2_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL2_UNDER_MCU_CONTROL */

#ifdef MCU_PLL3_UNDER_MCU_CONTROL
#if (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON)
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllCr = REG_READ32( PLLDIG_PLL3CR_ADDR32 ) & PLLDIG_PLL3CR_CLKCFG_MASK32;
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllSr = REG_READ32( PLLDIG_PLL3SR_ADDR32 ) & MCU_PLLDIG_PLL3SR_LOCK_U32;
    if (PLLDIG_PLL3CR_CLKCFG_BO_U32 != u32PllCr)
    {
        if (MCU_PLLDIG_PLL3SR_LOCK_U32 == u32PllSr)
        {
            u32PllLockedCount++;
        }
        else
        {
            u32PllUnlockedCount++;
        }
    }
#endif /* (MCU_PLL3_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL3_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
#ifdef MCU_PLL4_UNDER_MCU_CONTROL
#if (MCU_PLL4_UNDER_MCU_CONTROL == STD_ON)
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllCr = REG_READ32( PLLDIG_PLL4CR_ADDR32 ) & PLLDIG_PLL4CR_CLKCFG_MASK32;
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32PllSr = REG_READ32( PLLDIG_PLL4SR_ADDR32 ) & MCU_PLLDIG_PLL4SR_LOCK_U32;
    if (PLLDIG_PLL4CR_CLKCFG_BO_U32 != u32PllCr)
    {
        if (MCU_PLLDIG_PLL4SR_LOCK_U32 == u32PllSr)
        {
            u32PllLockedCount++;
        }
        else
        {
            u32PllUnlockedCount++;
        }
    }
#endif /* (MCU_PLL4_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL4_UNDER_MCU_CONTROL */
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) */

    /* compose the return value */
    /* the default return value is undefined */
    /* if any is unlocked return unlocked */
    /* else return locked */
#ifdef MCU_PLL_UNDER_MCU_CONTROL_AGGREGATOR
    if (u32PllUnlockedCount > (uint32)0U)
    {
        /* at leas 1 pll that was ON is unlocked return that there are unlocked PLL's */
        ePllDigStatus = MCU_PLLDIG_PLL_UNLOCKED;
    }
    else if (u32PllLockedCount > (uint32)0U)
    {
        /* at leas 1 pll that was ON is unlocked return that there are unlocked PLL's */
        ePllDigStatus = MCU_PLLDIG_PLL_LOCKED;
    }
    else
    {
        /* do nothing */
    }
#endif

    return ePllDigStatus;
}
#endif /* (MCU_NO_PLL == STD_OFF) */


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
#if (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL0_EXTPD_ISR_USED == STD_ON)

/**
* @brief            This function handle the External Power Down Cycle Complete interrupt.
*                   PLLDIG_PLL0SR[EXTPDF] bit will be set by the hardware only if
*                   PLLDIG_PLL0CR[EXPDIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL0PowerDownCompleteIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL0PowerDownCompleteIsr(VAR( void, AUTOMATIC))
{
    VAR( uint32, AUTOMATIC) u32Pll0Status;

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll0Status = REG_READ32(PLLDIG_PLL0SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(PLLDIG_PLL0SR_ADDR32, u32Pll0Status & PLLDIG_PLL0SR_EXTPDF_MASK32);
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
* @brief            This function handle the Loss of lock interrupt.
*                   PLLDIG_PLL0SR[LOLF] bit will be set by the hardware only if
*                   PLLDIG_PLL0CR[LOLIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL0LossOfLockIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL0LossOfLockIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32Pll0Status ;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32Pll0Enabled ;
#endif

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll0Status = REG_READ32(PLLDIG_PLL0SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PLLDIG_PLL0SR_ADDR32, u32Pll0Status & PLLDIG_PLL0SR_LOLF_MASK32 );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
        u32Pll0Enabled = REG_READ32(PLLDIG_PLL0CR_ADDR32);

        /*if isr is enabled */
        if \
        ( \
            (MCU_PLLDIG_PLL0CR_LOLIE_ENA_U32 == (u32Pll0Enabled & MCU_PLLDIG_PLL0CR_LOLIE_ENA_U32)) && \
            (PLLDIG_PLL0SR_LOLF_MASK32 == (u32Pll0Status & PLLDIG_PLL0SR_LOLF_MASK32)) \
        )
        {
            /* signal to upper layer that PLLDIG_Pll0 lost lock */
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_PLL_LOCK_FAILURE);
        }
    }
#endif
}
#endif /* MCU_PLLDIG_PLL0_LOL_ISR_USED == STD_ON */
#endif /* (MCU_PLL0_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)) */


#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
#ifdef MCU_PLL1_UNDER_MCU_CONTROL
#if (MCU_PLL1_UNDER_MCU_CONTROL == STD_ON)
#if (MCU_PLLDIG_PLL1_EXTPD_ISR_USED == STD_ON)

/**
* @brief            This function handle the External Power Down Cycle Complete interrupt.
*                   PLLDIG_PLL1SR[EXTPDF] bit will be set by the hardware only if
*                   PLLDIG_PLL1CR[EXPDIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL1PowerDownCompleteIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL1PowerDownCompleteIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32Pll1Status ;

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll1Status = REG_READ32(PLLDIG_PLL1SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PLLDIG_PLL1SR_ADDR32, u32Pll1Status & PLLDIG_PLL1SR_EXTPDF_MASK32 );
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
* @brief            This function handle the Loss of lock interrupt.
*                   PLLDIG_PLL1SR[LOLF] bit will be set by the hardware only if
*                   PLLDIG_PLL1CR[LOLIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL1LossOfLockIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL1LossOfLockIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32Pll1Status ;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32Pll1Enabled ;
#endif

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll1Status = REG_READ32(PLLDIG_PLL1SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PLLDIG_PLL1SR_ADDR32, u32Pll1Status & PLLDIG_PLL1SR_LOLF_MASK32 );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
        u32Pll1Enabled = REG_READ32(PLLDIG_PLL1CR_ADDR32);
        /*if isr is enabled */
        if \
        ( \
            (MCU_PLLDIG_PLL1CR_LOLIE_ENA_U32 == (u32Pll1Enabled  & MCU_PLLDIG_PLL1CR_LOLIE_ENA_U32)) && \
            (PLLDIG_PLL1SR_LOLF_MASK32 == (u32Pll1Status  & PLLDIG_PLL1SR_LOLF_MASK32)) \
        )
        {
            /* signal to upper layer that PLLDIG_Pll1 lost lock */
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_PLL_LOCK_FAILURE);
        }
    }
#endif
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
* @brief            This function handle the External Power Down Cycle Complete interrupt.
*                   PLLDIG_PLL2SR[EXTPDF] bit will be set by the hardware only if
*                   PLLDIG_PLL2CR[EXPDIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL2PowerDownCompleteIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL2PowerDownCompleteIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32Pll2Status ;

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll2Status = REG_READ32(PLLDIG_PLL2SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PLLDIG_PLL2SR_ADDR32, u32Pll2Status & PLLDIG_PLL2SR_EXTPDF_MASK32 );
}
#endif /* MCU_PLLDIG_PLL2_EXTPD_ISR_USED */


#if (MCU_PLLDIG_PLL2_LOL_ISR_USED == STD_ON)

/**
* @brief            This function handle the Loss of lock interrupt.
*                   PLLDIG_PLL2SR[LOLF] bit will be set by the hardware only if
*                   PLLDIG_PLL2CR[LOLIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL2LossOfLockIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL2LossOfLockIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32Pll2Status ;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32Pll2Enabled ;
#endif

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll2Status = REG_READ32(PLLDIG_PLL2SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PLLDIG_PLL2SR_ADDR32, u32Pll2Status & PLLDIG_PLL2SR_LOLF_MASK32 );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
        u32Pll2Enabled = REG_READ32(PLLDIG_PLL2CR_ADDR32);
        /*if isr is enabled */
        if \
        ( \
            (MCU_PLLDIG_PLL2CR_LOLIE_ENA_U32 == (u32Pll2Enabled  & MCU_PLLDIG_PLL2CR_LOLIE_ENA_U32)) && \
            (PLLDIG_PLL2SR_LOLF_MASK32 == (u32Pll2Status  & PLLDIG_PLL2SR_LOLF_MASK32)) \
        )
        {
            /* signal to upper layer that PLLDIG_Pll2 lost lock */
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_PLL_LOCK_FAILURE);
        }
    }
#endif
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
* @brief            This function handle the External Power Down Cycle Complete interrupt.
*                   PLLDIG_PLL3SR[EXTPDF] bit will be set by the hardware only if
*                   PLLDIG_PLL3CR[EXPDIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL3PowerDownCompleteIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL3PowerDownCompleteIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32Pll3Status ;

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll3Status = REG_READ32(PLLDIG_PLL3SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PLLDIG_PLL3SR_ADDR32, u32Pll3Status & PLLDIG_PLL3SR_EXTPDF_MASK32 );
}
#endif /* MCU_PLLDIG_PLL3_EXTPD_ISR_USED */


#if (MCU_PLLDIG_PLL3_LOL_ISR_USED == STD_ON)

/**
* @brief            This function handle the Loss of lock interrupt.
*                   PLLDIG_PLL3SR[LOLF] bit will be set by the hardware only if
*                   PLLDIG_PLL3CR[LOLIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL3LossOfLockIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL3LossOfLockIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32Pll3Status ;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32Pll3Enabled ;
#endif

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll3Status = REG_READ32(PLLDIG_PLL3SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PLLDIG_PLL3SR_ADDR32, u32Pll3Status & PLLDIG_PLL3SR_LOLF_MASK32 );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
        u32Pll3Enabled = REG_READ32(PLLDIG_PLL3CR_ADDR32);
        /*if isr is enabled */
        if \
        ( \
            (MCU_PLLDIG_PLL3CR_LOLIE_ENA_U32 == (u32Pll3Enabled  & MCU_PLLDIG_PLL3CR_LOLIE_ENA_U32)) && \
            (PLLDIG_PLL3SR_LOLF_MASK32 == (u32Pll3Status  & PLLDIG_PLL3SR_LOLF_MASK32)) \
        )
        {
            /* signal to upper layer that PLLDIG_Pll3 lost lock */
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_PLL_LOCK_FAILURE);
        }
    }
#endif
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
* @brief            This function handle the Loss of lock interrupt.
*                   PLLDIG_PLL4SR[LOLF] bit will be set by the hardware only if
*                   PLLDIG_PLL4CR[LOLIE] is true.
*
* @return           void
* @implements       Mcu_PLLDIG_PLL4LossOfLockIsr_Activity
*/

FUNC( void, MCU_CODE) Mcu_PLLDIG_PLL4LossOfLockIsr( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32Pll3Status ;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32Pll3Enabled ;
#endif

    /* get ISR flags and isr enable */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    u32Pll3Status = REG_READ32(PLLDIG_PLL4SR_ADDR32);

    /* clear the flags */
    /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PLLDIG_PLL4SR_ADDR32, u32Pll3Status & PLLDIG_PLL3SR_LOLF_MASK32 );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_PLLDIG_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_PLLDIG_c_REF_6 The cast is used to access memory mapped registers.*/
        u32Pll3Enabled = REG_READ32(PLLDIG_PLL4CR_ADDR32);
        
        /*if isr is enabled */
        if \
        ( \
            (MCU_PLLDIG_PLL4CR_LOLIE_ENA_U32 == (u32Pll3Enabled  & MCU_PLLDIG_PLL4CR_LOLIE_ENA_U32)) && \
            (PLLDIG_PLL4SR_LOLF_MASK32 == (u32Pll3Status  & PLLDIG_PLL4SR_LOLF_MASK32)) \
        )
        {
            /* signal to upper layer that PLLDIG_Pll3 lost lock */
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_PLL_LOCK_FAILURE);
        }
    }
#endif
}
#endif /* MCU_PLLDIG_PLL4_LOL_ISR_USED */
#endif /* (MCU_PLL4_UNDER_MCU_CONTROL == STD_ON) */
#endif /* ifdef MCU_PLL4_UNDER_MCU_CONTROL */
#endif 

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
