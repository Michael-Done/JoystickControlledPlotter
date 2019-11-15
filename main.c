#pragma config(Sensor, S1,     XG,         sensorEV3_Gyro)
#pragma config(Sensor, S2,     YG,         sensorEV3_Gyro)
#pragma config(Sensor, S3,     TOUCH,    sensorEV3_Touch)
#pragma config(Sensor, S4,     COLOR,          sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorA,          X,        tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          Y,        tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          DRAW,    tmotorEV3_Medium, PIDControl, encoder) 
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drawing.h" // Shape drawing functions
#include "movement.h" // Movement funcitons
#include "constants.h" // The constants associated with the robot

// Low-level system reset. This should be accessing sensor and motor data directly
void systemReset();

task main(){
    systemReset();
}

void systemReset() {

}
