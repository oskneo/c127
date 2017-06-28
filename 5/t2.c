#include "intarr.h"
/* LAB 5 TASK 2 */

// If index is valid, set the value at ia->data[index] to val and return
// INTARR_OK. Otherwise, leave the array unmodified and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_set( intarr_t* ia, 
			    unsigned int index, 
			    int val )
{
  //int le=-1;
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  if(index<ia->len&&index>=0){
    ia->data[index]=val;
    return INTARR_OK;
  }
  else{
    return INTARR_BADINDEX;
  }
}

// If index is valid and i is non-null, set *i to ia->data[index] and return
// INTARR_OK. Otherwise no not modify *i and return
// INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_get( const intarr_t* ia, 
			    unsigned int index, 
			    int* i )
{
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  if(index<ia->len&&index>=0){
    *i=ia->data[index];
    return INTARR_OK;
  }
  else{
    return INTARR_BADINDEX;
  }
}
