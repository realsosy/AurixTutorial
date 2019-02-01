/**
 * \file IfxPsi5_PinMap.c
 * \brief PSI5 I/O map
 * \ingroup IfxLld_Psi5
 *
 * \version iLLD_1_0_1_8_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 */

#include "IfxPsi5_PinMap.h"

IfxPsi5_Rx_In IfxPsi5_RX0A_P00_1_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P00, 1}, Ifx_RxSel_a};
IfxPsi5_Rx_In IfxPsi5_RX0B_P02_3_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P02, 3}, Ifx_RxSel_b};
IfxPsi5_Rx_In IfxPsi5_RX0C_P33_1_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P33, 1}, Ifx_RxSel_c};
IfxPsi5_Rx_In IfxPsi5_RX1A_P00_3_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P00, 3}, Ifx_RxSel_a};
IfxPsi5_Rx_In IfxPsi5_RX1B_P02_5_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P02, 5}, Ifx_RxSel_b};
IfxPsi5_Rx_In IfxPsi5_RX1C_P33_3_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P33, 3}, Ifx_RxSel_c};
IfxPsi5_Rx_In IfxPsi5_RX2A_P00_5_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P00, 5}, Ifx_RxSel_a};
IfxPsi5_Rx_In IfxPsi5_RX2B_P02_7_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P02, 7}, Ifx_RxSel_b};
IfxPsi5_Rx_In IfxPsi5_RX2C_P33_5_IN = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P33, 5}, Ifx_RxSel_c};
IfxPsi5_Tx_Out IfxPsi5_TX0_P00_2_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P00, 2}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX0_P02_2_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P02, 2}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX0_P33_2_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_0, {&MODULE_P33, 2}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX1_P00_4_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX1_P02_6_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P02, 6}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX1_P33_4_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_1, {&MODULE_P33, 4}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX2_P00_6_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX2_P02_8_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P02, 8}, IfxPort_OutputIdx_alt4};
IfxPsi5_Tx_Out IfxPsi5_TX2_P33_6_OUT = {&MODULE_PSI5, IfxPsi5_ChannelId_2, {&MODULE_P33, 6}, IfxPort_OutputIdx_alt4};


const IfxPsi5_Rx_In *IfxPsi5_Rx_In_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_RX_IN_NUM_ITEMS] = {
    {
        {
            &IfxPsi5_RX0A_P00_1_IN,
            &IfxPsi5_RX0B_P02_3_IN,
            &IfxPsi5_RX0C_P33_1_IN
        },
        {
            &IfxPsi5_RX1A_P00_3_IN,
            &IfxPsi5_RX1B_P02_5_IN,
            &IfxPsi5_RX1C_P33_3_IN
        },
        {
            &IfxPsi5_RX2A_P00_5_IN,
            &IfxPsi5_RX2B_P02_7_IN,
            &IfxPsi5_RX2C_P33_5_IN
        }
    }
};

const IfxPsi5_Tx_Out *IfxPsi5_Tx_Out_pinTable[IFXPSI5_PINMAP_NUM_MODULES][IFXPSI5_PINMAP_NUM_CHANNELS][IFXPSI5_PINMAP_TX_OUT_NUM_ITEMS] = {
    {
        {
            &IfxPsi5_TX0_P00_2_OUT,
            &IfxPsi5_TX0_P02_2_OUT,
            &IfxPsi5_TX0_P33_2_OUT
        },
        {
            &IfxPsi5_TX1_P00_4_OUT,
            &IfxPsi5_TX1_P02_6_OUT,
            &IfxPsi5_TX1_P33_4_OUT
        },
        {
            &IfxPsi5_TX2_P00_6_OUT,
            &IfxPsi5_TX2_P02_8_OUT,
            &IfxPsi5_TX2_P33_6_OUT
        }
    }
};
