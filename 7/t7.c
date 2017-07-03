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

list_t* list_create( void )
{
  
  char t[sizeof(list_t)];
  int i;
  for(i=0;i<sizeof(list_t);i++){
    t[i]='\0';
  }
  free(t);
  list_t* l = malloc( sizeof(list_t) );
  if( l )
    {
      l->head = NULL;
      l->tail = NULL;
    }
  return l;
}

void list_destroy( list_t* list )
{
  element_t* el = list->head;
  while( el )
    {
      element_t* next = el->next;
      free( el );
      el = next;
    }      
  
  // free( list );
  // char t[sizeof(list_t)];
  // int i;
  // for(i=0;i<sizeof(list_t);i++){
  //   t[i]='\0';
  // }
  // free(t);
}

element_t* element_create( int i )
{
  char t[sizeof(element_t)];
  int j;
  for(j=0;j<sizeof(list_t);j++){
    t[j]='\0';
  }
  free(t);
  element_t* el = malloc( sizeof(element_t) );
  el->val = i;
  //el->next==NULL;
  return el;
}

int list_append( list_t* list, int i )
{
  element_t* el = element_create( i );
  if( size(list)<0 )
    return 1;
  
  if( list->head == NULL )
    list->head = el;
  
  if( list->tail )
    list->tail->next = el;

  list->tail = el;
  return 0;
}

int list_prepend( list_t* list, int i )
{
  element_t* el = element_create( i );
  if( size(list)<0 )
    return 1;

  if( list->tail == NULL )
    list->tail = el;
  
  if( list->head )
    el->next = list->head;

  list->head = el;
  
  return 0;
}

element_t* list_index( list_t* list, unsigned int i )
{
  if( size(list)<=0 )
    return NULL;
  
  element_t* el = list->head;
  unsigned int now = 0;
  
  while( now < i )
    {
      if( el->next == NULL )
	return NULL;

      now++;
      el = el->next;
    }     
  
  return el;
}

void list_print( list_t* list )
{
  printf( "{" );
  
  if(size(list)>0){
    for( element_t* el = list->head;
       el!=NULL;
       el = el->next )
    printf( " %d", el->val );
  }
  
  

  printf( " }\n" );
}


