#include <stdio.h>

/* copy input to output; 1st version */

main()
{
  long lines = 0;
  long tabs = 0;
  long blanks = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\n') { ++lines; }
    else if (c == ' ') { ++ blanks; }
    else if (c == '\t') { ++ tabs; }
    
  }
    printf("%ld lines, %ld tabs, %ld blanks\n", lines, tabs, blanks);

}
