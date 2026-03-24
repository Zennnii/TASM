#ifndef INSTR_EMIT
#define INSTR_EMIT

#include "../bingen.h"
#include "../../tasm.h"
#include "../../parser/parser.h"
#include "../../utils/utils.h"

void emit_add(char *line, FILE *out);
void emit_addi(char *line, FILE *out);
void emit_inc(char *line, FILE *out);
void emit_dec(char *line, FILE *out);
void emit_cmp(char *line, FILE *out);
void emit_cmpi(char *line, FILE *out);
void emit_mov(char *line, FILE *out);
void emit_movi(char *line, FILE *out);
void emit_ldr(char *line, FILE *out);
void emit_ldri(char *line, FILE *out);
void emit_str(char *line, FILE *out);
void emit_stri(char *line, FILE *out);
void emit_out(char *line, FILE *out);
void emit_outi(char *line, FILE *out);
void emit_hlt(FILE *out);

#endif