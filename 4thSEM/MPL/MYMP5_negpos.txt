section .data
    msg1 db "Program to Display Positive and Negative number count: ",0ah
    len1 equ $-msg1
    msg2 db "Positive number count :",0ah
    len2 equ $-msg2
    msg3 db "Negative number count :",0ah
    len3 equ $-msg3
    nl db 0ah,0dh
    array db 40h,-10h,-16h,-23h,8h

%macro print 2
    mov rax,1
    mov rdi,1
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

;%macro exit 0
  ;  mov rax,60
  ;  mov rdi,0
  ;  syscall
;%endmacro

section .bss
    count resb 2
    pcount resb 2
    ncount resb 2
    totalcount resb 2


section .text
global _start
_start:

print msg1,len1

mov byte[count],5
mov byte[pcount],0
mov byte[ncount],0

mov rbp,array

up:
    mov al,byte[rbp]
    cmp al,00h
    jns pos       ;jump is sign flag is not set 
    inc byte[ncount]
    jmp down

    pos:
    inc byte[pcount]

down:inc rbp
    dec byte[count]
    jnz up

mov bl,byte[pcount]
mov dl,byte[ncount]

b1:
    print msg2,len2
    mov bh,[pcount]
    call display
    print nl,1

    print msg3,len3
    mov bh,[ncount]
    call display
    print nl,1

mov rax,60
	mov rdi,00
	syscall
    
display:
mov byte[count],02 	;count is 2 to indicate that only the last two bits are to be printed
 
loop:
        rol bh,04
        mov al,bh
        AND al,0FH
        cmp al,09
        jbe l1
        add al,07h

l1:
        add al,30h
        mov [totalcount],al
        print totalcount,02
        dec byte[count]
        jnz loop
ret
    

;alternate way 
;up:
;	mov al,byte[rbp]
;	cmp al,00h
;	js neg
;	inc byte[pcount]
;	jmp down
;	
;	neg:
;	inc byte[ncount]
;   jmp down
;
;down:
;	inc rbp
;	dec byte[count]
;	jnz up
;   





