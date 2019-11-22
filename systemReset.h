/*  void systemReset : performs a reset of the actuator position and the gyros
    Parameters:
        None
*/
void systemReset()
{
    motor[X_AXIS] = 0;
    motor[Y_AXIS] = 0;
    motor[DRAW_MOTOR] = 0;

    time1[T3] = 0;
    while(time1[T3] < 2000)
    motor[DRAW_MOTOR] = -20;
    motor[DRAW_MOTOR] = 0;
		nMotorEncoder[DRAW_MOTOR] = 0;

    nMotorEncoder[X_AXIS] = 0;
    motor[X_AXIS] = 50;
    while(SensorValue[COLOR_SENSOR] != (int)colorRed && (SensorValue[COLOR_SENSOR] != (int)colorBlack && SensorValue[COLOR_SENSOR]!=0) && nMotorEncoder[X_AXIS] < X_LIMIT)
    {
    	wait1Msec(50);
    }
    wait1Msec(50);
    motor[X_AXIS] = 0;
    wait1Msec(500);

    nMotorEncoder[Y_AXIS] = 0;
    motor[Y_AXIS] = -50;
    while((SensorValue[COLOR_SENSOR] != (int)colorBlack && SensorValue[COLOR_SENSOR]!=0) && nMotorEncoder[Y_AXIS] < Y_LIMIT)
    {wait1Msec(50);}
    motor[Y_AXIS] = 0;
    wait1Msec(500);

    nMotorEncoder[X_AXIS] = 0;
    motor[X_AXIS] = -50;
    while(nMotorEncoder[X_AXIS] > -X_LIMIT)
    {wait1Msec(50);}
    motor[X_AXIS] = 0;

    nMotorEncoder[X_AXIS] = 0;
    nMotorEncoder[Y_AXIS] = 0;
    nMotorEncoder[SENS_MOTOR] = 0;

    resetGyro(X_GYRO);
    resetGyro(Y_GYRO);
}
