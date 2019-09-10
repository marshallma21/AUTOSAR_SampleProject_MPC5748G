/**
*   @file CDD_Mcl_Cfg.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - contains the configuration data of the MCL driver
*   @details Contains the configuration data of the MCL driver
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




#ifndef CDD_MCL_CFG_H
#define CDD_MCL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif 
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_Cfg_h_REF_1
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent the
*          contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
*          on the significance of more than 31 characters. The used compilers use more than 31 chars 
*          for identifiers.
*
* @section Mcl_Cfg_h_REF_3
*          Violates MISRA 2004 Required Rule 19.4, C macros shall only expand to a braced initialiser, 
*          a constant, a parenthesised expression, a type qualifier, a storage class specifier, or a
*          do-while-zero construct. 
*          This is used to abstract the export of configuration sets or for a function define.
*
*/

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/*
* @violates @ref Mcl_Cfg_h_REF_1 MISRA 2004 Required Rule 19.15 precautions to prevent the
*            contents of a header file being included twice
*/
#include "Mcl_EnvCfg.h"
#include "Mcal.h"

    
    
/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCL_VENDOR_ID_CFG                       43

#define MCL_AR_RELEASE_MAJOR_VERSION_CFG        4
#define MCL_AR_RELEASE_MINOR_VERSION_CFG        2
#define MCL_AR_RELEASE_REVISION_VERSION_CFG     2

#define MCL_SW_MAJOR_VERSION_CFG                1
#define MCL_SW_MINOR_VERSION_CFG                0
#define MCL_SW_PATCH_VERSION_CFG                0
/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (MCL_AR_RELEASE_MINOR_VERSION_CFG != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcal.h are different"
    #endif
#endif

/* Check if header file and Dem.h file are of the same Autosar version */

#if (MCL_VENDOR_ID_CFG != MCL_ENVCFG_VENDOR_ID)
    #error "CDD_Mcl_Cfg.h and Mcl_EnvCfg.h have different vendor ids"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same Autosar version */
#if (( MCL_AR_RELEASE_MAJOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MAJOR_VERSION) || \
     ( MCL_AR_RELEASE_MINOR_VERSION_CFG != MCL_ENVCFG_AR_RELEASE_MINOR_VERSION) || \
     ( MCL_AR_RELEASE_REVISION_VERSION_CFG !=  MCL_ENVCFG_AR_RELEASE_REVISION_VERSION))
     #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif
/* Check if current file and Mcl_CfgEnv header file are of the same software version */
#if ((MCL_SW_MAJOR_VERSION_CFG != MCL_ENVCFG_SW_MAJOR_VERSION) || \
     (MCL_SW_MINOR_VERSION_CFG != MCL_ENVCFG_SW_MINOR_VERSION) || \
     (MCL_SW_PATCH_VERSION_CFG != MCL_ENVCFG_SW_PATCH_VERSION))
     #error "Software Version Numbers of CDD_Mcl_Cfg.h and Mcl_EnvCfg.h are different"
#endif

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
    

#define MCL_PRECOMPILE_SUPPORT (STD_OFF)




/**
*   @brief  Switches the Development Error Detection and Notification on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*   
*/
#define MCL_DEV_ERROR_DETECT                  (STD_OFF)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_GetVersionInfo() from the code.
*        STD_ON: Mcl_GetVersionInfo() can be used. STD_OFF: Mcl_GetVersionInfo() can not be used.
*   
*/
#define MCL_GET_VERSION_INFO_API              (STD_ON)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DeInit() from the code.
*        STD_ON: Mcl_DeInit() can be used. STD_OFF: Mcl_DeInit() can not be used.
*   
*/
#define MCL_DEINIT_API                        (STD_OFF)

/**
*   @brief   Switches DMA features initialization on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define MCL_ENABLE_DMA              (STD_ON)



/**
*   @brief   Switches the Crossbar support on or off.
*        STD_ON: Enabled. STD_OFF: Disabled.
*
*/
#define MCL_CROSSBAR_NUM_INSTANCES        (0x2U)

#define MCL_ENABLE_CROSSBAR              (STD_OFF)  

#define MCL_CROSSBAR_PRS_READONLY        (STD_OFF)

#define MCL_CROSSBAR0_PRS_RESET_VALUE_U32     (0x76543210U)   

#define MCL_CROSSBAR0_CRS_RESET_VALUE_U32     (0x00FF0010U) 

#define MCL_CROSSBAR1_PRS_RESET_VALUE_U32     (0x76543210U)   

#define MCL_CROSSBAR1_CRS_RESET_VALUE_U32     (0x00FF0010U) 

#define MCL_AXBS_ENABLE_INIT_MGPCR        (STD_ON)

 
/**
* @brief      This define specifies enable or disable initialization of DCHMID register in DMA
*
*/
#define MCL_DMA_ENABLE_INIT_DCHMID (STD_ON) 
/**
* @brief      This define specifies the number of eDma Channels available for one eDma instance
*
*/
#define MCL_DMA_NB_CHANNELS                      (0x20U)
/**
* @brief      This define specifies the number of eDma instances
*
*/
#define MCL_DMA_NB_CONTROLLERS                   (0x1U)
/**
* @brief      This define specifies the number of eDma Mux instances
*
*/
#define MCL_DMAMUX_NB_MODULES                    (0x2U)

/**
* @brief      This define specifies the access to registers of dmamux is Little Endian or not
*
*/
#define MCL_DMAMUX_CHCFG_LITTLE_ENDIAN        (STD_OFF)

/**
* @brief      The defines bellow specify the DMAMUX sources
*
*/
        
/** @brief DMA Channel Sources for DmaMux Instance 0 */
#define MCL_DMA_MUX_0_ADC_0 (1U)
#define MCL_DMA_MUX_0_ADC_1 (2U)
#define MCL_DMA_MUX_0_CMP_0 (3U)
#define MCL_DMA_MUX_0_BCTU_0 (4U)
#define MCL_DMA_MUX_0_FlexCAN_0 (5U)
#define MCL_DMA_MUX_0_FlexCAN_2 (7U)
#define MCL_DMA_MUX_0_FlexCAN_4 (9U)
#define MCL_DMA_MUX_0_SPI_0_TX (12U)
#define MCL_DMA_MUX_0_SPI_0_RX (13U)
#define MCL_DMA_MUX_0_SPI_0_CMD (14U)
#define MCL_DMA_MUX_0_SPI_2_TX (15U)
#define MCL_DMA_MUX_0_SPI_2_RX (16U)
#define MCL_DMA_MUX_0_SPI_2_CMD (17U)
#define MCL_DMA_MUX_0_SPI_4_TX (18U)
#define MCL_DMA_MUX_0_SPI_4_RX (19U)
#define MCL_DMA_MUX_0_SPI_4_CMD (20U)
#define MCL_DMA_MUX_0_DSPI_0_TX (21U)
#define MCL_DMA_MUX_0_DSPI_0_RX (22U)
#define MCL_DMA_MUX_0_DSPI_0_CMD (23U)
#define MCL_DMA_MUX_0_DSPI_0_DSI (24U)
#define MCL_DMA_MUX_0_DSPI_2_TX (25U)
#define MCL_DMA_MUX_0_DSPI_2_RX (26U)
#define MCL_DMA_MUX_0_DSPI_2_CMD (27U)
#define MCL_DMA_MUX_0_DSPI_2_DSI (28U)
#define MCL_DMA_MUX_0_LIN_0_TX (29U)
#define MCL_DMA_MUX_0_LIN_0_RX (30U)
#define MCL_DMA_MUX_0_eMIOS_0_chA (31U)
#define MCL_DMA_MUX_0_eMIOS_0_chB (32U)
#define MCL_DMA_MUX_0_eMIOS_0_chC (33U)
#define MCL_DMA_MUX_0_eMIOS_0_chD (34U)
#define MCL_DMA_MUX_0_eMIOS_1_chA (35U)
#define MCL_DMA_MUX_0_eMIOS_1_chB (36U)
#define MCL_DMA_MUX_0_eMIOS_1_chC (37U)
#define MCL_DMA_MUX_0_eMIOS_1_chD (38U)
#define MCL_DMA_MUX_0_uSDHC (39U)
#define MCL_DMA_MUX_0_I2C_0_TX (40U)
#define MCL_DMA_MUX_0_I2C_0_RX (41U)
#define MCL_DMA_MUX_0_I2C_2_TX (42U)
#define MCL_DMA_MUX_0_I2C_2_RX (43U)
#define MCL_DMA_MUX_0_CMP_2 (44U)
#define MCL_DMA_MUX_0_FLEXCAN_6 (45U)
#define MCL_DMA_MUX_0_eMIOS_2_chA (47U)
#define MCL_DMA_MUX_0_eMIOS_2_chB (48U)
#define MCL_DMA_MUX_0_eMIOS_2_chC (49U)
#define MCL_DMA_MUX_0_eMIOS_2_chD (50U)
#define MCL_DMA_MUX_0_SAI_0_TX (51U)
#define MCL_DMA_MUX_0_SAI_0_RX (52U)
#define MCL_DMA_MUX_0_SAI_2_TX (53U)
#define MCL_DMA_MUX_0_SAI_2_RX (54U)
#define MCL_DMA_MUX_0_ENET_M0_Time_CH0 (55U)
#define MCL_DMA_MUX_0_ENET_M0_Time_CH1 (56U)
#define MCL_DMA_MUX_0_ENET_M0_Time_CH2 (57U)
#define MCL_DMA_MUX_0_FCCU_DMA_request (61U)
#define MCL_DMA_MUX_0_Always_on1 (62U)
#define MCL_DMA_MUX_0_Always_on2 (63U)
#define MCL_DMA_MUX_0_NOT_USED (64U)
        
/** @brief DMA Channel Sources for DmaMux Instance 1 */
#define MCL_DMA_MUX_1_ADC_0 (1U)
#define MCL_DMA_MUX_1_ADC_1 (2U)
#define MCL_DMA_MUX_1_CMP_1 (3U)
#define MCL_DMA_MUX_1_BCTU_1 (4U)
#define MCL_DMA_MUX_1_FlexCAN_1 (5U)
#define MCL_DMA_MUX_1_FlexCAN_3 (7U)
#define MCL_DMA_MUX_1_FlexCAN_5 (9U)
#define MCL_DMA_MUX_1_SPI_1_TX (12U)
#define MCL_DMA_MUX_1_SPI_1_RX (13U)
#define MCL_DMA_MUX_1_SPI_1_CMD (14U)
#define MCL_DMA_MUX_1_SPI_3_TX (15U)
#define MCL_DMA_MUX_1_SPI_3_RX (16U)
#define MCL_DMA_MUX_1_SPI_3_CMD (17U)
#define MCL_DMA_MUX_1_SPI_5_TX (18U)
#define MCL_DMA_MUX_1_SPI_5_RX (19U)
#define MCL_DMA_MUX_1_SPI_5_CMD (20U)
#define MCL_DMA_MUX_1_DSPI_1_TX (21U)
#define MCL_DMA_MUX_1_DSPI_1_RX (22U)
#define MCL_DMA_MUX_1_DSPI_1_CMD (23U)
#define MCL_DMA_MUX_1_DSPI_1_DSI (24U)
#define MCL_DMA_MUX_1_DSPI_3_TX (25U)
#define MCL_DMA_MUX_1_DSPI_3_RX (26U)
#define MCL_DMA_MUX_1_DSPI_3_CMD (27U)
#define MCL_DMA_MUX_1_DSPI_3_DSI (28U)
#define MCL_DMA_MUX_1_LIN_1_TX (29U)
#define MCL_DMA_MUX_1_LIN_1_RX (30U)
#define MCL_DMA_MUX_1_eMIOS_0_chE (31U)
#define MCL_DMA_MUX_1_eMIOS_0_chF (32U)
#define MCL_DMA_MUX_1_eMIOS_0_chG (33U)
#define MCL_DMA_MUX_1_eMIOS_0_chH (34U)
#define MCL_DMA_MUX_1_eMIOS_1_chE (35U)
#define MCL_DMA_MUX_1_eMIOS_1_chF (36U)
#define MCL_DMA_MUX_1_eMIOS_1_chG (37U)
#define MCL_DMA_MUX_1_eMIOS_1_chH (38U)
#define MCL_DMA_MUX_1_I2C_1_TX (39U)
#define MCL_DMA_MUX_1_I2C_1_RX (40U)
#define MCL_DMA_MUX_1_I2C_3_TX (41U)
#define MCL_DMA_MUX_1_I2C_3_RX (42U)
#define MCL_DMA_MUX_1_FlexCAN_7 (43U)
#define MCL_DMA_MUX_1_eMIOS_2_chE (45U)
#define MCL_DMA_MUX_1_eMIOS_2_chF (46U)
#define MCL_DMA_MUX_1_eMIOS_2_chG (47U)
#define MCL_DMA_MUX_1_eMIOS_2_chH (48U)
#define MCL_DMA_MUX_1_SAI_1_TX (49U)
#define MCL_DMA_MUX_1_SAI_1_RX (50U)
#define MCL_DMA_MUX_1_ENET_M1_Time_CH0 (51U)
#define MCL_DMA_MUX_1_ENET_M1_Time_CH1 (52U)
#define MCL_DMA_MUX_1_ENET_M1_Time_CH2 (53U)
#define MCL_DMA_MUX_1_Always_on1 (62U)
#define MCL_DMA_MUX_1_Always_on2 (63U)
#define MCL_DMA_MUX_1_NOT_USED (64U)

/**
* @{
*   @brief Configuration of Optional API's
*/
/**
*   @brief  Adds or removes the service Mcl_DmaGetChannelErrorStatus() from the code.
*        STD_ON: Mcl_DmaGetChannelErrorStatusApi() can be used. STD_OFF: Mcl_DmaGetChannelErrorStatusApi() can not be used.
*   
*/
#define MCL_DMA_GET_CH_ERR_STATUS_API            (STD_OFF)

/**
*   @brief  Adds or removes the service Mcl_DmaGetGlobalErrorStatusApi() from the code.
*        STD_ON: Mcl_DmaGetGlobalErrorStatusApi() can be used. STD_OFF: Mcl_DmaGetGlobalErrorStatusApi() can not be used.
*   
*/
#define MCL_DMA_GET_GLOBAL_ERR_STATUS_API            (STD_OFF)

/**
* @brief      This define specifies the number of eTimer channels available
*             on the current platform
*
*/
#define MCL_EDMA_CHANNELS_NO            (32U)

/**
* @brief      This define specifies the number of eTimer channels in a group of channels available
*             on the current platform
*
*/
#define MCL_EDMA_CHANNELS_IN_GROUP            (16U)

/**
* @brief      This define specifies the number of eTimer channels in a group of channels available
*             on the current platform
*
*/
#define MCL_DMA_ERROR_INTERRUPTS_USED            (STD_ON)

/**
* @brief      This define specifies if there is only one transfer completion ISR for all DMA channels within a DMA instance
*             or if there is a transfer completion ISR for each channel
*
*/
#define MCL_DMA_COMBINED_TR_COMPLETION_ISR (STD_OFF)

/**
* @brief      This define specifies if there is only one error ISR for all DMA instances
*             or if there is an error ISR for each DMA instance
*
*/
#define MCL_DMA_COMBINED_ERROR_ISR (STD_OFF)
/**
* @brief      This define specifies if there is Ecc error reporting available          
*
*/
#define MCL_DMA_ECC_REPORTING_ENABLED (STD_ON)

/** 
* @brief  Switch to globaly enable/disable the production error reporting.
*/
#define MCL_DISABLE_DEM_REPORT_ERROR_STATUS  (STD_ON)



/**
* @brief      This define specifies if there is only one transfer completion ISR for a DMA channel within a DMA instance
*             or if there is a transfer completion ISR for each channel
*
*/
#define MCL_DMA_TR_SEPARATED_ISR (STD_OFF)

/**
* @brief      This define specifies if inside a DMA instance some channels have the same transfer completion ISR assigned,
*             and other channels have their own transfer completion ISR.
*
*/
#define MCL_DMA_TR_COMPLETION_MIXED_ISR (STD_OFF)

/** Define to specify if least one transfer completion interrupt and notification is used, 
*      needed for removing at precompile time the code for ISR handling for the transfer 
*      completion notification processing. This define is needed in both combined transfer
*      completion interrupt and single channel mode. */
#define MCL_DMA_NOTIFICATION_SUPPORTED              (STD_OFF)

/* Transfer size options available */
#define MCL_TRANSFER_SIZE_1_BYTE 
#define MCL_TRANSFER_SIZE_2_BYTE 
#define MCL_TRANSFER_SIZE_4_BYTE 
#define MCL_TRANSFER_SIZE_8_BYTE 
#define MCL_TRANSFER_SIZE_32_BYTE 




/**
* @brief            Support for User mode.
*                   STD_ON: the Mcl driver can be executed from both supervisor and user mode. 
*                   STD_OFF: the Mcl driver can be executed only from supervisor mode. 
*/
#define MCL_ENABLE_USER_MODE_SUPPORT     (STD_OFF)
#define MCL_DMAMUX_USER_MODE_SUPPORT     (STD_OFF)
#define MCL_AXBS_USER_MODE_SUPPORT     (STD_ON)





/** Variant aware structure.c file. */

/** @violates @ref Mcl_Cfg_h_REF_3 MISRA 2004 Required Rule 19.4 C macros shall only expand to  */  
#define MCL_CONF_PB \
 extern CONST(Mcl_ConfigType, MCL_CONST) MclConfigSet_0;
/*==================================================================================================
                                             ENUMS
==================================================================================================*/
#if (MCL_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
/**
* @brief            DEM error reporting configuration.
* @details          This structure contains information DEM error reporting
*/
typedef struct
{
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Bus;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Descriptor;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Ecc;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Priority;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Unrecognized;
    VAR( Mcal_DemErrorType, MCL_VAR) Mcl_E_Dma_Inconsistency;
} Mcl_DemConfigType;

extern CONST( Mcl_DemConfigType, MCL_CONST) Mcl_Dem_Config;

#endif


/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

#endif    /* CDD_MCL_CFG_H */
/**@}*/


