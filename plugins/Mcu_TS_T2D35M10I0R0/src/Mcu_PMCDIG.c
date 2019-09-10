/**
*   @file    Mcu_PMCDIG.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - PMCDIG functions implementation.
*   @details Specific functions for PMCDIG configuration and control.
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
* @section Mcu_PMCDIG_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_PMCDIG_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_PMCDIG_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
* pointer to a function and a type other than an integral type. This violation is due to the
* pointer arithmetic used to write/ read the data to/from the registers
*
* @section Mcu_PMCDIG_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is requiered
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_PMCDIG_c_REF_5
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
#include "Mcu_PMCDIG.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define Mcu_PMCDIG_VENDOR_ID_C                      43
#define Mcu_PMCDIG_AR_RELEASE_MAJOR_VERSION_C       4
#define Mcu_PMCDIG_AR_RELEASE_MINOR_VERSION_C       2
#define Mcu_PMCDIG_AR_RELEASE_REVISION_VERSION_C    2
#define Mcu_PMCDIG_SW_MAJOR_VERSION_C               1
#define Mcu_PMCDIG_SW_MINOR_VERSION_C               0
#define Mcu_PMCDIG_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if current file and Mcu_PMCDIG header file are of the same vendor */
#if (Mcu_PMCDIG_VENDOR_ID_C != MCU_PMCDIG_VENDOR_ID)
    #error "Mcu_PMCDIG.c and Mcu_PMCDIG.h have different vendor ids"
#endif
/* Check if current file and Mcu_PMCDIG header file are of the same Autosar version */
#if ((Mcu_PMCDIG_AR_RELEASE_MAJOR_VERSION_C    != MCU_PMCDIG_AR_RELEASE_MAJOR_VERSION) || \
     (Mcu_PMCDIG_AR_RELEASE_MINOR_VERSION_C    != MCU_PMCDIG_AR_RELEASE_MINOR_VERSION) || \
     (Mcu_PMCDIG_AR_RELEASE_REVISION_VERSION_C != MCU_PMCDIG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PMCDIG.c and Mcu_PMCDIG.h are different"
#endif
/* Check if current file and Mcu_PMCDIG header file are of the same Software version */
#if ((Mcu_PMCDIG_SW_MAJOR_VERSION_C != MCU_PMCDIG_SW_MAJOR_VERSION) || \
     (Mcu_PMCDIG_SW_MINOR_VERSION_C != MCU_PMCDIG_SW_MINOR_VERSION) || \
     (Mcu_PMCDIG_SW_PATCH_VERSION_C != MCU_PMCDIG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PMCDIG.c and Mcu_PMCDIG.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_PMCDIG_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_PMCDIG_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PMCDIG.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_PMCDIG_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_PMCDIG_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PMCDIG.c and SilRegMacros.h are different"
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
* @violates @ref Mcu_PMCDIG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
* @violates @ref Mcu_PMCDIG_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#if (MCU_PMCDIG_UNDER_MCU_CONTROL == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
*/
/** @violates @ref Mcu_PMCDIG_c_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC( void, MCU_CODE) Mcu_PMCDIG_SetUserAccessAllowed(void)
{
    /** @violates @ref Mcu_PMCDIG_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_PMCDIG_c_REF_5 The cast is used to access memory mapped registers.*/
    SET_USER_ACCESS_ALLOWED(PMCDIG_BASEADDR);
}
#endif
#endif

/**
* @brief            Write PMCDIG configuration if under MCU control
* @details          Write PMCDIG registers with the configuration values
*
* @param[in]        Mcu_pPmcdigConf - configuration pointer
*
* @return           void
*
*/
/** @violates @ref Mcu_PMCDIG_c_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC( void, MCU_CODE) Mcu_PMCDIG_Config(P2CONST(Mcu_PMCDIG_ConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pPmcdigConf)
{
    /* write PMCDIG configuration registers */
    /** @violates @ref Mcu_PMCDIG_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_PMCDIG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PMCDIG_RDCR_ADDR32, Mcu_pPmcdigConf->u32PmcdigRDCR );
    
    /** @violates @ref Mcu_PMCDIG_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_PMCDIG_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32( PMCDIG_MCR_ADDR32, Mcu_pPmcdigConf->u32PmcdigMCR );
}
#endif /* (MCU_PMCDIG_UNDER_MCU_CONTROL == STD_ON) */


#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_PMCDIG_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PMCDIG_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

