/**
*   @file    Mcu_IPW.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Mcu - Middle layer implementation.
*   @details Layer that implements the wrapper for routing data from/to external interface
*            to IP layer.
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
* @section Mcu_IPW_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Repeated include file MemMap.h,  Precautions shall be
* taken in order to prevent the contents of a header file being included twice This is not a violation
* since all header files are protected against multiple inclusions
*
* @section Mcu_IPW_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, only preprocessor statements and comments
* before '#include' MemMap.h included after each section define in order to set the current memory section
*
* @section Mcu_IPW_c_REF_3
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall be checked to ensure
* that 31 character significance and case sensitivity are supported for external identifiers.
* The defines are validated.
*
* @section Mcu_IPW_c_REF_4
* Violates MISRA 2004 Required Rule 11.1, Conversions shall not be performed between a
* pointer to a function and a type other than an integral type. This violation is due to the
* pointer arithmetic used to write/ read the data to/from the registers
*
* @section Mcu_IPW_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required
* This warning appears when defining functions that will be used by the upper layers.
*
* @section Mcu_IPW_c_REF_6
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/* Header file with prototype functions defines in this layer. */
#include "Mcu_IPW.h"
#include "Mcu_IPW_Irq.h"

/* Header files that are called from IPW layer. */
#include "Mcu_FIRC.h"
#include "Mcu_FXOSC.h"
#include "Mcu_MC_CGM.h"
#include "Mcu_MC_ME.h"
#include "Mcu_MC_RGM.h"
#include "Mcu_MC_PCU.h"
#include "Mcu_CMU.h"
#include "Mcu_SIRC.h"
#include "Mcu_SXOSC.h"
#include "Mcu_STCU.h"
#include "Mcu_SSCM.h"
#if (MCU_SRAMC_SUPPORT == STD_ON)
  #include "Mcu_PRAM.h"
#endif /* (MCU_SRAMC_SUPPORT == STD_ON) */
#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
  #include "Mcu_FLASH.h"
#endif
#include "Mcu_PLLDIG.h"
#include "Mcu_PMCDIG.h"
#include "Mcu_SIUL2.h"
#include "Mcu_eMios.h"
#if (MCU_LPU_SUPPORT == STD_ON)
#include "Mcu_LPU.h"
#endif


/**
* @brief    Detected development errors shall be reported to the Det_ReportError service of the
*           Development Error Tracer (DET) if the pre-processor switch McuDevErrorDetect is set
*           The detection of development errors is configurable (ON / OFF) at precompile time.
*           The switch McuDevErrorDetect (see chapter 10) shall activate or deactivate the detection
*           of all development errors.
*           Det_ReportError - Service to report development errors.
*
*/
#if (MCU_DEV_ERROR_DETECT == STD_ON)
    #include "Det.h"
#endif


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define MCU_IPW_VENDOR_ID_C                     43
/** @violates @ref Mcu_IPW_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_AR_RELEASE_MAJOR_VERSION_C      4
/** @violates @ref Mcu_IPW_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_AR_RELEASE_MINOR_VERSION_C      2
/** @violates @ref Mcu_IPW_c_REF_3 MISRA 2004 Rule 1.4, The compiler/linker shall be checked to ensure that 31 character
*   significance and case sensitivity are supported for external identifiers. */
#define MCU_IPW_AR_RELEASE_REVISION_VERSION_C   2
#define MCU_IPW_SW_MAJOR_VERSION_C              1
#define MCU_IPW_SW_MINOR_VERSION_C              0
#define MCU_IPW_SW_PATCH_VERSION_C              0


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/**
* @brief            The MCU module's implementer shall avoid the integration of incompatible files.
*/
/* Check if current file and Mcu_IPW header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_IPW_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_IPW.h have different vendor ids"
#endif
/* Check if current file and Mcu_IPW header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_IPW_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_IPW_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_IPW_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_IPW.h are different"
#endif
/* Check if current file and Mcu_IPW header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_IPW_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_IPW_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_IPW_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_IPW.h are different"
#endif

/* Check if current file and Mcu_IPW_Irq header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_IPW_IRQ_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_IPW_Irq.h have different vendor ids"
#endif
/* Check if current file and Mcu_IPW_Irq header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_IPW_IRQ_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_IPW_IRQ_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_IPW_IRQ_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_IPW_Irq.h are different"
#endif
/* Check if current file and Mcu_IPW_Irq header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_IPW_IRQ_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_IPW_IRQ_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_IPW_IRQ_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_IPW_Irq.h are different"
#endif

/* Check if current file and Mcu_FIRC header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_FIRC_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_FIRC.h have different vendor ids"
#endif

/* Check if current file and Mcu_FIRC header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_FIRC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_FIRC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_FIRC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_FIRC.h are different"
#endif

/* Check if current file and Mcu_FIRC header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_FIRC_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_FIRC_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_FIRC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_FIRC.h are different"
#endif

/* Check if current file and Mcu_FXOSC header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_FXOSC_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_FXOSC.h have different vendor ids"
#endif

/* Check if current file and Mcu_FXOSC header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_FXOSC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_FXOSC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_FXOSC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_FXOSC.h are different"
#endif

/* Check if current file and Mcu_FXOSC header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_FXOSC_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_FXOSC_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_FXOSC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_FXOSC.h are different"
#endif

/* Check if current file and Mcu_MC_CGM header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_MC_CGM_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_MC_CGM.h have different vendor ids"
#endif

/* Check if current file and Mcu_MC_CGM header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_CGM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_CGM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_MC_CGM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_MC_CGM.h are different"
#endif

/* Check if current file and Mcu_MC_CGM header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_MC_CGM_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_MC_CGM_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_MC_CGM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_MC_CGM.h are different"
#endif

/* Check if current file and Mcu_MC_ME header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_MC_ME_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_MC_ME.h have different vendor ids"
#endif

/* Check if current file and Mcu_MC_ME header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_ME_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_ME_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_MC_ME_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_MC_ME.h are different"
#endif

/* Check if current file and Mcu_MC_ME header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_MC_ME_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_MC_ME_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_MC_ME_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_MC_ME.h are different"
#endif

#if (MCU_LPU_SUPPORT == STD_ON)
/* Check if current file and Mcu_LPU header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_LPU_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_LPU.h have different vendor ids"
#endif

/* Check if current file and Mcu_LPU header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_LPU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_LPU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_LPU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_LPU.h are different"
#endif

/* Check if current file and Mcu_LPU header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_LPU_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_LPU_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_LPU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_LPU.h are different"
#endif
#endif

/* Check if current file and Mcu_MC_RGM header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_MC_RGM_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_MC_RGM.h have different vendor ids"
#endif

/* Check if current file and Mcu_MC_RGM header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_RGM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_RGM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_MC_RGM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_MC_RGM.h are different"
#endif

/* Check if current file and Mcu_MC_RGM header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_MC_RGM_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_MC_RGM_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_MC_RGM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_MC_RGM.h are different"
#endif

/* Check if current file and Mcu_MC_PCU header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_MC_PCU_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_MC_PCU.h have different vendor ids"
#endif

/* Check if current file and Mcu_MC_PCU header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_MC_PCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_MC_PCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_MC_PCU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_MC_PCU.h are different"
#endif

/* Check if current file and Mcu_MC_PCU header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_MC_PCU_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_MC_PCU_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_MC_PCU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_MC_PCU.h are different"
#endif

/* Check if current file and Mcu_CMU header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_CMU_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_CMU.h have different vendor ids"
#endif

/* Check if current file and Mcu_CMU header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_CMU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_CMU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_CMU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_CMU.h are different"
#endif

/* Check if current file and Mcu_CMU header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_CMU_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_CMU_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_CMU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_CMU.h are different"
#endif

/* Check if current file and Mcu_SIRC header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_SIRC_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_SIRC.h have different vendor ids"
#endif

/* Check if current file and Mcu_SIRC header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_SIRC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_SIRC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_SIRC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_SIRC.h are different"
#endif

/* Check if current file and Mcu_SIRC header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_SIRC_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_SIRC_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_SIRC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_SIRC.h are different"
#endif

/* Check if current file and Mcu_SXOSC header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_SXOSC_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_SXOSC.h have different vendor ids"
#endif

/* Check if current file and Mcu_SXOSC header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_SXOSC_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_SXOSC_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_SXOSC_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_SXOSC.h are different"
#endif

/* Check if current file and Mcu_SXOSC header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_SXOSC_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_SXOSC_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_SXOSC_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_SXOSC.h are different"
#endif

/* Check if current file and Mcu_STCU header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_STCU_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_STCU.h have different vendor ids"
#endif

/* Check if current file and Mcu_STCU header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_STCU_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_STCU_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_STCU_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_STCU.h are different"
#endif

/* Check if current file and Mcu_STCU header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_STCU_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_STCU_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_STCU_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_STCU.h are different"
#endif

/* Check if current file and Mcu_SSCM header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_SSCM_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_SSCM.h have different vendor ids"
#endif

/* Check if current file and Mcu_SSCM header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_SSCM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_SSCM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_SSCM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_SSCM.h are different"
#endif

/* Check if current file and Mcu_SSCM header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_SSCM_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_SSCM_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_SSCM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_SSCM.h are different"
#endif

#if (MCU_SRAMC_SUPPORT == STD_ON)
/* Check if current file and Mcu_PRAM header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_PRAM_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_PRAM.h have different vendor ids"
#endif

/* Check if current file and Mcu_PRAM header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_PRAM_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_PRAM_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_PRAM_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_PRAM.h are different"
#endif

/* Check if current file and Mcu_PRAM header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_PRAM_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_PRAM_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_PRAM_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_PRAM.h are different"
#endif
#endif

#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
/* Check if current file and Mcu_FLASH header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_FLASH_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_FLASH.h have different vendor ids"
#endif

/* Check if current file and Mcu_FLASH header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_FLASH_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_FLASH_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_FLASH_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_FLASH.h are different"
#endif

/* Check if current file and Mcu_FLASH header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_FLASH_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_FLASH_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_FLASH_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_FLASH.h are different"
#endif
#endif

/* Check if current file and Mcu_PLLDIG header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_PLLDIG_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_PLLDIG.h have different vendor ids"
#endif

/* Check if current file and Mcu_PLLDIG header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_PLLDIG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_PLLDIG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_PLLDIG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_PLLDIG.h are different"
#endif

/* Check if current file and Mcu_PLLDIG header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_PLLDIG_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_PLLDIG_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_PLLDIG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_PLLDIG.h are different"
#endif

/* Check if current file and Mcu_PMCDIG header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_PMCDIG_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_PMCDIG.h have different vendor ids"
#endif

/* Check if current file and Mcu_PMCDIG header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_PMCDIG_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_PMCDIG_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_PMCDIG_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_PMCDIG.h are different"
#endif

/* Check if current file and Mcu_PMCDIG header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_PMCDIG_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_PMCDIG_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_PMCDIG_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_PMCDIG.h are different"
#endif

/* Check if current file and Mcu_SIUL2 header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_SIUL2_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_SIUL2.h have different vendor ids"
#endif

/* Check if current file and Mcu_SIUL2 header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_SIUL2_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_SIUL2_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_SIUL2_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_SIUL2.h are different"
#endif

/* Check if current file and Mcu_SIUL2 header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_SIUL2_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_SIUL2_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_SIUL2_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_SIUL2.h are different"
#endif

#if (MCU_DEV_ERROR_DETECT == STD_ON)
/* Check if current file and DET header file are of the same version */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    #if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C != DET_AR_RELEASE_MAJOR_VERSION) || \
         (MCU_IPW_AR_RELEASE_MINOR_VERSION_C != DET_AR_RELEASE_MINOR_VERSION) \
        )
        #error "AutoSar Version Numbers of Mcu_IPW.c and Det.h are different"
    #endif
#endif
#endif

/* Check if current file and Mcu_eMios header file are of the same vendor */
#if (MCU_IPW_VENDOR_ID_C != MCU_EMIOS_H_VENDOR_ID)
    #error "Mcu_IPW.c and Mcu_eMios.h have different vendor ids"
#endif

/* Check if current file and Mcu_eMios header file are of the same Autosar version */
#if ((MCU_IPW_AR_RELEASE_MAJOR_VERSION_C    != MCU_EMIOS_H_AR_RELEASE_MAJOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_MINOR_VERSION_C    != MCU_EMIOS_H_AR_RELEASE_MINOR_VERSION) || \
     (MCU_IPW_AR_RELEASE_REVISION_VERSION_C != MCU_EMIOS_H_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Mcu_IPW.c and Mcu_eMios.h are different"
#endif

/* Check if current file and Mcu_eMios header file are of the same Software version */
#if ((MCU_IPW_SW_MAJOR_VERSION_C != MCU_EMIOS_H_SW_MAJOR_VERSION) || \
     (MCU_IPW_SW_MINOR_VERSION_C != MCU_EMIOS_H_SW_MINOR_VERSION) || \
     (MCU_IPW_SW_PATCH_VERSION_C != MCU_EMIOS_H_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Mcu_IPW.c and Mcu_eMios.h are different"
#endif

/*==================================================================================================
*                                       LOCAL MACROS
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
/* Mcu clock configuration structure used at a moment by the MCU driver. 
   When the Mcu_InitClock() API is called this pointer will be different from NULL_PTR - used as a 
    check trigger by Mcu_DistributePllClock() API.
*/
#if (MCU_INIT_CLOCK == STD_ON)
#define MCU_START_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_IPW_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

/**
* @violates @ref Mcu_IPW_c_REF_6 MISRA 2004 Required Rule 8.7, object defined external because of
* autosar
*/
static P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfig = NULL_PTR;

 
#define MCU_STOP_SEC_VAR_INIT_UNSPECIFIED
/**
* @violates @ref Mcu_IPW_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/    
#include "Mcu_MemMap.h"
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define MCU_START_SEC_CODE
/**
* @violates @ref Mcu_IPW_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"

#if (MCU_INIT_CLOCK == STD_ON)
static FUNC( uint32, MCU_CODE) Mcu_Ipw_PrepareClkSourcesToBeConfigured (P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/

#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function prepare clock sources.
* @details          The function switches system clock to FIRC and configure clock sources
*                   Called by:
*                       - Mcu_Ipw_InitClock().
*
* @param[in]        Mcu_pClockConfigPtr   Pointer to clock configuration structure
*                   (member of 'Mcu_ConfigType' struct).
*
* @return           u32ClockConfig
*
*/

static FUNC( uint32, MCU_CODE) Mcu_Ipw_PrepareClkSourcesToBeConfigured(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr)
{
    VAR (uint32, AUTOMATIC) u32ClockConfig;
    VAR (uint8, AUTOMATIC) u8ClockSourceControl;

    /* get the current system clock settings and enabled clocks */
    u32ClockConfig = Mcu_MC_ME_GetCurrentModeClockSettings();
    
    /* check the clock sources that are under MCU control and must be reconfigured */
    /* if a clock source is under MCU control then it must be turned off, configured and then re-enabled */
    u8ClockSourceControl = Mcu_pClockConfigPtr->u8ClockSourcesControl;
    
    if ( MCU_IPW_SIRC_UNDER_MCU_CONTROL ==  ( u8ClockSourceControl & MCU_IPW_SIRC_UNDER_MCU_CONTROL ))
    {
        /* if SIRC is under Mcu control mark it as disabled */
        u32ClockConfig &= ~( MC_ME_GS_S_SIRC_MASK32 );
    }
    
    if ( MCU_IPW_SXOSC_UNDER_MCU_CONTROL ==  ( u8ClockSourceControl & MCU_IPW_SXOSC_UNDER_MCU_CONTROL ))
    {
        /* if SXOSC is under Mcu control mark it as disabled */
        u32ClockConfig &= ~( MC_ME_GS_S_SXOSC_MASK32 );
    }
    
    if ( MCU_IPW_FXOSC_UNDER_MCU_CONTROL ==  ( u8ClockSourceControl & MCU_IPW_FXOSC_UNDER_MCU_CONTROL ))
    {
        /* if FXOSC is under Mcu control mark it as disabled */
        u32ClockConfig &= ~( MC_ME_GS_S_FXOSC_MASK32 );
    }
    
    if ( MCU_IPW_PLL0_UNDER_MCU_CONTROL ==  ( u8ClockSourceControl & MCU_IPW_PLL0_UNDER_MCU_CONTROL ))
    {
        /* if PLL0 is under Mcu control mark it as disabled */
        u32ClockConfig &= ~( MC_ME_GS_S_PLL0_MASK32 );
    }
    
    /* Check if either FXOSC or PLL0 are under Mcu control and need to be reconfigured. If any of them is under Mcu control
       the system clock must be switched to FIRC in order to be able to turn off FXOSC or PLL0 without losing the system clock. */
    u8ClockSourceControl &=  ( MCU_IPW_FXOSC_UNDER_MCU_CONTROL | MCU_IPW_PLL0_UNDER_MCU_CONTROL );
    
    if ( ( NULL_PTR != Mcu_pClockConfigPtr->MC_CGM_pClockConfig->apSystemClockConfig ) && ( (uint8)0x00U != u8ClockSourceControl ) )
    {
        /* Change system clock to FIRC for the safe turning OFF of FXOSC and/or PLL0 */
        Mcu_MC_ME_SystemClkUpdate( MC_ME_SYSCLK_FIRC_U32 );
    }
    
    /* Turn off the needed clock sources that will be reconfigured in Mcu_InitClock. */
    Mcu_MC_ME_EnabledClkUpdate( u32ClockConfig );
    
    return ((uint32)u32ClockConfig);
}
#endif /* (MCU_INIT_CLOCK == STD_ON) */


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/


/**
* @brief            This function initializes the MCU module.
* @details          The function initializes the CGM, ME, RGM, PCU modules, specific parameters
*                   modules and global parameters from FLASH module.
*                   Called by:
*                       - Mcu_Init() from HLD.
*
* @param[in]        Mcu_pHwIPsConfigPtr   Pointer to IPW configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_Init(P2CONST(Mcu_HwIPsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pHwIPsConfigPtr )
{

#if (STD_ON == MCU_ENABLE_USER_MODE_SUPPORT)
    Mcal_Trusted_Call(Mcu_MC_ME_SetUserAccessAllowed,());
    Mcal_Trusted_Call(Mcu_MC_RGM_SetUserAccessAllowed,());
#if (MCU_LPU_SUPPORT == STD_ON)
    Mcal_Trusted_Call(Mcu_LPU_SetUserAccessAllowed,());
#endif
#if (MCU_INIT_CLOCK == STD_ON)
    Mcal_Trusted_Call(Mcu_MC_CGM_SetUserAccessAllowed,());
#endif
#endif

    /* Init the ME_CCTLn registers */
    /* This must be done before applying any other changes */
    Mcu_MC_ME_InitCCTL(Mcu_pHwIPsConfigPtr->MC_ME_pConfig);
    /* Init MC_ME registers: MC_ME_RUN_PCx, MC_ME_LP_PCx, MC_ME_IM, clear ME_IS int flags.\
       Initialize the configurations during RUN and NON-RUN modes for each peripheral. Configuration of MC_ME_PCTLx registers. */
    Mcu_MC_ME_ModesPeriphInit( Mcu_pHwIPsConfigPtr->MC_ME_pConfig);

    /* Init MCU MC_RGM part of the registers: MC_RGM_FERD, MC_RGM_FEAR, MC_RGM_FESS, MC_RGM_FBRE, clear FES & DES status registers. */
    Call_Mcu_MC_RGM_ResetInit( Mcu_pHwIPsConfigPtr->MC_RGM_pConfig );

    /* Init Power Management Controller digital interface */
    Call_Mcu_PMCDIG_Config( Mcu_pHwIPsConfigPtr->MC_PMCDIG_pConfig );

#ifdef MCU_PREPARE_MEMORY_CONFIG
    /* The entry point of the flash controller configuration. */
    MCU_PREPARE_MEMORY_CONFIG(MCU_MEMORY_CONFIG_ENTRY_POINT);
#endif

#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
    /* Flash initialization. */
    Call_Mcu_FLASH_Init( Mcu_pHwIPsConfigPtr->FLASH_pConfig);
#endif

#ifdef MCU_PREPARE_MEMORY_CONFIG
    /* The exit point of the flash controller configuration. */
    MCU_PREPARE_MEMORY_CONFIG(MCU_MEMORY_CONFIG_EXIT_POINT);
#endif

}


#if (MCU_INIT_CLOCK == STD_ON)
/**
* @brief            This function initializes the clock structure.
* @details          This function intializes the clock structure by configuring the CGM module.
*                   The progressive clock switching output (PHI_PCS) of the FMPLL_0 is used as input for the System Clock Selector only.
*                   The non progressive clock switching output (PHI) of the FMPLL_0 is used as input for the Output Clock Selector and the Auxiliary Clock Selectors.
*                   Frequency of "PHI" output = Frequency of FVCO / ODF.
*                   Two clock outputs (PHI and FVCO/6) of the FMPLL_1 are used as inputs for the Auxiliary Clock Selectors.
*                   FMPLL_1 can not be used as a clock source for the System Clock Selector.
*                   Frequency of "FVCO/6" output = Frequency of FVCO / 6
*                   Called by:
*                       - Mcu_InitClock() from HLD.
*
* @param[in]        Mcu_pClockConfigPtr   Pointer to clock configuration structure (member of 'Mcu_ConfigType' struct).
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_InitClock(P2CONST(Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pClockConfigPtr)
{
#if (MCU_EMIOS_SUPPORT == STD_ON)
    VAR (uint8, AUTOMATIC)   u8Index = 0U;
#endif
    VAR (uint32, AUTOMATIC) u32ClockConfig;
    VAR (uint32, AUTOMATIC) u32TempClockConfig;

    /* Clear all the settings for CMU0/1/2. */
    /* In case one clock configuration has the CMU disabled, then need to make the transition to
    reset state of CMU modules. */
    if (NULL_PTR != Mcu_pClockConfig)
    {
        if (MCU_CLK_NOTIF_EN == Mcu_pClockConfig->Mcu_ClkNotification)
        {
            Mcu_CMU_DeInit();
        }
    }
    
    /* Save the current clock configuration to be used by Mcu_IPW_DistributePllClock(). */
    /** @violates @ref Mcu_IPW_c_REF_4 MISRA 2004 Required Rule 11.1, Conversion from integer to pointer */
    Mcu_pClockConfig = Mcu_pClockConfigPtr;
    
    u32ClockConfig = Mcu_Ipw_PrepareClkSourcesToBeConfigured(Mcu_pClockConfigPtr);
    
    /* set up the clock distribution tree */
    /* Progressive clock switch */
    Mcu_MC_CGM_ProgClockSwitchConfig( Mcu_pClockConfigPtr->MC_CGM_pClockConfig ) ;
    
    /* Configure system clock dividers */
    if( NULL_PTR != Mcu_pClockConfigPtr->MC_CGM_pClockConfig->apSystemClockConfig )
    {
        Mcu_MC_CGM_SystemClockConfig( Mcu_pClockConfigPtr->MC_CGM_pClockConfig ) ;
    }
    
    /* Configure all auxiliary clocks (selectors and dividers) */
    if( NULL_PTR != Mcu_pClockConfigPtr->MC_CGM_pClockConfig->apAuxClockConfig )
    {
        Call_Mcu_MC_CGM_AuxClockConfig( Mcu_pClockConfigPtr->MC_CGM_pClockConfig ) ;
    }
    
    /* Configure clock sources */
    /* SIRC */
#if (MCU_SIRC_UNDER_MCU_CONTROL == STD_ON)
    if ( NULL_PTR != Mcu_pClockConfigPtr->SIRC_pClockConfig )
    {
        Mcu_SIRC_Config( Mcu_pClockConfigPtr->SIRC_pClockConfig );
    }
#endif
    /* SXOSC */
#if (MCU_SXOSC_UNDER_MCU_CONTROL == STD_ON)

    if ( NULL_PTR != Mcu_pClockConfigPtr->SXOSC_pClockConfig )
    {
        Mcu_SXOSC_Config( Mcu_pClockConfigPtr->SXOSC_pClockConfig );
    }
#endif
    /* FIRC */
#if (MCU_FIRC_UNDER_MCU_CONTROL == STD_ON)
    if ( NULL_PTR != Mcu_pClockConfigPtr->FIRC_pClockConfig )
    {
        Mcu_FIRC_Config( Mcu_pClockConfigPtr->FIRC_pClockConfig );
    }
#endif    
    /* FXOSC */
#if (MCU_FXOSC_UNDER_MCU_CONTROL == STD_ON)   
    if ( NULL_PTR != Mcu_pClockConfigPtr->FXOSC_pClockConfig)
    {
        Call_Mcu_FXOSC_Config( Mcu_pClockConfigPtr->FXOSC_pClockConfig );
    }
#endif

    /* Configure PLLDIG clock generators */
    Mcu_PLLDIG_PllConfig( Mcu_pClockConfigPtr->MC_PLLDIG_pClockConfig ); 

#ifdef MCU_PREPARE_MEMORY_CONFIG
    /* The entry point of the flash and RAM controllers configuration. */
    MCU_PREPARE_MEMORY_CONFIG(MCU_MEMORY_CONFIG_ENTRY_POINT);
#endif

#if (MCU_DISABLE_FLASH_CONFIG == STD_OFF)
    /* Every Clock configuration need to adjust the wait-states for RAM and Flash. */
    /* Set the wait-states for Flash. */
    Call_Mcu_FLASH_SetWS( Mcu_pClockConfigPtr->FLASH_pClockConfig);
#endif

#if (MCU_SRAMC_SUPPORT == STD_ON)
    /* Set the wait-states for Ram (PRCR1 register of RAM controller). */
    Call_Mcu_PRAM_SetRamWS( Mcu_pClockConfigPtr->SRAMC_pClockConfig);
#endif /* (MCU_SRAMC_SUPPORT == STD_ON) */

#ifdef MCU_PREPARE_MEMORY_CONFIG
    /* The exit point of the flash and RAM controllers configuration. */
    MCU_PREPARE_MEMORY_CONFIG(MCU_MEMORY_CONFIG_EXIT_POINT);
#endif

    /* Enable clock sources that were turned off for re-configuring, and enable/disable other
       clock sources based on the clock configuration. */
    u32TempClockConfig = u32ClockConfig ;
    u32ClockConfig |= Mcu_pClockConfigPtr->MC_CGM_pClockConfig->u32EnabledClkSources;
    
    /* Filter the PLLs to check if any will be enabled in this clock configuration. */
    u32TempClockConfig &= ( MC_ME_GS_S_PLL0_MASK32 ) ;
    /* Check if any PLL was turned ON in this clock configuration. */
    if (u32TempClockConfig != ((Mcu_pClockConfigPtr->MC_CGM_pClockConfig->u32EnabledClkSources) & (MC_ME_GS_S_PLL0_MASK32)))
    {
        /* At least one PLL is used and needs to be started or re-started. */
        /* Call BlindEnabledClockUpdate to write the MC_ME registers without waiting for the clock sources to be stable, because
           Mcu_InitClock should not wait for the PLLs to lock. */
        Mcu_MC_ME_BlindEnabledClockUpdate( u32ClockConfig );
    }
    else
    {
        /* No PLL is started or re-started this configuration */
        /* Call EnabledClkUpdate to wait for the clock sources to be stable */
        Mcu_MC_ME_EnabledClkUpdate( u32ClockConfig );
    }
    
    /* Check if the system clock can be switched to the desired one, or the application should wait for a PLL to lock. */
    if ( 
        ( MC_ME_SYSCLK_FIRC_U32  == ( Mcu_pClockConfigPtr->Mcu_u32SystemClkSource & MC_ME_SYSCLK_DISABLED_U32 ) ) ||
        ( MC_ME_SYSCLK_FXOSC_U32 == ( Mcu_pClockConfigPtr->Mcu_u32SystemClkSource & MC_ME_SYSCLK_DISABLED_U32 ) )
       ) 
    {
        /* The system clock is not using a PLL so it can be switched in Mcu_InitClock */
        if ( NULL_PTR != Mcu_pClockConfigPtr->MC_CGM_pClockConfig->apSystemClockConfig )
        {
            Mcu_MC_ME_SystemClkUpdate( Mcu_pClockConfigPtr->Mcu_u32SystemClkSource );
        }
        
#if (MCU_EMIOS_SUPPORT == STD_ON)
            /* configure for eMios modules */
            for (u8Index = 0U; u8Index < MCU_EMIOS_NB_MODULES; u8Index++)
            {
#if (MCU_CHECK_EMIOS_STATUS == STD_ON)
                if ((Std_ReturnType)E_OK == Mcu_IPW_CheckEmiosStatus(u8Index))
                {
#endif /* (MCU_CHECK_EMIOS_STATUS == STD_ON) */
                    Mcu_eMios_Init(u8Index, Mcu_pClockConfigPtr->EMIOS_pClockConfig);
#if (MCU_CHECK_EMIOS_STATUS == STD_ON)
                }
#endif /* (MCU_CHECK_EMIOS_STATUS == STD_ON) */
            }
#endif
        /* Enable CMU */
        /* Set the Clock Monitoring Units ( CMU0 .. n ). */
        if ( MCU_CLK_NOTIF_EN == Mcu_pClockConfigPtr->Mcu_ClkNotification)
        {
            Mcu_CMU_Init( Mcu_pClockConfigPtr->Mcu_CMU_pClockConfig);
        }
    }
    else
    {
        /* The system clock is derived from PLL, so the application must wait until the PLLs are locked by 
           polling Mcu_GetPllStatus and then call Mcu_DistributePllClock */
    }

}
#endif /* (MCU_INIT_CLOCK == STD_ON) */


#if (MCU_INIT_CLOCK == STD_ON)
  #if (MCU_NO_PLL == STD_OFF)
/**
* @brief              This function activates the main PLL as the system clock source.
* @details            This function sets the PLL as the system clock and also enables monitoring.
*                     Called by:
*                       - Mcu_DistributePllClock() from HLD.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_DistributePllClock(VAR(void, AUTOMATIC))
{
#if (MCU_EMIOS_SUPPORT == STD_ON)
    VAR (uint8, AUTOMATIC)   u8Index = 0U;
#endif

    /* Mcu_pClockConfig is set by Mcu_InitClock(). 
        Mcu_DistributePllClock should not be called without calling Mcu_InitClock before */
    if ( NULL_PTR != Mcu_pClockConfig)
    {
        /* If system clock is under MCU control switch the system clock to PLL */
        if ( NULL_PTR != Mcu_pClockConfig->MC_CGM_pClockConfig->apSystemClockConfig )
        {
            Mcu_MC_ME_SystemClkUpdate( Mcu_pClockConfig->Mcu_u32SystemClkSource );
        }
#if (MCU_EMIOS_SUPPORT == STD_ON)
            /* Configure eMios modules */
            for (u8Index = 0U; u8Index < MCU_EMIOS_NB_MODULES; u8Index++)
            {
#if (MCU_CHECK_EMIOS_STATUS == STD_ON)
                if ((Std_ReturnType)E_OK == Mcu_IPW_CheckEmiosStatus(u8Index))
                {
#endif /* (MCU_CHECK_EMIOS_STATUS == STD_ON) */
                    Mcu_eMios_Init(u8Index, Mcu_pClockConfig->EMIOS_pClockConfig);
#if (MCU_CHECK_EMIOS_STATUS == STD_ON)
                }
#endif /* (MCU_CHECK_EMIOS_STATUS == STD_ON) */
            }
#endif
        /* Enable CMU if used */
        if ( MCU_CLK_NOTIF_EN == Mcu_pClockConfig->Mcu_ClkNotification)
        {
            Mcu_CMU_Init( Mcu_pClockConfig->Mcu_CMU_pClockConfig);
        }
    }
}
  #endif /* (MCU_NO_PLL == STD_OFF) */
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
/**
* @brief            This function returns the lock status of the PLL.
* @details          The user takes care that the PLL is locked by executing Mcu_GetPllStatus.
*                   If the MCU_NO_PLL is TRUE the MCU_GetPllStatus has to return MCU_PLL_STATUS_UNDEFINED.
*                   Called by:
*                       - Mcu_GetPllStatus() from HLD.
*
* @return           Provides the lock status of the PLL.
* @retval           MCU_PLL_STATUS_UNDEFINED   PLL Status is unknown.
* @retval           MCU_PLL_LOCKED   PLL is locked.
* @retval           MCU_PLL_UNLOCKED    PLL is unlocked.
*
*/
FUNC( Mcu_PllStatusType, MCU_CODE) Mcu_Ipw_GetPllStatus( VAR( void, AUTOMATIC))
{
    /* PLL status variable. */
    VAR( Mcu_PllStatusType, AUTOMATIC)   ePllStatus = MCU_PLL_STATUS_UNDEFINED;
    VAR( Mcu_PLLDIG_PllStatusType, AUTOMATIC) ePllDigStatus ; 
    
    /* get the status from each peripheral */
    
    ePllDigStatus = Mcu_PLLDIG_GetPLLStatus();
    
    /* If a PLL is unlocked return MCU_PLL_UNLOCKED */
    if ( MCU_PLLDIG_PLL_UNLOCKED == ePllDigStatus )
    {
        ePllStatus = MCU_PLL_UNLOCKED ;
    }
    else
    {
        /* if both are undefined return MCU_PLL_STATUS_UNDEFINED */
        if( MCU_PLLDIG_PLL_STATUS_UNDEFINED == ePllDigStatus )
        {
            ePllStatus = MCU_PLL_STATUS_UNDEFINED ;
        }
        else
        {
            /* Not unlocked and at least 1 is undefined */
            /* so at least 1 PLL is enabled and locked, the other ones are disabled  */
            ePllStatus = MCU_PLL_LOCKED ;
        }
    }
    
    /* Return the PLL status. */
    return (Mcu_PllStatusType)ePllStatus;
}
#endif /* (MCU_NO_PLL == STD_OFF) */


/**
* @brief            This function initializes the mode structure.
* @details          This function intializes the mode structure by configuring the MC_ME module.
*                   Called by:
*                       - Mcu_SetMode() from HLD.
*
* @param[in]        Mcu_pModeConfigPtr   Pointer to mode configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_SetMode(P2CONST(Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pModeConfigPtr)
{
    /* Request new mode transition to MC_ME. */
    Mcu_MC_ME_ModeConfig( Mcu_pModeConfigPtr);
}

#if (MCU_LPU_SUPPORT == STD_ON)
/**
* @brief            This function initializes the low power mode structure.
* @details          This function intializes the low power mode structure by configuring the LPU module.
*                   Called by:
*                       - Mcu_SetMode() from HLD.
*
* @param[in]        Mcu_pLowPowerModeConfigPtr   Pointer to low power mode configuration structure.
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_IPW_LpuSetMode(P2CONST(Mcu_LPU_LowPowerModeConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pLowPowerModeConfigPtr)
{
    if ( MCU_LPU_DRUN_MODE != Mcu_pLowPowerModeConfigPtr->Mcu_eLowPowerMode )
    {
        /* Request new mode transition to LPU. */
        Mcu_LPU_LowPowerModeConfig(Mcu_pLowPowerModeConfigPtr);
    }
}
#endif

#if (MCU_PERFORM_RESET_API == STD_ON)
/**
* @brief            This function performs a micro controller reset.
* @details          This function performs a micro controller reset by using the hardware feature of
*                   the micro controller.
*                   Called by:
*                       - Mcu_PerformReset() from HLD.
*
* @param[in]        Mcu_pHwIPsConfigPtr  Pointer to LLD configuration structure (member of 
*                   'Mcu_ConfigType' struct).
*
* @return           void
*
*/
FUNC( void, MCU_CODE) Mcu_Ipw_PerformReset(P2CONST(Mcu_HwIPsConfigType, AUTOMATIC, MCU_APPL_CONST) Mcu_pHwIPsConfigPtr )
{
    /* Performs a micro controller reset.
       A RESET mode requested via the ME_MCTL register is passed to the MC_RGM, which generates a
       global system reset and initiates the reset sequence. */
    Mcu_MC_RGM_PerformReset( Mcu_pHwIPsConfigPtr->MC_RGM_pConfig );
}
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */



/**
* @brief            This function returns the reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_GetResetReason() from HLD.
*
* @param[in]        None
*
* @return           void
*
*/
FUNC( Mcu_ResetType, MCU_CODE) Mcu_Ipw_GetResetReason(VAR(void, AUTOMATIC))
{
    VAR( Mcu_ResetType, AUTOMATIC) eResetReason = MCU_RESET_UNDEFINED;
    
    eResetReason = (Mcu_ResetType)Call_Mcu_MC_RGM_GetResetReason();
    return (Mcu_ResetType) eResetReason;
}


/**
* @brief            This function returns the reset reason.
* @details          This routine returns the Reset reason that is read from the hardware.
*                   Called by:
*                       - Mcu_GetResetReason() from HLD.
*
* @param[in]        None
*
* @return           void
*
*/
FUNC( Mcu_RawResetType, MCU_CODE) Mcu_Ipw_GetResetRawValue(VAR(void, AUTOMATIC))
{
    VAR( Mcu_RawResetType, AUTOMATIC) ResetReason ;
    
    ResetReason = (Mcu_RawResetType)Call_Mcu_MC_RGM_GetResetRawValue();
    return (Mcu_RawResetType) ResetReason;
}


#if (MCU_GET_RAM_STATE_API == STD_ON)
FUNC ( Mcu_RamStateType, MCU_CODE) Mcu_Ipw_GetRamState(VAR(void, AUTOMATIC))
{
    VAR( Mcu_RamStateType, AUTOMATIC) eRamState;
    
    eRamState = Mcu_STCU_GetRamState();
    return (Mcu_RamStateType) eRamState;
}
#endif /* (MCU_GET_RAM_STATE_API == STD_ON) */


#if (MCU_GET_PERIPH_STATE_API == STD_ON)
FUNC( Std_ReturnType, MCU_CODE) Mcu_Ipw_GetPeripheralState(VAR(Mcu_PeripheralIdType, AUTOMATIC) Mcu_PeriphId)
{
    VAR( Std_ReturnType, AUTOMATIC) State;
    
    State = Mcu_MC_ME_GetPeripheralState(Mcu_PeriphId);
    return (Std_ReturnType) State;
}
#endif /* (MCU_GET_PERIPH_STATE_API == STD_ON) */


#if (MCU_GET_SYSTEM_STATE_API == STD_ON)
FUNC( uint32, MCU_CODE) Mcu_Ipw_GetSystemState(VAR(void, AUTOMATIC))
{
    VAR( uint32, AUTOMATIC) u32State ;

    u32State = Mcu_SSCM_GetSystemState();
    return (uint32) u32State;
}
#endif /* (MCU_GET_SYSTEM_STATE_API == STD_ON) */


#if (MCU_POWERMODE_STATE_API == STD_ON)
FUNC( Mcu_PowerModeStateType, MCU_CODE) Mcu_Ipw_GetPowerModeState(VAR(void, AUTOMATIC))
{
    VAR( Mcu_PowerModeStateType, AUTOMATIC) State;
    
    State = Mcu_MC_ME_GetPowerModeState();
    return (Mcu_PowerModeStateType) State;
}
#endif /*(MCU_POWERMODE_STATE_API == STD_ON)*/


#if (MCU_GET_POWER_DOMAIN_API == STD_ON)
FUNC( Std_ReturnType, MCU_CODE) Mcu_Ipw_GetPowerDomainState(VAR(void, AUTOMATIC))
{
    VAR( Std_ReturnType, AUTOMATIC) State;
    
    State = Mcu_MC_PCU_Get_PcuState();
    return (Std_ReturnType) State;
}
#endif /*(MCU_GET_POWER_DOMAIN_API == STD_ON)*/


#if (MCU_GET_MEM_CONFIG_API == STD_ON)
FUNC( Mcu_SSCM_MemConfigType, MCU_CODE ) Mcu_Ipw_SscmGetMemConfig(VAR(void, AUTOMATIC) )
{
    VAR( Mcu_SSCM_MemConfigType, AUTOMATIC) MemConfig;
    
    MemConfig = Mcu_SSCM_GetMemConfig();
    return (Mcu_SSCM_MemConfigType) MemConfig;
}
#endif /* (MCU_GET_MEM_CONFIG_API == STD_ON) */


#if (MCU_SSCM_GET_STATUS_API == STD_ON)
FUNC( Mcu_SSCM_StatusType, MCU_CODE ) Mcu_Ipw_SscmGetStatus(VAR(void, AUTOMATIC) )
{
    VAR( Mcu_SSCM_StatusType, AUTOMATIC) Status;
    
    Status = Mcu_SSCM_GetStatus();
    return (Mcu_SSCM_StatusType) Status;
}
#endif /* (MCU_SSCM_GET_STATUS_API == STD_ON) */


#ifdef MCU_SSCM_GET_UOPS_API
#if (MCU_SSCM_GET_UOPS_API == STD_ON)
FUNC( Mcu_SSCM_UopsType, MCU_CODE ) Mcu_Ipw_SscmGetUops(VAR(void, AUTOMATIC) )
{
    VAR( Mcu_SSCM_UopsType, AUTOMATIC) Status;
    
    Status = Mcu_SSCM_GetUops();
    return (Mcu_SSCM_UopsType) Status;
}
#endif /* (MCU_SSCM_GET_UOPS_API == STD_ON) */
#endif /* MCU_SSCM_GET_UOPS_API */


#if (MCU_GET_MIDR_API == STD_ON)
/** @violates @ref Mcu_IPW_c_REF_5 Violates MISRA 2004 Required Rule 8.10, Global declaration of function. */
FUNC( void, MCU_CODE) Mcu_Ipw_GetMidrStructure(P2VAR(Mcu_MidrReturnType, AUTOMATIC, MCU_APPL_DATA) pMidr)
{
    /* just call low level API */
    Mcu_SIUL2_GetMidrStructure( pMidr );
}
#endif /*(MCU_GET_MIDR_API == STD_ON)*/

#if ((MCU_EMIOS_SUPPORT == STD_ON) || (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON))
#if (MCU_CHECK_EMIOS_STATUS == STD_ON)
/** @violates @ref Mcu_IPW_c_REF_5 Violates MISRA 2004 Required Rule 8.10, Global declaration of function. */
FUNC(Std_ReturnType, MCU_CODE) Mcu_IPW_CheckEmiosStatus(VAR(uint8, AUTOMATIC) u8Module)
{
    VAR( Std_ReturnType, AUTOMATIC) CheckStatus = (Std_ReturnType)E_NOT_OK;

#ifdef MCU_GET_INTERNAL_STATE
    switch (u8Module)
    {
    case MCU_EMIOS_MODULE_0:
        CheckStatus = Mcu_MC_ME_GetPeripheralState((Mcu_PeripheralIdType)S_EMIOS_0);
        break;
    case MCU_EMIOS_MODULE_1:
        CheckStatus = Mcu_MC_ME_GetPeripheralState((Mcu_PeripheralIdType)S_EMIOS_1);
        break;
#ifdef MCU_EMIOS_MODULE_2
    case MCU_EMIOS_MODULE_2:
        CheckStatus = Mcu_MC_ME_GetPeripheralState((Mcu_PeripheralIdType)S_EMIOS_2);
        break;
#endif
    default:
        /* do nothing */
        break;
    }
#endif /* MCU_GET_INTERNAL_STATE */

    return (Std_ReturnType) CheckStatus;
}
#endif /* (MCU_CHECK_EMIOS_STATUS == STD_ON) */
#endif /* #if ((MCU_EMIOS_SUPPORT == STD_ON) || (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)) */


#if (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_IPW_EmiosConfigureGpren(VAR (uint8, AUTOMATIC) u8Module, VAR (uint8, AUTOMATIC) u8Value)
{
    Mcu_eMios_ConfigureGpren(u8Module, u8Value);
}
#endif /* (MCU_EMIOS_CONFIGURE_GPREN_API == STD_ON) */


#ifdef MCU_DISABLE_CMU_API
#if (MCU_DISABLE_CMU_API == STD_ON)
FUNC( void, MCU_CODE ) Mcu_Ipw_DisableCmu(VAR (uint8, AUTOMATIC) u8IndexCmu)
{
    Mcu_CMU_Disable_CMU(u8IndexCmu);
}
#endif
#endif

#if (MCU_RGM_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
FUNC( void, MCU_CODE) Mcu_Ipw_RgmClearClockFailIrqFlags(VAR(void, AUTOMATIC))
{
    Mcu_MC_RGM_ClearClockMonitoringIrqFlags();
}
#endif

#ifdef MCU_ERROR_ISR_NOTIFICATION
#if (MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON)
FUNC( void, MCU_CODE) Mcu_Ipw_CmuClearClockFailIrqFlags(VAR(uint8, AUTOMATIC) u8CmuIdx, VAR(uint32, AUTOMATIC) u32IsrMask)
{
    VAR( Std_ReturnType, AUTOMATIC) CmuStatus = (Std_ReturnType)E_OK;
    
    CmuStatus = Mcu_CMU_ClearClockFailIrqFlags(u8CmuIdx, u32IsrMask);
    MCU_PARAM_UNUSED(CmuStatus);
}
#endif /* MCU_CMU_CLEAR_CLOCK_IRQ_FLAG == STD_ON */
#endif /* MCU_ERROR_ISR_NOTIFICATION */

#define MCU_STOP_SEC_CODE
/**
* @violates @ref Mcu_IPW_c_REF_1 MISRA 2004 Required Rule 19.15, Repeated include file
* @violates @ref Mcu_IPW_c_REF_2 MISRA 2004 Advisory Rule 19.1, only preprocessor 
* statements and comments before '#include'
*/
#include "Mcu_MemMap.h"


#ifdef __cplusplus
}
#endif

/** @} */

