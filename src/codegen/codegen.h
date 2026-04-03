#pragma once

#include "../parser/parser.h"
#include "../labels/labels.h"
#include <stdio.h>
#include <stdint.h>

void generate_binary(InstructionType instr_type, Token *t, int n, int line, SymbolTable *st, FILE *out);
uint8_t get_register_index(const char *reg);