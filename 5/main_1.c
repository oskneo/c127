#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h> 
#include <math.h>
#include <assert.h> 

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

  printf("Sort test_ia\n"); 
  intarr_sort( test_ia );

  printf("Printing test_ia\n"); 
  print_intarr( test_ia );

  printf("Destroying test_ia\n");  
  intarr_destroy( test_ia );

  return 0;
}