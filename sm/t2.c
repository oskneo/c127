#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char* argv[] )
{
  double fl=atof(argv[1]);
  unsigned int ui=atoi(argv[2]);
  unsigned int n=(unsigned int)round(fl);
  if(argc==3){
    int i,j;
    for(i=0;i<ui;i++){
      for(j=0;j<n;j++){
        printf("#");
      }
      puts("");
    }

  }
   return 0;
}
