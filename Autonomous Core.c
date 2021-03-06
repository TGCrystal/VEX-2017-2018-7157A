long auton_Duration = 0; //how long the autonomous run lasted in milliseconds, global so that it easily shows up in the debugger

void autonomousMain() //launches the correct autonomous routine and records the total amount of time to complete
{
	clearTimer(T2);
	auton_switchLauncher();
	auton_Duration = time1(T2);
}

void LCD_autonomousSwitcher()
{
	bLCDBacklight = true;
	bool autonomousDecision = false;
	const int NUM_OF_ROUTINES = 5;
	LCD_clear();
	while(!(autonomousDecision))
	{
		auton_switchOptions();
		
		displayLCDCenteredString(1, "<     Enter    >");
		if((nLCDButtons == 1)) //if the left button on the LCD panel is pressed
		{
			auton_routine--; //decrease the selected menu option by 1
			while(!(nLCDButtons == 0)) {}
			clearLCDLine(0);
		}
		else if((nLCDButtons == 4)) //if the right button on the LCD panel is pressed
		{
			auton_routine++; //increase the selected menu option by 1
			while(!(nLCDButtons == 0)) {} 
			LCD_clear();
		}
		if(auton_routine < 0)
		{
			auton_routine = NUM_OF_ROUTINES - 1;
		}
		else if(auton_routine >= NUM_OF_ROUTINES)
		{
			auton_routine = 0;
		}
		if(nLCDButtons == 2)
		{
			bool programChosen = false;
			while(!(programChosen))
			{
				displayLCDCenteredString(1, "Y   Correct?   N");
				if(nLCDButtons == 1)
				{
					LCD_clear();
					while(!(nLCDButtons == 0)) {}
					programChosen = true;
					autonomousDecision = true;
				}
				else if(nLCDButtons == 4)
				{
					clearLCDLine(1);
					while(!(nLCDButtons == 0)) {}
					programChosen = true;
				}
			}
		}
	}
}