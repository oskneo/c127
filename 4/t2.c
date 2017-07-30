#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include "imgops.h"
void draw_rectangle( uint8_t array[], 
		          unsigned int cols, 
		          unsigned int rows, 
		          int x,
		          int y,
		          int rect_width,
		          int rect_height,
		          uint8_t color )
{
	unsigned i,j;
	int x1=x+rect_width,x2=x-rect_width,
	y1=y+rect_height,y2=y-rect_height;
	if(x1>x2){
		int temp0=x1;
		x1=x2-1;
		x2=temp0;
	}
	else{
		x2++;
	}
	if(y1>y2){
		int temp1=y1;
		y1=y2-1;
		y2=temp1;
	}
	else{
		y2++;
	}
	for(i=x1;i<=x2;i++){
		for(j=y1;j<=y2;j++){
		  //  int check =1;
		  //  if(x+rect_width<x){
		  //      if(i<x+rect_width||i>x){
		  //          check=0;
		  //      }
		  //  }
		  //  else{
		  //      if(i<x||i>x+rect_width){
		  //          check=0;
		  //      }
		  //  }
		  //  if(y+rect_height<y){
		  //      if(i<y+rect_height||i>y){
		  //          check=0;
		  //      }
		  //  }
		  //  else{
		  //      if(i<y||i>y+rect_height){
		  //          check=0;
		  //      }
		  //  }
			if((i==x1||i==x2)||(j==y1||j==y2)){
				set_pixel(array, cols, rows, i,j,color);
			}
		}
	}
		      
}