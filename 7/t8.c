#include <stdio.h>
#include <stdlib.h>

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

void list_sort( list_t* list ){
  element_t *el,*pre;
  int index=0,check=0;
  int sz=size(list);
  if(sz>1){
    el=list->head;
    
    do{
      index++;
      el=list->head;
      do{
        puts("stss");
        list_print(list);
        element_t *t=el->next;
        if(el->val>el->next->val){
          puts("suss");
          
          if(el==list->head){
            el->next=el->next->next;
            t->next=el;
            list->head=t;
            if(el->next==NULL){
              list->tail=el;
            }
            puts("svss");
          }
          
          else if(el->next==list->tail){
            puts("sss");
            pre->next=el->next;
            t->next=el;
            el->next=NULL;
            list->tail=el;
            puts("s2ss");
            list_print(list);
            //break;
            
          }else{
            pre->next=el->next;
            el->next=el->next->next;
            t->next=el;
            
          }
          //el=t;
          //free(t);
          check=1;
        }
        puts("3sss");
        if(check==1){
          pre=t;
          //el=el->next;
          //pre->next=el->next;
          //el=el->next;
        }
        else{
          pre=el;
          el=el->next;
        }
        
        //index++;
        puts("4sss");
    
      }while(el->next!=NULL);
    
    }while(index!=sz-1);
  }
  
  return;
  
}

// void list_print( list_t* list )
// {
//   printf( "{" );
  
//   if(size(list)>0){
//     for( element_t* el = list->head;
//       el!=NULL;
//       el = el->next )
//     printf( " %d", el->val );
//   }
  
  

//   printf( " }\n" );
// }


// int list_append( list_t* list, int i )
// {
//   element_t* el = element_create( i );
//   if( size(list)<0 )
//     return 1;
  
//   if( list->head == NULL )
//     list->head = el;
  
//   if( list->tail )
//     list->tail->next = el;

//   list->tail = el;
//   return 0;
// }

// list_t* list_create( void )
// {
  
//   char t[sizeof(list_t)];
//   int i;
//   for(i=0;i<sizeof(list_t);i++){
//     t[i]='\0';
//   }
//   //free(t);
//   list_t* l = malloc( sizeof(list_t) );
//   if( l )
//     {
//       l->head = NULL;
//       l->tail = NULL;
//     }
//   return l;
// }
// int main(void){
  
//   list_t* l=list_create();
//   list_append(l,9);
//   list_print(l);
//   puts("         ");
//   list_append(l,5);
//   list_print(l);
//   puts("         ");
//   list_append(l,6);
//   list_print(l);
//   puts("         ");
//   list_append(l,1);
//   list_print(l);
//   puts("         ");
//   list_sort(l);
//   list_print(l);
//   return 0;
// }