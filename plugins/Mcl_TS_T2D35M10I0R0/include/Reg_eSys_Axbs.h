/**
*   @file    Reg_eSys_Axbs.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - Axbs registers and macros definitions.
*   @details Axbs registers and macros definitions.
*
*   @addtogroup MCL
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eDMA
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

#ifndef REG_ESYS_AXBS_H
#define REG_ESYS_AXBS_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_AXBS_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section REG_ESYS_AXBS_H_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section REG_ESYS_AXBS_H_REF_3
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are 
* only accessed from within a single function.
* 
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Reg_eSys.h"
#include "StdRegMacros.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_Axbs.h
* @requirements   
*/
#define AXBS_REG_VENDOR_ID                      43
#define AXBS_REG_AR_RELEASE_MAJOR_VERSION       4
#define AXBS_REG_AR_RELEASE_MINOR_VERSION       2
#define AXBS_REG_AR_RELEASE_REVISION_VERSION    2
#define AXBS_REG_SW_MAJOR_VERSION               1
#define AXBS_REG_SW_MINOR_VERSION               0
#define AXBS_REG_SW_PATCH_VERSION               0


/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Reg_eSys.h header file are of the same Autosar version */
    #if ((REG_ESYS_AR_RELEASE_MAJOR_VERSION != AXBS_REG_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_AR_RELEASE_MINOR_VERSION != AXBS_REG_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys.h and Reg_eSys_Axbs.h are different"
    #endif
#endif

/* Check if header file and StdRegMacros.h header file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((AXBS_REG_AR_RELEASE_MAJOR_VERSION != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (AXBS_REG_AR_RELEASE_MINOR_VERSION != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Reg_eSys_Axbs.h and StdRegMacros.h are different"
    #endif
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define MCL_START_SEC_CONST_32
/** @violates @ref REG_ESYS_AXBS_H_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"
/**
* @violates @ref REG_ESYS_AXBS_H_REF_3 Objects shall defined at block if they  only accessed from
*  within a single function.
*/
extern CONST(uint32, MCL_CONST) AXBS_BASE_ADDR32[MCL_CROSSBAR_NUM_INSTANCES] ;

#define MCL_STOP_SEC_CONST_32
/** @violates @ref REG_ESYS_AXBS_H_REF_2 Repeated include file MemMap.h */
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** AXBS_PRS register */
/** priority values of the masters */
#define AXBS_PRIORITY_0_U32               ((uint32)(0U))
#define AXBS_PRIORITY_1_U32               ((uint32)(1U))
#define AXBS_PRIORITY_2_U32               ((uint32)(2U))
#define AXBS_PRIORITY_3_U32               ((uint32)(3U))
#define AXBS_PRIORITY_4_U32               ((uint32)(4U))
#define AXBS_PRIORITY_5_U32               ((uint32)(5U))
#define AXBS_PRIORITY_6_U32               ((uint32)(6U))
#define AXBS_PRIORITY_7_U32               ((uint32)(7U))

/** mask for master bits */
#define AXBS_PRS_MASK32              ((uint32)(0x77777777UL))
#define AXBS_MASTER0_MASK32          ((uint32)(0x00000007UL))
#define AXBS_MASTER1_MASK32          ((uint32)(0x00000070UL))
#define AXBS_MASTER2_MASK32          ((uint32)(0x00000700UL))
#define AXBS_MASTER3_MASK32          ((uint32)(0x00007000UL))
#define AXBS_MASTER4_MASK32          ((uint32)(0x00070000UL))
#define AXBS_MASTER5_MASK32          ((uint32)(0x00700000UL))
#define AXBS_MASTER6_MASK32          ((uint32)(0x07000000UL))
#define AXBS_MASTER7_MASK32          ((uint32)(0x70000000UL))


/** bits to shift to get the master priority */
#define AXBS_MASTER1_SHIFT_U32           ((uint32)(4U))
#define AXBS_MASTER2_SHIFT_U32           ((uint32)(8U))
#define AXBS_MASTER3_SHIFT_U32           ((uint32)(12U))
#define AXBS_MASTER4_SHIFT_U32           ((uint32)(16U))
#define AXBS_MASTER5_SHIFT_U32           ((uint32)(20U))
#define AXBS_MASTER6_SHIFT_U32           ((uint32)(24U))
#define AXBS_MASTER7_SHIFT_U32           ((uint32)(28U))

/** AXBS_CRS registers */
#define AXBS_LOCK_EN_U32                 ((uint32)(1U))
#define AXBS_LOCK_DIS_U32                ((uint32)(0U))
#define AXBS_HLP_LOWEST_U32              ((uint32)(1U))
#define AXBS_HLP_HIGHEST_U32             ((uint32)(0U))
#define AXBS_HPE_EN_U32                  ((uint32)(1U))
#define AXBS_HPE_DIS_U32                 ((uint32)(0U))
#define AXBS_ARB_FIXED_U32               ((uint32)(0U))
#define AXBS_ARB_ROUND_ROBIN_U32         ((uint32)(1U))
#define AXBS_PCTL_PARK_FIELD_U32         ((uint32)(0U))
#define AXBS_PCTL_LAST_MASTER_U32        ((uint32)(1U))
#define AXBS_PCTL_LOW_POWER_PARK_U32     ((uint32)(2U))
#define AXBS_MASTER_0_U32                 ((uint32)(0U))
#define AXBS_MASTER_1_U32                 ((uint32)(1U))
#define AXBS_MASTER_2_U32                 ((uint32)(2U))
#define AXBS_MASTER_3_U32                 ((uint32)(3U))
#define AXBS_MASTER_4_U32                 ((uint32)(4U))
#define AXBS_MASTER_5_U32                 ((uint32)(5U))
#define AXBS_MASTER_6_U32                 ((uint32)(6U))
#define AXBS_MASTER_7_U32                 ((uint32)(7U))



#define AXBS_LK_BIT_MASK32        ((uint32)(0x80000000UL))
#define AXBS_HLP_BIT_MASK32       ((uint32)(0x40000000UL))
#define AXBS_HPE7_BIT_MASK32       ((uint32)(0x00800000UL))
#define AXBS_HPE6_BIT_MASK32       ((uint32)(0x00400000UL))
#define AXBS_HPE5_BIT_MASK32       ((uint32)(0x00200000UL))
#define AXBS_HPE4_BIT_MASK32       ((uint32)(0x00100000UL))
#define AXBS_HPE3_BIT_MASK32       ((uint32)(0x00080000UL))
#define AXBS_HPE2_BIT_MASK32       ((uint32)(0x00040000UL))
#define AXBS_HPE1_BIT_MASK32       ((uint32)(0x00020000UL))
#define AXBS_HPE0_BIT_MASK32       ((uint32)(0x00010000UL))
#define AXBS_ARB_BITS_MASK32        ((uint32)(0x00000300UL))
#define AXBS_PCTL_BITS_MASK32       ((uint32)(0x00000030UL))
#define AXBS_PARK_BITS_MASK32       ((uint32)(0x00000007UL))

/** shifts for AXBS_CRS registers */
#define AXBS_LOCK_SHIFT_U32               ((uint32)(31U))
#define AXBS_HLP_SHIFT_U32                ((uint32)(30U))
#define AXBS_HPE7_SHIFT_U32               ((uint32)(23U))
#define AXBS_HPE6_SHIFT_U32               ((uint32)(22U))
#define AXBS_HPE5_SHIFT_U32               ((uint32)(21U))
#define AXBS_HPE4_SHIFT_U32               ((uint32)(20U))
#define AXBS_HPE3_SHIFT_U32               ((uint32)(19U))
#define AXBS_HPE2_SHIFT_U32               ((uint32)(18U))
#define AXBS_HPE1_SHIFT_U32               ((uint32)(17U))
#define AXBS_HPE0_SHIFT_U32               ((uint32)(16U))
#define AXBS_ARB_SHIFT_U32                ((uint32)(8U))
#define AXBS_PCTL_SHIFT_U32               ((uint32)(4U))

/** masks for AXBS_MGPCR registers */
#define AXBS_MGPCR_MASK32          ((uint32)0x00000007UL)
/** shifts for AXBS_MGPCR registers */
#define AXBS_AULB_SHIFT_U32            ((uint32)(0U))
/** offsets used to calculate the registers addresses */
#define AXBS_PORT_OFFSET_U32 ((uint32)0x100)
#define AXBS_CRS_OFFSET_U32 ((uint32)0x10)
#define AXBS_MGPCR_OFFSET_U32 ((uint32)0x800)

/**
* @brief macros used to calculate the address of a AXBS_PRS register.
* @violates @ref REG_ESYS_AXBS_H_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define AXBS_PRS_ADDR(u8port, u8instance)  \
    (AXBS_BASE_ADDR32[(u8instance)] +  (AXBS_PORT_OFFSET_U32 * (u8port)))

/**
* @brief macros used to calculate the address of a AXBS_CRS register.
* @violates @ref REG_ESYS_AXBS_H_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define AXBS_CRS_ADDR(u8port, u8instance)  \
    (AXBS_BASE_ADDR32[(u8instance)] +  (AXBS_PORT_OFFSET_U32 * (u8port)) + AXBS_CRS_OFFSET_U32)
    

/**
* @brief macros used to calculate the address of a AXBS_MGPCR register.
* @violates @ref REG_ESYS_AXBS_H_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define AXBS_MGPCR_ADDR(u8port, u8instance)  \
    (AXBS_BASE_ADDR32[(u8instance)] +  (AXBS_PORT_OFFSET_U32 * (u8port)) + AXBS_MGPCR_OFFSET_U32)


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

#endif /* REG_ESYS_AXBS_H */

/** @} */
