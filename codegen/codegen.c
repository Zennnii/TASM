#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include "../tasm.h"
#include "../parser/parser.h"
#include "../utils/utils.h"
#include "instr_emit/instr_emit.h"

uint8_t get_register_index(const char *reg) {
    char tmp[8];
    to_uppercase(tmp, reg);

    if (strcmp(tmp, "R0") == 0) return REG_R0;
    if (strcmp(tmp, "R1") == 0) return REG_R1;
    if (strcmp(tmp, "R2") == 0) return REG_R2;
    if (strcmp(tmp, "R3") == 0) return REG_R3;
    if (strcmp(tmp, "R4") == 0) return REG_R4;
    if (strcmp(tmp, "R5") == 0) return REG_R5;
    if (strcmp(tmp, "R6") == 0) return REG_R6;
    if (strcmp(tmp, "R7") == 0) return REG_R7;

    fprintf(stderr, "Unknown register: %s\n", reg);
    exit(1);
}

// Generate binary for a single line
void generate_binary(InstructionType instr_type, Token *t, int n, int line, SymbolTable *st, FILE *out) {

    switch (instr_type) {
        case INSTR_ADD: {
            emit_add(t, n, line, out);

            break;
        }

        case INSTR_ADDI: {
            emit_addi(t, n, line, out);

            break;
        }

        case INSTR_INC: {
            emit_inc(t, n, line, out);

            break;
        }

        case INSTR_DEC: {
            emit_dec(t, n, line, out);

            break;
        }

        case INSTR_CMP: {
            emit_cmp(t, n, line, out);

            break;
        }

        case INSTR_CMPI: {
            emit_cmpi(t, n, line, out);

            break;
        }

        case INSTR_MOV: {
            emit_mov(t, n, line, out);

            break;
        }

        case INSTR_MOVI: {
            emit_movi(t, n, line, out);

            break;
        }

        case INSTR_LDR: {
            emit_ldr(t, n, line, out);

            break;
        }

        case INSTR_LDRI: {
            emit_ldri(t, n, line, out);

            break;
        }

        case INSTR_STR: {
            emit_str(t, n, line, out);

            break;
        }

        case INSTR_STRI: {
            emit_stri(t, n, line, out);

            break;
        }

        case INSTR_OUT: {
            emit_out(t, n, line, out);
            
            break;
        }

        case INSTR_OUTI: {
            emit_outi(t, n, line, out);

            break;
        }

        case INSTR_HLT: {
            emit_hlt(out);

            break;
        }

        case INSTR_JMP: {
            emit_jmp(t, n, line, st, out);

            break;
        }

        case INSTR_JZ: {
            emit_jz(t, n, line, st, out);

            break;
        }

        case INSTR_JNZ: {
            emit_jnz(t, n, line, st, out);

            break;
        }

        case INSTR_JN: {
            emit_jn(t, n, line, st, out);

            break;
        }

        case INSTR_JNN: {
            emit_jnn(t, n, line, st, out);

            break;
        }

        case INSTR_JC: {
            emit_jc(t, n, line, st, out);

            break;
        }

        case INSTR_JNC: {
            emit_jnc(t, n, line, st, out);

            break;
        }

        case INSTR_JV: {
            emit_jv(t, n, line, st, out);

            break;
        }

        case INSTR_JNV: {
            emit_jnv(t, n, line, st, out);

            break;
        }

        case INSTR_UNKNOWN: {
            fprintf(stderr, "[Line %i] Unknown instruction\n", line);
            break;
        }

        case INSTR_EMPTY: {
            break;
        }

        default: {
            fprintf(stderr, "[Line %i] Unsupported instruction\n", line);
            exit(1);
        }
    }
}