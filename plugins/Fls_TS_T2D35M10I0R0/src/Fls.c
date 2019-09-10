/**
*   @file    Fls.c
*   @implements Fls.c_Artifact   
*   @version 1.0.0
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Flash driver source code.
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
* @section fls_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
* contents of a header being included twice.
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_c_REF_2
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* Due to casting between a pointer and unsigned long
*
* @section fls_c_REF_3
* Violates MISRA 2004 Required Rule 12.4, Side effects on right hand of logical operator: '||' or '&&'. 
* This violation is because of complex statement
*
* @section fls_c_REF_4
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour
* This violation is because of complex statement
*
* @section fls_c_REF_5
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* This violation is not fixed since if hardware error is detected it should return from the function
*
* @section fls_c_REF_6
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* Return from function as soon as the read/write/erase/operation finished
*
* @section fls_c_REF_7
* Violates MISRA 2004 Advisory Rule 12.6, Booleans operands are not used for logical
* operators '&&', '||' and '!'
* This violation because of it is not effectively boolean
*
* @section fls_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* The cast can not be avoided as it is used to access memory mapped registers.
*
* @section fls_c_REF_9
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping
*
* @section fls_c_REF_10
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic
* This violation is because of complex statement
*
* @section fls_c_REF_11
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* State variables may be used by LLD layer.
*
* @section fls_c_REF_12
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any const and
* volatile qualification from the type address by a pointer
* Because of removing the const qualification from the type address by a pointer
*
* @section fls_c_REF_13
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section fls_c_REF_14
* Violates MISRA 2004 Required Rule 17.2, Pointer subtraction shall only be applied to pointers
* that address elements of the same array
* Due to the pointers that address elements are not the same array
* 
* @section fls_c_REF_15
* Violates MISRA 2004 Required Rule 16.10, Ignoring return value of function.
* The return value is intentionally ignored at this place.
*
* @section fls_c_REF_16
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable.
* The code is not dynamically linked. An absolute stack address is obtained 
* when taking the address of the near auto variable.
*
* @section fls_c_REF_17
* Violates MISRA 2004 Required Rule 13.7, Boolean within 'if' always evaluates to True.
* Depending on the result of the underlying HW erase operation, the condition might be evaluated 
* also to False (note the operands are initialized to FALSE).
*
* @section fls_c_REF_19
* Violates MISRA 2004 Required Rule 8.12,
* When an array is declared with external linkage, its size shall be stated explicitly or defined
* implicitly by initialization.
* For the purpose of copying from ROM to RAM the compiled access code opocode is treated as uint32 array.
* All start, end and size parameters are defined by the linker file and imported into C module as external
* variables.  
* 
* @section fls_c_REF_20
* Violates MISRA 2004 Required Rule 11.1, Conversions involving function pointers must be to/from integral types
* Conversion is made for special purpose - copying the compiled function opcode from ROM to RAM.
* 
* @section fls_c_REF_21
* Violates MISRA 2004 Required Rule 8.7, could define variable at block scope
* The symbol is defined by the linker file and imported into C module as external variable. 
*
* @section fls_c_REF_22 
* Violates MISRA 2004 Required Rule 17.2, Relational or subtract operator applied to pointers
* The pointers point to the same area in RAM where the AC opcode is copied from ROM.
*
* @section fls_c_REF_23 
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness
* The pointer subtraction is made inside while loop and due to its condition the subtraction 
* result is always positive and therefore it can be casted to unsigned. 
*
* @section fls_c_REF_24 
* Violates MISRA 2004 Required Rule 10.3, Cast of complex expression changes signedness
* This is due to boolean conversion.
* 
* @section fls_c_REF_25
* Violates MISRA 2004 Required Rule 11.1, cast from pointer to unsigned long
* Due to casting between a pointer and unsigned long representing address.
* 
* @section fls_c_REF_26
* Violates MISRA 2004 Advisory Rule 11.4, cast from pointer to pointer
* Cast from pointer to pointer to const is desired at this place.    
*
* @section fls_c_REF_27
* Violates MISRA 2004 Required Rule 14.6, more than one 'break' terminates loop
* Once abnormal condition is indicated, the loop is terminated by 'break'. Since 
* there are handled several abnormal conditions, the loop contains more
* than one 'break'.    
*
* @section fls_c_REF_28
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined: 'FLASH_AC_CALL'
* Macro is used for the purpose of abstraction between PPC and ARM platforms.
* 
* @section fls_c_REF_29
* Violates MISRA 2004 Required Rule 11.1, cast from pointer to unsigned long
* On ARM platform, the liker is not aware whether Access Code copied to RAM
* by the FLS driver is compiled in Thumb mode. Therefore LSB bit in its
* address needs to be set to notify the core that the code executed after BLX 
* instruction branching to AC code is in Thumb-encoded.
* 
* @section fls_c_REF_30
* Violates MISRA 2004 Advisory Rule 11.4,  A cast should not be performed between a pointer
* to object type and a different pointer to object type
* The casted value is assigned to the pointer declared with the PACKED compiler directive 
* to prevent the risk listed in the Rule 11.4 
* (invalid conversion if a new pointer requires a stricter alignment).     
*    
* @section fls_c_REF_31
* Violates MISRA 2004 Required Rule 11.5, A cast shall not be performed that removes any const and
* volatile qualification from the type address by a pointer
* This is done intentionally since it's the only reasonable way how to perform an interlock write 
* needed for the flash prefetch buffer invalidation. 
*
* @section fls_c_REF_32
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to a
* function and any type other than an integral type. 
* The cast is made in order to access memory mapped registers.
*
* @section fls_c_REF_33
* Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
* a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
* do-while-zero construct. 
* This is used to abstract the export of configuration sets or for a function define.
*
* @section fls_c_REF_34
* Violates MISRA 2004 Required Rule 10.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating 
* contents in that address.
*
* @section fls_c_REF_35
* Violates MISRA 2004 Required Rule 19.11, All macro identifiers in preprocessor directives shall be defined
* before use, except in #ifdef and #ifndef preprocessor directives and the defined() operator.
* This violation is due to configuration defines, defined in a different file. Those defines are always present.
*
* @section fls_c_REF_36
* Violates MISRA 2004 Advisory Rule 16.7, A pointer parameter in a function prototype should be declared
* as pointer to const if the pointer is not used to modify the addressed object.
* The pointer is used to modify the addressed object.
*
* @section fls_c_REF_37
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as in only one file 
*
* @section fls_c_REF_38
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
* This function may be called from Mcal.h in Base module 
*
* @section fls_c_REF_39
* Violates MISRA 2004 Required Rule 12.10, The comma operator shall not be used
* This comma operator was used for the side effect. The return value from called 
* was not evaluated
*
* @section fls_c_REF_40
* Violates MISRA 2004 Required Rule 17.3, >, >=, <, <=shall not be applied to pointer types 
* except where they point to the same array.
* Due to the pointers that address elements are not the same array
*
* @section fls_c_REF_41
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer
* to a function and any type other than an integral type contents in that address.
* This violation is due to casting unsigned long to pointer and access these addresses for updating 
* contents in that address.
*
* @section fls_c_REF_42
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only accessed
* from within a single function
* This violation because of using variable address instead of its value.

* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, 
* The names of standard library macros, objects and functions shall not be reused. 
* The driver needs to use defines starting with letter E.
*
* 
*/

/* Compiler warning fls_c_REF_CW_01: explicit cast discards volatile qualifier.
   The cast is explicit, intended and the casted value is treated properly. 
   Sizes of the pointers and integral types for all the supported platforms/compilers are well known 
   and the volatile keyword is not needed when using the pointer value as a flash address counter, 
   as the pointer value is not updated in the DSI interrupt context or by other hardware means.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


#include "Fls.h"
#include "Fls_InternalTypes.h"

#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON ))
#include "Det.h"
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */

#include "SchM_Fls.h"

#if (STD_ON == FLS_SYNCRONIZE_CACHE) 
#include "Mcl.h"
#endif /* FLS_SYNCRONIZE_CACHE */
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Reg_eSys_FLASHC.h"
#include "StdRegMacros.h"
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
#define USER_MODE_REG_PROT_ENABLED      (FLS_USER_MODE_REG_PROT_ENABLED)
#include "SilRegMacros.h"    
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_C       2
/*
* @violates @ref fls_c_REF_13 The compiler/linker shall be checked
* to ensure that 31 character significance and case sensitivity are supported for external identifiers
*/
#define FLS_AR_RELEASE_REVISION_VERSION_C    2
#define FLS_SW_MAJOR_VERSION_C               1
#define FLS_SW_MINOR_VERSION_C               0
#define FLS_SW_PATCH_VERSION_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_C != FLS_VENDOR_ID)
    #error "Fls.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls.c and Fls.h are different"
#endif

/* Check if current file and Fls_InternalTypes header file are of the same vendor */
#if (FLS_VENDOR_ID_C != FLS_INTERNALTYPES_VENDOR_ID)
    #error "Fls.c and Fls_InternalTypes.h have different vendor ids"
#endif
/* Check if current file and Fls_InternalTypes header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_C    != FLS_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_C    != FLS_INTERNALTYPES_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_C != FLS_INTERNALTYPES_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls.c and Fls_InternalTypes.h are different"
#endif
/* Check if current file and Fls_InternalTypes header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_C != FLS_INTERNALTYPES_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_C != FLS_INTERNALTYPES_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_C != FLS_INTERNALTYPES_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls.c and Fls_InternalTypes.h are different"
#endif


#if(( FLS_DEV_ERROR_DETECT == STD_ON ) || ( FLS_RUNTIME_ERROR_DETECT == STD_ON )) 
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Det header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Det.h are different"
    #endif
#endif
#endif

#if (STD_ON == FLS_SYNCRONIZE_CACHE) 
    
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Mcl header file are of the same Autosar version */
    #if ((FLS_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Fls.c and Mcl.h are different"
    #endif
#endif

#endif /* FLS_SYNCRONIZE_CACHE */

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/

/** 
    @brief fill pattern used to clear write and erase access code in RAM
*/
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_AC_UNLOAD_PATTERN 0xffffffffU
#endif

/** 
    @brief Calculate total flash size in bytes
*/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#define FLS_TOTAL_SIZE ((*(Fls_pConfigPtr->pSectorEndAddr))[Fls_pConfigPtr->u32SectorCount - 1U] + 1U)
#endif

/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/

#define FLS_START_SEC_CONST_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
*/
#include "Fls_MemMap.h"

  
#define FLASH_SECTOR_COUNT 44U

/**
    @brief FLASH physical sectorization description
*/
static CONST(Fls_Flash_SectorInfoType, FLS_CONST) Fls_Flash_aSectorList0[FLASH_SECTOR_COUNT]=
{
    {   /* FLS_CODE_ARRAY_0_PART_0_L00 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FC0000,
        FLASH_LMS_LSL18_U32,
        FLASH_LML_LLK18_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_0_L01 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FC8000,
        FLASH_LMS_LSL19_U32,
        FLASH_LML_LLK19_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_1_L02 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FD0000,
        FLASH_LMS_LSL20_U32,
        FLASH_LML_LLK20_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_1_L03 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FD8000,
        FLASH_LMS_LSL21_U32,
        FLASH_LML_LLK21_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_0_L04 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FE0000,
        FLASH_LMS_LSL22_U32,
        FLASH_LML_LLK22_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_1_L05 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FF0000,
        FLASH_LMS_LSL24_U32,
        FLASH_LML_LLK24_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_2_M00 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00F90000,
        FLASH_LMS_MSL0_U32,
        FLASH_LML_MLK0_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_2_M01 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00F94000,
        FLASH_LMS_MSL1_U32,
        FLASH_LML_MLK1_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_2_M02 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00F98000,
        FLASH_LMS_MSL2_U32,
        FLASH_LML_MLK2_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_2_M03 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00F9C000,
        FLASH_LMS_MSL3_U32,
        FLASH_LML_MLK3_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_3_M04 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FA0000,
        FLASH_LMS_MSL4_U32,
        FLASH_LML_MLK4_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_3_M05 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FA4000,
        FLASH_LMS_MSL5_U32,
        FLASH_LML_MLK5_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_3_M06 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FA8000,
        FLASH_LMS_MSL6_U32,
        FLASH_LML_MLK6_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_3_M07 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FAC000,
        FLASH_LMS_MSL7_U32,
        FLASH_LML_MLK7_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_2_M08 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FB0000,
        FLASH_LMS_MSL8_U32,
        FLASH_LML_MLK8_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_3_M09 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00FB8000,
        FLASH_LMS_MSL9_U32,
        FLASH_LML_MLK9_U32,
        FLASH_SEL0_ADDR32,
        FLASH_LOCK0_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_6_LG00 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01000000,
        FLASH_LGBS_LGSL0_U32,
        FLASH_LGBL_LGLK0_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_6_LG01 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01040000,
        FLASH_LGBS_LGSL1_U32,
        FLASH_LGBL_LGLK1_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_6_LG02 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01080000,
        FLASH_LGBS_LGSL2_U32,
        FLASH_LGBL_LGLK2_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_6_LG03 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x010C0000,
        FLASH_LGBS_LGSL3_U32,
        FLASH_LGBL_LGLK3_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_6_LG04 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01100000,
        FLASH_LGBS_LGSL4_U32,
        FLASH_LGBL_LGLK4_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_6_LG05 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01140000,
        FLASH_LGBS_LGSL5_U32,
        FLASH_LGBL_LGLK5_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_6_LG06 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01180000,
        FLASH_LGBS_LGSL6_U32,
        FLASH_LGBL_LGLK6_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_6_LG07 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x011C0000,
        FLASH_LGBS_LGSL7_U32,
        FLASH_LGBL_LGLK7_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_7_LG08 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01200000,
        FLASH_LGBS_LGSL8_U32,
        FLASH_LGBL_LGLK8_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_7_LG09 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01240000,
        FLASH_LGBS_LGSL9_U32,
        FLASH_LGBL_LGLK9_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_7_LG10 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01280000,
        FLASH_LGBS_LGSL10_U32,
        FLASH_LGBL_LGLK10_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_7_LG11 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x012C0000,
        FLASH_LGBS_LGSL11_U32,
        FLASH_LGBL_LGLK11_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_7_LG12 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01300000,
        FLASH_LGBS_LGSL12_U32,
        FLASH_LGBL_LGLK12_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_7_LG13 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01340000,
        FLASH_LGBS_LGSL13_U32,
        FLASH_LGBL_LGLK13_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_7_LG14 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01380000,
        FLASH_LGBS_LGSL14_U32,
        FLASH_LGBL_LGLK14_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_7_LG15 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x013C0000,
        FLASH_LGBS_LGSL15_U32,
        FLASH_LGBL_LGLK15_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_8_LG16 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01400000,
        FLASH_LGBS_LGSL16_U32,
        FLASH_LGBL_LGLK16_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_8_LG17 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01440000,
        FLASH_LGBS_LGSL17_U32,
        FLASH_LGBL_LGLK17_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_8_LG18 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01480000,
        FLASH_LGBS_LGSL18_U32,
        FLASH_LGBL_LGLK18_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_9_LG19 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x014C0000,
        FLASH_LGBS_LGSL19_U32,
        FLASH_LGBL_LGLK19_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_9_LG20 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01500000,
        FLASH_LGBS_LGSL20_U32,
        FLASH_LGBL_LGLK20_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_9_LG21 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x01540000,
        FLASH_LGBS_LGSL21_U32,
        FLASH_LGBL_LGLK21_U32,
        FLASH_SEL2_ADDR32,
        FLASH_LOCK2_ADDR32,
        (boolean)TRUE
    },
    {   /* FLS_UTEST_ARRAY_0_PART_0_L00 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00400000,
        FLASH_LMS_TSSL_U32, /* Not exist in SEL0 */
        FLASH_LML_TSLK_U32,
        FLASH_SEL0_ADDR32, 
        FLASH_LOCK0_ADDR32, 
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_0_SHSM00 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00F8C000,
        FLASH_LML_LLK16_U32, 
        FLASH_LMS_LSL16_U32,
        FLASH_SEL0_ADDR32, 
        FLASH_LOCK0_ADDR32,  
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_0_HSM02 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00610000,
        FLASH_LML_LLK23_U32, 
        FLASH_LMS_LSL23_U32,
        FLASH_SEL0_ADDR32, 
        FLASH_LOCK0_ADDR32, 
        (boolean)TRUE
    },
    {   /* FLS_CODE_ARRAY_0_PART_1_HSM03 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00620000,
        FLASH_LML_LLK25_U32, 
        FLASH_LMS_LSL25_U32,
        FLASH_SEL0_ADDR32, 
        FLASH_LOCK0_ADDR32, 
        (boolean)TRUE
    },
    {   /* FLS_DATA_ARRAY_0_PART_4_HSM00 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00F80000,
        FLASH_HBL_HLK0_U32, 
        FLASH_HBS_HSL0_U32,
        FLASH_SEL1_ADDR32, 
        FLASH_LOCK1_ADDR32, 
        (boolean)FALSE
    },
    {   /* FLS_DATA_ARRAY_0_PART_5_HSM01 */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        (volatile uint32*)0x00F84000,
        FLASH_HBL_HLK1_U32, 
        FLASH_HBS_HSL1_U32,
        FLASH_SEL1_ADDR32, 
        FLASH_LOCK1_ADDR32, 
        (boolean)FALSE
    }    
};


#define FLASH_ARRAY_COUNT 1U

/**
    @brief FLASH array description
*/
static CONST(Fls_Flash_ArrayInfoType, FLS_CONST) Fls_Flash_aArrayList0[FLASH_ARRAY_COUNT]=
{
    {    /* FLS_CODE_ARRAY_0_A */
        (boolean)TRUE,
        (boolean)TRUE
    }
};

#if (FLS_BLANK_CHECK_API == STD_ON)
/**
    @brief Flash erased value for erased state
*/
/*
* @violates @ref fls_c_REF_42 Objects shall be defined at block scope if they are only accessed
* from within a single function 
*/
static CONST(uint32, FLS_CONST) Fls_Flash_ErasedValue = FLS_ERASED_VALUE;
#endif

typedef uint32 Fls_Flash_DataBusWidthType; 
#define FLASH_DSI_EXC_SYNDROME (0x00088008UL)
#define FLASH_DSI_EXC_SYNDROME_CACHE    (0x00080008UL)

#define FLASH_INTERLEAVED_BLOCK  (STD_OFF)

/* Is there at least one (DATA) flash sector where ECCs does not lead to the exception? yes/no => STD_ON/STD_OFF */
#define FLASH_DATA_FLASH_EXISTS  (STD_ON)

#define FLASH_READSIZE   32U



#define FLS_STOP_SEC_CONST_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/** 
* @brief Maximum number of bytes to read or compare in one cycle of Fls_MainFunction
*/
static VAR(Fls_LengthType, FLS_VAR) Fls_u32MaxRead = 0UL;
/** 
* @brief Maximum number of bytes to write in one cycle of Fls_MainFunction
*/
static VAR(Fls_LengthType, FLS_VAR) Fls_u32MaxWrite = 0UL;
/** 
* @brief Logical address of data block currently processed by Fls_MainFunction
*/
static VAR(Fls_AddressType, FLS_VAR) Fls_u32JobAddrIt = 0UL;
/** 
* @brief Last logical address to be processed by a job
*/
static VAR(Fls_AddressType, FLS_VAR) Fls_u32JobAddrEnd = 0UL;
/** 
* @brief Index of flash sector currently processed by a job
* @details Used by all types of job
*/
static VAR(Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorIt = 0UL;
/** 
* @brief Index of last flash sector to be erase by current job
* @details Used only by erase job
*/
static VAR(Fls_SectorIndexType, FLS_VAR) Fls_u32JobSectorEnd = 0UL;
/** 
* @brief Result of last flash module job
* @implements Fls_eJobResult_Object
*/
static VAR(MemIf_JobResultType, FLS_VAR) Fls_eJobResult = MEMIF_JOB_OK;
/** 
* @brief Type of currently executed job (erase, write, read, or compare)
*/
static VAR(Fls_JobType, FLS_VAR) Fls_eJob = FLS_JOB_ERASE;
/** 
* @brief Pointer to current flash module configuration set
*/
static P2CONST(Fls_ConfigType, FLS_VAR, FLS_APPL_CONST) Fls_pConfigPtr = NULL_PTR;
#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_8
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/** 
* @brief Pointer to current position in source data buffer
* @details Used by both write and compare jobs
*/
static P2CONST( uint8, FLS_VAR, FLS_APPL_CONST ) Fls_pJobDataSrcPtr = NULL_PTR;
/** 
* @brief Pointer to current position in target data buffer
* @details Used only by read job
*/
static P2VAR( uint8, FLS_VAR, FLS_APPL_DATA ) Fls_pJobDataDestPtr = NULL_PTR;
/** 
* @brief Indicates that new job has been accepted
* @details Used by all types of job
*/
static VAR(uint8, FLS_VAR) Fls_u8JobStart = (uint8)0;
#define FLS_STOP_SEC_VAR_INIT_8
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/** 
* @brief Pointer to current flash module configuration set
* @implements Fls_u32AccCRCremainder_Object
*/
static VAR(uint32, FLS_VAR) Fls_u32AccCRCremainder = 0U;

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"



#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/** 
    @brief Result of last flash hardware job
*/
static VAR(MemIf_JobResultType, FLS_VAR) Fls_Flash_eJobResult = MEMIF_JOB_OK;
/** 
    @brief Type of current flash hardware job
*/
static VAR(Fls_Flash_JobType, FLS_VAR) Fls_Flash_eJob = FLASH_JOB_NONE;
#if( FLS_DSI_HANDLER_API == STD_ON )
/** 
    @brief Current status of the sector read operation. The Fls_DsiHandler function can terminate
        the read operation by setting this volatile variable to FLASH_E_FAILED
*/
static VAR( volatile Fls_Flash_ReturnType, FLS_VAR ) Fls_Flash_eReadStatus = FLASH_E_OK;

/** 
    @brief Current status of the sector compare operation. The Fls_DsiHandler function can terminate
        the compare operation by setting this volatile variable to FLASH_E_FAILED
*/
/* @violates @ref fls_c_REF_42 Could define variable at block scope */
static VAR( volatile Fls_Flash_ReturnType, FLS_VAR ) Fls_Flash_eCompareStatus = FLASH_E_OK;
#endif

/** 
    @brief Number of bytes of data left to write.
*/
static VAR(Fls_LengthType, AUTOMATIC) Fls_Flash_u32RemainingData=0UL;
#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_8
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/**
    @brief Physical address of currently read uint8, uint32 from flash
*/
/* @violates @ref fls_c_REF_42 Could define variable at block scope */
static P2CONST(volatile uint8, FLS_VAR, FLS_APPL_CONST) volatile Fls_Flash_pReadAddressPtr = NULL_PTR;
/**
    @brief Physical address of currently compared uint8, uint32 from user buffer
*/
/* @violates @ref fls_c_REF_42 Could define variable at block scope */
static P2CONST(volatile uint8, FLS_VAR, FLS_APPL_CONST) volatile Fls_Flash_pCompareAddressPtr = NULL_PTR;
#define FLS_STOP_SEC_VAR_INIT_8
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
/** 
    @brief 'double word program operation' iterator
*/
static VAR(uint32, FLS_VAR) Fls_Flash_u32ProgramCycle = 0UL;

/** 
    @brief 'double word program operation' count
*/
static VAR(uint32, FLS_VAR) Fls_Flash_u32DoubleWordToCopy = 0UL;
/** 
    @brief 'number of word / double word needed for program operation'
*/
static VAR(uint32, FLS_VAR) Fls_Flash_u32DoubleWordCounter = 0UL;

/** 
    @brief 'data copy' auxiliary pointers
*/
static P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_Flash_pTargetAddressPtr = NULL_PTR;
static P2CONST(uint32, FLS_VAR, FLS_APPL_CONST) Fls_Flash_pSourceAddressPtr = NULL_PTR;
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
static P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) Fls_Flash_pEndAddressPtr = NULL_PTR;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */


#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
    static VAR(Fls_LengthType, AUTOMATIC) Fls_Flash_u32NumberOfStepBack = 0UL;
#endif

#if (FLS_TIMEOUT_HANDLING == STD_ON)
/**
    @brief Timeout counter used in both sync/async modes
  */
static VAR(uint32, FLS_VAR) Fls_Flash_u32Timeout_Counter = 0U;
#endif

#define FLS_STOP_SEC_VAR_INIT_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_BOOLEAN
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
#define FLS_STOP_SEC_VAR_INIT_BOOLEAN
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
#define FLS_START_SEC_CONST_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/* Start Position and Size of erase access code in flash */
/* @violates @ref fls_c_REF_19 For fixed array size. */
/* @violates @ref fls_c_REF_21 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) Fls_ACEraseRomStart[];
/* @violates @ref fls_c_REF_19 For fixed array size. */
/* @violates @ref fls_c_REF_21 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) Fls_ACEraseSize[];

/* Start Position and Size of write access code in flash */
/* @violates @ref fls_c_REF_19 For fixed array size. */
/* @violates @ref fls_c_REF_21 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) Fls_ACWriteRomStart[];
/* @violates @ref fls_c_REF_19 For fixed array size. */
/* @violates @ref fls_c_REF_21 Could define variable at block scope */
extern CONST(uint32, FLS_CONST) Fls_ACWriteSize[];

#define FLS_STOP_SEC_CONST_32
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
#endif /* FLS_AC_LOAD_ON_JOB_START == STD_ON */

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/    

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"
static FUNC(Fls_SectorIndexType, FLS_CODE) Fls_GetSectorIndexByAddr
 (CONST (Fls_AddressType, AUTOMATIC) u32TargetAddress );
static FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr
( CONST(Fls_SectorIndexType, AUTOMATIC) u32SectorIndex );
#if( FLS_DEV_ERROR_DETECT == STD_ON )
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageStartAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
static FUNC(boolean, FLS_CODE) Fls_IsLengthAligned
(
    CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress,
    CONST(Fls_LengthType, AUTOMATIC) u32Length
);
static FUNC(boolean, FLS_CODE) Fls_IsAddrSectorStartAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
static FUNC(boolean, FLS_CODE) Fls_IsAddrSectorEndAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress );
#endif
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
static FUNC( void, FLS_CODE ) Fls_LoadAc
( CONST( Fls_JobType, AUTOMATIC) eJob );
static FUNC( void, FLS_CODE ) Fls_UnloadAc
( CONST( Fls_JobType, AUTOMATIC) eJob );
#endif
static FUNC(void, FLS_CODE) Fls_AccumulateCRC
( VAR(uint32, AUTOMATIC) u32InputData );
static FUNC(void, FLS_CODE) Fls_ResetCRC ( void );
static FUNC(uint32, FLS_CODE) Fls_FinalizeCRC ( void );
static FUNC( void, FLS_CODE ) Fls_UpdateCRCreminder ( VAR(Fls_CrcDataSizeType, AUTOMATIC) eDataSize );
static FUNC( Fls_CrcType, FLS_CODE )  Fls_CalcCfgCRC( void );
static FUNC( MemIf_JobResultType, FLS_CODE )  Fls_DoJobErase( void );
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcMaxTransferAddrEnd
( CONST( Fls_LengthType, AUTOMATIC) u32MaxTransfer );
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferOffset( void );
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferLength
( CONST( Fls_AddressType, AUTOMATIC) u32MaxTransferEndAddr );
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_DoJobRead
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
);
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_DoJobWrite
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
);
#if( FLS_COMPARE_API == STD_ON )
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_DoJobCompare
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
);
#endif
#if (FLS_BLANK_CHECK_API == STD_ON)
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_DoJobBlankCheck
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
);
#endif /* FLS_BLANK_CHECK_API == STD_ON */
static FUNC( MemIf_JobResultType, FLS_CODE ) Fls_DoJobDataTransfer
( 
    CONST( Fls_JobType, AUTOMATIC) eJob,
    CONST( Fls_LengthType, AUTOMATIC) u32MaxTransfer 
);
#if( FLS_USE_INTERRUPTS == STD_ON )
static FUNC(void, FLS_CODE) Fls_EnableInterruptProccessing ( void );
#if ( FLS_CANCEL_API == STD_ON )
static FUNC(void, FLS_CODE) Fls_DisableInterruptProccessing ( void );
#endif /* FLS_CANCEL_API == STD_ON */
#endif /* FLS_USE_INTERRUPTS == STD_ON */

#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#define FLS_START_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef MCAL_PLATFORM_ARM
#define FLASH_ARM_FAR_CALL2THUMB_CODE_BIT0_U32 (0x00000001UL)
    /* Macro for Access Code Call. On ARM/Thumb, BLX instruction used by the compiler for calling a function
       pointed to by the pointer requires that LSB bit of the address is set to one if the called fcn is coded in Thumb. */ 
    /* @violates @ref fls_c_REF_28 Function-like macro defined */
    #define FLASH_AC_CALL(ptr2fcn, ptr2fcnType) ((ptr2fcnType)(((uint32)(ptr2fcn)) | FLASH_ARM_FAR_CALL2THUMB_CODE_BIT0_U32))
#else
    /* @violates @ref fls_c_REF_28 Function-like macro defined */
    #define FLASH_AC_CALL(ptr2fcn, ptr2fcnType) (ptr2fcn)
#endif
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
    FUNC(void, FLS_CODE) Fls_Flash_SetUserAccessAllowed(void);    
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */
static FUNC( MemIf_JobResultType, FLS_CODE ) Fls_Flash_GetJobResult( void );
static FUNC( void, FLS_CODE ) Fls_Flash_Init( void );
static FUNC( void, FLS_CODE ) Fls_Flash_ClrJobResult( void );
static FUNC( void, FLS_CODE ) Fls_Flash_AbortSuspended(void);
#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ))
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_VerifyErase
(
    P2CONST(volatile Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pFlashAreaPtr,
    CONST( Fls_LengthType, AUTOMATIC) u32DataLength               
);
#endif    /* FLS_ERASE_BLANK_CHECK || FLS_WRITE_BLANK_CHECK */
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_VerifyWrite
(
    P2CONST( volatile Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pFlashAreaPtr,
    P2CONST( Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pUserBufferPtr,
    CONST( Fls_LengthType, AUTOMATIC) u32DataLength               
);
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */
static FUNC( void, FLS_CODE ) Fls_Flash_MainFunction( void );
#if (FLS_CANCEL_API == STD_ON )
static FUNC( void, FLS_CODE ) Fls_Flash_Cancel( void );
#endif   /* FLS_CANCEL_API == STD_ON */
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_SectorErase
(
    CONST( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector,
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    CONST( Fls_LengthType, AUTOMATIC) u32PhysicalSectorSize,
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
    CONST( boolean, AUTOMATIC) bAsynch
);
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_SectorWrite
(
    CONST( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr,
    CONST( boolean, AUTOMATIC) bAsynch
);
static FUNC( void, FLS_CODE ) Fls_Flash_PageWrite
( 
    CONST(uint32, AUTOMATIC) u32TotalBytes        
);
static FUNC( uint32, FLS_CODE ) Fls_Flash_CalcInitDataLength
( 
    CONSTP2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) volatile pSourceAddrPtr,
    CONST(uint32, AUTOMATIC) u32TotalBytes 
);
static FUNC( uint32, FLS_CODE ) Fls_Flash_CalcWideDataLength
(
    CONST(uint32, AUTOMATIC) u32InitDataLength,
    CONST(uint32, AUTOMATIC) u32TotalBytes 
);
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_SectorRead
(
    CONST( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pDataPtr
);
#if(( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_SectorCompare
(
    CONST( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr
);
#endif
static FUNC( boolean, FLS_CODE ) Fls_Flash_FinishHVOperation( void );
   
#if(( FLS_DSI_HANDLER_API == STD_ON )&&( FLASH_DATA_FLASH_EXISTS == STD_ON ))
#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_VERIFY_CHECK == STD_ON ))
static FUNC( Fls_Flash_PhysicalSectorType, FLS_CODE ) Fls_GetPhySectorByAddr
( CONST(Fls_AddressType, AUTOMATIC) u32PhyAddress );
#endif /* (( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_VERIFY_CHECK == STD_ON )) */
#endif /* (( FLS_DSI_HANDLER_API == STD_ON )&&( FLASH_DATA_FLASH_EXISTS == STD_ON )) */

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
/** 
* @brief        Enable user mode support to access C55FMC registers
*
* @details      Set UAA bit in FLASH_REG_PROT_GCR to allow user access locked registers in C55FMC module
*
* @param[in]    none   
* @retval       none
*
* @pre         The user mode is enabled       
*    
*/
/*
* @violates @ref fls_c_REF_38 All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage required
*/
FUNC(void, FLS_CODE) Fls_Flash_SetUserAccessAllowed(void)
{
    /*
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
   /* Set UAA bit in REG_PROT register */
   SET_USER_ACCESS_ALLOWED(FMCR_BASEADDR);
}
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */

#if(( FLS_DSI_HANDLER_API == STD_ON )&&( FLASH_DATA_FLASH_EXISTS == STD_ON ))
#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_VERIFY_CHECK == STD_ON ))
/** 
* @brief        Maps physical address to physical sector index
*
* @details      Calculate index of physical sector u32PhyAddress belongs to
*
* @param[in]    u32PhyAddress Physical address in flash memory
*
* @return       Zero based index of physical sector
* @retval       0 .. (FLASH_SECTOR_COUNT - 1)
*
* @pre          The module must be initialized
* @pre          u32PhyAddress must be in supported flash boundary
*    
*/
static FUNC( Fls_Flash_PhysicalSectorType, FLS_CODE ) Fls_GetPhySectorByAddr
( CONST(Fls_AddressType, AUTOMATIC) u32PhyAddress )
{
    VAR( Fls_AddressType, AUTOMATIC) u32AddrOffset;
    VAR( Fls_AddressType, AUTOMATIC) u32AddrOffsetMin = 0xFFFFFFFFUL;
    VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySectorIt;
    VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector = (Fls_Flash_PhysicalSectorType)0;
    
    /* Compiler_Warning: enumerated type mixed with another type.
       Counting from (Fls_Flash_PhysicalSectorType)0 is the safest way how to ensure iterating through all flash sectors. 
       Since ePhySectorIt is also used as an array index, the first enum value in the Fls_Flash_PhysicalSectorType 
       must be always 0. 
       If we use e.g. FLS_UTEST_ARRAY_0_PART_0_L00 instead of (Fls_Flash_PhysicalSectorType)0, the implementation will 
       become dependent on the actual sector naming and error-prone in the case of potential sector reordering.        
    */
    for( ePhySectorIt = (Fls_Flash_PhysicalSectorType)0; ePhySectorIt < (Fls_Flash_PhysicalSectorType)FLASH_SECTOR_COUNT; ePhySectorIt++ )
    {    
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        * @violates @ref fls_c_REF_25 Cast from pointer to unsigned long
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        if( u32PhyAddress >= (Fls_AddressType)Fls_Flash_aSectorList0[ePhySectorIt].pSectorStartAddressPtr )
        {      
            /* 
            * @violates @ref fls_c_REF_25 Cast from pointer to unsigned long 
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type
            */
            /* Compiler_Warning: see fls_c_REF_CW_01 */
            u32AddrOffset =  u32PhyAddress - (Fls_AddressType)Fls_Flash_aSectorList0[ePhySectorIt].pSectorStartAddressPtr;
            
            /* Addresses in Fls_Flash_aSectorList0 are not sorted. Therefore we have to indentify 
               the sector with the nearest start address below u32PhyAddress */
            if (u32AddrOffset < u32AddrOffsetMin)
            {
                u32AddrOffsetMin = u32AddrOffset;
                ePhySector = ePhySectorIt;   
            } 
        }
        else
        {
            /* Check next sector */
        }        
    }
   
    return ePhySector;
}
#endif /* (( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_VERIFY_CHECK == STD_ON )) */
#endif /* (( FLS_DSI_HANDLER_API == STD_ON )&&( FLASH_DATA_FLASH_EXISTS == STD_ON )) */


/**
* @brief          Disables HV operation with timeout.
* @return         Success (DONE)
*/
static FUNC( boolean, FLS_CODE ) Fls_Flash_FinishHVOperation( void )
{
#if FLS_TIMEOUT_HANDLING == STD_ON
    uint32 u32TimerCounterAbort = FLS_ABT_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    VAR(boolean, AUTOMATIC) bRetVal;

    /* disable HV to finalize/abort the operation */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32);
    
#if FLS_TIMEOUT_HANDLING == STD_ON
    /* wait until done or abort timeout is reached */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    while((0U == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32)) && (0U < u32TimerCounterAbort) )
    {
        --u32TimerCounterAbort;
    }
#else
    /* wait until done or abort timeout is reached */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    while(0U == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32))
    {
    }
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    /* return true if DONE */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    if (REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32))
    {
        bRetVal = (boolean)TRUE; 
    }
    else
    {
        bRetVal = (boolean)FALSE;
    }
    
    MCAL_FAULT_INJECTION_POINT(FLS_FIP_10_FLS_FLASH_FINISH_HV_OPERATION);
    
    return(bRetVal);
}


/**
* @brief          Returns the LLD JobResult
*/
static FUNC( MemIf_JobResultType, FLS_CODE ) Fls_Flash_GetJobResult( void )
{
    return( Fls_Flash_eJobResult );
}

/**
* @brief          Initialize flash hardware.
*/    
static FUNC( void, FLS_CODE ) Fls_Flash_Init( void )
{
    VAR(uint32, AUTOMATIC) u32McrValue = 0UL;    
    /* Use diffrent iterator for configured array and physical one */
    VAR(uint32, AUTOMATIC) u32ArrayIter = 0UL;
    VAR(uint32, AUTOMATIC) u32ConfigIter=0UL;

    Fls_Flash_eJobResult = MEMIF_JOB_OK;
#if (STD_ON == FLS_ENABLE_USER_MODE_SUPPORT)
    /*
    * @violates @ref fls_c_REF_39 The comma operator shall not be used
    */
    /* Enable user mode support */ 
  (void) Mcal_Trusted_Call(Fls_Flash_SetUserAccessAllowed,());
#endif /* STD_ON == FLS_ENABLE_USER_MODE_SUPPORT */

    /* iterate over all configured sectors (note now they are allowed to be sorted 
       independently of their physical order) */
    for (u32ConfigIter = 0U; u32ConfigIter < Fls_pConfigPtr->u32SectorCount; u32ConfigIter++ )
    { 
        /* This sector is configured to be unlocked? */
        if (1U == (*(Fls_pConfigPtr->pSectorUnlock))[u32ConfigIter]) 
        {
            /* Translate u32ConfigIter into Sector list Array index (u32ArrayIter)  */
            u32ArrayIter = (uint32)(*(Fls_pConfigPtr->pPhysicalSector))[u32ConfigIter];
             
            /* Read LOCK registers */        
            /* If belong to LOCK0 register */
            if(FLASH_LOCK0_ADDR32==Fls_Flash_aSectorList0[u32ArrayIter].u32AddrSpaceBloLockRegAddr)
            {
                /* Directly set protection bit */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */
                REG_BIT_CLEAR32(FLASH_LOCK0_ADDR32, Fls_Flash_aSectorList0[u32ArrayIter].u32AddrSpaceBloLockValue);
            }
            else if (FLASH_LOCK1_ADDR32==Fls_Flash_aSectorList0[u32ArrayIter].u32AddrSpaceBloLockRegAddr)
            {
                /* Directly set protection bit */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */
                REG_BIT_CLEAR32(FLASH_LOCK1_ADDR32, Fls_Flash_aSectorList0[u32ArrayIter].u32AddrSpaceBloLockValue);
            }
            else if (FLASH_LOCK2_ADDR32==Fls_Flash_aSectorList0[u32ArrayIter].u32AddrSpaceBloLockRegAddr)
            {
                /* Directly set protection bit */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */   
                REG_BIT_CLEAR32(FLASH_LOCK2_ADDR32, Fls_Flash_aSectorList0[u32ArrayIter].u32AddrSpaceBloLockValue);
            }
            else if (FLASH_LOCK3_ADDR32==Fls_Flash_aSectorList0[u32ArrayIter].u32AddrSpaceBloLockRegAddr)
            {
                /* Directly set protection bit */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */   
                REG_BIT_CLEAR32(FLASH_LOCK3_ADDR32, Fls_Flash_aSectorList0[u32ArrayIter].u32AddrSpaceBloLockValue);
            }
            else
            {
                /* No operation */
            }
        }
    } /* for (u32ConfigIter = 0U; u32ConfigIter < Fls_pConfigPtr->u32SectorCount; u32ConfigIter++ ) */   


    u32ArrayIter = 0U;
    /* process all FLASH arrays */
    for( u32ArrayIter = 0U; u32ArrayIter < FLASH_ARRAY_COUNT; u32ArrayIter++ )
    {        
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_7_FLS_FLASH_INIT);
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */          
        u32McrValue =  REG_READ32(FLASH_MCR_ADDR32);
        /* is program suspend operation possible within array? */      
        if(Fls_Flash_aArrayList0[u32ArrayIter].bProgramSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */             
            if(REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32))
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended program operation, and */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32);                
                MCAL_FAULT_INJECTION_POINT(FLS_FIP_8_FLS_FLASH_INIT);
                
                /* if definitely in suspended operation state ...
                  (PSUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                if(0U == REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32))
                {
                    /* immediatly abort it */
                    if( Fls_Flash_FinishHVOperation() )
                    {
                        /* terminate aborted program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */ 
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32);
                    }
                    else
                    {
                        /* Error, program was not aborted */
                        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_WRITE_FAILED);
                        #endif
                       
                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_FAILED;

                    }
                }
                else
                {
                    /* Error, program was not resumed because it is not yet suspended */
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_WRITE_FAILED);
                    #endif

                    Fls_Flash_eJob = FLASH_JOB_NONE;
                    Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                
                }
            }
        }
        
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_1_FLS_FLASH_INIT);
        
        /* update the value of MCR register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */          
        u32McrValue =  REG_READ32(FLASH_MCR_ADDR32);
        /* is erase suspend operation possible within array? */
        if(Fls_Flash_aArrayList0[u32ArrayIter].bEraseSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */ 
            if(REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32))
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended erase operation, and */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32);
                
                MCAL_FAULT_INJECTION_POINT(FLS_FIP_2_FLS_FLASH_INIT);
                
                /* if definitely in suspended operation state ...
                  (ESUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                if(0U == REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32))
                {
                    /* immediatly abort it */
                    if( Fls_Flash_FinishHVOperation() )
                    {
                        /* terminate aborted erase operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */ 
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32);
                    }
                    else
                    {
                        /* Error, erase was not aborted */
                        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ERASE_FAILED);
                        #endif
                        
                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                    }
                }
                else
                {
                    /* Error, erase was not resumed because it is not yet suspended */
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ERASE_FAILED);
                    #endif

                    Fls_Flash_eJob = FLASH_JOB_NONE;
                    Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                
                }
            }
        }
        /* update the value of MCR register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        u32McrValue = REG_READ32(FLASH_MCR_ADDR32);
        /* abort possible pending normal erase/program operation */
        if((0U != (u32McrValue & FLASH_MCR_ERS_U32)) || (0U != (u32McrValue & FLASH_MCR_PGM_U32)))
        {
           /* manage abort possible pending normal erase/program operation */  
            if( Fls_Flash_FinishHVOperation() )
            {
                /* terminate erase operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */                
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32);
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32);
            }
            else
            {
                /* Error, operation was not aborted */
                #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                if( 0U != (u32McrValue & FLASH_MCR_ERS_U32) )
                {
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_ERASE_FAILED);
                }
                if( 0U != (u32McrValue & FLASH_MCR_PGM_U32) )
                {
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_WRITE_FAILED);
                }
                #endif

                Fls_Flash_eJob = FLASH_JOB_NONE;
                Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                
            }
        }

        /* clear possible SBC, EER, RWE events within array */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        REG_BIT_SET32(FLASH_MCR_ADDR32,FLASH_MCR_SBC_W1C|FLASH_MCR_EER_W1C|FLASH_MCR_RWE_W1C);

        /* clear block select registers */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */         
        REG_WRITE32(FLASH_SEL0_ADDR32,0U);
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */     
        REG_WRITE32(FLASH_SEL1_ADDR32,0U);
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */         
        REG_WRITE32(FLASH_SEL2_ADDR32,0U);
    }

}


/**
* @brief          Mangeing Abort Erase suspend.
* @details        An erase suspend is resumed and after immediatly aborted 
*/
static FUNC( void, FLS_CODE ) Fls_Flash_AbortSuspended()
{
    VAR(uint32, AUTOMATIC) u32ArrayIter = 0UL;
    VAR(uint32, AUTOMATIC) u32McrValue = 0UL;
    
    for( u32ArrayIter = 0U; u32ArrayIter < FLASH_ARRAY_COUNT; u32ArrayIter++ )
    {        
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_5_FLS_FLASH_ABORT_SUSPENDED);     
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */   
        u32McrValue = REG_READ32(FLASH_MCR_ADDR32);
        /* is program suspend operation possible within array? */      
        if(Fls_Flash_aArrayList0[u32ArrayIter].bProgramSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            if(0U != (u32McrValue & FLASH_MCR_PSUS_U32))
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended program operation, and */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */   
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32);    

                MCAL_FAULT_INJECTION_POINT(FLS_FIP_6_FLS_FLASH_ABORT_SUSPENDED);
                /* if definitely in suspended operation state ...
                  (PSUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */  
                if(0U == REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_PSUS_U32))
                {
                    /* immediatly abort it */
                    if( Fls_Flash_FinishHVOperation() )
                    {
                        /* terminate aborted program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */     
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32);
                    }
                    else
                    {
                        /* Error, program was not aborted */
                        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                        #endif

                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                    }
                }
                else
                {
                    /* Error, program was not resumed because it is not yet suspended */
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                    #endif
                    
                    Fls_Flash_eJob = FLASH_JOB_NONE;
                    Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                
                }
            }
        }
        
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_3_FLS_FLASH_ABORT_SUSPENDED);
        
        /* update the value of MCR register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */  
        u32McrValue = REG_READ32(FLASH_MCR_ADDR32);
        /* is erase suspend operation possible within array? */
        if(Fls_Flash_aArrayList0[u32ArrayIter].bEraseSuspPossible)
        {
            /* this sector a candidate to be in erase suspend operation state */
            if(0U != (u32McrValue & FLASH_MCR_ESUS_U32))
            {
                /* suspended operation cannot be aborted, */
                /* so resume previously suspended erase operation, and */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32);
                
                MCAL_FAULT_INJECTION_POINT(FLS_FIP_4_FLS_FLASH_ABORT_SUSPENDED);
                
                /* if definitely in suspended operation state ...
                  (ESUS Bit can be cleared only if suspended operation is completed)*/
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */                 
                if(0U == REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_ESUS_U32))
                {
                    /* immediatly abort it */
                    if( Fls_Flash_FinishHVOperation() )
                    {
                        /* terminate aborted erase operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */ 
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32);
                    }
                    else
                    {
                        /* Error, erase was not aborted */
                        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
                        #endif

                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                    }
                }
                else
                {
                    /* Error, erase was not resumed because it is not yet suspended */
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
                    #endif

                    Fls_Flash_eJob = FLASH_JOB_NONE;
                    Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                
                }
            }
        }        
    }
}    

/**
* @brief          Clear status of erase or write hardware job result.
* @details        Set the internal status to  MEMIF_JOB_OK
*/  
static FUNC( void, FLS_CODE ) Fls_Flash_ClrJobResult( void )
{
    Fls_Flash_eJobResult = MEMIF_JOB_OK;
}

#if(( FLS_ERASE_BLANK_CHECK == STD_ON ) || ( FLS_WRITE_BLANK_CHECK == STD_ON ))
/**
* @brief          Check that the addressed flash memory area is erased.
* @details        The function compares the contents of the addressed flash memory 
*                 area against the value of an erased flash cell to check that the block 
*                 has been completely erased
*
* @param[in]      1           pFlashAreaPtr first address of the addressed flash memory area
*                             aligned to the MCU bus width
* @param[in]      2           u32DataLength number of bytes to check (aligned to the bus width)
*
* @return         Fls_Flash_ReturnType
* @retval         FLASH_E_OK operation succeeded
* @retval         FLASH_E_FAILED operation failed due to hardware error (ECC)
*                 or contents of the addressed memory area don't match with value of 
*                 an erased flash cell
*
* @note           Report the FLS_E_VERIFY_ERASE_FAILED Det error when the blank 
*                 check operation failed due to hardware error (ECC) or contents of 
*                 the addressed memory area didn't match with value of an erased 
*                 flash cell
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_VerifyErase
(
    P2CONST(volatile Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pFlashAreaPtr,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength 
)
{
    VAR(Fls_Flash_ReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) pFlashAreaEndPtr = \
           /*
           * @violates @ref fls_c_REF_2 A cast should not be performed
           * between a pointer to object type and a different pointer to object type
           * @violates @ref fls_c_REF_10 Array indexing shall be the
           * only allowed form of pointer arithmetic
           * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
           * and an integral type
           */
           ((const volatile uint8 *)pFlashAreaPtr) + u32DataLength;
#if(( FLS_DSI_HANDLER_API == STD_ON )&&( FLASH_DATA_FLASH_EXISTS == STD_ON ))
    VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector;

    /* Compiler_Warning: see fls_c_REF_CW_01 */
    /*
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    ePhySector = Fls_GetPhySectorByAddr( (Fls_AddressType) pFlashAreaPtr);
#endif /* (( FLS_DSI_HANDLER_API == STD_ON )&&( FLASH_DATA_FLASH_EXISTS == STD_ON )) */          
    
#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eReadStatus = FLASH_E_PENDING;
#endif
 
#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)
    /* Invalidate the cache, in order to display the erased flash values */
    Mcl_CacheInvalidateAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /* clear read monitoring error flags (w1c) */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */ 
    REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_RVE_W1C | FLASH_MCR_RRE_W1C );
#endif 

    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( Fls_Flash_pReadAddressPtr = ((const volatile uint8 *)pFlashAreaPtr); ((uint32)Fls_Flash_pReadAddressPtr) < \
    /*
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
         /* Compiler_Warning: see fls_c_REF_CW_01 */
         ((uint32)pFlashAreaEndPtr); Fls_Flash_pReadAddressPtr += sizeof(Fls_Flash_DataBusWidthType) \
       )
    {
        Fls_Flash_DataBusWidthType data;
#if( FLS_DSI_HANDLER_API == STD_ON )
    #if( FLASH_DATA_FLASH_EXISTS == STD_ON )
        VAR( boolean, AUTOMATIC ) bWasEccEvent;
    #endif
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
       
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C );

        /* read flash location */
        /* @violates @ref fls_c_REF_2 A cast should not be performed
         * between a pointer to object type and a different pointer to object type
         */                 
        data = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        /* Store the ECC status (EER bit) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_U32))
        {
            bWasEccEvent = (boolean)TRUE;
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    #endif
       
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        if ( (((boolean)FALSE) == Fls_Flash_aSectorList0[ePhySector].bEccTriggersExc) && \
             (((boolean)TRUE) == bWasEccEvent) \
           )
        {
            Fls_Flash_eReadStatus = FLASH_E_FAILED;            
        }
    #endif
        /* Fls_Flash_eReadStatus might have been updated by the exception handler */
        if (FLASH_E_FAILED == Fls_Flash_eReadStatus)
        {
            break;
        }        

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /* read flash location */
        /* @violates @ref fls_c_REF_2 A cast should not be performed
         * between a pointer to object type and a different pointer to object type
         */         
        data = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

#if( FLS_DSI_HANDLER_API == STD_ON )
        if( FLASH_E_PENDING != Fls_Flash_eReadStatus )
        {
            /* @violates @ref fls_c_REF_27 More than one 'break' terminates loop */
            break;         /* ECC handler has been triggered */
        }
#endif        
        if( FLS_ERASED_VALUE != data )
        {
            /* @violates @ref fls_c_REF_27 More than one 'break' terminates loop */
            break;         /* Read data differs from erased value */
        }
    }
    
    if( Fls_Flash_pReadAddressPtr == pFlashAreaEndPtr )
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_Flash_eReadStatus = FLASH_E_OK;
#endif
    }
    else
    {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                         FLS_E_VERIFY_ERASE_FAILED 
                              );
#endif
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_Flash_eReadStatus = FLASH_E_FAILED;
#else
        eRetVal = FLASH_E_FAILED;
#endif
    }

#if( FLS_DSI_HANDLER_API == STD_ON )
    eRetVal = Fls_Flash_eReadStatus;
#endif

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
    */ 
    if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_RVE_U32)) || (0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_RRE_U32)))
    {
        eRetVal = FLASH_E_FAILED;
    }
#endif /* #if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON) */

    return eRetVal;

}
#endif    /* FLS_ERASE_BLANK_CHECK || FLS_WRITE_BLANK_CHECK */

#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
/**
* @brief          Check that the addressed flash memory area is correctly programmed.
* @details        The function compares the contents of the reprogrammed memory area
*                 against the contents of the provided application buffer to check that 
*                 the block has been completely reprogrammed
*
* @param[in]      1           pFlashAreaPtr First address of the addressed flash memory area
*                             aligned to MCU bus width boundary
* @param[in]      2           pUserBufferPtr first address of the application buffer area 
*                             aligned to MCU bus width boundary
* @param[in]      3           DataLength number of bytes to compare aligned to the MCU bus
*                             width
*
* @return         Fls_Flash_ReturnType
* @retval         FLASH_E_OK operation succeeded
* @retval         FLASH_E_FAILED operation failed due to hardware error (ECC)
*                 or contents of the reprogrammed memory area don't match with the 
*                 contents of the provided application buffer
*
* @note           Report the FLS_E_VERIFY_WRITE_FAILED Det error when the verify 
*                 write operation failed due to hardware error (ECC) or contents of 
*                 the reprogrammed memory area didn't match with the contents of 
*                 the provided application buffer
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_VerifyWrite
(
    P2CONST( volatile Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pFlashAreaPtr,
    P2CONST( Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_CONST ) pUserBufferPtr,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength 
)
{
    VAR(Fls_Flash_ReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) pFlashAreaEndPtr = \
           /*
           * @violates @ref fls_c_REF_2 A cast should not be performed
           * between a pointer to object type and a different pointer to object type
           * @violates @ref fls_c_REF_10 Array indexing shall be the
           * only allowed form of pointer arithmetic
           * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
           * and an integral type
           */
           ((const volatile uint8 *)pFlashAreaPtr) + u32DataLength;
#if(( FLS_DSI_HANDLER_API == STD_ON )&&( FLASH_DATA_FLASH_EXISTS == STD_ON ))
    VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector;
    /* 
    * @violates @ref fls_c_REF_25 Cast from pointer to unsigned long 
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    ePhySector = Fls_GetPhySectorByAddr( (Fls_AddressType) pFlashAreaPtr);
#endif /* (( FLS_DSI_HANDLER_API == STD_ON )&&( FLASH_DATA_FLASH_EXISTS == STD_ON )) */           

#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eCompareStatus = FLASH_E_PENDING;
#endif
    
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    */
    Fls_Flash_pCompareAddressPtr = ((const uint8 *)pUserBufferPtr);

#ifdef CACHE_INVALIDATE_MACROS
#if (CACHE_INVALIDATE_MACROS == STD_ON)    
    /* Invalidate cache in order to discard any un-finalized hardware write */
    Mcl_CacheInvalidateAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */
   
#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /* clear read monitoring error flags (w1c) */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */ 
    REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_RVE_W1C | FLASH_MCR_RRE_W1C );
#endif
   
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( Fls_Flash_pReadAddressPtr = ((const volatile uint8 *)pFlashAreaPtr); ((uint32)Fls_Flash_pReadAddressPtr) < \
    /*
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
         /* Compiler_Warning: see fls_c_REF_CW_01 */
         ((uint32)pFlashAreaEndPtr); Fls_Flash_pReadAddressPtr += sizeof(Fls_Flash_DataBusWidthType) \
       )
    {
        Fls_Flash_DataBusWidthType data;
#if( FLS_DSI_HANDLER_API == STD_ON )
    #if( FLASH_DATA_FLASH_EXISTS == STD_ON )
        VAR( boolean, AUTOMATIC ) bWasEccEvent;
    #endif
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
       
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C );
       
        /* read flash location */
        /* @violates @ref fls_c_REF_2 A cast should not be performed
         * between a pointer to object type and a different pointer to object type
         */         
        data = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        /* Store the ECC status (EER bit) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_U32))
        {
            bWasEccEvent = (boolean)TRUE;
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    #endif
       
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        if ( (((boolean)FALSE) == Fls_Flash_aSectorList0[ePhySector].bEccTriggersExc) && \
             (((boolean)TRUE) == bWasEccEvent) \
           )
        {
            Fls_Flash_eCompareStatus = FLASH_E_FAILED;
        }
    #endif
        /* Fls_Flash_eCompareStatus might have been updated by the exception handler */
        if (FLASH_E_FAILED == Fls_Flash_eCompareStatus)
        {
            break;
        }

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /* read flash location */
        /* @violates @ref fls_c_REF_2 A cast should not be performed
         * between a pointer to object type and a different pointer to object type
         */         
        data = *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */

#if( FLS_DSI_HANDLER_API == STD_ON )
        if( FLASH_E_PENDING != Fls_Flash_eCompareStatus )
        {
            /* @violates @ref fls_c_REF_27 More than one 'break' terminates loop */
            break;         /* ECC handler has been triggered */
        }
#endif        
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        if( data != *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pCompareAddressPtr) )
        {
            /* @violates @ref fls_c_REF_27 More than one 'break' terminates loop */
            break;         /* Read data differs from erased value */
        }
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_Flash_pCompareAddressPtr += sizeof(Fls_Flash_DataBusWidthType);        
    }
    
    if( Fls_Flash_pReadAddressPtr == pFlashAreaEndPtr )
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_Flash_eCompareStatus = FLASH_E_OK;
#endif
    }
    else
    {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
       (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, \
                         FLS_E_VERIFY_WRITE_FAILED 
                             );
#endif
#if( FLS_DSI_HANDLER_API == STD_ON )
        Fls_Flash_eCompareStatus = FLASH_E_FAILED;
#else
        eRetVal = FLASH_E_FAILED;
#endif
    }

#if( FLS_DSI_HANDLER_API == STD_ON )
     eRetVal = Fls_Flash_eCompareStatus;
#endif
    
#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
    */ 
    if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_RVE_U32)) || (0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_RRE_U32)))
    {
        eRetVal = FLASH_E_FAILED;
    }
#endif

    return eRetVal;    
}
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */

/**
* @brief          Process ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will complete the following job:
*                 - Erase
*                 - Erase on Interleaved sectors
*                 - Write
*                 - Erase balnk Check
*                 .
*
* @implements     Fls_Flash_MainFunction_Activity
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error.
*                 Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
static FUNC( void, FLS_CODE ) Fls_Flash_MainFunction( void )
{
    if(MEMIF_JOB_PENDING == Fls_Flash_eJobResult )
    {
        /* some hardware job (asynchronous) is pending */
        if (FLASH_JOB_ERASE == Fls_Flash_eJob )
        {
            /* FLASH_JOB_ERASE */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */ 
            if(REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32))
            {
                /* erase/program high voltage sequence already finished */

                /* verify that erase operation was successful */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                if(REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32 ))
                {
                    /* disable high voltage */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */ 
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );    
                    /* terminate erase operation */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32 );
                    
                    /* clear block select registers */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                    
                    REG_WRITE32(FLASH_SEL0_ADDR32,0U);
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                     
                    REG_WRITE32(FLASH_SEL1_ADDR32,0U);
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                     
                    REG_WRITE32(FLASH_SEL2_ADDR32,0U);

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
                        /* schedule erase blank check of flash sector */
                        Fls_Flash_eJob = FLASH_JOB_ERASE_BLANK_CHECK;
#else
                        /* erase operation succeed */
                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_OK;
#endif /* FLS_ERASE_BLANK_CHECK == STD_ON */
                }
                else
                {
                    /* disable high voltage */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */ 
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );
                    /* terminate erase operation */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32 );
                    /* clear block select registers */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                    
                    REG_WRITE32(FLASH_SEL0_ADDR32,0U);
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                     
                    REG_WRITE32(FLASH_SEL1_ADDR32,0U);
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                     
                    REG_WRITE32(FLASH_SEL2_ADDR32,0U);                    
                    /* erase operation failed */

                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
                    #endif

                    Fls_Flash_eJob = FLASH_JOB_NONE;
                    Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                }
            }
            else
            {
#if FLS_TIMEOUT_HANDLING == STD_ON
                /* Operation in progress, handle possible timeout */
                Fls_Flash_u32Timeout_Counter--;
                if( 0U == Fls_Flash_u32Timeout_Counter )
                {
                    /* Abort the HV operation */               
                   (void) Fls_Flash_FinishHVOperation();
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32 );
                    /* clear block select registers */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                    
                    REG_WRITE32(FLASH_SEL0_ADDR32,0U);
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                     
                    REG_WRITE32(FLASH_SEL1_ADDR32,0U);
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */                     
                    REG_WRITE32(FLASH_SEL2_ADDR32,0U);
                    /* erase operation failed */

                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_ERASE_FAILED);
                    #endif

                    Fls_Flash_eJob = FLASH_JOB_NONE;
                    Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                }
#else
                /* erase/program high voltage sequence didn't finished yet */
                /* wait for another call of Fls_Flash_MainFunction, do nothing */
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            }
        }
        /* Write hardware job (asynchronous) is pending */        
        else if (FLASH_JOB_WRITE == Fls_Flash_eJob )
        {
            /* FLASH_JOB_WRITE */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */ 
            if(REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_DONE_U32))
            {
                /* erase/program high voltage sequence already finished */

                /* verify that program operation was successful */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */
                if(REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32 ))
                {
                    /* program operation was successful */
                    
                    /* disable high voltage */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */ 
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )                    
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    if( FLASH_E_OK != Fls_Flash_VerifyWrite \
                                        ( Fls_Flash_pTargetAddressPtr - Fls_Flash_u32NumberOfStepBack, \
                                          Fls_Flash_pSourceAddressPtr - Fls_Flash_u32NumberOfStepBack, \
                                          Fls_Flash_u32NumberOfStepBack*4U \
                                        ) 
                      )
                    {
                        /* terminate program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */ 
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );
                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                        /*
                        * @violates @ref fls_c_REF_5 Return statement before end of function.
                        */
                        return;
                    }
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */                    

                    /* more double word program operation to be performed? */
                    if(Fls_Flash_u32ProgramCycle<Fls_Flash_u32DoubleWordToCopy)
                    {
                        /* continue with next double word program operation */
#if( FLS_WRITE_BLANK_CHECK == STD_ON )                       
                        if( FLASH_E_OK != Fls_Flash_VerifyErase
                                           ( Fls_Flash_pTargetAddressPtr,
                                            /*
                                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                                            * only allowed form of pointer arithmetic
                                            */
                                            FLS_PAGE_SIZE
                                           ) 
                          )
                        {
                            /* terminate program operation */
                            /*
                            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                            */ 
                            REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );
                            Fls_Flash_eJob = FLASH_JOB_NONE;
                            Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                            /*
                            * @violates @ref fls_c_REF_5 Return statement before end of function.
                            */
                            return;                
                        }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
                        /* if not page aligned execute dw programming */
                        /*
                        * @violates @ref fls_c_REF_41 Conversions shall not be
                        * performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
                        * and an integral type
                        */
                        /* Compiler_Warning: see fls_c_REF_CW_01 */
                        if( (0U !=((uint32)Fls_Flash_pTargetAddressPtr % (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] ))|| \
                             (Fls_Flash_u32RemainingData < (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] ) \
                          )
                        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                           /* @violates @ref fls_c_REF_10 Array indexing shall be the only allowed 
                              form of pointer arithmetic */
                            if( FLASH_E_OK != Fls_Flash_VerifyErase \
                                                ( Fls_Flash_pTargetAddressPtr, \
                                                  FLS_PAGE_SIZE \
                                                ) 
                              )
                            {
                                /* terminate program operation */
                                /*
                                * @violates @ref fls_c_REF_32 Conversions shall not be performed 
                                * between a pointer to a function and any type other than an integral type
                                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                */ 
                                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );
                                Fls_Flash_eJob = FLASH_JOB_NONE;
                                Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                                /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                                return;                
                            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */                
                            /*It is time to do word or double word programming */
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_Flash_PageWrite(FLS_PAGE_SIZE);
                            Fls_Flash_u32ProgramCycle++;
                            /*
                            * @violates @ref fls_c_REF_10 Array indexing shall be the
                            * only allowed form of pointer arithmetic
                            */
                            Fls_Flash_u32RemainingData -= FLS_PAGE_SIZE;
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                            /* target and source address has been incresed by Fls_Flash_PageWrite,
                               so we need a number of step back for both pointer to perform a write 
                               verify check*/
                            /* @violates @ref fls_c_REF_10 Array indexing shall be the only 
                               allowed form of pointer arithmetic */
                            Fls_Flash_u32NumberOfStepBack = FLS_PAGE_SIZE/4U;
#endif
                        }
                        else
                        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                            if( FLASH_E_OK != Fls_Flash_VerifyErase \
                                                ( Fls_Flash_pTargetAddressPtr, \
                                                  (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] \
                                                ) 
                              )
                            {
                                /* terminate program operation */
                                /*
                                * @violates @ref fls_c_REF_32 Conversions shall not be performed 
                                * between a pointer to a function and any type other than an integral type
                                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                                */ 
                                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );
                                Fls_Flash_eJob = FLASH_JOB_NONE;
                                Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                                /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                                return;                
                            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */                
                            /* it is time to do page programming */
                            Fls_Flash_PageWrite((*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt]);
                            Fls_Flash_u32ProgramCycle+=Fls_Flash_u32DoubleWordCounter;
                            Fls_Flash_u32RemainingData -= (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                            /* target and source address has been incresed by Fls_Flash_PageWrite,
                               so we need a number of step back for both pointer to perform a write 
                               verify check*/
                            Fls_Flash_u32NumberOfStepBack = (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt]/4U;
#endif
                        }

                        /* start internal erase/program sequence */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed 
                        * between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */ 
                        REG_BIT_SET32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );

                        Fls_Flash_eJob = FLASH_JOB_WRITE;
                        Fls_Flash_eJobResult = MEMIF_JOB_PENDING;
                    }
                    else
                    {
                        /* all double word program operations succeed */
                        /* terminate program operation */    
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed 
                        * between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */ 
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );                        
                        
                        /* For a Write Job in ASYNC mode check if Fls_u32JobSectorIt should be increased */
                        if( (Fls_u32JobAddrIt > ((*(Fls_pConfigPtr->pSectorEndAddr))[Fls_u32JobSectorIt]) ))
                        {
                            /* Move on to the next sector */
                            Fls_u32JobSectorIt++;
                        }            
                        
                        /* program operation succeed */
                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_OK;
                    }
                }
                else
                {
                    /* program operation was not successful */
                    
                    /* disable high voltage */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed 
                    * between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */ 
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_EHV_U32 );
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed 
                    * between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */ 
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32 );      
                    /* program operation failed */
                    
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                    #endif

                    Fls_Flash_eJob = FLASH_JOB_NONE;
                    Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                }
            }
            else
            {
#if FLS_TIMEOUT_HANDLING == STD_ON
                /* Operation in progress, handle possible timeout */
                Fls_Flash_u32Timeout_Counter--;
                if( 0U == Fls_Flash_u32Timeout_Counter )
                {
                    /* Abort the HV operation */                  
                    (void) Fls_Flash_FinishHVOperation();
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed 
                    * between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                    */ 
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_PGM_U32);      
                    /* write operation failed */

                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_WRITE_FAILED);
                    #endif

                    Fls_Flash_eJob = FLASH_JOB_NONE;
                    Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                }
#else
                /* erase/program high voltage sequence didn't finished yet */
                /* wait for another call of Fls_Flash_MainFunction, do nothing */
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
            }
        }
        else if ( FLASH_JOB_ERASE_BLANK_CHECK == Fls_Flash_eJob )
        {
                /* FLASH_JOB_ERASE_BLANK_CHECK */
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
            /*
            * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
            * that address elements of the same array
            * @violates @ref fls_c_REF_40 >, >=, <, <=shall not be applied to pointer types except
            * where they point to the same array
            */
            while (Fls_Flash_pTargetAddressPtr < Fls_Flash_pEndAddressPtr)
            {
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
                * that address elements of the same array
                * @violates @ref fls_c_REF_40 >, >=, <, <=shall not be applied to pointer types except
                * where they point to the same array
                */
                if (((Fls_Flash_pEndAddressPtr - Fls_Flash_pTargetAddressPtr)*4) >= 
                      FLS_MAX_ERASE_BLANK_CHECK
                   )
                {
                    /* at least one erase blank check with FLS_MAX_ERASE_BLANK_CHECK size */
                    if( FLASH_E_OK != Fls_Flash_VerifyErase
                                        ( Fls_Flash_pTargetAddressPtr,
                                          FLS_MAX_ERASE_BLANK_CHECK
                                        ) 
                      )
                    {
                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                        /*
                        * @violates @ref fls_c_REF_5 Return statement before end of function.
                        */
                        return;
                    }
                    /*                           
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_Flash_pTargetAddressPtr += FLS_MAX_ERASE_BLANK_CHECK/(Fls_Flash_DataBusWidthType)4;
                    /*
                    * @violates @ref fls_c_REF_5 Return statement before end of function.
                    */
                    return;
                }
                else
                {
                    /* at least one erase blank check with 4 bytes size */
                    if( FLASH_E_OK != Fls_Flash_VerifyErase \
                                        ( Fls_Flash_pTargetAddressPtr, \
                                        /*
                                        * @violates @ref fls_c_REF_10 Array indexing shall be the
                                        * only allowed form of pointer arithmetic
                                        * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
                                        * that address elements of the same array
                                        * @violates @ref fls_c_REF_23 Cast of complex expression changes signedness
                                        * @violates @ref fls_c_REF_40 >, >=, <, <=shall not be applied to pointer types except
                                        * where they point to the same array
                                        */
                                          (Fls_LengthType)((Fls_Flash_pEndAddressPtr - Fls_Flash_pTargetAddressPtr)*4U) \
                                        ) 
                      )
                    {
                        Fls_Flash_eJob = FLASH_JOB_NONE;
                        Fls_Flash_eJobResult = MEMIF_JOB_FAILED;
                        /*
                        * @violates @ref fls_c_REF_5 Return statement before end of function.
                        */
                        return;
                    }
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    * @violates @ref fls_c_REF_14 Pointer subtraction shall only be applied to pointers
                    * that address elements of the same array
                    * @violates @ref fls_c_REF_40 >, >=, <, <=shall not be applied to pointer types except
                    * where they point to the same array
                    */
                    Fls_Flash_pTargetAddressPtr += Fls_Flash_pEndAddressPtr - Fls_Flash_pTargetAddressPtr;
                    /*
                    * @violates @ref fls_c_REF_5 Return statement before end of function.
                    */
                    return;
                }
            }
            /* erase blank check succeeded */
            Fls_Flash_eJob = FLASH_JOB_NONE;
            Fls_Flash_eJobResult = MEMIF_JOB_OK;
#else
            Fls_Flash_eJob = FLASH_JOB_NONE;
            Fls_Flash_eJobResult = MEMIF_JOB_OK;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */                
        }
        /* Write interleaved hardware job (asynchronous) is pending */
        else if (FLASH_JOB_NONE == Fls_Flash_eJob)
        {
            /* Do nothing */
        }
        else
        {
            /* Do nothing - should not happen in Fully Trusted Environment;
               'else' clause added to fulfill MISRA Rule 14.10 */
        }

    }
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */
    }
}

#if (FLS_CANCEL_API == STD_ON )
/**
* @brief          Cancel ongoing erase or write hardware job.
* @details        In case Async Operation is ongoing this function will abort the following jobs:
*                 - Erase
*                 - Erase on Interleaved sectors
*                 - Write
*                 .
*/
static FUNC( void, FLS_CODE ) Fls_Flash_Cancel( void )
{
    if(MEMIF_JOB_PENDING == Fls_Flash_eJobResult )
    {
        /* some hardware job (asynchronous) is pending */
        if (FLASH_JOB_ERASE == Fls_Flash_eJob )
        {
            /* FLASH_JOB_ERASE */
            /* hence make erase-abort operation */
            
            /* abort erase/program operation */
            if( Fls_Flash_FinishHVOperation() )
            {
                /* terminate erase operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */ 
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32);
                /* clear block select registers */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_ERS_U32 );
                /* clear block select registers */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */                    
                REG_WRITE32(FLASH_SEL0_ADDR32,0U);
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */                     
                REG_WRITE32(FLASH_SEL1_ADDR32,0U);
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */                     
                REG_WRITE32(FLASH_SEL2_ADDR32,0U);

                /* erase operation canceled */
                Fls_Flash_eJob = FLASH_JOB_NONE;
                Fls_Flash_eJobResult = MEMIF_JOB_CANCELED;
            }
        }
        else
        {
            /* FLASH_JOB_WRITE */
            /* hence make program-abort operation */
                
            /* abort erase/program operation */
            if( Fls_Flash_FinishHVOperation() )
            {
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                */   
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);

                /* program operation canceled */
                Fls_Flash_eJob = FLASH_JOB_NONE;
                Fls_Flash_eJobResult = MEMIF_JOB_CANCELED;
            }
        }
    }
    else
    {
        /* no hardware job (asynchronous) is pending, do nothing */
        Fls_Flash_eJob = FLASH_JOB_NONE;
        Fls_Flash_eJobResult = MEMIF_JOB_CANCELED;
    }
}
#endif /* FLS_CANCEL_API == STD_ON */

/**
* @brief          Erase one complete flash sector.
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           bAsynch Set to TRUE for asynchronous and FALSE for synchronous 
*                             function operation
*
* @return         Fls_Flash_ReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_FAILED Operation failed due to hardware error
* @retval         FLASH_E_PENDING The operation has not yet been finished 
*                 (only for asynchronous operation )
*
* @pre            ePhySector must be in range
* @pre            The module must be initialized
*
* @implements     Fls_Flash_SectorErase_Activity
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_EraseFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when erase operation failed due to hardware error
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_SectorErase
(
    CONST( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector,
#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    CONST(Fls_LengthType, AUTOMATIC) u32PhysicalSectorSize,
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
    CONST( boolean, AUTOMATIC) bAsynch
)
{
    VAR(uint32, AUTOMATIC) u32BloSelRegAddr = Fls_Flash_aSectorList0[ePhySector].u32SectorBloSelRegAddr;
    VAR(uint32, AUTOMATIC) u32BloSelValue = Fls_Flash_aSectorList0[ePhySector].u32AddrSpaceBloSelValue;
    VAR(uint32, AUTOMATIC) u32BloLockRegAddr = Fls_Flash_aSectorList0[ePhySector].u32AddrSpaceBloLockRegAddr; 
    VAR(uint32, AUTOMATIC) u32BloLockValue = Fls_Flash_aSectorList0[ePhySector].u32AddrSpaceBloLockValue;
#if FLS_TIMEOUT_HANDLING == STD_ON
    VAR(uint32, AUTOMATIC) u32Abort_Timeout_Counter;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

    Fls_Flash_pTargetAddressPtr = Fls_Flash_aSectorList0[ePhySector].pSectorStartAddressPtr;

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
    Fls_Flash_pEndAddressPtr = \
    /*   
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    (Fls_Flash_aSectorList0[ePhySector].pSectorStartAddressPtr + (u32PhysicalSectorSize/(Fls_Flash_DataBusWidthType)4));
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

    /* verify that EHV may be set */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */ 
    if((0UL != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32|FLASH_MCR_PGM_U32|FLASH_MCR_ESUS_U32)) || \
    /*  
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
        (0UL != REG_BIT_GET32(FLASH_UT0_ADDR32, FLASH_UT0_AIE_U32))
    /* @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement */
      )
    {
        /*  EHV may not be set: modify operation already in progress */
        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_ERASE_FAILED);
        #endif

        /*
        * @violates @ref fls_c_REF_5 Return statement before end of function.
        */      
        return FLASH_E_FAILED;
    }
    /* verify that sector is not protected against erase/program operations */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */ 
    if(REG_READ32(u32BloLockRegAddr) & u32BloLockValue )
    {
        /* sector protected: erase operation failed */
        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_ERASE_FAILED);
        #endif
        
        /*
        * @violates @ref fls_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_FAILED;
    }
    if ((boolean)FALSE == bAsynch)
    {
        /* setup erase operation */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32);
        /* load adequate block select register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        REG_WRITE32(u32BloSelRegAddr, u32BloSelValue );
        /* make an erase interlock write, dummy data word write */
        *Fls_Flash_pTargetAddressPtr = 0xFFFFFFFFU;
 
#ifdef CACHE_INVALIDATE_MACROS 
#if (CACHE_INVALIDATE_MACROS == STD_ON)        
        /* Flush the interlock write from cache to flash */
        Mcl_CacheFlushAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */

#if FLS_TIMEOUT_HANDLING == STD_ON
        /* Initialize timeout counters */
        Fls_Flash_u32Timeout_Counter = FLS_SYNC_ERASE_TIMEOUT_VALUE;
        u32Abort_Timeout_Counter = FLS_ABT_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        MCAL_FAULT_INJECTION_POINT(FLS_FIP_11_FLS_FLASH_SECTOR_ERASE);
        
        /* call flash access code routine */
#if FLS_TIMEOUT_HANDLING == STD_ON
        /*
        * @violates @ref fls_c_REF_16 Taking address of near auto variable.
        * @violates @ref fls_c_REF_29 Cast from pointer to unsigned long       
        */        
        FLASH_AC_CALL(Fls_pConfigPtr->acErasePtr, Fls_Flash_AcErasePtrType)(FLASH_BASEADDR, Fls_pConfigPtr->acCallBackPtr, &Fls_Flash_u32Timeout_Counter, &u32Abort_Timeout_Counter);
#else
        /* @violates @ref fls_c_REF_29 Cast from pointer to unsigned long */
        FLASH_AC_CALL(Fls_pConfigPtr->acErasePtr, Fls_Flash_AcErasePtrType)(FLASH_BASEADDR, Fls_pConfigPtr->acCallBackPtr);
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        MCAL_FAULT_INJECTION_POINT(FLS_FIP_12_FLS_FLASH_SECTOR_ERASE);
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }
    
        /* verify that erase operation was successful */
#if FLS_TIMEOUT_HANDLING == STD_ON
        /*  PEG is valid only after DONE transition to 1 which might not be the case if the timeout event occured */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32)) && (0U != Fls_Flash_u32Timeout_Counter) && (0U != u32Abort_Timeout_Counter))
#else
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        if(REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32))
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */        
        {
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32);
            /* clear adequate block select register */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */
            REG_WRITE32(u32BloSelRegAddr, 0U);
        }
        else
        {
            /* terminate erase operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32);
            /* clear adequate block select register */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */
            REG_WRITE32(u32BloSelRegAddr, 0U);
            /* erase operation failed */
            #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
            (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_ERASE_FAILED);
            #endif

            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_FAILED;
        }    

#if( FLS_ERASE_BLANK_CHECK == STD_ON )
            if( FLASH_E_OK != Fls_Flash_VerifyErase(Fls_Flash_pTargetAddressPtr, u32PhysicalSectorSize) )
            {
                /*
                * @violates @ref fls_c_REF_5 Return statement before end of function.
                */
                return FLASH_E_FAILED;
            }
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
            /* erase operation succeed */
            /*
            * @violates @ref fls_c_REF_6 Return statement before end of function.
            */         
            return FLASH_E_OK;
    }
    else /* bAsynch == TRUE */
    {
        /* setup erase operation */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32);
        /* load adequate block select register */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        REG_WRITE32(u32BloSelRegAddr, u32BloSelValue );
        /* make an erase interlock write, dummy data word write */
        *Fls_Flash_pTargetAddressPtr = 0xFFFFFFFFU;
        
#ifdef CACHE_INVALIDATE_MACROS        
#if (CACHE_INVALIDATE_MACROS == STD_ON)        
        /* Flush the interlock write from cache to flash */
        Mcl_CacheFlushAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */

        /* start internal erase/program sequence */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_EHV_U32);
        
        Fls_Flash_eJob = FLASH_JOB_ERASE;
        Fls_Flash_eJobResult = MEMIF_JOB_PENDING;
        
#if FLS_TIMEOUT_HANDLING == STD_ON
        /* Initialize timeout counter */
        Fls_Flash_u32Timeout_Counter = FLS_ASYNC_ERASE_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */        
        
        /*
        * @violates @ref fls_c_REF_6 Return statement before end of function.
        */
        return FLASH_E_PENDING;                
    }
}

/**
* @brief          Write one or more complete flash pages into given flash sector.
*
* @param[in]      ePhySector Physical sector ID
* @param[in]      u32SectorOffset sector offset in bytes
* @param[in]      u32DataLength data length in bytes
* @param[in]      pDataPtr data to be written
* @param[in]      bAsynch set to TRUE for asynchronous and FALSE for synchronous function operation
*
* @return         Fls_Flash_ReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_FAILED Operation failed due to hardware error
* @retval         FLASH_E_PENDING The operation has not yet been finished 
*                 (only for asynchronous operation )
*
* @pre            u32SectorOffset must be double word aligned
* @pre            u32DataLength must be multiple double word length
* @pre            ePhySector must be in range
* @pre            The module must be initialized
*
* @implements     Fls_Flash_SectorWrite_Activity
*
* @note           Dem_ReportErrorStatus(Fls_pConfigPtr->Fls_E_WriteFailedCfg.id, DEM_EVENT_STATUS_FAILED)
*                 when write operation failed due to hardware error
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_SectorWrite
(
    CONST( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr,
    CONST( boolean, AUTOMATIC) bAsynch
)
{ 
    VAR(uint32, AUTOMATIC) u32BloLockRegAddr = Fls_Flash_aSectorList0[ePhySector].u32AddrSpaceBloLockRegAddr;  
    VAR(uint32, AUTOMATIC) u32BloLockValue = Fls_Flash_aSectorList0[ePhySector].u32AddrSpaceBloLockValue;
#if FLS_TIMEOUT_HANDLING == STD_ON
    VAR(uint32, AUTOMATIC) u32Abort_Timeout_Counter;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    */
    Fls_Flash_pSourceAddressPtr = (const uint32*)(pDataPtr);
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_Flash_pTargetAddressPtr = Fls_Flash_aSectorList0[ePhySector].pSectorStartAddressPtr + \
                               (u32SectorOffset/4U);
    
    Fls_Flash_u32RemainingData = u32DataLength;

    /* verify that EHV may be set */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */ 
    if((0UL != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_ERS_U32|FLASH_MCR_PGM_U32|FLASH_MCR_ESUS_U32)) || \
    /*  
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
        (0UL != REG_BIT_GET32(FLASH_UT0_ADDR32, FLASH_UT0_AIE_U32))
    /* @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.This violation is because of complex statement */
      )
    {
        /*  EHV may not be set: modify operation already in progress */
        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_WRITE_FAILED);
        #endif

        /*
        * @violates @ref fls_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_FAILED;
    }

    
    /* verify that sector is not protected against erase/program operations */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */ 
    if (  REG_READ32(u32BloLockRegAddr) & u32BloLockValue)
    {
        /* sector protected: program operation failed */
        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_WRITE_FAILED);
        #endif

        /*
        * @violates @ref fls_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_FAILED;
    }
    /* Number of word (i.e.32bits=4bytes) double word (i.e.64bits=8bytes) to be copied  */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_Flash_u32DoubleWordToCopy = u32DataLength/FLS_PAGE_SIZE;
    /* Number of word or dw to be copied in one propram operation */
    Fls_Flash_u32DoubleWordCounter = (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] / FLS_PAGE_SIZE;
    Fls_Flash_u32ProgramCycle = 0U;

    /* before going into programming loop (and potential performing Verify Erase operation) and setting MCR[PGM],
       invalidate the flash prefetch buffer by performing a bogus interlock write while MCR[PGM,ERS] == 0 */
    *Fls_Flash_pTargetAddressPtr = 0x0UL;

#ifdef CACHE_INVALIDATE_MACROS    
#if (CACHE_INVALIDATE_MACROS == STD_ON)    
    /* Flush the interlock write from cache to flash */
    Mcl_CacheFlushAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */
#endif /* ifdef CACHE_INVALIDATE_MACROS */

    if ((boolean)FALSE == bAsynch)
    {
            /* setup program operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
            */ 
            REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
            
            /* process all double word program operations */
            /*for( Fls_Flash_u32ProgramCycle=0U; Fls_Flash_u32ProgramCycle < Fls_Flash_u32DoubleWordToCopy; \
                 Fls_Flash_u32ProgramCycle++ )*/
            while (Fls_Flash_u32ProgramCycle < Fls_Flash_u32DoubleWordToCopy)
            {
                
                /* if not page aligned execute dw programming */
                /*
                * @violates @ref fls_c_REF_41 Conversions shall not be
                * performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
                * and an integral type
                */
                /* Compiler_Warning: see fls_c_REF_CW_01 */
                if( (0U != ((uint32)Fls_Flash_pTargetAddressPtr % (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] )) || \
                    (Fls_Flash_u32RemainingData < (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] ) \
                  )
                {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                    /* @violates @ref fls_c_REF_10 Array indexing shall be the only 
                       allowed form of pointer arithmetic */
                    if( FLASH_E_OK != Fls_Flash_VerifyErase \
                                        ( Fls_Flash_pTargetAddressPtr, \
                                          FLS_PAGE_SIZE \
                                        ) 
                      )
                    {
                        /* terminate program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */ 
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
                        /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                        return FLASH_E_FAILED;                
                    }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */                
                    /*It is time to do word or double word programming */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_Flash_PageWrite(FLS_PAGE_SIZE);
                    Fls_Flash_u32ProgramCycle++;
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_Flash_u32RemainingData -= FLS_PAGE_SIZE;
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                    /* target and source address has been incresed by Fls_Flash_PageWrite,
                       so we need a number of step back for both pointer to perform a write 
                       verify check*/
                    /* @violates @ref fls_c_REF_10 Array indexing shall be the only 
                       allowed form of pointer arithmetic */
                    Fls_Flash_u32NumberOfStepBack = FLS_PAGE_SIZE/4U;
#endif
                }
                else
                {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
                    if( FLASH_E_OK != Fls_Flash_VerifyErase \
                                        ( Fls_Flash_pTargetAddressPtr, \
                                          (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] \
                                        ) 
                      )
                    {
                        /* terminate program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
                        */ 
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);                         
                        /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                        return FLASH_E_FAILED;                
                    }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */                
                    /* it is time to do page programming */
                    Fls_Flash_PageWrite((*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt]);
                    Fls_Flash_u32ProgramCycle+=Fls_Flash_u32DoubleWordCounter;
                    Fls_Flash_u32RemainingData -= (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                    /* target and source address has been incresed by Fls_Flash_PageWrite,
                       so we need a number of step back for both pointer to perform a write 
                       verify check*/
                    Fls_Flash_u32NumberOfStepBack = (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt]/4U;
#endif
                }
                
#if FLS_TIMEOUT_HANDLING == STD_ON
                /* Initialize timeout counters */
                Fls_Flash_u32Timeout_Counter = FLS_SYNC_WRITE_TIMEOUT_VALUE;
                u32Abort_Timeout_Counter = FLS_ABT_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

                /* start flash access section: implementation depends on integrator */
                if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
                {
                    /* Call FlsStartFlashAccessNotif function if configured */
                    Fls_pConfigPtr->startFlashAccessNotifPtr();
                }
                
                MCAL_FAULT_INJECTION_POINT(FLS_FIP_13_FLS_FLASH_SECTOR_WRITE);
                
                /* call flash access code routine */
#if FLS_TIMEOUT_HANDLING == STD_ON
                /*
                * @violates @ref fls_c_REF_16 Taking address of near auto variable.
                * @violates @ref fls_c_REF_29 Cast from pointer to unsigned long                
                */        
                FLASH_AC_CALL(Fls_pConfigPtr->acWritePtr, Fls_Flash_AcWritePtrType)(FLASH_BASEADDR, Fls_pConfigPtr->acCallBackPtr, &Fls_Flash_u32Timeout_Counter, &u32Abort_Timeout_Counter);
#else
                /* @violates @ref fls_c_REF_29 Cast from pointer to unsigned long */
                FLASH_AC_CALL(Fls_pConfigPtr->acWritePtr, Fls_Flash_AcWritePtrType)(FLASH_BASEADDR, Fls_pConfigPtr->acCallBackPtr);
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */               

                MCAL_FAULT_INJECTION_POINT(FLS_FIP_14_FLS_FLASH_SECTOR_ERASE);
                
                /* end flash access section: implementation depends on integrator */
                if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
                {
                    /* Call Fls_FinishedFlashAccessNotif function if configured */
                    Fls_pConfigPtr->finishedFlashAccessNotifPtr();
                }
        
                /* verify that program operation was successful */
                /*
                * @violates @ref fls_c_REF_10 Array indexing shall be the
                * only allowed form of pointer arithmetic
                */
#if FLS_TIMEOUT_HANDLING == STD_ON
                /*  PEG is valid only after DONE transition to 1 which might not be the case if the timeout event occured */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type          
                */
                if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32)) && (0U != Fls_Flash_u32Timeout_Counter) && (0U != u32Abort_Timeout_Counter))               
#else
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
                */
                if(REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PEG_U32))
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */                
                {
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
                    if( FLASH_E_OK != Fls_Flash_VerifyWrite
                                         ( /* @violates @ref fls_c_REF_10 Array indexing shall be the only 
                                               allowed form of pointer arithmetic */
                                            Fls_Flash_pTargetAddressPtr - Fls_Flash_u32NumberOfStepBack,
                                            /* @violates @ref fls_c_REF_10 Array indexing shall be the only 
                                               allowed form of pointer arithmetic */
                                            Fls_Flash_pSourceAddressPtr - Fls_Flash_u32NumberOfStepBack,
                                            Fls_Flash_u32NumberOfStepBack * 4U 
                                         ) 
                      )
                    {
                        /* terminate program operation */
                        /*
                        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
                        */                        
                        REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);

                        /*
                        * @violates @ref fls_c_REF_5 Return statement before end of function.
                        */
                        return FLASH_E_FAILED;
                    }
#endif    /* FLS_WRITE_VERIFY_CHECK == STD_ON */                    

                    /* program operation succeed */
                    /* continue with next double word program operation */
                }
                else
                {
                    /* terminate program operation */
                    /*
                    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
                    */     
                    REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
                    /* program operation failed */
                    #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
                    (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_WRITE_FAILED);
                    #endif

                    /*
                    * @violates @ref fls_c_REF_5 Return statement before end of function.
                    */
                    return FLASH_E_FAILED;
                }
            }
            
            /* all double word program operations succeed */
            /* terminate program operation */    
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
            */     
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
            /* program operation succeed */
            /*
            * @violates @ref fls_c_REF_6 Return statement before end of function.
            */
            return FLASH_E_OK;

    }
    else /* bAsynch == TRUE */
    {
        /* setup program operation */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
        */     
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
        
        /* first double word program operation */
        Fls_Flash_u32ProgramCycle=0U;
        
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
        if( FLASH_E_OK != 
            Fls_Flash_VerifyErase(Fls_Flash_pTargetAddressPtr,
                                  /*
                                  * @violates @ref fls_c_REF_10 Array indexing shall be the
                                  * only allowed form of pointer arithmetic
                                  */
                                  FLS_PAGE_SIZE
                                 ) 
          )
        {
            /* terminate program operation */
            /*
            * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
            */     
            REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_FAILED;                
        }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
        Fls_Flash_u32NumberOfStepBack = 0U;
#endif
        /* if not page aligned execute dw programming */
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        if( (0U != ((uint32)Fls_Flash_pTargetAddressPtr % (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] )) || \
                    (Fls_Flash_u32RemainingData < (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] ) \
          )
        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
            /* @violates @ref fls_c_REF_10 Array indexing shall be the only 
               allowed form of pointer arithmetic */
            if( FLASH_E_OK != Fls_Flash_VerifyErase \
                               ( Fls_Flash_pTargetAddressPtr, \
                                 FLS_PAGE_SIZE \
                               ) 
              )
            {
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
                */     
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
                /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
            /*It is time to do word or double word programming */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_PageWrite(FLS_PAGE_SIZE);
            Fls_Flash_u32ProgramCycle++;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_u32RemainingData -= FLS_PAGE_SIZE;
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /* target and source address has been incresed by Fls_Flash_PageWrite,
               so we need a number of step back for both pointer to perform a write 
               verify check*/
            /* @violates @ref fls_c_REF_10 Array indexing shall be the only 
               allowed form of pointer arithmetic */
            Fls_Flash_u32NumberOfStepBack = FLS_PAGE_SIZE/4U;
#endif
        }
        else
        {
#if( FLS_WRITE_BLANK_CHECK == STD_ON )
            if( FLASH_E_OK != Fls_Flash_VerifyErase \
                                ( Fls_Flash_pTargetAddressPtr, \
                                  (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt] \
                                ) 
              )
            {
                /* terminate program operation */
                /*
                * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
                * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
                */     
                REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32);
                /* @violates @ref fls_c_REF_5 Return statement before end of function. */
                return FLASH_E_FAILED;
            }
#endif    /* FLS_WRITE_BLANK_CHECK == STD_ON */
            /* it is time to do page programming */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_PageWrite((*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt]);
            Fls_Flash_u32ProgramCycle+=Fls_Flash_u32DoubleWordCounter;
            Fls_Flash_u32RemainingData -= (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt];
#if( FLS_WRITE_VERIFY_CHECK == STD_ON )
            /* target and source address has been incresed by Fls_Flash_PageWrite,
               so we need a number of step back for both pointer to perform a write 
               verify check*/
            Fls_Flash_u32NumberOfStepBack = (*(Fls_pConfigPtr->pSectorProgSize))[Fls_u32JobSectorIt]/4U;
#endif
        }
        /* start internal erase/program sequence */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type  
        */     
        REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_EHV_U32);
        Fls_Flash_eJob = FLASH_JOB_WRITE;
        Fls_Flash_eJobResult = MEMIF_JOB_PENDING;

#if FLS_TIMEOUT_HANDLING == STD_ON
        /* Initialize timeout counter */
        Fls_Flash_u32Timeout_Counter = FLS_ASYNC_WRITE_TIMEOUT_VALUE;
#endif /* FLS_TIMEOUT_HANDLING == STD_ON */

        /*
        * @violates @ref fls_c_REF_6 Return statement before end of function.
        */
        return FLASH_E_PENDING;
    }
}

/**
* @brief          Execute an interlock write and next program.
*
* @param[in]      1           u32TotalBytes Total number of bytes to program
*
*/
static FUNC( void, FLS_CODE ) Fls_Flash_PageWrite
( CONST(uint32, AUTOMATIC) u32TotalBytes )
{
    uint32 u32Counter;
    
    for (u32Counter=0UL; u32Counter < (u32TotalBytes/4U); u32Counter++)
    {
        /* make a program data interlock write, first word data write */
        *Fls_Flash_pTargetAddressPtr = *Fls_Flash_pSourceAddressPtr;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_Flash_pTargetAddressPtr += 1;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        Fls_Flash_pSourceAddressPtr += 1;
    }
    
#ifdef CACHE_INVALIDATE_MACROS    
#if (CACHE_INVALIDATE_MACROS == STD_ON)    
    /* Flush written data from cache to flush, before starting the actual HV programming */
    Mcl_CacheFlushAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */   
#endif /* ifdef CACHE_INVALIDATE_MACROS */ 
}

/**
* @brief          Calculate u32Length of initial 8-bit flash read.
* @details        Calculate number of bytes to read from flash until
*                 the source pointer is aligned to the data  width and
*                 optimized wide (32-bit or 64-bit) flash reads can begin
*
* @param[in]      1           pSourceAddrPtr Source pointer
* @param[in]      2           u32TotalBytes Total number of bytes to read
*
* @return         u32Length of initial 8-bit flash reads in bytes
*/
static FUNC( uint32, FLS_CODE ) Fls_Flash_CalcInitDataLength
( 
    CONSTP2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) volatile pSourceAddrPtr,
    CONST(uint32, AUTOMATIC) u32TotalBytes 
)
{
    /* Calc u32Length of initial 8-bit transfer */
    VAR(uint32, AUTOMATIC) u32Length = 
        /*
        * @violates @ref fls_c_REF_41 Conversions shall not be
        * performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        ( (uint32)pSourceAddrPtr ) & ( sizeof(Fls_Flash_DataBusWidthType) - 1UL );
    
    if ( u32Length != 0U )
    {
        u32Length = sizeof(Fls_Flash_DataBusWidthType) - u32Length;
    }
    else
    {
        /* u32Length == 0 */
    }

    if( u32Length > u32TotalBytes ) 
    {
        u32Length = u32TotalBytes;
    }
    else
    {
        /* u32Length <=  u32TotalBytes */
    }
    
    return u32Length;
}

/**
* @brief          Calculate u32Length of optimized wide flash reads.
* @details        Calculate number of bytes to read from flash until
*                 the source pointer is not aligned to the data bus width
*
* @param[in]      1           u32InitDataLength Calculated by Fls_Flash_CalcInitDataLength
* @param[in]      2           u32TotalBytes Total number of bytes to read
*
* @return         u32Length of optimized 32-bit or 64-bit flash reads in bytes
*/
static FUNC( uint32, FLS_CODE ) Fls_Flash_CalcWideDataLength
(
    CONST(uint32, AUTOMATIC) u32InitDataLength,
    CONST(uint32, AUTOMATIC) u32TotalBytes 
)
{
    VAR(uint32, AUTOMATIC) u32Length =
        (( u32TotalBytes - u32InitDataLength ) & (~( sizeof(Fls_Flash_DataBusWidthType) - 1UL )));

    return u32Length;
}

/**
* @brief          Read one or more bytes from given flash sector
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           u32SectorOffset sector offset in bytes
* @param[in]      3           u32DataLength data length in bytes
* @param[out]     pDataPtr     where read data to be written
*
* @return Fls_Flash_ReturnType
* @retval FLASH_E_OK Operation succeeded
*
* @implements     Fls_Flash_SectorRead_Activity
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_SectorRead
(
    CONST( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    P2VAR(uint8, AUTOMATIC, FLS_APPL_DATA) pDataPtr
)
{
    VAR(uint32, AUTOMATIC) u32InitDataLength = 0UL;
    VAR(Fls_Flash_ReturnType, AUTOMATIC) eRetVal = FLASH_E_OK;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) pReadAddressEndPtr = NULL_PTR;
    P2CONST(volatile uint8, AUTOMATIC, FLS_APPL_CONST) pReadBlockAddressEndPtr = NULL_PTR;
    PACKED P2VAR(Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_DATA) pDataPtrUnaligned = NULL_PTR;
#if ( ( FLS_DSI_HANDLER_API == STD_ON ) && ( FLASH_DATA_FLASH_EXISTS == STD_ON ) )
    VAR( boolean, AUTOMATIC ) bWasEccEvent;
#endif
   
    /* Physical flash address to read */
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_Flash_pReadAddressPtr = (volatile const uint8 *)(Fls_Flash_aSectorList0[ePhySector].pSectorStartAddressPtr) + \
                              u32SectorOffset;
    
    /* End of read pointer */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadAddressEndPtr = Fls_Flash_pReadAddressPtr + u32DataLength;
    
    /* Calculate end address of initial 8-bit transfer */
    u32InitDataLength = Fls_Flash_CalcInitDataLength( Fls_Flash_pReadAddressPtr, u32DataLength );
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadBlockAddressEndPtr = Fls_Flash_pReadAddressPtr + u32InitDataLength;
    
    /* first invalidate the flash prefetch buffer by performing a bogus interlock write 
       (avoid write if MCR[PGM|ERS] == 0)*/
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */     
    if(0UL == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32 | FLASH_MCR_ERS_U32))
    {
       /*
        * @violates @ref fls_c_REF_30 Cast from pointer to pointer
        * @violates @ref fls_c_REF_31 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer        
        */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        pDataPtrUnaligned = (Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr;
        *pDataPtrUnaligned = 0x0UL;

#ifdef CACHE_INVALIDATE_MACROS        
#if (CACHE_INVALIDATE_MACROS == STD_ON)        
        /* Flush the interlock write from cache to flash */
        Mcl_CacheFlushAll();
        /* Invalidate the bogus interlock write from cache, before the flash read */
        Mcl_CacheInvalidateAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */ 
#endif /* ifdef CACHE_INVALIDATE_MACROS */       
    }        

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /* clear read monitoring error flags (w1c) */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */
    REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_RVE_W1C | FLASH_MCR_RRE_W1C );
#endif    
    
#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eReadStatus = FLASH_E_PENDING;
    
    /* Initial 8-bit flash read (until the data bus alignment boundary) */ 
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr) ) && \
         /*
         * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
         * This violation is because of complex statement
         * @violates @ref fls_c_REF_10 Array indexing shall be the
         * only allowed form of pointer arithmetic
         */
         ( FLASH_E_PENDING == Fls_Flash_eReadStatus ); Fls_Flash_pReadAddressPtr++
       )
#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr); Fls_Flash_pReadAddressPtr++)
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */  
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C );
        
        /* read flash location */
        *pDataPtr = *Fls_Flash_pReadAddressPtr;

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        /* Store the ECC status (EER bit) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_U32))
        {
            bWasEccEvent = (boolean)TRUE;
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    #endif        
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        if ( (((boolean)FALSE) == Fls_Flash_aSectorList0[ePhySector].bEccTriggersExc) && \
             (((boolean)TRUE) == bWasEccEvent) \
           )
        {
            Fls_Flash_eReadStatus = FLASH_E_FAILED;
        }
    #endif        

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /* read flash location */
        *pDataPtr = *Fls_Flash_pReadAddressPtr;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        pDataPtr++;
    }

    /* Calculate end address of wide 32-bit or 64-bit flash read */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadBlockAddressEndPtr += Fls_Flash_CalcWideDataLength( u32InitDataLength, u32DataLength );

    /* Data bus width transfer */    
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr) ) && \
         ( FLASH_E_PENDING == Fls_Flash_eReadStatus ); Fls_Flash_pReadAddressPtr += \
           sizeof(Fls_Flash_DataBusWidthType) \
       )
#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr); Fls_Flash_pReadAddressPtr += \
           sizeof(Fls_Flash_DataBusWidthType) \
       )
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */  
    {
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C );
        
        /* @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type */
        pDataPtrUnaligned = (Fls_Flash_DataBusWidthType*)pDataPtr;
        /* read flash location */
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        *(pDataPtrUnaligned) = \
            *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        /* Store the ECC status (EER bit) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_U32))
        {
            bWasEccEvent = (boolean)TRUE;
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    #endif
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON) 
        if ( (((boolean)FALSE) == Fls_Flash_aSectorList0[ePhySector].bEccTriggersExc) && \
             (((boolean)TRUE) == bWasEccEvent) \
           )
        {
            Fls_Flash_eReadStatus = FLASH_E_FAILED;
        }
    #endif

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON )*/ 
        /* @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type */
        pDataPtrUnaligned = (Fls_Flash_DataBusWidthType*)pDataPtr;
        /* read flash location */
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        *(pDataPtrUnaligned) = \
            *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        pDataPtr += sizeof(Fls_Flash_DataBusWidthType);
    }
    
    /* Final 8-bit transfer */
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )    
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadAddressEndPtr) ) && \
         ( FLASH_E_PENDING == Fls_Flash_eReadStatus ); Fls_Flash_pReadAddressPtr++
       )
#else
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadAddressEndPtr); Fls_Flash_pReadAddressPtr++)
#endif /* #if( FLS_DSI_HANDLER_API == STD_ON ) */   
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C );
        
        /* read flash location */
        *pDataPtr = *Fls_Flash_pReadAddressPtr;

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        /* Store the ECC status (EER bit) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_U32))
        {
            bWasEccEvent = (boolean)TRUE;
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    #endif
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }
        
    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        if ( (((boolean)FALSE) == Fls_Flash_aSectorList0[ePhySector].bEccTriggersExc) && \
             (((boolean)TRUE) == bWasEccEvent) \
           )
        {
            Fls_Flash_eReadStatus = FLASH_E_FAILED;
        }
    #endif

#else
        /* read flash location */
        *pDataPtr = *Fls_Flash_pReadAddressPtr;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        pDataPtr++;
    }

#if( FLS_DSI_HANDLER_API == STD_ON )    
    if( FLASH_E_PENDING == Fls_Flash_eReadStatus )
    {
        Fls_Flash_eReadStatus = FLASH_E_OK;
    }
    
    eRetVal = Fls_Flash_eReadStatus;
#else
    eRetVal = FLASH_E_OK;
#endif  

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
    */ 
    if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_RVE_U32)) || (0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_RRE_U32)))
    {
        eRetVal = FLASH_E_FAILED;
    }
#endif 
  
    return eRetVal;
}
#if(( FLS_COMPARE_API == STD_ON ) || ( FLS_BLANK_CHECK_API == STD_ON ))
/**
* @brief          Compare data buffer with content of given flash sector.
*
* @param[in]      1           ePhySector Physical sector ID
* @param[in]      2           u32SectorOffset sector offset in bytes
* @param[in]      3           u32DataLength data length in bytes
* @param[in]      4           pDataPtr data to be compared
*                 
* @return         Fls_Flash_ReturnType
* @retval         FLASH_E_OK Operation succeeded
* @retval         FLASH_E_BLOCK_INCONSISTENT Data buffer doesn't match with content of flash sector
*
* @implements     Fls_Flash_SectorCompare_Activity
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_Flash_SectorCompare
(
    CONST( Fls_Flash_PhysicalSectorType, AUTOMATIC) ePhySector,
    CONST(Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST(Fls_LengthType, AUTOMATIC) u32DataLength,
    CONSTP2CONST(uint8, AUTOMATIC, FLS_APPL_CONST) pDataPtr
)
{
    VAR(uint32, AUTOMATIC) u32InitDataLength = 0UL;
    VAR(uint8, AUTOMATIC) Fls_Flash_u8ReadAddress8 = 0U;
    VAR(uint32, AUTOMATIC) Fls_Flash_u32ReadAddress32 = 0UL;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) pReadAddressEndPtr = NULL_PTR;
    P2CONST( volatile uint8, AUTOMATIC, FLS_APPL_CONST ) pReadBlockAddressEndPtr = NULL_PTR;
    PACKED P2VAR(Fls_Flash_DataBusWidthType, AUTOMATIC, FLS_APPL_DATA) pDataPtrUnaligned;
#if ( ( FLS_DSI_HANDLER_API == STD_ON ) && ( FLASH_DATA_FLASH_EXISTS == STD_ON ) )
    VAR( boolean, AUTOMATIC ) bWasEccEvent;
#endif
    
    /* Physical flash address to read */
    /*
    * @violates @ref fls_c_REF_2 A cast should not be performed
    * between a pointer to object type and a different pointer to object type
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    Fls_Flash_pReadAddressPtr = (volatile const uint8 *)(Fls_Flash_aSectorList0[ePhySector].pSectorStartAddressPtr) + \
                              u32SectorOffset;
#if (FLS_BLANK_CHECK_API == STD_ON)                              
    if (NULL_PTR == pDataPtr)
    {  
        /* BLANK_CHECK API */
        /* 
        *  @violates @ref fls_c_REF_2 A cast should not be performed
        *  between a pointer to object type and a different pointer to object type 
        */ 
        Fls_Flash_pCompareAddressPtr = (volatile const uint8 *) &Fls_Flash_ErasedValue;
    }
    else
#endif   
    {
        /* COMPARE API */
        Fls_Flash_pCompareAddressPtr = pDataPtr;
    }
    
        
    /* End of read pointer */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadAddressEndPtr = Fls_Flash_pReadAddressPtr + u32DataLength;
    
    /* Calculate end address of initial 8-bit transfer */
    u32InitDataLength = Fls_Flash_CalcInitDataLength( Fls_Flash_pReadAddressPtr, u32DataLength );
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadBlockAddressEndPtr = Fls_Flash_pReadAddressPtr + u32InitDataLength;
    
    /* first invalidate the flash prefetch buffer by performing a bogus interlock write 
       (avoid write if MCR[PGM|ERS] == 0)*/
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */ 
    if(0UL == REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_PGM_U32 | FLASH_MCR_ERS_U32))
    {
       /*
        * @violates @ref fls_c_REF_30 Cast from pointer to pointer
        * @violates @ref fls_c_REF_31 A cast shall not be performed that removes any const and
        * volatile qualification from the type address by a pointer        
        */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        pDataPtrUnaligned = (Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr;
        *pDataPtrUnaligned = 0x0UL;
    
#ifdef CACHE_INVALIDATE_MACROS    
#if (CACHE_INVALIDATE_MACROS == STD_ON)    
        /* Flush the interlock write from cache to flash */
        Mcl_CacheFlushAll();
        /* Invalidate the bogus interlock write from cache, before the flash read */
        Mcl_CacheInvalidateAll();
#endif /* CACHE_INVALIDATE_MACROS == STD_ON */ 
#endif /* ifdef CACHE_INVALIDATE_MACROS */       
    }   

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /* clear read monitoring error flags (w1c) */
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    */ 
    REG_BIT_SET32(FLASH_MCR_ADDR32, FLASH_MCR_RVE_W1C | FLASH_MCR_RRE_W1C );
#endif     

#if( FLS_DSI_HANDLER_API == STD_ON )
    Fls_Flash_eCompareStatus = FLASH_E_PENDING;
    
    /* Initial 8-bit flash read (until the data bus alignment boundary) */ 
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
    * This violation is because of complex statement
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr) ) && \
         ( Fls_Flash_eCompareStatus == FLASH_E_PENDING ); Fls_Flash_pReadAddressPtr++ \
       )
#else
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr); Fls_Flash_pReadAddressPtr++)
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */   
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C );
        
        /* read flash location */
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        /* Store the ECC status (EER bit) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_U32))
        {
            bWasEccEvent = (boolean)TRUE;
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    #endif
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON) 
        if ( (((boolean)FALSE) == Fls_Flash_aSectorList0[ePhySector].bEccTriggersExc) && \
             (((boolean)TRUE) == bWasEccEvent) \
           )
        {
            Fls_Flash_eCompareStatus = FLASH_E_FAILED;
        }
    #endif

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /* read flash location */
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /*
        * @violates @ref fls_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
        if( *Fls_Flash_pCompareAddressPtr != Fls_Flash_u8ReadAddress8 )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
            { 
                Fls_Flash_eCompareStatus = FLASH_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_Flash_eCompareStatus != FLASH_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_BLOCK_INCONSISTENT;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */          
        }
        else
        {
            /* *Fls_Flash_pCompareAddressPtr == *Fls_Flash_pReadAddressPtr */
        }

#if (FLS_BLANK_CHECK_API == STD_ON)         
        if (NULL_PTR == pDataPtr)
        {  
            /* BLANK_CHECK API */
        }
        else
#endif 
        {
            /* COMPARE API */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_pCompareAddressPtr++;
        }
    }

    /* Calculate end address of wide 32-bit or 64-bit flash read */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    pReadBlockAddressEndPtr += Fls_Flash_CalcWideDataLength( u32InitDataLength, u32DataLength );

    /* Data bus width transfer */    
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr) ) && \
         /*
         * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
         * This violation is because of complex statement
         */
         ( FLASH_E_PENDING == Fls_Flash_eCompareStatus ); Fls_Flash_pReadAddressPtr += \
         /*
         * @violates @ref fls_c_REF_10 Array indexing shall be the
         * only allowed form of pointer arithmetic
         */
         sizeof(Fls_Flash_DataBusWidthType) \
       )
#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadBlockAddressEndPtr); Fls_Flash_pReadAddressPtr += \
         /*
         * @violates @ref fls_c_REF_10 Array indexing shall be the
         * only allowed form of pointer arithmetic
         */
         sizeof(Fls_Flash_DataBusWidthType) \
       )
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */   
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32,FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C );
        /* read flash location */
        /* @violates @ref fls_c_REF_2 A cast should not be performed between a pointer to object type 
            and a different pointer to object type */
        Fls_Flash_u32ReadAddress32 = *((const volatile Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        /* Store the ECC status (EER bit) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_U32))
        {
            bWasEccEvent = (boolean)TRUE;
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    #endif
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        if ( (((boolean)FALSE) == Fls_Flash_aSectorList0[ePhySector].bEccTriggersExc) && \
             (((boolean)TRUE) == bWasEccEvent) \
           )
        {
            Fls_Flash_eCompareStatus = FLASH_E_FAILED;
        }
    #endif

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /* read flash location */
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        */
        Fls_Flash_u32ReadAddress32 = *((const volatile Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr);
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /*
        * @violates @ref fls_c_REF_2 A cast should not be performed
        * between a pointer to object type and a different pointer to object type
        * @violates @ref fls_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
        if( *((volatile const Fls_Flash_DataBusWidthType*)Fls_Flash_pCompareAddressPtr) !=
            Fls_Flash_u32ReadAddress32 
          )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
            { 
                Fls_Flash_eCompareStatus = FLASH_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_Flash_eCompareStatus != FLASH_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_BLOCK_INCONSISTENT;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        }
        else
        {
            /* *((const volatile Fls_Flash_DataBusWidthType*)Fls_Flash_pCompareAddressPtr) = \
               *((const volatile Fls_Flash_DataBusWidthType*)Fls_Flash_pReadAddressPtr) */
        }
#if (FLS_BLANK_CHECK_API == STD_ON) 
        if (NULL_PTR == pDataPtr)
        {  
            /* BLANK_CHECK API */
        }
        else
#endif 
        {
            /* COMPARE API */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_pCompareAddressPtr += sizeof(Fls_Flash_DataBusWidthType);
        }
    }
    
    /* Final 8-bit transfer */
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    */
#if( FLS_DSI_HANDLER_API == STD_ON )    
    /*
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ( ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadAddressEndPtr) ) && \
         /*
         * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
         * This violation is because of complex statement
         * @violates @ref fls_c_REF_10 Array indexing shall be the
         * only allowed form of pointer arithmetic
         */
         ( FLASH_E_PENDING == Fls_Flash_eCompareStatus ); Fls_Flash_pReadAddressPtr++
       )
#else   
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_4 No reliance shall be placed on
    * undefined or unspecified behaviour
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type
    */
    /* Compiler_Warning: see fls_c_REF_CW_01 */
    for( ; ((uint32)Fls_Flash_pReadAddressPtr) < ((uint32)pReadAddressEndPtr); Fls_Flash_pReadAddressPtr++)
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */   
    {
#if( FLS_DSI_HANDLER_API == STD_ON )
        /* start flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->startFlashAccessNotifPtr )
        {
            /* Call FlsStartFlashAccessNotif function if configured */
            Fls_pConfigPtr->startFlashAccessNotifPtr();
        }
        
        /* clear EER flags (w1c) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        REG_BIT_CLEAR32(FLASH_MCR_ADDR32, FLASH_MCR_RWE_W1C | FLASH_MCR_SBC_W1C );
        
        /* read flash location */
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON)
        /* Store the ECC status (EER bit) */
        /*
        * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
        */ 
        if(0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_EER_U32))
        {
            bWasEccEvent = (boolean)TRUE;
        }
        else
        {
            bWasEccEvent = (boolean)FALSE;
        }
    #endif
        
        /* end flash access section: implementation depends on integrator */
        if( NULL_PTR != Fls_pConfigPtr->finishedFlashAccessNotifPtr )
        {
            /* Call Fls_FinishedFlashAccessNotif function if configured */
            Fls_pConfigPtr->finishedFlashAccessNotifPtr();
        }

    #if (FLASH_DATA_FLASH_EXISTS == STD_ON) 
        if ( (((boolean)FALSE) == Fls_Flash_aSectorList0[ePhySector].bEccTriggersExc) && \
             (((boolean)TRUE) == bWasEccEvent) \
           )
        {
            Fls_Flash_eCompareStatus = FLASH_E_FAILED;
        }
    #endif

#else   /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /* read flash location */
        Fls_Flash_u8ReadAddress8 = *Fls_Flash_pReadAddressPtr;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        /*
        * @violates @ref fls_c_REF_4 No reliance shall be placed on
        * undefined or unspecified behaviour
        */
        if( *Fls_Flash_pCompareAddressPtr != Fls_Flash_u8ReadAddress8 )
        {
#if( FLS_DSI_HANDLER_API == STD_ON )
            if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
            { 
                Fls_Flash_eCompareStatus = FLASH_E_BLOCK_INCONSISTENT;
            }
            else
            {
                /* Fls_Flash_eCompareStatus != FLASH_E_PENDING */
            }
#else
            /*
            * @violates @ref fls_c_REF_5 Return statement before end of function.
            */
            return FLASH_E_BLOCK_INCONSISTENT;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */
        }
        else
        {
            /* *Fls_Flash_pCompareAddressPtr == *Fls_Flash_pReadAddressPtr */
        }
#if (FLS_BLANK_CHECK_API == STD_ON)         
        if (NULL_PTR == pDataPtr)
        {  
            /* BLANK_CHECK API */
        }
        else
#endif  
        {
            /* COMPARE API */
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            */
            Fls_Flash_pCompareAddressPtr++;
        }
    }

#if(FLS_EXTENDED_READ_ERROR_CHECK == STD_ON)
    /*
    * @violates @ref fls_c_REF_32 Conversions shall not be performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type and an integral type
    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'.
    */ 
    if((0U != REG_BIT_GET32(FLASH_MCR_ADDR32,FLASH_MCR_RVE_U32)) || (0U != REG_BIT_GET32(FLASH_MCR_ADDR32, FLASH_MCR_RRE_U32)))
    {
        /*
        * @violates @ref fls_c_REF_5 Return statement before end of function.
        */
        return FLASH_E_FAILED;
    }
#endif     

#if( FLS_DSI_HANDLER_API == STD_ON )    
    if( FLASH_E_PENDING == Fls_Flash_eCompareStatus )
    {
        Fls_Flash_eCompareStatus = FLASH_E_OK;
    }
    else
    {
        /* Do nothing */
    }
    /*
    * @violates @ref fls_c_REF_5 Return statement before end of function.
    */
    return Fls_Flash_eCompareStatus;
#else
    /*
    * @violates @ref fls_c_REF_5 Return statement before end of function.
    */
    return FLASH_E_OK;
#endif  /* #if( FLS_DSI_HANDLER_API == STD_ON ) */ 
}
#endif /* ( FLS_COMPARE_API == STD_ON ) || (FLS_BLANK_CHECK_API == STD_ON) */


#if( FLS_DSI_HANDLER_API == STD_ON )
/**
* @brief          Low level data storage exception handler.
*
* @return         Exc_CompHandlerReturnType
* @retval         EXC_HANDLED_SKIP The data storage exception was 
*                 caused by currently pending flash read or compare job
* @retval         EXC_UNHANDLED The data storage exception was 
*                 NOT caused by currently pending flash read or compare job
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Fls_CompHandlerReturnType, FLS_CODE ) Fls_DsiHandler
(
    P2CONST( Fls_ExceptionDetailsType, AUTOMATIC, FLS_APPL_CONST ) pExceptionDetailsPtr 
)
{
    VAR( Fls_CompHandlerReturnType, AUTOMATIC ) u8RetVal = FLS_UNHANDLED;

    /* @errata ERR_IPV_FLASH_0005 */
    #ifdef ERR_IPV_FLASH_0005
      #if (ERR_IPV_FLASH_0005 == STD_ON)   
        VAR(uint8, AUTOMATIC) u8DataPtr;
    
        u8DataPtr = *((volatile uint8 *)0x00C02000U);
     #endif
    #endif
        
    /*  Check whether there is 
        [1] pending read, compare, erase or write job, 
        [2] exception syndrome register indicates "DSI reason"(caused by driver load instruction) or 
                "DSI cache reason"(caused by a cache fetch, triggered by the flash access), and 
        [3] data_pt is in the same cache line as the address currently accessed by pending flash read or flash compare job*/       
    if( (FLASH_E_PENDING == Fls_Flash_eReadStatus ) 
        && 
        ( ( FLASH_DSI_EXC_SYNDROME       == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME)     ) ||
          ( FLASH_DSI_EXC_SYNDROME_CACHE == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME_CACHE) )
        )
        &&
        /* The reported exception address is in the same 32 bytes cache line as the Fls_Flash_pReadAddressPtr */
        /*
        * @violates @ref fls_c_REF_25 Cast from pointer to unsigned long
        * Due to casting between a pointer and unsigned long representing address.
        * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
        * and an integral type
        */
        /* Compiler_Warning: see fls_c_REF_CW_01 */
        ( ((uint32)pExceptionDetailsPtr->data_pt >> 5) == ((uint32)Fls_Flash_pReadAddressPtr >> 5) )
      /*
      * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
      * This violation is because of complex statement
      */  
      )
    {
        Fls_Flash_eReadStatus = FLASH_E_FAILED;
        u8RetVal = FLS_HANDLED_SKIP;
    }
    else if( (FLASH_E_PENDING == Fls_Flash_eCompareStatus ) 
             && 
             ( ( FLASH_DSI_EXC_SYNDROME       == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME)     ) ||
               ( FLASH_DSI_EXC_SYNDROME_CACHE == (pExceptionDetailsPtr->syndrome_u32 & FLASH_DSI_EXC_SYNDROME_CACHE) )
             )
             &&
             /* The reported exception address is in the same 32 bytes cache line as the Fls_Flash_pReadAddressPtr */
             /*
             * @violates @ref fls_c_REF_25 Cast from pointer to unsigned long
             * Due to casting between a pointer and unsigned long representing address.
             * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
             * and an integral type
             */
             /* Compiler_Warning: see fls_c_REF_CW_01 */
             ( ( ((uint32)pExceptionDetailsPtr->data_pt >> 5) == ((uint32)Fls_Flash_pReadAddressPtr >> 5) ) ||
              /*
               * @violates @ref fls_c_REF_25 Cast from pointer to unsigned long
               * Due to casting between a pointer and unsigned long representing address.
               * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
               * and an integral type
               */
               /* Compiler_Warning: see fls_c_REF_CW_01 */
               ( ((uint32)pExceptionDetailsPtr->data_pt >> 5) == ((uint32)Fls_Flash_pCompareAddressPtr >> 5) )
             /*
              * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
              * This violation is because of complex statement
              */  
             )
           /*
            * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
            * This violation is because of complex statement
            */
           )
    {
        Fls_Flash_eCompareStatus = FLASH_E_FAILED;
        u8RetVal = FLS_HANDLED_SKIP;
    }
    else
    {
        /* FLS_UNHANDLED */
    }    
    
    return u8RetVal;
}

#ifdef IPV_FLASH
    /* for XPC560XB, XPC560XP platform */
    #if ((IPV_FLASH == IPV_FLASH_C90FG_544_2_9_65) || (IPV_FLASH == IPV_FLASH_C90FG_1568_2_6_69) || \
         (IPV_FLASH == IPV_FLASH_C90FG_1024_2_0) ||  (IPV_FLASH == IPV_FLASH_C90FG_512_2_9) || \
         (IPV_FLASH == IPV_FLASH_C90FG_256_1_4) \
        )

    /**
    * @brief          Low level data storage exception handler.
    *
    * @return         Exc_CompHandlerReturnType
    * @retval         EXC_HANDLED_SKIP The data storage exception was 
    *                 caused by currently pending flash read or compare job
    * @retval         EXC_UNHANDLED The data storage exception was 
    *                 NOT caused by currently pending flash read or compare job
    */
    FUNC( Fls_CompHandlerReturnType, FLS_CODE ) Fls_MciHandler
    (
        P2CONST( Fls_ExceptionDetailsType, AUTOMATIC, FLS_APPL_CONST ) pExceptionDetailsPtr 
    )
    {
        VAR( Fls_CompHandlerReturnType, AUTOMATIC ) u8RetVal = FLS_UNHANDLED;

        /* @errata ERR_IPV_FLASH_0005 */
        #ifdef ERR_IPV_FLASH_0005
          #if (ERR_IPV_FLASH_0005 == STD_ON)   
            VAR(uint8, AUTOMATIC) u8DataPtr;
        
        
            u8DataPtr = *((volatile uint8 *)0x00C02000U);
         #endif
        #endif
    
        /*  In case of IVOR1 on Z0 check whether there is:
            [1] pending read, compare, erase or write job, 
            [2] exception syndrome register indicates DSI reason, and 
            [3] data_pt matches address currently accessed by pending flash read or flash compare job 
            [-] There is NO MCAR nor DEAR special register so address currently accessed can be taken 
                from Platform Flash ECC Address Register (PFEAR) on ECSM when after 
                ECC Configuration Register (ECR) has been configured.
        */
         
        if( ( FLASH_E_PENDING == Fls_Flash_eReadStatus ) && 
            ( FLASH_MCI_EXC_SYNDROME == 
              ( pExceptionDetailsPtr->syndrome_u32 & \
                FLASH_MCI_EXC_SYNDROME
              ) 
            ) && 
            /*
            * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
            * This violation is because of complex statement
            */
            ( pExceptionDetailsPtr->data_pt == Fls_Flash_pReadAddressPtr )
          )
        {
            Fls_Flash_eReadStatus = FLASH_E_FAILED;
            u8RetVal = FLS_HANDLED_SKIP;
        }   
        else if( ( FLASH_E_PENDING == Fls_Flash_eCompareStatus ) &&
                 ( FLASH_MCI_EXC_SYNDROME == \
                   ( pExceptionDetailsPtr->syndrome_u32 & FLASH_MCI_EXC_SYNDROME) 
                 ) &&
                 ( ( pExceptionDetailsPtr->data_pt == Fls_Flash_pReadAddressPtr ) ||
                    /*
                    * @violates @ref fls_c_REF_3 Side effects on right hand of logical operator: '||' or '&&'. 
                    * This violation is because of complex statement
                    */
                   ( pExceptionDetailsPtr->data_pt == Fls_Flash_pCompareAddressPtr )
                 )
               )
        {
            Fls_Flash_eCompareStatus = FLASH_E_FAILED;
            u8RetVal = FLS_HANDLED_SKIP;
        }
        else
        {
            /* FLS_UNHANDLED */
        }

        return u8RetVal;
    }
    #endif /* for XPC560XB platforms */
#endif /*ifdef IPV_FLASH */


#endif /* FLS_DSI_HANDLER_API == STD_ON */


/** 
* @brief        Maps u32TargetAddress to sector index
*
* @details      Calculate index of logical sector u32TargetAddress belongs to
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       Zero based index of logical sector
* @retval       0 .. (Fls_pConfigPtr->u32SectorCount - 1)
*
* @pre          The module must be initialized
* @pre          u32TargetAddress must be in configured flash boundary
*    
*/
static FUNC(Fls_SectorIndexType, FLS_CODE) Fls_GetSectorIndexByAddr
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32SectorIndex = 0UL;

    for( u32SectorIndex = 0U; u32SectorIndex < Fls_pConfigPtr->u32SectorCount;
         u32SectorIndex++ 
       )
    {
        if( u32TargetAddress <= (*(Fls_pConfigPtr->pSectorEndAddr))[u32SectorIndex] )
        {
            /* u32TargetAddress belongs to sector with index u32SectorIndex */
            break;
        }
        else
        {
            /* Check next sector */
        }
    }
    
    return u32SectorIndex;
}

/** 
* @brief        Return start address of given sector
*
* @details      Calculate start address (in linear space) of logical sector
*               specified by the u32SectorIndex parameter
*
* @param[in]    u32SectorIndex Index of logical sector
*
* @return       Start address of u32SectorIndex sector
* @retval       0 .. (FLS_TOTAL_SIZE - 1)
*
* @pre          The module must be initialized
* @pre          u32SectorIndex must be in range 0 .. (Fls_pConfigPtr->u32SectorCount - 1)
*    
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_GetSectorStartAddr
( CONST(Fls_SectorIndexType, AUTOMATIC) u32SectorIndex )
{
    VAR( Fls_AddressType, AUTOMATIC ) u32TargetAddress = 0U;
    
    if( 0U != u32SectorIndex ) 
    {
        u32TargetAddress = (*(Fls_pConfigPtr->pSectorEndAddr))[u32SectorIndex - 1U] + 1U;
    }
    else
    {
        /* First sector starts with address 0 */
    }

    return u32TargetAddress;
}

/** 
* @brief        Check whether u32TargetAddress is page aligned
*
* @details      Check whether u32TargetAddress is integer multiple of FLS_PAGE_SIZE
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is page aligned
* @retval       FALSE u32TargetAddress is not page aligned
*    
*/
#if( FLS_DEV_ERROR_DETECT == STD_ON )
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageAligned(
    CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;
    
    /* Aligned to Double Word or Word depending if CODE/DATA Flash or DFO */
    if(0U == (u32TargetAddress % FLS_PAGE_SIZE)) 
    {   
        bRetVal = (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not page aligned */
    }

    return( bRetVal );
}

/** 
* @brief        Check whether u32TargetAddress is page start aligned
*
* @details      Check whether u32TargetAddress is in range and aligned to first 
*               byte of flash page
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is in range and aligned to start of the page
* @retval       FALSE u32TargetAddress is not in range or aligned to start of the page
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsAddrPageStartAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;    
    
    if(( u32TargetAddress < (Fls_AddressType)FLS_TOTAL_SIZE ) &&
        ( (boolean)TRUE == Fls_IsAddrPageAligned( u32TargetAddress ) ) \
      )
    {
        bRetVal = (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not in range or aligned to start of the page */
    }
    
    return( bRetVal );    
}

/** 
* @brief        Check whether u32TargetAddress is page start aligned
*
* @details      Check whether u32Length is in range and aligned to 
*               flash page
*
* @param[in]    u32TargetAddress Target address in flash memory
* @param[in]    u32Length size of current write
*
* @return       boolean
* @retval       TRUE u32TargetAddress is in range and aligned to end of the page
* @retval       FALSE u32TargetAddress is not in range or aligned to end of the page
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsLengthAligned
(
    CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress,
    CONST(Fls_LengthType, AUTOMATIC) u32Length    
)
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;

    if((((u32TargetAddress + u32Length) - 1U) < (Fls_AddressType)FLS_TOTAL_SIZE ) &&
       (0U == (u32Length % FLS_PAGE_SIZE))
      ) 
    {    
        bRetVal = (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not in range or aligned to end of the page */
    }
    
    return( bRetVal );
}


/** 
* @brief        Check whether u32TargetAddress is sector start aligned
*
* @details      Check whether u32TargetAddress is in range and aligned to first 
*               byte of flash sector
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is in range and aligned to start of the sector
* @retval       FALSE u32TargetAddress is not in range or not aligned to 
*               start of the sector
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsAddrSectorStartAligned
( 
    CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress 
)
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;
    
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if( ( u32TargetAddress < FLS_TOTAL_SIZE ) && 
        ( u32TargetAddress == Fls_GetSectorStartAddr( Fls_GetSectorIndexByAddr( u32TargetAddress )))
      )
    {
        bRetVal = (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not in range or 
            not aligned to start of the sector */
    }
    
    return bRetVal;
}



/** 
* @brief        Check whether u32TargetAddress is sector end aligned
*
* @details      Check whether u32TargetAddress is in range and aligned to last 
*               byte of flash sector
*
* @param[in]    u32TargetAddress Target address in flash memory
*
* @return       boolean
* @retval       TRUE u32TargetAddress is in range and aligned to end of the sector
* @retval       FALSE u32TargetAddress is not in range or not aligned to 
*               end of the sector
*
* @pre          The module must be initialized
*    
*/
static FUNC(boolean, FLS_CODE) Fls_IsAddrSectorEndAligned
( CONST(Fls_AddressType, AUTOMATIC) u32TargetAddress )
{
    VAR( boolean, AUTOMATIC ) bRetVal = (boolean)FALSE;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32SectorIndex = 0UL;
    
    u32SectorIndex = Fls_GetSectorIndexByAddr( u32TargetAddress );
    
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    */
    if(( u32TargetAddress < FLS_TOTAL_SIZE ) &&
        ( u32TargetAddress == (*(Fls_pConfigPtr->pSectorEndAddr))[u32SectorIndex] )
      )
    {    
        bRetVal =  (boolean)TRUE;
    }
    else
    {
        /* u32TargetAddress is not in range or not aligned to end of the sector */
    }
    
    return bRetVal;
}
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */


#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
/** 
* @brief        Load access code to RAM
*
* @details      Load erase or write access code to statically 
*               pre-configured location in RAM
*
* @param[in]    eJob Type of access code to load. Can be either 
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized
*
* @implements     Fls_LoadAc_Activity
*    
*/
static FUNC( void, FLS_CODE ) Fls_LoadAc
( CONST( Fls_JobType, AUTOMATIC) eJob )
{
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pRomPtr = NULL_PTR;
    P2CONST( uint32, AUTOMATIC, FLS_APPL_CONST ) pRomEndPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pRamPtr = NULL_PTR;

    switch( eJob ) 
    {
        case FLS_JOB_ERASE:
            pRomPtr = Fls_ACEraseRomStart;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * 
            * @violates @ref fls_c_REF_20 Conversions involving function 
            * pointers must be to/from integral types
            * 
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type             
            */
            pRomEndPtr = pRomPtr + (uint32)(Fls_ACEraseSize);
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            * 
            * @violates @ref fls_c_REF_20 Conversions involving function 
            * pointers must be to/from integral types                        
            */
            pRamPtr = (uint32*)(Fls_pConfigPtr->acErasePtr);
            break;
        
        case FLS_JOB_WRITE:
            pRomPtr = Fls_ACWriteRomStart;
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * 
            * @violates @ref fls_c_REF_20 Conversions involving function 
            * pointers must be to/from integral types    
            *
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type             
            */
            pRomEndPtr = pRomPtr + (uint32)(Fls_ACWriteSize);
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            *
            * @violates @ref fls_c_REF_20 Conversions involving function 
            * pointers must be to/from integral types                         
            */
            pRamPtr = (uint32*)(Fls_pConfigPtr->acWritePtr);
            break;
        
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }

    /* Copy erase or write access code to RAM */
    /* pRomEndPtr is dynamically calculated and might not be multiple of 4U */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_22 Relational or subtract operator applied to pointers 
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type    
    */
    for(; (uint32)pRomPtr < (uint32)pRomEndPtr; pRomPtr++)
    {
        *pRamPtr = *pRomPtr;
        /*
        * @violates @ref fls_c_REF_10 Array indexing shall be the
        * only allowed form of pointer arithmetic
        */
        pRamPtr++;
    }
}


/** 
* @brief        Unload access code to RAM
*
* @details      Erase write or erase access code from statically 
*               pre-configured location in RAM. Fills the RAM location
*               with FLS_AC_UNLOAD_PATTERN
*
* @param[in]    eJob Type of access code to unload. Can be either 
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized
*
* @implements     Fls_UnloadAc_Activity
*    
*/
static FUNC( void, FLS_CODE ) Fls_UnloadAc
( CONST( Fls_JobType, AUTOMATIC) eJob )
{
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pRamPtr = NULL_PTR;
    P2VAR( uint32, AUTOMATIC, FLS_APPL_DATA ) pRamEndPtr = NULL_PTR;
    
    switch( eJob ) 
    {
        case FLS_JOB_ERASE:
        
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            * @violates @ref fls_c_REF_20 Conversions involving function 
            * pointers must be to/from integral types                         
            */
            pRamPtr = (uint32*)(Fls_pConfigPtr->acErasePtr);
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_20 Conversions involving function 
            * pointers must be to/from integral types     
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type             
            */
            pRamEndPtr = pRamPtr + (uint32)(Fls_ACEraseSize);
            break;
        
        case FLS_JOB_WRITE:
        
            /*
            * @violates @ref fls_c_REF_2 A cast should not be performed
            * between a pointer to object type and a different pointer to object type
            * @violates @ref fls_c_REF_4 No reliance shall be placed on
            * undefined or unspecified behaviour
            * @violates @ref fls_c_REF_20 Conversions involving function 
            * pointers must be to/from integral types                         
            */
            pRamPtr = (uint32*)(Fls_pConfigPtr->acWritePtr);
            /*
            * @violates @ref fls_c_REF_10 Array indexing shall be the
            * only allowed form of pointer arithmetic
            * @violates @ref fls_c_REF_20 Conversions involving function 
            * pointers must be to/from integral types 
            * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
            * and an integral type            
            */
            pRamEndPtr = pRamPtr + (uint32)(Fls_ACWriteSize);
            break;
        
        default:
            /* Do nothing - should not happen in Fully Trusted Environment;
               'default' clause added to fulfill MISRA Rule 15.3 */
            break;
    }    

    /* Unload (erase) write or erase access code from RAM */
    /*
    * @violates @ref fls_c_REF_10 Array indexing shall be the
    * only allowed form of pointer arithmetic
    * @violates @ref fls_c_REF_22 Relational or subtract operator applied to pointers
    * @violates @ref fls_c_REF_41 Conversions shall not be
    * performed between a pointer to a function and any type other than an integral type
    * @violates @ref fls_c_REF_8 A cast should not be performed between a pointer type 
    * and an integral type      
    */
    for(; (uint32)pRamPtr < (uint32)pRamEndPtr; pRamPtr++)
    {
        *pRamPtr = FLS_AC_UNLOAD_PATTERN;
    }    
}
#endif /* FLS_AC_LOAD_ON_JOB_START */

/** 
* @brief        Erase one complete flash sector
*
* @details      Call low level flash driver service 
*               to erase one complete flash sector specified by the Fls_u32JobSectorIt
*               internal job variable
*
* @return       MemIf_JobResultType
* @retval       MEMIF_JOB_OK erase operation succeeded and there 
*               is no more sectors to erase
* @retval       MEMIF_JOB_PENDING erase operation succeeded and there 
*               is still one or more sectors to erase
* @retval       MEMIF_JOB_FAILED operation failed due to hardware error
*
* @param[in]    Job Type of access code to unload. Can be either 
*               FLS_JOB_ERASE or FLS_JOB_WRITE
*
* @pre          The module must be initialized, the Fls_u32JobSectorIt internal
*               job variable must contain index of logical sector to be erased, and
*               Fls_u32JobSectorEnd must contain index of last logical sector to be erased
*
* @post         increments the Fls_u32JobSectorIt internal job variable
*
*
* @implements     Fls_DoJobErase_Activity
*    
*/
static FUNC( MemIf_JobResultType, FLS_CODE )  Fls_DoJobErase( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_PENDING;
    
    if( Fls_u32JobSectorIt > Fls_u32JobSectorEnd )
    {
        /* No more sectors to erase */
        eRetVal = MEMIF_JOB_OK;
    }
    else
    {
        VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC ) ePhysicalSectorId;
#if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
        VAR( Fls_LengthType, AUTOMATIC ) u32PhysicalSectorSize = 0UL;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */
        VAR( boolean, AUTOMATIC ) bAsynch = (boolean)0;
        VAR( Fls_Flash_ReturnType, AUTOMATIC ) eLldRetVal = FLASH_E_OK;
        
        /* Map logical sector index to physical sector ID */
        ePhysicalSectorId = (*(Fls_pConfigPtr->pPhysicalSector))[Fls_u32JobSectorIt];

#if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
        /* Calculate size of the physical sector */
        u32PhysicalSectorSize = ( (*(Fls_pConfigPtr->pSectorEndAddr))[Fls_u32JobSectorIt] -           
                               Fls_GetSectorStartAddr( Fls_u32JobSectorIt )
                             ) + (Fls_LengthType)1;
#endif    /* FLS_ERASE_BLANK_CHECK == STD_ON */

        /* Get the Fls_Flash_SectorErase function operation mode */
        if( (*(Fls_pConfigPtr->pSectorFlags))[Fls_u32JobSectorIt] & 
            FLS_SECTOR_ERASE_ASYNCH 
          )
        {       
            bAsynch = (boolean)TRUE;
        }
        else
        {          
            bAsynch = (boolean)FALSE;
        }

#if (FLASH_INTERLEAVED_BLOCK == STD_ON)
        /* To inform Mainfunction how to erase an interleaved block - in async mode only */
        Fls_Flash_bAsyncInterleavedBlock = Fls_Flash_aSectorList0[ePhysicalSectorId].bInterleavedBlo;
#endif /* FLASH_INTERLEAVED_BLOCK == STD_ON */
    
        /* Call Low-Level driver to erase one sector with 
            the Fls_u32JobSectorIt sector index */    
#if( (FLS_ERASE_BLANK_CHECK == STD_ON) ||  (STD_ON == FLS_SYNCRONIZE_CACHE) )
        eLldRetVal = Fls_Flash_SectorErase( ePhysicalSectorId, u32PhysicalSectorSize, bAsynch );        
#else
        eLldRetVal = Fls_Flash_SectorErase( ePhysicalSectorId, bAsynch );
#endif
        if(( FLASH_E_OK == eLldRetVal ) && ( Fls_u32JobSectorIt == Fls_u32JobSectorEnd ))
        {
            eRetVal = MEMIF_JOB_OK;
        }
        else if( FLASH_E_FAILED == eLldRetVal )
        {
            eRetVal = MEMIF_JOB_FAILED;
        }
        else
        {
            /* The erase operation is either pending (FLASH_E_PENDING) 
            in hardware in case of asynchronous operation or 
            finished (FLASH_E_OK) in case of synchronous operation
            and there is more sectors to erase */
            Fls_u32JobSectorIt++;
        }
    }
    
    return( eRetVal );
}


/** 
* @brief       Calculate last logical address to read, write, or compare 
*              from in current cycle of Fls_MainFunction
*
* @details      Calculate last logical address of Fls_DoJobDataTransfer
*               loop to limit number of bytes transferred to/from flash memory
*               in one cycle of Fls_MainFunction
*
* @return       Fls_AddressType
* @retval       0 .. (FLS_TOTAL_SIZE - 1)
*
* @param[in]    u32MaxTransfer Maximum number of bytes to read, write, or compare 
*               in current cycle of Fls_MainFunction
*
* @pre          Fls_u32JobAddrIt must contain current, and Fls_u32JobAddrEnd last
*               logical address of current job
*    
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcMaxTransferAddrEnd
( CONST( Fls_LengthType, AUTOMATIC) u32MaxTransfer )
{
    VAR( Fls_AddressType, AUTOMATIC ) u32MaxTransferEndAddr = Fls_u32JobAddrEnd;
    
    /* Adjust the u32MaxTransferEndAddr address to transfer only
        the u32MaxTransfer bytes in one Fls_MainFunction() call */
    if( u32MaxTransferEndAddr >= (Fls_u32JobAddrIt + u32MaxTransfer) )
    {
        u32MaxTransferEndAddr = (Fls_u32JobAddrIt + u32MaxTransfer) - 1U;
    } 
    else
    {
        /* No adjustment is necessary. Job will finish in this cycle
            of Fls_MainFunction */
    }
    
    return( u32MaxTransferEndAddr );
}

/** 
* @brief       Calculate sector offset to read, write, or compare 
*              from current sector
*
* @details      Calculate sector offset in bytes for low-level driver
*               services
*
* @return       Fls_AddressType
* @retval      0 .. (FLS_SECTOR_SIZE - 1)
*
* @pre         The module must be initialized, Fls_u32JobSectorIt internal job
*              variable must contain index of current logical sector, 
*              Fls_u32JobAddrIt must contain current logical address
*    
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferOffset( void )
{    
    VAR( Fls_AddressType, AUTOMATIC ) u32SectorAddrStart = 0UL;
        
    /* Get first address of Fls_u32JobSectorIt sector */
    u32SectorAddrStart = Fls_GetSectorStartAddr( Fls_u32JobSectorIt );

    /* Calculate the sector offset */
    return( Fls_u32JobAddrIt - u32SectorAddrStart );    
}


/** 
* @brief       Calculate number of bytes to read, write, or compare 
*              from current sector
*
* @details      Calculate sector transfer length for low-level driver
*               services
*
* @param[in]    u32MaxTransferEndAddr Last address to read, write, 
*               or compare data from in this cycle of Fls_MainFunction
*        
* @return      Fls_AddressType
* @retval      0 .. (FLS_SECTOR_SIZE - 1)
*
* @pre        The module must be initialized, Fls_u32JobSectorIt internal job
*             variable must contain index of current logical sector, 
*             Fls_u32JobAddrIt must contain current logical address, and
*             u32MaxTransferEndAddr must be >= Fls_u32JobAddrIt and lie within 
*             the specified lower and upper flash address boundaries
*    
*/
static FUNC( Fls_AddressType, FLS_CODE ) Fls_CalcSectorTransferLength
( CONST( Fls_AddressType, AUTOMATIC) u32MaxTransferEndAddr )
{
    VAR( Fls_AddressType, AUTOMATIC ) u32SectorEndAddr = 0UL;
        
    /* Get last address of Fls_u32JobSectorIt sector */
    u32SectorEndAddr = (*(Fls_pConfigPtr->pSectorEndAddr))[Fls_u32JobSectorIt];
        
    /* Adjust the u32SectorEndAddr according to max number of bytes to transfer
        during one cycle of Fls_MainFunction */
    if( u32SectorEndAddr > u32MaxTransferEndAddr )
    {
        u32SectorEndAddr = u32MaxTransferEndAddr;
    }
    else
    {
        /* No adjustment is necessary. There is more sectors 
            to transfer */
    }

    /* Calculate number of bytes to read from the sector */
    return(( u32SectorEndAddr - Fls_u32JobAddrIt ) + 1U );
}

/** 
* @brief       Read up to one physical flash sector
*
* @details      Call low level flash driver service to read given number of bytes
*               from given sector offset.
*
* @param[in]    SectorOffset Flash sector offset to read data from
* @param[in]    Length Number of bytes to read
*        
* @return       Fls_Flash_ReturnType
* @retval       FLASH_E_OK read operation succeeded
* @retval       FLASH_E_FAILED read operation failed due to a hardware error
*
* @pre          The module must be initialized, the Fls_u32JobSectorIt internal job
*               variable must contain valid index of logical sector to read, 
*               u32SectorOffset and u32Length must be in physical    sector boundary,
*               Fls_pJobDataDestPtr internal job variable must point to data read buffer
*
* @implements     Fls_DoJobRead_Activity
*    
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_DoJobRead
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length
)
{
    VAR( Fls_Flash_ReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;
    VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC ) ePhysicalSector;
    
    /* Map logical sector index to physical sector ID */
    ePhysicalSector = (*(Fls_pConfigPtr->pPhysicalSector))[Fls_u32JobSectorIt];
    
    /* Do physical sector read */
    if( FLASH_E_OK != Fls_Flash_SectorRead( ePhysicalSector, u32SectorOffset,
                                            u32Length, Fls_pJobDataDestPtr 
                                          )
      )
    {
        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_READ_FAILED);
        #endif
   
        eRetVal = FLASH_E_FAILED;
    }

    return( eRetVal );
}
 
/** 
* @brief        Write up to one physical flash sector
*
* @details      Call low level flash driver service to write given number of bytes
*               at given sector offset
*
* @param[in]    u32SectorOffset Flash sector offset to write data from
* @param[in]    Length Number of bytes to read
*        
* @return       Fls_Flash_ReturnType
* @retval       FLASH_E_OK write operation succeeded
* @retval       FLASH_E_FAILED write operation failed due to a hardware error
*
* @pre          The module must be initialized, the Fls_u32JobSectorIt internal job
*               variable must contain valid index of logical sector to write, 
*               u32SectorOffset and u32Length must be in physical sector boundary and page
*               aligned, Fls_pJobDataSrcPtr internal job variable must point to data
                write buffer
*
* @implements     Fls_DoJobWrite_Activity
*    
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_DoJobWrite
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
)
{
    VAR( Fls_Flash_ReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;
    VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC ) ePhysicalSector;
    VAR( boolean, AUTOMATIC ) bAsynch = (boolean)0;

    /* Map logical sector index to physical sector ID */
    ePhysicalSector = (*(Fls_pConfigPtr->pPhysicalSector))[Fls_u32JobSectorIt];

    /* Get the Fls_Flash_SectorWrite function operation mode */
    if( (*(Fls_pConfigPtr->pSectorFlags))[Fls_u32JobSectorIt] & FLS_PAGE_WRITE_ASYNCH )
    {
        bAsynch = (boolean)TRUE;
    }
    else
    {
        bAsynch = (boolean)FALSE;
    }    

#if (FLASH_INTERLEAVED_BLOCK == STD_ON)
    /* To inform Mainfunction how to write an interleaved block - in async mode only */
    Fls_Flash_bAsyncInterleavedBlock = Fls_Flash_aSectorList0[ePhysicalSector].bInterleavedBlo;
    Fls_Flash_u32InterleavedSize = Fls_Flash_aSectorList0[ePhysicalSector].u32InterleavedSize;
#endif /* FLASH_INTERLEAVED_BLOCK == STD_ON */

    eRetVal = Fls_Flash_SectorWrite( ePhysicalSector, u32SectorOffset, u32Length, 
                                    Fls_pJobDataSrcPtr, bAsynch 
                                  ); 
    return( eRetVal );
}

#if( FLS_COMPARE_API == STD_ON )
/** 
    @brief Compare up to one physical flash sector with data buffer
    @details Call low level flash driver service to compare given
        number of bytes at given sector offset with data buffer
    
    @param[in] u32SectorOffset Flash sector offset to compare data with
    @param[in] u32Length Number of bytes to compare
    
    @return Fls_Flash_ReturnType
    @retval FLASH_E_OK compare operation succeeded
    @retval FLASH_E_FAILED compare operation failed due to a hardware error
    @retval FLASH_E_BLOCK_INCONSISTENT compare operation failed 
        due to data mismatch
    
    @pre The module must be initialized, the Fls_u32JobSectorIt internal job
        variable must contain valid index of logical sector to compare, 
        u32SectorOffset and u32Length must be in physical sector boundary, 
        Fls_pJobDataSrcPtr internal job variable must point to 
        compare data buffer

    @implements Fls_DoJobCompare_Activity
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_DoJobCompare
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
)
{
    VAR( Fls_Flash_ReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;
    VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC ) ePhysicalSector;
    
    /* Map logical sector index to physical sector ID */
    ePhysicalSector = (*(Fls_pConfigPtr->pPhysicalSector))[Fls_u32JobSectorIt];

    eRetVal = Fls_Flash_SectorCompare( ePhysicalSector, u32SectorOffset, u32Length, Fls_pJobDataSrcPtr );

    if( FLASH_E_FAILED == eRetVal )
    {
        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_COMPARE_FAILED);
        #endif
    }
    
    return( eRetVal );
}
#endif /* FLS_COMPARE_API == STD_ON */  
  
#if (FLS_BLANK_CHECK_API == STD_ON)
/** 
*   @brief          Compare up to one physical flash sector with pre-defined erased value 
*   @details        Call low level flash driver service to compare given
*                   number of bytes at given sector offset with pre-defined erased value 
*    
*   @param[in]      u32SectorOffset Flash sector offset to verify memory area has been erased
*   @param[in]      u32Length Number of bytes to verify
*    
*   @return         Fls_Flash_ReturnType
*   @retval         FLASH_E_OK blank check operation succeeded
*   @retval         FLASH_E_FAILED blank check operation failed due to a hardware error
*   @retval         FLASH_E_BLOCK_INCONSISTENT blank check operation failed 
*                   due to data mismatch
*    
*   @pre            The module must be initialized, the Fls_u32JobSectorIt internal job
*                   variable must contain valid index of logical sector to blank check, 
*                   u32SectorOffset and u32Length must be in physical sector boundary
*
*/
static FUNC( Fls_Flash_ReturnType, FLS_CODE ) Fls_DoJobBlankCheck
(
    CONST( Fls_AddressType, AUTOMATIC) u32SectorOffset,
    CONST( Fls_AddressType, AUTOMATIC) u32Length 
)
{
    VAR( Fls_Flash_ReturnType, AUTOMATIC ) eRetVal = FLASH_E_OK;
    VAR( Fls_Flash_PhysicalSectorType, AUTOMATIC ) ePhysicalSector;
    
    /* Map logical sector index to physical sector ID */
    ePhysicalSector = (*(Fls_pConfigPtr->pPhysicalSector))[Fls_u32JobSectorIt];

    eRetVal = Fls_Flash_SectorCompare( ePhysicalSector, u32SectorOffset, u32Length, NULL_PTR );

    if( FLASH_E_FAILED == eRetVal )
    {
        #if( FLS_RUNTIME_ERROR_DETECT == STD_ON )
        (void)Det_ReportRuntimeError((uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_COMPARE_FAILED);
        #endif      
    } 
    /*else
    {
         physical sector blank check succeeded or
            FLASH_E_BLOCK_INCONSISTENT 
    }*/
    
    return( eRetVal );
}
#endif /* FLS_BLANK_CHECK_API == STD_ON */

/** 
    @brief Read, write, or compare flash data
    @details Call Fls_DoJobRead, Fls_DoJobWrite, or Fls_DoJobCompare
        functions to read, write, or compare flash data. The functions
        ensures that only pre-configured maximum number of bytes is
        read, written, or compared during one cycle of 
        the Fls_MainFunction call
    
    @return MemIf_JobResultType
    @retval MEMIF_JOB_OK read, write, or compare operation succeeded and there 
        is no more data to read, write, or compare
    @retval MEMIF_JOB_PENDING read, write, or compare operation succeeded
        and there is still some data to read, write, or compare
    @retval MEMIF_JOB_FAILED read, write, or compare operation failed due
        to a hardware error
    @retval MEMIF_BLOCK_INCONSISTENT Compared data from a flash compare
        eJob are not equal
    
    @pre The module must be initialized, the Fls_u32JobSectorIt internal
        eJob variable must contain index of logical sector to read, write, 
        or compare, the Fls_u32JobAddrIt must contain logical address to read, 
        write or compare, and Fls_u32JobAddrEnd must contain last address to read,
        write or compare.

    @post Updates the Fls_u32JobSectorIt, Fls_pJobDataSrcPtr, Fls_pJobDataDestPtr,
        and Fls_u32JobAddrIt internal eJob variables
        
    @implements Fls_DoJobDataTransfer_Activity
*/
static FUNC( MemIf_JobResultType, FLS_CODE ) Fls_DoJobDataTransfer
( 
    CONST( Fls_JobType, AUTOMATIC) eJob,
    CONST( Fls_LengthType, AUTOMATIC) u32MaxTransfer 
)
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_PENDING;
    
    /* No more data to write */
    if( Fls_u32JobAddrIt > Fls_u32JobAddrEnd )
    {
        eRetVal = MEMIF_JOB_OK;
    }
    else
    {
        VAR( Fls_AddressType, AUTOMATIC ) u32MaxTransferAddrEnd = 0UL;
        VAR( Fls_Flash_ReturnType, AUTOMATIC ) eTransferRetVal = FLASH_E_FAILED;
        
        /* Last address to transfer data to/from in this call of 
            the Fls_MainFunction() functions */
        u32MaxTransferAddrEnd = Fls_CalcMaxTransferAddrEnd( u32MaxTransfer );

        /* Transfer sector by sector until the u32MaxTransferAddrEnd address is reached
            or error is detected */
        do
        {
            VAR( Fls_AddressType, AUTOMATIC ) u32SectorTransferOffset = 0UL;
            VAR( Fls_AddressType, AUTOMATIC ) u32SectorTransferLength = 0UL;

            /* Calculate offset and length of the sector data transfer */
            u32SectorTransferOffset = Fls_CalcSectorTransferOffset();
            u32SectorTransferLength = Fls_CalcSectorTransferLength( u32MaxTransferAddrEnd );

            /* Call Low-level driver to transfer data to/from
                physical flash device */
            switch( eJob )
            {
                case FLS_JOB_WRITE:
                    eTransferRetVal =  Fls_DoJobWrite( u32SectorTransferOffset,
                                                      u32SectorTransferLength 
                                                    );                        
                    /* Update the source data pointer for next write */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_pJobDataSrcPtr += u32SectorTransferLength;                    
                    break;
                    
                case FLS_JOB_READ:
                    eTransferRetVal =  Fls_DoJobRead( u32SectorTransferOffset,
                                                     u32SectorTransferLength 
                                                   );
                        
                    /* Update the destination data pointer for next read */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_pJobDataDestPtr += u32SectorTransferLength;                    
                    break;

#if( FLS_COMPARE_API == STD_ON )
                case FLS_JOB_COMPARE:
                    eTransferRetVal =  Fls_DoJobCompare( u32SectorTransferOffset,
                                                        u32SectorTransferLength 
                                                      );
                    /* Update the source data pointer for next compare */
                    /*
                    * @violates @ref fls_c_REF_10 Array indexing shall be the
                    * only allowed form of pointer arithmetic
                    */
                    Fls_pJobDataSrcPtr += u32SectorTransferLength;                                
                    break;
#endif /* FLS_COMPARE_API == STD_ON */

                case FLS_JOB_ERASE:
        /* If the case corresponds to FLS_JOB_ERASE the switch case will  break */
                    break;

#if( FLS_BLANK_CHECK_API == STD_ON )                   
                case FLS_JOB_BLANK_CHECK:
                    eTransferRetVal =  Fls_DoJobBlankCheck(  u32SectorTransferOffset,
                                                            u32SectorTransferLength 
                                                         );
                    break;
#endif /* FLS_BLANK_CHECK_API == STD_ON */
                default:
                    /* Do nothing - should not happen in Fully Trusted Environment;
                       "default" clause added to fulfill MISRA Rule 15.3 */
                    break;
            }
            
            /* Update the Fls_JobAddressIt iterator */
            Fls_u32JobAddrIt += u32SectorTransferLength;

            /* Fls_u32JobSectorIt should be increased here only for SYNC mode and for read/compare job
               For a Write Job in ASYNC mode it should be set by Fls_Flash_MainFunction just before 
               completing the Job */
            if ( (0U == ((*(Fls_pConfigPtr->pSectorFlags))[Fls_u32JobSectorIt] & FLS_PAGE_WRITE_ASYNCH))  ||    \
                   (FLS_JOB_READ == eJob )                                                  ||    \
                   (FLS_JOB_COMPARE == eJob )                                                     \
               )
            {
                if( (Fls_u32JobAddrIt > (*(Fls_pConfigPtr->pSectorEndAddr))[Fls_u32JobSectorIt]))
                {
                    /* Move on to the next sector */
                    Fls_u32JobSectorIt++;        
                }
            
            }
        }
        while(( Fls_u32JobAddrIt <= u32MaxTransferAddrEnd ) && 
              ( FLASH_E_OK == eTransferRetVal )
             );
        if( FLASH_E_FAILED == eTransferRetVal )
        {
            eRetVal = MEMIF_JOB_FAILED;
        } 
        else if( FLASH_E_BLOCK_INCONSISTENT == eTransferRetVal )
        {
            /* compare job only */
            eRetVal = MEMIF_BLOCK_INCONSISTENT;
        }     
        else if(( Fls_u32JobAddrIt > Fls_u32JobAddrEnd ) && 
                ( FLASH_E_OK == eTransferRetVal )
               )
        {
            /* All desired job data has been successfully transferred */
            eRetVal = MEMIF_JOB_OK;
        }
        else
        {
            /* The write operation is either pending (FLASH_E_PENDING) 
            in hardware in case of asynchronous operation or 
            finished (FLASH_E_OK) in case of synchronous operation 
            and there is more pages to write */
        }
    }
    
    return( eRetVal );
}

/** 
* @brief        Function to handle cumulative CRC calculation over input data.
*
* @details      Handles cumulative CRC calculation over input 32-bit data, . 
*
* @param[in]    inputData ... data to be CRC-ed
*
* @return       void
* @retval       None.
*
* @pre          Fls_ResetCRC() was executed before the first call of 
*               Fls_AccumulateCRC().
*
*    
*/
static FUNC(void, FLS_CODE) Fls_AccumulateCRC
(
  VAR(uint32, AUTOMATIC) u32InputData
)
{     

    if (0xFFFFU < u32InputData)
    {
        /* preparation for accumulation of higher 16 bits of the u32InputData */
        Fls_u32AccCRCremainder = (Fls_u32AccCRCremainder << 16U) | (u32InputData >> 16U);
        /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
        Fls_UpdateCRCreminder(FLS_CRC_16_BITS);                    
    }

    if (0xFFU < u32InputData)
    {
        /* preparation for accumulation of lower 16 bits of the u32InputData */
        Fls_u32AccCRCremainder = (Fls_u32AccCRCremainder << 16U) | (u32InputData & 0x0000FFFFU);    
        /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
        Fls_UpdateCRCreminder(FLS_CRC_16_BITS);    
    }
    else
    {
        /* optimization: only 8 LSB bits are processed */
        /* preparation for accumulation of lower 8 bits of the u32InputData */
        Fls_u32AccCRCremainder = (Fls_u32AccCRCremainder << 8U) | u32InputData;    
        /* make 16-bit accumulated result (in lower 16-bits of Fls_u32AccCRCremainder) */
        Fls_UpdateCRCreminder(FLS_CRC_8_BITS);        
    }

    return;
} 


/** 
* @brief        Function to reset CRC calculation.
*
* @details      Resets accumulated Fls_u32AccCRCremainder. 
*
* @param[in]    void
*
* @return       void
* @retval       None.
*
* @pre          None.  
*
*    
*/
static FUNC(void, FLS_CODE) Fls_ResetCRC ( void )
{
    Fls_u32AccCRCremainder = 0U;
}

/** 
* @brief        Function to finalize CRC calculation.
*
* @details      Finalizes accumulated CRC computation and resturns the final 
*               CRC checksum. 
*
* @param[in]    void
*
* @return       uint32 
* @retval       The final CRC checksum in the lower 16 bits.                
*
* @pre          Fls_AccumulateCRC() was executed at least once before 
*               calling Fls_FinalizeCRC().
*    
*/
static FUNC(uint32, FLS_CODE) Fls_FinalizeCRC ( void )
{
    /* add the final 0x0000 to the remainder */
    Fls_u32AccCRCremainder = (Fls_u32AccCRCremainder << 16U);
    /* make the final 16-bit CRC */         
    Fls_UpdateCRCreminder(FLS_CRC_16_BITS);
    
    return (Fls_u32AccCRCremainder);
}

/** 
* @brief        Function to perfom CRC calculation over input 32-bit data.
*
* @details      Process 32-bit data to 16-bit reminder. 
*
* @param[in]    accDataPtr ... ptr to data to be processed
*
* @return       void 
* @retval       None.                
*
* @pre          Can be called only from Fls_AccumulateCRC().
*    
*/

static FUNC( void, FLS_CODE ) Fls_UpdateCRCreminder 
( 
    VAR(Fls_CrcDataSizeType, AUTOMATIC) eDataSize 
)
{
    VAR(uint32, AUTOMATIC) u32CrcPolynomSft; 
    VAR(uint32, AUTOMATIC) u32LeadingOne;
    VAR(uint32, AUTOMATIC) u32AccDataLoc;
    VAR(uint32, AUTOMATIC) u32LeadingOneInitial;
    
    switch (eDataSize)
    {
        case FLS_CRC_8_BITS:
            u32CrcPolynomSft = 0x11021U << 7U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            u32LeadingOneInitial = 0x10000U << 7U;        
            break;
        case FLS_CRC_16_BITS:
        default:
            u32CrcPolynomSft = 0x11021U << 15U; /* shifted CRC-16-CCITT (x.25 protocol)*/
            u32LeadingOneInitial = 0x10000U << 15U;
            break;
    }

    /* copy static variable to auto (computation over static may be slow) */
    u32AccDataLoc = Fls_u32AccCRCremainder;
    
    /* CRC computation */
    for (u32LeadingOne = u32LeadingOneInitial; u32LeadingOne >= 0x00010000U; u32LeadingOne >>= 1U)
    {
        if (u32AccDataLoc & u32LeadingOne)
        {
            u32AccDataLoc ^= u32CrcPolynomSft;   
        }
        u32CrcPolynomSft >>= 1U;
    }
    
    /* copy back to static variable */ 
    Fls_u32AccCRCremainder = u32AccDataLoc;
    
    return;    
}

/** 
* @brief        Calculates CRC over Fls configuration.
*
* @details      Calculates CRC over selected items of Fls configuration set 
*               pointed to by ConfigPtr. 
*
* @param[in]    ConfigPtr        Pointer to flash driver configuration set.
*
* @return       uint32
* @retval       0 .. 0xFFFF (16-bit CRC using CRC-16-CCITT polynomial)
*
* @pre          Fls_pConfigPtr must not be properly initialized.
*    
*/

static FUNC( Fls_CrcType, FLS_CODE )  Fls_CalcCfgCRC( void )
{
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32SectorIndex;
    
    /* Reset the accumulated CRC value */
    Fls_ResetCRC();
    /* Iterate through the sector-dependent params */
    for( u32SectorIndex = 0U; u32SectorIndex < Fls_pConfigPtr->u32SectorCount; u32SectorIndex++ )
    {
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->pSectorFlags))[u32SectorIndex]);
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->pSectorUnlock))[u32SectorIndex]);
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->pSectorEndAddr))[u32SectorIndex]);
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->pSectorProgSize))[u32SectorIndex]);
        Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))(*(Fls_pConfigPtr->pPhysicalSector))[u32SectorIndex]);
    }
    /* Accumulate the rest of the params (common for all sectors within a config set) */
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->eDefaultMode);
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32MaxReadFastMode );
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32MaxReadNormalMode);
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32MaxWriteFastMode);
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32MaxWriteNormalMode);        
    Fls_AccumulateCRC((VAR(uint32, AUTOMATIC))Fls_pConfigPtr->u32SectorCount);
    
    return ((Fls_CrcType)Fls_FinalizeCRC());
}

/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        The function initializes Fls module.
* @details      The function sets the internal module variables according to given
*               configuration set.
*
* @param[in]    pConfigPtr        Pointer to flash driver configuration set.
*
* @api
*
* @pre          @p pConfigPtr must not be @p NULL_PTR and the module status must not
*               be @p MEMIF_BUSY.
*
* @implements     Fls_Init_Activity 
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_Init
( P2CONST( Fls_ConfigType, AUTOMATIC, FLS_APPL_CONST ) pConfigPtr )
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
#ifdef FLS_PRECOMPILE_SUPPORT
    if (NULL_PTR != pConfigPtr)
#else
    if (NULL_PTR == pConfigPtr)
#endif /* <DRIVER>_PRECOMPILE_SUPPORT */
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_PARAM_CONFIG );
    }
    else if(MEMIF_JOB_PENDING == Fls_eJobResult)
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_BUSY );
    }
    else
    {
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    
    #ifdef FLS_PRECOMPILE_SUPPORT
       Fls_pConfigPtr = &Fls_PBCfgVariantPredefined;
    #else
       Fls_pConfigPtr = pConfigPtr;
    #endif /* <DRIVER>_PRECOMPILE_SUPPORT */
        if (Fls_pConfigPtr->u16ConfigCrc != Fls_CalcCfgCRC())
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_INIT_ID, FLS_E_PARAM_CONFIG );
            Fls_pConfigPtr = NULL_PTR;
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
            Fls_eJobResult = MEMIF_JOB_FAILED;            
        }
        else        
        {
            /* Set the max number of bytes to read/write
                during Fls_MainFunction call */    
            if (MEMIF_MODE_SLOW == Fls_pConfigPtr->eDefaultMode)
            {
                Fls_u32MaxRead = Fls_pConfigPtr->u32MaxReadNormalMode;
                Fls_u32MaxWrite = Fls_pConfigPtr->u32MaxWriteNormalMode;
            }
            else
            {
                Fls_u32MaxRead = Fls_pConfigPtr->u32MaxReadFastMode;
                Fls_u32MaxWrite = Fls_pConfigPtr->u32MaxWriteFastMode;
            }
            /* Initialize flash hardware 
               NOTE: The variable 'Fls_Flash_eJobResult' will be updated in the below function*/
            Fls_Flash_Init();
            
            if(  MEMIF_JOB_FAILED == Fls_Flash_eJobResult )
            {
                Fls_eJobResult = MEMIF_JOB_FAILED;
            #if( FLS_DEV_ERROR_DETECT == STD_ON )
                Fls_pConfigPtr = NULL_PTR; 
            #endif
            }
            else
            {
                Fls_eJobResult = MEMIF_JOB_OK;
            }
        }
    #if(FLS_DEV_ERROR_DETECT == STD_ON)
    }
    #endif
}

/**
* @brief            Erase one or more complete flash sectors.
* @details          Starts an erase job asynchronously. The actual job is performed
 *                  by the @p Fls_MainFunction.
*
* @param[in]        TargetAddress        Target address in flash memory.
* @param[in]        Length               Number of bytes to erase.
*
* @return           Std_ReturnType
* @retval           E_OK                    Erase command has been accepted.
* @retval           E_NOT_OK                Erase command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post             @p Fls_Erase changes module status and some internal variables 
*                   (@p Fls_u32JobSectorIt, @p Fls_u32JobSectorEnd, @p Fls_Job,
*                   @p Fls_eJobResult).
*
* @implements       Fls_Erase_Activity
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Erase
( 
    VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress,
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorEnd = 0UL;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( (boolean)FALSE == (Fls_IsAddrSectorStartAligned( (Fls_AddressType)u32TargetAddress )) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(( 0U == u32Length ) || ( (boolean)FALSE == (Fls_IsAddrSectorEndAligned(( (Fls_AddressType)u32TargetAddress + u32Length ) - 1U ))) )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32TargetAddress );
        u32TmpJobSectorEnd = Fls_GetSectorIndexByAddr(( u32TargetAddress + u32Length ) - 1U );

        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_10();
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_ERASE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10();
        }    
        else
        {
            /* Configure the erase job */
            Fls_u32JobSectorIt = u32TmpJobSectorIt;
            Fls_u32JobSectorEnd = u32TmpJobSectorEnd;
            Fls_eJob = FLS_JOB_ERASE;
            Fls_u8JobStart = 1U;
            
            /* Execute the erase job */
            Fls_eJobResult = MEMIF_JOB_PENDING;
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_10();
            
            #if( FLS_USE_INTERRUPTS == STD_ON )         
            /* Enable job processing using interrupts. Also, first round of the erase job will be started here. */
            Fls_EnableInterruptProccessing();
            #endif /* FLS_USE_INTERRUPTS == STD_ON */
        }
    }
    
    return( u8RetVal );
}


/**
* @brief            Write one or more complete flash pages to the flash device.
* @details          Starts a write job asynchronously. The actual job is performed by
*                   @p Fls_MainFunction.
*
* @param[in]        TargetAddress        Target address in flash memory.
* @param[in]        SourceAddressPtr     Pointer to source data buffer.
* @param[in]        Length               Number of bytes to write.
*
* @return           Std_ReturnType
* @retval           E_OK                 Write command has been accepted.
* @retval           E_NOT_OK             Write command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post             @p Fls_Write changes module status and some internal variables 
 *                  (@p Fls_u32JobSectorIt, @p Fls_u32JobAddrIt, @p Fls_u32JobAddrEnd,
 *                  @p Fls_pJobDataSrcPtr, @p Fls_eJob, @p Fls_eJobResult).
*
* @implements       Fls_Write_Activity
*
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Write
(
    VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress, 
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) pSourceAddressPtr,
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32TmpJobAddrEnd = 0UL;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;        
    }
    else if( (boolean)FALSE == (Fls_IsAddrPageStartAligned( (Fls_AddressType)u32TargetAddress )))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if(( 0U == u32Length ) || ( (boolean)FALSE == (Fls_IsLengthAligned( (Fls_AddressType)u32TargetAddress, u32Length ) )))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pSourceAddressPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_PARAM_DATA );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr(u32TargetAddress);
        u32TmpJobAddrEnd = ( u32TargetAddress + u32Length ) - 1U;
            
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_11();
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_WRITE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11();
        }
        else
        {
            /* Configure the write job */
            Fls_u32JobSectorIt = u32TmpJobSectorIt;
            Fls_u32JobAddrEnd = u32TmpJobAddrEnd;
            Fls_u32JobAddrIt = u32TargetAddress;
            Fls_pJobDataSrcPtr = pSourceAddressPtr;
            Fls_eJob = FLS_JOB_WRITE;
            Fls_u8JobStart = 1U;
            
            /* Execute the write job */
            Fls_eJobResult = MEMIF_JOB_PENDING;
            
            SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_11();
            
            #if( FLS_USE_INTERRUPTS == STD_ON )         
            /* Enable job processing using interrupts. Also, first round of the write job will be started here. */
            Fls_EnableInterruptProccessing();
            #endif /* FLS_USE_INTERRUPTS == STD_ON */
        }
    } 
    
    return( u8RetVal );
}


#if ( FLS_CANCEL_API == STD_ON ) || defined(__DOXYGEN__)
/**
* @brief            Cancel an ongoing flash read, write, erase or compare job.
* @details          Abort a running job synchronously so that directly after returning
*                   from this function a new job can be started.
*
* @api
*
* @pre              The module must be initialized.
* @post             @p Fls_Cancel changes module status and @p Fls_eJobResult
*                   internal variable.
*
* @implements       Fls_Cancel_Activity 
*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_Cancel( void )
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_CANCEL_ID, FLS_E_UNINIT );
    }
    else
    {
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */

        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
            #if( FLS_USE_INTERRUPTS == STD_ON )         
            /* Disable job processing using interrupts. */
            Fls_DisableInterruptProccessing();
            #endif /* FLS_USE_INTERRUPTS == STD_ON */
        
            /* Cancel ongoing hardware job */
            Fls_Flash_Cancel();

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
            if(( FLS_JOB_ERASE == Fls_eJob ) || ( FLS_JOB_WRITE == Fls_eJob ))
            {
                Fls_UnloadAc( Fls_eJob );
            }
            else
            {
                /* The FLS_JOB_READ and FLS_JOB_COMPARE jobs don't use the access code */
            }
#endif 
            /* If underlying hardware job was successfully canceled */
            if(MEMIF_JOB_CANCELED == Fls_Flash_eJobResult)
            {
                /* Update global job result status */
                Fls_eJobResult = MEMIF_JOB_CANCELED;
            }            

            if( NULL_PTR != Fls_pConfigPtr->jobErrorNotificationPtr )
            {
                /* Call FlsJobErrorNotification function if configured */
                Fls_pConfigPtr->jobErrorNotificationPtr();
            }
            else
            {
                /* Callback notification configured as null pointer */            
            }        
        }
        else
        {
            /* Leave the job result unchanged */
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    }
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif    /* FLS_CANCEL_API == STD_ON */


#if(( FLS_GET_STATUS_API == STD_ON ) || defined (__DOXYGEN__))
/**
* @brief            Returns the FLS module status.
* @details          Returns the FLS module status synchronously.
*
* @return           MemIf_StatusType
* @retval           MEMIF_UNINIT        Module has not been initialized (yet).
* @retval           MEMIF_IDLE          Module is currently idle.
* @retval           MEMIF_BUSY          Module is currently busy.
*
* @api
*
* @implements       Fls_GetStatus_Activity
*                   
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_StatusType, FLS_CODE ) Fls_GetStatus( void )
{
    VAR( MemIf_StatusType, AUTOMATIC ) eRetVal = MEMIF_IDLE;

    if( NULL_PTR == Fls_pConfigPtr )
    {
        eRetVal = MEMIF_UNINIT;
    } 
    else if( MEMIF_JOB_PENDING == Fls_eJobResult )
    {
        eRetVal = MEMIF_BUSY;
    }
    else
    {
        eRetVal = MEMIF_IDLE;
    }

    return( eRetVal );
}
#endif    /* FLS_GET_STATUS_API == STD_ON */


#if ( FLS_GET_JOB_RESULT_API == STD_ON )||  defined (__DOXYGEN__)/**
* @brief            Returns the result of the last job.
* @details          Returns synchronously the result of the last job.
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.
*
* @api
*
* @implements       Fls_GetJobResult_Activity
*                   
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( MemIf_JobResultType, FLS_CODE ) Fls_GetJobResult( void )
{
    VAR( MemIf_JobResultType, AUTOMATIC ) eRetVal = MEMIF_JOB_OK;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GETJOBRESULT_ID, FLS_E_UNINIT );
        eRetVal = (MemIf_JobResultType)MEMIF_JOB_FAILED;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        eRetVal = Fls_eJobResult;
    } 
    return( eRetVal );
}
#endif    /* FLS_GET_JOB_RESULT_API == STD_ON */


/**
* @brief            Reads from flash memory.
* @details          Starts a read job asynchronously. The actual job is performed by
*                   @p Fls_MainFunction.
*
* @param[in]        SourceAddress        Source address in flash memory.
* @param[in]        Length               Number of bytes to read.
* @param[out]       TargetAddressPtr    Pointer to target data buffer.
*
* @return           MemIf_JobResultType
* @retval           MEMIF_JOB_OK              Successfully completed job.
* @retval           MEMIF_JOB_FAILED          Not successfully completed job.
* @retval           MEMIF_JOB_PENDING         Still pending job (not yet completed).
* @retval           MEMIF_JOB_CANCELED        Job has been canceled.
* @retval           MEMIF_BLOCK_INCONSISTENT  Inconsistent block requested, it may
*                                             contains corrupted data.
* @retval           MEMIF_BLOCK_INVALID       Invalid block requested.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_Read changes module status and some internal variables 
*                 (@p Fls_u32JobSectorIt, @p Fls_u32JobAddrIt, @p Fls_u32JobAddrEnd,
*                 @p Fls_pJobDataDestPtr, @p Fls_eJob, @p Fls_eJobResult).
*
* @implements       Fls_Read_Activity
*                   
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Read
( 
    VAR( Fls_AddressType, AUTOMATIC) u32SourceAddress, 
    P2VAR( uint8, AUTOMATIC, FLS_APPL_DATA ) pTargetAddressPtr,    
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32TmpJobAddrEnd = 0UL;
    
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }    
    else if( u32SourceAddress >= FLS_TOTAL_SIZE )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(( 0U == u32Length ) || ((u32SourceAddress + u32Length) > FLS_TOTAL_SIZE ))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pTargetAddressPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_PARAM_DATA );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32SourceAddress );
        u32TmpJobAddrEnd = ( u32SourceAddress + u32Length ) - 1U;
        
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_12();
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_READ_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }    
        else
        {
            /* Configure the read job */
            Fls_u32JobSectorIt = u32TmpJobSectorIt;
            Fls_u32JobAddrIt = u32SourceAddress;
            Fls_u32JobAddrEnd = u32TmpJobAddrEnd;
            Fls_pJobDataDestPtr = pTargetAddressPtr;
            Fls_eJob = FLS_JOB_READ;
            
            Fls_u8JobStart = 1U;

            /* Execute the read job */
            Fls_eJobResult = MEMIF_JOB_PENDING;

        }       
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_12();
    }
    
    return( u8RetVal );
}


#if( FLS_COMPARE_API == STD_ON ) || defined(__DOXYGEN__)
/**
* @brief           Compares a flash memory area with an application data buffer.
* @details         Starts a compare job asynchronously. The actual job is performed by
*                  @p Fls_MainFunction.
*
* @param[in]        SourceAddress          Source address in flash memory.
* @param[in]        TargetAddressPtr       Pointer to source data buffer.
* @param[in]        Length                 Number of bytes to compare.
*
* @return           Std_ReturnType
* @retval           E_OK                      Compare command has been accepted.
* @retval           E_NOT_OK                   Compare command has not been accepted.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_Read changes module status and some internal variables 
 *                (@p Fls_u32JobSectorIt, @p Fls_u32JobAddrIt, @p Fls_u32JobAddrEnd,
 *                @p Fls_pJobDataSrcPtr, @p Fls_eJob, @p Fls_eJobResult).
*
* @implements       Fls_Compare_Activity
*                   
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_Compare
(
    VAR( Fls_AddressType, AUTOMATIC) u32SourceAddress, 
    P2CONST( uint8, AUTOMATIC, FLS_APPL_CONST ) pTargetAddressPtr, 
    VAR( Fls_LengthType, AUTOMATIC) u32Length 
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32TmpJobAddrEnd = 0UL;

#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( u32SourceAddress >= FLS_TOTAL_SIZE )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(( 0U == u32Length ) || ((u32SourceAddress + u32Length) > FLS_TOTAL_SIZE ))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( NULL_PTR == pTargetAddressPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_PARAM_DATA );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {

        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32SourceAddress );
        u32TmpJobAddrEnd = ( u32SourceAddress + u32Length ) - 1U;
   
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_13();    
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_COMPARE_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */            
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_u32JobSectorIt = u32TmpJobSectorIt;
            Fls_u32JobAddrIt = u32SourceAddress;
            Fls_u32JobAddrEnd = u32TmpJobAddrEnd;
            Fls_pJobDataSrcPtr = pTargetAddressPtr;
            Fls_eJob = FLS_JOB_COMPARE;
            Fls_u8JobStart = 1U;

            /* Execute the read job */
            Fls_eJobResult = MEMIF_JOB_PENDING;

        }       
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_13();
    }
    
    return( u8RetVal );
}
#endif /* FLS_COMPARE_API == STD_ON */

#if (FLS_BLANK_CHECK_API == STD_ON)
/**
* @brief           Verify whether a given memory area has been erased but not (yet) programmed.
* @details         Starts a compare job asynchronously. The actual job is performed by
*                  @p Fls_MainFunction.                  
*
* @param[in]        TargetAddress          Address in flash memory from which the blank check should be started.
* @param[in]        Length                 Number of bytes to be checked for erase pattern.
*
* @return           Std_ReturnType
* @retval           E_OK                   Blank checking command has been accepted.
* @retval           E_NOT_OK               Blank checking command has not been accepted.
*
* @api
*
* @pre              The module has to be initialized and not busy.
* @post             @p Fls_Read changes module status and some internal variables 
*                   (@p Fls_u32JobSectorIt, @p Fls_u32JobAddrIt, @p Fls_u32JobAddrEnd,
*                   @p Fls_pJobDataSrcPtr, @p Fls_eJob, @p Fls_eJobResult).
*
* @implements       Fls_BlankCheck_Activity
*                   
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( Std_ReturnType, FLS_CODE ) Fls_BlankCheck
(
    VAR( Fls_AddressType, AUTOMATIC) u32TargetAddress,
    VAR( Fls_LengthType, AUTOMATIC) u32Length
)
{
    VAR( Std_ReturnType, AUTOMATIC ) u8RetVal = (Std_ReturnType)E_OK;
    VAR( Fls_SectorIndexType, AUTOMATIC ) u32TmpJobSectorIt = 0UL;
    VAR( Fls_AddressType, AUTOMATIC ) u32TmpJobAddrEnd = 0UL;
    
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_UNINIT );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else if( u32TargetAddress >= FLS_TOTAL_SIZE )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_PARAM_ADDRESS );
        u8RetVal = (Std_ReturnType)E_NOT_OK;    
    }
    else if(( 0U == u32Length ) || ((u32TargetAddress + u32Length) > FLS_TOTAL_SIZE ))
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_PARAM_LENGTH );
        u8RetVal = (Std_ReturnType)E_NOT_OK;
    }
    else
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
    {
        /* Perform calculations outside the critical section in order
            to limit time spend in the CS */
        u32TmpJobSectorIt = Fls_GetSectorIndexByAddr( u32TargetAddress );
        u32TmpJobAddrEnd = ( u32TargetAddress + u32Length ) - 1U;
        
        SchM_Enter_Fls_FLS_EXCLUSIVE_AREA_14(); 
        
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
#if( FLS_DEV_ERROR_DETECT == STD_ON )
            (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_BLANK_CHECK_ID, FLS_E_BUSY );
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */               
            u8RetVal = (Std_ReturnType)E_NOT_OK;
        }
        else
        {
            Fls_u32JobSectorIt = u32TmpJobSectorIt;               
            Fls_u32JobAddrIt = u32TargetAddress;               
            Fls_u32JobAddrEnd = u32TmpJobAddrEnd;         
            Fls_eJob = FLS_JOB_BLANK_CHECK;
            Fls_u8JobStart = 1U;

            /* Execute the read job */
            Fls_eJobResult = MEMIF_JOB_PENDING;
        }       
        SchM_Exit_Fls_FLS_EXCLUSIVE_AREA_14();        
    }
    
    return( u8RetVal );
}
#endif /* FLS_BLANK_CHECK_API == STD_ON */

#if( FLS_SET_MODE_API == STD_ON )|| defined (__DOXYGEN__)
/**
* @brief           Sets the FLS module's operation mode to the given Mode.
* @details         Every given mode determinates maximum bytes for read-write
 *                 operations. Every mode has a set of pre-configured values.
*
* @param[in]        Mode        MEMIF_MODE_FAST or MEMIF_MODE_SLOW.
*
* @api
*
* @pre            The module has to be initialized and not busy.
* @post           @p Fls_SetMode changes internal variables @p Fls_u32MaxRead and
*                 @p Fls_u32MaxWrite.
*
* @implements       Fls_SetMode_Activity
*                   
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_SetMode
(
    VAR( MemIf_ModeType, AUTOMATIC ) eMode 
)
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SETMODE_ID, FLS_E_UNINIT );
    }
    else if( MEMIF_JOB_PENDING == Fls_eJobResult )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_SETMODE_ID, FLS_E_BUSY );
    }
    else
    {
#endif  /* FLS_DEV_ERROR_DETECT == STD_ON */
        /* Set the max number of bytes to read/write
            during Fls_MainFunction call */
        switch( eMode ) 
        {
            case MEMIF_MODE_FAST:
                Fls_u32MaxRead = Fls_pConfigPtr->u32MaxReadFastMode;
                Fls_u32MaxWrite = Fls_pConfigPtr->u32MaxWriteFastMode;    
                break;
                
            case MEMIF_MODE_SLOW:
                Fls_u32MaxRead = Fls_pConfigPtr->u32MaxReadNormalMode;
                Fls_u32MaxWrite = Fls_pConfigPtr->u32MaxWriteNormalMode;
                break;
                
            default:
                /* Do nothing - should not happen in Fully Trusted Environment;
                   'default' clause added to fulfill MISRA Rule 15.3 */
                break;
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )        
    }
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FLS_SET_MODE_API == STD_ON */

#if( FLS_VERSION_INFO_API == STD_ON )|| defined(__DOXYGEN__)
/**
* @brief        Returns version information about FLS module.
* @details      Version information includes:
*               - Module Id
*               - Vendor Id
*               - Vendor specific version numbers (BSW00407).
*
* @param[in,out] pVersionInfoPtr  Pointer to where to store the version information of this module.
*
* @api
*
* @implements       Fls_GetVersionInfo_Activity
*                   
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_GetVersionInfo
(
    P2VAR( Std_VersionInfoType, AUTOMATIC, FLS_APPL_DATA ) pVersionInfoPtr 
)
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == pVersionInfoPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_GETVERSIONINFO_ID, FLS_E_PARAM_POINTER );
    }
    else
    {
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        pVersionInfoPtr->moduleID = (uint16)FLS_MODULE_ID;
        pVersionInfoPtr->vendorID = (uint16)FLS_VENDOR_ID;
        pVersionInfoPtr->sw_major_version = (uint8)FLS_SW_MAJOR_VERSION;
        pVersionInfoPtr->sw_minor_version = (uint8)FLS_SW_MINOR_VERSION;
        pVersionInfoPtr->sw_patch_version = (uint8)FLS_SW_PATCH_VERSION;
#if( FLS_DEV_ERROR_DETECT == STD_ON )        
    }
#endif /* FLS_DEV_ERROR_DETECT == STD_ON */
}
#endif /* FLS_VERSION_INFO_API == STD_ON */

#if( FLS_USE_INTERRUPTS == STD_ON )
/**
* @brief        Enables job processing using interrupts.     
* @details      Calls IP function to enables command complete interrupt, which fires when CCIF == 1 (memory controller is idle).
*               The command complete interrupt is enabled at the start of a new write/erase job(in Fls_Write/Fls_Erase functions). 
*               The command complete interrupt is disabled at the end of a write/erase job(inside the IRQ hanfler)
*               or when a job is canceled(in Fls_Cancel function).
*
* @param[in]    none
* @param[out]   none
*
* @api
*
* @implements       
*                   
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
static FUNC(void, FLS_CODE) Fls_EnableInterruptProccessing ( void )
{
    /* Enable Command Complete interrupt */
    Fls_Flash_EnCmdCompleteInterrupt();
}

/**
* @brief        Disables job processing using interrupts.     
* @details      Calls IP function to disable command complete interrupt, which fires when CCIF == 1 (memory controller is idle).
*               The command complete interrupt is enabled at the start of a new write/erase job(in Fls_Write/Fls_Erase functions). 
*               The command complete interrupt is disabled at the end of a write/erase job(inside the IRQ hanfler)
*               or when a job is canceled(in Fls_Cancel function).
*
* @param[in]    none
* @param[out]   none
*
* @api
*
* @implements       
*                   
*/
#if ( FLS_CANCEL_API == STD_ON )
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
static FUNC(void, FLS_CODE) Fls_DisableInterruptProccessing ( void )
{
    /* Disable Command Complete interrupt */
    Fls_Flash_DisCmdCompleteInterrupt();
}
#endif /* FLS_CANCEL_API == STD_ON */
#endif /* FLS_USE_INTERRUPTS == STD_ON */

/**
* @brief            Performs actual flash read, write, erase and compare jobs.
* @details          Bytes number processed per cycle depends by job type (erase, write, read, compare)
*                   current FLS module's operating mode (normal, fast)
*                   and write, erase Mode of Execution (sync, async).
*
* @api
*
* @pre              The module has to be initialized.
*
*
* @implements       Fls_MainFunction_Activity
*                   
* @note             This function have to be called ciclically by the Basic Software Module; 
*                   it will do nothing if there aren't pending job.
*/
/*
* @violates @ref fls_c_REF_11 All declarations and definitions
* of objects or functions at file scope shall have internal linkage unless external linkage required
*/
FUNC( void, FLS_CODE ) Fls_MainFunction( void )
{
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    if( NULL_PTR == Fls_pConfigPtr )
    {
        (void) Det_ReportError( (uint16)FLS_MODULE_ID, FLS_INSTANCE_ID, FLS_MAINFUNCTION_ID, FLS_E_UNINIT );
    }
    else
    { 
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
        if( MEMIF_JOB_PENDING == Fls_eJobResult )
        {
            VAR(MemIf_JobResultType, AUTOMATIC) eWorkResult = MEMIF_JOB_OK;

            if( 1U == Fls_u8JobStart )
            {            
                Fls_u8JobStart = 0U;
                Fls_Flash_AbortSuspended();
#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
                /* Load position independent access code */
                if(( FLS_JOB_ERASE == Fls_eJob ) || ( FLS_JOB_WRITE == Fls_eJob ))
                {
                    Fls_LoadAc( Fls_eJob );
                }
                else
                {
                    /* Fls_Job != FLS_JOB_ERASE &&  Fls_Job != FLS_JOB_WRITE */
                }
#endif /* FLS_AC_LOAD_ON_JOB_START == STD_ON */
                
                /* Clear result of hardware job */
                Fls_Flash_ClrJobResult();
            }
            else
            {
                /* Fls_u8JobStart != 1U */
            }
                        
            if(( FLS_JOB_ERASE == Fls_eJob ) || ( FLS_JOB_WRITE == Fls_eJob ))
            {
                /* Process ongoing erase or write asynchronous hardware job */
                Fls_Flash_MainFunction();
        
                /* Get status/result of ongoing erase or write asynchronous 
                    hardware job */
                eWorkResult = Fls_Flash_GetJobResult();
            }
            else
            {
                /* FLS_JOB_READ and FLS_JOB_COMPARE jobs are
                    always synchronous */
                                /* FLS_JOB_BLANK_CHECK job is
                    always synchronous */
                                
            }

            if( MEMIF_JOB_OK == eWorkResult )
            {
                switch( Fls_eJob )
                {
                    case FLS_JOB_ERASE:
                            eWorkResult = Fls_DoJobErase();
                        break;
                    case FLS_JOB_WRITE:
                            eWorkResult = Fls_DoJobDataTransfer( Fls_eJob, Fls_u32MaxWrite );
                        break;
#if( FLS_BLANK_CHECK_API == STD_ON )                    
                    case FLS_JOB_BLANK_CHECK:
    /* For Blank Check job, the static function Fls_DoJobDataTransfer( ) 
                will be used with the same input parameters */
#endif /* FLS_BLANK_CHECK_API == STD_ON */                
                    case FLS_JOB_READ:
    /* For Read and Compare jobs the static function Fls_DoJobDataTransfer( ) 
                will be used with the same input parameters */
#if( FLS_COMPARE_API == STD_ON )                
                    case FLS_JOB_COMPARE:
#endif /* FLS_COMPARE_API == STD_ON */        
                            eWorkResult = Fls_DoJobDataTransfer( Fls_eJob, Fls_u32MaxRead );
                        break;
                    default:
                        /* Do nothing - should not happen in Fully Trusted Environment;
                           'default' clause added to fulfill MISRA Rule 15.3 */
                        break;
                }
            }
            else
            {
                /* eWorkResult != MEMIF_JOB_OK */
            }

#if( FLS_AC_LOAD_ON_JOB_START == STD_ON )
            if(( MEMIF_JOB_PENDING != eWorkResult ) &&
               (( FLS_JOB_ERASE == Fls_eJob ) || ( FLS_JOB_WRITE == Fls_eJob ))
              )
            {
                Fls_UnloadAc( Fls_eJob );
            }
#endif

            Fls_eJobResult = eWorkResult;

            if( MEMIF_JOB_OK == eWorkResult )
            {
                if( NULL_PTR != Fls_pConfigPtr->jobEndNotificationPtr )
                {
                    /* Call FlsJobEndNotification function if configured */
                    Fls_pConfigPtr->jobEndNotificationPtr();
                }
                else
                {
                    /* Callback notification configured as null pointer */
                }
            }
            else if(( MEMIF_JOB_FAILED == eWorkResult ) ||
                    ( MEMIF_BLOCK_INCONSISTENT == eWorkResult )
                   )
            {
                if( NULL_PTR != Fls_pConfigPtr->jobErrorNotificationPtr )
                {
                    /* Call FlsJobErrorNotification function if configured */
                    Fls_pConfigPtr->jobErrorNotificationPtr();
                }
                else
                {
                    /* Callback notification configured as null pointer */            
                }
            }
            else
            {
                /* Compiler_Warning: else clause added to fulfil the MISRA rule 14.10 */
                /* Not done yet. There is more data to transfer in following 
                    Fls_MainFunction call */
            }
        }
        else
        {
            /* Nothing to do since no job is pending */
        }
#if( FLS_DEV_ERROR_DETECT == STD_ON )
    }    
#endif    /* FLS_DEV_ERROR_DETECT == STD_ON */
}

#define FLS_STOP_SEC_CODE
/* 
* @violates @ref fls_c_REF_1 Precautions shall be taken 
* in order to prevent the contents of a header being included twice. 
* @violates @ref fls_c_REF_9 Only preprocessor statements
* and comments before '#include'
*/
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @}*/
/*Compiler_Warning: explicit cast discards volatile qualifier.
   The cast is explicit, intended and the casted value is treated properly. 
   Compiler wrongfully reports the warnings at the last line of the file. 
*/
