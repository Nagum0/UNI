global main
extern write_natural
extern read_natural
extern write_boolean
extern read_boolean

section .bss
label0: resd 1
label1: resd 2
label2: resd 2

section .text
main:
mov eax,0
mov [label0], eax
mov eax, 18
mov ebx, 25
mov [label1], eax
mov [label1 + 1 * 4], ebx
mov eax, 1
mov ebx, 02
push eax
 push ebx
mov eax, [label1]
mov ebx, [label1 + 1 * 4]
pop edx
 pop ecx
add eax, ecx
add ebx, edx
mov [label2], eax
mov [label2 + 1 * 4], ebx
mov eax, [label2]
push eax
mov eax, [label1 + 1 * 4]
mov ecx,eax
pop eax
add eax,ecx
mov [label0], eax
mov eax,[label0]
push eax
call write_natural
add esp,4
xor eax,eax
ret
