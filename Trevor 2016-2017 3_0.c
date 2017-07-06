#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    powerExpander,  sensorAnalog)
#pragma config(Sensor, in2,    clawPosition,   sensorPotentiometer)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl11, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           backRight,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port2,           frontLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port3,           clawLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port4,           armLeft,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           liftLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port6,           liftRight,     tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armRight,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           clawRight,     tmotorVex393, openLoop)
#pragma config(Motor,  port9,           frontRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port10,          backLeft,      tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
//#include "C:\Users\7157R\Desktop\Robot Includes\SongsCore.c"
//#include "C:\Users\7157R\Desktop\Robot Includes\UndertaleSongs.c"

long g_autonomousTestTimer = 0;
bool g_autonomousTrialRun = false;
int g_t = 0; //tick counter for refreshing the battery values on the LCD panel
int g_holdTimeLCD = 0; //counter used for activating the menu
int g_menuOption = 0; //signifies the prgram selected in the menu
long g_timeForDriver = 0; //if trial run is true, this is how long in milliseconds it will be
bool g_trialRun = false; //used to tell when a time trial for driver control is happening
bool g_menuMode = false; //when true, the menu shows up on the LCD panel
bool g_lockMenuChanger = false; //prevents the menu options from cycling through really fast
bool g_selectLCDProgram = false; //the selected program will activate if true
bool g_autonRed = true;
bool g_autonLeft = false;
bool g_autonCube = false;
bool g_autonomousDecision = false;
bool g_driveStraight = false;

void stopAllMotors()
{
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;
	motor[port10] = 0;
}

void clearEncoders()
{
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
}

void clearLCD() //function for clearing both lines on the lcd panel
{
	clearLCDLine(0); //clear the top lcd panel line
	clearLCDLine(1); //clear the bottom lcd panel line
}
void updateDisplayBattery() //Displays the value of both batteries
{
	displayLCDString(0, 0, "B: "); //displays B:
	displayLCDNumber(0, 3, nImmediateBatteryLevel); //displays the primary battery
	displayLCDString(0, 7, ", "); //adds a comma and a space between the battery levels
	displayLCDNumber(0, 9, SensorValue[powerExpander]); //displays the launch battery level
	displayLCDString(0, 14, "  "); //clears the lines
}
void countdownLCD() //used for the countdown after selecting programs on the lcd menu
{
	ClearTimer(T2); //clear the second timer
	clearLCD(); //clear both lines of the lcd panel
	displayLCDCenteredString(0, "Start In:"); //in the center of the first line display Start In:
	int c = 0; //create a variable, c, that is used as a counter to slow down the change rate of the lcd panel
	int timeLeft = 3000; //create an integer to represent the amount of time left, starts at 3 seconds
	while(time1(T2) <= 3000) //while 3 seconds have not yet passed by
	{
		if(c >= 10) //if the counter for the value has reached 10
		{
			timeLeft = 3000 - time1(T2); //update the amount of time left
			displayLCDNumber(1, 0, timeLeft); //on the seond line display the amount of time left in the countdown
			if(timeLeft < 10) //this set of if else statements makes sure that the zeros don't stick around after the number of digits left decreases
			{
				displayLCDString(1, 1, "       ");
			}
			else if(timeLeft < 100)
			{
				displayLCDString(1, 2, "       ");
			}
			else if(timeLeft < 1000)
			{
				displayLCDString(1, 3, "       ");
			}
			c = 0; //reset c to 0
		}
		c++; //add 1 to c

	}
	clearLCD(); //clear both lines of the lcd panel after the countdown has finished
}

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

void sideDrive(int sideDrivePower) //negative is left, positive is right
{
	motor[frontLeft] = driveSpeedModifier() * sideDrivePower;
	motor[backLeft] = -1 * driveSpeedModifier() * sideDrivePower;
	motor[frontRight] = driveSpeedModifier() * sideDrivePower;
	motor[backRight] = -1 * driveSpeedModifier() * sideDrivePower;
}

void drive(int drivePower)
{
	leftDrive(drivePower);
	rightDrive(drivePower);
}

void driveControl()
{
	//if(vexRT[Btn8L] == 1) //commented out because the side drive doesnt work in the current configuration
	//{
	//	sideDrive(-127);
	//}
	//else if(vexRT[Btn8R] == 1)
	//{
	//	sideDrive(127);
	//}
	//else
	//{
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
	//}
}

void arm(int armPower)
{
	motor[armLeft] = armPower;
	motor[armRight] = armPower;
}

void lift(int liftPower)
{
	motor[liftLeft] = liftPower;
	motor[liftRight] = liftPower;
}

void armControl()
{
	if(vexRT[Btn7D] == 0)
	{
		if(vexRT[Btn6U] == 1)
		{
			arm(75);
		}
		else if(vexRT[Btn6D] == 1)
		{
			arm(-75);
		}
		else
		{
			arm(0);
		}
	}
}

void claw(int clawPower)
{
	motor[clawLeft] = clawPower;
	motor[clawRight] = clawPower;
}

void clawControl()
{
	if(vexRT[Btn7D] == 0)
	{
		if(vexRT[Btn5U] == 1)
		{
			claw(-127);
		}
		else if(vexRT[Btn5D] == 1)
		{
			claw(127);
		}
		else
		{
			claw(0);
		}
	}
	else
	{
		if(vexRT[Btn5U] == 1)
		{
			motor[clawRight] = 75;
		}
		else if(vexRT[Btn5D] == 1)
		{
			motor[clawRight] = -75;
		}
		else
		{
			motor[clawRight] = 0;
		}
		if(vexRT[Btn6U] == 1)
		{
			motor[clawLeft] = 75;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[clawLeft] = -75;
		}
		else
		{
			motor[clawLeft] = 0;
		}
	}
}

void liftControl()
{
	if(vexRT[Btn8D] == 1)
	{
		lift(127);
	}
	else if(vexRT[Btn8U] == 1)
	{
		lift(-127);
	}
	else
	{
		lift(0);
	}
}

void userCode()
{
	driveControl();
	armControl();
	clawControl();
	liftControl();
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
		//if(g_driveStraight)
		//{
		//	if(leftEncoderValue > 0)
		//	{
		//		if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
		//		{
		//			leftPower++;
		//			rightPower--;
		//		}
		//		else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
		//		{
		//			leftPower--;
		//			rightPower++;
		//		}
		//	}
		//	else
		//	{
		//		if(SensorValue[leftEncoder] < SensorValue[rightEncoder])
		//		{
		//			leftPower--;
		//			rightPower++;
		//		}
		//		else if(SensorValue[leftEncoder] > SensorValue[rightEncoder])
		//		{
		//			leftPower++;
		//			rightPower--;
		//		}
		//	}
		//	if(rightPower > 127)
		//	{
		//		rightPower = 127;
		//	}
		//	else if(rightPower < -127)
		//	{
		//		rightPower = -127;
		//	}
		//	if(leftPower > 127)
		//	{
		//		leftPower = 127;
		//	}
		//	else if(leftPower < -127)
		//	{
		//		leftPower = -127;
		//	}
		// }
	}
	g_driveStraight = false;
	rightDrive(0);
	leftDrive(0);
}

void toClawPosition(int desiredClawPosition, int numOfPasses)
{
	if(numOfPasses > 11)
	{
		numOfPasses = 11;
	}
	for(int i = 0; i < numOfPasses; i++)
	{
		if(SensorValue[clawPosition] > desiredClawPosition)
		{
			while(SensorValue[clawPosition] > desiredClawPosition)
			{
				claw(127 - i*10);
			}
			claw(0);
		}
		else
		{
			while(SensorValue[clawPosition] < desiredClawPosition)
			{
				claw(-127 + i*10);
			}
			claw(0);
		}
		claw(0);
		wait1Msec(300);
	}
}

void sEncoderDrive(int drivePower, int driveEncoderValue)
{
	g_driveStraight = true;
	encoderDrive(drivePower, driveEncoderValue, drivePower, driveEncoderValue);
}

void leftRed()
{
	arm(80);
	wait1Msec(740);
	arm(0);
	toClawPosition(2200, 3);
	sEncoderDrive(100, 1400);
	arm(70);
	wait1Msec(100);
	arm(0);
	wait1Msec(500);
	toClawPosition(500, 3);
	toClawPosition(3000, 3);
	sEncoderDrive(-127, 300);
}

void rightRed()
{
	leftRed();
}

void leftBlue()
{
	leftRed();
}

void rightBlue()
{
	rightRed();
}

void autonomousMain()
{
	ClearTimer(T4);
	int dispTime = 0;
	long timeLeftForTrial = g_autonomousTestTimer - time1(T4); //used to show how much time is left as an integer
	while(!(g_autonomousTrialRun) || (g_autonomousTestTimer >= time1(T4)))
	{
		timeLeftForTrial = g_autonomousTestTimer - time1(T4);
		if((g_autonomousTrialRun) && ((g_autonomousTestTimer - time1(T4)) <= 30000)) //if it is in a trial run and less than 30 seconds are left
		{
			timeLeftForTrial = g_autonomousTestTimer - time1(T4);
			dispTime = timeLeftForTrial;
			displayLCDNumber(1, 0, dispTime); //show how much time is left in the trial run
			if(timeLeftForTrial < 10) //used to clear out 0's as the time left goes down
			{
				displayLCDString(1, 1, "    ");
			}
			else if(timeLeftForTrial < 100)
			{
				displayLCDString(1, 2, "   ");
			}
			else if(timeLeftForTrial < 1000)
			{
				displayLCDString(1, 3, "  ");
			}
			else if(timeLeftForTrial < 10000)
			{
				displayLCDString(1, 4, " ");
			}
		}
		if(!g_autonCube)
		{
			if(g_autonLeft && g_autonRed)
			{
				g_autonomousTrialRun = true;
				g_autonomousTestTimer = -1;
				leftRed();
			}
			else if(!(g_autonLeft) && g_autonRed)
			{
				g_autonomousTrialRun = true;
				g_autonomousTestTimer = -1;
				rightRed();
			}
			else if(g_autonLeft && !(g_autonRed))
			{
				g_autonomousTrialRun = true;
				g_autonomousTestTimer = -1;
				leftBlue();
			}
			else
			{
				g_autonomousTrialRun = true;
				g_autonomousTestTimer = -1;
				rightBlue();
			}
		}
	}
}

void autonomousSwitcher()
{
	bLCDBacklight = true;
	g_autonomousDecision = false;
	g_lockMenuChanger = false;
	g_selectLCDProgram = false;
	g_menuOption = 0;
	clearLCD();
	while(!(g_autonomousDecision))
	{
		if(g_menuOption == 0) //RED LEFT
		{
			g_autonLeft = true;
			g_autonRed = true;
		}
		if(g_menuOption == 1) //RED RIGHT
		{
			g_autonLeft = false;
			g_autonRed = true;
		}
		if(g_menuOption == 2) //BLUE LEFT
		{
			g_autonLeft = true;
			g_autonRed = false;
		}
		if(g_menuOption == 3) //BLUE RIGHT
		{
			g_autonLeft = false;
			g_autonRed = false;
		}
		if(g_autonRed)
		{
			displayLCDString(0, 0, " RED");
		}
		else
		{
			displayLCDString(0, 0, "BLUE");
		}
		if(g_autonLeft)
		{
			displayLCDString(0, 5, "LEFT ");
		}
		else
		{
			displayLCDString(0, 5, "RIGHT");
		}
		displayLCDCenteredString(1, "<     Enter    >");
		//if(!(g_lockMenuChanger))
		//{

		if((nLCDButtons == 1)) //if the left button on the LCD panel is pressed
		{
			g_menuOption--; //decrease the selected menu option by 1
			g_lockMenuChanger = true; //makes sure the menu options don't fly by
			while(!(nLCDButtons == 0)) {}
			clearLCD();
		}
		else if((nLCDButtons == 4)) //if the right button on the LCD panel is pressed
		{
			g_menuOption++; //increase the selected menu option by 1
			g_lockMenuChanger = true; //makes sure the menu options don't fly by
			while(!(nLCDButtons == 0)) {}
			clearLCD();
		}
		//}
		if(g_menuOption < 0)
		{
			g_menuOption = 3;
		}
		else if(g_menuOption > 3)
		{
			g_menuOption = 0;
		}
		if(nLCDButtons == 2)
		{
			bool programChosen = false;
			clearLCD();
			while(!(programChosen))
			{
				displayLCDCenteredString(0, "Are you sure?");
				if(g_autonRed)
				{
					displayLCDString(1, 3, " RED");
				}
				else
				{
					displayLCDString(1, 3, "BLUE");
				}
				if(g_autonLeft)
				{
					displayLCDString(1, 8, "LEFT ");
				}
				else
				{
					displayLCDString(1, 8, "RIGHT");
				}
				displayLCDString(1, 0, "Y");
				displayLCDString(1, 15, "N");
				if(nLCDButtons == 1)
				{
					clearLCD();
					while(!(nLCDButtons == 0)) {}
					programChosen = true;
					g_autonomousDecision = true;
				}
				else if(nLCDButtons == 4)
				{
					clearLCD();
					while(!(nLCDButtons == 0)) {}
					programChosen = true;
				}
			}
		}
	}
	bLCDBacklight = false;
}

#include "C:\Users\7157R\Documents\GitHub\VEX-2017-2018-7157A\VEX LCD Menu Core.c"

void pre_auton()
{
	//autonomousSwitcher();
	bStopTasksBetweenModes = true;
}


task autonomous()
{
	g_autonomousTrialRun = false;
	autonomousMain();
}


task usercontrol()
{
	// User control code here, inside the loop
	g_t = 0; //reset the battery refresh counter
	g_lockMenuChanger = false; //reset this
	g_selectLCDProgram = false; //reset that
	g_menuMode = false; //make sure the menu doesn't pop up
	bLCDBacklight = true; //turn on the LCD backlight
	g_trialRun = false; //do not run a trial run
	clearLCD(); //clear both lines on the LCD panel
	g_holdTimeLCD = 0; //reset the counter for activating the lcd menu

	menuLCDAndMainControl(); //launch the function for the main user and LCD control
}
