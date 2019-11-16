#include "constants.h"

#include "joystickControl.h"
void actuate (int sign, bool control) { //sign should be -1 or +1
    int priorButtonState = SensorValue[TOUCH_SENSOR]; //buttonState = 0 as this function is called only when button has been released
    while ((nMotorEncoder[DRAW_MOTOR]<DRAW_MOTOR_LIMIT && sign > 0) || (nMotorEncoder[DRAW_MOTOR]>10 && sign < 0)){//move based on actuation stage
        motor[DRAW_MOTOR]=ACTUATE_SPEED*sign;
        if (control){
        //   joystickControl();
            if (SensorValue[TOUCH_SENSOR]!=1 && priorButtonState==1)
                sign=-sign;
        }

        priorButtonState=SensorValue[TOUCH_SENSOR];
        wait1Msec(10);
    }
    motor[DRAW_MOTOR]=0;
}

void checkActuate (bool & headStateUp, int & priorButtonState) {
	if(SensorValue[TOUCH_SENSOR] != 1 && priorButtonState==1) {
		if(headStateUp){
			actuate(1, 1);
			headStateUp=false;
		}
		else {
			actuate(-1, 1);
			headStateUp = true;
		}
	}
	priorButtonState=SensorValue[TOUCH_SENSOR];
	wait1Msec(10);
}
