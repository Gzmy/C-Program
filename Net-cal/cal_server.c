/*
 *	基于tcp的一个网络版本服务器
 *	1. 接收客户端传输过来的结构化数据，从结构化数据解析出要进行计算的两个
 *		数字和运算符
 *	2. 进行计算并返回结果
 *
 */

//构造结构化数据
//客户端的请求数据结构，服务器对收到的数据
//将使用这个结构进行解析
typedef struct _req_t
{
	int num1;
	int num2;
	char sym;
} req_t;

//服务器对客户端的运算结果返回数据结构
typedef struct _rsp_t
{
	int res;
} rsp_t;

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>

rsp_t cal_robot(char *buf)
{
	//数据解析并进行计算
	rsp_t res;
	req_t *req = (req_t *)buf;
	
	if(req->sym == '+')
	{
		res.res = req->num1 + req->num2;
	}
	else if(req->sym == '-')
	{
		res.res = req->num1 - req->num2;
	}
	else if(req->sym == '*')
	{
		res.res = req->num1 * req->num2;
	}
	else if(req->sym == '/')
	{
		res.res = req->num1 / req->num2;
	}

	return res;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage : %s [ip] [port]\n", argv[0]);
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
		if(sock  < 0)
		{
			perror("accept");
			return 1;
		}
		//接收业务
		char buf[1024] = {0};
		recv(sock, buf, sizeof(buf)-1, 0);
		rsp_t res = cal_robot(buf);
		//向客户端发送结果
		send(sock, (void*)&res, sizeof(res), 0);
		close(sock);
	}
	return 0;
}
