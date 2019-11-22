/*  float setsensitivity : sets and returnss the sensitivity value based on motor input
    Parameters:
        None
*/
float setSensitivity()
{
	float sensitivity = (MAX_SENS+MIN_SENS)/2.0 + nMotorEncoder[SENS_MOTOR] * SENSFACTOR;
	char sensBar[30];
	for(int count = 0; count < 30; count++){
			if(count <= sensitivity/MAX_SENS*30.0)
				sensBar[count] = '|';
			else
				sensBar[count] = ' ';
	}
	eraseDisplay();
	displayString(8, sensBar);
	if(sensitivity > MAX_SENS)
		return MAX_SENS;
	else if(sensitivity < MIN_SENS)
		return MIN_SENS;

	return sensitivity;
}
