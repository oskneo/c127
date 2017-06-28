#include "intarr.h"
/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
  
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  int j;
  for(j=0;j<ia->len;j++){
    if(ia->data[j]==target&&i!=NULL){
      *i=j;
      return INTARR_OK;
    }
  }
  
  return INTARR_NOTFOUND;
  
  
}
