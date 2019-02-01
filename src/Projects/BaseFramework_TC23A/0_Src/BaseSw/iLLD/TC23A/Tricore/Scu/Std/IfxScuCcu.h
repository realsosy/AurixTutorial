/**
 * \file IfxScuCcu.h
 * \brief SCU  basic functionality
 * \ingroup IfxLld_Scu
 *
 * \version iLLD_1_0_1_7_0
 * \copyright Copyright (c) 2017 Infineon Technologies AG. All rights reserved.
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
 *
 * \defgroup IfxLld_Scu SCU
 * \addtogroup IfxLld_Scu
 * \{
 * \defgroup IfxLld_ScuCcu How to use the Scu Clock driver?
 * \addtogroup IfxLld_ScuCcu
 * \{
 *
 * The Scu Clock control unit driver provides a default configuration for pll and Clock initialisation and set of peripheral clock configuration functions.
 *
 * In the following sections it will be described, how to integrate the driver into the application framework.
 *
 * \section IfxLld_ScuCcu_Std_Preparation Preparation
 * \subsection IfxLld_ScuCcu_Std_Include Include Files
 *
 * Include following header file into your C code:
 * \code
 * #include <Scu/Std/IfxScuCcu.h>
 * \endcode
 *
 * \subsection IfxLld_ScuCcu_Std_Variables Variables
 *
 * Declare the Clock Configuration variables in your C code:
 *
 * \code
 * // used globally
 *
 * // configuration for the PLL  steps
 * static IfxScuCcu_PllStepsConfig IfxScuCcu_testPllConfigSteps[] = {
 *     IFXSCU_CFG_PLL_STEPS
 * };
 *
 *
 * // Default configuration for the Clock Configuration
 * IfxScuCcu_Config                      IfxScuCcu_testClockConfig = {
 *     {
 *        sizeof(IfxScuCcu_testPllConfigSteps) / sizeof(IfxScuCcu_PllStepsConfig),
 *        (IfxScuCcu_PllStepsConfig *)IfxScuCcu_testPllConfigSteps,
 *        IFXSCU_CFG_PLL_INITIAL_STEP,
 *     },
 *     IFXSCU_CFG_CLK_DISTRIBUTION,
 *     IFXSCU_CFG_FLASH_WAITSTATE,
 *     IFX_CFG_SCU_XTAL_FREQUENCY
 * };
 *
 * \endcode
 *
 * \subsection IfxLld_ScuCcu_Std_Init Module Initialisation
 *
 * The module initialisation can be done in the same function. Here an example:
 * \code
 *
 *        // standard PLL & clock initialisation
 *         IfxScuCcu_init(&IfxScuCcu_testClockConfig);
 *
 * \endcode
 *
 *    The PLL and clocks are now initialised based on the IFXSCU_CFG_XTAL_FREQ and  IFXSCU_CFG_PLL_FREQ values configured in Ifx_Cfg.h.
 *
 * \}
 * \}
 *
 * \defgroup IfxLld_Scu_Std_Ccu Ccu Basic Functionality
 * \ingroup IfxLld_Scu_Std
 * \defgroup IfxLld_Scu_Std_Ccu_Ccu Clock Control Functions
 * \ingroup IfxLld_Scu_Std_Ccu
 * \defgroup IfxLld_Scu_Std_Ccu_Ccu_Operative Clock Control Operative Functions
 * \ingroup IfxLld_Scu_Std_Ccu
 * \defgroup IfxLld_Scu_Std_Ccu_Ccu_Configuration Clock Control Configuration Functions
 * \ingroup IfxLld_Scu_Std_Ccu
 * \defgroup IfxLld_Scu_Std_Ccu_Enum Enumerations
 * \ingroup IfxLld_Scu_Std_Ccu
 */

#ifndef IFXSCUCCU_H
#define IFXSCUCCU_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "_Impl/IfxScu_cfg.h"
#include "Scu/Std/IfxScuWdt.h"
#include "Cpu/Std/IfxCpu.h"
#include "IfxStm_reg.h"
#include "IfxScu_reg.h"
#include "IfxFlash_reg.h"
#include "_PinMap/IfxScu_PinMap.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Oscillator stability check timeout count
 */
#define IFXSCUCCU_OSC_STABLECHK_TIME (640)

/******************************************************************************/
/*------------------------------Type Definitions------------------------------*/
/******************************************************************************/

/** \brief Function pointer type for the hooks
 * \return None
 */
typedef void (*IfxScuCcu_PllStepsFunctionHook)(void);

/******************************************************************************/
/*--------------------------------Enumerations--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Scu_Std_Ccu_Enum
 * \{ */
/** \brief MODULE_SCU.PLLCON1.B.K1DIV, specifies the K1-Divider
 */
typedef enum
{
    IfxScuCcu_K1divider_1 = 0,      /**< \brief K1-Divider 1  */
    IfxScuCcu_K1divider_2,          /**< \brief K1-Divider 2  */
    IfxScuCcu_K1divider_3,          /**< \brief K1-Divider 3  */
    IfxScuCcu_K1divider_4,          /**< \brief K1-Divider 4  */
    IfxScuCcu_K1divider_5,          /**< \brief K1-Divider 5  */
    IfxScuCcu_K1divider_6,          /**< \brief K1-Divider 6  */
    IfxScuCcu_K1divider_7,          /**< \brief K1-Divider 7  */
    IfxScuCcu_K1divider_8,          /**< \brief K1-Divider 8  */
    IfxScuCcu_K1divider_9,          /**< \brief K1-Divider 9  */
    IfxScuCcu_K1divider_10,         /**< \brief K1-Divider 10  */
    IfxScuCcu_K1divider_11,         /**< \brief K1-Divider 11  */
    IfxScuCcu_K1divider_12,         /**< \brief K1-Divider 12  */
    IfxScuCcu_K1divider_13,         /**< \brief K1-Divider 13  */
    IfxScuCcu_K1divider_14,         /**< \brief K1-Divider 14  */
    IfxScuCcu_K1divider_15,         /**< \brief K1-Divider 15  */
    IfxScuCcu_K1divider_16,         /**< \brief K1-Divider 16  */
    IfxScuCcu_K1divider_17,         /**< \brief K1-Divider 17  */
    IfxScuCcu_K1divider_18,         /**< \brief K1-Divider 18  */
    IfxScuCcu_K1divider_19,         /**< \brief K1-Divider 19  */
    IfxScuCcu_K1divider_20,         /**< \brief K1-Divider 20  */
    IfxScuCcu_K1divider_21,         /**< \brief K1-Divider 21  */
    IfxScuCcu_K1divider_22,         /**< \brief K1-Divider 22  */
    IfxScuCcu_K1divider_23,         /**< \brief K1-Divider 23  */
    IfxScuCcu_K1divider_24,         /**< \brief K1-Divider 24  */
    IfxScuCcu_K1divider_25,         /**< \brief K1-Divider 25  */
    IfxScuCcu_K1divider_26,         /**< \brief K1-Divider 26  */
    IfxScuCcu_K1divider_27,         /**< \brief K1-Divider 27  */
    IfxScuCcu_K1divider_28,         /**< \brief K1-Divider 28  */
    IfxScuCcu_K1divider_29,         /**< \brief K1-Divider 29  */
    IfxScuCcu_K1divider_30,         /**< \brief K1-Divider 30  */
    IfxScuCcu_K1divider_31,         /**< \brief K1-Divider 31  */
    IfxScuCcu_K1divider_32,         /**< \brief K1-Divider 32  */
    IfxScuCcu_K1divider_33,         /**< \brief K1-Divider 33  */
    IfxScuCcu_K1divider_34,         /**< \brief K1-Divider 34  */
    IfxScuCcu_K1divider_35,         /**< \brief K1-Divider 35  */
    IfxScuCcu_K1divider_36,         /**< \brief K1-Divider 36  */
    IfxScuCcu_K1divider_37,         /**< \brief K1-Divider 37  */
    IfxScuCcu_K1divider_38,         /**< \brief K1-Divider 38  */
    IfxScuCcu_K1divider_39,         /**< \brief K1-Divider 39  */
    IfxScuCcu_K1divider_40,         /**< \brief K1-Divider 40  */
    IfxScuCcu_K1divider_41,         /**< \brief K1-Divider 41  */
    IfxScuCcu_K1divider_42,         /**< \brief K1-Divider 42  */
    IfxScuCcu_K1divider_43,         /**< \brief K1-Divider 43  */
    IfxScuCcu_K1divider_44,         /**< \brief K1-Divider 44  */
    IfxScuCcu_K1divider_45,         /**< \brief K1-Divider 45  */
    IfxScuCcu_K1divider_46,         /**< \brief K1-Divider 46  */
    IfxScuCcu_K1divider_47,         /**< \brief K1-Divider 47  */
    IfxScuCcu_K1divider_48,         /**< \brief K1-Divider 48  */
    IfxScuCcu_K1divider_49,         /**< \brief K1-Divider 49  */
    IfxScuCcu_K1divider_50,         /**< \brief K1-Divider 50  */
    IfxScuCcu_K1divider_51,         /**< \brief K1-Divider 51  */
    IfxScuCcu_K1divider_52,         /**< \brief K1-Divider 52  */
    IfxScuCcu_K1divider_53,         /**< \brief K1-Divider 53  */
    IfxScuCcu_K1divider_54,         /**< \brief K1-Divider 54  */
    IfxScuCcu_K1divider_55,         /**< \brief K1-Divider 55  */
    IfxScuCcu_K1divider_56,         /**< \brief K1-Divider 56  */
    IfxScuCcu_K1divider_57,         /**< \brief K1-Divider 57  */
    IfxScuCcu_K1divider_58,         /**< \brief K1-Divider 58  */
    IfxScuCcu_K1divider_59,         /**< \brief K1-Divider 59  */
    IfxScuCcu_K1divider_60,         /**< \brief K1-Divider 60  */
    IfxScuCcu_K1divider_61,         /**< \brief K1-Divider 61  */
    IfxScuCcu_K1divider_62,         /**< \brief K1-Divider 62  */
    IfxScuCcu_K1divider_63,         /**< \brief K1-Divider 63  */
    IfxScuCcu_K1divider_64,         /**< \brief K1-Divider 64  */
    IfxScuCcu_K1divider_65,         /**< \brief K1-Divider 65  */
    IfxScuCcu_K1divider_66,         /**< \brief K1-Divider 66  */
    IfxScuCcu_K1divider_67,         /**< \brief K1-Divider 67  */
    IfxScuCcu_K1divider_68,         /**< \brief K1-Divider 68  */
    IfxScuCcu_K1divider_69,         /**< \brief K1-Divider 69  */
    IfxScuCcu_K1divider_70,         /**< \brief K1-Divider 70  */
    IfxScuCcu_K1divider_71,         /**< \brief K1-Divider 71  */
    IfxScuCcu_K1divider_72,         /**< \brief K1-Divider 72  */
    IfxScuCcu_K1divider_73,         /**< \brief K1-Divider 73  */
    IfxScuCcu_K1divider_74,         /**< \brief K1-Divider 74  */
    IfxScuCcu_K1divider_75,         /**< \brief K1-Divider 75  */
    IfxScuCcu_K1divider_76,         /**< \brief K1-Divider 76  */
    IfxScuCcu_K1divider_77,         /**< \brief K1-Divider 77  */
    IfxScuCcu_K1divider_78,         /**< \brief K1-Divider 78  */
    IfxScuCcu_K1divider_79,         /**< \brief K1-Divider 79  */
    IfxScuCcu_K1divider_80,         /**< \brief K1-Divider 80  */
    IfxScuCcu_K1divider_81,         /**< \brief K1-Divider 81  */
    IfxScuCcu_K1divider_82,         /**< \brief K1-Divider 82  */
    IfxScuCcu_K1divider_83,         /**< \brief K1-Divider 83  */
    IfxScuCcu_K1divider_84,         /**< \brief K1-Divider 84  */
    IfxScuCcu_K1divider_85,         /**< \brief K1-Divider 85  */
    IfxScuCcu_K1divider_86,         /**< \brief K1-Divider 86  */
    IfxScuCcu_K1divider_87,         /**< \brief K1-Divider 87  */
    IfxScuCcu_K1divider_88,         /**< \brief K1-Divider 88  */
    IfxScuCcu_K1divider_89,         /**< \brief K1-Divider 89  */
    IfxScuCcu_K1divider_90,         /**< \brief K1-Divider 90  */
    IfxScuCcu_K1divider_91,         /**< \brief K1-Divider 91  */
    IfxScuCcu_K1divider_92,         /**< \brief K1-Divider 92  */
    IfxScuCcu_K1divider_93,         /**< \brief K1-Divider 93  */
    IfxScuCcu_K1divider_94,         /**< \brief K1-Divider 94  */
    IfxScuCcu_K1divider_95,         /**< \brief K1-Divider 95  */
    IfxScuCcu_K1divider_96,         /**< \brief K1-Divider 96  */
    IfxScuCcu_K1divider_97,         /**< \brief K1-Divider 97  */
    IfxScuCcu_K1divider_98,         /**< \brief K1-Divider 98  */
    IfxScuCcu_K1divider_99,         /**< \brief K1-Divider 99  */
    IfxScuCcu_K1divider_100,        /**< \brief K1-Divider 100  */
    IfxScuCcu_K1divider_101,        /**< \brief K1-Divider 101  */
    IfxScuCcu_K1divider_102,        /**< \brief K1-Divider 102  */
    IfxScuCcu_K1divider_103,        /**< \brief K1-Divider 103  */
    IfxScuCcu_K1divider_104,        /**< \brief K1-Divider 104  */
    IfxScuCcu_K1divider_105,        /**< \brief K1-Divider 105  */
    IfxScuCcu_K1divider_106,        /**< \brief K1-Divider 106  */
    IfxScuCcu_K1divider_107,        /**< \brief K1-Divider 107  */
    IfxScuCcu_K1divider_108,        /**< \brief K1-Divider 108  */
    IfxScuCcu_K1divider_109,        /**< \brief K1-Divider 109  */
    IfxScuCcu_K1divider_110,        /**< \brief K1-Divider 110  */
    IfxScuCcu_K1divider_111,        /**< \brief K1-Divider 111  */
    IfxScuCcu_K1divider_112,        /**< \brief K1-Divider 112  */
    IfxScuCcu_K1divider_113,        /**< \brief K1-Divider 113  */
    IfxScuCcu_K1divider_114,        /**< \brief K1-Divider 114  */
    IfxScuCcu_K1divider_115,        /**< \brief K1-Divider 115  */
    IfxScuCcu_K1divider_116,        /**< \brief K1-Divider 116  */
    IfxScuCcu_K1divider_117,        /**< \brief K1-Divider 117  */
    IfxScuCcu_K1divider_118,        /**< \brief K1-Divider 118  */
    IfxScuCcu_K1divider_119,        /**< \brief K1-Divider 119  */
    IfxScuCcu_K1divider_120,        /**< \brief K1-Divider 120  */
    IfxScuCcu_K1divider_121,        /**< \brief K1-Divider 121  */
    IfxScuCcu_K1divider_122,        /**< \brief K1-Divider 122  */
    IfxScuCcu_K1divider_123,        /**< \brief K1-Divider 123  */
    IfxScuCcu_K1divider_124,        /**< \brief K1-Divider 124  */
    IfxScuCcu_K1divider_125,        /**< \brief K1-Divider 125  */
    IfxScuCcu_K1divider_126,        /**< \brief K1-Divider 126  */
    IfxScuCcu_K1divider_127,        /**< \brief K1-Divider 127  */
    IfxScuCcu_K1divider_128         /**< \brief K1-Divider 128  */
} IfxScuCcu_K1divider;

/** \brief MODULE_SCU.PLLCON1.B.K2DIV, specifies the K2-Divider
 */
typedef enum
{
    IfxScuCcu_K2divider_1 = 0,      /**< \brief K2-Divider 1  */
    IfxScuCcu_K2divider_2,          /**< \brief K2-Divider 2  */
    IfxScuCcu_K2divider_3,          /**< \brief K2-Divider 3  */
    IfxScuCcu_K2divider_4,          /**< \brief K2-Divider 4  */
    IfxScuCcu_K2divider_5,          /**< \brief K2-Divider 5  */
    IfxScuCcu_K2divider_6,          /**< \brief K2-Divider 6  */
    IfxScuCcu_K2divider_7,          /**< \brief K2-Divider 7  */
    IfxScuCcu_K2divider_8,          /**< \brief K2-Divider 8  */
    IfxScuCcu_K2divider_9,          /**< \brief K2-Divider 9  */
    IfxScuCcu_K2divider_10,         /**< \brief K2-Divider 10  */
    IfxScuCcu_K2divider_11,         /**< \brief K2-Divider 11  */
    IfxScuCcu_K2divider_12,         /**< \brief K2-Divider 12  */
    IfxScuCcu_K2divider_13,         /**< \brief K2-Divider 13  */
    IfxScuCcu_K2divider_14,         /**< \brief K2-Divider 14  */
    IfxScuCcu_K2divider_15,         /**< \brief K2-Divider 15  */
    IfxScuCcu_K2divider_16,         /**< \brief K2-Divider 16  */
    IfxScuCcu_K2divider_17,         /**< \brief K2-Divider 17  */
    IfxScuCcu_K2divider_18,         /**< \brief K2-Divider 18  */
    IfxScuCcu_K2divider_19,         /**< \brief K2-Divider 19  */
    IfxScuCcu_K2divider_20,         /**< \brief K2-Divider 20  */
    IfxScuCcu_K2divider_21,         /**< \brief K2-Divider 21  */
    IfxScuCcu_K2divider_22,         /**< \brief K2-Divider 22  */
    IfxScuCcu_K2divider_23,         /**< \brief K2-Divider 23  */
    IfxScuCcu_K2divider_24,         /**< \brief K2-Divider 24  */
    IfxScuCcu_K2divider_25,         /**< \brief K2-Divider 25  */
    IfxScuCcu_K2divider_26,         /**< \brief K2-Divider 26  */
    IfxScuCcu_K2divider_27,         /**< \brief K2-Divider 27  */
    IfxScuCcu_K2divider_28,         /**< \brief K2-Divider 28  */
    IfxScuCcu_K2divider_29,         /**< \brief K2-Divider 29  */
    IfxScuCcu_K2divider_30,         /**< \brief K2-Divider 30  */
    IfxScuCcu_K2divider_31,         /**< \brief K2-Divider 31  */
    IfxScuCcu_K2divider_32,         /**< \brief K2-Divider 32  */
    IfxScuCcu_K2divider_33,         /**< \brief K2-Divider 33  */
    IfxScuCcu_K2divider_34,         /**< \brief K2-Divider 34  */
    IfxScuCcu_K2divider_35,         /**< \brief K2-Divider 35  */
    IfxScuCcu_K2divider_36,         /**< \brief K2-Divider 36  */
    IfxScuCcu_K2divider_37,         /**< \brief K2-Divider 37  */
    IfxScuCcu_K2divider_38,         /**< \brief K2-Divider 38  */
    IfxScuCcu_K2divider_39,         /**< \brief K2-Divider 39  */
    IfxScuCcu_K2divider_40,         /**< \brief K2-Divider 40  */
    IfxScuCcu_K2divider_41,         /**< \brief K2-Divider 41  */
    IfxScuCcu_K2divider_42,         /**< \brief K2-Divider 42  */
    IfxScuCcu_K2divider_43,         /**< \brief K2-Divider 43  */
    IfxScuCcu_K2divider_44,         /**< \brief K2-Divider 44  */
    IfxScuCcu_K2divider_45,         /**< \brief K2-Divider 45  */
    IfxScuCcu_K2divider_46,         /**< \brief K2-Divider 46  */
    IfxScuCcu_K2divider_47,         /**< \brief K2-Divider 47  */
    IfxScuCcu_K2divider_48,         /**< \brief K2-Divider 48  */
    IfxScuCcu_K2divider_49,         /**< \brief K2-Divider 49  */
    IfxScuCcu_K2divider_50,         /**< \brief K2-Divider 50  */
    IfxScuCcu_K2divider_51,         /**< \brief K2-Divider 51  */
    IfxScuCcu_K2divider_52,         /**< \brief K2-Divider 52  */
    IfxScuCcu_K2divider_53,         /**< \brief K2-Divider 53  */
    IfxScuCcu_K2divider_54,         /**< \brief K2-Divider 54  */
    IfxScuCcu_K2divider_55,         /**< \brief K2-Divider 55  */
    IfxScuCcu_K2divider_56,         /**< \brief K2-Divider 56  */
    IfxScuCcu_K2divider_57,         /**< \brief K2-Divider 57  */
    IfxScuCcu_K2divider_58,         /**< \brief K2-Divider 58  */
    IfxScuCcu_K2divider_59,         /**< \brief K2-Divider 59  */
    IfxScuCcu_K2divider_60,         /**< \brief K2-Divider 60  */
    IfxScuCcu_K2divider_61,         /**< \brief K2-Divider 61  */
    IfxScuCcu_K2divider_62,         /**< \brief K2-Divider 62  */
    IfxScuCcu_K2divider_63,         /**< \brief K2-Divider 63  */
    IfxScuCcu_K2divider_64,         /**< \brief K2-Divider 64  */
    IfxScuCcu_K2divider_65,         /**< \brief K2-Divider 65  */
    IfxScuCcu_K2divider_66,         /**< \brief K2-Divider 66  */
    IfxScuCcu_K2divider_67,         /**< \brief K2-Divider 67  */
    IfxScuCcu_K2divider_68,         /**< \brief K2-Divider 68  */
    IfxScuCcu_K2divider_69,         /**< \brief K2-Divider 69  */
    IfxScuCcu_K2divider_70,         /**< \brief K2-Divider 70  */
    IfxScuCcu_K2divider_71,         /**< \brief K2-Divider 71  */
    IfxScuCcu_K2divider_72,         /**< \brief K2-Divider 72  */
    IfxScuCcu_K2divider_73,         /**< \brief K2-Divider 73  */
    IfxScuCcu_K2divider_74,         /**< \brief K2-Divider 74  */
    IfxScuCcu_K2divider_75,         /**< \brief K2-Divider 75  */
    IfxScuCcu_K2divider_76,         /**< \brief K2-Divider 76  */
    IfxScuCcu_K2divider_77,         /**< \brief K2-Divider 77  */
    IfxScuCcu_K2divider_78,         /**< \brief K2-Divider 78  */
    IfxScuCcu_K2divider_79,         /**< \brief K2-Divider 79  */
    IfxScuCcu_K2divider_80,         /**< \brief K2-Divider 80  */
    IfxScuCcu_K2divider_81,         /**< \brief K2-Divider 81  */
    IfxScuCcu_K2divider_82,         /**< \brief K2-Divider 82  */
    IfxScuCcu_K2divider_83,         /**< \brief K2-Divider 83  */
    IfxScuCcu_K2divider_84,         /**< \brief K2-Divider 84  */
    IfxScuCcu_K2divider_85,         /**< \brief K2-Divider 85  */
    IfxScuCcu_K2divider_86,         /**< \brief K2-Divider 86  */
    IfxScuCcu_K2divider_87,         /**< \brief K2-Divider 87  */
    IfxScuCcu_K2divider_88,         /**< \brief K2-Divider 88  */
    IfxScuCcu_K2divider_89,         /**< \brief K2-Divider 89  */
    IfxScuCcu_K2divider_90,         /**< \brief K2-Divider 90  */
    IfxScuCcu_K2divider_91,         /**< \brief K2-Divider 91  */
    IfxScuCcu_K2divider_92,         /**< \brief K2-Divider 92  */
    IfxScuCcu_K2divider_93,         /**< \brief K2-Divider 93  */
    IfxScuCcu_K2divider_94,         /**< \brief K2-Divider 94  */
    IfxScuCcu_K2divider_95,         /**< \brief K2-Divider 95  */
    IfxScuCcu_K2divider_96,         /**< \brief K2-Divider 96  */
    IfxScuCcu_K2divider_97,         /**< \brief K2-Divider 97  */
    IfxScuCcu_K2divider_98,         /**< \brief K2-Divider 98  */
    IfxScuCcu_K2divider_99,         /**< \brief K2-Divider 99  */
    IfxScuCcu_K2divider_100,        /**< \brief K2-Divider 100  */
    IfxScuCcu_K2divider_101,        /**< \brief K2-Divider 101  */
    IfxScuCcu_K2divider_102,        /**< \brief K2-Divider 102  */
    IfxScuCcu_K2divider_103,        /**< \brief K2-Divider 103  */
    IfxScuCcu_K2divider_104,        /**< \brief K2-Divider 104  */
    IfxScuCcu_K2divider_105,        /**< \brief K2-Divider 105  */
    IfxScuCcu_K2divider_106,        /**< \brief K2-Divider 106  */
    IfxScuCcu_K2divider_107,        /**< \brief K2-Divider 107  */
    IfxScuCcu_K2divider_108,        /**< \brief K2-Divider 108  */
    IfxScuCcu_K2divider_109,        /**< \brief K2-Divider 109  */
    IfxScuCcu_K2divider_110,        /**< \brief K2-Divider 110  */
    IfxScuCcu_K2divider_111,        /**< \brief K2-Divider 111  */
    IfxScuCcu_K2divider_112,        /**< \brief K2-Divider 112  */
    IfxScuCcu_K2divider_113,        /**< \brief K2-Divider 113  */
    IfxScuCcu_K2divider_114,        /**< \brief K2-Divider 114  */
    IfxScuCcu_K2divider_115,        /**< \brief K2-Divider 115  */
    IfxScuCcu_K2divider_116,        /**< \brief K2-Divider 116  */
    IfxScuCcu_K2divider_117,        /**< \brief K2-Divider 117  */
    IfxScuCcu_K2divider_118,        /**< \brief K2-Divider 118  */
    IfxScuCcu_K2divider_119,        /**< \brief K2-Divider 119  */
    IfxScuCcu_K2divider_120,        /**< \brief K2-Divider 120  */
    IfxScuCcu_K2divider_121,        /**< \brief K2-Divider 121  */
    IfxScuCcu_K2divider_122,        /**< \brief K2-Divider 122  */
    IfxScuCcu_K2divider_123,        /**< \brief K2-Divider 123  */
    IfxScuCcu_K2divider_124,        /**< \brief K2-Divider 124  */
    IfxScuCcu_K2divider_125,        /**< \brief K2-Divider 125  */
    IfxScuCcu_K2divider_126,        /**< \brief K2-Divider 126  */
    IfxScuCcu_K2divider_127,        /**< \brief K2-Divider 127  */
    IfxScuCcu_K2divider_128         /**< \brief K2-Divider 128  */
} IfxScuCcu_K2divider;

/** \brief MODULE_SCU.PLLCON1.B.K3DIV, specifies the K3-Divider
 */
typedef enum
{
    IfxScuCcu_K3divider_1 = 0,      /**< \brief K3-Divider 1  */
    IfxScuCcu_K3divider_2,          /**< \brief K3-Divider 2  */
    IfxScuCcu_K3divider_3,          /**< \brief K3-Divider 3  */
    IfxScuCcu_K3divider_4,          /**< \brief K3-Divider 4  */
    IfxScuCcu_K3divider_5,          /**< \brief K3-Divider 5  */
    IfxScuCcu_K3divider_6,          /**< \brief K3-Divider 6  */
    IfxScuCcu_K3divider_7,          /**< \brief K3-Divider 7  */
    IfxScuCcu_K3divider_8,          /**< \brief K3-Divider 8  */
    IfxScuCcu_K3divider_9,          /**< \brief K3-Divider 9  */
    IfxScuCcu_K3divider_10,         /**< \brief K3-Divider 10  */
    IfxScuCcu_K3divider_11,         /**< \brief K3-Divider 11  */
    IfxScuCcu_K3divider_12,         /**< \brief K3-Divider 12  */
    IfxScuCcu_K3divider_13,         /**< \brief K3-Divider 13  */
    IfxScuCcu_K3divider_14,         /**< \brief K3-Divider 14  */
    IfxScuCcu_K3divider_15,         /**< \brief K3-Divider 15  */
    IfxScuCcu_K3divider_16,         /**< \brief K3-Divider 16  */
    IfxScuCcu_K3divider_17,         /**< \brief K3-Divider 17  */
    IfxScuCcu_K3divider_18,         /**< \brief K3-Divider 18  */
    IfxScuCcu_K3divider_19,         /**< \brief K3-Divider 19  */
    IfxScuCcu_K3divider_20,         /**< \brief K3-Divider 20  */
    IfxScuCcu_K3divider_21,         /**< \brief K3-Divider 21  */
    IfxScuCcu_K3divider_22,         /**< \brief K3-Divider 22  */
    IfxScuCcu_K3divider_23,         /**< \brief K3-Divider 23  */
    IfxScuCcu_K3divider_24,         /**< \brief K3-Divider 24  */
    IfxScuCcu_K3divider_25,         /**< \brief K3-Divider 25  */
    IfxScuCcu_K3divider_26,         /**< \brief K3-Divider 26  */
    IfxScuCcu_K3divider_27,         /**< \brief K3-Divider 27  */
    IfxScuCcu_K3divider_28,         /**< \brief K3-Divider 28  */
    IfxScuCcu_K3divider_29,         /**< \brief K3-Divider 29  */
    IfxScuCcu_K3divider_30,         /**< \brief K3-Divider 30  */
    IfxScuCcu_K3divider_31,         /**< \brief K3-Divider 31  */
    IfxScuCcu_K3divider_32,         /**< \brief K3-Divider 32  */
    IfxScuCcu_K3divider_33,         /**< \brief K3-Divider 33  */
    IfxScuCcu_K3divider_34,         /**< \brief K3-Divider 34  */
    IfxScuCcu_K3divider_35,         /**< \brief K3-Divider 35  */
    IfxScuCcu_K3divider_36,         /**< \brief K3-Divider 36  */
    IfxScuCcu_K3divider_37,         /**< \brief K3-Divider 37  */
    IfxScuCcu_K3divider_38,         /**< \brief K3-Divider 38  */
    IfxScuCcu_K3divider_39,         /**< \brief K3-Divider 39  */
    IfxScuCcu_K3divider_40,         /**< \brief K3-Divider 40  */
    IfxScuCcu_K3divider_41,         /**< \brief K3-Divider 41  */
    IfxScuCcu_K3divider_42,         /**< \brief K3-Divider 42  */
    IfxScuCcu_K3divider_43,         /**< \brief K3-Divider 43  */
    IfxScuCcu_K3divider_44,         /**< \brief K3-Divider 44  */
    IfxScuCcu_K3divider_45,         /**< \brief K3-Divider 45  */
    IfxScuCcu_K3divider_46,         /**< \brief K3-Divider 46  */
    IfxScuCcu_K3divider_47,         /**< \brief K3-Divider 47  */
    IfxScuCcu_K3divider_48,         /**< \brief K3-Divider 48  */
    IfxScuCcu_K3divider_49,         /**< \brief K3-Divider 49  */
    IfxScuCcu_K3divider_50,         /**< \brief K3-Divider 50  */
    IfxScuCcu_K3divider_51,         /**< \brief K3-Divider 51  */
    IfxScuCcu_K3divider_52,         /**< \brief K3-Divider 52  */
    IfxScuCcu_K3divider_53,         /**< \brief K3-Divider 53  */
    IfxScuCcu_K3divider_54,         /**< \brief K3-Divider 54  */
    IfxScuCcu_K3divider_55,         /**< \brief K3-Divider 55  */
    IfxScuCcu_K3divider_56,         /**< \brief K3-Divider 56  */
    IfxScuCcu_K3divider_57,         /**< \brief K3-Divider 57  */
    IfxScuCcu_K3divider_58,         /**< \brief K3-Divider 58  */
    IfxScuCcu_K3divider_59,         /**< \brief K3-Divider 59  */
    IfxScuCcu_K3divider_60,         /**< \brief K3-Divider 60  */
    IfxScuCcu_K3divider_61,         /**< \brief K3-Divider 61  */
    IfxScuCcu_K3divider_62,         /**< \brief K3-Divider 62  */
    IfxScuCcu_K3divider_63,         /**< \brief K3-Divider 63  */
    IfxScuCcu_K3divider_64,         /**< \brief K3-Divider 64  */
    IfxScuCcu_K3divider_65,         /**< \brief K3-Divider 65  */
    IfxScuCcu_K3divider_66,         /**< \brief K3-Divider 66  */
    IfxScuCcu_K3divider_67,         /**< \brief K3-Divider 67  */
    IfxScuCcu_K3divider_68,         /**< \brief K3-Divider 68  */
    IfxScuCcu_K3divider_69,         /**< \brief K3-Divider 69  */
    IfxScuCcu_K3divider_70,         /**< \brief K3-Divider 70  */
    IfxScuCcu_K3divider_71,         /**< \brief K3-Divider 71  */
    IfxScuCcu_K3divider_72,         /**< \brief K3-Divider 72  */
    IfxScuCcu_K3divider_73,         /**< \brief K3-Divider 73  */
    IfxScuCcu_K3divider_74,         /**< \brief K3-Divider 74  */
    IfxScuCcu_K3divider_75,         /**< \brief K3-Divider 75  */
    IfxScuCcu_K3divider_76,         /**< \brief K3-Divider 76  */
    IfxScuCcu_K3divider_77,         /**< \brief K3-Divider 77  */
    IfxScuCcu_K3divider_78,         /**< \brief K3-Divider 78  */
    IfxScuCcu_K3divider_79,         /**< \brief K3-Divider 79  */
    IfxScuCcu_K3divider_80,         /**< \brief K3-Divider 80  */
    IfxScuCcu_K3divider_81,         /**< \brief K3-Divider 81  */
    IfxScuCcu_K3divider_82,         /**< \brief K3-Divider 82  */
    IfxScuCcu_K3divider_83,         /**< \brief K3-Divider 83  */
    IfxScuCcu_K3divider_84,         /**< \brief K3-Divider 84  */
    IfxScuCcu_K3divider_85,         /**< \brief K3-Divider 85  */
    IfxScuCcu_K3divider_86,         /**< \brief K3-Divider 86  */
    IfxScuCcu_K3divider_87,         /**< \brief K3-Divider 87  */
    IfxScuCcu_K3divider_88,         /**< \brief K3-Divider 88  */
    IfxScuCcu_K3divider_89,         /**< \brief K3-Divider 89  */
    IfxScuCcu_K3divider_90,         /**< \brief K3-Divider 90  */
    IfxScuCcu_K3divider_91,         /**< \brief K3-Divider 91  */
    IfxScuCcu_K3divider_92,         /**< \brief K3-Divider 92  */
    IfxScuCcu_K3divider_93,         /**< \brief K3-Divider 93  */
    IfxScuCcu_K3divider_94,         /**< \brief K3-Divider 94  */
    IfxScuCcu_K3divider_95,         /**< \brief K3-Divider 95  */
    IfxScuCcu_K3divider_96,         /**< \brief K3-Divider 96  */
    IfxScuCcu_K3divider_97,         /**< \brief K3-Divider 97  */
    IfxScuCcu_K3divider_98,         /**< \brief K3-Divider 98  */
    IfxScuCcu_K3divider_99,         /**< \brief K3-Divider 99  */
    IfxScuCcu_K3divider_100,        /**< \brief K3-Divider 100  */
    IfxScuCcu_K3divider_101,        /**< \brief K3-Divider 101  */
    IfxScuCcu_K3divider_102,        /**< \brief K3-Divider 102  */
    IfxScuCcu_K3divider_103,        /**< \brief K3-Divider 103  */
    IfxScuCcu_K3divider_104,        /**< \brief K3-Divider 104  */
    IfxScuCcu_K3divider_105,        /**< \brief K3-Divider 105  */
    IfxScuCcu_K3divider_106,        /**< \brief K3-Divider 106  */
    IfxScuCcu_K3divider_107,        /**< \brief K3-Divider 107  */
    IfxScuCcu_K3divider_108,        /**< \brief K3-Divider 108  */
    IfxScuCcu_K3divider_109,        /**< \brief K3-Divider 109  */
    IfxScuCcu_K3divider_110,        /**< \brief K3-Divider 110  */
    IfxScuCcu_K3divider_111,        /**< \brief K3-Divider 111  */
    IfxScuCcu_K3divider_112,        /**< \brief K3-Divider 112  */
    IfxScuCcu_K3divider_113,        /**< \brief K3-Divider 113  */
    IfxScuCcu_K3divider_114,        /**< \brief K3-Divider 114  */
    IfxScuCcu_K3divider_115,        /**< \brief K3-Divider 115  */
    IfxScuCcu_K3divider_116,        /**< \brief K3-Divider 116  */
    IfxScuCcu_K3divider_117,        /**< \brief K3-Divider 117  */
    IfxScuCcu_K3divider_118,        /**< \brief K3-Divider 118  */
    IfxScuCcu_K3divider_119,        /**< \brief K3-Divider 119  */
    IfxScuCcu_K3divider_120,        /**< \brief K3-Divider 120  */
    IfxScuCcu_K3divider_121,        /**< \brief K3-Divider 121  */
    IfxScuCcu_K3divider_122,        /**< \brief K3-Divider 122  */
    IfxScuCcu_K3divider_123,        /**< \brief K3-Divider 123  */
    IfxScuCcu_K3divider_124,        /**< \brief K3-Divider 124  */
    IfxScuCcu_K3divider_125,        /**< \brief K3-Divider 125  */
    IfxScuCcu_K3divider_126,        /**< \brief K3-Divider 126  */
    IfxScuCcu_K3divider_127,        /**< \brief K3-Divider 127  */
    IfxScuCcu_K3divider_128         /**< \brief K3-Divider 128  */
} IfxScuCcu_K3divider;

/** \brief MODULE_SCU.PLLCON0.B.NDIV, specifies the N-Divider
 */
typedef enum
{
    IfxScuCcu_Ndivider_1 = 0,      /**< \brief  N-divider 1  */
    IfxScuCcu_Ndivider_2,          /**< \brief  N-divider 2  */
    IfxScuCcu_Ndivider_3,          /**< \brief  N-divider 3  */
    IfxScuCcu_Ndivider_4,          /**< \brief  N-divider 4  */
    IfxScuCcu_Ndivider_5,          /**< \brief  N-divider 5  */
    IfxScuCcu_Ndivider_6,          /**< \brief  N-divider 6  */
    IfxScuCcu_Ndivider_7,          /**< \brief  N-divider 7  */
    IfxScuCcu_Ndivider_8,          /**< \brief  N-divider 8  */
    IfxScuCcu_Ndivider_9,          /**< \brief  N-divider 9  */
    IfxScuCcu_Ndivider_10,         /**< \brief  N-divider 10  */
    IfxScuCcu_Ndivider_11,         /**< \brief  N-divider 11  */
    IfxScuCcu_Ndivider_12,         /**< \brief  N-divider 12  */
    IfxScuCcu_Ndivider_13,         /**< \brief  N-divider 13  */
    IfxScuCcu_Ndivider_14,         /**< \brief  N-divider 14  */
    IfxScuCcu_Ndivider_15,         /**< \brief  N-divider 15  */
    IfxScuCcu_Ndivider_16,         /**< \brief  N-divider 16  */
    IfxScuCcu_Ndivider_17,         /**< \brief  N-divider 17  */
    IfxScuCcu_Ndivider_18,         /**< \brief  N-divider 18  */
    IfxScuCcu_Ndivider_19,         /**< \brief  N-divider 19  */
    IfxScuCcu_Ndivider_20,         /**< \brief  N-divider 20  */
    IfxScuCcu_Ndivider_21,         /**< \brief  N-divider 21  */
    IfxScuCcu_Ndivider_22,         /**< \brief  N-divider 22  */
    IfxScuCcu_Ndivider_23,         /**< \brief  N-divider 23  */
    IfxScuCcu_Ndivider_24,         /**< \brief  N-divider 24  */
    IfxScuCcu_Ndivider_25,         /**< \brief  N-divider 25  */
    IfxScuCcu_Ndivider_26,         /**< \brief  N-divider 26  */
    IfxScuCcu_Ndivider_27,         /**< \brief  N-divider 27  */
    IfxScuCcu_Ndivider_28,         /**< \brief  N-divider 28  */
    IfxScuCcu_Ndivider_29,         /**< \brief  N-divider 29  */
    IfxScuCcu_Ndivider_30,         /**< \brief  N-divider 30  */
    IfxScuCcu_Ndivider_31,         /**< \brief  N-divider 31  */
    IfxScuCcu_Ndivider_32,         /**< \brief  N-divider 32  */
    IfxScuCcu_Ndivider_33,         /**< \brief  N-divider 33  */
    IfxScuCcu_Ndivider_34,         /**< \brief  N-divider 34  */
    IfxScuCcu_Ndivider_35,         /**< \brief  N-divider 35  */
    IfxScuCcu_Ndivider_36,         /**< \brief  N-divider 36  */
    IfxScuCcu_Ndivider_37,         /**< \brief  N-divider 37  */
    IfxScuCcu_Ndivider_38,         /**< \brief  N-divider 38  */
    IfxScuCcu_Ndivider_39,         /**< \brief  N-divider 39  */
    IfxScuCcu_Ndivider_40,         /**< \brief  N-divider 40  */
    IfxScuCcu_Ndivider_41,         /**< \brief  N-divider 41  */
    IfxScuCcu_Ndivider_42,         /**< \brief  N-divider 42  */
    IfxScuCcu_Ndivider_43,         /**< \brief  N-divider 43  */
    IfxScuCcu_Ndivider_44,         /**< \brief  N-divider 44  */
    IfxScuCcu_Ndivider_45,         /**< \brief  N-divider 45  */
    IfxScuCcu_Ndivider_46,         /**< \brief  N-divider 46  */
    IfxScuCcu_Ndivider_47,         /**< \brief  N-divider 47  */
    IfxScuCcu_Ndivider_48,         /**< \brief  N-divider 48  */
    IfxScuCcu_Ndivider_49,         /**< \brief  N-divider 49  */
    IfxScuCcu_Ndivider_50,         /**< \brief  N-divider 50  */
    IfxScuCcu_Ndivider_51,         /**< \brief  N-divider 51  */
    IfxScuCcu_Ndivider_52,         /**< \brief  N-divider 52  */
    IfxScuCcu_Ndivider_53,         /**< \brief  N-divider 53  */
    IfxScuCcu_Ndivider_54,         /**< \brief  N-divider 54  */
    IfxScuCcu_Ndivider_55,         /**< \brief  N-divider 55  */
    IfxScuCcu_Ndivider_56,         /**< \brief  N-divider 56  */
    IfxScuCcu_Ndivider_57,         /**< \brief  N-divider 57  */
    IfxScuCcu_Ndivider_58,         /**< \brief  N-divider 58  */
    IfxScuCcu_Ndivider_59,         /**< \brief  N-divider 59  */
    IfxScuCcu_Ndivider_60,         /**< \brief  N-divider 60  */
    IfxScuCcu_Ndivider_61,         /**< \brief  N-divider 61  */
    IfxScuCcu_Ndivider_62,         /**< \brief  N-divider 62  */
    IfxScuCcu_Ndivider_63,         /**< \brief  N-divider 63  */
    IfxScuCcu_Ndivider_64,         /**< \brief  N-divider 64  */
    IfxScuCcu_Ndivider_65,         /**< \brief  N-divider 65  */
    IfxScuCcu_Ndivider_66,         /**< \brief  N-divider 66  */
    IfxScuCcu_Ndivider_67,         /**< \brief  N-divider 67  */
    IfxScuCcu_Ndivider_68,         /**< \brief  N-divider 68  */
    IfxScuCcu_Ndivider_69,         /**< \brief  N-divider 69  */
    IfxScuCcu_Ndivider_70,         /**< \brief  N-divider 70  */
    IfxScuCcu_Ndivider_71,         /**< \brief  N-divider 71  */
    IfxScuCcu_Ndivider_72,         /**< \brief  N-divider 72  */
    IfxScuCcu_Ndivider_73,         /**< \brief  N-divider 73  */
    IfxScuCcu_Ndivider_74,         /**< \brief  N-divider 74  */
    IfxScuCcu_Ndivider_75,         /**< \brief  N-divider 75  */
    IfxScuCcu_Ndivider_76,         /**< \brief  N-divider 76  */
    IfxScuCcu_Ndivider_77,         /**< \brief  N-divider 77  */
    IfxScuCcu_Ndivider_78,         /**< \brief  N-divider 78  */
    IfxScuCcu_Ndivider_79,         /**< \brief  N-divider 79  */
    IfxScuCcu_Ndivider_80,         /**< \brief  N-divider 80  */
    IfxScuCcu_Ndivider_81,         /**< \brief  N-divider 81  */
    IfxScuCcu_Ndivider_82,         /**< \brief  N-divider 82  */
    IfxScuCcu_Ndivider_83,         /**< \brief  N-divider 83  */
    IfxScuCcu_Ndivider_84,         /**< \brief  N-divider 84  */
    IfxScuCcu_Ndivider_85,         /**< \brief  N-divider 85  */
    IfxScuCcu_Ndivider_86,         /**< \brief  N-divider 86  */
    IfxScuCcu_Ndivider_87,         /**< \brief  N-divider 87  */
    IfxScuCcu_Ndivider_88,         /**< \brief  N-divider 88  */
    IfxScuCcu_Ndivider_89,         /**< \brief  N-divider 89  */
    IfxScuCcu_Ndivider_90,         /**< \brief  N-divider 90  */
    IfxScuCcu_Ndivider_91,         /**< \brief  N-divider 91  */
    IfxScuCcu_Ndivider_92,         /**< \brief  N-divider 92  */
    IfxScuCcu_Ndivider_93,         /**< \brief  N-divider 93  */
    IfxScuCcu_Ndivider_94,         /**< \brief  N-divider 94  */
    IfxScuCcu_Ndivider_95,         /**< \brief  N-divider 95  */
    IfxScuCcu_Ndivider_96,         /**< \brief  N-divider 96  */
    IfxScuCcu_Ndivider_97,         /**< \brief  N-divider 97  */
    IfxScuCcu_Ndivider_98,         /**< \brief  N-divider 98  */
    IfxScuCcu_Ndivider_99,         /**< \brief  N-divider 99  */
    IfxScuCcu_Ndivider_100,        /**< \brief  N-divider 100  */
    IfxScuCcu_Ndivider_101,        /**< \brief  N-divider 101  */
    IfxScuCcu_Ndivider_102,        /**< \brief  N-divider 102  */
    IfxScuCcu_Ndivider_103,        /**< \brief  N-divider 103  */
    IfxScuCcu_Ndivider_104,        /**< \brief  N-divider 104  */
    IfxScuCcu_Ndivider_105,        /**< \brief  N-divider 105  */
    IfxScuCcu_Ndivider_106,        /**< \brief  N-divider 106  */
    IfxScuCcu_Ndivider_107,        /**< \brief  N-divider 107  */
    IfxScuCcu_Ndivider_108,        /**< \brief  N-divider 108  */
    IfxScuCcu_Ndivider_109,        /**< \brief  N-divider 109  */
    IfxScuCcu_Ndivider_110,        /**< \brief  N-divider 110  */
    IfxScuCcu_Ndivider_111,        /**< \brief  N-divider 111  */
    IfxScuCcu_Ndivider_112,        /**< \brief  N-divider 112  */
    IfxScuCcu_Ndivider_113,        /**< \brief  N-divider 113  */
    IfxScuCcu_Ndivider_114,        /**< \brief  N-divider 114  */
    IfxScuCcu_Ndivider_115,        /**< \brief  N-divider 115  */
    IfxScuCcu_Ndivider_116,        /**< \brief  N-divider 116  */
    IfxScuCcu_Ndivider_117,        /**< \brief  N-divider 117  */
    IfxScuCcu_Ndivider_118,        /**< \brief  N-divider 118  */
    IfxScuCcu_Ndivider_119,        /**< \brief  N-divider 119  */
    IfxScuCcu_Ndivider_120,        /**< \brief  N-divider 120  */
    IfxScuCcu_Ndivider_121,        /**< \brief  N-divider 121  */
    IfxScuCcu_Ndivider_122,        /**< \brief  N-divider 122  */
    IfxScuCcu_Ndivider_123,        /**< \brief  N-divider 123  */
    IfxScuCcu_Ndivider_124,        /**< \brief  N-divider 124  */
    IfxScuCcu_Ndivider_125,        /**< \brief  N-divider 125  */
    IfxScuCcu_Ndivider_126,        /**< \brief  N-divider 126  */
    IfxScuCcu_Ndivider_127,        /**< \brief  N-divider 127  */
    IfxScuCcu_Ndivider_128         /**< \brief  N-divider 128  */
} IfxScuCcu_Ndivider;

/** \brief MODULE_SCU.PLLCON0.B.PDIV, specifies the P-Divider
 */
typedef enum
{
    IfxScuCcu_Pdivider_1 = 0,      /**< \brief  P-divider 1  */
    IfxScuCcu_Pdivider_2,          /**< \brief  P-divider 2  */
    IfxScuCcu_Pdivider_3,          /**< \brief  P-divider 3  */
    IfxScuCcu_Pdivider_4,          /**< \brief  P-divider 4  */
    IfxScuCcu_Pdivider_5,          /**< \brief  P-divider 5  */
    IfxScuCcu_Pdivider_6,          /**< \brief  P-divider 6  */
    IfxScuCcu_Pdivider_7,          /**< \brief  P-divider 7  */
    IfxScuCcu_Pdivider_8,          /**< \brief  P-divider 8  */
    IfxScuCcu_Pdivider_9,          /**< \brief  P-divider 9  */
    IfxScuCcu_Pdivider_10,         /**< \brief  P-divider 10  */
    IfxScuCcu_Pdivider_11,         /**< \brief  P-divider 11  */
    IfxScuCcu_Pdivider_12,         /**< \brief  P-divider 12  */
    IfxScuCcu_Pdivider_13,         /**< \brief  P-divider 13  */
    IfxScuCcu_Pdivider_14,         /**< \brief  P-divider 14  */
    IfxScuCcu_Pdivider_15,         /**< \brief  P-divider 15  */
    IfxScuCcu_Pdivider_16          /**< \brief  P-divider 16  */
} IfxScuCcu_Pdivider;

/** \} */

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu
 * \{ */
/** \brief Configuration structure type for CCUCON registers.
 */
typedef struct
{
    uint32 value;       /**< \brief CCUCON Register value to be updated. */
    uint32 mask;        /**< \brief CCUCON Mask to select the bit fields to be updated. */
} IfxScuCcu_CcuconRegConfig;

/** \brief Configuration structure type for the Pll initial step.
 * This structure must be used to configure the P, N and K2 dividers for initial step.
 */
typedef struct
{
    uint8   pDivider;        /**< \brief P divider value for basic (initial) step */
    uint8   nDivider;        /**< \brief N divider value for basic (initial) step */
    uint8   k2Initial;       /**< \brief K2 divider value for basic (initial) step */
    float32 waitTime;        /**< \brief Wait time for for basic (initial) step */
} IfxScuCcu_InitialStepConfig;

/** \brief Configuration structure type for the Pll Steps for current jump control.
 */
typedef struct
{
    uint8                          k2Step;             /**< \brief K2 divider value for this step. */
    float32                        waitTime;           /**< \brief Wait time for for this step. */
    IfxScuCcu_PllStepsFunctionHook hookFunction;       /**< \brief Hook function called at the end of this step. */
} IfxScuCcu_PllStepsConfig;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu
 * \{ */
/** \brief Configuration structure type for all the CCUCON registers to configure clock distribution.
 */
typedef struct
{
    IfxScuCcu_CcuconRegConfig ccucon0;       /**< \brief CCUCON0 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon1;       /**< \brief CCUCON1 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon2;       /**< \brief CCUCON2 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon5;       /**< \brief CCUCON5 Register configuration */
    IfxScuCcu_CcuconRegConfig ccucon6;       /**< \brief CCUCON6 Register configuration */
} IfxScuCcu_ClockDistributionConfig;

/** \brief Configuration structure type for the Flash waitstate configuration.
 */
typedef struct
{
    uint32 value;       /**< \brief FLASH.FCON Register value to be updated. */
    uint32 mask;        /**< \brief FLASH.FCON Mask to select the bit fields to be updated. */
} IfxScuCcu_FlashWaitstateConfig;

/** \brief Configuration structure type for the System Pll step.
 * This structure must be used to configure the P, N and K1 dividers .
 */
typedef struct
{
    uint8                       numOfPllDividerSteps;       /**< \brief Number of PLL divider steps during clock throttling. */
    IfxScuCcu_PllStepsConfig   *pllDividerStep;             /**< \brief Pointer to the array of Pll divider step configuration. */
    IfxScuCcu_InitialStepConfig pllInitialStep;             /**< \brief Configuration of first step which is same as internal osc frequency. */
} IfxScuCcu_SysPllConfig;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu
 * \{ */
/** \brief Configuration structure SCU module
 */
typedef struct
{
    IfxScuCcu_SysPllConfig            sysPll;                         /**< \brief System PLL configuration */
    IfxScuCcu_ClockDistributionConfig clockDistribution;              /**< \brief Configuration of of bus clocks and other module clock distribution. */
    IfxScuCcu_FlashWaitstateConfig    flashFconWaitStateConfig;       /**< \brief Configuration of flash waitstate */
    uint32                            xtalFrequency;                  /**< \brief Xtal Frequency */
} IfxScuCcu_Config;

/** \brief Configuration structure for E-ray PLL
 */
typedef struct
{
    IfxScuCcu_InitialStepConfig pllInitialStep;       /**< \brief Configuration of first step which is same as internal osc frequency. */
} IfxScuCcu_ErayPllConfig;

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu_Operative
 * \{ */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to get EVR Oscillator frequency.
 * This API returns the constant which is specific to the ScuCcu of the controller.
 * \return EVR Oscillator frequency (fBACK or fEVR) in Hz.
 */
IFX_INLINE float32 IfxScuCcu_getEvrFrequency(void);

/** \brief API to get actual PLL2 (K3 Divider for ADC clock) frequency
 * This API returns the  PLL2 frequency based on the K3 divider value in PLLCON and the VCO frequency. This frequency is one of the configurable inputs to ADC clock.
 * \return PLL2 (K3 Divider for ADC clock) frequency in Hz
 */
IFX_INLINE float32 IfxScuCcu_getPll2Frequency(void);

/** \brief Returns the clock source selection
 * \return Clock source selection
 */
IFX_INLINE IfxScu_CCUCON0_CLKSEL IfxScuCcu_getSourceSelection(void);

/** \brief API to get STM divider frequency.
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * \return STM frequency (fSTM) in Hz
 */
IFX_INLINE float32 IfxScuCcu_getStmFrequency(void);

/** \brief API to get CAN divider frequency.
 * This API returns the fCAN frequency based on the divider value in CCUCON register and fSOURCE.
 * \return STM frequency (fSTM) in Hz
 */
IFX_INLINE float32 IfxScuCcu_getCanFrequency(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to get BAUD2 divider frequency.
 * This API returns the Baud2 frequency based on the divider value in CCUCON register and the fMAX.
 * \return Baud2 frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getBaud2Frequency(void);

/** \brief API to get BBB divider frequency.
 * This API returns the BBBDivider frequency based on the divider value in CCUCON register and the input oscillator.
 * \return BBB frequency (fBBB) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getBbbFrequency(void);

/** \brief This API returns the Cpu frequency based on the divider value in CCUCON register and fSource frequency
 * \param cpu CPU number for which effective fCPU is sought
 * \return Cpu[x] frequency in Hz, where x is cpu number passed as parameter
 */
IFX_EXTERN float32 IfxScuCcu_getCpuFrequency(const IfxCpu_ResourceCpu cpu);

/** \brief API to get FSI2 divider frequency in Hz.
 * This API returns the fFSI2 frequency based on the divider value in CCUCON register and the input oscillator.
 * \return FSI2 frequency (fFSI2) in Hz.
 */
IFX_EXTERN float32 IfxScuCcu_getFsi2Frequency(void);

/** \brief API to get FSI divider frequency in Hz.
 * This API returns the fFSI based on the divider value in CCUCON register and the input oscillator.
 * \return FSI frequency (fFSI) in Hz.
 */
IFX_EXTERN float32 IfxScuCcu_getFsiFrequency(void);

/** \brief API to get FMAX divider frequency.
 * This API returns the fMax frequency based on the divider value in CCUCON register and the input oscillator.
 * \return Max frequency (fMAX) in Hz.
 */
IFX_EXTERN float32 IfxScuCcu_getMaxFrequency(void);

/** \brief get source frequency fSOURCE.
 * This API returns the source frequency based on the configurations with CCUCON register configuration.
 * \return Module frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getModuleFrequency(void);

/** \brief API to get Oscillator 0 frequency.
 * This API returns the fOsc0 frequency based on the divider value in CCUCON register and the input oscillator.
 * \return Osc0 frequency (fOSC0) in Hz.
 */
IFX_EXTERN float32 IfxScuCcu_getOsc0Frequency(void);

/** \brief API to get Oscillator 0 frequency.
 * This API returns the fOsc0 frequency based on the divider value in CCUCON register and the input oscillator.
 * \return Osc frequency (fOSC) in Hz.
 */
IFX_EXTERN float32 IfxScuCcu_getOscFrequency(void);

/** \brief API to get actual PLL (Eray) frequency.
 * This API returns the based on the divider values in CCUCON, PLLCON registers and the input oscillator.
 * \return frequency of Pll Eray (fPLLERAY) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getPllErayFrequency(void);

/** \brief API to get actual ERAY PLL Voltage Controlled Oscillator frequency.
 * This API returns the based on the divider values in PLLERAYCON registers and the input oscillator.
 * \return Pll (Eray) VCO frequency
 */
IFX_EXTERN float32 IfxScuCcu_getPllErayVcoFrequency(void);

/** \brief API to get actual PLL output frequency.
 * This API returns the based on the divider values in CCUCON, PLLCON registers and the input oscillator.
 * \return Pll (fPLL) frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getPllFrequency(void);

/** \brief API to get actual PLL Voltage Controlled Oscillator frequency.
 * This API returns the based on the divider values in PLLCON registers and the input oscillator.
 * \return Pll VCO frequency
 */
IFX_EXTERN float32 IfxScuCcu_getPllVcoFrequency(void);

/** \brief get source frequency fSOURCE.
 * This API returns the source frequency based on the configurations with CCUCON register configuration.
 * \return Effective fSOURCE in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getSourceFrequency(void);

/** \brief API to get SPB divider frequency.
 * This API returns the based on fSOURCE and also on Low power divider mode and/or SPBDIV divider value in CCUCON registers.
 * \return SPB frequency (fSPB) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getSpbFrequency(void);

/** \brief API to get SRI divider frequency.
 * This API returns the Sri frequency based on the divider values in CCUCON registers and fSOURCE.
 * \return Sri frequency (fSRI) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_getSriFrequency(void);

/** \brief API to set CPU frequency (with CPU divider)
 * This API configure CPU divider values in CCUCON registers. The actual frequency is always depends on the feasibility with the divider value
 * \param cpu CPU number for which fCPU to be configured
 * \param cpuFreq Desired CPU frequency in Hz
 * \return Actual CPU[x] frequency in Hz, where x is the cpu number passed as parameter
 */
IFX_EXTERN float32 IfxScuCcu_setCpuFrequency(IfxCpu_ResourceCpu cpu, float32 cpuFreq);

/** \brief API to configure PLL2 (K3 Divider for ADC clock) for desired frequency.
 * This API configure K3 divider value in CCUCON. The actual frequency always depends on the feasibility with the divider value
 * \param pll2Freq PLL2 (K3 Divider for ADC clock) frequency in Hz
 * \return Actual PLL2 (K3 Divider for ADC clock) frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setPll2Frequency(float32 pll2Freq);

/** \brief API to set SPB frequency (with SPB divider)
 * This API configure SPB divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param spbFreq Desired SPB frequency in Hz
 * \return Actual SPB frequency in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setSpbFrequency(float32 spbFreq);

/** \brief API to set SRI frequency (with SRI divider)
 * This API configure Sri divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param sriFreq Sri frequency (fSRI) in Hz
 * \return Actual Sri frequency (fSRI) in Hz
 */
IFX_EXTERN float32 IfxScuCcu_setSriFrequency(float32 sriFreq);

/** \} */

/** \addtogroup IfxLld_Scu_Std_Ccu_Ccu_Configuration
 * \{ */

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief The api calculates the system PLL divider values P, N, K based on given xtal frequency and PLL frequency.
 * \param cfg Pointer to the configuration structure of the ScuCcu
 * \param fPll Desired PLL frequency.
 * \return 0- Success, 1 - Failure
 */
IFX_EXTERN boolean IfxScuCcu_calculateSysPllDividers(IfxScuCcu_Config *cfg, uint32 fPll);

/** \brief API to initialize the SCU Clock Control Unit.
 * This API initialize the PLL with ramp steps, BUS dividers for the configuration provided by the configuration structure.
 * \param cfg Pointer to the configuration structure of the ScuCcu
 * \return Error status of the ScuCcu initialization process.
 * \retval TRUE: If an error occurred during initialization.
 * \retval FALSE: If initialization was successful.
 */
IFX_EXTERN boolean IfxScuCcu_init(const IfxScuCcu_Config *cfg);

/** \brief Initializes the clock configuration with default values
 * \param cfg Pointer to the configuration structure of the ScuCcu
 * \return None
 */
IFX_EXTERN void IfxScuCcu_initConfig(IfxScuCcu_Config *cfg);

/** \brief API to initialize the SCU Eray Pll
 * This API initialize the Eray PLL for the configuration provided by the configuration structure.
 * \param cfg Pointer to the configuration structure of the Eray Pll
 * \return Error status of the ScuCcu Eray Pll initialization process.
 * \retval TRUE: If an error occurred during initialization.
 * \retval FALSE: If initialization was successful.
 */
IFX_EXTERN boolean IfxScuCcu_initErayPll(const IfxScuCcu_ErayPllConfig *cfg);

/** \brief Initializes the clock configuration with default values
 * \param cfg Pointer to the configuration structure of the ScuCcuEray Pll
 * \return None
 */
IFX_EXTERN void IfxScuCcu_initErayPllConfig(IfxScuCcu_ErayPllConfig *cfg);

/** \brief API to switch to Backup clock from the current PLL frequency.
 * \param cfg Pointer to the configuration structure of the ScuCcu
 * \return None
 */
IFX_EXTERN void IfxScuCcu_switchToBackupClock(const IfxScuCcu_Config *cfg);

/** \} */

/******************************************************************************/
/*-------------------------Inline Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to get GTMdivider frequency
 * This API returns the based on the divider value in CCUCON register and fSOURCE.
 * return GTM frequency (fGTM) in Hz
 * \return Gtm Frequency
 */
IFX_INLINE float32 IfxScuCcu_getGtmFrequency(void);

/******************************************************************************/
/*-------------------------Global Function Prototypes-------------------------*/
/******************************************************************************/

/** \brief API to set GTM frequency (with GTM divider)
 * This API configure GTM divider values in CCUCON registers. The actual frequency always depends on the feasibility with the divider value
 * \param gtmFreq Desired GTM frequency in Hz
 * \return Actual GTM frequency in HZ
 */
IFX_EXTERN float32 IfxScuCcu_setGtmFrequency(float32 gtmFreq);

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

/** \brief Configuration structure for SCU CCU driver.
 * The values of this structure are defined as # defined macros in the implementation of Scu
 */
IFX_EXTERN IFX_CONST IfxScuCcu_Config IfxScuCcu_defaultClockConfig;

/** \brief Configuration structure for SCU CCU driver.
 * The values of this structure are defined as # defined macros in the implementation of Scu
 */
IFX_EXTERN IFX_CONST IfxScuCcu_ErayPllConfig IfxScuCcu_defaultErayPllConfig;

/******************************************************************************/
/*---------------------Inline Function Implementations------------------------*/
/******************************************************************************/

IFX_INLINE float32 IfxScuCcu_getEvrFrequency(void)
{
    return IFXSCU_EVR_OSC_FREQUENCY;
}


IFX_INLINE float32 IfxScuCcu_getGtmFrequency(void)
{
    return IfxScuCcu_getSourceFrequency() / SCU_CCUCON1.B.GTMDIV;
}


IFX_INLINE float32 IfxScuCcu_getPll2Frequency(void)
{
    float32 pll2Frequency;
    pll2Frequency = IfxScuCcu_getPllVcoFrequency() / (SCU_PLLCON1.B.K3DIV + 1);

    return pll2Frequency;
}


IFX_INLINE IfxScu_CCUCON0_CLKSEL IfxScuCcu_getSourceSelection(void)
{
    return (IfxScu_CCUCON0_CLKSEL)SCU_CCUCON0.B.CLKSEL;
}


IFX_INLINE float32 IfxScuCcu_getStmFrequency(void)
{
    return IfxScuCcu_getSourceFrequency() / SCU_CCUCON1.B.STMDIV;
}


IFX_INLINE float32 IfxScuCcu_getCanFrequency(void)
{
    float32 canFrequency;
    float32 sourceFrequency;

    sourceFrequency = IfxScuCcu_getSourceFrequency();

    if (SCU_CCUCON1.B.CANDIV == 0)
    {
        canFrequency = 0.0;
    }
    else
    {
        canFrequency = sourceFrequency / SCU_CCUCON1.B.CANDIV;
    }

    return canFrequency;
}


#endif /* IFXSCUCCU_H */
