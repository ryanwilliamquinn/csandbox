#include <stdio.h>

/* copy input to output; 1st version */

main()
{
  double chars = 0;

  for (; getchar() != EOF; chars++)
    ;
  printf("%.0f\n", chars);
  /*
  while (getchar() != EOF) 
    ++chars;
    printf("%ld\n", chars);
  */

}
