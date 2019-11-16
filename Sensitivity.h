#include "constants.h"
float setSensitivity()
{
	float sensitivity = nMotorEncoder[SENS_MOTOR] * SENSFACTOR;

	if(sensitivity > 100)
		return 100;
	else if(sensitivity < 0)
		return 0;

	return sensitivity;
}
