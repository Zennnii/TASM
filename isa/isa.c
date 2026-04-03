#include "isa.h"

int instr_size(InstructionType op) {
    switch (op) {
        case INSTR_ADD:  return 3;
        case INSTR_ADDI: return 4;
        case INSTR_SUB:  return 3;
        case INSTR_SUBI: return 4;
        case INSTR_INC:  return 2;
        case INSTR_DEC:  return 2;
        case INSTR_CMP:  return 3;
        case INSTR_CMPI: return 4;
        case INSTR_MOV: return 3;
        case INSTR_MOVI: return 4;
        case INSTR_LDR:  return 3;
        case INSTR_LDRI: return 5;
        case INSTR_STR:  return 3;
        case INSTR_STRI: return 5;
        case INSTR_JZ:   return 3;
        case INSTR_JNZ:  return 3;
        case INSTR_JN:   return 3;
        case INSTR_JNN:  return 3;
        case INSTR_JC:   return 3;
        case INSTR_JNC:  return 3;
        case INSTR_JV:   return 3;
        case INSTR_JNV:  return 3;
        case INSTR_HLT:  return 1;
        default: return 0;
    }
}
