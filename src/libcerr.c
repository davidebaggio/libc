#include "libcerr.h"

void printe(enum Err_type type, int e)
{
	switch (type)
	{
	case WSASTARTUPERR:
		printf("%s", RED);
		printf("WSAStartup failed with error: %d\n", e);
		break;
	case WSACLEANUPERR:
		printf("%s", RED);
		printf("WSACleanup failed with error: %d\n", e);
		break;
	case WINSOCKERR:
		printf("%s", RED);
		printf("Could not find a usable version of Winsock.dll\n");
		break;
	case CLOSINGSERVER:
		printf("%s", GREEN);
		printf("Server closing...\n");
		break;
	case CLOSINGCLIENT:
		printf("%s", GREEN);
		printf("Client closing...\n");
		break;
	case MESSAGE:
		printf("%s", PURPLE);
		printf("--> ");
		break;
	case WINSOCKOK:
		printf("%s", GREEN);
		printf("The Winsock 2.2 dll was found okay\n");
		break;
	case SOCKERR:
		printf("%s", RED);
		printf("Socket creation failed...\n");
		break;
	case SOCKOK:
		printf("%s", GREEN);
		printf("Socket successfully created..\n");
		break;
	case CONNECTIONERR:
		printf("%s", RED);
		printf("Connection creation failed...\n");
		break;
	case CONNECTIONOK:
		printf("%s", GREEN);
		printf("Connection successfully created..\n");
		break;
	case BINDERR:
		printf("%s", RED);
		printf("Bind creation failed...\n");
		break;
	case BINDOK:
		printf("%s", GREEN);
		printf("Bind successfully created..\n");
		break;
	case LISTENINGERR:
		printf("%s", RED);
		printf("Listening failed...\n");
		break;
	case LISTENINGOK:
		printf("%s", GREEN);
		printf("Server listening..\n");
		break;
	case ACCEPTERR:
		printf("%s", RED);
		printf("Couldn't accept client...\n");
		break;
	case ACCEPTOK:
		printf("%s", GREEN);
		printf("Client accepted..\n");
		break;
	default:
		break;
	}
	printf("%s", DEFAULT);
}