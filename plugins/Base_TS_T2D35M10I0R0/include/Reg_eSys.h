/**
*   @file    Reg_eSys.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Base - BIP Memory and DMA mapping.
*   @details Memory mapping of the IP modules and DMA channels present on the MPC574XG
*            hardware platform.
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : MPC574XG
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*/

#ifndef REG_ESYS_H
#define REG_ESYS_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file        Reg_eSys.h
* @brief Include platform types
* @violates @ref Reg_eSys_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Platform_Types.h"

/**
* @file        Reg_eSys.h
* @brief Include IP module versions
*/
#include "Soc_Ips.h"


/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define REG_ESYS_VENDOR_ID                    43
#define REG_ESYS_MODULE_ID                    0
#define REG_ESYS_AR_RELEASE_MAJOR_VERSION     4
#define REG_ESYS_AR_RELEASE_MINOR_VERSION     2
#define REG_ESYS_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_SW_MAJOR_VERSION             1
#define REG_ESYS_SW_MINOR_VERSION             0
#define REG_ESYS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys.h and Platform_Types.h are different"
    #endif
#endif

/* Check if source file and Soc_Ips.h header file have same versions */
#if (REG_ESYS_VENDOR_ID != SOC_IPS_VENDOR_ID)
#error "Reg_eSys.h and Soc_Ips.h have different vendor IDs"
#endif
#if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != SOC_IPS_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_AR_RELEASE_MINOR_VERSION != SOC_IPS_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_AR_RELEASE_REVISION_VERSION != SOC_IPS_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Reg_eSys.h and Soc_Ips.h are different"
#endif
#if ((REG_ESYS_SW_MAJOR_VERSION != SOC_IPS_SW_MAJOR_VERSION) || \
     (REG_ESYS_SW_MINOR_VERSION != SOC_IPS_SW_MINOR_VERSION) || \
     (REG_ESYS_SW_PATCH_VERSION != SOC_IPS_SW_PATCH_VERSION))
#error "Software Version Numbers of Reg_eSys.h and Soc_Ips.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
@brief  Internal Flash
@details MPC574XG System Memory Map
*/
#define INTERNAL_FLASH_BASEADDR             ((uint32)0x00000000UL)

/**
@brief  Internal RAM
@details MPC574XG System Memory Map
*/
#define INTERNAL_RAM_BASEADDR               ((uint32)0x40000000UL)

/**
@brief  PBRIDGE_A
@details MPC574XG System Memory Map
*/
#define PBRIDGE_A_BASEADDR               ((uint32)0xFC000000UL)

/**
@brief  PBRIDGE_B
@details MPC574XG System Memory Map
*/
#define PBRIDGE_B_BASEADDR               ((uint32)0xF8000000UL)

/**
* @brief Emios 0
* @details MPC574XG System Memory Map
*/
#define EMIOS0_BASEADDR                   ((uint32)0xFFC38000UL)

/**
* @brief Emios 1
* @details MPC574XG System Memory Map
*/
#define EMIOS1_BASEADDR                   ((uint32)0xFBC38000UL)
/**
* @brief Emios 2
* @details MPC574XG System Memory Map
*/
#define EMIOS2_BASEADDR                   ((uint32)0xFFC3C000UL)

/**
* @brief DSPI 0
* @details MPC574XG System Memory Map
*/
#define DSPI0_BASEADDR                      ((uint32)0xFFE70000UL)
/**
* @brief DSPI 1
* @details MPC574XG System Memory Map
*/
#define DSPI1_BASEADDR                      ((uint32)0xFBE70000UL)
/**
* @brief DSPI 2
* @details MPC574XG System Memory Map
*/
#define DSPI2_BASEADDR                      ((uint32)0xFFE74000UL)
/**
* @brief DSPI 3
* @details MPC574XG System Memory Map
*/
#define DSPI3_BASEADDR                      ((uint32)0xFBE74000UL)
/**
* @brief DSPI 4  (SPI 0)
* @details MPC574XG System Memory Map
*/
#define DSPI4_BASEADDR                      ((uint32)0xFFFCC000UL)
/**
* @brief DSPI 5  (SPI 1)
* @details MPC574XG System Memory Map
*/
#define DSPI5_BASEADDR                      ((uint32)0xFBF9C000UL)
/**
* @brief DSPI 6  (SPI 2)
* @details MPC574XG System Memory Map
*/
#define DSPI6_BASEADDR                      ((uint32)0xFFFD0000UL)
/**
* @brief DSPI 7  (SPI 3)
* @details MPC574XG System Memory Map
*/
#define DSPI7_BASEADDR                      ((uint32)0xFBFA0000UL)
/**
* @brief DSPI 8  (SPI 4)
* @details MPC574XG System Memory Map
*
*/
#define DSPI8_BASEADDR                      ((uint32)0xFFFD4000UL)
/**
* @brief DSPI 9  (SPI 5)
* @details MPC574XG System Memory Map
*/
#define DSPI9_BASEADDR                      ((uint32)0xFBFA4000UL)

/**
* @brief LINFlex 0
* @details MPC574XG System Memory Map
*/
#define LINFLEX0_BASEADDR                   ((uint32)0xFFE8C000UL)
/**
* @brief LINFlex 1
* @details MPC574XG System Memory Map
*/
#define LINFLEX1_BASEADDR                   ((uint32)0xFBE8C000UL)

/**
* @brief LINFlex 2
* @details MPC574XG System Memory Map
*/
#define LINFLEX2_BASEADDR                   ((uint32)0xFFE90000UL)

/**
* @brief LINFlex 3
* @details MPC574XG System Memory Map
*/
#define LINFLEX3_BASEADDR                   ((uint32)0xFBE90000UL)

/**
* @brief LINFlex 4
* @details MPC574XG System Memory Map
*/
#define LINFLEX4_BASEADDR                   ((uint32)0xFFE94000UL)

/**
* @brief LINFlex 5
* @details MPC574XG System Memory Map
*/
#define LINFLEX5_BASEADDR                   ((uint32)0xFBE94000UL)

/**
* @brief LINFlex 6
* @details MPC574XG System Memory Map
*/
#define LINFLEX6_BASEADDR                   ((uint32)0xFFE98000UL)

/**
* @brief LINFlex 7
* @details MPC574XG System Memory Map
*/
#define LINFLEX7_BASEADDR                   ((uint32)0xFBE98000UL)

/**
* @brief LINFlex 8
* @details MPC574XG System Memory Map
*/
#define LINFLEX8_BASEADDR                   ((uint32)0xFFE9C000UL)

/**
* @brief LINFlex 9
* @details MPC574XG System Memory Map
*/
#define LINFLEX9_BASEADDR                   ((uint32)0xFBE9C000UL)

/**
* @brief LINFlex 10
* @details MPC574XG System Memory Map
*/
#define LINFLEX10_BASEADDR                   ((uint32)0xFFEA0000UL)

/**
* @brief LINFlex 11
* @details MPC574XG System Memory Map
*/
#define LINFLEX11_BASEADDR                   ((uint32)0xFBEA0000UL)

/**
* @brief LINFlex 12
* @details MPC574XG System Memory Map
*/
#define LINFLEX12_BASEADDR                   ((uint32)0xFFEA4000UL)

/**
* @brief LINFlex 13
* @details MPC574XG System Memory Map
*/
#define LINFLEX13_BASEADDR                   ((uint32)0xFBEA4000UL)

/**
* @brief LINFlex 14
* @details MPC574XG System Memory Map
*/
#define LINFLEX14_BASEADDR                   ((uint32)0xFFEA8000UL)

/**
* @brief LINFlex 15
* @details MPC574XG System Memory Map
*/
#define LINFLEX15_BASEADDR                   ((uint32)0xFBEA8000UL)

/**
* @brief LINFlex 16
* @details MPC574XG System Memory Map
*/
#define LINFLEX16_BASEADDR                   ((uint32)0xFFEAC000UL)

/**
* @brief LINFlex 17
* @details MPC574XG System Memory Map
*
*/
#define LINFLEX17_BASEADDR                   ((uint32)0xFBEAC000UL)

/**
@brief  FlexCAN 0(CAN0)
@details MPC574XG System Memory Map
*/
#define FLEXCAN0_BASEADDR                  ((uint32)0xFFEC0000UL)

/**
@brief  FlexCAN 1(CAN1)
@details MPC574XG System Memory Map
*/
#define FLEXCAN1_BASEADDR                  ((uint32)0xFBEC0000UL)

/**
@brief  FlexCAN 2(CAN2)
@details MPC574XG System Memory Map
*/
#define FLEXCAN2_BASEADDR                  ((uint32)0xFFEC4000UL)

/**
@brief  FlexCAN 3(CAN3)
@details MPC574XG System Memory Map
*/
#define FLEXCAN3_BASEADDR                  ((uint32)0xFBEC4000UL)

/**
@brief  FlexCAN 4(CAN4)
@details MPC574XG System Memory Map
*/
#define FLEXCAN4_BASEADDR                  ((uint32)0xFFEC8000UL)

/**
@brief  FlexCAN 5(CAN5)
@details MPC574XG System Memory Map
*/
#define FLEXCAN5_BASEADDR                  ((uint32)0xFBEC8000UL)

/**
@brief  FlexCAN 6(CAN6)
@details MPC574XG System Memory Map
*/
#define FLEXCAN6_BASEADDR                  ((uint32)0xFFECC000UL)

/**
@brief  FlexCAN 7(CAN7)
@details MPC574XG System Memory Map
*/
#define FLEXCAN7_BASEADDR                  ((uint32)0xFBECC000UL)

/**
@brief  FlexRay controller (FlexRay)
@details MPC574XG System Memory Map
*/
#define FLEXRAY_BASEADDR                    ((uint32)0xFFE50000UL)

/**
@brief  SAR ADC 0 (ADC_0)
@details MPC574XG System Memory Map
*/
#define ADC0_BASEADDR                  ((uint32)0xFFE00000UL)

/**
@brief  SAR ADC 1 (ADC 1)
@details MPC574XG System Memory Map
*/
#define ADC1_BASEADDR                  ((uint32)0xFBE00000UL)

/**
@brief  Fault Collection and Control Unit (FCCU)
@details MPC574XG System Memory Map
*/
#define FCCU_BASEADDR                  ((uint32)0xFBF58000UL)

/**
* @brief Cyclic redundancy check unit 0 (CRC0)
* @details MPC574XG System Memory Map
*/
#define CRC0_BASEADDR                        ((uint32)0xFFF64000UL)

/**
@brief  Clock Monitor Unit
@details MPC574XG System Memory Map
*/
#define CMU0_BASEADDR                  ((uint32)0xFFFB0140UL)

/**
@brief  Direct Memory Access Controller Hardware Multiplexer (DMAMUX0)
@details MPC574XG System Memory Map
*/
#define DMAMUX0_BASEADDR                  ((uint32)0xFFF6C000UL)

/**
@brief  Direct Memory Access Controller Hardware Multiplexer 1 (DMAMUX1)
@details MPC574XG System Memory Map
*/
#define DMAMUX1_BASEADDR                  ((uint32)0xFFF6C200UL)

/**
@brief  Computational Shell Crossbar (XBAR_0)
@details MPC574XG System Memory Map
*/
#define XBAR_0_BASEADDR                  ((uint32)0xFC004000UL)

/**
@brief  Peripheral Shell Crossbar (XBAR_1)
@details MPC574XG System Memory Map
*/
#define XBAR_1_BASEADDR                  ((uint32)0xFC008000UL)

/**
@brief  System Memory Protection Unit 0 (SMPU_0)
@details MPC574XG System Memory Map
*/
#define SMPU0_BASEADDR                  ((uint32)0xFC010000UL)

/**
@brief  System Memory Protection Unit 1 (SMPU_1)
@details MPC574XG System Memory Map
*/
#define SMPU1_BASEADDR                  ((uint32)0xFC014000UL)

/**
@brief  Platform RAM Controller (PRAM_0)
@details MPC574XG System Memory Map
*/
#define PRAM0_BASEADDR                  ((uint32)0xFC020000UL)

/**
@brief  Platform RAM Controller (PRAM_1)
@details MPC574XG System Memory Map
*/
#define PRAM1_BASEADDR                  ((uint32)0xFC024000UL)

/**
@brief  Platform RAM Controller (PRAM_2)
@details MPC574XG System Memory Map
*/
#define PRAM2_BASEADDR                  ((uint32)0xFC02C000UL)

/**
@brief  Platform control module (PCM)
@details MPC574XG System Memory Map
*/
#define PCM_BASEADDR                  ((uint32)0xFC028000UL)

/**
@brief  Platform Flash controller (PFLASH)
@details MPC574XG System Memory Map
*/
#define PFLASH_BASEADDR                  ((uint32)0xFC030000UL)

/**
* @brief Interrupt Controller (INTC)
* @details MPC574XG System Memory Map
*/
#define INTC_BASEADDR                       ((uint32)0xFC040000UL)

/**
* @brief Software Watchdog 0 (SWT_0)
* @details MPC574XG System Memory Map
*/
#define SWT_0_BASEADDR                        ((uint32)0xFC050000UL)

/**
* @brief Software Watchdog 1 (SWT_1)
* @details MPC574XG System Memory Map
*/
#define SWT_1_BASEADDR                        ((uint32)0xFC054000UL)

/**
* @brief Software Watchdog 2 (SWT_2)
* @details MPC574XG System Memory Map
*/
#define SWT_2_BASEADDR                        ((uint32)0xFC058000UL)

/**
* @brief System Timer Module 0 (STM_0)
* @details XPC574XR System Memory Map
*/
#define STM_0_BASEADDR                        ((uint32)0xFC068000UL)

/**
* @brief System Timer Module 1 (STM_1)
* @details XPC574XR System Memory Map
*/
#define STM_1_BASEADDR                        ((uint32)0xFC06C000UL)

/**
* @brief System Timer Module 2 (STM_2)
* @details XPC574XR System Memory Map
*/
#define STM_2_BASEADDR                        ((uint32)0xFC070000UL)

/**
* @brief Direct Memory Access Controller (DMA)
* @details MPC574XG System Memory Map
*/
#define DMA_BASEADDR                        ((uint32)0xFC0A0000UL)

/**
@brief  Ethernet Controller 0 (ENET_0)
@details MPC574XG System Memory Map
*/
#define ENET_0_BASEADDR                  ((uint32)0xFFCC4000UL)

/**
@brief  Ethernet Controller 1 (ENET_1)
@details MPC574XG System Memory Map
*/
#define ENET_1_BASEADDR                  ((uint32)0xFFCC8000UL)

/**
* @brief Body cross triggering unit (BCTU)
* @details MPC574XG System Memory Map
*/
#define BCTU_BASEADDR                        ((uint32)0xFFC10000UL)

/**
@brief  Self Test Control Unit (STCU2)
@details MPC574XG System Memory Map
*/
#define STCU_BASEADDR                  ((uint32)0xFFF44000UL)

/**
@brief  Memory Error Management Unit (MEMU 0)
@details MPC574XG System Memory Map
*/
#define MEMU0_BASEADDR                  ((uint32)0xFFF50000UL)

/**
@brief  Memory Error Management Unit (MEMU 1)
@details MPC574XG System Memory Map
*/
#define MEMU1_BASEADDR                  ((uint32)0xFFFEC000UL)

/**
* @brief Periodic Interrupt Timer 0 (PIT0)
* @details MPC574XG System Memory Map
*/
#define PIT_0_BASEADDR                        ((uint32)0xFFF84000UL)

/**
* @brief Real Time Counter (RTC/API)
* @details MPC574XG System Memory Map
*/
#define RTC_BASEADDR                        ((uint32)0xFFFF0000UL)

/**
* @brief WakeUp Unit
* @details MPC574XG System Memory Map
*/
#define WKPU_BASEADDR                       ((uint32)0xFFF98000UL)

/**
* @brief Power Control Unit (MC_PCU)
* @details MPC574XG System Memory Map
*/
#define PCU_BASEADDR                     ((uint32)0xFFFA0000UL)

/**
@brief  Power Management Controller (PMCDIG)
@details MPC574XG System Memory Map
*/
#define PMCDIG_BASEADDR                  ((uint32)0xFFFA0400UL)

/**
* @brief Reset Generation Module (MC_RGM)
* @details MPC574XG System Memory Map
*/
#define MC_RGM_BASEADDR                     ((uint32)0xFFFA8000UL)

/**
@brief  Slow internal 128 kHz oscillator (SIRC)
@details MPC574XG System Memory Map
*/
#define SIRC_BASEADDR                  ((uint32)0xFFFB00C0UL)


/**
@brief  Fast internal 16 MHz (FIRC)
@details MPC574XG System Memory Map
*/
#define FIRC_BASEADDR                  ((uint32)0xFFFB0000UL)

/**
@brief  Slow external 32 KHz (SXOSC)
@details MPC574XG System Memory Map
*/
#define SXOSC_BASEADDR                  ((uint32)0xFFFB0100UL)

/**
@brief  Fast OSC Digital Interface (FXOSC)
@details MPC574XG System Memory Map
*/
#define FXOSC_BASEADDR                  ((uint32)0xFFFB0040UL)

/**
@brief  FM Dual PLL (PLL)
@details MPC574XG System Memory Map
*/
#define PLLDIG0_BASEADDR                  ((uint32)0xFFFB0080UL)

/**
* @brief Clock Generation Module (MC_CGM)
* @details MPC574XG System Memory Map
*/
#define MC_CGM_BASEADDR                     ((uint32)0xFFFB0000UL)

/**
* @brief Mode Entry Module (MC_ME)
* @details MPC574XG System Memory Map
*/
#define MC_ME_BASEADDR                      ((uint32)0xFFFB8000UL)

/**
@brief  System Integration Unit Lite 2 (SIUL2)
@details MPC574XG System Memory Map
*/
#define SIUL2_BASEADDR                  ((uint32)0xFFFC0000UL)

/**
@brief I2C0
@details MPC574XG System Memory Map
*/
#define I2C0_BASEADDR                        ((uint32)0xFFE68000UL)

/**
@brief I2C1
@details MPC574XG System Memory Map
*/
#define I2C1_BASEADDR                        ((uint32)0xFBE68000UL)

/**
@brief I2C2
@details MPC574XG System Memory Map
*/
#define I2C2_BASEADDR                        ((uint32)0xFFE6C000UL)

/**
@brief I2C3
@details MPC574XG System Memory Map
*/
#define I2C3_BASEADDR                        ((uint32)0xFBE6C000UL)

/**
@brief USB0
@details MPC574XG System Memory Map
*/
#define USB0_BASEADDR                        ((uint32)0xFFC90000UL)

/**
@brief USB1
@details MPC574XG System Memory Map
*/
#define USB1_BASEADDR                        ((uint32)0xFFC94000UL)

/**
@brief Secure Digital Host Controller (USDHC)
@details MPC574XG System Memory Map
*/
#define USDHC_BASEADDR                        ((uint32)0xFFCA4000UL)

/**
@brief Media Local Bus (MLB150)
@details MPC574XG System Memory Map
*/
#define MLB_BASEADDR                        ((uint32)0xFFC9C000UL)

/**
@brief Synchronous Audio Interface (SAI 0)
@details MPC574XG System Memory Map
*/
#define SAI0_BASEADDR                        ((uint32)0xFFCB4000UL)

/**
@brief Synchronous Audio Interface (SAI 1)
@details MPC574XG System Memory Map
*/
#define SAI1_BASEADDR                        ((uint32)0xFBCB4000UL)

/**
@brief Synchronous Audio Interface (SAI 2)
@details MPC574XG System Memory Map
*/
#define SAI2_BASEADDR                        ((uint32)0xFFCB8000UL)

/**
* @brief Flash main control registers
* @details MPC574XG System Memory Map
*/
#define FMCR_BASEADDR             ((uint32)0xFFFE0000UL)

/**
* @brief Password and Device Security Module (PASS)
* @details MPC574XG System Memory Map
*/
#define PASS_BASEADDR                       ((uint32)0xFFFF4000UL)

/**
* @brief System Status and Configuration Module (SSCM)
* @details MPC574XG System Memory Map
*/
#define SSCM_BASEADDR                       ((uint32)0xFFFF8000UL)

/**
* @brief Boot Assist ROM (BAR))
* @details MPC574XG System Memory Map
*/
#define BAR_BASEADDR                       ((uint32)0xFFFFC000UL)

/**
* @brief Low Power Unit (LPU))
* @details MPC574XG System Memory Map
*/
#define LPU_BASEADDR                       ((uint32)0xFFF9C000UL)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* #ifndef REG_ESYS_H*/

/** @} */
