/**
*   @file    Adc_Adcdig.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - low level driver source file.
*   @details This is the low level driver source file,mainly implemented for the ADCDig hardware IP.
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
* @section Adc_Adcdig_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Adcdig_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h.
* There are different kinds of execution code sections.
*
* @section Adc_Adcdig_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and 
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section Adc_Adcdig_c_REF_4
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section Adc_Adcdig_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer.
* This is used for the Speed optimization of the memory access.
*
* @section Adc_Adcdig_c_REF_6
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* These objects are used in several files in the code.
*
* @section Adc_Adcdig_c_REF_7
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 characters significance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Adcdig_c_REF_8
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is due to the code complexity.
*
* @section Adc_Adcdig_c_REF_9
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware offset of the controller. The address calculated as an
* unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_Adcdig_c_REF_10
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation is to be used by IPV layer.
*
* @section Adc_Adcdig_c_REF_12
* Violates MISRA 2004 Required Rule 1.2, place reliance on undefined or unspecified behaviour
* This is used for the code complexity.
*
* @section Adc_Adcdig_c_REF_13
* Violates MISRA 2004 Required Rule 12.4, contain side effects of right-hand operand of a logical && or ||
* This is used for the code complexity.
*
* @section Adc_Adcdig_c_REF_15
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function. These objects are used in various parts of the code
*
* @section Adc_Adcdig_c_REF_16
* Violates MISRA 2004 Required Rule 10.3, The value of a complex expression of integer type may
* only be cast to a type that is narrower and of the same sightedness as the underlying type of the
* expression.
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
* 3) internal and external interfaces from this Unit
==================================================================================================*/
#include "Adc_Ipw.h"
#define USER_MODE_REG_PROT_ENABLED                (ADC_USER_MODE_REG_PROT_ENABLED)
#include "SilRegMacros.h"
#include "Adc_Reg_eSys_Adcdig.h"
#include "Adc_Adcdig_CfgEx.h"
#include "SchM_Adc.h"
#include "Adc_Adcdig.h"
#include "Mcal.h"

#ifdef ADC_DMA_SUPPORTED
  #include "CDD_Mcl.h"
#endif

#if ((STD_ON == ADC_HW_TRIGGER_API) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON))
  #include "Adc_Siul2.h"
#endif /* (STD_ON == ADC_HW_TRIGGER_API)... */

#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
  #include "Dem.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define ADC_AR_VENDOR_ID_ADCDIG_C                 43
/** @violates @ref Adc_Adcdig_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C     4
/** @violates @ref Adc_Adcdig_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C     2
/** @violates @ref Adc_Adcdig_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_C  2
#define ADC_SW_MAJOR_VERSION_ADCDIG_C             1
#define ADC_SW_MINOR_VERSION_ADCDIG_C             0
#define ADC_SW_PATCH_VERSION_ADCDIG_C             0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC IPW header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_ADCDIG_C != ADC_VENDOR_ID_IPW_H)
    #error "Adc_Adcdig.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if source file and ADC IPW header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != ADC_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != ADC_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_C != ADC_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
    #error "AutoSar Version Numbers of Adc_Adcdig.c and Adc_Ipw.h are different"
#endif

/* Check if source file and ADC IPW header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADCDIG_C != ADC_SW_MAJOR_VERSION_IPW_H) || \
     (ADC_SW_MINOR_VERSION_ADCDIG_C != ADC_SW_MINOR_VERSION_IPW_H) || \
     (ADC_SW_PATCH_VERSION_ADCDIG_C != ADC_SW_PATCH_VERSION_IPW_H) \
    )
    #error "Software Version Numbers of Adc_Adcdig.c and Adc_Ipw.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adcdig header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_ADCDIG_C != ADC_VENDOR_ID_REG)
    #error "Adc_Adcdig.c and Adc_Reg_eSys_Adcdig.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Adcdig header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != ADC_AR_RELEASE_MAJOR_VERSION_REG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != ADC_AR_RELEASE_MINOR_VERSION_REG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_C != ADC_AR_RELEASE_REVISION_VERSION_REG) \
    )
    #error "AutoSar Version Numbers of Adc_Adcdig.c and Adc_Reg_eSys_Adcdig.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Adcdig header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADCDIG_C != ADC_SW_MAJOR_VERSION_REG) || \
     (ADC_SW_MINOR_VERSION_ADCDIG_C != ADC_SW_MINOR_VERSION_REG) || \
     (ADC_SW_PATCH_VERSION_ADCDIG_C != ADC_SW_PATCH_VERSION_REG) \
    )
    #error "Software Version Numbers of Adc_Adcdig.c and Adc_Reg_eSys_Adcdig.h are different"
#endif

/* Check if source file and Adc_Adcdig_CfgEx header file are of the same vendor */
#if (ADC_AR_VENDOR_ID_ADCDIG_C != ADC_VENDOR_ID_ADCDIG_CFGEX)
    #error "Adc_Adcdig.c and Adc_Adcdig_CfgEx.h have different vendor ids"
#endif

/* Check if source file and Adc_Adcdig_CfgEx header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_CFGEX) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_CFGEX) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_C != ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_CFGEX) \
    )
    #error "AutoSar Version Numbers of Adc_Adcdig.c and Adc_Adcdig_CfgEx.h are different"
#endif

/* Check if source file and Adc_Adcdig_CfgEx header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADCDIG_C != ADC_SW_MAJOR_VERSION_ADCDIG_CFGEX) || \
     (ADC_SW_MINOR_VERSION_ADCDIG_C != ADC_SW_MINOR_VERSION_ADCDIG_CFGEX) || \
     (ADC_SW_PATCH_VERSION_ADCDIG_C != ADC_SW_PATCH_VERSION_ADCDIG_CFGEX) \
    )
    #error "Software Version Numbers of Adc_Adcdig.c and Adc_Adcdig_CfgEx.h are different"
#endif

/* Check if source file and Adc_Adcdig header file are from the same vendor */
#if (ADC_AR_VENDOR_ID_ADCDIG_C != ADC_VENDOR_ID_ADCDIG)
    #error "Adc_Adcdig.c and Adc_Adcdig.h have different vendor ids"
#endif

/* Check if source file and Adc_Adcdig header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != ADC_AR_RELEASE_MINOR_VERSION_ADCDIG) || \
     (ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_C != ADC_AR_RELEASE_REVISION_VERSION_ADCDIG) \
    )
    #error "AutoSar Version Numbers of Adc_Adcdig.c and Adc_Adcdig.h are different"
#endif

/* Check if source file and Adc_Adcdig header file are of the same Software version */
#if ((ADC_SW_MAJOR_VERSION_ADCDIG_C != ADC_SW_MAJOR_VERSION_ADCDIG) || \
     (ADC_SW_MINOR_VERSION_ADCDIG_C != ADC_SW_MINOR_VERSION_ADCDIG) || \
     (ADC_SW_PATCH_VERSION_ADCDIG_C != ADC_SW_PATCH_VERSION_ADCDIG) \
    )
    #error "Software Version Numbers of Adc_Adcdig.c and Adc_Adcdig.h are different"
#endif

#if ((STD_ON == ADC_HW_TRIGGER_API) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON))
  /* Check if source file and Adc_Siul2.h header file are from the same vendor */
  #if (ADC_AR_VENDOR_ID_ADCDIG_C != ADC_SIUL2_VENDOR_ID)
      #error "Adc_Adcdig.c and Adc_Siul2.h have different vendor ids"
  #endif
  /* Check if source file and Adc_Siul2.h header file are of the same Autosar version */
  #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != ADC_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
       (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != ADC_SIUL2_AR_RELEASE_MINOR_VERSION) || \
       (ADC_AR_RELEASE_REVISION_VERSION_ADCDIG_C != ADC_SIUL2_AR_RELEASE_REVISION_VERSION) \
      )
      #error "AutoSar Version Numbers of Adc_Adcdig.c and Adc_Siul2.h are different"
  #endif
  /* Check if source file and Adc_Siul2.h header file are of the same Software version */
  #if ((ADC_SW_MAJOR_VERSION_ADCDIG_C != ADC_SIUL2_SW_MAJOR_VERSION) || \
       (ADC_SW_MINOR_VERSION_ADCDIG_C != ADC_SIUL2_SW_MINOR_VERSION) || \
       (ADC_SW_PATCH_VERSION_ADCDIG_C != ADC_SIUL2_SW_PATCH_VERSION) \
      )
      #error "Software Version Numbers of Adc_Adcdig.c and Adc_Siul2.h are different"
  #endif
#endif /* (STD_ON == ADC_HW_TRIGGER_API)... */

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#ifdef ADC_DMA_SUPPORTED
/* Check if source file and DMA header file are of the same Autosar version */
#if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
     (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != MCL_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Adcdig.c and CDD_Mcl.h are different"
#endif
#endif
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 /* Check if source file and Dem header file are of the same version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != DEM_AR_RELEASE_MINOR_VERSION) \
     )
    #error "AutoSar Version Numbers of Adc_Adcdig.c and Dem.h are different"
 #endif
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
  /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adcdig.c and Mcal.h are different"
 #endif
   /* Check if source file and SilREgMacros header file are of the same AutoSar version */
 #if ((ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
      (ADC_AR_RELEASE_MINOR_VERSION_ADCDIG_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adcdig.c and SilRegMacros.h are different"
 #endif
#endif

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

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h */
/** @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "Adc_MemMap.h"

/**
* @brief          MHT groups array.
* @details        This array is used to handle the MHT groups in an efficient manner
*                 through the driver code.
*/
/** @violates @ref Adc_Adcdig_c_REF_15 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
/** @violates @ref Adc_Adcdig_c_REF_10 External linkage */
VAR(Adc_GroupType, ADC_VAR) Adc_Adcdig_aMhtChannelGroup[ADC_MAX_HW_UNITS_CFG][ADC_MAX_GROUPS_PER_HW_UNIT];

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

#if ((ADC_BCTU_AVAILABLE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON))
#define ADC_START_SEC_VAR_INIT_BOOLEAN
/** @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h */
/** @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "Adc_MemMap.h"

/** @violates @ref Adc_Adcdig_c_REF_10 internal linkage or external linkage */
/** @violates @ref Adc_Adcdig_c_REF_15 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
VAR(boolean, ADC_VAR) Adc_Adcdig_abAlreadyCleared[ADC_MAX_GROUPS] = {(boolean)FALSE};

#define ADC_STOP_SEC_VAR_INIT_BOOLEAN
/** @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h */
/** @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include" */
#include "Adc_MemMap.h"
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) && (ADC_HW_TRIGGER_API == STD_ON) */

#ifdef ADC_DMA_SUPPORTED
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/**
 * @brief The array to store the TCD configuration for each channel segment
 */
VAR(Mcl_DmaTcdAttributesType, ADC_VAR) Adc_Adcdig_aDmaTcdConfig[ADC_MAX_HW_UNITS_CFG][ADC_MAX_CHANNEL_SEGMENTS_U8];

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

/** @violates @ref Adc_Adcdig_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
/**
* @brief          Internal buffer used by DMA to transfer blocks with gaps
* @violates @ref Adc_Adcdig_c_REF_10 External linkage
*/
VAR(Adc_ValueGroupType, ADC_VAR) Adc_Adcdig_aDmaInternalResultBuffer[ADC_MAX_HW_UNITS_CFG];
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */

/**
 * @brief Declare the memory to store DMA TCD configuration for scatter gather node
 */
ALIGNED_VARS_START(ADC_CODE, ADCDIG_TCD_REG_SIZE_U8)
VAR_ALIGN(VAR(Mcl_DmaTcdType, ADC_VAR) Adc_Adcdig_aDmaTcdConfigMem[ADC_MAX_HW_UNITS_CFG][ADC_MAX_CHANNEL_SEGMENTS_U8][ADCDIG_DMA_NUM_TCD_U8], ADCDIG_TCD_REG_SIZE_U8)
ALIGNED_VARS_STOP()

/** @violates @ref Adc_Adcdig_c_REF_7 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED_NO_CACHEABLE
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_BCTU_AVAILABLE == STD_ON)
#define ADC_START_SEC_VAR_INIT_8
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/**
* @brief          Index into the BCTU trigger buffer for each unit
*/
/** @violates @ref Adc_Adcdig_c_REF_15 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern VAR(uint8, ADC_VAR) Adc_Bctu_au8ResultIndex[ADC_MAX_HW_UNITS]; 

#define ADC_STOP_SEC_VAR_INIT_8
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/**
* @brief          Used to point the configuration structure.
*/
/** @violates @ref Adc_Adcdig_c_REF_6  External object declared more than once*/
extern P2CONST(Adc_ConfigType, ADC_VAR, ADC_APPL_CONST) Adc_pCfgPtr;

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
/**
* @brief          Clock mode in use 
*/
extern VAR(Adc_DualClockModeType, AUTOMATIC) Adc_ClockMode;
#endif /*if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)*/
#endif /*if (ADC_DUAL_CLOCK_MODE == STD_ON)*/

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/** @violates @ref Adc_Adcdig_c_REF_6  External object declared more than once*/
extern VAR(Adc_GroupStatusType, ADC_VAR) Adc_aGroupStatus[ADC_MAX_GROUPS];
/** @violates @ref Adc_Adcdig_c_REF_6  External object declared more than once*/
extern VAR(Adc_UnitStatusType , ADC_VAR) Adc_aUnitStatus[ADC_MAX_HW_UNITS];

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
/**
* @brief          This array is used to handle the MHT groups in
*                 an efficient manner through the driver code.
*/
extern VAR(Adc_GroupType, ADC_VAR) Adc_Adcdig_aMhtChannelGroup[ADC_MAX_HW_UNITS_CFG][ADC_MAX_GROUPS_PER_HW_UNIT];
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
 * @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include"
 * @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h
 */
#include "Adc_MemMap.h"
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/** @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
LOCAL_INLINE FUNC(Adc_HwTriggerTimerType, ADC_CODE) Adc_Adcdig_GetIndexOfCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
);
#endif
#ifdef ADC_DMA_SUPPORTED
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_StartDmaOperation
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
);
#endif /* ADC_DMA_SUPPORTED */

static FUNC(Std_ReturnType, ADC_CODE)  Adc_Adcdig_WritePowerDownBit
(
 VAR(Adc_HwUnitType,AUTOMATIC)Unit, 
 VAR(boolean, AUTOMATIC) bSetPowerDown
);

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          Initializes the conversion time registers.
* @details        Initializes the conversion time registers.
*
* @param[in]      Unit            the hardware Unit.
* @param[in]      ConvTime        the value to be written in ADC_CTR0.
* @param[in]      ConvTime1       the value to be written in ADC_CTR1.
* @param[in]      ConvTime2       the value to be written in ADC_CTR2.
*
* @return         void
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_SetCtrRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime,
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime1,
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime2
)
{
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CtrPresent[Unit][ADC_CTR0_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_CTR0_REG_ADDR32(Unit),ConvTime);
    }
#if (ADC_CTR1_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CtrPresent[Unit][ADC_CTR1_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_CTR1_REG_ADDR32(Unit),ConvTime1);
    }
#else
    (void)ConvTime1;
#endif
#if (ADC_CTR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CtrPresent[Unit][ADC_CTR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_CTR2_REG_ADDR32(Unit),ConvTime2);
    }
#else
    (void)ConvTime2;
#endif
}

/**
* @brief          Initializes the presampling registers.
* @details        Initializes the presampling registers.
*
* @param[in]      Unit               the hardware Unit.
* @param[in]      u32Precision       the value to be written in ADC_PSR0.
* @param[in]      u32Extended        the value to be written in ADC_PSR1.
* @param[in]      u32External        the value to be written in ADC_PRS2.
*
* @return         void
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_SetPsrRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32Precision,
    VAR(uint32, AUTOMATIC) u32Extended,
    VAR(uint32, AUTOMATIC) u32External
)
{
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_PsrPresent[Unit][ADC_PSR0_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_PSR0_REG_ADDR32(Unit), u32Precision);
    }

#if (ADC_PSR1_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_PsrPresent[Unit][ADC_PSR1_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_PSR1_REG_ADDR32(Unit), u32Extended);
    }
#else
    (void)u32Extended;
#endif /* (ADC_PSR1_AVAILABLE == STD_ON) */

#if (ADC_PSR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_PsrPresent[Unit][ADC_PSR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_PSR2_REG_ADDR32(Unit), u32External);
    }
#else
    (void)u32External;
#endif /* (ADC_PSR2_AVAILABLE == STD_ON) */
}

#if ((ADC_DEINIT_API == STD_ON) || (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) || (ADC_SETCHANNEL_API == STD_ON) || \
     ((ADC_HW_TRIGGER_API == STD_ON) && (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)) \
    )
/**
* @brief          Initializes the Normal Conversion Mask registers.
* @details        Initializes the Normal Conversion Mask registers.
*
* @param[in]      Unit               the hardware Unit.
* @param[in]      u32Precision       the value to be written in ADC_u32NCMR0.
* @param[in]      u32Extended        the value to be written in ADC_u32NCMR1.
* @param[in]      u32External        the value to be written in ADC_u32NCMR2.
*
* @return         void
*/
/** @violates @ref Adc_Adcdig_c_REF_10 internal linkage or external linkage */
FUNC(void, ADC_CODE) Adc_Adcdig_SetNcmrRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32Precision,
    VAR(uint32, AUTOMATIC) u32Extended,
    VAR(uint32, AUTOMATIC) u32External
)
{
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_NcmrPresent[Unit][ADC_NCMR0_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_NCMR0_REG_ADDR32(Unit), u32Precision);
    }
#if (ADC_NCMR1_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_NcmrPresent[Unit][ADC_NCMR1_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_NCMR1_REG_ADDR32(Unit), u32Extended);
    }
#else
    (void)u32Extended;
#endif /* (ADC_NCMR1_AVAILABLE == STD_ON) */

#if (ADC_NCMR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_NcmrPresent[Unit][ADC_NCMR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_NCMR2_REG_ADDR32(Unit), u32External);
    }
#else
    (void)u32External;
#endif /* (ADC_NCMR2_AVAILABLE == STD_ON) */
}
#endif /* (ADC_DEINIT_API == STD_ON)... */

#if ((ADC_DEINIT_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) || \
     ((ADC_ENABLE_START_STOP_GROUP_API == STD_ON) && (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON)) \
    )
/**
* @brief          Initializes the Injected Conversion Mask registers.
* @details        Initializes the Injected Conversion Mask registers.
*
* @param[in]      Unit               the hardware Unit.
* @param[in]      u32Precision       the value to be written in ADC_JCMR0.
* @param[in]      u32Extended        the value to be written in ADC_JCMR1.
* @param[in]      u32External        the value to be written in ADC_JCMR2.
*
* @return         void
*/
/** @violates @ref Adc_Adcdig_c_REF_10 internal linkage or external linkage */
FUNC(void, ADC_CODE) Adc_Adcdig_SetJcmrRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32Precision,
    VAR(uint32, AUTOMATIC) u32Extended,
    VAR(uint32, AUTOMATIC) u32External
)
{
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_JcmrPresent[Unit][ADC_JCMR0_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_JCMR0_REG_ADDR32(Unit), u32Precision);
    }
#if (ADC_JCMR1_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_JcmrPresent[Unit][ADC_JCMR1_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_JCMR1_REG_ADDR32(Unit), u32Extended);
    }
#else
    (void)u32Extended;
#endif /* (ADC_NCMR1_AVAILABLE == STD_ON) */

#if (ADC_JCMR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_JcmrPresent[Unit][ADC_JCMR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_JCMR2_REG_ADDR32(Unit), u32External);
    }
#else
    (void)u32External;
#endif /* (ADC_NCMR2_AVAILABLE == STD_ON) */
}
#endif /* (ADC_DEINIT_API == STD_ON)... */

#ifdef ADC_DMA_SUPPORTED
/**
* @brief          Initializes the Dma Channel select registers.
* @details        Initializes the Dma Channel select registers.
*
* @param[in]      Unit               the hardware Unit.
* @param[in]      u32Precision       the value to be written in ADC_DMAR0.
* @param[in]      u32Extended        the value to be written in ADC_DMAR1.
* @param[in]      u32External        the value to be written in ADC_DMAR2.
*
* @return         void
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_SetDmarRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_ChannelType, AUTOMATIC) PhChannel
)
{
    VAR(uint32, AUTOMATIC) u32Mask = 0UL;
    
    u32Mask = (1UL << (PhChannel%32U));
    if (ADC_ED_PRICISION_CH_U8 >= PhChannel)
    {
        if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_DmarPresent[Unit][ADC_DMAR0_INDEX])
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_DMAR0_REG_ADDR32(Unit), u32Mask);
        }
    }
#if (ADC_DMAR1_AVAILABLE == STD_ON)
    else if (ADC_ED_EXTENDED_CH_U8 >= PhChannel)
    {
        if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_DmarPresent[Unit][ADC_DMAR1_INDEX])
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_DMAR1_REG_ADDR32(Unit), u32Mask);
        }
    }
#endif /* (ADC_DMAR1_AVAILABLE == STD_ON) */

#if (ADC_DMAR2_AVAILABLE == STD_ON)
    else if (ADC_ED_EXTERNAL_CH_U8 >= PhChannel)
    {
        if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_DmarPresent[Unit][ADC_DMAR2_INDEX])
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_DMAR2_REG_ADDR32(Unit), u32Mask);
        }
    }
#endif /* (ADC_DMAR2_AVAILABLE == STD_ON) */
    else
    {
        /*Nothing for misra*/
    }
}
#endif /* #ifdef ADC_DMA_SUPPORTED */

#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
/**
* @brief          Initializes the Ncmr mask for group.
* @details        Initializes the Ncmr mask for group.
*
* @param[in]      pCfgPtr       Pointer to configuration structure.
*
* @return         void
*
* @pre            Driver must be initialized.
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_InitNcmrMask
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
)
{
    VAR(Adc_GroupType,AUTOMATIC) Group = 0U; /* Group Index */
    VAR(Adc_GroupType,AUTOMATIC) GroupIndex = 0U; /* Group Index */

    /* Initialize Group Status structures to beginning values */
    for (Group = 0U; Group < pCfgPtr->GroupCount; Group++)  /* GroupCount = total number of groups */
    {
       /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing */
        GroupIndex = (Adc_GroupType)pCfgPtr->pGroups[Group].EnableChDisableChGroupIndex;
        if(ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupIndex)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_aNCMRxMask[GroupIndex].Adc_u32NCMR0 = pCfgPtr->pGroups[Group].u32PrecisionChannel;
    #if (ADC_NCMR1_AVAILABLE == STD_ON)
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_aNCMRxMask[GroupIndex].Adc_u32NCMR1 = pCfgPtr->pGroups[Group].u32ExtendedChannel;
    #endif /* (ADC_NCMR1_AVAILABLE == STD_ON) */
    #if (ADC_NCMR2_AVAILABLE == STD_ON)
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_aNCMRxMask[GroupIndex].Adc_u32NCMR2 = pCfgPtr->pGroups[Group].u32ExternalChannel;
    #endif /* (ADC_NCMR2_AVAILABLE == STD_ON) */
        }
    }
}
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */

/**
* @brief          Initializes the ADC hardware.
* @details        Initializes the ADC hardware as per configuration.
*
* @param[in]      Unit         The hardware Unit.
* @param[in]      pConfigPtr   Pointer to the hardware configuratiojn structure to be used.
*
* @return         Std_ReturnType
*
* @pre            Driver must be initialized.
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_InitUnitHardware
(
    VAR(Adc_HwUnitType,AUTOMATIC)Unit,
    P2CONST(Adc_Adcdig_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex; /* Hardware index in the structure*/
    VAR(uint32, AUTOMATIC) u32PscrVal;
#ifdef ADC_WDG_SUPPORTED
    VAR(uint32, AUTOMATIC) u32WtimrValue = 0UL; /* watchdog timer temp variable */
#endif /* ADC_WDG_SUPPORTED */
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON)
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime1 = 0U;
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime2 = 0U;
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_ON */
#if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_ON)
    VAR(Adc_GroupType,AUTOMATIC) Group = 0U; /* Group Index */
    VAR(uint32, AUTOMATIC)  u32Precision = 0U;
    VAR(uint32, AUTOMATIC)  u32Extended = 0U;
    VAR(uint32, AUTOMATIC)  u32External = 0U;
#endif /*ADC_SET_ADC_PRESAMPLE_ONCE == STD_ON) */

    /* enter into power-down mode */
    if((Std_ReturnType)E_NOT_OK == Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE))
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return (Std_ReturnType)E_NOT_OK;
    }

    /* Get the index of hardware Unit*/
    HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
    
    /*ClkPrescaler, Auto Clock Off , Offset Refresh, Right align and overwrite */
    /**
    * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), (pConfigPtr[HwIndex].u32AdcMainConfig | pConfigPtr[HwIndex].u32AdcPrescale));
    
    /* Write the configured power down exit delay value into PDEDR register */
    /**
    * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
    * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer.
    * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
    */
    REG_WRITE32(ADCDIG_PDEDR_REG_ADDR32(Unit),pConfigPtr[HwIndex].u8AdcPwrDownDelay);

    /* comes out from PowerDown */
    if((Std_ReturnType)E_NOT_OK == Adc_Adcdig_WritePowerDownBit(Unit, (boolean)FALSE))
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return (Std_ReturnType)E_NOT_OK;
    }

#if (ADC_DSDR_AVAILABLE == STD_ON)
    /* Write the configured mux delay value into DSDR register */
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_DsdrPresent[Unit])
    {
        /**
        * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer
        * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
        */
        REG_WRITE32(ADCDIG_DSDR_REG_ADDR32(Unit),pConfigPtr[HwIndex].u16AdcMuxDelay);
    }
#endif /* (ADC_DSDR_AVAILABLE == STD_ON) */

#ifdef ADC_WDG_SUPPORTED
    /* Enable WatchDog Threshold Interrupt*/
    u32WtimrValue = ADCDIG_WTH0_LOW_ISR_EN_U32 | ADCDIG_WTH1_LOW_ISR_EN_U32 | ADCDIG_WTH2_LOW_ISR_EN_U32 |
                    ADCDIG_WTH3_LOW_ISR_EN_U32 | ADCDIG_WTH4_LOW_ISR_EN_U32 | ADCDIG_WTH5_LOW_ISR_EN_U32 |
                    ADCDIG_WTH6_LOW_ISR_EN_U32 | ADCDIG_WTH7_LOW_ISR_EN_U32 | ADCDIG_WTH8_LOW_ISR_EN_U32 |
                    ADCDIG_WTH9_LOW_ISR_EN_U32 | ADCDIG_WTH10_LOW_ISR_EN_U32 | ADCDIG_WTH11_LOW_ISR_EN_U32 |
                    ADCDIG_WTH12_LOW_ISR_EN_U32 | ADCDIG_WTH13_LOW_ISR_EN_U32 | ADCDIG_WTH14_LOW_ISR_EN_U32 |
                    ADCDIG_WTH15_LOW_ISR_EN_U32 | ADCDIG_WTH0_HIGH_ISR_EN_U32 | ADCDIG_WTH1_HIGH_ISR_EN_U32 |
                    ADCDIG_WTH2_HIGH_ISR_EN_U32 | ADCDIG_WTH3_HIGH_ISR_EN_U32 | ADCDIG_WTH4_HIGH_ISR_EN_U32 |
                    ADCDIG_WTH5_HIGH_ISR_EN_U32 | ADCDIG_WTH6_HIGH_ISR_EN_U32 | ADCDIG_WTH7_HIGH_ISR_EN_U32 |
                    ADCDIG_WTH8_HIGH_ISR_EN_U32 | ADCDIG_WTH9_HIGH_ISR_EN_U32 | ADCDIG_WTH10_HIGH_ISR_EN_U32 |
                    ADCDIG_WTH11_HIGH_ISR_EN_U32 | ADCDIG_WTH12_HIGH_ISR_EN_U32 | ADCDIG_WTH13_HIGH_ISR_EN_U32 |
                    ADCDIG_WTH14_HIGH_ISR_EN_U32 | ADCDIG_WTH15_HIGH_ISR_EN_U32;

    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_WTIMR_REG_ADDR32(Unit), u32WtimrValue);
#endif /* ADC_WDG_SUPPORTED */

    /* Presampling related configurations/initializations */
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    u32PscrVal = (uint32)(((uint32)(Adc_pCfgPtr->pAdc[HwIndex].u8PreVal0) << 1U) | \
                          ((uint32)(Adc_pCfgPtr->pAdc[HwIndex].u8PreVal1) << 3U) |
#if (ADC_EXTERNAL_CH_AVAILABLE == STD_ON)
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                          ((uint32)(Adc_pCfgPtr->pAdc[HwIndex].u8PreVal2) << 5U) |
#endif
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                          (uint32)Adc_pCfgPtr->pAdc[HwIndex].u8PreConv
                         );
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_PSCR_REG_ADDR32(Unit), u32PscrVal);

    #if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_ON)
    for (Group = 0U; Group < Adc_pCfgPtr->GroupCount; Group++)  /* GroupCount = total number of groups */
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (Unit == Adc_pCfgPtr->pGroups[Group].HwUnit)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            u32Precision |= Adc_pCfgPtr->pGroups[Group].u32PrecisionPsr;
    #if (ADC_PSR1_AVAILABLE == STD_ON)
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            u32Extended |= Adc_pCfgPtr->pGroups[Group].u32ExtendedPsr;
    #endif /* (ADC_PSR1_AVAILABLE == STD_ON) */
    #if (ADC_PSR2_AVAILABLE == STD_ON)
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            u32External |= Adc_pCfgPtr->pGroups[Group].u32ExternalPsr;
    #endif /* (ADC_PSR2_AVAILABLE == STD_ON) */
        }
    }
    /* set once presampling for every ADC HW Unit using setting of the all groups belonging to the Unit */
    Adc_Adcdig_SetPsrRegisters(Unit, u32Precision, u32Extended, u32External);
    #endif /* ADC_SET_ADC_PRESAMPLE_ONCE == STD_ON */

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON)
    #if (ADC_CTR1_AVAILABLE == STD_ON)
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ConvTime1 = Adc_pCfgPtr->pAdc[HwIndex].ConvTimeNormal1;
    #endif /* (ADC_CTR1_AVAILABLE == STD_ON) */
    #if (ADC_CTR2_AVAILABLE == STD_ON)
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ConvTime2 = Adc_pCfgPtr->pAdc[HwIndex].ConvTimeNormal2;
    #endif /* ADC_CTR2_AVAILABLE == STD_ON */
    /*  Program Conversion Time*/
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Adc_Adcdig_SetCtrRegisters(Unit, Adc_pCfgPtr->pAdc[HwIndex].ConvTimeNormal, ConvTime1, ConvTime2);
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_ON */
   
    return (Std_ReturnType)E_OK;
}

#ifdef ADC_WDG_SUPPORTED
/**
* @brief          Set channel watchdog threshold registers.
* @details        Used to set channel watchdog threshold registers.
*
* @param[in]      Unit        The hardware Unit.
* @param[in]      u8Th        The Threshold register to be used.
* @param[in]      Ch          The hardware Adc channel .
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_SetThresholds
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint8, AUTOMATIC) u8Th,
    VAR(Adc_ChannelType, AUTOMATIC) Ch
)
{
    VAR(uint32, AUTOMATIC) u32Mask ;
    VAR(uint32, AUTOMATIC) u32Index = ((uint32)Ch) / 8UL;

    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CwselrPresent[Unit][u32Index])
    {
        u32Mask = ((uint32)(u8Th))<<((uint32)((((uint32)Ch)%8UL)*(0x4UL)));
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_CWSELRx_REG_ADDR32(Unit, u32Index), u32Mask);
    }
}

/**
* @brief          Initializes the limit checking hardware.
* @details        Initializes the limit checking hardware configured.
*
* @param[in]      pCfgPtr      Pointer to the configuration structure.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_InitUnitLimitChecking
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = 0U;
    VAR(Adc_HwUnitType, AUTOMATIC) Index = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) Ch = 0U;
    P2CONST(Adc_Adcdig_ChannelConfigurationType, AUTOMATIC, ADC_APPL_CONST)  pChConf;

    for(HwIndex = 0U; HwIndex < pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Unit = pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId;
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        for (Index = 0U; Index < pCfgPtr->pAdc[HwIndex].ConfiguredThCount; Index++)
        {
            /**
             * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer
             * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
             * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
             */
            REG_WRITE32(ADCDIG_THRHLRx_REG_ADDR32(Unit, pCfgPtr->pAdc[HwIndex].pThConfigured[Index].u8Register), \
                                                     pCfgPtr->pAdc[HwIndex].pThConfigured[Index].u32ThValues \
                       );
        }

        for(Ch = 0U; Ch < pCfgPtr->Misc.aAdc_Channels[Unit]; Ch++)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pChConf = &(pCfgPtr->pChannels[Unit][Ch]);
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if(ADC_UNUSED_THRESHOLD_U8 != pChConf->u8ThReg)
            {
                /* program the CWSEL register (channel watchdog select register) */
                Adc_Adcdig_SetThresholds(Unit, pChConf->u8ThReg, (Adc_ChannelType)pChConf->ChId);
            }
        }
    }
}
#endif /* ADC_WDG_SUPPORTED */

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
/**
* @brief          Initializes the multiple hardware triggers structures.
* @details        Initializes the multiple hardware triggers structures.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_InitUnitMht
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(Adc_HwUnitType, AUTOMATIC) Index;
    VAR(Adc_GroupType, AUTOMATIC) Group;
    VAR(uint8, AUTOMATIC) u8PosGr;
    
    for (Index = 0U; Index < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; Index++)
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Unit = (Adc_HwUnitType)(Adc_pCfgPtr->pAdc[Index].AdcHardwareUnitId);
        /* Get the index of hardware Unit*/
        HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
        Group = (Adc_GroupType)0;
        u8PosGr = 0U;
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing */
        for(Group = 0U; Group < pCfgPtr->Misc.aAdc_Groups[Unit]; Group++)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing */
            if (ADC_MHT_GROUP_TYPE == pCfgPtr->pGroups[Group].IsMHTGroup)
            {
                /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing */
                Adc_Adcdig_aMhtChannelGroup[HwIndex][u8PosGr] = (Adc_GroupType)Group;
                u8PosGr++;
            }
        }
    }
}
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
#if (ADC_BCTU_AVAILABLE == STD_ON)
/**
* @brief          Initializes the BCTU hardware as configured.
* @details        Initializes the BCTU hardware as configured.
*
* @param[in]      pCfgPtr      Pointer to the configuration structure.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_InitBctu
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
)
{
    /* Initialize the CTUV2 hardware units*/
    /** @violates @ref Adc_Adcdig_c_REF_5 Cast from pointer to pointer. */
    Adc_Bctu_Init((const Adc_Bctu_ConfigType *)pCfgPtr->pCtuCfgPtr); /* Initialize the BCTU hardware units*/
}
#elif (ADC_CTUV2_AVAILABLE == STD_ON)
/**
* @brief          Initializes the CTU2 hardware as configured.
* @details        Initializes the CTU2 hardware as configured.
*
* @param[in]      pCfgPtr      Pointer to the configuration structure.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_InitCtu2
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
)
{
    /* Initialize the CTUV2 hardware units*/
    /** @violates @ref Adc_Adcdig_c_REF_5 Cast from pointer to pointer. */
    Adc_Ctu2_Init((const Adc_Ctu2_ConfigType *)pCfgPtr->pCtuCfgPtr); /* Initialize the CTUV2 hardware units*/
    Adc_Ctu2_SetupDma(); /* Also setup the DMA Transfer Descriptors */
}
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

/**
* @brief          Write Power down bit.
* @details        Initializes the Ncmr mask for group.
*
* @param[in]      Unit            The hardware Unit. (on other platforms there are more hw units)
* @param[in]      bSetPowerDown   Flag to set or clear power down 
*
* @return         Std_ReturnType
*
*/
static FUNC(Std_ReturnType, ADC_CODE)  Adc_Adcdig_WritePowerDownBit
(
 VAR(Adc_HwUnitType,AUTOMATIC)Unit, 
 VAR(boolean, AUTOMATIC) bSetPowerDown
)
{
    VAR(uint32, AUTOMATIC)  u32MsrStatus;
    VAR(volatile uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
    VAR(uint32, AUTOMATIC)  u32ExpectedMsrStatus = ADCDIG_IDLE_OFFSET_STATUS_U32;
        
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_31();
    if((boolean)FALSE == bSetPowerDown)
    {
        /* comes out from PowerDown */
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_POWER_DOWN_U32);
        u32ExpectedMsrStatus = ADCDIG_IDLE_OFFSET_STATUS_U32;
    }
    else
    {
        /* enter into power-down mode */
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_POWER_DOWN_U32);
        u32ExpectedMsrStatus = ADCDIG_POWERDOWN_STATUS_U32;
    }
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_31();

    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
    while(u32MsrStatus != u32ExpectedMsrStatus)
    {
        if (u32Timeout > 0UL)
        {
            u32Timeout--;
        }
        else
        {
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
            {
                /* Report production error and return from function. */
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
            return (Std_ReturnType)E_NOT_OK;
        }
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
    }
    
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
    {
        /* Report production error passed.  */
        Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
    }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
    
    return(Std_ReturnType)E_OK;
}

/**
* @brief          This function initializes the ADC hardware module, and the ADC driver.
* @details        This function initializes the ADC hardware module, and the ADC driver.
*
* @param[in]      pCfgPtr      Configuration data pointer.
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adcdig_Init
(
    P2CONST(Adc_ConfigType, AUTOMATIC, ADC_APPL_CONST) pCfgPtr
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
    VAR(Std_ReturnType, AUTOMATIC) DemTest = (Std_ReturnType)E_OK;
    P2CONST(Adc_Adcdig_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr = pCfgPtr->pAdc;

    /* Enter critical region to avoid ISRs during register reset */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_03();
#if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    Adc_Adcdig_InitNcmrMask(pCfgPtr);
#endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */

    /* Initialize Unit Status structures */
    for(Unit = 0U; Unit < (Adc_HwUnitType)ADC_MAX_HW_UNITS; Unit++)
    {
        if((uint8)STD_ON == ADC_HW_UNITS(Unit))
        {
            DemTest = Adc_Adcdig_InitUnitHardware(Unit, pConfigPtr);
        }
    }

#ifdef ADC_WDG_SUPPORTED
    Adc_Adcdig_InitUnitLimitChecking(pCfgPtr);
#endif /* ADC_WDG_SUPPORTED */

 /* If there are MHT then setup the relation between the physical channels and groups  */
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
    Adc_Adcdig_InitUnitMht(pCfgPtr);
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
  #if (ADC_BCTU_AVAILABLE == STD_ON)
    Adc_Adcdig_InitBctu(pCfgPtr);
  #elif (ADC_CTUV2_AVAILABLE == STD_ON)
    Adc_Adcdig_InitCtu2(pCfgPtr);
  #endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_03();
    
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Dem error was checked and not failed, so it must be reported passed */
    if (((Std_ReturnType)E_OK == DemTest) && ((uint32)STD_ON == Adc_E_TimeoutCfg.state))
    {
        /* Report production error passed.  */
        Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
    }
#else
    (void)DemTest;
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
}

#if (ADC_DEINIT_API == STD_ON)
/**
* @brief          This function de-initializes the ADC hardware.
*
* @param[in]      Unit      The hardware Unit.
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_DeInitHardware
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
#ifdef ADC_WDG_SUPPORTED
    VAR(uint8,AUTOMATIC) u8WdgIndex = 0U;
#endif

    /* Enter ADC Unit to power down mode */
    (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_MCR_RESET_VALUE_U32);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_CLEAR_VALUE_U32);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_IMR_RESET_VALUE_U32);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_WTISR_REG_ADDR32(Unit), ADCDIG_WTISR_RESET_VALUE_U32);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_WTIMR_REG_ADDR32(Unit), ADCDIG_WTIMR_RESET_VALUE_U32);

#ifdef ADC_DMA_SUPPORTED
    if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        /* Disable DMA interrupt */
        Mcl_DmaDisableHwRequest((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
        #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
        Mcl_DmaDisableNotification((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
        #endif /* MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON */
    }
#endif /* ifdef ADC_DMA_SUPPORTED */
    
    Adc_Adcdig_ClearDmarRegisters(Unit);

#ifdef ADC_WDG_SUPPORTED
    for (u8WdgIndex = 0U; u8WdgIndex < (uint8)ADC_THRHLR_REGS; u8WdgIndex++)
    {
        if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_ThrhlrPresent[Unit][u8WdgIndex])
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_THRHLRx_REG_ADDR32(Unit, u8WdgIndex), ADCDIG_THRHLRx_RESET_VALUE_U32(Unit));
        }
    }
#endif /* ADC_WDG_SUPPORTED */

    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CeocfrPresent[Unit][ADC_CEOCFR0_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_CEOCFR0_REG_ADDR32(Unit),0xFFFFFFFFUL);
    }
#if (ADC_CEOCFR1_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CeocfrPresent[Unit][ADC_CEOCFR1_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_CEOCFR1_REG_ADDR32(Unit),0xFFFFFFFFUL);
    }
#endif
#if (ADC_CEOCFR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CeocfrPresent[Unit][ADC_CEOCFR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_CEOCFR2_REG_ADDR32(Unit),0xFFFFFFFFUL);
    }
#endif
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_PSCR_REG_ADDR32(Unit), 0x0UL);
    
    Adc_Adcdig_SetPsrRegisters(Unit, 0x0UL, 0x0UL, 0x0UL);
    
    Adc_Adcdig_SetCtrRegisters(Unit, ADCDIG_CTR0_RESET_VALUE_U32, ADCDIG_CTR1_RESET_VALUE_U32, ADCDIG_CTR2_RESET_VALUE_U32);
    
    Adc_Adcdig_SetNcmrRegisters(Unit, ADCDIG_NCMR_RESET_VALUE_U32, ADCDIG_NCMR_RESET_VALUE_U32, ADCDIG_NCMR_RESET_VALUE_U32);
    
    Adc_Adcdig_SetJcmrRegisters(Unit, ADCDIG_JCMR_RESET_VALUE_U32, ADCDIG_JCMR_RESET_VALUE_U32, ADCDIG_JCMR_RESET_VALUE_U32);

#ifdef ADC_WDG_SUPPORTED
    /* Watchdog registers */
    for (u8WdgIndex = 0U; u8WdgIndex < (uint8)ADC_CWENR_REGS; u8WdgIndex++)
    {
        if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CwenrPresent[Unit][u8WdgIndex])
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_CWENRx_REG_ADDR32(Unit, (uint32)u8WdgIndex), ADCDIG_CWENR_RESET_VALUE_U32);
        }
    }

    for (u8WdgIndex = 0U; u8WdgIndex < (uint8)ADC_CWSELR_REGS; u8WdgIndex++)
    {
        if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CwselrPresent[Unit][u8WdgIndex])
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_CWSELRx_REG_ADDR32(Unit, (uint32)u8WdgIndex), ADCDIG_CWSEL_RESET_VALUE_U32);
        }
    }
#endif /* ADC_WDG_SUPPORTED */

#if (ADC_DSDR_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_DsdrPresent[Unit])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_DSDR_REG_ADDR32(Unit), ADCDIG_DSDR_RESET_VALUE_U32);
    }
#endif /* (ADC_DSDR_AVAILABLE == STD_ON) */

    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_PDEDR_REG_ADDR32(Unit), ADCDIG_PDEDR_RESET_VALUE_U32);
#if (STD_ON == ADC_HW_TRIGGER_API)
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    /* Disable Hardware Trigger Selection */
    Adc_Siul2_DisableHwTrigger(Unit);
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
#endif /* (STD_ON == ADC_HW_TRIGGER_API) */
}
#endif /* ADC_DEINIT_API == STD_ON */

#if (ADC_DEINIT_API == STD_ON)
/**
* @brief          This function de-initializes the ADC driver, and the ADC hardware.
* @details        This function de-initializes the ADC driver, and ensures that the ADC hardware
*                 will be in the power on after reset state.
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adcdig_DeInit(void)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U;
#if ((ADC_GRP_NOTIF_CAPABILITY == STD_ON) || (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON))
    VAR(Adc_GroupType,AUTOMATIC) GroupIdx = 0U;
  #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
    VAR(Adc_GroupType, AUTOMATIC) GroupIndex = 0U;
  #endif /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
#endif /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

    /* Enter critical region to avoid ISRs during register reset */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_06();

    for(;Unit<(Adc_HwUnitType)ADC_MAX_HW_UNITS;Unit++)
    {
        /* ADC111-- ADC110*/
        if((uint8)STD_ON == ADC_HW_UNITS(Unit))
        {
            Adc_Adcdig_DeInitHardware(Unit);
        }
    }

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
  #if (ADC_BCTU_AVAILABLE == STD_ON)
    Adc_Bctu_DeInit();
  #elif (ADC_CTUV2_AVAILABLE == STD_ON)
    Adc_Ctu2_DeInit();
  #endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) */

#if ((ADC_GRP_NOTIF_CAPABILITY == STD_ON) || (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON))
    for(GroupIdx = 0U; GroupIdx < (Adc_GroupType)ADC_MAX_GROUPS; GroupIdx++)
    {
    #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
        Adc_aGroupStatus[GroupIdx].eNotification = ADC_NOTIFICATION_DISABLED;
    #endif  /* (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

    #if (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON)
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing */
        GroupIndex = (Adc_GroupType)Adc_pCfgPtr->pGroups[GroupIdx].EnableChDisableChGroupIndex;
        if(ADC_ENABLE_CH_DISABLE_CH_INVALID_GROUP_INDEX != GroupIndex)
        {
            Adc_aNCMRxMask[GroupIndex].Adc_u32NCMR0 = (uint32)ADCDIG_NCMR_RESET_VALUE_U32;
        #if (ADC_NCMR1_AVAILABLE == STD_ON)
            Adc_aNCMRxMask[GroupIndex].Adc_u32NCMR1 = (uint32)ADCDIG_NCMR_RESET_VALUE_U32;
        #endif
        #if (ADC_NCMR2_AVAILABLE == STD_ON)
            Adc_aNCMRxMask[GroupIndex].Adc_u32NCMR2 = (uint32)ADCDIG_NCMR_RESET_VALUE_U32;
        #endif
        }
    #endif  /* (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON) */
    }
#endif /* ((ADC_GRP_NOTIF_CAPABILITY == STD_ON) || (ADC_ENABLE_CH_DISABLE_CH_NONAUTO_API == STD_ON))*/

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_06();
}
#endif /* #if (ADC_DEINIT_API == STD_ON) */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
* @brief          This function stops the current conversion.
* @details        This function stops the current conversion and checks if the hardware has responded to the command.
*
* @param[in]      Unit      The hardware Unit.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            If the conversion has stopped as expected.
* @retval         E_NOT_OK        In case of timeout while waiting for adc hardware to stop a conversion.
*
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_StopConversionCheckTimeout
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(boolean, AUTOMATIC) bStartApi
)
{
    VAR(uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
    VAR(uint32, AUTOMATIC) u32MsrStatus;

    do
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_CONV_MASK_U32 | ADCDIG_ABORT_CHAIN_U32, ADCDIG_ABORT_CHAIN_U32);
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
        if (u32Timeout > 0UL)
        {
            u32Timeout--;        
        }
        else
        {
            if ((boolean)TRUE == bStartApi)
            {
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_07();
            }
            else
            {
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_08();
            }
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
            {
                /* Report production error and return from function. */
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            if ((boolean)TRUE == bStartApi)
            {
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_07();
            }
            else
            {
                SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_08();
            }
            /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
            return (Std_ReturnType) E_NOT_OK;
        }
    }
    while(ADCDIG_NORMAL_CONV_ONGOING_U32 == u32MsrStatus);
    return (Std_ReturnType) E_OK;
}
#endif

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
* @brief          This function stops the current conversion of a group.
* @details        This function stops the current conversion of a group.
*
* @param[in]      Unit      The hardware Unit.
* @param[in]      Group     The group id.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            If the conversion has stopped as expected.
* @retval         E_NOT_OK        In case of timeout while waiting for adc hardware to stop a conversion.
*
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_StopCurrentConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(boolean, AUTOMATIC) bStartApi
)
{
    VAR(Std_ReturnType, AUTOMATIC) Test = (Std_ReturnType)E_OK;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChTemp;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndexTemp;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;

#ifdef ADC_DMA_SUPPORTED
    if (ADC_INTERRUPT == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
#endif /* ADC_DMA_SUPPORTED */
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32);
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
    }
#ifdef ADC_DMA_SUPPORTED
    else /* Is DMA driven: Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware == ADC_DMA */
    {
        Adc_Adcdig_ClearDmarRegisters(Unit);
        if ((uint8)STD_ON == Adc_pCfgPtr->Misc.au8Adc_HwUnit[Unit])
        {
            Mcl_DmaDisableHwRequest((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
            #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
            Mcl_DmaDisableNotification((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
            #endif /* MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON */
        }
    }
#endif /* ADC_DMA_SUPPORTED */
    /*  stop the conversion and abort the current group conversion */
#if (ADC_BYPASS_CONSISTENCY_LOOP == STD_ON)
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if((uint8)STD_ON == Adc_pCfgPtr->pGroups[Group].u8AdcWithoutInterrupt)
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_CONV_MASK_U32 | ADCDIG_ABORT_CHAIN_U32, ADCDIG_ABORT_CHAIN_U32);
    }
    else
    {
        Test = Adc_Adcdig_StopConversionCheckTimeout(Unit, bStartApi);
    }
#else /* (ADC_BYPASS_CONSISTENCY_LOOP == STD_ON) */
        Test = Adc_Adcdig_StopConversionCheckTimeout(Unit, bStartApi);
#endif /* (ADC_BYPASS_CONSISTENCY_LOOP == STD_OFF) */
    /* Clear the ABORT_CHAIN bit if set, otherwise the next chain will be ABORTED without any End of Chain Interrupt */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    if (REG_READ32(ADCDIG_MCR_REG_ADDR32(Unit))&ADCDIG_ABORT_CHAIN_U32)
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer. */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_ABORT_CHAIN_U32);
    }

    if ((Std_ReturnType)E_NOT_OK == Test)
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return Test;
    }
#if (ADC_SETCHANNEL_API == STD_ON)
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
#endif
    /* clear VALID bit from ADC result registers for all channels assigned to the group
        when conversion is aborted */
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    for(ChTemp = 0U; ChTemp < ChannelCount; ChTemp++)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ChIndexTemp = Adc_aRuntimeGroupChannel[Group].pChannel[ChTemp];
#else
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ChIndexTemp = Adc_pCfgPtr->pGroups[Group].pAssignment[ChTemp];
#endif

        /**
        * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer
        * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
        */
        REG_READ32(ADCDIG_CH_DATA_REG_ADDR32(Unit, (uint32)Adc_pCfgPtr->pChannels[Unit][ChIndexTemp].ChId));
    }
  
    return Test;
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#ifdef ADC_WDG_SUPPORTED
/**
* @brief          This function configures the CWENRx registers.
* @details        This function configures the CWENRx registers.
*
* @param[in]      pGroupPtr   Pointer to group of which conversion will be started.
* @param[in]      Unit        The hardware Unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_ConfigureCwenrRegiters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr
)
{
    /* Enable the Watchdog only on configured channels */
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CwenrPresent[Unit][ADC_CWENR0_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_CWENR0_REG_ADDR32(Unit), pGroupPtr->u32Wer0);
    }
#if (ADC_CWENR1_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CwenrPresent[Unit][ADC_CWENR1_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_CWENR1_REG_ADDR32(Unit), pGroupPtr->u32Wer1);
    }
#endif /* (ADC_CWENR1_AVAILABLE == STD_ON) */
#if (ADC_CWENR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_CwenrPresent[Unit][ADC_CWENR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_CWENR2_REG_ADDR32(Unit), pGroupPtr->u32Wer2);
    }
#endif /* (ADC_CWENR2_AVAILABLE == STD_ON) */
}
#endif /* ADC_WDG_SUPPORTED */

#if (ADC_READ_GROUP_API == STD_ON)
/**
* @brief          This function reads the converted data for the requested group.
* @details        Reads the converted data for the requested group.
*
* @param[in]      Group           The group number.
* @param[in]      pDataPtr        Pointer to a buffer which will be filled by the
*                                 conversion results.
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful read of the converted data.
* @retval         E_NOT_OK        In case of an ongoing conversion.
*
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_ReadGroup
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pDataPtr,
    P2VAR(boolean, AUTOMATIC, ADC_APPL_DATA) pFlag
)
{
    VAR(Std_ReturnType, AUTOMATIC) ReadGroupRet = (Std_ReturnType)E_OK;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;
    /* Pointer to AdcGroup */
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = NULL_PTR;
   
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
#if (ADC_SETCHANNEL_API == STD_ON)
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = pGroupPtr->AssignedChannelCount;
#endif  

    /* If the group is configured for without interrupts*/
    if((uint8)STD_ON == pGroupPtr->u8AdcWithoutInterrupt)
    {
        VAR(uint32, AUTOMATIC) u32CdrValue;
        VAR(uint32, AUTOMATIC) u32CdrMask = ADCDIG_CDR_DATA_MASK_U32;
        VAR(Adc_ChannelIndexType, AUTOMATIC) Channel;
        VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
        VAR(Adc_ChannelType, AUTOMATIC) LastCh;
#if (ADC_SETCHANNEL_API == STD_ON) 
        VAR(Adc_ChannelType, AUTOMATIC) CrtChannel;
#endif
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        VAR(Adc_HwUnitType, AUTOMATIC) Unit = pGroupPtr->HwUnit;
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
        P2CONST(Adc_Adcdig_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr = Adc_pCfgPtr->pAdc;
        VAR(Adc_ChannelType, AUTOMATIC) Shift = 0U;
#endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */
#if ((ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) || (ADC_ENABLE_LIMIT_CHECK == STD_ON))
        VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
#endif /* ((ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) || (ADC_ENABLE_LIMIT_CHECK == STD_ON)) */
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /* Flag to set if ADC results are in the selected range */
        VAR(boolean, AUTOMATIC) bWriteFlag = (boolean)TRUE;
        VAR(uint16, AUTOMATIC) u16CdrValueTemp = 0U;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
   
#if (ADC_SETCHANNEL_API == STD_ON)
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        LastCh = Adc_pCfgPtr->pChannels[Unit][Adc_aRuntimeGroupChannel[Group].pChannel[0]].ChId;   
        for(ChIndex = 0U; ChIndex < ChannelCount; ChIndex++)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
            CrtChannel = Adc_pCfgPtr->pChannels[Unit][Adc_aRuntimeGroupChannel[Group].pChannel[ChIndex]].ChId;
            if(CrtChannel > LastCh)
            {
                /* Calculate the last channel to configure DMA when SetChannel function is invoked */
                LastCh = CrtChannel;
            }
        }
#else
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        LastCh = (Adc_ChannelType)pGroupPtr->LastCh;
#endif
        /* Enter critical region */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32CdrValue = REG_READ32(ADCDIG_CH_DATA_REG_ADDR32(Unit, (uint32)LastCh));
        if(0UL == (u32CdrValue & ADCDIG_VALID_DATA_MASK_U32))
        {
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
            /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
            return (Std_ReturnType)E_NOT_OK;
        }
#if ((ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) || (ADC_ENABLE_LIMIT_CHECK == STD_ON))
        /* Get the index of hardware Unit*/
        HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
#endif /* ((ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) || (ADC_ENABLE_LIMIT_CHECK == STD_ON)) */
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Shift = (16U - (pConfigPtr[HwIndex].Res));
        u32CdrMask = (uint32)(ADCDIG_CDR_DATA_MASK_U32 << Shift);
#endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */

        /* Copy result direct from ADC result registers to output data array */
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        for(Channel = 0U; Channel < ChannelCount; Channel++)
        {
            /* there is only one channel in the group - the first channel */
#if (ADC_SETCHANNEL_API == STD_ON)
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            ChIndex = Adc_aRuntimeGroupChannel[Group].pChannel[Channel];
#else
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            ChIndex = pGroupPtr->pAssignment[Channel];
#endif
            /**
            * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer
            * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
            */
            u32CdrValue = REG_READ32(ADCDIG_CH_DATA_REG_ADDR32(Unit, (uint32)Adc_pCfgPtr->pChannels[Unit][ChIndex].ChId));
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)    
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if ((boolean)TRUE == Adc_ChannelsLimitCheckingCfg[HwIndex][ChIndex].bChannelLimitCheck)
            {
    #if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
                u16CdrValueTemp = (uint16)((u32CdrValue & ADCDIG_SHIFT_MASK_U32) >> Shift);
    #else
                u16CdrValueTemp = (uint16)(u32CdrValue & u32CdrMask);
    #endif /* (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT) */
                (*pFlag) = (boolean)Adc_CheckConversionValuesInRange(u16CdrValueTemp, Unit, ChIndex);
                if ((boolean)FALSE == (*pFlag))
                {
                    /* ADC448, ADC449, ADC450 */
                    ReadGroupRet = (Std_ReturnType)E_NOT_OK;
                    bWriteFlag = (boolean)FALSE;
                }
            }
            if((boolean)TRUE == bWriteFlag)
#else
            (*pFlag) = (boolean)TRUE;
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */
            {
                /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                *(pDataPtr + (Channel)) = (uint16)(u32CdrValue & u32CdrMask);
            }
        }
    }
    else  /* If the group is configured with interrupts*/
    {
        VAR(Adc_ChannelIndexType, AUTOMATIC) u8Count = 0U;
        P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pResultPtr = NULL_PTR;
        VAR(uint32, AUTOMATIC) u32DestOffset = 0UL;
        VAR(Adc_StreamNumSampleType, AUTOMATIC) ResultIndex = 0U;

        /* Enter critical region */
        SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_09();
        if (ADC_BUSY == Adc_aGroupStatus[Group].eConversion)
        {
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();
            /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
            return (Std_ReturnType)E_NOT_OK;
        }
        /* Get index of last completed sample */
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ResultIndex = Adc_aGroupStatus[Group].ResultIndex - (Adc_StreamNumSampleType)1;
        if ((Adc_StreamNumSampleType)0 == Adc_aGroupStatus[Group].ResultIndex)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            ResultIndex = pGroupPtr->NumSamples - (Adc_StreamNumSampleType)1;
        }

        /**
        * @violates @ref Adc_Adcdig_c_REF_5 Cast from pointer to pointer.
        * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        */
        pResultPtr=(Adc_ValueGroupType *)(pGroupPtr->pResultsBufferPtr[Group]+ResultIndex);
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        u32DestOffset = pGroupPtr->NumSamples;

        /* Copy results of last conversion from streaming buffer to internal buffer */
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        for(u8Count = 0U; u8Count < ChannelCount; u8Count++)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pDataPtr[u8Count] = (*pResultPtr);
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            pResultPtr += u32DestOffset;
        }
    }
    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_09();

    return(ReadGroupRet);
}
#endif /* (ADC_READ_GROUP_API == STD_ON) */

#if ((defined(ADC_WDG_SUPPORTED)) || (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF))
/**
* @brief          This function performs general configurations to the adc hardware prior to starting a conversion.
* @details        This function performs general configurations to the adc hardware prior to starting a conversion.
*
* @param[in]      Group       The group of which conversion will be started.
* @param[in]      Unit        The hardware Unit.
* @param[in]      pGroupPtr    The pointer to the group configuration structure.
*
* @return         void
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_PrepareGroupStart
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr
)
{
#if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF)
    VAR(uint32, AUTOMATIC) u32Extended = 0UL;
    VAR(uint32, AUTOMATIC) u32External = 0UL;
#endif /* #if ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF */

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime = 0U;
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime1 = 0U;
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime2 = 0U;
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF */

#ifdef ADC_WDG_SUPPORTED
    Adc_Adcdig_ConfigureCwenrRegiters(Unit, pGroupPtr);
#endif /* ADC_WDG_SUPPORTED */

#if (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF)
#if (ADC_PSR1_AVAILABLE == STD_ON)
    u32Extended = pGroupPtr->u32ExtendedPsr;
#endif
#if (ADC_PSR2_AVAILABLE == STD_ON)
    u32External = pGroupPtr->u32ExternalPsr;
#endif
    /* presampling related configurations/initializations */
    Adc_Adcdig_SetPsrRegisters(Unit, pGroupPtr->u32PrecisionPsr, u32Extended, u32External);
#endif /* #if ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF */

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    #if (ADC_DUAL_CLOCK_MODE == STD_ON)
        ConvTime = (ADC_NORMAL == Adc_ClockMode)?pGroupPtr->ConvTime:pGroupPtr->AltConvTime;
        #if (ADC_CTR1_AVAILABLE == STD_ON)
            ConvTime1 = (ADC_NORMAL == Adc_ClockMode)?pGroupPtr->ConvTime1:pGroupPtr->AltConvTime1;
        #endif
        #if (ADC_CTR2_AVAILABLE == STD_ON)
            ConvTime2 = (ADC_NORMAL == Adc_ClockMode)?pGroupPtr->ConvTime2:pGroupPtr->AltConvTime2;
        #endif
    #else
        ConvTime = pGroupPtr->ConvTime;
        #if (ADC_CTR1_AVAILABLE == STD_ON)
            ConvTime1 = pGroupPtr->ConvTime1;
        #endif
        #if (ADC_CTR2_AVAILABLE == STD_ON)
            ConvTime2 = pGroupPtr->ConvTime2;
        #endif
    #endif
    /*  Program Conversion Time*/
    Adc_Adcdig_SetCtrRegisters(Unit, ConvTime, ConvTime1, ConvTime2);
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF */
}
#endif /* ((defined(ADC_WDG_SUPPORTED)) || (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)) */

#if (ADC_HW_TRIGGER_API == STD_ON)
/**
* @brief          This function enables the hardware triggers for the specified group.
* @details        This function enables the hardware triggers for the specified group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      Unit            The hardware Unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adcdig_EnableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */
    VAR(uint32, AUTOMATIC)  u32Mcr_ClearVal = 0UL;
    VAR(uint32, AUTOMATIC)  u32Mcr_SetVal = 0UL;
    VAR(uint32, AUTOMATIC)  u32ImrSetVal = 0UL;
    VAR(uint32, AUTOMATIC)  u32Isr_SetVal = 0UL;
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    VAR(Adc_HwTriggerTimerType, AUTOMATIC)  ValOfMscr = 0U;
#endif
    VAR(Adc_NCMRType, AUTOMATIC) CMRMask;
    
    /* Enter critical section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_10();
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
#if ((defined(ADC_WDG_SUPPORTED)) || (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF))
    Adc_Adcdig_PrepareGroupStart(Unit, pGroupPtr);
#endif /* ((defined(ADC_WDG_SUPPORTED)) || (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)) */
   
    /** @violates @ref Adc_Adcdig_c_REF_12 It is needed for calculation value of go back space for source address.*/
    Adc_GetCMR_Register(Unit, Group, &CMRMask);
#if ((ADC_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_BCTU_AVAILABLE == STD_ON) || (ADC_CTUV2_AVAILABLE == STD_ON)))
    /* If the triggers are come from CTU */
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if (pGroupPtr->pHwResource[0] < (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
    {
        /* Switch to CTU trigger mode, ADC must be switched to power down mode to modify this bit */
        /* Enter power down bit */
        (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE);
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CTU_ENABLED_U32 | ADCDIG_CTU_TRIGGER_MODE_U32);
        /* Exit power down bit */
        (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)FALSE);

#ifdef ADC_DMA_SUPPORTED
        if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
        {
            /* If the group is configured for with interrupts*/
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing */
            if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
            {
                /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
                /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_SET32(ADCDIG_DMAE_REG_ADDR32(Unit), ADCDIG_DMA_GLOBAL_EN_U32);
                Adc_Adcdig_StartDmaOperation(Unit, Group);
            }
        }
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_BCTU_AVAILABLE == STD_ON)
        /* Configure for BCTU trigger */
        Adc_Adcdig_abAlreadyCleared[Group] = (boolean)FALSE;
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Adc_Bctu_EnableCtuTrigger(Group, pGroupPtr->pHwResource[0], (boolean)TRUE, (boolean)TRUE);
#elif (ADC_CTUV2_AVAILABLE == STD_ON)
        /* DODO: Implementation for CTU2 */
#endif /* ADC_BCTU_AVAILABLE == STD_ON */
        /* Exit critical section */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10();
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return;
    }
#endif /* ((ADC_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_BCTU_AVAILABLE == STD_ON) || (ADC_CTUV2_AVAILABLE == STD_ON))) */
#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    /* Normal conversion */
    if ((Adc_GroupConvType)ADC_CONV_TYPE_NORMAL == pGroupPtr->eType)
    {
        /* Program the Injected Conversion Mask register */
        Adc_Adcdig_SetNcmrRegisters(Unit, CMRMask.Adc_u32NCMR0, CMRMask.Adc_u32NCMR1, CMRMask.Adc_u32NCMR2);
        /* Clear Interrupt status flag */
        u32Isr_SetVal |= ADCDIG_ISR_END_CHAIN_NORM_CONV_U32;
        u32ImrSetVal |= ADCDIG_ISR_END_CHAIN_NORM_CONV_EN_U32;

        /* If internal trigger sources coming from ETPU and EMIOS */
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        if(Adc_GroupTriggerSource(Group, 0U) >= (Adc_HwTriggerTimerType)ADC_MIN_INTERNAL_TRIGGERS)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
            ValOfMscr = Adc_GroupTriggerSource(Group, 0U) - (Adc_HwTriggerTimerType)ADC_MIN_INTERNAL_TRIGGERS;
            /* Enable Hardware Trigger Selection */
            Adc_Siul2_EnableHwTrigger(Unit, ValOfMscr);
        }

        /* Select the Edge */
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (ADC_HW_TRIG_RISING_EDGE == pGroupPtr->eTriggerEdge)
        {
            u32Mcr_SetVal |= ADCDIG_NORMAL_TRIGGER_EDGE_U32;
        }
        else
        {
            /* Nothing for misra */
        }
        u32Mcr_SetVal |= ADCDIG_NORMAL_EXT_TRIGGER_EN_U32;
    }
    else
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
    {
        /* Program the Injected Conversion Mask register */
        Adc_Adcdig_SetJcmrRegisters(Unit, CMRMask.Adc_u32NCMR0, CMRMask.Adc_u32NCMR1, CMRMask.Adc_u32NCMR2);
        /* Clear Interrupt status flag and CTU interrupt flag */
        u32Isr_SetVal |= ADCDIG_ISR_END_CHAIN_INJ_CONV_U32 | ADCDIG_ISR_END_CHANNEL_CTU_CONV_CLEAN_U32;

        u32ImrSetVal |= ADCDIG_ISR_END_CHAIN_INJ_CONV_EN_U32;

        /* Select the Edge */
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if (ADC_HW_TRIG_RISING_EDGE == pGroupPtr->eTriggerEdge)
        {
            u32Mcr_SetVal |= ADCDIG_INJ_TRIGGER_EDGE_U32;
        }
        else
        {
            /* Nothing for misra */
        }
        u32Mcr_SetVal |= ADCDIG_INJ_EXT_TRIGGER_EN_U32;
    } /* End injected conversion */

#ifdef ADC_DMA_SUPPORTED
    if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        /* If the group is configured for with interrupts*/
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing */
        if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_DMAE_REG_ADDR32(Unit), ADCDIG_DMA_GLOBAL_EN_U32 | ADCDIG_DMA_CLEAR_ON_READ_U32);
            Adc_Adcdig_StartDmaOperation(Unit, Group);
        }
    }
    else
#endif /* ADC_DMA_SUPPORTED */
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
        {
            /* Enable Interrupt*/
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_SET32(ADCDIG_IMR_REG_ADDR32(Unit), u32ImrSetVal);
        }
        else
        {
            /* Disable Interrupt*/
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), u32ImrSetVal);
        }
    }

    /* Clear Interrupt status flag */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), u32Isr_SetVal);

    u32Mcr_ClearVal = ADCDIG_NORMAL_EXT_TRIGGER_EN_U32 | ADCDIG_INJ_EXT_TRIGGER_EN_U32 |
                      ADCDIG_NORMAL_TRIGGER_EDGE_U32 | ADCDIG_INJ_TRIGGER_EDGE_U32;
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), u32Mcr_ClearVal, u32Mcr_SetVal);

    /* Exit critical section */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_10();
}
/**
* @brief          This function disables the hardware triggers for the specified group.
* @details        This function disables the hardware triggers for the specified group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      Unit            The hardware Unit. (on other platforms there are more hw units)
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adcdig_DisableHardwareTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint32, AUTOMATIC) u32ImrValue = 0UL;
    VAR(uint32, AUTOMATIC) u32IsrValue = 0UL;
    VAR(uint32, AUTOMATIC) u32McrValue = 0UL;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */

    /* Enter critical region */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_11();

    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);

#if ((ADC_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_BCTU_AVAILABLE == STD_ON) || (ADC_CTUV2_AVAILABLE == STD_ON)))
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(pGroupPtr->pHwResource[0] < (Adc_HwTriggerTimerType)ADC_MAX_CTU_EVTCFGREGS)
    {
#if (ADC_BCTU_AVAILABLE == STD_ON)
        if((boolean)FALSE == Adc_Adcdig_abAlreadyCleared[Group])
        {
            Adc_Adcdig_abAlreadyCleared[Group] = (boolean)TRUE;
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Adc_Bctu_DisableCtuTrigger(pGroupPtr, pGroupPtr->pHwResource[0], (boolean)TRUE);
        }
#elif (ADC_CTUV2_AVAILABLE == STD_ON)
        /* TODO: Implementation for CTU2 */
#endif /* ADC_BCTU_AVAILABLE == STD_ON */
        /* Clear interrupt flags Interrupt Status */
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_CTU_CONV_CLEAN_U32 | \
                                                   ADCDIG_ISR_END_CHANNEL_INJ_CONV_CLEAN_U32 \
                     );
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
        /* If last group in the queue */
        if ((Adc_QueueIndexType)0 == Adc_aUnitStatus[Unit].HwInjectedQueueIndex)
        {
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
#ifdef ADC_DMA_SUPPORTED
            if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
            {
                Adc_Adcdig_ClearDmarRegisters(Unit);
                if ((uint8)STD_ON == Adc_pCfgPtr->Misc.au8Adc_HwUnit[Unit])
                {
                    /* Disable DMA interrupt */
                    Mcl_DmaDisableHwRequest((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
                    #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
                    Mcl_DmaDisableNotification((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
                    #endif /* MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON */
                }
            }
#endif /* ADC_DMA_SUPPORTED */
            /* Disable CTU trigger */
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CTU_ENABLED_U32);
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
            /* reset the queue group status to regular ones... */
            Adc_aUnitStatus[Unit].HwQueueGroupType = (Adc_MhtGroupType)ADC_REGULAR_GROUP_TYPE;
        }
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
        /* Exit critical region */
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11();
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return;
    }
#endif /* ((ADC_CTU_TRIGGER_MODE_SUPPORTED == STD_ON) && ((ADC_BCTU_AVAILABLE == STD_ON) || (ADC_CTUV2_AVAILABLE == STD_ON))) */

#ifdef ADC_DMA_SUPPORTED
    if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        Adc_Adcdig_ClearDmarRegisters(Unit);
        if ((uint8)STD_ON == Adc_pCfgPtr->Misc.au8Adc_HwUnit[Unit])
        {
            /* Disable DMA interrupt */
            Mcl_DmaDisableHwRequest((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
            #if (MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON)
            Mcl_DmaDisableNotification((Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit]);
            #endif /* MCL_DMA_NOTIFICATION_SUPPORTED == STD_ON */
        }
    }
#endif /* ADC_DMA_SUPPORTED */

#if (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON)
    if ((Adc_GroupConvType)ADC_CONV_TYPE_NORMAL == pGroupPtr->eType)
    {
        u32McrValue = ADCDIG_NORMAL_EXT_TRIGGER_EN_U32;
        u32ImrValue = ADCDIG_ISR_END_CHAIN_NORM_CONV_MASK_U32;
        u32IsrValue = (ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32 | ADCDIG_ISR_END_CHANNEL_NORM_CONV_CLEAN_U32);
        /* If internal trigger sources coming from ETPU and EMIOS */
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if(Adc_GroupTriggerSource(Group, 0U) >= (Adc_HwTriggerTimerType)ADC_MIN_INTERNAL_TRIGGERS)
        {
            /* Enable Hardware Trigger Selection */
            Adc_Siul2_DisableHwTrigger(Unit);
        }
    }
    else
#endif /* (ADC_HARDWARE_NORMAL_CONVERSIONS_USED == STD_ON) */
    {
        u32McrValue = ADCDIG_INJ_EXT_TRIGGER_EN_U32;
        u32ImrValue = ADCDIG_ISR_END_CHAIN_INJ_CONV_MASK_U32;
        u32IsrValue = (ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32 | ADCDIG_ISR_END_CHANNEL_INJ_CONV_CLEAN_U32);
    }

    /* Disable hardware trigger */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), u32McrValue);
    /* Disable Interrupt */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), u32ImrValue);
    /* Clear interrupt flags Interrupt Status */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_ISR_REG_ADDR32(Unit), u32IsrValue);
    (void)pGroupPtr;

    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_11();
}

#if (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON)
LOCAL_INLINE FUNC(Adc_HwTriggerTimerType, ADC_CODE) Adc_Adcdig_GetIndexOfCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Index = 0U;

    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    for(Index = 0U; Index < Adc_pCfgPtr->pGroups[Group].AssignedTriggerCount; Index++)
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if(TriggerSource == Adc_pCfgPtr->pGroups[Group].pHwResource[Index])
        {
            break;
        }
    }
    return Index;
}

/**
* @brief          This function enables the hardware trigger for the specified group.
* @details        Non autosar API to enable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adcdig_EnableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
    /* Pointer to AdcGroup */
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
    VAR(uint32, AUTOMATIC) u32Mcr_ClearVal = 0UL;
    VAR(uint32, AUTOMATIC) u32Mcr_SetVal = ADCDIG_INJ_EXT_TRIGGER_EN_U32;
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime1 = 0U;
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime2 = 0U;
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF */
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Index = 0U;
    VAR(boolean, AUTOMATIC) bFirstTrigger = (boolean)TRUE;
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = pGroupPtr->HwUnit;

    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    for(Index = 0U; Index < pGroupPtr->AssignedTriggerCount; Index++)
    {
        if(0U != Adc_au8BctuGroupTriggersActive [Unit][Index])
        {
            bFirstTrigger = (boolean)FALSE;
            break;
        }
    }

    Index = Adc_Adcdig_GetIndexOfCtuTrigger(Group, TriggerSource);
    Adc_au8BctuGroupTriggersActive [Unit][Index] = 1U;

    if ((boolean)FALSE == bFirstTrigger)
    {
        #if (ADC_BCTU_AVAILABLE == STD_ON)
            Adc_Bctu_EnableCtuTrigger(Group, TriggerSource, (boolean)FALSE, bFirstTrigger);
        #endif /* ADC_BCTU_AVAILABLE == STD_ON */
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return;
    }
    /* Enter critical section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_21();

    Adc_aUnitStatus[Unit].HwInjectedQueue[Adc_aUnitStatus[Unit].HwInjectedQueueIndex] = Group;
    Adc_aUnitStatus[Unit].HwInjectedQueueIndex++;

    /* ADC222*/
    /* Mark the Group as BUSY when the Group goes to the Queue or gets started */
    Adc_aGroupStatus[Group].eConversion = ADC_BUSY;

    /* if HW trigger is enabled for a group, its CTU trigger status becomes ENABLED */
    Adc_aGroupStatus[Group].eCtuTriggering = ADC_HWTRIGGER_ENABLED;

    /* ADC432 */
    /* Put the conversion results from Results Buffer Base Address */
    Adc_aGroupStatus[Group].ResultIndex = 0U;

#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)
    #if (ADC_CTR1_AVAILABLE == STD_ON)
    ConvTime1 = pGroupPtr->ConvTime1;
    #endif
    #if (ADC_CTR2_AVAILABLE == STD_ON)
    ConvTime2 = pGroupPtr->ConvTime2;
    #endif
    /*  Program Conversion Time*/
    Adc_Adcdig_SetCtrRegisters(Unit, pGroupPtr->ConvTime, ConvTime1, ConvTime2);
#endif /* ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF */
    /* Enter power down */
    (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE);
    /* Enable CTU trigger, put ADC to CTU trigger mode */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CTU_ENABLED_U32 | ADCDIG_CTU_TRIGGER_MODE_U32);
    /* Exit power down */
    (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)FALSE);

    /* Disable Interrupt Mask*/
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_MASK_U32 | \
                                              ADCDIG_ISR_END_CHANNEL_CTU_CONV_U32 \
                   );
    /* Select the Edge*/
    if(ADC_HW_TRIG_RISING_EDGE == pGroupPtr->eTriggerEdge)
    {
        u32Mcr_SetVal |= ADCDIG_INJ_TRIGGER_EDGE_U32;
    }
    else
    {
        u32Mcr_ClearVal = ADCDIG_INJ_TRIGGER_EDGE_U32;
    }

    /* Configure trigger edge for the group */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), u32Mcr_SetVal);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), u32Mcr_ClearVal);

#if (ADC_BCTU_AVAILABLE == STD_ON)
    Adc_Bctu_EnableCtuTrigger(Group, TriggerSource, (boolean)FALSE, bFirstTrigger);
#endif /* ADC_BCTU_AVAILABLE == STD_ON */

    /* Exit critical section */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_21();

}

/**
* @brief          This function disables the hardware trigger for the specified group.
* @details        Non autosar API to disable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be disabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adcdig_DisableCtuTrigger
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource
)
{
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) Index = 0U;
    VAR(boolean, AUTOMATIC) bLastTrigger = (boolean)TRUE;
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[Group].HwUnit;

    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    for(Index = 0U; Index < Adc_pCfgPtr->pGroups[Group].AssignedTriggerCount; Index++)
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        if ((0U != Adc_au8BctuGroupTriggersActive [Unit][Index]) && \
            (TriggerSource != Adc_pCfgPtr->pGroups[Group].pHwResource[Index])
           )
        {
            bLastTrigger = (boolean)FALSE;
            break;
        }
    }
    Index = Adc_Adcdig_GetIndexOfCtuTrigger(Group, TriggerSource);
    Adc_au8BctuGroupTriggersActive [Unit][Index] = 0U;

#if (ADC_BCTU_AVAILABLE == STD_ON)
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Adc_Bctu_DisableCtuTrigger(&(Adc_pCfgPtr->pGroups[Group]), TriggerSource, bLastTrigger);
#endif /* ADC_BCTU_AVAILABLE == STD_ON */

    if ((boolean)FALSE == bLastTrigger)
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return;
    }

     /* Enter critical region */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_22();

    Adc_aGroupStatus[Group].eCtuTriggering = ADC_HWTRIGGER_DISABLED;

    if(Adc_aUnitStatus[Unit].HwInjectedQueueIndex > 0U)
    {
        /* ADC429 */
        Adc_aUnitStatus[Unit].HwInjectedQueueIndex--;
    }

    /*Mark the group as IDLE */
    Adc_aGroupStatus[Group].eConversion = ADC_IDLE;

    /* Enter power down  */
    (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE);
    /* Disable CTU trigger, disable CTU trigger mode */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CTU_ENABLED_U32 | ADCDIG_CTU_TRIGGER_MODE_U32);
    /* Exit power down */
    (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)FALSE);

    /* Clear interrupt mask register*/
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHANNEL_CTU_CONV_CLEAN_U32);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_INJ_EXT_TRIGGER_EN_U32);

    /* Clear Interrupt status flag and CTU interrupt flag */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_U32 | \
                                          ADCDIG_ISR_END_CHANNEL_INJ_CONV_CLEAN_U32 | \
                                          ADCDIG_ISR_END_CHANNEL_CTU_CONV_CLEAN_U32 \
               );
    /* Exit critical region */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_22();
}

/**
* @brief          This function reads the data from the ADC channel hardware data register.
* @details        This non Autosar API is used to copy the data from the ADC channel
*                 hardware data register to the ADC group result buffer.
*
* @param[in]      Group           The group for which the data will be read.
* @param[in]      pDataPtr        Pointer to a buffer which will be filled by the
*                                 conversion results.
*

* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful read of the converted data.
* @retval         E_NOT_OK        In case of an ongoing conversion.
*
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_HwResultReadGroup
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2VAR(Adc_ValueGroupType, AUTOMATIC, ADC_APPL_DATA) pDataPtr
)
{
    VAR(Adc_ChannelIndexType, AUTOMATIC) Ch;
    VAR(Adc_ChannelType, AUTOMATIC) PreviousCh;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
    VAR(Adc_ChannelType, AUTOMATIC) PreviousChIndex;
    VAR(boolean, AUTOMATIC) bFlagStatus = (boolean)FALSE;
    VAR(Std_ReturnType, AUTOMATIC) Adc_ReadGroupRet = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32CdrValue = 0UL;
    VAR(uint32, AUTOMATIC) u32CdrMask = ADCDIG_CDR_DATA_MASK_U32;
#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
    VAR(Adc_ChannelType, AUTOMATIC) Shift = 0U;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
#endif /* ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT */
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[Group].HwUnit;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;

#if (ADC_RESULT_ALIGNMENT == ADC_ALIGN_LEFT)
    /* Get the index of hardware Unit*/
    HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Shift = (16U - Adc_pCfgPtr->pAdc[HwIndex].Res);
    u32CdrMask = (uint32)(ADCDIG_CDR_DATA_MASK_U32 << Shift);
#endif

    /* Global Interrupt disable to protect code section */
    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_23();
    
#if (ADC_SETCHANNEL_API == STD_ON)
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
#endif
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    for (Ch = 0U; Ch < ChannelCount; Ch++)
    {
#if (ADC_SETCHANNEL_API == STD_ON)
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ChIndex = Adc_aRuntimeGroupChannel[Group].pChannel[Ch];
#else
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        ChIndex = Adc_pCfgPtr->pGroups[Group].pAssignment[Ch];
#endif
        /**
        * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
        * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer.
        * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. 
        */
        u32CdrValue = REG_READ32(ADCDIG_CH_DATA_REG_ADDR32(Unit, (uint32)Adc_pCfgPtr->pChannels[Unit][ChIndex].ChId));
        bFlagStatus = (boolean)FALSE;
        if(0U == (u32CdrValue & ADCDIG_VALID_DATA_MASK_U32))
        {
            for (PreviousCh = (Adc_ChannelType)0U; PreviousCh < Ch; PreviousCh++)
            {
#if (ADC_SETCHANNEL_API == STD_ON)
                /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                PreviousChIndex = Adc_aRuntimeGroupChannel[Group].pChannel[PreviousCh];
#else
                /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
                PreviousChIndex = Adc_pCfgPtr->pGroups[Group].pAssignment[PreviousCh];
#endif
                if (PreviousChIndex == ChIndex)
                {
                    bFlagStatus = (boolean)TRUE;
                    break;
                }
            }
        }
        else
        {
            bFlagStatus = (boolean)TRUE;
        }
        if ((boolean)TRUE == bFlagStatus)
        {
            /**
            * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
            * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer.
            * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
            */
            *(pDataPtr+Ch) = (uint16)(u32CdrValue & u32CdrMask);
        }
        else
        {
            /* data are not measured yet -> VALID flag not set yet */
            Adc_ReadGroupRet = (Std_ReturnType)E_NOT_OK;
            break;
        }
    }
    /* Global Interrupt enable to protect code section */
    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_23();

    return(Adc_ReadGroupRet);
}
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) */
#endif /* (ADC_HW_TRIGGER_API == STD_ON) */


#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
/**
* @brief          This function starts the conversion on the specified hardware Unit.
* @details        This function starts the conversion on the specified hardware Unit.
*                 This function should be called with the ADC Unit on standby (no ADC interruptions
*                 allowed because its code is not protected by critical regions) - no conversions must
*                 be running.
*
* @param[in]      Unit            the used hw Unit.
*
* @return         void
*
*/
/**
* @violates @ref Adc_Adcdig_c_REF_10 All declarations and definitions of objects or
* functions at file scope shall have internal linkage unless external linkage is required
*/
FUNC(void, ADC_CODE) Adc_Adcdig_StartNormalConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */
    VAR(Adc_GroupType, AUTOMATIC) Group = 0U; /* Active group in the Queue */
    VAR(Adc_NCMRType, AUTOMATIC) CMRMask;

    if ((Adc_QueueIndexType)0 == Adc_aUnitStatus[Unit].SwNormalQueueIndex)
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return;
    }

    /* Get the Group ID of the current active group */
    /* Load the first group in the queue (Adc_aUnitStatus[Unit].SwNormalQueue[0])*/
    Group = Adc_aUnitStatus[Unit].SwNormalQueue[0];
    
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    if(((boolean)TRUE == Adc_aGroupStatus[Group].bLimitCheckFailed) && (ADC_CONV_MODE_ONESHOT == pGroupPtr->eMode))
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return;
    }
#endif /* ADC_ENABLE_LIMIT_CHECK == STD_ON */

#if ((defined(ADC_WDG_SUPPORTED)) || (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF))
    Adc_Adcdig_PrepareGroupStart(Unit, pGroupPtr);
#endif /* ((defined(ADC_WDG_SUPPORTED)) || (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)) */

    /** @violates @ref Adc_Adcdig_c_REF_12 It is needed for calculation value of go back space for source address.*/
    Adc_GetCMR_Register(Unit, Group, &CMRMask);

    /* Program the Normal Conversion Mask register */
    Adc_Adcdig_SetNcmrRegisters(Unit, CMRMask.Adc_u32NCMR0, CMRMask.Adc_u32NCMR1, CMRMask.Adc_u32NCMR2);

    /* Program the Mode */
    if(ADC_CONV_MODE_ONESHOT == pGroupPtr->eMode)
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit),ADCDIG_CONVERSION_MODE_U32);
    }
    else
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit),ADCDIG_CONVERSION_MODE_U32);
    }     

    /* Clear Interrupt status flag*/
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CLEAN_U32);
    
#ifdef ADC_DMA_SUPPORTED
    if (ADC_DMA == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
    {
        /* If the group is configured for with interrupts*/
        if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_WRITE32(ADCDIG_DMAE_REG_ADDR32(Unit), ADCDIG_DMA_GLOBAL_EN_U32 | ADCDIG_DMA_CLEAR_ON_READ_U32);
            Adc_Adcdig_StartDmaOperation(Unit, Group);
        }
    }
    else
#endif /* ADC_DMA_SUPPORTED */
    {
        /* If the group is configured for with interrupts*/
        if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
        {
            /* Enable Interrupt */
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            REG_BIT_SET32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_NORM_CONV_EN_U32);
        }
    }

    /* Start Normal Conversion */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_START_CONV_EN_U32);
}
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#ifdef ADC_DMA_SUPPORTED
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_ConfigureDmaTcd
(
    VAR(Adc_GroupType, AUTOMATIC)       Group,
    VAR(Adc_ChannelIndexType, AUTOMATIC) FirstChannel,
    VAR(Adc_ChannelIndexType, AUTOMATIC) LastChannel,
    P2VAR(Mcl_DmaTcdAttributesType, AUTOMATIC, ADC_APPL_DATA) pDmaTcdConfig
)
{
    VAR(uint32, AUTOMATIC) u32DesAddr;
    VAR(uint32, AUTOMATIC) u32DesOff;
    VAR(uint32, AUTOMATIC) u32SourceAddr;
    VAR(uint32, AUTOMATIC) u32SrcOff = 4UL;
    VAR(Adc_ChannelType, AUTOMATIC) FirstCh;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroups = NULL_PTR;
    VAR(uint32, AUTOMATIC) u32Iter;
    
    /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
    pGroups = &(Adc_pCfgPtr->pGroups[Group]);
    /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
    ChIndex = pGroups->pAssignment[FirstChannel];
    /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
    FirstCh = Adc_pCfgPtr->pChannels[pGroups->HwUnit][ChIndex].ChId;
    
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
    if ((boolean) TRUE == pGroups->bAdcDoubleBuffering)
    {
        u32DesOff = 2UL;
        u32SrcOff = 0UL;
        u32Iter = (uint32) pGroups->NumSamples;
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32DesAddr = (uint32)(pGroups->pResultsBufferPtr[Group]);
    }
    else
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */      
    {

#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        Unit = pGroups->HwUnit;
        /* Get the index of hardware Unit*/
        HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        if((boolean)TRUE == Adc_ChannelsLimitCheckingCfg[HwIndex][ChIndex].bChannelLimitCheck)
        {   
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            u32DesAddr = (uint32)&Adc_Adcdig_aDmaInternalResultBuffer[HwIndex];
            u32DesOff  = 0UL;
        }
        else
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            u32DesAddr = (uint32)(pGroups->pResultsBufferPtr[Group] + ((uint32)FirstChannel*(uint32)pGroups->NumSamples));
            u32DesOff  = (uint32)pGroups->NumSamples << 1U;
        }
        u32Iter = (uint32)1UL;
    }
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        u32SourceAddr = (uint32)(ADCDIG_CH_DATA_REG_ADDR32(pGroups->HwUnit, FirstCh));
#if CPU_BYTE_ORDER == HIGH_BYTE_FIRST
        u32SourceAddr = u32SourceAddr + 2UL;
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */ 

        pDmaTcdConfig->u32saddr     = (uint32)u32SourceAddr;
        pDmaTcdConfig->u32ssize     = (uint32)DMA_SIZE_2BYTES;
        pDmaTcdConfig->u32dsize     = (uint32)DMA_SIZE_2BYTES;
        pDmaTcdConfig->u32soff      = (uint32)u32SrcOff;
        pDmaTcdConfig->u32num_bytes = (uint32)(((uint32)LastChannel + 1U) - (uint32)FirstChannel) << 1U;
        pDmaTcdConfig->u32daddr     = (uint32)u32DesAddr;
        pDmaTcdConfig->u32iter      = (uint32)u32Iter;
        pDmaTcdConfig->u32doff      = (uint32)u32DesOff;
        pDmaTcdConfig->u32smod      = (uint32)0UL;
        pDmaTcdConfig->u32dmod      = (uint32)0UL;
}
/**
* @brief          This function programs the DMA transfers involved in the ADC conversion process.
* @details        This function should be called with the ADC Unit on standby (no ADC interruptions
*                 allowed because its code is not protected by critical regions) - no conversions must
*                 be running.
*
* @param[in]      Unit            the used hw Unit.
*
* @return         void
*
* @pre ADC Unit is not running anything.
*
* @violates @ref Adc_Adcdig_c_REF_10 internal linkage or external linkage
*/

LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Adcdig_StartDmaOperation
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(Adc_GroupType, AUTOMATIC) Group
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(sint32, AUTOMATIC) s32DLast = (sint32)0;
    VAR(sint32, AUTOMATIC) s32SLast = (sint32)0;
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
    VAR(Adc_ChannelType, AUTOMATIC) Index = 0U;
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
    VAR(boolean, AUTOMATIC) bChangeChType = (boolean)FALSE;
    VAR(Adc_ChannelType, AUTOMATIC) PreChannel = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) CrtChannel = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChIdx = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) FirstChannel = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) LastChannel = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) NumSegment = 0U;
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel = 0U;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) pTcdAddress;
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroups = NULL_PTR;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;

    /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
    pGroups = &(Adc_pCfgPtr->pGroups[Group]);
    /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
    ChannelCount = Adc_pCfgPtr->pGroups[Group].AssignedChannelCount;
    /* Read all data register to clear any pending DMA requests */
    for(ChIdx = 0U; ChIdx < Adc_pCfgPtr->Misc.aAdc_Channels[Unit]; ChIdx++)
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        CrtChannel = Adc_pCfgPtr->pChannels[Unit][ChIdx].ChId;
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer. */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        (void)REG_READ32(ADCDIG_CH_DATA_REG_ADDR32(Unit, CrtChannel));
    }
    DmaChannel = (Mcl_ChannelType)Adc_pCfgPtr->Misc.au8Adc_DmaChannel[Unit];
    /* Disable DMA hw request */
    Mcl_DmaDisableHwRequest(DmaChannel);   
    /* Get the index of hardware Unit*/
    HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
    
    /* First channel will be the first element of channel group, Search the continuous channel segment */
    for(ChIdx = 0U; ChIdx < ChannelCount; ChIdx++)
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        CrtChannel = Adc_pCfgPtr->pChannels[Unit][pGroups->pAssignment[ChIdx]].ChId;
        /* Ignore if this is the first element of channel group or the channel had changed type between Internal/Test/External channel */
        if((ChIdx > 0U) && ((boolean)FALSE == bChangeChType))
        {
            /* If channel is not continuous, A new segment is detected */
            if(CrtChannel != (PreChannel + 1U))
            {
                LastChannel = ChIdx - 1U;
                /* Store TCD configuration */
                Adc_Adcdig_ConfigureDmaTcd(Group, FirstChannel, LastChannel, &Adc_Adcdig_aDmaTcdConfig[HwIndex][NumSegment]);
                FirstChannel = ChIdx;
                NumSegment++;
            }
        }
        /* If the last channel had changed type between Internal/Test/External channel */
        if((boolean)TRUE == bChangeChType)
        {
            FirstChannel = ChIdx;
            bChangeChType = (boolean)FALSE;
        }
        /* If the channel is the last channel of channel group, mean that this is last channel of a segment */
        if((CrtChannel == ADC_ED_EXTERNAL_CH_U8) || (CrtChannel == ADC_ED_TST_CH_U8) || 
           (CrtChannel == ADC_ED_EXT_CH_U8) || (ChIdx >= (ChannelCount - 1U))
          )
        {
            LastChannel = ChIdx;
            bChangeChType = (boolean)TRUE;
            /* Store TCD configuration */
            Adc_Adcdig_ConfigureDmaTcd(Group, FirstChannel, LastChannel, &Adc_Adcdig_aDmaTcdConfig[HwIndex][NumSegment]);
            NumSegment++;
        }
        /* Store the current channel */
        PreChannel = CrtChannel;
    }
    /* Enable the last channel of the chain to transfer data in DMA mode */
    Adc_Adcdig_SetDmarRegisters(Unit, (Adc_ChannelType)pGroups->LastCh);
    /* Store the number channel segments of corrent group */
    Adc_aUnitStatus[Unit].NumSegment = NumSegment;
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    pTcdAddress = (Mcl_DmaTcdType*)Mcl_DmaGetChannelTcdAddress(DmaChannel);

    if(1U == NumSegment)
    {
        /* Configure DMA TCD channel */
        Mcl_DmaConfigTcd(pTcdAddress, &Adc_Adcdig_aDmaTcdConfig[HwIndex][0]);
#if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
        if ((boolean) TRUE == pGroups->bAdcDoubleBuffering)
        {
            Mcl_DmaTcdSetFlags(pTcdAddress, (DMA_TCD_INT_HALF_U8 | DMA_TCD_INT_MAJOR_U8));
        }
        else
#endif /* (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING) */
        {
            Mcl_DmaTcdSetFlags(pTcdAddress, (DMA_TCD_DISABLE_REQ_U8 | DMA_TCD_INT_MAJOR_U8));
        }
#if (ADC_ENABLE_LIMIT_CHECK == STD_ON)
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        Index = pGroups->pAssignment[0];
        /** @violates @ref Adc_Adcdig_c_REF_8 only Array indexing shall be allowed */
        if((boolean)FALSE == Adc_ChannelsLimitCheckingCfg[HwIndex][Index].bChannelLimitCheck)
#endif /* (ADC_ENABLE_LIMIT_CHECK == STD_ON) */
        {
            /* The channels are continuous, no need to use scatter gather mode */
            if(ADC_ACCESS_MODE_SINGLE == pGroups->eAccessMode)
            {
                /** @violates @ref Adc_Adcdig_c_REF_12 It is needed for calculation value of go back space for source address.*/
                /** @violates @ref Adc_Adcdig_c_REF_16 The value of a complex expression of integer type may only be cast to a type that is narrower */
                s32DLast = -(sint32)((uint32)ChannelCount << 1U);
            }
            else
            {
            #if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
                if ((boolean) TRUE == pGroups->bAdcDoubleBuffering)
                {
                    /** @violates @ref Adc_Adcdig_c_REF_12 It is needed for calculation value of go back space for source address.*/
                    /** @violates @ref Adc_Adcdig_c_REF_16 The value of a complex expression of integer type may only be cast to a type that is narrower */
                    s32DLast = -(sint32)((uint32)pGroups->NumSamples << 1U);
                }
                else
            #endif
                {
                    /** @violates @ref Adc_Adcdig_c_REF_12 It is needed for calculation value of go back space for source address.*/
                    /** @violates @ref Adc_Adcdig_c_REF_16 The value of a complex expression of integer type may only be cast to a type that is narrower */
                    s32DLast = -(sint32)((((uint32)ChannelCount * (uint32)pGroups->NumSamples) - 1UL) << 1U);
                }
            }
            Mcl_DmaTcdSetDlast(pTcdAddress, s32DLast);
        }
        #if (STD_ON == ADC_ENABLE_DOUBLE_BUFFERING)
        if((boolean)FALSE == pGroups->bAdcDoubleBuffering)
        #endif
        {
            /** @violates @ref Adc_Adcdig_c_REF_12 It is needed for calculation value of go back space for source address.*/
            /** @violates @ref Adc_Adcdig_c_REF_16 The value of a complex expression of integer type may only be cast to a type that is narrower. */
            s32SLast = -(sint32)((uint32)ChannelCount << 2U);
            Mcl_DmaTcdSetSlast(pTcdAddress, s32SLast);
        }
    }
    else
    {
        /* Need to update destination to next sample in the ISR */
        for(ChIdx = 0U; ChIdx < (NumSegment - 1U); ChIdx++)
        {
            /* Configure scatter gather TCD */
            Mcl_DmaConfigScatterGatherTcd(Adc_Adcdig_aDmaTcdConfigMem[HwIndex][ChIdx], &Adc_Adcdig_aDmaTcdConfig[HwIndex][ChIdx], Adc_Adcdig_aDmaTcdConfigMem[HwIndex][ChIdx + 1U]);
            /* Set START bit for configured memory TCD */
            Mcl_DmaTcdSetFlags(Adc_Adcdig_aDmaTcdConfigMem[HwIndex][ChIdx], (DMA_TCD_DISABLE_REQ_U8 | DMA_TCD_START_U8 | DMA_TCD_E_SG_U8));
        }
        /* Setting the last TCD configuration, it does not link to first configuration */
        Mcl_DmaConfigTcd(Adc_Adcdig_aDmaTcdConfigMem[HwIndex][ChIdx], &Adc_Adcdig_aDmaTcdConfig[HwIndex][ChIdx]);
        /* Set START bit for configured memory TCD and enable interrupt for the last transfer */
        Mcl_DmaTcdSetFlags(Adc_Adcdig_aDmaTcdConfigMem[HwIndex][ChIdx], (DMA_TCD_DISABLE_REQ_U8 | DMA_TCD_START_U8 | DMA_TCD_INT_MAJOR_U8));
        /* Enable Scatter Gather for DMA channel, link configuration 0 to configuration 1 */
        /** @violates @ref Adc_Adcdig_c_REF_12 It is needed for calculation value of go back space for source address.*/
        Mcl_DmaConfigScatterGatherTcd(pTcdAddress, &Adc_Adcdig_aDmaTcdConfig[HwIndex][0], Adc_Adcdig_aDmaTcdConfigMem[HwIndex][1]);
    }
    /* Start the DMA channel */
    Mcl_DmaEnableHwRequest(DmaChannel);
}

#endif /* ADC_DMA_SUPPORTED */

#if (ADC_ENABLE_START_STOP_GROUP_API == STD_ON)
#if (ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON) 
/**
* @brief          This function starts the injected conversion on the specified hardware Unit.
* @details        This function starts the injected conversion on the specified hardware Unit.
*                 This function should be called with the ADC Unit on idle or busy.
*
* @param[in]      Unit            The used hw Unit.
*
* @return         void
* @violates @ref Adc_Adcdig_c_REF_10 u32External linkage
*/
FUNC(void, ADC_CODE) Adc_Adcdig_StartInjectedConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr; /* Pointer to AdcGroup */
    VAR(Adc_GroupType, AUTOMATIC) Group = 0U; /* Active group in the Queue */
    VAR(Adc_NCMRType, AUTOMATIC) CMRMask;

    if ((Adc_QueueIndexType)0 == Adc_aUnitStatus[Unit].SwInjectedQueueIndex)
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return;
    }

    /* Get the Group ID of the current active group */
    /* Load the first group in the queue (Adc_aUnitStatus[Unit].SwInjectedQueue[0])*/
    Group=Adc_aUnitStatus[Unit].SwInjectedQueue[0];

    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
#if ((defined(ADC_WDG_SUPPORTED)) || (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF))
    Adc_Adcdig_PrepareGroupStart(Unit, pGroupPtr);
#endif /* ((defined(ADC_WDG_SUPPORTED)) || (ADC_SET_ADC_PRESAMPLE_ONCE == STD_OFF) || (ADC_SET_ADC_CONV_TIME_ONCE == STD_OFF)) */

    /** @violates @ref Adc_Adcdig_c_REF_12 It is needed for calculation value of go back space for source address.*/
    Adc_GetCMR_Register(Unit, Group, &CMRMask);
    
    /* Program the Injected Conversion Mask register */
    Adc_Adcdig_SetJcmrRegisters(Unit, CMRMask.Adc_u32NCMR0, CMRMask.Adc_u32NCMR1, CMRMask.Adc_u32NCMR2);
    /* Clear Interrupt status flag*/
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_ISR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_CLEAN_U32);

    /* If the group is configured for with interrupts*/
    if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
    {
        /* Enable Interrupt*/
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_EN_U32);
    }
    else
    {
        /* Disable Interrupt*/
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(ADCDIG_IMR_REG_ADDR32(Unit), ADCDIG_ISR_END_CHAIN_INJ_CONV_EN_U32);
    }

    /* Start Injected Conversion */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_INJ_START_CONV_EN_U32);
}
#endif /* ADC_SOFTWARE_INJECTED_CONVERSIONS_USED == STD_ON */
#endif /* (ADC_ENABLE_START_STOP_GROUP_API == STD_ON) */

#if (ADC_SET_MODE_API == STD_ON)
/**
* @brief          This function sets the PWDN bit while going in power down mode or clears it
*                 upon exit from power down mode.
* @details        Set power down/ normal mode.
*
* @param[in]      eSetMode         ADC_NORMAL_MODE,ADC_POWER_DOWN_MODE.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful set mode.
* @retval         E_NOT_OK        In case of unsuccessful set mode.
*
*/
FUNC (Std_ReturnType, ADC_CODE) Adc_Adcdig_SetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) eSetMode
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex = 0U; /* Hardware Unit index */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U; /* Hardware Unit ID */
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_OK;

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_05();

    if(ADC_POWER_DOWN_MODE == eSetMode)
    {
        for (HwIndex = 0U; HwIndex < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Unit = (Adc_HwUnitType)(Adc_pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId);
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            if (ADCDIG_CTU_CONV_FINISH_U32 != ((REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_CTU_CONV_ONGOING_U32))
            {
                SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
            #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
                if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
                {
                    /* Report production error and return from function. */
                    Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
                }
            #endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
                /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
                return ((Std_ReturnType)E_NOT_OK);
            }
                
        }
        for (HwIndex = 0U; HwIndex < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Unit = (Adc_HwUnitType)(Adc_pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId);
            /* enter into power-down Mode */
            if((Std_ReturnType)E_NOT_OK == Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE))
            {
                /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
                return (Std_ReturnType)E_NOT_OK;
            }
        }
    }
    else
    {
        for (HwIndex = 0U; HwIndex < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; HwIndex++)
        {
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Unit = (Adc_HwUnitType)(Adc_pCfgPtr->pAdc[HwIndex].AdcHardwareUnitId);
            /* Exit from PowerDown Mode */
            if((Std_ReturnType)E_NOT_OK == Adc_Adcdig_WritePowerDownBit(Unit, (boolean)FALSE))
            {
                /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
                return (Std_ReturnType)E_NOT_OK;
            }
        }
    }

    SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_05();
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
  #if (ADC_BCTU_AVAILABLE == STD_ON)
    /* Set mode for BCTU */
    TempReturn = Adc_Bctu_SetMode(eSetMode);
  #endif /* ADC_BCTU_AVAILABLE == STD_ON */
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
    {
        /* Report production error passed.  */
        Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
    }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
    return (TempReturn);
}
#endif /* (ADC_SET_MODE_API == STD_ON) */

#if (ADC_CALIBRATION == STD_ON)
/**
* @brief          Checks the ADC hardware status.
* @details        Checks the ADC hardware status and compares it with the flag parameter.
*
* @param[in]      Unit            The hardware Unit.
* @param[in]      u32testFlag     The flag that the status should be checked against.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of adc status read as expected.
* @retval         E_NOT_OK        In case of timeout while waiting for adc status to stabilize.
*
* @pre            Driver must be initialized.
*/
LOCAL_INLINE Std_ReturnType Adc_Adcdig_StatusTimeoutCalibration
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32testFlag
)
{
    VAR(volatile uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
    VAR(Std_ReturnType, AUTOMATIC) returnValue = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32MsrStatus;

    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
    while(u32MsrStatus != u32testFlag)
    {
        /* If the ongoing conversion is not aborted, report the production error */
        if (u32Timeout > 0UL)
        {
            u32Timeout--;        
        }
        else
        {
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
            {
                /* Report production error and return from function. */
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            returnValue = (Std_ReturnType)E_NOT_OK;
        }
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
    }
 
    return returnValue;
}

/**
* @brief          Executes high accuracy calibration of a ADC HW Unit.
* @details        This function calibrates the ADC HW Unit and updates calibration related registers
*
* @param[in]      Unit      ADC Unit Id.
* @param[in]      pStatus   Status of the ADC HW Unit calibration and
*                           list of failed/passed tests.
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Adcdig_Calibrate
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    P2VAR(Adc_CalibrationStatusType , AUTOMATIC, ADC_APPL_DATA) pStatus
)
{
#if (defined(ADC_BIST1_AVAILABLE) || defined(ADC_CALSTAT_AVAILABLE))
    VAR(uint8, AUTOMATIC) u8Index;
#endif /* (defined(ADC_BIST1_AVAILABLE)||defined(ADC_CALSTAT_AVAILABLE)) */
    VAR(volatile uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
    VAR(volatile uint32, AUTOMATIC) u32MsrStatus;
    VAR(uint32, AUTOMATIC) u32McrStatus;
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_OK;
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    VAR(Std_ReturnType, AUTOMATIC) TempCheck = (Std_ReturnType)E_OK;
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

    SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();
    pStatus->Adc_UnitSelfTestStatus = (Std_ReturnType)E_NOT_OK;
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32McrStatus = REG_READ32(ADCDIG_MCR_REG_ADDR32(Unit));
    
    /* 1. Configure the ADC. */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_POWER_DOWN_U32);
    TempReturn = Adc_Adcdig_StatusTimeoutCalibration(Unit, ADCDIG_POWERDOWN_STATUS_U32);
    if ((Std_ReturnType)E_NOT_OK == TempReturn)
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return ;
    }
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CLOCK_PRESCALER_DIV1_U32);
    /* Exit from PowerDown Mode */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_POWER_DOWN_U32);
    
    u32Timeout = ADC_TIMEOUT_COUNTER;
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
    while(u32MsrStatus != ADCDIG_IDLE_OFFSET_STATUS_U32)
    {
        if (u32Timeout > 0UL)
        {
            u32Timeout--;
        }
        else
        {
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
            if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
            {
                /* Report production error and return from function. */
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            }
            SchM_Enter_Adc_ADC_EXCLUSIVE_AREA_16();
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
            return;
        }
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
    }  
    TempReturn = Adc_Adcdig_StatusTimeoutCalibration(Unit, ADCDIG_IDLE_OFFSET_STATUS_U32);
    if ((Std_ReturnType)E_NOT_OK == TempReturn)
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return ;
    }

#ifdef ADC_CALBISTREG_NOT_AVAILABLE
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_MCR_CALIBRATE_MASK_U32, \
              ADCDIG_TSAMP_U32(3UL) | ADCDIG_NR_SMPL_U32(3UL) | ADCDIG_AVG_EN_U32 \
             );
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CALSTART_U32);
#else
    /* 2. Configure the Calibration, BIST Control, and status register (CALBISTREG) for
          TEST conditions. The default values are set for maximum accuracy (recommended). */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_RMW32(ADCDIG_CALBISTREG_REG_ADDR32(Unit), ADCDIG_CALBISTREG_REG_MASK_U32, \
              ADCDIG_TSAMP_U32(2UL) | ADCDIG_NR_SMPL_U32(3UL) | ADCDIG_AVG_EN_U32 \
             );
    /* 3. Set the TEST_EN bit of CALBISTREG. (The routine will start immediately) */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_CALBISTREG_REG_ADDR32(Unit), ADCDIG_TEST_EN_U32);
#endif /* ADC_CALBISTREG_AVAILABLE */

    /* 4. Poll the status of MSR.ADCSTATUS[2:0] (wait till it remains in 011b [Busy in Calibration]) */
    if ((Std_ReturnType) E_NOT_OK == Adc_Adcdig_StatusTimeoutCalibration(Unit, ADCDIG_IDLE_OFFSET_STATUS_U32))
    {
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return;
    }
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
    u32Timeout = ADC_TIMEOUT_COUNTER;
    /** @violates @ref Adc_Adcdig_c_REF_13 the right-hand operand of a logical "&&" or "||" operator
       shall not contain side effects.*/
    while((u32MsrStatus != ADCDIG_IDLE_OFFSET_STATUS_U32) && \
          (u32MsrStatus != ADCDIG_BUSY_IN_HIGH_ACCURACY_STATUS_U32) && (u32Timeout > (uint32)0U) \
         )
    {
        u32Timeout--;
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        u32MsrStatus = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
    }

    if ((uint32)0UL == u32Timeout)
    {
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
        {
            /* Report production error failed. */
            Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            TempCheck = (Std_ReturnType)E_NOT_OK;
        }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
    }
    else
    {
     
        /* 5. Check the value of MSR.CALIBRATED bit for successfulness of calibration. */
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        if (((REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_CALIBRTD_STATUS_U32) == ADCDIG_CALIBRTD_CALIBRATED_U32)
        {
            pStatus->Adc_UnitSelfTestStatus = (Std_ReturnType)E_OK;
        }
#ifdef ADC_BIST1_AVAILABLE
        /* 6. If the status of MSR.CALIBRATED is '1', calibration is successful, otherwise check
              the status bits (STAT_n, n= 1-12) of the BIST 1 Register (BIST1) to know the status
              of individual steps for further diagnosis. */
        for (u8Index = 0U; u8Index < (uint32)ADCDIG_MAX_CALIBRATION_STEPS; u8Index++)
        {
            pStatus->Adc_Calibrate_Failed_Steps[u8Index] = 0U;
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            if(((REG_READ32(ADC_BIST1_REG_ADDR(Unit))) & (uint32)ADCDIG_STAT_MASK_U32((uint32)u8Index)) == \
               (uint32)ADCDIG_STAT_FAIL_MASK_U32((uint32)u8Index)
              )
            {
                pStatus->Adc_Calibrate_Failed_Steps[u8Index] = 1U;
            }
        }
#endif /* ADC_BIST1_AVAILABLE */
#ifdef  ADC_CALSTAT_AVAILABLE
        /* 6. If the status of MSR.CALIBRATED is '1', calibration is successful, otherwise check
        the status bits (STAT_n, n= 1-12) of the CALSTAT Register to know the status
        of individual steps for further diagnosis. */
        for (u8Index = 0U; u8Index < (uint32)ADCDIG_MAX_CALIBRATION_STEPS; u8Index++)
        {
            pStatus->Adc_Calibrate_Failed_Steps[u8Index] = 0U;
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            if(((REG_READ32(ADC_CALSTAT_REG_ADDR32(Unit))) & (uint32)ADCDIG_STAT_MASK_U32((uint32)u8Index)) == \
               (uint32)ADCDIG_STAT_FAIL_MASK_U32((uint32)u8Index)
              )
            {
                pStatus->Adc_Calibrate_Failed_Steps[u8Index] = 1U;
            }
        }
#endif /* ADC_CALSTAT_AVAILABLE */
    }

    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_POWER_DOWN_U32);
    TempReturn = Adc_Adcdig_StatusTimeoutCalibration(Unit, ADCDIG_POWERDOWN_STATUS_U32);
    if ((Std_ReturnType)E_NOT_OK == TempReturn)
    {
        pStatus->Adc_UnitSelfTestStatus = (Std_ReturnType)E_NOT_OK;
        /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
        return ;
    }
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_12 place reliance on undefined or unspecified behaviour */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CLOCK_PRESCALER_MASK_U32, u32McrStatus);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_POWER_DOWN_U32);
    TempReturn = Adc_Adcdig_StatusTimeoutCalibration(Unit, ADCDIG_IDLE_OFFSET_STATUS_U32);
    if ((Std_ReturnType)E_NOT_OK == TempReturn)
    {
        pStatus->Adc_UnitSelfTestStatus = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        SchM_Exit_Adc_ADC_EXCLUSIVE_AREA_16();
    }
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    if ((uint32)STD_ON == Adc_E_TimeoutCfg.state)
    {
        if (((Std_ReturnType)E_OK == TempReturn) && ((Std_ReturnType)E_OK == TempCheck))
        {
            /* Report production must be reported error passed.  */
            Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_PASSED);
        }
    }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
    return;
}
#endif /* ADC_CALIBRATION == STD_ON */

#if (ADC_SELF_TEST == STD_ON)
/**
* @brief          Executes hardware Self Test of a ADC HW Unit.
* @details        This function checks if the ADC HW Unit is functioning correctly
*
* @param[in]      Unit    ADC Unit Id.
*
* @return         Std_ReturnType. Status of the ADC HW Unit Self Test.
*
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_SelfTest
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
   VAR(uint8, AUTOMATIC) u8Index = 0U;
   VAR(volatile uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
   VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_OK;

   /* 1. Program NCMR0 to select channels to be converted for normal conversion.*/
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_NCMR0_REG_ADDR32(Unit), 0x1UL);

    /* 2. Program MCR[MODE] = 1 to select Scan mode. ADC_ONE_SHOT_MODE_U32 ADCDIG_CONTINUOUS_MODE_U32*/
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned  int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CONTINUOUS_MODE_U32);

    /* 3. Program sampling duration values in STCR1[INPSAMPx].*/
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_RMW32(ADCDIG_STCR1_REG_ADDR32(Unit), ADCDIG_STCR1_MASK_U32, (ADCDIG_INPSAMP_C_U32(10UL) | ADCDIG_INPSAMP_S_U32(10UL)));

    /* 4. Select the self-testing algorithm in STCR3[ALG]. */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_STCR3_REG_ADDR32(Unit),ADCDIG_STCR3_ALG_C_U32);

    /* 5. Enable the self-testing channel by setting STCR2[EN]. */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_STCR2_REG_ADDR32(Unit), ADCDIG_STCR2_EN_SET_U32);

    /* 6. Start the normal conversion by setting MCR[NSTART]. */
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_START_CONV_EN_U32);

    u32Timeout = ADC_TIMEOUT_COUNTER;
    /* check that all algorithms have executed at least once */
    for (u8Index = 0U; u8Index < 2U; u8Index++)
    {
        /* Wait until Alg S has started*/
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        while(ADCDIG_SELF_TEST_S_U32 != ((REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_SELF_TEST_S_U32))
        { 
            if (u32Timeout > 0UL)
            {
                u32Timeout--;                
            }
            else
            {
                break;
            }
        }
        /* Wait until Alg S has finished*/
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        while(ADCDIG_SELF_TEST_S_U32 == ((REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_SELF_TEST_S_U32))
        {
            if (u32Timeout > 0UL)
            {
                u32Timeout--;                
            }
            else
            {
                break;
            }
        }
    }
    if (0UL == u32Timeout)
    {
        TempReturn = (Std_ReturnType)E_NOT_OK;
    }
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    if (0U != ((REG_READ32(ADCDIG_STSR1_REG_ADDR32(Unit))) & \
               (ADCDIG_STSR1_ERR_C_U32 | ADCDIG_STSR1_ERR_S2_U32 | ADCDIG_STSR1_ERR_S1_U32 | ADCDIG_STSR1_ERR_S0_U32)
              )
       )
    {
        TempReturn = (Std_ReturnType)E_NOT_OK;
    }

    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_NORMAL_START_CONV_EN_U32);

    return TempReturn;
}
#endif /* ADC_SELF_TEST == STD_ON */

#if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON)
/**
 * @brief   Function to reconfigure High and Low thresholds for a given group.
 * @details This Non Autosar API is used to reconfigure High and Low thresholds for a given group.
 *
 * @param[in]  GroupId          Index of group
 * @param[in]  LowValue         Low threshold value for channels in the group
 * @param[in]  HighValue        High threshold value for channels in the group
 *
 * @return         Std_ReturnType  E_OK or E_NOT_OK.
 * @retval         E_OK            In case of successful Configure Threshold.
 * @retval         E_NOT_OK        In case of unsuccessful ConfigureThreshold.
 */
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_ConfigureThreshold
(
    VAR(Adc_GroupType, AUTOMATIC) GroupId,
    VAR(Adc_ValueGroupType, AUTOMATIC) LowValue,
    VAR(Adc_ValueGroupType, AUTOMATIC) HighValue
)
{
    VAR(Std_ReturnType, AUTOMATIC) Adc_ConThdRet = (Std_ReturnType)E_NOT_OK;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChCount = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) Channel = 0U;
    VAR(uint32, AUTOMATIC) u32MaxHighValue = 0U;
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;
    VAR(uint32, AUTOMATIC) u32ThValue = ADCDIG_LOW_TH_VALUE_U32(LowValue) | ADCDIG_HIGH_TH_VALUE_U32((uint32)HighValue);

    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
    Unit = Adc_pCfgPtr->pGroups[GroupId].HwUnit;

    /* Get the index of hardware Unit*/
    HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];

    /* Test that the High value is within range */
    /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of */
    u32MaxHighValue = ADCDIG_HIGH_TH_VALUE_U32(((1UL << Adc_pCfgPtr->pAdc[HwIndex].Res) - 1UL));

    if (u32MaxHighValue > ADCDIG_HIGH_TH_VALUE_U32((uint32)HighValue))
    {

#if (ADC_SETCHANNEL_API == STD_ON)
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of */        
        ChannelCount = Adc_aRuntimeGroupChannel[GroupId].ChannelCount;
#else
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of */
        ChannelCount = Adc_pCfgPtr->pGroups[GroupId].AssignedChannelCount;
#endif

        /* Check the channels in the group one by one, set the threshold values if threshold is enabled */
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        for(ChCount = 0U; ChCount < ChannelCount; ChCount++)
        {
#if (ADC_SETCHANNEL_API == STD_ON)
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Channel = Adc_aRuntimeGroupChannel[GroupId].pChannel[ChCount];
#else
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            Channel = Adc_pCfgPtr->pGroups[GroupId].pAssignment[ChCount];
#endif
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
            if(ADC_UNUSED_THRESHOLD_U8 != Adc_pCfgPtr->pChannels[Unit][Channel].u8ThReg)
            {
                /**
                * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer
                * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(ADCDIG_THRHLRx_REG_ADDR32(Unit, Adc_pCfgPtr->pChannels[Unit][Channel].u8ThReg), u32ThValue);
                Adc_ConThdRet = (Std_ReturnType)E_OK;
            }
        }
    }
    return Adc_ConThdRet;
}
#endif /* if (ADC_ENABLE_CONFIGURE_THRESHOLD_NONAUTO_API == STD_ON) */

#if (ADC_DUAL_CLOCK_MODE == STD_ON)
/**
* @brief          This function sets the Prescaler value only when ADC is in power down mode.
* @details        Set prescaler clock divider only in power down mode.
*
* @param[in]      eClockMode       ADC_NORMAL, ADC_ALTERNATE.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of successful set mode.
* @retval         E_NOT_OK        In case of unsuccessful set mode.
*
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_SetClockMode
(
   VAR(Adc_DualClockModeType, AUTOMATIC) eClockMode
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = 0U; /* Hardware Unit index */
    VAR(Adc_HwUnitType, AUTOMATIC) HwIndex; /* Index of hardware Unit */
    P2CONST(Adc_Adcdig_HwUnitConfigurationType, AUTOMATIC, ADC_APPL_CONST) UnitConfigPtr; /* Pointer to Hw Unit config */
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON)
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime1 = 0U;
    VAR(Adc_ConversionTimeType, AUTOMATIC) ConvTime2 = 0U;
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON) */
    VAR(uint32, AUTOMATIC) u32MsrValue;
    
    for (Unit = 0U; Unit < ADC_MAX_HW_UNITS; Unit++)
    {
        if((uint8)STD_ON == ADC_HW_UNITS(Unit))
        {
            /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
            /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
            u32MsrValue = (REG_READ32(ADCDIG_MSR_REG_ADDR32(Unit))) & ADCDIG_STATUS_U32;
            if(u32MsrValue != ADCDIG_POWERDOWN_STATUS_U32)
            {
                /* Enter to PowerDown Mode */
                if((Std_ReturnType)E_NOT_OK == Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE))
                {
                    /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
                    return (Std_ReturnType)E_NOT_OK;
                }
            }
            /* Get the index of hardware Unit*/
            HwIndex = Adc_pCfgPtr->Misc.aHwLogicalId[Unit];
            /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall */
            UnitConfigPtr = &(Adc_pCfgPtr->pAdc[HwIndex]);
            if ((Adc_DualClockModeType)ADC_NORMAL == eClockMode)
            {
                /* Write the configured power down exit delay value into PDEDR register */
                /**
                * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer.
                * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(ADCDIG_PDEDR_REG_ADDR32(Unit),UnitConfigPtr->u8AdcPwrDownDelay);
                /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */               
                /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CLOCK_PRESCALER_MASK_U32, UnitConfigPtr->u32AdcPrescale);
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON)
#if (ADC_CTR1_AVAILABLE == STD_ON)
                ConvTime1 = UnitConfigPtr->ConvTimeNormal1;
#endif /* ADC_CTR1_AVAILABLE == STD_ON */
#if (ADC_CTR2_AVAILABLE == STD_ON)
                ConvTime2 = UnitConfigPtr->ConvTimeNormal2;
#endif /* ADC_CTR2_AVAILABLE == STD_ON */
                /**
                * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer
                * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
                */
                Adc_Adcdig_SetCtrRegisters(Unit, UnitConfigPtr->ConvTimeNormal, ConvTime1, ConvTime2);
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON) */
            }
            else
            {
                /**
                * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer.
                * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
                */
                REG_WRITE32(ADCDIG_PDEDR_REG_ADDR32(Unit),UnitConfigPtr->u8AdcAltPwrDownDelay);
                /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
                /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
                REG_RMW32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CLOCK_PRESCALER_MASK_U32, UnitConfigPtr->u32AdcAltPrescale);
#if (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON)
#if (ADC_CTR1_AVAILABLE == STD_ON)
                ConvTime1 = UnitConfigPtr->ConvTimeAlternate1;
#endif /* ADC_CTR1_AVAILABLE == STD_ON */
#if (ADC_CTR2_AVAILABLE == STD_ON)
                ConvTime2 = UnitConfigPtr->ConvTimeAlternate2;
#endif /* ADC_CTR2_AVAILABLE == STD_ON */
                /**
                * @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer
                * @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic
                * @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type.
                */
                Adc_Adcdig_SetCtrRegisters(Unit, UnitConfigPtr->ConvTimeAlternate, ConvTime1, ConvTime2);
#endif /* (ADC_SET_ADC_CONV_TIME_ONCE == STD_ON) */
            }
            /*Check Unit under power down mode before invoke SetClock function*/
            if(u32MsrValue != ADCDIG_POWERDOWN_STATUS_U32)
            {
                /* Exit from PowerDown Mode */
                if((Std_ReturnType)E_NOT_OK == Adc_Adcdig_WritePowerDownBit(Unit, (boolean)FALSE))
                {
                    /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
                    return (Std_ReturnType)E_NOT_OK;
                }    
            }
        }
    }
    return ((Std_ReturnType)E_OK);
}

#endif /* (ADC_DUAL_CLOCK_MODE == STD_ON) */

#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
 * @brief   Function to enable CTU control mode for an ADC unit.
 *
 * @details Enable CTU control mode for an ADC unit.
 *          This function to enable CTU control mode for Adc. When a unit works in CTU control mode,
 *          no other conversions shall run in parallel(Adc). The only conversions occurring shall be
 *          the ones defined in the CTU configuration.
 *
 * @param[in]  Unit      ADC Unit Id.
 *
 * @note    The function Service ID[hex]: 0x39.
 *
 * @api
 */
FUNC(void, ADC_CODE) Adc_Adcdig_EnableCtuControlMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Index;
    VAR(boolean, AUTOMATIC) bAlreadyCall = (boolean)FALSE;

    /* Enter ADC to CTU control mode, ADC must be switched to power down mode to modify this bit */
    (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CTU_TRIGGER_MODE_U32);
    /* Exit Power Down */
    (void)Adc_Adcdig_WritePowerDownBit(Unit, (boolean)FALSE);
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CTU_ENABLED_U32);

#if (ADC_BCTU_AVAILABLE == STD_ON)
    Adc_Bctu_au8ResultIndex[Unit] = 0U;
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */

    for (Index = 0U; Index < (Adc_HwUnitType)ADC_MAX_HW_UNITS; Index++)
    {
        if ((boolean)TRUE == Adc_aUnitStatus[Index].bCtuControlOngoing)
        {
            bAlreadyCall = (boolean)TRUE;
            break;
        }
    }
    /* Mark the unit as CTU control mode is ongoing */
    Adc_aUnitStatus[Unit].bCtuControlOngoing = (boolean)TRUE;

    if((boolean)FALSE == bAlreadyCall)
    {
#if (ADC_BCTU_AVAILABLE == STD_ON)
        /* Start BCTU control */
        Adc_Bctu_StartCtu();
#elif (ADC_CTUV2_AVAILABLE == STD_ON)
        /* Start CTU2 control */
        Adc_Ctu2_StartCtu();
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
    }
}

/**
 * @brief   Function to disable CTU control mode for an ADC unit.
 *
 * @details Disable CTU control mode for an ADC unit.
 *          This function to disable CTU control mode for Adc. The other Adc conversions can run in
 *          software trigger normal mode, software trigger injected mode or hardware trigger mode.
 *
 * @param[in]  Unit      ADC Unit Id.
 *
 * @note    The function Service ID[hex]: 0x4A.
 *
 * @api
 */
FUNC(void, ADC_CODE) Adc_Adcdig_DisableCtuControlMode
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Index;
    VAR(boolean, AUTOMATIC) bLastCall = (boolean)TRUE;

    /* Mark the unit as CTU control mode is not ongoing */
    Adc_aUnitStatus[Unit].bCtuControlOngoing = (boolean)FALSE;

#if (ADC_BCTU_AVAILABLE == STD_ON)
    Adc_Bctu_au8ResultIndex[Unit] = 0U;
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */

    for (Index = 0U; Index < (Adc_HwUnitType)ADC_MAX_HW_UNITS; Index++)
    {
        if ((boolean)TRUE == Adc_aUnitStatus[Index].bCtuControlOngoing)
        {
            bLastCall = (boolean)FALSE;
            break;
        }
    }

    if((boolean)TRUE == bLastCall)
    {
#if (ADC_BCTU_AVAILABLE == STD_ON)
        /* Stop BCTU control */
        Adc_Bctu_StopCtu();
#elif (ADC_CTUV2_AVAILABLE == STD_ON)
        /* Stop CTU2 control */
        Adc_Ctu2_StopCtu();
#endif /* (ADC_BCTU_AVAILABLE == STD_ON) */
    }

    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned long to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(ADCDIG_MCR_REG_ADDR32(Unit), ADCDIG_CTU_ENABLED_U32);
}
#endif /* ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

#if (defined(ADC_DMA_SUPPORTED) || (ADC_DEINIT_API == STD_ON))
/** @violates @ref Adc_Adcdig_c_REF_10 internal linkage or external linkage */
FUNC(void, ADC_CODE) Adc_Adcdig_ClearDmarRegisters
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
    /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(ADCDIG_DMAE_REG_ADDR32(Unit), ADCDIG_DMAE_RESET_VALUE_U32);
    
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_DmarPresent[Unit][ADC_DMAR0_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_DMAR0_REG_ADDR32(Unit),ADCDIG_DMAR_RESET_VALUE_U32);
    }
#if (ADC_DMAR1_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_DmarPresent[Unit][ADC_DMAR1_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_DMAR1_REG_ADDR32(Unit),ADCDIG_DMAR_RESET_VALUE_U32);
    }
#endif /* (ADC_DMAR1_AVAILABLE == STD_ON) */

#if (ADC_DMAR2_AVAILABLE == STD_ON)
    if ((uint8)STD_ON == Adc_RegistersAvailable.au8Adc_DmarPresent[Unit][ADC_DMAR2_INDEX])
    {
        /** @violates @ref Adc_Adcdig_c_REF_9 cast from unsigned int to pointer */
        /** @violates @ref Adc_Adcdig_c_REF_3 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(ADCDIG_DMAR2_REG_ADDR32(Unit),ADCDIG_DMAR_RESET_VALUE_U32);
    }
#endif /* (ADC_DMAR2_AVAILABLE == STD_ON) */

}
#endif /* (defined(ADC_DMA_SUPPORTED) || (ADC_DEINIT_API == STD_ON)) */

#if (ADC_POWER_STATE_SUPPORTED == STD_ON) || defined(__DOXYGEN__)
/**
* @brief          Set the desired power state.
* @details        This API changes power state of ADC module.
*
* @param[in]      Adc_ePowerState   The power state to set 
*                 
* @return         Std_ReturnType  Standard return type.
* @retval         E_OK:           Power Mode changed.
* @retval         E_NOT_OK:       Request rejected.
*
* @api
*
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Adcdig_SetPowerState
(
    VAR(Adc_PowerStateType, AUTOMATIC) Adc_ePowerState
)
{
    VAR(Adc_HwUnitType, AUTOMATIC) Index;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit;
    VAR(Std_ReturnType, AUTOMATIC) RetVal = (Std_ReturnType)E_OK;
     
    for (Index = 0U; Index < Adc_pCfgPtr->Misc.Adc_MaxHwCfg; Index++)
    {
        /** @violates @ref Adc_Adcdig_c_REF_8 Array indexing shall be the only allowed form of pointer arithmetic */
        Unit = (Adc_HwUnitType)(Adc_pCfgPtr->pAdc[Index].AdcHardwareUnitId);
            
        if(ADC_FULL_POWER == Adc_ePowerState)
        {
            /* comes out from PowerDown */
            RetVal = Adc_Adcdig_WritePowerDownBit(Unit, (boolean)FALSE);
        }
        else if(ADC_LOW_POWER == Adc_ePowerState)
        {
            /* enter into power-down mode */
            RetVal = Adc_Adcdig_WritePowerDownBit(Unit, (boolean)TRUE);
        }
        else
        {
            /* Do nothing for misra */
        }

        if((Std_ReturnType)E_NOT_OK == RetVal)
        {
            /** @violates @ref Adc_Adcdig_c_REF_4 Return statement before end of function. */
            return RetVal;
        }
    }/* for (Index = 0U; Index < ... */

    return RetVal;
}
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

#define ADC_STOP_SEC_CODE
/** @violates @ref Adc_Adcdig_c_REF_1 Only preprocessor statements and comments before "#include" */
/** @violates @ref Adc_Adcdig_c_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
