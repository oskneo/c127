#include <stdio.h>
#include <math.h>
#include <stdint.h>

void draw_circle( uint8_t img[], 
                  unsigned int cols,
                  unsigned int rows,
		  int x,
		  int y,
		  int r,
		  uint8_t color )
{
	// int i,j;
	// for(i=0;i<(int)cols;i++){
	// 	for(j=0;j<(int)rows;j++){
	// 		if(round(sqrt(pow((x-i-.5),2)+pow((y-j-.5),2)))<r&&r>0){
	// 			set_pixel(img, cols, rows, i,j,color);
	// 		}
	// 		if(round(sqrt(pow((x-i+.5),2)+pow((y-j+.5),2)))<r&&r>0){
	// 			set_pixel(img, cols, rows, i,j,color);
	// 		}
	// 		if(round(sqrt(pow((x-i-.5),2)+pow((y-j+.5),2)))<r&&r>0){
	// 			set_pixel(img, cols, rows, i,j,color);
	// 		}
	// 		if(round(sqrt(pow((x-i+.5),2)+pow((y-j-.5),2)))<r&&r>0){
	// 			set_pixel(img, cols, rows, i,j,color);
	// 		}
	// 	}
	// }
		int i, j;
    double dx,dy,dt;
 
    for(i = 0; i< cols; i++)
    {
        for(j = 0; j< rows;j++)
        {
 
          if(r > 0 )
          {
            dx = i-x-.5;
            dy = j-y-.5;
            dt = sqrt(pow(dx,2) + pow(dy,2));
            if(dt<r)
            {
                set_pixel(img, cols, rows, i,j,color);
            }
 
            dx = i-x+.5;
            dy = j-y+.5;
            dt = sqrt(pow(dx,2) + pow(dy,2));
            if(dt<r)
            {
                set_pixel(img, cols, rows, i,j,color);
            }
 
            dx = i-x+.5;
            dy = j-y-.5;
            dt = sqrt(pow(dx,2) + pow(dy,2));
            if(dt<r)
            {
                set_pixel(img, cols, rows, i,j,color);
            }
 
 
            dx = i-x-.5;
            dy = j-y+.5;
            dt = sqrt(pow(dx,2) + pow(dy,2));
            if(dt<r)
            {
                set_pixel(img, cols, rows, i,j,color);
            }
          } 
 
        }
    }
		      
}