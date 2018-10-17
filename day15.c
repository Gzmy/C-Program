/*
 * 逆置字符串
 */

#include <stdio.h>

void swap(char *str, char *std)
{
	while(str < std){
		char tmp = *str;
		*str = *std;
		*std = tmp;
		std--, str++;
	}
}

int main()
{
	char buf[1024];
	gets(buf);
	char *a = buf;
	char *b = buf;
	char *str = buf;

	//while(*a){
	//	if(isspace(*a))
	//	{
	//		swap(str, a-1);
	//		str = a+1;
	//	}
	//	a++;
	//}
	//swap(str, a-1);
	//swap(b, a-1);
	//printf("%s\n", b);
	

	while(*b){
		while(*b != ' '){
			b++;
		}
		swap(a, b-1);
		a = ++b;
	}
	swap(str, b-1);
	printf("%s\n", str);
	return 0;
}
