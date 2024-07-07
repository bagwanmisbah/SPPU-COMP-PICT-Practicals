;     AUTHOR :  MISBAH BAGWAN 21487

section .data
    menu db 0ah,0dh, "____________MENU____________"
         db 0ah,0dh, "1.Addition"
         db 0ah,0dh, "2.Subtraction"
         db 0ah,0dh, "3.Multiplication"
         db 0ah,0dh, "4.Division"
         db 0ah,0dh, "5.Exit"

    menulen equ $-menu

    arr dq 4h,4h
    n equ 2

    res db "Result : ",0ah
    rlen equ $-res

    e db "Exited ",0ah
    le equ $-e

    %macro scall 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3
        mov rdx,%4
    syscall
    %endmacro
        

section .bss
    ans resb 16
    choice resb 2

section .text
global _start
_start:

up:scall 1,1,menu,menulen
   scall 0,0,choice,2

cmp byte[choice],'1'
je case1
cmp byte[choice],'2'
je case2
cmp byte[choice],'3'
je case3
cmp byte[choice],'4'
je case4
cmp byte[choice],'5'
je case5

case1:scall 1,1,res,rlen
    call addition
    jmp up

case2:scall 1,1,res,rlen
    call subtraction
    jmp up

case3:scall 1,1,res,rlen
    call multiplication
    jmp up

case4:scall 1,1,res,rlen
    call division
    jmp up

case5:scall 1,1,e,le

mov rax,60
mov rdi,0
syscall

addition:
    mov rcx,n ;for iterating throigh the array
    dec rcx   
    mov rsi,arr ;using rsi to point to its first index
    mov rax,[rsi] ;store arrays current element in rax 

up1:
    add rsi,8  ;move to next element(each element is of 8 bytes )
    mov rbx,[rsi]
    add rax,rbx
    loop up1
    call display
ret 
subtraction:
    mov rcx,n
    dec rcx
    mov rsi,arr
    mov rax,[rsi]
up2:
    add rsi,8
    mov rbx,[rsi]
    sub rax,rbx
    loop up2
    call display
ret 

multiplication:
    mov rcx,n
    dec rcx
    mov rsi,arr
    mov rax,[rsi]
up3:
    add rsi,8
    mov rbx,[rsi]
    mul rbx
    loop up3
    call display
ret

division:
    mov rcx,n
    dec rcx
    mov rsi,arr
    mov rax,[rsi]
up4:
    add rsi,8
    mov rbx,[rsi]
    div rbx
    loop up4
    call display
ret



display:
    mov rsi,ans+15 ;rsi points to the last digit ,we are using to store result
    ;simply mov rsi,ans would make it point to the first bit 
    mov rcx,16

cnt:
    mov rdx,0         ;Clear the upper 64 bits of the dividend (remainder)
                      ;rax contains quotient after division
    mov rbx,16        ;loading base 16
    div rbx  ;div rbx,rax Divide RDX:RAX (remainder:quotient) by RBX (16)
    cmp dl,09h        ;Compare the remainder (DL) with 9 (in ASCII
    jbe add30h
    add dl,07h
    add30h: add dl,30h
    mov [rsi],dl
    dec rsi
    dec rcx
    jnz cnt

scall 1,1,ans,16
ret 



