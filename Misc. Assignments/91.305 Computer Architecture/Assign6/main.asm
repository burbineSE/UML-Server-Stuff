start:  lodd on:		;loads val 8 into the ac
	stod 4095	;srores it to 4095 to turn on the transmitter
	call xbsywt:	;call tansmitter wait function
	loco str1:	;loads starting sting into the ac
	jump nextw:
	.LOC 300
A0:     0
	0
R0:     0
	0
	0
	0
	0
numptr: A0:
splitN:	R0:
addptr:	A0:
flpptr:	R0:
NLcode:	10
nxtnum:	0
ascii0:	48
lpcnt:  0
mask:   10
on:     8
nl:	10
cr:     13
cnt:	30
c1:     1
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
