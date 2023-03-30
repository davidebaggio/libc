#include "server.h"

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

void host_chat(int connfd)
{
	char buff[MAX];
	message *recvs = malloc(sizeof(message));
	recvs->socknum = connfd;
	pthread_t id;
	int n;
	pthread_create(&id, NULL, recieving, recvs);
	for (;;)
	{
		// printe(MESSAGE, 0);
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

	pthread_cancel(id);
}