#include <stdio.h>
#include <math.h>
 
int main( void )
{
  float d = 0;
 
  //printf("Enter a floating number: \n");
  int ern =scanf( "%f", &d );
  if(ern<=0){
      printf("scanf error: (%d)\n",ern);
  }
  else{
      printf( "%.0f %.0f %.0f\n", floor(d), round(d), ceil(d) );

  }
  //printf("%d",ern);
  //puts("");
 
  return 0;
}
