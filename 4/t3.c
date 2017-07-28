#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "imgops.h"

unsigned int deadoralive( uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows , int x, int y)
{
	if(x==-1){
		x=cols-1;
	}
	if(x==cols){
		x=0;
	}
	if(y==-1){
		y=rows-1;
	}
	if(y==rows){
		y=0;
	}
	
	uint8_t cl=get_pixel(array,cols,rows,x,y);
	
    if(cl==0){
		return 0;
		
	}
	else{
	    return 1;
	}
}

void life( uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
	int i,j;
	
	uint8_t *ar2=malloc(cols*rows*sizeof(uint8_t));
	zero(ar2,cols,rows);
	for(i=0;i<cols;i++){
		for(j=0;j<rows;j++){
		    int check =deadoralive(array,cols,rows,i,j);
		    int n=0;
		    if(deadoralive(array,cols,rows,i+1,j)==1){
		        n++;
		    }
		    if(deadoralive(array,cols,rows,i+1,j+1)==1){
		        n++;
		    }
		    if(deadoralive(array,cols,rows,i,j+1)==1){
		        n++;
		    }
		    if(deadoralive(array,cols,rows,i+1,j-1)==1){
		        n++;
		    }
		    if(deadoralive(array,cols,rows,i-1,j+1)==1){
		        n++;
		    }
		    if(deadoralive(array,cols,rows,i-1,j)==1){
		        n++;
		    }
		    if(deadoralive(array,cols,rows,i-1,j-1)==1){
		        n++;
		    }
		    if(deadoralive(array,cols,rows,i,j-1)==1){
		        n++;
		    }
		    if(check==1){
		        if(n<2||n>3){
		            set_pixel(ar2, cols, rows, i,j,0);
		        }
		        
		        
		    }
		    else{
		        if(n==3){
		            set_pixel(ar2, cols, rows, i,j,255);
		        }
		    }
			if(n){
				printf("i:%d,j:%d,n:%d,st:%d.\n",i,j,n,check);
			}
			
			
			
		}
	}
	
	
	memcpy(array,ar2,cols*rows*sizeof(uint8_t));
	//*array=*ar2;
		      
}

