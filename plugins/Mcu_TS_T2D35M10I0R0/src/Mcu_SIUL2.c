/**
*   @file    Mcu_SIUL2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Power Control Unit module functions implementation.
*   @details Specific functions for AFE configuration and control.
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
* @section Mcu_SIUL2_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_SIUL2_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_SIUL2_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers. The defines
* are validated.
*
* @section Mcu_SIUL2_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. Appears when accessing memory-mapped registers.
*
* @section Mcu_SIUL2_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*
* @section Mcu_SIUL2_c_REF_6
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
#include "Mcu_SIUL2.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/
#define MCU_SIUL2_VENDOR_ID_C                      43
/** @violates @ref Mcu_SIUL2_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_SIUL2_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_SIUL2_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_SIUL2_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_SIUL2_c_REF_3 The compiler/linker shall be checked ... */
#define MCU_SIUL2_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_SIUL2_SW_MAJOR_VERSION_C               1
#define MCU_SIUL2_SW_MINOR_VERSION_C               0
#define MCU_SIUL2_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_SIUL2 header file are of the same vendor. */
#if (MCU_SIUL2_VENDOR_ID_C != MCU_SIUL2_VENDOR_ID)
    #error "Mcu_SIUL2.c and Mcu_SIUL2.h have different Vendor IDs."
#endif
#ifdef CHECK_AUTOSAR_VERSION
  /* Check if source file and Mcu_SIUL2 header file are of the same Autosar version. */
  #if ( (MCU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != MCU_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_SIUL2_AR_RELEASE_MINOR_VERSION_C != MCU_SIUL2_AR_RELEASE_MINOR_VERSION) || \
        (MCU_SIUL2_AR_RELEASE_REVISION_VERSION_C != MCU_SIUL2_AR_RELEASE_REVISION_VERSION) \
      )
        #error "AutoSar Version Numbers of Mcu_SIUL2.c and Mcu_SIUL2.h are different."
  #endif
#endif
/* Check if source file and Mcu_SIUL2 header file are of the same Software version. */
#if ( (MCU_SIUL2_SW_MAJOR_VERSION_C != MCU_SIUL2_SW_MAJOR_VERSION) || \
      (MCU_SIUL2_SW_MINOR_VERSION_C != MCU_SIUL2_SW_MINOR_VERSION) || \
      (MCU_SIUL2_SW_PATCH_VERSION_C != MCU_SIUL2_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SIUL2.c and Mcu_SIUL2.h are different."
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SIUL2_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SIUL2.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SIUL2_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SIUL2_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SIUL2.c and SilRegMacros.h are different"
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
* @violates @ref Mcu_SIUL2_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SIUL2_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include'
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_GET_MIDR_API == STD_ON)
FUNC( void, MCU_CODE) Mcu_SIUL2_GetMidrStructure(P2VAR(Mcu_MidrReturnType, AUTOMATIC, MCU_APPL_DATA) pMidr)
{
    /** @violates @ref Mcu_SIUL2_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SIUL2_c_REF_6 The cast is used to access memory mapped registers.*/
    pMidr->u32Midr1 = REG_READ32( SIUL2_MIDR1_ADDR32 );
    /** @violates @ref Mcu_SIUL2_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_SIUL2_c_REF_6 The cast is used to access memory mapped registers.*/
    pMidr->u32Midr2 = REG_READ32( SIUL2_MIDR2_ADDR32 );
}
#endif /* (MCU_GET_MIDR_API == STD_ON) */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SIUL2_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SIUL2_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */
