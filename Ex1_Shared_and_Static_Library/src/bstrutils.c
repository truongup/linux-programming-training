#include "strutils.h"

void str_reverse(char *str) {
    if (!str) return;
    int left = 0;
    int right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}


void str_trim(char *str) {
    if (!str) return;

    char *start = str;
    char *end = str + strlen(str) - 1;

    // skip leading whitespace
    while (*start && isspace((unsigned char)*start)) start++;

    // skip trailing whitespace
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';

    // move result to the front
    if (start != str) {
        memmove(str, start, end - start + 2); // +1 for '\0', +1 for inclusive
    }
}

bool str_to_int(const char *str, int *out) {
    if (!str || !out) return false;

    long result = 0;
    int sign = 1;

    // skip whitespace
    while (isspace((unsigned char)*str)) str++;

    // sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // must start with a digit
    if (!isdigit((unsigned char)*str)) return false;

    while (*str && isdigit((unsigned char)*str)) {
        result = result * 10 + (*str - '0');

        // overflow detection
        if (sign == 1 && result > INT_MAX) return false;
        if (sign == -1 && -result < INT_MIN) return false;

        str++;
    }

    // No invalid characters allowed after number (only whitespace)
    while (*str) {
        if (!isspace((unsigned char)*str)) return false;
        str++;
    }

    *out = (int)(result * sign);
    return true;
}
