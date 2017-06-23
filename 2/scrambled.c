#include <stdio.h>

int scrambled( unsigned int a[], unsigned int b[], unsigned int len ){
    int i,check=1;
    unsigned int totalA=0,totalB=0,varA=0,varB=0;
    for(i=0;i<len;i++){
        totalA+=a[i];
        totalB+=b[i];
        
    }
    if(totalA!=totalB){
        check=0;
        return check;
    }
    float mean=1.0*totalA/len;
    for(i=0;i<len;i++){
        varA+=(mean-a[i])*(mean-a[i]);
        varB+=(mean-b[i])*(mean-b[i]);
        
    }
    if(varA!=varB){
        check=0;
        
    }
    return check;
    
}