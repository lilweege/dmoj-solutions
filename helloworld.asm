section .text
global _start
_start:
	; print
	mov rax, 1			; syscall: sys_write = 1
	mov rdi, 1			; fd: stdout = 1
	mov rsi, msg		; buf
	mov rdx, len		; count
	syscall
	
	; done
    mov rax, 60			; syscall: sys_exit = 60
    mov rdi, 0			; error_code: success = 0
    syscall

section .data
	msg db "Hello, World!", 0x0A
	len equ $-msg