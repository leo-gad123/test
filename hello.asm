section .data
    Dta db "MyGod", 10, 0        ; Add newline (10) and null terminator (0)

section .text
    global main
    extern printf

main:
    sub rsp, 40                   ; Reserve 40 bytes (stack alignment for Windows x64 ABI)
    lea rcx, [Dta]                ; Load address of Dta into RCX (1st argument to printf)
    call printf                   ; Call printf(Dta)
    add rsp, 40                   ; Restore stack
    ret
