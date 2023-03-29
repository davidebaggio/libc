#ifndef CLIENTWEB_H
#define CLIENTWEB_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <pthread.h>
#include "libcerr.h"

#define SA struct sockaddr
#define MAX 80
#define PORT 8080

typedef struct
{
	int socknum;
	char buff[MAX];
} message;

void startup_socket();
void cleanup_socket();

#endif