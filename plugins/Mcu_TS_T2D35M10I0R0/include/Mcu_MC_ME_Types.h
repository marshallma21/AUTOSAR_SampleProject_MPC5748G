/**
*   @file    Mcu_MC_ME_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from MC_ME.
*   @details Public data types exported outside of the Mcu driver.
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


#ifndef MCU_MC_ME_TYPES_H
#define MCU_MC_ME_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_ME_Types_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_MC_ME_Types_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Mcu_MC_ME_Types_h_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
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
#include "Mcu_Cfg.h"
#include "Reg_eSys_MC_ME.h"
#include "Soc_Ips.h"
#include "Mcu_MC_IPVersion.h"


/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_MC_ME_TYPES_VENDOR_ID                     43
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_TYPES_AR_RELEASE_MAJOR_VERSION      4
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_TYPES_AR_RELEASE_MINOR_VERSION      2
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_TYPES_AR_RELEASE_REVISION_VERSION   2
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_TYPES_SW_MAJOR_VERSION              1
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_TYPES_SW_MINOR_VERSION              0
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MCU_MC_ME_TYPES_SW_PATCH_VERSION              0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_MC_ME_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_MC_ME_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_MC_ME_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_ME_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_MC_ME_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_MC_ME_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_MC_ME_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_ME_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Reg_eSys_MC_ME header file are from the same vendor */
#if (MCU_MC_ME_TYPES_VENDOR_ID != REG_ESYS_MC_ME_VENDOR_ID)
    #error "Mcu_MC_ME_Types.h and Reg_eSys_MC_ME.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_MC_ME header file are of the same Autosar version */
#if ((MCU_MC_ME_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_MC_ME_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_MC_ME_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_ME_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_MC_ME_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME_Types.h and Reg_eSys_MC_ME.h are different"
#endif
/* Check if source file and Reg_eSys_MC_ME header file are of the same Software version */
#if ((MCU_MC_ME_TYPES_SW_MAJOR_VERSION != REG_ESYS_MC_ME_SW_MAJOR_VERSION) || \
     (MCU_MC_ME_TYPES_SW_MINOR_VERSION != REG_ESYS_MC_ME_SW_MINOR_VERSION) || \
     (MCU_MC_ME_TYPES_SW_PATCH_VERSION != REG_ESYS_MC_ME_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_ME_Types.h and Reg_eSys_MC_ME.h are different"
#endif

/* Check if current file and Soc_Ips header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_ME_TYPES_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_ME_TYPES_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_ME_Types.h and Soc_Ips.h are different"
    #endif
#endif

/* Check if source file and Mcu_MC_IPVersion header file are from the same vendor */
#if (MCU_MC_ME_TYPES_VENDOR_ID != MCU_MC_IPVERSION_VENDOR_ID)
    #error "Mcu_MC_ME_Types.h and Mcu_MC_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Autosar version */
#if ((MCU_MC_ME_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_TYPES_AR_RELEASE_MINOR_VERSION != MCU_MC_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_ME_TYPES_AR_RELEASE_REVISION_VERSION != MCU_MC_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME_Types.h and Mcu_MC_IPVersion.h are different"
#endif
/* Check if source file and Mcu_MC_IPVersion header file are of the same Software version */
#if ((MCU_MC_ME_TYPES_SW_MAJOR_VERSION != MCU_MC_IPVERSION_SW_MAJOR_VERSION) || \
     (MCU_MC_ME_TYPES_SW_MINOR_VERSION != MCU_MC_IPVERSION_SW_MINOR_VERSION) || \
     (MCU_MC_ME_TYPES_SW_PATCH_VERSION != MCU_MC_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_ME_Types.h and Mcu_MC_IPVersion.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/********** ME_mode_MC Registers Configuration **********/

/* ME_mode_MC[PWRLVL] field configuration. */
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_POWER_LEVEL_U32(pwr_level)        ((uint32)( (uint32)((pwr_level) << MC_ME_MODE_MC_PWRLVL_SHIFT32) & MC_ME_MODE_MC_PWRLVL_MASK32 ))

/* ME_mode_MC[PDO] field configuration. */
#define MC_ME_OUT_POWER_CONTROL_EN_U32          (MC_ME_MODE_MC_PDO_MASK32)
#define MC_ME_OUT_POWER_CONTROL_DIS_U32         ((uint32)0x00000000U)

/* ME_mode_MC[MVRON] field configuration. */
#define MC_ME_MAIN_VOLTAGE_REG_EN_U32           (MC_ME_MODE_MC_MVRON_MASK32)
#define MC_ME_MAIN_VOLTAGE_REG_DIS_U32          ((uint32)0x00000000U)

/* ME_mode_MC[FLAON] field configuration. */
#define MC_ME_CODE_FLASH_POWER_DOWN_U32         ((uint32)0x00010000U)
#define MC_ME_CODE_FLASH_LOW_POWER_U32          ((uint32)0x00020000U)
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_CODE_FLASH_NORMAL_POWER_U32       ((uint32)0x00030000U)

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    /* ME_mode_MC[SDPLLON] field configuration. */
    #define MC_ME_SDPLL_EN_U32                  (MC_ME_MODE_MC_SDPLLON_MASK32)
    #define MC_ME_SDPLL_DIS_U32                 ((uint32)0x00000000U)
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* ME_mode_MC[PLL1ON] field configuration. */
    #define MC_ME_FMPLL1_EN_U32                 (MC_ME_MODE_MC_PLL1ON_MASK32)
    #define MC_ME_FMPLL1_DIS_U32                ((uint32)0x00000000U)

    /* ME_mode_MC[PLL0ON] field configuration. */
    #define MC_ME_FMPLL0_EN_U32                 (MC_ME_MODE_MC_PLL0ON_MASK32)
    #define MC_ME_FMPLL0_DIS_U32                ((uint32)0x00000000U)

    /* ME_mode_MC[XOSCON] field configuration. */
    #define MC_ME_XOSC_EN_U32                   (MC_ME_MODE_MC_XOSCON_MASK32)
    #define MC_ME_XOSC_DIS_U32                  ((uint32)0x00000000U)

    /* ME_mode_MC[IRCON] field configuration. */
    #define MC_ME_IRCOSC_EN_U32                 (MC_ME_MODE_MC_IRCOSCON_MASK32)
    #define MC_ME_IRCOSC_DIS_U32                ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    /* ME_mode_MC[PLL3ON] field configuration. */
    #define MC_ME_PLL3_EN_U32                   (MC_ME_MODE_MC_PLL3ON_MASK32)
    #define MC_ME_PLL3_DIS_U32                  ((uint32)0x00000000U)

    /* ME_mode_MC[PLL2ON] field configuration. */
    #define MC_ME_PLL2_EN_U32                   (MC_ME_MODE_MC_PLL2ON_MASK32)
    #define MC_ME_PLL2_DIS_U32                  ((uint32)0x00000000U)

    /* ME_mode_MC[PLL1ON] field configuration. */
    #define MC_ME_PLL1_EN_U32                   (MC_ME_MODE_MC_PLL1ON_MASK32)
    #define MC_ME_PLL1_DIS_U32                  ((uint32)0x00000000U)

    /* ME_mode_MC[PLL0ON] field configuration. */
    #define MC_ME_PLL0_EN_U32                   (MC_ME_MODE_MC_PLL0ON_MASK32)
    #define MC_ME_PLL0_DIS_U32                  ((uint32)0x00000000U)

    /* ME_mode_MC[SXOSCON] field configuration. */
    #define MC_ME_SXOSC_EN_U32                  (MC_ME_MODE_MC_SXOSCON_MASK32)
    #define MC_ME_SXOSC_DIS_U32                 ((uint32)0x00000000U)

    /* ME_mode_MC[SIRCON] field configuration. */
    #define MC_ME_SIRC_EN_U32                   (MC_ME_MODE_MC_SIRCON_MASK32)
    #define MC_ME_SIRC_DIS_U32                  ((uint32)0x00000000U)

    /* ME_mode_MC[FXOSCON] field configuration. */
    #define MC_ME_FXOSC_EN_U32                  (MC_ME_MODE_MC_FXOSCON_MASK32)
    #define MC_ME_FXOSC_DIS_U32                 ((uint32)0x00000000U)

    /* ME_mode_MC[SXOSCON] field configuration. */
    #define MC_ME_FIRC_EN_U32                   (MC_ME_MODE_MC_FIRCON_MASK32)
    #define MC_ME_FIRC_DIS_U32                  ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    /* ME_mode_MC[PLL0ON] field configuration. */
    #define MC_ME_PLL0_EN_U32                   (MC_ME_MODE_MC_PLL0ON_MASK32)
    #define MC_ME_PLL0_DIS_U32                  ((uint32)0x00000000U)

    /* ME_mode_MC[SXOSCON] field configuration. */
    #define MC_ME_SXOSC_EN_U32                  (MC_ME_MODE_MC_SXOSCON_MASK32)
    #define MC_ME_SXOSC_DIS_U32                 ((uint32)0x00000000U)

    /* ME_mode_MC[SIRCON] field configuration. */
    #define MC_ME_SIRC_EN_U32                   (MC_ME_MODE_MC_SIRCON_MASK32)
    #define MC_ME_SIRC_DIS_U32                  ((uint32)0x00000000U)

    /* ME_mode_MC[FXOSCON] field configuration. */
    #define MC_ME_FXOSC_EN_U32                      (MC_ME_MODE_MC_FXOSCON_MASK32)
    #define MC_ME_FXOSC_DIS_U32                     ((uint32)0x00000000U)

    /* ME_mode_MC[SXOSCON] field configuration. */
    #define MC_ME_FIRC_EN_U32                       (MC_ME_MODE_MC_FIRCON_MASK32)
    #define MC_ME_FIRC_DIS_U32                      ((uint32)0x00000000U)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* ME_mode_MC[VIDEOPLLON] field configuration. */
    #define MC_ME_VIDEOPLL_EN_U32           (MC_ME_MODE_MC_VIDEOPLLON_MASK32)
    #define MC_ME_VIDEOPLL_DIS_U32          ((uint32)0x00000000U)

    /* ME_mode_MC[DDRPLLDFS123ON] field configuration. */
    #define MC_ME_DDRPLLDFS123_EN_U32       (MC_ME_MODE_MC_DDRPLLDFS123ON_MASK32)
    #define MC_ME_DDRPLLDFS123_DIS_U32      ((uint32)0x00000000U)

    /* ME_mode_MC[ENETPLLDFS1234ON] field configuration. */
    #define MC_ME_ENETPLLDFS1234_EN_U32     (MC_ME_MODE_MC_ENETPLLDFS1234ON_MASK32)
    #define MC_ME_ENETPLLDFS1234_DIS_U32    ((uint32)0x00000000U)
    
    /* ME_mode_MC[PERIPHPLLON] field configuration. */
    #define MC_ME_PERIPHPLL_EN_U32          (MC_ME_MODE_MC_PERIPHPLLON_MASK32)
    #define MC_ME_PERIPHPLL_DIS_U32         ((uint32)0x00000000U)
    
    /* ME_mode_MC[ARMPLLDFS123ON] field configuration. */
    #define MC_ME_ARMPLLDFS123_EN_U32       (MC_ME_MODE_MC_ARMPLLDFS123ON_MASK32)
    #define MC_ME_ARMPLLDFS123_DIS_U32      ((uint32)0x00000000U)

    /* ME_mode_MC[XOSCON] field configuration. */
    #define MC_ME_XOSC_EN_U32               (MC_ME_MODE_MC_XOSCON_MASK32)
    #define MC_ME_XOSC_DIS_U32              ((uint32)0x00000000U)

    /* ME_mode_MC[FIRCON] field configuration. */
    #define MC_ME_FIRC_EN_U32               (MC_ME_MODE_MC_FIRCON_MASK32)
    #define MC_ME_FIRC_DIS_U32              ((uint32)0x00000000U)
#endif

/* MC_mode_MC mask for enable clocks bit field */
/* IRCOSC is always on */
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    #define MC_ME_ENABLED_CLOCKS_MASK32         ( \
                                                    MC_ME_MODE_MC_PLL1ON_MASK32 | \
                                                    MC_ME_MODE_MC_PLL0ON_MASK32 | \
                                                    MC_ME_MODE_MC_XOSCON_MASK32 \
                                                )
#elif ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_ENABLED_CLOCKS_MASK32         ( \
                                                    MC_ME_MODE_MC_SDPLLON_MASK32 | \
                                                    MC_ME_MODE_MC_PLL1ON_MASK32 | \
                                                    MC_ME_MODE_MC_PLL0ON_MASK32 | \
                                                    MC_ME_MODE_MC_XOSCON_MASK32 \
                                                )
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_ENABLED_CLOCKS_MASK32         ( \
                                                    MC_ME_MODE_MC_PLL3ON_MASK32 | \
                                                    MC_ME_MODE_MC_PLL2ON_MASK32 | \
                                                    MC_ME_MODE_MC_PLL1ON_MASK32 | \
                                                    MC_ME_MODE_MC_PLL0ON_MASK32 | \
                                                    MC_ME_MODE_MC_SXOSCON_MASK32 | \
                                                    MC_ME_MODE_MC_SIRCON_MASK32 | \
                                                    MC_ME_MODE_MC_FXOSCON_MASK32 | \
                                                    MC_ME_MODE_MC_FIRCON_MASK32 \
                                                )
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_ENABLED_CLOCKS_MASK32         ( \
                                                    MC_ME_MODE_MC_PLL0ON_MASK32 | \
                                                    MC_ME_MODE_MC_SXOSCON_MASK32 | \
                                                    MC_ME_MODE_MC_SIRCON_MASK32 | \
                                                    MC_ME_MODE_MC_FXOSCON_MASK32 | \
                                                    MC_ME_MODE_MC_FIRCON_MASK32 \
                                                )
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_ENABLED_CLOCKS_MASK32         ( \
                                                    MC_ME_MODE_MC_VIDEOPLLON_MASK32 | \
                                                    MC_ME_MODE_MC_DDRPLLDFS123ON_MASK32 | \
                                                    MC_ME_MODE_MC_ENETPLLDFS1234ON_MASK32 | \
                                                    MC_ME_MODE_MC_PERIPHPLLON_MASK32 | \
                                                    MC_ME_MODE_MC_ARMPLLDFS123ON_MASK32 | \
                                                    MC_ME_MODE_MC_XOSCON_MASK32 | \
                                                    MC_ME_MODE_MC_FIRCON_MASK32 \
                                                )
#endif


/* ME_mode_MC[SYSCLK] field configuration. */

/* macros to ensure that the ME_mode_MC values passed by */
/* Mcu_ModeConfigType structure are valid */
/* this will remove the checks done by Mcu_MC_ME_ModeConfig to */
/* reduce code size and increase execution speed */
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_RESET_MODE_U32(value)                 ( ((value) & MC_ME_RESET_MC_WRBITS_MASK32  ) | MC_ME_RESET_MC_RESBITS_MASK32  )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_TEST_MODE_U32(value)                  ( ((value) & MC_ME_TEST_MC_WRBITS_MASK32   ) | MC_ME_TEST_MC_RESBITS_MASK32   )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_SAFE_MODE_U32(value)                  ( ((value) & MC_ME_SAFE_MC_WRBITS_MASK32   ) | MC_ME_SAFE_MC_RESBITS_MASK32   )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_DRUN_MODE_U32(value)                  ( ((value) & MC_ME_DRUN_MC_WRBITS_MASK32   ) | MC_ME_DRUN_MC_RESBITS_MASK32   )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_RUN0_MODE_U32(value)                  ( ((value) & MC_ME_RUN0_3_MC_WRBITS_MASK32 ) | MC_ME_RUN0_3_MC_RESBITS_MASK32 )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_RUN1_MODE_U32(value)                  ( ((value) & MC_ME_RUN0_3_MC_WRBITS_MASK32 ) | MC_ME_RUN0_3_MC_RESBITS_MASK32 )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_RUN2_MODE_U32(value)                  ( ((value) & MC_ME_RUN0_3_MC_WRBITS_MASK32 ) | MC_ME_RUN0_3_MC_RESBITS_MASK32 )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_RUN3_MODE_U32(value)                  ( ((value) & MC_ME_RUN0_3_MC_WRBITS_MASK32 ) | MC_ME_RUN0_3_MC_RESBITS_MASK32 )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_HALT0_MODE_U32(value)                 ( ((value) & MC_ME_HALT0_MC_WRBITS_MASK32  ) | MC_ME_HALT0_MC_RESBITS_MASK32  )
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_STOP0_MODE_U32(value)                 ( ((value) & MC_ME_STOP0_MC_WRBITS_MASK32  ) | MC_ME_STOP0_MC_RESBITS_MASK32  )


/* system clock masks */
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    #define MC_ME_SYSCLK_SDPLL_U32                  (MC_ME_MODE_MC_SYSCLK_SDPLL_U32)
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    #define MC_ME_SYSCLK_IRCOSC_U32                 (MC_ME_MODE_MC_SYSCLK_IRCOSC_U32)
    #define MC_ME_SYSCLK_XOSC_U32                   (MC_ME_MODE_MC_SYSCLK_XOSC_U32)
    #define MC_ME_SYSCLK_PLL0_U32                   (MC_ME_MODE_MC_SYSCLK_PLL0_U32)
    #define MC_ME_SYSCLK_PLL1_U32                   (MC_ME_MODE_MC_SYSCLK_PLL1_U32)
    #define MC_ME_SYSCLK_DISABLED_U32               ((uint32)0x0000000FU)
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define MC_ME_SYSCLK_PLL1_U32                   (MC_ME_MODE_MC_SYSCLK_PLL1_U32)
    #define MC_ME_SYSCLK_PLL0_U32                   (MC_ME_MODE_MC_SYSCLK_PLL0_U32)
    #define MC_ME_SYSCLK_FXOSC_U32                  (MC_ME_MODE_MC_SYSCLK_FXOSC_U32)
    #define MC_ME_SYSCLK_FIRC_U32                   (MC_ME_MODE_MC_SYSCLK_FIRC_U32)
    #define MC_ME_SYSCLK_DISABLED_U32               ((uint32)0x0000000FU)
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define MC_ME_SYSCLK_PLL0_U32                   (MC_ME_MODE_MC_SYSCLK_PLL0_U32)
    #define MC_ME_SYSCLK_FXOSC_U32                  (MC_ME_MODE_MC_SYSCLK_FXOSC_U32)
    #define MC_ME_SYSCLK_FIRC_U32                   (MC_ME_MODE_MC_SYSCLK_FIRC_U32)
    #define MC_ME_SYSCLK_DISABLED_U32               ((uint32)0x0000000FU)
#elif (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_SYSCLK_ARM_PLL_DFS1_U32           (MC_ME_MODE_MC_SYSCLK_ARM_PLL_DFS1_U32)
    #define MC_ME_SYSCLK_XOSC_U32                   (MC_ME_MODE_MC_SYSCLK_XOSC_U32)
    #define MC_ME_SYSCLK_FIRC_U32                   (MC_ME_MODE_MC_SYSCLK_FIRC_U32)
    #define MC_ME_SYSCLK_DISABLED_U32               ((uint32)0x0000000FU)
#endif



/********** ME_RUN_PCn Registers Configuration **********/

/* ME_RUN_PCn[RUN3] field configuration. */
#define MC_ME_RUN3_CLK_GATED_U32                ((uint32)0x00000000U)
#define MC_ME_RUN3_CLK_ACTIVE_U32               ((uint32)0x00000080U)

/* ME_RUN_PCn[RUN2] field configuration. */
#define MC_ME_RUN2_CLK_GATED_U32                ((uint32)0x00000000U)
#define MC_ME_RUN2_CLK_ACTIVE_U32               ((uint32)0x00000040U)

/* ME_RUN_PCn[RUN1] field configuration. */
#define MC_ME_RUN1_CLK_GATED_U32                ((uint32)0x00000000U)
#define MC_ME_RUN1_CLK_ACTIVE_U32               ((uint32)0x00000020U)

/* ME_RUN_PCn[RUN0] field configuration. */
#define MC_ME_RUN0_CLK_GATED_U32                ((uint32)0x00000000U)
#define MC_ME_RUN0_CLK_ACTIVE_U32               ((uint32)0x00000010U)

/* ME_RUN_PCn[DRUN] field configuration. */
#define MC_ME_DRUN_CLK_GATED_U32                ((uint32)0x00000000U)
#define MC_ME_DRUN_CLK_ACTIVE_U32               ((uint32)0x00000008U)

/* ME_RUN_PCn[SAFE] field configuration. */
#define MC_ME_SAFE_CLK_GATED_U32                ((uint32)0x00000000U)
#define MC_ME_SAFE_CLK_ACTIVE_U32               ((uint32)0x00000004U)

/* ME_RUN_PCn[TEST] field configuration. */
#define MC_ME_TEST_CLK_GATED_U32                ((uint32)0x00000000U)
#define MC_ME_TEST_CLK_ACTIVE_U32               ((uint32)0x00000002U)

/* ME_RUN_PCn[RESET] field configuration. */
#define MC_ME_RESET_CLK_GATED_U32               ((uint32)0x00000000U)
#define MC_ME_RESET_CLK_ACTIVE_U32              ((uint32)0x00000001U)


/********** ME_LP_PCn Registers Configuration **********/
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* ME_LP_PCn[STOP0] field configuration. */
    #define MC_ME_STOP0_CLK_GATED_U32           ((uint32)0x00000000U)
    #define MC_ME_STOP0_CLK_ACTIVE_U32          ((uint32)0x00000400U)

    /* ME_LP_PCn[HALT0] field configuration. */
    #define MC_ME_HALT0_CLK_GATED_U32           ((uint32)0x00000000U)
    #define MC_ME_HALT0_CLK_ACTIVE_U32          ((uint32)0x00000100U)
#elif ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
    /* ME_LP_PCn[STOP0] field configuration. */
    #define MC_ME_STOP0_CLK_GATED_U32           ((uint32)0x00000000U)
    #define MC_ME_STOP0_CLK_ACTIVE_U32          ((uint32)0x00000400U)

    /* ME_LP_PCn[STANDBY0] field configuration. */
    #define MC_ME_STBY0_CLK_GATED_U32           ((uint32)0x00000000U)
    #define MC_ME_STBY0_CLK_ACTIVE_U32          ((uint32)0x00002000U)
#endif

/********** ME_PCTLn Registers Configuration **********/
/* ME_PCTLn[DBG_F] field configuration. */
#define MC_ME_PCTL_DBG_FRZ_EN_U8             ((uint8)0x40U)
#define MC_ME_PCTL_DBG_FRZ_DIS_U8            ((uint8)0x00U)

/* ME_PCTLn[RUN_CFG] field configuration. */
#define MC_ME_CFG_RUN_PC0_U8                    ((uint8)0x00U)
#define MC_ME_CFG_RUN_PC1_U8                    ((uint8)0x01U)
#define MC_ME_CFG_RUN_PC2_U8                    ((uint8)0x02U)
#define MC_ME_CFG_RUN_PC3_U8                    ((uint8)0x03U)
#define MC_ME_CFG_RUN_PC4_U8                    ((uint8)0x04U)
#define MC_ME_CFG_RUN_PC5_U8                    ((uint8)0x05U)
#define MC_ME_CFG_RUN_PC6_U8                    ((uint8)0x06U)
#define MC_ME_CFG_RUN_PC7_U8                    ((uint8)0x07U)

/* ME_PCTLn[LP_CFG] field configuration. */
#define MC_ME_CFG_LP_PC0_U8                     ((uint8)0x00U)
#define MC_ME_CFG_LP_PC1_U8                     ((uint8)0x08U)
#define MC_ME_CFG_LP_PC2_U8                     ((uint8)0x10U)
#define MC_ME_CFG_LP_PC3_U8                     ((uint8)0x18U)
#define MC_ME_CFG_LP_PC4_U8                     ((uint8)0x20U)
#define MC_ME_CFG_LP_PC5_U8                     ((uint8)0x28U)
#define MC_ME_CFG_LP_PC6_U8                     ((uint8)0x30U)
#define MC_ME_CFG_LP_PC7_U8                     ((uint8)0x38U)

/* ME_PCTLn[LP_CFG] and ME_PCTLn[RUN_CFG] fields configuration. */
#if ((IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_04_06_01_00))
    /** @violates @ref Mcu_MC_ME_Types_h_REF_2 Function-like macro defined.*/
    #define MC_ME_PCTLn_U8(dbg, rm, lpm)        ((uint8)( (dbg) | (lpm) | (rm) ))
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_ME_Types_h_REF_2 Function-like macro defined.*/
    #define MC_ME_PCTLn_U8(rm)        ((uint8)((rm)))
#else
    /** @violates @ref Mcu_MC_ME_Types_h_REF_2 Function-like macro defined.*/
    #define MC_ME_PCTLn_U8(rm, lpm)             ((uint8)( (lpm) | (rm) ))
#endif

/********** ME_ME Register Configuration **********/
/* this macro will be used in the plug-in code, with the following defines */
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_ME_ENABLE(value)                  ((uint32)( ((value) & MC_ME_ME_WRBITS_MASK32 ) | MC_ME_ME_RESBITS_MASK32 ))
/* MC_ME[RESET_DEST] field configuration. This is always on */
#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
/* MC_ME[STANDBY0] field configuration. */
#define MC_ME_STBY0_MODE_EN_U32                 (MC_ME_ME_STBY0_MASK32)
#define MC_ME_STBY0_MODE_DIS_U32                ((uint32)0x00000000U)
#endif
/* MC_ME[STOP0] field configuration. */
#define MC_ME_STOP0_MODE_EN_U32                 (MC_ME_ME_STOP0_MASK32)
#define MC_ME_STOP0_MODE_DIS_U32                ((uint32)0x00000000U)
/* MC_ME[HALT0] field configuration. */
#define MC_ME_HALT0_MODE_EN_U32                 (MC_ME_ME_HALT0_MASK32)
#define MC_ME_HALT0_MODE_DIS_U32                ((uint32)0x00000000U)
/* MC_ME[RUN3] field configuration. */
#define MC_ME_RUN3_MODE_EN_U32                  (MC_ME_ME_RUN3_MASK32)
#define MC_ME_RUN3_MODE_DIS_U32                 ((uint32)0x00000000U)
/* MC_ME[RUN2] field configuration. */
#define MC_ME_RUN2_MODE_EN_U32                  (MC_ME_ME_RUN2_MASK32)
#define MC_ME_RUN2_MODE_DIS_U32                 ((uint32)0x00000000U)
/* MC_ME[RUN1] field configuration. */
#define MC_ME_RUN1_MODE_EN_U32                  (MC_ME_ME_RUN1_MASK32)
#define MC_ME_RUN1_MODE_DIS_U32                 ((uint32)0x00000000U)
/* MC_ME[RUN0] field configuration. This mode is always enabled */
/* MC_ME[DRUN] field configuration. This mode is always enabled */
/* MC_ME[SAFE] field configuration. This mode is always enabled */
/* MC_ME[TEST] field configuration. */
#define MC_ME_TEST_MODE_EN_U32                  (MC_ME_ME_TEST_MASK32)
#define MC_ME_TEST_MODE_DIS_U32                 ((uint32)0x00000000U)
/* MC_ME[RESET_FUNC] field configuration. This mode is always enabled */


/********** ME_IM Register Configuration **********/

/* this macro will be used in the plug-in code, with the following defines */
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_INT_ENABLE(value)                     ( ((value) & MC_ME_IM_WRBITS_MASK32 ) | MC_ME_IM_RESBITS_MASK32 )

/* MC_IM[M_ICONF_SCC] field configuration. */
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_INVALID_MODE_SEC_CLK_INT_EN_U32       ((uint32)MC_ME_IM_ICONF_SCC_MASK32)
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_INVALID_MODE_SEC_CLK_INT_DIS_U32      ((uint32)0x00000000U)

/* MC_IM[M_ICONF_CC] field configuration. */
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_INVALID_MODE_CPU_INT_EN_U32           ((uint32)MC_ME_IM_ICONF_CC_MASK32)
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_INVALID_MODE_CPU_INT_DIS_U32          ((uint32)0x00000000U)
/* MC_IM[M_ICONF_CU] field configuration. */
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_INVALID_MODE_CLK_INT_EN_U32           ((uint32)MC_ME_IM_ICONF_CU_MASK32)
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_INVALID_MODE_CLK_INT_DIS_U32          ((uint32)0x00000000U)
/* MC_IM[M_ICONF] field configuration. */
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_INVALID_MODE_CFG_INT_EN_U32           ((uint32)MC_ME_IM_ICONF_MASK32)
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_INVALID_MODE_CFG_INT_DIS_U32          ((uint32)0x00000000U)
/* MC_IM[M_IMODE] field configuration. */
#define MC_ME_INVALID_MODE_INT_EN_U32               ((uint32)MC_ME_IM_IMODE_MASK32)
#define MC_ME_INVALID_MODE_INT_DIS_U32              ((uint32)0x00000000U)
/* MC_IM[M_SAFE] field configuration. */
#define MC_ME_SAFE_MODE_INT_EN_U32                  ((uint32)MC_ME_IM_SAFE_MASK32)
#define MC_ME_SAFE_MODE_INT_DIS_U32                 ((uint32)0x00000000U)
/* MC_IM[M_MTC] field configuration. */
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_TRANSITION_MODE_INT_EN_U32            ((uint32)MC_ME_IM_MTC_MASK32)
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_TRANSITION_MODE_INT_DIS_U32           ((uint32)0x00000000U)



/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_CCTL_ENABLE_U16(value)           ((uint16)(( (value) & MC_ME_CCTL_RWBITS_MASK16 ) | MC_ME_CCTL_RESBITS_MASK16 ))
#define MC_ME_CCTL_ALL_ON_U16                  (MC_ME_CCTL_RWBITS_MASK16)

/*bit maks */
#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
    #define MC_ME_CCTL_STBY_ON_U16                  (MC_ME_CCTL_STBY_MASK16)
    #define MC_ME_CCTL_STBY_OFF_U16                 ((uint16)0x0000)
#endif

#define MC_ME_CCTL_RUN3_ON_U16                  (MC_ME_CCTL_RUN3_MASK16)
#define MC_ME_CCTL_RUN3_OFF_U16                 ((uint16)0x0000)

#define MC_ME_CCTL_RUN2_ON_U16                  (MC_ME_CCTL_RUN2_MASK16)
#define MC_ME_CCTL_RUN2_OFF_U16                 ((uint16)0x0000)

#define MC_ME_CCTL_RUN1_ON_U16                  (MC_ME_CCTL_RUN1_MASK16)
#define MC_ME_CCTL_RUN1_OFF_U16                 ((uint16)0x0000)

#define MC_ME_CCTL_RUN0_ON_U16                  (MC_ME_CCTL_RUN0_MASK16)
#define MC_ME_CCTL_RUN0_OFF_U16                 ((uint16)0x0000)

#define MC_ME_CCTL_DRUN_ON_U16                  (MC_ME_CCTL_DRUN_MASK16)
#define MC_ME_CCTL_DRUN_OFF_U16                 ((uint16)0x0000)

#define MC_ME_CCTL_SAFE_ON_U16                  (MC_ME_CCTL_SAFE_MASK16)
#define MC_ME_CCTL_SAFE_OFF_U16                 ((uint16)0x0000)

#define MC_ME_CCTL_TEST_ON_U16                  (MC_ME_CCTL_TEST_MASK16)
#define MC_ME_CCTL_TEST_OFF_U16                 ((uint16)0x0000)



/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_CADDR_ENABLE_U32(value)           ((uint32)(((value) & MC_ME_CADDR_RWBITS_MASK32) | MC_ME_CADDR_RESBITS_MASK32))

/** @violates @ref Mcu_MC_ME_Types_h_REF_2 Function-like macro defined.*/
#define MC_ME_CADDR_ADDR_U32(value)             ((uint32)((value) & MC_ME_CADDR_ADDR_MASK32))

#define MC_ME_CADDR_RESET_ENABLE_U32            (MC_ME_CADDR_RMC_MASK32)
#define MC_ME_CADDR_RESET_DISABLE_U32           ((uint32)0x00000000U)

#if (IPV_MC == IPV_MC_06_00_00_10)
    #define MC_ME_CADDR_ADDR_BITS_EN_U32        ((uint32)0x00000001U)
    #define MC_ME_CADDR_ADDR_BITS_DIS_U32       ((uint32)0x00000000U)
#endif

/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_POWER_LEVEL3_U32(pwr_level)        ((uint32)( (uint32)((pwr_level) << MC_ME_MODE_SEC_CC_I_PWRLVL3_SHIFT32) & MC_ME_MODE_SEC_CC_I_PWRLVL3_MASK32 ))

/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_POWER_LEVEL2_U32(pwr_level)        ((uint32)( (uint32)((pwr_level) << MC_ME_MODE_SEC_CC_I_PWRLVL2_SHIFT32) & MC_ME_MODE_SEC_CC_I_PWRLVL2_MASK32 ))

/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_POWER_LEVEL1_U32(pwr_level)        ((uint32)( (uint32)((pwr_level) << MC_ME_MODE_SEC_CC_I_PWRLVL1_SHIFT32) & MC_ME_MODE_SEC_CC_I_PWRLVL1_MASK32 ))

#define MC_ME_SYSCLK3_ARM_PLL_DFS3_U32           (MC_ME_MODE_SEC_CC_I_SYSCLK3_ARM_PLL_DFS3_U32)
#define MC_ME_SYSCLK3_XOSC_U32                   (MC_ME_MODE_SEC_CC_I_SYSCLK3_XOSC_U32)
#define MC_ME_SYSCLK3_FIRC_U32                   (MC_ME_MODE_SEC_CC_I_SYSCLK3_FIRC_U32)

#define MC_ME_SYSCLK2_ARM_PLL_DFS2_U32           (MC_ME_MODE_SEC_CC_I_SYSCLK2_ARM_PLL_DFS2_U32)
#define MC_ME_SYSCLK2_XOSC_U32                   (MC_ME_MODE_SEC_CC_I_SYSCLK2_XOSC_U32)
#define MC_ME_SYSCLK2_FIRC_U32                   (MC_ME_MODE_SEC_CC_I_SYSCLK2_FIRC_U32)

#define MC_ME_SYSCLK1_ARM_PLL_U32                (MC_ME_MODE_SEC_CC_I_SYSCLK1_ARM_PLL_U32)
#define MC_ME_SYSCLK1_XOSC_U32                   (MC_ME_MODE_SEC_CC_I_SYSCLK1_XOSC_U32)
#define MC_ME_SYSCLK1_FIRC_U32                   (MC_ME_MODE_SEC_CC_I_SYSCLK1_FIRC_U32)
    
/********** Generic Defines **********/

/* Default configuration for Fast Wakeup settings. */
/** @violates @ref Mcu_MC_ME_Types_h_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
#define MC_ME_FAST_MODE_CONFIG_DEFAULT_U32      ((uint32)0x00000000U)

#ifdef MCU_ERR009139_IPV_MC_05000007
#if (MCU_ERR009139_IPV_MC_05000007 == STD_ON)
/*****************************************************************************/
/*  GPR SLEEP Register (GPR_SLEEP)   */
/****************************************************************************/
/** @violates @ref Mcu_MC_ME_Types_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.*/
#define MC_ME_GPR_SLEEP_VALUE_U32(value)            ((uint32)(( (value) & MC_ME_GPR_SLEEP_RWBITS_MASK32 ) | MC_ME_GPR_SLEEP_RESBITS_MASK32))

#endif  /* MCU_ERR009139_IPV_MC_05000007 */
#endif  /* (MCU_ERR009139_IPV_MC_05000007 == STD_ON) */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#if ((MCU_GET_PERIPH_STATE_API == STD_ON) || (defined MCU_GET_INTERNAL_STATE))
/**
* @brief            List of peripherals that can be interogated for state: frozen/active.
* @details          Result is reported from ME_PS0..3 registers.
*/
typedef enum
{

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_BCTU          = 0U,
    S_EMIOS_0       = 1U,
    S_EMIOS_1       = 2U,
    S_EMIOS_2       = 3U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_DMA_CH_MUX_0  = 1U,
    S_I2C_0         = 2U,
    S_I2C_1         = 3U,
#endif


#if (IPV_MC == IPV_MC_04_00_15_15)
    S_EBI_0         = 3U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_FLEXTIMER_0   = 4U,
    S_FLEXTIMER_1   = 5U,
    S_FLEXTIMER_2   = 6U,
    S_FLEXTIMER_3   = 7U,
    S_AN_CMP_0      = 9U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_USB_OTG   = 4U,
    S_USB_SPH   = 5U,
    S_MLB       = 6U,
    S_SDHC      = 7U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_LFAST_0       = 9U,
#elif (IPV_MC == IPV_MC_04_03_00_00)
    S_DIGRF_0       = 9U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_AN_CMP_1      = 10U,
    S_SMC           = 11U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_SAI_0           = 10U,
    S_SAI_1           = 11U,
    S_SAI_2           = 12U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_04_01_00_00) \
    )
    S_SIPI_0        = 11U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_ETH_0         = 12U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_SSD_0         = 12U,
    S_SSD_1         = 13U,
    S_SSD_2         = 14U,
    S_SSD_3         = 15U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_ENET         = 15U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_SIUL          = 15U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_SIUL2         = 15U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_SSD_4         = 16U,
    S_SSD_5         = 17U,
    S_DSPI_0        = 19U,
    S_DSPI_1        = 20U,
    S_DSPI_2        = 21U,
    S_DSPI_3        = 22U,
    S_DSPI_4        = 23U,
    S_LINFLEX_0     = 24U,
    S_LINFLEX_1     = 25U,
    S_LINFLEX_2     = 26U,
    S_SEG_LCD       = 27U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_MPR           = 18U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_CMP_0         = 20U,
    S_CMP_1         = 21U,
    S_CMP_2         = 22U,
    S_ADC_0         = 24U,
    S_ADC_1         = 25U,
    S_FLEXRAY       = 28U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_CAN_1         = 28U,
    S_CAN_2         = 29U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_DECFILT_1     = 28U,
    S_DECFILT_0     = 29U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_IIC_0         = 30U,
    S_IIC_1         = 31U,
    S_IIC_2         = 32U,
    S_IIC_3         = 33U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00))
    S_PIT_0         = 30U,
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
       (IPV_MC == IPV_MC_04_06_05_00) \
      )
    S_PIT_RTC_0     = 30U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_PIT_RTI_0     = 30U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_SARADC_0      = 30U,
#endif

#if (IPV_MC == IPV_MC_04_03_00_00)
    S_PIT_1         = 31U,
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
       (IPV_MC == IPV_MC_04_06_05_00) \
      )
    S_PIT_RTC_1     = 31U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_PIT_RTI_1     = 31U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_CRC           = 34U,
#endif

#if (IPV_MC == IPV_MC_04_03_00_00)
    S_ATX           = 34U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_DMAMUX_0      = 36U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_DMA_CH_MUX0_2 = 36U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_PIT_RTI_O     = 36U,
#endif

 #if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    S_CRC_0         = 38U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_DEC200         = 39U,
    S_2D_ACE         = 40U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_DSPI_0        = 40U,
    S_DSPI_1        = 41U,
    S_DSPI_2        = 42U,
    S_DSPI_3        = 43U,
#endif

#if ((IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_JTAGM         = 45U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_DTS           = 49U,
    S_PDI           = 55U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_CSI0          = 48U,
    S_DMACHMUX0     = 49U,
    S_ENET          = 50U,
    S_FRAY          = 52U,
    S_MMDC0         = 54U,
    S_PIT0          = 58U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_LIN_0        = 50U,
    S_LIN_1        = 51U,
    S_LIN_2        = 52U,
    S_LIN_3        = 53U,
    S_LIN_4        = 54U,
    S_LIN_5        = 55U,
    S_LIN_6        = 56U,
    S_LIN_7        = 57U,
    S_LIN_8        = 58U,
    S_LIN_9        = 59U,
    S_LIN_10       = 60U,
    S_LIN_11       = 61U,
    S_LIN_12       = 62U,
    S_LIN_13       = 63U,
    S_LIN_14       = 64U,
    S_LIN_15       = 65U,
    S_LIN_16       = 66U,
    S_LIN_17       = 67U,
#endif

#if (IPV_MC == IPV_MC_04_00_15_15)
    S_ADCSD_8       = 56U,
    S_ADCSD_6       = 57U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_ADCSD_4       = 58U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    S_ADCSD_2       = 59U,
    S_ADCSD_0       = 60U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_SIUL          = 60U,
#endif

#if (IPV_MC == IPV_MC_04_00_15_15)
    S_MCAN_4        = 67U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_MCAN_3        = 68U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_MCAN_2        = 69U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_ADCSAR_2      = 69U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_FLEXCAN_0        = 70U,
    S_FLEXCAN_1        = 71U,
    S_FLEXCAN_2        = 72U,
    S_FLEXCAN_3        = 73U,
    S_FLEXCAN_4        = 74U,
    S_FLEXCAN_5        = 75U,
    S_FLEXCAN_6        = 76U,
    S_FLEXCAN_7        = 77U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_MCAN_1        = 70U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_ADCSAR_0      = 71U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_TTCAN         = 72U,
    S_CAN_RAM_CTRL  = 74U,
#endif

#if (IPV_MC == IPV_MC_04_06_05_00)
    S_MCAN          = 75U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_FLEXCAN_3     = 76U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_SARADC0       = 77U,
    S_FLEXTIMER0    = 79U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00))
    S_CAN_2         = 77U,
    S_CAN_1         = 78U,
    S_CAN_0         = 79U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_IIC0          = 81U,
    S_LINFLEX0      = 83U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_TDM        = 81U,
    S_JDC        = 82U,
    S_MEMU_0     = 83U,
    S_CRC        = 84U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_FLEXCAN_2     = 81U,
    S_FLEXCAN_0     = 83U,
#endif

#if (IPV_MC == IPV_MC_04_00_15_15)
    S_LINFLEXD_16   = 84U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_RTC_API       = 84U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_LINFLEXD_14   = 85U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_LINFLEX_M0    = 85U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_CANFD0        = 85U,
    S_DSPI0         = 87U,
    S_DSPI2         = 89U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_FLEXCAN_0     = 88U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_DMAMUX        = 90U,
    S_PIT_RTI_0     = 91U,
    S_WKPU          = 93U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_LIN_2         = 90U,
#elif (IPV_MC == IPV_MC_04_01_00_00)
    S_LINFLEXD_A2   = 90U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_CRC0          = 91U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00))
    S_LINFLEX_1     = 91U,
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_LINFLEXD_1    = 91U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_LINFLEX_2     = 91U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_LINFLEX_3     = 92U,
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_LINFLEXD_0    = 92U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_LINFLEX_0     = 92U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_SDHC          = 93U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_DSPI_12       = 93U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_SPI0       = 96U,
    S_SPI1       = 97U,
    S_SPI2       = 98U,
    S_SPI3       = 99U,
    S_SPI4       = 100U,
    S_SPI5       = 101U,
    S_RTC_API    = 102U,
#endif

#if (IPV_MC == IPV_MC_04_00_15_15)
    S_DSPI_6        = 96U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_DSPI_M0       = 96U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    S_DSPI_4        = 97U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_DSPI_1        = 98U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_DSPI_2        = 98U,
#endif

 #if((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    S_DSPI_0        = 99U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_IIC_2         = 100U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_VIU0       = 100U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_IIC_0         = 101U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_IIC_1         = 102U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_EMIOS_0       = 102U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) \
    )
    S_SENT_0        = 104U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_HPSMI        = 104U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_07)
    S_MEMU_1      = 105U
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_01_00_00))
    S_FLEXRAY       = 107U,
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_05_00) ||\
       (IPV_MC == IPV_MC_04_03_00_00) \
      )
    S_FLEXRAY_0     = 107U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_PSI5_0        = 111U,
    S_ADCSAR_B      = 112U,
    S_ADCSAR_4      = 123U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_SIPI         = 116U,
    S_LFAST        = 120U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00))
    S_ADC_3         = 124U,
    S_ADC_1         = 126U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_ADCSAR_0      = 127U,
    S_GTMINT        = 128U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_QSPI_0        = 128U,
    S_QSPI_1        = 129U,
    S_DRAM_CTRLR    = 132U,
    S_ACE_0         = 136U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_ETIMER_1      = 137U,
    S_CTU_1         = 141U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_DMA_CH_MUX3   = 143U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00))
    S_PWM_1         = 144U,
    S_DMAMUX_1      = 146U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_CRC_1         = 148U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_ACE_1         = 152U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_CSI1          = 160U,
    S_DMACHMUX1     = 161U,
    S_MMDC1         = 162U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_PSI5_S_0      = 162U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    S_CRC_1         = 166U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_QUADSPI0      = 166U,
    S_PIT1          = 170U,
    S_FLEXTIMER1    = 182U,    
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_VIU           = 168U,
    S_GC355         = 172U,
    S_TCON          = 176U,
    S_TCON_LITE     = 180U,
    S_RLE           = 184U,
#endif


#if (IPV_MC == IPV_MC_04_00_15_15)
    S_ADCSD_9       = 184U,
    S_ADCSD_7       = 185U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_IIC1          = 184U,
    S_IIC2          = 186U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_ADCSD_5       = 186U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_SPT           = 187U,
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_ADCSD_3       = 187U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_LINFLEX1      = 188U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_SGM           = 188U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_CTE           = 188U,
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
       (IPV_MC == IPV_MC_04_06_01_00) \
      )
    S_ADCSD_1       = 188U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_CANFD1        = 190U,
    S_DSPI1         = 192U,
    S_DSPI3         = 194U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_DMA_0         = 192U,
    S_DMA_1         = 193U,
    S_ENET          = 196U,
    S_LDB           = 200U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_ADCSAR_3      = 196U,
    S_IGF           = 197U,
    S_ADCSAR_1      = 198U,
    S_ETPU_SCRAM_0  = 202U,
    S_ETPU_SCRAM_1  = 203U,
#endif

#if (IPV_MC == IPV_MC_05_00_00_10)
    S_MLB           = 204U
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_LINFLEX_0     = 204U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_ETPU_SPRAM_0  = 204U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_CRC1          = 204U,
    S_TSENS         = 206U,
    S_VIU1          = 208U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_ETPU_SPRAM_1  = 205U,
    S_REACM         = 206U,
    S_ETPU          = 207U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_DSPI_3        = 208U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_FLEXCAN_3     = 208U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_DSPI_2        = 209U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_FLEXCAN_1     = 210U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_JPEG          = 212U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_LINFLEXD_15   = 213U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_LINFLEX_M1    = 213U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00))
    S_SENT_1        = 214U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_H264_DEC      = 216U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_LINFLEX_3     = 219U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_LINFLEXD_2    = 220U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_LINFLEX_1     = 220U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_H264_ENC      = 220U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_DSPI_5        = 225U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_DSPI_M1       = 225U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    S_DSPI_3        = 226U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_DSPI_2        = 227U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_DSPI_1        = 227U,
#endif

#if (IPV_MC == IPV_MC_04_00_15_15)
    S_IIC_1         = 229U,
#endif

#if (IPV_MC == IPV_MC_04_06_01_00)
    S_EMIOS_1       = 230U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) \
    )
    S_SENT_1        = 232U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_ADC_2         = 235U,
#elif (IPV_MC == IPV_MC_04_00_15_15)
    S_FLEXRAY_1     = 235U,
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    S_MBIST         = 220U
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_ADC_0         = 237U,
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
    S_WGM_0         = 238U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_SGEN_0        = 239U,
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_PSI5_1        = 239U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_ETIMER_2      = 245U,
#elif (IPV_MC == IPV_MC_04_00_15_15)
    S_ADCSAR_10     = 245U,
#endif

#if (IPV_MC == IPV_MC_04_00_15_15)
    S_ADCSAR_9      = 246U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_ETIMER_0      = 247U,
#elif (IPV_MC == IPV_MC_04_00_15_15)
    S_ADCSAR_8      = 247U,
#endif

#if ((IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_00_15_15))
    S_ADCSAR_7      = 248U,
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_ADCSAR_6      = 249U,
#endif

#if (IPV_MC == IPV_MC_04_00_15_15)
    S_ADCSAR_5      = 250U,
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_CTU_0         = 251U,
#elif (IPV_MC == IPV_MC_04_06_01_00)
    S_BTCU          = 251U
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    S_ADCSAR_3      = 252U,
    S_ADCSAR_2      = 253U,
    S_ADCSAR_1      = 254U
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_03_00_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    S_PWM_0         = 255U
#endif

} Mcu_PeripheralIdType;

#endif /* ((MCU_GET_PERIPH_STATE_API == STD_ON) || (defined MCU_GET_INTERNAL_STATE)) */

/**
* @brief            Power Modes encoding.
* @details          Supported power modes for MC_ME hw IP.
*/
typedef enum
{
    MCU_RESET_MODE  = 0x0U,   /**< @brief Reset Mode. */
    MCU_TEST_MODE   = 0x1U,   /**< @brief Test Mode. */
    MCU_SAFE_MODE   = 0x2U,   /**< @brief Safe Mode. */
    MCU_DRUN_MODE   = 0x3U,   /**< @brief Drun Mode. */
    MCU_RUN0_MODE   = 0x4U,   /**< @brief Run0 Mode. */
    MCU_RUN1_MODE   = 0x5U,   /**< @brief Run1 Mode. */
    MCU_RUN2_MODE   = 0x6U,   /**< @brief Run2 Mode. */
    MCU_RUN3_MODE   = 0x7U,   /**< @brief Run3 Mode. */
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    MCU_HALT0_MODE  = 0x8U,   /**< @brief Halt0 Mode. */
    MCU_STOP0_MODE  = 0xAU,   /**< @brief Stop0 Mode. */
#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
    MCU_STBY0_MODE  = 0xDU,   /**< @brief StandBy0 Mode. */
#endif
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
    MCU_DEST_RESET_MODE = 0xFU,   /**< @brief Reset Mode. */

    MCU_CURRENT_MODE = 0x1FU   /**< @brief Any other Mode. */

} Mcu_PowerModeType;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCU_POWERMODE_STATE_API == STD_ON)
/**
* @brief            State of the current power mode.
* @details          Used to store the value of ME_GS register value.
*/
typedef VAR( uint32, MCU_VAR) Mcu_PowerModeStateType;
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */

typedef struct
{
   VAR( uint32, MCU_VAR) u32RegisterAddr;   /* register address, added by hand in the code template */
   VAR( uint8 , MCU_VAR) u8RegisterData;    /* generated value, as it's already defined */

} Mcu_MC_ME_RegisterConfigType;


typedef struct
{
   VAR( uint32, MCU_VAR) u32RegisterAddr;   /* register address, added by hand in the code template */
   VAR( uint16, MCU_VAR) u16RegisterData;   /* generated value, as it's already defined */

} Mcu_MC_ME_CoreConfigType;


typedef struct
{
   VAR( uint32, MCU_VAR) u32RegisterAddr;   /* register address, added by hand in the code template */
   VAR( uint32, MCU_VAR) u32RegisterMask;   /* generated mask, as it isn't already defined */
   VAR( uint32, MCU_VAR) u32RegisterData;   /* generated value, as it's already defined */

} Mcu_MC_ME_CoreAddressConfigType;


/**
* @brief            Configuration of MC_ME hw IP
* @details          This data configuration is set at module initialization phase.
*/
typedef struct
{
    VAR( uint32, MCU_VAR) u32RunConfig0;   /**< @brief Configuration for ME_RUN_PC0. */
    VAR( uint32, MCU_VAR) u32RunConfig1;   /**< @brief Configuration for ME_RUN_PC1. */
    VAR( uint32, MCU_VAR) u32RunConfig2;   /**< @brief Configuration for ME_RUN_PC2. */
    VAR( uint32, MCU_VAR) u32RunConfig3;   /**< @brief Configuration for ME_RUN_PC3. */
    VAR( uint32, MCU_VAR) u32RunConfig4;   /**< @brief Configuration for ME_RUN_PC4. */
    VAR( uint32, MCU_VAR) u32RunConfig5;   /**< @brief Configuration for ME_RUN_PC5. */
    VAR( uint32, MCU_VAR) u32RunConfig6;   /**< @brief Configuration for ME_RUN_PC6. */
    VAR( uint32, MCU_VAR) u32RunConfig7;   /**< @brief Configuration for ME_RUN_PC7. */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* no low power modes on this version */
#else
    VAR( uint32, MCU_VAR) u32LowPwrConfig0;   /**< @brief Configuration for ME_LP_PC0. */
    VAR( uint32, MCU_VAR) u32LowPwrConfig1;   /**< @brief Configuration for ME_LP_PC1. */
    VAR( uint32, MCU_VAR) u32LowPwrConfig2;   /**< @brief Configuration for ME_LP_PC2. */
    VAR( uint32, MCU_VAR) u32LowPwrConfig3;   /**< @brief Configuration for ME_LP_PC3. */
    VAR( uint32, MCU_VAR) u32LowPwrConfig4;   /**< @brief Configuration for ME_LP_PC4. */
    VAR( uint32, MCU_VAR) u32LowPwrConfig5;   /**< @brief Configuration for ME_LP_PC5. */
    VAR( uint32, MCU_VAR) u32LowPwrConfig6;   /**< @brief Configuration for ME_LP_PC6. */
    VAR( uint32, MCU_VAR) u32LowPwrConfig7;   /**< @brief Configuration for ME_LP_PC7. */
#endif

    /**< @brief number of pctl regs under mcu control */
    VAR ( uint8, MCU_VAR)  u8NumberOfPctlRegisters;
    /* auxiliary clock dividers */
    CONST( Mcu_MC_ME_RegisterConfigType, MCU_CONST) (*apPctControl)[];

    VAR( uint32, MCU_VAR) u32EnabledModes;      /**< @brief Configuration for ME_ME. */
    VAR( uint32, MCU_VAR) u32IsrMode;           /**< @brief Configuration for ME_IM (interrupt masking). */

    /* core address registers */
    VAR ( uint8, MCU_VAR) u8NumberOfCoreAddrRegs;                           /**< @brief number of CADDR registers */
    CONST( Mcu_MC_ME_CoreAddressConfigType, MCU_CONST) (*apCoreAddress)[];  /**< @brief configuration of CADDR registers */
    
    /* core control registers */
    VAR ( uint8, MCU_VAR) u8NumberOfCoreCtrlRegs;                           /**< @brief number of CCTL registers */
    CONST( Mcu_MC_ME_CoreConfigType, MCU_CONST) (*apCoreControl)[];         /**< @brief configuration of CCTL registers */

} Mcu_MC_ME_ConfigType;


/**
* @brief            Definition of a MCU mode section in the configuration structure.
* @details          Specifies the system behaviour during the selected target mode.
*                   Data set and configured by Mcu_SetMode call.
*/
typedef struct
{
    /**< @brief The ID for Power Mode configuration. */
    VAR( Mcu_ModeType, MCU_VAR) Mcu_ModeConfigId;
    /**< @brief The Power Mode name (code). */
    VAR( Mcu_PowerModeType, MCU_VAR) Mcu_ePowerMode;
    /**
    * < @brief System behaviour in the target mode
    * (SysClk<<0 + 16RC<<4 + XOSC<<5 + PLL0<<6 + CFlash<<16 +
    * DFlash<<18 + MainVolReg<<20 + PowDownIO<<23).
    */
    VAR( uint32, MCU_VAR) Mcu_u32ModeParams;
    
#if (IPV_MC == IPV_MC_06_00_00_10)
    /**< @brief Configuration for MC_ME_<MODE>_SEC_CC_I */
    VAR( uint32, MCU_VAR) Mcu_u32SecondaryClockConfig;
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* there are no lower power modes on this version */
#else
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    /**
    * < @brief When a transition to low power mode is requested (HALT/STOP) can modify the current
    * RUN mode settings to have it changed when the recover from low power will encounter.
    */
    VAR( boolean, MCU_VAR) Mcu_bFastWakeup;
    /**< @brief System behaviour in the current mode after exiting wakeup. */
    VAR( uint32, MCU_VAR) Mcu_u32FastWakeupParams;
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
#endif

#if ( MCU_CONFIGURE_CADDRN == STD_ON )
    /* core address registers */
    VAR ( uint8, MCU_VAR) u8NumberOfCoreAddrRegs;                           /**< @brief number of CADDR registers */
    CONST( Mcu_MC_ME_CoreAddressConfigType, MCU_CONST) (*apCoreAddress)[];  /**< @brief configuration of CADDR registers */
#endif /* MCU_CONFIGURE_CADDRN == STD_ON */

#ifdef MCU_ERR009139_IPV_MC_05000007
#if (MCU_ERR009139_IPV_MC_05000007 == STD_ON)
    VAR( uint32, MCU_VAR) u32GprSleepMode;          /**< @brief GPR SLEEP register. */
#endif  /* MCU_ERR009139_IPV_MC_05000007 */
#endif  /* (MCU_ERR009139_IPV_MC_05000007 == STD_ON) */

} Mcu_ModeConfigType;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_MC_ME_TYPES_H */

/** @} */
