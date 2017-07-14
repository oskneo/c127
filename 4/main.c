#include <stdio.h>
#include "t2.c"

int main(void){
    
    uint8_t img[193*96];
    draw_rectangle( img, 193,  96,  -73,   67,  126,   41,  117 );
    return 0;
}