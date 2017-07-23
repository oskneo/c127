#include <iostream>
#include "image2.hpp"
#include <stdlib.h>
using namespace std;
int main()
{

  
  Image *i1 = new Image();
  i1->resize(640,480,'k');
  cout << i1->pixels[5] << endl;
  cout << i1->pixels[5000] << endl;
  cout << i1->cols << endl;
  i1->save("i0");
  Image *i2 = new Image();
  //i2->resize(640,480,'j');
  i2->load("i0");
  cout << i2->pixels[5000] << endl;
  return 0;
}
