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
			//cut power to COM
			break;
			
		case PLD1 :
			//cut power to PLD1
			break;
			
		case PLD2 :
			//cut power to PLD2
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

