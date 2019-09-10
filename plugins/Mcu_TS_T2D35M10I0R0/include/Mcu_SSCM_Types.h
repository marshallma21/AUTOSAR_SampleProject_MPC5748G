/**
*   @file    Mcu_SSCM_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from SSCM.
*   @details Public data types exported outside of the Mcu driver.
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


#ifndef MCU_SSCM_TYPES_H
#define MCU_SSCM_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_SSCM_Types_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
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
#include "Mcu_Cfg.h"
#include "Reg_eSys_SSCM.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_SSCM_TYPES_VENDOR_ID                      43
#define MCU_SSCM_TYPES_AR_RELEASE_MAJOR_VERSION       4
#define MCU_SSCM_TYPES_AR_RELEASE_MINOR_VERSION       2
#define MCU_SSCM_TYPES_AR_RELEASE_REVISION_VERSION    2
#define MCU_SSCM_TYPES_SW_MAJOR_VERSION               1
#define MCU_SSCM_TYPES_SW_MINOR_VERSION               0
#define MCU_SSCM_TYPES_SW_PATCH_VERSION               0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_SSCM_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_SSCM_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_SSCM_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SSCM_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SSCM_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SSCM_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_SSCM_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_SSCM_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_SSCM_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SSCM_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_SSCM_TYPES_VENDOR_ID != REG_ESYS_SSCM_VENDOR_ID)
    #error "Mcu_SSCM_Types.h and Reg_eSys_SSCM.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_SSCM_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_SSCM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SSCM_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_SSCM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SSCM_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_SSCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SSCM_Types.h and Reg_eSys_SSCM.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_SSCM_TYPES_SW_MAJOR_VERSION != REG_ESYS_SSCM_SW_MAJOR_VERSION) || \
     (MCU_SSCM_TYPES_SW_MINOR_VERSION != REG_ESYS_SSCM_SW_MINOR_VERSION) || \
     (MCU_SSCM_TYPES_SW_PATCH_VERSION != REG_ESYS_SSCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SSCM_Types.h and Reg_eSys_SSCM.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* SSCM Error Configuration Register (SSCM_ERROR) */
/** @violates @ref Mcu_SSCM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define SSCM_ERROR_U16(value)               ((((value)) & SSCM_ERROR_RWBITS_MASK16) | SSCM_ERROR_RESBITS_MASK16)

#define SSCM_ERROR_PAE_ENABLE_U16           (SSCM_ERROR_PAE_MASK16)
#define SSCM_ERROR_PAE_DISABLE_U16          ((uint16)0x0000U)

#define SSCM_ERROR_RAE_ENABLE_U16           (SSCM_ERROR_RAE_MASK16)
#define SSCM_ERROR_RAE_DISABLE_U16          ((uint16)0x0000U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            SSCM basic configuration
* @details          Configuration for SSCM hw IP.
*
*/
typedef struct
{
    /* SSCM configuration */
    VAR(uint16, AUTOMATIC) u16SscmError;
} Mcu_SSCM_ConfigType;

/**
* @brief            Return type for Mcu_SSCM_GetMemConfig.
*
*/
typedef uint32 Mcu_SSCM_MemConfigType;

#if (MCU_SSCM_GET_STATUS_API == STD_ON)
/**
* @brief            Return type for Mcu_SSCM_GetStatus.
*
*/
typedef uint16 Mcu_SSCM_StatusType;
#endif /* MCU_SSCM_GET_STATUS_API == STD_ON */

#ifdef MCU_SSCM_GET_UOPS_API
#if (MCU_SSCM_GET_UOPS_API == STD_ON)
/**
* @brief            Return type for Mcu_SSCM_GetUops.
*
*/
typedef uint32 Mcu_SSCM_UopsType;
#endif /* MCU_SSCM_GET_UOPS_API == STD_ON */
#endif /* MCU_SSCM_GET_UOPS_API */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_SSCM_TYPES_H */

/** @} */
