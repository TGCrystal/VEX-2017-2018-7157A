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
	SensorValue[rightCylinder] = 1;
	// SensorValue[leftCylinder] = 1;
}

void pRetract()
{
	SensorValue[rightCylinder] = 0;
	// SensorValue[leftCylinder] = 0;
}

void goal(int goalPower)
{
	// motor[goalMotor] = (((2*(SensorValue[lowerBumper]))-1)*abs(goalPower) + goalPower)/2;
	if((SensorValue[lowerBumper] == 0) || (goalPower > 0))
	{
		motor[goalMotor] = goalPower;
	}
	else
	{
		motor[goalPower] = 0;
	}
}