/**
*   @file    Reg_eSys_MC_RGM.h
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


#ifndef REG_ESYS_MC_RGM_H
#define REG_ESYS_MC_RGM_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_MC_RGM_h_REF_1
* Violates MISRA 2004 Required Rule 1.4, : The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers
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
#include "Mcu_MC_IPVersion.h"
#include "Mcu_Cfg.h"
#include "Reg_eSys.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_MC_RGM_VENDOR_ID                       43
/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_RGM_AR_RELEASE_MAJOR_VERSION        4
/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_RGM_AR_RELEASE_MINOR_VERSION        2
/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_RGM_AR_RELEASE_REVISION_VERSION     2
/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_RGM_SW_MAJOR_VERSION                1
/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_RGM_SW_MINOR_VERSION                0
/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define REG_ESYS_MC_RGM_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_MC_RGM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_MC_RGM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_MC_RGM.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_MC_IPVersion header file are from the same vendor */
#if (REG_ESYS_MC_RGM_VENDOR_ID != MCU_MC_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_MC_RGM.h and Mcu_MC_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_MC_RGM_AR_RELEASE_MAJOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_MC_RGM_AR_RELEASE_MINOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_MC_RGM_AR_RELEASE_REVISION_VERSION != MCU_MC_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_MC_RGM.h and Mcu_MC_IPVersion.h are different"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Software version */
#if ((REG_ESYS_MC_RGM_SW_MAJOR_VERSION != MCU_MC_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_MC_RGM_SW_MINOR_VERSION != MCU_MC_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_MC_RGM_SW_PATCH_VERSION != MCU_MC_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_MC_RGM.h and Mcu_MC_IPVersion.h are different"
#endif

/* Check if current file and Mcu_Cfg header file are of the same vendor */
#if (REG_ESYS_MC_RGM_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Reg_eSys_MC_RGM.c and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if current file and Mcu_Cfg header file are of the same Autosar version */
#if ((REG_ESYS_MC_RGM_AR_RELEASE_MAJOR_VERSION    != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_MC_RGM_AR_RELEASE_MINOR_VERSION    != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_MC_RGM_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_MC_RGM.c and Mcu_Cfg.h are different"
#endif
/* Check if current file and Mcu_Cfg header file are of the same Software version */
#if ((REG_ESYS_MC_RGM_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (REG_ESYS_MC_RGM_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (REG_ESYS_MC_RGM_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_MC_RGM.c and Mcu_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/********** MC_RGM Registers **********/

/* destructive reset control */

/* MC_RGM: Destructive Event Status Register Address. */
#define MC_RGM_DES_ADDR32                   ((uint32)(MC_RGM_BASEADDR + (uint32)0x00UL))
/* MC_RGM: Destructive Event Reset Disable Register Address. */
#define MC_RGM_DERD_ADDR32                  ((uint32)(MC_RGM_BASEADDR + (uint32)0x0010U))
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* MC_RGM: Destructive Event Alternate Request Register Address. */
    #define MC_RGM_DEAR_ADDR32              ((uint32)(MC_RGM_BASEADDR + (uint32)0x0020U))
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||
           (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||
           (IPV_MC == IPV_MC_04_06_05_00) ) */

/* MC_RGM: Destructive' Bidirectional Reset Enable Register (MC_RGM_DBRE) */
#define MC_RGM_DBRE_ADDR32                  ((uint32)(MC_RGM_BASEADDR + (uint32)0x0030U))

/* functional reset control */
/* MC_RGM: Functional Event Status Register Address. */
#define MC_RGM_FES_ADDR32                   ((uint32)(MC_RGM_BASEADDR + (uint32)0x0300U))
/* MC_RGM: Functional Event Reset Disable Register Address. */
#define MC_RGM_FERD_ADDR32                  ((uint32)(MC_RGM_BASEADDR + (uint32)0x0310U))
/* MC_RGM: Functional Event Alternate Request Register Address. */
#define MC_RGM_FEAR_ADDR32                  ((uint32)(MC_RGM_BASEADDR + (uint32)0x0320U))
/* MC_RGM: Functional Bidirectional Reset Enable Register Address. */
#define MC_RGM_FBRE_ADDR32                  ((uint32)(MC_RGM_BASEADDR + (uint32)0x0330U))
/* MC_RGM: Functional Event Short Sequence Register Address. */
#define MC_RGM_FESS_ADDR32                  ((uint32)(MC_RGM_BASEADDR + (uint32)0x0340U))
/* MC_RGM: DDR Handshake Enable Register. */
#define MC_RGM_DDR_HE_ADDR32                ((uint32)(MC_RGM_BASEADDR + (uint32)0x0350U))
/* MC_RGM: DDR Handshake Status Register. */
#define MC_RGM_DDR_HS_ADDR32                ((uint32)(MC_RGM_BASEADDR + (uint32)0x0354U))
/* MC_RGM: Functional Reset Handshake Enable. */
#define MC_RGM_FRHE_ADDR32                  ((uint32)(MC_RGM_BASEADDR + (uint32)0x0358U))
/* MC_RGM: Functional Reset Escalation Counter. */
#define MC_RGM_DDR_FREC_ADDR32              ((uint32)(MC_RGM_BASEADDR + (uint32)0x0600U))

#if (IPV_MC == IPV_MC_05_00_00_10)
    /* MC_RGM: Functional Reset Threshold Register Address. */
    #define MC_RGM_FRET_ADDR8                   ((uint32)(MC_RGM_BASEADDR + (uint32)0x0607U))
    /* MC_RGM: Destructive Reset Escalation Threshold Register Address. */
    #define MC_RGM_DRET_ADDR8               ((uint32)(MC_RGM_BASEADDR + (uint32)0x060BU))
#else
    /* MC_RGM: Functional Reset Threshold Register Address. */
    #define MC_RGM_FRET_ADDR8                   ((uint32)(MC_RGM_BASEADDR + (uint32)0x0604U))
    /* MC_RGM: Destructive Reset Escalation Threshold Register Address. */
    #define MC_RGM_DRET_ADDR8               ((uint32)(MC_RGM_BASEADDR + (uint32)0x0608U))
    /* MC_RGM: Functional Reset Threshold Register Address. */
    #define MC_RGM_FRET_ADDR32                   ((uint32)(MC_RGM_BASEADDR + (uint32)0x0604U))
    /* MC_RGM: Destructive Reset Escalation Threshold Register Address. */
    #define MC_RGM_DRET_ADDR32                   ((uint32)(MC_RGM_BASEADDR + (uint32)0x0608U))
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
/* MC_RGM: External Reset Output Extension Control Register. */
#define MC_RGM_EROEC_ADDR8                  ((uint32)(MC_RGM_BASEADDR + (uint32)0x060CU))
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15)) */

/***********************************************/
/***************** MC_RGM_DES ******************/
/***********************************************/
#if (IPV_MC == IPV_MC_04_04_01_00)
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x01800339U)
#elif (IPV_MC == IPV_MC_04_03_00_00)
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x01800119U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x0180C73BU)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x0380077BU)
#elif (IPV_MC == IPV_MC_04_06_05_00)
#if (MCU_MIPI_PRESENT == STD_ON)
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x01FFBFF79)
#else
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x0DFBFF39U)
#endif
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x00001369U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x000005FDU)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_RGM_DES_RWBITS_MASK32        ((uint32)0x78001179U)
#endif

#define MC_RGM_DES_RESBITS_MASK32           ((uint32)0x00000000U)

/* flags that generate IRQ events */
#if (IPV_MC == IPV_MC_04_04_01_00)
    /* DES can not generate IRQ for this version */
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* DEAR:AR_TSR_DEST => DES:F_TSR_DEST */
    #define MC_RGM_DES_IRQ_BITS_MASK32          ((uint32)0x00800000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* DEAR:AR_PORST => DES:F_PORST */
    #define MC_RGM_DES_IRQ_BITS_MASK32          ((uint32)0x00000002U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* DEAR:AR_PORST => DES:F_PORST */
    #define MC_RGM_DES_IRQ_BITS_MASK32          ((uint32)0x00800002U)
#elif ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_06_00_00_10))
    #define MC_RGM_DES_IRQ_BITS_MASK32          ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_RGM_DES_IRQ_BITS_MASK32          ((uint32)0x00000000U)
#endif

/* RGM_DES[F_POR] bit mask. */
#define MC_RGM_DES_F_POR_MASK32             ((uint32)0x00000001U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
#define MC_RGM_DES_F_PORST_MASK32           ((uint32)0x00000002U)
#endif  /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||
            (IPV_MC == IPV_MC_04_06_01_00)) */

/* RGM_DES[F_SOFT_DEST] bit mask. */
#define MC_RGM_DES_F_SOFT_DEST_MASK32       ((uint32)0x00000008U)
/* RGM_DES[F_FFRR] bit mask. */
#define MC_RGM_DES_F_FFRR_MASK32            ((uint32)0x00000010U)

/* RGM_DES[F_SSCM_SEC] bit mask. */
#define MC_RGM_DES_F_SSCM_SEC_MASK32        ((uint32)0x00000010U)

/* RGM_DES[F_FUNC_ESC] bit mask. */
#define MC_RGM_DES_F_FUNC_ESC_MASK32        ((uint32)0x00000020U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) || \
     (IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_06_00_00_10) \
    )
    /* RGM_DES[F_SUF] bit mask. */
    #define MC_RGM_DES_F_SUF_MASK32             ((uint32)0x00000020U)

#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* RGM_DES[F_SUF] bit mask. */
    #define MC_RGM_DES_F_SUF_MASK32             ((uint32)0x00000040U)
#endif

#define MC_RGM_DES_F_DDR_HNDSHK_TO_MASK32       ((uint32)0x00000040U)

#if (IPV_MC == IPV_MC_04_06_01_00)
    /* RGM_DES[F_SSR] bit mask. */
    #define MC_RGM_DES_F_SSR_MASK32             ((uint32)0x00000040U)
#endif

/* RGM_DES[F_SSSR] bit mask. */
#define MC_RGM_F_SSSR_MASK32                ((uint32)0x00000040U)

/* RGM_DES[F_SWT0_RES] bit mask. */
#define MC_RGM_DES_F_SWT0_RES_MASK32        ((uint32)0x00000080U)

/* RGM_DES[F_SWT1_RES] bit mask. */
#define MC_RGM_DES_F_SWT1_RES_MASK32        ((uint32)0x00000100U)

/* RGM_DES[F_EDR] bit mask. */
#define MC_RGM_DES_F_EDR_MASK32             ((uint32)0x00000100U)

/* RGM_DES[F_EFR] bit mask. */
#define MC_RGM_DES_F_EFR_MASK32             ((uint32)0x00000100U)

/* RGM_DES[F_SWT2_RES] bit mask. */
#define MC_RGM_DES_F_SWT2_RES_MASK32        ((uint32)0x00000400U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_10) || \
     (IPV_MC == IPV_MC_04_04_01_00) \
    )
     /* RGM_DES[F_FIF] bit mask. */
    #define MC_RGM_DES_F_FIF_MASK32             ((uint32)0x00000200U)
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
           (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_10)) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    /* RGM_DES_[F_JTAG_DEST] bit mask. */
    #define MC_RGM_DES_F_JTAG_DEST_MASK32       ((uint32)0x00000400U)
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||
           (IPV_MC == IPV_MC_04_06_01_00)) */

#if (IPV_MC == IPV_MC_05_00_00_10)
    /* RGM_DES_[F_JTAG] bit mask. */
    #define MC_RGM_DES_F_JTAG_MASK32            ((uint32)0x00001000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#define MC_RGM_DES_F_DBGRST_MASK32              ((uint32)0x00001000U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* RGM_DES_[F_SSCM_DEST] bit mask. */
    #define MC_RGM_DES_F_SSCM_DEST_MASK32       ((uint32)0x00004000U)
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00)) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* RGM_DES_[F_HSM_DEST] bit mask. */
    #define MC_RGM_DES_F_HSM_DEST_MASK32        ((uint32)0x00008000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* RGM_DES_[F_HSM_DEST] bit mask. */
    #define MC_RGM_DES_F_HSM_DEST_MASK32        ((uint32)0x00000004U)
#endif  /* (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) */

/* RGM_DES[F_TSR_DEST] bit mask. */
#define MC_RGM_DES_F_TSR_DEST_MASK32        ((uint32)0x00800000U)

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    /* RGM_DES[F_VOR_DEST] bit mask. */
    #define MC_RGM_DES_F_VOR_DEST_MASK32        ((uint32)0x01000000U)
#endif

#define MC_RGM_DES_F_LVD_33_PMC_MASK32          ((uint32)0x20000000U)
#define MC_RGM_DES_F_HVD_18_MASK32              ((uint32)0x40000000U)

#if (IPV_MC == IPV_MC_04_06_01_00)
    /* RGM_DES[F_PMC] bit mask. */
    #define MC_RGM_DES_F_PMC_MASK32             ((uint32)0x02000000U)
#endif  /* (IPV_MC == IPV_MC_04_06_01_00) */

#if (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_RGM_DES_F_LVD_CORE_MASK32        ((uint32)0x00000200U)
    #define MC_RGM_DES_F_HVD_CORE_MASK32        ((uint32)0x00000400U)
    #define MC_RGM_DES_F_LVD_ADC_MASK32         ((uint32)0x00000800U)
    #define MC_RGM_DES_F_HVD_ADC_MASK32         ((uint32)0x00001000U)
    #define MC_RGM_DES_F_LVD_FLASH_MASK32       ((uint32)0x00002000U)
    #define MC_RGM_DES_F_LVD_PLL_MASK32         ((uint32)0x00004000U)
    #define MC_RGM_DES_F_LVD_IO_MASK32          ((uint32)0x00008000U)
    #define MC_RGM_DES_F_LVD_PMC_MASK32         ((uint32)0x00010000U)
    #define MC_RGM_DES_F_AFE_LVD0_MASK32        ((uint32)0x00020000U)
    #define MC_RGM_DES_F_AFE_LVD1_MASK32        ((uint32)0x00040000U)
    #define MC_RGM_DES_F_AFE_LVD2_MASK32        ((uint32)0x00080000U)
    #define MC_RGM_DES_F_AFE_LVD3_MASK32        ((uint32)0x00100000U)
    #define MC_RGM_DES_F_AFE_LVD4_MASK32        ((uint32)0x00200000U)
    #define MC_RGM_DES_F_AFE_LVD5_MASK32        ((uint32)0x00400000U)
    #define MC_RGM_DES_F_AFE_LVD7_MASK32        ((uint32)0x01000000U)
    #define MC_RGM_DES_F_AFE_LVD8_MASK32        ((uint32)0x02400000U)
    #define MC_RGM_DES_F_AFE_LVD6_MASK32        ((uint32)0x04000000U)
    #define MC_RGM_DES_F_AFE_LVD9_MASK32        ((uint32)0x08000000U)
    #define MC_RGM_DES_F_LVD_MIPI_MASK32        ((uint32)0x10000000U)
#else
    #define MC_RGM_DES_F_HVD_CORE_MASK32            ((uint32)0x08000000U)
    #define MC_RGM_DES_F_LVD_CORE_MASK32            ((uint32)0x10000000U)
#endif

/***********************************************/
/***************** MC_RGM_DERD *****************/
/***********************************************/
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_05_00_00_07))
    /* used bits mask */
    #define MC_RGM_DERD_RWBITS_MASK32           ((uint32)0x00000000U)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* used bits mask */
    #define MC_RGM_DERD_RWBITS_MASK32           ((uint32)0x00800000U)
#elif (IPV_MC == IPV_MC_04_00_15_15)
    /* used bits mask */
    #define MC_RGM_DERD_RWBITS_MASK32           ((uint32)0x00000002U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_RGM_DERD_RWBITS_MASK32           ((uint32)0x00800002U)
#elif (IPV_MC == IPV_MC_04_01_00_00)
    #define MC_RGM_DERD_RWBITS_MASK32           ((uint32)0x00000002U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_RGM_DERD_RWBITS_MASK32           ((uint32)0x00000000U)
#endif 

/* reserved bits mask */
#define MC_RGM_DERD_RESBITS_MASK32          ((uint32)0x00000000U)

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* Disable temperature sensor 'destructive' reset */
    #define MC_RGM_DERD_D_TSR_DEST_MASK32       ((uint32)0x00800000U)
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) \
    )
    /* Disable external power-on reset */
    #define MC_RGM_DERD_D_PORST_MASK32          ((uint32)0x00000002U)
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) */

/***********************************************/
/***************** MC_RGM_DBRE *****************/
/***********************************************/
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07) || \
     (IPV_MC == IPV_MC_06_00_00_10) \
    )
    /* used bits mask */
    #define MC_RGM_DBRE_RWBITS_MASK32           ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_04_00_15_15)
    /* used bits mask */
    #define MC_RGM_DBRE_RWBITS_MASK32           ((uint32)0x00008400U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* used bits mask */
    #define MC_RGM_DBRE_RWBITS_MASK32           ((uint32)0x02000400U)
#endif

/* reserved bits mask */
#define MC_RGM_DBRE_RESBITS_MASK32              ((uint32)0x00000000U)

#if (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_RGM_DBRE_BE_PMC_STF_MASK32       ((uint32)0x02000000U)
#endif
#if (IPV_MC == IPV_MC_04_00_15_15)
    /* Bidirectional Reset Enable for HSM destructive reset request */
    #define MC_RGM_DBRE_BE_HSM_DEST_MASK32      ((uint32)0x00008000U)
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00)) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_01_00))
    /* Bidirectional Reset Enable for JTAG destructive reset request */
    #define MC_RGM_DBRE_BE_JTAG_DEST_MASK32     ((uint32)0x00000400U)
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||
           (IPV_MC == IPV_MC_04_06_01_00)) */

#if (IPV_MC == IPV_MC_05_00_00_10)
    /* RGM_DBRE[BE_SOFT_DEST] bit mask */
    #define MC_RGM_DBRE_BE_SOFT_DEST_MASK32         ((uint32)0x00000008U)
    /* RGM_DBRE[BE_SUF] bit mask */
    #define MC_RGM_DBRE_BE_SUF_MASK32               ((uint32)0x00000020U)
    /* RGM_DBRE[BE_SSSR] bit mask */
    #define MC_RGM_DBRE_BE_SSSR_MASK32              ((uint32)0x00000040U)
    /* RGM_DBRE[BE_EFR] bit mask */
    #define MC_RGM_DBRE_BE_EFR_MASK32               ((uint32)0x00000100U)
    /* RGM_DBRE[BE_FIF] bit mask */
    #define MC_RGM_DBRE_BE_FIF_MASK32               ((uint32)0x00000200U)
    /* RGM_DBRE[BE_JTAG] bit mask */
    #define MC_RGM_DBRE_BE_JTAG_MASK32              ((uint32)0x00001000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */


/***********************************************/
/***************** MC_RGM_DEAR *****************/
/***********************************************/
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC ==IPV_MC_04_06_05_00))
    /* used bits mask */
    #define MC_RGM_DEAR_RWBITS_MASK32           ((uint32)0x00800000U)
    /* Alternate Request for temperature sensor 'destructive' reset */
    #define MC_RGM_DEAR_AR_TSR_DEST_MASK32      ((uint32)0x00800000U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* used bits mask */
    #define MC_RGM_DEAR_RWBITS_MASK32           ((uint32)0x00000002U)
    /* Alternate Request for temperature sensor 'destructive' reset */
    #define MC_RGM_DEAR_AR_PORST_MASK32         ((uint32)0x00000002U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* used bits mask */
    #define MC_RGM_DEAR_RWBITS_MASK32           ((uint32)0x00000002U)
    /* Alternate Request for temperature sensor 'destructive' reset */
    #define MC_RGM_DEAR_AR_TSR_DEST_MASK32      ((uint32)0x00800000U)
    /* Alternate Request for temperature sensor 'destructive' reset */
    #define MC_RGM_DEAR_AR_PORST_MASK32         ((uint32)0x00000002U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */

/* reserved bits mask */
#define MC_RGM_DEAR_RESBITS_MASK32              ((uint32)0x00000000U)

/***********************************************/
/***************** MC_RGM_FES  *****************/
/***********************************************/
#if ((IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    /* used bits mask */
    #define MC_RGM_FES_RWBITS_MASK32            ((uint32)0x0180046DU)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* used bits mask */
    #define MC_RGM_FES_RWBITS_MASK32            ((uint32)0x0180846FU)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    /* used bits mask */
    #define MC_RGM_FES_RWBITS_MASK32            ((uint32)0x0080046DU)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* used bits mask */
    #define MC_RGM_FES_RWBITS_MASK32            ((uint32)0x3C04C3F9U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* used bits mask */
    #define MC_RGM_FES_RWBITS_MASK32            ((uint32)0x00027FFDU)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* used bits mask */
    #define MC_RGM_FES_RWBITS_MASK32            ((uint32)0x0000846DU) 
#endif

/* reserved bits mask */
#define MC_RGM_FES_RESBITS_MASK32               ((uint32)0x00000000U)

/* flags that generate IRQ events */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00))
    /* AR_VOR_FUNC 7 => F_VOR_FUNC */
    /* AR_TSR_FUNC 8 => F_TSR_FUNC */
    /* AR_JTAG_FUNC 21 => F_JTAG_FUNC */
    #define MC_RGM_FES_IRQ_BITS_MASK32              ((uint32)0x01800400U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* AR_VOR_FUNC 7 => F_VOR_FUNC */
    /* AR_TSR_FUNC 8 => F_TSR_FUNC */
    /* AR_ESR1 30 => F_ESR1 */
    #define MC_RGM_FES_IRQ_BITS_MASK32              ((uint32)0x01800002U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    #define MC_RGM_FES_IRQ_BITS_MASK32              ((uint32)0x01800000U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #define MC_RGM_FES_IRQ_BITS_MASK32              ((uint32)0x01800400U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_RGM_FES_IRQ_BITS_MASK32              ((uint32)0x0000C020U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_RGM_FES_IRQ_BITS_MASK32              ((uint32)0x00027CB0U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_RGM_FES_IRQ_BITS_MASK32              ((uint32)0x00000000U)
#endif


#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    /* Flag for voltage out of range 'functional' reset */
    #define MC_RGM_FES_F_VOR_FUNC_MASK32            ((uint32)0x01000000U)
#endif

/* Flag for temperature sensor 'functional' reset */
#define MC_RGM_FES_F_TSR_FUNC_MASK32            ((uint32)0x00800000U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* Flag for HSM functional reset */
    #define MC_RGM_FES_F_HSM_FUNC_MASK32            ((uint32)0x00008000U)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* Flag for SWT4 Timeout functional reset */
    #define MC_RGM_FES_F_SWT4_MASK32                ((uint32)0x00008000U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)

    /* Flag for LVD_LV_PD2_cold reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FES_F_LVD_LV_PD2_COLD_MASK32     ((uint32)0x00020000U)
    /* Flag for HVD_LVD_cold reset */
    #define MC_RGM_FES_F_HVD_LV_COLD_MASK32        ((uint32)0x00004000U)
    /* Flag for LVD_IO_A_HI reset */
    #define MC_RGM_FES_F_LVD_IO_A_HI_MASK32         ((uint32)0x00002000U)
    /* Flag for Z2_DBG reset */
    #define MC_RGM_FES_F_Z2_DBG_MASK32              ((uint32)0x00001000U)
    /* Flag for Z4B_DBG reset */
    #define MC_RGM_FES_F_Z4B_DBG_MASK32             ((uint32)0x00000800U)
    /* Flag for Z4A_DBG reset */
    #define MC_RGM_FES_F_Z4A_DBG_MASK32             ((uint32)0x00000400U)
    /* Flag for FCCU_SHORT reset */
    #define MC_RGM_FES_F_FCCU_SHORT_MASK32          ((uint32)0x00000200U)
    /* Flag for FCCU_LONG reset */
    #define MC_RGM_FES_F_FCCU_LONG_MASK32           ((uint32)0x00000100U)
    /* Flag for CMU_OLR reset */
    #define MC_RGM_FES_F_CMU_OLR_MASK32             ((uint32)0x00000080U)
    /* Flag for Self Test done reset */
    #define MC_RGM_FES_F_ST_DONE_MASK32             ((uint32)0x00000040U)
    /* Flag for JTAG Functional reset */
    #define MC_RGM_FES_F_JTAG_FUNC_MASK32           ((uint32)0x00000020U)
    /* Flag for NMI WKPU reset */
    #define MC_RGM_FES_F_NMI_WKPU_MASK32            ((uint32)0x00000010U)
    /* Flag for HSM Functional reset */
    #define MC_RGM_FES_F_HSM_FUNC_MASK32            ((uint32)0x00000004U)

#elif (IPV_MC == IPV_MC_05_00_00_10)

    /* Flag for SWT2 timeout reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FES_F_SWT2_RST_REQ_MASK32        ((uint32)0x08000000U)
    /* Flag for CM0 software reset */
    #define MC_RGM_FES_F_CM0_RST_REQ_MASK32         ((uint32)0x04000000U)
    /* Flag for LVD LV PD2 COLD reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FES_F_LVD_LV_PD2_COLD_MASK32     ((uint32)0x00008000U)
    /* Flag for HVD VDD LV PD2 reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FES_F_HVD_VDD_LV_PD2_MASK32      ((uint32)0x00004000U)
    /* Flag for FCCU Soft reaction reset */
    #define MC_RGM_FES_F_FCCU_SOFT_MASK32           ((uint32)0x00000200U)
    /* Flag for FCCU Hard reaction reset */
    #define MC_RGM_FES_F_FCCU_HARD_MASK32           ((uint32)0x00000100U)
    /* Flag for FXOSC frequency out-of-range */
    #define MC_RGM_FES_F_FXOSC_OR_MASK32            ((uint32)0x00000080U)
    /* Flag for Self Test done reset */
    #define MC_RGM_FES_F_ST_DONE_MASK32             ((uint32)0x00000040U)
    /* Flag for JTAG Functional reset */
    #define MC_RGM_FES_F_JTAG_FUNC_MASK32           ((uint32)0x00000020U)
    /* Flag for CM0 LOCKUP reset */
    #define MC_RGM_FES_F_CM0_LOCKUP_MASK32          ((uint32)0x00000010U)
    /* Flag for CM4 LOCKUP reset */
    #define MC_RGM_FES_F_CM4_LOCKUP_MASK32          ((uint32)0x00040000U)
    /* Flag for SWT0 timeout reset */
    #define MC_RGM_FES_F_SWT0_RST_REQ_MASK32        ((uint32)0x20000000U)
    /* Flag for SWT1 timeout reset */
    #define MC_RGM_FES_F_SWT1_RST_REQ_MASK32        ((uint32)0x10000000U)

#else

    /* Flag for JTAG 'functional' reset */
    #define MC_RGM_FES_F_JTAG_FUNC_MASK32           ((uint32)0x00000400U)
    /* Flag for FCCU soft reaction */
    #define MC_RGM_FES_F_FCCU_SOFT_MASK32           ((uint32)0x00000040U)
    /* Flag for FCCU hard reaction reset */
    #define MC_RGM_FES_F_FCCU_HARD_MASK32           ((uint32)0x00000020U)
    /* Flag for self test completed */
    #define MC_RGM_FES_F_ST_DONE_MASK32             ((uint32)0x00000004U)
    
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */


/* Flag for JTAG or debug reset */
#define MC_RGM_FES_F_JTAG_OR_DBG_MASK32         ((uint32)0x00000400U)

/* Flag for software 'functional' reset */
#define MC_RGM_FES_F_SOFT_FUNC_MASK32           ((uint32)0x00000008U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define MC_RGM_FES_F_ESR1_MASK32            ((uint32)0x00000002U)
    #define MC_RGM_FES_F_ESR0_MASK32            ((uint32)0x00000001U)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_10) || \
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_04_06_05_00) || \
     (IPV_MC == IPV_MC_06_00_00_10) \
    )
    /* Flag for external reset */
    #define MC_RGM_FES_F_EXR_MASK32             ((uint32)0x00000001U)
#endif


/***********************************************/
/***************** MC_RGM_FERD *****************/
/***********************************************/
#if (IPV_MC == IPV_MC_04_04_01_00)
    /* used bits mask */
    #define MC_RGM_FERD_RWBITS_MASK32           ((uint32)0x0180046CU)
#elif (IPV_MC == IPV_MC_04_03_00_00)
    /* used bits mask */
    #define MC_RGM_FERD_RWBITS_MASK32           ((uint32)0x01800400U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* used bits mask */
    #define MC_RGM_FERD_RWBITS_MASK32           ((uint32)0x01800002U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* used bits mask */
    #define MC_RGM_FERD_RWBITS_MASK32           ((uint32)0x01800000U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    /* used bits mask */
    #define MC_RGM_FERD_RWBITS_MASK32           ((uint32)0x00800400U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* used bits mask */
    #define MC_RGM_FERD_RWBITS_MASK32           ((uint32)0x0004C0B0U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* used bits mask */
    #define MC_RGM_FERD_RWBITS_MASK32           ((uint32)0x00027CB0U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_RGM_FERD_RWBITS_MASK32           ((uint32)0x00000400U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    /* reserved bits mask */
    #define MC_RGM_FERD_RESBITS_MASK32              ((uint32)0x00010000U)
#else
    /* reserved bits mask */
    #define MC_RGM_FERD_RESBITS_MASK32              ((uint32)0x00000000U)
#endif

#define MC_RGM_FERD_D_JTAG_OR_DBG_MASK32        ((uint32)0x00000400U)

#if (IPV_MC == IPV_MC_05_00_00_10)
    /* Disable LVW PD2 reset */
    #define MC_RGM_FERD_D_LVW_PD2_MASK32           ((uint32)0x00010000U)
    /* Disable LVD LV PD2 COLD reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FERD_D_LVD_LV_PD2_COLD_MASK32   ((uint32)0x00008000U)
    /* Disable HVD VDD LV PD2 reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FERD_D_HVD_VDD_LV_PD2_MASK32    ((uint32)0x00004000U)
    /* Disable FXOSC frequency out-of-range */
    #define MC_RGM_FERD_D_FXOSC_OR_MASK32          ((uint32)0x00000080U)
    /* Disable JTAG Functional reset */
    #define MC_RGM_FERD_D_JTAG_FUNC_MASK32         ((uint32)0x00000020U)
    /* Disable CM0 LOCKUP reset */
    #define MC_RGM_FERD_D_CM0_LOCKUP_MASK32        ((uint32)0x00000010U)
    /* Disable CM4 LOCKUP reset */
    #define MC_RGM_FERD_D_CM4_LOCKUP_MASK32        ((uint32)0x00040000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */


#if (IPV_MC == IPV_MC_05_00_00_07)
    /* Disable LVD LV PD2 COLD reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FERD_D_LVD_LV_PD2_COLD_MASK32   ((uint32)0x00020000U)
    /* Disable HVD LV COLD reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FERD_D_HVD_LV_COLD_MASK32       ((uint32)0x00004000U)
    /* Disable LVD IO A HI reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FERD_D_LVD_IO_A_HI_MASK32       ((uint32)0x00002000U)
    /* Disable Z2 Debug Rreset */
    #define MC_RGM_FERD_D_Z2_DBG_MASK32            ((uint32)0x00001000U)
    /* Disable Z4B Debug Reset */
    #define MC_RGM_FERD_D_Z4B_DBG_MASK32           ((uint32)0x00000800U)
    /* Disable Z4A Debug Reset */
    #define MC_RGM_FERD_D_Z4A_DBG_MASK32           ((uint32)0x00000400U)
    /* Disable OSC Frequency less than RC */
    #define MC_RGM_FERD_D_CMU_OLR_MASK32           ((uint32)0x00000080U)
    /* Disable JTAG Functional reset */
    #define MC_RGM_FERD_D_JTAG_FUNC_MASK32         ((uint32)0x00000020U)
    /* Disable Non Maskable Interrupt from Wakeup Unit */
    #define MC_RGM_FERD_D_NMI_WKPU_MASK32          ((uint32)0x00000010U)
#endif /* (IPV_MC == IPV_MC_05_00_00_07) */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    /* Disable voltage out of range 'functional' reset */
    #define MC_RGM_FERD_D_VOR_FUNC_MASK32           ((uint32)0x01000000U)
#endif

/* Disable temperature sensor 'functional' reset */
#define MC_RGM_FERD_D_TSR_FUNC_MASK32           ((uint32)0x00800000U)

#if ((IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* Disable JTAG 'functional' reset */
    #define MC_RGM_FERD_D_JTAG_FUNC_MASK32          ((uint32)0x00000400U)
#endif /* ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00)) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* Disable ESR1 External Reset */
    #define MC_RGM_FERD_D_ESR1_MASK32               ((uint32)0x00000002U)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

#if (IPV_MC == IPV_MC_04_04_01_00)
    /* Disable FCCU soft reaction */
    #define MC_RGM_FERD_D_FCCU_SOFT_MASK32          ((uint32)0x00000040U)
    /* Disable FCCU hard reaction reset */
    #define MC_RGM_FERD_D_FCCU_HARD_MASK32          ((uint32)0x00000020U)
    /* Disable software 'functional' reset */
    #define MC_RGM_FERD_D_SOFT_FUNC_MASK32          ((uint32)0x00000008U)
    /* Disable self test completed */
    #define MC_RGM_FERD_D_ST_DONE_MASK32            ((uint32)0x00000004U)
#endif /* (IPV_MC == IPV_MC_04_04_01_00) */


/***********************************************/
/***************** MC_RGM_FEAR *****************/
/***********************************************/
#if ((IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* used bits mask */
    #define MC_RGM_FEAR_RWBITS_MASK32               ((uint32)0x01800400U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* used bits mask */
    #define MC_RGM_FEAR_RWBITS_MASK32               ((uint32)0x01800002U)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* used bits mask */
    #define MC_RGM_FEAR_RWBITS_MASK32               ((uint32)0x01800000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* used bits mask */
    #define MC_RGM_FEAR_RWBITS_MASK32               ((uint32)0x0000C020U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* used bits mask */
    #define MC_RGM_FEAR_RWBITS_MASK32               ((uint32)0x00027CB0U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* used bits mask */
    #define MC_RGM_FEAR_RWBITS_MASK32               ((uint32)0x00000000U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    /* reserved bits mask */
    #define MC_RGM_FEAR_RESBITS_MASK32              ((uint32)0x00010000U)
#else
    /* reserved bits mask */
    #define MC_RGM_FEAR_RESBITS_MASK32              ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

/* Alternate Request for voltage out of range 'functional' reset */
#define MC_RGM_FEAR_AR_VOR_FUNC_MASK32          ((uint32)0x01000000U)
/* Alternate Request for temperature sensor 'functional' reset */
#define MC_RGM_FEAR_AR_TSR_FUNC_MASK32          ((uint32)0x00800000U)

#if ((IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* Alternate Request for JTAG 'functional' reset */
    #define MC_RGM_FEAR_AR_JTAG_FUNC_MASK32         ((uint32)0x00000400U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* Alternate Request for ESR1 External Reset */
    #define MC_RGM_FEAR_AR_ESR1_MASK32              ((uint32)0x00000002U)
#endif


#if (IPV_MC == IPV_MC_05_00_00_10)
    /* Alternate Request for LVD_LV_PD2_COLD */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FEAR_AR_LVD_LV_PD2_COLD_MASK32       ((uint32)0x00008000U)
    /* Alternate Request for HVD VDD LV PD2 reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FEAR_AR_HVD_VDD_LV_PD2_MASK32        ((uint32)0x00004000U)
    /* Alternate request FXOSC frequency out-of-range */
    #define MC_RGM_FEAR_AR_FXOSC_OR_MASK32              ((uint32)0x00000080U)
    /* Alternate request for JTAG Functional reset */
    #define MC_RGM_FEAR_AR_JTAG_FUNC_MASK32             ((uint32)0x00000020U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_05_00_00_07)
    /* Alternate Request for LVD_LV_PD2_COLD */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FEAR_AR_LVD_LV_PD2_COLD_MASK32       ((uint32)0x00020000U)
    /* Alternate Request for HVD_LV_PD2_COLD */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FEAR_AR_HVD_LV_COLD_MASK32       ((uint32)0x00004000U)
    /* Alternate request for LVD IO A HI reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FEAR_AR_LVD_IO_A_HI_MASK32           ((uint32)0x00002000U)
    /* Alternate Request for Z2 Debug Reset */
    #define MC_RGM_FEAR_AR_Z2_DBG_MASK32                ((uint32)0x00001000U)
    /* Alternate Request for Z4B Debug Reset */
    #define MC_RGM_FEAR_AR_Z4B_DBG_MASK32               ((uint32)0x00000800U)
    /* Alternate Request for Z4A Debug Reset */
    #define MC_RGM_FEAR_AR_Z4A_DBG_MASK32               ((uint32)0x00000400U)
    /* Alternate Request for OSC Frequency less than RC */
    #define MC_RGM_FEAR_AR_CMU_OLR_MASK32               ((uint32)0x00000080U)
    /* Alternate request for JTAG Functional reset */
    #define MC_RGM_FEAR_AR_JTAG_FUNC_MASK32             ((uint32)0x00000020U)
    /* Alternate Request for Non Maskable Interrupt from Wakeup Unit */
    #define MC_RGM_FEAR_AR_NMI_WKPU_MASK32              ((uint32)0x00000010U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

/***********************************************/
/***************** MC_RGM_FBRE *****************/
/***********************************************/
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00))
    /* used bits mask */
    #define MC_RGM_FBRE_RWBITS_MASK32               ((uint32)0x01800468U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* used bits mask */
    #define MC_RGM_FBRE_RWBITS_MASK32               ((uint32)0x0180846AU)
#elif (IPV_MC == IPV_MC_04_06_01_00)
    /* used bits mask */
    #define MC_RGM_FBRE_RWBITS_MASK32               ((uint32)0x01800468U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    /* used bits mask */
    #define MC_RGM_FBRE_RWBITS_MASK32               ((uint32)0x00800468U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* used bits mask */
    #define MC_RGM_FBRE_RWBITS_MASK32               ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* used bits mask */
    #define MC_RGM_FBRE_RWBITS_MASK32               ((uint32)0x00021F7CU)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* used bits mask */
    #define MC_RGM_FBRE_RWBITS_MASK32               ((uint32)0x0000846CU)
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_06_00_00_10) \
    )
    /* reserved bits mask */
    #define MC_RGM_FBRE_RESBITS_MASK32              ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* reserved bits mask */
    #define MC_RGM_FBRE_RESBITS_MASK32              ((uint32)0x00000040U)
#elif (IPV_MC == IPV_MC_04_06_05_00)
    /* reserved bits mask */
    #define MC_RGM_FBRE_RESBITS_MASK32              ((uint32)0x01000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* reserved bits mask */
    #define MC_RGM_FBRE_RESBITS_MASK32              ((uint32)0x00016000U)
#endif

/* Bidirectional Reset Enable for voltage out of range 'functional' reset */
#define MG_RGM_FBRE_BE_VOR_FUNC_MASK32          ((uint32)0x01000000U)
/* Bidirectional Reset Enable for temperature sensor 'functional' reset */
#define MG_RGM_FBRE_BE_TSR_FUNC_MASK32          ((uint32)0x00800000U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* Bidirectional Reset Enable for HSM functional reset */
    #define MG_RGM_FBRE_BE_HSM_FUNC_MASK32          ((uint32)0x00008000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* Bidirectional Reset Enable for HSM functional reset */
    #define MG_RGM_FBRE_BE_HSM_FUNC_MASK32          ((uint32)0x00000004U)
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* Bidirectional Reset Enable for SWT4 timeout reset */
    #define MG_RGM_FBRE_BE_SWT4_MASK32              ((uint32)0x00008000U)
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)

    /* Bidirectional Reset Enable for PD2 LVD at Cold Point */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MG_RGM_FBRE_BE_LVD_LV_PD2_COLD_MASK32   ((uint32)0x00020000U)
    /* Bidirectional Reset Enable for Z2 debug reset */
    #define MG_RGM_FBRE_BE_Z2_DBG_MASK32            ((uint32)0x00001000U)
    /* Bidirectional Reset Enable for Z4B debug reset */
    #define MG_RGM_FBRE_BE_Z4B_DBG_MASK32           ((uint32)0x00000800U)
    /* Bidirectional Reset Enable for Z4A debug reset */
    #define MG_RGM_FBRE_BE_Z4A_DBG_MASK32           ((uint32)0x00000400U)
    /* Bidirectional Reset Enable for FCCU SHORT reaction reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MG_RGM_FBRE_BE_FCCU_SHORT_MASK32        ((uint32)0x00000200U)
    /* Bidirectional Reset Enable for FCCU LONG reaction reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MG_RGM_FBRE_BE_FCCU_LONG_MASK32         ((uint32)0x00000100U)
    /* Bidirectional Reset Enable for OSC Frequency less than RC */
    #define MG_RGM_FBRE_BE_CMU_OLR_MASK32           ((uint32)0x00000080U)
    /* Bidirectional Reset Enable for JTAG Functional reset */
    #define MG_RGM_FBRE_BE_JTAG_FUNC_MASK32         ((uint32)0x00000020U)
    /* Bidirectional Reset Enable for Non Maskable Interrupt from Wakeup Unit */
    #define MG_RGM_FBRE_BE_NMI_WKPU_MASK32          ((uint32)0x00000010U)

#elif (IPV_MC == IPV_MC_05_00_00_10)

    /* Bidirectional Reset Enable for SWT2 timeout reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MG_RGM_FBRE_BE_SWT2_RST_REQ_MASK32      ((uint32)0x08000000U)
    /* Bidirectional Reset Enable for CM0 software reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MG_RGM_FBRE_BE_CM0_RST_REQ_MASK32       ((uint32)0x04000000U)
    /* Bidirectional Reset Enable for LVW PD2 reset */
    #define MG_RGM_FBRE_BE_LVW_PD2_MASK32           ((uint32)0x00010000U)
    /* Bidirectional Reset Enable for LVD LV PD2 COLD reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MG_RGM_FBRE_BE_LVD_LV_PD2_COLD_MASK32   ((uint32)0x00008000U)
    /* Bidirectional Reset Enable for HVD VDD LV PD2 reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MG_RGM_FBRE_BE_HVD_VDD_LV_PD2_MASK32    ((uint32)0x00004000U)
    /* Bidirectional Reset Enable for LVD IO A HI reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MG_RGM_FBRE_BE_LVD_IO_A_HI_MASK32       ((uint32)0x00002000U)
    /* Bidirectional Reset Enable for FCCU Soft reaction reset */
    #define MG_RGM_FBRE_BE_FCCU_SOFT_MASK32         ((uint32)0x00000200U)
    /* Bidirectional Reset Enable for FCCU Hard reaction reset */
    #define MG_RGM_FBRE_BE_FCCU_HARD_MASK32         ((uint32)0x00000100U)
    /* Bidirectional Reset Enable for FXOSC frequency out-of-range */
    #define MG_RGM_FBRE_BE_FXOSC_OR_MASK32          ((uint32)0x00000080U)
    /* Bidirectional Reset Enable for Self Test done reset */
    #define MG_RGM_FBRE_BE_ST_DONE_MASK32           ((uint32)0x00000040U)
    /* Bidirectional Reset Enable for JTAG Functional reset */
    #define MG_RGM_FBRE_BE_JTAG_FUNC_MASK32         ((uint32)0x00000020U)

#else

    /* Bidirectional Reset Enable for JTAG 'functional' reset */
    #define MG_RGM_FBRE_BE_JTAG_FUNC_MASK32         ((uint32)0x00000400U)
    /* Bidirectional Reset Enable for FCCU soft reaction */
    #define MG_RGM_FBRE_BE_FCCU_SOFT_MASK32         ((uint32)0x00000040U)
    /* Bidirectional Reset Enable for a FCCU hard reaction */
    #define MG_RGM_FBRE_BE_FCCU_HARD_MASK32         ((uint32)0x00000020U)

#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

/* Bidirectional Reset Enable for JTAG or debug reset */
/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MG_RGM_FBRE_BE_JTAG_OR_DBG_MASK32       ((uint32)0x00000400U)

/* Bidirectional Reset Enable for software 'functional' reset */
#define MG_RGM_FBRE_BE_SOFT_FUNC_MASK32         ((uint32)0x00000008U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* Bidirectional Reset Enable for ESR1 External Reset */
    #define MG_RGM_FBRE_BE_ESR1_MASK32              ((uint32)0x00000002U)
#endif

#if ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_06_00_00_10))
    /* Bidirectional Reset Enable for Self Test Completed 'Functional' Reset */
    #define MG_RGM_FBRE_BE_ST_DONE_MASK32           ((uint32)0x00000004U)
#endif /* (IPV_MC == IPV_MC_04_06_01_00) */

/* Bidirectional Reset Enable for ESR0 External Reset */
#define MG_RGM_FBRE_BE_ESR0_MASK32              ((uint32)0x00000001U)

/***********************************************/
/***************** MC_RGM_FESS *****************/
/***********************************************/
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* used bits mask */
    #define MC_RGM_FESS_RWBITS_MASK32               ((uint32)0x00800409U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* used bits mask */
    #define MC_RGM_FESS_RWBITS_MASK32               ((uint32)0x0180040BU)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* used bits mask */
    #define MC_RGM_FESS_RWBITS_MASK32               ((uint32)0x3C04C0A8U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* used bits mask */
    #define MC_RGM_FESS_RWBITS_MASK32               ((uint32)0x00027CB9U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* used bits mask */
    #define MC_RGM_FESS_RWBITS_MASK32               ((uint32)0x00008409U)
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_06_01_00))
    /* reserved bits mask */
    #define MC_RGM_FESS_RESBITS_MASK32              ((uint32)0x00000040U)
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00) || \
       (IPV_MC == IPV_MC_06_00_00_10) \
      )
    /* reserved bits mask */
    #define MC_RGM_FESS_RESBITS_MASK32              ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* reserved bits mask */
    #define MC_RGM_FESS_RESBITS_MASK32              ((uint32)0x00000200U)
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* reserved bits mask */
    #define MC_RGM_FESS_RESBITS_MASK32              ((uint32)0x00008040U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* reserved bits mask */
    #define MC_RGM_FESS_RESBITS_MASK32              ((uint32)0x00000204U)
#endif

/* Short Sequence for voltage out of range 'functional' reset */
#define MC_RGM_FESS_SS_VOR_FUNC_MASK32          ((uint32)0x01000000U)
/* Short Sequence for temperature sensor 'functional' reset */
#define MC_RGM_FESS_SS_TSR_FUNC_MASK32          ((uint32)0x00800000U)

#if (IPV_MC == IPV_MC_05_00_00_07)

    /* Short Sequence for PD2 LVD at Cold Point */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FESS_SS_LVD_LV_PD2_COLD_MASK32       ((uint32)0x00020000U)
    /* Short Sequence for High Voltage Detect IOs */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FESS_SS_HVD_LV_COLD_MASK32           ((uint32)0x00004000U)
    /* Short Sequence for Low Voltage Detect IOs */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FESS_SS_LVD_IO_A_HI_MASK32           ((uint32)0x00002000U)
    /* Short Sequence for Z2 Debug Reset */
    #define MG_RGM_FESS_SS_Z2_DBG_MASK32                ((uint32)0x00001000U)
    /* Short Sequence for Z4B Debug Reset */
    #define MG_RGM_FESS_SS_Z4B_DBG_MASK32               ((uint32)0x00000800U)
    /* Short Sequence for Z4A Debug Reset */
    #define MG_RGM_FESS_SS_Z4A_DBG_MASK32               ((uint32)0x00000400U)
    /* Short Sequence for OSC Frequency less than RC */
    #define MG_RGM_FESS_SS_CMU_OLR_MASK32               ((uint32)0x00000080U)
    /* Short Sequence for JTAG Functional Reset */
    #define MC_RGM_FESS_SS_JTAG_FUNC_MASK32             ((uint32)0x00000020U)
    /* Short Sequence for Non Maskable Interrupt 3 Wakeup Unit */
    #define MG_RGM_FESS_SS_NMI_WKPU_MASK32              ((uint32)0x00000010U)

#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* Short Sequence for SWT2 timeout reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FESS_SS_SWT2_RST_REQ_MASK32      ((uint32)0x08000000U)
    /* Short Sequence for CM0 sofware reset */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FESS_SS_CM0_RST_REQ_MASK32       ((uint32)0x04000000U)
    /* Short Sequence for SS_LVD_LV_PD2_COLD */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FESS_SS_LVD_LV_PD2_COLD_MASK32   ((uint32)0x00008000U)
    /* Short Sequence for SS_HVD_VDD_LV_PD2 */
    /** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
    #define MC_RGM_FESS_SS_HVD_VDD_LV_PD2_MASK32    ((uint32)0x00004000U)
    /* Short Sequence for FCCU Soft reaction reset */
    #define MC_RGM_FESS_SS_FCCU_SOFT_MASK32         ((uint32)0x00000200U)
    /* Short Sequence for FCCU Hard reaction reset */
    #define MC_RGM_FESS_SS_FCCU_HARD_MASK32         ((uint32)0x00000100U)
    /* Short Sequence for FXOSC frequency out-of-range */
    #define MC_RGM_FESS_SS_FXOSC_OR_MASK32          ((uint32)0x00000080U)
    /* Short Sequence for Self Test done reset */
    #define MC_RGM_FESS_SS_ST_DONE_MASK32           ((uint32)0x00000040U)
    /* Short Sequence for JTAG Functional reset */
    #define MC_RGM_FESS_SS_JTAG_FUNC_MASK32         ((uint32)0x00000020U)
    /* Short Sequence for CM4 LOCKUP */
    #define MC_RGM_FESS_SS_CM4_LOCKUP_MASK32        ((uint32)0x00040000U)
    /* Short Sequence for SWT0 timeout reset */
    #define MC_RGM_FESS_SS_SWT0_RST_REQ_MASK32      ((uint32)0x20000000U)
    /* Short Sequence for SWT1 timeout reset */
    #define MC_RGM_FESS_SS_SWT1_RST_REQ_MASK32      ((uint32)0x10000000U)
#else
    /* Short Sequence for JTAG 'functional' reset */
    #define MC_RGM_FESS_SS_JTAG_FUNC_MASK32         ((uint32)0x00000400U)
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* Short Sequence for SWT4 timeout reset */
    #define MC_RGM_FESS_SS_SWT4_MASK32              ((uint32)0x00008000U)
    /* Short Sequence for JTAG or DBG reset */
    #define MC_RGM_FESS_SS_JTAG_OR_DBG_MASK32       ((uint32)0x00000400U)
    /* Short Sequence for external reset */
    #define MC_RGM_FESS_SS_EXT_RST_MASK32           ((uint32)0x00000001U)
#endif

/* Short Sequence for software 'functional' reset */
#define MC_RGM_FESS_SS_SOFT_FUNC_MASK32         ((uint32)0x00000008U)

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* Short Sequence for ESR1 External Reset */
    #define MC_RGM_FESS_SS_ESR1_MASK32              ((uint32)0x00000002U)
    /* Short Sequence for ESR0 External Reset */
    #define MC_RGM_FESS_SS_ESR0_MASK32              ((uint32)0x00000001U)
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) ||\
     (IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07) \
    )
/* Short Sequence for EXR External Reset */
#define MC_RGM_FESS_SS_EXR_MASK32               ((uint32)0x00000001U)
#endif

/***********************************************/
/***************** MC_RGM_EROEC ****************/
/***********************************************/
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
#define MC_RGM_EROEC_RWBITS_MASK32              ((uint32)0x00000001U)
#define MC_RGM_EROEC_RESBITS_MASK32             ((uint32)0x00000000U)

/* External Reset Input Status */
#define MC_RGM_EROEC_ERIS_MASK32                ((uint32)0x00000002U)
/* External Reset Output Assertion Control */
#define MC_RGM_EROEC_EROEC_MASK32               ((uint32)0x00000001U)
#endif


/***********************************************/
/*************** MC_RGM_DDR_HE *****************/
/***********************************************/
#define MC_RGM_DDR_HE_RWBITS_MASK32              ((uint32)0xFFFF0001U)

/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_RGM_DDR_HE_HNDSHK_TO_VAL_MASK32       ((uint32)0xFFFF0000U)
/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_RGM_DDR_HE_HNDSHK_TO_VAL_SHIFT32      ((uint32)16U)

#define MC_RGM_DDR_HE_HNDSHK_EN_MASK32           ((uint32)0x00000001U)

/***********************************************/
/*************** MC_RGM_DDR_HS *****************/
/***********************************************/
#define MC_RGM_DDR_HS_RWBITS_MASK32              ((uint32)0x00000002U)

/** @violates @ref REG_ESYS_MC_RGM_h_REF_1 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_RGM_DDR_HS_HNDSHK_DONE_MASK32         ((uint32)0x00000002U)

/***********************************************/
/*************** MC_RGM_FRHE *******************/
/***********************************************/
#define MC_RGM_FRHE_RWBITS_MASK32              ((uint32)0x0000846DU)

#define MC_RGM_FRHE_HE_SWT4_MASK32             ((uint32)0x00008000U)
#define MC_RGM_FRHE_HE_JTAG_OR_DBG_MASK32      ((uint32)0x00000400U)
#define MC_RGM_FRHE_HE_FCCU_SOFT_MASK32        ((uint32)0x00000040U)
#define MC_RGM_FRHE_HE_FCCU_HARD_MASK32        ((uint32)0x00000020U)
#define MC_RGM_FRHE_HE_SOFT_FUNC_MASK32        ((uint32)0x00000008U)
#define MC_RGM_FRHE_HE_ST_DONE_MASK32          ((uint32)0x00000004U)
#define MC_RGM_FRHE_HE_EXT_RST_MASK32          ((uint32)0x00000001U)


/***********************************************/
/***************  MC_RGM_FRET  *****************/
/***********************************************/
#define MC_RGM_FRET_RWBITS_MASK8                ((uint8)0x0FU)
#define MC_RGM_FRET_RESBITS_MASK8               ((uint8)0x00U)

/***********************************************/
/***************  MC_RGM_DRET  *****************/
/***********************************************/
#define MC_RGM_DRET_RWBITS_MASK8                ((uint8)0x0FU)
#define MC_RGM_DRET_RESBITS_MASK8               ((uint8)0x00U)

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

#endif /* REG_ESYS_MC_RGM_H */

/** @} */
