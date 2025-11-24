#include "strutils.h"

int main() {
    char str1[] = "Hello World";
    str_reverse(str1);
    printf("Reversed: %s\n", str1);

    char str2[] = "   Hi GIANG TRUONG   ";
    str_trim(str2);
    printf("Trimmed: '%s'\n", str2);

    int value;
    if (str_to_int(" -12345 ", &value))
        printf("Converted: %d\n", value);
    else
        printf("Invalid integer!\n");

    return 0;
}
