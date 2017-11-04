int auton_routine = 1; //Indicates which autonomous routine will run

void auton_skills() //The autonomous routine for the one minute skills challenge, auton_routine=0
{
	
}

void blueMobileAuton() //get mobile goal on the blue side, auton_routine=1
{
	sEncoderDrive(50, 1150);
	
	drive(20);
	clawRotation(-127);
	wait1Msec(600);
	clawRotation(0);
	drive(0);
	
	claw(127);
	wait1Msec(200);
	arm(-100);
	wait1Msec(700);
	arm(0);
	sEncoderDrive(127, 200);
	claw(0);
	
	arm(127);
	wait1Msec(200);
	arm(0);
}

void blueMobileDouble() //get two cones on the mobile goal
{
	sEncoderDrive(50, 1150);
	
	drive(20);
	clawRotation(-127);
	wait1Msec(600);
	clawRotation(0);
	drive(0);
	
	claw(127);
	wait1Msec(200);
	arm(-100);
	wait1Msec(700);
	arm(0);
	sEncoderDrive(127, 200);
	claw(0);
	
	arm(127);
	wait1Msec(200);
	arm(0);
}