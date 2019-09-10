/**
*   @file    eMios_Common_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eDMA
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
*
* @page misra_violations MISRA-C:2004 violations
*
* @section eMios_Common_Types_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section eMios_Common_Types_h_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section eMios_Common_Types_h_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section eMios_Common_Types_h_4
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused
*
*@section eMios_Common_Types_h_5
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/
#ifndef EMIOS_COMMON_TYPES_H
/** @violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_COMMON_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief   Header file version information
*/
/** 
* @violates @ref eMios_Common_Types_h_5 This is required as per autosar Requirement 
* @violates @ref eMios_Common_Types_h_4 This is not a standard library macro*/
#define EMIOS_COMMON_TYPES_VENDOR_ID                            43
/** @violates @ref eMios_Common_Types_h_5 This is required as per autosar Requirement
** @violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION             4
/**
* @violates @ref eMios_Common_Types_h_3 The compiler/linker shall be checked...
* @violates @ref eMios_Common_Types_h_5 This is required as per autosar Requirement,
* @violates @ref eMios_Common_Types_h_4 This is not a standard library macro
*/
#define EMIOS_COMMON_TYPES_AR_RELEASE_MINOR_VERSION             2
/**
* @violates @ref eMios_Common_Types_h_3 The compiler/linker shall be checked...
* @violates @ref eMios_Common_Types_h_5 This is required as per autosar Requirement,
* @violates @ref eMios_Common_Types_h_4 This is not a standard library macro
*/
#define EMIOS_COMMON_TYPES_AR_RELEASE_REVISION_VERSION          2
/** @violates @ref eMios_Common_Types_h_5 This is required as per autosar Requirement
 **@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_COMMON_TYPES_SW_MAJOR_VERSION                     1
/** @violates @ref eMios_Common_Types_h_5 This is required as per autosar Requirement
 **@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_COMMON_TYPES_SW_MINOR_VERSION                     0
/** @violates @ref eMios_Common_Types_h_5 This is required as per autosar Requirement
 **@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_COMMON_TYPES_SW_PATCH_VERSION                     0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief EMIOS channels defines
*/
/*
 * EMIOS channel encoding
 *
 * [              3 bit | 5 bit                ]
 * [ module id: 7 ... 0 | channel id: 31 ... 0 ]
 */
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_MOD_MASK_U8                                       ((uint8)0xE0)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_MOD_SHIFT                                         ((uint8)5U)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CH_MASK_U8                                        ((uint8)0x1F)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CH_SHIFT                                          ((uint8)0U)

/* EMIOS module and channel decoding */
/** @violates @ref eMios_Common_Types_h_2 Function-like macro defined */
/** @violates @ref eMios_Common_Types_h_4 This is not a standard library macro*/
#define EMIOS_MODULE_INDEX_U8(ch)      ((uint8)(((ch) & EMIOS_MOD_MASK_U8) >> EMIOS_MOD_SHIFT))
/** @violates @ref eMios_Common_Types_h_2 Function-like macro defined */
/** @violates @ref eMios_Common_Types_h_4 This is not a standard library macro*/
#define EMIOS_CHANNEL_INDEX_U8(ch)     ((uint8)(((ch) & EMIOS_CH_MASK_U8)  >> EMIOS_CH_SHIFT))

/**
* @brief EMIOS Modules defines
*/
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_MODULE_0     ((uint8)0x00U)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_MODULE_1     ((uint8)0x01U)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_MODULE_2     ((uint8)0x02U)

/**
* @brief EMIOS Channels defines
*/
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_0     ((uint8)0x00)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_1     ((uint8)0x01)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_2     ((uint8)0x02)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_3     ((uint8)0x03)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_4     ((uint8)0x04)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_5     ((uint8)0x05)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_6     ((uint8)0x06)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_7     ((uint8)0x07)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_8     ((uint8)0x08)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_9     ((uint8)0x09)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_10    ((uint8)0x0A)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_11    ((uint8)0x0B)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_12    ((uint8)0x0C)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_13    ((uint8)0x0D)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_14    ((uint8)0x0E)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_15    ((uint8)0x0F)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_16    ((uint8)0x10)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_17    ((uint8)0x11)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_18    ((uint8)0x12)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_19    ((uint8)0x13)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_20    ((uint8)0x14)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_21    ((uint8)0x15)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_22    ((uint8)0x16)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_23    ((uint8)0x17)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_24    ((uint8)0x18)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_25    ((uint8)0x19)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_26    ((uint8)0x1A)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_27    ((uint8)0x1B)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_28    ((uint8)0x1C)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_29    ((uint8)0x1D)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_30    ((uint8)0x1E)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_CHANNEL_31    ((uint8)0x1F)


/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_0    (EMIOS_CHANNEL_0)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_1    (EMIOS_CHANNEL_1)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_2    (EMIOS_CHANNEL_2)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_3    (EMIOS_CHANNEL_3)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_4    (EMIOS_CHANNEL_4)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_5    (EMIOS_CHANNEL_5)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_6    (EMIOS_CHANNEL_6)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_7    (EMIOS_CHANNEL_7)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_8    (EMIOS_CHANNEL_8)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_9    (EMIOS_CHANNEL_9)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_10   (EMIOS_CHANNEL_10)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_11   (EMIOS_CHANNEL_11)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_12   (EMIOS_CHANNEL_12)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_13   (EMIOS_CHANNEL_13)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_14   (EMIOS_CHANNEL_14)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_15   (EMIOS_CHANNEL_15)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_16   (EMIOS_CHANNEL_16)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_17   (EMIOS_CHANNEL_17)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_18   (EMIOS_CHANNEL_18)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_19   (EMIOS_CHANNEL_19)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_20   (EMIOS_CHANNEL_20)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_21   (EMIOS_CHANNEL_21)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_22   (EMIOS_CHANNEL_22)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_23   (EMIOS_CHANNEL_23)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_24   (EMIOS_CHANNEL_24)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_25   (EMIOS_CHANNEL_25)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_26   (EMIOS_CHANNEL_26)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_27   (EMIOS_CHANNEL_27)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_28   (EMIOS_CHANNEL_28)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_29   (EMIOS_CHANNEL_29)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_30   (EMIOS_CHANNEL_30)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_0_CH_31   (EMIOS_CHANNEL_31)
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_0    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_1    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_1))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_2    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_2))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_3    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_3))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_4    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_4))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_5    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_5))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_6    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_6))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_7    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_7))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_8    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_9    ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_9))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_10   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_10))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_11   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_11))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_12   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_12))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_13   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_13))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_14   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_14))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_15   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_15))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_16   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_17   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_17))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_18   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_18))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_19   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_19))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_20   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_20))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_21   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_21))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_22   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_22))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_23   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_24   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_25   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_25))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_26   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_26))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_27   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_27))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_28   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_28))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_29   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_29))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_30   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_30))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_1_CH_31   ((uint8)((uint8)(1U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_31))

/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_0    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_1    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_1))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_2    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_2))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_3    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_3))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_4    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_4))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_5    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_5))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_6    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_6))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_7    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_7))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_8    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_9    ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_9))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_10   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_10))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_11   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_11))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_12   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_12))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_13   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_13))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_14   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_14))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_15   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_15))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_16   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_17   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_17))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_18   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_18))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_19   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_19))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_20   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_20))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_21   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_21))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_22   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_22))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_23   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_24   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_25   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_25))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_26   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_26))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_27   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_27))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_28   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_28))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_29   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_29))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_30   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_30))
/**@violates @ref eMios_Common_Types_h_4 This is not a standard library macro */
#define EMIOS_2_CH_31   ((uint8)((uint8)(2U<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_31))
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* EMIOS_COMMON_TYPES_H */
/** @} */
