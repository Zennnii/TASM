#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "instr_emit.h"
#include "../../labels/labels.h"

void emit_hlt(FILE *out) {
    fputc(OP_HLT, out);
}

void emit_jmp(Token *t, int n, int line, SymbolTable *st, FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);

    fputc(OP_JMP, out);
    fputc(addr & 0xFF, out);
    fputc(addr >> 8, out);
}

void emit_jz(Token *t, int n, int line, SymbolTable *st ,FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);

    fputc(OP_JZ, out);
    fputc(addr & 0xFF, out);
    fputc((addr >> 8) & 0xFF, out);
}

void emit_jnz(Token *t, int n, int line, SymbolTable *st ,FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);

    fputc(OP_JNZ, out);
    fputc(addr & 0xFF, out);
    fputc((addr >> 8) & 0xFF, out);
}

void emit_jn(Token *t, int n, int line, SymbolTable *st ,FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);

    fputc(OP_JN, out);
    fputc(addr & 0xFF, out);
    fputc((addr >> 8) & 0xFF, out);
}

void emit_jnn(Token *t, int n, int line, SymbolTable *st ,FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);

    fputc(OP_JNN, out);
    fputc(addr & 0xFF, out);
    fputc((addr >> 8) & 0xFF, out);
}

void emit_jc(Token *t, int n, int line, SymbolTable *st ,FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);

    fputc(OP_JC, out);
    fputc(addr & 0xFF, out);
    fputc((addr >> 8) & 0xFF, out);
}

void emit_jnc(Token *t, int n, int line, SymbolTable *st ,FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);

    fputc(OP_JNC, out);
    fputc(addr & 0xFF, out);
    fputc((addr >> 8) & 0xFF, out);
}

void emit_jv(Token *t, int n, int line, SymbolTable *st ,FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);
    fputc(OP_JV, out);
    fputc(addr & 0xFF, out);
    fputc((addr >> 8) & 0xFF, out);
}

void emit_jnv(Token *t, int n, int line, SymbolTable *st ,FILE *out) {
    int i = 1;

    Token *op = next(t, &i, n);

    if (!op) {
        fprintf(stderr, "[Line %d] Invalid JMP\n", line);
        exit(1);
    }

    uint16_t addr = resolve_operand(st, op);

    fputc(OP_JNV, out);
    fputc(addr & 0xFF, out);
    fputc((addr >> 8) & 0xFF, out);
}