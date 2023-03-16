#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int s;

	s = socket(AF_INET, SOCK_STREAM, 0);

	printf("%d\n", s);
	return 0;
}