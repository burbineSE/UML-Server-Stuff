xbsywt:	lodd 4095		;loads the val atored in the RCVR stat reg
	subd mask:	;subs mask val 10
	jneg xbsywt:	;if neg we loop
	retn		;else we retur
