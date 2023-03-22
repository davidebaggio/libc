#ifndef CLIENTWEB_H
#define CLIENTWEB_H

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include "libcerr.h"

void startup_socket();
void cleanup_socket();

#endif