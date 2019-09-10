/**
*   @file    Reg_eSys_LINFlex.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Lin - LINFlex Registers and Macros Definitions.
*   @details Header file for LINFlex Registers and Macros Definitions.
*
*   @addtogroup LIN
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : LINFlex
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

#ifndef REG_ESYS_LINFLEX_H
#define REG_ESYS_LINFLEX_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Reg_eSys_LINFlex_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7, This violation is due to function
* like macros defined for register operations.
* Function like macros are used to reduce code complexity.
*
* @section Reg_eSys_LINFlex_h_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Reg_eSys_LINFlex_h_REF_3
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @violates @ref Reg_eSys_LINFlex_h_REF_3 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
#include "Reg_eSys.h" /* Reg_eSys.h is included in Mcal.h also*/
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_LINFlex.h
*/
#define LIN_VENDOR_ID_REGFLEX                    43
#define LIN_AR_RELEASE_MAJOR_VERSION_REGFLEX     4
#define LIN_AR_RELEASE_MINOR_VERSION_REGFLEX     2
/*
* @violates @ref Reg_eSys_LINFlex_h_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_REGFLEX  2
#define LIN_SW_MAJOR_VERSION_REGFLEX             1
#define LIN_SW_MINOR_VERSION_REGFLEX             0
#define LIN_SW_PATCH_VERSION_REGFLEX             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and Reg_eSys header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_REGFLEX != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_REGFLEX != REG_ESYS_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Lin_NonASR.c and Reg_eSys.h are different"
  #endif

#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define LIN_START_SEC_CONST_32
/**
* @violates @ref Reg_eSys_LINFlex_h_REF_3 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
extern CONST(uint32, LIN_CONST) Linflex_au32BaseAddrs[18];

#define LIN_STOP_SEC_CONST_32
/**
* @violates @ref Reg_eSys_LINFlex_h_REF_3 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/

/**
* @brief    IPV_LINFLEX macro definition.
* @details  Generic define for LINFLEX2 IP class.
*/
#define IPV_LINFLEX_00_10_00  (0x00001000UL)

/**
* @brief    IPV_LINFLEX macro definition.
* @details  Generic define for LINFLEX3 IP class.
*/
#define IPV_LINFLEX_03_00_00  (0x00030000UL)

#define IPV_LINFLEX_04_00_00  (0x00040000UL)

/**
* @brief    IPV_LINFLEX macro definition.
* @details  Specific define for LINFLEX3_IPS v5.4.h
*/
#define IPV_LINFLEX_05_04_68  (0x00050468UL)

/* sveral settings of the low level driver depends on the LINFlex IP hw version                   */
/* IPV_LINFLEX_00_10_00 - Spectrum/Bolero implementation                                          */
/* IPV_LINFLEX_03_00_00 - Leopard implementation                                                  */
/* IPV_LINFLEX_xx_xx_xx - ....                                                                    */
/*                                                                                                */
/* IPV_LINFLEX shall be defined in Reg_eSys.h file with the appropriate value                     */
/* because this convention started with Leopard and in order to keep the backward compatibility   */
/* the following 3 lines defines the default value for IPV_LINFLEX                                */
/* the only rule you need to follow is to include Reg_eSys.h before Reg_eSys_LINFlex.h in any     */
/* c source file                                                                                  */
#ifndef IPV_LINFLEX
    #error "IPV_LINFLEX not defined"
#endif

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access base addresses of LINFlex IPs.
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LIN_GET_BASE_ADDRESS(offset) ((uint32)( Linflex_au32BaseAddrs[(offset)] ))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Control Register 1 (LINCR1).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINCR1_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x00uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Interrupt Enable Register (LINIER).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINIER_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x04uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Status Register (LINSR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINSR_ADDR32(offset)     ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x08uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Error Status Register (LINESR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINESR_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x0CuL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register UART Mode Control Register (UARTCR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_UARTCR_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x10uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register UART Mode Status Register (UARTSR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_UARTSR_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x14uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Time-Out Control Status Register (LINTCSR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINTCSR_ADDR32(offset)   ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x18uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Output Compare Register (LINOCR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINOCR_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x1CuL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Time-Out Control Register (LINTOCR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINTOCR_ADDR32(offset)   ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x20uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Fractional Baud Rate Register (LINFBRR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINFBRR_ADDR32(offset)   ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x24uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Integer Baud Rate Register (LINIBRR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINIBRR_ADDR32(offset)   ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x28uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Checksum Field Register (LINCFR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINCFR_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x2CuL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register LIN Control Register 2 (LINCR2).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_LINCR2_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x30uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register Buffer Identifier Register (BIDR).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_BIDR_ADDR32(offset)      ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x34uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register Buffer Data Register Least Significant (BDRL).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_BDRL_ADDR32(offset)      ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x38uL))

/**
* @brief    LINFLEX Registers macro definition.
* @details  LINFLEX macro to access register Buffer Data Register Most Significant (BDRM).
* @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
*/
#define LINFLEX_BDRM_ADDR32(offset)      ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x3CuL))


/*=============== additional registers for LINFlex3 IP ================================*/
#if IPV_LINFLEX >= IPV_LINFLEX_03_00_00

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register Global control register (GCR).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_GCR_ADDR32(offset)       ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x8CuL))

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register UART preset timeout register (UARTPTO).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_UARTPTO_ADDR32(offset)   ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x90uL))

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register UART current timeout register (UARTCTO).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_UARTCTO_ADDR32(offset)   ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x94uL))

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register DMA Tx enable register (DMATXE).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_DMATXE_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x98uL))

    /**
    * @brief    LINFLEX Registers macro definition.
    * @details  LINFLEX macro to access register DMA Rx enable register (DMARXE).
    * @violates @ref Reg_eSys_LINFlex_h_REF_1 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    */
    #define LINFLEX_DMARXE_ADDR32(offset)    ((uint32)((uint32)( Linflex_au32BaseAddrs[(offset)] ) + 0x9CuL))

#endif
/*=============== end additional registers for LINFlex3 IP ============================*/

/**
* @brief    LINFLEX Registers bits.
* @details  LINCR1 register bit masks.
*/
#define LINFLEX_LINCR1_INIT_MASK_U32          ((uint32)0x00000001UL)
#define LINFLEX_LINCR1_SLEEP_MASK_U32         ((uint32)0x00000002UL)
#define LINFLEX_LINCR1_RBLM_MASK_U32          ((uint32)0x00000004UL)
#define LINFLEX_LINCR1_SSBL_MASK_U32          ((uint32)0x00000008UL)
#define LINFLEX_LINCR1_MME_MASK_U32           ((uint32)0x00000010UL)
#define LINFLEX_LINCR1_LBKM_MASK_U32          ((uint32)0x00000020UL)
#define LINFLEX_LINCR1_SFTM_MASK_U32          ((uint32)0x00000040UL)
#define LINFLEX_LINCR1_BF_MASK_U32            ((uint32)0x00000080UL)
#define LINFLEX_LINCR1_MBL_MASK_U32           ((uint32)0x00000F00UL)
#define LINFLEX_LINCR1_AWUM_MASK_U32          ((uint32)0x00001000UL)
#define LINFLEX_LINCR1_LASE_MASK_U32          ((uint32)0x00002000UL)
#define LINFLEX_LINCR1_CFD_MASK_U32           ((uint32)0x00004000UL)
#define LINFLEX_LINCR1_CCD_MASK_U32           ((uint32)0x00008000UL)
#define LINFLEX_LINCR1_RESET_MASK_U32         ((uint32)0x00000083UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LIN master break length selection register bit masks.
*/
#define LINFLEX_LINCR1_MBL_10_BITS_MASK_U32   ((uint32)0x00000000UL)
#define LINFLEX_LINCR1_MBL_11_BITS_MASK_U32   ((uint32)0x00000100UL)
#define LINFLEX_LINCR1_MBL_12_BITS_MASK_U32   ((uint32)0x00000200UL)
#define LINFLEX_LINCR1_MBL_13_BITS_MASK_U32   ((uint32)0x00000300UL)
#define LINFLEX_LINCR1_MBL_14_BITS_MASK_U32   ((uint32)0x00000400UL)
#define LINFLEX_LINCR1_MBL_15_BITS_MASK_U32   ((uint32)0x00000500UL)
#define LINFLEX_LINCR1_MBL_16_BITS_MASK_U32   ((uint32)0x00000600UL)
#define LINFLEX_LINCR1_MBL_17_BITS_MASK_U32   ((uint32)0x00000700UL)
#define LINFLEX_LINCR1_MBL_18_BITS_MASK_U32   ((uint32)0x00000800UL)
#define LINFLEX_LINCR1_MBL_19_BITS_MASK_U32   ((uint32)0x00000900UL)
#define LINFLEX_LINCR1_MBL_20_BITS_MASK_U32   ((uint32)0x00000A00UL)
#define LINFLEX_LINCR1_MBL_21_BITS_MASK_U32   ((uint32)0x00000B00UL)
#define LINFLEX_LINCR1_MBL_22_BITS_MASK_U32   ((uint32)0x00000C00UL)
#define LINFLEX_LINCR1_MBL_23_BITS_MASK_U32   ((uint32)0x00000D00UL)
#define LINFLEX_LINCR1_MBL_36_BITS_MASK_U32   ((uint32)0x00000E00UL)
#define LINFLEX_LINCR1_MBL_50_BITS_MASK_U32   ((uint32)0x00000F00UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINIER register bit masks.
*/
#define LINFLEX_LINIER_HRIE_MASK_U32   ((uint32)0x00000001UL)
#define LINFLEX_LINIER_DTIE_MASK_U32   ((uint32)0x00000002UL)
#define LINFLEX_LINIER_DRIE_MASK_U32   ((uint32)0x00000004UL)
#define LINFLEX_LINIER_DBEIE_MASK_U32  ((uint32)0x00000008UL)
#define LINFLEX_LINIER_DBFIE_MASK_U32  ((uint32)0x00000010UL)
#define LINFLEX_LINIER_WUIE_MASK_U32   ((uint32)0x00000020UL)
#define LINFLEX_LINIER_LSIE_MASK_U32   ((uint32)0x00000040UL)
#define LINFLEX_LINIER_BOIE_MASK_U32   ((uint32)0x00000080UL)
#define LINFLEX_LINIER_FEIE_MASK_U32   ((uint32)0x00000100UL)
#define LINFLEX_LINIER_HEIE_MASK_U32   ((uint32)0x00000800UL)
#define LINFLEX_LINIER_CEIE_MASK_U32   ((uint32)0x00001000UL)
#define LINFLEX_LINIER_BEIE_MASK_U32   ((uint32)0x00002000UL)
#define LINFLEX_LINIER_OCIE_MASK_U32   ((uint32)0x00004000UL)
#define LINFLEX_LINIER_SZIE_MASK_U32   ((uint32)0x00008000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINSR register bit masks.
*/
#define LINFLEX_LINSR_HRF_MASK_U32     ((uint32)0x00000001UL)
#define LINFLEX_LINSR_DTF_MASK_U32     ((uint32)0x00000002UL)
#define LINFLEX_LINSR_DRF_MASK_U32     ((uint32)0x00000004UL)
#define LINFLEX_LINSR_DBEF_MASK_U32    ((uint32)0x00000008UL)
#define LINFLEX_LINSR_DBFF_MASK_U32    ((uint32)0x00000010UL)
#define LINFLEX_LINSR_WUF_MASK_U32     ((uint32)0x00000020UL)
#define LINFLEX_LINSR_RPS_MASK_U32     ((uint32)0x00000040UL)
#define LINFLEX_LINSR_RBSY_MASK_U32    ((uint32)0x00000080UL)
#define LINFLEX_LINSR_RMB_MASK_U32     ((uint32)0x00000200UL)
#define LINFLEX_LINSR_LINS_MASK_U32    ((uint32)0x0000F000UL)
#define LINFLEX_LINSR_FLAGS_MASK_U32   ((uint32)0x0000033FUL)

/**
* @brief    LINFLEX LIN states.
* @details  Sleep mode: LINFlex is in Sleep mode to save power consumption.
*
*/
#define LINFLEX_LINSR_SLEEP_MODE_U8          ((uint8)0x00U)

/**
* @brief    LINFLEX LIN states.
* @details  Initialization mode: LINFlex is in Initialization mode.
*
*/
#define LINFLEX_LINSR_INIT_MODE_U8           ((uint8)0x01U)

/**
* @brief    LINFLEX LIN states.
* @details  Idle mode: This state is entered on several events:
*                - SLEEP bit and INIT in LINCR1 register have been cleared by software
*                - A falling edge has been received on RX pin and AWUM bit is set
*                - The previous frame reception or transmission has been completed or aborted.
*
*/
#define LINFLEX_LINSR_IDLE_MODE_U8           ((uint8)0x02U)

/**
* @brief    LINFLEX LIN states.
* @details  Break transmission ongoing.
*
*/
#define LINFLEX_LINSR_BREAK_TX_MODE_U8       ((uint8)0x03U)

/**
* @brief    LINFLEX LIN states.
* @details  Break transmission has been completed.Break Delimiter transmission is ongoing.
*
*/
#define LINFLEX_LINSR_BREAK_DEL_TX_MODE_U8   ((uint8)0x04U)

/**
* @brief    LINFLEX LIN states.
* @details  Synch Field transmission is ongoing.
*
*/
#define LINFLEX_LINSR_SYNC_FIELD_TX_MODE_U8  ((uint8)0x05U)

/**
* @brief    LINFLEX LIN states.
* @details  Identifier transmission is ongoing.
*
*/
#define LINFLEX_LINSR_ID_FIELD_TX_MODE_U8    ((uint8)0x06U)

/**
* @brief    LINFLEX LIN states.
* @details  Header transmission is completed.
*
*/
#define LINFLEX_LINSR_HEADER_TX_MODE_U8      ((uint8)0x07U)

/**
* @brief    LINFLEX LIN states.
* @details  Response reception/transmission is ongoing.
*
*/
#define LINFLEX_LINSR_DATA_RX_TX_MODE_U8     ((uint8)0x08U)

/**
* @brief    LINFLEX LIN states.
* @details  Data reception/transmission completed. Checksum RX/TX ongoing.
*
*/
#define LINFLEX_LINSR_CHECKSUM_RX_TX_MODE_U8 ((uint8)0x09U)

/**
* @brief    LINFLEX LIN states.
* @details  Reset LIN State Interrupt (generated on LIN state change).
*
*/
#define LINFLEX_LINSR_RESET_LSIE_MODE_U8     ((uint8)0x0FU)

/**
* @brief    LINFLEX Registers bits.
* @details  LINESR register bit masks.
*/
#define LINFLEX_LINESR_NF_MASK_U32     ((uint32)0x00000001UL)
#define LINFLEX_LINESR_BOF_MASK_U32    ((uint32)0x00000080UL)
#define LINFLEX_LINESR_FEF_MASK_U32    ((uint32)0x00000100UL)
#define LINFLEX_LINESR_IDPEF_MASK_U32  ((uint32)0x00000200UL)
#define LINFLEX_LINESR_BDEF_MASK_U32   ((uint32)0x00000400UL)
#define LINFLEX_LINESR_SFEF_MASK_U32   ((uint32)0x00000800UL)
#define LINFLEX_LINESR_CEF_MASK_U32    ((uint32)0x00001000UL)
#define LINFLEX_LINESR_BEF_MASK_U32    ((uint32)0x00002000UL)
#define LINFLEX_LINESR_OCF_MASK_U32    ((uint32)0x00004000UL)
#define LINFLEX_LINESR_SZF_MASK_U32    ((uint32)0x00008000UL)
#define LINFLEX_LINESR_FLAGS_MASK_U32  ((uint32)0x0000FF81UL)

/**
* @brief    LINFLEX Registers bits.
* @details  UARTCR register bit masks.
*/
#define LINFLEX_UARTCR_UART_MASK_U32   ((uint32)0x00000001UL)
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_UARTCR_WL_MASK_U32  ((uint32)0x00000002UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTCR_WL0_MASK_U32 ((uint32)0x00000002UL)
#endif
#define LINFLEX_UARTCR_PCE_MASK_U32    ((uint32)0x00000004UL)
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_UARTCR_OP_MASK_U32 ((uint32)0x00000008UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTCR_PC_U32     ((uint32)0x00000008UL)
#endif
#define LINFLEX_UARTCR_TXEN_MASK_U32   ((uint32)0x00000010UL)
#define LINFLEX_UARTCR_RXEN_MASK_U32   ((uint32)0x00000020UL)
#if IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTCR_PC1_U32     ((uint32)0x00000040UL)
#endif
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_UARTCR_RDFL_MASK_U32   ((uint32)0x00000C00UL)
    #define LINFLEX_UARTCR_TDFL_MASK_U32   ((uint32)0x00006000UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTCR_WL1_MASK_U32     ((uint32)0x00000080UL)
    #define LINFLEX_UARTCR_TFBM_MASK_U32    ((uint32)0x00000100UL)
    #define LINFLEX_UARTCR_RFBM_MASK_U32    ((uint32)0x00000200UL)
    #define LINFLEX_UARTCR_RDFLRFC_MASK_U32 ((uint32)0x00001C00UL)
    #define LINFLEX_UARTCR_TDFLTFC_MASK_U32 ((uint32)0x0000E000UL)
#endif

/**
* @brief    UART mode.
* @details  Receiver Data Field length selection.
*/
#define LINFLEX_UARTCR_RX_BUFF_SIZE_1_BYTES_MASK_U32   ((uint32)0x00000000UL)
#define LINFLEX_UARTCR_RX_BUFF_SIZE_2_BYTES_MASK_U32   ((uint32)0x00000400UL)
#define LINFLEX_UARTCR_RX_BUFF_SIZE_3_BYTES_MASK_U32   ((uint32)0x00000800UL)
#define LINFLEX_UARTCR_RX_BUFF_SIZE_4_BYTES_MASK_U32   ((uint32)0x00000C00UL)

/**
* @brief    UART mode.
* @details  Transmitter Data Field length selection.
*/
#define LINFLEX_UARTCR_TX_BUFF_SIZE_1_BYTES_MASK_U32   ((uint32)0x00000000UL)
#define LINFLEX_UARTCR_TX_BUFF_SIZE_2_BYTES_MASK_U32   ((uint32)0x00002000UL)
#define LINFLEX_UARTCR_TX_BUFF_SIZE_3_BYTES_MASK_U32   ((uint32)0x00004000UL)
#define LINFLEX_UARTCR_TX_BUFF_SIZE_4_BYTES_MASK_U32   ((uint32)0x00006000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  UARTSR register bit masks.
*/
#define LINFLEX_UARTSR_NF_MASK_U32     ((uint32)0x00000001UL)
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_UARTSR_DTF_MASK_U32         ((uint32)0x00000002UL)
    #define LINFLEX_UARTSR_DRF_MASK_U32         ((uint32)0x00000004UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_03_00_00
    #define LINFLEX_UARTSR_DTFTFF_MASK_U32      ((uint32)0x00000002UL)
    #define LINFLEX_UARTSR_DRFRFE_MASK_U32      ((uint32)0x00000004UL)
    #define LINFLEX_UARTSR_TO_MASK_U32          ((uint32)0x00000008UL)
#endif
#define LINFLEX_UARTSR_WUF_MASK_U32    ((uint32)0x00000020UL)
#define LINFLEX_UARTSR_RPS_MASK_U32    ((uint32)0x00000040UL)
#define LINFLEX_UARTSR_BOF_MASK_U32    ((uint32)0x00000080UL)
#define LINFLEX_UARTSR_FEF_MASK_U32    ((uint32)0x00000100UL)
#define LINFLEX_UARTSR_RMB_MASK_U32    ((uint32)0x00000200UL)
#define LINFLEX_UARTSR_PE0_MASK_U32    ((uint32)0x00000400UL)
#define LINFLEX_UARTSR_PE1_MASK_U32    ((uint32)0x00000800UL)
#define LINFLEX_UARTSR_PE2_MASK_U32    ((uint32)0x00001000UL)
#define LINFLEX_UARTSR_PE3_MASK_U32    ((uint32)0x00002000UL)
#define LINFLEX_UARTSR_OCF_MASK_U32    ((uint32)0x00004000UL)
#define LINFLEX_UARTSR_SZF_MASK_U32    ((uint32)0x00008000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINTCSR register bit masks.
*/
#define LINFLEX_LINTCSR_TOCE_MASK_U32  ((uint32)0x00000100UL)
#define LINFLEX_LINTCSR_IOT_MASK_U32   ((uint32)0x00000200UL)
#define LINFLEX_LINTCSR_LTOM_MASK_U32  ((uint32)0x00000400UL)
#define LINFLEX_LINTCSR_CNT_MASK_U32   ((uint32)0x000000FFUL)
#define LINFLEX_LINTCSR_RESET_MASK_U32 ((uint32)0x00000000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINOCR register bit masks.
*/
#define LINFLEX_LINOCR_OC1_MASK_U32    ((uint32)0x000000FFUL)
#define LINFLEX_LINOCR_OC2_MASK_U32    ((uint32)0x0000FF00UL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINTOCR register bit masks.
*/
#define LINFLEX_LINTOCR_RTO_MASK_U32   ((uint32)0x00000F00UL)
#define LINFLEX_LINTOCR_HTO_MASK_U32   ((uint32)0x0000007FUL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINFBRR register bit masks.
*/
#define LINFLEX_LINFBRR_DIV_F_MASK_U32 ((uint32)0x0000000FUL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINIBRR register bit masks.
*/
#if IPV_LINFLEX <= IPV_LINFLEX_00_10_00
    #define LINFLEX_LINIBRR_DIV_M_MASK_U32 ((uint32)0x1FFF0000UL)
#elif ((IPV_LINFLEX >= IPV_LINFLEX_03_00_00) && (IPV_LINFLEX < IPV_LINFLEX_04_00_00))
    #define LINFLEX_LINIBRR_DIV_M_MASK_U32 ((uint32)0xFFFFF000UL)
#elif IPV_LINFLEX >= IPV_LINFLEX_04_00_00
    #define LINFLEX_LINIBRR_DIV_M_MASK_U32 ((uint32)0xFFFFFF00UL)
#endif

/**
* @brief    LINFLEX Registers bits.
* @details  LINCFR register bit masks.
*/
#define LINFLEX_LINCFR_CF_MASK_U32     ((uint32)0x000000FFUL)

/**
* @brief    LINFLEX Registers bits.
* @details  LINCR2 register bit masks.
*/
#define LINFLEX_LINCR2_HTRQ_MASK_U32   ((uint32)0x00000100UL)
#define LINFLEX_LINCR2_ABRQ_MASK_U32   ((uint32)0x00000200UL)
#define LINFLEX_LINCR2_DTRQ_MASK_U32   ((uint32)0x00000400UL)
#define LINFLEX_LINCR2_DDRQ_MASK_U32   ((uint32)0x00000800UL)
#define LINFLEX_LINCR2_WURQ_MASK_U32   ((uint32)0x00001000UL)
#define LINFLEX_LINCR2_IOPE_MASK_U32   ((uint32)0x00002000UL)
#define LINFLEX_LINCR2_IOBE_MASK_U32   ((uint32)0x00004000UL)
#define LINFLEX_LINCR2_TBDE_MASK_U32   ((uint32)0x00008000UL)

/**
* @brief    LINFLEX Registers bits.
* @details  BIDR register bit masks.
*/
#define LINFLEX_BIDR_ID_MASK_U32       ((uint32)0x0000003FUL)
#define LINFLEX_BIDR_CCS_MASK_U32      ((uint32)0x00000100UL)
#define LINFLEX_BIDR_DIR_MASK_U32      ((uint32)0x00000200UL)

#if IPV_LINFLEX >= IPV_LINFLEX_05_04_68
    #define LINFLEX_BIDR_DFL_EXT_MASK_U32  ((uint32)0x00001C00UL)
#else
    #define LINFLEX_BIDR_DFL_EXT_MASK_U32  ((uint32)0x0000FC00UL)
#endif

#define LINFLEX_BIDR_DFL_NOR_MASK_U32  ((uint32)0x00001C00UL)
#define LINFLEX_BIDR_DFL_SET_MASK_U32  ((uint32)0x00000007UL)

/**
* @brief    LINFLEX Registers bits.
* @details  BDRL register bit masks.
*/
#define LINFLEX_BDRL_DATA3_MASK_U32    ((uint32)0xFF000000UL)
#define LINFLEX_BDRL_DATA2_MASK_U32    ((uint32)0x00FF0000UL)
#define LINFLEX_BDRL_DATA1_MASK_U32    ((uint32)0x0000FF00UL)
#define LINFLEX_BDRL_DATA0_MASK_U32    ((uint32)0x000000FFUL)

/**
* @brief    LINFLEX Registers bits.
* @details  BDRM register bit masks.
*/
#define LINFLEX_BDRM_DATA7_MASK_U32    ((uint32)0xFF000000UL)
#define LINFLEX_BDRM_DATA6_MASK_U32    ((uint32)0x00FF0000UL)
#define LINFLEX_BDRM_DATA5_MASK_U32    ((uint32)0x0000FF00UL)
#define LINFLEX_BDRM_DATA4_MASK_U32    ((uint32)0x000000FFUL)

/*==================================================================================================
                                             ENUMS
==================================================================================================*/

/*==================================================================================================
                                 STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
                                 GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                     FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* REG_ESYS_LINFLEX_H */

/** @} */
