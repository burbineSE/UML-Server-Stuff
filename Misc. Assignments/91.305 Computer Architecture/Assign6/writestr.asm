nextw:  pshi			;indirect push into stack
	addd c1:	;incremtns string
	stod pstr1:	;and stores incemented string into a temp string
	pop		;pops pushed val into ac, this is the first 16 bit val (first two letters)
	jzer crnl:	;if the number is zero, we are dont and we jump to the CR NL func
	stod 4094	;loads val into 4094
	push
	subd c255:	;subs to check if second half of num is zero, if so we are done
	jneg crnl:
	call sb:	;calls sb which swaps the rwo 8 bit numbers in the current 16 bit num
	insp 1		;dec the stack so our new val is on top
	push
	call xbsywt:	;we then write the first val out
	pop		;pop is off
	stod 4094	;store it the next val
	call xbsywt:	; and write it
	lodd pstr1:	;we the load the temp string
	jump nextw:	; and loop
crnl:   lodd cr:		; this function loads the carriage retr and new line for the output
	stod 4094	;we store the CR val into 4094 to be written
	call xbsywt:	;and call it to be written
	lodd nl:	;load new line val
	stod 4094	;stroe and write as before
	call xbsywt:
	lodd finchk:	;this is to check if we are looping nextw and crnl for the sum message print
	jnze encdfn:	;if finchk is not = 0 we jump
	lodd badadc:	;check for error message
	jnze badade:	;if badadc is not = 0 we jump
	lodd on:	;if neither pass, we then load on (val 8) for 4093
	stod 4093	;this truns on the reciver to get user input
	jump fstdig:
sb:     loco 8		;load val of 8, for the 8 bits
loop1:	jzer finish:		;jumps to finish whe = 0
	subd c1:	;subs 1
	stod lpcnt:	;stores it into a counter for checking later
	lodl 1		;loads in the current 16 bit number
	jneg add1:	;if its neg (first bit is = 1) we jump to add1
	addl 1		;else we add 1 to the number
	stol 1		;store the nuew number
	lodd lpcnt:	;load the count
	jump loop1:	;and jump to the top of the loop
add1:   addl 1		;in the case of a 1
	addd c1:	;we add direct instead of local
	stol 1		;store new val
	lodd lpcnt:	;load the count
	jump loop1:	;and jump to top of the loop
finish:	lodl 1			;when the count is zero we load the new val
	retn		;and return
	
