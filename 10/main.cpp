#include <iostream>
#include "image.hpp"
#include <stdlib.h>
using namespace std;
int main()
{

  
  Image *i1 = new Image();
  i1->resize(2,2,'k');
  cout << i1->pixels[5] << endl;
  
  i1->resize(3,3,'j');
  cout << i1->pixels[5] << endl;
  
  return 0;
}
