SRC= ./src
INCLUDE= ./include
TEST=./test
BIN= ./build/bin
LIBC= $(BIN)/libc.a
EXE= $(BIN)/executable
CC=gcc
CFLAGS= -std=c11 -I$(INCLUDE) -Wall -Wextra
LFLAGS=

ifeq ($(OS), Windows_NT)
    LFLAGS+= -lws2_32
endif


all: lib tests

lib:
	$(CC) $(CFLAGS) -c $(SRC)/lbendian.c -o ./build/lbendian.o
	$(CC) $(CFLAGS) -c $(SRC)/libcsocket.c -o ./build/libcsocket.o
	$(CC) $(CFLAGS) -c $(SRC)/libcerr.c -o ./build/libcerr.o
	$(CC) $(CFLAGS) -c $(SRC)/server.c -o ./build/server.o
	$(CC) $(CFLAGS) -c $(SRC)/client.c -o ./build/client.o
	$(CC) $(CFLAGS) -c $(SRC)/base64.c -o ./build/base64.o
	ar ruv $(BIN)/libc.a ./build/lbendian.o ./build/libcsocket.o ./build/libcerr.o ./build/client.o ./build/server.o ./build/base64.o
	ranlib $(BIN)/libc.a

tests:
	$(CC) $(CFLAGS) $(TEST)/main.c $(LIBC) -o $(EXE)/main
	$(CC) $(CFLAGS) $(TEST)/cwsocket.c $(LIBC) $(LFLAGS) -o $(EXE)/cwsocket
	$(CC) $(CFLAGS) $(TEST)/chatclient.c $(LIBC) $(LFLAGS) -o $(EXE)/chatclient
	$(CC) $(CFLAGS) $(TEST)/chatserver.c $(LIBC) $(LFLAGS) -o $(EXE)/chatserver
	$(CC) $(CFLAGS) $(TEST)/clientparser.c $(LIBC) $(LFLAGS) -o $(EXE)/clientparser
	$(CC) $(CFLAGS) $(TEST)/encode64.c $(LIBC) $(LFLAGS) -o $(EXE)/encode64

clear:
	rm ./build/*.o
	rm $(BIN)/libc.a
	rm $(EXE)/*