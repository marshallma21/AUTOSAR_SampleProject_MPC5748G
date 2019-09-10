[!CODE!][!//
/**
*   @file    Adc_PBcfg.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - Post Build configuration Adc source file.
*   @details Post Build configuration file for Adc driver.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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
* @section Adc_PBcfg_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before '#include'
* This is an Autosar memory management requirement.
*
* @section Adc_PBcfg_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Adc_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character signifiance and case
* sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 19.15, Repeated include file.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section Adc_PBcfg_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation is due to Autosar files and structures definitions.
*
* @section Adc_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* These notifications are declared as external in each variant configuration file.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. All compilers used support more than 31 chars for
* identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Adc.h"
/**  @violates @ref Adc_PBcfg_c_REF_4 Repeated include file */
#include "Adc_Reg_eSys_Adcdig.h"
[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
#include "Adc_Bctu.h"
#include "Adc_Reg_eSys_Bctu.h"
[!ENDIF!][!//

[!NOCODE!][!//
[!INCLUDE "Adc_VersionCheck_Src.m"!][!//
[!INCLUDE "Adc_RegOperations.m"!][!//
[!INCLUDE "Adc_Bctu_Cfg.m"!][!//
[!ENDNOCODE!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_VENDOR_ID_PBCFG_C                    43
/**
* @violates @ref Adc_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4
/**
* @violates @ref Adc_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_MINOR_VERSION_PBCFG_C     2
/**
* @violates @ref Adc_PBcfg_c_REF_3 The compiler/linker shall be checked to ensure that 31 character
* signifiance and case sensitivity are supported for external identifiers
*/
#define ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C  2
#define ADC_SW_MAJOR_VERSION_PBCFG_C             1
#define ADC_SW_MINOR_VERSION_PBCFG_C             0
#define ADC_SW_PATCH_VERSION_PBCFG_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC header file are of the same vendor */
#if (ADC_VENDOR_ID_PBCFG_C != ADC_VENDOR_ID)
    #error "Adc_PBcfg.c and Adc.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ADC_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PBCFG_C != ADC_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PBCFG_C != ADC_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_PBCFG_C != ADC_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_PBCFG_C != ADC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adcdig header file are of the same vendor */
#if (ADC_VENDOR_ID_PBCFG_C != ADC_VENDOR_ID_REG)
    #error "Adc_PBcfg.c and Adc_Reg_eSys_Adcdig.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Adcdig header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C != ADC_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PBCFG_C != ADC_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C != ADC_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc_Reg_eSys_Adcdig.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adcdig header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PBCFG_C != ADC_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_PBCFG_C != ADC_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_PBCFG_C != ADC_SW_PATCH_VERSION_REG) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc_Reg_eSys_Adcdig.h are different"
#endif

[!IF "NonAutosar/AdcEnableCtuControlModeApi"!][!//
/* Check if source file and Adc_Bctu.h header file are of the same vendor */
#if (ADC_VENDOR_ID_PBCFG_C != BCTU_VENDOR_ID)
    #error "Adc_PBcfg.c and Adc_Bctu.h have different vendor ids"
#endif

/* Check if source file and Adc_Bctu.h header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C != BCTU_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PBCFG_C != BCTU_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C != BCTU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc_Bctu.h are different"
#endif

/* Check if source file and Adc_Bctu.h header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PBCFG_C != BCTU_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_PBCFG_C != BCTU_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_PBCFG_C != BCTU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc_Bctu.h are different"
#endif


/* Check if source file and Adc_Reg_eSys_Bctu header file are of the same vendor */
#if (ADC_VENDOR_ID_PBCFG_C != BCTU_REG_VENDOR_ID)
    #error "Adc_PBcfg.c and Adc_Reg_eSys_Bctu.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Bctu header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_PBCFG_C != BCTU_REG_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_PBCFG_C != BCTU_REG_AR_RELEASE_MINOR_VERSION) || \
     (ADC_AR_RELEASE_REVISION_VERSION_PBCFG_C != BCTU_REG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_PBcfg.c and Adc_Reg_eSys_Bctu.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Bctu header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_PBCFG_C != BCTU_REG_SW_MAJOR_VERSION) || \
     (ADC_SW_MINOR_VERSION_PBCFG_C != BCTU_REG_SW_MINOR_VERSION) || \
     (ADC_SW_PATCH_VERSION_PBCFG_C != BCTU_REG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_PBcfg.c and Adc_Reg_eSys_Bctu.h are different"
#endif
[!ENDIF!][!//

/*==================================================================================================
                                           DEFINES AND MACROS
==================================================================================================*/

/** 
* @brief           Number of channels configured for each group.
*/
[!FOR "x" = "0" TO "count(AdcConfigSet/AdcHwUnit/*/AdcGroup/*)-1"!][!//
[!LOOP "AdcConfigSet/AdcHwUnit/*/AdcGroup/*"!][!//
[!IF "$x = AdcGroupId"!]
#define ADC_CFGSET[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_GROUP_[!"AdcGroupId"!]_CHANNELS      [!"num:i(count(AdcGroupDefinition/*))"!][!//
[!ENDIF!][!//
[!ENDLOOP!][!//
[!ENDFOR!][!//

[!CALL "Adc_Group_Define"!]

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

#define ADC_START_SEC_CODE
/**
 * @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include"
 * @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h
 */
#include "Adc_MemMap.h"

[!CALL "Adc_Notification_Config"!]
[!CALL "Adc_WdgNotification_Config"!]
[!CALL "Adc_Bctu_Callback_Configuration"!]

#define ADC_STOP_SEC_CODE
/**
 * @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include"
 * @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h
 */
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

[!CALL "Adc_ResultBuffer_Config"!]
  
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"
  
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

[!CALL "Adc_Group_Assignments"!]
[!CALL "Adc_WdgThreshold_Config"!]
[!CALL "Adc_Channel_Config"!]
[!CALL "Adc_HwTriggerSource_Config"!]
[!CALL "Adc_Group_Config"!]
[!CALL "Adc_Bctu_List_Trigger_Mode"!]
[!CALL "Adc_Bctu_Trigger_Configuration"!]
[!CALL "Adc_Bctu_Main_Configuration"!]

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

[!CALL "Adc_Channel_Pointer_Config"!]
  
#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/
#define ADC_START_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

[!CALL "Adc_Structure_Config"!]

#define ADC_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/** @violates @ref Adc_PBcfg_c_REF_1 only preprocessor statements and comments before "#include" */
/**  @violates @ref Adc_PBcfg_c_REF_2 Repeated include file Memmap.h*/
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

[!ENDCODE!][!//
