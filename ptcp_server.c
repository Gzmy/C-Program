/*
 * 这是一个基于多进程版本的tcp简单网络聊天程序-服务端
 *		1.创建socket
 *		2.绑定地址信息
 *		3.监听
 *		4.获取一个客户端连接成功的socket
 *		5.进程
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/socket.h>

int create_work(int sock)
{
	int pid = fork();
	if(pid < 0)
		return -1;
	else if(pid == 0)
	{
		while(1)
		{
			char buf[1024] = {0};
			int ret = recv(sock, buf, sizeof(buf), 0);
			if(ret <= 0)
			{
				close(sock);
				exit(-1);
			}
			printf("client say : [%s]\n", buf);
			fflush(stdout);
			send(sock, "what?", 5, 0);
		}
	}
	else
		close(sock);
	return 0;
}

void sigcb(int signo)
{
	//如果返回值大于0,代表有子进程退出,不确定有几个子进程退出
	//就一直循环,直到返回值为0,0代表没有子进程退出
	while(waitpid(-1, NULL, WNOHANG) > 0);
}

int main(int argc, char *argv[])
{
	signal(SIGCHLD, sigcb);
	if(argc != 3)
	{
		printf("Usage: %s [Ip] [Port]\n", argv[0]);
		return 1;
	}

	int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(listen_sock < 0)
	{
		perror("socket");
		return 2;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(atoi(argv[2]));
	local.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(local);

	if(bind(listen_sock, (struct sockaddr *)&local, len) < 0)
	{
		perror("bind");
		return 3;
	}

	if(listen(listen_sock, 5) < 0)
	{
		perror("listen");
		return 4;
	}

	char buf[1024];
	while(1)
	{
		struct sockaddr_in client;
		socklen_t len = sizeof(client);
		//accept是一个阻塞函数,如果连接成功队列中没有新的socket,那么她阻塞
		//直到有新的客户端连接上来创建socket
		int sock = accept(listen_sock, (struct sockaddr *)&client, &len);
		if(sock < 0)
		{
			perror("accept");
			continue;
		}
		printf("connect success:[%s] [%d]\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

		create_work(sock);

	}

	close(listen_sock);
	return 0;
}
