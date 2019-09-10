[!AUTOSPACING!]
[!NOCODE!]
/**
*   @file       Pwm_NotifyCheck_Src.c
*   @version    1.0.0
*
*   @brief      AUTOSAR Pwm - Pwm post-build configuration file.
*   @details    Macro to generate notification handler
*
*   @addtogroup PWM_MODULE
*   @{
*/
/*==================================================================================================
*   Project              : AUTOSAR 4.2 MCAL
*   Platform             : PA
*   Peripheral           : eMios
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


[!/* avoid multiple inclusion */!]
[!IF "not(var:defined('PWM_NOTIFY_CHECK_SRC_M'))"!]
[!VAR "PWM_NOTIFY_CHECK_SRC_M"="'true'"!]

/* Below there are a couple of macros implementing methods for working with string arrays 
   on top of a simple string. The arrays can store a variable number of string entries,
   each string having a maximum length of 30 chars 
   Each element in the array has exactly 30 chars (which is also the plugin maximum allowed
length for FlexPwm notification handlers) and is used to store the name of the FlexPwm
Fault notification handler trailed till 30 chars with '*' */
[!MACRO "ArrayDeclare", "Size"!]
    [!VAR "OutMyArray" = "''"!]
    [!FOR "i" = "1" TO "$Size"!]
        [!VAR "OutMyArray" = "concat($OutMyArray, '******************************')"!]
    [!ENDFOR!]
[!ENDMACRO!]

[!MACRO "ArraySetElement", "Index", "Value"!]
    [!VAR "MacSetElement" = "$Value"!]
    /* Add trailing '*' chars until length of 30 */
    [!FOR "idx" = "string-length($Value)" TO "30"!]
      [!VAR "MacSetElement" = "concat($MacSetElement, '*')"!]
    [!ENDFOR!]
    /* Insert the value prepared for the entry in it's place in the string keeping the array */
    [!IF "$Index = 0"!]
        [!VAR "OutMyArray" = "concat($MacSetElement, substring($OutMyArray,31))"!]
    [!ELSE!] 
        [!VAR "OutMyArray" = "concat(substring($OutMyArray,1,$Index*30), $MacSetElement, substring($OutMyArray,$Index*30+31))"!]
    [!ENDIF!]
[!ENDMACRO!]

[!MACRO "ArrayGetElement", "Index"!]
    /* Get the element out the string storring the array and
    remove the trailing '*' chars */
    [!VAR "OutGetElement" = "substring-before(substring($OutMyArray,$Index*30+1,30),'*')"!]
[!ENDMACRO!]

/*list of prototypes of Pwm channel notification handlers */
[!MACRO "GeneratePwmNotifications"!]
  [!CODE!]
/** @brief Prototypes of Pwm channels User Notifications */[!//
  [!ENDCODE!]  
  [!NOCODE!]
  [!VAR "MacOuterLoopCounter" = "0"!]
  [!VAR "MacInnerLoopCounter" = "0"!] 
  /* Loop through all Pwm channels and get name of Notification
  handlers for each of them. Loop the channels twice because there might be
  channels using same MacNotification function and we only want to 
  declare it as external once */
  [!LOOP "PwmChannelConfigSet/PwmChannel/*"!]
    [!VAR "MacOuterLoopCounter" = "$MacOuterLoopCounter + 1"!]
    [!VAR "MacInnerLoopCounter" = "0"!]
    [!VAR "MacMatchcounter" = "0"!]
    [!IF "node:exists('PwmNotification')"!]
        [!VAR "MacNotification" = "PwmNotification"!]
        [!LOOP "../../../*/PwmChannel/*"!]
            [!IF "(PwmNotification != 'NULL_PTR') and (PwmNotification != '"NULL"') and (PwmNotification != 'NULL')"!]
                [!VAR "MacInnerLoopCounter" = "$MacInnerLoopCounter + 1"!]
                [!IF "$MacOuterLoopCounter >= $MacInnerLoopCounter"!]
                    [!IF "($MacNotification = PwmNotification)"!]
                        [!VAR "MacMatchcounter" = "$MacMatchcounter + 1"!]
                    [!ENDIF!]
                [!ENDIF!]
            [!ENDIF!]
        [!ENDLOOP!]
    [!ENDIF!]
    [!IF "$MacMatchcounter = 1"!]
      [!CODE!]
/*@violates @ref Pwm_PBcfg_C_REF_7 An An external object or function shall be declared in one and only one file */
extern FUNC(void, PWM_CODE)[!"PwmNotification"!](void);[!//      
      [!ENDCODE!]
    [!ENDIF!]
  [!ENDLOOP!]
  [!ENDNOCODE!]
[!ENDMACRO!]

[!ENDIF!] /* Avoid multiple inclusion ENDIF */
[!ENDNOCODE!]
