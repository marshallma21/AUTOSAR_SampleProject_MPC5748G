/**
*   @file Reg_eSys_Siul2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Port - SIUL2 low level driver register defines.
*   @details The description of the registers of the SIUL2 module.
*
*   @addtogroup Siul2
*   @{
*/
/*=================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : SIUL2
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
=================================================================================================*/
/*=================================================================================================
=================================================================================================*/

#ifndef REG_ESYS_SIUL2_H
#define REG_ESYS_SIUL2_H
#ifdef __cplusplus
extern "C"{
#endif
/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Reg_eSys_Siul2_H_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined
* This violation is due to function like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers(internal and external) shall not rely 
* on the significance of more than 31 characters.The used compilers use more than 31 chars
* for identifiers.
*/

/*=================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
=================================================================================================*/

#include "Siul2_IpVersion.h"

/*=================================================================================================
*                              SOURCE FILE VERSION INFORMATION
=================================================================================================*/

#define REGESYS_SIUL2_VENDOR_ID                    43
#define REGESYS_SIUL2_AR_RELEASE_MAJOR_VERSION     4
#define REGESYS_SIUL2_AR_RELEASE_MINOR_VERSION     2
#define REGESYS_SIUL2_AR_RELEASE_REVISION_VERSION  2
#define REGESYS_SIUL2_SW_MAJOR_VERSION             1
#define REGESYS_SIUL2_SW_MINOR_VERSION             0
#define REGESYS_SIUL2_SW_PATCH_VERSION             0

/*=================================================================================================
*                                     FILE VERSION CHECKS
=================================================================================================*/

/* Check if the files Reg_eSys_Siul2.h and Siul2_IpVersion.h are of the same vendor */
#if (REGESYS_SIUL2_VENDOR_ID != SIUL2_IPVERSION_VENDOR_ID_REG)
    #error "Reg_eSys_Siul2.h and Siul2_IpVersion.h have different vendor ids"
#endif
/* Check if the files Reg_eSys_Siul2.h and Siul2_IpVersion.h are of the same Autosar version */
#if ((REGESYS_SIUL2_AR_RELEASE_MAJOR_VERSION    != SIUL2_IPVERSION_AR_RELEASE_MAJOR_VERSION_REG) || \
     (REGESYS_SIUL2_AR_RELEASE_MINOR_VERSION    != SIUL2_IPVERSION_AR_RELEASE_MINOR_VERSION_REG) || \
     (REGESYS_SIUL2_AR_RELEASE_REVISION_VERSION != SIUL2_IPVERSION_AR_RELEASE_REVISION_VERSION_REG) \
    )
  #error "AutoSar Version Numbers of Reg_eSys_Siul2.h and Siul2_IpVersion.h are different"
#endif
/* Check if the files Reg_eSys_Siul2.h and Siul2_IpVersion.h are of the same software version */
#if ((REGESYS_SIUL2_SW_MAJOR_VERSION != SIUL2_IPVERSION_SW_MAJOR_VERSION_REG) || \
     (REGESYS_SIUL2_SW_MINOR_VERSION != SIUL2_IPVERSION_SW_MINOR_VERSION_REG) || \
     (REGESYS_SIUL2_SW_PATCH_VERSION != SIUL2_IPVERSION_SW_PATCH_VERSION_REG)    \
    )
  #error "Software Version Numbers of Reg_eSys_Siul2.h and Siul2_IpVersion.h are different"
#endif

/*=================================================================================================
*                                          CONSTANTS
=================================================================================================*/


/*=================================================================================================
*                                       DEFINES AND MACROS
=================================================================================================*/

/*
* @brief Multiplexed Signal Configuration Register address for a specific pin defined.
*/
/** @violates @ref Reg_eSys_Siul2_H_REF_1 Function-like macro */
#define SIUL2_MSCR_ADDR32(PIN)  ((uint32)SIUL2_BASEADDR + (uint32)0x0240UL + (uint32)((PIN)<<2))

/* @brief define the mask used to write the IMCR registers. This is because for some platforms, the reserved
bits in the IMCR register do not have the reset value equal to zero */
#ifdef IPV_SIULV2
    #if (IPV_SIULV2_00_01_00_71 == IPV_SIULV2)
        /* For McKinley, the reserved bits are not having the reset value equal to 0b0 */
        #define SIUL2_IMCR_RESET_MASK_U32  ((uint32)0x00890000)
    #else
        #define SIUL2_IMCR_RESET_MASK_U32  ((uint32)0x00000000)
    #endif
#endif

/* @brief Mask definitions for MSCR bit field OERC or SRC */
#ifdef IPV_SIULV2
    #if (IPV_SIULV2_00_01_03_63 == IPV_SIULV2) && (defined(IPV_SIUL2_ODC_SUPPORT_U8))
        #define SIUL2_MSCR_OERC_U32                         (0x70000000UL)
        #define SIUL2_MSCR_OERC_OFFSET_U32                  ((uint32)28)
        #define SIUL2_MSCR_OERC_WEAK_DRIVE_U32              ((uint32)0x00000000U)
        #define SIUL2_MSCR_OERC_MEDIUM_DRIVE_U32            ((uint32)0x10000000U)
        #define SIUL2_MSCR_OERC_STRONG_DRIVE_U32            ((uint32)0x20000000U)
        #define SIUL2_MSCR_OERC_VERY_STRONG_DRIVE_U32       ((uint32)0x30000000U)
        #define SIUL2_MSCR_OERC_6PF_U32                     ((uint32)0x40000000U)
        #define SIUL2_MSCR_OERC_12PF_U32                    ((uint32)0x50000000U)
        #define SIUL2_MSCR_OERC_18PF_U32                    ((uint32)0x60000000U)
        #define SIUL2_MSCR_OERC_30PF_U32                    ((uint32)0x70000000U)
    #elif (IPV_SIULV2_00_01_03_61 == IPV_SIULV2) || (IPV_SIULV2_00_01_00_71 == IPV_SIULV2) 
        #define SIUL2_MSCR_OERC_U32                         (0x30000000UL)
        #define SIUL2_MSCR_OERC_OFFSET_U32                  ((uint32)28)
        #define SIUL2_MSCR_OERC_WEAK_DRIVE_U32              ((uint32)0x00000000U)
        #define SIUL2_MSCR_OERC_MEDIUM_DRIVE_U32            ((uint32)0x10000000U)
        #define SIUL2_MSCR_OERC_STRONG_DRIVE_U32            ((uint32)0x20000000U)
        #define SIUL2_MSCR_OERC_VERY_STRONG_DRIVE_U32       ((uint32)0x30000000U)
    #elif !defined (IPV_SIUL2_DDR_SUPPORT_U8)
        #define SIUL2_MSCR_SRC_U32                          (0x30000000UL)
        #define SIUL2_MSCR_SRC_OFFSET_U32                   ((uint32)28)
        #define SIUL2_MSCR_SRC_HALF_WITH_SLEW_RATE_U32      ((uint32)0x00000000U)
        #define SIUL2_MSCR_SRC_FULL_WITH_SLEW_RATE_U32      ((uint32)0x10000000U)
        #define SIUL2_MSCR_SRC_HALF_WITHOUT_SLEW_RATE_U32   ((uint32)0x20000000U)
        #define SIUL2_MSCR_SRC_FULL_WITHOUT_SLEW_RATE_U32   ((uint32)0x30000000U)
    #endif
#endif

/* @brief Mask definitions for MSCR bit field ODC or OBE and ODE */
#ifdef IPV_SIULV2
    #if (((IPV_SIULV2_00_01_03_63 == IPV_SIULV2) && defined(IPV_SIUL2_ODC_SUPPORT_U8)) || \
          (IPV_SIULV2_00_01_00_71 == IPV_SIULV2)                                          \
        )
        #define SIUL2_MSCR_ODC_U32                          (0x07000000UL)
        #define SIUL2_MSCR_ODC_OFFSET_U32                   ((uint32)24)
        #define SIUL2_MSCR_ODC_OUTPUT_BUFFER_DISABLED_U32   ((uint32)0x00000000U)
        #define SIUL2_MSCR_ODC_OPEN_DRAIN_U32               ((uint32)0x01000000U)
        #define SIUL2_MSCR_ODC_PUSH_PULL_U32                ((uint32)0x02000000U)
        #define SIUL2_MSCR_ODC_OPEN_SOURCE_U32              ((uint32)0x03000000U)
        #define SIUL2_MSCR_ODC_MICRO_LVDS_U32               ((uint32)0x04000000U)
        #define SIUL2_MSCR_ODC_LFAST_LVDS_U32               ((uint32)0x05000000U)
    #elif (IPV_SIULV2_00_01_03_61 == IPV_SIULV2)
        #define SIUL2_MSCR_ODC_U32                          (0x03000000UL)
        #define SIUL2_MSCR_ODC_OFFSET_U32                   ((uint32)24)
        #define SIUL2_MSCR_ODC_OUTPUT_BUFFER_DISABLED_U32   ((uint32)0x00000000U)
        #define SIUL2_MSCR_ODC_OPEN_DRAIN_U32               ((uint32)0x01000000U)
        #define SIUL2_MSCR_ODC_PUSH_PULL_U32                ((uint32)0x02000000U)
        #define SIUL2_MSCR_ODC_OPEN_SOURCE_U32              ((uint32)0x03000000U)
    #else
        #if defined (IPV_SIUL2_DDR_SUPPORT_U8)
            #define SIUL2_MSCR_OBE_U32                          (0x00200000UL)
            #define SIUL2_MSCR_OBE_OFFSET_U32                   ((uint32)21)
            #define SIUL2_MSCR_OBE_OFF_U32                      ((uint32)0x00000000U)
            #define SIUL2_MSCR_OBE_ON_U32                       ((uint32)0x00200000U)

            #define SIUL2_MSCR_ODE_U32                          (0x00100000UL)
            #define SIUL2_MSCR_ODE_OFFSET_U32                   ((uint32)20)
            #define SIUL2_MSCR_ODE_OFF_U32                      ((uint32)0x00000000U)
            #define SIUL2_MSCR_ODE_ON_U32                       ((uint32)0x00100000U)
        #else
            #define SIUL2_MSCR_OBE_U32                          (0x02000000UL)
            #define SIUL2_MSCR_OBE_OFFSET_U32                   ((uint32)25)
            #define SIUL2_MSCR_OBE_OFF_U32                      ((uint32)0x00000000U)
            #define SIUL2_MSCR_OBE_ON_U32                       ((uint32)0x02000000U)

            #define SIUL2_MSCR_ODE_U32                          (0x01000000UL)
            #define SIUL2_MSCR_ODE_OFFSET_U32                   ((uint32)24)
            #define SIUL2_MSCR_ODE_OFF_U32                      ((uint32)0x00000000U)
            #define SIUL2_MSCR_ODE_ON_U32                       ((uint32)0x01000000U)
        #endif
    #endif
#endif

/* @brief Mask definitions for MSCR bit field SMC */
#ifdef IPV_SIULV2
    #if defined (IPV_SIUL2_DDR_SUPPORT_U8)
        #define SIUL2_MSCR_SMC_U32                              (0x00000020UL)
        #define SIUL2_MSCR_SMC_OFFSET_U32                       ((uint32)5)
        #define SIUL2_MSCR_SMC_ON_U32                           ((uint32)0x00000020U)
        #define SIUL2_MSCR_SMC_OFF_U32                          ((uint32)0x00000000U)
    #else
        #define SIUL2_MSCR_SMC_U32                              (0x00800000UL)
        #define SIUL2_MSCR_SMC_OFFSET_U32                       ((uint32)23)
        #define SIUL2_MSCR_SMC_ON_U32                           ((uint32)0x00800000U)
        #define SIUL2_MSCR_SMC_OFF_U32                          ((uint32)0x00000000U)
    #endif
#endif    

/* @brief Mask definitions for MSCR bit field APC, IBE and HYS */
#define SIUL2_MSCR_APC_U32                              (0x00400000UL)
#define SIUL2_MSCR_APC_OFFSET_U32                       ((uint32)22)
#define SIUL2_MSCR_APC_ON_U32                           ((uint32)0x00400000U)
#define SIUL2_MSCR_APC_OFF_U32                          ((uint32)0x00000000U)


#define SIUL2_MSCR_IBE_U32                              (0x00080000UL)
#define SIUL2_MSCR_IBE_OFFSET_U32                       ((uint32)19)
#define SIUL2_MSCR_IBE_ON_U32                           ((uint32)0x00080000U)
#define SIUL2_MSCR_IBE_OFF_U32                          ((uint32)0x00000000U)

#define SIUL2_MSCR_HYS_U32                              (0x00040000UL)
#define SIUL2_MSCR_HYS_OFFSET_U32                       ((uint32)18)
#define SIUL2_MSCR_HYS_ON_U32                           ((uint32)0x00040000U)
#define SIUL2_MSCR_HYS_OFF_U32                          ((uint32)0x00000000U)


/* @brief Mask definitions for MSCR bit field ILS and TTL */
#if defined (IPV_SIUL2_ODC_SUPPORT_U8)
    #define SIUL2_MSCR_ILS_U32                              (0x00300000UL)
    #define SIUL2_MSCR_ILS_OFFSET_U32                       ((uint32)20)
    #define SIUL2_MSCR_ILS_AUTO_U32                         ((uint32)0x00000000U)
    #define SIUL2_MSCR_ILS_TTL_U32                          ((uint32)0x00100000U)
    #define SIUL2_MSCR_ILS_LVDS_U32                         ((uint32)0x00200000U)
    #define SIUL2_MSCR_ILS_CMOS_U32                         ((uint32)0x00300000U)
#elif !defined (IPV_SIUL2_DDR_SUPPORT_U8)
    #define SIUL2_MSCR_TTL_U32                              (0x00100000UL)
    #define SIUL2_MSCR_TTL_OFFSET_U32                       ((uint32)20)
    #define SIUL2_MSCR_TTL_ON_U32                           ((uint32)0x00100000U)
    #define SIUL2_MSCR_TTL_OFF_U32                          ((uint32)0x00000000U)
#endif
    
/* @brief Mask definitions for MSCR bit field PUS, PUE or WPDE, WPUE */
#ifdef IPV_SIULV2
    #if (((IPV_SIULV2_00_01_03_63 == IPV_SIULV2) && defined(IPV_SIUL2_ODC_SUPPORT_U8)) || \
          (IPV_SIULV2_00_01_00_71 == IPV_SIULV2) || \
          (IPV_SIULV2_00_01_03_61 == IPV_SIULV2)    \
        )
        #define SIUL2_MSCR_WPDE_U32                         (0x00020000UL)
        #define SIUL2_MSCR_WPDE_OFFSET_U32                  ((uint32)17)
        #define SIUL2_MSCR_WPDE_ON_U32                      ((uint32)0x00020000U)
        #define SIUL2_MSCR_WPDE_OFF_U32                     ((uint32)0x00000000U)

        #define SIUL2_MSCR_WPUE_U32                         (0x00010000UL)
        #define SIUL2_MSCR_WPUE_OFFSET_U32                  ((uint32)16)
        #define SIUL2_MSCR_WPUE_ON_U32                      ((uint32)0x00010000U)
        #define SIUL2_MSCR_WPUE_OFF_U32                     ((uint32)0x00000000U)
    #elif defined(IPV_SIUL2_DDR_SUPPORT_U8)   
        #define SIUL2_MSCR_PUS_U32                          (0x00001800UL)
        #define SIUL2_MSCR_PUS_OFFSET_U32                   ((uint32)11)
        #define SIUL2_MSCR_PUS_ON_U32                       ((uint32)0x00001800U)
        #define SIUL2_MSCR_PUS_OFF_U32                      ((uint32)0x00000000U)

        #define SIUL2_MSCR_PUE_U32                          (0x00002000UL)
        #define SIUL2_MSCR_PUE_OFFSET_U32                   ((uint32)13)
        #define SIUL2_MSCR_PUE_ON_U32                       ((uint32)0x00002000U)
        #define SIUL2_MSCR_PUE_OFF_U32                      ((uint32)0x00000000U)

        #define SIUL2_MSCR_PKE_U32                          (0x00010000UL)
        #define SIUL2_MSCR_PKE_OFFSET_U32                   ((uint32)16)
        #define SIUL2_MSCR_PKE_ON_U32                       ((uint32)0x00010000U)
        #define SIUL2_MSCR_PKE_OFF_U32                      ((uint32)0x00000000U)
    #else
        #define SIUL2_MSCR_PUS_U32                          (0x00020000UL)
        #define SIUL2_MSCR_PUS_OFFSET_U32                   ((uint32)17)
        #define SIUL2_MSCR_PUS_ON_U32                       ((uint32)0x00020000U)
        #define SIUL2_MSCR_PUS_OFF_U32                      ((uint32)0x00000000U)

        #define SIUL2_MSCR_PUE_U32                          (0x00010000UL)
        #define SIUL2_MSCR_PUE_OFFSET_U32                   ((uint32)16)
        #define SIUL2_MSCR_PUE_ON_U32                       ((uint32)0x00010000U)
        #define SIUL2_MSCR_PUE_OFF_U32                      ((uint32)0x00000000U)
    #endif
#endif

/* @brief Mask definitions for MSCR bit field INV */
#ifdef IPV_SIULV2
    #if (!((IPV_SIULV2_00_01_03_63 == IPV_SIULV2) && (!defined(IPV_SIUL2_ODC_SUPPORT_U8))))
        #define SIUL2_MSCR_INV_U32                          (0x00008000UL)
        #define SIUL2_MSCR_INV_OFFSET_U32                   ((uint32)15)
        #define SIUL2_MSCR_INV_ON_U32                       ((uint32)0x00008000U)
        #define SIUL2_MSCR_INV_OFF_U32                      ((uint32)0x00000000U)
    #endif
#endif

/* @brief Mask definitions for MSCR bit field SSS */
#ifdef IPV_SIULV2
    #if (((IPV_SIULV2_00_01_03_63 == IPV_SIULV2) && defined(IPV_SIUL2_ODC_SUPPORT_U8)) || \
          (IPV_SIULV2_00_01_00_71 == IPV_SIULV2)                                          \
        )
        #define SIUL2_MSCR_SSS_U32                          (0x000000FFUL)
        #define SIUL2_MSCR_SSS_OFFSET_U32                   ((uint32)0)
    #else
        #define SIUL2_MSCR_SSS_U32                          (0x0000000FUL)
        #define SIUL2_MSCR_SSS_OFFSET_U32                   ((uint32)0)
    #endif
#endif

/*
* @brief Multiplexed Signal Configuration for Multiplexed Inputs address for a specific pin
*/
/** @violates @ref Reg_eSys_Siul2_H_REF_1 Function-like macro defined. */
#ifdef IPV_SIULV2
    #if ((IPV_SIULV2_00_01_03_63 == IPV_SIULV2) || (IPV_SIULV2_00_01_00_71 == IPV_SIULV2) || (IPV_SIULV2_00_01_03_61 == IPV_SIULV2))
        /** @violates @ref Reg_eSys_Siul2_H_REF_1 Function-like macro defined.*/
        #define SIUL2_MSCR_INP_ADDR32(PIN)  ((uint32)SIUL2_BASEADDR + (uint32)0x0A40UL + (uint32)(((PIN) - 512UL)<<2))
    #else
        /** @violates @ref Reg_eSys_Siul2_H_REF_1 Function-like macro defined.*/
        #define SIUL2_MSCR_INP_ADDR32(PIN)  ((uint32)SIUL2_BASEADDR + (uint32)0x0A40UL + (uint32)((PIN)<<2))
    #endif
#endif

/** @violates @ref Reg_eSys_Siul2_H_REF_1 Function-like macro defined.*/
#define SIUL2_IMCR_ADDR32(PIN)  ((uint32)SIUL2_BASEADDR + (uint32)0x0A40UL + (uint32)((PIN)<<2))

/* @brief Multiplexed Signal Selection for puts bits and masks */
#ifdef IPV_SIULV2
    #if (IPV_SIULV2 != IPV_SIULV2_00_01_03_61)
        #define SIUL2_IMCR_INV_U32                              (0x00008000UL)
    #endif
#endif

#ifdef IPV_SIULV2
    #if ((IPV_SIULV2_00_01_03_63 == IPV_SIULV2) || (IPV_SIULV2_00_01_00_71 == IPV_SIULV2) || (IPV_SIULV2_00_01_03_61 == IPV_SIULV2))
        #define SIUL2_IMCR_SSS_U32                      (0x000000FFUL)
    #else
        #define SIUL2_IMCR_SSS_U32                      (0x0000000FUL)
    #endif
#endif

/* @brief IMCR bit offset */
#define SIUL2_IMCR_SSS_OFFSET_U32                       ((uint32)0)

/*
* @brief GPIO Pad Data Output Register address
*/
#if (LOW_BYTE_FIRST == CPU_BYTE_ORDER)
    /* On ARM platforms, endianess is LOW_BYTE_FIRST. Need to revert the GPDO register order */
    /** @violates @ref Reg_eSys_Siul2_H_REF_1 Function-like macro defined.*/
    #define SIUL2_GPDO_ADDR8(PIN)  (SIUL2_BASEADDR + (uint32)0x1300UL + (((PIN) & ~3UL) | (~((PIN) & 3UL) & 3UL)))
#else
    /** @violates @ref Reg_eSys_Siul2_H_REF_1 Function-like macro defined.*/
    #define SIUL2_GPDO_ADDR8(PIN)  (SIUL2_BASEADDR + (uint32)0x1300UL + (PIN))
#endif
    

/* @brief Mode bit offset mask */
#define SIUL2_BIT_OFFSET_MASK_U8       ((uint8)0x0F)

/*=================================================================================================
*                                             ENUMS
=================================================================================================*/


/*=================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
=================================================================================================*/


/*=================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
=================================================================================================*/


/*=================================================================================================
*                                    FUNCTION PROTOTYPES
=================================================================================================*/

#ifdef __cplusplus
}
#endif
/* PORT_REG_ESYS_SIUL2_H */
#endif
/** @} */
