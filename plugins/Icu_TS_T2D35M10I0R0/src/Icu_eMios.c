/**
*   @file    Icu_eMios.c
*   @implements    Icu_eMios_unit
*   @version 1.0.0
*
*   @brief   AUTOSAR Icu - Brief file description (one line).
*   @details Detailed file description (can be multiple lines).
*
*   @addtogroup ICU_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMIOS SIUL2 WKPU
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
* @section Icu_eMios_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Icu_eMios_c_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to prevent
* the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_eMios_c_3
* Violates MISRA 2004 Required Rule 11.1, Cast from unsigned long to pointer
*
* @section Icu_eMios_c_4
* Violates MISRA 2004 Required Rule 13.7, Boolean operations whose results are invariant shall not
* be permitted.
*
* @section Icu_eMios_c_5
* Violates MISRA 2004 Required Rule 8.10, external ... could be made static
* The respective code could not be made static because of layers architecture design of the driver.
*
* @section Icu_eMios_c_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function.
*
* @section Icu_eMios_c_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
* and an integral type.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars
* for identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects
* and functions shall not be reused. The driver needs to use defines starting with letter E
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external
* identifiers.
*
*/


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include "Std_Types.h"
#include "SchM_Icu.h"

#include "Icu_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

#include "Icu_Ipw_Types.h"
#include "Icu_eMios.h"
#include "Icu_Ipw_Irq.h"

#include "eMios_Common.h"
#include "eMios_Common_Types.h"

/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/

#define ICU_EMIOS_VENDOR_ID_C                       43
#define ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C        4
#define ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C        2
#define ICU_EMIOS_AR_RELEASE_REVISION_VERSION_C     2
#define ICU_EMIOS_SW_MAJOR_VERSION_C                1
#define ICU_EMIOS_SW_MINOR_VERSION_C                0
#define ICU_EMIOS_SW_PATCH_VERSION_C                0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

/* Check if header file and Std_Types.h file are of the same Autosar version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != STD_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C != STD_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_eMios.c and Std_Types.h are different"
    #endif
#endif

/* Check if source file and ICU configuration header file are of the same vendor */
#if (ICU_EMIOS_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_eMios.c and Icu_Cfg.h have different vendor IDs"
#endif
    /* Check if header file and ICU configuration header file are of the same Autosar version */
#if ((ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_EMIOS_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
#error "AutoSar Version Numbers of Icu_eMios.c and Icu_Cfg.h are different"
#endif
/* Check if header file and ICU configuration header file are of the same software version */
#if ((ICU_EMIOS_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_EMIOS_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_EMIOS_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
#error "Software Version Numbers of Icu_eMios.c and Icu_Cfg.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_eMios.c and SilRegMacros.h are different"
    #endif
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_EMIOS_VENDOR_ID_C != ICU_EMIOS_VENDOR_ID)
    #error "Icu_eMios.c and Icu_eMios.h have different vendor IDs"
#endif


/* Check if source file and Icu_eMios header file are of the same Autosar version */
#if (  (ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != ICU_EMIOS_AR_RELEASE_MAJOR_VERSION) || \
       (ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C != ICU_EMIOS_AR_RELEASE_MINOR_VERSION) || \
       (ICU_EMIOS_AR_RELEASE_REVISION_VERSION_C != ICU_EMIOS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_eMios.c and Icu_eMios.h are different"
#endif


/* Check if source file and Icu_eMIOS header file are of the same Software version */
#if ((ICU_EMIOS_SW_MAJOR_VERSION_C != ICU_EMIOS_SW_MAJOR_VERSION) || \
        (ICU_EMIOS_SW_MINOR_VERSION_C != ICU_EMIOS_SW_MINOR_VERSION) || \
        (ICU_EMIOS_SW_PATCH_VERSION_C != ICU_EMIOS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_eMios.c and Icu_eMios.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_EMIOS_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_eMios.c and Icu_Ipw_Types.h have different vendor IDs"
#endif


/* Check if source file and Icu_eMios header file are of the same Autosar version */
#if (  (ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
       (ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
       (ICU_EMIOS_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_eMios.c and Icu_Ipw_Types.h are different"
#endif


/* Check if source file and Icu_eMIOS header file are of the same Software version */
#if ((ICU_EMIOS_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
        (ICU_EMIOS_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
        (ICU_EMIOS_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_eMios.c and Icu_Ipw_Types.h are different"
#endif

/* Check if source file and ICU header file are of the same vendor */
#if (ICU_EMIOS_VENDOR_ID_C != ICU_IPW_IRQ_VENDOR_ID)
    #error "Icu_eMios.c and Icu_Ipw_Irq.h have different vendor IDs"
#endif


/* Check if source file and Icu_eMios header file are of the same Autosar version */
#if (  (ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
       (ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
       (ICU_EMIOS_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_eMios.c and Icu_Ipw_Irq.h are different"
#endif


/* Check if source file and Icu_eMIOS header file are of the same Software version */
#if ((ICU_EMIOS_SW_MAJOR_VERSION_C != ICU_IPW_IRQ_SW_MAJOR_VERSION) || \
        (ICU_EMIOS_SW_MINOR_VERSION_C != ICU_IPW_IRQ_SW_MINOR_VERSION) || \
        (ICU_EMIOS_SW_PATCH_VERSION_C != ICU_IPW_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_eMios.c and Icu_Ipw_Irq.h are different"
#endif

/* Check if source file and eMios_Common.h are of the same vendor */
#if (ICU_EMIOS_VENDOR_ID_C != EMIOS_COMMON_VENDOR_ID )
    #error "Icu_eMios.c and eMios_Common.h have different vendor ids"
#endif

/* Check if source file and eMios_Common.h are of the same Autosar version */
#if ((ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != EMIOS_COMMON_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C != EMIOS_COMMON_AR_RELEASE_MINOR_VERSION) || \
        (ICU_EMIOS_AR_RELEASE_REVISION_VERSION_C != EMIOS_COMMON_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_eMios.c and eMios_Common.h are different"
#endif

/* Check if source file and eMios_Common.h are of the same software version */
#if ((ICU_EMIOS_SW_MAJOR_VERSION_C != EMIOS_COMMON_SW_MAJOR_VERSION) || \
        (ICU_EMIOS_SW_MINOR_VERSION_C != EMIOS_COMMON_SW_MINOR_VERSION)  || \
        (ICU_EMIOS_SW_PATCH_VERSION_C != EMIOS_COMMON_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_eMios.c and eMios_Common.h are different"
#endif

/* Check if source file and eMios_Common_Type.h are of the same vendor */
#if (ICU_EMIOS_VENDOR_ID_C != EMIOS_COMMON_TYPES_VENDOR_ID )
    #error "Icu_eMios.c and eMios_Common_Types.h have different vendor ids"
#endif

/* Check if source file and eMios_Common_Type.h are of the same Autosar version */
#if ((ICU_EMIOS_AR_RELEASE_MAJOR_VERSION_C != EMIOS_COMMON_TYPES_AR_RELEASE_MAJOR_VERSION) || \
        (ICU_EMIOS_AR_RELEASE_MINOR_VERSION_C != EMIOS_COMMON_TYPES_AR_RELEASE_MINOR_VERSION) || \
        (ICU_EMIOS_AR_RELEASE_REVISION_VERSION_C != EMIOS_COMMON_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_eMios.c and eMios_Types_Common.h are different"
#endif

/* Check if source file and eMios_Common_Type.h are of the same software version */
#if ((ICU_EMIOS_SW_MAJOR_VERSION_C != EMIOS_COMMON_TYPES_SW_MAJOR_VERSION) || \
        (ICU_EMIOS_SW_MINOR_VERSION_C != EMIOS_COMMON_TYPES_SW_MINOR_VERSION)  || \
        (ICU_EMIOS_SW_PATCH_VERSION_C != EMIOS_COMMON_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_eMios.c and eMios_Common_Types.h are different"
#endif


/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
typedef uint32 Icu_eMios_ChConfigType;

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/
#define ICU_EMIOS_MEAS_MODE_MASK            ((uint16)(BIT8|BIT7|BIT6|BIT5|BIT4))
#define ICU_EMIOS_MEAS_MODE_SHIFT           (4U)

#define ICU_EMIOS_MEAS_PROPERTY_MASK        ((uint16)(BIT3|BIT2|BIT1|BIT0))
#define ICU_EMIOS_MEAS_PROPERTY_SHIFT       (0U)

#define ICU_EMIOS_CH_INITIALIZED_MASK       ((uint16)BIT9)

#define ICU_EMIOS_OPERATION_MODE_MASK       ((uint16)(BIT13|BIT12|BIT11|BIT10))
#define ICU_EMIOS_OPERATION_MODE_SHIFT      (10U)

#define ICU_EMIOS_BUS_CHANNEL_MASK          ((uint16)(BIT15|BIT14))
#define ICU_EMIOS_BUS_CHANNEL_SHIFT         (14U)



/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Icu_eMios_c_2 Only preprocessor statements and comments before "#include"
 ** @violates @ref Icu_eMios_c_1 only preprocessor statements and comments before "#include" */
#include "Icu_MemMap.h"
static VAR(Icu_eMios_ChConfigType, ICU_VAR) Icu_eMios_aChConfig[ICU_MAX_EMIOS_CHANNELS];

#if (ICU_EDGE_COUNT_API == STD_ON)
/** @violates @ref Icu_eMios_c_6 Objects shall be defined at block scope */
static VAR(uint32, ICU_VAR) Icu_aEdgeCurrent_Value[ICU_MAX_EMIOS_CHANNELS];
#endif /* ICU_EDGE_COUNT_API == STD_ON */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
static VAR(Icu_ValueType, ICU_VAR) Icu_aInt_Counter[ICU_MAX_EMIOS_CHANNELS];
static VAR(Icu_ValueType, ICU_VAR) Icu_CapturedActivePulseWidth[ICU_MAX_EMIOS_CHANNELS];
static VAR(Icu_ValueType, ICU_VAR) Icu_TimeStart[ICU_MAX_EMIOS_CHANNELS];
#endif /* ICU_SIGNAL_MEASUREMENT_API == STD_ON */

#if (ICU_TIMESTAMP_API == STD_ON)
static VAR(Icu_ValueType,ICU_VAR) Icu_eMios_aBufferPtr[ICU_MAX_EMIOS_CHANNELS];
#endif /* ICU_TIMESTAMP_API == STD_ON */

#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/** @violates @ref Icu_eMios_c_2 Only preprocessor statements and comments before "#include"
 ** @violates @ref Icu_eMios_c_1 only preprocessor statements and comments before "#include" */
#include "Icu_MemMap.h"
/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_SetPrescaler
(
    CONST(Icu_eMios_ChannelType,                AUTOMATIC) nHwChannel,
    CONST(uint32,                               AUTOMATIC) u32ChannelPrescaler
);
#endif  /* ICU_DUAL_CLOCK_MODE_API == STD_ON */
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/** @violates @ref Icu_eMios_c_2 Only preprocessor statements and comments before "#include"
 ** @violates @ref Icu_eMios_c_1 only preprocessor statements and comments before "#include" */
#include "Icu_MemMap.h"

/**
* @brief      Icu_eMios_SetChConfig
* @details    Set the Icu_eMios_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      nHwChannel  - The index of ICU channel for current configuration structure
* @param[in]      nMask    - bitfield mask
*
* @return void
*
*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_SetChConfig
(
    VAR(Icu_eMios_ChannelType,      AUTOMATIC) nHwChannel,
    VAR(Icu_eMios_ChConfigType,     AUTOMATIC) nMask
)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_13();
    Icu_eMios_aChConfig[nHwChannel] |= nMask;
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_13();
}


/**
* @brief      Icu_eMios_ClearChConfig
* @details    Clear the Icu_eMios_aChConfig bitfield specified by mask parameter in an atomic way.
*
* @param[in]      nHwChannel  - The index of ICU channel for current configuration structure
* @param[in]      nMask    - bitfield mask
*
* @return void
*
*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_ClearChConfig
(
    VAR(Icu_eMios_ChannelType,      AUTOMATIC) nHwChannel,
    VAR(Icu_eMios_ChConfigType,     AUTOMATIC) nMask
)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_14();
    Icu_eMios_aChConfig[nHwChannel]  &= ((Icu_eMios_ChConfigType)(~nMask));
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_14();
}


/**
 * @brief      Icu_eMios_GetChConfig
 * @details    Return the Icu_eMios_aChConfig bitfield specified by mask parameter in an atomic way.
 *
 * @param[in]      nHwChannel  - The index of ICU channel for current configuration structure
 * @param[in]      nMask    - bitfield mask
 * @return         Bitfield specified by mask parameter
 */
LOCAL_INLINE FUNC(Icu_eMios_ChConfigType, ICU_CODE) Icu_eMios_GetChConfig
(
    VAR(Icu_eMios_ChannelType,      AUTOMATIC) nHwChannel,
    VAR(Icu_eMios_ChConfigType,     AUTOMATIC) nMask
)
{
    return (Icu_eMios_aChConfig[nHwChannel]  & nMask);
}

#if ((ICU_TIMESTAMP_API == STD_ON) || (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
/**
* @brief      Icu_eMios_GetCaptureRegA
* @details    This function returns the register A of the given eMIOS Unified Channel
* @param[in]  nHwChannel  - eMIOS encoded hardware channel
* @return     uint32 - Captured value of the register A
*
* @api
* @violates @ref Icu_eMios_c_5 external ... could be made static
*/

LOCAL_INLINE FUNC(uint32, ICU_CODE) Icu_eMios_GetCaptureRegA
(
    VAR(Icu_eMios_ChannelType,      AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    return REG_READ32(EMIOS_CADR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx));
}
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu_eMios_GetCaptureRegB
* @details    This function returns the register B of the given eMIOS Unified Channel
* @param[in]  nHwChannel  - eMIOS encoded hardware channel
* @return     uint32 - Captured value of the register B
*
* @api
* @violates @ref Icu_eMios_c_5 external ... could be made static
*/

LOCAL_INLINE FUNC(uint32, ICU_CODE) Icu_eMios_GetCaptureRegB
(
    CONST(Icu_eMios_ChannelType,    AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    return REG_READ32(EMIOS_CBDR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx));
}

#endif

/**
* @brief      Icu_eMios_GetStatusFlags
* @details    Returns the flags set only for the enabled interrupts
*
* @param[in]   nHwChannel - eMIOS Hardware Channel
*
* @return      uint32 - Flags set for enabled interrupts
*
* */
LOCAL_INLINE FUNC(uint32, ICU_CODE) Icu_eMios_GetStatusFlags
(
    VAR(Icu_eMios_ChannelType,      AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(nHwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(nHwChannel);
    VAR(uint32, ICU_CODE) u32Flags;

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Flags = REG_READ32(EMIOS_CSR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx));

    return u32Flags;
}


/**
* @brief      Icu_eMios_ClearStatusFlags
* @details    Clear the flags set only for selected interrupts that are enabled
*
* @param[in]      nHwChannel    - eMIOS Hardware Channel
* @param[in]      u32BitMask   - flags to be cleared
*
* @return void
*
* */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_ClearStatusFlags
(
    VAR(Icu_eMios_ChannelType,      AUTOMATIC) nHwChannel,
    VAR(uint32,                     AUTOMATIC) u32BitMask
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)EMIOS_MODULE_INDEX_U8(nHwChannel);
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)EMIOS_CHANNEL_INDEX_U8(nHwChannel);

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /* Clear pending interrupt serviced */
    REG_WRITE32\
    (\
        EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx),\
        u32BitMask & (uint32)(CSR_OVR_BIT_U32 | CSR_OVFL_BIT_U32 | CSR_FLAG_BIT_U32)\
    );
}

/**
* @brief      Icu_eMios_EnableInterrupt
* @details    This function Clears the pending interrupts of eMIOS channels and
*             enables eMIOS Channel interrupt
*
* @param[in]  u8ModuleIdx  - eMIOS module index
* @param[in]  u8ChannelIdx - eMIOS Channel index
* @api
*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_EnableInterrupt
(
    CONST(uint8,                    AUTOMATIC) u8ModuleIdx,
    CONST(uint8,                    AUTOMATIC) u8ChannelIdx
)
{
    /* Clear pending flag */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_15();
    /* Enable interrupt */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_15();
}


/*================================================================================================*/
/**
* @brief      Icu_eMios_DisableInterrupt
* @details    This function disables eMIOS Channel interrupt
*
* @param[in]  u8ModuleIdx -  eMIOS module index
* @param[in]  u8ChannelIdx - eMIOS Channel index
* @api
*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_DisableInterrupt
(
    CONST(uint8,                    AUTOMATIC) u8ModuleIdx,
    CONST(uint8,                    AUTOMATIC) u8ChannelIdx
)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_16();
    /* Disable interrupt */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_16();
}


/*================================================================================================*/
/**
* @brief      Icu_eMios_UCSetMode
* @details    This function sets CCR_MODE bitfield, the mode of operation of the Unified Channel
*
* @param[in]  u8ModuleIdx  - eMIOS module index
* @param[in]  u8ChannelIdx - eMIOS Channel index
* @param[in]  u32Mode  - CCR_MODE bitfield value to be set
* @api
*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_UCSetMode
(
    CONST(uint8,                AUTOMATIC) u8ModuleIdx,
    CONST(uint8,                AUTOMATIC) u8ChannelIdx,
    CONST(uint32,               AUTOMATIC) u32Mode
)
{
    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_17();
    /* Clear MODE bitfield - GPIO mode */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_MODE_MASK_U32);

    /* Set desired mode */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), u32Mode & CCR_MODE_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_17();
}


/**
* @brief      Icu driver function that checks the overflow flag
* @details    This function returns true if the overflow flag is set
*
* @param[in]  u32Flags - the flags to be checked
*
* @return     boolean
* @retval     true -  if the parameter's value contains overflow flag
* @retval     false - if the parameter's value doesnot contains overflow flag
*
* @api
*/

LOCAL_INLINE FUNC (boolean, ICU_CODE) Icu_eMios_CheckOverflowFlag
(
    CONST(uint32,               AUTOMATIC) u32Flags
)
{
    return ((CSR_OVFL_BIT_U32 == (u32Flags & CSR_OVFL_BIT_U32)) ? (boolean)TRUE : (boolean)FALSE);
}
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu driver function that checks the overflow flag
* @details    This function returns clock mode of channel
*
* @param[in]  nHwChannel - hardware channel eMIOS
*
* @return     uint32
*
* @api
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (uint32, ICU_CODE) Icu_eMios_GetChannelClockMode
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
    VAR(uint32, AUTOMATIC) u32ChannelClockMode;

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32ChannelClockMode = \
        REG_READ32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx)) & CCR_MODE_MASK_U32;

    return u32ChannelClockMode;
}
#endif
/*================================================================================================*/
/**
* @brief   Function to return the channel id of master bus of current channel
* @details Function to return the channel id of master bus of current channel
* @param[in] u8mIdx  - the index of module
* @param[in] u8chIdx - the index of unified channel
* @param[out]  - The id of master bus
*/
/*================================================================================================*/
LOCAL_INLINE FUNC(Icu_eMios_ChannelType, ICU_CODE) Icu_eMios_GetMasterBus
(
    VAR(Icu_eMios_ChannelType, AUTOMATIC) u8ModuleIdx,
    VAR(Icu_eMios_ChannelType, AUTOMATIC) u8ChannelIdx,
    VAR(uint32 ,               AUTOMATIC) u32Bus
)
{
    VAR(Icu_eMios_ChannelType, AUTOMATIC) n8MasterBusIdx = (Icu_eMios_ChannelType)0;
    if (EMIOS_BUS_DIVERSE == u32Bus)
    {
        if (EMIOS_CHANNEL_7 >= u8ChannelIdx) /* bus B */
        {
            n8MasterBusIdx = (Icu_eMios_ChannelType)(((uint32)u8ModuleIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0);
        }
        else if (EMIOS_CHANNEL_15 >= u8ChannelIdx) /* Bus C */
        {
            n8MasterBusIdx = (Icu_eMios_ChannelType)(((uint32)u8ModuleIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8);
        }
        else if (EMIOS_CHANNEL_23 >= u8ChannelIdx) /* bus D */
        {
            n8MasterBusIdx = (Icu_eMios_ChannelType)(((uint32)u8ModuleIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16);
        }
        else /* Bus E remaining */
        {
            n8MasterBusIdx = (Icu_eMios_ChannelType)(((uint32)u8ModuleIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24);
        }
    }
    else if (EMIOS_BUS_A == u32Bus) /* bus A */
    {
        n8MasterBusIdx = (Icu_eMios_ChannelType)(((uint32)u8ModuleIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_23);
    }
    else if (EMIOS_BUS_F == u32Bus) /* bus F remaining */
    {
        n8MasterBusIdx = (Icu_eMios_ChannelType)(((uint32)u8ModuleIdx<<EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_22);
    }
    else
    {
        /*Empty else to fix misra*/
    }
    return n8MasterBusIdx;
}
#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
 @brief      This function is used to read the period values for channels
 @details    This function returns the Counter Value based on the configuration
 @param[in]  nHwChannel - hardware channel eMIOS
 @pre        Icu_Init must be called before.
*/
/*================================================================================================*/
LOCAL_INLINE FUNC (uint32, ICU_CODE) Icu_eMios_ReadCounterBus
(
    CONST(Icu_eMios_ChannelType,        AUTOMATIC) nHwChannel
)
{
    VAR(uint32,     AUTOMATIC) u32Period = (uint32)0u;

    CONST(uint8,    ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8,    ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
    VAR(uint32,     AUTOMATIC) u32BusChannelClockMode = (uint32)0u;
    VAR(Icu_eMios_ChannelType, AUTOMATIC) nChGeneratingEmiosBusA = (Icu_eMios_ChannelType)0u;
    VAR(uint32,                AUTOMATIC) u32ChGeneratingEmiosBusAClockMode = (uint32)0u;
    VAR(Icu_eMios_ChannelType, AUTOMATIC) nChGeneratingEmiosBusF = (Icu_eMios_ChannelType)0u;
    VAR(uint32,                AUTOMATIC) u32ChGeneratingEmiosBusFClockMode = (uint32)0u;

    /* Get eMiosBus of hardware channel */
    VAR(uint32, AUTOMATIC) u32ChannelEmiosBus = \
        (uint32)(Icu_eMios_GetChConfig
                    (nHwChannel,ICU_EMIOS_BUS_CHANNEL_MASK) >> ICU_EMIOS_BUS_CHANNEL_SHIFT
                );

    switch (u32ChannelEmiosBus)
    {
        case EMIOS_BUS_INTERNAL_COUNTER:
        {
            u32Period = EMIOS_COUNTER_MASK;
        }
        break;

        case EMIOS_BUS_DIVERSE:
        {
            if (EMIOS_CHANNEL_7 >= u8ChannelIdx  )
            {
                u32BusChannelClockMode = \
                        Icu_eMios_GetChannelClockMode((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0);
                /* eMIOS Counter Bus_B Channel (EMIOS_CHANNEL_0) is in Modulous counter buffer or
                Modulous counter mode */
                if ((CCR_MCB_MODE_U32 == u32BusChannelClockMode) || (CCR_MC_MODE_U32 == u32BusChannelClockMode))
                {
                    u32Period= (uint32) \
                            Icu_eMios_GetCaptureRegA((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0);
                }
                else
                {
                    u32Period= (uint32) \
                            Icu_eMios_GetCaptureRegB((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_0);
                }
            }

            /* eMIOS Channel configured is using Counter Bus_C */
            else if ((EMIOS_CHANNEL_8 <= u8ChannelIdx  ) && (EMIOS_CHANNEL_15 >= u8ChannelIdx))
            {
                u32BusChannelClockMode = \
                        Icu_eMios_GetChannelClockMode((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8);
                /* eMIOS Counter Bus_C Channel (EMIOS_CHANNEL_8) is in Modulous counter buffer or
                 Modulous counter mode */
                if ((CCR_MCB_MODE_U32 == u32BusChannelClockMode) || (CCR_MC_MODE_U32 == u32BusChannelClockMode))
                {
                    u32Period= (uint32) \
                            Icu_eMios_GetCaptureRegA((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8);
                }
                else
                {
                    u32Period= (uint32) \
                            Icu_eMios_GetCaptureRegB((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_8);
                }
            }

            /* eMIOS Channel configured is using Counter Bus_D */
            else if ((EMIOS_CHANNEL_16 <= u8ChannelIdx) && (EMIOS_CHANNEL_23 >= u8ChannelIdx ))
            {
                u32BusChannelClockMode = \
                        Icu_eMios_GetChannelClockMode((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16);
                /* eMIOS Counter Bus_D Channel (EMIOS_CHANNEL_16) is in Modulous counter buffer or
                 Modulous counter mode */
                if ((CCR_MCB_MODE_U32 == u32BusChannelClockMode) || (CCR_MC_MODE_U32 == u32BusChannelClockMode))
                {
                    u32Period= (uint32) \
                        Icu_eMios_GetCaptureRegA((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16);
                }
                else
                {
                    u32Period= (uint32) \
                        Icu_eMios_GetCaptureRegB((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_16);
                }
            }

            /* eMIOS Channel configured is using Counter Bus_E */
            else if ((EMIOS_CHANNEL_24  <= u8ChannelIdx) && (EMIOS_CHANNEL_31  >= u8ChannelIdx))
            {
                u32BusChannelClockMode = \
                    Icu_eMios_GetChannelClockMode((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24);
                /* eMIOS Counter Bus_E Channel (EMIOS_CHANNEL_24) is in Modulous counter buffer or
                 Modulous counter mode */
                if ((CCR_MCB_MODE_U32 == u32BusChannelClockMode) || (CCR_MC_MODE_U32 == u32BusChannelClockMode))
                {
                    u32Period= (uint32) \
                        Icu_eMios_GetCaptureRegA((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24);
                }
                else
                {
                    u32Period= (uint32) \
                        Icu_eMios_GetCaptureRegB((uint8)(u8ModuleIdx << EMIOS_MOD_SHIFT) + EMIOS_CHANNEL_24);
                }
            }
            else
            {
                /* Do Nothing */
            }
        }
        break;

        case EMIOS_BUS_A:
        {
            /* Get channel of bus A is used */
            nChGeneratingEmiosBusA = (Icu_eMios_ChannelType)CH_GENERATING_EMIOS_BUS_A(u8ModuleIdx);
            /* Get clock mode */
            u32ChGeneratingEmiosBusAClockMode = Icu_eMios_GetChannelClockMode(nChGeneratingEmiosBusA);

            if
            (
                (u32ChGeneratingEmiosBusAClockMode == CCR_MCB_MODE_U32) || \
                (u32ChGeneratingEmiosBusAClockMode == CCR_MC_MODE_U32)
            )
            {
                u32Period  = (uint32) Icu_eMios_GetCaptureRegA(nChGeneratingEmiosBusA);
            }
            else
            {
                u32Period  = (uint32) Icu_eMios_GetCaptureRegB(nChGeneratingEmiosBusA);
            }
        }
        break;

        case EMIOS_BUS_F:
        {
            /* Get channel of bus F is used */
            nChGeneratingEmiosBusF = (Icu_eMios_ChannelType)CH_GENERATING_EMIOS_BUS_F(u8ModuleIdx);
            /* Get clock mode of bus F */
            u32ChGeneratingEmiosBusFClockMode = Icu_eMios_GetChannelClockMode(nChGeneratingEmiosBusF);

            if
            (
                (u32ChGeneratingEmiosBusFClockMode == CCR_MCB_MODE_U32) || \
                (u32ChGeneratingEmiosBusFClockMode == CCR_MC_MODE_U32)
            )
            {
                u32Period  = (uint32) Icu_eMios_GetCaptureRegA(nChGeneratingEmiosBusF);
            }
            else
            {
                u32Period  = (uint32) Icu_eMios_GetCaptureRegB(nChGeneratingEmiosBusF);
            }
        }
        break;

        default:
            break;
    }

    /* return u32Period */
    return (u32Period);
}
#endif

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that handles the signal measurement type interrupt.
 * @details    This service is  called when an  interrupt is recognized  as a Signal  Measurement
 *             type. There are two branch depending on  the sub-function selected: Duty Cycle or
 *             OTHER. Duty Cycle requires  an extra  variable, because  three values  are required:
 *             two flanks for active signal time and another flank for the end of the pulse. For
 *             calculating high, low and period is enough with the HW registers.
 *
 * @param[in]  nHwChannel - The index of ICU channel for current configuration structure
 * @param[in]  bOverflow        Parameter that indicates the source of report is an overflow
*/
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_SignalMeasurement
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel,
    VAR(boolean,                            AUTOMATIC) bOverflow
)
{
    VAR(Icu_ValueType, AUTOMATIC) IcuActivePulseWidth;
    VAR(Icu_ValueType, AUTOMATIC) IcuPeriod;
    VAR(Icu_ValueType, AUTOMATIC) Bus_Period;
    VAR(Icu_ValueType, AUTOMATIC) IcuTempA;
    VAR(Icu_ValueType, AUTOMATIC) IcuTempB;


#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    VAR(Icu_ValueType, AUTOMATIC) Previous_Value;
    VAR(Icu_ValueType, AUTOMATIC) Pulse_Width;
#endif /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */

    VAR(Icu_eMios_SignalMeasurementPropertyType, AUTOMATIC) \
        nMeasurement_property = (Icu_eMios_SignalMeasurementPropertyType)\
        (
            Icu_eMios_GetChConfig(nHwChannel, ICU_EMIOS_MEAS_PROPERTY_MASK) >> ICU_EMIOS_MEAS_PROPERTY_SHIFT
        );

    VAR(Icu_eMios_OperationMode, AUTOMATIC) \
        eMios_OperationMode = (Icu_eMios_OperationMode)\
        (
            Icu_eMios_GetChConfig(nHwChannel,ICU_EMIOS_OPERATION_MODE_MASK) >> ICU_EMIOS_OPERATION_MODE_SHIFT
        );

    /* Read captured values */
    IcuTempA = (Icu_ValueType)Icu_eMios_GetCaptureRegA(nHwChannel);
    IcuTempB = (Icu_ValueType)Icu_eMios_GetCaptureRegB(nHwChannel);

    if (EMIOS_UC_IPWM_MODE == eMios_OperationMode)
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_23();
        if
        (
            (EMIOS_ICU_HIGH_TIME == nMeasurement_property) || \
            (EMIOS_ICU_LOW_TIME == nMeasurement_property)

        )
        {
            if (IcuTempA > IcuTempB)
            {
                IcuActivePulseWidth = (Icu_ValueType)(IcuTempA - IcuTempB);
            }
            else /*Counter overflow Case*/
            {
                Bus_Period = Icu_eMios_ReadCounterBus(nHwChannel);
                IcuActivePulseWidth = (Icu_ValueType)(IcuTempA + ((uint32)Bus_Period - IcuTempB) + 1U);
            }
            Icu_Ipw_SignalMeasurement
            (
                ICU_EMIOS_HW_CHANNEL(nHwChannel), IcuActivePulseWidth, (uint16)0, bOverflow
            );
        }
        /* Duty cycle */
        else
        {
            /* Check if a complete signal was acquired */
            if (0U == Icu_aInt_Counter[nHwChannel])
            {
                /* Mark that the complete signal was acquired */
                Icu_aInt_Counter[nHwChannel] = 1U;
                Icu_Ipw_ReportWakeupAndOverflow(ICU_EMIOS_HW_CHANNEL(nHwChannel), bOverflow);
            }
            else
            {
                /* Compute Period of the signal */
                if (IcuTempB > Icu_TimeStart[nHwChannel])
                {
                    IcuPeriod = IcuTempB - Icu_TimeStart[nHwChannel];
                }
                else     /*Counter overflow Case */
                {
                    Bus_Period = Icu_eMios_ReadCounterBus(nHwChannel);
                    IcuPeriod = (Icu_ValueType)\
                    (IcuTempB + ((uint32)Bus_Period - Icu_TimeStart[nHwChannel]) + 1U);
                }
                IcuActivePulseWidth = Icu_CapturedActivePulseWidth[nHwChannel];

                if (EMIOS_ICU_DUTY_CYCLE == nMeasurement_property)
                {
                    Icu_Ipw_SignalMeasurement
                    (
                        ICU_EMIOS_HW_CHANNEL(nHwChannel), IcuActivePulseWidth, IcuPeriod, bOverflow
                    );
                }
                else if (EMIOS_ICU_PERIOD_TIME == nMeasurement_property)
                {
                    Icu_Ipw_SignalMeasurement
                    (
                        ICU_EMIOS_HW_CHANNEL(nHwChannel), (Icu_ValueType)0, IcuPeriod, bOverflow
                    );
                }
                else
                {
                    /* Nothing to do */
                }
            }
        }

        if (IcuTempA > IcuTempB)
        {
            Icu_CapturedActivePulseWidth[nHwChannel] = IcuTempA - IcuTempB;
        }
        else /*Counter overflow Case */
        {
            Bus_Period = Icu_eMios_ReadCounterBus(nHwChannel);
            Icu_CapturedActivePulseWidth[nHwChannel] = (Icu_ValueType)(IcuTempA + ((uint32)Bus_Period - IcuTempB) + 1U);
        }
        Icu_TimeStart[nHwChannel] = (Icu_ValueType)IcuTempB;
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_23();
    }
    else
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
        if (EMIOS_UC_IPM_MODE == eMios_OperationMode)
#endif   /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */
    {
        if (IcuTempA > IcuTempB)
        {
            IcuPeriod = IcuTempA - IcuTempB;
        }
        else     /*Counter overflow Case*/
        {
            Bus_Period = Icu_eMios_ReadCounterBus(nHwChannel);
            IcuPeriod = (Icu_ValueType)(IcuTempA + ((uint32)Bus_Period - IcuTempB) + 1U);
        }
        Icu_Ipw_SignalMeasurement
        (
            ICU_EMIOS_HW_CHANNEL(nHwChannel), (Icu_ValueType)0, IcuPeriod, bOverflow
        );
    }
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    else
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_24();
        {
            Icu_eMios_SetActivationCondition
            (
                nHwChannel, EMIOS_OPPOSITE_EDGES
            );

            if (0U == Icu_aInt_Counter[nHwChannel])   /* store the first value */
            {
                Icu_TimeStart[nHwChannel] = IcuTempA;
                Icu_aInt_Counter[nHwChannel]++;
            }
            else
            {
                Previous_Value = Icu_TimeStart[nHwChannel];
                /* if first value is greater than the second value */
                if (IcuTempA < Previous_Value)
                {
                    Bus_Period = Icu_eMios_ReadCounterBus(nHwChannel);
                    Pulse_Width = (Bus_Period - Previous_Value) + IcuTempA + 1U;
                }
                else
                {
                    Pulse_Width = IcuTempA - Previous_Value;
                }

                /* HIGH TIME or LOW TIME measurement */
                if ((EMIOS_ICU_HIGH_TIME == nMeasurement_property) ||   \
                    (EMIOS_ICU_LOW_TIME == nMeasurement_property)
                   )
                {
                    IcuActivePulseWidth = Pulse_Width;
                    /* clear to measure next LOW/HIGH pulse */
                    Icu_aInt_Counter[nHwChannel] = 0U;
                    Icu_Ipw_SignalMeasurement
                    (
                        ICU_EMIOS_HW_CHANNEL(nHwChannel), IcuActivePulseWidth, (Icu_ValueType)0, bOverflow
                    );
                }
                /* Duty Cycle */
                else
                {
                    /* DUTYCYCLE or PERIOD measurement */
                    if (1U == Icu_aInt_Counter[nHwChannel])
                    {
                        Icu_CapturedActivePulseWidth[nHwChannel] = Pulse_Width;
                        Icu_aInt_Counter[nHwChannel] = 2U;
                        Icu_Ipw_ReportWakeupAndOverflow(ICU_EMIOS_HW_CHANNEL(nHwChannel), bOverflow);
                    }
                    else
                    {
                        /* counter = 2 */
                        IcuPeriod = Icu_CapturedActivePulseWidth[nHwChannel] + Pulse_Width;
                        IcuActivePulseWidth = Icu_CapturedActivePulseWidth[nHwChannel];
                        /* set to 1 to find active pulse width next time */
                        Icu_aInt_Counter[nHwChannel] = 1U;
                        if (EMIOS_ICU_DUTY_CYCLE == nMeasurement_property)
                        {
                            Icu_Ipw_SignalMeasurement
                            (
                                ICU_EMIOS_HW_CHANNEL(nHwChannel), IcuActivePulseWidth, IcuPeriod, bOverflow
                            );
                        }
                        else if (EMIOS_ICU_PERIOD_TIME == nMeasurement_property)
                        {
                            Icu_Ipw_SignalMeasurement
                            (
                                ICU_EMIOS_HW_CHANNEL(nHwChannel), (Icu_ValueType)0, IcuPeriod, bOverflow
                            );
                        }
                        else
                        {
                            /**/
                        }
                    }
                    /* store for next time */
                    Icu_TimeStart[nHwChannel] = IcuTempA;
                }
            }
        }
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_24();
    }
#endif /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_TIMESTAMP_API == STD_ON)
/*================================================================================================*/
/**
 * @brief      Icu driver function that handles the timestamp measurement type interrupt.
 * @details    This service is  called when an  interrupt is recognized  as a Timestamp
 *             Measurement type.
 *
 * @param[in]  nHwChannel - The index of ICU channel for current configuration structure
 * @param[in]  bOverflow        Parameter that indicates the source of report is an overflow
 *
*/
/*================================================================================================*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_Timestamp
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel,
    VAR(boolean,                            AUTOMATIC) bOverflow
)
{
    VAR(uint8, AUTOMATIC) u8CapturedWords = 1U;

    /* Store timestamp */
    /** @violates @ref Icu_eMios_c_3, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    Icu_eMios_aBufferPtr[nHwChannel]= (Icu_ValueType)Icu_eMios_GetCaptureRegA(nHwChannel);

    Icu_Ipw_Timestamp
    (
        ICU_EMIOS_HW_CHANNEL(nHwChannel), u8CapturedWords, &Icu_eMios_aBufferPtr[nHwChannel], bOverflow
    );
}
#endif  /* ICU_TIMESTAMP_API */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/


/*================================================================================================*/
/**
* @brief      Icu_eMios_Init
* @details    This function is called separately for each EMIOS hw channel corresponding to
*             the configured Icu channels, and:
*             - Disables the interrupt corresponding to eMIOS channel
*             - Initializes prescaler value, channel filter, freeze enable, and bus select fields
*             - Defines on which edge the period starts
*             - Clears the (pending) interrupt flag corresponding to eMIOS channel
*             - Resets the UC A register.
*             - Enables the SAIC mode for eMIOS channels.
* @param[in]  peMiosIpConfig  - pointer to eMios configuration structure
* @api
*/

FUNC(void, ICU_CODE) Icu_eMios_Init
(
    P2CONST(Icu_eMios_IpConfigType, AUTOMATIC, ICU_APPL_CONST) peMiosIpConfig
)
{
    /* @brief Pointer to eMIOS channel specific configuration */
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) peMiosChannelConfig;

    VAR(Icu_eMios_ControlType, AUTOMATIC)   nCtrlRegVal;
    /* logical channel */
    VAR(Icu_eMios_ChannelType, AUTOMATIC)   nCounter;

    VAR(uint8,                 AUTOMATIC)   u8ModuleIdx;
    VAR(uint8,                 AUTOMATIC)   u8ChannelIdx;
    VAR(uint8,                 AUTOMATIC)   u8MasterModule;
    VAR(uint8,                 AUTOMATIC)   u8MasterChannel;
    VAR(uint8,                 AUTOMATIC)   u8MasterBusIdx = 0xFFU;
    VAR(uint8,                 AUTOMATIC)   u8MasterBusMode[ICU_MAX_EMIOS_CHANNELS];
    VAR(uint32,                AUTOMATIC)   u32prescaler[ICU_MAX_EMIOS_CHANNELS];
    VAR(uint32,                AUTOMATIC)   u32RegCCR;
    VAR(Icu_eMios_OperationMode, AUTOMATIC) ChannelOperationMode;
    VAR(uint32,                AUTOMATIC)   u32ChannelEmiosBus;

    for (nCounter=0U; nCounter < (Icu_eMios_ChannelType)ICU_MAX_EMIOS_CHANNELS; nCounter++)
    {
        u8MasterBusMode[nCounter] = (uint8)0xFFU;

        u32prescaler[nCounter] = (uint32)0;
    }

    for (nCounter=0U; nCounter < peMiosIpConfig->nNumChannels; nCounter++)
    {
        /* only handle EMIOS channels */
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[nCounter];
        nCtrlRegVal  = peMiosChannelConfig->nControlValue;

        u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->nHwChannel));
        u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->nHwChannel));

        u8MasterBusIdx = (uint8)Icu_eMios_GetMasterBus(u8ModuleIdx, u8ChannelIdx, (uint32)((nCtrlRegVal & ICU_EMIOS_BUS_SELECT_PARAM_MASK)
                                                                                                        >> ICU_EMIOS_BUS_SELECT_PARAM_SHIFT));

        /** @violates @ref Icu_eMios_c_4 MISRA 2004 Required Rule,Invariant results for Boolean Ops */
        u32RegCCR = CCR_UCPREN_MASK_U32 | (CCR_FCK_PRESCALED_U32 << CCR_FCK_SHIFT);
        /* Store Operateion Mode for Hardware channel */
        ChannelOperationMode = (Icu_eMios_OperationMode) \
                            ((nCtrlRegVal & ICU_EMIOS_UC_MODE_PARAM_MASK) >> ICU_EMIOS_UC_MODE_PARAM_SHIFT);

        /* Store bus select of nHwChannel */
        u32ChannelEmiosBus = (uint32)(nCtrlRegVal & (ICU_EMIOS_BUS_SELECT_PARAM_MASK));
        /* Clear channel config for nHwChannel */
        Icu_eMios_ClearChConfig
        (
            peMiosChannelConfig->nHwChannel,
            (Icu_eMios_ChConfigType)
            (
                ICU_EMIOS_CH_INITIALIZED_MASK| \
                ICU_EMIOS_MEAS_MODE_MASK |ICU_EMIOS_MEAS_PROPERTY_MASK | \
                ICU_EMIOS_OPERATION_MODE_MASK | ICU_EMIOS_BUS_CHANNEL_MASK
            )
        );

#ifdef EMIOS_UCDIS_AVAILABLE
#if (EMIOS_UCDIS_AVAILABLE == STD_ON)
    /* Enable eMIOS Channel */
    eMios_StartChannel(peMiosChannelConfig->nHwChannel);
#endif  /* EMIOS_UCDIS_AVAILABLE */
#endif

        /* Enter GPIO Mode to Configure Channel */
        /* Reset mode for selected channel */
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), EMIOS_CCR_CLEAR_U32);

        /* Initialize prescaler value, channel filter, freeze enable, and bus select and disable the
        * prescaler The definition on which edge the period starts
        * Set Default Edge (included)
        */
        u32RegCCR |= ((nCtrlRegVal & ICU_EMIOS_FREEZE_PARAM_MASK) >> ICU_EMIOS_FREEZE_PARAM_SHIFT) << CCR_FREN_SHIFT;
        u32RegCCR |= ((nCtrlRegVal & ICU_EMIOS_PRESCALER_PARAM_MASK) >> ICU_EMIOS_PRESCALER_PARAM_SHIFT) << CCR_UCPRE_SHIFT;
        u32RegCCR |= ((nCtrlRegVal & ICU_EMIOS_DIG_FILTER_PARAM_MASK) >> ICU_EMIOS_DIG_FILTER_PARAM_SHIFT) << CCR_IF_SHIFT;
        u32RegCCR |= ((nCtrlRegVal & ICU_EMIOS_BUS_SELECT_PARAM_MASK) >> ICU_EMIOS_BUS_SELECT_PARAM_SHIFT) << CCR_BSL_SHIFT;

        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), u32RegCCR);

        /* Disable interrupt */
        Icu_eMios_DisableInterrupt(u8ModuleIdx, u8ChannelIdx);

        /* Clear pending interrupt flag (and other flags) for the channel */
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32 \
        ( \
            EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), \
            (uint32)(CSR_OVR_MASK_U32 | CSR_OVFL_MASK_U32 | CSR_FLAG_MASK_U32) \
        );

        Icu_eMios_SetActivationCondition
        (
            peMiosChannelConfig->nHwChannel,
            (Icu_eMios_ActivationType)(peMiosChannelConfig->nDefaultStartEdge)
        );

        /* Set Config for nHwChannel */
        Icu_eMios_SetChConfig
        (
            peMiosChannelConfig->nHwChannel,
            ICU_EMIOS_CH_INITIALIZED_MASK | \
            (Icu_eMios_ChConfigType) ((Icu_eMios_ChConfigType)ChannelOperationMode << ICU_EMIOS_OPERATION_MODE_SHIFT) | \
            (Icu_eMios_ChConfigType) ((Icu_eMios_ChConfigType)u32ChannelEmiosBus << ICU_EMIOS_BUS_CHANNEL_SHIFT)
        );

        if (EMIOS_BUS_INTERNAL_COUNTER != (uint32)((nCtrlRegVal & ICU_EMIOS_BUS_SELECT_PARAM_MASK) >>ICU_EMIOS_BUS_SELECT_PARAM_SHIFT))
        {
            if((uint8)0xFFU == u8MasterBusMode[u8MasterBusIdx]) /* This master bus have not been configed*/
            {
                /* store master bus mode and master bus prescaler*/
                u8MasterBusMode[u8MasterBusIdx] = (uint8)CCR_MODE_MCB_INT_CLOCK_U32;
                u32prescaler[u8MasterBusIdx] = (uint32)((nCtrlRegVal & ICU_EMIOS_PRESCALER_PARAM_MASK) >> ICU_EMIOS_PRESCALER_PARAM_SHIFT);
                /* enable unified channel to make registers writeable */
                #ifdef EMIOS_UCDIS_AVAILABLE
                #if (EMIOS_UCDIS_AVAILABLE == STD_ON)
                eMios_StartChannel((uint8)u8MasterBusIdx);
                #endif  /* EMIOS_UCDIS_AVAILABLE */
                #endif
            }
        }
    }

    /* configuration for master bus */
    for (nCounter=0U; nCounter < ICU_MAX_EMIOS_CHANNELS; nCounter++)
    {
        if((uint8)0xFFU != u8MasterBusMode[nCounter]) /* Master bus is used */
        {
            u8MasterModule = (uint8)(EMIOS_MODULE_INDEX_U8(nCounter));
            u8MasterChannel = (uint8)(EMIOS_CHANNEL_INDEX_U8(nCounter));

            /* Enter GPIO Mode to Configure Channel */
            /* Reset mode for selected channel */
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(EMIOS_CCR_ADDR32(u8MasterModule, u8MasterChannel), EMIOS_CCR_CLEAR_U32);
            /* Update register A */
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(EMIOS_CADR_ADDR32(u8MasterModule, u8MasterChannel), EMIOS_COUNTER_MASK);
            /* Initialize prescaler value, operation mode for master bus */
            u32RegCCR = EMIOS_CCR_CLEAR_U32;
            u32RegCCR = (u32prescaler[nCounter] << CCR_UCPRE_SHIFT) | (u8MasterBusMode[nCounter] & CCR_MODE_MASK_U32);
            /* Set up CCR Register for master bus */
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(EMIOS_CCR_ADDR32(u8MasterModule, u8MasterChannel), u32RegCCR);
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8MasterModule, u8MasterChannel),CCR_UCPREN_MASK_U32);
        }
    }
}

#if (ICU_DE_INIT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_eMios_DeInit
* @details    This function is called separately for each EMIOS hw channel corresponding to the
*             configured Icu channels, and:
*             - Resets the eMIOS channel control register
*             - Resets the UC A register.
*             - Clears the (pending) interrupt flag corresponding to eMIOS channel
* @param[in]  peMiosIpConfig   - pointer to eMios configuration structure
*
* @api
* @violates @ref Icu_eMios_c_5 external ... could be made static
*/
FUNC(void, ICU_CODE) Icu_eMios_DeInit
(
    P2CONST(Icu_eMios_IpConfigType, AUTOMATIC, ICU_APPL_CONST) peMiosIpConfig
)
{
    /* @brief Pointer to eMIOS channel specific configuration */
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) peMiosChannelConfig;

    VAR(Icu_eMios_ControlType, AUTOMATIC)   nCtrlRegVal;
    /* logical channel */
    VAR(Icu_eMios_ChannelType, AUTOMATIC)   nCounter;
    VAR(uint8,                 AUTOMATIC)   u8ModuleIdx;
    VAR(uint8,                 AUTOMATIC)   u8ChannelIdx;
    VAR(Icu_eMios_ChannelMeasurementModeType, AUTOMATIC) nMeasMode;

    /*Master bus */
    VAR(uint8,                 AUTOMATIC)   u8MasterModule;
    VAR(uint8,                 AUTOMATIC)   u8MasterChannel;
    VAR(uint8,                 AUTOMATIC)   u8MasterBusIdx = 0xFFU;
    VAR(uint8,                 AUTOMATIC)   u8MasterBusUse[ICU_MAX_EMIOS_CHANNELS];

    for (nCounter=0U; nCounter < (Icu_eMios_ChannelType)ICU_MAX_EMIOS_CHANNELS; nCounter++)
    {
        u8MasterBusUse[nCounter] = (uint8)0xFFU;
    }

    for (nCounter=0U; nCounter < peMiosIpConfig->nNumChannels; nCounter++)
    {
        /* only handle EMIOS channels */
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[nCounter];
        nCtrlRegVal  = peMiosChannelConfig->nControlValue;

        u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->nHwChannel));
        u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->nHwChannel));

        nMeasMode = (Icu_eMios_ChannelMeasurementModeType)\
                    (Icu_eMios_GetChConfig(peMiosChannelConfig->nHwChannel,ICU_EMIOS_MEAS_MODE_MASK) >> \
                                            ICU_EMIOS_MEAS_MODE_SHIFT);
        /* Set all channel registers as after reset */
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), EMIOS_CCR_CLEAR_U32);

        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(EMIOS_CADR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), EMIOS_CADR_CLEAR_U32);

        if (EMIOS_CHANNEL_MODE_SIGNAL_MEASUREMENT == nMeasMode)
        {
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(EMIOS_CBDR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), EMIOS_CBDR_CLEAR_U32);
        }

        else if (EMIOS_CHANNEL_MODE_EDGE_COUNTER == nMeasMode)
        {
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(EMIOS_CCNTR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), EMIOS_CCNTR_CLEAR_U32);
        }
        else
        {
            /*For Misra Compliance*/
        }
        /* Clear CSR register */
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), EMIOS_CSR_CLEAR_U32);

#ifdef EMIOS_UCDIS_AVAILABLE
#if (EMIOS_UCDIS_AVAILABLE == STD_ON)
    /* Disable eMIOS Channel */
    eMios_StopChannel(peMiosChannelConfig->nHwChannel);
#endif
#endif  /* EMIOS_UCDIS_AVAILABLE */
        /* Clear config for hardware channel */
        Icu_eMios_ClearChConfig
        (
            peMiosChannelConfig->nHwChannel,
            (Icu_eMios_ChConfigType)
            (
                ICU_EMIOS_CH_INITIALIZED_MASK | \
                ICU_EMIOS_MEAS_MODE_MASK | \
                ICU_EMIOS_MEAS_PROPERTY_MASK | \
                ICU_EMIOS_OPERATION_MODE_MASK | \
                ICU_EMIOS_BUS_CHANNEL_MASK
            )
        );
#if (ICU_EDGE_COUNT_API == STD_ON)
    /* Clear all aEdgeCurrent_Value */
    Icu_aEdgeCurrent_Value[peMiosChannelConfig->nHwChannel] = (uint32)(0x0U);
#endif /* ICU_EDGE_COUNT_API == STD_ON */

        /* if channel using master bus, so de-init for master bus */
        if (EMIOS_BUS_INTERNAL_COUNTER != (uint32)((nCtrlRegVal & ICU_EMIOS_BUS_SELECT_PARAM_MASK) >>ICU_EMIOS_BUS_SELECT_PARAM_SHIFT))
        {
            u8MasterBusIdx = (uint8)Icu_eMios_GetMasterBus(u8ModuleIdx, u8ChannelIdx, (uint32)((nCtrlRegVal & ICU_EMIOS_BUS_SELECT_PARAM_MASK)
                                                                                                        >> ICU_EMIOS_BUS_SELECT_PARAM_SHIFT));
            if ((uint8)0xFFU == u8MasterBusUse[u8MasterBusIdx])
            {
                u8MasterModule = (uint8)(EMIOS_MODULE_INDEX_U8(u8MasterBusIdx));
                u8MasterChannel = (uint8)(EMIOS_CHANNEL_INDEX_U8(u8MasterBusIdx));
                /* Clear register A */
                /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
                /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_WRITE32(EMIOS_CADR_ADDR32(u8MasterModule, u8MasterChannel), EMIOS_CBDR_CLEAR_U32);
                /* Clear register B */
                /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
                /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_WRITE32(EMIOS_CBDR_ADDR32(u8MasterModule, u8MasterChannel), EMIOS_CBDR_CLEAR_U32);
                /* Reset CCR register */
                /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
                /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_WRITE32(EMIOS_CCR_ADDR32(u8MasterModule, u8MasterChannel), EMIOS_CCR_CLEAR_U32);
                /* Clear CSR register */
                /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
                /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
                REG_WRITE32(EMIOS_CSR_ADDR32(u8MasterModule, u8MasterChannel), EMIOS_CSR_CLEAR_U32);
                u8MasterBusUse[u8MasterBusIdx] = (uint8)1U;
#ifdef EMIOS_UCDIS_AVAILABLE
#if (EMIOS_UCDIS_AVAILABLE == STD_ON)
    /* Disable eMIOS Channel */
    eMios_StopChannel(u8MasterBusIdx);
#endif
#endif  /* EMIOS_UCDIS_AVAILABLE */
            }
        }
    }
}
#endif

/*================================================================================================*/
#if (ICU_SET_MODE_API == STD_ON)
/**
* @brief      Icu_eMios_SetSleepMode
* @details    This function is called separately for each EMIOS hw channel corresponding to the
*             configured Icu channels, and:
*             - Enables the interrupt for the eMIOS channel,
*                 if the wake up functionality is enabled
*             - Disables the interrupt for the eMIOS channel,
*                 if the wake up functionality is disabled
* @param[in]  nHwChannel     - eMIOS encoded hardware channel
* @api
*/

FUNC(void, ICU_CODE) Icu_eMios_SetSleepMode
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* Stop eMIOS channel */
    Icu_eMios_DisableInterrupt(u8ModuleIdx, u8ChannelIdx);
}


/*================================================================================================*/
/**
* @brief      Icu_eMios_SetNormalMode
* @details    This function: Set normal mode
* @param[in]  nHwChannel          - eMIOS encoded hardware channel
* @api
*/

FUNC(void, ICU_CODE) Icu_eMios_SetNormalMode
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    VAR(uint32, AUTOMATIC) u32Value_CCR_FEN;

    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* u32Value_CCR_FEN will indicate whether the interrupt is enabled or not*/
    /** @violates @ref Icu_eMios_c_3 cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
     u32Value_CCR_FEN  = REG_BIT_GET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32);
    /* if interrupt is not enabled*/
    if(0U == u32Value_CCR_FEN)
    {
        Icu_eMios_EnableInterrupt(u8ModuleIdx, u8ChannelIdx);
    }
}
#endif  /* ICU_SET_MODE_API */

/*================================================================================================*/
/**
* @brief      Icu driver function that sets activation condition of eMIOS channel
* @details    This function enables the requested activation condition(rising, falling or both
*             edges) for corresponding eMIOS channels.
* @param[in]  nHwChannel   - eMIOS encoded hardware channel
* @param[in]  channelMode - Chanel mode
* @param[in]  Activation  - edge activation type
* @api
*/
FUNC(void, ICU_CODE) Icu_eMios_SetActivationCondition
(
    CONST(Icu_eMios_ChannelType,                        AUTOMATIC) nHwChannel,
    CONST(Icu_eMios_ActivationType,                     AUTOMATIC) Activation
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
    VAR(uint32, AUTOMATIC) u32RegEmiosCCR;
#endif  /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_19();
    switch (Activation)
    {
#ifdef SIGNAL_MEASUREMENT_USES_SAIC_MODE
        case EMIOS_OPPOSITE_EDGES:
        {
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            u32RegEmiosCCR = REG_READ32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx));

            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_WRITE32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx),(u32RegEmiosCCR ^ CCR_EDPOL_MASK_U32));
        }
        break;
#endif  /* SIGNAL_MEASUREMENT_USES_SAIC_MODE */

        case EMIOS_BOTH_EDGES:
        {
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_EDSEL_MASK_U32);
        }
        break;

        case EMIOS_RISING_EDGE:
        {
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_EDSEL_MASK_U32);

            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_EDPOL_MASK_U32);
        }
        break;

        default:
        {
            /* EMIOS_FALLING_EDGE */
            /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
            /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
            REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), (CCR_EDSEL_MASK_U32 | CCR_EDPOL_MASK_U32));
        }
        break;
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_19();
}

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_eMios_EnableEdgeDetection
* @details    eMIOS IP function that starts the edge detection service for an eMIOS channel
*
* @param[in]      nHwChannel   - eMIOS encoded hardware channel
*
* @return void
*/
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_eMios_EnableEdgeDetection
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* Enter GPIO Mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    /* Enable SAIC mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_SAIC_U32);

    /* Enable Interrupt */
    Icu_eMios_EnableInterrupt(u8ModuleIdx, u8ChannelIdx);

    /* Set Channel Config */
    Icu_eMios_SetChConfig
    (
        nHwChannel, \
        (Icu_eMios_ChConfigType)((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_SIGNAL_EDGE_DETECT << ICU_EMIOS_MEAS_MODE_SHIFT)
    );

}
#endif /* ICU_EDGE_DETECT_API */

#if (ICU_EDGE_DETECT_API == STD_ON)
/*================================================================================================*/
/**
* @brief      Icu_eMios_DisableEdgeDetection
* @details    eMIOS IP function that stops the edge detection service for an eMIOS channel
*
* @param[in]      nHwChannel   - eMIOS encoded hardware channel
*
* @return void
*/
/*================================================================================================*/
FUNC(void, ICU_CODE) Icu_eMios_DisableEdgeDetection
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{

    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* Disable interrupt */
    Icu_eMios_DisableInterrupt(u8ModuleIdx, u8ChannelIdx);

    /* Enter GPIO Mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    /* Get Channel Config */
    Icu_eMios_ClearChConfig
    (
        nHwChannel, \
        (Icu_eMios_ChConfigType)((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_SIGNAL_EDGE_DETECT << ICU_EMIOS_MEAS_MODE_SHIFT)
    );

}
#endif /* ICU_EDGE_DETECT_API */


#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu driver function that starts time stamp measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Clears the pending interrupts
*             - Enables SAIC mode for the channel
*             - Enbales the interrupt for the channel
*
* @param[in]  nHwChannel     - eMIOS encoded hardware channel
* @param[in]  bDmaSupport   - Indicate DMA support
* @api
*/

FUNC(void, ICU_CODE) Icu_eMios_StartTimestamp
(
    CONST(Icu_eMios_ChannelType,         AUTOMATIC)   nHwChannel,
    CONST(boolean,                       AUTOMATIC)   bDmaSupport
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* Reset aBufferPtr */
    Icu_eMios_aBufferPtr[nHwChannel] = 0U;

    /* Make sure channel is in GPIO mode before switching modes */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    /* Clear pending interrupts */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32\
    (\
        EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), \
        (uint32)(CSR_OVR_MASK_U32 | CSR_OVFL_MASK_U32 | CSR_FLAG_MASK_U32)\
    );

    /* Enable SAIC mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_SAIC_U32);

    if((boolean)TRUE == bDmaSupport)
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_20();
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx),(CCR_DMA_MASK_U32),(CCR_DMA_MASK_U32));
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_20();
        /* Set channel Config*/
        Icu_eMios_SetChConfig
        (
            nHwChannel,
            (Icu_eMios_ChConfigType)((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_TIMESTAMP_WITH_DMA << ICU_EMIOS_MEAS_MODE_SHIFT)
        );
    }
    else
    {
        /* Set channel Config*/
        Icu_eMios_SetChConfig
        (
            nHwChannel,
            (Icu_eMios_ChConfigType)((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA << ICU_EMIOS_MEAS_MODE_SHIFT)
        );
    }

    /* Enable Interrupt */
    Icu_eMios_EnableInterrupt(u8ModuleIdx, u8ChannelIdx);
}
#endif  /* ICU_TIMESTAMP_API */


/*================================================================================================*/
#if (ICU_TIMESTAMP_API == STD_ON)
/**
* @brief      Icu driver function that stops time stamp measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Disables the interrupt for the channel
*
* @param[in]  nHwChannel   - eMIOS encoded hardware channel
* @api
*/

FUNC(void, ICU_CODE) Icu_eMios_StopTimestamp
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC)   nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* Disable interrupt */
    Icu_eMios_DisableInterrupt(u8ModuleIdx, u8ChannelIdx);

    /* Enter GPIO Mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    /* Clear channel Config */
    Icu_eMios_ClearChConfig
    (
        nHwChannel,
        (Icu_eMios_ChConfigType)\
        (
            ((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA | \
            (Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_TIMESTAMP_WITH_DMA) << ICU_EMIOS_MEAS_MODE_SHIFT
        )
    );
}
#endif  /* ICU_TIMESTAMP_API */

#if ((ICU_SIGNALMEASUREMENT_USES_DMA == STD_ON) || (ICU_TIMESTAMP_USES_DMA == STD_ON))
/**
* @brief      Icu_eMios_GetStartAddress
* @details    eMIOS IP function that stops the edge detection service for an eMIOS channel
*
* @param[in]      nHwChannel   - eMIOS encoded hardware channel
*
* @return void
*
* */
FUNC(uint32, ICU_CODE) Icu_eMios_GetStartAddress
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    return (EMIOS_CADR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx));
}
#endif


#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that resets the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Puts the eMIOS channel into GPIO mode
*             - Resets the counter to initial value
*             - Loads the initial value to the RegisterA
*             - Clears the pending interrupts
*             - Restores the previous mode
*
* @param[in]  nHwChannel   - eMIOS encoded hardware channel
*
* @api
*/

FUNC(void, ICU_CODE) Icu_eMios_ResetEdgeCount
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
    VAR(uint32, AUTOMATIC)  u32PrevMode;

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32PrevMode = REG_BIT_GET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_MODE_MASK_U32);

    /* Disable timer interrupts */
    Icu_eMios_DisableInterrupt(u8ModuleIdx, u8ChannelIdx);

    /* Enter GPIO Mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    /* Reset counter */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(EMIOS_CCNTR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), EMIOS_INIT_CCNTR_U32);

    /* Max. value for register A. If reached, overflow interrupt */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(EMIOS_CADR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), EMIOS_INIT_CADR_U32);

    /* Clear pending interrupts */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32\
    (\
        EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), \
        (uint32)(CSR_OVR_MASK_U32 | CSR_OVFL_MASK_U32 | CSR_FLAG_MASK_U32)\
    );

    /* Restore previous mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, u32PrevMode);

    /* Cleare Current Value*/
    Icu_aEdgeCurrent_Value[nHwChannel] = (uint32)0;
    /* Enable timer interrupts */
    Icu_eMios_EnableInterrupt(u8ModuleIdx, u8ChannelIdx);
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that enables the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Puts the eMIOS channel into GPIO mode
*             - Counter register is loaded with startValue
*             - Loads initial value to RegisterA
*             - Clears the pending interrupts
*             - Sets the mode to Modulus counter mode
*             - Enables the interrupt for eMIOS channel
*
* @param[in]  nHwChannel   - eMIOS encoded hardware channel
*/
FUNC(void, ICU_CODE) Icu_eMios_EnableEdgeCount
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* Make sure channel is in GPIO mode before switching modes */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    /* Clear A register */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(EMIOS_CADR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), EMIOS_CADR_CLEAR_U32);

    /* Sync. eMIOS counter value. (Needed in case of stopping and re-enabling counting)
     * Note: Setting GPIO mode, the internal counter was cleared and must be restored
     */

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /* When call again affter call Icu_eMios_DisableEdgeCount*/
    REG_WRITE32(EMIOS_CCNTR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), Icu_aEdgeCurrent_Value[nHwChannel]);

    /* Clear pending interrupts */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32\
    (\
        EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx),\
        (uint32)(CSR_OVR_MASK_U32 | CSR_OVFL_MASK_U32 | CSR_FLAG_MASK_U32)\
    );

    /* Modulus counter mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_MCB_EXT_CLOCK_U32);

    /* Set Max. A value */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(EMIOS_CADR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx), EMIOS_INIT_CADR_U32);

    /* Enable interrupt */
    Icu_eMios_EnableInterrupt(u8ModuleIdx, u8ChannelIdx);

    /* Set Channel config */
    Icu_eMios_SetChConfig
    (
        nHwChannel,
        (Icu_eMios_ChConfigType)((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_EDGE_COUNTER << ICU_EMIOS_MEAS_MODE_SHIFT)
    );


}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that disables the edge counter measurement of eMIOS channel.
* @details    The function:
*             - Disables the eMIOS channel interrupt
*             - Clears the pending interrupts
*             - Save the current counter value before entering into GPIO mode
*             - Puts the channel into GPIO mode
*             - Disables MCB mode for the channel
*
* @param[in]  nHwChannel    - eMIOS encoded hardware channel
* @param[out] currentValue - the current value of the channel's counter
*
* @api
*/
FUNC(void, ICU_CODE) Icu_eMios_DisableEdgeCount
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* Disable interrupt */
    Icu_eMios_DisableInterrupt(u8ModuleIdx, u8ChannelIdx);

    /* Clear pending interrupts */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32\
    (\
        EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), \
        (uint32)(CSR_OVR_MASK_U32 | CSR_OVFL_MASK_U32 | CSR_FLAG_MASK_U32)\
    );

    /* Save count, before going to GPIO mode (because counter is reset to 0x0000) */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    Icu_aEdgeCurrent_Value[nHwChannel] = REG_READ32(EMIOS_CCNTR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx));

    /* Disable MCB mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    Icu_eMios_ClearChConfig
    (
        nHwChannel, \
        (Icu_eMios_ChConfigType)((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_EDGE_COUNTER << ICU_EMIOS_MEAS_MODE_SHIFT)
    );
}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_EDGE_COUNT_API == STD_ON)
/**
* @brief      Icu driver function that gets edge counter measurement of eMIOS channel.
* @details    This function returns counter value (the number of counter edges) of eMIOS channel
*
* @param[in]  nHwChannel   - eMIOS encoded hardware channel
*
* @return     uint32 - Counted edges number
*
* @api
*/
/*================================================================================================*/
FUNC (uint32, ICU_CODE) Icu_eMios_GetEdgeNumbers
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
    VAR(uint32, AUTOMATIC) u32Mode;
    VAR(uint32, AUTOMATIC) u32Result = (uint32)0;
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32Mode = (REG_READ32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx)) & CCR_MODE_MASK_U32);

    /* Check mode affter call Icu_eMios_DisableEdgeCount */
    if(CCR_MODE_GPI_U32 == u32Mode)
    {
        u32Result = Icu_aEdgeCurrent_Value[nHwChannel];
    }
    else
    {
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32Result = REG_READ32(EMIOS_CCNTR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx));
    }
    return u32Result;

}
#endif  /* ICU_EDGE_COUNT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu driver function that starts the signal measurement of eMIOS channel.
* @details    This function:
*             - Disables the interrupt of eMIOS channel
*             - Puts the eMIOS channel into GPIO mode
*             - Sets activation condition (Rising, Falling or Both edges)
*             - Puts the eMIOS channel into requested mode (IPWM, IPM or SAIC)
*             - Clears pending interrupts
*             - Enables the interrupt for eMIOS channel
*
* @param[in]  nHwChannel  - eMIOS encoded hardware channel
* @param[in]  Activation - edge activation type
* @param[in]  mode       - Unified Chanel mode of operation
*
* @api
*/
FUNC(void, ICU_CODE) Icu_eMios_StartSignalMeasurement
(
    CONST(Icu_eMios_ChannelType,                    AUTOMATIC) nHwChannel,
    CONST(Icu_eMios_ActivationType,                 AUTOMATIC) Activation,
    CONST(Icu_eMios_SignalMeasurementPropertyType,  AUTOMATIC) nMeasProperty,
    CONST(boolean,                                  AUTOMATIC) bDmaSupport,
    CONST(boolean,                                  AUTOMATIC) bWithoutInterrupt
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
    VAR(Icu_eMios_OperationMode, AUTOMATIC) eMiosOperationMode;

    /* Reset capture and timestart of nHwChannel */
    Icu_CapturedActivePulseWidth[nHwChannel] = 0U;
    Icu_TimeStart[nHwChannel] = 0U;

    /* Disable interrupt */
    Icu_eMios_DisableInterrupt(u8ModuleIdx, u8ChannelIdx);

    /* Enter GPIO Mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    /* Set activation condition */
    Icu_eMios_SetActivationCondition(nHwChannel, Activation);

    /* Get operation mode of hardware channel */
    if((boolean)TRUE == bDmaSupport)
    {
        SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_21();
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_RMW32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx),(CCR_DMA_MASK_U32),(CCR_DMA_MASK_U32));
        SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_21();
    }

    eMiosOperationMode = (Icu_eMios_OperationMode) \
        (
            Icu_eMios_GetChConfig(nHwChannel, ICU_EMIOS_OPERATION_MODE_MASK) >> ICU_EMIOS_OPERATION_MODE_SHIFT
        );

    if (EMIOS_UC_IPWM_MODE == eMiosOperationMode)
    {
        /* Enable IPWM mode */
        Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_IPWM_U32);
    }
    else if (EMIOS_UC_IPM_MODE == eMiosOperationMode)
    {
        /* Enable IPM mode */
        Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_IPM_U32);
    }
    else
    {
        /* Enable SAIC mode */
        Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_SAIC_U32);
    }

    /* Clear pending interrupt flag (and other flags) for the channel */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32\
    (\
        EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), \
        (uint32)(CSR_OVR_MASK_U32 | CSR_OVFL_MASK_U32 | CSR_FLAG_MASK_U32)\
    );
    /* Clear the counter for signal measurement */
    Icu_aInt_Counter[nHwChannel] = (Icu_ValueType)0;
    if ((boolean)TRUE != bWithoutInterrupt)
    {
        /* Enable Interrupt */
        Icu_eMios_EnableInterrupt(u8ModuleIdx, u8ChannelIdx);
    }

    /* Set channel config */
    Icu_eMios_SetChConfig
    (
        nHwChannel,
        (Icu_eMios_ChConfigType)((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_SIGNAL_MEASUREMENT << ICU_EMIOS_MEAS_MODE_SHIFT) |
        (Icu_eMios_ChConfigType)((Icu_eMios_ChConfigType)nMeasProperty << ICU_EMIOS_MEAS_PROPERTY_SHIFT)
    );

}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
/**
* @brief      Icu driver function that stops the signal measurement of eMIOS channel.
* @details    This function:
*             - Puts the eMIOS channel into GPIO mode
*             - Disables the interrupt for requsted eMIOS channel
*             - Clears pending interrupts
*
* @param[in]  nHwChannel  - eMIOS encoded hardware channel
*
* @api
*/
FUNC(void, ICU_CODE) Icu_eMios_StopSignalMeasurement
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /* Disable interrupt */
    Icu_eMios_DisableInterrupt(u8ModuleIdx, u8ChannelIdx);

    /* Enter GPIO Mode */
    Icu_eMios_UCSetMode(u8ModuleIdx, u8ChannelIdx, CCR_MODE_GPI_U32);

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_18();
    /* EDSEL is set to 1 to discard the input in GPIO mode (not to repond the input signal
       in GPIO mode)*/
    /* Disables the flag generation as defined by EDPOL Bit */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_EDSEL_MASK_U32);
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_18();

    /* Clear pending interrupt flag (and other flags) for the channel */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32\
    (\
        EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), \
        (uint32)(CSR_OVR_MASK_U32 | CSR_OVFL_MASK_U32 | CSR_FLAG_MASK_U32)\
    );
    /* Clear channel config */
    Icu_eMios_ClearChConfig
    (
        nHwChannel,
        (Icu_eMios_ChConfigType)\
            ((Icu_eMios_ChConfigType)EMIOS_CHANNEL_MODE_SIGNAL_MEASUREMENT << ICU_EMIOS_MEAS_MODE_SHIFT) | \
                ICU_EMIOS_MEAS_PROPERTY_MASK
    );
}
#endif  /* ICU_SIGNAL_MEASUREMENT_API */

/*================================================================================================*/
#if (ICU_GET_INPUT_STATE_API == STD_ON)
/**
* @brief      Icu driver function that gets the input state of eMIOS channel.
* @details    This function:
*            - Checks if interrupt flags for corresponding eMIOS channel is set then
*            it clears the interrupt flag and returns the value as true.
*
* @param[in]  nHwChannel - eMIOS encoded hardware channel
*
* @return       boolean
* @retval       true - if channel is active
* @retval       false - if channel is idle
*
* @api
*/

FUNC (boolean, ICU_CODE) Icu_eMios_GetInputState
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
    VAR(boolean, AUTOMATIC) bResult = (boolean)FALSE;
    VAR(uint32, AUTOMATIC) u32ValueCCRFEN;
    VAR(uint32, AUTOMATIC) u32ValueCSRFLAG;

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32ValueCCRFEN  = REG_BIT_GET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_FEN_MASK_U32);
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32ValueCSRFLAG = REG_BIT_GET32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);

    /* Interrupt not enabled, flag bit was set */
    if ( (CCR_FEN_MASK_U32 != u32ValueCCRFEN) && (CSR_FLAG_MASK_U32 == u32ValueCSRFLAG))
    {

        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer  */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Clear pending interrupt */
        REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), CSR_FLAG_MASK_U32);

        bResult = (boolean)TRUE;
    }

    return bResult;
}
#endif  /* ICU_GET_INPUT_STATE_API */


/*================================================================================================*/

/*================================================================================================*/
/**
* @brief      Icu_eMios_GetOverflow
* @details    eMIOS IP function that get the state of the overflow flag
*
* @param[in]   nHwChannel   - eMIOS  encoded hardware channel
*
* @return      boolean      the state of the overflow flag
* @retval      true         the overflow flag is set
* @retval      false        the overflow flag is not set
*
* @return void
* @violates @ref Icu_eMios_c_5 external ... could be made static
*/
/*================================================================================================*/
FUNC (boolean, ICU_CODE) Icu_eMios_GetOverflow
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
    VAR(boolean, AUTOMATIC) bResult = (boolean)FALSE;
    VAR(uint32, AUTOMATIC) u32RegCSR = (uint32) 0x00;
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32RegCSR = REG_READ32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx));

    /* Clear pending interrupt serviced */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx), u32RegCSR & (CSR_OVFL_BIT_U32));

    bResult = Icu_eMios_CheckOverflowFlag(u32RegCSR);

    return bResult;
}

/*================================================================================================*/
/**
* @brief      Icu driver function that handles the interrupt of eMIOS channel.
* @details    This function:
*              - Reads the status register
*              - Clears the pending interrupt
*              - Processes interrupt for corresponding eMIOS channel
*
* @param[in]  nHwChannel - eMIOS hardware channel
*
* @implements Icu_eMios_ProcessCommonInterrupt_Activity
* @violates @ref Icu_eMios_c_5 external ... could be made static
*/
FUNC(void, ICU_CODE) Icu_eMios_ProcessCommonInterrupt(CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    if
    (
        ICU_EMIOS_CH_INITIALIZED_MASK == \
                Icu_eMios_GetChConfig(nHwChannel, ICU_EMIOS_CH_INITIALIZED_MASK)
    )
    {
        VAR(uint32, AUTOMATIC) u32RegCSR = (uint32)0x0U;
        VAR(uint32, AUTOMATIC) u32RegCCR = (uint32)0x0U;
        VAR(Icu_eMios_ChannelMeasurementModeType, AUTOMATIC) nMeasMode;
        VAR(boolean, AUTOMATIC) bOverflow = (boolean)FALSE;

        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        /* Read UC Status Register */
        u32RegCSR = Icu_eMios_GetStatusFlags(nHwChannel);
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        u32RegCCR = REG_READ32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx));

        if ((0U != (u32RegCSR & CSR_FLAG_MASK_U32)) && (0U != (u32RegCCR & CCR_FEN_MASK_U32)))
        {
            bOverflow = Icu_eMios_CheckOverflowFlag(u32RegCSR);

            nMeasMode = (Icu_eMios_ChannelMeasurementModeType)\
                    (Icu_eMios_GetChConfig(nHwChannel,ICU_EMIOS_MEAS_MODE_MASK) >> ICU_EMIOS_MEAS_MODE_SHIFT);
            switch (nMeasMode)
            {
#if (ICU_EDGE_DETECT_API == STD_ON)
                case EMIOS_CHANNEL_MODE_SIGNAL_EDGE_DETECT:
                {
                    Icu_Ipw_ReportEvents(ICU_EMIOS_HW_CHANNEL(nHwChannel),bOverflow);
                }
                break;
#endif
#if (ICU_TIMESTAMP_API == STD_ON)
                case EMIOS_CHANNEL_MODE_TIMESTAMP_WITHOUT_DMA:
                {
                    Icu_eMios_Timestamp(nHwChannel,bOverflow);
                }
                break;
#if (ICU_TIMESTAMP_USES_DMA == STD_ON)
                case EMIOS_CHANNEL_MODE_TIMESTAMP_WITH_DMA:
                {
                    Icu_Ipw_ReportWakeupAndOverflow(ICU_EMIOS_HW_CHANNEL(nHwChannel), bOverflow);
                }
                break;
#endif
#endif /* ICU_TIMESTAMP_API == STD_ON */

#if (ICU_SIGNAL_MEASUREMENT_API == STD_ON)
                case EMIOS_CHANNEL_MODE_SIGNAL_MEASUREMENT:
                {
                    Icu_eMios_SignalMeasurement(nHwChannel,bOverflow);
                }
                break;
#endif
                default: /* case EMIOS_CHANNEL_MODE_EDGE_COUNTER:*/
                {
#if (ICU_EDGE_COUNT_API == STD_ON)
                    Icu_Ipw_ReportWakeupAndOverflow(ICU_EMIOS_HW_CHANNEL(nHwChannel), bOverflow);
#endif
                }
                break;
            }
        }
    }

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    /* Clear pending interrupt serviced */
    Icu_eMios_ClearStatusFlags\
    (\
        nHwChannel,\
        REG_READ32(EMIOS_CSR_ADDR32(u8ModuleIdx, (uint32)u8ChannelIdx))\
    );
}

#if (ICU_DUAL_CLOCK_MODE_API == STD_ON)
FUNC (void, ICU_CODE) Icu_eMios_SetClockMode
(
    P2CONST(Icu_eMios_IpConfigType,      AUTOMATIC, ICU_APPL_CONST) peMiosIpConfig,
    CONST(Icu_eMios_SelectPrescalerType, AUTOMATIC)                 Prescaler
)
{
    /* @brief Pointer to eMIOS channel specific configuration */
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) peMiosChannelConfig;

    VAR(uint8, AUTOMATIC) u8ModuleIdx;
    VAR(uint8, AUTOMATIC) u8ChannelIdx;

    VAR(Icu_eMios_ControlType, AUTOMATIC)   nCtrlRegVal;
    /* logical channel */
    VAR(Icu_eMios_ChannelType, AUTOMATIC)   nCounter;

    VAR(uint32,                AUTOMATIC)   nCtrlBus;
    VAR(uint8,                 AUTOMATIC)   u8MasterBusIdx;
    VAR(uint8,                 AUTOMATIC)   u8MasterBusUse[ICU_MAX_EMIOS_CHANNELS];

    for (nCounter=0U; nCounter < (Icu_eMios_ChannelType)ICU_MAX_EMIOS_CHANNELS; nCounter++)
    {
        u8MasterBusUse[nCounter] = (uint8)0xFFU;
    }

    for (nCounter=0U; nCounter < peMiosIpConfig->nNumChannels; nCounter++)
    {
        /* only handle EMIOS channels */
        peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[nCounter];
        nCtrlRegVal  = peMiosChannelConfig->nControlValue;

        u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8((uint8)peMiosChannelConfig->nHwChannel));
        u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8((uint8)peMiosChannelConfig->nHwChannel));
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        nCtrlBus = ((REG_READ32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx)) & CCR_BSL_MASK_U32) >> CCR_BSL_SHIFT);

        if (EMIOS_BUS_INTERNAL_COUNTER == nCtrlBus)
        {
            if (EMIOS_ICU_NORMAL_CLOCK_MODE == Prescaler)
            {
                Icu_eMios_SetPrescaler(
                                        peMiosChannelConfig->nHwChannel,
                                        (uint32)((nCtrlRegVal & ICU_EMIOS_PRESCALER_PARAM_MASK ) >> ICU_EMIOS_PRESCALER_PARAM_SHIFT)
                                    );
            }
            else
            {
                Icu_eMios_SetPrescaler(
                                        peMiosChannelConfig->nHwChannel,
                                        (uint32)((nCtrlRegVal & ICU_EMIOS_PRESC_ALT_PARAM_MASK ) >> ICU_EMIOS_PRESC_ALT_PARAM_SHIFT)
                                    );
            }
        }
        else
        {
            u8MasterBusIdx = (uint8)Icu_eMios_GetMasterBus(u8ModuleIdx, u8ChannelIdx, nCtrlBus);

            if(u8MasterBusUse[u8MasterBusIdx] == (uint8)0xFFU)
            {
                if (EMIOS_ICU_NORMAL_CLOCK_MODE == Prescaler)
                {
                    Icu_eMios_SetPrescaler(
                                            u8MasterBusIdx,
                                            (uint32)((nCtrlRegVal & ICU_EMIOS_PRESCALER_PARAM_MASK ) >> ICU_EMIOS_PRESCALER_PARAM_SHIFT)
                                          );
                }
                else
                {
                    Icu_eMios_SetPrescaler(
                                            u8MasterBusIdx,
                                            (uint32)((nCtrlRegVal & ICU_EMIOS_PRESC_ALT_PARAM_MASK ) >> ICU_EMIOS_PRESC_ALT_PARAM_SHIFT)
                                          );
                }
                u8MasterBusUse[u8MasterBusIdx] = (uint8)1U;
            }
        }
    }
}
/**
* @brief      Icu driver function that sets the channel prescaler.
* @details    This function:
*             - Clears GPREN bit in EMIOSMCR register and UCPREN bit in EMIOSC[n] register
*             - Writes prescaling rate at UCPRE[0:1] bits in EMIOSC[n] register
*             - Enables channel prescaler by setting UCPREN bit in EMIOSC[n] register
*             - Enables global prescaler by setting GPREN bit in EMIOSMCR register
*
* @param[in]  u32ChannelPrescaler       - prescaler for the hardware channel
* @param[in]  nHwChannel               - eMIOS encoded hardware channel
* @api
*/
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_eMios_SetPrescaler
(
    CONST(Icu_eMios_ChannelType,                AUTOMATIC) nHwChannel,
    CONST(uint32,                               AUTOMATIC) u32ChannelPrescaler
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    VAR(uint32, AUTOMATIC) u32RegMCR = REG_READ32(EMIOS_MCR_ADDR32(u8ModuleIdx));

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    VAR(uint32, AUTOMATIC) u32RegCCR = REG_READ32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx));

    SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_22();
    /* Clear GPREN bit */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(EMIOS_MCR_ADDR32(u8ModuleIdx), MCR_GPREN_MASK_U32);

    /* Clear GPRE bit */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_UCPREN_MASK_U32);

    /* Write prescaling rate at UCPRE[0:1] bits in EMIOSC[n] */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_CLEAR32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_UCPRE_MASK_U32);
    u32RegCCR &= ~CCR_UCPRE_MASK_U32;
    u32RegCCR |= (u32ChannelPrescaler << CCR_UCPRE_SHIFT);

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), u32RegCCR);

    /* Enable channel prescaler */
    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_BIT_SET32(EMIOS_CCR_ADDR32(u8ModuleIdx, u8ChannelIdx), CCR_UCPREN_MASK_U32);

    /* Enable global prescaler */
    if (MCR_GPREN_MASK_U32 == (u32RegMCR & MCR_GPREN_MASK_U32))
    {
        /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer*/
        /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_BIT_SET32(EMIOS_MCR_ADDR32(u8ModuleIdx), MCR_GPREN_MASK_U32);
    }
    SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_22();
}

#endif  /* ICU_DUAL_CLOCK_MODE_API == STD_ON */

#if (ICU_GET_INPUT_LEVEL_API == STD_ON)
/**
* @brief      This function returns the actual status of PIN.

* @details    This function returns the actual status o PIN
*
* @param[in]     nHwChannel      - eMIOS encoded hardware channel
*
* @return  void
*
* @api
* @violates @ref Icu_eMios_c_5 external ... could be made static
* @implements  Icu_eMios_GetInputLevel_Activity
*/
FUNC(boolean, ICU_CODE) Icu_eMios_GetInputLevel
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    CONST(uint8, ICU_CONST) u8ModuleIdx  = (uint8)(EMIOS_MODULE_INDEX_U8(nHwChannel));
    CONST(uint8, ICU_CONST) u8ChannelIdx = (uint8)(EMIOS_CHANNEL_INDEX_U8(nHwChannel));
    VAR(boolean, AUTOMATIC) bResult = (boolean)FALSE;

    /** @violates @ref Icu_eMios_c_3 Cast from unsigned long to pointer */
    /** @violates @ref Icu_eMios_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    bResult = (boolean) ((REG_READ32(EMIOS_CSR_ADDR32(u8ModuleIdx, u8ChannelIdx)) & CSR_UCIN_MASK_U32)>> CSR_UCIN_SHIFT);

    return bResult;

}
#endif /* ICU_GET_INPUT_LEVEL_API == STD_ON */

#if ((ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)))
FUNC(uint32, ICU_CODE) Icu_eMios_GetCaptureRegisterValue
(
    CONST(Icu_eMios_ChannelType,            AUTOMATIC) nHwChannel
)
{
    VAR(uint32, AUTOMATIC) u32CaptureRegisterValue;

    u32CaptureRegisterValue = Icu_eMios_GetCaptureRegA(nHwChannel);
    return u32CaptureRegisterValue;
}
#endif  /* (ICU_CAPTURERGISTER_API == STD_ON) && ((ICU_SIGNAL_MEASUREMENT_API == STD_ON) || (ICU_TIMESTAMP_API == STD_ON)) */

#if ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))
/**
* @brief      This function returns the signals High time, Low time and Period without using the
*             channel interrupt
* @details    This function returns the signals High time, Low time and Period without using the
*             channel interrupt
*
* @param[in]  nHwChannel          - eMIOS hardware channel
* @implements Icu_eMios_GetPulseWidth_Activity
*/
FUNC(void, ICU_CODE) Icu_eMios_GetPulseWidth
(
    CONST(Icu_eMios_ChannelType, AUTOMATIC) nHwChannel
)
{
    Icu_eMios_SignalMeasurement(nHwChannel,(boolean)FALSE);
}
#endif /* ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

#if ((ICU_VALIDATE_GLOBAL_CALL == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON)))
FUNC (Std_ReturnType, ICU_CODE) Icu_eMios_ValidateSignalMeasureWithoutInterrupt
(
    VAR         (uint8,                   AUTOMATIC)                 u8IdxChannelConfig,
    CONSTP2CONST(Icu_eMios_IpConfigType,  AUTOMATIC, ICU_APPL_CONST) peMiosIpConfig
)
{
    /* Icu channel Emios specific parameters from config structure */
    P2CONST(Icu_eMios_ChannelConfigType,AUTOMATIC,ICU_APPL_CONST) peMiosChannelConfig;
    VAR(boolean,               AUTOMATIC)                         bSignalMeasureWithoutInterrupt;

    VAR(Std_ReturnType, AUTOMATIC) valid = (Std_ReturnType)E_OK;

    peMiosChannelConfig = &(*peMiosIpConfig->pChannelsConfig)[u8IdxChannelConfig];
    bSignalMeasureWithoutInterrupt = (peMiosChannelConfig->bSignalMeasure_WithoutInterrupt);

    if((boolean)TRUE == bSignalMeasureWithoutInterrupt)
    {
        valid = (Std_ReturnType)E_OK;
    }
    else
    {
        valid = (Std_ReturnType)E_NOT_OK;
    }
    return valid;
}
#endif /* (ICU_VALIDATE_PARAMS == STD_ON) && ((ICU_GET_PULSE_WIDTH_API == STD_ON) && (ICU_SIGNAL_MEASUREMENT_API == STD_ON))*/

#define ICU_STOP_SEC_CODE
/** @violates @ref Icu_eMios_c_1 only preprocessor statements and comments before "#include" */
/** @violates @ref Icu_eMios_c_2 precautions to prevent the contents of a header file being included
twice */
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
