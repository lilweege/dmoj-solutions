global _start

section .bss
    input_buf: resb INPUT_BUF_SIZE

section .data
    INPUT_BUF_SIZE equ 1048576
    I64_BUF_SIZE equ 32

    STDIN           equ     0
    STDOUT          equ     1
    SYS_READ        equ     0
    SYS_WRITE       equ     1

    NEWLINE_CHAR    equ     10
    MINUS_CHAR      equ     45
    ZERO_CHAR       equ     48



section .text

; rdi contains char to put
putc:
    push    rdi
    mov     rax, SYS_WRITE
    mov     rdi, STDOUT
    lea     rsi, [rsp]
    mov     rdx, 1
    syscall
    pop     rax
    ret


; rdi contains integer to put
puti:
    mov     rcx, rdi
    sub     rsp, 40
    mov     r10, rdi
    mov     r11, -3689348814741910323
    neg     rcx
    cmovs   rcx, rdi
    mov     edi, I64_BUF_SIZE-1
.L11:
    mov     rax, rcx
    movsx   r9, dil
    mul     r11
    movsx   r8, r9b
    lea     edi, [r9-1]
    mov     rsi, r9
    shr     rdx, 3
    lea     rax, [rdx+rdx*4]
    add     rax, rax
    sub     rcx, rax
    add     ecx, ZERO_CHAR
    mov     BYTE [rsp+r8], cl
    mov     rcx, rdx
    test    rdx, rdx
    jne     .L11
    test    r10, r10
    jns     .L12
    movsx   rax, dil
    movsx   r9d, dil
    movsx   rsi, dil
    mov     BYTE [rsp+rax], MINUS_CHAR
.L12:
    mov     rax, SYS_WRITE
    mov     rdi, STDOUT
    lea     r10, [rsp+rsi]
    mov     rsi, r10
    mov     rdx, I64_BUF_SIZE
    sub     edx, r9d
    syscall
    add     rsp, 40
    ret




; rdi contains buf to read from
; rax returns result
geti:
    mov     rax, QWORD [rdi]
    mov     rsi, rdi
    movzx   edi, BYTE [rax]
    lea     r8d, [rdi-ZERO_CHAR]
    cmp     r8b, 9
    jbe     .L2
    xor     r8d, r8d
    cmp     dil, MINUS_CHAR
    jne     .L1
    lea     rcx, [rax+3]
    lea     rdx, [rax+2]
    mov     QWORD [rsi], rdx
    movsx   r8, BYTE [rax+1]
    mov     QWORD [rsi], rcx
    movsx   rax, BYTE [rax+2]
    sub     r8, ZERO_CHAR
    lea     ecx, [rax-ZERO_CHAR]
    cmp     cl, 9
    ja      .L4
.L6:
    add     rdx, 2
.L5:
    lea     rcx, [r8+r8*4]
    mov     QWORD [rsi], rdx
    add     rdx, 1
    lea     r8, [rax-ZERO_CHAR+rcx*2]
    movsx   rax, BYTE [rdx-2]
    lea     ecx, [rax-ZERO_CHAR]
    cmp     cl, 9
    jbe     .L5
    cmp     dil, MINUS_CHAR
    jne     .L1
.L4:
    neg     r8
.L1:
    mov     rax, r8
    ret
.L2:
    lea     rcx, [rax+2]
    lea     rdx, [rax+1]
    movsx   r8, r8b
    mov     QWORD [rsi], rcx
    movsx   rax, BYTE [rax+1]
    lea     ecx, [rax-ZERO_CHAR]
    cmp     cl, 9
    jbe     .L6
    jmp     .L1


read:
    mov     rax, SYS_READ
    mov     rdi, STDIN
    mov     rsi, input_buf
    mov     rdx, INPUT_BUF_SIZE
    syscall
    ret


_start:
    call    read
    push    input_buf

    lea     rdi, [rsp]
    call    geti
    push    rax

loop:
    pop     rcx
    cmp     rcx, 0
    je      done
    dec     rcx
    push    rcx
    
    lea     rdi, [rsp+8]
    call    geti
    push    rax

    lea     rdi, [rsp+16]
    call    geti

    pop     rdi
    add     rdi, rax
    call    puti

    mov     rdi, NEWLINE_CHAR
    call    putc

    jmp     loop


done:
    mov     rax, 60
    mov     rdi, 0
    syscall