const int DRAW_MOTOR_LIMIT = 120; // The limit above which the drawing head is considered to be "drawing"
const int X_LIMIT = 1600; // The maximum x-axis encoder limit
const int Y_LIMIT = 1500; // The maximum y-axis encoder limit
const int MOVE_TO_TOL = 3; // When the head is within this many ticks of a point, it is considered to be at the point
const int SHAPE_SPEED = 25; // The speed at which the pre-programmed shapes will be drawn
const int MAX_SENS = 75; // Speed at maximum sensitivity
const int MIN_SENS = 10; // Speed at minimum sensitivity
const float SENSFACTOR = -5*(MAX_SENS/360.0); //The % sensitivity the motor encoder changes
const int ACTUATE_SPEED = 60; //The speed at which the drawing head will actuate
const int IDLETIME = 5*60*1000; //triggers reset once the timer reaches this value
const int MANUAL_IDLETIME = 5000; // Idle on black for this time causees shutdown
const int INNER_GYRO_LIMIT = 10; //dead zone limit for x gyro
const int OUTER_GYRO_LIMIT = 30; //dead zone limit for y gyro
const int GYRO_RESET_TIME = 3*1000; //time until gyros try to reset themselves


const TTimers MANUAL_TIMER = T2; //The timer associated with checking manual shutdown time
const TTimers IDLE_TIMER = T1; // The timer associated with checking the idle time
const int CIRCLE_RAD = 360; // The radius of the preprogrammed circle
const int RECT_W = 360*2; // The width of the preprogrammed rectangle
const int RECT_H = 360*2; // The height of the preprogrammed rectangle
const int TRI_LEN = 360*2; // The side length of the preprogrammed triangl
const int UP = -1; // The integer for not drawing
const int DOWN = 1; // The integer for drawing

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

/*  float arctan : returns the arctangent of given x and y values (0 -> 2*PI)
*/
float arctan(int x, int y){
	float angle;

	if (x > 0) //4th to 1st quadrant
		angle = atan(y/x);
	else if (x < 0) //2nd to 3rd quadrant
		angle = PI + atan(y/x);
	else if (x == 0 && y > 0) //vertical up
		angle = PI/2;
	else if (x == 0 && y < 0) //vertical down
		angle = 3*PI/2;
	else //x,y = 0
		angle = 0;

	return angle;
}