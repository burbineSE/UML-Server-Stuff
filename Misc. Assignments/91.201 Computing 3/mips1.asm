	.data
msg1:		.asciiz	"Invalid input\n Usage: 1 for [-c decimalnum] | 2 for [ -i decimalnum] | 3 for [-b binarynum] | 4 for [-a decimalnum decimalnum]\n"
msg3:		.asciiz "Press 1 for [-c decimalnum]. Press 2 for [-i decimalnum]. Press 3 for [-b binarynum]. Press 4 for [-a decimalnum decialnum].\n"
msg4:		.asciiz "Enter the number you want to be converted.\n"
msg5:		.asciiz "Enter number(char) that you would like to be converted to a 8 bit binary.\n"
msg6:		.asciiz "Enter number(int) that you would like to be converted to 32 bit binary.\n"
msg7:		.asciiz "Enter binary(32-bit) that you owuld like to convert to decimal.\n"
msg8:	 	.asciiz	"Enter the first number you want check to see if ther addition will cuse overflow.\n"
msg9:	 	.asciiz	"Enter the second number you want check to see if ther addition will cuse overflow.\n"
msg10:		.asciiz "Number is too large.\n"
msg11:		.asciiz "Numbers are safe to add, total is: "
bitnum:		.word 0:32
BtoD:		.word 0:128

	.text
	.globl main
main:
	li	$t1, 0 #counter
	la	$t7, bitnum

	la	$a0, msg3 #calls for user input to pick what they wnat to do
	li	$v0, 4
	syscall

	li	$v0, 5 #user puts in aproperate number
	syscall

	ble 	$a0, $zero, ELSEmain #if input is less that zero or
	bge     $a0, 5, ELSEmain    #greater gretaer than 5, calls Else error msg

	beq 	$a0, 1, printBinaryChar
	beq 	$a0, 2, printBinaryInt
	beq	$a0, 3, intFromBinary
	beq 	$a0, 4, safeAddition

	jr	$ra
printBinaryChar:
	la	$a1, msg5
	li	$v0, 4
	syscall

	li 	$v0, 5
	syscall

	blt 	$a1, 0, negcheck #calls if number is negative
	j	loopPBC #calls if its not neg
loopPBC:
	div	$a1, 2
	mfhi	$t0 #stores result to HI, acts as mod
	div	$a1, 2
	mflo	$a1 #stores result to LO, acts as divide

	add 	$t2, $t7, $t1
	lw	$t0, ($t2)
	addi	$t1, $t1, 4

	move 	$t1, $t0
	li	$v0, 1
	syscall

	bgtz	$a1, loopPBC
	jr	$ra
negcheck:
	mult	$a1, -1
	mflo	$a1
	j	loopPBCneg
loopPBCneg:
	div	$a1, 2
	mfhi	$t0 #stores result to HI, acts as mod
	div	$a1, 2
	mflo	$a1 #stores result to LO, acts as divide

	beqz 	$t0, IFzero
	beq	$t0, 1, IFone

	add 	$t2, $t7, $t1
	lw	$t0, ($t2)
	addi	$t1, $t1, 4

	move 	$a1, $t0
	li	$v0, 1
	syscall

	bgtz	$a1, loopPBC
printBinaryInt:
	la	$a1, msg6 #calls for user input to pick what they want to do
	li	$v0, 4
	syscall

	li 	$v0, 5
	syscall

	j printBinaryChar
intFromBinary:
	la	$a2, msg7
	li	$v0, 4
	syscall

	li	$v0, 5
	syscall

	li	$t4, 0
	la 	$t5, BtoD

	j BtoDloop
BtoDloop:
	div 	$a2, 10
	mfhi	$t3
	div	$a2, $a2, 10

	sw 	$t3, $t4($t5)
	add	$t4, $t4, 4

	beq	$t4, 128, ArrayConv
	j BtoDloop
ArrayConv:
	lw	$t9, 128($t5)
	li	$t4, 128
	li	$s0, 0
	beqz 	$t9, regaddition
	beq	$t9, 1, negaddition
regaddition:
	sub	$t4, $t4, 4
	lw	$t9, $t4($t5)

	li 	$t8, 2147483647
	beqz 	$t9, bitweightdiv
	beq	$t9, 1, addition

	beq 	$t4, 1, printSum
	j regaddition
negaddition:
	add	$s0, $s0, -4294967294

	li 	$t8, 2147483647
	beqz 	$t9, bitweightdiv
	beq	$t9, 1, addition

	beq 	$t4, 1, printSum
	j negaddition
bitweightdiv:
	div 	$t8, $t8, 2
addition:
	add 	$s0, $s0, $t8
printSum:
	move 	$a2, $s0
	li	$v0, 1
	jr	$ra
safeAddition:
	la	$a2, msg8
	li	$v0, 4
	syscall

	li	$v0, 5
	syscall

	la 	$a3, msg9
	li 	$v0, 4
	syscall

	li	$v0, 5
	syscall

	add	$t9, $a2, $a3
	beq	$t9, 2147483647, overflow
	blt	$t9, 2147483647, safe

	jr 	$ra
overflow:
	la	$a2, msg10
	li	$v0, 4
	syscall

	j	safeAddition
safe:
	la	$a2, msg11
	li	$v0, 4
	syscall

	move 	$a0, $t9
	li	$v0, 1
IFone:
	mult 	$t0, 0
	mflo 	$t0
IFzero:
	add 	$t0, $t0, 1
ELSEmain:
	la	$a0, msg1
	li	$v0, 4
	syscall
	jr	$ra
