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
	motor[driveLeftFront] = driveSpeedModifier() * leftDrivePower;
	motor[driveLeftRear] = driveSpeedModifier() * leftDrivePower;
}

void rightDrive(int rightDrivePower)
{
	motor[driveRightFront] = driveSpeedModifier() * rightDrivePower;
	motor[driveRightRear] = driveSpeedModifier() * rightDrivePower;
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
	motor[armLeft] = armPower;
	motor[armRight] = armPower;
}

void claw(int clawPower)
{
	motor[clawMotor] = clawPower;
}