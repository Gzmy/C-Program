#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define INIT -1

void serviceIO(fd_set *rfds, int fd_array[], int num)
{
	int i = 0;
	for(; i < num; i++)
	{
		if(fd_array[i] == INIT)
			continue;

		if(i == 0 && FD_ISSET(fd_array[i], rfds))
		{
			struct sockaddr_in client;
			socklen_t len = sizeof(client);
			int sock = accept(fd_array[i], (struct sockaddr*)&client, &len);
			if(sock < 0)
			{
				perror("accept");
				continue;
			}
			printf("get a new client!\n");

			int j = 0;
			for(; j < num; j++)
			{
				if(fd_array[j] == INIT)
					break;
			}

			if(j < num)
			{
				fd_array[j] = sock;
			}
			else
			{
				printf("fd_array is full!\n");
				close(sock);
				continue;
			}
			continue;
		}
		if(FD_ISSET(fd_array[i], rfds))
		{//normal fd
			char buf[1024];
			ssize_t s = read(fd_array[i], buf, sizeof(buf)-1);
			if(s  > 0)
			{
				buf[s] = 0;
				printf("%s", buf);
			}
			else if(s == 0){
				printf("client quit!\n");
				fd_array[i] = INIT;
				close(fd_array[i]);
			}else{
				perror("read");
				fd_array[i] = INIT;
				close(fd_array[i]);
			}
		}
	}
}

int startup(int port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket");
		exit(2);
	}
	
	int opt = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0)
	{
		perror("bind");
		exit(3);
	}

	if(listen(sock, 5) < 0)
	{
		perror("listen");
		exit(4);
	}

	return sock;
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage : %s [port]\n", argv[0]);
		return 0;
	}

	int listen_sock = startup(atoi(argv[1]));
	int fd_array[sizeof(fd_set) * 8];
	int num = sizeof(fd_array)/sizeof(fd_array[0]);

	fd_array[0] = listen_sock; 
	fd_set rfds;
	int maxfd = INIT;
	int i = 1;
	for(; i < num; i++)
	{
		fd_array[i] = INIT;
	}

	for(;;)
	{
		struct timeval timeout = {1, 0}; //每隔一秒检测一次

		for(i = 0; i < num; i++)
		{
			if(fd_array[i] == INIT)
				continue;
			FD_SET(fd_array[i], &rfds);
			if(maxfd < fd_array[i])
			{
				maxfd = fd_array[i];
			}
		}//rfds, maxfd

		switch(select(maxfd+1, &rfds, NULL, NULL, /*&timeout)*/NULL))
		{
			case 0:
				printf("timeout!\n");
				break;
			case -1:
				perror("select");
				break;
			default:
				serviceIO(&rfds, fd_array, num);
				break;
		}
	}
}
