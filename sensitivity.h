/*  float setsensitivity : sets and returnss the sensitivity value based on motor input
    Parameters:
        None
*/
float setSensitivity()
{
	float sensitivity = (MAX_SENS-MIN_SENS)/2.0 + nMotorEncoder[SENS_MOTOR] * SENSFACTOR;

	if(sensitivity > MAX_SENS)
		return MAX_SENS;
	else if(sensitivity < MIN_SENS)
		return 0;

	return sensitivity;
}
