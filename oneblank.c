#include <stdio.h>

/* replace multiple spaces with a single space */

main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == '\b') {
      printf("\b");
    } else {
      putchar(c);
    }
  }
}
