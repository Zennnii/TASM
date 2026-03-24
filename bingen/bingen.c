#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "../tasm.h"
#include "../parser/parser.h"
#include "../utils/utils.h"
#include "instr_emit/instr_emit.h"

uint8_t get_register_index(char *reg) {
    to_uppercase(reg);

    if (strcmp(reg, "R0") == 0) return REG_R0;
    if (strcmp(reg, "R1") == 0) return REG_R1;
    if (strcmp(reg, "R2") == 0) return REG_R2;
    if (strcmp(reg, "R3") == 0) return REG_R3;
    if (strcmp(reg, "R4") == 0) return REG_R4;
    if (strcmp(reg, "R5") == 0) return REG_R5;
    if (strcmp(reg, "R6") == 0) return REG_R6;
    if (strcmp(reg, "R7") == 0) return REG_R7;

    fprintf(stderr, "Unknown register: %s\n", reg);
    exit(1);
}

// Generate binary for a single line
void generate_binary(InstructionType instr_type, char *line, FILE *out) {
    trim_whitespace(line);

    // Make commas behave like spaces: "ADD R1, R2" -> "ADD R1  R2"
    for (char *p = line; *p; p++) {
        if (*p == ',') *p = ' ';
    }

    switch (instr_type) {
        case INSTR_ADD: {
            emit_add(line, out);

            break;
        }

        case INSTR_ADDI: {
            emit_addi(line, out);

            break;
        }

        case INSTR_INC: {
            emit_inc(line, out);

            break;
        }

        case INSTR_DEC: {
            emit_dec(line, out);

            break;
        }

        case INSTR_CMP: {
            emit_cmp(line, out);

            break;
        }

        case INSTR_CMPI: {
            emit_cmpi(line, out);

            break;
        }

        case INSTR_MOV: {
            emit_mov(line, out);

            break;
        }

        case INSTR_MOVI: {
            emit_movi(line, out);

            break;
        }

        case INSTR_LDR: {
            emit_ldr(line, out);

            break;
        }

        case INSTR_LDRI: {
            emit_ldri(line, out);

            break;
        }

        case INSTR_STR: {
            emit_str(line, out);

            break;
        }

        case INSTR_STRI: {
            emit_stri(line, out);

            break;
        }

        case INSTR_OUT: {
            emit_out(line, out);
            
            break;
        }

        case INSTR_OUTI: {
            emit_outi(line, out);

            break;
        }

        case INSTR_HLT: {
            emit_hlt(out);

            break;
        }

        case INSTR_UNKNOWN: {
            fprintf(stderr, "Unknown instruction: %s\n", line);
            break;
        }

        case INSTR_EMPTY: {
            break;
        }

        default: {
            fprintf(stderr, "Unsupported instruction: %s\n", line);
            exit(1);
        }
    }
}