#include <stdio.h>


int main(int argc, char *argv[argc])
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  printf("%s %15s\n", "fahr", "celsius"); 
  while (fahr <= upper) {
    celsius = 5 * (fahr-32) / 9;
    printf("%3.0f %15.1f\n", fahr, celsius); 
    fahr = fahr + step;
  }
  return 0;
}
