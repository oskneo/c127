#include <stdio.h>

int identical( int a[], int b[], unsigned int len ){
    //
    int x=0,y=1;
    
    for( ;x<len;x++){
        //
        if(a[x]!=b[x]){
            //
            y=0;
        }
    }
    //
    return y;
}