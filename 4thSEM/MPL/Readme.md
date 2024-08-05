This folder contains all the microprocessor practicals i performed in my 4th semester at PICT

'Readme' file serves to help as a beginners guide that contains |General Syntax |System Calls| and |Assembly language statements|

Compilation and executing in Linux systems ( using 'NASM' ) at PICT Lab
64-bit Linux Ubuntu

    nasm -f elf64 filename.asm                                
    ld -o filename filename.asm
    ./filename

use same filename instead of 's' , as multiple 's' in single folder will make it difficult to identify 

System calls

    RAX//hold system call value
    MOV RAX,0    ;READ
    MOV RAX,1    ;WRITE
    MOV RAX,60   ;EXIT 
    RDI //stdout,file handler ,holds file handler value
    RSI//holds variable name ,buffer to be read
    ex: MOV RSI ,MSG
    RDX// no .of bytes to be read written 
    in any case
    MOV RDI,1 for both input and output

![image](https://github.com/user-attachments/assets/aeb41e58-0008-4b58-9342-fc9e9f49e6ed)


ASSEMBLY LANGUAGE PROGRAMMING
SELF | NOTES FOR REFERENCE
NAME: MISBAH BAGWAN


1.1	BASICS

An assembly program can be divided into three sections −
•	The data section,
•	The bss section, and
•	The text section.
data section:

    section.data
in this section, we declare constants ,data doesn’t change at runtime. Can declare constant values , file names ,buffer sizes etc 
example:

    section .data
        msg1 db "Program to accept 5 numbers and print them!",0xA ; 
        len1 equ $-msg1 ; length of msg1
here ; indicates beginning of comment to be ignored by compiler
bss section:
	
     section.bss
in this section we declare variables whose value can change from time to time
example:

    section .bss
        num resb 16 ; array to store the user input

above, num is an array ,resb refers to reserving bytes(8 bits) of 16 units each
if this was resw we would be telling compiler to reserve 2 bytes(1 word)(16 bits) 
this is equivalent to int arr[16]  //in my opinion – 
text section:
The text section is used for keeping the actual code. This section must begin with the declaration global _start, which tells the kernel where the program execution begins.

    section.text
       global _start
        _start:
Comments:
one line comments must precede with ;
ex:
    
    add eax, ebx     ; adds ebx to eax

ASSEMBLY LANGUAGE STATEMENTS:

•	Executable instructions or instructions,
tell the processor what to do. Each instruction consists of an operation code (opcode). Each executable instruction generates one machine language instruction.

•	Assembler directives or pseudo-ops, and
tell the assembler about the various aspects of the assembly process. These are non-executable and do not generate machine language instructions.

•	Macros.

o	a text substitution mechanism.

GENERAL SYNTAX

[label]   mnemonic   [operands]   [;comment]

mnemonics refers to instruction code opcode to be executes ,what follows the mnemonic are operands upon which operation is to be performed 

fields in square brackets above are optional, therefore it is not necessary to have label | operands | comments (depending upon operation to be performed)

some examples:

    INC COUNT        ; Increment the memory variable COUNT

    MOV TOTAL, 48    ; Transfer the value 48 in the  memory variable TOTAL
    equivalent to total=48
					  
    ADD AH, BH       ; Add the content of the  BH register into the AH register
    add dest ,source
					  
    AND MASK1, 128   ; Perform AND operation on the  variable MASK1 and 128
					  
    ADD MARKS, 10    ; Add 10 to the variable MARKS
    MOV AL, 10       ; Transfer the value 10 to the AL register

HELLO WORLD IN ASSEMBLY (64-bit)
[Online Assembler i used for practice](https://www.mycompiler.io/online-assembly-asm-compiler). 


    section  .data
        msg db "Hello world!", 0ah		;string to be printed db means define Byte
        len equ $-msg				;length of string
    section  .text
        global _start
    _start:					   ;signifies entry point
        mov rax, 1				;system call for write
        mov rdi, 1					;file handler 1(stdout)
        mov rsi, msg				;rsi holds variable name
        mov rdx, len				;rdx holds length of varianlei.ie no. of bytes
        syscall					;invoke OS to write
        mov rax, 60				;system call for exit
        mov rdi, 0
        syscall
 
EXECUTION  [LINUX  ONLY]
 

    nasm   -f   elf64   p1.asm
    ld -o   s   p1.o
    ./s

![image](https://github.com/user-attachments/assets/53f47676-1035-4295-ae71-d067c24c1b01)

![image](https://github.com/user-attachments/assets/f6557b36-d154-4b8c-a7ad-98dc8ccf814b)


 
 
 
 




  

 





