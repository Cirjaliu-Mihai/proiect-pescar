CC = gcc
CFLAGS = -I./include

all: main

main: main.o homar.o
	$(CC) -o main main.o homar.o

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

homar.o: src/homar.c
	$(CC) $(CFLAGS) -c src/homar.c

clean:
	rm -f *.o main
