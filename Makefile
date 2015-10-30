# The compiler
CC=g++

# Compiler flags
CFLAGS=-Wall
  #  -Wall turns on most, but not all, compiler warnings

creeps: clean main.o room.o connection.o
    $(CC) $(CFLAGS) -o main.o room.o connection.o

main.o:
$(CC) $(CFLAGS) -c main.cpp

room.o:
$(CC) $(CFLAGS) -c room.cpp

connection.o
$(CC) $(CFLAGS) -c connection.cpp

hello: clean
	$(CC) $(CFLAGS) -o hello main.cpp

clean:
	rm -f hello
