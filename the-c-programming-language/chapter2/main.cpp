// #include "functions-decl.h"
#include <iostream>

unsigned setbits(unsigned x,int p,int n,unsigned y);

int main(void)
{
  int x = 10;
  int * xPtr = &x;
  char y = 'a';
  char * yPtr = &y;

  std::cout << sizeof(x) << "\n";
  std::cout << sizeof(xPtr) << "\n";
  std::cout << sizeof(y) << "\n";
  std::cout << sizeof(yPtr) << "\n";
}

unsigned setbits(unsigned x,int p,int n,unsigned y)
{
  return x & ~(~(~0 << n) << (p+1-n)) | ( y & ~(~0<<n)) << (p+1-n);
}
