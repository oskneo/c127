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
	
	//uint8_t cl=get_pixel(array,cols,rows,(unsigned int)x,(unsigned int)y);
	uint8_t cl=array[ y*cols + x ];
	
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
	
	//uint8_t *ar2=malloc(cols*rows*sizeof(uint8_t));
	int ar3[100][3],k=0;
	//zero(ar2,cols,rows);
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
		            //set_pixel(ar2, cols, rows, i,j,1);
		            ar3[k][0]=i;
		            ar3[k][1]=j;
		            ar3[k][2]=1;
		            k++;
		            //printf("i:%d,j:%d,0.\n",i,j);
		        }
		        
		        
		    }
		    else{
		        if(n==3){
		            //set_pixel(ar2, cols, rows, i,j,2);
		            ar3[k][0]=i;
		            ar3[k][1]=j;
		            ar3[k][2]=2;
		            k++;
		            //printf("i:%d,j:%d,255.\n",i,j);
		        }
		    }
			// if(n){
			// 	printf("i:%d,j:%d,n:%d,st:%d.\n",i,j,n,check);
			// }
			
			
			
		}
	}
	
	//int x=1,y=2;
	//printf("0:%d\n",array[ y*cols + x ]);
	//memcpy(array,ar2,cols*rows*sizeof(uint8_t));
	k--;
	for(;k>=0;k--){
		if(ar3[k][2]==1){
			set_pixel(array, cols, rows, ar3[k][0],ar3[k][1],0);
		}else{
			set_pixel(array, cols, rows, ar3[k][0],ar3[k][1],255);
		}
	}
	
	
	
	
	//printf("1:%d\n",array[ y*cols + x ]);
	//printf("2:%d\n",ar2[ y*cols + x ]);
	//*array=*ar2;
		      
}

