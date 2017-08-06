#define _XOPEN_SOURCE 600

#include <stdio.h>
#include <stdlib.h>

#include "point_array.h"


/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
  pa->reserved=0;
  pa->len=0;
  pa->points=NULL;
  
  
  return;
   
   
}

/* TASK 2 */ 

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
   //puts("aa");
   if(pa){
      free(pa->points);
      //
      free(pa);
      
      point_array_init(pa);
   }
   
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
  

  point_t *npt;
  //unsigned int j;
  if(!pa||!p){
    return 1;
  }
  
  
  
  npt=realloc(pa->points,(pa->len+1)*sizeof(point_t));
  
  if(npt==NULL){
    return 1;
  }
  pa->points=npt;
  pa->points[ pa->len]=*p;
  //puts("bb");
  pa->len++;
  
  
  
  return 0;
  
  

}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
   
  point_t *npt;

  if(pa==NULL||i>=(unsigned int)(pa->len)){
    return 1;
  }
  

  
  pa->points[i]=pa->points[pa->len-1];
  
  npt=realloc(pa->points,(pa->len-1)*sizeof(point_t));
  if(npt==NULL&&pa->len-1>0){
    return 1;
  }
  pa->len--;
  pa->points=npt;

  return 0;
}



