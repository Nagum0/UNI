global main
extern read_unsigned, write_unsigned
extern read_boolean, write_boolean
segment .bss
label0: resd 5

segment .text
main:
mov eax, 0
mov esi, eax
mov eax, 10
mov [label0 + esi * 4], eax
mov eax, 0
mov esi, eax
mov eax, [label0 + esi * 4]
push eax
call write_unsigned
add esp,4

mov eax, 0
ret
