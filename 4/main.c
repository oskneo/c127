#include <stdio.h>
#include "imgops.h"

int main(void){
	int w=500,h=500;
	
	int glider[][2] = { {1,0}, {2,1}, {0,2}, {1,2}, {2,2} };   

	for( int i=0; i<5; i++ )
    		set_pixel( img, w, h, glider[i][0], glider[i][1], 255 );
  
	for( int i=0; i<32; i++ )
	{ 
      		draw_image_grey( img, w, h );
      		life( img, w, h );
	} 
	draw_image_grey( img, w, h );


}
