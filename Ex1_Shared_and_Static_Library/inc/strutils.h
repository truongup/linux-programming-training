#ifndef STR_UTILS_H
#define STR_UTILS_H

#include <stdio.h>
#include <stdbool.h>

#include <string.h>
#include <ctype.h>
#include <limits.h>

void str_reverse(char *str);
void str_trim(char *str);
bool str_to_int(const char *str, int *out);

#endif
