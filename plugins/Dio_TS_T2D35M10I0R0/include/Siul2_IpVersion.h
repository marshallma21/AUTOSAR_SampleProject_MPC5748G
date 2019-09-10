/**
*   @file Siul2_IpVersion.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Dio - SIUL2 low level driver register defines.
*   @details The description of the registers of the SIUL2 module.
*
*   @addtogroup SIUL2
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : SIUL2
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

#ifndef SIUL2_IPVERSION_H
#define SIUL2_IPVERSION_H
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Siul2_IpVersion_h_REF_1
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance 
* and case sensitivity are supported for external identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define SIUL2_IPVERSION_VENDOR_ID_REG                    43
#define SIUL2_IPVERSION_AR_RELEASE_MAJOR_VERSION_REG     4
#define SIUL2_IPVERSION_AR_RELEASE_MINOR_VERSION_REG     2
#define SIUL2_IPVERSION_AR_RELEASE_REVISION_VERSION_REG  2
#define SIUL2_IPVERSION_SW_MAJOR_VERSION_REG             1
#define SIUL2_IPVERSION_SW_MINOR_VERSION_REG             0
#define SIUL2_IPVERSION_SW_PATCH_VERSION_REG             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/** @violates @ref Siul2_IpVersion_h_REF_1 The used compilers use more than 31 chars for identifiers. */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((SIUL2_IPVERSION_AR_RELEASE_MAJOR_VERSION_REG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (SIUL2_IPVERSION_AR_RELEASE_MINOR_VERSION_REG != REG_ESYS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Siul2_IpVersion.h and Reg_eSys.h are different"
    #endif
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

#ifdef IPV_SIULV2 
/* @brief IP version siulv2.00.01.00.71 (SIUL2 v1.0.q)  - McKinley Cut1 */
    #define IPV_SIULV2_00_01_00_71    (0x00010071UL)
/* @brief IP version siulv2.00.01.01.65  (SIUL2 v1.1.e) - Panther */
    #define IPV_SIULV2_00_01_01_65    (0x00010165UL)
/* @brief IP version siulv2.00.01.02.6A (SIUL2 v1.2.j)  - Racerunner Cut 1.1 */
    #define IPV_SIULV2_00_01_02_6A    (0x0001026AUL)
/* @brief IP version siulv2.00.01.03.63 (SIUL2 v1.3.c)  - Matterhorn Cut2, Halo, Calypso */
    #define IPV_SIULV2_00_01_03_63    (0x00010363UL)
/* @brief IP version siulv2.00.01.03.61 (SIUL2 v1.3.a)  - Rainier */
    #define IPV_SIULV2_00_01_03_61    (0x00010361UL)
#endif

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
/* SIUL2_IPVERSION_H */
#endif
/** @} */
