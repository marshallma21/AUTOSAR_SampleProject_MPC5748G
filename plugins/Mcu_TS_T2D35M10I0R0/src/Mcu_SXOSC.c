/**
*   @file    Mcu_SXOSC.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Slow External Oscillator functions implementation.
*   @details Specific functions for SXOSC configuration and control.
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
* @section Mcu_SXOSC_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_SXOSC_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_SXOSC_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
* pointer to a function and a type other than an integral type. This violation is due to the
* pointer arithmetic used to write/ read the data to/from the registers
*
* @section Mcu_SXOSC_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is requiered
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_SXOSC_c_REF_5
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
#include "Mcu_SXOSC.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define Mcu_SXOSC_VENDOR_ID_C                      43
#define Mcu_SXOSC_AR_RELEASE_MAJOR_VERSION_C       4
#define Mcu_SXOSC_AR_RELEASE_MINOR_VERSION_C       2
#define Mcu_SXOSC_AR_RELEASE_REVISION_VERSION_C    2
#define Mcu_SXOSC_SW_MAJOR_VERSION_C               1
#define Mcu_SXOSC_SW_MINOR_VERSION_C               0
#define Mcu_SXOSC_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if current file and Mcu_SXOSC header file are of the same vendor */
#if (Mcu_SXOSC_VENDOR_ID_C != MCU_SXOSC_VENDOR_ID)
    #error "Mcu_SXOSC.c and Mcu_SXOSC.h have different vendor ids"
#endif
/* Check if current file and Mcu_SXOSC header file are of the same Autosar version */
#if ((Mcu_SXOSC_AR_RELEASE_MAJOR_VERSION_C    != MCU_SXOSC_AR_RELEASE_MAJOR_VERSION) || \
     (Mcu_SXOSC_AR_RELEASE_MINOR_VERSION_C    != MCU_SXOSC_AR_RELEASE_MINOR_VERSION) || \
     (Mcu_SXOSC_AR_RELEASE_REVISION_VERSION_C != MCU_SXOSC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SXOSC.c and Mcu_SXOSC.h are different"
#endif
/* Check if current file and Mcu_SXOSC header file are of the same Software version */
#if ((Mcu_SXOSC_SW_MAJOR_VERSION_C != MCU_SXOSC_SW_MAJOR_VERSION) || \
     (Mcu_SXOSC_SW_MINOR_VERSION_C != MCU_SXOSC_SW_MINOR_VERSION) || \
     (Mcu_SXOSC_SW_PATCH_VERSION_C != MCU_SXOSC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SXOSC.c and Mcu_SXOSC.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_SXOSC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_SXOSC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SXOSC.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_SXOSC_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_SXOSC_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SXOSC.c and SilRegMacros.h are different"
    #endif
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


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
* @violates @ref Mcu_SXOSC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
* @violates @ref Mcu_SXOSC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_SXOSC_UNDER_MCU_CONTROL == STD_ON)

/**
* @brief            Write SXOSC configuration if under MCU control
* @details          
*
* @param[in]        Mcu_pSxoscConf - configuration pointer
*
* @return           void
*
*/
/** @violates @ref Mcu_SXOSC_c_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC( void, MCU_CODE) Mcu_SXOSC_Config(P2CONST(Mcu_SXOSC_ConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pSxoscConf)
{
    /* write SXOSC configuration registers */
    /** @violates @ref Mcu_SXOSC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_SXOSC_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SXOSC_CTL_ADDR32, Mcu_pSxoscConf->u32SxoscCtl);
}
#endif /* (MCU_SXOSC_UNDER_MCU_CONTROL == STD_ON) */



#if (MCU_SXOSC_INT_USED == STD_ON)

FUNC( void, MCU_CODE) Mcu_SXOSC_ClockInterrupt(VAR(void, AUTOMATIC))
{
    VAR( uint32, AUTOMATIC) u32Status;
    
    /* get CTL value */
    /** @violates @ref Mcu_SXOSC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_SXOSC_c_REF_5 The cast is used to access memory mapped registers.*/
    u32Status = REG_READ32(SXOSC_CTL_ADDR32);
    
    /* clear the IRQ - write 1 to clear */
    /** @violates @ref Mcu_SXOSC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_SXOSC_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(SXOSC_CTL_ADDR32 , (u32Status | SXOSC_CTL_I_OSC_MASK32));
}

#endif


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SXOSC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SXOSC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

