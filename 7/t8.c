#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Implements a linked list of integers

 A list is comprised of a single header and zero or more elements. The
 header contains pointers to the first and last elements in the list,
 or NULL if the list is empty. The first element contains a pointer to
 the next element, and so on. The last element in the list has its
 "next" pointer set to NULL.

 ** Global Precondition **

 Functions that operate on an existing list require a valid pointer to
 a list_t header as their first argument.
*/

#include "list.h"




// element_t* element_create( int i )
// {
//   char t[sizeof(element_t)];
//   int j;
//   for(j=0;j<sizeof(list_t);j++){
//     t[j]='\0';
//   }
//   //free(t);
//   element_t* el = malloc( sizeof(element_t) );
//   el->val = i;
//   //el->next==NULL;
//   return el;
// }


void list_sort( list_t* list ){
  
  
  
  
  
  
  element_t *el;//,*el2,*pre;
  //int check=0;
  //int sz=size(list);
  list_t **lt=malloc(sizeof(list_t*)*19);
  int i;
  
  el=list->head;
  
  if(el){
    int count,dg=0;
    do{
      count=0;
      //printf("5:%d\n",count);
      for(i=0;i<19;i++){
        lt[i]=list_create();
      }
      do{
        int j=((el->val/(int)pow(10,dg))%10)+9;
        if(count==0){
          if(el->val/(int)pow(10,dg+1)!=0){
            count=1;
          }
        }
        //printf("1:%d\n",j);
        element_t *el3;//,*el4;
        if(el->next){
          list->head=list->head->next;
      
        }
        if(lt[j]->tail){
          lt[j]->tail->next=el;
          lt[j]->tail=lt[j]->tail->next;
        }
        else{
          lt[j]->tail=el;
          lt[j]->head=el;
        }
        el3=el->next;
        lt[j]->tail->next=NULL;
        //list_append(&(lt[j]),el->val);
        //printf("1:%d\n",el->next->val);
        //printf("2:%d\n",lt[j]->tail->val);
        el=el3;
        //printf("3:%d\n",el->val);
      }
      while(el);
      
      
      //printf("%d\n",list->head->next->val);
      list_t *list2=list_create();
    
      for(i=0;i<19;i++){
        if(lt[i]->head){
          //printf("++%d\n",i);
          if(list2->tail){
            //printf("%d\n",(-4%10));
            list2->tail->next=lt[i]->head;
            list2->tail=lt[i]->tail;
          }
          else{
            //printf("%d\n",lt[i]->head->val);
            list2->head=lt[i]->head;
            list2->tail=lt[i]->tail;
          }
        
        }
      }
      //printf("4:%d\n",list2->head->next->val);
      *list=*list2;
      
      
      el=list->head;
      
      dg++;
      //printf("6:%d\n",count);
      
      
    }
    while(count!=0);
    
    
    
    
  }
  
  
  
}  