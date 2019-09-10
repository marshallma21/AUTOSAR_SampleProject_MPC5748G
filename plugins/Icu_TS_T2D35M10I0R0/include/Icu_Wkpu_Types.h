/**
*     @file    Icu_Wkpu_Types.h
*     @version 1.0.0
* 
*     @brief   AUTOSAR Icu - WKPU header file support for ICU driver.
*     @details WKPU header file, containing the variables and functions that are exported by the WKPU driver.
* 
*     @addtogroup Wkpu
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
#ifndef ICU_WKPU_TYPES
#define ICU_WKPU_TYPES

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*       Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*       on the significance of more than 31 characters. The used compilers use more than 31 chars
*       for identifiers
*
* @section Icu_Wkpu_Types_h_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*          character significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly
*/

#ifdef __cplusplus
extern "C"
{
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
#define ICU_WKPU_TYPES_VENDOR_ID                     43

#define ICU_WKPU_TYPES_AR_RELEASE_MAJOR_VERSION      4
#define ICU_WKPU_TYPES_AR_RELEASE_MINOR_VERSION      2
#define ICU_WKPU_TYPES_AR_RELEASE_REVISION_VERSION   2

#define ICU_WKPU_TYPES_SW_MAJOR_VERSION              1
#define ICU_WKPU_TYPES_SW_MINOR_VERSION              0
#define ICU_WKPU_TYPES_SW_PATCH_VERSION              0

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
*@{
*@brief WKPU External Interrupt Channels defines
*/
#define ICU_WKPU_0    ((uint8) 0U)
#define ICU_WKPU_1    ((uint8) 1U)
#define ICU_WKPU_2    ((uint8) 2U)
#define ICU_WKPU_3    ((uint8) 3U)
#define ICU_WKPU_4    ((uint8) 4U)
#define ICU_WKPU_5    ((uint8) 5U)
#define ICU_WKPU_6    ((uint8) 6U)
#define ICU_WKPU_7    ((uint8) 7U)
#define ICU_WKPU_8    ((uint8) 8U)
#define ICU_WKPU_9    ((uint8) 9U)
#define ICU_WKPU_10   ((uint8)10U)
#define ICU_WKPU_11   ((uint8)11U)
#define ICU_WKPU_12   ((uint8)12U)
#define ICU_WKPU_13   ((uint8)13U)
#define ICU_WKPU_14   ((uint8)14U)
#define ICU_WKPU_15   ((uint8)15U)
#define ICU_WKPU_16   ((uint8)16U)
#define ICU_WKPU_17   ((uint8)17U)
#define ICU_WKPU_18   ((uint8)18U)
#define ICU_WKPU_19   ((uint8)19U)
#define ICU_WKPU_20   ((uint8)20U)
#define ICU_WKPU_21   ((uint8)21U)
#define ICU_WKPU_22   ((uint8)22U)
#define ICU_WKPU_23   ((uint8)23U)
#define ICU_WKPU_24   ((uint8)24U)
#define ICU_WKPU_25   ((uint8)25U)
#define ICU_WKPU_26   ((uint8)26U)
#define ICU_WKPU_27   ((uint8)27U)
#define ICU_WKPU_28   ((uint8)28U)
#define ICU_WKPU_29   ((uint8)29U)
#define ICU_WKPU_30   ((uint8)30U)
#define ICU_WKPU_31   ((uint8)31U)
/**@}*/

/**
*@{
*@brief Filter for enabling the WKPU interrupt
*/
#define ICU_WKPU_INT_FILTER_ENABLE  0x1U
/**@}*/

/**
*@{
*@brief define for enabling WKPU pullup
*/
#define ICU_WKPU_PULLUP_ENABLE      0x1U
/**@}*/


/**
* @{
* @brief WKPU Channel Parameters
* @remarks Wakeup/Interrupt Filter Enable Register (WIFER)
*          These macros are used in ICU plug-in
*/
#define ICU_WKPU_INT_FILTER_ENABLE_PARAM_MASK       (BIT1)

/* @violates @ref Icu_Wkpu_Types_h_1 Identifier clash.*/
#define ICU_WKPU_INT_FILTER_ENABLE_PARAM_SHIFT      ((uint32)1U)
/**@}*/


/* Specific WKPU Channel parameters
  *  - defines for bitfields used in Icu_ParamValue member for ICU WKPU Channels
 */
/**
* @{
* @brief WKPU Channel Parameters
* @remarks Wakeup/Interrupt Pullup Enable Register (WIPUER)
*          These macros are used in ICU plug-in
*/
#define ICU_WKPU_PULLUP_ENABLE_PARAM_MASK           (BIT0)

#define ICU_WKPU_PULLUP_ENABLE_PARAM_SHIFT          ((uint32)0U)
/**@}*/

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*================================================================================================*/
/**
* @typedef   Icu_Wkpu_ChannelType
*            Type for saving the WKPU channel id
*/
/*================================================================================================*/
typedef uint16  Icu_Wkpu_ChannelType;

typedef uint16 Icu_Wkpu_ControlType;

typedef struct
{  
    /** @brief Assigned Wkpu channel id*/
    CONST(Icu_Wkpu_ChannelType, ICU_CONST) nHwChannel;
    /** @brief Wkpu Default Start Edge */
    CONST(uint8,  ICU_CONST) nDefaultStartEdge; 
    /** @brief Wkpu channel parameters */
    CONST(Icu_Wkpu_ControlType, ICU_CONST) nControlValue;   
} Icu_Wkpu_ChannelConfigType;

/**
* @brief      Wkpu IP specific configuration structure type
*/
typedef struct
{
    /** @brief Number of Wkpu channels in the Icu configuration */
    CONST(Icu_Wkpu_ChannelType,       ICU_CONST) nNumChannels;
    /** @brief Pointer to the configured channels for Wkpu */
    CONST(Icu_Wkpu_ChannelConfigType, ICU_CONST) (*pChannelsConfig)[]; 
} Icu_Wkpu_IpConfigType;
/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif  /* ICU_WKPU_TYPES */
/**@}*/
