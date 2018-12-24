#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(void)
{
    printf("header values:\n");
    printf("signed long max: %ld\n", LONG_MAX);
    printf("signed long min: %ld\n", LONG_MIN);
    printf("unsigned long max: %lud\n", ULONG_MAX);
    printf("signed long long max: %lld\n", LLONG_MAX);
    printf("signed long long min: %lld\n", LLONG_MIN);
    printf("unsigned long long max: %llud\n", ULLONG_MAX);
    printf("signed int max: %d\n", INT_MAX);
    printf("signed int min: %d\n", INT_MIN);
    printf("unsigned int max: %u\n", UINT_MAX);
    printf("signed short max: %d\n", SHRT_MAX);
    printf("signed short min: %d\n", SHRT_MIN);
    printf("unsigned short max: %u\n", USHRT_MAX);
    printf("signed char max: %d\n", CHAR_MAX);
    printf("signed char min: %d\n", CHAR_MIN);
    printf("unsigned char max: %u\n", UCHAR_MAX);
    printf("signed float max: %f\n", FLT_MAX);
    printf("signed float min: %f\n", -FLT_MAX);

    printf("\n\ncomputed values:\n");




    /*
    // computation of max/min long
    long l = LONG_MAX - CHAR_MAX;
    long maxlong = l;
    while (++l > maxlong)
        maxlong++;
    
    l = LONG_MIN + CHAR_MAX;
    long minlong = l;
    while (--l < minlong)
        minlong--;

    unsigned long ul = ULONG_MAX-CHAR_MAX;
    unsigned long maxunsignedlong = ul;
    while (++ul > maxunsignedlong)
        maxunsignedlong++;

    unsigned long long ull = ULLONG_MAX - CHAR_MAX;
    unsigned long long maxunsignedlonglong = ull;
    while (++ull > maxunsignedlonglong)
        maxunsignedlonglong++;

    printf("computed signed max long %ld\n", maxlong);
    printf("computed signed min long %ld\n", minlong);
    printf("unsigned long max: %lu\n", maxunsignedlong);
    printf("unsigned long long max: %llu\n", maxunsignedlonglong);


    // computation of max/min int
    int k = 0;
    int maxint = 0;
    while (++k > maxint)
        maxint++;
    
    k = 0;
    int minint = 0;
    while (--k < minint)
        minint--;

    unsigned int uk = 0;
    unsigned int maxunsignedint = 0;
    while (++uk > maxunsignedint)
        maxunsignedint++;

    printf("computed signed max int %d\n", maxint);
    printf("computed signed min int %d\n", minint);
    printf("unsigned int max: %u\n", maxunsignedint);

    // computation of max/min short
    short j = 0;
    short maxshort = 0;
    while (++j > maxshort)
        maxshort++;
    
    j = 0;
    short minshort = 0;
    while (--j < minshort)
        minshort--;

    unsigned short uj = 0;
    unsigned short maxunsignedshort = 0;
    while (++uj > maxunsignedshort)
        maxunsignedshort++;

    printf("computed signed max short %d\n", maxshort);
    printf("computed signed min short %d\n", minshort);
    printf("unsigned short max: %u\n", maxunsignedshort);


    // computation of max/min char
    char i = 0;
    char maxchar = 0;
    while (++i > maxchar)
        maxchar++;

    i = 0;
    char minchar = 0;
    while (--i < minchar)
        minchar = i;


    unsigned char ui = 0;
    unsigned char maxunsignedchar = 0;
    while (++ui > maxunsignedchar)
        maxunsignedchar++;

    printf("computed signed max char %d\n", maxchar);
    printf("computed signed min char %d\n", minchar);
    printf("unsigned char max: %u\n", maxunsignedchar);
    */


}


