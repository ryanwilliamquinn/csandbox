#include <stdio.h>
#define MAXLINE 512 /* max input line length */
#define MINLENGTH 80 /* min input length to print */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
  int len;  /* current line length */
  char line[MAXLINE]; /* current input line */

  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > MINLENGTH) {
       printf("%s\n", line);
    }
  }
  return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
  int c, i;

  for (i=0; (c=getchar()) != EOF && c != '\n'; ++i) {
    if (i < (lim-1)) { 
      s[i] = c;
    }
  }
  return i;
}
