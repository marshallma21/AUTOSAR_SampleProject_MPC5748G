/**
*   @file    Mcu_CMU.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Clock Monitoring Unit functions implementation.
*   @details Specific functions for CMU configuration and control.
*            Part of the Magic Carpet hw IP.
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
* @section Mcu_CMU_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_CMU_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_CMU_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
* pointer to a function and a type other than an integral type. This violation is due to the
* pointer arithmetic used to write/ read the data to/from the registers
*
* @section Mcu_CMU_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is requiered
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_CMU_c_REF_5
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated
*
* @section Mcu_CMU_c_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section Mcu_CMU_c_REF_7
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function. These objects are external, and are used troughout the code
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
#include "Mcu_CMU.h"
#include "Mcu.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#if (MCU_RGM_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
#include "Mcu_IPW_Irq.h"
#endif

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_CMU_VENDOR_ID_C                      43
/** @violates @ref Mcu_CMU_c_REF_5 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_CMU_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_CMU_c_REF_5 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_CMU_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_CMU_c_REF_5 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_CMU_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_CMU_SW_MAJOR_VERSION_C               1
#define MCU_CMU_SW_MINOR_VERSION_C               0
#define MCU_CMU_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_CMU header file are of the same vendor */
#if (MCU_CMU_VENDOR_ID_C != MCU_CMU_VENDOR_ID)
    #error "Mcu_CMU.c and Mcu_CMU.h have different vendor ids"
#endif
/* Check if current file and Mcu_CMU header file are of the same Autosar version */
#if ((MCU_CMU_AR_RELEASE_MAJOR_VERSION_C    != MCU_CMU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CMU_AR_RELEASE_MINOR_VERSION_C    != MCU_CMU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CMU_AR_RELEASE_REVISION_VERSION_C != MCU_CMU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_CMU.c and Mcu_CMU.h are different"
#endif
/* Check if current file and Mcu_CMU header file are of the same Software version */
#if ((MCU_CMU_SW_MAJOR_VERSION_C != MCU_CMU_SW_MAJOR_VERSION) || \
     (MCU_CMU_SW_MINOR_VERSION_C != MCU_CMU_SW_MINOR_VERSION) || \
     (MCU_CMU_SW_PATCH_VERSION_C != MCU_CMU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_CMU.c and Mcu_CMU.h are different"
#endif

#if (MCU_RGM_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
/* Check if current file and Mcu_IPW_Irq header file are of the same vendor */
#if (MCU_CMU_VENDOR_ID_C != MCU_IPW_IRQ_VENDOR_ID)
    #error "Mcu_CMU.c and Mcu_IPW_Irq.h have different vendor ids"
#endif
/* Check if current file and Mcu_IPW_Irq header file are of the same Autosar version */
#if ((MCU_CMU_AR_RELEASE_MAJOR_VERSION_C    != MCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_CMU_AR_RELEASE_MINOR_VERSION_C    != MCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (MCU_CMU_AR_RELEASE_REVISION_VERSION_C != MCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_CMU.c and Mcu_IPW_Irq.h are different"
#endif
/* Check if current file and Mcu_IPW_Irq header file are of the same Software version */
#if ((MCU_CMU_SW_MAJOR_VERSION_C != MCU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (MCU_CMU_SW_MINOR_VERSION_C != MCU_IPW_IRQ_SW_MINOR_VERSION) || \
     (MCU_CMU_SW_PATCH_VERSION_C != MCU_IPW_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_CMU.c and Mcu_IPW_Irq.h are different"
#endif
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_CMU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_CMU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_CMU.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_CMU_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_CMU_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_CMU.c and SilRegMacros.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same vendor */
#if (MCU_CMU_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu_CMU.c and Mcu.h have different vendor ids"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_CMU_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_CMU_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
        (MCU_CMU_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Mcu_CMU.c and Mcu.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_CMU_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_CMU_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_CMU_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu_CMU.c and Mcu.h are different"
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/* doesn't have any CMU which is available on the platform. */
#define MCU_CMU_NONE_BASEADDR            ((uint32)0xFFFFFFFFUL)

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
#define MCU_START_SEC_CONST_32
/**
 * @violates @ref Mcu_CMU_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
 * @violates @ref Mcu_CMU_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
 * statements and comments before '#include'
 */
#include "Mcu_MemMap.h"

/**
* @brief CMU base address array
*/
/** @violates @ref Mcu_CMU_c_REF_4 Violates MISRA 2004 Required Rule 8.10, this symbol is only used at IPV_MCV4 level */
/** @violates @ref Mcu_CMU_c_REF_7 Violates MISRA 2004 Required Rule 8.7, these object are used trough the entire CMU code*/
CONST(uint32, MCU_CONST) Mcu_CMU_aBaseAddr[] =
{
#ifdef  CMU0_BASEADDR
    /** @brief check if CMU0 is available on the platform. */
    CMU0_BASEADDR,
#endif

#ifdef  CMU1_BASEADDR
    /** @brief check if CMU1 is available on the platform. */
    CMU1_BASEADDR,
#endif

#ifdef  CMU2_BASEADDR
    /** @brief check if CMU2 is available on the platform. */
    CMU2_BASEADDR,
#endif

#ifdef  CMU3_BASEADDR
    /** @brief check if CMU3 is available on the platform. */
    CMU3_BASEADDR,
#endif

#ifdef  CMU4_BASEADDR
    /** @brief check if CMU4 is available on the platform. */
    CMU4_BASEADDR,
#endif

#ifdef  CMU5_BASEADDR
    /** @brief check if CMU5 is available on the platform. */
    CMU5_BASEADDR,
#endif

#ifdef  CMU6_BASEADDR
    /** @brief check if CMU6 is available on the platform. */
    CMU6_BASEADDR,
#endif

#ifdef  CMU7_BASEADDR
    /** @brief check if CMU7 is available on the platform. */
    CMU7_BASEADDR,
#endif

#ifdef  CMU8_BASEADDR
    /** @brief check if CMU8 is available on the platform. */
    CMU8_BASEADDR,
#endif

#ifdef  CMU9_BASEADDR
    /** @brief check if CMU9 is available on the platform. */
    CMU9_BASEADDR,
#endif

#ifdef  CMU10_BASEADDR
    /** @brief check if CMU10 is available on the platform. */
    CMU10_BASEADDR,
#endif

#ifdef  CMU11_BASEADDR
    /** @brief check if CMU11 is available on the platform. */
    CMU11_BASEADDR,
#endif

#ifdef  CMU12_BASEADDR
    /** @brief check if CMU12 is available on the platform. */
    CMU12_BASEADDR,
#endif

#ifdef  CMU13_BASEADDR
    /** @brief check if CMU13 is available on the platform. */
    CMU13_BASEADDR,
#endif

#ifdef  CMU14_BASEADDR
    /** @brief check if CMU14 is available on the platform. */
    CMU14_BASEADDR,
#endif

#ifdef  CMU15_BASEADDR
    /** @brief check if CMU15 is available on the platform. */
    CMU15_BASEADDR,
#endif

    /** @brief doesn't have any CMU which is available on the platform. */
    MCU_CMU_NONE_BASEADDR
};

#define MCU_STOP_SEC_CONST_32
/**
 * @violates @ref Mcu_CMU_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
 * @violates @ref Mcu_CMU_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
 * statements and comments before '#include'
 */
#include "Mcu_MemMap.h"

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
* @violates @ref Mcu_CMU_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
* @violates @ref Mcu_CMU_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
* @violates @ref Mcu_CMU_c_REF_4 Global declaration of function
*/
FUNC( void, MCU_CODE) Mcu_CMU_SetUserAccessAllowed(void)
{
    /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
    SET_USER_ACCESS_ALLOWED(Mcu_CMU_aBaseAddr[0U]);
}
#endif
#endif

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function initializes the CMU module as after Reset.
* @details          The function configures the low and high frequecy reference values.
*                   Called by:
*                       - Mcu_Ipw_InitClock() from IPW.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_CMU_DeInit( VAR( void, AUTOMATIC) )
{
    /* Index for CMU units. */
    VAR( uint8, AUTOMATIC)   u8IndexCmu = 0U;

    /* MCU_CMU_UNITS define is generated in Mcu_Cfg.h and is specific to every platform. */
    for ( u8IndexCmu = 0U; u8IndexCmu < MCU_CMU_UNITS; u8IndexCmu++)
    {
        /* Reset the Control Status Register for CMU0. */
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32( CMU_CSR_X_ADDR32( u8IndexCmu ), MCU_CMU_CSR_RESET_VALUE_U32);

        /* CMU0: Set Low Frequency Reference. */
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32( CMU_LFREFR_X_ADDR32( u8IndexCmu ), MCU_CMU_LREF_RESET_VALUE_U32);

        /* CMU0: Set High Frequency Reference. */
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32( CMU_HFREFR_X_ADDR32( u8IndexCmu ), MCU_CMU_HFREFR_RESET_VALUE_U32);

        /* Clear CMU_MDR register value. */
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32( CMU_MDR_X_ADDR32( u8IndexCmu ), MCU_CMU_MDR_MD_RESET_VALUE_U32);

        /* Clear CMU_ISR register value. */
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32( CMU_ISR_X_ADDR32( u8IndexCmu ), MCU_CMU_ISR_RESET_VALUE_U32);
    }
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function initializes CMU blocks.
* @details          CMU blocks are used for monitoring major frequencis on the platform.
*                       - Mcu_Ipw_InitClock() from IPW.
*
* @param[in]        pCmu_ConfigPtr   Pointer to clock configuration structure (member of
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_CMU_Init(P2CONST(Mcu_CMU_ConfigType, AUTOMATIC, MCU_APPL_CONST) pCmu_ConfigPtr)
{
    /* Index for CMU units. */
    VAR(uint8, AUTOMATIC)   u8IndexCmu = 0U;

    /* MCU_CMU_UNITS define is generated in Mcu_Cgh.h and is specific to every platform. */
    for(u8IndexCmu = 0U; u8IndexCmu < MCU_CMU_UNITS; u8IndexCmu++)
    {
        /* Set High Frequency Reference. */
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32(CMU_HFREFR_X_ADDR32(u8IndexCmu), pCmu_ConfigPtr-> au32CmuHfRef[u8IndexCmu]);

        /* Set Low Frequency Reference. */
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32(CMU_LFREFR_X_ADDR32(u8IndexCmu), pCmu_ConfigPtr->au32CmuLfRef[u8IndexCmu]);

        /* Set CMU control register. */
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32(CMU_CSR_X_ADDR32(u8IndexCmu), pCmu_ConfigPtr-> au32CmuConfig[u8IndexCmu]);
    }
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
FUNC(void, MCU_CODE) Mcu_CMU_Disable_CMU(VAR (uint8, AUTOMATIC) u8IndexCmu)
{
    /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_BIT_CLEAR32(CMU_CSR_X_ADDR32(u8IndexCmu), CMU_CSR_CME_MASK32);
}
#endif
#endif

#if ((MCU_CMU_ERROR_ISR_USED == STD_ON) || (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON))
/**
* @brief        This function clear the CMU interrupt flag from CMU module.
* @details      Called by RGM ISR routine when a user notification for CMU FCCU events is configured
*
* @return       void
* @implements   Mcu_CMU_ClearClockFailIrqFlags_Activity
* @violates @ref Mcu_CMU_c_REF_4 Global declaration of function
*/
FUNC(Std_ReturnType, MCU_CODE) Mcu_CMU_ClearClockFailIrqFlags
(
    VAR(uint8, AUTOMATIC) u8CmuIdx,
    VAR(uint32, AUTOMATIC) u32IsrMask
)
{
    VAR(uint32, AUTOMATIC) u32cmuIsrValue;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR(uint32, AUTOMATIC) u32cmuCsrValue;
    VAR(Std_ReturnType, AUTOMATIC) CmuStatus = (Std_ReturnType)E_OK;
#endif

    /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
    u32cmuIsrValue = REG_READ32(CMU_ISR_X_ADDR32(u8CmuIdx)) & u32IsrMask;

    /* clear it's flags */
    /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(CMU_ISR_X_ADDR32(u8CmuIdx), u32cmuIsrValue);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_CMU_c_REF_3 Cast from unsigned long to pointer.*/
        /** @violates @ref Mcu_CMU_c_REF_6 The cast is used to access memory mapped registers.*/
        u32cmuCsrValue = REG_READ32(CMU_CSR_X_ADDR32(u8CmuIdx)) & CMU_CSR_MASK32;
        
        /* now check if there is a reason to signal to the upper layer */
        if(CMU_CSR_CME_MASK32 == (CMU_CSR_CME_MASK32 & u32cmuCsrValue))
        {
            /* cmu 0 got an extra feature */
            if(((uint8)0x00U == u8CmuIdx) && (CMU_ISR_OLRI_MASK32 == (CMU_ISR_OLRI_MASK32 & u32cmuIsrValue)))
            {
                CmuStatus = (Std_ReturnType)E_NOT_OK;
            }
#ifdef MCU_CMU_FLCI_BIT_PRESENT
#if (STD_ON == MCU_CMU_FLCI_BIT_PRESENT)
            /* cmu 0-4 got an extra bit */
            if(((uint8)0x06U > u8CmuIdx) && (CMU_ISR_FLCI_MASK32 == (CMU_ISR_FLCI_MASK32 & u32cmuIsrValue)))
            {
                CmuStatus = (Std_ReturnType)E_NOT_OK;
            }
#endif
#endif
            /* these are common to all cmu units */
            if ((CMU_ISR_FHHI_MASK32 == (CMU_ISR_FHHI_MASK32 & u32cmuIsrValue)) || \
                (CMU_ISR_FLLI_MASK32 == (CMU_ISR_FLLI_MASK32 & u32cmuIsrValue)) \
               )
            {
                CmuStatus = (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    
    return (Std_ReturnType)CmuStatus;
#else
    return (Std_ReturnType)E_OK;
#endif
}
#endif /* ((MCU_CMU_ERROR_ISR_USED == STD_ON) || (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON)) */

#if (MCU_CMU_ERROR_ISR_USED == STD_ON)
/**
* @brief            This function clear the interrupt flags from CMU module.
* @details          Called by ISR routine when a monitoring frequency is out of monitored range.
*                   FCCU NonCriticalFault4 catch the "Loss of XOSC clock".
*                   FCCU NonCriticalFault5 catch the "System Frequency out of Range".
*                   FCCU NonCriticalFault6 catch the "Motor Frequency out of Range".
*                   FCCU NonCriticalFault7 catch the "FlexRay Frequency out of Range".
*
* @return           void
* @implements Mcu_CMU_ClockFailInt_Activity
* @violates @ref Mcu_CMU_c_REF_4 Global declaration of function
*/
FUNC(void, MCU_CODE) Mcu_CMU_ClockFailInt(VAR(void, AUTOMATIC))
{
    VAR(uint8, AUTOMATIC) u8IndexCmu = 0U;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR(uint8, AUTOMATIC) u8CmuFailled = (uint8)0x00U;
#endif
    VAR(Std_ReturnType, AUTOMATIC) CmuStatus;

#if (MCU_RGM_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        Mcu_Ipw_RgmClearClockFailIrqFlags();
    }
#endif

    for(u8IndexCmu = 0U; u8IndexCmu < MCU_CMU_UNITS; u8IndexCmu++)
    {
        CmuStatus = Mcu_CMU_ClearClockFailIrqFlags(u8IndexCmu, CMU_ISR_MASK32);
        if(NULL_PTR != Mcu_pConfigPtr)
        {
            if((Std_ReturnType)E_NOT_OK == CmuStatus)
            {
#ifdef MCU_ERROR_ISR_NOTIFICATION
                u8CmuFailled = (uint8)0xFFU;
#endif
#ifdef MCU_CMU_FCCU_NOTIFICATION
                /* call the notification */
                MCU_CMU_FCCU_NOTIFICATION(u8IndexCmu);
#endif
            }
        }
    }

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        if((uint8)0xFFU == u8CmuFailled)
        {
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_CLOCK_FAILURE);
        }
    }
#endif
}
#endif /* (MCU_CMU_ERROR_ISR_USED == STD_ON) */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_CMU_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_CMU_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

