#include "libcsocket.h"

struct headers heads[100];
char hbuf[500];

char response[1000001];
char *request = "GET / HTTP/1.0\r\n\r\n";
struct sockaddr_in remote_addr;

int main(int argc, char const *argv[])
{
	(void)argc;

#ifdef _WIN32
	startup_socket();
#endif

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printe(SOCKERR, 0);
		exit(0);
	}
	else
		printe(SOCKOK, 0);
	memset(&remote_addr, 0, sizeof(remote_addr));
	// assign IP, PORT
	remote_addr.sin_family = AF_INET;
	unsigned char *ip = (unsigned char *)&remote_addr.sin_addr.s_addr;

	/*
	 */

	if (argv[1])
	{
		char s[256];
		strcpy(s, argv[1]);
		char *token = strtok(s, ".");
		int i = 0;
		while (token && i < 4)
		{
			// printf("token: %d\n", atoi(token));
			ip[i++] = atoi(token);
			token = strtok(NULL, ".");
		}
	}
	else
	{
		ip[0] = 142;
		ip[1] = 250;
		ip[2] = 200;
		ip[3] = 36;
	}

	/* for (size_t i = 0; i < 4; i++)
	{
		printf("%d.", ip[i]);
	}
	printf("\n");
	*/
	remote_addr.sin_port = htons(80);
	if (connect(sockfd, (SA *)&remote_addr, sizeof(struct sockaddr_in)) != 0)
	{
		printe(CONNECTIONERR, 0);
		exit(0);
	}
	else
		printe(CONNECTIONOK, 0);

	send(sockfd, request, strlen(request), 0);

	int t = 0;
	while ((t = recv(sockfd, response, 1000000, 0)))
	{
		for (size_t i = 0; i < (size_t)t; i++)
		{
			printf("%c", response[i]);
		}
	}

#ifdef _WIN32
	cleanup_socket();
#endif
	return 0;
}
