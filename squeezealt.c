#include <stdio.h>

/*
 * Write an alternate version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2
 *
 * squeeze("abcda", "ac") -> "bd"
 */

void altsqueeze(char s[], char t[]);

int main(void)
{
    char text[] = "ryan";
    char orig[] = "ryan";
    char exclude[] = "ra";
    altsqueeze(text, exclude);
    printf("input: %s, remove string: %s, result: %s", orig, exclude, text);
}

void altsqueeze(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
    {
        int include = 1;
        int k;
        for (k = 0; t[k] != '\0'; k++)
            if (s[i] == t[k])
            {
                include = 0;
                break;
            }
        if (include)
            s[j++] = s[i]; 
    }
    s[j] = '\0';
}
