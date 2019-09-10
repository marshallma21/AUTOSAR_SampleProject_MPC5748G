/**
*   @file    Mcu_eMios_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from eMios.
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

#ifndef MCU_EMIOS_TYPES_H
#define MCU_EMIOS_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_eMios_Types_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Mcu_eMios_Types_h_REF_2
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Mcu_Cfg.h"
#include "Mcu_Reg_eSys_eMios.h"

/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/
#define MCU_EMIOS_TYPES_VENDOR_ID                       43
#define MCU_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCU_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCU_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCU_EMIOS_TYPES_SW_MAJOR_VERSION                1
#define MCU_EMIOS_TYPES_SW_MINOR_VERSION                0
#define MCU_EMIOS_TYPES_SW_PATCH_VERSION                0

/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/
/* Check if source file and Mcu_Reg_eSys_eMios header file are from the same vendor */
#if (MCU_EMIOS_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_eMios_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Reg_eSys_eMios header file are of the same Autosar version */
#if ((MCU_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_eMios_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Reg_eSys_eMios header file are of the same Software version */
#if ((MCU_EMIOS_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_EMIOS_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_EMIOS_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_eMios_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and eMios header file are from the same vendor */
#if (MCU_EMIOS_TYPES_VENDOR_ID != MCU_REG_ESYS_EMIOS_VENDOR_ID)
    #error "Mcu_eMios_Types.h and Mcu_Reg_eSys_eMios.h have different vendor ids"
#endif
/* Check if source file and eMios header file are of the same Autosar version */
#if ((MCU_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION != MCU_REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION) || \
     (MCU_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION != MCU_REG_ESYS_EMIOS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_eMios_Types.h and Mcu_Reg_eSys_eMios.h are different"
#endif
/* Check if source file and eMios header file are of the same Software version */
#if ((MCU_EMIOS_TYPES_SW_MAJOR_VERSION != MCU_REG_ESYS_EMIOS_SW_MAJOR_VERSION) || \
     (MCU_EMIOS_TYPES_SW_MINOR_VERSION != MCU_REG_ESYS_EMIOS_SW_MINOR_VERSION) || \
     (MCU_EMIOS_TYPES_SW_PATCH_VERSION != MCU_REG_ESYS_EMIOS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_eMios_Types.h and Mcu_Reg_eSys_eMios.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/** @violates @ref Mcu_eMios_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.
  */
#define EMIOS_MCR_U32(value)                ((uint32)( ((value) & EMIOS_MCR_RWBITS_MASK32 ) | EMIOS_MCR_RESBITS_MASK32 ))

/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_MDIS_ENA_U32              (EMIOS_MCR_MDIS_MASK32)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_MDIS_DIS_U32              ((uint32)0x00000000U)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_FRZ_ENA_U32               (EMIOS_MCR_FRZ_MASK32)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_FRZ_DIS_U32               ((uint32)0x00000000U)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_GTBE_ENA_U32              (EMIOS_MCR_GTBE_MASK32)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_GTBE_DIS_U32              ((uint32)0x00000000U)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_ETB_ENA_U32               (EMIOS_MCR_ETB_MASK32)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_ETB_DIS_U32               ((uint32)0x00000000U)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_GPREN_ENA_U32             (EMIOS_MCR_GPREN_MASK32)
/** @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.*/
#define EMIOS_MCR_GPREN_DIS_U32             ((uint32)0x00000000U)

/** @violates @ref Mcu_eMios_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined. 
  * @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro
  */
#define EMIOS_MCR_SRV_U32(value)            ((uint32)(((value) << (uint32)16U) & EMIOS_MCR_SRV_MASK32))
/** @violates @ref Mcu_eMios_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref Mcu_eMios_Types_h_REF_2 This is not a standard library macro.
  */
#define EMIOS_MCR_GPRE_U32(value)           ((uint32)((((value) - (uint32)1U) << (uint32)8U) & EMIOS_MCR_GPRE_MASK32))

#ifdef EMIOS0_BASEADDR
#define MCU_EMIOS_MODULE_0                  ((uint8)0x00U)
#endif /* EMIOS0_BASEADDR */

#ifdef EMIOS1_BASEADDR
#define MCU_EMIOS_MODULE_1                  ((uint8)0x01U)
#endif /* EMIOS1_BASEADDR */

#ifdef EMIOS2_BASEADDR
#define MCU_EMIOS_MODULE_2                  ((uint8)0x02U)
#endif /* EMIOS2_BASEADDR */

#ifdef EMIOS3_BASEADDR
#define MCU_EMIOS_MODULE_3                  ((uint8)0x03U)
#endif /* EMIOS3_BASEADDR */

#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
#define MCU_EMIOS_GPREN_BIT_ENABLE          (0x01U)
#define MCU_EMIOS_GPREN_BIT_DISABLE         (0x00U)
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCU_EMIOS_SUPPORT == STD_ON)
/**
* @brief            EMIOS configuration.
*
*/
typedef struct
{
    VAR(uint32,  MCU_VAR) au32EmiosData[MCU_EMIOS_NB_MODULES];

} Mcu_eMios_ConfigType;
#endif

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* MCU_EMIOS_TYPES_H */
/** @} */
