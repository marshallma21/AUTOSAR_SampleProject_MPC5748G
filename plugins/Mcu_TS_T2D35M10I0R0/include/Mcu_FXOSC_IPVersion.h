/**
*   @file    Mcu_FXOSC_IPVersion.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Platform version definitions, used inside IPV_FXOSC.
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

#ifndef Mcu_FXOSC_IPVERSION_H
#define Mcu_FXOSC_IPVERSION_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_FXOSC_IPVersion_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
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
/* none */

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_FXOSC_IPVERSION_VENDOR_ID                       43
/** @violates @ref Mcu_FXOSC_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_FXOSC_IPVERSION_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref Mcu_FXOSC_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_FXOSC_IPVERSION_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref Mcu_FXOSC_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_FXOSC_IPVERSION_AR_RELEASE_REVISION_VERSION     2
#define MCU_FXOSC_IPVERSION_SW_MAJOR_VERSION                1
#define MCU_FXOSC_IPVERSION_SW_MINOR_VERSION                0
#define MCU_FXOSC_IPVERSION_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define IPV_FXOSC_00_00_00_05        (0x00000005UL)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* Mcu_FXOSC_IPVERSION_H */
