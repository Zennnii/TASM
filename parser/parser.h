#ifndef PARSER_H
#define PARSER_H

typedef enum {
    INSTR_ADD,
    INSTR_ADDI,
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
    INSTR_UNKNOWN,
    INSTR_EMPTY
} InstructionType;

extern InstructionType instr_type;

InstructionType parse_line(char *line);

#endif