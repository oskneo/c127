#include "intarr.h"
/* LAB 5 TASK 8 */

// Get a deep copy of a portion of ia from index first to index last
// inclusive. If successful, return a pointer to a newly-allocated
// intarr_t containing a copy of the specfied section. If an error
// occurs, i.e. ia is null, first or last are out of bounds, last <
// first, or memory allocation fails, return a null pointer.
intarr_t* intarr_copy_subarray( intarr_t* ia, 
				unsigned int first, 
				unsigned int last )
{
  intarr_t* a;
  
  if(ia==NULL||last<first||last<0||last>=ia->len||first<0||first>=ia->len){
    return a;
  }
  a=malloc(sizeof(intarr_t*));
  if(a==NULL){
    return a;
  }
  memcpy( a->data, &(ia->data[first]), sizeof(int)*(last-first+1) );
  a->len=last-first+1;
  return a;

  
  
}
