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