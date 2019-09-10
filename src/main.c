/**
    @file        main.c
    @version     1.0.0

    @brief       AUTOSAR - Autosar  Sample Application.
    @details     Sample application using AutoSar MCAL drivers.

    Project      : AUTOSAR 4.2 MCAL
    Platform     : PA
    Peripheral   : 
    Dependencies : Base Det Dem Port Dio Mcu Rte Wdg WdgIf CanIf LinIf FrIf EcuM

    Autosar Version       : 4.2.2
    Autosar Revision      : ASR_REL_4_2_REV_0002
    Autosar Conf. Variant :
    Software Version      : 1.0.0
    Build Version         : MPC574XG_MCAL_1_0_0_RTM_ASR_REL_4_2_REV_0002_20171702

    (c) Copyright 2006-2017 NXP Inc
    All Rights Reserved.

    This file contains sample code only. It is not part of the production code deliverables.

*/
/*==================================================================================================
==================================================================================================*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "typedefs.h"
#include "sample_app_mcal_initialization_task.h"
#include "SysDal.h"
#if defined(AUTOSAR_OS_NOT_USED)
#include "SysDal_IntSch.h"
#endif
#include "Mcal.h"


/*==================================================================================================
                                        LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
                                      FILE VERSION CHECKS
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


/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/

/**
@brief   Main function of the sample application using Leds.
@details The sample configures the processor and uses leds and keys from the mainboard the following way:
                LED1 - Light intensity controlled by Potentiometer
                LED2 - Will stay ON while Key1 is pressed and will go OFF when watchdog will run out
                LED3 - Blinking driven by GPT
                LED4 - Always ON
                KEY1 - disable watchdog and switch on the LED2
          The function will never return.
@return Returns ok
@retval 0 - Ok
@pre None
@post None
*/
int main( )
{
    SysDal_Init();
#if defined(AUTOSAR_OS_NOT_USED)
    SysDal_IntSch_TaskScheduler();

   /* CONSOLE_FLUSH();*/
#endif
    return 0;
}

#ifdef __cplusplus
}
#endif
