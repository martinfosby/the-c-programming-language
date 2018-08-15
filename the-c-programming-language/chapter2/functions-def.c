#include "functions-decl.h"


/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}


/* Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1 */
/*   where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. */
/*   (The standard library function strpbrk does the same job but returns a pointer to the */
/*    location.) */
int any(char s1[], char s2[])
{
  int i, k;

  for (i = 0; s1[i] != '\0'; ++i) {
    for (k = 0; s2[k] != '\0'; ++k) {
      if (s1[i] == s2[k]) {
        return i;
      }
    }
  }
  return -1; // end of loop no character found
}

/* Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in */
/* s1 that matches any character in the string s2. */
void squeeze_array(char s1[], char s2[])
{
  int j, k, l;

  int delete = 0;

  for(k = j = 0; s1[k] != '\0'; k++) {
    for (l = 0; s2[l] != '\0' && (delete == 0); l++) {
      if (s2[l] == s1[k]) {
        delete = 1;
      }
      else {
        delete = 0;
      }
    }
    if (! delete) {
      s1[j++] = s1[k];
    }
  }
  s1[j] = '\0'; // set rest of elements to null
}

/* strcat: concatenate t to end of s; s must be big enough */
void strcat1(char s[], char t[])
{
  int i, j;
  i = j = 0;
  while (s[i] != '\0') /* find end of s */
    i++;
  while ((s[i++] = t[j++]) != '\0') /* copy t */
    ;
}

/* squeeze: delete all c from s */
void squeeze1(char s[], int c)
{
  int i, j;
  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}


/* Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits */
/*   (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 */
/*   through 9, a through f, and A through F. */
int htoi (const char s[])
{
  int i;
  int n;

  // check for prefix
  int is_prefix = (s[0] == '0' && s[1] == 'x' || s[1] == 'X');
  if(is_prefix) i = 2;
  else i = 0;

  n = 0;
  for (; isxdigit(s[i]); ++i) {
    if (s[i] >= '0' && s[i] <= '9' ) {
      n = 16 * n + (s[i] - '0');
    }
    else if(s[i] >= 'a' && s[i] <= 'f') {
      n = 16 * n + (s[i] - 'W');
    }
    else if(s[i] >= 'A' && s[i] <= 'F'){
      n = 16 * n + (s[i] - '7');
    }
  } 
  return n;
}

/* strlen: return length of s */

int strlen2(char s[])
{
  int i;
  while (s[i] != '\0')
    ++i;
  return i;
}


/* atoi: convert s to integer */
int atoi1 (char s[])
{
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    n = 10 * n + (s[i] - '0');
  }
  return n;

}

/* lower: convert c to lower case; ASCII only */
int lower1(int c)
{
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}


/* Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. */
int getline_my_version(char s[])
{
  int c;
  int i; 
  for (i=0; i < 1000 ; ++i) {
    c = getchar();
    if (c == EOF) break;
    if (c == '\n') break;
    s[i] = c;
  }

  return i;
}



void fine_something (void)
{
  unsigned long long_size = ~0;
  unsigned int IntegerSize = ~0;
  signed int SignedIntegerSize = IntegerSize / 2 + 1;
 
  unsigned char CharSize = ~0;
  signed char SignedCharSize = CharSize / 2 + 1;

  printf("%lu\n", long_size);

}

int find_type_range(void)
{
  size_t char_size = 1;
  size_t short_size = 1;
  size_t int_size = 1;
  size_t long_size = 1;
  float float_size = 1;
  double double_size = 1;

  for(size_t i = 0; i < (CHAR_BIT*sizeof(char)); i++)
    char_size *= 2;
  for(size_t i = 0; i < (CHAR_BIT*sizeof(short)); i++)
    short_size *= 2;
  for(size_t i = 0; i < (CHAR_BIT*sizeof(int)); i++)
    int_size *= 2;
  for(size_t i = 0; i < (CHAR_BIT*sizeof(long)); i++) 
    long_size *= 2;
  for(size_t i = 0; i < (CHAR_BIT*sizeof(float)); i++)
    float_size *= 2;
  for(size_t i = 0; i < (CHAR_BIT*sizeof(double)); i++)
    double_size *= 2;

  // add negative one to avoid overflow
  char_size -= 1;
  short_size -= 1;
  int_size -= 1;
  long_size -= 1;
  float_size -= 1;
  double_size -= 1;

  printf("unsigned of char: %zu\n", char_size);
  printf("maximum signed of char: %zd\n", char_size / 2 );
  printf("minimum signed of char: %zd\n", char_size / 2 * -1 -1);
  printf("unsigned of short: %zu\n", short_size );
  printf("maximum signed of short: %zd\n", short_size / 2);
  printf("minimum signed of short: %zd\n", short_size / 2 * -1 -1);
  printf("unsigned of int: %zu\n", int_size);
  printf("maximum signed of int: %zd\n", int_size / 2);
  printf("minimum signed of int: %zd\n", int_size / 2 * -1 -1);
  printf("unsigned of long: %lu\n", long_size);
  printf("maximum signed of long: %ld\n", long_size / 2);
  printf("minimum signed of long: %ld\n", long_size / 2 * -1 -1);
  printf("unsigned of float: %f\n", float_size);
  printf("maximum signed of float: %f\n", float_size / 2);
  printf("minimum signed of float: %f\n", float_size / 2 * -1 -1);
  printf("unsigned of double: %f\n", double_size);
  printf("maximum signed of double: %f\n", double_size / 2);
  printf("minimum signed of double: %f\n", double_size / 2 * -1 -1);
  printf("\n");

  printf("from limits.h \n");
  printf("char max: %d\n", CHAR_MAX);
  printf("char min: %d\n", CHAR_MIN);
  printf("unsigned char max: %u\n", UCHAR_MAX);
  printf("short max: %d\n", SHRT_MAX);
  printf("short min: %d\n", SHRT_MIN);
  printf("unsigned short max: %u\n", USHRT_MAX);
  printf("int max: %d\n", INT_MAX);
  printf("int min: %d\n", INT_MIN);
  printf("unsigned int max: %u\n", UINT_MAX);
  printf("long max: %ld\n", LONG_MAX);
  printf("long min: %ld\n", LONG_MIN);
  printf("unsigned long max: %lu\n", ULONG_MAX);
  printf("float max: %f\n", FLT_MAX);
  printf("float min: %f\n", FLT_MIN);


}

void print_type_range(void)
{
  printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
  printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));

  printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
  printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

  printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
  printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

  printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
  printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));

  /* Unsigned Maximum Values */

  printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
  printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
  printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
  printf("Maximum Unsigned Long %lu\n",(unsigned long)~0);
}
