#include <stdio.h>

#define MAXSIZE 10

int main(void)
{
  int c, i, j, wordlength;
  int lengths[MAXSIZE]; 
  wordlength = 0;

  for (i = 0; i < MAXSIZE; i++)
    lengths[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') 
    {
      lengths[wordlength] = lengths[wordlength] + 1;
      wordlength = 0;
    }
    else 
      wordlength++;
  }

  for (i = 0; i < MAXSIZE; i++) {
    printf("%d: ", i);
    for (j = lengths[i]; j > 0; j--)
      putchar('|');
    putchar('\n');
  }

}
