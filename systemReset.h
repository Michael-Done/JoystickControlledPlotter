/*  void systemReset : performs a reset of the actuator porsition and the gyros
    Parameters:
        None
*/
void systemReset()
{
    motor[X_AXIS] = 0;
    motor[Y_AXIS] = 0;

    actuate(-1, 0);

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

    resetGyro(X_GYRO);
    resetGyro(Y_GYRO);
}