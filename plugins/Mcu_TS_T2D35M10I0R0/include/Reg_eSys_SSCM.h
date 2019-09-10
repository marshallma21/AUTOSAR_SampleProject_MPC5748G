/**
*   @file    Reg_eSys_SSCM.h
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


#ifndef REG_ESYS_SSCM_H
#define REG_ESYS_SSCM_H

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
#include "Mcu_SSCM_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_SSCM_VENDOR_ID                         43
#define REG_ESYS_SSCM_AR_RELEASE_MAJOR_VERSION          4
#define REG_ESYS_SSCM_AR_RELEASE_MINOR_VERSION          2
#define REG_ESYS_SSCM_AR_RELEASE_REVISION_VERSION       2
#define REG_ESYS_SSCM_SW_MAJOR_VERSION                  1
#define REG_ESYS_SSCM_SW_MINOR_VERSION                  0
#define REG_ESYS_SSCM_SW_PATCH_VERSION                  0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_SSCM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_SSCM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_SSCM.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_SSCM_IPVersion header file are from the same vendor */
#if (REG_ESYS_SSCM_VENDOR_ID != MCU_SSCM_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_SSCM.h and Mcu_SSCM_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_SSCM_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_SSCM_AR_RELEASE_MAJOR_VERSION != MCU_SSCM_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_SSCM_AR_RELEASE_MINOR_VERSION != MCU_SSCM_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_SSCM_AR_RELEASE_REVISION_VERSION != MCU_SSCM_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_SSCM.h and Mcu_SSCM_IPVersion.h are different"
#endif
/* Check if source file and Mcu_SSCM_IPVersion header file are of the same Software version */
#if ((REG_ESYS_SSCM_SW_MAJOR_VERSION != MCU_SSCM_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_SSCM_SW_MINOR_VERSION != MCU_SSCM_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_SSCM_SW_PATCH_VERSION != MCU_SSCM_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_SSCM.h and Mcu_SSCM_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

#if (IPV_SSCM == IPV_SSCM_06_00_00_06)
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)    
    /* SSCM System Status (SSCM_STATUS) */
    #define SSCM_STATUS_ADDR16                  ((uint32)(SSCM_BASEADDR + (uint32)0x0002UL))
    /* SSCM System Memory and ID Register (SSCM_MEMCONFIG) */
    #define SSCM_MEMCONFIG_ADDR16               ((uint32)(SSCM_BASEADDR + (uint32)0x0000UL))
#else
    /* SSCM System Status (SSCM_STATUS) */
    #define SSCM_STATUS_ADDR16                  ((uint32)(SSCM_BASEADDR + (uint32)0x0000UL))
    /* SSCM System Memory and ID Register (SSCM_MEMCONFIG) */
    #define SSCM_MEMCONFIG_ADDR16               ((uint32)(SSCM_BASEADDR + (uint32)0x0002UL))
#endif
#else
    /* SSCM System Status (SSCM_STATUS) */
    #define SSCM_STATUS_ADDR16                  ((uint32)(SSCM_BASEADDR + (uint32)0x0000UL))
    /* SSCM System Memory and ID Register (SSCM_MEMCONFIG) */
    #define SSCM_MEMCONFIG_ADDR16               ((uint32)(SSCM_BASEADDR + (uint32)0x0002UL))
#endif


/* SSCM Error Configuration Register (SSCM_ERROR) */
#define SSCM_ERROR_ADDR16                   ((uint32)(SSCM_BASEADDR + (uint32)0x0006UL))

#if ((IPV_SSCM == IPV_SSCM_05_03_00_00) || (IPV_SSCM == IPV_SSCM_06_00_00_06) ||  \
     (IPV_SSCM == IPV_SSCM_06_00_00_04) || (IPV_SSCM == IPV_SSCM_04_01_17_00))
    /* User Option Status Register (SSCM_UOPS) */
    #define SSCM_UOPS_ADDR32                ((uint32)(SSCM_BASEADDR + (uint32)0x0020UL))
#endif

/* SSCM System Status (SSCM_STATUS) bit masks */
#if (IPV_SSCM == IPV_SSCM_06_00_00_01)
    #define SSCM_STATUS_RWBITS_MASK16       ((uint16)0x6000U)
    #define SSCM_STATUS_RESBITS_MASK16      ((uint16)0x0400U)

#elif (IPV_SSCM == IPV_SSCM_05_03_00_00)
    #define SSCM_STATUS_RWBITS_MASK16       ((uint16)0x6000U)
    #define SSCM_STATUS_RESBITS_MASK16      ((uint16)0x0400U)

#elif (IPV_SSCM == IPV_SSCM_05_04_00_00)
    #define SSCM_STATUS_RWBITS_MASK16       ((uint16)0x6000U)
    #define SSCM_STATUS_RESBITS_MASK16      ((uint16)0x0010U)

#elif (IPV_SSCM == IPV_SSCM_06_00_00_06)
    #define SSCM_STATUS_RWBITS_MASK16       ((uint16)0x4000U)
    #define SSCM_STATUS_RESBITS_MASK16      ((uint16)0x0410U)

#elif (IPV_SSCM == IPV_SSCM_06_00_00_04)
    #define SSCM_STATUS_RWBITS_MASK16       ((uint16)0x6000U)
    #define SSCM_STATUS_RESBITS_MASK16      ((uint16)0x0410U)

#elif (IPV_SSCM == IPV_SSCM_04_01_17_00)
    #define SSCM_STATUS_RWBITS_MASK16       ((uint16)0x6000U)
    #define SSCM_STATUS_RESBITS_MASK16      ((uint16)0x0000U)

#endif

/* Configuration Error */
#define SSCM_STATUS_CER_MASK16              ((uint16)0x4000U)

/* Configuration Error for Safe DCF Clients */
#if ((IPV_SSCM == IPV_SSCM_06_00_00_01) || (IPV_SSCM == IPV_SSCM_05_04_00_00) || \
     (IPV_SSCM == IPV_SSCM_06_00_00_04) || (IPV_SSCM == IPV_SSCM_04_01_17_00))
    #define SSCM_STATUS_CERS_MASK16         ((uint16)0x2000U)
#endif

/* Processor 1 Nexus enable status */
#if ((IPV_SSCM == IPV_SSCM_05_03_00_00) || (IPV_SSCM == IPV_SSCM_06_00_00_01) || \
     (IPV_SSCM == IPV_SSCM_05_04_00_00))
    #define SSCM_STATUS_NXEN1_MASK16        ((uint16)0x1000U)
#endif

#if ((IPV_SSCM == IPV_SSCM_05_03_00_00) || (IPV_SSCM == IPV_SSCM_06_00_00_01) || \
     (IPV_SSCM == IPV_SSCM_05_04_00_00) || (IPV_SSCM == IPV_SSCM_04_01_17_00))
/* Processor 0 Nexus enable status */
    #define SSCM_STATUS_NXEN_MASK16         ((uint16)0x0800U)
#endif

/* Public Serial Access Status, Security Status */
#if ((IPV_SSCM == IPV_SSCM_05_04_00_00) || (IPV_SSCM == IPV_SSCM_04_01_17_00))
    #define SSCM_STATUS_PUB_MASK16          ((uint16)0x0400U)
    #define SSCM_STATUS_SEC_MASK16          ((uint16)0x0200U)
#endif

/* Device Boot Mode */
#define SSCM_STATUS_BMODE_MASK16            ((uint16)0x00E0U)

/* Variable Length Instruction Mode. */
#if ((IPV_SSCM == IPV_SSCM_06_00_00_01) || (IPV_SSCM == IPV_SSCM_04_01_17_00))
    #define SSCM_STATUS_VLE_MASK16          ((uint16)0x0010U)
#endif


/* SSCM System Memory and ID Register (SSCM_MEMCONFIG) */
#define SSCM_MEMCONFIG_RWBITS_MASK16        ((uint16)0x0000U)

#if ((IPV_SSCM == IPV_SSCM_06_00_00_01) || (IPV_SSCM == IPV_SSCM_06_00_00_06))
    #define SSCM_MEMCONFIG_RESBITS_MASK16   ((uint16)0x0020U)
#elif ((IPV_SSCM == IPV_SSCM_05_04_00_00) || (IPV_SSCM == IPV_SSCM_04_01_17_00))
    #define SSCM_MEMCONFIG_RESBITS_MASK16   ((uint16)0x0000U)
#endif

#define SSCM_MEMCONFIG_JPIN_MASK16          ((uint16)0xFFC0U)
#define SSCM_MEMCONFIG_MREV_MASK16          ((uint16)0x001EU)

#if (IPV_SSCM == IPV_SSCM_05_04_00_00)
    #define SSCM_MEMCONFIG_IVLD_MASK16      ((uint16)0x0020U)

#elif (IPV_SSCM == IPV_SSCM_04_01_17_00)
    #define SSCM_MEMCONFIG_IVLD_MASK16      ((uint16)0x0020U)
    #define SSCM_MEMCONFIG_DVLD_MASK16      ((uint16)0x0001U)
#endif

/* SSCM Error Configuration Register (SSCM_ERROR) */
#define SSCM_ERROR_RWBITS_MASK16            ((uint16)0x0003U)

#define SSCM_ERROR_RESBITS_MASK16           ((uint16)0x0000U)

#define SSCM_ERROR_PAE_MASK16               ((uint16)0x0002U)
#define SSCM_ERROR_RAE_MASK16               ((uint16)0x0001U)

/* User Option Status Register (SSCM_UOPS) */
#if (IPV_SSCM == IPV_SSCM_06_00_00_06)
    #define SSCM_UOPS_SBE_MASK32            ((uint32)0x00000010U)
    #define SSCM_UOPS_CSE_BC_MASK32         ((uint32)0x0000000EU)
    #define SSCM_UOPS_CEN_MASK32            ((uint32)0x00000001U)
#elif (IPV_SSCM == IPV_SSCM_04_01_17_00)
    #define SSCM_UOPS_UOPT_MASK32           ((uint32)0xFFFFFFFFU)
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

#endif /* REG_ESYS_SSCM_H */

/** @} */
