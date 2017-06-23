#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 
 
int main( void )
{
  
    
    
    

  unsigned long charcount=0,n=0;
  char str[204800]="";
  char st;
  int dt[26][2],i,j;
  for(j=0;j<26;j++){
      dt[j][0]='a'+j;
      dt[j][1]=0;
  }
  
 
  //printf("Enter anythings:\n");
  int ern=0;
  while (ern!=EOF){
      ern =scanf( "%c", &st );
      if(ern>0){
          
          st=tolower(st);
          str[charcount]=st;
          str[charcount+1]='\0';
          
          for(i=0;i<26;i++){
              if(dt[i][0]==st){
                  dt[i][1]++;
                  n++;
              }
          }
          
          charcount++;
          
          
      }
  }
  //puts("");
  for(j=0;j<26;j++){
      if(dt[j][1]>0){
          printf("%c %.4f\n",dt[j][0],1.0*dt[j][1]/n);
      }
      
  }
  
  
  
  
  

 
  return 0;
}
