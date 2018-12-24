#include <stdio.h>
#include <string.h>

/*
 * Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through nine, a through f, and A through F.
 */

int htoi(char s[]);
int topow(int num, int pow);

int main(void)
{
    htoi("0x1");
    htoi("0xf");
    htoi("0x101");
    htoi("0XFFF");
}

// input is a hex string like 0xa2F1 or 1234
// output is a decimal number
int htoi(char s[])
{
    // need length of the array because we have to start from the little end
    int len = strlen(s);
    int i;
    int sum = 0;
    int place = 0;
    char c;
    int val;
    int res;
    // skip the null terminator
    for (i = len - 1; i > 0; i--)
    {
        c = s[i];
        // printf("char is: %c\n", c);
        if (c == 'x' || c == 'X')
            break;
        if (c >= 'a' && c <= 'f')
            val = (c - 'a') + 10;
        else if (c >= 'A' && c <= 'F')
            val = (c - 'A') + 10;
        else
            val = c - '0';
        res = topow(place, 16);
        // printf("power result, %d, %d, %d\n", place, 16, res);
        sum = sum + val * res;
        ++place;
    }
    printf("input hex: %s, decimal %d\n", s, sum);
    return 0;
}

int topow(int num, int pow)
{
    int sum = 1;
    for (int i = num; i > 0; i--)
        sum = sum * pow;
    return sum;
}
