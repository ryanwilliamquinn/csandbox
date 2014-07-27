#include <stdio.h>

/* classes = 0-9 digits, ' ', \t, \n, other chars */
main()
{
  int c, i, nw, other;
  int ndigit[10];
  nw = other = 0;

  for (i = 0; i < 10; i++) 
    ndigit[i] = 0;
  
  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9')  
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\t' || c == '\n')
      ++nw;
    else 
      ++other;
  }

  printf("%s", "number of blanks:");
  while (nw-- > 0) {
    putchar('*');
  }
  printf("\n");
  printf("%s", "number of other:");
  while (other-- >0) {
    putchar('*');
  }
  for (int i = 0; i < 10; i++) {
    printf("\n");
    printf("%s %d", "number of digit", i);
    while (ndigit[i]-- > 0) {
      putchar('*');
    }
  }


}
