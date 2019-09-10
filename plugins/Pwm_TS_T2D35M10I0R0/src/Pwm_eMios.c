/**
*   @file    Pwm_eMios.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Pwm - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios
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

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_eMIOS_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*                                       before "#include"
* MemMap.h included after each section define in order to set the current memory section
*
* @section Pwm_eMIOS_C_REF_2
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion of integer to smaller type
*
* @section Pwm_eMIOS_C_REF_3
* Violates MISRA 2004 Required Rule 10.1, Prohibited Implicit Conversion:
*                                        Non-constant argument to function
*
* @section Pwm_eMIOS_C_REF_4
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness
*
* @section Pwm_eMIOS_C_REF_5
* Violates MISRA 2004 Required Rule 14.6, more than one 'break' terminates loop
*
* @section Pwm_eMIOS_C_REF_6
* Violates MISRA 2004 Required Rule 10.3, Cast of complex integer expression to larger type
*
* @section Pwm_eMIOS_C_REF_7
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer
*
* @section Pwm_eMIOS_C_REF_8
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents of a
* header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section Pwm_eMIOS_C_REF_10
* Violates MISRA 2004 Advisory Rule 11.4, : cast from pointer to pointer
* To typecast the pointer from one data type to other data type
*
* @section Pwm_eMIOS_C_REF_11
* Violates MISRA 2004 Required Rule 17.4, : pointer arithmetic other than array indexing used
*
* @section Pwm_eMIOS_C_REF_12
* Violates MISRA 2004 Required Rule 8.10, external  could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Pwm_eMIOS_C_REF_13
* Violates MISRA 2004 Required Rule 12.4, The right hand operand of a logical && or || operator shall not
*contain side effects.
*
* @section Pwm_eMIOS_C_REF_14
* Violates MISRA 2004 Required Rule 13.1, Assignment operators shall not be used in expressions that 
* yield a Boolean value.
*
* @section Pwm_eMIOS_C_REF_15
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they
* are accessed from within a sigle function.
* These symbols are used in the entire driver.*
*
* @section Pwm_eMIOS_C_REF_16
* Violates MISRA 2004 Advisory Rule 11.3, Cast between a pointer type and an integral type
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
* character significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*
*/


/*===============================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
===============================================================================================*/
#include "Pwm_Ipw_Types.h"
#include "Pwm_eMios.h"
#include "Pwm_Ipw_Notif.h"
#include "Reg_eSys_eMios.h"
#include "eMios_Common_Types.h"
#include "eMios_Common.h"
#define USER_MODE_REG_PROT_ENABLED  (STD_OFF)
#include "SilRegMacros.h"
#include "SchM_Pwm.h"


/*===============================================================================================
*                                        LOCAL MACROS
===============================================================================================*/
/**
* @{
* @brief Parameters that shall be published within the Pwm driver header file and also in the
*       module's description file
*/
#define PWM_EMIOS_C_VENDOR_ID                      43
#define PWM_EMIOS_C_AR_RELEASE_MAJOR_VERSION       4
#define PWM_EMIOS_C_AR_RELEASE_MINOR_VERSION       2
#define PWM_EMIOS_C_AR_RELEASE_REVISION_VERSION    2
#define PWM_EMIOS_C_SW_MAJOR_VERSION               1
#define PWM_EMIOS_C_SW_MINOR_VERSION               0
#define PWM_EMIOS_C_SW_PATCH_VERSION               0

/**@}*/
/*===============================================================================================
*                                      FILE VERSION CHECKS
===============================================================================================*/

/* Check if source file and Pwm_eMios.h are of the same vendor */
#if (PWM_EMIOS_C_VENDOR_ID != PWM_EMIOS_VENDOR_ID)
    #error "Pwm_eMios.c and Pwm_eMios.h have different vendor ids"
#endif

/* Check if source file and Pwm_eMios.h are of the same Autosar version */
#if ((PWM_EMIOS_C_AR_RELEASE_MAJOR_VERSION != PWM_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_C_AR_RELEASE_MINOR_VERSION != PWM_EMIOS_AR_RELEASE_MINOR_VERSION) || \
        (PWM_EMIOS_C_AR_RELEASE_REVISION_VERSION != PWM_EMIOS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMios.c and Pwm_eMios.h are different"
#endif

/* Check if source file and Pwm_eMios.h are of the same software version */
#if ((PWM_EMIOS_C_SW_MAJOR_VERSION != PWM_EMIOS_SW_MAJOR_VERSION) || \
        (PWM_EMIOS_C_SW_MINOR_VERSION != PWM_EMIOS_SW_MINOR_VERSION) || \
        (PWM_EMIOS_C_SW_PATCH_VERSION != PWM_EMIOS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMios.c and Pwm_eMios.h are different"
#endif


#if (PWM_EMIOS_C_VENDOR_ID != PWM_IPW_NOTIF_VENDOR_ID)
    #error "Pwm_Emios.c and Pwm_Ipw_Notif.h have different vendor ids"
#endif

/* Check if source file and Pwm_Ipw_Notif header file are of the same Autosar version */
#if ((PWM_EMIOS_C_AR_RELEASE_MAJOR_VERSION != PWM_IPW_NOTIF_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_C_AR_RELEASE_MINOR_VERSION != PWM_IPW_NOTIF_AR_RELEASE_MINOR_VERSION) || \
        (PWM_EMIOS_C_AR_RELEASE_REVISION_VERSION != PWM_IPW_NOTIF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_Emios.c and Pwm_Ipw_Notif.h are different"
#endif

/* Check if source file and Pwm_Ipw_Notif header file are of the same software version */
#if ((PWM_EMIOS_C_SW_MAJOR_VERSION != PWM_IPW_NOTIF_SW_MAJOR_VERSION) || \
        (PWM_EMIOS_C_SW_MINOR_VERSION != PWM_IPW_NOTIF_SW_MINOR_VERSION) || \
        (PWM_EMIOS_C_SW_PATCH_VERSION != PWM_IPW_NOTIF_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMios.c and Pwm_Ipw_Notif.h are different"
#endif


/* Check if source file and Pwm_Ipw_Types.h are of the same vendor */
#if (PWM_EMIOS_C_VENDOR_ID != PWM_IPW_TYPES_VENDOR_ID)
    #error "Pwm_eMios.c and Pwm_Ipw_Types.h have different vendor ids"
#endif
/* Check if source file and Pwm_Ipw_Types.h are of the same Autosar version */
#if ((PWM_EMIOS_C_AR_RELEASE_MAJOR_VERSION != PWM_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_EMIOS_C_AR_RELEASE_MINOR_VERSION != PWM_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (PWM_EMIOS_C_AR_RELEASE_REVISION_VERSION != PWM_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMios.c and Pwm_Ipw_Types.h are different"
#endif
/* Check if source file and Pwm_Ipw_Types.h are of the same software version */
#if ((PWM_EMIOS_C_SW_MAJOR_VERSION != PWM_IPW_TYPES_SW_MAJOR_VERSION) || \
     (PWM_EMIOS_C_SW_MINOR_VERSION != PWM_IPW_TYPES_SW_MINOR_VERSION)  || \
     (PWM_EMIOS_C_SW_PATCH_VERSION != PWM_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMios.c and Pwm_Ipw_Types.h are different"
#endif


/* Check if source file and Reg_eSys_eMios.h are of the same vendor */
#if (PWM_EMIOS_C_VENDOR_ID != REG_ESYS_EMIOS_VENDOR_ID)
    #error "Pwm_eMios.c and Reg_eSys_eMios.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_eMios.h are of the same Autosar version */
#if ((PWM_EMIOS_C_AR_RELEASE_MAJOR_VERSION != REG_ESYS_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_C_AR_RELEASE_MINOR_VERSION != REG_ESYS_EMIOS_AR_RELEASE_MINOR_VERSION) || \
        (PWM_EMIOS_C_AR_RELEASE_REVISION_VERSION != REG_ESYS_EMIOS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMios.c and Reg_eSys_eMios.h are different"
#endif

/* Check if source file and Reg_eSys_eMios.h are of the same software version */
#if ((PWM_EMIOS_C_SW_MAJOR_VERSION != REG_ESYS_EMIOS_SW_MAJOR_VERSION) || \
        (PWM_EMIOS_C_SW_MINOR_VERSION != REG_ESYS_EMIOS_SW_MINOR_VERSION)  || \
        (PWM_EMIOS_C_SW_PATCH_VERSION != REG_ESYS_EMIOS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMios.c and Reg_eSys_eMios.h are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK

    /* Check if source file and eMios_Common_Types.h are of the same vendor */
    #if (PWM_EMIOS_C_VENDOR_ID != EMIOS_COMMON_TYPES_VENDOR_ID )
        #error "Pwm_eMios.c and eMios_Common_Types.h have different vendor ids"
    #endif
    
    /* Check if source file and eMios_Common_Types.h are of the same Autosar version */
    #if ((PWM_EMIOS_C_AR_RELEASE_MAJOR_VERSION != EMIOS_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
            (PWM_EMIOS_C_AR_RELEASE_MINOR_VERSION != EMIOS_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
            (PWM_EMIOS_C_AR_RELEASE_REVISION_VERSION != EMIOS_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Pwm_eMios.c and eMios_Common_Types.h are different"
    #endif
    
    /* Check if source file and eMios_Common_Types.h are of the same software version */
    #if ((PWM_EMIOS_C_SW_MAJOR_VERSION != EMIOS_COMMON_TYPES_SW_MAJOR_VERSION) || \
            (PWM_EMIOS_C_SW_MINOR_VERSION != EMIOS_COMMON_TYPES_SW_MINOR_VERSION)  || \
            (PWM_EMIOS_C_SW_PATCH_VERSION != EMIOS_COMMON_TYPES_SW_PATCH_VERSION))
        #error "Software Version Numbers of Pwm_eMios.c and eMios_Common_Types.h are different"
    #endif


    /* Check if source file and SilRegMacros.h are of the same vendor */
    #if (PWM_EMIOS_C_VENDOR_ID != SILREGMACROS_VENDOR_ID )
        #error "Pwm_eMios.c and SilRegMacros.h have different vendor ids"
    #endif

    /* Check if source file and SilRegMacros.h are of the same Autosar version */
    #if ((PWM_EMIOS_C_AR_RELEASE_MAJOR_VERSION != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
            (PWM_EMIOS_C_AR_RELEASE_MINOR_VERSION != SILREGMACROS_AR_RELEASE_MINOR_VERSION) || \
            (PWM_EMIOS_C_AR_RELEASE_REVISION_VERSION != SILREGMACROS_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Pwm_eMios.c and SilRegMacros.h are different"
    #endif

    /* Check if source file and SilRegMacros.h are of the same software version */
    #if ((PWM_EMIOS_C_SW_MAJOR_VERSION != SILREGMACROS_SW_MAJOR_VERSION) || \
            (PWM_EMIOS_C_SW_MINOR_VERSION != SILREGMACROS_SW_MINOR_VERSION)  || \
            (PWM_EMIOS_C_SW_PATCH_VERSION != SILREGMACROS_SW_PATCH_VERSION))
        #error "Software Version Numbers of Pwm_eMios.c and SilRegMacros.h are different"
    #endif


    /* Check if source file and eMios_Common.h are of the same vendor */
    #if (PWM_EMIOS_C_VENDOR_ID != EMIOS_COMMON_VENDOR_ID )
        #error "Pwm_eMios.c and eMios_Common.h have different vendor ids"
    #endif

    /* Check if source file and eMios_Common.h are of the same Autosar version */
    #if ((PWM_EMIOS_C_AR_RELEASE_MAJOR_VERSION != EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION) || \
            (PWM_EMIOS_C_AR_RELEASE_MINOR_VERSION != EMIOS_COMMON_AR_RELEASE_MINOR_VERSION) || \
            (PWM_EMIOS_C_AR_RELEASE_REVISION_VERSION != EMIOS_COMMON_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Pwm_eMios.c and eMios_Common.h are different"
    #endif

    /* Check if source file and eMios_Common.h are of the same software version */
    #if ((PWM_EMIOS_C_SW_MAJOR_VERSION != EMIOS_COMMON_SW_MAJOR_VERSION) || \
            (PWM_EMIOS_C_SW_MINOR_VERSION != EMIOS_COMMON_SW_MINOR_VERSION)  || \
            (PWM_EMIOS_C_SW_PATCH_VERSION != EMIOS_COMMON_SW_PATCH_VERSION))
        #error "Software Version Numbers of Pwm_eMios.c and eMios_Common.h are different"
    #endif
#endif

/*===============================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
===============================================================================================*/


/*===============================================================================================
*                                       LOCAL CONSTANTS
===============================================================================================*/


/*===============================================================================================
*                                       LOCAL VARIABLES
===============================================================================================*/

#define PWM_START_SEC_VAR_NO_INIT_8
/*
* @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent
* the contents of a header file being included twice
*/
#include "Pwm_MemMap.h"

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief array used to store the notification status (enabled/disabled) and type
* @details  status and type of notification if enabled for each channel indexed using the hardware channel ID
*               \n PWM_RISING_EDGE,
*               \n PWM_FALLING_EDGE,
*               \n PWM_BOTH_EDGES,
*               \n 0xFF for disabled
*/
/*
* @violates @ref Pwm_eMIOS_C_REF_12 external  could be made static
*/
static VAR(uint8, PWM_VAR) Pwm_eMios_aChannelNotifType[PWM_EMIOS_HW_CHANNELS_U8];
#endif /* PWM_NOTIFICATION_SUPPORTED */


#define PWM_STOP_SEC_VAR_NO_INIT_8
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"

/*===============================================================================================
*                                       GLOBAL VARIABLES
===============================================================================================*/
#define PWM_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"

#define PWM_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"


/**
* @brief Array holding the configured polarity for all eMios channels
*/
static  VAR(Pwm_OutputStateType, PWM_VAR) Pwm_eMios_aChannelPolarity[PWM_EMIOS_HW_CHANNELS_MAX_U8];

/**
* @brief Array holding the configured polarity for all eMios channels
*/
#if ((PWM_DE_INIT_API == STD_ON)||\
     (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)||\
     (PWM_FEATURE_DAOC == STD_ON))
static  VAR(Pwm_OutputStateType, PWM_VAR) Pwm_eMios_aChannelIdleState[PWM_EMIOS_HW_CHANNELS_MAX_U8];
#endif

/**
* @brief   array used to store the current period for each pwm channel, indexed using the hw channel id
*/
/** @violates @ref Pwm_eMIOS_C_REF_15 external symbol. */
static VAR(Pwm_PeriodType, PWM_VAR) Pwm_eMios_aChannelPeriod[PWM_EMIOS_HW_CHANNELS_U8];

/**
* @brief   array used to store the current offset for each pwm channel, indexed using the hw channel id
*/
static VAR(Pwm_PeriodType, PWM_VAR) Pwm_eMios_aChannelOffset[PWM_EMIOS_HW_CHANNELS_MAX_U8];

#if (PWM_FEATURE_DAOC == STD_ON)
static VAR(Pwm_PeriodType, PWM_VAR) Pwm_eMios_aDaocChannelDuty[PWM_EMIOS_HW_CHANNELS_U8];
/**
@brief array used to store the current modulo for each pwm channel for updating the register A in DAOC mode
*/
static VAR(Pwm_PeriodType, PWM_VAR) Pwm_DAOC_aChannelModulo[PWM_EMIOS_HW_CHANNELS_U8];
#endif

#if (PWM_FEATURE_OPWMT == STD_ON)
/**
* @brief   array used to store the current Trigger delay value
*/
/** @violates @ref Pwm_eMIOS_C_REF_15 external symbol. */
static VAR(Pwm_PeriodType, PWM_VAR) Pwm_eMios_aTriggerDelay[PWM_EMIOS_HW_CHANNELS_MAX_U8];
#endif  /* PWM_FEATURE_OPWMT */

#define PWM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_NO_INIT_32
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief   array used to store the current dutycycle state
* details  allowable parameters are:
*           \n 1 - dutycycle != 0%, 100% - signal toggling
*           \n 0 - dutycycle == 0%, 100% - signal is stable state - no transition available
*/
static VAR(uint32, PWM_VAR)  Pwm_eMios_aDutyState[PWM_EMIOS_HW_MODULES_CFG_U8];
#endif /* PWM_NOTIFICATION_SUPPORTED */

#define PWM_STOP_SEC_VAR_NO_INIT_32
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8  */
#include "Pwm_MemMap.h"

#define PWM_START_SEC_VAR_NO_INIT_16
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"

#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief Array of the duty value of the EMIOS_PWM channels used for storing  Duty Cycle 
*/
static VAR(uint16, PWM_VAR) Pwm_eMios_aChannelDuty[PWM_EMIOS_HW_CHANNELS_MAX_U8];
#endif /*(PWM_GET_CHANNEL_STATE )*/

#define PWM_STOP_SEC_VAR_NO_INIT_16
/** @violates @ref Pwm_eMIOS_C_REF_8 */
/** @violates @ref Pwm_eMIOS_C_REF_1 Only preprocessor statements and comments before "#include" */
#include "Pwm_MemMap.h"

/*===============================================================================================
*                                       GLOBAL CONSTANTS
===============================================================================================*/

/*===============================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
===============================================================================================*/

LOCAL_INLINE FUNC(Pwm_eMios_ChannelType, PWM_CODE) Pwm_eMios_GetMasterBus
(
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx,
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx,
    VAR(Pwm_eMios_ControlType,      AUTOMATIC) u32Bus
);

LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_UpdateChannelAB
(
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx,
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx,
    VAR(uint32,                     AUTOMATIC) u32ValA,
    VAR(uint32,                     AUTOMATIC) u32ValB
);

#if (PWM_FEATURE_OPWMT == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_UpdateChannelB
(
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx,
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx,
    VAR(uint32,                     AUTOMATIC) u32ValB
);
#endif /*PWM_FEATURE_OPWMT*/

/*================================================================================================*/
#if (PWM_FEATURE_OPWMCB == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMCB_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
);
#endif /*PWM_FEATURE_OPWMCB*/


#if (PWM_FEATURE_DAOC == STD_ON)   
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_DAOC_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
);
#endif /*PWM_FEATURE_DAOC*/

#if (PWM_FEATURE_OPWMT == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMT_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
);
#endif /*PWM_FEATURE_OPWMT*/

LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMB_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
);

#if (PWM_FEATURE_OPWM == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWM_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
);
#endif /*PWM_FEATURE_OPWM*/

LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMFMB_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
);

#if (PWM_FEATURE_OPWFM == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMFM_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
);
#endif /*PWM_FEATURE_OPWFM*/

/*===============================================================================================*/
#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
LOCAL_INLINE FUNC(Pwm_PeriodType, PWM_CODE) Pwm_eMios_ComputeDutycycle_16bits
(
    VAR(Pwm_PeriodType, AUTOMATIC) nPeriod,
    VAR(uint16,         AUTOMATIC) u16Duty
);
#else
LOCAL_INLINE FUNC(Pwm_PeriodType, PWM_CODE) Pwm_eMios_ComputeDutycycle_32bits
(
    VAR(Pwm_PeriodType, AUTOMATIC) nPeriod,
    VAR(uint16,         AUTOMATIC) u16Duty
);
#endif

/*===============================================================================================*/
#if  (PWM_EMIOS_16_BITS_VARIANT == STD_OFF)  && (PWM_SET_COUNTER_BUS_API == STD_ON)
static FUNC(Pwm_uint64, PWM_CODE)Pwm_eMios_Div64(Pwm_uint64 nNume, Pwm_uint64 nDeno);
#endif

/*===============================================================================================*/
#if ( \
        (PWM_FEATURE_OPWFM == STD_ON) || \
        (PWM_FEATURE_OPWM == STD_ON) || \
        (PWM_FEATURE_DAOC == STD_ON) || \
        (PWM_FEATURE_OPWMT == STD_ON) || \
        (PWM_FEATURE_OPWMCB == STD_ON) \
    )
static FUNC(void, PWM_CODE)Pwm_eMios_HandlePolarityBit
(
    VAR(Pwm_OutputStateType,   AUTOMATIC) ePolarity,
    VAR(uint16,                AUTOMATIC) u16DutyCycle,
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx,
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx,
    VAR(Pwm_eMios_ControlType, AUTOMATIC) u32CtrlRegVal
);
#endif

/*===============================================================================================
*                                       LOCAL FUNCTIONS
===============================================================================================*/
#define PWM_START_SEC_CODE
/** @violates @ref Pwm_eMIOS_C_REF_1  nly preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 */
#include "Pwm_MemMap.h"

/**
* @brief   Function to return the channel id of master bus of current channel
* @details Function to return the channel id of master bus of current channel
* @param[in] u8mIdx  - the index of module
* @param[in] u8chIdx - the index of unified channel
* @param[out]  - The id of master bus
*/
LOCAL_INLINE FUNC(Pwm_eMios_ChannelType, PWM_CODE) Pwm_eMios_GetMasterBus
(
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx,
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx,
    VAR(Pwm_eMios_ControlType, AUTOMATIC) u32Bus
)
{
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) n8MasterBusIdx = (Pwm_eMios_ChannelType)0;
    
    if (PWM_BUS_DIVERSE_U32 == u32Bus)
    {
        if (EMIOS_CHANNEL_7 >= u8chIdx) /* bus B */
        {
            n8MasterBusIdx = (Pwm_eMios_ChannelType)(((uint32)u8mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0);
        }
        else if (EMIOS_CHANNEL_15 >= u8chIdx) /* Bus C */
        {
            n8MasterBusIdx = (Pwm_eMios_ChannelType)(((uint32)u8mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8);
        }
        else if (EMIOS_CHANNEL_23 >= u8chIdx) /* bus D */
        {
            n8MasterBusIdx = (Pwm_eMios_ChannelType)(((uint32)u8mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16);
        }
        else /* Bus E remaining */
        {
            n8MasterBusIdx = (Pwm_eMios_ChannelType)(((uint32)u8mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24);
        }
    }
    else if (PWM_BUS_A_U32 == u32Bus) /* bus A */
    {
        n8MasterBusIdx = (Pwm_eMios_ChannelType)(((uint32)u8mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23);
    } 
    else if (PWM_BUS_F_U32 == u32Bus) /* bus F remaining */
    {
        n8MasterBusIdx = (Pwm_eMios_ChannelType)(((uint32)u8mIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_22);
    }
    else
    {
        /*Empty else to fix misra*/
    }
    return n8MasterBusIdx;
}

/**
* @brief   Function to update the A and B registers in a critical section
* @details This function disable the transfer, updates the register A
*          and register B and enables the transfer
* @param[in] u8mIdx  - the index of module
* @param[in] u8chIdx - the index of unified channel
* @param[in] valA - The eMIOS Reg A value to be updated
* @param[in] valB - The eMIOS Reg B value to be updated
*
*/
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_UpdateChannelAB
(
    VAR(Pwm_eMios_ChannelType,  AUTOMATIC) u8mIdx,
    VAR(Pwm_eMios_ChannelType,  AUTOMATIC) u8chIdx,
    VAR(uint32,                 AUTOMATIC) u32ValA,
    VAR(uint32,                 AUTOMATIC) u32ValB
)
{
#if (PWM_BUFFER_TRANSFER_EN_DIS_API == STD_OFF)     
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_BIT_SET32(EMIOS_OUDR_ADDR32(u8mIdx), (uint32)((uint32)1<<(u8chIdx)));
#endif    
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_WRITE32(EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx), (u32ValA));
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_WRITE32(EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx), (u32ValB));

#if (PWM_BUFFER_TRANSFER_EN_DIS_API == STD_OFF)   
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_BIT_CLEAR32(EMIOS_OUDR_ADDR32(u8mIdx), (uint32)((uint32)1<<(u8chIdx)));
#endif    
}

#if (PWM_FEATURE_OPWMT == STD_ON)
/**
* @brief   Function to update the B registers in a critical section
* @details This function disable the transfer, updates  register B
* @and enables the transfer
* @param[in] u8mIdx  - the index of module
* @param[in] u8chIdx - the index of unified channel
* @param[in] u32ValB - The eMIOS Reg B value to be updated
*
*/
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_UpdateChannelB
(
    VAR(Pwm_eMios_ChannelType,  AUTOMATIC) u8mIdx,
    VAR(Pwm_eMios_ChannelType,  AUTOMATIC) u8chIdx,
    VAR(uint32,                 AUTOMATIC) u32ValB
)
{
#if (PWM_BUFFER_TRANSFER_EN_DIS_API == STD_OFF)
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_BIT_SET32(EMIOS_OUDR_ADDR32(u8mIdx), (uint32)((uint32)1<<(u8chIdx)));
#endif
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_WRITE32(EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx), (u32ValB));

#if (PWM_BUFFER_TRANSFER_EN_DIS_API == STD_OFF)
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_BIT_CLEAR32(EMIOS_OUDR_ADDR32(u8mIdx), (uint32)((uint32)1<<(u8chIdx)));
#endif
}
#endif /*PWM_FEATURE_OPWMT*/


/*===============================================================================================*/
/**
* @brief   Function to compute the duty cycle
* @details This function computes the dutycycle value in ticks
* @param[in] Period - period of pulse
* @param[in] Duty - duty cycle of pulse
*
* @return  Pwm_PeriodType - the computed dutycycle value in ticks
*        - uint16 - 16bit EMIOS return value
*        - uint32 - 24bit EMIOS return value
*
*/
#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
LOCAL_INLINE FUNC(Pwm_PeriodType, PWM_CODE) Pwm_eMios_ComputeDutycycle_16bits
(
    VAR(Pwm_PeriodType, AUTOMATIC) nPeriod,
    VAR(uint16,         AUTOMATIC) u16Duty
)
{
    VAR(Pwm_PeriodType, AUTOMATIC) nDutycycle;
    VAR(uint32,         AUTOMATIC) u32Calc_rounding;

    u32Calc_rounding = (uint32)((uint32)nPeriod * (uint32)u16Duty);
    nDutycycle       = (Pwm_PeriodType)((uint32)u32Calc_rounding>>(Pwm_PeriodType)15);

    return nDutycycle;
}
#else
LOCAL_INLINE FUNC(Pwm_PeriodType, PWM_CODE) Pwm_eMios_ComputeDutycycle_32bits
(
    VAR(Pwm_PeriodType, AUTOMATIC) nPeriod,
    VAR(uint16,         AUTOMATIC) u16Duty
)
{
    VAR(uint32,         AUTOMATIC)  u32Dutycycle;
    VAR(uint32,         AUTOMATIC)  u32PeriodHigh;
    VAR(uint32,         AUTOMATIC)  u32PeriodLow;

    u32PeriodHigh = (nPeriod >> (uint32)16U); /* get the 8bit  MS byte of 24-bit value stored on uint32 */
    u32PeriodLow  = (uint16)(nPeriod);          /* get the 16bit LS word of 24-bit value stored on uint32 */
    u32Dutycycle  = (uint32)((uint32)(u32PeriodHigh * (uint32)u16Duty) << 1U) +
                    (uint32)((uint32)(u32PeriodLow  * (uint32)u16Duty) >> 15U);

    return u32Dutycycle;
}
#endif

/*===============================================================================================*/
#if (PWM_FEATURE_OPWMCB == STD_ON)
/**
* @brief          This function configure for one EMIOS hardware channel follow OPWMCB mode
* @details        This function:
*                   - Calculate the duty tick follow nPeriod tick and Duty cycle
*                   - disables the interrupt and clears the interrupt flags
*                   - sets the regA register with value nPeriod+1 and regB register with 0 for 0% dutycycle
*                   - sets the regA register with value 1 and regB register with 0 for 100% dutycycle
*                   - for dutycycle not equal to 0% and 100% set the regA with values indicate dutycycle 
*                     and regB with values indicate deadtime. In this case the period is indicated 
*                     by regA of master bus
*                   - In 0% duty, we need correction duty when user switch 100% duty to 0 duty. In
*                     this case, the regA is switched from 1 value to nPeriod+1 value, so the match A
*                     may be never occur, so the output will be keep the old level. In this case, we
*                     need force match by set the FORCE_MATCH_A bit or FORCE_MATCH_B, follow the mode 
*                     is Lead Dead Time or Trail Dead Time
*                   - If notification is needed, setup EDGE selection with configuration of notification
*                   - If come from IDLE state or Un-Init state :
*                       + Write to RegControl with OPMCB mode
*                       + If dutycycle = 100%, when enter mode, EDPOL bit get complement of polarity 
*                         after that, EDPOL bit is restored valid value
*                       + Else, polarity and mode bits is writen into Cn simultaneously
*                   - Reset counter to value 0, because in OPWMCB mode, internal counter alway start from 0
*                   - Enable prescaler and start counter
*
* @param[in]      nPeriod               - Pwm signal period value
* @param[in]      u16DutyCycle          - Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]      peMiosChannelConfig   - Pointer to channel configuration data
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMCB_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
)
{
    VAR(Pwm_eMios_ControlType,      AUTOMATIC) u32CtrlRegVal;
    VAR(Pwm_PeriodType,             AUTOMATIC) nTempDuty;
    VAR(Pwm_PeriodType,             AUTOMATIC) nRegDuty;
    VAR(Pwm_PeriodType,             AUTOMATIC) nRegDeadtime;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx;
    VAR(uint32,                     AUTOMATIC) u32DutyCorrection;
    VAR(uint8 ,                     AUTOMATIC) u8HwChannel;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8,                      AUTOMATIC) u8Notification;
#endif

    u8HwChannel = (uint8)peMiosChannelConfig->u8HwChannel;

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    u8Notification =  Pwm_eMios_aChannelNotifType[(Pwm_eMios_ChannelType)u8HwChannel];
#endif

    u8mIdx      = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8chIdx     = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;

#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
    nTempDuty   = Pwm_eMios_ComputeDutycycle_16bits(nPeriod, u16DutyCycle);
#else
    nTempDuty   = Pwm_eMios_ComputeDutycycle_32bits(nPeriod, u16DutyCycle);
#endif

    /*divide by 2 and increment with 1 as counter always starts at 1 */
    nPeriod = (nPeriod >> (Pwm_PeriodType)1U) + 1U;

    /* when duty is computed to 1, the output channel should be put to 0%*/
    if((Pwm_PeriodType)1U == nTempDuty)
    {
        nTempDuty = (Pwm_PeriodType)0U;
        nRegDuty = (Pwm_PeriodType)0U;
    }
    else
    {
        nRegDuty = nTempDuty >> 1U;
    }

    nRegDeadtime = (peMiosChannelConfig->nPwmDeadTime);

    if (((uint16)0x0U == u16DutyCycle) || ((uint16)0x0U == nTempDuty))
    {
        /* disable and clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );

        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        u32DutyCorrection = REG_READ32(EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx));
        /* Write regA with value greater than period to generate 0% dutycycle*/
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (nPeriod + (uint32)1U), (uint32)nTempDuty);

        if(0x1U == u32DutyCorrection)
        {
            /*this statement is required to avoid limitation of 0% duty cycle(if call 100% to 0%)*/
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32((EMIOS_OUDR_ADDR32(u8mIdx)), (uint32)((uint32)1<<(u8chIdx)));
            if(PWM_MODE_OPWMCB_LEAD_DEADTIME_U32 == ((uint32)u32CtrlRegVal & CCR_MODE_MASK_U32))
            {
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMA_MASK_U32 );
            }
            else
            {
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32 );
            }
        }
    }
    else if (PWM_DUTY_CYCLE_100 == u16DutyCycle)
    {
        /* disable and clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /* Write regA with 1 to generate 100% dutycycle*/
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx,u8chIdx,(uint32)1U,(uint32)0U);
    }
    else
    {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        u8Notification =  Pwm_eMios_aChannelNotifType[u8HwChannel];
        if ((uint8)0U != u8Notification ) /* if notifications enabled */
        {
            /* FLAG event enabled */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        }
        else
        {
#endif
            /* disable and clear interrupt flag */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        }
#endif
        /* Write regA and regB with values indicate dutycycle and deadtime */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, ((uint32)nPeriod - (uint32)(nRegDuty)), (uint32)nRegDeadtime);
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    if ((uint8)0U != u8Notification ) /* if notifications enabled */
    {
        /* set notification edge in u32CtrlRegVal */
        if(PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)u8Notification)
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_SET32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_CLEAR32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
    }
#endif /* PWM_NOTIFICATION_SUPPORTED */
    
    /* come from Idle or Un-init state */
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
        /* Handling the EDPOL bit and mode to Control register */
        Pwm_eMios_HandlePolarityBit(Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx], u16DutyCycle, u8mIdx, u8chIdx, u32CtrlRegVal);
        /* set internal counter value to 1 - internal counter only used in OPWFMB mode for now */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CCNTR_ADDR32(u8mIdx, (uint32)u8chIdx) , 0U);
        /* set the prescaler divide value */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPRE_MASK_U32, u32CtrlRegVal & CCR_UCPRE_MASK_U32);
        /* enable prescaler - this will start the internal counter */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPREN_MASK_U32 );
    }
}
#endif /*PWM_FEATURE_OPWMCB*/


/*===============================================================================================*/
/**
* @brief          This function configure for one EMIOS hardware channel follow DAOC mode
* @details        This function:
*                   - Note: In DAOC mode, at the end of period, the regA and regB need re-calculated to
*                     enable next match A. This calculation and first pulse must be done by software
*                   - Calculate the duty tick follow nPeriod tick and Duty cycle
*                   - Alway enable interrupt. Because in this mode, the regA and regB is re-calculated
*                     with period and duty at the end of period by software
*                   - If come from IDLE state or Un-Init state :
*                       + If dutycycle = 100%, when enter mode, EDPOL bit get complement of polarity 
*                         after that, EDPOL bit is restored valid value
*                       + Else, polarity and mode bits is writen into Cn simultaneously
*                   - With 0% duty:
*                       + Force match B to generate first pulse
*                       + Write regA with 1 value and regB with nTempDuty + 1
*                       + Set EDPOL bit follow polarity of channel
*                   - With 100% duty:
*                       + Force match A to generate first pulse
*                       + Write regA and regB with same value and not equal 0
*                       + Set EDPOL bit follow polarity of channel
*                   - If not equal 0% and 100%:
*                       + To generate first pulse
*                           * If IdleState same Polarity, force match A
*                           * If IdleState not equal Polarity, force match B
*                       + set the regA with 1 values and set regB to nTempDuty + 1
*                       + Set EDPOL bit follow polarity of channel
*                   - Reset counter to value 0, because in OPWMCB mode, counter alway start from 0
*                   - Enable prescaler and start counter
*
* @param[in]      nPeriod               - Pwm signal period value
* @param[in]      u16DutyCycle          - Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]      peMiosChannelConfig   - Pointer to channel configuration data
*
* @return         void
*
*/
#if (PWM_FEATURE_DAOC == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_DAOC_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
)
{
    VAR(Pwm_eMios_ControlType,      AUTOMATIC) u32CtrlRegVal;
    VAR(Pwm_PeriodType,             AUTOMATIC) nTempDuty = 0U;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx; /*  assigned eMIOS HW channel index */
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx; /*  assigned eMIOS HW channel index */
    VAR(uint32,                     AUTOMATIC) u32RegAValue;
    VAR(uint32,                     AUTOMATIC) u32PolarityBit;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8,                      AUTOMATIC) u8Notification;
#endif
    VAR(uint8 ,                     AUTOMATIC) u8HwChannel;

    u8HwChannel = (uint8)peMiosChannelConfig->u8HwChannel;

    u8mIdx      = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8chIdx     = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;

#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
    nTempDuty   = Pwm_eMios_ComputeDutycycle_16bits(nPeriod, u16DutyCycle);
#else
    nTempDuty   = Pwm_eMios_ComputeDutycycle_32bits(nPeriod, u16DutyCycle);
#endif
    
    if (PWM_HIGH == Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx])
    {
        u32PolarityBit = (uint32)0x80;
    } 
    else
    {
        u32PolarityBit = (uint32)0;
    }
    
    /* FLAG event enabled */
    /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );

    /* come from Idle or Uninit state */
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
        /* Handling the EDPOL bit and mode to Control register */
        Pwm_eMios_HandlePolarityBit(Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx], u16DutyCycle, u8mIdx, u8chIdx, u32CtrlRegVal);
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        u8Notification =  Pwm_eMios_aChannelNotifType[(Pwm_eMios_ChannelType)u8HwChannel];
        if ((uint8)0U != u8Notification ) /* if notifications enabled */
        {
            /* set notification edge in u32CtrlRegVal */
            if(PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)u8Notification)
            {
                /* notification on both edges */
                /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
                REG_BIT_SET32(&u32CtrlRegVal, CCR_DAOC_MODE_EDGE_SELECT_MASK_U32 );
            }
            else
            {
                /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
                REG_BIT_CLEAR32(&u32CtrlRegVal, CCR_DAOC_MODE_EDGE_SELECT_MASK_U32 );
            }
        }
#endif /* PWM_NOTIFICATION_SUPPORTED */
    }

    if (((uint16)0x0U == u16DutyCycle) || ((uint16)0x0U == nTempDuty))
    {
        Pwm_eMios_aDaocChannelDuty[u8HwChannel] = (uint16)0U;
        /* force match B */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32 );

        /* write regA and regB with 1 to genenate 0% duty */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)1U, ((uint32)nTempDuty + (uint32)1U));

        /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), (CCR_EDPOL_MASK_U32), ((u32PolarityBit) & CCR_EDPOL_MASK_U32));
    }
    else if (PWM_DUTY_CYCLE_100 == u16DutyCycle)
    {
        Pwm_eMios_aDaocChannelDuty[u8HwChannel] = (uint16)0U;
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMA_MASK_U32 );
        
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        u32RegAValue = ((Pwm_eMios_aChannelPeriod[u8HwChannel] +
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_READ32( EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx))) % Pwm_DAOC_aChannelModulo[u8HwChannel]);
        if ((uint32)0 != u32RegAValue)
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32( EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx) ,  u32RegAValue);
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32( EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx) ,  u32RegAValue);
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32( EMIOS_CADR_ADDR32(u8mIdx,(uint32)u8chIdx),Pwm_DAOC_aChannelModulo[u8HwChannel]);
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32( EMIOS_CBDR_ADDR32(u8mIdx,(uint32)u8chIdx),Pwm_DAOC_aChannelModulo[u8HwChannel]);
        }
        /* Invert the EDGE POLARITY in control register */
        /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), (CCR_EDPOL_MASK_U32), ((~u32PolarityBit) & CCR_EDPOL_MASK_U32));
    }
    else
    {
        Pwm_eMios_aDaocChannelDuty[u8HwChannel] = (uint16)nTempDuty;
        if(Pwm_eMios_aChannelIdleState[u8eMiosChannelIdx] == Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx])
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMA_MASK_U32 );
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32 );
        }
        
        /* write regA with 1, write regB with calculated value of duty plus one */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)1U, ((uint32)nTempDuty + (uint32)1U));

        /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), (CCR_EDPOL_MASK_U32), ((u32PolarityBit) & CCR_EDPOL_MASK_U32));
    }
}
#endif /*PWM_FEATURE_DAOC*/

/*================================================================================================*/
/**
* @brief          This function configure for one EMIOS hardware channel follow OPWMT mode
* @details        This function:
*                   - With 0% duty:
*                       + If come from IDLE state or Un-Init state, set regA and regB to same 1 value
*                       + If not, set regB to same the current value of regA
*                   - With 100% duty:
*                       + If come from IDLE state or Un-Init state, set regA and regB to same 1 value
*                       + If not, set regB with nPeriod + 1
*                   - If not equal 0% and 100%:
*                       + Set regA with Offset + 1 and set regB follow the current of offset and the
*                         current of duty
*                   - If notification is needed, setup EDGE selection with configuration of notification
*                   - If come from IDLE state or Un-Init state :
*                       + Enable interrupt to enable trigger
*                       + Write to RegControl with OPMCB mode
*                       + If dutycycle = 100%, when enter mode, EDPOL bit get complement of polarity 
*                         after that, EDPOL bit is restored valid value
*                       + Else, polarity and mode bits is writen into Cn simultaneously
*                   - To generate first edge
*                       + If duty = 0%, force match B
*                       + If duty not equal 0%, force match A
*
* @param[in]      nPeriod               - Pwm signal period value
* @param[in]      u16DutyCycle          - Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]      peMiosChannelConfig   - Pointer to channel configuration data

* @return         void
*
*/
#if (PWM_FEATURE_OPWMT == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMT_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
)
{
    VAR(Pwm_eMios_ControlType,      AUTOMATIC) u32CtrlRegVal;
    VAR(Pwm_PeriodType,             AUTOMATIC) nTempDuty;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx;
#if (PWM_CHANGE_REGISTER_A_SWITCH == STD_ON)
    VAR(uint16,                     AUTOMATIC) u16TempRegB;
#endif
    VAR(uint32,                     AUTOMATIC) u32RegBValue;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8,   AUTOMATIC) u8Notification;
#endif
#if (PWM_CHANGE_REGISTER_A_SWITCH == STD_OFF)
    VAR(uint32,                     AUTOMATIC) u32TempDutyOffset;
#endif
    VAR(uint8 ,                     AUTOMATIC) u8HwChannel;

    u8HwChannel = (uint8)peMiosChannelConfig->u8HwChannel;
    
    u8mIdx      = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8chIdx     = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;

#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
    nTempDuty   = Pwm_eMios_ComputeDutycycle_16bits(nPeriod, u16DutyCycle);
#else
    nTempDuty   = Pwm_eMios_ComputeDutycycle_32bits(nPeriod, u16DutyCycle);
#endif

    if (((uint16)0x0U == u16DutyCycle) || ((uint16)0x0U == nTempDuty))
    {
        /* come from Idle and Uninit state */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
        {
            /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
            /* write regA and regB with the same value to achieve 0% duty */
            Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)1U, (uint32)1U);
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            u32RegBValue = REG_READ32(EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx));
            /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
            Pwm_eMios_UpdateChannelB(u8mIdx, u8chIdx, u32RegBValue);
        }
    }
    else if (PWM_DUTY_CYCLE_100 == u16DutyCycle)
    {
        /* come from Idle and Uninit state */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
        {
            /* write regB with the value greater than nPriod to achieve 100% duty */
            /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
            Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)1U, (uint32)(nPeriod+(uint32)1U));
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
            Pwm_eMios_UpdateChannelB(u8mIdx, u8chIdx, (uint32)(nPeriod+(uint32)1U));
        }
    }
    else
    {
#if (PWM_CHANGE_REGISTER_A_SWITCH == STD_ON)
        /* Calculate the B-register value */
        if ((uint16)0 != (uint16)peMiosChannelConfig->nPwmOffset)
        {
            u16TempRegB = ( (uint16)nPeriod - (uint16)peMiosChannelConfig->nPwmOffset ) + (uint16)1U;
        }
        else
        {
            u16TempRegB = (uint16)1U;
        }

        /* Calculate the A-register value */
        if (u16TempRegB > nTempDuty)
        {
            nTempDuty = u16TempRegB - nTempDuty;
        }
        else
        {
            /* @violates @ref Pwm_eMIOS_C_REF_2 Implicit conversion of integer to smaller type */
            nTempDuty = ((uint16)nPeriod - (uint16)nTempDuty) + (uint16)1U;
        }
        /* write regA with the calculated of dutyoffset and regB with the calculated of offset */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)nTempDuty, (uint32)u16TempRegB);
#else /* PWM_CHANGE_REGISTER_A_SWITCH */
        /* register B is updated on dutycycle change */
        u32TempDutyOffset = ( (uint32)nTempDuty + peMiosChannelConfig->nPwmOffset ) % nPeriod ;
        /* write regA with the calculated value of offset and regB with calculated value of dutyoffset */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx,(uint32)(peMiosChannelConfig->nPwmOffset)+(uint32)1U, (uint32)u32TempDutyOffset+(uint32)1U);
#endif /* PWM_CHANGE_REGISTER_A_SWITCH */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_ALTA_ADDR32(u8mIdx, u8chIdx), (uint32)(Pwm_eMios_aTriggerDelay[u8eMiosChannelIdx] + (uint32)1U));
    }
    /* come from Idle and Uninit state */
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_DMA_MASK_U32 );
        /* FLAG event enabled */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    u8Notification =  Pwm_eMios_aChannelNotifType[(Pwm_eMios_ChannelType)u8HwChannel];
    if ((uint8)0U != u8Notification ) /* if notifications enabled */
    {
        /* set notification edge in u32CtrlRegVal */
        if(PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)u8Notification)
        {
            /* notification on both edges */
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_SET32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_CLEAR32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
    }
#endif /* PWM_NOTIFICATION_SUPPORTED */

    /* come from Idle and Uninit state */
    /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
        /* Handling the EDPOL bit and mode to Control register */
        Pwm_eMios_HandlePolarityBit(Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx], u16DutyCycle, u8mIdx, u8chIdx, u32CtrlRegVal);
        /* force match on the first edge - this also sets the signal level */
        if (((uint16)0x0000 != u16DutyCycle) && (0x0U != nTempDuty))
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMA_MASK_U32); /* force match A */
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32 ); /* force match B */
        }
    }
}
#endif /*PWM_FEATURE_OPWMT*/

/*===============================================================================================*/
/**
* @brief          This function configure for one EMIOS hardware channel follow OPWMB mode
* @details        This function:
*                   - With 0% duty:
*                       + Disable and clear interrup flag
*                       + Set regA and regB with same value 0
*                   - With 100% duty:
*                       + Disable and clear interrup flag
*                       + Set regA with 0 value and regB with nPeriod value
*                   - If not equal 0% and 100%:
*                       + Enable interrupt if notification is enabled
*                       + Set regA with Offset and set regB follow the current of offset and the
*                         current of duty
*                   - If notification is needed, setup EDGE selection with configuration of notification
*                   - If come from IDLE state or Un-Init state :
*                       + Write to RegControl with OPWMB mode
*                       + If dutycycle = 100%, when enter mode, EDPOL bit get complement of polarity 
*                         after that, EDPOL bit is restored valid value
*                       + Else, polarity and mode bits is writen into Cn simultaneously
*                   - To generate first edge
*                       + If duty = 0%, force match B
*                       + If duty not equal 0%, force match A
*
* @param[in]      nPeriod               - Pwm signal period value
* @param[in]      u16DutyCycle          - Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]      peMiosChannelConfig   - Pointer to channel configuration data

* @return         void
*
*/
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMB_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
)
{
    VAR(Pwm_eMios_ControlType,      AUTOMATIC) u32CtrlRegVal;
    VAR(Pwm_PeriodType,             AUTOMATIC) nTempDuty;
    VAR(Pwm_PeriodType,             AUTOMATIC) nOffset;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx;
    VAR(uint32,                     AUTOMATIC) u32PolarityBit;
    VAR(uint32,                     AUTOMATIC) u32TempDutyOffset;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8,   AUTOMATIC) u8Notification;
#endif
    VAR(uint8 ,                     AUTOMATIC) u8HwChannel;

    u8HwChannel = (uint8)peMiosChannelConfig->u8HwChannel;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    u8Notification =  Pwm_eMios_aChannelNotifType[(Pwm_eMios_ChannelType)u8HwChannel];
#endif

    u8mIdx      = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8chIdx     = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;
    nOffset     = Pwm_eMios_aChannelOffset[u8eMiosChannelIdx];

#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
    nTempDuty   = Pwm_eMios_ComputeDutycycle_16bits(nPeriod, u16DutyCycle);
#else
    nTempDuty   = Pwm_eMios_ComputeDutycycle_32bits(nPeriod, u16DutyCycle);
#endif

    if (((uint16)0x0U == u16DutyCycle) || ((uint16)0x0U == nTempDuty))
    {
        /* disable and clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /* write 0 to regA and regB to generate 0% duty */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)0U, (uint32)0U);
    }
    else if (PWM_DUTY_CYCLE_100 == u16DutyCycle)
    {
        /* disable and clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /* write regA with 0 and regB with nPeriod to achieve 100% duty */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)0U, (uint32)nPeriod);
    }
    else
    {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        u8Notification =  Pwm_eMios_aChannelNotifType[u8HwChannel];
        if ((uint8)0U != u8Notification ) /* if notifications enabled */
        {
            /* FLAG event enabled */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        }
        else
        {
#endif
            /* disable and clear interrupt flag */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        }
#endif
        u32TempDutyOffset = (uint32)nTempDuty + nOffset;
        /* write regA with offset and regB with dutyoffset has been calculated */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)nOffset, (uint32)u32TempDutyOffset);
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    if ((uint8)0U != u8Notification ) /* if notifications enabled */
    {
        /* set notification edge in u32CtrlRegVal */
        if(PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)u8Notification)
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_SET32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_CLEAR32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
    }
#endif /* PWM_NOTIFICATION_SUPPORTED */
    
    /* come from Idle or Uninit state */
    /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
        if (PWM_HIGH == Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx])
        {
            u32PolarityBit = (uint32)0x80;
        } 
        else
        {
            u32PolarityBit = (uint32)0;
        }
        REG_RMW32
        (
            EMIOS_CCR_ADDR32(u8mIdx, u8chIdx),
            (CCR_MODE_MASK_U32 | CCR_EDPOL_MASK_U32),
            ((u32CtrlRegVal & CCR_MODE_MASK_U32) | (u32PolarityBit & CCR_EDPOL_MASK_U32 ))
        /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        );
        /* force match on the first edge - this also sets the signal level */
        /* do not force event A for OPWMB/OPWMT and 0% duty */
        if (((uint16)0x0000 != u16DutyCycle) && (0x0U != nTempDuty))
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMA_MASK_U32); /* force match A */
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32 ); /* force match B */
        }
    }
}

/*================================================================================================*/
/**
* @brief          This function configure for one EMIOS hardware channel follow OPWM mode
* @details        This function:
*                   - With 0% duty:
*                       + Disable and clear interrup flag
*                       + Set regA and regB with same value 0
*                   - With 100% duty:
*                       + Disable and clear interrup flag
*                       + Set regA and regB with same nPeriod - 1
*                   - If not equal 0% and 100%:
*                       + Enable interrupt if notification is enabled
*                       + Set regA with Offset and set regB follow the current of offset and the
*                         current of duty
*                   - If notification is needed, setup EDGE selection with configuration of notification
*                   - If come from IDLE state or Un-Init state :
*                       + Write to RegControl with OPWM mode
*                       + If dutycycle = 100%, when enter mode, EDPOL bit get complement of polarity 
*                         after that, EDPOL bit is restored valid value
*                       + Else, polarity and mode bits is writen into Cn simultaneously
*                   - To generate first edge
*                       + If duty = 0%, force match B
*                       + If duty not equal 0%, force match A
*
* @param[in]      nPeriod               - Pwm signal period value
* @param[in]      u16DutyCycle          - Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]      peMiosChannelConfig   - Pointer to channel configuration data

* @return         void
*
*/
#if (PWM_FEATURE_OPWM == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWM_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
)
{
    VAR(Pwm_eMios_ControlType,      AUTOMATIC) u32CtrlRegVal;
    VAR(Pwm_PeriodType,             AUTOMATIC) nTempDuty;
    VAR(Pwm_PeriodType,             AUTOMATIC) nOffset;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx;
    VAR(uint32,                     AUTOMATIC) u32TempDutyOffset;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8,                      AUTOMATIC) u8Notification;
#endif
    VAR(uint8 ,                     AUTOMATIC) u8HwChannel;

    u8HwChannel = (uint8)peMiosChannelConfig->u8HwChannel;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    u8Notification =  Pwm_eMios_aChannelNotifType[(Pwm_eMios_ChannelType)u8HwChannel];
#endif

    u8mIdx      = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8chIdx     = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;
    nOffset     = Pwm_eMios_aChannelOffset[u8eMiosChannelIdx];

#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
    nTempDuty   = Pwm_eMios_ComputeDutycycle_16bits(nPeriod - (Pwm_PeriodType)1U, u16DutyCycle);
#else
    nTempDuty   = Pwm_eMios_ComputeDutycycle_32bits(nPeriod - (Pwm_PeriodType)1U, u16DutyCycle);
#endif

    if (((uint16)0x0U == u16DutyCycle) || ((uint16)0x0U == nTempDuty))
    {
        /* disable and clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /* write regA with 0 to achieve 0% duty */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)0U, (uint32)0U);
    }
    else if (PWM_DUTY_CYCLE_100 == u16DutyCycle)
    {
        /* disable and clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        /* write regA and regB with the same values to achieve 100% duty */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)nPeriod - (uint32)1U, (uint32)nPeriod - (uint32)1U);
    }
    else
    {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        u8Notification =  Pwm_eMios_aChannelNotifType[u8HwChannel];
        if ((uint8)0U != u8Notification ) /* if notifications enabled */
        {
            /* FLAG event enabled */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        }
        else
        {
#endif
            /* disable and clear interrupt flag */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        }
#endif
        /* It is imposible to write 0 to register A, because match even does not occur. 
            So nOffset must be plus one before write to register A*/
        nOffset = nOffset + (Pwm_PeriodType)1U;
        u32TempDutyOffset = (uint32)nTempDuty + nOffset;
        /* write regA with the calculated value of offset and regB with calculated value of dutyoffset */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)nOffset, (uint32)u32TempDutyOffset);
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    if ((uint8)0U != u8Notification ) /* if notifications enabled */
    {
        /* set notification edge in u32CtrlRegVal */
        if(PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)u8Notification)
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_SET32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_CLEAR32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
    }
#endif /* PWM_NOTIFICATION_SUPPORTED */
    
    /* come from Idle or Uninit state */
    /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
        /* Handling the EDPOL bit and mode to Control register */
        Pwm_eMios_HandlePolarityBit(Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx], u16DutyCycle, u8mIdx, u8chIdx, u32CtrlRegVal);
        /* force match on the first edge - this also sets the signal level */
        /* do not force event A for OPWMB/OPWMT and 0% duty */
        if (((uint16)0x0000 != u16DutyCycle) && (0x0U != nTempDuty))
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMA_MASK_U32); /* force match A */
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32 ); /* force match B */
        }
    }
}
#endif /*PWM_FEATURE_OPWM*/
/*================================================================================================*/
/**
* @brief          This function configure for one EMIOS hardware channel follow OPWFMB mode
* @details        This function:
*                   - With 0% duty:
*                       + Disable and clear interrup flag
*                       + Set regA and regB with same nPeriod value
*                   - With 100% duty:
*                       + Disable and clear interrup flag
*                       + Set regA with 0 value and regB with nPeriod
*                   - If not equal 0% and 100%:
*                       + Enable interrupt if notification is enabled
*                       + Set regB with nPeriod and regA with Duty
*                   - If notification is needed, setup EDGE selection with configuration of notification
*                   - If come from IDLE state or Un-Init state :
*                       + Write to RegControl with OPWFMB mode
*                   - Force match B to generate first edge
*                   - Enable prescaler and start internal counter
*
* @param[in]      nPeriod               - Pwm signal period value
* @param[in]      u16DutyCycle          - Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]      peMiosChannelConfig   - Pointer to channel configuration data

* @return         void
*
*/
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMFMB_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
)
{
    VAR(Pwm_eMios_ControlType,      AUTOMATIC) u32CtrlRegVal;
    VAR(Pwm_PeriodType,             AUTOMATIC) nTempDuty;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx; /*  assigned eMIOS HW channel index */
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx; /*  assigned eMIOS HW channel index */
    VAR(uint32,                     AUTOMATIC) u32PolarityBit;  /*status of polarity bit */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8,   AUTOMATIC) u8Notification;
#endif
    VAR(uint8 ,                     AUTOMATIC) u8HwChannel;

    u8HwChannel = (uint8)peMiosChannelConfig->u8HwChannel;

#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    u8Notification =  Pwm_eMios_aChannelNotifType[(Pwm_eMios_ChannelType)u8HwChannel];
#endif

    u8mIdx      = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8chIdx     = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;

#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
    nTempDuty   = Pwm_eMios_ComputeDutycycle_16bits(nPeriod, u16DutyCycle);
#else
    nTempDuty   = Pwm_eMios_ComputeDutycycle_32bits(nPeriod, u16DutyCycle);
#endif

    if (((uint16)0x0U == u16DutyCycle) || ((uint16)0x0U == nTempDuty))
    {
        /* clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /* write regA and regB with nPeriod to achieve 0% duty*/
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)nPeriod, (uint32)nPeriod);
    }
    else if (PWM_DUTY_CYCLE_100 == u16DutyCycle)
    {
        /* clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /* write regA with 0 and regB with nPeriod to achieve 100% duty */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)0U, (uint32)nPeriod);
    }
    else
    {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        u8Notification =  Pwm_eMios_aChannelNotifType[u8HwChannel];
        if ((uint8)0U != u8Notification ) /* if notifications enabled */
        {
            /* FLAG event enabled */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        }
        else
        {
#endif /* PWM_NOTIFICATION_SUPPORTED */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
            /* clear interrupt flag */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        }
#endif
        /** @violates @ref Pwm_eMIOS_C_REF_4 Implicit conversion changes signedness */
        nTempDuty = nPeriod - nTempDuty;
        /* write regA with calculated value of duty and regB with period */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)nTempDuty, (uint32)nPeriod);
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    if ((uint8)0U != u8Notification ) /* if notifications enabled */
    {
        /* set notification edge in u32CtrlRegVal */
        if(PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)u8Notification)
        {
            /* notification on both edges */
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_SET32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_CLEAR32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
    }
#endif /* PWM_NOTIFICATION_SUPPORTED */
    
    /* come from Idle or Uninit State */
    /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CCNTR_ADDR32(u8mIdx, (uint32)u8chIdx) , 1U);

        if (PWM_HIGH == Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx])
        {
            u32PolarityBit = (uint32)0x80;
        } 
        else
        {
            u32PolarityBit = (uint32)0;
        }

        
        REG_RMW32
        (
            EMIOS_CCR_ADDR32(u8mIdx, u8chIdx),
            (CCR_MODE_MASK_U32 | CCR_EDPOL_MASK_U32),
            ((u32CtrlRegVal & CCR_MODE_MASK_U32) | ((u32PolarityBit) & CCR_EDPOL_MASK_U32 ))
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        );
        
        /* force match on the first edge - this also sets the signal level */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32);
        
        /* set the prescaler divide value */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPRE_MASK_U32, u32CtrlRegVal & CCR_UCPRE_MASK_U32);
        /* enable prescaler - this will start the internal counter */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPREN_MASK_U32 );
    }
}

/*================================================================================================*/
/**
* @brief          This function configure for one EMIOS hardware channel follow OPWFM mode
* @details        This function:
*                   - With 0% duty:
*                       + Disable and clear interrup flag
*                       + Set regA and regB with same 0 value
*                   - With 100% duty:
*                       + Disable and clear interrup flag
*                       + Set regA and regB with same nPeriod - 1 value
*                   - If not equal 0% and 100%:
*                       + Enable interrupt if notification is enabled
*                       + Set regB with nPeriod - 1 and regA with Duty
*                   - If notification is needed, setup EDGE selection with configuration of notification
*                   - If come from IDLE state or Un-Init state :
*                       + Write to RegControl with OPWFM mode
*                       + If dutycycle = 100%, when enter mode, EDPOL bit get complement of polarity 
*                         after that, EDPOL bit is restored valid value
*                       + Else, polarity and mode bits is writen into Cn simultaneously
*                   - Force match B to generate first edge
*                   - Enable prescaler and start internal counter
*
* @param[in]      nPeriod               - Pwm signal period value
* @param[in]      u16DutyCycle          - Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]      peMiosChannelConfig   - Pointer to channel configuration data

* @return         void
*
*/
#if (PWM_FEATURE_OPWFM == STD_ON)
LOCAL_INLINE FUNC(void, PWM_CODE) Pwm_eMios_SetRegs_OPWMFM_mode
(
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                   u8eMiosChannelIdx,
    VAR(Pwm_PeriodType,                     AUTOMATIC)                   nPeriod,
    VAR(uint16,                             AUTOMATIC)                   u16DutyCycle,
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,  PWM_APPL_CONST)  peMiosChannelConfig
)
{
    VAR(Pwm_eMios_ControlType,      AUTOMATIC) u32CtrlRegVal;
    VAR(Pwm_PeriodType,             AUTOMATIC) nTempDuty = 0U;
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8mIdx; /*  assigned eMIOS HW channel index */
    VAR(Pwm_eMios_ChannelType,      AUTOMATIC) u8chIdx; /*  assigned eMIOS HW channel index */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8,   AUTOMATIC) u8Notification;
#endif
    VAR(uint8 ,                     AUTOMATIC) u8HwChannel;

    u8HwChannel = (uint8)peMiosChannelConfig->u8HwChannel;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    u8Notification =  Pwm_eMios_aChannelNotifType[(Pwm_eMios_ChannelType)u8HwChannel];
#endif

    u8mIdx      = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8chIdx     = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;

#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
    nTempDuty   = Pwm_eMios_ComputeDutycycle_16bits(nPeriod, u16DutyCycle);
#else
    nTempDuty   = Pwm_eMios_ComputeDutycycle_32bits(nPeriod, u16DutyCycle);
#endif

    if (((uint16)0x0U == u16DutyCycle) || ((uint16)0x0U == nTempDuty))
    {
        /* clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /* write regA with 0 to achieve 0% duty */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)0U, (uint32)0U);
    }
    else if (PWM_DUTY_CYCLE_100 == u16DutyCycle)
    {
        /* clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
        /* write regA and regB with the same values to achieve 100& duty */
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)nPeriod - (uint32)1U, (uint32)nPeriod - (uint32)1U);
    }
    else
    {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        u8Notification =  Pwm_eMios_aChannelNotifType[u8HwChannel];
        if ((uint8)0U != u8Notification ) /* if notifications enabled */
        {
            /* FLAG event enabled */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        }
        else
        {
#endif /* PWM_NOTIFICATION_SUPPORTED */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
            /* clear interrupt flag */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx) , CSR_FLAG_BIT_U32 );
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        }
#endif
        nTempDuty = ((Pwm_PeriodType)nPeriod - (Pwm_PeriodType)nTempDuty) - (Pwm_PeriodType)1U;
        /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
        /* write regA with the calculated value of duty and regB with calculated value of period*/
        Pwm_eMios_UpdateChannelAB(u8mIdx, u8chIdx, (uint32)nTempDuty, (uint32)nPeriod - (uint32)1U);
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    if ((uint8)0U != u8Notification ) /* if notifications enabled */
    {
        /* set notification edge in u32CtrlRegVal */
        if(PWM_BOTH_EDGES == (Pwm_EdgeNotificationType)u8Notification)
        {
            /* notification on both edges */
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_SET32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_10 Cast from pointer to pointer.*/
            REG_BIT_CLEAR32(&u32CtrlRegVal, CCR_MODE_EDGE_SELECT_MASK_U32 );
        }
    }
#endif /* PWM_NOTIFICATION_SUPPORTED */
    
    /* come from Idle or Uninit State */
    /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 == (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CCNTR_ADDR32(u8mIdx, (uint32)u8chIdx) , 1U);
        /* Handling the EDPOL bit and mode to Control register */
        Pwm_eMios_HandlePolarityBit(Pwm_eMios_aChannelPolarity[u8eMiosChannelIdx], u16DutyCycle, u8mIdx, u8chIdx, u32CtrlRegVal);
        /* force match on the first edge - this also sets the signal level */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32);
        
        /* set the prescaler divide value */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPRE_MASK_U32, u32CtrlRegVal & CCR_UCPRE_MASK_U32);
        /* enable prescaler - this will start the internal counter */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPREN_MASK_U32 );
    }
}
#endif /*PWM_FEATURE_OPWFM*/

/*===============================================================================================*/
 #if  (PWM_EMIOS_16_BITS_VARIANT == STD_OFF)  &&  (PWM_SET_COUNTER_BUS_API == STD_ON)
/**
@brief   Function to get the division of 64 bit unsigned integers.
@details This function returns the division value of 64 bit unsigned integers.
@param[in] nNume - Numerator
@param[in] nDeno - Denominator
@return pwm_uint64 - division value of 64 bit unsigned integers.
*/
static FUNC(Pwm_uint64, PWM_CODE)Pwm_eMios_Div64
(
    VAR(Pwm_uint64, AUTOMATIC) nNume, 
    VAR(Pwm_uint64, AUTOMATIC) nDeno
)
{
    VAR(Pwm_uint64, AUTOMATIC) u64Mask;
    VAR(Pwm_uint64, AUTOMATIC) u64Temp;
    VAR(Pwm_uint64, AUTOMATIC) u64RetNumeric;
    VAR(uint32,  AUTOMATIC)    u32TempDeno;

    if (0ULL == nDeno) 
    {
        u64RetNumeric = ~(Pwm_uint64)0ULL;
    }
    else
    {
        if (0ULL == ((nDeno-1ULL) & nDeno))
        {
            /* Divide by power of 2. */
            u64RetNumeric = nNume;
            if(0ULL == (nDeno & 0x00000000ffffffffULL))
            {
                nDeno >>= 32U;
                u64RetNumeric >>= 32U;
            }
            u32TempDeno = (uint32)nDeno;
            if(0U == (u32TempDeno & 0xffffU))
            {
                u32TempDeno >>= 16U;
                u64RetNumeric >>= 16U;
            }
            if(0U == (u32TempDeno & 0xffU))
            {
                u32TempDeno >>= 8U;
                u64RetNumeric >>= 8U;
            }
            while (0U != (u32TempDeno >>= 1U))
            {
                u64RetNumeric >>= 1U;
            }
        } 
        /* @violates @ref Pwm_eMIOS_C_REF_14 Assignment operators shall not be used in expressions that 
        yield a Boolean value */
        else
        {
            u64Temp = nNume | nDeno;
            if(0ULL == (u64Temp & 0xffffffff00000000ULL))
            {
                /* @violates @ref Pwm_eMIOS_C_REF_6 Cast of complex integer expression to larger type */
                u64RetNumeric = (Pwm_uint64)((uint32)nNume/(uint32)nDeno);
            }
            else
            {
                u64Mask = 0xff00000000000000ULL;
                if (0ULL == (u64Temp & u64Mask)) {
                    u64Mask >>= 8U;
                    if ((u64Temp & u64Mask) == 0ULL) {
                        u64Mask >>= 8U;
                        if ((u64Temp & u64Mask) == 0ULL) {
                            u64Mask >>= 8U;
                        }
                    }
                }
                u32TempDeno = 0U;
                while ((nDeno & u64Mask) == 0ULL) {
                    nDeno <<= 8U;
                    u32TempDeno += 8U;
                }
                if(nNume & 0x8000000000000000ULL) {
                    while (0ULL == (nDeno & 0x8000000000000000ULL)) {
                        nDeno <<= 1U;
                        u32TempDeno++;
                    }
                    u64RetNumeric = 0ULL;
                    if (nNume >= nDeno) {
                        nNume -= nDeno;
                        u64RetNumeric |= 1ULL;
                    }
                } else {
                    while (nDeno <= nNume) {
                        nDeno <<= 1U;
                        u32TempDeno++;
                    }
                    u64RetNumeric = 0ULL;
                }
                while (u32TempDeno > 0U) {
                    u32TempDeno--;
                    nDeno >>= 1U;
                    u64RetNumeric <<= 1U;
                    if (nNume >= nDeno) {
                        nNume -= nDeno;
                        u64RetNumeric |= 1ULL;
                    }
                }
                u32TempDeno--;
            }
        }
    }
    return u64RetNumeric;
}
#endif

/*================================================================================================*/
#if ( \
        (PWM_FEATURE_OPWFM == STD_ON) || \
        (PWM_FEATURE_OPWM == STD_ON) || \
        (PWM_FEATURE_DAOC == STD_ON) || \
        (PWM_FEATURE_OPWMT == STD_ON) || \
        (PWM_FEATURE_OPWMCB == STD_ON) \
    )
/**
* @brief          This function used to handling the EDPOL bit and mode bits
* @details        This function:
*                   - With ePolarity is HIGH, the u32PolarityBit shoule be set to 0x80 value, otherwise,
*                     the u32PolarityBit shoule be set to 0x0 value
                    - Write to RegControl with mode and polarity
*                   - If dutycycle = 100%, when enter mode, EDPOL bit get complement of polarity 
*                     after that, EDPOL bit is restored valid value
*                   - Else, polarity and mode bits is writen into Cn simultaneously
*
* @param[in]      ePolarity         - Polarity of Pwm channel
* @param[in]      u16DutyCycle      - Pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]      u8mIdx            - module index of emios channel
* @param[in]      u8chIdx           - channel index of emios channel
* @param[in]      u32CtrlRegVal       - eMios channel control parameters
*
* @return         void
*
*/
static FUNC(void, PWM_CODE)Pwm_eMios_HandlePolarityBit
(
    VAR(Pwm_OutputStateType,   AUTOMATIC) ePolarity,
    VAR(uint16,                AUTOMATIC) u16DutyCycle,
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx,
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx,
    VAR(Pwm_eMios_ControlType, AUTOMATIC) u32CtrlRegVal
)
{
    VAR(uint32,       AUTOMATIC) u32PolarityBit;

    if (PWM_HIGH == ePolarity)
    {
        u32PolarityBit = (uint32)0x80;
    } 
    else
    {
        u32PolarityBit = (uint32)0;
    }
    /** To avoid spike pulse 
           - If dutycycle = 100%, when enter mode, EDPOL bit get complement of polarity 
             after that, EDPOL bit is restored valid value
           - Else, polarity and mode bits is writen into Cn simultaneously
    */
    if (PWM_DUTY_CYCLE_100 == u16DutyCycle)
    {
        REG_RMW32
        (
            EMIOS_CCR_ADDR32(u8mIdx, u8chIdx),
            (CCR_MODE_MASK_U32 | CCR_EDPOL_MASK_U32),
            (u32CtrlRegVal & CCR_MODE_MASK_U32) | ((~u32PolarityBit) & CCR_EDPOL_MASK_U32 )
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        );
        REG_RMW32
        (
            EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_EDPOL_MASK_U32, u32PolarityBit & CCR_EDPOL_MASK_U32 
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        );
    }
    else
    {
        REG_RMW32
        (
            EMIOS_CCR_ADDR32(u8mIdx, u8chIdx),
            (CCR_MODE_MASK_U32 | CCR_EDPOL_MASK_U32),
            ((u32CtrlRegVal & CCR_MODE_MASK_U32) | (u32PolarityBit & CCR_EDPOL_MASK_U32 ))
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        );
    }
}
#endif

#define PWM_STOP_SEC_CODE
/** @violates @ref Pwm_eMIOS_C_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Header file being included twice */
#include "Pwm_MemMap.h"
/*===============================================================================================
*                                       GLOBAL FUNCTIONS
===============================================================================================*/
#define PWM_START_SEC_CODE
/** @violates @ref Pwm_eMIOS_C_REF_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Pwm_eMIOS_C_REF_8 Header file being included twice */
#include "Pwm_MemMap.h"

/**
* @brief   Service for initializing the hardware timer module (low level)
* @details This function initializes all the configured hardware channels as per the
*         configured mode
*         - puts the channel in GPIO mode
*         - disables the interrupt corresponding to Emios channel
*         - clear pending interrupt flag for the channel
*         - enables/disables the Freeze Mode
*         - clears the (pending) interrupt flag corresponding to Emios channel
*         - get the Period that the current UC is using and also calculates the dutycycle
*         - update registers A and B with the dutycycle and period value for the configured mode
*         - force a match on B register for OPWFMB mode
*         - force a match on A register for OPWMB and OPWMT modes
*         - write trigger delay to alternate A register for OPWMT mode and offset to A register
*           for OPWMB and OPWMT modes
*         - FLAG assigned to DMA request and FLAG event is enabled for OPWMT mode
*         - FLAG event is disabled for OPWMB and OPWFMB modes
*         - sets the prescaler value
*         - enable prescaler which will start the internal counter, for Counter Bus
* @param[in] ConfigPtr - pointer to PWM top configuration structure
*
*/

FUNC(void, PWM_CODE) Pwm_eMios_Init
(
    P2CONST(Pwm_eMios_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* @brief Pointer to eMIOS channel specific configuration */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;

    VAR(Pwm_eMios_ControlType, AUTOMATIC)   u32CtrlRegVal;
    
    VAR(Pwm_PeriodType,        AUTOMATIC)   nPeriod;
    VAR(uint16,                AUTOMATIC)   u16DutyCycle;

    /* logical channel */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8Counter;

    /* assigned eMIOS HW module index and channel index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8mIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8chIdx;

    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8MasterModule;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8MasterChannel;

    VAR(uint8,                 AUTOMATIC)   u8MasterBusIdx;
    VAR(uint8,                 AUTOMATIC)   aMasterBusMode[PWM_EMIOS_HW_CHANNELS_U8];
    VAR(uint32,                AUTOMATIC)   aPrescaler[PWM_EMIOS_HW_CHANNELS_U8];

    for (u8Counter=0U; u8Counter < (Pwm_eMios_ChannelType)PWM_EMIOS_HW_CHANNELS_U8; u8Counter++)
    {
        aMasterBusMode[u8Counter] = (uint8)0xFFU;
        
        aPrescaler[u8Counter] = (uint32)0;
    }

    for (u8Counter=0U; u8Counter < peMiosIpConfig->u8NumChannels; u8Counter++)
    {
        /* only handle EMIOS channels */
        /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8Counter];

        u8mIdx = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
        u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

        Pwm_eMios_aChannelPolarity[u8Counter] = peMiosChannelConfig->ePwmPolarity;

#if ((PWM_DE_INIT_API == STD_ON)||\
     (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)||\
    (PWM_FEATURE_DAOC == STD_ON))
        Pwm_eMios_aChannelIdleState[u8Counter] = peMiosChannelConfig->ePwmIdleState;
#endif
        u32CtrlRegVal  = peMiosChannelConfig->u32ControlValue;
        nPeriod      = peMiosChannelConfig->nPwmDefaultPeriod;
        u16DutyCycle = peMiosChannelConfig->u16PwmDefaultDutyCycle;

        u8MasterBusIdx = (uint8)Pwm_eMios_GetMasterBus(u8mIdx, u8chIdx, ((uint32)u32CtrlRegVal & CCR_BSL_MASK_U32));

#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
        eMios_StartChannel((uint8)peMiosChannelConfig->u8HwChannel);
    #endif  /* EMIOS_UCDIS_AVAILABLE */
#endif

        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FREN_MASK_U32, CCR_FREN_MASK_U32 & u32CtrlRegVal);
        
        /* before entering GPIO mode set the EDPOL bit to the configured IDLE value */
        if (PWM_HIGH == peMiosChannelConfig->ePwmIdleState)
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_EDPOL_MASK_U32);
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_EDPOL_MASK_U32 );
        }
        
        /* Enter GPIO output mode */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_MODE_MASK_U32, CCR_MODE_GPO_U32);
        /* Disable channel interrupts  */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32);
        /* Clear pending interrupt flag for the channel  */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx), CSR_FLAG_BIT_U32);

        /* store the nPeriod that the current UC is using */
        Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel] = nPeriod;
        
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
        /* store the dutycycle */
        Pwm_eMios_aChannelDuty[u8Counter] = u16DutyCycle;
#endif /*PWM_GET_CHANNEL_STATE_API */

        /* write selected bus to the control register */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_BSL_MASK_U32, u32CtrlRegVal & CCR_BSL_MASK_U32);

        if (PWM_BUS_INTERNAL_COUNTER_U32 == ((uint32)u32CtrlRegVal & CCR_BSL_MASK_U32))
        {
            /* This will stop the internal counterl  */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPREN_MASK_U32 );

            switch((u32CtrlRegVal & CCR_MODE_MASK_U32))
            {
            case PWM_MODE_OPWFMB_U32:
                Pwm_eMios_SetRegs_OPWMFMB_mode(u8Counter, nPeriod, u16DutyCycle, peMiosChannelConfig);
                break;
#if (PWM_FEATURE_OPWFM == STD_ON)
            case PWM_MODE_OPWFM_U32:
                Pwm_eMios_SetRegs_OPWMFM_mode(u8Counter, nPeriod, u16DutyCycle, peMiosChannelConfig);
                break;
#endif /*PWM_FEATURE_OPWFM*/
            default:
                break;
            }
        }
        else
        { /* Bus A or Bus Diverse */
            switch((u32CtrlRegVal & CCR_MODE_MASK_U32))
            {
#if (PWM_FEATURE_OPWMCB == STD_ON)   
            case PWM_MODE_OPWMCB_LEAD_DEADTIME_U32:
            case PWM_MODE_OPWMCB_TRAIL_DEADTIME_U32:
                /* store the nPeriod that the master UC is using */
                Pwm_eMios_aChannelPeriod[u8MasterBusIdx] = nPeriod;
                Pwm_eMios_SetRegs_OPWMCB_mode(u8Counter, nPeriod, u16DutyCycle, peMiosChannelConfig);
                break;
#endif
#if (PWM_FEATURE_DAOC == STD_ON)   
            case PWM_MODE_DAOC_U32:
                /* store the nPeriod that the master UC is using */
                Pwm_eMios_aChannelPeriod[u8MasterBusIdx] = peMiosChannelConfig->nPwmDaocModulo;
                /* store the modulo of DAOC channel */
                Pwm_DAOC_aChannelModulo[peMiosChannelConfig->u8HwChannel] = peMiosChannelConfig->nPwmDaocModulo;
                Pwm_eMios_SetRegs_DAOC_mode(u8Counter, nPeriod, u16DutyCycle, peMiosChannelConfig);
                break;
#endif
#if (PWM_FEATURE_OPWMT == STD_ON)   
            case PWM_MODE_OPWMT_U32:
                /* store the nPeriod that the master UC is using */
                Pwm_eMios_aChannelPeriod[u8MasterBusIdx] = nPeriod;
                /* store the Trigger Delay that the master UC is using */
                Pwm_eMios_aTriggerDelay[u8Counter] = peMiosChannelConfig->nPwmTriggerDelay;
                /* store the offset channel that the master UC is using */
                Pwm_eMios_aChannelOffset[u8Counter] = peMiosChannelConfig->nPwmOffset;
                Pwm_eMios_SetRegs_OPWMT_mode(u8Counter, nPeriod, u16DutyCycle, peMiosChannelConfig);
                break;
#endif
            case PWM_MODE_OPWMB_U32:
                /* store the nPeriod that the master UC is using */
                Pwm_eMios_aChannelPeriod[u8MasterBusIdx] = nPeriod;
                /* store the offset channel that the master UC is using */
                Pwm_eMios_aChannelOffset[u8Counter] = peMiosChannelConfig->nPwmOffset;
                Pwm_eMios_SetRegs_OPWMB_mode(u8Counter, nPeriod, u16DutyCycle, peMiosChannelConfig);
                break;
#if (PWM_FEATURE_OPWM == STD_ON) 
            case PWM_MODE_OPWM_U32:
                /* store the nPeriod that the master UC is using */
                Pwm_eMios_aChannelPeriod[u8MasterBusIdx] = nPeriod;
                /* store the offset channel that the master UC is using */
                Pwm_eMios_aChannelOffset[u8Counter] = peMiosChannelConfig->nPwmOffset;
                Pwm_eMios_SetRegs_OPWM_mode(u8Counter, nPeriod, u16DutyCycle, peMiosChannelConfig);
                break;
#endif /*PWM_FEATURE_OPWM*/
            default:
                break;
            }
            /** @violates @ref Pwm_eMIOS_C_REF_11 pointer arithmetic other than array indexing used */
            if((uint8)0xFFU == aMasterBusMode[u8MasterBusIdx]) /* This master bus have not been configed*/
            {
                /* store master bus mode and master bus prescaler*/
                aMasterBusMode[u8MasterBusIdx] = peMiosChannelConfig->u8MasterMode;
                aPrescaler[u8MasterBusIdx] = peMiosChannelConfig->u32ControlValue & CCR_UCPRE_MASK_U32;
                /* enable unified channel to make registers writeable */
#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
                eMios_StartChannel((uint8)u8MasterBusIdx);
    #endif  /* EMIOS_UCDIS_AVAILABLE */
#endif
            }
        }
        
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        if (((uint16)0x0000 == u16DutyCycle) || (PWM_DUTY_CYCLE_100 == u16DutyCycle))
        {
            /* no transitions in the signal */
            Pwm_eMios_aDutyState[u8mIdx] &= ~((uint32)1<< u8chIdx);
        }
        else
        {
            /* transitions available in the signal */
            Pwm_eMios_aDutyState[u8mIdx] |= ((uint32)1U<< u8chIdx);
        }
#endif /* PWM_NOTIFICATION_SUPPORTED */
    }

    /* configuration for master bus */
    for (u8Counter=0U; u8Counter < PWM_EMIOS_HW_CHANNELS_U8; u8Counter++)
    {
        /** @violates @ref Pwm_eMIOS_C_REF_11 pointer arithmetic other than array indexing used */
        if((uint8)0xFFU != aMasterBusMode[u8Counter]) /* Master bus is used */
        {
            u8MasterModule  = EMIOS_MODULE_INDEX_U8(u8Counter);
            u8MasterChannel = EMIOS_CHANNEL_INDEX_U8(u8Counter);

           /* enter GPIO output mode */
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_RMW32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), CCR_MODE_MASK_U32, CCR_MODE_GPO_U32);
            /* disable prescaler - this will stop the internal counter */
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), CCR_UCPREN_MASK_U32);
            /* update prescaler values*/
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_RMW32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), CCR_UCPRE_MASK_U32, aPrescaler[u8Counter]);

            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel),CCR_FEN_MASK_U32);
            /** @violates @ref Pwm_eMIOS_C_REF_11 pointer arithmetic other than array indexing used */
            switch(aMasterBusMode[u8Counter])
            {
            case MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32:
                /*Updated period value to EMIOSA register*/
                nPeriod = (Pwm_eMios_aChannelPeriod[u8Counter] >> (Pwm_PeriodType)1U) + 1U;
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CADR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), nPeriod);
                /* set internal counter to 1 */
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CCNTR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), (uint32)1U);
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */        
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_RMW32(EMIOS_CCR_ADDR32(u8MasterModule,(uint32)u8MasterChannel),CCR_MODE_MASK_U32,(MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32 & CCR_MODE_MASK_U32));
                break;
            case MASTER_MODE_UP_BUFFERED_COUNTER_U32:
                /*Updated period value to EMIOSA register*/
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CADR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), (Pwm_eMios_aChannelPeriod[u8Counter]));
                /* set internal counter to 1 */
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CCNTR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), (uint32)1U);
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */        
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_RMW32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), CCR_MODE_MASK_U32, (MASTER_MODE_UP_BUFFERED_COUNTER_U32 & CCR_MODE_MASK_U32));
                break;
            case MASTER_MODE_UP_COUNTER_U32:
                /*Updated period value to EMIOSA register*/
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CADR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), (Pwm_eMios_aChannelPeriod[u8Counter]) - (uint32)1U);
                /* set internal counter to 1 */
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CCNTR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), (uint32)0U);
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */    
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_RMW32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), CCR_MODE_MASK_U32, (MASTER_MODE_UP_COUNTER_U32 & CCR_MODE_MASK_U32)); 
                break;
            default:
                break;
            }
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel),CCR_UCPREN_MASK_U32);
        }
    }
}

/*===============================================================================================*/
#if (PWM_DE_INIT_API == STD_ON)
/**
* @brief   This function deinitializes all eMIOS channels assigned to PWM
* @details This function
*          - sets the channel output to the configured Idle state
*          - Reset Timer control register, Internal Counter, A, B registers
*          - clears the (pending) interrupt flag corresponding to Emios channel
*
*/
FUNC(void, PWM_CODE) Pwm_eMios_DeInit
(
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* @brief Pointer to EMIOS channel specific configuration */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8Counter = (Pwm_eMios_ChannelType ) 0;
    /*  assigned eMIOS HW module index and channel index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8MasterChannel;
    
    /* assigned eMIOS HW module  index */
    VAR(Pwm_eMios_ControlType, AUTOMATIC) u32CtrlRegVal;
    VAR(uint8, AUTOMATIC) u8MasterBusIdx = 0xFFU;
    VAR(uint8, AUTOMATIC) aMasterBusUse[PWM_EMIOS_HW_CHANNELS_U8];
    
    for (u8Counter=0U; u8Counter < (Pwm_eMios_ChannelType)PWM_EMIOS_HW_CHANNELS_U8; u8Counter++)
    {
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
        /* notifications disabled */
        Pwm_eMios_aChannelNotifType[u8Counter] = (uint8)0;
#endif

#if (PWM_FEATURE_DAOC == STD_ON)
        Pwm_eMios_aDaocChannelDuty[u8Counter] = (uint16)0x00;
        /* @violates @ref Pwm_eMIOS_C_REF_4 Implicit conversion changes signedness */
        Pwm_DAOC_aChannelModulo[u8Counter] = (Pwm_PeriodType)0x00;
#endif
         /*Set 0 for array used to store the current period for each pwm channel*/
        Pwm_eMios_aChannelPeriod[u8Counter] = (Pwm_PeriodType)0x00;

        aMasterBusUse[u8Counter] = (uint8)0xFFU;
    }
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    for(u8Counter=0U; u8Counter < PWM_EMIOS_HW_MODULES_CFG_U8; u8Counter++)
    {
        /*Set 0 for array used to store the current dutycycle state*/
        Pwm_eMios_aDutyState[u8Counter] = (uint32)0;
    }
#endif

    for (u8Counter=0U; u8Counter < peMiosIpConfig->u8NumChannels; u8Counter++)
    {
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
        Pwm_eMios_aChannelDuty[u8Counter] = (uint16)0U;
#endif /*PWM_GET_CHANNEL_STATE_API */
        Pwm_eMios_aChannelOffset[u8Counter] = (Pwm_PeriodType)0x00;
#if (PWM_FEATURE_OPWMT == STD_ON)
        /** @violates @ref Pwm_eMIOS_C_REF_4 Implicit conversion changes signedness */
        Pwm_eMios_aTriggerDelay[u8Counter] = (Pwm_PeriodType)0x00;
#endif
        /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8Counter];

        u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
        u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

        u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;

        /* set the channel output to the configured Idle state */
        if (PWM_HIGH == Pwm_eMios_aChannelIdleState[u8Counter])
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_EDPOL_MASK_U32 );
        }
        else
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_EDPOL_MASK_U32 );
        }
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx) , 0U );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx) , 0U );
        /* enter GPIO ouput mode - this will set the ouput pin to the EDPOL value */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_MODE_MASK_U32, CCR_MODE_GPO_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), (~(CCR_EDPOL_MASK_U32 | CCR_MODE_MASK_U32)) );
        /* disable interrupt */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
        /* clear interrupt flag */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx), CSR_FLAG_BIT_U32 );
        /* only write UCDIS register if it's available */
        /* disable unified channel */
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
        eMios_StopChannel((uint8)peMiosChannelConfig->u8HwChannel);
    #endif  /* EMIOS_UCDIS_AVAILABLE */
#endif

        /* if channel using master bus, so de-init for master bus */
        if (PWM_BUS_INTERNAL_COUNTER_U32 != ((uint32)u32CtrlRegVal & CCR_BSL_MASK_U32))
        {
            u8MasterBusIdx = (uint8)Pwm_eMios_GetMasterBus(u8mIdx, u8chIdx, ((uint32)u32CtrlRegVal & CCR_BSL_MASK_U32));
            u8MasterChannel = EMIOS_CHANNEL_INDEX_U8(u8MasterBusIdx);
            if((uint8)0xFFU == aMasterBusUse[u8MasterBusIdx])
            {
                aMasterBusUse[u8MasterBusIdx] = (uint8)1U;
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8MasterChannel) , 0U );
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8MasterChannel) , 0U );
                /* enter GPIO ouput mode - this will set the ouput pin to the EDPOL value */
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, (uint32)u8MasterChannel), CCR_MODE_MASK_U32, CCR_MODE_GPO_U32 );
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, (uint32)u8MasterChannel), (~(CCR_EDPOL_MASK_U32 | CCR_MODE_MASK_U32)));
                /* disable interrupt */
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, (uint32)u8MasterChannel), CCR_FEN_MASK_U32 );
                /* clear interrupt flag */
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, (uint32)u8MasterChannel), CSR_FLAG_BIT_U32 );
#ifdef EMIOS_UCDIS_AVAILABLE
    #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
                /* disable unified channel */
                eMios_StopChannel(u8MasterBusIdx);
    #endif  /* EMIOS_UCDIS_AVAILABLE */
#endif
            }
        }
    }
}
#endif /* PWM_DE_INIT_API */


/*===============================================================================================*/
#if ((PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_COUNTER_BUS_API == STD_ON))
/**
* @brief   This function sets the dutycycle for the specified eMIOS channel
* @details This function:
*          - disable the interrupt and clear the interrupt flag
*          - sets the A register with value 0 for OPWFMB mode for 0% dutycycle
*          - sets the A and B registers with value 0 for OPWMB mode for 0% dutycycle
*          - sets the A and B registers with value 1 for OPWMT mode for 0% dutycycle
*          - sets the A register with value period for OPWFMB mode for 100% dutycycle
*          - sets the A register with 0 and B register with period for OPWMB mode for
*            100% dutycycle
*          - sets the A register with 1 and B register with period+1 for OPWMT mode for
*            100% dutycycle
*          - for dutycycle not equal to 0% and 100%, FLAG event is enabled
*          - sets the A register with value dutycycle for OPWFMB mode
*          - sets the A register with value offset+1 and B register with dutycycle+offset
*            for OPWMB mode
*          - sets the A register with value offset+1 and B register with
*            (dutycycle + offset) % period for OPWMT mode
*
* @param[in]    u8IdxChannelConfig  - pwm channel id
* @param[in]    u16DutyCycle        - pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
* @param[in]    peMiosIpConfig      - pointer to EMIOS IP Config
*/
/* @violates @ref Pwm_eMIOS_C_REF_12 external could be made static */
FUNC(void, PWM_CODE) Pwm_eMios_SetDutyCycle
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    VAR(uint16,                          AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* @brief Pointer to EMIOS channel specific configuration */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_PeriodType,                 AUTOMATIC)                nPeriod;
    VAR(Pwm_eMios_ControlType,          AUTOMATIC)                u32CtrlMode;
    VAR(Pwm_eMios_ControlType,          AUTOMATIC)                u32CtrlBus;
    VAR(Pwm_eMios_ChannelType,          AUTOMATIC)                u8mIdx;
    VAR(Pwm_eMios_ChannelType,          AUTOMATIC)                u8chIdx;
    VAR(uint8,                          AUTOMATIC)                u8MasterBusIdx = 0xFFU;
    
    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];
    
    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    /* save current channel control register config value in local variable */
    u32CtrlMode = (peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32);
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_00();
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
    Pwm_eMios_aChannelDuty[u8IdxChannelConfig] = u16DutyCycle;
#endif /*PWM_GET_CHANNEL_STATE_API */
    
    if((PWM_MODE_OPWFM_U32 == u32CtrlMode) || (PWM_MODE_OPWFMB_U32 == u32CtrlMode))
    {
        nPeriod = Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel];
    }
    else
    {
        /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        u32CtrlBus = (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_BSL_MASK_U32);
        u8MasterBusIdx = (uint8)Pwm_eMios_GetMasterBus(u8mIdx, u8chIdx, u32CtrlBus);
        nPeriod = Pwm_eMios_aChannelPeriod[u8MasterBusIdx];
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    if (((uint16)0x0000 == u16DutyCycle) || (PWM_DUTY_CYCLE_100 == u16DutyCycle))
    {
        /* no transitions in the signal */
        Pwm_eMios_aDutyState[u8mIdx] &= ~((uint32)1<< u8chIdx);
    }
    else
    {
        /* transitions available in the signal */
        Pwm_eMios_aDutyState[u8mIdx] |= ((uint32)1U<< u8chIdx);
    }
#endif /* PWM_NOTIFICATION_SUPPORTED */

    switch(u32CtrlMode)
    {
#if (PWM_FEATURE_OPWMCB == STD_ON)   
    case PWM_MODE_OPWMCB_LEAD_DEADTIME_U32:
    case PWM_MODE_OPWMCB_TRAIL_DEADTIME_U32:
        Pwm_eMios_SetRegs_OPWMCB_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#endif
#if (PWM_FEATURE_DAOC == STD_ON)   
    case PWM_MODE_DAOC_U32: 
        Pwm_eMios_SetRegs_DAOC_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#endif
#if (PWM_FEATURE_OPWMT == STD_ON)   
    case PWM_MODE_OPWMT_U32:
        Pwm_eMios_SetRegs_OPWMT_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#endif
    case PWM_MODE_OPWMB_U32:
        Pwm_eMios_SetRegs_OPWMB_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#if (PWM_FEATURE_OPWM == STD_ON) 
    case PWM_MODE_OPWM_U32:
        Pwm_eMios_SetRegs_OPWM_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#endif /*PWM_FEATURE_OPWM*/    
    case PWM_MODE_OPWFMB_U32:
        Pwm_eMios_SetRegs_OPWMFMB_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#if (PWM_FEATURE_OPWFM == STD_ON)
    case PWM_MODE_OPWFM_U32:
        Pwm_eMios_SetRegs_OPWMFM_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#endif /*PWM_FEATURE_OPWFM*/    
    default:
        break;
    }    
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_00();
}
#endif /* (PWM_SET_DUTY_CYCLE_API == STD_ON) || (PWM_SET_COUNTER_BUS_API == STD_ON) */


/*===============================================================================================*/
#if (PWM_SET_PERIOD_AND_DUTY_API == STD_ON)
/**
* @brief   This function sets the period and the dutycycle for the specified eMIOS channel
* @details This function is applicable for mode OPWFMB
*          - disable the interrupt and clear the interrupt flag
*          - sets the A register with value 0 and B register with period for 0% dutycycle
*          - sets the A and B registers with value period for 100% dutycycle
*          - for dutycycle not equal to 0% and 100% set the A register with value dutycycle
*            and B register with value period
*
* @param[in]     u8IdxChannelConfig - pwm channel id
* @param[in]     nPeriod            - pwm signal period value
* @param[in]     u16DutyCycle       - pwm dutycycle value 0x0000 for 0% ... 0x8000 for 100%
*
*/
FUNC(void, PWM_CODE) Pwm_eMios_SetPeriodAndDuty
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    VAR(Pwm_PeriodType,                  AUTOMATIC)                 nPeriod,
    VAR(uint16,                          AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* @brief Pointer to EMIOS channel specific configuration */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;

    VAR(Pwm_eMios_ControlType, AUTOMATIC) u32CtrlMode;
    VAR(Pwm_eMios_ControlType, AUTOMATIC) u32CtrlBus;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx;  /*  assigned eMIOS HW module index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx;  /*  assigned eMIOS HW channel index */
    VAR(uint8,                 AUTOMATIC) u8MasterBusIdx;

   /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];
    
    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    /* save current mode in local variable */
    u32CtrlMode = peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32;
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_01();
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
    Pwm_eMios_aChannelDuty[u8IdxChannelConfig] = u16DutyCycle;
#endif /*PWM_GET_CHANNEL_STATE */

    /* if new period == 0, keep old period and put duty to 0 */
    if( (Pwm_PeriodType)0x00 == nPeriod )
    {
        nPeriod = Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel]; /*keep the old period */
        u16DutyCycle = (uint16)0x00;
    }

    /* store new period value */
    Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel] = nPeriod; /* for current channel */
    if((PWM_MODE_DAOC_U32 != u32CtrlMode) && (PWM_MODE_OPWFMB_U32 != u32CtrlMode))
    {
        /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        u32CtrlBus = (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_BSL_MASK_U32);
        u8MasterBusIdx = (uint8)Pwm_eMios_GetMasterBus(u8mIdx, u8chIdx, u32CtrlBus);
        Pwm_eMios_aChannelPeriod[u8MasterBusIdx] = nPeriod; /* for master channel */
    }
    
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    if (((uint16)0x0000 == u16DutyCycle) || (PWM_DUTY_CYCLE_100 == u16DutyCycle))
    {
        /* no transitions in the signal */
        Pwm_eMios_aDutyState[u8mIdx] &= ~((uint32)1<< u8chIdx);
    }
    else
    {
        /* transitions available in the signal */
        Pwm_eMios_aDutyState[u8mIdx] |= ((uint32)1U<< u8chIdx);
    }
#endif /* PWM_NOTIFICATION_SUPPORTED */
    
    switch(u32CtrlMode)
    {
#if (PWM_FEATURE_DAOC == STD_ON)   
    case PWM_MODE_DAOC_U32:  
        Pwm_eMios_SetRegs_DAOC_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#endif
    case PWM_MODE_OPWFMB_U32:
        Pwm_eMios_SetRegs_OPWMFMB_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#if (PWM_FEATURE_OPWFM == STD_ON)
    case PWM_MODE_OPWFM_U32:
        Pwm_eMios_SetRegs_OPWMFM_mode(u8IdxChannelConfig, nPeriod, u16DutyCycle, peMiosChannelConfig);
        break;
#endif /*PWM_FEATURE_OPWFM*/    
    default:
        break;
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_01();
}
#endif /* PWM_SET_PERIOD_AND_DUTY_API */


/*===============================================================================================*/
#if (PWM_SET_OUTPUT_TO_IDLE_API == STD_ON)
/**
* @brief   This function sets the generated eMIOS channel to the idle value configured
* @details This function
*          - puts the channel in High or Low state by writing to the Control Register
*            based on the configured Idle state
*          - puts the Emios channel into GPIO mode
*
* @param[in]     u8IdxChannelConfig - pwm channel id
* @param[in]     peMiosIpConfig     - pointer to EMIOS IP Config
*
*/
FUNC(void, PWM_CODE) Pwm_eMios_SetOutputToIdle
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{

    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;

    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx;  /*  assigned eMIOS HW module index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx;  /*  assigned eMIOS HW channel index */

    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];
    
    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_02();
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
    Pwm_eMios_aChannelDuty[u8IdxChannelConfig] = (uint16)0U;
#endif /*PWM_GET_CHANNEL_STATE */
    if (PWM_HIGH == Pwm_eMios_aChannelIdleState[u8IdxChannelConfig])
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_EDPOL_MASK_U32);
    }
    else
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_EDPOL_MASK_U32 );
    }
    
    /* Enter GPIO output mode */
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_MODE_MASK_U32, CCR_MODE_GPO_U32);
    /* Disable channel interrupts  */
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32);
    /* Clear pending interrupt flag for the channel  */
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx), CSR_FLAG_BIT_U32);
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_02();
}
#endif /* PWM_SET_OUTPUT_TO_IDLE_API */


/*===============================================================================================*/
#if (PWM_GET_OUTPUT_STATE_API == STD_ON)
/**
* @brief   This function returns the pwm signal output state
* @details This function returns the PWM Channel state as High or Low
*
* @param[in]     u8IdxChannelConfig - pwm channel id
* @param[in]     peMiosIpConfig     - pointer to EMIOS IP Config
* @return        Pwm_OutputStateType - pwm signal output logic value
* @retval        PWM_LOW - The output state of PWM channel is low
* @retval        PWM_HIGH - The output state of PWM channel is high
*/

FUNC(Pwm_OutputStateType, PWM_CODE) Pwm_eMios_GetOutputState
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{

    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx;  /*  assigned eMIOS HW module index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx;  /*  assigned eMIOS HW channel index */

    VAR(Pwm_OutputStateType, AUTOMATIC) eOutputState;

    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (0U != (REG_READ32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx)) & CSR_UCOUT_MASK_U32))
    {
        eOutputState = PWM_HIGH;
    }
    else
    {
        eOutputState = PWM_LOW;
    }

    return eOutputState;
}
#endif /* PWM_GET_OUTPUT_STATE_API */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief   This function disables the user notifications
* @details This function
*          - enables the notification
*          - sets the Edge select bit in control register if notification is both edges
*          - clears the Edge select bit in control register if notification is both edges
*          - clears the interrupt flag and enables the FLAG event for OPWMB and OPWFMB modes
*          - clear interrupt flag in Status register and clear the DMA bit in
*            Control register for OPWMT mode
*
*
* @param[in]     u8IdxChannelConfig - pwm channel id
* @param[in]     eNotification      - notification type to be enabled
* @param[in]     peMiosIpConfig     - pointer to EMIOS IP Config
*
*/
FUNC(void, PWM_CODE) Pwm_eMios_EnableNotification
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    VAR(Pwm_EdgeNotificationType,        AUTOMATIC)                 eNotification,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{

    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx;  /*  assigned eMIOS HW module index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx;  /*  assigned eMIOS HW channel index */
#if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON))
    VAR(Pwm_eMios_ControlType, AUTOMATIC) u32CtrlRegVal;
#endif

    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

    /* save current channel control register config value in local variable */
#if ((PWM_FEATURE_OPWMT == STD_ON) || (PWM_FEATURE_DAOC == STD_ON))
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;
#endif
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_03();
    /* note that notifications are enabled for this channel */
    Pwm_eMios_aChannelNotifType[(uint8)peMiosChannelConfig->u8HwChannel] = (uint8)eNotification;
    /* only enable notifications if channel is not in idle state */
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    if (CCR_MODE_GPO_U32 != (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
    {
#if (PWM_FEATURE_OPWMT == STD_ON)
        /* activation edge not available in OPWMT */
        if (PWM_MODE_OPWMT_U32 != (u32CtrlRegVal & CCR_MODE_MASK_U32))
        {
#endif
    /* transitions are present in the signal ( duty != 0%,100% )  u16DutyCycle doesn't affect trigger in OPWMT mode */
            if (((uint32)1U << u8chIdx) & Pwm_eMios_aDutyState[u8mIdx])
            {
                /* Change activation edge if required */
                if (PWM_BOTH_EDGES == eNotification)
                {
#if (PWM_FEATURE_DAOC == STD_ON)
                    if (PWM_MODE_DAOC_U32 == (u32CtrlRegVal & CCR_MODE_MASK_U32))
                    {
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_DAOC_MODE_EDGE_SELECT_MASK_U32 );
                    }
                    else
                    {
#endif
                    /* notification on both edges */
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_MODE_EDGE_SELECT_MASK_U32 );
#if (PWM_FEATURE_DAOC == STD_ON)
                    }
#endif
                }
                else
                {
#if (PWM_FEATURE_DAOC == STD_ON)
                    if (PWM_MODE_DAOC_U32 == (u32CtrlRegVal & CCR_MODE_MASK_U32))
                    {
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_DAOC_MODE_EDGE_SELECT_MASK_U32);
                    }
                    else
                    {
#endif
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_MODE_EDGE_SELECT_MASK_U32);
#if (PWM_FEATURE_DAOC == STD_ON)
                    }
#endif
                }
#if (PWM_FEATURE_DAOC == STD_ON)
                if (PWM_MODE_DAOC_U32 != (u32CtrlRegVal & CCR_MODE_MASK_U32))
                {
#endif
                    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                    REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx), CSR_FLAG_BIT_U32 );
#if (PWM_FEATURE_DAOC == STD_ON)
                }
#endif
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
            }
    
#if (PWM_FEATURE_OPWMT == STD_ON)
        }
        else
        { /* OPWMT */
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx), CSR_FLAG_BIT_U32 );
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_DMA_MASK_U32 );
        }
#endif
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_03();
}
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
/**
* @brief   This function disables the user notifications
* @details This function
*          - disables the notification
*          - disables the FEN bit in Control register for OPWMB and OPWFMB modes
*          - clear interrupt flag in Status register and Set the DMA bit in
*            Control register for OPWMT mode
*
* @param[in]     u8IdxChannelConfig - pwm channel id
* @param[in]     peMiosIpConfig     - pointer to EMIOS IP Config
*/
FUNC(void, PWM_CODE) Pwm_eMios_DisableNotification
(
    VAR         (uint8,                  AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType, AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ChannelType,           AUTOMATIC)                u8mIdx;
    VAR(Pwm_eMios_ChannelType,           AUTOMATIC)                u8chIdx;

    /* extract from conf structure the generic channel information */
    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_04();
#if (PWM_FEATURE_OPWMT == STD_ON)
    if (PWM_MODE_OPWMT_U32 != (peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32))
    {
#endif /* PWM_FEATURE_OPWMT */
#if (PWM_FEATURE_DAOC == STD_ON)
        if (PWM_MODE_DAOC_U32 != (peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32))
        {
#endif
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FEN_MASK_U32 );
#if (PWM_FEATURE_DAOC == STD_ON)
        }
#endif
    /* no need to clear the flag as it will be cleared in EnableNotification before interrupts are enabled */
#if (PWM_FEATURE_OPWMT == STD_ON)
    }
    else
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx), CSR_FLAG_BIT_U32 );
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_DMA_MASK_U32 );
    }
#endif /* PWM_FEATURE_OPWMT */

    /* note that notifications are disabled for this channel */
    Pwm_eMios_aChannelNotifType[(uint8)peMiosChannelConfig->u8HwChannel] = (uint8)0U;
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_04();
}
#endif /* PWM_NOTIFICATION_SUPPORTED */


/*===============================================================================================*/
#if (PWM_SET_COUNTER_BUS_API == STD_ON)
/**
* @brief   Implementation specific function to set the frequency of pwm channel
*          running on PWM_MODE_OPWMB_U32, PWM_MODE_OPWM_U32 or PWM_MODE_OPWMT_U32 mode
* @details This function
*          - changes the counter bus from Bus A to Bus Diverse or vice versa
*          - Bus selection bits will be configured in Control register
*          - update dutycycle to the configured default value
*
* @param[in] u8IdxChannelConfig - pwm channel id
* @param[in] peMiosIpConfig     - pointer to EMIOS IP Config
* @param[in] u32Bus             - the eMIOS bus to change to

* @implements       Pwm_eMios_SetCounterBus_Activity
*/
FUNC(void, PWM_CODE) Pwm_eMios_SetCounterBus
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig,
    VAR(uint32,                          AUTOMATIC)                 u32Bus
)
{
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,    AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_PeriodType,                     AUTOMATIC)                nPeriod;
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                u8mIdx;
    VAR(Pwm_eMios_ChannelType,              AUTOMATIC)                u8chIdx;
    VAR(Pwm_eMios_ControlType,              AUTOMATIC)                u32CtrlRegVal;
    VAR(Pwm_PeriodType,                     AUTOMATIC)                nOffset;
#if (PWM_FEATURE_OPWMT == STD_ON)
    VAR(Pwm_PeriodType,                     AUTOMATIC)                nTrigger;
#endif
    VAR(uint8,                              AUTOMATIC)                u8MasterBusIdx = 0xFFU;
#if  (PWM_EMIOS_16_BITS_VARIANT == STD_OFF)
    VAR(Pwm_uint64,                         AUTOMATIC)                u64Temp = 0U;
#endif

    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];
    
    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);    
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_05();
    /* Get new period from new master bus */
    u8MasterBusIdx = (uint8)Pwm_eMios_GetMasterBus(u8mIdx, u8chIdx, u32Bus);
    nPeriod = Pwm_eMios_aChannelPeriod[u8MasterBusIdx];
    if((boolean)TRUE == (peMiosChannelConfig->bPwmOffsetTriggerDelay))
    {
#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
        nOffset = (((peMiosChannelConfig->nPwmOffset) * nPeriod) / Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel]);
#if (PWM_FEATURE_OPWMT == STD_ON)
        nTrigger = Pwm_eMios_aTriggerDelay[u8IdxChannelConfig];
        nTrigger = ((nTrigger * nPeriod) / Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel]);
#endif
#else
        u64Temp = ((Pwm_uint64)peMiosChannelConfig->nPwmOffset * (Pwm_uint64)nPeriod);
        nOffset = (Pwm_PeriodType)Pwm_eMios_Div64((Pwm_uint64)u64Temp, (Pwm_uint64)Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel]);
#if (PWM_FEATURE_OPWMT == STD_ON)
        nTrigger = Pwm_eMios_aTriggerDelay[u8IdxChannelConfig];
        u64Temp = ((Pwm_uint64)nTrigger * (Pwm_uint64)nPeriod);
        nTrigger = (Pwm_PeriodType)Pwm_eMios_Div64((Pwm_uint64)u64Temp, (Pwm_uint64)Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel]);
#endif
#endif
        /* update the channel period with the period of the new selected counter bus */
        Pwm_eMios_aChannelOffset[u8IdxChannelConfig] = nOffset;
#if (PWM_FEATURE_OPWMT == STD_ON)
        /* Update new trigger delay */
        Pwm_eMios_aTriggerDelay[u8IdxChannelConfig] = nTrigger;
#endif
    }

    /* set the new counter bus */
    if (PWM_BUS_DIVERSE_U32 == u32Bus)
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_BSL_MASK_U32, CCR_BSL_BUS_DIVERSE_U32 << CCR_BSL_SHIFT);
    }
    else if (PWM_BUS_A_U32 == u32Bus)
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_BSL_MASK_U32 );
    }
    else if (PWM_BUS_F_U32 == u32Bus)
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        REG_RMW32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_BSL_MASK_U32, CCR_BSL_BUS_F_U32 << CCR_BSL_SHIFT);
    }
    else
    {
        /* This for Misra complicated */
    }
    /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
    /* update dutycycle to the configured default value */
    switch((u32CtrlRegVal & CCR_MODE_MASK_U32))
    {
#if (PWM_FEATURE_OPWMCB == STD_ON)   
    case PWM_MODE_OPWMCB_LEAD_DEADTIME_U32:
    case PWM_MODE_OPWMCB_TRAIL_DEADTIME_U32:
        /* Update new period */
        Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel] = nPeriod;
        Pwm_eMios_SetRegs_OPWMCB_mode(u8IdxChannelConfig, nPeriod, peMiosChannelConfig->u16PwmDefaultDutyCycle, peMiosChannelConfig);
        break;
#endif
#if (PWM_FEATURE_DAOC == STD_ON)   
    case PWM_MODE_DAOC_U32:
        /* Update new modulo */
        Pwm_DAOC_aChannelModulo[peMiosChannelConfig->u8HwChannel] = nPeriod;
        nPeriod = Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel];
        Pwm_eMios_SetRegs_DAOC_mode(u8IdxChannelConfig, nPeriod, peMiosChannelConfig->u16PwmDefaultDutyCycle, peMiosChannelConfig);
        break;
#endif
#if (PWM_FEATURE_OPWMT == STD_ON)   
    case PWM_MODE_OPWMT_U32:
        /* Update new period */
        Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel] = nPeriod;
        Pwm_eMios_SetRegs_OPWMT_mode(u8IdxChannelConfig, nPeriod, peMiosChannelConfig->u16PwmDefaultDutyCycle, peMiosChannelConfig);
        break;
#endif
    case PWM_MODE_OPWMB_U32:
        /* Update new period */
        Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel] = nPeriod;
        Pwm_eMios_SetRegs_OPWMB_mode(u8IdxChannelConfig, nPeriod, peMiosChannelConfig->u16PwmDefaultDutyCycle, peMiosChannelConfig);
        break;
#if (PWM_FEATURE_OPWM == STD_ON) 
    case PWM_MODE_OPWM_U32:
        /* store the nPeriod that the master UC is using */
        Pwm_eMios_aChannelPeriod[u8MasterBusIdx] = nPeriod;
        /* store the offset channel that the master UC is using */
        Pwm_eMios_aChannelOffset[u8IdxChannelConfig] = peMiosChannelConfig->nPwmOffset;
        Pwm_eMios_SetRegs_OPWM_mode(u8IdxChannelConfig, nPeriod, peMiosChannelConfig->u16PwmDefaultDutyCycle, peMiosChannelConfig);
        break;
#endif /*PWM_FEATURE_OPWM*/    
    default:
        break;
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_05();
}
#endif /* PWM_SET_COUNTER_BUS_API */


/*===============================================================================================*/
#if (PWM_SET_CHANNEL_OUTPUT_API == STD_ON)
/**
* @brief   Implementation specific function to set the state of the PWM pin as requested
*         for the current cycle
* @details This function is useful to to set the state of the PWM pin as requested
*          for the current cycle and continues
*          with normal PWM operation from the next cycle
*          - OPWFMB, OPWFM: if the passed state is Active, force a match on B Register otherwise
*            force a match on A Register
*          - OPWMB, OPWM or OPWMT: if the passed state is Active, force a match on A Register
*            otherwise force a match on B Register
*          - the force match is done by setting the FORCMA and FORCMB bits is Control Register
*
* @param[in] u8IdxChannelConfig - pwm channel id
* @param[in] peMiosIpConfig     - pointer to EMIOS IP Config
* @param[in] eState             - Active - Inactive state of the channel
* @implements       Pwm_eMios_SetChannelOutput_Activity
*/
FUNC(void, PWM_CODE) Pwm_eMios_SetChannelOutput
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig,
    VAR(Pwm_StateType,                   AUTOMATIC)                 eState
)
{
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx;  /*  assigned eMIOS HW module index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx;  /*  assigned eMIOS HW channel index */
    VAR(Pwm_eMios_ControlType, AUTOMATIC) u32CtrlRegVal;
    
    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/    
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];
    
    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    /* save current channel control register config value in local variable */
    u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_06();
    if ((PWM_MODE_OPWFMB_U32 == ((uint32)u32CtrlRegVal & CCR_MODE_MASK_U32))||
        (PWM_MODE_OPWFM_U32 == ((uint32)u32CtrlRegVal & CCR_MODE_MASK_U32)))
    {
        if (PWM_ACTIVE == eState) /* force match B */
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32 );
        }
        else /* force match A */
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMA_MASK_U32 );
        }
    }
    else /* OPWMB / OPWMT / OPWM */
    {
        if (PWM_ACTIVE == eState) /* force match A */
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMA_MASK_U32 );
        }
        else /* force match B */
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_FORCMB_MASK_U32 );
        }
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_06();
}
#endif /* PWM_SET_CHANNEL_OUTPUT_API */


/*===============================================================================================*/
#if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) || (PWM_FEATURE_DAOC == STD_ON))
/**
* @brief   Interrupt service routine to process the eMIOS interrupt
* @details This function
*         - clears the unified channel interrupt flag bit in Control register
*         - calls the Ipw layer handler
*         - Recalculator and update register A,B for channel use DAOC mode
*
* @param[in]     u8HwChannel      EMIOS channel ID that triggered the interrupt
* @implements       Pwm_eMios_ProcessCommonInterrupt_Activity
*/
/* 
* @violates @ref Pwm_eMIOS_C_REF_12 external could be made static
*/
FUNC(void, PWM_CODE) Pwm_eMios_ProcessCommonInterrupt
(
    VAR(Pwm_ChannelType,                 AUTOMATIC)                 u8HwChannel
)
{
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)    u8mIdx;  /*  assigned eMIOS HW module index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)    u8chIdx;  /*  assigned eMIOS HW channel index */
    VAR (uint32, AUTOMATIC)                  u32TempStatus;
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    VAR(uint8, AUTOMATIC) u8Notification;
#endif      /* PWM_NOTIFICATION_SUPPORTED == STD_ON */
    
#if (PWM_FEATURE_DAOC == STD_ON)
    VAR(uint32, AUTOMATIC) u32ChMode;   /* channel mode */
    VAR(uint32, AUTOMATIC) u32EdpolValue;   /* edge polarity value */
    VAR(uint32, AUTOMATIC) u32UcoutValue;   /* ucout bit value */
    VAR(uint32, AUTOMATIC) u32RegAValue;   /* store the calculated register A value */
    VAR(uint32, AUTOMATIC) u32RegBValue;   /* store the calculated register B value */
    VAR(uint32, AUTOMATIC) u32RegDuty;   /* store the duty is apply to register */
#endif      /* PWM_FEATURE_DAOC == STD_ON */

    /* store the associated hw channel ID */
    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8(u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(u8HwChannel);

    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    u32TempStatus = ((REG_READ32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx))) & CSR_FLAG_MASK_U32);

    /* clear unified channel interrupt flag */
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_WRITE32( EMIOS_CSR_ADDR32(u8mIdx, u8chIdx), CSR_FLAG_BIT_U32 );

    /* get logical channel ID */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    u8Notification = Pwm_eMios_aChannelNotifType[u8HwChannel];
#endif    /* PWM_NOTIFICATION_SUPPORTED == STD_ON */
    /* Call Common Interrupt Routine */
    if (
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */    
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
         (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & (CCR_DMA_MASK_U32 | CCR_FEN_MASK_U32)) ==
         ((CCR_DMA_ASSIGN_INT_U32 << CCR_DMA_SHIFT) | ( CCR_FEN_ENABLE_U32 << CCR_FEN_SHIFT ))
       )
    {
        if(((uint32)0x0U) != u32TempStatus)
        {
#if (PWM_FEATURE_DAOC == STD_ON)
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            u32ChMode = ( REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32 );
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            u32EdpolValue = ( REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_EDPOL_MASK_U32 );
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            u32UcoutValue = ( REG_READ32(EMIOS_CSR_ADDR32(u8mIdx, u8chIdx)) & CSR_UCOUT_MASK_U32 );
            
            if (PWM_MODE_DAOC_U32 == u32ChMode )
            {
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                /* @violates @ref Pwm_eMIOS_C_REF_6 Cast of complex integer expression to larger type */
                u32RegDuty = (uint32)(Pwm_eMios_aChannelPeriod[u8HwChannel] - Pwm_eMios_aDaocChannelDuty[u8HwChannel]);
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                u32RegAValue = (((u32RegDuty) + REG_READ32(EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx))) % Pwm_DAOC_aChannelModulo[u8HwChannel]);
                if (u32RegAValue != (uint32)0U)
                {
                    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                    REG_WRITE32( EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx) ,  u32RegAValue);
                }
                else
                {
                    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                    REG_WRITE32(EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx),Pwm_DAOC_aChannelModulo[u8HwChannel]);
                }
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                u32RegDuty = REG_READ32(EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx));
                /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                u32RegBValue = ((Pwm_eMios_aChannelPeriod[u8HwChannel]+u32RegDuty)%Pwm_DAOC_aChannelModulo[u8HwChannel]);
                if (u32RegBValue != (uint32)0U)
                {
                    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                    REG_WRITE32( EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx) ,  u32RegBValue);
                }
                else
                {
                    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer  */
                    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                    REG_WRITE32(EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx),Pwm_DAOC_aChannelModulo[u8HwChannel]);
                }
            }
            else if(CCR_MODE_DAOC_BOTH_U32 == u32ChMode )
            {
                if( u32EdpolValue != (u32UcoutValue<<6) )
                {
                    u32RegAValue = ((Pwm_eMios_aChannelPeriod[u8HwChannel] + 
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                    REG_READ32( EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx)))% Pwm_DAOC_aChannelModulo[u8HwChannel]);
                    if (u32RegAValue != (uint32)0U)
                    {
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                        REG_WRITE32( EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx) , u32RegAValue);
                    } else
                    {
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                        REG_WRITE32(EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx), Pwm_DAOC_aChannelModulo[u8HwChannel]);
                    }
                }
                else
                {
                    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                    u32RegBValue = ((Pwm_eMios_aDaocChannelDuty[u8HwChannel] + \
                                    REG_READ32(EMIOS_CADR_ADDR32(u8mIdx, (uint32)u8chIdx)))% Pwm_DAOC_aChannelModulo[u8HwChannel]);
                    if (u32RegBValue != (uint32)0U)
                    {
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                        REG_WRITE32( EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx), u32RegBValue);
                    }
                    else
                    {
                        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                        REG_WRITE32(EMIOS_CBDR_ADDR32(u8mIdx, (uint32)u8chIdx),Pwm_DAOC_aChannelModulo[u8HwChannel]);
                    }
                }
            }
            else
            {
            /* For Misra Compliance */
            }
#endif
#if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) && (PWM_FEATURE_DAOC == STD_ON))
            /* Call Ipw interrupt handler at valid edge match*/
            if (CCR_MODE_DAOC_BOTH_U32 == u32ChMode) 
            {
                if( Pwm_eMios_aDaocChannelDuty[u8HwChannel] != 0x0U )
                {
                    if((uint8)0U != u8Notification)
                    {
                        /**  @violates @ref Pwm_eMIOS_C_REF_11 pointer arithmetic other than array indexing used  */
                        Pwm_Ipw_eMiosChannelNotification(u8HwChannel);
                    }
                }
            }
            else if (PWM_MODE_DAOC_U32 == u32ChMode)
            {
                if( Pwm_eMios_aDaocChannelDuty[u8HwChannel] != 0x0U )
                {
                    if((uint8)0U != u8Notification)
                    {
                        if( u32EdpolValue != (u32UcoutValue<<6) )
                        {
                            /**  @violates @ref Pwm_eMIOS_C_REF_11 pointer arithmetic other than array indexing used  */
                            Pwm_Ipw_eMiosChannelNotification(u8HwChannel);
                        }
                    }
                }
            }
            else
            {
#endif  /* PWM_NOTIFICATION_SUPPORTED == STD_ON && PWM_FEATURE_DAOC == STD_ON */
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
                if ( (uint8)0U != u8Notification )
                {
            /* Note: For PWM, interrupts are not enabled if the u8Notification function is a NULL_PTR. 
            * Therefore the code does not check for NULL_PTR before calling the u8Notification function */
                    /** @violates @ref Pwm_eMIOS_C_REF_11 pointer arithmetic other than array indexing used */
                    Pwm_Ipw_eMiosChannelNotification(u8HwChannel);
                }
#endif /* PWM_NOTIFICATION_SUPPORTED == STD_ON */
#if ((PWM_NOTIFICATION_SUPPORTED == STD_ON) && (PWM_FEATURE_DAOC == STD_ON))
            }
#endif /* PWM_NOTIFICATION_SUPPORTED == STD_ON && PWM_FEATURE_DAOC == STD_ON */
        }
    }
}
#endif /* PWM_NOTIFICATION_SUPPORTED == STD_ON || PWM_FEATURE_DAOC == STD_ON */
/*===============================================================================================*/
#if (PWM_SET_TRIGGER_DELAY_API == STD_ON)
/**
@brief   Implementation specific function to set the trigger delay  for  pwm channel
         running on PWM_MODE_OPWMT_U32 mode
         - write trigger delay to alternate A register for OPWMT mode

* @param[in] u8IdxChannelConfig - pwm channel id
* @param[in] peMiosIpConfig     - pointer to EMIOS IP Config
* @param[in] nTriggerDelay      - trigger delay
* @implements  Pwm_eMios_SetTriggerDelay_Activity
*/
FUNC(void, PWM_CODE) Pwm_eMios_SetTriggerDelay
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType, AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig,
    VAR(Pwm_PeriodType,                  AUTOMATIC)                 nTriggerDelay
)
{
#if (PWM_FEATURE_OPWMT == STD_ON)
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8mIdx;  /*  assigned eMIOS HW module index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC) u8chIdx;  /*  assigned eMIOS HW channel index */

    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

    /** @violates @ref Pwm_eMIOS_C_REF_3 Non-constant argument to function */
    Pwm_eMios_aTriggerDelay[u8IdxChannelConfig] = (Pwm_PeriodType)nTriggerDelay;
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_WRITE32(EMIOS_ALTA_ADDR32(u8mIdx, u8chIdx),(uint32)( (uint32)nTriggerDelay + (uint32)1U));
#endif
}
#endif

/*===============================================================================================*/
#if (PWM_GET_CHANNEL_STATE_API == STD_ON)
/**
* @brief   Implementation specific function to get the Duty cycle of the given PWM channel
* @param[in] u8IdxChannelConfig - pwm channel id
*/
FUNC(uint16, PWM_CODE)  Pwm_eMios_GetChannelState
(
    VAR(uint8,                           AUTOMATIC)                 u8IdxChannelConfig
)
{
    
    return Pwm_eMios_aChannelDuty[u8IdxChannelConfig];
}

#endif /*PWM_GET_CHANNEL_STATE_API*/


/*===============================================================================================*/
#if (PWM_BUFFER_TRANSFER_EN_DIS_API == STD_ON)
/**
* @brief            Pwm_eMios_BufferTransferEnableDisable
* @details          Implementation specific function to enable-disable the buffer transfer.
*
* @param[in]        u8ModuleIndex  - eMIOS module
* @param[in]        u32ChannelMask - channel mask set
* @implements       Pwm_eMios_BufferTransferEnableDisable_Activity
*/
FUNC(void, PWM_CODE) Pwm_eMios_BufferTransferEnableDisable
(
    VAR(uint8,                           AUTOMATIC)                 u8ModuleIndex,
    VAR(uint32,                          AUTOMATIC)                 u32ChannelMask
)
{
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_08();
    /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
    /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
    REG_RMW32(EMIOS_OUDR_ADDR32(u8ModuleIndex),(uint32)(0xFFFFFFF),(uint32)(u32ChannelMask & (uint32)0xFFFFFFF));
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_08();
}
#endif

#if ((PWM_PARAM_CHECK == STD_ON)  && (PWM_NOTIFICATION_SUPPORTED == STD_ON))
/*===============================================================================================*/
/**
* @brief            Pwm_eMios_ValidateNotification
* @details          This function will check validate of Edge type with polarity
*
* @param[in]        u8IdxChannelConfig  Pwm channel id in top configuration structure
* @param[in]        eNotification       Notification edge type
* @nRetVal          E_NOT_OK            Notification handler is not valid
* @violates @ref Pwm_eMIOS_C_REF_12 external  could be made static 
*/
FUNC(Std_ReturnType, PWM_CODE) Pwm_eMios_ValidateNotification
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (Pwm_EdgeNotificationType,AUTOMATIC)                 eNotification
)
{
    VAR(Std_ReturnType, AUTOMATIC)                                nRetVal = (Std_ReturnType)E_OK;

    if (
         ((PWM_LOW == Pwm_eMios_aChannelPolarity[u8IdxChannelConfig]) && (PWM_FALLING_EDGE == eNotification))||
         ((PWM_HIGH == Pwm_eMios_aChannelPolarity[u8IdxChannelConfig]) && (PWM_RISING_EDGE == eNotification))
       )
    {
        nRetVal = (Std_ReturnType)E_NOT_OK;
    }
    return nRetVal;
}
#endif

#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_COUNTER_BUS_API == STD_ON))
/*===============================================================================================*/
/**
* @brief            Pwm_eMios_ValidateCounterBus
* @details          This function will check validate of Edge type with polarity
*
* @param[in]        u8IdxChannelConfig  Pwm channel id in top configuration structure
* @param[in]        u32Bus              Current counter bus
* @param[in]        peMiosIpConfig      Pointer to PWM top configuration structure
* @nRetval          E_NOT_OK            Notification handler is not valid
*/
FUNC(Std_ReturnType, PWM_CODE) Pwm_eMios_ValidateCounterBus
(
    VAR         (uint32,                  AUTOMATIC)                 u32Bus
)
{
    VAR(Std_ReturnType, AUTOMATIC) nRetval = (Std_ReturnType)E_OK;
    
    if (PWM_BUS_INTERNAL_COUNTER_U32 == u32Bus)
    {
        nRetval = (Std_ReturnType)E_NOT_OK;
    }
    return nRetval;
}
#endif

/*===============================================================================================*/
#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_TRIGGER_DELAY_API == STD_ON))
/**
* @brief            This function get the current period value.
*
* @param[in]        u8IdxChannelConfig   EMIOS channel id
* @param[in]        peMiosIpConfig       Pointer to EMIOS channels configuration structure
*
* @return           Pwm_PeriodType
*
*/
FUNC(Pwm_PeriodType, PWM_CODE) Pwm_eMios_GetCurrentPeriodValue
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)                         u8mIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)                         u8chIdx;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)                         u32CtrlMode;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)                         u32CtrlBus;
    VAR(Pwm_PeriodType,        AUTOMATIC)                         nPeriod;
    VAR(uint8,                 AUTOMATIC)                         u8MasterBusIdx;

    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

    /* save current channel control register config value in local variable */
    u32CtrlMode = (peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32);

    if((PWM_MODE_DAOC_U32 == u32CtrlMode) || (PWM_MODE_OPWFMB_U32 == u32CtrlMode) ||
        (PWM_MODE_OPWFM_U32 == u32CtrlMode))
    {
        nPeriod = Pwm_eMios_aChannelPeriod[peMiosChannelConfig->u8HwChannel];
    }
    else /* using master bus */
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        u32CtrlBus = (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_BSL_MASK_U32);
        u8MasterBusIdx = (uint8)Pwm_eMios_GetMasterBus(u8mIdx, u8chIdx, u32CtrlBus);
        nPeriod =  Pwm_eMios_aChannelPeriod[u8MasterBusIdx];
    }
    return nPeriod;
}
/*===============================================================================================*/
/**
* @brief            This function validate the mode of current channel
*
* @param[in]        u8IdxChannelConfig   EMIOS channel id
* @param[in]        peMiosIpConfig       Pointer to EMIOS channels configuration structure
*
* @return           Std_ReturnType
*
*/
FUNC(Std_ReturnType, PWM_CODE) Pwm_eMios_ValidateTriggerMode
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)                         u32CtrlMode;
    
    VAR(Std_ReturnType, AUTOMATIC) nRetVal = (Std_ReturnType)E_OK;

    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    /* save current channel control register config value in local variable */
    u32CtrlMode = (peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32);
    
    if(PWM_MODE_OPWMT_U32 == u32CtrlMode)
    {
        nRetVal = (Std_ReturnType)E_OK;
    }
    else
    {
        nRetVal = (Std_ReturnType)E_NOT_OK;
    }

    return nRetVal;
}

#endif

/*===============================================================================================*/
#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_PERIOD_AND_DUTY_API == STD_ON))
FUNC(Pwm_PeriodType, PWM_CODE) Pwm_eMios_GetMaxPeriodValue
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* Pwm channel Emios specific parameters from config structure */
#if (PWM_FEATURE_DAOC == STD_ON)
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)                         u8mIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)                         u8chIdx;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)                         u32CtrlMode;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)                         u32CtrlBus;
#endif
    VAR(Pwm_PeriodType,        AUTOMATIC)                         nMaxPeriod;
    
#if (PWM_FEATURE_DAOC == STD_OFF)
    (void) u8IdxChannelConfig;
    (void) peMiosIpConfig;
#endif

#if (PWM_FEATURE_DAOC == STD_ON)
    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    u8mIdx  = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
    u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

    /* save current channel control register config value in local variable */
    u32CtrlMode = (peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32);

    if(PWM_MODE_DAOC_U32 == u32CtrlMode)
    {
        /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        u32CtrlBus = (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_BSL_MASK_U32);
        if(PWM_BUS_INTERNAL_COUNTER_U32 != u32CtrlBus)
        {
            nMaxPeriod = (Pwm_PeriodType)Pwm_DAOC_aChannelModulo[peMiosChannelConfig->u8HwChannel];
        }
        else
        {
            nMaxPeriod = (Pwm_PeriodType)PWM_MAX_PERIOD;
        }
    }
    else
    {
#endif
        nMaxPeriod = (Pwm_PeriodType)PWM_MAX_PERIOD;
#if (PWM_FEATURE_DAOC == STD_ON)
    }
#endif
    return nMaxPeriod;
}
#endif

/*===============================================================================================*/
#if (PWM_PARAM_CHECK == STD_ON)
/**
* @brief            This function validate offset parameter with duty and period default
*
* @param[in]        peMiosIpConfig       Pointer to EMIOS channels configuration structure
*
* @return           uint8
*
*/
FUNC(uint8, PWM_CODE) Pwm_eMios_ValidateParamOffset
(
    P2CONST(Pwm_eMios_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;

    VAR(Pwm_eMios_ControlType, AUTOMATIC)                         u32CtrlRegVal;
    VAR(Pwm_PeriodType,        AUTOMATIC)                         nPeriod;
    VAR(Pwm_PeriodType,        AUTOMATIC)                         nRegDuty;
    VAR(uint16,                AUTOMATIC)                         u16DutyCycle;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)                         u8Counter;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)                         u32ControlReg;
    /* return value */
    VAR(uint8,        AUTOMATIC)                                  u8RetVal;

    u8RetVal = (uint8)0U;

    for (u8Counter=0U; u8Counter < peMiosIpConfig->u8NumChannels; u8Counter++)
    {
        /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8Counter];

        nPeriod = peMiosChannelConfig->nPwmDefaultPeriod;
        u16DutyCycle = peMiosChannelConfig->u16PwmDefaultDutyCycle;
        
        /* save current channel control register config value in local variable */
        u32CtrlRegVal = peMiosChannelConfig->u32ControlValue;
        u32ControlReg = (uint32)(u32CtrlRegVal & CCR_MODE_MASK_U32);

        if ((PWM_MODE_OPWMB_U32 == u32ControlReg) || (PWM_MODE_OPWMT_U32 == u32ControlReg) ||
            (PWM_MODE_OPWM_U32 == u32ControlReg))
        {
            if (peMiosChannelConfig->nPwmOffset >= peMiosChannelConfig->nPwmDefaultPeriod)
            {
                u8RetVal = (uint8)PWM_E_CHANNEL_OFFSET_VALUE;
            }
            else
            {
#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
                nRegDuty = Pwm_eMios_ComputeDutycycle_16bits(nPeriod, u16DutyCycle);
#else
                nRegDuty = Pwm_eMios_ComputeDutycycle_32bits(nPeriod, u16DutyCycle);
#endif
                /* Duty Cycle != 0 and != 100% */
                if (((0x0U != nRegDuty)) && (PWM_DUTY_CYCLE_100 != u16DutyCycle) && (0U != u16DutyCycle))
                {
                    if ((nRegDuty + peMiosChannelConfig->nPwmOffset) >= nPeriod)
                    {
                        u8RetVal = (uint8)PWM_E_OPWMB_CHANNEL_OFFSET_DUTYCYCLE_RANGE;
                    }
                }
            }
        }
    }
    return u8RetVal;
}
#endif

/*===============================================================================================*/
#if ((PWM_PARAM_CHECK == STD_ON) && (PWM_SET_DUTY_CYCLE_API == STD_ON))
/**
* @brief            This function validate offset parameter with duty cycle input
*
* @param[in]        peMiosIpConfig       Structure of EMIOS channels configuration
*
* @return           uint8
*
*/
FUNC(uint8, PWM_CODE) Pwm_eMios_ValidateParamOffsetDuty
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    VAR         (uint16,                  AUTOMATIC)                 u16DutyCycle,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* Pwm channel Emios specific parameters from config structure */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;

    VAR(Pwm_PeriodType,        AUTOMATIC)                         nPeriod;
    VAR(Pwm_PeriodType,        AUTOMATIC)                         nRegDuty;
    /* return value */
    VAR(uint8,                 AUTOMATIC)                         u8RetVal;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)                         u32ControlReg;
    
    /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];

    nPeriod = peMiosChannelConfig->nPwmDefaultPeriod;

    u8RetVal = (uint8)0U;
    u32ControlReg = (uint32)(peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32);
    if ((PWM_MODE_OPWMB_U32 == u32ControlReg) || (PWM_MODE_OPWMT_U32 == u32ControlReg) ||
        (PWM_MODE_OPWM_U32 == u32ControlReg))
    {
        if (peMiosChannelConfig->nPwmOffset >= peMiosChannelConfig->nPwmDefaultPeriod)
        {
            u8RetVal = (uint8)PWM_E_CHANNEL_OFFSET_VALUE;
        }
        else
        {
            if((PWM_MODE_OPWMB_U32 == (peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32)) ||
                (PWM_MODE_OPWM_U32 == (peMiosChannelConfig->u32ControlValue & CCR_MODE_MASK_U32)))
            {
#if  (PWM_EMIOS_16_BITS_VARIANT == STD_ON)
                nRegDuty = Pwm_eMios_ComputeDutycycle_16bits(nPeriod, u16DutyCycle);
#else
                nRegDuty = Pwm_eMios_ComputeDutycycle_32bits(nPeriod, u16DutyCycle);
#endif
                /* Duty Cycle != 0 and != 100% */
                if (((0x0U != nRegDuty)) && (PWM_DUTY_CYCLE_100 != u16DutyCycle) && (0U != u16DutyCycle))
                {
                    if ((nRegDuty + peMiosChannelConfig->nPwmOffset) >= nPeriod)
                    {
                        u8RetVal = (uint8)PWM_E_OPWMB_CHANNEL_OFFSET_DUTYCYCLE_RANGE;
                    }
                }
            }
        }
    }
    return u8RetVal;
}
#endif

/*================================================================================================*/
#if (PWM_SET_CLOCK_MODE_API == STD_ON)
/**
* @brief        This function set the value of the prescaler on all eMios channels
* @details      This function set the channel prescaler depending on the value ePrescaler parameter. 
*               - ePrescaler value is either PWM_PRIMARY_PRESCALER or PWM_ALTERNATIVE_PRESCALER
*               - the values associated to either types are configured by tooling and the phisical values 
                  associated are written to hardware registry.
*
* @param[in]    ePrescaler - prescaler logical values selectable between PWM_PRIMARY_PRESCALER or PWM_ALTERNATIVE_PRESCALER
* @param[in]    peMiosIpConfig  - Pointer to configuration structure of eMios channels
*
* @return       void
*
*/
FUNC(void, PWM_CODE) Pwm_eMios_SetClockMode
(
    VAR         (Pwm_PrescalerType,        AUTOMATIC)                 ePrescaler,
    CONSTP2CONST(Pwm_eMios_IpConfigType,  AUTOMATIC, PWM_APPL_CONST)  peMiosIpConfig
)
{
    /* @brief Pointer to eMIOS channel specific configuration */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;

    VAR(Pwm_eMios_ControlType, AUTOMATIC)   u32CtrlRegVal;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)   u32tempctrlRegVal;
    /* logical channel */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8Counter;
    /* assigned eMIOS HW module index and channel index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8mIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8chIdx;
    VAR(Pwm_eMios_ControlType, AUTOMATIC)   u32CtrlBus;
    VAR(uint8,                 AUTOMATIC)   u8MasterBusIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8MasterModule;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8MasterChannel;
    VAR(uint8,                 AUTOMATIC)   aMasterBusUse[PWM_EMIOS_HW_CHANNELS_U8];
    
    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_07();
    for (u8Counter=0U; u8Counter < (Pwm_eMios_ChannelType)PWM_EMIOS_HW_CHANNELS_U8; u8Counter++)
    {
        aMasterBusUse[u8Counter] = (uint8)0xFFU;
    }

    /* modify prescaler of each eMios channel */
    for (u8Counter=0U; u8Counter < peMiosIpConfig->u8NumChannels; u8Counter++)
    {
        /* only handle EMIOS channels */
        /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8Counter];

        u8mIdx = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
        u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
        /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        u32CtrlBus = (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_BSL_MASK_U32);
        if (PWM_BUS_INTERNAL_COUNTER_U32 == u32CtrlBus)
        {
            /* Stop eMios channel - this will stop the internal counter */
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, (uint32)u8chIdx), CCR_UCPREN_MASK_U32);
            /* set internal counter to 1 */
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32(EMIOS_CCNTR_ADDR32(u8mIdx, (uint32)u8chIdx), (uint32)1U);
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            u32CtrlRegVal = (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, (uint32)u8chIdx)) & ((uint32)(~(CCR_UCPRE_MASK_U32))));
            
            if (PWM_ALTERNATIVE_PRESCALER == ePrescaler)
            {
                u32tempctrlRegVal = (uint32)(((uint32)peMiosChannelConfig->u32ControlValue >> (uint32)23U) & ((uint32)0x3U)); 
            }
            else 
            {
                u32tempctrlRegVal = (uint32)(((uint32)peMiosChannelConfig->u32ControlValue >> CCR_UCPRE_SHIFT) & ((uint32)0x3U));           
            }

            /*write the new prescaler value to the control register buffer value*/
            u32CtrlRegVal |= (uint32)((uint32)u32tempctrlRegVal << CCR_UCPRE_SHIFT);
            /*write to the control register buffer value*/
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_WRITE32(EMIOS_CCR_ADDR32(u8mIdx, (uint32)u8chIdx), (uint32)u32CtrlRegVal);

            /* Re-start eMios channel */
            /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, (uint32)u8chIdx), CCR_UCPREN_MASK_U32);
        }
        else
        {
            u8MasterBusIdx = (uint8)Pwm_eMios_GetMasterBus(u8mIdx, u8chIdx, u32CtrlBus);
            
            if(aMasterBusUse[u8MasterBusIdx] == (uint8)0xFFU)
            {
                aMasterBusUse[u8MasterBusIdx] = (uint8)1U;
                /* Get module id and channel id of master bus */
                u8MasterModule  = EMIOS_MODULE_INDEX_U8(u8MasterBusIdx);
                u8MasterChannel = EMIOS_CHANNEL_INDEX_U8(u8MasterBusIdx);

                /* Stop eMios channel - this will stop the internal counter */
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), CCR_UCPREN_MASK_U32);
                /* set internal counter to 1 */
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CCNTR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), (uint32)1U);
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                u32CtrlRegVal = (REG_READ32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel)) & ((uint32)(~(CCR_UCPRE_MASK_U32))));
            
                if (PWM_ALTERNATIVE_PRESCALER == ePrescaler)
                {
                    u32tempctrlRegVal = (uint32)(((uint32)peMiosChannelConfig->u32ControlValue >> (uint32)23U) & ((uint32)0x3U)); 
                }
                else 
                {
                    u32tempctrlRegVal = (uint32)(((uint32)peMiosChannelConfig->u32ControlValue >> CCR_UCPRE_SHIFT) & ((uint32)0x3U));           
                }
    
                /*write the new prescaler value to the control register buffer value*/
                u32CtrlRegVal |= (uint32)((uint32)u32tempctrlRegVal << CCR_UCPRE_SHIFT);
                /*write to the control register buffer value*/
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_WRITE32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), (uint32)u32CtrlRegVal);

                /* Re-start eMios channel */
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_SET32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), CCR_UCPREN_MASK_U32);
            }
        }
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_07();
}
#endif /*PWM_SET_CLOCK_MODE_API */

/*================================================================================================*/
/**
* @brief            This function validate the state of pwm channel is idle or not, and the notification
*                   is enabled or not
*
* @param[in]        peMiosIpConfig       Structure of EMIOS channels configuration
*
* @return           uint8
*
*/
#if (PWM_POWER_STATE_SUPPORTED == STD_ON)
FUNC(Std_ReturnType, PWM_CODE) Pwm_eMios_ValidateIdleState
(
    P2CONST(Pwm_eMios_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig
)
{
    /* @brief Pointer to eMIOS channel specific configuration */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;
    /* logical channel */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   nCounter;

    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8mIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8chIdx;

    VAR(Std_ReturnType, AUTOMATIC)  nRetVal = (Std_ReturnType)E_OK;

    for (nCounter=0U; nCounter < peMiosIpConfig->u8NumChannels; nCounter++)
    {
        /* only handle EMIOS channels */
        /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[nCounter];

        u8mIdx = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
        u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
        /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
        /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
        if (CCR_MODE_GPO_U32 != (REG_READ32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx)) & CCR_MODE_MASK_U32))
        {
            nRetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
#if (PWM_NOTIFICATION_SUPPORTED == STD_ON)
    for (nCounter=0U; nCounter < (Pwm_eMios_ChannelType)PWM_EMIOS_HW_CHANNELS_U8; nCounter++)
    {
        if((uint8)0 != Pwm_eMios_aChannelNotifType[nCounter])
        {
            nRetVal = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
#endif
    return nRetVal;
}

/*================================================================================================*/
/**
* @brief        Put pwm channel based on emios to target power mode.
* @details      This function will disable clock if target power mode is Low power, and enable clock
*               if target power mode is full power
*               - ePowerState value is either PWM_LOW_POWER or PWM_FULL_POWER
*               - the values associated to either types are configured by tooling and the phisical values 
                  associated are written to hardware registry.
*
* @param[in]    ePowerState - target mode value selectable between PWM_LOW_POWER or PWM_FULL_POWER
* @param[in]    peMiosIpConfig  - Pointer to configuration structure of eMios channels
*                 
* @return         none

*/
FUNC(void, PWM_CODE) Pwm_eMios_SetPowerState
(
    P2CONST(Pwm_eMios_IpConfigType,      AUTOMATIC, PWM_APPL_CONST) peMiosIpConfig,
    VAR    (Pwm_PowerStateType,          AUTOMATIC)                 ePowerState
)
{
    /* @brief Pointer to eMIOS channel specific configuration */
    P2CONST(Pwm_eMios_ChannelConfigType,AUTOMATIC,PWM_APPL_CONST) peMiosChannelConfig;

    VAR(Pwm_eMios_ControlType, AUTOMATIC)   nCtrlRegVal;
    
    /* logical channel */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   nCounter;

    /* assigned eMIOS HW module index and channel index */
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8mIdx;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8chIdx;

    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8MasterModule;
    VAR(Pwm_eMios_ChannelType, AUTOMATIC)   u8MasterChannel;

    VAR(uint8,                 AUTOMATIC)   u8MasterBusMode[PWM_EMIOS_HW_CHANNELS_U8];

    SchM_Enter_Pwm_PWM_EXCLUSIVE_AREA_09();
    for (nCounter=0U; nCounter < (Pwm_eMios_ChannelType)PWM_EMIOS_HW_CHANNELS_U8; nCounter++)
    {
        u8MasterBusMode[nCounter] = (uint8)0xFFU;
    }

    for (nCounter=0U; nCounter < peMiosIpConfig->u8NumChannels; nCounter++)
    {
        /* only handle EMIOS channels */
        /** @violates @ref Pwm_eMIOS_C_REF_11 Array indexing shall be the only allowed form of pointer arithmetic.*/
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[nCounter];

        u8mIdx = (uint8)EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);
        u8chIdx = (uint8)EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->u8HwChannel);

        /* save current channel control register config value in local variable */
        nCtrlRegVal = peMiosChannelConfig->u32ControlValue;

        if (PWM_BUS_INTERNAL_COUNTER_U32 == ((uint32)nCtrlRegVal & CCR_BSL_MASK_U32))
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            if(PWM_LOW_POWER == ePowerState)
            {
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPREN_MASK_U32 );
            }
            else
            {
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPREN_MASK_U32 );
            }
        }
        else
        {
            u8MasterBusMode[nCounter] = 0x00U;
        }
        if ((PWM_MODE_OPWMCB_TRAIL_DEADTIME_U32 == (nCtrlRegVal & CCR_MODE_MASK_U32)) ||
            (PWM_MODE_OPWMCB_LEAD_DEADTIME_U32 == (nCtrlRegVal & CCR_MODE_MASK_U32))
           )
        {
            /** @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
            /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
            if(PWM_LOW_POWER == ePowerState)
            {
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPREN_MASK_U32 );
            }
            else
            {
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_SET32(EMIOS_CCR_ADDR32(u8mIdx, u8chIdx), CCR_UCPREN_MASK_U32 );
            }
        }
    }

    /* configuration for master bus */
    for (nCounter=0U; nCounter < PWM_EMIOS_HW_CHANNELS_U8; nCounter++)
    {
        /** @violates @ref Pwm_eMIOS_C_REF_11 pointer arithmetic other than array indexing used */
        if((uint8)0x00U == u8MasterBusMode[nCounter]) /* Master bus is used */
        {
            u8MasterModule  = EMIOS_MODULE_INDEX_U8(nCounter);
            u8MasterChannel = EMIOS_CHANNEL_INDEX_U8(nCounter);

            if(PWM_LOW_POWER == ePowerState)
            {
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel),CCR_UCPREN_MASK_U32);
            }
            else
            {
                /* @violates @ref Pwm_eMIOS_C_REF_7 Cast from unsigned long to pointer */
                /** @violates @ref Pwm_eMIOS_C_REF_16 Cast between a pointer type and an integral type */
                REG_BIT_SET32(EMIOS_CCR_ADDR32(u8MasterModule, (uint32)u8MasterChannel), CCR_UCPREN_MASK_U32 );
            }
        }
    }
    SchM_Exit_Pwm_PWM_EXCLUSIVE_AREA_09();
}
#endif

#define PWM_STOP_SEC_CODE
/** @violates @ref Pwm_eMIOS_C_REF_1 only preprocessor statements and comments before '#include' */
/** @violates @ref Pwm_eMIOS_C_REF_8 Precautions shall be taken in order to prevent the contents of a header file being included twice */
#include "Pwm_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
