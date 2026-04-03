#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "instr_emit.h"

void emit_mov(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *r2 = next(t, &i, n);

    if (!r1 || !r2) {
        fprintf(stderr, "[Line %i] Invalid MOV instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint8_t reg2 = get_register_index(r2->text);

    fputc(OP_MOV, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_movi(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *imm = next(t, &i, n);

    if (!r1 || !imm || imm->type != TOK_NUMBER) {
        fprintf(stderr, "[Line %i] Invalid MOVI instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint16_t imm16 = (uint16_t)atoi(imm->text);

    fputc(OP_MOVI, out);
    fputc(reg1, out);
    fputc(imm16 & 0xFF, out);
    fputc((imm16 >> 8) & 0xFF, out);
}

void emit_ldr(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *r2 = next(t, &i, n);

    if (!r1 || !r2) {
        fprintf(stderr, "[Line %i] Invalid LDR instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint8_t reg2 = get_register_index(r2->text);

    fputc(OP_LDR, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_ldri(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *r2 = next(t, &i, n);
    Token *imm = next(t, &i, n);

    if (!r1 || !imm || imm->type != TOK_NUMBER) {
        fprintf(stderr, "[Line %i] Invalid LDRI instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint8_t reg2 = get_register_index(r2->text);
    uint16_t off16 = (uint16_t)atoi(imm->text);

    fputc(OP_LDRI, out);
    fputc(reg1, out);
    fputc(reg2, out);
    fputc(off16 & 0xFF, out);
    fputc((off16 >> 8) & 0xFF, out);
}

void emit_str(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *r2 = next(t, &i, n);

    if (!r1 || !r2) {
        fprintf(stderr, "[Line %i] Invalid STR instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint8_t reg2 = get_register_index(r2->text);

    fputc(OP_STR, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_stri(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *r2 = next(t, &i, n);
    Token *imm = next(t, &i, n);

    if (!r1 || !imm || imm->type != TOK_NUMBER) {
        fprintf(stderr, "[Line %i] Invalid STRI instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint8_t reg2 = get_register_index(r2->text);
    uint16_t off16 = (uint16_t)atoi(imm->text);

    fputc(OP_STRI, out);
    fputc(reg1, out);
    fputc(reg2, out);
    fputc(off16 & 0xFF, out);
    fputc((off16 >> 8) & 0xFF, out);
}