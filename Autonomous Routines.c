int auton_routine = 1; //Indicates which autonomous routine will run
void auton_skills() //The autonomous routine for the one minute skills challenge, auton_routine=0
{
	sEncoDrive(-127, -1000);
}

void blueMobileAuton() //get high goal, auton_routine=1
{
	claw(-127);
	wait1Msec(300);
	clearTimer(T4);
	
	
	
	int actionTolerance = 40;
	int drivePower = 127;
	int driveEncoderValue = 1100;
	clearEncoders();
		for(int i = (drivePower/5); i < drivePower; i++)
		{
			drive(i);
			arm((2278-SensorValue[armPot])/10);
			wait1Msec(10);
			if((SensorValue[leftEncoder] > (driveEncoderValue - actionTolerance)) || (SensorValue[rightEncoder] > (driveEncoderValue - actionTolerance)))
			{
				i = drivePower;
			}
		}
		int leftPower = drivePower;
		int rightPower = drivePower;
		while((SensorValue[leftEncoder] < (driveEncoderValue - actionTolerance)) || (SensorValue[rightEncoder] < (driveEncoderValue - actionTolerance)))
		{
			goalDown();
			arm((2278-SensorValue[armPot])/10);
			if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
			{
				leftPower--;
				rightPower++;
			}
			else if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
			{
				leftPower++;
				rightPower--;
			}
			
			if(leftPower > drivePower)
			{
				leftPower = drivePower;
			}
			else if(rightPower > drivePower)
			{
				rightPower = drivePower;
			}
			if(leftPower < (drivePower/5))
			{
				leftPower = (drivePower/5);
			}
			else if(rightPower < (drivePower/5))
			{
				rightPower = (drivePower/5);
			}
			
			leftDrive(leftPower);
			rightDrive(rightPower);
		}
		
		for(int i = drivePower; i > (drivePower/5); i--)
		{
			drive(i);
			wait1Msec(10);
			if((SensorValue[leftEncoder] > (driveEncoderValue)) || (SensorValue[rightEncoder] > (driveEncoderValue)))
			{
				i = drivePower/5;
				
			}
		}
		drive(0);
	
	
	// while(time1(T4) < 2000)
	// {
		// arm((3700-SensorValue[armPot])/9);
	// }
	// while(SensorValue[armPot] < 2440 + 30) {
		// arm((2440-SensorValue[armPot])/10);
	// }
	// wait1Msec(100);
	// while(SensorValue[armPot] > 2440) {
		// arm((2440-SensorValue[armPot])/4);
	// }
	arm(0);
}

void blueMobileDouble() //get mobile goal, auton_routine=2
{
	claw(0);
	wait1Msec(400);
	clearTimer(T1);
	arm(127);
	wait1Msec(2000);
	arm(0);
	
	// while(SensorValue[lowerBumper] == 0)
	// {
		// motor[goalMotor] = -127;
	// }
	// motor[goalMotor] = 0;
	
	drive(127);
	wait1Msec(2750);
	drive(0);
	
	goalGrab(127);
	wait1Msec(600);
	goalGrab(35);
	
	motor[goalMotor] = 127;
	wait1Msec(1500);
	motor[goalMotor] = 0;
	
	wait1Msec(250);
	
	drive(-127);
	wait1Msec(2600);
	drive(0);
	
	leftDrive(-127);
	rightDrive(127);
	wait1Msec(1000);
	leftDrive(0);
	rightDrive(0);
	
	drive(127);
	wait1Msec(600);
	drive(0);
	
	clearTimer(T1);
	// while(SensorValue[lowerBumper] == 0)
	// {
		// motor[goalMotor] = -127;
	// }
	// while(time1(T1) < 1000) {}
	// motor[goalMotor] = 0;
	goalGrab(-127);
	wait1Msec(300);
	goalGrab(0);
	drive(-127);
	wait1Msec(1000);
	drive(0);
}

void auton_switchOptions() //contains names for autonomous routines
{
	switch(auton_routine) {
		case 0:
			displayLCDCenteredString(0, "Darude Sandstorm");
			break;
		case 1:
			displayLCDCenteredString(0, "Blue Mobile1Cone");
			break;
		case 2:
			displayLCDCenteredString(0, "BlueMobile2Cones");
			break;
		default:
			displayLCDCenteredString(0, "Error");
	}
}

void auton_switchLauncher() //contains method names that correlate with the routines
{
	switch(auton_routine) {
		case 0:
			auton_skills();
			break;
		case 1:
			blueMobileAuton();
			break;
		case 2:
			blueMobileDouble();
			break;
		default:
	}	
}
