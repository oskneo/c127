#include <stdio.h>
#include <math.h>
 
int main( void )
{
  float d=0;
 
  //printf("Enter floating numbers:\n");
  int ern=0;
  while (ern!=EOF){
      ern =scanf( "%f", &d );
      if(ern>0){
        printf( "%.0f %.0f %.0f\n", floor(d), round(d), ceil(d) );
      }
      
  }
  puts("Done.");
  

 
  return 0;
}
