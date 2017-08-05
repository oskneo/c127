
#include <stdlib.h>
#include <iostream>
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
    
    free(pixels);
}
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
    uint8_t* pix;
    if(cols!=width||rows!=height){
        pix=(uint8_t*)realloc(pixels,sizeof(uint8_t)*width*height);
        if(width!=0&& height!=0&&!pix){
            return -1;
        }
        cols=width;
        rows=height;

        pixels=pix;
    }
    for(unsigned int i=0;i<(height*width);i++){
        pixels[i]=fillcolor;
    }
    
    
    
    return 0;
    
}
  
  /* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
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
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
    if(x>=cols||y>=rows){
        return -1;
    }
    if(colorp==NULL){
        return -1;
    }
    else{
        *colorp=pixels[y*cols+x];
        
    }
    
    
    return 0;
    
    
}