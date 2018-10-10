//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	FILE *fp = fopen("myfile", "w");
//	if(!fp)
//	{
//		printf("打开错误");
//	}
//
//	const char *msg = "hello world!\n";
//	int count = 5;
//	while(count--)
//	{
//		fwrite(msg, strlen(msg), 1, fp);
//	}
//
//	fclose(fp);
//	return 0;
//}


//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<unistd.h>
//#include<string.h>
//
//int main()
//{
//	umask(0);
//	int fd = open("myfile", O_WRONLY|O_CREAT, 0644);
//	if(fd < 0)
//	{
//		perror("open");
//		return 1;
//	}
//
//	int count = 5;
//	const char *msg = "hello world!\n";
//	int len = strlen(msg);
//
//	while(count--)
//	{
//		write(fd, msg, len);
//	}
//	close(fd);
//	return 0;
//}


//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<unistd.h>
//#include<string.h>
//
//int main()
//{
//	int fd = open("myfile", O_RDONLY);
//	if(fd < 0)
//	{
//		perror("open");
//		return 1;
//	}
//
//	const char *msg = "hello world!\n";
//	char buf[1024];
//	while(1)
//	{
//		ssize_t s = read(fd, buf, strlen(msg));
//		if(s > 0)
//		{
//			printf("%s", buf);
//		}
//		else
//		{
//			break;
//		}
//	}
//
//	close(fd);
//	return 0;
//}


//#include<stdio.h>
//#include<sys/types.h>
//#include<sys/stat.h>
//#include<fcntl.h>
//#include<string.h>
//
//int main()
//{
//	char buf[1024];
//	ssize_t s = read(0, buf, sizeof(buf));
//	if(s > 0)
//	{
//		buf[s] = 0;
//		write(1, buf, strlen(buf));
//		write(2, buf, strlen(buf));
//	}
//	return 0;
//}














