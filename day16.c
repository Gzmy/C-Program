#include <stdio.h>

int main()
{
	char buf[100];
	int std[100];
	gets(buf);
	int i, j, len;
	i = j = len = 0;
	while(buf[i++]){
		if(buf[i] == ' '){
			buf[i] = 0;
			std[j++] = ++i;
			len++;
		}
	}
	len++;
	j = 0;
	for(i = 0; i < len-1; i++){
		if(atoi(buf+std[i]) >= len/2)
			j++;
	}
	if(atoi(buf+0) >= len/2)
		j++;
	printf("%d\n", j);
	//char buf[100];
	//gets(buf);
	//int i = 0;
	//int j = 0;
	//while(buf[i++]){
	//	if(buf[i] != ' ')
	//		j++;
	//}
	//int flag = 0;
	//for(i = 0; buf[i] != 0; i++){
	//	if(buf[i] != ' ' && buf[i]-'0' >= j/2)
	//		flag++;
	//}
	//printf("%d\n", flag);
	return 0;
}
