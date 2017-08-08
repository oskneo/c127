/*
 * imageops.c - Simple operations on images
 *
 * C laboratory exercises.
 * Richard Vaughan, 2014.
 */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/* PAIR SECTION BEGINS - WORK WITH YOUR PARTNER ON THESE TASKS */
/*-------------------------------------------------
  PART 0: DEMONSTRATION
*/
// get the value in the array at coordinate (x,y)
uint8_t get_pixel( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows,
           unsigned int x,
           unsigned int y )
{
    assert( x < cols );
    assert( y < rows );
    return array[ y*cols + x ];
}
// set the pixel at coordinate {x,y} to the specified color
void set_pixel( uint8_t array[], 
        unsigned int cols, 
        unsigned int rows,
        unsigned int x,
        unsigned int y,
        uint8_t color )
{
    assert( x < cols );
    assert( y < rows );
    array[ y * cols + x ] = color;
} 
// Set every pixel to 0 (black) 
void zero( uint8_t array[],
	   unsigned int cols,
	   unsigned int rows )
{
  // your code here.
  int i=0;
  for (;i<cols*rows;i++){
      array[i] = 0;
  }
}
// Returns a pointer to a freshly allocated array that contains the
// same values as the original array, or a null pointer if the
// allocation fails. The caller is responsible for freeing the array
// later.
uint8_t* copy( const uint8_t array[], 
           unsigned int cols, 
           unsigned int rows )
{
  // your code here
  uint8_t *ar=realloc(NULL,cols*rows*sizeof(uint8_t));
  if(ar){
      memcpy(ar,array,cols*rows*sizeof(uint8_t));
  }
  
  return ar;
}
/*-------------------------------------------------
  PART 1: OPERATIONS ON THE WHOLE IMAGE 
*/
/* TASK 1 - three easy functions to get started */
// Return the darkest color that appears in the array; i.e. the
// smallest value
uint8_t min( const uint8_t array[], 
	     unsigned int cols, 
	     unsigned int rows )
{
  // your code here
  unsigned int x=0;
  //
  uint8_t ys=255;
  //
  for( ;x<cols*rows;x++){
      if( array[x]<ys){
          //
          ys=array[x];
      }
  }
  
  return ys;
}
// Return the lightest color that appears in the array; i.e. the
// largest value
uint8_t max( const uint8_t array[], 
		 unsigned int cols, 
		 unsigned int rows )
{
  // your code here
  unsigned int x=0;
  //
  uint8_t ys=0;
  //
  for( ;x<cols*rows;x++){
      //
      if(array[x]>ys){
          //
          ys=array[x];
      }
  }
  
  return ys;
}
// TASK 2
//  Replace every instance of pre_color with post_color.
void replace_color(  uint8_t array[], 
		     unsigned int cols, 
		     unsigned int rows,
		     uint8_t pre_color,
		     uint8_t post_color )
{
  // your code here
  unsigned int x=0;
  for( ;x<cols* rows;x++){
      if ( array[x]==pre_color){
          //
          array[x]= post_color;
      }
  }
}
/* TASK 3  - two functions */
// flip the image, left-to-right, like in a mirror.
void flip_horizontal( uint8_t array[], 
              unsigned int cols, 
              unsigned int rows )
{
  // your code here
  unsigned int x=0,y=0;
  for(;x< cols/2;x++){
      //
    for(;y< rows;y++){
        //
      
      //
      array[y*cols+x]=array[ y*cols+(cols-x-1)];
      //
      array[y* cols+(cols-x-1)]=get_pixel(array,cols,rows,x,y);
    }
    y=0;
  }
  
}
// flip the image top-to-bottom.
void flip_vertical( uint8_t array[], 
            unsigned int cols, 
            unsigned int rows )
{
    // your code here
  unsigned int x=0,y=0;
  //
  for(;x< cols;x++){
      //
    for(;y< rows/2;y++){
        //
      //
      array[y*cols+x]=array[( rows-y-1)*cols+x];
      //
      array[( rows-y-1)*cols+x]=array[y*cols+x];
    }
    y=0;
  }
}
/* TASK 4 */
// Find the first coordinate of the first pixel with a value that
// equals color. Search from left-to-right, top-to-bottom. If it is
// found, store the coordinates in *x and *y and return 1. If it is
// not found, return 0.
int locate_color(  const uint8_t array[], 
		   unsigned int cols, 
		   unsigned int rows,
		   uint8_t color,
		   unsigned int *x,
		   unsigned int *y )
{
    // your code here
    unsigned int a=0,b=0;
    
    for(;b< rows;b++){
        //
        for(;a< cols;a++){
            //
            if(*(array +b*cols+a)==color){
                //
                *x=a;//
                *y=b;
                return 1;
            }
        }//
        a=0;
    }
    return 0;
}
/* TASK 5 */
// Invert the image, so that black becomes white and vice versa, and
// light shades of grey become the corresponding dark shade. 
void invert( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows )
{
    // your code here
    unsigned int a=0;
    //
    for (;a< cols*rows;a++){
        //
        array[a]=255- array[a];
    }
}
/* TASK 6 */
// Multiply every pixel by scale_factor, in order to brighten or
// darken the image. Any resulting value over 255 is
// thresholded to 255.
void scale_brightness( uint8_t array[],
            unsigned int cols,
            unsigned int rows,
            double scale_factor )
{
  // your code here
    unsigned int a=0;
    //
    for (;a< cols*rows;a++){
        //
        unsigned int ls= (unsigned int)round( scale_factor*array[a]);
        //
        if( ls> 255){
            //
            ls=255;
        }
        //
        array[a]=ls;
    }
  return;
}
/* TASK 7 */
// Normalize the dynamic range of the image, i.e. Shift and scale the
// pixel colors so that that darkest pixel is 0 and the lightest pixel
// is 255. Hint: you already wrote min() and max(). 
void normalize( uint8_t array[],
        unsigned int cols,
        unsigned int rows )
{
    // your code here
    unsigned int a=0;
    
    //
    uint8_t maxnum=max( array,cols,rows);
    uint8_t minnum=min( array,cols,rows);
    //
    for (;a<cols* rows;a++){
        //
        array[a]=array[a]- minnum;
    }
    double d=1.0*255/(maxnum -minnum);
    //
    scale_brightness( array,cols,rows,d);
}
/* TASK 8 */
// Return a new image of size rows/2 by cols/2 If the original image              
// has an odd number of columns, ignore its rightmost column. If the              
// original image has an odd number of rows, ignore its bottom row.               
// The value of a pixel at (p,q) in the new image is the average of               
// the four pixels at (2p,2q), (2p+1,2q), (2p+1,2q+1), (2p,2q+1) in               
// the original image.                                                            
uint8_t* half( const uint8_t array[],
	       unsigned int cols,
	       unsigned int rows )
{
  // your code here
    int x=0,y=0;
    //
    unsigned int hi=cols/2,hj=rows/2;
    //
    uint8_t *sl=realloc(NULL,hi*hj*sizeof(uint8_t));
    //
    if (!sl&&hi*hj>0){
        return NULL;
    }
    for(;x< cols;x+=2){
        //
        for(;y< rows;y+=2){
        
            //
            //float ls=;
            
            set_pixel(sl,hi,hj,x/2,y/2,round(0.25*(get_pixel(array  ,cols,rows,x,y)	+ get_pixel(array ,cols,rows,x,y+1)+ get_pixel(array, cols,rows,x+1,y+1)	+ get_pixel(array ,cols,rows,x+1,y)	)));
        }
        y=0;
    }
    //
    return sl;
}
/*-------------------------------------------------
  PART 2: OPERATIONS ON IMAGE SUB-REGIONS
  These functions operate only on a rectangular region of the array
  defined by a (left,top) corner (i.e. closer to the image origin) and
  (right,bottom) corner (i.e. further from the image origin).
  The region includes all the columns from [left, right-1] inclusive,
  and allthe rows from [top, bottom-1] inclusive.
  
  In every case, you may assume that left <= right and top <= bottom:
  do not need to test for this.
  The area of the region is right-left * bottom-top pixels, which
  implies that if left == right or top == bottom, the region has no
  area and is defined as "empty". Each function notes how to handle
  empty regions.
 
  In every function, use assert() to test bounds on the region
  corners.
*/
/* TASK 9 */
// Set every pixel in the region to color. If the region is empty, the
// image must be unchanged.
void region_set( uint8_t array[], 
         unsigned int cols, 
         unsigned int rows,
         unsigned int left,
         unsigned int top,
         unsigned int right,
         unsigned int bottom,
         uint8_t color )
{
    // your code here
    int x=left,y=top;
    //
    if(right<=left || bottom<=top||bottom-top>=rows|| right-left>=cols){
        //
        return;
    }
    
    
    for(;x<right;x++){
    
        for(;y<bottom;y++){
            //
            
            set_pixel(array, cols,rows, x, y, color);
            
        }
        y=top;
    }
    //return;
}
/* TASK 10 */
// Return the sum of all the pixels in the region. Notice the large
// return type to handle potentially large numbers. Empty regions
// return the sum 0.
unsigned long int region_integrate( const uint8_t array[], 
                    unsigned int cols, 
                    unsigned int rows,
                    unsigned int left,
                    unsigned int top,
                    unsigned int right,
                    unsigned int bottom )
{
  
    
    int x=left,y=top;
    unsigned long int zhi=0;
    if(right<=left||bottom<=top||bottom -top>=rows||right- left>=cols){
        //
        return 0;
    }
    
    
    for(;x< right; x++){
    
        for(;y< bottom;y++){
            //
            
            zhi=zhi+get_pixel(array, cols, rows, x, y);
            
        }
        y=top;
    }
    return zhi;
}
/* TASK 11 */
// Get a new image which is a copy of the region. Empty regions return
// a null pointer. If memory allocation fails, return a null
// pointer. The caller is responsible for freeing the returned array
// later.
uint8_t* region_copy( const uint8_t array[], 
              unsigned int cols, 
              unsigned int rows,
              unsigned int left,
              unsigned int top,
              unsigned int right,
              unsigned int bottom )
{
    // your code here
    unsigned int x=left,y=top;
    //
    if(right<=left||right-left>=cols ||bottom-top>=rows||bottom<=top){
        //
        return NULL;
    }
    uint8_t *sl=realloc(NULL,(right-left)*(bottom-top)*sizeof(uint8_t));
    //
    if(sl==NULL&&(right-left)*(bottom-top)>0){
        return NULL;
    }
    else{
        for(;y<bottom;y++){
        //
            for(;x<right;x++){
            
           
            
            //
		        set_pixel(sl,right-left,bottom-top,x-left,y-top,get_pixel(array,cols,rows,x,y));
            }
            x=left;
        }
    //
        return sl;
    }
    
}
