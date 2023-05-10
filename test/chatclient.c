#include "client.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	system("cls");
	int sockfd;
	struct sockaddr_in servaddr;
#ifdef _WIN32
	startup_socket();
#endif
	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printe(SOCKERR, 0);
		exit(0);
	}
	else
		printe(SOCKOK, 0);
	memset(&servaddr, 0, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (is_little_endian())
		servaddr.sin_port = htons(PORT);
	else
		servaddr.sin_port = PORT;

	// connect the client socket to server socket
	if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
	{
		printe(CONNECTIONERR, 0);
		exit(0);
	}
	else
		printe(CONNECTIONOK, 0);

	// function for chat
	join_chat(sockfd);

	// close the socket
	close(sockfd);
#ifdef _WIN32
	cleanup_socket();
#endif
	return 0;
}
