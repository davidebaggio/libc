#ifndef SERVER_H
#define SERVER_H

#include "libcerr.h"
#include "libcsocket.h"
#include "lbendian.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void host_chat(int);
void *recieving(void *);
char *filebuf(const char *);

#endif