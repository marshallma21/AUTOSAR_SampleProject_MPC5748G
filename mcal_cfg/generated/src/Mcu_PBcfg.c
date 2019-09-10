/**
*   @file    Mcu_PBcfg.c
*   @implements Mcu_PBcfg.c_Artifact
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Data structures for the Mcu driver.
*   @details Postbuild structure configurations for the driver initalization.
*
*   @addtogroup MCU
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : MC
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
extern "C"
{
#endif


/**
* @page misra_violations MISRA-C:2004 violations
*
* @section Mcu_PBcfg_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a violation
* since all header files are protected against multiple inclusions
*
* @section Mcu_PBcfg_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_PBcfg_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_PBcfg_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between
* a pointer to a function and any type other than an integral type.
* Appears when accessing memory-mapped registers.
*
* @section Mcu_PBcfg_c_REF_5
* Violates MISRA 2004 Advisory Rule 11.4, A cast should not be performed
* between a pointer to object type and a different pointer to object type.
*
* @section Mcu_PBcfg_c_REF_6
* Violates MISRA 2004 Required Rule 20.2, The names of standard macros, objects and
* functions shall not be reused
*
* @section Mcu_PBcfg_c_REF_7
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects or functions
* at file scope shall have internal linkage unless external linkage is requiered.
*
* @section Mcu_PBcfg_c_REF_8
* Violates MISRA 2004 Required Rule 8.12, when an array is declared with external linkage, it's size shall be stated explicitly
* or defined implicitly by initialisation
*
* @section Mcu_PBcfg_c_REF_9
* Violates MISRA 2004 Required Rule 8.8, external object should be declared in one and only one file
*
* @section Mcu_PBcfg_c_REF_10
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
* The cast is used to access memory mapped registers.
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/


/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Mcu.h"

#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#include "Dem.h"
#endif /* (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF) */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

#define MCU_PBCFG_VENDOR_ID_C                     43
#define MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C      4
#define MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C      2
#define MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C   2
#define MCU_PBCFG_SW_MAJOR_VERSION_C              1
#define MCU_PBCFG_SW_MINOR_VERSION_C              0
#define MCU_PBCFG_SW_PATCH_VERSION_C              0

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/
/* Check if current file and MCU header file are of the same vendor */
#if (MCU_PBCFG_VENDOR_ID_C != MCU_VENDOR_ID)
    #error "Mcu_PBcfg.c and Mcu.h have different vendor ids"
#endif
/* Check if current file and MCU header file are of the same Autosar version */
#if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != MCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != MCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_PBCFG_AR_RELEASE_REVISION_VERSION_C != MCU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_PBcfg.c and Mcu.h are different"
#endif
/* Check if current file and MCU header file are of the same Software version */
#if ((MCU_PBCFG_SW_MAJOR_VERSION_C != MCU_SW_MAJOR_VERSION) || \
     (MCU_PBCFG_SW_MINOR_VERSION_C != MCU_SW_MINOR_VERSION) || \
     (MCU_PBCFG_SW_PATCH_VERSION_C != MCU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_PBcfg.c and Mcu.h are different"
#endif

/* Check if current file and DEM header file are of the same version */
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_PBCFG_AR_RELEASE_MAJOR_VERSION_C != DEM_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_PBCFG_AR_RELEASE_MINOR_VERSION_C != DEM_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_PBcfg.c and Dem.h are different"
    #endif
#endif
#endif


/*==================================================================================================
*                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
                                       LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#define MCU_START_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcu_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PBcfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/**
    @file    Mcu_checkvalues.m
    @version 1.0.0

    @brief   AUTOSAR Mcu - File used by the C generation templates.
    @details This file contains macros used by the C generation templates.

    Project AUTOSAR 4.2 MCAL
    Platform PA
    Peripheral MC
    Dependencies none

    ARVersion 4.2.2
    ARRevision ASR_REL_4_2_REV_0002
    ARConfVariant
    SWVersion 1.0.0
    BuildVersion MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20170217

    (c) Copyright 2006-2016 Freescale Semiconductor, Inc. 
*       Copyright 2017 NXP
    All Rights Reserved.
 */
/*==================================================================================================
==================================================================================================*/

/* Macro to check one RAM section */



/* Macro to check one clock setting */











/**
* @brief        Definition of RAM sections within the configuration structure.
* @details      Blocks of memory are initialized with a default data.
*               Configuration set by calling Mcu_InitClock() API.
*
*/
static CONST(Mcu_RamConfigType, MCU_CONST) Mcu_aRamConfigPB0[1] =
{

    {
        /* The ID for Ram Sector configuration. */
        (uint8)0U,

        /* RAM section base address: Start of Mcu_RamConfig[0]. */
        /** @violates @ref Mcu_PBcfg_c_REF_4 MISRA 2004 Required Rule 11.1, conversion from pointer to integer */
        /** @violates @ref Mcu_PBcfg_c_REF_5 MISRA 2004 Advisory Rule 11.4, cast between pointer and object */
        /** @violates @ref Mcu_PBcfg_c_REF_10 MISRA 2004 Required Rule 11.3, the cast is used to access a linker symbol */
        (uint8 (*)[1U])0x40000000U,

        /* RAM section size: Section base address (must be aligned to 4 bytes). */
        /** @violates @ref Mcu_PBcfg_c_REF_4 MISRA 2004 Required Rule 11.1, conversion from pointer to integer */
        /** @violates @ref Mcu_PBcfg_c_REF_10 MISRA 2004 Required Rule 11.3, the cast is used to access a linker symbol */
        (uint32)0x00000400U,

        /* RAM default value: Section size in bytes (must be multiple of 4). */
        (uint8)0xbaU
    } /* End of Mcu_Ram_ConfigPB[0]. */
                
};





#if (MCU_CONFIGURE_CADDRN == STD_ON)
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_MC_ME_CoreAddressConfigType, MCU_CONST) Mcu_aModeCoreAdressConfigPB0_0[MCU_MC_ME_NUMBER_OF_CORES] = 
{
    
    /* Core Control Register (ME_CADDR1) */
    {
        MC_ME_CADDR1_ADDR32,
        0x00000000U,
        0x00000000U
    },
    
    /* Core Control Register (ME_CADDR2) */
    {
        MC_ME_CADDR2_ADDR32,
        0x00000000U,
        0x00000000U
    },
    
    /* Core Control Register (ME_CADDR3) */
    {
        MC_ME_CADDR3_ADDR32,
        0x00000000U,
        0x00000000U
    }
    
};
#endif /* MCU_CONFIGURE_CADDRN == STD_ON */

/**
* @brief        Definition of MCU mode sections in the configuration structure.
* @details      Specifies the system behaviour during the selected target mode.
*               Configuration set by calling Mcu_SetMode() API.
*/
static CONST( Mcu_ModeConfigType, MCU_CONST) Mcu_aModeConfigPB0[1] = 
{    

    /* Start of Mcu_ModeConfig[0] - DRUN */
    {
        /* The ID for Power Mode configuration. */
        (uint8)0U,

        /* The selected magic target mode. Configure the ME_MCTL[TARGET_MODE] register filed. */
        (MCU_DRUN_MODE),

        /* Specifies the system behaviour for this configured state. */
        (
            /* Configure the MC_<mode>_MC[PDO] register field. */               
            (MC_ME_OUT_POWER_CONTROL_DIS_U32) |

            /* Configure the MC_<mode>_MC[MVRON] register field. */
            (MC_ME_MAIN_VOLTAGE_REG_EN_U32) |

            /* Configure the MC_<mode>_MC[CFLAON] register field. */
            (MC_ME_CODE_FLASH_NORMAL_POWER_U32) |

            /* Configure the MC_<mode>_MC[PLL0ON] register field. */
            (MC_ME_PLL0_EN_U32) | 

            /* Configure the MC_<mode>_MC[SXOSCON] register field. */
            (MC_ME_SXOSC_EN_U32) | 

            /* Configure the MC_<mode>_MC[SIRCON] register field. */
            (MC_ME_SIRC_EN_U32) | 

            /* Configure the MC_<mode>_MC[FXOSCON] register field. */
            (MC_ME_FXOSC_EN_U32) | 
            
            /* Configure the MC_<mode>_MC[FIRCON] register field. */
            (MC_ME_FIRC_EN_U32) | 

            /* Configure the MC_<mode>_MC[SYSCLK] register field. */
            (MC_ME_SYSCLK_PLL0_U32) |
            
            /* configure the MC_<mode>_MC[PWRLVL] register field. */
            MC_ME_POWER_LEVEL_U32( (uint32)0U )
        )
#if (MCU_ENTER_LOW_POWER_MODE == STD_ON)
        /* Fast transition supported (from Low Power to Run mode). */
        ,(boolean)FALSE

        /* Specifies the system behaviour for this RUN state that will be after wakeup (exit from low power mode - STOP0/HALT0). */
        ,(MC_ME_FAST_MODE_CONFIG_DEFAULT_U32)
#endif /* (MCU_ENTER_LOW_POWER_MODE == STD_ON) */
#if ( MCU_CONFIGURE_CADDRN == STD_ON)
        /* configuration of CADDRs */
        ,MCU_MC_ME_NUMBER_OF_CORES
        ,&Mcu_aModeCoreAdressConfigPB0_0
#endif /* MCU_CONFIGURE_CADDRN == STD_ON */

#ifdef MCU_ERR009139_IPV_MC_05000007
#if (MCU_ERR009139_IPV_MC_05000007 == STD_ON)
        /* Configure the GPR_SLEEP register. */
        ,(MC_ME_GPR_SLEEP_DEFAULT_U32)
#endif  /* MCU_ERR009139_IPV_MC_05000007 */
#endif  /* (MCU_ERR009139_IPV_MC_05000007 == STD_ON) */
    }
    /* end of Mcu_aModeConfigPB0[0]. */

};





/**
* @brief        Timing configuration for FLASH hw IP.
* @details      Set the Pipeline/Write/Read wait states for FLASH controller.
*               Configuration set by calling Mcu_InitClock API.
*/
#if (MCU_INIT_CLOCK == STD_ON)
static CONST( Mcu_FLASH_ClockConfigType, MCU_CONST) FLASH_ClockConfigPB0_0 = 
{
    /* Flash Controller timing settings. 
       PFCR1 configuration register: Address Pipelining Control & Read Wait State Control. */
    ( 
        MCU_FLASH_ADDR_PIPELINE_WS_U32((uint32)0) |
        MCU_FLASH_READ_WS_U32((uint32)4)
    )
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */





#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) MC_CGM_aPcsClockConfigPB0_0[MCU_CGM_NUMBER_OF_PCS_REGS] = 
{
    
    {
        MC_CGM_PCS_DIVC1_ADDR32,
        MC_CGM_PCS_DIVC_U32
        (
            MC_CGM_PCS_DIVC_INIT_U32((uint32)0x000003e7U) |
            MC_CGM_PCS_DIVC_RATE_U32((uint32)0x00000000U)
        )
    },
    {
        MC_CGM_PCS_DIVS1_ADDR32,
        MC_CGM_PCS_DIVS_U32((uint32)0x000003e7U)
    },
    {
        MC_CGM_PCS_DIVE1_ADDR32,
        MC_CGM_PCS_DIVE_U32((uint32)0x000003e7U)
    },
    
    {
        MC_CGM_PCS_DIVC2_ADDR32,
        MC_CGM_PCS_DIVC_U32
        (
            MC_CGM_PCS_DIVC_INIT_U32((uint32)0x000003e7U) |
            MC_CGM_PCS_DIVC_RATE_U32((uint32)0x00000000U)
        )
    },
    {
        MC_CGM_PCS_DIVS2_ADDR32,
        MC_CGM_PCS_DIVS_U32((uint32)0x000003e7U)
    },
    {
        MC_CGM_PCS_DIVE2_ADDR32,
        MC_CGM_PCS_DIVE_U32((uint32)0x000003e7U)
    },
    
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */





#if (MCU_INIT_CLOCK == STD_ON)
        
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) MC_CGM_aSystemClockConfigPB0_0[MCU_CGM_NUMBER_OF_SYSTEM_CLOCK_REGS] = 
{
    /* System Clock Divider 0 Configuration. */
    {
        MC_CGM_SC_DC0_ADDR32,
        MC_CGM_SYSCLK_DC0_DIVISOR_U32((uint32)1U)
    },
    /* System Clock Divider 1 Configuration. */
    {
        MC_CGM_SC_DC1_ADDR32,
        MC_CGM_SYSCLK_DC1_DIVISOR_U32((uint32)2U)
    },
    /* System Clock Divider 2 Configuration. */
    {
        MC_CGM_SC_DC2_ADDR32,
        MC_CGM_SYSCLK_DC2_DIVISOR_U32((uint32)4U)
    },
    /* System Clock Divider 5 Configuration. */
    {
        MC_CGM_SC_DC5_ADDR32,
        MC_CGM_SYSCLK_DC5_DIVISOR_U32((uint32)2U)
    }
};
    
#endif /* (MCU_INIT_CLOCK == STD_ON) */





#if (MCU_INIT_CLOCK == STD_ON)
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_MC_CGM_RegisterConfigType, MCU_CONST) MC_CGM_aAuxClockConfigPB0_0[12] = 
{
                /* Disable divider of CLKOUT1 */
    {
        MC_CGM_CLKOUT1_DC_ADDR32,
        MC_CGM_CLKOUT1_DC_U32
        (
            MC_CGM_CLKOUT1_DC_DIS_U32
        )
    },

    /* Select FIRC as source clock of CLKOUT1. */  
    {
        MC_CGM_CLKOUT1_SC_ADDR32,
        MC_CGM_CLKOUT1_U32(MC_CGM_CLKOUT1_SOURCE_FIRC_U32)
    },
        
    /* CLKOUT1 Source Selection. */  
    {
        MC_CGM_CLKOUT1_SC_ADDR32,
        MC_CGM_CLKOUT1_U32(MC_CGM_CLKOUT1_SOURCE_FXOSC_U32)
    },
    
    /* CLKOUT1_DC Configuration. */  
    {
        MC_CGM_CLKOUT1_DC_ADDR32,
        MC_CGM_CLKOUT1_DC_U32
        (            
            MC_CGM_CLKOUT1_DC_EN_U32 |
            MC_CGM_CLKOUT1_DIV_U32((uint32)1U)
        )
    },
    
    
        
    /* Auxiliary Clock2 Source Selection. */
    {
        MC_CGM_AC2_SC_ADDR32,
        MC_CGM_AUXCLK2_U32(MC_CGM_AUXCLK2_SOURCE_F40_U32)
    }

    ,
        
    /* Auxiliary Clock5 Source Selection. */
    {
        MC_CGM_AC5_SC_ADDR32,
        MC_CGM_AUXCLK5_U32(MC_CGM_AUXCLK5_SOURCE_FXOSC_U32)
    }

    ,
            /* Disable Auxiliary Clock6 Divider0 */
    {
        MC_CGM_AC6_DC0_ADDR32,
        MC_CGM_AC6_DC0_U32
        (                        
            MC_CGM_AUXCLK6_DIV0_DIS_U32
        )
    },
    
    /* Select FIRC as source clock of Auxiliary Clock6. */
    {
        MC_CGM_AC6_SC_ADDR32,
        MC_CGM_AUXCLK6_U32(MC_CGM_AUXCLK6_SOURCE_FIRC_U32)
    },
        
    /* Auxiliary Clock6 Source Selection. */
    {
        MC_CGM_AC6_SC_ADDR32,
        MC_CGM_AUXCLK6_U32(MC_CGM_AUXCLK6_SOURCE_F80_U32)
    }

    ,
    {
        MC_CGM_AC6_DC0_ADDR32,
        /* Auxiliary Clock6 Divider0 Configuration. */
        MC_CGM_AC6_DC0_U32
        (                        
            MC_CGM_AUXCLK6_DIV0_EN_U32 |             
            MC_CGM_AUXCLK6_DIV0_U32((uint32)20U)
        )
    }

    ,
        
    /* Auxiliary Clock8 Source Selection. */
    {
        MC_CGM_AC8_SC_ADDR32,
        MC_CGM_AUXCLK8_U32(MC_CGM_AUXCLK8_SOURCE_F40_U32)
    }

    ,
        
    /* Auxiliary Clock9 Source Selection. */
    {
        MC_CGM_AC9_SC_ADDR32,
        MC_CGM_AUXCLK9_U32(MC_CGM_AUXCLK9_SOURCE_FXOSC_U32)
    }
  
};

#endif /* (MCU_INIT_CLOCK == STD_ON) */





#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            MC_CGM IP clock configuration.
* @details          This structure contains information for IRCOSC, XOSC, PLL, Output Clocks, CMUs
*
*/
static CONST( Mcu_MC_CGM_ClockConfigType, MCU_CONST) MC_CGM_ClockConfigPB0_0 = 
{
    /* These clock sources must be powered on for the current clock setting */
    (
        MC_ME_FXOSC_EN_U32 |
        MC_ME_SXOSC_EN_U32 |
        MC_ME_FIRC_EN_U32 |
        MC_ME_SIRC_EN_U32 |
        MC_ME_PLL0_EN_U32
    ),
    
    /* Progressive Clock Switching (CGM_PCS_SDUR[SDUR]) */
    MC_CGM_PCS_SDUR_U8(0x00U),
    
    /* This is used as a mask to set the divider update mask and to triger a divider update after register update */
    MC_CGM_DIV_UPD_TYPE_U32(
        MC_CGM_DIV_UPD_TYPE_AUX6_UPD_TYPE_EN_U32
    ),
    
    /* number of pcs registers unde mcu control */
    MCU_CGM_NUMBER_OF_PCS_REGS,
    /* pcs registers */
     &MC_CGM_aPcsClockConfigPB0_0,
    
    /* number of sys clock regs unde mcu control */
    MCU_CGM_NUMBER_OF_SYSTEM_CLOCK_REGS,
    /* system clock configuration */
    &MC_CGM_aSystemClockConfigPB0_0,
    
    /* number of configurable aux clock regs */
    ((uint8)12U),
    /* auxiliary clock dividers */
    &MC_CGM_aAuxClockConfigPB0_0
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */






#if (MCU_INIT_CLOCK == STD_ON)            
/**
* @brief            SIRC clock configuration.
* @details          This structure contains information for SIRC 128Khz oscillator.
*
*/
static CONST( Mcu_SIRC_ConfigType, MCU_CONST) Mcu_SIRC_ClockConfigPB0_0 = 
{
    /* Control register */
    SIRC_CTL_VALUE_U32( SIRC_CTL_SIRCDIV_VALUE_U32( (uint32)0U ) )
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/







#if (MCU_INIT_CLOCK == STD_ON)            
/**
* @brief            FIRC clock configuration.
* @details          This structure contains information for FIRC 16Mhz oscillator.
*
*/
static CONST( Mcu_FIRC_ConfigType, MCU_CONST) Mcu_FIRC_ClockConfigPB0_0 = 
{
    /* Control register */
    FIRC_CTL_VALUE_U32( FIRC_CTL_FIRCDIV_VALUE_U32( (uint32)0U ) )
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/






            

#if (MCU_INIT_CLOCK == STD_ON)            
/**
* @brief            SXOSC clock configuration.
* @details          This structure contains information for SXOSC 32.767Khz oscillator.
*
*/
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_SXOSC_ConfigType, MCU_CONST) Mcu_SXOSC_ClockConfigPB0_0 = 
{
    /* Control register */
    SXOSC_CTL_VALUE_U32(
        SXOSC_CTL_OSCBYP_OUTPUT_NOT_USED_U32 |
        SXOSC_CTL_ALC_DISABLE_U32 |
        SXOSC_CTL_EOCV_VALUE_U32( (uint32)64U ) |
        SXOSC_CTL_M_OSC_DISABLE_U32 |
        SXOSC_CTL_OSCDIV_VALUE_U32( (uint32)0U )
    )
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/







#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            FXOSC clock configuration.
* @details          This structure contains information for FXOSC.
*
*/
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_FXOSC_ConfigType, MCU_CONST) Mcu_FXOSC_ClockConfigPB0_0 = 
{
    /* Control register */
    FXOSC_CTL_VALUE_U32(
        FXOSC_CTL_OSCBYP_OUTPUT_NOT_USED_U32 |
        FXOSC_CTL_MODE_LCP_U32 |
        FXOSC_CTL_EOCV_VALUE_U32( (uint32)48U ) |
        FXOSC_CTL_M_OSC_DISABLE_U32 |
        FXOSC_CTL_OSCDIV_VALUE_U32( (uint32)0U )
    )
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/





    

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            PLLDIG Registers configuration.
* @details          This structure contains configuration for PLLDIG Registers.
*
*/
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_PLLDIG_RegisterConfigType, MCU_CONST) Mcu_PLLDIG_aRegistersConfigPB0_0[6U] = 
{
    
    
    /* PLL0 configuration */
    {
        PLLDIG_PLL0CAL3_ADDR32,
        MCU_PLLDIG_PLL0CAL3_U32( MCU_PLLDIG_PLL0CAL3_MDFEN_U32( (uint32)4096U ) )
    },
        {
        PLLDIG_PLL0CAL1_ADDR32,
        MCU_PLLDIG_PLL0CAL1_BYPASS_DIS_U32
    },
        {
        PLLDIG_PLL0CR_ADDR32,
        (
            MCU_PLLDIG_PLL0CR_EXPDIE_DIS_U32 |
            MCU_PLLDIG_PLL0CR_LOLIE_DIS_U32 |
            MCU_PLLDIG_PLL0CR_LOLRE_DIS_U32
        )
    },
    {
        PLLDIG_PLL0DV_ADDR32,
        MCU_PLLDIG_PLL0DV_U32(
            MCU_PLLDIG_PLL0DV_RFDPHI1_U32( (uint32)3U ) | 
            MCU_PLLDIG_PLL0DV_RFDPHI_U32( (uint32)2U ) |
            MCU_PLLDIG_PLL0DV_PREDIV_U32( (uint32)1U ) |
            MCU_PLLDIG_PLL0DV_MFD_U32( (uint32)32U )
        )
    },
    {
        PLLDIG_PLL0FM_ADDR32,
        MCU_PLLDIG_PLL0FM_U32(
            MCU_PLLDIG_PLL0FM_SSCGBYP_ENA_U32 |
            MCU_PLLDIG_PLL0FM_MODPRD_U32( (uint32)0U ) |
            MCU_PLLDIG_PLL0FM_INCSTP_U32( (uint32)0U )
        )
    },
    {
        PLLDIG_PLL0FD_ADDR32,
        MCU_PLLDIG_PLL0FD_U32(
            MCU_PLLDIG_PLL0FD_SMDEN_ENA_U32 |
            MCU_PLLDIG_PLL0FD_SDM2_DIS_U32 |
            MCU_PLLDIG_PLL0FD_SDM3_DIS_U32 |
            MCU_PLLDIG_PLL0FD_DTHDIS_U32( (uint32)0U ) |
            MCU_PLLDIG_PLL0FD_MFN_U32( (uint32)0U )
        )
    }
    
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/






#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            PLLDIG clock configuration.
* @details          This structure contains information for PLLDIG PLL0 and FMPLL1.
*
*/
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
static CONST( Mcu_PLLDIG_ConfigType, MCU_CONST) Mcu_PLLDIG_ClockConfigPB0_0 =
{
    /* number of pll regs under mcu control */
     ((uint8)6U),
    
    &Mcu_PLLDIG_aRegistersConfigPB0_0
    
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/





#if (MCU_INIT_CLOCK == STD_ON)
#if (MCU_EMIOS_SUPPORT == STD_ON)
/**
* @brief            eMios Module Configuration.
* @details          This structure contains information for eMios0 and eMios1.
*
*/
/** @violates @ref Mcu_PBcfg_c_REF_3 MISRA 2004 Required Rule 1.4, 31 characters limit.*/
/** @violates @ref Mcu_PBcfg_c_REF_6 MISRA 2004 Required Rule 20.2, The names of standard macros, objects and functions shall not be reused */
static CONST(Mcu_eMios_ConfigType, MCU_CONST) EMIOS_ModuleConfigPB0_0 = 
{
    {
        /* eMios0 configuration */
        EMIOS_MCR_U32
        (
            EMIOS_MCR_MDIS_DIS_U32 |
            EMIOS_MCR_FRZ_ENA_U32 |
            EMIOS_MCR_GTBE_ENA_U32 |
            EMIOS_MCR_ETB_DIS_U32 |
            EMIOS_MCR_GPREN_ENA_U32 |
            EMIOS_MCR_GPRE_U32((uint32)80U)
        ),
        /* eMios1 configuration */
        EMIOS_MCR_U32
        (
            EMIOS_MCR_MDIS_DIS_U32 |
            EMIOS_MCR_FRZ_DIS_U32 |
            EMIOS_MCR_GTBE_ENA_U32 |
            EMIOS_MCR_ETB_DIS_U32 |
            EMIOS_MCR_GPREN_DIS_U32 |
            EMIOS_MCR_GPRE_U32((uint32)1U)
        ),
        /* eMios2 configuration */
        EMIOS_MCR_U32
        (
            EMIOS_MCR_MDIS_DIS_U32 |
            EMIOS_MCR_FRZ_DIS_U32 |
            EMIOS_MCR_GTBE_ENA_U32 |
            EMIOS_MCR_ETB_DIS_U32 |
            EMIOS_MCR_GPREN_DIS_U32 |
            EMIOS_MCR_GPRE_U32((uint32)1U)
        )
    }
};
#endif /* (MCU_EMIOS_SUPPORT == STD_ON) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */





#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            CMU configuration.
* @details          This structure contains information for CMU[n]. 
*                   The number of CMU's is defined in the resource files, 
*
*/
static CONST( Mcu_CMU_ConfigType, MCU_CONST) Mcu_CMU_ConfigPB0_0 =
{
    {

        /* McuClkMonitor_0 config */
        CMU_CSR_U32
        (
            CMU_CSR_CMU_DIS_U32 |
            CMU_CSR_RCDIV_1_U32
        )

    },
    {

        /* McuClkMonitor_0 hfRefr */
        CMU_HFREFR_VALUE_U32
        (
            (uint32)0U
        )

    },
    {

        /* McuClkMonitor_0 lfRefr */
        CMU_LFREFR_VALUE_U32
        (
            (uint32)0U
        )

    }
};
#endif /*(MCU_INIT_CLOCK == STD_ON)*/




#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief        Timing configuration for SRAMC hw IP.
* @details      Set the Read wait states for RAM.
*               Configuration set by calling Mcu_InitClock API.
*/
static CONST( Mcu_PRAM_ClockConfigType, MCU_CONST) SRAMC_ClockConfigPB0_0 = 
{
    /* PRCR1 configuration register. */
    PRAMC_PRCR1_VALUE_U32(
        PRAMC_PRCR1_PRI_VALUE_U32((uint32)2U)|
        PRAMC_PRCR1_P1_BO_ENA_U32|
        PRAMC_PRCR1_P0_BO_ENA_U32|
        PRAMC_PRCR1_FT_ENA_U32
    ),
    PRAMC_PRCR1_VALUE_U32(
        PRAMC_PRCR1_P0_BO_ENA_U32|
        PRAMC_PRCR1_FT_ENA_U32
    ),
    PRAMC_PRCR1_VALUE_U32(
        PRAMC_PRCR1_P0_BO_ENA_U32|
        PRAMC_PRCR1_FT_ENA_U32
    )
};
#endif /* (MCU_INIT_CLOCK == STD_ON) */




#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief          Initialization clock data.
* @details        Static configuration realized by calling Mcu_InitClock() API.
*
*/
static CONST( Mcu_ClockConfigType, MCU_CONST) Mcu_aClockConfigPB0[1] =  
{

    /* Start of Mcu_ClockConfig[0]. */
    {

        /* ID Clock Configuration. */
        (uint8)0U,

        /* Globally enable/disable SCM, loss of clock and loss of lock notification. */
        (MCU_CLK_NOTIF_DIS),
        
        /* System Clock Selection. 
           This affect the Mode settings from MC_ME IP. */
        (
MC_ME_SYSCLK_PLL0_U32 | MC_ME_PLL0_EN_U32 
        ),

        /* MC_CGM IP Clock settings. */
        &MC_CGM_ClockConfigPB0_0,
        
        /* PLLDIG IP Clock settings. */
        &Mcu_PLLDIG_ClockConfigPB0_0,
                
#if (MCU_EMIOS_SUPPORT == STD_ON)
        /* eMios Module settings. */
        &EMIOS_ModuleConfigPB0_0,
#endif
        /* CMU IP Clock settings. */
        &Mcu_CMU_ConfigPB0_0,
        
        /* FIRC IP Clock settings. */
        
        &Mcu_FIRC_ClockConfigPB0_0,
        
        
        /* SIRC IP Clock settings. */
        
        &Mcu_SIRC_ClockConfigPB0_0,
        
        
        /* FXOSC IP Clock settings. */
        
        &Mcu_FXOSC_ClockConfigPB0_0,
        
        
        /* SXOSC IP Clock settings. */
        
        &Mcu_SXOSC_ClockConfigPB0_0,
        
        
#if (MCU_SRAMC_SUPPORT == STD_ON)
        /* SRAMC IP Clock settings. */
         &SRAMC_ClockConfigPB0_0,
#endif /* (MCU_SRAMC_SUPPORT == STD_ON) */

        /* FLASH IP Clock settings. */
        &FLASH_ClockConfigPB0_0,
        
        ( MCU_IPW_FIRC_UNDER_MCU_CONTROL | 
         MCU_IPW_SIRC_UNDER_MCU_CONTROL | 
         MCU_IPW_SXOSC_UNDER_MCU_CONTROL | 
         MCU_IPW_FXOSC_UNDER_MCU_CONTROL | 
         MCU_IPW_PLL0_UNDER_MCU_CONTROL )
        
    }         /* end of Mcu_ClockConfig[0] */

};
#endif /* (MCU_INIT_CLOCK == STD_ON) */




/**
* @brief          Initialization data for MC_RGM hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_MC_RGM_ConfigType, MCU_CONST) MC_RGM_ConfigPB0 =
{
#if (MCU_PERFORM_RESET_API == STD_ON)
    /* MC_ResetType: Functional vs Destructive. */
    (MCU_FUNC_RESET),
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */
    /* destructive reset config */
    /* MCRGM_Dest_ResetOpt: RGM_DERD Register Configuration. */
    (uint32)0x00U, /* unused */
    /* MCRGM_Dest_SafeIsrOpt: RGM_DEAR Register Configuration. */
    (uint32)0x00U, /* unused */
    /* MCRGM_Dest_ExtPinReset: RGM_DBRE Register Configuration. */
    MC_RGM_DBRE_U32( (uint32)0x00U ),
    
    /* functional reset config */
    /* Func_ResetOpt: FERD Register Configuration. */
    MC_RGM_FERD_U32
    (
        (MC_RGM_LVD_LV_PD2_COLD_EVENT_RESET_U32) |
        (MC_RGM_HVD_LV_COLD_EVENT_RESET_U32) |
        (MC_RGM_LVD_IO_A_HI_EVENT_SAFE_INT_U32) |
        (MC_RGM_Z2_DBG_EVENT_RESET_U32) |
        (MC_RGM_Z4B_DBG_EVENT_RESET_U32) |
        (MC_RGM_Z4A_DBG_EVENT_SAFE_INT_U32) |
        (MC_RGM_CMU_OLR_EVENT_SAFE_INT_U32) |
        (MC_RGM_JTAG_FUNC_EVENT_SAFE_INT_U32) |
        (MC_RGM_NMI_WKPU_EVENT_SAFE_INT_U32)
        
    ),
    /* MCRGM_Func_SafeIsrOpt: RGM_FEAR Register Configuration. */
    MC_RGM_FEAR_U32
    (
        (MC_RGM_LVW_PD2_COLD_EVENT_SAFE_U32) |
        (MC_RGM_HVD_LV_COLD_EVENT_SAFE_U32) |
        (MC_RGM_LVD_IO_A_HI_EVENT_SAFE_U32) |
        (MC_RGM_Z2_DBG_EVENT_SAFE_U32) |
        (MC_RGM_Z4B_DBG_EVENT_SAFE_U32) |
        (MC_RGM_Z4A_DBG_EVENT_SAFE_U32) |
        (MC_RGM_CMU_OLR_EVENT_SAFE_U32) |
        (MC_RGM_JTAG_FUNC_EVENT_SAFE_U32) |
        (MC_RGM_NMI_WKPU_EVENT_SAFE_U32)
    ),
    /* MCRGM_Func_ExtPinReset: RGM_FBRE Register Configuration. */
    MC_RGM_FBRE_U32( 
        (MC_RGM_LVD_LV_PD2_COLD_ASSERT_ESR0_EN_U32) |
        (MC_RGM_Z2_DBG_ASSERT_ESR0_EN_U32) |
        (MC_RGM_Z4B_DBG_ASSERT_ESR0_EN_U32) |
        (MC_RGM_Z4A_DBG_ASSERT_ESR0_EN_U32) |
        (MC_RGM_FCCU_SHORT_ASSERT_ESR0_EN_U32) |
        (MC_RGM_FCCU_LONG_ASSERT_ESR0_EN_U32) |
        (MC_RGM_CMU_OLR_ASSERT_ESR0_EN_U32) |
        (MC_RGM_JTAG_FUNC_ASSERT_ESR0_EN_U32) |
        (MC_RGM_NMI_WKPU_ASSERT_ESR0_EN_U32) |
        (MC_RGM_SOFT_FUNC_ASSERT_ESR0_EN_U32) |
        (MC_RGM_HSM_FUNC_ASSERT_ESR0_EN_U32)
    ),
    /* MCRGM_Func_Phase1or3Opt: RGM_FESS Register Configuration. */
    MC_RGM_FESS_U32
    (
        (MC_RGM_LVD_LV_PD2_COLD_PHASE1_U32) |
        (MC_RGM_HVD_LV_COLD_PHASE1_U32) |
        (MC_RGM_LVD_IO_A_HI_PHASE1_U32) |
        (MC_RGM_Z2_DBG_PHASE3_U32) |
        (MC_RGM_Z4B_DBG_PHASE3_U32) |
        (MC_RGM_Z4A_DBG_PHASE3_U32) |
        (MC_RGM_CMU_OLR_PHASE1_U32) |
        (MC_RGM_JTAG_FUNC_RESET_PHASE1_U32) |
        (MC_RGM_NMI_WKPU_PHASE1_U32) | 
        (MC_RGM_SOFT_FUNC_RESET_PHASE1_U32) |      
        (MC_RGM_EXR_RESET_PHASE1_U32)
               
    ),

    /* MCRGM_Threshold_Reset: RGM_FRET Register Configuration. */
    MC_RGM_FRET_U8((uint8)15U),
    
    /* Destructive Reset Escalation Threshold Register */
    MC_RGM_DRET_U8((uint8)15U)
};




static CONST( Mcu_MC_ME_CoreAddressConfigType, MCU_CONST) MC_ME_aCaddrConfigPB0[MCU_MC_ME_NUMBER_OF_CORES] = 
{
    /* Core Control Register (ME_CADDR1) */
    {
        MC_ME_CADDR1_ADDR32,
        MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
             
            MC_ME_CADDR_RESET_DISABLE_U32
        )
    },
    
    /* Core Control Register (ME_CADDR2) */
    {
        MC_ME_CADDR2_ADDR32,
         MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
            
            MC_ME_CADDR_RESET_DISABLE_U32
        )
    },
    
    /* Core Control Register (ME_CADDR3) */
    {
        MC_ME_CADDR3_ADDR32,
        MC_ME_CADDR_RMC_MASK32,
        MC_ME_CADDR_ENABLE_U32
        (
            
            MC_ME_CADDR_RESET_DISABLE_U32
        )
    }
};

static CONST( Mcu_MC_ME_CoreConfigType, MCU_CONST) MC_ME_aCctlConfigPB0[MCU_MC_ME_NUMBER_OF_CORES] = 
{
    /* Core Control Register (ME_CCTL1) */
    {
        MC_ME_CCTL1_ADDR32,
        MC_ME_CCTL_ENABLE_U16
        ( 
            (MC_ME_CCTL_RUN3_ON_U16) |
            (MC_ME_CCTL_RUN2_ON_U16) |
            (MC_ME_CCTL_RUN1_ON_U16) |
            (MC_ME_CCTL_RUN0_ON_U16) |
            (MC_ME_CCTL_DRUN_ON_U16) |
            (MC_ME_CCTL_SAFE_ON_U16)
        )
    },
    
    /* Core Control Register (ME_CCTL2) */
    {
        MC_ME_CCTL2_ADDR32,
        MC_ME_CCTL_ENABLE_U16
        ( 
            (MC_ME_CCTL_RUN3_OFF_U16) |
            (MC_ME_CCTL_RUN2_OFF_U16) |
            (MC_ME_CCTL_RUN1_OFF_U16) |
            (MC_ME_CCTL_RUN0_OFF_U16) |
            (MC_ME_CCTL_DRUN_OFF_U16) |
            (MC_ME_CCTL_SAFE_OFF_U16)
        )
    },
    
    /* Core Control Register (ME_CCTL3) */
    {
        MC_ME_CCTL3_ADDR32,
        MC_ME_CCTL_ENABLE_U16
        ( 
            (MC_ME_CCTL_RUN3_OFF_U16) |
            (MC_ME_CCTL_RUN2_OFF_U16) |
            (MC_ME_CCTL_RUN1_OFF_U16) |
            (MC_ME_CCTL_RUN0_OFF_U16) |
            (MC_ME_CCTL_DRUN_OFF_U16) |
            (MC_ME_CCTL_SAFE_OFF_U16)
        )
    }
};

static CONST( Mcu_MC_ME_RegisterConfigType, MCU_CONST) MC_ME_aPCTLConfigPB0[MCU_MC_ME_NUMBER_OF_PCTL_REGS] = 
{

    /* PCTL0_BCTU */
    {
        MC_ME_PCTL0_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL1_eMIOS_0 */
    {
        MC_ME_PCTL1_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL2_eMIOS_1 */
    {
        MC_ME_PCTL2_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL3_eMIOS_2 */
    {
        MC_ME_PCTL3_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL4_USB_OTG */
    {
        MC_ME_PCTL4_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL5_USB_SPH */
    {
        MC_ME_PCTL5_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL6_MLB */
    {
        MC_ME_PCTL6_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL7_SDHC */
    {
        MC_ME_PCTL7_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL10_SAI0 */
    {
        MC_ME_PCTL10_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL11_SAI1 */
    {
        MC_ME_PCTL11_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL12_SAI2 */
    {
        MC_ME_PCTL12_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL15_ENET */
    {
        MC_ME_PCTL15_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL20_CMP_0 */
    {
        MC_ME_PCTL20_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL21_CMP_1 */
    {
        MC_ME_PCTL21_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL22_CMP_2 */
    {
        MC_ME_PCTL22_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL24_ADC_0 */
    {
        MC_ME_PCTL24_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL25_ADC_1 */
    {
        MC_ME_PCTL25_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL28_FlexRay */
    {
        MC_ME_PCTL28_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL30_IIC_0 */
    {
        MC_ME_PCTL30_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL31_IIC_1 */
    {
        MC_ME_PCTL31_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL32_IIC_2 */
    {
        MC_ME_PCTL32_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL33_IIC_3 */
    {
        MC_ME_PCTL33_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL40_DSPI_0 */
    {
        MC_ME_PCTL40_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL41_DSPI_1 */
    {
        MC_ME_PCTL41_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL42_DSPI_3 */
    {
        MC_ME_PCTL42_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL43_DSPI_4 */
    {
        MC_ME_PCTL43_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL50_LIN_0 */
    {
        MC_ME_PCTL50_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL51_LIN_1 */
    {
        MC_ME_PCTL51_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL52_LIN_2 */
    {
        MC_ME_PCTL52_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL53_LIN_3 */
    {
        MC_ME_PCTL53_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL54_LIN_4 */
    {
        MC_ME_PCTL54_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL55_LIN_5 */
    {
        MC_ME_PCTL55_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL56_LIN_6 */
    {
        MC_ME_PCTL56_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL57_LIN_7 */
    {
        MC_ME_PCTL57_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL58_LIN_8 */
    {
        MC_ME_PCTL58_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL59_LIN_9 */
    {
        MC_ME_PCTL59_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL60_LIN_10 */
    {
        MC_ME_PCTL60_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL61_LIN_11 */
    {
        MC_ME_PCTL61_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL62_LIN_12 */
    {
        MC_ME_PCTL62_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL63_LIN_13 */
    {
        MC_ME_PCTL63_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL64_LIN_14 */
    {
        MC_ME_PCTL64_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL65_LIN_15 */
    {
        MC_ME_PCTL65_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL66_LIN_16 */
    {
        MC_ME_PCTL66_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL67_LIN_17 */
    {
        MC_ME_PCTL67_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL70_FLEXCAN_0 */
    {
        MC_ME_PCTL70_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL71_FLEXCAN_1 */
    {
        MC_ME_PCTL71_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL72_FLEXCAN_2 */
    {
        MC_ME_PCTL72_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL73_FLEXCAN_3 */
    {
        MC_ME_PCTL73_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL74_FLEXCAN_4 */
    {
        MC_ME_PCTL74_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL75_FLEXCAN_5 */
    {
        MC_ME_PCTL75_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL76_FLEXCAN_6 */
    {
        MC_ME_PCTL76_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL77_FLEXCAN_7 */
    {
        MC_ME_PCTL77_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL82_JDC */
    {
        MC_ME_PCTL82_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL83_MEMU_0 */
    {
        MC_ME_PCTL83_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL84_CRC */
    {
        MC_ME_PCTL84_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL90_DMAMUX */
    {
        MC_ME_PCTL90_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL91_PIT_RTI_0 */
    {
        MC_ME_PCTL91_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL93_WKPU */
    {
        MC_ME_PCTL93_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL96_SPI0 */
    {
        MC_ME_PCTL96_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL97_SPI1 */
    {
        MC_ME_PCTL97_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL98_SPI2 */
    {
        MC_ME_PCTL98_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL99_SPI3 */
    {
        MC_ME_PCTL99_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL100_SPI4 */
    {
        MC_ME_PCTL100_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL101_SPI5 */
    {
        MC_ME_PCTL101_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL102_RTC_API */
    {
        MC_ME_PCTL102_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    },

    /* PCTL105_MEMU_1 */
    {
        MC_ME_PCTL105_ADDR32,
        MC_ME_PCTLn_U8(MC_ME_PCTL_DBG_FRZ_DIS_U8, MC_ME_CFG_RUN_PC0_U8, MC_ME_CFG_LP_PC0_U8)
    }

};
/**
* @brief            Configuration of MC_ME hw IP.
* @details          This data configuration is set at module initialization phase.
*
*/
static CONST( Mcu_MC_ME_ConfigType, MCU_CONST) MC_ME_ConfigPB0 =
{
    
    /* ME_RUN_PC0: Run Config Mode0 : McuRunConfig_0. */
    (
        (MC_ME_RUN3_CLK_ACTIVE_U32) |
        (MC_ME_RUN2_CLK_ACTIVE_U32) |
        (MC_ME_RUN1_CLK_ACTIVE_U32) |
        (MC_ME_RUN0_CLK_ACTIVE_U32) |
        (MC_ME_DRUN_CLK_ACTIVE_U32) |
        (MC_ME_SAFE_CLK_ACTIVE_U32) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        
    /* ME_RUN_PC1: Run Config Mode1 : McuRunConfig_1. */
    (
        (MC_ME_RUN3_CLK_ACTIVE_U32) |
        (MC_ME_RUN2_CLK_ACTIVE_U32) |
        (MC_ME_RUN1_CLK_ACTIVE_U32) |
        (MC_ME_RUN0_CLK_ACTIVE_U32) |
        (MC_ME_DRUN_CLK_ACTIVE_U32) |
        (MC_ME_SAFE_CLK_ACTIVE_U32) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        
    /* ME_RUN_PC2: Run Config Mode2 : McuRunConfig_2. */
    (
        (MC_ME_RUN3_CLK_ACTIVE_U32) |
        (MC_ME_RUN2_CLK_ACTIVE_U32) |
        (MC_ME_RUN1_CLK_ACTIVE_U32) |
        (MC_ME_RUN0_CLK_ACTIVE_U32) |
        (MC_ME_DRUN_CLK_ACTIVE_U32) |
        (MC_ME_SAFE_CLK_ACTIVE_U32) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        
    /* ME_RUN_PC3: Run Config Mode3 : McuRunConfig_3. */
    (
        (MC_ME_RUN3_CLK_ACTIVE_U32) |
        (MC_ME_RUN2_CLK_ACTIVE_U32) |
        (MC_ME_RUN1_CLK_ACTIVE_U32) |
        (MC_ME_RUN0_CLK_ACTIVE_U32) |
        (MC_ME_DRUN_CLK_ACTIVE_U32) |
        (MC_ME_SAFE_CLK_ACTIVE_U32) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        
    /* ME_RUN_PC4: Run Config Mode4 : McuRunConfig_4. */
    (
        (MC_ME_RUN3_CLK_ACTIVE_U32) |
        (MC_ME_RUN2_CLK_ACTIVE_U32) |
        (MC_ME_RUN1_CLK_ACTIVE_U32) |
        (MC_ME_RUN0_CLK_ACTIVE_U32) |
        (MC_ME_DRUN_CLK_ACTIVE_U32) |
        (MC_ME_SAFE_CLK_ACTIVE_U32) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        
    /* ME_RUN_PC5: Run Config Mode5 : McuRunConfig_5. */
    (
        (MC_ME_RUN3_CLK_ACTIVE_U32) |
        (MC_ME_RUN2_CLK_ACTIVE_U32) |
        (MC_ME_RUN1_CLK_ACTIVE_U32) |
        (MC_ME_RUN0_CLK_ACTIVE_U32) |
        (MC_ME_DRUN_CLK_ACTIVE_U32) |
        (MC_ME_SAFE_CLK_ACTIVE_U32) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        
    /* ME_RUN_PC6: Run Config Mode6 : McuRunConfig_6. */
    (
        (MC_ME_RUN3_CLK_ACTIVE_U32) |
        (MC_ME_RUN2_CLK_ACTIVE_U32) |
        (MC_ME_RUN1_CLK_ACTIVE_U32) |
        (MC_ME_RUN0_CLK_ACTIVE_U32) |
        (MC_ME_DRUN_CLK_ACTIVE_U32) |
        (MC_ME_SAFE_CLK_ACTIVE_U32) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        
    /* ME_RUN_PC7: Run Config Mode7 : McuRunConfig_7. */
    (
        (MC_ME_RUN3_CLK_ACTIVE_U32) |
        (MC_ME_RUN2_CLK_ACTIVE_U32) |
        (MC_ME_RUN1_CLK_ACTIVE_U32) |
        (MC_ME_RUN0_CLK_ACTIVE_U32) |
        (MC_ME_DRUN_CLK_ACTIVE_U32) |
        (MC_ME_SAFE_CLK_ACTIVE_U32) |
        (MC_ME_TEST_CLK_GATED_U32)
    ),
        
    /* ME_LP_PC0: Low Power Mode 0. */
    (
        (MC_ME_STOP0_CLK_ACTIVE_U32) |
        (MC_ME_STBY0_CLK_GATED_U32)
    ),

    /* ME_LP_PC1: Low Power Mode 1. */
    (
        (MC_ME_STOP0_CLK_GATED_U32) |
        (MC_ME_STBY0_CLK_GATED_U32)
    ),

    /* ME_LP_PC2: Low Power Mode 2. */
    (
        (MC_ME_STOP0_CLK_GATED_U32) |
        (MC_ME_STBY0_CLK_GATED_U32)
    ),

    /* ME_LP_PC3: Low Power Mode 3. */
    (
        (MC_ME_STOP0_CLK_GATED_U32) |
        (MC_ME_STBY0_CLK_GATED_U32)
    ),

    /* ME_LP_PC4: Low Power Mode 4. */
    (
        (MC_ME_STOP0_CLK_GATED_U32) |
        (MC_ME_STBY0_CLK_GATED_U32)
    ),

    /* ME_LP_PC5: Low Power Mode 5. */
    (
        (MC_ME_STOP0_CLK_GATED_U32) |
        (MC_ME_STBY0_CLK_GATED_U32)
    ),

    /* ME_LP_PC6: Low Power Mode 6. */
    (
        (MC_ME_STOP0_CLK_GATED_U32) |
        (MC_ME_STBY0_CLK_GATED_U32)
    ),

    /* ME_LP_PC7: Low Power Mode 7. */
    (
        (MC_ME_STOP0_CLK_GATED_U32) |
        (MC_ME_STBY0_CLK_GATED_U32)
    ),

    MCU_MC_ME_NUMBER_OF_PCTL_REGS,
    &MC_ME_aPCTLConfigPB0,

    /* Modes Enabled according to ME_ME details. RUN0/DRUN/SAFE/RESET/RESET_DEST are always ON. Configuration of ME_ME register. */
    MC_ME_ME_ENABLE
    (
        MC_ME_STOP0_MODE_DIS_U32 |
        MC_ME_STBY0_MODE_DIS_U32 |
        MC_ME_RUN3_MODE_EN_U32 |
        MC_ME_RUN2_MODE_EN_U32 |
        MC_ME_RUN1_MODE_EN_U32 |
        MC_ME_TEST_MODE_DIS_U32
    ),

    /* Enable Mode Transition Interrupts: Configure the ME_IM Register. */
    MC_ME_INT_ENABLE
    (
        MC_ME_TRANSITION_MODE_INT_DIS_U32 |
        MC_ME_SAFE_MODE_INT_DIS_U32 |
        MC_ME_INVALID_MODE_INT_DIS_U32 |
        MC_ME_INVALID_MODE_CFG_INT_DIS_U32 |
        MC_ME_INVALID_MODE_CLK_INT_DIS_U32 |
        MC_ME_INVALID_MODE_CPU_INT_DIS_U32
    ),

    /* configuration of CADDRs */
    MCU_MC_ME_NUMBER_OF_CORES,
    &MC_ME_aCaddrConfigPB0,
    
    /* configuration of CCTLs */
    MCU_MC_ME_NUMBER_OF_CORES,
    &MC_ME_aCctlConfigPB0
};








/**
* @brief            Platform FLASH hw IP configuration.
* @details          Configure prefetch mechanism, buffers, access protection.
*                   Configuration set by calling Mcu_Init API.
*/
static CONST( Mcu_FLASH_ConfigType, MCU_CONST) FLASH_ConfigPB0 =
{
    /* Platform Flash Configuration Register 1 (PFCR1). */
    MCU_FLASH_PFCR1_U32
    (
        MCU_FLASH_P0_MASTER15_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER14_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER13_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER12_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER11_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER10_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER9_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER8_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER7_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER6_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER5_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER4_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER3_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER2_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER1_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_MASTER0_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_DATA_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_INSTR_PREFETCH_DIS_U32 |
        MCU_FLASH_P0_PFLIM_U32( (uint32)0U ) |
        MCU_FLASH_P0_BUFFER_EN_U32
    ),
    
    /* Platform Flash Configuration Register 2 (PFCR2). */
    MCU_FLASH_PFCR2_U32
    (
        MCU_FLASH_P1_MASTER15_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER14_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER13_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER12_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER11_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER10_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER9_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER8_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER7_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER6_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER5_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER4_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER3_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER2_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER1_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_MASTER0_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_DATA_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_INSTR_PREFETCH_DIS_U32 |
        MCU_FLASH_P1_PFLIM_U32((uint32)0U) |
        MCU_FLASH_P1_BUFFER_EN_U32
    ),
    
    /* Platform Flash Configuration Register 3 (PFCR3). */
    MCU_FLASH_PFCR3_U32(
        MCU_FLASH_P0_WCFG_U32( (uint32)0U ) |
        MCU_FLASH_P1_WCFG_U32( (uint32)0U ) |
        MCU_FLASH_P2_WCFG_U32( (uint32)0U ) |
        MCU_FLASH_BAF_EN_U32 |
        MCU_FLASH_ARBM_WCFG_U32( (uint32)0U )
    ),
    /* Platform Flash Configuration Register 3 (PFCR3). */
    MCU_FLASH_PFCR4_U32(
        MCU_FLASH_P2_MASTER15_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER14_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER13_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER12_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER11_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER10_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER9_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER8_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER7_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER6_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER5_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER4_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER3_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER2_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER1_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_MASTER0_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_DATA_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_INSTR_PREFETCH_DIS_U32 |
        MCU_FLASH_P2_PFLIM_U32((uint32)0U) |
        MCU_FLASH_P2_BUFFER_EN_U32
    ),
    
    /* Platform Flash Access Protection Register (PFAPR). */
    MCU_FLASH_PFAPR_U32
    (
        MCU_FLASH_M0AP_U32( (uint32)3U ) |
        MCU_FLASH_M1AP_U32( (uint32)3U ) |
        MCU_FLASH_M2AP_U32( (uint32)3U ) |
        MCU_FLASH_M3AP_U32( (uint32)3U ) |
        MCU_FLASH_M4AP_U32( (uint32)3U ) |
        MCU_FLASH_M5AP_U32( (uint32)3U ) |
        MCU_FLASH_M6AP_U32( (uint32)3U ) |
        MCU_FLASH_M7AP_U32( (uint32)3U ) |
        MCU_FLASH_M8AP_U32( (uint32)3U ) |
        MCU_FLASH_M9AP_U32( (uint32)3U ) |
        MCU_FLASH_M10AP_U32( (uint32)3U ) |
        MCU_FLASH_M11AP_U32( (uint32)3U ) |
        MCU_FLASH_M12AP_U32( (uint32)3U ) |
        MCU_FLASH_M13AP_U32( (uint32)3U ) |
        MCU_FLASH_M14AP_U32( (uint32)3U ) |
        MCU_FLASH_M15AP_U32( (uint32)3U )
    )
};




/**
* @brief          Initialization data for PMCDIG hw IP.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_PMCDIG_ConfigType, MCU_CONST) PMCDIG_ConfigPB0 =
{
    /* RAM Domain Configuration Register */
    PMCDIG_RDCR_VALUE_U32(
        PMCDIG_RDCR_MEM_SLEEP_DISABLE_U32 |
        PMCDIG_RDCR_PAD_KEEP_DISABLE_U32 |
        PMCDIG_RDCR_RD64_RET_DISABLE_U32 |
        PMCDIG_RDCR_RD128_RET_DISABLE_U32 |
        PMCDIG_RDCR_RD256_RET_DISABLE_U32
    ),
    /* MISC Control Register */
    PMCDIG_MCR_VALUE_U32(
        PMCDIG_MCR_FLASH_LP_FAST_EXIT_DIS_U32 |
        PMCDIG_MCR_LVD_PD2_COLD_REE_DIS_U32 |
        PMCDIG_RDCR_MEM_SLEEP_DISABLE_U32 |
        PMCDIG_MCR_LVD_IO_HI_REE_DISABLE_U32
    )
};




/**
* @brief          Initialization data for different hw IPs.
* @details        Static configuration realized at statup by calling Mcu_Init() API.
*
*/
static CONST( Mcu_HwIPsConfigType, MCU_CONST) Mcu_HwIPsConfigPB0 =
{
    /* Configuration for MC_ME (Mode Entry Module) hardware IP. */
    &MC_ME_ConfigPB0,

    /* Configuration for MC_RGM (Reset Generation Module) hardware IP. */
    &MC_RGM_ConfigPB0,

    /* Configuration for FLASH (Flash Memory) hardware IP. */
    &FLASH_ConfigPB0,
    
    /* Configuration for PMCDIG (Power Management Controller) hardware IP. */
    &PMCDIG_ConfigPB0
};




/**
* @brief          Initialization data for the MCU driver.
* @details        A pointer to such a structure is provided to the MCU initialization routines for configuration.
*
*/
/** @violates @ref Mcu_PBcfg_c_REF_7 MISRA 2004 Required Rule 8.10, external linkage ... */
CONST(Mcu_ConfigType, MCU_CONST) McuConfigPB =
{
#if (MCU_DISABLE_DEM_REPORT_ERROR_STATUS == STD_OFF)
    /* Pointer to DEM error reporting configurations. */
    &Mcu_Dem_Config,
#endif

    /* Number of RAM Sections configurations. */
    (Mcu_RamSectionType)1U,

    /* Number of Power Modes configurations. */
    (Mcu_ModeType)1U,

#if (MCU_INIT_CLOCK == STD_ON)
    /* Number of Clock Setting configurations. */
    (Mcu_ClockType)1U,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#ifndef MCU_MAX_NORAMCONFIGS
    /* Pointer to RAM Section configurations. */
    &Mcu_aRamConfigPB0,
#endif

    /* Pointer to Power Mode configurations. */
    &Mcu_aModeConfigPB0,

#if (MCU_LPU_SUPPORT == STD_ON)
    /* Pointer to Low Power Mode configurations. */
    (NULL_PTR),
#endif
    
#if (MCU_INIT_CLOCK == STD_ON)
    /* Pointer to Clock configurations. */
    &Mcu_aClockConfigPB0,
#endif /* (MCU_INIT_CLOCK == STD_ON) */

    /* Pointer to Low Level Mcu driver configuration. */
    &Mcu_HwIPsConfigPB0
};




#define MCU_STOP_SEC_CONFIG_DATA_UNSPECIFIED
/**
* @violates @ref Mcu_PBcfg_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_PBcfg_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


#ifdef __cplusplus
}
#endif

/** @} */
