#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int InRectangle( float pt[2], float rect[4] ){
    float x=(rect[0]+rect[2])/2,
    y=(rect[1]+rect[3])/2,
    xb=fabs(rect[0]-x),
    yb=fabs(rect[1]-y);
    int check=-1;
    //gprintf("\n%.6f,%.6f\n",x-xb,y-yb);
    if(pt[0]<=x+xb&&pt[0]>=x-xb&&pt[1]<=y+yb&&pt[1]>=y-yb){
        return 1;
    }
    else{
        return 0;
    }
    
}