#include "client.h"

void *recieving(void *args)
{
	while (1)
	{
		message *a = ((message *)args);
		memset(a->buff, 0, sizeof(a->buff));
		recv(a->socknum, a->buff, sizeof(a->buff), 0);
		if (a->buff[0] != '\0')
		{
			// printe(MESSAGE, 0);
			printf("%d : %s", a->socknum, a->buff);
		}
	}
}

void join_chat(int sockfd)
{
	char buff[MAX];
	message *recvs = malloc(sizeof(message));
	recvs->socknum = sockfd;
	pthread_t id;
	int n;
	pthread_create(&id, NULL, recieving, recvs);
	for (;;)
	{
		memset(buff, 0, sizeof(buff));
		// printe(MESSAGE, 0);
		n = 0;
		while ((buff[n++] = getchar()) != '\n')
			;
		if ((strncmp(buff, "exit", 4)) == 0)
		{
			printe(CLOSINGCLIENT, 0);
			break;
		}
		send(sockfd, buff, sizeof(buff), 0);
		memset(buff, 0, sizeof(buff));
	}
	pthread_cancel(id);
}