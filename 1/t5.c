#include <stdio.h>
#include <math.h>
 
int main( void )
{
  //
  float f=0;
 
  //
  int sig=0;
  //
  while (sig!=EOF){
      sig =scanf( "%f", &f );
      if(sig>0){
        printf( "%.0f %.0f %.0f\n", floor(f), round(f), ceil(f) );
      }
      
  }
  //
  printf("Done.\n");
  

 
  return 0;
}
