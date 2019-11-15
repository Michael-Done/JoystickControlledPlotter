void checkActuate (int & headState, tSensors sPort)
{
	if(SensorValue[sPort] == 1)
	{
		if(headState == 1)
			actuate(1);
		else
			actuate(-1);
	}
}