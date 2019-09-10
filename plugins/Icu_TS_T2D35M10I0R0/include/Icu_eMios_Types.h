/**
*   @file    Icu_eMios_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup EMIOS_DRIVER
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS SIUL2 WKPU
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

#ifndef ICU_EMIOS_TYPES_H
#define ICU_EMIOS_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_eMios_Types_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_eMios_Types_h_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Icu_eMios_Types_h_3
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, 
* objects and functions shall not be reused
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*@section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_EMIOS_TYPES_VENDOR_ID            43
#define ICU_EMIOS_TYPES_MODULE_ID            122
#define ICU_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION          4
#define ICU_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION          2
#define ICU_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION       2
#define ICU_EMIOS_TYPES_SW_MAJOR_VERSION                  1
#define ICU_EMIOS_TYPES_SW_MINOR_VERSION                  0
#define ICU_EMIOS_TYPES_SW_PATCH_VERSION                  0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_eMios_Types.h and Std_Types.h are different"
    #endif
#endif
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Number of channels on eMIOS module
*/
#define eMIOS_N_CHANNELS         (32U)

#define ICU_CNT1_BUSA            (23U) /* A Side, Counter Bus A */
#define ICU_CNT2_BUSA            (eMIOS_N_CHANNELS + 23U) /* B Side, Counter Bus A */
#define ICU_CNT3_BUSA            ((2*eMIOS_N_CHANNELS) + 23U) /* B Side, Counter Bus A */

#define ICU_CNT1_BUSB            (0U)  /* A Side, Counter Bus B */
#define ICU_CNT2_BUSB            (eMIOS_N_CHANNELS + 0U) /* B Side, Counter Bus B */
#define ICU_CNT3_BUSB            ((2*eMIOS_N_CHANNELS) + 0U) /* B Side, Counter Bus B */

#define ICU_CNT1_BUSC            (8U)  /* A Side, Counter Bus C */
#define ICU_CNT2_BUSC            (eMIOS_N_CHANNELS + 8U) /* B Side, Counter Bus C */
#define ICU_CNT3_BUSC            ((2*eMIOS_N_CHANNELS) + 8U) /* B Side, Counter Bus C */

#define ICU_CNT1_BUSD            (16U) /* A Side, Counter Bus D */
#define ICU_CNT2_BUSD            (eMIOS_N_CHANNELS + 16U) /* B Side, Counter Bus D */
#define ICU_CNT3_BUSD            ((2*eMIOS_N_CHANNELS) + 16U) /* B Side, Counter Bus D */


#define ICU_CNT1_BUSE            (24U) /* A Side, Counter Bus E */
#define ICU_CNT2_BUSE            (eMIOS_N_CHANNELS + 24U) /* B Side, Counter Bus E */
#define ICU_CNT3_BUSE            ((2*eMIOS_N_CHANNELS) + 24U) /* B Side, Counter Bus E */

#define ICU_CNT1_BUSF            (22U) /* A Side, Counter Bus F */
#define ICU_CNT2_BUSF            (eMIOS_N_CHANNELS + 22U) /* B Side, Counter Bus F */
#define ICU_CNT3_BUSF            ((2*eMIOS_N_CHANNELS) + 22U) /* B Side, Counter Bus F */


/**
* @brief ID for edge overflow
* @details Additional errors that are detected because of specific implementation
*         and/or specific hardware properties shall be added in the ICU device specific
*         implementation specification. The classification and enumeration shall be compatible
*         with the errors listed above.
*/
#define ICU_E_EDGE_OVERFLOW     (0x18U)

/**
* @brief   Define for configuring Falling edge
* @details To automatically set the value in the eMios cfg register
*
 @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro, 
*/
#define EMIOS_FALLING_EDGE_PARAM     ((uint32)((0x0U << CCR_EDSEL_SHIFT)|(0x0U << CCR_EDPOL_SHIFT)))

/**
* @brief   Define for configuring Rising edge
* @details To automatically set the value in the eMios cfg register
* @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro, 
*/
#define EMIOS_RISING_EDGE_PARAM      ((uint32)((0x0U << CCR_EDSEL_SHIFT)|(BIT0 << CCR_EDPOL_SHIFT)))


/**
* @brief   Define for configuring Both edge
* @details To automatically set the value in the eMios cfg register
* @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro, 
*/
#define EMIOS_BOTH_EDGES_PARAM       ((uint32)((BIT0 << CCR_EDSEL_SHIFT)|(0x0U << CCR_EDPOL_SHIFT)))


/**
* @brief EMIOS unified channel specific control register bits desctiption
* @note Hardware Dependent Definition - DO NOT CHANGE
* @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro, 
*/
#define EMIOS_BUS_A                         ((uint32)0x0U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_BUS_DIVERSE                   ((uint32)0x1U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_BUS_F                         ((uint32)0x2U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_BUS_INTERNAL_COUNTER          ((uint32)0x3U)



/**
* @brief EMIOS unified channel digital filter control
* @note Hardware Dependent Definition - DO NOT CHANGE
*/

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_DIGITAL_FILTER_BYPASSED       ((uint32)0U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_DIGITAL_FILTER_02             ((uint32)BIT0)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_DIGITAL_FILTER_04             ((uint32)BIT1)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_DIGITAL_FILTER_08             ((uint32)BIT2)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_DIGITAL_FILTER_16             ((uint32)BIT3)


/**
* @brief EMIOS unified channel prescaller control
* @note Hardware Dependent Definition - DO NOT CHANGE
* @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro, 
*/
#define EMIOS_PRESCALER_DIVIDE_1            ((uint32)0U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_PRESCALER_DIVIDE_2            ((uint32)1U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_PRESCALER_DIVIDE_3            ((uint32)2U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_PRESCALER_DIVIDE_4            ((uint32)3U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_FREEZE_ENABLE                 ((uint32)0x1U)


/**
* @brief EMIOS controller register values
* @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro, 
*/
#define EMIOS_CCR_CLEAR_U32                     ((uint32)0x00000000U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_CADR_CLEAR_U32                    ((uint32)0x00000000U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_INIT_CADR_U32                     ((uint32)0x00FFFFFFU)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_CBDR_CLEAR_U32                    ((uint32)0x00000000U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_CCNTR_CLEAR_U32                   ((uint32)0x00000000U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_INIT_CCNTR_U32                    ((uint32)0x00000000U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_CCNTR_INIT_U32                    ((uint32)0x00000000U)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_CSR_CLEAR_U32                     ((uint32)0xFFFFFFFFU)

/** @violates @ref Icu_eMios_Types_h_3 This is not a standard library macro */
#define EMIOS_IFER_ENABLE_U32                   ((uint32)0x0000FFFFU)

/**
* @{
* @brief Specific eMIOS Channel parameters
* @remarks defines for bitfields used in Icu_ParamValue member for ICU eMIOS Channels
*/

#define ICU_EMIOS_PRESC_ALT_PARAM_MASK          ((uint32)(BIT14|BIT13))
#define ICU_EMIOS_PRESC_ALT_PARAM_SHIFT         ((uint32)13U)
#define ICU_EMIOS_UC_MODE_PARAM_MASK            ((uint32)(BIT12|BIT11|BIT10|BIT9))
#define ICU_EMIOS_UC_MODE_PARAM_SHIFT           ((uint32)9U)
#define ICU_EMIOS_FREEZE_PARAM_MASK             ((uint32)BIT8)
#define ICU_EMIOS_FREEZE_PARAM_SHIFT            ((uint32)8U)
#define ICU_EMIOS_PRESCALER_PARAM_MASK          ((uint32)(BIT7|BIT6))
#define ICU_EMIOS_PRESCALER_PARAM_SHIFT         ((uint32)6U)
#define ICU_EMIOS_DIG_FILTER_PARAM_MASK         ((uint32)(BIT5|BIT4|BIT3|BIT2))
#define ICU_EMIOS_DIG_FILTER_PARAM_SHIFT        (((uint32)2U))
#define ICU_EMIOS_BUS_SELECT_PARAM_MASK         ((uint32)(BIT1|BIT0))
#define ICU_EMIOS_BUS_SELECT_PARAM_SHIFT        ((uint32)0U)

/** @violates @ref Icu_eMios_Types_h_2 Function-like macro defined*/
#define CH_GENERATING_EMIOS_BUS_A(mIdx)         ((uint8)((uint8)((mIdx) << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23))
/** @violates @ref Icu_eMios_Types_h_2 Function-like macro defined*/
#define CH_GENERATING_EMIOS_BUS_F(mIdx)         ((uint8)((uint8)((mIdx) << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_22))

/**
 * @brief          This gives the numeric ID (hardware channel number) of an ICU channel
 * @implements Icu_ChannelType_typedef
 * */
typedef uint8                           Icu_eMios_ChannelType;

typedef uint32                          Icu_eMios_ControlType;

typedef enum
{
    /* EMIOS_UC_DAOC_MODEL : default mode */
    EMIOS_UC_UNSPECIFIED_MODE = 0x0U,
    /* EMIOS_UC_DAOC_MODE  : Double Action Output Compare mode */
    EMIOS_UC_DAOC_MODE,
    /* EMIOS_UC_GPIO_MODE : General purpose Input/Output mode */
    EMIOS_UC_GPIO_MODE,
    /* EMIOS_UC_IPM_MODE : Input Period Measurement mode */
    EMIOS_UC_IPM_MODE,
    /* EMIOS_UC_IPWM_MODE : Input Pulse Width Measurement mode */
    EMIOS_UC_IPWM_MODE,
    /* EMIOS_UC_MC_MODE : Modulus Counter mode */
    EMIOS_UC_MC_MODE,
    /* EMIOS_UC_MCB_MODE : Modulus Counter Buffered mode */
    EMIOS_UC_MCB_MODE,
    /* EMIOS_UC_OPWMB_MODE : Output Pulse Width Modulation Buffered mode */
    EMIOS_UC_OPWMB_MODE,
    /* EMIOS_UC_OPWMT_MODE : Output Pulse Width Modulation with Trigger mode */
    EMIOS_UC_OPWMT_MODE,
    /* EMIOS_UC_OPWFMB_MODE : Output Pulse Width and Frequency Modulation Buffered mode*/
    EMIOS_UC_OPWFMB_MODE,
    /* EMIOS_UC_OPWMCB_MODE : Output Pulse Width Modulation Counter Buffered mode */
    EMIOS_UC_OPWMCB_MODE,
    /* EMIOS_UC_SAIC_MODE : Single Action Input Capture mode */
    EMIOS_UC_SAIC_MODE,
    /* EMIOS_UC_SAOC_MODE : Single Action Output Capture mode */
    EMIOS_UC_SAOC_MODE
} Icu_eMios_OperationMode;

typedef struct
{  
    /** @brief Assigned eMios channel id*/
    CONST(Icu_eMios_ChannelType,     ICU_CONST) nHwChannel;
    /** @brief eMios channel parameters */
    CONST(Icu_eMios_ControlType,     ICU_CONST) nControlValue;
    /** @brief eMios Default Start Edge */
    CONST(uint8,  ICU_CONST) nDefaultStartEdge;
    /** @brief Measurement of ICU signal property without using interrupt */
    CONST(boolean,                   ICU_CONST) bSignalMeasure_WithoutInterrupt;
} Icu_eMios_ChannelConfigType;

/**
* @brief      eTimer IP specific configuration structure type
*/
typedef struct
{
    /** @brief Number of eMios channels in the Icu configuration */
    CONST(Icu_eMios_ChannelType,       ICU_CONST) nNumChannels;
    /** @brief Pointer to the configured channels for eMios */
    CONST(Icu_eMios_ChannelConfigType, ICU_CONST) (*pChannelsConfig)[]; 
} Icu_eMios_IpConfigType;
/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* ICU_EMIOS_TYPES_H */

/** @} */
