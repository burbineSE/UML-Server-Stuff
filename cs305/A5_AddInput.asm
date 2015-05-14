start:	lodd on:		;loads val 8 into the ac
	stod 4095		;srores it to 4095 to turn on the transmitter
	call xbsywt:		;call tansmitter wait function 
	loco str1: 		;loads starting sting into the ac
nextw:	pshi			;indirect push into stack
	addd c1:		;incremtns string
	stod pstr1:		;and stores incemented string into a temp string
	pop			;pops pushed val into ac, this is the first 16 bit val (first two letters)
	jzer crnl:		;if the number is zero, we are dont and we jump to the CR NL func
	stod 4094		;loads val into 4094
	push
	subd c255:		;subs to check if second half of num is zero, if so we are done
	jneg crnl:
	call sb:		;calls sb which swaps the rwo 8 bit numbers in the current 16 bit num
	insp 1			;dec the stack so our new val is on top
	push			
	call xbsywt:		;we then write the first val out
	pop			;pop is off
	stod 4094		;store it the next val 
	call xbsywt:		; and write it
	lodd pstr1:		;we the load the temp string 
	jump nextw:		; and loop
crnl:	lodd cr:		; this function loads the carriage retr and new line for the output
	stod 4094		;we store the CR val into 4094 to be written
	call xbsywt:		;and call it to be written
	lodd nl:		;load new line val
	stod 4094		;stroe and write as before
	call xbsywt:
	lodd finchk:		;this is to check if we are looping nextw and crnl for the sum message print
	jnze encdfn:		;if finchk is not = 0 we jump
	lodd badadc:		;check for error message 
        jnze badade:		;if badadc is not = 0 we jump
	lodd on:		;if neither pass, we then load on (val 8) for 4093
	stod 4093		;this truns on the reciver to get user input  
fstdig:	call rbsywt:		;calls for user input, we grab input char by char
	lodd 4092		;load first dig into ac
	subd ascii0:		; we then sub 48 to dec val
	push			; and push onto stack
nxtdig:	call rbsywt:		;we then do the same as above, but we dont sub right away and store it into a temp
	lodd 4092
	stod nxtnum:
	subd NLcode:		;sub val 10 to see if NL was entered
	jzer endnum:		; if so we are done
	mult 10			;if not we mult the val on the stack by 10
	lodd nxtnum:		;load in the ascii for the nect dig
	subd ascii0:		;sub 48
	addl 0			;add the mult 10 val to the new val
	stol 0			;and store sum onto stack
	jump nxtdig:		;the we jump, unti we hit a NL char
endnum:	lodd numptr:		;we then load a ptr to the array A0
	popi			;we the  pop our first val into A0
	addd c1:		;incemtn the pointer by one
	stod numptr: 		;and store the new val
	lodd lpcnte:		;we then laod our lopp count, initaly set to 1
	jzer addval: 		;if = zero we are done with the input phase
	subd c1:		;else we sub one fomr the counter
	stod lpcnte:		;store it 
	lodd 4092		;we then load the receiver
	jump start:		;and jump to get the second number
addval:	lodd addptr:		;loads new ptr which is potining at the top of A0
	pshi			;pushes first A0 val onto stack
	addd c1:		;inc ptr
	stod addptr:		;store new val
	lodd addptr:		;does this a second time to push on the second val
	pshi
	addd c1:
	stod addptr:
	pop			;pops seocnd val into the ac
	addl 0			;adds next val to ac
	jneg badadd:		;checks for OV
	stod sumdec:		;stores sum
	insp 1			;and insp by 1 to remove the top val fomr teh stack 
encode:	lodd NLcode:		;if prog as not jumps it comes here, uased NL code for val 10
	push			;puahes it onto the stack
	lodd sumdec:		;loads sum
	push			;pushes it onto stack
divlp:	div			;calls div wich takes val at SP as the numer and SP+1 a divisor
	pop			;we pop quot ans stor into a temp val
	stod quot:
	lodd splitN:		;we then load up the lard array R0 to store the indvs digs
	popi			;pop the rmander onto the array
	addd c1:		;we tehnincrement th ptr and store the nre ptr val
	stod splitN:
	lodd quot:		;we then load quot val
	jzer summes: 		;if quot is zero we are done
	stol 0			;else we load it ont the stack
	jump divlp:		;and jump 
encdfn: insp 2			;after sum messge is printed, we then wipe the stack
fliplp: lodd flipct:		;load the flip count starts as 5
	jzer stread: 		;if zero we jump
	subd c1:		;else we sub and store new val
	stod flipct:
	lodd flpptr:		; we then load the ptr 
	pshi			;and psuh the top val, ones place val, onto the stack
	addd c1:
	stod flpptr:
	jump fliplp:		;we then jump to the top of the flip loop
stread: lodl 0			;loads top of stack, possibly highest num into ac
	jnze numstr:		;if its not zero then we jump
	pop			;else we pop ot
	lodd rect:		;load the count, starts at 5
	subd c1:		;subs 1 and stores it
	stod rect:		
	jump stread:		;jumps to to pf loop
numstr:	lodd rect:		;load the count, this is how long the number is
	jzer done:		;if it zero we are done
	subd c1:		;else we sub and store
	stod rect:
	pop			;we pop the val into the ac 
	addd ascii0:		;add 48 to make it a ascii val
	stod 4094		;store it into the transmitter
	call xbsywt:		; and call teh trans wait
	jump numstr:		; then we loop
done:	lodd cr:		;the done loop then throws out a CR and NL char
	stod 4094
	call xbsywt:
	lodd nl:
	stod 4094
	call xbsywt:
	lodd c0:		;loads a zero into the ac 
	halt			;and the prog ends
summes: lodd finchk:		;we the load a finish sum check, starts as zero
	addd c1:		;add 1
	stod finchk:		;store it
	loco resmes:		;load the finish str
	jump nextw:		;jump to print func
badadd:	lodd badadc:		;loads bad add check, starts as 0
	addd c1:		;adds 1
	stod badadc:		; and stores new val
	loco errorm:		;loads error string
	jump nextw:		;jumps to nextw for printing
badade:	lodd c0:		;bad add end, loads -1 into the ac
	subd c1:
	halt			;prog ends
xbsywt:	lodd 4095		;loads the val atored in the RCVR stat reg
	subd mask:		;subs mask val 10
	jneg xbsywt:		;if neg we loop
	retn			;else we return
rbsywt:	lodd 4093		;sam idea as above, but instead works for reciver
	subd mask:
	jneg rbsywt:
	retn
sb:	loco 8			;load val of 8, for the 8 bits
loop1:	jzer finish:		;jumps to finish whe = 0
	subd c1:		;subs 1
	stod lpcnt:		;stores it into a counter for checking later
	lodl 1			;loads in the current 16 bit number
	jneg add1:		;if its neg (first bit is = 1) we jump to add1
	addl 1			;else we add 1 to the number
	stol 1			;store the nuew number
	lodd lpcnt:		;load the count
	jump loop1:		;and jump to the top of the loop
add1:	addl 1			;in the case of a 1
	addd c1:		;we add direct instead of local
	stol 1			;store new val
	lodd lpcnt:		;load the count 
	jump loop1:		;and jump to top of the loop
finish:	lodl 1			;when the count is zero we load the new val 
	retn			;and return
	.LOC 300
A0:	0
	0
R0:	0
	0
	0
	0
	0
numptr:	A0:
splitN:	R0:
addptr:	A0:
flpptr:	R0:
NLcode:	10
nxtnum:	0
ascii0:	48
lpcnt:	0
mask:	10
on:	8
nl:	10
cr:	13
cnt:	30
c1:	1
c0:	0
c255:	255
pstr1:	0
lpcnte:	1
sumdec:	0
quot:	0
flipct:	5
rect:	5
finchk:	0
badadc:	0
str1:	"PLASE ENTER AN INT BETWEEN 1 AND 32767"
resmes:	"THE SUM OF THESE NUMBERS IS:"
errorm:	"OVERFLOW, NO SUM POSSIBLE"
