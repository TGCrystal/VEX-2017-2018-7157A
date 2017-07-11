void autonomousMain()
{
	ClearTimer(T4);
	int dispTime = 0;
	long timeLeftForTrial = LCD_autonomousTestTimer - time1(T4); //used to show how much time is left as an integer
	while(!(LCD_autonomousTrialRun) || (LCD_autonomousTestTimer >= time1(T4)))
	{
		timeLeftForTrial = LCD_autonomousTestTimer - time1(T4);
		if((LCD_autonomousTrialRun) && ((LCD_autonomousTestTimer - time1(T4)) <= 30000)) //if it is in a trial run and less than 30 seconds are left
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
		//code goes here
	}
}