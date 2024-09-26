section .data
    result dq 1   ; Define the variable to store the result

section .text
    global _start

_start:
    ; Call the factorial function
    mov rdi, 5         ; Set the value whose factorial to calculate
    call factorial

    ; Print the result
    mov rax, 60        ; syscall number for sys_exit
    xor edi, edi       ; exit code 0
    syscall

factorial:
    ; Factorial function
    ; Input: rdi contains the value whose factorial to calculate
    ; Output: result contains the factorial of rdi

    ; Initialize the result to 1
    mov rax, 1
    mov qword [result], rax

    ; Loop to calculate factorial
    mov rcx, rdi       ; Load the value of n into rcx for the loop counter
    mov rax, 1         ; Initialize the loop multiplication factor

calc_loop:
    cmp rcx, 1         ; Check if n == 1
    jle end_calc_loop  ; If n <= 1, exit the loop

    ; Multiply the result with n
    mul rax            ; Multiply the current result with rax (1, 2, 3, ..., n)
    mov qword [result], rax  ; Store the result in the result variable

    ; Decrement n
    dec rcx            ; Decrement n for the next iteration

    ; Increment the multiplication factor
    inc rax            ; Increment the multiplication factor for the next iteration

    jmp calc_loop      ; Jump back to the beginning of the loop

end_calc_loop:
    ret
