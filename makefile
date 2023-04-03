SRC= ./src
INCLUDE= ./include
TEST=./test
BIN= ./build/bin
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
	$(CC) $(CFLAGS) -c $(TEST)/main.c -o $(TEST)/main.o
	$(CC) $(CFLAGS) -o $(TEST)/main.exe $(TEST)/main.o $(BIN)/libc.a
	rm $(TEST)/main.o
	$(CC) $(CFLAGS) -c $(TEST)/cwsocket.c -o $(TEST)/cwsocket.o
	$(CC) $(CFLAGS) -o $(TEST)/cwsocket.exe $(TEST)/cwsocket.o $(BIN)/libc.a -lws2_32
	rm $(TEST)/cwsocket.o
	$(CC) $(CFLAGS) -c $(TEST)/chatclient.c -o $(TEST)/chatclient.o
	$(CC) $(CFLAGS) -o $(TEST)/chatclient.exe $(TEST)/chatclient.o $(BIN)/libc.a -lws2_32
	rm $(TEST)/chatclient.o
	$(CC) $(CFLAGS) -c $(TEST)/chatserver.c -o $(TEST)/chatserver.o
	$(CC) $(CFLAGS) -o $(TEST)/chatserver.exe $(TEST)/chatserver.o $(BIN)/libc.a -lws2_32
	rm $(TEST)/chatserver.o

clear:
	rm ./build/*.o
	rm $(BIN)/libc.a
	rm $(TEST)/*.exe