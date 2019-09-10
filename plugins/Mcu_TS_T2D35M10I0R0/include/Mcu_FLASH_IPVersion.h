/**
*   @file    Mcu_FLASH_IPVersion.h
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

#ifndef MCU_FLASH_IPVERSION_H
#define MCU_FLASH_IPVERSION_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_FLASH_IPVersion_h_REF_1
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

#define MCU_FLASH_IPVERSION_VENDOR_ID                       43
/** @violates @ref Mcu_FLASH_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_FLASH_IPVERSION_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref Mcu_FLASH_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_FLASH_IPVERSION_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref Mcu_FLASH_IPVersion_h_REF_1 The compiler/linker shall be checked ... */
#define MCU_FLASH_IPVERSION_AR_RELEASE_REVISION_VERSION     2
#define MCU_FLASH_IPVERSION_SW_MAJOR_VERSION                1
#define MCU_FLASH_IPVERSION_SW_MINOR_VERSION                0
#define MCU_FLASH_IPVERSION_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define IPV_FLASH_00_00_05_01       (0x00000501UL)
#define IPV_FLASH_40_96_55_19       (0x40965519UL)
#define IPV_FLASH_25_60_86_00       (0x25608600UL)
#define IPV_FLASH_01_00_08_02       (0x01000802UL)
#define IPV_FLASH_01_00_03_05       (0x01000305UL)
#define IPV_FLASH_42_56_55_38       (0x42565538UL)
#define IPV_FLASH_62_72_55_39       (0x62725539UL)
#define IPV_FLASH_84_80_32_02       (0x84803202UL)
#define IPV_FLASH_20_48_55_46       (0x20485546UL)
#define IPV_FLASH_40_96_55_46       (0x40965546UL)
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

#endif /* MCU_FLASH_IPVERSION_H */
