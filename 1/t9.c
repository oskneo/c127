#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
int main( void )
{
  int a=0,b=0;
  int c=0;
  char txt[2048] ;
  
 memset(txt,'\0',2048);
 
  scanf( "%d", &a );
  //
  scanf( "%d", &b );
  //
  scanf( "%d", &c );
  //
  float m=2.0*c/a;
  //
  int lt,rt,x=c-1,y;
  //
  int ck=0;
  //
  for( ;x>0;x--){
    //
      lt= floor(x/m);
      //
      rt= a-lt-1;
      //
      y=0;
      for( ;y<a&& ck!=3;y++){
          
          
          
          //
          if( y==lt||y==rt|| (ck==1&&x==c-1)){
            //
              strcat( txt,"#");
              //
              if( y==rt){
                //
                  ck=2;
              }
              else if( y==lt){
                //
                  ck=1;
              }
          }
          else if( ck==1){
            //
              strcat( txt,".");
          }
          
          else{
            //
              strcat( txt," ");
          }
          if(ck==2){
            //
            strcat(txt,"\n");
            //
            ck=3;//
          }
      }
      //
      ck=0;
      
  }
  y=0;
  for( ;y<a;y++){
    //
      strcat( txt,"#");
      //
  }
  //
  strcat( txt,"\n");
  
  //
  printf( "%s",txt);
  

 
  return 0;
}
