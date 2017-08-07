#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "imgops.h"
void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
		  int x,
		  int y,
		  int r,
		  uint8_t color )
{
	int i,j;
	for(i=0;i<(int)cols&&r>0;i++){
		for(j=0;j<(int)rows;j++){
			if(sqrt(pow((x-i-0.5),2)+pow((y-j-0.5),2))<r){
				set_pixel(img, cols, rows, i,j,color);
			}
			if(sqrt(pow((x-i+.5),2)+pow((y-j+.5),2))<r){
				set_pixel(img, cols, rows, i,j,color);
			}
			if(sqrt(pow((x-i-.5),2)+pow((y-j+.5),2))<r){
				set_pixel(img, cols, rows, i,j,color);
			}
			if(sqrt(pow((x-i+.5),2)+pow((y-j-.5),2))<r){
				set_pixel(img, cols, rows, i,j,color);
			}
		}
	}

		      
}