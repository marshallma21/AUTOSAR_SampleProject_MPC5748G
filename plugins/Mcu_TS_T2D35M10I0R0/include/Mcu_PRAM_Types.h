/**
*   @file    Mcu_PRAM_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Exported data outside of the Mcu from PRAM.
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


#ifndef MCU_PRAM_TYPES_H
#define MCU_PRAM_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_PRAM_Types_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
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
#include "Reg_eSys_PRAM.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_PRAM_TYPES_VENDOR_ID                    43
#define MCU_PRAM_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define MCU_PRAM_TYPES_AR_RELEASE_MINOR_VERSION     2
#define MCU_PRAM_TYPES_AR_RELEASE_REVISION_VERSION  2
#define MCU_PRAM_TYPES_SW_MAJOR_VERSION             1
#define MCU_PRAM_TYPES_SW_MINOR_VERSION             0
#define MCU_PRAM_TYPES_SW_PATCH_VERSION             0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and Mcu_Cfg header file are from the same vendor */
#if (MCU_PRAM_TYPES_VENDOR_ID != MCU_CFG_VENDOR_ID)
    #error "Mcu_PRAM_Types.h and Mcu_Cfg.h have different vendor ids"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Autosar version */
#if ((MCU_PRAM_TYPES_AR_RELEASE_MAJOR_VERSION != MCU_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PRAM_TYPES_AR_RELEASE_MINOR_VERSION != MCU_CFG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PRAM_TYPES_AR_RELEASE_REVISION_VERSION != MCU_CFG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PRAM_Types.h and Mcu_Cfg.h are different"
#endif
/* Check if source file and Mcu_Cfg header file are of the same Software version */
#if ((MCU_PRAM_TYPES_SW_MAJOR_VERSION != MCU_CFG_SW_MAJOR_VERSION) || \
     (MCU_PRAM_TYPES_SW_MINOR_VERSION != MCU_CFG_SW_MINOR_VERSION) || \
     (MCU_PRAM_TYPES_SW_PATCH_VERSION != MCU_CFG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PRAM_Types.h and Mcu_Cfg.h are different"
#endif

/* Check if source file and Reg_eSys_PRAM header file are from the same vendor */
#if (MCU_PRAM_TYPES_VENDOR_ID != REG_ESYS_PRAM_VENDOR_ID)
    #error "Mcu_PRAM_Types.h and Reg_eSys_PRAM.h have different vendor ids"
#endif
/* Check if source file and Reg_eSys_PRAM header file are of the same Autosar version */
#if ((MCU_PRAM_TYPES_AR_RELEASE_MAJOR_VERSION != REG_ESYS_PRAM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PRAM_TYPES_AR_RELEASE_MINOR_VERSION != REG_ESYS_PRAM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PRAM_TYPES_AR_RELEASE_REVISION_VERSION != REG_ESYS_PRAM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PRAM_Types.h and Reg_eSys_PRAM.h are different"
#endif
/* Check if source file and Reg_eSys_PRAM header file are of the same Software version */
#if ((MCU_PRAM_TYPES_SW_MAJOR_VERSION != REG_ESYS_PRAM_SW_MAJOR_VERSION) || \
     (MCU_PRAM_TYPES_SW_MINOR_VERSION != REG_ESYS_PRAM_SW_MINOR_VERSION) || \
     (MCU_PRAM_TYPES_SW_PATCH_VERSION != REG_ESYS_PRAM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PRAM_Types.h and Reg_eSys_PRAM.h are different"
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
#define PRAMC_PRCR1_VALUE_U32(value)        ((uint32)(((value) & PRAMC_PRCR1_RWBITS_MASK32)|PRAMC_PRCR1_RESBITS_MASK32))

#if (IPV_MC == IPV_MC_04_00_15_02)
    #define PRAMC_PRCR1_P0_BO_DIS_U32           (PRAMC_PRCR1_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR1_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR1_FT_DIS_U32              (PRAMC_PRCR1_FT_DIS_MASK32)
    #define PRAMC_PRCR1_FT_ENA_U32              ((uint32)0x00000000U)
#endif

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07) \
    )

    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR1_PRI_VALUE_U32(value)    ((uint32)(((value)<< (uint32)8U) & PRAMC_PRCR1_PRI_MASK32))

    #define PRAMC_PRCR1_P1_BO_DIS_U32           (PRAMC_PRCR1_P1_BO_DIS_MASK32)
    #define PRAMC_PRCR1_P1_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR1_P0_BO_DIS_U32           (PRAMC_PRCR1_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR1_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR1_FT_DIS_U32              (PRAMC_PRCR1_FT_DIS_MASK32)
    #define PRAMC_PRCR1_FT_ENA_U32              ((uint32)0x00000000U)
#endif

#if (IPV_MC == IPV_MC_04_03_00_00)
    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR1_PRI_VALUE_U32(value)    ((uint32)(((value)<< (uint32)8U) & PRAMC_PRCR1_PRI_MASK32))
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))

/*********************************************************/
/********************* PRCR1 *****************************/
/*********************************************************/
    #define PRAMC_PRCR1_P0_BO_DIS_U32           (PRAMC_PRCR1_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR1_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR1_P0_RB_DIS_U32           (PRAMC_PRCR1_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR1_P0_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR1_FT_DIS_U32              (PRAMC_PRCR1_FT_DIS_MASK32)
    #define PRAMC_PRCR1_FT_ENA_U32              ((uint32)0x00000000U)
#endif


#if (IPV_MC == IPV_MC_04_06_05_00)
/*********************************************************/
/********************* PRCR2 *****************************/
/*********************************************************/
    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR2_VALUE_U32(value)        ((uint32)(((value) & PRAMC_PRCR2_RWBITS_MASK32)|PRAMC_PRCR2_RESBITS_MASK32))

    #define PRAMC_PRCR2_P0_BO_DIS_U32           (PRAMC_PRCR2_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR2_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR2_P0_RB_DIS_U32           (PRAMC_PRCR2_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR2_P0_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR2_FT_DIS_U32              (PRAMC_PRCR2_FT_DIS_MASK32)
    #define PRAMC_PRCR2_FT_ENA_U32              ((uint32)0x00000000U)


/*********************************************************/
/********************* PRCR3 *****************************/
/*********************************************************/
    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR3_VALUE_U32(value)        ((uint32)(((value) & PRAMC_PRCR3_RWBITS_MASK32)|PRAMC_PRCR3_RESBITS_MASK32))

    #define PRAMC_PRCR3_P0_BO_DIS_U32           (PRAMC_PRCR3_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR3_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR3_P0_RB_DIS_U32           (PRAMC_PRCR3_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR3_P0_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR3_FT_DIS_U32              (PRAMC_PRCR3_FT_DIS_MASK32)
    #define PRAMC_PRCR3_FT_ENA_U32              ((uint32)0x00000000U)


/*********************************************************/
/********************* PRCR4 *****************************/
/*********************************************************/
    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR4_VALUE_U32(value)        ((uint32)(((value) & PRAMC_PRCR4_RWBITS_MASK32)|PRAMC_PRCR4_RESBITS_MASK32))

    #define PRAMC_PRCR4_P0_BO_DIS_U32           (PRAMC_PRCR4_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR4_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR4_P0_RB_DIS_U32           (PRAMC_PRCR4_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR4_P0_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR4_FT_DIS_U32              (PRAMC_PRCR4_FT_DIS_MASK32)
    #define PRAMC_PRCR4_FT_ENA_U32              ((uint32)0x00000000U)


/*********************************************************/
/********************* PRCR5 *****************************/
/*********************************************************/
    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR5_VALUE_U32(value)        ((uint32)(((value) & PRAMC_PRCR5_RWBITS_MASK32)|PRAMC_PRCR5_RESBITS_MASK32))

    #define PRAMC_PRCR5_P0_BO_DIS_U32           (PRAMC_PRCR5_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR5_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR5_P0_RB_DIS_U32           (PRAMC_PRCR5_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR5_P0_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR5_FT_DIS_U32              (PRAMC_PRCR5_FT_DIS_MASK32)
    #define PRAMC_PRCR5_FT_ENA_U32              ((uint32)0x00000000U)


/*********************************************************/
/********************* PRCR6 *****************************/
/*********************************************************/
    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR6_VALUE_U32(value)        ((uint32)(((value) & PRAMC_PRCR6_RWBITS_MASK32)|PRAMC_PRCR6_RESBITS_MASK32))

    #define PRAMC_PRCR6_P0_BO_DIS_U32           (PRAMC_PRCR6_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR6_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR6_P0_RB_DIS_U32           (PRAMC_PRCR6_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR6_P0_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR6_FT_DIS_U32              (PRAMC_PRCR6_FT_DIS_MASK32)
    #define PRAMC_PRCR6_FT_ENA_U32              ((uint32)0x00000000U)


/*********************************************************/
/********************* PRCR7 *****************************/
/*********************************************************/
    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR7_VALUE_U32(value)        ((uint32)(((value) & PRAMC_PRCR7_RWBITS_MASK32)|PRAMC_PRCR7_RESBITS_MASK32))

    #define PRAMC_PRCR7_P0_BO_DIS_U32           (PRAMC_PRCR7_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR7_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR7_P0_RB_DIS_U32           (PRAMC_PRCR7_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR7_P0_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR7_FT_DIS_U32              (PRAMC_PRCR7_FT_DIS_MASK32)
    #define PRAMC_PRCR7_FT_ENA_U32              ((uint32)0x00000000U)


/*********************************************************/
/********************* PRCR8 *****************************/
/*********************************************************/
    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR8_VALUE_U32(value)        ((uint32)(((value) & PRAMC_PRCR8_RWBITS_MASK32)|PRAMC_PRCR8_RESBITS_MASK32))

    /** @violates @ref Mcu_PRAM_Types_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function like macro. */
    #define PRAMC_PRCR8_PRI_U32(value)          ((uint32)(((value)<<(uint32)8U) & PRAMC_PRCR8_PRI_MASK32))

    #define PRAMC_PRCR8_P1_BO_DIS_U32           (PRAMC_PRCR8_P1_BO_DIS_MASK32)
    #define PRAMC_PRCR8_P1_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR8_P0_BO_DIS_U32           (PRAMC_PRCR8_P0_BO_DIS_MASK32)
    #define PRAMC_PRCR8_P0_BO_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR8_P1_RB_DIS_U32           (PRAMC_PRCR8_P1_RB_DIS_MASK32)
    #define PRAMC_PRCR8_P1_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR8_P0_RB_DIS_U32           (PRAMC_PRCR8_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR8_P0_RB_ENA_U32           ((uint32)0x00000000U)

    #define PRAMC_PRCR8_FT_DIS_U32              (PRAMC_PRCR8_FT_DIS_MASK32)
    #define PRAMC_PRCR8_FT_ENA_U32              ((uint32)0x00000000U)
#endif

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* Port p1 read buffer disable. */
    #define PRAMC_PRCR1_P1_RB_DIS_U32           (PRAMC_PRCR1_P1_RB_DIS_MASK32)
    #define PRAMC_PRCR1_P1_RB_ENA_U32           ((uint32)0x00000000U)
    /* Port p0 read buffer disable. */
    #define PRAMC_PRCR1_P0_RB_DIS_U32           (PRAMC_PRCR1_P0_RB_DIS_MASK32)
    #define PRAMC_PRCR1_P0_RB_ENA_U32           ((uint32)0x00000000U)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            Timing configuration for PRAM hw IP.
* @details          Set the wait states (0 or 1) for the platform RAM controller.
*                   PRAM_1 is available only in Decoupled Mode.
*/
typedef struct
{
#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) ||\
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_05_00_00_10) \
    )
    VAR( uint32, MCU_VAR) u32RamWS;   /**< @brief PRAM configuration settings for PRCR1[RD1WS]. */
#elif (IPV_MC == IPV_MC_04_06_05_00)
    VAR( uint32, MCU_VAR) u32PramcPrcr1;   /**< @brief PRAM configuration settings for PRCR1. */
    VAR( uint32, MCU_VAR) u32PramcPrcr2;   /**< @brief PRAM configuration settings for PRCR2. */
    VAR( uint32, MCU_VAR) u32PramcPrcr3;   /**< @brief PRAM configuration settings for PRCR3. */
    VAR( uint32, MCU_VAR) u32PramcPrcr4;   /**< @brief PRAM configuration settings for PRCR4. */
    VAR( uint32, MCU_VAR) u32PramcPrcr5;   /**< @brief PRAM configuration settings for PRCR5. */
    VAR( uint32, MCU_VAR) u32PramcPrcr6;   /**< @brief PRAM configuration settings for PRCR6. */
    VAR( uint32, MCU_VAR) u32PramcPrcr7;   /**< @brief PRAM configuration settings for PRCR7. */
    VAR( uint32, MCU_VAR) u32PramcPrcr8;   /**< @brief PRAM configuration settings for PRCR8. */
#elif (IPV_MC == IPV_MC_05_00_00_07)
    VAR( uint32, MCU_VAR) u32Pramc0Prcr1;   /**< @brief PRAM0 configuration settings for PRCR1. */
    VAR( uint32, MCU_VAR) u32Pramc1Prcr1;   /**< @brief PRAM1 configuration settings for PRCR1. */
#if (MCU_PRAM_MULTIPLE_PRAM == STD_ON)    
    VAR( uint32, MCU_VAR) u32Pramc2Prcr1;   /**< @brief PRAM2 configuration settings for PRCR1. */
#endif
#elif (IPV_MC == IPV_MC_04_00_15_02)
    VAR( uint32, MCU_VAR) u32Pramc0Prcr1;   /**< @brief PRAMC_0 configuration settings for PRCR1. */
    VAR( uint32, MCU_VAR) u32Pramc1Prcr1;   /**< @brief PRAMC_1 configuration settings for PRCR1. */
#endif /* IPV_MC == IPV_MC_04_03_00_00 */
} Mcu_PRAM_ClockConfigType;
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCU_PRAM_TYPES_H */

/** @} */
