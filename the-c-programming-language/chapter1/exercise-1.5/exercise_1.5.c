#include <stdio.h>


int main(int argc, char *argv[argc])
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;


  printf("%s %15s\n", "fahr", "celsius"); 
  for (celsius = upper; celsius >= lower; celsius = celsius - step) {
    fahr = (9.0/5.0) * celsius + 32;
    printf("%3.0f %15.1f\n", fahr, celsius); 
  }
  return 0;
}
