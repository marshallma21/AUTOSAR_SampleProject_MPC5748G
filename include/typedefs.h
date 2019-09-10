/**
    @file    typedefs.h
    @version 1.0.0

    @brief   AUTOSAR Sample_app - typedefs for platform reg file.
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

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_

#ifdef __MWERKS__    /*Metrowerk CodeWarrior */
    #include <stdint.h>

    /* Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;

#else
#ifdef __ghs__    /*GreenHills */
    #include <stdint.h>

    /* Standard typedefs used by header files, based on ISO C standard */
    typedef volatile int8_t vint8_t;
    typedef volatile uint8_t vuint8_t;

    typedef volatile int16_t vint16_t;
    typedef volatile uint16_t vuint16_t;

    typedef volatile int32_t vint32_t;
    typedef volatile uint32_t vuint32_t;

#else

    /* This is needed for compilers that don't have a stdint.h file */
    #define SWCRTE_STD_ON   1U
	#define SWCRTE_STD_OFF  0U
    #define SWCRTE_TRUE   1U
	#define SWCRTE_FALSE  0U

	
    typedef unsigned char boolean_t;  
    typedef signed char int8_t;
    typedef unsigned char uint8_t;
    typedef volatile signed char vint8_t;
    typedef volatile unsigned char vuint8_t;

    typedef signed short int16_t;
    typedef unsigned short uint16_t;
    typedef volatile signed short vint16_t;
    typedef volatile unsigned short vuint16_t;

    typedef signed int int32_t;
    typedef unsigned int uint32_t;
    typedef volatile signed int vint32_t;
    typedef volatile unsigned int vuint32_t;

#endif
#endif
#endif


