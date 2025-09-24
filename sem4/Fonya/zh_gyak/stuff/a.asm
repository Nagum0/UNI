global main
extern read_unsigned, write_unsigned, write_time
extern read_boolean, write_boolean
segment .bss
    time: resb 2

segment .text
main:
    mov BYTE [time], 19
    mov BYTE [time + 1], 20

    push time
    call write_time
    add esp, 4

    mov eax, 0
    ret
