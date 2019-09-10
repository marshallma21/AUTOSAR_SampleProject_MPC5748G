/**
*   @file    Reg_eSys_PLLDIG.h
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

#ifndef REG_ESYS_PLLDIG_H
#define REG_ESYS_PLLDIG_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_PLLDIG_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "Mcu_PLLDIG_IPVersion.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define REG_ESYS_PLLDIG_VENDOR_ID                       43
#define REG_ESYS_PLLDIG_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_PLLDIG_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_PLLDIG_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_PLLDIG_SW_MAJOR_VERSION                1
#define REG_ESYS_PLLDIG_SW_MINOR_VERSION                0
#define REG_ESYS_PLLDIG_SW_PATCH_VERSION                0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_PLLDIG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_PLLDIG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_PLLDIG.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_PLLDIG_IPVersion header file are from the same vendor */
#if (REG_ESYS_PLLDIG_VENDOR_ID != MCU_PLLDIG_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_PLLDIG.h and Mcu_PLLDIG_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_PLLDIG_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_PLLDIG_AR_RELEASE_MAJOR_VERSION != \
      MCU_PLLDIG_IPVERSION_AR_RELEASE_MAJOR_VERSION \
     ) || \
     (REG_ESYS_PLLDIG_AR_RELEASE_MINOR_VERSION != \
      MCU_PLLDIG_IPVERSION_AR_RELEASE_MINOR_VERSION \
     ) || \
     (REG_ESYS_PLLDIG_AR_RELEASE_REVISION_VERSION != \
      MCU_PLLDIG_IPVERSION_AR_RELEASE_REVISION_VERSION \
     ) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_PLLDIG.h and Mcu_PLLDIG_IPVersion.h are different"
#endif
/* Check if source file and Mcu_PLLDIG_IPVersion header file are of the same Software version */
#if ((REG_ESYS_PLLDIG_SW_MAJOR_VERSION != MCU_PLLDIG_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_PLLDIG_SW_MINOR_VERSION != MCU_PLLDIG_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_PLLDIG_SW_PATCH_VERSION != MCU_PLLDIG_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_PLLDIG.h and Mcu_PLLDIG_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
    /* register definitions */
    /* PLLDIG PLL0 Control Register */
    #define PLLDIG_PLL0CR_ADDR32                ((uint32)(PLLDIG_BASEADDR + (uint32)0x00000000U))
    /* PLLDIG PLL0 Status Register */
    #define PLLDIG_PLL0SR_ADDR32                ((uint32)(PLLDIG_BASEADDR + (uint32)0x00000004U))
    /* PLLDIG PLL0 Divider Register */
    #define PLLDIG_PLL0DV_ADDR32                ((uint32)(PLLDIG_BASEADDR + (uint32)0x00000008U))
    /* PLLDIG PLL1 Control Register */
    #define PLLDIG_PLL1CR_ADDR32                ((uint32)(PLLDIG_BASEADDR + (uint32)0x00000020U))
    /* PLLDIG PLL1 Status Register */
    #define PLLDIG_PLL1SR_ADDR32                ((uint32)(PLLDIG_BASEADDR + (uint32)0x00000024U))
    /* PLLDIG PLL1 Divider Register */
    #define PLLDIG_PLL1DV_ADDR32                ((uint32)(PLLDIG_BASEADDR + (uint32)0x00000028U))
    /* PLLDIG PLL1 Frequency Modulation Register */
    #define PLLDIG_PLL1FM_ADDR32                ((uint32)(PLLDIG_BASEADDR + (uint32)0x0000002CU))
    /* PLLDIG PLL1 Fractional Divide Register */
    #define PLLDIG_PLL1FD_ADDR32                ((uint32)(PLLDIG_BASEADDR + (uint32)0x00000030U))

#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    /* pll 0 */
    #define PLLDIG_PLL0CAL3_ADDR32              ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000018U))
    #define PLLDIG_PLL0CR_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL0SR_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL0DV_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL0FM_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x0000002CU))
    #define PLLDIG_PLL0FD_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000030U))

    /* pll 1 */
    #define PLLDIG_PLL1CAL3_ADDR32              ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000018U))
    #define PLLDIG_PLL1CR_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL1SR_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL1DV_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL1FM_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x0000002CU))
    #define PLLDIG_PLL1FD_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000030U))

    /* pll 2 */
    #define PLLDIG_PLL2CAL3_ADDR32              ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000018U))
    #define PLLDIG_PLL2CR_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL2SR_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL2DV_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL2FM_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x0000002CU))
    #define PLLDIG_PLL2FD_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000030U))

    /* pll 3 */
    #define PLLDIG_PLL3CAL3_ADDR32              ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000018U))
    #define PLLDIG_PLL3CR_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL3SR_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL3DV_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL3FM_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x0000002CU))
    #define PLLDIG_PLL3FD_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000030U))
#endif

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL0CAL1_ADDR32              ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000038U))
#endif

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    /* pll 0 */
    #define PLLDIG_PLL0CR_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL0SR_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL0DV_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL0FM_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x0000002CU))
    #define PLLDIG_PLL0FD_ADDR32                ((uint32)(PLLDIG0_BASEADDR + (uint32)0x00000030U))
    
    /* pll 1 */
    #define PLLDIG_PLL1CR_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL1SR_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL1DV_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL1FD_ADDR32                ((uint32)(PLLDIG1_BASEADDR + (uint32)0x00000030U))

    /* pll 2 */
    #define PLLDIG_PLL2CR_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL2SR_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL2DV_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL2FD_ADDR32                ((uint32)(PLLDIG2_BASEADDR + (uint32)0x00000030U))

    /* pll 3 */
    #define PLLDIG_PLL3CR_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL3SR_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL3DV_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL3FD_ADDR32                ((uint32)(PLLDIG3_BASEADDR + (uint32)0x00000030U))
    
    /* pll 4 */
    #define PLLDIG_PLL4CR_ADDR32                ((uint32)(PLLDIG4_BASEADDR + (uint32)0x00000020U))
    #define PLLDIG_PLL4SR_ADDR32                ((uint32)(PLLDIG4_BASEADDR + (uint32)0x00000024U))
    #define PLLDIG_PLL4DV_ADDR32                ((uint32)(PLLDIG4_BASEADDR + (uint32)0x00000028U))
    #define PLLDIG_PLL4FD_ADDR32                ((uint32)(PLLDIG4_BASEADDR + (uint32)0x00000030U))
#endif


/**************************************************************/
/*                 PLLDIG_PLL0CAL3                            */
/**************************************************************/
#define PLLDIG_PLL0CAL3_RWBITS_MASK32           ((uint32)0x3FFFC000U)
#define PLLDIG_PLL0CAL3_RESBITS_MASK32          ((uint32)0x00000000U)

#define PLLDIG_PLL0CAL3_MDFEN_MASK32            ((uint32)0x3FFFC000U)
#define PLLDIG_PLL0CAL3_MDFEN_SHIFT32           ((uint32)14U)

/**************************************************************/
/*                 PLLDIG_PLLCR                              */
/**************************************************************/
#define PLLDIG_PLLxCR_CLKCFG_MASK32             ((uint32)0x00000300U)

/**************************************************************/
/*                 PLLDIG_PLL0CR                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)
    #define PLLDIG_PLL0CR_RWBITS_MASK32         ((uint32)0x0000000AU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01)
    #define PLLDIG_PLL0CR_RWBITS_MASK32         ((uint32)0x00000008U)
#elif ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13))
    #define PLLDIG_PLL0CR_RWBITS_MASK32         ((uint32)0x0000008CU)
#elif (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00)
    #define PLLDIG_PLL0CR_RWBITS_MASK32         ((uint32)0x00000308U)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL0CR_RWBITS_MASK32         ((uint32)0x00000000U)
#endif

#define PLLDIG_PLL0CR_RESBITS_MASK32            ((uint32)0x00000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) \
    )
    #define PLLDIG_PLL0CR_EXPDIE_MASK32         ((uint32)0x00000080U)
#endif

#define PLLDIG_PLL0CR_LOLIE_MASK32              ((uint32)0x00000008U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13))
    #define PLLDIG_PLL0CR_LOLRE_MASK32          ((uint32)0x00000004U)
#endif

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)
    #define PLLDIG_PLL0CR_LOCIE_MASK32          ((uint32)0x00000002U)
#endif

/* Clock Configuration status */
#define PLLDIG_PLL0CR_CLKCFG_MASK32             (PLLDIG_PLLxCR_CLKCFG_MASK32)
/* PLL off */
#define PLLDIG_PLL0CR_CLKCFG_BO_U32             ((uint32)0x00000000U)
/* Normal mode with PLL running */
#define PLLDIG_PLL0CR_CLKCFG_NR_U32             (PLLDIG_PLL0CR_CLKCFG_MASK32)

/**************************************************************/
/*                 PLLDIG_PLL0SR                              */
/**************************************************************/
#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) \
    )
    #define PLLDIG_PLL0SR_RWBITS_MASK32         ((uint32)0x00000008U)
#elif ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) \
      )
    #define PLLDIG_PLL0SR_RWBITS_MASK32         ((uint32)0x00000088U)
#endif

#define PLLDIG_PLL0SR_RESBITS_MASK32            ((uint32)0x00000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) \
    )
    #define PLLDIG_PLL0SR_EXTPDF_MASK32         ((uint32)0x00000080U)
#endif

#define PLLDIG_PLL0SR_LOLF_MASK32               ((uint32)0x00000008U)
#define PLLDIG_PLL0SR_LOCK_MASK32               ((uint32)0x00000004U)

/**************************************************************/
/*                 PLLDIG_PLL0DV                              */
/**************************************************************/
#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )

    #define PLLDIG_PLL0DV_RWBITS_MASK32             ((uint32)0x783F707FU)
    #define PLLDIG_PLL0DV_RESBITS_MASK32            ((uint32)0x00000000U)

    #define PLLDIG_PLL0DV_RFDPHI1_MASK32            ((uint32)0x78000000U)
    #define PLLDIG_PLL0DV_RFDPHI1_SHIFT32           ((uint32)27U)

    #define PLLDIG_PLL0DV_RFDPHI_MASK32             ((uint32)0x003F0000U)
    #define PLLDIG_PLL0DV_RFDPHI_SHIFT32            ((uint32)16U)

    #define PLLDIG_PLL0DV_PREDIV_MASK32             ((uint32)0x00007000U)
    #define PLLDIG_PLL0DV_PREDIV_SHIFT32            ((uint32)12U)

    #define PLLDIG_PLL0DV_MFD_MASK32                ((uint32)0x0000007FU)

#elif ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
    #define PLLDIG_PLL0DV_RWBITS_MASK32             ((uint32)0x7E3F70FFU)
    #define PLLDIG_PLL0DV_RESBITS_MASK32            ((uint32)0x00000000U)

    #define PLLDIG_PLL0DV_RFDPHI1_MASK32            ((uint32)0x7E000000U)
    #define PLLDIG_PLL0DV_RFDPHI1_SHIFT32           ((uint32)25U)

    #define PLLDIG_PLL0DV_RFDPHI_MASK32             ((uint32)0x003F0000U)
    #define PLLDIG_PLL0DV_RFDPHI_SHIFT32            ((uint32)16U)

    #define PLLDIG_PLL0DV_PREDIV_MASK32             ((uint32)0x00007000U)
    #define PLLDIG_PLL0DV_PREDIV_SHIFT32            ((uint32)12U)

    #define PLLDIG_PLL0DV_MFD_MASK32                ((uint32)0x000000FFU)

#endif

/**************************************************************/
/*                 PLLDIG_PLL0FM                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL0FM_RWBITS_MASK32             ((uint32)0x43FF07FFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL0FM_RWBITS_MASK32             ((uint32)0x63FF07FFU)
#else
    #define PLLDIG_PLL0FM_RWBITS_MASK32             ((uint32)0x7FFF07FFU)
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */

#define PLLDIG_PLL0FM_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL0FM_SSCGBYP_MASK32            ((uint32)0x40000000U)

#define PLLDIG_PLL0FM_MODSEL_MASK32             ((uint32)0x20000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
    #define PLLDIG_PLL0FM_MODPRD_MASK32             ((uint32)0x03FF0000U)
    #define PLLDIG_PLL0FM_STEPSIZE_MASK32           (PLLDIG_PLL0FM_MODPRD_MASK32)
#else
    #define PLLDIG_PLL0FM_MODPRD_MASK32             ((uint32)0x1FFF0000U)
#endif /* (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) */

#define PLLDIG_PLL0FM_MODPRD_SHIFT32            ((uint32)16U)
#define PLLDIG_PLL0FM_STEPSIZE_SHIFT32          (PLLDIG_PLL0FM_MODPRD_SHIFT32)

#define PLLDIG_PLL0FM_INCSTP_MASK32             ((uint32)0x000007FFU)
#define PLLDIG_PLL0FM_STEPNO_MASK32             (PLLDIG_PLL0FM_INCSTP_MASK32)

#define PLLDIG_PLL0FM_INCSTP_SHIFT32            ((uint32)0U)
#define PLLDIG_PLL0FM_STEPNO_SHIFT32            (PLLDIG_PLL0FM_INCSTP_SHIFT32)


/**************************************************************/
/*                 PLLDIG_PLL0FD                              */
/**************************************************************/

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL0FD_RWBITS_MASK32             ((uint32)0x703F7FFFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL0FD_RWBITS_MASK32             ((uint32)0x40007FFFU)
#else
    #define PLLDIG_PLL0FD_RWBITS_MASK32             ((uint32)0x70037FFFU)
#endif

#define PLLDIG_PLL0FD_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL0FD_SMDEN_MASK32              ((uint32)0x40000000U)
#define PLLDIG_PLL0FD_SDM2_MASK32               ((uint32)0x20000000U)
#define PLLDIG_PLL0FD_SDM3_MASK32               ((uint32)0x10000000U)

#define PLLDIG_PLL0FD_DTHDIS_MASK32             ((uint32)0x00030000U)
#define PLLDIG_PLL0FD_DTHDIS_SHIFT32            ((uint32)16U)

#define PLLDIG_PLL0FD_MFN_MASK32                ((uint32)0x00007FFFU)
#define PLLDIG_PLL0FD_MFN_SHIFT32               ((uint32)0U)

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL0FD_DTHRCTL_MASK32                ((uint32)0x003C0000U)
    #define PLLDIG_PLL0FD_DTHRCTL_SHIFT32               ((uint32)18U)
#endif

/**************************************************************/
/*                 PLLDIG_PLL0CAL1                            */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL0CAL1_BYPCAL_MASK32             ((uint32)0x80000000U)
#endif

/**************************************************************/
/*                 PLLDIG_PLL1CAL3                            */
/**************************************************************/
#define PLLDIG_PLL1CAL3_RWBITS_MASK32           ((uint32)0x3FFFC000U)
#define PLLDIG_PLL1CAL3_RESBITS_MASK32          ((uint32)0x00000000U)

#define PLLDIG_PLL1CAL3_MDFEN_MASK32            ((uint32)0x3FFFC000U)
#define PLLDIG_PLL1CAL3_MDFEN_SHIFT32           ((uint32)14U)

/**************************************************************/
/*                 PLLDIG_PLL1CR                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)
    #define PLLDIG_PLL1CR_RWBITS_MASK32         ((uint32)0x0000000AU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01)
    #define PLLDIG_PLL1CR_RWBITS_MASK32         ((uint32)0x00000008U)
#elif ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13))
    #define PLLDIG_PLL1CR_RWBITS_MASK32         ((uint32)0x0000008CU)
#elif (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00)
    #define PLLDIG_PLL1CR_RWBITS_MASK32         ((uint32)0x00000308U)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL1CR_RWBITS_MASK32         ((uint32)0x00000008U)
#endif

#define PLLDIG_PLL1CR_RESBITS_MASK32            ((uint32)0x00000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) \
    )
    #define PLLDIG_PLL1CR_EXPDIE_MASK32         ((uint32)0x00000080U)
#endif

#define PLLDIG_PLL1CR_LOLIE_MASK32              ((uint32)0x00000008U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13))
    #define PLLDIG_PLL1CR_LOLRE_MASK32          ((uint32)0x00000004U)
#endif

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_00)
    #define PLLDIG_PLL1CR_LOCIE_MASK32          ((uint32)0x00000002U)
#endif


/* Clock Configuration status */
#define PLLDIG_PLL1CR_CLKCFG_MASK32             (PLLDIG_PLLxCR_CLKCFG_MASK32)
/* PLL off */
#define PLLDIG_PLL1CR_CLKCFG_BO_U32             ((uint32)0x00000000U)
/* Normal mode with PLL running */
#define PLLDIG_PLL1CR_CLKCFG_NR_U32             (PLLDIG_PLL1CR_CLKCFG_MASK32)

/**************************************************************/
/*                 PLLDIG_PLL1SR                              */
/**************************************************************/
#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) || \
     (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) \
    )
    #define PLLDIG_PLL1SR_RWBITS_MASK32         ((uint32)0x00000008U)
#elif ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) \
      )
    #define PLLDIG_PLL1SR_RWBITS_MASK32         ((uint32)0x00000088U)
#endif

#define PLLDIG_PLL1SR_RESBITS_MASK32            ((uint32)0x00000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) \
    )
    #define PLLDIG_PLL1SR_EXTPDF_MASK32         ((uint32)0x00000080U)
#endif

#define PLLDIG_PLL1SR_LOLF_MASK32               ((uint32)0x00000008U)
#define PLLDIG_PLL1SR_LOCK_MASK32               ((uint32)0x00000004U)

/**************************************************************/
/*                 PLLDIG_PLL1DV                              */
/**************************************************************/
#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) ||\
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )

    #define PLLDIG_PLL1DV_RWBITS_MASK32             ((uint32)0x003F007FU)
    #define PLLDIG_PLL1DV_RESBITS_MASK32            ((uint32)0x00000000U)

    #define PLLDIG_PLL1DV_RFDPHI_MASK32             ((uint32)0x003F0000U)
    #define PLLDIG_PLL1DV_RFDPHI_SHIFT32            ((uint32)16U)

    #define PLLDIG_PLL1DV_MFD_MASK32                ((uint32)0x0000007FU)

#elif ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
    #define PLLDIG_PLL1DV_RWBITS_MASK32             ((uint32)0x7E3F70FFU)
    #define PLLDIG_PLL1DV_RESBITS_MASK32            ((uint32)0x00000000U)

    #define PLLDIG_PLL1DV_RFDPHI1_MASK32            ((uint32)0x7E000000U)
    #define PLLDIG_PLL1DV_RFDPHI1_SHIFT32           ((uint32)25U)

    #define PLLDIG_PLL1DV_RFDPHI_MASK32             ((uint32)0x003F0000U)
    #define PLLDIG_PLL1DV_RFDPHI_SHIFT32            ((uint32)16U)

    #define PLLDIG_PLL1DV_PREDIV_MASK32             ((uint32)0x00007000U)
    #define PLLDIG_PLL1DV_PREDIV_SHIFT32            ((uint32)12U)

    #define PLLDIG_PLL1DV_MFD_MASK32                ((uint32)0x000000FFU)

#endif

/**************************************************************/
/*                 PLLDIG_PLL1FM                              */
/**************************************************************/
#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) ||\
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
    #define PLLDIG_PLL1FM_RWBITS_MASK32             ((uint32)0x7FFF7FFFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL1FM_RWBITS_MASK32             ((uint32)0x00000000U)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL1FM_RWBITS_MASK32             ((uint32)0x43FF07FFU)
#endif

#define PLLDIG_PLL1FM_RESBITS_MASK32                ((uint32)0x00000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) ||\
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
    #define PLLDIG_PLL1FM_MODEN_MASK32              ((uint32)0x40000000U)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL1FM_SSCGBYP_MASK32            ((uint32)0x40000000U)
#endif

#define PLLDIG_PLL1FM_MODSEL_MASK32                 ((uint32)0x20000000U)

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL1FM_MODPRD_MASK32                 ((uint32)0x03FF0000U)
    #define PLLDIG_PLL1FM_STEPSIZE_MASK32               (PLLDIG_PLL1FM_MODPRD_MASK32)
#else
    #define PLLDIG_PLL1FM_MODPRD_MASK32                 ((uint32)0x1FFF0000U)
#endif

#define PLLDIG_PLL1FM_MODPRD_SHIFT32                ((uint32)16U)
#define PLLDIG_PLL1FM_STEPSIZE_SHIFT32              (PLLDIG_PLL1FM_MODPRD_SHIFT32)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) ||\
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
    #define PLLDIG_PLL1FM_INCSTP_MASK32                 ((uint32)0x00007FFFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL1FM_INCSTP_MASK32                 ((uint32)0x000007FFU)
    #define PLLDIG_PLL1FM_STEPNO_MASK32                 (PLLDIG_PLL1FM_INCSTP_MASK32)
#endif

#define PLLDIG_PLL1FM_INCSTP_SHIFT32                ((uint32)0U)
#define PLLDIG_PLL1FM_STEPNO_SHIFT32                (PLLDIG_PLL1FM_INCSTP_SHIFT32)

/**************************************************************/
/*                 PLLDIG_PLL1FD                              */
/**************************************************************/
#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) ||\
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
    #define PLLDIG_PLL1FD_RWBITS_MASK32             ((uint32)0x40030FFFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL1FD_RWBITS_MASK32             ((uint32)0x40007FFFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL1FD_RWBITS_MASK32             ((uint32)0x703F7FFFU)
#endif

#define PLLDIG_PLL1FD_RESBITS_MASK32                ((uint32)0x00000000U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) ||\
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
    #define PLLDIG_PLL1FD_FDEN_MASK32               ((uint32)0x40000000U)
#endif

#define PLLDIG_PLL1FD_SMDEN_MASK32              ((uint32)0x40000000U)

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL1FD_SDM2_MASK32               ((uint32)0x20000000U)
    #define PLLDIG_PLL1FD_SDM3_MASK32               ((uint32)0x10000000U)
#endif

#define PLLDIG_PLL1FD_DTHDIS_MASK32                 ((uint32)0x00030000U)
#define PLLDIG_PLL1FD_DTHDIS_SHIFT32                ((uint32)16U)

#define PLLDIG_PLL1FD_DTHDIS1_MASK32                 ((uint32)0x00020000U)
#define PLLDIG_PLL1FD_DTHDIS1_SHIFT32                ((uint32)17U)

#define PLLDIG_PLL1FD_DTHDIS0_MASK32                 ((uint32)0x00010000U)
#define PLLDIG_PLL1FD_DTHDIS0_SHIFT32                ((uint32)16U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_00) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_01) ||\
     (IPV_PLLDIG == IPV_PLLDIG_02_00_04_13) || (IPV_PLLDIG == IPV_PLLDIG_01_08_61_00) \
    )
    #define PLLDIG_PLL1FD_FRCDIV_MASK32             ((uint32)0x00000FFFU)
#elif ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_23) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29))
    #define PLLDIG_PLL1FD_MFN_MASK32                ((uint32)0x00007FFFU)
    #define PLLDIG_PLL1FD_MFN_SHIFT32               ((uint32)0U)
#endif

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL1FD_DTHRCTL_MASK32                ((uint32)0x003C0000U)
    #define PLLDIG_PLL1FD_DTHRCTL_SHIFT32               ((uint32)18U)
#endif

/**************************************************************/
/*                 PLLDIG_PLL2CAL3                            */
/**************************************************************/
#define PLLDIG_PLL2CAL3_RWBITS_MASK32           ((uint32)0x3FFFC000U)
#define PLLDIG_PLL2CAL3_RESBITS_MASK32          ((uint32)0x00000000U)

#define PLLDIG_PLL2CAL3_MDFEN_MASK32            ((uint32)0x3FFFC000U)
#define PLLDIG_PLL2CAL3_MDFEN_SHIFT32           ((uint32)14U)

/**************************************************************/
/*                 PLLDIG_PLL2CR                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL2CR_RWBITS_MASK32             ((uint32)0x00000008U)
#else
    #define PLLDIG_PLL2CR_RWBITS_MASK32             ((uint32)0x00000088U)
#endif

#define PLLDIG_PLL2CR_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL2CR_EXPDIE_MASK32             ((uint32)0x00000080U)
#define PLLDIG_PLL2CR_LOLIE_MASK32              ((uint32)0x00000008U)
#define PLLDIG_PLL2CR_CLKCFG_MASK32             (PLLDIG_PLLxCR_CLKCFG_MASK32)

/* Clock Configuration status */
/* PLL off */
#define PLLDIG_PLL2CR_CLKCFG_BO_U32             ((uint32)0x00000000U)
/* Normal mode with PLL running */
#define PLLDIG_PLL2CR_CLKCFG_NR_U32             (PLLDIG_PLL2CR_CLKCFG_MASK32)

/**************************************************************/
/*                 PLLDIG_PLL2SR                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL2SR_RWBITS_MASK32             ((uint32)0x00000008U)
#else
    #define PLLDIG_PLL2SR_RWBITS_MASK32             ((uint32)0x00000088U)
#endif

#define PLLDIG_PLL2SR_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL2SR_EXTPDF_MASK32             ((uint32)0x00000080U)
#define PLLDIG_PLL2SR_LOLF_MASK32               ((uint32)0x00000008U)
#define PLLDIG_PLL2SR_LOCK_MASK32               ((uint32)0x00000004U)

/**************************************************************/
/*                 PLLDIG_PLL2DV                              */
/**************************************************************/
#define PLLDIG_PLL2DV_RWBITS_MASK32             ((uint32)0x7E3F70FFU)
#define PLLDIG_PLL2DV_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL2DV_RFDPHI1_MASK32            ((uint32)0x7E000000U)
#define PLLDIG_PLL2DV_RFDPHI1_SHIFT32           ((uint32)25U)

#define PLLDIG_PLL2DV_RFDPHI_MASK32             ((uint32)0x003F0000U)
#define PLLDIG_PLL2DV_RFDPHI_SHIFT32            ((uint32)16U)

#define PLLDIG_PLL2DV_PREDIV_MASK32             ((uint32)0x00007000U)
#define PLLDIG_PLL2DV_PREDIV_SHIFT32            ((uint32)12U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
    #define PLLDIG_PLL2DV_MFD_MASK32                ((uint32)0x000000FFU)
#else
    #define PLLDIG_PLL2DV_MFD_MASK32                ((uint32)0x0000007FU)
#endif
/**************************************************************/
/*                 PLLDIG_PLL2FM                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL2FM_RWBITS_MASK32             ((uint32)0x43FF07FFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL2FM_RWBITS_MASK32             ((uint32)0x00000000U)
#else
    #define PLLDIG_PLL2FM_RWBITS_MASK32             ((uint32)0x7FFF07FFU)
#endif

#define PLLDIG_PLL2FM_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL2FM_SSCGBYP_MASK32            ((uint32)0x40000000U)
#define PLLDIG_PLL2FM_MODSEL_MASK32             ((uint32)0x20000000U)

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL2FM_MODPRD_MASK32             ((uint32)0x03FF0000U)
    #define PLLDIG_PLL2FM_STEPSIZE_MASK32           (PLLDIG_PLL2FM_MODPRD_MASK32)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL2FM_MODPRD_MASK32             ((uint32)0x00000000U)
#else
    #define PLLDIG_PLL2FM_MODPRD_MASK32             ((uint32)0x1FFF0000U)
#endif

#define PLLDIG_PLL2FM_MODPRD_SHIFT32            ((uint32)16U)
#define PLLDIG_PLL2FM_STEPSIZE_SHIFT32          (PLLDIG_PLL2FM_MODPRD_SHIFT32)

#define PLLDIG_PLL2FM_INCSTP_MASK32             ((uint32)0x000007FFU)
#define PLLDIG_PLL2FM_STEPNO_MASK32             (PLLDIG_PLL2FM_INCSTP_MASK32)

#define PLLDIG_PLL2FM_INCSTP_SHIFT32            ((uint32)0U)
#define PLLDIG_PLL2FM_STEPNO_SHIFT32            (PLLDIG_PLL2FM_INCSTP_SHIFT32)
/**************************************************************/
/*                 PLLDIG_PLL2FD                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL2FD_RWBITS_MASK32             ((uint32)0x703F7FFFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL2FD_RWBITS_MASK32             ((uint32)0x400F7FFFU) 
#else
    #define PLLDIG_PLL2FD_RWBITS_MASK32             ((uint32)0x70037FFFU)
#endif

#define PLLDIG_PLL2FD_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL2FD_SMDEN_MASK32              ((uint32)0x40000000U)
#define PLLDIG_PLL2FD_SDM2_MASK32               ((uint32)0x20000000U)
#define PLLDIG_PLL2FD_SDM3_MASK32               ((uint32)0x10000000U)

#define PLLDIG_PLL2FD_DTHDIS_MASK32             ((uint32)0x00030000U)
#define PLLDIG_PLL2FD_DTHDIS_SHIFT32            ((uint32)16U)

#define PLLDIG_PLL2FD_MFN_MASK32                ((uint32)0x00007FFFU)
#define PLLDIG_PLL2FD_MFN_SHIFT32               ((uint32)0U)

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL2FD_DTHRCTL_MASK32                ((uint32)0x003C0000U)
    #define PLLDIG_PLL2FD_DTHRCTL_SHIFT32               ((uint32)18U)
#endif

/**************************************************************/
/*                 PLLDIG_PLL3CAL3                            */
/**************************************************************/
#define PLLDIG_PLL3CAL3_RWBITS_MASK32           ((uint32)0x3FFFC000U)
#define PLLDIG_PLL3CAL3_RESBITS_MASK32          ((uint32)0x00000000U)

#define PLLDIG_PLL3CAL3_MDFEN_MASK32            ((uint32)0x3FFFC000U)
#define PLLDIG_PLL3CAL3_MDFEN_SHIFT32           ((uint32)14U)

/**************************************************************/
/*                 PLLDIG_PLL3CR                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL3CR_RWBITS_MASK32             ((uint32)0x00000008U)
#else
    #define PLLDIG_PLL3CR_RWBITS_MASK32             ((uint32)0x00000088U)
#endif

#define PLLDIG_PLL3CR_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL3CR_EXPDIE_MASK32             ((uint32)0x00000080U)
#define PLLDIG_PLL3CR_LOLIE_MASK32              ((uint32)0x00000008U)

#define PLLDIG_PLL3CR_CLKCFG_MASK32             (PLLDIG_PLLxCR_CLKCFG_MASK32)

/* Clock Configuration status */
/* PLL off */
#define PLLDIG_PLL3CR_CLKCFG_BO_U32             ((uint32)0x00000000U)
/* Normal mode with PLL running */
#define PLLDIG_PLL3CR_CLKCFG_NR_U32             (PLLDIG_PLL3CR_CLKCFG_MASK32)

/**************************************************************/
/*                 PLLDIG_PLL3SR                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL3SR_RWBITS_MASK32             ((uint32)0x00000008U)
#else
    #define PLLDIG_PLL3SR_RWBITS_MASK32             ((uint32)0x00000088U)
#endif

#define PLLDIG_PLL3SR_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL3SR_EXTPDF_MASK32             ((uint32)0x00000080U)
#define PLLDIG_PLL3SR_LOLF_MASK32               ((uint32)0x00000008U)
#define PLLDIG_PLL3SR_LOCK_MASK32               ((uint32)0x00000004U)

/**************************************************************/
/*                 PLLDIG_PLL3DV                              */
/**************************************************************/
#define PLLDIG_PLL3DV_RWBITS_MASK32             ((uint32)0x7E3F70FFU)
#define PLLDIG_PLL3DV_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL3DV_RFDPHI1_MASK32            ((uint32)0x7E000000U)
#define PLLDIG_PLL3DV_RFDPHI1_SHIFT32           ((uint32)25U)

#define PLLDIG_PLL3DV_RFDPHI_MASK32             ((uint32)0x003F0000U)
#define PLLDIG_PLL3DV_RFDPHI_SHIFT32            ((uint32)16U)

#define PLLDIG_PLL3DV_PREDIV_MASK32             ((uint32)0x00007000U)
#define PLLDIG_PLL3DV_PREDIV_SHIFT32            ((uint32)12U)

#if ((IPV_PLLDIG == IPV_PLLDIG_02_00_04_29) || (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23))
    #define PLLDIG_PLL3DV_MFD_MASK32                ((uint32)0x000000FFU)
#else
    #define PLLDIG_PLL3DV_MFD_MASK32                ((uint32)0x0000007FU)
#endif

/**************************************************************/
/*                 PLLDIG_PLL3FM                              */
/**************************************************************/
#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL3FM_RWBITS_MASK32             ((uint32)0x43FF07FFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL3FM_RWBITS_MASK32             ((uint32)0x00000000U)
#else
    #define PLLDIG_PLL3FM_RWBITS_MASK32             ((uint32)0x7FFF07FFU)
#endif

#define PLLDIG_PLL3FM_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL3FM_SSCGBYP_MASK32            ((uint32)0x40000000U)
#define PLLDIG_PLL3FM_MODSEL_MASK32             ((uint32)0x20000000U)

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL3FM_MODPRD_MASK32             ((uint32)0x03FF0000U)
    #define PLLDIG_PLL3FM_STEPSIZE_MASK32           (PLLDIG_PLL3FM_MODPRD_MASK32)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL3FM_MODPRD_MASK32             ((uint32)0x00000000U)
#else
    #define PLLDIG_PLL3FM_MODPRD_MASK32             ((uint32)0x1FFF0000U)
#endif

#define PLLDIG_PLL3FM_MODPRD_SHIFT32            ((uint32)16U)
#define PLLDIG_PLL3FM_STEPSIZE_SHIFT32          (PLLDIG_PLL3FM_MODPRD_SHIFT32)

#define PLLDIG_PLL3FM_INCSTP_MASK32             ((uint32)0x000007FFU)
#define PLLDIG_PLL3FM_STEPNO_MASK32             (PLLDIG_PLL3FM_INCSTP_MASK32)

#define PLLDIG_PLL3FM_INCSTP_SHIFT32            ((uint32)0U)
#define PLLDIG_PLL3FM_STEPNO_SHIFT32            (PLLDIG_PLL3FM_INCSTP_SHIFT32)

/**************************************************************/
/*                 PLLDIG_PLL3FD                              */
/**************************************************************/

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL3FD_RWBITS_MASK32             ((uint32)0x703F7FFFU)
#elif (IPV_PLLDIG == IPV_PLLDIG_02_00_04_29)
    #define PLLDIG_PLL3FD_RWBITS_MASK32             ((uint32)0x40007FFFU)
#else
    #define PLLDIG_PLL3FD_RWBITS_MASK32             ((uint32)0x70037FFFU)
#endif

#define PLLDIG_PLL3FD_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL3FD_SMDEN_MASK32              ((uint32)0x40000000U)
#define PLLDIG_PLL3FD_SDM2_MASK32               ((uint32)0x20000000U)
#define PLLDIG_PLL3FD_SDM3_MASK32               ((uint32)0x10000000U)

#define PLLDIG_PLL3FD_DTHDIS_MASK32             ((uint32)0x00030000U)
#define PLLDIG_PLL3FD_DTHDIS_SHIFT32            ((uint32)16U)

#define PLLDIG_PLL3FD_MFN_MASK32                ((uint32)0x00007FFFU)
#define PLLDIG_PLL3FD_MFN_SHIFT32               ((uint32)0U)

#if (IPV_PLLDIG == IPV_PLLDIG_02_00_04_23)
    #define PLLDIG_PLL3FD_DTHRCTL_MASK32                ((uint32)0x003C0000U)
    #define PLLDIG_PLL3FD_DTHRCTL_SHIFT32               ((uint32)18U)
#endif

/**************************************************************/
/*                 PLLDIG_PLL4CR                              */
/**************************************************************/
#define PLLDIG_PLL4CR_RWBITS_MASK32             ((uint32)0x00000008U)
#define PLLDIG_PLL4CR_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL4CR_LOLIE_MASK32              ((uint32)0x00000008U)

#define PLLDIG_PLL4CR_CLKCFG_MASK32             (PLLDIG_PLLxCR_CLKCFG_MASK32)

/* Clock Configuration status */
/* PLL off */
#define PLLDIG_PLL4CR_CLKCFG_BO_U32             ((uint32)0x00000000U)
/* Normal mode with PLL running */
#define PLLDIG_PLL4CR_CLKCFG_NR_U32             (PLLDIG_PLL4CR_CLKCFG_MASK32)

/**************************************************************/
/*                 PLLDIG_PLL4SR                              */
/**************************************************************/
#define PLLDIG_PLL4SR_RWBITS_MASK32             ((uint32)0x00000008U)
#define PLLDIG_PLL4SR_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL4SR_LOLF_MASK32               ((uint32)0x00000008U)
#define PLLDIG_PLL4SR_LOCK_MASK32               ((uint32)0x00000004U)

/**************************************************************/
/*                 PLLDIG_PLL4DV                              */
/**************************************************************/
#define PLLDIG_PLL4DV_RWBITS_MASK32             ((uint32)0x7E3F70FFU)
#define PLLDIG_PLL4DV_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL4DV_RFDPHI1_MASK32            ((uint32)0x7E000000U)
#define PLLDIG_PLL4DV_RFDPHI1_SHIFT32           ((uint32)25U)

#define PLLDIG_PLL4DV_RFDPHI_MASK32             ((uint32)0x003F0000U)
#define PLLDIG_PLL4DV_RFDPHI_SHIFT32            ((uint32)16U)

#define PLLDIG_PLL4DV_PREDIV_MASK32             ((uint32)0x00007000U)
#define PLLDIG_PLL4DV_PREDIV_SHIFT32            ((uint32)12U)

#define PLLDIG_PLL4DV_MFD_MASK32                ((uint32)0x000000FFU)

/**************************************************************/
/*                 PLLDIG_PLL4FD                              */
/**************************************************************/
#define PLLDIG_PLL4FD_RWBITS_MASK32             ((uint32)0x40007FFFU)
#define PLLDIG_PLL4FD_RESBITS_MASK32            ((uint32)0x00000000U)

#define PLLDIG_PLL4FD_SMDEN_MASK32              ((uint32)0x40000000U)

#define PLLDIG_PLL4FD_MFN_MASK32                ((uint32)0x00007FFFU)
#define PLLDIG_PLL4FD_MFN_SHIFT32               ((uint32)0U)

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

#endif /* REG_ESYS_PLLDIG_H */

/** @} */

