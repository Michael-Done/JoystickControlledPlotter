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
    while(time1[T3] < 2500)
        motor[DRAW_MOTOR] = 20;
    motor[DRAW_MOTOR] = 0;

    nMotorEncoder[X_AXIS] = 0;
    motor[X_AXIS] = 100;
    while(SensorValue[COLOR] != (int)colorRed && SensorValue[COLOR] != (int)colorBlack && nMotorEncoder[X_AXIS] < X_LIMIT)
    {}
    motor[X_AXIS] = 0;

    nMotorEncoder[Y_AXIS] = 0;
    motor[Y_AXIS] = -100;
    while(SensorValue[COLOR] != (int)colorBlack && nMotorEncoder[Y_AXIS] < Y_LIMIT)
    {}
    motor[Y_AXIS] = 0;

    nMotorEncoder[X_AXIS] = 0;
    motor[X_AXIS] = -100;
    while(nMotorEncoder[X_AXIS] < X_LIMIT)
    {}
    motor[X_AXIS] = 0;

    resetGyro(X_GYRO);
    resetGyro(Y_GYRO);
}