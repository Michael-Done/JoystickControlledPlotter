struct DrawingHead {
    // // The motor ports corresponding to the x-axis, y-axis, and drawing utensil acuation
    tMotor xAxisMotor, yAxisMotor, drawMotor;

    // The sensor ports for the color sensor
    tSensors colorSensor;
    
    // encoder values of the x and y axis respectively
    int x, y;

    // Specifies if the drawing utensil is on the suface or not
    bool drawing;

    // The limit on the actuation motor above which the head is considered to be drawing
    short DRAW_MOTOR_LIMIT;

    // The current color being sensed by the color sensor
    TLegoColors color;

};