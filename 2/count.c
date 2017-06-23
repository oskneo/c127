#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main( void )
{
  unsigned long charcount=0,wordcount=0,linecount=0;
  char str[204800]="";
  char st;
  //int check=1;
 
  //printf("Enter anythings:\n");
  int ern=0;
  while (ern!=EOF){
      ern =scanf( "%c", &st );
      if(ern>0){
          
          
          str[charcount]=st;
          str[charcount+1]='\0';
          
          if(st=='\n'){
            linecount++;
          }
          // if(charcount>0&&(st==' '||st=='.'||st=='\n'||st==EOF||st=='\"'||st==','||st=='-'||st=='?'||st=='!')&&(isalpha(str[charcount-1])||str[charcount-1]=='\'')){
          //   wordcount++;
          // }
          
          if(!isspace(st)&&(isspace(str[charcount-1])||str[charcount-1]=='\0')){
            wordcount+=check;
            //check=0;
          }
          // else{
          //   check=1;
            
          // }
          if(st=='\n'){
              linecount++;
          }
          
          charcount++;
          
          
      }
  }
  //puts(str);
  if(str[charcount-2]!='\n'){
    linecount++;
  }
  
  printf( "%lu %lu %lu\n", charcount, wordcount, linecount );
  

 
  return 0;
}
