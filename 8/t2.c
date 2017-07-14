#include <stdio.h>
//#include <stdlib.h>

#include "point_array.h"


/* ALL THESE FUNCTIONS REQUIRE A VALID POINT_ARRAY_T POINTER AS THEIR
   FIRST PARAMETER. THEY SHOULD FAIL ON ASSERTION IF THIS POINTER IS
   NULL */

/* TASK 1 */

// Safely initalize an empty array structure.
void point_array_init( point_array_t* pa ){
  point_t* ne=(point_t*)realloc(NULL,5*sizeof(point_t));
  if(pa==NULL||ne==NULL){
    return;
  }
  char *t=(char *)realloc(NULL,sizeof(point_t*));
  int i;
  for(i=0;i<sizeof(point_array_t);i++){
    t[i]='\0';
  }
  free(t);
  pa->points=ne;
  char *tu=(char *)realloc(NULL,sizeof(point_t*));
  int j;
  for(j=0;j<sizeof(point_t*);j++){
    tu[j]='\0';
  }
  free(tu);
  pa->points=realloc(NULL,sizeof(point_t*));
  pa->reserved=5;
  pa->len=0;
  
  return;
   
   
}

/* TASK 2 */

// Resets the array to be empty, freeing any memory allocated if
// necessary.
void point_array_reset( point_array_t* pa ){
   
   if(pa!=NULL){
      free(pa->points);
      free(pa);
      point_array_init(pa);
   }
   
}

/* TASK 3 */

// Append a point to the end of an array. If successful, return 0,
// else return 1;
int point_array_append( point_array_t* pa, point_t* p ){
   
  point_t *ne=realloc(NULL,(pa->len*2)*sizeof(point_t));
  if(pa==NULL||p==NULL||ne||NULL){
    return 1;
  }
  if(pa->reserved-pa->len==0){
    pa->points=ne;
    pa->reserved=pa->len*2;
  }
  
  pa->len++;
  pa->points[pa->len-1]=*p;
  return 0;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
   //puts("haaaaa");
  point_t *ne;
  unsigned int j;
  //puts("gaaaaa");
  if(pa==NULL||i>=(unsigned int)(pa->len)){
    return 1;
  }
  //puts("eaaaaa");
  if(i<(unsigned int)(pa->len)-1){
      
      for(j=i;j<pa->len-1;j++){
        pa->points[j]=pa->points[j+1];
      }
      //memcpy(&(pa->points[i]),&(pa->points[i+1]),sizeof(point_t)*((unsigned int)(pa->len)-i));
  }
  if(pa->reserved/pa->len>=2){
    ne=realloc(&(pa->points[0]),(pa->len-1)*sizeof(point_t));
  }
  //puts("faaaaa");
  
  if(ne==NULL){
    return 1;
  }
  pa->len--;
  pa->points=ne;
  //pa->points[pa->len-1]=p;
  return 0;
}




