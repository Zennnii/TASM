#pragma once

#include "../codegen.h"
#include "../../tasm.h"
#include "../../parser/parser.h"
#include "../../utils/utils.h"
#include "../../labels/labels.h"

// Arithmetic instructions
void emit_add(Token *t, int n, int line ,FILE *out);
void emit_addi(Token *t, int n, int line ,FILE *out);
void emit_inc(Token *t, int n, int line ,FILE *out);
void emit_dec(Token *t, int n, int line ,FILE *out);
void emit_cmp(Token *t, int n, int line ,FILE *out);
void emit_cmpi(Token *t, int n, int line ,FILE *out);

// Data transfer instructions
void emit_mov(Token *t, int n, int line ,FILE *out);
void emit_movi(Token *t, int n, int line ,FILE *out);
void emit_ldr(Token *t, int n, int line ,FILE *out);
void emit_ldri(Token *t, int n, int line ,FILE *out);
void emit_str(Token *t, int n, int line ,FILE *out);
void emit_stri(Token *t, int n, int line ,FILE *out);

// I/O instructions
void emit_out(Token *t, int n, int line ,FILE *out);
void emit_outi(Token *t, int n, int line ,FILE *out);

// Program flow instructions
void emit_hlt(FILE *out);
void emit_jmp(Token *t, int n, int line, SymbolTable *st ,FILE *out);
void emit_jz(Token *t, int n, int line, SymbolTable *st ,FILE *out);
void emit_jnz(Token *t, int n, int line, SymbolTable *st ,FILE *out);
void emit_jn(Token *t, int n, int line, SymbolTable *st ,FILE *out);
void emit_jnn(Token *t, int n, int line, SymbolTable *st ,FILE *out);
void emit_jc(Token *t, int n, int line, SymbolTable *st ,FILE *out);
void emit_jnc(Token *t, int n, int line, SymbolTable *st ,FILE *out);
void emit_jv(Token *t, int n, int line, SymbolTable *st ,FILE *out);
void emit_jnv(Token *t, int n, int line, SymbolTable *st ,FILE *out);
