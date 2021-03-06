#include <stdio.h>
#define MAXLINE 512 /* max input line length */

int getLine(char line[], int maxline);
void reset(char line[], int max);
void trim(char line[], int max);

/* print longest input line */
int main()
{
  char line[MAXLINE]; /* current input line */
  int c;

  while ((c = getLine(line, MAXLINE)) > EOF) {
      trim(line, MAXLINE);
    if (line[0] != 0) {
      printf("%s\n", line);
    }
  }
  return 0;
}

void reset(char l[], int m)
{
  int i;
  for (i=0;i<m-1;i++)
    l[i] = 0;
}

void trim(char cs[], int max)
{
  int i; // ignore the null char and offset
  for (i=(max-1);i>=0;--i) {
    if (cs[i] == '\n' || cs[i] == '\t' || cs[i] == ' ') 
      cs[i] = 0;
    else if (cs[i] != 0) 
      break; // we found a non-empty or non-whitespace 
  }
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
  int c, i;
  reset(s,lim);

  for (i=0; (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  return c;
}

