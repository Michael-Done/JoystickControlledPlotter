/*  float setsensitivity : sets and returnss the sensitivity value based on motor input
    Parameters:
        None
*/
float setSensitivity()
{
	float sensitivity = 50 + nMotorEncoder[SENS_MOTOR] * SENSFACTOR;
	eraseDisplay();
	for(int count = 0; count < sensitivity/100.0*175; count+=5){
		displayStringAt(count, 65, "|");
	}
	if(sensitivity > 100)
		return 100;
	else if(sensitivity < 0)
		return 0;

	return sensitivity;
}
