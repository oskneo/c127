#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h>
#include <string.h>
#include "image.hpp"

using namespace std;
unsigned int cols;
unsigned int rows;
uint8_t* pixels;

Image::Image(){
    cols=0;
    rows=0;
    pixels=(uint8_t*)realloc(NULL,sizeof(uint8_t*));
}
Image::~Image(){
    //free(cols);
    //free(rows);
    free(pixels);
}
int resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
    pixels=(uint8_t*)realloc(pixels,sizeof(uint8_t)*width*height);
    if(pixels==NULL){
        return -1;
    }
    for(int i;i<(int)(height*width);i++){
        pixels[i]=fillcolor;
    }
    cols=width+1;
    rows=height+1;
    
    return 0;
    
}
  
  /* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int set_pixel( unsigned int x, unsigned int y, uint8_t color ){
    if(x<cols&&y<rows)
    {
        pixels[y*cols+x]=color;
        return 0;
    }
    else{
        return -1;
    }
}
  
  /* Gets the color of the pixel at (x,y) and stores at the address pointed to 
     by colorp. Returns 0 on success, else a non-zero error code. */
int get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
    if(y*cols+x>cols*rows){
        return -1;
    }
    
    if(x<cols&&y<rows)
    {
        *colorp=pixels[y*cols+x];
        return 0;
    }
    else{
        return -1;
    }
    
    
}