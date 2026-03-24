; Store two values in adjacent memory locations

MOVI R2, 0x100

MOVI R0, 42
STRI R0, R2, 0

MOVI R1, 99
STRI R1, R2, 2

LDRI R3, R2, 0
OUT 0x01, R3

LDRI R4, R2, 2
OUT 0x01, R4

HLT