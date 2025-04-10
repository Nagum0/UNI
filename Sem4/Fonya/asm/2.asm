global main
extern be_elojeles_egesz, ki_elojeles_egesz

section .text
main:
    call be_elojeles_egesz
    
    cmp eax, 0
    jge greater_equal
    neg eax

greater_equal:
    push eax
    call ki_elojeles_egesz
    add esp, 4
    
    mov eax, 0
    ret
