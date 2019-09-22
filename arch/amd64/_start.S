.global _start

.section .text

.extern main

_start:
	xor	%rbp,%rbp
	pop	%rdi
	mov	%rsp,%rsi
	call	main

	mov	%rax,%rdi /* Move the return value of main to the error code arg of sys_exit.  */
        mov     $60,%rax  
	syscall
	
	
