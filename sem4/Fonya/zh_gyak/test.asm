global main
extern read_unsigned, write_unsigned
extern read_boolean, write_boolean
segment .bss

segment .text
main:
mov eax, 3
label0:
cmp eax, 0
je label1
dec eax
push eax
mov eax, 10
push eax
call write_unsigned
add esp,4
pop eax
jmp label0
label1:

mov eax, 0
ret
