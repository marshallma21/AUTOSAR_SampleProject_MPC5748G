/**
*   @file    Reg_eSys_PRAM.h
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


#ifndef REG_ESYS_PRAM_H
#define REG_ESYS_PRAM_H

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
#include "Mcu_PRAM_IPVersion.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_PRAM_VENDOR_ID                        43
#define REG_ESYS_PRAM_AR_RELEASE_MAJOR_VERSION         4
#define REG_ESYS_PRAM_AR_RELEASE_MINOR_VERSION         2
#define REG_ESYS_PRAM_AR_RELEASE_REVISION_VERSION      2
#define REG_ESYS_PRAM_SW_MAJOR_VERSION                 1
#define REG_ESYS_PRAM_SW_MINOR_VERSION                 0
#define REG_ESYS_PRAM_SW_PATCH_VERSION                 0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_PRAM_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_PRAM_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Reg_eSys_PRAM.h and Reg_eSys.h are different"
    #endif
#endif

/* Check if source file and Mcu_PRAM_IPVersion header file are from the same vendor */
#if (REG_ESYS_PRAM_VENDOR_ID != MCU_PRAM_IPVERSION_VENDOR_ID)
    #error "Reg_eSys_PRAM.h and Mcu_PRAM_IPVersion.h have different vendor ids"
#endif
/* Check if source file and Mcu_PRAM_IPVersion header file are of the same Autosar version */
#if ((REG_ESYS_PRAM_AR_RELEASE_MAJOR_VERSION != MCU_PRAM_IPVERSION_AR_RELEASE_MAJOR_VERSION) || \
     (REG_ESYS_PRAM_AR_RELEASE_MINOR_VERSION != MCU_PRAM_IPVERSION_AR_RELEASE_MINOR_VERSION) || \
     (REG_ESYS_PRAM_AR_RELEASE_REVISION_VERSION != MCU_PRAM_IPVERSION_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Reg_eSys_PRAM.h and Mcu_PRAM_IPVersion.h are different"
#endif
/* Check if source file and Mcu_PRAM_IPVersion header file are of the same Software version */
#if ((REG_ESYS_PRAM_SW_MAJOR_VERSION != MCU_PRAM_IPVERSION_SW_MAJOR_VERSION) || \
     (REG_ESYS_PRAM_SW_MINOR_VERSION != MCU_PRAM_IPVERSION_SW_MINOR_VERSION) || \
     (REG_ESYS_PRAM_SW_PATCH_VERSION != MCU_PRAM_IPVERSION_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Reg_eSys_PRAM.h and Mcu_PRAM_IPVersion.h are different"
#endif

/*==================================================================================================
                                             ENUMS
==================================================================================================*/


/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/* PRCR1: Processor Core Type. */
#if (IPV_MC == IPV_MC_05_00_00_07)
    #define PRAM0_PRCR1_ADDR32                ((uint32)(PRAM0_BASEADDR + (uint32)0x0000UL))
    #define PRAM1_PRCR1_ADDR32                ((uint32)(PRAM1_BASEADDR + (uint32)0x0000UL))
    #define PRAM2_PRCR1_ADDR32                ((uint32)(PRAM2_BASEADDR + (uint32)0x0000UL))
#else
    #define PRCR1_ADDR32                      ((uint32)(PRAM_BASEADDR + (uint32)0x0000UL))
#endif

#if (IPV_MC == IPV_MC_04_00_15_02)
#define PRAMC_0_PRCR1_ADDR32                  ((uint32)(PRAMC_0_BASEADDR + (uint32)0x0000UL))
#define PRAMC_1_PRCR1_ADDR32                  ((uint32)(PRAMC_1_BASEADDR + (uint32)0x0000UL))
#endif

#if (IPV_MC == IPV_MC_04_06_05_00)
    #define PRCR2_ADDR32            ((uint32)(PRAM_BASEADDR + (uint32)0x00004L))
    #define PRCR3_ADDR32            ((uint32)(PRAM_BASEADDR + (uint32)0x00008L))
    #define PRCR4_ADDR32            ((uint32)(PRAM_BASEADDR + (uint32)0x0000CL))
    #define PRCR5_ADDR32            ((uint32)(PRAM_BASEADDR + (uint32)0x00010L))
    #define PRCR6_ADDR32            ((uint32)(PRAM_BASEADDR + (uint32)0x00014L))
    #define PRCR7_ADDR32            ((uint32)(PRAM_BASEADDR + (uint32)0x00018L))
    #define PRCR8_ADDR32            ((uint32)(PRAM_BASEADDR + (uint32)0x0001CL))
#endif /* ( IPV_MC == IPV_MC_04_03_00_00 ) */

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_06_01_00))
    #define PRAMC_PRCR1_RWBITS_MASK32                   ( (uint32)0x000003C1U )
    #define PRAMC_PRCR1_RESBITS_MASK32                  ( (uint32)0x00000000U )
#elif ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define PRAMC_PRCR1_RWBITS_MASK32                   ( (uint32)0x000003F1U )
    #define PRAMC_PRCR1_RESBITS_MASK32                  ( (uint32)0x00000000U )
#elif (IPV_MC == IPV_MC_04_03_00_00)
    #define PRAMC_PRCR1_RWBITS_MASK32                   ( (uint32)0x00000051U )
    #define PRAMC_PRCR1_RESBITS_MASK32                  ( (uint32)0x00000000U )
#elif (IPV_MC == IPV_MC_05_00_00_10)
    #define PRAMC_PRCR1_RWBITS_MASK32                   ( (uint32)0x000003C0U )
    #define PRAMC_PRCR1_RESBITS_MASK32                  ( (uint32)0x00000001U )
#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define PRAMC_PRCR1_RWBITS_MASK32                   ( (uint32)0x000003C1U )
    #define PRAMC_PRCR1_RESBITS_MASK32                  ( (uint32)0x00000000U )
#elif (IPV_MC == IPV_MC_04_00_15_02)
    #define PRAMC_PRCR1_RWBITS_MASK32                   ( (uint32)0x00000041U )
    #define PRAMC_PRCR1_RESBITS_MASK32                  ( (uint32)0x00000100U )
#endif /* ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_06_01_00)) */

#if (IPV_MC == IPV_MC_04_00_15_02)
    #define PRAMC_PRCR1_FT_DIS_MASK32                   ( (uint32)0x00000001U )
    #define PRAMC_PRCR1_P0_BO_DIS_MASK32                ( (uint32)0x00000040U )

#elif ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
       (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
       (IPV_MC == IPV_MC_05_00_00_10) \
      )
    #define PRAMC_PRCR1_PRI_MASK32                      ( (uint32)0x00000300U )
    #define PRAMC_PRCR1_P1_BO_DIS_MASK32                ( (uint32)0x00000080U )
    #define PRAMC_PRCR1_P0_BO_DIS_MASK32                ( (uint32)0x00000040U )
    #define PRAMC_PRCR1_FT_DIS_MASK32                   ( (uint32)0x00000001U )

#elif (IPV_MC == IPV_MC_04_03_00_00)
    #define PRAMC_PRCR1_PRI_MASK32                      ( (uint32)0x00000300U )

#elif (IPV_MC == IPV_MC_04_03_00_00)
    #define PRAMC_PRCR1_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
    #define PRAMC_PRCR1_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
    #define PRAMC_PRCR1_FT_DIS_MASK32                       ((uint32)0x00000001U)

#elif (IPV_MC == IPV_MC_05_00_00_07)
    #define PRAMC_PRCR1_PRI_MASK32                          ((uint32)0x00000300U)
    #define PRAMC_PRCR1_P1_BO_DIS_MASK32                    ((uint32)0x00000080U)
    #define PRAMC_PRCR1_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
    #define PRAMC_PRCR1_FT_DIS_MASK32                       ((uint32)0x00000001U)
#elif (IPV_MC == IPV_MC_04_06_05_00)

/*********************************************************/
/********************* PRCR1_ADDR32 **********************/
/*********************************************************/
#define PRAMC_PRCR1_RWBITS_MASK32                       ((uint32)0x00000051U)
#define PRAMC_PRCR1_RESBITS_MASK32                      ((uint32)0x00000100U)
#define PRAMC_PRCR1_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
#define PRAMC_PRCR1_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
#define PRAMC_PRCR1_FT_DIS_MASK32                       ((uint32)0x00000001U)


/*********************************************************/
/********************* PRCR2_ADDR32 **********************/
/*********************************************************/
#define PRAMC_PRCR2_RWBITS_MASK32                       ((uint32)0x00000051U)
#define PRAMC_PRCR2_RESBITS_MASK32                      ((uint32)0x00000100U)
#define PRAMC_PRCR2_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
#define PRAMC_PRCR2_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
#define PRAMC_PRCR2_FT_DIS_MASK32                       ((uint32)0x00000001U)


/*********************************************************/
/********************* PRCR3_ADDR32 **********************/
/*********************************************************/
#define PRAMC_PRCR3_RWBITS_MASK32                       ((uint32)0x00000051U)
#define PRAMC_PRCR3_RESBITS_MASK32                      ((uint32)0x00000100U)
#define PRAMC_PRCR3_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
#define PRAMC_PRCR3_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
#define PRAMC_PRCR3_FT_DIS_MASK32                       ((uint32)0x00000001U)


/*********************************************************/
/********************* PRCR4_ADDR32 **********************/
/*********************************************************/
#define PRAMC_PRCR4_RWBITS_MASK32                       ((uint32)0x00000051U)
#define PRAMC_PRCR4_RESBITS_MASK32                      ((uint32)0x00000100U)
#define PRAMC_PRCR4_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
#define PRAMC_PRCR4_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
#define PRAMC_PRCR4_FT_DIS_MASK32                       ((uint32)0x00000001U)


/*********************************************************/
/********************* PRCR5_ADDR32 **********************/
/*********************************************************/
#define PRAMC_PRCR5_RWBITS_MASK32                       ((uint32)0x00000051U)
#define PRAMC_PRCR5_RESBITS_MASK32                      ((uint32)0x00000100U)
#define PRAMC_PRCR5_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
#define PRAMC_PRCR5_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
#define PRAMC_PRCR5_FT_DIS_MASK32                       ((uint32)0x00000001U)


/*********************************************************/
/********************* PRCR6_ADDR32 **********************/
/*********************************************************/
#define PRAMC_PRCR6_RWBITS_MASK32                       ((uint32)0x00000051U)
#define PRAMC_PRCR6_RESBITS_MASK32                      ((uint32)0x00000100U)
#define PRAMC_PRCR6_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
#define PRAMC_PRCR6_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
#define PRAMC_PRCR6_FT_DIS_MASK32                       ((uint32)0x00000001U)


/*********************************************************/
/********************* PRCR7_ADDR32 **********************/
/*********************************************************/
#define PRAMC_PRCR7_RWBITS_MASK32                       ((uint32)0x00000051U)
#define PRAMC_PRCR7_RESBITS_MASK32                      ((uint32)0x00000100U)
#define PRAMC_PRCR7_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
#define PRAMC_PRCR7_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
#define PRAMC_PRCR7_FT_DIS_MASK32                       ((uint32)0x00000001U)


/*********************************************************/
/********************* PRCR8_ADDR32 **********************/
/*********************************************************/
#define PRAMC_PRCR8_RWBITS_MASK32                       ((uint32)0x000003F1U)
#define PRAMC_PRCR8_RESBITS_MASK32                      ((uint32)0x00000000U)
#define PRAMC_PRCR8_PRI_MASK32                          ((uint32)0x00000300U)
#define PRAMC_PRCR8_P1_BO_DIS_MASK32                    ((uint32)0x00000080U)
#define PRAMC_PRCR8_P0_BO_DIS_MASK32                    ((uint32)0x00000040U)
#define PRAMC_PRCR8_P1_RB_DIS_MASK32                    ((uint32)0x00000020U)
#define PRAMC_PRCR8_P0_RB_DIS_MASK32                    ((uint32)0x00000010U)
#define PRAMC_PRCR8_FT_DIS_MASK32                       ((uint32)0x00000001U)


#endif /* IPV_MC == IPV_MC_04_03_00_00 */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    #define PRAMC_PRCR1_P1_RB_DIS_MASK32                ( (uint32)0x00000020U )
    #define PRAMC_PRCR1_P0_RB_DIS_MASK32                ( (uint32)0x00000010U )
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_PRAM_H */

/** @} */
