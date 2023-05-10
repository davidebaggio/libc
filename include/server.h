#ifndef SERVER_H
#define SERVER_H

#include "libcerr.h"
#include "libcsocket.h"
#include "lbendian.h"

void host_chat(int);
void *recieving(void *);
char *filebuf(const char *);

#endif