/**
*   @file    Wdg_Swt.c
*
*   @version 1.0.0
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) functions
*   @details Contains functions for accessing SWT from the WDG driver perspective
*
*   @addtogroup  Wdg
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : Swt
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
* @section Wdg_Swt_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
*
* @section Wdg_Swt_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
* @section Wdg_Swt_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
* @section Wdg_Swt_c_REF_4
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
*          pointer to a function and a type other than an integral type. This violation is due to the
*          pointer arithmetic used to write/ read the data to/from the registers
* @section Wdg_Swt_c_REF_5
*          Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or
*          functions at file scope shall have internal linkage unless external linkage is required.
* @section Wdg_Swt_c_REF_6
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer
*          type and an integral type. This violation is due to the pointer arithmetic used to 
*          write/ read the data to/from the registers.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Wdg_Swt.c    
*/

#include "Wdg_IPW_Types.h"
#include "Wdg_Swt.h"
#include "Reg_eSys_Swt.h"
#include "Reg_eSys_Swt_defines.h"
#include "Mcal.h"
#include "StdRegMacros.h"
#include "SchM_Wdg.h"

/*==================================================================================================
*                                       SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Wdg_Swt.c
*/
#define WDG_SWT_VENDOR_ID_C                     43
/** @violates @ref Wdg_Swt_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define WDG_SWT_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Wdg_Swt_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define WDG_SWT_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Wdg_Swt_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define WDG_SWT_AR_RELEASE_REVISION_VERSION_C   2
#define WDG_SWT_SW_MAJOR_VERSION_C              1
#define WDG_SWT_SW_MINOR_VERSION_C              0
#define WDG_SWT_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Wdg_Swt header file are of the same vendor */
#if (WDG_SWT_VENDOR_ID_C != WDG_SWT_VENDOR_ID)
    #error "Wdg_Swt.c and Wdg_Swt.h have different vendor ids"
#endif
/* Check if current file and Wdg_Swt header file are of the same Autosar version */
#if ((WDG_SWT_AR_RELEASE_MAJOR_VERSION_C    != WDG_SWT_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_MINOR_VERSION_C    != WDG_SWT_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_REVISION_VERSION_C != WDG_SWT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt.c and Wdg_Swt.h are different"
#endif
/* Check if current file and SWT header file are of the same Software version */
#if ((WDG_SWT_SW_MAJOR_VERSION_C != WDG_SWT_SW_MAJOR_VERSION) || \
     (WDG_SWT_SW_MINOR_VERSION_C != WDG_SWT_SW_MINOR_VERSION) || \
     (WDG_SWT_SW_PATCH_VERSION_C != WDG_SWT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt.c and Wdg_Swt.h are different"
#endif

/* Check if current file and Wdg_Cfg header file are of the same vendor */
#if (WDG_SWT_VENDOR_ID_C != WDG_VENDOR_ID_CFG)
    #error "Wdg_Swt.c and Wdg_Cfg.h have different vendor ids"
#endif
/* Check if current file and Wdg_Swt header file are of the same Autosar version */
#if ((WDG_SWT_AR_RELEASE_MAJOR_VERSION_C    != WDG_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (WDG_SWT_AR_RELEASE_MINOR_VERSION_C    != WDG_AR_RELEASE_MINOR_VERSION_CFG) || \
     (WDG_SWT_AR_RELEASE_REVISION_VERSION_C != WDG_AR_RELEASE_REVISION_VERSION_CFG) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt.c and Wdg_Cfg.h are different"
#endif
/* Check if current file and SWT header file are of the same Software version */
#if ((WDG_SWT_SW_MAJOR_VERSION_C != WDG_SW_MAJOR_VERSION_CFG) || \
     (WDG_SWT_SW_MINOR_VERSION_C != WDG_SW_MINOR_VERSION_CFG) || \
     (WDG_SWT_SW_PATCH_VERSION_C != WDG_SW_PATCH_VERSION_CFG)    \
    )
    #error "Software Version Numbers of Wdg_Swt.c and Wdg_Cfg.h are different"
#endif

/* Check if current file and SWT register header file are of the same vendor */
#if (WDG_SWT_VENDOR_ID_C != REG_ESYS_SWT_VENDOR_ID)
    #error "Wdg_Swt.c and Reg_eSys_Swt.h have different vendor ids"
#endif

/* Check if source file and SWT register header file are of the same Autosar version */
#if ((WDG_SWT_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_SWT_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_SWT_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SWT_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt.c and Reg_eSys_Swt.h are different"
#endif

/* Check if source file and SWT register header file are of the same Software version */
#if ((WDG_SWT_SW_MAJOR_VERSION_C != REG_ESYS_SWT_SW_MAJOR_VERSION) || \
     (WDG_SWT_SW_MINOR_VERSION_C != REG_ESYS_SWT_SW_MINOR_VERSION) || \
     (WDG_SWT_SW_PATCH_VERSION_C != REG_ESYS_SWT_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt.c and Reg_eSys_Swt.h are different"
#endif

/* Check if current file and Reg_eSys_Swt_defines header file are of the same vendor */
#if (WDG_SWT_VENDOR_ID_C != REG_ESYS_SWT_DEFINES_VENDOR_ID)
    #error "Wdg_Swt.c and Reg_eSys_Swt_defines.h have different vendor ids"
#endif

/* Check if source file and Reg_eSys_Swt_defines header file are of the same Autosar version */
#if ((WDG_SWT_AR_RELEASE_MAJOR_VERSION_C    != REG_ESYS_SWT_DEFINES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_MINOR_VERSION_C    != REG_ESYS_SWT_DEFINES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_REVISION_VERSION_C != REG_ESYS_SWT_DEFINES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt.c and Reg_eSys_Swt_defines.h are different"
#endif

/* Check if source file and Reg_eSys_Swt_defines header file are of the same Software version */
#if ((WDG_SWT_SW_MAJOR_VERSION_C != REG_ESYS_SWT_DEFINES_SW_MAJOR_VERSION) || \
     (WDG_SWT_SW_MINOR_VERSION_C != REG_ESYS_SWT_DEFINES_SW_MINOR_VERSION) || \
     (WDG_SWT_SW_PATCH_VERSION_C != REG_ESYS_SWT_DEFINES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt.c and Reg_eSys_Swt_defines.h are different"
#endif

/* Check if current file and Wdg_IPW_Types header file are of the same vendor */
#if (WDG_SWT_VENDOR_ID_C != WDG_IPW_TYPES_VENDOR_ID)
    #error "Wdg_Swt.c and Wdg_IPW_Types.h have different vendor ids"
#endif

/* Check if source file and Wdg_IPW_Types header file are of the same Autosar version */
#if ((WDG_SWT_AR_RELEASE_MAJOR_VERSION_C    != WDG_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_MINOR_VERSION_C    != WDG_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (WDG_SWT_AR_RELEASE_REVISION_VERSION_C != WDG_IPW_TYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Wdg_Swt.c and Wdg_IPW_Types.h are different"
#endif

/* Check if source file and Wdg_IPW_Types header file are of the same Software version */
#if ((WDG_SWT_SW_MAJOR_VERSION_C != WDG_IPW_TYPES_SW_MAJOR_VERSION) || \
     (WDG_SWT_SW_MINOR_VERSION_C != WDG_IPW_TYPES_SW_MINOR_VERSION) || \
     (WDG_SWT_SW_PATCH_VERSION_C != WDG_IPW_TYPES_SW_PATCH_VERSION)    \
    )
    #error "Software Version Numbers of Wdg_Swt.c and Wdg_IPW_Types.h are different"
#endif

/* Check if current file and StdRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_SWT_AR_RELEASE_MAJOR_VERSION_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_SWT_AR_RELEASE_MINOR_VERSION_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_Swt.c and StdRegMacros.h are different"
    #endif
#endif

/* Check if current file and Mcal header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((WDG_SWT_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (WDG_SWT_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Wdg_Swt.c and Mcal.h are different"
    #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
/**
* @brief          Wdg_Swt_ServiceMode
* @details        Contains the information related to the service mode

*/
typedef enum
{
    SWT_FIXED_SERVICE_MODE = 0x00,  /**< @brief Fixed service sequence is used to trigger the wdg */
    SWT_KEYED_SERVICE_MODE = 0x01  /**< @brief Keyed service sequence is used to trigger the wdg */
}Wdg_Swt_ServiceModeType;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define WDG_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#ifdef WDG_KEYED_SERVICE_USED
    static VAR(Wdg_Swt_ServiceModeType, WDG_VAR) Wdg_Swt_aeCrtServiceMode[WDG_NO_OF_INSTANCES] = {SWT_FIXED_SERVICE_MODE};
#endif

#define WDG_STOP_SEC_VAR_INIT_UNSPECIFIED

/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define WDG_START_SEC_CONST_32
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"
/** @violates @ref Wdg_Swt_c_REF_5 Violates MISRA 2004 Required Rule 8.10 could be made static */
CONST(uint32, WDG_CONST) SWT_aBASE_ADDR32[WDG_NO_OF_INSTANCES] = 
{
#ifdef SWT_0_BASEADDR
    SWT_0_BASEADDR
#else
#ifdef SWT_BASEADDR
    SWT_BASEADDR
#else
    /*if instance number 0 is missing */
    ((uint32)0x00000000UL)
#endif
#endif
#ifdef SWT_1_BASEADDR
    ,SWT_1_BASEADDR
#else
    /*if instance number 1 is missing but it has instance number 2 3 and 4 */
    #if ((defined SWT_2_BASEADDR) || (defined SWT_3_BASEADDR) || (defined SWT_4_BASEADDR)) 
        ,((uint32)0x00000000UL)
    #endif
#endif
#ifdef SWT_2_BASEADDR
    ,SWT_2_BASEADDR
#else
    #if ((defined SWT_3_BASEADDR) || (defined SWT_4_BASEADDR)) 
        ,((uint32)0x00000000UL)
    #endif
#endif
#ifdef SWT_3_BASEADDR
    ,SWT_3_BASEADDR
#else
    #if (defined SWT_4_BASEADDR)
    ,((uint32)0x00000000UL)
    #endif
#endif
#ifdef SWT_4_BASEADDR
    ,SWT_4_BASEADDR
#endif
};

#define WDG_STOP_SEC_CONST_32
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"


#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"
/*==================================================================================================
*                                      LOCAL FUNCTIONS
==================================================================================================*/
#ifdef WDG_ROM
#define WDG_START_SEC_CODE
#else 
#define WDG_START_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
*   @brief   This function initializes the hardware of WDG module.
*   @details Sets up the values such as timeout value
*
*   @param[in]      Swt_pConfigPtr      Pointer to configuration set.
*   @param[in]      Wdg_Instance        Harwdware SWT instance.
* 
*   @return uint32      The value in ticks that need to be set up for the timer
*
*/
FUNC(uint32, WDG_CODE) Wdg_Swt_Init(P2CONST(Wdg_Swt_ConfigType, AUTOMATIC, WDG_APPL_CONST) Swt_pConfigPtr,
                                    CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                                   )
{
    SuspendAllInterrupts();
    /* Unlock the possible soft lock condition   */
    /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(SWT_SR_ADDR32(Wdg_Instance), SWT_UNLOCK_SEQ1_U32);
    /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(SWT_SR_ADDR32(Wdg_Instance), SWT_UNLOCK_SEQ2_U32);
    /* Disable watchdog */
    /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_BIT_CLEAR32(SWT_CR_ADDR32(Wdg_Instance), SWT_WDG_ENABLED_U32);
    ResumeAllInterrupts();
    /* Set Timer-out register */
    /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(SWT_TO_ADDR32(Wdg_Instance), Swt_pConfigPtr->Swt_u32Timeout);

    /* Set Window register */
    /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(SWT_WN_ADDR32(Wdg_Instance), Swt_pConfigPtr->Swt_u32Window);
    
    

#ifdef WDG_KEYED_SERVICE_USED
    if (SWT_KEYED_SERVICE_U32 == (Swt_pConfigPtr->Swt_u32Config & SWT_KEYED_SERVICE_U32))
    {
        /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
        REG_WRITE32(SWT_SK_ADDR32(Wdg_Instance), Swt_pConfigPtr->Swt_u32InitialKey);        
        Wdg_Swt_aeCrtServiceMode[Wdg_Instance] = SWT_KEYED_SERVICE_MODE;
    }
    else
    {
        Wdg_Swt_aeCrtServiceMode[Wdg_Instance] = SWT_FIXED_SERVICE_MODE;
    }
#endif
    SuspendAllInterrupts();
    /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
    REG_WRITE32(SWT_CR_ADDR32(Wdg_Instance),(Swt_pConfigPtr->Swt_u32Config));
    ResumeAllInterrupts();
    
    return (uint32)(Swt_pConfigPtr->Swt_u32Timeout - (Swt_pConfigPtr->Swt_u32Window>>1));
}

/**
*   @brief   This function triggers the watchdog hardware.
*   @details Writes the trigger sequence on the hardware
*
*   @param[in]      Wdg_Instance   Harwdware SWT instance.
* 
* 
*   @return void
*  
*   @pre The Wdg module's environment shall make sure that the Wdg module has
*      been initialized before the Wdg_Trigger routine is called (Req: WDG104)
* 
*/
FUNC(void, WDG_CODE) Wdg_Swt_Trigger(CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance)
{
#ifdef WDG_KEYED_SERVICE_USED
    if (SWT_KEYED_SERVICE_MODE == Wdg_Swt_aeCrtServiceMode[Wdg_Instance])
    {
        VAR(uint32, AUTOMATIC) u32KeyedValue;
        
        SuspendAllInterrupts();
         /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
         /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
        u32KeyedValue = (uint32) ((((17UL * REG_READ32(SWT_SK_ADDR32(Wdg_Instance)))) + 3UL) & 0x0000FFFFUL);
        /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
        REG_WRITE32(SWT_SR_ADDR32(Wdg_Instance), u32KeyedValue);
        u32KeyedValue = ((17UL * u32KeyedValue) + 3UL) & 0x0000FFFFUL;
        /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
        /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
        REG_WRITE32(SWT_SR_ADDR32(Wdg_Instance), u32KeyedValue);
        ResumeAllInterrupts();
    }
    else 
    {
        if (SWT_FIXED_SERVICE_MODE == Wdg_Swt_aeCrtServiceMode[Wdg_Instance])
        {
#endif
            SuspendAllInterrupts();
            /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
            REG_WRITE32(SWT_SR_ADDR32(Wdg_Instance), SWT_FIXED_SERVICE_SEQ1_U32);
            /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
            REG_WRITE32(SWT_SR_ADDR32(Wdg_Instance), SWT_FIXED_SERVICE_SEQ2_U32);
            ResumeAllInterrupts();
#ifdef WDG_KEYED_SERVICE_USED
        }
        else
        {
            /*do nothing */
        }
    }
#endif
}

/**
*   @brief   The function checks the consistence between the configuration and the hardware.
*   @details Verifies if the given configuration set is within hardware limits
* 
*   @param[in]          Swt_pConfigPtr      Pointer to configuration set.  
*   @param[in]          Wdg_Instance        Harwdware SWT instance.
*
*   @return             Std_ReturnType
*   @retval E_OK        The mode switch has been executed completely and successfully
*   @retval E_NOT_OK    The mode switch has encounter errors
*
*/
FUNC(Std_ReturnType, WDG_CODE)
     Wdg_Swt_CheckHwSettings(P2CONST(Wdg_Swt_ConfigType, AUTOMATIC, WDG_APPL_CONST) Swt_pConfigPtr,
                             CONST(Wdg_IPW_InstanceType, WDG_CONST) Wdg_Instance
                            )
{
    VAR(Std_ReturnType, AUTOMATIC) response = (Std_ReturnType)E_OK;
    
    /* Returns error if the configuration pointer is NULL*/
    if (NULL_PTR == Swt_pConfigPtr)
    {
        response = (Std_ReturnType)E_NOT_OK;
    }
    else
    {
        /* Returns error if the timeout value is grater that the minimum timeout value supported by hardware*/
        if (Swt_pConfigPtr->Swt_u32Timeout < SWT_MIN_VALUE_TIMEOUT_U32)
        {
            response = (Std_ReturnType)E_NOT_OK;
        }
        else
        {

            /* Returns error if the hardlock is setup on the hardware*/
            /* @violates @ref Wdg_Swt_c_REF_4 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
            /* @violates @ref Wdg_Swt_c_REF_6 Violates MISRA 2004 Rule 11.3, Cast from unsigned long to pointer.*/
            if (SWT_WDG_HARD_LOCK_U32 == (REG_READ32(SWT_CR_ADDR32(Wdg_Instance)) & SWT_WDG_HARD_LOCK_U32))
            {

                response = (Std_ReturnType)E_NOT_OK;
            }
            else
            {
                /*do nothing*/
            }
            /* Return error if the value of the window frame is grater that the timeout - no trigger can occur*/
            if (SWT_TRIGGER_MODE_WINDOW_U32 == (Swt_pConfigPtr->Swt_u32Config & SWT_TRIGGER_MODE_WINDOW_U32))
            {
                if (Swt_pConfigPtr->Swt_u32Timeout < Swt_pConfigPtr->Swt_u32Window)
                {
                    response = (Std_ReturnType)E_NOT_OK;
                }
            }
        }
    }
    return response;
}

#ifdef WDG_ROM
#define WDG_STOP_SEC_CODE
#else 
#define WDG_STOP_SEC_RAMCODE
#endif
/**
* @brief Include Memory mapping specification
* @violates @ref Wdg_Swt_c_REF_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Wdg_Swt_c_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
