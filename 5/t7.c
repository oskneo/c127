#include "intarr.h"

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
  
  int *new,i;
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  if(newlen==ia->len){
    return INTARR_OK;
  }
  
  new=realloc(ia->data,newlen*sizeof(int));
  
  if(new==NULL){
    
    return INTARR_BADALLOC;
  }
  if(newlen<ia->len){
    ia->len=newlen;
    ia->data=new;
    return INTARR_OK;
  }
  
  
  // for(i=ia->len-1;i<newlen;i++){
  //   ia->data[i]=0;
  // }
  memset(ia->data, 0, newlen);

  
  
  ia->len=newlen;
  ia->data=new;
  
  return INTARR_OK;
  
}
