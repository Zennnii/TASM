#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void trim_newline(char *s) {
    char *p = strchr(s, '\n');
    if (p) *p = '\0';
}

// trim leading/trailing whitespace and CR/LF
void trim_whitespace(char *s) {
    size_t len = strlen(s);
    // Trim trailing \r and \n
    while (len > 0 && (s[len-1] == '\n' || s[len-1] == '\r')) {
        s[len-1] = '\0';
        len--;
    }
    // Trim trailing spaces/tabs
    while (len > 0 && isspace((unsigned char)s[len-1])) {
        s[len-1] = '\0';
        len--;
    }
    // Trim leading spaces/tabs
    char *start = s;
    while (*start && isspace((unsigned char)*start)) start++;
    if (start != s) memmove(s, start, strlen(start)+1);
}

// Utility: strip outer parentheses if present
void strip_outer_parentheses(char *s) {
    trim_whitespace(s);
    size_t len = strlen(s);
    if (len >= 2 && s[0] == '(' && s[len-1] == ')') {
        memmove(s, s+1, len-2);
        s[len-2] = '\0';
    }
}

void to_uppercase(char *dst, const char *src) {
    if (!dst || !src) return;

    while (*src) {
        *dst = toupper((unsigned char)*src);
        dst++;
        src++;
    }

    *dst = '\0';
}
int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_';
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_number(const char *s) {
    if (strncmp(s, "0x", 2) == 0 || strncmp(s, "0X", 2) == 0) {
        s += 2;
        if (*s == '\0') return 0;

        while (*s) {
            if (!isxdigit(*s)) return 0;
            s++;
        }
        return 1;
    }

    // decimal
    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}

int is_hex_digit(char c) {
    return (c >= '0' && c <= '9') ||
           (c >= 'a' && c <= 'f') ||
           (c >= 'A' && c <= 'F');
}