#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "instr_emit.h"

void emit_hlt(FILE *out) {
    fputc(OP_HLT, out);
}