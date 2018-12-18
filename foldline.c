#include <stdio.h>

int printchars(int start, int maxLength, char currentLine[], int isNewLine);
int process(char c);

int main(void)
{
    int isNewLine = 1;
    int maxLength = 5;
    int c,i,start;
    i = start = 0;
    char currentLine[maxLength];

    while((c = getchar()) != EOF)
    {
        // printf("i: %d\n, c: %d\n", i, c);
        // check if we are at the end of a line
        // think about the boundary condition here. does \n count in the line length? for now, no.
        if (c == '\n')
        {
            // printf("in newline block\n");
            // printf("i: %d, start: %d\n", i, start);
            printchars(start, i, currentLine, isNewLine);
            putchar('\n');
            isNewLine = 1;
            i = 0;
            start = 0;
            continue;
        }

        // if we are at maxLength, check if we had any spaces previously
        // if we had previous spaces, print a new line and continue with start set to 0
        // and i set to i - start
        // if we didn't have a space, print out the line, print a new line, set i and start to 0
        if (i == maxLength)
        {
            // printf("in maxlength block\n");
            if (start == 0)
            {
                printchars(start, i, currentLine, isNewLine);
                putchar('\n');
                isNewLine = 1;
                i = 0;
            }
            else
            {
                putchar('\n');
                isNewLine = 1;
                printchars(start, i, currentLine, isNewLine);
                isNewLine = 0;
                start = i;
            }
        } 
        else if (c == ' ' || c == '\t')
        // check if we are a space?
        // todo how to handle different tab widths?
        {
            // printf("in space block\n");
            printchars(start, i, currentLine, isNewLine);
            isNewLine = 0;
            start = i;
        }
        // printf("adding to currentline\n");
        // printf("adding c %d in %d position\n", c, i);
        currentLine[i] = c;
        i++;
    }
}

int printchars(int index, int maxLength, char currentLine[], int isNewLine)
{
    int start = index;
    for (;index < maxLength; index++)
    {

        if (isNewLine && start == index && currentLine[index] == ' ')
            continue;
        putchar(currentLine[index]);
    }
    return 0;
}
