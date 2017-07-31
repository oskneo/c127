#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"




/* LAB 6 TASK 2 */

/*
  Save the entire array ia into a file called 'filename' in a JSON
  text file array file format that can be loaded by
  intarr_load_json(). Returns zero on success, or a non-zero error
  code on failure. Arrays of length 0 should produce an output file
  containing an empty array.
  
  The JSON output should be human-readable.

  Examples:

  The following line is a valid JSON array:
  [ 100, 200, 300 ]
  
  The following lines are a valid JSON array:
  [ 
   100, 
   200, 
   300 
  ]
*/
int intarr_save_json( intarr_t* ia, const char* filename ){
  if(ia==NULL){
    return -4;
  }
  if(filename==NULL){
    return -5;
  }
    
  char st[100000];//=malloc(2000*sizeof(char));
  strcat(st,"[ ");
  char tk[20];
  int i;
  //char temp[10]="";
  
  if(ia==NULL||ia->len<0){
      return -1;
  }
  if(ia->data!=NULL&&ia->len>0){
      sprintf(tk,"%d",ia->data[0]);
      strcat(st,tk);
  }
  for(i=1;i<ia->len;i++){
      strcat(st,", ");
      sprintf(tk,"%d",ia->data[i]);
      strcat(st,tk);
  }
  strcat(st," ]\0");
  //st=(char*)realloc(st,strlen(st));
  int c=0;
  for(;st[c]!='\0';c++){}
  
    
  FILE* file=fopen(filename,"w");
  if(!file){
      return -1;
  }
  if(!fwrite(st,c,1,file)){
      return -2;
  }
  fclose(file);
  
  
  
  return 0;
    
}

/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save(). The file may contain an array
  of length 0. Returns a pointer to a newly-allocated intarr_t on
  success (even if that array has length 0), or NULL on failure.
*/
intarr_t* intarr_load_json( const char* filename ){
  if(filename==NULL){
    puts("file name null.");
    return NULL;
  }
    
  char st[100000],*tk;
  int fs=0;
  intarr_t* ia=intarr_create(0);
  if(!ia){
    puts("intarr create null.");
    return NULL;
  }
  
  //char temp[10]="";
  //puts("ccccc");
  FILE* file=fopen(filename,"r");
  if(!file){
      puts("file null");
      return NULL;
  }
  //puts("aaaa");
  fseek(file, 0, SEEK_END); 
  fs = ftell(file); 
  fseek(file, 0, SEEK_SET); 
  if(!fread(st,sizeof(char),fs,file)){
      puts("read null");
      return NULL;
  }
  fclose(file);
  //puts("bbbb");
  //puts(st);
  //strcat(st,"\0");
  //printf("%s...%lu\n",st,sizeof(intarr_t));
  
  int check=0,check2=0,check3=0;
  tk=strtok(st,", \t\0\n");
  //puts("ffff");
  while(tk!=NULL&&check!=4){
      //puts("ddddd");
      // if(ia->data!=NULL){
      //   printf("%d    %d\n",ia->data[0],ia->len);
      // }
      //puts(tk);
      check3++;
      if(strcmp(tk,"[")==0){
        check=1;
      }
      // else if(strcmp(tk,",")==0){
      //   check=2;
      // }
      else if(strcmp(tk,"]")==0){
        check=4;
      }
      else if(check==1){
        // if(ia->len==0){
        //   free(ia->data);
        // }
        if(intarr_push(ia,atoi(tk))==INTARR_BADALLOC){
          check2++;
        }
        //intarr_push(ia,atoi(tk));
        //check=1;
      }
      
      
      
      //printf("%d\n",ia->len);
      //puts("dde");
      tk=strtok(NULL,", \t\0\n");
      //puts("ddfdd");
  }
  
  printf("len=%d,check2=%d,check3=%d\n",ia->len,check2,check3);
  
//   if(ia==NULL||ia->len<0){
//       return -1;
//   }
//   if(ia->data!=NULL&&ia->len>0){
//       strcat(st,itoa(ia->data[0]));
//   }
//   for(i=0;i<ia->len;i++){
//       strcat(st,", ");
//       strcat(st,itoa(ia->data[i]));
//   }
//   strcat(st," ]");
    
  
  
  
  
  return ia;
    
}

// int main(void){
//     intarr_t* ia=intarr_create(1);
//     //printf("%d\n",ia->len);
//     //ia->len=5;
//     ia->data[0]=10;
//     intarr_push(ia,5);
//     //printf("%d\n",ia->len);
//     intarr_save_json(ia,"1.txt");
//     intarr_t* aa= intarr_load_json("1.txt");
//     //printf("%d\n",aa->data[1]);
// }