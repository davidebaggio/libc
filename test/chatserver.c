#include "server.h"

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	system("cls");
	int sockfd, connfd;
	int len;
	struct sockaddr_in servaddr, cli;
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

	// setsockopt(sockfd, SOL_SOCKET, )

	memset(&servaddr, 0, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(PORT);

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)
	{
		printe(BINDERR, 0);
		exit(0);
	}
	else
		printe(BINDOK, 0);

	// Now server is ready to listen and verification
	if ((listen(sockfd, 5)) != 0)
	{
		printe(LISTENINGERR, 0);
		exit(0);
	}
	else
		printe(LISTENINGOK, 0);
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA *)&cli, &len);
	if (connfd < 0)
	{
		printe(ACCEPTERR, 0);
		exit(0);
	}
	else
		printe(ACCEPTOK, 0);

	// Function for chatting between client and server
	host_chat(connfd);

	// After chatting close the socket
	close(sockfd);
#ifdef _WIN32
	cleanup_socket();
#endif

	return 0;
}
