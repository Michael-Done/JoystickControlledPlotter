#include "drawinghead.c"
#include "drawing.c"

// Low-level system reset. This should be accessing sensor and motor data directly rather than through DrawingHead
void systemReset(); 

task main(){
    struct DrawingHead head;
    updateDrawingHead(&head);
}
