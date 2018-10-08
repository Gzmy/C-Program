#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : %s [IP] [Port]\n", argv[0]);
		return 1;
	}

	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0)
	{
		perror("socket");
		return 2;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(atoi(argv[2]));
	local.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(local);

	char buf[1024];
	while(1)
	{
		ssize_t s = read(0, buf, sizeof(buf)-1);
		if(s < 0)
		{
			perror("read");
			return 3;
		}
		buf[s] = 0;
		s = sendto(sock, buf, strlen(buf), 0, (struct sockaddr*)&local, len);
		if(s < 0)
		{
			perror("sendto");
			return 4;
		}
		s = recvfrom(sock, buf, sizeof(buf)-1, 0, NULL, NULL);
		if(s < 0)
		{
			perror("recvfrom");
			return 5;
		}
		buf[s] = 0;
		printf("server echo# %s", buf);
	}
	return 0;
}
