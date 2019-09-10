/**
*   @file    Fls_Ac.c
*   @implements Fls_Ac.c_Artifact 
*   @version 1.0.0
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Position independent erase and write access code.
*
*   @addtogroup FLS
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : IPV_FLASHV2
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
* @section fls_ac_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
*
* @section fls_ac_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping.
*
* @section fls_ac_c_REF_3
* Violates MISRA 2004 Required Rule 10.1, Implicit conversion changes signedness.
* Caused by type signedness mismatch between the TRUE and FALSE macros which are defined as signed 
* integers (PLATFORM056) and the boolean data type (PLATFORM027) which is defined as uint8.
*
* @section fls_ac_c_REF_5
* Violates MISRA 2004 Advisory Rule 12.6, boolean expression required for operator: '!'
* This violation because of it is not effectively boolean.
*
* @section fls_ac_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* External linkage required for a global function.
* @section fls_ac_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section fls_ac_c_REF_8
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
* 
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
#include "Reg_eSys_FLASHC.h"
#include "StdRegMacros.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_AC_VENDOR_ID_C                      43U
#define FLS_AC_AR_RELEASE_MAJOR_VERSION_C       4
#define FLS_AC_AR_RELEASE_MINOR_VERSION_C       2
#define FLS_AC_AR_RELEASE_REVISION_VERSION_C    2
#define FLS_AC_SW_MAJOR_VERSION_C               1
#define FLS_AC_SW_MINOR_VERSION_C               0
#define FLS_AC_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
/* 
* @violates @ref fls_ac_c_REF_3 The value of an expression of
* an integer shall no be implicitly converted to a different underlying type if it is not a
* conversion to a wider integer type of the same signedness
*/
#if (FLS_AC_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls_Ac.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls_Ac header file are of the same Autosar version */
#if ((FLS_AC_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AC_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AC_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Ac.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_AC_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_AC_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_AC_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Ac.c and Fls.h are different"
#endif

/* Check if current file and Reg_eSys_FLASHC header file are of the same vendor */
/* 
* @violates @ref fls_ac_c_REF_3 The value of an expression of
* an integer shall no be implicitly converted to a different underlying type if it is not a
* conversion to a wider integer type of the same signedness
*/
#if (FLS_AC_VENDOR_ID_C != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_Ac.c and Reg_eSys_FLASHC.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Autosar version */
#if ((FLS_AC_AR_RELEASE_MAJOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AC_AR_RELEASE_MINOR_VERSION_C    != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AC_AR_RELEASE_REVISION_VERSION_C != ESYS_FLASHC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_Ac.c and Reg_eSys_FLASHC.h are different"
#endif
/* Check if current file and Reg_eSys_FLASHC header file are of the same Software version */
#if ((FLS_AC_SW_MAJOR_VERSION_C != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_AC_SW_MINOR_VERSION_C != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_AC_SW_PATCH_VERSION_C != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Ac.c and Reg_eSys_FLASHC.h are different"
#endif
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief    Start of Fls section CODE_AC 
*
* @violates @ref fls_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#define FLS_START_SEC_CODE_AC
/* 
* @violates @ref fls_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref fls_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

#ifdef _LINARO_C_MPC574XG_ 
    #if FLS_TIMEOUT_HANDLING == STD_ON
    void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort ) __attribute__ ((section (".acfls_code_rom")));
    #else
    void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
    #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#else
    #if FLS_TIMEOUT_HANDLING == STD_ON
    void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort );
    #else
    void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
    #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
#endif
/*==================================================================================================
                                      GLOBAL FUNCTIONS
==================================================================================================*/
/* Position independent erase access code */
#if FLS_TIMEOUT_HANDLING == STD_ON
/*
* @violates @ref fls_ac_c_REF_6 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort )
{
    /* start internal erase/program sequence */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    REG_BIT_SET32(u32RegBaseAddr + FLASH_MCR_OFFSET, FLASH_MCR_EHV_U32 );

    /* wait until operation finishes or write/erase timeout is reached */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    while((0U == REG_BIT_GET32(u32RegBaseAddr + FLASH_MCR_OFFSET, FLASH_MCR_DONE_U32 )) && (0U < *pTimerCounterAC))
    {
        (*pTimerCounterAC)--;
        if (NULL_PTR != CallBack) 
        {
            CallBack();
        }    
    }

    /* disable HV to finalize/abort the operation */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    REG_BIT_CLEAR32(u32RegBaseAddr + FLASH_MCR_OFFSET,FLASH_MCR_EHV_U32 );

    /* wait until done or abort timeout is reached */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    while((0U == REG_BIT_GET32(u32RegBaseAddr + FLASH_MCR_OFFSET, FLASH_MCR_DONE_U32 )) && (0U < *pTimerCounterAbort))
    {
        (*pTimerCounterAbort)--;
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }
    }
}
#else
/*
* @violates @ref fls_ac_c_REF_6 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) )
{
    /* start internal erase/program sequence */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
     REG_BIT_SET32(u32RegBaseAddr + FLASH_MCR_OFFSET, FLASH_MCR_EHV_U32 );

    /* wait until operation finishes or write/erase timeout is reached */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
     while(0U == REG_BIT_GET32(u32RegBaseAddr + FLASH_MCR_OFFSET, FLASH_MCR_DONE_U32 ))
    {
        if (NULL_PTR != CallBack)
        {
            CallBack();
        }
    }

    /* disable HV to finalize/abort the operation */
    /*
    * @violates @ref fls_ac_c_REF_8 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_ac_c_REF_7 A cast should not be performed between a pointer type and an integral type
    */
    REG_BIT_CLEAR32(u32RegBaseAddr + FLASH_MCR_OFFSET,FLASH_MCR_EHV_U32 );
}
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

/**
* @brief    Stop of Fls section CODE_AC 
*
* @violates @ref fls_ac_c_REF_2 Violates MISRA 2004 Required Rule 19.15
*/
#define FLS_STOP_SEC_CODE_AC
/* 
* @violates @ref fls_ac_c_REF_1 Only preprocessor statements
* and comments before '#include'
* @violates @ref fls_ac_c_REF_2 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif
