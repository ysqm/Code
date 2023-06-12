	.file	"RBT.cpp"
	.text
	.section	.text$_Z5scanfPKcz,"x"
	.linkonce discard
	.globl	_Z5scanfPKcz
	.def	_Z5scanfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z5scanfPKcz
_Z5scanfPKcz:
.LFB2:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z6printfPKcz
_Z6printfPKcz:
.LFB8:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%r8, -32(%rbp)
	movq	%r9, -24(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, -96(%rbp)
	movq	-96(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	-48(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -84(%rbp)
	movl	-84(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN12RedBlackTree3RBT8WhichSonEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN12RedBlackTree3RBT8WhichSonEv
	.def	_ZN12RedBlackTree3RBT8WhichSonEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT8WhichSonEv
_ZN12RedBlackTree3RBT8WhichSonEv:
.LFB44:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	32(%rax), %rax
	testq	%rax, %rax
	jne	.L6
	movl	$-1, %eax
	jmp	.L7
.L6:
	movq	16(%rbp), %rax
	movq	32(%rax), %rax
	movq	24(%rax), %rax
	cmpq	%rax, 16(%rbp)
	sete	%al
	movzbl	%al, %eax
.L7:
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN12RedBlackTree3RBT6UpdateEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN12RedBlackTree3RBT6UpdateEv
	.def	_ZN12RedBlackTree3RBT6UpdateEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT6UpdateEv
_ZN12RedBlackTree3RBT6UpdateEv:
.LFB45:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L9
	movq	16(%rbp), %rax
	movq	16(%rax), %rax
	movl	4(%rax), %eax
	jmp	.L10
.L9:
	movl	$0, %eax
.L10:
	addl	%eax, %edx
	movq	16(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	je	.L11
	movq	16(%rbp), %rax
	movq	24(%rax), %rax
	movl	4(%rax), %eax
	jmp	.L12
.L11:
	movl	$0, %eax
.L12:
	addl	%eax, %edx
	movq	16(%rbp), %rax
	movl	%edx, 4(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN12RedBlackTree3RBT6botherEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN12RedBlackTree3RBT6botherEv
	.def	_ZN12RedBlackTree3RBT6botherEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT6botherEv
_ZN12RedBlackTree3RBT6botherEv:
.LFB47:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -64(%rbp)
	movq	-64(%rbp), %rax
	movq	32(%rax), %rax
	testq	%rax, %rax
	je	.L14
	movq	-64(%rbp), %rax
	movq	32(%rax), %rbx
	movq	-64(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT8WhichSonEv
	xorl	$1, %eax
	cltq
	addq	$2, %rax
	movq	(%rbx,%rax,8), %rax
	jmp	.L16
.L14:
	movl	$0, %eax
.L16:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN12RedBlackTree3RBT9IsTwonodeEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN12RedBlackTree3RBT9IsTwonodeEv
	.def	_ZN12RedBlackTree3RBT9IsTwonodeEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT9IsTwonodeEv
_ZN12RedBlackTree3RBT9IsTwonodeEv:
.LFB48:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L18
	movl	$0, %eax
	jmp	.L23
.L18:
	movq	16(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L20
	movq	16(%rbp), %rax
	movq	16(%rax), %rax
	movzbl	(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L21
.L20:
	movl	$1, %eax
	jmp	.L23
.L21:
	movl	$0, %eax
.L23:
	popq	%rbp
	ret
	.seh_endproc
	.text
	.align 2
	.globl	_ZN12RedBlackTree3RBTC2Ejii
	.def	_ZN12RedBlackTree3RBTC2Ejii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBTC2Ejii
_ZN12RedBlackTree3RBTC2Ejii:
.LFB50:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movl	%r9d, 40(%rbp)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, 4(%rax)
	movq	16(%rbp), %rax
	movl	32(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	16(%rbp), %rax
	movl	40(%rbp), %edx
	movl	%edx, 12(%rax)
	movq	16(%rbp), %rax
	movq	$0, 24(%rax)
	movq	16(%rbp), %rax
	movq	24(%rax), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	16(%rbp), %rax
	movq	16(%rax), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, 32(%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN12RedBlackTree3RBTC1Ejii
	.def	_ZN12RedBlackTree3RBTC1Ejii;	.scl	2;	.type	32;	.endef
	.set	_ZN12RedBlackTree3RBTC1Ejii,_ZN12RedBlackTree3RBTC2Ejii
	.align 2
	.globl	_ZN12RedBlackTree3RBTD2Ev
	.def	_ZN12RedBlackTree3RBTD2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBTD2Ev
_ZN12RedBlackTree3RBTD2Ev:
.LFB53:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN12RedBlackTree3RBTD1Ev
	.def	_ZN12RedBlackTree3RBTD1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN12RedBlackTree3RBTD1Ev,_ZN12RedBlackTree3RBTD2Ev
	.align 2
	.globl	_ZN12RedBlackTree3RBT6createEi
	.def	_ZN12RedBlackTree3RBT6createEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT6createEi
_ZN12RedBlackTree3RBT6createEi:
.LFB55:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -48(%rbp)
	movl	%edx, -40(%rbp)
	movl	$40, %ecx
	call	_Znwy
	movq	%rax, %rbx
	movl	-40(%rbp), %eax
	movl	%eax, %r9d
	movl	$1, %r8d
	movl	$1, %edx
	movq	%rbx, %rcx
	call	_ZN12RedBlackTree3RBTC1Ejii
	movq	%rbx, -88(%rbp)
	movq	-88(%rbp), %rax
	movb	$1, (%rax)
	movq	-88(%rbp), %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT10updatelineEv
	.def	_ZN12RedBlackTree3RBT10updatelineEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT10updatelineEv
_ZN12RedBlackTree3RBT10updatelineEv:
.LFB56:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, -8(%rbp)
.L30:
	cmpq	$0, -8(%rbp)
	je	.L31
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT6UpdateEv
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L30
.L31:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	.def	_ZN12RedBlackTree3RBT4linkEPS0_S1_b;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
_ZN12RedBlackTree3RBT4linkEPS0_S1_b:
.LFB57:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movl	%r9d, %eax
	movb	%al, 40(%rbp)
	cmpq	$0, 24(%rbp)
	je	.L33
	movzbl	40(%rbp), %edx
	movq	24(%rbp), %rax
	movslq	%edx, %rdx
	addq	$2, %rdx
	movq	32(%rbp), %rcx
	movq	%rcx, (%rax,%rdx,8)
.L33:
	cmpq	$0, 32(%rbp)
	je	.L35
	movq	32(%rbp), %rax
	movq	24(%rbp), %rdx
	movq	%rdx, 32(%rax)
.L35:
	nop
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT6rotateEPS0_b
	.def	_ZN12RedBlackTree3RBT6rotateEPS0_b;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT6rotateEPS0_b
_ZN12RedBlackTree3RBT6rotateEPS0_b:
.LFB58:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	%r8d, %eax
	movb	%al, 32(%rbp)
	cmpq	$0, 24(%rbp)
	je	.L40
	movzbl	32(%rbp), %edx
	movq	24(%rbp), %rax
	movslq	%edx, %rdx
	addq	$2, %rdx
	movq	(%rax,%rdx,8), %rax
	testq	%rax, %rax
	je	.L40
	movq	24(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -8(%rbp)
	movzbl	32(%rbp), %edx
	movq	24(%rbp), %rax
	movslq	%edx, %rdx
	addq	$2, %rdx
	movq	(%rax,%rdx,8), %rax
	movq	%rax, -16(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT8WhichSonEv
	testl	%eax, %eax
	setne	%al
	movzbl	%al, %edx
	movq	-16(%rbp), %rcx
	movq	-8(%rbp), %rax
	movl	%edx, %r9d
	movq	%rcx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movzbl	32(%rbp), %edx
	movzbl	32(%rbp), %eax
	xorl	$1, %eax
	movzbl	%al, %ecx
	movq	-16(%rbp), %rax
	movslq	%ecx, %rcx
	addq	$2, %rcx
	movq	(%rax,%rcx,8), %rcx
	movq	24(%rbp), %rax
	movl	%edx, %r9d
	movq	%rcx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movzbl	32(%rbp), %eax
	xorl	$1, %eax
	movzbl	%al, %edx
	movq	24(%rbp), %rcx
	movq	-16(%rbp), %rax
	movl	%edx, %r9d
	movq	%rcx, %r8
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movq	24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT6UpdateEv
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT6UpdateEv
	jmp	.L36
.L40:
	nop
.L36:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT11ChangeColorEv
	.def	_ZN12RedBlackTree3RBT11ChangeColorEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT11ChangeColorEv
_ZN12RedBlackTree3RBT11ChangeColorEv:
.LFB59:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, -8(%rbp)
.L48:
	cmpq	$0, -8(%rbp)
	je	.L49
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L50
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	je	.L45
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L45
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L46
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L46
	movq	-8(%rbp), %rax
	movb	$1, (%rax)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movb	$0, (%rax)
	movq	-8(%rbp), %rdx
	movq	16(%rdx), %rdx
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	jmp	.L45
.L46:
	movq	-8(%rbp), %rax
	movb	$1, (%rax)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movb	$0, (%rax)
	movq	-8(%rbp), %rax
	movl	$1, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT6rotateEPS0_b
.L45:
	movq	-8(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L48
.L50:
	nop
	jmp	.L48
.L49:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT6InsertEi
	.def	_ZN12RedBlackTree3RBT6InsertEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT6InsertEi
_ZN12RedBlackTree3RBT6InsertEi:
.LFB60:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	_ZN12RedBlackTree3RBT4rootE(%rip), %rax
	testq	%rax, %rax
	jne	.L52
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT6createEi
	movq	%rax, _ZN12RedBlackTree3RBT4rootE(%rip)
	movq	_ZN12RedBlackTree3RBT4rootE(%rip), %rax
	movb	$0, (%rax)
	jmp	.L61
.L52:
	movq	_ZN12RedBlackTree3RBT4rootE(%rip), %rax
	movq	%rax, -8(%rbp)
.L55:
	cmpq	$0, -8(%rbp)
	je	.L54
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	je	.L54
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	24(%rbp), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT9chooseSonEi
	movq	%rax, -8(%rbp)
	jmp	.L55
.L54:
	cmpq	$0, -8(%rbp)
	je	.L56
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT10updatelineEv
	jmp	.L57
.L56:
	movq	-16(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jge	.L58
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT6createEi
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 16(%rax)
	jmp	.L57
.L58:
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT6createEi
	movq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, 24(%rax)
.L57:
	cmpq	$0, -8(%rbp)
	jne	.L61
	movq	-16(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L59
	movq	-16(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jle	.L60
	movq	-16(%rbp), %rax
	movl	$1, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT6rotateEPS0_b
.L60:
	movq	-16(%rbp), %rax
	movb	$0, (%rax)
	movq	-16(%rbp), %rax
	movq	32(%rax), %rax
	movb	$1, (%rax)
	movq	-16(%rbp), %rax
	movq	32(%rax), %rax
	movl	$0, %r8d
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT6rotateEPS0_b
.L59:
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT11ChangeColorEv
.L61:
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT6DeleteEi
	.def	_ZN12RedBlackTree3RBT6DeleteEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT6DeleteEi
_ZN12RedBlackTree3RBT6DeleteEi:
.LFB61:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$88, %rsp
	.seh_stackalloc	88
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -16(%rbp)
	movl	%edx, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	movq	-16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4FindEi
	movq	%rax, -64(%rbp)
	cmpq	$0, -64(%rbp)
	je	.L83
	movq	-64(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	$1, %eax
	jle	.L64
	movq	-64(%rbp), %rax
	movl	8(%rax), %eax
	leal	-1(%rax), %edx
	movq	-64(%rbp), %rax
	movl	%edx, 8(%rax)
	movq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT10updatelineEv
	jmp	.L83
.L64:
	movq	-64(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -56(%rbp)
	cmpq	$0, -56(%rbp)
	je	.L66
.L78:
	movq	-56(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L67
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L68
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	je	.L68
.L67:
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L84
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -56(%rbp)
	jmp	.L71
.L68:
	movq	-64(%rbp), %rax
	movq	24(%rax), %rax
	cmpq	%rax, -56(%rbp)
	jne	.L72
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L73
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movb	$1, (%rax)
.L73:
	movq	-56(%rbp), %rax
	movq	24(%rax), %rax
	testq	%rax, %rax
	je	.L74
	movq	-56(%rbp), %rax
	movq	24(%rax), %rax
	movb	$1, (%rax)
	jmp	.L74
.L72:
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT6botherEv
	testq	%rax, %rax
	setne	%al
	testb	%al, %al
	je	.L75
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT6botherEv
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT9IsTwonodeEv
	testb	%al, %al
	je	.L76
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT6botherEv
	movb	$1, (%rax)
	movq	-56(%rbp), %rax
	movb	$1, (%rax)
	movq	-56(%rbp), %rax
	movq	32(%rax), %rax
	movb	$0, (%rax)
	jmp	.L74
.L76:
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT6botherEv
	movq	%rax, -72(%rbp)
	movq	-56(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -80(%rbp)
	movq	-72(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -88(%rbp)
	movq	-80(%rbp), %rax
	movq	32(%rax), %rax
	movq	-88(%rbp), %rdx
	movl	$0, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movq	-88(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-72(%rbp), %rax
	movl	$0, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movq	-72(%rbp), %rdx
	movq	-88(%rbp), %rax
	movl	$1, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movq	-88(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-80(%rbp), %rax
	movl	$1, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movq	-80(%rbp), %rdx
	movq	-88(%rbp), %rax
	movl	$0, %r9d
	movq	%rdx, %r8
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movq	-80(%rbp), %rax
	movb	$0, (%rax)
	movq	-56(%rbp), %rax
	movb	$1, (%rax)
	movq	-72(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT6UpdateEv
	jmp	.L74
.L75:
	movq	-56(%rbp), %rax
	movb	$1, (%rax)
	movq	-56(%rbp), %rax
	movq	32(%rax), %rax
	movb	$0, (%rax)
.L74:
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L78
	movq	-56(%rbp), %rax
	movb	$1, (%rax)
.L71:
	jmp	.L78
.L84:
	nop
	movq	-56(%rbp), %rax
	movl	12(%rax), %edx
	movq	-64(%rbp), %rax
	movl	%edx, 12(%rax)
	movq	-56(%rbp), %rax
	movl	8(%rax), %edx
	movq	-64(%rbp), %rax
	movl	%edx, 8(%rax)
	movq	-56(%rbp), %rax
	movl	$0, 4(%rax)
	movq	-56(%rbp), %rax
	movl	$0, 8(%rax)
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT10updatelineEv
	jmp	.L83
.L66:
	movq	-64(%rbp), %rax
	movzbl	(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L79
	movq	-64(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L79
	movq	-64(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -56(%rbp)
	movq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT8WhichSonEv
	testl	%eax, %eax
	setne	%al
	movzbl	%al, %edx
	movq	-64(%rbp), %rax
	movq	32(%rax), %rax
	movq	-56(%rbp), %rcx
	movl	%edx, %r9d
	movq	%rcx, %r8
	movq	%rax, %rdx
	movq	-16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT4linkEPS0_S1_b
	movq	-64(%rbp), %rbx
	testq	%rbx, %rbx
	je	.L80
	movq	%rbx, %rcx
	call	_ZN12RedBlackTree3RBTD1Ev
	movl	$40, %edx
	movq	%rbx, %rcx
	call	_ZdlPvy
.L80:
	movq	-56(%rbp), %rax
	movb	$0, (%rax)
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT10updatelineEv
	jmp	.L83
.L79:
	movq	-64(%rbp), %rax
	movq	32(%rax), %rax
	movq	%rax, -56(%rbp)
	movq	-64(%rbp), %rbx
	testq	%rbx, %rbx
	je	.L81
	movq	%rbx, %rcx
	call	_ZN12RedBlackTree3RBTD1Ev
	movl	$40, %edx
	movq	%rbx, %rcx
	call	_ZdlPvy
.L81:
	movq	-56(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT10updatelineEv
.L83:
	nop
	addq	$88, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT9chooseSonEi
	.def	_ZN12RedBlackTree3RBT9chooseSonEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT9chooseSonEi
_ZN12RedBlackTree3RBT9chooseSonEi:
.LFB62:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jge	.L86
	movq	16(%rbp), %rax
	movq	24(%rax), %rax
	jmp	.L87
.L86:
	movq	16(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jle	.L88
	movq	16(%rbp), %rax
	movq	16(%rax), %rax
	jmp	.L87
.L88:
	movq	16(%rbp), %rax
.L87:
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT4FindEi
	.def	_ZN12RedBlackTree3RBT4FindEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT4FindEi
_ZN12RedBlackTree3RBT4FindEi:
.LFB63:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	_ZN12RedBlackTree3RBT4rootE(%rip), %rax
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L90
.L91:
	cmpq	$0, -8(%rbp)
	je	.L90
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	je	.L90
	movl	24(%rbp), %edx
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN12RedBlackTree3RBT9chooseSonEi
	movq	%rax, -8(%rbp)
	jmp	.L91
.L90:
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT7get_PreEi
	.def	_ZN12RedBlackTree3RBT7get_PreEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT7get_PreEi
_ZN12RedBlackTree3RBT7get_PreEi:
.LFB64:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	_ZN12RedBlackTree3RBT4rootE(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	$0, -16(%rbp)
.L97:
	cmpq	$0, -8(%rbp)
	je	.L94
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jle	.L95
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L97
.L95:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L97
.L94:
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT7get_SufEi
	.def	_ZN12RedBlackTree3RBT7get_SufEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT7get_SufEi
_ZN12RedBlackTree3RBT7get_SufEi:
.LFB65:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	_ZN12RedBlackTree3RBT4rootE(%rip), %rax
	movq	%rax, -8(%rbp)
	movq	$0, -16(%rbp)
.L103:
	cmpq	$0, -8(%rbp)
	je	.L100
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jge	.L101
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L103
.L101:
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L103
.L100:
	movq	-16(%rbp), %rax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT3PreEi
	.def	_ZN12RedBlackTree3RBT3PreEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT3PreEi
_ZN12RedBlackTree3RBT3PreEi:
.LFB66:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT7get_PreEi
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L106
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	jmp	.L108
.L106:
	movl	$-1, %eax
.L108:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT3SufEi
	.def	_ZN12RedBlackTree3RBT3SufEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT3SufEi
_ZN12RedBlackTree3RBT3SufEi:
.LFB67:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movq	16(%rbp), %rcx
	call	_ZN12RedBlackTree3RBT7get_SufEi
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L110
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	jmp	.L112
.L110:
	movl	$-1, %eax
.L112:
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT4RankEi
	.def	_ZN12RedBlackTree3RBT4RankEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT4RankEi
_ZN12RedBlackTree3RBT4RankEi:
.LFB68:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	movq	_ZN12RedBlackTree3RBT4rootE(%rip), %rax
	movq	%rax, -16(%rbp)
.L121:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jge	.L114
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	jne	.L115
	movq	-16(%rbp), %rax
	movl	8(%rax), %eax
	addl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L116
	movq	-16(%rbp), %rax
	movl	12(%rax), %eax
	jmp	.L117
.L116:
	movq	-16(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L121
.L115:
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	movl	4(%rax), %edx
	movl	-4(%rbp), %eax
	addl	%eax, %edx
	movl	24(%rbp), %eax
	cmpl	%eax, %edx
	jnb	.L119
	movq	-16(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %edx
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	movl	4(%rax), %eax
	addl	%eax, %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L120
	movq	-16(%rbp), %rax
	movl	12(%rax), %eax
	jmp	.L117
.L120:
	movq	-16(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L121
.L119:
	movq	-16(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L121
.L114:
	movl	$-1, %eax
.L117:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN12RedBlackTree3RBT8Get_RankEi
	.def	_ZN12RedBlackTree3RBT8Get_RankEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN12RedBlackTree3RBT8Get_RankEi
_ZN12RedBlackTree3RBT8Get_RankEi:
.LFB69:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	_ZN12RedBlackTree3RBT4rootE(%rip), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -12(%rbp)
.L130:
	cmpq	$0, -8(%rbp)
	je	.L123
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jge	.L124
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L130
.L124:
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jle	.L126
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L127
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movl	4(%rax), %eax
	jmp	.L128
.L127:
	movl	$0, %eax
.L128:
	addl	%eax, %edx
	movl	-12(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%rbp)
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rax, -8(%rbp)
	jmp	.L130
.L126:
	movl	-12(%rbp), %eax
	addl	$1, %eax
	jmp	.L129
.L123:
	movl	$-1, %eax
.L129:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN12RedBlackTree3RBT4rootE
	.bss
	.align 8
_ZN12RedBlackTree3RBT4rootE:
	.space 8
	.globl	T
	.align 32
T:
	.space 40
	.globl	n
	.align 4
n:
	.space 4
	.globl	opt
	.align 4
opt:
	.space 4
	.globl	x
	.align 4
x:
	.space 4
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "r\0"
.LC1:
	.ascii "RBT.in\0"
.LC2:
	.ascii "%d\0"
.LC3:
	.ascii "%d%d\0"
.LC4:
	.ascii "%d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB70:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	call	__main
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rax, %r8
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	freopen
	leaq	n(%rip), %rdx
	leaq	.LC2(%rip), %rcx
	call	_Z5scanfPKcz
.L141:
	movl	n(%rip), %eax
	leal	-1(%rax), %edx
	movl	%edx, n(%rip)
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	.L132
	leaq	x(%rip), %r8
	leaq	opt(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	call	_Z5scanfPKcz
	movl	opt(%rip), %eax
	cmpl	$6, %eax
	ja	.L141
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L135(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L135(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L135:
	.long	.L141-.L135
	.long	.L140-.L135
	.long	.L139-.L135
	.long	.L138-.L135
	.long	.L137-.L135
	.long	.L136-.L135
	.long	.L134-.L135
	.text
.L140:
	movl	x(%rip), %eax
	movl	%eax, %edx
	leaq	T(%rip), %rcx
	call	_ZN12RedBlackTree3RBT6InsertEi
	jmp	.L133
.L139:
	movl	x(%rip), %eax
	movl	%eax, %edx
	leaq	T(%rip), %rcx
	call	_ZN12RedBlackTree3RBT6DeleteEi
	jmp	.L133
.L138:
	movl	x(%rip), %eax
	movl	%eax, %edx
	leaq	T(%rip), %rcx
	call	_ZN12RedBlackTree3RBT8Get_RankEi
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	_Z6printfPKcz
	jmp	.L133
.L137:
	movl	x(%rip), %eax
	movl	%eax, %edx
	leaq	T(%rip), %rcx
	call	_ZN12RedBlackTree3RBT4RankEi
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	_Z6printfPKcz
	jmp	.L133
.L136:
	movl	x(%rip), %eax
	movl	%eax, %edx
	leaq	T(%rip), %rcx
	call	_ZN12RedBlackTree3RBT3PreEi
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	_Z6printfPKcz
	jmp	.L133
.L134:
	movl	x(%rip), %eax
	movl	%eax, %edx
	leaq	T(%rip), %rcx
	call	_ZN12RedBlackTree3RBT3SufEi
	movl	%eax, %edx
	leaq	.LC4(%rip), %rcx
	call	_Z6printfPKcz
	nop
.L133:
	jmp	.L141
.L132:
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB72:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	T(%rip), %rcx
	call	_ZN12RedBlackTree3RBTD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB71:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L146
	cmpl	$65535, 24(%rbp)
	jne	.L146
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %edx
	leaq	T(%rip), %rcx
	call	_ZN12RedBlackTree3RBTC1Ejii
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L146:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__ZN12RedBlackTree3RBTC2Ejii;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__ZN12RedBlackTree3RBTC2Ejii
_GLOBAL__sub_I__ZN12RedBlackTree3RBTC2Ejii:
.LFB73:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__ZN12RedBlackTree3RBTC2Ejii
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	_ZdlPvy;	.scl	2;	.type	32;	.endef
	.def	freopen;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
