#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include "imgops.h"

// void checkpos(unsigned int cr, int *n){
// 	if(*n<0){
// 		*n=0;
// 	}
// 	if(*n>(int)cr){
// 		*n=cr;
// 	}
// }

void comparear(uint8_t ar1[],uint8_t ar2[],unsigned int cols, unsigned int rows){
	unsigned int a,b,count=0;
	for(a=0;a<cols;a++){
		for(b=0;b<rows;b++){
			if(get_pixel(ar1,cols,rows,a,b)!=get_pixel(ar2,cols,rows,a,b)){
				printf("a=%u,b=%u,ar1=%d,ar2=%d;\n",a,b,get_pixel(ar1,cols,rows,a,b),get_pixel(ar2,cols,rows,a,b));
				count++;
			}
		}
		
	}
	printf("count=%u\n",count);
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
	
	uint8_t ar2[cols*rows];
	zero(ar2,cols,rows);
	
	int a,b;
	int x1=x+rect_width,x2=x,
	y1=y+rect_height,y2=y;
	
	if(x1>x2){
		int temp0=x1;
		x1=x2;
		x2=temp0;
	}
	else if(x1-x2==0){
		//x2--;
	}
	else{
		x1++;
		x2++;
	}
	if(y1>y2){
		int temp1=y1;
		y1=y2;
		y2=temp1;
	}
	else if(y1-y2==0){
		//y2--;
	}
	else{
		y1++;
		y2++;
	}
	// checkpos(cols,&x1);
	// checkpos(cols,&x2);
	// checkpos(rows,&y1);
	// checkpos(rows,&y2);
	
	int ck=0;
	for(a=x1;a<x2;a++){
		for(b=y1;b<y2;b++){
		  
			if((a==x1||a==x2-1||b==y1||b==y2-1)&&a>=0&&a<cols&&b>=0&&b<rows){
				set_pixel(array, cols, rows, a,b,color);
				ck++;
			}
		}
	}
	
	printf("x1=%d,x2=%d,y1=%d,y2=%d,ck=%d\n",x1,x2,y1,y2,ck);
	
	
	
	
	
	
	
	// 	      comparear(array,ar2,cols,rows);
}