#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "../utils/utils.h"

InstructionType parse_line(char *line) {
    to_uppercase(line);
    
    // Handle comments
    char *comment = strstr(line, ";");
    if (comment) *comment = '\0';

    trim_whitespace(line);
    if (*line == '\0') return INSTR_EMPTY;

    else if (strncmp(line, "ADD ", 4) == 0) {
        return INSTR_ADD;
    }

    else if (strncmp(line, "ADDI ", 5) == 0) {
        return INSTR_ADDI;
    }

    else if (strncmp(line, "INC ", 4) == 0) {
        return INSTR_INC;
    }

    else if (strncmp(line, "DEC ", 4) == 0) {
        return INSTR_DEC;
    }

    else if (strncmp(line, "CMP ", 4) == 0) {
        return INSTR_CMP;
    }

    else if (strncmp(line, "CMPI ", 5) == 0) {
        return INSTR_CMPI;
    }

    else if (strncmp(line, "MOV ", 4) == 0) {
        return INSTR_MOV;
    }

    else if (strncmp(line, "MOVI ", 5) == 0) {
        return INSTR_MOVI;
    }

    else if (strncmp(line, "LDR ", 4) == 0) {
        return INSTR_LDR;
    }

    else if (strncmp(line, "LDRI ", 5) == 0) {
        return INSTR_LDRI;
    }

    else if (strncmp(line, "STR ", 4) == 0) {
        return INSTR_STR;
    }
    else if (strncmp(line, "STRI ", 5) == 0) {
        return INSTR_STRI;
    }

    else if (strncmp(line, "IN ", 3) == 0) {
        return INSTR_IN;
    }

    else if (strncmp(line, "INI ", 4) == 0) {
        return INSTR_INI;
    }

    else if (strncmp(line, "OUT ", 4) == 0) {
        return INSTR_OUT;
    }

    else if (strncmp(line, "OUTI ", 5) == 0) {
        return INSTR_OUTI;
    }

    else if (strcmp(line, "HLT") == 0) {
        return INSTR_HLT;
    }

    else {
        return INSTR_UNKNOWN;
    }
}