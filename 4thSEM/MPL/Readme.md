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

  

 





