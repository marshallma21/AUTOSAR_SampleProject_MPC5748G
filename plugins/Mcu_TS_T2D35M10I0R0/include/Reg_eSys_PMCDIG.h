/**
*   @file    Reg_eSys_PMCDIG.h
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


#ifndef REG_ESYS_PMCDIG_H
#define REG_ESYS_PMCDIG_H


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
#include "Mcu_PMCDIG_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_PMCDIG_VENDOR_ID                       43
#define REG_ESYS_PMCDIG_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_PMCDIG_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_PMCDIG_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_PMCDIG_SW_MAJOR_VERSION                1
#define REG_ESYS_PMCDIG_SW_MINOR_VERSION                0
#define REG_ESYS_PMCDIG_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_PMCDIG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_PMCDIG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_PMCDIG.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_PMCDIG_IPVersion header file are from the same vendor */
#if (REG_ESYS_PMCDIG_VENDOR_ID != MCU_PMCDIG_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_PMCDIG.h and Mcu_PMCDIG_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_PMCDIG_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_PMCDIG_AR_RELEASE_MAJOR_VERSION != MCU_PMCDIG_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_PMCDIG_AR_RELEASE_MINOR_VERSION != MCU_PMCDIG_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_PMCDIG_AR_RELEASE_REVISION_VERSION != MCU_PMCDIG_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_PMCDIG.h and Mcu_PMCDIG_IPVersion.h are different"
#endif
/* Check if source file and Mcu_PMCDIG_IPVersion header file are of the same Software version */
#if ((REG_ESYS_PMCDIG_SW_MAJOR_VERSION != MCU_PMCDIG_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_PMCDIG_SW_MINOR_VERSION != MCU_PMCDIG_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_PMCDIG_SW_PATCH_VERSION != MCU_PMCDIG_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_PMCDIG.h and Mcu_PMCDIG_IPVersion.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* RAM Domain Configuration Register */
#define PMCDIG_RDCR_ADDR32                                  ((uint32)(PMCDIG_BASEADDR + (uint32)0x0000U))
/* Supply Gauge Status Register */
#define PMCDIG_SGSR_ADDR32                                  ((uint32)(PMCDIG_BASEADDR + (uint32)0x0004U))
/* MISC Control Register */
#define PMCDIG_MCR_ADDR32                                   ((uint32)(PMCDIG_BASEADDR + (uint32)0x0010U))


/***********************************************************/
/*                        PMCDIG_RDCR                      */
/***********************************************************/
#if (IPV_PMC == IPV_PMCDIG_00_01_04_43)
    #define PMCDIG_RDCR_RWBITS_MASK32                           ((uint32)0x00110111U)
#elif (IPV_PMC == IPV_PMCDIG_00_01_08_04)
    #define PMCDIG_RDCR_RWBITS_MASK32                           ((uint32)0x00100001U)
#endif

#define PMCDIG_RDCR_RESBITS_MASK32                          ((uint32)0x00000000U)

#define PMCDIG_RDCR_MEM_SLEEP_EN_MASK32                     ((uint32)0x00100000U)
#define PMCDIG_RDCR_PAD_KEEP_EN_MASK32                      ((uint32)0x00010000U)

#define PMCDIG_RDCR_RD24_RET_MASK32                         ((uint32)0x00000001U)

#define PMCDIG_RDCR_RD64_RET_MASK32                         ((uint32)0x00000001U)
#define PMCDIG_RDCR_RD128_RET_MASK32                        ((uint32)0x00000010U)
#define PMCDIG_RDCR_RD256_RET_MASK32                        ((uint32)0x00000100U)

/***********************************************************/
/*                        PMCDIG_SGSR                      */
/***********************************************************/
#if (IPV_PMC == IPV_PMCDIG_00_01_08_04)
    #define PMCDIG_SGSR_RWBITS_MASK32                           ((uint32)0x00001ABFU)
#else
    #define PMCDIG_SGSR_RWBITS_MASK32                           ((uint32)0x00001AFFU)
#endif

#define PMCDIG_SGSR_RESBITS_MASK32                          ((uint32)0x00000000U)

#define PMCDIG_SGSR_LP_STATUS_MASK32                        ((uint32)0x00001800U)
#define PMCDIG_SGSR_HVD_LV_COLD_MASK32                      ((uint32)0x00000200U)
#define PMCDIG_SGSR_LVD_FLASH_MASK32                        ((uint32)0x00000080U)
#define PMCDIG_SGSR_LVD_IO_A_HI_MASK32                      ((uint32)0x00000040U)
#define PMCDIG_SGSR_LVD_IO_A_LO_MASK32                      ((uint32)0x00000020U)
#define PMCDIG_SGSR_LVD_LV_PD0_HOT_MASK32                   ((uint32)0x00000010U)
#define PMCDIG_SGSR_LVD_LV_PD1_HOT_MASK32                   ((uint32)0x00000008U)
#define PMCDIG_SGSR_LVD_LV_PD2_COLD_MASK32                  ((uint32)0x00000004U)
#define PMCDIG_SGSR_LVD_LV_PD2_HOT_MASK32                   ((uint32)0x00000002U)
#define PMCDIG_SGSR_POR_LV_MASK32                           ((uint32)0x00000001U)


/***********************************************************/
/*                        PMCDIG_MCR                       */
/***********************************************************/
#if (IPV_PMC == IPV_PMCDIG_00_01_04_43)
    #define PMCDIG_MCR_RWBITS_MASK32                            ((uint32)0x00008D00U)
#elif (IPV_PMC == IPV_PMCDIG_00_01_08_04)
    #define PMCDIG_MCR_RWBITS_MASK32                            ((uint32)0x701E8C00U)
#endif

#define PMCDIG_MCR_RESBITS_MASK32                           ((uint32)0x00000000U)

#define PMCDIG_MCR_ISO_ACK2_MASK32                          ((uint32)0x40000000U)
#define PMCDIG_MCR_ISO_ACK1_MASK32                          ((uint32)0x20000000U)
#define PMCDIG_MCR_ISO_ACK0_MASK32                          ((uint32)0x10000000U)

#define PMCDIG_MCR_LP_ST_CHG_IN_PRGRS_MASK32                ((uint32)0x00010000U)

#define PMCDIG_MCR_FLASH_LP_FAST_EXIT_DIS_MASK32            ((uint32)0x00008000U)

#if ((IPV_PMC == IPV_PMCDIG_00_01_04_43) || (IPV_PMC == IPV_PMCDIG_00_01_08_04))
    #define PMCDIG_MCR_LVD_PD2_COLD_REE_MASK32                  ((uint32)0x00000800U)
    #define PMCDIG_MCR_HVD_REE_MASK32                           ((uint32)0x00000400U)
    #define PMCDIG_MCR_LVD_IO_HI_REE_MASK32                     ((uint32)0x00000100U)
#endif

#if (IPV_PMC == IPV_PMCDIG_00_01_08_04)
    #define PMCDIG_MCR_SIG_TO_ADC_FLIP_MASK32                  ((uint32)0x00400000U)
    #define PMCDIG_MCR_SIG_TO_ADC_EN_MASK32                    ((uint32)0x00200000U)
    #define PMCDIG_MCR_SIG_TO_ADC_SEL_MASK32                   ((uint32)0x001E0000U)
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

#endif /* REG_ESYS_PMCDIG_H */

/** @} */
