/**
    @file        sample_app_mcal_initialization_task.c
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
#include "StdRegMacros.h"
#include "typedefs.h"
#include "sample_app_mcal_initialization_task.h"


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
#define SIUL_PCR_OBE_MASK           (uint16)0x0200
#define SIUL_PCR_IBE_MASK           (uint16)0x0100


/*==================================================================================================
                                       LOCAL VARIABLES
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
volatile   VAR(uint8, MCU_VAR)  u8SwitchToSupervisor = 0U; 
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/
#if defined(AUTOSAR_OS_NOT_USED)
extern const vuint32_t IntcVectorTableHw[];
#endif

/*==================================================================================================
                                       GLOBAL VARIABLES
==================================================================================================*/

/**
@brief This is the global variable that holds all the sample app specific data
*/

/*==================================================================================================
                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/


/*==================================================================================================
                                       LOCAL FUNCTIONS
==================================================================================================*/
static void sys_enableAllInterrupts_call(void);
static void sys_disableAllInterrupts_call(void);
/*==================================================================================================
*                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/
static void sys_enableAllInterrupts_call(void)
{
    __asm(" wrteei 1");
}

static void sys_disableAllInterrupts_call(void)
{
    __asm(" wrteei 0");
}
/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/

/** 
* @brief sys_enableAllInterrupts
* @details function used to enable all interrupts
*/
void sys_enableAllInterrupts(void)
{
    
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
   Mcal_Trusted_Call(sys_enableAllInterrupts_call,());
#else
    __asm(" wrteei 1");
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */

}

/** 
* @brief sys_disableAllInterrupts
* @details function used to disable all interrupts
*/
void sys_disableAllInterrupts(void)
{
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
    Mcal_Trusted_Call(sys_disableAllInterrupts_call,());
#else
    __asm(" wrteei 0");
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */

}


/*==================================================================================================
                                       GLOBAL FUNCTIONS
==================================================================================================*/
#ifdef MCAL_ENABLE_USER_MODE_SUPPORT
/* make the switch to supervisor mode.
Return how many times the supervisor mode was entered */

uint8 Sys_GoToSupervisor(void)
{

    u8SwitchToSupervisor++;
    Mcal_goToSupervisor()

    return u8SwitchToSupervisor;
}

/*make the switch back to user mode, return a uint32 value passed as parameter */
uint32 Sys_GoToUser_Return(uint32 u32returnValue)
{
    /* if previously, the supervisor mode was accessed, then switch back to UserMode */
    if(1UL == u8SwitchToSupervisor) 
    { 
        Mcal_goToUser(); 
    } 
    if(0UL < u8SwitchToSupervisor)
    {
        u8SwitchToSupervisor--;
    }
    /* return the value from the driver's call */
    return u32returnValue; 
}
/*make the switch back to user mode, return 0. */
void Sys_GoToUser(void)
{
    /* if previously, the supervisor mode was accessed, then switch back to UserMode */
    if(1UL == u8SwitchToSupervisor) 
    { 
        Mcal_goToUser(); 
    } 
    if(0UL < u8SwitchToSupervisor)
    {
        u8SwitchToSupervisor--;
    }
}
#endif /* MCAL_ENABLE_USER_MODE_SUPPORT */


#ifdef __cplusplus
}
#endif
