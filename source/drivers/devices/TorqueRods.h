//////////////////////////////////////////
//	Torque Rods Header File				//
//	last edited by: Hossain-Al Masroor	//
//	date: February 1 , 2012				//
//										//
//										//
//////////////////////////////////////////

#ifndef TORQUERODS_H
#define TORQUERODS_H

#include <msp430fg4619.h>
#include "../DriversConfig.h"


//structures/////////////////////////////

typedef struct
{
		int x;
}TorqueRods;



typedef struct
{
	PWMIn	freq;
	PWMIn	dty_cycl;
	PWMOut	pwm_out0;
	PWMOut	pwm_out1;
	PWMOut	pwm_out2;
	PWMOut	pwm_out3;
	PWMOut	pwm_out4;
	PWMOut	pwm_out5;
	PWMOut	pwm_out6;
	PWMOut	pwm_out7;
	PWMOut	pwm_out8;



}PWMOutput;



//methods/////////////////////////////////
void setupPWM();
void timerAinitialize();





#endif /*TORQUERODS_H*/