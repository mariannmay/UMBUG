//////////////////////////////////////////////////////////////////
//                                                              //
//    STR source                                                //
//    last edited by: Matt Woelk                                //
//    date: 2012                                                //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "PWR.h"
#include "Power_Management.h"
#include "Power_Switching_Function.h"

// Runs on startup.
void initialize_pwr(void)
{
	// TODO
}

// Runs every time the scheduler allows PWR to act.
void pwr_routine(void)
{
	// TODO
}

// Cut or add power to a subsystem to conserve or stop conserving power.
void set_subsystem_power(SubsystemsToControlPowerTo subs, SubsBool ONoff)
{
	switch(subs)
	{
		case COM :
			//cut or apply power to COM
			//  set pin which controls COM power to be SubsBool
			if (ONoff)
			{
				//set pin 
				devices.pwrControllerCOM
			}else{
				//reset pin
			}
			break;
			
		case PLD1 :
			//cut or apply power to PLD1
			//  set pin which controls PLD1 power to be SubsBool
			if (ONoff)
			{
				//set pin 
			}else{
				//reset pin
			}
			break;
			
		case PLD2 :
			//cut or apply power to PLD2
			//  set pin which controls PLD2 power to be SubsBool
			if (ONoff)
			{
				//set pin 
			}else{
				//reset pin
			}
			break;
			
		default	  : ;
	}
}

void cut_power_from_subsystem(SubsystemsToControlPowerTo subs)
{
	set_subsystem_power(subs, subsOFF);
}

void add_power_to_subsystem(SubsystemsToControlPowerTo subs)
{
	set_subsystem_power(subs, subsON);
}

