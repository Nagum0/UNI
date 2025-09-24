global main
extern be_egesz
extern ki_egesz

section .data
X   dd  5
Y   dd  10

section .bss
Z   resd 4
; lehetne resw 2
; vagy resb 4

section .text
main:
    inc dword [X]
    
    ; eredmény kiirasa:    
    push dword [X]
    call ki_egesz
    add esp,4
    ; visszateres:
    ret
