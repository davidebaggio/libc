#include "libcerr.h"

void printe(enum Err_type type, int e)
{
	switch (type)
	{
	case WSASTARTUPERR:
		printf("%s", RED);
		printf("WSAStartup failed with error: %d\n", e);
		printf("%s", DEFAULT);
		break;
	case WSACLEANUPERR:
		printf("%s", RED);
		printf("WSACleanup failed with error: %d\n", e);
		printf("%s", DEFAULT);
		break;
	case WINSOCKERR:
		printf("%s", RED);
		printf("Could not find a usable version of Winsock.dll\n");
		printf("%s", DEFAULT);
	default:
		break;
	}
}