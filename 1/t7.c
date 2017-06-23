#include <stdio.h>
#include <string.h>
 
int main( void )
{
  int d=0;
  char str[2048]="";
 
  //printf("Enter an abitary number of positive integer numbers:\n");
  int ern=0;
  while (ern!=EOF){
      ern =scanf( "%d", &d );
      if(ern>0){
          
          int i;
          for(i=0;i<d;i++){
              strcat(str,"#");
          }
          strcat(str,"\n");
          
      }
  }
  
  printf("%s",str);
  

 
  return 0;
}
