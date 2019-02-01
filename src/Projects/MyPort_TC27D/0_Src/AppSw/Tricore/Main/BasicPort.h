/**
 * \file BasicPort.h
 * \brief BasicPort
 *
 * \version InfineonRacer 1_0_0
 */

#ifndef BASICPORT_H
#define BASICPORT_H 1
/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/
#include <Ifx_Types.h>
#include "Bsp.h"
#include "ConfigurationIsr.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
#include "IfxPort.h"
#include "Cpu0_Main.h"
#include "Cpu/Irq/IfxCpu_Irq.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/
#define IR_getLed0() IR_Port.led0
#define IR_getLed1() IR_Port.led1
#define IR_getLed2() IR_Port.led2
#define IR_getPort00_0() IR_Port.port00_0
#define IR_getPort00_1() IR_Port.port00_1

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/
typedef struct
{
	volatile boolean led0;
	volatile boolean led1;
	volatile boolean led2;
	volatile boolean port00_0;
	volatile boolean port00_1;
} Basic_Port;

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/
IFX_EXTERN Basic_Port IR_Port;

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
IFX_EXTERN void IR_setLed0(boolean led);
IFX_EXTERN void IR_setLed1(boolean led);
IFX_EXTERN void IR_setLed2(boolean led);

IFX_EXTERN void BasicPort_init(void);
IFX_EXTERN void BasicPort_run(void);

#endif
