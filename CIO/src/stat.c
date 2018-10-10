/*hello user*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
	struct stat sbuf;
	if (stat("test.c", &sbuf) == -1)
		perror("stat"),exit(1);
	printf("size = %d\n", sbuf.st_size);

	return 0;
}
