/**
*     @file            Icu_Ipw.c
*     @implements     Icu_Ipw_unit
*     @version 1.0.0
*
*     @brief   AUTOSAR Icu - ICU Driver LLD source file.
*     @details ICU driver source file, containing the LLD variables and functions that are used by
*              the ICU driver.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project AUTOSAR 4.2 MCAL
*     Platform PA
*     Peripheral eMIOS SIUL2 WKPU
*     Dependencies none
*
*     Autosar Version 4.2.2
*     Autosar Revision ASR_REL_4_2_REV_0002
*     Autosar ConfVariant
*     SWVersion 1.0.0
*     BuildVersion MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_Ipw_c_REF_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*          before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
*          is as  per Autosar  requirement MEMMAP003.
*
* @section Icu_Ipw_c_REF_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
*          the contents of a header file being included twice
*          This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_Ipw_c_REF_3
*          Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure 31
*          character significance and case sensitivity are supported for external identifiers.
*          This is not a violation since all the compilers used interpret the identifiers correctly.
*
* @section Icu_Ipw_c_REF_4
*          Violates MISRA 2004 Required Rule 8.10, could be made static
*          The respective code could not be made static because of layers architecture design of
*          the driver.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1,Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters.The used compilers use more than 31 chars
*          for identifiers.
*/


/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"

#include "Icu_Cfg.h"

#include "Icu_Ipw.h"
#include "Icu_eMios.h"
#include "Icu_Siul2.h"
#include "Icu_Wkpu.h"
/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

#define ICU_IPW_VENDOR_ID_C                     43
/*
* @violates @ref Icu_Ipw_c_REF_3 Identifier clash.
*/
#define ICU_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/*
* @violates @ref Icu_Ipw_c_REF_3 Identifier clash.
*/
#define ICU_IPW_AR_RELEASE_MINOR_VERSION_C      2
/*
* @violates @ref Icu_Ipw_c_REF_3 Identifier clash.
*/
#define ICU_IPW_AR_RELEASE_REVISION_VERSION_C   2
#define ICU_IPW_SW_MAJOR_VERSION_C              1
#define ICU_IPW_SW_MINOR_VERSION_C              0
#define ICU_IPW_SW_PATCH_VERSION_C              0
/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Ipw.c and Mcal.h are different"
    #endif
#endif


#if (ICU_IPW_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
#error "Icu_Ipw.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Ipw.c are different"
    #endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu_Cfg.h and Icu_Ipw.c are different"
#endif


#if (ICU_IPW_VENDOR_ID_C != ICU_TYPES_VENDOR_ID)
#error "Icu_Ipw.c and Icu_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_Types header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Types.h and Icu_Ipw.c are different"
    #endif
/* Check if source file and Icu_Types header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_TYPES_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_TYPES_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Types.h and Icu_Ipw.c are different"
#endif


#if (ICU_IPW_VENDOR_ID_C != ICU_IPW_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_Ipw.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Ipw.h are different"
#endif
/* Check if source file and Icu_Ipw header file are of the same Software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_IPW_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_IPW_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_IPW_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Ipw.c and Icu_Ipw.h are different"
#endif

 /* Check if source file and Icu_eMIOS header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_EMIOS_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_eMIOS.h have different vendor IDs"
#endif
    /* Check if source file and Icu_eMIOS header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_EMIOS_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_EMIOS_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_eMIOS.h are different"
#endif
/* Check if source file andIcu_eMIOS header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_EMIOS_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_EMIOS_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_EMIOS_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw.c and Icu_eMIOS.h are different"
#endif


/* Check if source file and Icu_Siul2 header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_SIUL2_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_Siul2.h have different vendor IDs"
#endif
    /* Check if source file and Icu_Siul2 header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_SIUL2_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_SIUL2_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Siul2.h are different"
#endif
/* Check if source file andIcu_Siul2 header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_SIUL2_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_SIUL2_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_SIUL2_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw.c and Icu_Siul2.h are different"
#endif


/* Check if source file and Icu_Wkpu header file are of the same vendor */
#if (ICU_IPW_VENDOR_ID_C != ICU_WKPU_VENDOR_ID)
    #error "Icu_Ipw.c and Icu_Wkpu.h have different vendor IDs"
#endif
    /* Check if source file and Icu_Wkpu header file are of the same Autosar version */
#if ((ICU_IPW_AR_RELEASE_MAJOR_VERSION_C != ICU_WKPU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_MINOR_VERSION_C != ICU_WKPU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_IPW_AR_RELEASE_REVISION_VERSION_C != ICU_WKPU_AR_RELEASE_REVISION_VERSION))
 #error "AutoSar Version Numbers of Icu_Ipw.c and Icu_Wkpu.h are different"
#endif
/* Check if source file and Icu_Wkpu header file are of the same software version */
#if ((ICU_IPW_SW_MAJOR_VERSION_C != ICU_WKPU_SW_MAJOR_VERSION) || \
     (ICU_IPW_SW_MINOR_VERSION_C != ICU_WKPU_SW_MINOR_VERSION) || \
     (ICU_IPW_SW_PATCH_VERSION_C != ICU_WKPU_SW_PATCH_VERSION))
 #error "Software Version Numbers of Icu_Ipw.c and Icu_Wkpu.h are different"
#endif
/*==================================================================================================
*                           LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                        GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                        GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                    LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/*
* @violates @ref Icu_Ipw_c_REF_1 only preprocessor statements and
*        comments before "#include".
*/
/*
* @violates @ref Icu_Ipw_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

 /**
 * @brief      Icu_Ipw_Init
 * @details    Initialize a hardware ICU channel
 *
 * @param[in]      hwChannel   - This index relates the Icu Channel number with the respective
 *                               global variable, depending on the measurement mode
 *                               Each kind of measurement mode has an array(s) in the ICU driver,
 *                               this index points to the corresponding variable within the ICU
 *                               channel
 * @param[in]      ParamValue  - contains the parameters to initialize the hardware channel
 * @param[in]      ChannelMode - The measurement mode of the channel
 *
 * @return void
 *
 * @pre        Icu_DeInit must be called before.
 *
 */
FUNC (void, ICU_CODE) Icu_Ipw_Init
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    /* eMIOS Channel Configuration */
    if (NULL_PTR != pIpConfig->peMiosIpConfig)
    {
        Icu_eMios_Init(pIpConfig->peMiosIpConfig);
    }

    /* External Interrupt Channel Configuration */
    if (NULL_PTR != pIpConfig->pSiul2IpConfig)
    {
        Icu_Siul2_Init(pIpConfig->pSiul2IpConfig);
    }

    /* Wakeup Unit Channel Configuration */
    if (NULL_PTR != pIpConfig->pWkpuIpConfig)
    {
        Icu_Wkpu_Init(pIpConfig->pWkpuIpConfig);
    }
}

 #if (ICU_DE_INIT_API == STD_ON)
/**
* @brief              Icu_Ipw_DeInit
* @details            De-initialize ICU hardware channel
*
* @param[in]          hwChannel - This index relates the Icu Channel number
*
* @return void
*
* @pre                Icu_Init must be called before.
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_DeInit
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    /* eMIOS Channel Configuration */
    if (NULL_PTR != pIpConfig->peMiosIpConfig)
    {
        Icu_eMios_DeInit(pIpConfig->peMiosIpConfig);
    }
    /* External Interrupt Channel Configuration */
    if (NULL_PTR != pIpConfig->pSiul2IpConfig)
    {
        Icu_Siul2_DeInit(pIpConfig->pSiul2IpConfig);
    }

    /* Wakeup Unit Channel Configuration */
    if (NULL_PTR != pIpConfig->pWkpuIpConfig)
    {
        Icu_Wkpu_DeInit(pIpConfig->pWkpuIpConfig);
    }
}
#endif /* ICU_DE_INIT_API == STD_ON */

#if (ICU_SET_MODE_API == STD_ON)
/**
* @brief      Icu_Ipw_SetSleepMode
* @details    Set sleep mode
*
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
* @param[in]      active     - ICU channel is active during SLEEP mode (wakeup was enabled)
*
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_SetSleepMode
(
    VAR(Icu_ChannelType,                           AUTOMATIC) nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    P2CONST(Icu_Siul2_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pSiul2IpChConfig;
    P2CONST(Icu_Siul2_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pSiul2ChannelConfig;

    P2CONST(Icu_Wkpu_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pWkpuIpChConfig;
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pWkpuChannelConfig;

    if (ICU_EMIOS_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        peMiosIpChConfig = pIpConfig->peMiosIpConfig;
        peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

        Icu_eMios_SetSleepMode((Icu_eMios_ChannelType)ICU_EMIOS_CHANNELS(nHardwareChannel));
    }
    else if (ICU_SIUL2_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pSiul2IpChConfig = pIpConfig->pSiul2IpConfig;
        pSiul2ChannelConfig = &(*pSiul2IpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pSiul2ChannelConfig->nHwChannel;

        Icu_Siul2_SetSleepMode((Icu_Siul2_ChannelType)ICU_IRQ_CHANNELS(nHardwareChannel));
    }
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pWkpuIpChConfig = pIpConfig->pWkpuIpConfig;
        pWkpuChannelConfig = &(*pWkpuIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pWkpuChannelConfig->nHwChannel;

        Icu_Wkpu_SetSleepMode((Icu_Wkpu_ChannelType)ICU_WKPU_CHANNELS(nHardwareChannel));
    }
}


/**
* @brief      Icu_Ipw_SetNormalMode
* @details    Set normal mode
*
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
*
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_SetNormalMode
(
    VAR(Icu_ChannelType,                           AUTOMATIC) nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    P2CONST(Icu_Siul2_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pSiul2IpChConfig;
    P2CONST(Icu_Siul2_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pSiul2ChannelConfig;

    P2CONST(Icu_Wkpu_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pWkpuIpChConfig;
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pWkpuChannelConfig;

    if (ICU_EMIOS_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        peMiosIpChConfig = pIpConfig->peMiosIpConfig;
        peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

        Icu_eMios_SetNormalMode((Icu_eMios_ChannelType)ICU_EMIOS_CHANNELS(nHardwareChannel));
    }
    else if (ICU_SIUL2_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pSiul2IpChConfig = pIpConfig->pSiul2IpConfig;
        pSiul2ChannelConfig = &(*pSiul2IpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pSiul2ChannelConfig->nHwChannel;

        Icu_Siul2_SetNormalMode((Icu_Siul2_ChannelType)ICU_IRQ_CHANNELS(nHardwareChannel));
    }

    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pWkpuIpChConfig = pIpConfig->pWkpuIpConfig;
        pWkpuChannelConfig = &(*pWkpuIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pWkpuChannelConfig->nHwChannel;

        Icu_Wkpu_SetNormalMode((Icu_Wkpu_ChannelType)ICU_WKPU_CHANNELS(nHardwareChannel));
    }
}
#endif  /* ICU_SET_MODE_API */

/**
* @brief      Icu_Ipw_SetActivationCondition
* @details
*
* @param[in]      nChannelNumber     - The index of ICU channel for current configuration structure
* @param[in]      Activation         - the type of Activation for the ICU channel.
* @param[in]      Mode               - the measurement mode of the channel
*
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_SetActivationCondition
(
    VAR(Icu_ChannelType,            AUTOMATIC) nChannelNumber,
    VAR(Icu_ActivationType,         AUTOMATIC) Activation,
    VAR(Icu_MeasurementModeType,    AUTOMATIC) Mode,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    P2CONST(Icu_Siul2_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pSiul2IpChConfig;
    P2CONST(Icu_Siul2_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pSiul2ChannelConfig;

    P2CONST(Icu_Wkpu_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pWkpuIpChConfig;
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pWkpuChannelConfig;
    (void) Mode;

    /* eMIOS Channel Configuration */
    if (ICU_EMIOS_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        peMiosIpChConfig = pIpConfig->peMiosIpConfig;
        peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

        Icu_eMios_SetActivationCondition
        (
            (Icu_eMios_ChannelType)ICU_EMIOS_CHANNELS(nHardwareChannel),
            (Icu_eMios_ActivationType)Activation
        );
    }
    /* External Interrupt Channel Configuration */
    else if (ICU_SIUL2_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pSiul2IpChConfig = pIpConfig->pSiul2IpConfig;
        pSiul2ChannelConfig = &(*pSiul2IpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pSiul2ChannelConfig->nHwChannel;

        Icu_Siul2_SetActivationCondition
        (
            (Icu_Siul2_ChannelType)ICU_IRQ_CHANNELS(nHardwareChannel),
            (Icu_Siul2_ActivationType)Activation
        );
    }

    /* Wakeup Unit Channel Configuration */
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pWkpuIpChConfig = pIpConfig->pWkpuIpConfig;
        pWkpuChannelConfig = &(*pWkpuIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pWkpuChannelConfig->nHwChannel;

        Icu_Wkpu_SetActivationCondition
        (
            (Icu_Wkpu_ChannelType)ICU_WKPU_CHANNELS(nHardwareChannel),
            (WKPU_ActivationType) Activation
        );
    }

}

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Icu_Ipw_GetInputState
* @details    Service that returns the state of the ICU driver
*
* @param[in]      nChannelNumber - The index of ICU channel for current configuration structure
*
* @return Icu_InputStateType
* @retval   ICU_ACTIVE          An active edge has been detected
* @retval   ICU_IDLE            No active edge has been detected since the cast call to
*                               Icu_Ipw_InitChannel or Icu_Ipw_GetInputState
*
*/
FUNC (Icu_InputStateType, ICU_CODE) Icu_Ipw_GetInputState
(
    VAR(Icu_ChannelType,                      AUTOMATIC) nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    P2CONST(Icu_Siul2_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pSiul2IpChConfig;
    P2CONST(Icu_Siul2_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pSiul2ChannelConfig;

    P2CONST(Icu_Wkpu_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pWkpuIpChConfig;
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pWkpuChannelConfig;
    VAR(Icu_InputStateType,             AUTOMATIC) tempReturn = ICU_IDLE;

    if (ICU_EMIOS_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        peMiosIpChConfig = pIpConfig->peMiosIpConfig;
        peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

        if (Icu_eMios_GetInputState((Icu_eMios_ChannelType)ICU_EMIOS_CHANNELS(nHardwareChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }

    else if (ICU_SIUL2_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pSiul2IpChConfig = pIpConfig->pSiul2IpConfig;
        pSiul2ChannelConfig = &(*pSiul2IpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pSiul2ChannelConfig->nHwChannel;

        if (Icu_Siul2_GetInputState((Icu_Siul2_ChannelType)ICU_IRQ_CHANNELS(nHardwareChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }

    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pWkpuIpChConfig = pIpConfig->pWkpuIpConfig;
        pWkpuChannelConfig = &(*pWkpuIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pWkpuChannelConfig->nHwChannel;

        if (Icu_Wkpu_GetInputState((Icu_Wkpu_ChannelType)ICU_WKPU_CHANNELS(nHardwareChannel)))
        {
            tempReturn = ICU_ACTIVE;
        }
    }
    return (tempReturn);
}
#endif  /* ICU_GET_INPUT_STATE_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief          Icu_Ipw_EnableEdgeDetection
* @details        Retrieve the number of edges
*
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
* @return         void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_EnableEdgeDetection
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    P2CONST(Icu_Siul2_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pSiul2IpChConfig;
    P2CONST(Icu_Siul2_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pSiul2ChannelConfig;

    P2CONST(Icu_Wkpu_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pWkpuIpChConfig;
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pWkpuChannelConfig;

    if (ICU_EMIOS_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        peMiosIpChConfig = pIpConfig->peMiosIpConfig;
        peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

        Icu_eMios_EnableEdgeDetection((Icu_eMios_ChannelType)ICU_EMIOS_CHANNELS(nHardwareChannel));
    }
    else if (ICU_SIUL2_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pSiul2IpChConfig = pIpConfig->pSiul2IpConfig;
        pSiul2ChannelConfig = &(*pSiul2IpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pSiul2ChannelConfig->nHwChannel;

        Icu_Siul2_EnableEdgeDetection((Icu_Siul2_ChannelType)ICU_IRQ_CHANNELS(nHardwareChannel));
    }
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pWkpuIpChConfig = pIpConfig->pWkpuIpConfig;
        pWkpuChannelConfig = &(*pWkpuIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pWkpuChannelConfig->nHwChannel;

        Icu_Wkpu_EnableEdgeDetection((Icu_Wkpu_ChannelType)ICU_WKPU_CHANNELS(nHardwareChannel));
    }
}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_EDGE_DETECT_API == STD_ON)
/**
* @brief      Icu_Ipw_DisableEdgeDetection
* @details    Retrieve the number of edges
*
* @param[in]      hwChannel - The index of ICU channel for current configuration structure
*
* @return         void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_DisableEdgeDetection
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    P2CONST(Icu_Siul2_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pSiul2IpChConfig;
    P2CONST(Icu_Siul2_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pSiul2ChannelConfig;

    P2CONST(Icu_Wkpu_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pWkpuIpChConfig;
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pWkpuChannelConfig;

    if (ICU_EMIOS_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        peMiosIpChConfig = pIpConfig->peMiosIpConfig;
        peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

        Icu_eMios_DisableEdgeDetection((Icu_eMios_ChannelType)ICU_EMIOS_CHANNELS(nHardwareChannel));
    }
    else if (ICU_SIUL2_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pSiul2IpChConfig = pIpConfig->pSiul2IpConfig;
        pSiul2ChannelConfig = &(*pSiul2IpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pSiul2ChannelConfig->nHwChannel;

        Icu_Siul2_DisableEdgeDetection((Icu_Siul2_ChannelType)ICU_IRQ_CHANNELS(nHardwareChannel));
    }
    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pWkpuIpChConfig = pIpConfig->pWkpuIpConfig;
        pWkpuChannelConfig = &(*pWkpuIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nHardwareChannel = (Icu_ChannelType)pWkpuChannelConfig->nHwChannel;

        Icu_Wkpu_DisableEdgeDetection((Icu_Wkpu_ChannelType)ICU_WKPU_CHANNELS(nHardwareChannel));
    }
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu_Ipw_StartSignalMeasurement
* @details    Starts the signal measurement service
*
* @param[in]      hwChannel     - The index of ICU channel for current configuration structure
* @param[in]      StartEdge     - Activation edge of the signal measurement
* @param[in]      MeasProperty  - the property that will be measured on the channel
* @param[in]      bDmaSupport   - Indicate DMA support
* @param[in]      bWithoutInterrupt - Measurement of ICU signal property without using interrupt
* @return void
*
*/
FUNC (void, ICU_CODE) Icu_Ipw_StartSignalMeasurement
(
    VAR(Icu_ChannelType,                  AUTOMATIC) nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig,
    VAR(Icu_ActivationType,                 AUTOMATIC) StartEdge,
    VAR(Icu_SignalMeasurementPropertyType,  AUTOMATIC) MeasProperty,
    VAR(boolean,                            AUTOMATIC) bDmaSupport
)
{
    VAR(Icu_eMios_ActivationType,       AUTOMATIC)                 Activation = EMIOS_RISING_EDGE;
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;
    VAR(boolean, AUTOMATIC) bWithoutInterrupt = (boolean)FALSE;

    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];

    /*Get eMios Hardware Channel */
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    bWithoutInterrupt = (boolean)peMiosChannelConfig->bSignalMeasure_WithoutInterrupt;
    /* Set Default Start Edge, signal can be start measured either by falling edge or
    rising edge */

    if (ICU_FALLING_EDGE == StartEdge)
    {
        Activation = EMIOS_FALLING_EDGE;
    }
    else if (ICU_RISING_EDGE == StartEdge)
    {
        Activation = EMIOS_RISING_EDGE;
    }
    else
    {
        Activation = EMIOS_BOTH_EDGES;
    }

    /* Start Signal Measurement */
    Icu_eMios_StartSignalMeasurement
    (
        (Icu_eMios_ChannelType)ICU_EMIOS_CHANNELS(nHardwareChannel),
        (Icu_eMios_ActivationType)Activation,
        (Icu_eMios_SignalMeasurementPropertyType)MeasProperty,
        (boolean)bDmaSupport,
        (boolean)bWithoutInterrupt
    );
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
FUNC (void, ICU_CODE) Icu_Ipw_StopSignalMeasurement
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    Icu_eMios_StopSignalMeasurement((Icu_eMios_ChannelType)nHardwareChannel);
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

FUNC (void, ICU_CODE) Icu_Ipw_PullUpNonBondedWakeupPin(void)
{
    Icu_Wkpu_PullUpNonBondedWakeupPin();
}

#if ((ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON))
FUNC (Icu_ChannelType, ICU_CODE) Icu_Ipw_ValidateGetInputLevel
(
    VAR         (Icu_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType, AUTOMATIC) nChannelInput;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    P2CONST(Icu_Siul2_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) pSiul2IpChConfig;
    P2CONST(Icu_Siul2_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  pSiul2ChannelConfig;

    P2CONST(Icu_Wkpu_IpConfigType,     AUTOMATIC, ICU_APPL_CONST)  pWkpuIpChConfig;
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)   pWkpuChannelConfig;

    if (ICU_EMIOS_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        peMiosIpChConfig = pIpConfig->peMiosIpConfig;
        peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nChannelInput = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;
    }

    else if (ICU_SIUL2_CHANNEL == (*pIpConfig->pIpChannelsConfig)[nChannelNumber].nChannelIp)
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pSiul2IpChConfig = pIpConfig->pSiul2IpConfig;
        pSiul2ChannelConfig = &(*pSiul2IpChConfig->pChannelsConfig)[u8IdxChConfig];
        nChannelInput = (Icu_ChannelType)pSiul2ChannelConfig->nHwChannel;
    }

    else
    {
        u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
        pWkpuIpChConfig = pIpConfig->pWkpuIpConfig;
        pWkpuChannelConfig = &(*pWkpuIpChConfig->pChannelsConfig)[u8IdxChConfig];
        nChannelInput = (Icu_ChannelType)pWkpuChannelConfig->nHwChannel;
    }

    return nChannelInput;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && (ICU_GET_INPUT_LEVEL_API == STD_ON */

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
FUNC (Std_ReturnType, ICU_CODE) Icu_Ipw_ValidateSignalMeasureWithoutInterrupt
(
    VAR         (Icu_ChannelType,  AUTOMATIC)                 nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    /* Variable to store the value returned by the function */
    VAR(Std_ReturnType, AUTOMATIC) Valid = (Std_ReturnType)E_OK;
    Valid = Icu_eMios_ValidateSignalMeasureWithoutInterrupt
          (
            (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig,
            pIpConfig->peMiosIpConfig
          );
    return Valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
FUNC(uint32, ICU_CODE)Icu_Ipw_GetStartAddress
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;
    VAR(uint32, AUTOMATIC) u32Saddress;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    u32Saddress =  Icu_eMios_GetStartAddress((Icu_eMios_ChannelType)nHardwareChannel);
    return (u32Saddress);
}
#endif

#if (ICU_TIMESTAMP_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ipw_StartTimestamp
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig,
    VAR(boolean,                              AUTOMATIC)      bDmaSupport
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    Icu_eMios_StartTimestamp((Icu_eMios_ChannelType)nHardwareChannel, (boolean)bDmaSupport);
}

FUNC(void, ICU_CODE) Icu_Ipw_StopTimestamp
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    Icu_eMios_StopTimestamp((Icu_eMios_ChannelType)nHardwareChannel);
}
#endif  /* ICU_TIMESTAMP_API == STD_ON */

#if (ICU_EDGE_COUNT_API == STD_ON)
FUNC(void, ICU_CODE) Icu_Ipw_ResetEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    Icu_eMios_ResetEdgeCount((Icu_eMios_ChannelType)nHardwareChannel);
}

FUNC(void, ICU_CODE) Icu_Ipw_EnableEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    Icu_eMios_EnableEdgeCount((Icu_eMios_ChannelType)nHardwareChannel);
}

FUNC(void, ICU_CODE) Icu_Ipw_DisableEdgeCount
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    Icu_eMios_DisableEdgeCount((Icu_eMios_ChannelType)nHardwareChannel);
}

FUNC(Icu_EdgeNumberType, ICU_CODE) Icu_Ipw_GetEdgeNumbers
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_EdgeNumberType,             AUTOMATIC)                 EdgeNumber;
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    EdgeNumber = Icu_eMios_GetEdgeNumbers((Icu_eMios_ChannelType)nHardwareChannel);
    return (EdgeNumber);
}
#endif  /* ICU_EDGE_COUNT_API == STD_ON */

#if ((ICU_EDGE_COUNT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON) || \
     (ICU_GET_TIME_ELAPSED_API == STD_ON) || (ICU_GET_DUTY_CYCLE_VALUES_API == STD_ON))
/*
 * @violates @ref Icu_Ipw_c_REF_4 Violates MISRA 2004 Required Rule 8.10 could be made static
 */
FUNC(boolean, ICU_CODE) Icu_Ipw_Get_Overflow
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(boolean,                        AUTOMATIC)                 bGetOverflow;
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    bGetOverflow = (boolean)Icu_eMios_GetOverflow((Icu_eMios_ChannelType)nHardwareChannel);
    return bGetOverflow;
}
#endif  /* ICU_EDGE_COUNT_API == STD_ON */

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
FUNC(Icu_LevelType, ICU_CODE) Icu_Ipw_GetInputLevel
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_LevelType,                  AUTOMATIC)                 InputLevel;
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    InputLevel = (Icu_LevelType)Icu_eMios_GetInputLevel((Icu_eMios_ChannelType)nHardwareChannel);
    return (InputLevel);
}
#endif   /* ICU_GET_INPUT_LEVEL_API == STD_ON */

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)))
FUNC(Icu_ValueType, ICU_CODE) Icu_Ipw_GetCaptureRegisterValue
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ValueType,                  AUTOMATIC)                 CaptureRegisterValue;
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    CaptureRegisterValue = (Icu_ValueType)Icu_eMios_GetCaptureRegisterValue((Icu_eMios_ChannelType)nHardwareChannel);
    return (CaptureRegisterValue);
}
#endif  /* (ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)) */

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
/*================================================================================================*/
/**
* @brief      This function changes the global prescaler.
* @details    This function sets the module prescalers based on the input mode.
*
* @param[in]  Icu_Ipw_GlobalConfiguration - The index of ICU channel for current
*                                            configuration structure
* @param[in]  Prescaler - Prescaler type ( Normal or Alternate )
*
* @return void
*/
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_Ipw_SetClockMode
(
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig,
    VAR(Icu_SelectPrescalerType,             AUTOMATIC) Prescaler
)
{
    /* Set ClockMode for eMios Channel */
    if (NULL_PTR != pIpConfig->peMiosIpConfig)
    {
        Icu_eMios_SetClockMode(
                                  pIpConfig->peMiosIpConfig,
                                  (Icu_eMios_SelectPrescalerType)Prescaler
                              );
    }

    /* Set ClockMode for Siul2 */
    if (NULL_PTR != pIpConfig->pSiul2IpConfig)
    {
        Icu_Siul2_SetClockMode(
                                  (Icu_Siul2_GlobalConfigurationType)(pIpConfig->pSiul2IpConfig->Icu_GlobalConfiguration),
                                  (Icu_Siul2_SelectPrescalerType)Prescaler
                              );
    }
}
#endif /* ICU_DUAL_CLOCK_MODE_API */

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
FUNC(void, ICU_CODE) Icu_Ipw_GetPulseWidth
(
    VAR(Icu_ChannelType,                      AUTOMATIC)      nChannelNumber,
    CONSTP2CONST(Icu_IpConfigType, AUTOMATIC, ICU_APPL_CONST) pIpConfig
)
{
    VAR(Icu_ChannelType,                AUTOMATIC)                 nHardwareChannel;
    VAR(uint8,                          AUTOMATIC)                 u8IdxChConfig;
    P2CONST(Icu_eMios_IpConfigType,     AUTOMATIC, ICU_APPL_CONST) peMiosIpChConfig;
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST)  peMiosChannelConfig;

    /*Get eMios Hardware Channel */
    u8IdxChConfig = (*pIpConfig->pIpChannelsConfig)[nChannelNumber].u8IdxChannelConfig;
    peMiosIpChConfig = pIpConfig->peMiosIpConfig;
    peMiosChannelConfig = &(*peMiosIpChConfig->pChannelsConfig)[u8IdxChConfig];
    nHardwareChannel = (Icu_ChannelType)peMiosChannelConfig->nHwChannel;

    Icu_eMios_GetPulseWidth((Icu_eMios_ChannelType)nHardwareChannel);
}
#endif /* (ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON) */

#define ICU_STOP_SEC_CODE
/*
* @violates @ref Icu_Ipw_c_REF_1 only preprocessor statements and
*        comments before "#include".
*/
/*
* @violates @ref Icu_Ipw_c_REF_2 precautions to prevent the contents
*        of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/** @} */

