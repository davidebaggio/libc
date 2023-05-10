#ifndef CLIENTWEB_H
#define CLIENTWEB_H

#define WIN32_LEAN_AND_MEAN

#ifdef _WIN32
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#endif

#ifdef __unix__
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#endif

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "libcerr.h"

#define SA struct sockaddr
#define MAX 80
#define PORT 8080

struct headers
{
	char *name;
	char *value;
};

typedef struct
{
	int socknum;
	char buff[MAX];
} message;

void startup_socket();
void cleanup_socket();

#endif