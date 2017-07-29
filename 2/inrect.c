#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int InRectangle( float pt[2], float rect[4] ){
    //
    float t1=(rect[0]+rect[2])/2,//
    t2=(rect[1]+rect[3])/2,
    
    t1b=fabs(rect[0]-t1),//
    t2b=fabs(rect[1]-t2);
    //int chck=-1;
    //gprintf("\n%.6f,%.6f\n",t1-t1b,t2-t2b);
    if( pt[0]<=t1+t1b&&pt[0]>=t1-t1b&&pt[1]<=t2+t2b&&pt[1]>=t2-t2b){
        //
        return 1;
    }
    else{
        return 0;
    }
    
}