SRC= ./src
INCLUDE= ./include
TEST=./example
CC=gcc
CFLAGS= -std=c11 -I$(INCLUDE) -Wall -Wextra

dir:
	mkdir ./build

lib:
	$(CC) $(CFLAGS) -c $(SRC)/*.c -o ./build/libc.o

clear:
	rm -r ./build

test:
	$(CC) $(CFLAGS) -c $(TEST)/main.c -o $(TEST)/main.o
	$(CC) $(CFLAGS) -o $(TEST)/main.exe $(TEST)/main.o ./build/libc.o
	rm $(TEST)/main.o