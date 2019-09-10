/**
    @file    sample_app_mcal_initialization_task.h
    @version 1.0.0

    @brief   AUTOSAR Sample_app - header file for the initialization task for platform reg file.
    @details .

    Project      : AUTOSAR 4.2 MCAL
    Platform     : PA
    Peripheral   : 
    Dependencies : Base Det Dem Port Dio Mcu Rte Wdg WdgIf CanIf LinIf FrIf EcuM

    ARVersion     : 4.2.2
    ARRevision    : ASR_REL_4_2_REV_0002
    ARConfVariant :
    SWVersion     : 1.0.0
    BuildVersion  : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20171702

    (c) Copyright 2006-2017 NXP Inc
    All Rights Reserved.

    This file contains sample code only. It is not part of the production code deliverables.

*/
/*==================================================================================================
==================================================================================================*/

#ifndef SAMPLE_APP_MCAL_INITIALIZATION_TASK_H
#define SAMPLE_APP_MCAL_INITIALIZATION_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
/**
@file        modules.h
@brief Include Standard types & defines
*/



/*==================================================================================================
                               SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
@{
@brief Parameters that shall be published within the modules header file.
       The integration of incompatible files shall be avoided.
@remarks Covers
@remarks Implements
*/

/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
                                           CONSTANTS
==================================================================================================*/

/* State machine constants*/

/* Other constants*/

/*==================================================================================================
                                       DEFINES AND MACROS
==================================================================================================*/
#define INTC_PSR(n)          (INTC_BASEADDR + ((uint32)0x60u) + (2*n))

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

extern void sys_enableAllInterrupts(void);
extern void sys_disableAllInterrupts(void);

#ifdef __cplusplus
}
#endif

#endif /* SAMPLE_APP_MCAL_INITIALIZATION_TASK_H */

