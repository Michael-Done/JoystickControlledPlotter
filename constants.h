const int DRAW_MOTOR_LIMIT = 120; // The limit above which the drawing head is considered to be "drawing"
const int X_LIMIT = 1600; // The maximum x-axis encoder limit
const int Y_LIMIT = 1500; // The maximum y-axis encoder limit
const int MOVE_TO_TOL = 3; // When the head is within this many ticks of a point, it is considered to be at the point
const int SHAPE_SPEED = 25; // The speed at which the pre-programmed shapes will be drawn
const float SENSFACTOR = -3*(100/360.0); //The % sensitivity the motor encoder changes
const int ACTUATE_SPEED = 20; //The speed at which the drawing head will actuate
const int IDLETIME = 50000; //triggers reset once the timer reaches this value
const int MANUAL_IDLETIME = 5000;
const int X_GYRO_LIMIT = 15; //dead zone limit for x gyro
const int Y_GYRO_LIMIT = 15; //dead zone limit for y gyro
//const tSensors COLOR_SENSOR = S1; // The color sensor port
//const tMotor X_AXIS = motorA; // The x-axis motor
//const tMotor Y_AXIS = motorB; // The y-axis motor
//const tMotor DRAW_MOTOR = motorC; // The drawing head medium motor

const TTimers MANUAL_TIMER = T2; //The timer associated with checking manual shutdown time
const TTimers IDLE_TIMER = T1; // The timer associated with checking the idle time
const int CIRCLE_RAD = 360*2; // The radius of the preprogrammed circle
const int RECT_W = 360*2; // The width of the preprogrammed rectangle
const int RECT_H = 360*2; // The height of the preprogrammed rectangle
const int TRI_LEN = 360*3; // The side length of the preprogrammed triangl
const int UP = -1;
const int DOWN = 1;
/*  int max : returns the larger of two integer values
*/
int max(int a, int b){
	if(a > b)
		return a;
	return b;
}

/*  int min : returns the smaller of two integer values
*/
int min(int a, int b){
	if(a < b)
		return a;
	return b;
}
