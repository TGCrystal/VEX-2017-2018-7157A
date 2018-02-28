void clearEncoders()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

void encoderDrive(int leftPower, int leftEncoderValue, int rightPower, int rightEncoderValue)
{
	clearEncoders();
	leftEncoderValue = abs(leftEncoderValue);
	rightEncoderValue = abs(rightEncoderValue);
	while((abs(SensorValue[leftEncoder]) < leftEncoderValue) || (abs(SensorValue[rightEncoder]) < rightEncoderValue))
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
}

void sEncoderDrive(int drivePower, int driveEncoderValue)
{
	encoderDrive(drivePower, driveEncoderValue, drivePower, driveEncoderValue);
}

void sEncoDrive(int drivePower, int driveEncoderValue) //new experimental method for driving straight forwards or backwards with built in straightening
{
	clearEncoders();
	clearLCDLine(0);
	clearLCDLine(1);
	
	if(((drivePower > 0) && (driveEncoderValue < 0)) || ((drivePower < 0) && (driveEncoderValue > 0))) //drive power and encoder distance are not the same sign
	{
		displayLCDString(0, 0, " Opposite Signs ");
		displayLCDNumber(1, 0, drivePower);
		displayLCDNumber(1, 4, driveEncoderValue);
	}
	else if(drivePower == 0)
	{
		displayLCDString(0, 0, "  drivePower=0  ");
	}
	else if(drivePower > 0) //moving forward
	{
		for(int i = drivePower/5; i < drivePower; i++)
		{
			drive(drivePower);
			wait1Msec(10);
		}
		while((SensorValue[leftEncoder] < driveEncoderValue) || (SensorValue[rightEncoder] < driveEncoderValue))
		{
			
		}
	}
}