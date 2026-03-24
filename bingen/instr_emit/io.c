#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "instr_emit.h"

void emit_out(char *line, FILE *out) {
    int port;
    char reg_str[4];

    if (sscanf(line, "%*s %i %3s", &port, reg_str) != 2) {
        fprintf(stderr, "Invalid OUT instruction: %s\n", line);
        exit(1);
    }

    uint8_t port8 = (uint8_t)port;
    uint8_t reg = get_register_index(reg_str);

    fputc(OP_OUT, out);
    fputc(port8, out);
    fputc(reg, out);
}

void emit_outi(char *line, FILE *out) {
    int port;
    int value;

    if (sscanf(line, "%*s %i %d", &port, &value) != 2) {
        fprintf(stderr, "Invalid OUTI instruction: %s\n", line);
        exit(1);
    }

    uint8_t port8 = (uint8_t)port;
    uint16_t val16 = (uint16_t)value;

    fputc(OP_OUTI, out);
    fputc(port8, out);
    fputc(val16 & 0xFF, out);
    fputc((val16 >> 8) & 0xFF, out);
}