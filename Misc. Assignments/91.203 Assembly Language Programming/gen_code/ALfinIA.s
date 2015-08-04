	.file	"ALfinIA.c"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	movl	$0, %eax
	leave
	ret
.LFE2:
	.size	main, .-main
.globl fun1
	.type	fun1, @function
fun1:
.LFB3:
	pushq	%rbp
.LCFI2:
	movq	%rsp, %rbp
.LCFI3:
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jge	.L4
	cmpl	$0, -4(%rbp)
	jne	.L5
.L4:
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L6
.L5:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
.L6:
	movl	-12(%rbp), %eax
	leave
	ret
.LFE3:
	.size	fun1, .-fun1
.globl fun2
	.type	fun2, @function
fun2:
.LFB4:
	pushq	%rbp
.LCFI4:
	movq	%rsp, %rbp
.LCFI5:
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jge	.L9
	cmpl	$0, -8(%rbp)
	je	.L9
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L10
.L9:
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
.L10:
	movl	-12(%rbp), %eax
	leave
	ret
.LFE4:
	.size	fun2, .-fun2
.globl fun3
	.type	fun3, @function
fun3:
.LFB5:
	pushq	%rbp
.LCFI6:
	movq	%rsp, %rbp
.LCFI7:
	movl	%edi, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -4(%rbp)
	cmpl	$0, -20(%rbp)
	js	.L13
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
	jmp	.L14
.L13:
	movl	-4(%rbp), %eax
	movl	%eax, -24(%rbp)
.L14:
	movl	-24(%rbp), %eax
	leave
	ret
.LFE5:
	.size	fun3, .-fun3
.globl fun4
	.type	fun4, @function
fun4:
.LFB6:
	pushq	%rbp
.LCFI8:
	movq	%rsp, %rbp
.LCFI9:
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$3, %eax
	imull	-4(%rbp), %eax
	addl	-8(%rbp), %eax
	leave
	ret
.LFE6:
	.size	fun4, .-fun4
.globl fun5
	.type	fun5, @function
fun5:
.LFB7:
	pushq	%rbp
.LCFI10:
	movq	%rsp, %rbp
.LCFI11:
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	leal	(%rdx,%rax), %eax
	movl	%eax, -4(%rbp)
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	leave
	ret
.LFE7:
	.size	fun5, .-fun5
.globl fun6
	.type	fun6, @function
fun6:
.LFB8:
	pushq	%rbp
.LCFI12:
	movq	%rsp, %rbp
.LCFI13:
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	subl	%edx, %eax
	leave
	ret
.LFE8:
	.size	fun6, .-fun6
.globl fun7
	.type	fun7, @function
fun7:
.LFB9:
	pushq	%rbp
.LCFI14:
	movq	%rsp, %rbp
.LCFI15:
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %edx
	movl	%edx, %eax
	sall	$4, %eax
	addl	%edx, %eax
	leave
	ret
.LFE9:
	.size	fun7, .-fun7
.globl fun8
	.type	fun8, @function
fun8:
.LFB10:
	pushq	%rbp
.LCFI16:
	movq	%rsp, %rbp
.LCFI17:
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	leal	(%rax,%rax), %edx
	movl	%edx, %eax
	sall	$4, %eax
	leal	(%rdx,%rax), %eax
	leave
	ret
.LFE10:
	.size	fun8, .-fun8
.globl fun9
	.type	fun9, @function
fun9:
.LFB11:
	pushq	%rbp
.LCFI18:
	movq	%rsp, %rbp
.LCFI19:
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	leal	0(,%rax,4), %edx
	movl	%edx, %eax
	sall	$4, %eax
	leal	(%rdx,%rax), %eax
	leave
	ret
.LFE11:
	.size	fun9, .-fun9
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zR"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x1
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB2
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI2-.LFB3
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI3-.LCFI2
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.long	.LFB4
	.long	.LFE4-.LFB4
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI4-.LFB4
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI5-.LCFI4
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE5:
.LSFDE7:
	.long	.LEFDE7-.LASFDE7
.LASFDE7:
	.long	.LASFDE7-.Lframe1
	.long	.LFB5
	.long	.LFE5-.LFB5
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI6-.LFB5
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI7-.LCFI6
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE7:
.LSFDE9:
	.long	.LEFDE9-.LASFDE9
.LASFDE9:
	.long	.LASFDE9-.Lframe1
	.long	.LFB6
	.long	.LFE6-.LFB6
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI8-.LFB6
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI9-.LCFI8
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE9:
.LSFDE11:
	.long	.LEFDE11-.LASFDE11
.LASFDE11:
	.long	.LASFDE11-.Lframe1
	.long	.LFB7
	.long	.LFE7-.LFB7
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI10-.LFB7
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI11-.LCFI10
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE11:
.LSFDE13:
	.long	.LEFDE13-.LASFDE13
.LASFDE13:
	.long	.LASFDE13-.Lframe1
	.long	.LFB8
	.long	.LFE8-.LFB8
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI12-.LFB8
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI13-.LCFI12
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE13:
.LSFDE15:
	.long	.LEFDE15-.LASFDE15
.LASFDE15:
	.long	.LASFDE15-.Lframe1
	.long	.LFB9
	.long	.LFE9-.LFB9
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI14-.LFB9
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI15-.LCFI14
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE15:
.LSFDE17:
	.long	.LEFDE17-.LASFDE17
.LASFDE17:
	.long	.LASFDE17-.Lframe1
	.long	.LFB10
	.long	.LFE10-.LFB10
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI16-.LFB10
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI17-.LCFI16
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE17:
.LSFDE19:
	.long	.LEFDE19-.LASFDE19
.LASFDE19:
	.long	.LASFDE19-.Lframe1
	.long	.LFB11
	.long	.LFE11-.LFB11
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI18-.LFB11
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI19-.LCFI18
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE19:
	.ident	"GCC: (Debian 4.3.2-1.1) 4.3.2"
	.section	.note.GNU-stack,"",@progbits
