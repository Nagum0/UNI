CC = gcc
CFLAGS = -Wall -Iheaders

nyuszi: nyuszi.o main.o
	$(CC) $(CFLAGS) nyuszi.o main.o -o nyuszi

nyuszi.o: src/nyuszi.c
	$(CC) $(CFLAGS) -c src/nyuszi.c -o nyuszi.o

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o main.o

clean:
	rm *.o nyuszi
