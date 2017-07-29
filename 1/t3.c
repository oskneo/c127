#include <stdio.h>
#include <math.h>
 
int main( void )
{
  float f = 0;
 
 
  scanf( "%f", &f );
  printf( "%.0f %.0f %.0f\n", floor(f), round(f), ceil(f) );
 
  return 0;
}
