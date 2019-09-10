/**
*     @file    Icu_Wkpu.c
*     @version 1.0.0
*
*     @brief   AUTOSAR Icu - WKPU source file support for ICU driver.
*     @details WKPU source file, containing the variables and functions that are exported by the WKPU driver.
*
*     @addtogroup ICU_MODULE
*     @{
*/
/*==================================================================================================
*     Project             : AUTOSAR 4.2 MCAL
*     Platform            : PA
*     Peripheral          : eMIOS SIUL2 WKPU
*     Dependencies        : none
*
*     Autosar Version     : 4.2.2
*     Autosar Revision    : ASR_REL_4_2_REV_0002
*     Autosar ConfVariant :
*     SWVersion           : 1.0.0
*     BuildVersion        : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217
*
*     (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
*     All Rights Reserved.
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Icu_WKPU_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include" MemMap.h/Icu_MemMap.h included after each section define in order to set the current memory section
*
* @section Icu_WKPU_c_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_WKPU_c_3
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
* registers or other hardware specific features.
*
* @section Icu_WKPU_c_4
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external
* identifiers.
* The defines are validated.
*
* @section Icu_WKPU_c_5
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section Icu_WKPU_c_6
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
* and an integral type.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
*
*/


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
*  1) system and project includes
*  2) needed interfaces from external units
*  3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "SchM_Icu.h"

#include "Icu_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

#include "Icu_Wkpu.h"
#include "Icu_Reg_eSys_Wkpu.h"

#include "Icu_Ipw_Types.h"
/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/
/**
* @{
* @brief          Source file version information
* */
#define ICU_WKPU_VENDOR_ID_C                  43
/* @violates @ref Icu_WKPU_c_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_WKPU_AR_RELEASE_MAJOR_VERSION_C   4
/* @violates @ref Icu_WKPU_c_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_WKPU_AR_RELEASE_MINOR_VERSION_C   2
/* @violates @ref Icu_WKPU_c_4 MISRA-C:2004 Rule 1.4: Identifier clash.*/
#define ICU_WKPU_AR_RELEASE_REVISION_VERSION_C  2

#define ICU_WKPU_SW_MAJOR_VERSION_C  1
#define ICU_WKPU_SW_MINOR_VERSION_C  0
#define ICU_WKPU_SW_PATCH_VERSION_C  0
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_WKPU_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_WKPU_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Wkpu.c and Mcal.h are different"
    #endif
#endif

/* Check if source file and Icu_Cfg header file are of the same vendor */
#if (ICU_WKPU_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_Wkpu.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_WKPU_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_WKPU_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_WKPU_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Wkpu.c are different"
#endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_WKPU_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_WKPU_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_WKPU_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_Wkpu.c are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((ICU_WKPU_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu.c and SilRegMacros.h are different"
#endif
#endif

/* Check if source file and Icu_Wkpu.h file are of the same vendor */
#if (ICU_WKPU_VENDOR_ID_C != ICU_WKPU_VENDOR_ID)
    #error "Icu_Wkpu.c and Icu_Wkpu.h have different vendor IDs"
#endif
/* Check if source file and Icu_Wkpu.h file are of the same Autosar version */
#if ((ICU_WKPU_AR_RELEASE_MAJOR_VERSION_C != ICU_WKPU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_MINOR_VERSION_C != ICU_WKPU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_REVISION_VERSION_C != ICU_WKPU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu.c and Icu_Wkpu.h are different"
#endif
/* Check if source file and Icu_Wkpu.h file are of the same Software version */
#if ((ICU_WKPU_SW_MAJOR_VERSION_C != ICU_WKPU_SW_MAJOR_VERSION) || \
     (ICU_WKPU_SW_MINOR_VERSION_C != ICU_WKPU_SW_MINOR_VERSION) || \
     (ICU_WKPU_SW_PATCH_VERSION_C != ICU_WKPU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Wkpu.c and Icu_Wkpu.h are different"
#endif

/* Check if source file and Icu_Reg_eSys_Wkpu.h file are of the same vendor */
#if (ICU_WKPU_VENDOR_ID_C != ICU_REG_ESYS_WKPU_VENDOR_ID)
    #error "Icu_Wkpu.c and Icu_Reg_eSys_Wkpu.h have different vendor IDs"
#endif
/* Check if source file and Icu_Reg_eSys_Wkpu.h file are of the same Autosar version */
#if ((ICU_WKPU_AR_RELEASE_MAJOR_VERSION_C != ICU_REG_ESYS_WKPU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_MINOR_VERSION_C != ICU_REG_ESYS_WKPU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_REVISION_VERSION_C != ICU_REG_ESYS_WKPU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu.c and Icu_Reg_eSys_Wkpu.h are different"
#endif
/* Check if source file and Icu_Reg_eSys_Wkpu.h header file are of the same Software version */
#if ((ICU_WKPU_SW_MAJOR_VERSION_C != ICU_REG_ESYS_WKPU_SW_MAJOR_VERSION) || \
     (ICU_WKPU_SW_MINOR_VERSION_C != ICU_REG_ESYS_WKPU_SW_MINOR_VERSION) || \
     (ICU_WKPU_SW_PATCH_VERSION_C != ICU_REG_ESYS_WKPU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Wkpu.c and Icu_Reg_eSys_Wkpu.h are different"
#endif

/* Check if source file and Icu_Reg_eSys_Wkpu.h file are of the same vendor */
#if (ICU_WKPU_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Wkpu.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Autosar version */
#if ((ICU_WKPU_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_WKPU_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_Wkpu.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Software version */
#if ((ICU_WKPU_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_WKPU_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_WKPU_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_Wkpu.c and Icu_Ipw_Types.h are different"
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
#define ICU_START_SEC_CODE
/* @violates @ref  Icu_WKPU_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before "#include"
*
* @violates @ref Icu_WKPU_c_2 precautions to prevent the contents
* of a header file being included twice
*/
#include "Icu_MemMap.h"

#if ((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_WKPU_EnableInterrupt(VAR(uint32, AUTOMATIC) u32ChannelMask);
#endif /*((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))*/

LOCAL_INLINE FUNC (void, ICU_CODE) Icu_WKPU_DisableInterrupt(VAR(uint32, AUTOMATIC) u32ChannelMask);
/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/


#if ((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))

/*==================================================================================================*/
/**
* @brief      Icu driver function that enables the interrupt of WKPU channel.
* @details    This function enables WKPU Channel Interrupt
*
* @param[in]  u32ChannelMask - Channel's Bit Mask
*
*/
/*==================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_WKPU_EnableInterrupt(VAR(uint32, AUTOMATIC) u32ChannelMask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_09();
    {
        /* Enable IRQ Interrupt */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(ICU_WKPU_IRER_ADDR32, u32ChannelMask);

        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(ICU_WKPU_WRER_ADDR32, u32ChannelMask);

        /* Clear ISR Flag */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(ICU_WKPU_WISR_ADDR32, u32ChannelMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_09();
}

#endif /*((ICU_SET_MODE_API == STD_ON) || (ICU_EDGE_DETECT_API == STD_ON))*/

/*==================================================================================================*/
/**
* @brief      Icu driver function that disables the interrupt of WKPU channel.
* @details    This function disables WKPU Channel Interrupt
*
* @param[in]  u32ChannelMask - Channel's Bit Mask
*
*/
/*==================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_WKPU_DisableInterrupt(VAR(uint32, AUTOMATIC) u32ChannelMask)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_10();
    {
        /* Disable IRQ Interrupt */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(ICU_WKPU_IRER_ADDR32, u32ChannelMask);

        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(ICU_WKPU_WRER_ADDR32, u32ChannelMask);

        /* Clear ISR Flag */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(ICU_WKPU_WISR_ADDR32, u32ChannelMask);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_10();
}

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================*/
/**
* @brief      Icu driver function that initializes WKPU channel.
* @details    This function:
*              - Disables IRQ Interrupt
*              - Sets Interrupt Filter Enable Register
*              - Sets Wakeup/Interrupt Pull-up Enable Register
*              - Sets Activation Condition
*
* @param[in]  ParamValue - Wake interrupt value
* @param[in]  HwChannel - Wake channel
*
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_Wkpu_Init
(
    P2CONST(Icu_Wkpu_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pWkpuIpConfig
)
{
    /* @brief Pointer to Wkpu channel specific configuration */
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pWkpuChannelConfig;

    VAR(Icu_Wkpu_ControlType, AUTOMATIC)   nCtrlRegVal;
    /* logical channel */
    VAR(Icu_Wkpu_ChannelType, AUTOMATIC)   nCounter;
    VAR(Icu_Wkpu_ChannelType, AUTOMATIC)   HwChannel;
    VAR(uint32,               AUTOMATIC)   u32ChannelMask;

    for (nCounter=0U; nCounter < pWkpuIpConfig->nNumChannels; nCounter++)
    {
        /* only handle WKPU channels */
        pWkpuChannelConfig = &(*pWkpuIpConfig->pChannelsConfig)[nCounter];
        nCtrlRegVal  = pWkpuChannelConfig->nControlValue;

        u32ChannelMask = (uint32)0U;
        HwChannel = (Icu_Wkpu_ChannelType)ICU_WKPU_CHANNELS(pWkpuChannelConfig->nHwChannel);
        u32ChannelMask = (uint32)1U << (uint32)(HwChannel);

        /* Disable IRQ Interrupt */
        Icu_WKPU_DisableInterrupt(u32ChannelMask);

        /* Set Interrupt Filter Enable Register */
        if (ICU_WKPU_INT_FILTER_ENABLE == ((nCtrlRegVal & ICU_WKPU_INT_FILTER_ENABLE_PARAM_MASK) >>  \
                                                            ICU_WKPU_INT_FILTER_ENABLE_PARAM_SHIFT))
        {
            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(ICU_WKPU_WIFER_ADDR32, u32ChannelMask);
        }
        else
        {
            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(ICU_WKPU_WIFER_ADDR32, u32ChannelMask);
        }

        /* Set Wakeup/Interrupt Pull-up Enable Register */
        if (ICU_WKPU_PULLUP_ENABLE == ((nCtrlRegVal & ICU_WKPU_PULLUP_ENABLE_PARAM_MASK) >> \
                                                          ICU_WKPU_PULLUP_ENABLE_PARAM_SHIFT))
        {
            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(ICU_WKPU_WIPUER_ADDR32, u32ChannelMask);
        }
        else
        {
            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(ICU_WKPU_WIPUER_ADDR32, u32ChannelMask);
        }

        /* Set Activation Condition */
        Icu_Wkpu_SetActivationCondition(
                                            HwChannel,
                                            (WKPU_ActivationType)pWkpuChannelConfig->nDefaultStartEdge
                                       );
    }
}

/*==================================================================================================*/
/**
* @brief      Icu driver function that initializes WKPU channel.
* @details    This function:
*              - Disables IRQ Interrupt
*              - Clears Wakeup/Interrupt Filter Enable Register
*              - Clears Wakeup/Interrupt Pull-up Enable Register
*              - Clears edge event enable registers
*              - Clear Interrupt Filter Enable Register
*
* @param[in]  HwChannel   - WKUP HW Channel
* @violates @ref Icu_WKPU_c_5 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_Wkpu_DeInit
(
    P2CONST(Icu_Wkpu_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) pWkpuIpConfig
)
{
    /* @brief Pointer to Wkpu channel specific configuration */
    P2CONST(Icu_Wkpu_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) pWkpuChannelConfig;

    /* logical channel */
    VAR(Icu_Wkpu_ChannelType, AUTOMATIC) nCounter;
    VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel;
    VAR(uint32,               AUTOMATIC) u32ChannelMask;

    for (nCounter=0U; nCounter < pWkpuIpConfig->nNumChannels; nCounter++)
    {
        /* only handle WKPU channels */
        pWkpuChannelConfig = &(*pWkpuIpConfig->pChannelsConfig)[nCounter];

        u32ChannelMask = (uint32)0U;
        HwChannel = (Icu_Wkpu_ChannelType)ICU_WKPU_CHANNELS(pWkpuChannelConfig->nHwChannel);
        u32ChannelMask = (uint32)1U << (uint32)(HwChannel);

        /* Disable IRQ Interrupt */
        Icu_WKPU_DisableInterrupt(u32ChannelMask);

        /* Clear Wakeup/Interrupt Filter Enable Register  */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(ICU_WKPU_WIFER_ADDR32, u32ChannelMask);

        /* Clear Wakeup/Interrupt Pull-up Enable Register */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(ICU_WKPU_WIPUER_ADDR32, u32ChannelMask);

        /* Clear edge event enable registers */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(ICU_WKPU_WIREER_ADDR32, u32ChannelMask);

        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(ICU_WKPU_WIFEER_ADDR32, u32ChannelMask);

        /* Clear Interrupt Filter Enable Register */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_CLEAR32(ICU_WKPU_WIFER_ADDR32, u32ChannelMask);
    }
}

#if (ICU_SET_MODE_API == STD_ON)
/*==================================================================================================*/
/**
* @brief      Icu driver function that sets WKPU channel to SLEEP mpde
* @details    This function enables the interrupt for WKUP channel if wakeup is enabled for the channel
*
* @param[in]  HwChannel       - IRQ HW Channel
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_Wkpu_SetSleepMode(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel)
{

    CONST(uint32, ICU_CONST) u32ChannelMask = (uint32)1U << (uint32)(HwChannel);

    /* Disable IRQ Interrupt */
    Icu_WKPU_DisableInterrupt(u32ChannelMask);
}

/*==================================================================================================*/
/**
* @brief      Icu driver function that sets WKPU channel to NORMAL mpde
* @details    This function enables the interrupt for WKUP channel if Notifcation is enabled
*             for the channel
*
* @param[in]  HwChannel IRQ HW Channel
*
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_Wkpu_SetNormalMode(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel)
{
    CONST(uint32, ICU_CONST) u32ChannelMask = (uint32)1U << (uint32)(HwChannel);

    /* Enable IRQ Interrupt */
    Icu_WKPU_EnableInterrupt(u32ChannelMask);
}
#endif  /* ICU_SET_MODE_API */
/*==================================================================================================*/
/**
* @brief      Icu driver function that sets activation condition of WKUP channel
* @details    This function enables the requested activation condition(rising, falling or both edges)
*             for corresponding WKPU channels.
*
* @param[in]  HwChannel - Wake up hardware channel
* @param[in]  Activation - activation condition
*
*/
/*==================================================================================================*/
FUNC (void, ICU_CODE) Icu_Wkpu_SetActivationCondition
(
    VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel,
    VAR(WKPU_ActivationType,  AUTOMATIC) Activation
)
{
    CONST(uint32, ICU_CONST) u32ChannelMask = (uint32)1U << (uint32)(HwChannel);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_11();
    switch (Activation)
    {
        case WKPU_RISING_EDGE:
        {
            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(ICU_WKPU_WIREER_ADDR32, u32ChannelMask);

            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(ICU_WKPU_WIFEER_ADDR32, u32ChannelMask);
        }
        break;

        case WKPU_FALLING_EDGE:
        {
            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(ICU_WKPU_WIREER_ADDR32, u32ChannelMask);

            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(ICU_WKPU_WIFEER_ADDR32, u32ChannelMask);
        }
        break;

        default:
        {
            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(ICU_WKPU_WIREER_ADDR32, u32ChannelMask);

            /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(ICU_WKPU_WIFEER_ADDR32, u32ChannelMask);
        }
        break;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_11();
}
#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu_Wkpu_DisableEdgeDetection
 * @details    WKPU IP function that stops the edge detection service for an WKPU channel
 *
 * @param[in]      HwChannel   - WKPU encoded hardware channel
 *
 * @return void
 *
*/
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Wkpu_DisableEdgeDetection(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel)
{
    CONST(uint32, ICU_CONST) u32ChannelMask = (uint32)1U << (uint32)(HwChannel);

    /* Disable IRQ Interrupt */
    Icu_WKPU_DisableInterrupt(u32ChannelMask);
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu_Wkpu_EnableEdgeDetection
 * @details    WKPU IP function that starts the edge detection service for an WKPU channel
 *
 * @param[in]      HwChannel   - WKPU encoded hardware channel
 *
 * @return void
 *
 */
/*================================================================================================*/
FUNC (void, ICU_CODE) Icu_Wkpu_EnableEdgeDetection(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel)
{
    CONST(uint32, ICU_CONST) u32ChannelMask = (uint32)1U << (uint32)(HwChannel);

    /* Enable IRQ Interrupt */
    Icu_WKPU_EnableInterrupt(u32ChannelMask);
}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_GET_INPUT_STATE_API == STD_ON)
/*==================================================================================================*/
/**
* @brief      Icu driver function that gets the input state of WKPU channel.
* @details    This function:
*             - Checks if interrupt flags for corresponding WKPU channel is set then
*             it clears the interrupt flag and returns the value as true.
*
* @param[in]  HwChannel - IRQ HW Channel
*
* @return     boolean
*              - true - if channel is active
*              - false - If channel is in idle
*
*/
/*==================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_Wkpu_GetInputState(VAR(Icu_Wkpu_ChannelType, AUTOMATIC) HwChannel)
{
    VAR(boolean, AUTOMATIC) status = (boolean) FALSE;
    VAR(uint32,  AUTOMATIC) u32ChannelMask;
    VAR(uint32,  AUTOMATIC) u32regWkpuWISR;
    VAR(uint32,  AUTOMATIC) u32regWkpuIRER;

    u32ChannelMask = (uint32)(BIT0 << HwChannel);

    /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32regWkpuWISR  = REG_BIT_GET32(ICU_WKPU_WISR_ADDR32, u32ChannelMask);

    /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32regWkpuIRER = REG_BIT_GET32(ICU_WKPU_IRER_ADDR32, u32ChannelMask);

    /* Interrupt condition activated (WISR), interrupt not enabled (IRER) */
    if ((0x0U != u32regWkpuWISR) && (0x0U == u32regWkpuIRER))
    {
        /* Clear ISR Flag */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(ICU_WKPU_WISR_ADDR32, u32ChannelMask);
        status = (boolean)TRUE;
    }

    return status;
}
#endif  /* ICU_GET_INPUT_STATE_API */

FUNC (void, ICU_CODE) Icu_Wkpu_PullUpNonBondedWakeupPin(void)
{
         VAR(uint32, AUTOMATIC) u32regWIPUER;

        /*Read current value of WIPUER register*/
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32regWIPUER = REG_READ32(ICU_WKPU_WIPUER_ADDR32);

        /*OR-ed with the current value of WIPUER register with ICU_WKUP_PULLUP_MASK_U32 */
        u32regWIPUER |= ICU_WKUP_PULLUP_MASK_U32;

        /* Rewirte WIPUER register */
        /** @violates @ref Icu_WKPU_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_WKPU_c_6 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(ICU_WKPU_WIPUER_ADDR32, u32regWIPUER);
}

#define ICU_STOP_SEC_CODE
/* @violates @ref  Icu_WKPU_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements and
* comments before "#include"
*
* @violates @ref Icu_WKPU_c_2 precautions to prevent the contents
* of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/**@}*/
