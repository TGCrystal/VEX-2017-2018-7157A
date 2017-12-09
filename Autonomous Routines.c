int auton_routine = 1; //Indicates which autonomous routine will run

void auton_skills() //The autonomous routine for the one minute skills challenge, auton_routine=0
{
	
}

void blueMobileAuton() //get mobile goal on the blue side, auton_routine=1
{
	
	if(nImmediateBatteryLevel < 7550 && SensorValue[powerExpander] < 2050)
	{
		drive(80);
		wait1Msec(350);
		drive(0);
		
		claw(0);
		arm(127);
		wait1Msec(1800);
		claw(127);
		wait1Msec(1000);
		arm(0);
		wait1Msec(500);
		claw(0);
		
		lift(-127);
		wait1Msec(700);
		lift(0);
		
		arm(-127);
		drive(80);
		wait1Msec(1000);
		drive(0);
		wait1Msec(150);
		arm(0);
		wait1Msec(400);
		
		claw(127);
		wait1Msec(300);
		arm(127);
		wait1Msec(500);
		arm(0);
		drive(-127);
		wait1Msec(600);
		drive(0);
	}
	else if(nImmediateBatteryLevel < 8650 && SensorValue[powerExpander] < 2450)
	{	
		drive(70);
		wait1Msec(300);
		drive(0);
		
		claw(0);
		arm(100);
		wait1Msec(1600);
		claw(127);
		wait1Msec(1000);
		arm(0);
		wait1Msec(500);
		claw(0);
		
		lift(-127);
		wait1Msec(700);
		lift(0);
		
		arm(-127);
		drive(50);
		wait1Msec(950);
		drive(0);
		wait1Msec(150);
		arm(0);
		wait1Msec(400);
		
		claw(127);
		wait1Msec(300);
		arm(80);
		wait1Msec(500);
		arm(0);
		drive(-127);
		wait1Msec(600);
		drive(0);
	}
}

void blueMobileDouble() //get two cones on the mobile goal, auton_routine=2
{
	
}