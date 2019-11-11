#pragma config(Sensor, S1,     X_GYRO,         sensorEV3_Gyro)
#pragma config(Sensor, S2,     Y_GYRO,         sensorEV3_Gyro)
#pragma config(Sensor, S3,     DRAW_BUTTON,    sensorEV3_Touch)
#pragma config(Sensor, S4,     COLOR,          sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorA,          X_AXIS,        tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          Y_AXIS,        tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          DRAW_MOTOR,    tmotorEV3_Medium, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "drawing.c" // Shape drawing functions
#include "movement.c" // Movement funcitons
#include "constants.c" // The constants associated with the robot
// Low-level system reset. This should be accessing sensor and motor data directly
void systemReset();
// test
task main(){
    // A structure that can be passed to functions that contains all the constants for things such as encoder limits
    struct constants CON;
    CON.DRAW_MOTOR_LIMIT = 180;
    CON.X_LIMIT = 360*5;
    CON.Y_LIMIT = 360*5;
    CON.MOVE_TO_TOL = 20;
    CON.SHAPE_SPEED = 50;

    systemReset();
}
