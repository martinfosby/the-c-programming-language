	.file	"main.c"
	.section	.rodata
.LC0:
	.string	"digits ="
.LC1:
	.string	" %d"
	.align 8
.LC2:
	.string	", white space = %d, other = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -56(%rbp)
	movl	-56(%rbp), %eax
	movl	%eax, -60(%rbp)
	movl	$0, -64(%rbp)
	jmp	.L2
.L3:
	movl	-64(%rbp), %eax
	cltq
	movl	$0, -48(%rbp,%rax,4)
	addl	$1, -64(%rbp)
.L2:
	cmpl	$9, -64(%rbp)
	jle	.L3
	jmp	.L4
.L8:
	cmpl	$47, -52(%rbp)
	jle	.L5
	cmpl	$57, -52(%rbp)
	jg	.L5
	movl	-52(%rbp), %eax
	subl	$48, %eax
	movslq	%eax, %rdx
	movl	-48(%rbp,%rdx,4), %edx
	addl	$1, %edx
	cltq
	movl	%edx, -48(%rbp,%rax,4)
	jmp	.L4
.L5:
	cmpl	$32, -52(%rbp)
	je	.L6
	cmpl	$10, -52(%rbp)
	je	.L6
	cmpl	$9, -52(%rbp)
	jne	.L7
.L6:
	addl	$1, -60(%rbp)
	jmp	.L4
.L7:
	addl	$1, -56(%rbp)
.L4:
	call	getchar
	movl	%eax, -52(%rbp)
	cmpl	$-1, -52(%rbp)
	jne	.L8
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -64(%rbp)
	jmp	.L9
.L10:
	movl	-64(%rbp), %eax
	cltq
	movl	-48(%rbp,%rax,4), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -64(%rbp)
.L9:
	cmpl	$9, -64(%rbp)
	jle	.L10
	movl	-56(%rbp), %edx
	movl	-60(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L12
	call	__stack_chk_fail
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC3:
	.string	"exercise 1-12/nWrite a program that prints its input one word per line."
	.text
	.globl	divide_word_per_line
	.type	divide_word_per_line, @function
divide_word_per_line:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC3, %edi
	call	puts
	jmp	.L14
.L16:
	cmpl	$32, -4(%rbp)
	jne	.L15
	movl	$10, %edi
	call	putchar
	jmp	.L14
.L15:
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	putchar
.L14:
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L16
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	divide_word_per_line, .-divide_word_per_line
	.section	.rodata
.LC4:
	.string	"%d %d %d\n"
	.text
	.globl	word_count
	.type	word_count, @function
word_count:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp	.L18
.L22:
	addl	$1, -12(%rbp)
	cmpl	$10, -4(%rbp)
	jne	.L19
	addl	$1, -20(%rbp)
.L19:
	cmpl	$32, -4(%rbp)
	je	.L20
	cmpl	$10, -4(%rbp)
	je	.L20
	cmpl	$9, -4(%rbp)
	jne	.L21
.L20:
	movl	$0, -8(%rbp)
	jmp	.L18
.L21:
	cmpl	$0, -8(%rbp)
	jne	.L18
	movl	$1, -8(%rbp)
	addl	$1, -16(%rbp)
.L18:
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L22
	movl	-12(%rbp), %ecx
	movl	-16(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	word_count, .-word_count
	.section	.rodata
	.align 8
.LC5:
	.string	"This program is exercise 1.10 from the book \"The C Programming Language\". It replaces tab, backspace and \\ with \\t, \\b and \\\\.\nPress control-h to enter a backspace character"
	.text
	.globl	replace_with_literal
	.type	replace_with_literal, @function
replace_with_literal:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$.LC5, %edi
	call	puts
	jmp	.L24
.L28:
	cmpl	$9, -4(%rbp)
	jne	.L25
	movl	$92, %edi
	call	putchar
	movl	$116, %edi
	call	putchar
	jmp	.L24
.L25:
	cmpl	$8, -4(%rbp)
	jne	.L26
	movl	$92, %edi
	call	putchar
	movl	$98, %edi
	call	putchar
	jmp	.L24
.L26:
	cmpl	$92, -4(%rbp)
	jne	.L27
	movl	$92, %edi
	call	putchar
	movl	$92, %edi
	call	putchar
	jmp	.L24
.L27:
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	putchar
.L24:
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jne	.L28
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	replace_with_literal, .-replace_with_literal
	.globl	replace_with_one_blank
	.type	replace_with_one_blank, @function
replace_with_one_blank:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	jmp	.L30
.L32:
	cmpl	$32, -4(%rbp)
	jne	.L31
	cmpl	$0, -8(%rbp)
	jne	.L31
	movl	$1, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	putchar
.L31:
	cmpl	$32, -4(%rbp)
	je	.L30
	movl	$0, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	putchar
.L30:
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L32
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	replace_with_one_blank, .-replace_with_one_blank
	.section	.rodata
.LC6:
	.string	"%d\n"
	.text
	.globl	count_whitespace
	.type	count_whitespace, @function
count_whitespace:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -8(%rbp)
	jmp	.L34
.L37:
	cmpl	$10, -4(%rbp)
	je	.L35
	cmpl	$9, -4(%rbp)
	je	.L35
	cmpl	$32, -4(%rbp)
	jne	.L36
.L35:
	addl	$1, -12(%rbp)
.L36:
	addl	$1, -8(%rbp)
.L34:
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L37
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	count_whitespace, .-count_whitespace
	.section	.rodata
.LC10:
	.string	"celsius"
.LC11:
	.string	"fahr"
.LC12:
	.string	"%s %15s\n"
.LC16:
	.string	"%3.0f %15.1f\n"
	.text
	.globl	print_table_with_heading
	.type	print_table_with_heading, @function
print_table_with_heading:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	pxor	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	movss	.LC8(%rip), %xmm0
	movss	%xmm0, -12(%rbp)
	movss	.LC9(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	movss	-16(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
	movl	$.LC10, %edx
	movl	$.LC11, %esi
	movl	$.LC12, %edi
	movl	$0, %eax
	call	printf
	jmp	.L39
.L40:
	movss	-20(%rbp), %xmm0
	movss	.LC13(%rip), %xmm1
	subss	%xmm1, %xmm0
	movss	.LC14(%rip), %xmm1
	mulss	%xmm1, %xmm0
	movss	.LC15(%rip), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, -4(%rbp)
	cvtss2sd	-4(%rbp), %xmm1
	cvtss2sd	-20(%rbp), %xmm0
	movl	$.LC16, %edi
	movl	$2, %eax
	call	printf
	movss	-20(%rbp), %xmm0
	addss	-8(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
.L39:
	movss	-12(%rbp), %xmm0
	ucomiss	-20(%rbp), %xmm0
	jnb	.L40
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	print_table_with_heading, .-print_table_with_heading
	.globl	print_celsius_to_fahr
	.type	print_celsius_to_fahr, @function
print_celsius_to_fahr:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	pxor	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	movss	.LC8(%rip), %xmm0
	movss	%xmm0, -12(%rbp)
	movss	.LC9(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	movss	-16(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
	movl	$.LC10, %edx
	movl	$.LC11, %esi
	movl	$.LC12, %edi
	movl	$0, %eax
	call	printf
	jmp	.L42
.L43:
	cvtss2sd	-20(%rbp), %xmm0
	movsd	.LC17(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	.LC18(%rip), %xmm1
	addsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -4(%rbp)
	cvtss2sd	-20(%rbp), %xmm1
	cvtss2sd	-4(%rbp), %xmm0
	movl	$.LC16, %edi
	movl	$2, %eax
	call	printf
	movss	-20(%rbp), %xmm0
	addss	-8(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
.L42:
	movss	-12(%rbp), %xmm0
	ucomiss	-20(%rbp), %xmm0
	jnb	.L43
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	print_celsius_to_fahr, .-print_celsius_to_fahr
	.globl	print_celsius_to_fahr_reverse
	.type	print_celsius_to_fahr_reverse, @function
print_celsius_to_fahr_reverse:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	pxor	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	movss	.LC8(%rip), %xmm0
	movss	%xmm0, -12(%rbp)
	movss	.LC9(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	movl	$.LC10, %edx
	movl	$.LC11, %esi
	movl	$.LC12, %edi
	movl	$0, %eax
	call	printf
	movss	-12(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
	jmp	.L45
.L46:
	cvtss2sd	-20(%rbp), %xmm0
	movsd	.LC17(%rip), %xmm1
	mulsd	%xmm1, %xmm0
	movsd	.LC18(%rip), %xmm1
	addsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, -4(%rbp)
	cvtss2sd	-20(%rbp), %xmm1
	cvtss2sd	-4(%rbp), %xmm0
	movl	$.LC16, %edi
	movl	$2, %eax
	call	printf
	movss	-20(%rbp), %xmm0
	subss	-8(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
.L45:
	movss	-20(%rbp), %xmm0
	ucomiss	-16(%rbp), %xmm0
	jnb	.L46
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	print_celsius_to_fahr_reverse, .-print_celsius_to_fahr_reverse
	.globl	print_eof_input
	.type	print_eof_input, @function
print_eof_input:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	call	getchar
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	setne	%al
	movb	%al, -5(%rbp)
	movsbl	-5(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	print_eof_input, .-print_eof_input
	.globl	print_eof
	.type	print_eof, @function
print_eof:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$-1, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	print_eof, .-print_eof
	.section	.rodata
	.align 4
.LC8:
	.long	1133903872
	.align 4
.LC9:
	.long	1101004800
	.align 4
.LC13:
	.long	1107296256
	.align 4
.LC14:
	.long	1084227584
	.align 4
.LC15:
	.long	1091567616
	.align 8
.LC17:
	.long	3435973837
	.long	1073532108
	.align 8
.LC18:
	.long	0
	.long	1077936128
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.5) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
