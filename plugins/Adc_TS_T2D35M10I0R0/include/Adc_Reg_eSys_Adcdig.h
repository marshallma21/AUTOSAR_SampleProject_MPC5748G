/**
*   @file    Adc_Reg_eSys_Adcdig.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - module register and macro definitions.
*   @details Adc module registers, and macro definitions used to manipulate the module registers.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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

#ifndef REG_ESYS_ADCDIG_H
#define REG_ESYS_ADCDIG_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Reg_eSys_Adcdig_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
* 
* @section Adc_Reg_eSys_Adcdig_h_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Adc_Reg_eSys_Adcdig_h_REF_3
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function. These objects are used in various parts of the code
*
* @section Adc_Reg_eSys_Adcdig_h_REF_6
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "Adc_Cfg.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_REG                      43
#define ADC_AR_RELEASE_MAJOR_VERSION_REG       4
#define ADC_AR_RELEASE_MINOR_VERSION_REG       2
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_6 Identifier clash */
#define ADC_AR_RELEASE_REVISION_VERSION_REG    2
#define ADC_SW_MAJOR_VERSION_REG               1
#define ADC_SW_MINOR_VERSION_REG               0
#define ADC_SW_PATCH_VERSION_REG               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Reg_eSys.h are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_REG != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_REG != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
    )
#error "AutoSar Version Numbers of Adc_Reg_eSys_Adcdig.h and Reg_eSys.h are different"
#endif
#endif

/* Check if source file and ADC configuration header file are of the same vendor */
#if (ADC_VENDOR_ID_REG != ADC_VENDOR_ID_CFG)
#error "Adc_Reg_eSys_Adcdig.h and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_REG != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_REG != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_REG != ADC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Adc_Reg_eSys_Adcdig.h and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((ADC_SW_MAJOR_VERSION_REG != ADC_SW_MAJOR_VERSION_CFG) || \
     (ADC_SW_MINOR_VERSION_REG != ADC_SW_MINOR_VERSION_CFG) || \
     (ADC_SW_PATCH_VERSION_REG != ADC_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Adc_Reg_eSys_Adcdig.h and Adc_Cfg.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define IPV_ADCDIG_00_00_01_02 (0x00000102UL) /**< @brief RaceRunner */
#define IPV_ADCDIG_00_00_03_01 (0x00000301UL) /**< @brief Panther */
#define IPV_ADCDIG_00_00_04_12 (0x00000412UL) /**< @brief Rainier cut 1.0*/
#define IPV_ADCDIG_00_00_04_14 (0x00000414UL) /**< @brief Halo cut 1.0*/
#define IPV_ADCDIG_00_00_04_09 (0x00000409UL) /**< @brief Calypso 6M/3M cut 2.0 and Rainier cut 2.0 */
#define IPV_ADCDIG_01_00_04_06 (0x01000406UL) /**< @brief Treerunner */

#define ADC_START_SEC_CONST_32
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

/**
* @brief base address array for ADCDig
*/
extern CONST(uint32, ADC_CONST) ADCDIG_BASE_ADDR32[ADC_MAX_HW_UNITS];

/**
* @brief offset from ADC unit base address for registers ADC_THRHLRn 
*/
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_3 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern CONST(uint32, ADC_CONST) ADCDIG_THR_REG_OFFSETS_U32[16];
    
#define ADC_STOP_SEC_CONST_32
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          ADC Base address definition.
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_ADDR32(HwUnit)          (ADCDIG_BASE_ADDR32[(HwUnit)])   

/**
* @brief          Main Configuration Register (MCR).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_MCR_REG_ADDR32(HwUnit)           (ADCDIG_ADDR32(HwUnit) + 0x0000UL)

/**
* @brief          Main Status Register (MSR).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_MSR_REG_ADDR32(HwUnit)           (ADCDIG_ADDR32(HwUnit) + 0x0004UL)

/**
* @brief          Reserved From 0x0008 to 0x000F.
*/

/**
* @brief          Interrupt Status Register (ISR).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_ISR_REG_ADDR32(HwUnit)           (ADCDIG_ADDR32(HwUnit)+0x0010UL)

/**
* @brief          Channel Pending Register (CEOCFR0-2).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_CEOCFR0_REG_ADDR32(HwUnit)             (ADCDIG_ADDR32(HwUnit)+0x0014UL)
#if (ADC_CEOCFR1_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_CEOCFR1_REG_ADDR32(HwUnit)           (ADCDIG_ADDR32(HwUnit)+0x0018UL)
#endif
#if (ADC_CEOCFR2_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_CEOCFR2_REG_ADDR32(HwUnit)           (ADCDIG_ADDR32(HwUnit)+0x001CUL)
#endif

/**
* @brief          Interrupt Mask Register (IMR).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_IMR_REG_ADDR32(HwUnit)           (ADCDIG_ADDR32(HwUnit)+0x0020UL)

/**
* @brief          Watchdog Threshold Interrupt Status Register (WTISR).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_WTISR_REG_ADDR32(HwUnit)         (ADCDIG_ADDR32(HwUnit)+0x0030UL)

/**
* @brief          Watchdog Threshold Interrupt Mask Register (WTIMR).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_WTIMR_REG_ADDR32(HwUnit)         (ADCDIG_ADDR32(HwUnit)+0x0034UL)

/**
* @brief          DMAE Register (DMAE).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_DMAE_REG_ADDR32(HwUnit)             (ADCDIG_ADDR32(HwUnit)+0x0040UL)

/**
* @brief          DMA Channel Select Register(DMAR0-2).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_DMAR0_REG_ADDR32(HwUnit)            (ADCDIG_ADDR32(HwUnit)+0x0044UL)
#if (ADC_DMAR1_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_DMAR1_REG_ADDR32(HwUnit)          (ADCDIG_ADDR32(HwUnit)+0x0048UL)
#endif
#if (ADC_DMAR2_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_DMAR2_REG_ADDR32(HwUnit)          (ADCDIG_ADDR32(HwUnit)+0x004CUL)
#endif

/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_THRHLRx_REG_ADDR32(HwUnit, regNr)   (ADCDIG_ADDR32(HwUnit)+ ADCDIG_THR_REG_OFFSETS_U32[(regNr)])

/**
* @brief          Presampling Control Register (PSCR).
* @details        Presampling Register (PSR0-2).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_PSCR_REG_ADDR32(HwUnit)               (ADCDIG_ADDR32(HwUnit)+0x0080UL)

/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_PSR0_REG_ADDR32(HwUnit)               (ADCDIG_ADDR32(HwUnit)+0x0084UL)
#if (ADC_PSR1_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_PSR1_REG_ADDR32(HwUnit)           (ADCDIG_ADDR32(HwUnit)+0x0088UL)
#endif
#if (ADC_PSR2_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_PSR2_REG_ADDR32(HwUnit)           (ADCDIG_ADDR32(HwUnit)+0x008CUL)
#endif

/**
* @brief          Conversion Timing Register (CTR0-2).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_CTR0_REG_ADDR32(HwUnit)          (ADCDIG_ADDR32(HwUnit)+0x0094UL)
#if (ADC_CTR1_AVAILABLE == STD_ON)
  /**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_CTR1_REG_ADDR32(HwUnit)          (ADCDIG_ADDR32(HwUnit)+0x0098UL)
#endif
#if (ADC_CTR2_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_CTR2_REG_ADDR32(HwUnit)      (ADCDIG_ADDR32(HwUnit)+0x009CUL)
#endif

/**
* @brief          Normal Conversion Mask Register (NCMR0-2).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_NCMR0_REG_ADDR32(HwUnit)            (ADCDIG_ADDR32(HwUnit)+0x00A4UL)
#if (ADC_NCMR1_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_NCMR1_REG_ADDR32(HwUnit)          (ADCDIG_ADDR32(HwUnit)+0x00A8UL)
#endif
#if (ADC_NCMR2_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_NCMR2_REG_ADDR32(HwUnit)          (ADCDIG_ADDR32(HwUnit)+0x00ACUL)
#endif

/**
* @brief          Reserved From 0x00B0 t0 0x00B3.
*/

/**
* @brief          Injected Conversion Mask Register (JCMR0-2).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_JCMR0_REG_ADDR32(HwUnit)         (ADCDIG_ADDR32(HwUnit)+0x00B4UL)
#if (ADC_JCMR1_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_JCMR1_REG_ADDR32(HwUnit)              (ADCDIG_ADDR32(HwUnit)+0x00B8UL)
#endif
#if (ADC_JCMR2_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_JCMR2_REG_ADDR32(HwUnit)              (ADCDIG_ADDR32(HwUnit)+0x00BCUL)
#endif

/**
* @brief          Decode Signals Delay Register (DSDR).
*
*/
#if (ADC_DSDR_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_DSDR_REG_ADDR32(HwUnit)          ((ADCDIG_ADDR32((HwUnit))+0x00C4UL))
#endif

/**
* @brief          Power-down Exit Delay Register (PDEDR).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_PDEDR_REG_ADDR32(HwUnit)         (ADCDIG_ADDR32(HwUnit)+0x00C8UL)

/**
* @brief          Displacement of the first channel data register
*                 address relative to the ADC base address.
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_CH_DATA_REGISTERS_START_ADDRESS_OFFSET_U32 (0x0100UL)
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_CH_DATA_REG_ADDR32(HwUnit,Ch) \
 (ADCDIG_ADDR32(HwUnit)+ ADCDIG_CH_DATA_REGISTERS_START_ADDRESS_OFFSET_U32 + ((uint32)(Ch) << 2UL))

/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_CWSELRx_REG_ADDR32(HwUnit, regNr)     (ADCDIG_ADDR32(HwUnit)+ 0x2B0UL + (uint32)((regNr) << 2UL))
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_CWENRx_REG_ADDR32(HwUnit, regNr)     (ADCDIG_ADDR32(HwUnit)+ 0x02E0UL + (uint32)((regNr) << 2UL))

/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_CWENR0_REG_ADDR32(HwUnit)        (ADCDIG_ADDR32(HwUnit)+0x02E0UL)
#if (ADC_CWENR1_AVAILABLE == STD_ON)
  /**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_CWENR1_REG_ADDR32(HwUnit)        (ADCDIG_ADDR32(HwUnit)+0x02E4UL)
#endif
#if (ADC_CWENR2_AVAILABLE == STD_ON)
  /**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_CWENR2_REG_ADDR32(HwUnit)        (ADCDIG_ADDR32(HwUnit)+0x02E8UL)
#endif

/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_AWORR0_REG_ADDR32(HwUnit)        (ADCDIG_ADDR32(HwUnit)+0x02F0UL)
#if (ADC_AWORR1_AVAILABLE == STD_ON)
  /**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_AWORR1_REG_ADDR32(HwUnit)        (ADCDIG_ADDR32(HwUnit)+0x02F4UL)
#endif
#if (ADC_AWORR2_AVAILABLE == STD_ON)
  /**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_AWORR2_REG_ADDR32(HwUnit)        (ADCDIG_ADDR32(HwUnit)+0x02F8UL)
#endif

#define ADCDIG_CWSEL_RESET_VALUE_U32          (0x0UL)
#define ADCDIG_CWENR_RESET_VALUE_U32          (0x0UL)
#define ADCDIG_AWORR_REG_RESET_VALUE_U32      (0xFFFFFFFFUL)

/**
* @brief          Self Test Configuration Register 1 (ADCx_STCR1).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_STCR1_REG_ADDR32(HwUnit)                   (ADCDIG_ADDR32(HwUnit) + 0x0340UL)

/**
* @brief          Self Test Configuration Register 2 (ADCx_STCR2).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_STCR2_REG_ADDR32(HwUnit)                   (ADCDIG_ADDR32(HwUnit) + 0x0344UL)

/**
* @brief          Self Test Configuration Register 3 (ADCx_STCR3).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_STCR3_REG_ADDR32(HwUnit)                   (ADCDIG_ADDR32(HwUnit) + 0x0348UL)

/**
* @brief          Self Test Status Register 1 (ADCx_STSR1).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_STSR1_REG_ADDR32(HwUnit)                   (ADCDIG_ADDR32(HwUnit) + 0x0350UL)

/**
* @brief          Calibration, BIST and Status register (CALBISTREG).
*
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_CALBISTREG_REG_ADDR32(HwUnit)              (ADCDIG_ADDR32(HwUnit) + 0x03A0UL)

/**
* @brief          Offset to the lower part of the first Channel Data Register.
*/
#define ADCDIG_CH_DATA_REG_OFFSET_U32  ((uint32)ADCDIG_CH_DATA_REGISTERS_START_ADDRESS_OFFSET_U32 + 0x0002UL)

/**********************************************************************************
***************                   Main Configuration Register (MCR) **************
**********************************************************************************/
/**
* @brief          OWREN: Overwrite enable.
* @details        If set to 1 the conversion data is overwritten by a 
*                 newer result otherwise it is discarded.
*/
#define ADCDIG_OVERWRITE_EN_U32                        (0x80000000UL)

/**
* @brief          WLSIDE: Write left /right-aligned.
* @details        0: The conversion data is written right-aligned.
*                 1: Data is left-aligned (from 15 to (15- resolution + 1)).
*/
#define ADCDIG_WRITE_LEFT_ALIGNED_U32                  (0x40000000UL)
#define ADCDIG_WRITE_RIGHT_ALIGNED_U32                 (0x0UL)

/**
* @brief          Shift mask to align conversion results.
*/
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
#define ADCDIG_SHIFT_MASK_U32                 (0x0000FFFFUL)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/**
* @brief          MODE: One_Shot/Scan.
* @details        0: One_Shot Mode - Configures the Normal conversion of one chain.
*                 1: Scan Mode - Configures continuous chain conversion mode; when the
*                 programmed chain conversion is finished it restarts immediately.
*/
#define ADCDIG_CONTINUOUS_MODE_U32                     (0x20000000UL)
#define ADCDIG_CONVERSION_MODE_U32                     (ADCDIG_CONTINUOUS_MODE_U32)

/**
* @brief          TRGEN: External trigger enable.
* @details        Setting this bit will enable the external trigger for channel normal.
*/
#define ADCDIG_NORMAL_EXT_TRIGGER_EN_U32               (0x08000000UL)

/**
* @brief          EDGE: Start trigger edge detection.
* @details        Edge selection for external trigger; if EDGE is one this bit selects
*                 the falling (EDGE = 0) or rising (EDGE = 1) edge for the external trigger.
*/
#define ADCDIG_NORMAL_TRIGGER_RISING_EDGE_U32          (0x04000000UL)
#define ADCDIG_NORMAL_TRIGGER_EDGE_U32                 (ADCDIG_NORMAL_TRIGGER_RISING_EDGE_U32)

/**
* @brief          NSTART: Start conversion.
* @details        Setting this bit starts the chain or scan conversion, resetting this bit 
*                 during scan mode cause the current chain conversion to finish and stops 
*                 the operation.
*                 This bit keeps the high value until the conversion is ongoing 
*                 (or pending during injection mode).
*/
#define ADCDIG_NORMAL_START_CONV_EN_U32                (0x01000000UL)
#define ADCDIG_NORMAL_CONV_MASK_U32                    (0x01000000UL)
#define ADCDIG_NORMAL_CONV_STOP_U32                    (0x01000000UL)

/**
* @brief          JTRGEN: Injection external trigger enable.
* @details        Setting this bit will enable the external trigger for channel injection.
*/
#define ADCDIG_INJ_EXT_TRIGGER_EN_U32                  (0x00400000UL)

/**
* @brief          JEDGE: Injection trigger edge selection.
* @details        Edge selection for external trigger; if JTRGEN is one this bit selects
*                 the falling (JEDGE = 0) or rising (JEDGE = 1) edge for the external trigger.
*/
#define ADCDIG_INJ_TRIGGER_RISING_EDGE_U32             (0x00200000UL)
#define ADCDIG_INJ_TRIGGER_EDGE_U32                    (ADCDIG_INJ_TRIGGER_RISING_EDGE_U32)

/**
* @brief          JSTART: Injection start.
* @details        Setting this bit will start the configured injected analog channels to be
*                 converted by software; resetting this bit has no effect, as the injected chain
*                 conversion cannot be interrupted.
*/
#define ADCDIG_INJ_START_CONV_EN_U32                   (0x00100000UL)

/**
* @brief          CTUEN: Cross Trigger Unit Enable.
* @details        0: The cross triggering unit is disabled and the triggered injected 
*                 conversion cannot take place.
*                 1: The cross triggering unit is enabled and the triggered injected
*                 conversion can take place.
*/
#define ADCDIG_CTU_ENABLED_U32                         (0x00020000UL)

/**
* @brief          CTU_MODE: CrossTrigger MODE bit.
* @details        0: CTU control mode is selected.
*                 1: CTU trigger mode is selected.
*/
#define ADCDIG_CTU_TRIGGER_MODE_U32                    (0x00010000UL)

/**
* @brief          ADCLKSEL: Analog clock frequency selector. ADCLKDIV: Analog Clock divide factor 
* @details        If ADCLKSEL is set the AD_clk frequency is equal to ipg_clk frequency.
*                 Otherwise, it is half of ipg_clk frequency if ADCLKDIV is zero and is quarter if ADCLKDIV is set. Those bit can be written
*                 in power-down only.
*/
#define ADCDIG_CLOCK_PRESCALER_DIV1_U32                (0x00000100UL)
#define ADCDIG_CLOCK_PRESCALER_DIV2_U32                (0x0UL)
#define ADCDIG_CLOCK_PRESCALER_DIV4_U32                (0x00000010UL)

#ifdef ADC_PRESCALER_DIV4_SUPPORTED
#define ADCDIG_CLOCK_PRESCALER_MASK_U32                (0x00000110UL)
#else
#define ADCDIG_CLOCK_PRESCALER_MASK_U32                (0x00000100UL)
#endif
/**
* @brief          ABORT CHAIN: Abort Chain.
* @details        If this bit is set the ongoing chain conversion is aborted. This bit is reset
*                 by hardware as soon as a new conversion is requested.
*/
#define ADCDIG_ABORT_CHAIN_U32                         (0x00000080UL)

/**
* @brief          ACKO: Auto-clock-off enable.
* @details        If set enables the auto-clock-off feature.
*/
#define ADCDIG_AUTO_CLKOFF_EN_U32                      (0x00000020UL)
#define ADCDIG_AUTO_CLKOFF_DIS_U32                     (0x0UL)

/**
* @brief          PWDN: Power-down enable
* @details        When this bit is set, the analog module is requested to enter power-down mode.
*                 When ADC status is PWDN, resetting this bit will start ADC transition to IDLE mode.
*/

#define ADCDIG_POWER_DOWN_U32                          (0x00000001UL)
#if (IPV_ADCDIG == IPV_ADCDIG_01_00_04_06)
#define ADCDIG_MCR_RESET_VALUE_U32                     (0x00003901UL)
#else
#define ADCDIG_MCR_RESET_VALUE_U32                     (0x00000101UL)
#endif /* (IPV_ADCDIG == IPV_ADCDIG_01_00_04_06) */

/**********************************************************************************
***************               Main Status Register (MSR)             **************
**********************************************************************************/
/**
* @brief          CALIBRTD.
* @details        This status bit indicates the ADC calibration status.
*/
#define ADCDIG_CALIBRTD_STATUS_U32                     (0x80000000UL)
#define ADCDIG_CALIBRTD_CALIBRATED_U32                 (0x80000000UL)

/**
* @brief          NSTART.
* @details        This status bit is used to signal that a Normal conversion is ongoing.
*/
#define ADCDIG_NORMAL_CONV_STATUS_U32                  (0x01000000UL)
#define ADCDIG_NORMAL_CONV_ONGOING_U32                 (0x01000000UL)

/**
* @brief          SELF_TEST_S.
* @details        This status bit signals that self test conversion is ongoing.
*/
#define ADCDIG_SELF_TEST_S_U32                         (0x00040000UL)

/**
* @brief          CTUSTART.
* @details        This status bit is used to signal that a CTU conversion is ongoing.
*                 This bit is set when a CTU trigger pulse is received and the CTU conversion starts.
*                 When CTU trigger mode is enabled this bit is automatically reset when the conversion
*                 is completed. Otherwise, if Control Mode is enabled this bit is reset when the CTU 
*                 is disabled.
*/
#define ADCDIG_CTU_CONV_ONGOING_U32                    (0x00010000UL)
#define ADCDIG_CTU_CONV_FINISH_U32                     (0x0UL)

/**
* @brief          ADCSTATUS
* @details        Adc Status.
*/
#define ADCDIG_STATUS_U32                              (0x00000007UL)
#define ADCDIG_IDLE_OFFSET_STATUS_U32                  (0x00000000UL)
#define ADCDIG_POWERDOWN_STATUS_U32                    (0x00000001UL)
#define ADCDIG_BUSY_IN_HIGH_ACCURACY_STATUS_U32        (0x00000003UL)

/**********************************************************************************
***************               Interrupt Status Register (ISR)        **************
**********************************************************************************/
/**
* @brief          ECH.
* @details        End of chain conversion.
*/
#define ADCDIG_ISR_END_CHAIN_NORM_CONV_U32         (0x00000001UL)
#define ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32        (0x00000001UL)

/**
* @brief          EOC.
* @details        End of channel conversion.
*/
#define ADCDIG_ISR_END_CHANNEL_NORM_CONV_U32       (0x00000002UL)
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_6 Identifier clash */
#define ADCDIG_ISR_END_CHANNEL_NORM_CONV_CLEAN_U32 (0x00000002UL)

/**
* @brief          JECH.
* @details        End of injected chain conversion.
*/
#define ADCDIG_ISR_END_CHAIN_INJ_CONV_U32          (0x00000004UL)
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_6 Identifier clash */
#define ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32    (0x00000004UL)

/**
* @brief          JEOC.
* @details        End of injected channel conversion.
*/
#define ADCDIG_ISR_END_CHANNEL_INJ_CONV_U32        (0x00000008UL)
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_6 Identifier clash */
#define ADCDIG_ISR_END_CHANNEL_INJ_CONV_CLEAN_U32  (0x00000008UL)

/**
* @brief          EOCTU.
* @details        End of CTU conversion.
*                 It is the interrupt of the digital end of conversion for the CTU channel;
*                 active when set.
*/
#define ADCDIG_ISR_END_CHANNEL_CTU_CONV_U32        (0x00000010UL)
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_6 Identifier clash */
#define ADCDIG_ISR_END_CHANNEL_CTU_CONV_CLEAN_U32  (0x00000010UL)

#define ADCDIG_ISR_RESET_VALUE_U32                 (0x00000000UL)

#if ((ADC_BCTU_AVAILABLE == STD_ON) || (ADC_CTUV2_AVAILABLE == STD_ON))
    #define ADCDIG_ISR_CLEAR_VALUE_U32             (0x0000001FUL)
#else
    #define ADCDIG_ISR_CLEAR_VALUE_U32             (0x0000000FUL)
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */

/**********************************************************************************
***************        Interrupt Mask Register (IMR)                **************
**********************************************************************************/

/**
* @brief          MSKECH.
* @details        Mask bit for ECH.
*/
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_6 Identifier clash */
#define ADCDIG_ISR_END_CHAIN_NORM_CONV_EN_U32      (0x00000001UL)
/** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_6 Identifier clash */
#define ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32    (ADCDIG_ISR_END_CHAIN_NORM_CONV_EN_U32)

/**
* @brief          MSKJECH.
* @details        Mask bit for JECH.
*/
#define ADCDIG_ISR_END_CHAIN_INJ_CONV_EN_U32       (0x00000004UL)
#define ADCDIG_ISR_END_CHAIN_INJ_CONV_MASK_U32     (ADCDIG_ISR_END_CHAIN_INJ_CONV_EN_U32)

/**
* @brief          IMR reset value.
* @details        Reset value for IMR register.
*/
#define ADCDIG_IMR_RESET_VALUE_U32                 (0x0UL)

/**********************************************************************************
****************   WatchDog Threshold Interrupt Status Register (WTISR) ***********
**********************************************************************************/
/**
* @brief          WTISR reset value.
* @details        Reset value for WTISR register.
*/
#define ADCDIG_WTISR_RESET_VALUE_U32        (0x0UL)

/**********************************************************************************
**************   WatchDog Threshold Interrupt Mask Register (WTIMR)  **************
**********************************************************************************/
/**
* @brief          MSKWDG0L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 0.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH0_LOW_ISR_EN_U32         (0x00000001UL)

/**
* @brief          MSKWDG1L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 1.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH1_LOW_ISR_EN_U32         (0x00000004UL)

/**
* @brief          MSKWDG2L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 2.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH2_LOW_ISR_EN_U32         (0x00000010UL)

/**
* @brief          MSKWDG3L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 3.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH3_LOW_ISR_EN_U32          (0x00000040UL)

/**
* @brief          MSKWDG4L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 4.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH4_LOW_ISR_EN_U32          (0x00000100UL)

/**
* @brief          MSKWDG5L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 5.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH5_LOW_ISR_EN_U32          (0x00000400UL)

/**
* @brief          MSKWDG6L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 6.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH6_LOW_ISR_EN_U32          (0x00001000UL)

/**
* @brief          MSKWDG7L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 7.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH7_LOW_ISR_EN_U32           (0x00004000UL)

/**
* @brief          MSKWDG8L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 8.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH8_LOW_ISR_EN_U32           (0x00010000UL)

/**
* @brief          MSKWDG9L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 9.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH9_LOW_ISR_EN_U32           (0x00040000UL)

/**
* @brief          MSKWDG10L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 10.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH10_LOW_ISR_EN_U32          (0x00100000UL)

/**
* @brief          MSKWDG11L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 11.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH11_LOW_ISR_EN_U32          (0x00400000UL)

/**
* @brief          MSKWDG12L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 12.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH12_LOW_ISR_EN_U32          (0x01000000UL)

/**
* @brief          MSKWDG13L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 13.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH13_LOW_ISR_EN_U32           (0x04000000UL)

/**
* @brief          MSKWDG14L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 14.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH14_LOW_ISR_EN_U32           (0x10000000UL)

/**
* @brief          MSKWDG15L.
* @details        This corresponds to the mask bit for the interrupt generated on the converted 
*                 value being lower than the programmed lower threshold 15.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH15_LOW_ISR_EN_U32           (0x40000000UL)

/**
* @brief          MSKWDG0H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 0.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH0_HIGH_ISR_EN_U32           (0x00000002UL)

/**
* @brief          MSKWDG1H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 1.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH1_HIGH_ISR_EN_U32            (0x00000008UL)

/**
* @brief          MSKWDG2H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 2.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH2_HIGH_ISR_EN_U32            (0x00000020UL)

/**
* @brief          MSKWDG3H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 3.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH3_HIGH_ISR_EN_U32            (0x00000080UL)

/**
* @brief          MSKWDG4H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 4.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH4_HIGH_ISR_EN_U32            (0x00000200UL)

/**
* @brief          MSKWDG5H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 5.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH5_HIGH_ISR_EN_U32            (0x00000800UL)

/**
* @brief          MSKWDG6H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 6.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH6_HIGH_ISR_EN_U32            (0x00002000UL)

/**
* @brief          MSKWDG7H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 7.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH7_HIGH_ISR_EN_U32            (0x00008000UL)

/**
* @brief          MSKWDG8H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 8.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH8_HIGH_ISR_EN_U32           (0x00020000UL)

/**
* @brief          MSKWDG9H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 9.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH9_HIGH_ISR_EN_U32           (0x00080000UL)

/**
* @brief          MSKWDG10H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 10.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH10_HIGH_ISR_EN_U32          (0x00200000UL)

/**
* @brief          MSKWDG11H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 11.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH11_HIGH_ISR_EN_U32          (0x00800000UL)

/**
* @brief          MSKWDG12H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 12.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH12_HIGH_ISR_EN_U32         (0x02000000UL)

/**
* @brief          MSKWDG13H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 13.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH13_HIGH_ISR_EN_U32         (0x08000000UL)

/**
* @brief          MSKWDG14H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 14.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH14_HIGH_ISR_EN_U32         (0x20000000UL)

/**
* @brief          MSKWDG15H.
* @details        This corresponds to the mask bit for the interrupt generated on the converted value
*                 being higher than the programmed higher threshold 15.
*                 When set the interrupt is enabled.
*/
#define ADCDIG_WTH15_HIGH_ISR_EN_U32          (0x80000000UL)

/**
* @brief          WTIMR reset value.
* @details        Reset value for WTIMR register.
*/
#define ADCDIG_WTIMR_RESET_VALUE_U32          (0x0UL)

/**********************************************************************************
***************             DMAE Register (DMAE)                    **************
**********************************************************************************/
/**
* @brief          DMAEN.
* @details        DMA global enable.
*                 When this bit is set, the DMA feature is enabled.
*/
#define ADCDIG_DMA_GLOBAL_EN_U32              (0x00000001UL)
#define ADCDIG_DMA_CLEAR_ON_READ_U32          ((uint32)0x00000002UL)

/**
* @brief          DMAE reset value.
* @details        Reset value for DMAE register.
*/
#define ADCDIG_DMAE_RESET_VALUE_U32            (0x0UL)

/**********************************************************************************
***************                  DMA Register (DMAR)                **************
**********************************************************************************/
/**
* @brief          DMAR reset value.
* @details        Reset value for DMAR register.
*/
#define ADCDIG_DMAR_RESET_VALUE_U32            (0x0UL)

/**********************************************************************************
***************   Threshold  Register (THRHLRx)                      **************
**********************************************************************************/
/**
* @brief          THRH.
* @details        High threshold value for channel x
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_HIGH_TH_VALUE_U32(Th)           ((uint32)((Th)<<16))

/**
* @brief          THRL.
* @details        Low threshold value for channel x
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_LOW_TH_VALUE_U32(Th)            ((uint32)(Th))

#if (ADC_UNIT_10_BITS_AVAILABLE == STD_ON)
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_THRHLRx_RESET_VALUE_U32(Unit)   (((Unit) == 0U) ? (0x03FF0000UL) : (0x0FFF0000UL))
#else
  /** @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
  #define ADCDIG_THRHLRx_RESET_VALUE_U32(Unit)     (0x0FFF0000UL)
#endif /* ADC_UNIT_10_BITS_AVAILABLE == STD_ON */

/**********************************************************************************
***************        Conversion Timing Register (CTRx)         **************
**********************************************************************************/
/**
* @brief          INPSAMP.
* @details        Configuration of sampling phase duration.
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_INPSAMP_VALUE_U32(x)          ((uint16)(x))

/**
* @brief          INPSAMP.
* @details        Configuration of sampling phase duration.
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_INPSAMP1_VALUE_U32(x)         ((uint16)((x)<<1))

/**
* @brief          CTRx reset values.
*/
#ifdef IPV_ADCDIG
  #if ((IPV_ADCDIG == IPV_ADCDIG_00_00_04_14) || (IPV_ADCDIG == IPV_ADCDIG_00_00_01_02))  /* if Halo or RaceRunner IS cut 2.1 */
    #define ADCDIG_CTR0_RESET_VALUE_U32          (0x14U)
    #define ADCDIG_CTR1_RESET_VALUE_U32          (0x14U)
    #define ADCDIG_CTR2_RESET_VALUE_U32          (0x14U)
  #else
    #define ADCDIG_CTR0_RESET_VALUE_U32          (0x16U)
    #define ADCDIG_CTR1_RESET_VALUE_U32          (0x16U)
    #define ADCDIG_CTR2_RESET_VALUE_U32          (0x16U)
  #endif /* IPV_ADCDIG == IPV_ADCDIG_00_00_04_14 ...*/
#endif /* IPV_ADCDIG */

/**********************************************************************************
***************   Normal Conversion Mask Register (NCMRx)            **************
**********************************************************************************/
/**
* @brief          NCMR register reset value.
*/
#define ADCDIG_NCMR_RESET_VALUE_U32          (0x0UL)

/**********************************************************************************
***************  Injected Conversion Mask Register (JCMRx)           **************
**********************************************************************************/
/**
* @brief          JCMR register reset value.
*/
#define ADCDIG_JCMR_RESET_VALUE_U32         (0x0UL)

/*********************************************************************************
*************** Decode Signals Delay Register (DSDR)               ***************
**********************************************************************************/
/**
* @brief          DSDR.
* @details        The delay between the external decode signals and the start of the sampling
*                 phase. It is used to take into account the settling time of the external mux.
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_MUX_DELAY_VALUE_U8(x)           ((uint8)(x))

/**
* @brief          DSDR register reset value.
*/
#define ADCDIG_DSDR_RESET_VALUE_U32        (0x0UL)

/**********************************************************************************
*************** Power-Down Exit Delay Registers (PDEDR)              **************
**********************************************************************************/
/**
* @brief          PDED.
* @details        The delay between the power-down bit reset and the starting of conversion.
* @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined
*/
#define ADCDIG_POWERDOWN_EXIT_DELAY_VALUE_U8(x) ((uint8)(x))

/**
* @brief          PDEDR register reset value.
*/
#define ADCDIG_PDEDR_RESET_VALUE_U32            (0x0UL)

/**********************************************************************************
*************** Data Registers    *************************************************
**********************************************************************************/
/**
* @brief          Mask used to verify the DATA registers content (VALID flag).
*/
#define ADCDIG_VALID_DATA_MASK_U32 (0x00080000UL)

/**
* @brief          Mask used to verify the DATA registers content (CDATA bitfield).
*/
#define ADCDIG_CDR_DATA_MASK_U32   (0x00000FFFUL)

/**********************************************************************************
************** Self Test Configuration Register 1 (ADCx_STCR1)  *******************
**********************************************************************************/
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_INPSAMP_C_U32(x)            ((uint32)((x)<<24))
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_INPSAMP_S_U32(x)            ((uint32)((x)<<8))

#define ADCDIG_STCR1_MASK_U32              (0xFF00FF00UL)

/**********************************************************************************
************** Self Test Configuration Register 2 (ADCx_STCR2)  *******************
**********************************************************************************/
/**
* @brief          Mask used to enable the self-testing channel.
*/
#define ADCDIG_STCR2_EN_SET_U32                 (0x00000080UL)

/**********************************************************************************
*************** Self Test Configuration Register 3 (ADCx_STCR3) *******************
**********************************************************************************/
/**
* @brief          Mask used to Select the self-testing algorithm.
*/
#define ADCDIG_STCR3_ALG_C_U32        (0x00000200UL)

/**********************************************************************************
*************** Self Test Status Register 1 (ADCx_STSR1) *************************
**********************************************************************************/
/**
* @brief          ERR_C.
* @details        Error on the self testing channel (alg C).
*/
#define ADCDIG_STSR1_ERR_C_U32             (0x00008000UL)

/**
* @brief          ERR_S2.
* @details        Error on the self testing channel (alg S, step2).
*/
#define ADCDIG_STSR1_ERR_S2_U32            (0x00002000UL)

/**
* @brief          ERR_S1.
* @details        Error on the self testing channel (alg S, step1).
*/
#define ADCDIG_STSR1_ERR_S1_U32            (0x00001000UL)

/**
* @brief          ERR_S0.
* @details        Error on the self testing channel (alg S, step0).
*/
#define ADCDIG_STSR1_ERR_S0_U32            (0x00000800UL)

/**********************************************************************************
*************** Calibration, Status register ****************
**********************************************************************************/

#ifdef ADC_CALBISTREG_NOT_AVAILABLE
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_TSAMP_U32(x)                ((uint32)((x) << 9))
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_NR_SMPL_U32(x)              ((uint32)((x) << 11))
#define ADCDIG_AVG_EN_U32                  (0x00002000UL)
#define ADCDIG_CALSTART_U32                (0x00004000UL)
#define ADCDIG_MCR_CALIBRATE_MASK_U32      (0x00003E00UL)
#else
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_TSAMP_U32(x)                ((uint32)((x) << 27))
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_NR_SMPL_U32(x)              ((uint32)((x) << 5))
#define ADCDIG_AVG_EN_U32                  (0x00000010UL)
/**
* @brief          TEST_EN.
* @details        Enable the test (self clearing)
*                 once set it cannot be overwritten till it resets.
*/
#define ADCDIG_TEST_EN_U32                 (0x00000001UL)
#define ADCDIG_CALBISTREG_REG_MASK_U32     (0x18000079UL)
#endif /* ADC_CALBISTREG_NOT_AVAILABLE */

/**********************************************************************************
*************** BIST 1 Register (BIST1) *******************************************
**********************************************************************************/
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_STAT_MASK_U32(x)        ((uint32)1U << (x))
/**  @violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined */
#define ADCDIG_STAT_FAIL_MASK_U32(x)   ((uint32)1U << (x)) 

#ifdef ADC_CALSTAT_AVAILABLE
/**@violates @ref Adc_Reg_eSys_Adcdig_h_REF_1 Function-like macro defined*/
#define ADC_CALSTAT_REG_ADDR32(Unit)      (ADCDIG_ADDR32(Unit) + 0x0000039CUL)      
#endif /* ADC_CALSTAT_AVAILABLE */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_ADCDIG_H */

/** @} */
