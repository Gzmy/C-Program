/*
 * 使用epoll多路转接技术的tcp服务端
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	if(argc != 3){
		printf("Usgae : %s [ip] [port]", argv[0]);
		return 1;
	}
	int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(listen_sock < 0){
		perror("socket");
		return 2;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(atoi(argv[2]));
	local.sin_addr.s_addr = inet_addr(argv[1]);
	socklen_t len = sizeof(local);

	if(bind(listen_sock, (struct sockaddr*)&local, len) < 0){
		perror("bind");
		return 3;
	}

	if(listen(listen_sock, 5) < 0){
		perror("listen");
		return 4;
	}

	//创建eventpoll结构
	int epfd = epoll_create(10);
	if(epfd < 0){
		perror("epoll_create");
		return -1;
	}

	//向内核添加事件
	//epoll_ctl(), 
	//默认水平触发(LT): 只要缓冲区有数据就一直提醒,每次epoll_wait都会触发事件就绪
	//------------------------------------------------------------------------
	//边缘触发(ET):每当有新的数据到来,事件会触发一次,假如缓冲区数据没有读完,
	//但是不会再次提醒(就这一条事件来说不会触发),基于这中特性,就需要我们一次性将缓冲区数据全部读完
	//为了防止数据缓冲区没有读完,因此进行了循环读取,recv有可能会阻塞,所以要设置成非阻塞
	struct epoll_event ev;
	ev.events = EPOLLIN;
	ev.data.fd = listen_sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev);

	while(1){
		int i, ret;
		struct epoll_event evs[10];
		int nfds = epoll_wait(epfd, evs, 10, 3000);
		if(nfds < 0){
			perror("epoll_wait");
			return -1;
		}
		else if(nfds == 0){
			printf("timeout!..\n");
			continue;
		}
		for(i = 0; i < nfds; i++){
			if(evs[i].data.fd == listen_sock){
				struct sockaddr_in client;
				len = sizeof(client);
				int sock = accept(listen_sock, (struct sockaddr*)&client, &len);
				if(sock < 0){
					perror("accept");
					continue;
				}
				//给新连接组织新的连接结构
				ev.events = EPOLLIN;
				ev.data.fd = listen_sock;
				epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev);
			}
			else{
				char buf[1024] = {0};
				ret = recv(evs[i].data.fd, buf, sizeof(buf)-1, 0);
				if(ret <= 0){
					if(errno == EAGAIN || errno == EINTR){
						continue;
					}
					epoll_ctl(epfd, EPOLL_CTL_DEL, evs[i].data.fd, &ev);
					close(evs[i].data.fd);
				}
				printf("client say:%s", buf);
			}
		}
	}
	return 0;
}
