global main
extern ki_elojeles_egesz

section .bss
    z resd 1

section .data
    x dd 10
    y dd 5

section .text
main:
    mov eax, [x]
    add eax, 2
    mov [x], eax
    push dword [x]
    call ki_elojeles_egesz
    add esp, 4

    mov eax, [x]
    mov [y], eax
    push dword [y]
    call ki_elojeles_egesz
    add esp, 4
    
    xor edx, edx
    mov eax, [x]
    mul dword [y]
    mov ecx, edx
    mov cx, ax
    mov [z], ecx
    push dword [z]
    call ki_elojeles_egesz
    add esp, 4

    mov eax, 0
    ret
