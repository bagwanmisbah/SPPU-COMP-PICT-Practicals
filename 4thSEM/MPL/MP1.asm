section .data
msg1 db "Program to Display 5 Hexadecimal numbers",0ah
len1 equ $-msg1
msg2 db "Enter 5 Hexadecimal numbers",0ah
len2 equ $-msg2
msg3 db "Displaying 5 Hexadecimal  numbers",0ah
len3 equ $-msg3

section .bss
num resd 200
counter resb 1

section .text
global _start
_start:mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,len1
	syscall
	
	mov rax,1
	mov rdi,1
	mov rsi,msg2
	mov rdx,len2
	syscall
	
	mov rbp,num 		;set pointer to arrays first location
	mov byte[counter],5		;assign counter=5
	
ipnum:	mov rax,0
	mov rdi,0
	mov rsi,rbp
	mov rdx,17
	syscall
	
	add rbp,17
	dec byte[counter]  	;dec counter until 0
	jnz ipnum 		;jump back to ipnum if not zero
	
;output msg
	mov rax,1
	mov rdi,1
	mov rsi,msg3
	mov rdx,len3
	syscall
	
	mov rbp,num		;reset rbp to num arrays first location
	mov byte[counter],5
	
opnum:	mov rax,1
	mov rdi,1
	mov rsi,rbp
	mov rdx,17
	syscall
	
	add rbp,17
	dec byte[counter]
	jnz opnum	
	
	mov rax,60
	mov rdi,0
	syscall

