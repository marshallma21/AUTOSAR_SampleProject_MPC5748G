/**
*   @file    Mcu_SSCM.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - SSCM functions implementation.
*   @details Specific functions for SSCM configuration and control.
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
* @section Mcu_SSCM_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a
* violation since all header files are protected against multiple inclusions
*
* @section Mcu_SSCM_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_SSCM_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_SSCM_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_SSCM_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
*
* @section Mcu_SSCM_c_REF_6
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
#include "Mcu_SSCM.h"

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

#define MCU_SSCM_VENDOR_ID_C                        43
/** @violates @ref Mcu_SSCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SSCM_AR_RELEASE_MAJOR_VERSION_C         4
/** @violates @ref Mcu_SSCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SSCM_AR_RELEASE_MINOR_VERSION_C         2
/** @violates @ref Mcu_SSCM_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_SSCM_AR_RELEASE_REVISION_VERSION_C      2
#define MCU_SSCM_SW_MAJOR_VERSION_C                 1
#define MCU_SSCM_SW_MINOR_VERSION_C                 0
#define MCU_SSCM_SW_PATCH_VERSION_C                 0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Mcu_SSCM header file are of the same vendor */
#if (MCU_SSCM_VENDOR_ID_C != MCU_SSCM_VENDOR_ID)
    #error "Mcu_SSCM.c and Mcu_SSCM.h have different vendor ids"
#endif
/* Check if current file and Mcu_SSCM header file are of the same Autosar version */
#if ((MCU_SSCM_AR_RELEASE_MAJOR_VERSION_C    != MCU_SSCM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_SSCM_AR_RELEASE_MINOR_VERSION_C    != MCU_SSCM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_SSCM_AR_RELEASE_REVISION_VERSION_C != MCU_SSCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_SSCM.c and Mcu_SSCM.h are different"
#endif
/* Check if current file and Mcu_SSCM header file are of the same Software version */
#if ((MCU_SSCM_SW_MAJOR_VERSION_C != MCU_SSCM_SW_MAJOR_VERSION) || \
     (MCU_SSCM_SW_MINOR_VERSION_C != MCU_SSCM_SW_MINOR_VERSION) || \
     (MCU_SSCM_SW_PATCH_VERSION_C != MCU_SSCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_SSCM.c and Mcu_SSCM.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SSCM_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SSCM_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SSCM.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and DEM header file are of the same version */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SSCM_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SSCM_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SSCM.c and Dem.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_SSCM_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_SSCM_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_SSCM.c and SilRegMacros.h are different"
    #endif
#endif

/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
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
* @violates @ref Mcu_SSCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SSCM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief            Initialize SSCM registers
* @details
*
* @param[in]        SSCM_pConfigPtr - Pointer to SSCM configuration structure.
*
* @return           void
*
*/
/** @violates @ref Mcu_SSCM_c_REF_5 Global declaration of function */
FUNC( void, MCU_CODE) Mcu_SSCM_Init(P2CONST( Mcu_SSCM_ConfigType, AUTOMATIC, MCU_APPL_CONST) SSCM_pConfigPtr)
{
    VAR( uint16, AUTOMATIC) u16State = (uint16)0U;

    /* check SSCM errors */
    /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
    u16State = REG_READ16(SSCM_STATUS_ADDR16) ;
    /* clear only the CER flag if set - W1 to clear */
    /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
    REG_WRITE16(SSCM_STATUS_ADDR16, ((u16State & SSCM_STATUS_CER_MASK16 ) | SSCM_STATUS_RESBITS_MASK16));

    /* check if error and report it */
    if ( SSCM_STATUS_CER_MASK16 == (SSCM_STATUS_CER_MASK16 & u16State) )
    {
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
        if ((uint32)STD_ON == Mcu_pDemCfgPtr->Mcu_E_SscmCerFailureCfg.state)
        {
            Dem_ReportErrorStatus((Dem_EventIdType)Mcu_pDemCfgPtr->Mcu_E_SscmCerFailureCfg.id, DEM_EVENT_STATUS_FAILED);
        }
#endif
    }
#if ((IPV_SSCM==IPV_SSCM_05_04_00_00) || (IPV_SSCM==IPV_SSCM_05_03_00_00) ||\
     (IPV_SSCM==IPV_SSCM_06_00_00_01) ||(IPV_SSCM==IPV_SSCM_06_00_00_06)\
    )
    #if (IPV_SSCM==IPV_SSCM_06_00_00_06)
        #if (MCU_SSCM_ERROR_PRESENT == STD_ON)
            /* write PAE and RAE bits */
            /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
            /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
            REG_WRITE16(SSCM_ERROR_ADDR16, SSCM_pConfigPtr->u16SscmError );
        #else
            MCU_PARAM_UNUSED(SSCM_pConfigPtr);
        #endif
    #else
        /* write PAE and RAE bits */
        /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
        /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
        REG_WRITE16(SSCM_ERROR_ADDR16, SSCM_pConfigPtr->u16SscmError );
    #endif
#else
    MCU_PARAM_UNUSED(SSCM_pConfigPtr);
#endif
}


#if (MCU_GET_SYSTEM_STATE_API == STD_ON)
/**
* @brief            Get the System Status and Configuration Module information.
* @details          Return information about execution mode, security, vle, jtag id, etc.
*                       - Mcu_IPW_GetSystem_State() from IPW.
*
* @return           Status read from SSCM module - STATUS and MEMCONFIG registers.
* @retval           uint32   Platform register specific.
*
*/
FUNC( uint32, MCU_CODE) Mcu_SSCM_GetSystemState ( VAR( void, AUTOMATIC) )
{

    /* Temporary variable. */
    VAR( uint32, AUTOMATIC) u32State = (uint32)0U;

    /* Get the STATUS content register. */
    /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32State = (uint32)REG_READ16(SSCM_STATUS_ADDR16);
    /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
    u32State |= (uint32)((uint32)REG_READ16(SSCM_MEMCONFIG_ADDR16) << (uint32)0x10U);

    return (uint32)u32State;
}
#endif /* (MCU_GET_SYSTEM_STATE_API == STD_ON) */

#if (MCU_GET_MEM_CONFIG_API == STD_ON)

/**
* @brief            This function returns the value of the SSCM_MEMCONFIG register.
* @details          Returns the System Memory and ID register which reflects the memory
*                   configuration of the system and the JTAG ID.
*
* @return           The value of the SSCM_MEMCONFIG register.
*
* @api
*
* @requirements
*
* @note
*
*/
FUNC( Mcu_SSCM_MemConfigType, MCU_CODE) Mcu_SSCM_GetMemConfig( VAR( void, AUTOMATIC) )
{
    /* Temporary variable. */
    VAR( Mcu_SSCM_MemConfigType, AUTOMATIC) State = (Mcu_SSCM_MemConfigType)0U;

    /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
    State = (Mcu_SSCM_MemConfigType)REG_READ16(SSCM_MEMCONFIG_ADDR16);

    return (Mcu_SSCM_MemConfigType)(State);
}

#endif /* (MCU_GET_MEM_CONFIG_API == STD_ON) */

#if (MCU_SSCM_GET_STATUS_API == STD_ON)
/**
* @brief            This function returns the value of the SSCM_STATUS register.
* @details          Return information about execution mode, security, vle.
*                       - Mcu_IPW_GetStatus() from IPW.
*
* @return           The value of the SSCM_STATUS register.
*
* @api
*
* @requirements
*
* @note
*
*/
FUNC (Mcu_SSCM_StatusType, MCU_CODE) Mcu_SSCM_GetStatus(VAR( void, AUTOMATIC))
{
    VAR(Mcu_SSCM_StatusType, AUTOMATIC) Status = (Mcu_SSCM_StatusType)0U;

    /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
    Status = (Mcu_SSCM_StatusType)REG_READ16(SSCM_STATUS_ADDR16);
    return Status;
}
#endif /* MCU_SSCM_GET_STATUS_API == STD_ON */

#ifdef MCU_SSCM_GET_UOPS_API
#if (MCU_SSCM_GET_UOPS_API == STD_ON)
/**
* @brief            This function returns the value of the SSCM_UOPS register.
* @details          Return information about User Option Bits, HSM Boot Configuration.
*                       - Mcu_Ipw_SscmGetUops() from IPW.
*
* @return           The value of the SSCM_UOPS register.
*
* @api
*
* @requirements
*
* @note
*
*/
FUNC (Mcu_SSCM_UopsType, MCU_CODE) Mcu_SSCM_GetUops(VAR( void, AUTOMATIC))
{
    VAR(Mcu_SSCM_UopsType, AUTOMATIC) State = (Mcu_SSCM_UopsType)0U;

    /** @violates @ref Mcu_SSCM_c_REF_4 Conversion form pointer to integer*/
    /** @violates @ref Mcu_SSCM_c_REF_6 The cast is used to access memory mapped registers.*/
    State = (Mcu_SSCM_UopsType)REG_READ32(SSCM_UOPS_ADDR32);
    return State;
}
#endif /* MCU_SSCM_GET_UOPS_API == STD_ON */
#endif /* MCU_SSCM_GET_UOPS_API */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_SSCM_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_SSCM_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */
