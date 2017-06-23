#include <stdio.h>
#include <math.h>
 
int main( void )
{
  float d=0,min=INFINITY,max=-INFINITY,total=0,n=0;
 
  //printf("Enter floating numbers:\n");
  int ern=0;
  while (ern!=EOF){
      ern =scanf( "%f", &d );
      if(ern>0){
          if(d<min){
              min=d;
          }
          if(d>max){
              max=d;
          }
          n++;
          total+=d;
      }
  }
  if(n>0){
        printf( "%.2f %.2f %.2f\n", min, max, total/n );

  }
  // else{
  //     printf("\nPlease input at least one floating number.\n");
  // }
  

 
  return 0;
}
