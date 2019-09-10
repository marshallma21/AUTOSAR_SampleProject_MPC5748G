/**
*   @file    Icu_eMios_Irq.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS SIUL2 WKPU
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

#ifndef ICU_EMIOS_IRQ_H
#define ICU_EMIOS_IRQ_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section ICU_EMIOS_IRQ_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars
* for identifiers.
*/

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_eMios_Types.h"
/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/


#define ICU_EMIOS_IRQ_VENDOR_ID                       43
#define ICU_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION        4
#define ICU_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION        2
#define ICU_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION     2
#define ICU_EMIOS_IRQ_SW_MAJOR_VERSION                1
#define ICU_EMIOS_IRQ_SW_MINOR_VERSION                0
#define ICU_EMIOS_IRQ_SW_PATCH_VERSION                0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if Icu_eMios_Irq.h file and  Icu_eMios_Types header file are of the same vendor */
#if (ICU_EMIOS_IRQ_VENDOR_ID != ICU_EMIOS_TYPES_VENDOR_ID)
    #error "Icu_eMios_Irq.h and Icu_eMios_Types.h have different vendor IDs"
#endif

#if ((ICU_EMIOS_IRQ_AR_RELEASE_MAJOR_VERSION != ICU_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_EMIOS_IRQ_AR_RELEASE_MINOR_VERSION != ICU_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_EMIOS_IRQ_AR_RELEASE_REVISION_VERSION != ICU_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_eMios_Irq.h and Icu_eMios_Types.h are different"
#endif

/*Check if Icu_eTimer_Irq.h file and Icu_eTimer_Types header file are of the same Software version*/
#if ((ICU_EMIOS_IRQ_SW_MAJOR_VERSION != ICU_EMIOS_TYPES_SW_MAJOR_VERSION) || \
     (ICU_EMIOS_IRQ_SW_MINOR_VERSION != ICU_EMIOS_TYPES_SW_MINOR_VERSION) || \
     (ICU_EMIOS_IRQ_SW_PATCH_VERSION != ICU_EMIOS_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_eMios_Irq.h and Icu_eMios_Types.h are different"
#endif
/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/** @violates @ref ICU_EMIOS_IRQ_H_REF_1 precautions to prevent the contents of a header
file being included twice  */
#include "Icu_MemMap.h"

FUNC (void, ICU_CODE) Icu_eMios_ProcessCommonInterrupt
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
);

#define ICU_STOP_SEC_CODE
/** @violates @ref ICU_EMIOS_IRQ_H_REF_1 precautions to prevent the contents of a header
file being included twice */
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_EMIOS_IRQ_H */

/** @} */
