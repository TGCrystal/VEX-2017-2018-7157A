void LCD_displayMenuOptions() //refreshes the option shon on screen
{
	if(LCD_menuOption < 0) //if the option for the menu is less than 0
	{
		LCD_menuOption = 5; //set it to the max value (which is 5)
	}
	else if(LCD_menuOption > 5) //if the option for the menu is above 5
	{
		LCD_menuOption = 0; //set it to the beginning to loop around
	}
	
	switch(LCD_menuOption) { //switch statement to chose which program to launch based on the value of LCD_menuOption
		case 0:
			LCD_finalCountdown = false;
			displayLCDCenteredString(0, "   Free Drive   "); //unlimited driving time
			break;
		case 1:
			LCD_finalCountdown = true;
			displayLCDCenteredString(0, "1:45 Drive Time "); //1 minute and 45 seconds of driving
			break;
		case 2:
			LCD_finalCountdown = true;
			displayLCDCenteredString(0, "1:00 Drive Time "); //1 minute of driving
			break;
		case 3:
			LCD_finalCountdown = true;
			displayLCDCenteredString(0, " 0:15 Auto Time "); //15 second competition autonomous
			break;
		case 4:
			LCD_finalCountdown = true;
			displayLCDCenteredString(0, " 1:00 Auto Time "); //programming skills challenge test
			break;
		case 5:
			LCD_finalCountdown = false;
			displayLCDCenteredString(0, "AutonomousSelect"); //selection screen for which autonomous routine to use
			break;
		default: //if somehow none of the available options were selected
			displayLCDCenteredString(0, "OutOfBoundsError");
	}
}

void menuLCDAndMainControl() //the controller for the lcd menu
{
	bool LCD_finalCountdown = true; //decides whether or not the countdown will be used after selecting a program
	int LCD_refreshCounter = 0; //tick counter for refreshing the battery values on the LCD panel
	int LCD_holdTime = 0; //counter used for activating the menu
	bool LCD_selectProgram = false; //the selected program will activate if true
	int LCD_menuOption = 0; //signifies the prgram selected in the menu
	bool LCD_menuMode = false; //when true, the menu shows up on the LCD panel
	bool LCD_lockMenuChanger = false; //prevents the menu options from cycling through really fast
	long LCD_timeforDriver = 0; //if trial run is true, this is how long in milliseconds it will be
	bool LCD_trialRun = false; //used to tell when a time trial for driver control is happening
	while(true) //keep running through this forever
	{
		if(!(LCD_trialRun) || (time1(T2) <= LCD_timeforDriver)) //if trial run is false or there is enough time left in the time for the driver test
		{
			if(LCD_menuMode == false) //makes sure the launch and the time left don't show up when the menu is up
			{
				int intTimeLeftForTheTrial = LCD_timeforDriver - time1(T2); //used to show how much time is left as an integer
				if((LCD_trialRun) && ((LCD_timeforDriver - time1(T2)) <= 30000)) //if it is in a trial run and less than 3 seconds are left
				{
					displayLCDNumber(1, 0, intTimeLeftForTheTrial); //show how much time is left in the trial run
					if(intTimeLeftForTheTrial < 10) //used to clear out 0's as the time left goes down
					{
						displayLCDString(1, 1, "    ");
					}
					else if(intTimeLeftForTheTrial < 100)
					{
						displayLCDString(1, 2, "   ");
					}
					else if(intTimeLeftForTheTrial < 1000)
					{
						displayLCDString(1, 3, "  ");
					}
					else if(intTimeLeftForTheTrial < 10000)
					{
						displayLCDString(1, 4, " ");
					}
				}
			}
			userCode(); //the only outgoing call to the driver control from here, function is in the file User Control Functions.c
			if((LCD_refreshCounter >= 100) && (LCD_menuMode == false)) //if the menu isn't being displayed and it is on an interval of 100 ticks
			{
				if(LCD_refreshCounter >= 500)  //if 500 ticks have been reached
				{
					LCD_updateBattery(); //update the battery levels on the diplay
					LCD_refreshCounter = 0; //reset the tick counter
				}
				if(LCD_holdTime >= 4333) //if there are at least 4333 ticks on the counter for activating the menu
				{
					displayLCDString(0, 14, ".."); //display two dots to signify the menu is about to open
				}
				else if(LCD_holdTime >= 2167) //if there at least 2167 ticks on the counter for activating the menu
				{
					displayLCDString(0, 14, " ."); //display one dot to indicate the menu is loading
				}
				else //if neither of those tick requirements are met
				{
					displayLCDString(0, 14, "  "); //don't display any dots
				}
			}
			LCD_refreshCounter++; //add one tick to the battery refresh counter
		}
		else //if driver control is not on
		{
			LCD_stopAllMotors();
		}

		if(nLCDButtons == 7) //if all 3 LCD buttons are held down
		{
			LCD_holdTime++; //add one tick to the counter for activating the LCD menu
		}
		else //if not all 3 of the LCD buttons are held down
		{
			LCD_holdTime = 0; //reset the counter for activating the LCD menu
		}

		if((LCD_holdTime >= 7500) || (LCD_menuMode == true)) //if the tick requirement for activating the menu has been met or the menu has been activated otherwise
		{
			if(LCD_menuMode == false) //if the menu is being initialized for the first time
			{
				LCD_clear(); //clear both lines on the LCD panel
				LCD_menuMode = true; //keep it in the menu
				while(nLCDButtons != 0) { } //don't do anything else until all the buttons have been let go of
				displayLCDCenteredString(1, "<     Enter    >"); //display the menu controls on the bottom line
				LCD_displayMenuOptions(); //refresh current choice
			}

			if(nLCDButtons == 2) //if the center button on the LCD panel is pressed
			{
				LCD_selectProgram = true; //activates the selection of the chosen program
			}
			else if((nLCDButtons == 1) && (LCD_lockMenuChanger == false)) //if the left button on the LCD panel is pressed
			{
				LCD_menuOption--; //decrease the selected menu option by 1
				LCD_lockMenuChanger = true; //makes sure the menu options don't fly by
				LCD_displayMenuOptions(); //refresh current choice
			}
			else if((nLCDButtons == 4) && (LCD_lockMenuChanger == false)) //if the right button on the LCD panel is pressed
			{
				LCD_menuOption++; //increase the selected menu option by 1
				LCD_lockMenuChanger = true; //makes sure the menu options don't fly by
				LCD_displayMenuOptions(); //refresh current choice
			}
			else if(nLCDButtons == 0) //if none of the lcd buttons are pressed
			{
				LCD_lockMenuChanger = false; //unlock the menu changer
			}

			if(LCD_selectProgram == true) //if the selected program will be executed
			{
				if(LCD_finalCountdown) //activate a 3 second countdown only for certain programs
				{
					LCD_countdown();
				}
				
				switch(LCD_menuOption) { //switch statement to chose which program to launch based on the value of LCD_menuOption
					case 0: //if unlimited driving has been selected
						LCD_trialRun = false; //disable it from being a trial run, allowing for infinite drive time
						break;
					case 1: //if 1:45 of drivetime has been selected
						LCD_trialRun = true; //make it a trial run
						LCD_timeforDriver = 105000; //give 105 seconds to drive
						ClearTimer(T2);
						break;
					case 2: //if 1:00 of drivetime has been selected
						LCD_trialRun = true; //make it a trial run
						LCD_timeforDriver = 60000; //give 60 seconds of drivetime
						ClearTimer(T2);
						break;
					case 3: //if the 15 second autonomous has been selected
						autonomousMain(); //launch the competition autonomous code
						break;
					case 4: //if the 1:00 autonomous has been selected
						auton_routine = 0; //set the desired autonomous routine to the skill autonomous
						autonomousMain(); //launch the programming skill autonomous
						break;
					case 5: //if the autonomous switcher has been selected
						LCD_autonomousSwitcher();
						break;
					default: //if somehow none of the available options were selected
						LCD_trialRun = false; //then default to an unlimited driver run
				}
				
				LCD_selectProgram = false; //disable the variable signifying the selection of a program
				LCD_menuMode = false; //disable the menu
			}
		}
	}
}
