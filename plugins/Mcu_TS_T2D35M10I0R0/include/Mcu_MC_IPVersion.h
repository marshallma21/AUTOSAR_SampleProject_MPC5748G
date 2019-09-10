/**
*   @file    Mcu_MC_IPVersion.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Platform version definitions, used inside IPV_MC.
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

#ifndef MCU_MC_IPVERSION_H
#define MCU_MC_IPVERSION_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_MC_IPVERSION_VENDOR_ID                       43
#define MCU_MC_IPVERSION_AR_RELEASE_MAJOR_VERSION        4
#define MCU_MC_IPVERSION_AR_RELEASE_MINOR_VERSION        2
#define MCU_MC_IPVERSION_AR_RELEASE_REVISION_VERSION     2
#define MCU_MC_IPVERSION_SW_MAJOR_VERSION                1
#define MCU_MC_IPVERSION_SW_MINOR_VERSION                0
#define MCU_MC_IPVERSION_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define IPV_MC_04_03_00_00      (0x04030000UL)
#define IPV_MC_04_04_01_00      (0x04040100UL)
#define IPV_MC_04_00_15_15      (0x04001515UL)
#define IPV_MC_04_01_00_00      (0x04010000UL)
#define IPV_MC_04_06_01_00      (0x04060100UL)
#define IPV_MC_04_06_05_00      (0x04060500UL)
#define IPV_MC_05_00_00_10      (0x05000010UL)
#define IPV_MC_05_00_00_07      (0x05000007UL)
#define IPV_MC_06_00_00_10      (0x06000010UL)


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

#endif /* MCU_MC_IPVERSION_H */
