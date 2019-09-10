/**
*   @file    Reg_eSys_Swt.h
*
*   @version 1.0.0
*   @brief   AUTOSAR Wdg - Software Watchdog Timer (SWT) Registers
*   @details Contains information about the SWT's registers
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

#ifndef REG_ESYS_SWT_H
#define REG_ESYS_SWT_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_Swt_h_REF_1
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
*          that 31 character significance and case sensitivity are supported for external identifiers.
*          The defines are validated.
*
* @section Reg_eSys_Swt_h_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*
* @section Reg_eSys_Swt_h_REF_3
*          Violates MISRA 2004 Advisory Rule 19.7, Use of function like macro.
*          This violation is due to function like macro defined for register operations.
*          Function like macro are used to reduce code complexity.
* @section Reg_eSys_Swt_h_REF_4
*          Violates MISRA 2004 Required Rule 8.12, Array size not defined.
*          SWT_aBASE_ADDR32 size is different base on configuration.
* @section Reg_eSys_Swt_h_REF_5
*          Violates MISRA 2004 Advisory Rule 19.1 ,only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
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
/**
* @brief Include Memory mapping specification
* @violates @ref Reg_eSys_Swt_h_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice*/
#include "Reg_eSys.h"
#include "Wdg_Cfg.h"
/**f
* @file           Reg_eSys_Swt.h    
*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @brief  Parameters that shall be published within the driver header file and also in the 
* module's description file
*/
#define REG_ESYS_SWT_VENDOR_ID                      43
/** @violates @ref Reg_eSys_Swt_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_SWT_AR_RELEASE_MAJOR_VERSION       4
/** @violates @ref Reg_eSys_Swt_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_SWT_AR_RELEASE_MINOR_VERSION       2
/** @violates @ref Reg_eSys_Swt_h_REF_1 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure
 *  that 31 character significance and case sensitivity are supported for external identifiers. */
#define REG_ESYS_SWT_AR_RELEASE_REVISION_VERSION    2
#define REG_ESYS_SWT_SW_MAJOR_VERSION               1
#define REG_ESYS_SWT_SW_MINOR_VERSION               0
#define REG_ESYS_SWT_SW_PATCH_VERSION               0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Reg_eSys header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((REG_ESYS_SWT_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_SWT_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of Reg_eSys_Swt.h and Reg_eSys.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define WDG_START_SEC_CONST_32
/**
* @brief Include Memory mapping specification
* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Reg_eSys_Swt_h_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

extern CONST(uint32, WDG_CONST) SWT_aBASE_ADDR32[WDG_NO_OF_INSTANCES];
#define WDG_STOP_SEC_CONST_32
/**
* @brief Include Memory mapping specification
* @violates @ref Reg_eSys_Swt_h_REF_5 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Reg_eSys_Swt_h_REF_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Wdg_MemMap.h"

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief This constant specifies the SWT Control Register
* @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define SWT_CR_ADDR32(u8ModuleIdx)      (SWT_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x00UL)

/**
* @brief This constant specifies the SWT Interrupt Register
* @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define SWT_IR_ADDR32(u8ModuleIdx)      (SWT_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x04UL)

/**
* @brief This constant specifies the SWT Time-out Register
* @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define SWT_TO_ADDR32(u8ModuleIdx)      (SWT_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x08UL)

/**
* @brief This constant specifies the SWT Window Register
* @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define SWT_WN_ADDR32(u8ModuleIdx)      (SWT_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x0CUL)

/**
* @brief This constant specifies the SWT Service Register
* @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define SWT_SR_ADDR32(u8ModuleIdx)      (SWT_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x10UL)

/**
* @brief This constant specifies the SWT Output Register
* @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define SWT_CO_ADDR32(u8ModuleIdx)      (SWT_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x14UL)

/**
* @brief This constant specifies the SWT Service Key Register
* @violates @ref Reg_eSys_Swt_h_REF_3 MISRA 2004 Advisory Rule 19.7, Function-like macro defined
*/
#define SWT_SK_ADDR32(u8ModuleIdx)      (SWT_aBASE_ADDR32[(u8ModuleIdx)] + (uint32)0x18UL)


/**
* @brief This constant specifies the value of the first part of the unlock sequence
*        which clears the soft lock
*/
#define SWT_UNLOCK_SEQ1_U32                     (0x0000C520UL)

/**
* @brief This constant specifies the value of the second part of the unlock sequence
*        which clears the soft lock
*/
#define SWT_UNLOCK_SEQ2_U32                     (0x0000D928UL)

/**
* @brief This constant specifies the minimum value that will be set in the SWT timeout register
*/
#define SWT_MIN_VALUE_TIMEOUT_U32               ((uint32)0x100)

/**
* @brief This constant specifies the value of the first part of the fixed service
*        sequence which resets the timeout
*/

#define SWT_FIXED_SERVICE_SEQ1_U32              (0x0000A602UL)

/**
* @brief This constant specifies the value of the second part of the fixed service
*        sequence which resets the timeout
*/
#define SWT_FIXED_SERVICE_SEQ2_U32              (0x0000B480UL)

/**
* @brief  This constant specifies the value that clears the flag and the interrupt. It is
*         written in SWT_IR_ADDR32 on the TIF bit
*/
#define SWT_IR_CLEAR_U32                            (0x00000001UL)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif  /* REG_ESYS_SWT_H */

/** @} */
