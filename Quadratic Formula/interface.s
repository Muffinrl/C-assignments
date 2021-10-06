	.file	"interface.c"
	.text
	.def	_printf;	.scl	3;	.type	32;	.endef
_printf:
LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	.cfi_offset 3, -12
	leal	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_vprintf
	movl	%eax, %ebx
	movl	%ebx, %eax
	addl	$36, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE1:
	.comm	_a, 4, 2
	.comm	_b, 4, 2
	.comm	_c, 4, 2
	.section .rdata,"dr"
LC0:
	.ascii "%d\12%d\12%d\0"
	.text
	.def	_get_parameters;	.scl	3;	.type	32;	.endef
_get_parameters:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$_c, 12(%esp)
	movl	$_b, 8(%esp)
	movl	$_a, 4(%esp)
	movl	$LC0, (%esp)
	call	_scanf
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.section .rdata,"dr"
	.align 4
LC1:
	.ascii "The roots of %dx^2 + %dx + %d are:\12\0"
LC3:
	.ascii "x = %.4f\12\0"
	.align 4
LC4:
	.ascii "x1 = %.4f+%.4fi, x2 = %.4f-%.4fi\12\0"
	.text
	.globl	_print_solution
	.def	_print_solution;	.scl	2;	.type	32;	.endef
_print_solution:
LFB11:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	_c, %ecx
	movl	_b, %edx
	movl	_a, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	fldl	_ximag
	fldt	LC2
	fucompp
	fnstsw	%ax
	sahf
	ja	L9
	jmp	L11
L9:
	fldl	_x1real
	fldl	_x2real
	fucom	%st(1)
	fnstsw	%ax
	sahf
	jp	L12
	fucompp
	fnstsw	%ax
	sahf
	jne	L7
	fldl	_x1real
	fstpl	4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	jmp	L11
L12:
	fstp	%st(0)
	fstp	%st(0)
L7:
	fldl	_ximag
	fldl	_x2real
	fldl	_ximag
	fldl	_x1real
	fxch	%st(3)
	fstpl	28(%esp)
	fxch	%st(1)
	fstpl	20(%esp)
	fstpl	12(%esp)
	fstpl	4(%esp)
	movl	$LC4, (%esp)
	call	_printf
L11:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE11:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC6:
	.ascii "%d\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB12:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	leal	24(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC6, (%esp)
	call	_scanf
	movl	$0, 28(%esp)
	jmp	L14
L15:
	call	_get_parameters
	call	_abc
	call	_print_solution
	addl	$1, 28(%esp)
L14:
	movl	24(%esp), %eax
	cmpl	%eax, 28(%esp)
	jl	L15
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE12:
	.section .rdata,"dr"
	.align 16
LC2:
	.long	-971378890
	.long	-1946424714
	.long	16054
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
	.def	_abc;	.scl	2;	.type	32;	.endef
