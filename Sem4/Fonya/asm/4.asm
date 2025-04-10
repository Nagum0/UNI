global main
extern be_egesz, ki_egesz

;  while b != 0:
;    temp := b
;    b := a % b
;    a := temp
;  
;  return a

section .text
main:
    call be_egesz
    push eax

    call be_egesz
    mov ebx, eax        ; ebx := b
    pop eax             ; eax := a
    xor ecx, ecx        ; ecx := temp

loop:
    cmp ebx, 0
    je end

    mov ecx, ebx        ; temp := b

    push eax
    xor edx, edx
    div ebx             ; edx := a % b
    pop eax             ; eax := a
    mov ebx, edx        ; b := edx (a % b)
    
    mov eax, ecx        ; a := temp
    
    jmp loop

end:
    push eax
    call ki_egesz
    add esp, 4

    mov eax, 0
    ret
