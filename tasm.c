#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "tasm.h"
#include "parser/parser.h"
#include "bingen/bingen.h"
#include "utils/utils.h"

char line_buf[256];
FILE *out;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s input.asm -o output_binary\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = NULL;

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-o") == 0 && i+1 < argc) {
            output_file = argv[i+1];
            i++;
        }
    }

    if (!output_file) {
        fprintf(stderr, "Error: no output file specified (use -o <file>)\n");
        return 1;
    }

    char bin[256];
    snprintf(bin, sizeof(bin), "%s", output_file);

    FILE *in = fopen(input_file, "r");
    out = fopen(bin, "wb");
    if (!in || !out) {
        perror("File open failed");
        return 1;
    }


    while (fgets(line_buf, sizeof(line_buf), in)) {
        trim_newline(line_buf);
        trim_whitespace(line_buf);

        // Skip empty lines and comments
        if (strlen(line_buf) == 0 || line_buf[0] == ';') {
            continue;
        }

        // Parse the line to get instruction type
        InstructionType instr_type = parse_line(line_buf);
        
        // Generate code based on instruction type
        if (instr_type != INSTR_UNKNOWN) {
            generate_binary(instr_type, line_buf, out);
        }
    }

    fclose(in);
    fclose(out);

    return 0;
}