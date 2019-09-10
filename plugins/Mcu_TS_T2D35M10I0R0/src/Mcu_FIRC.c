/**
*   @file    Mcu_FIRC.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Fast Internal Oscillator functions implementation.
*   @details Specific functions for FIRC configuration and control.
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
* @section Mcu_FIRC_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include files Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section Mcu_FIRC_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_FIRC_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
* pointer to a function and a type other than an integral type. This violation is due to the
* pointer arithmetic used to write/ read the data to/from the registers
*
* @section Mcu_FIRC_c_REF_4
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is requiered
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_FIRC_c_REF_5
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
#include "Mcu_FIRC.h"

#if (MCU_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* (MCU_DEV_ERROR_DETECT == STD_ON) */

#define USER_MODE_REG_PROT_ENABLED ( MCU_USER_MODE_REG_PROT_ENABLED )
#include "SilRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define Mcu_FIRC_VENDOR_ID_C                      43
#define Mcu_FIRC_AR_RELEASE_MAJOR_VERSION_C       4
#define Mcu_FIRC_AR_RELEASE_MINOR_VERSION_C       2
#define Mcu_FIRC_AR_RELEASE_REVISION_VERSION_C    2
#define Mcu_FIRC_SW_MAJOR_VERSION_C               1
#define Mcu_FIRC_SW_MINOR_VERSION_C               0
#define Mcu_FIRC_SW_PATCH_VERSION_C               0


/*==================================================================================================
                                     FILE VERSION CHECKS
=================================================================================================*/
/* Check if current file and Mcu_FIRC.h header file are of the same vendor */
#if (Mcu_FIRC_VENDOR_ID_C != MCU_FIRC_VENDOR_ID)
    #error "Mcu_FIRC.c and Mcu_FIRC.h have different vendor ids"
#endif
/* Check if current file and Mcu__CMU header file are of the same Autosar version */
#if ((Mcu_FIRC_AR_RELEASE_MAJOR_VERSION_C    != MCU_FIRC_AR_RELEASE_MAJOR_VERSION) || \
     (Mcu_FIRC_AR_RELEASE_MINOR_VERSION_C    != MCU_FIRC_AR_RELEASE_MINOR_VERSION) || \
     (Mcu_FIRC_AR_RELEASE_REVISION_VERSION_C != MCU_FIRC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_FIRC.c and Mcu_FIRC.h are different"
#endif
/* Check if current file and Mcu_FIRC.h header file are of the same Software version */
#if ((Mcu_FIRC_SW_MAJOR_VERSION_C != MCU_FIRC_SW_MAJOR_VERSION) || \
     (Mcu_FIRC_SW_MINOR_VERSION_C != MCU_FIRC_SW_MINOR_VERSION) || \
     (Mcu_FIRC_SW_PATCH_VERSION_C != MCU_FIRC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_FIRC.c and Mcu_FIRC.h are different"
#endif

/* Check if current file and DET header file are of the same version */
#if (MCU_DEV_ERROR_DETECT == STD_ON)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_FIRC_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_FIRC_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_FIRC.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and SilRegMacros header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((Mcu_FIRC_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (Mcu_FIRC_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_FIRC.c and SilRegMacros.h are different"
    #endif
#endif

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


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
* @violates @ref Mcu_FIRC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include files
* @violates @ref Mcu_FIRC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

#if (MCU_FIRC_UNDER_MCU_CONTROL == STD_ON)

/**
* @brief            Write FIRC configuration if under MCU control
* @details          
*
* @param[in]        Mcu_pFircConf - configuration pointer
*
* @return           void
*
*/
/** @violates @ref Mcu_FIRC_c_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC( void, MCU_CODE) Mcu_FIRC_Config(P2CONST(Mcu_FIRC_ConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pFircConf)
{
    /* write FIRC configuration registers */
    /** @violates @ref Mcu_FIRC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FIRC_c_REF_5 The cast is used to access memory mapped registers.*/
    REG_RMW32(FIRC_CTL_ADDR32, FIRC_CTL_RWBITS_MASK32, Mcu_pFircConf->u32FircCtl);
}
#endif /* (MCU_FIRC_UNDER_MCU_CONTROL == STD_ON) */



/**
* @brief            Describes the FIRC clock status
* @details          Returns MCU_FIRC_STABLE or MCU_FIRC_NOT_STABLE depending on the FIRC status
*
* @return           Returns the clock status
*
*/
/** @violates @ref Mcu_FIRC_c_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC( Mcu_FIRC_ClockStatusType, MCU_CODE) Mcu_FIRC_ActiveClockStatus(VAR(void, AUTOMATIC))
{
    VAR( Mcu_FIRC_ClockStatusType, AUTOMATIC) eState;
    VAR( uint32 , AUTOMATIC) u32Status ;
    
    /* get the register value */
    /** @violates @ref Mcu_FIRC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FIRC_c_REF_5 The cast is used to access memory mapped registers.*/
    u32Status = REG_READ32(FIRC_CTL_ADDR32) & FIRC_CTL_FIRCS_MASK32 ;
    
    /* check if enabled on not and decide on return value */
    if ( FIRC_CTL_FIRCS_MASK32 == u32Status )
    {
        eState = (Mcu_FIRC_ClockStatusType)MCU_FIRC_STABLE;
    }
    else
    {
        eState = (Mcu_FIRC_ClockStatusType)MCU_FIRC_NOT_STABLE;
    }
    
    /* return FIRC status */
    return (Mcu_FIRC_ClockStatusType)eState;
}



/**
* @brief            Low power RC control in Standby mode
* @details          Returns MCU_FIRC_IS_ON or MCU_FIRC_IS_OFF depending on FIRC status
*
* @return           Returns the standby status
*
*/
/** @violates @ref Mcu_FIRC_c_REF_4 Violates MISRA 2004 Required Rule 8.10, global declaration of function */
FUNC( Mcu_FIRC_StandbyStatusType, MCU_CODE) Mcu_FIRC_StandbyClockStatus(VAR(void, AUTOMATIC))
{
    VAR( Mcu_FIRC_StandbyStatusType, AUTOMATIC) eState;
    VAR( uint32 , AUTOMATIC) u32Status ;
    
    /* get the register value */
    /** @violates @ref Mcu_FIRC_c_REF_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Mcu_FIRC_c_REF_5 The cast is used to access memory mapped registers.*/
    u32Status = REG_READ32(FIRC_CTL_ADDR32) & FIRC_CTL_STDBY_MASK32 ;
    
    /* check if enabled on not and decide on return value */
    if ( FIRC_CTL_STDBY_MASK32 == u32Status )
    {
        eState = (Mcu_FIRC_StandbyStatusType)MCU_FIRC_IS_ON;
    }
    else
    {
        eState = (Mcu_FIRC_StandbyStatusType)MCU_FIRC_IS_OFF;
    }
    
    /* return FIRC status */
    return (Mcu_FIRC_StandbyStatusType)eState;
}

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_FIRC_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_FIRC_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */

