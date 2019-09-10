/**
 *     @file    Icu_Reg_eSys_WKPU.h
 *     @version 1.0.0
 * 
 *     @brief   AUTOSAR Icu - WKPU header file support for ICU driver.
 *     @details WKPU header file, containing the variables and functions that are exported by the WKPU driver.
 * 
 *     @addtogroup ICU_MODULE
 *     @{
*/
/*==================================================================================================
 *     Project             : AUTOSAR 4.2 MCAL
 *     Platform            : PA
 *     Peripheral          : eMIOS SIUL2 WKPU
 *     Dependencies        : none
 * 
 *     Autosar Version     : 4.2.2
 *     Autosar Revision    : ASR_REL_4_2_REV_0002
 *     Autosar ConfVariant : 
 *     SWVersion           : 1.0.0
 *     BuildVersion        : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217
 * 
 *     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
 *     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef ICU_REG_ESYS_WKPU_H
#define ICU_REG_ESYS_WKPU_H

#ifdef __cplusplus
extern "C" {
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Reg_eSys_Wkpu_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* @violates @ref Icu_Reg_eSys_Wkpu_h_1 precautions to prevent the contents
 * of a header file being included twice */
#include "Reg_eSys.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_REG_ESYS_WKPU_VENDOR_ID                      43

#define ICU_REG_ESYS_WKPU_AR_RELEASE_MAJOR_VERSION       4
#define ICU_REG_ESYS_WKPU_AR_RELEASE_MINOR_VERSION       2
#define ICU_REG_ESYS_WKPU_AR_RELEASE_REVISION_VERSION    2

#define ICU_REG_ESYS_WKPU_SW_MAJOR_VERSION      1
#define ICU_REG_ESYS_WKPU_SW_MINOR_VERSION      0
#define ICU_REG_ESYS_WKPU_SW_PATCH_VERSION      0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Icu_Reg_eSys_Wkpu header file are of the same vendor */
#if (ICU_REG_ESYS_WKPU_VENDOR_ID != REG_ESYS_VENDOR_ID)
    #error "Icu_Reg_eSys_Wkpu.h and Reg_eSys.h have different vendor IDs"
#endif
/* Check if header file and Icu_Reg_eSys_Wkpu header file are of the same Autosar version */
#if ((ICU_REG_ESYS_WKPU_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_REG_ESYS_WKPU_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) || \
     (ICU_REG_ESYS_WKPU_AR_RELEASE_REVISION_VERSION != REG_ESYS_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Reg_eSys_Wkpu.h and Reg_eSys.h are different"
#endif
/* Check if header file and Icu_Reg_eSys_Wkpu header file are of the same software version */
#if ((ICU_REG_ESYS_WKPU_SW_MAJOR_VERSION != REG_ESYS_SW_MAJOR_VERSION) || \
     (ICU_REG_ESYS_WKPU_SW_MINOR_VERSION != REG_ESYS_SW_MINOR_VERSION) || \
     (ICU_REG_ESYS_WKPU_SW_PATCH_VERSION != REG_ESYS_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Reg_eSys_Wkpu.h and Reg_eSys.h are different"
#endif
/*==================================================================================================
                                DEFINES AND MACROS
==================================================================================================*/
/**
*@brief Wakeup Register Defintions
*@{
*/

#define ICU_WKPU_WISR_ADDR32           (WKPU_BASEADDR + 0x14UL)
#define ICU_WKPU_IRER_ADDR32           (WKPU_BASEADDR + (uint32)0x18UL)
#define ICU_WKPU_WRER_ADDR32           (WKPU_BASEADDR + (uint32)0x1CUL)
#define ICU_WKPU_WIREER_ADDR32         (WKPU_BASEADDR + (uint32)0x28UL)
#define ICU_WKPU_WIFEER_ADDR32         (WKPU_BASEADDR + 0x2CUL)
#define ICU_WKPU_WIFER_ADDR32          (WKPU_BASEADDR + 0x30UL)
#define ICU_WKPU_WIPUER_ADDR32         (WKPU_BASEADDR + 0x34UL)
/**@}*/


#ifdef __cplusplus
}
#endif

#endif  /* ICU_REG_ESYS_WKPU_H */
/**@}*/
