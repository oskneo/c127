#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char* argv[] )
{
  double fl=atof(argv[1]);
  unsigned int ui=atoi(argv[2]);
  if(argc==3){
    printf("n=%d count=%u\n",(int)round(fl),ui);
  }
   return 0;
}
