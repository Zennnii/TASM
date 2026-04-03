#pragma once

void trim_newline(char *s);
void trim_whitespace(char *s);
void strip_outer_parentheses(char *cond);
void to_uppercase(char *dst, const char *src);
int is_alpha(char c);
int is_digit(char c);
int is_number(const char *s);
int is_hex_digit(char c);