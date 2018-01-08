int auton_routine = 1; //Indicates which autonomous routine will run

void auton_skills() //The autonomous routine for the one minute skills challenge, auton_routine=0
{
	
}

void blueMobileAuton() //get mobile goal on the blue side, auton_routine=1
{
	float mTM = 1; //main Time Multiplier
	float mPM = 1; //main Power Mulitplier
	float bTM = 1; //backup Time Multiplier
	float bPM = 1; //backup Power Multiplier
	
	if(nImmediateBatteryLevel < 7550)
	{
		mTM = 1;
		mPM = 1;
	}
	
	else if(nImmediateBatteryLevel < 8000)
	{
		mTM = .84;
		mPM = .84;
	}
	else if(nImmediateBatteryLevel < 8550)
	{
		mTM = .8;
		mPM = .72;
	}
	else if(nImmediateBatteryLevel < 8650)
	{
		mTM = .8;
		mPM = .65;
	}
	
	
	if(SensorValue[powerExpander] < 2050)
	{
		bTM = 1;
	    bPM = 1;
	}
	else if(SensorValue[powerExpander] < 2350)
	{
		bTM = .9;
	    bPM = .87;
	}
	else if(SensorValue[powerExpander] < 2450)
	{
		bTM = .83;
	    bPM = .83;
	}
	
	arm(60);
	wait1Msec(200);
	arm(0);
	
	drive(70 * mPM);
	wait1Msec(300 * mTM);
	drive(0);
	
	claw(0);
	arm(127 * bPM);
	wait1Msec(1400 * bTM);
	claw(127);
	wait1Msec(1400 * bTM);
	arm(0);
	wait1Msec(500 * bTM);
	claw(0);
	
	lift(-127 * mPM);
	wait1Msec(1000 * mTM);
	lift(0);
	
	arm(-127 * bPM);
	drive(80 * mPM);
	wait1Msec(((mTM + bTM)/2) * 1000);
	drive(0);
	wait1Msec(150 * bTM);
	arm(0);
	wait1Msec(400 * bTM);
	
	claw(127);
	wait1Msec(300);
	arm(127 * bPM);
	wait1Msec(300);
	claw(0);
	wait1Msec(200 * bTM);
	arm(0);
	drive(-127 * mPM);
	wait1Msec(600 * mTM);
	drive(0);
}

void blueMobileDouble() //get two cones on the mobile goal, auton_routine=2
{
	
}