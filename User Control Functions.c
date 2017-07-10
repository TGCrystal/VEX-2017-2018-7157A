void driveControl()
{
	if(abs(vexRT[Ch3]) > 30)
	{
		leftDrive(vexRT[Ch3]);
	}
	else
	{
		leftDrive(0);
	}
	if(abs(vexRT[Ch2]) > 30)
	{
		rightDrive(vexRT[Ch2]);
	}
	else
	{
		rightDrive(0);
	}
}

void userCode()
{
	driveControl();
}