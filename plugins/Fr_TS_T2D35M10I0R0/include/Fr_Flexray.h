/**
*   @file    Fr_Flexray.h
*   @implements Fr_Flexray.h_Artifact
* 
*   @version 1.0.0
*
*   @brief   AUTOSAR Fr - FlexRay LLD Module interface file..
*   @details Contains all types and function prototypes required by FlexRay LLD driver.
*
*   @addtogroup [MODULE_SECTION]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : FLEXRAY
*   Dependencies         : 
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
#ifndef FR_FLEXRAY_H
#define FR_FLEXRAY_H

#ifdef __cplusplus
extern "C"{
#endif
/***************************************************************************************************
* MISRA violations
***************************************************************************************************/

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section FR_FLEXRAY_H_REF_1
* Violates MISRA 2004 Required Rule 19.15, #include "Fr_MemMap.h" is not preceded only by
* preprocessor directives and appears not only in the beginning of file because it otherwise
* would not work.
*
* @section FR_FLEXRAY_H_REF_2
* Violates MISRA 2004 Required Rule 5.1, Identifier is specified by the FSL coding rule standard.
*
* @section FR_FLEXRAY_H_REF_4
* Violates MISRA 2004 Required Rule 1.4, The compiler - linker shall be checked to ensure that 31 
* character significance and case sensitivity are supported for external identifiers.
* Identifier is specified by ASR standard.
*
* @section FR_FLEXRAY_H_REF_5
* Violates MISRA 2004 Advisory Rule 19.1, Inclusion of "MemMap.h" is required here because of
* its functionality.
*/
/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#ifndef FR_H
  #include "Fr.h"
#endif
#include "SchM_Fr.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define FR_FLEXRAY_MODULE_ID                        81
#define FR_FLEXRAY_VENDOR_ID                        43
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION         4
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FR_FLEXRAY_AR_RELEASE_MINOR_VERSION         2
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FR_FLEXRAY_AR_RELEASE_REVISION_VERSION      2
#define FR_FLEXRAY_SW_MAJOR_VERSION                 1
#define FR_FLEXRAY_SW_MINOR_VERSION                 0
#define FR_FLEXRAY_SW_PATCH_VERSION                 0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Fr.h header file are of the same vendor */
#if(FR_FLEXRAY_VENDOR_ID != FR_FLEXRAY_VENDOR_ID)
    #error "Fr_Flexray.h and Fr.h have different Vendor IDs"
#endif
/* Check if current file and Fr.h header file are of the same Autosar version */
#if((FR_FLEXRAY_AR_RELEASE_MAJOR_VERSION    != FR_AR_RELEASE_MAJOR_VERSION) || \
    (FR_FLEXRAY_AR_RELEASE_MINOR_VERSION    != FR_AR_RELEASE_MINOR_VERSION) || \
    (FR_FLEXRAY_AR_RELEASE_REVISION_VERSION != FR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of Fr_Flexray.h and Fr.h are different"
#endif
/* Check if current file and Fr.h header file are of the same software version */
#if((FR_FLEXRAY_SW_MAJOR_VERSION != FR_SW_MAJOR_VERSION) || \
    (FR_FLEXRAY_SW_MINOR_VERSION != FR_SW_MINOR_VERSION) || \
    (FR_FLEXRAY_SW_PATCH_VERSION != FR_SW_PATCH_VERSION))
    #error "Software Version Numbers of Fr_Flexray.h and Fr.h are different"
#endif

/*==================================================================================================
*                                      DEFINES IP-VAULT VERSION
==================================================================================================*/
#ifdef IPV_FLEXRAY
/* Macro to determine the IP version */
/* FlexRay IP-Vault version 9 */
#define IPV_FLEXAY_03_00_01_18                                                 (0x03000118UL)
#endif /* IPV_FLEXRAY */

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/* Message buffer header size divided by 2 since memory access is 16-bit */
#ifdef IPV_FLEXRAY
#if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
    #define FLEXRAY_HEADER_SIZE                        ((uint8)5U)
    #define STATUS_SLOT                                ((uint8)4U)
#else
    #error "IP-Vault Version Numbers of Fr_Flexray.h and Soc_Ips.h are different"
#endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else
    #define FLEXRAY_HEADER_SIZE                        ((uint8)4U)
    #define STATUS_SLOT                                ((uint8)3U)
#endif /* IPV_FLEXRAY */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* FlexRay module/driver specific values */
/* FlexRay module register address offsets */
#define FLEXRAY_MCR_ADDR16                                                     ((uint16)0x0001U)
#define FLEXRAY_SYMBADHR_ADDR16                                                ((uint16)0x0002U)
#define FLEXRAY_SYMBADLR_ADDR16                                                ((uint16)0x0003U)
#define FLEXRAY_MVR_ADDR16                                                     ((uint16)0x0000U)
#define FLEXRAY_MBDSR_ADDR16                                                   ((uint16)0x0006U)
#define FLEXRAY_MBSSUTR_ADDR16                                                 ((uint16)0x0007U)
#define FLEXRAY_POCR_ADDR16                                                    ((uint16)0x000AU)
#define FLEXRAY_GIFER_ADDR16                                                   ((uint16)0x000BU)
#define FLEXRAY_PIFR0_ADDR16                                                   ((uint16)0x000CU)
#define FLEXRAY_PIFR1_ADDR16                                                   ((uint16)0x000DU)
#define FLEXRAY_PIER0_ADDR16                                                   ((uint16)0x000EU)
#define FLEXRAY_PIER1_ADDR16                                                   ((uint16)0x000FU)
#define FLEXRAY_CHIERFR_ADDR16                                                 ((uint16)0x0010U)
#define FLEXRAY_MBIVEC_ADDR16                                                  ((uint16)0x0011U)
#define FLEXRAY_PSR0_ADDR16                                                    ((uint16)0x0014U)
#define FLEXRAY_PSR1_ADDR16                                                    ((uint16)0x0015U)
#define FLEXRAY_PSR2_ADDR16                                                    ((uint16)0x0016U)
#define FLEXRAY_PSR3_ADDR16                                                    ((uint16)0x0017U)
#define FLEXRAY_MTCTR_ADDR16                                                   ((uint16)0x0018U)
#define FLEXRAY_CYCTR_ADDR16                                                   ((uint16)0x0019U)
#define FLEXRAY_RTCORVR_ADDR16                                                 ((uint16)0x001CU)
#define FLEXRAY_OFCORVR_ADDR16                                                 ((uint16)0x001DU)
#define FLEXRAY_SYMATOR_ADDR16                                                 ((uint16)0x001FU)
#define FLEXRAY_SFCNTR_ADDR16                                                  ((uint16)0x0020U)
#define FLEXRAY_SFTOR_ADDR16                                                   ((uint16)0x0021U)
#define FLEXRAY_SFTCCSR_ADDR16                                                 ((uint16)0x0022U)
#define FLEXRAY_NMVLR_ADDR16                                                   ((uint16)0x002CU)
#define FLEXRAY_TICCR_ADDR16                                                   ((uint16)0x002DU)
#define FLEXRAY_TI1CYSR_ADDR16                                                 ((uint16)0x002EU)
#define FLEXRAY_TI1MTOR_ADDR16                                                 ((uint16)0x002FU)
#define FLEXRAY_TI2CR0_ADDR16                                                  ((uint16)0x0030U)
#define FLEXRAY_TI2CR1_ADDR16                                                  ((uint16)0x0031U)
#define FLEXRAY_MTSACFR_ADDR16                                                 ((uint16)0x0040U)
#define FLEXRAY_MTSBCFR_ADDR16                                                 ((uint16)0x0041U)
#define FLEXRAY_RSBIR_ADDR16                                                   ((uint16)0x0042U)
#define FLEXRAY_RFWMSR_ADDR16                                                  ((uint16)0x0043U)
#define FLEXRAY_RFSIR_ADDR16                                                   ((uint16)0x0044U)
#define FLEXRAY_RFDSR_ADDR16                                                   ((uint16)0x0045U)
#define FLEXRAY_RFARIR_ADDR16                                                  ((uint16)0x0046U)
#define FLEXRAY_RFBRIR_ADDR16                                                  ((uint16)0x0047U)
#define FLEXRAY_RFMIDAFVR_ADDR16                                               ((uint16)0x0048U)
#define FLEXRAY_RFMIDAFMR_ADDR16                                               ((uint16)0x0049U)
#define FLEXRAY_RFFIDRFVR_ADDR16                                               ((uint16)0x004AU)
#define FLEXRAY_RFFIDRFMR_ADDR16                                               ((uint16)0x004BU)
#define FLEXRAY_RFRFCFR_ADDR16                                                 ((uint16)0x004CU)
#define FLEXRAY_RFRFCTR_ADDR16                                                 ((uint16)0x004DU)
#define FLEXRAY_PCR0_ADDR16                                                    ((uint16)0x0050U)
#define FLEXRAY_PCR1_ADDR16                                                    ((uint16)0x0051U)
#define FLEXRAY_PCR2_ADDR16                                                    ((uint16)0x0052U)
#define FLEXRAY_PCR3_ADDR16                                                    ((uint16)0x0053U)
#define FLEXRAY_PCR4_ADDR16                                                    ((uint16)0x0054U)
#define FLEXRAY_PCR5_ADDR16                                                    ((uint16)0x0055U)
#define FLEXRAY_PCR6_ADDR16                                                    ((uint16)0x0056U)
#define FLEXRAY_PCR7_ADDR16                                                    ((uint16)0x0057U)
#define FLEXRAY_PCR8_ADDR16                                                    ((uint16)0x0058U)
#define FLEXRAY_PCR9_ADDR16                                                    ((uint16)0x0059U)
#define FLEXRAY_PCR10_ADDR16                                                   ((uint16)0x005AU)
#define FLEXRAY_PCR11_ADDR16                                                   ((uint16)0x005BU)
#define FLEXRAY_PCR12_ADDR16                                                   ((uint16)0x005CU)
#define FLEXRAY_PCR13_ADDR16                                                   ((uint16)0x005DU)
#define FLEXRAY_PCR14_ADDR16                                                   ((uint16)0x005EU)
#define FLEXRAY_PCR15_ADDR16                                                   ((uint16)0x005FU)
#define FLEXRAY_PCR16_ADDR16                                                   ((uint16)0x0060U)
#define FLEXRAY_PCR17_ADDR16                                                   ((uint16)0x0061U)
#define FLEXRAY_PCR18_ADDR16                                                   ((uint16)0x0062U)
#define FLEXRAY_PCR19_ADDR16                                                   ((uint16)0x0063U)
#define FLEXRAY_PCR20_ADDR16                                                   ((uint16)0x0064U)
#define FLEXRAY_PCR21_ADDR16                                                   ((uint16)0x0065U)
#define FLEXRAY_PCR22_ADDR16                                                   ((uint16)0x0066U)
#define FLEXRAY_PCR23_ADDR16                                                   ((uint16)0x0067U)
#define FLEXRAY_PCR24_ADDR16                                                   ((uint16)0x0068U)
#define FLEXRAY_PCR25_ADDR16                                                   ((uint16)0x0069U)
#define FLEXRAY_PCR26_ADDR16                                                   ((uint16)0x006AU)
#define FLEXRAY_PCR27_ADDR16                                                   ((uint16)0x006BU)
#define FLEXRAY_PCR28_ADDR16                                                   ((uint16)0x006CU)
#define FLEXRAY_PCR29_ADDR16                                                   ((uint16)0x006DU)
#define FLEXRAY_PCR30_ADDR16                                                   ((uint16)0x006EU)
#define FLEXRAY_RFSDOR_ADDR16                                                  ((uint16)0x0073U)
#ifdef IPV_FLEXRAY
#if (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18)
#define FLEXRAY_MBCCSR0_ADDR16                                                 ((uint16)0x0080U)
#define FLEXRAY_MBCCFR0_ADDR16                                                 ((uint16)0x0081U)
#define FLEXRAY_MBFIDR0_ADDR16                                                 ((uint16)0x0082U)
#define FLEXRAY_MBIDXR0_ADDR16                                                 ((uint16)0x0083U)
#endif /* (IPV_FLEXRAY == IPV_FLEXAY_03_00_01_18) */
#else
#define FLEXRAY_MBCCSR0_ADDR16                                                 ((uint16)0x0400U)
#define FLEXRAY_MBCCFR0_ADDR16                                                 ((uint16)0x0401U)
#define FLEXRAY_MBFIDR0_ADDR16                                                 ((uint16)0x0402U)
#define FLEXRAY_MBIDXR0_ADDR16                                                 ((uint16)0x0403U)
#endif /* IPV_FLEXRAY */
#define FLEXRAY_MBDOR0_ADDR16                                                  ((uint16)0x0800U)
#if(FR_DEINIT_API == STD_ON)
#define FLEXRAY_STBSCR_ADDR16                                                   ((uint16)0x0004U)
#define FLEXRAY_PEDRDR_ADDR16                                                   ((uint16)0x0009U)
#define FLEXRAY_SFIDAFVR_ADDR16                                                 ((uint16)0x0024U)
#define FLEXRAY_SFIDAFMR_ADDR16                                                 ((uint16)0x0025U)
#define FLEXRAY_SSSR_ADDR16                                                     ((uint16)0x0032U)
#define FLEXRAY_SSCCR_ADDR16                                                    ((uint16)0x0033U)
#define FLEXRAY_RFPTR_ADDR16                                                    ((uint16)0x0076U)
#define FLEXRAY_RFFLPCR_ADDR16                                                  ((uint16)0x0077U)
#define FLEXRAY_EERICR_ADDR16                                                   ((uint16)0x0079U)
#define FLEXRAY_EEIAR_ADDR16                                                    ((uint16)0x007DU)
#define FLEXRAY_EEIDR_ADDR16                                                    ((uint16)0x007EU)
#define FLEXRAY_EEICR_ADDR16                                                    ((uint16)0x007FU)
#define FLEXRAY_EEIFER_ADDR16                                                   ((uint16)0x0078U)
#define FLEXRAY_RFSYMBADHR_ADDR16                                               ((uint16)0x0074U)
#define FLEXRAY_RFSYMBADLR_ADDR16                                               ((uint16)0x0075U)
#endif
#define FLEXRAY_NMVR0_8BIT                                              ((uint16)0x004CU) /* Address of NMVR0 reg. for 8-bit operations */
/* FlexRay module register bitfields and values */                      
/* FR_MCR bitfields */                                                  
#define FLEXRAY_MCR_MEN_U16                                             ((uint16)0x8000U)
#define FLEXRAY_MCR_SCM_U16                                             ((uint16)0x2000U)
#define FLEXRAY_MCR_CHB_U16                                             ((uint16)0x1000U)
#define FLEXRAY_MCR_CHA_U16                                             ((uint16)0x0800U)
#define FLEXRAY_MCR_SFFE_U16                                            ((uint16)0x0400U)
#define FLEXRAY_MCR_CLKSEL_U16                                          ((uint16)0x0010U)
#define FLEXRAY_MCR_BITRATE_MASK_U16                                    ((uint16)0x000EU)
/* FR_SYMBADHR bitfield*/
#define FLEXRAY_SYMBADLR_SMBA_MASK_U16                                  ((uint16)0xFFF0U)
/* FR_MBDSR bitfields */
#define FLEXRAY_MBDSR_MBSEG1DS_MASK_U16                                 ((uint16)0x007FU)
#define FLEXRAY_MBDSR_MBSEG2DS_MASK_U16                                 ((uint16)0x7F00U)
/* FR_MBSSUTR bitfields */
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_MBSSUTR_LAST_MB_UTIL_MASK_U16                           ((uint16)0x007FU)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_MBSSUTR_LAST_MB_SEG1_MASK_U16                           ((uint16)0x7F00U)
/* FR_POCR bitfields */                                                 
#define FLEXRAY_POCR_WME_U16                                            ((uint16)0x8000U)
#define FLEXRAY_POCR_BSY_U16                                            ((uint16)0x0080U)
#define FLEXRAY_POCR_WMC_U16                                            ((uint16)0x0080U)
/* FR_POCR EOC_AP values */                                             
#define FLEXRAY_POCR_EOC_ADD_U16                                            ((uint16)0x0C00U)
#define FLEXRAY_POCR_EOC_SUB_U16                                            ((uint16)0x0800U)
#define FLEXRAY_POCR_EOC_DONT_U16                                           ((uint16)0x0000U)
/* FR_POCR ERC_AP values */                                             
#define FLEXRAY_POCR_ERC_ADD_U16                                            ((uint16)0x0300U)
#define FLEXRAY_POCR_ERC_SUB_U16                                            ((uint16)0x0200U)
#define FLEXRAY_POCR_ERC_DONT_U16                                           ((uint16)0x0000U)
/* FR_POCR POCCMD commands */
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_POCR_CMDALLOWCOLDSTART_U16                                  ((uint16)0x0000U)
#define FLEXRAY_POCR_CMD_ALL_SLOTS_U16                                      ((uint16)0x0001U)
#define FLEXRAY_POCR_CMD_CONFIG_U16                                         ((uint16)0x0002U)
#define FLEXRAY_POCR_CMD_FREEZE_U16                                         ((uint16)0x0003U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_POCR_CMDCONFIGCOMPLETE_U16                                  ((uint16)0x0004U)
#define FLEXRAY_POCR_CMD_RUN_U16                                            ((uint16)0x0005U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_POCR_CMD_DEFAULTCONFIG_U16                                  ((uint16)0x0006U)
#define FLEXRAY_POCR_CMD_HALT_U16                                           ((uint16)0x0007U)
#define FLEXRAY_POCR_CMD_WAKEUP_U16                                         ((uint16)0x0008U)
/* FR_GIFER bitfields */                                                
#define FLEXRAY_GIFER_PRIE_U16                                          ((uint16)0x0040U)
#define FLEXRAY_GIFER_TBIF_U16                                          ((uint16)0x0100U)
#define FLEXRAY_GIFER_RBIF_U16                                          ((uint16)0x0200U)
#define FLEXRAY_GIFER_FNEAIF_U16                                        ((uint16)0x0400U)
#define FLEXRAY_GIFER_FNEBIF_U16                                        ((uint16)0x0800U)
#define FLEXRAY_GIFER_WUPIF_U16                                         ((uint16)0x1000U)
#ifdef IPV_FLEXRAY
#ifdef FR_ACCESS_ERROR_NOTIFICATION_EN
#define FLEXRAY_GIFER_CHIE_U16                                          ((uint16)0x0020U)
#define FLEXRAY_GIFER_CHIF_U16                                          ((uint16)0x2000U)
#endif /* FR_ACCESS_ERROR_NOTIFICATION_EN */
#endif /* IPV_FLEXRAY */
/* @violates @ref FR_FLEXRAY_H_REF_2 */                                 
#define FLEXRAY_GIFER_INT_FLAGS_MASK_U16                                ((uint16)0xFF00U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */                                 
#define FLEXRAY_GIFER_CTRL_FLAGS_MASK_U16                               ((uint16)0x00FFU)
/* FR_PIFR0 bitfields */                                                
#define FLEXRAY_PIFR0_TI2_IF_U16                                        ((uint16)0x0004U)
#define FLEXRAY_PIFR0_TI1_IF_U16                                        ((uint16)0x0002U)
/* FR_PIER0 bitfields */                                                
#define FLEXRAY_PIER0_TI2_IE_U16                                        ((uint16)0x0004U)
#define FLEXRAY_PIER0_TI1_IE_U16                                        ((uint16)0x0002U)
/* FR_PSR0 bitfields */                                                 
#define FLEXRAY_PSR0_ERRMODE_MASK_U16                                   ((uint16)0xC000U)
#define FLEXRAY_PSR0_SLOTMODE_MASK_U16                                  ((uint16)0x3000U)
#define FLEXRAY_PSR0_PROTSTATE_MASK_U16                                 ((uint16)0x0700U)
#define FLEXRAY_PSR0_STARTUP_MASK_U16                                   ((uint16)0x00F0U)
#define FLEXRAY_PSR0_WUP_MASK_U16                                       ((uint16)0x0007U)
/* FR_PSR0 slot mode */
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_PSR0_SLOTMODE_SINGLE_U16                                    ((uint16)0x0000U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */                                 
#define FLEXRAY_PSR0_SLOTMODE_ALL_PENDING_U16                               ((uint16)0x1000U)
#define FLEXRAY_PSR0_SLOTMODE_ALL_U16                                       ((uint16)0x2000U)
/* FR_PSR0 error mode */                                                
#define FLEXRAY_PSR0_ERRMODE_ACTIVE_U16                                     ((uint16)0x0000U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_PSR0_ERRMODE_PASSIVE_U16                                    ((uint16)0x4000U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_PSR0_ERRMODE_COMM_HALT_U16                                  ((uint16)0x8000U)
/* FR_PSR0 protocol state */                                            
/* @violates @ref FR_FLEXRAY_H_REF_2 */                                            
#define FLEXRAY_PSR0_PROTSTATE_DEFAULT_CONFIG_U16                           ((uint16)0x0000U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_PSR0_PROTSTATE_CONFIG_U16                                   ((uint16)0x0100U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_PSR0_PROTSTATE_WAKEUP_U16                                   ((uint16)0x0200U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_PSR0_PROTSTATE_READY_U16                                    ((uint16)0x0300U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */                                 
#define FLEXRAY_PSR0_PROTSTATE_NORMAL_PASSIVE_U16                           ((uint16)0x0400U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */                                 
#define FLEXRAY_PSR0_PROTSTATE_NORMAL_ACTIVE_U16                            ((uint16)0x0500U)
#define FLEXRAY_PSR0_PROTSTATE_HALT_U16                                     ((uint16)0x0600U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_PSR0_PROTSTATE_STARTUP_U16                                  ((uint16)0x0700U)
/* FR_PSR0 startup state */
#define FLEXRAY_PSR0_STARTUP_CCR_U16                                        ((uint16)0x0020U)
#define FLEXRAY_PSR0_STARTUP_CL_U16                                         ((uint16)0x0030U)
#define FLEXRAY_PSR0_STARTUP_ICOC_U16                                       ((uint16)0x0040U)
#define FLEXRAY_PSR0_STARTUP_IL_U16                                         ((uint16)0x0050U)
#define FLEXRAY_PSR0_STARTUP_IS_U16                                         ((uint16)0x0070U)
#define FLEXRAY_PSR0_STARTUP_CCC_U16                                        ((uint16)0x00A0U)
#define FLEXRAY_PSR0_STARTUP_ICLC_U16                                       ((uint16)0x00D0U)
#define FLEXRAY_PSR0_STARTUP_CG_U16                                         ((uint16)0x00E0U)
#define FLEXRAY_PSR0_STARTUP_CJ_U16                                         ((uint16)0x00F0U)
/* FR_PSR0 wakeup status */                                             
#define FLEXRAY_PSR0_WUP_UD_U16                                             ((uint16)0x0000U)
#define FLEXRAY_PSR0_WUP_RH_U16                                             ((uint16)0x0001U)
#define FLEXRAY_PSR0_WUP_RW_U16                                             ((uint16)0x0002U)
#define FLEXRAY_PSR0_WUP_HC_U16                                             ((uint16)0x0003U)
#define FLEXRAY_PSR0_WUP_WC_U16                                             ((uint16)0x0004U)
#define FLEXRAY_PSR0_WUP_UC_U16                                             ((uint16)0x0005U)
#define FLEXRAY_PSR0_WUP_T_U16                                              ((uint16)0x0006U)
#define FLEXRAY_PSR0_WUP_RESERVED_U16                                       ((uint16)0x0007U)
/* FR_PSR1 bitfields */                                                 
#define FLEXRAY_PSR1_CPN_U16                                            ((uint16)0x0080U)
#define FLEXRAY_PSR1_HHR_U16                                            ((uint16)0x0040U)
#define FLEXRAY_PSR1_FRZ_U16                                            ((uint16)0x0020U)
/* FR_PSR2 bitfields */
#define FLEXRAY_PSR2_CHB_MASK_U16                                       ((uint16)0xFC00U)
#define FLEXRAY_PSR2_CHA_MASK_U16                                       ((uint16)0x03F0U)
/* FR_PSR3 bitfields */
#define FLEXRAY_PSR3_CHB_MASK_U16                                       ((uint16)0x1F00U)
#define FLEXRAY_PSR3_CHA_MASK_U16                                       ((uint16)0x001FU)
#define FLEXRAY_PSR3_WUB_U16                                            ((uint16)0x2000U)
#define FLEXRAY_PSR3_WUA_U16                                            ((uint16)0x0020U)
/* FR_SFTCCSR bitfields */                                              
#define FLEXRAY_SFTCCSR_SIDEN_U16                                       ((uint16)0x0001U)
#define FLEXRAY_SFTCCSR_ELKT_U16                                        ((uint16)0x8000U)
#define FLEXRAY_SFTCCSR_OLKT_U16                                        ((uint16)0x4000U)
#define FLEXRAY_SFTCCSR_ELKS_U16                                        ((uint16)0x0080U)
#define FLEXRAY_SFTCCSR_OLKS_U16                                        ((uint16)0x0040U)
#define FLEXRAY_SFTCCSR_EVAL_U16                                        ((uint16)0x0020U)
#define FLEXRAY_SFTCCSR_OVAL_U16                                        ((uint16)0x0010U)
/* FR_NMVLR bitfield */
#define FLEXRAY_NMVLR_MASK_U16                                          ((uint16)0x000FU)
/* FR_TICCR bitfields */                                                
#define FLEXRAY_TICCR_T2SP_U16                                          ((uint16)0x0400U)
#define FLEXRAY_TICCR_T2TR_U16                                          ((uint16)0x0200U)
#define FLEXRAY_TICCR_T1SP_U16                                          ((uint16)0x0004U)
#define FLEXRAY_TICCR_T1TR_U16                                          ((uint16)0x0002U)
#define FLEXRAY_TICCR_CONFIG_MASK_U16                                   ((uint16)0x3010U)
/* FR_TI1CYSR bitfield */                                               
#define FLEXRAY_TI1CYSR_T1_CYC_MSK_U16                                  ((uint16)0x003FU)
/* FR_RSBIR selector values */                                          
#define FLEXRAY_RSBIR_SEL_RSBIR_A1_U16                                  0x0000U
#define FLEXRAY_RSBIR_SEL_RSBIR_A2_U16                                  ((uint16)0x1000U)
#define FLEXRAY_RSBIR_SEL_RSBIR_B1_U16                                  ((uint16)0x2000U)
#define FLEXRAY_RSBIR_SEL_RSBIR_B2_U16                                  ((uint16)0x3000U)
/* FR_RFWMSR selector value */                                          
#define FLEXRAY_RFWMSR_SEL_U16                                          ((uint16)0x0001U)
/* FR_RFSIR bitfield */
#define FLEXRAY_RFSIR_SIDX_MASK_U16                                     ((uint16)0x03FFU)
/* FR_RFDSR bitfields */
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_RFDSR_ENTRY_SIZE_MASK_U16                               ((uint16)0x007FU)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_RFDSR_FIFO_DEPTH_MASK_U16                               ((uint16)0xFF00U)
/* FR_RFRFCFR selector values */                                        
#define FLEXRAY_RFRFCFR_IBD_LOWINT_U16                                  0x0000U
#define FLEXRAY_RFRFCFR_IBD_UPPINT_U16                                  ((uint16)0x4000U)
#define FLEXRAY_RFRFCFR_SEL_F0_U16                                      ((uint16)0x0000U)/* range filter 0 */
#define FLEXRAY_RFRFCFR_SEL_F1_U16                                      ((uint16)0x1000U)/* range filter 1 */
#define FLEXRAY_RFRFCFR_SEL_F2_U16                                      ((uint16)0x2000U)/* range filter 2 */
#define FLEXRAY_RFRFCFR_SEL_F3_U16                                      ((uint16)0x3000U)/* range filter 3 */
/* FR_RFRFCFR bitfield */
#define FLEXRAY_RFRFCFR_SID_MASK_U16                                    ((uint16)0x07FFU)
/* RFRFCTR range control bits */                                        
#define FLEXRAY_RFRFCTR_F3MD_U16                                        ((uint16)0x0800U)
#define FLEXRAY_RFRFCTR_F2MD_U16                                        ((uint16)0x0400U)
#define FLEXRAY_RFRFCTR_F1MD_U16                                        ((uint16)0x0200U)
#define FLEXRAY_RFRFCTR_F0MD_U16                                        ((uint16)0x0100U)
#define FLEXRAY_RFRFCTR_F3EN_U16                                        ((uint16)0x0008U)
#define FLEXRAY_RFRFCTR_F2EN_U16                                        ((uint16)0x0004U)
#define FLEXRAY_RFRFCTR_F1EN_U16                                        ((uint16)0x0002U)
#define FLEXRAY_RFRFCTR_F0EN_U16                                        ((uint16)0x0001U)
/* FR_PCR10 bitfield */                                                 
#define FLEXRAY_PCR10_WUP_CH_U16                                        ((uint16)0x4000U)
/* FR_MBCCSR bitfields */                                               
#define FLEXRAY_MBCCSR0_CONFIG_MASK_U16                                 ((uint16)0x7900U)
#define FLEXRAY_MBCCSR_MTD_U16                                          ((uint16)0x1000U)
#define FLEXRAY_MBCCSR_CMT_U16                                          ((uint16)0x0800U)
#define FLEXRAY_MBCCSR_EDT_U16                                          ((uint16)0x0400U)
#define FLEXRAY_MBCCSR_LCKT_U16                                         ((uint16)0x0200U)
#define FLEXRAY_MBCCSR_MBIE_U16                                         ((uint16)0x0100U)
#define FLEXRAY_MBCCSR_DUP_U16                                          ((uint16)0x0010U)
#define FLEXRAY_MBCCSR_EDS_U16                                          ((uint16)0x0004U)
#define FLEXRAY_MBCCSR_LCKS_U16                                         ((uint16)0x0002U)
#define FLEXRAY_MBCCSR_MBIF_U16                                         ((uint16)0x0001U)
/* FR_MBCCFR bitfields */                                               
#define FLEXRAY_MBCCFR_CHA_U16                                          ((uint16)0x4000U)
#define FLEXRAY_MBCCFR_CHB_U16                                          ((uint16)0x2000U)
#define FLEXRAY_MBCCFR_CCFE_U16                                         ((uint16)0x1000U)
#define FLEXRAY_MBCCFR_CCFVAL_MASK_U16                                  ((uint16)0x003FU)
#define FLEXRAY_MBCCFR_CCFMSK_MASK_U16                                  ((uint16)0x0FC0U)
/* FR_MBFIDR bitfields */
#define FLEXRAY_MBFIDR_FID_MASK_U16                                     ((uint16)0x07FFU)
                                                                        
#define FLEXRAY_FRAMEHEADER0_PPI_U16                                    ((uint16)0x4000U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */                                 
#define FLEXRAY_FRAMEHEADER1_PLDLENMASK_U16                             ((uint16)0x007FU)

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
/*FR 16-bit registers mask */
#define FLEXRAY_REGISTER_MASK_HIGH_U32                                  ((uint32)0xFFFF0000U)
#define FLEXRAY_REGISTER_MASK_LOW_U32                                   ((uint32)0x0000FFFFU)
#define FLEXRAY_REGISTER_OFFSET_U8                                      ((uint8)16U)

/*FR payload data field mask */
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U32                              ((uint32)0x00FF00FF00U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
#define FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U32                               ((uint32)0x0000FF00FFU)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
/* @violates @ref FR_FLEXRAY_H_REF_4 */
#define FLEXRAY_EVEN_PAYLOAD_BYTE_MASK_U16                              ((uint16)0xFF00U)
/* @violates @ref FR_FLEXRAY_H_REF_2 */
/* @violates @ref FR_FLEXRAY_H_REF_4 */
#define FLEXRAY_ODD_PAYLOAD_BYTE_MASK_U16                               ((uint16)0x00FFU)
#define FLEXRAY_PAYLOAD_BYTE_OFFSET_U32                                 ((uint32)8U)
#endif

#if(FR_DEINIT_API == STD_ON)
#define FLEXRAY_RESET_VAL_U16                                                ((uint16)0x0000U)
#define FLEXRAY_RESET_VAL_1_U16                                              ((uint16)0x0001U)
#define FLEXRAY_EERICR_BSY_U16                                               ((uint16)0x8000U)
#define FLEXRAY_MBSSUTR_RESET_VAL_U16                                        ((uint16)0xFFFFU)
#define FLEXRAY_GIFER_RESET_VAL_U16                                          ((uint16)0x1C00U)
#define FLEXRAY_PIFR0_RESET_VAL_U16                                          ((uint16)0xFFFFU)
#define FLEXRAY_PIFR1_RESET_VAL_U16                                          ((uint16)0xFF30U)
#define FLEXRAY_PSR1_RESET_VAL_U16                                           ((uint16)0x8000U)
#define FLEXRAY_PSR3_RESET_VAL_U16                                           ((uint16)0x3F3FU)
#define FLEXRAY_EEIFER_RESET_VAL_U16                                         ((uint16)0xFF00U)
#define FLEXRAY_CHIERFR_RESET_VAL_U16                                        ((uint16)0xFFFFU)
#define FLEXRAY_SYMATOR_RESET_VAL_U16                                        ((uint16)0x0006U)
#define FLEXRAY_NUMBER_PCR_U8                                                ((uint8)0x0001FU)
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define FR_START_SEC_CODE
/* @violates @ref FR_FLEXRAY_H_REF_1 */
#include "Fr_MemMap.h"

FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_CCInit(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_EnterPOCConfigState(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(void, FR_CODE) Fr_Flexray_ClusterNodeParamCfg(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_BuffersInit(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_ClearDisableIRQs(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_LeavePOCConfigState(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_InvokeCHICommand(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) chiCommand);
FUNC(void, FR_CODE) Fr_Flexray_AckAbsTimerIRQ(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(void, FR_CODE) Fr_Flexray_CancelAbsTimer(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(void, FR_CODE) Fr_Flexray_DisableAbsTimerIRQ(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(boolean, FR_CODE) Fr_Flexray_GetAbsTimerIRQStatus(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(void, FR_CODE) Fr_Flexray_SetAbsTimer(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx, VAR(uint8, AUTOMATIC) cycle, VAR(uint16, AUTOMATIC) offset);
FUNC(void, FR_CODE) Fr_Flexray_EnableAbsTimerIRQ(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) timerIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_SetWakeupChannel(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(Fr_ChannelType, AUTOMATIC) chnlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetGlobalTime(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) cyclePtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) macroTickPtr);
FUNC(uint16, FR_CODE) Fr_Flexray_GetPOCState(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetPOCStatus(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(Fr_POCStatusType, AUTOMATIC, FR_APPL_DATA) pocStatusPtr);
FUNC(void, FR_CODE) Fr_Flexray_DisableTimers(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetNmVector(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) nmVectorPtr, P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) hwErr);
FUNC(void, FR_CODE) Fr_Flexray_GetChannelStatus(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAStatusPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBStatusPtr);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetClockCorrection(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(sint16, AUTOMATIC, FR_APPL_DATA) rateCorrectionPtr, P2VAR(sint32, AUTOMATIC, FR_APPL_DATA) offsetCorrectionPtr);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetSyncFrameList(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint8, AUTOMATIC) listSize,
                                                          P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAEvenListPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBEvenListPtr,
                                                          P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelAOddListPtr, P2VAR(uint16, AUTOMATIC, FR_APPL_DATA) channelBOddListPtr
                                                         );
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetWakeupRxStatus(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) wakeupRxStatusPtr); 
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_ReadbackCCConfig(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_TransmitTxLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lpduIdx, P2CONST(uint8, AUTOMATIC, FR_APPL_CONST) lsduPtr, VAR(uint8, AUTOMATIC) lsduLength);

FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_ReceiveRxLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lpduIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr, 
                                                       P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
                                                      );
FUNC(void, FR_CODE) Fr_Flexray_ReceiveFifoA(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lpduIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr, 
                                                       P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
                                                      );
FUNC(void, FR_CODE) Fr_Flexray_ReceiveFifoB(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lpduIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduPtr, 
                                                       P2VAR(Fr_RxLPduStatusType, AUTOMATIC, FR_APPL_DATA) lpduStatusPtr, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) lsduLengthPtr
                                                      );
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_CheckTxLPduStatus(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx, P2VAR(Fr_TxLPduStatusType, AUTOMATIC, FR_APPL_DATA) txLPduStatusPtr);
#if(FR_PREPARE_LPDU_SUPPORT == STD_ON)
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_PrepareLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx);
#endif
#if(FR_RECONFIG_LPDU_SUPPORT == STD_ON)
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_ReconfigLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx, VAR(uint16, AUTOMATIC) frameId, VAR(Fr_ChannelType, AUTOMATIC) chnlIdx,
                                                      VAR(uint8, AUTOMATIC) cycleRepetition, VAR(uint8, AUTOMATIC) cycleOffset, VAR(uint8, AUTOMATIC) payloadLength, VAR(uint16, AUTOMATIC) headerCRC
                                                     );
#endif
#if(FR_DISABLE_LPDU_SUPPORT == STD_ON)
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_DisableLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx);
#endif
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_CancelTxLPdu(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) lPduIdx, P2VAR(boolean, AUTOMATIC, FR_APPL_DATA) pendingStatusPtr);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_GetNumOfStartFrames(VAR(uint8, AUTOMATIC) ctrlIdx, P2VAR(uint8, AUTOMATIC, FR_APPL_DATA) numOfStartupFramesPtr);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_CheckCCAccess(VAR(uint8, AUTOMATIC) ctrlIdx, CONST(boolean, AUTOMATIC) Fr_CC_enabled, CONST(uint16, AUTOMATIC) regMVR);
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_WaitForPOCState(VAR(uint8, AUTOMATIC) ctrlIdx, CONST(uint16, AUTOMATIC) pocState);
#ifdef IPV_FLEXRAY
#ifdef FR_ACCESS_ERROR_NOTIFICATION_EN
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_EnableErrorIRQs(VAR(uint8, AUTOMATIC) ctrlIdx);
FUNC(void, FR_CODE) Fr_Flexray_WriteValueRegister(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) RegisterAdress, VAR(uint16, AUTOMATIC) RegisterValue);
FUNC(uint16, FR_CODE) Fr_Flexray_ReadValueRegister(VAR(uint8, AUTOMATIC) ctrlIdx, VAR(uint16, AUTOMATIC) RegisterAdress);
#endif /* FR_ACCESS_ERROR_NOTIFICATION_EN */
#endif /* IPV_FLEXRAY */
#if(FR_DEINIT_API == STD_ON)
FUNC(Std_ReturnType, FR_CODE) Fr_Flexray_DeInit(VAR(uint8, AUTOMATIC) u8CtrlIdx);
#endif

#define FR_STOP_SEC_CODE
/* @violates @ref FR_FLEXRAY_H_REF_1 */
#include "Fr_MemMap.h"

#ifdef __cplusplus
}
#endif

#endif /* FR_FLEXRAY_H */
/* End of file */
