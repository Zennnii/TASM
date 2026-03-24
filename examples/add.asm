; Example 1: Add 5 + 10 and output the result

; R0 = 5
MOVI R0, 5
; R1 = 10
MOVI R1, 10
; R0 = R0 + R1
ADD R0, R1
; Output R0 to port 0x01
OUT 0x01, R0

; Halt CPU
HLT