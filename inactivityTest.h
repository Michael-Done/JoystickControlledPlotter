//newEncoderX = x-axis motor encoder value
//newEncoderY = y-axis motor encoder value
//oldEncoderx = oldEncoderX value (initialized as 0 in task main() )
//oldEncoderY = oldEncoderY value (initialized as 0 in task main() )

#include "constants.h"


bool inactivityTest(int newEncoderX, int newEncoderY, int & oldEncoderX, int & oldEncoderY) //True implies exit
{
	if (time1[IDLE_TIMER]>IDLETIME)
		return true;

	if(newEncoderX != oldEncoderX && newEncoderY !=oldEncoderY)  //an axis has moved
	{
		time1[T1]=0;
		oldEncoderX=newEncoderX;        //Reset Timer, Update Current Encoder Value
		oldEncoderY=newEncoderY;
	}

	return false;

}

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
