# Tau Assembler (TASM)

**TASM** is the assembler for **TauCPU**. It converts human-readable assembly programs into machine code that can be executed on the TauCPU emulator.

## Usage
`tasm input.asm -o output.bin`


## Supported Instructions
TASM supports all TauCPU instructions

The syntax for each instruction follows the TauCPU instruction set defined in the [instruction_set.txt](https://github.com/Zennnii/TauCPU/blob/master/docs/instruction_set.txt).

# Features
- Two-pass assembly process
- Lexical analysis (lexer-based parsing)
- Label support with address resolution
- Conditional jump support (JZ, JNZ, JN, JNN, JC, JNC, JV, JNV)

## Notes
- **Case-insensitive**: `add r0, r1` and `ADD R0, R1` are equivalent.
- Labels are resolved during the second pass of assembly.
- Only output-based I/O instructions are fully supported in the current CPU emulator.

## See Also
- [TauCPU Repo](https://github.com/Zennnii/TauCPU)
- [TauCPU Instruction Set](https://github.com/Zennnii/TauCPU/blob/master/docs/instruction_set.txt)
- [TauCPU I/O Ports](https://github.com/Zennnii/TauCPU/blob/master/docs/io_ports.txt)