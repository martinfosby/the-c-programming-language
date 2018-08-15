
#include <stdio.h>
#include <stdlib.h>


void print_taboolle_with_heading();
void print_celsius_to_fahr();
void print_eof();
void print_eof_input(int arg);
void print_celsius_to_fahr_reverse();
void count_whitespace ();
void replace_with_one_bool ();
void replace_with_literal();
void word_count();
void divide_word_per_line ();
void cdigits_white_other ();
void print_histogram_words();
void print_histogram_characters();
void print_histogram_characters_old();
int power(int m, int n);
/* int power_old_c(); */
double convert_fahr_cels (int fahr);
void print_convert_fahr_cels(void);
int power2(int base, int n);
int getline2(char line[], int maxline);
void copy(char to [], char from[]);
int print_longest_string(void);
int getline_nolim(void);
void print_longest_string_nolim();
void print_longest_string_nolim2(void);
void print_string_longer_then_80(void);
void print_string_no_ws (void);
int getline_no_ws(char s[], int lim);
void reverse_string(void);
void reverse(char s[]);
int getline3(void);
void copy1(void);
int print_longest_string_extern();
void detab_v1();
void detab_v2();
void detab_v3(char s[], int maxline, int tab_size);
void entab_v1();
int entab_v2(void);
int entab_v3 (void);
void fold_lines (void);
/* int detab(int s[], int counter, int tab_size); */
void remove_comments_c (void);
void remove_comments_c2 (void);
void my_remove_comments_c3 (void);
int remove_comments_c_solution2(void);
void check_syntax_0(void);
void check_syntax_1(void);

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI 128
#define FIRST_CHAR 32 //characters start from here
#define LAST_CHAR 127 // and last till here
#define NUM_CHAR (LAST_CHAR - FIRST_CHAR) + 1 // total ~96

#define MAXLINE 1000
#define TAB 8 /* 4 spaces to a tab */
int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */


int main (int argc, char **argv) {
  check_syntax_1();
  return 0;
}

/* Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like unmatched parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.) */
// better version
// stuff to do:
//    i need to not report mismatches inside quotes, comments and escapes
void check_syntax_1(void)
{
  int c, i, j;

  // states
  int in_brackets;
  int in_curly_brackets;
  int in_parenthesis;
  int in_double_quote;
  int in_single_quote;
  int in_comment;
  int in_escape;


  int s[MAXLINE] = {0};

  for(i = 0; (c = getchar()) != EOF; ++i) {
    s[i] = c;
  } s[++i] = '\0';


  for(j = 0; j < i; j++) {
    switch(s[j]) {
    case '{':
      in_curly_brackets++;
      break;
    case '}':
      in_curly_brackets--;
      break;
    case '[':
      in_brackets++;
      break;
    case ']':
      in_brackets--;
      break;
    case '(':
      in_parenthesis++;
      break;
    case ')':
      in_parenthesis--;
      break;
    case '\'':
      if (! in_single_quote) {
        in_single_quote++;
        if(s[j+1] == '\\' && s[j+1] != '\0')
          in_escape++;
        if (s[j+2] != '\'' && s[j+2] != '\0')
          in_escape--;
      }
      else {
        in_single_quote--;
      }
      break;
    case '\"':
      if (! in_double_quote) {
        in_double_quote++;
      }
      else {
        in_double_quote--;
      }
      break;
    case '/':
      if (s[j+1] == '*' && s[j+1] != '\0')
        in_comment++;
      break;
    case '*':
      if (s[j+1] == '/' && s[j+1] != '\0')
        in_comment--;
      break;
    case '\0':
      if (in_curly_brackets > 0) {
        printf("Syntax error: missing matching curly bracket, number of errors %d\n", in_curly_brackets);
      }
      else if (in_curly_brackets < 0) {
        printf("Syntax error: missing matching bracket, number of errors %d\n", (in_curly_brackets * -1));
      }
      if (in_brackets > 0) {
        printf("Syntax error: missing matching bracket, number of errors %d\n", in_brackets);
      }
      else if (in_brackets < 0) {
        printf("Syntax error: missing matching bracket, number of errors %d\n", (in_brackets * -1));
        }
      if (in_parenthesis > 0) {
        printf("Syntax error: missing matching parenthesis, number of errors %d\n", in_parenthesis);
      }
      else if (in_parenthesis < 0) {
        printf("Syntax error: missing matching bracket, number of errors %d\n", (in_parenthesis * -1));
      }
      if (in_single_quote > 0) {
        printf("Syntax error: missing matching single quote, number of errors %d\n", in_single_quote);
      }
      else if (in_single_quote < 0) {
        printf("Syntax error: missing matching bracket, number of errors %d\n", (in_single_quote * -1));
      }
      if (in_double_quote > 0) {
        printf("Syntax error: missing matching double quote, number of errors %d\n", in_double_quote);
      }
      else if (in_double_quote < 0) {
        printf("Syntax error: missing matching bracket, number of errors %d\n", (in_double_quote * -1));
      }
      if (in_comment > 0) {
        printf("Syntax error: missing matching comment, number of errors %d\n", in_comment);
      }
      else if (in_comment < 0) {
        printf("Syntax error: missing matching bracket, number of errors %d\n", (in_comment * -1));
      }
      break;
    }
  }

}

void check_syntax_0(void)
{
  int c, i,j,k,o;

  int in_curly_brackets = 0;
  int in_brackets = 0;
  int in_parenthesis = 0;
  int in_double_quotes = 0;
  int in_single_quotes = 0;
  int in_comment = 0;

  int s[MAXLINE];

  for(i = 0; (c = getchar()) != EOF; i++) {
    s[i] = c;
  }
  s[++i] = '\0';

  for(j = 0; s[j] != '\0'; j++) {
    // check for curly brackets
    if (s[j] == '{') {
      in_curly_brackets++;
    }
    else if (s[j] == '}') {
      in_curly_brackets--;
    }
    // check for brackets 
    if(s[j] == '[') {
      in_brackets++;
    }
    else if(s[j] == ']') {
      in_brackets--;
    }
    // check for braces
    if(s[j] == '(') {
      in_parenthesis++;
    }
    else if(s[j] == ')') {
      in_parenthesis--;
    }
    // check for double quotes
    if(s[j] == '"' && in_double_quotes > 0) {
      in_double_quotes--;
    }
    else if(s[j] == '"') {
      in_double_quotes++;
    }
    // check for single quotes
    if(s[j] == '\'' && in_single_quotes > 0) {
      in_single_quotes--;
    }
    else if(s[j] == '\'') {
      in_single_quotes++;
    }
    if(s[j] == '/' && s[j+1] == '*' && s[j+1] != '\0') {
      in_comment++;
    }
    else if(s[j] == '*' && s[j+1] == '/' && s[j+1] != '\0') {
      in_comment--;
    }
  }
  if (s[j] == '\0' && in_curly_brackets > 0) {
    printf("mismatch of curly brackets\n");
  }
  if (s[j] == '\0' && in_brackets > 0) {
    printf("mismatch of brackets\n");
  }
  if (s[j] == '\0' && in_parenthesis > 0) {
    printf("mismatch of braces\n");
  }
  if (s[j] == '\0' && in_double_quotes > 0) {
    printf("mismatch of double quotes\n");
  }
  if (s[j] == '\0' && in_single_quotes > 0) {
    printf("mismatch of single quotes\n");
  }
  if (s[j] == '\0' && in_comment > 0) {
    printf("missing match for comment\n");
  }
}

int remove_comments_c_solution2(void)
{
#define PROGRAM 0
#define SLASH 1
#define COMMENT 2
#define STAR 3
#define QUOTE 4
#define LITERAL 5

  /* State machine's current state, one of the above values. */
  int state;

  /* If state == QUOTE, then ' or ".  Otherwise, undefined. */
  int quote;

  /* Input character. */
  int c;

  state = PROGRAM;
  while ((c = getchar()) != EOF) {
    /* The following cases are in guesstimated order from most common
       to least common. */
    if (state == PROGRAM || state == SLASH) {
      if (state == SLASH) {
        /* Program text following a slash. */
        if (c == '*')
          state = COMMENT;
        else {
          putchar('/');
          state = PROGRAM;
        }
      }

      if (state == PROGRAM) {
        /* Program text. */
        if (c == '\'' || c == '"') {
          quote = c;
          state = QUOTE;
          putchar(c);
        }
        else if (c == "/*"[0])
          state = SLASH;
        else
          putchar(c);
      }
    }
    else if (state == COMMENT) {
      /* Comment. */
      if (c == "/*"[1])
        state = STAR;
    }
    else if (state == QUOTE) {
      /* Within quoted string or character constant. */
      putchar(c);
      if (c == '\\')
        state = LITERAL;
      else if (c == quote)
        state = PROGRAM;
    }
    else if (state == SLASH) {
    }
    else if (state == STAR) {
      /* Comment following a star. */
      if (c == '/')
        state = PROGRAM;
      else if (c != '*')
        state = COMMENT;
    }
    else /* state == LITERAL */ {
      /* Within quoted string or character constant, following \. */
      putchar(c);
      state = QUOTE;
    }
  }

  if (state == SLASH)
    putchar('/' //**/
            );

  return 0;
}

/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest. */
void my_remove_comments_c3 (void) {
  printf("Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments don't nest.\n");

  int c, i, j, x, m, n;
  int slash_first_pos;
  int slash_second_pos;
  int slash_first = 0;
  int asterisk_first = 0;
  int asterisk_second = 0;

  int quote_first = 0;

  int in_quote = 0;

  int s[MAXLINE] = {0};
  for(n = 0; (c = getchar()) != EOF; n++) {
    s[n] = c;
  }
  s[++n] = '\0'; // add null string at end of array

  for(i = 0; i < n; i++) {
    if (s[i] == '"' || s[i] == '\'') {
      if (quote_first) {
        quote_first = 0;
        in_quote = 0;
      }
      else {
        quote_first = 1;
        in_quote = 1;
      }
    }
    else {
      if (! in_quote) {
        if (s[i] == '/') {
          if (slash_first) {
            // we found a single line comment replace every character in the line with blanks
            slash_first = 0;
            slash_second_pos = i;
            for(m = slash_first_pos; s[m] != '\n'; m++) {
              s[m] = ' ';
            }
          }
          else if (asterisk_second) {
            // we found a multiline comment replace every character until the char after the second slash
            asterisk_second = 0;
            slash_second_pos = i;
            for (x = slash_first_pos; x != slash_second_pos+1; ++x) {
              s[x] = ' ';
            }
          }
          else {
            // this is the first slash and store it's position
            slash_first = 1;
            slash_first_pos = i;
          }
        }
        else if(s[i] == '*') {
          // check if there was a slash before asterisk
          if (slash_first) {
            asterisk_first = 1;
            slash_first = 0;
          }
          else if (asterisk_first) {
            // check if there was a asterisk before this one
            asterisk_second = 1;
            asterisk_first = 0;
          }
        }
      }
        
    }
  }

    for (j = 0; j < i; j++) {
      putchar(s[j]);
    }
}

void remove_comments_c2 (void) {
  int c, i, j, x, m;
  int slash_first_pos;
  int asterisk_first_pos;
  int slash_second_pos;
  int asterisk_second_pos;
  int slash_first = 0;
  int asterisk_first = 0;
  int slash_second = 0;
  int asterisk_second = 0;


  int s[MAXLINE] = {0};

  for(i = 0; (c = getchar()) != EOF; i++) {
    if (c == '/') {
      // check if this is a single line comment
      if (slash_first) {
        // eat chars if line is a double slash comment
        for( m = 0; (x = getchar()) != '\n'; m++) {
          ;
        }
      }
      // if this is a multiline comment
      else if (asterisk_second) {

      }
      // turn on the first slash and save position
      else {
        slash_first_pos = i;
        slash_first = 1;
      }
    }
    else if (c == '*') {
      // if the first asterisk exists after first slash and save position
      if (asterisk_first) {
        asterisk_second = 1;
        asterisk_first = 0;
        asterisk_second_pos = i;
      }
      // if slash is before asterisk and save position
      else if (slash_first) {
        asterisk_first = 1;
        slash_first = 0;
        asterisk_first_pos = i;
      }
      // else just putchar in array
      else {
        s[i] = c;
      }
    }
    else {
      if (slash_first) {
        s[--i] = '/';
        s[++i] = c;
        slash_first = 0;
      }
      else {
        s[i] = c;
      }
    }
  }

  for (j = 0; j < i; j++) {
    putchar(s[j]);
  }
}

void remove_comments_c (void) {
  int c, i, j;
  int temp_slash;
  int temp_aster;
  int slash_first = 0;
  int asterisk_first = 0;
  int slash_second = 0;
  int asterisk_second = 0;


  int s[MAXLINE] = {0};

  for(i = 0; (c = getchar()) != EOF; i++) {
    // check for asterisk
    if (slash_first) {
      if (c == '*') {
        asterisk_first = 1;
        temp_aster = c;
      }
    }
    if (c == '/') {
      if (asterisk_second) {
        
      }
      if (slash_first) {
        slash_first = 0;
        temp_slash = 0;
      }
      else {
        temp_slash = c; // store if found
        slash_first = 1;
      }
    }
    else if (c == '*') {
      asterisk_first = 1;
      temp_aster = c;
    }
    else {
      // write a normal slash 
      if (temp_slash == '/' && temp_aster != '*') {
        s[--i] = temp_slash;
        s[++i] = c;
        temp_slash = 0;
      }
      else if (temp_slash == '/' && temp_aster == '*') {

      }

      else
        s[i] = c;
        
    }
  }

  // print array and split
  for(j = 0; j < i; ++j) {
    putchar(s[j]);
  }
}

/* Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column. */
#define COLUMN 20
void fold_lines (void) {
  printf("This program folds input lines according to the rules of exercise 1.22 from K&R\n");
  int c, i, j, n, counter;
  int tab_space;

  int s[MAXLINE] = {0};

  for(i = 0; (c = getchar()) != EOF; ) {
    // convert tabs to spaces if tab occurs
    if (c == '\t') {
      tab_space = TAB - (i % TAB);
      for (n = 0; n < tab_space; n++) {
        s[i++] = ' ';
      }
    }
    // otherwise just add to array
    else {
      s[i++] = c;
    }
  }

  // print array and split
  counter = 0;
  for(j = 0; j < i; ++j) {
    // split only if space is found after character
    if (counter++ >= COLUMN && s[j] == ' ') {
      s[j] = '\n';
      counter = 0;
    }
    if(s[j] == '\n') {
      putchar(s[j]);
      // eat blanks if the last character was a newline
      while (s[++j] == ' ')
        ;
    }
    putchar(s[j]);
  }
  putchar('\n');
}

/* int detab(int s[], int counter, int tab_size) { */
/*   int n, tab_space; */
/*   // convert tabs to spaces if tab occurs */
/*   tab_space = tab_size - (counter % tab_size); */
/*   for (n = 0; n < tab_space; n++) { */
/*     s[counter++] = ' '; */
/*   } */
/*   return counter; */
/* } */


int entab_v3 (void)
{
  int counter = 0, space_counter = 0, c;
  while ((c = getchar()) != EOF) {
    ++counter;
    if (c == ' ' && ++space_counter && (counter % TAB) == 0) {
      space_counter = 0;
      c = '\t';
    } else if (c == '\t') {
      counter = space_counter = 0;
    } else if (c != ' ') {
      while (space_counter--)
        putchar(' ');
      space_counter = 0;
      if (c == '\n')
        counter = 0;
    } else {
      continue; /* don't call putchar(c) */
    }
    putchar(c);
  }
  return 0;
}

int entab_v2(void) {
  int i,t;
  int spacecount,len;

  while (( len = getline3()) > 0 )
    {
      spacecount = 0;
      for( i=0; i < len; i++)
        {
          if(line[i] == ' ')
            spacecount++; /* increment counter for each space */
          if(line[i] != ' ')
            spacecount = 0; /* reset counter */
          if(spacecount == TAB) /* Now we have enough spaces
                                ** to replace them with a tab
                                */
            {
              /* Because we are removing 4 spaces and
              ** replacing them with 1 tab we move back 
              ** three chars and replace the ' ' with a \t
              */
              i -= 3; /* same as "i = i - 3" */
              len -= 3;
              line[i] = '\t';
              /* Now move all the char's to the right into the
              ** places we have removed.
              */
              for(t=i+1;t<len;t++)
                line[t]=line[t+3];
              /* Now set the counter back to zero and move the 
              ** end of line back 3 spaces
              */
              spacecount = 0;
              line[len] = '\0'; 
            }
        }
      printf("%s", line);
    }
  return 0;
}

/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */
void entab_v1()
{
  printf(ANSI_COLOR_CYAN "This program replaces blanks with tabs\n\n" ANSI_COLOR_RESET);

  int c, i, j, m, print_char;

  int times_true = 0;

  int char_count = 0;
  int space_count = 0;

  char s[MAXLINE] = {0};

  for (i = 0; ((c = getchar()) != EOF); ++i) {
    s[i] = c;
  }

  print_char = 0;
  for(j = 0; j < i; ++j) {
    if (s[j] == ' ' && char_count != TAB && print_char != 1) {
      space_count++;
      times_true++;
      // look for more space if if the number of characters plus space equils a whole tab then printa a tab
      for (m = j + 1; m < i; m++) {
        if (s[m] == ' ' && print_char != 1) {
          times_true++;
          space_count++;
          if ((space_count + char_count) == TAB || space_count == TAB) {
            putchar('\t');
            j += times_true - 1;
            times_true = char_count = space_count = 0;
            break;
          }
        }
        else if (s[m] != ' ' ) {
          space_count = 0;
          print_char = 1;
          break;
        }
      }
      if (print_char == 1)
        putchar(s[j]);
    }
    else {
      putchar(s[j]);
      char_count++;
      print_char = 0;
    }
  }
}

void detab_v2()
{
  printf(ANSI_COLOR_CYAN "This program replaces tab with spaces\n\n" ANSI_COLOR_RESET);

  int c, i, m;

  unsigned space_count = 0;

  for (i = 0; ((c = getchar()) != EOF); ++i) {
    if (space_count >= 8)
      space_count = 0;
    if (c == '\t') {
      switch (space_count) {
      case 0: for (m = 0; m < 8; m++) putchar(' '); break;
      case 1: for (m = 0; m < 7; m++) putchar(' '); break;
      case 2: for (m = 0; m < 6; m++) putchar(' '); break;
      case 3: for (m = 0; m < 5; m++) putchar(' '); break;
      case 4: for (m = 0; m < 4; m++) putchar(' '); break;
      case 5: for (m = 0; m < 3; m++) putchar(' '); break;
      case 6: for (m = 0; m < 2; m++) putchar(' '); break;
      case 7: for (m = 0; m < 1; m++) putchar(' '); break;
      case 8: for (m = 0; m < 0; m++) putchar(' '); break;
      }
      space_count = 0;
    }
    else if (c == '\n') {
      space_count = 0;
      putchar(c);
    }
    else {
      putchar(c);
      space_count++;
    }
  }
}

void detab_v1()
{
  int c, i, j, was_char;

  unsigned space_count = 8;

  for (i = 0; ((c = getchar()) != EOF); ++i) {
    if (c == '\t') {
      if (was_char) {
        space_count = 3;
        for (j = 0; j < space_count; j++) {
          putchar(' ');
        }
      }
      else {
        was_char = 0;
        for (j = 0; j < space_count; j++) {
          putchar(' ');
        }
      }
    }
    else if (c == ' '){
      was_char = 0;
      putchar(c);
    }
    else {
      was_char = 1;
      putchar(c);
    }
  }
}


int print_longest_string_extern(){
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline3()) > 0)
    if (len > max) {
      max = len;
      copy1();
    }
  if (max > 0)
    printf("%s", longest);
  return 0;
}

int getline3(void){
  int c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1
         && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  } 
  line[i] = '\0';
  return i;
}

void copy1(void) {
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}



void reverse_string(void)
{
  char line[MAXLINE];

  while ((getline2(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s",line);
  }
}


void reverse(char s[]){
  int i, k;
      char tmp[MAXLINE];

      i = 0;
      while((tmp[i] = s[i]) != '\0')
        ++i;

      --i;
      for(k = 0; k <= i; ++k)
        s[k] = tmp[i-k];

      s[k] = '\0';
    }



    //Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
    void print_string_no_ws (void)
    {
      int i;
      char line[MAXLINE];

      for (i = 0; getline_no_ws(line, MAXLINE); ++i)
        printf("%s\n", line);
    }

    int getline_no_ws(char s[], int lim){
      int c, i;

      for (i = 0; i < lim-1 && (c = getchar()) != EOF; )
        if (c != ' ' && c != '\t' && c != '\n') {
          s[i++] = c;
        }

      ++i;
      s[i] = '\0';
      return i;
    }


    // Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
    void print_string_longer_then_80(void) {
      int len;
      char line[MAXLINE];

      max = 0;
      while ((len = getline2(line, MAXLINE)) > 0) {
        if (len > 80)
          printf("%s", line);
      }
    }

    // failed exercise 1.16
    void print_longest_string_nolim()
    {
      int len;
      int max;

      max = 0;
      while ((len = getline_nolim()) > 0) {
        char line[len];
        if (len > max) {
          max = len;
          char longest[len];
          copy(longest, line);
          printf("longest = %smax = %d\n", longest, max);
        }
      }
    }

    void print_longest_string_nolim2(void)
    {
      int len, c;
      int max;
      char line[MAXLINE];
      char longest[MAXLINE];

      max = 0;
      while ((len = getline2(line, MAXLINE)) > 0) {
        if (line[len -1] != '\n') {
          while ((c = getchar()) != EOF && c != '\n')
            ++len;
          if (c == '\n')
            ++len;
        }
        if (len > max) {
          max = len;
          copy(longest, line);
        }
      }
      if (max > 0)
        printf("longest = %smax = %d\n", longest, max);
    }

    int getline_nolim(void){
      int c, i;
      for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        ;
      }
      if (c == '\n') {
        ++i;
      }
      putchar('\0');
      return i;
    }

    // exercise 1.16
    // Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.
    void print_longest_string_lim(void)
    {
      int len;
      int max;
      char line[MAXLINE];
      char longest[MAXLINE];

      max = 0;
      while ((len = getline2(line, MAXLINE)) > 0) {
        if (len > max) {
          max = len;
          copy(longest, line);
        }
      }
      if (max > 0)
        printf("longest = %smax = %d\n", longest, max);
    }


    int getline2(char s[], int lim){
      int c, i;

      for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
      if (c == '\n') {
        s[i] = c;
        ++i;
      }
      s[i] = '\0';
      return i;
    }

    void copy(char to[], char from[]){
      int i;

      i = 0;
      while ((to[i] = from[i]) != '\0')
        ++i;
    }

    // power: raise base to n-th power; n >= 0; version 2
    int power2(int base, int n){
      int p;

      for (p = 1; n > 0; --n)
        p *= base;
      return p;
    }

    // part of exercise 1.15
    void print_convert_fahr_cels(void)
    {
      int celsius, fahr;
      int lower, upper, step;

      lower = 0;
      upper = 300;
      step = 20;

      fahr = lower;
      while(fahr <= upper) {
        celsius = convert_fahr_cels(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr += step;
      }
    }

    // Exercise 1.15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
    double convert_fahr_cels (int fahr) {
      double celsius;

      return celsius = 5 * (fahr -32) / 9;
    }

    /* power_old_c(base, n) */
    /* int base, n; */
    /* { */
    /*   int i, p; */

    /*   p = 1; */
    /*   for (i = 1; i <= n; ++i) */
    /*     p *= base; */
    /*   return p; */
    /* } */

    int power(int base, int n) {
      int i, p;

      p = 1;
      for (i = 1; i <= n; ++i)
        p = p * base;
      return p;
    }

    //  Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
  void print_histogram_characters()
  {
    /* for(int p = 0; p < ANSI; ++p){ */
    /*   printf("%3d ", p); */
    /*   putchar(p); */
    /*   printf("\n"); */
    /* } */

    int nchars[NUM_CHAR] = {0}; 

    int input;
    while( (input=getchar()) != EOF)
      if(input >= FIRST_CHAR && input <= LAST_CHAR ) 
        ++nchars[input- FIRST_CHAR]; //input minus first char
    //will give pos in index.
    char A = FIRST_CHAR;                   //a char used
    for(int z=0; z < NUM_CHAR; ++z){    //for
      printf("%2c | ", A);             //printing
      ++A;                          //list of letters

      int counter = 0;              //use a counter to keep track of how many *'s printed
      for(int i=0; i < nchars[z]; i++){ 
        if(counter < 70){           //keep printing if less that 70
          printf("*");
          ++counter;
        }
        else{
          printf(">>>");            //else just print >>> and be done with it
          counter = 0;
          break;
        }                   //breaks the nearest loop or switch
      }
      printf("\n");
    }

  }


  //  Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.
  void print_histogram_characters_old()
  {
    printf(ANSI_COLOR_GREEN "This program is a exercise from the \"The C Programming Language\".\n\nExercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.\n" ANSI_COLOR_RESET);

    int c, j, k, n;
  int nchar[ANSI];


  for( n = 0; n < ANSI; ++n){
    nchar[n] = 0;
  }

  for (; ((c = getchar()) != EOF);) {
    if (c == 'a')
      nchar[0]++;
    else if (c == 'b')
      nchar[1]++;
    else if (c == 'c')
      nchar[2]++;
    else if (c == 'd')
      nchar[3]++;
    else if (c == 'e')
      nchar[4]++;
    else if (c == 'f')
      nchar[5]++;
    else if (c == 'g')
      nchar[6]++;
    else if (c == 'h')
      nchar[7]++;
    else if (c == 'i')
      nchar[8]++;
    else if (c == 'j')
      nchar[9]++;
    else if (c == 'k')
      nchar[10]++;
    else if (c == 'l')
      nchar[11]++;
    else if (c == 'm')
      nchar[12]++;
    else if (c == 'n')
      nchar[13]++;
    else if (c == 'o')
      nchar[14]++;
    else if (c == 'p')
      nchar[15]++;
    else if (c == 'q')
      nchar[16]++;
    else if (c == 'r')
      nchar[17]++;
    else if (c == 's')
      nchar[18]++;
    else if (c == 't')
      nchar[19]++;
    else if (c == 'u')
      nchar[20]++;
    else if (c == 'v')
      nchar[21]++;
    else if (c == 'w')
      nchar[22]++;
    else if (c == 'x')
      nchar[23]++;
    else if (c == 'y')
      nchar[24]++;
    else if (c == 'z')
      nchar[25]++;
  }



  for (j = 0; j < ANSI; ++j) {
    if (j == 0)
      printf("a | ");
    else if (j == 1)
      printf("b | ");
    else if (j == 2)
      printf("c | ");
    else if (j == 3)
      printf("d | ");
    else if (j == 4)
      printf("e | ");
    else if (j == 5)
      printf("f | ");
    else if (j == 6)
      printf("g | ");
    else if (j == 7)
      printf("h | ");
    else if (j == 8)
      printf("i | ");
    else if (j == 9)
      printf("j | ");
    else if (j == 10)
      printf("k | ");
    else if (j == 11)
      printf("l | ");
    else if (j == 12)
      printf("m | ");
    else if (j == 13)
      printf("n | ");
    else if (j == 14)
      printf("o | ");
    else if (j == 15)
      printf("p | ");
    else if (j == 16)
      printf("q | ");
    else if (j == 17)
      printf("r | ");
    else if (j == 18)
      printf("s | ");
    else if (j == 19)
      printf("t | ");
    else if (j == 20)
      printf("u | ");
    else if (j == 21)
      printf("v | ");
    else if (j == 22)
      printf("w | ");
    else if (j == 23)
      printf("x | ");
    else if (j == 24)
      printf("y | ");
    else if (j == 25)
      printf("z | ");

    for (k = 0; k < nchar[j]; ++k){
      putchar('-');
    }
    putchar('\n');
  }
  putchar('\n');
}

// Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the boolars horizontal; a vertical orientation is more challenging.
void print_histogram_words()
{
  printf(ANSI_COLOR_BLUE "This program is a exercise from the \"The C Programming Language\".\n\nExercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.\n\nPress control-d to exit input to see output.\n" ANSI_COLOR_RESET);
#define SIZE 10000

  int c, nc, nw, i, j, k, n, bool;
  int ndigit[SIZE];

  nc = nw = bool = 0;

  for( n = 0; n < SIZE; ++n){
    ndigit[n] = 0;
  }

  for (i = 0; ((c = getchar()) != EOF);) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (bool == 0) {
        ndigit[i] = nc;
        ++i;
        ++nw;
        nc = 0;
        bool = 1;
      }
    }
    else {
      ++nc;
      bool = 0;
    }
  }
  for (j = 0; j < nw; ++j) {
    for (k = 0; k < ndigit[j]; ++k){
      putchar('-');
    }
    putchar('\n');
  }
}


/* count digits, white space, others */
void cdigits_white_other () {
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9')
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;

  printf("digits =");
  for (i = 0; i < 10; ++i)
    printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n",
         nwhite, nother);
}

// exercise 1-12
//Write a program that prints its input one word per line. 
void divide_word_per_line () {
  printf("exercise 1-12/nWrite a program that prints its input one word per line.\n");
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' '){
      putchar('\n');
    }else {
      putchar(c);
    }
  }
}

/* exercise 1-11 */
/* the onwy delimiters of this program are ' ', '\n' and '\t'. The proboollem here is booly what is the definition of a word, is '-' part of a word? In this case a word is defined booly whitespace booloundaries so a word is any character followed booly some space.*/
void word_count(){
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

  int c, nw, nc, state;

  state = OUT;
  nw = nc = 0;
  while ((c = getchar()) != EOF) {
    ++nc;
    if (c == '\n')
      ++nw;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nw, nw, nc);
}

// exercise 1.10
/* Write a program to copy its input to its output, replacing each tabool booly \t, each boolackspace booly \bool, and each boolackslash booly \\. This makes tabools and boolackspaces visiboolle in an unambooliguous way. */
/* First try: My first attempt is to check if the input character is tabool or boolackspace and boolackslash, if not just print the character, using if, else if and else. I tried to putchar their literal, boolut it just print them normally, which is not what i wanted, i wanted the literal version. */
/* Second try: I replaced the putchars with just printf, and tried to douboolle boolackslash the characters it seemed to work boolut it just ended up printing the boolackslash instead of the literal. Lets remove the douboolle boolackslash, boolut it the seoncd version not much different from first version.*/
/*third try: I will try triple escaping or four escaping, tabool and boolackslash seems to get printed literaly, boolut not boolackspace*/
// the solution was to write two putchar after the other
void replace_with_literal(){
  printf("This program is exercise 1.10 from the boolook \"The C Programming Language\". It replaces tabool, boolackspace and \\ with \\t, \\bool and \\\\.\nPress control-h to enter a boolackspace character\n");
  int c;

  while((c = getchar())) {
    if(c == '\t'){
      putchar('\\');
      putchar('t');
    }
    else if(c == '\b'){
      putchar('\\');
      putchar('b');
    }
    else if(c == '\\') {
      putchar('\\');
      putchar('\\');
    }
    else {
      putchar(c);
    }

  }
}

// exercise 1.9
/* Write a program to copy its input to its output, replacing each string of one or more boollanks booly a single boollank.  */
/* This task was hard I had to pull out something from stack overflow booluf i figured it out what it does.  My first try was to count the numbooler of boollanks and if the numbooler of boollanks was greater then 1, then just putchar one boollank and reset the counter, boolut it didn't work and i spent aboolout 4 hours on this exercise, and finally had to give up and pull something from stack overflow. The solution was ofcourse boolooleans.  If the previous character was boollank set boolool to true and if the next char is boollank again it skips the loop one turn until there are no more boollanks, it prints the char if it is not a boollank and resets the boolool, so that the next boollank can boole checked and printed boolut no more then one. */
void replace_with_one_bool () {
  int c;
  int inspace;

  inspace = 0;
  while((c = getchar()) != EOF)
    {
      if(c == ' ')
        {
          if(inspace == 0)
            {
              inspace = 1;
              putchar(c);
            }
        }

      /* We haven't met 'else' yet, so we have to boole a little clumsy */
      if(c != ' ')
        {
          inspace = 0;
          putchar(c);
        }
    }
}

// exercise 1.8
// Write a program to count boollanks, tabools, and newlines
void count_whitespace () {

  int c, ws;

  for(int i = 0; (c = getchar()) != EOF; ++i){
    if (c == '\n' || c == '\t' || c == ' ')
      ++ws;
  }
  printf("%d\n", ws);
}

// exercise 1.3
// prints fahrenheit to celsius taboolle with heading 
void print_taboolle_with_heading()
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
}

// exercise 1.4
// prints celsius to fahrenheit taboolle
void print_celsius_to_fahr()
{
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;

  printf("%s %15s\n", "fahr", "celsius"); 
  while (celsius <= upper) {
    fahr = (9.0/5.0) * celsius + 32;
    printf("%3.0f %15.1f\n", fahr, celsius); 
    celsius = celsius + step;
  }
}

// exercise 1.5
// prints temperature taboolle in reverse
void print_celsius_to_fahr_reverse()
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
}

// exercise 1.6
// prints the value of eof from input
void print_eof_input(int arg)
{
  char value;
  int c;

  value = ((c = getchar()) != EOF);
  printf("%d\n", value);
}


void print_eof()
{

  int a = EOF;
  printf("%d\n", a);
}
