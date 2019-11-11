struct constants {
    int DRAW_MOTOR_LIMIT; // The limit above which the drawing head is considered to be "drawing"
    int X_LIMIT; // The maximum x-axis encoder limit
    int Y_LIMIT; // The maximum y-axis encoder limit
    int MOVE_TO_TOL; // When the head is within this many ticks of a point, it is considered to be at the point
    int SHAPE_SPEED; // The speed at which the pre-programmed shapes will be drawn
};
