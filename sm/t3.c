#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main( int argc, char* argv[] )
{
  double fl=atof(argv[1]);
  unsigned int ui=atoi(argv[2]);
  unsigned int n=(unsigned int)round(fl);
  int j,i=1;
  for(j=0;j<n;j++){
    printf("#");
  }
  do{
    i++;
    puts("");
    if(n%2==0){
      n=n/2;
    }
    else{
      n=3*n+1;
    }
    for(j=0;j<n;j++){
      printf("#");
    }
  }
  while(i<ui);
  puts("");


   return 0;
}
