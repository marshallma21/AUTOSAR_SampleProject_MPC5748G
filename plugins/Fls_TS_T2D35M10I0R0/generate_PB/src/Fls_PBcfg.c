[!CODE!][!//
/**
*   @file    Fls_PBcfg.c
*   @implements Fls_PBcfg.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all post-build configuration structures.
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
* @section fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, Only preprocessor statements and comments before 
* '#include'
* Because of Autosar requirement MEMMAP003 of memory mapping.
* 
* @section fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_2
* Violates MISRA 2004 Required Rule 11.1, Conversions involing function pointers must be to/from integral types.
* This violation is due to FLS213.
* 
* @section fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_3
* Violates MISRA 2004 Advisory Rule 11.4, Cast from pointer to pointer.
* This violation is due to FLS213.
* 
* @section fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4
* Violates MISRA 2004 Required Rule 8.8, Object/function previously declared.
* The rule 8.8 requires that 'An external object or function shall be declared in one and only one file'.
* This requirement is fulfilled since the function is declared as external in and only in one configuration 
* C file (Fls_Cfg.c or Fls_PBcfg.c). There is no need to put the declaration into Fls_Cfg.h and made it 
* accessible for all modules which includes Fls.h/Fls_Cfg.h.
* 
* @section fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Could be made static.  
* Making FlsConfigSet_0 static would make it unaccessible to the application.
*
* @section fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_6
* Violates MISRA 2004 Required Rule 20.2, Re-use of C90 identifier pattern.
* This is just a matter of a symbol specified in the configuration.
* 
* @section fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_7
* Violates MISRA 2004 Required Rule 8.8,
* An external object or function shall be declared in one and only one file.
* Possible MISRA error if the same callback function or variable name is used in multiple configuration variants. 
* Callback function/variable name is set by the driver user so this cannot be fixed by updating the driver code.*
*
* @section fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and
* an integral type.
* This violation is due to FLS213.
* 
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 character significance and case sensitivity are supported for external identifiers
* This violation is due to the requirement that requests to have a file version check.
*
* @section [global]
* Violates MISRA 2004 Required Rule 19.15, Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*  
*/

[!INDENT "0"!][!//
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Fls.h"
[!ENDINDENT!][!//
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_VENDOR_ID_CFG_C                      43
#define FLS_AR_RELEASE_MAJOR_VERSION_CFG_C       4
#define FLS_AR_RELEASE_MINOR_VERSION_CFG_C       2
#define FLS_AR_RELEASE_REVISION_VERSION_CFG_C    2
#define FLS_SW_MAJOR_VERSION_CFG_C               1
#define FLS_SW_MINOR_VERSION_CFG_C               0
#define FLS_SW_PATCH_VERSION_CFG_C               0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fls header file are of the same vendor */
#if (FLS_VENDOR_ID_CFG_C != FLS_VENDOR_ID)
    #error "Fls_PBcfg.c and Fls.h have different vendor ids"
#endif
/* Check if current file and Fls header file are of the same Autosar version */
#if ((FLS_AR_RELEASE_MAJOR_VERSION_CFG_C    != FLS_AR_RELEASE_MAJOR_VERSION) || \
     (FLS_AR_RELEASE_MINOR_VERSION_CFG_C    != FLS_AR_RELEASE_MINOR_VERSION) || \
     (FLS_AR_RELEASE_REVISION_VERSION_CFG_C != FLS_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif
/* Check if current file and Fls header file are of the same Software version */
#if ((FLS_SW_MAJOR_VERSION_CFG_C != FLS_SW_MAJOR_VERSION) || \
     (FLS_SW_MINOR_VERSION_CFG_C != FLS_SW_MINOR_VERSION) || \
     (FLS_SW_PATCH_VERSION_CFG_C != FLS_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_PBcfg.c and Fls.h are different"
#endif

[!INCLUDE "Fls_VersionCheck.m"!][!//

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/
[!NOCODE!][!//
[!VAR "FlsIndex0" = "0"!][!//
[!VAR "FlsIndex1" = "0"!][!//
[!VAR "FlsIndex2" = "0"!][!//
[!VAR "FlsIndex3" = "0"!][!//
[!VAR "FlsIndex4" = "0"!][!//

[!LOOP "FlsConfigSet"!][!//
    [!IF "node:exists(FlsJobEndNotification)"!][!//
        [!VAR "FlsIndex0" = "1"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(FlsJobErrorNotification)"!][!//
        [!VAR "FlsIndex1" = "1"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(FlsACCallback)"!][!//
        [!VAR "FlsIndex2" = "1"!][!//
    [!ENDIF!][!//
 [!IF "node:exists(FlsStartFlashAccessNotif)"!][!//
        [!VAR "FlsIndex3" = "1"!][!//
    [!ENDIF!][!//
    [!IF "node:exists(FlsFinishedFlashAccessNotif)"!][!//
        [!VAR "FlsIndex4" = "1"!][!//
    [!ENDIF!][!//
[!ENDLOOP!][!//

[!ENDNOCODE!][!//
[!IF "$FlsIndex0 = '1.0' or $FlsIndex1 = '1.0' or $FlsIndex2 = '1.0' or $FlsIndex3 = '1.0' or $FlsIndex4 = '1.0'"!][!//
    [!INDENT "0"!]
    
    #define FLS_START_SEC_CODE
    /* 
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    
    [!LOOP "text:order(text:split(normalize-space(text:join(FlsConfigSet/FlsJobEndNotification | FlsConfigSet/FlsJobErrorNotification | FlsConfigSet/FlsACCallback | FlsConfigSet/FlsStartFlashAccessNotif | FlsConfigSet/FlsFinishedFlashAccessNotif))))"!][!//

    /* Declaration of Fls notification function ([!"."!]())*/
    /*
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_7 An external object or function shall be declared in one and only one file.
    */
    extern FUNC( void, FLS_CODE ) [!"."!]( void );
    
    [!ENDLOOP!][!//
    #define FLS_STOP_SEC_CODE
    /* 
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    [!ENDINDENT!][!//
[!ENDIF!][!//
[!INDENT "0"!][!//
[!IF "FlsGeneral/FlsAcLoadOnJobStart != 'true'"!][!//
    #define FLS_START_SEC_CODE_AC
    /* 
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    
#ifdef _LINARO_C_MPC574XG_ 
    #if (FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON)
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort ) __attribute__ ((section (".acfls_code_rom")));
        #else
            /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    #else   /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_OFF */
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC ) __attribute__ ((section (".acfls_code_rom")));
        #else
            /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) ) __attribute__ ((section (".acfls_code_rom")));
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    #endif  /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON */
#else
    #if (FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON)
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode(CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort );
        #else
            /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    #else   /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_OFF */
        #if (FLS_TIMEOUT_HANDLING == STD_ON)
            /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode(CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ), P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC );
        #else
            /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_4 Object/function previously declared */
            extern void Fls_Flash_AccessCode( CONST(uint32, AUTOMATIC) u32RegBaseAddr, P2FUNC(void, FLS_CODE, CallBack)( void ) );
        #endif /* FLS_TIMEOUT_HANDLING == STD_ON */
    #endif  /* FLS_HW_OPERATION_ABORT_SUPPORTED == STD_ON */
#endif /* #ifdef _LINARO_C_MPC574XG_ */
    
    #define FLS_STOP_SEC_CODE_AC
    /* 
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"

[!ENDIF!][!//
[!ENDINDENT!][!//
/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/
[!IF "FlsGeneral/FlsAcLoadOnJobStart = 'true'"!][!//
 
    [!IF "count(text:grep(FlsConfigSet/FlsAcErasePointer | FlsConfigSet/FlsAcWritePointer, '^(\s*NULL_PTR\s*)|(\s*NULL\s*)$')) != count(FlsConfigSet) * 2"!][!//

        [!INDENT "0"!]
        #define FLS_START_SEC_CODE
        /* 
        * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
        * and comments before '#include'
        */
        #include "Fls_MemMap.h"
          
        [!LOOP "text:order(text:split(normalize-space(text:join(FlsConfigSet/FlsAcErasePointer | FlsConfigSet/FlsAcWritePointer))))"!][!//            
            [!IF ". != 'NULL_PTR' and . != 'NULL'"!][!//
                /* Declaration of Fls Access Code Pointer ([!"."!])*/
                /*
                 * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_6 Re-use of C90 identifier pattern 
                 * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_7 An external object or function shall be declared in one and only one file.
                 */
                extern uint8 [!"."!];
            
            [!ENDIF!][!//
        [!ENDLOOP!][!//
        #define FLS_STOP_SEC_CODE
        /* 
        * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
        * and comments before '#include'
        */
        #include "Fls_MemMap.h"
        [!ENDINDENT!][!//
    [!ENDIF!][!//

[!ENDIF!][!//

[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('FLS_CFG_GENERIC_MACROS_M4'))"!][!//
    [!VAR "FLS_CFG_GENERIC_MACROS_M4"="'true'"!][!//
    [!MACRO "FlsAccCrc","FlsData32"!][!//
    [!NOCODE!][!//
    [!IF "65535 < $FlsData32"!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,16),bit:shr($FlsData32,16))"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ENDIF!][!//
    [!IF "255 < $FlsData32"!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,16),bit:and($FlsData32,65535))"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ELSE!][!//
        [!VAR "FlsCrcReminder" = "bit:or(bit:shl($FlsCrcReminder,8),bit:and($FlsData32,255))"!][!//
        [!CALL "FlsCalcCrcRemainder8bit"!][!//    
    [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsFinishCrc"!][!//
    [!NOCODE!][!//
        [!VAR "FlsCrcReminder" = "bit:shl($FlsCrcReminder,16)"!][!//
        [!CALL "FlsCalcCrcRemainder16bit"!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsCalcCrcRemainder16bit"!][!//
    [!NOCODE!][!//
        [!VAR "Rem16CrcPolynomSft" = "2282782720"!][!//
        [!VAR "Rem16LeadingOne" = "2147483648"!][!//
        [!FOR "Rem16Counter"="31" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem16LeadingOne,$FlsCrcReminder) = $Rem16LeadingOne"!][!//
                [!VAR "FlsCrcReminder"="bit:xor($FlsCrcReminder,$Rem16CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem16CrcPolynomSft"="bit:shr($Rem16CrcPolynomSft,1)"!][!//
            [!VAR "Rem16LeadingOne"="bit:shr($Rem16LeadingOne,1)"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsCalcCrcRemainder8bit"!][!//
    [!NOCODE!][!//
        [!VAR "Rem8CrcPolynomSft" = "8917120"!][!//
        [!VAR "Rem8LeadingOne" = "8388608"!][!//
        [!FOR "Rem8Counter"="23" TO "16" STEP "-1"!][!//
            [!IF "bit:and($Rem8LeadingOne,$FlsCrcReminder) = $Rem8LeadingOne"!][!//
                [!VAR "FlsCrcReminder"="bit:xor($FlsCrcReminder,$Rem8CrcPolynomSft)"!][!//
            [!ENDIF!][!//
            [!VAR "Rem8CrcPolynomSft"="bit:shr($Rem8CrcPolynomSft,1)"!][!//
            [!VAR "Rem8LeadingOne"="bit:shr($Rem8LeadingOne,1)"!][!//
        [!ENDFOR!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsDemEventCfg","FlsDemEventName","FlsDelimiter"!][!//
        [!NOCODE!][!//
        [!VAR "DemNodeFound" = "'false'"!][!//        
        [!LOOP "./FlsDemEventParameterRefs/*"!][!//
            [!IF "node:name(.)=$FlsDemEventName"!][!//
                [!VAR "DemNodeFound" = "'true'"!][!//
                [!IF "not(node:empty(.))"!][!//
                    [!IF "node:exists(node:ref(.))"!][!//                
                        [!IF "node:refvalid(.)"!][!//
                            [!VAR "DemRefName" = "(text:split(normalize-space(node:value(.)),'/'))[last()]"!][!//
                            [!CODE!]{(uint32)STD_ON, DemConf_DemEventParameter_[!"$DemRefName"!]}[!"$FlsDelimiter"!]    /* [!"node:name(.)"!] parameters */[!CR!][!ENDCODE!]
                        [!ELSE!][!//
                            [!ERROR "Invalid reference for $FlsDemEventName"!][!//
                        [!ENDIF!][!//   
                    [!ELSE!][!//
                        [!ERROR "Invalid reference for $FlsDemEventName"!]
                    [!ENDIF!][!//                 
                [!ELSE!][!//
                    [!CODE!]{(uint32)STD_OFF, 0U}[!"$FlsDelimiter"!]   /* [!"$FlsDemEventName"!] parameters */[!CR!][!ENDCODE!]
                [!ENDIF!][!//
            [!ENDIF!][!//
        [!ENDLOOP!][!//        
        [!IF "$DemNodeFound='false'"!]
            [!CODE!]{(uint32)STD_OFF, 0U}[!"$FlsDelimiter"!]   /* [!"$FlsDemEventName"!] parameters */[!CR!][!ENDCODE!]
        [!ENDIF!]
        [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
[!ENDIF!][!//
[!/* *** multiple inclusion protection *** */!]
[!IF "not(var:defined('FLS_CFG_SPECIFIC_MACROS_M4'))"!][!//
    [!VAR "FLS_CFG_SPECIFIC_MACROS_M4"="'true'"!][!//
    [!MACRO "FlsGetWritePageSizeValue","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!IF "$FlsEnumName='FLS_WRITE_DOUBLE_WORD'"!][!//
            [!VAR "OutWritePageSize" = "8"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_PAGE'"!][!//
            [!VAR "OutWritePageSize" = "32"!][!//
        [!ELSEIF "$FlsEnumName='FLS_WRITE_QUAD_PAGE'"!][!//       
            [!VAR "OutWritePageSize" = "128"!][!//
        [!ELSE!][!//   
            [!VAR "OutWritePageSize" = "0"!][!//
        [!ENDIF!][!//   
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsGetSectorId","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!IF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_0_L00'"!][!//
            [!VAR "OutFlsSectorId" = "0"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_0_L01'"!][!//
            [!VAR "OutFlsSectorId" = "1"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_1_L02'"!][!//
            [!VAR "OutFlsSectorId" = "2"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_1_L03'"!][!//
            [!VAR "OutFlsSectorId" = "3"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_0_L04'"!][!//
            [!VAR "OutFlsSectorId" = "4"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_1_L05'"!][!//
            [!VAR "OutFlsSectorId" = "5"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_2_M00'"!][!//
            [!VAR "OutFlsSectorId" = "6"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_2_M01'"!][!//
            [!VAR "OutFlsSectorId" = "7"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_2_M02'"!][!//
            [!VAR "OutFlsSectorId" = "8"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_2_M03'"!][!//
            [!VAR "OutFlsSectorId" = "9"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_3_M04'"!][!//
            [!VAR "OutFlsSectorId" = "10"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_3_M05'"!][!//
            [!VAR "OutFlsSectorId" = "11"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_3_M06'"!][!//
            [!VAR "OutFlsSectorId" = "12"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_3_M07'"!][!//
            [!VAR "OutFlsSectorId" = "13"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_2_M08'"!][!//
            [!VAR "OutFlsSectorId" = "14"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_3_M09'"!][!//
            [!VAR "OutFlsSectorId" = "15"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_6_LG00'"!][!//
            [!VAR "OutFlsSectorId" = "16"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_6_LG01'"!][!//
            [!VAR "OutFlsSectorId" = "17"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_6_LG02'"!][!//
            [!VAR "OutFlsSectorId" = "18"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_6_LG03'"!][!//
            [!VAR "OutFlsSectorId" = "19"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_6_LG04'"!][!//
            [!VAR "OutFlsSectorId" = "20"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_6_LG05'"!][!//
            [!VAR "OutFlsSectorId" = "21"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_6_LG06'"!][!//
            [!VAR "OutFlsSectorId" = "22"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_6_LG07'"!][!//
            [!VAR "OutFlsSectorId" = "23"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_7_LG08'"!][!//
            [!VAR "OutFlsSectorId" = "24"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_7_LG09'"!][!//
            [!VAR "OutFlsSectorId" = "25"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_7_LG10'"!][!//
            [!VAR "OutFlsSectorId" = "26"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_7_LG11'"!][!//
            [!VAR "OutFlsSectorId" = "27"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_7_LG12'"!][!//
            [!VAR "OutFlsSectorId" = "28"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_7_LG13'"!][!//
            [!VAR "OutFlsSectorId" = "29"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_7_LG14'"!][!//
            [!VAR "OutFlsSectorId" = "30"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_7_LG15'"!][!//
            [!VAR "OutFlsSectorId" = "31"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_8_LG16'"!][!//
            [!VAR "OutFlsSectorId" = "32"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_8_LG17'"!][!//
            [!VAR "OutFlsSectorId" = "33"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_8_LG18'"!][!//
            [!VAR "OutFlsSectorId" = "34"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_9_LG19'"!][!//
            [!VAR "OutFlsSectorId" = "35"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_9_LG20'"!][!//
            [!VAR "OutFlsSectorId" = "36"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_9_LG21'"!][!//
            [!VAR "OutFlsSectorId" = "37"!][!//
        [!ELSEIF "$FlsEnumName='FLS_UTEST_ARRAY_0_PART_0_L00'"!][!//
            [!VAR "OutFlsSectorId" = "38"!][!//
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_0_SHSM00'"!][!//
            [!VAR "OutFlsSectorId" = "39"!][!//    
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_0_HSM02'"!][!//
            [!VAR "OutFlsSectorId" = "40"!][!// 
        [!ELSEIF "$FlsEnumName='FLS_CODE_ARRAY_0_PART_1_HSM03'"!][!//
            [!VAR "OutFlsSectorId" = "41"!][!//
        [!ELSEIF "$FlsEnumName='FLS_DATA_ARRAY_0_PART_4_HSM00'"!][!//
            [!VAR "OutFlsSectorId" = "42"!][!//
        [!ELSEIF "$FlsEnumName='FLS_DATA_ARRAY_0_PART_5_HSM01'"!][!//
            [!VAR "OutFlsSectorId" = "43"!][!//
        [!ELSE!][!//
            [!VAR "OutFlsSectorId" = "4294967295"!][!//        
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
    [!//
    [!MACRO "FlsGetMemifModeValue","FlsEnumName"!][!//
    [!NOCODE!][!//
        [!IF "$FlsEnumName='MEMIF_MODE_SLOW'"!][!//
            [!VAR "OutMemifModeValue" = "0"!][!//
        [!ELSEIF "$FlsEnumName='MEMIF_MODE_FAST'"!][!//
            [!VAR "OutMemifModeValue" = "1"!][!//
        [!ELSE!][!//   
            [!VAR "OutMemifModeValue" = "4294967295"!][!//
        [!ENDIF!][!//
    [!ENDNOCODE!][!//
    [!ENDMACRO!][!//
[!ENDIF!][!//


[!INDENT "0"!][!//

[!LOOP "FlsConfigSet"!][!//

    #define FLS_START_SEC_CONFIG_DATA_8
    /* 
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    /* aFlsSectorFlags[] ([!"node:name(.)"!]) */
    static CONST(uint8, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorFlags[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!VAR "FlsFlag" = "0"!][!//
        [!IF "./FlsSectorEraseAsynch"!][!WS "4"!]FLS_SECTOR_ERASE_ASYNCH[!VAR "FlsFlag" = "1"!][!ENDIF!][!//
        [!IF "./FlsPageWriteAsynch"!][!IF "$FlsFlag = 1"!] | [!ELSE!][!WS "4"!][!VAR "FlsFlag" = "1"!][!ENDIF!]FLS_PAGE_WRITE_ASYNCH[!ENDIF!][!//
        [!IF "$FlsFlag = 0"!][!WS "4"!]0U[!ENDIF!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };
    /* aFlsSectorUnlock[] ([!"node:name(.)"!]) */
    static CONST(uint8, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorUnlock[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!][!IF "./FlsPhysicalSectorUnlock"!]1U[!ELSE!]0U[!ENDIF!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };
    #define FLS_STOP_SEC_CONFIG_DATA_8
    /* 
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    
    #define FLS_START_SEC_CONFIG_DATA_UNSPECIFIED
    /* 
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    /* aFlsSectorEndAddr[] ([!"node:name(.)"!]) */
    static CONST(Fls_AddressType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorEndAddr[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!][!"num:i(./FlsSectorSize + ./FlsSectorStartaddress - 1)"!]U[!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* FlsSectorEndAddr ([!"node:name(.)"!])*/
    [!ENDLOOP!][!//
    };
    /* aFlsProgrammingSize[] ([!"node:name(.)"!]) */
    static CONST(Fls_LengthType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsProgSize[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!](Fls_LengthType)[!"./FlsProgrammingSize"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* FlsProgrammingSize ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };
    /* aFlsPhysicalSector[] ([!"node:name(.)"!]) */
    static CONST(Fls_Flash_PhysicalSectorType, FLS_CONST) [!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsPhysicalSector[[!"num:i(count(FlsSectorList/FlsSector/*))"!]] =
    {
    [!VAR "FlsLoopIt" = "count(FlsSectorList/FlsSector/*)"!][!//
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        [!VAR "FlsLoopIt" = "$FlsLoopIt - 1"!][!//
        [!WS "4"!][!"./FlsPhysicalSector"!][!IF "$FlsLoopIt != 0"!],[!ENDIF!] /* FlsPhysicalSector ([!"node:name(.)"!]) */
    [!ENDLOOP!][!//
    };
    [!NOCODE!][!//
    
    
    [!VAR "FlsCrcReminder" = "0"!][!// reset CRC reminder
    [!LOOP "node:order(FlsSectorList/FlsSector/*,'node:value(./FlsSectorIndex)')"!][!//
        // CRC - Accumulate pSectorFlags
        [!VAR "FlsFlag" = "0"!][!//
        [!IF "./FlsSectorEraseAsynch"!][!VAR "FlsFlag" = "1"!][!ENDIF!][!//
        [!IF "./FlsPageWriteAsynch"!][!IF "$FlsFlag = 1"!][!VAR "FlsFlag" = "3"!][!ELSE!][!VAR "FlsFlag" = "2"!][!ENDIF!][!ENDIF!][!//
        [!CALL "FlsAccCrc","FlsData32"="$FlsFlag"!][!// 
        // CRC - Accumulate pSectorUnlock
        [!IF "./FlsPhysicalSectorUnlock"!][!VAR "FlsSectorUnlock"="1"!][!ELSE!][!VAR "FlsSectorUnlock"="0"!][!ENDIF!]
        [!CALL "FlsAccCrc","FlsData32"="$FlsSectorUnlock"!][!//
        // CRC - Accumulate pSectorEndAddr
        [!CALL "FlsAccCrc","FlsData32"="num:i(./FlsSectorSize + ./FlsSectorStartaddress - 1)"!][!//
        // CRC - Accumulate pSectorProgSize
        [!CALL "FlsGetWritePageSizeValue","FlsEnumName"="./FlsProgrammingSize"!][!//
        [!CALL "FlsAccCrc","FlsData32"="$OutWritePageSize"!][!// 
        // CRC - Accumulate pPhysicalSector
        [!CALL "FlsGetSectorId","FlsEnumName"="./FlsPhysicalSector"!][!//
        [!CALL "FlsAccCrc","FlsData32"="$OutFlsSectorId"!][!//            
    [!ENDLOOP!][!//
    
    // CRC - Accumulate eDefaultMode
    [!CALL "FlsGetMemifModeValue","FlsEnumName"="./FlsDefaultMode"!][!//
    [!CALL "FlsAccCrc","FlsData32"="$OutMemifModeValue"!][!//
    // CRC - Accumulate u32MaxReadFastMode
    [!CALL "FlsAccCrc","FlsData32"="./FlsMaxReadFastMode"!][!//
    // CRC - Accumulate u32MaxReadNormalMode
    [!CALL "FlsAccCrc","FlsData32"="./FlsMaxReadNormalMode"!][!//
    // CRC - Accumulate u32MaxWriteFastMode
    [!CALL "FlsAccCrc","FlsData32"="./FlsMaxWriteFastMode"!][!//
    // CRC - Accumulate u32MaxWriteNormalMode
    [!CALL "FlsAccCrc","FlsData32"="./FlsMaxWriteNormalMode"!][!//
    // CRC - Accumulate u32SectorCount
    [!CALL "FlsAccCrc","FlsData32"="num:i(count(FlsSectorList/FlsSector/*))"!][!//
    
    [!ENDNOCODE!][!//
    /**
    * @brief        Structure used to set function pointers notification, working mode
    */
    /* Fls module initialization data ([!"node:name(.)"!])*/
    /* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_5 Could be made static */
    
    CONST(Fls_ConfigType, FLS_CONST) [!"as:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!] =
    {
        [!WS "4"!]/* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_2 Conversions involing function pointers must be to/from integral types */
        [!WS "4"!]/* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_3 Cast from pointer to pointer */
        [!WS "4"!]/* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
        [!WS "4"!](Fls_Flash_AcErasePtrType)[!IF "../FlsGeneral/FlsAcLoadOnJobStart"!][!IF "normalize-space(./FlsAcErasePointer) = 'NULL_PTR' or normalize-space(./FlsAcErasePointer) = 'NULL'"!][!"normalize-space(./FlsAcErase)"!]U[!ELSE!]&[!"./FlsAcErasePointer"!][!ENDIF!][!ELSE!]&Fls_Flash_AccessCode[!ENDIF!], /* FlsAcErase */
        [!WS "4"!]/* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_2 Conversions involing function pointers must be to/from integral types */
        [!WS "4"!]/* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_3 Cast from pointer to pointer */
        [!WS "4"!]/* @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_8 A cast should not be performed between a pointer type and an integral type.*/
        [!WS "4"!](Fls_Flash_AcWritePtrType)[!IF "../FlsGeneral/FlsAcLoadOnJobStart"!][!IF "normalize-space(./FlsAcWritePointer) = 'NULL_PTR' or normalize-space(./FlsAcWritePointer) = 'NULL'"!][!"normalize-space(./FlsAcWrite)"!]U[!ELSE!]&[!"./FlsAcWritePointer"!][!ENDIF!][!ELSE!]&Fls_Flash_AccessCode[!ENDIF!], /* FlsAcWrite */
        [!WS "4"!][!IF "node:exists(FlsACCallback)"!]&[!"./FlsACCallback"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsACCallback */  
        [!WS "4"!][!IF "node:exists(FlsJobEndNotification)"!]&[!"./FlsJobEndNotification"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsJobEndNotification */
        [!WS "4"!][!IF "node:exists(FlsJobErrorNotification)"!]&[!"./FlsJobErrorNotification"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsJobErrorNotification */  
        [!WS "4"!][!IF "node:exists(FlsStartFlashAccessNotif)"!]&[!"./FlsStartFlashAccessNotif"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsStartFlashAccessNotif */
        [!WS "4"!][!IF "node:exists(FlsFinishedFlashAccessNotif)"!]&[!"./FlsFinishedFlashAccessNotif"!][!ELSE!]NULL_PTR[!ENDIF!], /* FlsFinishedFlashAccessNotif */
        [!WS "4"!][!"./FlsDefaultMode"!], /* FlsDefaultMode */
        [!WS "4"!][!"./FlsMaxReadFastMode"!]U, /* FlsMaxReadFastMode */
        [!WS "4"!][!"./FlsMaxReadNormalMode"!]U, /* FlsMaxReadNormalMode */
        [!WS "4"!][!"./FlsMaxWriteFastMode"!]U, /* FlsMaxWriteFastMode */
        [!WS "4"!][!"./FlsMaxWriteNormalMode"!]U, /* FlsMaxWriteNormalMode */
        [!WS "4"!][!"num:i(count(FlsSectorList/FlsSector/*))"!]U, /* FlsSectorCount */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorEndAddr, /* aFlsSectorEndAddr[]  */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsPhysicalSector, /* aFlsPhysicalSector[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorFlags, /* aFlsSectorFlags[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsProgSize, /* aFlsProgSize[] */
        [!WS "4"!]&[!"node:name(.)"!][!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_aFlsSectorUnlock, /* aFlsSectorUnlock[] */
        [!CALL "FlsFinishCrc"!][!//
        [!WS "4"!][!"$FlsCrcReminder"!]U /* configCrc */
    };
    #define FLS_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    /* 
    * @violates @ref fls_pbcfg[!IF "var:defined('postBuildVariant')"!]_[!"$postBuildVariant"!][!ENDIF!]_c_REF_1 Only preprocessor statements
    * and comments before '#include'
    */
    #include "Fls_MemMap.h"
    
[!ENDLOOP!][!//
[!ENDINDENT!][!//
[!ENDCODE!][!//

#ifdef __cplusplus
}
#endif

/** @}*/
