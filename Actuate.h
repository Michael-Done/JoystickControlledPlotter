#include "constants.h"
#include "joystickControl.h"


bool actuate (int sign, bool control) //sign should be -1 or +1
{
    int priorButtonState = SensorValue[TOUCH_SENSOR]; //buttonState = 0 as this function is called only when button has been released
  
    while ((nMotorEncoder[DRAW_MOTOR]<DRAW_MOTOR_LIMIT && sign > 0) || (nMotorEncoder[DRAW_MOTOR]>0 && sign < 0))//move based on actuation stage
    {  

    motor[DRAW_MOTOR]=ACTUATE_SPEED*sign;

    if (control)
    {
       joystickControl()

        if (SensorValue[TOUCH_SENSOR]!=1 && priorButtonState==1)
            sign=-sign;
       
    }
    
    priorButtonState=SensorValue[TOUCH_SENSOR];
    
    }

    
    motor[DRAW_MOTOR]=0;
    return true;
    
}