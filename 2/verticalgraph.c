#include <stdio.h>
#include <string.h>

 
int main( void )
{
  int d=0,ver[128],n=0,max=0,i,j;
  char str[2048]="";
 
  //printf("Enter an abitary number of positive integer numbers:\n");
  int ern=0;
  while (ern!=EOF){
      ern =scanf( "%d", &d );
      if(ern>0){
          
          int i;
          ver[n]=d;
          if(d>max){
              max=d;
          }
          n++;
          
      }
  }
  //puts("");
  for(i=0;i<max;i++){
      for(j=0;j<n;j++){
          if(max-ver[j]>i){
              printf(" ");
          }
          else{
              printf("#");
          }
      }
      puts("");
  }
  
  //printf("\n%s",str);
  

 
  return 0;
}
