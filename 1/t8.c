#include <stdio.h>
#include <string.h>
 
int main( void )
{
  int x=0,y=0,z=0,i,j;
  char str[2048]="";
  
 
  //printf("Enter three positive integers:\n");
  scanf( "%d", &x );
  scanf( "%d", &y );
  scanf( "%d", &z );
  
  for(i=0;i<y;i++){
      for(j=0;j<x;j++){
          if(i==0||i==y-1||j==0||j==x-1){
              strcat(str,"#");
          }
          else{
              strcat(str,".");
          }
      }
      strcat(str,"\n");
  }
  
  
  printf("%s",str);
  

 
  return 0;
}
