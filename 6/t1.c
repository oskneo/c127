#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intarr.h"


/* -------------------------------------------------------------- */

/* LAB 6 TASK 1 */

/*
  Save the entire array ia into a file called 'filename' in a binary
  file format that can be loaded by intarr_load_binary(). Returns
  zero on success, or a non-zero error code on failure. Arrays of
  length 0 should produce an output file containing an empty array.
*/
int intarr_save_binary( intarr_t* ia, const char* filename ){
  
  if(ia==NULL){
    return -4;
    //ia=intarr_create(0);
  }
  if(filename==NULL){
    return -5;
  }
  
  FILE* file=fopen(filename,"w");
  if(!file){
      return -1;
  }
  if(!fwrite(ia,sizeof(intarr_t),1,file)){
      return -2;
  }
  fclose(file);
  
  
  
  return 0;
}
/*
  Load a new array from the file called 'filename', that was
  previously saved using intarr_save_binary(). Returns a pointer to a
  newly-allocated intarr_t on success, or NULL on failure.
*/
intarr_t* intarr_load_binary( const char* filename ){
  if(filename==NULL){
    return NULL;
  }
  intarr_t *ia;
  ia=malloc(sizeof(intarr_t*));
  if(!ia){
      return NULL;
  }
  FILE* file=fopen(filename,"r");
  if(!file){
      return NULL;
  }
  if(!fread(ia,sizeof(intarr_t),1,file)){
      return NULL;
  }
  fclose(file);
  
  
  
  return ia;
    
}


