CC=g++

all: tsh

tsh: main.o tsh.o
	$(CC) main.o tsh.o -o tsh

main.o: main.cpp tsh.h
	$(CC) -c main.cpp

tsh.o: tsh.cpp tsh.h
	$(CC) -c tsh.cpp

clean:
	rm -f *~ *.o
	rm -f tsh