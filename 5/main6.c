#include <stdio.h>
#include "intarr.h"

void print_intarr(intarr_t* ia)
{
  if (ia != NULL ) 
  {
    printf("Printing intarr of length %d:\n", ia->len);
    for( unsigned i=0; i<ia->len; i++ )
      printf( "%d ", ia->data[i] );
    puts( "(end)" );
  }
  return;
}


int main( int argc, char* argv[] )
{
  printf("Creating test_ia\n"); 
  intarr_t* test_ia = intarr_create( 10 );
  if ( test_ia ==  NULL ) {
    printf("test_ia ==  NULL\n");
    return 1;
  } 

  printf("Populating test_ia\n");
  // Put data in the array
  for( unsigned i=0; i<test_ia->len; i++ )
    test_ia->data[i] = rand() % 100;
  printf("Printing test_ia\n"); 
  print_intarr( test_ia );
  
  
  
  intarr_resize(test_ia,11);
  //puts("hhhh");


  printf("Printing test_ia\n"); 
  print_intarr( test_ia );
  
  intarr_resize(test_ia,10);
  //puts("hhhh");
  intarr_push(test_ia,98);


  printf("Printing test_ia\n"); 
  print_intarr( test_ia );

  printf("Sort test_ia\n"); 
  intarr_sort( test_ia );

  printf("Printing test_ia\n"); 
  print_intarr( test_ia );

  printf("pop\n");  
  int i=0;
  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  printf("%d\n",i);
  print_intarr( test_ia );
  printf("pop\n");  
  intarr_pop( test_ia,&i );
  print_intarr( test_ia );
  printf("pop\n");  

  return 0;
}