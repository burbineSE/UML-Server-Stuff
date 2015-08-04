OBJS   = GradeBookTest.o
CC     = g++
DEBUG  = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

GradeBookTest : GradeBookTest.o
	$(CC) $(LFLAGS) -o GradeBookTest GradeBookTest.o

GradeBook : GradeBook.h GradeBook.cpp
	$(CC) $(CFLAGS) GradeBook.cpp

GradeBookTest.o : GradeBook.h GradeBookTest.cpp
	$(CC) $(CFLAGS) GradeBookTest.cpp

clean:
	rm *.o *~ GradeBookTest
