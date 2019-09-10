/**
*   @file    Mcl_Axbs.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcl - Axbs low level driver.
*   @details contains the low level driver for the Axbs module.
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

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcl_AXBS_c_REF_2
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken in order to
* prevent the contents of a header file being included twice.
* All header files are protected against multiple inclusions
*
* @section [global]
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters. The used compilers use more than 31 chars 
* for identifiers.
*
* @section Mcl_AXBS_c_REF_6
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before "#include". This violation  is not  fixed since  the inclusion  of MemMap.h
* is as  per Autosar  requirement MEMMAP003.
*
* @section Mcl_AXBS_c_REF_9
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions at file scope
* shall have internal linkage unless external linkage is required.
*
* @section Mcl_AXBS_c_REF_10
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a pointer to 
* a function and any type other than an integral type.
*
* @section Mcl_AXBS_c_REF_11
* Violates MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between
* a pointer type and an integral type
* This violation is due to the pointer arithmetic used to write/ read
* the data to/from the registers.
*
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "CDD_Mcl_Cfg.h"

#ifdef MCL_ENABLE_CROSSBAR
#if (MCL_ENABLE_CROSSBAR == STD_ON)

#include "Mcl_Axbs.h"
#include "CDD_Mcl.h"
#if (MCL_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Mcl_Axbs.c
*/
#define MCL_AXBS_VENDOR_ID_C                    43
#define MCL_AXBS_AR_RELEASE_MAJOR_VERSION_C     4
#define MCL_AXBS_AR_RELEASE_MINOR_VERSION_C     2
#define MCL_AXBS_AR_RELEASE_REVISION_VERSION_C  2
#define MCL_AXBS_SW_MAJOR_VERSION_C             1
#define MCL_AXBS_SW_MINOR_VERSION_C             0
#define MCL_AXBS_SW_PATCH_VERSION_C             0


/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/

#if (MCL_AXBS_VENDOR_ID_C != MCL_AXBS_VENDOR_ID)
    #error "Mcl_Axbs.c and Mcl_Axbs.h have different vendor IDs"
#endif
/* Check if source file and Mcl_Axbs header file are of the same Autosar version */
#if ((MCL_AXBS_AR_RELEASE_MAJOR_VERSION_C != MCL_AXBS_AR_RELEASE_MAJOR_VERSION) || \
     (MCL_AXBS_AR_RELEASE_MINOR_VERSION_C != MCL_AXBS_AR_RELEASE_MINOR_VERSION) || \
     (MCL_AXBS_AR_RELEASE_REVISION_VERSION_C != MCL_AXBS_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Mcl_Axbs.h and Mcl_Axbs.c are different"
#endif
/* Check if source file and Mcl_Axbs header file are of the same Software version */
#if ((MCL_AXBS_SW_MAJOR_VERSION_C != MCL_AXBS_SW_MAJOR_VERSION) || \
     (MCL_AXBS_SW_MINOR_VERSION_C != MCL_AXBS_SW_MINOR_VERSION) || \
     (MCL_AXBS_SW_PATCH_VERSION_C != MCL_AXBS_SW_PATCH_VERSION))
    #error "Software Version Numbers of Mcl_Axbs.h and Mcl_Axbs.c are different"
#endif


#if (MCL_AXBS_VENDOR_ID_C != MCL_VENDOR_ID_CFG)
    #error "Mcl_Axbs.c and CDD_Mcl_Cfg.h have different vendor IDs"
#endif
/* Check if source file and CDD_Mcl_Cfg header file are of the same Autosar version */
#if ((MCL_AXBS_AR_RELEASE_MAJOR_VERSION_C != MCL_AR_RELEASE_MAJOR_VERSION_CFG) || \
     (MCL_AXBS_AR_RELEASE_MINOR_VERSION_C != MCL_AR_RELEASE_MINOR_VERSION_CFG) || \
     (MCL_AXBS_AR_RELEASE_REVISION_VERSION_C != MCL_AR_RELEASE_REVISION_VERSION_CFG))
    #error "AutoSar Version Numbers of CDD_Mcl_Cfg.h and Mcl_Axbs.c are different"
#endif
/* Check if source file and CDD_Mcl_Cfg header file are of the same Software version */
#if ((MCL_AXBS_SW_MAJOR_VERSION_C != MCL_SW_MAJOR_VERSION_CFG) || \
     (MCL_AXBS_SW_MINOR_VERSION_C != MCL_SW_MINOR_VERSION_CFG) || \
     (MCL_AXBS_SW_PATCH_VERSION_C != MCL_SW_PATCH_VERSION_CFG))
    #error "Software Version Numbers of CDD_Mcl_Cfg.h and Mcl_Axbs.c are different"
#endif


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#define MCL_START_SEC_CONST_32
/**
* @violates @ref Mcl_AXBS_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice
*
* @violates @ref Mcl_AXBS_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
and comments before "#include"
*/
#include "Mcl_MemMap.h"
/**
* @brief base address array for Axbs
*/
/**
* @violates @ref Mcl_AXBS_c_REF_9 All declarations and definitions shall have internal linkage unless external  
* is required
*/
CONST(uint32, MCL_CONST) AXBS_BASE_ADDR32[MCL_CROSSBAR_NUM_INSTANCES] = {
    XBAR_0_BASEADDR
#ifdef XBAR_1_BASEADDR
    #if (MCL_CROSSBAR_NUM_INSTANCES > 1U)
    ,XBAR_1_BASEADDR
    #endif
#endif
};

#define MCL_STOP_SEC_CONST_32
/**
* @violates @ref Mcl_AXBS_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice
*
* @violates @ref Mcl_AXBS_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
and comments before "#include"
*/
#include "Mcl_MemMap.h"
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/
#define MCL_START_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_AXBS_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice
*
* @violates @ref Mcl_AXBS_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
and comments before "#include"
*/
#include "Mcl_MemMap.h"


#define MCL_STOP_SEC_CONST_UNSPECIFIED
/**
* @violates @ref Mcl_AXBS_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
* of a header file being included twice
*
* @violates @ref Mcl_AXBS_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements 
and comments before "#include"
*/
#include "Mcl_MemMap.h"

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define MCL_START_SEC_CODE
/**
* @violates @ref Mcl_AXBS_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*       of a header file being included twice 
*
* @violates @ref Mcl_AXBS_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*/
#include "Mcl_MemMap.h"


/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
* @brief        This function initializes the AXBS module. 
* @details     
*
* @param[in]    pAxbsConfig - pointer to Axbs configuration structure
*/
FUNC(void, MCL_CODE) Axbs_Init( P2CONST(Mcl_CrossbarConfigType, AUTOMATIC, MCL_APPL_CONST) pAxbsConfig)
{
    /* @brief Counter value used in loops */
    VAR(uint8, AUTOMATIC) u8Counter;
    /* @brief Pointer to DMA channel specific configuration */
    P2CONST(Mcl_AxbsSlavePortConfigType, AUTOMATIC, MCL_APPL_CONST) pSlavePortConfig = NULL_PTR;
#ifdef MCL_AXBS_ENABLE_INIT_MGPCR
    #if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)    
        P2CONST(Mcl_AxbsMasterPortConfigType, AUTOMATIC, MCL_APPL_CONST) pMasterPortConfig = NULL_PTR;
    #endif
#endif
    /* Configuring channels Enable, Trigger and Source */
    for (u8Counter = 0x0U; u8Counter < pAxbsConfig->MclCrossbarIpNumPorts; u8Counter++)
    {
        pSlavePortConfig = &((*(pAxbsConfig->pMclCrossbarSlaveHwIpConfig))[u8Counter]);
        /** @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to a function and any type other than an integral type. */
        /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        if((REG_READ32(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber)) & AXBS_LK_BIT_MASK32) == 0UL)
        {
#ifdef MCL_CROSSBAR_PRS_READONLY
    #if (STD_OFF == MCL_CROSSBAR_PRS_READONLY)
            /**
            * @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to 
            * a function and any type other than an integral type.
            */
            /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_RMW32(AXBS_PRS_ADDR(pSlavePortConfig->Axbs_PortNumber,pSlavePortConfig->Axbs_InstanceNumber), AXBS_PRS_MASK32, pSlavePortConfig->Axbs_PortPriorityConfig);
    #endif
#endif
            /**
            * @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to 
            * a function and any type other than an integral type.
            */
            /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_WRITE32(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber),pSlavePortConfig->Axbs_PortControlConfig);
        }
#if (MCL_DEV_ERROR_DETECT == STD_ON)   
        else
        {   
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_INIT_ID_U8, (uint8)MCL_E_CRS_AXBS_LOCKED_U8);
        }
#endif        
    }
    
#ifdef MCL_AXBS_ENABLE_INIT_MGPCR
    #if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)
        /* Configuring for Master ports */
        for (u8Counter = 0x0U; u8Counter < pAxbsConfig->MclCrossbarMasterNumPorts; u8Counter++)
        {
            pMasterPortConfig = &((*(pAxbsConfig->pMclCrossbarMasterHwIpConfig))[u8Counter]);
            /**
            * @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to 
            * a function and any type other than an integral type.
            */
            /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
            REG_RMW32(AXBS_MGPCR_ADDR(pMasterPortConfig->Axbs_PortNumber, pMasterPortConfig->Axbs_InstanceNumber), AXBS_MGPCR_MASK32, pMasterPortConfig->Axbs_MasterGeneralConfig);
        }
    #endif
#endif
}

#if (MCL_DEINIT_API == STD_ON)
/**
* @brief        This function de-initializes the AXBS module. 
* @details     
*
* @param[in]    pAxbsConfig - pointer to Axbs configuration structure
*/
FUNC(void, MCL_CODE) Axbs_DeInit( P2CONST(Mcl_CrossbarConfigType, AUTOMATIC, MCL_APPL_CONST) pAxbsConfig)
{
    /* @brief Counter value used in loops */
    VAR(uint8, AUTOMATIC) u8Counter;
    /* @brief Pointer to DMA channel specific configuration */
    P2CONST(Mcl_AxbsSlavePortConfigType, AUTOMATIC, MCL_APPL_CONST) pSlavePortConfig = NULL_PTR;
#ifdef MCL_AXBS_ENABLE_INIT_MGPCR
    #if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)    
        P2CONST(Mcl_AxbsMasterPortConfigType, AUTOMATIC, MCL_APPL_CONST) pMasterPortConfig = NULL_PTR;
    #endif
#endif
    /* Configuring channels Enable, Trigger and Source */
    for (u8Counter = 0x0U; u8Counter < pAxbsConfig->MclCrossbarIpNumPorts; u8Counter++)
    {
        pSlavePortConfig = &((*(pAxbsConfig->pMclCrossbarSlaveHwIpConfig))[u8Counter]);
        /**
        * @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to 
        * a function and any type other than an integral type.
        */
        /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        if((REG_READ32(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber)) & AXBS_LK_BIT_MASK32) == 0UL)
        {
#ifdef MCL_CROSSBAR_PRS_READONLY
    #if (STD_OFF == MCL_CROSSBAR_PRS_READONLY)       
            if(AXBS_INSTANCE0 == pSlavePortConfig->Axbs_InstanceNumber)
            {
                /** @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to a function and any type other than an integral type. */
                /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
                REG_RMW32(AXBS_PRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber), AXBS_PRS_MASK32, MCL_CROSSBAR0_PRS_RESET_VALUE_U32);
            }
        #ifdef MCL_CROSSBAR_NUM_INSTANCES
            #if (MCL_CROSSBAR_NUM_INSTANCES == 2U)
            else
            {
                /** @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to a function and any type other than an integral type. */
                /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
                REG_RMW32(AXBS_PRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber), AXBS_PRS_MASK32, MCL_CROSSBAR1_PRS_RESET_VALUE_U32);
            }
            #endif
        #endif
    #endif
#endif
            if(AXBS_INSTANCE0 == pSlavePortConfig->Axbs_InstanceNumber)
            {
                /** @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to a function and any type other than an integral type. */
                /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
                REG_WRITE32(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber), MCL_CROSSBAR0_CRS_RESET_VALUE_U32);
            }
#ifdef MCL_CROSSBAR_NUM_INSTANCES
    #if (MCL_CROSSBAR_NUM_INSTANCES == 2U)
            else
            {
                /** @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to a function and any type other than an integral type. */     
                /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
                REG_WRITE32(AXBS_CRS_ADDR(pSlavePortConfig->Axbs_PortNumber, pSlavePortConfig->Axbs_InstanceNumber), MCL_CROSSBAR1_CRS_RESET_VALUE_U32);
            }
    #endif
#endif 
        }
#if (MCL_DEV_ERROR_DETECT == STD_ON)
        else
        {
            (void)Det_ReportError((uint16)MCL_MODULE_ID, 0U, (uint8)MCL_DEINIT_ID_U8, (uint8)MCL_E_CRS_AXBS_LOCKED_U8);
        }
#endif
#ifdef MCL_AXBS_ENABLE_INIT_MGPCR
    #if (STD_ON == MCL_AXBS_ENABLE_INIT_MGPCR)  
        pMasterPortConfig = &((*(pAxbsConfig->pMclCrossbarMasterHwIpConfig))[u8Counter]);
        /**
        * @violates @ref Mcl_AXBS_c_REF_10 Conversions shall not be performed between a pointer to 
        * a function and any type other than an integral type.
        */
        /** @violates @ref Mcl_AXBS_c_REF_11 MISRA 2004 Advisory Rule 11.3, A Cast should not be performed between a pointer type and an integral type */
        REG_RMW32(AXBS_MGPCR_ADDR(pMasterPortConfig->Axbs_PortNumber, pMasterPortConfig->Axbs_InstanceNumber), AXBS_MGPCR_MASK32, (uint32)0x00000000);
    #endif
#endif
    }
}
#endif
#define MCL_STOP_SEC_CODE
/**
* @violates @ref Mcl_AXBS_c_REF_2 MISRA 2004 Advisory Rule 19.15, precautions to prevent the contents
*       of a header file being included twice 
*
* @violates @ref Mcl_AXBS_c_REF_6 Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
*        before "#include"
*/
#include "Mcl_MemMap.h"

#endif     /* #ifdef MCL_ENABLE_CROSSBAR */
#endif     /* #if (MCL_ENABLE_CROSSBAR == STD_ON) */

#ifdef __cplusplus
}
#endif
/** @} */
