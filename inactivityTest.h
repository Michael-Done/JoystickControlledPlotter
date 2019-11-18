/*  bool inactivityTest: Checks if the robot has not moved for the designated idle time. If true, system shuts off
Parameters:
int oldEncoderX                   : value of the x position last moved to. Used for to check for movement.
int oldEncoderY                   : value of the y position last moved to. Used for to check for movement.
*/

bool inactivityTest(int & oldEncoderX, int & oldEncoderY) //True implies exit entire program
{
	if (time1[IDLE_TIMER]>IDLETIME)
		return true;

	if(nMotorEncoder[X_AXIS] != oldEncoderX || nMotorEncoder[Y_AXIS] != oldEncoderY)  //an axis has moved
	{
		time1[IDLE_TIMER]=0;
		oldEncoderX= nMotorEncoder[X_AXIS];        //Reset Timer, Update Current Encoder Tracker Value
		oldEncoderY= nMotorEncoder[Y_AXIS];
	}

	return false;

}

/*  bool manualShutdown: Checks if the robot has been moved over the black box for duration of manual idle time. If true, system shuts off
Parameters:
None.
*/

bool manualShutdown()
{
	if (SensorValue[COLOR_SENSOR] == (int)colorBlack || SensorValue[COLOR_SENSOR] == 0)
	{
		if (time1[MANUAL_TIMER]>=MANUAL_IDLETIME)
			return true;
		return false;
	}
	time1[MANUAL_TIMER]=0;
	return false;

}

void checkRecalibrate(int & oldGyroX, int & oldGyroY) //in deadzone and not changed
{
	if( (getGyroDegrees(X_GYRO) == oldGyroX) && (getGyroDegrees(Y_GYRO)==oldGyroY))
		if(abs(oldGyroX)<INNER_GYRO_LIMIT && abs(oldGyroY)<INNER_GYRO_LIMIT)
			if (time1[IDLE_TIMER]>GYRO_RESET_TIME)
				{
					 resetGyro(X_GYRO);
    				 resetGyro(Y_GYRO);
				}


	oldGyroX = getGyroDegrees(X_GYRO);  //if gyros have moved, update old values
	oldGyroY = getGyroDegrees(Y_GYRO);

}
