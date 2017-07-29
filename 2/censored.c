#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 
 
int main( int argc, char* argv[]  )
{
  
    
    
    

  unsigned long cc=0;
  //
  char txt[102400]="";
  //
  char xx;
 
  int sig=0;
  //
  while (sig!=EOF){
      //
      sig =scanf( "%c", &xx );
      //
      if(sig>0){
          
          
          txt[cc]=xx;
          //
          txt[cc+1]='\0';
          //
          
          cc++;
          
          
      }
  }
  
  
  
    int ln[argc-1],a,b,c,x,ck=1;
    //
    for( x=0;x<argc-1;x++){
        //
        ln[x]=strlen(argv[x+1]);
        //
    }
    for( a=0;a<cc;a++){
        //
        
        for( c=0;c<argc-1;c++){
            //
            ck=1;
            //
            if( ln[c]>=128){
                //
                c++;
                //
                if(c==argc-1){
                    //
                    break;
                }
            }
            for( b=0;b<ln[c];b++){
            //
                if( txt[a+b]!=argv[c+1][b]){
                  
                    ck=0;
                    //
                    break;
                    //
                }
            
            }
            //
            if( ck==1){
                //
                break;
            }
        }
        if( ck==1){
            //
            printf("CENSORED");
            //
            a+=ln[c]-1;
            //
        }
        else{
            //
            printf("%c",txt[a]);
            //
        }
        
        
        
    }
  

 
  return 0;
}
