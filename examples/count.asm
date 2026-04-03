movi r5, 10
movi r1, 11

loop:
    out 0x01, r5

    dec r5

    cmpi r5, 0
    jz done
    jnz loop

done:
    out 0x01, r5
    hlt