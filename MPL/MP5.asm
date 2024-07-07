section .data
	msg1 db "Program for displaying count of positive and negative numbers: ",0ah
	len1 equ $-msg1
	msg2 db "Positive number count: ",0ah
	len2 equ $-msg2
	msg3 db "Negative number count: ",0ah
	len3 equ $-msg3
	array db 40h,10h,16h,23h,-8h
	endl db 0xA, 0xD
	
	
	%macro print 2
		mov rax,1
		mov rdi,1
		mov rsi,%1
		mov rdx,%2
		syscall
	%endmacro
	
	
section .bss
	count resb 2
pcount resb 2
ncount resb 2
totalcount resb 2
	
	
section .text
global _start
_start:

	print msg1,len1
	;print endl,1
	mov byte[count],5
	mov byte[pcount],0		;initialize pcount and n count to 0
	mov byte[ncount],0
	mov rbp,array			;let rsi point to arrays first location
	
	
up:
	mov al,byte[rbp]
	cmp al,00h
	js neg
	inc byte[pcount]
	jmp down
	
	neg:
	inc byte[ncount]

down:
	inc rbp
	dec byte[count]
	jnz up
	
mov bl,byte[pcount]
mov dl,byte[ncount]
b1:
	print msg2,len2
	mov bh,[pcount]
	call display
	print endl,1
	
	print msg3,len3
	mov bh,[ncount]
	call display
	print endl,1
	
	mov rax,60
	mov rdi,00
	syscall
	
display:
mov byte[count],02

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
	

	
	
	
	
	
