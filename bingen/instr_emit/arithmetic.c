#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "instr_emit.h"

void emit_add(char *line, FILE *out) {
    char r1_str[4], r2_str[4];

    if (sscanf(line, "%*s %3s %3s", r1_str, r2_str) != 2) {
        fprintf(stderr, "Invalid ADD instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1_str);
    uint8_t reg2 = get_register_index(r2_str);

    fputc(OP_ADD, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_addi(char* line, FILE *out) {
    char r1_str[4];
    int imm;

    if (sscanf(line, "%*s %3s %d", r1_str, &imm) != 2) {
        fprintf(stderr, "Invalid ADDI instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1_str);
    uint16_t imm16 = (uint16_t)imm;

    fputc(OP_ADDI, out);
    fputc(reg1, out);
    fputc(imm16 & 0xFF, out);
    fputc((imm16 >> 8) & 0xFF, out);
}

void emit_inc(char* line, FILE *out) {
    char r1_str[4];

    if (sscanf(line, "%*s %3s", r1_str) != 1) {
        fprintf(stderr, "Invalid INC instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1_str);

    fputc(OP_INC, out);
    fputc(reg1, out);    
}

void emit_dec(char* line, FILE *out) {
    char r1_str[4];

    if (sscanf(line, "%*s %3s", r1_str) != 1) {
        fprintf(stderr, "Invalid DEC instruction: %s\n", line);
        exit(1);
    }
    
    uint8_t reg1 = get_register_index(r1_str);

    fputc(OP_DEC, out);
    fputc(reg1, out);
}

void emit_cmp(char* line, FILE *out) {
    char r1_str[4], r2_str[4];

    if (sscanf(line, "%*s %3s %3s", r1_str, r2_str) != 2) {
        fprintf(stderr, "Invalid CMP instruction: %s\n", line);
        exit(1);
        }

    uint8_t reg1 = get_register_index(r1_str);
    uint8_t reg2 = get_register_index(r2_str);

    fputc(OP_CMP, out);
    fputc(reg1, out);
    fputc(reg2, out);
}

void emit_cmpi(char* line, FILE *out) {
    char r1_str[4];
    int imm;

    if (sscanf(line, "%*s %3s %d", r1_str, &imm) != 2) {
        fprintf(stderr, "Invalid CMPI instruction: %s\n", line);
        exit(1);
    }

    uint8_t reg1 = get_register_index(r1_str);
    uint16_t imm16 = (uint16_t)imm;

    fputc(OP_CMPI, out);
    fputc(reg1, out);
    fputc(imm16 & 0xFF, out);
    fputc((imm16 >> 8) & 0xFF, out);
}
