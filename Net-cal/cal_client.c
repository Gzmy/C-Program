/*
 *	基于tcp的网络版本计算器
 *		将数据以指定的格式组织并发送给服务端，等待服务端返回的结果
 */

typedef struct _req_t
{
	int num1;
	int num2;
	int sym;
} req_t;

typedef struct _rsp_t
{
	int res;
} rsp_t;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : %s [Ip] [Port]\n", argv[0]);
		return 1;
	}
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if(sock < 0)
	{
		perror("socket");
		return 1;
	}
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(atoi(argv[2]));
	local.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(local);
	if(connect(sock, (struct sockaddr*)&local, len) < 0)
	{
		perror("connect");
		return 1;
	}

	while(1)
	{
		//组织数据
		req_t req;
		req.num1 = 33;
		req.num2 = 44;
		req.sym = '+';
		//发送数据
		send(sock, (void*)&req, sizeof(req), 0);
		//等待服务器返回结果
		rsp_t rsp;
		recv(sock, (void*)&rsp, sizeof(rsp), 0);
		printf("res:%d\n", rsp.res);
		break;
	}
	return 0;
}
