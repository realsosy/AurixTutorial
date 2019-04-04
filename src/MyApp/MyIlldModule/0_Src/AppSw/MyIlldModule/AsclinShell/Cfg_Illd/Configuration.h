/**
 * \file Configuration.h
 * \brief Global configuration
 *
 * \version iLLD_Demos_1_0_1_4_0
 * \copyright Copyright (c) 2014 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxLld_Demo_AsclinShellInterface_SrcDoc_Config Application configuration
 * \ingroup IfxLld_Demo_AsclinShellInterface_SrcDoc
 *
 *
 */

#ifndef CONFIGURATION_H
#define CONFIGURATION_H
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include "Ifx_Cfg.h"
#include "ConfigurationIsr.h"
#include "ifxPort_PinMap.h"
/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
/* APPLICATION_KIT_TC237 혹은 SHIELD_BUDDY 중에 한가지만 선택*/
#define APPLICATION_KIT_TC237 1
#define SHIELD_BUDDY 2

#define ASCLIN0			0		// For HC06 Bluetooth module
#define ASCLIN3			3		// For USB
#define SHELL_ASCLIN	ASCLIN3

/** \addtogroup IfxLld_Demo_AsclinShellInterface_SrcDoc_Config
 * \{ */

#define CFG_ASC0_BAUDRATE       (115200.0)                   /**< \brief Define the Baudrate */
#define CFG_ASC0_RX_BUFFER_SIZE (512)                        /**< \brief Define the Rx buffer size in byte. */
#define CFG_ASC0_TX_BUFFER_SIZE (6 * 1024)                   /**< \brief Define the Tx buffer size in byte. */

/*______________________________________________________________________________
** Help Macros
**____________________________________________________________________________*/
/**
 * \name Macros for Regression Runs
 * \{
 */

#if BOARD == APPLICATION_KIT_TC237
	#define LED_TICK					IfxPort_P13_0
	#define LED0						IfxPort_P13_1
	#define LED1						IfxPort_P13_2
	#define LED2						IfxPort_P13_3

	#define PORT00_0					IfxPort_P00_0
	#define PORT00_1					IfxPort_P00_1

	#define SHELL_RX        IfxAsclin0_RXA_P14_1_IN
	#define SHELL_TX        IfxAsclin0_TX_P14_0_OUT

#elif BOARD == SHIELD_BUDDY
	#define LED_TICK					IfxPort_P10_2
	#define LED0						IfxPort_P00_4
	#define LED1						IfxPort_P00_3
	#define LED2						IfxPort_P00_2

	#define PORT00_0					IfxPort_P00_0
	#define PORT00_1					IfxPort_P00_1

	#define SHELL_RX        IfxAsclin3_RXD_P32_2_IN
	#define SHELL_TX        IfxAsclin3_TX_P15_7_OUT


#endif



#ifndef REGRESSION_RUN_STOP_PASS
#define REGRESSION_RUN_STOP_PASS
#endif

#ifndef REGRESSION_RUN_STOP_FAIL
#define REGRESSION_RUN_STOP_FAIL
#endif

/** \} */

/** \} */

#endif
