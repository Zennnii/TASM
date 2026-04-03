#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "tasm.h"
#include "parser/parser.h"
#include "codegen/codegen.h"
#include "lexer/lexer.h"
#include "utils/utils.h"
#include "isa/isa.h"
#include "labels/labels.h"

char line_buf[256];
FILE *out;

static int is_label_line(Token *t, int count) {
    if (!t || count <= 0) return 0;

    size_t len = strlen(t[0].text);
    return len > 0 && t[0].text[len - 1] == ':';
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s input.asm -o output\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = NULL;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            output_file = argv[i + 1];
            i++;
        }
    }

    if (!output_file) {
        fprintf(stderr, "Missing output file\n");
        return 1;
    }

    FILE *in = fopen(input_file, "r");
    out = fopen(output_file, "wb");

    if (!in || !out) {
        perror("file open");
        return 1;
    }

    SymbolTable sym;
    init_table(&sym);

    uint16_t lc = 0;
    int line = 1;

    // Pass 1
    while (fgets(line_buf, sizeof(line_buf), in)) {
        trim_newline(line_buf);
        trim_whitespace(line_buf);

        if (line_buf[0] == '\0' || line_buf[0] == ';') {
            line++;
            continue;
        }

        Token tokens[64];
        int count = lex_line(line_buf, tokens, 64);

        if (count <= 0) {
            line++;
            continue;
        }

        if (is_label(tokens, count)) {
            char name[64];

            if (tokens[1].type == TOK_IDENT || strcmp(tokens[1].text, ":") != 0) {
                snprintf(name, sizeof(name), "%s", tokens[0].text);
                name[strlen(name) - 1] = '\0';
            } else {
                snprintf(name, sizeof(name), "%s", tokens[0].text);
            }

        add_label(&sym, name, lc);

        line++;
        continue;
    }

        InstructionType type = parse_tokens(tokens, count);
        lc += instr_size(type);

        line++;
    }

    rewind(in);
    lc = 0;
    line = 1;

    // Pass 2
    while (fgets(line_buf, sizeof(line_buf), in)) {
        trim_newline(line_buf);
        trim_whitespace(line_buf);

        if (line_buf[0] == '\0' || line_buf[0] == ';') {
            line++;
            continue;
        }

        Token tokens[64];
        int count = lex_line(line_buf, tokens, 64);

        if (count <= 0) {
            line++;
            continue;
        }

        if (is_label_line(tokens, count)) {
            line++;
            continue;
        }

        InstructionType type = parse_tokens(tokens, count);

        if (type != INSTR_UNKNOWN && type != INSTR_EMPTY) {
            generate_binary(type, tokens, count, line, &sym, out);
        }

        lc += instr_size(type);
        line++;
    }

    fclose(in);
    fclose(out);

    return 0;
}