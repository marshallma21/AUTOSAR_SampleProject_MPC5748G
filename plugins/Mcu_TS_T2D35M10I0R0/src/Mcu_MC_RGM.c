/**
*   @file    Mcu_MC_RGM.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Reset Generation Module functions implementation.
*   @details Specific functions for MC_RGM configuration and control.
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
* @section Mcu_MC_RGM_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_MC_RGM_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_MC_RGM_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers. The defines
* are validated.
*
* @section Mcu_MC_RGM_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_MC_RGM_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*
* @section Mcu_MC_RGM_c_REF_6
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or
* unspecified behaviour.
*
* @section Mcu_MC_RGM_c_REF_7
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
#include "Mcu_MC_RGM.h"

#ifdef MCU_ERROR_ISR_NOTIFICATION
#include "Mcu.h"
#endif /* MCU_ERROR_ISR_NOTIFICATION */

#include "Mcu_MC_ME.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

#if (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
#include "Mcu_IPW_Irq.h"
#endif

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_MC_RGM_VENDOR_ID_C                      43
/**
* @violates @ref Mcu_MC_RGM_c_REF_3 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
*/
#define MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION_C       4
/**
* @violates @ref Mcu_MC_RGM_c_REF_3 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
*/
#define MCU_MC_RGM_AR_RELEASE_MINOR_VERSION_C       2
/**
* @violates @ref Mcu_MC_RGM_c_REF_3 The compiler/linker shall be checked to ensure that 31
* character significance and case sensitivity are supported for external identifiers.
*/
#define MCU_MC_RGM_AR_RELEASE_REVISION_VERSION_C    2
#define MCU_MC_RGM_SW_MAJOR_VERSION_C               1
#define MCU_MC_RGM_SW_MINOR_VERSION_C               0
#define MCU_MC_RGM_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if current file and Mcu_ME_RGM header file are of the same vendor */
#if (MCU_MC_RGM_VENDOR_ID_C != MCU_MC_RGM_VENDOR_ID)
    #error "Mcu_MC_RGM.c and Mcu_MC_RGM.h have different vendor ids"
#endif
/* Check if current file and Mcu_ME_RGM header file are of the same Autosar version */
#if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_RGM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_REVISION_VERSION_C != MCU_MC_RGM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_RGM.c and Mcu_MC_RGM.h are different"
#endif
/* Check if current file and Mcu_ME_RGM header file are of the same Software version */
#if ((MCU_MC_RGM_SW_MAJOR_VERSION_C != MCU_MC_RGM_SW_MAJOR_VERSION) || \
     (MCU_MC_RGM_SW_MINOR_VERSION_C != MCU_MC_RGM_SW_MINOR_VERSION) || \
     (MCU_MC_RGM_SW_PATCH_VERSION_C != MCU_MC_RGM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_RGM.c and Mcu_MC_RGM.h are different"
#endif

/* Check if current file and Mcu_MC_ME header file are of the same vendor */
#if (MCU_MC_RGM_VENDOR_ID_C != MCU_MC_ME_VENDOR_ID)
    #error "Mcu_MC_RGM.c and Mcu_MC_ME.h have different vendor ids"
#endif
/* Check if current file and Mcu_MC_ME header file are of the same Autosar version */
#if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_ME_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_ME_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_REVISION_VERSION_C != MCU_MC_ME_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_RGM.c and Mcu_MC_ME.h are different"
#endif
/* Check if current file and Mcu_MC_ME header file are of the same Software version */
#if ((MCU_MC_RGM_SW_MAJOR_VERSION_C != MCU_MC_ME_SW_MAJOR_VERSION) || \
     (MCU_MC_RGM_SW_MINOR_VERSION_C != MCU_MC_ME_SW_MINOR_VERSION) || \
     (MCU_MC_RGM_SW_PATCH_VERSION_C != MCU_MC_ME_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_RGM.c and Mcu_MC_ME.h are different"
#endif

#if (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
/* Check if current file and Mcu_IPW_Irq header file are of the same vendor */
#if (MCU_MC_RGM_VENDOR_ID_C != MCU_IPW_IRQ_VENDOR_ID)
    #error "Mcu_MC_RGM.c and Mcu_IPW_Irq.h have different vendor ids"
#endif
/* Check if current file and Mcu_IPW_Irq header file are of the same Autosar version */
#if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION_C    != MCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION_C    != MCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (MCU_MC_RGM_AR_RELEASE_REVISION_VERSION_C != MCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_MC_RGM.c and Mcu_IPW_Irq.h are different"
#endif
/* Check if current file and Mcu_IPW_Irq header file are of the same Software version */
#if ((MCU_MC_RGM_SW_MAJOR_VERSION_C != MCU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (MCU_MC_RGM_SW_MINOR_VERSION_C != MCU_IPW_IRQ_SW_MINOR_VERSION) || \
     (MCU_MC_RGM_SW_PATCH_VERSION_C != MCU_IPW_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_MC_RGM.c and Mcu_IPW_Irq.h are different"
#endif
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_RGM.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and DEM header file are of the same version */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_RGM.c and Dem.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_MC_RGM.c and SilRegMacros.h are different"
    #endif
#endif

#ifdef MCU_ERROR_ISR_NOTIFICATION
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_MC_RGM_VENDOR_ID_C != MCU_VENDOR_ID)
#error "Mcu_MC_RGM.c and Mcu.h have different vendor ids"
#endif

/* Check if current file and MCU header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
        (MCU_MC_RGM_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
        (MCU_MC_RGM_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
        )
    #error "AutoSar Version Numbers of Mcu_MC_RGM.c and Mcu.h are different"
    #endif
#endif

/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_MC_RGM_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_MC_RGM_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_MC_RGM_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
#error "Software Version Numbers of Mcu_MC_RGM.c and Mcu.h are different"
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
#define MCU_START_SEC_VAR_INIT_32
/**
 * @violates @ref Mcu_MC_RGM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
 * @violates @ref Mcu_MC_RGM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
 * statements and comments before '#include'
 */
#include "Mcu_MemMap.h"

static VAR(uint32, MCU_VAR) Mcu_u32DesResetStatus = 0x00U;
static VAR(uint32, MCU_VAR) Mcu_u32FesResetStatus = 0x00U;

#define MCU_STOP_SEC_VAR_INIT_32
/**
 * @violates @ref Mcu_MC_RGM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
 * @violates @ref Mcu_MC_RGM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
 * statements and comments before '#include'
 */
#include "Mcu_MemMap.h"

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
* @violates @ref Mcu_MC_RGM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_MC_RGM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
*/
#include "Mcu_MemMap.h"

static FUNC( void, MCU_CODE ) Mcu_MC_RGM_ClearFesResetFlags(VAR( uint32, AUTOMATIC) u32RegValue);
static FUNC( void, MCU_CODE ) Mcu_MC_RGM_ClearDesResetFlags(VAR( uint32, AUTOMATIC) u32RegValue);

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief            This function clear all the reset flags from MC_RGM_FES.
* @details          This function clear all the reset flags from MC_RGM_FES.
*                   Called by:
*                       - Mcu_MC_RGM_GetResetReason().
*                       - Mcu_MC_RGM_GetResetRawValue().
*
* @param[in]        u32RegValue that include the status of MC_RGM_FES register.
*
* @return           void
*
*/
static FUNC( void, MCU_CODE ) Mcu_MC_RGM_ClearFesResetFlags(VAR( uint32, AUTOMATIC) u32RegValue)
{
    /* Time-out value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32TimeOut;

    /* clear all the reset flags from MC_RGM_FES */
    if ((uint32)0x00U != u32RegValue)
    {
        u32TimeOut = MCU_TIMEOUT_LOOPS;
        do
        {
            u32TimeOut--;
            /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
            /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(MC_RGM_FES_ADDR32, u32RegValue);
            /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
            /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
            u32RegValue = (uint32)REG_READ32(MC_RGM_FES_ADDR32) & MC_RGM_FES_RWBITS_MASK32;
        }
        while (((uint32)0x00U != u32RegValue) && ((uint32)0x00U < u32TimeOut));
    
        if ( (uint32)0x00U == u32TimeOut)
        {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
        }
    }
}

/**
* @brief            This function clear all the reset flags from MC_RGM_DES.
* @details          This function clear all the reset flags from MC_RGM_DES.
*                   Called by:
*                       - Mcu_MC_RGM_GetResetReason().
*                       - Mcu_MC_RGM_GetResetRawValue().
*
* @param[in]        u32RegValue that include the status of MC_RGM_DES register.
*
* @return           void
*
*/
static FUNC( void, MCU_CODE ) Mcu_MC_RGM_ClearDesResetFlags(VAR( uint32, AUTOMATIC) u32RegValue)
{
    /* Time-out value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32TimeOut;

    /* clear all the reset flags from MC_RGM_DES */
    if ((uint32)0x00U != u32RegValue)
    {
        u32TimeOut = MCU_TIMEOUT_LOOPS;
        do
        {
            u32TimeOut--;
            /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
            /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
            REG_WRITE32(MC_RGM_DES_ADDR32, u32RegValue);
            /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
            /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
            u32RegValue = (uint32)REG_READ32(MC_RGM_DES_ADDR32) & MC_RGM_DES_RWBITS_MASK32;
        }
        while (((uint32)0x00U != u32RegValue) && ((uint32)0x00U < u32TimeOut));

        if ( (uint32)0x00U == u32TimeOut)
        {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.state)
            {
                Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_TimeoutFailureCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif
        }
    }
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef MCU_ENABLE_USER_MODE_SUPPORT
#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
/**
* @brief            This function will enable writing in User mode by configuring REG_PROT
*/
FUNC( void, MCU_CODE) Mcu_MC_RGM_SetUserAccessAllowed(void)
{
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    SET_USER_ACCESS_ALLOWED(MC_RGM_BASEADDR);
}
#endif
#endif

/**
* @brief            This function initializes the Reset parameters.
* @details          This function configures disabling the functional event reset, disabling the
*                   destructive event reset, the functional event alternate request, the
*                   destructive event alternate request, the functional event short sequence, the
*                   standby reset sequence and enabling the functional bidirectional reset.
*                   Called by:
*                       - Mcu_Ipw_Init() from IPW.
*
* @param[in]        MC_RGM_pConfigPtr   Pointer to the MC_RGM configuration structure.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_MC_RGM_ResetInit(P2CONST( Mcu_MC_RGM_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_RGM_pConfigPtr)
{
#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_04_01_00) || \
     (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* 'Destructive' Event Reset Disable Register (RGM_DERD) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_DERD_ADDR32, (MC_RGM_pConfigPtr->u32DestResetOpt));
#endif

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* 'Destructive' Event Alternate Request Register (RGM_DEAR) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_DEAR_ADDR32, (MC_RGM_pConfigPtr->u32DestSafeIsrOpt));
#endif

#if ((IPV_MC == IPV_MC_06_00_00_10) || (IPV_MC == IPV_MC_04_06_05_00))
    /* The register RGM_DBRE is not available on this version */
#else
    /* 'Destructive' Bidirectional Reset Enable Register (RGM_DBRE) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_DBRE_ADDR32, (MC_RGM_pConfigPtr->u32DestExtPinReset));
#endif

    /* 'Functional' Event Reset Disable Register (RGM_FERD) */
#ifdef ERR_IPV_MC_0044
#if (ERR_IPV_MC_0044 == STD_ON)
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_FERD_ADDR32, (MC_RGM_pConfigPtr->u32FuncResetOpt) & (~MC_RGM_FERD_D_ESR0_MASK32));
#else
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_FERD_ADDR32, (MC_RGM_pConfigPtr->u32FuncResetOpt));
#endif /* (ERR_IPV_MC_0044 == STD_ON) */
#else
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_FERD_ADDR32, (MC_RGM_pConfigPtr->u32FuncResetOpt));
#endif /* ERR_IPV_MC_0044 */

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* The register RGM_FEAR is not available on this version */
#else
    /* 'Functional' Event Alternate Request Register (RGM_FEAR) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_FEAR_ADDR32, (MC_RGM_pConfigPtr->u32FuncSafeIsrOpt));
#endif

    /* 'Functional' Bidirectional Reset Enable Register (RGM_FBRE) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_FBRE_ADDR32, (MC_RGM_pConfigPtr->u32FuncExtPinReset));

    /* 'Functional' Event Short Sequence Register (RGM_FESS) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32( MC_RGM_BASEADDR, MC_RGM_FESS_ADDR32, (MC_RGM_pConfigPtr->u32FuncPhase1or3Opt));

#if (IPV_MC == IPV_MC_06_00_00_10)
    /* 'Functional' Reset Escalation Threshold Register (MC_RGM_FRET) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(MC_RGM_BASEADDR, MC_RGM_FRET_ADDR32,  (uint32)(MC_RGM_pConfigPtr->u8ThresholdReset));
    
    /* 'Destructive' Reset Escalation Threshold Register (MC_RGM_DRET) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(MC_RGM_BASEADDR, MC_RGM_DRET_ADDR32, (uint32)(MC_RGM_pConfigPtr->u8DesThresholdReset));
    
    /* DDR Handshake Enable Register (MC_RGM_DDR_HE) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(MC_RGM_BASEADDR, MC_RGM_FRHE_ADDR32, (MC_RGM_pConfigPtr->u32FuncResetHandshakeEnable));
    
    /* DDR Handshake Enable Register (MC_RGM_DDR_HE) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK32(MC_RGM_BASEADDR, MC_RGM_DDR_HE_ADDR32, (MC_RGM_pConfigPtr->u32DDRHandshakeOpt));
#else
    /* 'Functional' Reset Escalation Threshold Register (MC_RGM_FRET) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK8(MC_RGM_BASEADDR, MC_RGM_FRET_ADDR8,  (MC_RGM_pConfigPtr->u8ThresholdReset));
    
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) || \
     (IPV_MC == IPV_MC_04_06_01_00) || (IPV_MC == IPV_MC_04_06_05_00) || \
     (IPV_MC == IPV_MC_05_00_00_10) || (IPV_MC == IPV_MC_05_00_00_07) || \
     (IPV_MC == IPV_MC_04_04_01_00) \
    )
    /* 'Destructive' Reset Escalation Threshold Register (MC_RGM_DRET) */
#ifdef ERR_IPV_MC_0042
#if (ERR_IPV_MC_0042  != STD_ON)
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK8(MC_RGM_BASEADDR, MC_RGM_DRET_ADDR8, (MC_RGM_pConfigPtr->u8DesThresholdReset));
#endif /* (ERR_IPV_MC_0042  != STD_ON) */
#else
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE_LOCK8(MC_RGM_BASEADDR, MC_RGM_DRET_ADDR8, (MC_RGM_pConfigPtr->u8DesThresholdReset));
#endif /* ERR_IPV_MC_0042 */
#endif /* IPV_MC == IPV_MC_04_00_15_15 */
#endif
}


/**
* @brief            This function returns the Reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_Ipw_GetResetReason() from IPW.
*
* @return           Reason of the Reset event.
* @retval           MCU_SOFT_DEST_RESET   Software destructive reset.
* @retval           MCU_POWER_ON_RESET   Power on event.
* @retval           MCU_1_2_LV_RESET   1.2 V low-voltage detected event.
* @retval           MCU_1_2_HV_RESET   1.2 V high-voltage detected event.
* @retval           MCU_2_7_LV_VREG_RESET   2.7 V low-voltage detected event (VREG).
* @return           MCU_2_7_LV_FLASH_RESET   2.7 V low-voltage detected event (FLASH).
* @retval           MCU_2_7_LV_IO_RESET   2.7 V low-voltage detected event (I/O).
* @retval           MCU_JTAG_RESET   JTAG initiated reset event.
* @retval           MCU_CORE_RESET   Core reset event.
* @retval           MCU_SOFT_RESET   Software destrutive event.
* @retval           MCU_CWD_RESET   Core watchdog reset event.
* @return           MCU_PLL0_RESET   PLL0 fail event.
* @retval           MCU_MC_RGM_OLR_RESET   Oscillator frequency lower than reference event.
* @retval           MCU_MC_RGM_FHL_RESET   CMU0 clock frequency higher/lower than reference event.
* @retval           MCU_FCCU_SAFE_RESET   FCCU safe mode event.
* @retval           MCU_SW_RESET   Software reset event.
* @retval           MCU_PLL1_RESET   PLL1 fail event.
* @return           MCU_FL_ECC_RCC_RESET   Flash, ECC or lock-step error event.
* @retval           MCU_MC_RGM12_FHL_RESET   CMU 1/2 clock frequence too high/low event.
* @retval           MCU_ST_DONE_RESET   Self-test completed event.
* @retval           MCU_FCCU_SOFT_RESET   FCCU soft reaction request event.
* @retval           MCU_FCCU_HARD_RESET   FCCU hard reaction request event.
* @retval           MCU_EXR_RESET   External reset event.
* @retval           MCU_NO_RESET_REASON   External reset event.
* @retval           MCU_MULTIPLE_RESET_REASON   External reset event.
* @retval           MCU_RESET_UNDEFINED   Undefined reset source.
*
* @note             The User should ensure that the reset reason is cleared once it has been read
*                   out to avoid multiple reset reasons. The function Mcu_GetResetReason shall
*                   return MCU_RESET_UNDEFINED if this function is called prior to calling of the
*                   function Mcu_Init, and if supported by the hardware.
*/
FUNC( Mcu_ResetType, MCU_CODE) Mcu_MC_RGM_GetResetReason(VAR( void, AUTOMATIC))
{
    /* Code for the Reset event returned by this function. */
    VAR( Mcu_ResetType, AUTOMATIC) eResetReason = MCU_NO_RESET_REASON;
    /* Temporary variable for DES and FES registers value. */
    VAR( uint32, AUTOMATIC) u32RegValue = 0U;
    VAR( uint32, AUTOMATIC) u32ActiveValue;
    VAR( uint32, AUTOMATIC) u32NumberOfFlags = 0U;
    VAR( uint32, AUTOMATIC) u32Index;
    VAR( uint32, AUTOMATIC) u32DynamicMask;
    VAR( uint32, AUTOMATIC) u32Position = (uint32)0x00U;

    /* Check "Destructive Reset Reason" from DES Status Register. */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    u32RegValue = (uint32)REG_READ32(MC_RGM_DES_ADDR32) & MC_RGM_DES_RWBITS_MASK32;
    /* store the content of DES */
    if (0x00U != u32RegValue)
    {
        Mcu_u32DesResetStatus = u32RegValue;
    }
    u32ActiveValue = Mcu_u32DesResetStatus;

    /* If at least one bit is set in RGM_DES register, then it means a some reset events are logged. */
    for (u32Index = 0x00U; u32Index < 0x20U; u32Index++)
    {
        u32DynamicMask = ((uint32)0x01U << u32Index);
        if ((uint32)0x00U != (u32DynamicMask & MC_RGM_DES_RWBITS_MASK32))
        {
            if ((uint32)0x00U != (u32DynamicMask & u32ActiveValue))
            {
                eResetReason = (Mcu_ResetType)u32Position;
                u32NumberOfFlags++;
                
                /* 
                   MCU_MULTIPLE_RESET_REASON returned if more than one reset reason 
                   in this case use function Mcu_GetRawValue to determine. 
                */
                if (u32NumberOfFlags >= (uint32)2)
                {
                    eResetReason = MCU_MULTIPLE_RESET_REASON;
                    break;
                }
            }
            u32Position++;
        }
    }
    /* clear all the reset flags from MC_RGM_DES */
    Mcu_MC_RGM_ClearDesResetFlags(u32RegValue);

    if (MCU_MULTIPLE_RESET_REASON != eResetReason)
    {
        /* Check "Functional Reset Reason" from FES Status Register. */
        /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
        u32RegValue = (uint32)REG_READ32(MC_RGM_FES_ADDR32) & MC_RGM_FES_RWBITS_MASK32;
        /* store the content of FES */
        if ((uint32)0x00U != u32RegValue)
        {        
            Mcu_u32FesResetStatus = u32RegValue;
        }
        u32ActiveValue = Mcu_u32FesResetStatus;
        
        if ((uint32)0x00U != u32ActiveValue)
        {
            /* If at least one bit is set in RGM_DES register, then it means a some reset events are logged. */
            for (u32Index = 0x00U; u32Index < 0x20U; u32Index++)
            {
                u32DynamicMask = ((uint32)0x01U << u32Index);
                if ((uint32)0x00U != (u32DynamicMask & MC_RGM_FES_RWBITS_MASK32))
                {
                    if ((uint32)0x00U != (u32DynamicMask & u32ActiveValue))
                    {
                        eResetReason = (Mcu_ResetType)u32Position;
                        u32NumberOfFlags++;
                        /* Check if there is more than 1 reset reason except MCU_POWER_ON_RESET */
                        if (u32NumberOfFlags >= (uint32)2)
                        {
                            eResetReason = MCU_MULTIPLE_RESET_REASON;
                            break;
                        }
                    }
                    u32Position++;
                }
            }
        }
        /* clear all the reset flags from MC_RGM_FES */
        Mcu_MC_RGM_ClearFesResetFlags(u32RegValue);
    }

    return (Mcu_ResetType)eResetReason;
}


/**
* @brief            This function returns the Raw Reset value.
* @details          This routine returns the Raw Reset value that is read from the hardware.
*                   Called by:
*                       - Mcu_Ipw_GetResetRawValue() from IPW.
*
* @return           Register value with the Reset status.
* @retval           uint32   Code of the Raw reset value.
*
* @note             The User should ensure that the reset reason is cleared once it has been read
*                   out to avoid multiple reset reasons.
*
*/
FUNC( Mcu_RawResetType, MCU_CODE) Mcu_MC_RGM_GetResetRawValue( VAR( void, AUTOMATIC))
{
    /* Temporary variable for DES and FES registers value. */
    VAR( uint32, AUTOMATIC) u32RawReset = (uint32)0x00U;
    VAR( uint32, AUTOMATIC) u32RegValue;
    VAR( uint32, AUTOMATIC) u32ActiveValue;
    VAR( uint32, AUTOMATIC) u32Index;
    VAR( uint32, AUTOMATIC) u32DynamicMask;
    VAR( uint32, AUTOMATIC) u32Position;

    /* compact the 2x32 registers to 1x32 register */
    /* lower 16 bits will be FES, higher 16 bits will be DES */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    u32RegValue = REG_READ32( MC_RGM_FES_ADDR32) & MC_RGM_FES_RWBITS_MASK32;
    /* store the content of FES */
    if ((uint32)0x00U != u32RegValue)
    {
        Mcu_u32FesResetStatus = u32RegValue;
    }
    u32ActiveValue = Mcu_u32FesResetStatus;

    if ((uint32)0x00U != u32ActiveValue)
    {
        u32Position = (uint32)0x00U;
        
        for (u32Index = 0x00U; u32Index < 0x20U; u32Index++)
        {
            u32DynamicMask = ((uint32)0x01U << u32Index);
            if ((uint32)0x00U != (u32DynamicMask & MC_RGM_FES_RWBITS_MASK32))
            {
                if ((uint32)0x00U != (u32DynamicMask & u32ActiveValue))
                {
                    u32RawReset |= ((uint32)0x01U << u32Position);
                }
                u32Position++;
            }
        }
        /* clear all the reset flags from MC_RGM_FES */
        Mcu_MC_RGM_ClearFesResetFlags(u32RegValue);
    }
    
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    u32RegValue = REG_READ32( MC_RGM_DES_ADDR32) & MC_RGM_DES_RWBITS_MASK32;
    /* store the content of DES */
    if ((uint32)0x00U != u32RegValue)
    {        
        Mcu_u32DesResetStatus = u32RegValue;
    }
    u32ActiveValue = Mcu_u32DesResetStatus;
    
    if ((uint32)0x00U != u32ActiveValue)
    {
#if (IPV_MC == IPV_MC_04_06_05_00)
        u32Position = (uint32)0x08U;
#else
        u32Position = (uint32)0x10U;
#endif

        for (u32Index = 0x00U; u32Index < 0x20U; u32Index++)
        {
            u32DynamicMask = ((uint32)0x01U << u32Index);
            if ((uint32)0x00U != (u32DynamicMask & MC_RGM_DES_RWBITS_MASK32))
            {
                if ((uint32)0x00U != (u32DynamicMask & u32ActiveValue))
                {
                    u32RawReset |= ((uint32)0x01U << u32Position);
                }
                u32Position++;
            }
        }
        /* clear all the reset flags from MC_RGM_DES */
        Mcu_MC_RGM_ClearDesResetFlags(u32RegValue);
    }

    return (Mcu_RawResetType)u32RawReset;
}


#if (MCU_PERFORM_RESET_API == STD_ON)

/**
* @brief            This function performs a microcontroller reset.
* @details          This function performs a microcontroller reset by using the hardware feature of
*                   the microcontroller.
*                   This is a chip-wide virtual mode during which the application is not active.
*                   The system remains in this mode until all resources are available for the
*                   embedded software to take control of the device.
*                   Called by:
*                       - Mcu_Ipw_PerformReset() from IPW.
*
* @param[in]        MC_RGM_pConfigPtr  Pointer to the MC_RGM configuration structure.
*
* @return           void
*
*/
FUNC(void, MCU_CODE) Mcu_MC_RGM_PerformReset(P2CONST( Mcu_MC_RGM_ConfigType, AUTOMATIC, MCU_APPL_CONST) MC_RGM_pConfigPtr)
{
    switch (MC_RGM_pConfigPtr->Mcu_MC_RGM_eResetType)
    {
        case (MCU_FUNC_RESET):
        {
            /* Initiate "Functional Reset" Mode. */
            Mcu_MC_ME_ApplyMode( MCU_RESET_MODE);
            break;
        }
        case (MCU_DEST_RESET):
        {
            /* Initiate "Destructive Reset" Mode. */
            Mcu_MC_ME_ApplyMode( MCU_DEST_RESET_MODE);
            break;
        }
        default:
        {
            /* Default case - should never enter here. */
            break;
        }
    }
}
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */


#if (MCU_RESET_ALTERNATE_ISR_USED == STD_ON)
/**
* @brief            This function handle the 'Functional' Reset Alternate Event Interrupt for
*                   Leopard. This function handle the 'Functional' and 'Destructive' Reset
*                   Alternate Event Interrupt for Panther.
* @details          Assigned to INTC56 for MPC56XXL.
*                   Assigned to INTC255 for MPC57XXP.
*                   Only the following errors support interrupt reaction.
*                       - CMU12_FHL
*                       - PLL1
*                       - CMU0_FHL
*                       - CMU0_OLR
*                       - PLL0
*                       - CWD
*
* @return           void
* @implements Mcu_MC_RGM_ResetAltInt_Activity
*/
/** @violates @ref Mcu_MC_RGM_c_REF_5 Global declaration of function */
FUNC(void, MCU_CODE) Mcu_MC_RGM_ResetAltInt( VAR( void, AUTOMATIC))
{
#ifdef MCU_ERROR_ISR_NOTIFICATION
#if (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
    VAR( uint32, AUTOMATIC) u32CmuIrqMask = 0U;
#endif /* MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON */
    VAR( uint32, AUTOMATIC) u32MCRGM_EnabledFunctionalIsr ;
#endif /* MCU_ERROR_ISR_NOTIFICATION */
    /* functional event ISR's */
    VAR( uint32, AUTOMATIC) u32MCRGM_FunctionalEventStatus ;

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* destructive event ISR's on platform that support this feature */
    VAR( uint32, AUTOMATIC) u32MCRGM_DestructiveEventStatus ;
#ifdef MCU_ERROR_ISR_NOTIFICATION
    VAR( uint32, AUTOMATIC) u32MCRGM_EnabledDestructiveIsr ;
#endif
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || ... */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
 #ifdef ERR_IPV_MC_0045
  #if (STD_ON != ERR_IPV_MC_0045)
    VAR( uint8, AUTOMATIC) u8MCRGM_ExtResetOutputStatus;
  #endif /* (STD_ON != ERR_IPV_MC_0045) */
 #else
    VAR( uint8, AUTOMATIC) u8MCRGM_ExtResetOutputStatus;
 #endif /* ERR_IPV_MC_0045 */
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */

    /* get the ISR status and enables isr's */
    /* functional */
    /* get only the bits that can generate a functional reset IRQ */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    u32MCRGM_FunctionalEventStatus = (uint32)(REG_READ32(MC_RGM_FES_ADDR32) & MC_RGM_FES_IRQ_BITS_MASK32);
    /* clear active IRQ's */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_RGM_FES_ADDR32, u32MCRGM_FunctionalEventStatus);

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
    /* destructive */
    /* reset only the bits that can generate an IRQ ( defined in RGM_DEAR ) */
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    u32MCRGM_DestructiveEventStatus = (uint32)(REG_READ32(MC_RGM_DES_ADDR32) & MC_RGM_DES_IRQ_BITS_MASK32);
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE32( MC_RGM_DES_ADDR32, u32MCRGM_DestructiveEventStatus);
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15)) */

#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
    /* destructive */
 #ifdef ERR_IPV_MC_0045
  #if (STD_ON != ERR_IPV_MC_0045)
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    u8MCRGM_ExtResetOutputStatus = (uint8)(REG_READ8(MC_RGM_EROEC_ADDR8) & MC_RGM_EROEC_EROEC_MASK32);
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE8( MC_RGM_EROEC_ADDR8, u8MCRGM_ExtResetOutputStatus);
  #endif /* (STD_ON != ERR_IPV_MC_0045) */
 #else
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    u8MCRGM_ExtResetOutputStatus = (uint8)(REG_READ8(MC_RGM_EROEC_ADDR8) & MC_RGM_EROEC_EROEC_MASK32);
    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    REG_WRITE8( MC_RGM_EROEC_ADDR8, u8MCRGM_ExtResetOutputStatus);
 #endif /* ERR_IPV_MC_0045 */
#endif /* (IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00) */

#ifdef MCU_ERROR_ISR_NOTIFICATION
    if(NULL_PTR != Mcu_pConfigPtr)
    {
        /* get enabled ISR's */
        /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
        u32MCRGM_EnabledFunctionalIsr = REG_READ32(MC_RGM_FEAR_ADDR32) & MC_RGM_FEAR_RWBITS_MASK32;

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
        /* destructive */
        /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
        u32MCRGM_EnabledDestructiveIsr = REG_READ32(MC_RGM_DEAR_ADDR32) & MC_RGM_DEAR_RWBITS_MASK32;
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15)) */

        /* signal event to upper layers */
        /* functional */
#if ((IPV_MC == IPV_MC_04_00_15_15) || (IPV_MC == IPV_MC_04_01_00_00))
  #ifdef ERR_IPV_MC_0045
    #if (STD_ON == ERR_IPV_MC_0045)
        if ((uint32)0x00U != u32MCRGM_FunctionalEventStatus)
    #else
        if (((uint32)0x00U != u32MCRGM_FunctionalEventStatus) || ((uint8)0x00U != u8MCRGM_ExtResetOutputStatus))
    #endif /* (STD_ON == ERR_IPV_MC_0045) */
  #else
        if (((uint32)0x00U != u32MCRGM_FunctionalEventStatus) || ((uint8)0x00U != u8MCRGM_ExtResetOutputStatus))
  #endif /* ERR_IPV_MC_0045 */
#else
        if ((uint32)0x00U != u32MCRGM_FunctionalEventStatus)
#endif /* (IPV_MC == IPV_MC_04_00_15_15) */
        {
            if ( (uint32)0x00U != u32MCRGM_EnabledFunctionalIsr )
            {
                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_FUNC_RESET_ALT_FAILURE);
            }
        }

#if ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
     (IPV_MC == IPV_MC_04_01_00_00) || (IPV_MC == IPV_MC_04_06_01_00) || \
     (IPV_MC == IPV_MC_04_06_05_00) \
    )
        /* destructive */
        if ( (uint32)0x00U != u32MCRGM_DestructiveEventStatus )
        {
            if ( (uint32)0x00U != u32MCRGM_EnabledDestructiveIsr )
            {
                MCU_ERROR_ISR_NOTIFICATION(MCU_E_ISR_DEST_RESET_ALT_FAILURE);
            }
        }
#endif /* ((IPV_MC == IPV_MC_04_03_00_00) || (IPV_MC == IPV_MC_04_00_15_15) || \
          (IPV_MC == IPV_MC_04_01_00_00)) */

    /* clear the CMU interrupt irq */
#if (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
#if (IPV_MC == IPV_MC_05_00_00_07)
        u32CmuIrqMask = MC_RGM_FES_F_CMU_OLR_MASK32;
#elif (IPV_MC == IPV_MC_05_00_00_10)
        u32CmuIrqMask = MC_RGM_FES_F_FXOSC_OR_MASK32;
#endif
        if ((uint32)0x00U != (u32MCRGM_FunctionalEventStatus & u32CmuIrqMask))
        {
            Mcu_Ipw_CmuClearClockFailIrqFlags((uint8)0U, MCU_IPW_CMU_ISR_OLRI_MASK32);
        }
#endif
    }
#endif
}
#endif /* ( MCU_RESET_ALTERNATE_ISR_USED == STD_ON ) */


#if (MCU_RGM_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
/**
* @brief            This function clear the Reset Alternate Event Interrupt flags.
* @details          This function clear the Reset Alternate Event Interrupt flags which were
*                   generated by the CMU.
*
*
* @return           void
* @implements Mcu_MC_RGM_ClearClockMonitoringIrqFlags_Activity
*/
FUNC( void, MCU_CODE ) Mcu_MC_RGM_ClearClockMonitoringIrqFlags(VAR( void, AUTOMATIC))
{
    /* Timeout value for specific wait operations. */
    VAR( uint32, AUTOMATIC) u32TimeOut = MCU_TIMEOUT_LOOPS;
    VAR( uint32, AUTOMATIC) u32MaskValue = (uint32)0U;
    VAR( uint32, AUTOMATIC) u32RegValue;

#if (IPV_MC == IPV_MC_05_00_00_07)
    u32MaskValue = MC_RGM_FES_F_CMU_OLR_MASK32;
#elif (IPV_MC == IPV_MC_05_00_00_10)
    u32MaskValue = MC_RGM_FES_F_FXOSC_OR_MASK32;
#endif

    /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
    /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
    u32RegValue = REG_READ32(MC_RGM_FES_ADDR32);

    /* check if the F_CMU_OLR bit has been cleared */
    while (((uint32) 0x00 != (u32RegValue & u32MaskValue)) && (u32TimeOut > (uint32)0x0U))
    {
        /* clear it again */
        /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
        REG_WRITE32(MC_RGM_FES_ADDR32, (u32RegValue & u32MaskValue));
        /** @violates @ref Mcu_MC_RGM_c_REF_4 Conversion from int to pointer */
        /** @violates @ref Mcu_MC_RGM_c_REF_7 The cast is used to access memory mapped registers.*/
        u32RegValue = REG_READ32( MC_RGM_FES_ADDR32 );
        u32TimeOut--;
    }
}
#endif /* (MCU_RGM_CLEAR_CLOCK_IRQ_FLAG == STD_ON) */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_MC_RGM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_MC_RGM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

