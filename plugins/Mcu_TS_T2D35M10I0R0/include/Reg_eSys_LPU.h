/**
*   @file    Reg_eSys_LPU.h
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


#ifndef REG_ESYS_LPU_H
#define REG_ESYS_LPU_H


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

#define REG_ESYS_LPU_VENDOR_ID                       43
#define REG_ESYS_LPU_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_LPU_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_LPU_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_LPU_SW_MAJOR_VERSION                1
#define REG_ESYS_LPU_SW_MINOR_VERSION                0
#define REG_ESYS_LPU_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_LPU_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_LPU_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_LPU.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* LPU Mode Control Register */
#define LPU_MCTL_ADDR32                                     ((uint32)(LPU_BASEADDR + (uint32)0x0000U))

/* LPU Run Configuration Register */
#define LPU_RUN_CF_ADDR32                                   ((uint32)(LPU_BASEADDR + (uint32)0x0004U))

/* LPU Stop Configuration Register */
#define LPU_STOP_CF_ADDR32                                  ((uint32)(LPU_BASEADDR + (uint32)0x0008U))

/* LPU Standby Configuration Register */
#define LPU_STANDBY_CF_ADDR32                               ((uint32)(LPU_BASEADDR + (uint32)0x000CU))

/* LPU Status Register */
#define LPU_SR_ADDR32                                       ((uint32)(LPU_BASEADDR + (uint32)0x0010U))

/* LPU Interrupt control register */
#define LPU_ICR_ADDR32                                      ((uint32)(LPU_BASEADDR + (uint32)0x0014U))

/* Module Disable */
#define LPU_MDIS_ADDR32                                     ((uint32)(LPU_BASEADDR + (uint32)0x0018U))

/***********************************************************/
/*                           LPU_MCTL                      */
/***********************************************************/
#define LPU_MCTL_RWBITS_MASK32                             ((uint32)0xF000FFFFU)
#define LPU_MCTL_RESBITS_MASK32                            ((uint32)0x00000000U)

/********************************************************/
/*                    LPU_MCTL[KEY]                     */
/********************************************************/
/* LPU_MCTL[KEY] field: Control key - These bits enable write access to this register. */
#define LPU_MCTL_DIRECT_KEY_U32                   ((uint32)0x00005AF0U)
/* LPU_MCTL[KEY] field: Read access will always return inverted key. */
#define LPU_MCTL_INVERTED_KEY_U32                 ((uint32)0x0000A50FU)

/***********************************************************/
/*                           LPU_RUN_CF                    */
/***********************************************************/
#define LPU_RUN_CF_RWBITS_MASK32                             ((uint32)0x000101DAU)
#define LPU_RUN_CF_RESBITS_MASK32                            ((uint32)0x00000000U)

#define LPU_RUN_CF_CAN0_CONT_MASK32                          ((uint32)0x00010000U)
#define LPU_RUN_CF_DIRECT_DRUN_MASK32                        ((uint32)0x00000100U)
#define LPU_RUN_CF_SYS_CLK_SEL_MASK32                        ((uint32)0x00000080U)
#define LPU_RUN_CF_LPU_SLEEP_MASK32                          ((uint32)0x00000040U)
#define LPU_RUN_CF_SXOSC_ON_MASK32                           ((uint32)0x00000010U)
#define LPU_RUN_CF_SIRC_ON_MASK32                            ((uint32)0x00000008U)
#define LPU_RUN_CF_FXOSC_ON_MASK32                           ((uint32)0x00000002U)
#define LPU_RUN_CF_FIRC_ON_MASK32                            ((uint32)0x00000001U)

/***********************************************************/
/*                           LPU_STOP_CF                   */
/***********************************************************/
#define LPU_STOP_CF_RWBITS_MASK32                             ((uint32)0x0000001BU)
#define LPU_STOP_CF_RESBITS_MASK32                            ((uint32)0x00000000U)

#define LPU_STOP_CF_SXOSC_ON_MASK32                           ((uint32)0x00000010U)
#define LPU_STOP_CF_SIRC_ON_MASK32                            ((uint32)0x00000008U)
#define LPU_STOP_CF_FXOSC_ON_MASK32                           ((uint32)0x00000002U)
#define LPU_STOP_CF_FIRC_ON_MASK32                            ((uint32)0x00000001U)

/***********************************************************/
/*                           LPU_STANDBY_CF                */
/***********************************************************/
#define LPU_STANDBY_CF_RWBITS_MASK32                             ((uint32)0x0000001BU)
#define LPU_STANDBY_CF_RESBITS_MASK32                            ((uint32)0x00000000U)

#define LPU_STANDBY_CF_SXOSC_ON_MASK32                           ((uint32)0x00000010U)
#define LPU_STANDBY_CF_SIRC_ON_MASK32                            ((uint32)0x00000008U)
#define LPU_STANDBY_CF_FXOSC_ON_MASK32                           ((uint32)0x00000002U)
#define LPU_STANDBY_CF_FIRC_ON_MASK32                            ((uint32)0x00000001U)

/***********************************************************/
/*                           LPU_SR                        */
/***********************************************************/
#define LPU_SR_RWBITS_MASK32                                 ((uint32)0x00000000U)
#define LPU_SR_RESBITS_MASK32                                ((uint32)0x00018003U)

#define LPU_SR_PD2_PWR_STAT_MASK32                           ((uint32)0x00200000U)
#define LPU_SR_SXOSC_STAT_MASK32                             ((uint32)0x00100000U)
#define LPU_SR_SIRC_STAT_MASK32                              ((uint32)0x00080000U)
#define LPU_SR_FXOSC_STAT_MASK32                             ((uint32)0x00020000U)
#define LPU_SR_FIRC_STAT_MASK32                              ((uint32)0x00010000U)
#define LPU_SR_CLK1_STOP_MASK32                              ((uint32)0x00008000U)
#define LPU_SR_CLK0_STOP_MASK32                              ((uint32)0x00004000U)
#define LPU_SR_MTRANS_MASK32                                 ((uint32)0x00000020U)
#define LPU_SR_CURRENT_MODE_MASK32                           ((uint32)0x0000000FU)

/***********************************************************/
/*                           LPU_ICR                       */
/***********************************************************/
#define LPU_ICR_RWBITS_MASK32                               ((uint32)0x000C000CU)
#define LPU_ICR_RESBITS_MASK32                              ((uint32)0x00000000U)

#define LPU_ICR_LPU_MRIG_E_MASK32                           ((uint32)0x00080000U)
#define LPU_ICR_LPU_NEM_E_MASK32                            ((uint32)0x00040000U)
#define LPU_ICR_LPU_MRIG_MASK32                             ((uint32)0x00000008U)
#define LPU_ICR_LPU_NEM_MASK32                              ((uint32)0x00000004U)

/***********************************************************/
/*                           LPU_MDIS                      */
/***********************************************************/
#define LPU_MDIS_RWBITS_MASK32                           ((uint32)0x000003FFU)
#define LPU_MDIS_RESBITS_MASK32                          ((uint32)0x00000000U)

#define LPU_MDIS_eMIOS_0_MASK32                          ((uint32)0x00000200U)
#define LPU_MDIS_eMIOS_2_MASK32                          ((uint32)0x00000200U)
#define LPU_MDIS_CMP_2_MASK32                            ((uint32)0x00000100U)
#define LPU_MDIS_CMP_1_MASK32                            ((uint32)0x00000080U)
#define LPU_MDIS_CMP_0_MASK32                            ((uint32)0x00000040U)
#define LPU_MDIS_MEMU_1_MASK32                           ((uint32)0x00000020U)
#define LPU_MDIS_BCTU_MASK32                             ((uint32)0x00000010U)
#define LPU_MDIS_CAN0_MASK32                             ((uint32)0x00000008U)
#define LPU_MDIS_LIN_0_MASK32                            ((uint32)0x00000004U)
#define LPU_MDIS_SPI_0_MASK32                            ((uint32)0x00000002U)
#define LPU_MDIS_ADC_0_MASK32                            ((uint32)0x00000001U)

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

#endif /* REG_ESYS_LPU_H */

/** @} */
