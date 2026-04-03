#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "instr_emit.h"

void emit_add(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *r2 = next(t, &i, n);

    if (!r1 || !r2) {
        fprintf(stderr, "[Line %i] Invalid ADD instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint8_t reg2 = get_register_index(r2->text);

    fputc(OP_ADD, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_addi(Token *t, int n, int line ,FILE *out) { 
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *imm = next(t, &i, n);

    if (!r1 || !imm || imm->type != TOK_NUMBER) {
        fprintf(stderr, "[Line %i] Invalid ADDI instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint16_t imm16 = (uint16_t)atoi(imm->text);

    fputc(OP_ADDI, out);
    fputc(reg1, out);
    fputc(imm16 & 0xFF, out);
    fputc((imm16 >> 8) & 0xFF, out);
}

void emit_inc(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);

    if (!r1) {
        fprintf(stderr, "[Line %i] Invalid INC instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);

    fputc(OP_INC, out);
    fputc(reg1, out);    
}

void emit_dec(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);

    if (!r1) {
        fprintf(stderr, "[Line %i] Invalid DEC instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);

    fputc(OP_DEC, out);
    fputc(reg1, out);  
}

void emit_cmp(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *r2 = next(t, &i, n);

    if (!r1 || !r2) {
        fprintf(stderr, "[Line %i] Invalid CMP instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint8_t reg2 = get_register_index(r2->text);

    fputc(OP_CMP, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_cmpi(Token *t, int n, int line ,FILE *out) {
    int i = 1; // skip opcode

    Token *r1 = next(t, &i, n);
    Token *imm = next(t, &i, n);

    if (!r1 || !imm || imm->type != TOK_NUMBER) {
        fprintf(stderr, "[Line %i] Invalid CMPI instruction\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1->text);
    uint16_t imm16 = (uint16_t)atoi(imm->text);

    fputc(OP_CMPI, out);
    fputc(reg1, out);
    fputc(imm16 & 0xFF, out);
    fputc((imm16 >> 8) & 0xFF, out);
}
