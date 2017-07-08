bool LCD_autonomousTrialRun = false;
long LCD_autonomousTestTimer = 0;
int LCD_refreshCounter = 0; //tick counter for refreshing the battery values on the LCD panel
int LCD_holdTime = 0; //counter used for activating the menu
int LCD_menuOption = 0; //signifies the prgram selected in the menu
long LCD_timeforDriver = 0; //if trial run is true, this is how long in milliseconds it will be
bool LCD_trialRun = false; //used to tell when a time trial for driver control is happening
bool LCD_menuMode = false; //when true, the menu shows up on the LCD panel
bool LCD_lockMenuChanger = false; //prevents the menu options from cycling through really fast
bool LCD_selectProgram = false; //the selected program will activate if true

void LCD_stopAllMotors()
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

void LCD_clear() //function for clearing both lines on the lcd panel
{
	clearLCDLine(0); //clear the top lcd panel line
	clearLCDLine(1); //clear the bottom lcd panel line
}
void LCD_updateBattery() //Displays the value of both batteries
{
	displayLCDString(0, 0, "B: "); //displays B:
	displayLCDNumber(0, 3, nImmediateBatteryLevel); //displays the primary battery
	displayLCDString(0, 7, ", "); //adds a comma and a space between the battery levels
	displayLCDNumber(0, 9, SensorValue[powerExpander]); //displays the launch battery level
	displayLCDString(0, 14, "  "); //clears the lines
}
void LCD_countdown() //used for the countdown after selecting programs on the lcd menu
{
	ClearTimer(T2); //clear the second timer
	LCD_clear(); //clear both lines of the lcd panel
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
	LCD_clear(); //clear both lines of the lcd panel after the countdown has finished
}