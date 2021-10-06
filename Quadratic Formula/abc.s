	.file	"abc.c"
	.comm	_x1real, 8, 3
	.comm	_x2real, 8, 3
	.comm	_ximag, 8, 3
	.text
	.globl	_discriminant
	.def	_discriminant;	.scl	2;	.type	32;	.endef
_discriminant:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	_b, %eax
	movl	%eax, -20(%ebp)
	fildl	-20(%ebp)
	fldl	LC0
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_pow
	movl	_a, %eax
	leal	0(,%eax,4), %edx
	movl	_c, %eax
	imull	%edx, %eax
	movl	%eax, -20(%ebp)
	fildl	-20(%ebp)
	fsubrp	%st, %st(1)
	fnstcw	-10(%ebp)
	movzwl	-10(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -12(%ebp)
	fldcw	-12(%ebp)
	fistpl	-16(%ebp)
	fldcw	-10(%ebp)
	movl	-16(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.globl	_abc
	.def	_abc;	.scl	2;	.type	32;	.endef
_abc:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	call	_discriminant
	testl	%eax, %eax
	js	L4
	movl	_b, %eax
	negl	%eax
	movl	%eax, -40(%ebp)
	fildl	-40(%ebp)
	fstpt	-40(%ebp)
	call	_discriminant
	movl	%eax, -20(%ebp)
	fildl	-20(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldt	-40(%ebp)
	faddp	%st, %st(1)
	movl	_a, %eax
	addl	%eax, %eax
	movl	%eax, -40(%ebp)
	fildl	-40(%ebp)
	fdivrp	%st, %st(1)
	fstpl	-16(%ebp)
	fldl	-16(%ebp)
	fstpl	_x1real
	movl	_b, %eax
	negl	%eax
	movl	%eax, -40(%ebp)
	fildl	-40(%ebp)
	fstpt	-40(%ebp)
	call	_discriminant
	movl	%eax, -20(%ebp)
	fildl	-20(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fldt	-40(%ebp)
	fsubp	%st, %st(1)
	movl	_a, %eax
	addl	%eax, %eax
	movl	%eax, -40(%ebp)
	fildl	-40(%ebp)
	fdivrp	%st, %st(1)
	fstpl	-16(%ebp)
	fldl	-16(%ebp)
	fstpl	_x2real
	fldz
	fstpl	_ximag
	jmp	L6
L4:
	movl	_b, %eax
	negl	%eax
	movl	_a, %edx
	leal	(%edx,%edx), %ecx
	cltd
	idivl	%ecx
	movl	%eax, -40(%ebp)
	fildl	-40(%ebp)
	fstpl	_x1real
	fldl	_x1real
	fstpl	_x2real
	call	_discriminant
	negl	%eax
	movl	%eax, -40(%ebp)
	fildl	-40(%ebp)
	fstpl	(%esp)
	call	_sqrt
	fstpl	_ximag
L6:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.section .rdata,"dr"
	.align 8
LC0:
	.long	0
	.long	1073741824
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_pow;	.scl	2;	.type	32;	.endef
	.def	_sqrt;	.scl	2;	.type	32;	.endef
