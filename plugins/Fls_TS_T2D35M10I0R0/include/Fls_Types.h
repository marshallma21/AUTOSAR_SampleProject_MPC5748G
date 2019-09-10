/**
*   @file    Fls_Types.h   
*   @version 1.0.0
*
*   @brief   AUTOSAR Fls - AUTOSAR Module Flash Driver.
*   @details Definitions of all Flash driver exported types.
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

#ifndef FLS_TYPES_H
#define FLS_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1,
* Identifiers (internal and external) shall not rely on the significance of more than 31 characters. 
* The used compilers use more than 31 chars for identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "MemIf_Types.h"
#include "Reg_eSys_FLASHC.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FLS_TYPES_VENDOR_ID                    43
#define FLS_TYPES_MODULE_ID                    92
#define FLS_TYPES_AR_RELEASE_MAJOR_VERSION     4
#define FLS_TYPES_AR_RELEASE_MINOR_VERSION     2
#define FLS_TYPES_AR_RELEASE_REVISION_VERSION  2
#define FLS_TYPES_SW_MAJOR_VERSION             1
#define FLS_TYPES_SW_MINOR_VERSION             0
#define FLS_TYPES_SW_PATCH_VERSION             0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Std_Types.h file are of the same version */
    #if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_TYPES_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fls_Types.h and Std_Types.h are different"
    #endif
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and MemIf_Types.h file are of the same version */
    #if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION != MEMIF_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_TYPES_AR_RELEASE_MINOR_VERSION != MEMIF_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fls_Types.h and MemIf_Types.h are different"
    #endif
#endif

/* Check if current file and Reg_eSys_FLASHC.h file are of the same vendor */
#if (FLS_TYPES_VENDOR_ID != ESYS_FLASHC_VENDOR_ID)
    #error "Fls_Types.h and Reg_eSys_FLASHC.h have different vendor ids"
#endif
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if current file and Reg_eSys_FLASHC.h file are of the same version */
    #if ((FLS_TYPES_AR_RELEASE_MAJOR_VERSION != ESYS_FLASHC_AR_RELEASE_MAJOR_VERSION) || \
         (FLS_TYPES_AR_RELEASE_MINOR_VERSION != ESYS_FLASHC_AR_RELEASE_MINOR_VERSION)\
        )
        #error "AutoSar Version Numbers of Fls_Types.h and Reg_eSys_FLASHC.h are different"
    #endif
#endif
/* Check if current file and Reg_eSys_FLASHC.h header file are of the same Software version */
#if ((FLS_TYPES_SW_MAJOR_VERSION != ESYS_FLASHC_SW_MAJOR_VERSION) || \
     (FLS_TYPES_SW_MINOR_VERSION != ESYS_FLASHC_SW_MINOR_VERSION) || \
     (FLS_TYPES_SW_PATCH_VERSION != ESYS_FLASHC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Fls_Types.h and Reg_eSys_FLASHC.h are different"
#endif
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module doesn't feel responsible (e.g. address does not belong to its current job)
*
*/
#define FLS_UNHANDLED       0U

/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module feels responsible, but wants to repeat the  causing instruction. 
*                 Maybe: it still uses information in MCM or ECSM module, but they are outdated 
*                (e.g. due to an erroneous DMA transfer in the meantime)
*
*/
#define FLS_HANDLED_RETRY   1U
/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module feels responsible (usually it just would set some internal flag?) 
*                 processing may continue, skipping the causing instruction
*
*/
#define FLS_HANDLED_SKIP    2U  /* module feels responsible (usually it just would set some 
                                       internal flag?) processing may continue, skipping the 
                                       causing instruction                                        */

/**
* @brief          Return value for Fls_DsiHandler and Fls_MciHandler.
* @details        module  feels responsible, but the only reaction is to stop the system 
*                 (e.g.: try to shut-down in a quite safe way)
*
*/
#define FLS_HANDLED_STOP    3U

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
    @brief Enumeration of physical flash sectors
*/
typedef enum
{
    FLS_CODE_ARRAY_0_PART_0_L00 = 0,
    FLS_CODE_ARRAY_0_PART_0_L01,
    FLS_CODE_ARRAY_0_PART_1_L02,
    FLS_CODE_ARRAY_0_PART_1_L03,
    FLS_CODE_ARRAY_0_PART_0_L04,
    FLS_CODE_ARRAY_0_PART_1_L05,
    FLS_CODE_ARRAY_0_PART_2_M00,
    FLS_CODE_ARRAY_0_PART_2_M01,
    FLS_CODE_ARRAY_0_PART_2_M02,
    FLS_CODE_ARRAY_0_PART_2_M03,
    FLS_CODE_ARRAY_0_PART_3_M04,
    FLS_CODE_ARRAY_0_PART_3_M05,
    FLS_CODE_ARRAY_0_PART_3_M06,
    FLS_CODE_ARRAY_0_PART_3_M07,
    FLS_CODE_ARRAY_0_PART_2_M08,
    FLS_CODE_ARRAY_0_PART_3_M09,
    FLS_CODE_ARRAY_0_PART_6_LG00,
    FLS_CODE_ARRAY_0_PART_6_LG01,
    FLS_CODE_ARRAY_0_PART_6_LG02,
    FLS_CODE_ARRAY_0_PART_6_LG03,
    FLS_CODE_ARRAY_0_PART_6_LG04,
    FLS_CODE_ARRAY_0_PART_6_LG05,
    FLS_CODE_ARRAY_0_PART_6_LG06,
    FLS_CODE_ARRAY_0_PART_6_LG07,
    FLS_CODE_ARRAY_0_PART_7_LG08,
    FLS_CODE_ARRAY_0_PART_7_LG09,
    FLS_CODE_ARRAY_0_PART_7_LG10,
    FLS_CODE_ARRAY_0_PART_7_LG11,
    FLS_CODE_ARRAY_0_PART_7_LG12,
    FLS_CODE_ARRAY_0_PART_7_LG13,
    FLS_CODE_ARRAY_0_PART_7_LG14,
    FLS_CODE_ARRAY_0_PART_7_LG15,
    FLS_CODE_ARRAY_0_PART_8_LG16,
    FLS_CODE_ARRAY_0_PART_8_LG17,
    FLS_CODE_ARRAY_0_PART_8_LG18,
    FLS_CODE_ARRAY_0_PART_9_LG19,
    FLS_CODE_ARRAY_0_PART_9_LG20,
    FLS_CODE_ARRAY_0_PART_9_LG21,
    FLS_UTEST_ARRAY_0_PART_0_L00,
    FLS_CODE_ARRAY_0_PART_0_SHSM00,
    FLS_CODE_ARRAY_0_PART_0_HSM02,
    FLS_CODE_ARRAY_0_PART_1_HSM03,
    FLS_DATA_ARRAY_0_PART_4_HSM00,
    FLS_DATA_ARRAY_0_PART_5_HSM01    
} Fls_Flash_PhysicalSectorType;

/** 
    @brief Enumeration of physical flash sectors page size
*/ 
typedef enum
{
    FLS_PAGE_SIZE_04 = 0x4U,
    FLS_PAGE_SIZE_08 = 0x8U
} Fls_Flash_PageSizeType;

/** 
    @brief Enumeration of physical flash sectors program size
*/ 
typedef enum
{
    FLS_WRITE_DOUBLE_WORD = 8U,
    FLS_WRITE_PAGE = 32U,
    FLS_WRITE_QUAD_PAGE = 128U
} Fls_Flash_ProgSizeType;

/** 
    @brief Define pointer type of erase access code function
*/
typedef P2FUNC( void, FLS_CODE, Fls_Flash_AcErasePtrTOType )    (
                                                                    CONST(uint32, AUTOMATIC) u32RegBaseAddr, 
                                                                    P2FUNC(void, FLS_CODE, CallBack)( void ), 
                                                                    P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, 
                                                                    P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort
                                                                );
typedef P2FUNC( void, FLS_CODE, Fls_Flash_AcErasePtrNoTOType )  (
                                                                    CONST(uint32, AUTOMATIC) u32RegBaseAddr, 
                                                                    P2FUNC(void, FLS_CODE, CallBack)( void )
                                                                );

/**
    @brief Define pointer type of write access code function
*/
typedef P2FUNC( void, FLS_CODE, Fls_Flash_AcWritePtrTOType )    (
                                                                    CONST(uint32, AUTOMATIC) u32RegBaseAddr, 
                                                                    P2FUNC(void, FLS_CODE, CallBack)( void ), 
                                                                    P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAC, 
                                                                    P2VAR(uint32, AUTOMATIC, FLS_CODE) pTimerCounterAbort
                                                                );
typedef P2FUNC( void, FLS_CODE, Fls_Flash_AcWritePtrNoTOType )  (   
                                                                    CONST(uint32, AUTOMATIC) u32RegBaseAddr, 
                                                                    P2FUNC(void, FLS_CODE, CallBack)( void )
                                                                );



/**
* @brief          Fls Address Type.
* @details        Address offset from the configured flash base address to access a certain flash 
*                 memory area.
* @implements     Fls_AddressType_typedef
*/
typedef uint32 Fls_AddressType;

/**
* @brief          Fls Length Type.
* @details        Number of bytes to read,write,erase,compare
* @implements     Fls_LengthType_typedef
*/
typedef uint32 Fls_LengthType;

/**
* @brief          Fls Sector Count Type
* @details        Number of configured sectors
*/
typedef uint32 Fls_SectorCountType;

/**
 * @brief Pointer type of Fls_AC_Callback function
*/
typedef P2FUNC( void, FLS_CODE, Fls_ACCallbackPtrType )  ( void );


/**
* @brief          Fls Job End Notification Pointer Type
* @details        Pointer type of Fls_JobEndNotification function
* @implements     Fls_JobEndNotificationPtrType_typedef
*/
typedef P2FUNC(void, FLS_CODE, Fls_JobEndNotificationPtrType)(void);

/**
* @brief          Fls Job Error Notification Pointer Type
* @details        Pointer type of Fls_JobErrorNotification function
* @implements     Fls_JobErrorNotificationPtrType_typedef
*/
typedef P2FUNC(void, FLS_CODE, Fls_JobErrorNotificationPtrType)(void);  


/**
* @brief          Fls Start Flash Access Notification Pointer Type
* @details        Pointer type of Fls_StartFlashAccessNotif function
*
*/
typedef P2FUNC(void, FLS_CODE, Fls_StartFlashAccessNotifPtrType)(void);

/**
* @brief          Fls Finished Flash Access Notification Pointer Type
* @details        Pointer type of Fls_FinishedFlashAccessNotif function
* 
*/
typedef P2FUNC(void, FLS_CODE, Fls_FinishedFlashAccessNotifPtrType)(void);  


/**
* @brief          Return value of Fls handler function.
* @details        Fls_DsiHandler and Fls_MciHandler can return the following value:
*                 - FLS_UNHANDLED    Fls driver is not responsable for this situation
*                 - FLS_HANDLED_SKIP Fls driver is responsable for this exception and want to skip this job
*                 .
*/ 
typedef uint8_least Fls_CompHandlerReturnType;

typedef const uint8 * Fls_InstructionAddressType;
typedef const void * Fls_DataAddressType;

/**
* @brief          Detailed information on the exception.
* @details        The following information will be checked by the driver:
*                 - if there is a pending read, compare, 
*                 - data_pt matches address currently accessed by pending flash read or flash compare job, 
*                 - if the exception syndrome register indicates DSI or MCI reason, 
*                 .
*
*/
typedef struct
{
    Fls_InstructionAddressType instruction_pt; /**< @brief pointer to the instruction that generated the ECC */
    Fls_DataAddressType        data_pt;        /**< @brief data address that caused the ECC error */
    uint32                     syndrome_u32;   /**< @brief details on the type of exception */
} Fls_ExceptionDetailsType;

typedef const Fls_ExceptionDetailsType *ExceptionDetailsPtrType;


/**
* @brief          Fls CRC Type.
* @details        CRC computed over config set.
* @implements     Fls_CrcType_typedef
*/
typedef uint16 Fls_CrcType;



#ifdef __cplusplus
}
#endif

#endif /* FLS_TYPES_H */

/** @}*/
