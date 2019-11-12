CC = clang
CFLAGS = -g -Wall

make: main.c array.c
	$(CC) $(CFLAGS) -o GoL main.c array.c

clean:
	rm -rf GoL
