#include <iostream>
#include "image.hpp"
#include <stdlib.h>
int main()
{

  
  Image *i1 = new Image();
  i1->resize(2,2,'j');
  if(i1->pixels[0]=='j'){
    std::cout << "sss\n";
  }
  std::cout << i1->pixels[1] << std::endl;
  //uint8_t a='p';
  uint8_t *t=(uint8_t*)malloc(sizeof(uint8_t));
  //t=(uint8_t*)malloc(sizeof(uint8_t));
  i1->get_pixel(0,0,t);
  std::cout << "lll" << std::endl;
  if(!t){
    std::cout << "lll2" << std::endl;
  }
  std::cout << *t << std::endl;
  return 0;
}
