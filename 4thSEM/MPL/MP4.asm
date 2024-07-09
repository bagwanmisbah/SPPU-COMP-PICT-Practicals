;BAGWAN MISBAH
%macro scall 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .data
	arr dq 18h,18h
	n equ 2
	
	menu db 10d,13d,"-------------MENU-------------"
		db 10d,13d,"1.ADDITON "
		db 10d,13d,"2.SUBTRACTION "
		db 10d,13d,"3.MULTIPLICATION "
		db 10d,13d,"4.DIVSION "
		db 10d,13d,"5.EXIT"
		
	menulen equ $-menu
	
	fno db "First number is : ",0ah
	flen equ $-fno
	sno db "Second number is :" ,0ah
	slen equ $-sno
	res db "Result is : ",0AH
	reslen equ $-res
	e5 db "Exited :",0ah
	len5 equ $-e5

	
section .bss
ans resb 16
choice resb 2


section .text
global _start
_start:


up:	scall 1,1,menu,menulen	;keep calling menu until exit
	scall 0,0,choice,2	
	
	;jump to case1 if choice equal to 1
	
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


case1:scall 1,1,res,reslen
	call addition
	jmp up
	
case2:scall 1,1,res,reslen
	call subtraction
	jmp up
	
case3:scall 1,1,res,reslen
	call mult
	jmp up
	
case4:scall 1,1,res,reslen
	call div
	jmp up	
	
case5:scall 1,1,e5,len5

	
mov rax,60
mov rdx,0
syscall
       
addition:
	mov rcx,n
	dec rcx
	mov rsi,arr
	mov rax,[rsi]

up1: add rsi,8
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

up2: add rsi,8
     mov rbx,[rsi]
     sub rax,rbx
     loop up2
     call display
    
  ret
  
 mult:
 	mov rcx,n
 	dec rcx
 	mov rsi,arr
 	mov rax,[rsi]
 up3:add rsi,8
 	mov rbx,[rsi]
 	mul rbx
 	loop up3
 	call display
 
 ret
 
 div:mov rcx,n
 	dec rcx
 	mov rsi,arr
 	mov rax,[rsi]
 up4:add rsi,8
 	mov rdx,0
 	mov rbx,[rsi]
 	div rbx
 	loop up4
 	call display
 
 ret
 

up5: add rsi,8
     mov rbx,[rsi]
     or rax,rbx
     loop up5
     call display
     
ret


display: mov rsi,ans+15
mov rcx,16

cnt:
mov rdx,0
mov rbx,16
div rbx
cmp dl,09H
jbe add_30
add dl,07h
add_30:
add dl,30h
mov [rsi],dl
dec rsi
dec rcx
jnz cnt


scall 1,1,ans,16
ret

	
	
