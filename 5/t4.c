#include "intarr.h"
/* LAB 5 TASK 4 */

// sort ia by value smallest-to-largest, so that data[i] < data[i+1]
// for all valid i, then return INTARR_OK. Works in-place: contents of
// ia are sorted on return. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_sort( intarr_t* ia ){
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  int i,j;
  for(i=0;i<ia->len;i++){
    for(j=1;j<ia->len;j++){
      if(ia->data[j-1]>ia->data[j]){
        int temp=ia->data[j-1];
        ia->data[j-1]=ia->data[j];
        ia->data[j]=temp;
      }
    }
  }
  
  
  return INTARR_OK;
}

