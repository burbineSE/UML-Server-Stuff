addval:	lodd addptr:		;loads new ptr which is potining at the top of A0
	pshi		;pushes first A0 val onto stack
	addd c1:	;inc ptr
	stod addptr:	;store new val
	lodd addptr:	;does this a second time to push on the second val
	pshi
	addd c1:
	stod addptr:
	pop		;pops seocnd val into the ac
	addl 0		;adds next val to ac
	jneg badadd:	;checks for OV
	stod sumdec:	;stores sum
	insp 1		;and insp by 1 to remove the top val fomr teh stack
encode:	lodd NLcode:		;if prog as not jumps it comes here, uased NL code for val 10
	push		;puahes it onto the stack
	lodd sumdec:	;loads sum
	push		;pushes it onto stack
divlp:	div			;calls div wich takes val at SP as the numer and SP+1 a divisor
	pop		;we pop quot ans stor into a temp val
	stod quot:
	lodd splitN:	;we then load up the lard array R0 to store the indvs digs
	popi		;pop the rmander onto the array
	addd c1:	;we tehnincrement th ptr and store the nre ptr val
	stod splitN:
	lodd quot:	;we then load quot val
	jzer summes:	;if quot is zero we are done
	stol 0		;else we load it ont the stack
	jump divlp:	;and jump
summes:	lodd finchk:	;we the load a finish sum check, starts as zero
	addd c1:	;add 1
	stod finchk:	;store it
	loco resmes:	;load the finish str
	jump nextw:	;jump to print func
badadd:	lodd badadc:	;loads bad add check, starts as 0
        addd c1:	;adds 1
	stod badadc:	; and stores new val
	loco errorm:	;loads error string
	jump nextw:	;jumps to nextw for printing
badade:	lodd c0:	;bad add end, loads -1 into the ac
	subd c1:
	halt		;prog end
encdfn:	insp 2		;after sum messge is printed, we then wipe the stack
fliplp:	lodd flipct:	;load the flip count starts as 5
	jzer stread:	;if zero we jump
	subd c1:	;else we sub and store new val
	stod flipct:
	lodd flpptr:	; we then load the ptr
	pshi		;and psuh the top val, ones place val, onto the stack
	addd c1:
	stod flpptr:
	jump fliplp:	;we then jump to the top of the flip loop
stread:	lodl 0			;loads top of stack, possibly highest num into ac
	jnze numstr:	;if its not zero then we jump
	pop		;else we pop ot
	lodd rect:	;load the count, starts at 5
	subd c1:	;subs 1 and stores it
	stod rect:
	jump stread:	;jumps to to pf loop
numstr:	lodd rect:		;load the count, this is how long the number is
	jzer done:	;if it zero we are done
	subd c1:	;else we sub and store
	stod rect:
	pop		;we pop the val into the ac
	addd ascii0:	;add 48 to make it a ascii val
	stod 4094	;store it into the transmitter
	call xbsywt:	; and call teh trans wait
	jump numstr:	; then we loop
done:	lodd cr:	;the done loop then throws out a CR and NL char
	stod 4094
	call xbsywt:
	lodd nl:
	stod 4094
	call xbsywt:
	lodd c0:	;loads a zero into the ac
	halt		;and the prog ends
	
