#include "constants.h"

float setSensitivity()
{
	float sensitivity = 50 + nMotorEncoder[SENS_MOTOR] * SENSFACTOR;

	if(sensitivity > 100)
		return 100;
	else if(sensitivity < 0)
		return 0;

	return sensitivity;
}