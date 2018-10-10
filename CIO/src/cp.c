/*hello user*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "usage: %s src dst\n", argv[0]);
		exit(1);
	}

	//打开源文件
	int fd_src = open(argv[1], O_RDONLY);
	if (fd_src == -1)
	{
		perror("open src");
		exit(1);
	}

	//打开目标文件
	int fd_dst = open(argv[2], O_WRONLY|O_CREAT|O_EXCL, 0644);
	if(fd_dst == -1 && errno == EEXIST)
	{
		printf("目标存在,是否覆盖?\n");
		char choose;
		scanf(" %s", &choose);
		if(choose == 'y' || choose == 'Y')
		{
			fd_dst = open(argv[2], O_WRONLY);
		}
		else
			exit(0);
	}

	//循环读写
	char buf[1024+1];
	while(1)
	{
		memset(buf, 0x00, sizeof(buf));
		int r = read(fd_src, buf, 1024);
		if(r <= 0);
		break;
		write(fd_dst, buf, r);
	}

	close(fd_src);
	close(fd_dst);
}
