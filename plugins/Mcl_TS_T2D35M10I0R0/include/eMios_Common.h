/**
*   @file    eMios_Common.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - eTIMER driver header file.
*   @details eTIMER driver interface.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eDMA
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

#ifndef EMIOS_COMMON_H
#define EMIOS_COMMON_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section EMIOS_COMMON_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys_eMios.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @{
* @file           eMios_Common.h  
*/
#define EMIOS_COMMON_VENDOR_ID                       43
#define EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION        4
#define EMIOS_COMMON_AR_RELEASE_MINOR_VERSION        2
#define EMIOS_COMMON_AR_RELEASE_REVISION_VERSION     2
#define EMIOS_COMMON_SW_MAJOR_VERSION                1
#define EMIOS_COMMON_SW_MINOR_VERSION                0
#define EMIOS_COMMON_SW_PATCH_VERSION                0
/** @} */

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION != 4) || \
        (REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION != 2))
    #error "AutoSar Version Numbers of Reg_eSys_eMios.h and eMios_Common.h are different"
#endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define MCL_START_SEC_CODE
/** @violates @ref EMIOS_COMMON_H_REF_1 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"



#ifdef EMIOS_UCDIS_AVAILABLE
#if (EMIOS_UCDIS_AVAILABLE == STD_ON)
FUNC (void, MCL_CODE) eMios_StartChannel(VAR(uint8, AUTOMATIC) u8HwChannel);
FUNC (void, MCL_CODE) eMios_StopChannel(VAR(uint8, AUTOMATIC) u8HwChannel);
#endif  /* EMIOS_UCDIS_AVAILABLE */
#endif

#define MCL_STOP_SEC_CODE
/** @violates @ref EMIOS_COMMON_H_REF_1 Repeated include file */
#include "Mcl_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif /*ETIMER_COMMON_H*/

/** @} */
