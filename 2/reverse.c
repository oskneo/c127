#include <stdio.h>
void reverse( int arr[], unsigned int len ){
    int x;
    //
    for( x=0;x<len/2;x++){
        //
        int zs=arr[x];
        //
        arr[x]=arr[len-x-1];
        //
        arr[len-x-1]=zs;
        
    }
}