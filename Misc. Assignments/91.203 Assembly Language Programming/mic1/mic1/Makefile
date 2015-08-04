mic1 : driver98.o alu.o control93.o clock.o cpu.o datapath93.o memory98.o shifter.o 
	cc -o mic1 driver98.o alu.o control93.o clock.o cpu.o datapath93.o memory98.o shifter.o
driver98.o: driver98.c globals.h
	cc -c -g driver98.c 
alu.o: alu.c globals.h
	cc -c -g alu.c
control93.o: control93.c globals.h
	cc -c -g control93.c
clock.o: clock.c 
	cc -c -g clock.c
cpu.o: cpu.c globals.h
	cc -c -g cpu.c
datapath93.o: datapath93.c  globals.h
	cc -c -g datapath93.c
memory98.o: memory98.c globals.h
	cc -c -g  memory98.c 
shifter.o: shifter.c globals.h
	cc -c -g shifter.c
clean:
	rm mic1 *.o
