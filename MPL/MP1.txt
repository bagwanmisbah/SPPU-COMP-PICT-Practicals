section .data
    msg1 db "Enter 5 Hexadecimal values: ",10,13
    len1 equ $-msg1
    msg2 db "The hexadecimal numbers are: ",10,13
    len2 equ $-msg2
    cnt db 05h
    mov r8,00h
section .bss
    num resb 16
section .text
global _start
_start:
ipmsg:mov rax,1
     mov rdi,1
     mov rsi,msg1
     mov rdx,len1
     syscall
     mov r8,num    
ipnum:mov rax,0
      mov rdi,0
      mov rsi,r8
      mov rdx,17
      syscall
      add r8,17
      dec byte[cnt]
      jnz ipnum
opmsg:mov rax,1
      mov rdi,1
      mov rsi,msg2
      mov rdx,len2
      syscall
      mov byte[cnt],05h
      mov r8,num
opnum:mov rax,1
      mov rdi,1
      mov rsi,r8
      mov rdx,17
      syscall
      add r8,17
      dec byte[cnt]
      jnz opnum
exit:mov rax,60
    mov rdi,0
    syscall
