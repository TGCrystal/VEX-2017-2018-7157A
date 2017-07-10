float driveSpeedModifier()
{
	if(vexRT[Btn5D] == 1)
	{
		return .7;
	}
	else
	{
		return 1;
	}
}

void leftDrive(int leftDrivePower)
{
	motor[frontLeft] = driveSpeedModifier() * leftDrivePower;
	motor[backLeft] = driveSpeedModifier() * leftDrivePower;
}

void rightDrive(int rightDrivePower)
{
	motor[frontRight] = driveSpeedModifier() * rightDrivePower;
	motor[backRight] = driveSpeedModifier() * rightDrivePower;
}

void drive(int drivePower)
{
	leftDrive(drivePower);
	rightDrive(drivePower);
}