/**
*   @file    Mcl_Axbs_Types.h
*   @version 1.0.0
*
*       AUTOSAR Mcl - Exported data outside of the Mcl from AXBS.
*   @details Public data types exported outside of the Mcl driver.
*
*   @addtogroup MCL_MODULE
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


#ifndef MCL_AXBS_TYPES_H
#define MCL_AXBS_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_AXBS_Types_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, : Repeated include files, Precautions shall be taken in
* order to prevent the contents of a header file being included twice This is not a violation since
* all header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"
#include "Soc_Ips.h"

/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_AXBS_Types.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define MCL_AXBS_TYPES_VENDOR_ID                       43
#define MCL_AXBS_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCL_AXBS_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCL_AXBS_TYPES_AR_RELEASE_REVISION_VERSION     2
#define MCL_AXBS_TYPES_SW_MAJOR_VERSION                1
#define MCL_AXBS_TYPES_SW_MINOR_VERSION                0
#define MCL_AXBS_TYPES_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
 /* Check if header file and MCL configuration header file are of the same vendor */
#if (MCL_AXBS_TYPES_VENDOR_ID != MCL_VENDOR_ID_CFG)
    #error "Mcl_Axbs_Types.h and CDD_Mcl_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and MCL configuration header file are of the same Autosar version */
#if ((MCL_AXBS_TYPES_AR_RELEASE_MAJOR_VERSION != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_AXBS_TYPES_AR_RELEASE_MINOR_VERSION != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_AXBS_TYPES_AR_RELEASE_REVISION_VERSION != MCL_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Mcl_Axbs_Types.h and CDD_Mcl_Cfg.h are different"
#endif
/* Check if header file and MCL configuration header file are of the same software version */
#if ((MCL_AXBS_TYPES_SW_MAJOR_VERSION != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_AXBS_TYPES_SW_MINOR_VERSION != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_AXBS_TYPES_SW_PATCH_VERSION != MCL_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Mcl_Axbs_Types.h and CDD_Mcl_Cfg.hare different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and Soc_Ips.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != MCL_AXBS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != MCL_AXBS_TYPES_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and Mcl_Axbs_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/* Mcl_AxbsPortType possible values. */
#define AXBS_PORT_0       (0U)
#define AXBS_PORT_1       (1U)
#define AXBS_PORT_2       (2U)
#define AXBS_PORT_3       (3U)
#define AXBS_PORT_4       (4U)
#define AXBS_PORT_5       (5U)
#define AXBS_PORT_6       (6U)
#define AXBS_PORT_7       (7U)


/* Mcl_AxbsInstanceType possible values. */
#define AXBS_INSTANCE0       (0U)
#define AXBS_INSTANCE1       (1U)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
*     Axbs port number type
*/
typedef uint8 Mcl_AxbsPortNumberType;
/**
*     Axbs instance number type
*/
typedef uint8 Axbs_InstanceNumber;
/**
*     Axbs port priority config
*/
typedef uint32 Mcl_AxbsPortPriorityType;
/**
*     Axbs port control type
*/
typedef uint32 Mcl_AxbsPortControlType;
/**
*     Master General Purpose Control type
*/
typedef uint32 Mcl_AxbsMasterGeneralType;
/**
*        configuration structure for Slave ports
*/
typedef struct
{
    /**   hardware port number */
    CONST(Mcl_AxbsPortNumberType,  MCL_CONST)   Axbs_PortNumber;
    /**   hardware instance  */
    CONST(Axbs_InstanceNumber,  MCL_CONST)      Axbs_InstanceNumber;
#ifdef MCL_CROSSBAR_PRS_READONLY    
#if (MCL_CROSSBAR_PRS_READONLY == STD_OFF)
    /**   port priority config */
    CONST(Mcl_AxbsPortPriorityType, MCL_CONST)  Axbs_PortPriorityConfig;
#endif
#endif
    /**   port control config */
    CONST(Mcl_AxbsPortControlType, MCL_CONST)   Axbs_PortControlConfig;   
} Mcl_AxbsSlavePortConfigType;

#ifdef MCL_AXBS_ENABLE_INIT_MGPCR
#if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)
/**
*        configuration structure for Master ports
*/
typedef struct
{
    /**   hardware port number */
    CONST(Mcl_AxbsPortNumberType,  MCL_CONST)   Axbs_PortNumber;
    /**   hardware instance  */
    CONST(Axbs_InstanceNumber,  MCL_CONST)      Axbs_InstanceNumber;
    CONST(Mcl_AxbsMasterGeneralType, MCL_CONST)   Axbs_MasterGeneralConfig;
} Mcl_AxbsMasterPortConfigType;
#endif
#endif

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /* MCL_AXBS_TYPES_H */

/** @} */
