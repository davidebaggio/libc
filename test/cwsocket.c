#include "libcsocket.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	startup_socket();

	int s;

	s = socket(AF_INET, SOCK_STREAM, 0);

	printf("%d", s);
	return 0;

	/* then call WSACleanup when done using the Winsock dll */
	cleanup_socket();
}
