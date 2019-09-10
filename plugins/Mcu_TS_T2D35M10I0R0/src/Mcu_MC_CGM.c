/**
*   @file    Mcu_MC_CGM.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Clock Generation Module functions implementation.
*   @details Specific functions for MC_CGM configuration and control.
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
* @section Mcu_MC_CGM_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_MC_CGM_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory
* section
*
* @section Mcu_MC_CGM_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_MC_CGM_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any other type than an integral type. Specific for accessing memory-mapped
* registers
*
* @section Mcu_MC_CGM_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_MC_CGM_c_REF_6
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
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu_MC_CGM.h"
#include "Mcu_MC_ME.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_MC_CGM_VENDOR_ID_C                      43
/** @violates @ref Mcu_MC_CGM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION_C       4
/** @violates @ref Mcu_MC_CGM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_MC_CGM_AR_RELEASE_MINOR_VERSION_C       2
/** @violates @ref Mcu_MC_CGM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_MC_CGM_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_MC_CGM_SW_MAJOR_VERSION_C               1
#define MCU_MC_CGM_SW_MINOR_VERSION_C               0
#define MCU_MC_CGM_SW_PATCH_VERSION_C               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_MC_CGM header file are of the same vendor */
#if (MCU_MC_CGM_VENDOR_ID_C != MCU_MC_CGM_VENDOR_ID)
    #error "Mcu_MC_CGM.c and Mcu_MC_CGM.h have different vendor ids"
#endif
/* Check if current file and Mcu_MC_CGM header file are of the same Autosar version */
#if ((MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_CGM_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_CGM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_CGM_AR_RELEASE_REVISION_VERSION_C != MCU_MC_CGM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_CGM.c and Mcu_MC_CGM.h are different"
#endif
/* Check if current file and Mcu_MC_CGM header file are of the same Software version */
#if ((MCU_MC_CGM_SW_MAJOR_VERSION_C != MCU_MC_CGM_SW_MAJOR_VERSION) || \
     (MCU_MC_CGM_SW_MINOR_VERSION_C != MCU_MC_CGM_SW_MINOR_VERSION) || \
     (MCU_MC_CGM_SW_PATCH_VERSION_C != MCU_MC_CGM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_CGM.c and Mcu_MC_CGM.h are different"
#endif

/* Check if current file and Mcu_MC_ME header file are of the same vendor */
#if (MCU_MC_CGM_VENDOR_ID_C != MCU_MC_ME_VENDOR_ID)
    #error "Mcu_MC_CGM.c and Mcu_MC_ME.h have different vendor ids"
#endif
/* Check if current file and Mcu_MC_ME header file are of the same Autosar version */
#if ((MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_ME_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_CGM_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_ME_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_CGM_AR_RELEASE_REVISION_VERSION_C != MCU_MC_ME_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_CGM.c and Mcu_MC_ME.h are different"
#endif
/* Check if current file and Mcu_MC_ME header file are of the same Software version */
#if ((MCU_MC_CGM_SW_MAJOR_VERSION_C != MCU_MC_ME_SW_MAJOR_VERSION) || \
     (MCU_MC_CGM_SW_MINOR_VERSION_C != MCU_MC_ME_SW_MINOR_VERSION) || \
     (MCU_MC_CGM_SW_PATCH_VERSION_C != MCU_MC_ME_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_CGM.c and Mcu_MC_ME.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_CGM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_CGM.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_CGM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_CGM.c and SilRegMacros.h are different"
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


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_MC_CGM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#if (MCU_INIT_CLOCK == STD_ON)

#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
*/
FUNC( void, MCU_CODE) Mcu_MC_CGM_SetUserAccessAllowed(void)
{
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    SET_USER_ACCESS_ALLOWED(MC_CGM_BASEADDR);
}
#endif
#endif

#if (IPV_MC == IPV_MC_06_00_00_10)
/**
* @brief            This function will configure PLL clock sources
*/
FUNC( void, MCU_CODE) Mcu_SRC_ConfigPllClockSources(VAR( Mcu_SRC_ConfigType, MCU_VAR) SRC_ClockConfig)
{
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_RMW32(SRC_GPR1_ADDR32, SRC_ClockConfig.u32RegisterMask, SRC_ClockConfig.u32RegisterData);
}
#endif


/**
* @brief            This function will configure prog. clock switching
*/
FUNC( void, MCU_CODE) Mcu_MC_CGM_ProgClockSwitchConfig(P2CONST( Mcu_MC_CGM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) MC_CGM_pClockConfigPtr)
{
    /* local vars */
    VAR(uint32, AUTOMATIC) u32Counter;

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* the SDUR values will be generated in the prog clock switch pointer array */ 
#else
    /* this register is always here, so no need to add it to the array */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE8( MC_CGM_PCS_SDUR_ADDR8, MC_CGM_pClockConfigPtr->u8ProgClkSwitch );
#endif

    /* now write the available PCS registers */
    for ( u32Counter = (uint32)0x00U; u32Counter < (uint32)(MC_CGM_pClockConfigPtr->u8NoOfProgSwitchUnderMcuControl); u32Counter++)
    {
        /* for all pairs write them to harware */
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32 \
        ( \
            (*MC_CGM_pClockConfigPtr->apPcsClockConfig)[u32Counter].u32RegisterAddr,\
            (*MC_CGM_pClockConfigPtr->apPcsClockConfig)[u32Counter].u32RegisterData \
        );
    }

}


/**
* @brief            This function will configure the system clock tree
*
* @details          This function will configure the system clock switch(es) and dividers
*
*/
FUNC( void, MCU_CODE) Mcu_MC_CGM_SystemClockConfig(P2CONST( Mcu_MC_CGM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) MC_CGM_pClockConfigPtr)
{
    VAR(uint32, AUTOMATIC) u32Counter;
#if (IPV_MC == IPV_MC_04_06_05_00)
    VAR(uint32, AUTOMATIC) u32SysClkDivider = 0x00U;
    VAR(uint32, AUTOMATIC) u32CurrentSysClkDivider = 0x00U;
    VAR(uint32, AUTOMATIC) u32NewSysClkDivider = 0x00U;
#endif    
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_01_00_00))
    VAR(uint32, AUTOMATIC) u32RegValue;
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #if (MCU_UPDATE_TRIGGER_PRESENT == STD_ON)
        VAR(uint32, AUTOMATIC) u32RegValue;
    #endif
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_01_00) ||
           (IPV_MC == IPV_MC_04_01_00_00)) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_01_00_00))
    /* mark the system clock update as a divider ratio change */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_CGM_SC_DIV_RC_ADDR32, MC_CGM_SC_DIV_RC_SYS_DIV_RATIO_CHNG_EN_U32 );
    /* mark system clock update as a triggered one */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32RegValue = REG_READ32( MC_CGM_DIV_UPD_TYPE_ADDR32 );
    /* update only system clock */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_CGM_DIV_UPD_TYPE_ADDR32, MC_CGM_DIV_UPD_TYPE_SYS_UPD_TYPE_EN_U32 );
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #if (MCU_UPDATE_TRIGGER_PRESENT == STD_ON)
        /* mark the system clock update as a divider ratio change */
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32( MC_CGM_SC_DIV_RC_ADDR32, MC_CGM_SC_DIV_RC_SYS_DIV_RATIO_CHNG_EN_U32 );
        /* mark system clock update as a triggered one */
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        u32RegValue = REG_READ32( MC_CGM_DIV_UPD_TYPE_ADDR32 );
        /* update only system clock */
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32( MC_CGM_DIV_UPD_TYPE_ADDR32, MC_CGM_DIV_UPD_TYPE_SYS_UPD_TYPE_EN_U32 );
    #endif
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_01_00) ||
           (IPV_MC == IPV_MC_04_01_00_00)) */

    /* This step to make sure the secondary core freq is always greater than system freq (core 0)
       or equal at least, and smaller than the maximum allowed frequency */
#if (IPV_MC == IPV_MC_04_06_05_00)
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
/** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32CurrentSysClkDivider = (uint32)(REG_READ32(MC_CGM_SC_DC0_ADDR32) & MC_CGM_SC_DC0_DIV_RWBITS_MASK32);
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32NewSysClkDivider = (uint32)(*MC_CGM_pClockConfigPtr->apSystemClockConfig)[0].u32RegisterData & MC_CGM_SC_DC0_DIV_RWBITS_MASK32;
    
    if(u32CurrentSysClkDivider <= u32NewSysClkDivider)
    {
        u32SysClkDivider = u32CurrentSysClkDivider | MC_CGM_SC_DC0_DIV_RESBITS_MASK32; 
    }
    else
    {
        u32SysClkDivider = u32NewSysClkDivider | MC_CGM_SC_DC0_DIV_RESBITS_MASK32;
    }
    /* reset core 1 DIV */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_SC_DC1_ADDR32, (uint32)u32SysClkDivider);
    /* reset core 2 DIV */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_SC_DC2_ADDR32, (uint32)u32SysClkDivider);
#endif
    
    /* now write the available system clock registers through clock configuration */
    for ( u32Counter = (uint32)0x00U; u32Counter < (uint32)(MC_CGM_pClockConfigPtr->u8NoOfSysClockUnderMcuControl); u32Counter++)
    {
        /* for all pairs write them to harware */
        /* add eratas, etc here */
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32 \
        ( \
            (*MC_CGM_pClockConfigPtr->apSystemClockConfig)[u32Counter].u32RegisterAddr,\
            (*MC_CGM_pClockConfigPtr->apSystemClockConfig)[u32Counter].u32RegisterData \
        );
    }

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_01_00_00))
    /* trigger an update */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_DIV_UPD_TRIG_ADDR32, MC_CGM_DIV_UPD_TYPE_SYS_UPD_TYPE_EN_U32);
    /* restore register value */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_DIV_UPD_TYPE_ADDR32, u32RegValue);
#elif (IPV_MC == IPV_MC_04_06_05_00)
    #if (MCU_UPDATE_TRIGGER_PRESENT == STD_ON)
    /* trigger an update */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_DIV_UPD_TRIG_ADDR32, MC_CGM_DIV_UPD_TYPE_SYS_UPD_TYPE_EN_U32);
    /* restore register value */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_DIV_UPD_TYPE_ADDR32, u32RegValue);
    #endif
#endif /* ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_06_01_00) ||
           (IPV_MC == IPV_MC_04_01_00_00)) */
           
#if (IPV_MC == IPV_MC_06_00_00_10)
    /* now write the available system clock registers */
    for ( u32Counter = (uint32)0x00U; u32Counter < (uint32)(MC_CGM_pClockConfigPtr->u8NoOfSecondarySysClockUnderMcuControl); u32Counter++)
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE32 \
        ( \
            (*MC_CGM_pClockConfigPtr->apSecondarySystemClockConfig)[u32Counter].u32RegisterAddr,\
            (*MC_CGM_pClockConfigPtr->apSecondarySystemClockConfig)[u32Counter].u32RegisterData \
        );
    }
#endif 
}


/**
* @brief            This function will configure the peripheral clock tree
*
* @details          This function will configure the peripheral clock switches and dividers
*
*/
FUNC( void, MCU_CODE) Mcu_MC_CGM_AuxClockConfig(P2CONST( Mcu_MC_CGM_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) MC_CGM_pClockConfigPtr)
{
    /* local variables */
    VAR(uint32, AUTOMATIC) u32Counter;
#if (IPV_MC == IPV_MC_04_06_05_00)
    VAR(uint32, AUTOMATIC) u32ClockoutMaskValue = 0x0U;
    VAR(uint32, AUTOMATIC) u32ClockoutSelectValue = 0x0U;
#endif

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_05_00_00_07) || (IPV_MC == IPV_MC_06_00_00_10) \
    )
    VAR(uint32, AUTOMATIC) u32RegValue;
#endif /* ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_06_01_00)) */

#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_07))
    /* perform a triggered update */
    /* prepare it by updating the MC_CGM_DIV_UPD_TYPE register for all used peripherals */
    /* take care not to touch registers unused by the mcu driver */
    /* I need to do this every time because I don't know if it's the firs or nth call of
    Mcu_InitClock */
    /* get the original value - so not to bother other code */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32RegValue = REG_READ32( MC_CGM_DIV_UPD_TYPE_ADDR32 );
    /* mark aux. sources that will be updated */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_DIV_UPD_TYPE_ADDR32, MC_CGM_pClockConfigPtr->u32AuxDividerUpdateTriggerMask);
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
/** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32RegValue = REG_READ32( MC_CGM_0_DIV_UPD_TYPE_ADDR32 );
    /* mark aux. sources that will be updated */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_0_DIV_UPD_TYPE_ADDR32, MC_CGM_pClockConfigPtr->u32AuxDividerUpdateTriggerMask);
#endif /* ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_06_01_00)) */


    /* now write the available system clock registers */
    for (u32Counter = (uint32)0x00U; u32Counter < (uint32)(MC_CGM_pClockConfigPtr->u8NoAuxClockUnderMcuControl) ; u32Counter++)
    {
        /* for all pairs write them to harware */
        /* add eratas, etc here */
        /* do other stuff */
#if (IPV_MC == IPV_MC_04_06_05_00)
        /* the address for MC_CGM_AC9_SC_ADDR32 is intentionally wrong in the Reg_eSys file, */
        /* but the value is written to the correct address */
        /* this is for differentiating the values for AC9 and AC14 */
        if ( MC_CGM_AC9_SC_ADDR32 == (uint32)(*MC_CGM_pClockConfigPtr->apAuxClockConfig)[u32Counter].u32RegisterAddr)
        {
            u32ClockoutMaskValue |= MC_CGM_AC9_SC_SELCTL_MASK32;
            u32ClockoutSelectValue |= (*MC_CGM_pClockConfigPtr->apAuxClockConfig)[u32Counter].u32RegisterData;
        }
        else if( MC_CGM_AC14_SC_ADDR32 == (uint32)(*MC_CGM_pClockConfigPtr->apAuxClockConfig)[u32Counter].u32RegisterAddr)
        {
            u32ClockoutMaskValue |= MC_CGM_AC14_SC_SELCTL_MASK32;
            u32ClockoutSelectValue |= (*MC_CGM_pClockConfigPtr->apAuxClockConfig)[u32Counter].u32RegisterData;
        }
        else
        {
#endif
            /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
            /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
            REG_WRITE32 \
            ( \
                (*MC_CGM_pClockConfigPtr->apAuxClockConfig)[u32Counter].u32RegisterAddr,\
                (*MC_CGM_pClockConfigPtr->apAuxClockConfig)[u32Counter].u32RegisterData \
            );
#if (IPV_MC == IPV_MC_04_06_05_00)
        }
#endif
    }
#if (IPV_MC == IPV_MC_04_06_05_00)
    if ( (uint32)0x0U != u32ClockoutMaskValue )
    {
        #if (MCU_UPDATE_TRIGGER_PRESENT == STD_ON)
            u32ClockoutMaskValue |= MCB_CGM_SINK_SEL_MASK32;
        #endif
        /* the values for AC9 and AC14 select bits are written to the correct address */
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_RMW32( MC_CGM_AC14_SC_ADDR32, u32ClockoutMaskValue, u32ClockoutSelectValue );
    }
#endif
#if ((IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_05_00_00_07))
    /* update */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_CGM_DIV_UPD_TRIG_ADDR32, MC_CGM_pClockConfigPtr->u32AuxDividerUpdateTriggerMask);
    /* restore value */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_CGM_DIV_UPD_TYPE_ADDR32, u32RegValue );
#elif (IPV_MC == IPV_MC_06_00_00_10)
    /* update */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(MC_CGM_0_DIV_UPD_TYPE_ADDR32, MC_CGM_pClockConfigPtr->u32AuxDividerUpdateTriggerMask);
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_CGM_0_DIV_UPD_TYPE_ADDR32, u32RegValue );
#endif
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_INIT_CLOCK == STD_ON)
#if (IPV_MC == IPV_MC_04_06_05_00)
/**
* @brief            This function will check if all ACn_SC registers are under or equal to the
*                   requested clock source. If not, it will update ACn_SS to point to clock source
*                   given by u32McuMaxClockMode. This is requested because some MC_ME
*                   implementation will not check the DE bit for each divider, thus stalling clock
*                   tree reconfiguration even if a specific clock source is not actualy linked to
*                   any peripherals
*
* @param[in]        u32McuMaxClockMode the max. available clock value, already shifted to the
*                   SELSTAT position
*
* @return           void
*
*/
/** @violates @ref Mcu_MC_CGM_c_REF_5 Global declaration of function. */
FUNC( void, MCU_CODE) Mcu_MC_CGM_PeriphClkPrepareForSwitch(VAR( uint32, AUTOMATIC ) u32McuMaxClockMode)
{
    VAR( uint32, AUTOMATIC) u32SelStat = 0U;
    /* the check is done by directly comparing the ACn_SS selstat field to the u32McuMaxClockMode
    value */

    /* for this platform the following ACn_SC registers are checked and updated */
    /* AC0_SS */
    /* get the current clock */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC0_SS_ADDR32) & MC_CGM_AC0_SS_SELSTAT_MASK32;
    /* compare it against the max. clock source */
    /* this works because clock sources are in linear progresion related to how they are */
    /* disabled or enabled */
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /* drop it down to u32McuMaxClockMode + extra check */
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC0_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC0_SC_SELCTL_MASK32);
    }

    /* AC1_SS */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC1_SS_ADDR32) & MC_CGM_AC1_SS_SELCTL_MASK32;
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC1_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC1_SC_SELCTL_MASK32);
    }

    /* AC2_SS */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC2_SS_ADDR32) & MC_CGM_AC2_SS_SELCTL_MASK32;
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC2_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC2_SC_SELCTL_MASK32);
    }

    /* skip AC3 and AC4 */

    /* AC7_SS */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC7_SS_ADDR32) & MC_CGM_AC7_SS_SELSTAT_MASK32;
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC7_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC7_SC_SELCTL_MASK32);
    }

    /* AC8_SS */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC8_SS_ADDR32) & MC_CGM_AC8_SS_SELSTAT_MASK32;
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC8_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC8_SC_SELCTL_MASK32);
    }

    /* skip AC9 */

    /* AC10_SS */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC10_SS_ADDR32) & MC_CGM_AC10_SS_SELSTAT_MASK32;
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC10_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC10_SC_SELCTL_MASK32);
    }

    /* AC11_SS */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC11_SS_ADDR32) & MC_CGM_AC11_SS_SELSTAT_MASK32;
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC11_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC11_SC_SELCTL_MASK32);
    }

    /* AC12_SS */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC12_SS_ADDR32) & MC_CGM_AC12_SS_SELSTAT_MASK32;
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC12_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC12_SC_SELCTL_MASK32);
    }

    /* AC13_SS */
    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32SelStat = REG_READ32(MC_CGM_AC13_SS_ADDR32) & MC_CGM_AC13_SS_SELSTAT_MASK32;
    if ( u32SelStat > u32McuMaxClockMode )
    {
        /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
        /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE_LOCK32( MC_CGM_BASEADDR, MC_CGM_AC13_SC_ADDR32, u32McuMaxClockMode & MC_CGM_AC13_SC_SELCTL_MASK32);
    }

    /* skip AC14 */

    /* skip AC15 - NO SS reg. defined */
}
#endif /* (IPV_MC == IPV_MC_04_06_05_00) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#ifdef MCU_GET_INTERNAL_STATE
#if (IPV_MC == IPV_MC_04_06_01_00)
/**
* @brief            This function will check the divider enable bit of Aux Clock 5 Divider
*                   Configuration 1. We have to check the clock source of the EMIOSs before
*                   accessing to them.
*
* @param[in]        void
*
* @return           Std_ReturnType
*
*/
FUNC(Std_ReturnType, MCU_CODE) Mcu_MC_CGM_GetEmiosClockState(VAR( void, AUTOMATIC))
{
    VAR(uint32, AUTOMATIC) u32RegValue;
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_NOT_OK;

    /** @violates @ref Mcu_MC_CGM_c_REF_4 Conversion from pointer to integer */
    /** @violates @ref Mcu_MC_CGM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32RegValue = REG_READ32(MC_CGM_AC5_DC1_ADDR32);
    if (MC_CGM_AUXCLK5_DIV1_EN_U32 == (u32RegValue & MC_CGM_AC5_DC1_DE_MASK32))
    {
        CheckStatus = (Std_ReturnType)E_OK;
    }
    return (Std_ReturnType)CheckStatus;
}
#endif /* (IPV_MC == IPV_MC_04_06_01_00) */
#endif /* MCU_GET_INTERNAL_STATE */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_MC_CGM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_MC_CGM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
