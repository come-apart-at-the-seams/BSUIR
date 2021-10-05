section	.text
   global _start    ; необходимо для линкера (ld)

_start:
main:
   call func
   mov	eax,1       ; номер системного вызова (sys_exit)
   int	0x80        ; вызов ядра
;___________________________________
func:
push eax
push ebx
push ecx
push edx
    mov eax, 4 ;print
    mov ebx, 1
    mov ecx, emsg
    mov edx, lenemsg
    int 80h

    mov eax, 3 ;write st
    mov ebx, 1
    mov ecx, st
    mov edx, 100
    int 80h

    mov ebx, 0
    mov ecx, 100
    mov esi, st
    mov edi, s
    L1:
        lodsb
        cmp al, ' '
            je L2
        stosb
        inc ebx
        loop L1

    L2:
    mov ecx, 100
    mov edi, t
    L3:
        movsb
    loop L3

push ebx
    mov eax, 4 ;print
    mov ebx, 1
    mov ecx, s
    mov edx, 100
    int 80h

    mov eax, 4 ;print
    mov ebx, 1
    mov ecx, t
    mov edx, 100
    int 80h

    mov esi, s
    mov edi, t
    mov edx, 0
    pop ebx
    mov ecx, 100
    ;mov ebx, 0
    L6:
    push ecx
    mov ecx, ebx
    L4:
        lodsb
        scasb
        jne L5
        inc edx
    loop L4

    mov eax, 4 ;print
    mov ebx, 1
    mov ecx, yesm
    mov edx, lyes
    int 80h
    jmp L7
    
    L5:
        cmp edx, 0
        je M
        mov ecx, edx
        mov edx, 0
            LL:
                std
                scasb
                cld
            loop LL
        M:
        mov esi, s
        pop ecx
        loop L6
    mov eax, 4 ;print
    mov ebx, 1
    mov ecx, nom
    mov edx, lno
    int 80h
    L7:

pop edx
pop ecx
pop ebx
pop eax
fin:
ret

section .bss
   s resb 100
   t resb 100
   st resb 201

section	.data
   emsg db 0xA,'Enter str: '
   lenemsg equ $-emsg
   nom db 0xA,'no'
   lno equ $-nom
   yesm db 0xA,'yes'
   lyes equ $-yesm

