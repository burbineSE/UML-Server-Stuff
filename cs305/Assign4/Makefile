masm: mic1symasm.o lex.yy.o
	gcc -o masm mic1symasm.o lex.yy.o -ll
mic1symasm.o:  mic1symasm.c
	gcc -c -g mic1symasm.c
lex.yy.o:  lex.yy.c
	gcc -c -g lex.yy.c
lex.yy.c: mic1symasm.ll
	flex mic1symasm.ll
clean:
	rm lex.yy.o lex.yy.c mic1symasm.o masm
