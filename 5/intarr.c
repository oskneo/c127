#include "stdio.h"
#include "intarr.h"

/* LAB 5 TASK 1 */

// Create a new intarr_t with initial size len.  If successful
// (i.e. memory allocation succeeds), returns a pointer to a
// newly-allocated intarr_t.  If unsuccessful, returns a null pointer.

intarr_t* intarr_create( unsigned int len ){
  intarr_t* a=malloc(sizeof(intarr_t));
  // if(a!=NULL){
  //   a->len=len;
  //   a->data=malloc(len*sizeof(int));
    
  // }
  
  
  
  a->data=malloc(len*sizeof(int));
  if(a->data==NULL){
    return NULL;
  }
  a->len=len;
  return a;
  
}

// frees all memory allocated for ia. If the pointer is null, do
// nothing. If the ia->data is null, do not attempt to free it.
void intarr_destroy( intarr_t* ia ){
  if (ia!=NULL){
    free(ia);
  }
}


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

/* LAB 5 TASK 3 */

// Return a duplicate of ia, allocating new storage for the duplicate
// data (we call this a "deep copy"). If unsuccessful (i.e. memory
// allocation for the copy fails, or ia is null), return a null pointer. 
intarr_t* intarr_copy( const intarr_t* ia ){
  intarr_t* a;
  if(ia==NULL){
    return NULL;
  }
  a=malloc(sizeof(intarr_t ));
  if(a==NULL){
    return a;
  }
  a->data=malloc(sizeof(int)*ia->len);
  a->len=ia->len;
  memcpy( a->data, ia->data, sizeof(int)*ia->len );
  return a;
}

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


/* LAB 5 TASK 5 */

// Find the first occurance of the target in the array, searching from
// index 0. If the target is found and i is non-null, set *i to the
// location index and return INTARR_OK. If target does not occur in
// the array, leave *i unmodified and return INTARR_NOTFOUND. If ia is
// null, return INTARR_BADARRAY.
intarr_result_t intarr_find( intarr_t* ia, int target, int* i ){
  
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  int j;
  for(j=0;j<ia->len;j++){
    if(ia->data[j]==target&&i!=NULL){
      *i=j;
      return INTARR_OK;
    }
  }
  
  return INTARR_NOTFOUND;
  
  
}

/* LAB 5 TASK 6 */

// Append val to the end of ia (allocating space for it). If
// successful, return INTARR_OK, otherwise return
// INTARR_BADALLOC. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_push( intarr_t* ia, int val ){
  //int *new;
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  //new=realloc(ia->data,(ia->len+1)*sizeof(int));
  int i,i2=0;
  // for(i=0;i<ia->len;i++){
  //   if(ia->data[i]=='\0'){
  //     ia->data[i]=val;
  //     break;
  //   }
  //   else if(i==ia->len-1){
  //     if(intarr_resize(ia,ia->len*2)!=INTARR_OK){
  //       return INTARR_BADALLOC;
  //     }
  //     else{
  //       ia->data[i+1]=val;
  //     }
      
  //   }
  // }
  
  
  for(i=0;i<ia->len;i++){
      if(ia->data[i]!='\0'){
        i2=i;
        
        // *i=ia->data[ii-1];
        // ia->data[ii-1]='\0';
        // break;
      }
      // else if(ia->data[ii]=='\0'&&ii==0){
      //   return INTARR_BADINDEX;
      // }
      // else if(ii==ia->len-1){
      //   *i=ia->data[ii];
        

      //   ia->data[ii]='\0';
        
      // }
    }
    if(i2==ia->len-1){
      if(intarr_resize(ia,ia->len+1)!=INTARR_OK){
        return INTARR_BADALLOC;
      }
      else{
        ia->data[i2+1]=val;
      }
    }
    else{
      ia->data[i2+1]=val;
    }
  
  // if(new==NULL){
  //   return INTARR_BADALLOC;
  // }
  //ia->len++;
  //ia->data=new;
  //ia->data[ia->len-1]=val;
  return INTARR_OK;
}
// If the array is not empty, remove the value with the highest index
// from the array, and, if i is non-null, set *i to the removed value,
// then return INTARR_OK. If the array is empty, leave *i unmodified
// and return INTARR_BADINDEX. If ia is null, return INTARR_BADARRAY.
intarr_result_t intarr_pop( intarr_t* ia, int* i ){
  
  
  //int *newia/*,l,j=-999999*/;
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  if(ia->len<=0){
    return INTARR_BADINDEX;
  }
  // for(l=0;l<ia->len;l++){
  //   if(ia->data[l]>j){
  //     j=ia->data[l];
  //     k=l;
  //   }
  // }
  if(i!=NULL){
    //*i=ia->data[ia->len-1];
    int i2=0;
    int ii;
    for(ii=0;ii<ia->len;ii++){
      if(ia->data[ii]!='\0'){
        i2=ii;
        
        // *i=ia->data[ii-1];
        // ia->data[ii-1]='\0';
        // break;
      }
      // else if(ia->data[ii]=='\0'&&ii==0){
      //   return INTARR_BADINDEX;
      // }
      // else if(ii==ia->len-1){
      //   *i=ia->data[ii];
        

      //   ia->data[ii]='\0';
        
      // }
    }
    if(i2==0){
      return INTARR_BADINDEX;
    }
    else{
      *i=ia->data[i2];
        

      ia->data[i2]='\0';
    }
    
  }
  // for(l=k;l<ia->len-1;l++){
  //   ia->data[l]=ia->data[l+1];
  // }
  //newia=realloc(ia->data,(ia->len-1)*sizeof(int));
  
  // if(new==NULL){
  //   return INTARR_BADALLOC;
  // }
  
  //ia->len--;
  //ia->data=newia;
  
  return INTARR_OK;
  
}

/* LAB 5 TASK 7 */

// Resize ia to contain newlen values. If newlen is less than the
// original array length, the end of the array is discarded. If newlen
// is greater than the original array length, intialize all the new
// integers to zero. If the allocation is successful, return
// INTARR_OK, otherwise return INTARR_BADALLOC. If ia is null, return
// INTARR_BADARRAY.
intarr_result_t intarr_resize( intarr_t* ia, unsigned int newlen ){
  
  //int *newia,i;
  if(ia==NULL){
    return INTARR_BADARRAY;
  }
  if(newlen==ia->len){
    return INTARR_OK;
  }
  
  
  
  
  
  
  
  intarr_t *newia=intarr_create(newlen);
  if(newia==NULL){
    return INTARR_BADALLOC;
  }
  unsigned int i;
  if(ia->len<newlen){
    for(i=0;i<newlen;i++){
      if(i<ia->len){
        newia->data[i]=ia->data[i];
      }
      else{
        newia->data[i]=0;
      }
    }
  }
  else{
    for(i=0;i<newlen;i++){
      newia->data[i]=ia->data[i];
    }
  }
  newia->len=newlen;
  
  *ia=*newia;
  //free(ia);
  //printf("%u\n",ia->len);
  
  // newia=realloc(ia->data,newlen*sizeof(int));
  
  // if(newia==NULL&&newlen!=0){
    
  //   return INTARR_BADALLOC;
  // }
  // if(newlen<ia->len){
  //   ia->len=newlen;
  //   ia->data=newia;
  //   return INTARR_OK;
  // }
  
  
  // for(i=ia->len;i<newlen;i++){
  //   ia->data[i]=0;
  // }

  
  
  // ia->len=newlen;
  // ia->data=newia;
  
  return INTARR_OK;
  
}

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
    return NULL;
  }
  a=malloc(sizeof(intarr_t));
  if(a==NULL){
    return NULL;
  }
  a->data=malloc((last-first+1)*sizeof(int));
  if(a->data==NULL){
    return NULL;
  }
  memcpy( a->data, &(ia->data[first]), sizeof(int)*(last-first+1) );
  
  a->len=last-first+1;
  return a;

  
  
}
