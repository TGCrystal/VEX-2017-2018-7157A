int auton_routine = 1; //Indicates which autonomous routine will run
void auton_test() //The autonomous routine for the one minute skills challenge, auton_routine=0
{
	drive(127);
}

int auton_time = 0;

void auton_rightMobile() //get high goal, auton_routine=1
{
	clearTimer(T1);
	claw(-127);
	wait1Msec(300);
	clearTimer(T4);
	
	int actionTolerance = 40;
	int drivePower = 127;
	int driveEncoderValue = 900;
	clearEncoders();
		for(int i = (drivePower/5); i < drivePower; i++)
		{
			drive(i);
			arm((2278-SensorValue[armPot])/10);
			if(SensorValue[goalPot] < 3250)
			{
				goal(-127);
			}
			else
			{
				goal(0);
			}
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
			if(SensorValue[goalPot] < 3250)
			{
				goal(-127);
			}
			else
			{
				goal(0);
			}
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
			if(SensorValue[goalPot] < 3250)
			{
				goal(-127);
			}
			else
			{
				goal(0);
			}
			wait1Msec(10);
			if((SensorValue[leftEncoder] > (driveEncoderValue)) || (SensorValue[rightEncoder] > (driveEncoderValue)))
			{
				i = drivePower/5;
				
			}
		}
		drive(0);
		arm(0);
	
	while(SensorValue[goalPot] > 1350)
	{
		goal(127);
	}
	goal(0);
	arm(-127);
	while(SensorValue[armPot] > 1250) {}
	arm(0);
	
	sEncoDrive(-127, -750);
	encoderDrive(-127, -400, 127, 400);
	claw(0);
	
	int leftPower = 46;
	int leftEncoderValue = 100;
	int rightPower = 127;
	int rightEncoderValue = 325;
	clearEncoders();
	leftEncoderValue = abs(leftEncoderValue);
	rightEncoderValue = abs(rightEncoderValue);
	clearTimer(T2);
	while(((abs(SensorValue[leftEncoder]) < leftEncoderValue) || (abs(SensorValue[rightEncoder]) < rightEncoderValue)) && (time1(T2) < 1000))
	{
		if(abs(SensorValue[leftEncoder]) < leftEncoderValue)
		{
			leftDrive(leftPower);
		}
		else
		{
			leftDrive(0);
		}
		if(abs(SensorValue[rightEncoder]) < rightEncoderValue)
		{
			rightDrive(rightPower);
		}
		else
		{
			rightDrive(0);
		}
	}
	rightDrive(0);
	leftDrive(0);
	
	drive(50);
	wait1Msec(400);
	drive(0);
	
	arm(127);
	while(SensorValue[armPot] < 2500) {}
	arm(0);
	
	goal(-127);
	while(SensorValue[goalPot] < 2465) {}
	goal(0);
	
	sEncoDrive(-127, -150);
	
	
	encoderDrive(-127, -220, 127, 220);
	
	sEncoDrive(127, 500);
	
	encoderDrive(-127, -100, 127, 100);
	
	sEncoDrive(127, 250);
	
	encoderDrive(-127, -100, 127, 100);
	
	auton_time = time1(T1);
}

void auton_leftMobile() //get mobile goal, auton_routine=2
{
	clearTimer(T1);
	claw(-127);
	wait1Msec(300);
	clearTimer(T4);
	
	int actionTolerance = 40;
	int drivePower = 127;
	int driveEncoderValue = 900;
	clearEncoders();
		for(int i = (drivePower/5); i < drivePower; i++)
		{
			drive(i);
			arm((2278-SensorValue[armPot])/10);
			if(SensorValue[goalPot] < 3250)
			{
				goal(-127);
			}
			else
			{
				goal(0);
			}
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
			if(SensorValue[goalPot] < 3250)
			{
				goal(-127);
			}
			else
			{
				goal(0);
			}
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
			if(SensorValue[goalPot] < 3250)
			{
				goal(-127);
			}
			else
			{
				goal(0);
			}
			wait1Msec(10);
			if((SensorValue[leftEncoder] > (driveEncoderValue)) || (SensorValue[rightEncoder] > (driveEncoderValue)))
			{
				i = drivePower/5;
				
			}
		}
		drive(0);
		arm(0);
	
	while(SensorValue[goalPot] > 1350)
	{
		goal(127);
	}
	goal(0);
	arm(-127);
	while(SensorValue[armPot] > 1250) {}
	arm(0);
	
	sEncoDrive(-127, -750);
	encoderDrive(127, 400, -127, -400);
	claw(0);
	
	int leftPower = 127;
	int leftEncoderValue = 325;
	int rightPower = 46;
	int rightEncoderValue = 100;
	clearEncoders();
	leftEncoderValue = abs(leftEncoderValue);
	rightEncoderValue = abs(rightEncoderValue);
	clearTimer(T2);
	while(((abs(SensorValue[leftEncoder]) < leftEncoderValue) || (abs(SensorValue[rightEncoder]) < rightEncoderValue)) && (time1(T2) < 1000))
	{
		if(abs(SensorValue[leftEncoder]) < leftEncoderValue)
		{
			leftDrive(leftPower);
		}
		else
		{
			leftDrive(0);
		}
		if(abs(SensorValue[rightEncoder]) < rightEncoderValue)
		{
			rightDrive(rightPower);
		}
		else
		{
			rightDrive(0);
		}
	}
	rightDrive(0);
	leftDrive(0);
	
	drive(50);
	wait1Msec(400);
	drive(0);
	
	arm(127);
	while(SensorValue[armPot] < 2500) {}
	arm(0);
	
	goal(-127);
	while(SensorValue[goalPot] < 2465) {}
	goal(0);
	
	sEncoDrive(-127, -150);
	
	
	encoderDrive(127, 220, -127, -220);
	
	sEncoDrive(127, 500);
	
	encoderDrive(127, 100, -127, -100);
	
	sEncoDrive(127, 250);
	
	encoderDrive(127, 100, -127, -100);
	
	auton_time = time1(T1);
}

void auton_rightMobile20() //auton_routine=3
{
	
}

void auton_leftMobile20() //auton_routine=4
{
	
}

void auton_switchOptions() //contains names for autonomous routines
{
	switch(auton_routine) {
		case 0:
			displayLCDCenteredString(0, " Straight Test  ");
			break;
		case 1:
			displayLCDCenteredString(0, "1RightMobileGoal");
			break;
		case 2:
			displayLCDCenteredString(0, "1Left MobileGoal");
			break;
		case 3:
			displayLCDCenteredString(0, "2RightMobileGoal");
			break;
		case 4:
			displayLCDCenteredString(0, "2LeftMobile Goal");
			break;
		default:
			displayLCDCenteredString(0, "Error");
	}
}

void auton_switchLauncher() //contains method names that correlate with the routines
{
	switch(auton_routine) {
		case 0:
			auton_test();
			break;
		case 1:
			auton_rightMobile();
			break;
		case 2:
			auton_leftMobile();
			break;
		case 3:
			auton_rightMobile20();
			break;
		case 4:
			auton_leftMobile20();
			break;
		default:
	}	
}
