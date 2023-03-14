SRC= ./src
INCLUDE= ./include
TEST=./test
CC=gcc
CFLAGS= -std=c11 -I$(INCLUDE)

#-Wall -Wextra -Wimplicit-function-declaration

lib:
	$(CC) $(CFLAGS) -c $(SRC)/*.c -o ./build/libc.o

test:
	$(CC) $(CFLAGS) -c $(TEST)/main.c -o $(TEST)/main.o
	$(CC) $(CFLAGS) -o $(TEST)/main.exe $(TEST)/main.o ./build/libc.o
	rm $(TEST)/main.o