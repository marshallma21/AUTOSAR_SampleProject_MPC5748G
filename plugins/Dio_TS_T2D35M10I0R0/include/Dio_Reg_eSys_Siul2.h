/**
*   @file Dio_Reg_eSys_Siul2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Dio - SIUL2 low level driver register defines.
*   @details The description of the registers of the SIUL2 module.
*
*   @addtogroup DIO_SIUL2
*   @{
*/
/*=================================================================================================
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef DIO_REG_ESYS_SIUL2_H
#define DIO_REG_ESYS_SIUL2_H
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Dio_Reg_eSys_SIUL2_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.

*/


/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Reg_eSys.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define DIO_REGESYS_SIUL2_VENDOR_ID_REG                    43
#define DIO_REGESYS_SIUL2_AR_RELEASE_MAJOR_VERSION_REG     4
#define DIO_REGESYS_SIUL2_AR_RELEASE_MINOR_VERSION_REG     2
#define DIO_REGESYS_SIUL2_AR_RELEASE_REVISION_VERSION_REG  2
#define DIO_REGESYS_SIUL2_SW_MAJOR_VERSION_REG             1
#define DIO_REGESYS_SIUL2_SW_MINOR_VERSION_REG             0
#define DIO_REGESYS_SIUL2_SW_PATCH_VERSION_REG             0


/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Reg_eSys.h version check start */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((DIO_REGESYS_SIUL2_AR_RELEASE_MAJOR_VERSION_REG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (DIO_REGESYS_SIUL2_AR_RELEASE_MINOR_VERSION_REG != REG_ESYS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Dio_Reg_eSys_Siul2.h and Reg_eSys.h are different"
    #endif
#endif
/* Reg_eSys.h version check end */


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*=================================================================================================
*                               DEFINES AND MACROS
=================================================================================================*/

/* @brief Offset of GPDO Pad Data Output Registers from SIUL2_BASEADDR*/
#define  SIUL2_GPDO_OFFSET_U32          ((uint32)0x1300UL)

/* @brief Offset of GPDI Pad Data Output Registers from SIUL2_BASEADDR*/
#define  SIUL2_GPDI_OFFSET_U32          ((uint32)0x1500UL)

/* @brief Offset of PGPDO Parallel GPIO Pad Data Output Registers from SIUL2_BASEADDR*/
#define  SIUL2_PGPDO_OFFSET_U32         ((uint32)0x1700UL)

/* @brief Offset of PGPDI Parallel GPIO Pad Data Input Registers from SIUL2_BASEADDR*/
#define  SIUL2_PGPDI_OFFSET_U32         ((uint32)0x1740UL)

/* @brief Offset of MPGPDO Masked Parallel GPIO Pad Data Output Registers from SIUL2_BASEADDR*/
#define  SIUL2_MPGPDO_OFFSET_U32        ((uint32)0x1780UL)

/*
* @brief GPIO Pad Data Output Register address
*/
#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
    /* On ARM platforms, endianess is LOW_BYTE_FIRST. Need to revert the GPDO register order */
    /*
    * @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined
    */
    #define SIUL2_GPDO_ADDR32(PIN)  (SIUL2_BASEADDR + SIUL2_GPDO_OFFSET_U32 + (((PIN) & ~3UL) | (~((PIN) & 3UL) & 3UL)))
#else
    /*
    * @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined
    */
    #define SIUL2_GPDO_ADDR32(PIN)  (SIUL2_BASEADDR + SIUL2_GPDO_OFFSET_U32 + (PIN))
#endif

/* @brief GPIO Pad Data Output Register 0 */
#define SIUL2_GPDO_PDO_0_U32           ((uint32)0x01000000UL)

/* @brief GPIO Pad Data Output Register 1 */
#define SIUL2_GPDO_PDO_1_U32           ((uint32)0x00010000UL)

/* @brief GPIO Pad Data Output Register 2 */
#define SIUL2_GPDO_PDO_2_U32           ((uint32)0x00000100UL)

/* @brief GPIO Pad Data Output Register 3 */
#define SIUL2_GPDO_PDO_3_U32           ((uint32)0x00000001UL)

/*
* @brief GPIO Pad Data Input Register address
*/
#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
    /* On ARM platforms, endianess is LOW_BYTE_FIRST. Need to revert the GPDO register order */
    /*
    * @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined
    */
    #define SIUL2_GPDI_ADDR32(PIN)  (SIUL2_BASEADDR + SIUL2_GPDI_OFFSET_U32 + (((PIN) & ~3UL) | (~((PIN) & 3UL) & 3UL)))
#else
    /*
    * @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined
    */
    #define SIUL2_GPDI_ADDR32(PIN)  (SIUL2_BASEADDR + SIUL2_GPDI_OFFSET_U32 + (PIN))
#endif

/* @brief GPIO Pad Data Input Register 0 */
#define SIUL2_GPDI_PDI_0_U32           ((uint32)0x01000000UL)

/* @brief GPIO Pad Data Input Register 1 */
#define SIUL2_GPDI_PDI_1_U32           ((uint32)0x00010000UL)

/* @brief GPIO Pad Data Input Register 2 */
#define SIUL2_GPDI_PDI_2_U32           ((uint32)0x00000100UL)

/* @brief GPIO Pad Data Input Register 3 */
#define SIUL2_GPDI_PDI_3_U32           ((uint32)0x00000001UL)

/*
* @brief Parallel GPIO Pad Data Output Register address
*/
#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
    /* On ARM platforms, endianess is LOW_BYTE_FIRST. Need to revert the GPDO register order */
    /* @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined. */
    #define SIUL2_PGPDO_ADDR32(PGPDO_INDEX)  (SIUL2_BASEADDR + SIUL2_PGPDO_OFFSET_U32                                            + \
              (uint32)((uint32)((uint32)((uint32)((uint32)((PGPDO_INDEX)/2)+1)*2) - (uint32)((uint32)((PGPDO_INDEX)%2)+1)) << 1U)  \
                                             )
#else
    /* @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined. */
    #define SIUL2_PGPDO_ADDR32(PGPDO_INDEX)  (SIUL2_BASEADDR + SIUL2_PGPDO_OFFSET_U32 + (((PGPDO_INDEX) << 1U)))
#endif

/*
* @brief Parallel GPIO Pad Data Input Register address
*/
#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
    /* On ARM platforms, endianess is LOW_BYTE_FIRST. Need to revert the GPDO register order */
    /* @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined. */
#define SIUL2_PGPDI_ADDR32(PGPDI_INDEX)     (SIUL2_BASEADDR + SIUL2_PGPDI_OFFSET_U32                                             + \
              (uint32)((uint32)((uint32)((uint32)((uint32)((PGPDI_INDEX)/2)+1)*2) - (uint32)((uint32)((PGPDI_INDEX)%2)+1)) << 1U)  \
                                            )
#else
    /* @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined. */
    #define SIUL2_PGPDI_ADDR32(PGPDI_INDEX) (SIUL2_BASEADDR + SIUL2_PGPDI_OFFSET_U32 + (((PGPDI_INDEX) << 1U)))
  
#endif

/*
* @brief  Masked Parallel GPIO Pad Data Output Register address
*/
/*
* @violates @ref Dio_Reg_eSys_SIUL2_H_REF_1 Function-like macro defined
*/
#define SIUL2_MPGPDO_ADDR32(MPGPDO_INDEX)   (SIUL2_BASEADDR+SIUL2_MPGPDO_OFFSET_U32+(MPGPDO_INDEX))

/* @brief  Masked Parallel GPIO Pad Data Output Register(Mask Field) */
#define SIUL2_MPGPDO_MASK_U32               ((uint32)0xFFFF0000UL)

/* @brief  Masked Parallel Pad Data Out */
#define SIUL2_MPGPDO_MPPDO_U32              ((uint32)0x0000FFFFUL)


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
/* DIO_REG_ESYS_SIUL2_H */
#endif
/** @} */
