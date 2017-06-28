#include "intarr.h"
/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia ){
  intarr_t* a;
  if(ia==NULL){
    return a;
  }
  a=malloc(sizeof(intarr_t *));
  if(a==NULL){
    return a;
  }
  memcpy( a, ia, sizeof(intarr_t *) );
  return a;
}
