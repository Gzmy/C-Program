#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : %s [Ip] [Port]\n", argv[0]);
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
	local.sin_port = htons((atoi(argv[2])));
	local.sin_addr.s_addr = inet_addr(argv[1]); 
	socklen_t len = sizeof(local);
	
	if(bind(sock, (struct sockaddr *)&local, len) < 0)
	{
		perror("bind");
		return 3;
	}

	char buf[1024];
	while(1)
	{
		struct sockaddr_in client;
		socklen_t tmp = sizeof(client);
		ssize_t s = recvfrom(sock, buf, sizeof(buf)-1, 0, (struct sockaddr *)&client, &tmp);
		if(s < 0)
		{
			perror("recvfrom");
			return 4;
		}
		buf[s] = 0;
		printf("[%s : %d] : %s", inet_ntoa(client.sin_addr), ntohs(client.sin_port), buf);
		s = sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&client,tmp);
		if(s < 0)
		{
			perror("sendto");
			return 5;
		}
	}

	close(sock);
	return 0;
}
