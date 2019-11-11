const int DRAW_MOTOR_LIMIT = 180; // The limit above which the drawing head is considered to be "drawing"
const int X_LIMIT = 360*5; // The maximum x-axis encoder limit
const int Y_LIMIT = 360*5; // The maximum y-axis encoder limit
const int MOVE_TO_TOL = 10; // When the head is within this many ticks of a point, it is considered to be at the point
const int SHAPE_SPEED = 50; // The speed at which the pre-programmed shapes will be drawn
const tSensors COLOR_SENSOR = S1; // The color sensor port
const tMotor X_AXIS = motorA; // The x-axis motor
const tMotor Y_AXIS = motorB; // The y-axis motor
const tMotor DRAW_MOTOR = motorC; // The drawing head medium motor

