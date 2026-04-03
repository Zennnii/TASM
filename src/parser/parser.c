#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.h"
#include "../utils/utils.h"

InstructionType parse_tokens(Token *t, int n) {
    if (n == 0) return INSTR_EMPTY;
    if (t[0].type != TOK_IDENT) return INSTR_UNKNOWN;

    char opcode[64];
    strcpy(opcode, t[0].text);
    to_uppercase(opcode, t[0].text);

    for (int i = 0; i < table_size; i++) {
        if (strcmp(opcode, table[i].name) == 0)
            return table[i].type;
    }

    return INSTR_UNKNOWN;
}

int is_label(Token *t, int count) {
    return count >= 2 &&
           t[0].type == TOK_IDENT &&
           t[1].type == TOK_COLON;
}

int parse_imm(const char *s, int *out) {
    if (!s) return 0;

    char *end;
    long val = strtol(s, &end, 0);

    if (*end != '\0') return 0;

    *out = (int)val;
    return 1;
}

InstrMap table[] = {
    {"ADD",  INSTR_ADD},
    {"ADDI", INSTR_ADDI},
    {"SUB", INSTR_SUB},
    {"SUBI", INSTR_SUBI},
    {"INC",  INSTR_INC},
    {"DEC",  INSTR_DEC},
    {"CMP",  INSTR_CMP},
    {"CMPI", INSTR_CMPI},
    {"MOV",  INSTR_MOV},
    {"MOVI", INSTR_MOVI},
    {"LDR",  INSTR_LDR},
    {"LDRI", INSTR_LDRI},
    {"STR",  INSTR_STR},
    {"STRI", INSTR_STRI},
    {"OUT", INSTR_OUT},
    {"OUTI", INSTR_OUTI},
    {"IN", INSTR_IN},
    {"INI", INSTR_INI},
    {"HLT",  INSTR_HLT},
    {"JMP",  INSTR_JMP},
    {"JZ",   INSTR_JZ},
    {"JNZ",  INSTR_JNZ},
    {"JN",   INSTR_JN},
    {"JNN",  INSTR_JNN},
    {"JC",   INSTR_JC},
    {"JNC",  INSTR_JNC},
    {"JV",   INSTR_JV},
    {"JNV",  INSTR_JNV},
};

const int table_size = sizeof(table) / sizeof(table[0]);