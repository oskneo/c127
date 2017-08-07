#include <stdio.h>
void reverse( int arr[], unsigned int len ){
    int x=0;
    //
    for( ;x<len/2;x++){
        //
        int zs=arr[x];
        //
        arr[x]=arr[len-x-1];
        //
        arr[len-x-1]=zs;
        
    }
}