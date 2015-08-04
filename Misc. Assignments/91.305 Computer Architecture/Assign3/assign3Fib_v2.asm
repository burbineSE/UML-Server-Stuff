LOOP:	LODD PASSCT: 		;Loads PASSCT into the AC
	JZER DONE:		;If PASSCT is zero jumps to DONE
	SUBD C1:		;Subs 1 from PASSCT 
	STOD PASSCT:		;Stores new (PASSCT - 1) back into PASSCT
	LODD DADDR:		;Loads value from D0, this is th number we will be finding FIB for
	PSHI
	ADDD C1:		;Adds one to the array at DADDR
	STOD DADDR:		;Stores new number into array, incrementing the array by one
	CALL FIB:		;Calls the FIB function to get the Fib of the desired number
	INSP 1			;Increment SP by 1
	PUSH			;Pushes Fibonacci of desired number onto stack
	LODD FADDR:		;Loads answer storage array
	POPI
	ADDD C1: 		;Next two lines do the same as above, increments the array for the next value
	STOD FADDR:
	JUMP LOOP:		;Jumps back to the top of the loop
	HALT 			;Program should not reach here, ends the program if it does
FIB:    LODL 1			;Loads the value onto the AC one below the SP
	JZER IFZERO:		;If value is zero IFZERO is called
	SUBD C1:		
	JZER IFONE:		;If value is (n-1) = 1 then IFONE is called
	PUSH			;Pushes n-1 onto stack
	CALL FIB:		;Calles FIB
	PUSH			;Pushes Fib(n-1) onto stack
	LODL 1			
	SUBD C1:		;Value is now n-2
	PUSH			;Pushes n-2 onto stack
	CALL FIB:		;Calles FIB to find n-2
	ADDL 1			
	INSP 3
	RETN
	HALT
IFZERO: LODD C0: 		;Called if n == 0, stores 0 on the stack and returns
	RETN
IFONE:  LODD C1:		;Called if n == 1, stores 1 on the stack and returns
	RETN
DONE:   HALT			;Called when PASSCT == 0, ends the progam
	.LOC 100
D0:     3 			;Array of numbers to find the Fibonacci of
	9
	18
	23
	25
F0:     0			;Array where the Fibonacci numbers will be stored
	0
	0
	0
	0
DADDR:	D0: 			
FADDR:	F0:
C0:	0			;Constant 0
C1:	1			;Constant 1
PASSCT:	5			;NUmber of times the loop will be made
	
