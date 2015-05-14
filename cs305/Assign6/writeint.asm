fstdig:	call rbsywt:		;calls for user input, we grab input char by char
	lodd 4092	;load first dig into ac
	subd ascii0:	; we then sub 48 to dec val
	push		; and push onto stack
nxtdig: call rbsywt:		;we then do the same as above, but we dont sub right away and store it into a temp
	lodd 4092
	stod nxtnum:
	subd NLcode:	;sub val 10 to see if NL was entered
	jzer endnum:	; if so we are done
	mult 10		;if not we mult the val on the stack by 10
	lodd nxtnum:	;load in the ascii for the nect dig
	subd ascii0:	;sub 48
	addl 0		;add the mult 10 val to the new val
	stol 0		;and store sum onto stack
	jump nxtdig:	;the we jump, unti we hit a NL char
endnum:	lodd numptr:		;we then load a ptr to the array A0
	popi		;we the  pop our first val into A0
	addd c1:	;incemtn the pointer by one
	stod numptr:	;and store the new val
	lodd lpcnte:	;we then laod our lopp count, initaly set to 1
	jzer addval:	;if = zero we are done with the input phase
	subd c1:	;else we sub one fomr the counter
	stod lpcnte:	;store it
	lodd 4092	;we then load the receiver
	jump start:	;and jump to get the second number
	
