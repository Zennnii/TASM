#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "instr_emit.h"

void emit_out(Token *t, int n, int line ,FILE *out) {
    int i = 1;

    Token *port = next(t, &i, n);
    Token *r1   = next(t, &i, n);

    if (!port || !r1) {
        fprintf(stderr, "[Line %i] Invalid OUT instruction\n", line);
        exit(1);
    }

    if (!is_number(port->text)) {
        fprintf(stderr, "[Line %i] OUT expects immediate port\n", line);
        exit(1);
    }

    char c = r1->text[0];
    if (c != 'r' && c != 'R') {
        fprintf(stderr, "[Line %i] OUT expects register\n", line);
        exit(1);
    }

    uint8_t port8 = (uint8_t)strtol(port->text, NULL, 0);
    uint8_t reg   = get_register_index(r1->text);

    fputc(OP_OUT, out);
    fputc(port8, out);
    fputc(reg, out);
}

void emit_outi(Token *t, int n, int line, FILE *out) {
    int i = 1;

    Token *port = next(t, &i, n);
    Token *imm  = next(t, &i, n);

    if (!port || !imm) {
        fprintf(stderr, "[Line %i] Invalid OUTI instruction\n", line);
        exit(1);
    }
    
    int port_val;
    int imm_val;

    if (!parse_imm(port->text, &port_val)) {
        fprintf(stderr, "[Line %i] OUTI expects immediate port, got '%s'\n",
                line, port->text);
        exit(1);
    }

    if (!parse_imm(imm->text, &imm_val)) {
        fprintf(stderr, "[Line %i] OUTI expects immediate value, got '%s'\n",
                line, imm->text);
        exit(1);
    }   

    uint8_t port8 = (uint8_t)port_val;
    uint16_t val16 = (uint16_t)imm_val;

    fputc(OP_OUTI, out);
    fputc(port8, out);
    fputc(val16 & 0xFF, out);
    fputc((val16 >> 8) & 0xFF, out);
}