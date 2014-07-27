#include <stdio.h>

/* copy input to output; 1st version */

main()
{
  long chars = 0;
  long lines = 0;
  int c;

  while ((c = getchar()) != EOF) {
    ++chars;
    if (c == '\n') 
      ++lines;
  }
    printf("%ld chars, %ld lines\n", chars, lines);

}
