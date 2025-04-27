global main
extern read_unsigned, write_unsigned
extern read_boolean, write_boolean
extern write_char, write_str
segment .bss

segment .text
main:
sub esp, 20

add esp, 20
mov eax, 0
ret
