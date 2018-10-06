#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#define PORT 8888
#define BACKLOG 2   //侦听队列长度

void process_conn_server(int s)
{
	ssize_t size = 0;
	char buffer[1024];

	for(;;)
	{
		size = read(s, buffer, 1024);

		if(size == 0)
			return;

		sprintf(buffer, "%d bytes altoether\n", size);
		write(s, buffer, strlen(buffer)+1);
	}
}

int main(int argc, char *argv[])
{
	int ss, sc;//ss为服务器的socket描述符,sc为客户端的socket描述符
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int err; //返回值
	pid_t pid; //分叉进行的ID

	ss = socket(AF_INET, SOCK_STREAM, 0);
	if(ss < 0)
	{
		printf("socket error\n");
		return -1;
	}

	//设置服务器地址
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);//本地地址

	//绑定
	err = bind(ss, (struct sockaddr *)&server_addr, sizeof(server_addr));
	if(err < 0)
	{
		printf("bind error!\n");
		return -1;
	}

	//监听
	err = listen(ss, BACKLOG);
	if(err < 0)
	{
		printf("listen error!\n");
		return -1;
	}

	for(;;)
	{
		socklen_t addrlen = sizeof(struct sockaddr);

		sc = accept(ss, (struct sockaddr *)&client_addr, &addrlen);
		if(sc < 0)
			continue;

		//建立一个新的进程处理来到的连接
		pid = fork();
		if(pid == 0)
			close(ss); //子进程中关闭服务器的侦听
		else
			process_conn_server(sc);
			close(sc); //父进程中关闭客户端的连接
	}
	return 0;
}
