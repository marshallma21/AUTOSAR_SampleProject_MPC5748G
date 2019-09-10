/**
*   @file    Mcu_eMios.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - eMios functions implementation.
*   @details Specific functions for eMios configuration and control.
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
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section MCU_EMIOS_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
*
* @section MCU_EMIOS_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files,  Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section MCU_EMIOS_C_REF_3
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned long to pointer.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section MCU_EMIOS_C_REF_4
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions at
* file scope shall have internal linkage unless external linkage is required. This variables cannot
* be made static, because they are used by applications.
*
* @section MCU_EMIOS_C_REF_5
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
* @section MCU_EMIOS_C_REF_6
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
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_eMios.h"
#include "SchM_Mcu.h"

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_EMIOS_VENDOR_ID_C                           43
#define MCU_EMIOS_AR_RELEASE_MAJOR_VERSION_C            4
#define MCU_EMIOS_AR_RELEASE_MINOR_VERSION_C            2
#define MCU_EMIOS_AR_RELEASE_REVISION_VERSION_C         2
#define MCU_EMIOS_SW_MAJOR_VERSION_C                    1
#define MCU_EMIOS_SW_MINOR_VERSION_C                    0
#define MCU_EMIOS_SW_PATCH_VERSION_C                    0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and Mcu_eMios header file are of the same vendor */
#if (MCU_EMIOS_VENDOR_ID_C != MCU_EMIOS_H_VENDOR_ID)
    #error "Mcu_eMios.c and Mcu_eMios.h have different vendor ids"
#endif
/* Check if current file and Mcu_eMios header file are of the same Autosar version */
#if ((MCU_EMIOS_AR_RELEASE_MAJOR_VERSION_C    != MCU_EMIOS_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_EMIOS_AR_RELEASE_MINOR_VERSION_C    != MCU_EMIOS_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_EMIOS_AR_RELEASE_REVISION_VERSION_C != MCU_EMIOS_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_eMios.c and Mcu_eMios.h are different"
#endif
/* Check if current file and Mcu_eMios header file are of the same Software version */
#if ((MCU_EMIOS_SW_MAJOR_VERSION_C != MCU_EMIOS_H_SW_MAJOR_VERSION) || \
     (MCU_EMIOS_SW_MINOR_VERSION_C != MCU_EMIOS_H_SW_MINOR_VERSION) || \
     (MCU_EMIOS_SW_PATCH_VERSION_C != MCU_EMIOS_H_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_eMios.c and Mcu_eMios.h are different"
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_EMIOS_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_eMios.c and SilRegMacros.h are different"
    #endif
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/
/* doesn't have any EMIOS which is available on the platform. */
/** @violates @ref MCU_EMIOS_C_REF_5 This is not a standard library macro */
#define EMIOS3_MCR_NONE_ADDR32            ((uint32)0xFFFFFFFFUL)

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
#define MCU_START_SEC_CONST_32
/**
* @violates @ref MCU_EMIOS_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_EMIOS_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/**
* @violates @ref MCU_EMIOS_C_REF_4 This is not a standard library macro
* @violates @ref MCU_EMIOS_C_REF_5 This symbol is only used at IPV_EMIOS level
*/
CONST(uint32, MCU_CONST) EMIOS_MCR_ADDR32[] = 
{
#ifdef EMIOS0_BASEADDR
    /** @brief check if first emios is available on the platform */
    EMIOS0_BASEADDR,
#endif

#ifdef EMIOS1_BASEADDR
    /** @brief check if second emios is available on the platform */
    EMIOS1_BASEADDR,
#endif

#ifdef EMIOS2_BASEADDR
    /** @brief check if third emios is available on the platform */
    EMIOS2_BASEADDR,
#endif

#ifdef EMIOS3_BASEADDR
    /** @brief check if for fourth emios is available on the platform */
    EMIOS3_BASEADDR,
#endif

    /** @brief doesn't have any EMIOS which is available on the platform. */
    EMIOS3_MCR_NONE_ADDR32
};

#define MCU_STOP_SEC_CONST_32
/**
* @violates @ref MCU_EMIOS_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
 *  @violates @ref MCU_EMIOS_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
 *  statements and comments before '#include' */
#include "Mcu_MemMap.h"
/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref MCU_EMIOS_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_EMIOS_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (MCU_EMIOS_SUPPORT == STD_ON)
/**
* @brief            Initializes the EMIOS MCR register for EMIOS_0, EMIOS_1
* @details          Function to initialize the Emios MCR register value configured.
*                   Called by:
*                       - Mcu_IPW_InitClock() and Mcu_IPW_DistributePllClock() from IPW.
*
* @param[in]        pEmiosConfigPtr   Pointer to eMios configuration structure.
*
* @return           void
*
*/
/** @violates @ref MCU_EMIOS_C_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC (void, MCU_CODE) Mcu_eMios_Init(VAR (uint8, AUTOMATIC) u8Module, P2CONST(Mcu_eMios_ConfigType, AUTOMATIC, MCU_APPL_CONST) pConfigPtr)
{
    /* Enter critical region*/
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_00();

    /** @violates @ref MCU_EMIOS_C_REF_3 Cast from unsigned long to pointer. */
    /** @violates @ref MCU_EMIOS_C_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(EMIOS_MCR_ADDR32[u8Module], pConfigPtr->au32EmiosData[u8Module]);

    /* Exit critical region. */
    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_00();
}
#endif

#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
/**
 * @brief   eMios Global Prescaler Enable.
 * @details This function enable/disable the GPREN bit of the EMIOSMCR register of an
 *          addressed eMIOS instance.
 *                   Called by:
 *                       - Mcu_IPW_CheckEmiosStatus() from IPW.
 *
 * @param[in] u8Module       MCU_EMIOS_MODULE_0 --> Select eMios 0
 *                           MCU_EMIOS_MODULE_1 --> Select eMios 1
 *                           MCU_EMIOS_MODULE_2 --> Select eMios 2
 *                           MCU_EMIOS_MODULE_3 --> Select eMios 3
 *
 * @param[in] u8Value        MCU_EMIOS_GPREN_BIT_ENABLE   --> Global Prescaler Enabled
 *                           MCU_EMIOS_GPREN_BIT_DISABLE  --> Global Prescaler Disabled
 *
 * @return                   void
 *
 */
FUNC( void, MCU_CODE ) Mcu_eMios_ConfigureGpren(VAR (uint8, AUTOMATIC) u8Module, VAR (uint8, AUTOMATIC) u8Value)
{
    /* Enter critical region*/
    SchM_Enter_Mcu_MCU_EXCLUSIVE_AREA_01();
    
    if (MCU_EMIOS_GPREN_BIT_ENABLE == u8Value)
    {
        /** @violates @ref MCU_EMIOS_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref MCU_EMIOS_C_REF_6 The cast is used to access memory mapped registers.*/
        REG_BIT_SET32(EMIOS_MCR_ADDR32[u8Module], EMIOS_MCR_GPREN_MASK32);
    }
    else
    {
        /** @violates @ref MCU_EMIOS_C_REF_3 Cast from unsigned long to pointer. */
        /** @violates @ref MCU_EMIOS_C_REF_6 The cast is used to access memory mapped registers.*/
        REG_BIT_CLEAR32(EMIOS_MCR_ADDR32[u8Module], EMIOS_MCR_GPREN_MASK32);
    }
    
    /* Exit critical region. */
    SchM_Exit_Mcu_MCU_EXCLUSIVE_AREA_01();
}
#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref MCU_EMIOS_C_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref MCU_EMIOS_C_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
