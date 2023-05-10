#ifndef CLIENT_H
#define CLIENT_H

#include "libcerr.h"
#include "libcsocket.h"
#include "lbendian.h"

void join_chat(int);
void *recieving(void *);

#endif