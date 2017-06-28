#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.

intarr_t* intarr_create( unsigned int len ){
  intarr_t* a=malloc(sizeof(intarr_t*));
  if(a!=NULL){
    a->len=len;
    a->data=malloc(len*sizeof(int));
    
  }
  return a;
  
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
  if (ia!=NULL){
    free(ia);
  }
}