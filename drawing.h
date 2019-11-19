#include "movement.h"
#include "systemReset.h"
#include "actuate.h"

// Functions used for drawing

/*  void beginShape : performs actions common to the start of all shapes
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
*/
void beginShape(int startX, int startY){
    while(getButtonPress(buttonAny)) {}
    actuate(UP, false);
    moveTo(startX, startY, SHAPE_SPEED, true);
}

/*  void endShape : performs actions common to the ending of all shapes
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
*/
void endShape(int startX, int startY) {
    actuate(UP, false);
    moveTo(startX,startY, SHAPE_SPEED, true);
    time1[IDLE_TIMER] = 0;
}

/*  void drawCircle : draws a circle of specified radius starting at the center
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        int radius                   : The radius of the circle in encoder ticks
*/
void drawCirc(int startX, int startY, int radius) {
    beginShape(startX, startY);
    moveTo(startX + radius, startY, SHAPE_SPEED, true);
    actuate(DOWN, false);
    for(int angle = 0; angle <= 360; angle += 1) {
        moveTo(startX + radius*cos(angle*(PI/180)), startY + radius*sin(angle*(PI/180)), SHAPE_SPEED, angle == 360);
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
    actuate(DOWN, false);
    moveTo(startX + width, startY, SHAPE_SPEED, true);
    moveTo(startX + width, startY + height, SHAPE_SPEED, true);
    moveTo(startX, startY + height, SHAPE_SPEED, true);
    moveTo(startX, startY, SHAPE_SPEED, true);
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
    actuate(DOWN, false);
    moveTo(startX + sideLength, startY, SHAPE_SPEED, true);
    wait1Msec(100);
    moveTo(startX + sideLength*cos(PI/3.0), startY + sideLength*sin(PI/3.0), SHAPE_SPEED, true);
    wait1Msec(100);
    moveTo(startX, startY, SHAPE_SPEED, true);
    wait1Msec(100);
    endShape(startX, startY);
}

/*  void checkButtons : checks the EV3 buttons to see if the robot needs to draw any shapes
    Parameters:
        None
*/
void checkButtons(){
    if(getButtonPress(buttonUp))
        drawCirc(nMotorEncoder[X_AXIS], nMotorEncoder[Y_AXIS], CIRCLE_RAD);
    else if(getButtonPress(buttonEnter))
        drawRectangle(nMotorEncoder[X_AXIS], nMotorEncoder[Y_AXIS], RECT_W, RECT_H);
    else if(getButtonPress(buttonDown))
        drawTriangle(nMotorEncoder[X_AXIS], nMotorEncoder[Y_AXIS], TRI_LEN);
    else if (getButtonPress(buttonBack))
    {
       	while (getButtonPress(buttonBack))
	        {}
        systemReset();
    }
}
