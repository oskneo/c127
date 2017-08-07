#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main( void )
{
  unsigned long cc=0,wc=0,lc=0;
  //
  char xtx[204800];
  memset(xtx,'\0',204800);
  //
  char st;
  //
  int ck=1;
  //
  char *ch="abcdefghijklmnopqrstuvwxyzABCDEFGHJIKLMNOPQRSTUVWXYZ'";
  //
  char *p;
 
  int ern=0;
  //
  while (ern!=EOF){
    //
      ern =scanf( "%c", &st );
      //
      if(ern){
          
          
          xtx[cc]=st;
          xtx[cc+1]='\0';
          
          if(st=='\n'){
            lc++;
          }
          
          if( !isspace(st)&& (isspace(xtx[cc-1])|| xtx[cc-1]=='\0')){
            wc+=ck;
            //ck=0;
          }
          
          p=strchr(ch,st);
          if(!p){
            if(ck){
              ck=0;
            }
            
            
          }
          else{
            if(!ck){
              wc++;
              ck=1;
            }
          }
          p=NULL;
          
          
          
          cc+=1;
          
          
      }
  }
  
  printf( "%lu %lu %lu\n", cc, wc, lc );
  

 
  return 0;
}
