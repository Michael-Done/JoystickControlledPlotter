void checkActuate (int & headState, tSensors sPort)
{
	if(SensorValue[TOUCH_SENSOR] == 1)
	{
		if(headState == 1)
			actuate(1, 1);
		else
			actuate(-1, 1);
	}
}