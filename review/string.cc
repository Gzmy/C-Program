#include <stdio.h>
#include <string.h>
#include <iostream>
#include <memory.h>

struct A {
	int _a:2;
	int _b:5;
	int _c:10;
	int _d:30;
};

int main()
{
	std::cout << sizeof(A) << std::endl;
	//char str[] = "This is a sample string";
	//char *pch;
	//printf("lookng for the 's' character in \"%s\"...\n", str);
	//pch = strchr(str, 's');
	//while(pch != NULL) {
	//	printf("found at %d\n", pch-str+1);
	//	pch = strchr(pch+1, 's');
	//}

	//char str1[20];
	//char str2[20];
	//strcpy(str1, "to be");
	//strcpy(str2, "or not to be");
	//strncat(str1, str2, 6);
	//puts(str1);
	return 0;
}
