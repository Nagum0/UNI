global main

segment .data
    z dw 1

segment .bss
    x resw 10
    y resw 4

main:
    add [x], 69
    mox [x], [y]
