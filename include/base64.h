#ifndef BASE64_H
#define BASE64_H

#include "libcsocket.h"

char base64_encode_char(char);
char *base64_encode(unsigned char *, size_t);

#endif