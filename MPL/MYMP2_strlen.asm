section .data
    msg1 db "Program to calculate length of string "
    len1 equ $-msg1
    msg2 db "Enter String: "
    len2 equ $-msg2
    msg3 db "Length of String:  "
    len3 equ $-msg3
    n db 0ah
    nl equ $-n

    %macro scall 4             ;macro for both read and write 
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro

%macro exit 0                 ;macro for exit
    mov rax,60
    mov rdi,0
    syscall
%endmacro

section .bss
    string resb 200 ;declaring string variable to reserve 200 bytes
    result resb 200

section .text
global _start
_start:

scall 1,1,msg1,len1
scall 1,1,n,nl
scall 1,1,msg2,len2
scall 0,0,string,200     


mov rbx,rax  ;value indicates how many characters were actually read into memory.
             ;we are going to use rbx register for rotating
mov rbp,result;letting rbp point to result buffer (preparing to store hex representation) 
mov rcx,16h  ;using rcx register for counting purpose

back:
    rol rbx,04h ; shifting out the least significant nibble (4 bits) of the value.
    ;It then extracts this nibble and converts it into its corresponding hexadecimal ASCII representation. 
    ;This converted value is stored in the result buffer.
    mov al,bl
    and al,0fh   ; clears the upper 4 bits of al, retaining only the lower 4 bits.
    cmp al,09h   ;affects two flags zero and sign,if op1=op2 the zf=1 else if op1 is less than op2 then sf=1 since subtraction result is negative 
    jg add37h    ;if greater than jump to label add37h
    add al,30h   ;if not greater than add 30h hex equ of 0 
    jmp skip
add37h:add al,37h

skip:mov byte[rbp],al ;rbp currently points to beginning of result buffer ,this instruction commands converted value in al to be stored where rbp is pointing to
     inc rbp          ;letting rbp move to the next consecutive location i.e from a[0] to a[1] nd so on
     dec cx           ;rbx was initially set to 16 and will keep decrementing for processing of each nibble
     jnz back         ;unless and until value in cx does not become zero ,keep executing instr in back label to ensure all bits are processed

scall 1,1,msg3,len3
scall 1,1,n,nl
scall 1,1,result,16

    

exit 
    


;nasm -f elf64 mymp2.asm

;Program to calculate length of string 
;Enter String: misbah Length of String:  
;0000000000000006
;[Execution complete with exit code 0]
    