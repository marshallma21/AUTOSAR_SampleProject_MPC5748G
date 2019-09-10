/**
*   @file    Mcu_FLASH.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - FLASH functions implementation.
*   @details Specific functions for FLASH Controller configuration and control.
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
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_FLASH_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_FLASH_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include files.  Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation
* since all header files are protected against multiple inclusions
*
* @section Mcu_FLASH_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_FLASH_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
* pointer to a function and a type other than an integral type. This violation is due to the
* pointer arithmetic used to write/ read the data to/from the registers
*
* @section Mcu_FLASH_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is requiered
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_FLASH_c_REF_6
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
#include "Mcu_FLASH.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_FLASH_VENDOR_ID_C                       43
/** @violates @ref Mcu_FLASH_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_FLASH_AR_RELEASE_MAJOR_VERSION_C        4
/** @violates @ref Mcu_FLASH_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_FLASH_AR_RELEASE_MINOR_VERSION_C        2
/** @violates @ref Mcu_FLASH_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_FLASH_AR_RELEASE_REVISION_VERSION_C     2
#define MCU_FLASH_SW_MAJOR_VERSION_C                1
#define MCU_FLASH_SW_MINOR_VERSION_C                0
#define MCU_FLASH_SW_PATCH_VERSION_C                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_FLASH.h file are of the same vendor */
#if (MCU_FLASH_VENDOR_ID_C != MCU_FLASH_VENDOR_ID)
    #error "Mcu_FLASH.c and Mcu_FLASH.h have different vendor ids"
#endif
/* Check if current file and Mcu_FLASH.h file are of the same Autosar version */
#if ((MCU_FLASH_AR_RELEASE_MAJOR_VERSION_C != MCU_FLASH_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_FLASH_AR_RELEASE_MINOR_VERSION_C != MCU_FLASH_AR_RELEASE_MINOR_VERSION) || \
     (MCU_FLASH_AR_RELEASE_REVISION_VERSION_C != MCU_FLASH_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FLASH.c and Mcu_FLASH.h are different"
#endif
/* Check if current file and Mcu_FLASH.h file are of the same Software version */
#if ((MCU_FLASH_SW_MAJOR_VERSION_C != MCU_FLASH_SW_MAJOR_VERSION) || \
     (MCU_FLASH_SW_MINOR_VERSION_C != MCU_FLASH_SW_MINOR_VERSION) || \
     (MCU_FLASH_SW_PATCH_VERSION_C != MCU_FLASH_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FLASH.c and Mcu_FLASH.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_FLASH_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_FLASH_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_FLASH.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_FLASH_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_FLASH_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_FLASH.c and SilRegMacros.h are different"
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


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_RAMCODE
/**
* @violates @ref Mcu_FLASH_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
/** @violates @ref Mcu_FLASH_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include files.  */
#include "Mcu_MemMap.h"

#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
static FUNC(void, MCU_RAM_CODE) Mcu_FLASH_InitRam (P2CONST( Mcu_FLASH_ConfigType, AUTOMATIC, MCU_APPL_CONST) FLASH_pConfigPtr);
#endif

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
/* Set the Flash Wait States. */
static FUNC(void, MCU_RAM_CODE) Mcu_FLASH_SetWsRam (P2CONST(Mcu_FLASH_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) FLASH_pClockConfigPtr);
#endif /* (MCU_DISABLE_FLASH_CONFIG == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#define MCU_STOP_SEC_RAMCODE
/**
* @violates @ref Mcu_FLASH_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
* @violates @ref Mcu_FLASH_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_FLASH_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
* @violates @ref Mcu_FLASH_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Mcu_MemMap.h"

#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
P2FUNC(void, MCU_CODE, Mcu_FLASH_Init) (P2CONST(Mcu_FLASH_ConfigType, AUTOMATIC, MCU_APPL_DATA) FLASH_pConfigPtr) = &Mcu_FLASH_InitRam;
#endif


#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
/* Pointer to function that configure the wait states. */
P2FUNC(void, MCU_CODE, Mcu_FLASH_SetWS) (P2CONST(Mcu_FLASH_ClockConfigType, AUTOMATIC, MCU_APPL_DATA) FLASH_pClockConfigPtr) = &Mcu_FLASH_SetWsRam;
#endif /* (MCU_DISABLE_FLASH_CONFIG == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_FLASH_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
/** @violates @ref Mcu_FLASH_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include files.  */
#include "Mcu_MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#define MCU_START_SEC_RAMCODE
/**
* @violates @ref Mcu_FLASH_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
/** @violates @ref Mcu_FLASH_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include files.  */
#include "Mcu_MemMap.h"

/*
!!!CAUTION for Registers:
    Software executing from flash memory must not write to registers that
        control flash behavior (such as wait state settings or prefetch
        enable/disable). Doing so can cause data corruption.
    Flash memory configuration registers should be written only with 32-bit
        write operations to avoid any issues associated with register incoherency
        caused by bit fields spanning smaller size (8-, 16-bit) boundaries.

    XPC56XXL: IPV_FLASHV2== IPV_FLASH_C90FL3_1024_6_0
    XPC56XXL has configuration only for Code Flash.
*/

#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
/**
* @brief            This function initializes global settings for the Flash memory.
* @details          Config Page Buffer Configuration, Data Prefetch Enable, Instruction
*                   Prefetch Enable, Prefetch Limit, Buffer Enable, Arbitration Mode, Master
*                   Prefetch Disable, Master Access Protection.
*                   Called by:
*                       - Mcu_Ipw_Init() from IPW.
*
* @param[in]        FLASH_pConfigPtr   Pointer to Flash configuration structure.
*
* @return           void
*
*/
static FUNC(void, MCU_RAM_CODE) Mcu_FLASH_InitRam(P2CONST( Mcu_FLASH_ConfigType, AUTOMATIC, MCU_APPL_CONST) FLASH_pConfigPtr)
{
#if (IPV_FLASHV2 == IPV_FLASH_00_00_05_01)
    /* Set the PFCR0 register, but except wait-state values which are configured by clock
    initialization. */
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_RMW32 \
    ( \
        FLASHC_PFCR0_ADDR32, \
        ( \
            MCU_FLASH_B02P1BCFG_MASK32 | MCU_FLASH_B02P1DPFE_MASK32 | \
            MCU_FLASH_B02P1IPFE_MASK32 | MCU_FLASH_B02P1PFLM_MASK32 | \
            MCU_FLASH_B02P1BFE_MASK32  | MCU_FLASH_B02P0BCFG_MASK32 | \
            MCU_FLASH_B02P0DPFE_MASK32 | MCU_FLASH_B02P0IPFE_MASK32 | \
            MCU_FLASH_B02P0PFLM_MASK32 | MCU_FLASH_B02P0BFE_MASK32 \
        ), \
        (uint32)(FLASH_pConfigPtr->u32FlashConfig) \
    );

    /* Set the Flash access protection register. */
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLASHC_PFAPR_ADDR32, (uint32)(FLASH_pConfigPtr->u32FlashAccess));
#elif ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || \
       (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || \
       (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || \
       (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
      )
    /* Write all bits excepting wait states configuration. */
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_RMW32 \
    ( \
        FLASHC_PFCR1_ADDR32, \
        (~( FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32 ) ), \
        (uint32)(FLASH_pConfigPtr->u32FlashConfig1) \
    );

    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLASHC_PFCR2_ADDR32, (uint32)(FLASH_pConfigPtr->u32FlashConfig2));
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLASHC_PFCR3_ADDR32, (uint32)(FLASH_pConfigPtr->u32FlashConfig3));
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLASHC_PFAPR_ADDR32, (uint32)(FLASH_pConfigPtr->u32FlashAccess));
#elif (IPV_FLASHV2== IPV_FLASH_25_60_86_00)
    /* Write all bits excepting wait states configuration. */
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_RMW32 \
    ( \
        FLASHC_PFCR1_ADDR32, \
        (~( FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32 ) ), \
        (uint32)(FLASH_pConfigPtr->u32FlashConfig1) \
    );
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLASHC_PFCR3_ADDR32, (uint32)(FLASH_pConfigPtr->u32FlashConfig3));
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLASHC_PFAPR_ADDR32, (uint32)(FLASH_pConfigPtr->u32FlashAccess));
#endif /* ((IPV_FLASHV2== IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_01_00_08_02)) */
#if ((IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || (IPV_FLASHV2 == IPV_FLASH_40_96_55_46))
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLASHC_PFCR4_ADDR32, (uint32)(FLASH_pConfigPtr->u32FlashConfig4));
#endif
}
#endif

#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)

/**
* @brief            This function configure PFCR00 register from FLASH controller.
* @details          Set Pipeline/Write/Read wait-states.
*                   The fields APC, WWSC and RWSC of the PFCR0 register should be set to the same
*                   value.
*                   Called by:
*                       - Mcu_Ipw_InitClock() from IPW.
*
* @param[in]        FLASH_pClockConfigPtr   Pointer to ECSM configuration structure.
*
* @return           void
*
*/
static FUNC(void, MCU_RAM_CODE) Mcu_FLASH_SetWsRam (P2CONST( Mcu_FLASH_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) FLASH_pClockConfigPtr)
{
#if ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || \
     (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || \
     (IPV_FLASHV2 == IPV_FLASH_25_60_86_00) || (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || \
     (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || \
     (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
    )
    VAR( uint32, AUTOMATIC) u32CurrentFlashConfig ;

#endif /* ((IPV_FLASHV2== IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) ||
           (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) ||
           (IPV_FLASHV2== IPV_FLASH_25_60_86_00)) */

#if (IPV_FLASHV2== IPV_FLASH_00_00_05_01)
    /* Set the AddressPipelining/Write/Read Wait State Control. */
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_RMW32 \
    ( \
        FLASHC_PFCR0_ADDR32, \
        (MCU_FLASH_B02APC_MASK32 | MCU_FLASH_B02WWSC_MASK32 | MCU_FLASH_B02RWSC_MASK32), \
        FLASH_pClockConfigPtr->u32FlashWS \
    );
#elif ((IPV_FLASHV2 == IPV_FLASH_40_96_55_19) || (IPV_FLASHV2 == IPV_FLASH_01_00_08_02) || \
       (IPV_FLASHV2 == IPV_FLASH_01_00_03_05) || (IPV_FLASHV2 == IPV_FLASH_42_56_55_38) || \
       (IPV_FLASHV2 == IPV_FLASH_25_60_86_00) || (IPV_FLASHV2 == IPV_FLASH_62_72_55_39) || \
       (IPV_FLASHV2 == IPV_FLASH_84_80_32_02) || (IPV_FLASHV2 == IPV_FLASH_20_48_55_46) || \
       (IPV_FLASHV2 == IPV_FLASH_40_96_55_46) \
      )
    /* get the current flash config */
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    u32CurrentFlashConfig = REG_READ32( FLASHC_PFCR1_ADDR32 );
    u32CurrentFlashConfig &= (uint32)(~(uint32)(FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32));

#ifdef ERR_IPV_FLASH_0015
#if (STD_ON == ERR_IPV_FLASH_0015)
    u32CurrentFlashConfig |= (uint32)(FLASHC_PFCR1_RWSC_MASK32 & FLASH_pClockConfigPtr->u32FlashWS);
    u32CurrentFlashConfig |= MCU_FLASH_ADDR_PIPELINE_WS_U32(MCU_FLASH_ADDR_PIPELINE_WS_DIS_U32);
#else
    u32CurrentFlashConfig |= (uint32)((FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32) & FLASH_pClockConfigPtr->u32FlashWS);
#endif /* (STD_ON == ERR_IPV_FLASH_0015) */
#else
    u32CurrentFlashConfig |= (uint32)((FLASHC_PFCR1_APC_MASK32 | FLASHC_PFCR1_RWSC_MASK32) & FLASH_pClockConfigPtr->u32FlashWS);
#endif /* ERR_IPV_FLASH_0015 */

    /* Set the AddressPipelining/Write/Read Wait State Control. */
    /** @violates @ref Mcu_FLASH_c_REF_4 Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FLASH_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE32(FLASHC_PFCR1_ADDR32, u32CurrentFlashConfig );
#endif /* (IPV_FLASHV2== IPV_FLASH_00_00_05_01) */

}
#endif /* (MCU_DISABLE_FLASH_CONFIG == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#define MCU_STOP_SEC_RAMCODE
/**
* @violates @ref Mcu_FLASH_c_REF_1 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
/** @violates @ref Mcu_FLASH_c_REF_2 MISRA 2004 Required Rule 19.15, Repeated include files.  */
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif


/** @} */
