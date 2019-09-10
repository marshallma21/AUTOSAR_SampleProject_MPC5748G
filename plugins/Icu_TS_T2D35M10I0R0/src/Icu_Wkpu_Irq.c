/**
*     @file    Icu_Wkpu_IRQ.c
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
* @section Icu_Wkpu_IRQ_c_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before
* "#include" MemMap.h/Icu_MemMap.h included after each section define in order to set the current memory section
*
* @section Icu_Wkpu_IRQ_c_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice
* This is not a violation since all header files are protected against multiple inclusions
*
* @section Icu_Wkpu_IRQ_c_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form
* of pointer arithmetic.
* The violation occurs because the variables are defined as per Autosar API specifications.
*
* @section Icu_Wkpu_IRQ_c_5
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integer type.
* This violation can not be avoided because it appears when addressing memory mapped
* registers or other hardware specific features.
*
* @section Icu_Wkpu_IRQ_c_6
* Violates MISRA 2004 Required Rule 8.10, could be made static
* The respective code could not be made static because of layers architecture design of the
* driver.
*
* @section Icu_Wkpu_IRQ_c_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
* and an integral type.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters.
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

#include "Icu_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED (ICU_USER_MODE_SOFT_LOCKING)
#include "SilRegMacros.h"

#include "Icu_Reg_eSys_WKPU.h"
#include "Icu_WKPU.h"

#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_Irq.h"

#include "SchM_Icu.h"
/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

#define ICU_WKPU_IRQ_VENDOR_ID_C         43

#define ICU_WKPU_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
#define ICU_WKPU_IRQ_AR_RELEASE_MINOR_VERSION_C     2
#define ICU_WKPU_IRQ_AR_RELEASE_REVISION_VERSION_C  2

#define ICU_WKPU_IRQ_SW_MAJOR_VERSION_C  1
#define ICU_WKPU_IRQ_SW_MINOR_VERSION_C  0
#define ICU_WKPU_IRQ_SW_PATCH_VERSION_C  0

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((ICU_WKPU_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_Irq.c and Mcal.h are different"
#endif
#endif

/* Check if source file and Icu_Cfg header file are of the same vendor */
#if (ICU_WKPU_IRQ_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_Wkpu_Irq.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_WKPU_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_WKPU_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_WKPU_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Wkpu_Irq.c are different"
#endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_WKPU_IRQ_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_WKPU_IRQ_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_WKPU_IRQ_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_Wkpu_Irq.c are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((ICU_WKPU_IRQ_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_Irq.c and SilRegMacros.h are different"
#endif
#endif

/* Check if source file and Icu_Reg_eSys_Wkpu.h file are of the same vendor */
#if (ICU_WKPU_IRQ_VENDOR_ID_C != ICU_REG_ESYS_WKPU_VENDOR_ID)
    #error "Icu_Wkpu_Irq.c and Icu_Reg_eSys_Wkpu.h have different vendor IDs"
#endif
/* Check if source file and Icu_Reg_eSys_Wkpu.h file are of the same Autosar version */
#if ((ICU_WKPU_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_REG_ESYS_WKPU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_REG_ESYS_WKPU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_REG_ESYS_WKPU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_Irq.c and Icu_Reg_eSys_Wkpu.h are different"
#endif
/* Check if source file and Icu_Reg_eSys_Wkpu.h header file are of the same Software version */
#if ((ICU_WKPU_IRQ_SW_MAJOR_VERSION_C != ICU_REG_ESYS_WKPU_SW_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_SW_MINOR_VERSION_C != ICU_REG_ESYS_WKPU_SW_MINOR_VERSION) || \
     (ICU_WKPU_IRQ_SW_PATCH_VERSION_C != ICU_REG_ESYS_WKPU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Wkpu_Irq.c and Icu_Reg_eSys_Wkpu.h are different"
#endif

/* Check if source file and Icu_Wkpu.h file are of the same vendor */
#if (ICU_WKPU_IRQ_VENDOR_ID_C != ICU_WKPU_VENDOR_ID)
    #error "Icu_Wkpu_Irq.c and Icu_Wkpu.h have different vendor IDs"
#endif
/* Check if source file and Icu_Wkpu.h file are of the same Autosar version */
#if ((ICU_WKPU_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_WKPU_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_WKPU_AR_RELEASE_MINOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_WKPU_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_Irq.c and Icu_Wkpu.h are different"
#endif
/* Check if source file and Icu_Wkpu.h file are of the same Software version */
#if ((ICU_WKPU_IRQ_SW_MAJOR_VERSION_C != ICU_WKPU_SW_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_SW_MINOR_VERSION_C != ICU_WKPU_SW_MINOR_VERSION) || \
     (ICU_WKPU_IRQ_SW_PATCH_VERSION_C != ICU_WKPU_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Wkpu_Irq.c and Icu_Wkpu.h are different"
#endif

/* Check if source file and Icu_Ipw_Types header file are of the same vendor */
#if (ICU_WKPU_IRQ_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_Wkpu_Irq.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Autosar version */
#if ((ICU_WKPU_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_Irq.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and Icu_Ipw_Types header file are of the same Software version */
#if ((ICU_WKPU_IRQ_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_WKPU_IRQ_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Wkpu_Irq.c and Icu_Ipw_Types.h are different"
#endif

/* Check if source file and Icu_Ipw_Types header file are of the same vendor */
#if (ICU_WKPU_IRQ_VENDOR_ID_C != ICU_IPW_IRQ_VENDOR_ID)
    #error "Icu_Wkpu_Irq.c and Icu_Ipw_Irq.h have different vendor IDs"
#endif
/* Check if source file and Icu_Ipw_Irq header file are of the same Autosar version */
#if ((ICU_WKPU_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_WKPU_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_Wkpu_Irq.c and Icu_Ipw_Irq.h are different"
#endif
/* Check if source file and Icu_Ipw_Irq header file are of the same Software version */
#if ((ICU_WKPU_IRQ_SW_MAJOR_VERSION_C != ICU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (ICU_WKPU_IRQ_SW_MINOR_VERSION_C != ICU_IPW_IRQ_SW_MINOR_VERSION) || \
     (ICU_WKPU_IRQ_SW_PATCH_VERSION_C != ICU_IPW_IRQ_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_Wkpu_Irq.c and Icu_Ipw_Irq.h are different"
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

#if (defined ICU_WKPU_SINGLE_INTERRUPT)
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_Wkpu_ProcessSingleInterrupt(void);
#else

#if ((defined ICU_WKPU_CH_0_ISR_USED) || (defined ICU_WKPU_CH_1_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_2_ISR_USED) || (defined ICU_WKPU_CH_3_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_4_ISR_USED) || (defined ICU_WKPU_CH_5_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_6_ISR_USED) || (defined ICU_WKPU_CH_7_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_8_ISR_USED) || (defined ICU_WKPU_CH_9_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_10_ISR_USED) || (defined ICU_WKPU_CH_11_ISR_USED) ||  \
     (defined ICU_WKPU_CH_12_ISR_USED) || (defined ICU_WKPU_CH_13_ISR_USED) ||  \
     (defined ICU_WKPU_CH_14_ISR_USED) || (defined ICU_WKPU_CH_15_ISR_USED) ||  \
     (defined ICU_WKPU_CH_16_ISR_USED) || (defined ICU_WKPU_CH_17_ISR_USED) ||  \
     (defined ICU_WKPU_CH_18_ISR_USED) || (defined ICU_WKPU_CH_19_ISR_USED) ||  \
     (defined ICU_WKPU_CH_20_ISR_USED) || (defined ICU_WKPU_CH_21_ISR_USED) ||  \
     (defined ICU_WKPU_CH_22_ISR_USED) || (defined ICU_WKPU_CH_23_ISR_USED) ||  \
     (defined ICU_WKPU_CH_24_ISR_USED) || (defined ICU_WKPU_CH_25_ISR_USED) ||  \
     (defined ICU_WKPU_CH_26_ISR_USED) || (defined ICU_WKPU_CH_27_ISR_USED) ||  \
     (defined ICU_WKPU_CH_28_ISR_USED) || (defined ICU_WKPU_CH_29_ISR_USED) ||  \
     (defined ICU_WKPU_CH_30_ISR_USED) || (defined ICU_WKPU_CH_31_ISR_USED))
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_WKPU_ProcessInterrupt(CONST(uint8, AUTOMATIC) u8FirstHwChannel);
#endif
#endif /*defined ICU_WKPU_SINGLE_INTERRUPT*/

#if (defined ICU_WKPU_SINGLE_INTERRUPT)
ISR(WKPU_EXT_IRQ_SINGLE_0_31_ISR);
#else

#if ((defined ICU_WKPU_CH_0_ISR_USED) || (defined ICU_WKPU_CH_1_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_2_ISR_USED) || (defined ICU_WKPU_CH_3_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_4_ISR_USED) || (defined ICU_WKPU_CH_5_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_6_ISR_USED) || (defined ICU_WKPU_CH_7_ISR_USED))
ISR(WKPU_EXT_IRQ_0_7_ISR);
#endif

#if ((defined ICU_WKPU_CH_8_ISR_USED)  || (defined ICU_WKPU_CH_9_ISR_USED)   || \
     (defined ICU_WKPU_CH_10_ISR_USED) || (defined ICU_WKPU_CH_11_ISR_USED)  || \
     (defined ICU_WKPU_CH_12_ISR_USED) || (defined ICU_WKPU_CH_13_ISR_USED)  || \
     (defined ICU_WKPU_CH_14_ISR_USED) || (defined ICU_WKPU_CH_15_ISR_USED))
ISR(WKPU_EXT_IRQ_8_15_ISR);
#endif

#if ((defined ICU_WKPU_CH_16_ISR_USED) || (defined ICU_WKPU_CH_17_ISR_USED)  || \
     (defined ICU_WKPU_CH_18_ISR_USED) || (defined ICU_WKPU_CH_19_ISR_USED)  || \
     (defined ICU_WKPU_CH_20_ISR_USED) || (defined ICU_WKPU_CH_21_ISR_USED)  || \
     (defined ICU_WKPU_CH_22_ISR_USED) || (defined ICU_WKPU_CH_23_ISR_USED))
ISR(WKPU_EXT_IRQ_16_23_ISR);
#endif

#if ((defined ICU_WKPU_CH_24_ISR_USED) || (defined ICU_WKPU_CH_25_ISR_USED)  || \
     (defined ICU_WKPU_CH_26_ISR_USED) || (defined ICU_WKPU_CH_27_ISR_USED)  || \
     (defined ICU_WKPU_CH_28_ISR_USED) || (defined ICU_WKPU_CH_29_ISR_USED)  || \
     (defined ICU_WKPU_CH_30_ISR_USED) || (defined ICU_WKPU_CH_31_ISR_USED))
ISR(WKPU_EXT_IRQ_24_31_ISR);
#endif
#endif /*defined ICU_WKPU_SINGLE_INTERRUPT*/
/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/**
* @violates @ref Icu_Wkpu_IRQ_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before "#include"
*
* @violates @ref Icu_Wkpu_IRQ_c_3 precautions to prevent the contents
* of a header file being included twice
*/
#include "Icu_MemMap.h"

#if (defined ICU_WKPU_SINGLE_INTERRUPT)
/*==================================================================================================*/
/**
* @brief      Icu_Wkpu_ProcessSingleInterrupt
* @details
*
* @param[in]      u8FirstHwChannel - first IRQ HW Channel from the HW group
*
* @retval None
* @violates @ref Icu_Wkpu_IRQ_c_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*==================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_Wkpu_ProcessSingleInterrupt()
{

    VAR(uint8,  AUTOMATIC) u8WkpuChannel = 0U;
    VAR(uint32, AUTOMATIC) u32ChannelMask = 0x00000001U;
    VAR(uint32, AUTOMATIC) u32RegIrqMask = 0xFFFFFFFFU;

    /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
    /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32reg_WKPU_WISR = REG_READ32(ICU_WKPU_WISR_ADDR32);

    /* Get  WKPU0 -WKPU31 flags that has Interrupt enable bit set*/
    /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
    /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32RegIrqMask = (u32RegIrqMask & (u32reg_WKPU_WISR & REG_READ32(ICU_WKPU_IRER_ADDR32)));

    if(u32RegIrqMask > (uint32)0)
    {
        /* Clear pending interrupt serviced */
        /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
        /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(ICU_WKPU_WISR_ADDR32, u32RegIrqMask);
        while(0x0U != u32RegIrqMask)
        {
            if (0x0U != (u32RegIrqMask & u32ChannelMask))
            {
                /* @violates @ref Icu_Wkpu_IRQ_c_4 Array indexing shall be the only allowed form of
                pointer arithmetic.*/
                Icu_Ipw_ReportEvents(ICU_WKPU_HW_CHANNEL((uint16)u8WkpuChannel),(boolean)FALSE);
                /* clear the IRQ bit for current IRQ channel*/
                u32RegIrqMask = (u32RegIrqMask & ~u32ChannelMask);
            }
            u8WkpuChannel++;
            u32ChannelMask <<= (uint32)1U;
        }
    }
}

#else

#if ((defined ICU_WKPU_CH_0_ISR_USED) || (defined ICU_WKPU_CH_1_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_2_ISR_USED) || (defined ICU_WKPU_CH_3_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_4_ISR_USED) || (defined ICU_WKPU_CH_5_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_6_ISR_USED) || (defined ICU_WKPU_CH_7_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_8_ISR_USED) || (defined ICU_WKPU_CH_9_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_10_ISR_USED) || (defined ICU_WKPU_CH_11_ISR_USED) ||  \
     (defined ICU_WKPU_CH_12_ISR_USED) || (defined ICU_WKPU_CH_13_ISR_USED) ||  \
     (defined ICU_WKPU_CH_14_ISR_USED) || (defined ICU_WKPU_CH_15_ISR_USED) ||  \
     (defined ICU_WKPU_CH_16_ISR_USED) || (defined ICU_WKPU_CH_17_ISR_USED) ||  \
     (defined ICU_WKPU_CH_18_ISR_USED) || (defined ICU_WKPU_CH_19_ISR_USED) ||  \
     (defined ICU_WKPU_CH_20_ISR_USED) || (defined ICU_WKPU_CH_21_ISR_USED) ||  \
     (defined ICU_WKPU_CH_22_ISR_USED) || (defined ICU_WKPU_CH_23_ISR_USED) ||  \
     (defined ICU_WKPU_CH_24_ISR_USED) || (defined ICU_WKPU_CH_25_ISR_USED) ||  \
     (defined ICU_WKPU_CH_26_ISR_USED) || (defined ICU_WKPU_CH_27_ISR_USED) ||  \
     (defined ICU_WKPU_CH_28_ISR_USED) || (defined ICU_WKPU_CH_29_ISR_USED) ||  \
     (defined ICU_WKPU_CH_30_ISR_USED) || (defined ICU_WKPU_CH_31_ISR_USED))
/*==================================================================================================*/
/**
* @brief      Icu_WKPU_ProcessInterrupt
* @details
*
* @param[in]      u8FirstHwChannel - first IRQ HW Channel from the HW group
*
* @retval None
*/
/*==================================================================================================*/
LOCAL_INLINE FUNC (void, ICU_CODE) Icu_WKPU_ProcessInterrupt(CONST(uint8, AUTOMATIC) u8FirstHwChannel)
{
    VAR(uint8,  AUTOMATIC) u8WkpuChannel = u8FirstHwChannel;
    VAR(uint32, AUTOMATIC) u32ChannelMask = ICU_WKPU_CHANNEL_MASK(u8FirstHwChannel);
    VAR(uint32, AUTOMATIC) u32RegIrqMask = ICU_WKPU_IRQ_CHANNEL_GROUP_MASK(u8FirstHwChannel);

    /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
    /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32reg_WKPU_WISR = REG_READ32(ICU_WKPU_WISR_ADDR32);

    /* Get  WKPU0 -WKPU31 flags that has Interrupt enable bit set*/
    /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
    /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    u32RegIrqMask = (u32RegIrqMask & (u32reg_WKPU_WISR & REG_READ32(ICU_WKPU_IRER_ADDR32)));

    if(u32RegIrqMask > (uint32)0)
    {
        /* Clear pending interrupt serviced */
        /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
        /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
        REG_WRITE32(ICU_WKPU_WISR_ADDR32, u32RegIrqMask );
        while(0x0U != u32RegIrqMask)
        {
            if (0x0U != (u32RegIrqMask & u32ChannelMask))
            {
                /* @violates @ref Icu_Wkpu_IRQ_c_4 Array indexing shall be the only allowed form of
                pointer arithmetic.*/
                Icu_Ipw_ReportEvents(ICU_WKPU_HW_CHANNEL((uint16)u8WkpuChannel),(boolean)FALSE);
                /* clear the IRQ bit for current IRQ channel*/
                u32RegIrqMask = (u32RegIrqMask & ~u32ChannelMask);
            }
            u8WkpuChannel++;
            u32ChannelMask <<= (uint32)1U;
        }
    }
}
#endif
#endif /*defined ICU_WKPU_SINGLE_INTERRUPT*/

/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (defined ICU_WKPU_SINGLE_INTERRUPT)
/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 0 to 31
* @details   Process the interrupt of WKPU channels 0 to 31 for platforms with only one interrupt line
*
* @remarks   This will be defined only if any of WKPU channels 0 to 31 are configured
* @violates @ref Icu_Wkpu_IRQ_c_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_SINGLE_0_31_ISR)
{
    Icu_Wkpu_ProcessSingleInterrupt();

    EXIT_INTERRUPT();
}
#else

#if ((defined ICU_WKPU_CH_0_ISR_USED) || (defined ICU_WKPU_CH_1_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_2_ISR_USED) || (defined ICU_WKPU_CH_3_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_4_ISR_USED) || (defined ICU_WKPU_CH_5_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_6_ISR_USED) || (defined ICU_WKPU_CH_7_ISR_USED))
/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 0 to 7
* @details   Process the interrupt of WKPU channels 0 to 7
*
* @remarks   This will be defined only if any of WKPU channels 0 to 7 is configured
* @violates @ref Icu_Wkpu_IRQ_c_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_0_7_ISR)
{
    Icu_WKPU_ProcessInterrupt(ICU_WKPU_0);
    /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
    /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}
#endif  /* WKPU IRQ 0 - 7 */


#if ((defined ICU_WKPU_CH_8_ISR_USED) || (defined ICU_WKPU_CH_9_ISR_USED)   ||  \
     (defined ICU_WKPU_CH_10_ISR_USED) || (defined ICU_WKPU_CH_11_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_12_ISR_USED) || (defined ICU_WKPU_CH_13_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_14_ISR_USED) || (defined ICU_WKPU_CH_15_ISR_USED))
/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 8 to 15
* @details   Process the interrupt of WKPU channels 8 to 15
*
* @remarks   This will be defined only if any of WKPU channels 8 to 15 is configured
* @violates @ref Icu_Wkpu_IRQ_c_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_8_15_ISR)
{
    Icu_WKPU_ProcessInterrupt(ICU_WKPU_8);
    /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
    /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}
#endif  /* WKPU IRQ 8 - 15 */


#if ((defined ICU_WKPU_CH_16_ISR_USED) || (defined ICU_WKPU_CH_17_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_18_ISR_USED) || (defined ICU_WKPU_CH_19_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_20_ISR_USED) || (defined ICU_WKPU_CH_21_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_22_ISR_USED) || (defined ICU_WKPU_CH_23_ISR_USED))
/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 16 to 23
* @details   Process the interrupt of WKPU channels 16 to 23
*
* @remarks   This will be defined only if any of WKPU channels 16 to 23 is configured
* @violates @ref Icu_Wkpu_IRQ_c_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_16_23_ISR)
{
    Icu_WKPU_ProcessInterrupt(ICU_WKPU_16);
    /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
    /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}
#endif   /* WKPU IRQ 16 - 23 */


#if ((defined ICU_WKPU_CH_24_ISR_USED) || (defined ICU_WKPU_CH_25_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_26_ISR_USED) || (defined ICU_WKPU_CH_27_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_28_ISR_USED) || (defined ICU_WKPU_CH_29_ISR_USED)  ||  \
     (defined ICU_WKPU_CH_30_ISR_USED) || (defined ICU_WKPU_CH_31_ISR_USED))
/*==================================================================================================*/
/**
* @brief     Interrupt handler for WKPU channels : 24 to 31
* @details   Process the interrupt of WKPU channels 24 to 31
*
* @remarks   This will be defined only if any of WKPU channels 24 to 31 is configured
* @violates @ref Icu_Wkpu_IRQ_c_6 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*==================================================================================================*/
ISR(WKPU_EXT_IRQ_24_31_ISR)
{
    Icu_WKPU_ProcessInterrupt(ICU_WKPU_24);
    /** @violates @ref Icu_Wkpu_IRQ_c_5 Cast from unsigned long to pointer */
    /** @violates @ref Icu_Wkpu_IRQ_c_7 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}
#endif   /* WKPU IRQ 24 - 31 */
#endif   /* defined ICU_WKPU_SINGLE_INTERRUPT */

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_Wkpu_IRQ_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
* and comments before "#include"
*
* @violates @ref Icu_Wkpu_IRQ_c_3 precautions to prevent the contents
* of a header file being included twice
*/
#include "Icu_MemMap.h"

#ifdef __cplusplus
}
#endif
/**@}*/
