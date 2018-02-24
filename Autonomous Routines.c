int auton_routine = 2; //Indicates which autonomous routine will run

void auton_skills() //The autonomous routine for the one minute skills challenge, auton_routine=0
{
	
}

void blueMobileAuton() //get high goal, auton_routine=1
{
	
	while(SensorValue[lowerBumper] == 0)
	{
		motor[goalMotor] = -127;
	}
	motor[goalMotor] = 0;
	
}

void blueMobileDouble() //get mobile goal, auton_routine=2
{
claw(0);
	clearTimer(T1);
	while(time1(T1) < 1750)
	{
		arm((2440-SensorValue[armPot])/2);
	}
	arm(0);
	
	while(SensorValue[lowerBumper] == 0)
	{
		motor[goalMotor] = -127;
	}
	motor[goalMotor] = 0;
	
	drive(127);
	wait1Msec(2750);
	drive(0);
	
	while((SensorValue[upperBumper1]+SensorValue[upperBumper2]) == 0)
	{
		motor[goalMotor] = 127;
	}
	
	arm(-127);
	wait1Msec(500);
	arm(0);
	wait1Msec(250);
	
	drive(-127);
	wait1Msec(2600);
	drive(0);
	
	leftDrive(-127);
	rightDrive(127);
	wait1Msec(1000);
	leftDrive(0);
	rightDrive(0);
	
	claw(100);
	clearTimer(T1);
	while(time1(T1) < 750)
	{
		arm((2440-SensorValue[armPot])/2);
	}
	arm(0);
	
	clearTimer(T1);
	while(SensorValue[lowerBumper] == 0)
	{
		motor[goalMotor] = -127;
	}
	while(time1(T1) < 1000) {}
	motor[goalMotor] = 0;
	wait1Msec(1000);
	drive(0);
}