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
    mov eax,[X]
    xor edx,edx     ; mov edx,0
    mul dword [Y]   ; edx|eax := eax * [Y]
    mov [Z],eax
    
    ; eredmény kiirasa:    
    push dword [Z]
    call ki_egesz
    add esp,4
    ; visszateres:
    ret
