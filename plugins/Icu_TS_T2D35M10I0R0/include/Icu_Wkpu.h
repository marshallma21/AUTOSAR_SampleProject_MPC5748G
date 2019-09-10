/**
 *     @file    Icu_Wkpu.h
 *     @version 1.0.0
 *
 *     @brief   AUTOSAR Icu - WKPU header file support for ICU driver.
 *     @details WKPU header file, containing the variables and functions that are exported by the WKPU driver.
 *
 *     @addtogroup ICU_MODULE
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

#ifndef WKPU_ICU_H
#define WKPU_ICU_H

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Wkpu_h_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Icu_Wkpu_h_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
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

#include "Icu_Wkpu_Types.h"

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define ICU_WKPU_VENDOR_ID            43

#define ICU_WKPU_AR_RELEASE_MAJOR_VERSION     4
#define ICU_WKPU_AR_RELEASE_MINOR_VERSION     2
#define ICU_WKPU_AR_RELEASE_REVISION_VERSION     2

#define ICU_WKPU_SW_MAJOR_VERSION     1
#define ICU_WKPU_SW_MINOR_VERSION     0
#define ICU_WKPU_SW_PATCH_VERSION     0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
/* Check if header file and Icu_Wkpu_Types.h file are of the same vendor */
#if (ICU_WKPU_VENDOR_ID != ICU_WKPU_TYPES_VENDOR_ID)
    #error "Icu_Wkpu.h and Icu_Wkpu_Types.h have different vendor IDs"
#endif
/* Check if header file and Icu_Wkpu_Types.h file are of the same Autosar version */
#if ((ICU_WKPU_AR_RELEASE_MAJOR_VERSION != ICU_WKPU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_MINOR_VERSION != ICU_WKPU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_REVISION_VERSION != ICU_WKPU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu.h and Icu_Wkpu_Types.h are different"
#endif
/* Check if source file and ICU header file are of the same Software version */
#if ((ICU_WKPU_SW_MAJOR_VERSION != ICU_WKPU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_WKPU_SW_MINOR_VERSION != ICU_WKPU_TYPES_SW_MINOR_VERSION) || \
     (ICU_WKPU_SW_PATCH_VERSION != ICU_WKPU_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Wkpu.h and Icu_Wkpu_Types.h are different"
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief   ICU_WKPU_ISR_CHANNEL_MASK - used for masking IRQ Channels
* @remarks Beside IRQ Channels, WKPU provides also NMI capabilities. In order to not alter NMI
* settings all the operations will be masked.
*/
#define ICU_WKPU_ISR_CHANNEL_MASK           ((uint32)0xFFFFFFFFU)
/**@}*/

/**
* @{
* @brief ICU_WKPU_CHANNEL_MASK - Used for masking WKPU IRQ channels
*/
/* @violates @ref Icu_Wkpu_h_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define ICU_WKPU_CHANNEL_MASK(hwChannel)     (((uint32)BIT0 << (uint32)(hwChannel)) &  \
                                                                              ICU_WKPU_ISR_CHANNEL_MASK)
/**@}*/

/**
* @{
* @brief   WKPU_IRQ_CHANNEL_GROUP_MASK - used for masking a group of IRQ Channels
* @remarks The groups are mapped as follows WKUP0-7; WKUP8-15; WKUP16-23; WKUP24-31
*/

/* @violates @ref Icu_Wkpu_h_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define ICU_WKPU_IRQ_CHANNEL_GROUP_MASK(hwChannel)   \
                                  ((uint32)((BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0) << (hwChannel)))
/**@}*/

/**
* @{
* @brief WKPU_EIISR_ESEL - compute EIISR.ESEL bitfield value for a given channel
*/
/* @violates @ref Icu_Wkpu_h_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined */
#define ICU_WKPU_EIISR_ESEL(hwChannel, value)       (((uint32)(value)) << ((uint32)(hwChannel) <<  \
                                                                                        (uint32)1U))
/**@}*/


/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*================================================================================================*/
/**
* @{
* @enum   WKPU_ActivationType
*         Type that indicates the channel activation type(Rising, Falling, Both Edges or Opposite
*         Edges).
*/
/*================================================================================================*/
typedef enum
{
    /** WKPU_FALLING_EDGE = An appropriate action shall be executed when a falling edge
        occurs on the WKPU input signal. */
    WKPU_FALLING_EDGE = 0x0U,
    /** WKPU_RISING_EDGE = An appropriate action shall be executed when a rising edge
        occurs on the WKPU input signal. */
    WKPU_RISING_EDGE  = 0x1U,
    /** WKPU_BOTH_EDGES = An appropriate action shall be executed when a falling edge or
        rising edge occurs on the WKPU input signal. */
    WKPU_BOTH_EDGES   = 0x2U
} WKPU_ActivationType;
/**@}*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*================================================================================================*/
/**
* @typedef   Icu_Wkpu_ParamType
*            WKPU Channel parameter type (i.e used for register values)
*/
/*================================================================================================*/
typedef uint32 Icu_Wkpu_ParamType;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/
#define ICU_START_SEC_CODE

/* @violates @ref Icu_Wkpu_h_2 precautions to prevent the contents
of a header file being included twice */
#include "Icu_MemMap.h"

FUNC (void, ICU_CODE) Icu_Wkpu_Init
(
    P2CONST(Icu_Wkpu_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pWkpuIpConfig
);

FUNC (void, ICU_CODE) Icu_Wkpu_DeInit
(
    P2CONST(Icu_Wkpu_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pWkpuIpConfig
);

#if (ICU_SET_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Wkpu_SetSleepMode(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel);

FUNC (void, ICU_CODE) Icu_Wkpu_SetNormalMode(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel);
#endif  /* ICU_SET_MODE_API  */

FUNC (void, ICU_CODE) Icu_Wkpu_SetActivationCondition
(
    VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel,
    VAR(WKPU_ActivationType,  AUTOMATIC) Activation
);

#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Wkpu_EnableEdgeDetection(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel);
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Wkpu_DisableEdgeDetection(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel);
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
FUNC (boolean, ICU_CODE) Icu_Wkpu_GetInputState(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel);
#endif  /* ICU_GET_INPUT_STATE_API */

FUNC (void, ICU_CODE) Icu_Wkpu_PullUpNonBondedWakeupPin(void);

#define ICU_STOP_SEC_CODE
/* @violates @ref Icu_Wkpu_h_2 precautions to prevent the contents
of a header file being included twice */
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif  /* WKPU_ICU_H */
/**@}*/
