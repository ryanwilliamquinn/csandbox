#include <stdio.h>
/*
 write a for loop like this but without && or || operators
    for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
 */

#define MAXLINE 100

int main(void)
{
    char s[MAXLINE];
    int lim = MAXLINE;
    int i;
    char c;
    // for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
    //    s[i] = c;
    for (i=0; i<lim-1; ++i)
    {
        c = getchar();
        if ( c == '\n')
            break;
        if (c == EOF)
            break;
        s[i] = c;
    }

    printf("line: %s", s);
}
