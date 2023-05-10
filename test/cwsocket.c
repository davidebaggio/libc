#include "libcsocket.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
#ifdef _WIN32
	startup_socket();
#endif

	int s;

	s = socket(AF_INET, SOCK_STREAM, 0);

	printf("%d", s);
	return 0;

	/* then call WSACleanup when done using the Winsock dll */
#ifdef _WIN32
	cleanup_socket();
#endif
}
