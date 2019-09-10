/**
*   @file    Reg_eSys_STCU.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Macros for memory access.
*   @details Macros/Defines used for registry and memory read/write.
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


#ifndef REG_ESYS_STCU_H
#define REG_ESYS_STCU_H

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
#include "Reg_eSys.h"
#include "Mcu_STCU_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_STCU_VENDOR_ID                      43
#define REG_ESYS_STCU_AR_RELEASE_MAJOR_VERSION       4
#define REG_ESYS_STCU_AR_RELEASE_MINOR_VERSION       2
#define REG_ESYS_STCU_AR_RELEASE_REVISION_VERSION    2
#define REG_ESYS_STCU_SW_MAJOR_VERSION               1
#define REG_ESYS_STCU_SW_MINOR_VERSION               0
#define REG_ESYS_STCU_SW_PATCH_VERSION               0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_STCU_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_STCU_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_STCU.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_STCU_IPVersion header file are from the same vendor */
#if (REG_ESYS_STCU_VENDOR_ID != MCU_STCU_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_STCU.h and Mcu_STCU_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_STCU_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_STCU_AR_RELEASE_MAJOR_VERSION != MCU_STCU_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_STCU_AR_RELEASE_MINOR_VERSION != MCU_STCU_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_STCU_AR_RELEASE_REVISION_VERSION != MCU_STCU_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_STCU.h and Mcu_STCU_IPVersion.h are different"
#endif
/* Check if source file and Mcu_STCU_IPVersion header file are of the same Software version */
#if ((REG_ESYS_STCU_SW_MAJOR_VERSION != MCU_STCU_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_STCU_SW_MINOR_VERSION != MCU_STCU_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_STCU_SW_PATCH_VERSION != MCU_STCU_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_STCU.h and Mcu_STCU_IPVersion.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
/* STCU_SKC: STCU SK Code Register. */
#define STCU_MBSL_ADDR32                 ((uint32)(STCU_BASEADDR+(uint32)0x0044UL))

#if ((IPV_STCU2 == IPV_STCU2_01_00_61_00) || (IPV_STCU2 == IPV_STCU2_01_00_61_01))
#define STCU_MBEL_ADDR32                 ((uint32)(STCU_BASEADDR+(uint32)0x0050UL))
#elif (IPV_STCU2 == IPV_STCU2_01_00_61_04)
#define STCU_MBEL_ADDR32                 ((uint32)(STCU_BASEADDR+(uint32)0x0084UL))
#endif

/* STCU_MBSL mask */
#define STCU_MBSL_RAM_TEST_MASK32       ((uint32)0x000000FCUL)

/* STCU_MBEL mask */
#define STCU_MBEL_RAM_TEST_MASK32       ((uint32)0x000000FCUL)

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_STCU_H */

/** @} */

