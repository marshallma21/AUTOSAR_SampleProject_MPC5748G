/**
*   @file    Fls_InternalTypes.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all Flash driver private types.
*
*   @addtogroup [FLS]
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

#ifndef FLS_INTERNALTYPES_H
#define FLS_INTERNALTYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Fls_InternalTypes_H_REF_1
* Violates MISRA 2004 Required Rule 1.4, Identifier clash.
* Define name is required by the AUTOSAR specifications although it exceeds the
* max length of 31 characters.
*
* @section Fee_InternalTypes_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier exceeds 31 characters
*
*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @{
* @file           Fee_InternalTypes.h
* @brief          Source file version information
* 
*/
#define FLS_INTERNALTYPES_VENDOR_ID                       43
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define FLS_INTERNALTYPES_AR_RELEASE_MAJOR_VERSION        4
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define FLS_INTERNALTYPES_AR_RELEASE_MINOR_VERSION        2
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define FLS_INTERNALTYPES_AR_RELEASE_REVISION_VERSION     2
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define FLS_INTERNALTYPES_SW_MAJOR_VERSION                1
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define FLS_INTERNALTYPES_SW_MINOR_VERSION                0
/* @violates @ref Fee_InternalTypes_H_REF_2 Identifier exceeds 31 characters */
#define FLS_INTERNALTYPES_SW_PATCH_VERSION                0
/** @} */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief          Type of job currently executed by Fls_MainFunction.
*/

typedef enum
{
    /**
    * @brief erase one or more complete flash sectors
    */
    FLS_JOB_ERASE = 0,    
    /**
    * @brief write one or more complete flash pages 
    */
    FLS_JOB_WRITE,        
    /**
    * @brief read one or more bytes from flash memory 
    */
    FLS_JOB_READ,     
    /**
    * @brief compare data buffer with content of flash memory
    */
    FLS_JOB_COMPARE 
    /**
    * @brief check content of erased flash memory area
    */
    ,FLS_JOB_BLANK_CHECK

} Fls_JobType;

/**
* @brief          Result of low-level flash operation.
*/
typedef enum 
{
    FLASH_E_OK = 0,                 /**< @brief operation succeeded */
    FLASH_E_FAILED,                 /**< @brief operation failed due to hardware error */
    FLASH_E_BLOCK_INCONSISTENT,     /**< @brief data buffer doesn't match with content of flash memory */
    FLASH_E_PENDING,                /**< @brief operation is pending */
    FLASH_E_PARTITION_ERR           /**< @brief FlexNVM partition ratio error */
} Fls_Flash_ReturnType;

/**
* @brief          Type of job currently executed by Fls_Flash_MainFunction.
*/
typedef enum
{
    /**
    * @brief no job executed by Fls_Flash_MainFunction 
    */    
    FLASH_JOB_NONE = 0, 
    /**
    * @brief erase one flash sector 
    */    
    FLASH_JOB_ERASE, 
    /**
    * @brief complete erase and start an interleaved erase flash sector 
    */
    FLASH_JOB_ERASE_TEMP,
    /**
    * @brief write one or more complete flash pages 
    */
    FLASH_JOB_WRITE, 
    /**
    * @brief erase blank check of flash sector
    */    
    FLASH_JOB_ERASE_BLANK_CHECK 
    
} Fls_Flash_JobType;

/**
* @brief          Size of data to be processeed by CRC.
*
* @implements     Fls_CrcDataSizeType_enumeration
*/
typedef enum 
{
    FLS_CRC_8_BITS = 0,
    FLS_CRC_16_BITS
} Fls_CrcDataSizeType;


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Logical sector index.
*/
typedef uint32 Fls_SectorIndexType;


/** 
    @brief FLASH physical sector description
*/
typedef struct
{
    P2VAR(volatile uint32, FLS_VAR, FLS_APPL_DATA) pSectorStartAddressPtr; /**< @brief FLASH physical sector start address */
    uint32 u32AddrSpaceBloSelValue; /**< @brief address space block select value */
    uint32 u32AddrSpaceBloLockValue; /**< @brief address space block lock value */
    uint32 u32SectorBloSelRegAddr; /**< @brief block select register address */
    uint32 u32AddrSpaceBloLockRegAddr; /**< @brief address space block primary lock register address */
    boolean bEccTriggersExc; /**< @brief triggers reading ECC data exception? */       
} Fls_Flash_SectorInfoType;

/** 
    @brief FLASH array description
*/
typedef struct
{
    boolean bProgramSuspPossible; /**< @brief is Program suspend operation possible within FLASH array */
    boolean bEraseSuspPossible; /**< @brief is Erase suspend operation possible within FLASH array */
} Fls_Flash_ArrayInfoType;


#ifdef __cplusplus
}
#endif

#endif /* FLS_INTERNALTYPES_H */

/** @}*/
