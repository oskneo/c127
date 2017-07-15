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
  //char *t=(char *)realloc(NULL,sizeof(point_t*));
  // int i;
  // for(i=0;i<sizeof(point_array_t);i++){
  //   t[i]='\0';
  // }
  // free(t);
  //pa=realloc(NULL,sizeof(point_array_t));
  // char *tu=(char *)realloc(NULL,sizeof(point_t*));
  // int j;
  // for(j=0;j<sizeof(point_t*);j++){
  //   tu[j]='\0';
  // }
  // free(tu);
  pa->points=realloc(NULL,1*sizeof(point_t));
  pa->reserved=1;
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
  // point_t *new;
  // if(pa==NULL||p==NULL){
  //   return 1;
  // }
   
  
  // new=realloc(pa->points,(pa->len+2)*sizeof(pa->points[0]));
  // if(new==NULL){
  //   return 1;
  // }
  // pa->points=new;
  // pa->points[pa->len]=*p;
  // pa->len++;
  // return 0;
  
  //point_t *new;

  
  
  //unsigned int j;
  if(pa==NULL||p==NULL){
    return 1;
  }
  
  if(pa->reserved!=0){
    pa->len++;
    pa->reserved--;
    pa->points[pa->len-1]=*p;
  }
  else{
    point_t *new;
    new=realloc(pa->points,(pa->len*2)*sizeof(point_t));
    if(new==NULL){
      return 1;
    }
    pa->reserved=pa->len-1;
    pa->len++;
    pa->points=new;
    pa->points[pa->len-1]=*p;
  }
  
  
  //pa->points[pa->len-1]=p;
  return 0;
  
  
  // if(pa==NULL||p==NULL){
  //   return 1;
  // }
  // pa=realloc(pa,sizeof(point_array_t*));
  // //new=realloc(pa->points,(pa->len+1)*sizeof(point_t));
  // if(new==NULL){
  //   return 1;
  // }
  // pa->len++;
  // pa->points=new;
  // pa->points[pa->len-1]=*p;
  //return 0;
}

/* TASK 4 */

// Remove the point at index i from the array, reducing the size of
// the array by one. The order of points in the array may change.
int point_array_remove( point_array_t* pa, unsigned int i ){
   
  //point_t *new;
  //unsigned int j;
  if(pa==NULL||i>=(unsigned int)(pa->len)){
    return 1;
  }
  
  // if(i<(unsigned int)(pa->len)-1){
      
  //     for(j=i;j<pa->len-1;j++){
  //       pa->points[j]=pa->points[j+1];
  //     }
  //     //memcpy(&(pa->points[i]),&(pa->points[i+1]),sizeof(point_t)*((unsigned int)(pa->len)-i));
  // }
  
  pa->points[i]=pa->points[pa->len-1];
  
  
  if(pa->reserved<pa->len){
    pa->len--;
    pa->reserved++;
    //pa->points[pa->len-1]=*p;
  }
  else{
    point_t *new;
    new=realloc(pa->points,(pa->len/2+pa->len%2)*sizeof(point_t));
    if(new==NULL){
      return 1;
    }
    pa->reserved=pa->len%2;
    pa->len--;
    pa->points=new;
    
    //pa->points[pa->len-1]=*p;
  }
  
  
  // new=realloc(&(pa->points[0]),(pa->len-1)*sizeof(point_t));
  // if(new==NULL){
  //   return 1;
  // }
  // pa->len--;
  // pa->points=new;
  //pa->points[pa->len-1]=p;
  return 0;
}



