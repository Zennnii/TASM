#pragma once

#include "../lexer/lexer.h"

typedef enum {
    INSTR_ADD,
    INSTR_ADDI,
    INSTR_SUB,
    INSTR_SUBI,
    INSTR_INC,
    INSTR_DEC,
    INSTR_CMP,
    INSTR_CMPI,
    INSTR_MOV,
    INSTR_MOVI,
    INSTR_LDR,
    INSTR_LDRI,
    INSTR_STR,
    INSTR_STRI,
    INSTR_IN,
    INSTR_INI,
    INSTR_OUT,
    INSTR_OUTI,
    INSTR_HLT,
    INSTR_JMP,
    INSTR_JZ,
    INSTR_JNZ,
    INSTR_JN,
    INSTR_JNN,
    INSTR_JC,
    INSTR_JNC,
    INSTR_JV,
    INSTR_JNV,
    INSTR_UNKNOWN,
    INSTR_EMPTY
} InstructionType;

extern const int table_size;

typedef struct {
    const char *name;
    InstructionType type;
} InstrMap;

extern InstrMap table[];

extern InstructionType instr_type;

InstructionType parse_tokens(Token *t, int n);
int is_label(Token *t, int n);
int parse_imm(const char *s, int *out);