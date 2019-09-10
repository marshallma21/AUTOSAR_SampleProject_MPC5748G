/**
*   @file    Pwm_eMIOS_Types.h
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

#ifndef PWM_EMIOS_TYPES_H
#define PWM_EMIOS_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Pwm_eMIOS_Types_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the contents of a
* header file being included twice.
* This is not a violation since all header files are protected against multiple inclusions.
*
* @section Pwm_eMIOS_Types_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31 character
* significance and case sensitivity are supported for external identifiers.
* This is not a violation since all the compilers used interpret the identifiers correctly.
*
*@section Pwm_eMIOS_Types_h_REF_3
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
*/
/*===============================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
===============================================================================================*/
/** @violates @ref Pwm_eMIOS_Types_h_REF_1 MISRA 2004 Required Rule 19.15, precautions to prevent the
*   contents of a header file being included twice.*/
#include "eMios_Common_Types.h"
#include "Std_Types.h"
#include "Pwm_Cfg.h"


/*===============================================================================================
                               SOURCE FILE VERSION INFORMATION
===============================================================================================*/

#define PWM_EMIOS_TYPES_VENDOR_ID                         43
#define PWM_EMIOS_TYPES_MODULE_ID                         121
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION          4
/**  @violates @ref Pwm_eMIOS_Types_h_REF_2 Identifier clash. */
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION          2
/**  @violates @ref Pwm_eMIOS_Types_h_REF_2 Identifier clash. */
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION       2
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_EMIOS_TYPES_SW_MAJOR_VERSION                  1
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_EMIOS_TYPES_SW_MINOR_VERSION                  0
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_EMIOS_TYPES_SW_PATCH_VERSION                  0


/*===============================================================================================
                                      FILE VERSION CHECKS
===============================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
/* Check if source file and Std_Types.h are of the same Autosar version */
    #if ((PWM_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
        (PWM_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pwm_eMios_Types.h and Std_Types.h are different"
    #endif

    #if ((PWM_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION != EMIOS_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (PWM_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION != EMIOS_COMMON_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Pwm_eMios_Types.h and eMios_Common_Types.h are different"
    #endif
#endif /* DISABLE_MCAL_INTERMODULE_ASR_CHECK */

/* Check if header file and Pwm_Cfg header file are of the same vendor */
#if (PWM_EMIOS_TYPES_VENDOR_ID != PWM_CFG_VENDOR_ID)
    #error "Pwm_eMios_Types.h and Pwm_Cfg.h have different vendor ids"
#endif
/* Check if header file and Pwm_Cfg header file are of the same Autosar version */
#if ((PWM_EMIOS_TYPES_AR_RELEASE_MAJOR_VERSION    != PWM_CFG_AR_RELEASE_MAJOR_VERSION) || \
     (PWM_EMIOS_TYPES_AR_RELEASE_MINOR_VERSION    != PWM_CFG_AR_RELEASE_MINOR_VERSION) || \
     (PWM_EMIOS_TYPES_AR_RELEASE_REVISION_VERSION != PWM_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Pwm_eMios_Types.h and Pwm_Cfg.h are different"
#endif
/* Check if header file and Pwm_Cfg header file are of the same software version */
#if ((PWM_EMIOS_TYPES_SW_MAJOR_VERSION != PWM_CFG_SW_MAJOR_VERSION) || \
     (PWM_EMIOS_TYPES_SW_MINOR_VERSION != PWM_CFG_SW_MINOR_VERSION) || \
     (PWM_EMIOS_TYPES_SW_PATCH_VERSION != PWM_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of Pwm_eMios_Types.h and Pwm_Cfg.h are different"
#endif

/*===============================================================================================
                                           CONSTANTS
===============================================================================================*/


/*===============================================================================================
                                       DEFINES AND MACROS
===============================================================================================*/
/**
* @{
* @brief          eMios module 0 and channel macros for module 0
*/
#define PWM_EMIOS_M0_C0    (EMIOS_0_CH_0)
#define PWM_EMIOS_M0_C1    (EMIOS_0_CH_1)
#define PWM_EMIOS_M0_C2    (EMIOS_0_CH_2)
#define PWM_EMIOS_M0_C3    (EMIOS_0_CH_3)
#define PWM_EMIOS_M0_C4    (EMIOS_0_CH_4)
#define PWM_EMIOS_M0_C5    (EMIOS_0_CH_5)
#define PWM_EMIOS_M0_C6    (EMIOS_0_CH_6)
#define PWM_EMIOS_M0_C7    (EMIOS_0_CH_7)
#define PWM_EMIOS_M0_C8    (EMIOS_0_CH_8)
#define PWM_EMIOS_M0_C9    (EMIOS_0_CH_9)
#define PWM_EMIOS_M0_C10   (EMIOS_0_CH_10)
#define PWM_EMIOS_M0_C11   (EMIOS_0_CH_11)
#define PWM_EMIOS_M0_C12   (EMIOS_0_CH_12)
#define PWM_EMIOS_M0_C13   (EMIOS_0_CH_13)
#define PWM_EMIOS_M0_C14   (EMIOS_0_CH_14)
#define PWM_EMIOS_M0_C15   (EMIOS_0_CH_15)
#define PWM_EMIOS_M0_C16   (EMIOS_0_CH_16)
#define PWM_EMIOS_M0_C17   (EMIOS_0_CH_17)
#define PWM_EMIOS_M0_C18   (EMIOS_0_CH_18)
#define PWM_EMIOS_M0_C19   (EMIOS_0_CH_19)
#define PWM_EMIOS_M0_C20   (EMIOS_0_CH_20)
#define PWM_EMIOS_M0_C21   (EMIOS_0_CH_21)
#define PWM_EMIOS_M0_C22   (EMIOS_0_CH_22)
#define PWM_EMIOS_M0_C23   (EMIOS_0_CH_23)
#define PWM_EMIOS_M0_C24   (EMIOS_0_CH_24)
#define PWM_EMIOS_M0_C25   (EMIOS_0_CH_25)
#define PWM_EMIOS_M0_C26   (EMIOS_0_CH_26)
#define PWM_EMIOS_M0_C27   (EMIOS_0_CH_27)
#define PWM_EMIOS_M0_C28   (EMIOS_0_CH_28)
#define PWM_EMIOS_M0_C29   (EMIOS_0_CH_29)
#define PWM_EMIOS_M0_C30   (EMIOS_0_CH_30)
#define PWM_EMIOS_M0_C31   (EMIOS_0_CH_31)

/**
* @{
* @brief          eMios module 1 and channel macros for module 1
*/
#define PWM_EMIOS_M1_C0    (EMIOS_1_CH_0)
#define PWM_EMIOS_M1_C1    (EMIOS_1_CH_1)
#define PWM_EMIOS_M1_C2    (EMIOS_1_CH_2)
#define PWM_EMIOS_M1_C3    (EMIOS_1_CH_3)
#define PWM_EMIOS_M1_C4    (EMIOS_1_CH_4)
#define PWM_EMIOS_M1_C5    (EMIOS_1_CH_5)
#define PWM_EMIOS_M1_C6    (EMIOS_1_CH_6)
#define PWM_EMIOS_M1_C7    (EMIOS_1_CH_7)
#define PWM_EMIOS_M1_C8    (EMIOS_1_CH_8)
#define PWM_EMIOS_M1_C9    (EMIOS_1_CH_9)
#define PWM_EMIOS_M1_C10   (EMIOS_1_CH_10)
#define PWM_EMIOS_M1_C11   (EMIOS_1_CH_11)
#define PWM_EMIOS_M1_C12   (EMIOS_1_CH_12)
#define PWM_EMIOS_M1_C13   (EMIOS_1_CH_13)
#define PWM_EMIOS_M1_C14   (EMIOS_1_CH_14)
#define PWM_EMIOS_M1_C15   (EMIOS_1_CH_15)
#define PWM_EMIOS_M1_C16   (EMIOS_1_CH_16)
#define PWM_EMIOS_M1_C17   (EMIOS_1_CH_17)
#define PWM_EMIOS_M1_C18   (EMIOS_1_CH_18)
#define PWM_EMIOS_M1_C19   (EMIOS_1_CH_19)
#define PWM_EMIOS_M1_C20   (EMIOS_1_CH_20)
#define PWM_EMIOS_M1_C21   (EMIOS_1_CH_21)
#define PWM_EMIOS_M1_C22   (EMIOS_1_CH_22)
#define PWM_EMIOS_M1_C23   (EMIOS_1_CH_23)
#define PWM_EMIOS_M1_C24   (EMIOS_1_CH_24)
#define PWM_EMIOS_M1_C25   (EMIOS_1_CH_25)
#define PWM_EMIOS_M1_C26   (EMIOS_1_CH_26)
#define PWM_EMIOS_M1_C27   (EMIOS_1_CH_27)
#define PWM_EMIOS_M1_C28   (EMIOS_1_CH_28)
#define PWM_EMIOS_M1_C29   (EMIOS_1_CH_29)
#define PWM_EMIOS_M1_C30   (EMIOS_1_CH_30)
#define PWM_EMIOS_M1_C31   (EMIOS_1_CH_31)

/**
* @{
* @brief          eMios module 1 and channel macros for module 2
*/
#define PWM_EMIOS_M2_C0    (EMIOS_2_CH_0)
#define PWM_EMIOS_M2_C1    (EMIOS_2_CH_1)
#define PWM_EMIOS_M2_C2    (EMIOS_2_CH_2)
#define PWM_EMIOS_M2_C3    (EMIOS_2_CH_3)
#define PWM_EMIOS_M2_C4    (EMIOS_2_CH_4)
#define PWM_EMIOS_M2_C5    (EMIOS_2_CH_5)
#define PWM_EMIOS_M2_C6    (EMIOS_2_CH_6)
#define PWM_EMIOS_M2_C7    (EMIOS_2_CH_7)
#define PWM_EMIOS_M2_C8    (EMIOS_2_CH_8)
#define PWM_EMIOS_M2_C9    (EMIOS_2_CH_9)
#define PWM_EMIOS_M2_C10   (EMIOS_2_CH_10)
#define PWM_EMIOS_M2_C11   (EMIOS_2_CH_11)
#define PWM_EMIOS_M2_C12   (EMIOS_2_CH_12)
#define PWM_EMIOS_M2_C13   (EMIOS_2_CH_13)
#define PWM_EMIOS_M2_C14   (EMIOS_2_CH_14)
#define PWM_EMIOS_M2_C15   (EMIOS_2_CH_15)
#define PWM_EMIOS_M2_C16   (EMIOS_2_CH_16)
#define PWM_EMIOS_M2_C17   (EMIOS_2_CH_17)
#define PWM_EMIOS_M2_C18   (EMIOS_2_CH_18)
#define PWM_EMIOS_M2_C19   (EMIOS_2_CH_19)
#define PWM_EMIOS_M2_C20   (EMIOS_2_CH_20)
#define PWM_EMIOS_M2_C21   (EMIOS_2_CH_21)
#define PWM_EMIOS_M2_C22   (EMIOS_2_CH_22)
#define PWM_EMIOS_M2_C23   (EMIOS_2_CH_23)
#define PWM_EMIOS_M2_C24   (EMIOS_2_CH_24)
#define PWM_EMIOS_M2_C25   (EMIOS_2_CH_25)
#define PWM_EMIOS_M2_C26   (EMIOS_2_CH_26)
#define PWM_EMIOS_M2_C27   (EMIOS_2_CH_27)
#define PWM_EMIOS_M2_C28   (EMIOS_2_CH_28)
#define PWM_EMIOS_M2_C29   (EMIOS_2_CH_29)
#define PWM_EMIOS_M2_C30   (EMIOS_2_CH_30)
#define PWM_EMIOS_M2_C31   (EMIOS_2_CH_31)

/** @} */

/**
* @brief   Bus Select: MC up counter
*/
#define MASTER_MODE_UP_COUNTER_U32         (0x00000010UL)
/**
* @brief   Bus Select: MC up/down counter
*/
#define MASTER_MODE_UP_DOWN_COUNTER_U32         (0x00000014UL)
/**
* @brief   Bus Select: MCB up
*/
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define MASTER_MODE_UP_BUFFERED_COUNTER_U32         (0x00000050UL)

/**
* @brief   Bus Select: MCB up/down
*/
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define MASTER_MODE_UP_DOWN_BUFFERED_COUNTER_U32              (0x00000054UL)
/**
* @brief   OPWFMB Buffered with Flag on B Match (period)
*/
#define PWM_MODE_OPWFMB_U32                     (0x00000058UL)
/**
* @brief   OPWMB Buffered with Flag on B Match (period)
*/
#define PWM_MODE_OPWMB_U32                      (0x00000060UL)
/**
* @brief   Output Pulse Width Modulation with Trigger
*/
#define PWM_MODE_OPWMT_U32                      (0x00000026UL)
/**
* @brief Center Aligned Output Pulse Width Modulation Buffered Lead Edge
*/
#define PWM_MODE_OPWMCB_U32                     (0x0000005DUL)
/**
* @brief Center Aligned Output Pulse Width Modulation Buffered with lead edge dead time
*/
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_MODE_OPWMCB_LEAD_DEADTIME_U32       (0x0000005DUL)
/**
* @brief Center Aligned Output Pulse Width Modulation Buffered with trial edge dead time
*/
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_MODE_OPWMCB_TRAIL_DEADTIME_U32      (0x0000005CUL)
 /**
     @brief   Double Action Output Compare
  */
#define PWM_MODE_DAOC_U32                       (0x00000006UL)
 /**
     @brief   Output Pulse Width and Frequency Modulation flag at match B, B update at match A 
  */
#define PWM_MODE_OPWFM_U32                       (0x00000018UL)
 /**
     @brief   Output Pulse Width Modulation flag at match B, B update at match A
  */
#define PWM_MODE_OPWM_U32                       (0x00000021UL)
 /**
     @brief   Center Aligned Output Pulse Width Modulation with Dead Time Insertion lead edge, flag at trail edge
  */
#define PWM_MODE_OPWMC_U32                       (0x0000001DUL)
 /**
     @brief   Center Aligned Output Pulse Width Modulation with Dead Time Insertion lead edge, flag at trail edge
  */
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_MODE_OPWMC_LEAD_DEADTIME_U32                       (0x0000001DUL)
 /**
     @brief   Center Aligned Output Pulse Width Modulation with Trail Time Insertion lead edge, flag at trail edge
  */
/** @violates @ref Pwm_eMIOS_Types_h_REF_3 This is required as per autosar Requirement */
#define PWM_MODE_OPWMC_TRAIL_DEADTIME_U32                       (0x0000001CUL)
 /**
* @brief   Bus select: counter bus[A]
*/
#define PWM_BUS_A_U32                  (0x00000000UL)
/**
* @brief   Bus select: channels [0,7]: counter busB, channels [8,15]: counter busC, channels [16,23]: counter busD
*/
#define PWM_BUS_DIVERSE_U32            (0x00000200UL)

/**
* @brief   Bus select: counter bus[F]
*/
#define PWM_BUS_F_U32                  (0x00000400UL)

/**
* @brief   Bus select: internal counter
*/
#define PWM_BUS_INTERNAL_COUNTER_U32   (0x00000600UL)
/**
* @brief   Bus select mask
*/
#define PWM_BUS_MASK_U32               (0x00000600UL)
/**
* @brief   Initialization option to set the channel prescaler value to 1
*/
#define PWM_PRES_1_U32                 (0x00000000UL)
/**
* @brief   Initialization option to set the channel prescaler value to 2
*/
#define PWM_PRES_2_U32                 (0x04000000UL)
/**
* @brief   Initialization option to set the channel prescaler value to 3
*/
#define PWM_PRES_3_U32                 (0x08000000UL)
/**
* @brief   Initialization option to set the channel prescaler value to 4
*/
#define PWM_PRES_4_U32                 (0x0C000000UL)
/**
* @brief   Initialization option to enable freeze mode for the channel
*/
#define PWM_FREEZE_ENABLE_U32          (0x80000000UL)
/**
* @brief   Channel 24 index
*/
#define PWM_EMIOS_CH_24            (24UL)

/**
* @brief   Pwm Master bus mode index
*/
#define PWM_MASTER_OPWMCB_MODE      (1U)
#define PWM_MASTER_OPWMB_MODE       (2U)
#define PWM_MASTER_DAOC_MODE        (3U)


/*===============================================================================================
                                             ENUMS
===============================================================================================*/


/*===============================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
===============================================================================================*/
#ifdef PWM_EMIOS_16_BITS_VARIANT
 #if  (PWM_EMIOS_16_BITS_VARIANT == STD_OFF)
/**
* @brief Unsigned long long integer at least 64 bit long.
* (0x00000000..0xFFFFFFFFFFFFFFFF) - 64 bit
*/
typedef unsigned long long Pwm_uint64;

/**
* @brief long long integer at least 64 bit long.
* (0x00000000..0xFFFFFFFFFFFFFFFF) - 64 bit
*/
typedef long long Pwm_sint64;
#endif
#endif

/**
* @brief          EMIOS HW module/channel id type
*
*/
typedef uint8 Pwm_eMios_ChannelType;


/**
* @brief          EMIOS unified channel control register value
*
*/
typedef uint32 Pwm_eMios_ControlType;

/**
* @brief EMIOS IP specific channel configuration structure for the PWM functionality
*
*/
typedef struct
{
    /** @brief Pwm signal polarity:   High or low */
    CONST(Pwm_OutputStateType, PWM_CONST) ePwmPolarity;
    /** @brief Pwm signal idle state: High or low */
    CONST(Pwm_OutputStateType, PWM_CONST) ePwmIdleState;
    /** @brief Default value for duty cycle: [0-0x8000] (0-100%) */
    CONST(uint16, PWM_CONST) u16PwmDefaultDutyCycle; 
    /** @brief Default value for period */
    CONST(Pwm_PeriodType, PWM_CONST) nPwmDefaultPeriod;
    /** @brief Assigned eMios channel id*/
    CONST(Pwm_eMios_ChannelType, PWM_CONST) u8HwChannel;
    /** @brief eMios channel parameters */
    CONST(Pwm_eMios_ControlType, PWM_CONST) u32ControlValue;
    /** @brief leading edge of the output pulse */
    CONST(Pwm_PeriodType, PWM_CONST) nPwmOffset;
    /** @brief Master mode used */
    CONST(uint8, PWM_CONST) u8MasterMode;
#if (PWM_FEATURE_DAOC == STD_ON)
    /** @brief Default value for period */
    CONST(Pwm_PeriodType, PWM_CONST) nPwmDaocModulo;
#endif
#if (PWM_FEATURE_OPWMT == STD_ON)
    /**< @brief delay of trigger generation */
    CONST(Pwm_PeriodType, PWM_CONST) nPwmTriggerDelay;
#endif
#if (PWM_FEATURE_OPWMCB == STD_ON)
    CONST(Pwm_PeriodType, PWM_CONST) nPwmDeadTime;/**< @brief deadtime value */
#endif
    /**< @brief delay of trigger delay adjust */
    CONST(boolean, PWM_CONST) bPwmOffsetTriggerDelay;

} Pwm_eMios_ChannelConfigType;

/**
* @brief      eMios IP specific configuration structure type
*/
typedef struct
{
    /** @brief Number of eMios channels in the Pwm configuration */
    CONST(Pwm_eMios_ChannelType, PWM_CONST) u8NumChannels;
    /** @brief Pointer to the configured channels for eMios */
    CONST(Pwm_eMios_ChannelConfigType, PWM_CONST) (*pChannelsConfig)[]; 
} Pwm_eMios_IpConfigType;



/*===============================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
===============================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* PWM_EMIOS_Types_H */

/** @} */
