#pragma config(Sensor, S1,     X_GYRO,         sensorEV3_Gyro)
#pragma config(Sensor, S2,     Y_GYRO,         sensorEV3_Gyro)
#pragma config(Sensor, S3,     TOUCH_SENSOR,   sensorEV3_Touch)
#pragma config(Sensor, S4,     COLOR_SENSOR,   sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorA,          X_AXIS,        tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          Y_AXIS,        tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          DRAW_MOTOR,    tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorD,          SENS_MOTOR,    tmotorEV3_Medium, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drawing.h" // Shape drawing functions
#include "joystickControl.h"
#include "movement.h" // Movement funcitons
//#include "constants.h" // The constants associated with the robot
#include "systemReset.h"
#include "actuate.h"
#include "inactivityTest.h"

task main(){
	//setBlockBackButton(1);
	// Proper task main layout:
	int oldEncoderY=0;
	int oldEncoderX=0;
	time1[IDLE_TIMER]=0;
	bool exit = false;
	int sensitivity = 50;

	systemReset();
	while(!exit && !inactivityTest(oldEncoderX,oldEncoderY) && !manualShutdown()) {
		//checkButtons();
		joystickControl(sensitivity);
		sensitivity = setSensitivity();
		//checkActuation();


	}
	systemReset();
}
