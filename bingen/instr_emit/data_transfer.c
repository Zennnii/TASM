#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "instr_emit.h"

void emit_mov(char *line, FILE *out) {
    char dest[4], src[4];

    if (sscanf(line, "%*s %3s %3s", dest, src) != 2) {
        fprintf(stderr, "Invalid MOV instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(dest);
    uint8_t reg2 = get_register_index(src);

    fputc(OP_MOV, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_movi(char *line, FILE *out) {
    char dest[4];
    int imm;
    if (sscanf(line, "%*s %3s %d", dest, &imm) != 2) {
        fprintf(stderr, "Invalid MOVI instruction: %s\n", line);
        exit(1);
    }
    
    uint8_t reg1 = get_register_index(dest);
    uint16_t imm16 = (uint16_t)imm;

    fputc(OP_MOVI, out);
    fputc(reg1, out);
    fputc(imm16 & 0xFF, out);
    fputc((imm16 >> 8) & 0xFF, out);
}

void emit_ldr(char *line, FILE *out) {
    char dest[4], src[4];

    if (sscanf(line, "%*s %3s %3s", dest, src) != 2) {
        fprintf(stderr, "Invalid LDR instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(dest);
    uint8_t reg2 = get_register_index(src);

    fputc(OP_LDR, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_ldri(char *line, FILE *out) {
    char dest[4], base[4];
    int offset;

    if (sscanf(line, "%*s %3s %3s %d", dest, base, &offset) != 3) {
        fprintf(stderr, "Invalid LDRI instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(dest);
    uint8_t reg2 = get_register_index(base);
    uint16_t off16 = (uint16_t)offset;

    fputc(OP_LDRI, out);
    fputc(reg1, out);
    fputc(reg2, out);
    fputc(off16 & 0xFF, out);
    fputc((off16 >> 8) & 0xFF, out);
}

void emit_str(char *line, FILE *out) {
    char src[4], base[4];

    if (sscanf(line, "%*s %3s %3s", src, base) != 2) {
        fprintf(stderr, "Invalid STR instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(src);
    uint8_t reg2 = get_register_index(base);

    fputc(OP_STR, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_stri(char *line, FILE *out) {
    char src[4], base[4];
    int offset;
    
    if (sscanf(line, "%*s %3s %3s %d", src, base, &offset) != 3) {
        fprintf(stderr, "Invalid STRI instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(src);
    uint8_t reg2 = get_register_index(base);
    uint16_t off16 = (uint16_t)offset;

    fputc(OP_STRI, out);
    fputc(reg1, out);
    fputc(reg2, out);
    fputc(off16 & 0xFF, out);
    fputc((off16 >> 8) & 0xFF, out);
}