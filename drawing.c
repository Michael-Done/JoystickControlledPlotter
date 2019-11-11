#include "movement.c"

// Functions used for drawing

/*  void drawCircle : draws a circle of specidied radius starting at the center
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        int radius                   : The radius of the circle in encoder ticks
        const struct constants *CON  : structure containing all constants specific to the physical robot
*/
void drawCircle(int startX, int startY, int radius, const struct constants *CON) {
    beginShape(startX, startY, CON);
    // TO DO
    endShape(startX, startY, CON);
}

/*  void drawRect : draws a rectangle of a specified width and height with the bottom left corner specified by the startX and startY
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        int width                    : The width of the rectangle in encoder ticks
        int height                   : The height of the rectangle in encoder ticks
        const struct constants *CON  : structure containing all constants specific to the physical robot
*/
void drawRect(int startX, int startY, int width, int height, const struct constants *CON) {
    beginShape(startX, startY, CON);
    moveTo(startX + width, startY, CON->SHAPE_SPEED, CON);
    moveTo(startX + width, startY + height, CON->SHAPE_SPEED, CON);
    moveTo(startX, startY + height, CON->SHAPE_SPEED, CON);
    moveTo(startX, startY, CON->SHAPE_SPEED, CON);
    endShape(startX, startY, CON);
}

/*  void drawTiangle : draws an equilateral triangle of specified side length
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        int sideLength               : the side length in encoder ticks
        const struct constants *CON  : structure containing all constants specific to the physical robot
*/
void drawTriangle(int startX, int startY, int sideLength, const struct constants *CON) {
    beginShape(startX, startY, CON);
    // TO DO
    endShape(startX, startY, CON);
}

/*  void beginShape : performs actions common to the start of all shapes
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        const struct constants *CON  : structure containing all constants specific to the physical robot
*/
void beginShape(int startX, int startY, const struct constants *CON){
    actuate(false, CON);
    moveTo(startX, startY, CON->SHAPE_SPEED, CON);
    actuate(true, CON);
}

/*  void endShape : performs actions common to the ending of all shapes
    Parameters:
        int startX                   : the start x-axis position
        int startY                   : the start y-axis position
        const struct constants *CON  : structure containing all constants specific to the physical robot
*/
void endShape(int startX, int startY, const struct constants *CON) {
    actuate(false, CON);
    moveTo(startX,startY, CON->SHAPE_SPEED, CON);
}
