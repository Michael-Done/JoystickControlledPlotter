#include "constants.h"
#include "joystickControl.h"

/*  bool actuate: Moves the plotter head up and down.
Parameters:
int sign                  : determines the direction of actuation. (Down when sign = 1. Up when sign = -1.)
int control               : determines if user can move the robot while the plotter is actuating
*/

bool actuate (int sign, bool control) { //sign should be -1 or +1
	int priorButtonState = 0; //buttonState = 0 as this function is called only when button has been released
	while ((nMotorEncoder[DRAW_MOTOR]<DRAW_MOTOR_LIMIT && sign > 0) || (nMotorEncoder[DRAW_MOTOR]>10 && sign < 0))//move based on actuation stage
	{
		motor[DRAW_MOTOR]=ACTUATE_SPEED*sign;

		if (control)
		{
			joystickControl(setSensitivity());

			if (SensorValue[TOUCH_SENSOR]!=1 && priorButtonState==1)
				sign=-sign;

			priorButtonState=SensorValue[TOUCH_SENSOR];
			wait1Msec(10);
		}
	}

	if ((nMotorEncoder[DRAW_MOTOR]>=DRAW_MOTOR_LIMIT)){
		motor[DRAW_MOTOR]=5; //holding power
		return true; //means it's acuated to bottom
	}
	else
	{
		motor[DRAW_MOTOR]=0;
		return false; //means it's actuated to top
	}
}

/*  bool checkActuate: Checks if the user has pressed and released the touch sensor to initiate actuation.
Parameters:
bool headStateUp                  : indicates whether drawing head is actuated up or down
int  priorButtonState             : Value used track when the touch sensor has been pushed and released.
*/

void checkActuate (bool & headState, int & priorButtonState) {
	if(SensorValue[TOUCH_SENSOR] != 1 && priorButtonState==1) { //check that the touch sensor is not pushed, but was pushed an instance ago
		if(headState)
			headState = actuate(-1,true);
		else
			headState = actuate(1,true);

	}
	priorButtonState=SensorValue[TOUCH_SENSOR];
	wait1Msec(10);
}
