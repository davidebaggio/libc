#include "server.h"

void *recieving(void *args)
{
	message *a = ((message *)args);
	memset(a->buff, 0, sizeof(a->buff));
	recv(a->socknum, a->buff, sizeof(a->buff), 0);
	printf("%d : %s\n", a->socknum, a->buff);
}

void host_chat(int connfd)
{
	char buff[MAX];
	message *recvs = malloc(sizeof(message));
	recvs->socknum = connfd;
	pthread_t id;
	int n;
	// infinite loop for chat
	for (;;)
	{
		pthread_create(&id, NULL, recieving, recvs);
		printe(MESSAGE, 0);
		n = 0;
		while ((buff[n++] = getchar()) != '\n')
			;
		if (strncmp("exit", buff, 4) == 0)
		{
			printe(CLOSINGSERVER, 0);
			break;
		}
		send(connfd, buff, sizeof(buff), 0);
		memset(buff, 0, MAX);
	}
}