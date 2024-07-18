section .data
    msg1 : db "Number is : ",0xa
    len1 : equ $-msg1
    mfact : db "Factorial is :",0xa
    mfactlen :equ $-mfact
    nl db 10

section .bss
    fact resb 8
    num resb 2

%macro print 2  ;using macro for printing 
    mov rax,01
    mov rdi,01
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

%macro exit
   mov rax,60
   mov rdi,0
syscall
%endmacro 

section .text
global _start
_start:

pop rbx    
pop rbx
pop rbx

mov [num],rbx
print msg1,len1

print [num],2

mov rax,1
mov rdi,1
mov rsi,[num]
mov rdx,2
syscall

mov rsi,[num]
mov rcx,2
xor rbx,rbx
call a2h

mov rax,rbx

call factp

mov rcx,8
mov rdi,fact
xor bx,bx
mov ebx,eax
call htoa

print nl
print msg1,len1
print fact, 8
print nl
stop

factp:
    dec rbx             ; Decrement the value in RBX (which likely contains the number whose factorial is being calculated)
    cmp rbx,01          ; Compare the value in RBX with 1
    je b1               ; Jump to 'b1' if the value in RBX is 1
    cmp rbx,00          ; Compare the value in RBX with 0
    je b1               ; Jump to 'b1' if the value in RBX is 0
    mul rbx             ; Multiply RAX (likely containing the current factorial value) by RBX (current number)
    call factp          ; Recursively call the 'factp' function
b1:
    ret                 ; Return from the function


a2h:
	up1: 
rol bx,04
mov al,[rsi]
cmp al,39h
jbe a2
 

sub al,07h
a2:
sub al,30h
add bl,al
inc rsi
loop up1
ret

htoa:
d:
rol ebx,4
mov ax,bx
and ax,0fh
cmp ax,09h
jbe ii
add ax,07h
ii:add ax,30h
mov [rdi],ax
inc rdi
loop d
ret
	

    
    
