#include <stdio.h>

/* 
  Replaces tabs in the input with the proper number of blanks to space to the next tab stop.
  Assume a fixed set of tab stops, say every n columns.  Should n be a variable or a symbolic parameter? 
*/

static const int tabstop = 4;

int main ()
{
    int c, i;
    int column;
    column = 0;
    while ((c = getchar()) != EOF) 
    {
        if (c == '\t') {
            for (i=(tabstop - column); i > 0; i--) 
            {
                // printf("%d", i);
                putchar('|');
                column++;
            }
        }
        else
            putchar(c);

        if (column < (tabstop - 1) && column != '\n') 
            column++;
        else
            column = 0;
    }
    return 0;
}



