//#include <stdio.h>
//#include <stdint.h> 
#include <stdlib.h>
//#include <string.h>
#include <fstream>
#include <iostream>
#include "image3.hpp"

using namespace std;
unsigned int cols;
unsigned int rows;
uint8_t** pixels;

Image::Image(){
    cols=0;
    rows=0;
    pixels=(uint8_t**)realloc(NULL,sizeof(uint8_t*));
    
}
Image::~Image(){
    int i;
    for(i=0;i<(int)cols;i++){
      free(pixels[i]);
    }
    //free(cols);
    //free(&rows);
    //free(&i);
    free(pixels);
}
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
  
    uint8_t** pix;
    int check=0;
    if(cols!=width||rows!=height){
        pix=(uint8_t**)realloc(pixels,sizeof(uint8_t*)*height);
        if(width!=0&&height!=0&&pix==NULL){
            return -1;
        }
        cols=width;
        rows=height;
        check=1;
        
        pixels=pix;
    }
  
  
    //pixels=(uint8_t**)realloc(sizeof(uint8_t)*width*height);
    // if(pixels==NULL){
    //     return -1;
    // }
    for(unsigned int j=0;j<height&&width!=0;j++){
      if(check){
        pixels[j]=(uint8_t*)malloc(sizeof(uint8_t)*width);
        if(pixels[j]==NULL){
          return -1;
        }
        //cout << "yyy" << endl;
      }
    
      
      
      for(unsigned int i=0;i<width;i++){
        pixels[j][i]=fillcolor;
        //cout << pixels[j][i] << endl;
      }
        
    }
    //cout << pixels[0][0] << endl;
    return 0;
    
}
  
  /* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
    if(cols==0||rows==0){
      return -1;
    }
    if(x<cols&&y<rows)
    {
        pixels[y][x]=color;
        return 0;
    }
    else{
        return -1;
    }
}
  
  /* Gets the color of the pixel at (x,y) and stores at the address pointed to 
     by colorp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
    if(x>=cols||y>=rows||!colorp){
      return -1;
    }
    if(x<cols&&y<rows)
    {
        *colorp=pixels[y][x];
        return 0;
    }
    else{
        return -1;
    }
    
    
}
  
  /* Saves the image in the file filename. In a format that can be
     loaded by load().  Returns 0 on success, else a non-zero error
     code. */
int Image::save( const char* filename ){
  int hdr[2];
  if(filename==NULL){
    return -1;
  }
  hdr[0]=cols;
  hdr[1]=rows;
  ofstream ofs(filename,ios::binary);
  if(ofs){
    ofs.write(reinterpret_cast<const char*>(hdr),2*sizeof(int));
    ofs.write(reinterpret_cast<const char*>(pixels),sizeof(uint8_t)*cols*rows);
    //ofs<<hdr<<" "<<pixels;
  }
    
    ofs.close();
    
  // }
  // catch(const ifstream::failure&e){
  //   //cout << "Open failue\n" ;
  //   return -1;
  // }
  return 0;
}

  /* Load the an image from the file filename, replacing the current
     image size and data. The file is in a format that was saved by
     save().  Returns 0 success, else a non-zero error code . */
int Image::load( const char* filename ){
  unsigned int hdr[2];
  if(filename==NULL){
    return -1;
  }
  
  ifstream in(filename,ios::binary);
  if(in){
      //in.seekg(0,ios::beg);
      //in>>hdr>>pixels;
      in.read(reinterpret_cast<char*>(hdr),2*sizeof(int));
      if(cols!=hdr[0]||rows!=hdr[1]){
        //cout << "not" << endl;
        resize(hdr[0],hdr[1],0);
      }
      
      
      in.read(reinterpret_cast<char*>(pixels),sizeof(uint8_t)*cols*rows);
  }
  else{
    return -1;
  }
    
    
    // file.read(hdr,sizeof(int)*2);
    // pixels=(uint8_t*)malloc(sizeof(uint8_t)*hdr[0]*hdr[1]);
    // file.read(pixels,sizeof(uint8_t)*hdr[0]*hdr[1]);
    // file.close();
    
  // }
  // catch(const ifstream::failure&e){
  //   //cout << "Open failue\n" ;
  //   return -1;
  // }
  cols=hdr[0];
  rows=hdr[1];
  return 0;
}
