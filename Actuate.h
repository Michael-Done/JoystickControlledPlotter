void actuate (int sign) //sign should be -1 or +1
//assuming user will not be able to move robot while it actuates
{

    if(nMotorEncoder[DRAW_MOTOR]<DRAW_MOTOR_LIMIT && sign > 0 )//move until it reaches bottom boundary
        motor[DRAW_MOTOR]=ACUTATE_SPEED*sign; 
    
    else if(nMotorEncoder[DRAW_MOTOR] > 0 && sign < 0 )
        motor[DRAW_MOTOR]=ACUTATE_SPEED*sign; 
    
    else if(nMotorEncoder[DRAW_MOTOR]>=DRAW_MOTOR_LIMIT || nMotorEncoder[DRAW_MOTOR]<=0)
        motor[DRAW_MOTOR]=0;

    
    
    
}