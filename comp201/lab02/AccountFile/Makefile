OBJS = AccountTest.o Account.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

AccountTest : $(OBJS)
	$(CC) $(LFLAGS) -o AccountTest

AccountTest.o : Account.h Account.cpp AccountTest.cpp
	$(CC) $(CFLAGS) AccountTest.cpp

Account.o : Account.h Account.cpp
	$(CC) $(CFLAGS) Account.cpp

clean:
	rm *.o *~ AccountTest
