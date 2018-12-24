#include <stdio.h>

/**
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly. 
 * C comments do not nest.
 *
 * C comments are either started with forward slash and a start
 * or by two forward slashes
 * any comment can appear on their own line, or at the end of a statement
 *
 * take the chunk that you know is escaped and replace it with a regular literal
 * then look again at the string
 */

#define MAXLINE 120 
#define ESCAPE_CHAR '\\'
#define DOUBLE_QUOTE_CHAR '"'
#define SINGLE_QUOTE_CHAR '"'

int printchars(char line[], int i, int end);
int getLine(char s[], int lim);
void clearLine(char s[], int lim);
int isSingleLineComment(char s[], int lim);
int containsSingleLineComment(char s[], int lim);
int isMultiLineCommentStart(char s[], int lim);
int isMultiLineCommentEnd(char s[], int lim);
/*
 * we can just write in one place i think
 * we just need to know:
 * the multi line comment start index
 * the multi line comment end index
 * the single line comment start index
 * if we are in a multi line comment
 *
 */

char line[MAXLINE];
int main(void)
{
    int len;
    int linecount = 0;
    int inMultiLineComment = 0;
    int multiLineCommentStartIndex;
    int multiLineCommentEndIndex;
    int singleLineCommentStartIndex;
    while ((len = getLine(line, MAXLINE)) > 0) {
        linecount++;
        // printf("%d:", linecount);
        multiLineCommentStartIndex = -1;
        multiLineCommentEndIndex = -1;
        singleLineCommentStartIndex = -1;

        // check for multi line comment start
        if (inMultiLineComment == 0)
        {
            multiLineCommentStartIndex = isMultiLineCommentStart(line, MAXLINE);
            if (multiLineCommentStartIndex != -1)
            {
                inMultiLineComment = 1;
            } 
        }

        // case for in a multi line comment
        if (inMultiLineComment == 1)
        {
            multiLineCommentEndIndex = isMultiLineCommentEnd(line, MAXLINE);
            if (multiLineCommentEndIndex > -1)
            {
                inMultiLineComment = 0;
            }
        }

        if (inMultiLineComment == 0)
        {
            singleLineCommentStartIndex = containsSingleLineComment(line, MAXLINE);
        }

         // printf("single line comment start %d,", singleLineCommentStartIndex);
         // printf("start %d, stop %d, multiline", multiLineCommentStartIndex, multiLineCommentEndIndex);
         // printf("in multi line comment %d\n", inMultiLineComment);

        // if we are in a multilinecomment, do nothing, just fall through to the end
        if (inMultiLineComment == 0)
        {
            // line has a single line comment
            if (singleLineCommentStartIndex != -1)
            {
                if (multiLineCommentStartIndex != -1)
                    printchars(line, 0, multiLineCommentStartIndex);
                if (multiLineCommentEndIndex != -1)
                    printchars(line, multiLineCommentEndIndex + 1, singleLineCommentStartIndex);
                else
                    printchars(line, 0, singleLineCommentStartIndex);

            }
            // line has a multiline comment start or end
            else if (multiLineCommentStartIndex != -1 || multiLineCommentEndIndex != -1)
            {
                if (multiLineCommentStartIndex != -1)
                    printchars(line, 0, multiLineCommentStartIndex);
                if (multiLineCommentEndIndex != -1)
                    printchars(line, multiLineCommentEndIndex + 1, MAXLINE);
            }
            else
            {
                printchars(line, 0, MAXLINE);
            }
        }
            
        clearLine(line, MAXLINE);
    }
}

int printchars(char line[], int i, int end)
{
    for (; i < end; i++)
    {
        if (line[i] == '\n')
        {
            // putchar('\n');
            break;
        }
        putchar(line[i]);
    }
    putchar('\n');
    return 0;
}

void clearLine(char s[], int lim)
{
    for(int i=0; i<lim; i++)
        s[i] = ' ';
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
  int c, i;

  for (i=0; (c=getchar()) != EOF && c != '\n'; ++i) {
    if (i < (lim-1)) { 
      s[i] = c;
    }   
  }
  return i;
}

int containsSingleLineComment(char s[], int lim)
{
    int i;
    char c;
    int isInString = 0;
    int isInCharLiteral = 0;
    char lastchar = '\0';
    int commentStartIndex = -1;
    int isLastCharEscape = 0;
    for (i=0; i<lim; ++i)
    {
        c = s[i]; 
        if (c == '\n')
            break;
        if (isLastCharEscape == 1)
        {
            isLastCharEscape = 0;
            continue;
        }
        // we found an escape character, skip it
        if (c == ESCAPE_CHAR)
        {
            isLastCharEscape = 1;
            continue;
        }
        if (c == SINGLE_QUOTE_CHAR)
        {
            if (isInCharLiteral == 1)
                isInCharLiteral = 0;
            else
                isInCharLiteral = 1;
        }
        if (c == DOUBLE_QUOTE_CHAR)
        {
            if (isInString == 1)
                isInString = 0;
            else
                isInString = 1;
        }
        if (isInString == 0 && c == '/' && lastchar == '/')
            commentStartIndex = i-1;
        lastchar = c;

    }    
    return commentStartIndex;
}

int isSingleLineComment(char s[], int lim)
{
    int i;
    char c;
    char lastchar = '\0';
    for (i=0; i<lim; ++i)
    {
        c = s[i]; 
        if (c == '/' && lastchar == '/')
            return 1;
        lastchar = c;

    }    
    return 0;
}

int isMultiLineCommentStart(char s[], int lim)
{
    int i;
    char c;
    char lastchar = '\0';
    int isInString = 0;
    int isInCharLiteral = 0;
    int multiLineCommentStartIndex = -1;
    int isLastCharEscape = 0;
    for (i=0; i<lim; ++i)
    {
        c = s[i]; 
        if (c == '\n')
            break;
        if (isLastCharEscape == 1)
        {
            isLastCharEscape = 0;
            continue;
        }
        // we found an escape character, skip it
        if (c == ESCAPE_CHAR)
        {
            isLastCharEscape = 1;
            continue;
        }
        if (c == SINGLE_QUOTE_CHAR)
        {
            if (isInCharLiteral)
                isInCharLiteral = 0;
            else
                isInCharLiteral = 1;
        }
        if (c == DOUBLE_QUOTE_CHAR)
        {
            if (isInString)
                isInString = 0;
            else
                isInString = 1;
        }
        if (isInString == 0 && isInCharLiteral == 0 && c == '*' && lastchar == '/')
        {
            multiLineCommentStartIndex = i-1;
            break;
        }
        lastchar = c;
    }    
    return multiLineCommentStartIndex;
}


int isMultiLineCommentEnd(char s[], int lim)
{
    int i;
    char c;
    char lastchar = '\0';
    int isInString = 0;
    int isInCharLiteral = 0;
    int multiLineCommentEndIndex = -1;
    int isLastCharEscape = 0;
    for (i=0; i<lim; ++i)
    {
        c = s[i]; 
        if (isLastCharEscape == 1)
        {
            isLastCharEscape = 0;
            continue;
        }
        // we found an escape character, skip it
        if (c == ESCAPE_CHAR)
        {
            isLastCharEscape = 1;
            continue;
        }
        if (c == SINGLE_QUOTE_CHAR)
        {
            if (isInCharLiteral)
                isInCharLiteral = 0;
            else
                isInCharLiteral = 1;
        }
        if (c == DOUBLE_QUOTE_CHAR)
        {
            if (isInString)
                isInString = 0;
            else
                isInString = 1;
        }
        if (isInString == 0 && isInCharLiteral == 0 && lastchar == '*' && c == '/')
        {
            multiLineCommentEndIndex = i;
            break;
        }
        lastchar = c;
    }    
    return multiLineCommentEndIndex;
}
