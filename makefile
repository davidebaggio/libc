SRC= ./src
INCLUDE= ./include
TEST=./test
CC=gcc
CFLAGS= -std=c11 -I$(INCLUDE)

#-Wall -Wextra -Wimplicit-function-declaration

lib:
	$(CC) $(CFLAGS) -c $(SRC)/lbendian.c -o ./build/lbendian.o
	$(CC) $(CFLAGS) -c $(SRC)/clientweb.c -o ./build/clientweb.o
	ar ruv ./build/libc.a ./build/lbendian.o ./build/clientweb.o
	ranlib ./build/libc.a

tests: lib
	$(CC) $(CFLAGS) -c $(TEST)/main.c -o $(TEST)/main.o
	$(CC) $(CFLAGS) -o $(TEST)/main.exe $(TEST)/main.o ./build/libc.a
	rm $(TEST)/main.o
	$(CC) $(CFLAGS) -c $(TEST)/cwsocket.c -o $(TEST)/cwsocket.o
	$(CC) $(CFLAGS) -o $(TEST)/cwsocket.exe $(TEST)/cwsocket.o ./build/libc.a -lws2_32
	rm $(TEST)/cwsocket.o

clear:
	rm ./build/*
	rm $(TEST)/*.exe