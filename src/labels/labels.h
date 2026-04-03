#pragma once

#include <stdint.h>
#include "../parser/parser.h"

#define TABLE_SIZE 256

typedef struct Symbol {
    char *name;
    uint16_t addr;
    struct Symbol *next;
} Symbol;

typedef struct {
    Symbol *buckets[TABLE_SIZE];
} SymbolTable;

void init_table(SymbolTable *st);
unsigned hash(const char *s);
void add_label(SymbolTable *st, const char *name, uint16_t addr);
uint16_t lookup_label(SymbolTable *st, const char *name);
void add_label_from_token(SymbolTable *st, Token *t, uint16_t lc);
uint16_t resolve_operand(SymbolTable *st, Token *tok);