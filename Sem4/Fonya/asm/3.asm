global main
extern be_egesz, ki_egesz

section .text
main:
    call be_egesz
    push eax

    call be_egesz
    pop ebx
    mov edx, eax

    xor ecx, ecx
    
loop:
    cmp ecx, ebx
    je end
    inc ecx

    push ecx
    push ebx
    push edx

    push edx
    call ki_egesz
    add esp, 4

    pop edx
    pop ebx
    pop ecx

    jmp loop
    
end:
    mov eax, 0
    ret
