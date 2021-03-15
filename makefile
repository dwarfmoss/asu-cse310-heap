EXEC = run
CC = g++
CFLAGS = -c -Wall

$(EXEC)	: main.o util.o heap.o element.o
	$(CC) -o $(EXEC) main.o util.o heap.o element.o

main.o	: main.cpp
	$(CC) $(CFLAGS) main.cpp

util.o	: util.h util.cpp
	$(CC) $(CFLAGS) util.cpp

heap.o	: heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

element.o: element.h element.cpp
	$(CC) $(CFLAGS) element.cpp

clean	:
	rm *.o