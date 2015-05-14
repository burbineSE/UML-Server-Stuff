;;  test for the new MULT assembly instruction
start:	LODD d1:
	PUSH
	MULT 2
	LODL 0
	HALT	     		; AC has status, product on stack
d1:	2542
d2:     -362
d3:     520
d4:	-2048
d5:     715
d6:	-1
