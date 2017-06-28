#include "intarr.h"
/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ){
  int *new;
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  new=realloc(ia->data,(ia->len+1)*sizeof(int));
  if(new==NULL){
    return INTARR_BADALLOC;
  }
  ia->len++;
  ia->data=new;
  ia->data[ia->len-1]=val;
  return INTARR_OK;
}
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){
  
  
  int *new,l,j=-999999,k=0;
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  if(ia->len<=0){
    return INTARR_BADINDEX;
  }
  for(l=0;l<ia->len;l++){
    if(ia->data[l]>j){
      j=ia->data[l];
      k=l;
    }
  }
  if(i!=NULL){
    *i=ia->data[k];
  }
  for(l=k;l<ia->len-1;l++){
    ia->data[l]=ia->data[l+1];
  }
  new=realloc(ia->data,(ia->len-1)*sizeof(int));
  
  if(new==NULL&&ia->len!=1){
    return INTARR_BADALLOC;
  }
  
  ia->len--;
  ia->data=new;
  
  return INTARR_OK;
  
}
