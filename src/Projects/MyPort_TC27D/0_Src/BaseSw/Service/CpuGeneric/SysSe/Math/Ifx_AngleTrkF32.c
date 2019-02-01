/**
 * \file Ifx_AngleTrkF32.c
 * \brief Angle-tracking observer for sin/cos analog position sensor
 *
 *
 * \version disabled
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

//________________________________________________________________________________________
// INCLUDES

#include "Ifx_AngleTrkF32.h"
#include <math.h>
#include "string.h"
#include "Ifx_LutAtan2F32.h"

//________________________________________________________________________________________
// LOCAL DEFINITIONS

#define IFX_ANGLETRKF32_ATAN2F Ifx_LutAtan2F32_float32

//________________________________________________________________________________________
// LOCAL FUNCTION PROTOTYPES

void Ifx_AngleTrkF32_setUserSampling(Ifx_AngleTrkF32 *aObsv, float32 Ts);

//________________________________________________________________________________________
// GLOBAL VARIABLES

//________________________________________________________________________________________
// LOCAL VARIABLES

//________________________________________________________________________________________
// LOCAL FUNCTION IMPLEMENTATIONS

IFX_INLINE float32 Ifx_AngleTrkF32_bound(float32 angle, float32 periodPerRotation)
{
    float32 fullPeriod = 2 * IFX_PI;

    if (angle >= (fullPeriod / 2))
    {
        angle = angle - fullPeriod;
    }
    else if (angle < (-fullPeriod / 2))
    {
        angle = angle + fullPeriod;
    }
    else
    {}

    return angle;
}


IFX_INLINE float32 Ifx_AngleTrkF32_boundInput(float32 input)
{
    return Ifx_AngleTrkF32_bound(input, 1);
}


IFX_INLINE float32 round_f(float32 val)
{
    /*lint -e632 -e633 -e524*/
    sint32 val_i = (sint32)val;

    /*lint +e632 +e633 +e524*/
    if ((val - (float32)val_i) > 0.5)
    {
        val = (float32)(val_i + 1);
    }
    else
    {
        val = (float32)val_i;
    }

    return val;
}


//________________________________________________________________________________________
// PUBLIC FUNCTION IMPLEMENTATIONS
#define ATO_T   (15e-3f)
#define ATO_K   (39.05f)
#define ATO_PSI (1.5f * IFX_PI)

void Ifx_AngleTrkF32_setControlGains(Ifx_AngleTrkF32_CfgData *cfgData, float32 K, float32 T, float32 psi)
{
    cfgData->kp = ((2 * K) + (psi * psi) + 1) / (T * T);
    cfgData->ki = K * ((psi * psi) + 1) / (T * T * T);
    cfgData->kd = (K + 2) / T;
}


/** \brief Fill config with default values */
void Ifx_AngleTrkF32_initConfig(Ifx_AngleTrkF32_Config *config, sint16 *sinIn, sint16 *cosIn)
{
    Ifx_AngleTrkF32_CfgData cfgData;
    Ifx_AngleTrkF32_setControlGains(&cfgData, ATO_K, ATO_T, ATO_PSI);
    config->kp                = cfgData.kp;
    config->ki                = cfgData.ki;
    config->kd                = cfgData.kd;
    config->sinIn             = sinIn;
    config->cosIn             = cosIn;
    config->errorThreshold    = 5.0f / 180 * IFX_PI;
    config->sqrAmplMax        = (sint32)((1.01f * 1.01f) * 2048);
    config->sqrAmplMin        = (sint32)((0.99f * 0.99f) * 2048);
    config->speedLpfFc        = 100;
    config->periodPerRotation = 1;
    config->reversed          = FALSE;
    config->offset            = 0;
    config->resolution        = (1UL << 12);/** \brief 12-bit default resolution */
}


void Ifx_AngleTrkF32_setUserSampling(Ifx_AngleTrkF32 *aObsv, float32 Ts)
{
    aObsv->base.Ts = Ts;
    aObsv->halfTs  = aObsv->base.Ts / 2.0F;
}


/** \brief Initialize the Angle Tracking object
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 * \param config Pointer to the configuration data
 * \param Ts sampling period in seconds
 */
void Ifx_AngleTrkF32_init(Ifx_AngleTrkF32 *aObsv, const Ifx_AngleTrkF32_Config *config, float32 Ts)
{
    aObsv->base.offset            = config->offset;
    aObsv->base.resolution        = config->resolution;
    aObsv->base.reversed          = config->reversed;
    aObsv->base.Ts                = Ts;
    aObsv->base.rawPosition       = 0;
    aObsv->base.direction         = IfxStdIf_Pos_Dir_unknown;
    aObsv->base.turn              = 0;
    aObsv->base.status.status     = 0;
    aObsv->base.periodPerRotation = config->periodPerRotation;
    aObsv->base.positionConst     = 1.0 / (float32)aObsv->base.resolution * 2.0 * IFX_PI;

    aObsv->cfgData.kd             = config->kd;
    aObsv->cfgData.ki             = config->ki;
    aObsv->cfgData.kp             = config->kp;
    aObsv->cfgData.errorThreshold = config->errorThreshold;
    aObsv->cfgData.sqrAmplMax     = config->sqrAmplMax;
    aObsv->cfgData.sqrAmplMin     = config->sqrAmplMin;
    aObsv->sinIn                  = config->sinIn;
    aObsv->cosIn                  = config->cosIn;

    if (!__neqf(config->kp, 0) && !__neqf(config->ki, 0) && !__neqf(config->kp, 0))
    {   /* all gains are zero, use default */
        /* FIXME might not be requied as set by Ifx_AngleTrkF32_initConfig() */
        Ifx_AngleTrkF32_setControlGains(&aObsv->cfgData, ATO_K, ATO_T, ATO_PSI);
    }

    Ifx_AngleTrkF32_setUserSampling(aObsv, Ts);
    aObsv->angleErr  = 0.0F;
    aObsv->angleEst  = 0.0F;
    aObsv->accelEst  = 0.0F;
    aObsv->speedEstA = 0.0F;
    aObsv->speedEstB = 0.0F;
    aObsv->angleRef  = 0.0F;
    {
#if IFX_CFG_ANGLETRKF32_SPEED_FILTER
        Ifx_LowPassPt1F32_Config lpfConfig;
        lpfConfig.gain            = 1.0F;
        lpfConfig.cutOffFrequency = (2 * IFX_PI * config->speedLpfFc);
        lpfConfig.samplingTime    = Ts;
        Ifx_LowPassPt1F32_init(&aObsv->speedLpf, &lpfConfig);
#endif
    }
}


/** \brief Step function of Ifx_AngleTrkF32 should be called at every sampling period provided
 * during initialisation (call to Ifx_AngleTrkF32_init()).
 *
 * \note This function is automatically called by Ifx_AngleTrkF32_update()
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 * \param sinIn sine input signal. The offset shall be zero.
 * \param cosIn cosine input signal. The offset shall be zero.
 * \param phase phase of input signal.
 * \note This function returns the angular position in radians
 * \note The amplitude of both sinIn and cosIn signal shall be the same.
 */
float32 Ifx_AngleTrkF32_step(Ifx_AngleTrkF32 *aObsv, sint16 sinIn, sint16 cosIn, float32 phase)
{
    float32 angleRef, angleEst, dAccel, dSpeed, dAngle;

    if (aObsv->base.reversed != FALSE)
    {
        angleRef = IFX_ANGLETRKF32_ATAN2F((float32)cosIn, (float32)sinIn);
    }
    else
    {
        angleRef = IFX_ANGLETRKF32_ATAN2F((float32)sinIn, (float32)cosIn);
    }

    aObsv->angleAtan = angleRef;
    angleRef         = angleRef + phase;

    aObsv->angleRef  = angleRef;

    // Acceleration, zero-order-hold integrator:
    dAccel          = aObsv->cfgData.ki * aObsv->angleErr;
    aObsv->accelEst = aObsv->accelEst + (dAccel * aObsv->base.Ts);

    // Speed, zero-order-hold integrator:
    dSpeed           = ((aObsv->cfgData.kp * aObsv->angleErr) + aObsv->accelEst);
    aObsv->speedEstA = aObsv->speedEstA + (dSpeed * aObsv->base.Ts);

    // Angle, first-order-hold integrator:
    dAngle           = ((aObsv->cfgData.kd * aObsv->angleErr) + aObsv->speedEstA);
    angleEst         = aObsv->angleEst + ((dAngle + aObsv->speedEstB) * aObsv->halfTs);
    aObsv->speedEstB = dAngle;

    aObsv->angleEst  = Ifx_AngleTrkF32_boundInput(angleEst);

    // Error, is calculated here to compensate one period delay
    aObsv->angleErr       = Ifx_AngleTrkF32_boundInput(aObsv->angleRef - aObsv->angleEst);

    aObsv->base.direction = aObsv->speedEstB > 0 ? IfxStdIf_Pos_Dir_forward : IfxStdIf_Pos_Dir_backward;

#if IFX_CFG_ANGLETRKF32_SPEED_FILTER
    // Filter speed:
    Ifx_LowPassPt1F32_do(&aObsv->speedLpf, aObsv->speedEstB);
#endif

    return aObsv->angleEst;
}


/** \brief Set the position offset (in ticks)
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 * \param offset Position offset in ticks 
 */
void Ifx_AngleTrkF32_setOffset(Ifx_AngleTrkF32 *aObsv, IfxStdIf_Pos_RawAngle offset)
{
    Ifx_AngleTrkF32_PosIf *base = &aObsv->base;
    base->offset = offset;
}


/** \brief Update the status flags.
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 * \param sinIn Sinus value
 * \param cosIn Cosinus value
 * \note This function is automatically called by Ifx_AngleTrkF32_update()
 */
void Ifx_AngleTrkF32_updateStatus(Ifx_AngleTrkF32 *aObsv, sint16 sinIn, sint16 cosIn)
{
    Ifx_AngleTrkF32_PosIf *base    = &aObsv->base;
    sint32                  sqrAmpl = ((sint32)sinIn * (sint32)sinIn) + ((sint32)cosIn * (sint32)cosIn);
    base->status.B.signalLoss        = (sqrAmpl < aObsv->cfgData.sqrAmplMin);
    base->status.B.signalDegradation = (sqrAmpl > aObsv->cfgData.sqrAmplMax);
    base->status.B.trackingLoss      = __absf(aObsv->angleErr) > aObsv->cfgData.errorThreshold;
}


/** \brief Update the object directly from its analog input
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 */
void Ifx_AngleTrkF32_update(Ifx_AngleTrkF32 *aObsv)
{
    Ifx_AngleTrkF32_PosIf *base        = &aObsv->base;
    float32                 angleEst    = Ifx_AngleTrkF32_step(aObsv, *aObsv->sinIn, *aObsv->cosIn, 0);

    IfxStdIf_Pos_RawAngle   newPosition = (IfxStdIf_Pos_RawAngle)(angleEst * (aObsv->base.resolution / 2) / IFX_PI);
    newPosition       = newPosition & (aObsv->base.resolution - 1);
    base->rawPosition = newPosition;

    Ifx_AngleTrkF32_updateStatus(aObsv, *aObsv->sinIn, *aObsv->cosIn);
}


/** \brief Returns the actual position
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 * \note This function returns the angular position in ticks [0 .. Ifx_AngleTrkF32.base.resolution-1] (represents 0..360 degree)
 */
IfxStdIf_Pos_RawAngle Ifx_AngleTrkF32_getRawPosition(Ifx_AngleTrkF32 *aObsv)
{
    Ifx_AngleTrkF32_PosIf *base = &aObsv->base;
    return base->rawPosition;
}


/** \brief Returns the Speed
 * \param aObsv Pointer to the Ifx_AngleTrkF32 object
 */
float32 Ifx_AngleTrkF32_getSpeed(Ifx_AngleTrkF32 *aObsv)
{
    //return aObsv->speedEstB;   /* note: using speedEstB has better dynamic */
    return aObsv->speedLpf.out;
}


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
float32 Ifx_AngleTrkF32_getAbsolutePosition(Ifx_AngleTrkF32 *driver)
{
    return ((float32)driver->base.turn + (float32)driver->base.rawPosition / (float32)driver->base.resolution) * 2.0 * IFX_PI;
}


IfxStdIf_Pos_Dir Ifx_AngleTrkF32_getDirection(Ifx_AngleTrkF32 *driver)
{
    return driver->base.direction;
}


IfxStdIf_Pos_Status Ifx_AngleTrkF32_getFault(Ifx_AngleTrkF32 *driver)
{
    return driver->base.status;
}


sint32 Ifx_AngleTrkF32_getOffset(Ifx_AngleTrkF32 *driver)
{
    return driver->base.offset;
}


uint16 Ifx_AngleTrkF32_getPeriodPerRotation(Ifx_AngleTrkF32 *driver)
{
    return driver->base.periodPerRotation;
}


float32 Ifx_AngleTrkF32_getPosition(Ifx_AngleTrkF32 *driver)
{
    return (float32)driver->base.rawPosition * driver->base.positionConst;
}


float32 Ifx_AngleTrkF32_getRefreshPeriod(Ifx_AngleTrkF32 *driver)
{
    return driver->base.Ts;
}


sint32 Ifx_AngleTrkF32_getResolution(Ifx_AngleTrkF32 *driver)
{
    return driver->base.resolution;
}


IfxStdIf_Pos_SensorType Ifx_AngleTrkF32_getSensorType(Ifx_AngleTrkF32 *driver)
{
    return IfxStdIf_Pos_SensorType_angletrk;
}


sint32 Ifx_AngleTrkF32_getTurn(Ifx_AngleTrkF32 *driver)
{
    return driver->base.turn;
}


void Ifx_AngleTrkF32_resetFaults(Ifx_AngleTrkF32 *driver)
{
    driver->base.status.status = 0;
}


void Ifx_AngleTrkF32_setRefreshPeriod(Ifx_AngleTrkF32 *driver, float32 updatePeriod)
{
    driver->base.Ts = updatePeriod;
}


void Ifx_AngleTrkF32_reset(Ifx_AngleTrkF32 *driver)
{
    driver->base.rawPosition = 0;
    driver->base.direction   = IfxStdIf_Pos_Dir_unknown;
    driver->base.turn        = 0;
    driver->angleErr         = 0.0F;
    driver->angleEst         = 0.0F;
    driver->accelEst         = 0.0F;
    driver->speedEstA        = 0.0F;
    driver->speedEstB        = 0.0F;
    driver->angleRef         = 0.0F;
#if IFX_CFG_ANGLETRKF32_SPEED_FILTER
    Ifx_LowPassPt1F32_reset(&driver->speedLpf);
#endif

    driver->base.status.status = 0;
}


boolean Ifx_AngleTrkF32_stdIfPosInit(IfxStdIf_Pos *stdif, Ifx_AngleTrkF32 *driver)
{
    /* Ensure the stdif is reset to zeros */
    memset(stdif, 0, sizeof(IfxStdIf_Pos));

    /* Set the driver */
    stdif->driver = driver;

    /* *INDENT-OFF* Note: this file was indented manually by the author. */
    /* Set the API link */
	stdif->onZeroIrq          =(IfxStdIf_Pos_OnZeroIrq               )NULL_PTR;
	stdif->getAbsolutePosition=(IfxStdIf_Pos_GetAbsolutePosition     )&Ifx_AngleTrkF32_getAbsolutePosition;
	stdif->getDirection		  =(IfxStdIf_Pos_GetDirection            )&Ifx_AngleTrkF32_getDirection;
	stdif->getFault           =(IfxStdIf_Pos_GetFault                )&Ifx_AngleTrkF32_getFault;
	stdif->getOffset		  =(IfxStdIf_Pos_GetOffset			     )&Ifx_AngleTrkF32_getOffset;
	stdif->getPeriodPerRotation  =(IfxStdIf_Pos_GetPeriodPerRotation )&Ifx_AngleTrkF32_getPeriodPerRotation;
	stdif->getPosition		  =(IfxStdIf_Pos_GetPosition			 )&Ifx_AngleTrkF32_getPosition;
	stdif->getRawPosition	  =(IfxStdIf_Pos_GetRawPosition          )&Ifx_AngleTrkF32_getRawPosition;
	stdif->getRefreshPeriod   =(IfxStdIf_Pos_GetRefreshPeriod        )&Ifx_AngleTrkF32_getRefreshPeriod;
	stdif->getResolution      =(IfxStdIf_Pos_GetResolution           )&Ifx_AngleTrkF32_getResolution;
    stdif->getSensorType      =(IfxStdIf_Pos_GetSensorType           )&Ifx_AngleTrkF32_getSensorType;
	stdif->reset			  =(IfxStdIf_Pos_Reset				     )&Ifx_AngleTrkF32_reset;
	stdif->resetFaults		  =(IfxStdIf_Pos_ResetFaults			 )&Ifx_AngleTrkF32_resetFaults;
	stdif->getSpeed           =(IfxStdIf_Pos_GetSpeed                )&Ifx_AngleTrkF32_getSpeed;
	stdif->update			  =(IfxStdIf_Pos_Update				     )&Ifx_AngleTrkF32_update;
	stdif->setPosition		  =(IfxStdIf_Pos_SetPosition			 )NULL_PTR;
	stdif->setRawPosition	  =(IfxStdIf_Pos_SetRawPosition			 )NULL_PTR;
	stdif->setSpeed		      =(IfxStdIf_Pos_SetSpeed			     )NULL_PTR;
	stdif->setOffset		  =(IfxStdIf_Pos_SetOffset			     )&Ifx_AngleTrkF32_setOffset;
	stdif->setRefreshPeriod   =(IfxStdIf_Pos_SetRefreshPeriod        )&Ifx_AngleTrkF32_setRefreshPeriod;
	stdif->getTurn            =(IfxStdIf_Pos_GetTurn                 )&Ifx_AngleTrkF32_getTurn;
    /* *INDENT-ON* */

    return TRUE;
}
