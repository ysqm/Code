	.file	"new.cpp"
	.text
	.globl	_Z4Readv
	.def	_Z4Readv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4Readv
_Z4Readv:
.LFB44:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	$0, %ebx
	call	getchar
	movb	%al, -81(%rbp)
.L4:
	cmpb	$47, -81(%rbp)
	jle	.L2
	cmpb	$57, -81(%rbp)
	jle	.L3
.L2:
	call	getchar
	movb	%al, -81(%rbp)
	jmp	.L4
.L3:
	cmpb	$47, -81(%rbp)
	jle	.L5
	cmpb	$57, -81(%rbp)
	jg	.L5
	movl	%ebx, %eax
	sall	$2, %eax
	addl	%ebx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movzbl	-81(%rbp), %eax
	xorl	$48, %eax
	movsbl	%al, %eax
	leal	(%rdx,%rax), %ebx
	call	getchar
	movb	%al, -81(%rbp)
	jmp	.L3
.L5:
	movl	%ebx, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB45:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movl	$0, -4(%rbp)
	call	_Z4Readv
	movl	%eax, -4(%rbp)
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	getchar;	.scl	2;	.type	32;	.endef
