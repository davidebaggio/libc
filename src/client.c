#include "client.h"

void join_chat(int sockfd)
{
	char buff[MAX];
	int n;
	for (;;)
	{
		memset(buff, 0, sizeof(buff));
		printe(MESSAGE, 0);
		n = 0;
		while ((buff[n++] = getchar()) != '\n')
			;
		write(sockfd, buff, sizeof(buff));
		memset(buff, 0, sizeof(buff));
		read(sockfd, buff, sizeof(buff));
		printf("From Server : %s", buff);
		if ((strncmp(buff, "exit", 4)) == 0)
		{
			printe(CLOSINGCLIENT, 0);
			break;
		}
	}
}