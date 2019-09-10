/**
*   @file    Mcl_IPW_Types.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - Exported data outside of the Mcl from IPW.
*   @details Public data types exported outside of the Mcl driver.
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


#ifndef MCL_IPW_TYPES_H
#define MCL_IPW_TYPES_H


#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
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
#if (MCL_ENABLE_DMA == STD_ON)
    #include "Mcl_Dma_Types.h"
    #include "Mcl_DmaMux_Types.h"
#endif 

#if (MCL_ENABLE_CROSSBAR == STD_ON)
    #include "Mcl_Axbs_Types.h"
#endif
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_IPW_Types.h
* @requirements   BSW00374, BSW00379, BSW00318
*/
#define MCL_IPW_TYPES_VENDOR_ID                       43
#define MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION        4
#define MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION        2
#define MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION     2

#define MCL_IPW_TYPES_SW_MAJOR_VERSION                1
#define MCL_IPW_TYPES_SW_MINOR_VERSION                0
#define MCL_IPW_TYPES_SW_PATCH_VERSION                0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)

/* Check if header file and Mcl_Dma_Types.h header file are of the same vendor */
#if (MCL_IPW_TYPES_VENDOR_ID != MCL_DMA_TYPES_VENDOR_ID)
    #error "Mcl_IPW_Types.h and Mcl_Dma_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_Dma_Types.h header file are of the same Autosar version */
#if ((MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCL_DMA_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCL_DMA_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCL_DMA_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_IPW_Types.h and Mcl_Dma_Types.h are different"
#endif
/* Check if header file and Mcl_Dma_Types.h header file are of the same software version */
#if ((MCL_IPW_TYPES_SW_MAJOR_VERSION != MCL_DMA_TYPES_SW_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_SW_MINOR_VERSION != MCL_DMA_TYPES_SW_MINOR_VERSION) || \
     (MCL_IPW_TYPES_SW_PATCH_VERSION != MCL_DMA_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_IPW_Types.h and Mcl_Dma_Types.h are different"
#endif
/* Check if header file and Mcl_DmaMux_Types.h header file are of the same vendor */
#if (MCL_IPW_TYPES_VENDOR_ID != MCL_DMAMUX_TYPES_VENDOR_ID)
    #error "Mcl_IPW_Types.h and Mcl_DmaMux_Types.h have different vendor ids"
#endif
/* Check if header file and Mcl_DmaMux_Types.h header file are of the same Autosar version */
#if ((MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCL_DMAMUX_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCL_DMAMUX_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCL_DMAMUX_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_IPW_Types.h and Mcl_DmaMux_Types.h are different"
#endif
/* Check if header file and Mcl_DmaMux_Types.h header file are of the same software version */
#if ((MCL_IPW_TYPES_SW_MAJOR_VERSION != MCL_DMAMUX_TYPES_SW_MAJOR_VERSION) || \
     (MCL_IPW_TYPES_SW_MINOR_VERSION != MCL_DMAMUX_TYPES_SW_MINOR_VERSION) || \
     (MCL_IPW_TYPES_SW_PATCH_VERSION != MCL_DMAMUX_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_IPW_Types.h and Mcl_DmaMux_Types.h are different"
#endif
#endif

#if (MCL_ENABLE_CROSSBAR == STD_ON)

    /* Check if header file and Mcl_Axbs_Types.h header file are of the same vendor */
    #if (MCL_IPW_TYPES_VENDOR_ID != MCL_AXBS_TYPES_VENDOR_ID)
        #error "Mcl_IPW_Types.h and Mcl_Axbs_Types.h have different vendor ids"
    #endif
    /* Check if header file and Mcl_Axbs_Types.h header file are of the same Autosar version */
    #if ((MCL_IPW_TYPES_AR_RELEASE_MAJOR_VERSION    != MCL_AXBS_TYPES_AR_RELEASE_MAJOR_VERSION) || \
         (MCL_IPW_TYPES_AR_RELEASE_MINOR_VERSION    != MCL_AXBS_TYPES_AR_RELEASE_MINOR_VERSION) || \
         (MCL_IPW_TYPES_AR_RELEASE_REVISION_VERSION != MCL_AXBS_TYPES_AR_RELEASE_REVISION_VERSION))
        #error "AutoSar Version Numbers of Mcl_IPW_Types.h and Mcl_Axbs_Types.h are different"
    #endif
    /* Check if header file and Mcl_Axbs_Types.h header file are of the same software version */
    #if ((MCL_IPW_TYPES_SW_MAJOR_VERSION != MCL_AXBS_TYPES_SW_MAJOR_VERSION) || \
         (MCL_IPW_TYPES_SW_MINOR_VERSION != MCL_AXBS_TYPES_SW_MINOR_VERSION) || \
         (MCL_IPW_TYPES_SW_PATCH_VERSION != MCL_AXBS_TYPES_SW_PATCH_VERSION))
        #error "Software Version Numbers of Mcl_IPW_Types.h and Mcl_Axbs_Types.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#if (MCL_ENABLE_DMA == STD_ON)
/**
* @brief            Mcl driver configuration structure.
* @details          Configuration for DMA_MUX and eDMA modules.
*                   Used by "Mcl_ConfigType" structure.
*
*/
typedef struct
{
    P2CONST( Mcl_DmaConfigType, MCL_VAR, MCL_APPL_CONST) pDma_Config;         /**< @brief Configuration for eDMA (Enhanced Direct Memory Access) hardware IP. */ 
    P2CONST( Mcl_DmaMuxConfigType, MCL_VAR, MCL_APPL_CONST) pDmaMux_Config;   /**< @brief Configuration for DMA_MUX (eDMA Channel Mux) hardware IP. */ 
} Mcl_DmaHwIpsConfigType;

#endif /* (MCL_ENABLE_DMA == STD_ON) */

#if (MCL_ENABLE_CROSSBAR == STD_ON)
    /**  This gives the numeric ID of a Mcl logical slave port for the crossbar */
    typedef uint8      Mcl_CrossbarPortType;

    /**   Mcl Crossbar Slave Hw IP Configuration*/
    typedef Mcl_AxbsSlavePortConfigType  Mcl_CrossbarSlaveHwIpsConfigType;
#ifdef MCL_AXBS_ENABLE_INIT_MGPCR
#if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)
    /**   Mcl Crossbar Master Hw IP Configuration*/
    typedef Mcl_AxbsMasterPortConfigType  Mcl_CrossbarMasterHwIpsConfigType;
#endif
#endif   
    /**  Mcl Crossbar Configuration */
    typedef struct
    {
        /** @brief The number of configured channels. **/
        CONST(Mcl_CrossbarPortType, MCL_CONST)                                                  MclCrossbarIpNumPorts;
    #ifdef MCL_AXBS_ENABLE_INIT_MGPCR
    #if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)
        /** @brief The number of Master port. **/
        CONST(Mcl_CrossbarPortType, MCL_CONST)                                                  MclCrossbarMasterNumPorts;
    #endif
    #endif   
        /** @brief configuration of the crossbar IP for Slave */
        CONST(Mcl_CrossbarSlaveHwIpsConfigType, MCL_CONST)                             (* const pMclCrossbarSlaveHwIpConfig)[]; 
    #ifdef MCL_AXBS_ENABLE_INIT_MGPCR
    #if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)
        /** @brief configuration of the crossbar IP for Master */
        CONST(Mcl_CrossbarMasterHwIpsConfigType, MCL_CONST)                            (* const pMclCrossbarMasterHwIpConfig)[]; 
    #endif
    #endif   
    } Mcl_CrossbarConfigType;
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

#endif /* MCL_IPW_TYPES_H */


/** @} */

