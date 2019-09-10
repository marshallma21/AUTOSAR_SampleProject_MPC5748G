/**
*   @file    Mcu_MC_ME.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Mode Entry module functions implementation.
*   @details Specific functions for MC_ME configuration and control.
*            Part of the Magic Carpet hw IP.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : MC
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
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_MC_ME_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_MC_ME_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_MC_ME_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers. The defines
* are validated.
*
* @section Mcu_MC_ME_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_MC_ME_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_MC_ME_c_REF_6
* Violates MISRA 2004 Required Rule 19.5, Macros shall not be #define'd or #undef'd within a block
* These defines are used to increase code maintainability are are not used anywhere else.
*
* @section Mcu_MC_ME_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

#include "Mcu_MC_CGM.h"
#include "Mcu_MC_ME.h"

#ifdef MCU_ERROR_ISR_NOTIFICATION
#include "Mcu.h"
#endif /* MCU_ERROR_ISR_NOTIFICATION */

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_MC_ME_VENDOR_ID_C                       43
/** @violates @ref Mcu_MC_ME_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_MC_ME_AR_RELEASE_MAJOR_VERSION_C        4
/** @violates @ref Mcu_MC_ME_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_MC_ME_AR_RELEASE_MINOR_VERSION_C        2
/** @violates @ref Mcu_MC_ME_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_MC_ME_AR_RELEASE_REVISION_VERSION_C     2
#define MCU_MC_ME_SW_MAJOR_VERSION_C                1
#define MCU_MC_ME_SW_MINOR_VERSION_C                0
#define MCU_MC_ME_SW_PATCH_VERSION_C                0


/*==================================================================================================
                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcal header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME.c and Mcal.h are different"
#endif
#endif

/* Check if current file and Mcu_MC_CGM header file are of the same vendor */
#if (MCU_MC_ME_VENDOR_ID_C != MCU_MC_CGM_VENDOR_ID)
    #error "Mcu_MC_ME.c and Mcu_MC_CGM.h have different vendor ids"
#endif
/* Check if current file and Mcu_MC_CGM header file are of the same Autosar version */
#if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_CGM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_REVISION_VERSION_C != MCU_MC_CGM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME.c and Mcu_MC_CGM.h are different"
#endif
/* Check if current file and Mcu_MC_CGM header file are of the same Software version */
#if ((MCU_MC_ME_SW_MAJOR_VERSION_C != MCU_MC_CGM_SW_MAJOR_VERSION) || \
     (MCU_MC_ME_SW_MINOR_VERSION_C != MCU_MC_CGM_SW_MINOR_VERSION) || \
     (MCU_MC_ME_SW_PATCH_VERSION_C != MCU_MC_CGM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_ME.c and Mcu_MC_CGM.h are different"
#endif

/* Check if current file and Mcu_ME_ME header file are of the same vendor */
#if (MCU_MC_ME_VENDOR_ID_C != MCU_MC_ME_VENDOR_ID)
    #error "Mcu_MC_ME.c and Mcu_MC_ME.h have different vendor ids"
#endif
/* Check if current file and Mcu_ME_ME header file are of the same Autosar version */
#if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_ME_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_ME_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_REVISION_VERSION_C != MCU_MC_ME_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME.c and Mcu_MC_ME.h are different"
#endif
/* Check if current file and Mcu_ME_ME header file are of the same Software version */
#if ((MCU_MC_ME_SW_MAJOR_VERSION_C != MCU_MC_ME_SW_MAJOR_VERSION) || \
     (MCU_MC_ME_SW_MINOR_VERSION_C != MCU_MC_ME_SW_MINOR_VERSION) || \
     (MCU_MC_ME_SW_PATCH_VERSION_C != MCU_MC_ME_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_ME.c and Mcu_MC_ME.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME.c and Det.h are different"
#endif
#endif
#endif

/* Check if current file and DEM header file are of the same version */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME.c and Dem.h are different"
#endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_ME_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_ME.c and SilRegMacros.h are different"
#endif
#endif

#ifdef MCU_ERROR_ISR_NOTIFICATION
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_MC_ME_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu_MC_ME.c and Mcu.h have different vendor ids"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_ME_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_MC_ME_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
        (MCU_MC_ME_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Mcu_MC_ME.c and Mcu.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_MC_ME_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_MC_ME_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_MC_ME_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu_MC_ME.c and Mcu.h are different"
#endif
#endif /* MCU_ERROR_ISR_NOTIFICATION */

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_MC_ME_c_REF_1 Repeated include file
* @violates @ref Mcu_MC_ME_c_REF_2 only preprocessor statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#if ( (MCU_ENTER_LOW_POWER_MODE == STD_ON) && (MCU_FAST_MODE_CONFIG == STD_ON) )
static FUNC( void, MCU_CODE) Mcu_MC_ME_FastModeConfig ( VAR(uint32, AUTOMATIC) u32FastWakeupParams);
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */

#if ( MCU_CONFIGURE_CADDRN == STD_ON )
static FUNC( void, MCU_CODE) Mcu_MC_ME_ConfigureCoreAddrRegister(P2CONST( Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pModeConfigPtr);
#endif /* MCU_CONFIGURE_CADDRN == STD_ON */

#if (IPV_MC == IPV_MC_05_00_00_10)
static FUNC( Std_ReturnType, MCU_CODE) Mcu_MC_ME_CheckResetOnModeChange(VAR( void, AUTOMATIC));
#endif

#if (MCU_INIT_CLOCK == STD_ON)
static FUNC( void, MCU_CODE) Mcu_MC_ME_BlindApplyMode( VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode);
#endif /*(MCU_INIT_CLOCK == STD_ON)*/

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_MC_ME_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_MC_ME_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_MC_ME_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_MC_ME_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
*/
FUNC( void, MCU_CODE) Mcu_MC_ME_SetUserAccessAllowed(void)
{
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    SET_USER_ACCESS_ALLOWED(MC_ME_BASEADDR);
}
#endif
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||\
     (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_10) ||\
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_06_00_00_10) ||\
     (IPV_MC == IPV_MC_04_04_01_00)\
    )
/**
* @brief            This function writes the MC_CCTLn registers
* @details
*                   Called by:
*                       - Mcu_Ipw_Init() from IPW.
*
* @param[in]        MC_ME_pConfigPtr   Pointer to MC_ME configuration structure.
*
* @return           void
*
*/
/** @violates @ref Mcu_MC_ME_c_REF_5 Global declaration of function. */
FUNC( void, MCU_CODE) Mcu_MC_ME_InitCCTL(P2CONST( Mcu_MC_ME_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_ME_pConfigPtr)
{
    VAR(uint8, AUTOMATIC) u8CoreIdx;
    
    /* set the boot address here */
    for (u8CoreIdx = 0x00U; u8CoreIdx < MC_ME_pConfigPtr->u8NumberOfCoreAddrRegs; u8CoreIdx++)
    {
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer. */
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32 \
        ( \
            (*MC_ME_pConfigPtr->apCoreAddress)[u8CoreIdx].u32RegisterAddr, \
            (*MC_ME_pConfigPtr->apCoreAddress)[u8CoreIdx].u32RegisterMask, \
            (*MC_ME_pConfigPtr->apCoreAddress)[u8CoreIdx].u32RegisterData  \
        );
    }
    
    /* enable multi-core */
    for (u8CoreIdx = 0x00U; u8CoreIdx < MC_ME_pConfigPtr->u8NumberOfCoreCtrlRegs; u8CoreIdx++)
    {
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK16 \
        ( \
            MC_ME_BASEADDR, \
            (*MC_ME_pConfigPtr->apCoreControl)[u8CoreIdx].u32RegisterAddr, \
            (*MC_ME_pConfigPtr->apCoreControl)[u8CoreIdx].u16RegisterData \
        );
    }
}
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || 
           (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) ||
           (IPV_MC == IPV_MC_04_06_05_00) || (IPV_MC == IPV_MC_05_00_00_10) ||
           (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_06_00_00_10) ||
           (IPV_MC == IPV_MC_04_04_01_00)) */


/**
* @brief            This function initializes the ME configuration registers.
* @details          This function initializes the ME running and non-running configuration
*                   registers and ME interrupt masks. Any modifications to the ME_RUN_PC0_7,
*                   ME_LP_PC0_7 registers do not affect the clock gating behavior until a new mode
*                   transition request is generated.
*                   Each peripheral clock source can be switched on or off independently when it is
*                   not used, to optimize power consumption. The ME module manages the clock gating
*                   of each peripheral, defining peripherals state (active/frozen) in each mode.
*                   Called by:
*                       - Mcu_Ipw_Init() from IPW.
*
* @param[in]        MC_ME_pConfigPtr   Pointer to MC_ME configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_MC_ME_ModesPeriphInit(P2CONST( Mcu_MC_ME_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_ME_pConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Counter;

    /* ME_ME: This register allows a way to disable the device modes which are not required for a given device. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer */
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_ME_ADDR32, (uint32)(MC_ME_pConfigPtr->u32EnabledModes));

    Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE );

    /* These registers configure eight different types of peripheral behaviour during run modes. */
    /* Configure peripheral activation during RUN0 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN_PC0_ADDR32, MC_ME_pConfigPtr->u32RunConfig0);
    /* Configure peripheral activation during RUN1 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN_PC1_ADDR32, MC_ME_pConfigPtr->u32RunConfig1);
    /* Configure peripheral activation during RUN2 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN_PC2_ADDR32, MC_ME_pConfigPtr->u32RunConfig2);
    /* Configure peripheral activation during RUN3 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN_PC3_ADDR32, MC_ME_pConfigPtr->u32RunConfig3);
    /* Configure peripheral activation during RUN4 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN_PC4_ADDR32, MC_ME_pConfigPtr->u32RunConfig4);
    /* Configure peripheral activation during RUN5 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN_PC5_ADDR32, MC_ME_pConfigPtr->u32RunConfig5);
    /* Configure peripheral activation during RUN6 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN_PC6_ADDR32, MC_ME_pConfigPtr->u32RunConfig6);
    /* Configure peripheral activation during RUN7 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN_PC7_ADDR32, MC_ME_pConfigPtr->u32RunConfig7);

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* no low power modes on this version */
#else
    /* These registers configure eight different types of peripheral behaviour during non-run modes. */
    /* Configure peripheral activation during LOW POWER0 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_LP_PC0_ADDR32, MC_ME_pConfigPtr->u32LowPwrConfig0);
    /* Configure peripheral activation during LOW POWER1 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_LP_PC1_ADDR32, MC_ME_pConfigPtr->u32LowPwrConfig1);
    /* Configure peripheral activation during LOW POWER2 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_LP_PC2_ADDR32, MC_ME_pConfigPtr->u32LowPwrConfig2);
    /* Configure peripheral activation during LOW POWER3 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_LP_PC3_ADDR32, MC_ME_pConfigPtr->u32LowPwrConfig3);
    /* Configure peripheral activation during LOW POWER4 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_LP_PC4_ADDR32, MC_ME_pConfigPtr->u32LowPwrConfig4);
    /* Configure peripheral activation during LOW POWER5 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_LP_PC5_ADDR32, MC_ME_pConfigPtr->u32LowPwrConfig5);
    /* Configure peripheral activation during LOW POWER6 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_LP_PC6_ADDR32, MC_ME_pConfigPtr->u32LowPwrConfig6);
    /* Configure peripheral activation during LOW POWER7 mode. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_LP_PC7_ADDR32, MC_ME_pConfigPtr->u32LowPwrConfig7);
#endif

    /* PCTLn registers */
    for(u32Counter = (uint32)0x00U; u32Counter < (uint32)(MC_ME_pConfigPtr->u8NumberOfPctlRegisters) ; u32Counter++)
    {
#if (IPV_MC == IPV_MC_04_06_01_00)
#ifdef ERR_IPV_SIUL2_0001
#if (STD_ON == ERR_IPV_SIUL2_0001)
        /* if the errata is ON the PCTL15 register must be written */
#else
        if (MC_ME_PCTL15_ADDR32 != (*MC_ME_pConfigPtr->apPctControl)[u32Counter].u32RegisterAddr)
        {
#endif
#else
        if (MC_ME_PCTL15_ADDR32 != (*MC_ME_pConfigPtr->apPctControl)[u32Counter].u32RegisterAddr)
        {
#endif
#endif
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion from pointer to integer */
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE8 \
            ( \
                (*MC_ME_pConfigPtr->apPctControl)[u32Counter].u32RegisterAddr, \
                (*MC_ME_pConfigPtr->apPctControl)[u32Counter].u8RegisterData \
            );
#if (IPV_MC == IPV_MC_04_06_01_00)
#ifdef ERR_IPV_SIUL2_0001       
#if (STD_ON == ERR_IPV_SIUL2_0001)
        /* if the errata is ON the PCTL15 register must be written */
#else
        }
#endif
#else
        }
#endif
#endif
    }

    /* Make a transition from current mode to the same mode.
       After modifying any of the ME_RUN_PC0_7, ME_LP_PC0_7 and ME_PCTLn registers,
       software must request a mode change and wait for the mode change to be completed.
       When first parameter is MCU_SET_CURRENT_MODE it means that MODEx->MODEx
       (Ex: RUN0->RUN0, DRUN->DRUN, etc). */
    Mcu_MC_ME_ApplyMode(MCU_CURRENT_MODE);

    /* clear already set ISR flags */
    /* during the set-up phase, some ISR's might trigger because one or more peripheral might be
    enabled */
    /* while their clock sources are still disabled */
    /** @violates @ref Mcu_MC_ME_c_REF_4 conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_IS_ADDR32, MC_ME_IS_I_CLEAR_MASK32);

    /* Enable/Disable ISRs for MC_ME. */
#ifdef ERR_IPV_MC_0037
#if (STD_ON == ERR_IPV_MC_0037)
    /* if this errata is defined, mask out ICONF_CU source */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_IM_ADDR32, MC_ME_pConfigPtr->u32IsrMode & (~MC_ME_IM_ICONF_CU_MASK32));
#else
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_IM_ADDR32, MC_ME_pConfigPtr->u32IsrMode);
#endif /* ERR_IPV_MC_0037 */
#else
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_IM_ADDR32, MC_ME_pConfigPtr->u32IsrMode);
#endif /* ERR_IPV_MC_0037 */
}


#if ((MCU_ENTER_LOW_POWER_MODE == STD_ON) && (MCU_FAST_MODE_CONFIG == STD_ON))
/**
* @brief            This function initializes the current running mode for fast wakeup concept.
* @details          The user can modify the mode configuration registers because the updates will
*                   not be taken into account if ME_MCTL[TARGET_MODE] is not programmed.
*                   On wakeup the ME_MCTL[TARGET_MODE] is managed by hardware and load the
*                   configuration that is now written in ME_<mode>_MC register.
*                   This function initializes the one of RUN0/RUN1/RUN2/RUN3 modes.
*                   Called by:
*                       - MC_ME_ModeConfig() from this file.
*
* @param[in]        u32FastWakeupParams   Configuration mode after wakeup.
*
* @return           void
*
*/
static FUNC(void, MCU_CODE) Mcu_MC_ME_FastModeConfig (VAR( uint32, AUTOMATIC) u32FastWakeupParams)
{
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode = MCU_CURRENT_MODE;
#ifdef MCU_XOSC_MCB_SIN_END_BYP_AVAILABLE
    VAR (uint32, AUTOMATIC) u32XoscConfig;
#endif

    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    ePowerMode = (Mcu_PowerModeType)(((uint32)REG_READ32(MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_CURRENT_MODE_MASK32) >> MC_ME_MODE_MC_PWRLVL_SHIFT32);
    
#ifdef MCU_XOSC_MCB_SIN_END_BYP_AVAILABLE
    /* get MC_ME_GS and mask agains what i need */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32XoscConfig = REG_READ32(MC_ME_GS_ADDR32);
    u32XoscConfig &= MC_ME_GS_S_XOSC_MASK32;
    u32FastWakeupParams |= u32XoscConfig;
#endif

    /* Any modification of the mode configuration register of the currently selected mode will not
    be taken into account immediately but on the next request to enter this mode. While exiting
    from the HALT0 and STOP0 modes on hardware exit events, these are updated with the appropriate
    RUN0_3 mode value. */
    switch (ePowerMode)
    {
        case (MCU_RUN0_MODE):
        {
            /* Set the new configuration for RUN0 - to be used after wakeup.
            System clock source will not be changed. */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN0_MC_ADDR32, (uint32)u32FastWakeupParams);
            break;
        }
        case (MCU_RUN1_MODE):
        {
            /* Set the new configuration for RUN1 - to be used after wakeup. System clock source
            will not be changed. */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN1_MC_ADDR32, (uint32)u32FastWakeupParams);
            break;
        }
        case (MCU_RUN2_MODE):
        {
            /* Set the new configuration for RUN2 - to be used after wakeup. System clock source
            will not be changed. */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN2_MC_ADDR32, (uint32)u32FastWakeupParams);
            break;
        }
        case (MCU_RUN3_MODE):
        {
            /* Set the new configuration for RUN3 - to be used after wakeup. System clock source
            will not be changed. */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN3_MC_ADDR32, (uint32)u32FastWakeupParams);
            break;

        }
        default:
        {
            /* To HALT/STOP/STBY only from RUN0/RUN1/RUN2/RUN3 is permitted to switch.
               Default case - should never enter here. */
            break;
        }
    }
}
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function update the enabled clock sources without changing the .
* @details          This function will write only the SDPLLON, PLL0ON, PLL1ON, XOSCON field from
*                   ME_mode_MC registers. It will always set the IRCON bit to 1. It disables ERROR
*                   IRQ's during it's mode transition and will not wait for the transition to
*                   properly finish
*                   Called by:
*                       - Mcu_Ipw_InitClock() from IPW.
*
* @param[in]        u32EnabledClocks   Enabled clock selection.
*
* @return           void
*
*/
/** @violates @ref Mcu_MC_ME_c_REF_5 Global declaration of function. */
FUNC(void, MCU_CODE) Mcu_MC_ME_BlindEnabledClockUpdate(VAR(uint32, AUTOMATIC) u32EnabledClocks)
{
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode = MCU_CURRENT_MODE;
    VAR( uint32, AUTOMATIC) u32CurrentModeConfig ;

    /* u32SystemClk parameter should be obtained from the configuration.
    It also must have encoded the other bits necessary to be set belong System clock selection. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    ePowerMode = (Mcu_PowerModeType)(((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_CURRENT_MODE_MASK32) >> (uint32)28U);

    /* Only these power modes support system clock change. */
    switch ( ePowerMode)
    {
        case (MCU_RUN0_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_RUN0_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)( u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_RUN0_3_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN0_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_BlindApplyMode( MCU_CURRENT_MODE);

            break;
        }
        case (MCU_RUN1_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_RUN1_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)( MC_ME_ENABLED_CLOCKS_MASK32)));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_RUN0_3_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN1_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_BlindApplyMode( MCU_CURRENT_MODE);

            break;
        }
        case (MCU_RUN2_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32( MC_ME_RUN2_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)( ~ ((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)( u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_RUN0_3_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN2_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_BlindApplyMode( MCU_CURRENT_MODE);

            break;
        }
        case (MCU_RUN3_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32( MC_ME_RUN3_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)( ~ ((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_RUN0_3_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN3_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_BlindApplyMode( MCU_CURRENT_MODE);

            break;
        }
        case (MCU_DRUN_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32( MC_ME_DRUN_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)( ~ ((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_DRUN_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_DRUN_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_BlindApplyMode(MCU_CURRENT_MODE);

            break;
        }
        case (MCU_TEST_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_TEST_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)( MC_ME_ENABLED_CLOCKS_MASK32)));
            u32CurrentModeConfig |= (uint32)((uint32)( u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_TEST_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_TEST_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_BlindApplyMode( MCU_CURRENT_MODE);

            break;
        }
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
        case (MCU_HALT0_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32( MC_ME_HALT0_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)( ~ ((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_HALT0_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_HALT0_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_BlindApplyMode( MCU_CURRENT_MODE);

            break;
        }
#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
        case (MCU_STBY0_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_STBY0_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_STBY0_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_STBY0_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_BlindApplyMode( MCU_CURRENT_MODE);

            break;
        }
#endif
        case (MCU_STOP0_MODE):
        {
            /* This power mode doesn't support system clock change - only 16MHz internal RC
            oscillator (set default by hardware). */
            break;
        }

#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */

        case (MCU_RESET_MODE):
        case (MCU_DEST_RESET_MODE):
        case (MCU_CURRENT_MODE):
        {
            /* This power mode doesn't support system clock change - only 16MHz internal RC
            oscillator (set default by hardware). */
            break;

        }
        default:
        {
            /* Default case - should never enter here. */
            break;
        }
    }
}



/**
* @brief            This function update the enabled clock sources without changing the system
*                   clock.
* @details          This function will write only the SDPLLON, PLL0ON, PLL1ON, XOSCON field from
*                   ME_mode_MC registers. It will always set the IRCON bit to 1. If the user tries
*                   to force an invalid configuration the mode entry will fail with a invalid Mode
*                   configuration interrupt and a time out.
*                   Called by:
*                       - Mcu_Ipw_InitClock() from IPW.
*
* @param[in]        u32EnabledClocks   Enabled clock selection.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_MC_ME_EnabledClkUpdate( VAR( uint32, AUTOMATIC ) u32EnabledClocks)
{
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode = MCU_CURRENT_MODE;
    VAR( uint32, AUTOMATIC) u32CurrentModeConfig ;

    /* u32SystemClk parameter should be obtained from the configuration.
    It also must have encoded the other bits necessary to be set belong System clock selection. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    ePowerMode = (Mcu_PowerModeType)(((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_CURRENT_MODE_MASK32) >> (uint32)28U);

    /* Only these power modes support system clock change. */
    switch(ePowerMode)
    {
        case (MCU_RUN0_MODE):
        {
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32( MC_ME_RUN0_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)( u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_RUN0_3_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN0_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);

            break;
        }

        case (MCU_RUN1_MODE):

            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_RUN1_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)( MC_ME_ENABLED_CLOCKS_MASK32)));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_RUN0_3_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer */
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN1_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);

            break;

        case (MCU_RUN2_MODE):

            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer */
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_RUN2_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)(MC_ME_ENABLED_CLOCKS_MASK32)));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_RUN0_3_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN2_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);

            break;

        case (MCU_RUN3_MODE):

            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32( MC_ME_RUN3_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)( ~ ((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)( u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_RUN0_3_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_RUN3_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);

            break;

        case (MCU_DRUN_MODE):

            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_DRUN_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)(MC_ME_ENABLED_CLOCKS_MASK32)));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_DRUN_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_DRUN_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_ApplyMode(MCU_CURRENT_MODE);

            break;

        case (MCU_TEST_MODE):

            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_TEST_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)(MC_ME_ENABLED_CLOCKS_MASK32)));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_TEST_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_TEST_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);

            break;

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
        case (MCU_HALT0_MODE):

            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32(MC_ME_HALT0_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)(~((uint32)(MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_HALT0_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_HALT0_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);

            break;

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
        case (MCU_STBY0_MODE):

            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            u32CurrentModeConfig = REG_READ32( MC_ME_STBY0_MC_ADDR32);
            u32CurrentModeConfig &= (uint32)( ~ ((uint32)( MC_ME_ENABLED_CLOCKS_MASK32 )));
            u32CurrentModeConfig |= (uint32)((uint32)(u32EnabledClocks & MC_ME_ENABLED_CLOCKS_MASK32) | MC_ME_STBY0_MC_RESBITS_MASK32);

            /* Update the new clock settings in current running mode. */
            /* IRCOSC is always ON */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE_LOCK32( MC_ME_BASEADDR, MC_ME_STBY0_MC_ADDR32, (uint32)u32CurrentModeConfig);

            Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);

            break;
#endif
        case (MCU_STOP0_MODE):
            /* This power mode doesn't support system clock change - only 16MHz internal RC
            oscillator (set default by hardware). */
            break;

#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */

        case (MCU_RESET_MODE):
        case (MCU_DEST_RESET_MODE):
        case (MCU_CURRENT_MODE):
            /* This power mode doesn't support system clock change - only 16MHz internal RC
            oscillator (set default by hardware). */
            break;

        default:
            /* Default case - should never enter here. */
            break;
    }
}


#if (IPV_MC == IPV_MC_06_00_00_10)
/**
* @brief            This function updates the secondary system clock selection for a new clock configuration.
* @details          This function is not responsible for setting other bits from ME_mode_SEC_CC_I
*                   register. If a system clock is selected with a clock source that is not enabled
*                   in the corresponding ME_mode_MC register, then an invalid Mode configuration
*                   interrupt will be activated.
*                   This function sets the ME_mode_SEC_CC_I[SYSCLK3], ME_mode_SEC_CC_I[SYSCLK2] and 
*                   ME_mode_SEC_CC_I[SYSCLK1] fields in case the fields need to be updated for a new clock configuration.
*                   Called by:
*                       - Mcu_Ipw_InitClock() from IPW.
*
* @param[in]        u32SecSysClkValue   Secondary system clock value.
*                   u32SecSysClkMask    Secondary system clock mask.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_MC_ME_SecondarySystemClkUpdate(VAR(uint32, AUTOMATIC) u32SecSysClkValue, VAR(uint32, AUTOMATIC) u32SecSysClkMask)
{
    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode = MCU_CURRENT_MODE;

    /* u32SecSysClkValue parameter should be obtained from the configuration.
    It also must have encoded the other bits necessary to be set belong System clock selection. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    ePowerMode = (Mcu_PowerModeType)(((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_CURRENT_MODE_MASK32) >> (uint32)28U);
    
    /* Only these power modes support system clock change. */
    switch ( ePowerMode)
    {
        case (MCU_RUN0_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if (((uint32)REG_READ32(MC_ME_RUN0_SEC_CC_I_ADDR32) & (uint32)(u32SecSysClkMask)
                ) != (uint32)u32SecSysClkValue
               )
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32(MC_ME_RUN0_SEC_CC_I_ADDR32, u32SecSysClkMask, u32SecSysClkValue);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_RUN1_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if (((uint32)REG_READ32(MC_ME_RUN1_SEC_CC_I_ADDR32) & (uint32)(u32SecSysClkMask)
                ) != (uint32)u32SecSysClkValue
               )
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_RUN1_SEC_CC_I_ADDR32, u32SecSysClkMask, u32SecSysClkValue);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_RUN2_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if (((uint32)REG_READ32(MC_ME_RUN2_SEC_CC_I_ADDR32) & (uint32)(u32SecSysClkMask)
                ) != (uint32)u32SecSysClkValue
               )
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_RUN2_SEC_CC_I_ADDR32, u32SecSysClkMask, u32SecSysClkValue);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_RUN3_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if (((uint32)REG_READ32(MC_ME_RUN3_SEC_CC_I_ADDR32) & (uint32)(u32SecSysClkMask)
                ) != (uint32)u32SecSysClkValue
               )
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_RUN3_SEC_CC_I_ADDR32, u32SecSysClkMask, u32SecSysClkValue);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_DRUN_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if (((uint32)REG_READ32(MC_ME_DRUN_SEC_CC_I_ADDR32) & (uint32)(u32SecSysClkMask)
                ) != (uint32)u32SecSysClkValue
               )
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_DRUN_SEC_CC_I_ADDR32, u32SecSysClkMask, u32SecSysClkValue);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_TEST_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if (((uint32)REG_READ32(MC_ME_TEST_SEC_CC_I_ADDR32) & (uint32)(u32SecSysClkMask)
                ) != (uint32)u32SecSysClkValue
               )
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_TEST_SEC_CC_I_ADDR32, u32SecSysClkMask, u32SecSysClkValue);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }
            break;

        case (MCU_RESET_MODE):
        case (MCU_DEST_RESET_MODE):
        case (MCU_CURRENT_MODE):
            /* This power mode doesn't support system clock change - only 16MHz internal RC
            oscillator (set default by hardware). */
            break;

        default:
            /* Default case - should never enter here. */
            break;
    }
}
#endif

/**
* @brief            This function update the system clock selection for a new clock configuration.
* @details          This function is not responsible for setting other bits from ME_mode_MC
*                   register. If a system clock is selected with a clock source that is not enabled
*                   in the corresponding ME_mode_MC register, then an invalid Mode configuration
*                   interrupt will be activated.
*                   This function set the ME_mode_MC[SYSCLK] field register in case need to be
*                   updated for a new clock configuration set.
*                   Called by:
*                       - Mcu_Ipw_InitClock() from IPW.
*
* @param[in]        u32SystemClk   System clock selection.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_MC_ME_SystemClkUpdate(VAR(uint32, AUTOMATIC) u32SystemClk)
{

    /* Contains the code of the Power Mode (based PowerModeType enumeration). */
    VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode = MCU_CURRENT_MODE;

    /* u32SystemClk parameter should be obtained from the configuration.
    It also must have encoded the other bits necessary to be set belong System clock selection. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    ePowerMode = (Mcu_PowerModeType)(((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_CURRENT_MODE_MASK32) >> (uint32)28U);

    /* Only these power modes support system clock change. */
    switch ( ePowerMode)
    {
        case (MCU_RUN0_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if (((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_SYSCLK_MASK32) != (uint32)u32SystemClk)
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_RUN0_MC_ADDR32, MC_ME_MODE_MC_SYSCLK_MASK32, u32SystemClk);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_RUN1_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if ( ((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_SYSCLK_MASK32) != (uint32)u32SystemClk)
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_RUN1_MC_ADDR32, MC_ME_MODE_MC_SYSCLK_MASK32, u32SystemClk);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_RUN2_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if ( ((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_SYSCLK_MASK32) != (uint32)u32SystemClk)
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_RUN2_MC_ADDR32, MC_ME_MODE_MC_SYSCLK_MASK32, u32SystemClk);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_RUN3_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if ( ((uint32)REG_READ32(MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_SYSCLK_MASK32) != (uint32)u32SystemClk)
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_RUN3_MC_ADDR32, MC_ME_MODE_MC_SYSCLK_MASK32, u32SystemClk);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_DRUN_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if ( ((uint32)REG_READ32(MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_SYSCLK_MASK32) != (uint32)u32SystemClk)
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_DRUN_MC_ADDR32, MC_ME_MODE_MC_SYSCLK_MASK32, u32SystemClk);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;

        case (MCU_TEST_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if ( ((uint32)REG_READ32(MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_SYSCLK_MASK32) != (uint32)u32SystemClk)
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_TEST_MC_ADDR32, MC_ME_MODE_MC_SYSCLK_MASK32, u32SystemClk);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }
            break;

#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
        case (MCU_HALT0_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if ( ((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_SYSCLK_MASK32) != (uint32)u32SystemClk)
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_HALT0_MC_ADDR32, MC_ME_MODE_MC_SYSCLK_MASK32, u32SystemClk);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }
            break;

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
        case (MCU_STBY0_MODE):
            /* Check if the system clock need to be changed (because of new source clock value). */
            /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
            if ( ((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_SYSCLK_MASK32) != (uint32)u32SystemClk)
            {
                /* Update the new clock settings in current running mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_STBY0_MC_ADDR32, MC_ME_MODE_MC_SYSCLK_MASK32, u32SystemClk);

                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
            }

            break;
#endif
        case (MCU_STOP0_MODE):
            /* This power mode doesn't support system clock change - only 16MHz internal RC
            oscillator (set default by hardware). */
            break;

#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */

        case (MCU_RESET_MODE):
        case (MCU_DEST_RESET_MODE):
        case (MCU_CURRENT_MODE):
            /* This power mode doesn't support system clock change - only 16MHz internal RC
            oscillator (set default by hardware). */
            break;

        default:
            /* Default case - should never enter here. */
            break;
    }
}

#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function activate the transition to a new MCU mode.
* @details          This function set the ME_MCTL register to load the mode configuration from one
*                   of the MC_<mode>_ME registers. It will not wait for the actual mode switch to
*                   finish and will not give any error code. It's used fore some clock tree
*                   configurations by Mcu_MC_ME_BlindEnabledClockUpdate. It's used only inside
*                   MC_ME.c -> not exported
*
* @param[in]        ePowerMode   Code of the MCU mode that is mapped to ME_MCTL register.
*
* @return           void
*
*/
static FUNC( void, MCU_CODE) Mcu_MC_ME_BlindApplyMode( VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode)
{
    /* i need to disable error IRQ's for this step - I don't want to see them */
    VAR( uint32, AUTOMATIC ) u32EnabledIRQs;

    /* Configuration register value calculated based input parameter. */
    VAR( uint32, AUTOMATIC) u32ModeConfig = 0U;

    /* get enabled irq's from MC_ME_IM */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32EnabledIRQs = REG_READ32( MC_ME_IM_ADDR32) ;

    /* disable all IRQ's */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IM_ADDR32, MC_ME_IM_RESBITS_MASK32 );

    /* This if-branch = true can be used only for re-apply some new clock/mode settings of the same
    mode. */
    if ( MCU_CURRENT_MODE == ePowerMode)
    {
        /* Any modification of the mode configuration register of the currently selected mode will
        not be taken into account immediately but on the next request to enter this mode. This means
        that transition requests such as RUN0_3->RUN0_3, DRUN->DRUN, SAFE->SAFE and TEST->TEST are
        considered valid mode transition requests. */
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        u32ModeConfig = (uint32)REG_READ32( MC_ME_GS_ADDR32) & MC_ME_GS_S_CURRENT_MODE_MASK32;
    }
    else
    {
        u32ModeConfig = (uint32)ePowerMode << (uint32)28U;
    }

    /* Mode transition is performed by writing ME_MCTL register twice:
        - 1st write: TARGET_MODE + KEY
        - 2nd write: TARGET_MODE + INVERTED KEY */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_MCTL_ADDR32, ((uint32)u32ModeConfig | (uint32)MC_ME_MCTL_DIRECT_KEY_U32));
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_MCTL_ADDR32, ((uint32)u32ModeConfig | (uint32)MC_ME_MCTL_INVERTED_KEY_U32));

    /* I will not wait for the actual mode shwitch to complete */
    /* clear all event flags */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IS_ADDR32, MC_ME_IS_I_CLEAR_MASK32 );
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IMTS_ADDR32, MC_ME_IMTS_MASK32 );

    /* and restore IRQ's */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_ME_IM_ADDR32, (u32EnabledIRQs & MC_ME_IM_WRBITS_MASK32) | MC_ME_IM_RESBITS_MASK32);
}
#endif /*(MCU_INIT_CLOCK == STD_ON)*/


/**
* @brief            This function activate the transition to a new MCU mode.
* @details          This function set the ME_MCTL register to load the mode configuration from one
*                   of the MC_<mode>_ME registers.
*                   Called by:
*                       - Mcu_MC_ME_ModeConfig() from this file
*                       - Mcu_MC_ME_ModesPeriphInit from this file
*                       - Mcu_MC_CGM_SetFMPLLOff() from MC_CGM
*                       - Mcu_MC_CGM_RestorePLL from MC_CGM
*
* @param[in]        ePowerMode   Code of the MCU mode that is mapped to ME_MCTL register.
*
* @return           void
* @implements       Mcu_MC_ME_ApplyMode_Activity
*/
/** @violates @ref Mcu_MC_ME_c_REF_5 Global declaration of function. */
FUNC( void, MCU_CODE) Mcu_MC_ME_ApplyMode( VAR( Mcu_PowerModeType, AUTOMATIC) ePowerMode )
{
    /* Timeout value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32Timeout = MCU_TIMEOUT_LOOPS;
    /* Configuration register value calculated based input parameter. */
    VAR( uint32, AUTOMATIC) u32ModeConfig = 0U;
#if (IPV_MC == IPV_MC_05_00_00_10)
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_NOT_OK;
#endif
    
    /* This if-branch = true can be used only for re-apply some new clock/mode settings of the same mode.*/
    if ( MCU_CURRENT_MODE == ePowerMode)
    {
        /*
        Any modification of the mode configuration register of the currently selected mode will not
        be taken into account immediately but on the next request to enter this mode. This means
        that transition requests such as RUN0_3->RUN0_3, DRUN->DRUN, SAFE->SAFE and TEST->TEST are
        considered valid mode transition requests. */
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        u32ModeConfig = (uint32)REG_READ32( MC_ME_GS_ADDR32) & MC_ME_GS_S_CURRENT_MODE_MASK32;
    }
    else
    {
        u32ModeConfig = (uint32)ePowerMode << (uint32)28U;
    }
    
#if (IPV_MC == IPV_MC_05_00_00_10)
    CheckStatus = Mcu_MC_ME_CheckResetOnModeChange();
#endif

    /* Mode transition is performed by writing ME_MCTL register twice:
        - 1st write: TARGET_MODE + KEY
        - 2nd write: TARGET_MODE + INVERTED KEY */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_MCTL_ADDR32, ((uint32)u32ModeConfig | (uint32)MC_ME_MCTL_DIRECT_KEY_U32) );
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_MCTL_ADDR32, ((uint32)u32ModeConfig | (uint32)MC_ME_MCTL_INVERTED_KEY_U32) );

#if (IPV_MC == IPV_MC_05_00_00_10)
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    if (((uint32)MCU_STBY0_MODE == (u32ModeConfig >> (uint32)28U)) || ((uint32)MCU_STOP0_MODE == (u32ModeConfig >> (uint32)28U)))
    {
        if ((Std_ReturnType)E_OK == CheckStatus)
        {
            SuspendAllInterrupts();
        }
        EXECUTE_WAIT();
    }
    else
    {
#endif
        if ((Std_ReturnType)E_OK == CheckStatus)
        {
            SuspendAllInterrupts();
            EXECUTE_WAIT();
        }
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    }
#endif
#endif

    /* The mode transition request may require a number of cycles depending on the programmed
    configuration, and software should check the S_CURRENT_MODE bit field and the S_MTRANS bit of
    the global status register ME_GS to verify when the mode has been correctly entered and the
    transition process has completed. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    while (((uint32)MC_ME_GS_S_MTRANS_MASK32 == (REG_READ32(MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_MTRANS_MASK32)) && (u32Timeout > (uint32)0x0U))
    {
        /* (ME_GS[S_MTRANS]=1) <=> (Transition ongoing). */
        u32Timeout--;
    }

    if ( (uint32)0x0U == u32Timeout)
    {
#if (IPV_MC == IPV_MC_05_00_00_10)
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    if (((uint32)MCU_STBY0_MODE == (u32ModeConfig >> (uint32)28U)) || ((uint32)MCU_STOP0_MODE == (u32ModeConfig >> (uint32)28U)))
    {
#endif
        if ((Std_ReturnType)E_OK == CheckStatus)
        {
            ResumeAllInterrupts();
        }
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
    }
#endif
#endif

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
}


/**
* @brief            This function initializes the mode structure.
* @details          This function initializes the mode structure by configuring the MC_ME module.
*                   The target mode is requested by accessing the ME_MCTL register with the required
*                   keys. This mode transition request by software must be a valid request
*                   satisfying a set of pre-defined rules to initiate the process. In the case of
*                   mode transitions occurring because of hardware events such as a reset, a SAFE
*                   mode request, or interrupt requests and wakeup events to exit from low-power
*                   modes, the TARGET_MODE bit field of the ME_MCTL register is automatically
*                   updated with the appropriate target mode.
*                   Called by:
*                       - Mcu_Ipw_SetMode() from IPW.
*
* @param[in]        Mcu_pModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_MC_ME_ModeConfig(P2CONST( Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pModeConfigPtr)
{
#if ((STD_ON == MCU_ENTER_LOW_POWER_MODE) && (defined ERR_IPV_MC_0036))
#if (STD_ON == ERR_IPV_MC_0036)
/** @violates @ref Mcu_MC_ME_c_REF_6 Macros defined within a block */
#define MC_ME_ERR_AGREGATOR_0
#endif /* (STD_ON == ERR_IPV_MC_0036) */
#elif (defined ERR_IPV_MC_0040) /* ((STD_ON == MCU_ENTER_LOW_POWER_MODE) && (defined ERR_IPV_MC_0036))*/
/* The condition is not met ,but we still need these variables */
#if ( STD_ON == ERR_IPV_MC_0040 )
/** @violates @ref Mcu_MC_ME_c_REF_6 Macros defined within a block */
#define MC_ME_ERR_AGREGATOR_0
#endif /* ( STD_ON == ERR_IPV_MC_0040 ) */
#endif /* (defined ERR_IPV_MC_0040) */

#ifdef MC_ME_ERR_AGREGATOR_0
    VAR( Mcu_PowerModeType, AUTOMATIC) CurrentMode = MCU_CURRENT_MODE;
    VAR( uint32, AUTOMATIC) u32ModeConfig = 0U;
    VAR( uint32, AUTOMATIC) u32InitModeConfig = 0U;
#endif /* MC_ME_ERR_AGREGATOR_0 */

#ifdef  ERR_IPV_MC_0040
#if (ERR_IPV_MC_0040 == STD_ON)
    VAR( uint32, AUTOMATIC) u32CurrentClockState = 0U;
    VAR( uint32, AUTOMATIC) u32SettingClockState = 0U;
#endif  /* ERR_IPV_MC_0040 */
#endif  /* (ERR_IPV_MC_0040 == STD_ON) */

#ifdef MCU_XOSC_MCB_SIN_END_BYP_AVAILABLE
    VAR (uint32, AUTOMATIC) u32XoscConfig;
#endif
    VAR (uint32, AUTOMATIC) u32ModeParams;

    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    if ((uint32)0x0U == ((uint32)REG_READ32(MC_ME_ME_ADDR32) & ((uint32)0x1U<<(uint32)Mcu_pModeConfigPtr->Mcu_ePowerMode)))
    {
        /* check if the requested mode is enabled */
        /* the transition will not take place if a disable mode is requested */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_InvalidModeConfigCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_InvalidModeConfigCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
    else
    {
#ifdef  ERR_IPV_MC_0040
#if (ERR_IPV_MC_0040 == STD_ON)
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        u32CurrentClockState = ((uint32)REG_READ32( MC_ME_GS_ADDR32) & (MC_ME_ENABLED_CLOCKS_MASK32));
        u32SettingClockState = (uint32)Mcu_pModeConfigPtr->Mcu_u32ModeParams & (MC_ME_ENABLED_CLOCKS_MASK32);

        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        CurrentMode = (Mcu_PowerModeType)(((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_CURRENT_MODE_MASK32) >> (uint32)28U);

        if \
        ( \
            (MCU_RUN3_MODE  == Mcu_pModeConfigPtr->Mcu_ePowerMode) || (MCU_RUN2_MODE  == Mcu_pModeConfigPtr->Mcu_ePowerMode) || \
            (MCU_RUN1_MODE  == Mcu_pModeConfigPtr->Mcu_ePowerMode) || (MCU_RUN0_MODE  == Mcu_pModeConfigPtr->Mcu_ePowerMode) || \
            (MCU_DRUN_MODE  == Mcu_pModeConfigPtr->Mcu_ePowerMode) || (MCU_SAFE_MODE  == Mcu_pModeConfigPtr->Mcu_ePowerMode) || \
            (MCU_TEST_MODE  == Mcu_pModeConfigPtr->Mcu_ePowerMode) \
        )
        {
            if \
            ( \
                ( \
                    ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_XOSC_MASK32)) && \
                    (MC_ME_GS_S_XOSC_MASK32 == (u32SettingClockState & MC_ME_GS_S_XOSC_MASK32)) \
                ) && \
                ( \
                    ( \
                        ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL0_MASK32)) && \
                        (MC_ME_GS_S_PLL0_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL0_MASK32)) \
                    ) || \
                    ( \
                        ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL1_MASK32)) && \
                        (MC_ME_GS_S_PLL1_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL1_MASK32)) \
                    ) \
                ) \
            )
            {
                /* get the current mode configuration */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                u32InitModeConfig = (uint32)REG_READ32(MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32));
                /* step 1 : switch to current mode but with HALT mode clock settings */
                u32ModeConfig = u32InitModeConfig & (~MC_ME_ENABLED_CLOCKS_MASK32);
                /* it's corresponding bit will be set to 0 by the mode macro that */
                /* defines the value of Mcu_pModeConfigPtr->Mcu_u32ModeParams */
                u32ModeConfig = u32ModeConfig | (Mcu_pModeConfigPtr->Mcu_u32ModeParams & (MC_ME_GS_S_XOSC_MASK32));

                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32 \
                ( \
                    MC_ME_BASEADDR, \
                    (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                    (uint32)u32ModeConfig \
                );
                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode(MCU_CURRENT_MODE);
            }

            if \
            ( \
                ( \
                    ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL0_MASK32)) && \
                    (MC_ME_GS_S_PLL0_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL0_MASK32))
                ) && \
                ( \
                    ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL1_MASK32)) && \
                    (MC_ME_GS_S_PLL1_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL1_MASK32)) \
                ) \
            )
            {
                /* get the current mode configuration */
                /** @violates @ref Mcu_MC_ME_c_REF_4 MISRA 2004 Required Rule 11.1, conversion form
                pointer to integer */
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                u32InitModeConfig = (uint32)REG_READ32(MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32));
                /* step 1 : switch to current mode but with HALT mode clock settings */
                u32ModeConfig = u32InitModeConfig & (~MC_ME_ENABLED_CLOCKS_MASK32);
                /* it's corresponding bit will be set to 0 by the mode macro that */
                /* defines the value of Mcu_pModeConfigPtr->Mcu_u32ModeParams */
                u32ModeConfig = u32ModeConfig | (Mcu_pModeConfigPtr->Mcu_u32ModeParams & (MC_ME_GS_S_XOSC_MASK32 | MC_ME_GS_S_PLL0_MASK32));

                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32 \
                ( \
                    MC_ME_BASEADDR, \
                    (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                    (uint32)u32ModeConfig \
                );
                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode(MCU_CURRENT_MODE);
            }
        }
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
        else if ((MCU_HALT0_MODE == Mcu_pModeConfigPtr->Mcu_ePowerMode) || (MCU_STOP0_MODE == Mcu_pModeConfigPtr->Mcu_ePowerMode))
        {
            if \
            ( \
                ( \
                    ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_XOSC_MASK32)) && \
                    (MC_ME_GS_S_XOSC_MASK32 == (u32SettingClockState & MC_ME_GS_S_XOSC_MASK32)) \
                ) && \
                ( \
                    (((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL0_MASK32)) && \
                    (MC_ME_GS_S_PLL0_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL0_MASK32))) || \
                    ( \
                        ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL1_MASK32)) && \
                        (MC_ME_GS_S_PLL1_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL1_MASK32)) \
                    ) \
                ) \
            )
            {
                /* get the current mode configuration */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                u32InitModeConfig = (uint32)REG_READ32(MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32));
                /* step 1 : switch to current mode but with HALT mode clock settings */
                u32ModeConfig = u32InitModeConfig & (~MC_ME_ENABLED_CLOCKS_MASK32);
                /* it's corresponding bit will be set to 0 by the mode macro that */
                /* defines the value of Mcu_pModeConfigPtr->Mcu_u32ModeParams */
                u32ModeConfig = u32ModeConfig | (Mcu_pModeConfigPtr->Mcu_u32ModeParams & (MC_ME_GS_S_XOSC_MASK32));

                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32 \
                ( \
                    MC_ME_BASEADDR, \
                    (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                    (uint32)u32ModeConfig \
                );
                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode(MCU_CURRENT_MODE);
            }

            if \
            ( \
                ( \
                    ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL0_MASK32)) && \
                    (MC_ME_GS_S_PLL0_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL0_MASK32)) \
                ) && \
                ( \
                    ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL1_MASK32)) && \
                    (MC_ME_GS_S_PLL1_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL1_MASK32)) \
                ) \
            )
            {
                /* get the current mode configuration */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                u32InitModeConfig = (uint32)REG_READ32(MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32));
                /* step 1 : switch to current mode but with HALT mode clock settings */
                u32ModeConfig = u32InitModeConfig & (~MC_ME_ENABLED_CLOCKS_MASK32);
                /* it's corresponding bit will be set to 0 by the mode macro that */
                /* defines the value of Mcu_pModeConfigPtr->Mcu_u32ModeParams */
                u32ModeConfig = u32ModeConfig | (Mcu_pModeConfigPtr->Mcu_u32ModeParams & (MC_ME_GS_S_XOSC_MASK32 | MC_ME_GS_S_PLL0_MASK32));

                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32 \
                (
                    MC_ME_BASEADDR, \
                    (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                    (uint32)u32ModeConfig \
                );
                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode(MCU_CURRENT_MODE);
            }

            if \
            ( \
                ((uint32)0x00000000UL == (u32CurrentClockState & MC_ME_GS_S_PLL1_MASK32)) && \
                (MC_ME_GS_S_PLL1_MASK32 == (u32SettingClockState & MC_ME_GS_S_PLL1_MASK32)) \
            )
            {
                /* get the current mode configuration */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                u32InitModeConfig = (uint32)REG_READ32(MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32));
                /* step 1 : switch to current mode but with HALT mode clock settings */
                u32ModeConfig = u32InitModeConfig & (~MC_ME_ENABLED_CLOCKS_MASK32);
                /* it's corresponding bit will be set to 0 by the mode macro that */
                /* defines the value of Mcu_pModeConfigPtr->Mcu_u32ModeParams */
                u32ModeConfig = u32ModeConfig | \
                                ( \
                                    Mcu_pModeConfigPtr->Mcu_u32ModeParams & \
                                    (MC_ME_GS_S_XOSC_MASK32 | MC_ME_GS_S_PLL0_MASK32 | MC_ME_GS_S_PLL1_MASK32) \
                                );

                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32 \
                ( \
                    MC_ME_BASEADDR, \
                    (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                    (uint32)u32ModeConfig \
                );
                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode(MCU_CURRENT_MODE);
            }
        }
#endif  /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
        else
        {
            /* do nothing */
        }
#endif  /* ERR_IPV_MC_0040 */
#endif  /* (ERR_IPV_MC_0040 == STD_ON) */

#if (MCU_CONFIGURE_CADDRN == STD_ON)
        /* now write the CADDRn registgers */
        /* the procedure is to write their value*/
        Mcu_MC_ME_ConfigureCoreAddrRegister( Mcu_pModeConfigPtr );
#endif /* (MCU_CONFIGURE_CADDRN == STD_ON) */

       u32ModeParams = (uint32)Mcu_pModeConfigPtr->Mcu_u32ModeParams;

#ifdef MCU_XOSC_MCB_SIN_END_BYP_AVAILABLE
       /* get MC_ME_GS and mask agains what i need */
       /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
       /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
       u32XoscConfig = REG_READ32(MC_ME_GS_ADDR32);
       u32XoscConfig &= MC_ME_GS_S_XOSC_MASK32;
       u32ModeParams|= (uint32)u32XoscConfig;
#endif

        /* ePowerMode should be in the range of "PowerModeType" enumeration values. */
        switch (Mcu_pModeConfigPtr->Mcu_ePowerMode)
        {
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
            case (MCU_HALT0_MODE):
#ifdef ERR_IPV_MC_0036
#if (STD_ON == ERR_IPV_MC_0036)
                /* e3879: MC_ME: Wakeup from HALT0/STOP0 modes to RUNx may get stalled */
                /* get the current mode */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                CurrentMode = \
                    (Mcu_PowerModeType)(((uint32)REG_READ32( MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_CURRENT_MODE_MASK32) >> (uint32)28U);
                /* get the current mode configuration */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                u32InitModeConfig = (uint32)REG_READ32(MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32));
                /* step 1 : switch to current mode but with HALT mode clock settings */
                u32ModeConfig = u32InitModeConfig & \
                                ~( \
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
                                     MC_ME_SDPLL_EN_U32  | \
#endif /* IPV_MC_04_03_00_00 */
                                     MC_ME_FMPLL0_EN_U32 | \
                                     MC_ME_FMPLL1_EN_U32 | \
                                     MC_ME_XOSC_EN_U32   | \
                                     MC_ME_IRCOSC_EN_U32 | \
                                     MC_ME_SYSCLK_DISABLED_U32 \
                                 ); /* clear the clock source bits */
                /* Note: SDPLL is used here, but for platforms that do not use this IP */
                /* it's corresponding bit will be set to 0 by the mode macro that */
                /* defines the value of Mcu_pModeConfigPtr->Mcu_u32ModeParams */
                u32ModeConfig = u32ModeConfig | \
                                ( \
                                    Mcu_pModeConfigPtr->Mcu_u32ModeParams & \
                                    ( \
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
                                        MC_ME_SDPLL_EN_U32  | \
#endif /* IPV_MC_04_03_00_00 */
                                        MC_ME_FMPLL0_EN_U32 | \
                                        MC_ME_FMPLL1_EN_U32 | \
                                        MC_ME_XOSC_EN_U32   | \
                                        MC_ME_IRCOSC_EN_U32 | \
                                        MC_ME_SYSCLK_DISABLED_U32 \
                                    ) \
                                ); /* merge with the sleep mode clock config bits */
                /* write this config to the current mode register */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32 \
                ( \
                    MC_ME_BASEADDR, \
                    (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                    (uint32)u32ModeConfig
                );
                /* jump to current mode with HALT clock sources */
                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
                /* write the config for HALT0 mode */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_HALT0_MC_ADDR32, (uint32)Mcu_pModeConfigPtr->Mcu_u32ModeParams);
                /* jump to halt */
                Mcu_MC_ME_ApplyMode( MCU_HALT0_MODE);
                /* we are back from halt, in mode X, with the same clocks as HALT */
                /* now set-up the original / fast wake-up mode and jump to it */
                /* fast wake-up if requered */
                if ( (boolean)TRUE == (boolean)Mcu_pModeConfigPtr->Mcu_bFastWakeup)
                {
                    /* Any modification of the mode configuration register of the currently
                    selected mode will not be taken into account immediately but on the next
                    request to enter this mode. */
#if ((MCU_ENTER_LOW_POWER_MODE == STD_ON) && (MCU_FAST_MODE_CONFIG == STD_ON))
                    Mcu_MC_ME_FastModeConfig( Mcu_pModeConfigPtr->Mcu_u32FastWakeupParams);
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
                }
                else
                {
                    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                    REG_WRITE_LOCK32 \
                    ( \
                        MC_ME_BASEADDR, \
                        (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                        (uint32)u32InitModeConfig \
                    );
                }
                /* switch to the original mode with the original / new config */
                Mcu_MC_ME_ApplyMode(CurrentMode);
#endif
#else
                /* normal way */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_HALT0_MC_ADDR32, (uint32)u32ModeParams);

                /* If fast transition is configured for current mode, update the running mode for
                the desired configuration when the system will wakeup. */
                if((boolean)TRUE == (boolean)Mcu_pModeConfigPtr->Mcu_bFastWakeup)
                {
                    /* Any modification of the mode configuration register of the currently
                    selected mode will not be taken into account immediately but on the next
                    request to enter this mode. */
#if ((MCU_ENTER_LOW_POWER_MODE == STD_ON) && (MCU_FAST_MODE_CONFIG == STD_ON))
                    Mcu_MC_ME_FastModeConfig( Mcu_pModeConfigPtr->Mcu_u32FastWakeupParams);
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
                }

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_HALT0_MODE);
#endif /* ERR_IPV_MC_0036 */
                break;

            case (MCU_STOP0_MODE):
#ifdef ERR_IPV_MC_0036
#if (STD_ON == ERR_IPV_MC_0036)
                /* e3879: MC_ME: Wakeup from HALT0/STOP0 modes to RUNx may get stalled */
                /* get the current mode */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                CurrentMode = (Mcu_PowerModeType)(((uint32)REG_READ32(MC_ME_GS_ADDR32) & (uint32)MC_ME_GS_S_CURRENT_MODE_MASK32) >> (uint32)28U);
                /* get the current mode configuration */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                u32InitModeConfig = (uint32)REG_READ32(MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32));
                /* step 1 : switch to current mode but with STOP mode clock settings */
                u32ModeConfig = u32InitModeConfig & \
                                ~( \
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
                                     MC_ME_SDPLL_EN_U32  | \
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */
                                     MC_ME_FMPLL0_EN_U32 | \
                                     MC_ME_FMPLL1_EN_U32 | \
                                     MC_ME_XOSC_EN_U32   | \
                                     MC_ME_IRCOSC_EN_U32 | \
                                     MC_ME_SYSCLK_DISABLED_U32 \
                                 ); /* clear the clock source bits */
                /* Note: SDPLL is used here, but for platforms that do not use this IP */
                /* it's corresponding bit will be set to 0 by the mode macro that */
                /* defines the value of Mcu_pModeConfigPtr->Mcu_u32ModeParams */
                u32ModeConfig = u32ModeConfig | \
                                (Mcu_pModeConfigPtr->Mcu_u32ModeParams & \
                                ( \
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
                                    MC_ME_SDPLL_EN_U32  | \
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */
                                    MC_ME_FMPLL0_EN_U32 | \
                                    MC_ME_FMPLL1_EN_U32 | \
                                    MC_ME_XOSC_EN_U32   | \
                                    MC_ME_IRCOSC_EN_U32 | \
                                    MC_ME_SYSCLK_DISABLED_U32) \
                                ); /* merge with the sleep mode clock config bits */
                /* write this config to the current mode register */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32 \
                ( \
                    MC_ME_BASEADDR, \
                    (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                    (uint32)u32ModeConfig \
                );
                /* jump to current mode with HALT clock sources */
                Mcu_MC_ME_ApplyMode( MCU_CURRENT_MODE);
                /* configure STOP0 */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_STOP0_MC_ADDR32, (uint32)Mcu_pModeConfigPtr->Mcu_u32ModeParams);
                /* jump to stop */
                Mcu_MC_ME_ApplyMode( MCU_STOP0_MODE);
                /* now set-up the original / fast wake-up mode and jump to it */
                /* fast wake-up if requered */
                if ((boolean)TRUE == (boolean)Mcu_pModeConfigPtr->Mcu_bFastWakeup)
                {
                    /* Any modification of the mode configuration register of the currently
                    selected mode will not be taken into account immediately but on the next
                    request to enter this mode. */
#if ((STD_ON == MCU_ENTER_LOW_POWER_MODE) && (MCU_FAST_MODE_CONFIG == STD_ON))
                    Mcu_MC_ME_FastModeConfig( Mcu_pModeConfigPtr->Mcu_u32FastWakeupParams);
#endif /* (STD_ON == MCU_ENTER_LOW_POWER_MODE) */
                }
                else
                {
                    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                    REG_WRITE_LOCK32 \
                    ( \
                        MC_ME_BASEADDR, \
                        (MC_ME_RESET_MC_ADDR32 + ((uint32)CurrentMode * (uint32)MC_ME_MODE_MC_REG_OFFSET_U32)), \
                        (uint32)u32InitModeConfig \
                    );
                }
                /* switch to the original mode with the original / new config */
                Mcu_MC_ME_ApplyMode(CurrentMode);
#endif
#else
                /* normal way */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_STOP0_MC_ADDR32, (uint32)u32ModeParams);

                /* If fast transition is configured for current mode, update the running mode for
                the desired configuration when the system will wakeup. */
                if ( (boolean)TRUE == (boolean)Mcu_pModeConfigPtr->Mcu_bFastWakeup)
                {
                    /* Any modification of the mode configuration register of the currently
                    selected mode will not be taken into account immediately but on the next
                    request to enter this mode. */
#if ((MCU_ENTER_LOW_POWER_MODE == STD_ON) && (MCU_FAST_MODE_CONFIG == STD_ON))
                    Mcu_MC_ME_FastModeConfig(Mcu_pModeConfigPtr->Mcu_u32FastWakeupParams);
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
                }

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode(MCU_STOP0_MODE);
#endif /* ERR_IPV_MC_0036 */
                break;

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07))
            case (MCU_STBY0_MODE):
#ifdef MCU_ERR009139_IPV_MC_05000007
#if (MCU_ERR009139_IPV_MC_05000007 == STD_ON)
                /* Support to configure GPR_SLEEP_BIT for errata ERR009139 on C3M */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_RMW32( MC_ME_GPR_SLEEP_ADDR32, MC_ME_GPR_SLEEP_RWBITS_MASK32, (uint32)Mcu_pModeConfigPtr->u32GprSleepMode);
#endif  /* MCU_ERR009139_IPV_MC_05000007 */
#endif  /* (MCU_ERR009139_IPV_MC_05000007 == STD_ON) */

                /* normal way */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_STBY0_MC_ADDR32, (uint32)u32ModeParams);

                /* If fast transition is configured for current mode, update the running mode for
                the desired configuration when the system will wakeup. */
                if ( (boolean)TRUE == (boolean)Mcu_pModeConfigPtr->Mcu_bFastWakeup)
                {
                    /* Any modification of the mode configuration register of the currently
                    selected mode will not be taken into account immediately but on the next
                    request to enter this mode. */
#if ((MCU_ENTER_LOW_POWER_MODE == STD_ON) && (MCU_FAST_MODE_CONFIG == STD_ON))
                    Mcu_MC_ME_FastModeConfig( Mcu_pModeConfigPtr->Mcu_u32FastWakeupParams);
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
                }

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_STBY0_MODE);
                break;
#endif
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */

            case (MCU_RUN3_MODE):
                /* Previous valid states: DRUN, SAFE, RUN0_3, HALT0 (interrupt event), STOP0
                (interrupt or wakeup event). */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN3_MC_ADDR32, (uint32)u32ModeParams);
                
#if (IPV_MC == IPV_MC_06_00_00_10)
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN3_SEC_CC_I_ADDR32, (uint32)Mcu_pModeConfigPtr->Mcu_u32SecondaryClockConfig);
#endif

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_RUN3_MODE);
                break;

            case (MCU_RUN2_MODE):
                /* Previous valid states: DRUN, SAFE, RUN0_3, HALT0 (interrupt event), STOP0
                (interrupt or wakeup event). */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN2_MC_ADDR32, (uint32)u32ModeParams);

#if (IPV_MC == IPV_MC_06_00_00_10)
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN2_SEC_CC_I_ADDR32, (uint32)Mcu_pModeConfigPtr->Mcu_u32SecondaryClockConfig);
#endif

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_RUN2_MODE);
                break;

            case (MCU_RUN1_MODE):
                /* Previous valid states: DRUN, SAFE, RUN0_3, HALT0 (interrupt event), STOP0
                (interrupt or wakeup event). */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN1_MC_ADDR32, (uint32)u32ModeParams);

#if (IPV_MC == IPV_MC_06_00_00_10)
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN1_SEC_CC_I_ADDR32, (uint32)Mcu_pModeConfigPtr->Mcu_u32SecondaryClockConfig);
#endif

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_RUN1_MODE);
                break;

            case (MCU_RUN0_MODE):
                /* Previous valid states: DRUN, SAFE, RUN0_3, HALT0 (interrupt event), STOP0
                (interrupt or wakeup event). */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN0_MC_ADDR32, (uint32)u32ModeParams);
                
#if (IPV_MC == IPV_MC_06_00_00_10)
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN0_SEC_CC_I_ADDR32, (uint32)Mcu_pModeConfigPtr->Mcu_u32SecondaryClockConfig);
#endif

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_RUN0_MODE);
                break;

            case (MCU_DRUN_MODE):
                /* Previous valid states: RUN0_3, SAFE, TEST and RESET
                (automatically after completion of the reset sequence). */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_DRUN_MC_ADDR32, (uint32)u32ModeParams);
                
#if (IPV_MC == IPV_MC_06_00_00_10)
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_RUN0_SEC_CC_I_ADDR32, (uint32)Mcu_pModeConfigPtr->Mcu_u32SecondaryClockConfig);
#endif

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_DRUN_MODE);
                break;

            case (MCU_SAFE_MODE):
                /* Previous valid states: DRUN, RUN0_3, TEST. */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_SAFE_MC_ADDR32, (uint32)u32ModeParams);

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_SAFE_MODE);
                break;

            case (MCU_RESET_MODE):
                /* A RESET mode requested via the ME_MCTL register is passed to the MC_RGM, which
                generates a global system reset and initiates the reset sequence. The RESET mode
                request has the highest priority, and the MC_ME is kept in the RESET mode during
                the entire reset sequence. */

                /* Previous valid states: SAFE, DRUN, RUN0_3, TEST. */

                /* This mode has a pre-defined configuration, and the 16 MHz int. RC osc. is
                selected as the system clock. */

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_RESET_MODE);
                break;

            case (MCU_DEST_RESET_MODE):
                /* A RESET mode requested via the ME_MCTL register is passed to the MC_RGM, which
                generates a global system reset and initiates the reset sequence. The RESET mode
                request has the highest priority, and the MC_ME is kept in the RESET mode during
                the entire reset sequence. */

                /* Previous valid states: SAFE, DRUN, RUN0_3, TEST. */

                /* This mode has a pre-defined configuration, and the 16 MHz int. RC osc. is
                selected as the system clock. */

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_DEST_RESET_MODE);

                break;

            case (MCU_TEST_MODE):
                /* Previous valid states: DRUN. */
                /* Set the new configuration for the mode. */
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_TEST_MC_ADDR32, (uint32)u32ModeParams);
                
#if (IPV_MC == IPV_MC_06_00_00_10)
                /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
                /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
                REG_WRITE_LOCK32(MC_ME_BASEADDR, MC_ME_TEST_SEC_CC_I_ADDR32, (uint32)Mcu_pModeConfigPtr->Mcu_u32SecondaryClockConfig);
#endif

                /* Apply the new mode using above configuration. */
                Mcu_MC_ME_ApplyMode( MCU_TEST_MODE);
                break;

            default:
                /* Default case - should never enter here. */
                break;
        }
    }
}

#if ((MCU_GET_PERIPH_STATE_API == STD_ON) || (defined MCU_GET_INTERNAL_STATE))
/**
* @brief            This function returns the peripheral clock state.
* @details          This function returns one peripheral is frozen or active from MC_ME hw IP.
*                   Called by:
*                       - Mcu_IPW_GetPeripheral_State() from IPW.
*
* @param[in]        Mcu_ePeriphId   Peripheral ID based ME_PSx registers.
*
* @return           Status of the peripheral clock.
* @retval           E_OK   Peripheral is active (clocked).
* @retval           E_NOT_OK   Peripheral is not active (not clocked).
*
*/
FUNC( Std_ReturnType, MCU_CODE) Mcu_MC_ME_GetPeripheralState(VAR( Mcu_PeripheralIdType, AUTOMATIC) Mcu_ePeriphId)
{
    /* MC_ME: ME_PS register value. */
    VAR( uint32, AUTOMATIC)   u32RegVal = (uint32)0x0U;
    /* Result of the operation. */
    VAR( Std_ReturnType, AUTOMATIC) PeripheralStatus = (Std_ReturnType)E_NOT_OK;

    /* Get the value of ME_PSx register. */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32RegVal = REG_READ32(MC_ME_PS0_ADDR32 + (((uint32)Mcu_ePeriphId >> (uint32)0x05U) * (uint32)MC_ME_PS_OFFSET_U32));

    if ((uint32)0x0U != (uint32)((uint32)u32RegVal & ((uint32)0x01U << ((uint32)Mcu_ePeriphId & (uint32)0x1FU ))))
    {
        PeripheralStatus = (Std_ReturnType)E_OK;
    }

    return (Std_ReturnType)PeripheralStatus;
}
#endif /* ((MCU_GET_PERIPH_STATE_API == STD_ON) || (defined MCU_GET_INTERNAL_STATE)) */


#if (MCU_POWERMODE_STATE_API == STD_ON)
/**
* @brief            This function returns the System Status (power mode, clock settings) from MC_ME
*                   hw IP.
* @details          The return value is the content register read from hardware (ME_GS).
*                   The return value shall evidentiate the current running mode, clock settings and
*                   activation, etc.
*                   Called by:
*                       - Mcu_IPW_GetPowerMode_State() from IPW.
*
* @return           Get the state of the power mode.
* @retval           uint32   Content of ME_GS register.
*
*/
FUNC( Mcu_PowerModeStateType, MCU_CODE) Mcu_MC_ME_GetPowerModeState( VAR( void, AUTOMATIC) )
{
    /* Return value of this function. */
    VAR( Mcu_PowerModeStateType, AUTOMATIC) PowerMode_State = 0U;

    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    PowerMode_State = (Mcu_PowerModeStateType)REG_READ32(MC_ME_GS_ADDR32);

    return (Mcu_PowerModeStateType)PowerMode_State;

}
#endif /* (MCU_POWERMODE_STATE_API == STD_ON) */

#if ( MCU_CONFIGURE_CADDRN == STD_ON )
/**
* @brief            This function will write the MC_ME_CADDRn registers
* @details          Each CADDRn register is written with it's specific value.
*                   No checks will be done in this function, the code assumes that the input
*                   parameters are already checked
*                   Called by:
*                       - Mcu_MC_ME_ModeConfig().
*
* @param[in]        Mcu_CADDR1,2,3   Value of the respective register.
*
* @return           none
*
*/
static FUNC( void, MCU_CODE) Mcu_MC_ME_ConfigureCoreAddrRegister(P2CONST( Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pModeConfigPtr)
{
    VAR(uint8, AUTOMATIC) u8CoreIdx;
    
    /* set the boot address here */
    for (u8CoreIdx = 0x00U; u8CoreIdx < Mcu_pModeConfigPtr->u8NumberOfCoreAddrRegs; u8CoreIdx++)
    {
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer. */
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_RMW32 \
        ( \
            (*Mcu_pModeConfigPtr->apCoreAddress)[u8CoreIdx].u32RegisterAddr, \
            (*Mcu_pModeConfigPtr->apCoreAddress)[u8CoreIdx].u32RegisterMask, \
            (*Mcu_pModeConfigPtr->apCoreAddress)[u8CoreIdx].u32RegisterData  \
        );
    }
}

#endif /* MCU_CONFIGURE_CADDRN == STD_ON */

#if (IPV_MC == IPV_MC_05_00_00_10)
static FUNC( Std_ReturnType, MCU_CODE) Mcu_MC_ME_CheckResetOnModeChange(VAR( void, AUTOMATIC))
{
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_NOT_OK;

    /* CORE0 Address Register (MC_ME_CADDR0) */
    {
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        if (MC_ME_CADDR_RESET_ENABLE_U32 == (REG_READ32(MC_ME_CADDR0_ADDR32) & MC_ME_CADDR_RMC_MASK32))
        {
            CheckStatus = (Std_ReturnType)E_OK;
        }
    }
    /* CORE1 Address Register (MC_ME_CADDR1) */
    if ((Std_ReturnType)E_NOT_OK == CheckStatus)
    {
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        if (MC_ME_CADDR_RESET_ENABLE_U32 == (REG_READ32(MC_ME_CADDR1_ADDR32) & MC_ME_CADDR_RMC_MASK32))
        {
            CheckStatus = (Std_ReturnType)E_OK;
        }
    }
    /* CORE2 Address Register (MC_ME_CADDR2) */
    if ((Std_ReturnType)E_NOT_OK == CheckStatus)
    {
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        if (MC_ME_CADDR_RESET_ENABLE_U32 == (REG_READ32(MC_ME_CADDR2_ADDR32) & MC_ME_CADDR_RMC_MASK32))
        {
            CheckStatus = (Std_ReturnType)E_OK;
        }
    }

    return (Std_ReturnType)CheckStatus;
}
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_06_00_00_10))
#if((MCU_SAFE_MODE_ISR_USED == STD_ON ) || \
    (MCU_INVALID_MODE_ISR_USED == STD_ON ) || \
    (MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) || \
    (MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON) || \
    (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON) \
   )
/* this platform has only 1 IRQ handler for all MC_ME events - enable it if there is at leas one IRQ handled */
FUNC( void, MCU_CODE) Mcu_MC_ME_Int( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC)   u32InterruptStatus;
#if((MCU_SAFE_MODE_ISR_USED == STD_ON ) || \
    (MCU_INVALID_MODE_ISR_USED == STD_ON ) || \
    (MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) || \
    (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON) \
   )
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC)   u32InterruptEnable;
#endif  /* MCU_ERROR_ISR_NOTIFICATION */
#endif
    VAR( uint32, AUTOMATIC)   u32InvalidModeTransition;

    /* step 1: get all flags and clear them */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32InterruptStatus = REG_READ32( MC_ME_IS_ADDR32 ) & MC_ME_IS_I_CLEAR_MASK32 ;
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IS_ADDR32 , u32InterruptStatus );

    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32InvalidModeTransition = REG_READ32( MC_ME_IMTS_ADDR32 ) & MC_ME_IMTS_S_CLEAR_MASK32 ;
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IMTS_ADDR32 , u32InvalidModeTransition );

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
#if((MCU_SAFE_MODE_ISR_USED == STD_ON ) || \
    (MCU_INVALID_MODE_ISR_USED == STD_ON ) || \
    (MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) || \
    (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON) \
   )
        /* step 2 - get interrupt enable mask */
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        u32InterruptEnable = REG_READ32( MC_ME_IM_ADDR32 );
#endif

        /* step 3 - check if there are handlers enabled */
#if ( MCU_SAFE_MODE_ISR_USED == STD_ON )
        if(MC_ME_IS_I_SAFE_MASK32 == (MC_ME_IS_I_SAFE_MASK32 & u32InterruptStatus))
        {
            if(MC_ME_IM_M_SAFE_MASK32 == (MC_ME_IM_M_SAFE_MASK32 & u32InterruptEnable))
            {
                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_SAFE_MODE);
            }
        }
#endif /* ( MCU_SAFE_MODE_ISR_USED == STD_ON ) */

#if (MCU_INVALID_MODE_ISR_USED == STD_ON)
        if(MC_ME_IS_I_IMODE_MASK32 == ( MC_ME_IS_I_IMODE_MASK32 & u32InterruptStatus))
        {
            if (MC_ME_IM_M_IMODE_MASK32 == (MC_ME_IM_M_IMODE_MASK32 & u32InterruptEnable))
            {
                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_INVALID_MODE);
            }
        }
#endif /* (MCU_INVALID_MODE_ISR_USED == STD_ON) */

#if ((MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) || \
     (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON) \
    )
        /* all conf type irq's are treated as one */
        if ( (uint32)0x00U != ( MC_ME_IS_I_CONF_ALL_MASK32 & u32InterruptStatus ) )
        {
            if ( (uint32)0x00U != ( MC_ME_IM_M_ICONF_ALL_MASK32 & u32InterruptEnable))
            {
                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_INVALID_MODE_CONFIG);
            }
        }
#endif
    }
#endif
}
#endif
#else
    /* for all other platforms */
#if (MCU_SAFE_MODE_ISR_USED == STD_ON )
/**
* @brief            This function handle the Safe Mode Interrupt.
* @details          Assigned to INTC51 for MPC56XXL.
*                   Assigned to INTC251 for MPC57XXP.
*                   ME_IS[I_SAFE] bit is set by hardwrae only if ME_IM[M_SAFE] is true.
*
* @return           void
* @implements       Mcu_MC_ME_SafeMode_Int_Activity
*/
FUNC( void, MCU_CODE) Mcu_MC_ME_SafeMode_Int( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC)   u32InterruptStatus;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC)   u32InterruptEnable;
#endif
    /* read my IRQ flag */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32InterruptStatus = (REG_READ32(MC_ME_IS_ADDR32) & MC_ME_IS_I_SAFE_MASK32);
    /* clear IRQ flag */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IS_ADDR32, u32InterruptStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /*  check if IRQ is enabled */
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        u32InterruptEnable = REG_READ32(MC_ME_IM_ADDR32) & MC_ME_IM_M_SAFE_MASK32;
        
        /* my IRQ is 1 */
        if(MC_ME_IS_I_SAFE_MASK32 == (MC_ME_IS_I_SAFE_MASK32 & u32InterruptStatus))
        {
            /* and enable is 1 */
            if (MC_ME_IM_M_SAFE_MASK32 == (MC_ME_IM_M_SAFE_MASK32 & u32InterruptEnable))
            {
                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_SAFE_MODE);
            }
        }
    }
#endif
}
#endif /* (MCU_SAFE_MODE_ISR_USED == STD_ON) */


#if ( MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON )
/**
* @brief            This function handle the Mode Transition Complete Interrupt.
* @details          Assigned to INTC52 for MPC56XXL.
*                   Assigned to INTC252 for MPC57XXP.
*                   ME_IS[I_MTC] bit is set by hardwrae only if ME_IM[M_MTC] is true.
*
* @return           void
* @implements       Mcu_MC_ME_TransitionComplete_Int_Activity
*/
FUNC( void, MCU_CODE) Mcu_MC_ME_TransitionComplete_Int( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC) u32InterruptStatus;

    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32InterruptStatus = (REG_READ32(MC_ME_IS_ADDR32) & MC_ME_IS_I_MTC_MASK32);
    /* clear isr flags */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IS_ADDR32, u32InterruptStatus);

    /* nothing to report for this IRQ */
}
#endif /* (MCU_TRANSITION_COMPLETE_ISR_USED == STD_ON) */


#if (MCU_INVALID_MODE_ISR_USED == STD_ON)
/**
* @brief            This function handle the Invalid Mode Interrupt.
* @details          Assigned to INTC53 for MPC56XXL.
*                   Assigned to INTC253 for MPC57XXP.
*                   ME_IS[I_IMODE] bit is set by hardware only if ME_IM[M_IMODE] is true.
*
* @return           void
* @implements       Mcu_MC_ME_InvalidMode_Int_Activity
*/
FUNC( void, MCU_CODE) Mcu_MC_ME_InvalidMode_Int( VAR( void, AUTOMATIC) )
{
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC)   u32InterruptEnable;
#endif
    VAR( uint32, AUTOMATIC)   u32InterruptStatus;
    VAR( uint32, AUTOMATIC)   u32InvalidModeStatus;

    /* get IRQ flags */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32InterruptStatus = (REG_READ32(MC_ME_IS_ADDR32) & MC_ME_IS_I_IMODE_MASK32);

    /* clear isr flags */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IS_ADDR32, u32InterruptStatus);

    /* get the invalid mode status and clear the bits*/
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32InvalidModeStatus = REG_READ32(MC_ME_IMTS_ADDR32) & MC_ME_IMTS_MASK32;
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IMTS_ADDR32, u32InvalidModeStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        u32InterruptEnable = REG_READ32(MC_ME_IM_ADDR32);
        
        if ( MC_ME_IS_I_IMODE_MASK32 == ( MC_ME_IS_I_IMODE_MASK32 & u32InterruptStatus ))
        {
            if (MC_ME_IM_M_IMODE_MASK32 == ( MC_ME_IM_M_IMODE_MASK32 & u32InterruptEnable))
            {
                /* Invalid mode transition interrupt can have many sources. */
                /* report an event if any of it's sources are visible */
                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_INVALID_MODE);
            }
        }
    }
#endif
}
#endif /* (MCU_INVALID_MODE_ISR_USED == STD_ON) */

#if ((MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) || \
     (MCU_INVALID_CLK_CONFIGURATION_ISR_USED == STD_ON) || \
     (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON) \
    )
/**
* @brief            This function handle the Invalid Mode Interrupt
* @details          Assigned to INTC54 for MPC56XXL.
*                   Assigned to INTC254 for MPC57XXP.
*                   ME_IS[I_ICONF] bit is set by hardware only if ME_IM[M_ICONF] is true.
*                   ME_IS[I_ICONF_CU] bit is set by hardware only if ME_IM[M_ICONF_CU] is true.
*
* @return           void
* @implements       Mcu_MC_ME_InvalidModeConfig_Int_Activity
*/
FUNC( void, MCU_CODE) Mcu_MC_ME_InvalidModeConfig_Int( VAR( void, AUTOMATIC) )
{
    VAR( uint32, AUTOMATIC)   u32InterruptStatus;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC)   u32InterruptEnable;
#endif

    /* get ISR status */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32InterruptStatus = REG_READ32(MC_ME_IS_ADDR32) & (MC_ME_IS_I_ICONF_MASK32 | MC_ME_IS_I_ICONF_CU_MASK32 | MC_ME_IS_I_ICONF_CC_MASK32);

    /* clear ISR flags */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_ME_IS_ADDR32, u32InterruptStatus);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* get enabled IRQ flags */
        /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
        u32InterruptEnable = REG_READ32(MC_ME_IM_ADDR32) & (MC_ME_IM_M_ICONF_CC_MASK32 | MC_ME_IM_M_ICONF_CU_MASK32 | MC_ME_IM_M_ICONF_MASK32);
        
        if (((uint32)0U != u32InterruptStatus) && ((uint32)0U != u32InterruptEnable))
        {
            MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_INVALID_MODE_CONFIG);
        }
    }
#endif
}
#endif /* ((MCU_INVALID_CONFIGURATION_ISR_USED == STD_ON) ||
          (MCU_INVALID_CLK_CONFIGURATION_ISR_USED == STD_ON) || \
          (MCU_INVALID_CORE_CONFIGURATION_ISR_USED == STD_ON)  */
#endif /* ((IPV_MC == IPV_MC_05_00_00_10) && (MCU_ISR_USED == STD_ON )) */


/**
* @brief    This function returns the value of MC_ME_GS masked against enabled clock sources and
*           system clock selection
*/
/** @violates @ref Mcu_MC_ME_c_REF_5 Global declaration of function */
FUNC( uint32, MCU_CODE) Mcu_MC_ME_GetCurrentModeClockSettings( VAR( void, AUTOMATIC))
{
    VAR( uint32, AUTOMATIC) u32ClockStatus;

    /* get MC_ME_GS and mask agains what i need */
    /** @violates @ref Mcu_MC_ME_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_MC_ME_c_REF_7 The cast is used to access memory mapped registers.*/
    u32ClockStatus = REG_READ32(MC_ME_GS_ADDR32);

#if ((IPV_MC == IPV_MC_04_04_01_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00))
     u32ClockStatus &= ( \
                           MC_ME_GS_S_SYSCLK_MASK32 | \
                           MC_ME_GS_S_PLL1_MASK32 | \
                           MC_ME_GS_S_PLL0_MASK32 | \
                           MC_ME_GS_S_XOSC_MASK32 | \
                           MC_ME_GS_S_IRCOSC_MASK32 \
                       );
#endif /* (IPV_MC == IPV_MC_04_04_01_00)  ... */

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_06_05_00))
     u32ClockStatus &= ( \
                           MC_ME_GS_S_SYSCLK_MASK32 | \
                           MC_ME_GS_S_SDPLL_MASK32 | \
                           MC_ME_GS_S_PLL1_MASK32 | \
                           MC_ME_GS_S_PLL0_MASK32 | \
                           MC_ME_GS_S_XOSC_MASK32 | \
                           MC_ME_GS_S_IRCOSC_MASK32 \
                       );
#endif /* (IPV_MC == IPV_MC_04_03_00_00) */

#if (IPV_MC == IPV_MC_05_00_00_10)
    /* i select only the current system clock and active clock sources */
    u32ClockStatus &= ( \
                          MC_ME_GS_S_SYSCLK_MASK32 | \
                          MC_ME_GS_S_FIRC_MASK32 | \
                          MC_ME_GS_S_FXOSC_MASK32 | \
                          MC_ME_GS_S_SIRC_MASK32 | \
                          MC_ME_GS_S_SXOSC_MASK32 | \
                          MC_ME_GS_S_PLL0_MASK32 | \
                          MC_ME_GS_S_PLL1_MASK32 | \
                          MC_ME_GS_S_PLL2_MASK32 | \
                          MC_ME_GS_S_PLL3_MASK32 \
                      );
#endif /* (IPV_MC == IPV_MC_05_00_00_10) */

#if (IPV_MC == IPV_MC_05_00_00_07)
    /* i select only the current system clock and active clock sources */
    u32ClockStatus &= ( \
                          MC_ME_GS_S_SYSCLK_MASK32 | \
                          MC_ME_GS_S_FIRC_MASK32 | \
                          MC_ME_GS_S_FXOSC_MASK32 | \
                          MC_ME_GS_S_SIRC_MASK32 | \
                          MC_ME_GS_S_SXOSC_MASK32 | \
                          MC_ME_GS_S_PLL0_MASK32 \
                      );
#endif /* (IPV_MC == IPV_MC_05_00_00_07) */

#if (IPV_MC == IPV_MC_06_00_00_10)
    u32ClockStatus &= ( \
                          MC_ME_GS_S_SYSCLK_MASK32 | \
                          MC_ME_GS_S_FIRC_MASK32 | \
                          MC_ME_GS_S_XOSC_MASK32 | \
                          MC_ME_GS_S_ARMPLLDFS123_MASK32 | \
                          MC_ME_GS_S_PERIPHPLL_MASK32 | \
                          MC_ME_GS_S_ENETPLLDFS1234_MASK32 | \
                          MC_ME_GS_S_DDRPLLDFS123_MASK32 | \
                          MC_ME_GS_S_VIDEOPLL_MASK32 \
                      );
#endif
    return ((uint32)u32ClockStatus);
}

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_MC_ME_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_MC_ME_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
