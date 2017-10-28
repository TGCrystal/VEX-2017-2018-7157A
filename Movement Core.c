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
	motor[driveLeft] = driveSpeedModifier() * leftDrivePower;
}

void rightDrive(int rightDrivePower)
{
	motor[driveRight] = driveSpeedModifier() * rightDrivePower;
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
	motor[armLeft1] = armPower;
	motor[armRight1] = armPower;
	motor[armLeft2] = armPower;
	motor[armRight2] = armPower;
}

void claw(int clawPower)
{
	motor[clawSolo] = clawPower;
}

void clawRotation(int clawRotationPower)
{
	motor[clawRotationSolo] = clawRotationPower;
}