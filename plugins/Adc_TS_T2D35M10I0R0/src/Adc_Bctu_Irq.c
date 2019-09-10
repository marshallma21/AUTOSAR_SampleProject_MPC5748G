/**
*   @file    Adc_Bctu_Irq.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - Interrupt Low Level Driver source file.
*   @details BCTU Interrupt Low Level Driver source file.
*
*   @addtogroup ADC
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : ADCDIG
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
* @section Adc_Bctu_Irq_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Bctu_Irq_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* There are different kinds of execution code sections.
*
* @section Adc_Bctu_Irq_c_REF_3
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function. These objects are used in various parts of the code
*
* @section Adc_Bctu_Irq_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware ofsset of the controller. The address calculated as an
* unsigned int is passed to a amcro for initializing the pointer with that address.
*
* @section Adc_Bctu_Irq_c_REF_5
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*
* @section Adc_Bctu_Irq_c_REF_6
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation is to be used by IPV layer.
*
* @section Adc_Bctu_Irq_c_REF_7
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and 
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section Adc_Bctu_Irq_c_REF_8
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared in one and only one file
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers shall not more than 31 characters
* Violation is needed because of Autosar restrictions for naming File version check macros.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcal.h"
#include "Adc_Ipw.h"
#define USER_MODE_REG_PROT_ENABLED                (ADC_USER_MODE_REG_PROT_ENABLED)
#include "SilRegMacros.h"
#include "Adc_Bctu.h"
#include "Adc_Reg_eSys_Bctu.h"

#ifdef ADC_BCTU_DMA_SUPPORTED
#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
  #include "CDD_Mcl.h"
#endif
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
    #include "Adc_Adcdig.h"
#endif /* ADC_HW_TRIGGER_API == STD_ON */

#if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_Bctu_Irq.c
*/
#define BCTU_IRQ_AR_VENDOR_ID_C                 43
#define BCTU_IRQ_AR_RELEASE_MAJOR_VERSION_C     4
#define BCTU_IRQ_AR_RELEASE_MINOR_VERSION_C     2
#define BCTU_IRQ_AR_RELEASE_REVISION_VERSION_C  2
#define BCTU_IRQ_SW_MAJOR_VERSION_C             1
#define BCTU_IRQ_SW_MINOR_VERSION_C             0
#define BCTU_IRQ_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if source file and BCTU header file are from the same vendor */
#if (BCTU_IRQ_AR_VENDOR_ID_C != BCTU_VENDOR_ID)
    #error "Adc_Bctu_Irq.c and Adc_Bctu.h have different vendor ids"
#endif

/* Check if source file and BCTU header file are of the same Autosar version */
#if ((BCTU_IRQ_AR_RELEASE_MAJOR_VERSION_C != BCTU_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IRQ_AR_RELEASE_MINOR_VERSION_C != BCTU_AR_RELEASE_MINOR_VERSION) || \
     (BCTU_IRQ_AR_RELEASE_REVISION_VERSION_C != BCTU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Bctu_Irq.c and Adc_Bctu.h are different"
#endif

/* Check if source file and BCTU header file are of the same Software version */
#if ((BCTU_IRQ_SW_MAJOR_VERSION_C != BCTU_SW_MAJOR_VERSION) || \
     (BCTU_IRQ_SW_MINOR_VERSION_C != BCTU_SW_MINOR_VERSION) || \
     (BCTU_IRQ_SW_PATCH_VERSION_C != BCTU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_Bctu_Irq.c and Adc_Bctu.h are different"
#endif

/* Check if source file and ADC header file are of the same vendor */
#if (BCTU_IRQ_AR_VENDOR_ID_C != ADC_VENDOR_ID_IPW_H)
#error "Adc_Bctu_Irq.c and Adc_Ipw.h have different vendor ids"
#endif

/* Check if source file and ADC header file are of the same Autosar version */
#if ((BCTU_IRQ_AR_RELEASE_MAJOR_VERSION_C != ADC_AR_RELEASE_MAJOR_VERSION_IPW_H) || \
     (BCTU_IRQ_AR_RELEASE_MINOR_VERSION_C != ADC_AR_RELEASE_MINOR_VERSION_IPW_H) || \
     (BCTU_IRQ_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION_IPW_H) \
    )
#error "AutoSar Version Numbers of Adc_Bctu_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if source file and ADC header file are of the same Software version */
#if ((BCTU_IRQ_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION_IPW_H) || \
     (BCTU_IRQ_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION_IPW_H) || \
     (BCTU_IRQ_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION_IPW_H) \
    )
#error "Software Version Numbers of Adc_Bctu_Irq.c and Adc_Ipw.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Bctu.h are from the same vendor */
#if (BCTU_IRQ_AR_VENDOR_ID_C != BCTU_REG_VENDOR_ID)
    #error "Adc_Bctu_Irq.c and Adc_Reg_eSys_Bctu.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Bctu.h are of the same Autosar version */
#if ((BCTU_IRQ_AR_RELEASE_MAJOR_VERSION_C != BCTU_REG_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_IRQ_AR_RELEASE_MINOR_VERSION_C != BCTU_REG_AR_RELEASE_MINOR_VERSION) || \
     (BCTU_IRQ_AR_RELEASE_REVISION_VERSION_C != BCTU_REG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Bctu_Irq.c and Adc_Reg_eSys_Bctu.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Bctu.h are of the same Software version */
#if ((BCTU_IRQ_SW_MAJOR_VERSION_C != BCTU_REG_SW_MAJOR_VERSION) || \
     (BCTU_IRQ_SW_MINOR_VERSION_C != BCTU_REG_SW_MINOR_VERSION) || \
     (BCTU_IRQ_SW_PATCH_VERSION_C != BCTU_REG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_Bctu_Irq.c and Adc_Reg_eSys_Bctu.h are different"
#endif

#if (ADC_HW_TRIGGER_API == STD_ON)
 /* Check if source file and Adc_ADCDig header file are of the same vendor */
 #if (BCTU_IRQ_AR_VENDOR_ID_C != ADC_VENDOR_ID_ADCDIG)
     #error "Adc_Bctu_Irq.c and Adc_Adcdig.h have different vendor ids"
 #endif
 
 /* Check if source file and Adc_ADCDig header file are of the same Autosar version */
     #if ((BCTU_IRQ_AR_RELEASE_MAJOR_VERSION_C != ADC_AR_RELEASE_MAJOR_VERSION_ADCDIG) || \
          (BCTU_IRQ_AR_RELEASE_MINOR_VERSION_C != ADC_AR_RELEASE_MINOR_VERSION_ADCDIG) || \
          (BCTU_IRQ_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION_ADCDIG) \
         )
     #error "AutoSar Version Numbers of Adc_Bctu_Irq.h and Adc_Adcdig.h are different"
 #endif
 
 /* Check if source file and ADC Adc_ADCDig header file are of the same software version */
 #if ((BCTU_IRQ_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION_ADCDIG) || \
      (BCTU_IRQ_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION_ADCDIG) || \
      (BCTU_IRQ_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION_ADCDIG) \
     )
 #error "Software Version Numbers of Adc_Bctu_Irq.h and Adc_Adcdig.h are different"
 #endif
#endif


#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if source file and Mcal header file are of the same AutoSar version */
 #if ((BCTU_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCAL_AR_RELEASE_MAJOR_VERSION) || \
      (BCTU_IRQ_AR_RELEASE_MINOR_VERSION_C != MCAL_AR_RELEASE_MINOR_VERSION) \
     )
  #error "AutoSar Version Numbers of Adc_Bctu_Irq.c and Mcal.h are different"
 #endif 

 /* Check if source file and SilREgMacros header file are of the same AutoSar version */
 #if ((BCTU_IRQ_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
      (BCTU_IRQ_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Bctu_Irq.c and SilRegMacros.h are different"
 #endif  

 #ifdef ADC_BCTU_DMA_SUPPORTED
  #if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
  
   /* Check if source file and MCL header file are of the same Autosar version */
   #if ((BCTU_IRQ_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
        (BCTU_IRQ_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION) \
       )
       #error "AutoSar Version Numbers of Adc_Bctu_Irq.c and CDD_Mcl.h are different"
   #endif
  
  #endif /* (ADC_BCTU_DMA_SUPPORTED == STD_ON) */
 #endif /* ADC_BCTU_DMA_SUPPORTED */
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ADC_START_SEC_VAR_INIT_8
/** @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"

/** @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage. */
VAR(uint8, ADC_VAR) Adc_Bctu_au8ResultIndex[ADC_MAX_HW_UNITS] = {0U}; 
/** @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage. */
VAR(uint8, ADC_VAR) Adc_Bctu_u8TotalIndex = 0U;

#define ADC_STOP_SEC_VAR_INIT_8
/**
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"
/**
* @brief          Used to point the BCTU configuration structure.
*/
/** @violates @ref Adc_Bctu_Irq_c_REF_3 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern P2CONST(Adc_Bctu_ConfigType, ADC_VAR, ADC_APPL_CONST) Adc_Bctu_pCfgPtr;

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"

#ifdef ADC_BCTU_DMA_SUPPORTED
#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)

#define ADC_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
/**
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"
/**
* @brief          Internal buffer used by DMA to transfer blocks with gaps
*/
extern VAR(uint32, ADC_VAR) Adc_Bctu_au32DmaInternalBuffer[ADC_MAX_HW_UNITS][ADC_MAXIMUM_HW_CHANNELS];

#define ADC_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
/**
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"

#endif /* ADC_BCTU_DMA_SUPPORTED == STD_ON */
#endif /* ADC_BCTU_DMA_SUPPORTED */

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
#define ADC_START_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"

/** @violates @ref Adc_Bctu_Irq_c_REF_8 External object declared more than once*/
extern VAR(Adc_UnitStatusType , ADC_VAR) Adc_UnitStatus[ADC_MAX_HW_UNITS];

#define ADC_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
/**
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define ADC_START_SEC_CODE
/**
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
*/
#include "Adc_MemMap.h"
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcEndConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcEndCtuConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32DataReg
);

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcEndMultiCtuConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32DataReg
);
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */

#ifdef ADC_BCTU_COMMON_ISR_HANDLER
 #if (ADC_BCTU_COMMON_ISR_HANDLER == STD_ON)
  ISR(Bctu0_AdcEndConvInterrupt);
 #endif /* (ADC_BCTU_COMMON_ISR_HANDLER == STD_ON) */
#else
 #if (ADC_MAX_HW_UNITS >= 1U)
  ISR(Bctu0_Adc0EndConvInterrupt);
 #endif /* (ADC_MAX_HW_UNITS >= 1U) */

 #if (ADC_MAX_HW_UNITS >= 2U)
  ISR(Bctu0_Adc1EndConvInterrupt);
 #endif /* (ADC_MAX_HW_UNITS >= 2U) */

 #if (ADC_MAX_HW_UNITS >= 3U)
  ISR(Bctu0_Adc2EndConvInterrupt);
 #endif /* (ADC_MAX_HW_UNITS >= 3U) */

 #if (ADC_MAX_HW_UNITS >= 4U)
  ISR(Bctu0_Adc3EndConvInterrupt);
 #endif /* (ADC_MAX_HW_UNITS >= 4U) */
#endif /* ADC_BCTU_COMMON_ISR_HANDLER */

#if (ADC_MAX_HW_UNITS >= 1U)
/** @violates @ref Adc_Bctu_Irq_c_REF_8 declaration of an external object or function */
FUNC(void, ADC_CODE) Bctu0_Adc0DmaTransferComplete(void);
#endif /* (ADC_MAX_HW_UNITS >= 1U) */

#if (ADC_MAX_HW_UNITS >= 2U)
/** @violates @ref Adc_Bctu_Irq_c_REF_8 declaration of an external object or function */
FUNC(void, ADC_CODE) Bctu0_Adc1DmaTransferComplete(void);
#endif /* (ADC_MAX_HW_UNITS >= 2U) */

#if (ADC_MAX_HW_UNITS >= 3U)
/** @violates @ref Adc_Bctu_Irq_c_REF_8 declaration of an external object or function */
FUNC(void, ADC_CODE) Bctu0_Adc2DmaTransferComplete(void);
#endif /* (ADC_MAX_HW_UNITS >= 3U) */

#if (ADC_MAX_HW_UNITS >= 4U)
/** @violates @ref Adc_Bctu_Irq_c_REF_8 declaration of an external object or function */
FUNC(void, ADC_CODE) Bctu0_Adc3DmaTransferComplete(void);
#endif /* (ADC_MAX_HW_UNITS >= 4U) */

#ifdef ADC_BCTU_DMA_SUPPORTED
#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcDmaEndConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);
#endif /* (ADC_BCTU_DMA_SUPPORTED == STD_ON) */
#endif /* ADC_BCTU_DMA_SUPPORTED */

#if (ADC_HW_TRIGGER_API == STD_ON)
#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) \
     )
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcEndListConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
);

ISR(Bctu0_AdcEndListConvInterrupt);
#endif /* (defined(ADC_UNIT_0_ISR_USED) */
#endif /* ADC_HW_TRIGGER_API == STD_ON */

/*==================================================================================================
                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
extern FUNC(void, ADC_CODE) Adc_Adcdig_EndMultipleCtuConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32TrgSrc
/** @violates @ref Adc_Bctu_Irq_c_REF_8 declaration of an external object or function */
);
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */

#if (ADC_HW_TRIGGER_API == STD_ON)
extern FUNC(void, ADC_CODE) Adc_Adcdig_EndHardwareConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(boolean, AUTOMATIC) bInjectedFlag
/** @violates @ref Adc_Bctu_Irq_c_REF_8 declaration of an external object or function */
);
#endif /* ADC_HW_TRIGGER_API == STD_ON */
/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief          This function handles the new data interrupt for BCTU control mode.
* @details        When the new data available, this function
*                 take cares about handling of driver
*
* @param[in]      Adc_HwUnitType
*
* @return         void
*
* @api
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcEndCtuConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32DataReg
)
{
    VAR(uint8, AUTOMATIC) u8Index;
    VAR(uint32, AUTOMATIC) u32TrgSrc;
    P2CONST(Adc_Bctu_TriggerConfigType, AUTOMATIC, ADC_APPL_CONST) pTriggerPtr = NULL_PTR;

    /* Clear interrupt flag */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_MSR_ADDR32, (BCTU_NDATA_FLAG_U32(Unit) | BCTU_DATAOVR_FLAG_U32(Unit)));
    
    if(NULL_PTR != Adc_Bctu_pCfgPtr)
    {
        /* Get trigger source number of this interrupt */
        u32TrgSrc = (u32DataReg >> BCTU_TRGSRC_SHIFT_MASK_U8) & 0xFFUL;
     
        for(u8Index = 0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
        {
            /** @violates @ref Adc_Bctu_Irq_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic */
            pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);
     
            if(u32TrgSrc == (uint32)pTriggerPtr->u8BctuTrCfgId)
            {
                break;
            }
        }
     
        /** @violates @ref Adc_Bctu_Irq_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic */
        pTriggerPtr->pResultsBufferPtr[Unit][Adc_Bctu_au8ResultIndex[Unit]] = (uint16)(u32DataReg & 0x0FFFUL);
        /* Increase results index */
        Adc_Bctu_au8ResultIndex[Unit]++;
        Adc_Bctu_u8TotalIndex++;
        if(Adc_Bctu_au8ResultIndex[Unit] >= (pTriggerPtr->u8NumListElement/pTriggerPtr->u8NumHwCfg))
        {
            /* Reset result index for new conversion */
            Adc_Bctu_au8ResultIndex[Unit] = 0U;
        }
        if (Adc_Bctu_u8TotalIndex >= pTriggerPtr->u8NumListElement)
        {
            Adc_Bctu_u8TotalIndex = 0U;
            if(NULL_PTR != pTriggerPtr->BctuNotification)
            {
                /* Call the user notification function */
                pTriggerPtr->BctuNotification();
            }       
        }
        /* Reset input trigger */
        /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
        /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(BCTU_TRGCFG_ADDR32(u32TrgSrc), BCTU_TRIG_FLAG_CLEAR_U32);
    }
}

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
/**
* @brief          This function handles the multiple Ctu trigger conversion.
* @details        When the new data available, this function
*                 take cares about handling of driver
*
* @param[in]      Adc_HwUnitType
*
* @return         void
*
* @api
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcEndMultiCtuConv
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit,
    VAR(uint32, AUTOMATIC) u32DataReg
)
{
    VAR(uint32, AUTOMATIC) u32TrgSrc;

    /* Get trigger source number of this interrupt */
    u32TrgSrc = (uint32)(u32DataReg >> BCTU_TRGSRC_SHIFT_MASK_U8);

    Adc_Adcdig_EndMultipleCtuConv(Unit, u32TrgSrc);

    /* Clear trigger timer flag */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_TRGCFG_ADDR32(u32TrgSrc), BCTU_TRIG_FLAG_CLEAR_U32);
    /* Clear the CTU interrupt flag */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_MSR_ADDR32,(BCTU_NDATA_FLAG_U32((uint32)Unit)|BCTU_DATAOVR_FLAG_U32((uint32)Unit)));
}
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */

/**
* @brief          This function handles the new data interrupt.
* @details        When the new data available, this function
*                 take cares about handling of driver
*
* @param[in]      Adc_HwUnitType
*
* @return         void
*
* @api
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcEndConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint32, AUTOMATIC) u32InterruptActivated = (uint32)(1UL << Unit);
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    volatile VAR(uint32, AUTOMATIC) u32DataReg = REG_READ32(BCTU_ADCDR_ADDR32((uint32)Unit));

    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    if(u32InterruptActivated == (u32InterruptActivated & REG_READ32(BCTU_MCR_ADDR32)))
    {
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
        if((Adc_MhtGroupType)ADC_MHT_GROUP_TYPE == Adc_UnitStatus[Unit].HwQueueGroupType)
        {
            Bctu0_AdcEndMultiCtuConv(Unit, u32DataReg);
        }
        else
#endif /* (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON) */
        {
            Bctu0_AdcEndCtuConversion(Unit, u32DataReg);
        }
    }
}

#ifdef ADC_BCTU_COMMON_ISR_HANDLER
 #if (ADC_BCTU_COMMON_ISR_HANDLER == STD_ON)
/**
* @brief          This function handles the BCTU_0_ADC_EndConvInterrupt.
* @details        The function handles the BCTU_0_ADC_EndConvInterrupt.
*
* @isr
*
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
ISR(Bctu0_AdcEndConvInterrupt)
{
    VAR(uint32, AUTOMATIC) u32IsrStatus;

    /* Read Module Status Register value */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    u32IsrStatus = (uint32)REG_READ32(BCTU_MSR_ADDR32);

    #if (ADC_MAX_HW_UNITS >= 1U)
    if(ADC_UNIT_0_MASK_U32 == (u32IsrStatus & ADC_UNIT_0_MASK_U32))
    {
        Bctu0_AdcEndConversion((Adc_HwUnitType)ADC_UNIT_0);
    }
    #endif /* (ADC_MAX_HW_UNITS >= 1U) */

    #if (ADC_MAX_HW_UNITS >= 2U)
    else if(ADC_UNIT_1_MASK_U32 == (u32IsrStatus & ADC_UNIT_1_MASK_U32))
    {
        Bctu0_AdcEndConversion((Adc_HwUnitType)ADC_UNIT_1);
    }
    #endif /* (ADC_MAX_HW_UNITS >= 2U) */

    #if (ADC_MAX_HW_UNITS >= 3U)
    else if(ADC_UNIT_2_MASK_U32 == (u32IsrStatus & ADC_UNIT_2_MASK_U32))
    {
        Bctu0_AdcEndConversion((Adc_HwUnitType)ADC_UNIT_2);
    }
    #endif /* (ADC_MAX_HW_UNITS >= 3U) */

    #if (ADC_MAX_HW_UNITS >= 4U)
    else if(ADC_UNIT_3_MASK_U32 == (u32IsrStatus & ADC_UNIT_3_MASK_U32))
    {
        Bctu0_AdcEndConversion((Adc_HwUnitType)ADC_UNIT_3);
    }
    #endif /* (ADC_MAX_HW_UNITS >= 4U) */
    else
    {
        /* Nothing for Misra */
    }
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    EXIT_INTERRUPT();
}
 #endif /* (ADC_BCTU_COMMON_ISR_HANDLER == STD_ON) */
#else
 #if (ADC_MAX_HW_UNITS >= 1U)
/**
* @brief          This function handles the BCTU_0_ADC0_EndConvInterrupt.
* @details        The function handles the BCTU_0_ADC0_EndConvInterrupt.
*
* @isr
*
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
ISR(Bctu0_Adc0EndConvInterrupt)
{
    Bctu0_AdcEndConversion((Adc_HwUnitType)ADC_UNIT_0);
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    EXIT_INTERRUPT();
}
 #endif /* (ADC_MAX_HW_UNITS >= 1U) */

 #if (ADC_MAX_HW_UNITS >= 2U)
/**
* @brief          This function handles the BCTU_0_ADC1_EndConvInterrupt.
* @details        The function handles the BCTU_0_ADC1_EndConvInterrupt.
*
* @isr
*
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
ISR(Bctu0_Adc1EndConvInterrupt)
{
    Bctu0_AdcEndConversion((Adc_HwUnitType)ADC_UNIT_1);
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    EXIT_INTERRUPT();
}
 #endif /* (ADC_MAX_HW_UNITS >= 2U) */

 #if (ADC_MAX_HW_UNITS >= 3U)
/**
* @brief          This function handles the BCTU_0_ADC2_EndConvInterrupt.
* @details        The function handles the BCTU_0_ADC2_EndConvInterrupt.
*
* @isr
*
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
ISR(Bctu0_Adc2EndConvInterrupt)
{
    Bctu0_AdcEndConversion((Adc_HwUnitType)ADC_UNIT_2);
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    EXIT_INTERRUPT();
}
 #endif /* (ADC_MAX_HW_UNITS >= 3U) */

 #if (ADC_MAX_HW_UNITS >= 4U)
/**
* @brief          This function handles the BCTU_0_ADC3_EndConvInterrupt.
* @details        The function handles the BCTU_0_ADC3_EndConvInterrupt.
*
* @isr
*
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
ISR(Bctu0_Adc3EndConvInterrupt)
{
    Bctu0_AdcEndConversion((Adc_HwUnitType)ADC_UNIT_3);
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    EXIT_INTERRUPT();
}
 #endif /* (ADC_MAX_HW_UNITS >= 4U) */
#endif /* ADC_BCTU_COMMON_ISR_HANDLER */

#ifdef ADC_BCTU_DMA_SUPPORTED
#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
/**
* @brief          This function handles the DMA channel ending.
* @details        When transfering data of DMA channel completed, this function
*                 take cares about handling of driver
*
* @param[in]      Adc_HwUnitType
*
* @return         void
*
* @api
*
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcDmaEndConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    VAR(uint8, AUTOMATIC) u8Index;
    VAR(uint32, AUTOMATIC) u32TrgSrc;
    VAR(Adc_HwUnitType, AUTOMATIC) HwUnit;
    VAR(Adc_ChannelType, AUTOMATIC) MaxChPerUnit;
    P2CONST(Adc_Bctu_TriggerConfigType, AUTOMATIC, ADC_APPL_CONST) pTriggerPtr = NULL_PTR;
    static VAR(uint8, ADC_VAR) u8DmaResultIndex = 0U;
    static VAR(boolean, ADC_VAR) bUnitActive[ADC_MAX_HW_UNITS];
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) pTcdAddress;
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel;

    if(NULL_PTR != Adc_Bctu_pCfgPtr)
    {
        /* Get trigger source number of this interrupt */
        u32TrgSrc = (Adc_Bctu_au32DmaInternalBuffer[Unit][0] >> BCTU_TRGSRC_SHIFT_MASK_U8) & 0xFFUL;

        for(u8Index = 0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
        {
            /** @violates @ref Adc_Bctu_Irq_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic */
            pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);

            if(u32TrgSrc == (uint32)pTriggerPtr->u8BctuTrCfgId)
            {
                break;
            }
        }

        bUnitActive[Unit] = (boolean)TRUE;
        /* Increase results index */
        u8DmaResultIndex++;

        if(u8DmaResultIndex >= pTriggerPtr->u8NumListElement)
        {
            MaxChPerUnit = pTriggerPtr->u8NumListElement/pTriggerPtr->u8NumHwCfg;

            for(HwUnit = 0U; HwUnit < ADC_MAX_HW_UNITS; HwUnit++)
            {
                if((boolean)TRUE == bUnitActive[HwUnit])
                {
                    for(u8Index = 0U; u8Index < MaxChPerUnit; u8Index++)
                    {
                        /** @violates @ref Adc_Bctu_Irq_c_REF_5 Array indexing shall be the only allowed form of pointer arithmetic */
                        pTriggerPtr->pResultsBufferPtr[HwUnit][u8Index] = \
                        (uint16)(Adc_Bctu_au32DmaInternalBuffer[HwUnit][u8Index] & 0x0FFFUL);
                    }
                    bUnitActive[HwUnit] = (boolean)FALSE;
                    /* Get Dma channel for this unit */
                    DmaChannel = Adc_Bctu_pCfgPtr->au8DmaChanel[HwUnit];
                    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
                    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
                    pTcdAddress = (Mcl_DmaTcdType *)Mcl_DmaGetChannelTcdAddress((Mcl_ChannelType)DmaChannel);
                    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
                    /** Compiler_Warning: It is intended for the address of the element to be passed
                    to the function as an unsigned integer. */
                    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
                    Mcl_DmaTcdSetDaddr(pTcdAddress, (uint32)(&Adc_Bctu_au32DmaInternalBuffer[HwUnit][0]));
                }
            }
            /* Reset result index for new conversion */
            u8DmaResultIndex = 0U;
            if(NULL_PTR != pTriggerPtr->BctuNotification)
            {
                /* Call the user notification function */
                pTriggerPtr->BctuNotification();
            }
        }
        /* Clear the trigger timer flag */
        /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
        /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(BCTU_TRGCFG_ADDR32(u32TrgSrc), BCTU_TRIG_FLAG_CLEAR_U32);
        /* Start DMA channel */
        DmaChannel = Adc_Bctu_pCfgPtr->au8DmaChanel[Unit];
        Mcl_DmaEnableHwRequest((Mcl_ChannelType)DmaChannel);
    }
    /* Clear interrupt flag */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_MSR_ADDR32, (BCTU_NDATA_FLAG_U32(Unit) | BCTU_DATAOVR_FLAG_U32(Unit)));
}
#endif /* (ADC_BCTU_DMA_SUPPORTED == STD_ON) */
#endif /* ADC_BCTU_DMA_SUPPORTED */

#if (ADC_MAX_HW_UNITS >= 1U)
/**
* @brief          This function handles internal BCTU updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the BCTU_ADC Hardware unit 0.
*
* @return         void
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
FUNC(void, ADC_CODE) Bctu0_Adc0DmaTransferComplete()
{
#ifdef ADC_BCTU_DMA_SUPPORTED
    #if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
    Bctu0_AdcDmaEndConversion((Adc_HwUnitType)ADC_UNIT_0);
    #endif
#endif
}
#endif /* (ADC_MAX_HW_UNITS >= 1U) */

#if (ADC_MAX_HW_UNITS >= 2U)
/**
* @brief          This function handles internal BCTU updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the BCTU_ADC Hardware unit 1.
*
* @return         void
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
FUNC(void, ADC_CODE) Bctu0_Adc1DmaTransferComplete()
{
#ifdef ADC_BCTU_DMA_SUPPORTED
    #if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
    Bctu0_AdcDmaEndConversion((Adc_HwUnitType)ADC_UNIT_1);
    #endif
#endif
}
#endif /* (ADC_MAX_HW_UNITS >= 2U) */

#if (ADC_MAX_HW_UNITS >= 3U)
/**
* @brief          This function handles internal BCTU updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the BCTU_ADC Hardware unit 2.
*
* @return         void
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
FUNC(void, ADC_CODE) Bctu0_Adc2DmaTransferComplete()
{
#ifdef ADC_BCTU_DMA_SUPPORTED
    #if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
    Bctu0_AdcDmaEndConversion((Adc_HwUnitType)ADC_UNIT_2);
    #endif
#endif
}
#endif /* (ADC_MAX_HW_UNITS >= 3U) */

#if (ADC_MAX_HW_UNITS >= 4U)
/**
* @brief          This function handles internal BCTU updates after a DMA transfer is completed.
* @details        The function is a notification called by MCL module after the transfer
*                 is completed for the BCTU_ADC Hardware unit 3.
*
* @return         void
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
FUNC(void, ADC_CODE) Bctu0_Adc3DmaTransferComplete()
{
#ifdef ADC_BCTU_DMA_SUPPORTED
    #if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
    Bctu0_AdcDmaEndConversion((Adc_HwUnitType)ADC_UNIT_3);
    #endif
#endif
}
#endif /* (ADC_MAX_HW_UNITS >= 4U) */

#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON)*/

#if (ADC_HW_TRIGGER_API == STD_ON)
#if ((defined(ADC_UNIT_0_ISR_USED)) || (defined(ADC_UNIT_1_ISR_USED)) || \
     (defined(ADC_UNIT_2_ISR_USED)) || (defined(ADC_UNIT_3_ISR_USED)) \
     )
LOCAL_INLINE FUNC(void, ADC_CODE) Bctu0_AdcEndListConversion
(
    VAR(Adc_HwUnitType, AUTOMATIC) Unit
)
{
    volatile VAR(uint32, AUTOMATIC) u32TrgSrc;

    /* Get trigger source number of this interrupt */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    u32TrgSrc = REG_READ32(BCTU_ADCDR_ADDR32((uint32)Unit)) >> BCTU_TRGSRC_SHIFT_MASK_U8;

    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    if(BCTU_LIST_INT_EN_U32 == (BCTU_LIST_INT_EN_U32 & REG_READ32(BCTU_MCR_ADDR32)))
    {
        /* Call the processing function from Adcdig */
        Adc_Adcdig_EndHardwareConv(Unit, (boolean)TRUE);
    }
    /* Clear the trigger timer flag */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_TRGCFG_ADDR32(u32TrgSrc), BCTU_TRIG_FLAG_CLEAR_U32);
    /* Clear interrupt flag */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_MSR_ADDR32, BCTU_LIST_FLAG_U32(Unit));
}
/**
* @brief          This function handles the List interrupt.
* @details        The function handles the interrupt of last channel in the list.
*
* @isr
*
* @violates @ref Adc_Bctu_Irq_c_REF_6 internal linkage or external linkage.
*/
ISR(Bctu0_AdcEndListConvInterrupt)
{
    VAR(uint32, AUTOMATIC) u32IsrStatus;

    /* Read Module Status Register value */
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    u32IsrStatus = (uint32)REG_READ32(BCTU_MSR_ADDR32);

    #if (ADC_MAX_HW_UNITS >= 1U)
    if(BCTU_LIST_FLAG_ADC_0_U32 == (u32IsrStatus & BCTU_LIST_FLAG_ADC_0_U32))
    {
        Bctu0_AdcEndListConversion((Adc_HwUnitType)ADC_UNIT_0);
    }
    #endif /* (ADC_MAX_HW_UNITS >= 1U) */

    #if (ADC_MAX_HW_UNITS >= 2U)
    else if(BCTU_LIST_FLAG_ADC_1_U32 == (u32IsrStatus & BCTU_LIST_FLAG_ADC_1_U32))
    {
        Bctu0_AdcEndListConversion((Adc_HwUnitType)ADC_UNIT_1);
    }
    #endif /* (ADC_MAX_HW_UNITS >= 2U) */

    #if (ADC_MAX_HW_UNITS >= 3U)
    else if(BCTU_LIST_FLAG_ADC_2_U32 == (u32IsrStatus & BCTU_LIST_FLAG_ADC_2_U32))
    {
        Bctu0_AdcEndListConversion((Adc_HwUnitType)ADC_UNIT_2);
    }
    #endif /* (ADC_MAX_HW_UNITS >= 3U) */

    #if (ADC_MAX_HW_UNITS >= 4U)
    else if(BCTU_LIST_FLAG_ADC_3_U32 == (u32IsrStatus & BCTU_LIST_FLAG_ADC_3_U32))
    {
        Bctu0_AdcEndListConversion((Adc_HwUnitType)ADC_UNIT_3);
    }
    #endif /* (ADC_MAX_HW_UNITS >= 4U) */
    else
    {
        /* Nothing for Misra */
    }
    /** @violates @ref Adc_Bctu_Irq_c_REF_4 cast from unsigned int to pointer. */
    /** @violates @ref Adc_Bctu_Irq_c_REF_7 A cast should not be performed between a pointer type and an integral type. */
    EXIT_INTERRUPT();
}
#endif /* defined(ADC_UNIT_0_ISR_USED) */
#endif /* ADC_HW_TRIGGER_API == STD_ON */
#define ADC_STOP_SEC_CODE
/**
* @violates @ref Adc_Bctu_Irq_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_Irq_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

#ifdef __cplusplus
}
#endif

/** @} */
