#HELLO WORLD IN ASSEMBLY (64-bit)
#https://www.mycompiler.io/online-assembly-asm-compiler
#ctrl+click to follow above link | to be used for practice 

section  .data
    msg db "Hello world!", 0ah		;string to be printed db means define Byte
    len equ $-msg				;length of string
section  .text
    global _start
_start:					      ;signifies entry point
    mov rax, 1				;system call for write
    mov rdi, 1					;file handler 1(stdout)
    mov rsi, msg				;rsi holds variable name
    mov rdx, len				;rdx holds length of varianlei.ie no. of bytes
    syscall					;invoke OS to write
    mov rax, 60				;system call for exit
    mov rdi, 0
    syscall
