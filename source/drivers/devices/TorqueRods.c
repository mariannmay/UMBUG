/////////////////////////////////////////
//	Torque Rods controlled by PWM
//	last edited by: Hossain-Al Masroor
//	date: February 1, 2012
//
//
//////////////////////////////////////////

#include "TorqueRods.h"

/*Use timers and switch port pin high/low
 *at defined intervals to cerate PWM output
 *Changing the Ton time the width of the
 *square wave can be varied keeping same
 *time period*/

//setup/initialize PWM
void setupPWM()
{
	//To DO
	//enable interrupts
	//start timer
	//enable timer interrupts

}


// initialize timers
void timerAinitialize(PWMOutput* pwmoutput)
{
		//TO DO
		//Configure timer registers
		//Divide task in two parts : High part
		//							and low part of the waveform
		//High part: set PWM output pin HIGH
		//Load high byte of timer with duty cycle value pwm_dc
		//clear timer interrupt flags
		//return from interrupts where the timer came from
		//Start low part by pulling pwm output pin low
		//Subtract duty cycle from some number say 255
		//clear timer interrupt flags
		//return from interrupt where the program came from


}

