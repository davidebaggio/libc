SRC= ./src
INCLUDE= ./include
TEST=./test
BIN= ./build/bin
LIBC= $(BIN)/libc.a
EXE= $(BIN)/executable
CC=gcc
CFLAGS= -std=c11 -I$(INCLUDE) -Wall -Wextra

all: lib tests

lib:
	$(CC) $(CFLAGS) -c $(SRC)/lbendian.c -o ./build/lbendian.o
	$(CC) $(CFLAGS) -c $(SRC)/libcsocket.c -o ./build/libcsocket.o
	$(CC) $(CFLAGS) -c $(SRC)/libcerr.c -o ./build/libcerr.o
	$(CC) $(CFLAGS) -c $(SRC)/server.c -o ./build/server.o
	$(CC) $(CFLAGS) -c $(SRC)/client.c -o ./build/client.o
	ar ruv $(BIN)/libc.a ./build/lbendian.o ./build/libcsocket.o ./build/libcerr.o ./build/client.o ./build/server.o
	ranlib $(BIN)/libc.a

tests:
	$(CC) $(CFLAGS) $(TEST)/main.c $(LIBC) -o $(EXE)/main.exe
	$(CC) $(CFLAGS) $(TEST)/cwsocket.c $(LIBC) -lws2_32 -o $(EXE)/cwsocket.exe
	$(CC) $(CFLAGS) $(TEST)/chatclient.c $(LIBC) -lws2_32 -o $(EXE)/chatclient.exe
	$(CC) $(CFLAGS) $(TEST)/chatserver.c $(LIBC) -lws2_32 -o $(EXE)/chatserver.exe
	$(CC) $(CFLAGS) $(TEST)/clientparser.c $(LIBC) -lws2_32 -o $(EXE)/clientparser.exe

clear:
	rm ./build/*.o
	rm $(BIN)/libc.a
	rm $(EXE)/*.exe