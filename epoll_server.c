#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void handlerReadyEvents(int epfd, struct epoll_event revs[], int num, int listen_sock)
{
	int i = 0;
	struct epoll_event ev;
	for(; i < num; i++){
		int sock = revs[i].data.fd;
		uint32_t events = revs[i].events;

		if(sock == listen_sock && (events & EPOLLIN)){ //link event ready
			struct sockaddr_in client;
			socklen_t len = sizeof(client);
			int new_sock = accept(sock, (struct sockaddr*)&client, &len);
			if(new_sock < 0){
				perror("accept");
				continue;
			}
			printf("get a new client!\n");

			//添加新事件到epoll模型
			ev.events = EPOLLIN;
			ev.data.fd = new_sock;
			epoll_ctl(epfd, EPOLL_CTL_ADD, new_sock, &ev);
		}
		else if(events & EPOLLIN){ //normal read event ready
			char buf[10240];
			ssize_t s = read(sock, buf, sizeof(buf)-1);
			if(s > 0){
				buf[s] = 0;
				printf("%s", buf); //read ok
				ev.events = EPOLLOUT;
				ev.data.fd = sock;
				epoll_ctl(epfd, EPOLL_CTL_MOD, sock, &ev);
			}else if(s == 0){
				printf("client quit!\n");
				close(sock);
				epoll_ctl(epfd, EPOLL_CTL_DEL, sock, NULL);
			}else{
				perror("read");
			}
		}
		else if(events & EPOLLOUT){ //normal write event ready
			const char *echo_http = "http/1.0 200 OK\r\n\r\n<html><h1>hello Epoll Server!</h1></html>\r\n";
			write(sock, echo_http, strlen(echo_http));
			close(sock);
			epoll_ctl(epfd, EPOLL_CTL_DEL, sock, NULL);
		}
		else{ //bug!
		}
	}
}

int startup(int port)
{
	int sock = socket(AF_INET, SOCK_STREAM, 0);

	if(sock < 0){
		perror("socket");
		exit(2);
	}

	int opt = 1;
	setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0){
		perror("bind");
		exit(3);
	}

	if(listen(sock, 5) < 0){
		perror("bind");
		exit(4);
	}

	return sock;
}

int main(int argc, char *argv[])
{
	if(argc != 2){
		printf("Usage : %s [port]\n", argv[0]);
		return 1;
	}

	int listen_sock = startup(atoi(argv[1]));
	int epfd = epoll_create(256);
	if(epfd < 0){
		printf("epoll_create error!\n");
		return 5;
	}

	struct epoll_event ev; //需要监听的事
	ev.events = EPOLLIN;
	ev.data.fd = listen_sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, listen_sock, &ev);

	struct epoll_event revs[64]; //发生的事件存放在这个数组中
	while(1){
		int timeout = 1000;
		int num = epoll_wait(epfd, revs, sizeof(revs)/sizeof(revs[0]), timeout);
		switch(num){
			case -1:
				printf("epoll_wait error!\n");
				break;
			case 0:
				printf("timeout!!!\n");
				break;
			default:
				handlerReadyEvents(epfd, revs, num, listen_sock);
				break;
		}
	}
}
