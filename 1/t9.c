#include <stdio.h>
#include <math.h>
#include <string.h>
 
int main( void )
{
  int x=0,y=0,z=0,i,j;
  
  char str[2048]="";
  
 
  //printf("Enter three positive integers:\n");
  scanf( "%d", &x );
  scanf( "%d", &y );
  scanf( "%d", &z );
  float m=2.0*z/x;
  int left,right;
  int check=0;
  for(i=z-1;i>0;i--){
      left=floor(i/m);
      right=x-left-1;
      for(j=0;j<x&&check!=3;j++){
          
          
          
          
          if(j==left||j==right||(check==1&&i==z-1)){
              strcat(str,"#");
              if(j==right){
                  check=2;
              }
              else if(j==left){
                  check=1;
              }
          }
          else if(check==1){
              strcat(str,".");
          }
          
          else{
              strcat(str," ");
          }
          if(check==2){
            strcat(str,"\n");
            check=3;
          }
      }
      check=0;
      
  }
  
  for(j=0;j<x;j++){
      strcat(str,"#");
  }
  strcat(str,"\n");
  
  
  printf("%s",str);
  

 
  return 0;
}
