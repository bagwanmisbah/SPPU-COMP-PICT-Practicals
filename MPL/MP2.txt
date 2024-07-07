section .data
    msg1 db "Enter string : ",0ah
    len1 equ $-msg1

    msg2 db "Length of string: ",0ah
    len2 equ $-msg2

section .bss
    string resb 200
    result resb 200

section .text
global _start
    _start: mov rax,1
            mov rdi,1
            mov rsi,msg1
            mov rdx,len1
            syscall 

            mov rax,0
            mov rdi,0
            mov rsi,string
            mov rdx,200
            syscall

            mov rbx,rax ;move length of string stored in rax to rbx  ;b=a
            mov rbp,result ;rbp points to the first location of result ;bp=result[0]
            mov cx,16h ;using cx to count nibbles processed  ;c=16

        back: rol rbx,04h ;rotate left the value stored in rbx by 4 ;rotating four digits
            mov al,bl ;bl contains rotated value ;store rotated digits 
            and al,0fh;gives last nibble of value ; take units value
            cmp al,09h ;compare bl with 09h(ascii 9)
            jg add37 ;if value greater than 9 then jump to label add37
            add al,30h ;if value aint greater add 30h
            jmp skip

            add37: add al,37h

            skip:
                mov byte[rbp],al ;mov ascii value to current position in al 
                inc rbp ;add rbp,1
                dec cx 
                jnz back ;jump to label back if there are more nibbles to process 

            mov rax,1
            mov rdi,1
            mov rsi,msg2
            mov rdx,len2
            syscall
            
            mov rax,1
            mov rdi,1
            mov rsi,result
            mov rdx,16
            syscall
