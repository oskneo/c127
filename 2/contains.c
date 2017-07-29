#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
 
 
int main( int argc, char* argv[] )
{
    int cd1=strlen(argv[1]),cd2=strlen(argv[2]);
    
    int a,j,ck=1;
    //char fr=argv[2][0];
    //
    for(a=0;a<cd1-cd2+1;a++){
        //
        ck=1;
        //
        for( j=0;j<cd2;j++){
            //
            if( argv[1][a+j]!=argv[2][j]){
                //
                ck=0;
            }
            
        }
        if( ck==1){
            //
            break;
        }
    }
    if( cd1<cd2){
        //
        ck=0;
    }
    if( ck==1){
        //
        puts("true");
    }
    else{
        //
        puts("false");
    }
    
    return 0;
}