float driveSpeedModifier()
{
	// if(vexRT[Btn8U] == 1)
	// {
		// return .7;
	// }
	// else
	// {
		return 1;
	// }
}

void leftDrive(int leftDrivePower)
{
	motor[driveLeftTop] = driveSpeedModifier() * leftDrivePower;
	motor[driveLeftBottom] = driveSpeedModifier() * leftDrivePower;
}

void rightDrive(int rightDrivePower)
{
	motor[driveRightTop] = driveSpeedModifier() * rightDrivePower;
	motor[driveRightBottom] = driveSpeedModifier() * rightDrivePower;
}

void drive(int drivePower)
{
	leftDrive(drivePower);
	rightDrive(drivePower);
}

void lift(int liftPower)
{
	motor[liftLeft] = liftPower;
	motor[liftRight] = liftPower;
}

void arm(int armPower)
{
	motor[armMotor] = armPower;
}

void claw(int clawPower)
{
	motor[clawMotor] = clawPower;
}

void goalGrab(int goalGrabberPower)
{
	motor[goalGrabber] = goalGrabberPower;
}

void pExtend()
{
	// SensorValue[rightCylinder] = 1;
	// SensorValue[leftCylinder] = 1;
}

void pRetract()
{
	// SensorValue[rightCylinder] = 0;
	// SensorValue[leftCylinder] = 0;
}

void goal(int goalPower) //up = positive, down = negative
{
	motor[goalMotor] = goalPower;
}

void goalUp()
{
	int goalUpPot = 1340;
	if((SensorValue[goalPot] < (goalUpPot + 100)) && (SensorValue[goalPot] > (goalUpPot - 100)))
	{
		motor[goalMotor] = ((SensorValue[goalPot] - goalUpPot)/3);
	}
	else
	{
		motor[goalMotor] = (SensorValue[goalPot] - goalUpPot);
	}
}

void goalDown()
{
	int goalDownPot = 3250;
	if((SensorValue[goalPot] > (goalDownPot - 20)))
	{
		motor[goalMotor] = 0;
	}
	else if((SensorValue[goalPot] < (goalDownPot + 150)) && (SensorValue[goalPot] > (goalDownPot - 150)))
	{
		motor[goalMotor] = ((SensorValue[goalPot] - goalDownPot)/2);
	}
	else
	{
		motor[goalMotor] = ((SensorValue[goalPot] - goalDownPot));
	}
}

void toGoalPos(int goalDownPot)
{
	if((SensorValue[goalPot] < (goalDownPot + 100)) && (SensorValue[goalPot] > (goalDownPot - 100)))
	{
		motor[goalMotor] = ((SensorValue[goalPot] - goalDownPot)/2);
	}
	else
	{
		motor[goalMotor] = (SensorValue[goalPot] - goalDownPot);
	}
}