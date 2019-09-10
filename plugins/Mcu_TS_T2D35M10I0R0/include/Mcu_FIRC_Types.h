/**
*   @file    Mcu_FIRC_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from SRC.
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


#ifndef MCU_FIRC_TYPES_H
#define MCU_FIRC_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section MCU_FIRC_TYPES_h_REF_1
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
#include "Reg_eSys_FIRC.h"
#include "Soc_Ips.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_FIRC_TYPES_VENDOR_ID                     43
#define MCU_FIRC_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define MCU_FIRC_TYPES_AR_RELEASE_MINOR_VERSION      2
#define MCU_FIRC_TYPES_AR_RELEASE_REVISION_VERSION   2
#define MCU_FIRC_TYPES_SW_MAJOR_VERSION              1
#define MCU_FIRC_TYPES_SW_MINOR_VERSION              0
#define MCU_FIRC_TYPES_SW_PATCH_VERSION              0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and PLLDIG header file are from the same vendor */
#if (MCU_FIRC_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_FIRC_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((MCU_FIRC_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FIRC_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FIRC_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FIRC_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((MCU_FIRC_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_FIRC_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_FIRC_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FIRC_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Reg_eSys_FIRC header file are from the same vendor */
#if (MCU_FIRC_TYPES_VENDOR_ID != REG_ESYS_FIRC_VENDOR_ID)
    #error "Mcu_FIRC_Types.h and Reg_eSys_FIRC.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_FIRC header file are of the same Autosar version */
#if ((MCU_FIRC_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_FIRC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FIRC_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_FIRC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FIRC_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_FIRC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FIRC_Types.h and Reg_eSys_FIRC.h are different"
#endif
/* Check if source file and Reg_eSys_FIRC header file are of the same Software version */
#if ((MCU_FIRC_TYPES_SW_MAJOR_VERSION != REG_ESYS_FIRC_SW_MAJOR_VERSION) || \
     (MCU_FIRC_TYPES_SW_MINOR_VERSION != REG_ESYS_FIRC_SW_MINOR_VERSION) || \
     (MCU_FIRC_TYPES_SW_PATCH_VERSION != REG_ESYS_FIRC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FIRC_Types.h and Reg_eSys_FIRC.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_FIRC_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_FIRC_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_FIRC_Types.h and Soc_Ips.h are different"
    #endif
#endif


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/** @violates @ref MCU_FIRC_TYPES_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define FIRC_CTL_FIRCDIV_VALUE_U32(value)               ((uint32)( ( (value) << FIRC_CTL_FIRCDIV_SHIFT32 ) & FIRC_CTL_FIRCDIV_MASK32 ))

/** @violates @ref MCU_FIRC_TYPES_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define FIRC_CTL_VALUE_U32(value)                       ((uint32)( ( (value) & FIRC_CTL_RWBITS_MASK32 ) | FIRC_CTL_RESBITS_MASK32 ))

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief            Describes the FIRC clock status
* @details          Describes the FIRC clock status
*/
typedef enum
{
    MCU_FIRC_NOT_STABLE = 0x00U,    /**< @brief FIRC is not providing a stable clock. */
    MCU_FIRC_STABLE = 0x01U         /**< @brief FIRC is providing a stable clock. */

} Mcu_FIRC_ClockStatusType;

/**
* @brief            Low power RC control in Standby mode
* @details          Low power RC control in Standby mode
*/
typedef enum
{
    MCU_FIRC_IS_OFF = 0x00U,        /**< @brief FIRC is switched off. */
    MCU_FIRC_IS_ON = 0x01U          /**< @brief FIRC is switched on. */

} Mcu_FIRC_StandbyStatusType;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief            Configuration of FIRC hw IP
* @details          This data configuration is set at module initialization phase.
*/
typedef struct
{
    /* Control register */
    VAR( uint32, MCU_VAR) u32FircCtl;
} Mcu_FIRC_ConfigType;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_FIRC_TYPES_H */

/** @} */
