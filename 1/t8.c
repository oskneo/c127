#include <stdio.h>
#include <string.h>
 
int main( void )
{
  int a=0,b=0;
  //
  int i,j,c=0;
  //
  char txt[2048]="";
  
 
  
  scanf( "%d", &a );
  //
  scanf( "%d", &b );
  //
  
  scanf( "%d", &c );
  
  for( i=0;i<b;i++){
      for( j=0;j<a;j++){
          if( i==0||i==b-1|| j==0||j==a-1){
            //
              strcat(txt,"#");
          }
          else{
            //
              strcat(txt,".");
          }
      }
      //
      strcat(txt,"\n");
  }
  
  //
  printf("%s",txt);
  

 
  return 0;
}
