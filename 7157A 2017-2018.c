#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    powerExpander,  sensorAnalog)
#pragma config(Sensor, in2,    armPot,         sensorPotentiometer)
#pragma config(Sensor, dgtl5,  upperBumper1,   sensorTouch)
#pragma config(Sensor, dgtl6,  upperBumper2,   sensorTouch)
#pragma config(Sensor, dgtl7,  lowerBumper,    sensorTouch)
#pragma config(Sensor, dgtl8,  rightCylinder,  sensorDigitalOut)
#pragma config(Sensor, dgtl9,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl11, rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port1,           driveLeftTop,  tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           driveRightBottom, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           liftLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           goalGrabber,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           clawMotor,     tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,           goalMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           liftRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           driveLeftBottom, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          driveRightTop, tmotorVex393_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//Overall Information
/* Controls (All are located in User Control Functions unless noted otherwise)
* Channel 1 (Ch1) - Unused
* Channel 2 (Ch2) - Controls the left side of the drive
* Channel 3 (Ch3) - Controls the right side of the drive
* Channel 4 (Ch4) - Unused
* Button 5D (Btn5D) - Closes claw
* Button 5U (Btn5U) - Opens claw
* Button 6D (Btn6D) - Moves arm to front
* Button 6U (Btn6U) - Moves arm to back
* Button 7D (Btn7D) - Unused
* Button 7L (Btn7L) - Unused
* Button 7R (Btn7R) - Unused
* Button 7U (Btn7U) - Unused
* Button 8D (Btn8D) - Lower the lift
* Button 8L (Btn8L) - Unused
* Button 8R (Btn8R) - Unused
* Button 8U (Btn8U) - Raise the lift
*/
/* Partner Controls
* Channel 1 (Ch1) - Unused
* Channel 2 (Ch2) - Unused
* Channel 3 (Ch3) - Unused
* Channel 4 (Ch4) - Unused
* Button 5D (Btn5D) - Unused
* Button 5U (Btn5U) - Unused
* Button 6D (Btn6D) - Unused
* Button 6U (Btn6U) - Unused
* Button 7D (Btn7D) - Unused
* Button 7L (Btn7L) - Unused
* Button 7R (Btn7R) - Unused
* Button 7U (Btn7U) - Unused
* Button 8D (Btn8D) - Unused
* Button 8L (Btn8L) - Unused
* Button 8R (Btn8R) - Unused
* Button 8U (Btn8U) - Unused
*/
/* Timers
* T1 - unused
* T2 - used for countdown in LCD_countdown(), as a timer in autonomousMain(), and for trial driver run duration in menuLCDAndMainCore(), don't reuse
* T3 - unused
* T4 - unused
*/

#include "Music Core.c" //just a fun program for playing music on the VEX Speaker Module
#include "Genesis Music.c" //plays some Genesis music through the speakers
#include "Dixieland Clarinet Music.c" //plays the Clarinet Dixieland Music that I have

#include "LCD Functions And Variables.c" //required variables and functions for the LCD Menu Core to function
/* Global Variables
* LCD_finalCountdown - indicates if the LCD countdown will run after selecting a program
* LCD_menuOption - which selected program will be run by the LCD menu
*/
/* Timers
* T2 - used in the countdown
*/
/* Methods
* LCD_stopAllMotors() - stops every motor in every port regardless of name
* LCD_clear() - clears both lines of the LCD panel with only one line instead of two
* LCD_updateBattery() - refreshes the values of the batteries displayed on the LCD panel
* LCD_countdown() - runs a countdown of three seconds on the LCD panel
*/

#include "Movement Core.c" //functions that control movement, used by user control and autonomous code
/* Methods
* driveSpeedModifier() - if Button 7U is held then the powr of the drive is multiplied by .7
* leftDrive(int leftDrivePower) - sets the power of both left motors to leftDrivePower
* rightDrive(int rightDrivePower) - sets the power of both right motors to rightDrivePower
* drive(int drivePower) - sets the power of all four drive motors to drivePower
* lift(int liftPower) - move the lift motors at liftPower
* arm(int armPower) - move the arm at armPower
* claw(int clawPower) - open/close the claw at clawPower
*/

#include "Encoder Functions.c" //functions used by autonomous for using encoders
/* Methods
* clearEncoders() - clears encoders, needs to be configured for whatever encoders are attached, currently has leftEncoder and rightEncoder for left and right drives
* encoderDrive(int leftPower, int leftEncoderValue, int rightPower, int rightEncoderValue) - moves sides of the drive at given powers until they reach the given distances
* sEncoderDrive(int drivePower, int driveEncoderValue) - similar to encoderDrive but has both sides moving the same amount
*/

#include "User Control Functions.c" //code that applies during the user control period
/* Methods
* driveControl() - uses the joysticks to control each side of the drive with tank style controls
* liftControl() - raises the lift up and down
* armcontrol() - flips the arm over
* clawControl() - opens and closes the claw
* userCode()- calls all of the methods in the file
*/

#include "Autonomous Routines.c" //the various functions to be ran for autonomous
/* Global Variables
* auton_routine - Indicates which autonomous routine will run
*/
/* Methods
* auton_skills() - the autonomous routine for the one minute skills challenge
*/

#include "Autonomous Core.c" //contains code for launching the correct autnomous routine
/* Global Variables
* long auton_Duration - how long the autonomous run lasted in milliseconds, global so that it easily shows up in the debugger
*/
/* Timers
* T2 - keeps track fo the autonomous duration
*/
/* Methods
* autonomousMain() - launches the correct program for use for the autonomous routine
*/

#include "LCD Menu Core.c" //the central LCD menu that then loads the user code and also the switcher of the autonomous routines
/* Timers
* T2 - used for timing trial driver runs
*/
/* Methods
* LCD_autonomousSwitcher() - used to change the autonomous program to use
* menuLCDAndMainControl() - the core code for the LCD menu
*/


void pre_auton() //runs when the robot is first turned on
{
	if(nLCDButtons == 7) //the autonomous selector will only activate if all LCD buttons are pressed on launch
	{
		LCD_autonomousSwitcher();
	}
	claw(127);
	clearEncoders(); //resets the encoders
	bLCDBacklight = false;
	bStopTasksBetweenModes = true; //honestly not quite sure what this does but I've had issues when setting it to false before
}


task autonomous() //runs when autonomous is started from a competion switch
{
	autonomousMain(); //call the core of the autonomous code
}

task usercontrol() //runs when driver is selected from the competition switch or when the robot is turned on without a competition switch
{
	bLCDBacklight = true; //turn on the LCD backlight
	LCD_clear(); //clear both lines on the LCD panel



	menuLCDAndMainControl(); //launch the function for the main user and LCD control
}
