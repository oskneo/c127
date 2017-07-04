#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "vec.h"


/* TASK 1 */

// Find the first element of the vector v and set the deferenced
// pointer result to the first element of v. Return 0 on success.
// If v is NULL or v->dim is zero or v->data is NULL then return -1.
// Do not modify *result on failure.
int vec_first( vec_t *v, double* result ){
  if(v==NULL||v->dim==0||v->data==NULL){
    return -1;
  }
  *result=v->data[0];
  return 0;
}

/* TASK 2 */

// Find the last element of the vector v and set the deferenced
// pointer result to the last element of v. Return 0 on success.
// If v is NULL or v->dim is zero or v->data is NULL then return -1.
// Do not modify *result on failure.
int vec_last( vec_t *v, double* result ){
  if(v==NULL||v->dim==0||v->data==NULL){
    return -1;
  }
  *result=v->data[v->dim-1];

  return 0;
}

/* TASK 3 */

// Return the maximum value in the vector.
// If finding the maximum was successful, dereference the pointer
// result and place the max value in that location. Return 0 on success.
// If finding the maximum failed, because the vector v was
// NULL or v->dim is zero or v->data was NULL then return -1 on failure.
// Do not modify *result in this case.
int vec_max( vec_t *v, double* result ){
  if(v==NULL||v->dim==0||v->data==NULL){
    return -1;
  }
  double rs=-9999;
  unsigned int i=0;
  for(;i<v->dim;i++){
    if(v->data[i]>rs){
      rs=v->data[i];
    }
  }
  *result=rs;

  return 0;
}

/* TASK 4 */

// Return the minimum value in the vector.
// If finding the minimum was successful, dereference the pointer
// result and place the min value in that location. Return 0 on success.
// If finding the minimum failed, because the vector v was
// NULL or v->dim is zero or v->data was NULL then return -1 on failure.
// Do not modify *result in this case.
int vec_min( vec_t *v, double* result ){
  if(v==NULL||v->dim==0||v->data==NULL){
    return -1;
  }
  double rs=9999;
  unsigned int i=0;
  for(;i<v->dim;i++){
    if(v->data[i]<rs){
      rs=v->data[i];
    }
  }
  *result=rs;

  return 0;
}

/* TASK 5 */

// Return the sum of all elements in vector v.
// If sum was successful, dereference the pointer result and
// place the sum value in that location. Return 0 on success.
// If calculating the sum was unsuccessful, because vector v
// was NULL or v->dim was zero or v->data was NULL then return
// -1 on failure. Do not modify *result in this case.
int vec_sum( vec_t *v, double* result ){
  if(v==NULL||v->dim==0||v->data==NULL){
    return -1;
  }
  double rs=0;
  unsigned int i=0;
  for(;i<v->dim;i++){
    rs+=v->data[i];
  }
  *result=rs;

  return 0;
}

/* TASK 6 */

// Return the dot product of two vectors which is defined as the
// sum of the product of the corresponding elements of each vector.
// For example, if v1 = [0.3,0.2] and v2 = [0.5,0.4] then vec_dotprod
// will return 0.23 = (.3*.5) + (.2*.4)
// If the dot product was successful, dereference the pointer
// result and place the result in that location. Return 0 on success.
// If the dot product was unsuccessful return -1.
// The two vectors must have the same dimension. If they do not
// then the dot product will be unsuccessful. If either vector
// is NULL or the data location for either vector is NULL then
// the dot product will be unsuccessful.
int vec_dotprod( vec_t *v1, vec_t *v2, double *result ){
  if(v1==NULL||v2==NULL||v1->dim==0||v2->dim==0||v1->data==NULL||v2->data==NULL||v1->dim!=v2->dim){
    return -1;
  }
  double rs=0;
  unsigned int i=0;
  for(;i<v1->dim;i++){
    rs+=v1->data[i]*v2->data[i];
  }
  *result=rs;

  return 0;
}
