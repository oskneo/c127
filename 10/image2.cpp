//#include <stdio.h>
//#include <stdint.h> 
#include <stdlib.h>
//#include <string.h>
#include <iostream>
#include <fstream>
#include "image2.hpp"
using namespace std;
unsigned int cols;
unsigned int rows;
uint8_t* pixels;

Image::Image(){
    cols=0;
    rows=0;
    pixels=(uint8_t*)realloc(NULL,sizeof(uint8_t*));
}
Image::~Image(){
    //free(cols);
    //free(rows);
    free(pixels);
}
int Image::resize( unsigned int width,  unsigned int height, uint8_t fillcolor ){
    uint8_t* pix;
    if(cols!=width||rows!=height){
        pix=(uint8_t*)realloc(pixels,sizeof(uint8_t)*width*height);
        if(pix==NULL){
            return -1;
        }
        cols=width;
        rows=height;
        //free(pixels);
        pixels=pix;
    }
    //cout<<"kkkkk"<<endl;
    for(unsigned int i=0;i<(height*width);i++){
        pixels[i]=fillcolor;
    }
    
    //cout << "yyy" << endl;
    
    
    return 0;
    
}
  
  /* Sets the color of the pixel at (x,y) to color. Returns 0 on success, else a non-zero 
     error code. If (x,y) is not a valid pixel, the call fails and the image does not change.*/
int Image::set_pixel( unsigned int x, unsigned int y, uint8_t color ){
    if(x<cols&&y<rows)
    {
        pixels[y*cols+x]=color;
        return 0;
    }
    else{
        return -1;
    }
}
  
  /* Gets the color of the pixel at (x,y) and stores at the address pointed to 
     by colorp. Returns 0 on success, else a non-zero error code. */
int Image::get_pixel( unsigned int x, unsigned int y, uint8_t* colorp ){
    if(x>=cols||y>=rows){
        return -1;
    }
    if(colorp==NULL){
        return -1;
    }
    else{
        //std::cout << "hhh\n";
        *colorp=pixels[y*cols+x];
        
    }
    
    
    //std::cout << "hhhh\n";
    return 0;
    
    
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
  in.close();
    
    
    // file.read(hdr,sizeof(int)*2);
    // pixels=(uint8_t*)malloc(sizeof(uint8_t)*hdr[0]*hdr[1]);
    // file.read(pixels,sizeof(uint8_t)*hdr[0]*hdr[1]);
    // file.close();
    
  // }
  // catch(const ifstream::failure&e){
  //   //cout << "Open failue\n" ;
  //   return -1;
  // }
  
  return 0;
}
