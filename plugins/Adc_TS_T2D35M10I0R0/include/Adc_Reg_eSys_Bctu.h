/**
*   @file    Adc_Reg_eSys_Bctu.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - module register and macro definitions.
*   @details BCTU module registers, and macrodefinitions used to manipulate the module registers.
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

#ifndef ADC_REG_ESYS_BCTU_H
#define ADC_REG_ESYS_BCTU_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Adc_Reg_eSys_Bctu_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Reg_eSys.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_Reg_eSys_Bctu.h
*/
#define BCTU_REG_VENDOR_ID                       43
#define BCTU_REG_AR_RELEASE_MAJOR_VERSION        4
#define BCTU_REG_AR_RELEASE_MINOR_VERSION        2
#define BCTU_REG_AR_RELEASE_REVISION_VERSION     2
#define BCTU_REG_SW_MAJOR_VERSION                1
#define BCTU_REG_SW_MINOR_VERSION                0
#define BCTU_REG_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 /* Check if Std_Types.h file and BCTU register header file are of the same Autosar version */
 #if ((BCTU_REG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
      (BCTU_REG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Reg_eSys_Bctu.h and Std_Types.h are different"
 #endif
 /* Check if source file and Reg_eSys.h are of the same Autosar version */
 #if ((BCTU_REG_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
      (BCTU_REG_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Reg_eSys_Bctu.h and Reg_eSys.h are different"
 #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define BCTU_DMA_TRANSFER_WORD_SIZE  4U

/**
* @brief          Module Configuration Register
*/
#define BCTU_MCR_ADDR32        (BCTU_BASEADDR + (uint32)0x0UL)

/**
* @brief          Module Status Register
*/
#define BCTU_MSR_ADDR32        (BCTU_BASEADDR + (uint32)0x8UL)

/**
* @brief          Trigger x Configuration Register
*/
/** @violates @ref Adc_Reg_eSys_Bctu_h_REF_1 MISRA-C:2004 Rule 19.7: Function-like macro defined */
#define BCTU_TRGCFG_ADDR32(x)  (BCTU_BASEADDR + (uint32)0x18UL + (uint32)((x)<<(uint8)2))

/**
* @brief          Write Protection Register
*/
#define BCTU_WRPROT_ADDR32     (BCTU_BASEADDR + (uint32)0x228UL)

/**
* @brief          Software Trigger Register
*/
/** @violates @ref Adc_Reg_eSys_Bctu_h_REF_1 MISRA-C:2004 Rule 19.7: Function-like macro defined */
#define BCTU_SFTRGR_ADDR32(x)  (BCTU_BASEADDR + (uint32)0x22CUL + (uint32)((x)<<(uint8)2))

/**
* @brief          ADCx Result Data Register
*/
/** @violates @ref Adc_Reg_eSys_Bctu_h_REF_1 MISRA-C:2004 Rule 19.7: Function-like macro defined */
#define BCTU_ADCDR_ADDR32(x)   (BCTU_BASEADDR + (uint32)0x23CUL + (uint32)((x)<<(uint8)2))

/**
* @brief          LIST Size Status Register
*/
#define BCTU_LISTSTAR_ADDR32   (BCTU_BASEADDR + (uint32)0x24CUL)

/**
* @brief          LIST Channel x Address Register
*/
/** @violates @ref Adc_Reg_eSys_Bctu_h_REF_1 MISRA-C:2004 Rule 19.7: Function-like macro defined */
#define BCTU_LISTCHR_ADDR32(x) (BCTU_BASEADDR + (uint32)0x250UL + (uint32)((x)<<(uint8)2))

/**
* @brief          Conversion Configuration x Register
*/
/** @violates @ref Adc_Reg_eSys_Bctu_h_REF_1 MISRA-C:2004 Rule 19.7: Function-like macro defined */
#define BCTU_CCR_ADDR32(x)     (BCTU_BASEADDR + (uint32)0x2D0UL + (uint32)((x)<<(uint8)2))

/**
* @brief          BCTU Module enable
*/
#define BCTU_MDIS_DIS_U32       ((uint32)0x00000000UL)

/**
* @brief          BCTU Module disable
*/
#define BCTU_MDIS_EN_U32        ((uint32)0x40000000UL)

/**
* @brief          BCTU Global trigger enable
*/
#define BCTU_GTRG_EN_U32        ((uint32)0x04000000UL)

/**
* @brief          BCTU Freeze mode enable
*/
#define BCTU_FRZ_EN_U32         ((uint32)0x20000000UL)

/**
* @brief          BCTU Freeze mode disable
*/
#define BCTU_FRZ_DIS_U32        ((uint32)0x00000000UL)

/**
* @brief          BCTU trigger interrupt enable
*/
#define BCTU_TRG_INT_EN_U32     ((uint32)0x00000080UL)

/**
* @brief          BCTU trigger interrupt disable
*/
#define BCTU_TRG_INT_DIS_U32    ((uint32)0x00000000UL)

/**
* @brief          BCTU input trigger enable
*/
#define BCTU_INPUT_TRIG_EN_U32 ((uint32)0x00008000UL)

/**
* @brief          BCTU input trigger enable
*/
#define BCTU_TRIG_FLAG_CLEAR_U32 ((uint32)0x00004000UL)

/**
* @brief          BCTU input trigger flag clean
*/
#define BCTU_TRIG_FLAG_CLEAN_U32 ((uint32)0x80000000UL)

/**
* @brief          BCTU input trigger flag
*/
#define BCTU_TRIG_FLAG_U32      ((uint32)0x00008000UL)

/**
* @brief          BCTU LIST interrupt enable
*/
#define BCTU_LIST_INT_EN_U32    ((uint32)0x00000020UL)

/**
* @brief          BCTU LIST interrupt disable
*/
#define BCTU_LIST_INT_DIS_U32   ((uint32)0x0UL)

/**
* @brief          Enable write to SFTGRG1 register
*/
#define BCTU_WRPROT_DISABLE_PROTECTED_U32   ((uint32)0xAUL)

/**
* @brief          BCTU new data interrupt flag for ADCx
*/
/** @violates @ref Adc_Reg_eSys_Bctu_h_REF_1 MISRA-C:2004 Rule 19.7: Function-like macro defined */
#define BCTU_NDATA_FLAG_U32(x)  ((uint32)((uint32)1<<(uint32)((x) + (uint32)16)))

/**
* @brief          BCTU data over write interrupt flag for ADCx
*/
/** @violates @ref Adc_Reg_eSys_Bctu_h_REF_1 MISRA-C:2004 Rule 19.7: Function-like macro defined */
#define BCTU_DATAOVR_FLAG_U32(x)  ((uint32)((uint32)1<<(uint32)((x) + (uint32)20)))

/**
* @brief          BCTU LIST interrupt flag for ADCx
*/
/** @violates @ref Adc_Reg_eSys_Bctu_h_REF_1 MISRA-C:2004 Rule 19.7: Function-like macro defined */
#define BCTU_LIST_FLAG_U32(x)   ((uint32)((uint32)1<<(uint32)((x) + (uint32)24)))

/**
* @brief          Shift mask to get DMAx interupt enable.
*/
#define BCTU_DMA_INT_SHIFT_MASK_U8     ((uint8)16)

/**
* @brief          Shift mask to get loop mode enable.
*/
#define BCTU_LOOP_SHIFT_MASK_U8        ((uint8)31)

/**
* @brief          Shift mask to get LIST mode enable.
*/
#define BCTU_LIST_SHIFT_MASK_U8        ((uint8)13)

/**
* @brief          Shift mask to get Adc unit selected.
*/
#define BCTU_ADC_UNIT_SHIFT_MASK_U8    ((uint8)8)

/**
* @brief          Shift mask to get trigger source.
*/
#define BCTU_TRGSRC_SHIFT_MASK_U8      ((uint8)24)

/**
* @brief          Shift mask to put channel number in list mode.
*/
#define BCTU_LISTCHR_NUM_SHIFT_MASK_U8 ((uint8)16)
#define BCTU_LIST_MASK_ODD_U32         (0x0000FFFFUL)
#define BCTU_LIST_MASK_EVEN_U32        (0xFFFF0000UL)

/**
* @brief          Masks for Trigger Configuration Register.
*/
#define BCTU_LIST_ADDR_MASK_U32        (0x007FUL)
#define BCTU_LIST_ACTIVE_MASK_U32      (0xA000UL)

/**
* @brief          Last channel mask.
*/
#define BCTU_LAST_CHANNEL_U32          (0x8000UL)

/**
* @brief          BCTUSTATUS
* @details        BCTU Status.
*/
#define BCTU_STATUS_U32                    (0x44000000UL)
#define BCTU_SET_GTRG_EN_STATUS_U32        (0x04000000UL)
#define BCTU_CLEAR_GTRG_EN_STATUS_U32      (0x00000000UL)
#define BCTU_SET_MDIS_EN_STATUS_U32        (0x40000000UL)
#define BCTU_CLEAR_MDIS_EN_STATUS_U32      (0x00000000UL)

/**
 * @brief          List interrupt flags mask.
 *
 */
#define BCTU_LIST_FLAG_ADC_0_U32       (0x0100UL)
#define BCTU_LIST_FLAG_ADC_1_U32       (0x0200UL)
#define BCTU_LIST_FLAG_ADC_2_U32       (0x0400UL)
#define BCTU_LIST_FLAG_ADC_3_U32       (0x0800UL)
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

#endif /* ADC_REG_ESYS_BCTU_H */

/** @} */
