/**
*   @file    Reg_eSys_FIRC.h
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


#ifndef REG_ESYS_FIRC_H
#define REG_ESYS_FIRC_H


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

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_FIRC_VENDOR_ID                       43
#define REG_ESYS_FIRC_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_FIRC_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_FIRC_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_FIRC_SW_MAJOR_VERSION                1
#define REG_ESYS_FIRC_SW_MINOR_VERSION                0
#define REG_ESYS_FIRC_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_FIRC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_FIRC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_FIRC.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Control register */
#define FIRC_CTL_ADDR32                                     ((uint32)(FIRC_BASEADDR + (uint32)0x0000U))


/***********************************************************/
/*                           FIRC_CTL                      */
/***********************************************************/
#define FIRC_CTL_RWBITS_MASK32                              ((uint32)0x00001F00U)
#define FIRC_CTL_RESBITS_MASK32                             ((uint32)0x00000011U)

#define FIRC_CTL_FIRCDIV_MASK32                             ((uint32)0x00001F00U)
#define FIRC_CTL_FIRCDIV_SHIFT32                            ((uint32)8U)

#define FIRC_CTL_FIRCS_MASK32                               ((uint32)0x00000010U)
#define FIRC_CTL_STDBY_MASK32                               ((uint32)0x00000001U)

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

#endif /* REG_ESYS_FIRC_H */

/** @} */
