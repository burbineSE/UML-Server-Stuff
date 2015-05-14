proddonuts consdonuts: donuts.h proddonuts.o consdonuts.o utilities.o
	cc -o proddonuts proddonuts.o utilities.o
	cc -o consdonuts consdonuts.o utilities.o
consdonuts.o: donuts.h consdonuts.c
	cc -c consdonuts.c
proddonuts.o: donuts.h proddonuts.c
	cc -c proddonuts.c
utilities.o:  utilities.c
	cc -c utilities.c
clean:
	rm *.o proddonuts consdonuts
