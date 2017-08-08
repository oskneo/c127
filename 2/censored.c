#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 
 
int main( int argc, char* argv[]  )
{
  
    
    
    

  unsigned long cc=0;
  //
  char txt[102400];
  memset(txt,'\0',102400);
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
  
  
  
    int ln[argc-1],a=0,b=0,c=0,x=0,ck=1;
    //
    for( ;x<argc-1;x++){
        //
        ln[x]=strlen(argv[x+1]);
        //
    }
    for( ;a<cc;a++){
        //
        
        for( ;c<argc-1;c++){
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
            for( ;b<ln[c];b++){
            //
                if( txt[a+b]!=argv[c+1][b]){
                  
                    ck=0;
                    //
                    break;
                    //
                }
            
            }
            b=0;
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
        c=0;  
        
        
    }
  

 
  return 0;
}
