#pragma once

#include "../utils/utils.h"

typedef enum {
    TOK_IDENT,
    TOK_NUMBER,
    TOK_COLON,
    TOK_COMMA,
    TOK_EOF
} TokenType;

typedef struct {
    TokenType type;
    char text[64];
} Token;

int lex_line(const char *line, Token *tokens, int max_tokens);
Token* next(Token *t, int *i, int n);