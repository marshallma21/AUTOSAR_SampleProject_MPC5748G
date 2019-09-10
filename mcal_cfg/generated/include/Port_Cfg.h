/**
* @file    Port_Cfg.h
* @implements Port_Cfg.h_Artifact
*
* @version 1.0.0
* @brief   AUTOSAR Port - PORT driver configuration.
* @details This file contains the PORT driver precompile configuration.
*
* @addtogroup Port
* @{
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


#ifndef PORT_CFG_H
#define PORT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section PORT_CFG_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, The compiler/linkershall be checked to ensure 
* that 31 character significance and case sensitivity are supported for external identifiers. 
* The used compilers/linkers allow more than 31 characters significance for external identifiers.
*
* @section PORT_CFG_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section PORT_CFG_H_REF_3
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section PORT_CFG_H_REF_4
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function.
* These objects are used in various parts of the code.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/

/*=================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Port_EnvCfg.h"
#include "Port_Siul2_Types.h"


/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

/**
* @brief Parameters that shall be published within the Port driver header file and also in the
*        module's description file
* @details The integration of incompatible files shall be avoided.
*/
#define PORT_VENDOR_ID_CFG_H                       43
#define PORT_AR_RELEASE_MAJOR_VERSION_CFG_H        4
#define PORT_AR_RELEASE_MINOR_VERSION_CFG_H        2
#define PORT_AR_RELEASE_REVISION_VERSION_CFG_H     2
#define PORT_SW_MAJOR_VERSION_CFG_H                1
#define PORT_SW_MINOR_VERSION_CFG_H                0
#define PORT_SW_PATCH_VERSION_CFG_H                0

/*=================================================================================================
*                               FILE VERSION CHECKS
=================================================================================================*/

/* Check if Port_Cfg.h and Port_Siul2_Types.h file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_SIUL2_VENDOR_ID_TYPES_H)
    #error "Port_Cfg.h and Port_Siul2_Types.h have different vendor ids"
#endif
/* Check if Port_Cfg.h and Port_Siul2_Types.h file are of the same Autosar version */
#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_SIUL2_AR_RELEASE_MAJOR_VERSION_TYPES_H)   ||  \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_SIUL2_AR_RELEASE_MINOR_VERSION_TYPES_H)   ||  \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_SIUL2_AR_RELEASE_REVISION_VERSION_TYPES_H) \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_Siul2_Types.h are different"
#endif
/* Check if Port_Cfg.h and Port_Siul2_Types.h file are of the same software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_SIUL2_SW_MAJOR_VERSION_TYPES_H) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_SIUL2_SW_MINOR_VERSION_TYPES_H) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_SIUL2_SW_PATCH_VERSION_TYPES_H)    \
    )
    #error "Software Version Numbers of Port_Cfg.h and Port_Siul2_Types.h are different"
#endif

/* Check if Port_Cfg.h file and Port_EnvCfg header file are of the same vendor */
#if (PORT_VENDOR_ID_CFG_H != PORT_ENVCFG_VENDOR_ID)
    #error "Port_Cfg.h and Port_EnvCfg.h have different vendor IDs"
#endif

#if ((PORT_AR_RELEASE_MAJOR_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_MAJOR_VERSION)      || \
     (PORT_AR_RELEASE_MINOR_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_MINOR_VERSION)      || \
     (PORT_AR_RELEASE_REVISION_VERSION_CFG_H != PORT_ENVCFG_AR_RELEASE_REVISION_VERSION)   \
    )
    #error "AutoSar Version Numbers of Port_Cfg.h and Port_EnvCfg.h are different"
#endif
/* Check if Port_Cfg.h and PORT header file are of the same Software version */
#if ((PORT_SW_MAJOR_VERSION_CFG_H != PORT_ENVCFG_SW_MAJOR_VERSION) || \
     (PORT_SW_MINOR_VERSION_CFG_H != PORT_ENVCFG_SW_MINOR_VERSION) || \
     (PORT_SW_PATCH_VERSION_CFG_H != PORT_ENVCFG_SW_PATCH_VERSION)    \
    )
#error "Software Version Numbers of Port_Cfg.h and Port_EnvCfg.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                      DEFINES AND MACROS
=================================================================================================*/

/**
* @brief       Ensure better readability of the configuration
* @note 
*
* @violates @ref PORT_CFG_H_REF_3 Function-like macro defined.
*/
#define SHL_PAD_U16(x)                      ((uint16)(((uint16)1) << (x)))

/**
* @brief PSMI setting not available
* @note The current platform does not implement pad selection for multiplexed input for current pin.
*       Used for better readability of PSMI settings.
*
*/
#define NO_INPUTMUX_U16                     ((uint16)0xFFFFU)

/**
* @brief Show the Platform used.
* @note This define can be used by test phase.  
*
*/
#define PLATFORM_CALYPSO
/**
* @brief Show the IPV used.
* @note This define can be used by test phase.
*
*/
#define IPV_SIUL2_USED


/** @brief Port GPIO Mode */
#define PORT_GPIO_MODE                  ((Port_PinModeType)0)
/** @brief Port Alternate 1 Mode */
#define PORT_ALT1_FUNC_MODE             ((Port_PinModeType)1)
/** @brief Port Alternate 2 Mode */
#define PORT_ALT2_FUNC_MODE             ((Port_PinModeType)2)
/** @brief Port Alternate 3 Mode */
#define PORT_ALT3_FUNC_MODE             ((Port_PinModeType)3)
/** @brief Port Alternate 4 Mode */
#define PORT_ALT4_FUNC_MODE             ((Port_PinModeType)4)
/** @brief Port Alternate 5 Mode */
#define PORT_ALT5_FUNC_MODE             ((Port_PinModeType)5)
/** @brief Port Alternate 6 Mode */
#define PORT_ALT6_FUNC_MODE             ((Port_PinModeType)6)
/** @brief Port Alternate 7 Mode */
#define PORT_ALT7_FUNC_MODE             ((Port_PinModeType)7)
/** @brief Port Output Only Mode */
#define PORT_ONLY_OUTPUT_MODE           ((Port_PinModeType)8)
/** @brief Port Input Only Mode */
#define PORT_ONLY_INPUT_MODE            ((Port_PinModeType)9)
/** @brief Port Analog input Mode */
#define PORT_ANALOG_INPUT_MODE          ((Port_PinModeType)10)
/** @brief Port Input 1 Mode*/
#define PORT_INPUT1_MODE                ((Port_PinModeType)11)
/** @brief Port Input 2 Mode*/
#define PORT_INPUT2_MODE                ((Port_PinModeType)12)
/** @brief Port Input 3 Mode*/
#define PORT_INPUT3_MODE                ((Port_PinModeType)13)
/** @brief Port Input 4 Mode*/
#define PORT_INPUT4_MODE                ((Port_PinModeType)14)
/** @brief Port Input 5 Mode*/
#define PORT_INPUT5_MODE                ((Port_PinModeType)15)
/** @brief Port Input 6 Mode*/
#define PORT_INPUT6_MODE                ((Port_PinModeType)16)
/** @brief Port Input/Output 1 Mode */
#define PORT_INOUT1_MODE                ((Port_PinModeType)17)
/** @brief Port Input/Output 2 Mode */
#define PORT_INOUT2_MODE                ((Port_PinModeType)18)
/** @brief Port Input/Output 3 Mode */
#define PORT_INOUT3_MODE                ((Port_PinModeType)19)
/** @brief Port Input/Output 4 Mode */
#define PORT_INOUT4_MODE                ((Port_PinModeType)20)
/** @brief Port Input/Output 5 Mode */
#define PORT_INOUT5_MODE                ((Port_PinModeType)21)
/** @brief Port Input/Output 6 Mode */
#define PORT_INOUT6_MODE                ((Port_PinModeType)22)
/** @brief Port Input/Output 7 Mode */
#define PORT_INOUT7_MODE                ((Port_PinModeType)23)


/** @brief Port Abstraction Modes */


#define    PORT0_GPIO        (PORT_GPIO_MODE)
#define    PORT0_EMIOS0_E0UC_0_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT0_CGM_CLKOUT0        (PORT_ALT2_FUNC_MODE)
#define    PORT0_EMIOS0_E0UC_13_H_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT0_WKPU_WKPU_19        (PORT_ONLY_INPUT_MODE)
#define    PORT0_EMIOS0_E0UC_0_X_IN        (PORT_INPUT1_MODE)
#define    PORT0_EMIOS0_E0UC_13_H_IN        (PORT_INPUT2_MODE)
#define    PORT0_FlexCAN_1_RX        (PORT_INPUT3_MODE)
#define    PORT0_EMIOS0_E0UC_0_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT0_EMIOS0_E0UC_13_H_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT1_GPIO        (PORT_GPIO_MODE)
#define    PORT1_EMIOS0_E0UC_1_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT1_WKPU_WKPU_2        (PORT_ONLY_INPUT_MODE)
#define    PORT1_WKPU_NMI_0        (PORT_ONLY_INPUT_MODE)
#define    PORT1_EMIOS0_E0UC_1_G_IN        (PORT_INPUT1_MODE)
#define    PORT1_FlexCAN_3_RX        (PORT_INPUT2_MODE)
#define    PORT1_EMIOS0_E0UC_1_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT2_GPIO        (PORT_GPIO_MODE)
#define    PORT2_EMIOS0_E0UC_2_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT2_EMIOS2_E2UC_0_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT2_ADC_0_ADC0_MA_2        (PORT_ALT3_FUNC_MODE)
#define    PORT2_WKPU_WKPU_3        (PORT_ONLY_INPUT_MODE)
#define    PORT2_EMIOS0_E0UC_2_G_IN        (PORT_INPUT1_MODE)
#define    PORT2_EMIOS2_E2UC_0_X_IN        (PORT_INPUT2_MODE)
#define    PORT2_EMIOS0_E0UC_2_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT2_EMIOS2_E2UC_0_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT3_GPIO        (PORT_GPIO_MODE)
#define    PORT3_EMIOS0_E0UC_3_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT3_LIN_5_LIN5TX        (PORT_ALT2_FUNC_MODE)
#define    PORT3_DSPI_1_dCS4        (PORT_ALT3_FUNC_MODE)
#define    PORT3_ADC_1_ADC1_S_0        (PORT_ANALOG_INPUT_MODE)
#define    PORT3_EMIOS0_E0UC_3_G_IN        (PORT_INPUT1_MODE)
#define    PORT3_SIUL2_EIRQ0        (PORT_INPUT2_MODE)
#define    PORT3_ENET0_MII_0_RX_CLK        (PORT_INPUT3_MODE)
#define    PORT3_EMIOS0_E0UC_3_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT4_GPIO        (PORT_GPIO_MODE)
#define    PORT4_EMIOS0_E0UC_4_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT4_DSPI_1_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT4_EMIOS2_E2UC_24_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT4_WKPU_WKPU_9        (PORT_ONLY_INPUT_MODE)
#define    PORT4_CMP1_CMP1_13        (PORT_ANALOG_INPUT_MODE)
#define    PORT4_EMIOS0_E0UC_4_G_IN        (PORT_INPUT1_MODE)
#define    PORT4_EMIOS2_E2UC_24_X_IN        (PORT_INPUT2_MODE)
#define    PORT4_LIN_5_LIN5RX        (PORT_INPUT3_MODE)
#define    PORT4_DSPI_1_dSS        (PORT_INPUT4_MODE)
#define    PORT4_EMIOS0_E0UC_4_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT4_EMIOS2_E2UC_24_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT5_GPIO        (PORT_GPIO_MODE)
#define    PORT5_EMIOS0_E0UC_5_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT5_LIN_4_LIN4TX        (PORT_ALT2_FUNC_MODE)
#define    PORT5_USB0_ULPI0_STP        (PORT_ALT4_FUNC_MODE)
#define    PORT5_EMIOS0_E0UC_5_G_IN        (PORT_INPUT1_MODE)
#define    PORT5_EMIOS0_E0UC_5_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT6_GPIO        (PORT_GPIO_MODE)
#define    PORT6_EMIOS0_E0UC_6_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT6_DSPI_1_dCS1        (PORT_ALT2_FUNC_MODE)
#define    PORT6_EMIOS0_E0UC_6_G_IN        (PORT_INPUT1_MODE)
#define    PORT6_SIUL2_EIRQ1        (PORT_INPUT2_MODE)
#define    PORT6_LIN_4_LIN4RX        (PORT_INPUT3_MODE)
#define    PORT6_USB0_ULPI0_DIR        (PORT_INPUT4_MODE)
#define    PORT6_EMIOS0_E0UC_6_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT7_GPIO        (PORT_GPIO_MODE)
#define    PORT7_EMIOS0_E0UC_7_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT7_LIN_3_LIN3TX        (PORT_ALT2_FUNC_MODE)
#define    PORT7_ADC_1_ADC1_S_8        (PORT_ANALOG_INPUT_MODE)
#define    PORT7_EMIOS0_E0UC_7_G_IN        (PORT_INPUT1_MODE)
#define    PORT7_SIUL2_EIRQ2        (PORT_INPUT2_MODE)
#define    PORT7_ENET0_MII_0_RXD_2        (PORT_INPUT3_MODE)
#define    PORT7_EMIOS0_E0UC_7_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT8_GPIO        (PORT_GPIO_MODE)
#define    PORT8_EMIOS0_E0UC_8_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT8_EMIOS0_E0UC_14_H_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT8_ADC_1_ADC1_S_9        (PORT_ANALOG_INPUT_MODE)
#define    PORT8_EMIOS0_E0UC_8_X_IN        (PORT_INPUT1_MODE)
#define    PORT8_EMIOS0_E0UC_14_H_IN        (PORT_INPUT2_MODE)
#define    PORT8_SIUL2_EIRQ3        (PORT_INPUT3_MODE)
#define    PORT8_LIN_3_LIN3RX        (PORT_INPUT4_MODE)
#define    PORT8_ENET0_MII_RMII_0_RXD_1        (PORT_INPUT5_MODE)
#define    PORT8_EMIOS0_E0UC_8_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT8_EMIOS0_E0UC_14_H_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT9_GPIO        (PORT_GPIO_MODE)
#define    PORT9_EMIOS0_E0UC_9_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT9_DSPI_1_dCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT9_ADC_1_ADC1_S_10        (PORT_ANALOG_INPUT_MODE)
#define    PORT9_EMIOS0_E0UC_9_H_IN        (PORT_INPUT1_MODE)
#define    PORT9_ENET0_MII_RMII_0_RXD_0        (PORT_INPUT2_MODE)
#define    PORT9_EMIOS0_E0UC_9_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT10_GPIO        (PORT_GPIO_MODE)
#define    PORT10_EMIOS0_E0UC_10_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT10_IIC_0_SDA0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT10_LIN_2_LIN2TX        (PORT_ALT3_FUNC_MODE)
#define    PORT10_ENET1_MII_1_TXD_1        (PORT_ALT4_FUNC_MODE)
#define    PORT10_ADC_1_ADC1_S_11        (PORT_ANALOG_INPUT_MODE)
#define    PORT10_EMIOS0_E0UC_10_H_IN        (PORT_INPUT1_MODE)
#define    PORT10_IIC_0_SDA0_IN        (PORT_INPUT2_MODE)
#define    PORT10_DSPI_1_dSIN        (PORT_INPUT3_MODE)
#define    PORT10_ENET0_MII_0_COL        (PORT_INPUT4_MODE)
#define    PORT10_EMIOS0_E0UC_10_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT10_IIC_0_SDA0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT11_GPIO        (PORT_GPIO_MODE)
#define    PORT11_EMIOS0_E0UC_11_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT11_IIC_0_SCL0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT11_ENET1_MII_1_TXD_0        (PORT_ALT3_FUNC_MODE)
#define    PORT11_ADC_1_ADC1_S_12        (PORT_ANALOG_INPUT_MODE)
#define    PORT11_EMIOS0_E0UC_11_H_IN        (PORT_INPUT1_MODE)
#define    PORT11_SIUL2_EIRQ16        (PORT_INPUT2_MODE)
#define    PORT11_LIN_2_LIN2RX        (PORT_INPUT3_MODE)
#define    PORT11_USB0_ULPI0_FAULT        (PORT_INPUT4_MODE)
#define    PORT11_IIC_0_SCL0_IN        (PORT_INPUT5_MODE)
#define    PORT11_ENET0_MII_RMII_0_RX_ER        (PORT_INPUT6_MODE)
#define    PORT11_EMIOS0_E0UC_11_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT11_IIC_0_SCL0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT12_GPIO        (PORT_GPIO_MODE)
#define    PORT12_EMIOS0_E0UC_28_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT12_DSPI_1_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT12_EMIOS2_E2UC_26_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT12_CMP1_CMP1_15        (PORT_ANALOG_INPUT_MODE)
#define    PORT12_EMIOS0_E0UC_28_Y_IN        (PORT_INPUT1_MODE)
#define    PORT12_EMIOS2_E2UC_26_Y_IN        (PORT_INPUT2_MODE)
#define    PORT12_SIUL2_EIRQ17        (PORT_INPUT3_MODE)
#define    PORT12_DSPI_0_dSIN        (PORT_INPUT4_MODE)
#define    PORT12_EMIOS0_E0UC_28_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT12_EMIOS2_E2UC_26_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT13_GPIO        (PORT_GPIO_MODE)
#define    PORT13_DSPI_0_dSOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT13_EMIOS0_E0UC_29_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT13_EMIOS2_E2UC_25_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT13_FlexCAN_0_TX        (PORT_ALT4_FUNC_MODE)
#define    PORT13_CMP1_CMP1_14        (PORT_ANALOG_INPUT_MODE)
#define    PORT13_EMIOS0_E0UC_29_Y_IN        (PORT_INPUT1_MODE)
#define    PORT13_EMIOS2_E2UC_25_Y_IN        (PORT_INPUT2_MODE)
#define    PORT13_EMIOS0_E0UC_29_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT13_EMIOS2_E2UC_25_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT14_GPIO        (PORT_GPIO_MODE)
#define    PORT14_DSPI_0_dSCLK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT14_DSPI_0_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT14_EMIOS0_E0UC_0_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT14_EMIOS2_E2UC_23_X_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT14_CMP1_CMP1_12        (PORT_ANALOG_INPUT_MODE)
#define    PORT14_EMIOS0_E0UC_0_X_IN        (PORT_INPUT1_MODE)
#define    PORT14_EMIOS2_E2UC_23_X_IN        (PORT_INPUT2_MODE)
#define    PORT14_SIUL2_EIRQ4        (PORT_INPUT3_MODE)
#define    PORT14_DSPI_0_dSCLK_IN        (PORT_INPUT4_MODE)
#define    PORT14_DSPI_0_dSS        (PORT_INPUT5_MODE)
#define    PORT14_DSPI_0_dSCLK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT14_EMIOS0_E0UC_0_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT14_EMIOS2_E2UC_23_X_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT15_GPIO        (PORT_GPIO_MODE)
#define    PORT15_DSPI_0_dCS0        (PORT_ALT1_FUNC_MODE)
#define    PORT15_DSPI_0_dSCLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT15_EMIOS0_E0UC_1_G_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT15_EMIOS2_E2UC_21_Y_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT15_WKPU_WKPU_10        (PORT_ONLY_INPUT_MODE)
#define    PORT15_CMP1_CMP1_10        (PORT_ANALOG_INPUT_MODE)
#define    PORT15_EMIOS0_E0UC_1_G_IN        (PORT_INPUT1_MODE)
#define    PORT15_EMIOS2_E2UC_21_Y_IN        (PORT_INPUT2_MODE)
#define    PORT15_FlexCAN_0_RX        (PORT_INPUT3_MODE)
#define    PORT15_DSPI_0_dSCLK_IN        (PORT_INPUT4_MODE)
#define    PORT15_DSPI_0_dSS        (PORT_INPUT5_MODE)
#define    PORT15_DSPI_0_dSCLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT15_EMIOS0_E0UC_1_G_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT15_EMIOS2_E2UC_21_Y_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT16_GPIO        (PORT_GPIO_MODE)
#define    PORT16_FlexCAN_0_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT16_EMIOS0_E0UC_30_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT16_LIN_0_LIN0TX        (PORT_ALT3_FUNC_MODE)
#define    PORT16_EMIOS2_E2UC_4_Y_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT16_CMP0_CMP0_2        (PORT_ANALOG_INPUT_MODE)
#define    PORT16_EMIOS0_E0UC_30_Y_IN        (PORT_INPUT1_MODE)
#define    PORT16_EMIOS2_E2UC_4_Y_IN        (PORT_INPUT2_MODE)
#define    PORT16_EMIOS0_E0UC_30_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT16_EMIOS2_E2UC_4_Y_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT17_GPIO        (PORT_GPIO_MODE)
#define    PORT17_EMIOS0_E0UC_31_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT17_EMIOS2_E2UC_5_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT17_WKPU_WKPU_4        (PORT_ONLY_INPUT_MODE)
#define    PORT17_CMP0_CMP0_3        (PORT_ANALOG_INPUT_MODE)
#define    PORT17_EMIOS0_E0UC_31_Y_IN        (PORT_INPUT1_MODE)
#define    PORT17_EMIOS2_E2UC_5_Y_IN        (PORT_INPUT2_MODE)
#define    PORT17_FlexCAN_0_RX        (PORT_INPUT3_MODE)
#define    PORT17_LIN_0_LIN0RX        (PORT_INPUT4_MODE)
#define    PORT17_EMIOS0_E0UC_31_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT17_EMIOS2_E2UC_5_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT18_GPIO        (PORT_GPIO_MODE)
#define    PORT18_LIN_0_LIN0TX        (PORT_ALT1_FUNC_MODE)
#define    PORT18_IIC_0_SDA0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT18_EMIOS0_E0UC_30_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT18_USDHC_SD_DAT7_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT18_EMIOS0_E0UC_30_Y_IN        (PORT_INPUT1_MODE)
#define    PORT18_IIC_0_SDA0_IN        (PORT_INPUT2_MODE)
#define    PORT18_USDHC_SD_DAT7_IN        (PORT_INPUT3_MODE)
#define    PORT18_IIC_0_SDA0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT18_EMIOS0_E0UC_30_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT18_USDHC_SD_DAT7_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT19_GPIO        (PORT_GPIO_MODE)
#define    PORT19_EMIOS0_E0UC_31_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT19_IIC_0_SCL0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT19_EMIOS2_E2UC_8_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT19_WKPU_WKPU_11        (PORT_ONLY_INPUT_MODE)
#define    PORT19_EMIOS0_E0UC_31_Y_IN        (PORT_INPUT1_MODE)
#define    PORT19_EMIOS2_E2UC_8_X_IN        (PORT_INPUT2_MODE)
#define    PORT19_LIN_0_LIN0RX        (PORT_INPUT3_MODE)
#define    PORT19_IIC_0_SCL0_IN        (PORT_INPUT4_MODE)
#define    PORT19_USB0_ULPI0_FAULT        (PORT_INPUT5_MODE)
#define    PORT19_EMIOS0_E0UC_31_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT19_IIC_0_SCL0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT19_EMIOS2_E2UC_8_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT20_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT20_ADC_1_ADC1_P_0        (PORT_ANALOG_INPUT_MODE)
#define    PORT21_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT21_ADC_1_ADC1_P_1        (PORT_ANALOG_INPUT_MODE)
#define    PORT21_ENET1_MII_1_RX_DV        (PORT_INPUT1_MODE)
#define    PORT22_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT22_ADC_1_ADC1_P_2        (PORT_ANALOG_INPUT_MODE)
#define    PORT22_ENET1_MII_1_RXD_3        (PORT_INPUT1_MODE)
#define    PORT23_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT23_ADC_1_ADC1_P_3        (PORT_ANALOG_INPUT_MODE)
#define    PORT23_ENET1_MII_1_RXD_2        (PORT_INPUT1_MODE)
#define    PORT24_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT24_ADC_0_ADC0_S_0        (PORT_ANALOG_INPUT_MODE)
#define    PORT24_WKPU_WKPU_25        (PORT_ONLY_INPUT_MODE)
#define    PORT24_XOSC_OSC32K_XTAL        (PORT_ONLY_INPUT_MODE)
#define    PORT25_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT25_ADC_0_ADC0_S_1        (PORT_ANALOG_INPUT_MODE)
#define    PORT25_WKPU_WKPU_26        (PORT_ONLY_INPUT_MODE)
#define    PORT25_XOSC_OSC32K_EXTAL        (PORT_ONLY_INPUT_MODE)
#define    PORT26_GPIO        (PORT_GPIO_MODE)
#define    PORT26_DSPI_1_dSOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT26_FlexCAN_3_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT26_CMP2_CMP2_O        (PORT_ALT3_FUNC_MODE)
#define    PORT26_SAI0_SAI0_SYNC_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT26_EMIOS2_E2UC_29_Y_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT26_ADC_0_ADC0_S_2        (PORT_ANALOG_INPUT_MODE)
#define    PORT26_WKPU_WKPU_8        (PORT_ONLY_INPUT_MODE)
#define    PORT26_EMIOS2_E2UC_29_Y_IN        (PORT_INPUT1_MODE)
#define    PORT26_FlexCAN_6_RX        (PORT_INPUT2_MODE)
#define    PORT26_SAI0_SAI0_SYNC_IN        (PORT_INPUT3_MODE)
#define    PORT26_SAI0_SAI0_SYNC_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT26_EMIOS2_E2UC_29_Y_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT27_GPIO        (PORT_GPIO_MODE)
#define    PORT27_EMIOS0_E0UC_3_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT27_DSPI_0_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT27_ADC_0_ADC0_S_3        (PORT_ANALOG_INPUT_MODE)
#define    PORT27_EMIOS0_E0UC_3_G_IN        (PORT_INPUT1_MODE)
#define    PORT27_DSPI_0_dSS        (PORT_INPUT2_MODE)
#define    PORT27_ENET1_MII_1_RX_CLK        (PORT_INPUT3_MODE)
#define    PORT27_EMIOS0_E0UC_3_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT28_GPIO        (PORT_GPIO_MODE)
#define    PORT28_EMIOS0_E0UC_4_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT28_DSPI_0_dCS1        (PORT_ALT2_FUNC_MODE)
#define    PORT28_HSM_DO1        (PORT_ALT3_FUNC_MODE)
#define    PORT28_ENET1_ENET1_TMR0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT28_ADC_0_ADC0_X_0        (PORT_ANALOG_INPUT_MODE)
#define    PORT28_EMIOS0_E0UC_4_G_IN        (PORT_INPUT1_MODE)
#define    PORT28_ENET1_ENET1_TMR0_IN        (PORT_INPUT2_MODE)
#define    PORT28_EMIOS0_E0UC_4_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT28_ENET1_ENET1_TMR0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT29_GPIO        (PORT_GPIO_MODE)
#define    PORT29_EMIOS0_E0UC_5_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT29_DSPI_0_dCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT29_ADC_0_ADC0_X_1        (PORT_ANALOG_INPUT_MODE)
#define    PORT29_EMIOS0_E0UC_5_G_IN        (PORT_INPUT1_MODE)
#define    PORT29_ENET1_MII_1_RX_DV        (PORT_INPUT2_MODE)
#define    PORT29_EMIOS0_E0UC_5_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT30_GPIO        (PORT_GPIO_MODE)
#define    PORT30_EMIOS0_E0UC_6_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT30_DSPI_0_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT30_FlexRay_FR_DBG_1        (PORT_ALT3_FUNC_MODE)
#define    PORT30_ADC_0_ADC0_X_2        (PORT_ANALOG_INPUT_MODE)
#define    PORT30_EMIOS0_E0UC_6_G_IN        (PORT_INPUT1_MODE)
#define    PORT30_ENET1_MII_1_RXD_2        (PORT_INPUT2_MODE)
#define    PORT30_EMIOS0_E0UC_6_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT31_GPIO        (PORT_GPIO_MODE)
#define    PORT31_EMIOS0_E0UC_7_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT31_DSPI_0_dCS4        (PORT_ALT2_FUNC_MODE)
#define    PORT31_MLB_MLBSIG_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT31_ADC_0_ADC0_X_3        (PORT_ANALOG_INPUT_MODE)
#define    PORT31_EMIOS0_E0UC_7_G_IN        (PORT_INPUT1_MODE)
#define    PORT31_MLB_MLBSIG_IN        (PORT_INPUT2_MODE)
#define    PORT31_ENET1_MII_1_RXD_0        (PORT_INPUT3_MODE)
#define    PORT31_EMIOS0_E0UC_7_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT31_MLB_MLBSIG_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT32_GPIO        (PORT_GPIO_MODE)
#define    PORT32_DCI_TDI        (PORT_ALT1_FUNC_MODE)
#define    PORT33_GPIO        (PORT_GPIO_MODE)
#define    PORT33_DCI_TDO        (PORT_ALT1_FUNC_MODE)
#define    PORT34_GPIO        (PORT_GPIO_MODE)
#define    PORT34_DSPI_1_dSCLK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT34_FlexCAN_4_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT34_EMIOS2_E2UC_22_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT34_SSCM_SSCM_DBG_0        (PORT_ALT4_FUNC_MODE)
#define    PORT34_EMIOS2_E2UC_22_X_IN        (PORT_INPUT1_MODE)
#define    PORT34_SIUL2_EIRQ5        (PORT_INPUT2_MODE)
#define    PORT34_USB1_ULPI1_CLK        (PORT_INPUT3_MODE)
#define    PORT34_DSPI_1_dSCLK_IN        (PORT_INPUT4_MODE)
#define    PORT34_DSPI_1_dSCLK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT34_EMIOS2_E2UC_22_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT35_GPIO        (PORT_GPIO_MODE)
#define    PORT35_DSPI_1_dCS0        (PORT_ALT1_FUNC_MODE)
#define    PORT35_ADC_0_ADC0_MA_0        (PORT_ALT2_FUNC_MODE)
#define    PORT35_EMIOS2_E2UC_23_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT35_SSCM_SSCM_DBG_1        (PORT_ALT4_FUNC_MODE)
#define    PORT35_EMIOS2_E2UC_23_X_IN        (PORT_INPUT1_MODE)
#define    PORT35_SIUL2_EIRQ6        (PORT_INPUT2_MODE)
#define    PORT35_FlexCAN_1_RX        (PORT_INPUT3_MODE)
#define    PORT35_FlexCAN_4_RX        (PORT_INPUT4_MODE)
#define    PORT35_USB1_ULPI1_DIR        (PORT_INPUT5_MODE)
#define    PORT35_DSPI_1_dSS        (PORT_INPUT6_MODE)
#define    PORT35_EMIOS2_E2UC_23_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT36_GPIO        (PORT_GPIO_MODE)
#define    PORT36_EMIOS1_E1UC_31_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT36_FlexRay_FR_B_TX_EN        (PORT_ALT2_FUNC_MODE)
#define    PORT36_USDHC_SD_DAT0_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT36_USB0_ULPI0_D1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT36_SSCM_SSCM_DBG_2        (PORT_ALT5_FUNC_MODE)
#define    PORT36_EMIOS1_E1UC_31_Y_IN        (PORT_INPUT1_MODE)
#define    PORT36_SIUL2_EIRQ18        (PORT_INPUT2_MODE)
#define    PORT36_FlexCAN_3_RX        (PORT_INPUT3_MODE)
#define    PORT36_USB0_ULPI0_D1_IN        (PORT_INPUT4_MODE)
#define    PORT36_DSPI_1_dSIN        (PORT_INPUT5_MODE)
#define    PORT36_USDHC_SD_DAT0_IN        (PORT_INPUT6_MODE)
#define    PORT36_EMIOS1_E1UC_31_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT36_USDHC_SD_DAT0_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT36_USB0_ULPI0_D1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT37_GPIO        (PORT_GPIO_MODE)
#define    PORT37_DSPI_1_dSOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT37_FlexCAN_3_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT37_EMIOS2_E2UC_24_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT37_FlexRay_FR_A_TX        (PORT_ALT4_FUNC_MODE)
#define    PORT37_USDHC_SD_CLK_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT37_USB0_ULPI0_D0_OUT        (PORT_ALT6_FUNC_MODE)
#define    PORT37_SSCM_SSCM_DBG_3        (PORT_ALT7_FUNC_MODE)
#define    PORT37_EMIOS2_E2UC_24_X_IN        (PORT_INPUT1_MODE)
#define    PORT37_SIUL2_EIRQ7        (PORT_INPUT2_MODE)
#define    PORT37_USB0_ULPI0_D0_IN        (PORT_INPUT3_MODE)
#define    PORT37_USDHC_SD_CLK_IN        (PORT_INPUT4_MODE)
#define    PORT37_EMIOS2_E2UC_24_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT37_USDHC_SD_CLK_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT37_USB0_ULPI0_D0_IN_OUT        (PORT_INOUT6_MODE)
#define    PORT38_GPIO        (PORT_GPIO_MODE)
#define    PORT38_LIN_1_LIN1TX        (PORT_ALT1_FUNC_MODE)
#define    PORT38_EMIOS1_E1UC_28_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT38_EMIOS2_E2UC_17_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT38_SSCM_SSCM_DBG_4        (PORT_ALT4_FUNC_MODE)
#define    PORT38_CMP0_CMP0_7        (PORT_ANALOG_INPUT_MODE)
#define    PORT38_EMIOS1_E1UC_28_Y_IN        (PORT_INPUT1_MODE)
#define    PORT38_EMIOS2_E2UC_17_Y_IN        (PORT_INPUT2_MODE)
#define    PORT38_EMIOS1_E1UC_28_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT38_EMIOS2_E2UC_17_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT39_GPIO        (PORT_GPIO_MODE)
#define    PORT39_EMIOS1_E1UC_29_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT39_CMP1_CMP1_O        (PORT_ALT2_FUNC_MODE)
#define    PORT39_EMIOS2_E2UC_18_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT39_SSCM_SSCM_DBG_5        (PORT_ALT4_FUNC_MODE)
#define    PORT39_WKPU_WKPU_12        (PORT_ONLY_INPUT_MODE)
#define    PORT39_EMIOS1_E1UC_29_Y_IN        (PORT_INPUT1_MODE)
#define    PORT39_EMIOS2_E2UC_18_Y_IN        (PORT_INPUT2_MODE)
#define    PORT39_LIN_1_LIN1RX        (PORT_INPUT3_MODE)
#define    PORT39_EMIOS1_E1UC_29_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT39_EMIOS2_E2UC_18_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT40_GPIO        (PORT_GPIO_MODE)
#define    PORT40_LIN_2_LIN2TX        (PORT_ALT1_FUNC_MODE)
#define    PORT40_EMIOS0_E0UC_3_G_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT40_USDHC_SD_DAT6_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT40_SSCM_SSCM_DBG_6        (PORT_ALT4_FUNC_MODE)
#define    PORT40_EMIOS0_E0UC_3_G_IN        (PORT_INPUT1_MODE)
#define    PORT40_USDHC_SD_DAT6_IN        (PORT_INPUT2_MODE)
#define    PORT40_EMIOS0_E0UC_3_G_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT40_USDHC_SD_DAT6_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT41_GPIO        (PORT_GPIO_MODE)
#define    PORT41_EMIOS0_E0UC_7_G_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT41_EMIOS2_E2UC_7_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT41_SSCM_SSCM_DBG_7        (PORT_ALT3_FUNC_MODE)
#define    PORT41_WKPU_WKPU_13        (PORT_ONLY_INPUT_MODE)
#define    PORT41_EMIOS0_E0UC_7_G_IN        (PORT_INPUT1_MODE)
#define    PORT41_EMIOS2_E2UC_7_Y_IN        (PORT_INPUT2_MODE)
#define    PORT41_LIN_2_LIN2RX        (PORT_INPUT3_MODE)
#define    PORT41_USB1_ULPI1_FAULT        (PORT_INPUT4_MODE)
#define    PORT41_EMIOS0_E0UC_7_G_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT41_EMIOS2_E2UC_7_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT42_GPIO        (PORT_GPIO_MODE)
#define    PORT42_FlexCAN_1_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT42_FlexCAN_4_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT42_ADC_0_ADC0_MA_1        (PORT_ALT3_FUNC_MODE)
#define    PORT42_CMP0_CMP0_O        (PORT_ALT4_FUNC_MODE)
#define    PORT42_LIN_6_LIN6TX        (PORT_ALT6_FUNC_MODE)
#define    PORT43_GPIO        (PORT_GPIO_MODE)
#define    PORT43_ADC_0_ADC0_MA_2        (PORT_ALT1_FUNC_MODE)
#define    PORT43_EMIOS2_E2UC_1_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT43_WKPU_WKPU_5        (PORT_ONLY_INPUT_MODE)
#define    PORT43_EMIOS2_E2UC_1_Y_IN        (PORT_INPUT1_MODE)
#define    PORT43_FlexCAN_1_RX        (PORT_INPUT2_MODE)
#define    PORT43_FlexCAN_4_RX        (PORT_INPUT3_MODE)
#define    PORT43_EMIOS2_E2UC_1_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT44_GPIO        (PORT_GPIO_MODE)
#define    PORT44_EMIOS0_E0UC_12_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT44_FlexRay_FR_DBG_0        (PORT_ALT2_FUNC_MODE)
#define    PORT44_USDHC_SD_DAT4_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT44_EMIOS0_E0UC_12_H_IN        (PORT_INPUT1_MODE)
#define    PORT44_SIUL2_EIRQ19        (PORT_INPUT2_MODE)
#define    PORT44_DSPI_2_dSIN        (PORT_INPUT3_MODE)
#define    PORT44_USDHC_SD_DAT4_IN        (PORT_INPUT4_MODE)
#define    PORT44_EMIOS0_E0UC_12_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT44_USDHC_SD_DAT4_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT45_GPIO        (PORT_GPIO_MODE)
#define    PORT45_EMIOS0_E0UC_13_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT45_DSPI_2_dSOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT45_FlexRay_FR_DBG_1        (PORT_ALT3_FUNC_MODE)
#define    PORT45_USDHC_SD_DAT5_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT45_EMIOS0_E0UC_13_H_IN        (PORT_INPUT1_MODE)
#define    PORT45_USDHC_SD_DAT5_IN        (PORT_INPUT2_MODE)
#define    PORT45_EMIOS0_E0UC_13_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT45_USDHC_SD_DAT5_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT46_GPIO        (PORT_GPIO_MODE)
#define    PORT46_EMIOS0_E0UC_14_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT46_DSPI_2_dSCLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT46_EMIOS2_E2UC_6_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT46_FlexRay_FR_DBG_2        (PORT_ALT4_FUNC_MODE)
#define    PORT46_FlexCAN_4_TX        (PORT_ALT5_FUNC_MODE)
#define    PORT46_EMIOS0_E0UC_14_H_IN        (PORT_INPUT1_MODE)
#define    PORT46_EMIOS2_E2UC_6_Y_IN        (PORT_INPUT2_MODE)
#define    PORT46_SIUL2_EIRQ8        (PORT_INPUT3_MODE)
#define    PORT46_DSPI_2_dSCLK_IN        (PORT_INPUT4_MODE)
#define    PORT46_EMIOS0_E0UC_14_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT46_DSPI_2_dSCLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT46_EMIOS2_E2UC_6_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT47_GPIO        (PORT_GPIO_MODE)
#define    PORT47_EMIOS0_E0UC_15_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT47_DSPI_2_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT47_EMIOS2_E2UC_5_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT47_FlexRay_FR_DBG_3        (PORT_ALT4_FUNC_MODE)
#define    PORT47_EMIOS0_E0UC_15_H_IN        (PORT_INPUT1_MODE)
#define    PORT47_EMIOS2_E2UC_5_Y_IN        (PORT_INPUT2_MODE)
#define    PORT47_SIUL2_EIRQ20        (PORT_INPUT3_MODE)
#define    PORT47_DSPI_2_dSS        (PORT_INPUT4_MODE)
#define    PORT47_FlexCAN_4_RX        (PORT_INPUT5_MODE)
#define    PORT47_EMIOS0_E0UC_15_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT47_EMIOS2_E2UC_5_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT48_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT48_ADC_1_ADC1_P_4        (PORT_ANALOG_INPUT_MODE)
#define    PORT48_WKPU_WKPU_27        (PORT_ONLY_INPUT_MODE)
#define    PORT49_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT49_ADC_1_ADC1_P_5        (PORT_ANALOG_INPUT_MODE)
#define    PORT49_WKPU_WKPU_28        (PORT_ONLY_INPUT_MODE)
#define    PORT50_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT50_ADC_1_ADC1_P_6        (PORT_ANALOG_INPUT_MODE)
#define    PORT51_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT51_ADC_1_ADC1_P_7        (PORT_ANALOG_INPUT_MODE)
#define    PORT52_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT52_ADC_1_ADC1_P_8        (PORT_ANALOG_INPUT_MODE)
#define    PORT53_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT53_ADC_1_ADC1_P_9        (PORT_ANALOG_INPUT_MODE)
#define    PORT54_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT54_ADC_1_ADC1_P_10        (PORT_ANALOG_INPUT_MODE)
#define    PORT55_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT55_ADC_1_ADC1_P_11        (PORT_ANALOG_INPUT_MODE)
#define    PORT56_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT56_ADC_1_ADC1_P_12        (PORT_ANALOG_INPUT_MODE)
#define    PORT57_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT57_ADC_1_ADC1_P_13        (PORT_ANALOG_INPUT_MODE)
#define    PORT57_ENET1_MII_1_RXD_1        (PORT_INPUT1_MODE)
#define    PORT58_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT58_ADC_1_ADC1_P_14        (PORT_ANALOG_INPUT_MODE)
#define    PORT58_ENET1_MII_1_RXD_0        (PORT_INPUT1_MODE)
#define    PORT59_GPI        (PORT_ONLY_INPUT_MODE)
#define    PORT59_ADC_1_ADC1_P_15        (PORT_ANALOG_INPUT_MODE)
#define    PORT60_GPIO        (PORT_GPIO_MODE)
#define    PORT60_DSPI_0_dCS5        (PORT_ALT1_FUNC_MODE)
#define    PORT60_EMIOS0_E0UC_24_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT60_HSM_DO0        (PORT_ALT3_FUNC_MODE)
#define    PORT60_ENET1_ENET1_TMR1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT60_ADC_0_ADC0_S_4        (PORT_ANALOG_INPUT_MODE)
#define    PORT60_EMIOS0_E0UC_24_X_IN        (PORT_INPUT1_MODE)
#define    PORT60_ENET1_ENET1_TMR1_IN        (PORT_INPUT2_MODE)
#define    PORT60_EMIOS0_E0UC_24_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT60_ENET1_ENET1_TMR1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT61_GPIO        (PORT_GPIO_MODE)
#define    PORT61_DSPI_1_dCS0        (PORT_ALT1_FUNC_MODE)
#define    PORT61_EMIOS0_E0UC_25_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT61_ENET0_ENET0_TMR0_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT61_ADC_0_ADC0_S_5        (PORT_ANALOG_INPUT_MODE)
#define    PORT61_EMIOS0_E0UC_25_Y_IN        (PORT_INPUT1_MODE)
#define    PORT61_DSPI_1_dSS        (PORT_INPUT2_MODE)
#define    PORT61_ENET0_ENET0_TMR0_IN        (PORT_INPUT3_MODE)
#define    PORT61_EMIOS0_E0UC_25_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT61_ENET0_ENET0_TMR0_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT62_GPIO        (PORT_GPIO_MODE)
#define    PORT62_DSPI_1_dCS1        (PORT_ALT1_FUNC_MODE)
#define    PORT62_EMIOS0_E0UC_26_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT62_FlexRay_FR_DBG_0        (PORT_ALT3_FUNC_MODE)
#define    PORT62_ADC_0_ADC0_S_6        (PORT_ANALOG_INPUT_MODE)
#define    PORT62_EMIOS0_E0UC_26_Y_IN        (PORT_INPUT1_MODE)
#define    PORT62_ENET1_MII_1_RXD_3        (PORT_INPUT2_MODE)
#define    PORT62_EMIOS0_E0UC_26_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT63_GPIO        (PORT_GPIO_MODE)
#define    PORT63_DSPI_1_dCS2        (PORT_ALT1_FUNC_MODE)
#define    PORT63_EMIOS0_E0UC_27_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT63_FlexRay_FR_DBG_1        (PORT_ALT3_FUNC_MODE)
#define    PORT63_MLB_MLBDAT_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT63_ADC_0_ADC0_S_7        (PORT_ANALOG_INPUT_MODE)
#define    PORT63_EMIOS0_E0UC_27_Y_IN        (PORT_INPUT1_MODE)
#define    PORT63_MLB_MLBDAT_IN        (PORT_INPUT2_MODE)
#define    PORT63_ENET1_MII_1_RXD_1        (PORT_INPUT3_MODE)
#define    PORT63_EMIOS0_E0UC_27_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT63_MLB_MLBDAT_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT64_GPIO        (PORT_GPIO_MODE)
#define    PORT64_EMIOS0_E0UC_16_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT64_IIC_1_SCL1_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT64_WKPU_WKPU_6        (PORT_ONLY_INPUT_MODE)
#define    PORT64_EMIOS0_E0UC_16_X_IN        (PORT_INPUT1_MODE)
#define    PORT64_FlexCAN_5_RX        (PORT_INPUT2_MODE)
#define    PORT64_LIN_11_LIN11RX        (PORT_INPUT3_MODE)
#define    PORT64_IIC_1_SCL1_IN        (PORT_INPUT4_MODE)
#define    PORT64_EMIOS0_E0UC_16_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT64_IIC_1_SCL1_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT65_GPIO        (PORT_GPIO_MODE)
#define    PORT65_EMIOS0_E0UC_17_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT65_FlexCAN_5_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT65_IIC_1_SDA1_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT65_EMIOS0_E0UC_17_Y_IN        (PORT_INPUT1_MODE)
#define    PORT65_IIC_1_SDA1_IN        (PORT_INPUT2_MODE)
#define    PORT65_EMIOS0_E0UC_17_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT65_IIC_1_SDA1_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT66_GPIO        (PORT_GPIO_MODE)
#define    PORT66_EMIOS0_E0UC_18_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT66_FlexRay_FR_A_TX_EN        (PORT_ALT2_FUNC_MODE)
#define    PORT66_USDHC_SD_DAT3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT66_EMIOS0_E0UC_18_Y_IN        (PORT_INPUT1_MODE)
#define    PORT66_SIUL2_EIRQ21        (PORT_INPUT2_MODE)
#define    PORT66_USB0_ULPI0_CLK        (PORT_INPUT3_MODE)
#define    PORT66_DSPI_1_dSIN        (PORT_INPUT4_MODE)
#define    PORT66_USDHC_SD_DAT3_IN        (PORT_INPUT5_MODE)
#define    PORT66_EMIOS0_E0UC_18_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT66_USDHC_SD_DAT3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT67_GPIO        (PORT_GPIO_MODE)
#define    PORT67_EMIOS0_E0UC_19_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT67_DSPI_1_dSOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT67_USDHC_SD_CMD_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT67_WKPU_WKPU_29        (PORT_ONLY_INPUT_MODE)
#define    PORT67_EMIOS0_E0UC_19_Y_IN        (PORT_INPUT1_MODE)
#define    PORT67_FlexRay_FR_A_RX        (PORT_INPUT2_MODE)
#define    PORT67_USB0_ULPI0_NXT        (PORT_INPUT3_MODE)
#define    PORT67_USDHC_SD_CMD_IN        (PORT_INPUT4_MODE)
#define    PORT67_EMIOS0_E0UC_19_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT67_USDHC_SD_CMD_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT68_GPIO        (PORT_GPIO_MODE)
#define    PORT68_EMIOS0_E0UC_20_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT68_DSPI_1_dSCLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT68_FlexRay_FR_B_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT68_USDHC_SD_DAT1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT68_USB0_ULPI0_D2_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT68_EMIOS0_E0UC_20_Y_IN        (PORT_INPUT1_MODE)
#define    PORT68_SIUL2_EIRQ9        (PORT_INPUT2_MODE)
#define    PORT68_USB0_ULPI0_D2_IN        (PORT_INPUT3_MODE)
#define    PORT68_DSPI_1_dSCLK_IN        (PORT_INPUT4_MODE)
#define    PORT68_USDHC_SD_DAT1_IN        (PORT_INPUT5_MODE)
#define    PORT68_EMIOS0_E0UC_20_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT68_DSPI_1_dSCLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT68_USDHC_SD_DAT1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT68_USB0_ULPI0_D2_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT69_GPIO        (PORT_GPIO_MODE)
#define    PORT69_EMIOS0_E0UC_21_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT69_DSPI_1_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT69_ADC_0_ADC0_MA_2        (PORT_ALT3_FUNC_MODE)
#define    PORT69_USDHC_SD_DAT2_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT69_USB0_ULPI0_D3_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT69_WKPU_WKPU_30        (PORT_ONLY_INPUT_MODE)
#define    PORT69_EMIOS0_E0UC_21_Y_IN        (PORT_INPUT1_MODE)
#define    PORT69_FlexRay_FR_B_RX        (PORT_INPUT2_MODE)
#define    PORT69_USB0_ULPI0_D3_IN        (PORT_INPUT3_MODE)
#define    PORT69_DSPI_1_dSS        (PORT_INPUT4_MODE)
#define    PORT69_USDHC_SD_DAT2_IN        (PORT_INPUT5_MODE)
#define    PORT69_EMIOS0_E0UC_21_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT69_USDHC_SD_DAT2_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT69_USB0_ULPI0_D3_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT70_GPIO        (PORT_GPIO_MODE)
#define    PORT70_EMIOS0_E0UC_22_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT70_DSPI_0_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT70_ADC_0_ADC0_MA_1        (PORT_ALT3_FUNC_MODE)
#define    PORT70_ADC_1_ADC1_MA_1        (PORT_ALT4_FUNC_MODE)
#define    PORT70_USDHC_SD_CMD_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT70_EMIOS0_E0UC_22_X_IN        (PORT_INPUT1_MODE)
#define    PORT70_SIUL2_EIRQ22        (PORT_INPUT2_MODE)
#define    PORT70_USDHC_SD_CMD_IN        (PORT_INPUT3_MODE)
#define    PORT70_EMIOS0_E0UC_22_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT70_USDHC_SD_CMD_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT71_GPIO        (PORT_GPIO_MODE)
#define    PORT71_EMIOS0_E0UC_23_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT71_DSPI_0_dCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT71_ADC_0_ADC0_MA_0        (PORT_ALT3_FUNC_MODE)
#define    PORT71_ADC_1_ADC1_MA_0        (PORT_ALT4_FUNC_MODE)
#define    PORT71_USDHC_SD_CLK_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT71_EMIOS0_E0UC_23_X_IN        (PORT_INPUT1_MODE)
#define    PORT71_SIUL2_EIRQ23        (PORT_INPUT2_MODE)
#define    PORT71_USDHC_SD_CLK_IN        (PORT_INPUT3_MODE)
#define    PORT71_EMIOS0_E0UC_23_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT71_USDHC_SD_CLK_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT72_GPIO        (PORT_GPIO_MODE)
#define    PORT72_FlexCAN_2_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT72_EMIOS0_E0UC_22_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT72_FlexCAN_3_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT72_IIC_2_SDA2_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT72_LIN_6_LIN6TX        (PORT_ALT5_FUNC_MODE)
#define    PORT72_EMIOS0_E0UC_22_X_IN        (PORT_INPUT1_MODE)
#define    PORT72_IIC_2_SDA2_IN        (PORT_INPUT2_MODE)
#define    PORT72_EMIOS0_E0UC_22_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT72_IIC_2_SDA2_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT73_GPIO        (PORT_GPIO_MODE)
#define    PORT73_EMIOS0_E0UC_23_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT73_IIC_2_SCL2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT73_WKPU_WKPU_7        (PORT_ONLY_INPUT_MODE)
#define    PORT73_EMIOS0_E0UC_23_X_IN        (PORT_INPUT1_MODE)
#define    PORT73_FlexCAN_2_RX        (PORT_INPUT2_MODE)
#define    PORT73_FlexCAN_3_RX        (PORT_INPUT3_MODE)
#define    PORT73_IIC_2_SCL2_IN        (PORT_INPUT4_MODE)
#define    PORT73_EMIOS0_E0UC_23_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT73_IIC_2_SCL2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT74_GPIO        (PORT_GPIO_MODE)
#define    PORT74_LIN_3_LIN3TX        (PORT_ALT1_FUNC_MODE)
#define    PORT74_DSPI_1_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT74_EMIOS1_E1UC_30_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT74_IIC_3_SDA3_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT74_EMIOS1_E1UC_30_Y_IN        (PORT_INPUT1_MODE)
#define    PORT74_SIUL2_EIRQ10        (PORT_INPUT2_MODE)
#define    PORT74_IIC_3_SDA3_IN        (PORT_INPUT3_MODE)
#define    PORT74_EMIOS1_E1UC_30_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT74_IIC_3_SDA3_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT75_GPIO        (PORT_GPIO_MODE)
#define    PORT75_EMIOS0_E0UC_24_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT75_DSPI_1_dCS4        (PORT_ALT2_FUNC_MODE)
#define    PORT75_CGM_CLKOUT1        (PORT_ALT3_FUNC_MODE)
#define    PORT75_IIC_3_SCL3_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT75_WKPU_WKPU_14        (PORT_ONLY_INPUT_MODE)
#define    PORT75_EMIOS0_E0UC_24_X_IN        (PORT_INPUT1_MODE)
#define    PORT75_LIN_3_LIN3RX        (PORT_INPUT2_MODE)
#define    PORT75_IIC_3_SCL3_IN        (PORT_INPUT3_MODE)
#define    PORT75_EMIOS0_E0UC_24_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT75_IIC_3_SCL3_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT76_GPIO        (PORT_GPIO_MODE)
#define    PORT76_EMIOS1_E1UC_19_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT76_ADC_1_ADC1_S_13        (PORT_ANALOG_INPUT_MODE)
#define    PORT76_EMIOS1_E1UC_19_Y_IN        (PORT_INPUT1_MODE)
#define    PORT76_SIUL2_EIRQ11        (PORT_INPUT2_MODE)
#define    PORT76_USB1_ULPI1_FAULT        (PORT_INPUT3_MODE)
#define    PORT76_DSPI_2_dSIN        (PORT_INPUT4_MODE)
#define    PORT76_ENET0_MII_0_CRS        (PORT_INPUT5_MODE)
#define    PORT76_ENET1_MII_1_TX_CLK        (PORT_INPUT6_MODE)
#define    PORT76_EMIOS1_E1UC_19_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT77_GPIO        (PORT_GPIO_MODE)
#define    PORT77_DSPI_2_dSOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT77_EMIOS1_E1UC_20_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT77_ADC_1_ADC1_X_3        (PORT_ANALOG_INPUT_MODE)
#define    PORT77_EMIOS1_E1UC_20_Y_IN        (PORT_INPUT1_MODE)
#define    PORT77_ENET0_MII_0_RXD_3        (PORT_INPUT2_MODE)
#define    PORT77_EMIOS1_E1UC_20_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT78_GPIO        (PORT_GPIO_MODE)
#define    PORT78_DSPI_2_dSCLK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT78_EMIOS1_E1UC_21_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT78_USB1_ULPI1_D2_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT78_EMIOS1_E1UC_21_Y_IN        (PORT_INPUT1_MODE)
#define    PORT78_SIUL2_EIRQ12        (PORT_INPUT2_MODE)
#define    PORT78_USB1_ULPI1_D2_IN        (PORT_INPUT3_MODE)
#define    PORT78_DSPI_2_dSCLK_IN        (PORT_INPUT4_MODE)
#define    PORT78_DSPI_2_dSCLK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT78_EMIOS1_E1UC_21_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT78_USB1_ULPI1_D2_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT79_GPIO        (PORT_GPIO_MODE)
#define    PORT79_DSPI_2_dCS0        (PORT_ALT1_FUNC_MODE)
#define    PORT79_EMIOS1_E1UC_22_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT79_SPI_2_SCLK_2_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT79_USB1_ULPI1_D3_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT79_EMIOS1_E1UC_22_X_IN        (PORT_INPUT1_MODE)
#define    PORT79_USB1_ULPI1_D3_IN        (PORT_INPUT2_MODE)
#define    PORT79_DSPI_2_dSS        (PORT_INPUT3_MODE)
#define    PORT79_SPI_2_SCLK_2_IN        (PORT_INPUT4_MODE)
#define    PORT79_EMIOS1_E1UC_22_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT79_SPI_2_SCLK_2_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT79_USB1_ULPI1_D3_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT80_GPIO        (PORT_GPIO_MODE)
#define    PORT80_EMIOS0_E0UC_10_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT80_DSPI_1_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT80_SPI_4_SOUT_4        (PORT_ALT3_FUNC_MODE)
#define    PORT80_FlexCAN_6_TX        (PORT_ALT4_FUNC_MODE)
#define    PORT80_ADC_0_ADC0_S_8        (PORT_ANALOG_INPUT_MODE)
#define    PORT80_CMP2_CMP2_16        (PORT_ANALOG_INPUT_MODE)
#define    PORT80_SAI0_SAI0_MCLK_OUT        (PORT_ALT7_FUNC_MODE)
#define    PORT80_EMIOS0_E0UC_10_H_IN        (PORT_INPUT1_MODE)
#define    PORT80_SAI0_SAI0_MCLK_IN        (PORT_INPUT2_MODE)
#define    PORT80_EMIOS0_E0UC_10_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT80_SAI0_SAI0_MCLK_IN_OUT        (PORT_INOUT7_MODE)
#define    PORT81_GPIO        (PORT_GPIO_MODE)
#define    PORT81_EMIOS0_E0UC_11_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT81_DSPI_1_dCS4        (PORT_ALT2_FUNC_MODE)
#define    PORT81_SPI_0_CS3_0        (PORT_ALT3_FUNC_MODE)
#define    PORT81_SAI0_SAI0_BCLK_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT81_ADC_0_ADC0_S_9        (PORT_ANALOG_INPUT_MODE)
#define    PORT81_CMP2_CMP2_17        (PORT_ANALOG_INPUT_MODE)
#define    PORT81_EMIOS0_E0UC_11_H_IN        (PORT_INPUT1_MODE)
#define    PORT81_SPI_4_SIN_4        (PORT_INPUT2_MODE)
#define    PORT81_SAI0_SAI0_BCLK_IN        (PORT_INPUT3_MODE)
#define    PORT81_EMIOS0_E0UC_11_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT81_SAI0_SAI0_BCLK_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT82_GPIO        (PORT_GPIO_MODE)
#define    PORT82_EMIOS0_E0UC_12_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT82_DSPI_2_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT82_SPI_4_SCLK_4_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT82_SAI0_SAI0_D3_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT82_ADC_0_ADC0_S_10        (PORT_ANALOG_INPUT_MODE)
#define    PORT82_CMP2_CMP2_18        (PORT_ANALOG_INPUT_MODE)
#define    PORT82_EMIOS0_E0UC_12_H_IN        (PORT_INPUT1_MODE)
#define    PORT82_DSPI_2_dSS        (PORT_INPUT2_MODE)
#define    PORT82_SPI_4_SCLK_4_IN        (PORT_INPUT3_MODE)
#define    PORT82_SAI0_SAI0_D3_IN        (PORT_INPUT4_MODE)
#define    PORT82_EMIOS0_E0UC_12_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT82_SPI_4_SCLK_4_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT82_SAI0_SAI0_D3_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT83_GPIO        (PORT_GPIO_MODE)
#define    PORT83_EMIOS0_E0UC_13_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT83_DSPI_2_dCS1        (PORT_ALT2_FUNC_MODE)
#define    PORT83_SPI_4_CS0_4        (PORT_ALT3_FUNC_MODE)
#define    PORT83_SAI0_SAI0_D2_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT83_ADC_0_ADC0_S_11        (PORT_ANALOG_INPUT_MODE)
#define    PORT83_CMP2_CMP2_19        (PORT_ANALOG_INPUT_MODE)
#define    PORT83_EMIOS0_E0UC_13_H_IN        (PORT_INPUT1_MODE)
#define    PORT83_SPI_4_SS_4        (PORT_INPUT2_MODE)
#define    PORT83_SAI0_SAI0_D2_IN        (PORT_INPUT3_MODE)
#define    PORT83_EMIOS0_E0UC_13_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT83_SAI0_SAI0_D2_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT84_GPIO        (PORT_GPIO_MODE)
#define    PORT84_EMIOS0_E0UC_14_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT84_DSPI_2_dCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT84_SPI_5_SOUT_5        (PORT_ALT3_FUNC_MODE)
#define    PORT84_SAI0_SAI0_D1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT84_ADC_0_ADC0_S_12        (PORT_ANALOG_INPUT_MODE)
#define    PORT84_CMP2_CMP2_20        (PORT_ANALOG_INPUT_MODE)
#define    PORT84_EMIOS0_E0UC_14_H_IN        (PORT_INPUT1_MODE)
#define    PORT84_SAI0_SAI0_D1_IN        (PORT_INPUT2_MODE)
#define    PORT84_EMIOS0_E0UC_14_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT84_SAI0_SAI0_D1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT85_GPIO        (PORT_GPIO_MODE)
#define    PORT85_EMIOS0_E0UC_22_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT85_DSPI_2_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT85_SPI_0_CS2_0        (PORT_ALT3_FUNC_MODE)
#define    PORT85_SAI0_SAI0_D0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT85_ADC_0_ADC0_S_13        (PORT_ANALOG_INPUT_MODE)
#define    PORT85_CMP2_CMP2_21        (PORT_ANALOG_INPUT_MODE)
#define    PORT85_EMIOS0_E0UC_22_X_IN        (PORT_INPUT1_MODE)
#define    PORT85_SPI_5_SIN_5        (PORT_INPUT2_MODE)
#define    PORT85_SAI0_SAI0_D0_IN        (PORT_INPUT3_MODE)
#define    PORT85_EMIOS0_E0UC_22_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT85_SAI0_SAI0_D0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT86_GPIO        (PORT_GPIO_MODE)
#define    PORT86_EMIOS0_E0UC_23_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT86_DSPI_1_dCS1        (PORT_ALT2_FUNC_MODE)
#define    PORT86_SPI_5_SCLK_5_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT86_SAI1_SAI1_SYNC_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT86_EMIOS2_E2UC_30_Y_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT86_ADC_0_ADC0_S_14        (PORT_ANALOG_INPUT_MODE)
#define    PORT86_CMP2_CMP2_22        (PORT_ANALOG_INPUT_MODE)
#define    PORT86_EMIOS0_E0UC_23_X_IN        (PORT_INPUT1_MODE)
#define    PORT86_EMIOS2_E2UC_30_Y_IN        (PORT_INPUT2_MODE)
#define    PORT86_SPI_5_SCLK_5_IN        (PORT_INPUT3_MODE)
#define    PORT86_SAI1_SAI1_SYNC_IN        (PORT_INPUT4_MODE)
#define    PORT86_EMIOS0_E0UC_23_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT86_SPI_5_SCLK_5_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT86_SAI1_SAI1_SYNC_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT86_EMIOS2_E2UC_30_Y_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT87_GPIO        (PORT_GPIO_MODE)
#define    PORT87_SPI_0_SCLK_0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT87_DSPI_1_dCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT87_SPI_5_CS0_5        (PORT_ALT3_FUNC_MODE)
#define    PORT87_ADC_0_ADC0_S_15        (PORT_ANALOG_INPUT_MODE)
#define    PORT87_CMP2_CMP2_23        (PORT_ANALOG_INPUT_MODE)
#define    PORT87_SAI1_SAI1_MCLK_OUT        (PORT_ALT6_FUNC_MODE)
#define    PORT87_SPI_0_SCLK_0_IN        (PORT_INPUT1_MODE)
#define    PORT87_SPI_5_SS_5        (PORT_INPUT2_MODE)
#define    PORT87_SAI1_SAI1_MCLK_IN        (PORT_INPUT3_MODE)
#define    PORT87_SPI_0_SCLK_0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT87_SAI1_SAI1_MCLK_IN_OUT        (PORT_INOUT6_MODE)
#define    PORT88_GPIO        (PORT_GPIO_MODE)
#define    PORT88_FlexCAN_3_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT88_DSPI_0_dCS4        (PORT_ALT2_FUNC_MODE)
#define    PORT88_FlexCAN_2_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT88_EMIOS2_E2UC_15_Y_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT88_CMP0_CMP0_5        (PORT_ANALOG_INPUT_MODE)
#define    PORT88_EMIOS2_E2UC_15_Y_IN        (PORT_INPUT1_MODE)
#define    PORT88_EMIOS2_E2UC_15_Y_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT89_GPIO        (PORT_GPIO_MODE)
#define    PORT89_EMIOS1_E1UC_1_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT89_DSPI_0_dCS5        (PORT_ALT2_FUNC_MODE)
#define    PORT89_EMIOS2_E2UC_14_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT89_WKPU_WKPU_22        (PORT_ONLY_INPUT_MODE)
#define    PORT89_CMP0_CMP0_4        (PORT_ANALOG_INPUT_MODE)
#define    PORT89_EMIOS1_E1UC_1_H_IN        (PORT_INPUT1_MODE)
#define    PORT89_EMIOS2_E2UC_14_Y_IN        (PORT_INPUT2_MODE)
#define    PORT89_FlexCAN_2_RX        (PORT_INPUT3_MODE)
#define    PORT89_FlexCAN_3_RX        (PORT_INPUT4_MODE)
#define    PORT89_EMIOS1_E1UC_1_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT89_EMIOS2_E2UC_14_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT90_GPIO        (PORT_GPIO_MODE)
#define    PORT90_DSPI_0_dCS1        (PORT_ALT1_FUNC_MODE)
#define    PORT90_LIN_4_LIN4TX        (PORT_ALT2_FUNC_MODE)
#define    PORT90_EMIOS1_E1UC_2_H_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT90_EMIOS2_E2UC_19_Y_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT90_FCCU_EOUT0_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT90_FCCU_EOUT0_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT90_FCCU_EOUT0_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT90_CMP1_CMP1_8        (PORT_ANALOG_INPUT_MODE)
#define    PORT90_EMIOS1_E1UC_2_H_IN        (PORT_INPUT1_MODE)
#define    PORT90_EMIOS2_E2UC_19_Y_IN        (PORT_INPUT2_MODE)
#define    PORT90_EMIOS1_E1UC_2_H_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT90_EMIOS2_E2UC_19_Y_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT91_GPIO        (PORT_GPIO_MODE)
#define    PORT91_DSPI_0_dCS2        (PORT_ALT1_FUNC_MODE)
#define    PORT91_EMIOS1_E1UC_3_H_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT91_EMIOS2_E2UC_20_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT91_WKPU_WKPU_15        (PORT_ONLY_INPUT_MODE)
#define    PORT91_CMP1_CMP1_9        (PORT_ANALOG_INPUT_MODE)
#define    PORT91_EMIOS1_E1UC_3_H_IN        (PORT_INPUT1_MODE)
#define    PORT91_EMIOS2_E2UC_20_Y_IN        (PORT_INPUT2_MODE)
#define    PORT91_LIN_4_LIN4RX        (PORT_INPUT3_MODE)
#define    PORT91_EMIOS1_E1UC_3_H_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT91_EMIOS2_E2UC_20_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT92_GPIO        (PORT_GPIO_MODE)
#define    PORT92_EMIOS1_E1UC_25_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT92_LIN_5_LIN5TX        (PORT_ALT2_FUNC_MODE)
#define    PORT92_EMIOS2_E2UC_16_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT92_FCCU_EOUT1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT92_FCCU_EOUT1_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT92_FCCU_EOUT1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT92_CMP0_CMP0_6        (PORT_ANALOG_INPUT_MODE)
#define    PORT92_EMIOS1_E1UC_25_Y_IN        (PORT_INPUT1_MODE)
#define    PORT92_EMIOS2_E2UC_16_X_IN        (PORT_INPUT2_MODE)
#define    PORT92_EMIOS1_E1UC_25_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT92_EMIOS2_E2UC_16_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT93_GPIO        (PORT_GPIO_MODE)
#define    PORT93_EMIOS1_E1UC_26_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT93_EMIOS2_E2UC_22_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT93_WKPU_WKPU_16        (PORT_ONLY_INPUT_MODE)
#define    PORT93_CMP1_CMP1_11        (PORT_ANALOG_INPUT_MODE)
#define    PORT93_EMIOS1_E1UC_26_Y_IN        (PORT_INPUT1_MODE)
#define    PORT93_EMIOS2_E2UC_22_X_IN        (PORT_INPUT2_MODE)
#define    PORT93_LIN_5_LIN5RX        (PORT_INPUT3_MODE)
#define    PORT93_EMIOS1_E1UC_26_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT93_EMIOS2_E2UC_22_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT94_GPIO        (PORT_GPIO_MODE)
#define    PORT94_FlexCAN_4_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT94_EMIOS1_E1UC_27_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT94_FlexCAN_1_TX        (PORT_ALT3_FUNC_MODE)
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define    PORT94_ENET0_MII_RMII_0_MDIO_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT94_ADC_1_ADC1_X_2        (PORT_ANALOG_INPUT_MODE)
#define    PORT94_EMIOS1_E1UC_27_Y_IN        (PORT_INPUT1_MODE)
#define    PORT94_ENET0_MII_RMII_0_MDIO_IN        (PORT_INPUT2_MODE)
#define    PORT94_EMIOS1_E1UC_27_Y_IN_OUT        (PORT_INOUT2_MODE)
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define    PORT94_ENET0_MII_RMII_0_MDIO_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT95_GPIO        (PORT_GPIO_MODE)
#define    PORT95_EMIOS1_E1UC_4_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT95_ADC_1_ADC1_X_1        (PORT_ANALOG_INPUT_MODE)
#define    PORT95_EMIOS1_E1UC_4_H_IN        (PORT_INPUT1_MODE)
#define    PORT95_SIUL2_EIRQ13        (PORT_INPUT2_MODE)
#define    PORT95_FlexCAN_1_RX        (PORT_INPUT3_MODE)
#define    PORT95_FlexCAN_4_RX        (PORT_INPUT4_MODE)
#define    PORT95_ENET0_MII_RMII_0_RX_DV        (PORT_INPUT5_MODE)
#define    PORT95_EMIOS1_E1UC_4_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT96_GPIO        (PORT_GPIO_MODE)
#define    PORT96_FlexCAN_5_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT96_EMIOS1_E1UC_23_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT96_ENET0_MII_RMII_0_MDC        (PORT_ALT3_FUNC_MODE)
#define    PORT96_ADC_1_ADC1_X_0        (PORT_ANALOG_INPUT_MODE)
#define    PORT96_EMIOS1_E1UC_23_X_IN        (PORT_INPUT1_MODE)
#define    PORT96_EMIOS1_E1UC_23_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT97_GPIO        (PORT_GPIO_MODE)
#define    PORT97_EMIOS1_E1UC_24_X_OUT        (PORT_ALT1_FUNC_MODE)
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define    PORT97_ENET0_MII_RMII_0_TX_CLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT97_ADC_1_ADC1_S_7        (PORT_ANALOG_INPUT_MODE)
#define    PORT97_EMIOS1_E1UC_24_X_IN        (PORT_INPUT1_MODE)
#define    PORT97_SIUL2_EIRQ14        (PORT_INPUT2_MODE)
#define    PORT97_FlexCAN_5_RX        (PORT_INPUT3_MODE)
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define    PORT97_ENET0_MII_RMII_0_TX_CLK_IN        (PORT_INPUT4_MODE)
#define    PORT97_EMIOS1_E1UC_24_X_IN_OUT        (PORT_INOUT1_MODE)
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define    PORT97_ENET0_MII_RMII_0_TX_CLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT98_GPIO        (PORT_GPIO_MODE)
#define    PORT98_EMIOS1_E1UC_11_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT98_DSPI_3_dSOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT98_FlexCAN_7_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT98_LIN_11_LIN11TX        (PORT_ALT4_FUNC_MODE)
#define    PORT98_EMIOS1_E1UC_11_H_IN        (PORT_INPUT1_MODE)
#define    PORT98_EMIOS1_E1UC_11_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT99_GPIO        (PORT_GPIO_MODE)
#define    PORT99_EMIOS1_E1UC_12_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT99_DSPI_3_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT99_EMIOS2_E2UC_1_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT99_WKPU_WKPU_17        (PORT_ONLY_INPUT_MODE)
#define    PORT99_EMIOS1_E1UC_12_H_IN        (PORT_INPUT1_MODE)
#define    PORT99_EMIOS2_E2UC_1_Y_IN        (PORT_INPUT2_MODE)
#define    PORT99_FlexCAN_7_RX        (PORT_INPUT3_MODE)
#define    PORT99_DSPI_3_dSS        (PORT_INPUT4_MODE)
#define    PORT99_EMIOS1_E1UC_12_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT99_EMIOS2_E2UC_1_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT100_GPIO        (PORT_GPIO_MODE)
#define    PORT100_EMIOS1_E1UC_13_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT100_DSPI_3_dSCLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT100_LIN_10_LIN10TX        (PORT_ALT3_FUNC_MODE)
#define    PORT100_EMIOS1_E1UC_13_H_IN        (PORT_INPUT1_MODE)
#define    PORT100_DSPI_3_dSCLK_IN        (PORT_INPUT2_MODE)
#define    PORT100_EMIOS1_E1UC_13_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT100_DSPI_3_dSCLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT101_GPIO        (PORT_GPIO_MODE)
#define    PORT101_EMIOS1_E1UC_14_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT101_EMIOS2_E2UC_2_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT101_WKPU_WKPU_18        (PORT_ONLY_INPUT_MODE)
#define    PORT101_EMIOS1_E1UC_14_H_IN        (PORT_INPUT1_MODE)
#define    PORT101_EMIOS2_E2UC_2_Y_IN        (PORT_INPUT2_MODE)
#define    PORT101_LIN_10_LIN10RX        (PORT_INPUT3_MODE)
#define    PORT101_DSPI_3_dSIN        (PORT_INPUT4_MODE)
#define    PORT101_EMIOS1_E1UC_14_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT101_EMIOS2_E2UC_2_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT102_GPIO        (PORT_GPIO_MODE)
#define    PORT102_EMIOS1_E1UC_15_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT102_LIN_6_LIN6TX        (PORT_ALT2_FUNC_MODE)
#define    PORT102_CGM_CLKOUT1        (PORT_ALT3_FUNC_MODE)
#define    PORT102_EMIOS2_E2UC_3_Y_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT102_CMP0_CMP0_1        (PORT_ANALOG_INPUT_MODE)
#define    PORT102_PMCDIG_EXTREGC        (PORT_ONLY_OUTPUT_MODE)
#define    PORT102_EMIOS1_E1UC_15_H_IN        (PORT_INPUT1_MODE)
#define    PORT102_EMIOS2_E2UC_3_Y_IN        (PORT_INPUT2_MODE)
#define    PORT102_EMIOS1_E1UC_15_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT102_EMIOS2_E2UC_3_Y_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT103_GPIO        (PORT_GPIO_MODE)
#define    PORT103_EMIOS1_E1UC_16_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT103_EMIOS1_E1UC_30_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT103_CGM_CLKOUT0        (PORT_ALT3_FUNC_MODE)
#define    PORT103_EMIOS2_E2UC_2_Y_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT103_WKPU_WKPU_20        (PORT_ONLY_INPUT_MODE)
#define    PORT103_CMP0_CMP0_0        (PORT_ANALOG_INPUT_MODE)
#define    PORT103_EMIOS1_E1UC_16_X_IN        (PORT_INPUT1_MODE)
#define    PORT103_EMIOS1_E1UC_30_Y_IN        (PORT_INPUT2_MODE)
#define    PORT103_EMIOS2_E2UC_2_Y_IN        (PORT_INPUT3_MODE)
#define    PORT103_LIN_6_LIN6RX        (PORT_INPUT4_MODE)
#define    PORT103_EMIOS1_E1UC_16_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT103_EMIOS1_E1UC_30_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT103_EMIOS2_E2UC_2_Y_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT104_GPIO        (PORT_GPIO_MODE)
#define    PORT104_EMIOS1_E1UC_17_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT104_LIN_7_LIN7TX        (PORT_ALT2_FUNC_MODE)
#define    PORT104_DSPI_2_dCS0        (PORT_ALT3_FUNC_MODE)
#define    PORT104_FlexCAN_7_TX        (PORT_ALT4_FUNC_MODE)
#define    PORT104_EMIOS1_E1UC_17_Y_IN        (PORT_INPUT1_MODE)
#define    PORT104_SIUL2_EIRQ15        (PORT_INPUT2_MODE)
#define    PORT104_DSPI_2_dSS        (PORT_INPUT3_MODE)
#define    PORT104_EMIOS1_E1UC_17_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT105_GPIO        (PORT_GPIO_MODE)
#define    PORT105_EMIOS1_E1UC_18_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT105_DSPI_2_dSCLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT105_EMIOS2_E2UC_0_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT105_WKPU_WKPU_21        (PORT_ONLY_INPUT_MODE)
#define    PORT105_EMIOS1_E1UC_18_Y_IN        (PORT_INPUT1_MODE)
#define    PORT105_EMIOS2_E2UC_0_X_IN        (PORT_INPUT2_MODE)
#define    PORT105_FlexCAN_7_RX        (PORT_INPUT3_MODE)
#define    PORT105_LIN_7_LIN7RX        (PORT_INPUT4_MODE)
#define    PORT105_DSPI_2_dSCLK_IN        (PORT_INPUT5_MODE)
#define    PORT105_EMIOS1_E1UC_18_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT105_DSPI_2_dSCLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT105_EMIOS2_E2UC_0_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT106_GPIO        (PORT_GPIO_MODE)
#define    PORT106_EMIOS0_E0UC_24_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT106_EMIOS1_E1UC_31_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT106_USB1_ULPI1_D4_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT106_EMIOS0_E0UC_24_X_IN        (PORT_INPUT1_MODE)
#define    PORT106_EMIOS1_E1UC_31_Y_IN        (PORT_INPUT2_MODE)
#define    PORT106_USB1_ULPI1_D4_IN        (PORT_INPUT3_MODE)
#define    PORT106_SPI_0_SIN_0        (PORT_INPUT4_MODE)
#define    PORT106_EMIOS0_E0UC_24_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT106_EMIOS1_E1UC_31_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT106_USB1_ULPI1_D4_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT107_GPIO        (PORT_GPIO_MODE)
#define    PORT107_EMIOS0_E0UC_25_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT107_SPI_0_CS0_0        (PORT_ALT2_FUNC_MODE)
#define    PORT107_SPI_2_CS0_2        (PORT_ALT3_FUNC_MODE)
#define    PORT107_USB1_ULPI1_D5_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT107_EMIOS0_E0UC_25_Y_IN        (PORT_INPUT1_MODE)
#define    PORT107_USB1_ULPI1_D5_IN        (PORT_INPUT2_MODE)
#define    PORT107_SPI_0_SS_0        (PORT_INPUT3_MODE)
#define    PORT107_SPI_2_SS_2        (PORT_INPUT4_MODE)
#define    PORT107_EMIOS0_E0UC_25_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT107_USB1_ULPI1_D5_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT108_GPIO        (PORT_GPIO_MODE)
#define    PORT108_EMIOS0_E0UC_26_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT108_SPI_0_SOUT_0        (PORT_ALT2_FUNC_MODE)
#define    PORT108_EMIOS2_E2UC_12_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT108_ENET0_MII_0_TXD_2        (PORT_ALT4_FUNC_MODE)
#define    PORT108_ADC_1_ADC1_S_2        (PORT_ANALOG_INPUT_MODE)
#define    PORT108_EMIOS0_E0UC_26_Y_IN        (PORT_INPUT1_MODE)
#define    PORT108_EMIOS2_E2UC_12_Y_IN        (PORT_INPUT2_MODE)
#define    PORT108_EMIOS0_E0UC_26_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT108_EMIOS2_E2UC_12_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT109_GPIO        (PORT_GPIO_MODE)
#define    PORT109_EMIOS0_E0UC_27_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT109_SPI_0_SCLK_0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT109_EMIOS2_E2UC_13_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT109_ENET0_MII_0_TXD_3        (PORT_ALT4_FUNC_MODE)
#define    PORT109_ADC_1_ADC1_S_1        (PORT_ANALOG_INPUT_MODE)
#define    PORT109_EMIOS0_E0UC_27_Y_IN        (PORT_INPUT1_MODE)
#define    PORT109_EMIOS2_E2UC_13_Y_IN        (PORT_INPUT2_MODE)
#define    PORT109_SPI_0_SCLK_0_IN        (PORT_INPUT3_MODE)
#define    PORT109_EMIOS0_E0UC_27_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT109_SPI_0_SCLK_0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT109_EMIOS2_E2UC_13_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT110_GPIO        (PORT_GPIO_MODE)
#define    PORT110_EMIOS1_E1UC_0_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT110_LIN_8_LIN8TX        (PORT_ALT2_FUNC_MODE)
#define    PORT110_USB1_ULPI1_D0_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT110_EMIOS1_E1UC_0_X_IN        (PORT_INPUT1_MODE)
#define    PORT110_USB1_ULPI1_D0_IN        (PORT_INPUT2_MODE)
#define    PORT110_SPI_2_SIN_2        (PORT_INPUT3_MODE)
#define    PORT110_EMIOS1_E1UC_0_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT110_USB1_ULPI1_D0_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT111_GPIO        (PORT_GPIO_MODE)
#define    PORT111_EMIOS1_E1UC_1_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT111_SPI_2_SOUT_2        (PORT_ALT2_FUNC_MODE)
#define    PORT111_USB1_ULPI1_D1_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT111_EMIOS1_E1UC_1_H_IN        (PORT_INPUT1_MODE)
#define    PORT111_LIN_8_LIN8RX        (PORT_INPUT2_MODE)
#define    PORT111_USB1_ULPI1_D1_IN        (PORT_INPUT3_MODE)
#define    PORT111_EMIOS1_E1UC_1_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT111_USB1_ULPI1_D1_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT112_GPIO        (PORT_GPIO_MODE)
#define    PORT112_EMIOS1_E1UC_2_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT112_EMIOS2_E2UC_11_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT112_ENET0_MII_RMII_0_TXD_1        (PORT_ALT3_FUNC_MODE)
#define    PORT112_ADC_1_ADC1_S_3        (PORT_ANALOG_INPUT_MODE)
#define    PORT112_EMIOS1_E1UC_2_H_IN        (PORT_INPUT1_MODE)
#define    PORT112_EMIOS2_E2UC_11_Y_IN        (PORT_INPUT2_MODE)
#define    PORT112_DSPI_1_dSIN        (PORT_INPUT3_MODE)
#define    PORT112_EMIOS1_E1UC_2_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT112_EMIOS2_E2UC_11_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT113_GPIO        (PORT_GPIO_MODE)
#define    PORT113_EMIOS1_E1UC_3_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT113_DSPI_1_dSOUT        (PORT_ALT2_FUNC_MODE)
#define    PORT113_EMIOS2_E2UC_10_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT113_ENET0_MII_RMII_0_TXD_0        (PORT_ALT4_FUNC_MODE)
#define    PORT113_ADC_1_ADC1_S_4        (PORT_ANALOG_INPUT_MODE)
#define    PORT113_EMIOS1_E1UC_3_H_IN        (PORT_INPUT1_MODE)
#define    PORT113_EMIOS2_E2UC_10_Y_IN        (PORT_INPUT2_MODE)
#define    PORT113_EMIOS1_E1UC_3_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT113_EMIOS2_E2UC_10_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT114_GPIO        (PORT_GPIO_MODE)
#define    PORT114_EMIOS1_E1UC_4_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT114_DSPI_1_dSCLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT114_EMIOS2_E2UC_9_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT114_ENET0_MII_RMII_0_TX_EN        (PORT_ALT4_FUNC_MODE)
#define    PORT114_ADC_1_ADC1_S_5        (PORT_ANALOG_INPUT_MODE)
#define    PORT114_EMIOS1_E1UC_4_H_IN        (PORT_INPUT1_MODE)
#define    PORT114_EMIOS2_E2UC_9_Y_IN        (PORT_INPUT2_MODE)
#define    PORT114_DSPI_1_dSCLK_IN        (PORT_INPUT3_MODE)
#define    PORT114_EMIOS1_E1UC_4_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT114_DSPI_1_dSCLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT114_EMIOS2_E2UC_9_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT115_GPIO        (PORT_GPIO_MODE)
#define    PORT115_EMIOS1_E1UC_5_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT115_DSPI_1_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT115_ENET0_MII_0_TX_ER        (PORT_ALT3_FUNC_MODE)
#define    PORT115_ENET1_MII_1_TXD_2        (PORT_ALT4_FUNC_MODE)
#define    PORT115_ADC_1_ADC1_S_6        (PORT_ANALOG_INPUT_MODE)
#define    PORT115_EMIOS1_E1UC_5_H_IN        (PORT_INPUT1_MODE)
#define    PORT115_DSPI_1_dSS        (PORT_INPUT2_MODE)
#define    PORT115_EMIOS1_E1UC_5_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT116_GPIO        (PORT_GPIO_MODE)
#define    PORT116_EMIOS1_E1UC_6_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT116_SPI_3_SOUT_3        (PORT_ALT2_FUNC_MODE)
#define    PORT116_IIC_3_SCL3_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT116_USB0_ULPI0_D4_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT116_EMIOS1_E1UC_6_H_IN        (PORT_INPUT1_MODE)
#define    PORT116_USB0_ULPI0_D4_IN        (PORT_INPUT2_MODE)
#define    PORT116_IIC_3_SCL3_IN        (PORT_INPUT3_MODE)
#define    PORT116_EMIOS1_E1UC_6_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT116_IIC_3_SCL3_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT116_USB0_ULPI0_D4_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT117_GPIO        (PORT_GPIO_MODE)
#define    PORT117_EMIOS1_E1UC_7_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT117_IIC_3_SDA3_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT117_USB0_ULPI0_D5_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT117_EMIOS1_E1UC_7_H_IN        (PORT_INPUT1_MODE)
#define    PORT117_USB0_ULPI0_D5_IN        (PORT_INPUT2_MODE)
#define    PORT117_IIC_3_SDA3_IN        (PORT_INPUT3_MODE)
#define    PORT117_SPI_3_SIN_3        (PORT_INPUT4_MODE)
#define    PORT117_EMIOS1_E1UC_7_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT117_IIC_3_SDA3_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT117_USB0_ULPI0_D5_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT118_GPIO        (PORT_GPIO_MODE)
#define    PORT118_EMIOS1_E1UC_8_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT118_SPI_3_SCLK_3_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT118_ADC_0_ADC0_MA_2        (PORT_ALT3_FUNC_MODE)
#define    PORT118_ADC_1_ADC1_MA_2        (PORT_ALT4_FUNC_MODE)
#define    PORT118_USB0_ULPI0_D6_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT118_EMIOS1_E1UC_8_X_IN        (PORT_INPUT1_MODE)
#define    PORT118_USB0_ULPI0_D6_IN        (PORT_INPUT2_MODE)
#define    PORT118_SPI_3_SCLK_3_IN        (PORT_INPUT3_MODE)
#define    PORT118_EMIOS1_E1UC_8_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT118_SPI_3_SCLK_3_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT118_USB0_ULPI0_D6_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT119_GPIO        (PORT_GPIO_MODE)
#define    PORT119_EMIOS1_E1UC_9_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT119_DSPI_2_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT119_ADC_0_ADC0_MA_1        (PORT_ALT3_FUNC_MODE)
#define    PORT119_SPI_3_CS0_3        (PORT_ALT4_FUNC_MODE)
#define    PORT119_ADC_1_ADC1_MA_1        (PORT_ALT5_FUNC_MODE)
#define    PORT119_USB0_ULPI0_D7_OUT        (PORT_ALT6_FUNC_MODE)
#define    PORT119_EMIOS1_E1UC_9_H_IN        (PORT_INPUT1_MODE)
#define    PORT119_USB0_ULPI0_D7_IN        (PORT_INPUT2_MODE)
#define    PORT119_SPI_3_SS_3        (PORT_INPUT3_MODE)
#define    PORT119_EMIOS1_E1UC_9_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT119_USB0_ULPI0_D7_IN_OUT        (PORT_INOUT6_MODE)
#define    PORT120_GPIO        (PORT_GPIO_MODE)
#define    PORT120_EMIOS1_E1UC_10_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT120_DSPI_2_dCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT120_ADC_0_ADC0_MA_0        (PORT_ALT3_FUNC_MODE)
#define    PORT120_ADC_1_ADC1_MA_0        (PORT_ALT4_FUNC_MODE)
#define    PORT120_USDHC_SD_RST        (PORT_ALT5_FUNC_MODE)
#define    PORT120_EMIOS1_E1UC_10_H_IN        (PORT_INPUT1_MODE)
#define    PORT120_USDHC_SD_WP        (PORT_INPUT2_MODE)
#define    PORT120_EMIOS1_E1UC_10_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT121_GPIO        (PORT_GPIO_MODE)
#define    PORT121_DCI_TCK        (PORT_ALT1_FUNC_MODE)
#define    PORT122_GPIO        (PORT_GPIO_MODE)
#define    PORT122_DCI_TMS_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT122_DCI_TMS_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT122_DCI_TMS_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT123_GPIO        (PORT_GPIO_MODE)
#define    PORT123_DSPI_3_dSOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT123_SPI_0_CS0_0        (PORT_ALT2_FUNC_MODE)
#define    PORT123_EMIOS1_E1UC_5_H_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT123_USB1_ULPI1_D6_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT123_EMIOS1_E1UC_5_H_IN        (PORT_INPUT1_MODE)
#define    PORT123_USB1_ULPI1_D6_IN        (PORT_INPUT2_MODE)
#define    PORT123_SPI_0_SS_0        (PORT_INPUT3_MODE)
#define    PORT123_EMIOS1_E1UC_5_H_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT123_USB1_ULPI1_D6_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT124_GPIO        (PORT_GPIO_MODE)
#define    PORT124_DSPI_3_dSCLK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT124_SPI_0_CS1_0        (PORT_ALT2_FUNC_MODE)
#define    PORT124_EMIOS1_E1UC_25_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT124_USB1_ULPI1_D7_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT124_EMIOS1_E1UC_25_Y_IN        (PORT_INPUT1_MODE)
#define    PORT124_USB1_ULPI1_D7_IN        (PORT_INPUT2_MODE)
#define    PORT124_DSPI_3_dSCLK_IN        (PORT_INPUT3_MODE)
#define    PORT124_DSPI_3_dSCLK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT124_EMIOS1_E1UC_25_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT124_USB1_ULPI1_D7_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT125_GPIO        (PORT_GPIO_MODE)
#define    PORT125_SPI_0_SOUT_0        (PORT_ALT1_FUNC_MODE)
#define    PORT125_DSPI_3_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT125_EMIOS1_E1UC_26_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT125_FCCU_EOUT1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT125_FCCU_EOUT1_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT125_FCCU_EOUT1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT125_EMIOS1_E1UC_26_Y_IN        (PORT_INPUT1_MODE)
#define    PORT125_DSPI_3_dSS        (PORT_INPUT2_MODE)
#define    PORT125_EMIOS1_E1UC_26_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT126_GPIO        (PORT_GPIO_MODE)
#define    PORT126_SPI_0_SCLK_0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT126_DSPI_3_dCS1        (PORT_ALT2_FUNC_MODE)
#define    PORT126_EMIOS1_E1UC_27_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT126_EMIOS1_E1UC_27_Y_IN        (PORT_INPUT1_MODE)
#define    PORT126_SPI_0_SCLK_0_IN        (PORT_INPUT2_MODE)
#define    PORT126_FCCU_EIN_ERR        (PORT_INPUT3_MODE)
#define    PORT126_SPI_0_SCLK_0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT126_EMIOS1_E1UC_27_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT127_GPIO        (PORT_GPIO_MODE)
#define    PORT127_SPI_1_SOUT_1        (PORT_ALT1_FUNC_MODE)
#define    PORT127_EMIOS2_E2UC_3_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT127_EMIOS1_E1UC_17_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT127_FCCU_EOUT0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT127_FCCU_EOUT0_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT127_FCCU_EOUT0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT127_EMIOS1_E1UC_17_Y_IN        (PORT_INPUT1_MODE)
#define    PORT127_EMIOS2_E2UC_3_Y_IN        (PORT_INPUT2_MODE)
#define    PORT127_EMIOS2_E2UC_3_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT127_EMIOS1_E1UC_17_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT128_GPIO        (PORT_GPIO_MODE)
#define    PORT128_EMIOS0_E0UC_28_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT128_LIN_8_LIN8TX        (PORT_ALT2_FUNC_MODE)
#define    PORT128_IIC_1_SDA1_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT128_USDHC_SD_DAT3_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT128_EMIOS0_E0UC_28_Y_IN        (PORT_INPUT1_MODE)
#define    PORT128_IIC_1_SDA1_IN        (PORT_INPUT2_MODE)
#define    PORT128_USDHC_SD_DAT3_IN        (PORT_INPUT3_MODE)
#define    PORT128_EMIOS0_E0UC_28_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT128_IIC_1_SDA1_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT128_USDHC_SD_DAT3_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT129_GPIO        (PORT_GPIO_MODE)
#define    PORT129_EMIOS0_E0UC_29_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT129_IIC_1_SCL1_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT129_USDHC_SD_DAT2_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT129_WKPU_WKPU_24        (PORT_ONLY_INPUT_MODE)
#define    PORT129_EMIOS0_E0UC_29_Y_IN        (PORT_INPUT1_MODE)
#define    PORT129_LIN_8_LIN8RX        (PORT_INPUT2_MODE)
#define    PORT129_IIC_1_SCL1_IN        (PORT_INPUT3_MODE)
#define    PORT129_USDHC_SD_DAT2_IN        (PORT_INPUT4_MODE)
#define    PORT129_EMIOS0_E0UC_29_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT129_IIC_1_SCL1_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT129_USDHC_SD_DAT2_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT130_GPIO        (PORT_GPIO_MODE)
#define    PORT130_EMIOS0_E0UC_30_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT130_LIN_9_LIN9TX        (PORT_ALT2_FUNC_MODE)
#define    PORT130_IIC_2_SDA2_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT130_USDHC_SD_DAT1_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT130_EMIOS0_E0UC_30_Y_IN        (PORT_INPUT1_MODE)
#define    PORT130_IIC_2_SDA2_IN        (PORT_INPUT2_MODE)
#define    PORT130_USDHC_SD_DAT1_IN        (PORT_INPUT3_MODE)
#define    PORT130_EMIOS0_E0UC_30_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT130_IIC_2_SDA2_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT130_USDHC_SD_DAT1_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT131_GPIO        (PORT_GPIO_MODE)
#define    PORT131_EMIOS0_E0UC_31_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT131_IIC_2_SCL2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT131_USDHC_SD_DAT0_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT131_WKPU_WKPU_23        (PORT_ONLY_INPUT_MODE)
#define    PORT131_EMIOS0_E0UC_31_Y_IN        (PORT_INPUT1_MODE)
#define    PORT131_LIN_9_LIN9RX        (PORT_INPUT2_MODE)
#define    PORT131_IIC_2_SCL2_IN        (PORT_INPUT3_MODE)
#define    PORT131_USDHC_SD_DAT0_IN        (PORT_INPUT4_MODE)
#define    PORT131_EMIOS0_E0UC_31_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT131_IIC_2_SCL2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT131_USDHC_SD_DAT0_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT132_GPIO        (PORT_GPIO_MODE)
#define    PORT132_EMIOS1_E1UC_28_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT132_SPI_0_SOUT_0        (PORT_ALT2_FUNC_MODE)
#define    PORT132_USB1_ULPI1_STP        (PORT_ALT3_FUNC_MODE)
#define    PORT132_EMIOS1_E1UC_28_Y_IN        (PORT_INPUT1_MODE)
#define    PORT132_EMIOS1_E1UC_28_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT133_GPIO        (PORT_GPIO_MODE)
#define    PORT133_EMIOS1_E1UC_29_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT133_SPI_0_SCLK_0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT133_SPI_1_CS2_1        (PORT_ALT3_FUNC_MODE)
#define    PORT133_SPI_2_CS2_2        (PORT_ALT4_FUNC_MODE)
#define    PORT133_EMIOS1_E1UC_29_Y_IN        (PORT_INPUT1_MODE)
#define    PORT133_USB1_ULPI1_NXT        (PORT_INPUT2_MODE)
#define    PORT133_SPI_0_SCLK_0_IN        (PORT_INPUT3_MODE)
#define    PORT133_EMIOS1_E1UC_29_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT133_SPI_0_SCLK_0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT134_GPIO        (PORT_GPIO_MODE)
#define    PORT134_EMIOS1_E1UC_30_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT134_SPI_0_CS0_0        (PORT_ALT2_FUNC_MODE)
#define    PORT134_SPI_1_CS0_1        (PORT_ALT3_FUNC_MODE)
#define    PORT134_SPI_2_CS0_2        (PORT_ALT4_FUNC_MODE)
#define    PORT134_HSM_DO0        (PORT_ALT5_FUNC_MODE)
#define    PORT134_EMIOS1_E1UC_30_Y_IN        (PORT_INPUT1_MODE)
#define    PORT134_SPI_0_SS_0        (PORT_INPUT2_MODE)
#define    PORT134_SPI_1_SS_1        (PORT_INPUT3_MODE)
#define    PORT134_SPI_2_SS_2        (PORT_INPUT4_MODE)
#define    PORT134_EMIOS1_E1UC_30_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT135_GPIO        (PORT_GPIO_MODE)
#define    PORT135_EMIOS1_E1UC_31_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT135_SPI_0_CS1_0        (PORT_ALT2_FUNC_MODE)
#define    PORT135_SPI_1_CS1_1        (PORT_ALT3_FUNC_MODE)
#define    PORT135_SPI_2_CS1_2        (PORT_ALT4_FUNC_MODE)
#define    PORT135_HSM_DO1        (PORT_ALT5_FUNC_MODE)
#define    PORT135_EMIOS1_E1UC_31_Y_IN        (PORT_INPUT1_MODE)
#define    PORT135_EMIOS1_E1UC_31_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT136_GPIO        (PORT_GPIO_MODE)
#define    PORT136_EMIOS2_E2UC_15_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT136_ADC_0_ADC0_S_16        (PORT_ANALOG_INPUT_MODE)
#define    PORT136_EMIOS2_E2UC_15_Y_IN        (PORT_INPUT1_MODE)
#define    PORT136_MLB_MLBCLK        (PORT_INPUT2_MODE)
#define    PORT136_ENET1_MII_1_RX_CLK        (PORT_INPUT3_MODE)
#define    PORT136_EMIOS2_E2UC_15_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT137_GPIO        (PORT_GPIO_MODE)
#define    PORT137_EMIOS2_E2UC_20_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT137_ADC_0_ADC0_S_17        (PORT_ANALOG_INPUT_MODE)
#define    PORT137_EMIOS2_E2UC_20_Y_IN        (PORT_INPUT1_MODE)
#define    PORT137_EMIOS2_E2UC_20_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT138_GPIO        (PORT_GPIO_MODE)
#define    PORT138_EMIOS2_E2UC_21_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT138_ADC_0_ADC0_S_18        (PORT_ANALOG_INPUT_MODE)
#define    PORT138_EMIOS2_E2UC_21_Y_IN        (PORT_INPUT1_MODE)
#define    PORT138_EMIOS2_E2UC_21_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT139_GPIO        (PORT_GPIO_MODE)
#define    PORT139_EMIOS2_E2UC_14_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT139_ENET0_ENET0_TMR1_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT139_ADC_0_ADC0_S_19        (PORT_ANALOG_INPUT_MODE)
#define    PORT139_EMIOS2_E2UC_14_Y_IN        (PORT_INPUT1_MODE)
#define    PORT139_DSPI_3_dSIN        (PORT_INPUT2_MODE)
#define    PORT139_ENET0_ENET0_TMR1_IN        (PORT_INPUT3_MODE)
#define    PORT139_EMIOS2_E2UC_14_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT139_ENET0_ENET0_TMR1_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT140_GPIO        (PORT_GPIO_MODE)
#define    PORT140_DSPI_3_dCS0        (PORT_ALT1_FUNC_MODE)
#define    PORT140_DSPI_2_dCS0        (PORT_ALT2_FUNC_MODE)
#define    PORT140_ENET1_MII_1_TX_EN        (PORT_ALT3_FUNC_MODE)
#define    PORT140_ADC_0_ADC0_S_20        (PORT_ANALOG_INPUT_MODE)
#define    PORT140_DSPI_2_dSS        (PORT_INPUT1_MODE)
#define    PORT140_DSPI_3_dSS        (PORT_INPUT2_MODE)
#define    PORT141_GPIO        (PORT_GPIO_MODE)
#define    PORT141_DSPI_3_dCS1        (PORT_ALT1_FUNC_MODE)
#define    PORT141_DSPI_2_dCS1        (PORT_ALT2_FUNC_MODE)
#define    PORT141_ENET1_MII_1_TXD_3        (PORT_ALT3_FUNC_MODE)
#define    PORT141_ADC_0_ADC0_S_21        (PORT_ANALOG_INPUT_MODE)
#define    PORT142_GPIO        (PORT_GPIO_MODE)
#define    PORT142_SAI2_SAI2_D0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT142_ADC_0_ADC0_S_22        (PORT_ANALOG_INPUT_MODE)
#define    PORT142_SPI_0_SIN_0        (PORT_INPUT1_MODE)
#define    PORT142_SAI2_SAI2_D0_IN        (PORT_INPUT2_MODE)
#define    PORT142_SAI2_SAI2_D0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT143_GPIO        (PORT_GPIO_MODE)
#define    PORT143_SPI_0_CS0_0        (PORT_ALT1_FUNC_MODE)
#define    PORT143_DSPI_2_dCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT143_SAI2_SAI2_MCLK_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT143_ADC_0_ADC0_S_23        (PORT_ANALOG_INPUT_MODE)
#define    PORT143_SPI_0_SS_0        (PORT_INPUT1_MODE)
#define    PORT143_SAI2_SAI2_MCLK_IN        (PORT_INPUT2_MODE)
#define    PORT143_SAI2_SAI2_MCLK_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT144_GPIO        (PORT_GPIO_MODE)
#define    PORT144_SPI_0_CS1_0        (PORT_ALT1_FUNC_MODE)
#define    PORT144_DSPI_2_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT144_SAI2_SAI2_SYNC_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT144_EMIOS2_E2UC_19_Y_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT144_ADC_0_ADC0_S_24        (PORT_ANALOG_INPUT_MODE)
#define    PORT144_EMIOS2_E2UC_19_Y_IN        (PORT_INPUT1_MODE)
#define    PORT144_SAI2_SAI2_SYNC_IN        (PORT_INPUT2_MODE)
#define    PORT144_SAI2_SAI2_SYNC_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT144_EMIOS2_E2UC_19_Y_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT145_GPIO        (PORT_GPIO_MODE)
#define    PORT145_SPI_0_SOUT_0        (PORT_ALT1_FUNC_MODE)
#define    PORT145_SAI2_SAI2_BCLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT145_ADC_0_ADC0_S_25        (PORT_ANALOG_INPUT_MODE)
#define    PORT145_SPI_1_SIN_1        (PORT_INPUT1_MODE)
#define    PORT145_SAI2_SAI2_BCLK_IN        (PORT_INPUT2_MODE)
#define    PORT145_SAI2_SAI2_BCLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT146_GPIO        (PORT_GPIO_MODE)
#define    PORT146_SPI_1_CS0_1        (PORT_ALT1_FUNC_MODE)
#define    PORT146_SPI_2_CS0_2        (PORT_ALT2_FUNC_MODE)
#define    PORT146_SPI_3_CS0_3        (PORT_ALT3_FUNC_MODE)
#define    PORT146_SAI1_SAI1_D0_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT146_ADC_0_ADC0_S_26        (PORT_ANALOG_INPUT_MODE)
#define    PORT146_SPI_1_SS_1        (PORT_INPUT1_MODE)
#define    PORT146_SPI_2_SS_2        (PORT_INPUT2_MODE)
#define    PORT146_SPI_3_SS_3        (PORT_INPUT3_MODE)
#define    PORT146_SAI1_SAI1_D0_IN        (PORT_INPUT4_MODE)
#define    PORT146_SAI1_SAI1_D0_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT147_GPIO        (PORT_GPIO_MODE)
#define    PORT147_SPI_1_CS1_1        (PORT_ALT1_FUNC_MODE)
#define    PORT147_SPI_2_CS1_2        (PORT_ALT2_FUNC_MODE)
#define    PORT147_SPI_3_CS1_3        (PORT_ALT3_FUNC_MODE)
#define    PORT147_SAI1_SAI1_BCLK_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT147_ADC_0_ADC0_S_27        (PORT_ANALOG_INPUT_MODE)
#define    PORT147_SAI1_SAI1_BCLK_IN        (PORT_INPUT1_MODE)
#define    PORT147_SAI1_SAI1_BCLK_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT148_GPIO        (PORT_GPIO_MODE)
#define    PORT148_SPI_1_SCLK_1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT148_EMIOS1_E1UC_18_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT148_EMIOS2_E2UC_4_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT148_EMIOS1_E1UC_18_Y_IN        (PORT_INPUT1_MODE)
#define    PORT148_EMIOS2_E2UC_4_Y_IN        (PORT_INPUT2_MODE)
#define    PORT148_SPI_1_SCLK_1_IN        (PORT_INPUT3_MODE)
#define    PORT148_FCCU_EIN_ERR        (PORT_INPUT4_MODE)
#define    PORT148_SPI_1_SCLK_1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT148_EMIOS1_E1UC_18_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT148_EMIOS2_E2UC_4_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT149_GPIO        (PORT_GPIO_MODE)
#define    PORT149_EMIOS2_E2UC_16_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT149_SAI2_SAI2_D0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT149_ADC_0_ADC0_S_28        (PORT_ANALOG_INPUT_MODE)
#define    PORT149_EMIOS2_E2UC_16_X_IN        (PORT_INPUT1_MODE)
#define    PORT149_SAI2_SAI2_D0_IN        (PORT_INPUT2_MODE)
#define    PORT149_EMIOS2_E2UC_16_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT149_SAI2_SAI2_D0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT150_GPIO        (PORT_GPIO_MODE)
#define    PORT150_EMIOS2_E2UC_17_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT150_SAI2_SAI2_BCLK_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT150_ADC_0_ADC0_S_29        (PORT_ANALOG_INPUT_MODE)
#define    PORT150_EMIOS2_E2UC_17_Y_IN        (PORT_INPUT1_MODE)
#define    PORT150_SAI2_SAI2_BCLK_IN        (PORT_INPUT2_MODE)
#define    PORT150_EMIOS2_E2UC_17_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT150_SAI2_SAI2_BCLK_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT151_GPIO        (PORT_GPIO_MODE)
#define    PORT151_EMIOS2_E2UC_18_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT151_ADC_0_ADC0_S_30        (PORT_ANALOG_INPUT_MODE)
#define    PORT151_SAI2_SAI2_MCLK_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT151_EMIOS2_E2UC_18_Y_IN        (PORT_INPUT1_MODE)
#define    PORT151_SAI2_SAI2_MCLK_IN        (PORT_INPUT2_MODE)
#define    PORT151_EMIOS2_E2UC_18_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT151_SAI2_SAI2_MCLK_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT152_GPIO        (PORT_GPIO_MODE)
#define    PORT152_EMIOS2_E2UC_19_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT152_SAI2_SAI2_SYNC_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT152_ADC_0_ADC0_S_31        (PORT_ANALOG_INPUT_MODE)
#define    PORT152_EMIOS2_E2UC_19_Y_IN        (PORT_INPUT1_MODE)
#define    PORT152_SAI2_SAI2_SYNC_IN        (PORT_INPUT2_MODE)
#define    PORT152_EMIOS2_E2UC_19_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT152_SAI2_SAI2_SYNC_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT153_GPIO        (PORT_GPIO_MODE)
#define    PORT153_FlexCAN_4_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT153_EMIOS1_E1UC_17_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT153_EMIOS1_E1UC_17_Y_IN        (PORT_INPUT1_MODE)
#define    PORT153_EMIOS1_E1UC_17_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT154_GPIO        (PORT_GPIO_MODE)
#define    PORT154_EMIOS1_E1UC_16_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT154_EMIOS1_E1UC_16_X_IN        (PORT_INPUT1_MODE)
#define    PORT154_FlexCAN_4_RX        (PORT_INPUT2_MODE)
#define    PORT154_EMIOS1_E1UC_16_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT155_GPIO        (PORT_GPIO_MODE)
#define    PORT155_FlexCAN_2_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT155_EMIOS1_E1UC_11_H_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT155_EMIOS1_E1UC_11_H_IN        (PORT_INPUT1_MODE)
#define    PORT155_EMIOS1_E1UC_11_H_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT156_GPIO        (PORT_GPIO_MODE)
#define    PORT156_EMIOS1_E1UC_10_H_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT156_EMIOS1_E1UC_10_H_IN        (PORT_INPUT1_MODE)
#define    PORT156_FlexCAN_2_RX        (PORT_INPUT2_MODE)
#define    PORT156_EMIOS1_E1UC_10_H_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT157_GPIO        (PORT_GPIO_MODE)
#define    PORT157_SPI_3_CS1_3        (PORT_ALT1_FUNC_MODE)
#define    PORT157_SPI_5_CS0_5        (PORT_ALT2_FUNC_MODE)
#define    PORT157_EMIOS1_E1UC_15_H_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT157_WKPU_WKPU_31        (PORT_ONLY_INPUT_MODE)
#define    PORT157_EMIOS1_E1UC_15_H_IN        (PORT_INPUT1_MODE)
#define    PORT157_FlexCAN_1_RX        (PORT_INPUT2_MODE)
#define    PORT157_FlexCAN_4_RX        (PORT_INPUT3_MODE)
#define    PORT157_FlexCAN_6_RX        (PORT_INPUT4_MODE)
#define    PORT157_SPI_5_SS_5        (PORT_INPUT5_MODE)
#define    PORT157_EMIOS1_E1UC_15_H_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT158_GPIO        (PORT_GPIO_MODE)
#define    PORT158_FlexCAN_1_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT158_FlexCAN_4_TX        (PORT_ALT2_FUNC_MODE)
#define    PORT158_SPI_3_CS2_3        (PORT_ALT3_FUNC_MODE)
#define    PORT158_FlexCAN_6_TX        (PORT_ALT4_FUNC_MODE)
#define    PORT158_SPI_5_SCLK_5_OUT        (PORT_ALT5_FUNC_MODE)
#define    PORT158_EMIOS1_E1UC_14_H_OUT        (PORT_ALT6_FUNC_MODE)
#define    PORT158_EMIOS1_E1UC_14_H_IN        (PORT_INPUT1_MODE)
#define    PORT158_SPI_5_SCLK_5_IN        (PORT_INPUT2_MODE)
#define    PORT158_SPI_5_SCLK_5_IN_OUT        (PORT_INOUT5_MODE)
#define    PORT158_EMIOS1_E1UC_14_H_IN_OUT        (PORT_INOUT6_MODE)
#define    PORT159_GPIO        (PORT_GPIO_MODE)
#define    PORT159_SPI_2_CS1_2        (PORT_ALT1_FUNC_MODE)
#define    PORT159_EMIOS1_E1UC_13_H_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT159_SPI_5_SOUT_5        (PORT_ALT3_FUNC_MODE)
#define    PORT159_EMIOS1_E1UC_13_H_IN        (PORT_INPUT1_MODE)
#define    PORT159_FlexCAN_1_RX        (PORT_INPUT2_MODE)
#define    PORT159_FlexCAN_3_RX        (PORT_INPUT3_MODE)
#define    PORT159_EMIOS1_E1UC_13_H_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT160_GPIO        (PORT_GPIO_MODE)
#define    PORT160_FlexCAN_1_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT160_SPI_2_CS2_2        (PORT_ALT2_FUNC_MODE)
#define    PORT160_FlexCAN_3_TX        (PORT_ALT3_FUNC_MODE)
#define    PORT160_EMIOS1_E1UC_12_H_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT160_EMIOS1_E1UC_12_H_IN        (PORT_INPUT1_MODE)
#define    PORT160_SPI_5_SIN_5        (PORT_INPUT2_MODE)
#define    PORT160_EMIOS1_E1UC_12_H_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT161_GPIO        (PORT_GPIO_MODE)
#define    PORT161_SPI_2_CS3_2        (PORT_ALT1_FUNC_MODE)
#define    PORT161_EMIOS2_E2UC_6_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT161_EMIOS1_E1UC_1_H_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT161_EMIOS1_E1UC_1_H_IN        (PORT_INPUT1_MODE)
#define    PORT161_EMIOS2_E2UC_6_Y_IN        (PORT_INPUT2_MODE)
#define    PORT161_FlexCAN_4_RX        (PORT_INPUT3_MODE)
#define    PORT161_EMIOS2_E2UC_6_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT161_EMIOS1_E1UC_1_H_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT162_GPIO        (PORT_GPIO_MODE)
#define    PORT162_FlexCAN_4_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT162_EMIOS2_E2UC_7_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT162_EMIOS1_E1UC_2_H_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT162_EMIOS1_E1UC_2_H_IN        (PORT_INPUT1_MODE)
#define    PORT162_EMIOS2_E2UC_7_Y_IN        (PORT_INPUT2_MODE)
#define    PORT162_EMIOS2_E2UC_7_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT162_EMIOS1_E1UC_2_H_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT163_GPIO        (PORT_GPIO_MODE)
#define    PORT163_EMIOS1_E1UC_0_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT163_EMIOS2_E2UC_8_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT163_EMIOS1_E1UC_3_H_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT163_EMIOS1_E1UC_0_X_IN        (PORT_INPUT1_MODE)
#define    PORT163_EMIOS1_E1UC_3_H_IN        (PORT_INPUT2_MODE)
#define    PORT163_EMIOS2_E2UC_8_X_IN        (PORT_INPUT3_MODE)
#define    PORT163_SIUL2_EIRQ31        (PORT_INPUT4_MODE)
#define    PORT163_FlexCAN_5_RX        (PORT_INPUT5_MODE)
#define    PORT163_LIN_8_LIN8RX        (PORT_INPUT6_MODE)
#define    PORT163_EMIOS1_E1UC_0_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT163_EMIOS2_E2UC_8_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT163_EMIOS1_E1UC_3_H_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT164_GPIO        (PORT_GPIO_MODE)
#define    PORT164_FlexCAN_5_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT164_LIN_8_LIN8TX        (PORT_ALT2_FUNC_MODE)
#define    PORT164_EMIOS1_E1UC_1_H_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT164_EMIOS2_E2UC_9_Y_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT164_EMIOS1_E1UC_1_H_IN        (PORT_INPUT1_MODE)
#define    PORT164_EMIOS2_E2UC_9_Y_IN        (PORT_INPUT2_MODE)
#define    PORT164_EMIOS1_E1UC_1_H_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT164_EMIOS2_E2UC_9_Y_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT165_GPIO        (PORT_GPIO_MODE)
#define    PORT165_EMIOS2_E2UC_10_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT165_EMIOS1_E1UC_4_H_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT165_EMIOS1_E1UC_4_H_IN        (PORT_INPUT1_MODE)
#define    PORT165_EMIOS2_E2UC_10_Y_IN        (PORT_INPUT2_MODE)
#define    PORT165_FlexCAN_2_RX        (PORT_INPUT3_MODE)
#define    PORT165_LIN_2_LIN2RX        (PORT_INPUT4_MODE)
#define    PORT165_EMIOS2_E2UC_10_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT165_EMIOS1_E1UC_4_H_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT166_GPIO        (PORT_GPIO_MODE)
#define    PORT166_FlexCAN_2_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT166_LIN_2_LIN2TX        (PORT_ALT2_FUNC_MODE)
#define    PORT166_EMIOS2_E2UC_11_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT166_EMIOS1_E1UC_5_H_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT166_EMIOS1_E1UC_5_H_IN        (PORT_INPUT1_MODE)
#define    PORT166_EMIOS2_E2UC_11_Y_IN        (PORT_INPUT2_MODE)
#define    PORT166_EMIOS2_E2UC_11_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT166_EMIOS1_E1UC_5_H_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT167_GPIO        (PORT_GPIO_MODE)
#define    PORT167_EMIOS2_E2UC_12_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT167_EMIOS1_E1UC_6_H_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT167_EMIOS1_E1UC_6_H_IN        (PORT_INPUT1_MODE)
#define    PORT167_EMIOS2_E2UC_12_Y_IN        (PORT_INPUT2_MODE)
#define    PORT167_FlexCAN_3_RX        (PORT_INPUT3_MODE)
#define    PORT167_LIN_3_LIN3RX        (PORT_INPUT4_MODE)
#define    PORT167_EMIOS2_E2UC_12_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT167_EMIOS1_E1UC_6_H_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT168_GPIO        (PORT_GPIO_MODE)
#define    PORT168_FlexCAN_3_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT168_LIN_3_LIN3TX        (PORT_ALT2_FUNC_MODE)
#define    PORT168_EMIOS2_E2UC_13_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT168_EMIOS1_E1UC_7_H_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT168_EMIOS1_E1UC_7_H_IN        (PORT_INPUT1_MODE)
#define    PORT168_EMIOS2_E2UC_13_Y_IN        (PORT_INPUT2_MODE)
#define    PORT168_EMIOS2_E2UC_13_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT168_EMIOS1_E1UC_7_H_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT169_GPIO        (PORT_GPIO_MODE)
#define    PORT169_EMIOS1_E1UC_29_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT169_EMIOS1_E1UC_29_Y_IN        (PORT_INPUT1_MODE)
#define    PORT169_LIN_15_LIN15RX        (PORT_INPUT2_MODE)
#define    PORT169_SPI_0_SIN_0        (PORT_INPUT3_MODE)
#define    PORT169_EMIOS1_E1UC_29_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT170_GPIO        (PORT_GPIO_MODE)
#define    PORT170_SPI_0_SOUT_0        (PORT_ALT1_FUNC_MODE)
#define    PORT170_EMIOS1_E1UC_30_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT170_LIN_15_LIN15TX        (PORT_ALT3_FUNC_MODE)
#define    PORT170_EMIOS1_E1UC_30_Y_IN        (PORT_INPUT1_MODE)
#define    PORT170_EMIOS1_E1UC_30_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT171_GPIO        (PORT_GPIO_MODE)
#define    PORT171_SPI_0_SCLK_0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT171_EMIOS1_E1UC_31_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT171_LIN_14_LIN14TX        (PORT_ALT3_FUNC_MODE)
#define    PORT171_EMIOS1_E1UC_31_Y_IN        (PORT_INPUT1_MODE)
#define    PORT171_SPI_0_SCLK_0_IN        (PORT_INPUT2_MODE)
#define    PORT171_SPI_0_SCLK_0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT171_EMIOS1_E1UC_31_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT172_GPIO        (PORT_GPIO_MODE)
#define    PORT172_SPI_0_CS0_0        (PORT_ALT1_FUNC_MODE)
#define    PORT172_EMIOS0_E0UC_0_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT172_EMIOS0_E0UC_0_X_IN        (PORT_INPUT1_MODE)
#define    PORT172_LIN_14_LIN14RX        (PORT_INPUT2_MODE)
#define    PORT172_SPI_0_SS_0        (PORT_INPUT3_MODE)
#define    PORT172_EMIOS0_E0UC_0_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT173_GPIO        (PORT_GPIO_MODE)
#define    PORT173_SPI_2_CS3_2        (PORT_ALT1_FUNC_MODE)
#define    PORT173_SPI_3_CS2_3        (PORT_ALT2_FUNC_MODE)
#define    PORT173_SPI_1_SCLK_1_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT173_EMIOS0_E0UC_1_G_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT173_EMIOS0_E0UC_1_G_IN        (PORT_INPUT1_MODE)
#define    PORT173_FlexCAN_3_RX        (PORT_INPUT2_MODE)
#define    PORT173_SPI_1_SCLK_1_IN        (PORT_INPUT3_MODE)
#define    PORT173_SPI_1_SCLK_1_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT173_EMIOS0_E0UC_1_G_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT174_GPIO        (PORT_GPIO_MODE)
#define    PORT174_FlexCAN_3_TX        (PORT_ALT1_FUNC_MODE)
#define    PORT174_SPI_3_CS3_3        (PORT_ALT2_FUNC_MODE)
#define    PORT174_SPI_1_CS0_1        (PORT_ALT3_FUNC_MODE)
#define    PORT174_EMIOS0_E0UC_2_G_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT174_EMIOS0_E0UC_2_G_IN        (PORT_INPUT1_MODE)
#define    PORT174_SPI_1_SS_1        (PORT_INPUT2_MODE)
#define    PORT174_EMIOS0_E0UC_2_G_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT175_GPIO        (PORT_GPIO_MODE)
#define    PORT175_SPI_0_CS2_0        (PORT_ALT1_FUNC_MODE)
#define    PORT175_EMIOS0_E0UC_3_G_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT175_LIN_13_LIN13TX        (PORT_ALT3_FUNC_MODE)
#define    PORT175_EMIOS0_E0UC_3_G_IN        (PORT_INPUT1_MODE)
#define    PORT175_SPI_1_SIN_1        (PORT_INPUT2_MODE)
#define    PORT175_SPI_3_SIN_3        (PORT_INPUT3_MODE)
#define    PORT175_EMIOS0_E0UC_3_G_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT176_GPIO        (PORT_GPIO_MODE)
#define    PORT176_SPI_1_SOUT_1        (PORT_ALT1_FUNC_MODE)
#define    PORT176_SPI_3_SOUT_3        (PORT_ALT2_FUNC_MODE)
#define    PORT176_SPI_0_CS3_0        (PORT_ALT3_FUNC_MODE)
#define    PORT176_EMIOS0_E0UC_4_G_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT176_EMIOS0_E0UC_4_G_IN        (PORT_INPUT1_MODE)
#define    PORT176_LIN_13_LIN13RX        (PORT_INPUT2_MODE)
#define    PORT176_EMIOS0_E0UC_4_G_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT177_GPIO        (PORT_GPIO_MODE)
#define    PORT177_SAI0_SAI0_D0_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT177_ADC_0_ADC0_S_47        (PORT_ANALOG_INPUT_MODE)
#define    PORT177_SAI0_SAI0_D0_IN        (PORT_INPUT1_MODE)
#define    PORT177_SAI0_SAI0_D0_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT195_GPIO        (PORT_GPIO_MODE)
#define    PORT195_SAI0_SAI0_D1_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT195_ENET0_ENET0_TMR2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT195_ADC_0_ADC0_S_46        (PORT_ANALOG_INPUT_MODE)
#define    PORT195_SAI0_SAI0_D1_IN        (PORT_INPUT1_MODE)
#define    PORT195_ENET0_ENET0_TMR2_IN        (PORT_INPUT2_MODE)
#define    PORT195_SAI0_SAI0_D1_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT195_ENET0_ENET0_TMR2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT196_GPIO        (PORT_GPIO_MODE)
#define    PORT196_SAI0_SAI0_D2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT196_ENET1_ENET1_TMR2_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT196_ADC_0_ADC0_S_45        (PORT_ANALOG_INPUT_MODE)
#define    PORT196_SAI0_SAI0_D2_IN        (PORT_INPUT1_MODE)
#define    PORT196_ENET1_ENET1_TMR2_IN        (PORT_INPUT2_MODE)
#define    PORT196_SAI0_SAI0_D2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT196_ENET1_ENET1_TMR2_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT197_GPIO        (PORT_GPIO_MODE)
#define    PORT197_SAI0_SAI0_D3_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT197_DCI_TCK_ALT        (PORT_ALT2_FUNC_MODE)
#define    PORT197_ADC_0_ADC0_S_44        (PORT_ANALOG_INPUT_MODE)
#define    PORT197_SAI0_SAI0_D3_IN        (PORT_INPUT1_MODE)
#define    PORT197_SAI0_SAI0_D3_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT206_GPIO        (PORT_GPIO_MODE)
#define    PORT206_SAI0_SAI0_MCLK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT206_DCI_TMS_ALT_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT206_DCI_TMS_ALT_IN        (PORT_ONLY_INPUT_MODE)
#define    PORT206_DCI_TMS_ALT_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT206_ADC_1_ADC1_S_15        (PORT_ANALOG_INPUT_MODE)
#define    PORT206_SAI0_SAI0_MCLK_IN        (PORT_INPUT1_MODE)
#define    PORT206_SAI0_SAI0_MCLK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT224_GPIO        (PORT_GPIO_MODE)
#define    PORT224_EMIOS2_E2UC_20_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT224_IIC_0_SDA0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT224_LIN_12_LIN12TX        (PORT_ALT3_FUNC_MODE)
#define    PORT224_EMIOS2_E2UC_20_Y_IN        (PORT_INPUT1_MODE)
#define    PORT224_IIC_0_SDA0_IN        (PORT_INPUT2_MODE)
#define    PORT224_EMIOS2_E2UC_20_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT224_IIC_0_SDA0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT225_GPIO        (PORT_GPIO_MODE)
#define    PORT225_EMIOS2_E2UC_19_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT225_IIC_0_SCL0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT225_EMIOS2_E2UC_19_Y_IN        (PORT_INPUT1_MODE)
#define    PORT225_LIN_12_LIN12RX        (PORT_INPUT2_MODE)
#define    PORT225_IIC_0_SCL0_IN        (PORT_INPUT3_MODE)
#define    PORT225_EMIOS2_E2UC_19_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT225_IIC_0_SCL0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT252_GPIO        (PORT_GPIO_MODE)
#define    PORT252_SPI_2_CS0_2        (PORT_ALT1_FUNC_MODE)
#define    PORT252_DSPI_0_dCS4        (PORT_ALT2_FUNC_MODE)
#define    PORT252_EMIOS1_E1UC_24_X_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT252_USB0_ULPI0_D3_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT252_LIN_16_LIN16TX        (PORT_ALT5_FUNC_MODE)
#define    PORT252_EMIOS1_E1UC_24_X_IN        (PORT_INPUT1_MODE)
#define    PORT252_USB0_ULPI0_D3_IN        (PORT_INPUT2_MODE)
#define    PORT252_SPI_2_SS_2        (PORT_INPUT3_MODE)
#define    PORT252_EMIOS1_E1UC_24_X_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT252_USB0_ULPI0_D3_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT253_GPIO        (PORT_GPIO_MODE)
#define    PORT253_SPI_2_SOUT_2        (PORT_ALT1_FUNC_MODE)
#define    PORT253_EMIOS1_E1UC_23_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT253_USB0_ULPI0_D2_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT253_EMIOS1_E1UC_23_X_IN        (PORT_INPUT1_MODE)
#define    PORT253_LIN_17_LIN17RX        (PORT_INPUT2_MODE)
#define    PORT253_USB0_ULPI0_D2_IN        (PORT_INPUT3_MODE)
#define    PORT253_EMIOS1_E1UC_23_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT253_USB0_ULPI0_D2_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT254_GPIO        (PORT_GPIO_MODE)
#define    PORT254_SPI_2_SCLK_2_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT254_EMIOS1_E1UC_22_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT254_USB0_ULPI0_D1_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT254_LIN_17_LIN17TX        (PORT_ALT4_FUNC_MODE)
#define    PORT254_EMIOS1_E1UC_22_X_IN        (PORT_INPUT1_MODE)
#define    PORT254_USB0_ULPI0_D1_IN        (PORT_INPUT2_MODE)
#define    PORT254_SPI_2_SCLK_2_IN        (PORT_INPUT3_MODE)
#define    PORT254_SPI_2_SCLK_2_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT254_EMIOS1_E1UC_22_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT254_USB0_ULPI0_D1_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT255_GPIO        (PORT_GPIO_MODE)
#define    PORT255_EMIOS1_E1UC_21_Y_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT255_USB0_ULPI0_D0_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT255_EMIOS1_E1UC_21_Y_IN        (PORT_INPUT1_MODE)
#define    PORT255_USB0_ULPI0_D0_IN        (PORT_INPUT2_MODE)
#define    PORT255_SPI_2_SIN_2        (PORT_INPUT3_MODE)
#define    PORT255_EMIOS1_E1UC_21_Y_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT255_USB0_ULPI0_D0_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT256_GPIO        (PORT_GPIO_MODE)
#define    PORT256_DSPI_0_dCS1        (PORT_ALT1_FUNC_MODE)
#define    PORT256_EMIOS2_E2UC_25_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT256_USB0_ULPI0_STP        (PORT_ALT3_FUNC_MODE)
#define    PORT256_EMIOS2_E2UC_25_Y_IN        (PORT_INPUT1_MODE)
#define    PORT256_EMIOS2_E2UC_25_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT257_GPIO        (PORT_GPIO_MODE)
#define    PORT257_DSPI_0_dCS0        (PORT_ALT1_FUNC_MODE)
#define    PORT257_EMIOS2_E2UC_24_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT257_EMIOS2_E2UC_24_X_IN        (PORT_INPUT1_MODE)
#define    PORT257_USB0_ULPI0_CLK        (PORT_INPUT2_MODE)
#define    PORT257_DSPI_0_dSS        (PORT_INPUT3_MODE)
#define    PORT257_EMIOS2_E2UC_24_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT258_GPIO        (PORT_GPIO_MODE)
#define    PORT258_DSPI_0_dSCLK_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT258_EMIOS2_E2UC_23_X_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT258_EMIOS2_E2UC_23_X_IN        (PORT_INPUT1_MODE)
#define    PORT258_USB0_ULPI0_DIR        (PORT_INPUT2_MODE)
#define    PORT258_DSPI_0_dSCLK_IN        (PORT_INPUT3_MODE)
#define    PORT258_DSPI_0_dSCLK_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT258_EMIOS2_E2UC_23_X_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT259_GPIO        (PORT_GPIO_MODE)
#define    PORT259_EMIOS2_E2UC_22_X_OUT        (PORT_ALT1_FUNC_MODE)
#define    PORT259_EMIOS2_E2UC_22_X_IN        (PORT_INPUT1_MODE)
#define    PORT259_USB0_ULPI0_NXT        (PORT_INPUT2_MODE)
#define    PORT259_DSPI_0_dSIN        (PORT_INPUT3_MODE)
#define    PORT259_EMIOS2_E2UC_22_X_IN_OUT        (PORT_INOUT1_MODE)
#define    PORT260_GPIO        (PORT_GPIO_MODE)
#define    PORT260_DSPI_0_dSOUT        (PORT_ALT1_FUNC_MODE)
#define    PORT260_EMIOS1_E1UC_28_Y_OUT        (PORT_ALT2_FUNC_MODE)
#define    PORT260_USB0_ULPI0_D7_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT260_EMIOS1_E1UC_28_Y_IN        (PORT_INPUT1_MODE)
#define    PORT260_USB0_ULPI0_D7_IN        (PORT_INPUT2_MODE)
#define    PORT260_EMIOS1_E1UC_28_Y_IN_OUT        (PORT_INOUT2_MODE)
#define    PORT260_USB0_ULPI0_D7_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT261_GPIO        (PORT_GPIO_MODE)
#define    PORT261_SPI_2_CS3_2        (PORT_ALT1_FUNC_MODE)
#define    PORT261_DSPI_0_dCS3        (PORT_ALT2_FUNC_MODE)
#define    PORT261_EMIOS1_E1UC_27_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT261_USB0_ULPI0_D6_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT261_EMIOS1_E1UC_27_Y_IN        (PORT_INPUT1_MODE)
#define    PORT261_USB0_ULPI0_D6_IN        (PORT_INPUT2_MODE)
#define    PORT261_EMIOS1_E1UC_27_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT261_USB0_ULPI0_D6_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT262_GPIO        (PORT_GPIO_MODE)
#define    PORT262_SPI_2_CS2_2        (PORT_ALT1_FUNC_MODE)
#define    PORT262_DSPI_0_dCS2        (PORT_ALT2_FUNC_MODE)
#define    PORT262_EMIOS1_E1UC_26_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT262_USB0_ULPI0_D5_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT262_EMIOS1_E1UC_26_Y_IN        (PORT_INPUT1_MODE)
#define    PORT262_USB0_ULPI0_D5_IN        (PORT_INPUT2_MODE)
#define    PORT262_EMIOS1_E1UC_26_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT262_USB0_ULPI0_D5_IN_OUT        (PORT_INOUT4_MODE)
#define    PORT263_GPIO        (PORT_GPIO_MODE)
#define    PORT263_SPI_2_CS1_2        (PORT_ALT1_FUNC_MODE)
#define    PORT263_DSPI_0_dCS5        (PORT_ALT2_FUNC_MODE)
#define    PORT263_EMIOS1_E1UC_25_Y_OUT        (PORT_ALT3_FUNC_MODE)
#define    PORT263_USB0_ULPI0_D4_OUT        (PORT_ALT4_FUNC_MODE)
#define    PORT263_EMIOS1_E1UC_25_Y_IN        (PORT_INPUT1_MODE)
#define    PORT263_LIN_16_LIN16RX        (PORT_INPUT2_MODE)
#define    PORT263_USB0_ULPI0_D4_IN        (PORT_INPUT3_MODE)
#define    PORT263_EMIOS1_E1UC_25_Y_IN_OUT        (PORT_INOUT3_MODE)
#define    PORT263_USB0_ULPI0_D4_IN_OUT        (PORT_INOUT4_MODE)


/**
* @brief Enable/Disable Development Error Detection
*
* @implements   PORT_DEV_ERROR_DETECT_define
*/
#define PORT_DEV_ERROR_DETECT           (STD_OFF)

/**
* @brief Use/remove Port_SetPinDirection function from the compiled driver
*
* @implements   PORT_SET_PIN_DIRECTION_API_define
*/
#define PORT_SET_PIN_DIRECTION_API      (STD_ON)


/**
* @brief Use/remove Port_SetPinMode function from the compiled driver
*
* @implements   PORT_SET_PIN_MODE_API_define
*/
#define PORT_SET_PIN_MODE_API           (STD_ON)


/**
* @brief Enable/Disable Port_SetPinMode function updating the output level of the pins configured at runtime as GPIO
*/
#define PORT_SETPINMODE_DOES_NOT_TOUCH_GPIO_LEVEL           (STD_OFF)

/**
* @brief Support for User mode.
*        If this parameter has been configured to 'STD_ON', the Port driver code can be executed from both supervisor and user mode.
*
*/
#define PORT_ENABLE_USER_MODE_SUPPORT   (STD_OFF)


/**
* @brief Use/remove Port_GetVersionInfo function from the compiled driver
*
* @implements   PORT_VERSION_INFO_API_define
*/
#define PORT_VERSION_INFO_API           (STD_ON)

/**
* @brief Port Pin symbolic names
* @details Get All Symbolic Names from configuration tool
*
*
*/
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_PortContainer_0_PortPin_LED1  0
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_PortContainer_0_PortPin_LED2  1
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_PortContainer_0_PortPin_Key1  2
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_PortContainer_0_PortPin_Key2  3
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_PortContainer_0_DCI_TCK  4
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_PortContainer_0_DCI_TDI  5
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_PortContainer_0_DCI_TDO  6
/**
* @violates @ref PORT_CFG_H_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to
*  ensure that 31 character significance and case sensitivity are supported for external ids
*/
#define PortConfigSet_PortContainer_0_DCI_TMS  7


/**
* @brief Number of INMUX registers
* @details Platform constant
*/
#define PORT_NMBR_INMUX_REGS_U16    ((uint16)509)
/**
* @brief Number of available pad modes options
* @details Platform constant
*/
#define PAD_MODE_OPTIONS_U8         ((uint8)24)
/**
* @brief Number of pad 16 blocks
* @details Platform constant
*/
#define PAD_16BLOCK_NO_U8           ((uint8)17)
/**
 * @brief The last supported pin number
 */
#define PORT_MAX_PIN_PACKAGE_U16    ((uint16)263)

/**
* @brief The maximum number of configured pins
*/
#define PORT_MAX_CONFIGURED_PADS_U16   ((uint16)8)

/**
 * @brief Number of UnUsed pin array
*/
#define PORT_MAX_UNUSED_PADS_U16   (256U)


/**
* @brief Port driver Post-build configuration switch
*/
#define PORT_PRECOMPILE_SUPPORT     (STD_OFF)


#if (STD_ON == PORT_SET_PIN_MODE_API)
#define  PORT_INOUT_TABLE_NUM_ENTRIES_U16       ((uint16)327)
#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */
/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/

/**
* @brief   Structure needed by @p Port_Init().
* @details The structure @p Port_ConfigType is a type for the external data
*          structure containing the initialization data for the PORT Driver.
* @note    The user must use the symbolic names defined in the configuration
*          tool.
*
* @implements Port_ConfigType_struct
*
* @api
*/
typedef struct
{
    VAR(uint16, AUTOMATIC) u16NumPins;                                                     /**< @brief Number of used pads (to be configured) */
    VAR(uint16, AUTOMATIC) u16NumUnusedPins;                                               /**< @brief Number of unused pads */
    P2CONST(uint16, AUTOMATIC, PORT_APPL_CONST) au16UnusedPads;                            /**< @brief Unused pad id's array */
    P2CONST(Port_Siul2_UnUsedPinConfigType, AUTOMATIC, PORT_APPL_CONST) pUnusedPadConfig;  /**< @brief Unused pad configuration */
    P2CONST(Port_Siul2_PinConfigType, AUTOMATIC, PORT_APPL_CONST) pUsedPadConfig;          /**< @brief Used pads data configuration */
    P2CONST(Port_Siul2_PadSelConfigType, AUTOMATIC, PORT_APPL_CONST) pPadSelConfig;        /**< @brief Used pads INMUX configuration */
} Port_ConfigType;

/**
* @brief Settings for a INMUX register
* @details The structure @p Port_InMuxSettingType manages ExtraFunctions PinMode.
*
* @api
*/
typedef struct
{
    VAR(uint16,AUTOMATIC) u16InMuxId;   /**< @brief The id of the INMUX register to be configured */
    VAR(uint8, AUTOMATIC) u8InMuxCode;  /**< @brief The value of the INMUX reg for signal allocation */
} Port_InMuxSettingType;

/**
* @brief Settings for a INOUT functionality
* @details The structure @p Port_InoutSettingType manages Inout PinModes.
* 
* @api
*/
typedef struct
{
    VAR(uint16,AUTOMATIC) u16MSCR;      /**< @brief The id of the MSCR register to be configured */
    VAR(uint8,AUTOMATIC)  u8Mode;       /**< @brief The mode to be configured */
    VAR(uint16,AUTOMATIC) u16InMuxId;   /**< @brief The id of the INMUX register to be configured */
    VAR(uint8, AUTOMATIC) u8InMuxCode;  /**< @brief The value of the INMUX reg for signal allocation */
} Port_InoutSettingType;
/*=================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/
#if (STD_ON == PORT_SET_PIN_MODE_API)

#define PORT_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

/**
* @brief External declaration of the Port inout functionality settings array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(Port_InoutSettingType,PORT_CONST) Port_aPadFunctInoutMuxSettings[PORT_INOUT_TABLE_NUM_ENTRIES_U16];

/**
* @brief External declaration of the Port pad inmux functionality settings array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(Port_InMuxSettingType,PORT_CONST) Port_aPadFunctInMuxSettings[504];

#define PORT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

#define PORT_START_SEC_CONFIG_DATA_16
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

/**
* @brief External declaration of the Port pin description array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(uint16, PORT_CONST) Port_au16PinDescription[24][17];

/**
* @brief External declaration of the Port pad inmux functionality settings index array
*
* @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope if they are only accessed
* from within a single function.
*/
extern CONST(uint16,PORT_CONST) Port_au16PadFunctInMuxIndex[264];

#define PORT_STOP_SEC_CONFIG_DATA_16
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

#endif /* (STD_ON == PORT_SET_PIN_MODE_API) */


#define PORT_START_SEC_CONST_UNSPECIFIED
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"


/** @violates @ref PORT_CFG_H_REF_4 Objects shall be defined at block scope */
extern CONST(Port_ConfigType, PORT_CONST) PortConfigSet;


#define PORT_STOP_SEC_CONST_UNSPECIFIED
/**
* @violates @ref PORT_CFG_H_REF_2 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Port_MemMap.h"

/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* PORT_CFG_H */

/** @} */

/* End of File */
