#include "constants.h"
#include "joystickControl.h"

bool actuate (int sign, bool control) { //sign should be -1 or +1
	int priorButtonState = 0; //buttonState = 0 as this function is called only when button has been released
	while ((nMotorEncoder[DRAW_MOTOR]<DRAW_MOTOR_LIMIT && sign > 0) || (nMotorEncoder[DRAW_MOTOR]>10 && sign < 0))//move based on actuation stage
	{
		motor[DRAW_MOTOR]=ACTUATE_SPEED*sign;

		if (control)
		{
			//   joystickControl();

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


void checkActuate (bool & headStateUp, int & priorButtonState) {
	if(SensorValue[TOUCH_SENSOR] != 1 && priorButtonState==1) {
		if(headStateUp)
			headStateUp=actuate(1,true); //make actuate back into bool, headstate=actuate(1,101)
		else
			headStateUp = actuate(1,false);

	}
	priorButtonState=SensorValue[TOUCH_SENSOR];
	wait1Msec(10);
}
