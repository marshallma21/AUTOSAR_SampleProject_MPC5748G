/**
*   @file    Soc_Ips.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Base - IP module versions.
*   @details The IP modules versions used on PA hardware platform and
*            IP specific defines
*
*   @addtogroup BASE_COMPONENT
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : MPC574XG
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

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Soc_Ips_h_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely on the
* significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 20.2, The names of standard library macros, objects and functions
* shall not be reused. The driver needs to use defines starting with letter E.
*/

#ifndef SOC_IPS_H
#define SOC_IPS_H

#ifdef __cplusplus
extern "C"{
#endif


/*==================================================================================================
*                                         INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file        Soc_Ips.h
* @brief Include platform types
* @violates @ref Soc_Ips_h_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
*/
#include "Platform_Types.h"

/*==================================================================================================
*                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define SOC_IPS_VENDOR_ID                    43
#define SOC_IPS_MODULE_ID                    0
#define SOC_IPS_AR_RELEASE_MAJOR_VERSION     4
#define SOC_IPS_AR_RELEASE_MINOR_VERSION     2
#define SOC_IPS_AR_RELEASE_REVISION_VERSION  2
#define SOC_IPS_SW_MAJOR_VERSION             1
#define SOC_IPS_SW_MINOR_VERSION             0
#define SOC_IPS_SW_PATCH_VERSION             0

/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if source file and Platform_Types.h header file are of the same Autosar version */
    #if ((SOC_IPS_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION) || \
         (SOC_IPS_AR_RELEASE_MINOR_VERSION != PLATFORM_AR_RELEASE_MINOR_VERSION))
        #error "AutoSar Version Numbers of Soc_Ips.h and Platform_Types.h are different"
    #endif
#endif


/*==================================================================================================
*                                           CONSTANTS
==================================================================================================*/
/**
* @brief STCU IP Version: STA1_STCU2_IPS@v1.0.a_0.01
* @details MPC574XG IP Versions
*/
#define IPV_STCU2             (0x01006101UL)

/**
* @brief FLASHv2 IP Version: FLASHv2 V_MS_c55fmc_039
* @details MPC574XG IP Versions
*/
#define IPV_FLASHV2          (0x62725539UL)

/**
* @brief LINFLEX IP Version: LINFLEX3_IPS v5.4.h
* @details MPC574XG IP Version
*/
#define IPV_LINFLEX             (0x00050468UL)

/**
* @brief LINFLEX IP Version: FLEXCAN3 d_ip_flexcan3_syn.03.00.11.00
* @details MPC574XG IP Version
*/
#define IPV_FLEXCAN             (0x03001100UL)

/**
* @brief SIUL2 IP Version: SIUL2 v1.3.c
* @details MPC574XG IP Versions
*/
#define IPV_SIULV2             (0x00010363UL)
/**
* @brief WKUP IP Version: WKPU.01.00.14.01
* @details MPC574XG IP Versions
*/
#define IPV_WKUP                 (0x01001401UL)

/**
* @brief ADCDIG IP Version: D_IP_ADC_12b1MSPS_SAR_c55fg_SYN [R00.00.04.09]
* @details MPC574XG IP Versions
*/
#define IPV_ADCDIG              (0x00000409UL)
/**
* @brief BCTU IP Version: BCTU_01.00.08.00 
* @details MPC574XG IP Versions
*/
#define IPV_BCTU                 (0x01000800UL)

/**
* @brief MC IP Version: MC v05.00.00.07
* @details MPC574XG IP Versions
*/
#define IPV_MC                  (0x05000007UL)

/**
* @brief PLLDIG IP Version: PLLDIG v02.00.04.23
* @details MPC574XG IP Versions
*/
#define IPV_PLLDIG               (0x02000423UL)

/**
* @brief XOSC IP Version: OSCDIG v01.00.09.00
* @details MPC574XG IP Versions
*/
#define IPV_FXOSC                 (0x01000900UL)

/**
* @brief PIT_RTI IP Version: PIT_RTI v05.00.06.09
* @details MPC574XG IP Versions
*/
#define IPV_PIT                 (0x05000609UL)

/**
* @brief RTC IP Version: RTC v00.00.03.03
* @details MPC574XG IP Versions
*/
#define IPV_RTC                 (0x00000303UL)

/**
* @brief DMA IP Version: DMA v02.02.02.14
* @details MPC574XG IP Versions
*/
#define IPV_DMA               (0x02020214UL)

/**
* @brief DMAMUX IP Version: DMAMUX v06.01.04.00
* @details MPC574XG IP Versions
*/
#define IPV_DMAMUX               (0x06010400UL)

/**
* @brief DSPI IP Version: DSPI v06.03.04.02
* @details MPC574XG IP Versions
*/
#define IPV_DSPI                 (0x06030402UL)

/**
* @brief SSCM IP Version: SSCM v06.00.00.04
* @details MPC574XG IP Versions
*/
#define IPV_SSCM                 (0x06000004UL)

/**
* @brief PMC IP Version: PMC.00.01.04.43
* @details MPC574XG IP Versions
*/
#define IPV_PMC                 (0x00010443UL)


/**
* @brief Number of STM modules
* @details MPC574XG Platform Defines/Configurations
*/
#define STM_NB_MODULES           (0x03U)

/**
* @brief EMIOS interrupts are handled by common ISRs
* @details MPC574XG Platform specific Defines/Configurations for EMIOS
*/
#define EMIOS_COMMON_ISR_HANDLER     (STD_ON)
/**
* @brief EMIOS UCDIS register is available
* @details MPC574XG Platform specific Defines/Configurations for EMIOS
*/
#define EMIOS_UCDIS_AVAILABLE        (STD_ON)


/*==================================================================================================
*                              Software Erratas for Hardware Erratas
==================================================================================================*/
/**
* @brief Hardware errata for FlexRAY: (e8770)
* @details FlexRAY: e8770: Missing TX frames on Channel B when in dual channel mode and Channel A is disabled ( Initial revision ) 
*/
#define ERR_IPV_FLEXRAY_0005         (STD_ON)

/**
* @brief Hardware errata for EMIOS (e9978)
* @details EMIOS: e9978: EMIOS: Unexpected channel flag asserion during GPIO to MCB mode transition
*/ 
#define ERR_IPV_EMIOS_0001          (STD_ON)

/**
* @brief Hardware errata for FLEXCAN (e10368)
* @details FLEXCAN: e10368: FLEXCAN:  Transition of the CAN FD operation enable bit may lead FlexCAN
* logic to an inconsistent state.
*/ 
#define ERR_IPV_FLEXCAN_0016        (STD_ON)

/**
* @brief Hardware errata for IPV_MCV4 (ERR009139)
* @details MCV4: ERR009139:   256k SRAM retention across standby mode
*/ 
#define ERR_IPV_MC_0050        (STD_ON)

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/**
* @brief User Mode feature is enabled
* @details User Mode feature is enabled
*/

#ifndef MCAL_ENABLE_SUPERVISOR_MODE /* command line parameter */
    #define MCAL_ENABLE_USER_MODE_SUPPORT /* global user mode support define */
#endif
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif


#endif /* #ifndef SOC_IPS_H*/

/** @} */
