void menuLCDAndMainControl() //contains both the control for the lcd menu and for the main driver control hub
{
	while(true) //keep running through this forever
	{
		if(!(g_trialRun) || (time1(T3) <= g_timeForDriver)) //if trial run is false or there is enough time left in the time for the driver test
		{
			if(g_menuMode == false) //makes sure the launch and the time left don't show up when the menu is up
			{
				int intTimeLeftForTheTrial = g_timeForDriver - time1(T3); //used to show how much time is left as an integer
				if((g_trialRun) && ((g_timeForDriver - time1(T3)) <= 30000)) //if it is in a trial run and less than 3 seconds are left
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
			userCode();
			if((t >= 100) && (g_menuMode == false)) //if the menu isn't being displayed and it is on an interval of 100 ticks
			{
				if(t >= 500)  //if 500 ticks have been reached
				{
					updateDisplayBattery(); //update the battery levels on the diplay
					t = 0; //reset the tick counter
				}
				if(g_holdTimeLCD >= 4333) //if there are at least 4333 ticks on the counter for activating the menu
				{
					displayLCDString(0, 14, ".."); //display two dots to signify the menu is about to open
				}
				else if(g_holdTimeLCD >= 2167) //if there at least 2167 ticks on the counter for activating the menu
				{
					displayLCDString(0, 14, " ."); //display one dot to indicate the menu is loading
				}
				else //if neither of those tick requirements are met
				{
					displayLCDString(0, 14, "  "); //don't display any dots
				}
			}
			t++; //add one tick to the battery refresh counter
		}
		else //if driver control is not on
		{
			stopAllMotors();
		}

		if(nLCDButtons == 7) //if all 3 LCD buttons are held down
		{
			g_holdTimeLCD++; //add one tick to the counter for activating the LCD menu
		}
		else //if not all 3 of the LCD buttons are held down
		{
			g_holdTimeLCD = 0; //reset the counter for activating the LCD menu
		}

		if((g_holdTimeLCD >= 7500) || (g_menuMode == true)) //if the tick requirement for activating the menu has been met or the menu has been activated otherwise
		{
			if(g_menuMode == false) //if the menu is being initialized for the first time
			{
				clearLCD(); //clear both lines on the LCD panel
				g_menuMode = true; //keep it in the menu
				while(nLCDButtons != 0) { } //don't do anything else until all the buttons have been let go of
			}
			if(g_menuOption < 0) //if the option for the menu is less than 0
			{
				g_menuOption = 5; //set it to the max value (which is 5)
			}
			else if(g_menuOption > 5) //if the option for the menu is above 5
			{
				g_menuOption = 0; //set it to the beginning to loop around
			}

			displayLCDCenteredString(1, "<     Enter    >"); //display the menu controls on the bottom line
			if(g_menuOption == 0) //first option
			{
				displayLCDCenteredString(0, "Free Drive"); //unlimited driving time
			}
			else if(g_menuOption == 1) //second option
			{
				displayLCDCenteredString(0, "1:45 Drive Time"); //1 minute and 45 seconds of driving
			}
			else if(g_menuOption == 2) //third option
			{
				displayLCDCenteredString(0, "1:00 Drive Time"); //1 minute of driving
			}
			else if(g_menuOption == 3) //fourth option
			{
				displayLCDCenteredString(0, "0:15 Auto Time"); //15 second competition autonomous
			}
			else if(g_menuOption == 4) //fifth option
			{
				displayLCDCenteredString(0, "1:00 Auto Time"); //programming skills challenge test
			}
			else if(g_menuOption == 5)
			{
				displayLCDCenteredString(0, "AutonomousSelect");
			}

			if(nLCDButtons == 2) //if the center button on the LCD panel is pressed
			{
				g_selectLCDProgram = true; //activates the selection of the chosen program
			}
			else if((nLCDButtons == 1) && (g_lockMenuChanger == false)) //if the left button on the LCD panel is pressed
			{
				g_menuOption--; //decrease the selected menu option by 1
				g_lockMenuChanger = true; //makes sure the menu options don't fly by
			}
			else if((nLCDButtons == 4) && (g_lockMenuChanger == false)) //if the right button on the LCD panel is pressed
			{
				g_menuOption++; //increase the selected menu option by 1
				g_lockMenuChanger = true; //makes sure the menu options don't fly by
			}
			else if(nLCDButtons == 0) //if none of the lcd buttons are pressed
			{
				g_lockMenuChanger = false; //unlock the menu changer
			}

			if(g_selectLCDProgram == true) //if the selected program will be executed
			{
				countdownLCD(); //activate a 3 second countdown
				g_menuMode = false; //disable the menu
				g_selectLCDProgram = false; //don't change the LCD program if the menu were somehow reopened
				if(g_menuOption == 0) //if unlimited driving has been selected
				{
					g_trialRun = false; //disable it from being a trial run, allowing for infinite drive time
				}
				else if(g_menuOption == 1) //if 1:45 of drivetime has been selected
				{
					g_trialRun = true; //make it a trial run
					g_timeForDriver = 105000; //give 105 seconds to drive
					ClearTimer(T3); //clear the third timer
				}
				else if(g_menuOption == 2) //if 1:00 of drivetime has been selected
				{
					g_trialRun = true; //make it a trial run
					g_timeForDriver = 60000; //give 60 seconds of drivetime
					ClearTimer(T3); //clear the third timer
				}
				else if(g_menuOption == 3) //if the 15 second autonomous has been selected
				{
					g_autonomousTrialRun = true;
					g_autonomousTestTimer = 15000;
					autonomousMain(); //launch the competition autonomous code
				}
				else if(g_menuOption == 4) //if the 1:00 autonomous has been selected
				{
					g_autonomousTrialRun = true;
					g_autonomousTestTimer = 60000;
					autonomousMain(); //launch the programming skill autonomous
				}
				else if(g_menuOption == 5)
				{
					autonomousSwitcher();
				}
				g_selectLCDProgram = false; //disable the variable signifying the selection of a program
				g_menuMode = false; //disable the menu
			}
		}
		else //if the menu isn't up
		{
			g_selectLCDProgram = false; //disable the variable signifying the selection of a program
			g_menuMode = false; //disable the menu
		}
	}
}