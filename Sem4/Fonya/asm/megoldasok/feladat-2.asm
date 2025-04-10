global main
extern be_elojeles_egesz
extern ki_elojeles_egesz

section .text
main:
    call be_elojeles_egesz
    cmp eax,0
    jge nagyobb_egyenlo
    neg eax
nagyobb_egyenlo:
    
    ; eredmény kiirasa:    
    push eax
    call ki_elojeles_egesz
    add esp,4
    ; visszateres:
    ret
