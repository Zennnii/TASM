#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "../utils/utils.h"

int lex_line(const char *line, Token *tokens, int max_tokens) {
    int i = 0;
    int t = 0;

    memset(tokens, 0, sizeof(Token) * max_tokens);

    while (line[i] != '\0') {

        if (t >= max_tokens) break;

        // skip whitespace
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\r') {
            i++;
            continue;
        }

        // comma
        if (line[i] == ',') {
            tokens[t].type = TOK_COMMA;
            strcpy(tokens[t].text, ",");
            t++;
            i++;
            continue;
        }

        // colon
        if (line[i] == ':') {
            tokens[t].type = TOK_COLON;
            strcpy(tokens[t].text, ":");
            t++;
            i++;
            continue;
        }

        // Ident (instructions, registers, labels)
        if (is_alpha(line[i])) {
            int start = i;

            while (is_alpha(line[i]) || is_digit(line[i]) || line[i] == '_') {
                i++;
            }

            int len = i - start;
            
            if (len >= (int)sizeof(tokens[t].text))
                len = sizeof(tokens[t].text) - 1;

            tokens[t].type = TOK_IDENT;
            memcpy(tokens[t].text, line + start, len);
            tokens[t].text[len] = '\0';

            t++;
            continue;
        }

        // Hex numbers
        if (line[i] == '0' && (line[i+1] == 'x' || line[i+1] == 'X')) {
            int start = i;
            i += 2;

            while (is_hex_digit(line[i])) i++;

            int len = i - start;

            if (len >= (int)sizeof(tokens[t].text))
                len = sizeof(tokens[t].text) - 1;

            tokens[t].type = TOK_NUMBER;
            memcpy(tokens[t].text, line + start, len);
            tokens[t].text[len] = '\0';

            t++;
            continue;
        }

        // Decimal numbers
        if (is_digit(line[i]) || (line[i] == '-' && is_digit(line[i+1]))) {
            int start = i;

            if (line[i] == '-') i++;

            while (is_digit(line[i])) i++;

            int len = i - start;

            if (len >= (int)sizeof(tokens[t].text))
                len = sizeof(tokens[t].text) - 1;

            tokens[t].type = TOK_NUMBER;
            memcpy(tokens[t].text, line + start, len);
            tokens[t].text[len] = '\0';

            t++;
            continue;
        }

        // unknown char -> skip
        i++;
    }

    return t;
}

// helper: skip commas
Token* next(Token *t, int *i, int n) {
    while (*i < n && t[*i].type == TOK_COMMA) (*i)++;

    if (*i >= n) return NULL;

    return &t[(*i)++];
}