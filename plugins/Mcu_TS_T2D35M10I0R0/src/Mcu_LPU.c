/**
*   @file    Mcu_LPU.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Low Power Unit functions implementation.
*   @details Specific functions for LPU configuration and control.
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
* @section Mcu_LPU_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_LPU_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_LPU_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
* pointer to a function and a type other than an integral type. This violation is due to the
* pointer arithmetic used to write/ read the data to/from the registers
*
* @section Mcu_LPU_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is requiered
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_LPU_c_REF_5
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
#include "Mcu_LPU.h"

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
#define Mcu_LPU_VENDOR_ID_C                      43
#define Mcu_LPU_AR_RELEASE_MAJOR_VERSION_C       4
#define Mcu_LPU_AR_RELEASE_MINOR_VERSION_C       2
#define Mcu_LPU_AR_RELEASE_REVISION_VERSION_C    2
#define Mcu_LPU_SW_MAJOR_VERSION_C               1
#define Mcu_LPU_SW_MINOR_VERSION_C               0
#define Mcu_LPU_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if current file and Mcu_CMU header file are of the same vendor */
#if (Mcu_LPU_VENDOR_ID_C != MCU_LPU_VENDOR_ID)
    #error "Mcu_LPU.c and Mcu_LPU.h have different vendor ids"
#endif
/* Check if current file and Mcu__CMU header file are of the same Autosar version */
#if ((Mcu_LPU_AR_RELEASE_MAJOR_VERSION_C    != MCU_LPU_AR_RELEASE_MAJOR_VERSION) || \
     (Mcu_LPU_AR_RELEASE_MINOR_VERSION_C    != MCU_LPU_AR_RELEASE_MINOR_VERSION) || \
     (Mcu_LPU_AR_RELEASE_REVISION_VERSION_C != MCU_LPU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_LPU.c and Mcu_LPU.h are different"
#endif
/* Check if current file and Mcu_CMU header file are of the same Software version */
#if ((Mcu_LPU_SW_MAJOR_VERSION_C != MCU_LPU_SW_MAJOR_VERSION) || \
     (Mcu_LPU_SW_MINOR_VERSION_C != MCU_LPU_SW_MINOR_VERSION) || \
     (Mcu_LPU_SW_PATCH_VERSION_C != MCU_LPU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_LPU.c and Mcu_LPU.h are different"
#endif

/* Check if current file and DEM header file are of the same version */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_LPU_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_LPU_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_LPU.c and Dem.h are different"
    #endif
#endif
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_LPU_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_LPU_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_LPU.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_LPU_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_LPU_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_LPU.c and SilRegMacros.h are different"
    #endif
#endif

#ifdef MCU_ERROR_ISR_NOTIFICATION
/* Check if current file and MCU header file are of the same vendor */
#if (Mcu_LPU_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu_LPU.c and Mcu.h have different vendor ids"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_LPU_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (Mcu_LPU_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
        (Mcu_LPU_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Mcu_LPU.c and Mcu.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same Software version */
#if ((Mcu_LPU_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (Mcu_LPU_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (Mcu_LPU_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu_LPU.c and Mcu.h are different"
#endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
* @violates @ref Mcu_LPU_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
* @violates @ref Mcu_LPU_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#if (MCU_LPU_SUPPORT == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
*/
FUNC( void, MCU_CODE) Mcu_LPU_SetUserAccessAllowed(void)
{
    /** @violates @ref Mcu_LPU_c_REF_3 Conversion from pointer to integer */
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    SET_USER_ACCESS_ALLOWED(LPU_BASEADDR);
}
#endif
#endif

static FUNC( void, MCU_CODE) Mcu_LPU_ConfigureModuleDisable(VAR(uint32, AUTOMATIC) Mcu_u32ModuleDisableConfiguration);
static FUNC( void, MCU_CODE) Mcu_LPU_ConfigureInterrupts(VAR(uint32, AUTOMATIC) Mcu_u32InterruptConfiguration);
static FUNC( void, AUTOMATIC) Mcu_LPU_ApplyMode(VAR(Mcu_LpuModeType, MCU_VAR) eLowPowerMode);
#endif

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

#if (MCU_LPU_SUPPORT == STD_ON)
/**
* @brief            This function initializes the LPU interrupts.
* @details          This function intializes the LPU interrupts by configuring the LPU_ICR register.
*                   LPU_MRIG_E - LPU mode request ignored interrupt enable
*                   LPU_NEM_E  - LPU non-exist mode interrupt enable
*                   Called by:
*                       - Mcu_LPU_LowPowerModeConfig() from Mcu_LPU.
*
* @param[in]        Mcu_u32ModuleDisableConfiguration   Peripherals to be disabled in LPU modes.
*
* @return           void
*
*/
static FUNC( void, MCU_CODE) Mcu_LPU_ConfigureModuleDisable (VAR(uint32, AUTOMATIC) Mcu_u32ModuleDisableConfiguration)
{
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32( LPU_MDIS_ADDR32, (Mcu_u32ModuleDisableConfiguration & LPU_MDIS_RWBITS_MASK32) | LPU_MDIS_RESBITS_MASK32 );
}

/**
* @brief            This function configures the peripherals in LPU modes.
* @details          This function configures the module disable register (LPU_MIDS).
*                   If a module is disabled in RUN mode using ME_PCTL, it is suggested to configure
*                   MDIS to 1 in LPU modes as by default the clock to that module will be enabled while
*                   transitioning to LPU mode.
*                   Called by:
*                       - Mcu_LPU_LowPowerModeConfig() from Mcu_LPU.
*
* @param[in]        Mcu_u32InterruptConfiguration   Enabled interrupts.
*
* @return           void
*
*/
static FUNC( void, MCU_CODE) Mcu_LPU_ConfigureInterrupts(VAR(uint32, AUTOMATIC) Mcu_u32InterruptConfiguration)
{
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32(LPU_ICR_ADDR32, LPU_ICR_INT_ENABLE(Mcu_u32InterruptConfiguration));
}

/**
* @brief            This function activate the transition to a new LPU mode.
* @details          This function set the LPU_MCTL register to load the mode configuration from one of the LPU_<mode>_CF registers.
*                   Called by:
*                       - Mcu_LPU_LowPowerModeConfig() from this file
*
* @param[in]        eLowPowerMode   Code of the LPU mode that is mapped to LPU_MCTL register.
*
* @return           void
*
*/
static FUNC( void, AUTOMATIC) Mcu_LPU_ApplyMode(VAR(Mcu_LpuModeType, MCU_VAR) eLowPowerMode)
{
    /* Configuration register value calculated based input parameter. */
    VAR( uint32, AUTOMATIC) u32LpuModeConfig = 0U;
    /* Timeout value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32TimeOut = MCU_TIMEOUT_LOOPS;
    
    u32LpuModeConfig = (uint32)eLowPowerMode << (uint32)28U;
    /* Mode transition is performed by writing LPU_MCTL register twice:
        - 1st write: TARGET_MODE + KEY
        - 2nd write: TARGET_MODE + INVERTED KEY */
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32( LPU_MCTL_ADDR32, ((uint32)u32LpuModeConfig | (uint32)LPU_MCTL_DIRECT_KEY_U32) );
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32( LPU_MCTL_ADDR32, ((uint32)u32LpuModeConfig | (uint32)LPU_MCTL_INVERTED_KEY_U32) );

    /* The mode transition request may require a number of cycles depending on the programmed configuration,
        and software should check the CURRENT_MODE bit field and the MTRANS bit of the global status register
        LPU_SR to verify when the mode has been correctly entered and the transition process has completed. */
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    while (((uint32)LPU_SR_MTRANS_MASK32 == (REG_READ32( LPU_SR_ADDR32 ) & (uint32)LPU_SR_MTRANS_MASK32)) &&
           (u32TimeOut > (uint32)0x0U)
          )
    {
        /* (LPU_SR[MTRANS]=1) <=> (Transition ongoing). */
        u32TimeOut--;
    }

    if ( (uint32)0x0U == u32TimeOut)
    {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief            This function initializes the mode structure.
* @details          This function intializes the mode structure by configuring the LPU module.
*                   The target mode is requested by accessing the LPU_MCTL register with the required keys. This mode transition
*                   request by software must be a valid request satisfying a set of pre-defined rules to initiate the process.
*                   Called by:
*                       - Mcu_IPW_SetMode() from IPW.
*
* @param[in]        Mcu_pLowPowerModeConfigPtr   Pointer to low powermode configuration structure.
*
* @return           void
*
*/
/** @violates @ref Mcu_LPU_c_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function. */
FUNC( void, MCU_CODE) Mcu_LPU_LowPowerModeConfig(P2CONST(Mcu_LPU_LowPowerModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pLowPowerModeConfigPtr)
{
    Mcu_LPU_ConfigureInterrupts( (uint32)Mcu_pLowPowerModeConfigPtr->u32LpuInterrupts );
    Mcu_LPU_ConfigureModuleDisable( (uint32)Mcu_pLowPowerModeConfigPtr->u32LpuModuleDisable );

    /* Mcu_LowPowerMode should be in the range of "Mcu_LpuModeType" enumeration values. */
    switch (Mcu_pLowPowerModeConfigPtr->Mcu_eLowPowerMode)
    {
        case (MCU_LPU_RUN_MODE):
            /* LPU RUN mode */
            
            /* Set the new configuration for the mode. */
            /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
            /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
            REG_WRITE32( LPU_RUN_CF_ADDR32, (uint32)Mcu_pLowPowerModeConfigPtr->u32LpuModeParams );

            /* Apply the new mode using above configuration. */
            Mcu_LPU_ApplyMode( MCU_LPU_RUN_MODE );
            break;
            
        case (MCU_LPU_STOP_MODE):
            /* LPU STOP mode */
            
            /* Set the new configuration for the mode. */
            /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
            /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
            REG_WRITE32( LPU_STOP_CF_ADDR32, (uint32)Mcu_pLowPowerModeConfigPtr->u32LpuModeParams );

            /* Apply the new mode using above configuration. */
            Mcu_LPU_ApplyMode( MCU_LPU_STOP_MODE );
            break;
            
        case (MCU_LPU_STANDBY_MODE):
            /* LPU STANDBY mode */
            
            /* Set the new configuration for the mode. */
            /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
            /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
            REG_WRITE32( LPU_STANDBY_CF_ADDR32, (uint32)Mcu_pLowPowerModeConfigPtr->u32LpuModeParams );

            /* Apply the new mode using above configuration. */
            Mcu_LPU_ApplyMode( MCU_LPU_STANDBY_MODE );
            break;
            
        default:
            /* Default case - should never enter here. */

            break;
    }
}


#if (MCU_LPU_INVALID_MODE_ISR_USED == STD_ON)
/**
* @brief            This function handles the LPU interrupts.
*
* @return           void
*/
FUNC( void, MCU_CODE) Mcu_LPU_InvalidModeIsr( VAR( void, AUTOMATIC) )
{
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC)   u32InterruptEnable;
#endif
    VAR( uint32, AUTOMATIC)   u32InterruptStatus;
    VAR( uint32, AUTOMATIC)   u32ModeRequestIgnored;

    /* get IRQ flags */
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    u32InterruptStatus = (REG_READ32(LPU_ICR_ADDR32) & LPU_ICR_LPU_NEM_MASK32);

    /* clear isr flags */
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32( LPU_ICR_ADDR32, u32InterruptStatus);

    /* get the invalid mode status and clear the bits*/
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    u32ModeRequestIgnored = REG_READ32(LPU_ICR_ADDR32) & LPU_ICR_LPU_MRIG_MASK32;
    /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
    /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_WRITE32( LPU_ICR_ADDR32, u32ModeRequestIgnored);

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /** @violates @ref Mcu_LPU_c_REF_3 MISRA 2004 Required Rule 11.1, conversion form pointer to integer*/
        /** @violates @ref Mcu_LPU_c_REF_5 The cast is used to access memory mapped registers.*/
        u32InterruptEnable = REG_READ32(LPU_ICR_ADDR32);
        
        if ( LPU_ICR_LPU_NEM_MASK32 == ( LPU_ICR_LPU_NEM_MASK32 & u32InterruptStatus ))
        {
            if (LPU_ICR_LPU_NEM_E_MASK32 == ( LPU_ICR_LPU_NEM_E_MASK32 & u32InterruptEnable))
            {
                /* Invalid mode transition interrupt can have many sources. */
                /* report an event if any of it's sources are visible */

                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_INVALID_MODE);
            }
        }
    }
#endif
}
#endif /* (MCU_LPU_INVALID_MODE_ISR_USED == STD_ON) */


#endif

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_LPU_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_LPU_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

