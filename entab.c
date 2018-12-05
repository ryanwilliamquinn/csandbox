#include <stdio.h>

/*
   Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks
   to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank
   would suffice to reach a tab stop, which should be given preference? 
 */

/*
    column is the current 0-based index
    for instance if we read 4 letters 4 spaces and a letter, column will be 8 when we are processing the final letter
    column is incremented at the end of the while loop
    if tabstop was 3 in this case, we would print a tab and two spaces. we would do this because we can calculate the starting
    column, 4 (current column minus num spaces 8-4), and the next tabstop after 4 (tabstop - (column % tabstop) + starting column = 3 - (4 % 3) + 4) = 6. since the next tabstop is more than one space away, we print a tab, and then repeat. now starting column is 6, the next tabstop is 9, and numspaces is 2. since we don't have enough spaces to make it to the tabstop, we print out the spaces, and then the non-space character. 
    
*/
void insertspaces(int numspaces, int column, int tabstop);

int main(void)
{
    // check if we are at a tabstop
    int c;
    int tabstop = 4;
    int column = 0;
    int numspaces = 0;

    while((c = getchar()) != EOF)
    {

        if (c == ' ')
            numspaces++;
        else
        {
            if (numspaces > 0)
                insertspaces(numspaces, column, tabstop);
            putchar(c);
            numspaces = 0;
            if (c == '\n')
                column = 0;
        }
        if (c == '\n')
        {
            column = 0;
            numspaces = 0;
        }
        else 
            column++;
    }

}

void insertspaces(int numspaces, int column, int tabstop)
{
    if (numspaces == 1)
        putchar('<');
    else if (numspaces > 1)
    {
        int initialcolumn = column - numspaces;
        int firsttabstop = tabstop - (initialcolumn % tabstop) + initialcolumn;
        int spacestotabstop = firsttabstop - initialcolumn;
        // if we are on a tabstop, look we need to make it to the next one
        if (spacestotabstop == 0)
            spacestotabstop = tabstop;
        
        if (spacestotabstop <= numspaces)
        {
            putchar('|');
            numspaces = numspaces - spacestotabstop;
            column = column + tabstop;
            insertspaces(numspaces, column, tabstop);
        }
        else 
            for (; numspaces > 0; numspaces--)
                putchar('>');
    }

}
