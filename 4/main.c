#include <stdint.h>
#include "imgops.h"
#include "t2.h"


int main(void){
    
    unsigned int cols=193,rows=96;
    uint8_t ar[cols*rows];
    zero(ar,cols,rows);
    draw_rectangle(ar,cols,rows,40,122,9,-48,255);
}