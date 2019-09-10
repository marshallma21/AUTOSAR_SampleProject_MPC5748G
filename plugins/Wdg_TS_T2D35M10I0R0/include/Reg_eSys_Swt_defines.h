/**
*   @file    Reg_eSys_Swt_defines.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Wdg - Register SWT masks.
*   @details Contains the masks for SWT registers
*
*   @addtogroup Wdg
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

#ifndef REG_E_SYS_SWT_DEFINES_H
#define REG_E_SYS_SWT_DEFINES_H

#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations

* @section Reg_eSys_Swt_defines_h_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_SWT_defines.h
*/
#define REG_ESYS_SWT_DEFINES_VENDOR_ID                    43
#define REG_ESYS_SWT_DEFINES_MODULE_ID                    102
#define REG_ESYS_SWT_DEFINES_AR_RELEASE_MAJOR_VERSION     4
/** @violates @ref Reg_eSys_Swt_defines_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *            that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_SWT_DEFINES_AR_RELEASE_MINOR_VERSION     2
/** @violates @ref Reg_eSys_Swt_defines_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *            that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_SWT_DEFINES_AR_RELEASE_REVISION_VERSION  2
#define REG_ESYS_SWT_DEFINES_SW_MAJOR_VERSION             1
#define REG_ESYS_SWT_DEFINES_SW_MINOR_VERSION             0
#define REG_ESYS_SWT_DEFINES_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief This constant specifies the value of the CR's Wdg enable bit if enabled
*/
#define SWT_WDG_ENABLED_U32                     (0x00000001UL)

/**
* @brief This constant specifies the value of the CR's Wdg enable bit if disabled
*/
#define SWT_WDG_DISABLED_U32                    (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's debug mode control bit if enabled
*/
#define SWT_WDG_STOP_IN_DEBUG_U32               (0x00000002UL)

/**
* @brief This constant specifies the value of the CR's debug mode control bit if disabled
*/
#define SWT_WDG_RUN_IN_DEBUG_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's stop mode control bit if enabled
*/
#define SWT_WDG_STOP_IN_HALT_U32                (0x00000004UL)

/**
* @brief This constant specifies the value of the CR's stop mode control bit if disabled
*/
#define SWT_WDG_RUN_IN_HALT_U32                 (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's clock selection bit if enabled
*/
#define SWT_WDG_OSCILLATOR_U32                  (0x00000008UL)

/**
* @brief This constant specifies the value of the CR's clock selection bit if disabled
*/
#define SWT_WDG_SYSTEM_CLOCK_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's soft lock bit if enabled
*/
#define SWT_WDG_SOFT_LOCK_U32                   (0x00000010UL)

/**
* @brief This constant specifies the value of the CR's soft lock bit if disabled
*/
#define SWT_WDG_NO_SOFT_LOCK_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's hard lock bit if enabled
*/
#define SWT_WDG_HARD_LOCK_U32                   (0x00000020UL)

/**
* @brief This constant specifies the value of the CR's hard lock bit if disabled
*/
#define SWT_WDG_NO_HARD_LOCK_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's interrupt then reset bit if disabled
*        Generate an interrupt on an initial time-out, reset on a second consecutive time-out
*/
#define SWT_INTERRUPT_TOGGLE_U32                (0x00000040UL)

/**
* @brief This constant specifies the value of the CR's interrupt then reset bit if enabled
*        Generate Reset on a time-out
*/
#define SWT_RESET_ON_TIMEOUT_U32                (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's window mode bit if enabled
*        Windowed mode, the service sequence is only valid when the down counter
*        is less then value in the SWT_WN_ADDR32 register
*/
#define SWT_TRIGGER_MODE_WINDOW_U32             (0x00000080UL)

/**
* @brief This constant specifies the value of the CR's window mode bit if disabled
*        Regular mode, service sequence can be done at any time
*/
#define SWT_TRIGGER_MODE_REGULAR_U32            (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's reset on invalid access bit if enabled
*        Invalid access to the SWT causes a system reset if WEN = 1
*/
#define SWT_INVALID_ACCESS_GEN_SYSTEM_RESET_U32 (0x00000100UL)

/**
* @brief This constant specifies the value of the CR's reset on invalid access bit if disabled
*        Invalid access to the SWT generates a bus error+
*/
#define SWT_INVALID_ACCESS_GEN_BUS_ERROR_U32    (0x00000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP0_ENABLE_U32                 (0x80000000UL)
/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP1_ENABLE_U32                 (0x40000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP2_ENABLE_U32                 (0x20000000UL)
/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP3_ENABLE_U32                 (0x10000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP4_ENABLE_U32                 (0x08000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP5_ENABLE_U32                 (0x04000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP6_ENABLE_U32                 (0x02000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP7_ENABLE_U32                 (0x01000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection disabled
*/
#define SWT_ALL_MAP_DISABLE_U32              (0x00000000UL)


/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/
#define SWT_MAP_ENABLE_4BITS_U32                 (0xF0000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
* Master acces protection enabled
*/

#define SWT_MAP_ENABLE_8BITS_U32                (0xFF000000UL)

/**
* @brief This constant specifies the value of the CR's master access protection
*        Master acces protection enabled
*/

#define SWT_MAP_ENABLE_6BITS_U32                (0xCF000000UL)


/**
* @brief This constant indicates that the fixed service sequence is chosen
*/

#define SWT_FIXED_SERVICE_U32               (0x00000000UL)

/**
* @brief This constant indicates that the keyed service sequence is chosen
*/

#define SWT_KEYED_SERVICE_U32               (0x00000200UL)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif /*REG_E_SYS_SWT_DEFINES_H*/

/** @} */
