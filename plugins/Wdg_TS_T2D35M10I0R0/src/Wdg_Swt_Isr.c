/**
*   @file    Wdg_Swt_Isr.c
*
*   @version 1.0.0
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) functions
*   @details Contains functions for accessing SWT from the WDG driver perspective
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : Swt
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
* @section Wdg_Swt_Isr_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
*
* @section Wdg_Swt_Isr_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*
* @section Wdg_Swt_Isr_c_REF_3
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
*          pointer to a function and a type other than an integral type. This violation is due to the
*          pointer arithmetic used to write/ read the data to/from the registers
*
* @section Wdg_Swt_Isr_c_REF_4
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
*          The functions are external.
*
* @section Wdg_Swt_Isr_c_REF_5
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer
*          type and an integral type. This violation is due to the pointer arithmetic used to 
*          write/ read the data to/from the registers.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Wdg_Swt_Isr.c   
*/
#include "Wdg_IPW_Types.h"
#include "Mcal.h"
#include "Wdg_Irq.h"
#include "Reg_eSys_Swt.h"
#include "Reg_eSys_Swt_defines.h"
#include "StdRegMacros.h"


/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Swt_Isr.c     
*/
#define WDG_SWT_ISR_VENDOR_ID_C                     43
#define WDG_SWT_ISR_AR_RELEASE_MAJOR_VERSION_C      4
#define WDG_SWT_ISR_AR_RELEASE_MINOR_VERSION_C      2
#define WDG_SWT_ISR_AR_RELEASE_REVISION_VERSION_C   2
#define WDG_SWT_ISR_SW_MAJOR_VERSION_C              1
#define WDG_SWT_ISR_SW_MINOR_VERSION_C              0
#define WDG_SWT_ISR_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_IPW_Types header file are of the same vendor */
#if (WDG_SWT_ISR_VENDOR_ID_C != WDG_IPW_TYPES_VENDOR_ID)
    #error "Wdg_Swt_Isr.c and Wdg_IPW_Types.h have different vendor ids"
#endif
/* Check if current file and Wdg_IPW_Types header file are of the same Autosar version */
#if ((WDG_SWT_ISR_AR_RELEASE_MAJOR_VERSION_C    != WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_ISR_AR_RELEASE_MINOR_VERSION_C    != WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_ISR_AR_RELEASE_REVISION_VERSION_C != WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt_Isr.c and Wdg_IPW_Types.h are different"
#endif
/* Check if current file and Wdg_IPW_Types header file are of the same Software version */
#if ((WDG_SWT_ISR_SW_MAJOR_VERSION_C != WDG_IPW_TYPES_SW_MAJOR_VERSION) || \
     (WDG_SWT_ISR_SW_MINOR_VERSION_C != WDG_IPW_TYPES_SW_MINOR_VERSION) || \
     (WDG_SWT_ISR_SW_PATCH_VERSION_C != WDG_IPW_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt_Isr.c and Wdg_IPW_Types.h are different"
#endif

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_SWT_ISR_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_SWT_ISR_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_Swt_Isr.c and Mcal.h are different"
    #endif
#endif

/* Check if current file and Wdg_Irq header file are of the same vendor */
#if (WDG_SWT_ISR_VENDOR_ID_C != WDG_IRQ_VENDOR_ID)
    #error "Wdg_Swt_Isr.c and Wdg_Irq.h have different vendor ids"
#endif
/* Check if current file and Wdg_Irq header file are of the same Autosar version */
#if ((WDG_SWT_ISR_AR_RELEASE_MAJOR_VERSION_C    != WDG_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_ISR_AR_RELEASE_MINOR_VERSION_C    != WDG_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_ISR_AR_RELEASE_REVISION_VERSION_C != WDG_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt_Isr.c and Wdg_Irq.h are different"
#endif
/* Check if current file and Wdg_Irq header file are of the same Software version */
#if ((WDG_SWT_ISR_SW_MAJOR_VERSION_C != WDG_IRQ_SW_MAJOR_VERSION) || \
     (WDG_SWT_ISR_SW_MINOR_VERSION_C != WDG_IRQ_SW_MINOR_VERSION) || \
     (WDG_SWT_ISR_SW_PATCH_VERSION_C != WDG_IRQ_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt_Isr.c and Wdg_Irq.h are different"
#endif

/* Check if current file and SWT register header file are of the same vendor */
#if (WDG_SWT_ISR_VENDOR_ID_C != REG_ESYS_SWT_VENDOR_ID)
    #error "Wdg_Swt_Isr.c and Reg_eSys_Swt.h have different vendor ids"
#endif

/* Check if source file and SWT register header file are of the same Autosar version */
#if ((WDG_SWT_ISR_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_SWT_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_ISR_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_SWT_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_ISR_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SWT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt_Isr.c and Reg_eSys_Swt.h are different"
#endif

/* Check if source file and SWT register header file are of the same Software version */
#if ((WDG_SWT_ISR_SW_MAJOR_VERSION_C != REG_ESYS_SWT_SW_MAJOR_VERSION) || \
     (WDG_SWT_ISR_SW_MINOR_VERSION_C != REG_ESYS_SWT_SW_MINOR_VERSION) || \
     (WDG_SWT_ISR_SW_PATCH_VERSION_C != REG_ESYS_SWT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt_Isr.c and Reg_eSys_Swt.h are different"
#endif

/* Check if current file and Reg_eSys_Swt_defines header file are of the same vendor */
#if (WDG_SWT_ISR_VENDOR_ID_C != REG_ESYS_SWT_DEFINES_VENDOR_ID)
    #error "Wdg_Swt_Isr.c and Reg_eSys_Swt_defines.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_Swt_defines header file are of the same Autosar version */
#if ((WDG_SWT_ISR_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_SWT_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_ISR_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_SWT_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_ISR_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SWT_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt_Isr.c and Reg_eSys_Swt_defines.h are different"
#endif

/* Check if source file and Reg_eSys_Swt_defines header file are of the same Software version */
#if ((WDG_SWT_ISR_SW_MAJOR_VERSION_C != REG_ESYS_SWT_DEFINES_SW_MAJOR_VERSION) || \
     (WDG_SWT_ISR_SW_MINOR_VERSION_C != REG_ESYS_SWT_DEFINES_SW_MINOR_VERSION) || \
     (WDG_SWT_ISR_SW_PATCH_VERSION_C != REG_ESYS_SWT_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt_Isr.c and Reg_eSys_Swt_defines.h are different"
#endif

/* Check if current file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_SWT_ISR_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_SWT_ISR_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_Swt_Isr.c and StdRegMacros.h are different"
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
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_Isr_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_Isr_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"
#if ((defined WDG_ISR0_USED)|| (defined WDG_ISR1_USED)|| (defined WDG_ISR2_USED) || (defined WDG_ISR3_USED)) || (defined WDG_ISR4_USED)
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_Swt_ProcessInterrupt(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance);
#endif

#ifdef WDG_ISR0_USED
ISR(Wdg_Swt0_Isr);
#endif /* WDG_ISR0_USED */

#ifdef WDG_ISR1_USED
ISR(Wdg_Swt1_Isr);
#endif /* WDG_ISR1_USED */

#ifdef WDG_ISR2_USED
ISR(Wdg_Swt2_Isr);
#endif /* WDG_ISR2_USED */

#ifdef WDG_ISR3_USED
ISR(Wdg_Swt3_Isr);
#endif /* WDG_ISR3_USED */

#ifdef WDG_ISR4_USED
ISR(Wdg_Swt4_Isr);
#endif /* WDG_ISR4_USED */
#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_Isr_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_Isr_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_Isr_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_Isr_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/**
*   @brief   This function process the interrupt.
*   @details This function process the SWT interrup
*
*   @param[in]          Wdg_Instance        Harwdware SWT instance.
* 
*
*/
#if ((defined WDG_ISR0_USED) || (defined WDG_ISR1_USED) || (defined WDG_ISR2_USED) || (defined WDG_ISR3_USED)) || (defined WDG_ISR4_USED)
LOCAL_INLINE FUNC(void, WDG_CODE) Wdg_Swt_ProcessInterrupt(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
    /* @violates @ref Wdg_Swt_Isr_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_Isr_c_REF_5 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    VAR(uint32, AUTOMATIC) swt_u32IntEnableFlag = REG_READ32(SWT_CR_ADDR32(Wdg_Instance)) & SWT_INTERRUPT_TOGGLE_U32;
    /* @violates @ref Wdg_Swt_Isr_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_Isr_c_REF_5 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    VAR(uint32, AUTOMATIC) swt_u32IntStatusFlag = REG_READ32(SWT_IR_ADDR32(Wdg_Instance)) & SWT_IR_CLEAR_U32;
    
    /* Clear the interrupt flag  */
    /* @violates @ref Wdg_Swt_Isr_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_Isr_c_REF_5 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(SWT_IR_ADDR32(Wdg_Instance), SWT_IR_CLEAR_U32);
    
    /* Check for spurious interrupt */
    if((SWT_INTERRUPT_TOGGLE_U32 == swt_u32IntEnableFlag) && (SWT_IR_CLEAR_U32 == swt_u32IntStatusFlag))
    {
        Wdg_ProcessInterrupt(Wdg_Instance);
    }
}
#endif

#ifdef WDG_ISR0_USED
/**
*   @brief   This function process the interrupt SWT0.
*   @details This function process the SWT0 interrup
*   @isr
    @implements  Wdg_SwtInterfaceNo_Isr_Activity
*   @violates @ref Wdg_Swt_Isr_c_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Wdg_Swt0_Isr)
{
    Wdg_Swt_ProcessInterrupt(WDG_IPW_INSTANCE0);
    /* @violates @ref Wdg_Swt_Isr_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    EXIT_INTERRUPT();
}

#endif /* WDG_ISR_USED */

#ifdef WDG_ISR1_USED
/**
*   @brief   This function process the interrupt SWT1.
*   @details This function process the SWT1 interrup
*   @implements  Wdg_SwtInterfaceNo_Isr_Activity
*   @isr
*   @violates @ref Wdg_Swt_Isr_c_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Wdg_Swt1_Isr)
{
    Wdg_Swt_ProcessInterrupt(WDG_IPW_INSTANCE1);
    /* @violates @ref Wdg_Swt_Isr_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    EXIT_INTERRUPT();
}

#endif /* WDG_ISR_USED */

#ifdef WDG_ISR2_USED
/**
*   @brief   This function process the interrupt SWT2.
*   @details This function process the SWT2 interrup
*   @implements  Wdg_SwtInterfaceNo_Isr_Activity
*   @isr
*   @violates @ref Wdg_Swt_Isr_c_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Wdg_Swt2_Isr)
{
    Wdg_Swt_ProcessInterrupt(WDG_IPW_INSTANCE2);
    /* @violates @ref Wdg_Swt_Isr_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    EXIT_INTERRUPT();
}

#endif /* WDG_ISR_USED */

#ifdef WDG_ISR3_USED
/**
*   @brief   This function process the interrupt SWT3.
*   @details This function process the SWT3 interrup
    @implements  Wdg_SwtInterfaceNo_Isr_Activity
*   @isr
*   @violates @ref Wdg_Swt_Isr_c_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Wdg_Swt3_Isr)
{
    Wdg_Swt_ProcessInterrupt(WDG_IPW_INSTANCE3);
    /* @violates @ref Wdg_Swt_Isr_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    EXIT_INTERRUPT();
}

#endif /* WDG_ISR_USED */


#ifdef WDG_ISR4_USED
/**
*   @brief   This function process the interrupt SWT4.
*   @details This function process the SWT4 interrup
    @implements  Wdg_SwtInterfaceNo_Isr_Activity
*   @isr
*   @violates @ref Wdg_Swt_Isr_c_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
ISR(Wdg_Swt4_Isr)
{
    Wdg_Swt_ProcessInterrupt(WDG_IPW_INSTANCE4);
    /* @violates @ref Wdg_Swt_Isr_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    EXIT_INTERRUPT();
}

#endif /* WDG_ISR_USED */

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_Isr_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_Isr_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
