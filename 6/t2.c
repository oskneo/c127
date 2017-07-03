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
    
  char st[2000];//=malloc(2000*sizeof(char));
  strcat(st,"[ ");
  char tk[10];
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
    
  FILE* file=fopen(filename,"w");
  if(!file){
      return -1;
  }
  if(!fwrite(st,sizeof(st),1,file)){
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
    return NULL;
  }
    
  char st[10000],*tk;
  int fs=0;
  intarr_t* ia=malloc(sizeof(intarr_t*));
  //char temp[10]="";
  //puts("ccccc");
  FILE* file=fopen(filename,"r");
  if(!file){
      return NULL;
  }
  //puts("aaaa");
  fseek(file, 0, SEEK_END); 
  fs = ftell(file); 
  fseek(file, 0, SEEK_SET); 
  if(!fread(st,sizeof(char),fs,file)){
      return NULL;
  }
  fclose(file);
  //puts("bbbb");
  //puts(st);
  
  tk=strtok(st,"[ ,]\0");
  //puts("ffff");
  while(tk!=NULL){
      //puts("ddddd");
      intarr_push(ia,atoi(tk));
      //printf("%d\n",ia->len);
      //puts("dde");
      tk=strtok(NULL,"[ ,]\0");
      //puts("ddfdd");
  }
  
  
  
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