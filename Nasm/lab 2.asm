  section	.text
   global _start    ; необходимо для линкера (ld)

_start:
main:	            ; сообщает линкеру стартовую точку
   ;mov	eax, 4451
   ;mov ebx, 99
   call input
   push eax; save eax
   call input
   mov ebx, eax
   pop eax
   cdq; eax to EDX:EAX
   div ebx

   call output

   mov	eax,1       ; номер системного вызова (sys_exit)

   int	0x80        ; вызов ядра


output:
   push eax
   push ebx
   push ecx
   push edx

      mov ebx, eax
      L3:
         cdq
         mov ecx, 10
         div ecx
         add edx, '0'
         push edx

         cmp eax, 0
      jg L3

      mov eax, ebx
      L4:
         cdq
         mov ecx, 10
         div ecx
         pop ebx
         push eax

         mov [res], ebx
         mov ecx, res
         mov ebx, 0
         mov edx, 1
         mov eax, 4 ;print
         int 80h
         pop eax
         cmp eax, 0
      jg L4

   pop edx
   pop ecx
   pop ebx
   pop eax
   ret

input:

   push ebx
   push ecx
   push edx
      mov eax, 4 ;emsg "Enter num"
      mov ebx, 1
      mov ecx, emsg
      mov edx, lenemsg
      int 80h

      mov eax, 3 ;read
      mov ebx, 1
      mov ecx, num
      mov edx, 6
      int 80h

      mov eax, 4 ;print
      mov ebx, 1
      mov ecx, num
      mov edx, 5
      int 80h

      mov eax, 4 ;print
      mov ebx, 1
      mov ecx, nlmsg
      mov edx, 2
      int 80h

      mov ecx, 5
      mov esi, num
      mov ebx, 0

      L1:
         lodsb
         movsx edx, al
         sub edx, '0'
         mov eax, edx
         push ecx ;save ecx
         dec ecx
         jz Z1
         L2:
            mov edx, 10
            mul edx
            loop L2
         Z1:
         pop ecx

         add ebx, eax
         xor eax, eax
         loop L1

      mov eax, ebx
  fin:
   pop edx
   pop ecx
   pop ebx
   ret

section .bss
   num resb 5
   res resb 1

section	.data
   emsg db 0xA,'Enter num: '
   lenemsg equ $-emsg
   nlmsg db 0xA

   ;d10 dw 10
