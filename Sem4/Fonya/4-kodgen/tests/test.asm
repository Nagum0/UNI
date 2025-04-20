global main
extern read_unsigned, write_unsigned
extern read_boolean, write_boolean
extern write_char, write_str
segment .bss
label0: resb 5
label1: resb 69

segment .text
main:
mov BYTE [label0 + 0], 90
mov BYTE [label0 + 1], 101
mov BYTE [label0 + 2], 107
mov BYTE [label0 + 3], 105
mov BYTE [label0 + 4], 10
mov eax, 5
push eax
push label0
call write_str
add esp, 8
mov BYTE [label1 + 0], 65
mov BYTE [label1 + 1], 83
mov BYTE [label1 + 2], 84
mov BYTE [label1 + 3], 79
mov BYTE [label1 + 4], 76
mov BYTE [label1 + 5], 70
mov BYTE [label1 + 6], 79
mov BYTE [label1 + 7], 79
mov BYTE [label1 + 8], 79
mov BYTE [label1 + 9], 79
mov BYTE [label1 + 10], 79
mov BYTE [label1 + 11], 79
mov BYTE [label1 + 12], 79
mov BYTE [label1 + 13], 79
mov BYTE [label1 + 14], 32
mov BYTE [label1 + 15], 73
mov BYTE [label1 + 16], 83
mov BYTE [label1 + 17], 32
mov BYTE [label1 + 18], 84
mov BYTE [label1 + 19], 72
mov BYTE [label1 + 20], 69
mov BYTE [label1 + 21], 9
mov BYTE [label1 + 22], 66
mov BYTE [label1 + 23], 69
mov BYTE [label1 + 24], 69
mov BYTE [label1 + 25], 69
mov BYTE [label1 + 26], 69
mov BYTE [label1 + 27], 69
mov BYTE [label1 + 28], 69
mov BYTE [label1 + 29], 69
mov BYTE [label1 + 30], 69
mov BYTE [label1 + 31], 69
mov BYTE [label1 + 32], 83
mov BYTE [label1 + 33], 84
mov BYTE [label1 + 34], 10
mov eax, 69
push eax
push label1
call write_str
add esp, 8

mov eax, 0
ret
