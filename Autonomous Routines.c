int auton_routine = 1; //Indicates which autonomous routine will run

void auton_skills() //The autonomous routine for the one minute skills challenge, auton_routine=0
{
	
}

void blueMobileAuton() //get high goal, auton_routine=1
{
	clearTimer(T1);
	while(time1(T1) < 750)
	{
		arm((2440-SensorValue[armPot])/2);
	}
	arm(0);
	
	goal(90);
	wait1Msec(500);
	goal(0);
	
	drive(127);
	wait1Msec(2750);
	drive(0);
	
	goal(-90);
	wait1Msec(500);
	goal(0);
	
	arm(-127);
	wait1Msec(500);
	arm(0);
	wait1Msec(250);
	
	drive(-127);
	wait1Msec(3000);
	drive(0);
	
	claw(100);
	clearTimer(T1);
	while(time1(T1) < 750)
	{
		arm((2440-SensorValue[armPot])/2);
	}
	arm(0);
	
	goal(90);
	drive(-127);
	wait1Msec(500);
	goal(0);
	wait1Msec(1000);
	drive(0);
}

void blueMobileDouble() //get mobile goal, auton_routine=2
{
	
}