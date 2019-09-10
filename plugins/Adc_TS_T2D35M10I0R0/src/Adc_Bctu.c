/**
*   @file    Adc_Bctu.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Adc - low level driver source file.
*   @details This is the low level driver source file,mainly implemented for the BCTU hardware IP.
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
* @section Adc_Bctu_c_REF_1
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments before "#include"
* This violation is not fixed since the inclusion of MemMap.h is as per Autosar requirement.
*
* @section Adc_Bctu_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* There are different kinds of execution code sections.
*
* @section Adc_Bctu_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, cast from unsigned int to pointer. This macro compute the
* address of any register by using the hardware offset of the controller. The address calculated as
* an unsigned int is passed to a macro for initializing the pointer with that address.
*
* @section Adc_Bctu_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, Array indexing shall be the only allowed form of pointer
* arithmetic but used due to the code complexity.
*
* @section Adc_Bctu_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between a pointer type and 
* an integral type.
* The cast is used to access memory mapped registers.
*
* @section Adc_Bctu_c_REF_6
* Violates MISRA 2004 Required Rule 14.7, Return statement before end of function.
* The return statement are used to simplify the code structure and easier readability.
*
* @section Adc_Bctu_c_REF_7
* Violates MISRA 2004 Required Rule 8.10, all declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is required.
* This violation is to be used by LLD layer.
*
* @section Adc_Bctu_c_REF_8
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function. These objects are used in various parts of the code
*
* @section Adc_Bctu_c_REF_9
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure that
* 31 characters significance and case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have a file version check.
*
* @section Adc_Bctu_c_REF_11
* Violates MISRA 2004 Required Rule 1.2, No reliance shall be placed on undefined or unspecified behaviour.
* The local address passed as parameter is used in a safe way.
*
* @section Adc_Bctu_c_REF_12
* Violates MISRA 2004 Required Rule 8.8, An external object or function shall be declared
* in one and only one file.
* This violation cannot be removed due to the interaction with MCL module.
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
#include "Adc_Cfg.h"
#define USER_MODE_REG_PROT_ENABLED                (ADC_USER_MODE_REG_PROT_ENABLED)
#include "SilRegMacros.h"

#if ((STD_ON == ADC_ENABLE_CTU_CONTROL_MODE_API) || \
     (STD_ON == ADC_ENABLE_CTUTRIG_NONAUTO_API) || \
     (STD_ON == ADC_HW_TRIGGER_API) \
    )
#include "Adc_Bctu.h"
#include "Adc_Reg_eSys_Bctu.h"

#ifdef ADC_BCTU_DMA_SUPPORTED
#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
  #include "CDD_Mcl.h"
#endif
#endif

#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Adc_Bctu.c
*/
#define BCTU_VENDOR_ID_C                    43
#define BCTU_AR_RELEASE_MAJOR_VERSION_C     4
#define BCTU_AR_RELEASE_MINOR_VERSION_C     2
/** @violates @ref Adc_Bctu_c_REF_9 MISRA-C:2004 Rule 1.4: Identifier clash. */
#define BCTU_AR_RELEASE_REVISION_VERSION_C  2
#define BCTU_SW_MAJOR_VERSION_C             1
#define BCTU_SW_MINOR_VERSION_C             0
#define BCTU_SW_PATCH_VERSION_C             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if source file and ADC configuration header file are of the same vendor */
#if (BCTU_VENDOR_ID_C != ADC_VENDOR_ID_CFG)
#error "Adc_Bctu.c and Adc_Cfg.h have different vendor ids"
#endif

/* Check if source file and ADC configuration header file are of the same Autosar version */
#if ((BCTU_AR_RELEASE_MAJOR_VERSION_C != ADC_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (BCTU_AR_RELEASE_MINOR_VERSION_C != ADC_AR_RELEASE_MINOR_VERSION_CFG) || \
     (BCTU_AR_RELEASE_REVISION_VERSION_C != ADC_AR_RELEASE_REVISION_VERSION_CFG) \
    )
#error "AutoSar Version Numbers of Adc_Bctu.c and Adc_Cfg.h are different"
#endif

/* Check if source file and ADC configuration header file are of the same software version */
#if ((BCTU_SW_MAJOR_VERSION_C != ADC_SW_MAJOR_VERSION_CFG) || \
     (BCTU_SW_MINOR_VERSION_C != ADC_SW_MINOR_VERSION_CFG) || \
     (BCTU_SW_PATCH_VERSION_C != ADC_SW_PATCH_VERSION_CFG) \
    )
#error "Software Version Numbers of Adc_Bctu.c and Adc_Cfg.h are different"
#endif

/* Check if source file and BCTU header file are from the same vendor */
#if (BCTU_VENDOR_ID_C != BCTU_VENDOR_ID)
    #error "Adc_Bctu.c and Adc_Bctu.h have different vendor ids"
#endif

/* Check if source file and BCTU header file are of the same Autosar version */
#if ((BCTU_AR_RELEASE_MAJOR_VERSION_C != BCTU_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_AR_RELEASE_MINOR_VERSION_C != BCTU_AR_RELEASE_MINOR_VERSION) || \
     (BCTU_AR_RELEASE_REVISION_VERSION_C != BCTU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Bctu.c and Adc_Bctu.h are different"
#endif

/* Check if source file and BCTU header file are of the same Software version */
#if ((BCTU_SW_MAJOR_VERSION_C != BCTU_SW_MAJOR_VERSION) || \
     (BCTU_SW_MINOR_VERSION_C != BCTU_SW_MINOR_VERSION) || \
     (BCTU_SW_PATCH_VERSION_C != BCTU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_Bctu.c and Adc_Bctu.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Bctu.h are from the same vendor */
#if (BCTU_VENDOR_ID_C != BCTU_REG_VENDOR_ID)
    #error "Adc_Bctu.c and Adc_Reg_eSys_Bctu.h have different vendor ids"
#endif

/* Check if source file and Adc_Reg_eSys_Bctu.h are of the same Autosar version */
#if ((BCTU_AR_RELEASE_MAJOR_VERSION_C != BCTU_REG_AR_RELEASE_MAJOR_VERSION) || \
     (BCTU_AR_RELEASE_MINOR_VERSION_C != BCTU_REG_AR_RELEASE_MINOR_VERSION) || \
     (BCTU_AR_RELEASE_REVISION_VERSION_C != BCTU_REG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Adc_Bctu.c and Adc_Reg_eSys_Bctu.h are different"
#endif

/* Check if source file and Adc_Reg_eSys_Bctu.h are of the same Software version */
#if ((BCTU_SW_MAJOR_VERSION_C != BCTU_REG_SW_MAJOR_VERSION) || \
     (BCTU_SW_MINOR_VERSION_C != BCTU_REG_SW_MINOR_VERSION) || \
     (BCTU_SW_PATCH_VERSION_C != BCTU_REG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Adc_Bctu.c and Adc_Reg_eSys_Bctu.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
 #ifdef ADC_BCTU_DMA_SUPPORTED
  #if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
  /* Check if source file and MCL header file are of the same Autosar version */
   #if ((BCTU_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION) || \
        (BCTU_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION)  \
       )
       #error "AutoSar Version Numbers of Adc_Bctu.c CDD_Mcl.h are different"
   #endif

  #endif /* (ADC_BCTU_DMA_SUPPORTED == STD_ON) */
 #endif /* ADC_BCTU_DMA_SUPPORTED */
 #if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
 /* Check if source file and Dem header file are of the same version */
 #if ((BCTU_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
      (BCTU_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Bctu.c and Dem.h are different"
 #endif
 #endif /* ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF */
 /* Check if source file and SilREgMacros header file are of the same AutoSar version */
 #if ((BCTU_AR_RELEASE_MAJOR_VERSION_C != SILREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
      (BCTU_AR_RELEASE_MINOR_VERSION_C != SILREGMACROS_AR_RELEASE_MINOR_VERSION) \
     )
 #error "AutoSar Version Numbers of Adc_Adcdig_Irq.c and SilRegMacros.h are different"
 #endif  
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
#if ((ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/** @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h */
#include "Adc_MemMap.h"
/**
* @brief          Global BCTU configuration structure pointer.
*
*/
P2CONST(Adc_Bctu_ConfigType, ADC_VAR, ADC_APPL_CONST) Adc_Bctu_pCfgPtr = NULL_PTR;

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

#ifdef ADC_BCTU_DMA_SUPPORTED
#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)

#define ADC_START_SEC_VAR_NO_INIT_32_NO_CACHEABLE
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

/**
* @brief          Internal buffer used by DMA to transfer blocks with gaps
*
* @violates @ref Adc_Bctu_c_REF_7 Declaration and definition of objects or function
*/
VAR(uint32, ADC_VAR) Adc_Bctu_au32DmaInternalBuffer[ADC_MAX_HW_UNITS][ADC_MAXIMUM_HW_CHANNELS];

#define ADC_STOP_SEC_VAR_NO_INIT_32_NO_CACHEABLE
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

#endif /* ADC_BCTU_DMA_SUPPORTED == STD_ON */
#endif /* ADC_BCTU_DMA_SUPPORTED */
#endif /* (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) */

#if ((ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
#define ADC_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"
/**
* @brief          Used to point the configuration structure.
*
* @violates @ref Adc_Bctu_c_REF_12 Function decalration
*/
extern P2CONST(Adc_ConfigType , ADC_VAR, ADC_APPL_CONST) Adc_pCfgPtr;

#define ADC_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

#define ADC_START_SEC_VAR_INIT_16
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

/** @brief          List address value for list mode */
static VAR(uint16, AUTOMATIC) Adc_Bctu_u16ListAddressIndex = 0U;
static VAR(uint16, AUTOMATIC) Adc_Bctu_au16ListChannelAddress[ADC_MAX_HW_UNITS] = {0U};
#if (ADC_SETCHANNEL_API == STD_ON)
static VAR(uint16, AUTOMATIC) Adc_Bctu_aPreListElement[ADC_MAX_HW_UNITS] = {0U};
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

#define ADC_STOP_SEC_VAR_INIT_16
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"
#endif /* (ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) */

#define ADC_START_SEC_VAR_INIT_8
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"
/**
* @brief          Total indexfor BCTU trigger buffers for all units
*/
/** @violates @ref Adc_Bctu_c_REF_8 MISRA 2004 Required Rule 8.7, objects shall be defined at block scope */
extern VAR(uint8, ADC_VAR) Adc_Bctu_u8TotalIndex;

#define ADC_STOP_SEC_VAR_INIT_8
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define ADC_START_SEC_CODE
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

/**
* @brief          Checks the BCTU hardware status.
* @details        Checks the BCTU hardware status and compares it with the flag parameter.
*
* @param[in]      u32MaskValue   The mark value should be checked.
* @param[in]      u32testFlag    The flag that the status should be checked against.
*
* @return         Std_ReturnType  E_OK or E_NOT_OK.
* @retval         E_OK            In case of adc status read as expected.
* @retval         E_NOT_OK        In case of timeout while waiting for adc status to stabilize.
*
* @pre            Driver must be initialized.
*/
LOCAL_INLINE FUNC(Std_ReturnType, ADC_CODE) Adc_Bctu_StatusCheckTimeout
(
    VAR(uint32, AUTOMATIC) u32MaskValue,
    VAR(uint32, AUTOMATIC) u32testFlag
)
{
    VAR(volatile uint32, AUTOMATIC) u32Timeout = ADC_TIMEOUT_COUNTER;
    VAR(Std_ReturnType, AUTOMATIC) ReturnValue = (Std_ReturnType)E_OK;
    VAR(uint32, AUTOMATIC) u32BctuMcrValue;

    /* load the u32Timeout counter */
    u32Timeout = ADC_TIMEOUT_COUNTER;
    /* Wait until the global trigger is enabled */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    u32BctuMcrValue = REG_READ32(BCTU_MCR_ADDR32)&u32MaskValue;
    while(u32BctuMcrValue != u32testFlag)
    {

        if (u32Timeout > (uint32)0UL)
        {
            u32Timeout--;
        }
        /* If global trigger is not enabled, report the production error */
        else
        {
#if (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
            if((uint32)STD_ON == Adc_E_TimeoutCfg.state)
            {
                /* Report production error and return from function. */
                Dem_ReportErrorStatus((Dem_EventIdType)Adc_E_TimeoutCfg.id, DEM_EVENT_STATUS_FAILED);
            }
#endif /* (ADC_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */
            ReturnValue = (Std_ReturnType)E_NOT_OK;
        }
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        u32BctuMcrValue = REG_READ32(BCTU_MCR_ADDR32)&u32MaskValue;
    }
    return ReturnValue;
}

#ifdef ADC_BCTU_DMA_SUPPORTED
#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
/**
* @brief          This function initializes the DMA hardware module, to read
*                 from the BCTU data register to the user specified destination
*                 addresses.
* @details        Configures the DMA to use the user specified channel, to
*                 read from the user specified BCTU data register, to the user
*                 specified buffer, when the configured channel will be active.
*
* @param[in]      void
*
* @return         void
*
* @api
*/
LOCAL_INLINE FUNC(void, ADC_CODE) Adc_Bctu_SetupDma(void)
{
    VAR(uint8, AUTOMATIC) u8Index;
    VAR(uint8, AUTOMATIC) u8DmaVar = 0U;
    VAR(Mcl_DmaTcdAttributesType, AUTOMATIC) dmaTcdConfig;
    P2VAR(Mcl_DmaTcdType, AUTOMATIC, ADC_APPL_DATA) pTcdAddress;
    P2VAR(Mcl_DmaTcdAttributesType, AUTOMATIC, ADC_APPL_DATA) pTcdDmaConfig;
    VAR(Mcl_ChannelType, AUTOMATIC) DmaChannel;
    P2CONST(Adc_Bctu_TriggerConfigType, AUTOMATIC, ADC_APPL_CONST) pTriggerPtr = NULL_PTR;

    for (u8Index = 0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
    {
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);
        u8DmaVar |= (uint8)pTriggerPtr->u8AdcHwSelected;
    }

    dmaTcdConfig.u32ssize = (uint32)DMA_SIZE_4BYTES;
    dmaTcdConfig.u32dsize = (uint32)DMA_SIZE_4BYTES;
    dmaTcdConfig.u32soff = 0UL;
    dmaTcdConfig.u32num_bytes = (uint32) BCTU_DMA_TRANSFER_WORD_SIZE;
    dmaTcdConfig.u32iter = 1UL;
    dmaTcdConfig.u32doff = 4UL;
    dmaTcdConfig.u32smod = 0UL;
    dmaTcdConfig.u32dmod = 0UL;
    
    for(u8Index = 0U; u8Index < ADC_MAX_HW_UNITS; u8Index++)
    {
        if((ADC_UNIT_0_MASK_U32 << u8Index) == ((ADC_UNIT_0_MASK_U32 << u8Index) & u8DmaVar))
        {
            /* Get Dma channel for this unit */
            DmaChannel = Adc_Bctu_pCfgPtr->au8DmaChanel[u8Index];
            /* Get source address to configure TCD */
            dmaTcdConfig.u32saddr = (uint32)BCTU_ADCDR_ADDR32((uint32)u8Index);
            /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
            /** Compiler_Warning: It is intended for the address of the element to be passed
            to the structure field as an unsigned integer. */
            /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
            dmaTcdConfig.u32daddr = (uint32)(&Adc_Bctu_au32DmaInternalBuffer[u8Index][0]);
            /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
            pTcdAddress = (Mcl_DmaTcdType *)Mcl_DmaGetChannelTcdAddress((Mcl_ChannelType)DmaChannel);
            /** @violates @ref Adc_Bctu_c_REF_11 MISRA-C:2004 Rule 1.2: Undefined behaviour */
            pTcdDmaConfig = &dmaTcdConfig;
            Mcl_DmaConfigTcd(pTcdAddress, pTcdDmaConfig);
            Mcl_DmaTcdSetFlags(pTcdAddress, (DMA_TCD_DISABLE_REQ_U8 | DMA_TCD_INT_HALF_U8));
            /* Start the DMA channel */
            Mcl_DmaEnableHwRequest(DmaChannel);
        }
    }
}
#endif /* ADC_BCTU_DMA_SUPPORTED == STD_ON */
#endif /* ADC_BCTU_DMA_SUPPORTED */

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
#if (ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON)
/**
* @brief          This function initializes the BCTU hardware module.
* @details        Initializes all the BCTU registers and structures.
*
* @param[in]      pConfigPtr   BCTU configuration pointer structure.
*
* @return         void
*
* @api
*/
FUNC(void, ADC_CODE) Adc_Bctu_Init
(
    P2CONST(Adc_Bctu_ConfigType, AUTOMATIC, ADC_APPL_CONST) pConfigPtr
)
{
    VAR(uint8, AUTOMATIC)  u8Index = (uint8)0;
    VAR(uint8, AUTOMATIC)  u8ChIndex = (uint8)0;
    VAR(uint8, AUTOMATIC)  u8ListChRIndex = (uint8)0;
    VAR(uint32, AUTOMATIC) u32McrValue = (uint32)0;
    VAR(uint32, AUTOMATIC) u32TrgCfgValue = (uint32)0;
    VAR(uint32, AUTOMATIC) u32BctuInt = (uint32)0;
    VAR(uint32, AUTOMATIC) u32TempBCTU_LISTCHR = (uint32)0;
    VAR(uint8, AUTOMATIC) u8IsRemained = (uint8)0;
    P2CONST(Adc_Bctu_TriggerConfigType, AUTOMATIC, ADC_APPL_CONST) pTriggerPtr = NULL_PTR;

    Adc_Bctu_pCfgPtr = pConfigPtr;

    for (u8Index = (uint8)0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
    {
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);

#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
        /* Interrupt for DMA transfer */
        u32BctuInt |= ((uint32)pTriggerPtr->u8AdcHwSelected << BCTU_DMA_INT_SHIFT_MASK_U8);
#else
        u32BctuInt |= (uint32)pTriggerPtr->u8AdcHwSelected;
#endif /* (ADC_BCTU_DMA_SUPPORTED == STD_ON) */
    }

    /* Calculated BCTU_MCR_ADDR32 register value */
    u32McrValue = (uint32)((uint32)BCTU_MDIS_DIS_U32 |
                           (uint32)BCTU_FRZ_DIS_U32 |
                           (uint32)u32BctuInt |
                           (uint32)BCTU_TRG_INT_DIS_U32 |
                           (uint32)BCTU_LIST_INT_DIS_U32
                          );
    /* Set BCTU Main Configuration Register value */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(BCTU_MCR_ADDR32, u32McrValue);

    for (u8Index = (uint8)0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
    {
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);

        u32TrgCfgValue = (uint32)(((uint32)pTriggerPtr->u8BctuLoop << BCTU_LOOP_SHIFT_MASK_U8) |
                                  ((uint32)pTriggerPtr->u8BctuTrs << BCTU_LIST_SHIFT_MASK_U8) |
                                  ((uint32)pTriggerPtr->u8AdcHwSelected << BCTU_ADC_UNIT_SHIFT_MASK_U8) |
                                  ((uint32)pTriggerPtr->u8BctuLADDR)
                                 );
        /* Set BCTU Trigger Configuration Register value */
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(BCTU_TRGCFG_ADDR32((uint32)pTriggerPtr->u8BctuTrCfgId), u32TrgCfgValue);
        if((uint8)1 == pTriggerPtr->u8BctuTrs)
        {
            for(u8ChIndex = (uint8)0; u8ChIndex < (uint8)pTriggerPtr->u8NumListElement; u8ChIndex++)
            {
                if((uint8)0 == u8IsRemained)
                {
                    /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                    u32TempBCTU_LISTCHR = (uint32)((uint32)pTriggerPtr->pAdcChannelTriggered[u8ChIndex] << BCTU_LISTCHR_NUM_SHIFT_MASK_U8);
                }
                else
                {
                    /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                    u32TempBCTU_LISTCHR |= (uint32)pTriggerPtr->pAdcChannelTriggered[u8ChIndex];
                    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
                    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
                    REG_BIT_SET32(BCTU_LISTCHR_ADDR32((uint32)u8ListChRIndex), (uint32)u32TempBCTU_LISTCHR);

                    u8ListChRIndex++;
                }
                u8IsRemained = (uint8)1-u8IsRemained;
            }
        }
    }
    if((uint8)1 == u8IsRemained)
    {
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(BCTU_LISTCHR_ADDR32((uint32)u8ListChRIndex), (uint32)u32TempBCTU_LISTCHR);
    }
#if (ADC_BCTU_DMA_SUPPORTED == STD_ON)
    /* Also setup the DMA Transfer Descriptors */
    Adc_Bctu_SetupDma();
#endif /* ADC_BCTU_DMA_SUPPORTED == STD_ON */
}

/**
* @brief          This function de-initializes the BCTU hardware.
* @details        De-initializes all the BCTU registers and structures.
*
* @param[in]      void
*
* @return         void
*
* @api
*
* @violates @ref Adc_Bctu_c_REF_7 Declaration and definition of objects or function
*/
FUNC(void, ADC_CODE) Adc_Bctu_DeInit(void)
{
    VAR(uint8, AUTOMATIC) u8Index;
    P2CONST(Adc_Bctu_TriggerConfigType, AUTOMATIC, ADC_APPL_CONST) pTriggerPtr = NULL_PTR;

    /* Stop BCTU trigger */
    Adc_Bctu_StopCtu();

    /* Reset BCTU Main Configuration Register value */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(BCTU_MCR_ADDR32, (uint32)0x00000000UL);

    for (u8Index = (uint8)0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
    {
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);
        /* Reset BCTU Trigger Configuration Register value */
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(BCTU_TRGCFG_ADDR32((uint32)pTriggerPtr->u8BctuTrCfgId), (uint32)0x00000000UL);
    }

    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(BCTU_MSR_ADDR32, (uint32)0xFFFF0000UL);

    /* Enable write to BCTU_SFTRGR_ADDR32 register */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(BCTU_WRPROT_ADDR32, BCTU_WRPROT_DISABLE_PROTECTED_U32);

    for (u8Index = (uint8)0; u8Index < BCTU_NUMB_SFTRG_REG; u8Index++)
    {
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(BCTU_SFTRGR_ADDR32((uint32)u8Index), (uint32)0x00000000UL);
    }

    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(BCTU_WRPROT_ADDR32, (uint32)0x00000000UL);

    for (u8Index = (uint8)0; u8Index < BCTU_NUMB_LISTCHR_REG; u8Index++)
    {
        /* Reset BCTU LIST Channel Address Register value */
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_WRITE32(BCTU_LISTCHR_ADDR32((uint32)u8Index), (uint32)0x00000000UL);
    }

    /* Reset global BCTU configuration structure pointer */
    Adc_Bctu_pCfgPtr = NULL_PTR;
}

/**
* @brief          This function starts the BCTU hardware module configured.
* @details        Starts the input signals of the module.
*
* @param[in]      void
*
* @return         void
*
* @api
*/
FUNC(void, ADC_CODE) Adc_Bctu_StartCtu(void)
{
    VAR(uint8, AUTOMATIC)  u8Index;
    P2CONST(Adc_Bctu_TriggerConfigType, AUTOMATIC, ADC_APPL_CONST) pTriggerPtr = NULL_PTR;

    for (u8Index = 0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
    {
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);
        
        /* Enable input trigger */
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(BCTU_TRGCFG_ADDR32((uint32)pTriggerPtr->u8BctuTrCfgId), \
                      BCTU_INPUT_TRIG_EN_U32 | \
                      BCTU_TRIG_FLAG_CLEAR_U32 \
                     );
    }

    Adc_Bctu_u8TotalIndex = 0U;
    /* Enable global trigger for all trigger input */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_MCR_ADDR32, BCTU_GTRG_EN_U32);

    if ((Std_ReturnType)E_NOT_OK == Adc_Bctu_StatusCheckTimeout(BCTU_STATUS_U32, BCTU_SET_GTRG_EN_STATUS_U32))
    {
      /** @violates @ref Adc_Bctu_c_REF_6 Return statement before end of function. */
      return;
    }
}

/**
* @brief          This function stops the BCTU hardware module configured.
* @details        Stops the input signals of the module.
*
* @param[in]      void
*
* @return         void
*
* @api
*/
FUNC(void, ADC_CODE) Adc_Bctu_StopCtu(void)
{
    VAR(uint8, AUTOMATIC)  u8Index;
    P2CONST(Adc_Bctu_TriggerConfigType, AUTOMATIC, ADC_APPL_CONST) pTriggerPtr = NULL_PTR;

    /* Disable global trigger for all trigger input */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(BCTU_MCR_ADDR32, BCTU_GTRG_EN_U32);

    Adc_Bctu_u8TotalIndex = 0U;
    
    if ((Std_ReturnType)E_NOT_OK == Adc_Bctu_StatusCheckTimeout(BCTU_STATUS_U32, BCTU_CLEAR_GTRG_EN_STATUS_U32))
    {
        /** @violates @ref Adc_Bctu_c_REF_6 Return statement before end of function. */
        return;
    }
    for (u8Index = 0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
    {
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);

        /* Disable input trigger */
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(BCTU_TRGCFG_ADDR32((uint32)pTriggerPtr->u8BctuTrCfgId),BCTU_INPUT_TRIG_EN_U32);
        /* Clear input trigger flag */
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(BCTU_TRGCFG_ADDR32((uint32)pTriggerPtr->u8BctuTrCfgId),BCTU_TRIG_FLAG_CLEAR_U32);
    }
}

#if (ADC_SET_MODE_API == STD_ON)
/**
* @brief          This function set operation mode for BCTU module.
* @details        Set operation mode for BCTU module: Normal mode or power down mode
*
* @param[in]      Adc_SetModeType
*
* @return         Std_ReturnType
*
* @api
*/
FUNC(Std_ReturnType, ADC_CODE) Adc_Bctu_SetMode
(
    VAR(Adc_SetModeType, AUTOMATIC) eSetMode
)
{
    VAR(uint8, AUTOMATIC)  u8Index = (uint8)0;
    VAR(Std_ReturnType, AUTOMATIC) TempReturn = (Std_ReturnType)E_OK;
    P2CONST(Adc_Bctu_TriggerConfigType, AUTOMATIC, ADC_APPL_CONST) pTriggerPtr = NULL_PTR;

    if(ADC_POWER_DOWN_MODE == eSetMode)
    {
        /* Enter BCTU into power down mode */
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_SET32(BCTU_MCR_ADDR32, BCTU_MDIS_EN_U32);

        if ((Std_ReturnType)E_OK == Adc_Bctu_StatusCheckTimeout(BCTU_STATUS_U32, BCTU_SET_MDIS_EN_STATUS_U32))
        {
            for (u8Index = 0U; u8Index < Adc_Bctu_pCfgPtr->u8NumInputTrigger; u8Index++)
            {
                /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                pTriggerPtr = &(Adc_Bctu_pCfgPtr->pTriggerConfig[u8Index]);
                /* Clear input trigger flag */
                /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
                REG_BIT_SET32(BCTU_TRGCFG_ADDR32((uint32)pTriggerPtr->u8BctuTrCfgId), BCTU_TRIG_FLAG_CLEAR_U32);
            }
        }
        else
        {
            TempReturn = (Std_ReturnType)E_NOT_OK;
        }
    }
    else if (ADC_NORMAL_MODE == eSetMode)
    {
        /* Exit BCTU into normal mode */
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_BIT_CLEAR32(BCTU_MCR_ADDR32, BCTU_MDIS_EN_U32);

        if ((Std_ReturnType)E_NOT_OK == Adc_Bctu_StatusCheckTimeout(BCTU_STATUS_U32, BCTU_CLEAR_MDIS_EN_STATUS_U32))
        {
            TempReturn = (Std_ReturnType)E_NOT_OK;
        }
    }
    else
    {
        /* Nothing for Misra */
    }
    return (TempReturn);
}
#endif /* (ADC_SET_MODE_API == STD_ON) */
#endif /* ( ADC_ENABLE_CTU_CONTROL_MODE_API == STD_ON */

#if ((ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON))
/** @violates @ref Adc_Bctu_c_REF_7 Declaration and definition of objects or function */
FUNC(void, ADC_CODE) Adc_BctuUpdateListElement
(
    VAR(uint16, AUTOMATIC) u16ListIndex,
    VAR(uint32, AUTOMATIC) u32Value
)
{
    if (1U == (u16ListIndex%2U))
    {
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(BCTU_LISTCHR_ADDR32((uint32)u16ListIndex>>1U), BCTU_LIST_MASK_ODD_U32, u32Value);
    }
    else
    {
        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
        REG_RMW32(BCTU_LISTCHR_ADDR32((uint32)u16ListIndex>>1U), BCTU_LIST_MASK_EVEN_U32, \
                  (u32Value << BCTU_LISTCHR_NUM_SHIFT_MASK_U8) \
                 );
    }
}

/**
* @brief          This function updates the BCTU list address.
*
* @param[in]      Group           The group for which the BCTU list address is updated.
* @param[in]      pGroupPtr       Pointer to group configuration
*
* @return         void
*
* @violates @ref Adc_Bctu_c_REF_7 Declaration and definition of objects or function
*/
FUNC(void, ADC_CODE) Adc_BctuUpdateListAddress
(
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr
)
{
    VAR(uint16, AUTOMATIC) u16Idx = 0U;
    VAR(uint16, AUTOMATIC) u16RegIdx = 0U;
    VAR(uint16, AUTOMATIC) u16RegShift = 0U;
    VAR(uint16, AUTOMATIC) u16CurrentListAdd = 0U;
    VAR(uint16, AUTOMATIC) u16NextListAdd = 0U;
    VAR(uint16, AUTOMATIC) u16NumRegShift = 0U;
    VAR(uint32, AUTOMATIC) u32Temp = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;
    VAR(Adc_HwUnitType, AUTOMATIC) Unit  = pGroupPtr->HwUnit;
    
    u16CurrentListAdd = Adc_Bctu_au16ListChannelAddress[Unit];
#if (ADC_SETCHANNEL_API == STD_ON)
    ChannelCount = Adc_Bctu_aPreListElement[Unit];
#else
    /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    ChannelCount = pGroupPtr->AssignedChannelCount;
#endif
    for(u16Idx = 0U; u16Idx < ADC_MAX_HW_UNITS; u16Idx++)
    {
        u16NextListAdd = Adc_Bctu_au16ListChannelAddress[u16Idx];
        
        if(u16CurrentListAdd < u16NextListAdd)
        {
            Adc_Bctu_au16ListChannelAddress[u16Idx] -= ChannelCount;
            u16CurrentListAdd = Adc_Bctu_au16ListChannelAddress[u16Idx];
            for(u16RegIdx = 0U; u16RegIdx < BCTU_NUMB_TRGCFG_REG; u16RegIdx++)
            {
                /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
                /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
                u32Temp = REG_READ32(BCTU_TRGCFG_ADDR32((uint32)u16RegIdx));
                /* Check if the trigger is activated with list mode */
                if(BCTU_LIST_ACTIVE_MASK_U32 == (u32Temp & BCTU_LIST_ACTIVE_MASK_U32))
                {
                    /* Check if this trigger need to be updated */
                    if(u16NextListAdd == (u32Temp & BCTU_LIST_ADDR_MASK_U32))
                    {
                        /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
                        /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
                        REG_RMW32(BCTU_TRGCFG_ADDR32((uint32)u16RegIdx), \
                                  BCTU_LIST_ADDR_MASK_U32, u16CurrentListAdd \
                                 );
                    }
                }
            }
        }
    }

    u16RegIdx = Adc_Bctu_au16ListChannelAddress[Unit];
    u16RegShift = u16RegIdx + ChannelCount;
    u16NumRegShift = Adc_Bctu_u16ListAddressIndex - (u16RegIdx + ChannelCount);
    
    for(u16Idx = 0U; u16Idx < u16NumRegShift; u16Idx++)
    {
        if(1U == (u16RegShift%2U))
        {
            /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
            u32Temp = (REG_READ32(BCTU_LISTCHR_ADDR32((uint32)u16RegShift>>1U)) & BCTU_LIST_MASK_ODD_U32);
        }
        else
        {
            /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
            /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
            u32Temp = (REG_READ32(BCTU_LISTCHR_ADDR32((uint32)u16RegShift>>1U)) & BCTU_LIST_MASK_EVEN_U32) \
                      >> BCTU_LISTCHR_NUM_SHIFT_MASK_U8;
        }

        Adc_BctuUpdateListElement(u16RegIdx, (uint32)u32Temp);
        u16RegIdx++;
        u16RegShift++;
    }

#if (ADC_SETCHANNEL_API == STD_ON)
    Adc_Bctu_aPreListElement[Unit] = 0U;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
    Adc_Bctu_u16ListAddressIndex -= ChannelCount;
    Adc_Bctu_au16ListChannelAddress[Unit] = 0U;
}

/**
* @brief          This function sorts the channel list.
* @details        Non autosar API to sort the channel list used with BCTU.
*
* @param[in,out]  pListChannelSorted           The sorted list of channels.
* @param[in]      ListSize                     The size of channel list
*
* @return         void
*
* @violates @ref Adc_Bctu_c_REF_7 Declaration and definition of objects or function
*/
FUNC(void, ADC_CODE) Adc_BctuSortListChannels
(
    P2VAR(Adc_ChannelType, AUTOMATIC, ADC_APPL_CONST) pListChannelSorted,
    VAR(Adc_ChannelIndexType, AUTOMATIC) ListSize
)
{
    VAR(Adc_ChannelIndexType, AUTOMATIC) Index0 = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) Index1 = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) IdxMin = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) ChTemp = 0U;

    for (Index0 = 0U; Index0 < (ListSize-1U); Index0++) 
    {
        IdxMin = Index0;
        
        for (Index1 = (Index0+1U); Index1 < ListSize; Index1++)
        {
            /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            if (pListChannelSorted[Index1] < pListChannelSorted[IdxMin]) 
            { 
                IdxMin = Index1; 
            }
        }
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        ChTemp = pListChannelSorted[Index0];
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        pListChannelSorted[Index0] = pListChannelSorted[IdxMin];
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        pListChannelSorted[IdxMin] = ChTemp;
    }
}

/**
* @brief          This function enables the hardware trigger for the specified group.
* @details        Non autosar API to enable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be enabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Bctu_EnableCtuTrigger
(
    CONST(Adc_GroupType, AUTOMATIC) Group,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource,
    VAR(boolean, AUTOMATIC) bAutosarApi,
    VAR(boolean, AUTOMATIC) bFirstTrigger
)
{
    VAR(uint32, AUTOMATIC) u32TrgCfgValue = 0UL;
    VAR(uint32, AUTOMATIC) u32McrInit = 0UL;
    VAR(uint32, AUTOMATIC) u32Mask = 0UL;
    VAR(Adc_ChannelType, AUTOMATIC) PhChannel = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex = 0U;
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount;
    /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit = Adc_pCfgPtr->pGroups[Group].HwUnit;
    /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr = &(Adc_pCfgPtr->pGroups[Group]);
    VAR(Adc_ChannelType, AUTOMATIC) ListChannelSorted[ADC_MAXIMUM_HW_CHANNELS] = {0U};

    u32McrInit = BCTU_MDIS_DIS_U32|BCTU_FRZ_DIS_U32|BCTU_TRG_INT_DIS_U32;
    u32Mask = u32McrInit | BCTU_LIST_INT_EN_U32 | (1UL << Unit);
    
    if((boolean)TRUE == bAutosarApi)
    {
        if((uint8)STD_OFF == pGroupPtr->u8AdcWithoutInterrupt)
        {
#ifdef ADC_DMA_SUPPORTED
            if (ADC_INTERRUPT == Adc_pCfgPtr->Misc.u8Adc_DmaInterruptSoftware[Unit])
#endif /* ADC_DMA_SUPPORTED */
            {
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
                if(ADC_MHT_GROUP_TYPE == pGroupPtr->IsMHTGroup)
                {
                    u32McrInit |= (1UL << Unit);
                }
                else
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */
                {
                    u32McrInit |= BCTU_LIST_INT_EN_U32;
                }
            }
        }
    }
    /* Switch to configuration mode */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(BCTU_MCR_ADDR32, BCTU_GTRG_EN_U32);
    /* Set BCTU Main Configuration Register value */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_RMW32(BCTU_MCR_ADDR32, u32Mask, u32McrInit);
    /* Clear timer flag through software */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_TRGCFG_ADDR32((uint32)TriggerSource), BCTU_TRIG_FLAG_CLEAR_U32);

#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
    if(ADC_MHT_GROUP_TYPE == pGroupPtr->IsMHTGroup)
    {
        /* Configure for single mode */
#if (ADC_SETCHANNEL_API == STD_ON)
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        PhChannel = Adc_pCfgPtr->pChannels[Unit][Adc_aRuntimeGroupChannel[Group].pChannel[0]].ChId;
#else
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        PhChannel = Adc_pCfgPtr->pChannels[Unit][(pGroupPtr->pAssignment[0])].ChId;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */

        u32TrgCfgValue = (1UL << (BCTU_ADC_UNIT_SHIFT_MASK_U8 + Unit)) | PhChannel;
    }
    else
#endif /* ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON */
    {
        /* Configure for list mode */
        u32TrgCfgValue = ((1UL << BCTU_LIST_SHIFT_MASK_U8) | 
                          (1UL << (BCTU_ADC_UNIT_SHIFT_MASK_U8 + Unit))
                         );
        /* If this is the first call for this group */
        if((boolean)TRUE == bFirstTrigger)
        {
            /* Add new list address for new group */
            u32TrgCfgValue |= Adc_Bctu_u16ListAddressIndex;

            /* Get index of List channel register */
            Adc_Bctu_au16ListChannelAddress[Unit] = Adc_Bctu_u16ListAddressIndex;
#if (ADC_SETCHANNEL_API == STD_ON)
            ChannelCount = Adc_aRuntimeGroupChannel[Group].ChannelCount;
#else
            /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
            ChannelCount = pGroupPtr->AssignedChannelCount;
#endif
            for(ChIndex = (Adc_ChannelType)0; ChIndex < ChannelCount; ChIndex++)
            {
#if (ADC_SETCHANNEL_API == STD_ON)
                /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                ListChannelSorted[ChIndex] = Adc_pCfgPtr->pChannels[Unit][Adc_aRuntimeGroupChannel[Group].pChannel[ChIndex]].ChId;
#else
                /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                ListChannelSorted[ChIndex] = Adc_pCfgPtr->pChannels[Unit][(pGroupPtr->pAssignment[ChIndex])].ChId;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
            }
            /* Sort list channels */
            /** @violates @ref Adc_Bctu_c_REF_11 MISRA-C:2004 Rule 1.2: Undefined behaviour */
            Adc_BctuSortListChannels(ListChannelSorted, ChannelCount);
            
            for(ChIndex = (Adc_ChannelType)0; ChIndex < ChannelCount; ChIndex++)
            {
                /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
                /* PhChannel = Adc_pCfgPtr->pChannels[Unit][(pGroupPtr->pAssignment[ChIndex])].ChId; */
                PhChannel = ListChannelSorted[ChIndex];
                /* If this is last channels of this group */
                if (ChIndex == (ChannelCount - (Adc_ChannelType)1))
                {
                    Adc_BctuUpdateListElement(Adc_Bctu_u16ListAddressIndex, (uint32)(PhChannel | BCTU_LAST_CHANNEL_U32));
                }
                else
                {
                    Adc_BctuUpdateListElement(Adc_Bctu_u16ListAddressIndex, (uint32)PhChannel);
                }
                
                Adc_Bctu_u16ListAddressIndex++;
            }
#if (ADC_SETCHANNEL_API == STD_ON)
            Adc_Bctu_aPreListElement[Unit] = ChannelCount;
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
        }
    }

    /* Set BCTU Trigger Configuration Register value */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(BCTU_TRGCFG_ADDR32((uint32)TriggerSource), u32TrgCfgValue | BCTU_INPUT_TRIG_EN_U32);

    /* Enable global trigger for all trigger input */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    REG_BIT_SET32(BCTU_MCR_ADDR32, BCTU_GTRG_EN_U32);

    if ((Std_ReturnType)E_NOT_OK == Adc_Bctu_StatusCheckTimeout(BCTU_STATUS_U32, BCTU_SET_GTRG_EN_STATUS_U32))
    {
        /** @violates @ref Adc_Bctu_c_REF_6 Return statement before end of function. */
        return;
    }
}

/**
* @brief          This function disables the hardware trigger for the specified group.
* @details        Non autosar API to disable the trigger source configured for the group.
*
* @param[in]      Group           The group for which the hardware triggers will be disabled.
* @param[in]      TriggerSource   Trigger source to be use for the group
*
* @return         void
*
*/
FUNC(void, ADC_CODE) Adc_Bctu_DisableCtuTrigger
(
    P2CONST(Adc_GroupConfigurationType, AUTOMATIC, ADC_APPL_CONST) pGroupPtr,
    VAR(Adc_HwTriggerTimerType, AUTOMATIC) TriggerSource,
    VAR(boolean, AUTOMATIC) bLastTrigger
)
{
    /* Disable global trigger for all trigger input */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(BCTU_MCR_ADDR32, BCTU_GTRG_EN_U32);
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_CLEAR32(BCTU_TRGCFG_ADDR32((uint32)TriggerSource), BCTU_INPUT_TRIG_EN_U32);
    
    if((boolean)TRUE == bLastTrigger)
    {
#if (ADC_MULTIPLE_HARDWARE_TRIGGERS == STD_ON)
        if(ADC_REGULAR_GROUP_TYPE == pGroupPtr->IsMHTGroup)
#endif
        {
            Adc_BctuUpdateListAddress(pGroupPtr);
        }
    }
    /* Clear all interrupt flag status */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_MSR_ADDR32, 0xFFFF0000UL);
    /* Reset input trigger */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_WRITE32(BCTU_TRGCFG_ADDR32((uint32)TriggerSource), BCTU_TRIG_FLAG_CLEAR_U32);
    /* Enable global trigger for all trigger input */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    REG_BIT_SET32(BCTU_MCR_ADDR32, BCTU_GTRG_EN_U32);
}

#if (ADC_SETCHANNEL_API == STD_ON)
/** @violates @ref Adc_Bctu_c_REF_7 Declaration and definition of objects or function */
FUNC(void, ADC_CODE) Adc_BctuUpdateCurrentListElement
(
    VAR(Adc_GroupType, AUTOMATIC) Group,
    P2CONST(Adc_ChannelType, AUTOMATIC, ADC_APPL_CONST) pListChannelSorted,
    VAR(Adc_ChannelIndexType, AUTOMATIC) ChannelCount
)
{
    VAR(uint32, AUTOMATIC) u32TrgCfgValue = 0UL;
    VAR(Adc_ChannelType, AUTOMATIC) ChIndex = 0U;
    VAR(Adc_ChannelType, AUTOMATIC) PhChannel = 0U;
    /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    VAR(Adc_HwUnitType, AUTOMATIC) Unit  = (&(Adc_pCfgPtr->pGroups[Group]))->HwUnit;
    
    /* Configure for list mode and add new list address for new group */
    u32TrgCfgValue = ((uint32)(1UL << BCTU_LIST_SHIFT_MASK_U8) | (uint32)(1UL << (BCTU_ADC_UNIT_SHIFT_MASK_U8 + Unit))) | (uint32)Adc_Bctu_u16ListAddressIndex;
    /* Get index of List channel register */
    Adc_Bctu_au16ListChannelAddress[Unit] = Adc_Bctu_u16ListAddressIndex;
    
    for(ChIndex = (Adc_ChannelType)0; ChIndex < ChannelCount; ChIndex++)
    {
        /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
        PhChannel = pListChannelSorted[ChIndex];
        /* If this is last channels of this group */
        if (ChIndex == (ChannelCount - (Adc_ChannelType)1))
        {
            Adc_BctuUpdateListElement(Adc_Bctu_u16ListAddressIndex, (uint32)(PhChannel | BCTU_LAST_CHANNEL_U32));
        }
        else
        {
            Adc_BctuUpdateListElement(Adc_Bctu_u16ListAddressIndex, (uint32)PhChannel);
        }
        
        Adc_Bctu_u16ListAddressIndex++;
    }

    /* Set BCTU Trigger Configuration Register value */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    REG_WRITE32(BCTU_TRGCFG_ADDR32((uint32)(&(Adc_pCfgPtr->pGroups[Group]))->pHwResource[0]), (u32TrgCfgValue | BCTU_INPUT_TRIG_EN_U32));
    
    /* Enable global trigger for all trigger input */
    /** @violates @ref Adc_Bctu_c_REF_5 A cast should not be performed between a pointer type and an integral type. */
    /** @violates @ref Adc_Bctu_c_REF_3 cast from unsigned int to pointer */
    REG_BIT_SET32(BCTU_MCR_ADDR32, BCTU_GTRG_EN_U32);

    /** @violates @ref Adc_Bctu_c_REF_4 Array indexing shall be the only allowed form of pointer arithmetic */
    Adc_Bctu_aPreListElement[Adc_pCfgPtr->pGroups[Group].HwUnit] = ChannelCount;
}
#endif /* (ADC_SETCHANNEL_API == STD_ON) */
#endif /*(ADC_ENABLE_CTUTRIG_NONAUTO_API == STD_ON) || (ADC_HW_TRIGGER_API == STD_ON) */

#define ADC_STOP_SEC_CODE
/**
* @violates @ref Adc_Bctu_c_REF_1 only preprocessor statements and comments before "#include"
* @violates @ref Adc_Bctu_c_REF_2 Repeated include file MemMap.h
*/
#include "Adc_MemMap.h"

#endif /* ((STD_ON == ADC_ENABLE_CTU_CONTROL_MODE_API) || \
           (STD_ON == ADC_ENABLE_CTUTRIG_NONAUTO_API) || \
           (STD_ON == ADC_HW_TRIGGER_API) \
          ) */

#ifdef __cplusplus
}
#endif

/** @} */
