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
	int actionTolerance = 40;
	
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
		for(int i = (drivePower/5); i < drivePower; i++)
		{
			drive(i);
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
	}
	else if(drivePower < 0) //moving backward
	{
		for(int i = (drivePower/5); i > drivePower; i--)
		{
			drive(i);
			wait1Msec(10);
			if((SensorValue[leftEncoder] < (driveEncoderValue + actionTolerance)) || (SensorValue[rightEncoder] < (driveEncoderValue + actionTolerance)))
			{
				i = drivePower;
			}
		}
		int leftPower = drivePower;
		int rightPower = drivePower;
		while((SensorValue[leftEncoder] > (driveEncoderValue + actionTolerance)) || (SensorValue[rightEncoder] > (driveEncoderValue + actionTolerance)))
		{
			if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
			{
				leftPower++;
				rightPower--;
			}
			else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
			{
				leftPower--;
				rightPower++;
			}
			
			if(leftPower < drivePower)
			{
				leftPower = drivePower;
			}
			else if(rightPower < drivePower)
			{
				rightPower = drivePower;
			}
			if(leftPower > (drivePower/5))
			{
				leftPower = (drivePower/5);
			}
			else if(rightPower > (drivePower/5))
			{
				rightPower = (drivePower/5);
			}
			
			leftDrive(leftPower);
			rightDrive(rightPower);
		}
		
		for(int i = drivePower; i < (drivePower/5); i++)
		{
			drive(i);
			wait1Msec(10);
			if((SensorValue[leftEncoder] < (driveEncoderValue)) || (SensorValue[rightEncoder] < (driveEncoderValue)))
			{
				i = drivePower/5;
				
			}
		}
	}
	drive(0);
}