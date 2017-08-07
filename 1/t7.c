#include <stdio.h>
#include <string.h>
 
int main( void )
{
  int f=0;
  //
  char txt[2048]="";
  memset(txt,'\0',2048);
 
  
  int sig=0;
  //
  while ( sig!=EOF){
      sig =scanf( "%d", &f );
      if(sig>0){
          //
          int j;
          //
          for(j=0;j<f;j++){
            //
              strcat(txt,"#");
          }
          //
          strcat(txt,"\n");
          
      }
  }
  //
  printf("%s",txt);
  

 
  return 0;
}
