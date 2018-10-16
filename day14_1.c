/*
 * 模拟三次密码输入
 */

#include <stdio.h>
#include <string.h>

int main()
{
	int i = 3;
	char buf[] = "123456";
	char input[20];
	while(i--)
	{
		memset(input, 0x00, sizeof(input));
		printf(">");
		scanf("%s", input);
		int k;
		for(k = 0; k < strlen(input); k++)
		{
			if(buf[i] != input[i])
				break;
		}
		if(k == strlen(buf))
		{
			printf("welcome!\n");
			return 0;
		}
		else 
		{
			printf("error\n");
			continue;
		}
	}
}
