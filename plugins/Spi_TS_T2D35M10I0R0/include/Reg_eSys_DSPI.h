/**
*   @file    Reg_eSys_DSPI.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Spi - Reg eSys header file.
*   @details Reg eSys header file.

*   @addtogroup [SPI_MODULE]
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : DSPI
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

#ifndef REG_ESYS_DSPI_H
#define REG_ESYS_DSPI_H

#ifdef __cplusplus
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely 
* on the significance of more than 31 characters.
*
* @section Reg_eSys_DSPI_h_REF_1
* Violates MISRA 2004 Advisory Rule 19.7,
* A function should be used in preference to a function-like macro.
* Compiler abstraction need to implement function-like macros to hide
* compiler specifics from the implementation.
*
* @section Reg_eSys_DSPI_h_REF_2
* Violates MISRA 2004 Required Rule 19.15,
* Precautions shall be taken in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from include dependencies. As a safe
* approach, any file must include all its dependencies. Header files are already protected against
* double inclusions. The inclusion of MemMap.h is as per Autosar requirement MEMMAP003.
*
* @section Reg_eSys_DSPI_h_REF_4
* Violates MISRA 2004 Required Rule 1.4,
* The compiler/linker shall be checked to ensure that 31 character significance and case sensitivity
* are supported for external identifiers.
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Reg_eSys_DSPI.c
* @requirements   BSW00374, BSW00318, SPI276.
*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
#include "Reg_eSys.h"
#include "StdRegMacros.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Reg_eSys_DSPI.h
*/
#define SPI_VENDOR_ID_REGFLEX                    43
#define SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX     4
#define SPI_AR_RELEASE_MINOR_VERSION_REGFLEX     2
/*
* @violates @ref Reg_eSys_DSPI_h_REF_4 The compiler/linker shall be checked to
* ensure that 31 character significance and case sensitivity are supported for
* external identifiers.
*/
#define SPI_AR_RELEASE_REVISION_VERSION_REGFLEX  2
#define SPI_SW_MAJOR_VERSION_REGFLEX             1
#define SPI_SW_MINOR_VERSION_REGFLEX             0
#define SPI_SW_PATCH_VERSION_REGFLEX             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and Reg_eSys header file are of the same version */
  #if ((SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION_REGFLEX != REG_ESYS_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Reg_eSys_DSPI.c and Reg_eSys.h are different"
  #endif

  /* Check if the source file and StdRegMacros header file are of the same version */
  #if ((SPI_AR_RELEASE_MAJOR_VERSION_REGFLEX != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
       (SPI_AR_RELEASE_MINOR_VERSION_REGFLEX != STDREGMACROS_AR_RELEASE_MINOR_VERSION))
      #error "AutoSar Version Numbers of Reg_eSys_DSPI.c and StdRegMacros.h are different"
  #endif
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#define SPI_START_SEC_CONST_32
/*
* @violates @ref Reg_eSys_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
 #include "Spi_MemMap.h"
 

/* HWUnit base address mapping array */
extern CONST(uint32, SPI_CONST) Spi_Dspi_au32BaseAddrs[13];

#define SPI_STOP_SEC_CONST_32
/*
* @violates @ref Reg_eSys_DSPI_h_REF_2 Precautions shall be taken in order to prevent the contents of a header 
* file being included twice.
*/
 #include "Spi_MemMap.h"
 /*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief Macros used for low-level DSPI register manipulation (begin section).
*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*to a function-like macro.
*/

#define DSPI_GET_BASE_ADDRESS_U32(offset) \
    ((uint32)Spi_Dspi_au32BaseAddrs[(offset)])

/* Mode control Register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_MCR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_Dspi_au32BaseAddrs[(offset)]))

/* Transfer count */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TCR_ADDR32(offset) \
    ((uint32) ((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x08u))

/* DSPI Clock and transfer attributes */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_GENERATE_CTAR_U32(nrofctar) \
    (((nrofctar) - 1u) << 28u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR0_ADDR32(offset) \
    ((uint32) ((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x0Cu))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR3_ADDR32(offset) \
    ((uint32) ((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x18u))

/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_CTAR_ADDR32(offset, selected_ctar) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + ((((selected_ctar) - 1u) << 2u) + 0x0Cu)))

/* DSPI Status register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_BASEADDR2SR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x2Cu))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_SR_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x2Cu))

/* DSPI DMA/Interrupt request select and enable register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_RSER_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x30u))

/* DSPI Push TX FIFO Register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_BASEADDR2PUSHR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x34u))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_PUSHR_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x34u))

/* DSPI Pop RX register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_BASEADDR2POPR_ADDR32(base_addr) \
    ((uint32)((base_addr) + 0x38u))
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_POPR_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x38u))

/* Not used for SPI module - driver/handler */

/* DSPI DSI Config register 0 */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0xBCu))

/* DSPI DSI alternate serialization data register 0 */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_ASDR_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0xC4u))

/* DSPI DSI Config register 1 */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR1_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0xD0u))

/* DSPI DSI alternate serialization data register 1 */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_ASDR1_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0xF4u))
    
#ifdef ITSB_MODE_SUPPORTED    
/* DSPI Time slot length register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TSL_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x150u))
/* DSPI Time slot configuration register */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_TS_CONF_ADDR32(offset) \
    ((uint32)((uint32)Spi_Dspi_au32BaseAddrs[(offset)] + 0x154u))    
#endif /*ITSB_MODE_SUPPORTED*/    
/*-----------------------------------------------------------------------*/

/* DSPI reserved bit masks */
#define DSPI_MCR_RESERVED_MASK_U32         ((uint32)0xFFFF7F0Fu)
#define DSPI_TCR_RESERVED_MASK_U32         ((uint32)0xFFFF0000u)
#define DSPI_CTAR_SLAVE_RESERVED_MASK_U32  ((uint32)0x7F800000u)
#define DSPI_SR_RESERVED_MASK_U32          ((uint32)0xFEFF0000u)
#define DSPI_RSER_RESERVED_MASK_U32        ((uint32)0xFFFFC000u)
#define DSPI_PUSHR_RESERVED_MASK_U32       ((uint32)0xFFFFFFFFu)
#define DSPI_DSICR_RESERVED_MASK_U32       ((uint32)0x403DFFFFu)
#define DSPI_DSICR1_RESERVED_MASK_U32      ((uint32)0x1F03FFFFu)

/* DSPI MCR attributes */
#define DSPI_MCR_MSTR_U32            ((uint32)0x80000000u)
#define DSPI_MCR_DCONF_U32           ((uint32)0x30000000u)
#define DSPI_MCR_CONT_SCKE_U32       ((uint32)0x40000000u)
#define DSPI_MCR_PCSIS_ALL_U32       ((uint32)0x00FF0000u)
#define DSPI_MCR_MDIS_U32            ((uint32)0x00004000u)  /*Module Disable*/
#define DSPI_MCR_CLR_TXF_U32         ((uint32)0x00000800u)  /*Clear TX FIFO*/
#define DSPI_MCR_CLR_RXF_U32         ((uint32)0x00000400u)  /*Clear RX FIFO*/
#define DSPI_MCR_HALT_U32            ((uint32)0x00000001u)  /*Halt 0 : starts tranfer, 1: stops transfer*/
#define DSPI_MCR_RESET_U32           (DSPI_MCR_MDIS_U32 | DSPI_MCR_HALT_U32) /* Reset value */

/* DSPI TCR attributes */
#define DSPI_TCR_RESET_U32           ((uint32)0x00000000u)

#ifdef TSB_MODE_SUPPORTED
/*Added for initialisation in TSB mode*/
#define DSPI_MCR_DCONF_DSI_U32       ((uint32)0x10000000u)  /*DSI configuration of DSPI*/
#define DSPI_MCR_DCONF_CSI_U32       ((uint32)0x20000000u)  /*CSI configuration of DSPI*/
#define DSPI_MCR_RX_FIFO_U32         ((uint32)0x00001000u)  /*Receive FIFO*/
#define DSPI_MCR_TX_FIFO_U32         ((uint32)0x00002000u)  /*Transmit FIFO*/
#endif /*TSB_MODE_SUPPORTED*/

#define DSPI_PCS0_IDLEHIGH_U32       ((uint32)0x00010000u)
#define DSPI_PCS1_IDLEHIGH_U32       ((uint32)0x00020000u)
#define DSPI_PCS2_IDLEHIGH_U32       ((uint32)0x00040000u)
#define DSPI_PCS3_IDLEHIGH_U32       ((uint32)0x00080000u)
#define DSPI_PCS4_IDLEHIGH_U32       ((uint32)0x00100000u)
#define DSPI_PCS5_IDLEHIGH_U32       ((uint32)0x00200000u)
#define DSPI_PCS6_IDLEHIGH_U32       ((uint32)0x00400000u)
#define DSPI_PCS7_IDLEHIGH_U32       ((uint32)0x00800000u)

/* Write to CTARx Register - Word access */
/* Individual flag write access shall be provided based LLD requirement */
/* Practically this file should provide write access to bits / nibble / bytes */
#define DSPI_CTAR_LSBFE_MASK_U32         ((uint32) 0x01000000u)
#define DSPI_CPHA_MASK_U32               ((uint32) 0x02000000u)
#define DSPI_LSBFE_MASK_U32              ((uint32) 0x01000000u)
#define DSPI_PCSSCK_MASK_U32             ((uint32) 0x00C00000u) /* 1, 3, 5 , 7 */
#define DSPI_PASC_MASK_U32               ((uint32) 0x00300000u)
#define DSPI_PDT_MASK_U32                ((uint32) 0x000C0000u)
#define DSPI_PBR_MASK_U32                ((uint32) 0x00030000u)
#define DSPI_CSSCK_MASK_U32              ((uint32) 0x0000F000u)
#define DSPI_ASC_MASK_U32                ((uint32) 0x00000F00u)
#define DSPI_DT_MASK_U32                 ((uint32) 0x000000F0u)
#define DSPI_BR_MASK_U32                 ((uint32) 0x0000000Fu)

/*-----------Read DSPI Status Register-Start---------------------------------*/
#define DSPI_SR_TCF_W1C                 ((uint32) 0x80000000u)
#define DSPI_SR_TXRXS_W1C               ((uint32) 0x40000000u)
#define DSPI_SR_EOQF_W1C                ((uint32) 0x10000000u)
#define DSPI_SR_TFUF_W1C                ((uint32) 0x08000000u)
#define DSPI_SR_TFFF_W1C                ((uint32) 0x02000000u)
#define DSPI_SR_DPEF_W1C                ((uint32) 0x00400000u)
#define DSPI_SR_SPEF_W1C                ((uint32) 0x00200000u)
#define DSPI_SR_DDIF_W1C                ((uint32) 0x00100000u)
#define DSPI_SR_RFOF_W1C                ((uint32) 0x00080000u)
#define DSPI_SR_RFDF_W1C                ((uint32) 0x00020000u)
#define DSPI_SR_TXCTR_MASK_U32          ((uint32) 0x0000F000u)
#define DSPI_SR_TXNXT_MASK_U32          ((uint32) 0x00000F00u)
#define DSPI_SR_RXCTR_MASK_U32          ((uint32) 0x000000F0u)
#define DSPI_SR_RXNXT_MASK_U32          ((uint32) 0x0000000Fu)
#define DSPI_SR_INT_MASK_U32 \
    ((uint32)( DSPI_SR_TCF_W1C | DSPI_SR_TXRXS_W1C | DSPI_SR_EOQF_W1C | \
    DSPI_SR_TFUF_W1C | DSPI_SR_TFFF_W1C | DSPI_SR_DPEF_W1C | \
    DSPI_SR_SPEF_W1C | DSPI_SR_DDIF_W1C | DSPI_SR_RFOF_W1C | DSPI_SR_RFDF_W1C ))

/*----Write to DSPI DMA/Interrupt Request Select and Enable - Start ----------*/
#define DSPI_RSER_TCF_RE_MASK_U32     ((uint32) 0x80000000u)
#define DSPI_RSER_EOQF_RE_MASK_U32    ((uint32) 0x10000000u)
#define DSPI_RSER_TFUF_RE_MASK_U32    ((uint32) 0x08000000u)
#define DSPI_RSER_TFFF_RE_MASK_U32    ((uint32) 0x02000000u)
#define DSPI_RSER_TFFF_DIRS_MASK_U32  ((uint32) 0x01000000u)
#define DSPI_RSER_DPEF_RE_MASK_U32    ((uint32) 0x00400000u)
#define DSPI_RSER_SPEF_RE_MASK_U32    ((uint32) 0x00200000u)
#define DSPI_RSER_DDIF_RE_MASK_U32    ((uint32) 0x00100000u)
#define DSPI_RSER_RFOF_RE_MASK_U32    ((uint32) 0x00080000u)
#define DSPI_RSER_RFDF_RE_MASK_U32    ((uint32) 0x00020000u)
#define DSPI_RSER_RFDF_DIRS_MASK_U32  ((uint32) 0x00010000u)
#define DSPI_RSER_RESET_MASK_U32      ((uint32) 0x00000000u)

/* ---------------DSPI FIFO Transmit Register - Start ----------------------- */
#define DSPI_CONT_MASK_U32           ((uint32) 0x80000000u)
#define DSPI_CTAS_MASK_U32           ((uint32) 0x70000000u)
#define DSPI_EOQ_MASK_U32            ((uint32) 0x08000000u)
#define DSPI_CTCNT_MASK_U32          ((uint32) 0x04000000u)
#define DSPI_PE_MASK_U32             ((uint32) 0x02000000u)
#define DSPI_PP_MASK_U32             ((uint32) 0x01000000u)
#define DSPI_PCS7_MASK_U32           ((uint32) 0x00800000u)
#define DSPI_PCS6_MASK_U32           ((uint32) 0x00400000u)
#define DSPI_PCS5_MASK_U32           ((uint32) 0x00200000u)
#define DSPI_PCS4_MASK_U32           ((uint32) 0x00100000u)
#define DSPI_PCS3_MASK_U32           ((uint32) 0x00080000u)
#define DSPI_PCS2_MASK_U32           ((uint32) 0x00040000u)
#define DSPI_PCS1_MASK_U32           ((uint32) 0x00020000u)
#define DSPI_PCS0_MASK_U32           ((uint32) 0x00010000u)
#define DSPI_TXDATA_MASK_U32         ((uint32) 0x0000FFFFu)

/* ---------------DSPI FIFO Receive Register - Start------------------------- */
#define DSPI_RXDATA_MASK_U32             ((uint32) 0x0000FFFFu)

/* ---------------DSPI Transmit FIFO Register0-4 - Start---------------------- */
#define DSPI_TX_CMD_MASK_U32             ((uint32) 0xFFFF0000u)

/* DSPI CTAR attributes */
#define DSPI_CTAR_RESET_U32          ((uint32)0x78000000u)
#define DSPI_CTAR_DBR_0_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_DBR_1_U32          ((uint32)0x80000000u)

#define DSPI_CTAR_CPOL_LOW_U32       ((uint32)0x00000000u)
#define DSPI_CTAR_CPOL_HIGH_U32      ((uint32)0x04000000u)

#define DSPI_CTAR_CPHA_LEADING_U32   ((uint32)0x02000000u)
#define DSPI_CTAR_CPHA_TRAILING_U32  ((uint32)0x00000000u)

#define DSPI_CTAR_MSB_U32            ((uint32)0x00000000u)
#define DSPI_CTAR_LSB_U32            ((uint32)0x01000000u)

#define DSPI_CTAR_PCSCLK_0_U32       ((uint32)0x00000000u)
#define DSPI_CTAR_PCSCLK_1_U32       ((uint32)0x00000000u)
#define DSPI_CTAR_PCSCLK_3_U32       ((uint32)0x00400000u)
#define DSPI_CTAR_PCSCLK_5_U32       ((uint32)0x00800000u)
#define DSPI_CTAR_PCSCLK_7_U32       ((uint32)0x00C00000u)

#define DSPI_CTAR_PASC_0_U32         ((uint32)0x00000000u)
#define DSPI_CTAR_PASC_1_U32         ((uint32)0x00000000u)
#define DSPI_CTAR_PASC_3_U32         ((uint32)0x00100000u)
#define DSPI_CTAR_PASC_5_U32         ((uint32)0x00200000u)
#define DSPI_CTAR_PASC_7_U32         ((uint32)0x00300000u)

#define DSPI_CTAR_PDT_0_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_PDT_1_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_PDT_3_U32          ((uint32)0x00040000u)
#define DSPI_CTAR_PDT_5_U32          ((uint32)0x00080000u)
#define DSPI_CTAR_PDT_7_U32          ((uint32)0x000C0000u)

#define DSPI_CTAR_PBR_0_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_PBR_2_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_PBR_3_U32          ((uint32)0x00010000u)
#define DSPI_CTAR_PBR_5_U32          ((uint32)0x00020000u)
#define DSPI_CTAR_PBR_7_U32          ((uint32)0x00030000u)

#define DSPI_CTAR_SCSCLK_0_U32       ((uint32)0x00000000u)
#define DSPI_CTAR_SCSCLK_2_U32       ((uint32)0x00000000u)
#define DSPI_CTAR_SCSCLK_4_U32       ((uint32)0x00001000u)
#define DSPI_CTAR_SCSCLK_8_U32       ((uint32)0x00002000u)
#define DSPI_CTAR_SCSCLK_16_U32      ((uint32)0x00003000u)
#define DSPI_CTAR_SCSCLK_32_U32      ((uint32)0x00004000u)
#define DSPI_CTAR_SCSCLK_64_U32      ((uint32)0x00005000u)
#define DSPI_CTAR_SCSCLK_128_U32     ((uint32)0x00006000u)
#define DSPI_CTAR_SCSCLK_256_U32     ((uint32)0x00007000u)
#define DSPI_CTAR_SCSCLK_512_U32     ((uint32)0x00008000u)
#define DSPI_CTAR_SCSCLK_1024_U32    ((uint32)0x00009000u)
#define DSPI_CTAR_SCSCLK_2048_U32    ((uint32)0x0000A000u)
#define DSPI_CTAR_SCSCLK_4096_U32    ((uint32)0x0000B000u)
#define DSPI_CTAR_SCSCLK_8192_U32    ((uint32)0x0000C000u)
#define DSPI_CTAR_SCSCLK_16384_U32   ((uint32)0x0000D000u)
#define DSPI_CTAR_SCSCLK_32768_U32   ((uint32)0x0000E000u)
#define DSPI_CTAR_SCSCLK_65536_U32   ((uint32)0x0000F000u)

#define DSPI_CTAR_SASC_0_U32         ((uint32)0x00000000u)
#define DSPI_CTAR_SASC_2_U32         ((uint32)0x00000000u)
#define DSPI_CTAR_SASC_4_U32         ((uint32)0x00000100u)
#define DSPI_CTAR_SASC_8_U32         ((uint32)0x00000200u)
#define DSPI_CTAR_SASC_16_U32        ((uint32)0x00000300u)
#define DSPI_CTAR_SASC_32_U32        ((uint32)0x00000400u)
#define DSPI_CTAR_SASC_64_U32        ((uint32)0x00000500u)
#define DSPI_CTAR_SASC_128_U32       ((uint32)0x00000600u)
#define DSPI_CTAR_SASC_256_U32       ((uint32)0x00000700u)
#define DSPI_CTAR_SASC_512_U32       ((uint32)0x00000800u)
#define DSPI_CTAR_SASC_1024_U32      ((uint32)0x00000900u)
#define DSPI_CTAR_SASC_2048_U32      ((uint32)0x00000A00u)
#define DSPI_CTAR_SASC_4096_U32      ((uint32)0x00000B00u)
#define DSPI_CTAR_SASC_8192_U32      ((uint32)0x00000C00u)
#define DSPI_CTAR_SASC_16384_U32     ((uint32)0x00000D00u)
#define DSPI_CTAR_SASC_32768_U32     ((uint32)0x00000E00u)
#define DSPI_CTAR_SASC_65536_U32     ((uint32)0x00000F00u)

#define DSPI_CTAR_SDT_0_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_SDT_2_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_SDT_4_U32          ((uint32)0x00000010u)
#define DSPI_CTAR_SDT_8_U32          ((uint32)0x00000020u)
#define DSPI_CTAR_SDT_16_U32         ((uint32)0x00000030u)
#define DSPI_CTAR_SDT_32_U32         ((uint32)0x00000040u)
#define DSPI_CTAR_SDT_64_U32         ((uint32)0x00000050u)
#define DSPI_CTAR_SDT_128_U32        ((uint32)0x00000060u)
#define DSPI_CTAR_SDT_256_U32        ((uint32)0x00000070u)
#define DSPI_CTAR_SDT_512_U32        ((uint32)0x00000080u)
#define DSPI_CTAR_SDT_1024_U32       ((uint32)0x00000090u)
#define DSPI_CTAR_SDT_2048_U32       ((uint32)0x000000A0u)
#define DSPI_CTAR_SDT_4096_U32       ((uint32)0x000000B0u)
#define DSPI_CTAR_SDT_8192_U32       ((uint32)0x000000C0u)
#define DSPI_CTAR_SDT_16384_U32      ((uint32)0x000000D0u)
#define DSPI_CTAR_SDT_32768_U32      ((uint32)0x000000E0u)
#define DSPI_CTAR_SDT_65536_U32      ((uint32)0x000000F0u)

#define DSPI_CTAR_SBR_0_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_SBR_2_U32          ((uint32)0x00000000u)
#define DSPI_CTAR_SBR_4_U32          ((uint32)0x00000001u)
#define DSPI_CTAR_SBR_6_U32          ((uint32)0x00000002u)
#define DSPI_CTAR_SBR_8_U32          ((uint32)0x00000003u)
#define DSPI_CTAR_SBR_16_U32         ((uint32)0x00000004u)
#define DSPI_CTAR_SBR_32_U32         ((uint32)0x00000005u)
#define DSPI_CTAR_SBR_64_U32         ((uint32)0x00000006u)
#define DSPI_CTAR_SBR_128_U32        ((uint32)0x00000007u)
#define DSPI_CTAR_SBR_256_U32        ((uint32)0x00000008u)
#define DSPI_CTAR_SBR_512_U32        ((uint32)0x00000009u)
#define DSPI_CTAR_SBR_1024_U32       ((uint32)0x0000000Au)
#define DSPI_CTAR_SBR_2048_U32       ((uint32)0x0000000Bu)
#define DSPI_CTAR_SBR_4096_U32       ((uint32)0x0000000Cu)
#define DSPI_CTAR_SBR_8192_U32       ((uint32)0x0000000Du)
#define DSPI_CTAR_SBR_16384_U32      ((uint32)0x0000000Eu)
#define DSPI_CTAR_SBR_32768_U32      ((uint32)0x0000000Fu)

/* DSPI CMD attributes */
#define DSPI_CMD_CONTINOUS_FALSE_U32  ((uint32)0x00000000u)
#define DSPI_CMD_CONTINOUS_TRUE_U32   ((uint32)0x80000000u)

#define DSPI_CMD_CTAR_SEL_0_U32     ((uint32)0x00000000u)
#define DSPI_CMD_CTAR_SEL_1_U32     ((uint32)0x10000000u)
#define DSPI_CMD_CTAR_SEL_2_U32     ((uint32)0x20000000u)
#define DSPI_CMD_CTAR_SEL_3_U32     ((uint32)0x30000000u)
#define DSPI_CMD_CTAR_SEL_4_U32     ((uint32)0x40000000u)
#define DSPI_CMD_CTAR_SEL_5_U32     ((uint32)0x50000000u)
#define DSPI_CMD_CTAR_SEL_6_U32     ((uint32)0x60000000u)
#define DSPI_CMD_CTAR_SEL_7_U32     ((uint32)0x70000000u)

#define DSPI_CMD_MSB_U32             ((uint32)0x00000000u)
#define DSPI_CMD_LSB_U32             ((uint32)0x01000000u)

#define DSPI_CMD_WIDTH_4_U32         ((uint32)0x18000000u)
#define DSPI_CMD_WIDTH_5_U32         ((uint32)0x20000000u)
#define DSPI_CMD_WIDTH_6_U32         ((uint32)0x28000000u)
#define DSPI_CMD_WIDTH_7_U32         ((uint32)0x30000000u)
#define DSPI_CMD_WIDTH_8_U32         ((uint32)0x38000000u)
#define DSPI_CMD_WIDTH_9_U32         ((uint32)0x40000000u)
#define DSPI_CMD_WIDTH_10_U32        ((uint32)0x48000000u)
#define DSPI_CMD_WIDTH_11_U32        ((uint32)0x50000000u)
#define DSPI_CMD_WIDTH_12_U32        ((uint32)0x58000000u)
#define DSPI_CMD_WIDTH_13_U32        ((uint32)0x60000000u)
#define DSPI_CMD_WIDTH_14_U32        ((uint32)0x68000000u)
#define DSPI_CMD_WIDTH_15_U32        ((uint32)0x70000000u)
#define DSPI_CMD_WIDTH_16_U32        ((uint32)0x78000000u)

#define DSPI_CMD_PCS0_U32            ((uint32)0x00010000u)
#define DSPI_CMD_PCS1_U32            ((uint32)0x00020000u)
#define DSPI_CMD_PCS2_U32            ((uint32)0x00040000u)
#define DSPI_CMD_PCS3_U32            ((uint32)0x00080000u)
#define DSPI_CMD_PCS4_U32            ((uint32)0x00100000u)
#define DSPI_CMD_PCS5_U32            ((uint32)0x00200000u)
#define DSPI_CMD_PCS6_U32            ((uint32)0x00400000u)
#define DSPI_CMD_PCS7_U32            ((uint32)0x00800000u)

#ifdef TSB_MODE_SUPPORTED
/*DSI Configuration Register selects various attributes associated
with DSI and CSI Configurations.*/
/*TSBC bit enables the Timed Serial Bus Configuration.*/
#define DSPI_DSICR_TSBC_U32           ((uint32)0x00100000u)
#ifdef ITSB_MODE_SUPPORTED
/*iTSBC bit enables the Interleave Timed Serial Bus Configuration.*/
#define DSPI_DSICR_ITSBC_U32          ((uint32)0x00300000u)
#endif /*ITSB_MODE_SUPPORTED*/
/*ctar3 selection*/
#define DSPI_DSICR_DSICTAS_CTAR3_U32  ((uint32)0x00003000u)
#endif /*TSB_MODE_SUPPORTED*/

/**
* @brief Macros used for low-level DSPI register read/writes operations (begin section).
*/

/* ---------- Read transfer count register to manage queue --Start ---------- */

/* Read TXCTR FIFO value - Nibble */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_SR_TXCTR_VAL_U32(value) \
    (((value) & DSPI_SR_TXCTR_MASK_U32) >> 12 )

/* Read RXCTR FIFO value - Nibble */
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_SR_RXCTR_VAL_U32(value) \
    (((value) & DSPI_SR_RXCTR_MASK_U32) >> 4 )


/* ---------------DSPI FIFO Transmit Register - End-------------------------- */

#ifdef TSB_MODE_SUPPORTED
/*----------------DSPI DSI Configuration Register DSPI_DSICR -----------------------------*/
/*Timed Serial Bus Configuration enabled*/
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_TXSS_SET_U32       ((uint32)0x00080000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_TXSS_CLEAR_U32     ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CID_SET_U32        ((uint32)0x00010000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CID_CLEAR_U32      ((uint32)0x00000000u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS0_U32       ((uint32)0x00000001u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS1_U32       ((uint32)0x00000002u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS2_U32       ((uint32)0x00000004u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS3_U32       ((uint32)0x00000008u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS4_U32       ((uint32)0x00000010u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS5_U32       ((uint32)0x00000020u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS6_U32       ((uint32)0x00000040u)
/*
* @violates @ref Reg_eSys_DSPI_h_REF_1 A function should be used in preference
*   to a function-like macro.
*/
#define DSPI_DSICR_CS_DPCS7_U32       ((uint32)0x00000080u)

/*----------------DSPI DSI Configuration Register1 DSPI_DSICR1 -----------------------------*/
#define DSPI_DSICR1_CS_DPCS0_U32       ((uint32)0x00000001u)
#define DSPI_DSICR1_CS_DPCS1_U32       ((uint32)0x00000002u)
#define DSPI_DSICR1_CS_DPCS2_U32       ((uint32)0x00000004u)
#define DSPI_DSICR1_CS_DPCS3_U32       ((uint32)0x00000008u)
#define DSPI_DSICR1_CS_DPCS4_U32       ((uint32)0x00000010u)
#define DSPI_DSICR1_CS_DPCS5_U32       ((uint32)0x00000020u)
#define DSPI_DSICR1_CS_DPCS6_U32       ((uint32)0x00000040u)
#define DSPI_DSICR1_CS_DPCS7_U32       ((uint32)0x00000080u)
#define DSPI_DSICR1_TSBCNT_3_U32       ((uint32)0x03000000u)
#define DSPI_DSICR1_TSBCNT_4_U32       ((uint32)0x04000000u)
#define DSPI_DSICR1_TSBCNT_5_U32       ((uint32)0x05000000u)
#define DSPI_DSICR1_TSBCNT_6_U32       ((uint32)0x06000000u)
#define DSPI_DSICR1_TSBCNT_7_U32       ((uint32)0x07000000u)
#define DSPI_DSICR1_TSBCNT_8_U32       ((uint32)0x08000000u)
#define DSPI_DSICR1_TSBCNT_9_U32       ((uint32)0x09000000u)
#define DSPI_DSICR1_TSBCNT_10_U32      ((uint32)0x0A000000u)
#define DSPI_DSICR1_TSBCNT_11_U32      ((uint32)0x0B000000u)
#define DSPI_DSICR1_TSBCNT_12_U32      ((uint32)0x0C000000u)
#define DSPI_DSICR1_TSBCNT_13_U32      ((uint32)0x0D000000u)
#define DSPI_DSICR1_TSBCNT_14_U32      ((uint32)0x0E000000u)
#define DSPI_DSICR1_TSBCNT_15_U32      ((uint32)0x0F000000u)
#define DSPI_DSICR1_TSBCNT_16_U32      ((uint32)0x10000000u)
#define DSPI_DSICR1_TSBCNT_17_U32      ((uint32)0x11000000u)
#define DSPI_DSICR1_TSBCNT_18_U32      ((uint32)0x12000000u)
#define DSPI_DSICR1_TSBCNT_19_U32      ((uint32)0x13000000u)
#define DSPI_DSICR1_TSBCNT_20_U32      ((uint32)0x14000000u)
#define DSPI_DSICR1_TSBCNT_21_U32      ((uint32)0x15000000u)
#define DSPI_DSICR1_TSBCNT_22_U32      ((uint32)0x16000000u)
#define DSPI_DSICR1_TSBCNT_23_U32      ((uint32)0x17000000u)
#define DSPI_DSICR1_TSBCNT_24_U32      ((uint32)0x18000000u)
#define DSPI_DSICR1_TSBCNT_25_U32      ((uint32)0x19000000u)
#define DSPI_DSICR1_TSBCNT_26_U32      ((uint32)0x1A000000u)
#define DSPI_DSICR1_TSBCNT_27_U32      ((uint32)0x1B000000u)
#define DSPI_DSICR1_TSBCNT_28_U32      ((uint32)0x1C000000u)
#define DSPI_DSICR1_TSBCNT_29_U32      ((uint32)0x1D000000u)
#define DSPI_DSICR1_TSBCNT_30_U32      ((uint32)0x1E000000u)
#define DSPI_DSICR1_TSBCNT_31_U32      ((uint32)0x1F000000u)
#define DSPI_DSICR1_TSBCNT_32_U32      ((uint32)0x20000000u)
#define DSPI_DSICR1_TSBCNT_33_U32      ((uint32)0x21000000u)
#define DSPI_DSICR1_TSBCNT_34_U32      ((uint32)0x22000000u)
#define DSPI_DSICR1_TSBCNT_35_U32      ((uint32)0x23000000u)
#define DSPI_DSICR1_TSBCNT_36_U32      ((uint32)0x24000000u)
#define DSPI_DSICR1_TSBCNT_37_U32      ((uint32)0x25000000u)
#define DSPI_DSICR1_TSBCNT_38_U32      ((uint32)0x26000000u)
#define DSPI_DSICR1_TSBCNT_39_U32      ((uint32)0x27000000u)
#define DSPI_DSICR1_TSBCNT_40_U32      ((uint32)0x28000000u)
#define DSPI_DSICR1_TSBCNT_41_U32      ((uint32)0x29000000u)
#define DSPI_DSICR1_TSBCNT_42_U32      ((uint32)0x2A000000u)
#define DSPI_DSICR1_TSBCNT_43_U32      ((uint32)0x2B000000u)
#define DSPI_DSICR1_TSBCNT_44_U32      ((uint32)0x2C000000u)
#define DSPI_DSICR1_TSBCNT_45_U32      ((uint32)0x2D000000u)
#define DSPI_DSICR1_TSBCNT_46_U32      ((uint32)0x2E000000u)
#define DSPI_DSICR1_TSBCNT_47_U32      ((uint32)0x2F000000u)
#define DSPI_DSICR1_TSBCNT_48_U32      ((uint32)0x30000000u)
#define DSPI_DSICR1_TSBCNT_49_U32      ((uint32)0x31000000u)
#define DSPI_DSICR1_TSBCNT_50_U32      ((uint32)0x32000000u)
#define DSPI_DSICR1_TSBCNT_51_U32      ((uint32)0x33000000u)
#define DSPI_DSICR1_TSBCNT_52_U32      ((uint32)0x34000000u)
#define DSPI_DSICR1_TSBCNT_53_U32      ((uint32)0x35000000u)
#define DSPI_DSICR1_TSBCNT_54_U32      ((uint32)0x36000000u)
#define DSPI_DSICR1_TSBCNT_55_U32      ((uint32)0x37000000u)
#define DSPI_DSICR1_TSBCNT_56_U32      ((uint32)0x38000000u)
#define DSPI_DSICR1_TSBCNT_57_U32      ((uint32)0x39000000u)
#define DSPI_DSICR1_TSBCNT_58_U32      ((uint32)0x3A000000u)
#define DSPI_DSICR1_TSBCNT_59_U32      ((uint32)0x3B000000u)
#define DSPI_DSICR1_TSBCNT_60_U32      ((uint32)0x3C000000u)
#define DSPI_DSICR1_TSBCNT_61_U32      ((uint32)0x3D000000u)
#define DSPI_DSICR1_TSBCNT_62_U32      ((uint32)0x3E000000u)
#define DSPI_DSICR1_TSBCNT_63_U32      ((uint32)0x3F000000u)
#define DSPI_DUALRECEIVER_DISABLED_U32 ((uint32)0x00000000u)
#define DSPI_DSICR1_DSI64E_MASK_U32    ((uint32)0x00040000u)

#endif /*TSB_MODE_SUPPORTED*/

#ifdef ITSB_MODE_SUPPORTED
/*----------------DSPI Time Slot Configuration Register DSPI_TS_CONF -----------------------------*/
/*Interleave Timed Serial Bus Configuration enabled*/
/*----------------Time Slot 3 Configuration -----------------------------*/
#define DSPI_TS_CONF_TS3_PF_U32       ((uint32)0x00000000u)
#define DSPI_TS_CONF_TS3_SRDF_U32     ((uint32)0x00001000u)
#define DSPI_TS_CONF_TS3_DRF1_U32     ((uint32)0x00002000u)
#define DSPI_TS_CONF_TS3_DRF2_U32     ((uint32)0x00003000u)
#define DSPI_TS_CONF_TS3_CMD_PF_U32   ((uint32)0x00004000u)
#define DSPI_TS_CONF_TS3_CMD_SRDF_U32 ((uint32)0x00005000u)
#define DSPI_TS_CONF_TS3_CMD_DRF1_U32 ((uint32)0x00006000u)
#define DSPI_TS_CONF_TS3_CMD_DRF2_U32 ((uint32)0x00007000u)
/*----------------Time Slot 2 Configuration -----------------------------*/
#define DSPI_TS_CONF_TS2_PF_U32       ((uint32)0x00000000u)
#define DSPI_TS_CONF_TS2_SRDF_U32     ((uint32)0x00000100u)
#define DSPI_TS_CONF_TS2_DRF1_U32     ((uint32)0x00000200u)
#define DSPI_TS_CONF_TS2_DRF2_U32     ((uint32)0x00000300u)
#define DSPI_TS_CONF_TS2_CMD_PF_U32   ((uint32)0x00000400u)
#define DSPI_TS_CONF_TS2_CMD_SRDF_U32 ((uint32)0x00000500u)
#define DSPI_TS_CONF_TS2_CMD_DRF1_U32 ((uint32)0x00000600u)
#define DSPI_TS_CONF_TS2_CMD_DRF2_U32 ((uint32)0x00000700u)
/*----------------Time Slot 1 Configuration -----------------------------*/
#define DSPI_TS_CONF_TS1_PF_U32       ((uint32)0x00000000u)
#define DSPI_TS_CONF_TS1_SRDF_U32     ((uint32)0x00000010u)
#define DSPI_TS_CONF_TS1_DRF1_U32     ((uint32)0x00000020u)
#define DSPI_TS_CONF_TS1_DRF2_U32     ((uint32)0x00000030u)
#define DSPI_TS_CONF_TS1_CMD_PF_U32   ((uint32)0x00000040u)
#define DSPI_TS_CONF_TS1_CMD_SRDF_U32 ((uint32)0x00000050u)
#define DSPI_TS_CONF_TS1_CMD_DRF1_U32 ((uint32)0x00000060u)
#define DSPI_TS_CONF_TS1_CMD_DRF2_U32 ((uint32)0x00000070u)
/*----------------Time Slot 0 Configuration -----------------------------*/
#define DSPI_TS_CONF_TS0_PF_U32       ((uint32)0x00000000u)
#define DSPI_TS_CONF_TS0_SRDF_U32     ((uint32)0x00000001u)
#define DSPI_TS_CONF_TS0_DRF1_U32     ((uint32)0x00000002u)
#define DSPI_TS_CONF_TS0_DRF2_U32     ((uint32)0x00000003u)
#define DSPI_TS_CONF_TS0_CMD_PF_U32   ((uint32)0x00000004u)
#define DSPI_TS_CONF_TS0_CMD_SRDF_U32 ((uint32)0x00000005u)
#define DSPI_TS_CONF_TS0_CMD_DRF1_U32 ((uint32)0x00000006u)
#define DSPI_TS_CONF_TS0_CMD_DRF2_U32 ((uint32)0x00000007u)
#endif /*ITSB_MODE_SUPPORTED*/

/*==================================================================================================
*                                            ENUMS
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


#ifdef __cplusplus
}
#endif

#endif /* REG_eSys_DSPI_H */



/** @} */
