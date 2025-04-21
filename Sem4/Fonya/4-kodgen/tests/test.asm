global main
extern read_unsigned, write_unsigned
extern read_boolean, write_boolean
extern write_char, write_str
segment .bss

segment .text
main:
sub esp, 4
mov eax, 10
mov [ebp - 4], eax
sub esp, 1
mov al, 90
mov [ebp - 5], al
mov eax, [ebp - 4]
push eax
call write_unsigned
add esp,4
xor eax, eax
mov al, [ebp - 5]
push eax
call write_char
add esp,4

add esp, 5
mov eax, 0
ret
