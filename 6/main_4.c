#include <stdint.h> // for uint8_t
#include <stdlib.h> // for malloc()
#include <string.h> // for memset()
#include <stdio.h> 
#include <math.h>
#include <assert.h> 

#include "intarr.h"
//#include "t1.c"

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

  const char* filename = "JSON_Test.txt";
  printf("Creating test_ia\n"); 
  intarr_t* test_ia = intarr_create( 12 );
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

  printf("Saving test_ia into JSON file %s\n", filename); 
  if ( intarr_save_json( test_ia, filename ) != 0 )
  	printf("Saving test_ia into JSON file failed!\n"); 
  
  
  printf("Destroying test_ia\n");  
  intarr_destroy( test_ia );
  printf("loading test_ia from JSON file %s\n", filename); 
  intarr_t* test_ia2 = intarr_load_json("JSON_Test.txt");
  printf("Printing test_ia\n"); 
  print_intarr( test_ia2 );
  printf("Destroying test_ia\n");  
  intarr_destroy( test_ia2 );

  return 0;
}