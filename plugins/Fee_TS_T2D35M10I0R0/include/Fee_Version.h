/**
*   @file    Fee_Version.h
*   @implements Fee_Version.h_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Fee - Version Information.
*   @details Flash EEPROM emulation driver version information.
*
*   @addtogroup FEE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : none
*   Dependencies         : Fls
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

#ifndef FEE_VERSION_H 
#define FEE_VERSION_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fee_Version_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
* @section Fee_Version_h_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not rely on the 
* significance of more than 31 characters.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
*/


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FEE_AR_RELEASE_MAJOR_VERSION     4
#define FEE_AR_RELEASE_MINOR_VERSION     2
/* @violates @ref Fee_Version_h_REF_1 Identifier clash */
/* @violates @ref Fee_Version_h_REF_2 Identifiers shall not rely*/
#define FEE_AR_RELEASE_REVISION_VERSION  2
#define FEE_SW_MAJOR_VERSION             1
#define FEE_SW_MINOR_VERSION             0
#define FEE_SW_PATCH_VERSION             0

#ifdef __cplusplus
}
#endif

#endif /* FEE_VERSION_H */
/** @} */
