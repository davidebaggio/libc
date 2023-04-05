#include "server.h"

void *recieving(void *args)
{
	int valrecv;
	char str[MAX];
	while (1)
	{
		message *a = ((message *)args);
		memset(a->buff, 0, sizeof(a->buff));
		valrecv = recv(a->socknum, a->buff, sizeof(a->buff), 0);
		if (valrecv > 0)
		{
			printf("%d : %s", a->socknum, a->buff);
			if (strlen(a->buff) > 4)
			{
				if (strncmp("get", a->buff, 3) == 0)
				{
					size_t l = 0;
					memset(str, 0, MAX);
					while (a->buff[4 + l] != '\n' && a->buff[4 + l] != '\0')
					{
						l++;
					}
					memcpy(str, &a->buff[4], l);
					str[l++] = '\0';
					printf("%s[INFO]: getting file --> %s\n%s", YELLOW, str, DEFAULT);
					char *p = filebuf(str);
					// printf("%s\n", p);
					if (p)
						send(a->socknum, p, strlen(p), 0);
				}
			}
		}
	}
	pthread_exit(NULL);
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
	free(recvs);
	pthread_cancel(id);
}

char *filebuf(const char *file_path)
{
	FILE *file = fopen(file_path, "r");
	if (!file)
	{
		printe(FILEERR, 0);
		printf("%s\n", file_path);
		return NULL;
	}
	char *source = NULL;
	if (fseek(file, 0L, SEEK_END) == 0)
	{
		/* Get the size of the file. */
		long bufsize = ftell(file);
		if (bufsize == -1)
		{
			printe(FILEERR, 0);
		}

		/* Allocate our buffer to that size. */
		source = malloc(sizeof(char) * (bufsize + 1));

		/* Go back to the start of the file. */
		if (fseek(file, 0L, SEEK_SET) != 0)
		{
			printe(FILEERR, 0);
		}

		/* Read the entire file into memory. */
		size_t newLen = fread(source, sizeof(char), bufsize, file);
		if (ferror(file) != 0)
		{
			fputs("Error reading file", stderr);
		}
		else
		{
			source[newLen++] = '\0'; /* Just to be safe. */
		}
	}
	fclose(file);
	return source;
}