#include <stdio.h>
#include <string.h>

 
int main( void )
{
  int f=0,stg[128],zs=0,zd=0,x=0,j=0;
  //char txt[2048]="";
 
  int sig=0;
  //
  while (sig!=EOF){
    //
      sig =scanf( "%d", &f );
      //
      if(sig){
          //
          //int i;
          //
          stg[zs]=f;
          //
          if(f>zd){
            //
              zd=f;
          }
          zs=zs+1;
          
      }
  }
  for( ;x<zd;x++){
    //
      for( ;j<zs;j++){
        //
          if( zd-stg[j]>x){
              printf(" ");//
          }
          else{
              printf("#");//
          }
      }
      printf("\n");//
  }
  

 
  return 0;
}
