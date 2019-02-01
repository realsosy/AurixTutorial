/**
 * \file IfxI2c_I2c.h
 * \brief I2C I2C details
 * \ingroup IfxLld_I2c
 *
 * \version iLLD_1_0_1_8_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_I2c_I2c_Usage How to use the I2c driver?
 * \ingroup IfxLld_I2c
 *
 * The I2c driver provides a default configuration for 8bit wide data transfers in Master mode.
 *
 * NOTE: Interrupts are disabled during data transfers as long as the driver operates on the I2C hardware FIFO,
 * except for reading 32 bytes or less. This is due to limitations of the I2c Module.
 *
 * NOTE : Send Slave address as 8-bit by left shifting it by 1.E.g incase of EEPROM,slave address is 7 bit represented
 * as 0x50, after left shifting it by 1, it will be 0xa0
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_I2c_I2c Preparation Preparation
 * \subsection IfxLld_I2c_I2c_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <I2c/I2c/IfxI2c_I2c.h>
 * \endcode
 *
 * \subsection IfxLld_I2c_I2c_Variables Variables
 *
 * Declare the I2c handle, the I2c device handle and the data buffer in your C code:
 *
 * \code
 * // used globally
 * static IfxI2c_I2c i2c;                      // i2c handle
 * static IfxI2c_I2c_Device i2cDev;    // slave device handle
 * uint8 data[128];                           // data buffer
 * \endcode
 *
 * \subsection IfxLld_I2c_I2c_Init Module Initialisation
 *
 * \code
 *     // create config structure
 *     IfxI2c_I2c_Config config;
 *
 *     // fill structure with default values and Module address
 *     IfxI2c_I2c_initConfig(&config, &MODULE_I2C0);
 *
 *     // configure pins
 *     const IfxI2c_Pins pins = {
 *         &IfxI2c0_SCL_P02_5_INOUT,
 *         &IfxI2c0_SDA_P02_4_INOUT,
 *         IfxPort_PadDriver_cmosAutomotiveSpeed1
 *     };
 *
 *     config.pins = &pins;
 *
 *     config.baudrate = 400000;   // 400 kHz
 *
 *     // initialize module
 *     IfxI2c_I2c_initModule(&i2c, &config);
 * \endcode
 *
 * \subsection IfxLld_I2c_I2c_InitDevice Device Initialisation
 * Here the i2c device handle is initialized.
 * \code
 *     // create device config
 *     IfxI2c_I2c_deviceConfig i2cDeviceConfig;
 *
 *     // fill structure with default values and i2c Handler
 *     IfxI2c_I2c_initDeviceConfig(&i2cDeviceConfig, &i2c);
 *
 *     // set device specifig values.
 *     i2cDeviceConfig.deviceAddress = 0xa0;  // 8 bit device address
 *
 *     // initialize the i2c device handle
 *     IfxI2c_I2c_initDevice(&i2cDev, &i2cDeviceConfig);
 * \endcode
 *
 * \section IfxLld_I2c_I2c_DataTransfers Data Transfers
 * Example for an i2c EEPROM.
 *
 * \subsection IfxLld_I2c_I2c_Write Write
 *
 * \code
 *     uint16 addr = 0x0000;
 *
 *     // setup the device's internal address
 *     data[0] = addr >> 8; // High byte
 *     data[1] = (uint8)addr; // Low byte
 *      // setup data to be written
 *      data[2] = 0x01;
 *      data[3] = 0x02;
 *      data[4] = 0x03;
 *
 *      uint8 size = 5; // 5 bytes to transmit to i2cDev (data and internal address)
 *
 *      // write data to device as soon as it is ready
 *      while(IfxI2c_I2c_write(&i2cDev, data, size) == IfxI2c_I2c_Status_nak);
 * \endcode
 *
 * \subsection IfxLld_I2c_I2c_Read Read
 *
 * \code
 *     Ifx_SizeT size;
 *     uint16    addr = 0x0000;
 *
 *     // setup internal address to be read from
 *     data[0] = addr >> 8; // High byte
 *     data[1] = (uint8)addr; // Low byte
 *     size = 2;
 *     while(IfxI2c_I2c_write(&i2cDev, data, size) == IfxI2c_I2c_Status_nak);
 *
 *     size = 8; // 8 bytes to read
 *
 *     // read device data to data array
 *     while(IfxI2c_I2c_read(&i2cDev, data, size) == IfxI2c_I2c_Status_nak);
 * \endcode
 *
 * \subsection IfxLld_I2c_I2c_ACK Acknowledge Polling
 * It is also possible to poll explicitly for NAK.
 *
 * By using write operations:
 * \code
 *     // size = 0;
 *     while(IfxI2c_I2c_write(&i2cDev, data, 0) == IfxI2c_I2c_Status_nak)); // where data is just a dummy pointer
 * \endcode
 *
 * By using read operations:
 * \code
 *     // size = 0;
 *     while(IfxI2c_I2c_read(&i2cDev, data, 0) == IfxI2c_I2c_Status_nak)); // where data is just a dummy pointer
 * \endcode
 *
 * \subsection IfxLld_I2c_I2c_Interrupts Interrupts usage
 *
 * Interrupts can be enabled from the application by using the APIs provided in the driver,
 * there are APIs available in the driver to enable, disable, clear and read the status of interrupt falgs, along with these,\n
 * APIs to enable the the interrupts are also available.
 *
 * here is an example of how to use the interrupts in I2C driver.
 *
 * Using I2C interrupts
 *
 *
 * I2C burst data transfer interrupt
 *
 * After initilaising I2C device \ref IfxLld_I2c_I2c_InitDevice
 *
 * choose the burst data transfer interrupt source needed to be enabled for I2C module and call the following function once and after choosing burst data transfer \n
 * interrupt source, enable burst data transfer service request or interrupt with the desired type of service and priority
 *
 * \code
 *     //enable burst data transfer interrupt source
 *     Ifx_I2C *i2c = &MODULE_I2C0; // or choose &MODULE_I2C1
 *     IfxI2c_enableBurstRequestInterruptSource(i2c);
 *
 *     // enable the burst data transfer interrupt
 *     IfxI2c_enableBurstDataTransferInterrupt(i2c, IfxSrc_Tos_cpu0, 8);
 * \endcode
 *
 * I2C last burst data transfer interrupt
 *
 * After initilaising I2C device \ref IfxLld_I2c_I2c_InitDevice
 *
 * choose the last burst data transfer interrupt source needed to be enabled for I2C module and call the following function once and after choosing last burst data transfer \n
 * interrupt source, enable burst data transfer service request or interrupt with the desired type of service and priority
 *
 * \code
 *     //enable last burst data transfer interrupt source
 *     Ifx_I2C *i2c = &MODULE_I2C0; // or choose &MODULE_I2C1
 *     IfxI2c_enableLastBurstRequestInterruptSource(i2c);
 *
 *     // enable the last burst data transfer interrupt
 *     IfxI2c_enableLastBurstDataTransferInterrupt(i2c, IfxSrc_Tos_cpu0, 8);
 * \endcode
 *
 * I2C single data transfer interrupt
 *
 * After initilaising I2C device \ref IfxLld_I2c_I2c_InitDevice
 *
 * choose the single data transfer interrupt source needed to be enabled for I2C module and call the following function once and after choosing single data transfer \n
 * interrupt source, enable single data transfer service request or interrupt with the desired type of service and priority
 *
 * \code
 *     //enable burst data transfer interrupt source
 *     Ifx_I2C *i2c = &MODULE_I2C0; // or choose &MODULE_I2C1
 *     IfxI2c_enableSingleRequestInterruptSource(i2c);
 *
 *     // enable the burst data transfer interrupt
 *     IfxI2c_enableSingleDataTransferInterrupt(i2c, IfxSrc_Tos_cpu0, 8);
 * \endcode
 *
 * I2C last single data transfer interrupt
 *
 * After initilaising I2C device \ref IfxLld_I2c_I2c_InitDevice
 *
 * choose the last single data transfer interrupt source needed to be enabled for I2C module and call the following function once and after choosing last single data transfer \n
 * interrupt source, enable last single data transfer service request or interrupt with the desired type of service and priority
 *
 * \code
 *     //enable burst data transfer interrupt source
 *     Ifx_I2C *i2c = &MODULE_I2C0; // or choose &MODULE_I2C1
 *     IfxI2c_enableLastSingleRequestInterruptSource(i2c);
 *
 *     // enable the burst data transfer interrupt
 *     IfxI2c_enableLastSingleDataTransferInterrupt(i2c, IfxSrc_Tos_cpu0, 8);
 * \endcode
 *
 * I2C error interrupt (ERR)
 *
 * After initilaising I2C device \ref IfxLld_I2c_I2c_InitDevice
 *
 * choose the error interrupt sources needed to be enabled for I2C module and call the following functions once for each error interrupt source by choosing the right \n
 * error interrupt source as parameter,and after choosing all the error interrupt sources, enable the I2C error interrupt flag and then enable I2C error service request or interrupt with desired type of service and priority
 *
 * \code
 *     //enable error interrupt sources
 *     Ifx_I2C *i2c = &MODULE_I2C0; // or choose &MODULE_I2C1
 *     IfxI2c_enableErrorInterruptSource(i2c, IfxI2c_ErrorInterruptSource_rxFifoUnderflow);
 *     IfxI2c_enableErrorInterruptSource(i2c, IfxI2c_ErrorInterruptSource_txFifoOverflow);
 *
 *     // enable the error interrupt flag
 *     IfxI2c_enableErrorInterruptFlag(Ifx_I2C *i2c);
 *
 *     // enable the error interrupt
 *     IfxI2c_enableErrorInterrupt(i2c, IfxSrc_Tos_cpu0, 8);
 * \endcode
 *
 *
 * I2C protocol interrupt (PROTOCOL)
 *
 * After initilaising I2C device \ref IfxLld_I2c_I2c_InitDevice
 *
 * choose the protocol interrupt sources needed to be enabled for I2C module and call the following functions once for each protocol interrupt source by choosing the \n
 * right protocol interrupt source as parameter,and after choosing all the protocol interrupt sources, enable the I2C protocol interrupt flag and then enable \n
 * I2C protocol service request or interrupt with desired type of service and priority
 *
 * \code
 *     //enable protocol interrupt sources
 *     Ifx_I2C *i2c = &MODULE_I2C0; // or choose &MODULE_I2C1
 *     IfxI2c_enableProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_addressMatch);
 *     IfxI2c_enableProtocolInterruptSource(i2c, IfxI2c_ProtocolInterruptSource_arbitrationLost);
 *
 *     // enable the protocol interrupt flag
 *     IfxI2c_enableProtocolInterruptFlag(Ifx_I2C *i2c);
 *
 *     // enable the protocol interrupt
 *     IfxI2c_enableProtocolInterrupt(i2c, IfxSrc_Tos_cpu0, 8);
 * \endcode
 *
 * you can define the ISR of your own and service the interrupt, please refer to more general usage of interrupts \ref IfxLld_Cpu_Irq_Usage
 *
 * some additional APIs to clear, disable interrupt flags and get flag status are also available.
 *
 * \defgroup IfxLld_I2c_I2c I2C
 * \ingroup IfxLld_I2c
 * \defgroup IfxLld_I2c_I2c_Functions Module Functions
 * \ingroup IfxLld_I2c_I2c
 * \defgroup IfxLld_I2c_I2c_Enum Enumerations
 * \ingroup IfxLld_I2c_I2c
 * \defgroup IfxLld_I2c_I2c_DataStructures Data Structures
 * \ingroup IfxLld_I2c_I2c
 */

#ifndef IFXI2C_I2C_H
#define IFXI2C_I2C_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "I2c/Std/IfxI2c.h"
#include "Cpu/Std/IfxCpu.h"

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_I2c_I2c_Enum
 * \{ */
typedef enum
{
    IfxI2c_I2c_Status_ok         = 0,  /**< \brief ok */
    IfxI2c_I2c_Status_nak        = 1,  /**< \brief NAK */
    IfxI2c_I2c_Status_al         = 2,  /**< \brief Arbitration Lost */
    IfxI2c_I2c_Status_busNotFree = 3,  /**< \brief bus is not free */
    IfxI2c_I2c_Status_error      = 4   /**< \brief error */
} IfxI2c_I2c_Status;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_I2c_I2c_DataStructures
 * \{ */
/** \brief Handler
 */
typedef struct
{
    Ifx_I2C          *i2c;             /**< \brief Module Pointer */
    IfxI2c_BusStatus  busStatus;       /**< \brief Status of the bus */
    IfxI2c_I2c_Status status;          /**< \brief Status of the last bus operation */
    float32           baudrate;        /**< \brief Baudrate */
} IfxI2c_I2c;

/** \brief Structure to configure the Module
 */
typedef struct
{
    Ifx_I2C               *i2c;            /**< \brief Module Pointer */
    float32                baudrate;       /**< \brief Baudrate */
    IFX_CONST IfxI2c_Pins *pins;           /**< \brief Pins */
} IfxI2c_I2c_Config;

/** \brief Structure with slave device data
 */
typedef struct
{
    IfxI2c_I2c *i2c;                 /**< \brief Module Pionter */
    uint8       deviceAddress;
} IfxI2c_I2c_Device;

/** \brief Structure to configure the device's data structure
 */
typedef struct
{
    IfxI2c_I2c *i2c;                 /**< \brief Module Pointer */
    uint8       deviceAddress;       /**< \brief the slave device's address */
} IfxI2c_I2c_deviceConfig;

/** \} */

/** \addtogroup IfxLld_I2c_I2c_Functions
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief Fills the config structure with default values
 * \param config Structure to configure the Module
 * \param i2c Module address
 * \return None
 */
IFX_EXTERN void IfxI2c_I2c_initConfig(IfxI2c_I2c_Config *config, Ifx_I2C *i2c);

/** \brief Initializes the device Handler
 * \param i2cDevice I2c device Handler
 * \param i2cDeviceConfig Structure to configure the device's data structure
 * \return None
 *
 * A coding example can be found in \ref IfxLld_I2c_I2c_Usage
 *
 */
IFX_EXTERN void IfxI2c_I2c_initDevice(IfxI2c_I2c_Device *i2cDevice, const IfxI2c_I2c_deviceConfig *i2cDeviceConfig);

/** \brief Fills the config structure of the slave device with default values.
 * \param i2cDeviceConfig Structure to configure the device's data structure
 * \param i2c Handler
 * \return None
 */
IFX_EXTERN void IfxI2c_I2c_initDeviceConfig(IfxI2c_I2c_deviceConfig *i2cDeviceConfig, IfxI2c_I2c *i2c);

/** \brief Initializes the Module
 * \param i2c Handler
 * \param config Configuration structure
 * \return None
 *
 * A coding example can be found in \ref IfxLld_I2c_I2c_Usage
 *
 */
IFX_EXTERN void IfxI2c_I2c_initModule(IfxI2c_I2c *i2c, const IfxI2c_I2c_Config *config);

/** \brief reads the I2c device
 *
 * A coding example can be found in \ref IfxLld_I2c_I2c_Usage
 *
 */
IFX_EXTERN IfxI2c_I2c_Status IfxI2c_I2c_read(IfxI2c_I2c_Device *i2cDevice, volatile uint8 *data, Ifx_SizeT size);

/** \brief writes to the I2c device
 *
 * A coding example can be found in \ref IfxLld_I2c_I2c_Usage
 *
 */
IFX_EXTERN IfxI2c_I2c_Status IfxI2c_I2c_write(IfxI2c_I2c_Device *i2cDevice, volatile uint8 *data, Ifx_SizeT size);

/** \} */

#endif /* IFXI2C_I2C_H */
