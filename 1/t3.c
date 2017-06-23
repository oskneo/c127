#include <stdio.h>
#include <math.h>
 
int main( void )
{
  float d = 0;
 
  //printf("Enter a floating number: \n");
 
  scanf( "%f", &d );
  printf( "%.0f %.0f %.0f\n", floor(d), round(d), ceil(d) );
 
  return 0;
}
