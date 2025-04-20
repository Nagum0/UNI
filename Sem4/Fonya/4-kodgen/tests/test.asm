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
mov eax, 0
mov [label0], eax
label2:
mov eax, 5
push eax
mov eax, [label0]
pop ebx
cmp eax, ebx
setl al
cmp al, 1
jne near label3
xor eax, eax
mov eax, [label0]
mov esi, eax
mov eax, [label1 + esi * 1]
push eax
call write_char
add esp,4
mov eax, 1
push eax
mov eax, [label0]
pop ebx
add eax, ebx
mov [label0], eax
jmp label2
label3:

mov eax, 0
ret
