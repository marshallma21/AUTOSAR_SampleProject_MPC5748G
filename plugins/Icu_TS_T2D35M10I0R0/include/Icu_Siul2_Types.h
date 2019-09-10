/**
*     @file    Icu_Siul2_Types.h
*     @version 1.0.0
* 
*     @brief   AUTOSAR Icu - SIUL low level driver exported structures.
*     @details Interface between the high level driver (Autosar dependent) and the low level driver(platform dependent).
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

#ifndef ICU_SIUL2_TYPES
#define ICU_SIUL2_TYPES

/**
* @page misra_violations MISRA-C:2004 violations
* 
* @section Icu_SIUL2_Types_h_1
*        Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*        that 31 character significance and case sensitivity are supported for external identifiers.
*        The defines are validated.
*
* @section [global]
*        Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*        on the significance of more than 31 characters. The used compilers use more than 31 chars
*        for identifiers.
*/

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ICU_SIUL2_TYPES_VENDOR_ID                   43
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_TYPES_AR_RELEASE_MAJOR_VERSION    4
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_TYPES_AR_RELEASE_MINOR_VERSION    2
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_TYPES_AR_RELEASE_REVISION_VERSION 2
#define ICU_SIUL2_TYPES_SW_MAJOR_VERSION            1
#define ICU_SIUL2_TYPES_SW_MINOR_VERSION            0
#define ICU_SIUL2_TYPES_SW_PATCH_VERSION            0
/**@}*/


/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                        DEFINES AND MACROS
==================================================================================================*/
/**
* @{
* @brief SIUL External Interrupt Channels defines
*/
#define ICU_SIUL2_IRQ_0    ((uint8) 0U)
#define ICU_SIUL2_IRQ_1    ((uint8) 1U)
#define ICU_SIUL2_IRQ_2    ((uint8) 2U)
#define ICU_SIUL2_IRQ_3    ((uint8) 3U)
#define ICU_SIUL2_IRQ_4    ((uint8) 4U)
#define ICU_SIUL2_IRQ_5    ((uint8) 5U)
#define ICU_SIUL2_IRQ_6    ((uint8) 6U)
#define ICU_SIUL2_IRQ_7    ((uint8) 7U)
#define ICU_SIUL2_IRQ_8    ((uint8) 8U)
#define ICU_SIUL2_IRQ_9    ((uint8) 9U)
#define ICU_SIUL2_IRQ_10   ((uint8)10U)
#define ICU_SIUL2_IRQ_11   ((uint8)11U)
#define ICU_SIUL2_IRQ_12   ((uint8)12U)
#define ICU_SIUL2_IRQ_13   ((uint8)13U)
#define ICU_SIUL2_IRQ_14   ((uint8)14U)
#define ICU_SIUL2_IRQ_15   ((uint8)15U)
#define ICU_SIUL2_IRQ_16   ((uint8)16U)
#define ICU_SIUL2_IRQ_17   ((uint8)17U)
#define ICU_SIUL2_IRQ_18   ((uint8)18U)
#define ICU_SIUL2_IRQ_19   ((uint8)19U)
#define ICU_SIUL2_IRQ_20   ((uint8)20U)
#define ICU_SIUL2_IRQ_21   ((uint8)21U)
#define ICU_SIUL2_IRQ_22   ((uint8)22U)
#define ICU_SIUL2_IRQ_23   ((uint8)23U)
#define ICU_SIUL2_IRQ_24   ((uint8)24U)
#define ICU_SIUL2_IRQ_25   ((uint8)25U)
#define ICU_SIUL2_IRQ_26   ((uint8)26U)
#define ICU_SIUL2_IRQ_27   ((uint8)27U)
#define ICU_SIUL2_IRQ_28   ((uint8)28U)
#define ICU_SIUL2_IRQ_29   ((uint8)29U)
#define ICU_SIUL2_IRQ_30   ((uint8)30U)
#define ICU_SIUL2_IRQ_31   ((uint8)31U)

/**@}*/

/**
* @{
* @brief Filter for enabling the SIUL2 interrupt
*/
#define ICU_SIUL2_INT_FILTER_ENABLE  (0x1U)
/**@}*/


/**
* @{
* @brief SIUL2 Channel Parameters
* @remarks Interrupt Filter Enable Register (IFER)
*          These macros are used in ICU plug-in
*
*/
#define ICU_SIUL2_INT_FILTER_ENABLE_PARAM_MASK       ((uint32)BIT4)
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_INT_FILTER_ENABLE_PARAM_SHIFT      ((uint32)4U)
/**@}*/

/**
* @{
* @brief SIUL2 Channel Parameters
* @remarks Interrupt Filter Maximum Counter Registers (IFMC0-FMC23)
*          These macros are used in ICU plug-in
*/
#define ICU_SIUL2_INT_FILTER_COUNTER_PARAM_MASK      (BIT3|BIT2|BIT1|BIT0)
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_INT_FILTER_COUNTER_PARAM_SHIFT     ((uint32)0U)
/**@}*/

/**
* @{
* @brief SIUL2 Global Configuration Parameter
* @remarks Interrupt Filter Clock Prescaler Register(SIUL2_IFCPR)
*/
#define ICU_SIUL2_INT_FILTER_CLOCK_PRESCALER_GC_MASK      (BIT3|BIT2|BIT1|BIT0)
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_INT_FILTER_CLOCK_PRESCALER_GC_SHIFT     ((uint32)0U)

/**
* @{
* @brief SIUL2 Global Configuration Parameter
* @remarks Interrupt Filter Clock Prescaler in Alternate Mode(SIUL2_IFCPR)
*/
#define ICU_SIUL2_INT_ALTERNATE_FILTER_CLOCK_PRESCALER_GC_MASK      (BIT7|BIT6|BIT5|BIT4)
/* @violates @ref Icu_SIUL2_Types_h_1 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_SIUL2_INT_ALTERNATE_FILTER_CLOCK_PRESCALER_GC_SHIFT     ((uint32)4U)

/**@}*/
/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uint8  Icu_Siul2_ChannelType;

typedef uint16 Icu_Siul2_ControlType;

typedef uint16 Icu_Siul2_GlobalConfigurationType;

typedef struct
{  
    /** @brief Assigned Siul2 channel id*/
    CONST(Icu_Siul2_ChannelType,  ICU_CONST) nHwChannel;
    /** @brief Siul2 channel parameters */
    CONST(Icu_Siul2_ControlType,  ICU_CONST) nControlValue;
    /** @brief Siul2 Default Start Edge */
    CONST(uint8,  ICU_CONST) nDefaultStartEdge;   
} Icu_Siul2_ChannelConfigType;

/**
* @brief      Siul2 IP specific configuration structure type
*/
typedef struct
{
    /** @brief Number of Siul2 channels in the Icu configuration */
    CONST(Icu_Siul2_ChannelType,       ICU_CONST) nNumChannels;
    /** @brief The Siul2 global configuration paramters */
    CONST(Icu_Siul2_GlobalConfigurationType, ICU_CONST) Icu_GlobalConfiguration;
    /** @brief Pointer to the configured channels for Siul2 */
    CONST(Icu_Siul2_ChannelConfigType, ICU_CONST) (*pChannelsConfig)[];
} Icu_Siul2_IpConfigType;
/*==================================================================================================
*                                      FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  /* ICU_SIUL2_TYPES */
/** @} */

