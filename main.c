#include "DrawingHead.h"

// Low-level system reset. This should be accessing sensor and motor data directly rather than through DrawingHead
void systemReset();

// Creates a new structure to keep track of the drawing head's data
struct DrawingHead newDrawingHead();

task main(){
    struct DrawingHead head = newDrawingHead();
}