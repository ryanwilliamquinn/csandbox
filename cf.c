#include <stdio.h>

/* print fahrenheit-celsius table
  for fahr = 0, 20, ..., 300 */

int cfconvert(int c);

main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = -20;
  upper = 200;
  step = 20;      /* step size */

  celsius = lower;
  printf("c\t%6s\n","fahr");
  while (celsius <= upper) {
    fahr = cfconvert(celsius);
    printf("%6.1f\t%6.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}

cfconvert(float celsius)
{
    return (9.0/5.0) * celsius + 32.0;
}
