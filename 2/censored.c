#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> 
 
int main( int argc, char* argv[]  )
{
  
    
    
    

  unsigned long charcount=0;
  char str[204800]="";
  char st;
 
  //printf("Enter anythings:\n");
  int ern=0;
  while (ern!=EOF){
      ern =scanf( "%c", &st );
      if(ern>0){
          
          
          str[charcount]=st;
          str[charcount+1]='\0';
          
          
          charcount++;
          
          
      }
  }
  //puts(str);
  
  
  
    int len2[argc-1],i,j,k,x,check2=1;
    for(x=0;x<argc-1;x++){
        len2[x]=strlen(argv[x+1]);
    }
    //strcmp(argv[1],argv[2]);
    
    //puts("");
    for(i=0;i<charcount;i++){
        
        
        for(k=0;k<argc-1;k++){
            check2=1;
            if(len2[k]>=128){
                k++;
                if(k==argc-1){
                    break;
                }
            }
            for(j=0;j<len2[k];j++){
            
                if(str[i+j]!=argv[k+1][j]){
                    //puts("aaa");
                    check2=0;
                    break;
                }
            
            }
            if(check2==1){
                break;
            }
        }
        if(check2==1){
            printf("CENSORED");
            i+=len2[k]-1;
        }
        else{
            printf("%c",str[i]);
        }
        
        
        
    }
    //puts("");
  
  
  

 
  return 0;
}
