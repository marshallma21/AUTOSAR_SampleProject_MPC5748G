/**
*     @version 1.0.0
*
*     @brief   AUTOSAR Icu - SIUL source file support for ICU driver.
*     @details SIUL source file, containing the variables and functions that are exported by the SIUL driver.
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
* @section Icu_SIUL2_Irq_c_1
*          Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*          and comments before '#include'. This is an Autosar requirement about
*          the memory management (Autosar requirement MEMMAP003).
*
* @section Icu_SIUL2_Irq_c_2
*          Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
*          prevent the contents of a header file being included twice. All header files are
*          protected against multiple inclusions.
*
* @section Icu_SIUL2_Irq_c_3
*          Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
*          pointer to a function and a type other than an integral type. This violation is due to
*          the pointer arithmetic used to write/ read the data to/from the registers
*
* @section Icu_SIUL2_Irq_c_4
*          Violates MISRA 2004 Required Rule 8.10, could be made static
*          The respective code could not be made static because of layers architecture design of the
*          driver.
*
* @section Icu_SIUL2_Irq_c_5
*          Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type
*          and an integral type.
*
* @section [global]
*          Violates MISRA 2004 Required Rule 5.1,Identifiers (internal and external) shall not rely
*          on the significance of more than 31 characters.The used compilers use more than 31 chars
*          for identifiers.
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

#include "Icu_Reg_eSys_Siul2.h"
#include "Icu_Siul2.h"

#include "Icu_Ipw_Types.h"
#include "Icu_Ipw_Irq.h"

#include "SchM_Icu.h"

/*==================================================================================================
*                                         LOCAL MACROS
==================================================================================================*/

/**
* @{
* @brief          Source file version information
* */
#define ICU_SIUL2_IRQ_VENDOR_ID_C                      43
#define ICU_SIUL2_IRQ_AR_RELEASE_MAJOR_VERSION_C       4
#define ICU_SIUL2_IRQ_AR_RELEASE_MINOR_VERSION_C       2
#define ICU_SIUL2_IRQ_AR_RELEASE_REVISION_VERSION_C    2
#define ICU_SIUL2_IRQ_SW_MAJOR_VERSION_C               1
#define ICU_SIUL2_IRQ_SW_MINOR_VERSION_C               0
#define ICU_SIUL2_IRQ_SW_PATCH_VERSION_C               0
/**@}*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_SIUL2_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL2_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION))
            #error "AutoSar Version Numbers of Icu_Siul2_Irq.c and Mcal.h are different"
    #endif
#endif


#if (ICU_SIUL2_IRQ_VENDOR_ID_C != ICU_VENDOR_ID_CFG)
    #error "Icu_Siul2_Irq.c and Icu_Cfg.h have different vendor IDs"
#endif
/* Check if source file and Icu_Cfg header file are of the same Autosar version */
#if ((ICU_SIUL2_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (ICU_SIUL2_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_AR_RELEASE_MINOR_VERSION_CFG) || \
     (ICU_SIUL2_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of Icu_Cfg.h and Icu_Siul2_Irq.c are different"
#endif
/* Check if source file and Icu_Cfg header file are of the same Software version */
#if ((ICU_SIUL2_IRQ_SW_MAJOR_VERSION_C != ICU_SW_MAJOR_VERSION_CFG) || \
     (ICU_SIUL2_IRQ_SW_MINOR_VERSION_C != ICU_SW_MINOR_VERSION_CFG) || \
     (ICU_SIUL2_IRQ_SW_PATCH_VERSION_C != ICU_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of Icu_Cfg.h and Icu_Siul2_Irq.c are different"
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((ICU_SIUL2_IRQ_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL2_IRQ_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Icu_Siul2_Irq.c and SilRegMacros.h are different"
    #endif
#endif

/* Check if source file and Icu_Reg_eSys_Siul2.h file are of the same vendor */
#if (ICU_SIUL2_IRQ_VENDOR_ID_C != ICU_REGESYS_SIUL2_VENDOR_ID)
    #error "Icu_SIUL2_Irq.c and Icu_Reg_eSys_Siul2.h have different vendor IDs"
#endif
#if ((ICU_SIUL2_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_REGESYS_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_SIUL2_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_REGESYS_SIUL2_AR_RELEASE_MINOR_VERSION) || \
     (ICU_SIUL2_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_REGESYS_SIUL2_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_SIUL2_Irq.c and Icu_Reg_eSys_Siul2.h are different"
#endif
/* Check if source file and Icu_Siul2.h header file are of the same Software version */
#if ((ICU_SIUL2_IRQ_SW_MAJOR_VERSION_C != ICU_REGESYS_SIUL2_SW_MAJOR_VERSION) || \
     (ICU_SIUL2_IRQ_SW_MINOR_VERSION_C != ICU_REGESYS_SIUL2_SW_MINOR_VERSION) || \
     (ICU_SIUL2_IRQ_SW_PATCH_VERSION_C != ICU_REGESYS_SIUL2_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_SIUL2_Irq.c and Icu_Reg_eSys_Siul2.h are different"
#endif


/* Check if source file and Icu_Siul2.h file are of the same vendor */
#if (ICU_SIUL2_IRQ_VENDOR_ID_C != ICU_SIUL2_VENDOR_ID)
    #error "Icu_SIUL2_Irq.c and Icu_Siul2.h have different vendor IDs"
#endif
#if ((ICU_SIUL2_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
         (ICU_SIUL2_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_SIUL2_AR_RELEASE_MINOR_VERSION) || \
         (ICU_SIUL2_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_SIUL2_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Icu_SIUL2_Irq.c and Icu_Siul2.h are different"
#endif
/* Check if source file and Icu_Siul2_Types.h file are of the same Software version */
#if ((ICU_SIUL2_IRQ_SW_MAJOR_VERSION_C != ICU_SIUL2_SW_MAJOR_VERSION) || \
     (ICU_SIUL2_IRQ_SW_MINOR_VERSION_C != ICU_SIUL2_SW_MINOR_VERSION) || \
     (ICU_SIUL2_IRQ_SW_PATCH_VERSION_C != ICU_SIUL2_SW_PATCH_VERSION))
    #error "Software Version Numbers of Icu_SIUL2_Irq.c and Icu_SIUL2.h are different"
#endif


#if (ICU_SIUL2_IRQ_VENDOR_ID_C != ICU_IPW_TYPES_VENDOR_ID)
    #error "Icu_SIUL2_Irq.c and Icu_Ipw_Types.h have different vendor IDs"
#endif
/* Check if source file and Icu_IPW_Types header file are of the same Autosar version */
#if ((ICU_SIUL2_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_SIUL2_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_MINOR_VERSION) || \
     (ICU_SIUL2_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_TYPES_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_SIUL2_Irq.c and Icu_Ipw_Types.h are different"
#endif
/* Check if source file and Icu_IPW_Types header file are of the same Software version */
#if ((ICU_SIUL2_IRQ_SW_MAJOR_VERSION_C != ICU_IPW_TYPES_SW_MAJOR_VERSION) || \
     (ICU_SIUL2_IRQ_SW_MINOR_VERSION_C != ICU_IPW_TYPES_SW_MINOR_VERSION) || \
     (ICU_SIUL2_IRQ_SW_PATCH_VERSION_C != ICU_IPW_TYPES_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_SIUL2_Irq.c and Icu_Ipw_Types.h are different"
#endif


#if (ICU_SIUL2_IRQ_VENDOR_ID_C != ICU_IPW_IRQ_VENDOR_ID)
    #error "Icu_SIUL2_Irq.c and Icu_Ipw_Irq.h have different vendor IDs"
#endif
/* Check if source file and Icu_IPW_Irq header file are of the same Autosar version */
#if ((ICU_SIUL2_IRQ_AR_RELEASE_MAJOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (ICU_SIUL2_IRQ_AR_RELEASE_MINOR_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (ICU_SIUL2_IRQ_AR_RELEASE_REVISION_VERSION_C != ICU_IPW_IRQ_AR_RELEASE_REVISION_VERSION))
#error "AutoSar Version Numbers of Icu_SIUL2_Irq.c and Icu_Ipw_Irq.h are different"
#endif
/* Check if source file and Icu_IPW_Irq header file are of the same Software version */
#if ((ICU_SIUL2_IRQ_SW_MAJOR_VERSION_C != ICU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (ICU_SIUL2_IRQ_SW_MINOR_VERSION_C != ICU_IPW_IRQ_SW_MINOR_VERSION) || \
     (ICU_SIUL2_IRQ_SW_PATCH_VERSION_C != ICU_IPW_IRQ_SW_PATCH_VERSION))
#error "Software Version Numbers of Icu_SIUL2_Irq.c and Icu_Ipw_Irq.h are different"
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

#if (ICU_IRQ_SINGLE_INTERRUPT == STD_ON)

ISR(ICU_EXT_IRQ_SINGLE_INTERRUPT);
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Siul2_ProcessSingleInterrupt(void);
#else

#if ((defined ICU_IRQ_CH_0_ISR_USED) || (defined ICU_IRQ_CH_1_ISR_USED) ||\
     (defined ICU_IRQ_CH_2_ISR_USED) || (defined ICU_IRQ_CH_3_ISR_USED) ||\
     (defined ICU_IRQ_CH_4_ISR_USED) || (defined ICU_IRQ_CH_5_ISR_USED) ||\
     (defined ICU_IRQ_CH_6_ISR_USED) || (defined ICU_IRQ_CH_7_ISR_USED))
ISR(SIUL2_EXT_IRQ_0_7_ISR);
#endif

#if ((defined ICU_IRQ_CH_8_ISR_USED) || (defined ICU_IRQ_CH_9_ISR_USED) ||\
     (defined ICU_IRQ_CH_10_ISR_USED) || (defined ICU_IRQ_CH_11_ISR_USED) ||\
     (defined ICU_IRQ_CH_12_ISR_USED) || (defined ICU_IRQ_CH_13_ISR_USED) ||\
     (defined ICU_IRQ_CH_14_ISR_USED) || (defined ICU_IRQ_CH_15_ISR_USED))
ISR(SIUL2_EXT_IRQ_8_15_ISR);
#endif

#if ((defined ICU_IRQ_CH_16_ISR_USED) || (defined ICU_IRQ_CH_17_ISR_USED) || \
     (defined ICU_IRQ_CH_18_ISR_USED) || (defined ICU_IRQ_CH_19_ISR_USED) || \
     (defined ICU_IRQ_CH_20_ISR_USED) || (defined ICU_IRQ_CH_21_ISR_USED) || \
     (defined ICU_IRQ_CH_22_ISR_USED) || (defined ICU_IRQ_CH_23_ISR_USED))
ISR(SIUL2_EXT_IRQ_16_23_ISR);
#endif

#if ((defined ICU_IRQ_CH_24_ISR_USED) || (defined ICU_IRQ_CH_25_ISR_USED) || \
     (defined ICU_IRQ_CH_26_ISR_USED) || (defined ICU_IRQ_CH_27_ISR_USED) || \
     (defined ICU_IRQ_CH_28_ISR_USED) || (defined ICU_IRQ_CH_29_ISR_USED) || \
     (defined ICU_IRQ_CH_30_ISR_USED) || (defined ICU_IRQ_CH_31_ISR_USED))
ISR(SIUL2_EXT_IRQ_24_31_ISR);
#endif
#if ((defined ICU_IRQ_CH_0_ISR_USED)  || (defined ICU_IRQ_CH_1_ISR_USED) \
    || (defined ICU_IRQ_CH_2_ISR_USED) || (defined ICU_IRQ_CH_3_ISR_USED) \
    || (defined ICU_IRQ_CH_4_ISR_USED) || (defined ICU_IRQ_CH_5_ISR_USED) \
    || (defined ICU_IRQ_CH_6_ISR_USED) || (defined ICU_IRQ_CH_7_ISR_USED) \
    || (defined ICU_IRQ_CH_8_ISR_USED) || (defined ICU_IRQ_CH_9_ISR_USED) \
    || (defined ICU_IRQ_CH_10_ISR_USED) || (defined ICU_IRQ_CH_11_ISR_USED) \
    || (defined ICU_IRQ_CH_12_ISR_USED) || (defined ICU_IRQ_CH_13_ISR_USED) \
    || (defined ICU_IRQ_CH_14_ISR_USED) || (defined ICU_IRQ_CH_15_ISR_USED) \
    || (defined ICU_IRQ_CH_16_ISR_USED) || (defined ICU_IRQ_CH_17_ISR_USED) \
    || (defined ICU_IRQ_CH_18_ISR_USED) || (defined ICU_IRQ_CH_19_ISR_USED) \
    || (defined ICU_IRQ_CH_20_ISR_USED) || (defined ICU_IRQ_CH_21_ISR_USED) \
    || (defined ICU_IRQ_CH_22_ISR_USED) || (defined ICU_IRQ_CH_23_ISR_USED) \
    || (defined ICU_IRQ_CH_24_ISR_USED) || (defined ICU_IRQ_CH_25_ISR_USED) \
    || (defined ICU_IRQ_CH_26_ISR_USED) || (defined ICU_IRQ_CH_27_ISR_USED) \
    || (defined ICU_IRQ_CH_28_ISR_USED) || (defined ICU_IRQ_CH_29_ISR_USED) \
    || (defined ICU_IRQ_CH_30_ISR_USED) || (defined ICU_IRQ_CH_31_ISR_USED))
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Siul2_ProcessInterrupt(CONST(uint8, AUTOMATIC) FirstHwChannel);
#endif
#endif /* ICU_IRQ_SINGLE_INTERRUPT */

/*==================================================================================================
*                                        LOCAL FUNCTIONS
==================================================================================================*/
#define ICU_START_SEC_CODE
/**
* @brief Include Memory mapping specification
* @violates @ref Icu_SIUL2_Irq_c_1 MISRA 2004 Required Rule 19.1 , only preprocessor statements
*                and comments before '#include'
* @violates @ref Icu_SIUL2_Irq_c_2 MISRA 2004 Required Rule 19.15 precautions to prevent the contents
*                of a header file being included twice
*/
#include "Icu_MemMap.h"

#if (ICU_IRQ_SINGLE_INTERRUPT == STD_ON)

/**
* @brief      Icu_Siul2_ProcessSingleInterrupt
* @details
*
*
* @return void
*
* @implements Icu_Siul2_ProcessSingleInterrupt_Activity
*
* */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Siul2_ProcessSingleInterrupt()
{
    VAR(uint8, AUTOMATIC) u8IrqChannel = 0U;
    VAR(uint32, AUTOMATIC) u32ChannelMask = 1U;
    VAR(uint32, AUTOMATIC) u32RegIrqMask = 0U;

    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegSIUL2DISR = REG_READ32(ICU_SIUL2_DISR0_ADDR32);
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegSIUL2DIRER = REG_READ32(ICU_SIUL2_DIRER0_LOCKABLE_ADDR32);

    /* Clear pending interrupt serviced */
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(ICU_SIUL2_DISR0_ADDR32, u32RegSIUL2DISR);

    u32RegIrqMask = u32RegSIUL2DISR & u32RegSIUL2DIRER;

    while(0x0U != u32RegIrqMask)
    {
        if (0x0U != (u32RegIrqMask & u32ChannelMask))
        {
            if(Icu_Siul2_GetChInit(u8IrqChannel))
            {
                Icu_Ipw_ReportEvents(ICU_IRQ_HW_CHANNEL((uint16)u8IrqChannel), (boolean)FALSE);
            }
            /* clear the IRQ bit for current IRQ channel*/
            u32RegIrqMask = u32RegIrqMask & (uint32)(~u32ChannelMask);
        }
        u8IrqChannel++;
        u32ChannelMask <<= (uint32)1;
    }
}

#else
#if ((defined ICU_IRQ_CH_0_ISR_USED)  || (defined ICU_IRQ_CH_1_ISR_USED) \
    || (defined ICU_IRQ_CH_2_ISR_USED) || (defined ICU_IRQ_CH_3_ISR_USED) \
    || (defined ICU_IRQ_CH_4_ISR_USED) || (defined ICU_IRQ_CH_5_ISR_USED) \
    || (defined ICU_IRQ_CH_6_ISR_USED) || (defined ICU_IRQ_CH_7_ISR_USED) \
    || (defined ICU_IRQ_CH_8_ISR_USED) || (defined ICU_IRQ_CH_9_ISR_USED) \
    || (defined ICU_IRQ_CH_10_ISR_USED) || (defined ICU_IRQ_CH_11_ISR_USED) \
    || (defined ICU_IRQ_CH_12_ISR_USED) || (defined ICU_IRQ_CH_13_ISR_USED) \
    || (defined ICU_IRQ_CH_14_ISR_USED) || (defined ICU_IRQ_CH_15_ISR_USED) \
    || (defined ICU_IRQ_CH_16_ISR_USED) || (defined ICU_IRQ_CH_17_ISR_USED) \
    || (defined ICU_IRQ_CH_18_ISR_USED) || (defined ICU_IRQ_CH_19_ISR_USED) \
    || (defined ICU_IRQ_CH_20_ISR_USED) || (defined ICU_IRQ_CH_21_ISR_USED) \
    || (defined ICU_IRQ_CH_22_ISR_USED) || (defined ICU_IRQ_CH_23_ISR_USED) \
    || (defined ICU_IRQ_CH_24_ISR_USED) || (defined ICU_IRQ_CH_25_ISR_USED) \
    || (defined ICU_IRQ_CH_26_ISR_USED) || (defined ICU_IRQ_CH_27_ISR_USED) \
    || (defined ICU_IRQ_CH_28_ISR_USED) || (defined ICU_IRQ_CH_29_ISR_USED) \
    || (defined ICU_IRQ_CH_30_ISR_USED) || (defined ICU_IRQ_CH_31_ISR_USED))
/**
* @brief      Icu_Siul2_ProcessInterrupt
* @details
*
* @param[in]      FirstHwChannel - first IRQ HW Channel from the HW group
*
* @return void
*
* @implements Icu_Siul2_ProcessInterrupt_Activity
*
* */
LOCAL_INLINE FUNC(void, ICU_CODE) Icu_Siul2_ProcessInterrupt(CONST(uint8, AUTOMATIC) FirstHwChannel)
{
    VAR(uint8,  AUTOMATIC) u8IrqChannel = FirstHwChannel;
    VAR(uint32, AUTOMATIC) u32ChannelMask = ICU_SIUL2_CHANNEL_MASK_U32((uint32)FirstHwChannel);
    VAR(uint32, AUTOMATIC) u32RegIrqMask = ICU_SIUL2_IRQ_CHANNEL_GROUP_MASK_U32((uint32)FirstHwChannel);

    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegSIUL2DISR = REG_READ32(ICU_SIUL2_DISR0_ADDR32);
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    CONST(uint32, ICU_CONST) u32RegSIUL2DIRER = REG_READ32(ICU_SIUL2_DIRER0_LOCKABLE_ADDR32);

    /* Clear pending interrupt serviced */
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    REG_WRITE32(ICU_SIUL2_DISR0_ADDR32, u32RegIrqMask & u32RegSIUL2DISR);

    /* Get only IRQ4 .. IRQ15 flags that has Interrupt enable bit set*/
    u32RegIrqMask = u32RegIrqMask & u32RegSIUL2DISR & u32RegSIUL2DIRER;

    while(0x0U != u32RegIrqMask)
    {
        if (0x0U != (u32RegIrqMask & u32ChannelMask))
        {
            if(Icu_Siul2_GetChInit(u8IrqChannel))
            {
                Icu_Ipw_ReportEvents(ICU_IRQ_HW_CHANNEL((uint16)u8IrqChannel),(boolean)FALSE);
            }
            /* clear the IRQ bit for current IRQ channel*/
            u32RegIrqMask = u32RegIrqMask & (uint32)(~u32ChannelMask);
        }
        u8IrqChannel++;
        u32ChannelMask <<= (uint32)1;
    }
}
#endif
#endif /* ICU_IRQ_SINGLE_INTERRUPT */
/*==================================================================================================
*                                        GLOBAL FUNCTIONS
==================================================================================================*/

#if (ICU_IRQ_SINGLE_INTERRUPT == STD_ON)
/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL2 channels : 0 to 29
* @details   Process the interrupt of SIUL2 channels 0 to 29
*
* @isr
*
* *
* @note   This will be defined only if the single interrupt mode is configured
* @violates @ref Icu_SIUL2_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(ICU_EXT_IRQ_SINGLE_INTERRUPT)
{
    Icu_Siul2_ProcessSingleInterrupt();
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}

#else

#if ((defined ICU_IRQ_CH_0_ISR_USED) || (defined ICU_IRQ_CH_1_ISR_USED) ||\
     (defined ICU_IRQ_CH_2_ISR_USED) || (defined ICU_IRQ_CH_3_ISR_USED) ||\
     (defined ICU_IRQ_CH_4_ISR_USED) || (defined ICU_IRQ_CH_5_ISR_USED) ||\
     (defined ICU_IRQ_CH_6_ISR_USED) || (defined ICU_IRQ_CH_7_ISR_USED))
/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL channels : 0 to 7
* @details   Process the interrupt of SIUL channels 0 to 7
*
* @isr
*
* *
* @note   This will be defined only if any of SIUL channels 0 to 7 is configured
* @violates @ref Icu_SIUL2_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(SIUL2_EXT_IRQ_0_7_ISR)
{
    Icu_Siul2_ProcessInterrupt(ICU_SIUL2_IRQ_0);
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}
#endif  /* IRQ 0 - 7 */


#if ((defined ICU_IRQ_CH_8_ISR_USED) || (defined ICU_IRQ_CH_9_ISR_USED) ||\
     (defined ICU_IRQ_CH_10_ISR_USED) || (defined ICU_IRQ_CH_11_ISR_USED) ||\
     (defined ICU_IRQ_CH_12_ISR_USED) || (defined ICU_IRQ_CH_13_ISR_USED) ||\
     (defined ICU_IRQ_CH_14_ISR_USED) || (defined ICU_IRQ_CH_15_ISR_USED))

/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL channels : 8 to 15
* @details   Process the interrupt of SIUL channels 8 to 15
*
* @isr
*
* *
* @note  This will be defined only if any of SIUL channels 8 to 15 is configured
* @violates @ref Icu_SIUL2_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(SIUL2_EXT_IRQ_8_15_ISR)
{
    Icu_Siul2_ProcessInterrupt(ICU_SIUL2_IRQ_8);
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}
#endif  /* IRQ 8 - 15 */


#if ((defined ICU_IRQ_CH_16_ISR_USED) || (defined ICU_IRQ_CH_17_ISR_USED) || \
     (defined ICU_IRQ_CH_18_ISR_USED) || (defined ICU_IRQ_CH_19_ISR_USED) || \
     (defined ICU_IRQ_CH_20_ISR_USED) || (defined ICU_IRQ_CH_21_ISR_USED) || \
     (defined ICU_IRQ_CH_22_ISR_USED) || (defined ICU_IRQ_CH_23_ISR_USED))

/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL channels : 16 to 23
* @details   Process the interrupt of SIUL channels 16 to 23
*
* @isr
*
* *
* @note   This will be defined only if any of SIUL channels 16 to 23 is configured
* @violates @ref Icu_SIUL2_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(SIUL2_EXT_IRQ_16_23_ISR)
{
    Icu_Siul2_ProcessInterrupt(ICU_SIUL2_IRQ_16);
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}
#endif


#if ((defined ICU_IRQ_CH_24_ISR_USED) || (defined ICU_IRQ_CH_25_ISR_USED) || \
     (defined ICU_IRQ_CH_26_ISR_USED) || (defined ICU_IRQ_CH_27_ISR_USED) || \
     (defined ICU_IRQ_CH_28_ISR_USED) || (defined ICU_IRQ_CH_29_ISR_USED) || \
     (defined ICU_IRQ_CH_30_ISR_USED) || (defined ICU_IRQ_CH_31_ISR_USED))
/*================================================================================================*/
/**
* @brief     Interrupt handler for SIUL channels : 24 to 31
* @details   Process the interrupt of SIUL channels 24 to 31
*
* @isr
*
* *
* @note   This will be defined only if any of SIUL channels 16 to 23 is configured
* @violates @ref Icu_SIUL2_Irq_c_4 Violates MISRA 2004 Required Rule 8.10 could be made static
*/
/*================================================================================================*/
ISR(SIUL2_EXT_IRQ_24_31_ISR)
{
    Icu_Siul2_ProcessInterrupt(ICU_SIUL2_IRQ_24);
    /** @violates @ref Icu_SIUL2_Irq_c_3 Violates MISRA 2004 Rule 11.1, Cast from unsigned long to pointer.*/
    /** @violates @ref Icu_SIUL2_Irq_c_5 Violates MISRA 2004 Rule 11.3, Cast from pointer type and integral type.*/
    EXIT_INTERRUPT();
}

#endif

#endif /* ICU_IRQ_SINGLE_INTERRUPT */

#define ICU_STOP_SEC_CODE
/**
* @violates @ref Icu_SIUL2_Irq_c_1 MISRA 2004 Advisory Rule 19.1, only preprocessor statements
*               and comments before "#include"
*
* @violates @ref Icu_SIUL2_Irq_c_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the
*               contents of a header file being included twice
*/
#include "Icu_MemMap.h"


#ifdef __cplusplus
}
#endif
/** @} */
