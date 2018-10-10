/*hello user*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd = open("open.c", O_RDONLY);
	if(fd == -1)
		perror("open");
	else
		printf("open success");

	while(1)
	{
		char buf[10+1] = {};
		int r = read(fd, buf, 10);
		if(r == -1) perror("read"), exit(1);
		if(r == 0)
		{
			printf("read end\n");
			break;
		}
		else
		{
			printf("%s", buf);
		}
	}
	return 0;
}
