#include <stdio.h>
#include <math.h>
 
int main( void )
{
  float f = 0, mnum = INFINITY, xnum = -INFINITY, tt = 0, n = 0;
 
  
  int sig=0;
  //
  while ( sig!=EOF ){
    //
      sig =scanf( "%f", &f );
      //
      if(sig>0){
          if(f<mnum){
            //
              mnum=f;
              //
          }
          if ( f > xnum ){
            //
              xnum = f;
              //
          }
          //
          n++;
          //
          tt+=f;
      }
  }
  if ( n > 0 ){
    //
        printf( "%.2f %.2f %.2f\n", mnum, xnum, tt/n );
//
  }
  

 
  return 0;
}
