#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8888

void process_conn_client(int s)
{
	ssize_t size = 0;
	char buffer[1024];

	for(;;)
	{
		size = read(0, buffer, 1024);
		if(size > 0)
		{
			write(s, buffer, size);
			size = read(s, buffer, 1024);
			write(1, buffer, size);
		}
	}
}

int main(int argc, char *argv[])
{
	int s;
	socklen_t len;
	struct sockaddr_in server_addr;
	len = sizeof(struct sockaddr);

	s = socket(AF_INET, SOCK_STREAM, 0);
	if(s < 0)
	{
		printf("socket error\n");
		return -1;
	}

	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);

	inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
	connect(s, (struct sockaddr *)&server_addr, len);
	process_conn_client(s);
	close(s);
	return 0;
}