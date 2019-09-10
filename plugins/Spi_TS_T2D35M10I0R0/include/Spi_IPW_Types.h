/**
*   @file    Spi_IPW_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Spi middle level driver header file.
*   @details This file is the header containing all the necessary information for SPI
*            LLD.
*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : DSPI
*   Dependencies         : 
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

#ifndef SPI_IPW_TYPES_H
#define SPI_IPW_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SPI_IPW_TYPES_MODULE_ID                       83
#define SPI_IPW_TYPES_VENDOR_ID                       43
#define SPI_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define SPI_IPW_TYPES_AR_RELEASE_MINOR_VERSION        2
#define SPI_IPW_TYPES_AR_RELEASE_REVISION_VERSION     2
#define SPI_IPW_TYPES_SW_MAJOR_VERSION                1
#define SPI_IPW_TYPES_SW_MINOR_VERSION                0
#define SPI_IPW_TYPES_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                            ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief Internal structure used to manage the channel attributes.
*/
typedef struct
{
    VAR(uint32, SPI_VAR) u32CMD; /**< @brief Channel attributes for CMD in PUSHR (selects CTAR to use). */
#if (SPI_FORCE_DATA_TYPE == STD_ON)
    VAR(uint8, SPI_VAR)  u8DataWidth;       /**< @brief Channel attributes for data width. */
#endif
} Spi_Ipw_ChannelAttributesConfigType;

/**
* @brief Internal structure used to manage the DSPI unit attributes.
*/
typedef struct
{
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, SPI_VAR) u32CTAR[2];     /**< @brief Device attributes for CTARs. */
#else
    VAR(uint32, SPI_VAR) u32CTAR;        /**< @brief Device attributes for CTARs. */
#endif
    VAR(uint32, SPI_VAR) u32CMD;         /**< @brief Device attributes for CMD in PUSHR. */
    VAR(uint32, SPI_VAR) u32MCR;         /**< @brief Device CS idle setting. */
} Spi_Ipw_DeviceAttributesConfigType;

/**
* @brief Internal structure used to manage LLD attributes.
*/
typedef struct
{
    /**< @brief Array of configuration channel attributes. */
    CONST(Spi_Ipw_ChannelAttributesConfigType, SPI_CONST) (* const pcChannelAttributesConfig)[];
    /**< @brief Array of DSPI units attributes. */
    CONST(Spi_Ipw_DeviceAttributesConfigType, SPI_CONST) (* const pcDeviceAttributesConfig)[]; 
} Spi_AttributesConfigType;

#ifdef TSB_MODE_SUPPORTED
#if (SPI_TSB_MODE == STD_ON)
/**
* @brief Internal structure used to manage the TSB attributes.
*/
typedef struct
{
    VAR(uint32, SPI_VAR) u32DSICR;    /**< @brief Device attributes for DSICR. */
    VAR(uint32, SPI_VAR) u32DSICR1;   /**< @brief Device attributes for DSICR1. */
#if (SPI_DUAL_CLOCK_MODE == STD_ON)
    VAR(uint32, SPI_VAR) u32CTAR[2];
#else
    VAR(uint32, SPI_VAR) u32CTAR;
#endif
#ifdef ITSB_MODE_SUPPORTED
#if (SPI_ITSB_MODE == STD_ON)
    VAR(boolean, SPI_VAR) bIsITSBmode;/**< @brief Device attributes for determine ITSB enable or not. */
#if (ITSB_TIMESLOT_MODE == STD_ON)
    VAR(uint32, SPI_VAR)  u32TSL;      /**< @brief Device attributes for TSL. */
    VAR(uint32, SPI_VAR)  u32TS_CONF;  /**< @brief Device attributes for TS_CONF. */
#endif
#endif
#endif
} Spi_Ipw_TSBAttributesConfigType;
#endif /*SPI_TSB_MODE == STD_ON*/
#endif /*TSB_MODE_SUPPORTED*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif

#endif /*SPI_IPW_TYPES_H*/

/** @} */
