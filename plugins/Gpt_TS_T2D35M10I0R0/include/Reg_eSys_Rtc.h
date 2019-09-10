/**
*   @file    Reg_eSys_Rtc.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Gpt - Source file of the RTC driver.
*   @details RTC driver interface.
*
*   @addtogroup GPT_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios_Stm_Pit
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

#ifndef REG_ESYS_RTC_H
#define REG_ESYS_RTC_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section REG_ESYS_RTC_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, IIdentifiers (internal and external) shall not rely on the significance
* of more than 31 characters.
* The long identifiers are maintained for better readability.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.15, Repeated include file */
#include "Reg_eSys.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define REG_ESYS_RTC_VENDOR_ID                       43
#define REG_ESYS_RTC_AR_RELEASE_MAJOR_VERSION        4
#define REG_ESYS_RTC_AR_RELEASE_MINOR_VERSION        2
#define REG_ESYS_RTC_AR_RELEASE_REVISION_VERSION     2
#define REG_ESYS_RTC_SW_MAJOR_VERSION                1
#define REG_ESYS_RTC_SW_MINOR_VERSION                0
#define REG_ESYS_RTC_SW_PATCH_VERSION                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if this header file and Reg_eSys.h file are of the same Autosar version */
    #if ((REG_ESYS_RTC_AR_RELEASE_MAJOR_VERSION != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
         (REG_ESYS_RTC_AR_RELEASE_MINOR_VERSION != REG_ESYS_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Reg_eSys_Rtc.h and Reg_eSys.h are different"
    #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef IPV_RTC
/* @brief IP version RTC.00.03.00.03 */
    #define IPV_RTC_00_03_00_03    (0x00000303UL)
#endif

/**
* @{
* @brief Real Time Counter (RTC) Registers address
*/
#ifdef IPV_RTC
    #if (IPV_RTC == IPV_RTC_00_03_00_03)
        #define RTC_SUPV_ADDR32                     (RTC_BASEADDR + (uint32)0x00UL)
        #define RTC_CTRL_ADDR32                     (RTC_BASEADDR + (uint32)0x04UL)
        #define RTC_STATUS_ADDR32                   (RTC_BASEADDR + (uint32)0x08UL)
        #define RTC_CNT_ADDR32                      (RTC_BASEADDR + (uint32)0x0CUL)
        #define RTC_APIVAL_ADDR32                   (RTC_BASEADDR + (uint32)0x10UL)
        #define RTC_RTCVAL_ADDR32                   (RTC_BASEADDR + (uint32)0x14UL)
        #define RTC_ANLCMP_CNT_ADDR32               (RTC_BASEADDR + (uint32)0x18UL)
    #else
        #define RTC_CTRL_ADDR32                     (RTC_BASEADDR + (uint32)0x00UL)
        #define RTC_STATUS_ADDR32                   (RTC_BASEADDR + (uint32)0x04UL)
        #define RTC_COR_VAL_ADDR32                  (RTC_BASEADDR + (uint32)0x08UL)
        #define RTC_WKEUP_ADDR32                    (RTC_BASEADDR + (uint32)0x0CUL)
        #define RTC_WKEUP_CNT_ADDR32                (RTC_BASEADDR + (uint32)0x10UL)
        #define RTC_TOD_ADDR32                      (RTC_BASEADDR + (uint32)0x14UL)
        #define RTC_SCCPRSC_ADDR32                  (RTC_BASEADDR + (uint32)0x18UL)
        #define RTC_APIVAL_ADDR32                   (RTC_BASEADDR + (uint32)0x1CUL)
        #define RTC_ANLCMP_ADDR32                   (RTC_BASEADDR + (uint32)0x20UL)
    #endif
#endif
/**@}*/

/**
* @brief Number of channels in RTC
*/
#define RTC_MAX_CH                          ((uint8)1U)


#ifdef IPV_RTC
    #if (IPV_RTC == IPV_RTC_00_03_00_03)
        /**
        * @brief Bit mask for RTC Supervisor Control Register
        */
        #define RTC_SUPV_MASK_U32           ((uint32)BIT31)
        /**
        * @{
        * @brief Bit mask for RTC Control Register
        */
        #define RTC_CTLR_CNTEN_MASK_U32      ((uint32)BIT31)
        #define RTC_CTLR_CNTEN_SHIFT         ((uint32)31U)
        #define RTC_CTLR_RTCIE_MASK_U32      ((uint32)BIT30)
        #define RTC_CTLR_RTCIE_SHIFT         ((uint32)30U)
        #define RTC_CTLR_FRZEN_MASK_U32      ((uint32)BIT29)
        #define RTC_CTLR_FRZEN_SHIFT         ((uint32)29U)
        #define RTC_CTLR_ROVREN_MASK_U32     ((uint32)BIT28)
        #define RTC_CTLR_ROVREN_SHIFT        ((uint32)28U)
        #define RTC_CTLR_APIEN_MASK_U32      ((uint32)BIT15)
        #define RTC_CTLR_APIEN_SHIFT         ((uint32)15U)
        #define RTC_CTLR_APIIE_MASK_U32      ((uint32)BIT14)
        #define RTC_CTLR_APIIE_SHIFT         ((uint32)14U)
        #define RTC_CTLR_CLKSEL_MASK_U32     ((uint32)BIT13|BIT12)
        #define RTC_CTLR_CLKSEL_SHIFT        ((uint32)12U)
        #define RTC_CTLR_DIV512EN_MASK_U32   ((uint32)BIT11)
        #define RTC_CTLR_DIV512EN_SHIFT      ((uint32)11U)
        #define RTC_CTLR_DIV32EN_MASK_U32    ((uint32)BIT10)
        #define RTC_CTLR_DIV32EN_SHIFT       ((uint32)10U)


        /**
        * @{
        * @brief Bit mask for RTC Status Register
        */
        #define RTC_STATUS_RTCF_MASK_U32       ((uint32)BIT29)
        #define RTC_STATUS_RTCF_SHIFT          ((uint32)29U)
        #define RTC_STATUS_APIF_MASK_U32       ((uint32)BIT13)
        #define RTC_STATUS_APIF_SHIFT          ((uint32)13U)
        #define RTC_STATUS_ROVRF_MASK_U32      ((uint32)BIT10)
        #define RTC_STATUS_ROVRF_SHIFT         ((uint32)10U)
        #define RTC_STATUS_ALL_INT_MASK_U32    ((uint32)BIT29|BIT13|BIT10)
        /**@}*/

        /**
        * @{
        * @brief Bit offset for RTC Control Register
        */
        #define RTC_CLKSEL_OFFSET                   ((uint32)(12U))
        #define RTC_DIV_OFFSET                      ((uint32)(10U))
        
        /**
        * @{
        * @brief Define max value of RTC_APIVAL register
        */

        #define RTC_APIVAL_MASK_U32                 ((uint32)0xFFFFFFFFUL)

    #else
        /**
        * @{
        * @brief Bit mask for RTC Control Register
        */
        #define RTC_CTLR_RTCEN_MASK_U32             ((uint32)(BIT31))
        #define RTC_CTLR_RTCEN_SHIFT                ((uint32)(31U))

        #define RTC_CTLR_WKP_RES_MASK_U32           ((uint32)(BIT30|BIT29))
        #define RTC_CTLR_WKP_RES_SHIFT              ((uint32)(29U))

        #define RTC_CTLR_WKP_CLK_SEL_MASK_U32       ((uint32)(BIT28))
        #define RTC_CTLR_WKP_CLK_SHIFT              ((uint32)(28U))

        #define RTC_CTLR_ANL_TRIG_EN_MASK_U32        ((uint32)(BIT26))
        #define RTC_CTLR_ANL_TRIG_EN_SHIFT           ((uint32)(26U))

        #define RTC_CTLR_TRIGEN_MASK_U32             ((uint32)(BIT25))
        #define RTC_CTLR_TRIGEN_SHIFT                ((uint32)(25U))

        #define RTC_CTLR_SCLKSEL_MASK_U32            ((uint32)(BIT23|BIT22))
        #define RTC_CTLR_SCLKSEL_SHIFT               ((uint32)(22U))

        #define RTC_CTLR_PREDIV_MASK_U32             ((uint32)(BIT21|BIT20|BIT19|BIT18|BIT17|BIT16))
        #define RTC_CTLR_PREDIV_SHIFT                ((uint32)(16U))

        #define RTC_CTLR_APIEN_MASK_U32              ((uint32)(BIT15))
        #define RTC_CTLR_APIEN_SHIFT                 ((uint32)(15U))

        #define RTC_CTLR_APIIE_MASK_U32              ((uint32)(BIT14))
        #define RTC_CTLR_APIIE_SHIFT                 ((uint32)(14U))

        #define RTC_CTLR_FRZEN_MASK_U32              ((uint32)(BIT12))
        #define RTC_CTLR_FRZEN_SHIFT                 ((uint32)(12U))

        #define RTC_CTLR_CLKSEL_MASK_U32             ((uint32)(BIT9))
        #define RTC_CTLR_CLKSEL_SHIFT                ((uint32)(9U))

        #define RTC_CTLR_WKPEN_MASK_U32              ((uint32)(BIT7))
        #define RTC_CTLR_WKPEN_SHIFT                 ((uint32)(7U))

        #define RTC_CTLR_DAYEN_MASK_U32              ((uint32)(BIT6))
        #define RTC_CTLR_DAYEN_SHIFT                 ((uint32)(6U))

        #define RTC_CTLR_HOUREN_MASK_U32             ((uint32)(BIT5))
        #define RTC_CTLR_HOUREN_SHIFT                ((uint32)(5U))

        #define RTC_CTLR_MINEN_MASK_U32              ((uint32)(BIT4))
        #define RTC_CTLR_MINEN_SHIFT                 ((uint32)(4U))

        #define RTC_CTLR_SECEN_MASK_U32              ((uint32)(BIT3))
        #define RTC_CTLR_SECEN_SHIFT                 ((uint32)(3U))

        #define RTC_CTLR_SSECEN_MASK_U32             ((uint32)(BIT2))
        #define RTC_CTLR_SSECEN_SHIFT                ((uint32)(2U))

        /**@}*/


        /**
        * @{
        * @brief Bit mask for RTC Status Register
        */
        #define RTC_STATUS_INVAL_ANL_WR_MASK_U32           ((uint32)(BIT18))
        #define RTC_STATUS_INVAL_ANL_WR_SHIFT              ((uint32)(18U))

        #define RTC_STATUS_INVAL_WKP_WR_MASK_U32           ((uint32)(BIT17))
        #define RTC_STATUS_INVAL_WKP_WR_SHIFT              ((uint32)(17U))

        #define RTC_STATUS_INVAL_API_WR_MASK_U32           ((uint32)(BIT16))
        #define RTC_STATUS_INVAL_API_WR_SHIFT              ((uint32)(16U))

        #define RTC_STATUS_APIF_MASK_U32                   ((uint32)(BIT15))
        #define RTC_STATUS_APIF_MASK_SHIFT                 ((uint32)(15U))

        #define RTC_STATUS_WKPF_MASK_U32                   ((uint32)(BIT7))
        #define RTC_STATUS_WKPF_SHIFT                      ((uint32)(7U))

        #define RTC_STATUS_DAYF_MASK_U32                   ((uint32)(BIT6))
        #define RTC_STATUS_DAYF_SHIFT                      ((uint32)(6U))

        #define RTC_STATUS_HOURF_MASK_U32                  ((uint32)(BIT5))
        #define RTC_STATUS_HOURF_SHIFT                     ((uint32)(5U))

        #define RTC_STATUS_MINF_MASK_U32                   ((uint32)(BIT4))
        #define RTC_STATUS_MINF_SHIFT                      ((uint32)(4U))

        #define RTC_STATUS_SECF_MASK_U32                   ((uint32)(BIT3))
        #define RTC_STATUS_SECF_SHIFT                      ((uint32)(3U))

        #define RTC_STATUS_SSECF_MASK_U32                  ((uint32)(BIT2))
        #define RTC_STATUS_SSECF_SHIFT                     ((uint32)(2U))

        /**@}*/

        /**
        * @{
        * @brief Bit mask for RTC Correction Value Register 
        */
        #define RTC_COR_VAL_SCVAL_MASK_U32          ((uint32)(BIT24|BIT23|BIT22|BIT21|BIT20|BIT19|BIT18|BIT17|BIT16|BIT15|BIT14|BIT13|BIT12|\
                                                                 BIT11|BIT10|BIT9|BIT8|BIT7|BIT6|BIT5|BIT4|BIT3|BIT2|BIT1|BIT0))

        #define RTC_COR_VAL_SCVAL_SHIFT             ((uint32)0U)


        /**
        * @{
        * @brief Bit mask for RTC Time of Day Register
        */
        #define RTC_TOD_SEC_CNT_MAKS_U32            ((uint32)(BIT21|BIT20|BIT19|BIT18|BIT17|BIT16))
        #define RTC_TOD_SEC_CNT_SHIFT               ((uint32)(16U))

        #define RTC_TOD_MIN_CNT_MAKS_U32            ((uint32)(BIT13|BIT12|BIT11|BIT10|BIT9|BIT8))
        #define RTC_TOD_MIN_CNT_SHIFT               ((uint32)(8U))

        #define RTC_TOD_HOUR_CNT_MAKS_U32           ((uint32)(BIT4|BIT3|BIT2|BIT1|BIT0))
        #define RTC_TOD_HOUR_CNT_SHIFT              ((uint32)(0U))

        /**
        * @{
        * @brief Bit offset for RTC APIVAL register
        */
        #define RTC_APIVAL_MASK_U32     ((uint32)0xFFFFFFFFUL)
        
    #endif
#endif
/**
* @brief Highest possible value for RTC API Value
*/
#define RTC_API_RTCC_APIVAL_MAX_VALUE_U32                ((uint32)0x000003FFUL)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define GPT_START_SEC_CODE
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#define GPT_STOP_SEC_CODE
/* @violates @ref REG_ESYS_RTC_H_REF_1 MISRA 2004 Advisory Rule 19.15, Repeated include file MemMap.h */
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /*REG_ESYS_RTC_H*/

/**@}*/
