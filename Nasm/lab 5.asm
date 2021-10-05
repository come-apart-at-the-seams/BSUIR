section	.text
   global _start    ; необходимо для линкера (ld)

_start:
main:
   call input

   mov ecx, eax
   mov [num_l], ecx; save nlines
   mul ecx
   mov [num_arr], eax; save n el in arr

   call output

   mov ecx, [num_arr]
   mov edx, arr
    N:
      call input2
      mov [edx], eax
      add edx, 4 ; go to next elm
    loop N

   mov ecx, [num_arr]
   mov edx, arr
    H:
      mov eax, [edx]
      call output
      add edx, 4
    loop H

call matrix_t
mov ecx, [num_arr]
mov edx, mas
    H1:
      mov eax, [edx]
      call output
      add edx, 4
    loop H1
      
    call multiply
    mov edx, res_arr
    mov ecx, [num_arr]
    HHH:
      mov eax, [edx]
      call output
      add edx, 4
    loop HHH

   mov	eax,1       ; номер системного вызова (sys_exit)
   int	0x80        ; вызов ядра
;___________________________________

output:
   push eax
   push ebx
   push ecx
   push edx
         push eax
         mov ecx, new
         mov ebx, 0
         mov edx, 1
         mov eax, 4 ;print
         int 80h
         pop eax
      mov ebx, eax

      cmp eax, 0
      jle P71
      P73:
      L73:
         cdq
         mov ecx, 10
         div ecx
         add edx, '0'
         push edx

         cmp eax, 0
      jg L73

      mov eax, ebx
      L74:
         cdq
         mov ecx, 10
         idiv ecx
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
      jg L74
   jmp P72
   P71:
      push ebx
      push eax
         mov ecx, unss
         mov ebx, 0
         mov edx, 1
         mov eax, 4 ;print
         int 80h
      pop eax
      pop ebx
      neg ebx
      neg eax
      jmp P73
   P72:
   pop edx
   pop ecx
   pop ebx
   pop eax
   ret

input:
   push ebx
   push ecx
   push edx
      mov eax, 4
      mov ebx, 1
      mov ecx, line
      mov edx, lline
      int 80h

      mov eax, 3 ;read
      mov ebx, 1
      mov ecx, numb
      mov edx, 3
      int 80h

      mov eax, 4 ;print
      mov ebx, 1
      mov ecx, numb
      mov edx, 2
      int 80h

      mov ecx, 2
      mov esi, numb
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

   pop edx
   pop ecx
   pop ebx
   ret

input2:
   push ebx
   push ecx
   push edx
         mov ecx, new
         mov ebx, 0
         mov edx, 1
         mov eax, 4 ;print
         int 80h

      mov eax, 4 ;emsg "Enter num"
      mov ebx, 1
      mov ecx, emsg
      mov edx, lenemsg
      int 80h

      mov eax, 3 ;read
      mov ebx, 1
      mov ecx, num
      mov edx, 7
      int 80h

      mov eax, 4 ;print
      mov ebx, 1
      mov ecx, num
      mov edx, 6
      int 80h

      ;mov eax, 4 ;print
      ;mov ebx, 1
      ;mov ecx, lmsg
      ;mov edx, 1
      ;int 80h

      mov ecx, 5
      mov esi, num
      mov ebx, 0

         lodsb
         movsx edx, al
         cmp edx, '-'
         je L11 ;if [0] = '-'
         jmp L12 ;if [0] != '-'
      L1q:
         lodsb
         movsx edx, al
         L12:
         sub edx, '0'
         mov eax, edx
         push ecx ;save ecx
         dec ecx
         jz Z1q
         L2q:
            mov edx, 10
            mul edx
            loop L2q
         Z1q:
         pop ecx

         add ebx, eax
         xor eax, eax
         loop L1q
         jmp L9q
    L11:
      LL1q:
         lodsb
         movsx edx, al
         sub edx, '0'
         mov eax, edx
         push ecx ;save ecx
         dec ecx
         jz ZZ1q
         LL2q:
            mov edx, 10
            mul edx
            loop LL2q
         ZZ1q:
         pop ecx

         add ebx, eax
         xor eax, eax
         loop LL1q
      NEG EBX
   L9q:
   mov eax, ebx
   pop edx
   pop ecx
   pop ebx
   ret

matrix:
   push ebx
   push ecx
   push edx

      mov ecx, [num_l]
      mov eax, [i]
      mul ecx
      mov ecx, [j]
      add eax, ecx
      mov ecx, 4
      mul ecx

      mov edx, arr
      add edx, eax
      mov eax, [edx]
      push eax

      mov ecx, [num_l]
      mov eax, [j]
      mul ecx
      mov ecx, [i]
      add eax, ecx
      mov ecx, 4
      mul ecx

      mov edx, mas
      add edx, eax
      pop eax
      mov [edx], eax

   pop edx
   pop ecx
   pop ebx
   ret

matrix_t:
   push ebx
   push ecx
   push edx
      mov ecx, [num_l]
      ML1:
         push ecx
         dec ecx
         mov [i], ecx
         mov ecx, [num_l]
            ML:
               push ecx
               dec ecx
               mov [j], ecx
               call matrix
               pop ecx
            loop ML
         pop ecx
      loop ML1



   pop edx
   pop ecx
   pop ebx
   ret

multiply:
   push eax
   push ebx
   push ecx
   push edx

      mov ecx, [num_l]
      S0:
       push ecx
       dec ecx
       mov [ii], ecx
       mov ecx, [num_l]
       S:
         push ecx
         dec ecx
         mov [i], ecx
         mov ebx, 0
         
            
         mov ecx, [num_l]
          S1:
            push ecx
            dec ecx
            mov [j], ecx

             mov ecx, [num_l]
             mov eax, [ii]
             mul ecx
             mov ecx, [j]
             add eax, ecx
             mov ecx, 4
             mul ecx
             ;  push ebx
             mov edx, arr
             add edx, eax
             mov eax, [edx]
             push eax
             ;mov ebx, eax

                  mov ecx, [num_l]
                  mov eax, [i]
                  mul ecx
                  mov ecx, [j]
                  add eax, ecx
                  mov ecx, 4
                  mul ecx

             mov edx, mas
             add edx, eax
             mov eax, [edx]
            
            pop ecx
            imul ecx
            add eax, ebx
            mov ebx, eax

            pop ecx
          loop S1
          
          pop ecx
          push ecx
          dec ecx
          mov [j], ecx
             mov ecx, [num_l]
             mov eax, [ii]
             mul ecx
             mov ecx, [j]
             add eax, ecx
             mov ecx, 4
             mul ecx
             
             mov edx, res_arr
             add edx, eax
             mov [edx], ebx
         pop ecx
         dec ecx
       cmp ecx, 0
       jne S
       pop ecx
       dec ecx
      cmp ecx, 0
      jne S0

   pop edx
   pop ecx
   pop ebx
   pop eax
   fin:
   ret

section .bss
   numb resb 2
   num resb 6
   res resb 4
section	.data
   emsg db 0xA,'Enter num: '
   lenemsg equ $-emsg
   line db 0xA,'Num of lines = '
   lline equ $-line
   arr times 100 dd 0
   mas times 100 dd 0
   res_arr times 100 dd 0
   unss db '-'
   new db 0xA
   i dd 0
   j dd 0
   ii dd 0
   num_l dd 0
   num_arr dd 0
