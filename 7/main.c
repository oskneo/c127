#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int isempty(list_t *list){
  if(list==NULL){
    return -1;
  }
  else if(list->tail==NULL&&list->head==NULL){
    return 1;
  }
  else if(list->head==NULL||list->tail==NULL){
    return -1;
  }
  else{
    return 0;
  }
}

int size(list_t *list){
  int index=0;
  element_t* el;
  int ern;
  ern=isempty(list);
  if(ern==1){
    
    return 0;
  }
  else if(ern==-1){
    return -1;
  }
  el=list->head;
  index++;
  while(el->next!=NULL){
    index++;
    el=el->next;
    
  }
  if(el!=list->tail){
    return -1;
  }
  //index++;
  return index;
  
}

int checkappend(list_t *list,int i){
  //puts("aaaaa0"); 
  int sz=size(list);
  //puts("aaaaa1"); 
  element_t *ls;
  if(sz<0){
    return 1;
  }
  //printf("%d\n",sz);
  ls=list->tail;
  list_append( list, i );
  //printf("%d\n",size(list));
  //puts("aaaaa2"); 
  if(sz!=size(list)-1||list->head==NULL||list->tail==NULL||list->tail->val!=i){
    return 1;
  }
  if(sz>0){
    if(ls->next==NULL||ls->next->val!=i||ls->next!=list->tail){
      return 1;
    }
  }else{
    if(list->head->val!=i||list->head->next!=NULL||list->tail->next!=NULL){
      return 1;
    }
  }
  
  //puts("aaaaa3"); 
  return 0;
}

int checkprepend(list_t *list,int i){
  int sz=size(list);
  element_t *ls;
  if(sz<0){
    return 1;
  }
  ls=list->head;
  list_prepend( list, i );
  if(sz!=size(list)-1){
    return 1;
  }
  if(list->head==NULL||list->tail==NULL||list->head->val!=i){
    return 1;
  }
  if(sz>0){
    if(list->head==ls||list->head->next!=ls){
      return 1;
    }
  }
  else{
    if(list->head!=ls||list->head->next!=NULL){
      return 1;
    }
  }
  return 0;
}
int checkcreate(list_t *list){
  if(list->head!=NULL||list->tail!=NULL){
    return 1;
  }
  else{
    return 0;
  }
  
}

int checkindex(list_t *list,unsigned int i,element_t *el2){
  
  int sz=size(list);
  unsigned int index=0;
  element_t *el;
  if(sz<0){
    return 1;
  }
  el=list->head;
  if(index==i){
    if(el==el2){
      return 0;
    }
    else{
      return 1;
    }
    
  }
  
  
  while(el->next!=NULL){
    index++;
    el=el->next;
    if(index==i){
      if(el==el2){
        return 0;
      }
      else{
        return 1;
      }
    
    }
    
  }
  return 0;
  
}


int main( int argc, char* argv[] )
{
  list_t* list = list_create();
  if(checkcreate(list)==1){
    return 1;
  }
  //puts("0aaaaa"); 

  for( int i=0; i<5; i++ )
  {
    if(checkappend(list,i)==1){
      return 1;
    }
  }
  //puts("aaaaa");  
  
  for( int i=-1; i>-5; i-- )
  {
    if(checkprepend(list,i)==1){
      return 1;
    }
  }
  list_print( list );

  int index = 2;
  element_t* el = list_index( list, index );
  if(checkindex(list,index,el)==1){
    return 1;
  }
  if( el == NULL )
    {
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  
  printf( "value at index %d is %d\n", index, el->val );
  
  if( el->val != -2 ) 
  {
    puts("The val of el is not -2");
    return 1;
  }
    
  
  list_destroy( list );

  return 0; // tests pass
}
