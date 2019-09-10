/**
*   @file    Mcl_Axbs.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - Axbs Low level driver header file.
*   @details Axbs module low level driver.
*
*   @addtogroup MCL
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

#ifndef MCL_AXBS_H
#define MCL_AXBS_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_AXBS_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Mcl_AXBS_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Mcl_IPW_Types.h"
#include "Mcl_Axbs_Types.h"
#include "Reg_eSys_Axbs.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_Axbs.h
*/
#define MCL_AXBS_VENDOR_ID                      43
#define MCL_AXBS_AR_RELEASE_MAJOR_VERSION       4
#define MCL_AXBS_AR_RELEASE_MINOR_VERSION       2
#define MCL_AXBS_AR_RELEASE_REVISION_VERSION    2
#define MCL_AXBS_SW_MAJOR_VERSION               1
#define MCL_AXBS_SW_MINOR_VERSION               0
#define MCL_AXBS_SW_PATCH_VERSION               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (MCL_AXBS_VENDOR_ID != AXBS_REG_VENDOR_ID)
    #error "Mcl_Axbs.h and Reg_eSys_Axbs.h have different vendor IDs"
#endif
/* Check if Mcl_Dma header file and Reg_eSys are of the same Autosar version */
#if ((MCL_AXBS_AR_RELEASE_MAJOR_VERSION != AXBS_REG_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AXBS_AR_RELEASE_MINOR_VERSION != AXBS_REG_AR_RELEASE_MINOR_VERSION) || \
     (MCL_AXBS_AR_RELEASE_REVISION_VERSION != AXBS_REG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Axbs.h and Reg_eSys_Axbs.h are different"
#endif
/* Check if Mcl_Dma header file and Reg_eSys are of the same Software version */
#if ((MCL_AXBS_SW_MAJOR_VERSION != AXBS_REG_SW_MAJOR_VERSION) || \
     (MCL_AXBS_SW_MINOR_VERSION != AXBS_REG_SW_MINOR_VERSION) || \
     (MCL_AXBS_SW_PATCH_VERSION != AXBS_REG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Axbs.h and Reg_eSys_Axbs.h are different"
#endif

/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_AXBS_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_AXBS_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Mcl_Axbs.h and Std_Types.h are different"
    #endif
#endif

/* Check if header file and Mcl_Axbs_Types.h header file are of the same vendor */
#if (MCL_AXBS_VENDOR_ID != MCL_AXBS_TYPES_VENDOR_ID)
    #error "Mcl_Axbs.h and Mcl_Axbs_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_Axbs_Types.h header file are of the same Autosar version */
#if ((MCL_AXBS_AR_RELEASE_MAJOR_VERSION    != MCL_AXBS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AXBS_AR_RELEASE_MINOR_VERSION    != MCL_AXBS_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_AXBS_AR_RELEASE_REVISION_VERSION != MCL_AXBS_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Axbs.h and Mcl_Axbs_Types.h are different"
#endif
/* Check if header file and Mcl_Axbs_Types.h header file are of the same software version */
#if ((MCL_AXBS_SW_MAJOR_VERSION != MCL_AXBS_TYPES_SW_MAJOR_VERSION) || \
     (MCL_AXBS_SW_MINOR_VERSION != MCL_AXBS_TYPES_SW_MINOR_VERSION) || \
     (MCL_AXBS_SW_PATCH_VERSION != MCL_AXBS_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Axbs.h and Mcl_Axbs_Types.h are different"
#endif

/* Check if header file and Mcl_IPW_Types.h header file are of the same vendor */
#if (MCL_AXBS_VENDOR_ID != MCL_IPW_TYPES_VENDOR_ID)
    #error "Mcl_Axbs.h and Mcl_IPW_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_IPW_Types.h header file are of the same Autosar version */
#if ((MCL_AXBS_AR_RELEASE_MAJOR_VERSION    != MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AXBS_AR_RELEASE_MINOR_VERSION    != MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_AXBS_AR_RELEASE_REVISION_VERSION != MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Axbs.h and Mcl_IPW_Types.h are different"
#endif
/* Check if header file and Mcl_IPW_Types.h header file are of the same software version */
#if ((MCL_AXBS_SW_MAJOR_VERSION != MCL_IPW_TYPES_SW_MAJOR_VERSION) || \
     (MCL_AXBS_SW_MINOR_VERSION != MCL_IPW_TYPES_SW_MINOR_VERSION) || \
     (MCL_AXBS_SW_PATCH_VERSION != MCL_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Axbs.h and Mcl_IPW_Types.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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
#define MCL_START_SEC_CODE
/** @violates @ref Mcl_AXBS_h_REF_1 MISRA 2004 Advisory Rule 19.15, header file being included twice */
#include "Mcl_MemMap.h"
    
FUNC(void, MCL_CODE) Axbs_Init( P2CONST(Mcl_CrossbarConfigType, AUTOMATIC, MCL_APPL_CONST) pAxbsConfig);           
#if (MCL_DEINIT_API == STD_ON)
FUNC(void, MCL_CODE) Axbs_DeInit( P2CONST(Mcl_CrossbarConfigType, AUTOMATIC, MCL_APPL_CONST) pAxbsConfig); 
#endif                                               
#define MCL_STOP_SEC_CODE
/** @violates @ref Mcl_AXBS_h_REF_1 MISRA 2004 Advisory Rule 19.15, header file being included twice */
#include "Mcl_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* MCL_AXBS_H */

/** @} */
