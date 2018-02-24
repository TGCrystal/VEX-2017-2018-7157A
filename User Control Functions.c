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

void liftControl()
{
	if(vexRT[Btn8U] == 1)
	{
		lift(-127);
	}
	else if(vexRT[Btn8D] == 1)
	{
		lift(127);
	}
	else
	{
		lift(0);
	}
}


void armControl()
{
	if(vexRT[Btn6D] == 1)
	{
		arm(-127);
	}
	else if(vexRT[Btn6U] == 1)
	{
		arm(127);
	}
	else if (vexRT[Btn8R] == 1)
	{
		arm(3540-SensorValue[armPot]);
	}
	else if (vexRT[Btn8U] == 1)
	{
		arm(1333-SensorValue[armPot]);
	}
	else if (vexRT[Btn8L] == 1)
	{
		arm((2440-SensorValue[armPot])/2);
	}
	else
	{
		arm(0);
	}
}

void clawControl()
{
	if(vexRT[Btn5D] == 1)
	{
		claw(-127); 
	}
	else if(vexRT[Btn5U] == 1)
	{
		claw(127);
	}
	else
	{
		claw(0);
	}
}

void pControl()
{
	if(vexRT[Btn7U] == 1)
	{
		pExtend();
	}
	else if(vexRT[Btn7D] == 1)
	{
		pRetract();
	}
}

void goalControl()
{
	if(vexRT[Btn7U] == 1)
	{
		goal(127);
	}
	else if(vexRT[Btn7D] == 1)
	{
		goal(-127);
	}
	else
	{
		motor[goalMotor] = 0;
	}
}

void userCode()
{
	driveControl();
	liftControl();
	armControl();
	clawControl();
	// pControl();
	goalControl();
}