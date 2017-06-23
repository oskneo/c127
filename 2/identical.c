#include <stdio.h>

int identical( int a[], int b[], unsigned int len ){
    int i,iden=1;
    
    for(i=0;i<len;i++){
        if(a[i]!=b[i]){
            iden=0;
        }
    }
    return iden;
}