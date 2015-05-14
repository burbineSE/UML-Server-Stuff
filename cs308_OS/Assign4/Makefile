pc_threads: project_header.h my_th_donuts.o
	cc -o pc_threads my_th_donuts.o -lpthread
my_th_donuts.o: project_header.h my_th_donuts.c
	cc -c my_th_donuts.c 
clean:
	rm *.o pc_threads
