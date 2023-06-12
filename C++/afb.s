	.file	"a.cpp"
	.text
	.globl	_Z4fbciii
	.def	_Z4fbciii;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z4fbciii
_Z4fbciii:
.LFB0:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %eax
	cmpl	24(%rbp), %eax
	jle	.L2
	movl	24(%rbp), %eax
	movl	%eax, 16(%rbp)
	jmp	.L3
.L2:
	movl	16(%rbp), %eax
	movl	%eax, 24(%rbp)
.L3:
	movl	$0, %eax
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
