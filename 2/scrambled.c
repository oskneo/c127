#include <stdio.h>

int scrambled( unsigned int a[], unsigned int b[], unsigned int len ){
    //
    int x,jc=1;
    //
    unsigned int sumA=0,sumB=0,ybA=0,ybB=0;
    //
    for( x=0;x<len;x++){
        //
        sumA=sumA+a[x];
        //
        sumB=sumB+b[x];
        
    }
    //
    if(sumA!=sumB){
        //
        jc=0;
        //
        return jc;
    }
    //
    float pj= 1.0*sumA/len;
    //
    for( x=0;x<len;x++){
        //
        ybA=ybA+(pj-a[x])*(pj-a[x]);
        //
        ybB=ybB+(pj-b[x])*(pj-b[x]);
        
    }
    if(ybA!=ybB){
        //
        jc=0;
        
    }
    //
    return jc;
    
}