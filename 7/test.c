#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void){
    
    
    int (*a1)[2]=malloc(sizeof(int)*2*5);
    //int a2[2]={1,2};
    //*(a1[0])=*a2;
    //a1[0]=malloc(sizeof(int)*2);
    //memcpy(a1[0],a2,sizeof(int)*2);
    a1=realloc(a1,sizeof(int)*2*10);
    
    printf("%d\n",a1[8][1]);
    
    
    
    return 0;
}