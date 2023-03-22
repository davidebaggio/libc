#include "server.h"

void host_chat(int connfd)
{
	char buff[MAX];
	int n;
	// infinite loop for chat
	for (;;)
	{
		memset(buff, 0, MAX);
		read(connfd, buff, sizeof(buff));
		// print buffer which contains the client contents
		printe(MESSAGE, 0);
		printf("%s", buff);
		memset(buff, 0, MAX);
		n = 0;
		while ((buff[n++] = getchar()) != '\n')
			;
		write(connfd, buff, sizeof(buff));

		if (strncmp("exit", buff, 4) == 0)
		{
			printe(CLOSINGSERVER, 0);
			break;
		}
	}
}