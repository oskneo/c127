#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
 
 
int main( int argc, char* argv[] )
{
    int len1=strlen(argv[1]),len2=strlen(argv[2]),i,j,check2=1;
    //strcmp(argv[1],argv[2]);
    char fir=argv[2][0];
    for(i=0;i<len1-len2+1;i++){
        check2=1;
        for(j=0;j<len2;j++){
            if(argv[1][i+j]!=argv[2][j]){
                check2=0;
            }
            
        }
        if(check2==1){
            break;
        }
    }
    if(len1<len2){
        check2=0;
    }
    if(check2==1){
        puts("true");
    }
    else{
        puts("false");
    }
    
    return 0;
}