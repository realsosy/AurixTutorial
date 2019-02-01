/**
 * \file IfxSent_PinMap.c
 * \brief SENT I/O map
 * \ingroup IfxLld_Sent
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

#include "IfxSent_PinMap.h"

IfxSent_Sent_In IfxSent_SENT0A_AN24_IN = {&MODULE_SENT, IfxSent_ChannelId_0, {NULL_PTR,24}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT0A_P40_0_IN = {&MODULE_SENT, IfxSent_ChannelId_0, {&MODULE_P40, 0}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT0B_P00_1_IN = {&MODULE_SENT, IfxSent_ChannelId_0, {&MODULE_P00, 1}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT0C_P02_8_IN = {&MODULE_SENT, IfxSent_ChannelId_0, {&MODULE_P02, 8}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT1A_AN25_IN = {&MODULE_SENT, IfxSent_ChannelId_1, {NULL_PTR,25}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT1A_P40_1_IN = {&MODULE_SENT, IfxSent_ChannelId_1, {&MODULE_P40, 1}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT1B_P00_2_IN = {&MODULE_SENT, IfxSent_ChannelId_1, {&MODULE_P00, 2}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT1C_P02_7_IN = {&MODULE_SENT, IfxSent_ChannelId_1, {&MODULE_P02, 7}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT2A_AN26_IN = {&MODULE_SENT, IfxSent_ChannelId_2, {NULL_PTR,26}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT2A_P40_2_IN = {&MODULE_SENT, IfxSent_ChannelId_2, {&MODULE_P40, 2}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT2B_P00_3_IN = {&MODULE_SENT, IfxSent_ChannelId_2, {&MODULE_P00, 3}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT2C_P02_6_IN = {&MODULE_SENT, IfxSent_ChannelId_2, {&MODULE_P02, 6}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT3A_AN27_IN = {&MODULE_SENT, IfxSent_ChannelId_3, {NULL_PTR,27}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT3A_P40_3_IN = {&MODULE_SENT, IfxSent_ChannelId_3, {&MODULE_P40, 3}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT3B_P00_4_IN = {&MODULE_SENT, IfxSent_ChannelId_3, {&MODULE_P00, 4}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT3C_P02_5_IN = {&MODULE_SENT, IfxSent_ChannelId_3, {&MODULE_P02, 5}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT4A_AN32_IN = {&MODULE_SENT, IfxSent_ChannelId_4, {NULL_PTR,32}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT4A_P40_4_IN = {&MODULE_SENT, IfxSent_ChannelId_4, {&MODULE_P40, 4}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT4B_P00_5_IN = {&MODULE_SENT, IfxSent_ChannelId_4, {&MODULE_P00, 5}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT4C_P33_6_IN = {&MODULE_SENT, IfxSent_ChannelId_4, {&MODULE_P33, 6}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT5A_AN33_IN = {&MODULE_SENT, IfxSent_ChannelId_5, {NULL_PTR,33}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT5A_P40_5_IN = {&MODULE_SENT, IfxSent_ChannelId_5, {&MODULE_P40, 5}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT5B_P00_6_IN = {&MODULE_SENT, IfxSent_ChannelId_5, {&MODULE_P00, 6}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT5C_P33_5_IN = {&MODULE_SENT, IfxSent_ChannelId_5, {&MODULE_P33, 5}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT6A_AN36_IN = {&MODULE_SENT, IfxSent_ChannelId_6, {NULL_PTR,36}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT6A_P40_6_IN = {&MODULE_SENT, IfxSent_ChannelId_6, {&MODULE_P40, 6}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT6B_P00_7_IN = {&MODULE_SENT, IfxSent_ChannelId_6, {&MODULE_P00, 7}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT6C_P33_4_IN = {&MODULE_SENT, IfxSent_ChannelId_6, {&MODULE_P33, 4}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT7A_AN37_IN = {&MODULE_SENT, IfxSent_ChannelId_7, {NULL_PTR,37}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT7A_P40_7_IN = {&MODULE_SENT, IfxSent_ChannelId_7, {&MODULE_P40, 7}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT7B_P00_8_IN = {&MODULE_SENT, IfxSent_ChannelId_7, {&MODULE_P00, 8}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT7C_P33_3_IN = {&MODULE_SENT, IfxSent_ChannelId_7, {&MODULE_P33, 3}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT8A_AN38_IN = {&MODULE_SENT, IfxSent_ChannelId_8, {NULL_PTR,38}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT8A_P40_8_IN = {&MODULE_SENT, IfxSent_ChannelId_8, {&MODULE_P40, 8}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT8B_P00_9_IN = {&MODULE_SENT, IfxSent_ChannelId_8, {&MODULE_P00, 9}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT8C_P33_2_IN = {&MODULE_SENT, IfxSent_ChannelId_8, {&MODULE_P33, 2}, Ifx_RxSel_c};
IfxSent_Sent_In IfxSent_SENT9A_AN39_IN = {&MODULE_SENT, IfxSent_ChannelId_9, {NULL_PTR,39}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT9A_P40_9_IN = {&MODULE_SENT, IfxSent_ChannelId_9, {&MODULE_P40, 9}, Ifx_RxSel_a};
IfxSent_Sent_In IfxSent_SENT9B_P00_10_IN = {&MODULE_SENT, IfxSent_ChannelId_9, {&MODULE_P00,10}, Ifx_RxSel_b};
IfxSent_Sent_In IfxSent_SENT9C_P33_1_IN = {&MODULE_SENT, IfxSent_ChannelId_9, {&MODULE_P33, 1}, Ifx_RxSel_c};
IfxSent_Spc_Out IfxSent_SPC0_P00_1_OUT = {&MODULE_SENT, IfxSent_ChannelId_0, {&MODULE_P00, 1}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC1_P02_7_OUT = {&MODULE_SENT, IfxSent_ChannelId_1, {&MODULE_P02, 7}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC2_P00_3_OUT = {&MODULE_SENT, IfxSent_ChannelId_2, {&MODULE_P00, 3}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC3_P00_4_OUT = {&MODULE_SENT, IfxSent_ChannelId_3, {&MODULE_P00, 4}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC4_P00_5_OUT = {&MODULE_SENT, IfxSent_ChannelId_4, {&MODULE_P00, 5}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC5_P00_6_OUT = {&MODULE_SENT, IfxSent_ChannelId_5, {&MODULE_P00, 6}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC6_P00_7_OUT = {&MODULE_SENT, IfxSent_ChannelId_6, {&MODULE_P00, 7}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC7_P00_8_OUT = {&MODULE_SENT, IfxSent_ChannelId_7, {&MODULE_P00, 8}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC8_P00_9_OUT = {&MODULE_SENT, IfxSent_ChannelId_8, {&MODULE_P00, 9}, IfxPort_OutputIdx_alt6};
IfxSent_Spc_Out IfxSent_SPC9_P00_10_OUT = {&MODULE_SENT, IfxSent_ChannelId_9, {&MODULE_P00,10}, IfxPort_OutputIdx_alt6};


const IfxSent_Sent_In *IfxSent_Sent_In_pinTable[IFXSENT_PINMAP_NUM_MODULES][IFXSENT_PINMAP_NUM_CHANNELS][IFXSENT_PINMAP_SENT_IN_NUM_ITEMS] = {
    {
        {
            &IfxSent_SENT0A_P40_0_IN,
            &IfxSent_SENT0B_P00_1_IN,
            &IfxSent_SENT0C_P02_8_IN
        },
        {
            &IfxSent_SENT1A_P40_1_IN,
            &IfxSent_SENT1B_P00_2_IN,
            &IfxSent_SENT1C_P02_7_IN
        },
        {
            &IfxSent_SENT2A_P40_2_IN,
            &IfxSent_SENT2B_P00_3_IN,
            &IfxSent_SENT2C_P02_6_IN
        },
        {
            &IfxSent_SENT3A_P40_3_IN,
            &IfxSent_SENT3B_P00_4_IN,
            &IfxSent_SENT3C_P02_5_IN
        },
        {
            &IfxSent_SENT4A_P40_4_IN,
            &IfxSent_SENT4B_P00_5_IN,
            &IfxSent_SENT4C_P33_6_IN
        },
        {
            &IfxSent_SENT5A_P40_5_IN,
            &IfxSent_SENT5B_P00_6_IN,
            &IfxSent_SENT5C_P33_5_IN
        },
        {
            &IfxSent_SENT6A_P40_6_IN,
            &IfxSent_SENT6B_P00_7_IN,
            &IfxSent_SENT6C_P33_4_IN
        },
        {
            &IfxSent_SENT7A_P40_7_IN,
            &IfxSent_SENT7B_P00_8_IN,
            &IfxSent_SENT7C_P33_3_IN
        },
        {
            &IfxSent_SENT8A_P40_8_IN,
            &IfxSent_SENT8B_P00_9_IN,
            &IfxSent_SENT8C_P33_2_IN
        },
        {
            &IfxSent_SENT9A_P40_9_IN,
            &IfxSent_SENT9B_P00_10_IN,
            &IfxSent_SENT9C_P33_1_IN
        }
    }
};

const IfxSent_Spc_Out *IfxSent_Spc_Out_pinTable[IFXSENT_PINMAP_NUM_MODULES][IFXSENT_PINMAP_NUM_CHANNELS][IFXSENT_PINMAP_SPC_OUT_NUM_ITEMS] = {
    {
        {
            &IfxSent_SPC0_P00_1_OUT
        },
        {
            &IfxSent_SPC1_P02_7_OUT
        },
        {
            &IfxSent_SPC2_P00_3_OUT
        },
        {
            &IfxSent_SPC3_P00_4_OUT
        },
        {
            &IfxSent_SPC4_P00_5_OUT
        },
        {
            &IfxSent_SPC5_P00_6_OUT
        },
        {
            &IfxSent_SPC6_P00_7_OUT
        },
        {
            &IfxSent_SPC7_P00_8_OUT
        },
        {
            &IfxSent_SPC8_P00_9_OUT
        },
        {
            &IfxSent_SPC9_P00_10_OUT
        }
    }
};
