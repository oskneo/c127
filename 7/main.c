
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>
#include <string.h>



#include "list.h"



int checkappend(list_t *list,int i){
  

  list_append( list, i );
  //printf("%d\n",size(list));
  //puts("aaaaa2"); 
  
  
  
  //puts("aaaaa3"); 
  return 0;
}

int checkprepend(list_t *list,int i){
  
  
  list_t *lt=list_create();
  list_prepend(lt,0);
  if(lt->tail==NULL){
    return 1;
  }
  
  
  
  
  
  // int sz=size(list);
  element_t *ls;
  // if(sz<0){
  //   return 1;
  // }
  ls=list->head;
  list_prepend( list, i );
  // if(sz!=size(list)-1){
  //   return 1;
  // }
  if(list->head==NULL||list->tail==NULL||list->head->val!=i){
    return 1;
  }
  // if(sz>0){
    if(list->head==ls||list->head->next!=ls){
      return 1;
    }
  // }
  // else{
  //   if(list->head!=ls||list->head->next!=NULL){
  //     return 1;
  //   }
  // }
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








jmp_buf rsp;
void Handler(int sig)
{
    if (sig == SIGSEGV)
    {
        //printf("received SegFault\n");
        signal(SIGSEGV, &Handler);
        longjmp(rsp, SIGSEGV);
    }
}


int chElCre(){
  
  //puts("kkkkk");
  list_t *lt=list_create();
  list_append(lt,0);
  list_append(lt,1);
  free(lt->head);
  lt->head=element_create(0);
  if(lt->head->next==NULL){
    return 0;
  }
  else{
    return 1;
  }
  //element_t *el=element_create(5);
 
  //puts("ddd");
  //int *ee=malloc(sizeof(int)*2);
  //free(el);
  //free(ee);
  //puts("kkkkk");
}

void testindex(){
        list_t *l1=list_create();
        l1->head=NULL;
        l1->tail=element_create(5);
        list_index(l1,1);
}
int test(void f())
{
    int fc = setjmp(rsp);
    if (fc==0)
    {
        
        f();
        
        return 1;
    }
    return 2;
}




void testindex2(){
        list_t *l1=list_create();
        list_append(l1,5);
        //l1->head=NULL;
        //l1->tail=element_create(5);
        list_index(l1,2);
}



int checkindex(list_t *list,unsigned int i,element_t **el1){
  

  
  if(test(testindex)==2){
    return 1;
  }
  
  
  
  if(test(testindex2)==2){
    return 1;
  }
  
  
  
  
  
  
  
  
  
  

  unsigned int index=0;
  element_t *el,*el2=NULL;
  if(list->head!=NULL){
    el2= list_index( list, i );
    *el1=el2;
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
  element_t* el=list_index(list,index) ;
  signal(SIGSEGV,Handler);
  if(chElCre()==1){
    return 1;
  }
  if(checkindex(list,index,&el)==1){
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
