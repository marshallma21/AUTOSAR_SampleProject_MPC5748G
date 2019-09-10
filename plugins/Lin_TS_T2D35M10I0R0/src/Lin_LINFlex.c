/**
*   @file    Lin_LINFlex.c
*   @version 1.0.0
*
*   @brief   AUTOSAR Lin - LINFlex.
*   @details File containing the low level driver of the LINFlex IP.
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
extern "C"{
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section [global]
* Violates MISRA 2004 Required Rule 5.1, Identifiers (internal and external) shall not rely
* on the significance of more than 31 characters. The used compilers use more than 31 chars for
* identifiers.
*
* @section Lin_LINFlex_c_REF_1
* Violates MISRA 2004 Required Rule 19.15, Precautions shall be taken
* in order to prevent the contents of a header file being included twice.
* This comes from the order of includes in the .c file and from
* include dependencies. As a safe approach, any file must include all
* its dependencies. Header files are already protected against double
* inclusions. The inclusion of MemMap.h is as per Autosar
* requirement MEMMAP003.
*
* @section Lin_LINFlex_c_REF_2
* Violates MISRA 2004 Advisory Rule 19.1, #include statements in a
* file should only be preceded by other preprocessor directives or
* comments. AUTOSAR imposes the specification of the sections in which
* certain parts of the driver must be placed.
*
* @section Lin_LINFlex_c_REF_3
* Violates MISRA 2004 Required Rule 11.1, This violation is due to
* the casting pointers to other types used in macros for reading or
* writing data from address location of controller register.
*
* @section Lin_LINFlex_c_REF_4
* Violates MISRA 2004 Required Rule 17.4, This violation is due to
* the structure of the types used. The application should ensure that the
* SDU pointer is pointing to an array.
*
* @section Lin_LINFlex_c_REF_5
* Violates MISRA 2004 Required Rule 8.10, Not required from Autosar
* specification.
*
* @section Lin_LINFlex_c_REF_6
* Violates MISRA 2004 Required Rule 1.4, The compiler/linker shall
* be checked to ensure that 31 character signifiance and
* case sensitivity are supported for external identifiers.
* This violation is due to the requirement that requests to have
* a file version check.
*
* @section Lin_LINFlex_c_REF_8
* Violates MISRA 2004 Required Rule 8.7, Objects shall be defined at block scope if they are only
* accessed from within a single function
*
* @section Lin_LINFlex_c_REF_9
* Violates MISRA 2004 Advisory Rule 11.3, A cast should not be performed between
* a pointer type and an integral type
*/



/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Lin.h"
#include "Lin_LINFlex.h"
#include "StdRegMacros.h"
#include "Reg_eSys_LINFlex.h"
#include "SchM_Lin.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           Lin_LINFlex.c
*/
#define LIN_VENDOR_ID_FLEX_C                    43
/*
* @violates @ref Lin_LINFlex_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C     4
/*
* @violates @ref Lin_LINFlex_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_MINOR_VERSION_FLEX_C     2
/*
* @violates @ref Lin_LINFlex_c_REF_6 The compiler/linker shall be checked to
* ensure that 31 character signifiance and case sensitivity are supported for
* external identifiers.
*/
#define LIN_AR_RELEASE_REVISION_VERSION_FLEX_C  2
#define LIN_SW_MAJOR_VERSION_FLEX_C             1
#define LIN_SW_MINOR_VERSION_FLEX_C             0
#define LIN_SW_PATCH_VERSION_FLEX_C             0
/*==================================================================================================
*                                      FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and Lin header file are of the same vendor */
#if (LIN_VENDOR_ID_FLEX_C != LIN_VENDOR_ID)
    #error "Lin_LINFlex.c and Lin.h have different vendor ids"
#endif
/* Check if current file and Lin_LINFlex header file are of the same vendor */
#if (LIN_VENDOR_ID_FLEX_C != LIN_VENDOR_ID_FLEX)
    #error "Lin_LINFlex.c and Lin_LINFlex.h have different vendor ids"
#endif
/* Check if current file and Lin_Linflex header file are of the same vendor */
#if (LIN_VENDOR_ID_FLEX_C != LIN_VENDOR_ID_REGFLEX)
    #error "Lin_LINFlex.c and Reg_eSys_LINFlex.h have different vendor ids"
#endif
/* Check if current file and Lin.h header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MAJOR_VERSION) || \
     (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MINOR_VERSION) || \
     (LIN_AR_RELEASE_REVISION_VERSION_FLEX_C != LIN_AR_RELEASE_REVISION_VERSION) \
    )
    #error "AutoSar Version Numbers of Lin_LINFlex.c and Lin.h are different"
#endif
/* Check if current file and Lin.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_FLEX_C != LIN_SW_MAJOR_VERSION) || \
     (LIN_SW_MINOR_VERSION_FLEX_C != LIN_SW_MINOR_VERSION) || \
     (LIN_SW_PATCH_VERSION_FLEX_C != LIN_SW_PATCH_VERSION) \
    )
    #error "Software Version Numbers of Lin_LINFlex.c and Lin.h are different"
#endif

/* Check if current file and Lin_LINFlex.h header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MAJOR_VERSION_FLEX) || \
     (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MINOR_VERSION_FLEX) || \
     (LIN_AR_RELEASE_REVISION_VERSION_FLEX_C != LIN_AR_RELEASE_REVISION_VERSION_FLEX) \
    )
    #error "AutoSar Version Numbers of Lin_LINFlex.c and Lin_LINFlex.h are different"
#endif
/* Check if current file and Lin_LINFlex.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_FLEX_C != LIN_SW_MAJOR_VERSION_FLEX) || \
     (LIN_SW_MINOR_VERSION_FLEX_C != LIN_SW_MINOR_VERSION_FLEX) || \
     (LIN_SW_PATCH_VERSION_FLEX_C != LIN_SW_PATCH_VERSION_FLEX) \
    )
    #error "Software Version Numbers of Lin_LINFlex.c and Lin_LINFlex.h are different"
#endif

/* Check if current file and Reg_eSys_LINFlex.h header file are of the same Autosar version */
#if ((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MAJOR_VERSION_REGFLEX) || \
      (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C    != LIN_AR_RELEASE_MINOR_VERSION_REGFLEX) || \
      (LIN_AR_RELEASE_REVISION_VERSION_FLEX_C != LIN_AR_RELEASE_REVISION_VERSION_REGFLEX) \
    )
    #error "AutoSar Version Numbers of Lin_LINFlex.c and Reg_eSys_LINFlex.h are different"
#endif
/* Check if current file and Reg_eSys_LINFlex.h header file are of the same Software version */
#if ((LIN_SW_MAJOR_VERSION_FLEX_C != LIN_SW_MAJOR_VERSION_REGFLEX) || \
     (LIN_SW_MINOR_VERSION_FLEX_C != LIN_SW_MINOR_VERSION_REGFLEX) || \
     (LIN_SW_PATCH_VERSION_FLEX_C != LIN_SW_PATCH_VERSION_REGFLEX) \
    )
    #error "Software Version Numbers of Lin_LINFlex.c and Reg_eSys_LINFlex.h are different"
#endif

#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
  /* Check if the source file and StdRegMacros header file are of the same version */
  #if ((LIN_AR_RELEASE_MAJOR_VERSION_FLEX_C != STDREGMACROS_AR_RELEASE_MAJOR_VERSION) || \
       (LIN_AR_RELEASE_MINOR_VERSION_FLEX_C != STDREGMACROS_AR_RELEASE_MINOR_VERSION) \
      )
      #error "AutoSar Version Numbers of Lin_Linflex.c and StdRegMacros.h are different"
  #endif
#endif
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL VARIABLES
==================================================================================================*/
#define LIN_START_SEC_VAR_NO_INIT_8
/**
* @violates @ref Lin_LINFlex_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_c_REF_2 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @brief        State of the LIN State Machine when a BIT error occurs
*
* @details      Stores the state of the LIN State machine when a BIT error occurs
*
* @violates @ref Lin_LINFlex_c_REF_8 Objects shall be defined at block scope if they are only
*                                    accessed from within a single function
*/
static volatile VAR(uint8, LIN_VAR) Lin_Linflex_au8StateOfBEF[LIN_HW_MAX_MODULES];

#define LIN_STOP_SEC_VAR_NO_INIT_8
/**
* @violates @ref Lin_LINFlex_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_c_REF_2 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
 #include "Lin_MemMap.h"
 /*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/
#define LIN_START_SEC_CONST_32
/**
* @violates @ref Lin_LINFlex_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_c_REF_2 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
 #include "Lin_MemMap.h"
 
/**
* @brief        LINFlex IPs base addresses.
*
* @details      Array containing the base address of all the LINFlex IPs.
*
*
* @violates @ref Lin_LINFlex_c_REF_5 All declarations and definitions
*                of objects or functions at file scope shall have
*                internal linkage unless external linkage is required.
*/
CONST(uint32, LIN_CONST) Linflex_au32BaseAddrs[] =
{
    #ifdef  LINFLEX0_BASEADDR
        LINFLEX0_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX0_BASEADDR */
    #ifdef  LINFLEX1_BASEADDR
        LINFLEX1_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX1_BASEADDR */
    #ifdef  LINFLEX2_BASEADDR
        LINFLEX2_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX2_BASEADDR */
    #ifdef  LINFLEX3_BASEADDR
        LINFLEX3_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX3_BASEADDR */
    #ifdef  LINFLEX4_BASEADDR
        LINFLEX4_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX4_BASEADDR */
    #ifdef  LINFLEX5_BASEADDR
        LINFLEX5_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX5_BASEADDR */
    #ifdef  LINFLEX6_BASEADDR
        LINFLEX6_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX6_BASEADDR */
    #ifdef  LINFLEX7_BASEADDR
        LINFLEX7_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX7_BASEADDR */
    #ifdef  LINFLEX8_BASEADDR
        LINFLEX8_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX8_BASEADDR */
    #ifdef  LINFLEX9_BASEADDR
        LINFLEX9_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX9_BASEADDR */
    #ifdef  LINFLEX10_BASEADDR
        LINFLEX10_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX10_BASEADDR */
    #ifdef  LINFLEX11_BASEADDR
        LINFLEX11_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX11_BASEADDR */
    #ifdef  LINFLEX12_BASEADDR
        LINFLEX12_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX12_BASEADDR */
    #ifdef  LINFLEX13_BASEADDR
        LINFLEX13_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX13_BASEADDR */
    #ifdef  LINFLEX14_BASEADDR
        LINFLEX14_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX14_BASEADDR */
    #ifdef  LINFLEX15_BASEADDR
        LINFLEX15_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX15_BASEADDR */
    #ifdef  LINFLEX16_BASEADDR
        LINFLEX16_BASEADDR,
    #else
        ((uint32)0x00000000UL),
    #endif /* LINFLEX16_BASEADDR */
    #ifdef  LINFLEX17_BASEADDR
        LINFLEX17_BASEADDR
    #else
        ((uint32)0x00000000UL)
    #endif /* LINFLEX17_BASEADDR */
};

#define LIN_STOP_SEC_CONST_32
/**
* @violates @ref Lin_LINFlex_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_c_REF_2 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
 #include "Lin_MemMap.h"
 /*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#define LIN_START_SEC_CODE
/**
* @violates @ref Lin_LINFlex_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_c_REF_2 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
 #include "Lin_MemMap.h"
 static FUNC (void, LIN_CODE) Lin_Linflex_CopyData(CONST(uint8, AUTOMATIC) u8Channel, \
                                                  P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr \
                                                 );
/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
/**
* @brief   Copy the data received from the LINFlex data registers to pu8LinSduPtr.
* @details This function shall copy the received data in the provided buffer
*          addressed by the pu8LinSduPtr pointer parameter.
*
* @param[in]   Channel LIN channel to be addressed.
* @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
*              mapped LIN Hardware receive buffer where the current SDU is stored
*
* @return       void.
*
*
* @note         Internal driver function.
*
* @violates @ref Lin_LINFlex_c_REF_5 All declarations and definitions
*                of objects or functions at file scope shall have
*                internal linkage unless external linkage is required.
*/
static FUNC (void, LIN_CODE) Lin_Linflex_CopyData(CONST(uint8, AUTOMATIC) u8Channel, \
                                                  P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr \
                                                  )
{
    VAR(uint8, AUTOMATIC) u8tempDataLength;
    VAR(uint8, AUTOMATIC) u8Loop;
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u8tempDataLength = (uint8)((( REG_READ32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex)) & LINFLEX_BIDR_DFL_NOR_MASK_U32)  >> 10U) + 1UL);

    /* Data Length Calculation */
    if (u8tempDataLength < 5U)
    {
        for (u8Loop = (uint8) 0U; u8Loop < u8tempDataLength; u8Loop++)
        {
            /* Copy LSB data received in pu8LinSduPtr[] buffer */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            *
            * @violates @ref Lin_LINFlex_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            pu8LinSduPtr[u8Loop] = (uint8)((REG_READ32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex)) >> (u8Loop * 8U)) & LINFLEX_BDRL_DATA0_MASK_U32);
        }
    }

    if (u8tempDataLength > 4U)
    {
        for (u8Loop = 0U; u8Loop < 4U; u8Loop++)
        {
            /* Copy LSB data received in pu8LinSduPtr[] buffer */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            *
            * @violates @ref Lin_LINFlex_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            pu8LinSduPtr[u8Loop] = (uint8)((REG_READ32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex)) >> (u8Loop * 8U))& LINFLEX_BDRL_DATA0_MASK_U32);
        }

        for (u8Loop = 4U; u8Loop < u8tempDataLength; u8Loop++)
        {
            /* Copy MSB data received in pu8LinSduPtr[] buffer */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            *
            * @violates @ref Lin_LINFlex_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            pu8LinSduPtr[u8Loop] = (uint8)((REG_READ32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex)) >> ((u8Loop -  4U) *  8U))&LINFLEX_BDRM_DATA4_MASK_U32);
        }
    }
    /* Release Message Buffer */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_RMB_MASK_U32);
}

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/*================================================================================================*/

/**
* @brief   Check if a LIN channel has been waked-up.
* @details This function identifies if the addressed LIN channel
*          has been woken up by the LIN bus transceiver. This API
*          is used when the LIN channel wake up functionality is
*          disabled (wake up interrupt is disabled). It checks
*          the wake up flag from the addressed LIN channel which
*          must be in sleep mode and have the wake up
*          functionality disabled.
*
* @param[in] Channel LIN channel to be waked-up.
*
* @return            Std_ReturnType.
* @retval E_OK       If the LIN Channel has the wake
*                    up flag set and the wake up ISR disabled
* @retval E_NOT_OK   Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_Linflex_CheckWakeup(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(Std_ReturnType, AUTOMATIC) u8TempReturn = (uint8)FALSE;
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    /* check whether wake up flag has been set and wake up ISR is disabled */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    if( LINFLEX_LINSR_WUF_MASK_U32== ( REG_READ32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINSR_WUF_MASK_U32))
    {
        /* read the Wake-up Interrupt Enable request */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        if (LINFLEX_LINIER_WUIE_MASK_U32== ( REG_READ32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINIER_WUIE_MASK_U32))
        {
            u8TempReturn = (uint8)FALSE;
        }
        else
        {
            /* LIN channel with wake up support disabled has been woken up */
            /* Clear Wake-Up flag */
            /* Note: all flags have to be cleared by writing a 1 to the flags -> writing 0 has
                    no effect */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_WUF_MASK_U32);
            SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_00();
            {
                /* Exit from Sleep mode and enters in Init mode */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_BIT_CLEAR32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_SLEEP_MASK_U32);
            }
            SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_00();
            /* Set the returned value to TRUE */
            u8TempReturn = (uint8)TRUE;
        }
    }
    else
    {
      u8TempReturn = (uint8)FALSE;
    }

    return u8TempReturn;
}

/**
* @brief   Initialize a LIN channel.
* @details This function initializes all hardware registers needed to
*          start the LIN functionality on the selected channel.
*
* @param[in] Channel LIN channel to be initialized.
*
* @return            void.
*
*/
FUNC(void, LIN_CODE) Lin_Linflex_InitChannel(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8BreakLength;
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;
    VAR(uint32, AUTOMATIC) u32Lin_register;

    /* Clear State of Bit Error flag */
    Lin_Linflex_au8StateOfBEF[u8Channel] = 0u;

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    /* Get the Break Lenght choosen for the hardware Lin channel from logical channel */
    u8BreakLength = Lin_pChannelConfigPtr[u8Channel]->u8LinChannelBreakLength;

    /* Check whether wake up detection is enabled */
     if ( (uint8) STD_ON == Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u16LinChannelWakeupSupport)
     {
        /* Check whether Wake up flag set */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        if(LINFLEX_LINSR_WUF_MASK_U32== ( REG_READ32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINSR_WUF_MASK_U32))
        {
            /* The wake-up shall directly be reported to the EcuM */
            /* via EcuM_SetWakeupEvent call-back function. */
             EcuM_SetWakeupEvent(Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->LinChannelEcuMWakeupSource);
         }
    }

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_01();
    {
        /* Switch to Initialization mode */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_INIT_MASK_U32);
        /* Clear sleep mode */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_SLEEP_MASK_U32);
        /* Enable Lin Mode */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_UARTCR_ADDR32(u8Lin_LINFlex), LINFLEX_UARTCR_UART_MASK_U32);
        /* Clear master break length*/
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_MBL_MASK_U32);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_01();

    /* Read value of CR1 register */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u32Lin_register = REG_READ32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex));
    /* Enable Master mode */
    /* Set By-pass filter bit to its reset value */
    /* Set Break Length */
    /* Checksum calculation is done by Hardware */
    /* Checksum field is sent after the required number of data bytes is sent */
    /* Disable LIN Auto Synchronization */
    /* Disable Loop Back Mode */
    /* Set Receiver Buffer Locked mode to its default value */
    /* Disable AWUM bit, software will take care clear sleep bit */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register \
                                                             | LINFLEX_LINCR1_MME_MASK_U32 \
                                                             | LINFLEX_LINCR1_BF_MASK_U32 \
                                                             | ((((uint32)u8BreakLength) << 8U) & LINFLEX_LINCR1_MBL_MASK_U32)) \
                                                             & (uint32)((~LINFLEX_LINCR1_CCD_MASK_U32) \
                                                             & (~LINFLEX_LINCR1_CFD_MASK_U32) \
                                                             & (~LINFLEX_LINCR1_LASE_MASK_U32) \
                                                             & (~LINFLEX_LINCR1_LBKM_MASK_U32) \
                                                             & (~LINFLEX_LINCR1_RBLM_MASK_U32) \
                                                             & (~LINFLEX_LINCR1_AWUM_MASK_U32))) \
               );
    /* Read value of CR2 register */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u32Lin_register = REG_READ32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex));
    /* Bit error reset LIN state machine. */
    /* Set 2 bits for the break delimiter */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register & (~LINFLEX_LINCR2_IOBE_MASK_U32)) | LINFLEX_LINCR2_TBDE_MASK_U32));
    /* Initialize Baudrate Registers */
    /* do not put semicolon after this macro it will violate MISRA 2004 14.3 rule */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINFBRR_ADDR32(u8Lin_LINFlex), ((Lin_pcConfigPtr->pLin_Channel[u8Channel]->u32Lin_BaudRate_RegValue) \
                                                        & LINFLEX_LINFBRR_DIV_F_MASK_U32) \
                                                       );
#if IPV_LINFLEX < IPV_LINFLEX_04_00_00
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINIBRR_ADDR32(u8Lin_LINFlex), (((Lin_pcConfigPtr->pLin_Channel[u8Channel]->u32Lin_BaudRate_RegValue) \
                                                        & LINFLEX_LINIBRR_DIV_M_MASK_U32)>>(uint8)16U) \
                                                       );
#elif IPV_LINFLEX >= IPV_LINFLEX_04_00_00
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINIBRR_ADDR32(u8Lin_LINFlex), (((Lin_pcConfigPtr->pLin_Channel[u8Channel]->u32Lin_BaudRate_RegValue) \
                                                        & LINFLEX_LINIBRR_DIV_M_MASK_U32)>>(uint8)8U) \
                                                       );
#endif

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_02();
    {
    /* Enable Lin Timeout counter */
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_LTOM_MASK_U32);
    #else
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_LTOM_MASK_U32);
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#else
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_LTOM_MASK_U32);
#endif  /* defined (ERR_IPV_LINFLEX_0010) */

    /* LIN state machine reset to Idle on timeout event */
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
#ifdef ERR_IPV_LINFLEX_0012
    #if (ERR_IPV_LINFLEX_0012 == STD_ON)
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_IOT_MASK_U32);
    #else
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_IOT_MASK_U32);
    #endif  /* (ERR_IPV_LINFLEX_0012 == STD_ON) */
#else
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_IOT_MASK_U32);
#endif  /* ERR_IPV_LINFLEX_0012 */
#else
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_IOT_MASK_U32);
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */

    /* Timeout counter enable. */
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
    #else
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#else
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
#endif  /* defined (ERR_IPV_LINFLEX_0010) */

        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_RMB_MASK_U32);

        /* Exit Init mode and switch to Normal mode */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_INIT_MASK_U32);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_02();

    /* Enable Bit Error Interrupt */
    /* Enable Checksum Error Interrupt */
    /* Enable Frame Error Interrupt */
    /* Enable Buffer Overrun Error Interrupt */
    /* Enable Data Reception Complete Interrupt */
    /* Enable Data Transmitted Interrupt  */
    /* Disable Stuck at Zero Interrupt */
    /* Disable Header Error Interrupt */
    /* Disable LIN state Interrupt */
    /* Disable wake up interrupt */
    /* It will be enabled only when needed (after sending sleep command and at the end of */
    /** the Lin_LINFlex_GoToSleepInternal()) and only for
    *   Lin_pChannelConfigPtr[Channel]->u16LinChannelWakeupSupport == (uint8) STD_ON
    */
    /* Disable Data Buffer Full Interrupt */
    /* Disable Data Buffer Empty Interrupt */
    /* Disable Header Received Interrupt */

    /* Read value of LINIER register */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u32Lin_register = REG_READ32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex));
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
    #if defined (ERR_IPV_LINFLEX_0010)
        #if (ERR_IPV_LINFLEX_0010 == STD_ON)
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register \
                                                             | LINFLEX_LINIER_BEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_CEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_FEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_BOIE_MASK_U32 \
                                                             | LINFLEX_LINIER_DRIE_MASK_U32 \
                                                             | LINFLEX_LINIER_DTIE_MASK_U32) \
                                                             & (uint32)((~LINFLEX_LINIER_SZIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_HEIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_LSIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_WUIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_DBFIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_DBEIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_HRIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_OCIE_MASK_U32))) \
               );
        #else
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register \
                                                             | LINFLEX_LINIER_BEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_CEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_FEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_BOIE_MASK_U32 \
                                                             | LINFLEX_LINIER_DRIE_MASK_U32 \
                                                             | LINFLEX_LINIER_DTIE_MASK_U32 \
                                                             | LINFLEX_LINIER_OCIE_MASK_U32) \
                                                             & (uint32)((~LINFLEX_LINIER_SZIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_HEIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_LSIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_WUIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_DBFIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_DBEIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_HRIE_MASK_U32))) \
               );
        #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
    #else
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register \
                                                             | LINFLEX_LINIER_BEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_CEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_FEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_BOIE_MASK_U32 \
                                                             | LINFLEX_LINIER_DRIE_MASK_U32 \
                                                             | LINFLEX_LINIER_DTIE_MASK_U32 \
                                                             | LINFLEX_LINIER_OCIE_MASK_U32) \
                                                             & (uint32)((~LINFLEX_LINIER_SZIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_HEIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_LSIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_WUIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_DBFIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_DBEIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_HRIE_MASK_U32))) \
               );
    #endif  /* defined (ERR_IPV_LINFLEX_0010) */
#else
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    REG_WRITE32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register \
                                                             | LINFLEX_LINIER_BEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_CEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_FEIE_MASK_U32 \
                                                             | LINFLEX_LINIER_BOIE_MASK_U32 \
                                                             | LINFLEX_LINIER_DRIE_MASK_U32 \
                                                             | LINFLEX_LINIER_DTIE_MASK_U32) \
                                                             & (uint32)((~LINFLEX_LINIER_SZIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_HEIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_LSIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_WUIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_DBFIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_DBEIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_HRIE_MASK_U32) \
                                                             & (~LINFLEX_LINIER_OCIE_MASK_U32))) \
               );
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */
}

/**
* @brief   Sends the header part of the LIN frame.
* @details Initiates the transmission of the header
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*          If response type is MASTER_RESPONSE then nothing is sent over the bus
*          the entire frame (including header) is sent with the Lin_LINFlex_SendReponse
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_Linflex_SendHeader(CONST(uint8, AUTOMATIC) u8Channel, \
                                                       P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr \
                                                      )
{
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;
    VAR(uint32, AUTOMATIC) volatile u32counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Lin_register;
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
    VAR(uint32, AUTOMATIC) u32LINOCR_OC;
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#endif  /*defined (ERR_IPV_LINFLEX_0010)*/
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_03();
    {
        /** Stop any ongoing transmission */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR2_ABRQ_MASK_U32);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_03();

    MCAL_FAULT_INJECTION_POINT(LINFLEX_FIP_1_T_TIME_OUT_1);

    /* wait till Cancellation of current frame */
    while(u32counter <= LIN_TIMEOUT_LOOPS)
    {
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        if( LINFLEX_LINCR2_ABRQ_MASK_U32!= ( REG_READ32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINCR2_ABRQ_MASK_U32))
        {
            u8TmpReturn = (uint8)E_OK;
            break;
        }
        u32counter++;
    }
    if((uint8)E_OK == u8TmpReturn)
    {
        /* Reset error status global flag */
        Lin_au8LinChFrameErrorStatus[u8Channel] = LIN_NO_ERROR;

        /* Set header status to TRUE if master wants to send the response frame */
        if (LIN_MASTER_RESPONSE == pPduInfoPtr->Drc)
        {
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_MASTER_RES_COMMAND;
            /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
            Lin_au8LinChFrameStatus[u8Channel] = LIN_CH_READY_STATE;
        }
        else
        {
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_SLAVE_RES_COMMAND;
            Lin_au8LinChFrameStatus[u8Channel] = LIN_CH_RECEIVE_NOTHING_STATE;
        }

        /* Release the Message buffer */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_RMB_MASK_U32);
        /* Clear the Noise Flag of LIN Error Status Register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_NF_MASK_U32);
        /* Read value of BIDR register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32Lin_register = REG_READ32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex));
        /* Prepare header */
        /* First step Clear previous ID and Data Lenght */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
            REG_WRITE32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex), (uint32)(u32Lin_register & ~LINFLEX_BIDR_ID_MASK_U32 & ~(LINFLEX_BIDR_DFL_SET_MASK_U32 << 10U) & ~LINFLEX_BIDR_DFL_EXT_MASK_U32));

        /* Reset previous Data Bytes */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex), (uint32)(0x00000000));
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex), (uint32)(0x00000000));
        /* Read value of BIDR register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32Lin_register = REG_READ32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex));
        if (LIN_MASTER_RESPONSE == pPduInfoPtr->Drc)
        {
            /* do not transmit header here because its a master->slave frame
            the header will be transmited together with the respose when calling SendResponse function*/

            /* Set new Identifier - Low parity bits are ignored - Calculated by LinFlex controller */
            /* Set Data length */
            /* Set Tx direction of the frame */
            if (LIN_ENHANCED_CS == pPduInfoPtr->Cs)
            {
                /* Set Enhanced Checksum for the frame */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_WRITE32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register \
                                                                       | (uint32)(((uint32)pPduInfoPtr->Pid) & LINFLEX_BIDR_ID_MASK_U32) \
                                                                       | (uint32)((((uint32)pPduInfoPtr->Dl - 1U) & LINFLEX_BIDR_DFL_SET_MASK_U32) << 10U) \
                                                                       | LINFLEX_BIDR_DIR_MASK_U32) \
                                                                       & (~LINFLEX_BIDR_CCS_MASK_U32)) \
                           );
            }
            else
            {
                /* Set Classic Checksum for the frame */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_WRITE32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex), (uint32)(u32Lin_register \
                                                                      | (uint32)(((uint32)pPduInfoPtr->Pid) & LINFLEX_BIDR_ID_MASK_U32) \
                                                                      | (uint32)((((uint32)pPduInfoPtr->Dl - 1U) & LINFLEX_BIDR_DFL_SET_MASK_U32) << 10U) \
                                                                      | LINFLEX_BIDR_DIR_MASK_U32 \
                                                                      | LINFLEX_BIDR_CCS_MASK_U32) \
                           );
            }
        }
        else
        {
            /* Set new Identifier - Low parity bits are ignored - Calculated by LinFlex controller */
            /* Set Data length */
            /* Set Rx direction of the frame. */
            if (LIN_ENHANCED_CS == pPduInfoPtr->Cs)
            {
                /* Set Enhanced Checksum for the frame */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_WRITE32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register \
                                                                       | (((uint32)pPduInfoPtr->Pid) & LINFLEX_BIDR_ID_MASK_U32) \
                                                                       | ((((uint32)pPduInfoPtr->Dl - 1U) & LINFLEX_BIDR_DFL_SET_MASK_U32) << 10U)) \
                                                                       & (uint32)((~LINFLEX_BIDR_DIR_MASK_U32) \
                                                                       & (~LINFLEX_BIDR_CCS_MASK_U32))) \
                           );
            }
            else
            {
                /* Set Classic Checksum for the frame */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_WRITE32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex), (uint32)((uint32)(u32Lin_register \
                                                                       | (((uint32)pPduInfoPtr->Pid) & LINFLEX_BIDR_ID_MASK_U32) \
                                                                       | ((((uint32)pPduInfoPtr->Dl - 1U) & LINFLEX_BIDR_DFL_SET_MASK_U32) << 10U) \
                                                                       | LINFLEX_BIDR_CCS_MASK_U32) \
                                                                       & (~LINFLEX_BIDR_DIR_MASK_U32)) \
                           );
            }
            SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_04();
            {
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
    #if defined (ERR_IPV_LINFLEX_0010)
        #if (ERR_IPV_LINFLEX_0010 == STD_ON)
                /**
                * Manually update OC1[7:0] (Output Compare Value 1) and OC2[7:0] (Output Compare Value 2) bits in the LINOCR (LIN Output Compare Register)
                * LINOCR[OC1] = LINTCSR[CNT] + 49 + LINTOCR[RTO] × (pPduInfoPtr->Dl + 1);
                * LINOCR[OC2] = LINTCSR[CNT] + 49 + LINTOCR[RTO] × (pPduInfoPtr->Dl + 1);
                */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_BIT_SET32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_OCF_MASK_U32);
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_BIT_SET32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                u32LINOCR_OC = ((((REG_READ32(LINFLEX_LINTOCR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINTOCR_RTO_MASK_U32) >> 8U) * ((uint32)pPduInfoPtr->Dl + 1U)) + \
                                (REG_READ32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINTCSR_CNT_MASK_U32) + 49U \
                               ) & LINFLEX_LINOCR_OC1_MASK_U32;
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_WRITE32(LINFLEX_LINOCR_ADDR32(u8Lin_LINFlex), ((u32LINOCR_OC << 8U) & LINFLEX_LINOCR_OC2_MASK_U32) | u32LINOCR_OC);
        #endif   /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
    #endif /* defined (ERR_IPV_LINFLEX_0010) */
#else
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
#endif /* LIN_DISABLE_FRAME_TIMEOUT */
                /* Transmit Header */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_BIT_SET32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR2_HTRQ_MASK_U32);
            }
            SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_04();
        }
    }
    return u8TmpReturn;
}

/**
* @brief   Sends the response part of the LIN frame.
* @details Initiates the transmission of the data
*          part of the LIN frame on Channel using information
*          stored on PduInfoPtr pointer.
*
* @param[in]   Channel LIN channel to be addressed.
* @param[in]   PduInfoPtr pointer to PDU containing the PID, Checksum model,
*              Response type, Dl and SDU data pointer.
*
* @return            void.
*
*/
FUNC (void, LIN_CODE) Lin_Linflex_SendResponse(CONST(uint8, AUTOMATIC) u8Channel, \
                                               P2CONST(Lin_PduType, AUTOMATIC, LIN_APPL_CONST) pPduInfoPtr \
                                              )
{
    VAR(uint8, AUTOMATIC) u8tempDataLength;
    VAR(uint8, AUTOMATIC) u8Loop;
    VAR(uint32, AUTOMATIC) u32tempBDR;
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
    VAR(uint32, AUTOMATIC) u32LINOCR_OC;
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#endif  /*(defined ERR_IPV_LINFLEX_0010)*/
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    /* Get data length */
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u8tempDataLength = ((uint8) ((( REG_READ32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex)) & LINFLEX_BIDR_DFL_NOR_MASK_U32)  >> 10U) + 1UL));

    /* Fill buffer data registers: fill only BDRL or both BDRL and BDRM depending on data length */
    /* If data length < 5 fill only BDRL otherwise (data length > 4) fill both BDRL and BDRM     */
    if ((uint8)5U > u8tempDataLength)
    {
        u32tempBDR = (uint32)0x00000000;
        for (u8Loop = (uint8)0U; u8Loop <  u8tempDataLength; u8Loop++)
        {
            /**
            * @violates @ref Lin_LINFlex_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            u32tempBDR |= (uint32)((pPduInfoPtr->SduPtr[u8Loop] & LINFLEX_BDRL_DATA0_MASK_U32)<<((uint8)8U * u8Loop));
        }

        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex), u32tempBDR );
    }

    if ((uint8)4U < u8tempDataLength)
    {
        u32tempBDR = (uint32)0x00000000;
        for (u8Loop = (uint8)0U; u8Loop < (uint8)4U; u8Loop++)
        {
            /**
            * @violates @ref Lin_LINFlex_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            u32tempBDR |= ((pPduInfoPtr->SduPtr[u8Loop] & LINFLEX_BDRL_DATA0_MASK_U32) << ( 8U * u8Loop));
        }
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex), u32tempBDR );
        u32tempBDR = (uint32)0x00000000;
        for (u8Loop =  (uint8)4U; u8Loop < u8tempDataLength; u8Loop++)
        {
            /**
            * @violates @ref Lin_LINFlex_c_REF_4 pointer arithmetic other
            *                                    than array indexing used
            */
            u32tempBDR |= ((pPduInfoPtr->SduPtr[u8Loop] & LINFLEX_BDRM_DATA4_MASK_U32) << ( 8U * (u8Loop - 4U)));
        }
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex), u32tempBDR );
    }

    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_05();
    {
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
    #if  defined (ERR_IPV_LINFLEX_0010)
        #if (ERR_IPV_LINFLEX_0010 == STD_ON)
        /**
        * Manually update OC1[7:0] (Output Compare Value 1) and OC2[7:0] (Output Compare Value 2) bits in the LINOCR (LIN Output Compare Register)
        * LINOCR[OC1] = LINTCSR[CNT] + 49 + LINTOCR[RTO] × (pPduInfoPtr->Dl + 1);
        * LINOCR[OC2] = LINTCSR[CNT] + 49 + LINTOCR[RTO] × (pPduInfoPtr->Dl + 1);
        */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_OCF_MASK_U32);
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32LINOCR_OC = ((((REG_READ32(LINFLEX_LINTOCR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINTOCR_RTO_MASK_U32) >> 8U) * ((uint32)pPduInfoPtr->Dl + 1U)) + \
                        (REG_READ32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINTCSR_CNT_MASK_U32) + 49U \
                       ) & LINFLEX_LINOCR_OC1_MASK_U32;
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_LINOCR_ADDR32(u8Lin_LINFlex), ((u32LINOCR_OC << 8U) & LINFLEX_LINOCR_OC2_MASK_U32) | u32LINOCR_OC);
        #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
    #endif  /* defined (ERR_IPV_LINFLEX_0010) */
#else
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */
        /* Transmit Header and Response */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR2_HTRQ_MASK_U32);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_05();
}

/**
* @brief   Prepares and send a go-to-sleep-command
*          frame on Channel.
* @details This function stops any ongoing transmission and initiates
*          the transmission of the sleep command (master command frame with
*          ID = 0x3C and data = (0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_Linflex_GoToSleep(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;
    VAR(uint32, AUTOMATIC) volatile u32counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;
    VAR(uint32, AUTOMATIC) u32Lin_register;

#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
    VAR(uint32, AUTOMATIC) u32LINOCR_OC;
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#endif  /*defined (ERR_IPV_LINFLEX_0010)*/
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_06();
    {
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#endif  /*defined (ERR_IPV_LINFLEX_0010)*/

        /* Stop any ongoing transmission */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR2_ABRQ_MASK_U32);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_06();

    MCAL_FAULT_INJECTION_POINT(LINFLEX_FIP_2_T_TIME_OUT_2);

    /* wait till Cancellation of current frame */
    while(u32counter <= LIN_TIMEOUT_LOOPS)
    {
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        if( LINFLEX_LINCR2_ABRQ_MASK_U32!= ( REG_READ32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINCR2_ABRQ_MASK_U32))
        {
            u8TmpReturn = (uint8)E_OK;
            break;
        }
        u32counter++;
    }
    if((uint8)E_OK == u8TmpReturn)
    {
        /* Release the message buffer */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_RMB_MASK_U32);
        /* Read value of BIDR register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32Lin_register = REG_READ32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex));
        /* Prepare header */
        /* First step Clear previous ID */
        /* Clear previous Data Lenght */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex), (uint32)(u32Lin_register & ~LINFLEX_BIDR_ID_MASK_U32 & ~(LINFLEX_BIDR_DFL_SET_MASK_U32 << 10U) & ~LINFLEX_BIDR_DFL_EXT_MASK_U32));
        /* Read value of BIDR register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32Lin_register = REG_READ32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex));
        /* Set CheckSum type */
        /* Set Data direction */
        /* Set SLEEP Mode Identifier - Parity bits are ignored - Calculated by LinFlex controller */
        /* Set Data Length */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BIDR_ADDR32(u8Lin_LINFlex), (uint32)(u32Lin_register \
                                                               | LINFLEX_BIDR_CCS_MASK_U32 \
                                                               | LINFLEX_BIDR_DIR_MASK_U32 \
                                                               | (uint32)((LINFLEX_SLEEP_COMMAND_ID_U32) & LINFLEX_BIDR_ID_MASK_U32) \
                                                               | (uint32)((LINFLEX_DATA_LENGTH_8_U32 & LINFLEX_BIDR_DFL_SET_MASK_U32) << 10U)) \
                   );
        /* Read value of BDRM register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32Lin_register = REG_READ32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex));
        /* Update Data bytes */
        /* do not put semicolon after these macros; it will violate MISRA 2004 14.3 rule */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex), (u32Lin_register \
                                                      & (~LINFLEX_BDRM_DATA7_MASK_U32) \
                                                      & (~LINFLEX_BDRM_DATA6_MASK_U32) \
                                                      & (~LINFLEX_BDRM_DATA5_MASK_U32) \
                                                      & (~LINFLEX_BDRM_DATA4_MASK_U32)) \
                   );
        /* Read value of BDRM register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32Lin_register = REG_READ32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex));
        /* Clear value of BDRM register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex), (uint32)(u32Lin_register \
                                                              | ((uint32)(LINFLEX_DATA_255_U32) << 24U) \
                                                              | ((uint32)(LINFLEX_DATA_255_U32) << 16U) \
                                                              | ((uint32)(LINFLEX_DATA_255_U32) << 8U) \
                                                              | (uint32)(LINFLEX_DATA_255_U32)) \
                   );
        /* Read value of BDRL register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32Lin_register = REG_READ32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex));
        /* Clear value of BDRL register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex), (uint32)(u32Lin_register \
                                                               & (~LINFLEX_BDRL_DATA3_MASK_U32) \
                                                               & (~LINFLEX_BDRL_DATA2_MASK_U32) \
                                                               & (~LINFLEX_BDRL_DATA1_MASK_U32) \
                                                               & (~LINFLEX_BDRL_DATA0_MASK_U32)) \
                   );
        /* Read value of BDRL register */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        u32Lin_register = REG_READ32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex));
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex), (uint32)(u32Lin_register \
                                                              | ((uint32)(LINFLEX_DATA_255_U32) << 24U) \
                                                              | ((uint32)(LINFLEX_DATA_255_U32) << 16U) \
                                                              | ((uint32)(LINFLEX_DATA_255_U32) << 8U) \
                                                              | (uint32)(LINFLEX_DATA_0_U32)) \
                   );
        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_07();
        {
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
    #if  defined (ERR_IPV_LINFLEX_0010)
        #if (ERR_IPV_LINFLEX_0010 == STD_ON)
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_BIT_SET32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_OCF_MASK_U32);
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_BIT_SET32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            u32LINOCR_OC = ((((REG_READ32(LINFLEX_LINTOCR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINTOCR_RTO_MASK_U32) >> 8U) * (LINFLEX_DATA_LENGTH_8_U32 + 2U)) + \
                            (REG_READ32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINTCSR_CNT_MASK_U32) + 49U \
                           ) & LINFLEX_LINOCR_OC1_MASK_U32;
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_WRITE32(LINFLEX_LINOCR_ADDR32(u8Lin_LINFlex), ((u32LINOCR_OC << 8U) & LINFLEX_LINOCR_OC2_MASK_U32) | u32LINOCR_OC);
        #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
    #endif  /* defined (ERR_IPV_LINFLEX_0010) */
#else
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */
            Lin_au8TransmitHeaderCommand[u8Channel] = LIN_TX_SLEEP_COMMAND;
            /* Transmit Header and Response */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_BIT_SET32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR2_HTRQ_MASK_U32);
        }
        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_07();
    }
    return u8TmpReturn;
}

/**
* @brief   Same function as Lin_LLD_GoToSleep() but
*          without sending a go-to-sleep-command on the bus.
* @details This function stops any ongoing transmission and put the
*          Channel in sleep mode (then LIN hardware enters a
*          reduced power operation mode).
*
* @param[in] Channel LIN channel to be addressed.
*
* @return            Std_ReturnType.
* @retval E_NOT_OK   In case of a timeout situation only.
* @retval E_OK       Otherwise.
*
*/
FUNC (Std_ReturnType, LIN_CODE) Lin_Linflex_GoToSleepInternal(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;
    VAR(uint32, AUTOMATIC) volatile u32counter = 0U;
    VAR(Std_ReturnType, AUTOMATIC) u8TmpReturn = (uint8)E_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_08();
    {
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#endif  /*defined (ERR_IPV_LINFLEX_0010)*/

        /* Stop any ongoing transmission */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR2_ABRQ_MASK_U32);

        MCAL_FAULT_INJECTION_POINT(LINFLEX_FIP_3_T_TIME_OUT_3);

        /* wait till Cancellation of current frame */
        while(u32counter <= LIN_TIMEOUT_LOOPS)
        {
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            if( LINFLEX_LINCR2_ABRQ_MASK_U32!= ( REG_READ32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINCR2_ABRQ_MASK_U32))
            {
                u8TmpReturn = (uint8)E_OK;
                break;
            }
            u32counter++;
        }
        if((uint8)E_OK == u8TmpReturn)
        {
            /* Release the message buffer */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_RMB_MASK_U32);

            /* Enter Sleep mode */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_BIT_SET32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_SLEEP_MASK_U32);
            /* Check whether wake-up detection by interrupt is enabled */
             if ( (uint8) STD_ON == Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u16LinChannelWakeupSupport)
             {
                /* Wake up detection is enabled */
                /* Clear Wake-Up flag */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_WUF_MASK_U32);

                /* Enable wake up interrupt */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                REG_BIT_SET32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_WUIE_MASK_U32);
            }
        }
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_08();
    return u8TmpReturn;
}

/**
* @brief   Sends a wake up signal to the LIN bus.
* @details This function shall sent a wake up signal to the LIN bus
*          and put the LIN channel in LIN_CH_OPERATIONAL state.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
FUNC (void, LIN_CODE) Lin_Linflex_WakeUp(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_09();
    {
        /* Clear Sleep Bit */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_SLEEP_MASK_U32);

        /* Send Wake up request */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_SET32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR2_WURQ_MASK_U32);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_09();
}

 /**
* @brief   Wake up the LIN channel.
* @details This function shall put the LIN channel in LIN_CH_OPERATIONAL state without
*          sending a wake up signal to the LIN bus
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return            void.
*
*/
FUNC(void, LIN_CODE) Lin_Linflex_WakeupInternal(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_10();
    {
        /* Clear Sleep Bit */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_SLEEP_MASK_U32);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_10();
}
 
/**
 * @brief   Gets the status of the LIN driver when Channel is operating.
 * @details This function returns the state of the current
 *          transmission, reception or operation status.
 *          If the reception of a Slave response was successful then
 *          this service provides a pointer to the buffer where the
 *          data is stored.
 *
 * @param[in]   Channel LIN channel to be addressed
 * @param[out]  pu8LinSduPtr pointer to pointer to a shadow buffer or memory
 *              mapped LIN Hardware receive buffer where the current SDU is
 *              stored
 * @return                  Lin_StatusType.
 * @retval LIN_NOT_OK       Development or production error rised
 *                          none of the below conditions.
 * @retval LIN_TX_OK        Successful transmission.
 * @retval LIN_TX_BUSY      Ongoing transmission of header or response.
 * @retval LIN_TX_HEADER_ERROR Error occurred during header
 *                          transmission.
 * @retval LIN_TX_ERROR     Error occurred during response
 *                          transmission.
 * @retval LIN_RX_OK        Reception of correct response.
 * @retval LIN_RX_BUSY      Ongoing reception where at least one byte
 *                          has been received.
 * @retval LIN_RX_ERROR     Error occurred during reception.
 * @retval LIN_RX_NO_REPONSE No data byte has been received yet.
 * @retval LIN_OPERATIONAL  Channel is ready for next header.
 *                          transmission and no data are available.
 * @retval LIN_CH_SLEEP     Channel is in sleep mode.
 *
 *
 */
FUNC(Lin_StatusType, LIN_CODE) Lin_Linflex_HardwareGetStatus(CONST(uint8, AUTOMATIC) u8Channel, \
                                                             P2VAR(uint8, AUTOMATIC, LIN_APPL_DATA) pu8LinSduPtr \
                                                            )
{
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;
    VAR(uint8, AUTOMATIC) u8tempStatus;
    VAR(uint8, AUTOMATIC) u8Temp;
    VAR(uint8, AUTOMATIC) u8tempOC1 = 0U;
    VAR(uint8, AUTOMATIC) u8tempHTO = 0U;
    VAR(uint32, AUTOMATIC) u32BDRL_EMPTY= 0U;
    VAR(uint32, AUTOMATIC) u32BDRM_EMPTY= 0U;
    VAR(Lin_StatusType,AUTOMATIC) TempReturn = LIN_NOT_OK;

    /* Get the hardware Lin channel from logical channel */
     u8Lin_LINFlex = Lin_pChannelConfigPtr[u8Channel]->pChannelConfigPC->u8LinHwChannel;
 
#ifdef  ERR_IPV_LINFLEX_0011
    #if (ERR_IPV_LINFLEX_0011 == STD_ON)
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u8tempStatus = (uint8)((REG_READ32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINSR_LINS_MASK_U32)>>(uint8)12U);
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    if((uint8)((REG_READ32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINSR_LINS_MASK_U32)>>(uint8)12U) == u8tempStatus)
    {
    #else
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u8tempStatus = (uint8)((REG_READ32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINSR_LINS_MASK_U32)>>(uint8)12U);
    #endif  /* (ERR_IPV_LINFLEX_0011 == STD_ON) */
#else
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u8tempStatus = (uint8)((REG_READ32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINSR_LINS_MASK_U32)>>(uint8)12U);
#endif  /* ERR_IPV_LINFLEX_0011 */

    switch (u8tempStatus & (uint8)0x0FU)
    {
        /* Master mode => return status to TX_BUSY if any of the following condition */
        case LINFLEX_LINSR_SLEEP_MODE_U8:
        case LINFLEX_LINSR_INIT_MODE_U8:
            TempReturn = LIN_NOT_OK;
            break;
        case LINFLEX_LINSR_BREAK_TX_MODE_U8 :
        case LINFLEX_LINSR_BREAK_DEL_TX_MODE_U8 :
        case LINFLEX_LINSR_SYNC_FIELD_TX_MODE_U8:
        case LINFLEX_LINSR_ID_FIELD_TX_MODE_U8:
#ifdef  ERR_IPV_LINFLEX_0011
    #if (ERR_IPV_LINFLEX_0011 == STD_ON)
            TempReturn = LIN_TX_BUSY;
            break;
        case LINFLEX_LINSR_HEADER_TX_MODE_U8:
            /* Check error status */
            switch(Lin_au8LinChFrameErrorStatus[u8Channel])
            {
                /* Header or Response timeout error conditions */
                case LIN_TIMEOUT_ERROR:
                    if(LIN_TX_SLAVE_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel])
                    {
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        u32BDRL_EMPTY = REG_READ32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex));
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        u32BDRM_EMPTY = REG_READ32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex));
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        if((0U == u32BDRL_EMPTY)&&(0U == u32BDRM_EMPTY ))
                        {
                        /* Driver has received 0 bytes */
                            TempReturn = LIN_RX_NO_RESPONSE;
                        }
                        else
                        {
                            /* Driver has received at least 1 byte */
                            TempReturn = LIN_RX_ERROR;
                        }
                    }
                    else if ((LIN_TX_MASTER_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) || \
                             (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) \
                            )
                    {
                        TempReturn = LIN_RX_ERROR;
                    }
                    else
                    {
                        TempReturn = LIN_NOT_OK;
                    }

                    break;
                /* Tx data error conditions */
                case LIN_BIT_ERROR:
                    if ((LIN_TX_MASTER_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) || \
                        (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) \
                       )
                    {
                        u8Temp = Lin_Linflex_au8StateOfBEF[u8Channel];
                        if((LINFLEX_LINSR_BREAK_TX_MODE_U8 != u8Temp) && \
                           (LINFLEX_LINSR_BREAK_DEL_TX_MODE_U8 != u8Temp) && \
                           (LINFLEX_LINSR_SYNC_FIELD_TX_MODE_U8 != u8Temp) && \
                           (LINFLEX_LINSR_ID_FIELD_TX_MODE_U8 != u8Temp) && \
                           (LINFLEX_LINSR_HEADER_TX_MODE_U8 != u8Temp) \
                          )
                        {
                            TempReturn = LIN_TX_ERROR;
                        }
                        else
                        {
                            TempReturn = LIN_TX_HEADER_ERROR;
                        }
                    }
                    else if (LIN_TX_SLAVE_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel])
                    {
                        TempReturn = LIN_TX_HEADER_ERROR;
                    }
                    else
                    {
                        TempReturn = LIN_TX_ERROR;
                    }
                    break;

                case LIN_NO_ERROR :
                    TempReturn = LIN_TX_BUSY;
                    break;

                default:
                    TempReturn = LIN_NOT_OK;
                    break;
            }
            break;
    #else
        case LINFLEX_LINSR_HEADER_TX_MODE_U8:
            TempReturn = LIN_TX_BUSY;
            break;
    #endif /* (ERR_IPV_LINFLEX_0011 == STD_ON) */
#else
        case LINFLEX_LINSR_HEADER_TX_MODE_U8:
            TempReturn = LIN_TX_BUSY;
            break;
#endif /* ERR_IPV_LINFLEX_0011 */

        case LINFLEX_LINSR_DATA_RX_TX_MODE_U8:
        case LINFLEX_LINSR_CHECKSUM_RX_TX_MODE_U8:
            if ((LIN_TX_MASTER_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) || \
                (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) \
               )
            {
                TempReturn = LIN_TX_BUSY;
            }
            else if (LIN_TX_SLAVE_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel])
            {
#ifdef ERR_IPV_LINFLEX_0012
    #if (ERR_IPV_LINFLEX_0012 == STD_ON)
                switch(Lin_au8LinChFrameErrorStatus[u8Channel])
                {
                    case LIN_TIMEOUT_ERROR:
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        u32BDRL_EMPTY = REG_READ32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex));
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        u32BDRM_EMPTY = REG_READ32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex));
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        if((0U == u32BDRL_EMPTY)&&(0U == u32BDRM_EMPTY ))
                        {
                        /* Driver has received 0 bytes */
                            TempReturn = LIN_RX_NO_RESPONSE;
                        }
                        else
                        {
                            /* Driver has received at least 1 byte */
                            TempReturn = LIN_RX_ERROR;
                        }
                        break;
                    default:
                        TempReturn = LIN_RX_BUSY;
                        break;
                }
    #else
                TempReturn = LIN_RX_BUSY;
    #endif  /* (ERR_IPV_LINFLEX_0012 == STD_ON) */
#else
                TempReturn = LIN_RX_BUSY;
#endif  /* ERR_IPV_LINFLEX_0012 */
            }
            else
            {
                TempReturn = LIN_NOT_OK;
            }
            break;

        case LINFLEX_LINSR_IDLE_MODE_U8:
        /* Check error status */
            switch(Lin_au8LinChFrameErrorStatus[u8Channel])
            {
                /* Tx header error conditions */
                case LIN_IDENTIFIER_PARITY_ERROR:
                case LIN_BREAK_DELIMITER_ERROR:
                case LIN_SYNCH_FIELD_ERROR:
                    TempReturn = LIN_TX_HEADER_ERROR;
                    break;

                /* Header or Response timeout error conditions */
                case LIN_TIMEOUT_ERROR:
                    if ((LIN_TX_MASTER_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) || \
                        (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) \
                       )
                    {
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        u8tempOC1 = (uint8) ( REG_READ32( LINFLEX_LINOCR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINOCR_OC1_MASK_U32);
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        u8tempHTO = (uint8) ( REG_READ32( LINFLEX_LINTOCR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINTOCR_HTO_MASK_U32);
                        if (u8tempOC1 <= u8tempHTO)
                        {
                            /* Timeout on Master Header Transmission */
                            TempReturn = LIN_TX_HEADER_ERROR;
                        }
                        else
                        {
                            /* Timeout on Master Response Transmission */
                            TempReturn = LIN_TX_ERROR;
                        }
                    }
                    /* Timeout on Data Transmission or Reception */
                    else
                    {
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        u32BDRL_EMPTY = REG_READ32(LINFLEX_BDRL_ADDR32(u8Lin_LINFlex));
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        u32BDRM_EMPTY = REG_READ32(LINFLEX_BDRM_ADDR32(u8Lin_LINFlex));
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        if((0U == u32BDRL_EMPTY)&&(0U == u32BDRM_EMPTY ))
                        {
                           /* Driver has received 0 bytes */
                            TempReturn = LIN_RX_NO_RESPONSE;
                        }
                        else
                        {
                            /* Driver has received at least 1 byte */
                            TempReturn = LIN_RX_ERROR;
                        }
                    }
                    break;

                /* Tx data error conditions */
                case LIN_BIT_ERROR:
                    if ((LIN_TX_MASTER_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) || \
                        (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel]) \
                       )
                    {
                        u8Temp = Lin_Linflex_au8StateOfBEF[u8Channel];
                        if( (LINFLEX_LINSR_BREAK_TX_MODE_U8 != u8Temp) && \
                            (LINFLEX_LINSR_BREAK_DEL_TX_MODE_U8 != u8Temp) && \
                            (LINFLEX_LINSR_SYNC_FIELD_TX_MODE_U8 != u8Temp) && \
                            (LINFLEX_LINSR_ID_FIELD_TX_MODE_U8 != u8Temp) && \
                            (LINFLEX_LINSR_HEADER_TX_MODE_U8 != u8Temp) \
                          )
                        {
                            TempReturn = LIN_TX_ERROR;
                        }
                        else
                        {
                            TempReturn = LIN_TX_HEADER_ERROR;
                        }
                    }
                    else if (LIN_TX_SLAVE_RES_COMMAND == Lin_au8TransmitHeaderCommand[u8Channel])
                    {
                        TempReturn = LIN_TX_HEADER_ERROR;
                    }
                    else
                    {
                        TempReturn = LIN_TX_ERROR;
                    }
                    break;

                /* Rx error conditions */
                case LIN_NOISE_ERROR:
                case LIN_CHECKSUM_ERROR:
                case LIN_FRAMING_ERROR:
                case LIN_BUFFER_OVER_RUN_ERROR:
                    /* Release Message Buffer */
                    /**
                     * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                     *
                     * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                     */
                    REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_RMB_MASK_U32);
                    TempReturn = LIN_RX_ERROR;
                    break;

                case LIN_NO_ERROR :
                    /* Check Lin frame status variable */
                    switch(Lin_au8LinChFrameStatus[u8Channel])
                    {
                        /* Tx completed - Status Updated in ISR */
                        case LIN_TX_COMPLETE_STATE:
                            TempReturn = LIN_TX_OK;
                            break;

                        /* Rx completed - Status Updated in ISR */
                        case LIN_RX_COMPLETE_STATE:
                            /* Copy the data from hardware buffer */
                            Lin_Linflex_CopyData(u8Channel, pu8LinSduPtr);
                            TempReturn =  LIN_RX_OK;
                            break;

                        /* Tx completed - But master not received any data */
                        case LIN_CH_RECEIVE_NOTHING_STATE:
                            TempReturn = LIN_RX_NO_RESPONSE;
                            break;

                        /* Channel Initialized or wakenup or all activity completed and ready to
                        send next header */
                        case LIN_CH_READY_STATE:
                            TempReturn = LIN_OPERATIONAL;
                            break;

                        /* Channel not ready */
                        case LIN_CH_NOT_READY_STATE:
                          TempReturn = LIN_NOT_OK;
                          break;

                        default :
                            TempReturn = LIN_NOT_OK;
                            break;
                    }
                    break;
                default:
                    TempReturn = LIN_NOT_OK;
                    break;
            }
            break;
        default :
            TempReturn = LIN_NOT_OK;
            break;
    }

#ifdef  ERR_IPV_LINFLEX_0011
    #if (ERR_IPV_LINFLEX_0011 == STD_ON)
    }
    #endif  /* (ERR_IPV_LINFLEX_0011 == STD_ON) */
#endif  /* ERR_IPV_LINFLEX_0011 */

    return TempReturn;
}



/**
* @brief   Interrupt handler for TX and RX on LINFlex.
* @details This function shall manage all the RX and TX ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
* @implements Lin_Linflex_TxRxInterruptHandler_Activity
*
* @note         Internal driver function.
*/
FUNC(void, LIN_CODE) Lin_Linflex_TxRxInterruptHandler(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8, AUTOMATIC) u8LogicalChannel = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;
    VAR(uint32, AUTOMATIC) u32Lin_status;

    /* Get base address of LINFlex module which is used by LIN channel */
    u8Lin_LINFlex = (uint8)u8Channel;

#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_11();
    {
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
    }
    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_11();
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#endif  /*defined (ERR_IPV_LINFLEX_0010)*/

    /* Check if driver is initialized */
    if( NULL_PTR != Lin_pcConfigPtr )
    {
        while(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
             if((sint32)u8Lin_LINFlex == Lin_as8ChannelHardwareMap[Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID])
             {
                break;
            }
            else
            {
                u8LogicalChannel++;
            }
        }

        if(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
            /* Get the logical channel index from physical channel */
             u8LogicalChannel = Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID;
  
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            u32Lin_status = REG_READ32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex));
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            u32Lin_status &= REG_READ32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex));
            if (0UL != u32Lin_status)
            {
                /* Wake up interrupt */
                /* Wake up flag set */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                if (0U != (u32Lin_status & LINFLEX_LINSR_WUF_MASK_U32))
                {
                    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_12();
                    {
                        /* Disable wake up interrupt */
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_WUIE_MASK_U32);
                    }
                    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_12();

                    /* if channel is in sleep, wakeup it to operational state */
                    if (LIN_CH_SLEEP_STATE == Lin_au8LinChStatus[u8LogicalChannel])
                    {
                        /* Indicates a valid timer wakeup event to ECU State Manager */
                         if ((uint8) STD_ON == Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u16LinChannelWakeupSupport)
                        {
                            EcuM_CheckWakeup(Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->LinChannelEcuMWakeupSource);
                        }
                         /* Set Channel state Operational */
                        Lin_au8LinChStatus[u8LogicalChannel] = LIN_CH_OPERATIONAL;
                        /* Update LIN channel frame operation status to LIN_CH_READY_STATE */
                        Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_CH_READY_STATE;
                    }
                }
                /* Data Reception Complete interrupt */
                /* Data Reception Completed Flag set */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                else if (0U != (u32Lin_status & LINFLEX_LINSR_DRF_MASK_U32))
                {
                    /* Clear interrupt flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_DRF_MASK_U32);

                    /* Update LIN channel frame operation status to LIN_RX_COMPLETE_STATE */
                    Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_RX_COMPLETE_STATE;

                    /* Noise Error has occurred ? */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    if(LINFLEX_LINESR_NF_MASK_U32== ( REG_READ32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINESR_NF_MASK_U32))

                    {
                        /* Set LIN channel frame error status to LIN_NOISE_ERROR */
                        Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_NOISE_ERROR;

                        /* Clear the Noise Flag of LIN Error Status Register */
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_NF_MASK_U32);
                    }
                    #if defined (ERR_IPV_LINFLEX_0010)
                        #if (ERR_IPV_LINFLEX_0010 == STD_ON)
                        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_13();
                        {
                            /**
                            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                            */
                            REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
                        }
                        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_13();
                        #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
                    #endif  /*defined (ERR_IPV_LINFLEX_0010)*/
                }
                /* Data Transmitted Complete interrupt */
                /* Data Transmission Completed Flag set */
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                else if (0U != (u32Lin_status & LINFLEX_LINSR_DTF_MASK_U32))
                {
                    /* Clear interrupt flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_DTF_MASK_U32);
                    /* Check if sleep mode was transmitted */
                    if (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8LogicalChannel])
                    {
                        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_14();
                        {
                            /* Check whether wake up detection be interrupt is enabled */
                             if ((uint8) STD_ON == Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u16LinChannelWakeupSupport)
                             {
                                /* Wake up detection enabled */
                                /* Clear Wake-Up flag */
                                /**
                                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                                *
                                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                                */
                                REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_WUF_MASK_U32);
                                /* Enable wake up interrupt */
                                /**
                                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                                *
                                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                                */
                                REG_BIT_SET32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_WUIE_MASK_U32);
                            }
                            /* Enter Sleep mode */
                            /**
                            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                            */
                            REG_BIT_SET32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_SLEEP_MASK_U32);
                        }
                        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_14();

                         /* Set Channel state to LIN_CH_SLEEP_PENDING state */
                        Lin_au8LinChStatus[u8LogicalChannel] = LIN_CH_SLEEP_PENDING;
                         /* Update Lin_au8TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
                        Lin_au8TransmitHeaderCommand[u8LogicalChannel] = LIN_TX_NO_COMMAND;
                    }
                    else
                    {
                        /* Update LIN channel frame operation status to LIN_TX_COMPLETE_STATE */
                        Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_TX_COMPLETE_STATE;
                    }
                }
                else
                {
                    /* Error condition - Clear all flag */
                    /* Clear Wake-Up flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_WUF_MASK_U32);
                    /* Clear Data Reception Completed flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_DRF_MASK_U32);
                    /* Clear Data Transmission Completed flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_DTF_MASK_U32);
                    #if defined (ERR_IPV_LINFLEX_0010)
                        #if (ERR_IPV_LINFLEX_0010 == STD_ON)
                        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_15();
                        {
                            /**
                            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                            */
                            REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
                        }
                        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_15();
                        #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
                    #endif  /*defined (ERR_IPV_LINFLEX_0010)*/
                }
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* Error occured, reset all flags */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_FLAGS_MASK_U32);
        }
    }
    else
    {
        /* Error occured, reset all flags */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_FLAGS_MASK_U32);
    }

    return; /* exit function with no return */
}

/**
* @brief   Interrupt handler for Error on LINFlex.
* @details This function shall manage all the Error ISRs on the
*          addressed channel.
*
* @param[in]   Channel LIN channel to be addressed.
*
* @return       void.
*
*
* @note         Internal driver function.
*/
FUNC (void, LIN_CODE) Lin_Linflex_ErrorInterruptHandler(CONST(uint8, AUTOMATIC) u8Channel)
{
    VAR(uint8,AUTOMATIC) u8LogicalChannel = (uint8)0U;
    VAR(uint8, AUTOMATIC) u8Lin_LINFlex;
    VAR(boolean, AUTOMATIC) bIsTxErrorOnSleepCmd = (boolean)FALSE;
    VAR(uint32, AUTOMATIC) u32Lin_status;
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
    VAR(uint32, AUTOMATIC) u32Count;
    VAR(uint32, AUTOMATIC) u32LINOCR_OC;
    VAR(uint32, AUTOMATIC) u32CompareResult;
    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#endif  /*defined (ERR_IPV_LINFLEX_0010)*/
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */

    /* Get base address of LINFlex module which is used by LIN channel */
    u8Lin_LINFlex = (uint8)u8Channel;

#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
#if defined (ERR_IPV_LINFLEX_0010)
    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u32Count = REG_READ32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINTCSR_CNT_MASK_U32;
    /**
    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
    *
    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
    */
    u32LINOCR_OC = ((REG_READ32(LINFLEX_LINOCR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINOCR_OC2_MASK_U32) >> 8U);

    if(u32Count < u32LINOCR_OC)
    {
        u32CompareResult = u32LINOCR_OC - u32Count;
    }
    else
    {
        u32CompareResult = u32Count - u32LINOCR_OC;
    }

    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
#endif  /*defined (ERR_IPV_LINFLEX_0010)*/
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */

    /* Check if driver is initialized */
    if( NULL_PTR != Lin_pcConfigPtr )
    {
        while(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
             if((sint32)u8Lin_LINFlex == Lin_as8ChannelHardwareMap[Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID])
             {
                break;
            }
            else
            {
                u8LogicalChannel++;
            }
        }

        if(LIN_HW_MAX_AVAILABLE_MODULES > u8LogicalChannel)
        {
            /* Get the logical channel index from physical channel */
             u8LogicalChannel = Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u8LinChannelID;
             /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            u32Lin_status = REG_READ32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex));
            /**
             * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
             *
             * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            u32Lin_status &= REG_READ32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex));
            /**
             * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
             *
             * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            if (0UL != u32Lin_status)
            {
                /* Check only error flags */
                if (0U != (u32Lin_status & LINFLEX_LINESR_BEF_MASK_U32))
                {
                    /* Clear Bit Error flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_BEF_MASK_U32);

                    /* Stores the state of the LIN State machine when a BIT error occurs*/
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    Lin_Linflex_au8StateOfBEF[u8LogicalChannel] = (uint8)((REG_READ32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex)) & LINFLEX_LINSR_LINS_MASK_U32)>>(uint8)12U);

                    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_16();
                    {
                        /* Stop any ongoing transmission */
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        REG_BIT_SET32(LINFLEX_LINCR2_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR2_ABRQ_MASK_U32);
                    }
                    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_16();

                    /* Set LIN channel frame error status to LIN_BIT_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BIT_ERROR;
                    /* Check if error was on sleep frame transmitting */
                    if (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8LogicalChannel])
                    {
                        bIsTxErrorOnSleepCmd = (boolean)TRUE;
                    }
                }
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                if (0U != (u32Lin_status & LINFLEX_LINESR_CEF_MASK_U32))
                {
                    /* Clear Checksum Error flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_CEF_MASK_U32);
                    /* Set LIN channel frame error status to LIN_CHECKSUM_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_CHECKSUM_ERROR;
                }
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                if (0U != (u32Lin_status & LINFLEX_LINESR_OCF_MASK_U32))
                {
                    /* Clear Output Compare flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_OCF_MASK_U32);
#if (LIN_DISABLE_FRAME_TIMEOUT == STD_OFF)
                #if defined (ERR_IPV_LINFLEX_0010)
                    #if (ERR_IPV_LINFLEX_0010 == STD_ON)
                    /* Spurious timeout event check */
                    if(1U >= u32CompareResult)
                    {
                        /* Set LIN channel frame error status to LIN_TIMEOUT_ERROR */
                        Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_TIMEOUT_ERROR;
                        /* Check if error was on sleep frame transmitting */
                        if (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8LogicalChannel])
                        {
                            bIsTxErrorOnSleepCmd = (boolean)TRUE;
                        }
                        SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_17();
                        {
                            /**
                            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                            */
                            REG_BIT_CLEAR32(LINFLEX_LINTCSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINTCSR_TOCE_MASK_U32);
                            /**
                            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                            */
                            REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
                        }
                        SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_17();
                    }
                    #else
                    /* Set LIN channel frame error status to LIN_TIMEOUT_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_TIMEOUT_ERROR;
                    /* Check if error was on sleep frame transmitting */
                    if (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8LogicalChannel])
                    {
                        bIsTxErrorOnSleepCmd = (boolean)TRUE;
                    }
                    #endif  /* (ERR_IPV_LINFLEX_0010 == STD_ON) */
                #else
                    /* Set LIN channel frame error status to LIN_TIMEOUT_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_TIMEOUT_ERROR;
                    /* Check if error was on sleep frame transmitting */
                    if (LIN_TX_SLEEP_COMMAND == Lin_au8TransmitHeaderCommand[u8LogicalChannel])
                    {
                        bIsTxErrorOnSleepCmd = (boolean)TRUE;
                    }
                #endif  /*defined (ERR_IPV_LINFLEX_0010)*/
#else
                    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_18();
                    {
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        REG_BIT_CLEAR32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_OCIE_MASK_U32);
                    }
                    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_18();
#endif  /* LIN_DISABLE_FRAME_TIMEOUT */
                }
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                if (0U != (u32Lin_status & LINFLEX_LINESR_FEF_MASK_U32))
                {
                    /* Framing Error flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_FEF_MASK_U32);
                    /* Set LIN channel frame error status to LIN_FRAMING_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_FRAMING_ERROR;
                }
                /**
                * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                *
                * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                */
                if (0U != (u32Lin_status & LINFLEX_LINESR_BOF_MASK_U32))
                {
                    /* Buffer Overrun flag */
                    /**
                    * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                    *
                    * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                    */
                    REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_BOF_MASK_U32);
                    /* Set LIN channel frame error status to LIN_BUFFER_OVER_RUN_ERROR */
                    Lin_au8LinChFrameErrorStatus[u8LogicalChannel] = LIN_BUFFER_OVER_RUN_ERROR;
                }
                /* Check if error was on sleep frame transmitting */
                if ((boolean)TRUE == bIsTxErrorOnSleepCmd) /* Error was on sleep frame transmitting */
                {
                    SchM_Enter_Lin_LIN_EXCLUSIVE_AREA_19();
                    {
                        /* Check whether wake up detection by interrupt is enabled */
                         if ((uint8) STD_ON == Lin_pChannelConfigPtr[u8LogicalChannel]->pChannelConfigPC->u16LinChannelWakeupSupport)
                         {
                            /* Wake up detection enabled */
                            /* Clear Wake-Up flag */
                            /**
                            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                            */
                            REG_WRITE32(LINFLEX_LINSR_ADDR32(u8Lin_LINFlex), LINFLEX_LINSR_WUF_MASK_U32);
                            /* Enable wake up interrupt */
                            /**
                            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                            *
                            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                            */
                            REG_BIT_SET32(LINFLEX_LINIER_ADDR32(u8Lin_LINFlex), LINFLEX_LINIER_WUIE_MASK_U32);
                        }
                        /* Enter Sleep mode */
                        /**
                        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
                        *
                        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
                        */
                        REG_BIT_SET32(LINFLEX_LINCR1_ADDR32(u8Lin_LINFlex), LINFLEX_LINCR1_SLEEP_MASK_U32);
                    }
                    SchM_Exit_Lin_LIN_EXCLUSIVE_AREA_19();

                     /* Set Channel state to LIN_CH_SLEEP_PENDING state */
                    Lin_au8LinChStatus[u8LogicalChannel] = LIN_CH_SLEEP_PENDING;
                     /* Update Lin_au8TransmitHeaderCommand value to LIN_TX_NO_COMMAND */
                    Lin_au8TransmitHeaderCommand[u8LogicalChannel] = LIN_TX_NO_COMMAND;
                    /* Update LIN channel frame operation status to LIN_CH_NOT_READY_STATE */
                    Lin_au8LinChFrameStatus[u8LogicalChannel] = LIN_CH_NOT_READY_STATE;
                    /* Reset bIsTxErrorOnSleepCmd flag */
                    bIsTxErrorOnSleepCmd = (boolean)FALSE;
                }
            }
            else
            {
               /* Do nothing */
            }
        }
        else
        {
            /* Error occured, reset all flags */
            /**
            * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
            *
            * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
            */
            REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_FLAGS_MASK_U32);
        }
    }
    else
    {
        /* Error occured, reset all flags */
        /**
        * @violates @ref Lin_LINFlex_c_REF_3 cast from unsigned int to pointer
        *
        * @violates @ref Lin_LINFlex_c_REF_9 cast should not be performed
        */
        REG_WRITE32(LINFLEX_LINESR_ADDR32(u8Lin_LINFlex), LINFLEX_LINESR_FLAGS_MASK_U32);
    }

    return; /* exit function with no return */
}

#define LIN_STOP_SEC_CODE
/**
* @violates @ref Lin_LINFlex_c_REF_1 #include statements in a file should
*                only be preceded by other preprocessor directives or comments.
* @violates @ref Lin_LINFlex_c_REF_2 Precautions shall be taken in
*                order to prevent the contents of a header file being
*                included twice.
*/
 #include "Lin_MemMap.h"
 
#ifdef __cplusplus
}
#endif
/** @} */
