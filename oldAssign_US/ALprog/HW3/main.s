// Cant seem to find the problem with this code gives a prompt for input
// but then does nothing
	
globl ints
	.data
	.type	ints, @object
	.size	ints, 10
ints:
	.byte	48
	.byte	49
	.byte	50
	.byte	51
	.byte	52
	.byte	53
	.byte	54
	.byte	55
	.byte	56
	.byte	57
.globl charsCap
	.align 16
	.type	charsCap, @object
	.size	charsCap, 26
charsCap:
	.byte	65
	.byte	66
	.byte	67
	.byte	68
	.byte	69
	.byte	70
	.byte	71
	.byte	72
	.byte	73
	.byte	74
	.byte	75
	.byte	76
	.byte	77
	.byte	78
	.byte	79
	.byte	80
	.byte	81
	.byte	82
	.byte	83
	.byte	84
	.byte	85
	.byte	86
	.byte	87
	.byte	88
	.byte	89
	.byte	90
.globl charsNorm
	.align 16
	.type	charsNorm, @object
	.size	charsNorm, 26
charsNorm:
	.byte	97
	.byte	98
	.byte	99
	.byte	100
	.byte	101
	.byte	102
	.byte	103
	.byte	104
	.byte	105
	.byte	106
	.byte	107
	.byte	108
	.byte	109
	.byte	110
	.byte	111
	.byte	112
	.byte	113
	.byte	114
	.byte	115
	.byte	116
	.byte	117
	.byte	118
	.byte	119
	.byte	120
	.byte	121
	.byte	122
.globl operators
	.type	operators, @object
	.size	operators, 4
operators:
	.byte	42
	.byte	43
	.byte	45
	.byte	47
.globl delimiters
	.type	delimiters, @object
	.size	delimiters, 5
delimiters:
	.byte	46
	.byte	40
	.byte	41
	.byte	44
	.byte	58
.globl blank
	.type	blank, @object
	.size	blank, 1
blank:
	.byte	32
.globl endofline
	.type	endofline, @object
	.size	endofline, 1
endofline:
	.byte	35
	.section	.rodata
.LC0:
	.string	"Please enter your string "
	.align 8
.LC1:
	.string	"( max size 80 charaters, to end enter # ): "
.LC2:
	.string	"%s"
.LC3:
	.string	"loop"
.LC4:
	.string	"6"
.LC5:
	.string	"%d"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$432, %rsp
.LCFI2:
	movl	%edi, -420(%rbp)
	movq	%rsi, -432(%rbp)
	movl	$0, -4(%rbp)
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	-96(%rbp), %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	movl	$0, -12(%rbp)
	jmp	.L2
.L4:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	-12(%rbp), %eax
	cltq
	movzbl	-96(%rbp,%rax), %eax
	cmpb	$35, %al
	jne	.L3
	movl	$.LC4, %edi
	call	puts
	movl	$1, %edi
	call	exit
.L3:
	movl	-12(%rbp), %eax
	cltq
	movzbl	-96(%rbp,%rax), %eax
	movsbl	%al,%edi
	call	getline
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -12(%rbp)
.L2:
	cmpl	$80, -12(%rbp)
	jg	.L4
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	movl	-4(%rbp), %eax
	cltq
	movl	-416(%rbp,%rax,4), %esi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	printf
	movl	$10, %edi
	call	putchar
	addl	$1, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	jg	.L6
	movl	$0, %eax
	leave
	ret
.LFE2:
	.size	main, .-main
	.section	.rodata
.LC6:
	.string	"ret1"
.LC7:
	.string	"ret2"
.LC8:
	.string	"Ret2"
	.text
.globl getline
	.type	getline, @function
getline:
.LFB3:
	pushq	%rbp
.LCFI3:
	movq	%rsp, %rbp
.LCFI4:
	subq	$32, %rsp
.LCFI5:
	movb	%dil, -20(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$10, -4(%rbp)
	jle	.L9
	movl	-4(%rbp), %eax
	cltq
	movzbl	ints(%rax), %eax
	cmpb	-20(%rbp), %al
	jne	.L10
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
.L10:
	movl	$1, -24(%rbp)
	jmp	.L11
.L9:
	movl	$0, -4(%rbp)
	cmpl	$26, -4(%rbp)
	jle	.L12
	movl	-4(%rbp), %eax
	cltq
	movzbl	charsCap(%rax), %eax
	cmpb	-20(%rbp), %al
	jne	.L13
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
.L13:
	movl	$2, -24(%rbp)
	jmp	.L11
.L12:
	movl	$0, -4(%rbp)
	cmpl	$26, -4(%rbp)
	jle	.L14
	movl	-4(%rbp), %eax
	cltq
	movzbl	charsNorm(%rax), %eax
	cmpb	-20(%rbp), %al
	jne	.L15
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
.L15:
	movl	$2, -24(%rbp)
	jmp	.L11
.L14:
	movl	$0, -4(%rbp)
	jmp	.L16
.L18:
	movl	-4(%rbp), %eax
	cltq
	movzbl	operators(%rax), %eax
	cmpb	-20(%rbp), %al
	jne	.L17
	movl	$3, -24(%rbp)
	jmp	.L11
.L17:
	addl	$1, -4(%rbp)
.L16:
	cmpl	$4, -4(%rbp)
	jg	.L18
	movl	$0, -4(%rbp)
	jmp	.L19
.L21:
	movl	-4(%rbp), %eax
	cltq
	movzbl	delimiters(%rax), %eax
	cmpb	-20(%rbp), %al
	jne	.L20
	movl	$4, -24(%rbp)
	jmp	.L11
.L20:
	addl	$1, -4(%rbp)
.L19:
	cmpl	$5, -4(%rbp)
	jg	.L21
	movzbl	blank(%rip), %eax
	cmpb	-20(%rbp), %al
	jne	.L22
	movl	$5, -24(%rbp)
	jmp	.L11
.L22:
	movl	$0, -24(%rbp)
.L11:
	movl	-24(%rbp), %eax
	leave
	ret
.LFE3:
	.size	getline, .-getline
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
	.long	.LCFI3-.LFB3
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE3:
	.ident	"GCC: (Debian 4.3.2-1.1) 4.3.2"
	.section	.note.GNU-stack,"",@progbits
