#ifndef BINGEN_H
#define BINGEN_H

#include "../parser/parser.h"
#include <stdint.h>

void generate_binary(InstructionType instr_type, char *line, FILE *out);
uint8_t get_register_index(char *reg);

#endif