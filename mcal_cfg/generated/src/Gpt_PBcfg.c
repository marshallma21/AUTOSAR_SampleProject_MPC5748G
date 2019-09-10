/**
*   @file    Gpt_PBcfg.c
*   @implements    Gpt_PBcfg.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt -  GPT driver configuration source file.
*   @details GPT driver source file, containing C and XPath constructs for generating Gpt
*            configuration source file for the Post-build configuration variant.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios_Stm_Pit
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
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
*     Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
*     on the significance of more than 31 characters. The used compilers use more than 31 chars for
*     identifiers.
*
* @section GPT_PBCFG_C_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before '#include'. This is an Autosar requirement about
* the memory management.
*
* @section GPT_PBCFG_C_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice. This is an Autosar requirement
* about the memory management.
*
* @section GPT_PBCFG_C_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* Compilers and linkers checked. Feature is supported
*
* @section GPT_PBCFG_C_REF_4
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section GPT_PBCFG_C_REF_5
* Violates MISRA 2004 Required Rule 8.8, an external variable or function should only be declared 
* in one file. The variable can not be included in only one file because of the arhitecture of the
* ASR 4.2 driver
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Gpt_Cfg.h"
#include "Gpt.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define GPT_VENDOR_ID_PBCFG_C                      43
#define GPT_AR_RELEASE_MAJOR_VERSION_PBCFG_C       4
#define GPT_AR_RELEASE_MINOR_VERSION_PBCFG_C       2
/** @violates @ref GPT_PBCFG_C_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define GPT_AR_RELEASE_REVISION_VERSION_PBCFG_C    2
#define GPT_SW_MAJOR_VERSION_PBCFG_C               1
#define GPT_SW_MINOR_VERSION_PBCFG_C               0
#define GPT_SW_PATCH_VERSION_PBCFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if ( GPT_VENDOR_ID_PBCFG_C != GPT_VENDOR_ID_CFG)
    #error "Gpt_PBcfg.c and Gpt_Cfg.h have different vendor ids"
#endif
/* Check if the header files are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_PBCFG_C != GPT_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_MINOR_VERSION_PBCFG_C != GPT_AR_RELEASE_MINOR_VERSION_CFG) || \
     (GPT_AR_RELEASE_REVISION_VERSION_PBCFG_C != GPT_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Gpt_PBcfg.c and Gpt_Cfg.h are different"
#endif
/* Check if the header files are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_PBCFG_C != GPT_SW_MAJOR_VERSION_CFG) || \
     (GPT_SW_MINOR_VERSION_PBCFG_C != GPT_SW_MINOR_VERSION_CFG) || \
     (GPT_SW_PATCH_VERSION_PBCFG_C != GPT_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of Gpt_PBcfg.c and Gpt_Cfg.h are different"
#endif

/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same vendor */
#if (GPT_VENDOR_ID_PBCFG_C != GPT_VENDOR_ID)
    #error "Gpt_PBcfg.c and Gpt.h have different vendor ids"
#endif
/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same Autosar version */
#if ((GPT_AR_RELEASE_MAJOR_VERSION_PBCFG_C != GPT_AR_RELEASE_MAJOR_VERSION) || \
     (GPT_AR_RELEASE_MINOR_VERSION_PBCFG_C != GPT_AR_RELEASE_MINOR_VERSION) || \
     (GPT_AR_RELEASE_REVISION_VERSION_PBCFG_C != GPT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif
/* Check if Gpt_PBcfg.c file and Gpt.h header file are of the same Software version */
#if ((GPT_SW_MAJOR_VERSION_PBCFG_C != GPT_SW_MAJOR_VERSION) || \
     (GPT_SW_MINOR_VERSION_PBCFG_C != GPT_SW_MINOR_VERSION) || \
     (GPT_SW_PATCH_VERSION_PBCFG_C != GPT_SW_PATCH_VERSION))
    #error "Software Version Numbers of Gpt_PBcfg.c and Gpt.h are different"
#endif

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define GPT_START_SEC_CODE
/** @violates @ref GPT_PBCFG_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_PBCFG_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/**
* @{
* @brief The callback functions defined by the user to be called as channel notifications
*/
/** @violates @ref GPT_PBCFG_C_REF_5 External variables and functions should only appear in one file*/
extern void SysDal_IntSch_TaskActivationIsr(void);
/** @} */
#define GPT_STOP_SEC_CODE
/** @violates @ref GPT_PBCFG_C_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref GPT_PBCFG_C_REF_2 Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define GPT_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"




#define GPT_CONF_CHANNELS_PB            1


#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
/* configuration predef timers here */

/** @violates @ref GPT_CFG_C_REF_4 MISRA 2004 Required Rule 8.10, could be made static */
static CONSTP2CONST(Gpt_HwPredefChannelConfigType, GPT_CONST, GPT_APPL_CONST) Gpt_pInitPredefTimerChannelPB[GPT_HW_PREDEFTIMER_NUM]=
{
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR
};
#endif /*GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON*/

static CONST(Gpt_ChannelConfigType, GPT_CONST) Gpt_InitChannelPB[GPT_CONF_CHANNELS_PB] =
{
    {   /*GptChannelConfiguration_INTOS configuration data*/
        (boolean)FALSE, /* Wakeup capability */
        &SysDal_IntSch_TaskActivationIsr, /* Channel notification */
#if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
         (EcuM_WakeupSourceType)0U, /* Wakeup information */
#endif
        (Gpt_ValueType)(4294967295U), /* Maximum ticks value*/
        (Gpt_ChannelModeType)(GPT_CH_MODE_CONTINUOUS), /* Timer mode:continous/one-shot */
        {
            (uint8)(PIT_0_CH_0), /* GPT physical channel no. */
            (uint8)(GPT_PIT_MODULE), /* hardware module ID */
            (boolean)(FALSE), /* Freeze Enable */
            (uint8)0U, /* PIT Clock divider - Unused */
            (uint8)0U, /* RTC clock source - Unused */
#if (GPT_STM_ENABLECLOCKSWITCH == STD_ON)
            (Gpt_PrescalerType)0U, /* STM clock source - Unused*/
#endif
        }
    }



};

/*PostBuild configuration structure.*/
/** @violates @ref GPT_PBCFG_C_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static*/


CONST(Gpt_ConfigType, GPT_CONST)  GptChannelConfigSet =


{
    (Gpt_ChannelType)1U,
    &Gpt_InitChannelPB,
#if(GPT_PREDEFTIMER_FUNCTIONALITY_API == STD_ON)
    Gpt_pInitPredefTimerChannelPB,
#endif 
    /*Hardware to logic channel mapping.*/
    {
        GPT_CHN_NOT_USED, /*mapping of STM_0_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of STM_0_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of STM_0_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of STM_0_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of STM_1_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of STM_1_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of STM_1_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of STM_1_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of STM_2_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of STM_2_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of STM_2_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of STM_2_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_RTI*/
        GptConf_GptChannelConfiguration_GptChannelConfiguration_INTOS, /*mapping of PIT_0_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_4*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_5*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_6*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_7*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_8*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_9*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_10*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_11*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_12*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_13*/
        GPT_CHN_NOT_USED, /*mapping of PIT_0_CH_14*/
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*Index not used */
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_4*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_5*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_6*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_7*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_8*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_9*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_10*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_11*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_12*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_13*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_14*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_15*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_16*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_17*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_18*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_19*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_20*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_21*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_22*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_23*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_24*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_25*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_26*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_27*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_28*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_29*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_30*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_0_CH_31*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_4*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_5*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_6*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_7*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_8*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_9*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_10*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_11*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_12*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_13*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_14*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_15*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_16*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_17*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_18*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_19*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_20*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_21*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_22*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_23*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_24*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_25*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_26*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_27*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_28*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_29*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_30*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_1_CH_31*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_0*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_1*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_2*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_3*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_4*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_5*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_6*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_7*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_8*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_9*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_10*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_11*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_12*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_13*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_14*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_15*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_16*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_17*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_18*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_19*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_20*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_21*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_22*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_23*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_24*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_25*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_26*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_27*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_28*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_29*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_30*/
        GPT_CHN_NOT_USED, /*mapping of EMIOS_2_CH_31*/
        GPT_CHN_NOT_USED /*mapping of RTC_0_CH_0*/
    }
};

#define GPT_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref GPT_PBCFG_C_REF_1 Only preprocessor statements and comments before '#include' */
/** @violates @ref GPT_PBCFG_C_REF_2 Precautions to prevent the contents of a header file being included twice.*/
#include "Gpt_MemMap.h"


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
