global main
extern read_unsigned, write_unsigned
extern read_boolean, write_boolean
extern write_char, write_str
segment .bss
label1: resb 5
label0: resd 1

segment .text
main:
mov eax, 0
mov esi, eax
mov al, 90
mov [label1 + esi * 1], al
mov eax, 1
mov esi, eax
mov al, 101
mov [label1 + esi * 1], al
mov eax, 2
mov esi, eax
mov al, 107
mov [label1 + esi * 1], al
mov eax, 3
mov esi, eax
mov al, 105
mov [label1 + esi * 1], al
mov eax, 4
mov esi, eax
mov al, 10
mov [label1 + esi * 1], al
mov eax, 5
push eax
push label1
call write_str
add esp, 8

mov eax, 0
ret
