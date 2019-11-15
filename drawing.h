#include "movement.h"
#include "constants.h"

// Functions used for drawing

/*  void beginShape : performs actions common to the start of all shapes
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
*/
void beginShape(int startX, int startY){
    while(getButtonPress(buttonAny)) {}
    actuate(false);
    moveTo(startX, startY, SHAPE_SPEED);
}

/*  void endShape : performs actions common to the ending of all shapes
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
*/
void endShape(int startX, int startY) {
    actuate(false);
    moveTo(startX,startY, SHAPE_SPEED);
    time1[IDLE_TIMER] = 0;
}

/*  void drawCircle : draws a circle of specidied radius starting at the center
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        int radius                   : The radius of the circle in encoder ticks
*/
void drawCirc(int startX, int startY, int radius) {
    beginShape(startX, startY);
    moveTo(startX + radius, startY, SHAPE_SPEED);
    actuate(true);
    for(int angle = 0; angle <= 360; angle += 10) {
        moveTo(startX + radius*cos(angle*(PI/180)), startY + radius*sin(angle*(PI/180)), SHAPE_SPEED);
    }
    endShape(startX, startY);
}

/*  void drawRect : draws a rectangle of a specified width and height with the bottom left corner specified by the startX and startY
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        int width                    : The width of the rectangle in encoder ticks
        int height                   : The height of the rectangle in encoder ticks
*/
void drawRectangle(int startX, int startY, int width, int height) {
    beginShape(startX, startY);
    actuate(true);
    moveTo(startX + width, startY, SHAPE_SPEED);
    moveTo(startX + width, startY + height, SHAPE_SPEED);
    moveTo(startX, startY + height, SHAPE_SPEED);
    moveTo(startX, startY, SHAPE_SPEED);
    endShape(startX, startY);
}

/*  void drawTiangle : draws an equilateral triangle of specified side length
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        int sideLength               : the side length in encoder ticks
*/
void drawTriangle(int startX, int startY, int sideLength) {
    beginShape(startX, startY);
    actuate(true);
    moveTo(startX + sideLength, startY, SHAPE_SPEED);
    moveTo(startX + sideLength*cos(PI/3.0), startY + sideLength*sin(PI/3.0), SHAPE_SPEED);
    moveTo(startX, startY, SHAPE_SPEED);
    endShape(startX, startY);
}

/*  void checkButtons : checks the EV3 buttons to see if the robot needs to draw any shapes
    Parameters:
        None
*/
void checkButtons(){
    if(getButtonPress(buttonLeft))
        drawCirc(nMotorEncoder[X_AXIS], nMotorEncoder[Y_AXIS], CIRCLE_RAD);
    else if(getButtonPress(buttonEnter))
        drawRectangle(nMotorEncoder[X_AXIS], nMotorEncoder[Y_AXIS], RECT_W, RECT_H);
    else if(getButtonPress(buttonRight))
        drawTriangle(nMotorEncoder[X_AXIS], nMotorEncoder[Y_AXIS], TRI_LEN);
}
