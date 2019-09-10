/**
*   @file    Icu_eMios.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup ICU_MODULE
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
#ifndef ICU_EMIOS_H
#define ICU_EMIOS_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_eMios_h_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
* character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_EMIOS_VENDOR_ID                           43
#define ICU_EMIOS_MODULE_ID                           122
#define ICU_EMIOS_AR_RELEASE_MAJOR_VERSION            4
#define ICU_EMIOS_AR_RELEASE_MINOR_VERSION            2
#define ICU_EMIOS_AR_RELEASE_REVISION_VERSION         2
#define ICU_EMIOS_SW_MAJOR_VERSION                    1
#define ICU_EMIOS_SW_MINOR_VERSION                    0
#define ICU_EMIOS_SW_PATCH_VERSION                    0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
                                             ENUMS
==================================================================================================*/
/**
* @brief            eMIOS_ChannelModeType
* @details          Type that indicates the channel mode type(capture mode, edge counter).
* */
typedef enum
{
    EMIOS_CHANNEL_MODE_SIGNAL_EDGE_DETECT    = 0x01U, /*< @brief Mode for detecting edges. */
    EMIOS_CHANNEL_MODE_SIGNAL_MEASUREMENT    = 0x02U, /*< @brief Mode for measuring different times
                                                        *  between various configurable edges. */
    EMIOS_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA = 0x04U, /*< @brief Mode for capturing timer values
                                                        *  on configurable edges. */
    EMIOS_CHANNEL_MODE_TIMESTAMP_WITH_DMA    = 0x10U, /*< @brief Mode for capturing timer values
                                                            *  on configurable edges. */
    EMIOS_CHANNEL_MODE_EDGE_COUNTER          = 0x08U /*< @brief Mode for counting edges on
                                                       *  configurable edges. */
} Icu_eMios_ChannelMeasurementModeType;


/*================================================================================================*/
/**
* @brief    eMIOS_ActivationType
* @details  Type that indicates the channel activation type(Rising, Falling, Both Edges or Opposite
*           Edges).
*/
/*================================================================================================*/
typedef enum
{
    /* EMIOS_OPPOSITE_EDGES = An appropriate action shall be executed when either a falling or
        rising edge occur on the ICU input signal. */
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    EMIOS_OPPOSITE_EDGES    = 0x3U,
#endif   /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */
    /* EMIOS_FALLING_EDGE = An appropriate action shall be executed when a falling edge occurs
        on the ICU input signal. */
    EMIOS_FALLING_EDGE      = 0x0U,
    /* EMIOS_RISING_EDGE = An appropriate action shall be executed when a rising edge occurs on
        the ICU input signal.*/
    EMIOS_RISING_EDGE       = 0x1U,
    /* EMIOS_RISING_EDGE = An appropriate action shall be executed when either a rising or
        falling edge occur on the ICU input signal.*/
    EMIOS_BOTH_EDGES        = 0x2U
} Icu_eMios_ActivationType;

/*================================================================================================*/
/**
* @brief    Icu_eMios_OperationMode
* @details  eMIOS Unified Channel Modes of Operation.
*           These macros are used in ICU plug-in for specifying the UC mode to be used
*/
/*================================================================================================*/
/**
 *@brief Definition of the measurement property type.
*/
typedef enum
{
    EMIOS_ICU_LOW_TIME     = 0x01U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Low Time. */
    EMIOS_ICU_HIGH_TIME    = 0x02U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal High Time. */
    EMIOS_ICU_PERIOD_TIME  = 0x04U,    /*< @brief The channel is configured for reading the
                                         *          elapsed Signal Period Time. */
    EMIOS_ICU_DUTY_CYCLE   = 0x08U     /*< @brief The channel is configured to read values which
                                         *          are needed for calculating the duty cycle
                                         *          (coherent Active and Period Time). */
} Icu_eMios_SignalMeasurementPropertyType;

/**
 * @brief   Definition of prescaler type.
 *
*/
typedef enum
{
    EMIOS_ICU_NORMAL_CLOCK_MODE    = 0x0U,           /*< @brief Default channel prescaler. */
    EMIOS_ICU_ALTERNATE_CLOCK_MODE                   /*< @brief Alternate channel prescaler mode */
} Icu_eMios_SelectPrescalerType;

/**
 * @brief          The Icu_ParamType contains combined bit fields for initialization options, for
 *                 different registers.
 *
 * */
typedef uint32                          Icu_eMios_ParamType;
/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/



/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE
/**@violates @ref Icu_eMios_h_1 precautions to prevent...*/
#include "Icu_MemMap.h"

FUNC (void, ICU_CODE) Icu_eMios_Init
(
    P2CONST(Icu_eMios_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) peMiosIpConfig
);

#if (ICU_DE_INIT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMios_DeInit
(
    P2CONST(Icu_eMios_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) peMiosIpConfig
);
#endif

#if (ICU_SET_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMios_SetSleepMode
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
FUNC (void, ICU_CODE) Icu_eMios_SetNormalMode
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
#endif  /* ICU_SET_MODE_API */


FUNC (void, ICU_CODE) Icu_eMios_SetActivationCondition
(
    CONST(Icu_eMios_ChannelType,                    AUTOMATIC) nHwChannel,
    CONST(Icu_eMios_ActivationType,                 AUTOMATIC) Activation
);

#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMios_EnableEdgeDetection
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
FUNC (void, ICU_CODE) Icu_eMios_DisableEdgeDetection
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_eMios_StartTimestamp
(
    CONST(Icu_eMios_ChannelType,         AUTOMATIC)   nHwChannel,
    CONST(boolean,                       AUTOMATIC)   bDmaSupport
);
FUNC(void, ICU_CODE) Icu_eMios_StopTimestamp
(
    CONST(Icu_eMios_ChannelType,         AUTOMATIC)   nHwChannel
);
#endif  /* ICU_TIMESTAMP_API */
#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
FUNC(uint32, ICU_CODE) Icu_eMios_GetStartAddress
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
#endif

#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMios_ResetEdgeCount
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
FUNC (void, ICU_CODE) Icu_eMios_EnableEdgeCount
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
FUNC (void, ICU_CODE) Icu_eMios_DisableEdgeCount
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
FUNC (uint32, ICU_CODE) Icu_eMios_GetEdgeNumbers
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMios_StartSignalMeasurement
(
    CONST(Icu_eMios_ChannelType,                    AUTOMATIC) nHwChannel,
    CONST(Icu_eMios_ActivationType,                 AUTOMATIC) Activation,
    CONST(Icu_eMios_SignalMeasurementPropertyType,  AUTOMATIC) nMeasProperty,
    CONST(boolean,                                  AUTOMATIC) bDmaSupport,
    CONST(boolean,                                  AUTOMATIC) bWithoutInterrupt
);

FUNC (void, ICU_CODE) Icu_eMios_StopSignalMeasurement
(
    CONST(Icu_eMios_ChannelType,                    AUTOMATIC) nHwChannel
);
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
FUNC (boolean, ICU_CODE) Icu_eMios_GetInputState
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
#endif  /* ICU_GET_INPUT_STATE_API */

FUNC (void, ICU_CODE) Icu_eMios_ProcessCommonInterrupt
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
);

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
FUNC (boolean, ICU_CODE) Icu_eMios_GetInputLevel
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
#endif /* ICU_GET_INPUT_LEVEL_API == STD_ON */

FUNC (boolean, ICU_CODE) Icu_eMios_GetOverflow
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMios_SetClockMode
(
    P2CONST(Icu_eMios_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) peMiosIpConfig,
    CONST(Icu_eMios_SelectPrescalerType, AUTOMATIC)                 Prescaler
);
#endif  /* ICU_DUAL_CLOCK_MODE_API == STD_ON */

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)))
FUNC(uint32, ICU_CODE) Icu_eMios_GetCaptureRegisterValue
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
#endif  /* ICU_DUAL_CLOCK_MODE_API == STD_ON */

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
FUNC(void, ICU_CODE) Icu_eMios_GetPulseWidth
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
);
#endif /* ((ICU_GET_PULSE_WIDTH_API == STD_ON) &&  (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
FUNC (Std_ReturnType, ICU_CODE) Icu_eMios_ValidateSignalMeasureWithoutInterrupt
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Icu_eMios_IpConfigType,  AUTOMATIC, ICU_APPL_CONST) peMiosIpConfig
);
#endif /* ((ICU_GET_PULSE_WIDTH_API == STD_ON) &&  (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

#define ICU_STOP_SEC_CODE
/**@violates @ref Icu_eMios_h_1 precautions to prevent...*/
#include "Icu_MemMap.h"


#ifdef __cplusplus
}
#endif

#endif  /* ICU_EMIOS_H */

/** @} */
