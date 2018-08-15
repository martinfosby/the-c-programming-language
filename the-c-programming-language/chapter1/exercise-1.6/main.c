#include <stdio.h>


int main(int argc, char *argv[argc])
{
  char value;
  int c;

  value = ((c = getchar()) != EOF);
  printf("%d\n", value);


  return 0;
}
