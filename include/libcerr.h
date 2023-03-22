#ifndef LIBC_ERR
#define LIBC_ERR

#include <stdio.h>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

#define DEFAULT "\033[0m"

enum Err_type
{
	WSASTARTUPERR,
	WSACLEANUPERR,
	WINSOCKERR
};

void printe(enum Err_type, int);

#endif