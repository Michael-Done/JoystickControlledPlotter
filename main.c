#include "DrawingHead.h"

// Low-level system reset. This should be accessing sensor and motor data directly rather than through DrawingHead
void systemReset(); 

// Run every loop to update the status of the drawing head with the real-world sensor and encoder data
void updateDrawingHead(struct DrawingHead *head);


task main(){
    struct DrawingHead head;
    updateDrawingHead(&head);
}

void updateDrawingHead(struct DrawingHead *head) {
    // Update motor encoders
    head->x = nMotorEncoder[head->xAxisMotor];
    head->y = nMotorEncoder[head->yAxisMotor];

    // Detect whether or not it is drawing on the surface
    head->drawing = nMotorEncoder[head->drawMotor] >= head->DRAW_MOTOR_LIMIT;

    // Update the color
    head->color = SensorValue[head->colorSensor];
}
