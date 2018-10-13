/*
 *	这是一个非常简单的http服务端程序，可以接收任何请求，
 *	不管任何请求，只回复hello world
 *	http是应用层协议，在传输层使用tcp，所写的实际是tcp的服务端程序
 *	假设监听的是10000端口，也就意味着浏览器请求url中服务地址需要手动指定10000，否则
 *	浏览器默认使用80
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : %s [Ip] [Port]\n", argv[0]);
		return 1;
	}

	int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(listen_sock < 0)
	{
		perror("socket");
		return 1;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(atoi(argv[2]));
	local.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(local);

	if(bind(listen_sock, (struct sockaddr*)&local, len) < 0)
	{
		perror("bind");
		return 1;
	}

	if(listen(listen_sock, 5) < 0)
	{
		perror("listen");
		return 1;
	}

	while(1)
	{
		struct sockaddr_in client;
		len = sizeof(client);
		int sock = accept(listen_sock, (struct sockaddr*)&client, &len);
		if(sock < 0)
		{
			perror("accept");
			continue;
		}

		char buf[1024] = {0};
		ssize_t s = recv(sock, buf, sizeof(buf)-1, 0);
		if(s > 0)
		{
			printf("s : [%s]\n", buf);
		}
		//整体http响应包含:
		//1 首行
		//		HTPP
		//2 头信息 Content-Length
		//3 空行
		//
		//4 正文
		//		rsp
		char *rsp = "<h1>hello world</h1>";
		char std[1024] = {0};
		sprintf(std, "%s\r\n%s%d\r\n%s\r\n\r\n%s", 
							"HTTP/1.1 200 OK", 
							"Content-Length: ", 
							strlen(rsp), 
							"Content-Type: text/html;charest=UTF-8",
							rsp);

		send(sock, std, strlen(std), 0);
		close(sock);
	}
}
