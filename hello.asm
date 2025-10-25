; File: add.asm
; Assemble: nasm -f win64 add.asm -o add.obj
; Link:   gcc add.obj -o add.exe

section .data
    num1 dq 5          ; first number
    num2 dq 10         ; second number
    fmt db "Sum: %d", 10, 0  ; format string with newline

section .text
    global main
    extern printf

main:
    ; Load numbers into registers
    mov rax, [num1]
    add rax, [num2]    ; rax = num1 + num2

    ; Prepare arguments for printf
    mov rdi, fmt       ; first argument: format string
    mov rsi, rax       ; second argument: value to print
    xor rax, rax       ; rax = 0, required for variadic functions on Windows
    call printf

    ; Return 0
    mov eax, 0
    ret
