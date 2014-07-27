#include <stdio.h>
#define MAXLINE 10 /* max input line length */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
  int len;  /* current line length */
  int largestSoFar;  /* maximum length seen so far */
  char line[MAXLINE]; /* current input line */
  char longest[MAXLINE];  /* longest line saved here */

  largestSoFar = 0;
  while ((len = getLine(line, MAXLINE)) > 0) {
    if (len > largestSoFar) {
      largestSoFar = len;
      copy(longest, line);
    } 
    if (largestSoFar > 0) {
       printf("%s\n%d\n", longest, largestSoFar);
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

/* copy: copy 'from' into 'to'; assume to is beig enough */
void copy(char to[], char from[])
{
  int i;

  i=0;
  while (from[i] != '\0') {
    if (from[i] != '\n') 
      to[i] = from[i];
    ++i;
  }
}
