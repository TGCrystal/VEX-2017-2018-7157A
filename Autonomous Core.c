void autonomousMain()
{
	ClearTimer(T4);
	int dispTime = 0;
	long timeLeftForTrial = LCD_autonomousTestTimer - time1(T4); //used to show how much time is left as an integer
	while(!(g_autonomousTrialRun) || (LCD_autonomousTestTimer >= time1(T4)))
	{
		timeLeftForTrial = LCD_autonomousTestTimer - time1(T4);
		if((g_autonomousTrialRun) && ((LCD_autonomousTestTimer - time1(T4)) <= 30000)) //if it is in a trial run and less than 30 seconds are left
		{
			timeLeftForTrial = LCD_autonomousTestTimer - time1(T4);
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
	}
}

void LCD_autonomousSwitcher()
{
	bLCDBacklight = true;
	g_autonomousDecision = false;
	LCD_lockMenuChanger = false;
	LCD_selectProgram = false;
	LCD_menuOption = 0;
	LCD_clear();
	while(!(g_autonomousDecision))
	{
		if(LCD_menuOption == 0)
		{
			
		}
		if(LCD_menuOption == 1)
		{
			
		}
		if(LCD_menuOption == 2)
		{
			
		}
		if(LCD_menuOption == 3)
		{
			
		}
		if(g_autonRed)
		{
			
		}
		else
		{
			
		}
		if(g_autonLeft)
		{
			
		}
		else
		{
			
		}
		displayLCDCenteredString(1, "<     Enter    >");
		if((nLCDButtons == 1)) //if the left button on the LCD panel is pressed
		{
			LCD_menuOption--; //decrease the selected menu option by 1
			LCD_lockMenuChanger = true; //makes sure the menu options don't fly by
			while(!(nLCDButtons == 0)) {}
			LCD_clear();
		}
		else if((nLCDButtons == 4)) //if the right button on the LCD panel is pressed
		{
			LCD_menuOption++; //increase the selected menu option by 1
			LCD_lockMenuChanger = true; //makes sure the menu options don't fly by
			while(!(nLCDButtons == 0)) {}
			LCD_clear();
		}
		if(LCD_menuOption < 0)
		{
			LCD_menuOption = 3;
		}
		else if(LCD_menuOption > 3)
		{
			LCD_menuOption = 0;
		}
		if(nLCDButtons == 2)
		{
			bool programChosen = false;
			LCD_clear();
			while(!(programChosen))
			{
				displayLCDCenteredString(0, "Are you sure?");
				displayLCDString(1, 0, "Y");
				displayLCDString(1, 15, "N");
				if(nLCDButtons == 1)
				{
					LCD_clear();
					while(!(nLCDButtons == 0)) {}
					programChosen = true;
					g_autonomousDecision = true;
				}
				else if(nLCDButtons == 4)
				{
					LCD_clear();
					while(!(nLCDButtons == 0)) {}
					programChosen = true;
				}
			}
		}
	}
	bLCDBacklight = false;
}