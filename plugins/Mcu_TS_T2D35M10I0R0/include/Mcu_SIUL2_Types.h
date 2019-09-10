/**
*   @file    Mcu_SIUL2_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from AFE.
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


#ifndef MCU_SIUL2_TYPES_H
#define MCU_SIUL2_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
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
#include "Soc_Ips.h"
#include "Mcu_Reg_eSys_SIUL2.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_SIUL2_TYPES_VENDOR_ID                       43
#define MCU_SIUL2_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCU_SIUL2_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCU_SIUL2_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCU_SIUL2_TYPES_SW_MAJOR_VERSION                1
#define MCU_SIUL2_TYPES_SW_MINOR_VERSION                0
#define MCU_SIUL2_TYPES_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_SIUL2_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_SIUL2_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_SIUL2_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SIUL2_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SIUL2_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SIUL2_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_SIUL2_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_SIUL2_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_SIUL2_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SIUL2_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Mcu_Reg_eSys_SIUL2 header file are from the same vendor */
#if (MCU_SIUL2_TYPES_VENDOR_ID != MCU_REG_ESYS_SIUL2_VENDOR_ID)
    #error "Mcu_SIUL2_Types.h and Mcu_Reg_eSys_SIUL2.h have different vendor ids"
#endif
/* Check if source file and Mcu_Reg_eSys_SIUL2 header file are of the same Autosar version */
#if ((MCU_SIUL2_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_REG_ESYS_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SIUL2_TYPES_AR_RELEASE_MINOR_VERSION != MCU_REG_ESYS_SIUL2_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SIUL2_TYPES_AR_RELEASE_REVISION_VERSION != MCU_REG_ESYS_SIUL2_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SIUL2_Types.h and Mcu_Reg_eSys_SIUL2.h are different"
#endif
/* Check if source file and Mcu_Reg_eSys_SIUL2 header file are of the same Software version */
#if ((MCU_SIUL2_TYPES_SW_MAJOR_VERSION != MCU_REG_ESYS_SIUL2_SW_MAJOR_VERSION) || \
     (MCU_SIUL2_TYPES_SW_MINOR_VERSION != MCU_REG_ESYS_SIUL2_SW_MINOR_VERSION) || \
     (MCU_SIUL2_TYPES_SW_PATCH_VERSION != MCU_REG_ESYS_SIUL2_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SIUL2_Types.h and Mcu_Reg_eSys_SIUL2.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SIUL2_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SIUL2_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SIUL2_Types.h and Soc_Ips.h are different"
    #endif
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief            MIDR configuration
*
*/
typedef struct
{
    VAR(uint32, AUTOMATIC) u32Midr1;   /**< @brief SIUL2_MIDR1 Configuration register. */
    VAR(uint32, AUTOMATIC) u32Midr2;   /**< @brief SIUL2_MIDR2 Configuration register. */
} Mcu_MidrReturnType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_SIUL2_TYPES_H */

/** @} */
