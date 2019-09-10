/**
*   @file    Lin_NonASR.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Lin - Lin NonAutosar high level interface implementation.
*   @details Lin NonAutosar high level interface implementation.
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
* @section Lin_NonASR_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_NonASR_c_REF_2
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_NonASR_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, Casting operation to a pointer.
* This violation is due to the Casting pointers to other types used in macros
* for Reading or writing data from address location of controller register
*
* @section Lin_NonASR_c_REF_4
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_NonASR_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section Lin_NonASR_c_REF_6
* Violates MISRA 2004 Advisory Rule 11.3, cast should not be performed between
* a pointer type and an integral type
*
* @section Lin_NonASR_c_REF_7
* Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable
* The code is not dynamically linked. An absolute stack address is obtained when taking the address of the near auto variable.
* A source of error in writing dynamic code is that the stack segment may be different from the data segment.
*
*/

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
/**
* @file           Lin_NonASR.c
*/
#include "Lin.h"
#include "Lin_NonASR.h"
#include "Lin_IPW.h"
#include "Lin_LINFlex.h"
#include "StdRegMacros.h"
/**
* @violates @ref Lin_NonASR_c_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
#include "Reg_eSys.h"
#include "Reg_eSys_LINFlex.h"
#include "SchM_Lin.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_NonASR.c
*/
#define LIN_VENDOR_ID_NONASR_C                      43
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C       4
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MINOR_VERSION_NONASR_C       2
/*
* @violates @ref Lin_NonASR_c_REF_2 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_NONASR_C    2
#define LIN_SW_MAJOR_VERSION_NONASR_C               1
#define LIN_SW_MINOR_VERSION_NONASR_C               0
#define LIN_SW_PATCH_VERSION_NONASR_C               0
/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_VENDOR_ID)
    #error "Lin_NonASR.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin.h are different"
#endif
/* Check if current file and Lin header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_NonASR.c and Lin.h are different"
#endif
/* Check if current file and Lin_Ipw header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_IPW_VENDOR_ID)
    #error "Lin_NonASR.c and Lin_NonASR.h have different vendor ids"
#endif
/* Check if current file and Lin_Ipw header file are of the same version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_IPW) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_Ipw.h are different"
#endif
/* Check if current file and Lin_Ipw header file are of the same version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_IPW) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_IPW) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_Ipw.h are different"
#endif
/* Check if current file and Lin_NonASR header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_VENDOR_ID_NONASR)
    #error "Lin_NonASR.c and Lin_NonASR.h have different vendor ids"
#endif
/* Check if current file and Lin_NonASR header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_NONASR) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_NONASR) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_NONASR) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_NonASR.h are different"
#endif
/* Check if current file and Lin_NonASR header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != LIN_SW_MAJOR_VERSION_NONASR) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != LIN_SW_MINOR_VERSION_NONASR) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != LIN_SW_PATCH_VERSION_NONASR) \
    )
    #error "Software Version Numbers of Lin_NonASR.c and Lin_NonASR.h are different"
#endif
/* Check if current file and Lin_Linflex header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_VENDOR_ID_FLEX)
    #error "Lin_NonASR.c and Lin_Linflex.h have different vendor ids"
#endif
/* Check if current file and Lin_Linflex header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_FLEX) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_FLEX) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_FLEX) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Lin_Linflex.h are different"
#endif
/* Check if current file and Lin_Linflex header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != LIN_SW_MAJOR_VERSION_FLEX) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != LIN_SW_MINOR_VERSION_FLEX) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != LIN_SW_PATCH_VERSION_FLEX) \
    )
    #error "Software Version Numbers of Lin_NonASR.c and Lin_Linflex.h are different"
#endif
/* Check if current file and Reg_eSys_LINFlex header file are of the same vendor */
#if (LIN_VENDOR_ID_NONASR_C != LIN_VENDOR_ID_REGFLEX)
    #error "Lin_NonASR.c and Reg_eSys_LINFlex.h have different vendor ids"
#endif
/* Check if current file and Reg_eSys_LINFlex header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
     (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C    != LIN_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
     (LIN_AR_RELEASE_REVISION_VERSION_NONASR_C != LIN_AR_RELEASE_REVISION_VERSION_REGFLEX) \
    )
    #error "AutoSar Version Numbers of Lin_NonASR.c and Reg_eSys_LINFlex.h are different"
#endif
/* Check if current file and Reg_eSys_LINFlex header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_NONASR_C != LIN_SW_MAJOR_VERSION_REGFLEX) || \
     (LIN_SW_MINOR_VERSION_NONASR_C != LIN_SW_MINOR_VERSION_REGFLEX) || \
     (LIN_SW_PATCH_VERSION_NONASR_C != LIN_SW_PATCH_VERSION_REGFLEX) \
    )
    #error "Software Version Numbers of Lin_NonASR.c and Reg_eSys_LINFlex.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and StdRegMacros header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
      )
      #error "AutoSar Version Numbers of Lin_NonASR.c and StdRegMacros.h are different"
  #endif
  /* Check if the source file and Reg_eSys header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_NONASR_C != REG_ESYS_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_NONASR_C != REG_ESYS_AR_RELEASE_MINOR_VERSION) \
      )
      #error "AutoSar Version Numbers of Lin_NonASR.c and Reg_eSys.h are different"
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

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_NonASR_c_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*/
/**
* @violates @ref Lin_NonASR_c_REF_4 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/
#if LIN_DUAL_CLOCK_MODE == STD_ON

/**
* @brief          Lin_SetClockMode.
* @details        Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*
* @param[in]      ClockMode   New clock mode.
*
* @return                     The result of the switching clock operation.
* @retval E_OK                The switching operation was OK.
* @retval E_NOT_OK            The switching operation has failed caused by the
*                             wrong driver state.
*
* @api            Switch the clock mode to the alternate clock mode on all
*                 the Lin channels.
*
* @pre            LIN_DUAL_CLOCK_MODE must be defined and its value must be STD_ON.
*
* @implements     Lin_SetClockMode_Activity
*
* @note           Switch the clock mode to the alternate clock mode on
*                 all the Lin channels.
*/
/**
* @violates @ref Lin_NonASR_c_REF_5 All declarations and definitions of objects
* or functions at file scope shall have internal linkage unless external linkage is required.
*/
FUNC(Std_ReturnType, LIN_CODE) Lin_SetClockMode(VAR(Lin_ClockModesType, AUTOMATIC) ClockMode)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)E_OK;
    VAR(uint8,AUTOMATIC) u8chLoop;
    VAR(uint8,AUTOMATIC) u8Lin_LINFlex;
    VAR(Lin_StatusType,AUTOMATIC) LinStatus = LIN_NOT_OK;
    VAR(uint8,AUTOMATIC) *pu8linSduPtr[1];
    VAR(uint8,AUTOMATIC) au8linSdu[8] = {(uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0, (uint8)0};

    /* @violates @ref Lin_NonASR_c_REF_7 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
    pu8linSduPtr[0] = au8linSdu;

    for(u8chLoop=(uint8)0U; u8chLoop < LIN_HW_MAX_MODULES; u8chLoop++)
    {
        /* Get the hardware Lin channel from logical channel */
         u8Lin_LINFlex = Lin_pChannelConfigPtr[u8chLoop]->pChannelConfigPC->u8LinHwChannel;
         /* @violates @ref Lin_NonASR_c_REF_7 Violates MISRA 2004 Required Rule 1.2, Taking address of near auto variable */
        LinStatus = Lin_GetStatus(u8chLoop, pu8linSduPtr);

        switch (LinStatus)
        {
            case LIN_NOT_OK :

            /* If the LIN driver or some channels are not initialized it's not possible to change the baudrate */
            u8TempReturn = (uint8)E_NOT_OK;
                break;

            default :
                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_20();
                {
                    /* Switch to Initialization mode */
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 Cast from unsigned long to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_BIT_SET32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_INIT_MASK_U32);

                    /* Clear sleep mode */
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 Cast from unsigned long to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_BIT_CLEAR32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_SLEEP_MASK_U32);
                }
                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_20();

                /* Set the Baudrate */
                if (ClockMode == LIN_NORMAL)
                {
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 Cast from unsigned long to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINFBRR_ADDR32(u8Lin_LINFlex), ((Lin_pcConfigPtr->pLin_Channel[u8chLoop]->u32Lin_BaudRate_RegValue) & LINFLEX_LINFBRR_DIV_F_MASK_U32));

#if IPV_LINFLEX < IPV_LINFLEX_04_00_00
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINIBRR_ADDR32(u8Lin_LINFlex), (((Lin_pcConfigPtr->pLin_Channel[u8chLoop]->u32Lin_BaudRate_RegValue) & LINFLEX_LINIBRR_DIV_M_MASK_U32)>>(uint8)16U));

#elif IPV_LINFLEX >= IPV_LINFLEX_04_00_00
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINIBRR_ADDR32(u8Lin_LINFlex), (((Lin_pcConfigPtr->pLin_Channel[u8chLoop]->u32Lin_BaudRate_RegValue) & LINFLEX_LINIBRR_DIV_M_MASK_U32)>>(uint8)8U));

#endif
                }
                else
                {
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 Cast from unsigned long to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINFBRR_ADDR32(u8Lin_LINFlex), ((Lin_pcConfigPtr->pLin_Channel[u8chLoop]->u32Lin_BaudRate_RegValue_Alternate) & LINFLEX_LINFBRR_DIV_F_MASK_U32));

    #if IPV_LINFLEX < IPV_LINFLEX_04_00_00
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINIBRR_ADDR32(u8Lin_LINFlex), (((Lin_pcConfigPtr->pLin_Channel[u8chLoop]->u32Lin_BaudRate_RegValue_Alternate) & LINFLEX_LINIBRR_DIV_M_MASK_U32)>>(uint8)16U));
    #elif IPV_LINFLEX >= IPV_LINFLEX_04_00_00
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINIBRR_ADDR32(u8Lin_LINFlex), (((Lin_pcConfigPtr->pLin_Channel[u8chLoop]->u32Lin_BaudRate_RegValue_Alternate) & LINFLEX_LINIBRR_DIV_M_MASK_U32)>>(uint8)8U));
    #endif
                }
                SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_21();
                {
                    /* Exit Init mode and switch to Normal mode */
                    /**
                    * @violates @ref Lin_NonASR_c_REF_3 Cast from unsigned long to pointer
                    *
                    * @violates @ref Lin_NonASR_c_REF_6 Cast should not be performed
                    */
                    REG_BIT_CLEAR32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_INIT_MASK_U32);
                }
                SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_21();
                break;
        }
    }
    return u8TempReturn;
}

#endif /* DUAL CLOCK MODE */

#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_NonASR_c_REF_1 Precautions shall be taken in order to prevent the contents
* of a header file being included twice.
*
* @violates @ref Lin_NonASR_c_REF_4 #include statements in a file should only be preceded
* by other preprocessor directives or comments.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif
/** @} */
