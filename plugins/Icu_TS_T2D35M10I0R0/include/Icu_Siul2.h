/**
*     @file    Icu_Siul2.h
*     @version 1.0.0
* 
*     @brief   AUTOSAR Icu - SIUL low level driver exported functions.
*     @details Interface between the high level driver (Autosar dependent) and the low level driver
              (platform dependent).
*     
*     *     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : PA
*     Peripheral          : eMIOS SIUL2 WKPU
*     Dependencies        : none
* 
*     Autosar Version     : 4.2.2
*     Autosar Revision    : ASR_REL_4_2_REV_0002
*     Autosar ConfVariant : 
*     SWVersion           : 1.0.0
*     BuildVersion        : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217
* 
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/


#ifndef ICU_SIUL2_H
#define ICU_SIUL2_H


/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Icu_SIUL2_h_REF_1
*          Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*          This violation is due to function like macros defined for register operations.
*          Function like macros are used to reduce code complexity.
* 
* @section Icu_SIUL2_h_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice.
*          All header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters. The used compilers use more than 31 chars
*          for identifiers.
*
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Icu_Siul2_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_SIUL2_VENDOR_ID                    43

#define ICU_SIUL2_AR_RELEASE_MAJOR_VERSION     4
#define ICU_SIUL2_AR_RELEASE_MINOR_VERSION     2
#define ICU_SIUL2_AR_RELEASE_REVISION_VERSION  2
#define ICU_SIUL2_SW_MAJOR_VERSION             1
#define ICU_SIUL2_SW_MINOR_VERSION             0
#define ICU_SIUL2_SW_PATCH_VERSION             0
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Icu_SIUL2_Types.h file are of the same vendor */
#if (ICU_SIUL2_VENDOR_ID != ICU_SIUL2_TYPES_VENDOR_ID)
#error "Icu_SIUL2.h and Icu_SIUL2_Types.h have different vendor IDs"
#endif
#if ((ICU_SIUL2_AR_RELEASE_MAJOR_VERSION != ICU_SIUL2_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_SIUL2_AR_RELEASE_MINOR_VERSION != ICU_SIUL2_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_SIUL2_AR_RELEASE_REVISION_VERSION != ICU_SIUL2_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_SIUL2.h and Icu_SIUL2_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_SIUL2_SW_MAJOR_VERSION != ICU_SIUL2_TYPES_SW_MAJOR_VERSION) || \
     (ICU_SIUL2_SW_MINOR_VERSION != ICU_SIUL2_TYPES_SW_MINOR_VERSION) || \
     (ICU_SIUL2_SW_PATCH_VERSION != ICU_SIUL2_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_SIUL2.h and Icu_SIUL2_Types.h are different"
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @brief   ICU_SIUL2_IFCPR_DEFAULT_VALUE - after reset
*/
#define ICU_SIUL2_IFCPR_DEFAULT_VALUE     (0x00U)
/**
* @{
* @brief   SIUL_IRQ_CHANNEL_MASK - used for masking IRQ Channels
* @remarks on this IP are available 32 channels
*/
#define ICU_SIUL2_IRQ_CHANNEL_MASK            (0xFFFFFFFFU)
/**@}*/


/**
* @brief   SIUL_IRQ_CHANNEL_GROUP_MASK - used for masking a group of IRQ Channels
* @remarks The groups are mapped as follows IRQ0-IRQ7; IRQ8-IRQ15; IRQ16-IRQ23; IRQ24-IRQ31
* @violates @ref Icu_SIUL2_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define ICU_SIUL2_IRQ_CHANNEL_GROUP_MASK_U32(hwChannel) \
            ((uint32)((BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0) << (hwChannel)))
/**
 * @brief   Channel mask
 * @violates @ref Icu_SIUL2_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define ICU_SIUL2_CHANNEL_MASK_U32(hwChannel) \
            (((uint32)BIT0 << (hwChannel)) & ICU_SIUL2_IRQ_CHANNEL_MASK)


/**
* @brief SIUL_EIISR_ESEL - compute EIISR.ESEL bitfield value for a given channel
* @violates @ref Icu_SIUL2_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define ICU_SIUL2_EIISR_ESEL_U32(hwChannel, value) \
        (((uint32)(value)) << ((hwChannel) << (uint32)1U))

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/**
* @brief         Icu_Siul2_ActivationType
* @details       This indicates the activation type SIUL channel (Rising, Falling or Both)
*
* */
typedef enum
{
    SIUL2_FALLING_EDGE = 0x0U,  /**< @brief  An appropriate action shall be executed when a falling
                                 * edge occurs on the SIUL input signal. */

    SIUL2_RISING_EDGE  = 0x1U,  /**< @brief  An appropriate action shall be executed when a rising
                                 *   edge occurs on the ICU input signal. */

    SIUL2_BOTH_EDGES   = 0x2U  /**< @brief  An appropriate action shall be executed when a rising
                                *   edge or falling edge occurs on the ICU input signal. */
} Icu_Siul2_ActivationType;
/**@}*/


/**
 * @brief   Definition of prescaler type.
 *
*/
typedef enum
{
    SIUL2_ICU_NORMAL_CLOCK_MODE    = 0x0U,           /*< @brief Default channel prescaler. */
    SIUL2_ICU_ALTERNATE_CLOCK_MODE                   /*< @brief Alternate channel prescaler mode */
} Icu_Siul2_SelectPrescalerType;
/**@}*/
/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*================================================================================================*/
/**
* @brief            Icu_Siul2_ParamType
* @details          SIUL Channel interrupt parameter type (i.e Interrupt registers)
*/
/*================================================================================================*/
typedef uint32 Icu_Siul2_ParamType;

/*================================================================================================*/
/**
* @brief            Icu_Siul2_ChannelType
* @details          Type for saving the SIUL interrupt channel id
* */
/*================================================================================================*/


/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/**
* @violates @ref Icu_SIUL2_h_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*of a header file being included twice */
#include "Icu_MemMap.h"

#if ((defined ICU_IRQ_CH_0_ISR_USED)  || (defined ICU_IRQ_CH_1_ISR_USED) \
    || (defined ICU_IRQ_CH_2_ISR_USED) || (defined ICU_IRQ_CH_3_ISR_USED) \
    || (defined ICU_IRQ_CH_4_ISR_USED) || (defined ICU_IRQ_CH_5_ISR_USED) \
    || (defined ICU_IRQ_CH_6_ISR_USED) || (defined ICU_IRQ_CH_7_ISR_USED) \
    || (defined ICU_IRQ_CH_8_ISR_USED) || (defined ICU_IRQ_CH_9_ISR_USED) \
    || (defined ICU_IRQ_CH_10_ISR_USED) || (defined ICU_IRQ_CH_11_ISR_USED) \
    || (defined ICU_IRQ_CH_12_ISR_USED) || (defined ICU_IRQ_CH_13_ISR_USED) \
    || (defined ICU_IRQ_CH_14_ISR_USED) || (defined ICU_IRQ_CH_15_ISR_USED) \
    || (defined ICU_IRQ_CH_16_ISR_USED) || (defined ICU_IRQ_CH_17_ISR_USED) \
    || (defined ICU_IRQ_CH_18_ISR_USED) || (defined ICU_IRQ_CH_19_ISR_USED) \
    || (defined ICU_IRQ_CH_20_ISR_USED) || (defined ICU_IRQ_CH_21_ISR_USED) \
    || (defined ICU_IRQ_CH_22_ISR_USED) || (defined ICU_IRQ_CH_23_ISR_USED) \
    || (defined ICU_IRQ_CH_24_ISR_USED) || (defined ICU_IRQ_CH_25_ISR_USED) \
    || (defined ICU_IRQ_CH_26_ISR_USED) || (defined ICU_IRQ_CH_27_ISR_USED) \
    || (defined ICU_IRQ_CH_28_ISR_USED) || (defined ICU_IRQ_CH_29_ISR_USED) \
    || (defined ICU_IRQ_CH_30_ISR_USED) || (defined ICU_IRQ_CH_31_ISR_USED) \
    || (defined ICU_IRQ_SINGLE_INTERRUPT))
FUNC(boolean, ICU_CODE) Icu_Siul2_GetChInit(CONST(Icu_Siul2_ChannelType, AUTOMATIC) HwChannel);
#endif

#ifdef ICU_ENABLE_USER_MODE_SUPPORT
#if (ICU_ENABLE_USER_MODE_SUPPORT == STD_ON)
/* @brief    Sets the User Access Allowed bit in SIUL2 IP. */
FUNC( void, PORT_CODE) Icu_Siul2_SetUserAccessAllowed(void);
#endif /* (ICU_ENABLE_USER_MODE_SUPPORT == STD_ON) */
#endif /* ICU_ENABLE_USER_MODE_SUPPORT */

FUNC(void, ICU_CODE) Icu_Siul2_Init
(
    P2CONST(Icu_Siul2_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pSiul2IpConfig
);

#if (ICU_DE_INIT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Siul2_DeInit
(
    P2CONST(Icu_Siul2_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pSiul2IpConfig
);
#endif

#if (ICU_SET_MODE_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_Siul2_SetSleepMode
 (
    VAR(Icu_Siul2_ChannelType, AUTOMATIC) HwChannel
 );
 FUNC(void, ICU_CODE) Icu_Siul2_SetNormalMode
 (
    VAR(Icu_Siul2_ChannelType, AUTOMATIC) HwChannel
 );
#endif  /* ICU_SET_MODE_API  */

FUNC (void, ICU_CODE) Icu_Siul2_SetActivationCondition
(
    VAR(Icu_Siul2_ChannelType,    AUTOMATIC) HwChannel,
    VAR(Icu_Siul2_ActivationType, AUTOMATIC) Activation
);


#if (ICU_EDGE_DETECT_API == STD_ON)
 FUNC(void, ICU_CODE) Icu_Siul2_EnableEdgeDetection(VAR(Icu_Siul2_ChannelType, AUTOMATIC) HwChannel);
 FUNC(void, ICU_CODE) Icu_Siul2_DisableEdgeDetection(VAR(Icu_Siul2_ChannelType, AUTOMATIC) HwChannel);
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_GET_INPUT_STATE_API == STD_ON)
 FUNC (boolean, ICU_CODE) Icu_Siul2_GetInputState(VAR(Icu_Siul2_ChannelType, AUTOMATIC) HwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
 FUNC (void, ICU_CODE) Icu_Siul2_SetClockMode
 (
    VAR(Icu_Siul2_GlobalConfigurationType,   AUTOMATIC) nGlobalConfig,
    CONST(Icu_Siul2_SelectPrescalerType,     AUTOMATIC) Prescaler
 );
#endif  /* ICU_DUAL_CLOCK_MODE_API */

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_SIUL2_h_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice  */
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* ICU_SIUL2_H */
/** @} */

