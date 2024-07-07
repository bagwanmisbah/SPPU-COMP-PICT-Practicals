; AUTHOR :  MISBAH BAGWAN 21487
section .data
    msg1 db "Array elements are: ",0ah
    len1 equ $-msg1
    msg2 db "Largest number: ",0ah
    len2 equ $-msg2
    nl db 0ah,0dh
    array db 14h, 10h, 12h, 32h, 1h

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
count resb 1

section .text
global _start
_start:

print msg1,len1

mov rbp,array  ;let rbp point to arrays first location i.e. rbp=array[0]
mov byte[count],05h ;count=05h

printall:
    mov al,[rbp] ;move current element pointed by rbp in al 
                  ;in first iteration the number would be 14 h then 10h and so on
    call display ;since current element is in hex form convert it into its equivalent ASCII from
                 ;this will be achived by calling display function while the value currently is stored in rbx register
    inc rbp ;make rbp point to the next location in array
    dec byte[count];count=count-1 
    jnz printall   ;keep executing printall until count!=0

print msg2,len2

;logic for finding out largest number and printing it :
;similar to other programming languages ,we assign the first element of array to large var
;and keep traversing the array until we find an element larger than the current large element

mov rbp,array ;let rbp point to array's first location
xor rax,rax ;we clear rax register,therefore ax,ah,al=0,this is essential for upcoming steps
mov cx,05h ;using cx register for counter purpose ,we know our array has 5 elements so using it to our advantage :D

up: cmp al,[rbp] ;we compare element pointed by rbp to value in al register
    ;currently entire rax register has 0 in it ,so al=0
    ;for first iteration rbp point to first element 14h 
    ;therefore 0 is compared to 14h
    ;if value in al is greater than 14h then jump to next label 
    ja next ;jump if above to next label 
        ;since for this iteration al=0 is not greater than 14h
        ;we dont jump 
    mov al,[rbp];if value in al not greater(it isnt),
    ;we move the current value in al register that is pointed by rbp
    ;updating the largest value found so far
    ;for this iteration  al=14h
    next:inc rbp 
        dec cx
        jnz up

;for 2nd iteration 14h is compared with next value pointed by rbp that is 10h
;10h is compared with al that contains 14h
;since 14h is greater than 10h,it jumps to label next
;in next label rbp is incremented and points to 12h
;subsequently cx is decremented to 3 and since it is not 0,we jump back to up label 

;for third iteration 14h is compared with 12h 
;therefore value in al=14h ,is compared with 12h
;since value in al is greater than 12h ,we jump to next label
;rbp points to next location and cx is decremented to 2

;for fourth iteration rbp points to 32h
;al=14h ,value in al=14h is compared with 32h
;32h is greater than 14h ,so we dont jump to next label
;we execute the statement just below it
;i.e  mov al,[rbp]
;we instruct storing of the value in al ,currently pointed by rbp that is 32h
;so now al =32h
;as always regardless of ja condition rbp is incremented 
;to next location and counter is decremented to 1

;now rbp points to final element 1h
;value in al=32h is compared to 1h
;since 32h is greater than 1h
;al is greater than value pointed by rbp
;we jump to next label that inc rbp but since cx=0 ,
;zero flag is set and we stop executing up


;At the end of entire Array traversal ,
;al finally contains largest value encountered so far 
;we print al using hex to ascii conversion 


call display 
exit

display:mov rbx,rax
    mov rsi,result
    mov cx,16

back:rol rbx,04h
    mov al,bl
    and al,0fh
    cmp al,09h
    jle add30h
    add al,07h
    add30h: add al,30h


mov byte[rsi],al
inc rsi 
dec cx
jnz back

print result,16
print nl,1
ret











;JAE transfers control to short- label if the first operand 
;(which should be unsigned) was greater than or equal to the second operand

