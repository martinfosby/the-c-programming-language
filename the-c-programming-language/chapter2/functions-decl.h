#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

enum boolean { NO, YES };
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
               NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC }; /* FEB = 2, MAR = 3, etc. */

int find_type_range(void);
void print_type_range(void);
void fine_something (void);
int htoi (const char s[]);
void squeeze_array(char s1[], char s2[]);
void squeeze1(char s[], int c );
int any(char s1[], char s2[]);
unsigned getbits(unsigned x, int p, int n);




