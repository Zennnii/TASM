#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "labels.h"
#include "../utils/utils.h"
#include "../codegen/codegen.h"

void init_table(SymbolTable *st) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        st->buckets[i] = NULL;
    }
}

unsigned hash(const char *s) {
    unsigned h = 0;
    while (*s) {
        h = (h * 31) + (unsigned char)(*s);
        s++;
    }
    return h % TABLE_SIZE;
}

void add_label(SymbolTable *st, const char *name, uint16_t addr) {
    unsigned idx = hash(name);

    Symbol *cur = st->buckets[idx];
    while (cur) {
        if (strcmp(cur->name, name) == 0) {
            fprintf(stderr, "Duplicate label: %s\n", name);
            exit(1);
        }
        cur = cur->next;
    }

    Symbol *sym = malloc(sizeof(Symbol));
    if (!sym) {
        perror("malloc");
        exit(1);
    }

    sym->name = malloc(strlen(name) + 1);
    strcpy(sym->name, name);

    sym->addr = addr;
    sym->next = st->buckets[idx];
    st->buckets[idx] = sym;
}

uint16_t lookup_label(SymbolTable *st, const char *name) {
    unsigned idx = hash(name);

    Symbol *cur = st->buckets[idx];
    while (cur) {
        if (strcmp(cur->name, name) == 0)
            return cur->addr;
        cur = cur->next;
    }

    fprintf(stderr, "Undefined label: %s\n", name);
    exit(1);
}

void add_label_from_token(SymbolTable *st, Token *t, uint16_t lc) {
    char name[64];
    snprintf(name, sizeof(name), "%s", t[0].text);

    size_t len = strlen(name);
    if (name[len - 1] == ':') {
        name[len - 1] = '\0';
    }

    add_label(st, name, lc);
}

uint16_t resolve_operand(SymbolTable *st, Token *t) {
    if (t->type == TOK_NUMBER)
        return (uint16_t)strtol(t->text, NULL, 0);

    if (t->type == TOK_IDENT) {
        if (t->text[0] == 'R' || t->text[0] == 'r')
            return get_register_index(t->text);

        return lookup_label(st, t->text);
    }

    fprintf(stderr, "Invalid operand\n");
    exit(1);
}