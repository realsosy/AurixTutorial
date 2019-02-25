/**
 * \file AsclinAscDemo.c
 * \brief Demo AsclinAscDemo
 *
 * \version iLLD_Demos_1_0_0_11_0
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
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include <stdio.h>
#include <string.h>

#include "AsclinAscBtDemo.h"
#include "SysSe/Bsp/Bsp.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/******************************************************************************/
/*------------------------------Global variables------------------------------*/
/******************************************************************************/

App_AsclinAsc g_AsclinAscUsb; /**< \brief Demo information */
App_AsclinAsc g_AsclinAscBt; /**< \brief Demo information */

/******************************************************************************/
/*-------------------------Function Prototypes--------------------------------*/
/******************************************************************************/
boolean AsclinAscBtComm(char * tx_ptr, char * rx_ptr);

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

#if BOARD == APPLICATION_KIT_TC237
/** \addtogroup IfxLld_Demo_AsclinAsc_SrcDoc_Main_Interrupt
 * \{ */

/** \name Interrupts for Transmit
 * \{ */

IFX_INTERRUPT(asclin0TxISR, 0, ISR_PRIORITY_ASC_0_TX)
{
    IfxAsclin_Asc_isrTransmit(&g_AsclinAscUsb.drivers.asc);
}

/** \} */

/** \name Interrupts for Receive
 * \{ */

IFX_INTERRUPT(asclin0RxISR, 0, ISR_PRIORITY_ASC_0_RX)
{
    IfxAsclin_Asc_isrReceive(&g_AsclinAscUsb.drivers.asc);
}

/** \} */

/** \name Interrupts for Error
 * \{ */

IFX_INTERRUPT(asclin0ErISR, 0, ISR_PRIORITY_ASC_0_EX)
{
    IfxAsclin_Asc_isrError(&g_AsclinAscUsb.drivers.asc);
}

/** \} */

/** \} */
#elif BOARD == SHIELD_BUDDY
/** \addtogroup IfxLld_Demo_AsclinAsc_SrcDoc_Main_Interrupt
 * \{ */

///** \name Interrupts for Transmit
// * \{ */
//
//IFX_INTERRUPT(asclin3TxISR, 0, ISR_PRIORITY_ASC_3_TX)
//{
//    IfxAsclin_Asc_isrTransmit(&g_AsclinAscUsb.drivers.asc);
//}
//
///** \} */
//
///** \name Interrupts for Receive
// * \{ */
//
//IFX_INTERRUPT(asclin3RxISR, 0, ISR_PRIORITY_ASC_3_RX)
//{
//    IfxAsclin_Asc_isrReceive(&g_AsclinAscUsb.drivers.asc);
//
//}
//
///** \} */
//
///** \name Interrupts for Error
// * \{ */
//
//IFX_INTERRUPT(asclin3ErISR, 0, ISR_PRIORITY_ASC_3_EX)
//{
//    IfxAsclin_Asc_isrError(&g_AsclinAscUsb.drivers.asc);
//}

/** \} */
/** \name Interrupts for Transmit
 * \{ */

IFX_INTERRUPT(asclin0TxISR, 0, ISR_PRIORITY_ASC_0_TX)
{
    IfxAsclin_Asc_isrTransmit(&g_AsclinAscBt.drivers.asc);
}

/** \} */

/** \name Interrupts for Receive
 * \{ */

IFX_INTERRUPT(asclin0RxISR, 0, ISR_PRIORITY_ASC_0_RX)
{
    IfxAsclin_Asc_isrReceive(&g_AsclinAscBt.drivers.asc);

}

/** \} */

/** \name Interrupts for Error
 * \{ */

IFX_INTERRUPT(asclin0ErISR, 0, ISR_PRIORITY_ASC_0_EX)
{
    IfxAsclin_Asc_isrError(&g_AsclinAscBt.drivers.asc);
}

/** \} */

/** \} */
#endif

/** \brief Demo init API
 *
 * This function is called from main during initialization phase
 */
void AsclinAscBtDemo_init(void)
{
    /* disable interrupts */
    boolean              interruptState = IfxCpu_disableInterrupts();

    /* BT **************/
    IfxAsclin_Asc_Config ascConfig;
#if BOARD == APPLICATION_KIT_TC237

#elif BOARD == SHIELD_BUDDY
    IfxAsclin_Asc_initModuleConfig(&ascConfig, &MODULE_ASCLIN0);
#endif
    /* set the desired baudrate */
    ascConfig.baudrate.prescaler    = 1;
//    ascConfig.baudrate.baudrate     = 9600; /* FDR values will be calculated in initModule */
    ascConfig.baudrate.baudrate     = 115200; /* FDR values will be calculated in initModule */
    ascConfig.baudrate.oversampling = IfxAsclin_OversamplingFactor_4;
#if BOARD == APPLICATION_KIT_TC237

#elif BOARD == SHIELD_BUDDY
    ascConfig.interrupt.txPriority    = ISR_PRIORITY_ASC_0_TX;
    ascConfig.interrupt.rxPriority    = ISR_PRIORITY_ASC_0_RX;
    ascConfig.interrupt.erPriority    = ISR_PRIORITY_ASC_0_EX;
#endif
    ascConfig.interrupt.typeOfService = (IfxSrc_Tos)IfxCpu_getCoreIndex();


    /* FIFO configuration */
    ascConfig.txBuffer     = g_AsclinAscBt.ascBuffer.tx;
    ascConfig.txBufferSize = ASC_TX_BUFFER_SIZE;

    ascConfig.rxBuffer     = g_AsclinAscBt.ascBuffer.rx;
    ascConfig.rxBufferSize = ASC_RX_BUFFER_SIZE;

    /* pin configuration */
#if BOARD == APPLICATION_KIT_TC237

#elif BOARD == SHIELD_BUDDY
    const IfxAsclin_Asc_Pins pins_bt = {
        NULL_PTR,                     IfxPort_InputMode_pullUp,        /* CTS pin not used */
        &IfxAsclin0_RXB_P15_3_IN, IfxPort_InputMode_pullUp,        /* Rx pin */
        NULL_PTR,                     IfxPort_OutputMode_pushPull,     /* RTS pin not used */
        &IfxAsclin0_TX_P15_2_OUT, IfxPort_OutputMode_pushPull,     /* Tx pin */
        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
#endif
    ascConfig.pins = &pins_bt;

    /* initialize module */
    IfxAsclin_Asc_initModule(&g_AsclinAscBt.drivers.asc, &ascConfig);

    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

    printf("Asclin Asc is initialised\n");

}

boolean AsclinAscBtComm(char * tx_ptr, char * rx_ptr){
	boolean success;
	uint16 tx_count, rx_count;
	tx_count = strlen(tx_ptr);
	rx_count = strlen(rx_ptr);

    memset(g_AsclinAscBt.txData, '\0', 16);
    memset(g_AsclinAscBt.rxData, '\0', 16);

    g_AsclinAscBt.count = tx_count;
    memcpy(g_AsclinAscBt.txData, tx_ptr, g_AsclinAscBt.count);
    IfxAsclin_Asc_write(&g_AsclinAscBt.drivers.asc, g_AsclinAscBt.txData, &g_AsclinAscBt.count, TIME_INFINITE);
    while(rx_count == IfxAsclin_Asc_getReadCount(&g_AsclinAscBt.drivers.asc)){
    	;
    }
    g_AsclinAscBt.count = rx_count;
	IfxAsclin_Asc_read(&g_AsclinAscBt.drivers.asc, g_AsclinAscBt.rxData, &g_AsclinAscBt.count, TIME_INFINITE);

	printf("tx: %s        rx(exp):%s 		rx:%s       ", tx_ptr, rx_ptr, g_AsclinAscBt.rxData );
	if( 0 == memcmp(g_AsclinAscBt.rxData, rx_ptr, rx_count)){
		success = TRUE;
		printf("Success\n");
	}
	else{
		success = FALSE;
	    printf("Fail\n");
	}
	return(success);
}


/** \brief Demo run API
 *
 * This function is called from main, background loop
 */
void AsclinAscBtDemo_run(void)
{
	volatile boolean status = FALSE;
	initTime();

    do{
    	status = AsclinAscBtComm("AT", "OK");
    	wait(TimeConst_100ms);
    }while(FALSE == status);

//    do{
//		status = AsclinAscBtComm("AT+VERSION", "OKlinvorV1.8");
//    	wait(TimeConst_100ms);
//    }while(FALSE == status);
//
    do{
    	status = AsclinAscBtComm("AT+NAMEMyRacer", "OKsetname");
    	wait(TimeConst_100ms);
    }while(FALSE == status);

    do{
    	status = AsclinAscBtComm("AT+PIN6802", "OKsetPIN");
    	wait(TimeConst_100ms);
    }while(FALSE == status);

    do{
//    	status = AsclinAscBtComm("AT+BAUD4", "OK9600");
    	status = AsclinAscBtComm("AT+BAUD8", "OK115200");
    	wait(TimeConst_100ms);
    }while(FALSE == status);

}
