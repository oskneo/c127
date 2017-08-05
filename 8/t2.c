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

  pa->len=0;
  pa->reserved=1;
  pa->points=realloc(NULL,sizeof(point_t));
  
  

  return;
   
   
}

/* TASK 2 */ 

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
   
   if(pa){
      free(pa->points);
      free(pa);
      point_array_init(pa);
   }
   
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){

  if(!pa||!p){
    return 1;
  }
  
  if(pa->reserved>0){
    pa->points[pa->len]=*p;
    pa->len++;
    pa->reserved--;

    
    
  }
  else{
    
    point_t *npt;
    npt=realloc(pa->points,(pa->len*2)*sizeof(point_t));
    if(!npt){
      return 1;
    }
    pa->reserved=pa->len-1;
    pa->len++;
    pa->points=npt;
    pa->points[pa->len-1]=*p;
  }
  

  return 0;
  
  

}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
   

  if(!pa||i>=(unsigned int)(pa->len)){
    return 1;
  }
  

  
  pa->points[i]=pa->points[pa->len-1];
  
  
  if(pa->reserved<pa->len){
    pa->len--;
    pa->reserved++;

  }
  else{
    point_t *npt;

    npt=realloc(pa->points,(pa->len+pa->len%2)*sizeof(point_t));

    if(!npt){
      return 1;
    }
    pa->reserved=pa->len%2+1;
    pa->len--;
    pa->points=npt;

  }

  return 0;
}



