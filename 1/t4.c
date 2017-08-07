#include <stdio.h>
#include <math.h>
 
int main( void )
{
  float f = 0;
 
  
  int sig =scanf( "%f", &f );
  //
  if(!sig){
      printf("scanf error: (%d)\n",sig);
      //
  }
  else{
      printf( "%.0f %.0f %.0f\n", floor(f), round(f), ceil(f) );
//
  }
  
 
  return 0;
}
