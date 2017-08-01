#include <string.h>
void revstr(char s[]){
  int len=strlen(s),i;
  // if(len%2==0){
  //   for(i=0;i<len/2;i++){
  //     char t=s[i];
  //     s[i]=s[len-i-1];
  //     s[len-i-1]=t;
  //   }
  // }
  // else{
  //   for(i=0;i<len/2;i++){
  //     char t=s[i];
  //     s[i]=s[len-i-1];
  //     s[len-i-1]=t;
  //   }
  // }
  for(i=0;i<len/2;i++){
    char t=s[i];
    s[i]=s[len-i-1];
    s[len-i-1]=t;
  }
}
