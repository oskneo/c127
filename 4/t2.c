#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include "imgops.h"

void checkpos(unsigned int cr, int *n){
	if(*n<0){
		*n=0;
	}
	if(*n>(int)cr){
		*n=cr;
	}
}

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
	int x1=x+rect_width,x2=x,
	y1=y+rect_height,y2=y;
	
	if(x1>x2){
		int temp0=x1;
		x1=x2+1;
		x2=temp0+1;
	}
	else if(x1-x2==0){
		//x2--;
	}
	else{
		//x1++;
		//x2++;
	}
	if(y1>y2){
		int temp1=y1;
		y1=y2+1;
		y2=temp1+1;
	}
	else if(y1-y2==0){
		//y2--;
	}
	else{
		//y1++;
		//y2++;
	}
	checkpos(cols,&x1);
	checkpos(cols,&x2);
	checkpos(rows,&y1);
	checkpos(rows,&y2);
	
	int ck=0;
	for(i=(unsigned int)x1;i<(unsigned int)x2;i++){
		for(j=(unsigned int)y1;j<(unsigned int)y2;j++){
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
			if(i==(unsigned int)x1||i==(unsigned int)x2-1||j==(unsigned int)y1||j==(unsigned int)y2-1){
				set_pixel(array, cols, rows, i,j,color);
				ck++;
			}
		}
	}
	
	printf("x1=%d,x2=%d,y1=%d,y2=%d,ck=%d\n",x1,x2,y1,y2,ck);
		      
}