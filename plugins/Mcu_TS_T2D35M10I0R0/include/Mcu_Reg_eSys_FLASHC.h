/**
*   @file    Reg_eSys_FLASHC.h
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


#ifndef MCU_REG_ESYS_FLASHC_H
#define MCU_REG_ESYS_FLASHC_H

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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "Mcu_FLASH_IPVersion.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_FLASHC_VENDOR_ID                           43
#define REG_ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION            4
#define REG_ESYS_FLASHC_AR_RELEASE_MINOR_VERSION            2
#define REG_ESYS_FLASHC_AR_RELEASE_REVISION_VERSION         2
#define REG_ESYS_FLASHC_SW_MAJOR_VERSION                    1
#define REG_ESYS_FLASHC_SW_MINOR_VERSION                    0
#define REG_ESYS_FLASHC_SW_PATCH_VERSION                    0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_FLASHC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_Reg_eSys_FLASHC.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and PLLDIG header file are from the same vendor */
#if (REG_ESYS_FLASHC_VENDOR_ID != MCU_FLASH_IPVERSION_VENDOR_ID)
    #error "Mcu_Reg_eSys_FLASHC.h and Mcu_FLASH_IPVersion.h have different vendor ids"
#endif
/* Check if source file and PLLDIG header file are of the same Autosar version */
#if ((REG_ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION != MCU_FLASH_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_FLASHC_AR_RELEASE_MINOR_VERSION != MCU_FLASH_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_FLASHC_AR_RELEASE_REVISION_VERSION != \
      MCU_FLASH_IPVERSION_AR_RELEASE_REVISION_VERSION \
     ) \
    )
    #error "AutoSar Version Numbers of Mcu_Reg_eSys_FLASHC.h and Mcu_FLASH_IPVersion.h are \
    different"
#endif
/* Check if source file and PLLDIG header file are of the same Software version */
#if ((REG_ESYS_FLASHC_SW_MAJOR_VERSION != MCU_FLASH_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_FLASHC_SW_MINOR_VERSION != MCU_FLASH_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_FLASHC_SW_PATCH_VERSION != MCU_FLASH_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_Reg_eSys_FLASHC.h and Mcu_FLASH_IPVersion.h are \
    different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/* PFCR0: Platform Flash Configuration Register 0. */
#define FLASHC_PFCR0_ADDR32                     ((uint32)(PFLASH_BASEADDR + (uint32)0x001CU))
/* PFCR1: Platform Flash Configuration Register 1. */
#define FLASHC_PFCR1_ADDR32                     ((uint32)(PFLASH_BASEADDR + (uint32)0x0000U))
/* PFCR2: Platform Flash Configuration Register 2. - not available */
#define FLASHC_PFCR2_ADDR32                     ((uint32)(PFLASH_BASEADDR + (uint32)0x0004U))
/* PFCR3: Platform Flash Configuration Register 3. */
#define FLASHC_PFCR3_ADDR32                     ((uint32)(PFLASH_BASEADDR + (uint32)0x0008U))
/* PFCR3: Platform Flash Configuration Register 4. */
#define FLASHC_PFCR4_ADDR32                     ((uint32)(PFLASH_BASEADDR + (uint32)0x0018U))

#if (IPV_FLASHV2 == IPV_FLASH_00_00_05_01)
    /* PFAPR: Platform Flash Access Protection Register. */
    #define FLASHC_PFAPR_ADDR32                     ((uint32)(PFLASH_BASEADDR + (uint32)0x0024U))
#elif ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || \
       (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || \
       (IPV_FLASHV2 == IPV_FLASH_25_60_86_00) || (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || \
       (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || \
       (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
      )
    /* PFAPR: Platform Flash Access Protection Register. */
    #define FLASHC_PFAPR_ADDR32                     ((uint32)(PFLASH_BASEADDR + (uint32)0x000CU))
#endif /* (IPV_FLASHV2 == IPV_FLASH_25_60_86_00) */


#if (IPV_FLASHV2 == IPV_FLASH_00_00_05_01)
    #define MCU_FLASH_B02APC_MASK32                 ((uint32)0x38000000U)
    #define MCU_FLASH_B02WWSC_MASK32                ((uint32)0x00C00000U)
    #define MCU_FLASH_B02RWSC_MASK32                ((uint32)0x000E0000U)

    #define MCU_FLASH_B02P1BCFG_MASK32              ((uint32)0x00006000U)
    #define MCU_FLASH_B02P1DPFE_MASK32              ((uint32)0x00001000U)
    #define MCU_FLASH_B02P1IPFE_MASK32              ((uint32)0x00000800U)
    #define MCU_FLASH_B02P1PFLM_MASK32              ((uint32)0x00000600U)
    #define MCU_FLASH_B02P1BFE_MASK32               ((uint32)0x00000100U)
    #define MCU_FLASH_B02P0BCFG_MASK32              ((uint32)0x00000060U)
    #define MCU_FLASH_B02P0DPFE_MASK32              ((uint32)0x00000010U)
    #define MCU_FLASH_B02P0IPFE_MASK32              ((uint32)0x00000008U)
    #define MCU_FLASH_B02P0PFLM_MASK32              ((uint32)0x00000006U)
    #define MCU_FLASH_B02P0BFE_MASK32               ((uint32)0x00000001U)
#endif



/* defines for FLASHC_PFCR1_ADDR32 */
/* writable and reserved to 1 bits. */
#define FLASHC_PFCR1_RWBITS_MASK32              ((uint32)0xFFFFFF57U)
#define FLASHC_PFCR1_RESBITS_MASK32             ((uint32)0x00000000U)

/* defines for FLASHC_PFCR2_ADDR32 */
/* writable and reserved to 1 bits. */
#define FLASHC_PFCR2_RWBITS_MASK32              ((uint32)0xFFFF0057U)
#define FLASHC_PFCR2_RESBITS_MASK32             ((uint32)0x00000000U)

#if (IPV_FLASHV2 == IPV_FLASH_25_60_86_00)

    /* defines for FLASHC_PFCR3_ADDR32 */
    /* writable and reserved to 1 bits. */
    #define FLASHC_PFCR3_RWBITS_MASK32              ((uint32)0xFC00F000U)
    #define FLASHC_PFCR3_RESBITS_MASK32             ((uint32)0x00000000U)


#elif ((IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || \
       (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_19) \
      )

    /* defines for FLASHC_PFCR3_ADDR32 */
    /* writable and reserved to 1 bits. */
    #define FLASHC_PFCR3_RWBITS_MASK32              ((uint32)0xF011C000U)
    #define FLASHC_PFCR3_RESBITS_MASK32             ((uint32)0x00000000U)
    
    #if (IPV_FLASHV2 == IPV_FLASH_42_56_55_38)
        #define FLASHC_PFCR3_DERR_SUP_MASK32            ((uint32)0x00000001U)
    #endif /* (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) */

#elif (IPV_FLASHV2 == IPV_FLASH_62_72_55_39)
    /* defines for FLASHC_PFCR3_ADDR32 */
    /* writable and reserved to 1 bits. */
    #define FLASHC_PFCR3_RWBITS_MASK32              ((uint32)0xFC01F000U)
    #define FLASHC_PFCR3_RESBITS_MASK32             ((uint32)0x00000000U)

    /* defines for FLASHC_PFCR4_ADDR32 */
    /* writable and reserved to 1 bits. */
    #define FLASHC_PFCR4_RWBITS_MASK32              ((uint32)0xFFFF005EU)
    #define FLASHC_PFCR4_RESBITS_MASK32             ((uint32)0x00000000U)
#elif (IPV_FLASHV2 == IPV_FLASH_84_80_32_02)

    /* defines for FLASHC_PFCR3_ADDR32 */
    /* writable and reserved to 1 bits. */
    #define FLASHC_PFCR3_RWBITS_MASK32              ((uint32)0xF001C001U)
    #define FLASHC_PFCR3_RESBITS_MASK32             ((uint32)0x00000000U)
    
    #define FLASHC_PFCR3_DERR_SUP_MASK32            ((uint32)0x00000001U)
    
#elif ((IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46))
    /* defines for FLASHC_PFCR3_ADDR32 */
    /* writable and reserved to 1 bits. */
    #define FLASHC_PFCR3_RWBITS_MASK32              ((uint32)0xFC01F000U)
    #define FLASHC_PFCR3_RESBITS_MASK32             ((uint32)0x00000000U)

    /* defines for FLASHC_PFCR4_ADDR32 */
    /* writable and reserved to 1 bits. */
    #define FLASHC_PFCR4_RWBITS_MASK32              ((uint32)0xFFFF0057U)
    #define FLASHC_PFCR4_RESBITS_MASK32             ((uint32)0x00000000U)
#endif

/* PFCR1 bit masks. */
#define FLASHC_PFCR1_P0_M15PFE_MASK32           ((uint32)0x80000000U)
#define FLASHC_PFCR1_P0_M14PFE_MASK32           ((uint32)0x40000000U)
#define FLASHC_PFCR1_P0_M13PFE_MASK32           ((uint32)0x20000000U)
#define FLASHC_PFCR1_P0_M12PFE_MASK32           ((uint32)0x10000000U)
#define FLASHC_PFCR1_P0_M11PFE_MASK32           ((uint32)0x08000000U)
#define FLASHC_PFCR1_P0_M10PFE_MASK32           ((uint32)0x04000000U)
#define FLASHC_PFCR1_P0_M9PFE_MASK32            ((uint32)0x02000000U)
#define FLASHC_PFCR1_P0_M8PFE_MASK32            ((uint32)0x01000000U)
#define FLASHC_PFCR1_P0_M7PFE_MASK32            ((uint32)0x00800000U)
#define FLASHC_PFCR1_P0_M6PFE_MASK32            ((uint32)0x00400000U)
#define FLASHC_PFCR1_P0_M5PFE_MASK32            ((uint32)0x00200000U)
#define FLASHC_PFCR1_P0_M4PFE_MASK32            ((uint32)0x00100000U)
#define FLASHC_PFCR1_P0_M3PFE_MASK32            ((uint32)0x00080000U)
#define FLASHC_PFCR1_P0_M2PFE_MASK32            ((uint32)0x00040000U)
#define FLASHC_PFCR1_P0_M1PFE_MASK32            ((uint32)0x00020000U)
#define FLASHC_PFCR1_P0_M0PFE_MASK32            ((uint32)0x00010000U)

#define FLASHC_PFCR1_APC_MASK32                 ((uint32)0x0000E000U)
#define FLASHC_PFCR1_RWSC_MASK32                ((uint32)0x00001F00U)
#define FLASHC_PFCR1_P0_DPFEN_MASK32            ((uint32)0x00000040U)
#define FLASHC_PFCR1_P0_IFPFEN_MASK32           ((uint32)0x00000010U)
#define FLASHC_PFCR1_P0_PFLIM_MASK32            ((uint32)0x00000006U)
#define FLASHC_PFCR1_P0_BFEN_MASK32             ((uint32)0x00000001U)

/* PFCR2 bit masks. */
#define FLASHC_PFCR2_P1_M15PFE_MASK32           ((uint32)0x80000000U)
#define FLASHC_PFCR2_P1_M14PFE_MASK32           ((uint32)0x40000000U)
#define FLASHC_PFCR2_P1_M13PFE_MASK32           ((uint32)0x20000000U)
#define FLASHC_PFCR2_P1_M12PFE_MASK32           ((uint32)0x10000000U)
#define FLASHC_PFCR2_P1_M11PFE_MASK32           ((uint32)0x08000000U)
#define FLASHC_PFCR2_P1_M10PFE_MASK32           ((uint32)0x04000000U)
#define FLASHC_PFCR2_P1_M9PFE_MASK32            ((uint32)0x02000000U)
#define FLASHC_PFCR2_P1_M8PFE_MASK32            ((uint32)0x01000000U)
#define FLASHC_PFCR2_P1_M7PFE_MASK32            ((uint32)0x00800000U)
#define FLASHC_PFCR2_P1_M6PFE_MASK32            ((uint32)0x00400000U)
#define FLASHC_PFCR2_P1_M5PFE_MASK32            ((uint32)0x00200000U)
#define FLASHC_PFCR2_P1_M4PFE_MASK32            ((uint32)0x00100000U)
#define FLASHC_PFCR2_P1_M3PFE_MASK32            ((uint32)0x00080000U)
#define FLASHC_PFCR2_P1_M2PFE_MASK32            ((uint32)0x00040000U)
#define FLASHC_PFCR2_P1_M1PFE_MASK32            ((uint32)0x00020000U)
#define FLASHC_PFCR2_P1_M0PFE_MASK32            ((uint32)0x00010000U)

#define FLASHC_PFCR2_P1_DPFEN_MASK32            ((uint32)0x00000040U)
#define FLASHC_PFCR2_P1_IFPFEN_MASK32           ((uint32)0x00000010U)
#define FLASHC_PFCR2_P1_PFLIM_MASK32            ((uint32)0x00000006U)
#define FLASHC_PFCR2_P1_BFEN_MASK32             ((uint32)0x00000001U)

/* PFCR3 bit masks. */
#define FLASHC_PFCR3_P0_WCFG_MASK32             ((uint32)0xC0000000U)
#define FLASHC_PFCR3_P1_WCFG_MASK32             ((uint32)0x30000000U)
#define FLASHC_PFCR3_P2_WCFG_MASK32             ((uint32)0x0C000000U)
#define FLASHC_PFCR3_BDRM_MASK32                ((uint32)0x00100000U)
#define FLASHC_PFCR3_BAF_DIS_MASK32             ((uint32)0x00010000U)

#define FLASHC_PFCR3_BFEN_LK_MASK32             ((uint32)0x00010000U)

#if ((IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || \
     (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) \
    )

    #define FLASHC_PFCR3_ARBM_MASK32                ((uint32)0x0000C000U)

#elif ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_25_60_86_00) || \
       (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || \
       (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
      )

    #define FLASHC_PFCR3_ARBM_MASK32                ((uint32)0x0000F000U)

#endif

/* PFAPR bit masks. */

#define FLASHC_PFAPR_RWBITS_MASK32              ((uint32)0xFFFFFFFFU)
#define FLASHC_PFAPR_RESBITS_MASK32             ((uint32)0x00000000U)

#define FLASHC_PFAPR_M0AP_MASK32                ((uint32)0xC0000000U)
#define FLASHC_PFAPR_M1AP_MASK32                ((uint32)0x30000000U)
#define FLASHC_PFAPR_M2AP_MASK32                ((uint32)0x0C000000U)
#define FLASHC_PFAPR_M3AP_MASK32                ((uint32)0x03000000U)
#define FLASHC_PFAPR_M4AP_MASK32                ((uint32)0x00C00000U)
#define FLASHC_PFAPR_M5AP_MASK32                ((uint32)0x00300000U)
#define FLASHC_PFAPR_M6AP_MASK32                ((uint32)0x000C0000U)
#define FLASHC_PFAPR_M7AP_MASK32                ((uint32)0x00030000U)
#define FLASHC_PFAPR_M8AP_MASK32                ((uint32)0x0000C000U)
#define FLASHC_PFAPR_M9AP_MASK32                ((uint32)0x00003000U)
#define FLASHC_PFAPR_M10AP_MASK32               ((uint32)0x00000C00U)
#define FLASHC_PFAPR_M11AP_MASK32               ((uint32)0x00000300U)
#define FLASHC_PFAPR_M12AP_MASK32               ((uint32)0x000000C0U)
#define FLASHC_PFAPR_M13AP_MASK32               ((uint32)0x00000030U)
#define FLASHC_PFAPR_M14AP_MASK32               ((uint32)0x0000000CU)
#define FLASHC_PFAPR_M15AP_MASK32               ((uint32)0x00000003U)

/* PFCR4 bit masks. */
#define FLASHC_PFCR4_P2_M15PFE_MASK32           ((uint32)0x80000000U)
#define FLASHC_PFCR4_P2_M14PFE_MASK32           ((uint32)0x40000000U)
#define FLASHC_PFCR4_P2_M13PFE_MASK32           ((uint32)0x20000000U)
#define FLASHC_PFCR4_P2_M12PFE_MASK32           ((uint32)0x10000000U)
#define FLASHC_PFCR4_P2_M11PFE_MASK32           ((uint32)0x08000000U)
#define FLASHC_PFCR4_P2_M10PFE_MASK32           ((uint32)0x04000000U)
#define FLASHC_PFCR4_P2_M9PFE_MASK32            ((uint32)0x02000000U)
#define FLASHC_PFCR4_P2_M8PFE_MASK32            ((uint32)0x01000000U)
#define FLASHC_PFCR4_P2_M7PFE_MASK32            ((uint32)0x00800000U)
#define FLASHC_PFCR4_P2_M6PFE_MASK32            ((uint32)0x00400000U)
#define FLASHC_PFCR4_P2_M5PFE_MASK32            ((uint32)0x00200000U)
#define FLASHC_PFCR4_P2_M4PFE_MASK32            ((uint32)0x00100000U)
#define FLASHC_PFCR4_P2_M3PFE_MASK32            ((uint32)0x00080000U)
#define FLASHC_PFCR4_P2_M2PFE_MASK32            ((uint32)0x00040000U)
#define FLASHC_PFCR4_P2_M1PFE_MASK32            ((uint32)0x00020000U)
#define FLASHC_PFCR4_P2_M0PFE_MASK32            ((uint32)0x00010000U)

#define FLASHC_PFCR4_P2_DPFEN_MASK32            ((uint32)0x00000040U)
#define FLASHC_PFCR4_P2_IFPFEN_MASK32           ((uint32)0x00000010U)
#define FLASHC_PFCR4_P2_PFLIM_MASK32            ((uint32)0x00000006U)
#define FLASHC_PFCR4_P2_BFEN_MASK32             ((uint32)0x00000001U)
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

#endif /* MCU_REG_ESYS_FLASHC_H */

/** @} */
