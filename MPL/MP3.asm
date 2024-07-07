section .data
  msg1 db "Array elements are: ",0ah
  len1 equ $-msg1

  msg2 db "Largest number is : ",0ah
  len2 equ $-msg2

  endl db 0ah,0dh
  array db 1h,14h,34h,23h,78h

%macro print 2
    mov rax,1
    mov rdi,1
    mov rsi,%1
    mov rdx,%2
    syscall
%endmacro

%macro exit 0
    mov rax,60
    mov rdi,0
    syscall
%endmacro

section .bss 
    result resb 16
    counter resb 1

section .text
global _start
_start:

print msg1,len1

    mov rbp,array ;rbp=array[0]
    mov byte[counter],05h ;counter=5
print_array_element:
    mov al,[rbp] ;
    call display
    inc rbp
    dec byte[counter]
    jnz print_array_element

print msg2,len2

;for finding largest number

mov rbp,array
xor rax,rax ;entire rax register has zero in it .Therefore , large=a[0] here large =al 
mov cx,05h
b2:cmp al,[rbp] ;compare value in al that is zero with the first index of array
    ja next ;if value is greater than jump to label next 
    mov al,[rbp] ;else if value is not greater , make large = current value ,therefore al will contain value greater value enountered till now
next:inc rbp
    dec cx
    jnz b2

call display

exit 

display: 
    mov rbx,rax
    mov rsi,result
	mov cx,16
    
back:  rol rbx,04h
	   mov al,bl
	   and al,0Fh
	   cmp al,09h
	   jle add_30
	   add al,07h
	   add_30:  add al,30h
mov byte[rsi],al
inc rsi
dec cx
jnz back	
print result,16
print  endl,1
ret


