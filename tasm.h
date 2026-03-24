#ifndef TASM_H
#define TASM_H

extern char line_buf[256];
extern FILE *in;
extern FILE *out;
extern char bin[];

#define REG_R0 0
#define REG_R1 1
#define REG_R2 2
#define REG_R3 3
#define REG_R4 4
#define REG_R5 5
#define REG_R6 6
#define REG_R7 7

// Instruction opcodes
    // Arithmetic
    #define OP_ADD 10
    #define OP_ADDI 11
    #define OP_INC 12
    #define OP_DEC 13
    #define OP_CMP 14
    #define OP_CMPI 15

    // Data transfer
    #define OP_MOV 20
    #define OP_MOVI 21
    #define OP_LDR 22
    #define OP_LDRI 23
    #define OP_STR 24
    #define OP_STRI 25

    // I/O
    #define OP_IN 40
    #define OP_INI 41
    #define OP_OUT 42
    #define OP_OUTI 43

    // Program flow
    #define OP_HLT 30

#endif